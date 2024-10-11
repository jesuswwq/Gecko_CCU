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

#include "Mcu_Mpu.h"

/* SCTLR bits */
#define SCTLR_M         (1 << 0)    /* Enable MPU */
#define SCTLR_BR        (1 << 17)   /* Enable MPU background region */

/* RBAR bits [31:5] */
#define MPU_RBAR_MASK   (0xffffffe0U)

/* RACR bits */
#define MPU_RACR_B_SHIFT    (0)     /* Bufferable */
#define MPU_RACR_C_SHIFT    (1)     /* Cacheable */
#define MPU_RACR_S_SHIFT    (2)     /* Sharable. For normal memory only. */
#define MPU_RACR_TEX_SHIFT  (3)     /* Type extension */
#define MPU_RACR_AP_SHIFT   (8)     /* Access permission */
#define MPU_RACR_XN_SHIFT   (12)    /* Execution Never */

/* RACR Access permissions */
#define RACR_AP_NO_NO   (0)     /* Privileged NO, Unprivileged NO */
#define RACR_AP_RW_NO   (1)     /* Privileged RW, Unprivileged NO */
#define RACR_AP_RW_RO   (2)     /* Privileged RW, Unprivileged RO */
#define RACR_AP_RW_RW   (3)     /* Privileged RW, Unprivileged RW */
#define RACR_AP_RO_NO   (5)     /* Privileged RO, Unprivileged NO */
#define RACR_AP_RO_RO   (6)     /* Privileged RO, Unprivileged RO */

#define MPU_RACR_CONFIG(TEX, C, B, S, AP, XN) \
    ((B << MPU_RACR_B_SHIFT)      | \
     (C << MPU_RACR_C_SHIFT)      | \
     (S << MPU_RACR_S_SHIFT)      | \
     (TEX << MPU_RACR_TEX_SHIFT)  | \
     (AP << MPU_RACR_AP_SHIFT)    | \
     (XN << MPU_RACR_XN_SHIFT))

/* Region Size and Enable Register */
#define RSR_EN           (1 << 0)   /* Enable region */
#define RSR_SIZE_SHIFT   (1)        /* Region Size = log2(size) - 1 */

#define MCU_START_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

static const uint32 g_racr_config[] = {
    [MPU_REGION_STRONGORDERED] = MPU_RACR_CONFIG(
        0, 0, 0,    /* See "TEX[2:0], C and B encodings" */
        0,          /* S bit is not used for strong ordered. */
        RACR_AP_RW_RW,
        1           /* XN */
    ),

    [MPU_REGION_DEVICE] = MPU_RACR_CONFIG(
        0, 0, 1,
        0,          /* S bit is not used for device memory */
        RACR_AP_RW_RW,
        1           /* XN */
    ),

    [MPU_REGION_NORMAL] = MPU_RACR_CONFIG(
        0, 1, 0,    /* cacheable, WB, no WA */
        0,          /* Not shared. R5 L1 cache does not cache shared
                       normal regions */
        RACR_AP_RW_RW,
        0           /* non XN */
    ),

    [MPU_REGION_NORMAL_NONCACHEABLE] = MPU_RACR_CONFIG(
        1, 0, 0,    /* non-cacheable */
        0,
        RACR_AP_RW_RW,
        0           /* non XN */
    ),

    [MPU_REGION_NO_ACCESS] = MPU_RACR_CONFIG(
        0,
        0,
        0,
        0,
        RACR_AP_NO_NO,
        0
    ),

    [MPU_REGION_READONLY] = MPU_RACR_CONFIG(
        0, 1, 1,    /* cacheable, WB, no WA */
        0,          /* Not shared. R5 L1 cache does not cache shared
                       normal regions */
        RACR_AP_RO_NO,
        0           /* non XN */
    ),
};

#define MCU_STOP_SEC_CONST_UNSPECIFIED
#include "Mcu_MemMap.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

static int log2ull(uint64 val)
{
    int i = 0;

    if (val == 0) {
        return -1;
    }

    while ((val >> i) != 1) {
        i++;
    }

    return i;
}

static int mpu_region_nr(void)
{
    uint32 val = arm_read_mpuir();
    return (int)BITS_SHIFT(val, 15, 8);   /* 0, 12 or 16 */
}

int mpu_add_region(int region, uint32 base, uint64 size,
                   mpu_region_type_e type)
{
    int Ret = 0;

    do {
        if (!(region >= 0 && region < mpu_region_nr())) {
            Ret = -1;
            break;
        }

        if (!((size & (size - 1)) == 0 && size >= 32ULL)) {
            Ret = -2;
            break;
        }

        if (base % size != 0) {
            Ret = -3;
            break;
        }

        if (type >= MPU_REGION_MAX) {
            Ret = -4;
            break;
        }
    } while (0);

    /* Calculate size field of RSR register.
     *  pow(2, sz + 1) = size
     */
    if (0 == Ret) {
        uint32 sz = (uint32)log2ull(size) - 1;
        arm_write_rgnr(region);
        arm_write_rbar(base & MPU_RBAR_MASK);
        arm_write_racr(g_racr_config[type]);
        arm_write_rsr((sz << RSR_SIZE_SHIFT) | RSR_EN);
    }

    return Ret;
}

/*
 * Enable or disable the MPU.
 *
 * MPU regions must have been configured before enabling the MPU.
 */
void mpu_enable(uint8 enable)
{
    uint32 val = arm_read_sctlr();

    if (enable)
        /* Enable MPU. The default background region is always
         * enabled as well.
         */
    {
        val |= SCTLR_BR | SCTLR_M;
    } else {
        val &= (uint32)(~SCTLR_M);
    }

    DSB;
    /* arm_write_sctlr include isb instruction*/
    arm_write_sctlr(val);
}

void mpu_reset(void)
{
    uint8 region = 0;

    /* clean all mpu region */
    for (region = 0; region < mpu_region_nr(); region++) {
        arm_write_rgnr(region);
        arm_write_rsr(0x0);
    }
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"
