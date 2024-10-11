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

/**
 * \file  Gpt.c
 * \brief Semidrive. AUTOSAR 4.3.1 MCAL Gpt
 */

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Gpt.h"
#include "Gpt_Register.h"
#if (STD_ON == GPT_SAFETY_ENABLE)
#include "FuSaMcalReportError.h"
#endif /** #if (STD_ON == GPT_SAFETY_ENABLE) */
/**
 * Traceability       : SWSR_GPT_003
 */
#include "Det.h"

/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
#if (STD_ON == GPT_CORE0_ENABLE)
#define GPT_CORE0_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/** Save the configuration and channel status information of core0. */
static Gpt_Ip_Handler Gpt_HandlerCore0 LOCATE_ALIGNED(GPT_CACHE_LINE);
#define GPT_CORE0_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
#endif /** #if (STD_ON == GPT_CORE0_ENABLE) */

#if (STD_ON == GPT_CORE1_ENABLE)
#define GPT_CORE1_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/** Save the configuration and channel status information of core1. */
static Gpt_Ip_Handler Gpt_HandlerCore1 LOCATE_ALIGNED(GPT_CACHE_LINE);
#define GPT_CORE1_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
#endif /** #if (STD_ON == GPT_CORE1_ENABLE) */

#if (STD_ON == GPT_CORE2_ENABLE)
#define GPT_CORE2_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/** Save the configuration and channel status information of core2. */
static Gpt_Ip_Handler Gpt_HandlerCore2 LOCATE_ALIGNED(GPT_CACHE_LINE);
#define GPT_CORE2_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
#endif /** #if (STD_ON == GPT_CORE2_ENABLE) */

#if (STD_ON == GPT_CORE3_ENABLE)
#define GPT_CORE3_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/** Save the configuration and channel status information of core3. */
static Gpt_Ip_Handler Gpt_HandlerCore3 LOCATE_ALIGNED(GPT_CACHE_LINE);
#define GPT_CORE3_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
#endif /** #if (STD_ON == GPT_CORE3_ENABLE) */

#if (STD_ON == GPT_CORE4_ENABLE)
#define GPT_CORE4_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
/** Save the configuration and channel status information of core4. */
static Gpt_Ip_Handler Gpt_HandlerCore4 LOCATE_ALIGNED(GPT_CACHE_LINE);
#define GPT_CORE4_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Gpt_MemMap.h"
#endif /** #if (STD_ON == GPT_CORE4_ENABLE) */


#define GPT_START_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

/********************************************************************************************************
 *                                  Private Constant Definitions                                        *
 *******************************************************************************************************/
/**  GPT handler */
Gpt_Ip_Handler *const Gpt_Handler[5] =
{
#if (STD_ON == GPT_CORE0_ENABLE)
    &Gpt_HandlerCore0,
#else
    NULL_PTR,
#endif /** #if (STD_ON == GPT_CORE0_ENABLE) */
#if (STD_ON == GPT_CORE1_ENABLE)
    &Gpt_HandlerCore1,
#else
    NULL_PTR,
#endif /** #if (STD_ON == GPT_CORE1_ENABLE) */
#if (STD_ON == GPT_CORE2_ENABLE)
    &Gpt_HandlerCore2,
#else
    NULL_PTR,
#endif /** #if (STD_ON == GPT_CORE2_ENABLE) */
#if (STD_ON == GPT_CORE3_ENABLE)
    &Gpt_HandlerCore3,
#else
    NULL_PTR,
#endif /** #if (STD_ON == GPT_CORE3_ENABLE) */
#if (STD_ON == GPT_CORE4_ENABLE)
    &Gpt_HandlerCore4,
#else
    NULL_PTR
#endif /** #if (STD_ON == GPT_CORE4_ENABLE) */
};

#define GPT_STOP_SEC_CONST_UNSPECIFIED
#include "Gpt_MemMap.h"

/********************************************************************************************************
 *                                 Imported Compiler Switch Checks                                      *
 *******************************************************************************************************/
#ifndef GPT_SW_MAJOR_VERSION
#error "GPT_SW_MAJOR_VERSION is not defined."
#endif

#ifndef GPT_SW_MINOR_VERSION
#error "GPT_SW_MINOR_VERSION is not defined."
#endif

#ifndef GPT_SW_PATCH_VERSION
#error "GPT_SW_PATCH_VERSION is not defined."
#endif

#ifndef GPT_AR_RELEASE_MAJOR_VERSION
#error "GPT_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

#ifndef GPT_AR_RELEASE_MINOR_VERSION
#error "GPT_AR_RELEASE_MINOR_VERSION is not defined."
#endif

#ifndef GPT_AR_RELEASE_REVISION_VERSION
#error "GPT_AR_RELEASE_REVISION_VERSION is not defined."
#endif

#if(GPT_AR_RELEASE_MAJOR_VERSION != 4U)
#error "GPT_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#if(GPT_AR_RELEASE_MINOR_VERSION != 3U)
#error "GPT_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#define GPT_START_SEC_CODE
#include "Gpt_MemMap.h"

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
void Gpt_GetVersionInfo(Std_VersionInfoType *VerInfoPtr)
{
    if (NULL_PTR == VerInfoPtr)
    {
#if (STD_ON == GPT_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_VERSION_INFO_ID, GPT_E_PARAM_POINTER);
#endif /** #if (STD_ON == GPT_DEV_ERROR_DETECT) */
#if (STD_ON == GPT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_VERSION_INFO_ID,
                                   GPT_E_PARAM_POINTER);
#endif /** #if (STD_ON == GPT_SAFETY_ENABLE) */
    }
    else
    {
        VerInfoPtr->vendorID = GPT_VENDOR_ID;
        VerInfoPtr->moduleID = GPT_MODULE_ID;
        VerInfoPtr->sw_major_version = GPT_SW_MAJOR_VERSION;
        VerInfoPtr->sw_minor_version = GPT_SW_MINOR_VERSION;
        VerInfoPtr->sw_patch_version = GPT_SW_PATCH_VERSION;
    }
}
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
void Gpt_Init(const Gpt_ConfigType *ConfigPtr)
{
    Gpt_ChannelType channel;
    uint32 coreId = Gpt_GetCoreId();
    Std_ReturnType errorId;

    /* #10 check config */
    errorId = Gpt_ValidateInitCfg(ConfigPtr);

    if (E_OK == errorId)
    {
        /* #20 save config */
#if (STD_ON == GPT_PRECOMPILE_SUPPORT)
        Gpt_Handler[coreId]->config = &Gpt_CfgVariantPredefined;
#else
        Gpt_Handler[coreId]->config = ConfigPtr;
#endif /** #if (STD_ON == GPT_PRECOMPILE_SUPPORT) */

#if(STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API)

        /* #30 start Predef timer */
        if (0U == coreId)
        {
            Gpt_Ip_StartPreDefTimer(Gpt_Handler[coreId]->config->predefChannelConfig);
        } /* else not needed */

#endif /** #if(STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API) */

        /* #40 initializes every timer channel that configured */
        for (channel = 0; channel < Gpt_Handler[coreId]->config->channelCount; channel++)
        {
            if (coreId == (*(Gpt_Handler[coreId]->config->channelConfig))[channel].gptCoreId)
            {
                Gpt_Handler[coreId]->channelInfo[channel].notificationEnabled =
                    (*(Gpt_Handler[coreId]->config->channelConfig))[channel].hwChannelConfig.notificationEnabled;
                /* #50 Change channel state and initialize time */
                Gpt_Handler[coreId]->targetTime[channel] = (Gpt_ValueType)0;
                Gpt_Handler[coreId]->elapsedTime[channel] = (Gpt_ValueType)0;
                Gpt_Handler[coreId]->channelInfo[channel].channelStatus = GPT_STATUS_INITIALIZED;
                Gpt_Ip_Init(&((*
                               (Gpt_Handler[coreId]->config->channelConfig))[channel].hwChannelConfig));
            } /* else not needed */
        }

        /* #60 Change driver state */
        Gpt_Handler[coreId]->driverMode = GPT_MODE_INITED;
    } /* else not needed */

#if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE))

    if (E_OK != errorId)
    {
#if (STD_ON == GPT_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_ID, errorId);
#endif /** #if (STD_ON == GPT_DEV_ERROR_DETECT) */
#if (STD_ON == GPT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_INIT_ID, errorId);
#endif /** #if (STD_ON == GPT_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE)) */
}

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
void Gpt_DeInit(void)
{
    Gpt_ChannelType channel;
    uint32 coreId = Gpt_GetCoreId();
    Std_ReturnType errorId;

    /* #10 Change driver/channel state */
    errorId = Gpt_CheckModuleStaDeInit();

    if (E_OK == errorId)
    {
        /* #20 disable all core channel */
        for (channel = 0; channel < Gpt_Handler[coreId]->config->channelCount; channel++)
        {
            if (coreId == (*(Gpt_Handler[coreId]->config->channelConfig))[channel].gptCoreId)
            {
                Gpt_Ip_DeInit(&((*
                                 (Gpt_Handler[coreId]->config->channelConfig))[channel].hwChannelConfig));
                /* #30 Change channel status and reset time */
                Gpt_Handler[coreId]->channelInfo[channel].channelStatus = GPT_STATUS_UNKNOW;
                Gpt_Handler[coreId]->channelInfo[channel].channelMode = GPT_CH_MODE_CONTINUOUS;
                Gpt_Handler[coreId]->elapsedTime[channel] = 0;
                Gpt_Handler[coreId]->targetTime[channel] = 0;
            } /* else not needed */
        }

#if(STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API)

        /* #40 disable predef timer */
        if (0U == coreId)
        {
            Gpt_Ip_PredefDeInit(Gpt_Handler[coreId]->config->predefChannelConfig);
        } /* else not needed */

#endif /** #if(STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API) */
        /* #50 change driver status. */
        Gpt_Handler[coreId]->driverMode = GPT_MODE_UNINIT;
    } /* else not needed */

#if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE))

    if (E_OK != errorId)
    {
#if (STD_ON == GPT_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DEINIT_ID, errorId);
#endif /** #if (STD_ON == GPT_DEV_ERROR_DETECT) */
#if (STD_ON == GPT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DEINIT_ID, errorId);
#endif /** #if (STD_ON == GPT_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE)) */
}
#endif /** #if (STD_ON == GPT_DEINIT_API) */

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
void Gpt_StartTimer(Gpt_ChannelType Channel, Gpt_ValueType Value)
{
    uint32 coreId = Gpt_GetCoreId();
    Std_ReturnType errorId;

    /* #10 check parameter. */
    errorId = Gpt_ValidateParamStartTimer(Channel, Value);

    if (E_OK == errorId)
    {
        /* #20 check channel status. */
        errorId = Gpt_CheckStaStartTimer(Channel);

        /* #30 start timer and modify channel status. */
        if (E_OK == errorId)
        {
            Gpt_Handler[coreId]->channelInfo[Channel].channelStatus = GPT_STATUS_RUNNING;
            Gpt_Handler[coreId]->channelInfo[Channel].channelMode = (*
                    (Gpt_Handler[coreId]->config->channelConfig))[Channel].channelMode;
            Gpt_Handler[coreId]->targetTime[Channel] = Value;
            Gpt_Ip_StartTimer( &((*(Gpt_Handler[coreId]->config->channelConfig))[Channel].hwChannelConfig),
                               (*(Gpt_Handler[coreId]->config->channelConfig))[Channel].channelMode, Value);
        } /* else not needed */
    } /* else not needed */

#if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE))

    if (E_OK != errorId)
    {
#if (STD_ON == GPT_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_START_TIMER_ID, errorId);
#endif /** #if (STD_ON == GPT_DEV_ERROR_DETECT) */
#if (STD_ON == GPT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_START_TIMER_ID, errorId);
#endif /** #if (STD_ON == GPT_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE)) */
}

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
void Gpt_StopTimer(Gpt_ChannelType Channel)
{
    boolean isExpired = FALSE;
    uint32 coreId = Gpt_GetCoreId();
    Std_ReturnType errorId;

    /* #10 check parameter and channel status. */
    errorId = Gpt_ValidateParamCommon(Channel);

    if (E_OK == errorId)
    {
        /* #20 If the stop is repeated, nothing will be done. This is the autosar specification. */
        if (GPT_STATUS_RUNNING == Gpt_Handler[coreId]->channelInfo[Channel].channelStatus)
        {
            /* #20 get channel Elapsed */
            Gpt_Handler[coreId]->elapsedTime[Channel] = Gpt_Ip_GetTimeElapsed(&((*
                    (Gpt_Handler[coreId]->config->channelConfig))[Channel].hwChannelConfig), &isExpired);
            /* #30 stop channel */
            Gpt_Ip_StopTimer(&((*(Gpt_Handler[coreId]->config->channelConfig))[Channel].hwChannelConfig));

            /* #40 Change channel status */
            if (TRUE == (boolean)isExpired)
            {
                Gpt_Handler[coreId]->channelInfo[Channel].channelStatus = GPT_STATUS_EXPIRED;
            }
            else
            {
                Gpt_Handler[coreId]->channelInfo[Channel].channelStatus = GPT_STATUS_STOPPED;
            }
        } /* else not needed */
    } /* else not needed */

#if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE))

    if (E_OK != errorId)
    {
#if (STD_ON == GPT_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_STOP_TIMER_ID, errorId);
#endif /** #if (STD_ON == GPT_DEV_ERROR_DETECT) */
#if (STD_ON == GPT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_STOP_TIMER_ID, errorId);
#endif /** #if (STD_ON == GPT_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE)) */

}

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
Gpt_ValueType Gpt_GetTimeElapsed(Gpt_ChannelType Channel)
{
    Gpt_ValueType retVal = 0;
    boolean isExpired = FALSE;
    uint32 coreId = Gpt_GetCoreId();
    Std_ReturnType errorId;

    /* #10 check parameter and channel status. */
    errorId = Gpt_ValidateParamCommon(Channel);

    if (E_OK == errorId)
    {
        /* #20 get channel elapsed. */
        retVal = Gpt_Ip_GetTimeElapsed(&((*
                                          (Gpt_Handler[coreId]->config->channelConfig))[Channel].hwChannelConfig), &isExpired);

        /* #30 View the corresponding channel status. */
        switch (Gpt_Handler[coreId]->channelInfo[Channel].channelStatus)
        {
        case GPT_STATUS_INITIALIZED:
            retVal = (Gpt_ValueType)0;
            break;

        case GPT_STATUS_RUNNING:
            if (TRUE == isExpired)
            {
                Gpt_Handler[coreId]->channelInfo[Channel].channelStatus = GPT_STATUS_EXPIRED;
            } /* else not needed */

            break;

        case GPT_STATUS_STOPPED:
            retVal = Gpt_Handler[coreId]->elapsedTime[Channel];
            break;

        case GPT_STATUS_EXPIRED:
            retVal = Gpt_Handler[coreId]->targetTime[Channel];
            break;

        default:
            /* Do Nothing */
            break;
        }
    } /* else not needed */

#if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE))

    if (E_OK != errorId)
    {
#if (STD_ON == GPT_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_TIME_ELAPSED_ID, errorId);
#endif /** #if (STD_ON == GPT_DEV_ERROR_DETECT) */
#if (STD_ON == GPT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_TIME_ELAPSED_ID, errorId);
#endif /** #if (STD_ON == GPT_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE)) */
    return retVal;
}
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
Gpt_ValueType Gpt_GetTimeRemaining(Gpt_ChannelType Channel)
{
    Gpt_ValueType retVal = 0;
    boolean isExpired = FALSE;
    uint32 coreId = Gpt_GetCoreId();
    Std_ReturnType errorId;

    /* #10 check parameter and channel status. */
    errorId = Gpt_ValidateParamCommon(Channel);

    if (E_OK == errorId)
    {
        /* #20 get channel elapsed. */
        retVal = Gpt_Ip_GetTimeElapsed(&((*
                                          (Gpt_Handler[coreId]->config->channelConfig))[Channel].hwChannelConfig), &isExpired);

        /* #30 View the corresponding channel status. */
        switch (Gpt_Handler[coreId]->channelInfo[Channel].channelStatus)
        {
        case GPT_STATUS_INITIALIZED:
            retVal = 0;
            break;

        case GPT_STATUS_RUNNING:
            if (TRUE == isExpired)
            {
                Gpt_Handler[coreId]->channelInfo[Channel].channelStatus = GPT_STATUS_EXPIRED;
                retVal = 0;
            }
            else
            {
                retVal = Gpt_Handler[coreId]->targetTime[Channel] - retVal;
            }

            break;

        case GPT_STATUS_STOPPED:
            retVal = Gpt_Handler[coreId]->targetTime[Channel] -
                     Gpt_Handler[coreId]->elapsedTime[Channel];
            break;

        case GPT_STATUS_EXPIRED:
            retVal = 0;
            break;

        default:
            /* Do Nothing */
            break;
        }
    } /* else not needed */

#if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE))

    if (E_OK != errorId)
    {
#if (STD_ON == GPT_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_TIME_REMAINING_ID, errorId);
#endif /** #if (STD_ON == GPT_DEV_ERROR_DETECT) */
#if (STD_ON == GPT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_TIME_REMAINING_ID, errorId);
#endif /** #if (STD_ON == GPT_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE)) */
    return retVal;
}
#endif /** #if (STD_ON == GPT_TIME_REMAINING_API) */

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
void Gpt_EnableNotification(Gpt_ChannelType Channel)
{
    uint32 coreId = Gpt_GetCoreId();
    Std_ReturnType errorId;

    /* #10 check parameter and channel status. */
    errorId = Gpt_ValidateParamCommon(Channel);

    if (E_OK == errorId)
    {
        /* #20 check notification point. */
        errorId = Gpt_ValidateNotification(Channel);

        if (E_OK == errorId)
        {
            /* #30 Change channel notification status. */
            Gpt_Handler[coreId]->channelInfo[Channel].notificationEnabled = (boolean)TRUE;
        } /* else not needed */
    } /* else not needed */

#if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE))

    if (E_OK != errorId)
    {
#if (STD_ON == GPT_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_NOTIFICATION_ID, errorId);
#endif /** #if (STD_ON == GPT_DEV_ERROR_DETECT) */
#if (STD_ON == GPT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_ENABLE_NOTIFICATION_ID, errorId);
#endif /** #if (STD_ON == GPT_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE)) */
}

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
void Gpt_DisableNotification(Gpt_ChannelType Channel)
{
    uint32 coreId = Gpt_GetCoreId();
    Std_ReturnType errorId;

    /* #10 check parameter and channel status. */
    errorId = Gpt_ValidateParamCommon(Channel);

    if (E_OK == errorId)
    {
        /* #20 check notification point. */
        errorId = Gpt_ValidateNotification(Channel);

        if (E_OK == errorId)
        {
            /* #30 Change channel notification status. */
            Gpt_Handler[coreId]->channelInfo[Channel].notificationEnabled = (boolean)FALSE;
        } /* else not needed */

    } /* else not needed */

#if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE))

    if (E_OK != errorId)
    {
#if (STD_ON == GPT_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DISABLE_NOTIFICATION_ID, errorId);
#endif /** #if (STD_ON == GPT_DEV_ERROR_DETECT) */
#if (STD_ON == GPT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_DISABLE_NOTIFICATION_ID, errorId);
#endif /** #if (STD_ON == GPT_SAFETY_ENABLE) */
    } /* else not needed */

#endif /** #if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE)) */
}
#endif /** #if (STD_ON == GPT_ENABLE_DISABLE_NOTIFICATION_API) */


#if (STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API)
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
Std_ReturnType Gpt_GetPredefTimerValue(Gpt_PredefTimerType PredefTimer, uint32 *TimeValuePtr)
{
    Std_ReturnType errorId;
    uint32 coreId = Gpt_GetCoreId();

    /* #10 check parameter and channel status. */
    errorId = Gpt_ValidateParamGetPredefTime(PredefTimer, TimeValuePtr);

    if (E_OK == errorId)
    {
        /* #20 get predef timer value. */
        Gpt_Ip_GetPredefTimerValue(Gpt_Handler[coreId]->config->predefChannelConfig, PredefTimer,
                                   TimeValuePtr);
    } /* else not needed */

    if (E_OK != errorId)
    {
#if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE))
#if (STD_ON == GPT_DEV_ERROR_DETECT)
        (void)Det_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_PREDEF_TIME_ID, errorId);
#endif /** #if (STD_ON == GPT_DEV_ERROR_DETECT) */
#if (STD_ON == GPT_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(GPT_MODULE_ID, GPT_INSTANCE_ID, GPT_GET_PREDEF_TIME_ID, errorId);
#endif /** #if (STD_ON == GPT_SAFETY_ENABLE) */
#endif /** #if ((STD_ON == GPT_DEV_ERROR_DETECT) || (STD_ON == GPT_SAFETY_ENABLE)) */
        errorId = E_NOT_OK;
    } /* else not needed */

    return errorId;
}
#endif /** #if (STD_ON == GPT_PREDEFTIMER_FUNCTIONALITY_API) */

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
void Gpt_Irq(Gpt_HwModule hwModule)
{
    uint32 irqStatus;
    uint8 i = 0;
    Gpt_HwChannel hwChannel;
    Gpt_ChannelType channel = 0u;
    uint32 coreId = Gpt_GetCoreId();
    uint32 errorId = Gpt_ValidateIrq(hwModule);

    irqStatus = Gpt_Ip_GetInterrupt((uint8)hwModule);
    /* #10 Is the interrupt expected. */
    if ((E_OK == errorId) &&
        (0UL != irqStatus))
    {
        /* #30 clear g0 irq. */
        if ((irqStatus & GPT_IP_HW_CHANNEL_G0_IRQ) > 0U)
        {
            hwChannel = GPT_HW_TIMER_G0;
            Gpt_Ip_ClearInterrupt((uint8)hwModule, ((uint8)(irqStatus & GPT_IP_HW_CHANNEL_G0_IRQ)));
        }
        /* #40 clear g1 irq. */
        else
        {
            hwChannel = GPT_HW_TIMER_G1;
            Gpt_Ip_ClearInterrupt((uint8)hwModule, ((uint8)(irqStatus & GPT_IP_HW_CHANNEL_G1_IRQ)));
        }

        /* #50 get channel ID. */
        while (i < Gpt_Handler[coreId]->config->channelCount)
        {
            if (((*(Gpt_Handler[coreId]->config->channelConfig))[i].hwChannelConfig.timerHwModule
                    == (Gpt_HwModule)hwModule)
                    && ((*(Gpt_Handler[coreId]->config->channelConfig))[i].hwChannelConfig.hwChannel ==
                        (Gpt_HwChannel)hwChannel))
            {
                channel = i;
                break;
            } /* else not needed */

            i++;
        }

        /* #60 Change channel status. */
        if (GPT_CH_MODE_ONESHOT == Gpt_Handler[coreId]->channelInfo[channel].channelMode)
        {
            Gpt_Handler[coreId]->channelInfo[channel].channelStatus = GPT_STATUS_EXPIRED;
        } /* else not needed */

        /* #70 call back. */
        if ((TRUE == Gpt_Handler[coreId]->channelInfo[channel].notificationEnabled) &&
                ((*(Gpt_Handler[coreId]->config->channelConfig))[channel].notification != NULL_PTR))
        {
            (*(Gpt_Handler[coreId]->config->channelConfig))[channel].notification();
        } /* else not needed */
    } /* else not needed */
}

#define GPT_STOP_SEC_CODE
#include "Gpt_MemMap.h"

#ifdef __cplusplus
}
#endif

/* End of file */
