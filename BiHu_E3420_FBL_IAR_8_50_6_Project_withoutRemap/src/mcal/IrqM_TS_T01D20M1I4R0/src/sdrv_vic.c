/*
 * sd_vic.c
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: SemiDrive VIC driver.
 *
 * Revision History:
 * -----------------
 */

#include "RegHelper.h"
#include "arch_irq.h"
#include "sdrv_vic.h"
#include "Vic_Irq_Cfg.h"
#include "bits.h"

#include "arch.h"
#include "mini_libc.h"
#include "Mcu.h"

#define OFFSET32(v)  (((v) >> 5) << 2)
#define SHIFT32(v)  ((v) & 31U)

#define VICINTENABLE(v)         (g_vic_data[core_id].base + 0x100U + OFFSET32(v))
#define VICINTENCLEAR(v)        (g_vic_data[core_id].base + 0x1C0U + OFFSET32(v))
#define VICSWMASK(v)            (g_vic_data[core_id].base + 0x180U + OFFSET32(v))
#define VICVECTPRIORITY(v)      (g_vic_data[core_id].base + 0x400U + ((v) << 2))
#define VIC_WDT_EN              (g_vic_data[core_id].base + 0x380U)
#define VIC_WDT_TH              (g_vic_data[core_id].base + 0x3C0U)
#define VIC_ERRINT_CLR          (g_vic_data[core_id].base + 0x3CCU)
#define VIC_SFINT_MASK          (g_vic_data[core_id].base + 0x1F00U)
#define VICVECADDR(v)           (g_vic_data[core_id].base + 0xF000U + ((v) << 2))
#define VICADDRESS              (g_vic_data[core_id].base + 0xF00U)
#define VICINTSELECT(v)         (g_vic_data[core_id].base + 0xC0U + OFFSET32(v))
#define VICSOFTINT(v)           (g_vic_data[core_id].base + 0x140U + OFFSET32(v))
#define VICSOFTINTCLEAR(v)      (g_vic_data[core_id].base + 0x200U + OFFSET32(v))
#define VICFIQSTATUS(v)         (g_vic_data[core_id].base + 0x40U + OFFSET32(v))
#define VICSWPRIORITYMASK       (g_vic_data[core_id].base + 0x3C8U)
#define VICSWMASK_REG(n)        (g_vic_data[core_id].base + 0x180U + ((n) << 2))

#define MAX_PRI 15

#define SWMASK_REG_NUM  8

/* Timeout configuration */
#define WDT_EN  0U
#define WDT_DIV 1U
#define WDT_TH  0x80U
#define MAKE_WDT_TH(en, div, th)    (((en) << 31) | (((div) & 0x3FFU) << 16) | \
                                     ((th) & 0xFFU))

struct vic_data {
    uint32 base;
    uint32 int_num;
    uint32 cur_rp;
    uint32 irq_nest_cnt;
    /* Current masked priority set by user or interrrupt framework. */
    uint32 pri_masked;

#ifndef CONFIG_VIC_IRQ_INTERRUPT_MODE
    #ifndef CONFIG_VIC_INT_NEST_MAX_CNT
    #define CONFIG_VIC_INT_NEST_MAX_CNT 16
    #endif

    struct stack {
        uint32 buf[CONFIG_VIC_INT_NEST_MAX_CNT];
        uint32 head;
    } old_pri;
#endif

    /* The following members are only needed on E3 v1.0. */
    struct sw_mask {
        /* Bitmap that record registered interrupt of each priority
         * and each sw mask register value.
         */
        struct pri_mask {
            /* Is each priority masked?
            * Each priority is arranged linealy to get higher access performance.
            */
            bool masked[MAX_PRI + 1] ALIGNED(CACHE_LINE);
            /* Registered interrupt of each priority. */
            unsigned long int_mask[MAX_PRI + 1][SWMASK_REG_NUM] ALIGNED(CACHE_LINE);
            /* Registerd interrupt which has a equal or lower priority than
            * each given priority specified by array index.
            */
            unsigned long low_pri_mask[MAX_PRI + 1][SWMASK_REG_NUM] ALIGNED(CACHE_LINE);
        } pmsk;
        uint32 cur_sw_mask[SWMASK_REG_NUM] ALIGNED(CACHE_LINE);
    } swmsk;
    /* Current masked priority set by user. */
    uint32 cur_sw_mask;
} ALIGNED(CACHE_LINE);

#define IRQM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "IrqM_MemMap.h"

static struct vic_data g_vic_data[CONFIG_VIC_CORE_NUM];

#define IRQM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "IrqM_MemMap.h"

#define IRQM_START_SEC_CODE
#include "IrqM_MemMap.h"

static uint8 get_vic_version(void)
{
#ifdef SEMIDRIVE_E3_SERIES
    return Mcu_GetChipVersion();
#else
    return  1;
#endif
}

int int_nest_errata_enabled(void)
{
    /* Subsequent changes to this interface behavior require attention */
    uint8 minor_id = get_vic_version();

    /* Maybe other version number needed, if so add it here. */
    if ((minor_id == 0) || (minor_id == 1)) {
    #ifdef CONFIG_VIC_INT_NEST_ERRATA
        if (minor_id == 0)
            return INT_NEST_ERRATA_TYPE_0;
        else {
        #ifdef CONFIG_VIC_IRQ_INTERRUPT_MODE
            return INT_NEST_ERRATA_TYPE_1;
        #else
            return INT_NEST_ERRATA_TYPE_2;
        #endif
        }
    #else
        return NO_INT_NEST_ERRATA;
    #endif
    }else{
        return NO_INT_NEST_ERRATA;
    }
}


static inline void sdrv_vic_lld_int_disable_all(void)
{
    int core_id = get_core_id();
    uint32 int_num = g_vic_data[core_id].int_num;

    for (uint32 i = 0U; i < int_num; i += 32U) {
        writel(0xFFFFFFFFU, VICINTENCLEAR(i));
    }
}

static void sdrv_vic_lld_func_safety_en(void)
{
    int core_id = get_core_id();
    /* Enable timeout dection. */
    writel(MAKE_WDT_TH(WDT_EN, WDT_DIV, WDT_TH), VIC_WDT_TH);
    writel(WDT_EN, VIC_WDT_EN);

    /* Unmask error interrupts. */
    writel(0U, VIC_SFINT_MASK);
}

static void sdrv_vic_lld_all_ints_trigger_irq(void)
{
    int core_id = get_core_id();
    uint32  int_num = g_vic_data[core_id].int_num;

    for (uint32  i = 0U; i < int_num; i += 32U) {
        writel(0U, VICINTSELECT(i));
    }
}

static void sdrv_vic_lld_set_vector(void)
{
    int core_id = get_core_id();
    uint32  int_num = g_vic_data[core_id].int_num;

#if defined(CONFIG_VIC_IRQ_INTERRUPT_MODE)
    extern uint8 vectored_irq0_handler, vectored_irq1_handler;

    uint32  vector_start_addr = (uint32 )&vectored_irq0_handler;
    uint32  each_vector_size = (uint32 )((uint32)&vectored_irq1_handler -
                                           (uint32)&vectored_irq0_handler);

    for (uint32  i = 0U; i < int_num; i++) {
        writel(vector_start_addr + i * each_vector_size,
               VICVECADDR(i));
    }
#else
    for (uint32  i = 0U; i < int_num; i++) {
        writel(i, VICVECADDR(i));
    }
#endif
}

#if defined(CONFIG_VIC_IRQ_INTERRUPT_MODE)
static int sdrv_vic_dummy_isr(uint32  vector)
{
    return -1;
}

/* IRQ handler may be allowed not to use per cpu variable?
 * Because this variable value is the same on all cores.
 */
int (*g_vic_user_isr)(uint32  vector) = sdrv_vic_dummy_isr;

static inline void sdrv_vic_lld_set_user_isr(int (*isr)(uint32 ))
{
    if (isr) {
        g_vic_user_isr = isr;
    }
}
#else
static inline void sdrv_vic_inc_int_nest_cnt(void)
{
    g_vic_data[get_core_id()].irq_nest_cnt++;
}

static inline int sdrv_vic_dec_int_nest_cnt(void)
{
    return (--g_vic_data[get_core_id()].irq_nest_cnt);
}
#endif

static inline void sdrv_vic_lld_clr_int_nest_cnt(void)
{
    int core_id = get_core_id();
    g_vic_data[core_id].irq_nest_cnt = 0U;
}

static void sdrv_vic_lld_unmask_interrupt(uint32  vector)
{
    int core_id = get_core_id();
    RMWREG32(VICSWMASK(vector), SHIFT32(vector), 1U, 0U);
}

/**
 * @brief Mask specified interrupt
 * @param vector priority to be masked
 */
static void sdrv_vic_lld_mask_interrupt(uint32  vector)
{
    int core_id = get_core_id();
    RMWREG32(VICSWMASK(vector), SHIFT32(vector), 1U, 1U);
}

/**
 * @brief Mask all low priority level
 * @param pri_threshold interrupts with priority equals
 *        to or lower than pri_threshold are masked.
 * @param user if this api called by user or interrupt
 *        framework.
 * @return Previous masked priority value
 */
uint32  sdrv_vic_lld_mask_low_priority(uint32  pri_threshold, boolean user)
{
    uint32  ret;
    int core_id = get_core_id();
    struct vic_data *vicdata = &g_vic_data[core_id];
    static uint32  old_mask = ~0U;

    irq_state_t state = arch_irq_save();
    ret = old_mask;
    pri_threshold = MIN(pri_threshold, MAX_PRI + 1);

    if (user)
        old_mask = pri_threshold;

    if (NO_INT_NEST_ERRATA != int_nest_errata_enabled()) {
        /* If called by user, update current masked priority. */
        if (user)
            vicdata->cur_sw_mask = pri_threshold;

        /* When user sets priority mask, always no unmasking any
         * priority masked by interrupt framework.
         */
        if (user && (vicdata->cur_rp < pri_threshold))
            pri_threshold = vicdata->cur_rp;
        /* When interrupt framework sets priority mask, always no
         * unmasking any priority masked by user.
         */
        else if (!user && (vicdata->cur_sw_mask < pri_threshold))
            pri_threshold = vicdata->cur_sw_mask;
    }

    if (get_vic_version() == 0) {
        uint32  swmask[SWMASK_REG_NUM] = {0};
        struct pri_mask *pmsk = &vicdata->swmsk.pmsk;
        uint32  *curmask = vicdata->swmsk.cur_sw_mask;

        /* Larger priority value, lower priority. */
        for (int i = 0; i <= MAX_PRI; i++) {
            /* Update mask value of each priroity. */
            if (i < pri_threshold)
                pmsk->masked[i] = FALSE;
            else
                pmsk->masked[i] = TRUE;
        }
        if (pri_threshold <= MAX_PRI) {
            /* Update swmask register value to low pri masked bitmap. */
            memcpy(swmask, pmsk->low_pri_mask[pri_threshold], sizeof(swmask));
        }

        for (int i = 0; i < SWMASK_REG_NUM; i++) {
            if (curmask[i] != swmask[i]) {
                writel(swmask[i], VICSWMASK_REG(i));
                curmask[i] = swmask[i];
            }
        }
    }
    else {
        uint16 temp = 0xFFFF;
        temp = temp >> (16 - pri_threshold);
        writel(temp, VICSWPRIORITYMASK);
    }

    vicdata->pri_masked = pri_threshold;
    arch_irq_restore(state);

    return ret;
}

/**
 * @brief Unmask all interrupt
 */
void sdrv_vic_lld_unmask_all_interrupt(void)
{
    if (get_vic_version() == 1) {
        int core_id = get_core_id();
        irq_state_t state = arch_irq_save();

        for (int i = 0; i < SWMASK_REG_NUM; i++)
            writel(0, VICSWMASK_REG(i));

        arch_irq_restore(state);
    }
}

/**
 * @brief Unmask all priority
 */
void sdrv_vic_lld_unmask_all_priority(void)
{
    sdrv_vic_lld_mask_low_priority(0xFF, TRUE);
}

/**
 * @brief Initialize VIC
 * @param isr user ISR
 */
void sdrv_vic_lld_init(uint32  base, uint32  intr_num, int (*isr)(uint32 ))
{
    int core_id = get_core_id();

    g_vic_data[core_id].base = base;
    g_vic_data[core_id].int_num = intr_num;
    g_vic_data[core_id].cur_rp = 0xFF;
    if (get_vic_version() == 0){
        memset(g_vic_data[core_id].swmsk.cur_sw_mask, 0xFF,
               sizeof(g_vic_data[core_id].swmsk.cur_sw_mask));
    }

    sdrv_vic_lld_int_disable_all();
    sdrv_vic_lld_all_ints_trigger_irq();
    sdrv_vic_lld_unmask_all_interrupt();
    sdrv_vic_lld_unmask_all_priority();

    sdrv_vic_lld_func_safety_en();

    sdrv_vic_lld_set_vector();

#if defined(CONFIG_VIC_IRQ_INTERRUPT_MODE)
    sdrv_vic_lld_set_user_isr(isr);
    arch_vectored_irq_enable(1U);
#else
    arch_vectored_irq_enable(0U);
#endif

    sdrv_vic_lld_clr_int_nest_cnt();
}

static inline void
sdrv_vic_lld_clear_int_mask(uint32  vector)
{
    int core_id = get_core_id();
    struct sw_mask *swmsk = &g_vic_data[core_id].swmsk;

    for (int i = 0; i <= MAX_PRI; i++) {
        unsigned long *intmask = swmsk->pmsk.int_mask[i];
        unsigned long *low_pir_mask = swmsk->pmsk.low_pri_mask[i];
        if (bitmap_test(intmask, vector))
            bitmap_clear(intmask, vector);
        if (bitmap_test(low_pir_mask, vector))
            bitmap_clear(low_pir_mask, vector);
    }
}

/**
 * @brief Set priority
 */
void sdrv_vic_lld_set_priority(uint32  vector,
                               uint32  pri)
{
    int core_id = get_core_id();
    irq_state_t state = arch_irq_save();
    writel(pri & 15U, VICVECTPRIORITY(vector));

    if (get_vic_version() == 0) {
        struct pri_mask *pmsk = &g_vic_data[core_id].swmsk.pmsk;
        unsigned long *intmask = pmsk->int_mask[pri];

        /* In case of modifying priority dynamically, clear
         * previous int bitmap first.
         */
        sdrv_vic_lld_clear_int_mask(vector);
        bitmap_set(intmask, vector);
        /* If masking a equal or higher priority, this
         * vector should be masked. So, set this vector
         * in each low pir mask bitmap with a equal or
         * higher priority.
         */
        for (int i = 0; i <= pri; i++) {
            bitmap_set(pmsk->low_pri_mask[i], vector);
        }

        if (pmsk->masked[pri])
            sdrv_vic_lld_mask_interrupt(vector);
        else
            sdrv_vic_lld_unmask_interrupt(vector);
    }
    arch_irq_restore(state);
}

/**
 * @brief Enable interrupt
 * @param vector interrupt vector number
 */
void sdrv_vic_lld_int_enable(uint32  vector)
{
    int core_id = get_core_id();
    irq_state_t state = arch_irq_save();
    RMWREG32(VICINTENABLE(vector), SHIFT32(vector), 1U, 1U);
    arch_irq_restore(state);
}

/**
 * @brief Disable interrupt
 * @param vector interrupt vector number
 */
void sdrv_vic_lld_int_disable(uint32  vector)
{
    int core_id = get_core_id();
    irq_state_t state = arch_irq_save();
    RMWREG32(VICINTENCLEAR(vector), SHIFT32(vector), 1U, 1U);
    arch_irq_restore(state);
}

/**
 * @brief Get priority
 * @param vector interrupt vector number
 * @return interrupt priority
 */
uint32  sdrv_vic_lld_get_priority(uint32  vector)
{
    int core_id = get_core_id();
    return readl(VICVECTPRIORITY(vector)) & 15U;
}

/**
 * @brief Get current running priority
 * @return uint32  current running priority
 */
uint32  sdrv_vic_lld_current_running_priority(void)
{
    return g_vic_data[get_core_id()].cur_rp;
}

/**
 * @brief Set one vector to trigger FIQ requeset
 * @param vector vector number
 */
void sdrv_vic_lld_set_fiq_req_src(uint32  vector)
{
    int core_id = get_core_id();
    uint32  int_num = g_vic_data[core_id].int_num;
    irq_state_t state = arch_irq_save();

    /* The system should have at most one FIQ source. */
    for (uint32  i = 0U; i < int_num; i += 32U) {
        if ((i >> 5) == (vector >> 5)) {
            writel(1U << SHIFT32(vector), VICINTSELECT(vector));
        }
        else {
            writel(0U, VICINTSELECT(i));
        }
    }

    arch_irq_restore(state);
}

static inline int local_fls(int x)
{
    int r = 32;

    if (!x)
        return 0;
    if (!(x & 0xffff0000u)) {
        x <<= 16;
        r -= 16;
    }
    if (!(x & 0xff000000u)) {
        x <<= 8;
        r -= 8;
    }
    if (!(x & 0xf0000000u)) {
        x <<= 4;
        r -= 4;
    }
    if (!(x & 0xc0000000u)) {
        x <<= 2;
        r -= 2;
    }
    if (!(x & 0x80000000u)) {
        r -= 1;
    }
    return r;
}

/**
 * @brief Get current serviced fiq vector number
 * @return uint32  vector number
 */
uint32  sdrv_vic_lld_get_active_fiq_src(void)
{
    int core_id = get_core_id();
    uint32  int_num = g_vic_data[core_id].int_num;
    uint32  i = 0U;
    uint32  fiq_status = 0U;
    uint32  ret = ~0UL;

    irq_state_t state = arch_irq_save();

    for (i = 0U; i < int_num; i += 32U) {
        fiq_status = readl(VICFIQSTATUS(i));
        if (fiq_status) {
            ret = i + local_fls(fiq_status) - 1;
            break;
        }
    }

    arch_irq_restore(state);
    return ret;
}

#ifndef CONFIG_VIC_IRQ_INTERRUPT_MODE
/**
 * No lock needed, because the folling function
 * is always called in IRQ disabled interrupt context.
 */
static void sdrv_vic_push_stack(struct stack *s, uint32  val)
{
    uint32  head = s->head;

    s->buf[head] = val;
    s->head = head + 1;
}

static uint32  sdrv_vic_pop_stack(struct stack *s)
{
    uint32  top = s->head - 1;
    uint32  ret = s->buf[top];
    s->head = top;

    return ret;
}

static inline void sdrv_vic_push_old_pri(void)
{
    int core_id = get_core_id();
    struct stack *old_pri = &g_vic_data[core_id].old_pri;

    sdrv_vic_push_stack(old_pri, g_vic_data[core_id].cur_rp);
}

static inline void sdrv_vic_pop_old_pri(void)
{
    int core_id = get_core_id();
    struct stack *old_pri = &g_vic_data[core_id].old_pri;
    g_vic_data[core_id].cur_rp = sdrv_vic_pop_stack(old_pri);
}
#endif

void sdrv_vic_lld_ack_slow_path(int errata, uint32 running_pri)
{
    /* Mask all interrupt with the same and lower priority
     * to prevent:
     * 1) same or lower priority interrupt preempting after
     *    writing VICADDRESS
     * 2) same sw priority but higher hw priority interrupt
     *    preempting
     */
    sdrv_vic_lld_mask_low_priority(running_pri, FALSE);

    /* Type0 (v1.0) & Type2 (v1.1 non-vectored irq) should wr isr to
     * clear hwmask, in order to avoid mismatch between hwmask and
     * vicaddress.
     */
    if ((errata == INT_NEST_ERRATA_TYPE_0) ||
        (errata == INT_NEST_ERRATA_TYPE_2)) {
        int core_id = get_core_id();
        if (errata == INT_NEST_ERRATA_TYPE_0)
            /* Because irq_b given by vic can only be cleared by CPU
             * acknowledge to vic, so if vic outputs another valid
             * irq_b signal triggered by interrupt with the same sw
             * priority but lower interrupt number before masking it,
             * CPU will take it after IRQ re-enabled.
             * To avoid this, here we should read vicaddress register
             * first to clear the additional irq_b signal, and then
             * writing vicaddress register to clear hwmask to make all
             * interrupts, including this additional interrupt, can be
             * sent to CPU at the right time.
             */
            (void)readl(VICADDRESS);
        /* A dummy write to VICADDRESS
         * finish the current interrupt.
         */
        writel(0, VICADDRESS);
    }
}

/**
 * @brief Interrupt acknowledge
 * @return uint32  interrupt number
 */
uint32  sdrv_vic_lld_ack(void)
{
#ifndef CONFIG_VIC_IRQ_INTERRUPT_MODE
    int core_id = get_core_id();
    if (!arch_in_fiq_mode()) {
        sdrv_vic_inc_int_nest_cnt();

        uint32  vector_num =  readl(VICADDRESS);

        /* Save previous running priority. */
        sdrv_vic_push_old_pri();
        /* Update current running priority. */
        uint32  cur_rp = sdrv_vic_lld_get_priority(vector_num);
        g_vic_data[core_id].cur_rp = cur_rp;
        /* Save priority mask before this interrupt. */
        uint32  pri_mask = g_vic_data[core_id].pri_masked;

        int errata = int_nest_errata_enabled();
        if (errata != NO_INT_NEST_ERRATA)
            sdrv_vic_lld_ack_slow_path(errata, cur_rp);

    /* Make sure only unmasked interrupt can be taken. */
    if (cur_rp >= pri_mask)
        return g_vic_data[core_id].int_num;

    #ifdef CONFIG_VIC_INT_NEST_AUTO_ENABLE
        if (g_vic_data[core_id].irq_nest_cnt < CONFIG_VIC_INT_NEST_MAX_CNT)
            arch_irq_enable();
    #endif

        return vector_num;
    }
    else
#endif
    {
        return sdrv_vic_lld_get_active_fiq_src();
    }
}

#ifndef CONFIG_VIC_IRQ_INTERRUPT_MODE
/**
 * @brief Interrupt completed
 */
void sdrv_vic_lld_eoi(uint32  vector)
{
    /* No need to write vicaddress register
     * in FIQ service routine.
     */
    if (!arch_in_fiq_mode()) {
        int core_id = get_core_id();
        arch_irq_disable();
        int errta = int_nest_errata_enabled();
        if (errta == NO_INT_NEST_ERRATA)
            /* A dummy write to VICADDRESS
             * finish the current interrupt.
             */
            writel(vector, VICADDRESS);

        sdrv_vic_dec_int_nest_cnt();
        /* Restore previous running priority. */
        sdrv_vic_pop_old_pri();

        if (NO_INT_NEST_ERRATA != int_nest_errata_enabled()){
            /* Unmask priority to previous state. */
            sdrv_vic_lld_mask_low_priority(g_vic_data[core_id].cur_rp,
                                           FALSE);
        }
    }
}
#endif

/**
 * @brief Trigger software interrupt
 * @param vector interrupt number
 */
void sdrv_vic_lld_trigger_soft_int(uint32  vector)
{
    int core_id = get_core_id();
    irq_state_t state = arch_irq_save();
    writel(1U << SHIFT32(vector), VICSOFTINT(vector));
    arch_irq_restore(state);
}

/**
 * @brief Clear software interrupt
 * @param vector interrupt number
 */
void sdrv_vic_lld_clear_soft_int(uint32  vector)
{
    int core_id = get_core_id();
    irq_state_t state = arch_irq_save();
    writel(1U << SHIFT32(vector), VICSOFTINTCLEAR(vector));
    arch_irq_restore(state);
}

void *get_vic_data_base(void)
{
    return &g_vic_data[get_core_id()];
}

#define IRQM_STOP_SEC_CODE
#include "IrqM_MemMap.h"
