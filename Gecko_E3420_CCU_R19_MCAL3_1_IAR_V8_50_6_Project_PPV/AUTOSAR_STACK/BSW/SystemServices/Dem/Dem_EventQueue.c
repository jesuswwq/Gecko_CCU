/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Dem_EventQueue.c                                            **
**                                                                            **
**  Created on  :                                                             **
**  Author      : tao.yu                                                      **
**  Vendor      : i-soft                                                      **
**  DESCRIPTION : API definitions of DEM for EventQueue                       **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem_Internal.h"
#if (STD_ON == DEM_TRIGGER_FIM_REPORTS)
#include "FiM.h"
#endif

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
typedef struct
{
    Dem_EventDataBufferType Queue[DEM_EVENT_QUEUE_SIZE];
    uint8 ReadIndex;
    uint8 WriteIndex;
} Dem_EventQueueType;

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
static VAR(Dem_EventQueueType, AUTOMATIC) DemEventQueue;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

/*******************************************************************************
**                      Private Function Definitions                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*************************************************************************/
/*
 * Brief               Dem_EventQueueInit
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_EventQueueInit(void) /* PRQA S 1532 */                                   /* MISRA Rule 8.7 */
{
    P2VAR(Dem_EventQueueType, AUTOMATIC, DEM_VAR) pQueue = &DemEventQueue; /* PRQA S 3432 */      /* MISRA Rule 20.7 */
    P2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pBuffer = pQueue->Queue; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint16 iloop = 0;

    pQueue->ReadIndex = 0x00;
    pQueue->WriteIndex = 0x00;

    while (iloop < DEM_EVENT_QUEUE_SIZE)
    {
        pBuffer->ExtId = 0x00;
        pBuffer->Status = 0x00;
#if ((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0))
#if (DEM_FREEZE_FRAME_MAX_LEN > 0u)
        Dem_MemSet(pBuffer->FFData, 0xFFu, DEM_FREEZE_FRAME_MAX_LEN);
#endif
#endif
#if (DEM_EXTENDED_DATA_CLASS_NUM > 0)
#if (DEM_EXTENDED_DATA_MAX_LEN > 0u)
        Dem_MemSet(pBuffer->ExtData, 0xFFu, DEM_EXTENDED_DATA_MAX_LEN);
#endif
#endif
        iloop++;
        pBuffer++;
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_EventQueueAdd
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ExtId && Status
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
FUNC(Std_ReturnType, DEM_CODE) Dem_EventQueueAdd(Dem_EventIdType ExtId, Dem_EventStatusType Status)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    SuspendAllInterrupts();
    Std_ReturnType res = E_NOT_OK;
    P2VAR(Dem_EventQueueType, AUTOMATIC, DEM_VAR) pQueue = &DemEventQueue; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    /* PRQA S 3432++ */                                                                      /* MISRA Rule 20.7 */
    P2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pBuffer = &(pQueue->Queue[pQueue->WriteIndex]);
    /* PRQA S 3432-- */                                                                      /* MISRA Rule 20.7 */

    if (pBuffer->ExtId == 0x00u)
    {
        pBuffer->ExtId = ExtId;
        pBuffer->Status = Status;
#if (DEM_ENVIRONMENT_DATA_CAPTURE == DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING)
#if (                                                                          \
    (DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) \
    || (DEM_PID_CLASS_NUM > 0)) /*SWS_Dem_00805*/
        Dem_GetFreezeFrame(Dem_GetEventInternalId(ExtId), pBuffer->FFData);
#endif
#if (DEM_EXTENDED_DATA_CLASS_NUM > 0) /*SWS_Dem_00812*/
        Dem_GetExtendedData(Dem_GetEventInternalId(ExtId), pBuffer->ExtData);
#endif
#endif
        pQueue->WriteIndex++;
        if (pQueue->WriteIndex >= DEM_EVENT_QUEUE_SIZE)
        {
            pQueue->WriteIndex = 0x00;
        }
        res = E_OK;
    }

    ResumeAllInterrupts();
    return res;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_EventQueueProcess
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_EventQueueProcess(void) /* PRQA S 1532 */                           /* MISRA Rule 8.7 */
{
    P2VAR(Dem_EventQueueType, AUTOMATIC, DEM_VAR) pQueue = &DemEventQueue; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    /* PRQA S 3432++ */                                                                      /* MISRA Rule 20.7 */
    P2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pBuffer = &(pQueue->Queue[pQueue->ReadIndex]);
    /* PRQA S 3432-- */                                                                      /* MISRA Rule 20.7 */
    Dem_EventIdType IntId;
    uint8 OperationCycleId;
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#if (DEM_DEAL_MAINFUNCTION_ENABLE == STD_ON)
    uint8 Deal_Cnt = 0;
#endif
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
    uint8 OldStatus;
#endif
    /* Proccess Event */
    while ((pBuffer->ExtId != 0x00u)
#if (DEM_DEAL_MAINFUNCTION_ENABLE == STD_ON)
           && (Deal_Cnt < DEM_DEAL_MAINFUNCTION_COUNTER)
#endif
    )
    {
#if (DEM_DEAL_MAINFUNCTION_ENABLE == STD_ON)
        Deal_Cnt++;
#endif
        IntId = Dem_GetEventInternalId(pBuffer->ExtId);
        pEvent = Dem_GetEventInfo(IntId);
        OperationCycleId = DemPbCfgPtr->DemEventParameter[IntId].DemOperationCycleRef;
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
        OldStatus = pEvent->UdsStatus;
#endif
        if ((0x00u != DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_DTC_SETTING))
            && (0x00u != DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
#if (DEM_ENABLE_CONDITION_NUM > 0)
            && (0x00u != DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_ENABLED_CONDICTION))
#endif
        )
        {
            /*SWS_Dem_00854] */
            if (((0x00u != DEM_BITS_ISSET(DemOperationCycleStatus, OperationCycleId))
                 || (DemOperationCycle[OperationCycleId].DemOperationCycleType
                     == DEM_OPCYC_OBD_DCY)) /*SWS_Dem_00700]*/)
            {
                if ((pBuffer->Status == DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED) && (pEvent->FDC_Trigger == FALSE))
                {
                    pEvent->FDC_Trigger = TRUE; /*SWS_Dem_01068,SWS_Dem_01069*/
                    Dem_EventDataStorageTrigger(
                        IntId,
                        (Dem_EventDataBufferType* const)pBuffer,
                        DEM_TRIGGER_ON_FDC_THRESHOLD);
                }
                else
                {
                    uint16 DemDTCRef = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;
                    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST)
                    pEventCfg = &DemPbCfgPtr->DemEventParameter[IntId];
                    /* Debounce */
                    switch (Dem_DebounceProcess((Dem_EventDataBufferType* const)pBuffer))
                    {
                    case DEM_EVENT_STATUS_PASSED:
                        Dem_EventTestPassed(IntId, (Dem_EventDataBufferType* const)pBuffer);
                        break;
                    case DEM_EVENT_STATUS_FAILED:
                        Dem_EventTestFailed(IntId, (Dem_EventDataBufferType* const)pBuffer);
                        break;
                    default:
                        /*idle*/
                        break;
                    }
                    Dem_UpdateFDC(IntId);
                    /*SWS_Dem_00786][SWS_Dem_01068][SWS_Dem_00811] [SWS_Dem_01069]*/
                    if ((DemDTCRef != DEM_DTC_REF_INVALID) && (FDCInfo[DemDTCRef].FDC > 0)
                        && (DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[DemDTCRef].DemDTCAttributesRef]
                                .DemEventMemoryEntryFdcThresholdStorageValue
                            <= (uint8)FDCInfo[DemDTCRef].FDC)
                        && (DEM_DEBOUNCE_COUNTER_BASED == pEventCfg->AlgorithmType))
                    {
                        /*SWS_Dem_00799]*/
                        DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_FDC_TRIGGERED);
#if (DEM_TRIGGER_ON_FDC_THRESHOLD == DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER)
                        Dem_EventRetention(IntId, (Dem_EventDataBufferType* const)pBuffer);
#else
                        Dem_EventDataStorageTrigger(
                            IntId,
                            (Dem_EventDataBufferType* const)pBuffer,
                            DEM_TRIGGER_ON_FDC_THRESHOLD);
#endif
                    }
                }
            }
            else
            { /*debounce counter shall be reset to zero*/
                switch (DemPbCfgPtr->DemEventParameter[IntId].AlgorithmType)
                {
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
                case DEM_DEBOUNCE_COUNTER_BASED:
                    if (DemPbCfgPtr->DemEventParameter[IntId].AlgorithmIndex < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM)
                    {
                        DemDebounceCounterInfo[DemPbCfgPtr->DemEventParameter[IntId].AlgorithmIndex]
                            .InternalDebounceCounter = 0;
                        DemDebounceCounterInfo[DemPbCfgPtr->DemEventParameter[IntId].AlgorithmIndex].CurStatus =
                            DEM_EVENT_STATUS_PREPASSED;
                    }
                    break;
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
                case DEM_DEBOUNCE_TIME_BASE:
                    if (DemPbCfgPtr->DemEventParameter[IntId].AlgorithmIndex < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM)
                    {
                        DemDebounceTimerInfo[DemPbCfgPtr->DemEventParameter[IntId].AlgorithmIndex].Timeout = 0u;
                        DemDebounceTimerInfo[DemPbCfgPtr->DemEventParameter[IntId].AlgorithmIndex].Triggered = FALSE;
                        DemDebounceTimerInfo[DemPbCfgPtr->DemEventParameter[IntId].AlgorithmIndex].CurStatus =
                            DEM_EVENT_STATUS_PREPASSED;
                    }
                    break;
#endif
                default:
                    /*idle*/
                    break;
                }
            }
        }
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
        if (OldStatus != pEvent->UdsStatus)
        {
            (void)FiM_DemTriggerOnEventStatus(pEvent->IntId + 1u, OldStatus, pEvent->UdsStatus);
        }
#endif
        /* Clear Buffer */
        pBuffer->ExtId = 0x00;
        pBuffer->Status = 0x00;

        /* Move ReadIndex */
        pQueue->ReadIndex++;
        if (pQueue->ReadIndex >= DEM_EVENT_QUEUE_SIZE)
        {
            pQueue->ReadIndex = 0x00;
        }
        pBuffer = &(pQueue->Queue[pQueue->ReadIndex]);
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/
