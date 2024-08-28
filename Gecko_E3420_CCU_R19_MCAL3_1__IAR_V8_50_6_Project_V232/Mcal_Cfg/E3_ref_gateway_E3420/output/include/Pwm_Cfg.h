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
 *  \file     Pwm_Cfg.h                                                                                 *
 *  \brief    This file contains generated pre compile configuration file for                           *
 *            PWM MCAL driver                                                                           *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:00  <td>1.0.0 R                                                             *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef PWM_CFG_H
#define PWM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Pwm_Type.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/**
 *  \addtogroup MCAL_PWM_MACRO PWM macro
 *  \{
 */

/**
 *  \name PWM software version macro
 *  \{
 */
/* Autosar version information */
/** \brief  PWM driver autosar major version */
#define PWM_AR_RELEASE_MAJOR_VERSION                                    (4U)
/** \brief  PWM driver autosar minor version */
#define PWM_AR_RELEASE_MINOR_VERSION                                    (3U)
/** \brief  PWM driver autosar revision version */
#define PWM_AR_RELEASE_REVISION_VERSION                                 (1U)
/* Semidrive driver information */
/** \brief  PWM driver vendor major version */
#define PWM_SW_MAJOR_VERSION                                            (3U)
/** \brief  PWM driver vendor minor version */
#define PWM_SW_MINOR_VERSION                                            (1U)
/** \brief  PWM driver vendor patch version */
#define PWM_SW_PATCH_VERSION                                            (0U)
/** \} */

/**
 *  \name PWM service enable/diable defines
 *
 *  Pre-compile switches for enabling/disabling PWM MCAL APIs
 *  \{
 */
/** \brief  PWM Build Variant.. */
#define PWM_PRECOMPILE_SUPPORT          (STD_OFF)

/** \brief  Derived Configuration for PwmDevErrorDetect */
#define PWM_DEV_ERROR_DETECT            (STD_ON)

/** \brief  Derived Configuration for PwmSafetyEnable */
#define PWM_SAFETY_ENABLE               (STD_OFF)

/** \brief  Derived Configuration for PwmNonCacheableNeeded */
#define PWM_NO_CACHEABLE_NEEDED         (STD_OFF)

/** \brief  Derived Configuration for PwmDeInitApi */
#define PWM_DE_INIT_API                 (STD_ON)

/** \brief  Derived Configuration for PwmSetPeriodAndDuty */
#define PWM_SET_DUTY_CYCLE_API          (STD_ON)

/** \brief  Derived Configuration for PwmSetPeriodAndDuty */
#define PWM_SET_PERIOD_AND_DUTY_API     (STD_ON)

/** \brief  Derived Configuration for PwmSetOutputToIdle */
#define PWM_SET_OUTPUT_TO_IDLE_API      (STD_ON)

/** \brief  Derived Configuration for PwmNotificationSupported */
#define PWM_NOTIFICATION_SUPPORTED      (STD_ON)

/** \brief  Derived Configuration for PwmDmaTxSupported */
#define PWM_DMA_SUPPORTED               (STD_ON)

/** \brief  Derived Configuration for PwmGetOutputState */
#define PWM_GET_OUTPUT_STATE_API        (STD_ON)

/** \brief  Configuration: PWM_VERSION_INFO_API Version Information API configuration */
#define PWM_VERSION_INFO_API            (STD_OFF)
/** \} */

/**
 *  \name PWM controller(s) assigned core
 *  \{
 */
/** \brief  Whether PWM controller(s) is assigned to core0  */
#define PWM_CFG_ENABLE_CORE0            (STD_ON)
/** \brief  Whether PWM controller(s) is assigned to core1  */
#define PWM_CFG_ENABLE_CORE1            (STD_OFF)
/** \brief  Whether PWM controller(s) is assigned to core2  */
#define PWM_CFG_ENABLE_CORE2            (STD_OFF)
/** \brief  Whether PWM controller(s) is assigned to core3  */
#define PWM_CFG_ENABLE_CORE3            (STD_OFF)
/** \brief  Whether PWM controller(s) is assigned to core4  */
#define PWM_CFG_ENABLE_CORE4            (STD_OFF)
/** \} */

/**
 *  \name PWM channels
 *  \{
 */
/** \brief  HwModule EPWM1 channel_0 [X0]*/
#define  PWM_CONFIG_CHANNEL_EPWM1_CHANNELA0     ((Pwm_ChannelType)1U)
/** \brief  HwModule EPWM1 channel_1 [X0]*/
#define  PWM_CONFIG_CHANNEL_EPWM1_CHANNELB0     ((Pwm_ChannelType)2U)
/** \brief  HwModule EPWM1 channel_1 [X1] */
#define  PWM_CONFIG_CHANNEL_PwmChannel_7E100B_IN0     ((Pwm_ChannelType)3U)
/** \brief  HwModule EPWM1 channel_2 [X0]*/
#define  PWM_CONFIG_CHANNEL_PwmChannel_7020_A_IN0     ((Pwm_ChannelType)4U)
/** \brief  HwModule EPWM1 channel_2 [X1] */
#define  PWM_CONFIG_CHANNEL_PwmChannel_7020_A_IN1     ((Pwm_ChannelType)5U)
/** \brief  HwModule EPWM1 channel_3 [X0]*/
#define  PWM_CONFIG_CHANNEL_PwmChannel_7020_B_IN0     ((Pwm_ChannelType)6U)
/** \brief  HwModule EPWM1 channel_3 [X1] */
#define  PWM_CONFIG_CHANNEL_PwmChannel_7020_B_IN1     ((Pwm_ChannelType)7U)
/** \brief  HwModule EPWM2 channel_0 [X0]*/
#define  PWM_CONFIG_CHANNEL_EPWM2_CHANNELA0     ((Pwm_ChannelType)8U)
/** \brief  HwModule EPWM2 channel_1 [X0]*/
#define  PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_A_IN0     ((Pwm_ChannelType)9U)
/** \brief  HwModule EPWM2 channel_1 [X1] */
#define  PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_A_IN1     ((Pwm_ChannelType)10U)
/** \brief  HwModule EPWM2 channel_2 [X0]*/
#define  PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_B_IN0     ((Pwm_ChannelType)11U)
/** \brief  HwModule EPWM2 channel_3 [X0]*/
#define  PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_B_IN1     ((Pwm_ChannelType)12U)
/** \brief  HwModule EPWM3 channel_1 [X0]*/
#define  PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_C_IN0     ((Pwm_ChannelType)14U)
/** \brief  HwModule EPWM3 channel_1 [X1] */
#define  PWM_CONFIG_CHANNEL_PwmChannel_BTS7012_C_IN1     ((Pwm_ChannelType)15U)
/** \brief  HwModule EPWM3 channel_2 [X0]*/
#define  PWM_CONFIG_CHANNEL_PwmChannel_7120_B_IN1     ((Pwm_ChannelType)16U)
/** \brief  HwModule EPWM3 channel_2 [X1] */
#define  PWM_CONFIG_CHANNEL_PwmChannel_7120_B_IN0     ((Pwm_ChannelType)17U)
/** \brief  HwModule EPWM3 channel_3 [X0]*/
#define  PWM_CONFIG_CHANNEL_PwmChannel_7120_D_IN0     ((Pwm_ChannelType)18U)
/** \brief  HwModule EPWM3 channel_3 [X1] */
#define  PWM_CONFIG_CHANNEL_PwmChannel_7120_D_IN1     ((Pwm_ChannelType)19U)
/** \brief  HwModule EPWM4 channel_1 [X0]*/
#define  PWM_CONFIG_CHANNEL_PwmChannel_75242_A_IN0     ((Pwm_ChannelType)21U)
/** \brief  HwModule EPWM4 channel_1 [X1] */
#define  PWM_CONFIG_CHANNEL_PwmChannel_75242_A_IN1     ((Pwm_ChannelType)22U)
/** \brief  HwModule EPWM4 channel_2 [X0]*/
#define  PWM_CONFIG_CHANNEL_PwmChannel_8108_IN1     ((Pwm_ChannelType)23U)
/** \brief  HwModule EPWM4 channel_2 [X1] */
#define  PWM_CONFIG_CHANNEL_PwmChannel_8108_IN2     ((Pwm_ChannelType)24U)
/** \brief  HwModule EPWM4 channel_3 [X0]*/
#define  PWM_CONFIG_CHANNEL_PwmChannel_8108_IN3     ((Pwm_ChannelType)25U)
/** \brief  HwModule EPWM4 channel_3 [X1] */
#define  PWM_CONFIG_CHANNEL_PwmChannel_8108_IN4     ((Pwm_ChannelType)26U)

/** \} */

/** \brief  PWM maximal channel number */
#define PWM_MAX_CHANNEL_NUM             ((uint8)26U)

/** \brief  PWM EPWM and ETIMER controller total number */
#define EPWM_AND_ETIMER_MODULE_TOTAL_NUMBER (8U)

/** \brief  PWM maximal core number */
#define PWM_MAX_CORE_NUM                (5U)
/** \} */

/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/

/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
/** \brief  PWM global configure information */
extern const Pwm_ConfigType Pwm_Config;

#ifdef __cplusplus
}
#endif

#endif

