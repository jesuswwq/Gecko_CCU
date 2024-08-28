/********************************************************
 *	        Copyright(c) 2018	Semidrive 		        *
 *******************************************************/

#include "asm_def.h"

#if defined(__ARMCC_VERSION)
.eabi_attribute Tag_ABI_align_preserved, 1
#endif

	ASM_EXTERN default_exception_hdlr_s
    ASM_EXTERN reset_hdlr
    ASM_EXTERN irq_hdlr_s
    ASM_EXTERN fiq_hdlr_s
    ASM_EXTERN FreeRTOS_IRQ_Handler
    ASM_EXTERN FreeRTOS_SWI_Handler
    ASM_EXTERN tpl_primary_irq_handler
    ASM_EXTERN tpl_primary_syscall_handler
    ASM_EXTERN osFiqHandler
    ASM_EXTERN osIrqHandler
    ASM_EXTERN AutosarOsIrqHandler
    ASM_EXTERN TrapExceptionHandler
    ASM_EXTERN SVC_Entry

#if defined(__ICCARM__)
    SECTION .vector:CODE(2)
    ARM
#else
    .section ".text.vector"
    .arm
#endif

_vector_tbl:
	ldr pc, reset_addr
	ldr pc, undefined_addr
	ldr pc, syscall_addr
	ldr pc, prefetch_addr
	ldr pc, data_abort_addr
	b .							// Reserved
	ldr pc, irq_addr
	ldr pc, fiq_addr

reset_addr: 		ASM_WORD reset_hdlr
undefined_addr:		ASM_WORD default_exception_hdlr_s //TrapExceptionHandler

syscall_addr:		ASM_WORD SVC_Entry

prefetch_addr:		ASM_WORD default_exception_hdlr_s //TrapExceptionHandler
data_abort_addr:	ASM_WORD default_exception_hdlr_s //TrapExceptionHandler


irq_addr:			ASM_WORD AutosarOsIrqHandler
fiq_addr:			ASM_WORD osFiqHandler
padding:			ASM_WORD 0

#if defined(_IAR_C_)
    END
#endif
