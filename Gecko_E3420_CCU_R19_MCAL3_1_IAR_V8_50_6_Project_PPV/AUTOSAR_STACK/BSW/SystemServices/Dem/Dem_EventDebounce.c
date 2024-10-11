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
**  FILENAME    : Dem_EventDebounce.c                                         **
**                                                                            **
**  Created on  :                                                             **
**  Author      : tao.yu                                                      **
**  Vendor      : i-soft                                                      **
**  DESCRIPTION : DEM EventDebounce API definitions                           **
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
**                      macros  define                                        **
*******************************************************************************/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(FDCInfoType, AUTOMATIC) FDCInfo[DEM_DTC_NUM];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
/* Debounce Counter Base Info Define */

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(Dem_DebounceCounterInfoType, AUTOMATIC) DemDebounceCounterInfo[DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM];
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
VAR(Dem_DebounceTimeInfoType, AUTOMATIC) DemDebounceTimerInfo[DEM_DEBOUNCE_TIME_BASED_EVENT_NUM];
#endif
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
static FUNC(void, DEM_CODE) Dem_DebouceProcessPrePassedCounter(
    P2CONST(Dem_DebounceCounterBasedClassType, AUTOMATIC, DEM_CONST) pCfgCounter,
    P2VAR(Dem_DebounceCounterInfoType, AUTOMATIC, DEM_VAR) pCounter);
static FUNC(void, DEM_CODE) Dem_DebouceProcessPreFailedCounter(
    P2CONST(Dem_DebounceCounterBasedClassType, AUTOMATIC, DEM_CONST) pCfgCounter,
    P2VAR(Dem_DebounceCounterInfoType, AUTOMATIC, DEM_VAR) pCounter);
static FUNC(Dem_EventStatusType, DEM_CODE) Dem_DebounceProcessCounter(
    CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer,
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg);
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
static FUNC(Dem_EventStatusType, DEM_CODE) Dem_DebounceProcessTimer(
    CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer,
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg);
#endif
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*************************************************************************/
/*
 * Brief               Dem_DebounceInit
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_DebounceInit(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint16 iloop;

#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
    iloop = 0;
    while (iloop < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM)
    {
        DemDebounceCounterInfo[iloop].InternalDebounceCounter = 0;
        DemDebounceCounterInfo[iloop].CurStatus = DEM_EVENT_STATUS_PREPASSED;
        iloop++;
    }
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    iloop = 0;
    while (iloop < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM)
    {
        DemDebounceTimerInfo[iloop].Timeout = 0x00;
        DemDebounceTimerInfo[iloop].Triggered = FALSE;
        DemDebounceTimerInfo[iloop].CurStatus = DEM_EVENT_STATUS_PREPASSED;
        iloop++;
    }
#endif
    iloop = 0;
    while (iloop < DEM_DTC_NUM)
    {
        FDCInfo[iloop].FDC = 0;
        FDCInfo[iloop].MaxFDCDuringCurrentCycle = 0;
        FDCInfo[iloop].MaxFDCSinceLastClear = 0;
        iloop++;
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_DebounceReset
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_DebounceReset(Dem_EventIdType IntId)
{
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg = &DemPbCfgPtr->DemEventParameter[IntId];

#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
    P2VAR(Dem_DebounceCounterInfoType, AUTOMATIC, DEM_VAR) pCounter; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    P2VAR(Dem_DebounceTimeInfoType, AUTOMATIC, DEM_VAR) pTimer; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#endif

    switch (pEventCfg->AlgorithmType)
    {
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
    case DEM_DEBOUNCE_COUNTER_BASED:
        if (pEventCfg->AlgorithmIndex < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM)
        {
            pCounter = &DemDebounceCounterInfo[pEventCfg->AlgorithmIndex];
            pCounter->CurStatus = DEM_EVENT_STATUS_PREPASSED;
            pCounter->InternalDebounceCounter = 0;
        }
        break;
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    case DEM_DEBOUNCE_TIME_BASE:
        if (pEventCfg->AlgorithmIndex < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM)
        {
            pTimer = &DemDebounceTimerInfo[pEventCfg->AlgorithmIndex];
            pTimer->Timeout = 0;
            pTimer->Triggered = FALSE;
            pTimer->CurStatus = DEM_EVENT_STATUS_PREPASSED;
        }
        break;
#endif
    default:
        /*idle*/
        break;
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_GetInteralFDC
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              sint8
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
Dem_GetInteralFDC(Dem_EventIdType IntId, P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg = &DemPbCfgPtr->DemEventParameter[IntId];
    Std_ReturnType ret = E_NOT_OK;
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
    P2VAR(Dem_DebounceCounterInfoType, AUTOMATIC, DEM_VAR) pCounter; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(Dem_DebounceCounterBasedClassType, AUTOMATIC, DEM_CONST) pCfgCounter;
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    P2VAR(Dem_DebounceTimeInfoType, AUTOMATIC, DEM_VAR) pTimer; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(Dem_DebounceTimeBaseClassType, AUTOMATIC, DEM_CONST) pTimerCfg;
#endif
#if (DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0)
    Dem_GetFDCFncType GetFnc;
#endif
    switch (pEventCfg->AlgorithmType)
    {
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
    case DEM_DEBOUNCE_COUNTER_BASED: /*SWS_Dem_00415*/
        if (((DemPbCfgPtr->DemEventParameter[IntId].AlgorithmRef) < DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM)
            && ((pEventCfg->AlgorithmIndex) < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM))
        {
            pCfgCounter =
                &DemPbCfgPtr->DemDebounceCounterBasedClass[DemPbCfgPtr->DemEventParameter[IntId].AlgorithmRef];
            pCounter = &DemDebounceCounterInfo[pEventCfg->AlgorithmIndex];
            if (pCounter->InternalDebounceCounter > 0)
            {
                *FaultDetectionCounter = (sint8)((pCounter->InternalDebounceCounter * 127)
                                                 / (sint32)pCfgCounter->DemDebounceCounterFailedThreshold);
            }
            else
            {
                *FaultDetectionCounter = (sint8)((pCounter->InternalDebounceCounter * (-128))
                                                 / (sint32)pCfgCounter->DemDebounceCounterPassedThreshold);
            }
            ret = E_OK;
        }
        break;
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    case DEM_DEBOUNCE_TIME_BASE: /*SWS_Dem_00427*/
        if (((DemPbCfgPtr->DemEventParameter[IntId].AlgorithmRef) < DEM_DEBOUNCE_TIME_BASE_CLASS_NUM)
            && ((pEventCfg->AlgorithmIndex) < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM))
        {
            pTimer = &DemDebounceTimerInfo[pEventCfg->AlgorithmIndex];
            pTimerCfg = &DemPbCfgPtr->DemDebounceTimeBaseClass[DemPbCfgPtr->DemEventParameter[IntId].AlgorithmRef];
            switch (pTimer->CurStatus)
            {
            case DEM_EVENT_STATUS_FAILED:
            case DEM_EVENT_STATUS_PREFAILED:
                *FaultDetectionCounter = (sint8)((pTimer->Timeout * 127UL) /* PRQA S 4394 */ /* MISRA Rule 10.8 */
                                                 / (uint64)pTimerCfg->DemDebounceTimeFailedThreshold);
                break;
            default:
                /* PRQA S 4394++ */                                                             /* MISRA Rule 10.8 */
                *FaultDetectionCounter = ((sint8)(-1))
                                         * ((sint8)((pTimer->Timeout * 128UL) /* PRQA S 4394 */ /* MISRA Rule 10.8 */
                                                    / (uint64)pTimerCfg->DemDebounceTimePassedThreshold));
                /* PRQA S 4394-- */                                                             /* MISRA Rule 10.8 */
                break;
            }
            ret = E_OK;
        }
        break;
#endif
#if (DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0)
    case DEM_DEBOUNCE_MONITOR_INTERNAL: /*SWS_Dem_00264] */
        if ((DemPbCfgPtr->DemEventParameter[IntId].AlgorithmRef) < DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM)
        {
            GetFnc = DemGetFDCFncs[DemPbCfgPtr->DemEventParameter[IntId].AlgorithmRef];
            *FaultDetectionCounter = 0;
            if (GetFnc != NULL_PTR)
            { /*SWS_Dem_00439] */
                ret = GetFnc(FaultDetectionCounter);
                if (E_OK != ret)
                {
                    *FaultDetectionCounter = 0;
                }
            }
            else
            {
                ret = DEM_E_NO_FDC_AVAILABLE;
            }
        }
        break;
#endif
    default:
        *FaultDetectionCounter = 0;
        break;
    }
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_DebounceProcess
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEventBuffer
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Dem_EventStatusType
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Dem_EventStatusType, DEM_CODE)
/* PRQA S 1532，3432++ */ /* MISRA Rule 8.7，Rule 20.7 */
Dem_DebounceProcess(CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer)
/* PRQA S 1532，3432-- */ /* MISRA Rule 8.7，Rule 20.7 */
{
    Dem_EventIdType IntId = Dem_GetEventInternalId(pEventBuffer->ExtId);
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg = &DemPbCfgPtr->DemEventParameter[IntId];
    Dem_EventStatusType Status = pEventBuffer->Status;
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent = Dem_GetEventInfo(IntId);
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint16 DemDTCRef = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;

    switch (pEventCfg->AlgorithmType)
    {
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
    case DEM_DEBOUNCE_COUNTER_BASED:
        Status = Dem_DebounceProcessCounter(pEventBuffer, pEventCfg);
        break;
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    case DEM_DEBOUNCE_TIME_BASE:
        Status = Dem_DebounceProcessTimer(pEventBuffer, pEventCfg);
        break;
#endif
    default:
        /*idle*/
        break;
    }
    /* if event failed clear anging counter*/
    pEvent->AgingCounter = (DEM_EVENT_STATUS_FAILED == Status) ? 0u : pEvent->AgingCounter;
    if (DEM_EVENT_STATUS_FAILED == Status)
    {
        Dem_EventQueueAddDebounceFailed(pEvent);
    }
    /*SWS_Dem_00786][SWS_Dem_01068][SWS_Dem_00811] [SWS_Dem_01069]*/
    Dem_UpdateFDC(IntId);
    if ((DemDTCRef != DEM_DTC_REF_INVALID) && (FDCInfo[DemDTCRef].FDC > 0)
        && (DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[DemDTCRef].DemDTCAttributesRef]
                .DemEventMemoryEntryFdcThresholdStorageValue
            <= (uint8)FDCInfo[DemDTCRef].FDC)
        && (DEM_DEBOUNCE_COUNTER_BASED == pEventCfg->AlgorithmType))
    {
        /*SWS_Dem_00799]*/
        DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_FDC_TRIGGERED);
#if (DEM_TRIGGER_ON_FDC_THRESHOLD == DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER)
        Dem_EventRetention(IntId, pEventBuffer);
#else
        Dem_EventDataStorageTrigger(IntId, pEventBuffer, DEM_TRIGGER_ON_FDC_THRESHOLD);
#endif
    }
    return Status;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
/*************************************************************************/
/*
 * Brief               Dem_DebounceFreeze
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_DebounceFreeze(Dem_EventIdType IntId)
{
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg = &DemPbCfgPtr->DemEventParameter[IntId];
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    /*[SWS_Dem_00654]  [SWS_Dem_00677] */
    if ((pEventCfg->AlgorithmType == DEM_DEBOUNCE_TIME_BASE)
        && (pEventCfg->AlgorithmRef < DEM_DEBOUNCE_TIME_BASE_CLASS_NUM)
        && (pEventCfg->AlgorithmIndex < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM))
    {
        if (DemPbCfgPtr->DemDebounceTimeBaseClass[pEventCfg->AlgorithmRef].DemDebounceBehavior == DEM_DEBOUNCE_FREEZE)
        {
            DemDebounceTimerInfo[pEventCfg->AlgorithmIndex].IsFreezing = TRUE;
        }
        else
        {
            DemDebounceTimerInfo[pEventCfg->AlgorithmIndex].CurStatus = DEM_EVENT_STATUS_PREPASSED;
            DemDebounceTimerInfo[pEventCfg->AlgorithmIndex].Timeout = 0;
            DemDebounceTimerInfo[pEventCfg->AlgorithmIndex].Triggered = FALSE;
        }
    }
    else
#endif /* (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
        if ((pEventCfg->AlgorithmType == DEM_DEBOUNCE_COUNTER_BASED)
            && (pEventCfg->AlgorithmRef < DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM)
            && (pEventCfg->AlgorithmIndex < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM))
    {
        if (DemPbCfgPtr->DemDebounceCounterBasedClass[pEventCfg->AlgorithmRef].DemDebounceBehavior
            == DEM_DEBOUNCE_RESET)
        {
            DemDebounceCounterInfo[pEventCfg->AlgorithmIndex].InternalDebounceCounter = 0;
        }
    }
    else
#endif /* (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0) */
    {
        /*idle*/
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
/*************************************************************************/
/*
 * Brief               Dem_DebounceTimerMain
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_DebounceTimerMain(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg;
    P2CONST(Dem_DebounceTimeBaseClassType, AUTOMATIC, DEM_CONST) pTimerCfg;

    uint16 iloop = 0;
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_DebounceTimeInfoType, AUTOMATIC, DEM_VAR) pTimer = DemDebounceTimerInfo;
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */

#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
    uint8 OldStatus;
#endif

    while ((iloop < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM)
           && (DemPbCfgPtr->DemEventParameter[pTimer->IntId].AlgorithmRef < DEM_DEBOUNCE_TIME_BASE_CLASS_NUM))
    {
        if ((pTimer->Triggered == TRUE) && (pTimer->IsFreezing == FALSE))
        {
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
            OldStatus = pTimer->CurStatus;
#endif
            if ((pTimer->CurStatus != DEM_EVENT_STATUS_FAILED) && (pTimer->CurStatus != DEM_EVENT_STATUS_PASSED))
            {
                pTimer->Timeout += DEM_TASK_TIME;
            }
            pTimerCfg =
                &DemPbCfgPtr->DemDebounceTimeBaseClass[DemPbCfgPtr->DemEventParameter[pTimer->IntId].AlgorithmRef];
            pEventCfg = &DemPbCfgPtr->DemEventParameter[pTimer->IntId];
            if ((pTimer->Timeout >= pTimerCfg->DemDebounceTimeFailedThreshold)
                && ((pTimer->CurStatus == DEM_EVENT_STATUS_PREFAILED)))
            {
                pTimer->CurStatus = DEM_EVENT_STATUS_FAILED;
                pTimer->Triggered = FALSE;
                if ((0x00u != DEM_BITS_ISSET(DemOperationCycleStatus, pEventCfg->DemOperationCycleRef))
                    || (DemOperationCycle[pEventCfg->DemOperationCycleRef].DemOperationCycleType == DEM_OPCYC_OBD_DCY))
                {
                    Dem_EventQueueAddDebounceFailed(&DemEventRelateInformation[pTimer->IntId]);
                    Dem_EventTestFailed(pTimer->IntId, (Dem_EventDataBufferType* const)&(pTimer->Dem_EventBuffer));
                }
            }
            else if (
                (pTimer->Timeout >= pTimerCfg->DemDebounceTimePassedThreshold)
                && ((pTimer->CurStatus == DEM_EVENT_STATUS_PREPASSED)))
            {
                pTimer->CurStatus = DEM_EVENT_STATUS_PASSED;
                pTimer->Triggered = FALSE;
                if ((0x00u != DEM_BITS_ISSET(DemOperationCycleStatus, pEventCfg->DemOperationCycleRef))
                    || (DemOperationCycle[pEventCfg->DemOperationCycleRef].DemOperationCycleType == DEM_OPCYC_OBD_DCY))
                {
                    Dem_EventTestPassed(pTimer->IntId, (Dem_EventDataBufferType* const)&(pTimer->Dem_EventBuffer));
                }
            }
            else
            {
                /*idle*/
            }
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
            if (OldStatus != pTimer->CurStatus)
            {
                (void)FiM_DemTriggerOnEventStatus(pTimer->IntId + 1u, OldStatus, pTimer->CurStatus);
            }
#endif
        }
        pTimer++;
        iloop++;
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)

static FUNC(void, DEM_CODE) Dem_DebouceProcessPrePassedCounter(
    P2CONST(Dem_DebounceCounterBasedClassType, AUTOMATIC, DEM_CONST) pCfgCounter,
    P2VAR(Dem_DebounceCounterInfoType, AUTOMATIC, DEM_VAR) pCounter) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    switch (pCounter->CurStatus)
    {
    case DEM_EVENT_STATUS_FAILED:                            /* Failed => PrePassed */
    case DEM_EVENT_STATUS_PREFAILED:                         /* PreFailed => PrePassed */
        if (pCfgCounter->DemDebounceCounterJumpDown == TRUE) /*SWS_Dem_00423*/
        {
            if (pCounter->InternalDebounceCounter > pCfgCounter->DemDebounceCounterJumpDownValue)
            {
                pCounter->InternalDebounceCounter = pCfgCounter->DemDebounceCounterJumpDownValue;
            }
        }
    case DEM_EVENT_STATUS_PREPASSED: /* PrePassed => PrePassed SWS_Dem_00419*/ /* PRQA S 2003 */ /* MISRA Rule 16.3 */
        if ((pCfgCounter->DemDebounceCounterPassedThreshold
             + ((sint16)pCfgCounter->DemDebounceCounterDecrementStepSize))
            >= (sint16)pCounter->InternalDebounceCounter)
        {
            pCounter->InternalDebounceCounter = pCfgCounter->DemDebounceCounterPassedThreshold;
        }
        else
        {
            pCounter->InternalDebounceCounter -= (sint16)pCfgCounter->DemDebounceCounterDecrementStepSize;
        }
        break;
    default: /* Passed do nothing */
        break;
    }
}

static FUNC(void, DEM_CODE) Dem_DebouceProcessPreFailedCounter(
    P2CONST(Dem_DebounceCounterBasedClassType, AUTOMATIC, DEM_CONST) pCfgCounter,
    P2VAR(Dem_DebounceCounterInfoType, AUTOMATIC, DEM_VAR) pCounter) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    switch (pCounter->CurStatus)
    {
    case DEM_EVENT_STATUS_PASSED:                          /* Passed => Prefailed */
    case DEM_EVENT_STATUS_PREPASSED:                       /* PrePassed => Prefailed */
        if (pCfgCounter->DemDebounceCounterJumpUp == TRUE) /*SWS_Dem_00425*/
        {
            if (pCounter->InternalDebounceCounter < pCfgCounter->DemDebounceCounterJumpUpValue)
            {
                pCounter->InternalDebounceCounter = pCfgCounter->DemDebounceCounterJumpUpValue;
            }
        }
    case DEM_EVENT_STATUS_PREFAILED: /* Prefailed => Prefailed SWS_Dem_00418 */ /* PRQA S 2003 */ /* MISRA Rule 16.3 */
        if ((pCfgCounter->DemDebounceCounterFailedThreshold
             - ((sint16)pCfgCounter->DemDebounceCounterIncrementStepSize))
            <= (sint16)pCounter->InternalDebounceCounter)
        {
            pCounter->InternalDebounceCounter = pCfgCounter->DemDebounceCounterFailedThreshold;
        }
        else
        {
            pCounter->InternalDebounceCounter += (sint16)pCfgCounter->DemDebounceCounterIncrementStepSize;
        }
        break;
    default: /* Failed do nothing */
        break;
    }
}

/*************************************************************************/
/*
 * Brief               Dem_DebounceProcessCounter
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEventBuffer && pEventCfg
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Dem_EventStatusType
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
static FUNC(Dem_EventStatusType, DEM_CODE) Dem_DebounceProcessCounter(
    CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer,
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    P2CONST(Dem_DebounceCounterBasedClassType, AUTOMATIC, DEM_CONST)
    pCfgCounter = &DemPbCfgPtr->DemDebounceCounterBasedClass
                       [DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(pEventBuffer->ExtId)].AlgorithmRef];
    P2VAR(Dem_DebounceCounterInfoType, AUTOMATIC, DEM_VAR) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    pCounter = &DemDebounceCounterInfo[pEventCfg->AlgorithmIndex];
    Dem_EventStatusType Status = pEventBuffer->Status;

    switch (Status)
    {
    case DEM_EVENT_STATUS_PASSED: /*SWS_Dem_00421*/
        pCounter->InternalDebounceCounter = pCfgCounter->DemDebounceCounterPassedThreshold;
        break;
    case DEM_EVENT_STATUS_FAILED: /*SWS_Dem_00420] */
        pCounter->InternalDebounceCounter = pCfgCounter->DemDebounceCounterFailedThreshold;
        break;
    case DEM_EVENT_STATUS_PREPASSED: {
        Dem_DebouceProcessPrePassedCounter(pCfgCounter, pCounter);
    }
    break;
    default: /* DEM_EVENT_STATUS_PREFAILED */
    {
        Dem_DebouceProcessPreFailedCounter(pCfgCounter, pCounter);
    }
    break;
    }

    if (pCounter->InternalDebounceCounter >= pCfgCounter->DemDebounceCounterFailedThreshold)
    {
        pCounter->InternalDebounceCounter = pCfgCounter->DemDebounceCounterFailedThreshold;
        pCounter->CurStatus = DEM_EVENT_STATUS_FAILED;
        Status = DEM_EVENT_STATUS_FAILED;
    }
    else if (pCounter->InternalDebounceCounter <= pCfgCounter->DemDebounceCounterPassedThreshold)
    {
        pCounter->InternalDebounceCounter = pCfgCounter->DemDebounceCounterPassedThreshold;
        pCounter->CurStatus = DEM_EVENT_STATUS_PASSED;
        Status = DEM_EVENT_STATUS_PASSED;
    }
    else
    {
        pCounter->CurStatus = Status;
    }

    return Status;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
/*************************************************************************/
/*
 * Brief               Dem_DebounceProcessTimer
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEventBuffer && pEventCfg
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Dem_EventStatusType
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
static FUNC(Dem_EventStatusType, DEM_CODE) Dem_DebounceProcessTimer(
    CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer,
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Dem_EventStatusType Status = pEventBuffer->Status;
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_DebounceTimeInfoType, AUTOMATIC, DEM_VAR) pTimer = &DemDebounceTimerInfo[pEventCfg->AlgorithmIndex];
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    P2CONST(Dem_DebounceTimeBaseClassType, AUTOMATIC, DEM_CONST)
    pTimerCfg = &DemPbCfgPtr->DemDebounceTimeBaseClass
                     [DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(pEventBuffer->ExtId)].AlgorithmRef];

    uint8 chkmask = DEM_EVENT_STATUS_ENABLED_CONDICTION | DEM_EVENT_STATUS_DTC_SETTING;
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

    pEvent = Dem_GetEventInfo(Dem_GetEventInternalId(pEventBuffer->ExtId));
    if (pTimer->IsFreezing != FALSE)
    {
        /*SWS_Dem_00656*/
        if (chkmask == DEM_FLAGS_ISSET(pEvent->Status, chkmask))
        {
            pTimer->IsFreezing = FALSE;
        }
    }
    switch (Status)
    {
    case DEM_EVENT_STATUS_PASSED:
        pTimer->CurStatus = DEM_EVENT_STATUS_PASSED; /*SWS_Dem_00435*/
        pTimer->Timeout = pTimerCfg->DemDebounceTimePassedThreshold;
        break;
    case DEM_EVENT_STATUS_FAILED:
        pTimer->CurStatus = DEM_EVENT_STATUS_FAILED; /*SWS_Dem_00431*/
        pTimer->Timeout = pTimerCfg->DemDebounceTimeFailedThreshold;
        break;
    case DEM_EVENT_STATUS_PREPASSED: /*SWS_Dem_00432*/
        if ((pTimer->CurStatus == DEM_EVENT_STATUS_FAILED) || (pTimer->CurStatus == DEM_EVENT_STATUS_PREFAILED)
            || (pTimer->CurStatus == DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED)
            || (pTimer->Triggered == FALSE)) /*SWS_Dem_00433*/
        {
            pTimer->CurStatus = DEM_EVENT_STATUS_PREPASSED;
            pTimer->Triggered = TRUE;
            pTimer->Timeout = 0;
        }
        break;
    case DEM_EVENT_STATUS_FDC_THRESHOLD_REACHED:
        break;
    case DEM_EVENT_STATUS_PREFAILED:         /* Prefailed */
        if ((pTimer->CurStatus == DEM_EVENT_STATUS_PASSED) || (pTimer->CurStatus == DEM_EVENT_STATUS_PREPASSED)
            || (pTimer->Triggered == FALSE)) /*SWS_Dem_00429*/
        {
            pTimer->CurStatus = DEM_EVENT_STATUS_PREFAILED;
            pTimer->Triggered = TRUE;
            pTimer->Timeout = 0;
        }
        break;
    default:
        /*idle*/
        break;
    }
    Dem_MemCopy(&(pTimer->Dem_EventBuffer), pEventBuffer, sizeof(Dem_EventDataBufferType));
    return Status;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif

/*************************************************************************/
/*
 * Brief               Dem_UpdateFDC
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Dem_EventStatusType
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_UpdateFDC(Dem_EventIdType IntId)
{
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg = &DemPbCfgPtr->DemEventParameter[IntId];
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
    P2VAR(Dem_DebounceCounterInfoType, AUTOMATIC, DEM_VAR) pCounter; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(Dem_DebounceCounterBasedClassType, AUTOMATIC, DEM_CONST) pCfgCounter;
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    P2VAR(Dem_DebounceTimeInfoType, AUTOMATIC, DEM_VAR) pTimer; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(Dem_DebounceTimeBaseClassType, AUTOMATIC, DEM_CONST) pTimerCfg;
#endif
    sint8 FDC = 0;

    switch (pEventCfg->AlgorithmType)
    {
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
    case DEM_DEBOUNCE_COUNTER_BASED:

        if (((DemPbCfgPtr->DemEventParameter[IntId].AlgorithmRef) < DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM)
            && ((pEventCfg->AlgorithmIndex) < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM))
        {
            pCfgCounter =
                &DemPbCfgPtr->DemDebounceCounterBasedClass[DemPbCfgPtr->DemEventParameter[IntId].AlgorithmRef];
            pCounter = &DemDebounceCounterInfo[pEventCfg->AlgorithmIndex];
            if (pCounter->InternalDebounceCounter == 0)
            {
                FDC = 0;
            }
            else if (pCounter->InternalDebounceCounter > 0)
            {
                FDC =
                    (sint8)((pCounter->InternalDebounceCounter * 127) / pCfgCounter->DemDebounceCounterFailedThreshold);
            }
            else
            {
                FDC = (sint8)((pCounter->InternalDebounceCounter * ((sint8)(-128)))
                              / pCfgCounter->DemDebounceCounterPassedThreshold);
            }
        }
        break;
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    case DEM_DEBOUNCE_TIME_BASE:
        if (((DemPbCfgPtr->DemEventParameter[IntId].AlgorithmRef) < DEM_DEBOUNCE_TIME_BASE_CLASS_NUM)
            && ((pEventCfg->AlgorithmIndex) < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM))
        {
            pTimer = &DemDebounceTimerInfo[pEventCfg->AlgorithmIndex];
            pTimerCfg = &DemPbCfgPtr->DemDebounceTimeBaseClass[DemPbCfgPtr->DemEventParameter[IntId].AlgorithmRef];
            switch (pTimer->CurStatus)
            {
            case DEM_EVENT_STATUS_PASSED:
                FDC = -128;
                break;
            case DEM_EVENT_STATUS_FAILED:
                FDC = 127;
                break;
            case DEM_EVENT_STATUS_PREFAILED:
                FDC = (sint8)((pTimer->Timeout * 127UL) /* PRQA S 4394 */ /* MISRA Rule 10.8 */
                              / (uint64)pTimerCfg->DemDebounceTimeFailedThreshold);
                break;
            default:
                FDC = ((sint8)(-1))
                      * ((sint8)((pTimer->Timeout * 128UL) /* PRQA S 4394 */ /* MISRA Rule 10.8 */
                                 / (uint64)pTimerCfg->DemDebounceTimePassedThreshold));
                break;
            }
        }
        break;
#endif
    default:
        /*idle*/
        break;
    }

    if (pEventCfg->DemDTCRef != DEM_DTC_REF_INVALID)
    {
        if (FDC > 0) /* SWS_Dem_00795 */
        {
            if ((uint8)FDC > FDCInfo[pEventCfg->DemDTCRef].MaxFDCSinceLastClear)
            {
                FDCInfo[pEventCfg->DemDTCRef].MaxFDCSinceLastClear = (uint8)FDC;
            }
            if ((uint8)FDC > FDCInfo[pEventCfg->DemDTCRef].MaxFDCDuringCurrentCycle)
            {
                FDCInfo[pEventCfg->DemDTCRef].MaxFDCDuringCurrentCycle = (uint8)FDC;
            }
        }
        FDCInfo[pEventCfg->DemDTCRef].FDC = FDC;
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/
