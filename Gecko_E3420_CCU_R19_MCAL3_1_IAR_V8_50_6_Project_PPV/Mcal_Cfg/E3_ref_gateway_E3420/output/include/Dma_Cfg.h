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
 *  \file     Dma_Cfg.h                                                                                 *
 *  \brief    This file contains generated pre compile configuration file for                           *
 *            DMA MCAL driver                                                                           *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:00  <td>3.0.0 R                                                             *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef DMA_CFG_H
#define DMA_CFG_H

#ifdef __cplusplus
extern "C" {
#endif
/** Traceability       : SWSR_DMA_045 */
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/**
 *  \defgroup MCAL_DMA_MACRO Dma Macro.
 *
 * This files defines DMA MCAL macros.
 *  @{
 */

 /**
 *  \name Dma Module generation version.
 *
 *  @{
 */
/** \brief  Generate Autosar Specific Version Information. */
#define DMA_AR_RELEASE_MAJOR_VERSION                                    (4U)
#define DMA_AR_RELEASE_MINOR_VERSION                                    (3U)
#define DMA_AR_RELEASE_REVISION_VERSION                                 (1U)

/** \brief  Generate Vendor Specific Version Information. */
#define DMA_SW_MAJOR_VERSION                                            (3U)
#define DMA_SW_MINOR_VERSION                                            (1U)
#define DMA_SW_PATCH_VERSION                                            (0U)
/** @} */

/**
 *  \name Dma Module generation configuration info.
 *
 *  @{
 */
/** \brief  Enable/Disable dma lockstep mode */
/** Traceability       : SWSR_DMA_013 SW_SM008 */
#define DMA_LOCK_STEP_MODE                                              (STD_OFF)

/** \brief  Derived Configuration for DmaDevErrorDetect */
#define DMA_DEV_ERROR_DETECT                                            (STD_ON)

/** \brief  Derived Configuration for DmaSafetyEnable */
#define DMA_SAFETY_ENABLE                                               (STD_ON)

/** \brief  Define if global variables need to be placed in non-cache area or not */
#define DMA_NO_CACHEABLE_NEEDED                                         (STD_OFF)

/** \brief  Whether dma channel(s) is assigned to core0  */
#define DMA_CORE0_ENABLE                                                (STD_ON)

/** \brief  Whether dma channel(s) is assigned to core1  */
#define DMA_CORE1_ENABLE                                                (STD_ON)

/** \brief  Whether dma channel(s) is assigned to core2  */
#define DMA_CORE2_ENABLE                                                (STD_OFF)

/** \brief  Whether dma channel(s) is assigned to core3  */
#define DMA_CORE3_ENABLE                                                (STD_OFF)

/** \brief  Whether dma channel(s) is assigned to core4  */
#define DMA_CORE4_ENABLE                                                (STD_OFF)


/** \brief  Configuration: DMA_GETVERSIONINFO_API Version Information API configuration */
#define DMA_GETVERSIONINFO_API                                          (STD_OFF)

/** \brief  Configuration: DMA_UPDATE_CONFIG_API Dma_UpdateTransmitAddressAndLength API configuration */
#define DMA_UPDATE_CONFIG_API                                           (STD_OFF)

/** \brief  Configuration: DMA_CONFIG_CHECK_API Dma_ConfigurationCheck API configuration */
#define DMA_CONFIG_CHECK_API                                            (STD_OFF)

/** \brief  Dma link list buffer maximum length on core0 */
#define DMA_LINK_LIST_LENGTH_CORE0                                      (32U)

/** \brief  Dma link list buffer maximum length on core1 */
#define DMA_LINK_LIST_LENGTH_CORE1                                      (5U)

/** \brief  Dma link list buffer maximum length on core2 */
#define DMA_LINK_LIST_LENGTH_CORE2                                      (5U)

/** \brief  Dma link list buffer maximum length on core3 */
#define DMA_LINK_LIST_LENGTH_CORE3                                      (5U)

/** \brief  Dma link list buffer maximum length on core4 */
#define DMA_LINK_LIST_LENGTH_CORE4                                      (5U)

/** \brief  Max dma channel number per SF controller */
#define DMA_SF_MAX_CHANNEL_NUMBER                                       (24U)

/** \brief  Total number of SF0 channels allocated on core CORE0 */
#define DMA_CHANNEL_SF0_ON_CORE0_NUMBER                                 (8U)

/** \brief  Total number of SF1 channels allocated on core CORE0 */
#define DMA_CHANNEL_SF1_ON_CORE0_NUMBER                                 (0U)

/** \brief  Total number of SF0 channels allocated on core CORE1 */
#define DMA_CHANNEL_SF0_ON_CORE1_NUMBER                                 (1U)

/** \brief  Total number of SF1 channels allocated on core CORE1 */
#define DMA_CHANNEL_SF1_ON_CORE1_NUMBER                                 (0U)

/** \brief  Total number of SF0 channels allocated on core CORE2 */
#define DMA_CHANNEL_SF0_ON_CORE2_NUMBER                                 (0U)

/** \brief  Total number of SF1 channels allocated on core CORE2 */
#define DMA_CHANNEL_SF1_ON_CORE2_NUMBER                                 (0U)

/** \brief  Total number of SF0 channels allocated on core CORE3 */
#define DMA_CHANNEL_SF0_ON_CORE3_NUMBER                                 (0U)

/** \brief  Total number of SF1 channels allocated on core CORE3 */
#define DMA_CHANNEL_SF1_ON_CORE3_NUMBER                                 (0U)

/** \brief  Total number of SF0 channels allocated on core CORE4 */
#define DMA_CHANNEL_SF0_ON_CORE4_NUMBER                                 (0U)

/** \brief  Total number of SF1 channels allocated on core CORE4 */
#define DMA_CHANNEL_SF1_ON_CORE4_NUMBER                                 (0U)

/** @} */

#ifdef __cplusplus
}
#endif
#endif /* #ifndef DMA_CFG_H */
/** @} */
/* End of file */
