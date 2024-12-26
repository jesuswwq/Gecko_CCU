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

#include "Compiler.h"

#if defined(_IAR_C_)
    SECTION .text:CODE(2)
    ARM
#else
    .section ".text"
    .arm
#endif

    ASM_PUBLIC arch_go_idle
ASM_FUNCTION(arch_go_idle)
    wfi
    bx lr

    ASM_PUBLIC arch_invalidate_tlb
ASM_FUNCTION(arch_invalidate_tlb)
    mov  r0, #0
    mcr  p15, 0, r0, c8, c7, 0
    bx   lr

    ASM_PUBLIC arch_enable_branch_predict
/* Note: call this function after MPU been properly configured */
ASM_FUNCTION(arch_enable_branch_predict)
    mrc p15, 0, r0, c1, c0, 1    // ACTLR
    bic r0, r0, #(0x1 << 17)    // Clear RSDIS to enable return stack
    bic r0, r0, #(0x1 << 16)    // BP=00: Normal operation, branch prediction enabled
    bic r0, r0, #(0x1 << 15)
    mcr p15, 0, r0, c1, c0, 1
    isb
    bx     lr

    ASM_PUBLIC arch_rd_sctlr
ASM_FUNCTION(arch_rd_sctlr)
    mrc p15, 0, r0, c1, c0, 0
    bx lr

    ASM_PUBLIC arch_wr_sctlr
ASM_FUNCTION(arch_wr_sctlr)
    mcr p15, 0, r0, c1, c0, 0
    bx lr

    ASM_PUBLIC arch_rd_actlr
ASM_FUNCTION(arch_rd_actlr)
    mrc p15, 0, r0, c1, c0, 1
    bx lr

    ASM_PUBLIC arch_wr_actlr
ASM_FUNCTION(arch_wr_actlr)
    mcr p15, 0, r0, c1, c0, 1
    bx lr

    ASM_PUBLIC arch_rd_dfsr
ASM_FUNCTION(arch_rd_dfsr)
    mrc p15, 0, r0, c5, c0, 0
    bx lr

    ASM_PUBLIC arch_rd_ifsr
ASM_FUNCTION(arch_rd_ifsr)
    mrc p15, 0, r0, c5, c0, 1
    bx lr

    ASM_PUBLIC arch_rd_ifar
ASM_FUNCTION(arch_rd_ifar)
    mrc p15, 0, r0, c6, c0, 2
    bx lr

    ASM_PUBLIC arch_rd_dfar
ASM_FUNCTION(arch_rd_dfar)
    mrc p15, 0, r0, c6, c0, 0
    bx lr

    ASM_PUBLIC arch_rd_mpuir
ASM_FUNCTION(arch_rd_mpuir)
    mrc p15, 0, r0, c0, c0, 4
    bx lr

    ASM_PUBLIC arch_rd_mpurbar
/* Read MPU Region Base Address Register */
ASM_FUNCTION(arch_rd_mpurbar)
    mrc p15, 0, r0, c6, c1, 0
    bx lr

    ASM_PUBLIC arch_wr_mpurbar
ASM_FUNCTION(arch_wr_mpurbar)
    mcr p15, 0, r0, c6, c1, 0
    bx lr

    ASM_PUBLIC arch_rd_mpurser
/* Read MPU Region Size and Enable Register */
ASM_FUNCTION(arch_rd_mpurser)
    mrc p15, 0, r0, c6, c1, 2
    bx lr

    ASM_PUBLIC arch_wr_mpurser
ASM_FUNCTION(arch_wr_mpurser)
    mcr p15, 0, r0, c6, c1, 2
    bx lr

    ASM_PUBLIC arch_rd_mpuracr
/* Read MPU Region Access Control Register */
ASM_FUNCTION(arch_rd_mpuracr)
    mrc p15, 0, r0, c6, c1, 4
    bx lr

    ASM_PUBLIC arch_wr_mpuracr
ASM_FUNCTION(arch_wr_mpuracr)
    mcr p15, 0, r0, c6, c1, 4
    bx lr

    ASM_PUBLIC arch_rd_mpurgnr
/* Read MPU Region Number Register */
ASM_FUNCTION(arch_rd_mpurgnr)
    mrc p15, 0, r0, c6, c2, 0
    bx lr

    ASM_PUBLIC arch_wr_mpurgnr
ASM_FUNCTION(arch_wr_mpurgnr)
    mcr p15, 0, r0, c6, c2, 0
    bx lr

    ASM_PUBLIC arch_rd_ccsidr
ASM_FUNCTION(arch_rd_ccsidr)
    mrc p15, 1, r0, c0, c0, 0
    bx lr

    ASM_PUBLIC arch_disable_interrupt
ASM_FUNCTION(arch_disable_interrupt)
    cpsid if
    bx lr

    ASM_PUBLIC arch_enable_interrupt
ASM_FUNCTION(arch_enable_interrupt)
    cpsie if
    bx lr

    ASM_PUBLIC arch_disable_async_abort
ASM_FUNCTION(arch_disable_async_abort)
    cpsid a
    isb
    dsb
    bx lr

    ASM_PUBLIC arch_enable_async_abort
ASM_FUNCTION(arch_enable_async_abort)
    cpsie a
    isb
    dsb
    bx lr

    ASM_PUBLIC arch_get_cur_pc
ASM_FUNCTION(arch_get_cur_pc)
    mov r0, pc
    bx lr

    ASM_PUBLIC arch_get_cpuid
ASM_FUNCTION(arch_get_cpuid)
    /*
        SF:0xC0000000 SP0:0xC0000100 SP1:0xC0000101
        SX0:0xC0000200 SX1:0xC0000201 SP = SP0 SX = SX0
    */
    mrc p15, 0, r0, c0, c0, 5
    bfi r0, r0, #7, #1
    lsr r0,#7
    and r0,#0xFF
    /* adjust core id since sf is lockstep always */
    cmp r0, #0
    subne r0, #1
    bx  lr

    ASM_PUBLIC Mcu_GetTcmBase
ASM_FUNCTION(Mcu_GetTcmBase)
    /*
        TCM Mem Map TCMB_Start---TCMB_Start+TCMB_SIZE(TCMA_Start)----TCMA + TCMA_ZISE(TCM End)
    */
    mrc p15, 0, r0, c9, c1, 0
    ldr r1,=0xFFFF
    bic r0 ,r0,r1
    bx  lr

    ASM_PUBLIC Mcu_GetTcmSize
    /* uint32 Mcu_GetTcmSize(void) */
ASM_FUNCTION(Mcu_GetTcmSize)
    /*
        ATCM & BTCM always availability
    */
    mrc p15, 0, r1, c9, c1, 1
    /* r1 now contains ATCM size in bits[6:2] */
    mrc p15, 0, r2, c9, c1, 0
    /* r2 now contains BTCM size in bits[6:2] */
    mov r0, #0x200
    lsr r1, r1, #2
    and r1, r1, #0x1f
    /* ATCM Region Register [4:0] */
    lsl r1, r0, r1
    /* r1 now contains ATCM size */
    lsr r2, r2, #2
    and r2, r2, #0x1f
    /* BTCM Region Register [4:0] */
    lsl r2, r0,r2
    /* r2 now contains ATCM size */
	add r0, r1, r2
    bx  lr

#if defined(_IAR_C_)
    END
#endif
