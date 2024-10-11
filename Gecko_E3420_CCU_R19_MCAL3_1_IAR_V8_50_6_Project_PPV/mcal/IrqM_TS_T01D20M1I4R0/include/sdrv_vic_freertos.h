/*
 * sd_vic_freertos.S
 *
 * Copyright (c) 2020 Semidrive Semiconductor.
 * All rights reserved.
 *
 * Description: SemiDrive VIC interrupt handlers for freertos.
 *
 * Revision History:
 * -----------------
 */

#define NO_INT_NEST_ERRATA      0
#define INT_NEST_ERRATA_TYPE_0  1
#define INT_NEST_ERRATA_TYPE_1  2

#if __ICCARM__
    EXTERN ulCriticalNesting
    EXTERN ulMaxAPIPriority
    EXTERN pxCurrentTCB
    EXTERN vTaskSwitchContext
    EXTERN vApplicationIRQHandler
    EXTERN ulPortInterruptNesting
    EXTERN ulPortTaskHasFPUContext
    EXTERN ulPortYieldRequired
    EXTERN vPortSetInterruptMaskAsm
    EXTERN get_vic_data_base
    EXTERN sdrv_vic_lld_get_priority
    EXTERN sdrv_vic_lld_ack_slow_path
    EXTERN sdrv_vic_lld_mask_low_priority
    EXTERN g_vic_user_isr
    EXTERN int_nest_errata_enabled
#endif

#if __GNUC__
.macro portSAVE_CONTEXT
#elif __ICCARM__
portSAVE_CONTEXT MACRO
#endif

    /* Save the LR and SPSR onto the system mode stack before switching to
    system mode to save the remaining system mode registers. */
    SRSDB   sp!, #SYS_MODE
    CPS     #SYS_MODE
    PUSH    {R0-R12, R14}

    /* Push the critical nesting count. */
    LDR     R2, =ulCriticalNesting
    LDR     R1, [R2]
    PUSH    {R1}

    /* Does the task have a floating point context that needs saving?  If
    ulPortTaskHasFPUContext is 0 then no. */
    LDR     R2, =ulPortTaskHasFPUContext
    LDR     R3, [R2]
    CMP     R3, #0

    /* Save the floating point context, if any. */
    FMRXNE  R1,  FPSCR
    VPUSHNE {D0-D15}
    /*VPUSHNE   {D16-D31}*/
    PUSHNE  {R1}

    /* Save ulPortTaskHasFPUContext itself. */
    PUSH    {R3}

    /* Save the stack pointer in the TCB. */
    LDR     R0, =pxCurrentTCB
    LDR     R1, [R0]
    STR     SP, [R1]

#if __GNUC__
.endm
#elif __ICCARM__
    ENDM
#endif

; /**********************************************************************/

#if __GNUC__
.macro portRESTORE_CONTEXT
#elif __ICCARM__
portRESTORE_CONTEXT MACRO
#endif

    /* Set the SP to point to the stack of the task being restored. */
    LDR     R0, =pxCurrentTCB
    LDR     R1, [R0]
    LDR     SP, [R1]

    /* Is there a floating point context to restore?  If the restored
    ulPortTaskHasFPUContext is zero then no. */
    LDR     R0, =ulPortTaskHasFPUContext
    POP     {R1}
    STR     R1, [R0]
    CMP     R1, #0

    /* Restore the floating point context, if any. */
    POPNE   {R0}
    /*VPOPNE    {D16-D31}*/
    VPOPNE  {D0-D15}
    VMSRNE  FPSCR, R0

    /* Restore the critical section nesting depth. */
    LDR     R0, =ulCriticalNesting
    POP     {R1}
    STR     R1, [R0]

    /* Ensure the priority mask is correct for the critical nesting depth. */
    CMP     R1, #0
    MOVEQ   R0, #255
    LDRNE   R0, =ulMaxAPIPriority
    LDRNE   R0, [R0]
    LDR     R4, =vPortSetInterruptMaskAsm
    BLX     R4

    /* Restore all system mode registers other than the SP (which is already
    being used). */
    POP     {R0-R12, R14}

    /* Return to the task code, loading CPSR on the way. */
    RFEIA   sp!

#if __GNUC__
.endm
#elif __ICCARM__
    ENDM
#endif

#if __GNUC__
.macro vectored_irq_handler vector_num
    .globl vectored_irq\vector_num\()_handler
vectored_irq\vector_num\()_handler:
    /* Return to the interrupted instruction. */
    SUB     lr, lr, #4

    /* Push the return address and SPSR. */
    PUSH    {lr}
    MRS     lr, SPSR
    PUSH    {lr}

    /* Change to supervisor mode to allow reentry. */
    CPS     #SVC_MODE

    /* Push used registers. */
    PUSH    {r0-r4, r12}

    MOV     r0, #\vector_num
    B       .Lcommon_irq_handler
.endm
#elif __ICCARM__
vectored_irq_handler MACRO vector_num
    PUBLIC vectored_irq\1_handler
vectored_irq\1_handler:
    /* Return to the interrupted instruction. */
    SUB     lr, lr, #4

    /* Push the return address and SPSR. */
    PUSH    {lr}
    MRS     lr, SPSR
    PUSH    {lr}

    /* Change to supervisor mode to allow reentry. */
    CPS     #SVC_MODE

    /* Push used registers. */
    PUSH    {r0-r4, r12}

    MOV     r0, #vector_num
    B       .Lcommon_irq_handler
    ENDM
#endif

.Lcommon_irq_handler:
    /* Save old running priority. */
    PUSH    {r0, lr}    /* Save vectore number (r0) & svc return address (lr) */
    BLX     get_vic_data_base
    ADD     r2, r0, #8  /* r2 now holds address of {struct vic_data}.cur_rp */
    POP     {r0, lr}    /* Restore vectore number (r0) & svc return address (lr) */
    LDR     r1, [r2]
    PUSH    {r1, r2}

    /* Increment nesting count.  r3 holds the address of ulPortInterruptNesting
    for future use.  r1 holds the original ulPortInterruptNesting value for
    future use. */
    LDR     r3, =ulPortInterruptNesting
    LDR     r1, [r3]
    ADD     r4, r1, #1
    STR     r4, [r3]

    /* Save address of {struct vic_data}.cur_rp into callee-saved r4. */
    MOV     r4, r2

    /* Use r5 to record errata enabled flag, save it before corrupted. */
    PUSH    {r5}

    /* Ensure bit 2 of the stack pointer is clear.  r2 holds the bit 2 value for
    future use.  _RB_ Is this ever needed provided the start of the stack is
    alligned on an 8-byte boundary? */
    MOV     r2, sp
    AND     r2, r2, #4
    SUB     sp, sp, r2

    /* Call the interrupt handler. */
    PUSH    {r0-r4, lr}
    /* Update current running priority. */
    BLX     sdrv_vic_lld_get_priority
    STR     r0, [r4]

    /* Get previous masked priority. */
    LDR     r1, [r4, #8]

    PUSH    {r0, r1}
    BLX     int_nest_errata_enabled
    MOVS    r5, r0
    BEQ     .Lno_errata

    LDR     r1, [sp]
    BLX     sdrv_vic_lld_ack_slow_path

.Lno_errata:
    POP     {r0, r1}
    /* Make sure only unmasked interrupt can be taken. */
    CMP     r0, r1
    BGE     .Lirq_out

#ifdef CONFIG_VIC_INT_NEST_AUTO_ENABLE
    LDR r0, [sp, #4]
    CMP r0, #(CONFIG_VIC_INT_NEST_MAX_CNT - 1)
    BGE .Lskip_reenable_irq
    CPSIE i
.Lskip_reenable_irq:
#endif
    /* Restore vector number */
    LDR     r0, [sp]
    /* Call user ISR. */
    ;LDR     r1, =g_vic_user_isr
    LDR     r1, [r1]
    BLX     r1
.Lirq_out:
    POP     {r0-r4, lr}
    ADD     sp, sp, r2

    CPSID   i
    DSB
    ISB

    CMP     r5, #INT_NEST_ERRATA_TYPE_0
    BEQ     .Lerrata_skip_wr_isr
    LDR     r2, [r4, #-8]
    ADD     r2, r2, #0xF00
    /* Perform a dummy write to VICADDRESS register to finish this interrupt */
    STR     r0, [r2]

.Lerrata_skip_wr_isr:
    /* Restore the old nesting count. */
    STR     r1, [r3]

    CMP     r5, #NO_INT_NEST_ERRATA
    /* Restore r5. */
    POP     {r5}

    /* Restore current running priority. */
    POP     {r0, r2}
    STR     r0, [r2]

    BEQ     .Lrestore_context
    /* Save previous nesting counter and supervisor lr (preempted isr lr). */
    PUSH    {r1, lr}
    MOV     r1, #0
    /* Unmask priority to previous state. */
    BLX     sdrv_vic_lld_mask_low_priority
    /* Restore previous nesting counter and supervisor lr. */
    POP    {r1, lr}

.Lrestore_context:
    /* A context switch is never performed if the nesting count is not 0. */
    CMP     r1, #0

    BNE     .Lexit_without_switch

    /* Did the interrupt request a context switch?  r1 holds the address of
    ulPortYieldRequired and r0 the value of ulPortYieldRequired for future
    use. */
    LDR     r1, =ulPortYieldRequired
    LDR     r0, [r1]
    CMP     r0, #0
    BNE     .Lswitch_before_exit
    B       .Lexit_without_switch

#if __GNUC__
    .ltorg
#elif __ICCARM__
    LTORG
#endif

.Lexit_without_switch:
    /* No context switch.  Restore used registers, LR_irq and SPSR before
    returning. */
    POP     {r0-r4, r12}
    CPS     #IRQ_MODE
    POP     {LR}
    MSR     SPSR_cxsf, LR
    POP     {LR}
    MOVS    PC, LR

.Lswitch_before_exit:
    /* A context swtich is to be performed.  Clear the context switch pending
    flag. */
    MOV     r0, #0
    STR     r0, [r1]

    /* Restore used registers, LR-irq and SPSR before saving the context
    to the task stack. */
    POP     {r0-r4, r12}
    CPS     #IRQ_MODE
    POP     {LR}
    MSR     SPSR_cxsf, LR
    POP     {LR}
    portSAVE_CONTEXT

    /* Call the function that selects the new task to execute.
    vTaskSwitchContext() if vTaskSwitchContext() uses LDRD or STRD
    instructions, or 8 byte aligned stack allocated data.  LR does not need
    saving as a new LR will be loaded by portRESTORE_CONTEXT anyway. */
    LDR     R0, =vTaskSwitchContext
    BLX     R0

    /* Restore the context of, and branch to, the task selected to execute
    next. */
    portRESTORE_CONTEXT

#if __GNUC__
    .ltorg
#elif __ICCARM__
    LTORG
#endif

