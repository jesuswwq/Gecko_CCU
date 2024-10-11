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
 * \file     Fls_IpDrv.c                                                                            *
 * \brief    AUTOSAR 4.3.1 MCAL fls Driver                                                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/26     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

#include <Fls_IpDrv.h>
#include <Fls_Ip.h>
#include "__regs_base.h"
#include "Fls.h"
#include "Fls_Cfg.h"
#include "Fls_Asm.h"

/* PRQA S 0306,0316,0326,0488,1505,3218,3387,3673,3678 EOF */

/********************************************************************************************************
 *                                 Private Macro definition                                             *
 *******************************************************************************************************/
/* default use direct read mode */
#ifndef FLS_IP_USE_DIRECT_MODE
#define FLS_IP_USE_DIRECT_MODE (1)
#endif /* #ifndef FLS_IP_USE_DIRECT_MODE */

/* default use prefetch */
#ifndef FLS_IP_USE_PREFETCH
#define FLS_IP_USE_PREFETCH (1)
#endif /* #ifndef FLS_IP_USE_PREFETCH */

#define FLS_BUS_XFER_COMPLETE (0x1u)

#define FLS_IP_READ_ADDR_ALIGNED (4UL)

#define FLS_IP_SCR_SF_BASE APB_SCR_SF_BASE
#define FLS_IP_SCR_TYPE_RW_REG_OFFSET (0x1000U)
#define FLS_IP_SCR_TYPE_L31_REG_OFFSET (0x1400U)

#define FLS_IP_RESET_CONTROL_OFF(n)          (0x1304U + (8U*(n)))
#define FLS_IP_RESET_CONTROL_RSTA            (29)
#define FLS_IP_RESET_CONTROL_MASK            (0x07U)
#define FLS_IP_RESET_CONTROL_POLLS           (0x10000U)

#define FLS_IP_XFER_TIMEOUT_CYCLES           (1000000U)

#define FLS_IP_PMU_LOOPS                     (100U)
#define FLS_IP_PMU_MAX_DELAY_TIME            (21000000UL)

#define FLS_PMU_EN_CYCLE  (0x80000000u)
#define FLS_PMU_US_TO_TICK(us)  \
        ((uint32)(((us) * (FLS_IP_CPU_FREQUENCY_MHZ / 4U)) / 16U))


#if defined SEMIDRIVE_E3_SERIES
#define FLS_IP_LOCKSTEP_START_BIT_ARRAY \
{\
    258u, 290u  \
}

#define FLS_IP_PARALLEL_MODE_START_BIT_ARRAY \
{\
    257u, 289u  \
}

#define FLS_IP_RESET_IDS_ARRAY \
{\
    10u, 11u, 12u, 13u  \
}

#define FLS_IP_APB_SRC_IRQ_ENB \
{\
    352, 356, 360, 364 \
}

#define FLS_IP_APB_SRC_UNCERR_CLR \
{\
    353, 357, 361, 365 \
}

#define FLS_IP_APB_DST_IRQ_ENB \
{\
    354u, 358, 362, 366  \
}

#define FLS_IP_APB_DST_UNCERR_CLR \
{\
    355, 359, 363, 367  \
}

#else
#define FLS_IP_LOCKSTEP_START_BIT_ARRAY \
{\
    34u  \
}

#define FLS_IP_PARALLEL_MODE_START_BIT_ARRAY \
{\
    33u  \
}

#define FLS_IP_RESET_IDS_ARRAY \
{\
    8u, 9u  \
}

#define FLS_IP_APB_SRC_IRQ_ENB \
{\
    192, 196 \
}

#define FLS_IP_APB_SRC_UNCERR_CLR \
{\
    193, 197 \
}

#define FLS_IP_APB_DST_IRQ_ENB \
{\
    194u, 198u  \
}

#define FLS_IP_APB_DST_UNCERR_CLR \
{\
    195, 199 \
}

#endif /* #if defined SEMIDRIVE_E3_SERIES */

#if (FLS_IP_USE_IRQ != 0)
#define FLS_IP_IRQ_HANDLER(n) \
FLS_IP_IRQ_HANDLER_FUNC(n)\
{\
    if ((NULL_PTR != Fls_ConfigPtr) &&\
        (NULL_PTR != Fls_ConfigPtr->controllerTable[n].pointerContex)) {\
        (void) Fls_IpIrqHandler(n,\
            &(Fls_ConfigPtr->controllerTable[n].pointerContex->host));\
    }\
}
#endif /* #if (FLS_IP_USE_IRQ != 0) */

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

static int Fls_IpCommandRead(Fls_BusHandleType *nor, Fls_BusCommandType *cmd,
                             Fls_AddressType addr, uint8 *buf, Fls_LengthType len);
static int Fls_IpCommandWrite(Fls_BusHandleType *nor, Fls_BusCommandType *cmd,
                              Fls_AddressType addr, const uint8 *buf,
                              Fls_LengthType len);
static int Fls_IpRead(Fls_BusHandleType *nor, Fls_AddressType addr, uint8 *buf,
                      Fls_LengthType size);
static int Fls_IpWrite(Fls_BusHandleType *nor, Fls_AddressType addr,
                       const uint8 *buf, Fls_LengthType size);
#ifdef FLS_SPIBUS_FLASH_CNT
static int Fls_IpErase(Fls_BusHandleType *nor, Fls_AddressType offset);
#endif /* #ifdef FLS_SPIBUS_FLASH_CNT */
static int Fls_IpTraining(Fls_BusHandleType *nor, Fls_AddressType addr,
                          uint8 *buf, const uint8 *pattern,
                          Fls_LengthType size);
static int Fls_IpLock(Fls_BusHandleType *nor, Fls_BusOpsType ops);
static void Fls_IpUnlock(Fls_BusHandleType *nor, Fls_BusOpsType ops);
static void Fls_IpCacheFlush(Fls_BusHandleType *nor, Fls_AddressType addr,
                             Fls_LengthType length);
#ifdef FLS_HYPERBUS_FLASH_CNT
static int Fls_IpRead16(Fls_BusHandleType *nor, Fls_AddressType addr, uint16 *buf);
static int Fls_IpWrite16(Fls_BusHandleType *nor, Fls_AddressType addr, uint16 *buf);
static void Fls_IpSetPreTransaction(Fls_BusHandleType *nor, boolean isRead,
                                    boolean isDirect, uint32 num, Fls_HyperbusCaType **caArray);
#endif /* #ifdef FLS_HYPERBUS_FLASH_CNT */
static int Fls_IpEnterXipMode(Fls_BusHandleType *handle, boolean enable);

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

/********************************************************************************************************
 *                                  Private Variable Definitions                                        *
 *******************************************************************************************************/
#define FLS_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

static Fls_IpContextType Fls_IpContextTable[FLS_CONTROLLER_ID_MAX];

static uint32 Fls_IpEnableEvent;

static uint32 Fls_IpLockstepErr;

#define FLS_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

#define FLS_START_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

static Fls_IpConfigType Fls_IpConfigTable[FLS_CONTROLLER_ID_MAX] =
{
    [FLS_XSPI1_PORTA] = {
        .id = (uint8)FLS_XSPI1_PORTA,
        .apbBase = APB_XSPI1PORTA_BASE,
        .directBase = XSPI1_XSPI1PORTA_BASE,
    },
    [FLS_XSPI1_PORTB] = {
        .id = (uint8)FLS_XSPI1_PORTB,
        .apbBase = APB_XSPI1PORTB_BASE,
        .directBase = XSPI1_XSPI1PORTB_BASE,
    },
#if (FLS_IP_RESOURE_NUM >= 2)
    [FLS_XSPI2_PORTA] = {
        .id = (uint8)FLS_XSPI2_PORTA,
        .apbBase = APB_XSPI2PORTA_BASE,
        .directBase = XSPI2_XSPI2PORTA_BASE,
    },
    [FLS_XSPI2_PORTB] = {
        .id = (uint8)FLS_XSPI2_PORTB,
        .apbBase = APB_XSPI2PORTB_BASE,
        .directBase = XSPI2_XSPI2PORTB_BASE,
    },
#endif /* #if (FLS_IP_RESOURE_NUM >= 2) */
};

static uint32 Fls_IpResetIds[] = FLS_IP_RESET_IDS_ARRAY;
static uint32 Fls_IpApbSrcIrqEnStartBit[] = FLS_IP_APB_SRC_IRQ_ENB;
static uint32 Fls_IpApbSrcUncerrClrStartBit[] = FLS_IP_APB_SRC_UNCERR_CLR;
static uint32 Fls_IpApbDstIrqEnStartBit[] = FLS_IP_APB_DST_IRQ_ENB;
static uint32 Fls_IpApbDstUncerrClrStartBit[] = FLS_IP_APB_DST_UNCERR_CLR;
static uint32 Fls_IpLockstepStartBit[] = FLS_IP_LOCKSTEP_START_BIT_ARRAY;
static uint32 Fls_IpParallelStartBit[] = FLS_IP_PARALLEL_MODE_START_BIT_ARRAY;

static Fls_IpHostOpsType Fls_IpHostOps =
{
    .regRead = Fls_IpCommandRead,
    .regWrite = Fls_IpCommandWrite,
    .read = Fls_IpRead,
    .write = Fls_IpWrite,
#ifdef FLS_SPIBUS_FLASH_CNT
    .erase = Fls_IpErase,
#endif /* #ifdef FLS_SPIBUS_FLASH_CNT */
    .training = Fls_IpTraining,
    .prepare = Fls_IpLock,
    .unprepare = Fls_IpUnlock,
    .cacheFlush = Fls_IpCacheFlush,
#ifdef FLS_RFD_ENABLE_CNT
    .enableRfd = Fls_IpRfdEnable,
#endif /* #ifdef FLS_RFD_ENABLE_CNT */
#ifdef FLS_HYPERBUS_FLASH_CNT
    .read16 = Fls_IpRead16,
    .write16 = Fls_IpWrite16,
    .hyperramEnable = Fls_IpHyperramEnable,
    .setPreTransaction = Fls_IpSetPreTransaction,
#endif /* #ifdef FLS_HYPERBUS_FLASH_CNT */
    .enterXipMode = Fls_IpEnterXipMode,
};

#define FLS_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "Fls_MemMap.h"

/********************************************************************************************************
 *                                  Private Function Declarations                                       *
 *******************************************************************************************************/
#define FLS_START_SEC_CODE
#include "Fls_MemMap.h"

/** *****************************************************************************************************
 * \brief This function Configure registers for SCR.
 *
 * \verbatim
 * Syntax             : void Fls_IpScrSetBit(
 *                          uint32 startBit, uint32 offset, uint32 width, uint32 value)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : startBit - The starting bit of the SCR
 *                      offset - The register offset for different type
 *                      width - Width of configuration bits
 *                      value - Value of configuration bits
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configure registers for SCR
 * \endverbatim
 * Traceability       : SWSR_FLS_169
 *******************************************************************************************************/
static void Fls_IpScrSetBit(uint32 startBit, uint32 typeOffset, uint32 width, uint32 value)
{
    uint32 start = startBit & 0x1FU;
    uint32 regOffset = FLS_IP_SCR_SF_BASE + typeOffset + ((startBit >> 5) * 4U);
    uint32 val = REG_READ32(regOffset);

    if (0U == (val & FLS_BIT(31)))   /* Is locked */
    {
        REG_RMW32(regOffset, start, width, value);
    }
}

/** *****************************************************************************************************
 * \brief This function reset the IP module.
 *
 * \verbatim
 * Syntax             : int Fls_IpModuleReset(
 *                          uint32 id, boolean runMode)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : id - The id of reset control
 *                      runMode - Switch of reset mode
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Timeout
 *
 * Description        : Reset the IP module
 * \endverbatim
 * Traceability       : SWSR_FLS_169
 *******************************************************************************************************/
static int Fls_IpModuleReset(uint8 id, boolean runMode)
{
    uint32 moduleRstRegBase = APB_RSTGEN_SF_BASE + FLS_IP_RESET_CONTROL_OFF(Fls_IpResetIds[id]);
    uint32 val = readl(moduleRstRegBase);
    int ret;

    if (TRUE == runMode)
    {
        val |= FLS_IP_RESET_CONTROL_MASK;
    }
    else
    {
        val &= (~FLS_IP_RESET_CONTROL_MASK);
        Fls_IpScrSetBit(Fls_IpApbSrcIrqEnStartBit[id], FLS_IP_SCR_TYPE_RW_REG_OFFSET, 1U, 0U);
        Fls_IpScrSetBit(Fls_IpApbDstIrqEnStartBit[id], FLS_IP_SCR_TYPE_RW_REG_OFFSET, 1U, 0U);

        /* workaround: Ensure that the last operation before reset is a read.
           xspi aapb's master and slave sides are connected to different resets, resulting in
           xspi ip reset aapb only slave side is reset, master side free run. after the reset is
           released, aapb slave side mistakenly believes that there is a transmission needs to be
           sent to xspi, and at the same time, it will produce a aapb unc_err_irq
        */
        (void) readl(Fls_IpConfigTable[id].apbBase);

    }

    writel(val, moduleRstRegBase);

    ret = Fls_IpWaitForBitTimes(moduleRstRegBase, ((uint32)0x1u) << FLS_IP_RESET_CONTROL_RSTA,
                                 (TRUE == runMode) ? FALSE : TRUE, FLS_IP_RESET_CONTROL_POLLS);

    if (TRUE == runMode)
    {
        Fls_IpDelayUs(10);
        /* workaround: SEM errors may occur on the first apb visit
        */
        (void) readl(Fls_IpConfigTable[id].apbBase);

        Fls_IpScrSetBit(Fls_IpApbSrcUncerrClrStartBit[id], FLS_IP_SCR_TYPE_RW_REG_OFFSET, 1U, 1U);
        Fls_IpScrSetBit(Fls_IpApbSrcUncerrClrStartBit[id], FLS_IP_SCR_TYPE_RW_REG_OFFSET, 1U, 0U);
        Fls_IpScrSetBit(Fls_IpApbDstUncerrClrStartBit[id], FLS_IP_SCR_TYPE_RW_REG_OFFSET, 1U, 1U);
        Fls_IpScrSetBit(Fls_IpApbDstUncerrClrStartBit[id], FLS_IP_SCR_TYPE_RW_REG_OFFSET, 1U, 0U);

        Fls_IpScrSetBit(Fls_IpApbSrcIrqEnStartBit[id], FLS_IP_SCR_TYPE_RW_REG_OFFSET, 1U, 1U);
        Fls_IpScrSetBit(Fls_IpApbDstIrqEnStartBit[id], FLS_IP_SCR_TYPE_RW_REG_OFFSET, 1U, 1U);
    }
    return ret;
}

/** *****************************************************************************************************
 * \brief This function Configure the controller to lockstep mode or parallel mode.
 *
 * \verbatim
 * Syntax             : int Fls_IpModeEnable(
 *                          boolean lockstepEn, boolean parallelEn, uint8 id)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : lockstepEn - Switch of lockstep mode
 *                      parallelEn - Switch of parallel mode
 *                      id - The ID of the controller port
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure the controller to lockstep mode or parallel mode.
 *
 * \endverbatim
 * Traceability       : SWSR_FLS_169
 *******************************************************************************************************/
static int Fls_IpModeEnable(boolean lockstepEn, boolean parallelEn, uint8 id)
{
    uint8 index = id >> 1;
    boolean isPortA = (0U == (id % 2U)) ? TRUE : FALSE;

    int ret = -1;

    if (index >= (ARRAY_SIZE(Fls_IpLockstepStartBit)))
    {
        FLS_DEBUG("xspi %d unsupport switch mode\n", id);
    }
    else if ((TRUE == lockstepEn) && (TRUE == parallelEn))
    {
        FLS_DEBUG("xspi %d cannot support both modes simultaneously\n", id);
    }
    else
    {
        (void) Fls_IpModuleReset(id, FALSE);

        if (TRUE == isPortA)   /* Is portA */
        {
            if ((TRUE == lockstepEn) || (TRUE == parallelEn))
            {
                (void)Fls_IpModuleReset(id + 1U, FALSE);
            }
        }

        Fls_IpDelayUs(10);
        Fls_IpScrSetBit(Fls_IpLockstepStartBit[index], FLS_IP_SCR_TYPE_L31_REG_OFFSET, 1U, (TRUE == lockstepEn) ? 0U : 1U);
        Fls_IpScrSetBit(Fls_IpParallelStartBit[index], FLS_IP_SCR_TYPE_L31_REG_OFFSET, 1U, parallelEn);
        Fls_IpDelayUs(10);
        (void) Fls_IpModuleReset(id, TRUE);

        if (TRUE == isPortA)   /* Is portA */
        {
            if ((TRUE == lockstepEn) || (TRUE == parallelEn))
            {
                (void) Fls_IpModuleReset(id + 1U, TRUE);
            }
        }

        ret = 0;
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function returns the result of compromise algorithm with the input value
 *
 * \verbatim
 * Syntax             : uint8 Fls_IpCompromiseAlg(
 *                          unsigned int x)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : x - Value to be calculated
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Calculation results
 *
 * Description        : Calculate the power value of a quadratic power closest to the input value
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static uint8 Fls_IpCompromiseAlg(unsigned int x)
{
    uint8 left = 0U, right = 31U, mid;

    while (left < right)
    {
        mid = (left + right) >> 1;

        if (0U != ((0xffffffffU - (((uint32)1u << (mid + 1U)) - 1U)) & x))
        {
            left = mid + 1U;
        }
        else if (0U != (x & ((uint32)1U << mid)))
        {
            left = mid;
            break;
        }
        else
        {
            right = mid - 1U;
        }
    }

    return left;
}

/** *****************************************************************************************************
 * \brief This function polling once for read/write operations.
 *
 * \verbatim
 * Syntax             : int Fls_IpPollingHandler(
 *                          void *arg)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : arg - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Controller access to polling once for read/write operations
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpPollingHandler(void *arg)
{
    int ret = -1;
    Fls_BusHandleType *nor = (Fls_BusHandleType *)arg;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;

    if (FLS_BUS_OPS_PENDING == nor->xferInfoBottom.opsResult)
    {
        if (FLS_BUS_OPS_READ == nor->xferInfoBottom.opsType)
        {
            ret = Fls_IpRxPolling(nor);
        }
        else if (FLS_BUS_OPS_WRITE == nor->xferInfoBottom.opsType)
        {
            ret = Fls_IpTxPolling(nor);
        }
        else
        {
            /* Do nothing */
        }
    }

    nor->xferInfoBottom.opsResult = (0 != ret) ? FLS_BUS_OPS_FAILED : FLS_BUS_OPS_PENDING;

    if ((0U == nor->xferInfoBottom.size) &&
            (FLS_BUS_OPS_PENDING == nor->xferInfoBottom.opsResult))
    {
        nor->xferInfoBottom.opsResult = FLS_BUS_OPS_COMPLETE;

        if ((FLS_BUS_XFER_POLLING_MODE == nor->xferMode)
                || (FLS_BUS_OPS_READ == nor->xferInfoBottom.opsType))
        {
            Fls_IpWritel(ipCtx, FLS_IP_INT_EN_FUC, 0u);

            if (NULL_PTR != nor->eventHandler)
            {
                nor->eventHandler(nor->xferInfoBottom.opsType, nor->xferInfoBottom.opsResult);
            }

            Fls_IpEnableEvent = 1U;
        }
    }
    else if (FLS_BUS_OPS_FAILED == nor->xferInfoBottom.opsResult)
    {
        if (NULL_PTR != nor->eventHandler)
        {
            nor->eventHandler(nor->xferInfoBottom.opsType, nor->xferInfoBottom.opsResult);
        }

        Fls_IpEnableEvent = 1U;
    }
    else
    {
        /* Do nothing */
    }

    return (int)nor->xferInfoBottom.opsResult;
}

/** *****************************************************************************************************
 * \brief This function Block waiting for the operation to complete until timeout.
 *
 * \verbatim
 * Syntax             : void Fls_IpWaitXferDone(
 *                          Fls_BusHandleType *nor)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Block waiting for the operation to complete until timeout.
 *                      If in polling mode, call the controller's polling handle to
 *                      complete the operation.
 * \endverbatim
 * Traceability       : SWSR_FLS_166
 *******************************************************************************************************/
static void Fls_IpWaitXferDone(Fls_BusHandleType *nor)
{
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;
    uint32 tryCount = 0;

    if (nor->xferMode != FLS_BUS_XFER_POLLING_MODE)
    {
        while ((0U == Fls_IpEnableEvent) && (tryCount < FLS_IP_XFER_TIMEOUT_CYCLES))
        {
            Fls_IpDelayUs(1);  // wait 1s for indirect write(<=256B) or read(nB)
            tryCount++;
        }

        if (tryCount >= FLS_IP_XFER_TIMEOUT_CYCLES)
        {
            FLS_DEBUG("xspi wait 0x%u us, exit\n", tryCount);
            nor->xferInfoBottom.opsResult = FLS_BUS_OPS_FAILED;
        }

        Fls_IpEnableEvent = 0U;
        Fls_IpLockstepErr = Fls_IpReadl(ipCtx, FLS_IP_LSP_ERR_ST);

        if (0U != Fls_IpLockstepErr)
        {
            Fls_IpWritel(ipCtx, FLS_IP_LSP_ERR_ST, Fls_IpLockstepErr);
            FLS_DEBUG("xspi lsp error status = 0x%x\n", Fls_IpLockstepErr);
        }
    }
    else
    {
        for (tryCount = 0; tryCount < FLS_IP_XFER_TIMEOUT_CYCLES; tryCount++)
        {
            (void) Fls_IpPollingHandler((void *)(Fls_PointerType)nor);

            if (0U != Fls_IpEnableEvent)
            {
                Fls_IpEnableEvent = 0U;
                Fls_IpLockstepErr = Fls_IpReadl(ipCtx, FLS_IP_LSP_ERR_ST);

                if (0U != Fls_IpLockstepErr)
                {
                    Fls_IpWritel(ipCtx, FLS_IP_LSP_ERR_ST, Fls_IpLockstepErr);
                    FLS_DEBUG("xspi lsp error status = 0x%x\n", Fls_IpLockstepErr);
                }

                break;
            }
        }

        if (tryCount >= FLS_IP_XFER_TIMEOUT_CYCLES)
        {
            nor->xferInfoBottom.opsResult = FLS_BUS_OPS_FAILED;
            FLS_DEBUG("xspi polling 0x%u times, exit\n", tryCount);
        }
    }

    Fls_IpReleaseXfer(nor);
}

/** *****************************************************************************************************
 * \brief This function recombine input data in parallel mode.
 *
 * \verbatim
 * Syntax             : void Fls_IpParallelDataPrepare(
 *                          const uint8 *raw, uint8 *dst, uint32 len)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : raw - Pointer to source buffer
 *                      dst - Pointer to target buffer
 *                      len - Target buffer size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Recombine input data in parallel mode.
 *                      Data is repeated for each byte to ensure that the two flash devices receive
 *                      the same data
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpParallelDataPrepare(const uint8 *raw, uint8 *dst, uint32 len)
{
    uint32 i;

    if ((raw != NULL_PTR) && (dst != NULL_PTR))
    {
        for (i = 0U; i < (len >> 1); i++)
        {
            *(dst + (2U * i)) = *(raw + i);
            *(dst + (2U * i) + 1U) = *(raw + i);
        }
    }
}

/** *****************************************************************************************************
 * \brief This function Parsing input data with parallel mode.
 *
 * \verbatim
 * Syntax             : void Fls_IpParallelDataParse(
 *                          const uint8 *raw, uint8 *dst, uint32 len)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : raw - Pointer to source buffer
 *                      dst - Pointer to target buffer
 *                      len - Source buffer size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Parsing input data with parallel mode.
 *                      Determines whether the data of adjacent bytes is the same and copies
 *                      one byte to the target buffer
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpParallelDataParse(const uint8 *raw, uint8 *dst, uint32 len)
{
    uint32 i;
    int ret = 0;

    if ((raw != NULL_PTR) && (dst != NULL_PTR))
    {
        for (i = 0U; i < (len >> 1); i++)
        {
            if (*(raw + (2U * i)) != *(raw + (2U * i) + 1U))
            {
                FLS_DEBUG("xspi parallel read register data error!\n");
                ret = -1;
            }

            *(dst + i) = *(raw + (2U * i));
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function use the specified command to read data from Flash.
 *
 * \verbatim
 * Syntax             : int Fls_IpCommandRead(
 *                          Fls_BusHandleType *nor, Fls_BusCommandType *cmd,
 *                          Fls_AddressType addr, uint8 *buf, Fls_LengthType len)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      cmd - Pointer to Special command configuration information
 *                      addr - Reading address
 *                      len - Reading size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Reading data from Flash with specified command which Specify parameters
 *                      such as opcode dummy etc.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpCommandRead(Fls_BusHandleType *nor, Fls_BusCommandType *cmd,
                             Fls_AddressType addr, uint8 *buf, Fls_LengthType len)
{
    uint32 irqTrigLevel;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;
    uint8 *ptr = buf;
    uint8 localBuffer[32] = {0};
    Fls_LengthType readLength = len;
    Fls_AddressType readAddress = addr;
    int ret = 0;

    if (FLS_BUS_DEV_PARALLEL_MODE == nor->devMode)
    {
        ptr = localBuffer;
        readLength = FLS_MAX((uint32)4u, len * 2U);
        readAddress = 2u * addr;
    }
    else if (FLS_BUS_DEV_SWITCH_MODE == nor->devMode)
    {
        readAddress += nor->info.regOffset;
    }
    else
    {
        /* Do nothing */
    }

    Fls_IpSetupXfer(nor, FLS_BUS_OPS_READ, readAddress, ptr, NULL_PTR, readLength);

    Fls_IpProtocolSetup(nor, cmd, FLS_IP_INDIRECT_ACCESS_MODE,
                        FLS_BUS_OPS_READ);

    irqTrigLevel = FLS_MIN((uint32)ipCtx->fifoDepth / 2UL, FLS_DIV_ROUND_UP(readLength, 4UL));

    Fls_IpWriteBits(ipCtx, FLS_IP_INDIRECT_RD_DMA,
                    FLS_IP_INDIRECT_DMA_TRIG_WML_LSB, 8u, irqTrigLevel);

    Fls_IpSetInterruptMask(ipCtx, FLS_IP_INT_EN_FUC, FLS_IP_INT_ST_FUC_RX_FRE_FULL |
                           FLS_IP_INT_ST_FUC_INDIRECT_RD_DONE);

    Fls_IpIndirectTrigger(ipCtx, readAddress, readLength, INDIRECT_READ_FLAG);

    Fls_IpWaitXferDone(nor);

    if (FLS_BUS_OPS_FAILED == nor->xferInfoBottom.opsResult)
    {
        ret = -1;
    }
    else if (FLS_BUS_DEV_PARALLEL_MODE == nor->devMode)
    {
        ret = Fls_IpParallelDataParse(localBuffer, buf, readLength);
    }
    else
    {
        /* Do nothing */
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function use the specified command to write data to Flash.
 *
 * \verbatim
 * Syntax             : int Fls_IpCommandWrite(
 *                          Fls_BusHandleType *nor, Fls_BusCommandType *cmd,
 *                          Fls_AddressType addr, uint8 *buf, Fls_LengthType len)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      cmd - Pointer to Special command configuration information
 *                      addr - Writing address
 *                      len - Writing size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Writing data to Flash with specified command which Specify parameters
 *                      such as opcode dummy etc.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpCommandWrite(Fls_BusHandleType *nor, Fls_BusCommandType *cmd,
                              Fls_AddressType addr, const uint8 *buf,
                              Fls_LengthType len)
{
    uint32 txSize;
    uint32 irqTrigLevel;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;
    const uint8 *ptr = buf;
    uint8 localBuffer[32] = {0};
    Fls_LengthType writeLength = len;
    Fls_AddressType writeAddress = addr;
    int ret = 0;

    if (FLS_BUS_DEV_PARALLEL_MODE == nor->devMode)
    {
        if (len != 0u)
        {
            writeLength = len * 2u;
            Fls_IpParallelDataPrepare(buf, localBuffer, writeLength);
            ptr = localBuffer;
        }

        writeAddress = addr * 2u;
    }
    else if (FLS_BUS_DEV_SWITCH_MODE == nor->devMode)
    {
        writeAddress += nor->info.regOffset;
    }
    else
    {
        /* Do nothing */
    }

    Fls_IpSetupXfer(nor, FLS_BUS_OPS_WRITE, writeAddress, NULL_PTR, ptr, writeLength);

    Fls_IpProtocolSetup(nor, cmd, FLS_IP_INDIRECT_ACCESS_MODE, FLS_BUS_OPS_WRITE);

    if ((NULL_PTR != nor->xferInfoBottom.writeBuf) &&
            (nor->xferInfoBottom.size > 0u))
    {
        txSize = Fls_IpWriteFifo(ipCtx, nor->xferInfoBottom.writeBuf,
                                 nor->xferInfoBottom.size);
        nor->xferInfoBottom.writeBuf += txSize;
        nor->xferInfoBottom.size -= txSize;
    }

    Fls_IpIndirectTrigger(ipCtx, writeAddress, writeLength, INDIRECT_WRITE_FLAG);

    Fls_IpSetInterruptMask(ipCtx, FLS_IP_INT_EN_FUC, FLS_IP_INT_ST_FUC_INDIRECT_WR_DONE);

    if (buf != NULL_PTR)
    {
        irqTrigLevel = FLS_MIN(ipCtx->fifoDepth, FLS_DIV_ROUND_UP(writeLength, 4u));

        Fls_IpWriteBits(ipCtx, FLS_IP_INDIRECT_WR_DMA,
                        FLS_IP_INDIRECT_DMA_TRIG_WML_LSB, 8u, irqTrigLevel);
    }

    Fls_IpWaitXferDone(nor);

    if (FLS_BUS_OPS_FAILED == nor->xferInfoBottom.opsResult)
    {
        ret = -1;
    }

    return ret;
}

#if (FLS_IP_USE_IRQ != 0)
/** *****************************************************************************************************
 * \brief This function is interrupt handling process.
 *
 * \verbatim
 * Syntax             : int Fls_IpIrqHandler(
 *                          uint32 irq, void *arg)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : irq - Interrupt number in non-standard mode
 *                            Standard mode does not care about this variable
 *                      arg - Pointer to controller handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Interrupt handler function, responsible for clearing the
 *                      ISR and calling the data handler.
 * \endverbatim
 * Traceability       : SWSR_FLS_167
 *******************************************************************************************************/
int Fls_IpIrqHandler(uint32 irq, void *arg)
{
    Fls_IpHostType *host = arg;
    Fls_IpContextType *ipCtx = host->privData;
    Fls_BusHandleType *nor = host->dev;
    uint32 status;

    (void) irq; /* Do not care about this parameter */

    status = Fls_IpReadl(ipCtx, FLS_IP_INT_ST_ERR);
    Fls_IpWritel(ipCtx, FLS_IP_INT_ST_ERR, status);

    status = Fls_IpReadl(ipCtx, FLS_IP_INT_ST_FUC);
    FLS_DEBUG("xspi irq status = 0x%x\n", status);

    if (0u != (status & (FLS_IP_INT_ST_FUC_IND_COMP)))
    {
        nor->xferInfoBottom.opsResult = FLS_BUS_OPS_COMPLETE;

        if (NULL_PTR != nor->eventHandler)
        {
            nor->eventHandler(nor->xferInfoBottom.opsType,
                              nor->xferInfoBottom.opsResult);
        }

        Fls_IpEnableEvent = 1U;

        Fls_IpWritel(ipCtx, FLS_IP_INT_EN_FUC, 0u);
    }
    else if (0U != (status &
                    (FLS_IP_INT_ST_FUC_FIFO_LEVEL_TRIG | FLS_IP_INT_ST_FUC_INDIRECT_RD_DONE)))
    {
        (void) Fls_IpPollingHandler((void *)(Fls_PointerType)nor);
    }
    else
    {
        /* Do nothing */
    }

    Fls_IpWritel(ipCtx, FLS_IP_INT_ST_FUC, status);
    return 0;
}

#ifndef NON_AUTOSAR_STANDARD_IRQ_HANDLER
FLS_IP_IRQ_HANDLER(0)
FLS_IP_IRQ_HANDLER(1)
#if (FLS_IP_RESOURE_NUM >= 2)
FLS_IP_IRQ_HANDLER(2)
FLS_IP_IRQ_HANDLER(3)
#endif /* #if (FLS_IP_RESOURE_NUM >= 2) */
#endif /* #ifndef NON_AUTOSAR_STANDARD_IRQ_HANDLER */
#endif /* #if (FLS_IP_USE_IRQ != 0) */

/** *****************************************************************************************************
 * \brief This function Occupancy controller, and communication preparations.
 *
 * \verbatim
 * Syntax             : int Fls_IpLock(
 *                          Fls_BusHandleType *nor, Fls_BusOpsType ops)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      ops - Type of operation
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Occupancy controller If locks are supported, and communication
 *                      preparations  by configuration registers
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpLock(Fls_BusHandleType *nor, Fls_BusOpsType ops)
{
    int ret = -1;
    Fls_IpPretransClean(nor);

    if (NULL_PTR == nor->host->dev)
    {
        nor->host->dev = nor;
        Fls_IpBusSetup(nor, ops);

        ret = 0;
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Unoccupy the controller.
 *
 * \verbatim
 * Syntax             : void Fls_IpUnlock(
 *                          Fls_BusHandleType *nor, Fls_BusOpsType ops)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      ops - Type of operation
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Unoccupy the controller
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpUnlock(Fls_BusHandleType *nor, Fls_BusOpsType ops)
{
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;
    (void) ops;
    Fls_IpWriteBits(ipCtx, FLS_IP_MISC, FLS_IP_MISC_IMMEDIATE_LSB, 1u, 0U);  /* default */
    nor->host->dev = NULL_PTR;
}

#if FLS_IP_USE_DMA
/** *****************************************************************************************************
 * \brief This function is DMA interrupt callbacks.
 *
 * \verbatim
 * Syntax             : void Fls_IpDmaTransferDone(
 *                          uint8 status, void *context)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : status - DMA operating state
 *                      param - Parameters for DMA callbacks
 *                      context - Context of the current module callback delivery
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : DMA interrupt callbacks, Callback when the DMA completes its work
 *                      or an error occurs
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpDmaTransferDone(uint8 status, void *context)
{
    FLS_DEBUG(" xspi set dma transfer done\r\n");
}

/** *****************************************************************************************************
 * \brief This function Configuring DMA Channels.
 *
 * \verbatim
 * Syntax             : void Fls_IpDmaConfig(
 *                          Fls_BusHandleType *nor, Fls_AddressType addr, uint8 *buf,
 *                          uint32 len, boolean isRead, boolean isDirect)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      addr - Physical address of Flash
 *                      buf - buffer is alloc by the user
 *                      len - Total size of transmission
 *                      isRead - Is it reading
 *                      isDirect - Is it in direct mode (Direct mode is not supported)
 *
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configuring DMA Channels
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpDmaConfig(Fls_BusHandleType *nor, Fls_AddressType addr, uint8 *buf,
                            uint32 len, boolean isRead, boolean isDirect)
{
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;
    Dma_DeviceConfigType dmaConfig;
    Dma_InstanceConfigType dmaALConfigParams;
    Dma_PeripheralIdType dmaId  = (0U == (ipCtx->id >> 1)) ? DMA_XSPI0 : DMA_XSPI1;
    Dma_SubIdType dmaSubId = (0U == (ipCtx->id % 2)) ?
                             ((TRUE == isRead) ? DMA_XSPI_PORTA_RD : DMA_XSPI_PORTA_WR)
                             : ((TRUE == isRead) ? DMA_XSPI_PORTB_RD : DMA_XSPI_PORTB_WR);
    (void) isDirect; /* Direct mode is not supported, don't care about this. */

    if (E_OK != Dma_GetConfigParams(dmaId, dmaSubId, DMA_MODULE_XSPI, &dmaALConfigParams))
    {
        FLS_DEBUG("ERROR: get EB configurations failed. \n");
    }
    else
    {
        FLS_DEBUG("Dma controller id %d, Dma channel id %d\n",
                  dmaALConfigParams.controller, dmaALConfigParams.channelId);
        ipCtx->dmaChannel = Dma_RequestChannelWithId(dmaALConfigParams.controller,
                            dmaALConfigParams.channelId);
    }

    if (NULL_PTR == ipCtx->dmaChannel)
    {
        FLS_DEBUG("ERROR: DMA alloc channel failed.. \n");
    }
    else
    {
        ipCtx->dmaChannel->irqCallback = (Dma_IrqHandle)&Fls_IpDmaTransferDone;

        Fls_MemClear(&dmaConfig, sizeof(Dma_DeviceConfigType));
        (void) Dma_InitConfigChannel(&dmaConfig);

        dmaConfig.srcBusWidth = DMA_BEAT_SIZE_4_BYTE;
        dmaConfig.dstBusWidth = DMA_BEAT_SIZE_4_BYTE;
        dmaConfig.srcMaxBurst = DMA_BURST_LENGTH_16;
        dmaConfig.dstMaxBurst = DMA_BURST_LENGTH_16;

        if (TRUE == isRead)
        {
            FLS_DEBUG("dev2mem\n");
            dmaConfig.direction = DMA_DEVICE_TO_MEMORY;
            dmaConfig.srcAddress = (uint32)ipCtx->apbBase + FLS_IP_INDIRECT_RDATA;
            dmaConfig.dstAddress = (uint32)buf;
            dmaConfig.srcPortSelect = DMA_PORT_AHB32;
            dmaConfig.dstPortSelect = DMA_PORT_AXI64;
            dmaConfig.srcIncDirection = DMA_BURST_FIXED;
            dmaConfig.dstIncDirection = DMA_BURST_INCREMENTAL;
            dmaConfig.flowControl = DMA_DIR_DEVICE_TO_MEMORY;
        }
        else
        {
            FLS_DEBUG("mem2dev\n");
            dmaConfig.direction = DMA_MEMORY_TO_DEVICE;
            dmaConfig.dstAddress = (uint32)ipCtx->apbBase + FLS_IP_INDIRECT_WDATA;
            dmaConfig.srcAddress = (uint32)buf;
            dmaConfig.srcPortSelect = DMA_PORT_AXI64;
            dmaConfig.dstPortSelect = DMA_PORT_AHB32;
            dmaConfig.srcIncDirection = DMA_BURST_INCREMENTAL;
            dmaConfig.dstIncDirection = DMA_BURST_FIXED;
            dmaConfig.flowControl = DMA_DIR_MEMORY_TO_DEVICE;
        }

        dmaConfig.transaction = DMA_DEVICE;
        dmaConfig.processMode = DMA_INTERRUPT;
        dmaConfig.srcStridePol = DMA_POSITIVE_OFFSET;
        dmaConfig.dstStridePol = DMA_POSITIVE_OFFSET;
        dmaConfig.bufferMode = DMA_SINGLE_BUFFER;
        dmaConfig.loopMode = DMA_LOOP_MODE_2;
        dmaConfig.transferMode = DMA_TRANSFER_MODE_LINKLIST;
        dmaConfig.linkListTriggerMode = DMA_TRIGGER_BY_HARDWARE;

        if (E_OK != Dma_ConfigChannel(ipCtx->dmaChannel, &dmaConfig))
        {
            FLS_DEBUG("ERROR: copy configurations to channel buffer failed. \n");
        }
        else if (E_OK != Dma_PrepareTransmission(ipCtx->dmaChannel, len))
        {
            FLS_DEBUG("ERROR: Prepare transmission failed. \n");
        }
        else if (E_OK != Dma_Start(ipCtx->dmaChannel))
        {
            FLS_DEBUG("ERROR: Start transmission failed. \n");
        }
        else
        {
            /* Do nohing */
        }
    }
}
#endif /* #if FLS_IP_USE_DMA */

/** *****************************************************************************************************
 * \brief This function Copying data.
 *
 * \verbatim
 * Syntax             : void Fls_IpReadUnaligned(
 *                          void *src, void *dst, uint32 size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : src - Source address
 *                      dst - Target address
 *                      size - Data size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Automatically selects the copy method to copy data according to the
 *                      alignment of address and length.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpReadUnaligned(void *src, void *dst, uint32 size)
{
    uint32 alignSrc = FLS_ROUNDUP((Fls_PointerType)src, FLS_IP_READ_ADDR_ALIGNED)
                      - (Fls_PointerType)src;
    uint32 alignDst = FLS_ROUNDUP((Fls_PointerType)dst, FLS_IP_READ_ADDR_ALIGNED)
                      - (Fls_PointerType)dst;
    uint8 *dstPtr = (uint8 *)dst;
    uint8 *srcPtr = (uint8 *)src;
    uint8 i;
    uint32 bytes_aligned;
    uint32 sizeTemp = size;

    if (alignSrc != alignDst)
    {
        for (; sizeTemp > 0U; sizeTemp--)
        {
            *dstPtr = readb(srcPtr);
            dstPtr++;
            srcPtr++;
        }
    }
    else
    {
        for (i = 0U; (i < alignSrc) && (sizeTemp > 0U); i++)
        {
            *dstPtr = readb(srcPtr);
            sizeTemp--;
            dstPtr++;
            srcPtr++;
        }

        bytes_aligned = sizeTemp / 4U * 4U;
        if (0U != bytes_aligned)
        {
            (void) Fls_Memcpy4ByteAligned((void *)(Fls_PointerType)dstPtr,
                                    (void *)(Fls_PointerType)srcPtr, bytes_aligned);
            sizeTemp -= bytes_aligned;
            dstPtr += bytes_aligned;
            srcPtr += bytes_aligned;
        }

        for (; sizeTemp > 0U; sizeTemp--)
        {
            *dstPtr = readb(srcPtr);
            dstPtr++;
            srcPtr++;
        }
    }
}

/** *****************************************************************************************************
 * \brief This function Implementation of reading data from Flash.
 *
 * \verbatim
 * Syntax             : int Fls_IpRead(
 *                          Fls_BusHandleType *nor, Fls_AddressType addr, uint8 *buf,
 *                          Fls_LengthType size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      addr - Physical address of Flash
 *                      buf - buffer is alloc by the user
 *                      size - Total size of transmission
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Reading data from Flash, default use direct mode to read, if the address
 *                      beyond the return automatically switch to indirect mode reading
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpRead(Fls_BusHandleType *nor, Fls_AddressType addr, uint8 *buf,
                      Fls_LengthType size)
{
    uint32 irqTrigLevel;
    uint32 mask = 0u;
    Fls_LengthType limitSize = size;
    Fls_LengthType readSize;
    Fls_AddressType currentAddr = addr;
    Fls_LengthType sizeDone = 0;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;
    uint8 *dstBuf;

#if (1 == FLS_IP_USE_DIRECT_MODE)

    if (addr < ipCtx->directRangeSize)
    {
        /* direct access */
#if (FLS_NON_CACHEABLE_EN == STD_OFF)
        Dma_InvalidateCache((uint32)(Fls_PointerType)(ipCtx->directBase + addr),
                            FLS_ROUNDUP(size, FLS_IP_ARCH_CACHE_LINE));
#endif /* #if (FLS_NON_CACHEABLE_EN == STD_OFF) */
        Fls_IpReadUnaligned((void *)(Fls_PointerType)(ipCtx->directBase + addr),
                            (void *)(Fls_PointerType)buf, size);
        nor->xferInfoBottom.opsResult = FLS_BUS_OPS_COMPLETE;
    }
    else
#endif /* #if (1 == FLS_IP_USE_DIRECT_MODE) */
    {

#ifdef SEMIDRIVE_E3_SERIES

        if ((FLS_BUS_DEV_PARALLEL_MODE == nor->devMode))
        {
            limitSize = ((uint32)ipCtx->fifoDepth * (uint32)ipCtx->fifoWidth);
        }

#endif /* #ifdef SEMIDRIVE_E3_SERIES */

        while (sizeDone < size)
        {
            readSize = FLS_MIN(size - sizeDone, limitSize);
            dstBuf = buf + sizeDone;

            Fls_IpSetupXfer(nor, FLS_BUS_OPS_READ, currentAddr, dstBuf, NULL_PTR, readSize);
            Fls_IpProtocolSetup(nor, NULL_PTR, FLS_IP_INDIRECT_ACCESS_MODE,
                                FLS_BUS_OPS_READ);

            irqTrigLevel = FLS_MIN((uint32)ipCtx->fifoDepth / 2UL, FLS_DIV_ROUND_UP(readSize, 4UL));
            irqTrigLevel = (uint32)1u << Fls_IpCompromiseAlg(irqTrigLevel);

            /* workaround dma not support single req */
            if (readSize < 32u)
            {
                irqTrigLevel = 1;
            }

            Fls_IpWriteBits(ipCtx, FLS_IP_INDIRECT_RD_DMA,
                            FLS_IP_INDIRECT_DMA_TRIG_WML_LSB, 8u, irqTrigLevel);
#if FLS_IP_USE_DMA

            if (nor->xferMode == FLS_BUS_XFER_DMA_MODE)
            {
#if (FLS_NON_CACHEABLE_EN == STD_OFF)
                Dma_InvalidateCache((uint32)dstBuf, FLS_ROUNDUP(readSize, 32));
#endif /* #if (FLS_NON_CACHEABLE_EN == STD_OFF) */
                Fls_IpDmaEnable(ipCtx);
                FLS_DEBUG("indirect read length %lld, dma trig level %d\n", readSize, irqTrigLevel);
                Fls_IpDmaConfig(nor, currentAddr, dstBuf, readSize, TRUE, FALSE);

                if (NULL_PTR == ipCtx->dmaChannel)
                {
                    Fls_IpDmaDisable(ipCtx);
                    nor->xferInfoBottom.opsResult = FLS_BUS_OPS_FAILED;
                    break;
                }

                mask |= FLS_IP_INT_ST_FUC_INDIRECT_DMA_RD_DONE;
            }
            else
            {
                mask |= FLS_IP_INT_ST_FUC_RX_FRE_FULL | FLS_IP_INT_ST_FUC_INDIRECT_RD_DONE;
            }

#else
            mask |= FLS_IP_INT_ST_FUC_RX_FRE_FULL | FLS_IP_INT_ST_FUC_INDIRECT_RD_DONE;
#endif /* #if FLS_IP_USE_DMA */

            Fls_IpSetInterruptMask(ipCtx, FLS_IP_INT_EN_FUC, mask);
            Fls_IpIndirectTrigger(ipCtx, currentAddr, readSize, INDIRECT_READ_FLAG);

            Fls_IpWaitXferDone(nor);
#if FLS_IP_USE_DMA

            if (nor->xferMode == FLS_BUS_XFER_DMA_MODE)
            {
                Fls_IpDmaDisable(ipCtx);

                if (E_OK != Dma_Stop(ipCtx->dmaChannel))
                {
                    FLS_DEBUG("Dma channel stop failed\n");
                }

                (void)Dma_ReleaseChannel(ipCtx->dmaChannel);
            }

#endif /* #if FLS_IP_USE_DMA */

            if (FLS_BUS_OPS_FAILED == nor->xferInfoBottom.opsResult)
            {
                break;
            }
            else
            {
                currentAddr += readSize;
                sizeDone += readSize;
            }
        }
    }

    FlsHookError_Fls_IpRead();

    return (int)nor->xferInfoBottom.opsResult;
}

/** *****************************************************************************************************
 * \brief This function Flush CPU and IP cache.
 *
 * \verbatim
 * Syntax             : void Fls_IpCacheFlush(
 *                          Fls_BusHandleType *nor, Fls_AddressType addr, Fls_LengthType length)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      addr - Physical address of Flash
 *                      length - Total size of Flush
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Flush CPU and IP cache, The address of the CPU cache is mapped based
 *                      on the physical address of the Flash
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpCacheFlush(Fls_BusHandleType *nor, Fls_AddressType addr,
                             Fls_LengthType length)
{
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;

#if (FLS_NON_CACHEABLE_EN == STD_OFF)
    Dma_InvalidateCache((uint32)(Fls_PointerType)(ipCtx->directBase + addr),
                        FLS_ROUNDUP(length, FLS_IP_ARCH_CACHE_LINE));
#endif /* #if (FLS_NON_CACHEABLE_EN == STD_OFF) */
    Fls_IpPrefetchFlush(ipCtx, 0);
    Fls_IpPrefetchFlush(ipCtx, 1);
}

/** *****************************************************************************************************
 * \brief This function Implementation of writing data to Flash.
 *
 * \verbatim
 * Syntax             : int Fls_IpRead(
 *                          Fls_BusHandleType *nor, Fls_AddressType addr, uint8 *buf,
 *                          Fls_LengthType size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      addr - Physical address of Flash
 *                      buf - buffer is alloc by the user
 *                      size - Total size of transmission
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Writing data to Flash, default use indirect mode to write, if using
 *                      hyperram automatically switch to direct mode writing
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpWrite(Fls_BusHandleType *nor, Fls_AddressType addr,
                       const uint8 *buf, Fls_LengthType size)
{
#ifndef FLS_ASYNC_MODE_EN
    int ret;
#endif /* #ifndef FLS_ASYNC_MODE_EN */
    uint32 irqTrigLevel;
    uint32 mask = 0u;
    uint32 addr_tmp = addr;
    uint32 buf_index = 0;
    uint32 size_tmp = size;
    uint32 write_size;
    boolean hyperram_mode = (nor->memType == FLS_BUS_HYPERRAM) ? TRUE : FALSE;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;

    if (!FLS_IS_ALIGNED(addr, 4) || !FLS_IS_ALIGNED(buf, 4) || !FLS_IS_ALIGNED(size, 4))
    {
        nor->xferInfoBottom.opsResult = FLS_BUS_OPS_INVALID;
    }
    else
    {
        Fls_IpCacheFlush(nor, addr, size);
#if (1 == FLS_IP_USE_DIRECT_MODE)

        if ((addr < ipCtx->directRangeSize) && (TRUE == hyperram_mode))
        {
            /* direct access */
            (void) Fls_MemCopy((void *)(Fls_PointerType)(ipCtx->directBase + addr),
                               (void *)(Fls_PointerType)buf, size);
#if (FLS_NON_CACHEABLE_EN == STD_OFF)
            Dma_FlushCache((uint32)(Fls_PointerType)(ipCtx->directBase + addr),
                           FLS_ROUNDUP(size, FLS_IP_ARCH_CACHE_LINE));
#endif /* #if (FLS_NON_CACHEABLE_EN == STD_OFF) */
            nor->xferInfoBottom.opsResult = FLS_BUS_OPS_COMPLETE;
        }
        else
#endif /* #if (1 == FLS_IP_USE_DIRECT_MODE) */
        {
#if FLS_IP_USE_DMA && (FLS_NON_CACHEABLE_EN == STD_OFF)

            if (nor->xferMode == FLS_BUS_XFER_DMA_MODE)
            {
                Dma_CleanCache((uint32)(Fls_PointerType)buf, FLS_ROUNDUP(size, 32));
            }

#endif /* #if FLS_IP_USE_DMA && (FLS_NON_CACHEABLE_EN == STD_OFF) */

            while (size_tmp > 0U)
            {
                write_size = FLS_MIN((nor->info.pageSize - (addr_tmp % nor->info.pageSize)), size_tmp);
                (void) Fls_BusWriteEnable(nor, TRUE);

                Fls_IpSetupXfer(nor, FLS_BUS_OPS_WRITE, addr_tmp, NULL_PTR, buf + buf_index, write_size);
                Fls_IpProtocolSetup(nor, NULL_PTR, FLS_IP_INDIRECT_ACCESS_MODE,
                                    FLS_BUS_OPS_WRITE);

                irqTrigLevel = FLS_MIN((uint32)ipCtx->fifoDepth / 2UL, FLS_DIV_ROUND_UP(size, 4UL));
                irqTrigLevel =  ((uint32)1u) << Fls_IpCompromiseAlg(irqTrigLevel);
                Fls_IpWriteBits(ipCtx, FLS_IP_INDIRECT_WR_DMA,
                                FLS_IP_INDIRECT_DMA_TRIG_WML_LSB, 8u, irqTrigLevel);
#if FLS_IP_USE_DMA

                if (nor->xferMode == FLS_BUS_XFER_DMA_MODE)
                {
                    Fls_IpDmaEnable(ipCtx);
                    Fls_IpDmaConfig(nor, addr_tmp, (uint8 *)buf + buf_index, write_size, FALSE, FALSE);

                    if (NULL_PTR == ipCtx->dmaChannel)
                    {
                        Fls_IpDmaDisable(ipCtx);
                        nor->xferInfoBottom.opsResult = FLS_BUS_OPS_FAILED;
                        break;
                    }

                    mask |= FLS_IP_INT_ST_FUC_INDIRECT_WR_DONE;
                }
                else
                {
                    mask |= FLS_IP_INT_ST_FUC_TX_FRE_EMPTY | FLS_IP_INT_ST_FUC_INDIRECT_WR_DONE;
                }

#else
                mask |= FLS_IP_INT_ST_FUC_TX_FRE_EMPTY | FLS_IP_INT_ST_FUC_INDIRECT_WR_DONE;
#endif /* #if FLS_IP_USE_DMA */
                Fls_IpIndirectTrigger(ipCtx, addr_tmp, write_size, INDIRECT_WRITE_FLAG);
                Fls_IpSetInterruptMask(ipCtx, FLS_IP_INT_EN_FUC, mask);

                Fls_IpWaitXferDone(nor);
#if FLS_IP_USE_DMA

                if (nor->xferMode == FLS_BUS_XFER_DMA_MODE)
                {
                    Fls_IpDmaDisable(ipCtx);

                    if (E_OK != Dma_Stop(ipCtx->dmaChannel))
                    {
                        FLS_DEBUG("Dma channel stop failed\n");
                    }

                    (void)Dma_ReleaseChannel(ipCtx->dmaChannel);
                }

#endif /* #if FLS_IP_USE_DMA */

#ifndef FLS_ASYNC_MODE_EN

                /* wait for flash idle */
                do
                {
                    ret = Fls_BusWaitIdle(nor);

                    if (ret)
                    {
                        nor->xferInfoBottom.opsResult = FLS_BUS_OPS_FAILED;
                    }
                }
                while (Fls_IpLockstepErr != 0u);

#endif /* #ifndef FLS_ASYNC_MODE_EN */

                if (FLS_BUS_OPS_FAILED == nor->xferInfoBottom.opsResult)
                {
                    break;
                }
                else
                {
                    addr_tmp += write_size;
                    size_tmp -= write_size;
                    buf_index += write_size;
                }
            }
        }
    }

    FlsHookError_Fls_IpWrite();

    return (int)(nor->xferInfoBottom.opsResult);
}

#ifdef FLS_SPIBUS_FLASH_CNT
/** *****************************************************************************************************
 * \brief This function Erase a sector of Flash.
 *
 * \verbatim
 * Syntax             : int Fls_IpErase(
 *                          Fls_BusHandleType *nor, Fls_AddressType offset)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      offset - Offset address where the sector is located
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Send command to erase a sector of Flash
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpErase(Fls_BusHandleType *nor, Fls_AddressType offset)
{
    int ret = 0;
    Fls_AddressType eraseAddress = offset;
    Fls_BusCommandType writeEnableCmd;
    Fls_BusCommandType eraseCmd;
    writeEnableCmd.opcode = 0x6u;
    writeEnableCmd.addrBytes = 0;
    /* the write enable cmd inst_width need aline with erase cmd */
    writeEnableCmd.instType = FLS_BUS_INST_LANS(nor->regProto);
    eraseCmd.opcode = (uint8)(nor->info.eraseProto[nor->info.sectorType] >> FLS_BUS_OPCODE_PROTO_LSB);
    eraseCmd.addrBytes = (uint8)nor->addrWidth;
    /* the write enable cmd inst_width need aline with erase cmd */
    eraseCmd.instType = FLS_BUS_INST_LANS(nor->regProto);

    if (FLS_BUS_DEV_PARALLEL_MODE == nor->devMode)
    {
        eraseAddress = offset / 2u;
    }

    Fls_IpCacheFlush(nor, eraseAddress, nor->info.sectorSize);

    if (FLS_BUS_DEV_SWITCH_MODE == nor->devMode)
    {
        eraseAddress -= nor->info.regOffset;
    }

    if (0 != Fls_IpCommandWrite(nor, &writeEnableCmd, 0, NULL_PTR, 0))
    {
        ret = -1;
    }
    else if (0 != Fls_IpCommandWrite(nor, &eraseCmd, eraseAddress, NULL_PTR, 0))
    {
        ret = -1;
    }
    else
    {
#ifndef FLS_ASYNC_MODE_EN

        /* wait for flash idle */
        do
        {
            ret = Fls_BusWaitIdle(nor);

            if (ret)
            {
                nor->xferInfoBottom.opsResult = FLS_BUS_OPS_FAILED;
            }
        }
        while (Fls_IpLockstepErr != 0u);

#endif /* #ifndef FLS_ASYNC_MODE_EN */
    }

    FlsHookError_Fls_IpErase();

    return ret;
}
#endif /* #ifdef FLS_SPIBUS_FLASH_CNT */

/** *****************************************************************************************************
 * \brief This function perform training operations.
 *
 * \verbatim
 * Syntax             : int Fls_IpTraining(
 *                          Fls_BusHandleType *nor, Fls_AddressType addr,
 *                          uint8 *buf, const uint8 *pattern, Fls_LengthType size)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      addr - Physical address of Flash
 *                      buf - Read buffer, alloc by user
 *                      pattern - Training pattern buffer
 *                      size - Buffer size
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Perform DLL training on the IP data acquisition channel
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpTraining(Fls_BusHandleType *nor, Fls_AddressType addr,
                          uint8 *buf, const uint8 *pattern,
                          Fls_LengthType size)
{
    int ret;
    uint32 rx_delay;
    uint32 rx_delay_start = 0;
    boolean train_ok = FALSE;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;

    for (rx_delay = 0u; rx_delay <= 0x7fu; rx_delay++)
    {
        Fls_IpDllEnable(ipCtx, 0, rx_delay, TRUE);
        Fls_IpDllEnable(ipCtx, 1, rx_delay, TRUE);

        if (0 != Fls_BusRead(nor, addr, buf, size))
        {
            train_ok = FALSE;
            FLS_DEBUG("Bus read failed\n");
        }
        else
        {
            Fls_IpLockstepErr = Fls_IpReadl(ipCtx, FLS_IP_LSP_ERR_ST);

            if (0U != Fls_IpLockstepErr)
            {
                Fls_IpWritel(ipCtx, FLS_IP_LSP_ERR_ST, Fls_IpLockstepErr);
                FLS_DEBUG("xspi lsp error status = 0x%x\n", Fls_IpLockstepErr);
            }

            if (0U == Fls_MemCompare((const void *)(Fls_PointerType)buf,
                                     (const void *)(Fls_PointerType)pattern, (uint32)size))
            {
                if (FALSE == train_ok)
                {
                    train_ok = TRUE;
                    rx_delay_start = rx_delay;
                }
            }
            else
            {
                if ((TRUE == train_ok) && (rx_delay > (rx_delay_start + 10u)))
                {
                    break;
                }
                else
                {
                    train_ok = FALSE;
                }
            }
        }
    }

    if (TRUE == train_ok)
    {
        rx_delay = (rx_delay_start + rx_delay) / 2u;
        Fls_IpDllEnable(ipCtx, 0, rx_delay, TRUE);
        Fls_IpDllEnable(ipCtx, 1, rx_delay, TRUE);
        FLS_DEBUG("xspi phy training pass!\n");
        ret = 0;
    }
    else
    {
        Fls_IpDllEnable(ipCtx, 0, 0u, FALSE);
        Fls_IpDllEnable(ipCtx, 1, 0u, FALSE);
        FLS_DEBUG("xspi phy training failed, disable dll!\n");
        ret = -1;
    }

    return ret;
}

#ifdef FLS_HYPERBUS_FLASH_CNT
/** *****************************************************************************************************
 * \brief This function Read two bytes from Flash.
 *
 * \verbatim
 * Syntax             : int Fls_IpRead16(
 *                          Fls_BusHandleType *nor, Fls_AddressType addr, uint16 *buf)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      addr - The address to be read
 *                      buf - Data buffer
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Read two bytes from Flash, And use the specified command
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpRead16(Fls_BusHandleType *nor, Fls_AddressType addr, uint16 *buf)
{
    Fls_BusCommandType read_cmd;
    read_cmd.opcode = 0;
    read_cmd.dummy = nor->info.readDummy;
    read_cmd.addrBytes = nor->addrWidth;
    read_cmd.instType = FLS_BUS_INST_LANS(nor->regProto);

    return Fls_IpCommandRead(nor, &read_cmd, addr * 2u, (uint8 *)buf, 2u);
}

/** *****************************************************************************************************
 * \brief This function write two bytes to Flash.
 *
 * \verbatim
 * Syntax             : int Fls_IpWrite16(
 *                          Fls_BusHandleType *nor, Fls_AddressType addr, uint16 *buf)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      addr - The address to be write
 *                      buf - Data buffer
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Write two bytes to Flash, And use the specified command
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpWrite16(Fls_BusHandleType *nor, Fls_AddressType addr, uint16 *buf)
{
    Fls_BusCommandType write_cmd;
    write_cmd.opcode = 0;
    write_cmd.dummy = 0;
    write_cmd.addrBytes = nor->addrWidth;
    write_cmd.instType = FLS_BUS_INST_LANS(nor->regProto);

    return Fls_IpCommandWrite(nor, &write_cmd, addr * 2u, (uint8 *)buf, 2u);
}

/** *****************************************************************************************************
 * \brief This function configure pre-transaction data.
 *
 * \verbatim
 * Syntax             : int Fls_IpSetPreTransaction(
 *                          Fls_BusHandleType *nor, boolean isRead,
 *                          boolean isDirect, uint32 num, Fls_HyperbusCaType **caArray)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      isRead - Read or Write flag
 *                      isDirect - Direct or Indirect flag
 *                      num - The number of command
 *                      caArray - Pointer array of commands
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Configure pre-transaction data, These configured data are automatically
 *                      sent before a normal send.
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static void Fls_IpSetPreTransaction(Fls_BusHandleType *nor, boolean isRead,
                                    boolean isDirect, uint32 num, Fls_HyperbusCaType **caArray)
{
    uint32 addr;
    uint32 data;
    uint32 ptc_addr;
    uint32 pta_base_addr;
    uint32 ptd_base_addr;
    Fls_HyperbusCaType const *caPtr = *caArray;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)nor->host->privData;
    uint32 i;

    if (nor->memType == FLS_BUS_HYPERBUS_MCP)
    {
        for (i = 0u; i < num; i++)
        {
            addr = caPtr->addr;
            data = caPtr->data;

            if (0 != Fls_IpWrite16(nor, addr, (uint16 *)(Fls_PointerType)(&data)))
            {
                FLS_DEBUG("MCP SetPreTransaction failed\n");
                break;
            }
            else
            {
                caPtr += 1;
            }
        }
    }
    else
    {
        if (TRUE == isRead)
        {
            if (TRUE == isDirect)
            {
                ptc_addr = FLS_IP_DIRECT_RD_PTC;
                pta_base_addr = FLS_IP_DIRECT_RD_PTA;
                ptd_base_addr = FLS_IP_DIRECT_RD_PTD;
            }
            else
            {
                ptc_addr = FLS_IP_INDR_RD_PTC;
                pta_base_addr = FLS_IP_INDR_RD_PTA;
                ptd_base_addr = FLS_IP_INDR_RD_PTD;
            }
        }
        else
        {
            if (TRUE == isDirect)
            {
                ptc_addr = FLS_IP_DIRECT_WR_PTC;
                pta_base_addr = FLS_IP_DIRECT_WR_PTA;
                ptd_base_addr = FLS_IP_DIRECT_WR_PTD;
            }
            else
            {
                ptc_addr = FLS_IP_INDR_WR_PTC;
                pta_base_addr = FLS_IP_INDR_WR_PTA;
                ptd_base_addr = FLS_IP_INDR_WR_PTD;
            }
        }

        for (i = 0u; i < num; i++)
        {
            addr = caPtr->addr;
            data = caPtr->data;
            Fls_IpWritel(ipCtx, pta_base_addr, addr);
            Fls_IpWritel(ipCtx, ptd_base_addr, data);

            pta_base_addr += 0x20U;
            ptd_base_addr += 0x20U;
            caPtr += 1;
        }

        /* set pre-tansaction num */
        Fls_IpWritel(ipCtx, ptc_addr, num << 8u);
    }
}
#endif /* #ifdef FLS_HYPERBUS_FLASH_CNT */

/** *****************************************************************************************************
 * \brief This function Configure the IP to enter XIP mode.
 *
 * \verbatim
 * Syntax             : int Fls_IpEnterXipMode(
 *                          Fls_BusHandleType *nor, boolean enable)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : nor - Pointer to bus handler
 *                      enable - Switch for entering XIP mode or not(unused)
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Configure the IP to enter XIP mode
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpEnterXipMode(Fls_BusHandleType *handle, boolean enable)
{
    (void) enable;
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)handle->host->privData;
    Fls_IpXipEnable(ipCtx);
    Fls_IpCacheFlush(handle, 0, handle->info.size);
    FLS_DEBUG("read to confirm XIP %X\r\n", *(uint32 *)ipCtx->directBase);
    Fls_IpCacheFlush(handle, 0, handle->info.size);
    Fls_IpXipEnter(ipCtx);
    return 0;
}

/** *****************************************************************************************************
 * \brief This function Initialise the controller's context.
 *
 * \verbatim
 * Syntax             : int Fls_IpHostInit(
 *                          Fls_IpHostType *host, Fls_IpContextType *ipCtx,
 *                          Fls_IpConfigType *config)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : host - Pointer to controller handler
 *                      ipCtx - Pointer to controller context
 *                      config - Pointer to controller configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Initialise the controller's context
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
static int Fls_IpHostInit(Fls_IpHostType *host, Fls_IpContextType *ipCtx,
                          Fls_IpConfigType *config)
{
    int ret = 0;

    if ((NULL_PTR != host) && (NULL_PTR != ipCtx) && (NULL_PTR != config))
    {
        Fls_MemClear((void *)(Fls_PointerType)host, sizeof(Fls_IpHostType));
        Fls_MemClear((void *)(Fls_PointerType)ipCtx, sizeof(Fls_IpContextType));

        ipCtx->id = config->id;
        ipCtx->apbBase = config->apbBase;
        ipCtx->directRangeSize = 0x8000000U;
        ipCtx->directBase = config->directBase;
        ipCtx->irq = config->irq;
        ipCtx->refClkHz = config->refClkHz;
        ipCtx->prefetchEnable = config->prefetchEnable;

        Fls_IpEnableEvent = 0U;
        host->id = config->id;
        host->refClkHz = config->refClkHz;
        host->privData = (void *)(Fls_PointerType)ipCtx;
        host->ops = &Fls_IpHostOps;

        if (NULL_PTR == Fls_IpContextInit(ipCtx))
        {
            ret = -1;
        }
    }
    else
    {
        ret = -2;
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Initialise the controller.
 *
 * \verbatim
 * Syntax             : int Fls_IpInit(
 *                          Fls_IpHostType *host, Fls_IpConfigType *config)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : host - Pointer to controller handler
 *                      config - Pointer to controller configuration
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : 0 - Sucessfully
 *                     !0 - Failed
 *
 * Description        : Initialise the controller
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
int Fls_IpInit(Fls_IpHostType *host, const Fls_BusConfigType *config)
{
    int ret;

    ret = Fls_IpModeEnable((FLS_BUS_DEV_LOCKSTEP_MODE == config->devMode) ? TRUE : FALSE,
                           (FLS_BUS_DEV_PARALLEL_MODE == config->devMode) ? TRUE : FALSE,
                           config->id);

    if (0 != ret)
    {
        FLS_DEBUG("Fls set device mode failed\n");
    }
    else
    {
        Fls_IpConfigTable[config->id].refClkHz = config->refClkHz;
#if (1 == FLS_IP_USE_PREFETCH)
        Fls_IpConfigTable[config->id].prefetchEnable = TRUE;
#else
        Fls_IpConfigTable[config->id].prefetchEnable = FALSE;
#endif
        ret = Fls_IpHostInit(host, &Fls_IpContextTable[config->id], &Fls_IpConfigTable[config->id]);

        if ((0 == ret) && (NULL_PTR != host->clkOps))
        {
            ret = host->clkOps->setClkRate(host->id, config->baudrate);
            FLS_DEBUG("spinor host clock rate is %u!\n",
                      host->clkOps->getClkRate(host->id));
        }
    }

    return ret;
}

/** *****************************************************************************************************
 * \brief This function Reverse initialisation of the controller.
 *
 * \verbatim
 * Syntax             : void Fls_IpDeinit(
 *                          Fls_BusHandleType *bus)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : bus - Pointer to bus handler
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Reverse initialisation of the controller
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpDeinit(Fls_BusHandleType *bus)
{
    (void) bus;
#ifdef FLS_BUS_DMA_ENABLE
#endif /* #ifdef FLS_BUS_DMA_ENABLE */
    return;
}

/** *****************************************************************************************************
 * \brief This function return value of timer register.
 *
 * \verbatim
 * Syntax             : uint32 Fls_IpReadPmcnten( )
 *
 * Service ID[hex]    : None
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
 * Return value       : The value of timer register
 *
 * Description        : Get timer value register
 * \endverbatim
 *******************************************************************************************************/
static uint32 Fls_IpReadPmcnten(void)
{
    return Fls_ReadPmcnten();
}

/** *****************************************************************************************************
 * \brief This function return value of counter frequency register.
 *
 * \verbatim
 * Syntax             : uint32 Fls_IpReadPmccntr( )
 *
 * Service ID[hex]    : None
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
 * Return value       : The value of counter frequency register
 *
 * Description        : Get timer counter frequency register
 * \endverbatim
 *******************************************************************************************************/
static uint32 Fls_IpReadPmccntr(void)
{
    return Fls_ReadPmccntr();
}

/** *****************************************************************************************************
 * \brief This function blocking for specified time in order to delay.
 *
 * \verbatim
 * Syntax             : void Fls_IpDelayUs(uint32 us)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : us - Specify the blocking time in us
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Blocking for a specified time in order to delay
 * \endverbatim
 * Traceability       : None
 *******************************************************************************************************/
void Fls_IpDelayUs(uint32 us)
{
    uint32 tickTo, startTick, currentTick;
    uint32 tmt = 0u;
    uint32 usTemp = us;

    if (0U == usTemp)
    {
        /* Do nothing */
    }
    else if ((FLS_PMU_EN_CYCLE != (Fls_IpReadPmcnten() & FLS_PMU_EN_CYCLE)) || (us <= 10U))
    {
        FLS_IP_DELAY_US(usTemp);
    }
    else     /* pmu */
    {
        if (usTemp > FLS_IP_PMU_MAX_DELAY_TIME)
        {
            usTemp = FLS_IP_PMU_MAX_DELAY_TIME;
        }

        startTick = Fls_IpReadPmccntr();

        /* make sure cycled information: loops takes ~5us */
        while ((startTick == Fls_IpReadPmccntr()) && (tmt < FLS_IP_PMU_LOOPS))
        {
            tmt++;
        }

        /* timeout check is not a must here, just in case the pmccntr abnormal */
        if (tmt < FLS_IP_PMU_LOOPS)
        {
            tickTo = startTick + FLS_PMU_US_TO_TICK(usTemp);

            if (tickTo > startTick)
            {
                /* tickTo not overflowed */
                do
                {
                    currentTick = Fls_IpReadPmccntr();
                }
                while ((currentTick < tickTo)
                        && (currentTick > startTick));
            }
            else
            {
                /* currentTick overflowed */
                do
                {
                    currentTick = Fls_IpReadPmccntr();
                }
                while ((currentTick > startTick) || (currentTick < tickTo));
            }
        }
    }
}

#ifdef FLS_RFD_ENABLE_CNT
int Fls_IpEnableRfd(Fls_BusHandleType *bus)
{
    int ret = -2;

    if ((NULL_PTR != bus) && (NULL_PTR != bus->host->ops->enableRfd))
    {
        bus->host->ops->prepare(bus, FLS_BUS_OPS_LOCK);
        ret = bus->host->ops->enableRfd(bus);
        bus->host->ops->unprepare(bus, FLS_BUS_OPS_LOCK);
    }

    return ret;
}
#endif /* #ifdef FLS_RFD_ENABLE_CNT */

void Fls_BusSetupXfer(Fls_BusHandleType *nor, Fls_BusOpsType opt,
                      Fls_AddressType addr, uint8 *readBuf,
                      const uint8 *writeBuf, Fls_LengthType size)
{
    nor->xferInfo.opsType = opt;
    nor->xferInfo.addr = addr;
    nor->xferInfo.readBuf = readBuf;
    nor->xferInfo.writeBuf = writeBuf;
    nor->xferInfo.size = size;
    nor->xferInfo.opsResult = FLS_BUS_OPS_PENDING;
}

void Fls_BusXferComplete(Fls_BusHandleType *nor)
{
    nor->xferInfo.size = 0;
    nor->xferInfo.opsResult = FLS_BUS_OPS_COMPLETE;
    nor->host->ops->unprepare(nor, (Fls_BusOpsType)nor->xferInfo.opsType);
    nor->xferInfo.opsType = FLS_BUS_OPS_UNKNOW;
}

void Fls_BusXferError(Fls_BusHandleType *nor)
{
    nor->xferInfo.size = 0;
    nor->xferInfo.opsResult = FLS_BUS_OPS_FAILED;
    nor->host->ops->unprepare(nor, (Fls_BusOpsType)nor->xferInfo.opsType);
    nor->xferInfo.opsType = FLS_BUS_OPS_UNKNOW;
}

int Fls_BusSetupClockCallback(Fls_IpHostType *host, Fls_IpClockOpsType *clkOps)
{
    int ret = -1;

    if ((NULL_PTR != host) && (NULL_PTR != clkOps) &&
            (NULL_PTR != clkOps->getClkRate) && (NULL_PTR != clkOps->setClkRate))
    {
        host->clkOps = clkOps;
        ret = 0;
    }

    return ret;
}

int Fls_BusWaitIdle(Fls_BusHandleType *bus)
{
    return bus->ops->waitIdle(bus);
}

int Fls_BusWriteEnable(Fls_BusHandleType *bus, boolean enable)
{
    return bus->ops->writeEnable(bus, enable);
}

/**
 * \brief spi norflash instance initialization interface.
 * \details This function must used after Fls_Bushost_init and before other APIs.
 * \param[in, out] bus spi norflash instance contex handle, the data memory need alloc by user.
 * \param[in] busConfig spi norflash device config data, will not used after function return, so this param can be in stack.
 * \return int
 * \retval 0: sucess
 * \retval other: failed
 */
int Fls_BusInit(Fls_BusHandleType *bus, Fls_IpHostType *host,
                const Fls_BusConfigType *busConfig)
{
    int ret = -1;

    if (NULL_PTR == bus)
    {
        /* Do nothing */
    }
    else if (NULL_PTR != bus->ops)
    {
        ret = bus->ops->init(bus, host, busConfig);
    }
    else if (TRUE == busConfig->hyperbusMode)
    {
#ifdef FLS_HYPERBUS_FLASH_CNT
        bus->ops = &Fls_HyperbusOps;
        ret = Fls_HyperbusOps.init(bus, host, busConfig);
#endif /* #ifdef FLS_HYPERBUS_FLASH_CNT */
    }
    else
    {
#ifdef FLS_SPIBUS_FLASH_CNT
        bus->ops = &Fls_SpibusOps;
        ret = Fls_SpibusOps.init(bus, host, busConfig);
#endif /* #ifdef FLS_SPIBUS_FLASH_CNT */
    }

    return ret;
}

/**
 * \brief spi norflash instance destruction interface.
 * \param[in] bus spi norflash instance contex handle.
 */
void Fls_BusDeinit(Fls_BusHandleType *bus)
{
    bus->ops->deinit(bus);
}

/**
 * \brief spi norflash read interface.
 * \details When the buffer and read size aligned with cacheline size will provide best performance.
 * \param[in] bus spi norflash instance contex handle.
 * \param[in] addr spi norflash addr.
 * \param[in] buf Read buffer, alloc by user.
 * \param[in] size Read size, need aligned with 4bytes for dma limit.
 * \return int
 * \retval 0: sucess
 * \retval other: failed
 */
int Fls_BusRead(Fls_BusHandleType *bus, Fls_AddressType addr, uint8 *buf,
                Fls_LengthType size)
{
    return bus->ops->read(bus, addr, buf, size);
}

/**
 * \brief spi norflash write interface.
 * \details When the buffer and write size aligned with cacheline size will provide best performance.
 * \param[in] bus spi norflash instance contex handle.
 * \param[in] addr spi norflash addr.
 * \param[in] buf Write buffer, alloc by user.
 * \param[in] size Read size, need aligned with 4bytes for dma limit.
 * \return int
 * \retval 0: sucess
 * \retval other: failed
 */
int Fls_BusWrite(Fls_BusHandleType *bus, Fls_AddressType addr,
                 const uint8 *buf, Fls_LengthType size)
{
    return bus->ops->write(bus, addr, buf, size);
}
/**
 * \brief spi norflash erase interface.
 * \param[in] bus spi norflash instance contex handle.
 * \param[in] addr spi norflash addr.
 * \param[in] size Erase size, need aligned with sector_size what get by Fls_Busget_info API.
 * \return int
 * \retval 0: sucess
 * \retval other: failed
 */
int Fls_BusErase(Fls_BusHandleType *bus, Fls_AddressType addr,
                 Fls_LengthType size)
{
    return bus->ops->erase(bus, addr, size);
}


/**
 * \brief spi norflash get flash status interface.
 * \param[in] bus spi norflash instance contex handle.
 * \return int
 * \retval 0: flash is idle
 * \retval other: flash is busy
 */
int Fls_BusGetBusyStatus(Fls_BusHandleType *bus)
{
    return bus->ops->getBusyStatus(bus);
}

/**
 * \brief spi norflash async cancel interface.
 * \details Used for cancel the last tansfer what like read write or erase.
 * \param[in] bus spi norflash instance contex handle.
 * \return int
 * \retval 0: sucess
 * \retval other: failed
 */
int Fls_BusCancel(Fls_BusHandleType *bus)
{
    return bus->ops->cancel(bus);
}

/**
 * \brief Used for setup spi norflash async mode notification handler.
 * \details When use async mode, user can selet passive notification mode or active query mode.
 * \param[in] bus spi norflash instance contex handle.
 * \param[in] handler flash notification handler.
 */
void Fls_BusSetupNotificationCallback(Fls_BusHandleType *bus, Fls_BusNotificationType callback)
{
    bus->eventHandler = callback;
    return;
}

/**
 * \brief Used for get spi norflash async tansfer result.
 * \param[in] bus spi norflash instance contex handle.
 * \return Fls_BusOpsResultType
 * \retval FLS_BUS_OPS_COMPLETE: last transfer sucess
 * \retval FLS_BUS_OPS_FAILED: last tansfer failed
 * \retval FLS_BUS_OPS_PENDING: last tansfer not complete
 * \retval FLS_BUS_OPS_INCONSISTENT: last tansfer data error
 * \retval FLS_BUS_OPS_INVALID: last tansfer invalid
 */
Fls_BusOpsResultType Fls_BusGetResult(Fls_BusHandleType *bus)
{
    Fls_BusOpsResultType ret = FLS_BUS_OPS_INVALID;

    if (NULL_PTR != bus)
    {
        ret = bus->xferInfo.opsResult;
    }

    return ret;
}

/**
 * \brief Used for get spi norflash info what like sector size, page size, and ect.
 * \param[in] bus spi norflash instance contex handle.
 * \return Fls_BusFlashInfoType* Norflash info data.
 */
Fls_BusFlashInfoType *Fls_BusGetInfo(Fls_BusHandleType *bus)
{
    Fls_BusFlashInfoType *ret = NULL_PTR;

    if (NULL_PTR != bus)
    {
        ret = &bus->info;
    }

    return ret;
}

int Fls_BusSetProtectArea(Fls_BusHandleType *bus, Fls_AddressType addr,
                          Fls_LengthType size)
{
    int ret = -1;

    if ((NULL_PTR != bus) && (NULL_PTR != bus->info.SetProtectArea))
    {
        ret = bus->info.SetProtectArea(bus, addr, size);
    }

    return ret;
}

int Fls_BusEnterXipMode(Fls_BusHandleType *bus, boolean en)
{
    int ret = -1;

    if ((NULL_PTR != bus) && (NULL_PTR != bus->info.enterXipMode)
            && (NULL_PTR != bus->host->ops->enterXipMode))
    {
        if (0 == bus->info.enterXipMode(bus, en))
        {
            ret = bus->host->ops->enterXipMode(bus, en);
        }
    }

    return ret;
}

void Fls_IpWritel(Fls_IpContextType *ipCtx, uint32 addr, uint32 value)
{
    writel(value, ipCtx->apbBase + addr);
#ifdef FLS_IP_DEBUG

    if (1 == Fls_IpDebug)
    {
        FLS_DEBUG("w(0x%x, 0x%08x), r(0x%08x)\n", addr, value, readl(ipCtx->apbBase + addr));
    }

#endif /* #ifdef FLS_IP_DEBUG */
}

uint32 Fls_IpReadl(Fls_IpContextType *ipCtx, uint32 addr)
{
    uint32 value = readl(ipCtx->apbBase + addr);
#ifdef FLS_IP_DEBUG

    if (1 == Fls_IpDebug)
    {
        FLS_DEBUG("r(0x%x, r(0x%08x)\n", addr, value);
    }

#endif /* #ifdef FLS_IP_DEBUG */
    return value;
}

void Fls_IpWriteBits(Fls_IpContextType *ipCtx, uint32 addr,
                     uint8 startBit, uint8 width, uint32 val)
{
    REG_RMW32(ipCtx->apbBase + addr, startBit, width, val);
#ifdef FLS_IP_DEBUG

    if (1 == Fls_IpDebug)
    {
        FLS_DEBUG("wb(0x%x, bit[%d:%d] 0x%08x), r(0x%08x)\n", addr, startBit + width,
                  startBit, val, readl(ipCtx->apbBase + addr));
    }

#endif /* #ifdef FLS_IP_DEBUG */
}

void Fls_IpPretransClean(Fls_BusHandleType *bus)
{
    Fls_IpContextType *ipCtx = (Fls_IpContextType *)bus->host->privData;

    /* Config indirect read pre-transaction to 0 */
    Fls_IpWritel(ipCtx, FLS_IP_INDR_RD_PTC, 0U);

    /* Config direct write pre-transaction to 0 */
    Fls_IpWritel(ipCtx, FLS_IP_INDR_WR_PTC, 0U);
}

#define FLS_STOP_SEC_CODE
#include "Fls_MemMap.h"

#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */

/* End of file */
