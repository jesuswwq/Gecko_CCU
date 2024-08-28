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

    ASM_PUBLIC arch_arm_clz
/* uint8 arch_arm_clz(uint32 x) */
ASM_FUNCTION(arch_arm_clz)
    push {r4-r11}
    clz r0, r0
    pop {r4-r11}
	bx lr
ASM_FUNCTION_END(arch_arm_clz)

    ASM_PUBLIC arch_arm_rbitu32
/* uint32 arch_arm_rbitu32(uint32 x) */
ASM_FUNCTION(arch_arm_rbitu32)
    push {r4-r11}
    rbit r0, r0
    pop {r4-r11}
	bx lr
ASM_FUNCTION_END(arch_arm_rbitu32)

#if defined(_IAR_C_)
    END
#endif
