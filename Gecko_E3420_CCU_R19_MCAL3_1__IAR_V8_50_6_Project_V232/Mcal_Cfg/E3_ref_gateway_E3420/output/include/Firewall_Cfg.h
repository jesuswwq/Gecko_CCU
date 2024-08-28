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
 *  \file     Firewall_Cfg.h                                                                            *
 * \brief    This file contains configuration header for Firewall MCAL driver                           *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:01      <td>1.0.0 R                                                         *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef FIREWALL_CFG_H
#define FIREWALL_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Firewall.h"

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \brief  Generate Autosar Specific Version Information. */
#define FIREWALL_AR_RELEASE_MAJOR_VERSION                                    (4U)
#define FIREWALL_AR_RELEASE_MINOR_VERSION                                    (3U)
#define FIREWALL_AR_RELEASE_REVISION_VERSION                                 (1U)

/** \brief  Generate Vendor Specific Version Information. */
#define FIREWALL_SW_MAJOR_VERSION                                            (3U)
#define FIREWALL_SW_MINOR_VERSION                                            (1U)
#define FIREWALL_SW_PATCH_VERSION                                            (0U)

/** \brief Enable/Disable SX0/SX1 lockstep.
 * Traceability: SWSR_FIREWALL_006
 */
#define FIREWALL_SX_LOCKSTEP_ENSTD_ON

/** \brief Enable/Disable SP0/SP1 lockstep.
 * Traceability: SWSR_FIREWALL_006
 */
#define FIREWALL_SP_LOCKSTEP_EN STD_ON

/** \brief Enable/Disable the firewall interrupt.
 * Traceability: SWSR_FIREWALL_017
 */
#define FIREWALL_INTERRUPT_EN STD_ON

/** \brief Enable/Disable the response error to bus when occur illegal access.
 * Traceability: SWSR_FIREWALL_029
 */
#define FIREWALL_RESPONSE_ERROR_EN STD_ON

/** \brief Enable/Disable the system detect the error from firewall driver. */
#define FIREWALL_DEV_ERROR_DETECT STD_ON

/** \brief Enable/Disable the safety system detect the error from firewall driver. */
#define FIREWALL_SAFETY_ENABLE STD_ON


/** \brief The id of the core SF master. */
#define FIREWALL_MASTER_ID_CORE_SF      (0U)
/** \brief The id of the core SP0 master. */
#define FIREWALL_MASTER_ID_CORE_SP0     (1U)
/** \brief The id of the core SP1 master. */
#define FIREWALL_MASTER_ID_CORE_SP1     (2U)
/** \brief The id of the core SX0 master. */
#define FIREWALL_MASTER_ID_CORE_SX0     (3U)
/** \brief The id of the core SX1 master. */
#define FIREWALL_MASTER_ID_CORE_SX1     (4U)
/** \brief The id of the core DMA_SF master. */
#define FIREWALL_MASTER_ID_DMA_SF       (5U)
/** \brief The id of the core GAMA master. */
#define FIREWALL_MASTER_ID_GAMA         (6U)
/** \brief The id of the core ENET and FLEXRAY master. */
#define FIREWALL_MASTER_ID_ENET_FLEXRAY (7U)
/** \brief The id of the core DMA_AP master. */
#define FIREWALL_MASTER_ID_DMA_AP       (8U)
/** \brief The id of the core USB master. */
#define FIREWALL_MASTER_ID_USB          (9U)
/** \brief The id of the core SEHC master. */
#define FIREWALL_MASTER_ID_SEHC         (10U)
/** \brief The id of the core SEIP master. */
#define FIREWALL_MASTER_ID_SEIP         (11U)
/** \brief The id of the core CSI master. */
#define FIREWALL_MASTER_ID_CSI          (12U)
/** \brief The id of the core DC master. */
#define FIREWALL_MASTER_ID_DC           (13U)
/** \brief The id of the core G2D master. */
#define FIREWALL_MASTER_ID_G2D          (14U)
/** \brief The id of the core XSPISLV master. */
#define FIREWALL_MASTER_ID_PTB_XSPISLV  (15U)
/** \brief The maximum number of masters. */
#define FIREWALL_MASTER_MAXNUM          (16U)

/** \brief The id of the SF domain. */
#define FIREWALL_DOMAIN_ID_SF           (0x7U)
/** \brief The id of the SP0 domain. */
#define FIREWALL_DOMAIN_ID_SP0          (0x2U)
/** \brief The id of the SP1 domain. */
#define FIREWALL_DOMAIN_ID_SP1          (0x3U)
/** \brief The id of the SX0 domain. */
#define FIREWALL_DOMAIN_ID_SX0          (0x4U)
/** \brief The id of the SX1 domain. */
#define FIREWALL_DOMAIN_ID_SX1          (0x5U)
/** \brief The id of the UNLOCK domain. */
#define FIREWALL_DOMAIN_ID_UNLOCK       (0x0U)
/** \brief The id of the LOCK domain. */
#define FIREWALL_DOMAIN_ID_LOCK         (0x1U)
/** \brief The id of the DMA domain. */
#define FIREWALL_DOMAIN_ID_DMA          (0x6U)
/** \brief The maximum number of domains. */
#define FIREWALL_DOMAIN_MAXNUM          (0x8U)

/********************************************************************************************************
 *                                  Global Variable Declarations                                        *
 *******************************************************************************************************/
/** \brief The pointer to the firewall interrupt callback function.
 * Traceability: SWSR_FIREWALL_017
 */
extern void (*Firewall_ErrorNotification)(void);

/** \brief The configuration of the firewall module.
 * Traceability: SWSR_FIREWALL_020
 */
extern const Firewall_ConfigType Firewall_Cfg;

#ifdef __cplusplus
}
#endif

#endif /* FIREWALL_CFG_H */
/* End of file */
