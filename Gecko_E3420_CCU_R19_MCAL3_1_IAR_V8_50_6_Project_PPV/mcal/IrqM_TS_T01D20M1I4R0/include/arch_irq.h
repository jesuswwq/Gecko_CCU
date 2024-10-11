/*
 * irq.h
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: ARM irq interface.
 *
 * Revision History:
 * -----------------
 */

#ifndef INCLUDE_ARCH_IRQ_H
#define INCLUDE_ARCH_IRQ_H

#ifndef ASSEMBLY

#include "Std_Types.h"
#include <Compiler.h>
#define COMPILER_BARRIER() ASM volatile ("" ::: "memory")

/*
 * irq state type.
 */
typedef unsigned int  irq_state_t;

/*
 * irq enable.
 */
static inline void arch_irq_enable(void)
{
    COMPILER_BARRIER();
    ASM volatile("cpsie i");
}

/*
 * irq disable.
 */
static inline void arch_irq_disable(void)
{
    ASM volatile("cpsid i");
    COMPILER_BARRIER();
}

/*
 * irq save.
 *
 * @return  old irq state.
 */
static inline irq_state_t arch_irq_save(void)
{
    unsigned int cpsr;

    ASM volatile
    (
        "\tmrs    %0, cpsr\n"
        "\tcpsid  i\n"
        : "=r" (cpsr)
        :
        : "memory"
    );

    return cpsr;
}

/*
 * irq restore.
 *
 * @flags   old irq state.
 */
static inline void arch_irq_restore(irq_state_t flags)
{
    ASM volatile
    (
        "msr    cpsr_c, %0"
        :
        : "r" (flags)
        : "memory"
    );
}

/*
 * is irq masked.
 *
 * @return   masked or not.
 */
boolean arch_irq_is_masked(void);

/*
 * is irq mode.
 *
 * @return   irq mode or not.
 */
boolean arch_in_irq_mode(void);

/**
 * @brief Enable vectored interrupt mode.
 */
void arch_vectored_irq_enable(boolean en);

/**
 * @brief Whether core is in FIQ mode or not
 *
 * @return true FIQ mode
 * @return false otherwise
 */
boolean arch_in_fiq_mode(void);
/*
 * cpsr irq si masked.
 *
 * @return  masked or not.
 */
boolean prev_irq_is_masked(uint32 cpsr);
#endif

#endif
