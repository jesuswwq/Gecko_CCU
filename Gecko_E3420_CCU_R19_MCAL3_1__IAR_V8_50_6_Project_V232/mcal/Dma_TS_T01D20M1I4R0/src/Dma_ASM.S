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
/** *****************************************************************************************************
 * \file     Dma_Cache.S                                                                                *
 * \brief    Cache opeartions.                                                                          *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/15     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#include "Dma_ASM.h"
#include "Compiler.h"

#if defined(_IAR_C_)
    SECTION .text:CODE(2)
    ARM
#else
    .section ".text"
    .arm
#endif /** #if defined(_IAR_C_) */
    ASM_PUBLIC Dma_CleanCacheRange
    /* void Dma_CleanCacheRange(unsigned long start, uint32 len); */
ASM_FUNCTION(Dma_CleanCacheRange)
    mov     r3, r0                      // save the start address
    add     r2, r0, r1                  // calculate the end address
    bic     r0, r0, #(DMA_CACHE_LINE-1)         // align the start with a cache line
Dma_CleanLoop:
    mcr     p15, 0, r0, c7, c10, 1      // clean cache to PoC by MVA
    add     r0, r0, #DMA_CACHE_LINE
    cmp     r0, r2
    blo     Dma_CleanLoop

    dsb
    bx      lr

    ASM_PUBLIC Dma_CleanInvalidateCacheRange
    /* void Dma_CleanInvalidateCacheRange(unsigned long start, uint32 len); */
ASM_FUNCTION(Dma_CleanInvalidateCacheRange)
    mov     r3, r0                      // save the start address
    add     r2, r0, r1                  // calculate the end address
    bic     r0, r0, #(DMA_CACHE_LINE-1)         // align the start with a cache line
Dma_FlushLoop:
    mcr     p15, 0, r0, c7, c14, 1      // clean & invalidate dcache to PoC by MVA
    add     r0, r0, #DMA_CACHE_LINE
    cmp     r0, r2
    blo     Dma_FlushLoop
    dsb
    bx      lr

    ASM_PUBLIC Dma_InvalidateCacheRange
    /* void Dma_InvalidateCacheRange(unsigned long start, uint32 len); */
ASM_FUNCTION(Dma_InvalidateCacheRange)
    mov     r3, r0                      // save the start address
    add     r2, r0, r1                  // calculate the end address
    bic     r0, r0, #(DMA_CACHE_LINE-1)         // align the start with a cache line
Dma_InvLoop:
    mcr     p15, 0, r0, c7, c6, 1       // invalidate dcache to PoC by MVA
    add     r0, r0, #DMA_CACHE_LINE
    cmp     r0, r2
    blo     Dma_InvLoop
    dsb
    bx      lr

    ASM_PUBLIC Dma_ArchAtomicOr
ASM_FUNCTION(Dma_ArchAtomicOr)
.Lloop_atomic_or:
    ldrex   r12, [r0]
    orr     r2, r12, r1
    strex   r3, r2, [r0]
    cmp     r3, #0
    bne     .Lloop_atomic_or
    mov     r0, r12
    bx      lr
ASM_FUNCTION_END(Dma_ArchAtomicOr)

    ASM_PUBLIC Dma_ArchAtomicAnd
ASM_FUNCTION(Dma_ArchAtomicAnd)
.Lloop_atomic_and:
    ldrex   r12, [r0]
    and     r2, r12, r1
    strex   r3, r2, [r0]
    cmp     r3, #0
    bne     .Lloop_atomic_and
    mov     r0, r12
    bx      lr
ASM_FUNCTION_END(Dma_ArchAtomicAnd)

#if defined(_IAR_C_)
    END
#endif /** #if defined(_IAR_C_) */
/* End of file */
