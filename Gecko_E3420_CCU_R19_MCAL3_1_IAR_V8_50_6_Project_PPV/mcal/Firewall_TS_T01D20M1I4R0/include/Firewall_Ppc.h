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
 *  \file     Firewall_Ppc.h                                                                            *
 * \brief    This file contains interface header for Firewall PPC MCAL driver.                          *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/24     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef FIREWALL_PPC_H
#define FIREWALL_PPC_H

#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Firewall_Type.h"

/** *****************************************************************************************************
 * \brief This function configure the permission of peripherals in PPC module.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_PpcIpConfigure
 *                      (
 *                          uint32 macBaseAddr,
 *                          const Firewall_PpcIpConfigType *ppcIpCfgPtr,
 *                          uint16 ppcIpNum
 *                       )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : macBaseAddr - The base address of the firewall
 *                      ppcIpCfgPtr - The pointer to the ip permission configuration of PPC
 *                      ppcIpNum - The number of ip permission configurations
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configurate PPC ip permission success.
 *                      FIREWALL_E_NULL_POINTER: The pointer is a NULL_PTR.
 *                      FIREWALL_E_PPC_IP_NUM: The number of peripherals is unvalid.
 *
 * Description        : This function configure the permission of peripherals in PPC module.
 *                      The permissions of peripherals in PPC module will be locked after configuring.
 *                      This function controls the features of interrupt and error response according
 *                      to the EB configuration.
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_004 SWSR_FIREWALL_006 SWSR_FIREWALL_008 SWSR_FIREWALL_013
 *                      SWSR_FIREWALL_014 SWSR_FIREWALL_018 SWSR_FIREWALL_017 SWSR_FIREWALL_029 SM006
 *******************************************************************************************************/
Std_ReturnType Firewall_PpcIpConfigure(uint32 macBaseAddr, const Firewall_PpcIpConfigType *ppcIpCfgPtr,
                                       uint16 ppcIpNum);

/** *****************************************************************************************************
 * \brief This function configure the permission of peripherals' regions in PPC module.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_PpcAddrConfigure
 *                      (
 *                          uint32 macBaseAddr,
 *                          const Firewall_PpcAddrConfigType *ppcAddrCfgPtr,
 *                          uint16 ppcAddrNum
 *                       )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : macBaseAddr - The base address of the firewall
 *                      ppcAddrCfgPtr - The pointer to the ip region permission configuration of PPC
 *                      ppcAddrNum - The number of ip region permission configurations
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configurate PPC ip permission success.
 *                      FIREWALL_E_NULL_POINTER: The pointer is a NULL_PTR.
 *                      FIREWALL_E_PPC_REGION_NUM: The number of peripherals' regions is unvalid.
 *
 * Description        : This function configure the permission of peripherals' regions in PPC module.
 *                      The permissions of regions will be locked after configuring.
 *                      This function controls the features of interrupt and error response according
 *                      to the EB configuration.
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_004 SWSR_FIREWALL_006 SWSR_FIREWALL_008 SWSR_FIREWALL_013
 *                      SWSR_FIREWALL_014 SWSR_FIREWALL_018 SWSR_FIREWALL_017 SWSR_FIREWALL_029 SM006
 *******************************************************************************************************/
Std_ReturnType Firewall_PpcAddrConfigure(uint32 macBaseAddr, const Firewall_PpcAddrConfigType *ppcAddrCfgPtr,
                                         uint16 ppcAddrNum);

/** *****************************************************************************************************
 * \brief This function locks the configurations of the PPC module.
 *
 * \verbatim
 * Syntax             : void Firewall_PpcLock
 *                      (
 *                          uint32 macBaseAddr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : No reentrant
 *
 * Parameters (in)    : macBaseAddr - The base address of the firewall
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function locks the permissions of all peripherals and
 *                      apb regions in the PPC module.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_008
 *******************************************************************************************************/
void Firewall_PpcLock(uint32 macBaseAddr);

/** *****************************************************************************************************
 * \brief This function get the interrupt status of the PPC module.
 *
 * \verbatim
 * Syntax             : Firewall_PpcIrqStaType Firewall_PpcIrqHandler
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
 * Return value       : IrqSta - The illegal access error status of the PPC module
 *
 * Description        : This function get the illegal access error information of the PPC module.
 *                      The function exits as soon as it gets an illegal access message.
 *                      This function should be called by the firewall interrupt handler
 *                      Firewall_IrqHandler().
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_017 SM004
 *******************************************************************************************************/
Firewall_PpcIrqStaType Firewall_PpcIrqHandler(uint32 macBaseAddr);

/** *****************************************************************************************************
 * \brief This function clear the interrupt status of the PPC module.
 *
 * \verbatim
 * Syntax             : void Firewall_PpcClearInterrupt
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
 * Description        : This function clear the interrupt status of the PPC module.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_017
 *******************************************************************************************************/
void Firewall_PpcClearInterrupt(uint32 macBaseAddr);

#ifdef __cplusplus
}
#endif

#endif /* FIREWALL_PPC_H */
/* End of file */
