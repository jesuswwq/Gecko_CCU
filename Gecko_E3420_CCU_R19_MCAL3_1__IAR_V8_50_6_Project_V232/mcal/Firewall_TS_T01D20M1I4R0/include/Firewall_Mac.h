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
 *  \file     Firewall_Mac.h                                                                            *
 * \brief    This file contains interface header for Firewall MAC MCAL Driver.                          *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/25     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef FIREWALL_MAC_H
#define FIREWALL_MAC_H

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
 * \brief This function configure the mapping between masters and domains in MAC module.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_MacConfigure
 *                      (
 *                          uint32 macBaseAddr,
 *                          const Firewall_MacConfigType *macConfigPtr
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : macBaseAddr - The base address of the firewall
 *                      macConfigPtr - The pointer to the ip permission configuration of the MAC
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configurate PPC ip permission success.
 *                      FIREWALL_E_NULL_POINTER: The pointer is a NULL_PTR.
 *
 * Description        : This function configure the mapping between masters and domains in MAC module.
 *                      The System should call Firewall_MacLockDomainAssignment() to lock the MAC
 *                      configurations after calling this function.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_004 SWSR_FIREWALL_005 SM006
 *******************************************************************************************************/
Std_ReturnType Firewall_MacConfigure(uint32 macBaseAddr, const Firewall_MacConfigType *macConfigPtr);

/** *****************************************************************************************************
 * \brief This function configure the mapping between masters and domains in MAC module.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_MacAssignDomain
 *                      (
 *                          uint32 macBaseAddr,
 *                          uint8 masterId,
 *                          uint8 domainId
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : macBaseAddr - The base address of the firewall
 *                      masterId - The id of the master
 *                      domainId - The id of the domain
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configurate PPC ip permission success.
 *                      FIREWALL_E_MAC_MASTER_ID: The master id is unvalid.
 *                      FIREWALL_E_MAC_DOMAIN_ID: The domain id is unvalid.
 *                      FIREWALL_E_MAC_LOCKED: The domain assignment of the master is locked.
 *
 * Description        : This function configure the mapping between masters and domains in MAC module.
 *                      This function is called by Firewall_AssignDomain().
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_009 SM006
 *******************************************************************************************************/
Std_ReturnType Firewall_MacAssignDomain(uint32 macBaseAddr, uint8 masterId, uint8 domainId);

/** *****************************************************************************************************
 * \brief This function lock the configuration of map between masters and domains in MAC module.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_MacLockDomainAssignment
 *                      (
 *                          uint32 macBaseAddr,
 *                          const Firewall_MacConfigType macConfigPtr,
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : macBaseAddr - The base address of the firewall
 *                      macConfigPtr - The pointer to the configuration of the MAC module
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Lock domain assignment success.\
 *                      FIREWALL_E_NULL_POINTER: The pointer is a NULL_PTR.
 *
 * Description        : This function lock the configuration of map between masters and domains
 *                      in MAC module.
 *                      This function is called by Firewall_LockDomainAssignment.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_008 SM006
 *******************************************************************************************************/
Std_ReturnType Firewall_MacLockDomainAssignment(uint32 macBaseAddr, const Firewall_MacConfigType *macConfigPtr);

/** *****************************************************************************************************
 * \brief This function clear the interrupt status of the MAC module.
 *
 * \verbatim
 * Syntax             : void Firewall_MacClearInterrupt
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
 * Description        : This function clear the interrupt status of the MAC module.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_017
 *******************************************************************************************************/
void Firewall_MacClearInterrupt(uint32 macBaseAddr);

#ifdef __cplusplus
}
#endif

#endif /* FIREWALL_MAC_H */
/* End of file */
