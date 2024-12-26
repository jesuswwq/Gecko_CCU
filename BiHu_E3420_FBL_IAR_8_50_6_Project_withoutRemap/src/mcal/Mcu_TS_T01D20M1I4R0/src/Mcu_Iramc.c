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

#include "RegHelper.h"
#include "Mcu_Iramc.h"
#include "Iramc_Reg.h"

/* Version and Check Begin */
/* Version Info Begin */
#define MCU_IRAMC_C_VENDOR_ID    0x8C
#define MCU_IRAMC_C_AR_RELEASE_MAJOR_VERSION    4
#define MCU_IRAMC_C_AR_RELEASE_MINOR_VERSION    3
#define MCU_IRAMC_C_AR_RELEASE_REVISION_VERSION 1
#define MCU_IRAMC_C_SW_MAJOR_VERSION    1
#define MCU_IRAMC_C_SW_MINOR_VERSION    0
#define MCU_IRAMC_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_IRAMC_C_AR_RELEASE_MAJOR_VERSION != MCU_IRAMC_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_IRAMC_C_AR_RELEASE_MINOR_VERSION != MCU_IRAMC_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_IRAMC_C_AR_RELEASE_REVISION_VERSION != MCU_IRAMC_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Iramc.c and Mcu_Iramc.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_IRAMC_C_SW_MAJOR_VERSION != MCU_IRAMC_H_SW_MAJOR_VERSION)\
    || (MCU_IRAMC_C_SW_MINOR_VERSION != MCU_IRAMC_H_SW_MINOR_VERSION)\
    || (MCU_IRAMC_C_SW_PATCH_VERSION != MCU_IRAMC_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Iramc.c and Mcu_Iramc.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_IRAMC_C_AR_RELEASE_MAJOR_VERSION != IRAMC_REG_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_IRAMC_C_AR_RELEASE_MINOR_VERSION != IRAMC_REG_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_IRAMC_C_AR_RELEASE_REVISION_VERSION != IRAMC_REG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Iramc.c and Iramc_Reg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_IRAMC_C_SW_MAJOR_VERSION != IRAMC_REG_H_SW_MAJOR_VERSION)\
    || (MCU_IRAMC_C_SW_MINOR_VERSION != IRAMC_REG_H_SW_MINOR_VERSION)\
    || (MCU_IRAMC_C_SW_PATCH_VERSION != IRAMC_REG_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Iramc.c and Iramc_Reg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

void Mcu_IramcPowerCfg(uint32 base, iramc_power_mode_e mode)
{
    uint32 v = readl(base + IRAMC_WRAP_POWER_CFG);

    v &= ~FM_IRAMC_WRAP_POWER_CFG_VAL;
    v |= FV_IRAMC_WRAP_POWER_CFG_VAL(mode);

    writel(v, base + IRAMC_WRAP_POWER_CFG);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
