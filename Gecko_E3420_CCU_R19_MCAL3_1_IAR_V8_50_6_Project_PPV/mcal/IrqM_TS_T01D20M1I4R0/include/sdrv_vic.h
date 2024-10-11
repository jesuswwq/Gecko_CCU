/*
 * sd_vic.h
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: SemiDrive VIC header file.
 *
 * Revision History:
 * -----------------
 */

#ifndef SDRV_VIC_H_
#define SDRV_VIC_H_

#include "Vic_Irq_Cfg.h"

#ifndef VIC_SOFT_IRQ_CLR_BY_HANDLER
#define VIC_SOFT_IRQ_CLR_BY_HANDLER 0
#endif

#define DEFAULT_IRQ_PRIORITY    10U

#define irq_lld_initialize  sdrv_vic_lld_init
#define irq_lld_set_priority    sdrv_vic_lld_set_priority
#define irq_lld_disable sdrv_vic_lld_int_disable
#define irq_lld_enable  sdrv_vic_lld_int_enable
#define irq_lld_mask(x)    sdrv_vic_lld_mask_low_priority(x, TRUE)
#define irq_lld_get_priority    sdrv_vic_lld_get_priority
#define irq_lld_get_current_priority    sdrv_vic_lld_current_running_priority
#define irq_lld_unmask  sdrv_vic_lld_unmask_all_priority
#define irq_lld_acknowledge sdrv_vic_lld_ack

#ifdef CONFIG_VIC_IRQ_INTERRUPT_MODE
#define irq_lld_complete(irq)
#else
#define irq_lld_complete(irq)   sdrv_vic_lld_eoi(irq)
#endif

/* Not supported interface by VIC. */
#define irq_lld_set_trigger_mode(irq, mode) (void)mode

#ifndef ASSEMBLY

#include <Compiler.h>
/**
 * Type 0: v1.0
 * Type 1: v1.1 vectored irq mode
 * Type 2: v1.1 non-vectored irq mode
 */
#define NO_INT_NEST_ERRATA      0
#define INT_NEST_ERRATA_TYPE_0  1
#define INT_NEST_ERRATA_TYPE_1  2
#define INT_NEST_ERRATA_TYPE_2  3


#include "Mcu_Soc.h"

uint32 sdrv_vic_lld_mask_low_priority(uint32 pri_threshold, boolean user);

void sdrv_vic_lld_unmask_all_priority(void);

void sdrv_vic_lld_init(uint32 base, uint32 intr_num, int (*isr)(uint32));
void sdrv_vic_lld_set_priority(uint32 vector,
                               uint32 pri);
void sdrv_vic_lld_int_enable(uint32 vector);
void sdrv_vic_lld_int_disable(uint32 vector);
uint32 sdrv_vic_lld_get_priority(uint32 vector);
uint32 sdrv_vic_lld_current_running_priority(void);
void sdrv_vic_lld_set_fiq_req_src(uint32 vector);
uint32 sdrv_vic_lld_get_active_fiq_src(void);
uint32 sdrv_vic_lld_ack(void);
#ifndef CONFIG_VIC_IRQ_INTERRUPT_MODE
void sdrv_vic_lld_eoi(uint32 vector);
#endif
void sdrv_vic_lld_trigger_soft_int(uint32 vector);
void sdrv_vic_lld_clear_soft_int(uint32 vector);
#if (VIC_SOFT_IRQ_CLR_BY_HANDLER == 1)
boolean sdrv_vic_lld_is_soft_int(uint32  vector);
#endif
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))

#if (CONFIG_VIC_CORE_NUM > 1)
static inline int get_core_id(void)
{
    return Mcu_GetCoreID();
}
#else
#define get_core_id()      0
#endif
#endif // !ASSEMBLY

#endif // !SDRV_VIC_H_
