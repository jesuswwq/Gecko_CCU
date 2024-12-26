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
#include "Mcu_Xtal.h"
#include "Xtal_Reg.h"

/* Version and Check Begin */
/* Version Info Begin */
#define MCU_XTAL_C_VENDOR_ID    0x8C
#define MCU_XTAL_C_AR_RELEASE_MAJOR_VERSION    4
#define MCU_XTAL_C_AR_RELEASE_MINOR_VERSION    3
#define MCU_XTAL_C_AR_RELEASE_REVISION_VERSION 1
#define MCU_XTAL_C_SW_MAJOR_VERSION    1
#define MCU_XTAL_C_SW_MINOR_VERSION    0
#define MCU_XTAL_C_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_XTAL_C_AR_RELEASE_MAJOR_VERSION != MCU_XTAL_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_XTAL_C_AR_RELEASE_MINOR_VERSION != MCU_XTAL_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_XTAL_C_AR_RELEASE_REVISION_VERSION != MCU_XTAL_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Xtal.c and Mcu_Xtal.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_XTAL_C_SW_MAJOR_VERSION != MCU_XTAL_H_SW_MAJOR_VERSION)\
    || (MCU_XTAL_C_SW_MINOR_VERSION != MCU_XTAL_H_SW_MINOR_VERSION)\
    || (MCU_XTAL_C_SW_PATCH_VERSION != MCU_XTAL_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Xtal.c and Mcu_Xtal.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_XTAL_C_AR_RELEASE_MAJOR_VERSION != XTAL_REG_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_XTAL_C_AR_RELEASE_MINOR_VERSION != XTAL_REG_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_XTAL_C_AR_RELEASE_REVISION_VERSION != XTAL_REG_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Xtal.c and Xtal_Reg.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_XTAL_C_SW_MAJOR_VERSION != XTAL_REG_H_SW_MAJOR_VERSION)\
    || (MCU_XTAL_C_SW_MINOR_VERSION != XTAL_REG_H_SW_MINOR_VERSION)\
    || (MCU_XTAL_C_SW_PATCH_VERSION != XTAL_REG_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Xtal.c and Xtal_Reg.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define MCU_START_SEC_CODE
#include "Mcu_MemMap.h"

uint8 Mcu_GetXtal32KStatus(void)
{
    uint32 b = FS_32K_BASE_ADDR;
    uint32 v = readl(b + FS_32K_XTAL_CTL) ;

    v &= XTAL_CTRL_STATE;

    return v;
}

void Mcu_Xtal32KEnable(xtal_ctrl_e en)
{
    uint32 b = FS_32K_BASE_ADDR;
    uint32 v = readl(b + FS_32K_XTAL_CTL);

    if (en == XTAL_ENABLE) {
        v |= BM_FS_32K_XTAL_CTL_E0;
    } else {
        v &= ~BM_FS_32K_XTAL_CTL_E0;
    }

    writel(v, b + FS_32K_XTAL_CTL);
}

uint8 Mcu_GetLpvdPowerStatus(void)
{
    uint32 b = FS_32K_BASE_ADDR;
    uint32 v = readl(b + FS_32K_LPVD_CTL) ;

    v &= LPVD_POWER_STATE;

    return v;
}

void Mcu_LpvdPowerSwitch(lpvd_ctrl_e pd)
{
    uint32 v = readl(FS_32K_BASE_ADDR + FS_32K_LPVD_CTL);

    if (pd == LPVD_POWER_DOWN) {
        v |= BM_FS_32K_LPVD_CTL_PD;
    } else {
        v &= ~BM_FS_32K_LPVD_CTL_PD;
    }

    writel(v, FS_32K_BASE_ADDR + FS_32K_LPVD_CTL);
}

#define MCU_STOP_SEC_CODE
#include "Mcu_MemMap.h"

#ifdef __cplusplus
}
#endif
