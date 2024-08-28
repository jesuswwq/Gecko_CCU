/*
* SEMIDRIVE Copyright Statement
* Copyright (c) SEMIDRIVE. All rights reserved
*
* This software and all rights therein are owned by SEMIDRIVE, and are
* protected by copyright law and other relevant laws, regulations and
* protection. Without SEMIDRIVE's prior written consent and/or related rights,
* please do not use this software or any potion thereof in any form or by any
* means. You may not reproduce, modify or distribute this software except in
* compliance with the License. Unless required by applicable law or agreed to
* in writing, software distributed under the License is distributed on
* an "AS IS" basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.
*
* You should have received a copy of the License along with this program.
* If not, see <http://www.semidrive.com/licenses/>.
*/

#include "arch.h"
#include "Compiler.h"

#if defined(_IAR_C_)
    SECTION .text:CODE(2)
    ARM
#else
    .section ".text"
    .arm
#endif

    ASM_PUBLIC arch_disable_cache
/* void arch_disable_cache(uint32 flags) */
ASM_FUNCTION(arch_disable_cache)
    stmfd   sp!, {r4-r11, lr}

    mov     r7, r0                      // save flags

    mrs     r8, cpsr                    // save the old interrupt state
    cpsid   iaf                         // interrupts disabled

.Ldcache_disable:
    tst     r7, #DCACHE
    beq     .Licache_disable
    mrc     p15, 0, r0, c1, c0, 0       // cr1
    tst     r0, #(1<<2)                 // is the dcache already disabled?
    beq     .Ldcache_already_disabled

    bic     r0, r0, #(1<<2)
    mcr     p15, 0, r0, c1, c0, 0       // disable dcache

    // clean and invalidate the dcache
    // NOTE: trashes a bunch of registers, can't be spilling stuff to the stack
    bl      clean_invalidate_cache_v7

    b       .Ldcache_disable_L2

.Ldcache_already_disabled:
    // make sure all of the caches are invalidated
    // NOTE: trashes a bunch of registers, can't be spilling stuff to the stack
    bl      invalidate_cache_v7

.Ldcache_disable_L2:

.Licache_disable:
    tst     r7, #ICACHE
    beq     .Ldone_disable

    mrc     p15, 0, r0, c1, c0, 0       // cr1
    bic     r0, r0, #(1<<12)
    mcr     p15, 0, r0, c1, c0, 0       // disable icache

.Ldone_disable:
    // make sure the icache is always invalidated
    mov     r0, #0
    mcr     p15, 0, r0, c7, c5, 0       // invalidate icache to PoU

    msr     cpsr_cxsf, r8
    ldmfd   sp!, {r4-r11, pc}
ASM_FUNCTION_END(arch_disable_cache)

    ASM_PUBLIC arch_enable_cache
/* void arch_enable_cache(uint32 flags) */
ASM_FUNCTION(arch_enable_cache)
    stmfd   sp!, {r4-r12, lr}

    mov     r7, r0                      // save flags

    mrs     r8, cpsr                    // save the old interrupt state
    cpsid   iaf                         // interrupts disabled

.Ldcache_enable:
    tst     r7, #DCACHE
    beq     .Licache_enable
    mrc     p15, 0, r0, c1, c0, 0       // cr1
    tst     r0, #(1<<2)                 // is the dcache already enabled?
    bne     .Licache_enable

    // invalidate L1 and L2
    // NOTE: trashes a bunch of registers, can't be spilling stuff to the stack
    bl      invalidate_cache_v7

    mrc     p15, 0, r0, c1, c0, 0       // cr1
    orr     r0, r0, #(1<<2)
    mcr     p15, 0, r0, c1, c0, 0       // enable dcache

.Licache_enable:
    tst     r7, #ICACHE
    beq     .Ldone_enable

    mov     r0, #0
    mcr     p15, 0, r0, c7, c5, 0       // invalidate icache to PoU

    mrc     p15, 0, r0, c1, c0, 0       // cr1
    orr     r0, r0, #(1<<12)
    mcr     p15, 0, r0, c1, c0, 0       // enable icache

.Ldone_enable:
    isb
    msr     cpsr_cxsf, r8
    ldmfd   sp!, {r4-r12, pc}

ASM_FUNCTION_END(arch_enable_cache)

    ASM_PUBLIC clean_invalidate_cache_v7
    /* clean & invalidate cache routine, trashes r0-r6, r9-r11 */
ASM_FUNCTION(clean_invalidate_cache_v7)
    /* from ARMv7 manual, B2-17 */
    dmb
    MRC     p15, 1, R0, c0, c0, 1       // Read CLIDR
    ANDS    R3, R0, #0x7000000
    MOV     R3, R3, LSR #23             // Cache level value (naturally aligned)
    BEQ     .Lfinished
    MOV     R10, #0
.Loop1:
    ADD     R2, R10, R10, LSR #1        // Work out 3xcachelevel
    MOV     R1, R0, LSR R2              // bottom 3 bits are the Cache type for this level
    AND     R1, R1, #7                  // get those 3 bits alone
    CMP     R1, #2
    BLT     .Lskip                      // no cache or only instruction cache at this level
    MCR     p15, 2, R10, c0, c0, 0      // write the Cache Size selection register
    isb                                 // ISB to sync the change to the CacheSizeID reg
    MRC     p15, 1, R1, c0, c0, 0       // reads current Cache Size ID register
    AND     R2, R1, #0x7                // extract the line length field
    ADD     R2, R2, #4                  // add 4 for the line length offset (log2 16 bytes)
    LDR     R4, =0x3FF
    ANDS    R4, R4, R1, LSR #3          // R4 is the max number on the way size (right aligned)
    CLZ     R5, R4                      // R5 is the bit position of the way size increment
    LDR     R6, =0x00007FFF
    ANDS    R6, R6, R1, LSR #13         // R6 is the max number of the index size (right aligned)
.Loop2:
    MOV     R9, R4                      // R9 working copy of the max way size (right aligned)
.Loop3:
    ORR     R11, R10, R9, LSL R5        // factor in the way number and cache number into R11
    ORR     R11, R11, R6, LSL R2        // factor in the index number
    MCR     p15, 0, R11, c7, c14, 2     // clean & invalidate by set/way
    SUBS    R9, R9, #1                  // decrement the way number
    BGE     .Loop3
    SUBS    R6, R6, #1                  // decrement the index
    BGE     .Loop2
.Lskip:
    ADD     R10, R10, #2                    // increment the cache number
    CMP     R3, R10
    BGT     .Loop1

.Lfinished:
    mov     r10, #0
    mcr     p15, 2, r10, c0, c0, 0      // select cache level 0
    dsb
    isb

    bx      lr
ASM_FUNCTION_END(clean_invalidate_cache_v7)

    ASM_PUBLIC invalidate_cache_v7
    /* invalidate cache routine, trashes r0-r6, r9-r11 */
ASM_FUNCTION(invalidate_cache_v7)
    /* from ARMv7 manual, B2-17 */
    dmb
    MRC     p15, 1, R0, c0, c0, 1       // Read CLIDR
    ANDS    R3, R0, #0x7000000
    MOV     R3, R3, LSR #23             // Cache level value (naturally aligned)
    BEQ     .Lfinished_invalidate
    MOV     R10, #0
.Loop1_invalidate:
    ADD     R2, R10, R10, LSR #1        // Work out 3xcachelevel
    MOV     R1, R0, LSR R2              // bottom 3 bits are the Cache type for this level
    AND     R1, R1, #7                  // get those 3 bits alone
    CMP     R1, #2
    BLT     .Lskip_invalidate           // no cache or only instruction cache at this level
    MCR     p15, 2, R10, c0, c0, 0      // write the Cache Size selection register
    isb                                 // ISB to sync the change to the CacheSizeID reg
    MRC     p15, 1, R1, c0, c0, 0       // reads current Cache Size ID register
    AND     R2, R1, #0x7                // extract the line length field
    ADD     R2, R2, #4                  // add 4 for the line length offset (log2 16 bytes)
    LDR     R4, =0x3FF
    ANDS    R4, R4, R1, LSR #3          // R4 is the max number on the way size (right aligned)
    CLZ     R5, R4                      // R5 is the bit position of the way size increment
    LDR     R6, =0x00007FFF
    ANDS    R6, R6, R1, LSR #13         // R6 is the max number of the index size (right aligned)
.Loop2_invalidate:
    MOV     R9, R4                      // R9 working copy of the max way size (right aligned)
.Loop3_invalidate:
    ORR     R11, R10, R9, LSL R5        // factor in the way number and cache number into R11
    ORR     R11, R11, R6, LSL R2        // factor in the index number
    MCR     p15, 0, R11, c7, c6, 2      // invalidate by set/way
    SUBS    R9, R9, #1                  // decrement the way number
    BGE     .Loop3_invalidate
    SUBS    R6, R6, #1                  // decrement the index
    BGE     .Loop2_invalidate
.Lskip_invalidate:
    ADD     R10, R10, #2                // increment the cache number
    CMP     R3, R10
    BGT     .Loop1_invalidate

.Lfinished_invalidate:
    dsb
    mov     r10, #0
    mcr     p15, 2, r10, c0, c0, 0      // select cache level 0
    isb

    bx      lr
ASM_FUNCTION_END(invalidate_cache_v7)

    ASM_PUBLIC arch_clean_cache_range
    /* void arch_clean_cache_range(unsigned long start, uint32 len); */
ASM_FUNCTION(arch_clean_cache_range)
    mov     r3, r0                      // save the start address
    add     r2, r0, r1                  // calculate the end address
    bic     r0, r0, #(CACHE_LINE-1)         // align the start with a cache line
clean_loop:
    mcr     p15, 0, r0, c7, c10, 1      // clean cache to PoC by MVA
    add     r0, r0, #CACHE_LINE
    cmp     r0, r2
    blo     clean_loop

    dsb
    bx      lr
ASM_FUNCTION_END(arch_clean_cache_range)

    ASM_PUBLIC arch_clean_invalidate_cache_range
    /* void arch_clean_invalidate_cache_range(unsigned long start, uint32 len); */
ASM_FUNCTION(arch_clean_invalidate_cache_range)
    mov     r3, r0                      // save the start address
    add     r2, r0, r1                  // calculate the end address
    bic     r0, r0, #(CACHE_LINE-1)         // align the start with a cache line
flush_loop:
    mcr     p15, 0, r0, c7, c14, 1      // clean & invalidate dcache to PoC by MVA
    add     r0, r0, #CACHE_LINE
    cmp     r0, r2
    blo     flush_loop
    dsb
    bx      lr
ASM_FUNCTION_END(arch_clean_invalidate_cache_range)

    ASM_PUBLIC arch_invalidate_cache_range
    /* void arch_invalidate_cache_range(unsigned long start, uint32 len); */
ASM_FUNCTION(arch_invalidate_cache_range)
    mov     r3, r0                      // save the start address
    add     r2, r0, r1                  // calculate the end address
    bic     r0, r0, #(CACHE_LINE-1)         // align the start with a cache line
inv_loop:
    mcr     p15, 0, r0, c7, c6, 1       // invalidate dcache to PoC by MVA
    add     r0, r0, #CACHE_LINE
    cmp     r0, r2
    blo     inv_loop
    dsb
    bx      lr
ASM_FUNCTION_END(arch_invalidate_cache_range)

    ASM_PUBLIC arch_sync_cache_range
    /* void arch_sync_cache_range(unsigned long start, uint32 len); */
ASM_FUNCTION(arch_sync_cache_range)
    push    { r14 }
    bl      arch_clean_cache_range

    mov     r0, #0
    mcr     p15, 0, r0, c7, c5, 0       // invalidate icache to PoU

    pop     { pc }
ASM_FUNCTION_END(arch_sync_cache_range)

/*Set DCACHE error check*/
    ASM_PUBLIC    arch_set_dcache_error_check
ASM_FUNCTION(arch_set_dcache_error_check)
    mrc p15, 0, r1, c1, c0, 1          // read auxiliary control register
    orr r1,    r1,    #0x1 << 5              // b101:do not generate abort on ecc errors, enable hardware recover
    bic r1,    r1,    #0x1 << 4
    orr r1,    r1,    #0x1 << 3
    mcr p15, 0, r1, c1, c0, 1          // write auxiliary control register
    isb
    bx lr
ASM_FUNCTION_END(arch_set_dcache_error_check)

#if defined(_IAR_C_)
    END
#endif
