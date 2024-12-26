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

/**
 * @file  Wdg_Hw_E3.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Wdg
 */

#ifndef WDG_HW_E3_H
#define WDG_HW_E3_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Wdg_Types.h"
#include "Wdg_Cfg.h"
#include "Wdg_140_Instance1_Cfg.h"
#include "Wdg_140_Instance2_Cfg.h"
#include "Wdg_140_Instance3_Cfg.h"
#include "Wdg_140_Instance4_Cfg.h"
#include "Wdg_140_Instance5_Cfg.h"
#include "Wdg_140_Instance6_Cfg.h"
#include "Wdg_140_Instance8_Cfg.h"
/* Version and Check Begin */
/* Version Info Begin */
#define WDG_IP_H_VENDOR_ID    0x8C
#define WDG_IP_H_AR_RELEASE_MAJOR_VERSION    4
#define WDG_IP_H_AR_RELEASE_MINOR_VERSION    3
#define WDG_IP_H_AR_RELEASE_REVISION_VERSION 1
#define WDG_IP_H_SW_MAJOR_VERSION    1
#define WDG_IP_H_SW_MINOR_VERSION    0
#define WDG_IP_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */

/* Version Check End */
/* Version and Check End */

/**
 * @brief Wdg Ip initial
 * @param[in]  pModeSetting Pointer to mode setting.
 * @param[in]  uInitTimeout Initial Timeout (in ms).
 * @param[in]  Wdg_InstanceID Watchdog driver instance id.
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_Ip_Init
(
    P2CONST(Wdg_Ip_ModeConfigType, AUTOMATIC, WDG_APPL_CONST) pModeSetting,
    VAR(uint16, AUTOMATIC) uInitTimeout,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
);

/**
 * @brief Wdg Ip set mode
 * @param[in]  pModeSetting Pointer to mode setting.
 * @param[in]  Wdg_InstanceID Watchdog driver instance id.
 * @return   none
 * @implements
*/
FUNC(void, WDG_CODE) Wdg_Ip_SetMode
(
    P2CONST(Wdg_Ip_ModeConfigType, AUTOMATIC, WDG_APPL_CONST) pModeSetting,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
);

/**
 * @brief Wdg Ip set trigger condition
 * @param[in]  Timeout Timeout timeout value (in ms)
 * @param[in]  Wdg_InstanceID Watchdog driver instance id.
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_Ip_SetTriggerCondition
(
    VAR(uint16, AUTOMATIC) Timeout,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
);

/**
 * @brief Wdg Ip clear interrupt flag. Be called by Wdg_CommonInterrupt.
 * @param[in]  Wdg_InstanceID Watchdog driver instance id.
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_Ip_ClearInterruptFlag
(
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
);

/**
 * @brief TriggerRoutine, can be used to feed wdg.
 * @param[in]  Wdg_InstanceID Driver instance ID
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_Ip_TriggerRoutine
(
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
);

#ifdef __cplusplus
}
#endif

#endif /*WDG_HW_E3_H*/
