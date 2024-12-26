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

#ifndef __MCU_XTAL_H__
#define __MCU_XTAL_H__
#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
/* Version and Check Begin */
/* Version Info Begin */
#define MCU_XTAL_H_VENDOR_ID    0x8C
#define MCU_XTAL_H_AR_RELEASE_MAJOR_VERSION    4
#define MCU_XTAL_H_AR_RELEASE_MINOR_VERSION    3
#define MCU_XTAL_H_AR_RELEASE_REVISION_VERSION 1
#define MCU_XTAL_H_SW_MAJOR_VERSION    1
#define MCU_XTAL_H_SW_MINOR_VERSION    0
#define MCU_XTAL_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((MCU_XTAL_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (MCU_XTAL_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (MCU_XTAL_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Mcu_Xtal.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((MCU_XTAL_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (MCU_XTAL_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (MCU_XTAL_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Mcu_Xtal.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define XTAL_CTRL_STATE 0x01u
#define LPVD_POWER_STATE 0x01u

typedef enum {
    XTAL_DISABLE,
    XTAL_ENABLE,
} xtal_ctrl_e;

typedef enum {
    LPVD_POWER_ON,
    LPVD_POWER_DOWN,
} lpvd_ctrl_e;

/**
 * @brief   To get xtal status.
 * @details This function gate xtal status.
 */
uint8 Mcu_GetXtal32KStatus(void);

/**
 * @brief   To enable xtal.
 * @details This function enable xtal, .
 * @param[in] en  enable/disable xtal
 */
void Mcu_Xtal32KEnable(xtal_ctrl_e en);

/**
 * @brief   To get xtal status.
 * @details This function gate xtal status.
 */
uint8 Mcu_GetLpvdPowerStatus(void);

/**
 * @brief   To switch lpvd power.
 * @details This function switch lpvd power.
 * @param[in] pd  power on/down
 */
void Mcu_LpvdPowerSwitch(lpvd_ctrl_e pd);

#endif  /* __MCU_XTAL_H__ */
