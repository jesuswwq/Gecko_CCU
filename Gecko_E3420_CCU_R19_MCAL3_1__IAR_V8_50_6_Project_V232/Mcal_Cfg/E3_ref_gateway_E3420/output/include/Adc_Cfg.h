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
 *  \file     Adc_Cfg.h                                                                                 *
 *  \brief    This file contains configuration for ADC MCAL driver                                      *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/30     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef ADC_CFG_H
#define ADC_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/*****************************************************************************************
 *                       Include header files
 *****************************************************************************************/
#include "Adc_Types.h"

extern const Adc_ConfigType Adc_Config;
/*----------------------[version identification]-----------------------------*/
/** \brief  Generate Autosar Specific Version Information. */
#define ADC_AR_RELEASE_MAJOR_VERSION                                    (4U)
#define ADC_AR_RELEASE_MINOR_VERSION                                    (3U)
#define ADC_AR_RELEASE_REVISION_VERSION                                 (1U)

/** \brief  Generate Vendor Specific Version Information. */
#define ADC_SW_MAJOR_VERSION                                            (3U)
#define ADC_SW_MINOR_VERSION                                            (1U)
#define ADC_SW_PATCH_VERSION                                            (0U)



/*
Configuration:
- if STD_ON, DET is Enabled
- if STD_OFF,DET is Disabled
*/
#define ADC_PRECOMPILE_SUPPORT                  (STD_OFF)

/** \brief  Define if global variables need to be placed in non-cache area or not */
#define ADC_NO_CACHEABLE_NEEDED                 (STD_OFF)

#define ADC_VOLTAGE_CALIBRATION                 (STD_OFF)

/** Traceability       : SWSR_ADC_195 */
#define ADC_OVERVOLTAGE_DETECT                  (STD_OFF)

#define ADC_DEV_ERROR_DETECT                    (STD_ON)

#define ADC_SAFETY_ENABLE                       (STD_OFF)

/** Traceability       : SWSR_ADC_070 */
#define ADC_DEINIT_API                          (STD_ON)

/** Traceability       : SWSR_ADC_007 SWSR_ADC_077
 *                       SWSR_ADC_091               */
#define ADC_ENABLE_START_STOP_GROUP_API         (STD_ON)

/** Traceability       : SWSR_ADC_106 SWSR_ADC_112 */
#define ADC_GRP_NOTIF_CAPABILITY                (STD_ON)

/** Traceability       : SWSR_ADC_008 SWSR_ADC_171
 *                       SWSR_ADC_184 */
#define ADC_HW_TRIGGER_API                      (STD_ON)
/** Traceability       : SWSR_ADC_022 SWSR_ADC_023 */
#define ADC_POWER_STATE_SUPPORTED               (STD_ON)

#define ADC_READ_GROUP_API                      (STD_ON)

/** Traceability       : SWSR_ADC_193 */
#define ADC_DMA_SUPPORTED                       (STD_OFF)

#define ADC_VERSION_INFO_API                    (STD_OFF)

#define ADC_USED_MAX_GROUP_CHNL_COUNT (10U)

#define ADC_USED_GROUP_COUNT (3U)

#define ADC_USED_UNIT_COUNT (1U)

/*------------------[Symbolic Names of Hardware Units]-----------------------*/
#define ADCCONF_ADCHWUNIT_ADC2 (0U)

/*------------------[Symbolic Names of Groups]-----------------------*/
/** Traceability       : SWSR_ADC_165 */
#define ADCCONF_ADCGROUP_ADC2GROUP_0 (0U)
#define ADCCONF_ADCGROUP_ADC2GROUP_1 (1U)
#define ADCCONF_ADCGROUP_ADC2GROUP_2 (2U)

/*------------------[Symbolic Names of Channels]-----------------------*/
/** Traceability       : SWSR_ADC_165 */
#define ADCCONF_ADCCHANNEL_ADC_EXP_A_GPIO_B14 (0U)
#define ADCCONF_ADCCHANNEL_ADC_EXP_D_GPIO_B15 (3U)
#define ADCCONF_ADCCHANNEL_IN_IAN23_A6 (5U)
#define ADCCONF_ADCCHANNEL_IN_IAN24_C10 (6U)
#define ADCCONF_ADCCHANNEL_IN_IAN9_B7 (7U)
#define ADCCONF_ADCCHANNEL_IN_IAN25_A4 (8U)
#define ADCCONF_ADCCHANNEL_IN_IAN35_B8 (9U)
#define ADCCONF_ADCCHANNEL_IN_IAN41_C9 (10U)
#define ADCCONF_ADCCHANNEL_IN_IAN43_C5 (11U)
#define ADCCONF_ADCCHANNEL_IN_IAN45_B9 (12U)
#define ADCCONF_ADCCHANNEL_IN_IAN46_C8 (13U)
#define ADCCONF_ADCCHANNEL_IN_IAN47_C4 (14U)
#define ADCCONF_ADCCHANNEL_IN_IAN48_C1 (15U)
#define ADCCONF_ADCCHANNEL_IN_IAN49_C0 (16U)
#define ADCCONF_ADCCHANNEL_IN_IAN44_C11 (17U)
#define ADCCONF_ADCCHANNEL_ADC_EXP_B_GPIO_A14 (1U)
#define ADCCONF_ADCCHANNEL_ADC_EXP_C_GPIO_A5 (2U)
#define ADCCONF_ADCCHANNEL_ADC_EXP_E_GPIO_B6 (4U)

#define ADC_OVERVOLTAGE_THRESHOLD 3500U


#ifdef __cplusplus
}
#endif
#endif /* ADC_CFG_H */
/* End of file */

