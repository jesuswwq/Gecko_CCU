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

#ifndef ARCH_H
#define ARCH_H

#define DCACHE      0x01
#define ICACHE      0x02

#define CACHE_LINE      32U

#define BM_SCTLR_M  (0x01UL << 0)
#define BM_SCTLR_A  (0x01UL << 1)
#define BM_SCTLR_C  (0x01UL << 2)

#define BM_ACTLR_B1TCMPCEN  (0x01u << 27)
#define BM_ACTLR_B0TCMPCEN  (0x01u << 26)
#define BM_ACTLR_ATCMPCEN   (0x01u << 25)

#define TICKET_SHIFT 16
#define TICKET_BITS 16

#if !defined(ASSEMBLY)

#include <Mcal.h>

#define isb()   ASM_KEYWORD("isb sy")
#define dsb()   ASM_KEYWORD("dsb sy")
#define dmb()   ASM_KEYWORD("dmb sy")
#define nop()   ASM_KEYWORD("nop")

void arch_enable_branch_predict(void);
void arch_invalidate_tlb(void);

uint32 arch_rd_sctlr(void);
uint32 arch_rd_actlr(void);
void arch_wr_actlr(uint32);
void arch_wr_sctlr(uint32);

uint32 arch_rd_dfsr(void);
uint32 arch_rd_ifsr(void);
uint32 arch_rd_ifar(void);
uint32 arch_rd_dfar(void);

uint32 arch_rd_mpuir(void);
uint32 arch_rd_mpurbar(void);
uint32 arch_rd_mpurser(void);
uint32 arch_rd_mpuracr(void);
uint32 arch_rd_mpurgnr(void);
void arch_wr_mpurbar(uint32);
void arch_wr_mpurser(uint32);
void arch_wr_mpuracr(uint32);
void arch_wr_mpurgnr(uint32);
void arch_enable_async_abort(void);
void arch_disable_async_abort(void);
void arch_enable_interrupt(void);
void arch_disable_interrupt(void);

void arch_disable_cache(uint32 flags);
void arch_enable_cache(uint32 flags);
void arch_sync_cache_range(unsigned long start, uint32 len); //invalidate icache
void arch_clean_cache_range(const void *start, uint32 len);
void arch_clean_invalidate_cache_range(const void *start, uint32 len);
void arch_invalidate_cache_range(const void *start, uint32 len);
void arch_set_dcache_error_check(void);

void *memcpy_4bytes_aligned(void *dst, const void *src, uint32 bytes);
void *memclr_4bytes_aligned(void *dst, uint32 bytes);
void fast_fifo_wr32(uint32 fifo, uint32 *data, uint32 size);

static inline void flush_dcache_range(uint32 addr, uint32 size)
{
    arch_clean_invalidate_cache_range((const void *)addr, (uint32)size);
}

#endif
#endif
