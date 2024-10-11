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
 * \file     Icu.h                                                                                      *
 * \brief    This file mainly contains the definition of the autosar standard                           *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/17     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef ICU_H
#define ICU_H

/**
 *
 * \defgroup MCAL_ICU ICU Driver
 *
 * The ICU driver is a module using the input capture unit (ICU) for demodulation of aPWM signal,
 * counting pulses, measuring of frequency and duty cycle, generating simple interrupts and also wakeup
 * interrupts.
 *
 * \sa MCAL_ICU_CFG
 * \sa MCAL_ICU_API
 * \sa MCAL_ICU_MACRO
 * \{
 */


#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/

/* internal hardware operation file */
#include "Icu_Ip.h"

/**
 *  \defgroup MCAL_ICU_CFG ICU Configuration.
 *
 * This files defines MCAL ICU configuration structures
 *  \{
 */

/** \} */

/**
 *  \defgroup MCAL_ICU_API ICU Api.
 *
 * This files defines MCAL ICU api
 *  \{
 */

/** \} */

/**
 *  \defgroup MCAL_ICU_MACRO ICU macro.
 *
 * This files defines MCAL ICU macro
 *  \{
 */

/** \} */

/********************************************************************************************************
 *                                         Macro definition                                             *
 *******************************************************************************************************/

/**
 *  \addtogroup MCAL_ICU_MACRO ICU macro.
 *  \{
 */

/**
 *  \name ICU error ID Info
 * The following macros are all det_err that can be detected with in the software module
 *  \{
 */

/******************Autosar standard macro definition***************************/

/** \brief API service called with invalid pointer */
#define ICU_E_PARAM_POINTER             (0x0AU)
/** \brief API service called with invalid channel */
#define ICU_E_PARAM_CHANNEL             (0x0BU)
/** \brief API service called with invalid activation */
#define ICU_E_PARAM_ACTIVATION          (0x0CU)
/** \brief The ICU driver initilized fail */
#define ICU_E_INIT_FAILED               (0x0DU)
/** \brief API service used with invalid buffer size value */
#define ICU_E_PARAM_BUFFER_SIZE         (0x0EU)
/** \brief The ICU driver not initilized yet */
#define ICU_E_UNINIT                    (0x14U)
/** \brief The ICU channel with timestamp mode not started or the channel has stoped */
#define ICU_E_NOT_STARTED               (0x15U)
/** \brief API service is called while a running operation */
#define ICU_E_BUSY_OPERATION            (0x16U)
/** \brief The ICU driver has been initilized before */
#define ICU_E_ALREADY_INITIALIZED       (0x17U)
/** \brief API service used with invalid buffer interval value */
#define ICU_E_PARAM_NOTIFY_INTERVAL     (0x18U)
/** \brief API service called with invalid parameter */
#define ICU_E_PARAM_VINFO               (0x19U)

/****************Semidrive customised error definition*************************/
/** \brief API service called without any error happens */
#define ICU_E_PARAM_INVALID_VALUE       (0xFFU)
/** \brief API service called with invalid hardware channel parameter */
#define ICU_E_PARAM_CHANNEL_CONFIG      (0x80U)

/** \} */
/* end of ICU error ID Info */

/****************Semidrive customised macro definition*************************/

/**
 *  \name ICU service ID Info
 * The following macros contain the service_id information included when det_err is generated
 *  \{
 */

/* service_id information: consistent with that defined by autodar */
/** \brief Icu_Init() API Service ID */
#define ICU_INIT_ID                     (0x00U)
/** \brief Icu_DeInit() API Service ID */
#define ICU_DEINIT_ID                   (0x01U)
/** \brief Icu_SetActivationCondition() API Service ID */
#define ICU_SET_ACTIVATION_CONDITION_ID (0x05U)
/** \brief Icu_DisableNotification() API Service ID */
#define ICU_DISABLE_NOTIFICATION_ID     (0x06U)
/** \brief Icu_EnableNotification() API Service ID */
#define ICU_ENABLE_NOTIFICATION_ID      (0x07U)
/** \brief Icu_GetInputState() API Service ID */
#define ICU_GET_INPUT_STATE_ID          (0x08U)
/** \brief Icu_StartTimestamp() API Service ID */
#define ICU_START_TIME_STAMP_ID         (0x09U)
/** \brief Icu_StopTimestamp() API Service ID */
#define ICU_STOP_TIME_STAMP_ID          (0x0AU)
/** \brief Icu_GetTimeStampIndex() API Service ID */
#define ICU_GET_TIME_STAMPINDEX_ID      (0x0BU)
/** \brief Icu_ResetEdgeCount() API Service ID */
#define ICU_RESET_EDGE_COUNT_ID         (0x0CU)
/** \brief Icu_EnableEdgeCount() API Service ID */
#define ICU_ENABLE_EDGE_COUNT_ID        (0x0DU)
/** \brief Icu_DisableEdgeCount() API Service ID */
#define ICU_DISABLE_EDGE_COUNT_ID       (0x0EU)
/** \brief Icu_GetEdgeNumbers() API Service ID */
#define ICU_GET_EDGE_NUMBER_ID          (0x0FU)
/** \brief Icu_GetTimeElapsed() API Service ID */
#define ICU_GET_TIME_ELPASED_ID         (0x10U)
/** \brief Icu_GetDutyCycleValues() API Service ID */
#define ICU_GET_DUTY_CYCLE_VALUES_ID    (0x11U)
/** \brief Icu_GetVersionInfo() API Service ID */
#define ICU_GET_VERSIONINFO_ID          (0x12U)
/** \brief Icu_StartSignalMeasurement() API Service ID */
#define ICU_START_SIGNAL_MEASURE_ID     (0x13U)
/** \brief Icu_StopSignalMeasurement() API Service ID */
#define ICU_STOP_SIGNAL_MEASURE_ID      (0x14U)
/** \brief Icu_EnableEdgeDetection() API Service ID */
#define ICU_ENABLE_EDGE_DETECTION_ID    (0x16U)
/** \brief Icu_DisableEdgeDetection() API Service ID */
#define ICU_DISABLE_EDGE_DETECTION_ID   (0x17U)

/** \} */
/* end of ICU service ID Info */

/**
 *  \name ICU version Info
 * The following macros contain the vendor information and software version information
 *  \{
 */

/* module information */
/** \brief  Semi Driver Vendor ID */
#define ICU_VENDOR_ID                   (0x8CU)
/** \brief  ICU driver module ID */
#define ICU_MODULE_ID                   (122U)
/** \brief  ICU driver module instance ID */
#define ICU_INSTANCE_ID                 (0U)

/** \} */
/* end of ICU version Info */


/**
 *  \name ICU version Info
 * The following macros contain channel mask information
 *  \{
 */

/* ICU channel mask */
/** \brief  ICU driver valid logic channel index mask */
#define ICU_ACTUAL_CHAN_INDEX_MASK          (0xFFU)
/** \brief  ICU driver sub-channel offset in multi capture mode */
#define ICU_MULTI_SUBCHAN_OFFSET            (0x08U)
/** \brief  ICU driver valid sub-channel index in multi capture mode */
#define ICU_MULTI_SUBCHAN_INDEX_MASK        (0xFF00U)

/** \} */
/* end of ICU version Info */

/** \} */
/* end of MCAL_ICU_MACRO ICU macro */

/********************************************************************************************************
 *                                         Function definition                                          *
 *******************************************************************************************************/

/**
 *  \addtogroup MCAL_ICU_API ICU Api.
 *  \{
 */

/*********************Autosar standard function *******************************/

/** *****************************************************************************************************
 * \brief Service for ICU de-initialization.
 *
 * \verbatim
 * Syntax             : void Icu_Init(const Icu_ConfigType* ConfigPtr)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function initializes the driver.
 * \endverbatim
 * Traceability       : SWSR_ICU_031 SWSR_ICU_032 SWSR_ICU_033 SWSR_ICU_034
 *                      SWSR_ICU_035 SWSR_ICU_039 SWSR_ICU_040 SWSR_ICU_041
 *                      SWSR_ICU_042 SWSR_ICU_043
 *******************************************************************************************************/
void Icu_Init(const Icu_ConfigType* ConfigPtr);

#if (STD_ON == ICU_DEINIT_API)
/** *****************************************************************************************************
 * \brief This function returns the version information of this module.
 *
 * \verbatim
 * Syntax             : void Icu_DeInit(void)
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
 * Description        : This function de-initializes the ICU module
 * \endverbatim
 * Traceability       : SWSR_ICU_044 SWSR_ICU_045 SWSR_ICU_046 SWSR_ICU_047
 *                      SWSR_ICU_048 SWSR_ICU_049 SWSR_ICU_050 SWSR_ICU_051
 *                      SWSR_ICU_052 SWSR_ICU_053
 *******************************************************************************************************/
void Icu_DeInit(void);
#endif /* STD_ON == ICU_DEINIT_API */

/** *****************************************************************************************************
 * \brief Service for setting Activation Condition
 *
 * \verbatim
 * Syntax             : void Icu_SetActivationCondition(Icu_ChannelType Channel,
 *                                               Icu_ActivationType Activation)
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *                      Activation - type of activation (if supported by
 *                                   hardware)
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function sets the activation-edge for the given
 *                      channel.
 * \endverbatim
 * Traceability       : SWSR_ICU_054 SWSR_ICU_055 SWSR_ICU_056 SWSR_ICU_057
 *                      SWSR_ICU_058
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation);

/** *****************************************************************************************************
 * \brief Service for disabling notification
 *
 * \verbatim
 * Syntax             : void Icu_DisableNotification(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x06
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function disables the notification of a channel.
 * \endverbatim
 * Traceability       : SWSR_ICU_059 SWSR_ICU_060 SWSR_ICU_061 SWSR_ICU_062
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_DisableNotification(Icu_ChannelType Channel);

/** *****************************************************************************************************
 * \brief Service for enabling notification.
 *
 * \verbatim
 * Syntax             : void Icu_EnableNotification(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x07
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function enables the notification of a channel.
 * \endverbatim
 * Traceability       : SWSR_ICU_063 SWSR_ICU_064 SWSR_ICU_065 SWSR_ICU_066
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_EnableNotification(Icu_ChannelType Channel);

#if (STD_ON == ICU_GET_INPUTSTATE_API)
/** *****************************************************************************************************
 * \brief Service for getting the ICU input status.
 *
 * \verbatim
 * Syntax             : Icu_InputStateType Icu_GetInputState(
 *                                                      Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x08
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function returns the status of the ICU input.
 * \endverbatim
 * Traceability       : SWSR_ICU_067 SWSR_ICU_068 SWSR_ICU_069 SWSR_ICU_070
 *                      SWSR_ICU_071 SWSR_ICU_072 SWSR_ICU_073 SWSR_ICU_074
 *                      SWSR_ICU_075 SWSR_ICU_076 SWSR_ICU_077
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel);
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */

#if (STD_ON == ICU_TIMESTAMP_API)
/** *****************************************************************************************************
 * \brief Service for starts the captuing of timer values on the edges.
 *
 * \verbatim
 * Syntax             : void Icu_StartTimestamp(Icu_ChannelType Channel,
 *                                  Icu_ValueType* BufferPtr, uint16 BufferSize,
 *                                  uint16 NotifyInterval)
 *
 * Service ID[hex]    : 0x09
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *                      BufferSize - size of the external buffer (number of
 *                                   entries)
 *                      NotifyInterval - notification interval (number of
 *                                       events)
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : BufferPtr - pointer to the buffer-array where the
 *                                  timestamp values shall be placed
 *
 * Return value       : None
 *
 * Description        : This function starts the capturing of timer values on
 *                      the edges.
 * \endverbatim
 * Traceability       : SWSR_ICU_078 SWSR_ICU_079 SWSR_ICU_080 SWSR_ICU_081
 *                      SWSR_ICU_082 SWSR_ICU_083 SWSR_ICU_084 SWSR_ICU_085
 *                      SWSR_ICU_086 SWSR_ICU_087 SWSR_ICU_088 SWSR_ICU_089
 *                      SWSR_ICU_090 SWSR_ICU_091 SWSR_ICU_092 SWSR_ICU_093
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType* BufferPtr, uint16 BufferSize, uint16 NotifyInterval);

/** *****************************************************************************************************
 * \brief Service for stopping the timestamp measurement.
 *
 * \verbatim
 * Syntax             : void Icu_StopTimestamp(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x0A
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function stops the timestamp measurement of the
 *                      given channel
 * \endverbatim
 * Traceability       : SWSR_ICU_094 SWSR_ICU_095 SWSR_ICU_096 SWSR_ICU_097
 *                      SWSR_ICU_098 SWSR_ICU_099 SWSR_ICU_100
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_StopTimestamp(Icu_ChannelType Channel);

/** *****************************************************************************************************
 * \brief Service for reading the timestamp index of a givem channel.
 *
 * \verbatim
 * Syntax             : Icu_IndexType Icu_GetTimestampIndex(
 *                                                      Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x0B
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Get buffer index in timestamp mode
 *
 * Description        : This function reads the timestamp index of the given channel
 * \endverbatim
 * Traceability       : SWSR_ICU_101 SWSR_ICU_102 SWSR_ICU_103 SWSR_ICU_104
 *                      SWSR_ICU_105 SWSR_ICU_106 SWSR_ICU_107 SWSR_ICU_108
 *                      SWSR_ICU_109
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
Icu_IndexType Icu_GetTimestampIndex(Icu_ChannelType Channel);
#endif /* STD_ON == ICU_TIMESTAMP_API */

#if (STD_ON == ICU_EDGE_COUNT_API)
/** *****************************************************************************************************
 * \brief Service for resets the value of the counted edges to zero.
 *
 * \verbatim
 * Syntax             : void Icu_ResetEdgeCount(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x0C
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function resets the value of the counted edges to zero
 * \endverbatim
 * Traceability       : SWSR_ICU_110 SWSR_ICU_111 SWSR_ICU_112 SWSR_ICU_113
 *                      SWSR_ICU_114 SWSR_ICU_115
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_ResetEdgeCount(Icu_ChannelType Channel);

/** *****************************************************************************************************
 * \brief Service enabling the counting of edges of a given channel.
 *
 * \verbatim
 * Syntax             : void Icu_EnableEdgeCount(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x0D
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function enables the counting of edges of the given
 *                      channel
 * \endverbatim
 * Traceability       : SWSR_ICU_116 SWSR_ICU_117 SWSR_ICU_118 SWSR_ICU_119
 *                      SWSR_ICU_120 SWSR_ICU_121 SWSR_ICU_122 SWSR_ICU_123
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_EnableEdgeCount(Icu_ChannelType Channel);

/** *****************************************************************************************************
 * \brief Service for disabling the couting of edges of the given channel.
 *
 * \verbatim
 * Syntax             : void Icu_DisableEdgeCount(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x0E
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function disables the counting of edges of the
 *                      given channel
 * \endverbatim
 * Traceability       : SWSR_ICU_138 SWSR_ICU_139 SWSR_ICU_140 SWSR_ICU_141
 *                      SWSR_ICU_142 SWSR_ICU_143
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_DisableEdgeCount(Icu_ChannelType Channel);

/** *****************************************************************************************************
 * \brief Service for reading the number of counted edges
 *
 * \verbatim
 * Syntax             : Icu_EdgeNumberType Icu_GetEdgeNumbers(
 *                                                      Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x0F
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The edge number in edge counter
 *
 * Description        : This function reads the number of counted edges
 * \endverbatim
 * Traceability       : SWSR_ICU_144 SWSR_ICU_145 SWSR_ICU_146 SWSR_ICU_147
 *                      SWSR_ICU_148 SWSR_ICU_149 SWSR_ICU_150
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel);
#endif /* STD_ON == ICU_EDGE_COUNT_API */

#if (STD_ON == ICU_EDGE_DETECT_API)
/** *****************************************************************************************************
 * \brief Service for enabling/re-enabling the detection of edges of the given channel.
 *
 * \verbatim
 * Syntax             : void Icu_EnableEdgeDetection(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x16
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function enables the detection of edges of the
 *                      given channel
 * \endverbatim
 * Traceability       : SWSR_ICU_124 SWSR_ICU_125 SWSR_ICU_126 SWSR_ICU_127
 *                      SWSR_ICU_128 SWSR_ICU_129 SWSR_ICU_130 SWSR_ICU_131
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_EnableEdgeDetection(Icu_ChannelType Channel);

/** *****************************************************************************************************
 * \brief Service for disabling the detection of edges of the given channel.
 *
 * \verbatim
 * Syntax             : void Icu_DisableEdgeDetection(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x17
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function disables the detection of edges of the
 *                      given channel
 * \endverbatim
 * Traceability       : SWSR_ICU_132 SWSR_ICU_133 SWSR_ICU_134 SWSR_ICU_135
 *                      SWSR_ICU_136 SWSR_ICU_137
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_DisableEdgeDetection(Icu_ChannelType Channel);
#endif /* STD_ON == ICU_EDGE_DETECT_API */

#if (STD_ON == ICU_SIGNALMEASUREMENT_API)
/** *****************************************************************************************************
 * \brief Service for starting the measurement of signals.
 *
 * \verbatim
 * Syntax             : void Icu_StartSignalMeasurement(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x13
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function starts the measurement of signals
 * \endverbatim
 * Traceability       : SWSR_ICU_151 SWSR_ICU_152 SWSR_ICU_153 SWSR_ICU_154
 *                      SWSR_ICU_155 SWSR_ICU_156 SWSR_ICU_157 SWSR_ICU_158
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_StartSignalMeasurement(Icu_ChannelType Channel);

/** *****************************************************************************************************
 * \brief Service for stopping the measurement of signals.
 *
 * \verbatim
 * Syntax             : void Icu_StopSignalMeasurement(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x14
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function stops the measurement of signals
 * \endverbatim
 * Traceability       : SWSR_ICU_159 SWSR_ICU_160 SWSR_ICU_161 SWSR_ICU_162
 *                      SWSR_ICU_163 SWSR_ICU_164 SWSR_ICU_165
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_StopSignalMeasurement(Icu_ChannelType Channel);

#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
/** *****************************************************************************************************
 * \brief Service for reading the coherent active time and period time of given
 *        channel.
 *
 * \verbatim
 * Syntax             : void Icu_GetDutyCycleValues(Icu_ChannelType Channel,
 *                                          Icu_DutyCycleType* DutyCycleValues)
 *
 * Service ID[hex]    : 0x11
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : DutyCycleValues - pointer to a buffer where the results
 *
 * Return value       : None
 *
 * Description        : This function reads the coherent active time and period
 *                      time for the given ICU Channel.
 * \endverbatim
 * Traceability       : SWSR_ICU_178 SWSR_ICU_179 SWSR_ICU_180 SWSR_ICU_181
 *                      SWSR_ICU_182 SWSR_ICU_183 SWSR_ICU_184 SWSR_ICU_185
 *                      SWSR_ICU_186 SWSR_ICU_187 SWSR_ICU_038
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues);
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */

#if (STD_ON == ICU_GET_TIMEELAPSED_API)
/** *****************************************************************************************************
 * \brief Service for reading the coherent signal time of given channel.
 *
 * \verbatim
 * Syntax             : Icu_ValueType Icu_GetTimeElapsed(
 *                                                  Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x11
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The signal time value in sigmaesurement mode
 *
 * Description        : This function reads the elapsed Signal Time for the
 *                      given channel
 * \endverbatim
 * Traceability       : SWSR_ICU_166 SWSR_ICU_167 SWSR_ICU_168 SWSR_ICU_169
 *                      SWSR_ICU_170 SWSR_ICU_171 SWSR_ICU_172 SWSR_ICU_173
 *                      SWSR_ICU_174 SWSR_ICU_175 SWSR_ICU_176 SWSR_ICU_177
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel);
#endif /* STD_ON == ICU_GET_TIMEELAPSED_API */
#endif /* STD_ON == ICU_SIGNALMEASUREMENT_API */

#if (STD_ON == ICU_GET_VERSIONINFO_API)
/** *****************************************************************************************************
 * \brief Service returns the version information of this module.
 *
 * \verbatim
 * Syntax             : void Icu_GetVersionInfo(
 *                                          Std_VersionInfoType* versioninfo)
 *
 * Service ID[hex]    : 0x12
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : versioninfo - Pointer to where to store the version
 *                                    information
 *
 * Return value       : None
 *
 * Description        : This function returns the version information of this
 *                      module
 * \endverbatim
 * Traceability       : SWSR_ICU_188 SWSR_ICU_189
 *                      SW_SM006
 *******************************************************************************************************/
void Icu_GetVersionInfo(Std_VersionInfoType* versioninfo);
#endif /* STD_ON == ICU_GET_VERSIONINFO_API */

/** \cond private irq handler function */
/*********************Semidrive customised function ***************************/

/** *****************************************************************************************************
 * \brief Common entry of interrupt handler.
 *
 * \verbatim
 * Syntax             : void Icu_IrqCommon(Icu_HwModule tmrModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module uint
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Common entry of interrupt handler
 * \endverbatim
 * Traceability       : SWSR_ICU_036 SWSR_ICU_190 SWSR_ICU_202
 *                      SW_SM001 SW_SM003 SW_SM004
 *******************************************************************************************************/
void Icu_IrqCommon(Icu_HwModule tmrModule);
/** \endcond */

/** \} */
/* end of MCAL_ICU_API ICU Api. */

#ifdef __cplusplus
}
#endif

/** \} */
/* end of MCAL_ICU ICU Driver */

#endif /* ICU_H */
/* End of file */
