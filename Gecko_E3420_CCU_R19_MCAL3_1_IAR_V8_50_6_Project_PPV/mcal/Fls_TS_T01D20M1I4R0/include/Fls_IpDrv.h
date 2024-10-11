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
 *  \file     Fls_IpDrv.h                                                                           *
 *  \brief    This file contains interface header for FLS MCAL driver, ...                             *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/07/26     <td>1.0.0                               *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifndef FLS_IPDRV_H
#define FLS_IPDRV_H

#ifdef __cplusplus
extern "C" {
#endif /* #ifdef __cplusplus */

#include "Fls_Bus.h"
#include "Fls_Fault.h"
#include <Dma.h>

#ifdef FLS_DEBUG_LOG
#include "debug.h"
#define FLS_DEBUG  PRINT
#else
#define FLS_DEBUG(...)
#endif /* FLS_DEBUG */

#define FLS_IP_ARCH_CACHE_LINE (32UL)

#define FLS_DIV_ROUND_UP(n,d) (((n) + (d) - 1U) / (d))
#define FLS_ROUNDUP(a, b) (((a) + (uint32)((b)-1U)) & (uint32)~((b)-1U))
#define FLS_ROUNDDOWN(a, b) ((a) & ~((b)-1U))
#define FLS_IS_ALIGNED(a, b) (0U == (((uint32)(a)) & (((uint32)(b))-1U)))
#define FLS_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define FLS_MAX(a, b) (((a) > (b)) ? (a) : (b))

#ifndef FLS_IP_USE_DMA
#define FLS_IP_USE_DMA (0)
#endif

#ifndef FLS_IP_USE_IRQ
#define FLS_IP_USE_IRQ (0)
#endif

#define ARRAY_SIZE(x) (sizeof(x)/sizeof((x)[0]))

typedef struct
{
    uint8 id;
    uint32 apbBase;
    uint32 directBase;
    unsigned int irq;
    unsigned long refClkHz;
    boolean prefetchEnable;
} Fls_IpConfigType;

typedef struct
{
    uint8 id;
    uint32 apbBase;
    uint32 directBase;
    unsigned int irq;
    unsigned long refClkHz;
    unsigned int sclkHz;
    boolean csDecoded;
    uint8 currentCs;
    boolean dqsEnable;
    uint8 fifoDepth;
    uint8 fifoWidth;
    uint32 directRangeSize;
    boolean prefetchEnable;
#if FLS_IP_USE_DMA
    uint8 dmaBurstWidth;
    uint32 dmaBurstSize;
    Dma_ChannelConfigType *dmaChannel;
#endif /* #if FLS_IP_USE_DMA */
} Fls_IpContextType;

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
int Fls_IpInit(Fls_IpHostType *host, const Fls_BusConfigType *config);

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
void Fls_IpDeinit(Fls_BusHandleType *bus);

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
void Fls_IpDelayUs(uint32 us);

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
int Fls_IpIrqHandler(uint32 irq, void *arg);
#ifndef NON_AUTOSAR_STANDARD_IRQ_HANDLER

#define FLS_IP_IRQ_FUNC_NAME(n) Fls_IpIrqHandlerChannel##n
#define FLS_IP_IRQ_HANDLER_FUNC(n) ISR(FLS_IP_IRQ_FUNC_NAME(n))

FLS_IP_IRQ_HANDLER_FUNC(0);
FLS_IP_IRQ_HANDLER_FUNC(1);
#if (FLS_IP_RESOURE_NUM >= 2)
FLS_IP_IRQ_HANDLER_FUNC(2);
FLS_IP_IRQ_HANDLER_FUNC(3);
#endif /* #if (FLS_IP_RESOURE_NUM >= 2) */
#endif /* #ifndef NON_AUTOSAR_STANDARD_IRQ_HANDLER */
#endif /* #if (FLS_IP_USE_IRQ != 0) */

#ifdef FLS_RFD_ENABLE_CNT
int Fls_IpEnableRfd(Fls_BusHandleType *bus);
#endif /* #ifdef FLS_RFD_ENABLE_CNT */
void Fls_BusSetupXfer(Fls_BusHandleType *nor, Fls_BusOpsType opt,
                      Fls_AddressType addr, uint8 *readBuf,
                      const uint8 *writeBuf, Fls_LengthType size);
void Fls_BusXferComplete(Fls_BusHandleType *nor);
void Fls_BusXferError(Fls_BusHandleType *nor);
int Fls_BusSetupClockCallback(Fls_IpHostType *host, Fls_IpClockOpsType *clkOps);
int Fls_BusWaitIdle(Fls_BusHandleType *bus);
int Fls_BusWriteEnable(Fls_BusHandleType *bus, boolean enable);
int Fls_BusInit(Fls_BusHandleType *bus, Fls_IpHostType *host,
                const Fls_BusConfigType *busConfig);
void Fls_BusDeinit(Fls_BusHandleType *bus);
int Fls_BusRead(Fls_BusHandleType *bus, Fls_AddressType addr, uint8 *buf,
                Fls_LengthType size);
int Fls_BusWrite(Fls_BusHandleType *bus, Fls_AddressType addr,
                 const uint8 *buf, Fls_LengthType size);
int Fls_BusErase(Fls_BusHandleType *bus, Fls_AddressType addr,
                 Fls_LengthType size);
int Fls_BusGetBusyStatus(Fls_BusHandleType *bus);
int Fls_BusCancel(Fls_BusHandleType *bus);
void Fls_BusSetupNotificationCallback(Fls_BusHandleType *bus, Fls_BusNotificationType callback);
Fls_BusOpsResultType Fls_BusGetResult(Fls_BusHandleType *bus);
Fls_BusFlashInfoType *Fls_BusGetInfo(Fls_BusHandleType *bus);
int Fls_BusSetProtectArea(Fls_BusHandleType *bus, Fls_AddressType addr,
                          Fls_LengthType size);
int Fls_BusEnterXipMode(Fls_BusHandleType *bus, boolean en);

#ifdef __cplusplus
}
#endif /* #ifdef __cplusplus */
#endif /* #if FLS_IPDRV_H */

/* End of file */
