/*
 * arm_atomic.s
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: ARM atomic function.
 *
 * Revision History:
 * -----------------
 */
#include "arch.h"
#include "asm_def.h"

#if defined(_IAR_C_)
    SECTION .text:CODE(2)
    ARM
#else
    .section ".text"
    .arm
#endif

    ASM_PUBLIC arch_atomic_swap
ASM_FUNCTION(arch_atomic_swap)
.Lloop_atomic_swap:
    ldrex   r12, [r0]
    strex   r2, r1, [r0]
    cmp     r2, #0
    bne     .Lloop_atomic_swap
    mov     r0, r12
    bx      lr

    ASM_PUBLIC arch_atomic_add
ASM_FUNCTION(arch_atomic_add)
.Lloop_atomic_add:
    ldrex   r12, [r0]
    add     r2, r12, r1
    strex   r3, r2, [r0]
    cmp     r3, #0
    bne     .Lloop_atomic_add
    mov     r0, r12
    bx      lr

    ASM_PUBLIC arch_atomic_and
ASM_FUNCTION(arch_atomic_and)
.Lloop_atomic_and:
    ldrex   r12, [r0]
    and     r2, r12, r1
    strex   r3, r2, [r0]
    cmp     r3, #0
    bne     .Lloop_atomic_and
    mov     r0, r12
    bx      lr

    ASM_PUBLIC arch_atomic_or
ASM_FUNCTION(arch_atomic_or)
.Lloop_atomic_or:
    ldrex   r12, [r0]
    orr     r2, r12, r1
    strex   r3, r2, [r0]
    cmp     r3, #0
    bne     .Lloop_atomic_or
    mov     r0, r12
    bx      lr

    ASM_PUBLIC arch_atomic_try_update
ASM_FUNCTION(arch_atomic_try_update)
.Lloop_atomic_try_update:
    ldrex   r12, [r0]
    subs	r2, r12, r12, ror #TICKET_SHIFT
    addeq	r12, r12, r1
    strex   r3, r12, [r0]
    cmp     r3, #0
    bne     .Lloop_atomic_try_update
    mov     r0, r2
    bx      lr

#if defined(_IAR_C_)
    END
#endif