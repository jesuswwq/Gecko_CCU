/*
 * interrupt.c
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: interrupt driver.
 *
 * Revision History:
 * -----------------
 */

#include "Std_Types.h"
#define CONFIG_SDRV_VIC
#include "irq.h"
#include "arch.h"
#ifdef CONFIG_ARM_GIC
#include "arm_gic.h"
#endif
#ifdef CONFIG_SDRV_VIC
#include "sdrv_vic.h"
#endif
#include "irq_num.h"
#include "__regs_base.h"

/* irq info type */
struct irq_info_s {
  irq_handler handler;      /* Address of the interrupt handler */
  void *arg;                /* The argument provided to the interrupt handler. */
};

struct irq_table {
    struct irq_info_s irq_info[IRQ_MAX_INTR_NUM];
} ALIGNED(CACHE_LINE);

#define IRQM_START_SEC_CONST_UNSPECIFIED
#include "IrqM_MemMap.h"

const uint32 VIC_BASE_TABLE[] = {
#ifdef SEMIDRIVE_E3_SERIES
        PERIPHERALSF_VIC1_BASE,
        PERIPHERALSF_VIC3PORTA_BASE,
        PERIPHERALSF_VIC3PORTB_BASE,
        PERIPHERALSP_VIC2PORTA_BASE,
        PERIPHERALSP_VIC2PORTB_BASE
#endif
#ifdef SEMIDRIVE_E3_LITE_SERIES
        VIC1_BASE
#endif
};
#define IRQM_STOP_SEC_CONST_UNSPECIFIED
#include "IrqM_MemMap.h"

#define IRQM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "IrqM_MemMap.h"

/* int table */
static struct irq_table g_irq_table[CONFIG_VIC_CORE_NUM];

#define IRQM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "IrqM_MemMap.h"


#define IRQM_START_SEC_CODE
#include "IrqM_MemMap.h"

static int irq_handle(uint32 irq)
{
    int ret_value = -1;
    if (irq < IRQ_MAX_INTR_NUM) {
        int core_id = get_core_id();
        struct irq_info_s *irq_info = &g_irq_table[core_id].irq_info[irq];
        if (irq_info->handler) {
#if defined(NON_AUTOSAR_STANDARD_IRQ_HANDLER)
            return irq_info->handler(irq, irq_info->arg);
#else
            irq_info->handler();
#endif
            ret_value = 0;
        }
#if(VIC_SOFT_IRQ_CLR_BY_HANDLER == 1)
        if(sdrv_vic_lld_is_soft_int(irq)){
            sdrv_vic_lld_clear_soft_int(irq);
        }
#endif
    }

    return ret_value;
}

/*
 * interrupt initialize.
 */

void irq_initialize(uint32 base, uint32 intr_num)
{
    int core_id = get_core_id();
#ifdef CONFIG_ARM_GIC
    irq_lld_initialize(base, intr_num);
#endif
#ifdef CONFIG_SDRV_VIC
    irq_lld_initialize(VIC_BASE_TABLE[core_id], intr_num, irq_handle);
#endif
    // arch_irq_enable();
}

/*
 * interrupt attach.
 */
int irq_attach(uint32 irq, irq_handler handler, void *arg)
{
    int ret = -1;

    if (irq < IRQ_MAX_INTR_NUM) {
        int core_id = get_core_id();
        struct irq_info_s *irq_info = &g_irq_table[core_id].irq_info[irq];

        IRQ_SAVE

        irq_info->handler = handler;
        irq_info->arg = arg;

        irq_lld_set_priority(irq, DEFAULT_IRQ_PRIORITY);

        IRQ_RESTORE

        ret = 0;
    }

    return ret;
}

/*
 * interrupt detach.
 */
int irq_detach(uint32 irq)
{
    int ret = -1;

    if (irq < IRQ_MAX_INTR_NUM) {
        int core_id = get_core_id();
        struct irq_info_s *irq_info = &g_irq_table[core_id].irq_info[irq];

        IRQ_SAVE

        irq_lld_disable(irq);

        irq_info->handler = NULL_PTR;
        irq_info->arg = NULL_PTR;

        IRQ_RESTORE

        ret = 0;
    }

    return ret;
}

/*
 * interrupt dispatch.
 */
int irq_dispatch(void)
{
    int ret = -1;

    uint32 irq = irq_lld_acknowledge();

    ret = irq_handle(irq);

    irq_lld_complete(irq);

    return ret;
}

/*
 * irq enable.
 *
 * @irq   irq number.
 */
void irq_enable(uint32 irq)
{
    irq_lld_enable(irq);
}

/*
 * irq disable.
 *
 * @irq   irq number.
 */
void irq_disable(uint32 irq)
{
    irq_lld_disable(irq);
}

/*
 * interrupt set priority mask.
 *
 * @mask     int priority mask.
 * @return   old int priority mask.
 */
uint32 irq_mask(uint32 mask)
{
    return irq_lld_mask(mask);
}

/*
 * interrupt unmask all int.
 */
void irq_unmask(void)
{
    irq_lld_unmask();
}

/*
 * set irq priority.
 *
 * @irq         irq number.
 * @priority    irq priority.
 */
void irq_set_priority(uint32 irq, uint32 priority)
{
    irq_lld_set_priority(irq, priority);
}

/*
 * get irq priority.
 *
 * @irq         irq number.
 * @return      irq priority.
 */
int irq_get_priority(uint32 irq)
{
    return irq_lld_get_priority(irq);
}

/*
 * set irq trigger mode.
 *
 * @irq         irq number.
 * @mode        irq trigger mode.
 */
void irq_set_trigger_mode(uint32 irq, uint8 mode)
{
    uint8 lld_mode = 0;

#ifdef CONFIG_ARM_GIC
    if (mode == TRIGGER_MODE_LEVEL) {
        lld_mode = GIC_LEVEL_SENSITIVE;
    }
    else if (mode == TRIGGER_MODE_EDGE) {
        lld_mode = GIC_EDGE_TRIGGERED;
    }
    else {
        return;
    }
#endif
    irq_lld_set_trigger_mode(irq, lld_mode);
}

/*
 * interrupt get current int priority.
 *
 * @return      int priority.
 */
uint32 irq_get_current_priority(void)
{
    return irq_lld_get_current_priority();
}

#define IRQM_STOP_SEC_CODE
#include "IrqM_MemMap.h"
