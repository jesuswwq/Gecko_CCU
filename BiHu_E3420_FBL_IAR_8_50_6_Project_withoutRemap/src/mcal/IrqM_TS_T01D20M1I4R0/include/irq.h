/*
 * irq.h
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: interrupt interface.
 *
 * Revision History:
 * -----------------
 */

#ifndef INCLUDE_DRV_IRQ_H
#define INCLUDE_DRV_IRQ_H


#include "arch_irq.h"

/* trigger mode */
#define TRIGGER_MODE_LEVEL         0
#define TRIGGER_MODE_EDGE          1

#ifndef ASSEMBLY

/* irq callback type */
#if defined(NON_AUTOSAR_STANDARD_IRQ_HANDLER)
typedef int (*irq_handler)(uint32 irq, void *arg);
#else
typedef void (*irq_handler)(void);
#endif

/*
 * irq initialize.
 *
 * @base   irq base
 * @intr_num  irq number
 */
void irq_initialize(uint32 base, uint32 intr_num);

/*
 * irq attach.
 *
 * @irq     irq id.
 * @handler irq callback handler.
 * @arg     irq callback arg.
 * @return  result.
 */
int irq_attach(uint32 irq, irq_handler handler, void *arg);

/*
 * irq detach.
 *
 * @irq     irq id.
 * @return  result.
 */
int irq_detach(uint32 irq);

/*
 * interrupt dispatch.
 *
 * @return  irq dispatch result.
 */
int irq_dispatch(void);

/*
 * irq enable.
 *
 * @irq   irq number.
 */
void irq_enable(uint32 irq);

/*
 * irq disable.
 *
 * @irq   irq number.
 */
void irq_disable(uint32 irq);

/*
 * interrupt set priority mask.
 *
 * @mask     int priority mask.
 * @return   old int priority mask.
 */
uint32 irq_mask(uint32 mask);

/*
 * interrupt unmask all int.
 */
void irq_unmask(void);

/*
 * set irq priority.
 *
 * @irq         irq number.
 * @priority    irq priority.
 */
void irq_set_priority(uint32 irq, uint32 priority);

/*
 * get irq priority.
 *
 * @irq         irq number.
 * @return      irq priority.
 */
int irq_get_priority(uint32 irq);

/*
 * set irq trigger mode.
 *
 * @irq         irq number.
 * @mode        irq trigger mode.
 */
void irq_set_trigger_mode(uint32 irq, uint8 mode);

/*
 * interrupt get current int priority.
 *
 * @return      int priority.
 */
uint32 irq_get_current_priority(void);

/*
 * irq save.
 *
 * @return  old irq state.
 */
#define IRQ_SAVE                \
    irq_state_t irq_flags;      \
    irq_flags = arch_irq_save();

/*
 * irq restore.
 *
 * @flags   old irq state.
 */
#define IRQ_RESTORE             \
    arch_irq_restore(irq_flags);

#endif

#endif
