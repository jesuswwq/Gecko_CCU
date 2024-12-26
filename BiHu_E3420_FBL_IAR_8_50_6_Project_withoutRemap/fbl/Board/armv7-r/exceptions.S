/*
 * exceptions.c
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: bare metal exceptions handler.
 *
 * Revision History:
 * -----------------
 */

#include <Compiler.h>

#if defined(_IAR_C_)
    SECTION .text:CODE(2)
    ARM
#else
    .section ".text"
    .arm
#endif

    ASM_EXTERN BareMetalFIQHandler
    ASM_EXTERN BareMetalIRQHandler

ASM_FUNCTION(osSysCallHandler)
    /* not support */
    ldr     r0,=osSysCallHandler
    bx      r0

    ASM_PUBLIC osFiqHandler
ASM_FUNCTION(osFiqHandler)
    push    {r0-r4, lr}
    sub     sp, sp, #4
    blx     BareMetalFIQHandler
    add     sp, sp, #4
    pop     {r0-r4, lr}
    subs    pc, lr, #4

    ASM_PUBLIC osIrqHandler
ASM_FUNCTION(osIrqHandler)
    sub     lr, lr, #4

    srsdb   #0x13!

    cpsid   i,#0x13

    push    {r0-r4, r12, lr}

    sub     sp, #8
    stmia   sp, {r13, r14}^

    mov     r2, sp
    tst     sp, #4
    subeq   sp, #4
    push    {r2}

    push    {r0, lr}

    bl      BareMetalIRQHandler

    pop     {r0, lr}

    pop     {r2}
    mov     sp, r2

    ldmia   sp, {r13, r14}^
    add     sp, #8

    pop     {r0-r4, r12, lr}

    rfeia   sp!

#if defined(_IAR_C_)
    END
#endif
