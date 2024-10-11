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
 * \file     Pwm.c                                                                                      *
 * \brief    AUTOSAR 4.3.1 MCAL PWM Driver                                                              *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/18     <td>3.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "FuSaMcalReportError.h"
/** Traceability       : SWSR_PWM_004 */
#include "SchM_Pwm.h"
#include "Det.h"
#include "Pwm.h"

#define PWM_START_SEC_CODE
#include "Pwm_MemMap.h"

/********************************************************************************************************
 *                                 Imported Compiler Switch Checks                                      *
 *******************************************************************************************************/
#ifndef PWM_SW_MAJOR_VERSION
#error "PWM_SW_MAJOR_VERSION is not defined."
#endif

#ifndef PWM_SW_MINOR_VERSION
#error "PWM_SW_MINOR_VERSION is not defined."
#endif

#ifndef PWM_SW_PATCH_VERSION
#error "PWM_SW_PATCH_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef PWM_AR_RELEASE_MAJOR_VERSION
#error "PWM_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef PWM_AR_RELEASE_MINOR_VERSION
#error "PWM_AR_RELEASE_MINOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef PWM_AR_RELEASE_REVISION_VERSION
#error "PWM_AR_RELEASE_REVISION_VERSION is not defined."
#endif

/** \brief  AUTOSAR Major and Minor release version check. */
#if(PWM_AR_RELEASE_MAJOR_VERSION != 4U)
#error "PWM_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#if(PWM_AR_RELEASE_MINOR_VERSION != 3U)
#error "PWM_AR_RELEASE_MINOR_VERSION does not match."
#endif

#if(PWM_AR_RELEASE_REVISION_VERSION != 1U)
#error "PWM_AR_RELEASE_REVISION_VERSION does not match."
#endif

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief  Dummy error id state process. */
#define PWM_DUMMY_STATEMENT(state)                                      ((state) = (state))

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief Service for PWM initialization.
 *
 * \verbatim
 * Syntax             : void Pwm_Init(
 *                          const Pwm_ConfigType* ConfigPtr)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : ConfigPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Driver Module Initialization function.The Initialization function shall
 *                      initialize all PWM relevant registers with the values of the structure
 *                      referenced by the parameter ConfigPtr.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_008 SWSR_PWM_009 SWSR_PWM_012 SWSR_PWM_024 SWSR_PWM_025 SWSR_PWM_026
 *                      SWSR_PWM_027 SWSR_PWM_030 SWSR_PWM_032 SWSR_PWM_033 SWSR_PWM_034 SWSR_PWM_083
 *                      SWSR_PWM_084 SWSR_PWM_091 SWSR_PWM_092
 *******************************************************************************************************/
void Pwm_Init(const Pwm_ConfigType* ConfigPtr)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType* coreHandlerPtr = Pwm_HandlerPtr[coreId];

#if (STD_ON == PWM_PRECOMPILE_SUPPORT)
    coreHandlerPtr->configPtr = &Pwm_Config;
#else
    coreHandlerPtr->configPtr = ConfigPtr;
#endif /** #if (STD_ON == PWM_PRECOMPILE_SUPPORT) */

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (PWM_STATE_INIT == coreHandlerPtr->globalState)
    {
        errorId = (Std_ReturnType)PWM_E_ALREADY_INITIALIZED;
    }
    else if(NULL_PTR == coreHandlerPtr->configPtr)
    {
        errorId = (Std_ReturnType)PWM_E_PARAM_POINTER;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 Set PWM controllers base addresses */
        Pwm_Ip_SetBaseAddr();
        /* #30 PWM IP initialize */
        errorId = Pwm_Ip_Init(coreHandlerPtr->configPtr);
        if ((Std_ReturnType)E_OK != errorId)
        {
            coreHandlerPtr->globalState = PWM_STATE_UNINIT;
        }
        else
        {
            /* #40 Set module state to initialized */
            coreHandlerPtr->globalState = PWM_STATE_INIT;
        }
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE))
    /* #50 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == PWM_DEV_ERROR_DETECT)
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_INIT_SID, errorId);
#endif /** #if (STD_ON == PWM_DEV_ERROR_DETECT) */
#if (STD_ON == PWM_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_INIT_SID, errorId);
#endif /** #if (STD_ON == PWM_SAFETY_ENABLE) */
    } /* else not needed */
#else
    /* #60 Dummy assignment avoid compiler warning */
    PWM_DUMMY_STATEMENT(errorId);
#endif /** #if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE)) */

#if (STD_ON == PWM_PRECOMPILE_SUPPORT)
    (void)ConfigPtr;
#endif /** #if (STD_ON == PWM_PRECOMPILE_SUPPORT) */
}

#if (STD_ON == PWM_DE_INIT_API)
/** *****************************************************************************************************
 * \brief Service for PWM De-Initialization.
 *
 * \verbatim
 * Syntax             : void Pwm_DeInit(void)
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The function Pwm_DeInit shall de-initialize the PWM module.
 *                      This function is available if the PWM_DE_INIT_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_008 SWSR_PWM_035 SWSR_PWM_036 SWSR_PWM_037 SWSR_PWM_038 SWSR_PWM_039
 *                      SWSR_PWM_040 SWSR_PWM_083 SWSR_PWM_084 SWSR_PWM_085 SWSR_PWM_091 SWSR_PWM_092
 *******************************************************************************************************/
void Pwm_DeInit(void)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType* coreHandlerPtr = Pwm_HandlerPtr[coreId];

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (PWM_STATE_UNINIT == coreHandlerPtr->globalState)
    {
        errorId = (Std_ReturnType)PWM_E_UNINIT;
    }
    else
    {
        /* ----- Implementation ----------------------------------------------- */
        /* #20 PWM IP de-initialize */
        errorId = Pwm_Ip_Deinit();
        if ((Std_ReturnType)E_OK == errorId)
        {
            /* #30 Set module state to uninitialized */
            coreHandlerPtr->globalState = PWM_STATE_UNINIT;
        }
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE))
    /* #40 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == PWM_DEV_ERROR_DETECT)
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_DEINIT_SID, errorId);
#endif /** #if (STD_ON == PWM_DEV_ERROR_DETECT) */
#if (STD_ON == PWM_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_DEINIT_SID, errorId);
#endif /** #if (STD_ON == PWM_SAFETY_ENABLE) */
    } /* else not needed */
#else
    /* #50 Dummy assignment avoid compiler warning */
    PWM_DUMMY_STATEMENT(errorId);
#endif /** #if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE)) */
}
#endif /** #if (STD_ON == PWM_DE_INIT_API) */

#if (STD_ON == PWM_SET_DUTY_CYCLE_API)
/** *****************************************************************************************************
 * \brief Service sets the duty cycle of the PWM channel.
 *
 * \verbatim
 * Syntax             : void Pwm_SetDutyCycle(
 *                          Pwm_ChannelType ChannelNumber,
 *                          uint16 DutyCycle)
 *
 * Service ID[hex]    : 0x02
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ChannelNumber - Numeric identifier of the PWM
 *                      DutyCycle     - Min=0x0000 Max=0x8000
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The function Pwm_SetDutyCycle shall set the duty cycle of the PWM channel.
 *                      This function is available if the PWM_SET_DUTY_CYCLE_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_008 SWSR_PWM_010 SWSR_PWM_011 SWSR_PWM_014
 *                      SWSR_PWM_015 SWSR_PWM_041 SWSR_PWM_042 SWSR_PWM_047 SWSR_PWM_048 SWSR_PWM_061
 *                      SWSR_PWM_062 SWSR_PWM_083 SWSR_PWM_084 SWSR_PWM_085 SWSR_PWM_086 SWSR_PWM_087
 *                      SWSR_PWM_091 SWSR_PWM_092
 *******************************************************************************************************/
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (PWM_STATE_UNINIT == coreHandlerPtr->globalState)
    {
        errorId = (Std_ReturnType)PWM_E_UNINIT;
    }
    else if ((ChannelNumber > PWM_MAX_CHANNEL_NUM) || (((uint8)0U) == ChannelNumber))
    {
        errorId = (Std_ReturnType)PWM_E_PARAM_CHANNEL;
    }
    else if (DutyCycle > PWM_IP_DUTY_100)
    {
        errorId = (Std_ReturnType)PWM_E_DUTYCYCLE_OUT_OF_RANGE;
    }
    else if (coreId != Pwm_Ip_GetModuleAssignCoreId(ChannelNumber))
    {
        errorId = (Std_ReturnType)PWM_E_ILLEGAL_RES;
    }
    else
    {
        /* #20 PWM IP set duty cycle */
        errorId = Pwm_Ip_SetDutyCycle(ChannelNumber, DutyCycle);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE))
    /* #30 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == PWM_DEV_ERROR_DETECT)
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SETDUTYCYCLE_SID, errorId);
#endif /** #if (STD_ON == PWM_DEV_ERROR_DETECT) */
#if (STD_ON == PWM_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SETDUTYCYCLE_SID, errorId);
#endif /** #if (STD_ON == PWM_SAFETY_ENABLE) */
    } /* else not needed */
#else
    /* #40 Dummy assignment avoid compiler warning */
    PWM_DUMMY_STATEMENT(errorId);
#endif /** #if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE)) */
}
#endif /** #if (STD_ON == PWM_SET_DUTY_CYCLE_API) */

#if (STD_ON == PWM_SET_PERIOD_AND_DUTY_API)
/** *****************************************************************************************************
 * \brief Service sets the period and the duty cycle of a PWM channel.
 *
 * \verbatim
 * Syntax             : void Pwm_SetPeriodAndDuty(
 *                          Pwm_ChannelType ChannelNumber,
 *                          Pwm_PeriodType Period,
 *                          uint16 DutyCycle)
 *
 * Service ID[hex]    : 0x03
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ChannelNumber - Numeric identifier of the PWM
 *                      Period        - Period of the PWM signal
 *                      DutyCycle     - Min=0x0000 Max=0x8000
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The function Pwm_SetPeriodAndDuty shall set the period and the duty cycle of a
 *                      PWM channel.
 *                      This function is available if the PWM_SET_PERIOD_AND_DUTY_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_008 SWSR_PWM_010 SWSR_PWM_011 SWSR_PWM_014
 *                      SWSR_PWM_015 SWSR_PWM_049 SWSR_PWM_050 SWSR_PWM_051 SWSR_PWM_053 SWSR_PWM_054
 *                      SWSR_PWM_055 SWSR_PWM_056 SWSR_PWM_060 SWSR_PWM_083 SWSR_PWM_084 SWSR_PWM_085
 *                      SWSR_PWM_086 SWSR_PWM_087 SWSR_PWM_091 SWSR_PWM_092
 *******************************************************************************************************/
void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (PWM_STATE_UNINIT == coreHandlerPtr->globalState)
    {
        errorId = (Std_ReturnType)PWM_E_UNINIT;
    }
    else if ((ChannelNumber > PWM_MAX_CHANNEL_NUM) || (((uint8)0U) == ChannelNumber))
    {
        errorId = (Std_ReturnType)PWM_E_PARAM_CHANNEL;
    }
    else if (PWM_VARIABLE_PERIOD != Pwm_Ip_ValidateChannelClass(ChannelNumber))
    {
        errorId = (Std_ReturnType)PWM_E_PERIOD_UNCHANGEABLE;
    }
    else if (DutyCycle > PWM_IP_DUTY_100)
    {
        errorId = (Std_ReturnType)PWM_E_DUTYCYCLE_OUT_OF_RANGE;
    }
    else if (coreId != Pwm_Ip_GetModuleAssignCoreId(ChannelNumber))
    {
        errorId = (Std_ReturnType)PWM_E_ILLEGAL_RES;
    }
    else
    {
        errorId = Pwm_Ip_SetPeriodAndDuty(ChannelNumber, Period, DutyCycle);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE))
    /* #30 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == PWM_DEV_ERROR_DETECT)
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SETPERIODANDDUTY_SID, errorId);
#endif /** #if (STD_ON == PWM_DEV_ERROR_DETECT) */
#if (STD_ON == PWM_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SETPERIODANDDUTY_SID,
                                   errorId);
#endif /** #if (STD_ON == PWM_SAFETY_ENABLE) */
    } /* else not needed */
#else
    /* #40 Dummy assignment avoid compiler warning */
    PWM_DUMMY_STATEMENT(errorId);
#endif /** #if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE)) */
}
#endif /** #if (STD_ON == PWM_SET_PERIOD_AND_DUTY_API) */

#if (STD_ON == PWM_SET_OUTPUT_TO_IDLE_API)
/** *****************************************************************************************************
 * \brief Service sets the PWM output to the configured Idle state.
 *
 * \verbatim
 * Syntax             : void Pwm_SetOutputToIdle(
 *                          Pwm_ChannelType ChannelNumber)
 *
 * Service ID[hex]    : 0x04
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ChannelNumber - Numeric identifier of the PWM
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The function Pwm_SetOutputToIdle shall set immediately the PWM output to the
 *                      configured Idle state.
 *                      This function is available if the PWM_SET_OUTPUT_TO_IDLE_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_008 SWSR_PWM_010 SWSR_PWM_057 SWSR_PWM_058
 *                      SWSR_PWM_059 SWSR_PWM_083 SWSR_PWM_084 SWSR_PWM_085 SWSR_PWM_087 SWSR_PWM_091
 *                      SWSR_PWM_092
 *******************************************************************************************************/
void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId;
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (PWM_STATE_UNINIT == coreHandlerPtr->globalState)
    {
        errorId = (Std_ReturnType)PWM_E_UNINIT;
    }
    else if ((ChannelNumber > PWM_MAX_CHANNEL_NUM) || (((uint8)0U) == ChannelNumber))
    {
        errorId = (Std_ReturnType)PWM_E_PARAM_CHANNEL;
    }
    else if (coreId != Pwm_Ip_GetModuleAssignCoreId(ChannelNumber))
    {
        errorId = (Std_ReturnType)PWM_E_ILLEGAL_RES;
    }
    else
    {
        /* #20 PWM IP set output idle */
        errorId = Pwm_Ip_SetOutputToIdle(ChannelNumber);
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE))
    /* #30 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == PWM_DEV_ERROR_DETECT)
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SETOUTPUTTOIDLE_SID, errorId);
#endif /** #if (STD_ON == PWM_DEV_ERROR_DETECT) */
#if (STD_ON == PWM_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_SETOUTPUTTOIDLE_SID,
                                   errorId);
#endif /** #if (STD_ON == PWM_SAFETY_ENABLE) */
    } /* else not needed */
#else
    /* #40 Dummy assignment avoid compiler warning */
    PWM_DUMMY_STATEMENT(errorId);
#endif /** #if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE)) */
}
#endif /** #if (STD_ON == PWM_SET_OUTPUT_TO_IDLE_API) */

#if (STD_ON == PWM_GET_OUTPUT_STATE_API)
/** *****************************************************************************************************
 * \brief  Service to get output state of PWM.
 *
 * \verbatim
 * Syntax             : Pwm_OutputStateType Pwm_GetOutputState(
 *                          Pwm_ChannelType ChannelNumber)
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ChannelNumber - Numeric identifier of the PWM
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : PWM_LOW  - The PWM output state is low
                        PWM_HIGH - The PWM output state is high
 *
 * Description        : The function Pwm_GetOutputState shall get status of output PWM.
 *                      This function is available if the PWM_GET_OUTPUT_STATE_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_008 SWSR_PWM_010 SWSR_PWM_063 SWSR_PWM_064
 *                      SWSR_PWM_065 SWSR_PWM_066 SWSR_PWM_067 SWSR_PWM_083 SWSR_PWM_084 SWSR_PWM_085
 *                      SWSR_PWM_087 SWSR_PWM_091 SWSR_PWM_092
 *******************************************************************************************************/
Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    Pwm_OutputStateType outputState = PWM_LOW;
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (PWM_STATE_UNINIT == coreHandlerPtr->globalState)
    {
        errorId = (Std_ReturnType)PWM_E_UNINIT;
    }
    else if ((ChannelNumber > PWM_MAX_CHANNEL_NUM) || (((uint8)0U) == ChannelNumber))
    {
        errorId = (Std_ReturnType)PWM_E_PARAM_CHANNEL;
    }
    else
    {
        if (coreId != Pwm_Ip_GetModuleAssignCoreId(ChannelNumber))
        {
            errorId = (Std_ReturnType)PWM_E_ILLEGAL_RES;
        } /* else not needed */
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE))
    /* #20 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == PWM_DEV_ERROR_DETECT)
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_GETOUTPUTSTATE_SID, errorId);
#endif /** #if (STD_ON == PWM_DEV_ERROR_DETECT) */
#if (STD_ON == PWM_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_GETOUTPUTSTATE_SID,
                                   errorId);
#endif /** #if (STD_ON == PWM_SAFETY_ENABLE) */
    } /* else not needed */
#endif /** #if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE)) */

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #30 PWM IP get output state */
        outputState = Pwm_Ip_GetOutputState(ChannelNumber);
    } /* else not needed */

    return outputState;
}
#endif /** #if (STD_ON == PWM_GET_OUTPUT_STATE_API) */

#if (STD_ON == PWM_NOTIFICATION_SUPPORTED)
/** *****************************************************************************************************
 * \brief Service to disable the PWM signal edge notification.
 *
 * \verbatim
 * Syntax             : void Pwm_DisableNotification(
 *                          Pwm_ChannelType ChannelNumber)
 *
 * Service ID[hex]    : 0x06
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ChannelNumber - Numeric identifier of the PWM
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The function Pwm_DisableNotification shall disable the PWM signal edge
 *                      notification.
 *                      This function is available if the PWM_NOTIFICATION_SUPPORTED is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_008 SWSR_PWM_010 SWSR_PWM_068 SWSR_PWM_069
 *                      SWSR_PWM_070 SWSR_PWM_071 SWSR_PWM_080 SWSR_PWM_082 SWSR_PWM_083 SWSR_PWM_084
 *                      SWSR_PWM_085 SWSR_PWM_087 SWSR_PWM_091 SWSR_PWM_092
 *******************************************************************************************************/
void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (PWM_STATE_UNINIT == coreHandlerPtr->globalState)
    {
        errorId = (Std_ReturnType)PWM_E_UNINIT;
    }
    else if ((ChannelNumber > PWM_MAX_CHANNEL_NUM) || (((uint8)0U) == ChannelNumber))
    {
        errorId = (Std_ReturnType)PWM_E_PARAM_CHANNEL;
    }
    else
    {
        if (coreId != Pwm_Ip_GetModuleAssignCoreId(ChannelNumber))
        {
            errorId = (Std_ReturnType)PWM_E_ILLEGAL_RES;
        } /* else not needed */
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE))
    /* #20 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == PWM_DEV_ERROR_DETECT)
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_DISABLENOTIFICATION_SID,
                            errorId);
#endif /** #if (STD_ON == PWM_DEV_ERROR_DETECT) */
#if (STD_ON == PWM_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_DISABLENOTIFICATION_SID,
                                   errorId);
#endif /** #if (STD_ON == PWM_SAFETY_ENABLE) */
    } /* else not needed */
#endif /** #if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE)) */

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #30 PWM IP disable notification */
        Pwm_Ip_DisableNotification(ChannelNumber);
    } /* else not needed */
}
#endif /** #if (STD_ON == PWM_NOTIFICATION_SUPPORTED) */

#if (STD_ON == PWM_NOTIFICATION_SUPPORTED)
/** *****************************************************************************************************
 * \brief Service to enable the PWM signal edge notification according to notification parameter.
 *
 * \verbatim
 * Syntax             : void Pwm_EnableNotification(
 *                          Pwm_ChannelType ChannelNumber,
 *                          Pwm_EdgeNotificationType Notification)
 *
 * Service ID[hex]    : 0x07
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ChannelNumber - Numeric identifier of the PWM
 *                      Notification  - Notification only support PWM_FALLING_EDGE.
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : The function Pwm_EnableNotification shall enable the PWM signal edge
 *                      notification according to notification parameter.
 *                      This function is available if the PWM_NOTIFICATION_SUPPORTED is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_006 SWSR_PWM_007 SWSR_PWM_008 SWSR_PWM_010 SWSR_PWM_072 SWSR_PWM_073
 *                      SWSR_PWM_074 SWSR_PWM_075 SWSR_PWM_076 SWSR_PWM_080 SWSR_PWM_081 SWSR_PWM_083
 *                      SWSR_PWM_084 SWSR_PWM_085 SWSR_PWM_087 SWSR_PWM_091 SWSR_PWM_092
 *******************************************************************************************************/
void Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;
    uint8 coreId = Pwm_Ip_GetCoreID();
    Pwm_HandlerConfigType const* coreHandlerPtr = Pwm_HandlerPtr[coreId];

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check module states */
    if (PWM_STATE_UNINIT == coreHandlerPtr->globalState)
    {
        errorId = (Std_ReturnType)PWM_E_UNINIT;
    }
    else if ((ChannelNumber > PWM_MAX_CHANNEL_NUM) || (((uint8)0U) == ChannelNumber))
    {
        errorId = (Std_ReturnType)PWM_E_PARAM_CHANNEL;
    }
    else if (coreId != Pwm_Ip_GetModuleAssignCoreId(ChannelNumber))
    {
        errorId = (Std_ReturnType)PWM_E_ILLEGAL_RES;
    }
    else
    {
        /* Check notification type */
        if (PWM_FALLING_EDGE != Notification)
        {
            errorId = PWM_E_CONFIG_EDGE_TYPE;
        } /* else not needed */
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE))
    /* #20 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == PWM_DEV_ERROR_DETECT)
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_ENABLENOTIFICATION_SID,
                            errorId);
#endif /** #if (STD_ON == PWM_DEV_ERROR_DETECT) */
#if (STD_ON == PWM_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_ENABLENOTIFICATION_SID,
                                   errorId);
#endif /** #if (STD_ON == PWM_SAFETY_ENABLE) */
    } /* else not needed */
#endif /** #if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE)) */

    if ((Std_ReturnType)E_OK == errorId)
    {
        /* #30 PWM IP enable notification */
        Pwm_Ip_EnableNotification(ChannelNumber, Notification);
    } /* else not needed */
}
#endif /** #if (STD_ON == PWM_NOTIFICATION_SUPPORTED) */

#if (STD_ON == PWM_VERSION_INFO_API)
/** *****************************************************************************************************
 * \brief Service returns the version information of PWM.
 *
 * \verbatim
 * Syntax             : void Pwm_GetVersionInfo(
 *                          Std_VersionInfoType versionInfo)
 *
 * Service ID[hex]    : 0x08
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : versioninfo - Pointer to where to store the version information of PWM.
 *
 * Return value       : None
 *
 * Description        : This function returns the version information of this module
 *                      The version information include : Module ID, Vendor ID.
 *                      Vendor specific version numbers.
 *                      This function is available if the PWM_VERSION_INFO_API is set STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_PWM_008 SWSR_PWM_077 SWSR_PWM_083 SWSR_PWM_084 SWSR_PWM_091 SWSR_PWM_092
 *******************************************************************************************************/
void Pwm_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    /* ----- Local Variables ---------------------------------------------- */
    Std_ReturnType errorId = (Std_ReturnType)E_OK;

    /* ----- Development Error Checks ------------------------------------- */
    /* #10 Check input parameters for plausibility */
    if ( NULL_PTR == versioninfo )
    {
        errorId = PWM_E_PARAM_POINTER;
    }
    else
    {
        /* #20 Retrieve version information */
        versioninfo->vendorID = PWM_VENDOR_ID;
        versioninfo->moduleID = PWM_MODULE_ID;
        versioninfo->sw_major_version = PWM_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = PWM_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = PWM_SW_PATCH_VERSION;
    }

    /* ----- Development Error Report --------------------------------------- */
#if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE))
    /* #30 Report default errors if any occurred */
    if ((Std_ReturnType)E_OK != errorId)
    {
#if (STD_ON == PWM_DEV_ERROR_DETECT)
        (void)Det_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_GETVERSIONINFO_SID, errorId);
#endif /** #if (STD_ON == PWM_DEV_ERROR_DETECT) */
#if (STD_ON == PWM_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(PWM_MODULE_ID, PWM_INSTANCE_ID, PWM_GETVERSIONINFO_SID,
                errorId);
#endif /** #if (STD_ON == PWM_SAFETY_ENABLE) */
    }
#else
    /* #40 Dummy assignment avoid compiler warning */
    PWM_DUMMY_STATEMENT(errorId);
#endif /** #if ((STD_ON == PWM_DEV_ERROR_DETECT) || (STD_ON == PWM_SAFETY_ENABLE)) */
}
#endif /** #if (STD_ON == PWM_VERSION_INFO_API) */

#define PWM_STOP_SEC_CODE
#include "Pwm_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
