/*
 * sd_vic_baremetal.S
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: SemiDrive VIC interrupt handlers for baremetal.
 *
 * Revision History:
 * -----------------
 */
#define NO_INT_NEST_ERRATA      0
#define INT_NEST_ERRATA_TYPE_0  1
#define INT_NEST_ERRATA_TYPE_1  2

#if __ICCARM__
    extern get_vic_data_base
    extern sdrv_vic_lld_get_priority
    extern sdrv_vic_lld_ack_slow_path
    extern sdrv_vic_lld_mask_low_priority
    extern g_vic_user_isr
    extern int_nest_errata_enabled
#endif

#if __GNUC__
.macro save_fpu_context
#elif __ICCARM__
save_fpu_context macro
#endif
    vmrs r1, fpexc
    tst r1, #(1 << 30)
    beq save_exit
    /* Save callee corrupted fpu registers */
    vpush {d0-d7}
    /* Save fpscr and fpexc */
    vmrs r1, fpscr
    push {r1}
    vmrs r1, fpexc
save_exit:
    push {r1}
#if __GNUC__
.endm
#elif __ICCARM__
    endm
#endif

#if __GNUC__
.macro restore_fpu_context
#elif __ICCARM__
restore_fpu_context macro
#endif
    pop {r1}
    vmsr fpexc, r1
    tst r1, #(1 << 30)
    beq restore_exit
    pop {r1}
    vmsr fpscr, r1
    vpop {d0-d7}
restore_exit:
#if __GNUC__
.endm
#elif __ICCARM__
    endm
#endif

#if __GNUC__
.macro vectored_irq_handler vector_num
#if defined (_GHS_C_)
    .globl vectored_irq><vector_num><_handler
vectored_irq><vector_num><_handler:
#else
    .globl vectored_irq\vector_num\()_handler
vectored_irq\vector_num\()_handler:
#endif
    sub lr, lr, #4
    srsdb sp!, #SVC_MODE

    cps #SVC_MODE

    /* Save callee and common_irq_handler corrupted registers */
    push {r0-r5, r12}
#if defined (_GHS_C_)
    mov r0, #vector_num
#else
    mov r0, #\vector_num
#endif
    b .Lcommon_irq_handler
.endm
#elif __ICCARM__
vectored_irq_handler macro vector_num
    public vectored_irq\1_handler
vectored_irq\1_handler:
    sub lr, lr, #4
    srsdb sp!, #SVC_MODE

    cps #SVC_MODE

    /* Save callee and common_irq_handler corrupted registers */
    push {r0-r5, r12}

    mov r0, #vector_num
    b .Lcommon_irq_handler
    endm
#endif

.Lcommon_irq_handler:
    /* Save fpu context, will corrupt r1 */
    save_fpu_context

    /* Force sp to align to 8 bytes */
    mov r1, sp
    bic sp, sp, #7
    /* Save old sp and supervisor lr */
    push {r1, lr}

    /* Save vector number into callee-saved register */
    mov r4, r0

    /* Save old running priority */
    blx get_vic_data_base
    add r1, r0, #8 /* r1 now holds address of {struct vic_data}.cur_rp */
    ldr r2, [r1]
    push {r1, r2}
    /* Update current running priority */
    mov r0, r4
    blx sdrv_vic_lld_get_priority
    ldr r1, [sp]
    str r0, [r1]

    /* Get previous masked priority */
    ldr r1, [r1, #8]

    push {r0, r1}
    blx int_nest_errata_enabled
    /* Save errata enabled flag into callee-saved r5 */
    movs r5, r0
    beq .Lno_errata

    ldr r1, [sp]
    blx sdrv_vic_lld_ack_slow_path

.Lno_errata:
    pop {r0, r1}

    /* Make sure only unmasked interrupt can be taken. */
    cmp r0, r1
    bge .Lirq_out

    /* Increment interrupt nesting counter */
    ldr r1, [sp]
    ldr r2, [r1, #4]!   /* r1 now holds address of {struct vic_data}.irq_nest_cnt */
    add r0, r2, #1
    str r0, [r1]
    push {r1, r2}

#ifdef CONFIG_VIC_INT_NEST_AUTO_ENABLE
    cmp r0, #CONFIG_VIC_INT_NEST_MAX_CNT
    bge .Lskip_reenable_irq
    cpsie i
.Lskip_reenable_irq:
#endif

    /* Call user ISR */
    mov r0, r4
    ldr r1, =g_vic_user_isr
    ldr r1, [r1]
    blx r1

    cpsid i

    /* Decrement interrupt nesting counter */
    pop {r1, r2}
    str r2, [r1]

.Lirq_out:
    /* Restore current running priority */
    pop {r1, r2}
    str r2, [r1]

    cmp r5, #INT_NEST_ERRATA_TYPE_0
    beq .Lerrata_skip_wr_isr
    ldr r1, [r1, #-8]
    add r1, r1, #0xF00
    /* Perform a dummy write to VICADDRESS register to clear hwmask */
    str r4, [r1]

.Lerrata_skip_wr_isr:
    cmp r5, #NO_INT_NEST_ERRATA
    beq .Lrestore_context
    /* Unmask priority to previous state. */
    mov r0, r2
    mov r1, #0
    blx sdrv_vic_lld_mask_low_priority

.Lrestore_context:
    /* Restore sp and supervisor lr */
    pop {r1, lr}
    mov sp, r1

    restore_fpu_context

    /* Restore context */
    pop {r0-r5, r12}
    rfeia sp!

#if __GNUC__
    .ltorg
#elif __ICCARM__
    ltorg
#endif

