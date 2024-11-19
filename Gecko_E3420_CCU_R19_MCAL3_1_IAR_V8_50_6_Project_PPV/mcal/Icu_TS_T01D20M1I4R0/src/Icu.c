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
 * \file     Icu.c                                                                                      *
 * \brief    This file mainly contains the implementation of the autosar standard                       *
 *           interface                                                                                  *
 *                                                                                                      *
 * <table>                                                                                              *
 * <tr><th>Date           <th>Version                                                                   *
 * <tr><td>2023/08/18     <td>1.0.0                                                                     *
 * </table>                                                                                             *
 *******************************************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/********************************************************************************************************
 *                                      Include header files                                            *
 *******************************************************************************************************/
/* icu-self definition */
#include "Icu.h"
#if (STD_ON == ICU_DEV_ERROR_DETECT)
/* det_err report file */
/** Traceability       : SWSR_ICU_003 */
#include "Det.h"
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
/* safety mcal report file */
#include "FuSaMcalReportError.h"
#endif /* STD_ON == ICU_SAFETY_ENABLE */
#if (STD_ON == ICU_DMA_SUPPORT)
/* dma driver file */
#include "Dma.h"
#endif /* STD_ON == ICU_DMA_SUPPORT */
/* critical section protection file */
#include "SchM_Icu.h"
/* icu fault injection file */
#include "Icu_Fault.h"

/********************************************************************************************************
 *                                 Imported Compiler Switch Checks                                      *
 *******************************************************************************************************/
#ifndef ICU_SW_MAJOR_VERSION
#error "ICU_SW_MAJOR_VERSION is not defined."
#endif

#ifndef ICU_SW_MINOR_VERSION
#error "ICU_SW_MINOR_VERSION is not defined."
#endif

#ifndef ICU_SW_PATCH_VERSION
#error "ICU_SW_PATCH_VERSION is not defined."
#endif

#ifndef ICU_AR_RELEASE_MAJOR_VERSION
#error "ICU_AR_RELEASE_MAJOR_VERSION is not defined."
#endif

#ifndef ICU_AR_RELEASE_MINOR_VERSION
#error "ICU_AR_RELEASE_MINOR_VERSION is not defined."
#endif

#ifndef ICU_AR_RELEASE_REVISION_VERSION
#error "ICU_AR_RELEASE_REVISION_VERSION is not defined."
#endif

#if(ICU_AR_RELEASE_MAJOR_VERSION != 4U)
#error "ICU_AR_RELEASE_MAJOR_VERSION does not match."
#endif

#if(ICU_AR_RELEASE_MINOR_VERSION != 3U)
#error "ICU_AR_RELEASE_MAJOR_VERSION does not match."
#endif

/********************************************************************************************************
 *                                      Static variables                                                *
 *******************************************************************************************************/

/* memap infomation */
#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Icu_MemMap.h"

/* icu driver initial status */
static Icu_InitialStateType Icu_DriverState;
/* pointer to the icu channnels configuration */
static const Icu_ConfigType* Icu_ConfigPtr;
/* whether the icu channel is running now */
static boolean Icu_ChanRunningStatus[NUM_OF_CHANNEL];

#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/* whether to get the first value in multi capture mode  */
static boolean Icu_MulHaveGotValFlag[MULTI_CPT_MODULE_NUM];
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */

#if (STD_ON == ICU_EDGE_COUNT_API)
/* edge count value for icu channel */
static Icu_EdgeNumberType Icu_ChanEdgeCnt[NUM_OF_CHANNEL];
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/* edge count value for icu channel */
static Icu_EdgeNumberType Icu_MulChanEdgeCnt[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
#endif /* STD_ON == ICU_EDGE_COUNT_API */

#if (STD_ON == ICU_TIMESTAMP_API)
/* whether the timestamp mode channel is running */
static boolean Icu_ChanTsActived[NUM_OF_CHANNEL];
/* store the address of the timestamp buffer passed in externally */
static Icu_ValueType* Icu_ChanBufferPtr[NUM_OF_CHANNEL];
/* store the size of the timestamp buffer passed in externally */
static uint32 Icu_TsBufferSize[NUM_OF_CHANNEL];
/* store the interval of the timestamp buffer passed in externally */
static uint32 Icu_TsNotifyInterval[NUM_OF_CHANNEL];
/* store the index of the timestamp buffer */
static uint32 Icu_TsCurrentSize[NUM_OF_CHANNEL];
/* the least common multiple of the size and interval */
static uint32 Icu_TsMaxSize[NUM_OF_CHANNEL];
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/* whether the timestamp mode channel is running */
static boolean Icu_MulChanTsActived[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
/* store the address of the timestamp buffer passed in externally */
static Icu_ValueType* Icu_MulTsChanBufferPtr[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
/* store the size of the timestamp buffer passed in externally */
static uint32 Icu_MulTsBufferSize[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
/* store the interval of the timestamp buffer passed in externally */
static uint32 Icu_MulTsNotifyInterval[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
/* store the index of the timestamp buffer */
static uint32 Icu_MulTsCurrentSize[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
/* the least common multiple of the size and interval */
static uint32 Icu_MulTsMaxSize[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
#endif /* STD_ON == ICU_TIMESTAMP_API */

#if (STD_ON == ICU_GET_INPUTSTATE_API)
/* whether recieved the activation edge */
static Icu_InputStateType Icu_ChanInputSta[NUM_OF_CHANNEL];
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/* whether recieved the activation edge */
static Icu_InputStateType Icu_MulChanInputSta[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */

/* whether to support calling the notification function */
static boolean Icu_ChanNtfyEnable[NUM_OF_CHANNEL];
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/* whether the sub-channel of multi capture mode is enabled */
static boolean Icu_MulChanEnable[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
/* whether the etimer of multi capture mode is enabled */
static boolean Icu_MulTimerEnable[MULTI_CPT_MODULE_NUM];
/* whether to support calling the notification function */
static boolean Icu_MulNtfyEnable[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
/* store the last captured leval status */
static uint32 Icu_MulPreIoVlue[MULTI_CPT_MODULE_NUM];
/* store the sub-channel on which the edge changed */
static uint32 Icu_MulChangeIoChan[MULTI_CPT_MODULE_NUM];
/* store the last captured timestamp value */
static uint32 Icu_MulPreCptTime[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
/* store the type of edge change produced */
static Icu_MultiCptEdgeChangeType Icu_MulEdgeChange[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */

#if (STD_ON == ICU_DMA_SUPPORT)
/* whether the dma is running */
static boolean Icu_ChanDmaIsRuning[NUM_OF_CHANNEL];
/* the flag bit of the half buffer carried by dma */
static boolean Icu_HalfBufferFlag[NUM_OF_CHANNEL];
#endif /* STD_ON == ICU_DMA_SUPPORT */

#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
/* the flag bit of the half buffer carried by dma */
static boolean Icu_MulHalfBufferFlag[MULTI_CPT_MODULE_NUM];
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */

/********************************************************************************************************
 *                                      GLobal variables                                                *
 *******************************************************************************************************/

/* physical to logic channel mapping */
uint8 Icu_PhyToLogMap[TIMER_MODULE_NUMBER][LOCAL_CHANNEL_NUMBER];

#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/* the activation edge for sub-channel */
Icu_ActivationType Icu_MulEdgeSelect[MULTI_CPT_MODULE_NUM][MULTI_CPT_MAX_IO_NUM];
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */

/* memap infomation */
#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Icu_MemMap.h"

#if (STD_ON == ICU_DMA_SUPPORT)
/* the destination buffer of dma transfer data */
#if (STD_ON == ICU_NON_CACHE_NEEDED)
/* memap infomation */
#define ICU_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#include "Icu_MemMap.h"
/* PRQA S 1751  2 */
uint32 Icu_ChanRxBuffer[NUM_OF_CHANNEL][(ICU_RX_BURST_LEN * 2U)];
/* memap infomation */
#define ICU_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#include "Icu_MemMap.h"
#else
/* memap infomation */
#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Icu_MemMap.h"
/* PRQA S 1751  2 */
uint32 Icu_ChanRxBuffer[NUM_OF_CHANNEL][(ICU_RX_BURST_LEN * 2U)]
                                                        LOCATE_ALIGNED(ICU_CONFIG_ARCH_CACHE_LINE);
/* memap infomation */
#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Icu_MemMap.h"
#endif /* STD_ON == ICU_NON_CACHE_NEEDED */
#endif /* STD_ON == ICU_DMA_SUPPORT */

#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
#if (STD_ON == ICU_NON_CACHE_NEEDED)
/* memap infomation */
#define ICU_START_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#include "Icu_MemMap.h"
/* the destination buffer of channel B */
/* PRQA S 1751  2 */
uint32 Icu_MulChanbBuffer[MULTI_CPT_MODULE_NUM][MULTI_CPT_BURST_LEN * 2U];
/* the destination buffer of channel C */
/* PRQA S 1751  2 */
uint32 Icu_MulChancBuffer[MULTI_CPT_MODULE_NUM][MULTI_CPT_BURST_LEN * 2U];
/* memap infomation */
#define ICU_STOP_SEC_VAR_NO_INIT_NO_CACHE_UNSPECIFIED
#include "Icu_MemMap.h"
#else
/* memap infomation */
#define ICU_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Icu_MemMap.h"
/* the destination buffer of channel B */
/* PRQA S 1751  2 */
uint32 Icu_MulChanbBuffer[MULTI_CPT_MODULE_NUM][MULTI_CPT_BURST_LEN * 2U]
                                                        LOCATE_ALIGNED(ICU_CONFIG_ARCH_CACHE_LINE);
/* the destination buffer of channel C */
/* PRQA S 1751  2 */
uint32 Icu_MulChancBuffer[MULTI_CPT_MODULE_NUM][MULTI_CPT_BURST_LEN * 2U]
                                                        LOCATE_ALIGNED(ICU_CONFIG_ARCH_CACHE_LINE);
/* memap infomation */
#define ICU_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Icu_MemMap.h"
#endif /* STD_ON == ICU_NON_CACHE_NEEDED */
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */

/********************************************************************************************************
 *                                      Static fcuntion                                                 *
 *******************************************************************************************************/

/* memap infomation */
#pragma default_function_attributes = @".iram_func"
#define ICU_START_SEC_CODE
#include "Icu_MemMap.h"

static Std_ReturnType Icu_ValidateCommon(Icu_ChannelType channel, uint8 serviceId);
static void Icu_SingleIrqCommon(Icu_HwModule tmrModule);
#if (STD_ON == ICU_TIMESTAMP_API)
static Std_ReturnType Icu_ValidateParamStamp(const Icu_ValueType *BufferPtr, uint16 bufferSize, uint16 notifyInterval);
static void Icu_SingleTsHandler (Icu_HwModule tmrModule, Icu_HwChannel hwChannel, uint8 logicChannel, Icu_TimestampBufferType bufferType);
#if (STD_ON == ICU_DMA_SUPPORT)
static void Icu_SingleDmaTsHandler(Icu_HwModule tmrModule, Icu_HwChannel hwChannel, uint8 logicChannel, Icu_TimestampBufferType bufferType, uint32 initBufferIdx);
#endif /* STD_ON == ICU_DMA_SUPPORT */
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
static boolean Icu_MultiCptRestoreTsVaribles(Icu_HwModule tmrModule, uint8 subChan, uint8 mulChnNumber);
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
#endif /* STD_ON == ICU_TIMESTAMP_API */
#if (STD_ON == ICU_DEINIT_API)
static Std_ReturnType Icu_ValidateDeInit(void);
static void Icu_SingleRestoreVaribles(Icu_ChannelType logicChan);
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
static void Icu_MultiCptRestoreAllVaribles(Icu_HwModule tmrModule);
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
#endif /* STD_ON == ICU_DEINIT_API */
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
static boolean Icu_MultiCptOffTimerCheck(Icu_HwModule tmrModule, uint8 mulChanNum);
static void Icu_MultiCptTsHandler(Icu_HwModule tmrModule, uint8 logicChannel, uint8 subChannel, Icu_TimestampBufferType bufferType, uint32 tsValue);
static void Icu_MultiCptEdgeChangeHandler(Icu_HwModule tmrModule, uint8 logicChannel, uint8 subChannel, uint32 tsValue);
static void Icu_MultiCptValueHandler(Icu_HwModule tmrModule);
static void Icu_MultiIrqCommon(Icu_HwModule tmrModule);
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */

/** *****************************************************************************************************
 * \brief General parameter verification of icu driver.
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Icu_ValidateCommon(
 *                                   Icu_ChannelType channel, uint8 serviceId)
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : channel - numeric identifier of the ICU channel
 *                      serviceId - service function id
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Parameter verification result
 *
 * Description        : General parameter verification of icu driver.
 * \endverbatim
 * Traceability       : SW_SM001 SW_SM006
 *******************************************************************************************************/
static Std_ReturnType Icu_ValidateCommon(Icu_ChannelType channel, uint8 serviceId)
{
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType retVal = E_OK;
    uint8 chanIdx = (uint8)(channel & ICU_ACTUAL_CHAN_INDEX_MASK);
    uint8 ioIdx = (uint8)((channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
    uint8 mulChanNum;
    /* #10 parameter validity check */
    /* driver initial status check */
    if (ICU_STATUS_UNINIT == Icu_DriverState)
    {
        errId = ICU_E_UNINIT;
        retVal = E_NOT_OK;
    }
    /* channel validity check */
    else if (chanIdx >= NUM_OF_CHANNEL)
    {
        errId = ICU_E_PARAM_CHANNEL;
        retVal = E_NOT_OK;
    }
    /* channel config pointer validity check */
    else if (NULL_PTR == Icu_ConfigPtr)
    {
        errId = ICU_E_PARAM_POINTER;
        retVal = E_NOT_OK;
    }
    else
    {
        mulChanNum = (*(Icu_ConfigPtr->chanConfigPtr))[chanIdx].icuHwChanCfgPtr->multiCptChanNum;
        /* high 8 bit channel validity check */
        if (ioIdx >= mulChanNum)
        {
            errId = ICU_E_PARAM_CHANNEL;
            retVal = E_NOT_OK;
        } /* else not needed */
    }
    /* #20 report error */
    if (ICU_E_PARAM_INVALID_VALUE != errId)
    {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID, (uint8)serviceId,
                              (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID, (uint8)serviceId,
                              (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
    } /* else not needed */

    return retVal;
}

/** *****************************************************************************************************
 * \brief Interrupt handler function in the case of single capture mode.
 *
 * \verbatim
 * Syntax             : static void Icu_SingleIrqCommon(
 *                                                      Icu_HwModule tmrModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module uint
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt handler function in the case of single capture
 *                      mode.
 * \endverbatim
 * Traceability       : SWSR_ICU_190
 *******************************************************************************************************/
static void Icu_SingleIrqCommon(Icu_HwModule tmrModule)
{
    /* init local varibles */
    Icu_MeasurementModeType measureType;
    uint32 irqStatus;
    uint8 logChannel;
    Icu_HwChannel hwChannel;
    uint8 j;
    boolean fifoErr;
#if (STD_ON == ICU_TIMESTAMP_API)
    Icu_TimestampBufferType bufferType;
#endif /* STD_ON == ICU_TIMESTAMP_API */
    /* #10 get the interrupt information */
    irqStatus = Icu_Ip_GetInterrupt(tmrModule);
    for (j = 0U; j < (uint8)LOCAL_CHANNEL_NUMBER; j++)
    {
        if (((irqStatus >> j) & 0x1u) > 0U)
        {
            /* PRQA S 4342 1 */
            hwChannel = (Icu_HwChannel)j;
            /* get the logic channel number */
            logChannel = Icu_PhyToLogMap[tmrModule][hwChannel];
            (void)Icu_Ip_ClearInterrupt(tmrModule, hwChannel);
            /* #20 check if fifo has error generate */
            fifoErr = Icu_Ip_CheckFifoSta(tmrModule, hwChannel);
            IcuHookBegin_Icu_SingleCptFifoErr();
            if (TRUE == fifoErr)
            {
                IcuHookEnd_Icu_SingleCptFifoErr();
                continue;
            } /* else not needed */
            /* #30 calculation processing according to the measurement mode */
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChannel].icuMeasurementMode;
            switch (measureType)
            {
#if (STD_ON == ICU_SIGNALMEASUREMENT_API)
            /* #40 signal measurement mode processing */
            case ICU_MODE_SIGNAL_MEASUREMENT:
            {
                Icu_Ip_SigMeasurementIrq(&(*(Icu_ConfigPtr->chanConfigPtr))[logChannel]);
                break;
            }
#endif /* STD_ON == ICU_SIGNALMEASUREMENT_API*/
#if (STD_ON == ICU_EDGE_COUNT_API)
            /* #50 edge counter mode processing */
            case ICU_MODE_EDGE_COUNTER:
            {
                ++Icu_ChanEdgeCnt[logChannel];
                break;
            }

#endif /* STD_ON == ICU_EDGE_COUNT_API */
#if (STD_ON == ICU_TIMESTAMP_API)
            /* #60 timestamp mode processing */
            case ICU_MODE_TIMESTAMP:
            {
                bufferType = (*(Icu_ConfigPtr->chanConfigPtr))
                    [logChannel].measureParamPtr->Icu_TimestampMeasurement.tsBufferProperty;
                /* timestamp mode handler in interrupt mode */
                Icu_SingleTsHandler(tmrModule, hwChannel, logChannel, bufferType);
                break;
            }

#endif /* STD_ON == ICU_TIMESTAMP_API */
#if (STD_ON == ICU_EDGE_DETECT_API)
            /* #70 edge detection mode processing */
            case ICU_MODE_SIGNAL_EDGE_DETECT:
            {
#if (STD_ON == ICU_GET_INPUTSTATE_API)
                /* update the input status */
                Icu_ChanInputSta[logChannel] = ICU_ACTIVE;
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */
                if ((boolean)TRUE == Icu_ChanNtfyEnable[logChannel])
                {
                    /* call the notification function */
                    (*(Icu_ConfigPtr->chanConfigPtr))
                        [logChannel].measureParamPtr->Icu_SignalEdgeDetection.sigNotifyFuncPtr();
                } /* else not needed */
                break;
            }
#endif /* STD_ON == ICU_EDGE_DETECT_API */
            default:
            {
		        /* do nothing to avoid warning */
                break;
            }
            }
        }
    }
}

#if (STD_ON == ICU_TIMESTAMP_API)
/** *****************************************************************************************************
 * \brief Timestamp mode parameter verification
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Icu_ValidateParamStamp(
 *                          const Icu_ValueType *BufferPtr, uint16 bufferSize,
 *                          uint16 notifyInterval)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : bufferSize - buffer size parameter of timestamp channel
 *                      notifyInterval - noyify interval value of timestamp
 *                                       channel
 *                      BufferPtr - pointer to the buffer-array where the
 *                                  timestamp values shall be placed
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Parameter verification result
 *
 * Description        : Timestamp mode parameter verification
 * \endverbatim
 * Traceability       : SWSR_ICU_089 SWSR_ICU_090 SWSR_ICU_091 SWSR_ICU_092
 *                      SWSR_ICU_093
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
static Std_ReturnType Icu_ValidateParamStamp(const Icu_ValueType *BufferPtr, uint16 bufferSize, uint16 notifyInterval)
{
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType retVal = E_OK;

    /* #10 timestamp parameter validity check */
    if (NULL_PTR == BufferPtr)
    {
        errId = ICU_E_PARAM_POINTER;
        retVal = E_NOT_OK;
    }
    /* buffer size check */
    else if (0U == bufferSize)
    {
        errId = ICU_E_PARAM_BUFFER_SIZE;
        retVal = E_NOT_OK;
    }
    /* notify interval value check */
    else if ((0U == notifyInterval) || (notifyInterval > bufferSize))
    {
        errId = ICU_E_PARAM_NOTIFY_INTERVAL;
        retVal = E_NOT_OK;
    }
    else
    {
        /* do nothing to avoid warning */
    }
    /* #20 report error */
    if (ICU_E_PARAM_INVALID_VALUE != errId)
    {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                (uint8)ICU_START_TIME_STAMP_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                (uint8)ICU_START_TIME_STAMP_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
    } /* else not needed */
    return retVal;
}

/** *****************************************************************************************************
 * \brief Icu handles the timestamp mode channel
 *
 * \verbatim
 * Syntax             : static void Icu_SingleTsHandler (
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel,
 *                              uint8 logicChannel,
 *                              Icu_TimestampBufferType bufferType)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module uint channel
 *                      hwChannel - etimer hardware channel
 *                      logicChannel - logic channel index
 *                      bufferType - buffer type in timestamp mode
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Parameter verification result
 *
 * Description        : Icu handles the timestamp mode channel
 * \endverbatim
 * Traceability       : SWSR_ICU_082 SWSR_ICU_083 SWSR_ICU_084 SWSR_ICU_085
 *                      SWSR_ICU_086 SWSR_ICU_087 SWSR_ICU_089 SWSR_ICU_090
 *                      SWSR_ICU_190
 *******************************************************************************************************/
static void Icu_SingleTsHandler (Icu_HwModule tmrModule, Icu_HwChannel hwChannel, uint8 logicChannel, Icu_TimestampBufferType bufferType)
{
    /* init local varibles */
    uint8 fifoIdx;
    uint32 bufIndex;
    /* #10 get fifo number value */
    uint8 fifoEntry = Icu_Ip_GetFifoEntry(tmrModule, hwChannel);
    for(fifoIdx = 0U; fifoIdx < fifoEntry; fifoIdx++)
    {
        if (ICU_LINEAR_BUFFER == bufferType)
        {
            /* #20 linear buffer mode handler */
            if (Icu_TsCurrentSize[logicChannel] >= Icu_TsBufferSize[logicChannel])
            {
                /* irq situation no need to check the parameter */
                (void)Icu_Ip_TurnOffCapture(tmrModule, hwChannel, FALSE);
                Icu_ChanTsActived[logicChannel] = (boolean)FALSE;
                Icu_ChanRunningStatus[logicChannel] = (boolean)FALSE;
            }
            else
            {
                Icu_ChanBufferPtr[logicChannel][Icu_TsCurrentSize[logicChannel]] =
                    Icu_Ip_GetFifoVal(tmrModule, hwChannel);
                Icu_TsCurrentSize[logicChannel]++;
            }
        }
        else
        {
            /* #30 circular buffer mode handler */
            if (Icu_TsBufferSize[logicChannel] > 0U)
            {
                bufIndex = Icu_TsCurrentSize[logicChannel] % Icu_TsBufferSize[logicChannel];
                Icu_ChanBufferPtr[logicChannel][bufIndex] = Icu_Ip_GetFifoVal(tmrModule, hwChannel);
                Icu_TsCurrentSize[logicChannel]++;
            } /* else not needed */
            if (Icu_TsMaxSize[logicChannel] == Icu_TsCurrentSize[logicChannel])
            {
                Icu_TsCurrentSize[logicChannel] = 0U;
            } /* else not needed */
        }
        /* #40 notification function handler */
        if (Icu_TsNotifyInterval[logicChannel] > 0U)
        {
            if (((boolean)TRUE == Icu_ChanNtfyEnable[logicChannel]) &&
                ((0U == (Icu_TsCurrentSize[logicChannel] % Icu_TsNotifyInterval[logicChannel]))))
            {
                (*(Icu_ConfigPtr->chanConfigPtr))
                    [logicChannel].measureParamPtr->Icu_TimestampMeasurement.tsNotifyFuncPtr();
            } /* else not needed */
        } /* else not needed */
        if (FALSE == Icu_ChanTsActived[logicChannel])
        {
            /* the buffer size is overflow in linear buffer mode */
            break;
        } /* else not needed */
    }
}

#if (STD_ON == ICU_DMA_SUPPORT)
/** *****************************************************************************************************
 * \brief Icu handles the timestamp buffer channel when using dma
 *
 * \verbatim
 * Syntax             : static void Icu_SingleDmaTsHandler(
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel,
 *                              uint8 logicChannel,
 *                              Icu_TimestampBufferType bufferType,
 *                              uint32 initBufferIdx)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module uint channel
 *                      hwChannel - etimer hardware channel
 *                      logicChannel - logic channel index
 *                      bufferType - buffer type in timestamp mode
 *                      initBufferIdx - initial buffer handle index
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Parameter verification result
 *
 * Description        : Icu handles the timestamp buffer channel when using dma
 * \endverbatim
 * Traceability       : SWSR_ICU_082 SWSR_ICU_083 SWSR_ICU_084 SWSR_ICU_085
 *                      SWSR_ICU_086 SWSR_ICU_087 SWSR_ICU_089 SWSR_ICU_090
 *                      SWSR_ICU_205
 *******************************************************************************************************/
static void Icu_SingleDmaTsHandler(Icu_HwModule tmrModule, Icu_HwChannel hwChannel, uint8 logicChannel, Icu_TimestampBufferType bufferType, uint32 initBufferIdx)
{
    /* init local varibles */
    uint32 bufIndex;
    uint32 loopCount;
    uint32 endBufferIdx = initBufferIdx + ICU_RX_BURST_LEN;
    for (loopCount = initBufferIdx; loopCount < endBufferIdx; loopCount++)
    {
        if (ICU_LINEAR_BUFFER == bufferType)
        {
            /* #10 linear buffer mode handler */
            if (Icu_TsCurrentSize[logicChannel] >= Icu_TsBufferSize[logicChannel])
            {
                /* irq situation no need to check the parameter */
                (void)Icu_Ip_TurnOffCapture(tmrModule, hwChannel, TRUE);
                Icu_ChanTsActived[logicChannel] = (boolean)FALSE;
                Icu_ChanRunningStatus[logicChannel] = (boolean)FALSE;
            }
            else
            {
                Icu_ChanBufferPtr[logicChannel][Icu_TsCurrentSize[logicChannel]] =
                    Icu_ChanRxBuffer[logicChannel][loopCount];
                Icu_TsCurrentSize[logicChannel]++;

            }
        }
        else
        {
            /* #20 circular buffer mode handler */
            if (Icu_TsBufferSize[logicChannel] > 0U)
            {
                bufIndex = Icu_TsCurrentSize[logicChannel] % Icu_TsBufferSize[logicChannel];
                Icu_ChanBufferPtr[logicChannel][bufIndex] = Icu_ChanRxBuffer[logicChannel][loopCount];
                Icu_TsCurrentSize[logicChannel]++;
            } /* else not needed */
            if (Icu_TsMaxSize[logicChannel] == Icu_TsCurrentSize[logicChannel])
            {
                Icu_TsCurrentSize[logicChannel] = 0U;
            } /* else not needed */
        }
        /* #30 notification function handler */
        if (Icu_TsNotifyInterval[logicChannel] > 0U)
        {
            if (((boolean)TRUE == Icu_ChanNtfyEnable[logicChannel]) &&
                ((0U == (Icu_TsCurrentSize[logicChannel] % Icu_TsNotifyInterval[logicChannel]))))
            {
                (*(Icu_ConfigPtr->chanConfigPtr))
                    [logicChannel].measureParamPtr->Icu_TimestampMeasurement.tsNotifyFuncPtr();
            } /* else not needed */
        } /* else not needed */
        if (FALSE == Icu_ChanTsActived[logicChannel])
        {
            /* the buffer size is overflow in linear buffer mode */
            break;
        } /* else not needed */
    }
}
#endif /* STD_ON == ICU_DMA_SUPPORT */

#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/** *****************************************************************************************************
 * \brief Restore timestamp parameters releated in multi capture mode
 *
 * \verbatim
 * Syntax             : static void Icu_SingleDmaTsHandler(
 *                              Icu_HwModule tmrModule, Icu_HwChannel hwChannel,
 *                              uint8 logicChannel,
 *                              Icu_TimestampBufferType bufferType,
 *                              uint32 initBufferIdx)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module uint channel
 *                      subChan - sub channel id in multi capture mode
 *                      mulChnNumber - total channel number in multi capture
 *                                     mode
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The conditions for closing the capture are met
 *
 * Description        : Icu handles the timestamp buffer channel when using dma
 * \endverbatim
 * Traceability       : SWSR_ICU_206
 *******************************************************************************************************/
static boolean Icu_MultiCptRestoreTsVaribles(Icu_HwModule tmrModule, uint8 subChan, uint8 mulChnNumber)
{
    /* init local varibles */
    boolean offTimer = TRUE;
    uint8 i;
    /* #10 restore timastamp varibles */
    Icu_MulChanEnable[tmrModule][subChan] = FALSE;
    Icu_MulTsBufferSize[tmrModule][subChan] = 0U;
    Icu_MulTsCurrentSize[tmrModule][subChan] = 0U;
    Icu_MulTsNotifyInterval[tmrModule][subChan] = 0U;
    Icu_MulTsMaxSize[tmrModule][subChan] = 0UL;
    Icu_MulChanTsActived[tmrModule][subChan] = (boolean)FALSE;
    /* #20 check if all xtrg.Io disable */
    for (i = 0U; i < mulChnNumber; i++)
    {
        if (TRUE == Icu_MulChanEnable[tmrModule][i])
        {
            offTimer = FALSE;
            break;
        } /* else not needed */
    }
    return offTimer;
}
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
#endif /* STD_ON == ICU_TIMESTAMP_API */


#if (STD_ON == ICU_DEINIT_API)
/** *****************************************************************************************************
 * \brief Verify that the driver meets the conditions of deinit
 *
 * \verbatim
 * Syntax             : static Std_ReturnType Icu_ValidateDeInit(void)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Parameter verification result
 *
 * Description        : Verify that the driver meets the conditions of deinit
 * \endverbatim
 * Traceability       : SWSR_ICU_049 SWSR_ICU_050 SWSR_ICU_051
 *******************************************************************************************************/
static Std_ReturnType Icu_ValidateDeInit(void)
{
    /* init local varibles */
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType retVal = E_OK;
    Icu_ChannelType channel;
    /* #10 check driver status */
    if (ICU_STATUS_UNINIT == Icu_DriverState)
    {
        errId = ICU_E_UNINIT;
        retVal = E_NOT_OK;
    }
    else if (NULL_PTR == Icu_ConfigPtr)
    {
        errId = ICU_E_PARAM_POINTER;
        retVal = E_NOT_OK;
    }
    else
    {
        /* #20 check driver channel status */
        for (channel = 0U; channel < NUM_OF_CHANNEL; channel++)
        {
            /* get the channel hardware information */
            if (TRUE == Icu_ChanRunningStatus[channel])
            {
                errId = ICU_E_PARAM_CHANNEL;
                retVal = E_NOT_OK;
                break;
            } /* else not needed */
        }
    }
    if (ICU_E_PARAM_INVALID_VALUE != errId)
    {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                  (uint8)ICU_DEINIT_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                  (uint8)ICU_DEINIT_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
    } /* else not needed */

    return retVal;
}

/** *****************************************************************************************************
 * \brief Restore parameters releated in single capture mode
 *
 * \verbatim
 * Syntax             : static void Icu_SingleRestoreVaribles(
 *                                                  Icu_ChannelType logicChan)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : logicChan - icu logic channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Restore parameters releated in single capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_048
 *******************************************************************************************************/
static void Icu_SingleRestoreVaribles(Icu_ChannelType logicChan)
{
    Icu_ChanNtfyEnable[logicChan] = FALSE;
#if (STD_ON == ICU_GET_INPUTSTATE_API)
    /* #10 restore channel input status */
    Icu_ChanInputSta[logicChan] = ICU_IDLE;
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */
#if (STD_ON == ICU_EDGE_COUNT_API)
    /* #20 restore edge count number */
    Icu_ChanEdgeCnt[logicChan] = 0U;
#endif /* STD_ON == ICU_EDGE_COUNT_API */

#if (STD_ON == ICU_TIMESTAMP_API)
    /* #30 restore timestamp mode varibles */
    Icu_ChanBufferPtr[logicChan] = NULL_PTR;
    Icu_TsBufferSize[logicChan] = 0U;
    Icu_TsCurrentSize[logicChan] = 0U;
    Icu_TsNotifyInterval[logicChan] = 0U;
    Icu_ChanTsActived[logicChan] = (boolean)FALSE;
#endif /* STD_ON == ICU_TIMESTAMP_API */

#if (STD_ON == ICU_DMA_SUPPORT)
    /* #40 restore dma mode varibles */
    Icu_ChanDmaIsRuning[logicChan] = FALSE;
    Icu_HalfBufferFlag[logicChan] = FALSE;
#endif
}

#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/** *****************************************************************************************************
 * \brief Restore parameters releated in multi capture mode
 *
 * \verbatim
 * Syntax             : static void Icu_MultiCptRestoreAllVaribles(
 *                                                      Icu_HwModule tmrModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : logicChan - icu logic channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Restore parameters releated in multi capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_048 SWSR_ICU_206
 *******************************************************************************************************/
static void Icu_MultiCptRestoreAllVaribles(Icu_HwModule tmrModule)
{
    /* init local vaibles */
    uint8 i;
    /* restore sub-channel varibles */
    for (i = 0U; i < MULTI_CPT_MAX_IO_NUM; i++)
    {
        /* #10 restore the sub-channel varibles in multi captre mode */
        Icu_MulChanEnable[tmrModule][i] = FALSE;
        Icu_MulNtfyEnable[tmrModule][i] = FALSE;
        Icu_MulEdgeSelect[tmrModule][i] = ICU_RISING_EDGE;
        Icu_MulEdgeChange[tmrModule][i] = ICU_MULTI_CPT_RISING_EDGE;
        Icu_MulPreCptTime[tmrModule][i] = 0UL;
#if (STD_ON == ICU_GET_INPUTSTATE_API)
        /* #20 set multi cpt io init tatus */
        Icu_MulChanInputSta[tmrModule][i] = ICU_IDLE;
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */
#if (STD_ON == ICU_EDGE_COUNT_API)
        /* #30 restore the edge counter mode varibles */
        Icu_MulChanEdgeCnt[tmrModule][i] = 0UL;
#endif /* STD_ON == ICU_EDGE_COUNT_API */
#if (STD_ON == ICU_TIMESTAMP_API)
        /* #40 restore the timestamp mode varibles */
        Icu_MulTsChanBufferPtr[tmrModule][i] = NULL_PTR;
        Icu_MulTsBufferSize[tmrModule][i] = 0U;
        Icu_MulTsCurrentSize[tmrModule][i] = 0U;
        Icu_MulChanTsActived[tmrModule][i] = FALSE;
#endif /* STD_ON == ICU_TIMESTAMP_API */
    }
    /* #50 restore the etimer varibles in multi capture mode */
    Icu_MulTimerEnable[tmrModule] = FALSE;
    Icu_MulPreIoVlue[tmrModule] = 0U;
    Icu_MulChangeIoChan[tmrModule] = 0U;
    Icu_MulHaveGotValFlag[tmrModule] = FALSE;
#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
    Icu_MulHalfBufferFlag[tmrModule] = FALSE;
#endif /* ICU_MULTI_CAPTURE_DMA_MODE */
}
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
#endif /* STD_ON == ICU_DEINIT_API */

#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
/** *****************************************************************************************************
 * \brief Check whether the timer need to be turned off
 *
 * \verbatim
 * Syntax             : static boolean Icu_MultiCptOffTimerCheck(
 *                                  Icu_HwModule tmrModule, uint8 mulChanNum)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module uint
 *                      mulChanNum - multi capture channel number
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Whether the timer need to be turned off
 *
 * Description        : Check whether the timer need to be turned off
 * \endverbatim
 * Traceability       : SWSR_ICU_206
 *******************************************************************************************************/
static boolean Icu_MultiCptOffTimerCheck(Icu_HwModule tmrModule, uint8 mulChanNum)
{
    boolean offTimer = TRUE;
    uint8 i;
    for (i = 0U; i < mulChanNum; i++)
    {
        if (TRUE == Icu_MulChanEnable[tmrModule][i])
        {
            offTimer = FALSE;
            break;
        } /* else not needed */
    }
    return offTimer;
}

/** *****************************************************************************************************
 * \brief Icu handles edge change situation in different measurement type for
 *        multi capture mode
 *
 * \verbatim
 * Syntax             : static void Icu_MultiCptTsHandler(
 *                                  Icu_HwModule tmrModule, uint8 logicChannel,
 *                                  uint8 subChannel,
 *                                  Icu_TimestampBufferType bufferType,
 *                                  uint32 tsValue)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module uint
 *                      logicChannel - logic channel index
 *                      subChannel - sub channel of multi capture timer
 *                      bufferType - buffer type in timestamp mode of multi
 *                                   capture
 *                      tsValue - channel c captured time stamp value
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Icu handles edge change situation in different
 *                      measurement type for multi capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_082 SWSR_ICU_083 SWSR_ICU_084 SWSR_ICU_085
 *                      SWSR_ICU_086 SWSR_ICU_087 SWSR_ICU_089 SWSR_ICU_090
 *                      SWSR_ICU_190 SWSR_ICU_206
 *******************************************************************************************************/
static void Icu_MultiCptTsHandler(Icu_HwModule tmrModule, uint8 logicChannel, uint8 subChannel, Icu_TimestampBufferType bufferType, uint32 tsValue)
{
    /* init local varibles */
    uint32 currSize;
    uint32 curCircleSize;
    uint8 ioIdx;
    boolean chanRuning = FALSE;
    if (ICU_LINEAR_BUFFER == bufferType)
    {
        /* #10 linear buffer mode timestamp handler */
        if (Icu_MulTsCurrentSize[tmrModule][subChannel] >=
            Icu_MulTsBufferSize[tmrModule][subChannel])
        {
            Icu_MulChanEnable[tmrModule][subChannel] = FALSE;
            Icu_MulChanTsActived[tmrModule][subChannel] = (boolean)FALSE;
            for (ioIdx = 0U; ioIdx < MULTI_CPT_MAX_IO_NUM; ioIdx++)
            {
                if (TRUE == Icu_MulChanEnable[tmrModule][ioIdx])
                {
                    chanRuning = TRUE;
                } /* else not needed */
            }
            if (FALSE == chanRuning)
            {
                Icu_ChanRunningStatus[logicChannel] = FALSE;
            } /* else not needed */
        }
        else
        {
            currSize = Icu_MulTsCurrentSize[tmrModule][subChannel];
            Icu_MulTsChanBufferPtr[tmrModule][subChannel][currSize] = tsValue;
            Icu_MulTsCurrentSize[tmrModule][subChannel]++;
        }
    }
    else
    {
        /* #20 circular buffer mode timestamp handler */
        if (Icu_MulTsBufferSize[tmrModule][subChannel] > 0U)
        {
            curCircleSize = Icu_MulTsCurrentSize[tmrModule][subChannel] %
                            Icu_MulTsBufferSize[tmrModule][subChannel];
            Icu_MulTsChanBufferPtr[tmrModule][subChannel][curCircleSize] = tsValue;
            Icu_MulTsCurrentSize[tmrModule][subChannel]++;
            if (Icu_MulTsCurrentSize[tmrModule][subChannel] ==
                Icu_MulTsMaxSize[tmrModule][subChannel])
            {
                Icu_MulTsCurrentSize[tmrModule][subChannel] = 0U;
            } /* else not needed */
        } /* else not needed */
    }
    /* #30 notification function handler */
    if (Icu_MulTsNotifyInterval[tmrModule][subChannel] > 0U)
    {
        if ((TRUE == Icu_MulNtfyEnable[tmrModule][subChannel]) &&
            (0UL == (Icu_MulTsCurrentSize[tmrModule][subChannel] %
                    Icu_MulTsNotifyInterval[tmrModule][subChannel])))
        {
            (*(Icu_ConfigPtr->chanConfigPtr))[logicChannel].multiCptChanCfgPtr
                [subChannel].Icu_MultiCptTimestamp.notifyTsMulFuncPtr();
        } /* else not needed */
    } /* else not needed */
}


/** *****************************************************************************************************
 * \brief Icu handles edge change situation in different measurement type for
 *        multi capture mode
 *
 * \verbatim
 * Syntax             : static void Icu_MultiCptEdgeChangeHandler(
 *                                  Icu_HwModule tmrModule, uint8 logicChannel,
 *                                  uint8 subChannel, uint32 tsValue)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module uint
 *                      logicChannel - logic channel index
 *                      subChannel - sub channel of multi capture timer
 *                      tsValue - channel c captured time stamp value
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Icu handles edge change situation in different
 *                      measurement type for multi capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_206
 *******************************************************************************************************/
static void Icu_MultiCptEdgeChangeHandler(Icu_HwModule tmrModule, uint8 logicChannel, uint8 subChannel, uint32 tsValue)
{
    /* init local varibles */
    Icu_MeasurementModeType measureType;
    Icu_ActivationType edgeSelect;
    Icu_SignalMeasurementPropertyType signalType;
    Icu_MultiCptEdgeChangeType edgeChange;
    uint32 timeSpend;
    boolean sigCalcOver;
    /* #10 get the edge-change information */
    if (0U == ((Icu_MulPreIoVlue[tmrModule] >> subChannel) & 0x1u))
    {
        Icu_MulEdgeChange[tmrModule][subChannel] = ICU_MULTI_CPT_RISING_EDGE;
    }
    else
    {
        Icu_MulEdgeChange[tmrModule][subChannel] = ICU_MULTI_CPT_FALLING_EDGE;
    }
    /* #20 check the sub channel enable status */
    if (TRUE == Icu_MulChanEnable[tmrModule][subChannel])
    {
        measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                        [logicChannel].multiCptChanCfgPtr[subChannel].icuMeasurementModeMul;
        edgeSelect = Icu_MulEdgeSelect[tmrModule][subChannel];
        /* #30 check the measurement mode */
        if (ICU_MODE_EDGE_COUNTER == measureType)
        {
            /* #40 edge counter handler */
            if ((ICU_BOTH_EDGES == edgeSelect) ||
                ((uint8)Icu_MulEdgeChange[tmrModule][subChannel] == (uint8)edgeSelect))
            {
                Icu_MulChanEdgeCnt[tmrModule][subChannel]++;
            } /* else not needed */
        }
        else if (ICU_MODE_SIGNAL_MEASUREMENT == measureType)
        {
            /* #50 get the signal measurement mode */
            signalType = (*(Icu_ConfigPtr->chanConfigPtr))[logicChannel].multiCptChanCfgPtr
                            [subChannel].Icu_MultiCptSigMeasure.sigMeasureMulProperty;
            edgeChange = Icu_MulEdgeChange[tmrModule][subChannel];
            /* get time spend information */
            if (tsValue < Icu_MulPreCptTime[tmrModule][subChannel])
            {
                timeSpend = (0xFFFFFFFFUL - Icu_MulPreCptTime[tmrModule][subChannel]) + tsValue;
            }
            else
            {
                timeSpend = tsValue - Icu_MulPreCptTime[tmrModule][subChannel];
            }
            /* signal measurement data calculation */
            sigCalcOver = Icu_Ip_MultiCptSigMeasurementIrq(tmrModule,
                                                    subChannel, signalType, edgeChange, timeSpend);
            /* check if signal time calculate over */
            if (TRUE == sigCalcOver)
            {
                /* update input status */
                Icu_MulChanInputSta[tmrModule][subChannel] = ICU_ACTIVE;
            } /* else not needed */
        }
        else if (ICU_MODE_TIMESTAMP == measureType)
        {
            /* #60 check the edge change information */
            if ((ICU_BOTH_EDGES == edgeSelect) ||
                ((uint8)Icu_MulEdgeChange[tmrModule][subChannel] == (uint8)edgeSelect))
            {
                Icu_TimestampBufferType bufferType =
                    (*(Icu_ConfigPtr->chanConfigPtr))[logicChannel].multiCptChanCfgPtr
                        [subChannel].Icu_MultiCptTimestamp.tsBufferMulProperty;
                Icu_MultiCptTsHandler(tmrModule, logicChannel, subChannel, bufferType, tsValue);
            } /* else not needed */
        }
        else
        {
            /* do nothing to avoid warning */
        }
    }
}

/** *****************************************************************************************************
 * \brief Captured timestamp value handler in interrupt mode
 *
 * \verbatim
 * Syntax             : static void Icu_MultiCptValueHandler(
 *                                                      Icu_HwModule tmrModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module uint
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Captured timestamp value handler in interrupt mode
 * \endverbatim
 * Traceability       : SWSR_ICU_206
 *******************************************************************************************************/
static void Icu_MultiCptValueHandler(Icu_HwModule tmrModule)
{
    Icu_HwChannel chanbIndex = ICU_HW_CPT_B;
    Icu_HwChannel chancIndex = ICU_HW_CPT_C;
    uint32 chnbFifoVal;
    uint32 chncFifoVal;
    uint8 mulChanNum;
    uint8 logicChan;
    uint8 fifoIdx;
    uint8 fifoEntry;
    uint8 ioIdx;
    uint32 ioEdgeIdx;
    boolean ioEdgeChange;
    /* #20 get fifo number value */
    fifoEntry = Icu_Ip_GetFifoEntry(tmrModule, chancIndex);
    for(fifoIdx = 0U; fifoIdx < fifoEntry; fifoIdx++)
    {
        chnbFifoVal = Icu_Ip_GetFifoVal(tmrModule, chanbIndex);
        chncFifoVal = Icu_Ip_GetFifoVal(tmrModule, chancIndex);
        /* get logic chan */
        logicChan = Icu_PhyToLogMap[tmrModule][chanbIndex];
        /* get multi cpt num */
        mulChanNum = Icu_PhyToLogMap[tmrModule][chancIndex];

        if (FALSE == Icu_MulHaveGotValFlag[tmrModule])
        {
            /* #30 first value captured no need to handle */
            Icu_MulHaveGotValFlag[tmrModule] = TRUE;
            /* store the first captured value */
            Icu_MulPreIoVlue[tmrModule] = chnbFifoVal;
            for (ioIdx = 0U; ioIdx < mulChanNum; ioIdx++)
            {
                Icu_MulPreCptTime[tmrModule][ioIdx] = chncFifoVal;
            }
        }
        else
        {
            /* #40 get edge change channel information */
            Icu_MulChangeIoChan[tmrModule] = chnbFifoVal ^ Icu_MulPreIoVlue[tmrModule];
            for (ioIdx = 0U; ioIdx < mulChanNum; ioIdx++)
            {
                ioEdgeIdx = (Icu_MulChangeIoChan[tmrModule] & ((uint32)0x01U << (uint32)ioIdx));
                ioEdgeChange = (ioEdgeIdx != 0U) ? TRUE : FALSE;
                if (TRUE == ioEdgeChange)
                {
                    /* sub channel edge change handler */
                    Icu_MultiCptEdgeChangeHandler(tmrModule, logicChan, ioIdx, chncFifoVal);
                    Icu_MulPreCptTime[tmrModule][ioIdx] = chncFifoVal;
                } /* else not needed */
            }
            Icu_MulPreIoVlue[tmrModule] = chnbFifoVal;
        }
    }
}

/** *****************************************************************************************************
 * \brief Interrupt handler function in the case of multi capture mode
 *
 * \verbatim
 * Syntax             : static void Icu_MultiIrqCommon(
 *                                                  Icu_HwModule tmrModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module uint
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt handler function in the case of multi capture
 *                      mode
 * \endverbatim
 * Traceability       : SWSR_ICU_206
 *******************************************************************************************************/
static void Icu_MultiIrqCommon(Icu_HwModule tmrModule)
{
    Icu_HwChannel chanbIndex = ICU_HW_CPT_B;
    Icu_HwChannel chancIndex = ICU_HW_CPT_C;
    uint32 irqStatus = Icu_Ip_GetInterrupt(tmrModule);
    boolean fifoErrChnb;
    boolean fifoErrChnc;

    /* #10 multi capture mode enable c channel (timestamp information) only */
    if ((irqStatus & ((uint32)0x01U << (uint32)chancIndex)) != 0U)
    {
        /* clear int */
        (void)Icu_Ip_ClearInterrupt(tmrModule, chancIndex);
        /* check chan b if fifo has error generate */
        fifoErrChnb = Icu_Ip_CheckFifoSta(tmrModule, chanbIndex);
        /* check chan c if fifo has error generate */
        fifoErrChnc = Icu_Ip_CheckFifoSta(tmrModule, chancIndex);
        IcuHookBegin_Icu_MultiCptFifoErr();
        if ((FALSE == fifoErrChnb) && (FALSE == fifoErrChnc))
        {
            /* #20 captured value handler */
            Icu_MultiCptValueHandler(tmrModule);
        } /* else not needed */
        IcuHookEnd_Icu_MultiCptFifoErr();
    } /* else not needed */

}
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */

/********************************************************************************************************
 *                                      External Function                                               *
 *******************************************************************************************************/

/** *****************************************************************************************************
 * \brief This function initializes the driver.
 *
 * \verbatim
 * Syntax             : void Icu_Init(const Icu_ConfigType* ConfigPtr);
 *
 * Service ID[hex]    : 0x00
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : configPtr - Pointer to configuration set
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function initializes the driver.
 *
 * \endverbatim
 * Traceability       : SWSR_ICU_031 SWSR_ICU_032 SWSR_ICU_033 SWSR_ICU_034
 *                      SWSR_ICU_035 SWSR_ICU_039 SWSR_ICU_040 SWSR_ICU_041
 *                      SWSR_ICU_042 SWSR_ICU_043
 *******************************************************************************************************/
void Icu_Init(const Icu_ConfigType* ConfigPtr)
{
    /* init local varibles */
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType callResult;
    Icu_ChannelType channel;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 i;
    uint8 multiCptNum;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check the driver initial status */
    if (ICU_STATUS_INITED == Icu_DriverState)
    {
        errId = ICU_E_ALREADY_INITIALIZED;
    }
    /* #20 check the pointer */
    else if (NULL_PTR == ConfigPtr)
    {
        errId = ICU_E_PARAM_POINTER;
    }
    else
    {
        Icu_ConfigPtr = ConfigPtr;
        for (channel = 0U; channel < NUM_OF_CHANNEL; channel++)
        {
            /* get the channel hardware information */
            tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[channel].icuHwChanCfgPtr->timerModule;
            hwChannel = (*(Icu_ConfigPtr->chanConfigPtr))[channel].icuHwChanCfgPtr->timerChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
            multiCptNum = (*(Icu_ConfigPtr->chanConfigPtr))
                                    [channel].icuHwChanCfgPtr->multiCptChanNum;
            /* #30 check the channel enable multi capture or not  */
            if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[channel].multiCaptureEnable)
            {
                /* multi etimer chn b store logic chan number for multi interrupt mode */
                Icu_PhyToLogMap[tmrModule][1] = (uint8)channel;
                /* multi etimer chn c store multicpt number for multi interrupt mode */
                Icu_PhyToLogMap[tmrModule][2] = multiCptNum;
                callResult = Icu_Ip_MultiCptChannelInit(&((*(Icu_ConfigPtr->chanConfigPtr))[channel]));
                /* set multi capture channel default value */
                for (i = 0U; i < MULTI_CPT_MAX_IO_NUM; i++)
                {
#if (STD_ON == ICU_GET_INPUTSTATE_API)
                    /* set multi cpt io init tatus */
                    Icu_MulChanInputSta[tmrModule][i] = ICU_IDLE;
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */
                    /* disable all multi cpt io chan */
                    Icu_MulChanEnable[tmrModule][i] = FALSE;
                }
            }
            else
            {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
                /* store the logic channel information */
                Icu_PhyToLogMap[tmrModule][hwChannel] = (uint8)channel;
                callResult = Icu_Ip_ChannelInit(&((*(Icu_ConfigPtr->chanConfigPtr))[channel]));
#if (STD_ON == ICU_GET_INPUTSTATE_API)
                Icu_ChanInputSta[channel] = ICU_IDLE;
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
            }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            Icu_ChanRunningStatus[channel] = FALSE;
            if (E_OK != callResult)
            {
                errId = ICU_E_PARAM_CHANNEL_CONFIG;
                break;
            } /* else not needed */
        }
    }
    /* #40 check the error status */
    if (ICU_E_PARAM_INVALID_VALUE != errId)
    {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                              (uint8)ICU_INIT_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                              (uint8)ICU_INIT_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
    }
    else
    {
        /* #50 icu driver initilized complete */
        Icu_DriverState = ICU_STATUS_INITED;
    }
}


#if (STD_ON == ICU_DEINIT_API)
/** *****************************************************************************************************
 * \brief This function de-initializes the ICU module
 *
 * \verbatim
 * Syntax             : void Icu_DeInit(void)
 *
 * Service ID[hex]    : 0x01
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
 * Return value       : None
 *
 * Description        : this function de-initializes the ICU module
 * \endverbatim
 * Traceability       : SWSR_ICU_044 SWSR_ICU_045 SWSR_ICU_046 SWSR_ICU_047
 *                      SWSR_ICU_048 SWSR_ICU_049 SWSR_ICU_050 SWSR_ICU_051
 *                      SWSR_ICU_052 SWSR_ICU_053
 *******************************************************************************************************/
void Icu_DeInit(void)
{
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType callResult;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
    Icu_ChannelType channel;
    /* #10 check driver deinit status */
    if (E_OK == Icu_ValidateDeInit())
    {
        for (channel = 0U; channel < NUM_OF_CHANNEL; channel++)
        {
            /* get the channel hardware information */
            tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[channel].icuHwChanCfgPtr->timerModule;
            hwChannel = (*(Icu_ConfigPtr->chanConfigPtr))[channel].icuHwChanCfgPtr->timerChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
            /* #20 check the channel enable multi capture or not  */
            if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[channel].multiCaptureEnable)
            {
                /* multi etimer chn b store logic chan number for multi interrupt mode */
                Icu_PhyToLogMap[tmrModule][ICU_HW_CPT_B] = 0U;
                /* multi etimer chn c store multicpt number for multi interrupt mode */
                Icu_PhyToLogMap[tmrModule][ICU_HW_CPT_C] = 0U;
                callResult = Icu_Ip_MultiCptChannelDeInit(&((*(Icu_ConfigPtr->chanConfigPtr))[channel]));
                /* restore varibles in multi capture mode */
                Icu_MultiCptRestoreAllVaribles(tmrModule);
            }
            else
            {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
                callResult = Icu_Ip_ChannelDeInit(&((*(Icu_ConfigPtr->chanConfigPtr))[channel]));
                /* restore the mapping relationship */
                Icu_PhyToLogMap[tmrModule][hwChannel] = 0U;
                /* restore varibles in single capture mode */
                Icu_SingleRestoreVaribles(channel);

#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
            }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            if (callResult != E_OK)
            {
                errId = ICU_E_PARAM_CHANNEL_CONFIG;
                break;
            } /* else not needed */
        }
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                (uint8)ICU_DEINIT_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                (uint8)ICU_DEINIT_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        }
        else
        {
            /* #30 restore the driver status */
            Icu_ConfigPtr = NULL_PTR;
            Icu_DriverState = ICU_STATUS_UNINIT;
        }
    } /* else not needed */

}
#endif /* STD_ON == ICU_DEINIT_API */

/** *****************************************************************************************************
 * \brief Service for setting Activation Condition
 *
 * \verbatim
 * Syntax             : void Icu_SetActivationCondition(Icu_ChannelType Channel,
 *                                               Icu_ActivationType Activation);
 *
 * Service ID[hex]    : 0x05
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *                      Activation - type of activation (if supported by
 *                                   hardware)
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function sets the activation-edge for the given
 *                      channel.
 * \endverbatim
 * Traceability       : SWSR_ICU_054 SWSR_ICU_055 SWSR_ICU_056 SWSR_ICU_057
 *                      SWSR_ICU_058 SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_SetActivationCondition(Icu_ChannelType Channel, Icu_ActivationType Activation)
{
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType callResult;
    uint8 logChanIdx;
    Icu_MeasurementModeType measureType;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 ioIdx;
    Icu_HwModule tmrModule;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    if (Activation > ICU_BOTH_EDGES)
    {
        errId = ICU_E_PARAM_ACTIVATION;
    }
    else if (E_OK == Icu_ValidateCommon(Channel, ICU_SET_ACTIVATION_CONDITION_ID))
    {
        /* get channel hardware information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
            if (measureType != ICU_MODE_SIGNAL_MEASUREMENT)
            {
                Icu_MulEdgeSelect[tmrModule][ioIdx] = Activation;
            }
            else
            {
                errId = ICU_E_PARAM_ACTIVATION;
            }
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
            if (ICU_MODE_SIGNAL_MEASUREMENT != measureType)
            {
                callResult = Icu_Ip_SetActivationCondition(
                            (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr, Activation);
                if(E_OK != callResult)
                {
                    errId = ICU_E_PARAM_CHANNEL_CONFIG;
                }
                else
                {
#if (STD_ON == ICU_GET_INPUTSTATE_API)
                    Icu_ChanInputSta[logChanIdx] = ICU_IDLE;
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */
                }
            }
            else
            {
                errId = ICU_E_PARAM_ACTIVATION;
            }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    }
    else
    {
        /* do nothing to avoid warning */
    }
    if (ICU_E_PARAM_INVALID_VALUE != errId)
    {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                              (uint8)ICU_SET_ACTIVATION_CONDITION_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                              (uint8)ICU_SET_ACTIVATION_CONDITION_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
    } /* else not needed */
}

/** *****************************************************************************************************
 * \brief Service for disabling notification
 *
 * \verbatim
 * Syntax             : void Icu_DisableNotification(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x06
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function disables the notification of a channel.
 * \endverbatim
 * Traceability       : SWSR_ICU_059 SWSR_ICU_060 SWSR_ICU_061 SWSR_ICU_062
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_DisableNotification(Icu_ChannelType Channel)
{
    /* init local varibles */
    uint8 logChanIdx;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 ioIdx;
    Icu_HwModule tmrModule;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_DISABLE_NOTIFICATION_ID))
    {
        /* get channel hardware information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            /* disable notification function */
            Icu_MulNtfyEnable[tmrModule][ioIdx] = FALSE;
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            /* disable notification function */
            Icu_ChanNtfyEnable[logChanIdx] = (boolean)FALSE;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    } /* else not needed */
}

/** *****************************************************************************************************
 * \brief Service for enabling notification.
 *
 * \verbatim
 * Syntax             : void Icu_EnableNotification(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x07
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function enables the notification of a channel.
 * \endverbatim
 * Traceability       : SWSR_ICU_063 SWSR_ICU_064 SWSR_ICU_065 SWSR_ICU_066
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_EnableNotification(Icu_ChannelType Channel)
{
    /* init local varibles */
    uint8 logChanIdx;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 ioIdx;
    Icu_HwModule tmrModule;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_ENABLE_NOTIFICATION_ID))
    {
        /* get channel hardware information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            /* enable channel notification */
            Icu_MulNtfyEnable[tmrModule][ioIdx] = TRUE;
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            /* enable channel notification */
            Icu_ChanNtfyEnable[logChanIdx] = (boolean)TRUE;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    } /* else not needed */
}

#if (STD_ON == ICU_GET_INPUTSTATE_API)
/** *****************************************************************************************************
 * \brief Service for getting the ICU input status.
 *
 * \verbatim
 * Syntax             : Icu_InputStateType Icu_GetInputState(
 *                                                      Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x08
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function returns the status of the ICU input.
 * \endverbatim
 * Traceability       : SWSR_ICU_067 SWSR_ICU_068 SWSR_ICU_069 SWSR_ICU_070
 *                      SWSR_ICU_071 SWSR_ICU_072 SWSR_ICU_073 SWSR_ICU_074
 *                      SWSR_ICU_075 SWSR_ICU_076 SWSR_ICU_077
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
Icu_InputStateType Icu_GetInputState(Icu_ChannelType Channel)
{
    /* init local varibles */
    Icu_InputStateType retVal = ICU_IDLE;
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    uint8 logChanIdx;
    Icu_MeasurementModeType measureType;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 ioIdx;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_GET_INPUT_STATE_ID))
    {
        /* get channel hardware information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        hwChannel = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
            /* check the measurement mode */
            if (ICU_MODE_SIGNAL_MEASUREMENT == measureType)
            {
                SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00();
                /* get the input status */
                retVal = Icu_MulChanInputSta[tmrModule][ioIdx];
                Icu_MulChanInputSta[tmrModule][ioIdx] = ICU_IDLE;
                SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00();
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
            /* check the measurement mode */
            if ((ICU_MODE_SIGNAL_MEASUREMENT == measureType) ||
                (ICU_MODE_SIGNAL_EDGE_DETECT == measureType))
            {
                SchM_Enter_Icu_ICU_EXCLUSIVE_AREA_00();
                /* get the input status */
                if (ICU_MODE_SIGNAL_MEASUREMENT == measureType)
                {
                    retVal = Icu_Ip_GetInputState(tmrModule, hwChannel);
                }
                else
                {
                    retVal = Icu_ChanInputSta[logChanIdx];
                }
                Icu_ChanInputSta[logChanIdx] = ICU_IDLE;
                SchM_Exit_Icu_ICU_EXCLUSIVE_AREA_00();
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
        /* #30 check error status */
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_GET_INPUT_STATE_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                        (uint8)ICU_GET_INPUT_STATE_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    } /* else not needed */
    return retVal;
}
#endif /* STD_ON == ICU_GET_INPUTSTATE_API */

#if (STD_ON == ICU_TIMESTAMP_API)
/** *****************************************************************************************************
 * \brief Service for starts the captuing of timer values on the edges.
 *
 * \verbatim
 * Syntax             : void Icu_StartTimestamp(Icu_ChannelType Channel,
 *                                  Icu_ValueType* BufferPtr, uint16 BufferSize,
 *                                  uint16 NotifyInterval)
 *
 * Service ID[hex]    : 0x09
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *                      BufferSize - size of the external buffer (number of
 *                                   entries)
 *                      NotifyInterval - notification interval (number of
 *                                       events)
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : BufferPtr - pointer to the buffer-array where the
 *                                  timestamp values shall be placed
 *
 * Return value       : None
 *
 * Description        : This function starts the capturing of timer values on
 *                      the edges.
 * \endverbatim
 * Traceability       : SWSR_ICU_078 SWSR_ICU_079 SWSR_ICU_080 SWSR_ICU_081
 *                      SWSR_ICU_082 SWSR_ICU_083 SWSR_ICU_084 SWSR_ICU_085
 *                      SWSR_ICU_086 SWSR_ICU_087 SWSR_ICU_088 SWSR_ICU_089
 *                      SWSR_ICU_090 SWSR_ICU_091 SWSR_ICU_092 SWSR_ICU_093
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_StartTimestamp(Icu_ChannelType Channel, Icu_ValueType* BufferPtr, uint16 BufferSize, uint16 NotifyInterval)
{
    /* init local varibles */
    uint8 logChanIdx;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
    Icu_MeasurementModeType measureType;
    boolean dmaSupport;
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType callResult = E_OK;
    Std_ReturnType comVali = Icu_ValidateCommon(Channel, ICU_START_TIME_STAMP_ID);
    Std_ReturnType timeVali = Icu_ValidateParamStamp(BufferPtr, BufferSize, NotifyInterval);
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 ioIdx;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common parameter validity */
    if ((E_OK == comVali) && (E_OK == timeVali))
    {
        /* get channel configuration information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        hwChannel = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
            /* check the measurement mode */
            if (ICU_MODE_TIMESTAMP == measureType)
            {
                /* set initial timestamp varibles */
                Icu_MulTsCurrentSize[tmrModule][ioIdx] = 0U;
                Icu_MulChanEnable[tmrModule][ioIdx] = TRUE;
                Icu_MulTsBufferSize[tmrModule][ioIdx] = BufferSize;
                Icu_MulTsChanBufferPtr[tmrModule][ioIdx] = BufferPtr;
                Icu_MulChanTsActived[tmrModule][ioIdx] = (boolean)TRUE;
                Icu_MulTsNotifyInterval[tmrModule][ioIdx] = NotifyInterval;
                Icu_MulTsMaxSize[tmrModule][ioIdx] = ((uint32)NotifyInterval * (uint32)BufferSize);
                /* check the timer enable status in multi capture mode */
                if (FALSE == Icu_MulTimerEnable[tmrModule])
                {
                    /* turn on the capture */
                    Icu_MulTimerEnable[tmrModule] = TRUE;
                    Icu_ChanRunningStatus[logChanIdx] = (boolean)TRUE;
#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
                    callResult = Icu_Ip_MultiCptTurnOnCapture(tmrModule, FALSE);
#else /* ICU_MULTI_CAPTURE_DMA_MODE */
                    callResult = Icu_Ip_MultiCptTurnOnCapture(tmrModule, TRUE);
#endif /* ICU_MULTI_CAPTURE_DMA_MODE */
                } /* else not needed */
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
            /* check the measurement mode */
            if (ICU_MODE_TIMESTAMP == measureType)
            {
                /* set initial timestamp varibles */
                Icu_TsCurrentSize[logChanIdx] = 0U;
                Icu_TsMaxSize[logChanIdx] = ((uint32)NotifyInterval * (uint32)BufferSize);
                Icu_TsNotifyInterval[logChanIdx] = NotifyInterval;
                Icu_TsBufferSize[logChanIdx] = BufferSize;
                Icu_ChanBufferPtr[logChanIdx] = BufferPtr;
                Icu_ChanTsActived[logChanIdx] = (boolean)TRUE;
                Icu_ChanRunningStatus[logChanIdx] = (boolean)TRUE;
#if (STD_ON == ICU_DMA_SUPPORT)
                dmaSupport = TRUE;
                if (FALSE == Icu_ChanDmaIsRuning[logChanIdx])
                {
                    /* setup dma channel configuration */
                    Icu_HalfBufferFlag[logChanIdx] = FALSE;
                    Icu_ChanDmaIsRuning[logChanIdx] =
                        Icu_Ip_SetupDma(&(*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx]);
                } /* else not needed */
#else /* STD_ON == ICU_DMA_SUPPORT */
                dmaSupport = FALSE;
#endif /* STD_ON == ICU_DMA_SUPPORT */
                /* turn on the capture */
                callResult = Icu_Ip_TurnOnCapture(tmrModule, hwChannel, dmaSupport);
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
        /* #30 check error status */
        if (E_OK != callResult)
        {
            errId = ICU_E_PARAM_CHANNEL_CONFIG;
        }
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_START_TIME_STAMP_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                        (uint8)ICU_START_TIME_STAMP_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    } /* else not needed */
}

/** *****************************************************************************************************
 * \brief Service for stopping the timestamp measurement.
 *
 * \verbatim
 * Syntax             : void Icu_StopTimestamp(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x0A
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function stops the timestamp measurement of the
 *                      given channel
 * \endverbatim
 * Traceability       : SWSR_ICU_094 SWSR_ICU_095 SWSR_ICU_096 SWSR_ICU_097
 *                      SWSR_ICU_098 SWSR_ICU_099 SWSR_ICU_100
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_StopTimestamp(Icu_ChannelType Channel)
{
    /* init local varibles */
    uint8 logChanIdx;
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType callResult = E_OK;
    uint8 runTimeErr = ICU_E_PARAM_INVALID_VALUE;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
    Icu_MeasurementModeType measureType;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 ioIdx;
    uint8 mulChanNum;
    boolean turnOffTimer;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_STOP_TIME_STAMP_ID))
    {
        /* get channel configuration information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        hwChannel = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        mulChanNum = (*(Icu_ConfigPtr->chanConfigPtr))
                                            [logChanIdx].icuHwChanCfgPtr->multiCptChanNum;
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
            /* check the measurement mode  */
            if (ICU_MODE_TIMESTAMP != measureType)
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
            else if (FALSE == Icu_MulChanTsActived[tmrModule][ioIdx])

            {
                runTimeErr = ICU_E_NOT_STARTED;

            }
            else
            {
                /* #30 check the conditions for turning off the capture */
                turnOffTimer = Icu_MultiCptRestoreTsVaribles(tmrModule, ioIdx, mulChanNum);
                if (TRUE == turnOffTimer)
                {
                    /* turn off the capture channel */
#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
                    callResult = Icu_Ip_MultiCptTurnOffCapture(tmrModule, FALSE);
#else /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */
                    callResult = Icu_Ip_MultiCptTurnOffCapture(tmrModule, TRUE);
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */
                    Icu_MulTimerEnable[tmrModule] = FALSE;
                    Icu_ChanRunningStatus[logChanIdx] = (boolean)FALSE;
                } /* else not needed */
            }
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
            /* check the measurement mode  */
            if (ICU_MODE_TIMESTAMP != measureType)
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
            else if (FALSE == Icu_ChanTsActived[logChanIdx])
            {
                runTimeErr = ICU_E_NOT_STARTED;
            }
            else
            {
                /* #40 restore timestamp varibles */
#if (STD_ON == ICU_DMA_SUPPORT)
                callResult = Icu_Ip_FreeDma(logChanIdx);
                Icu_ChanDmaIsRuning[logChanIdx] = FALSE;
                Icu_HalfBufferFlag[logChanIdx] = FALSE;
                callResult |= Icu_Ip_TurnOffCapture(tmrModule, hwChannel, TRUE);
#else
                callResult |= Icu_Ip_TurnOffCapture(tmrModule, hwChannel, FALSE);
#endif /* STD_ON == ICU_DMA_SUPPORT */

                Icu_ChanBufferPtr[logChanIdx] = NULL_PTR;
                Icu_TsBufferSize[logChanIdx] = 0U;
                Icu_TsCurrentSize[logChanIdx] = 0U;
                Icu_TsNotifyInterval[logChanIdx] = 0U;
                Icu_ChanTsActived[logChanIdx] = (boolean)FALSE;
                Icu_ChanRunningStatus[logChanIdx] = FALSE;
            }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
        /* #50 check error status */
        if (E_OK != callResult)
        {
            errId = ICU_E_PARAM_CHANNEL_CONFIG;
        }
        if (ICU_E_PARAM_INVALID_VALUE != runTimeErr)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportRuntimeError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                                 (uint8)ICU_STOP_TIME_STAMP_ID, (uint8)runTimeErr);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                                 (uint8)ICU_STOP_TIME_STAMP_ID, (uint8)runTimeErr);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_STOP_TIME_STAMP_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_STOP_TIME_STAMP_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    }
}

/** *****************************************************************************************************
 * \brief Service for reading the timestamp index of a givem channel.
 *
 * \verbatim
 * Syntax             : Icu_IndexType Icu_GetTimestampIndex(
 *                                                      Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x0B
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : Get buffer index in timestamp mode
 *
 * Description        : This function reads the timestamp index of the given channel
 * \endverbatim
 * Traceability       : SWSR_ICU_101 SWSR_ICU_102 SWSR_ICU_103 SWSR_ICU_104
 *                      SWSR_ICU_105 SWSR_ICU_106 SWSR_ICU_107 SWSR_ICU_108
 *                      SWSR_ICU_109
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
Icu_IndexType Icu_GetTimestampIndex(Icu_ChannelType Channel)
{
    /* init local varibles */
    Icu_IndexType tsBufferIdx = 0U;
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    uint8 logChanIdx;
    Icu_MeasurementModeType measureType;
    Icu_TimestampBufferType bufferType;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 ioIdx;
    Icu_HwModule tmrModule;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_GET_TIME_STAMPINDEX_ID))
    {
        /* get channel configuration information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))
                                                    [logChanIdx].icuHwChanCfgPtr->timerModule;
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
            /* check the measurement mode */
            if (ICU_MODE_TIMESTAMP != measureType)
            {
                errId = ICU_E_PARAM_CHANNEL;
                tsBufferIdx = 0U;
            }
            else if ((NULL_PTR == Icu_MulTsChanBufferPtr[tmrModule][ioIdx]) ||
                    (0UL == Icu_MulTsBufferSize[tmrModule][ioIdx]))
            {
                errId = ICU_E_PARAM_BUFFER_SIZE;
                tsBufferIdx = 0U;
            }
            else
            {
                bufferType = (*(Icu_ConfigPtr->chanConfigPtr))
                    [logChanIdx].multiCptChanCfgPtr[ioIdx].Icu_MultiCptTimestamp.tsBufferMulProperty;
                /* check the buffer mode */
                if (ICU_LINEAR_BUFFER == bufferType)
                {
                    tsBufferIdx = (Icu_IndexType)Icu_MulTsCurrentSize[tmrModule][ioIdx];
                }
                else
                {
                    /* ICU_CIRCULAR_BUFFER */
                    tsBufferIdx = (Icu_IndexType)((Icu_MulTsCurrentSize[tmrModule][ioIdx]) %
                                        Icu_MulTsBufferSize[tmrModule][ioIdx]);
                }
            }
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
            /* check the measurement mode */
            if (ICU_MODE_TIMESTAMP != measureType)
            {
                errId = ICU_E_PARAM_CHANNEL;
                tsBufferIdx = 0U;
            }
            else if ((NULL_PTR == Icu_ChanBufferPtr[logChanIdx]) ||
                    (0U == Icu_TsBufferSize[logChanIdx]))
            {
                errId = ICU_E_PARAM_BUFFER_SIZE;
                tsBufferIdx = 0U;
            }
            else
            {
                bufferType = (*(Icu_ConfigPtr->chanConfigPtr))
                    [logChanIdx].measureParamPtr->Icu_TimestampMeasurement.tsBufferProperty;
                /* check the buffer mode */
                if (ICU_LINEAR_BUFFER == bufferType)
                {
                    tsBufferIdx = (Icu_IndexType)Icu_TsCurrentSize[logChanIdx];
                }
                else
                {
                    /* ICU_CIRCULAR_BUFFER */
                    tsBufferIdx = (Icu_IndexType)((Icu_TsCurrentSize[logChanIdx]) %
                                        Icu_TsBufferSize[logChanIdx]);
                }
            }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
        /* #30 check error status */
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_GET_TIME_STAMPINDEX_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_GET_TIME_STAMPINDEX_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    }
    /* return the buffer index */
    return tsBufferIdx;
}
#endif /* STD_ON == ICU_TIMESTAMP_API */

#if (STD_ON == ICU_EDGE_COUNT_API)
/** *****************************************************************************************************
 * \brief Service for resets the value of the counted edges to zero.
 *
 * \verbatim
 * Syntax             : void Icu_ResetEdgeCount(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x0C
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function resets the value of the counted edges to zero
 * \endverbatim
 * Traceability       : SWSR_ICU_110 SWSR_ICU_111 SWSR_ICU_112 SWSR_ICU_113
 *                      SWSR_ICU_114 SWSR_ICU_115
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_ResetEdgeCount(Icu_ChannelType Channel)
{
    /* init local varibles */
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    uint8 logChanIdx;
    Icu_MeasurementModeType measureType;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 ioIdx;
    Icu_HwModule tmrModule;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_RESET_EDGE_COUNT_ID))
    {
        /* get channel configuration information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
            /* check the measurement mode */
            if (ICU_MODE_EDGE_COUNTER == measureType)
            {
                /* set edge counter to 0 */
                Icu_MulChanEdgeCnt[tmrModule][ioIdx] = 0UL;
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
            /* check the measurement mode */
            if (ICU_MODE_EDGE_COUNTER == measureType)
            {
                /* set edge counter to 0 */
                Icu_ChanEdgeCnt[logChanIdx] = 0U;
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif  /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
        /* #30 check error status */
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_RESET_EDGE_COUNT_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_RESET_EDGE_COUNT_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    }
}

/** *****************************************************************************************************
 * \brief Service enabling the counting of edges of a given channel.
 *
 * \verbatim
 * Syntax             : void Icu_EnableEdgeCount(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x0D
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function enables the counting of edges of the given
 *                      channel
 * \endverbatim
 * Traceability       : SWSR_ICU_116 SWSR_ICU_117 SWSR_ICU_118 SWSR_ICU_119
 *                      SWSR_ICU_120 SWSR_ICU_121 SWSR_ICU_122 SWSR_ICU_123
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_EnableEdgeCount(Icu_ChannelType Channel)
{
    /* init local varibles */
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType callResult = E_OK;
    uint8 logChanIdx;
    Icu_MeasurementModeType measureType;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 ioIdx;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_ENABLE_EDGE_COUNT_ID))
    {
        /* get channel configuration information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        hwChannel = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
            /* check the measurement mode */
            if (ICU_MODE_EDGE_COUNTER == measureType)
            {
                Icu_MulChanEnable[tmrModule][ioIdx] = TRUE;
                /* check the timer enable status in multi capture mode */
                if (FALSE == Icu_MulTimerEnable[tmrModule])
                {
                    Icu_MulTimerEnable[tmrModule] = TRUE;
                    Icu_ChanRunningStatus[logChanIdx] = (boolean)TRUE;
#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
                    callResult = Icu_Ip_MultiCptTurnOnCapture(tmrModule, FALSE);
#else /* ICU_MULTI_CAPTURE_DMA_MODE */
                    callResult = Icu_Ip_MultiCptTurnOnCapture(tmrModule, TRUE);
#endif /* ICU_MULTI_CAPTURE_DMA_MODE */
                } /* else not needed */
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
            /* check the measurement mode */
            if (ICU_MODE_EDGE_COUNTER == measureType)
            {
                Icu_ChanRunningStatus[logChanIdx] = (boolean)TRUE;
                /* turn on the capture channel */
                callResult = Icu_Ip_TurnOnCapture(tmrModule, hwChannel, FALSE);
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
        /* #30 check error status */
        if (E_OK != callResult)
        {
            errId = ICU_E_PARAM_CHANNEL_CONFIG;
        } /* else not needed */
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_ENABLE_EDGE_COUNT_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_ENABLE_EDGE_COUNT_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    }
}

/** *****************************************************************************************************
 * \brief Service for disabling the couting of edges of the given channel.
 *
 * \verbatim
 * Syntax             : void Icu_DisableEdgeCount(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x0E
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function disables the counting of edges of the
 *                      given channel
 * \endverbatim
 * Traceability       : SWSR_ICU_138 SWSR_ICU_139 SWSR_ICU_140 SWSR_ICU_141
 *                      SWSR_ICU_142 SWSR_ICU_143
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_DisableEdgeCount(Icu_ChannelType Channel)
{
    /* init local varibles */
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType callResult = E_OK;
    uint8 logChanIdx;
    Icu_MeasurementModeType measureType;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 ioIdx;
    uint8 mulChanNum;
    boolean turnOffEtimer;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_DISABLE_EDGE_COUNT_ID))
    {
        /* get channel configuration information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        hwChannel = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        mulChanNum = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->multiCptChanNum;
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
            /* check the measurement mode */
            if (ICU_MODE_EDGE_COUNTER == measureType)
            {
                Icu_MulChanEnable[tmrModule][ioIdx] = FALSE;
                /* check if all xtrg.Io disable */
                turnOffEtimer = Icu_MultiCptOffTimerCheck(tmrModule, mulChanNum);
                if (TRUE == turnOffEtimer)
                {
                    /* turn off etimer capture */
#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
                    callResult = Icu_Ip_MultiCptTurnOffCapture(tmrModule, FALSE);
#else/* ICU_MULTI_CAPTURE_DMA_MODE */
                    callResult = Icu_Ip_MultiCptTurnOffCapture(tmrModule, TRUE);
#endif /* ICU_MULTI_CAPTURE_DMA_MODE */
                    Icu_MulTimerEnable[tmrModule] = FALSE;
                    Icu_ChanRunningStatus[logChanIdx] = (boolean)FALSE;
                } /* else not needed */
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
            /* check the measurement mode */
            if (ICU_MODE_EDGE_COUNTER == measureType)
            {
                Icu_ChanRunningStatus[logChanIdx] = (boolean)FALSE;
                /* turn off the capture channel */
                callResult = Icu_Ip_TurnOffCapture(tmrModule, hwChannel, FALSE);
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
        /* #30 check error status */
        if (E_OK != callResult)
        {
            errId = ICU_E_PARAM_CHANNEL_CONFIG;
        } /* else not needed */
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_DISABLE_EDGE_COUNT_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_DISABLE_EDGE_COUNT_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    }
}

/** *****************************************************************************************************
 * \brief Service for reading the number of counted edges
 *
 * \verbatim
 * Syntax             : Icu_EdgeNumberType Icu_GetEdgeNumbers(
 *                                                      Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x0F
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The edge number in edge counter
 *
 * Description        : This function reads the number of counted edges
 * \endverbatim
 * Traceability       : SWSR_ICU_144 SWSR_ICU_145 SWSR_ICU_146 SWSR_ICU_147
 *                      SWSR_ICU_148 SWSR_ICU_149 SWSR_ICU_150
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
Icu_EdgeNumberType Icu_GetEdgeNumbers(Icu_ChannelType Channel)
{
    /* init local varibles */
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Icu_EdgeNumberType edgeNumber = 0U;
    uint8 logChanIdx;
    Icu_MeasurementModeType measureType;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    Icu_HwModule tmrModule;
    uint8 ioIdx;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_GET_EDGE_NUMBER_ID))
    {
        /* get channel configuration information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))
                                                    [logChanIdx].icuHwChanCfgPtr->timerModule;
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
            /* check the measurement mode */
            if (ICU_MODE_EDGE_COUNTER == measureType)
            {
                /* get edge counter */
                edgeNumber = Icu_MulChanEdgeCnt[tmrModule][ioIdx];
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
                edgeNumber = 0U;
            }
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
            /* check the measurement mode */
            if (ICU_MODE_EDGE_COUNTER == measureType)
            {
                /* get edge counter */
                edgeNumber = Icu_ChanEdgeCnt[logChanIdx];
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
                edgeNumber = 0U;
            }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
        /* #30 check error status */
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_GET_EDGE_NUMBER_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_GET_EDGE_NUMBER_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    }
    return edgeNumber;
}
#endif /* STD_ON == ICU_EDGE_COUNT_API */

#if (STD_ON == ICU_EDGE_DETECT_API)
/*******************************************************************************
 * @brief   Icu_EnableEdgeDetection                                            *
 *                                                                             *
 * @details this function enables the detection of edges of the given channel  *
 *                                                                             *
 * @param[in] Channel numeric identifier of the ICU channel                    *
 ******************************************************************************/
void Icu_EnableEdgeDetection
(
    Icu_ChannelType Channel
)
{
    /* init local varibles */
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType callResult = E_OK;
    uint8 logChanIdx;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
    Icu_MeasurementModeType measureType;
    /* #10 check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_ENABLE_EDGE_DETECTION_ID))
    {
        /* get channel configuration information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        hwChannel = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerChannel;
        measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
        /* #20 check the measurement mode, multi cpt not support edge detection */
        if ((ICU_MODE_SIGNAL_EDGE_DETECT == measureType) &&
            (FALSE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable))
        {
            Icu_ChanRunningStatus[logChanIdx] = (boolean)TRUE;
            /* turn on the capture channel */
            callResult = Icu_Ip_TurnOnCapture(tmrModule, hwChannel, FALSE);

        }
        else
        {
            errId = ICU_E_PARAM_CHANNEL;
        }
        /* #30 check error status */
        if (E_OK != callResult)
        {
            errId = ICU_E_PARAM_CHANNEL_CONFIG;
        }
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_ENABLE_EDGE_DETECTION_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_ENABLE_EDGE_DETECTION_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    }
}

/** *****************************************************************************************************
 * \brief Service for disabling the detection of edges of the given channel.
 *
 * \verbatim
 * Syntax             : void Icu_DisableEdgeDetection(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x17
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function disables the detection of edges of the
 *                      given channel
 * \endverbatim
 * Traceability       : SWSR_ICU_132 SWSR_ICU_133 SWSR_ICU_134 SWSR_ICU_135
 *                      SWSR_ICU_136 SWSR_ICU_137
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_DisableEdgeDetection(Icu_ChannelType Channel)
{
    /* init local varibles */
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType callResult = E_OK;
    uint8 logChanIdx;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
    Icu_MeasurementModeType measureType;
    /* #10 check common paramerter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_DISABLE_EDGE_DETECTION_ID))
    {
        /* get channel configuration information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        hwChannel = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerChannel;
        measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
        /* #20 check the measurement mode, multi cpt not support edge detection */
        if ((ICU_MODE_SIGNAL_EDGE_DETECT == measureType) &&
            (FALSE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable))
        {
            Icu_ChanRunningStatus[logChanIdx] = (boolean)FALSE;
            /* turn off the capture channel */
            callResult = Icu_Ip_TurnOffCapture(tmrModule, hwChannel, FALSE);
        }
        else
        {
            errId = ICU_E_PARAM_CHANNEL;
        }
        /* #30 check error status */
        if (E_OK != callResult)
        {
            errId = ICU_E_PARAM_CHANNEL_CONFIG;
        }
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_DISABLE_EDGE_DETECTION_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_DISABLE_EDGE_DETECTION_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    }
}
#endif /* STD_ON == ICU_EDGE_DETECT_API */

#if (STD_ON == ICU_SIGNALMEASUREMENT_API)
/** *****************************************************************************************************
 * \brief Service for starting the measurement of signals.
 *
 * \verbatim
 * Syntax             : void Icu_StartSignalMeasurement(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x13
 *
 * Sync/Async         : Asynchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function starts the measurement of signals
 * \endverbatim
 * Traceability       : SWSR_ICU_151 SWSR_ICU_152 SWSR_ICU_153 SWSR_ICU_154
 *                      SWSR_ICU_155 SWSR_ICU_156 SWSR_ICU_157 SWSR_ICU_158
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_StartSignalMeasurement(Icu_ChannelType Channel)
{
    /* init local varibles */
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType callResult = E_OK;
    uint8 logChanIdx;
    Icu_MeasurementModeType measureType;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    Icu_HwModule tmrModule;
    uint8 ioIdx;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common paramerter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_START_SIGNAL_MEASURE_ID))
    {
        /* get channel configuration information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))
                                                    [logChanIdx].icuHwChanCfgPtr->timerModule;
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
            /* check the measurement mode */
            if (ICU_MODE_SIGNAL_MEASUREMENT == measureType)
            {
                /* set signal measurement mode varibles */
                callResult = Icu_Ip_MultiCptStartSignalMeasurement(tmrModule, ioIdx);
                Icu_MulChanEnable[tmrModule][ioIdx] = TRUE;
                /* check timer enable status */
                if (FALSE == Icu_MulTimerEnable[tmrModule])
                {
                    Icu_MulTimerEnable[tmrModule] = TRUE;
                    Icu_ChanRunningStatus[logChanIdx] = (boolean)TRUE;
#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
                    callResult |= Icu_Ip_MultiCptTurnOnCapture(tmrModule, FALSE);
#else /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */
                    callResult |= Icu_Ip_MultiCptTurnOnCapture(tmrModule, TRUE);
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */
                } /* else not needed */
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
            /* check the measurement mode */
            if (ICU_MODE_SIGNAL_MEASUREMENT == measureType)
            {
                Icu_ChanRunningStatus[logChanIdx] = (boolean)TRUE;
                /* set timer releated harsware register */
                callResult = Icu_Ip_StartSignalMeasurement(
                                                    &(*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx]);
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
        /* #30 check error status */
        if (E_OK != callResult)
        {
            errId = ICU_E_PARAM_CHANNEL_CONFIG;
        }
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_START_SIGNAL_MEASURE_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_START_SIGNAL_MEASURE_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    }
}

/** *****************************************************************************************************
 * \brief Service for stopping the measurement of signals.
 *
 * \verbatim
 * Syntax             : void Icu_StopSignalMeasurement(Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x14
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : This function stops the measurement of signals
 * \endverbatim
 * Traceability       : SWSR_ICU_159 SWSR_ICU_160 SWSR_ICU_161 SWSR_ICU_162
 *                      SWSR_ICU_163 SWSR_ICU_164 SWSR_ICU_165
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_StopSignalMeasurement(Icu_ChannelType Channel)
{
    /* init local varibles */
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType callResult = E_OK;
    uint8 logChanIdx;
    Icu_MeasurementModeType measureType;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    Icu_HwModule tmrModule;
    uint8 ioIdx;
    uint8 mulChanNum;
    boolean turnOffEtimer;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_STOP_SIGNAL_MEASURE_ID))
    {
        /* get channel configuration information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        mulChanNum = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->multiCptChanNum;
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
            /* check the measurement mode */
            if (ICU_MODE_SIGNAL_MEASUREMENT == measureType)
            {
                Icu_MulChanEnable[tmrModule][ioIdx] = FALSE;
                /* check if all xtrg.Io disable */
                turnOffEtimer = Icu_MultiCptOffTimerCheck(tmrModule, mulChanNum);
                if (TRUE == turnOffEtimer)
                {
                    /* turn off etimer capture */
#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
                    callResult = Icu_Ip_MultiCptTurnOffCapture(tmrModule, FALSE);
#else /* ICU_MULTI_CAPTURE_DMA_MODE */
                    callResult = Icu_Ip_MultiCptTurnOffCapture(tmrModule, TRUE);
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */
                    Icu_MulTimerEnable[tmrModule] = FALSE;
                    Icu_ChanRunningStatus[logChanIdx] = (boolean)FALSE;
                } /* else not needed */
                /* restore signal measurement mode varibles */
                callResult |= Icu_Ip_MultiCptStopSignalMeasurement(tmrModule, ioIdx);
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
            /* check the measurement mode */
            if (ICU_MODE_SIGNAL_MEASUREMENT == measureType)
            {
                Icu_ChanRunningStatus[logChanIdx] = (boolean)FALSE;
                /* disable hardware registers */
                callResult = Icu_Ip_StopSignalMeasurement(&(*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx]);
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
        if (E_OK != callResult)
        {
            errId = ICU_E_PARAM_CHANNEL_CONFIG;
        } /* else not needed */
        /* #30 check error status */
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_STOP_SIGNAL_MEASURE_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_STOP_SIGNAL_MEASURE_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    }
}

#if (STD_ON == ICU_GET_DUTYCYCLE_VALUES_API)
/** *****************************************************************************************************
 * \brief Service for reading the coherent active time and period time of given
 *        channel.
 *
 * \verbatim
 * Syntax             : void Icu_GetDutyCycleValues(Icu_ChannelType Channel,
 *                                          Icu_DutyCycleType* DutyCycleValues)
 *
 * Service ID[hex]    : 0x11
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : DutyCycleValues - pointer to a buffer where the results
 *
 * Return value       : None
 *
 * Description        : This function reads the coherent active time and period
 *                      time for the given ICU Channel.
 * \endverbatim
 * Traceability       : SWSR_ICU_178 SWSR_ICU_179 SWSR_ICU_180 SWSR_ICU_181
 *                      SWSR_ICU_182 SWSR_ICU_183 SWSR_ICU_184 SWSR_ICU_185
 *                      SWSR_ICU_186 SWSR_ICU_187 SWSR_ICU_038
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
void Icu_GetDutyCycleValues(Icu_ChannelType Channel, Icu_DutyCycleType* DutyCycleValues)
{
    /* init local varibles */
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Std_ReturnType callResult = E_OK;
    uint8 logChanIdx;
    Icu_MeasurementModeType measureType;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
    Icu_SignalMeasurementPropertyType signalType;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 ioIdx;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_GET_DUTY_CYCLE_VALUES_ID))
    {
        /* check the pointer */
        if (NULL_PTR == DutyCycleValues)
        {
            errId = ICU_E_PARAM_POINTER;
        }
        else
        {
            /* get channel configuration information */
            logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
            tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
            hwChannel = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
            ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
            /* #20 check the channel enable multi capture or not  */
            if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
            {
                measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                                [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
                /* get the measurement type */
                signalType = (*(Icu_ConfigPtr->chanConfigPtr))
                    [logChanIdx].multiCptChanCfgPtr[ioIdx].Icu_MultiCptSigMeasure.sigMeasureMulProperty;
                /* check the measurement mode and signal measurement type */
                if ((ICU_MODE_SIGNAL_MEASUREMENT == measureType) && (ICU_DUTY_CYCLE == signalType))
                {
                    /* get the duty cycle and period value */
                    callResult = Icu_Ip_MultiCptGetDutyCycle(tmrModule, ioIdx, DutyCycleValues);
                }
                else
                {
                    errId = ICU_E_PARAM_CHANNEL;
                }
            }
            else
            {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
                signalType = ((*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].measureParamPtr->sigMeasureProperty);
                measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
                /* check the measurement mode and signal measurement type */
                if ((ICU_MODE_SIGNAL_MEASUREMENT == measureType) && (ICU_DUTY_CYCLE == signalType))
                {
                    /* get the duty cycle and period value */
                    callResult = Icu_Ip_GetDutyCycle(tmrModule, hwChannel, DutyCycleValues);
                }
                else
                {
                    errId = ICU_E_PARAM_CHANNEL;
                }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
            }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
        }
        if (E_OK != callResult)
        {
            errId = ICU_E_PARAM_CHANNEL_CONFIG;
        }
        /* #30 check error status */
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_GET_DUTY_CYCLE_VALUES_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_GET_DUTY_CYCLE_VALUES_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    }
}
#endif /* STD_ON == ICU_GET_DUTYCYCLE_VALUES_API */

#if (STD_ON == ICU_GET_TIMEELAPSED_API)
/** *****************************************************************************************************
 * \brief Service for reading the coherent signal time of given channel.
 *
 * \verbatim
 * Syntax             : Icu_ValueType Icu_GetTimeElapsed(
 *                                                  Icu_ChannelType Channel)
 *
 * Service ID[hex]    : 0x11
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Non reentrant
 *
 * Parameters (in)    : Channel - numeric identifier of the ICU channel
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : The signal time value in sigmaesurement mode
 *
 * Description        : This function reads the elapsed Signal Time for the
 *                      given channel
 * \endverbatim
 * Traceability       : SWSR_ICU_166 SWSR_ICU_167 SWSR_ICU_168 SWSR_ICU_169
 *                      SWSR_ICU_170 SWSR_ICU_171 SWSR_ICU_172 SWSR_ICU_173
 *                      SWSR_ICU_174 SWSR_ICU_175 SWSR_ICU_176 SWSR_ICU_177
 *                      SW_SM001 SW_SM006
 *******************************************************************************************************/
Icu_ValueType Icu_GetTimeElapsed(Icu_ChannelType Channel)
{
    /* init local varibles */
    uint8 errId = ICU_E_PARAM_INVALID_VALUE;
    Icu_ValueType timeElapse = 0U;
    uint8 logChanIdx;
    Icu_MeasurementModeType measureType;
    Icu_HwModule tmrModule;
    Icu_HwChannel hwChannel;
    Icu_SignalMeasurementPropertyType signalType;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
    uint8 ioIdx;
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    /* #10 check common parameter validity */
    if (E_OK == Icu_ValidateCommon(Channel, ICU_GET_TIME_ELPASED_ID))
    {
        /* get channel configuration information */
        logChanIdx = (uint8)(Channel & ICU_ACTUAL_CHAN_INDEX_MASK);
        tmrModule = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerModule;
        hwChannel = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuHwChanCfgPtr->timerChannel;
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        ioIdx = (uint8)((Channel & ICU_MULTI_SUBCHAN_INDEX_MASK) >> ICU_MULTI_SUBCHAN_OFFSET);
        /* #20 check the channel enable multi capture or not  */
        if (TRUE == (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].multiCaptureEnable)
        {
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))
                            [logChanIdx].multiCptChanCfgPtr[ioIdx].icuMeasurementModeMul;
            /* get the measurement type */
            signalType = (*(Icu_ConfigPtr->chanConfigPtr))
                [logChanIdx].multiCptChanCfgPtr[ioIdx].Icu_MultiCptSigMeasure.sigMeasureMulProperty;
            /* check the measurement mode and signal measurement type */
            if ((ICU_MODE_SIGNAL_MEASUREMENT == measureType) &&
                (ICU_DUTY_CYCLE != signalType))
            {
                /* get the signal time information */
                timeElapse = Icu_Ip_MultiCptGetTimeElapsed(tmrModule, ioIdx);
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            signalType = ((*(Icu_ConfigPtr->chanConfigPtr))
                          [logChanIdx].measureParamPtr->sigMeasureProperty);
            measureType = (*(Icu_ConfigPtr->chanConfigPtr))[logChanIdx].icuMeasurementMode;
            /* check the measurement mode and signal measurement type */
            if ((ICU_MODE_SIGNAL_MEASUREMENT == measureType) && (ICU_DUTY_CYCLE != signalType))
            {
                /* get the signal time information */
                timeElapse = Icu_Ip_GetTimeElapsed(tmrModule, hwChannel);
            }
            else
            {
                errId = ICU_E_PARAM_CHANNEL;
            }
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
        /* #30 check error status */
        if (ICU_E_PARAM_INVALID_VALUE != errId)
        {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
            (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_GET_TIME_ELPASED_ID, (uint8)errId);
#endif /* STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
            (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                                    (uint8)ICU_GET_TIME_ELPASED_ID, (uint8)errId);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
        } /* else not needed */
    }
    return timeElapse;
}
#endif /* STD_ON == ICU_GET_TIMEELAPSED_API */
#endif /* STD_ON == ICU_SIGNALMEASUREMENT_API */

#if (STD_ON == ICU_GET_VERSIONINFO_API)
/** *****************************************************************************************************
 * \brief Service returns the version information of this module.
 *
 * \verbatim
 * Syntax             : void Icu_GetVersionInfo(
 *                                          Std_VersionInfoType* versioninfo)
 *
 * Service ID[hex]    : 0x12
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : Reentrant
 *
 * Parameters (in)    : None
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : versioninfo - Pointer to where to store the version
 *                                    information
 *
 * Return value       : None
 *
 * Description        : This function returns the version information of this
 *                      module
 * \endverbatim
 * Traceability       : SWSR_ICU_188 SWSR_ICU_189
 *                      SW_SM006
 *******************************************************************************************************/
void Icu_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    /* check the pointer validity */
    if (NULL_PTR != versioninfo)
    {
        /* get the vendor information */
        versioninfo->vendorID = ICU_VENDOR_ID;
        versioninfo->moduleID = ICU_MODULE_ID;
        /* get the driver version information */
        versioninfo->sw_major_version = ICU_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = ICU_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = ICU_SW_PATCH_VERSION;

    }
    else
    {
#if (STD_ON == ICU_DEV_ERROR_DETECT)
        (void)Det_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                              (uint8)ICU_GET_VERSIONINFO_ID, (uint8)ICU_E_PARAM_VINFO);
#endif /*STD_ON == ICU_DEV_ERROR_DETECT */
#if (STD_ON == ICU_SAFETY_ENABLE)
        (void)FuSaMcal_ReportError((uint16)ICU_MODULE_ID, (uint8)ICU_INSTANCE_ID,
                              (uint8)ICU_GET_VERSIONINFO_ID, (uint8)ICU_E_PARAM_VINFO);
#endif /* STD_ON == ICU_SAFETY_ENABLE */
    }
}
#endif /* STD_ON == ICU_GET_VERSIONINFO_API */

/** *****************************************************************************************************
 * \brief Common entry of interrupt handler.
 *
 * \verbatim
 * Syntax             : void Icu_IrqCommon(Icu_HwModule tmrModule)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : tmrModule - etimer hardware module uint
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Common entry of interrupt handler
 * \endverbatim
 * Traceability       : SWSR_ICU_036 SWSR_ICU_190 SWSR_ICU_202
 *                      SW_SM001 SW_SM003 SW_SM004
 *******************************************************************************************************/
void Icu_IrqCommon(Icu_HwModule tmrModule)
{
    /* init local varibles */
    uint32 irqStatus;
    uint8 j;
    /* #10 driver initial status check */
    if (ICU_STATUS_INITED == Icu_DriverState)
    {
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        /* only etimer1 and etimer2 support multi capture */
        if ((tmrModule <= ICU_INDEX_ETIMER2) && (TRUE == Icu_MulTimerEnable[tmrModule]))
        {
            /* #20 multi capture handler function with interrupt mode */
            Icu_MultiIrqCommon(tmrModule);
        }
        else
        {
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
            /* #30 single capture function handler */
            Icu_SingleIrqCommon(tmrModule);
#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)
        }
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */
    }
    else
    {
        /* if the driver not initilized yet, clear the interrupt flag and no
           need to do anyothing */
        irqStatus = Icu_Ip_GetInterrupt(tmrModule);
        for (j = 0U; j < (uint8)LOCAL_CHANNEL_NUMBER; j++)
        {
            /* #40 check the channel interrupt status */
            if (((irqStatus >> j) & 0x1u) > 0U)
            {
                /* clear the interrupt status */
                /* PRQA S 4342 1 */
                (void)Icu_Ip_ClearInterrupt(tmrModule, (Icu_HwChannel)j);
            } /* else not needed */
        }
    }
}

#if (STD_ON == ICU_DMA_SUPPORT)
/* PRQA S 3673  28 */
/** *****************************************************************************************************
 * \brief Interrupt handler function for timestamp mode when using dma in single
 *        capture mode
 *
 * \verbatim
 * Syntax             : void Icu_DmaIrqHandler(Dma_ControllerStatusType dmaTransSta, void* arg)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : dmaTransSta - dma trandfer date status
 *                      arg  - dma channel information
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt handler function for timestamp mode when using
 *                      dma in single capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_205
 *******************************************************************************************************/
void Icu_DmaIrqHandler(Dma_ControllerStatusType dmaTransSta, void* arg)
{
    /* get dma channel configuration */
    /* PRQA S 0316  1 */
    const Dma_ChannelConfigType *chanRx = (const Dma_ChannelConfigType *)arg;
    /* get channel configuration information */
    /* PRQA S 0316  1 */
    const Icu_ChannelConfigType *channelConfigPtr = (const Icu_ChannelConfigType *)chanRx->context;
    Icu_HwModule tmrModule = channelConfigPtr->icuHwChanCfgPtr->timerModule;
    Icu_HwChannel hwChannel = channelConfigPtr->icuHwChanCfgPtr->timerChannel;
    Icu_MeasurementModeType measureType = channelConfigPtr->icuMeasurementMode;
    Icu_TimestampBufferType bufferType;
    /* logic channel and physic channel mapping */
    uint8 logChan = Icu_PhyToLogMap[tmrModule][hwChannel];
    /* buffer handle initial index */
    uint32 bufferInitIndex;

    /* #10 check dma channel transfer status */
    if (dmaTransSta == DMA_BLOCK_DONE)
    {
        /* check ping-pong buffer half flag */
        if (FALSE == Icu_HalfBufferFlag[logChan])
        {
            Icu_HalfBufferFlag[logChan] = TRUE;
            bufferInitIndex = 0UL;
#if (STD_OFF == ICU_NON_CACHE_NEEDED)
            /* PRQA S 0306  1 */
            Dma_InvalidateCache((uint32)(&Icu_ChanRxBuffer[logChan][ICU_RX_BURST_LEN]),
                                ICU_RX_BURST_LEN * 0x4UL);
#endif /* STD_OFF == ICU_NON_CACHE_NEEDED */
        }
        else
        {
            Icu_HalfBufferFlag[logChan] = FALSE;
            bufferInitIndex = ICU_RX_BURST_LEN;
#if (STD_OFF == ICU_NON_CACHE_NEEDED)
            /* PRQA S 0306  1 */
            Dma_InvalidateCache((uint32)(&Icu_ChanRxBuffer[logChan][0]),
                                ICU_RX_BURST_LEN * 0x4UL);
#endif /* STD_OFF == ICU_NON_CACHE_NEEDED */
        }

        /* #20 only timestamp mode support dma in single capture mode */
        if (ICU_MODE_TIMESTAMP == measureType)
        {
            bufferType = channelConfigPtr->measureParamPtr->Icu_TimestampMeasurement.tsBufferProperty;
            /* timestamp mode handler in dma mode */
            Icu_SingleDmaTsHandler(tmrModule, hwChannel, logChan, bufferType, bufferInitIndex);
        } /* else not needed */
    }
}
#endif /* STD_ON == ICU_DMA_SUPPORT */

#if (STD_ON == ICU_MULTI_CAPTURE_SUPPORT)

#if (STD_ON == ICU_MULTI_CAPTURE_DMA_MODE)
/* PRQA S 3673  28 */
/** *****************************************************************************************************
 * \brief Interrupt handler function when using dma in multi capture mode
 *
 * \verbatim
 * Syntax             : void Icu_MultiCptDmaIrqHandler(Dma_ControllerStatusType dmaTransSta,
 *                                                     void* arg)
 *
 * Service ID[hex]    : None
 *
 * Sync/Async         : Synchronous
 *
 * Reentrancy         : None
 *
 * Parameters (in)    : dmaTransSta - dma trandfer date status
 *                      arg  - dma channel information
 *
 * Parameters (inout) : None
 *
 * Parameters (out)   : None
 *
 * Return value       : None
 *
 * Description        : Interrupt handler function when using dma in multi
 *                      capture mode
 * \endverbatim
 * Traceability       : SWSR_ICU_205 SWSR_ICU_206
 *******************************************************************************************************/
void Icu_MultiCptDmaIrqHandler(Dma_ControllerStatusType dmaTransSta, void* arg)
{
    /* get dma channel configuration */
    /* PRQA S 0316  1 */
    const Dma_ChannelConfigType *mulChanRx = (const Dma_ChannelConfigType *)arg;
    /* PRQA S 0316  1 */
    const Icu_ChannelConfigType *mulChanConfigPtr = (const Icu_ChannelConfigType *)mulChanRx->context;
    /* get channel configuration information */
    Icu_HwModule tmrModule = mulChanConfigPtr->icuHwChanCfgPtr->timerModule;
    uint8 mulChanNum = mulChanConfigPtr->icuHwChanCfgPtr->multiCptChanNum;
    /* multi etimer chn b store logic chan number for multi interrupt mode */
    uint8 logicChan =Icu_PhyToLogMap[tmrModule][ICU_HW_CPT_B];
    uint32 bufferInitIndex;
    uint32 bufferEndIndex;
    uint8 ioIdx;
    uint32 index;
    boolean ioEdgeChange;
    uint32 chancVal;
    /* #10 check dma channel transfer status */
    if (dmaTransSta == DMA_BLOCK_DONE)
    {

        /* #20 check ping-pong buffer half flag */
        if (FALSE == Icu_MulHalfBufferFlag[tmrModule])
        {
            Icu_MulHalfBufferFlag[tmrModule] = TRUE;
            bufferInitIndex = 0UL;
#if (STD_OFF == ICU_NON_CACHE_NEEDED)
            /* PRQA S 0306  1 */
            Dma_InvalidateCache((uint32)(&Icu_MulChanbBuffer[tmrModule][MULTI_CPT_BURST_LEN]),
                                MULTI_CPT_BURST_LEN * 0x4UL);
            /* PRQA S 0306  1 */
            Dma_InvalidateCache((uint32)(&Icu_MulChancBuffer[tmrModule][MULTI_CPT_BURST_LEN]),
                                MULTI_CPT_BURST_LEN * 0x4UL);
#endif /* STD_OFF == ICU_NON_CACHE_NEEDED */
        }
        else
        {
            Icu_MulHalfBufferFlag[tmrModule] = FALSE;
            bufferInitIndex = MULTI_CPT_BURST_LEN;
#if (STD_OFF == ICU_NON_CACHE_NEEDED)
            /* PRQA S 0306  1 */
            Dma_InvalidateCache((uint32)(&Icu_MulChanbBuffer[tmrModule][0]),
                                MULTI_CPT_BURST_LEN * 0x4UL);
            /* PRQA S 0306  1 */
            Dma_InvalidateCache((uint32)(&Icu_MulChancBuffer[tmrModule][0]),
                                MULTI_CPT_BURST_LEN * 0x4UL);
#endif /* STD_OFF == ICU_NON_CACHE_NEEDED */
        }
        bufferEndIndex = bufferInitIndex + MULTI_CPT_BURST_LEN;
        if (FALSE == Icu_MulHaveGotValFlag[tmrModule])
        {
            /* #30 first value captured no need to handle */
            Icu_MulHaveGotValFlag[tmrModule] = TRUE;
            /* store the first captured value */
            Icu_MulPreIoVlue[tmrModule] = Icu_MulChanbBuffer[tmrModule][bufferInitIndex];
            for (ioIdx = 0U; ioIdx < mulChanNum; ioIdx++)
            {
                Icu_MulPreCptTime[tmrModule][ioIdx] = Icu_MulChancBuffer[tmrModule][bufferInitIndex];
            }
            bufferInitIndex++;
        }
        for (index = bufferInitIndex; index < bufferEndIndex; index++)
        {
            Icu_MulChangeIoChan[tmrModule] = Icu_MulChanbBuffer[tmrModule][index] ^
                                             Icu_MulPreIoVlue[tmrModule];
            for (ioIdx = 0U; ioIdx < mulChanNum; ioIdx++)
            {
                if (FALSE == Icu_MulChanEnable[tmrModule][ioIdx])
                {
                    continue;
                } /* else not needed */
                ioEdgeChange =
                        ((Icu_MulChangeIoChan[tmrModule] & (0x1UL << ioIdx)) > 0UL) ? TRUE : FALSE;
                if (TRUE == ioEdgeChange)
                {
                    chancVal = Icu_MulChancBuffer[tmrModule][index];
                    /* #40 sub channel edge change handler */
                    Icu_MultiCptEdgeChangeHandler(tmrModule, logicChan, ioIdx, chancVal);
                    Icu_MulPreCptTime[tmrModule][ioIdx] = Icu_MulChancBuffer[tmrModule][index];
                } /* else not needed */
            }
            Icu_MulPreIoVlue[tmrModule] = Icu_MulChanbBuffer[tmrModule][index];
        }
    }
}
#endif /* STD_ON == ICU_MULTI_CAPTURE_DMA_MODE */
#endif /* STD_ON == ICU_MULTI_CAPTURE_SUPPORT */

/* memap infomation */
#define ICU_STOP_SEC_CODE
#include "Icu_MemMap.h"
#pragma default_function_attributes =
#ifdef __cplusplus
}
#endif
/* End of file */
