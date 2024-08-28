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
 * \file     Firewall.c                                                                                 *
 * \brief    MCAL Firewall Driver                                                                       *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/21     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif
/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Firewall.h"
#include "Firewall_Cfg.h"
#include "Firewall_Dio.h"
#include "Firewall_Mac.h"
#include "Firewall_Mpc.h"
#include "Firewall_Ppc.h"
#include "RegHelper.h"
#include "SchM_Firewall.h"
#if (STD_ON == FIREWALL_DEV_ERROR_DETECT)
#include "Det.h"
#endif /* #if (FIREWALL_DEV_ERROR_DETECT == STD_ON) */
#if (STD_ON == FIREWALL_SAFETY_ENABLE)
#include "FuSaMcalReportError.h"
#endif /* #if (FIREWALL_SAFETY_ENABLE == STD_ON) */

/********************************************************************************************************
 *                                 Imported Compiler Switch Checks                                      *
 *******************************************************************************************************/
#ifndef FIREWALL_SW_MAJOR_VERSION
#error "FIREWALL_SW_MAJOR_VERSION is not defined."
#endif

#ifndef FIREWALL_SW_MINOR_VERSION
#error "FIREWALL_SW_MINOR_VERSION is not defined."
#endif

#ifndef FIREWALL_SW_PATCH_VERSION
#error "FIREWALL_SW_PATCH_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef FIREWALL_AR_RELEASE_MAJOR_VERSION
#error "FIREWALL_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef FIREWALL_AR_RELEASE_MINOR_VERSION
#error "FIREWALL_AR_RELEASE_MINOR_VERSION is not defined."
#endif

/* AUTOSAR Secification File Version Check */
#ifndef FIREWALL_AR_RELEASE_REVISION_VERSION
#error "FIREWALL_AR_RELEASE_REVISION_VERSION is not defined."
#endif

/** \brief  AUTOSAR Major and Minor release version check. */
#if (FIREWALL_AR_RELEASE_MAJOR_VERSION != 4U)
#error "FIREWALL_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#if (FIREWALL_AR_RELEASE_MINOR_VERSION != 3U)
#error "FIREWALL_AR_RELEASE_MINOR_VERSION does not match."
#endif

#if (FIREWALL_AR_RELEASE_REVISION_VERSION != 1U)
#error "FIREWALL_AR_RELEASE_REVISION_VERSION does not match."
#endif

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/** \brief  Firewall module uninitialized state. */
#define FIREWALL_UNINIT (0x00U)
/** \brief  Firewall module initialized state. */
#define FIREWALL_INIT   (0x01U)

/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
#define FIREWALL_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Firewall_MemMap.h"
/** \brief  Firewall illegal access error information. */
static Firewall_ErrInfoType Firewall_ErrInfo;
/** \brief  Firewall driver status. */
static uint8 Firewall_Initializestatus;
/** \brief The pointer to the firewall configuration. */
static const Firewall_ConfigType *Firewall_CfgPtr;
#define FIREWALL_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Firewall_MemMap.h"

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
#define FIREWALL_START_SEC_CODE
#include "Firewall_MemMap.h"
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
void Firewall_Init(const Firewall_ConfigType *firewallCfgPtr)
{
    Std_ReturnType errId;
    /* #10 Check the status of Firewall driver. */
    if (FIREWALL_UNINIT != Firewall_Initializestatus)
    {
        errId = (Std_ReturnType)FIREWALL_E_INIT;
    }
    /* #20 Check the parameters. */
    else if (NULL_PTR == firewallCfgPtr)
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else
    {
        /* #30 Clear interrupt controller and status. */
        Firewall_MacClearInterrupt(firewallCfgPtr->macBaseAddr);
        Firewall_PpcClearInterrupt(firewallCfgPtr->macBaseAddr);
        Firewall_MpcClearInterrupt(firewallCfgPtr->macBaseAddr);

        /* #40 Configure the MAC module. */
        errId = Firewall_MacConfigure(firewallCfgPtr->macBaseAddr, firewallCfgPtr->macCfgPtr);

        if (((Std_ReturnType)E_OK == errId) && (0U < firewallCfgPtr->mpcMemPortCfgNum))
        {
            /* #50 Configure the Firewall MPC module. */
            errId = Firewall_MpcConfigure(
                firewallCfgPtr->macBaseAddr, firewallCfgPtr->mpcCfgPtr, firewallCfgPtr->mpcMemPortCfgNum);
        } /* else not needed */

        if (((Std_ReturnType)E_OK == errId) && (0U < firewallCfgPtr->ppcBaseIpCfgNum))
        {
            /* #60 Configure the Firewall PPC module as default. Select peripheral mode. */
            errId = Firewall_PpcIpConfigure(
                firewallCfgPtr->macBaseAddr, firewallCfgPtr->ppcBaseIpCfgPtr, firewallCfgPtr->ppcBaseIpCfgNum);
        } /* else not needed */

        if (((Std_ReturnType)E_OK == errId) && (0U < firewallCfgPtr->ppcIpCfgNum))
        {
            /* #70 Configure the Firewall PPC module. Select peripheral mode. */
            errId = Firewall_PpcIpConfigure(
                firewallCfgPtr->macBaseAddr, firewallCfgPtr->ppcIpCfgPtr, firewallCfgPtr->ppcIpCfgNum);
        } /* else not needed */

        if (((Std_ReturnType)E_OK == errId) && (0U < firewallCfgPtr->ppcAddrCfgNum))
        {
            /* #80 Configure the Firewall PPC module. Select address region mode.  */
            errId = Firewall_PpcAddrConfigure(
                firewallCfgPtr->macBaseAddr, firewallCfgPtr->ppcAddrCfgPtr, firewallCfgPtr->ppcAddrCfgNum);
        } /* else not needed */

        if (((Std_ReturnType)E_OK == errId) && (0U < firewallCfgPtr->dioCoreCfgNum))
        {
            /* #90 Configure the Firewall DIO module. */
            errId = Firewall_DioRuleSpaceConfigure(firewallCfgPtr->dioRuleSpaceCfgPtr, firewallCfgPtr->dioCoreCfgNum);
        } /* else not needed */

        if ((Std_ReturnType)E_OK == errId)
        {
            /* #100 Lock the Firewall PPC module. */
            Firewall_PpcLock(firewallCfgPtr->macBaseAddr);
            /* #110 Save the configuration pointer if the firewall initialization success. */
            Firewall_CfgPtr = firewallCfgPtr;
            /* #120 Switch Firewall driver status as initialized. */
            Firewall_Initializestatus = FIREWALL_INIT;
        } /* else not needed */
    }

/* #130 Report error code to the system if the firewall initialization failed. */
#if ((STD_ON == FIREWALL_DEV_ERROR_DETECT) || (STD_ON == FIREWALL_SAFETY_ENABLE))
    if ((Std_ReturnType)E_OK != errId)
    {
#if (STD_ON == FIREWALL_DEV_ERROR_DETECT)
        (void)Det_ReportError(FIREWALL_MODULE_ID, FIREWALL_INSTANCE_ID, FIREWALL_INIT_ID, errId);
#endif /** #if (STD_ON == FIREWALL_DEV_ERROR_DETECT) */
#if (STD_ON == FIREWALL_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(FIREWALL_MODULE_ID, FIREWALL_INSTANCE_ID, FIREWALL_INIT_ID, errId);
#endif /** #if (STD_ON == FIREWALL_SAFETY_ENABLE) */
    }
#else
    /* # Dummy assignment avoid compiler warning */
    FIREWALL_DUMMY_STATEMENT(errId);
#endif /** #if ((STD_ON == FIREWALL_DEV_ERROR_DETECT) || (FIREWALL_SAFETY_ENABLE)) */
}

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
Std_ReturnType Firewall_AssignDomain(uint8 masterId, uint8 domainId)
{
    Std_ReturnType errId;

    /* #10 Check the status of Firewall driver. */
    if (FIREWALL_INIT != Firewall_Initializestatus)
    {
        errId = (Std_ReturnType)FIREWALL_E_UNINIT;
    }
    else
    {
        /* #20 Assign the master to the specified domain. */
        errId = Firewall_MacAssignDomain(Firewall_CfgPtr->macBaseAddr, masterId, domainId);
    }

/* #30 Report error code to the system if the firewall initialization failed. */
#if ((STD_ON == FIREWALL_DEV_ERROR_DETECT) || (STD_ON == FIREWALL_SAFETY_ENABLE))
    if ((Std_ReturnType)E_OK != errId)
    {
#if (STD_ON == FIREWALL_DEV_ERROR_DETECT)
        (void)Det_ReportError(FIREWALL_MODULE_ID, FIREWALL_INSTANCE_ID, FIREWALL_ASSIGN_DOMAIN_ID, errId);
#endif /** #if (STD_ON == FIREWALL_DEV_ERROR_DETECT) */
#if (STD_ON == FIREWALL_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(FIREWALL_MODULE_ID, FIREWALL_INSTANCE_ID, FIREWALL_ASSIGN_DOMAIN_ID, errId);
#endif /** #if (STD_ON == FIREWALL_SAFETY_ENABLE) */
    }  /* else not needed */
#endif /** #if ((STD_ON == FIREWALL_DEV_ERROR_DETECT) || (FIREWALL_SAFETY_ENABLE)) */

    return errId;
}

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
Std_ReturnType Firewall_LockDomainAssignment(void)
{
    Std_ReturnType errId;

    /* #10 Check the status of Firewall driver. */
    if (FIREWALL_INIT != Firewall_Initializestatus)
    {
        errId = (Std_ReturnType)FIREWALL_E_UNINIT;
    }
    else
    {
        /* #20 Lock the domain assignment of the master. */
        errId = Firewall_MacLockDomainAssignment(Firewall_CfgPtr->macBaseAddr, Firewall_CfgPtr->macCfgPtr);
    }

/* #30 Report error code to the system if the firewall initialization failed. */
#if ((STD_ON == FIREWALL_DEV_ERROR_DETECT) || (STD_ON == FIREWALL_SAFETY_ENABLE))
    if ((Std_ReturnType)E_OK != errId)
    {
#if (STD_ON == FIREWALL_DEV_ERROR_DETECT)
        (void)Det_ReportError(FIREWALL_MODULE_ID, FIREWALL_INSTANCE_ID, FIREWALL_LOCK_DOMAIN_ID, errId);
#endif /** #if (STD_ON == FIREWALL_DEV_ERROR_DETECT) */
#if (STD_ON == FIREWALL_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(FIREWALL_MODULE_ID, FIREWALL_INSTANCE_ID, FIREWALL_LOCK_DOMAIN_ID, errId);
#endif /** #if (STD_ON == FIREWALL_SAFETY_ENABLE) */
    }  /* else not needed */
#endif /** #if ((STD_ON == FIREWALL_DEV_ERROR_DETECT) || (FIREWALL_SAFETY_ENABLE)) */

    return errId;
}

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
ISR(Firewall_IrqHandler)
{
    Std_ReturnType errId;
    Firewall_PpcIrqStaType ppcIrqErrInfo;
    Firewall_MpcIrqStaType mpcIrqErrInfo;

    /* Struct variables need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    mpcIrqErrInfo.mpcMemPortId = 0U;
    mpcIrqErrInfo.mpcErrSta = 0U;

    /* #10 Check the status of Firewall driver. */
    if (FIREWALL_INIT != Firewall_Initializestatus)
    {
        errId = (Std_ReturnType)FIREWALL_E_UNINIT;
        Firewall_PpcClearInterrupt(FIREWALL_APB_MAC_BASE);
        Firewall_MpcClearInterrupt(FIREWALL_APB_MAC_BASE);
    }
    else
    {
        /* #20 Get the illegal access information of the MPC module. */
        errId = Firewall_MpcIrqHandler(Firewall_CfgPtr->macBaseAddr,
                                       Firewall_CfgPtr->mpcCfgPtr,
                                       Firewall_CfgPtr->mpcMemPortCfgNum,
                                       &mpcIrqErrInfo);
        /* #30 Get the illegal access information of the PPC module. */
        ppcIrqErrInfo = Firewall_PpcIrqHandler(Firewall_CfgPtr->macBaseAddr);

        /* #40 Enter critical region. */
        SchM_Enter_Firewall_FIREWALL_EXCLUSIVE_AREA_00();

        /* #50 Save the illegal access information if the firewall to a global variable. */
        Firewall_ErrInfo.ppcErrInfo[ppcIrqErrInfo.ppcApbmuxIpId] = ppcIrqErrInfo;
        Firewall_ErrInfo.mpcErrInfo[mpcIrqErrInfo.mpcMemPortId] = mpcIrqErrInfo;

        /* Exit critical region. */
        SchM_Exit_Firewall_FIREWALL_EXCLUSIVE_AREA_00();

        if ((NULL_PTR != Firewall_ErrorNotification) &&
            ((0U != ppcIrqErrInfo.ppcErrSta) || (0U != mpcIrqErrInfo.mpcErrSta)))
        {
            Firewall_ErrorNotification();
        } /* else not needed */
    }

    /* #60 Clear the interrupt of the MAC module. */
    Firewall_MacClearInterrupt(FIREWALL_APB_MAC_BASE);

/* #70 Report error code to the system of the firewall initialization failed. */
#if ((STD_ON == FIREWALL_DEV_ERROR_DETECT) || (STD_ON == FIREWALL_SAFETY_ENABLE))
    if ((Std_ReturnType)E_OK != errId)
    {
#if (STD_ON == FIREWALL_DEV_ERROR_DETECT)
        (void)Det_ReportError(FIREWALL_MODULE_ID, FIREWALL_INSTANCE_ID, FIREWALL_IRQ_HANDLER_ID, errId);
#endif /** #if (STD_ON == FIREWALL_DEV_ERROR_DETECT) */
#if (STD_ON == FIREWALL_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(FIREWALL_MODULE_ID, FIREWALL_INSTANCE_ID, FIREWALL_IRQ_HANDLER_ID, errId);
#endif /** #if (STD_ON == FIREWALL_SAFETY_ENABLE) */
    }
#else
    FIREWALL_DUMMY_STATEMENT(errId);
#endif /** #if ((STD_ON == FIREWALL_DEV_ERROR_DETECT) || (FIREWALL_SAFETY_ENABLE)) */
}

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
Std_ReturnType Firewall_GetErrorInformation(Firewall_ErrInfoType *Firewall_ErrorInfoPtr)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;
    uint8 memPortNum;
    uint16 ipNum;

    /* #10 Check the status of Firewall driver. */
    if (FIREWALL_INIT != Firewall_Initializestatus)
    {
        errId = (Std_ReturnType)FIREWALL_E_UNINIT;
    }
    /* #20 Check the parameters. */
    else if (NULL_PTR == Firewall_ErrorInfoPtr)
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else
    {
        /* #30 Enter critical region. */
        SchM_Enter_Firewall_FIREWALL_EXCLUSIVE_AREA_00();

        /* #40 Get the illegal access information of the firewall from the global variable.
         *     Clear the illegal access information of the firewall in a global variable.
         */
        for (ipNum = 0U; ipNum < FIREWALL_PPC_APBMUX_MAXNUM; ++ipNum)
        {
            Firewall_ErrorInfoPtr->ppcErrInfo[ipNum] = Firewall_ErrInfo.ppcErrInfo[ipNum];
            Firewall_ErrInfo.ppcErrInfo[ipNum].ppcApbmuxIpId = 0U;
            Firewall_ErrInfo.ppcErrInfo[ipNum].ppcErrSta = 0U;
        }
        for (memPortNum = 0U; memPortNum < FIREWALL_MPC_MEMPORT_MAXNUM; ++memPortNum)
        {
            Firewall_ErrorInfoPtr->mpcErrInfo[memPortNum] = Firewall_ErrInfo.mpcErrInfo[memPortNum];
            Firewall_ErrInfo.mpcErrInfo[memPortNum].mpcMemPortId = 0U;
            Firewall_ErrInfo.mpcErrInfo[memPortNum].mpcErrSta = 0U;
        }

        /* Exit critical region. */
        SchM_Exit_Firewall_FIREWALL_EXCLUSIVE_AREA_00();
    }

/* #50 Report error code to the system if the firewall initialization failed. */
#if ((STD_ON == FIREWALL_DEV_ERROR_DETECT) || (STD_ON == FIREWALL_SAFETY_ENABLE))
    if ((Std_ReturnType)E_OK != errId)
    {
#if (STD_ON == FIREWALL_DEV_ERROR_DETECT)
        (void)Det_ReportError(FIREWALL_MODULE_ID, FIREWALL_INSTANCE_ID, FIREWALL_GET_ERRORINFO_ID, errId);
#endif /** #if (STD_ON == FIREWALL_DEV_ERROR_DETECT) */
#if (STD_ON == FIREWALL_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(FIREWALL_MODULE_ID, FIREWALL_INSTANCE_ID, FIREWALL_GET_ERRORINFO_ID, errId);
#endif /** #if (STD_ON == FIREWALL_SAFETY_ENABLE) */
    }  /* else not needed */
#endif /** #if ((STD_ON == FIREWALL_DEV_ERROR_DETECT) || (FIREWALL_SAFETY_ENABLE)) */

    return errId;
}

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
void Firewall_GetVersionInfo(Std_VersionInfoType *versionInfo)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;

    /* #10 Check the parameters. */
    if (NULL_PTR == versionInfo)
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else
    {
        /* #20 Retrieve version information */
        versionInfo->vendorID = FIREWALL_VENDOR_ID;
        versionInfo->moduleID = FIREWALL_MODULE_ID;
        versionInfo->sw_major_version = FIREWALL_SW_MAJOR_VERSION;
        versionInfo->sw_minor_version = FIREWALL_SW_MINOR_VERSION;
        versionInfo->sw_patch_version = FIREWALL_SW_PATCH_VERSION;
    }

/* #30 Report error code to the system if the firewall initialization failed. */
#if ((STD_ON == FIREWALL_DEV_ERROR_DETECT) || (STD_ON == FIREWALL_SAFETY_ENABLE))
    if ((Std_ReturnType)E_OK != errId)
    {
#if (STD_ON == FIREWALL_DEV_ERROR_DETECT)
        (void)Det_ReportError(FIREWALL_MODULE_ID, FIREWALL_INSTANCE_ID, FIREWALL_GET_VERSION_ID, errId);
#endif /** #if (STD_ON == FIREWALL_DEV_ERROR_DETECT) */
#if (STD_ON == FIREWALL_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError(FIREWALL_MODULE_ID, FIREWALL_INSTANCE_ID, FIREWALL_GET_VERSION_ID, errId);
#endif /** #if (STD_ON == FIREWALL_SAFETY_ENABLE) */
    }  /* else not needed */
#else
    FIREWALL_DUMMY_STATEMENT(errId);
#endif /** #if ((STD_ON == FIREWALL_DEV_ERROR_DETECT) || (FIREWALL_SAFETY_ENABLE)) */
}

#define FIREWALL_STOP_SEC_CODE
#include "Firewall_MemMap.h"

#ifdef __cplusplus
}
#endif
