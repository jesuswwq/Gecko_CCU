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
 *  \file     Gpt_Cfg.h                                                                                 *
 *  \brief    This file contains interface header for GPT MCAL config.                                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:00      <td>1.0.0 R                                            *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef GPT_CFG_H
#define GPT_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Gpt_Types.h"

/**
 *  \addtogroup MCAL_GPT_MACRO GPT macro.
 *  \{
 */
 /**
 *  \name GPT software version macro
 *  \{
 */
/* autosar version information */
/** \brief  GPT driver autosar major version */
#define GPT_AR_RELEASE_MAJOR_VERSION      (0x04U)
/** \brief  GPT driver autosar minor version */
#define GPT_AR_RELEASE_MINOR_VERSION      (0x03U)
/** \brief  GPT driver autosar revision version */
#define GPT_AR_RELEASE_REVISION_VERSION   (0x01U)
/* semidrive driver information */
/** \brief  GPT driver vendor major version */
#define GPT_SW_MAJOR_VERSION              (0x03U)
/** \brief  GPT driver vendor minor version */
#define GPT_SW_MINOR_VERSION              (0x01U)
/** \brief  GPT driver vendor patch version */
#define GPT_SW_PATCH_VERSION              (0x00U)
/** \} */

 /**
 *  \name GPT service enable/diable defines
 *
 *  Pre-compile switches for enabling/disabling GPT MCAL config
 *  \{
 */
/** \brief Enable/disable GPT get version info API */
#define GPT_VERSION_INFO_API (STD_ON)
/** \brief Enable/disable GPT dev detect error */
#define GPT_DEV_ERROR_DETECT (STD_ON)
/** \brief Enable/disable GPT dev safety error */
#define GPT_SAFETY_ENABLE (STD_ON)
/** \brief Enable/disable GPT predef timer API */
#define GPT_PREDEFTIMER_FUNCTIONALITY_API (STD_ON)
/** \brief Enable/disable GPT get time elapsed API */
/**
 * Traceability       : SWSR_GPT_036
 */
#define GPT_TIME_ELAPSED_API (STD_ON)
/** \brief Enable/disable GPT time remaining API */
/**
 * Traceability       : SWSR_GPT_044
 */
#define GPT_TIME_REMAINING_API (STD_ON)
/** \brief Enable/disable GPT enable/disable GPT API */
/**
 * Traceability       : SWSR_GPT_066 SWSR_GPT_072
 */
#define GPT_ENABLE_DISABLE_NOTIFICATION_API (STD_ON)
/** \brief Enable/disable GPT deinit API */
/**
 * Traceability       : SWSR_GPT_028
 */
#define GPT_DEINIT_API (STD_ON)
/* Gpt Pre Compile Switch */

#define GPT_PRECOMPILE_SUPPORT (STD_OFF)

/** \} */

/** \brief GPT channel number */
#define GPT_HW_CHANNEL_NUM   (9U)

/** \brief GPT bus clock */
#define GPT_BUS_CLK 150000000UL

/** \brief GPT max core number */
#define GPT_MAX_CORE_NUM  3U

/** \brief GPT core0 enable/disable */
#define GPT_CORE0_ENABLE STD_ON
/** \brief GPT core1 enable/disable */
#define GPT_CORE1_ENABLE STD_OFF
/** \brief GPT core2 enable/disable */
#define GPT_CORE2_ENABLE STD_OFF
/** \brief GPT core3 enable/disable */
#define GPT_CORE3_ENABLE STD_OFF
/** \brief GPT core4 enable/disable */
#define GPT_CORE4_ENABLE STD_OFF

/** \brief Shorter Symbolic name for GPT channel #0 GptChannelConfiguratiuuuu0 */
#define GptConf_GptChannelConfiguration_GptChannelConfiguratiuuuu0 (0)
/** \brief Shorter Symbolic name for GPT channel #1 GptChannelConfiguration_1 */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_1 (1)
/** \brief Shorter Symbolic name for GPT channel #2 GptChannelConfiguration_2 */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_2 (2)
/** \brief Shorter Symbolic name for GPT channel #3 GptChannelConfiguration_3 */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_3 (3)
/** \brief Shorter Symbolic name for GPT channel #4 GptChannelConfiguration_0 */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_0 (4)
/** \brief Shorter Symbolic name for GPT channel #5 GptChannelConfiguration_4 */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_4 (5)
/** \brief Shorter Symbolic name for GPT channel #6 GptChannelConfiguration_5 */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_5 (6)
/** \brief Shorter Symbolic name for GPT channel #7 GptChannelConfiguration_6 */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_6 (7)
/** \brief Shorter Symbolic name for GPT channel #8 GptChannelConfiguration_7 */
#define GptConf_GptChannelConfiguration_GptChannelConfiguration_7 (8)
/** \} */

/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
/** \brief  GPT config generate */
extern const Gpt_ConfigType  GptChannelConfigSet;

#ifdef __cplusplus
}
#endif

#endif /*GPT_CFG_H*/

/* End of file */
