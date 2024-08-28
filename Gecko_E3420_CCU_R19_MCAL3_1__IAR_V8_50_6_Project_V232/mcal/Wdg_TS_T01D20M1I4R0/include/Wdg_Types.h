/********************************************************************************************************
 * SEMIDRIVE Copyright Statement                                                                        *
 * Copyright (c) SEMIDRIVE. All rights reserved                                                         *
 *                                                                                                      *
 * This software and all rights therein are owned by SEMIDRIVE, and are                                 *
 * protected by copyright law and other relevant laws, regulations and                                  *
 * protection. Without SEMIDRIVE's prior written consent and/or related rights,                         *
 * please do not use this software or any potion thereof in any form or by any                          *
 * means. You may not reproduce, modify or distribute this software except in                           *
 * compliance with the License. Unless required by applicable law or agreed to                          *
 * in writing, software distributed under the License is distributed on                                 *
 * an 'AS IS' basis, WITHOUT WARRANTIES OF ANY KIND, either express or implied.                         *
 *                                                                                                      *
 *******************************************************************************************************/

/** *****************************************************************************************************
 *  \file     Wdg_Types.h                                                                               *
 *  \brief    This file contains interface header for WDG MCAL driver, ...                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef WDG_TYPES_H
#define WDG_TYPES_H
/**
 *
 * \defgroup MCAL_WDG_API WDG Driver
 *
 * The WDG Driver MCAL provides low level access to onbaord WDG peripheral
 * present on Device.Wdg's timeout behavior(RESET/INTERRUPT),timeout counter,
 * trigger condition mode(window/normal mode) and timeout externel signal
 * output support and so on.
 * The WDG Driver implements a standardized interface specified in the
 * AUTOSAR_SWS_WDGDriver document.For example Wdg_init,Wdg_SetMode,Wdg_GetVersion,
 * Wdg_SetTriggerCondition,and Wdg_SetTriggerRoutine interface,and support
 * instanceId 1~6 and 8.So each of the above interfaces have it own independent name.
 * The WDG Driver is part of the Communication Stack in the AUTOSAR Basic
 * Software (BSW),include EcuM,WdgM,WdgIf can call corresponding interface,reference
 * AUTOSAR_SWS_WDGDriver.pdf sequence discription.
 * The WDG Hardware Unit cntrolled by WDG Driver combines one or several WDG controllers,
 * which may be located on-chip or as external standalone devices of the same
 * type, with common or separate
 */

/** @{ */

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/

#include "WdgIf_Types.h"
#include "Std_Types.h"

#ifdef __cplusplus
extern "C" {
#endif
/**
 *
 * \addtogroup MCAL_WDG_TYPEDEF WDG Driver Typedef
 */
/** @{ */
/********************************************************************************************************
 *                                  Global Types definition                                             *
 *******************************************************************************************************/
/** \brief  Wdg module identify, which are currently support modules. */

/** \name Call back notification type
 *
 * Use for Wdg timeout event report to user.
 *  @{
 */
typedef void(*Wdg_NotificationType)(void);
/* @} */

/**
 *  \name  Watchdog timeour behavior
 *
 * Use for Wdg timeout behavior setting(Reset/Interrupt/Both).
 *  @{
 */
typedef enum
{
    WDG_RESET = 0,
    /**< use for Wdg timeout Reset behavior setting */
    WDG_INTERRUPT,
    /**< use for Wdg timeout Interrupt behavior setting */
    WDG_BOTH
    /**< use for Wdg timeout Reset and Interrupt behavior setting */
} Wdg_TimeoutBehaviorType;
/* @} */
/**
 *  \name  Watchdog trigger mode
 *
 *  Watchdog trigger mode support normal mode(no condition) which can trigger
 *  by setting timeout value and recount it.
 *  Watchdog trigger mode support window mode setting which can trigger
 *  within start time and time-out boundary.
 *  @{
 */
typedef enum
{
    NO_CONDITION_MODE        = 0,
    /**< Normal mode,can be triggered directly*/
    WINDOW_BASED_MODE        = 2U
                               /**< Only can be triggered in between low_limit and timeout.*/
} Wdg_TriggerConditionType;
/* @} */

/** \name WDG Config mode set
 *
 *  The WDG Config mode set struct save the wdg work independent parameters for
 *  WDGIF_MODE_OFF/WDGIF_MODE_FAST/WDGIF_MODE_SLOW.
 *  @{
*/
/** Traceability: SWSR_WDG_011 */
typedef struct Wdg_ModeConfigType_s
{
    uint32                      clockFrequency;
    /**< main clock frequence and default is 24000000 */
    uint32                      timeoutPeriod;
    /**< timeout Period (in ms)*/
    uint32                      refreshTime;
    /**< use for Wdg window mode trigger time only between refreshTime(in ms) ~ timeoutPeriod(in ms) */
    Wdg_TimeoutBehaviorType     timeoutBehavior;
    /**< use for Wdg timeout behavior (Reset/Interrupt/Both) */
    Wdg_TriggerConditionType    triggerCondition;
    /**< use for Wdg trigger mode(normal mode or window mode) setting  */
    boolean                     externalSignalEnable;
    /**< use for Wdg timeout wether support external signal notify*/
} Wdg_ModeConfigType;
/* @} */

/**
 *  \name  Watchdog driver state
 *
 *  The WDG state is used internally to check that Watchdog trigger happens
 *  only in IDLE state.Also additional check to check Wdg_Init is invoked
 *  before any other Wdg API is called.
 *  @{
 */
/** Traceability: SWSR_WDG_009 SWSR_WDG_010 SWSR_WDG_018 SWSR_WDG_027 SWSR_WDG_028 */
typedef enum
{
    WDG_UNINIT = 0,
    /**< Watchdog driver is uninitialized. State on power on before
     *   invoking Wdg_Init() */
    WDG_IDLE,
    /**< Watchdog driver is in idle state. Default state when WDG
     *   timer regs are not being programmed */
    WDG_BUSY
    /**< Watchdog driver is reprogramming the WD to trigger the
     *   watchdog */
} Wdg_ModuleStatusType;
/* @} */

/** \name WDG config structure number
 *  @{
*/
/** Traceability: SWSR_WDG_011 */
typedef struct Wdg_ConfigType_s
{
    uint16 initTimeout;
    /**< Init Timeout(in ms) */
    uint16 maxTimeout;
    /**< Max Timeout(in ms) */
    WdgIf_ModeType defaultMode;
    /**< Default mode */
    uint8  currentInstance;
    /**< Current Wdg driver instance */
    Wdg_NotificationType pfNotification;
    /**< Timeout call back notification */
    const Wdg_ModeConfigType *modeSettings;
    /**Wdg mode settings*/
} Wdg_ConfigType;
/* @} */

/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
/*none*/

/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/*none*/

/*none*/
#ifdef __cplusplus
}
#endif
/** @} */
/** @} */
/** @} */
#endif /* WDG_TYPES_H */
/* End of file */


