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

#ifndef MCU_MPU_H
#define MCU_MPU_H

#include <Std_Types.h>

#define ISB __asm volatile("ISB" : : : "memory")
#define DMB __asm volatile("DMB" : : : "memory")
#define DSB __asm volatile("DSB" : : : "memory")
#define barriers __asm volatile("" : : : "memory")

#define BITS_SHIFT(x, high, low) (((x) >> (low)) & ((1UL<<((high)-(low)+1))-1))

#define GEN_CP_REG_FUNCS(cp, reg, op1, c1, c2, op2) \
static inline uint32 arm_read_##reg(void) { \
    uint32 val; \
    ASM volatile("mrc " #cp ", " #op1 ", %0, " #c1 ","  #c2 "," #op2 : "=r" (val)); \
    return val; \
} \
\
static inline uint32 arm_read_##reg##_relaxed(void) { \
    uint32 val; \
    ASM("mrc " #cp ", " #op1 ", %0, " #c1 ","  #c2 "," #op2 : "=r" (val)); \
    return val; \
} \
\
static inline void arm_write_##reg(uint32 val) { \
    ASM volatile("mcr " #cp ", " #op1 ", %0, " #c1 ","  #c2 "," #op2 :: "r" (val)); \
    ISB; \
} \
\
static inline void arm_write_##reg##_relaxed(uint32 val) { \
   ASM volatile("mcr " #cp ", " #op1 ", %0, " #c1 ","  #c2 "," #op2 :: "r" (val)); \
}

#define GEN_CP15_REG_FUNCS(reg, op1, c1, c2, op2) \
    GEN_CP_REG_FUNCS(p15, reg, op1, c1, c2, op2)

#define GEN_CP14_REG_FUNCS(reg, op1, c1, c2, op2) \
    GEN_CP_REG_FUNCS(p14, reg, op1, c1, c2, op2)

/* armv6+ control regs */
GEN_CP15_REG_FUNCS(sctlr, 0, c1, c0, 0)

/* mpu registers (using unified memory regions) */
GEN_CP15_REG_FUNCS(mpuir, 0, c0, c0, 4)
GEN_CP15_REG_FUNCS(rbar, 0, c6, c1, 0)
GEN_CP15_REG_FUNCS(rsr, 0, c6, c1, 2)
GEN_CP15_REG_FUNCS(racr, 0, c6, c1, 4)
GEN_CP15_REG_FUNCS(rgnr, 0, c6, c2, 0)

typedef enum mpu_region_type {
    /* Strong ordered
     *  - non-bufferable, non-cachable, shareable, RW, XN
     */
    MPU_REGION_STRONGORDERED,

    /* Device memory
     *  - bufferable, non-cachable, shareable, RW, XN
     */
    MPU_REGION_DEVICE,

    /* Normal memory
     *  - bufferable, outer and inner write-back & write allocate,
     *    shareble, RW, non XN
     */
    MPU_REGION_NORMAL,

    /* Normal non-cacheable memory
     *  - bufferable, outer and inner non-cacheable, shareble, RW,
     *    non XN
     */
    MPU_REGION_NORMAL_NONCACHEABLE,

    /* Not accessable.
     */
    MPU_REGION_NO_ACCESS,

    /* read only, executable .
     */
    MPU_REGION_READONLY,

    MPU_REGION_MAX,
} mpu_region_type_e;

/* The region base address for setting DDR memory type as Normal */
#define DDR_REGION_BASE         (0x30000000u)
/* The region size for setting DDR memory type as Normal */
#define DDR_REGION_SIZE         (0x10000000u)
/* The region base address for setting IRAM memory type as Normal */
#define IRAM_REGION_BASE        (0x100000u)
/* The region size for setting IRAM memory type as Normal */
#define IRAM_REGION_SIZE        (0x100000u)
/* The region base address for setting VECTOR memory type as Normal */
#define VECTORTBL_REGION_BASE   (0u)
/* The region size for setting IRAM memory type as Normal */
#define VECTORTBL_REGION_SIZE   (0x1000u)
/* The region base address for opsi1 */
#define OSPI1_REGION_BSAE       (0x4000000u)
/* The region size for opsi1 */
#define OSPI1_REGION_SIZE       (0x4000000u)
/* The region base address for setting TCMB memory type as Normal */
#define TCMB_REGION_BASE        (0x4B0000u)
/* The region size for setting TCMB memory type as Normal */
#define TCMB_REGION_SIZE        (0x10000u)
/* The region base address for setting TCMA memory type as Normal */
#define TCMA_REGION_BASE        (0x4C0000u)
/* The region size for setting TCMA memory type as Normal */
#define TCMA_REGION_SIZE        (0x10000u)

void mpu_enable(uint8 enable);
int mpu_add_region(int region, uint32 base, uint64 size,
                   mpu_region_type_e type);
void mpu_init(void);
void mpu_reset();

static inline int mpu_cfg_region(int region, uint32 base, uint64 size,
                                 mpu_region_type_e type)
{
    return mpu_add_region(region, base, size, type);
}

#endif  /*MCU_MPU_H*/
