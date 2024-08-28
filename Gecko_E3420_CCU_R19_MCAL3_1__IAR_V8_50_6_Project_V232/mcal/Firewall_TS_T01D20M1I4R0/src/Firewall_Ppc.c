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
 * \file     Firewall_Ppc.c                                                                             *
 * \brief    MCAL Firewall PPC Module Driver                                                            *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/24     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
#include "Firewall_PpcReg.h"
#include "Firewall_Ppc.h"
#include "Firewall_Cfg.h"
#include "Firewall_Ppc_Cfg.h"
#include "RegHelper.h"

#define FIREWALL_START_SEC_CODE
#include "Firewall_MemMap.h"
/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
static uint16 Firewall_PpcGetApbmuxIpMaxnum(uint8 ppcApbmuxId);
#if (STD_ON == FIREWALL_INTERRUPT_EN)
static void Firewall_PpcInterruptEnable(uint32 macBaseAddr);
#endif /** #if (STD_ON == FIREWALL_INTERRUPT_EN)*/
#if (STD_OFF == FIREWALL_RESPONSE_ERROR_EN)
static void Firewall_PpcResponseErrDisable(uint32 macBaseAddr);
#endif /** #if (STD_OFF == FIREWALL_RESPONSE_ERROR_EN)*/

/********************************************************************************************************
 *                                  Global Function Declarations                                        *
 *******************************************************************************************************/
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
Std_ReturnType Firewall_PpcIpConfigure(uint32 macBaseAddr, const Firewall_PpcIpConfigType *ppcIpCfgPtr, uint16 ppcIpNum)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;
    uint32 tempVal;
    uint16 ipNum;

    /* #10 Check the parameters. */
    if (NULL_PTR == ppcIpCfgPtr)
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else if (FIREWALL_PPC_IP_MAXNUM < ppcIpNum)
    {
        errId = (Std_ReturnType)FIREWALL_E_PPC_IP_NUM;
    }
    else
    {
        /* #20 Configure permissions of peripherals for every domain. */
        for (ipNum = 0U; ipNum < ppcIpNum; ++ipNum)
        {
            /* DOM0 all permissions is open */
            tempVal = (uint32)FIREWALL_PERMISSION_RW << FIREWALL_PPC_DOM0_PRIVILEGED_BIT;
            tempVal |= (uint32)FIREWALL_PERMISSION_RW << FIREWALL_PPC_DOM0_USER_BIT;

            /* DOM1 all permission is close */
            tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_PPC_DOM1_PRIVILEGED_BIT;
            tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_PPC_DOM1_USER_BIT;

            /* DOM2 SP0 permission */
            tempVal |= (uint32)ppcIpCfgPtr[ipNum].ppcSp0PrivilegedPermission << FIREWALL_PPC_DOM2_PRIVILEGED_BIT;
            tempVal |= (uint32)ppcIpCfgPtr[ipNum].ppcSp0UserPermission << FIREWALL_PPC_DOM2_USER_BIT;

#if (STD_OFF == FIREWALL_SP_LOCKSTEP_EN)
            /* DOM3 SP1 permission */
            tempVal |= (uint32)ppcIpCfgPtr[ipNum].ppcSp1PrivilegedPermission << FIREWALL_PPC_DOM3_PRIVILEGED_BIT;
            tempVal |= (uint32)ppcIpCfgPtr[ipNum].ppcSp1UserPermission << FIREWALL_PPC_DOM3_USER_BIT;
#endif /** #if (STD_OFF == FIREWALL_SP_LOCKSTEP_EN) */

            /* DOM0 ~ DOM3 permission set */
            REG_WRITE32(
                tempVal,
                FIREWALL_PPC_DOMPER0_ADDR(
                    macBaseAddr, (uint32)ppcIpCfgPtr[ipNum].ppcApbmuxId, (uint32)ppcIpCfgPtr[ipNum].ppcApbmuxIpId));

            /* DOM4 SX0 permission */
            tempVal = (uint32)ppcIpCfgPtr[ipNum].ppcSx0PrivilegedPermission << FIREWALL_PPC_DOM4_PRIVILEGED_BIT;
            tempVal |= (uint32)ppcIpCfgPtr[ipNum].ppcSx0UserPermission << FIREWALL_PPC_DOM4_USER_BIT;

#if (STD_OFF == FIREWALL_SX_LOCKSTEP_EN)
            /* DOM5 SX1 permission */
            tempVal |= (uint32)ppcIpCfgPtr[ipNum].ppcSx1PrivilegedPermission << FIREWALL_PPC_DOM5_PRIVILEGED_BIT;
            tempVal |= (uint32)ppcIpCfgPtr[ipNum].ppcSx1UserPermission << FIREWALL_PPC_DOM5_USER_BIT;
#endif /** #if (STD_OFF == FIREWALL_SX_LOCKSTEP_EN) */

            /* DOM6 DMA permission */
            tempVal |= (uint32)ppcIpCfgPtr[ipNum].ppcDmaPermission << FIREWALL_PPC_DOM6_PRIVILEGED_BIT;
            tempVal |= (uint32)ppcIpCfgPtr[ipNum].ppcDmaPermission << FIREWALL_PPC_DOM6_USER_BIT;

            /* DOM7 SF permission */
            tempVal |= (uint32)ppcIpCfgPtr[ipNum].ppcSfPrivilegedPermission << FIREWALL_PPC_DOM7_PRIVILEGED_BIT;
            tempVal |= (uint32)ppcIpCfgPtr[ipNum].ppcSfUserPermission << FIREWALL_PPC_DOM7_USER_BIT;

            /* DOM4 ~ DOM7 permission set */
            REG_WRITE32(
                tempVal,
                FIREWALL_PPC_DOMPER1_ADDR(
                    macBaseAddr, (uint32)ppcIpCfgPtr[ipNum].ppcApbmuxId, (uint32)ppcIpCfgPtr[ipNum].ppcApbmuxIpId));
        }

#if (STD_ON == FIREWALL_INTERRUPT_EN)
        /* #30 Turn on inturrupt when illegal access. */
        Firewall_PpcInterruptEnable(macBaseAddr);
#endif /** #if (STD_ON == FIREWALL_INTERRUPT_EN) */

#if (STD_OFF == FIREWALL_RESPONSE_ERROR_EN)
        /* #40 Disable respone error when illegal access. */
        Firewall_PpcResponseErrDisable(macBaseAddr);
#endif /** #if (STD_OFF == FIREWALL_RESPONSE_ERROR_EN) */
    }

    return errId;
}

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
                                         uint16 ppcAddrNum)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;
    uint16 ipMaxNum;
    uint16 addrNum;
    uint32 tempVal;

    /* #10 Check the parameters. */
    if (NULL_PTR == ppcAddrCfgPtr)
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else if (FIREWALL_PPC_REGION_MAXNUM < ppcAddrNum)
    {
        errId = (Std_ReturnType)FIREWALL_E_PPC_REGION_NUM;
    }
    else
    {
        /* #20 Configure permissions of apb regions for every domain. */
        for (addrNum = 0U; addrNum < ppcAddrNum; ++addrNum)
        {
            /* Get the maximum number of peripherals in the specified apbmux. */
            ipMaxNum = Firewall_PpcGetApbmuxIpMaxnum((uint8)ppcAddrCfgPtr[addrNum].ppcApbmuxId);

            /* DOM0 all permissions is open */
            tempVal = (uint32)FIREWALL_PERMISSION_RW << FIREWALL_PPC_DOM0_PRIVILEGED_BIT;
            tempVal |= (uint32)FIREWALL_PERMISSION_RW << FIREWALL_PPC_DOM0_USER_BIT;

            /* DOM1 all permissions is open */
            tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_PPC_DOM1_PRIVILEGED_BIT;
            tempVal |= (uint32)FIREWALL_PERMISSION_NONE << FIREWALL_PPC_DOM1_USER_BIT;

            /* DOM2 SP0 permission */
            tempVal |= (uint32)ppcAddrCfgPtr[addrNum].ppcSp0PrivilegedPermission << FIREWALL_PPC_DOM2_PRIVILEGED_BIT;
            tempVal |= (uint32)ppcAddrCfgPtr[addrNum].ppcSp0UserPermission << FIREWALL_PPC_DOM2_USER_BIT;

#if (STD_OFF == FIREWALL_SP_LOCKSTEP_EN)
            /* DOM3 SP1 permission */
            tempVal |= (uint32)ppcAddrCfgPtr[addrNum].ppcSp1PrivilegedPermission << FIREWALL_PPC_DOM3_PRIVILEGED_BIT;
            tempVal |= (uint32)ppcAddrCfgPtr[addrNum].ppcSp1UserPermission << FIREWALL_PPC_DOM3_USER_BIT;
#endif /** #if (STD_OFF == FIREWALL_SP_LOCKSTEP_EN) */

            /* DOM0 ~ DOM3 permission set */
            REG_WRITE32(tempVal,
                        FIREWALL_PPC_DOMPER0_ADDR(macBaseAddr,
                                                  (uint32)ppcAddrCfgPtr[addrNum].ppcApbmuxId,
                                                  (uint32)ppcAddrCfgPtr[addrNum].ppcRegionN + (uint32)ipMaxNum));

            /* DOM4 SX0 permission */
            tempVal = (uint32)ppcAddrCfgPtr[addrNum].ppcSx0PrivilegedPermission << FIREWALL_PPC_DOM4_PRIVILEGED_BIT;
            tempVal |= (uint32)ppcAddrCfgPtr[addrNum].ppcSx0UserPermission << FIREWALL_PPC_DOM4_USER_BIT;

#if (STD_OFF == FIREWALL_SX_LOCKSTEP_EN)
            /* DOM5 SX1 permission */
            tempVal |= (uint32)ppcAddrCfgPtr[addrNum].ppcSx1PrivilegedPermission << FIREWALL_PPC_DOM5_PRIVILEGED_BIT;
            tempVal |= (uint32)ppcAddrCfgPtr[addrNum].ppcSx1UserPermission << FIREWALL_PPC_DOM5_USER_BIT;
#endif /** #if (STD_OFF == FIREWALL_SX_LOCKSTEP_EN) */

            /* DOM6 DMA permission */
            tempVal |= (uint32)ppcAddrCfgPtr[addrNum].ppcDmaPermission << FIREWALL_PPC_DOM6_PRIVILEGED_BIT;
            tempVal |= (uint32)ppcAddrCfgPtr[addrNum].ppcDmaPermission << FIREWALL_PPC_DOM6_USER_BIT;

            /* DOM7 SF permission */
            tempVal |= (uint32)ppcAddrCfgPtr[addrNum].ppcSfPrivilegedPermission << FIREWALL_PPC_DOM7_PRIVILEGED_BIT;
            tempVal |= (uint32)ppcAddrCfgPtr[addrNum].ppcSfUserPermission << FIREWALL_PPC_DOM7_USER_BIT;

            /* DOM4 ~ DOM7 permission set */
            REG_WRITE32(tempVal,
                        FIREWALL_PPC_DOMPER1_ADDR(macBaseAddr,
                                                  (uint32)ppcAddrCfgPtr[addrNum].ppcApbmuxId,
                                                  (uint32)ppcAddrCfgPtr[addrNum].ppcRegionN + (uint32)ipMaxNum));

            /* Configure address range */
            REG_WRITE32(
                (uint32)FIREWALL_PPC_ADDR(ppcAddrCfgPtr[addrNum].ppcStartAddr) << FIREWALL_PPC_RGN_START_ADDR_BIT,
                FIREWALL_PPC_RGN_START_REG_ADDR(
                    macBaseAddr, (uint32)ppcAddrCfgPtr[addrNum].ppcApbmuxId, ppcAddrCfgPtr[addrNum].ppcRegionN));
            REG_WRITE32(
                (uint32)FIREWALL_PPC_ADDR(ppcAddrCfgPtr[addrNum].ppcEndAddr) << FIREWALL_PPC_RGN_END_ADDR_BIT,
                FIREWALL_PPC_RGN_END_REG_ADDR(
                    macBaseAddr, (uint32)ppcAddrCfgPtr[addrNum].ppcApbmuxId, ppcAddrCfgPtr[addrNum].ppcRegionN));

            /* Enable the region's configuration. */
            tempVal = REG_READ32(FIREWALL_PPC_RGN_END_REG_ADDR(
                macBaseAddr, (uint32)ppcAddrCfgPtr[addrNum].ppcApbmuxId, ppcAddrCfgPtr[addrNum].ppcRegionN));
            REG_WRITE32(
                (uint32)FIREWALL_PPC_RGN_EN | tempVal,
                FIREWALL_PPC_RGN_END_REG_ADDR(
                    macBaseAddr, (uint32)ppcAddrCfgPtr[addrNum].ppcApbmuxId, ppcAddrCfgPtr[addrNum].ppcRegionN));
        }

#if (STD_ON == FIREWALL_INTERRUPT_EN)
        /* #30 Turn on inturrupt when illegal access. */
        Firewall_PpcInterruptEnable(macBaseAddr);
#endif /** #if (STD_ON == FIREWALL_INTERRUPT_EN) */

#if (STD_OFF == FIREWALL_RESPONSE_ERROR_EN)
        /* #40 Disable respone error when illegal access. */
        Firewall_PpcResponseErrDisable(macBaseAddr);
#endif /** #if (STD_OFF == FIREWALL_RESPONSE_ERROR_EN) */
    }

    return errId;
}

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
void Firewall_PpcLock(uint32 macBaseAddr)
{
    uint32 ipNum;
    uint8 apbmuxNum;
    uint16 ipMaxNum;
    uint8 regionNum;
    uint32 tempVal;

    /* #10 Lock the configuarions of the PPC module. */
    for (apbmuxNum = 0U; apbmuxNum < FIREWALL_PPC_APBMUX_MAXNUM; apbmuxNum++)
    {
        ipMaxNum = Firewall_PpcGetApbmuxIpMaxnum(apbmuxNum);

        /* Lock permissions of all peripherals. */
        for (ipNum = 0U; ipNum < ipMaxNum; ipNum++)
        {
            REG_WRITE32((uint32)FIREWALL_PPC_PERMISSION_LOCK,
                        FIREWALL_PPC_DOM_PER_LOCK_ADDR(macBaseAddr, apbmuxNum, ipNum));
        }

        /* Lock permissions of all apb regions.
         * Lock address range of all apb regions.
         */
        for (regionNum = 0U; regionNum < FIREWALL_PPC_APBMUXREGION_MAXNUM; ++regionNum)
        {
            tempVal = REG_READ32(FIREWALL_PPC_RGN_END_REG_ADDR(macBaseAddr, apbmuxNum, regionNum));
            REG_WRITE32(tempVal | (uint32)FIREWALL_PPC_RGN_END_ADDR_LOCK,
                        FIREWALL_PPC_RGN_END_REG_ADDR(macBaseAddr, apbmuxNum, regionNum));

            REG_WRITE32((uint32)FIREWALL_PPC_PERMISSION_LOCK,
                        FIREWALL_PPC_DOM_PER_LOCK_ADDR(macBaseAddr, apbmuxNum, (uint32)ipMaxNum + (uint32)regionNum));
        }
    }
}

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
Firewall_PpcIrqStaType Firewall_PpcIrqHandler(uint32 macBaseAddr)
{
    Firewall_PpcIrqStaType IrqSta;
    uint8 apbmuxNum;
    uint32 staEn;
    uint32 sigEn;

    /* Struct variables need to be defined first and then assigned initial values to avoid linking to
        rodata section in some compiler */
    IrqSta.ppcApbmuxIpId = 0U;

    /* #10 Get the illegal access information from the PPC module interrupt. */
    for (apbmuxNum = 0U; apbmuxNum < FIREWALL_PPC_APBMUX_MAXNUM; ++apbmuxNum)
    {
        /* Get the interrupt status of the apbmux. */
        IrqSta.ppcErrSta = (REG_READ32(FIREWALL_PPC_FUNC_INT_STA_ADDR(macBaseAddr, apbmuxNum)) &
                            (FIREWALL_PPC_FUNC_INT_STA_REG_RES_ERR | FIREWALL_PPC_FUNC_INT_STA_PER_RES_ERR));

        if (0U < IrqSta.ppcErrSta)
        {
            /* Clear the interrupt status of the apbmux. */
            REG_WRITE32((uint32)IrqSta.ppcErrSta, FIREWALL_PPC_FUNC_INT_STA_ADDR(macBaseAddr, apbmuxNum));

            staEn = REG_READ32(FIREWALL_PPC_FUNC_INT_STA_EN_ADDR(macBaseAddr, apbmuxNum));
            sigEn = REG_READ32(FIREWALL_PPC_FUNC_INT_SIG_EN_ADDR(macBaseAddr, apbmuxNum));
            if (0U == ((uint32)IrqSta.ppcErrSta & staEn & sigEn))
            {
                IrqSta.ppcErrSta = 0U;
            }
            else
            {
                IrqSta.ppcApbmuxIpId = apbmuxNum;
            }

            break;
        } /* else not needed */
    }

    return IrqSta;
}

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
void Firewall_PpcClearInterrupt(uint32 macBaseAddr)
{
    uint8 apbmuxNum;

    /* #10 Clear the interrupt of all apbmuxs. */
    for (apbmuxNum = 0U; apbmuxNum < FIREWALL_PPC_APBMUX_MAXNUM; ++apbmuxNum)
    {
        /* Disable the interrupt of the apbmux. */
        REG_WRITE32(FIREWALL_REG_VALUE_MIN, FIREWALL_PPC_FUNC_INT_STA_EN_ADDR(macBaseAddr, apbmuxNum));
        /* Disable the interrupt signal of the apbmux. */
        REG_WRITE32(FIREWALL_REG_VALUE_MIN, FIREWALL_PPC_FUNC_INT_SIG_EN_ADDR(macBaseAddr, apbmuxNum));
        /* Clear the interrupt status of the apbmux. */
        REG_WRITE32(FIREWALL_REG_VALUE_MAX, FIREWALL_PPC_FUNC_INT_STA_ADDR(macBaseAddr, apbmuxNum));
    }
}

/** *****************************************************************************************************
 * \brief This function get the maximum number of peripherals in the specified apbmux.
 *
 * \verbatim
 * Syntax             : uint16 Firewall_PpcGetApbmuxIpMaxnum
 *                      (
 *                          uint8 ppcApbmuxId
 *                      )
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : ppcApbmuxId - The id of the specified apbmux
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : ipMaxNum - The maximum number of peripherals in the specified apbmux
 *
 * Description        : This function get the maximum number of peripherals in the specified apbmux.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_001
 *******************************************************************************************************/
static uint16 Firewall_PpcGetApbmuxIpMaxnum(uint8 ppcApbmuxId)
{
    uint16 ipMaxNum;

    /* #10 Get the maximum number of peripherals in the specified apbmux. */
    switch (ppcApbmuxId)
    {
        case 0:
        {
            ipMaxNum = FIREWALL_PPC_APBMUX1_IP_MAXNUM;
            break;
        }

        case 1:
        {
            ipMaxNum = FIREWALL_PPC_APBMUX2_IP_MAXNUM;
            break;
        }

        case 2:
        {
            ipMaxNum = FIREWALL_PPC_APBMUX3_IP_MAXNUM;
            break;
        }

        case 3:
        {
            ipMaxNum = FIREWALL_PPC_APBMUX4_IP_MAXNUM;
            break;
        }

        case 4:
        {
            ipMaxNum = FIREWALL_PPC_APBMUX5_IP_MAXNUM;
            break;
        }

        case 5:
        {
            ipMaxNum = FIREWALL_PPC_APBMUX6_IP_MAXNUM;
            break;
        }

        case 6:
        {
            ipMaxNum = FIREWALL_PPC_APBMUX7_IP_MAXNUM;
            break;
        }
        default:
        {
            ipMaxNum = 0U;
            break;
        }
    }

    return ipMaxNum;
}

#if (STD_ON == FIREWALL_INTERRUPT_EN)
/** *****************************************************************************************************
 * \brief This function enable the interrupt of illegal accessing for the PPC module.
 *
 * \verbatim
 * Syntax             : void Firewall_PpcInterruptEnable
 *                      (
 *                          uint32 macBaseAddr
 *                      )
 *
 * Service ID[hex]    : 0x00
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
 * Description        : This function enable the interrupt of illegal accessing for the PPC module.
 *                      This function should be called if FIREWALL_INTERRUPT_EN is STD_ON.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_017
 *******************************************************************************************************/
static void Firewall_PpcInterruptEnable(uint32 macBaseAddr)
{
    uint8 apbmuxNum;

    /* #10 Turn on inturrupt when illegal access. */
    for (apbmuxNum = 0; apbmuxNum < FIREWALL_PPC_APBMUX_MAXNUM; ++apbmuxNum)
    {
        REG_WRITE32(FIREWALL_PPC_FUNC_INT_STA_EN_PER_RES_ERR | FIREWALL_PPC_FUNC_INT_STA_EN_REG_RES_ERR,
                    FIREWALL_PPC_FUNC_INT_STA_EN_ADDR(macBaseAddr, apbmuxNum));
        REG_WRITE32(FIREWALL_PPC_FUNC_INT_SIG_EN_PER_RES_ERR | FIREWALL_PPC_FUNC_INT_SIG_EN_REG_RES_ERR,
                    FIREWALL_PPC_FUNC_INT_SIG_EN_ADDR(macBaseAddr, apbmuxNum));
    }
}
#endif /** #if (STD_ON == FIREWALL_INTERRUPT_EN) */

#if (STD_OFF == FIREWALL_RESPONSE_ERROR_EN)
/** *****************************************************************************************************
 * \brief This function disable the error response feature in the PPC module.
 *
 * \verbatim
 * Syntax             : void Firewall_PpcInterruptEnable
 *                      (
 *                          uint32 macBaseAddr
 *                      )
 *
 * Service ID[hex]    : 0x00
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
 * Description        : This function disable the error response to bus of illegal accessing to
 *                      peripherals in the PPC module.
 *                      This function should be called if FIREWALL_RESPONSE_ERROR_EN is STD_OFF.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_029
 *******************************************************************************************************/
static void Firewall_PpcResponseErrDisable(uint32 macBaseAddr)
{
    uint8 apbmuxNum;

    /* #10 Disable respone error when illegal access, and lock this configuarion. */
    for (apbmuxNum = 0; apbmuxNum < FIREWALL_PPC_APBMUX_MAXNUM; ++apbmuxNum)
    {
        /* Disable respone error. */
        REG_WRITE32((uint32)FIREWALL_PPC_PESP_ERR_DIS_ENABLE, FIREWALL_PPC_PESP_ERR_DIS_ADDR(macBaseAddr, apbmuxNum));

        /* lock the configuarion. */
        REG_WRITE32((uint32)FIREWALL_PPC_PESP_ERR_DIS_ENABLE | (uint32)FIREWALL_PPC_PESP_ERR_LOCK,
                    FIREWALL_PPC_PESP_ERR_DIS_ADDR(macBaseAddr, apbmuxNum));
    }
}
#endif /** #if (STD_OFF == FIREWALL_RESPONSE_ERROR_EN) */

#define FIREWALL_STOP_SEC_CODE
#include "Firewall_MemMap.h"

#ifdef __cplusplus
}
#endif
