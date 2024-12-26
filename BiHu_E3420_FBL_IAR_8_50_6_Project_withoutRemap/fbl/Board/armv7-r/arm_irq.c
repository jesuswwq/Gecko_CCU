/*
 * arm_irq.c
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: ARM irq function.
 *
 * Revision History:
 * -----------------
 */


#include "Mcu_Mpu.h"

#define PSR_F_BIT           (1 << 6)
#define PSR_I_BIT           (1 << 7)

#define MODE_USR            0x10
#define MODE_FIQ            0x11
#define MODE_IRQ            0x12
#define MODE_SVC            0x13
#define MODE_ABT            0x17
#define MODE_UND            0x1B
#define MODE_SYS            0x1F

#define MODE_MASK           0x1F

static inline uint32 read_cpsr(void)
{
    uint32 cpsr;
    ASM volatile("mrs   %0, cpsr" : "=r" (cpsr));
    return cpsr;
}

/*
 * is irq masked.
 *
 * @return   masked or not.
 */
boolean arch_irq_is_masked(void)
{
    uint32 cpsr = read_cpsr();
    return (!!(cpsr & PSR_I_BIT));
}

/*
 * is irq mode.
 *
 * @return   irq mode or not.
 */
boolean arch_in_irq_mode(void)
{
    uint32 cpsr;
    uint8 mode;

    cpsr = read_cpsr();
    mode = cpsr & MODE_MASK;
    return ((mode != MODE_USR) && (mode != MODE_SYS));
}

/**
 * @brief Enable vectored interrupt mode.
 */
void arch_vectored_irq_enable(boolean en)
{
    uint32 sctlr;

    sctlr = arm_read_sctlr();

    if (en) {
        sctlr |= 1U << 24;
    }
    else {
        sctlr &= ~(1U << 24);
    }

    arm_write_sctlr(sctlr);
}

/**
 * @brief Whether core is in FIQ mode or not
 *
 * @return true FIQ mode
 * @return false otherwise
 */
boolean arch_in_fiq_mode(void)
{
    uint32 cpsr = read_cpsr();

    return (cpsr & MODE_MASK) == MODE_FIQ;
}

/*
 * cpsr irq si masked.
 *
 * @return  masked or not.
 */
boolean prev_irq_is_masked(uint32 cpsr)
{
    return (!!(cpsr & PSR_I_BIT));
}
