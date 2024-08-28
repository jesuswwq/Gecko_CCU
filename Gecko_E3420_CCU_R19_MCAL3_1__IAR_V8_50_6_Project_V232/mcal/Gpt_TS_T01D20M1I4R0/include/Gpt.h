/** *****************************************************************************************************
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
 *  \file     Gpt.h                                                                                     *
 *  \brief    This file contains interface header for GPT MCAL driver                                   *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/24     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef GPT_H
#define GPT_H

/**
 *
 * \defgroup MCAL_GPT GPT Driver API
 *
 * The GPT Driver MCAL provides low level access to GPT peripheral
 *
 * \sa MCAL_GPT_CFG
 * \sa MCAL_GPT_API
 * \sa MCAL_GPT_MACRO
 * \{
 */


#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Mcal.h"
#include "Gpt_Ip.h"
/**
 * Traceability       : SWSR_GPT_001
 */
#include "Gpt_Cfg.h"

/**
 *  \defgroup MCAL_GPT_CFG GPT Configuration.
 *
 * This files defines GPT MCAL configuration structures
 *  \{
 */

/** \} */

/**
 *  \defgroup MCAL_GPT_API GPT Api.
 *
 * This files defines GPT MCAL api
 *  \{
 */

/** \} */

/**
 *  \defgroup MCAL_GPT_MACRO GPT macro.
 *
 * This files defines GPT MCAL macro
 *  \{
 */

/** \} */

/**
 *  \addtogroup MCAL_GPT_MACRO GPT macro.
 *  \{
 */

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/**
 *  \name GPT Driver ID Info
 *  \{
 */
/** \brief Semidrive Vendor ID */
#define GPT_VENDOR_ID    0x8C
/** \brief GPT Driver Module ID */
#define GPT_MODULE_ID   (100u)
/** \brief GPT Driver Instance ID */
#define GPT_INSTANCE_ID   ((uint8)0U)
/** \} */

/**
 *  \name GPT Service Ids
 *
 *  The Service Id is one of the argument to Det_ReportError function and
 *  is used to identify the source of the error
 *  \{
 */
/** \brief Gpt_GetVersionInfo() API Service ID */
#define GPT_GET_VERSION_INFO_ID ((uint8)0x00U)
/** \brief Gpt_Init() API Service ID */
#define GPT_INIT_ID     ((uint8)0x01U)
/** \brief Gpt_DeInit() API Service ID */
#define GPT_DEINIT_ID   ((uint8)0x02U)
/** \brief Gpt_GetTimeElapsed() API Service ID */
#define GPT_GET_TIME_ELAPSED_ID ((uint8)0x03U)
/** \brief Gpt_GetTimeRemaining() API Service ID */
#define GPT_GET_TIME_REMAINING_ID ((uint8)0x04U)
/** \brief Gpt_StartTimer() API Service ID */
#define GPT_START_TIMER_ID ((uint8)0x05U)
/** \brief Gpt_StopTimer() API Service ID */
#define GPT_STOP_TIMER_ID ((uint8)0x06U)
/** \brief Gpt_EnableNotification() API Service ID */
#define GPT_ENABLE_NOTIFICATION_ID ((uint8)0x07U)
/** \brief Gpt_DisableNotification() API Service ID */
#define GPT_DISABLE_NOTIFICATION_ID ((uint8)0x08U)
/** \brief Gpt_GetPredefTimerValue() API Service ID */
#define GPT_GET_PREDEF_TIME_ID ((uint8)0x0dU)
/** \} */


/**
 *  \name GPT Error Codes
 *
 *  Error codes returned by GPT functions
 *  \{
 */
/** \brief API service used without module initialization */
#define GPT_E_UNINIT    ((uint8)0x0AU)
/**
 *  \brief API service called during ongoing process (Timer is already
 *  running)
 */
#define GPT_E_BUSY  ((uint8)0x0BU)
/** \brief API Gpt_Init is called but the module is already initialized. */
#define GPT_E_ALREADY_INITIALIZED   ((uint8)0x0DU)
/** \brief API called with invalid channel. */
#define GPT_E_PARAM_CHANNEL ((uint8)0x14U)
/** \brief API service called with invalid start timer parameter */
#define GPT_E_PARAM_VALUE   ((uint8)0x15U)
/** \brief API service called with invalid(Null_Ptr) data buffer pointer. */
#define GPT_E_PARAM_POINTER ((uint8)0x16U)
/** \brief API service called with invalid Predef Timer. Not supported in this
    implementation*/
#define GPT_E_PARAM_PREDEF_TIMER    ((uint8)0x17U)
/** \brief API Gpt_Init is called but the module is already initialized. */
#define GPT_E_INIT_FAILED   ((uint8)0x0EU)
/** \} */

/** \} */

/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
/**
 *  \addtogroup MCAL_GPT_API GPT Api.
 *  \{
 */
/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#if (STD_ON == GPT_VERSION_INFO_API)
/** *****************************************************************************************************
 * \brief This service returns the version information of this module.
 *
 * \verbatim
 * Syntax             : void Gpt_GetVersionInfo(Std_VersionInfoType*
 *                                                          VersionInfoPtr)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : VersionInfoPtr - Pointer to where to store the version
 *                        information of this module
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Returns the version information of this module
 * \endverbatim
 * Traceability       : SWSR_GPT_015 SWSR_GPT_016 SW_SM006
 *******************************************************************************************************/
void Gpt_GetVersionInfo(Std_VersionInfoType *VerInfoPtr);
#endif /** #if (STD_ON == GPT_VERSION_INFO_API) */

/** *****************************************************************************************************
 * \brief This service initializes all the configured Gpt channels. This will
 *         set the state of the each channel to"initialized", also set the Gpt
 *         driver state to "Normal".
 *
 * \verbatim
 * Syntax             : void Gpt_Init(const Gpt_ConfigType* CfgPtr)
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non Reentrant
 *
 * Parameters (in)    : Gpt_ConfigType* CfgPtr - configuration structure
 *                        for initializing the module.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Initializes the GPT driver.
 * \endverbatim
 * Traceability       : SWSR_GPT_007 SWSR_GPT_008 SWSR_GPT_010 SWSR_GPT_017 SWSR_GPT_018
 *                      SWSR_GPT_019 SWSR_GPT_020 SWSR_GPT_021 SWSR_GPT_022 SWSR_GPT_023
 *                      SWSR_GPT_024 SWSR_GPT_087 SW_SM006
 *******************************************************************************************************/
void Gpt_Init(const Gpt_ConfigType *ConfigPtr);

#if (STD_ON == GPT_DEINIT_API)
/** *****************************************************************************************************
 * \brief This service deinitializes the RTI used by Gpt driver to the power on
 *         reset state.
 *         The Gpt driver state is changed to "Uninitialized" state".
 *         All the channel registers are cleared to stop the timer channels.
 *         API will disable all interrupt notifications, wakeup interrupts.
 *
 * \verbatim
 * Syntax             : void Gpt_DeInit(void)
 *
 * Service ID[hex]    : 0x02
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Deinitializes the GPT driver.
 * \endverbatim
 * Traceability       : SWSR_GPT_025 SWSR_GPT_026 SWSR_GPT_027 SWSR_GPT_029
 *                      SWSR_GPT_030 SWSR_GPT_031 SWSR_GPT_087 SW_SM001
 *******************************************************************************************************/
void Gpt_DeInit(void);
#endif /** #if (STD_ON == GPT_DEINIT_API) */

#if (STD_ON == GPT_TIME_ELAPSED_API)
/** *****************************************************************************************************
 * \brief Gpt_GetTimeElapsed will return the time elapsed for channel which is
 *         referenced. The user can configure the channel in two modes, One-shot
 *         and Continuous mode. In one shot mode, if the timer is in stopped
 *         state, the function will return time value at the moment of stopping.
 *         If the timer is expired, the function will return the target time
 *         configured for the channel. In Continuous Mode - The elapsed time
 *         value will be the value relative to last occurrence.
 *
 * \verbatim
 * Syntax             : Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType
 *                                                                      Channel)
 *
 * Service ID[hex]    : 0x03
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - ChannelId of the Gpt channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Gpt_ValueType Elapsed timer value (in number of ticks)
 *
 * Description        : Returns the time already elapsed.
 * \endverbatim
 * Traceability       : SWSR_GPT_032 SWSR_GPT_033 SWSR_GPT_035 SWSR_GPT_037
 *                      SWSR_GPT_038 SWSR_GPT_087 SW_SM001 SW_SM006
 *******************************************************************************************************/
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel);
#endif /** #if (STD_ON == GPT_TIME_ELAPSED_API) */

#if (STD_ON == GPT_TIME_REMAINING_API)
/** *****************************************************************************************************
 * \brief Gpt_GetTimeRemaining will return the timer value remaining until the
 *         target time will be reached next time. The remaining time is target
 *         time minus time already elapsed. In one shot mode, if the timer is in
 *         stopped state, the function will return remaining time value at the
 *         moment of stopping. If the timer is expired, the function will
 *         return 0.
 *
 * \verbatim
 * Syntax             : Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType
 *                                                                    Channel)
 *
 * Service ID[hex]    : 0x04
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - ChannelId of the Gpt channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Gpt_ValueType Remaining timer value (in number o
 *                        ticks)
 *
 * Description        : Returns the time remaining until the target time is
 *                      reached.
 * \endverbatim
 * Traceability       : SWSR_GPT_039 SWSR_GPT_040 SWSR_GPT_041 SWSR_GPT_042 SWSR_GPT_043
 *                      SWSR_GPT_045 SWSR_GPT_087 SW_SM001 SW_SM006 SWSR_GPT_034
 *******************************************************************************************************/
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel);
#endif /** #if (STD_ON == GPT_TIME_REMAINING_API) */

/** *****************************************************************************************************
 * \brief Gpt_StartTimer will start the selected timer channel with defined
 *         target time. If the timer channel is enabled for interrupt
 *         notification, then interrupt notification will be triggered after
 *         expiration of the selected timer channel. In one shot mode, if the
 *         timer is expired then the channel will be stopped in interrupt
 *         subroutine. The selected channel will be moved to "Running" state
 *         after calling this function.
 *
 * \verbatim
 * Syntax             : void Gpt_StartTimer(Gpt_ChannelType Channel,
 *                                            Gpt_ValueType Value)
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - ChannelId of the Gpt channel.
 *                      value - Target time in number of ticks.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Starts a timer channel.
 * \endverbatim
 * Traceability       : SWSR_GPT_004 SWSR_GPT_005 SWSR_GPT_047 SWSR_GPT_048 SWSR_GPT_049 SWSR_GPT_050
 *                      SWSR_GPT_051 SWSR_GPT_052 SWSR_GPT_053 SWSR_GPT_055 SWSR_GPT_087 SW_SM001
 *                      SW_SM006
 *******************************************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value);

/** *****************************************************************************************************
 * \brief Gpt_StopTimer will stop the selected timer channel.This will clear
 *         all the registers corresponding to the selected channel. The state of
 *         the timer channel will be changed to "Stopped".If the channel is in
 *         state "Initialized","Expired","Stopped" before calling this function,
 *         the function will be left without any action.
 *
 * \verbatim
 * Syntax             : void Gpt_StopTimer( Gpt_ChannelType Channel )
 *
 * Service ID[hex]    : 0x06
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant (but not for the same timer channel)
 *
 * Parameters (in)    : Channel: Numeric identifier of the GPT channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Stops a timer channel.
 * \endverbatim
 * Traceability       : SWSR_GPT_056 SWSR_GPT_057 SWSR_GPT_058 SWSR_GPT_059 SWSR_GPT_060
 *                      SWSR_GPT_061 SWSR_GPT_062 SWSR_GPT_087 SW_SM001 SW_SM006
 *******************************************************************************************************/
void Gpt_StopTimer(Gpt_ChannelType Channel);

#if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API)
/** *****************************************************************************************************
 * \brief Gpt_EnableNotification will enable the interrupt notification for the
 *         selected channel. The SETINT bit in RTI Set interrupt register will
 *         be Set to enable the Compare interrupt. The interrupt is triggered
 *         when Free running counter value matches with compare register value.
 *
 * \verbatim
 * Syntax             : void Gpt_EnableNotification( Gpt_ChannelType Channel)
 *
 * Service ID[hex]    : 0x07
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant (but not for the same timer channel)
 *
 * Parameters (in)    : Channel: Numeric identifier of the GPT channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Enables the interrupt notification for a channel
 *                        relevant in normal mode).
 * \endverbatim
 * Traceability       : SWSR_GPT_006 SWSR_GPT_063 SWSR_GPT_064 SWSR_GPT_065 SWSR_GPT_068
 *                      SWSR_GPT_087 SW_SM001 SW_SM006 SWSR_GPT_067
 *******************************************************************************************************/
void Gpt_EnableNotification(Gpt_ChannelType Channel);

/** *****************************************************************************************************
 * \brief Gpt_DisableNotification will disable the compare interrupt
 *    notification for the selected channel. The SETINT bit in RTI Set interrupt
 *    register will be cleared to disable the Compare interrupt. The
 *    interrupt is triggered when Free running counter value matches with
 *    compare register value.
 *
 * \verbatim
 * Syntax             : void Gpt_DisableNotification( Gpt_ChannelType Channel)
 *
 * Service ID[hex]    : 0x08
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant (but not for the same timer channel)
 *
 * Parameters (in)    : Channel: Numeric identifier of the GPT channel.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Disables the interrupt notification for a channel
 *                        relevant in normal mode).
 * \endverbatim
 * Traceability       : SWSR_GPT_006 SWSR_GPT_070 SWSR_GPT_071 SWSR_GPT_073 SWSR_GPT_074
 *                      SWSR_GPT_087 SW_SM001 SW_SM006 SWSR_GPT_067
 *******************************************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType Channel);
#endif /** #if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API) */

#if(STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API)
/** *****************************************************************************************************
 * \brief Provides the current value of the given predefined free-running timer
 *
 * \verbatim
 * Syntax             : Std_ReturnType Gpt_GetPredefTimerValue(
 *                                Gpt_PredefTimerType PredefTimer,
 *                                uint32* TimeValuePtr);
 *
 * Service ID[hex]    : 0x0d
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : PredefTimer: Gpt_PredefTimerType ( GPT_PREDEF_TIMER_1US_16BIT,
 *                                               GPT_PREDEF_TIMER_1US_24BIT,
 *                                               GPT_PREDEF_TIMER_1US_32BIT)
 *
 * Parameters (inout) : TimeValuePtr: Pointer to time value destination data in RAM
 *
 * Parameters (out)   : None
 *
 * Return value       : returnValue  - E_OK: no error has been detected.
 *                                   - E_NOT_OK: aborted due to errors.
 *
 * Description        : Delivers the current value of the desired GPT Predef Timer.
 *
 * \endverbatim
 * Traceability       : SWSR_GPT_011 SWSR_GPT_075 SWSR_GPT_076 SWSR_GPT_077 SWSR_GPT_078
 *                      SWSR_GPT_079 SWSR_GPT_080 SWSR_GPT_081 SWSR_GPT_082 SWSR_GPT_083
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr);
#endif /** #if(STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API) */

/** *****************************************************************************************************
 *
 * Syntax             : void Gpt_Irq(
 *                          Gpt_HwModule hwModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : hwModule - (GPT_INDEX_BTM1,
 *                                  GPT_INDEX_BTM2,
 *                                  GPT_INDEX_BTM3,
 *                                  GPT_INDEX_BTM4,
 *                                  GPT_INDEX_BTM5,
 *                                  GPT_INDEX_BTM6)
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : GPT interrupt processing interface, switching channel status.
 *
 * Traceability       : SWSR_GPT_084 SWSR_GPT_086 SW_SM003 SW_SM004
 *******************************************************************************************************/
void Gpt_Irq(Gpt_HwModule hwModule);
/** \} */
/** \} */

#ifdef __cplusplus
}
#endif

#endif /* GPT_H */

/* End of file */
