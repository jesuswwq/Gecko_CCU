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
 *  \file     Firewall_Mpc.h                                                                            *
 * \brief    This file contains interface header for Firewall MPC MCAL Driver.                          *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/25     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef FIREWALL_MPC_H
#define FIREWALL_MPC_H

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Firewall_Type.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/** *****************************************************************************************************
 * \brief This function configure the permission of memory port regions in MPC module.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_MpcConfigure
 *                      (
 *                          uint32 macBaseAddr,
 *                          const Firewall_MpcMemPortConfigType *mpcMemPortCfgPtr,
 *                          uint16 mpcMemPortNum
 *                       )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : macBaseAddr - The base address of the firewall
 *                      mpcMemPortCfgPtr - The pointer to memory port regions configuration of MPC module
 *                      mpcMemPortNum - The number of memory port configurations
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configurate MPC memory port success.
 *                      FIREWALL_E_NULL_POINTER: The pointer is a NULL_PTR.
 *                      FIREWALL_E_MPC_PORT_NUM: The number of memory port is unvalid.
 *
 * Description        : This function configure memory ports in MPC module.
 *                      The permissions of memory regions in MPC module will be locked after configuring.
 *                      This function controls the features of interrupt and error response according
 *                      to the EB configuration.
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_003 SWSR_FIREWALL_004 SWSR_FIREWALL_008 SWSR_FIREWALL_009
 *                      SWSR_FIREWALL_010 SWSR_FIREWALL_018 SM006
 *******************************************************************************************************/
Std_ReturnType Firewall_MpcConfigure(uint32 macBaseAddr, const Firewall_MpcMemPortConfigType *mpcMemPortCfgPtr,
                                     uint8 mpcMemPortNum);

/** *****************************************************************************************************
 * \brief This function get the interrupt status of the MPC module.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_MpcIrqHandler
 *                      (
 *                          uint32 macBaseAddr,
 *                          const Firewall_MpcMemPortConfigType *mpcMemPortCfgPtr,
 *                          uint8 mpcMemPortNum,
 *                          Firewall_MpcIrqStaType *mpcIrqSta
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : macBaseAddr - The base address of the firewall
 *                      mpcMemPortCfgPtr - The pointer to memory ports configuration
 *                      mpcMemPortNum - The number of memory ports
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : mpcIrqSta - The illegal access error status of the PPC module
 *
 * Return value       : E_OK: Get MPC illegal access error infomation success.
 *                      FIREWALL_E_NULL_POINTER: The pointer is a NULL_PTR.
 *                      FIREWALL_E_MPC_PORT_NUM: The number of memory port is unvalid.
 *
 * Description        : This function get the illegal access error information of the MPC module.
 *                      The function exits as soon as it gets an illegal access message.
 *                      This function should be called by the firewall interrupt handler
 *                      Firewall_IrqHandler().
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_017 SM006 SM004
 *******************************************************************************************************/
Std_ReturnType Firewall_MpcIrqHandler(uint32 macBaseAddr, const Firewall_MpcMemPortConfigType *mpcMemPortCfgPtr,
                                      uint8 mpcMemPortNum, Firewall_MpcIrqStaType *mpcIrqSta);

/** *****************************************************************************************************
 * \brief This function clear the interrupt status of the MPC module.
 *
 * \verbatim
 * Syntax             : void Firewall_MpcClearInterrupt
 *                      (
 *                          uint32 macBaseAddr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : macBaseAddr - The base address of the firewall
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function clear the interrupt status of the MPC module.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_017
 *******************************************************************************************************/
void Firewall_MpcClearInterrupt(uint32 macBaseAddr);

#ifdef __cplusplus
}
#endif

#endif /* FIREWALL_MPC_H */
/* End of file */
