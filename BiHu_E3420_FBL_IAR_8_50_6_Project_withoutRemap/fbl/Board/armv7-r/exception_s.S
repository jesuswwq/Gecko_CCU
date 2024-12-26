/********************************************************
 *	        Copyright(c) 2018	Semidrive 		        *
 *******************************************************/

#include "asm_def.h"

#if defined(_IAR_C_)
    SECTION .text:CODE(2)
    ARM
#else
    .section ".text"
    .arm
#endif

    ASM_EXTERN default_exception_hdlr
    ASM_PUBLIC default_exception_hdlr_s
ASM_FUNCTION(default_exception_hdlr_s)
    /* save spsr and r14 onto the svc stack */
	srsdb #0x13!
	/* change to svc mode, disable interrupt */
	cpsid i, #0x13	// we are in svc now
	push {r0-r12, lr}
	mov r0, sp
	bl default_exception_hdlr
    pop {r0-r12, lr}
    RFEFD sp!
    b .		// default_exception_hdlr will not return, add a loop here in case.
    
#if defined(_IAR_C_)
    END
#endif
