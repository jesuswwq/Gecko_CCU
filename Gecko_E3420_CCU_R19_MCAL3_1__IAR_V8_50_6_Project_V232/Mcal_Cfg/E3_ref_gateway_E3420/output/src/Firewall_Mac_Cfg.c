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
 * \file     Firewall_Mac_Cfg.c                                                                         *
 * \brief    This file contains configuration source for Firewall MAC MCAL driver                       *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:01      <td>1.0.0 R                                                         *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#include "Firewall_Mac_Cfg.h"
#include "Firewall_Cfg.h"
#include "Platform_Types.h"
#include "Compiler.h"

#define FIREWALL_START_SEC_CONST_UNSPECIFIED
#include "Firewall_MemMap.h"

/********************************************************************************************************
 *                                  Private Constant Definitions                                        *
 *******************************************************************************************************/
/** \brief The masters assigned to UNLOCK domain. */
static const uint8 domain_unlock_set[] = {FIREWALL_MASTER_ID_GAMA,FIREWALL_MASTER_ID_ENET_FLEXRAY,FIREWALL_MASTER_ID_SEIP,FIREWALL_MASTER_ID_PTB_XSPISLV,FIREWALL_MASTER_MAXNUM};
/** \brief The masters assigned to LOCK domain. */
static const uint8 domain_lock_set[]   = {FIREWALL_MASTER_ID_USB,FIREWALL_MASTER_ID_SEHC,FIREWALL_MASTER_ID_CSI,FIREWALL_MASTER_ID_DC,FIREWALL_MASTER_ID_G2D,FIREWALL_MASTER_MAXNUM};
/** \brief The masters assigned to SP0 domain. */
static const uint8 domain_sp0_set[]    = {FIREWALL_MASTER_ID_CORE_SP0,FIREWALL_MASTER_ID_CORE_SP1,FIREWALL_MASTER_MAXNUM};
/** \brief The masters assigned to SP1 domain. */
static const uint8 domain_sp1_set[]    = {FIREWALL_MASTER_MAXNUM};
/** \brief The masters assigned to SX0 domain. */
static const uint8 domain_sx0_set[]    = {FIREWALL_MASTER_ID_CORE_SX0,FIREWALL_MASTER_ID_CORE_SX1,FIREWALL_MASTER_MAXNUM};
/** \brief The masters assigned to SX1 domain. */
static const uint8 domain_sx1_set[]    = {FIREWALL_MASTER_MAXNUM};
/** \brief The masters assigned to SF domain. */
static const uint8 domain_sf_set[]     = {FIREWALL_MASTER_MAXNUM};
/** \brief The masters assigned to DMA domain. */
static const uint8 domain_dma_set[]    = {FIREWALL_MASTER_ID_DMA_SF, FIREWALL_MASTER_MAXNUM};

/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
/*PRQA S 1531 4*/
/** \brief The configuration of the firewall mac module.
 * Traceability: SWSR_FIREWALL_004 SWSR_FIREWALL_005
 */
const Firewall_MacConfigType Firewall_MacDomainMasterMap[FIREWALL_DOMAIN_MAXNUM] =
{
    domain_unlock_set, domain_lock_set, domain_sp0_set, domain_sp1_set, domain_sx0_set, domain_sx1_set, domain_dma_set, domain_sf_set
};

#define FIREWALL_STOP_SEC_CONST_UNSPECIFIED
#include "Firewall_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
