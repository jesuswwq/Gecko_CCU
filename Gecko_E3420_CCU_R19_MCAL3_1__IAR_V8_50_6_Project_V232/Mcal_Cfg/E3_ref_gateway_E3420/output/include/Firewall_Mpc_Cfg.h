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
 *  \file     Firewall_Mpc_Cfg.h                                                                        *
 * \brief    This file contains configuration header for Firewall MPC MCAL driver                       *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date                 <th>Version                                                             *
 * <tr><td>2024-03-08 16:29:01      <td>1.0.0 R                                                         *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef FIREWALL_MPC_CFG_H
#define FIREWALL_MPC_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "Std_Types.h"
#include "Firewall_Type.h"


/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/** \brief The number of the memory ports. */
#define FIREWALL_MPC_MEMPORT_NUM 23

/********************************************************************************************************
 *                                  Global Constant Declarations                                        *
 *******************************************************************************************************/
/** \brief The configuration of the firewall MPC module.
 * Traceability: SWSR_FIREWALL_010 SWSR_FIREWALL_011 SWSR_FIREWALL_012
 */
extern const Firewall_MpcMemPortConfigType Firewall_MpcCfg[FIREWALL_MPC_MEMPORT_NUM];

#ifdef __cplusplus
}
#endif

#endif /* FIREWALL_MPC_CFG_H */
/* End of file */
