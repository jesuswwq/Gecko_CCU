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
 * \file     Firewall_Mac.c                                                                             *
 * \brief    MCAL Firewall MAC Module Driver                                                            *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/25     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Firewall_Mac_Cfg.h"
#include "Firewall_MacReg.h"
#include "Firewall_Mac.h"
#include "Firewall_Cfg.h"
#include "RegHelper.h"

#define FIREWALL_START_SEC_CODE
#include "Firewall_MemMap.h"
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
Std_ReturnType Firewall_MacConfigure(uint32 macBaseAddr, const Firewall_MacConfigType *macConfigPtr)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;
    uint8 masterNum;
    uint8 domainNum;

    /* #10 Check the parameters. */
    if (NULL_PTR == macConfigPtr)
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else
    {
        /* #20 Configure the firewall permission for SF core. */
        /* Assign the SF master to the SF domain, and lock this configuration. */
        REG_WRITE32(MAC_MDA_DID_VALUE(FIREWALL_DOMAIN_ID_SF),
                    macBaseAddr + MAC_MDA_OFFSET_ADDR(FIREWALL_MASTER_ID_CORE_SF));
        REG_WRITE32(MAC_MDA_DID_VALUE(FIREWALL_DOMAIN_ID_SF) | MAC_MDA_LOCK,
                    macBaseAddr + MAC_MDA_OFFSET_ADDR(FIREWALL_MASTER_ID_CORE_SF));
        /* Set the SF domain as the global manager. */
        REG_WRITE32(MAC_ACS_DID_VALUE(FIREWALL_DOMAIN_ID_SF), macBaseAddr + MAC_ACS_DID);
        REG_WRITE32(MAC_ACS_DID_VALUE(FIREWALL_DOMAIN_ID_SF) | MAC_ACS_DID_LOCK, macBaseAddr + MAC_ACS_DID);

        /* #30 Assign all masters to the different domain. */
        for (domainNum = 0U; domainNum < FIREWALL_DOMAIN_MAXNUM; ++domainNum)
        {
            if (NULL != macConfigPtr[domainNum])
            {
                masterNum = 0U;
                while (macConfigPtr[domainNum][masterNum] < FIREWALL_MASTER_MAXNUM)
                {
                    /* Assign the master to the specified domain. */
                    REG_WRITE32(MAC_MDA_DID_VALUE(domainNum),
                                macBaseAddr + MAC_MDA_OFFSET_ADDR(macConfigPtr[domainNum][masterNum]));
                    /* Lock the master transaction attribute. */
                    REG_WRITE32(MAC_MAA_PRI_LOCK | MAC_MAA_SEC_LOCK, macBaseAddr + MAC_MAA_ADDR(masterNum));
                    ++masterNum;
                }
            } /* else not needed */
        }

#if (STD_OFF == FIREWALL_RESPONSE_ERROR_EN)
        /* #40 Disable respone error when illegal access */
        REG_WRITE32(MAC_RESP_ERR_DIS_ALL_DIS | MAC_RESP_ERR_DIS_MAC_DIS, macBaseAddr + MAC_RESP_ERR_DIS);
        REG_WRITE32(
            MAC_RESP_ERR_DIS_ALL_DIS | MAC_RESP_ERR_DIS_MAC_DIS | MAC_RESP_ERR_DIS_ALL_LOCK | MAC_RESP_ERR_DIS_MAC_LOCK,
            macBaseAddr + MAC_RESP_ERR_DIS);
#endif /** #if (STD_OFF == FIREWALL_RESPONSE_ERROR_EN) */
    }

    return errId;
}

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
Std_ReturnType Firewall_MacAssignDomain(uint32 macBaseAddr, uint8 masterId, uint8 domainId)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;

    /* #10 Check the parameters. */
    if (masterId >= FIREWALL_MASTER_MAXNUM)
    {
        errId = (Std_ReturnType)FIREWALL_E_MAC_MASTER_ID;
    }
    else if (domainId >= FIREWALL_DOMAIN_MAXNUM)
    {
        errId = (Std_ReturnType)FIREWALL_E_MAC_DOMAIN_ID;
    }
    else if (0U != (MAC_ACS_DID_LOCK & REG_READ32(macBaseAddr + MAC_MDA_OFFSET_ADDR(masterId))))
    {
        errId = (Std_ReturnType)FIREWALL_E_MAC_LOCKED;
    }
    else
    {
        /* #20 Assign the master to the specified domain. */
        REG_WRITE32(MAC_MDA_DID_VALUE(domainId), macBaseAddr + MAC_MDA_OFFSET_ADDR(masterId));
    }

    return errId;
}

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
Std_ReturnType Firewall_MacLockDomainAssignment(uint32 macBaseAddr, const Firewall_MacConfigType *macConfigPtr)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;
    uint32 tempVal;
    uint8 masterNum;
    uint8 domainNum;

    /* #10 Check the parameters. */
    if (NULL_PTR == macConfigPtr)
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else
    {
        /* #20 Lock the domain assignment of all masters. */
        for (domainNum = 0U; domainNum < FIREWALL_DOMAIN_MAXNUM; ++domainNum)
        {
            if (NULL_PTR != macConfigPtr[domainNum])
            {
                masterNum = 0U;
                while (macConfigPtr[domainNum][masterNum] < FIREWALL_MASTER_MAXNUM)
                {
                    tempVal = REG_READ32(macBaseAddr + MAC_MDA_OFFSET_ADDR(macConfigPtr[domainNum][masterNum])) |
                              MAC_MDA_LOCK;
                    REG_WRITE32(tempVal, macBaseAddr + MAC_MDA_OFFSET_ADDR(macConfigPtr[domainNum][masterNum]));

                    ++masterNum;
                }
            } /* else not needed */
        }
    }

    return errId;
}

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
void Firewall_MacClearInterrupt(uint32 macBaseAddr)
{
    /* #10 Clear the interrupt of the MAC module. */
    /* Disable the interrupt of the mac. */
    REG_WRITE32(FIREWALL_REG_VALUE_MIN, macBaseAddr + MAC_FUNC_INT_STA_EN);
    /* Disable the interrupt signal of the mac. */
    REG_WRITE32(FIREWALL_REG_VALUE_MIN, macBaseAddr + MAC_FUNC_INT_SIG_EN);
    /* Clear the interrupt status of the mac. */
    REG_WRITE32(FIREWALL_REG_VALUE_MAX, macBaseAddr + MAC_FUNC_INT_STA);
}

#define FIREWALL_STOP_SEC_CODE
#include "Firewall_MemMap.h"

#ifdef __cplusplus
}
#endif
