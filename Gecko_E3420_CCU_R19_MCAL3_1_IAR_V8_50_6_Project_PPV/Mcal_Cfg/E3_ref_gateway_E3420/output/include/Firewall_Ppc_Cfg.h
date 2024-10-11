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
 *  \file     Firewall_Ppc_Cfg.h                                                                        *
 * \brief    This file contains configuration header for Firewall PPC MCAL driver                       *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:01      <td>1.0.0 R                                                         *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef FIREWALL_PPC_CFG_H
#define FIREWALL_PPC_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Firewall_Ppc.h"
#include "Firewall_Type.h"
/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \brief The maximum number of peripherals in apbmux1. */
#define FIREWALL_PPC_APBMUX1_IP_MAXNUM 16U
/** \brief The maximum number of peripherals in apbmux2. */
#define FIREWALL_PPC_APBMUX2_IP_MAXNUM 64U
/** \brief The maximum number of peripherals in apbmux3. */
#define FIREWALL_PPC_APBMUX3_IP_MAXNUM 64U
/** \brief The maximum number of peripherals in apbmux4. */
#define FIREWALL_PPC_APBMUX4_IP_MAXNUM 64U
/** \brief The maximum number of peripherals in apbmux5. */
#define FIREWALL_PPC_APBMUX5_IP_MAXNUM 32U
/** \brief The maximum number of peripherals in apbmux6. */
#define FIREWALL_PPC_APBMUX6_IP_MAXNUM 32U
/** \brief The maximum number of peripherals in apbmux7. */
#define FIREWALL_PPC_APBMUX7_IP_MAXNUM 16U
/** \brief The number of peripherals should be configured as defualt. */
#define FIREWALL_PPC_BASE_IP_NUM 184U
/** \brief The number of peripherals. */
#define FIREWALL_PPC_IP_NUM 0U
/** \brief The number of apb regions. */
#define FIREWALL_PPC_ADDR_NUM 0U

/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
/** \brief The base configuration of the firewall PPC module.
 * Traceability: SWSR_FIREWALL_015
 */
extern const Firewall_PpcIpConfigType Firewall_PpcBaseIpCfg[FIREWALL_PPC_BASE_IP_NUM];

/** \brief The configuration of peripherals in the firewall PPC module. */


#ifdef __cplusplus
}
#endif

#endif /* FIREWALL_PPC_CFG_H */
/* End of file */
