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
 *  \file     Pwm.h                                                                                     *
 *  \brief    This file contains interface header for PWM MCAL driver                                   *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/18     <td>3.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef PWM_H
#define PWM_H

/**
 *
 * \defgroup MCAL_PWM PWM Driver
 *
 * This component provides services for initialization and control of
 * the PWM unit (pulse width modulation).
 * The PWM module generates pulses with variable pulse width.
 * It allows the selection of the duty cycle and the
 * signal period time.
 *
 * \sa MCAL_PWM_MACRO
 * \sa MCAL_PWM_CFG
 * \sa MCAL_PWM_API
 */

/** \{ */

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
/** Traceability       : SWSR_PWM_003 */
#include "Pwm_Cfg.h"
#include "Pwm_Type.h"
#include "Pwm_Ip.h"

/**
 *  \defgroup MCAL_PWM_CFG PWM Configuration.
 *
 * This files defines PWM MCAL configuration structures
 *  \{
 */

/** \} */

/**
 *  \defgroup MCAL_PWM_API PWM Api.
 *
 * This files defines PWM MCAL api
 *  \{
 */

/** \} */

/**
 *  \defgroup MCAL_PWM_MACRO PWM macro.
 *
 * This files defines PWM MCAL macro
 *  \{
 */

/** \} */

/**
 *  \addtogroup MCAL_PWM_MACRO PWM macro
 *  \{
 */
/** \{ */
/** \brief  Semi Driver Vendor ID */
#define PWM_VENDOR_ID                                                   (0x8cU)
/** \brief  PWM Driver Module ID       */
#define PWM_MODULE_ID                                                   (121U)
/** \brief PWM Driver Instance ID */
#define PWM_INSTANCE_ID                                                 (0x00U)
/** \} */

/**
 * \brief   API service id.
 */
/** \{ */
/** \brief  Service ID for Pwm_Init */
#define PWM_INIT_SID                                                    ((uint8)0x00U)
/** \brief  Service ID for Pwm_DeInit */
#define PWM_DEINIT_SID                                                  ((uint8)0x01U)
/** \brief  Service ID for Pwm_SetDutyCycle */
#define PWM_SETDUTYCYCLE_SID                                            ((uint8)0x02U)
/** \brief  Service ID for Pwm_SetPeriodAndDuty */
#define PWM_SETPERIODANDDUTY_SID                                        ((uint8)0x03U)
/** \brief  Service ID for Pwm_SetOutputToIdle */
#define PWM_SETOUTPUTTOIDLE_SID                                         ((uint8)0x04U)
/** \brief  Service ID for Pwm_GetOutputState */
#define PWM_GETOUTPUTSTATE_SID                                          ((uint8)0x05U)
/** \brief  Service ID for Pwm_DisableNotification */
#define PWM_DISABLENOTIFICATION_SID                                     ((uint8)0x06U)
/** \brief  Service ID for Pwm_EnableNotification */
#define PWM_ENABLENOTIFICATION_SID                                      ((uint8)0x07U)
/** \brief  Service ID for Pwm_SetPowerState */
#define PWM_SETPOWERSTATE_SID                                           ((uint8)0x09U)
/** \brief  Service ID for Pwm_GetCurrentPowerState */
#define PWM_GETCURRENTPOWERSTATE_SID                                    ((uint8)0x0aU)
/** \brief  Service ID for Pwm_GetTargetPowerState */
#define PWM_GETTARGETPOWERSTATE_SID                                     ((uint8)0x0bU)
/** \brief  Service ID for Pwm_PreparePowerState */
#define PWM_PREPAREPOWERSTATE_SID                                       ((uint8)0x0cU)
/** \brief  Service ID for Pwm_GetVersionInfo */
#define PWM_GETVERSIONINFO_SID                                          ((uint8)0x08U)
/** \} */
/** \} */

/**
 *  \addtogroup MCAL_PWM_API PWM Api
 *  \{
 */
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
void Pwm_Init(const Pwm_ConfigType* ConfigPtr);

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
void Pwm_DeInit(void);
#endif /* #if (STD_ON == PWM_DE_INIT_API) */

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
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle);
#endif /* #if (STD_ON == PWM_SET_DUTY_CYCLE_API) */

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
void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle);
#endif /* #if (STD_ON == PWM_SET_PERIOD_AND_DUTY_API) */

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
void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber);
#endif /* #if (STD_ON == PWM_SET_OUTPUT_TO_IDLE_API) */

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
Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber);
#endif /* #if (STD_ON == PWM_GET_OUTPUT_STATE_API) */

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
void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber);
#endif /* #if (STD_ON == PWM_NOTIFICATION_SUPPORTED) */

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
void Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification);
#endif /* #if (STD_ON == PWM_NOTIFICATION_SUPPORTED) */

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
void Pwm_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif /* #if (STD_ON == PWM_VERSION_INFO_API) */

#ifdef __cplusplus
}
#endif

/** \} */

/** \} */

#endif /* PWM_H */
/* End of file */
