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
 * \file     Firewall_Mpc.c                                                                             *
 * \brief    MCAL Firewall MPC Module Driver                                                            *
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
#include "Firewall_Mpc_Cfg.h"
#include "Firewall_Cfg.h"
#include "Firewall_MpcReg.h"
#include "Firewall_Mpc.h"
#include "RegHelper.h"

#define FIREWALL_START_SEC_CODE
#include "Firewall_MemMap.h"

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
static uint8 Firewall_MpcGetRegionMaxNum(uint16 baseOffset);
static Std_ReturnType Firewall_MpcRegionConfigure(uint32 macBaseAddr,
                                                  const Firewall_MpcMemPortConfigType *mpcMemPortCfgPtr);
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
                                     uint8 mpcMemPortNum)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;
    uint8 portNum;
    uint32 tempVal;

    /* #10 Check the parameters. */
    if (NULL_PTR == mpcMemPortCfgPtr)
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else if (FIREWALL_MPC_MEMPORT_MAXNUM < mpcMemPortNum)
    {
        errId = (Std_ReturnType)FIREWALL_E_MPC_PORT_NUM;
    }
    else
    {
        /* #20 Configure all memory ports. */
        for (portNum = 0U; portNum < mpcMemPortNum; ++portNum)
        {
            /* Disable sem error check. */
            if (FIREWALL_MPC_GAMA_ADDR_OFFSET == mpcMemPortCfgPtr[portNum].mpcBaseOffset)
            {
                tempVal = REG_READ32(FIREWALL_SCR_SF_BASE);
                REG_WRITE32(tempVal & (~FIREWALL_SCR_SF_APB_MAC_ENB_BIT), FIREWALL_SCR_SF_BASE);
            }
            /* Configure all regions of the memory port. */
            errId = Firewall_MpcRegionConfigure(macBaseAddr, &mpcMemPortCfgPtr[portNum]);
            if ((Std_ReturnType)E_OK != errId)
            {
                /* Enable sem error check. */
                if (FIREWALL_MPC_GAMA_ADDR_OFFSET == mpcMemPortCfgPtr[portNum].mpcBaseOffset)
                {
                    tempVal = REG_READ32(FIREWALL_SCR_SF_BASE);
                    REG_WRITE32(tempVal | FIREWALL_SCR_SF_APB_MAC_ENB_BIT, FIREWALL_SCR_SF_BASE);
                }
                break;
            } /* else not needed */
#if (STD_ON == FIREWALL_INTERRUPT_EN)
            if ((FIREWALL_MPC_VIC1_ADDR_OFFSET != mpcMemPortCfgPtr[portNum].mpcBaseOffset) &&
                (FIREWALL_MPC_VIC3A_ADDR_OFFSET != mpcMemPortCfgPtr[portNum].mpcBaseOffset) &&
                (FIREWALL_MPC_VIC3B_ADDR_OFFSET != mpcMemPortCfgPtr[portNum].mpcBaseOffset))
            {
                /* #30 Turn on inturrupt when illegal access. */
                REG_WRITE32(MPC_REG_ACS_ERR | MPC_MEM_ACS_ERR,
                            macBaseAddr + mpcMemPortCfgPtr[portNum].mpcBaseOffset + MPC_FUNC_INT_STA_EN);
                REG_WRITE32(MPC_REG_ACS_ERR | MPC_MEM_ACS_ERR,
                            macBaseAddr + mpcMemPortCfgPtr[portNum].mpcBaseOffset + MPC_FUNC_INT_SIG_EN);
            }
#endif /** #if (STD_ON == FIREWALL_INTERRUPT_EN) */

#if (STD_OFF == FIREWALL_RESPONSE_ERROR_EN)
            /* #40 Disable respone error when illegal access, and lock this configuration. */
            REG_WRITE32(MPC_RESP_ERR_DIS_DIS, macBaseAddr + mpcMemPortCfgPtr[portNum].mpcBaseOffset + MPC_RESP_ERR_DIS);
            REG_WRITE32(MPC_RESP_ERR_DIS_LOCK | MPC_RESP_ERR_DIS_DIS,
                        macBaseAddr + mpcMemPortCfgPtr[portNum].mpcBaseOffset + MPC_RESP_ERR_DIS);
#endif /** #if (STD_OFF == FIREWALL_RESPONSE_ERROR_EN) */

            /* Enable sem error check. */
            if (FIREWALL_MPC_GAMA_ADDR_OFFSET == mpcMemPortCfgPtr[portNum].mpcBaseOffset)
            {
                tempVal = REG_READ32(FIREWALL_SCR_SF_BASE);
                REG_WRITE32(tempVal | FIREWALL_SCR_SF_APB_MAC_ENB_BIT, FIREWALL_SCR_SF_BASE);
            }
        }
    }

    return errId;
}

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
                                      uint8 mpcMemPortNum, Firewall_MpcIrqStaType *mpcIrqSta)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;
    uint32 memPortBase;
    uint8 portNum;
    uint32 staEn;
    uint32 sigEn;
    uint32 tempVal;

    /* #10 Check the parameters. */
    if ((NULL_PTR == mpcMemPortCfgPtr) || (NULL_PTR == mpcIrqSta))
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else if (FIREWALL_MPC_MEMPORT_MAXNUM < mpcMemPortNum)
    {
        errId = (Std_ReturnType)FIREWALL_E_MPC_PORT_NUM;
    }
    else
    {
        /* #20 Get the illegal access information from the MPC module interrupt. */
        for (portNum = 0U; portNum < mpcMemPortNum; ++portNum)
        {
            /* Disable sem error check. */
            if (FIREWALL_MPC_GAMA_ADDR_OFFSET == mpcMemPortCfgPtr[portNum].mpcBaseOffset)
            {
                tempVal = REG_READ32(FIREWALL_SCR_SF_BASE);
                REG_WRITE32(tempVal & (~FIREWALL_SCR_SF_APB_MAC_ENB_BIT), FIREWALL_SCR_SF_BASE);
            }
            /* Get the interrupt status of the memory port. */
            memPortBase = macBaseAddr + mpcMemPortCfgPtr[portNum].mpcBaseOffset;
            mpcIrqSta->mpcErrSta = REG_READ32(memPortBase + MPC_FUNC_INT_STA);

            if (0U < mpcIrqSta->mpcErrSta)
            {
                /* Clear the interrupt status of the memory port. */
                REG_WRITE32(mpcIrqSta->mpcErrSta, memPortBase + MPC_FUNC_INT_STA);

                staEn = REG_READ32(memPortBase + MPC_FUNC_INT_STA_EN);
                sigEn = REG_READ32(memPortBase + MPC_FUNC_INT_SIG_EN);
                if (0U == ((uint32)mpcIrqSta->mpcErrSta & staEn & sigEn))
                {
                    mpcIrqSta->mpcErrSta = 0U;
                }
                else
                {
                    mpcIrqSta->mpcMemPortId = portNum;
                }

                /* Enable sem error check. */
                if (FIREWALL_MPC_GAMA_ADDR_OFFSET == mpcMemPortCfgPtr[portNum].mpcBaseOffset)
                {
                    tempVal = REG_READ32(FIREWALL_SCR_SF_BASE);
                    REG_WRITE32(tempVal | FIREWALL_SCR_SF_APB_MAC_ENB_BIT, FIREWALL_SCR_SF_BASE);
                }

                break;
            } /* else not needed */

            /* Enable sem error check. */
            if (FIREWALL_MPC_GAMA_ADDR_OFFSET == mpcMemPortCfgPtr[portNum].mpcBaseOffset)
            {
                tempVal = REG_READ32(FIREWALL_SCR_SF_BASE);
                REG_WRITE32(tempVal | FIREWALL_SCR_SF_APB_MAC_ENB_BIT, FIREWALL_SCR_SF_BASE);
            }
        }
    }

    return errId;
}

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
void Firewall_MpcClearInterrupt(uint32 macBaseAddr)
{
    uint32 tempVal;
    uint32 memPortBase;
    uint8 portNum;

    /* #10 Clear the interrupt of all memory ports. */
    for (portNum = 0U; portNum < FIREWALL_MPC_MEMPORT_MAXNUM; ++portNum)
    {
        if (FIREWALL_MPC_RESERVED_PORTID == portNum)
        {
            continue;
        }
        memPortBase = macBaseAddr + FIREWALL_MPC_ROMC_ADDR_OFFSET + MPC_FUNC_PORT_ADDR_SIZE(portNum);
        /* Disable the interrupt of the memory port. */
        REG_WRITE32(FIREWALL_REG_VALUE_MIN, memPortBase + MPC_FUNC_INT_STA_EN);
        /* Disable the interrupt signal of the memory port. */
        REG_WRITE32(FIREWALL_REG_VALUE_MIN, memPortBase + MPC_FUNC_INT_SIG_EN);
        /* Clear the interrupt status of the memory port. */
        REG_WRITE32(FIREWALL_REG_VALUE_MAX, memPortBase + MPC_FUNC_INT_STA);
    }
    /* Disable sem error check. */
    tempVal = REG_READ32(FIREWALL_SCR_SF_BASE);
    REG_WRITE32(tempVal & (~FIREWALL_SCR_SF_APB_MAC_ENB_BIT), FIREWALL_SCR_SF_BASE);

    memPortBase = macBaseAddr + FIREWALL_MPC_ROMC_ADDR_OFFSET + MPC_FUNC_PORT_ADDR_SIZE(FIREWALL_MPC_MEMPORT_MAXNUM);
    /* Disable the interrupt of the memory port. */
    REG_WRITE32(FIREWALL_REG_VALUE_MIN, memPortBase + MPC_FUNC_INT_STA_EN);
    /* Disable the interrupt signal of the memory port. */
    REG_WRITE32(FIREWALL_REG_VALUE_MIN, memPortBase + MPC_FUNC_INT_SIG_EN);
    /* Clear the interrupt status of the memory port. */
    REG_WRITE32(FIREWALL_REG_VALUE_MAX, memPortBase + MPC_FUNC_INT_STA);

    /* Enable sem error check. */
    tempVal = REG_READ32(FIREWALL_SCR_SF_BASE);
    REG_WRITE32(tempVal | FIREWALL_SCR_SF_APB_MAC_ENB_BIT, FIREWALL_SCR_SF_BASE);
}

/** *****************************************************************************************************
 * \brief This function get the maximum number of memory regions in the specified memory port.
 *
 * \verbatim
 * Syntax             : uint8 Firewall_MpcGetRegionMaxNum
 *                      (
 *                          uint16 baseOffset
 *                      )
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : baseOffset - The offset address of the memory port
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : regionMaxNum : The maximum number of memory regions in the specified memory port.
 *
 * Description        : This function get the maximum number of memory regions in the specified memory
 *                      port.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_010
 *******************************************************************************************************/
static uint8 Firewall_MpcGetRegionMaxNum(uint16 baseOffset)
{
    uint8 regionMaxNum;

    /* #10 Get the maximum number of the memory port. */
    switch (baseOffset)
    {
        case FIREWALL_MPC_ROMC_ADDR_OFFSET:
        {
            regionMaxNum = FIREWALL_MPC_ROM_MAXREGION;
            break;
        }
        /* The maximum number of regions in RAM port are same. */
        case FIREWALL_MPC_RAM1C_ADDR_OFFSET:
        case FIREWALL_MPC_RAM2C_ADDR_OFFSET:
        case FIREWALL_MPC_RAM3C_ADDR_OFFSET:
        case FIREWALL_MPC_RAM4C_ADDR_OFFSET:
        {
            regionMaxNum = FIREWALL_MPC_RAM_MAXREGION;
            break;
        }
        case FIREWALL_MPC_SDRAMC_ADDR_OFFSET:
        {
            regionMaxNum = FIREWALL_MPC_DRAM_MAXREGION;
            break;
        }
        /* The maximum number of regions in XSPI port are same. */
        case FIREWALL_MPC_XSPI1A_ADDR_OFFSET:
        case FIREWALL_MPC_XSPI1B_ADDR_OFFSET:
        case FIREWALL_MPC_XSPI2A_ADDR_OFFSET:
        case FIREWALL_MPC_XSPI2B_ADDR_OFFSET:
        {
            regionMaxNum = FIREWALL_MPC_XSPI_MAXREGION;
            break;
        }
        case FIREWALL_MPC_MB_ADDR_OFFSET:
        {
            regionMaxNum = FIREWALL_MPC_MB_MAXREGION;
            break;
        }
        /* The maximum number of regions in VIC port are same. */
        case FIREWALL_MPC_VIC1_ADDR_OFFSET:
        case FIREWALL_MPC_VIC2A_ADDR_OFFSET:
        case FIREWALL_MPC_VIC2B_ADDR_OFFSET:
        case FIREWALL_MPC_VIC3A_ADDR_OFFSET:
        case FIREWALL_MPC_VIC3B_ADDR_OFFSET:
        {
            regionMaxNum = FIREWALL_MPC_VIC_MAXREGION;
            break;
        }
        /* The maximum number of regions in CR5 CACHE/TCM port are same. */
        case FIREWALL_MPC_CR5SF_ADDR_OFFSET:
        case FIREWALL_MPC_CR5SP0_ADDR_OFFSET:
        case FIREWALL_MPC_CR5SP1_ADDR_OFFSET:
        case FIREWALL_MPC_CR5SX0_ADDR_OFFSET:
        case FIREWALL_MPC_CR5SX1_ADDR_OFFSET:
        {
            regionMaxNum = FIREWALL_MPC_CR5_MAXREGION;
            break;
        }
        case FIREWALL_MPC_SEIP_ADDR_OFFSET:
        {
            regionMaxNum = FIREWALL_MPC_SEIP_MAXREGION;
            break;
        }
        case FIREWALL_MPC_GAMA_ADDR_OFFSET:
        {
            regionMaxNum = FIREWALL_MPC_GAMA_MAXREGION;
            break;
        }
        default:
        {
            regionMaxNum = 0U;
            break;
        }
    }

    return regionMaxNum;
}

/** *****************************************************************************************************
 * \brief This function configure the permission of memory regions in MPC module.
 *
 * \verbatim
 * Syntax             : Std_ReturnType Firewall_MpcRegionConfigure
 *                      (
 *                          uint32 macBaseAddr,
 *                          const Firewall_MpcMemPortConfigType *mpcMemPortCfgPtr,
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
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : E_OK: Configurate MPC memory port success.
 *                      FIREWALL_E_NULL_POINTER: The pointer is a NULL_PTR.
 *                      FIREWALL_E_MPC_REGION_NUM: The number of memory regions is unvalid.
 *
 * Description        : This function configure memory regions in MPC module.
 *                      The permissions of memory regions in MPC module will be locked after configuring.
 *
 * \endverbatim
 * Traceability       : SWSR_FIREWALL_009 SWSR_FIREWALL_010 SM006
 *******************************************************************************************************/
static Std_ReturnType Firewall_MpcRegionConfigure(uint32 macBaseAddr,
                                                  const Firewall_MpcMemPortConfigType *mpcMemPortCfgPtr)
{
    Std_ReturnType errId = (Std_ReturnType)E_OK;
    const Firewall_MpcRegionConfigType *region;
    uint32 memPortBase;
    uint32 tempVal;
    uint8 num;

    /* #10 Check the parameters. */
    if (NULL_PTR == mpcMemPortCfgPtr)
    {
        errId = (Std_ReturnType)FIREWALL_E_NULL_POINTER;
    }
    else if (Firewall_MpcGetRegionMaxNum(mpcMemPortCfgPtr->mpcBaseOffset) < mpcMemPortCfgPtr->mpcRegionNum)
    {
        errId = (Std_ReturnType)FIREWALL_E_MPC_REGION_NUM;
    }
    else
    {
        memPortBase = macBaseAddr + mpcMemPortCfgPtr->mpcBaseOffset;
        /* #20 Configure all regions of the memory port. */
        for (num = 0U; num < mpcMemPortCfgPtr->mpcRegionNum; ++num)
        {
            region = &mpcMemPortCfgPtr->mpcRegionCfgPtr[num];

            /* Configure and lock the address range of the region. */
            REG_WRITE32(MPC_REGION_ADDR(region->mpcStartAddr), memPortBase + MPC_RGN_START_ADDR(num));
            REG_WRITE32(MPC_REGION_ADDR(region->mpcEndAddr), memPortBase + MPC_RGN_END_ADDR(num));
            REG_WRITE32(MPC_REGION_ADDR(region->mpcStartAddr), memPortBase + RGN_LOW_LIM(num));
            REG_WRITE32(MPC_REGION_ADDR(region->mpcEndAddr), memPortBase + RGN_UP_LIM(num));
            tempVal = MPC_REGION_ADDR(region->mpcEndAddr) | MPC_RGN_ENABLE;
            REG_WRITE32(tempVal, memPortBase + MPC_RGN_END_ADDR(num));
            tempVal |= MPC_RGN_LOCK;
            REG_WRITE32(tempVal, memPortBase + MPC_RGN_END_ADDR(num));

            /* Configure the permission of domain 0 - 3. */
            tempVal = (uint32)((uint32)region->mpcUnlockPermission << DOM_PER_DOMAIN0_BIT);
            tempVal |= (uint32)region->mpcLockPermission << DOM_PER_DOMAIN1_BIT;
            tempVal |= (uint32)region->mpcSp0Permission << DOM_PER_DOMAIN2_BIT;
            tempVal |= (uint32)region->mpcSp1Permission << DOM_PER_DOMAIN3_BIT;
            REG_WRITE32(tempVal, memPortBase + MPC_DOM_PER0(num));

            /* Configure the permission of domain 4 - 7. */
            tempVal = (uint32)((uint32)region->mpcSx0Permission << DOM_PER_DOMAIN4_BIT);
            tempVal |= (uint32)region->mpcSx1Permission << DOM_PER_DOMAIN5_BIT;
            tempVal |= (uint32)region->mpcDmaPermission << DOM_PER_DOMAIN6_BIT;
            tempVal |= (uint32)region->mpcSfPermission << DOM_PER_DOMAIN7_BIT;
            REG_WRITE32(tempVal, memPortBase + MPC_DOM_PER1(num));

            /* Lock the permission configuration of all domains. */
            tempVal = REG_READ32(memPortBase + MPC_DOM_PER_LOCK(num));
            REG_WRITE32(tempVal | MPC_DOM_PER_LOCK_MASK, memPortBase + MPC_DOM_PER_LOCK(num));
        }
    }

    return errId;
}

#define FIREWALL_STOP_SEC_CODE
#include "Firewall_MemMap.h"

#ifdef __cplusplus
}
#endif
