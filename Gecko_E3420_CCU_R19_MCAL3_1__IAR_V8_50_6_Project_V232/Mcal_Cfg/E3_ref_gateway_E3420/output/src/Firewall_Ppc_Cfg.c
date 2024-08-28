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
 * \file     Firewall_Ppc_Cfg.c                                                                         *
 * \brief    This file contains configuration source for Firewall PPC MCAL driver                       *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:01      <td>1.0.0 R                                                         *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#include "Firewall_Ppc_Cfg.h"

#define FIREWALL_START_SEC_CONST_UNSPECIFIED
#include "Firewall_MemMap.h"

/*PRQA S 1531 4*/
/** \brief The base configuration of the firewall PPC module.
 * Traceability: SWSR_FIREWALL_015
 */
const Firewall_PpcIpConfigType Firewall_PpcBaseIpCfg[FIREWALL_PPC_BASE_IP_NUM] =
{
    {
        /* APB_MUX1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 0U,
        .ppcApbmuxIpId = 0U,
    },
    {
        /* RTC1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 0U,
        .ppcApbmuxIpId = 1U,
    },
    {
        /* RTC2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 0U,
        .ppcApbmuxIpId = 2U,
    },
    {
        /* FS_32K */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 0U,
        .ppcApbmuxIpId = FIREWALL_PERMISSION_NONE,
    },
    {
        /* SIMULARION RESEVED0 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 0U,
        .ppcApbmuxIpId = 4U,
    },
    {
        /* PMU_CORE */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 0U,
        .ppcApbmuxIpId = 6U,
    },
    {
        /* IOMUXC_RTC */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 0U,
        .ppcApbmuxIpId = 7U,
    },
    {
        /* TM */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 0U,
        .ppcApbmuxIpId = 8U,
    },
    {
        /* SEC_STORAGE */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 0U,
        .ppcApbmuxIpId = 10U,
    },
    {
        /* APB_MUX2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 0U,
    },
    {
        /* XTRG */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 1U,
    },
    {
        /* BTM1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 2U,
    },
    {
        /* BTM2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = FIREWALL_PERMISSION_NONE,
    },
    {
        /* BTM3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 4U,
    },
    {
        /* BTM4 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 5U,
    },
    {
        /* BTM5 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 6U,
    },
    {
        /* BTM6 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 7U,
    },
    {
        /* ePWM1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 8U,
    },
    {
        /* ePWM2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 9U,
    },
    {
        /* ePWM3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 10U,
    },
    {
        /* ePWM4 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 11U,
    },
    {
        /* eTMR1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 12U,
    },
    {
        /* eTMR2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 13U,
    },
    {
        /* eTMR3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 14U,
    },
    {
        /* eTMR4 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 15U,
    },
    {
        /* DMA_SF0(APB_S0_A) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 16U,
    },
    {
        /* DMA_SF0(APB_S0_B) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 17U,
    },
    {
        /* DMA_SF0(APB_S0_C) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 18U,
    },
    {
        /* DMA_SF0(APB_S0_D) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 19U,
    },
    {
        /* DMA_SF1(APB_S1_A) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 20U,
    },
    {
        /* DMA_SF1(APB_S1_B) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 21U,
    },
    {
        /* DMA_SF1(APB_S1_C) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 22U,
    },
    {
        /* DMA_SF1(APB_S1_D) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 23U,
    },
    {
        /* CANFD1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 24U,
    },
    {
        /* CANFD2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 25U,
    },
    {
        /* CANFD3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 26U,
    },
    {
        /* CANFD4 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 27U,
    },
    {
        /* EFUSE */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 31U,
    },
    {
        /* DCDC1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 32U,
    },
    {
        /* LDO_DIG */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 33U,
    },
    {
        /* ISTC */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 34U,
    },
    {
        /* IOMUXC_SF */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 35U,
    },
    {
        /* SMC */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 36U,
    },
    {
        /* POR_SF */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 37U,
    },
    {
        /* FS_24M */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 38U,
    },
    {
        /* IROMC */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 39U,
    },
    {
        /* SCR_SF */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 40U,
    },
    {
        /* RSTGEN_SF */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 41U,
    },
    {
        /* CKGEN_SF */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 42U,
    },
    {
        /* PLL1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 43U,
    },
    {
        /* PLL2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 44U,
    },
    {
        /* PLL3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 45U,
    },
    {
        /* VD_SF */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 46U,
    },
    {
        /* PT_SNS_SF */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 47U,
    },
    {
        /* XSPI1(PortA) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 48U,
    },
    {
        /* XSPI1(PortB) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 49U,
    },
    {
        /* EIC_BOOT */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 50U,
    },
    {
        /* GPIO_SF */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 52U,
    },
    {
        /* IOC */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 53U,
    },
    {
        /* GPV_AAHB */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 55U,
    },
    {
        /* FAB_SF */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 56U,
    },
    {
        /* XB_XB */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 57U,
    },
    {
        /* GPV_SX */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 58U,
    },
    {
        /* MAC */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 59U,
    },
    {
        /* SEM1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 60U,
    },
    {
        /* SEM2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 61U,
    },
    {
        /* WDT1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 62U,
    },
    {
        /* WDT2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 1U,
        .ppcApbmuxIpId = 63U,
    },
    {
        /* APB_MUX3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 0U,
    },
    {
        /* UART1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 19U,
    },
    {
        /* UART3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 20U,
    },
    {
        /* UART5 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 21U,
    },
    {
        /* UART7 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 22U,
    },
    {
        /* UART9 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 23U,
    },
    {
        /* UART11 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 24U,
    },
    {
        /* UART13 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 25U,
    },
    {
        /* UART15 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 26U,
    },
    {
        /* SPI1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 31U,
    },
    {
        /* SPI3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 32U,
    },
    {
        /* SPI5 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 33U,
    },
    {
        /* SPI7 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 34U,
    },
    {
        /* I2C1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 35U,
    },
    {
        /* I2C3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 36U,
    },
    {
        /* I2C5 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 37U,
    },
    {
        /* I2C8 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 37U,
    },
    {
        /* CANFD5 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 45U,
    },
    {
        /* CANFD7 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 46U,
    },
    {
        /* CANFD9 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 47U,
    },
    {
        /* CANFD11 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 48U,
    },
    {
        /* CANFD13 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 49U,
    },
    {
        /* CANFD15 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 50U,
    },
    {
        /* CANFD17 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 51U,
    },
    {
        /* CANFD19 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 52U,
    },
    {
        /* CANFD21 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 53U,
    },
    {
        /* CANFD23 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 54U,
    },
    {
        /* SIMULATION RESERVED1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 59U,
    },
    {
        /* XSPI2(PortA) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 60U,
    },
    {
        /* XSPI2(PortB) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 61U,
    },
    {
        /* WDT5 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 62U,
    },
    {
        /* WDT6 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 2U,
        .ppcApbmuxIpId = 63U,
    },
    {
        /* APB_MUX4 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 0U,
    },
    {
        /* UART2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 6U,
    },
    {
        /* UART4 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 7U,
    },
    {
        /* UART6 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 8U,
    },
    {
        /* UART8 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 9U,
    },
    {
        /* UART10 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 10U,
    },
    {
        /* UART12 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 11U,
    },
    {
        /* UART14 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 12U,
    },
    {
        /* UART16 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 13U,
    },
    {
        /* IRAMC1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 18U,
    },
    {
        /* IRAMC2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 19U,
    },
    {
        /* IRAMC3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 20U,
    },
    {
        /* SPI2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 25U,
    },
    {
        /* SPI4 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 26U,
    },
    {
        /* SPI6 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 27U,
    },
    {
        /* SPI8 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 28U,
    },
    {
        /* I2C2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 29U,
    },
    {
        /* I2C4 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 30U,
    },
    {
        /* I2C6 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 31U,
    },
    {
        /* I2C8 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 32U,
    },
    {
        /* FLEXRAY2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 37U,
    },
    {
        /* FLEXRAY1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 38U,
    },
    {
        /* CANFD6 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 43U,
    },
    {
        /* CANFD8 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 44U,
    },
    {
        /* CANFD10 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 45U,
    },
    {
        /* CANFD12 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 46U,
    },
    {
        /* CANFD14 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 47U,
    },
    {
        /* CANFD14 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 47U,
    },
    {
        /* CANFD16 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 48U,
    },
    {
        /* CANFD18 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 49U,
    },
    {
        /* CANFD20 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 50U,
    },
    {
        /* CANFD22 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 51U,
    },
    {
        /* CANFD24 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 52U,
    },
    {
        /* ADC1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 55U,
    },
    {
        /* ADC2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 56U,
    },
    {
        /* ADC3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 57U,
    },
    {
        /* ACMP1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 58U,
    },
    {
        /* ACMP2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 59U,
    },
    {
        /* ACMP3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 60U,
    },
    {
        /* ACMP4 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 61U,
    },
    {
        /* BIC_SF */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 3U,
        .ppcApbmuxIpId = 62U,
    },
    {
        /* APB_MUX5 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = 0U,
    },
    {
        /* ENET1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = 1U,
    },
    {
        /* ENET2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = 2U,
    },
    {
        /* IRAMC4 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = FIREWALL_PERMISSION_NONE,
    },
    {
        /* XSPI_SLV */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = 4U,
    },
    {
        /* EIC_SP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = 5U,
    },
    {
        /* CSSYS(APB_S0) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = 8U,
    },
    {
        /* CSSYS(APB_S1) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = 9U,
    },
    {
        /* CSSYS(APB_S2) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = 10U,
    },
    {
        /* CSSYS(APB_S3) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = 11U,
    },
    {
        /* WDT3 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = 16U,
    },
    {
        /* WDT4 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = 17U,
    },
    {
        /* GPV_SP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 4U,
        .ppcApbmuxIpId = 24U,
    },
    {
        /* APB_MUX6 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 0U,
    },
    {
        /* SACI1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 1U,
    },
    {
        /* SACI2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 2U,
    },
    {
        /* VD_AP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 4U,
    },
    {
        /* POR_AP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 5U,
    },
    {
        /* PT_SNS_AP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 6U,
    },
    {
        /* PLL4 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 8U,
    },
    {
        /* PLL5 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 9U,
    },
    {
        /* PLL_LVDS */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 10U,
    },
    {
        /* USB */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 11U,
    },
    {
        /* CKGEN_AP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 12U,
    },
    {
        /* RSTGEN_AP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 13U,
    },
    {
        /* IOMUXC_AP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 14U,
    },
    {
        /* SCR_AP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 15U,
    },
    {
        /* SEIP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 16U,
    },
    {
        /* GPIO_AP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_RW, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 18U,
    },
    {
        /* SDRAMC */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 19U,
    },
    {
        /* SEHC1 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 22U,
    },
    {
        /* SEHC2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 23U,
    },
    {
        /* DMA_AP(APB_S_A) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 24U,
    },
    {
        /* DMA_AP(APB_S_B) */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 25U,
    },
    {
        /* GPV_AP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 27U,
    },
    {
        /* SIMULATION RESERVED2 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 28U,
    },
    {
        /* WDT8 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 5U,
        .ppcApbmuxIpId = 31U,
    },
    {
        /* APB_MUX7 */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 6U,
        .ppcApbmuxIpId = 0U,
    },
    {
        /* DC */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 6U,
        .ppcApbmuxIpId = 1U,
    },
    {
        /* G2D */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 6U,
        .ppcApbmuxIpId = 4U,
    },
    {
        /* CSI */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 6U,
        .ppcApbmuxIpId = 6U,
    },
    {
        /* DISP_MUX */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 6U,
        .ppcApbmuxIpId = 12U,
    },
    {
        /* GPC_DISP */
        .ppcSfUserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSfPrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSp1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx0PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1UserPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcSx1PrivilegedPermission = FIREWALL_PERMISSION_NONE, /* 0:RW 1:RO 2:WO 3:NONE */
        .ppcDmaPermission = FIREWALL_PERMISSION_NONE,
        .ppcApbmuxId = 6U,
        .ppcApbmuxIpId = 15U,
    },
};



#define FIREWALL_STOP_SEC_CONST_UNSPECIFIED
#include "Firewall_MemMap.h"

#define FIREWALL_START_SEC_CODE
#include "Firewall_MemMap.h"

#define FIREWALL_STOP_SEC_CODE
#include "Firewall_MemMap.h"


#ifdef __cplusplus
}
#endif
/* End of file */
