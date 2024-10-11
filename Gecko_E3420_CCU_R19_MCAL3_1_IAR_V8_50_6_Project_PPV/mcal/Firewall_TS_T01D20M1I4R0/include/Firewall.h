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
 *  \file     Firewall.h                                                                                *
 * \brief    This file contains interface header for Firewall MCAL driver                               *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/24     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifndef FIREWALL_H
#define FIREWALL_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 * \defgroup MCAL_FIREWALL FIREWALL Driver
 *
 * The FIREWALL provides the isolation of destination memory mapped locations such as peripherals,
 * memory and pin to a domain, which includes a single core, a bus master, or a group of cores and
 * bus masters.
 * The FIREWALL driver is implemented in two layers of E3 family, the higher layer is the FIREWALL,
 * which is mainly provides users with external function interfaces for initialization, assigning/
 * locking the domain for the master and interruption handler. The lower layer is the FIREWALL_IP
 * which provides the hardware service for FIREWALL layer, including internal function interfaces
 * for configing MAC (memory access controller) , MPC(memory protection controller),
 * PPC(Peripheral Protection Controller) and pin rule space.
 *
 * \sa MCAL_FIREWALL_MACRO
 * \sa MCAL_FIREWALL_STRUCT
 * \sa MCAL_FIREWALL_API
 *  \{
 */

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Firewall_Type.h"
#include <Mcal.h>

/********************************************************************************************************
 *                                 Global Macro definition                                              *
 *******************************************************************************************************/
/**
 *  \defgroup MCAL_FIREWALL_MACRO Firewall Macro.
 *
 * This files defines FIREWALL MCAL macros.
 *  \{
 */

/**
 *  \name FIREWALL Driver ID Info
 * \{
 */
/** \brief  Semi Driver Vendor ID */
#define FIREWALL_VENDOR_ID        (0x8CU)
/** \brief  FIREWALL Driver Module ID */
#define FIREWALL_MODULE_ID        (2049U)
/** \brief FIREWALL Driver Instance ID */
#define FIREWALL_INSTANCE_ID      (0x00U)
/** \} */

/**
 *  \name FIREWALL Driver Functions ID
 * \{
 */
/** \brief  Firewall_Init() function id. */
#define FIREWALL_INIT_ID          (0U)
/** \brief  Firewall_AssignDomain() function id. */
#define FIREWALL_ASSIGN_DOMAIN_ID (1U)
/** \brief  Firewall_LockDomainAssignment() function id. */
#define FIREWALL_LOCK_DOMAIN_ID   (2U)
/** \brief  Firewall_GetErrorInformation() function id. */
#define FIREWALL_GET_ERRORINFO_ID (3U)
/** \brief  Firewall_IrqHandler() function id. */
#define FIREWALL_IRQ_HANDLER_ID   (4U)
/** \brief  Firewall_GetVersionInfo() function id. */
#define FIREWALL_GET_VERSION_ID   (5U)
/** \} */

/** \brief  Firewall module base address. */
#define FIREWALL_APB_MAC_BASE     (0xF07B0000u)

/** \} */

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
/**
 *  \defgroup MCAL_FIREWALL_API Firewall driver interfaces.
 *
 * This files defines FIREWALL MCAL driver interface
 * \{
 */
/** *****************************************************************************************************
 * \brief This function configure the firewall.
 *
 * \verbatim
 * Syntax             : void Firewall_Init
 *                      (
 *                          const Firewall_ConfigType *firewallCfgPtr
 *                      )
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : firewallCfgPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Driver Module Initialization function.The Initialization function shall
 *                      initialize MAC/MPC/PPC/DIO registers with the values of the structure
 *                      referenced by the parameter ConfigPtr
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_001 SWSR_FIREWALL_003 SWSR_FIREWALL_004 SWSR_FIREWALL_005
 *                      SWSR_FIREWALL_006 SWSR_FIREWALL_008 SWSR_FIREWALL_013 SWSR_FIREWALL_016
 *                      SWSR_FIREWALL_018 SWSR_FIREWALL_021 SM006 SM002
 *******************************************************************************************************/
void Firewall_Init(const Firewall_ConfigType *firewallCfgPtr);

/** *****************************************************************************************************
 * \brief This function assigns the master to the specified domain.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_AssignDomain
 *                      (
 *                          uint8 masterId,
 *                          uint8 domainId
 *                      )
 *
 * Service ID[hex]    : 0x02
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : masterId - The id of the master
 *
 * Parameters (in)    : domainId - The id of the domain
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Assigned the master to the domain success.
 *                      FIREWALL_E_UNINIT: The firewall is uninitialized.
 *                      FIREWALL_E_MAC_MASTER_ID: The master id is unvalid.
 *                      FIREWALL_E_MAC_DOMAIN_ID: The domain id is unvalid.
 *                      FIREWALL_E_MAC_LOCKED: The domain assignment of the master is locked.
 *
 * Description        : Assign the specified master to a domain.
 *                      This function should be executed after the initialization function
 *                      Firewall_Init().
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_009 SWSR_FIREWALL_018 SWSR_FIREWALL_024 SM001
 *******************************************************************************************************/
Std_ReturnType Firewall_AssignDomain(uint8 masterId, uint8 domainId);

/** *****************************************************************************************************
 * \brief This function lock the domain assignment of the master.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_LockDomainAssignment
 *                      (
 *                      void
 *                      )
 *
 * Service ID[hex]    : 0x03
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Lock domain assignment success.
 *                      FIREWALL_E_UNINIT: The firewall is uninitialized.
 *                      FIREWALL_E_NULL_POINTER: The pointer to the MAC configuration is NULL.
 *
 * Description        : This function lock the domain assignment of the master, should be called
 *                      after the initialization function Firewall_Init() or domain assignment
 *                      function Firewall_AssignDomain().
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_008 SWSR_FIREWALL_018 SWSR_FIREWALL_023 SM001
 *******************************************************************************************************/
Std_ReturnType Firewall_LockDomainAssignment(void);

/** *****************************************************************************************************
 * \brief This function handle the firewall illegal access interrupt.
 *
 * \verbatim
 * Syntax             : void Firewall_IrqHandler
 *                      (
 *                          void
 *                      )
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Driver Module interrupt handle function. Clear PPC/MPC Interrupt status,
 *                      Save interrupt state to the global variable.
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_017 SWSR_FIREWALL_018 SWSR_FIREWALL_026 SM003 SM007
 *******************************************************************************************************/
ISR(Firewall_IrqHandler);

/** *****************************************************************************************************
 * \brief This function get the firewall illegal access information.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_GetErrorInformation
 *                      (
 *                          Firewall_ErrInfoType *Firewall_ErrorInfoPtr
 *                      )
 *
 * Service ID[hex]    : 0x01
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : Firewall_ErrorInfoPtr - Pointer to the buffer used by system to get the information.
 *
 * Return value       : E_OK: Get error information success.
 *                      FIREWALL_E_UNINIT: The firewall is uninitialized.
 *                      FIREWALL_E_NULL_POINTER: The input pointer is NULL_PTR.
 *
 * Description        : System calls this function to get the firewall illegal access information. Should
 *                      enable the macro FIREWALL_INTERRUPT_EN.
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_022 SM007 SM006 SM001
 *******************************************************************************************************/
Std_ReturnType Firewall_GetErrorInformation(Firewall_ErrInfoType *Firewall_ErrorInfoPtr);

/** *****************************************************************************************************
 * \brief This function gets the version information of this module.
 *
 * \verbatim
 * Syntax             : void Firewall_GetVersionInfo
 *                      (
 *                          Std_VersionInfoType *versionInfo
 *                      )
 *
 * Service ID[hex]    : 0x04
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : versioninfo - Pointer to where to store the version information of this module.
 *
 * Return value       : None
 *
 * Description        : This function returns the version information of this module.
 *                      The version information include : Module ID, Vendor ID.
 *                      Vendor specific version numbers.
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_025 SM006
 *******************************************************************************************************/
void Firewall_GetVersionInfo(Std_VersionInfoType *versionInfo);

/** \} */
/** \} */

#ifdef __cplusplus
}
#endif

#endif /* FIREWALL_H */
/* End of file */
