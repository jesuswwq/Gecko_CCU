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
 * @file  Wdg.h
 * @brief Semidrive. AUTOSAR 4.3.1 MCAL Wdg
 */

#ifndef WDG_H
#define WDG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Wdg_Hw_E3.h"

/* Version and Check Begin */
/* Version Info Begin */
#define WDG_H_VENDOR_ID    0x8C
#define WDG_H_AR_RELEASE_MAJOR_VERSION    4
#define WDG_H_AR_RELEASE_MINOR_VERSION    3
#define WDG_H_AR_RELEASE_REVISION_VERSION 1
#define WDG_H_SW_MAJOR_VERSION    1
#define WDG_H_SW_MINOR_VERSION    0
#define WDG_H_SW_PATCH_VERSION    0
/* Version Info End */

/* Version Check Begin */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDG_H_AR_RELEASE_MAJOR_VERSION != STD_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDG_H_AR_RELEASE_MINOR_VERSION != STD_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (WDG_H_AR_RELEASE_REVISION_VERSION != STD_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Wdg.h and Std_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDG_H_SW_MAJOR_VERSION != STD_TYPES_H_SW_MAJOR_VERSION)\
    || (WDG_H_SW_MINOR_VERSION != STD_TYPES_H_SW_MINOR_VERSION)\
    || (WDG_H_SW_PATCH_VERSION != STD_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Wdg.h and Std_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDG_H_AR_RELEASE_MAJOR_VERSION != WDG_IP_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDG_H_AR_RELEASE_MINOR_VERSION != WDG_IP_H_AR_RELEASE_MINOR_VERSION)\
    || (WDG_H_AR_RELEASE_REVISION_VERSION != WDG_IP_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Wdg.h and Wdg_Hw_E3.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDG_H_SW_MAJOR_VERSION != WDG_IP_H_SW_MAJOR_VERSION)\
    || (WDG_H_SW_MINOR_VERSION != WDG_IP_H_SW_MINOR_VERSION)\
    || (WDG_H_SW_PATCH_VERSION != WDG_IP_H_SW_PATCH_VERSION))
#error "Opps, Wdg.h and Wdg_Hw_E3.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
#if !defined(DISABLE_MCAL_ASR_VER_CHECK)
#if ((WDG_H_AR_RELEASE_MAJOR_VERSION != WDGIF_TYPES_H_AR_RELEASE_MAJOR_VERSION)\
    || (WDG_H_AR_RELEASE_MINOR_VERSION != WDGIF_TYPES_H_AR_RELEASE_MINOR_VERSION)\
    || (WDG_H_AR_RELEASE_REVISION_VERSION != WDGIF_TYPES_H_AR_RELEASE_REVISION_VERSION))
#error "Opps, Wdg.h and WdgIf_Types.h AutoSAR version not match!"
#endif
#endif  /* !DISABLE_MCAL_ASR_VER_CHECK */
#if !defined(DISABLE_MCAL_SW_VER_CHECK)
#if ((WDG_H_SW_MAJOR_VERSION != WDGIF_TYPES_H_SW_MAJOR_VERSION)\
    || (WDG_H_SW_MINOR_VERSION != WDGIF_TYPES_H_SW_MINOR_VERSION)\
    || (WDG_H_SW_PATCH_VERSION != WDGIF_TYPES_H_SW_PATCH_VERSION))
#error "Opps, Wdg.h and WdgIf_Types.h Software version not match!"
#endif
#endif  /* !DISABLE_MCAL_SW_VER_CHECK */
/* Version Check End */
/* Version and Check End */

#define WDG_E_DRIVER_STATE     0x10U
#define WDG_E_PARAM_MODE       0x11U
#define WDG_E_PARAM_CONFIG     0x12U
#define WDG_E_PARAM_TIMEOUT    0x13U
#define WDG_E_PARAM_POINTER    0x14U
#define WDG_E_INIT_FAILED      0x15U
#define WDG_E_MODE_FAILED      0x20U
#define WDG_E_DISABLE_REJECTED 0x21U

#define WDG_MODULE_ID          102U

#define WDG_INIT_SERVICE_ID                 0x00u
#define WDG_SETMODE_SERVICE_ID              0x10u
#define WDG_SETTRIGGERCONDITION_SERVICE_ID  0x03u
#define WDG_GETVERSIONINFO_SERVICE_ID       0x04u

/**
 * @brief Wdg initial
 * @param[in]  ConfigPtr Pointer to a selected configuration structure
 * @param[in]  Wdg_InstanceID Driver instance ID
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_Init
(
    P2CONST(Wdg_ConfigType, AUTOMATIC, WDG_APPL_CONST) ConfigPtr,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
);

/**
 * @brief Change wdg running mode
 * @param[in]  Mode WDGIF_OFF_MODE/WDGIF_SLOW_MODE/WDGIF_FAST_MODE
 * @param[in]  Wdg_InstanceID Driver instance ID
 * @return   none
*/
FUNC(Std_ReturnType, WDG_CODE) Wdg_SetMode
(
    VAR(WdgIf_ModeType, AUTOMATIC) Mode,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
);

/**
 * @brief Set TriggerCondition (Alter timeout value)
 * @param[in]  Timeout timeout value (in ms)
 * @param[in]  Wdg_InstanceID Driver instance ID
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_SetTriggerCondition
(
    VAR(uint16, AUTOMATIC) Timeout,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
);

/**
 * @brief Get version information of module
 * @param[in]  ConfigPtr Pointer to a selected configuration structure
 * @param[in]  Wdg_InstanceID Driver instance ID
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_GetVersionInfo
(
    P2VAR(Std_VersionInfoType, AUTOMATIC, WDG_APPL_DATA) VerInfoPtr,
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
);

/**
 * @brief Interrupt handler. Be called by ISR(Wdg_Isr_Instance1) in Wdg_Irq.c
 * @param[in]  Wdg_InstanceID Driver instance ID
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_CommonInterrupt
(
    CONST(uint8, WDG_CONST) Wdg_InstanceID
);

/**
 * @brief TriggerRoutine, can be used to feed wdg.
 * @param[in]  Wdg_InstanceID Driver instance ID
 * @return   none
*/
FUNC(void, WDG_CODE) Wdg_TriggerRoutine
(
    VAR(uint8, AUTOMATIC) Wdg_InstanceID
);

#ifdef __cplusplus
}
#endif

#endif /*WDG_H*/
