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
 *  \file     Adc_ConfigTypes.h                                                                         *
 *  \brief    This file contains adc types which will be influenced by config file                      *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/29     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef ADC_CONFIGTYPES_H
#define ADC_CONFIGTYPES_H

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include <Std_Types.h>
#include "Adc_Types.h"
#include "Adc_Cfg.h"

/**
 *  \addtogroup MCAL_ADC_CFG Adc Configuration.
 *
 * This files defines ADC MCAL configuration structures
 *  \{
 */

/** \brief  Type for power state currently active or set as target
 *          power state.                                                */
/** Traceability    :   SWSR_ADC_049                                    */
typedef enum
{
    ADC_FULL_POWER = 0U,
    ADC_LOW_POWER
} Adc_PowerStateType;

#if (ADC_POWER_STATE_SUPPORTED == STD_ON)
/** \brief  Type for result of power state.                             */
/** Traceability    :   SWSR_ADC_030 SWSR_ADC_050                       */
typedef enum
{
    ADC_SERVICE_ACCEPTED = 0U,
    ADC_NOT_INIT,
    ADC_SEQUENCE_ERROR,
    ADC_POWER_STATE_NOT_SUPP,
    ADC_TRANS_NOT_POSSIBLE
} Adc_PowerStateRequestResultType;

/** \brief  Type for confirming Adc_PrePowerState is beginning of a
 *           Adc Power State transition.                                */
/** Traceability    :   SWSR_ADC_026 SWSR_ADC_027 */
typedef enum
{
    ADC_POWER_CHANGE_NOT_START = 0U,
    ADC_POWER_CHANGE_START,
} Adc_PowerChangeType;

/** \brief  Type for confirming current power state is the same as the
 *          target power state.                                         */
typedef enum
{
    ADC_POWER_SAME = 0U,
    ADC_POWER_DIFF,
} Adc_PowerCheckType;
#endif /* (ADC_POWER_STATE_SUPPORTED == STD_ON) */

/** \brief  Type for recording hardware trigger enabled/disabled.       */
#if(ADC_HW_TRIGGER_API == STD_ON)
typedef enum
{
    ADC_HARDWARE_NO_TRIGGERRING = 0U,
    ADC_HARDWARE_TRIGGERRING
} Adc_HardwareTriggerType;
#endif /* #if(ADC_HW_TRIGGER_API == STD_ON) */

#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
/** \brief Type for indicates if notification is enabled for the group. */
/** Traceability    :   SWSR_ADC_018                                    */
typedef enum
{
    ADC_NOTIFICATION_DISABLED = 0U,
    ADC_NOTIFICATION_ENABLED
} Adc_NotificationType;
#endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */

#if (ADC_OVERVOLTAGE_DETECT == STD_ON)
/** \brief  Type for current detect status of the conversion of the
 *          requested ADC Channel group.                                */
typedef enum
{
    ADC_GROUP_UNDETECTED = 0U,
    ADC_GROUP_DETECTED
} Adc_GroupDetectType;

/** \brief  Type for current detect status of the conversion of the
 *          requested ADC Channel.                                      */
typedef enum
{
    ADC_CHANNE_DET_NORMAL = 0U,
    ADC_CHANNE_DET_ABNORMAL
} Adc_ChannelDetectType;
#endif /* #if (ADC_OVERVOLTAGE_DETECT == STD_ON) */

/** \brief  Type for all group information.                             */
typedef struct
{
    volatile Adc_StatusType groupStatus;
    volatile Adc_GroupBusyType groupConvStatus;
    volatile Adc_GroupValueUpdateType groupValueStatus;
    /** Traceability    :   SWSR_ADC_037 SWSR_ADC_038                       */
    volatile Adc_StreamNumSampleType groupConvFinishTime;
    volatile Adc_StreamNumSampleType groupConvFinishIndex;
#if(ADC_HW_TRIGGER_API == STD_ON)
    volatile Adc_HardwareTriggerType groupHardwareTrigger;
#endif /* #if(ADC_HW_TRIGGER_API == STD_ON) */
#if (ADC_GRP_NOTIF_CAPABILITY == STD_ON)
    /** Traceability    :   SWSR_ADC_157                                    */
    volatile Adc_NotificationType groupNotifStatus;
#endif /* #if (ADC_GRP_NOTIF_CAPABILITY == STD_ON) */
#if (ADC_OVERVOLTAGE_DETECT == STD_ON)
    volatile Adc_GroupDetectType groupDetectStatus;
    volatile Adc_ChannelDetectType channelDetectStatus[ADC_USED_MAX_GROUP_CHNL_COUNT];
#endif /* #if (ADC_OVERVOLTAGE_DETECT == STD_ON) */
} Adc_GroupStatusType;
/** \} */
#ifdef __cplusplus
}
#endif

#endif /* ADC_CONFIGTYPES_H */
/* End of file */
