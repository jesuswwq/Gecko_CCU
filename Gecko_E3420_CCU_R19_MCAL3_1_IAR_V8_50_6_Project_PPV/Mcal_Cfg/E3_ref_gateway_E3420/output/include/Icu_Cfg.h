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
 *  \file     Icu_Cfg.h                                                                                 *
 *  \brief    This file contains interface header for ICU MCAL config.                                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:00      <td>1.0.0 R                                            *
 * </table>                                                                                             *
 *******************************************************************************************************/




#ifndef ICU_CFG_H
#define ICU_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Icu_Types.h"
/**
 *  \addtogroup MCAL_ICU_MACRO ICU macro.
 *  \{
 */


 /**
 *  \name ICU software version macro
 *
 *  Pre-compile switches for enabling/disabling ICU MCAL config
 *  \{
 */

/* autosar version information */
/** \brief  ICU driver autosar major version */
#define ICU_AR_RELEASE_MAJOR_VERSION      (0x04U)
/** \brief  ICU driver autosar minor version */
#define ICU_AR_RELEASE_MINOR_VERSION      (0x03U)
/** \brief  ICU driver autosar revision version */
#define ICU_AR_RELEASE_REVISION_VERSION   (0x01U)
/* semidrive driver information */
/** \brief  ICU driver vendor major version */
#define ICU_SW_MAJOR_VERSION              (0x03U)
/** \brief  ICU driver vendor minor version */
#define ICU_SW_MINOR_VERSION              (0x01U)
/** \brief  ICU driver vendor patch version */
#define ICU_SW_PATCH_VERSION              (0x00U)
/** \} */
/* end of ICU software version macro */

 /**
 *  \name ICU service enable/diable macro
 *
 *  Pre-compile switches for enabling/disabling ICU MCAL config
 *  \{
 */

/** \brief Enable/disable ICU det_error report */
#define ICU_DEV_ERROR_DETECT (STD_ON)
/** \brief Enable/disable ICU safety_error report */
#define ICU_SAFETY_ENABLE   (STD_ON)
/** \brief Enable/disable ICU dma mode */
#define ICU_DMA_SUPPORT (STD_ON)
/** \brief Enable/disable ICU cache maintain */
#define ICU_NON_CACHE_NEEDED (STD_OFF)
/** \brief Enable/disable ICU multi capture mode */
#define ICU_MULTI_CAPTURE_SUPPORT (STD_ON)
/** \brief Enable/disable ICU multi capture mode with dma */
#define ICU_MULTI_CAPTURE_DMA_MODE (STD_ON)
/** \brief Enable/disable ICU get version info API */
#define ICU_GET_VERSIONINFO_API (STD_OFF)
/** \brief Enable/disable ICU deinit API */
#define ICU_DEINIT_API (STD_ON)
/** \brief Enable/disable ICU edge counter mode API */
#define ICU_EDGE_COUNT_API (STD_ON)
/** \brief Enable/disable ICU edge detection mode API */
#define ICU_EDGE_DETECT_API (STD_ON)
/** \brief Enable/disable ICU get input status API */
#define ICU_GET_INPUTSTATE_API (STD_ON)
/** \brief Enable/disable ICU signal measurement mode API */
#define ICU_SIGNALMEASUREMENT_API (STD_ON)
/** \brief Enable/disable ICU signal time API */
#define ICU_GET_TIMEELAPSED_API (STD_ON)
/** \brief Enable/disable ICU dutycycle value API */
#define ICU_GET_DUTYCYCLE_VALUES_API (STD_ON)
/** \brief Enable/disable ICU timestamp mode API */
#define ICU_TIMESTAMP_API (STD_ON)





/** \brief Burst transfer data length in single capture mode with dma */
#define ICU_RX_BURST_LEN    (256U)
/** \brief Dma watermark level in single capture mode with dma */
#define ICU_RX_FIFO_WML    (8U)

/** \brief Burst transfer data length in multi capture mode with dma */
#define MULTI_CPT_BURST_LEN     (256U)



/** \brief Icu Pre Compile Switch */

#define ICU_PRECOMPILE_SUPPORT (STD_OFF)

/** \brief icu total channel number */
#define NUM_OF_CHANNEL   (5U)

/** \} */
/* end of ICU service enable/diable macro */

/** \brief Shorter Symbolic name for ICU single capture channel : IcuChannel_0 */
#define IcuConf_IcuChannel_IcuChannel_0 (0U)
/** \brief Shorter Symbolic name for ICU single capture channel : IcuChannel_1 */
#define IcuConf_IcuChannel_IcuChannel_1 (1U)
/** \brief Shorter Symbolic name for ICU single capture channel : IcuChannel_2 */
#define IcuConf_IcuChannel_IcuChannel_2 (2U)
/** \brief Shorter Symbolic name for ICU single capture channel : IcuChannel_3 */
#define IcuConf_IcuChannel_IcuChannel_3 (3U)
/** \brief Shorter Symbolic name for ICU multi capture channel : MultiCpt_IcuChannel_4 */
#define IcuConf_IcuChannel_IcuChannel_4_MultiCpt_0 (0 << 8 | 4U)
/** \brief Shorter Symbolic name for ICU multi capture channel : MultiCpt_IcuChannel_4 */
#define IcuConf_IcuChannel_IcuChannel_4_MultiCpt_1 (1 << 8 | 4U)
/** \brief Shorter Symbolic name for ICU multi capture channel : MultiCpt_IcuChannel_4 */
#define IcuConf_IcuChannel_IcuChannel_4_MultiCpt_2 (2 << 8 | 4U)
/** \brief Shorter Symbolic name for ICU multi capture channel : MultiCpt_IcuChannel_4 */
#define IcuConf_IcuChannel_IcuChannel_4_MultiCpt_3 (3 << 8 | 4U)
/** \brief Shorter Symbolic name for ICU multi capture channel : MultiCpt_IcuChannel_4 */
#define IcuConf_IcuChannel_IcuChannel_4_MultiCpt_4 (4 << 8 | 4U)
/** \brief Shorter Symbolic name for ICU multi capture channel : MultiCpt_IcuChannel_4 */
#define IcuConf_IcuChannel_IcuChannel_4_MultiCpt_5 (5 << 8 | 4U)
/** \brief Shorter Symbolic name for ICU multi capture channel : MultiCpt_IcuChannel_4 */
#define IcuConf_IcuChannel_IcuChannel_4_MultiCpt_6 (6 << 8 | 4U)
/** \brief Shorter Symbolic name for ICU multi capture channel : MultiCpt_IcuChannel_4 */
#define IcuConf_IcuChannel_IcuChannel_4_MultiCpt_7 (7 << 8 | 4U)
/** \brief Shorter Symbolic name for ICU multi capture channel : MultiCpt_IcuChannel_4 */
#define IcuConf_IcuChannel_IcuChannel_4_MultiCpt_8 (8 << 8 | 4U)
/** \brief Shorter Symbolic name for ICU multi capture channel : MultiCpt_IcuChannel_4 */
#define IcuConf_IcuChannel_IcuChannel_4_MultiCpt_9 (9 << 8 | 4U)
/** \brief Shorter Symbolic name for ICU multi capture channel : MultiCpt_IcuChannel_4 */
#define IcuConf_IcuChannel_IcuChannel_4_MultiCpt_10 (10 << 8 | 4U)
/** \brief Shorter Symbolic name for ICU multi capture channel : MultiCpt_IcuChannel_4 */
#define IcuConf_IcuChannel_IcuChannel_4_MultiCpt_11 (11 << 8 | 4U)

/** \} */
/* end of MCAL_ICU_MACRO ICU macro. */



/** \brief  ICU channel config */
extern const Icu_ConfigType Icu_ConfigSet;

#ifdef __cplusplus
}
#endif

#endif /*ICU_CFG_H*/
/* End of file */
