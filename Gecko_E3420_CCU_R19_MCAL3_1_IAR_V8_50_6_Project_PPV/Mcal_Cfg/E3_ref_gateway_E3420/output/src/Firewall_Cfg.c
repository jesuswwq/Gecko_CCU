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
 * \file     Firewall_Cfg.c                                                                             *
 * \brief   This file contains configuration source for Firewall MCAL driver                            *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:01      <td>1.0.0 R                                                         *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

#include "Firewall_Cfg.h"
#include "Firewall_Mac_Cfg.h"
#include "Firewall_Ppc_Cfg.h"
#include "Firewall_Mpc_Cfg.h"
#include "Firewall_Dio_Cfg.h"

#define FIREWALL_START_SEC_VAR_INIT_UNSPECIFIED
#include "Firewall_MemMap.h"

/********************************************************************************************************
 *                                  Global Variable Definitions                                        *
 *******************************************************************************************************/
extern void eeeeeee(void);
/*PRQA S 1533 4*/
/** \brief The pointer to the firewall interrupt callback function.
 * Traceability: SWSR_FIREWALL_017
 */
void (*Firewall_ErrorNotification)(void) = eeeeeee;
#define FIREWALL_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Firewall_MemMap.h"

#define FIREWALL_START_SEC_CONST_UNSPECIFIED
#include "Firewall_MemMap.h"

/** \brief The configuration of the firewall module.
 * Traceability: SWSR_FIREWALL_020
 */
const Firewall_ConfigType Firewall_Cfg =
{
    .macBaseAddr = FIREWALL_APB_MAC_BASE,
    .macCfgPtr = &Firewall_MacDomainMasterMap[0],
#if (FIREWALL_MPC_MEMPORT_NUM > 0U)
    .mpcCfgPtr = &Firewall_MpcCfg[0],
#else
    .mpcCfgPtr = NULL_PTR,
#endif  /** #if (FIREWALL_MPC_MEMPORT_NUM > 0U) */
    .mpcMemPortCfgNum = FIREWALL_MPC_MEMPORT_NUM,
#if (FIREWALL_PPC_BASE_IP_NUM > 0U)
    .ppcBaseIpCfgPtr = &Firewall_PpcBaseIpCfg[0],
#else
    .ppcBaseIpCfgPtr = NULL_PTR,
#endif  /** #if (FIREWALL_PPC_BASE_IP_NUM > 0U) */
    .ppcBaseIpCfgNum = FIREWALL_PPC_BASE_IP_NUM,
#if (FIREWALL_PPC_IP_NUM > 0U)
    .ppcIpCfgPtr = &Firewall_PpcIpCfg[0],
#else
    .ppcIpCfgPtr = NULL_PTR,
#endif  /** #if (FIREWALL_PPC_IP_NUM > 0U) */
    .ppcIpCfgNum = FIREWALL_PPC_IP_NUM,
#if (FIREWALL_PPC_ADDR_NUM > 0U)
    .ppcAddrCfgPtr = &Firewall_PpcAddrCfg[0],
#else
    .ppcAddrCfgPtr = NULL_PTR,
#endif  /** #if (FIREWALL_PPC_ADDR_NUM > 0U) */
    .ppcAddrCfgNum = FIREWALL_PPC_ADDR_NUM,
#if (FIREWALL_DIO_CORE_NUM > 0U)
    .dioRuleSpaceCfgPtr = &Firewall_DioRuleSpaceCfg[0],
#else
    .dioRuleSpaceCfgPtr = NULL_PTR,
#endif  /** #if (FIREWALL_DIO_CORE_NUM > 0U) */
    .dioCoreCfgNum = FIREWALL_DIO_CORE_NUM,
};

#define FIREWALL_STOP_SEC_CONST_UNSPECIFIED
#include "Firewall_MemMap.h"

#ifdef __cplusplus
}
#endif
/* End of file */
