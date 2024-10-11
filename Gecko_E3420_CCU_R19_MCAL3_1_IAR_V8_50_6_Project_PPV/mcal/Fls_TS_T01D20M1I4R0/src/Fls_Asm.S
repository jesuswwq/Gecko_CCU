/** *****************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Compiler.h"

#if defined(_IAR_C_)
        SECTION .text:CODE(2)
        ARM
#else
        .section ".text"
        .arm
#endif

    ASM_PUBLIC Fls_ReadPmccntr
ASM_FUNCTION(Fls_ReadPmccntr)   /* counter frequency register */
    mrc p15, 0, r0, c9, c13, 0
    isb
    bx lr
ASM_FUNCTION_END(Fls_ReadPmccntr)

    ASM_PUBLIC Fls_WritePmcr
ASM_FUNCTION(Fls_WritePmcr)  /* counter frequency register */
    mcr p15, 0, r0, c9, c12, 0
    bx lr
ASM_FUNCTION_END(Fls_WritePmcr)

    ASM_PUBLIC Fls_WritePmcntenset
ASM_FUNCTION(Fls_WritePmcntenset)  /* virtual timer value register */
    mcr p15, 0, r0, c9, c12, 1
    bx lr
ASM_FUNCTION_END(Fls_WritePmcntenset)

    ASM_PUBLIC Fls_ReadPmcnten
ASM_FUNCTION(Fls_ReadPmcnten)  /* virtual timer value register */
    mrc p15, 0, r0, c9, c12, 1
    bx lr
ASM_FUNCTION_END(Fls_ReadPmcnten)

    ASM_PUBLIC Fls_Memcpy4ByteAligned
/* void *Fls_Memcpy4ByteAligned(void* dst, void* src, uint32 bytes) */
ASM_FUNCTION(Fls_Memcpy4ByteAligned)
	push {r4-r11}
	mov r3, r0
word8_cp:
	cmp r2, #32
	blt word4_cp
	ldm r1!, {r4-r11}
	stm r0!, {r4-r11}
	sub r2, r2, #32
	b word8_cp
word4_cp:
	cmp r2, #16
	blt word2_cp
	ldm r1!, {r4-r7}
	stm r0!, {r4-r7}
	sub r2, r2, #16
	b word4_cp
word2_cp:
	cmp r2, #8
	blt word_cp
	ldm r1!, {r4-r5}
	stm r0!, {r4-r5}
	sub r2, r2, #8
	b word2_cp
word_cp:
	cmp r2, #0
	beq done
	ldr r4, [r1]
	str r4, [r0]
done:
	mov r0, r3
	pop {r4-r11}
	bx lr
ASM_FUNCTION_END(Fls_Memcpy4ByteAligned)

#if defined(_IAR_C_)
        END
#endif
/* End of file */
