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

    ASM_PUBLIC memcpy_4bytes_aligned
/* void *memcpy_4bytes_aligned(void* dst, void* src, uint32 bytes) */
ASM_FUNCTION(memcpy_4bytes_aligned)
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
ASM_FUNCTION_END(memcpy_4bytes_aligned)

#if defined(_IAR_C_)
    END
#endif
