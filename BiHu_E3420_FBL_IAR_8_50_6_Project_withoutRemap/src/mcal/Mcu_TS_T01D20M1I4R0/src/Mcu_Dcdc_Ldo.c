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

#ifdef __cplusplus
extern "C" {
#endif

#include "__regs_base.h"
#include "RegHelper.h"
#include "Mcu_Dcdc_Ldo.h"

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

int dcdc_set_vout(uint32 mv)
{
    uint32 dcdc_reg_1 = 0;
    uint32 diff = 0;

    if ((mv > 990u) ||
        (mv < 640u)) {
        return -1;
    }

    if (mv < 800U) {
        dcdc_reg_1 |= 0x01U << 4;

        if (mv > 790U) mv = 790U;

        diff = 790u - mv;
    } else {
        diff = mv - 800U;
    }

    dcdc_reg_1 |= (diff / 10U) & 0xfU;

    RMWREG32(APB_DCDC1_BASE + 0x10U, 16U, 5U, dcdc_reg_1);

    return 0;
}

#ifndef SEMIDRIVE_E3_LITE_SERIES
int ldo_set_hp_vout(uint32 mv)
{
    uint32 ldo_reg_1 = 0U;
    uint32 ratio = 0U;

    if (mv > 1910U &&
        mv < 6361U) {
        ratio = 1U;
        ldo_reg_1 = ((mv / 4U) - 320U) / 10U;
    } else if (mv < 1911U &&
               mv > 639U) {
        ratio = 0U;
        ldo_reg_1 = ((mv / 2U) - 320U) / 5U;
    } else {
        return -1;
    }

    ldo_reg_1 |= ratio << 23U;

    RMWREG32(APB_LDO_DIG_BASE + 0x08U, 16U, 8U, ldo_reg_1);
    RMWREG32(APB_LDO_DIG_BASE + 0x10U, 0U, 1U, 1);

    return 0;
}
#endif

void Mcu_DCDC_MODE_SET(void)
{
    rmw32(APB_DCDC1_BASE + 0x10u, 0, 2, 0x3);
    rmw32(APB_DCDC1_BASE + 0x18u, 0, 2, 0x3);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
