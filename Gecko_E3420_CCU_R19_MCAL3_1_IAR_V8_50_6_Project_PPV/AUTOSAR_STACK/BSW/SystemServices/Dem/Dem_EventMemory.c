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
**  FILENAME    : Dem_EventMemory.c                                           **
**                                                                            **
**  Created on  :                                                             **
**  Author      : tao.yu                                                      **
**  Vendor      : i-soft                                                      **
**  DESCRIPTION : DEM EventMemory API definitions                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem_Internal.h"
#include "Dem_Dcm.h"
#if (DEM_NVRAM_BLOCKID_NUM > 0)
#include "NvM.h"
#include "NvM_Types.h"
#endif
#if (STD_ON == DEM_TRIGGER_FIM_REPORTS)
#include "FiM.h"
#endif
#if (STD_ON == DEM_J1939_SUPPORT)
#include "J1939Dcm_Cbk.h"
#endif

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
uint8 AgedFlag;
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(Dem_MemDestInfoType, AUTOMATIC) DemMemDestInfo[DEM_MEM_DEST_TOTAL_NUM];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(Dem_EventRelateInformationType, AUTOMATIC) DemEventRelateInformation[DEM_EVENT_PARAMETER_NUM];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(Dem_DTCGeneralStatusType, AUTOMATIC) DemDTCGeneralStatus[DEM_DTC_NUM];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#if (DEM_INDICATOR_NUM > 0)
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(Dem_IndicatorStatusType, AUTOMATIC) DemWIRStatus[DEM_INDICATOR_NUM];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
#endif

#define DEM_START_SEC_VAR_POWER_ON_INIT_8
#include "Dem_MemMap.h"
VAR(uint8, AUTOMATIC) DemAgingCycle = DEM_OPERATION_CYCLE_INVALID;
#define DEM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "Dem_MemMap.h"

#if (DEM_COMPONENT_NUM > 0)
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(DemComponentStatusType, AUTOMATIC) DemComponentStatus[DEM_COMPONENT_NUM];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
#endif

#if (DEM_NVRAM_BLOCKID_NUM > 0)
#if (DEM_NVRAM_DIVADED == STD_OFF)
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
static VAR(Dem_EventMemEntryType, AUTOMATIC) DemEventMemoryEntryStorage[ENTRY_STORAGE_NUM];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
#endif /* DEM_NVRAM_DIVADED == STD_OFF */

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(boolean, AUTOMATIC) DemAgingStorageTrigger;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
static VAR(Dem_EventRelateInformationStorageType, AUTOMATIC) DemEventRelateInformationStorage;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
static VAR(DemOBDDataStorageType, AUTOMATIC) DemOBDDataStorage;
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
#endif
#endif
/*******************************************************************************
**                      Private Function Definitions                         **
*******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(uint8, DEM_CODE) Dem_GetEventPriority(Dem_EventIdType IntId);
#if (DEM_COMPONENT_NUM > 0)
static FUNC(void, DEM_CODE) Dem_EventTestFailedProcessOfComponent(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg);
#endif
static FUNC(Dem_ReturnCheckEntryIsStoredType, DEM_CODE) Dem_CheckEntryAlreadyAllocated(
    Dem_EventIdType IntId,
    uint8 memDest,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) * pEntry,
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) Entry);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
static FUNC(void, DEM_CODE) Dem_EntryChronologicalOrderUpdate(
    Dem_EventIdType IntId,
    uint8 memDest,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_EVENT_DISPLACEMENT_STRATEGY != DEM_DISPLACEMENT_NONE)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_DeleteDisplacementEntry(
    /* PRQA S 3432++ */                                                                   /* MISRA Rule 20.7 */
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pResEntry,
    /* PRQA S 3432-- */                                                                   /* MISRA Rule 20.7 */
    VAR(uint8, DEM_VAR) memDest);
static FUNC(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR), DEM_CODE) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    Dem_EventDisplacementProcess(Dem_EventIdType InternalId, uint8 memDest);
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
static FUNC(void, DEM_CODE) Dem_ClearUdsStatusOfPDTC(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

static FUNC(void, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_EventAgingProcess(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent, uint8 OpId);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
static FUNC(void, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_EventHealingProcess(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent, uint8 OpId);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
#if ((DEM_INDICATOR_NUM > 0) && (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0))
static FUNC(boolean, DEM_CODE) Dem_CheckWIROn(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg);
static FUNC(boolean, DEM_CODE) Dem_CheckWIROff(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg);
#endif
static FUNC(void, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_OperationCycleCounterProcess(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
static FUNC(void, DEM_CODE) Dem_EventStatusProcessByDTC(
    uint16 dtcIndex,
    uint16 iloop,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
/* PRQA S 3432++ */     /* MISRA Rule 20.7 */
static void Dem_ClearEventRelateInformation(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
#if ((DEM_NVRAM_DIVADED == STD_ON) && (DEM_NVRAM_BLOCKID_NUM > 0))
static FUNC(void, DEM_CODE) Dem_IntWriteOneNvRAM(uint16 IntId);
#endif

#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*************************************************************************/
/*
 * Brief               Dem_EventMemInit
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
FUNC(void, DEM_CODE) Dem_EventMemInit(Std_ReturnType NvmResult) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint16 iloop = 0;
    uint16 index;
    uint16 dtcIndex;
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent = DemEventRelateInformation;
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg = DemPbCfgPtr->DemEventParameter;
    uint16 dtcRef;
    uint8 CbUdsStatus;
    while (iloop < DEM_MEM_DEST_TOTAL_NUM)
    {
        DemMemDestInfo[iloop].OverFlow = FALSE;
        if (E_NOT_OK == NvmResult)
        {
            DemMemDestInfo[iloop].RecordNum = 0;
        }
        Dem_MemSet(DemMemDestInfo[iloop].DisableDTCRecordUpdate, 0x00u, DEM_DTC_NUM_BYTE);
        iloop++;
    }
#if (DEM_INDICATOR_NUM > 0)
    Dem_MemSet(DemWIRStatus, DEM_INDICATOR_OFF, DEM_INDICATOR_NUM);
#endif
    iloop = 0;
    while (iloop < DEM_EVENT_PARAMETER_NUM)
    {
        pEvent->IntId = iloop;

#if (DEM_STATUS_BIT_STORAGE_TEST_FAILED == STD_OFF)
        /*SWS_Dem_00525] */
        DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_TF); /* clear bit0 */
#else
        if (0x00u != DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TF))
        {
            DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_ACTIVE);
        }
        else
        {
            DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_ACTIVE);
        }
#endif

        if ((E_NOT_OK == NvmResult) || (pEvent->Status == 0x00u))
        {
            DEM_FLAGS_SET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCTOC); /* set bit 6 */
        }

        pEvent->OldUdsStatus = pEvent->UdsStatus;
        dtcIndex = DemPbCfgPtr->DemEventParameter[iloop].DemDTCRef;

        Dem_EventStatusProcessByDTC(dtcIndex, iloop, pEvent);

#if (DEM_ENABLE_CONDITION_NUM > 0)
        if (pEventCfg->DemEnableConditionGroupRef != DEM_ENABLE_CONDITION_GROUP_INVALID)
        {
            if (Dem_CheckCondictionFulfilled(
                    DemEnableConditionStatus,
                    &DemEnableConditionGroup[DemPbCfgPtr->DemEventParameter[iloop].DemEnableConditionGroupRef][0],
                    DEM_ENABLE_CONDITION_NUM_BYTE)
                == TRUE)
            {
                DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_ENABLED_CONDICTION);
            }
        }
        else
#endif
        {
            DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_ENABLED_CONDICTION);
        }
#if (DEM_STORAGE_CONDITION_NUM > 0)
        if (pEventCfg->DemStorageConditionGroupRef != DEM_STORAGE_CONDITION_GROUP_INVALID)
        {
            if (Dem_CheckCondictionFulfilled(
                    DemStorageConditionStatus,
                    &DemStorageConditionGroup[DemPbCfgPtr->DemEventParameter[iloop].DemStorageConditionGroupRef][0],
                    DEM_STORAGE_CONDITION_NUM_BYTE)
                == TRUE)
            {
                DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_STORAGE_CONDICTION);
            }
        }
        else
#endif
        {
            DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_STORAGE_CONDICTION);
        }
        DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_DTC_SETTING);

        index = 0;
        dtcRef = DemPbCfgPtr->DemEventParameter[iloop].DemDTCRef;
        if (DEM_DTC_REF_INVALID != dtcRef)
        {
            DemDTCGeneralStatus[dtcRef].CbUdsStatus = 0;
            while (index < DEM_EVENT_PARAMETER_NUM)
            {
                if (DemPbCfgPtr->DemEventParameter[index].DemDTCRef == dtcRef)
                {
                    DemDTCGeneralStatus[dtcRef].CbUdsStatus |=
                        DemEventRelateInformation[index].UdsStatus; /*bit0 - bit7 or-operation */
                }
                index++;
            }
            CbUdsStatus =
                ~((DemDTCGeneralStatus[dtcRef].CbUdsStatus & DEM_UDS_STATUS_TFSLC) >> 1u); /* bit4 calculation */
            DemDTCGeneralStatus[dtcRef].CbUdsStatus &= CbUdsStatus;
            CbUdsStatus = (uint8)(~((uint8)((DemDTCGeneralStatus[dtcRef].CbUdsStatus & DEM_UDS_STATUS_TFTOC)
                                            << 5u))); /* bit6 calculation */
            DemDTCGeneralStatus[dtcRef].CbUdsStatus &= CbUdsStatus;
        }

        if (E_NOT_OK == NvmResult)
        {
            Dem_ClearEventRelateInformation(pEvent);
        }

        DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_CONSECUTIVE_FAULT);
        DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_FDC_TRIGGERED);
        DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_TFBITCHANGE);
        pEvent++;
        pEventCfg++;
        iloop++;
    }
#if (DEM_COMPONENT_NUM > 0)
    iloop = 0;
    while (iloop < DEM_COMPONENT_NUM) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
    {
        DemComponentStatus[iloop].FailurePriority = 0xFF;
        DemComponentStatus[iloop].Status = FALSE;
        DemComponentStatus[iloop].availability = TRUE;
        iloop++;
    }
#endif
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_CheckEventMemEntryExistsAlready
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Dem_EventMemEntryType*
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR), DEM_CODE) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
Dem_CheckEventMemEntryExistsAlready(Dem_EventIdType IntId)
{
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pMemDest;
    uint16 iloop = 0;
    uint16 TempRef = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

    if (TempRef == DEM_DTC_REF_INVALID)
    {
        return NULL_PTR;
    }
    pMemDest = DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[TempRef].DemDTCAttributesRef].DemMemoryDestinationRef;
    while (iloop < DEM_MEM_DEST_MAX_NUM_OF_DTC) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
    {
        if (pMemDest[iloop] != DEM_MEM_DEST_INVALID)
        {
            pEntry = Dem_MemEntryGet(Dem_GetEventExternalId(IntId), pMemDest[iloop]);
            if (NULL_PTR != pEntry)
            {
                return pEntry;
            }
        }
        iloop++;
    }
    return NULL_PTR;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_GetEventInfo
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Dem_EventRelateInformationType*
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR), DEM_CODE) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
Dem_GetEventInfo(Dem_EventIdType IntId)
{
    return &DemEventRelateInformation[IntId];
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_EventTestFailed
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && pEventBuffer
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
FUNC(void, DEM_CODE)
Dem_EventTestFailed(Dem_EventIdType IntId, CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg = &DemPbCfgPtr->DemEventParameter[IntId];
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent = &DemEventRelateInformation[IntId];
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint8 index;
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pMemDest;
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) Entry; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint16 iloop;
    uint16 DTCRef;

#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
    uint16 eventIndex = 0;
#endif
    boolean Find = FALSE;

#if (DEM_COMPONENT_NUM > 0)
    Dem_EventTestFailedProcessOfComponent(pEvent, pEventCfg);
#endif

#if (DEM_TRIGGER_ON_TEST_FAILED == DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER)
    Dem_EventRetention(IntId, pEventBuffer); /*SWS_Dem_00783 SWS_Dem_00800 SWS_Dem_00812*/
#else
    Dem_EventDataStorageTrigger(IntId, pEventBuffer, DEM_TRIGGER_ON_TEST_FAILED);
#endif
#if (DEM_OCCURRENCE_COUNTER_PROCESSING == DEM_PROCESS_OCCCTR_TF)
    index = 0u;
    DTCRef = DemPbCfgPtr->DemEventParameter[pEvent->IntId].DemDTCRef;
    /* PRQA S 2877++ */ /* MISRA Dir 4.1 */
    while ((index < DEM_MEM_DEST_MAX_NUM_OF_DTC) && (DEM_DTC_REF_INVALID != DTCRef))
    /* PRQA S 2877-- */ /* MISRA Dir 4.1 */
    {
        uint16 DemDTCAttributesRef = DemPbCfgPtr->DemDTC[DTCRef].DemDTCAttributesRef;
        pMemDest = DemPbCfgPtr->DemDTCAttributes[DemDTCAttributesRef].DemMemoryDestinationRef;
        if (pMemDest[index] != DEM_MEM_DEST_INVALID)
        {
            Entry = DemMemDestCfg[pMemDest[index]].EntryList;
            iloop = 0;
            while ((iloop < DemMemDestCfg[pMemDest[index]].EntryNum)
                   && (Find == FALSE)) /*check if event is already stored*/
            {
                if (Entry->EventId == Dem_GetEventExternalId(IntId))
                {
                    Find = TRUE;
                }
                Entry++;
                iloop++;
            }
        }
        index++;
    }
    /*SWS_Dem_00524 SWS_Dem_00625 */
    if ((pEvent->OccurrenceCounter < 0xFFu) && (Find == TRUE)
        && ((DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TF) != 0u)
            && (DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_TFBITCHANGE) != 0u)))
    {
        pEvent->OccurrenceCounter++;
    }
#endif

    /* if event failed clear anging counter*/
    pEvent->AgingCounter = 0;

    if (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_PDTC)) /* Check PendingDTC bit */
    {
        /* req SWS_Dem_00784 SWS_Dem_00801 SWS_Dem_00813*/
        DEM_FLAGS_SET(pEvent->UdsStatus, DEM_UDS_STATUS_PDTC); /* bit 2*/
#if (DEM_TRIGGER_ON_PENDING == DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER)
        Dem_EventRetention(IntId, pEventBuffer);
#else
        Dem_EventDataStorageTrigger(IntId, pEventBuffer, DEM_TRIGGER_ON_PENDING);
#endif
    }
#if (DEM_TRIGGER_ON_PENDING == DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER)
    else
    {
        /* req SWS_Dem_00922 */
        if (DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_TFBITCHANGE) != 0x00u)
        {
            Dem_EventDataStorageTrigger(IntId, pEventBuffer, DEM_TRIGGER_ON_PENDING);
        }
    }
#endif

    /* confirmedLevel reached? */
    if (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_CDTC))
    {
        if ((pEvent->FailureCounter + 1u) >= pEventCfg->DemEventFailureCycleCounterThreshold) /* SWS_Dem_00528 */
        {
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
            Find = FALSE;
            while ((eventIndex < DEM_EVENT_PARAMETER_NUM) && (Find == FALSE))
            {
                DTCRef = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;
                if ((DTCRef != DEM_DTC_REF_INVALID) && (DTCRef == DemPbCfgPtr->DemEventParameter[eventIndex].DemDTCRef)
                    && (DEM_FLAGS_ISSET(DemEventRelateInformation[eventIndex].UdsStatus, DEM_UDS_STATUS_CDTC) != 0x00u))
                {
                    Find = TRUE;
                }
                eventIndex++;
            }
            if (Find == FALSE)
#endif
            {
                DTCRef = DemPbCfgPtr->DemEventParameter[pEvent->IntId].DemDTCRef;
                index = 0u;
                /* PRQA S 2877++ */ /* MISRA Dir 4.1 */
                while ((index < DEM_MEM_DEST_MAX_NUM_OF_DTC) && (DTCRef != DEM_DTC_REF_INVALID))
                /* PRQA S 2877-- */ /* MISRA Dir 4.1 */
                {
                    uint16 DemDTCAttributesRef = DemPbCfgPtr->DemDTC[DTCRef].DemDTCAttributesRef;
                    pMemDest = DemPbCfgPtr->DemDTCAttributes[DemDTCAttributesRef].DemMemoryDestinationRef;
                    if (DemMemDestCfg[pMemDest[index]].ExtId == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
                    {
                        Dem_SetOccurrenceEvent(IntId, DEM_UDS_STATUS_CDTC); /* SWS_Dem_00219 */
                    }
                    index++;
                }
                if ((0x00u == DEM_BITS_ISSET(DemOperationCycleStatus, pEventCfg->DemOperationCycleRef))
                    && (DemOperationCycle[pEventCfg->DemOperationCycleRef].DemOperationCycleType
                        == DEM_OPCYC_OBD_DCY)) /*SWS_Dem_00700*/
                {
                    /*idle*/
                }
                else
                {
                    DEM_FLAGS_SET(pEvent->UdsStatus, DEM_UDS_STATUS_CDTC); /* bit 3 */
                    /*  The counter may also be cleared when the conﬁrmedDTCLimit is reached. */
                    pEvent->OCC6 = 0;
                }
                /* req SWS_Dem_00785 SWS_Dem_00802 SWS_Dem_00814*/
#if (DEM_TRIGGER_ON_CONFIRMED == DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER)
                Dem_EventRetention(IntId, pEventBuffer);
#else
                Dem_EventDataStorageTrigger(IntId, pEventBuffer, DEM_TRIGGER_ON_CONFIRMED);
#endif
            }
        }
    }
    else
    {
#if (                                                                    \
    (DEM_TRIGGER_ON_CONFIRMED == DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER) \
    && (DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_OFF))
        /* req SWS_Dem_00923 */
        if (DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_TFBITCHANGE) != 0x00u)
        {
            Dem_EventRetention(IntId, pEventBuffer);
        }
#endif
    }
#if (DEM_OCCURRENCE_COUNTER_PROCESSING == DEM_PROCESS_OCCCTR_CDTC)
    index = 0u;
    DTCRef = DemPbCfgPtr->DemEventParameter[pEvent->IntId].DemDTCRef;
    while ((index < DEM_MEM_DEST_MAX_NUM_OF_DTC) && (DTCRef != DEM_DTC_REF_INVALID))
    {
        uint16 DemDTCAttributesRef = DemPbCfgPtr->DemDTC[DTCRef].DemDTCAttributesRef;
        pMemDest = DemPbCfgPtr->DemDTCAttributes[DemDTCAttributesRef].DemMemoryDestinationRef;
        if (pMemDest[index] != DEM_MEM_DEST_INVALID)
        {
            Entry = DemMemDestCfg[pMemDest[index]].EntryList;
            iloop = 0;
            while ((iloop < DemMemDestCfg[pMemDest[index]].EntryNum)
                   && (Find == FALSE)) /*check if event is already stored*/
            {
                if (Entry->EventId == Dem_GetEventExternalId(IntId))
                {
                    Find = TRUE;
                }
                Entry++;
                iloop++;
            }
        }
        index++;
    }
    /*SWS_Dem_00580 SWS_Dem_00625 */
    if ((pEvent->OccurrenceCounter < 0xFFu) && (Find == TRUE)
        && ((DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TF) != 0)
            && (DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_TFBITCHANGE) != 0))
        && (DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_CDTC) != 0))
    {
        Find = FALSE;
        pEvent->OccurrenceCounter++; /*  occurrence counter counter by one ,trigger by TF bit transition
                                        from 0 to 1 if CDTC is set */
    }
#endif

#if ((DEM_INDICATOR_NUM > 0) && (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0))
    /* Check WarningIndicatorOnCondition */
    if (TRUE == Dem_CheckWIROn(pEvent, pEventCfg))
    {
        DEM_FLAGS_SET(pEvent->UdsStatus, DEM_UDS_STATUS_WIR); /* bit 7 */
    }
#endif
#if (DEM_NVRAM_BLOCKID_NUM > 0)
    DTCRef = DemPbCfgPtr->DemEventParameter[pEvent->IntId].DemDTCRef;
    if ((DTCRef != DEM_DTC_REF_INVALID)
        && (DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[DTCRef].DemDTCAttributesRef].DemImmediateNvStorage
            == TRUE)
        && (DemEventRelateInformation[IntId].OccurrenceCounter < DEM_IMMEDIATE_NV_STORAGE_LIMIT))
    {
#if (DEM_NVRAM_DIVADED == STD_ON)
        Dem_IntWriteOneNvRAM(IntId);
#else
        Dem_IntWriteNvRAM();
#endif
    }
#endif
    if (DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_TFBITCHANGE) != 0x00u)
    {
        DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_TFBITCHANGE);
    }

    Dem_UpdateCombinedDtcStatus(IntId); /* update the combination event dtc status*/
    Dem_ResponseOnDtcStatusChange(IntId);
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_UpdateCombinedDtcStatus
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_UpdateCombinedDtcStatus(Dem_EventIdType IntId)
{
    uint16 iloop = 0;
    uint16 dtcRef = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;
    uint8 CbUdsStatus;

    if (dtcRef == DEM_DTC_REF_INVALID)
    {
        return;
    }
    DemDTCGeneralStatus[dtcRef].CbUdsStatus = 0;
    /* SWS_Dem_00441*/
    while (iloop < DEM_EVENT_PARAMETER_NUM)
    {
        if (DemPbCfgPtr->DemEventParameter[iloop].DemDTCRef == dtcRef)
        {
            DemDTCGeneralStatus[dtcRef].CbUdsStatus |=
                DemEventRelateInformation[iloop].UdsStatus; /*bit0 - bit7 or-operation */
        }
        iloop++;
    }
    CbUdsStatus = ~((DemDTCGeneralStatus[dtcRef].CbUdsStatus & DEM_UDS_STATUS_TFSLC) >> 1u); /* bit4 calculation */
    DemDTCGeneralStatus[dtcRef].CbUdsStatus &= CbUdsStatus;
    CbUdsStatus = (uint8)(~(uint8)((DemDTCGeneralStatus[dtcRef].CbUdsStatus & DEM_UDS_STATUS_TFTOC)
                                   << 5u)); /* bit6 calculation */
    DemDTCGeneralStatus[dtcRef].CbUdsStatus &= CbUdsStatus;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_ResponseOnDtcStatusChange
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_ResponseOnDtcStatusChange(Dem_EventIdType IntId)
{
    uint16 dtcRef = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;
#if (DEM_J1939_NODE_NUM > 0)
    uint8 iloop = 0;
    P2CONST(uint8, AUTOMATIC, DEM_VAR) Nodeindex;
    uint8 NodeNum;
#endif
    if (dtcRef == DEM_DTC_REF_INVALID)
    {
        return;
    }

    if (DemEventRelateInformation[IntId].OldUdsStatus != DemEventRelateInformation[IntId].UdsStatus)
    {
        Dem_TriggerOnEventStatus(
            IntId,
            DemEventRelateInformation[IntId].OldUdsStatus,
            DemEventRelateInformation[IntId].UdsStatus); /*SWS_Dem_01050*/

#if (DEM_J1939_NODE_NUM > 0)
        if ((DemPbCfgPtr->DemDTC[dtcRef].DemObdDTCRef != DEM_OBD_DTC_INVALID)
            && (DEM_J1939_DTC_CFG_INVALID
                != DemPbCfgPtr->DemObdDTC[DemPbCfgPtr->DemDTC[dtcRef].DemObdDTCRef].DemJ1939DTCValue)
            && ((DemEventRelateInformation[IntId].OldUdsStatus & DEM_UDS_STATUS_TF)
                != (DemDTCGeneralStatus[dtcRef].CbUdsStatus & DEM_UDS_STATUS_TF)))
        {
            Nodeindex = DemPbCfgPtr
                            ->J1939Node[DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[dtcRef].DemDTCAttributesRef]
                                            .DemJ1939DTC_J1939NodeRef]
                            .NodeIDRef;
            NodeNum = DemPbCfgPtr
                          ->J1939Node[DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[dtcRef].DemDTCAttributesRef]
                                          .DemJ1939DTC_J1939NodeRef]
                          .NodeNum;
            while (iloop < NodeNum)
            {
                J1939Dcm_DemTriggerOnDTCStatus(
                    DemPbCfgPtr->DemObdDTC[DemPbCfgPtr->DemDTC[dtcRef].DemObdDTCRef].DemJ1939DTCValue,
                    *Nodeindex); /*SWS_Dem_00971*/
                iloop++;
                Nodeindex++;
            }
        }
#endif
        DemEventRelateInformation[IntId].OldUdsStatus = DemEventRelateInformation[IntId].UdsStatus;
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*************************************************************************/
/*
 * Brief               Dem_EventTestPassed
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && pEventBuffer
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
FUNC(void, DEM_CODE)
Dem_EventTestPassed(Dem_EventIdType IntId, CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent = &DemEventRelateInformation[IntId];
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint16 TempRef = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;
    P2CONST(Dem_DTCAttributesType, AUTOMATIC, DEM_CONST) pDTCAttrCfg;

#if ((DEM_INDICATOR_NUM > 0) && (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0))
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg = &DemPbCfgPtr->DemEventParameter[IntId];
    P2CONST(Dem_IndicatorAttributeType, AUTOMATIC, DEM_CONST) pWIRAttr;
    boolean allThreshold = FALSE;
    uint16 kloop;
#endif

#if (DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_OFF)
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pMemDest;
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry = NULL_PTR;
    uint8 MinAbsTimeInMemory = 0xf;
    uint8 iloop;
    uint8 jloop;
#endif

#if (DEM_COMPONENT_NUM > 0)
    uint16 ComponentID;
    boolean allParentComponentpass = TRUE;

    ComponentID = pEventCfg->DemComponentClassRef; /* PRQA S 2812 */ /* MISRA Dir 4.1 */
    if (ComponentID != DEM_COMPONENT_INVALID)                        /*check whether event ref the component*/
    {
        if (DemComponentStatus[ComponentID].availability == TRUE)    /*check the component availability*/
        {
            DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_CONSECUTIVE_FAULT);
            if (DemPbCfgPtr->DemComponent[ComponentID].DemParentComponentRef != DEM_COMPONENT_INVALID)
            {
                while ((DemPbCfgPtr->DemComponent[ComponentID].DemParentComponentRef != DEM_COMPONENT_INVALID)
                       && (allParentComponentpass == TRUE))
                {
                    if (DemComponentStatus[DemPbCfgPtr->DemComponent[ComponentID].DemParentComponentRef].Status == TRUE)
                    {
                        allParentComponentpass = FALSE;
                    }
                    ComponentID =
                        DemPbCfgPtr->DemComponent[ComponentID].DemParentComponentRef; /* next parent component*/
                }
            }
            if (allParentComponentpass == TRUE)
            {
                ComponentID = pEventCfg->DemComponentClassRef;
                /*SWS_Dem_01125*/
                DemComponentStatus[ComponentID].Status = FALSE;
                DemComponentStatus[ComponentID].FailurePriority = 0xFF;
#if (STD_ON == DEM_TRIGGER_FIM_REPORTS)
                (void)FiM_DemTriggerOnComponentStatus(ComponentID + 1u, FALSE);
#endif
            }
        }
    }
#endif

    DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_TF | DEM_UDS_STATUS_TNCTOC | DEM_UDS_STATUS_TNCSLC); /* bit 0 6 4*/
    DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_ACTIVE);
    pEvent->OCC6 = 0;

#if ((DEM_INDICATOR_NUM > 0) && (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0))
    for (kloop = 0; kloop < pEventCfg->AttrNum; kloop++)
    {
        pWIRAttr = &DemIndicatorAttribute[pEventCfg->AttrStartIndex + kloop];
        if (0x00u != pWIRAttr->DemIndicatorHealingCycleCounterThreshold)
        {
            allThreshold = TRUE;
            break;
        }
    }
    if ((FALSE == allThreshold) /* R19-11: SWS_Dem_01233*/
        && (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TFTOC)) && (pEventCfg != NULL_PTR))
    {
        if ((0x00u != DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_WIR))
            && (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCTOC)))
        {
            DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_WIR);
            for (kloop = 0; kloop < pEventCfg->AttrNum; kloop++)
            {
                pWIRAttr = &DemIndicatorAttribute[pEventCfg->AttrStartIndex + kloop];
                DemWIRStatus[pWIRAttr->DemIndicatorRef] = DEM_INDICATOR_OFF;
            }
        }
    }
#endif

#if (DEM_EXTENDED_DATA_CLASS_NUM > 0)
    /*SWS_Dem_01070*/
    if (DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_TFBITCHANGE) != 0x00u)
    {
        Dem_EventDataStorageTrigger(IntId, pEventBuffer, DEM_TRIGGER_ON_PASSED);
        DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_TFBITCHANGE);
    }
#endif
    if (TempRef == DEM_DTC_REF_INVALID)
    {
        return;
    }

    /* req SWS_Dem_00698 */
    pDTCAttrCfg = &DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[TempRef].DemDTCAttributesRef];
    if ((pDTCAttrCfg->DemAgingAllowed == FALSE) && (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_CDTC)))
    {
        return;
    }
#if (DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_OFF)

    /* insert a entry that been displaced into entry memory as first entry,
     * so its absolute time is minimum of all entry.
     * And update other absolute time of other entry by increment one  */

    pMemDest = DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[TempRef].DemDTCAttributesRef].DemMemoryDestinationRef;
    iloop = 0;
    jloop = 0;
    while (iloop < DEM_MEM_DEST_MAX_NUM_OF_DTC)
    {
        if ((DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_CDTC) != 0x00)
            && (Dem_MemEntryGet(Dem_GetEventExternalId(IntId), *pMemDest) == NULL_PTR))
        { /*not stored in an event memory entry  UDS status bit 3 (ConfirmedDTC) set   gets qualified as passed*/
            pEntry = Dem_MemEntryGet(0x00, *pMemDest); /*return NULL_PTR means no idle memory*/
            if (pEntry != NULL_PTR)
            {                                          /*SWS_Dem_00823] */
                if (DemMemDestInfo[*pMemDest].RecordNum < DemMemDestCfg[*pMemDest].EntryNum)
                {
                    DemMemDestInfo[*pMemDest].RecordNum++;
                }
                pEntry->EventId = IntId;
                iloop = 0;
                while (jloop < DemMemDestCfg[*pMemDest].EntryNum)
                {
                    if (MinAbsTimeInMemory > DemMemDestCfg[*pMemDest].EntryList[iloop].AbsTime)
                    {
                        MinAbsTimeInMemory = DemMemDestCfg[*pMemDest].EntryList[iloop].AbsTime;
                    }
                    DemMemDestCfg[*pMemDest].EntryList[jloop].AbsTime += 1; /* Update absolute time of other entry */
                    jloop++;
                }
                pEntry->AbsTime = MinAbsTimeInMemory;
            }
        }
        pMemDest++;
        iloop++;
    }
#endif
    Dem_UpdateCombinedDtcStatus(IntId); /* update the combination event dtc status*/
    Dem_ResponseOnDtcStatusChange(IntId);
#if (DEM_MAX_NUMBER_PRESTORED_FF > 0)
    (void)Dem_ClearPreStoreFF(Dem_GetEventExternalId(IntId)); /*SWS_Dem_00465*/
#endif
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_EventRetention
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && pEventBuffer
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE)
/* PRQA S 1505,3432++ */ /* MISRA Rule 8.7,Rule 20.7 */
Dem_EventRetention(Dem_EventIdType IntId, CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer)
/* PRQA S 1505,3432-- */ /* MISRA Rule 8.7,Rule 20.7 */
{
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pMemDest;
    uint16 iloop = 0;
    uint16 TempRef = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

    if (TempRef == DEM_DTC_REF_INVALID)
    {
        return;
    }
    Dem_Pending = TRUE;
    pMemDest = DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[TempRef].DemDTCAttributesRef].DemMemoryDestinationRef;

    while (iloop < DEM_MEM_DEST_MAX_NUM_OF_DTC) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
    {
        if (pMemDest[iloop] != DEM_MEM_DEST_INVALID)
        {
            pEntry = Dem_MemEntryAllocate(IntId, pMemDest[iloop]); /*Check if event is already stored*/

            if ((pEntry != NULL_PTR)
                && (0x00u == DEM_BITS_ISSET(DemMemDestInfo[pMemDest[iloop]].DisableDTCRecordUpdate, TempRef)))
            {
#if ((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0))
                Dem_FreezeFrameStorage(IntId, pEntry, pEventBuffer, DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER);
#endif
#if (DEM_EXTENDED_DATA_CLASS_NUM > 0)
                Dem_ExtendedDataStorage(IntId, pEntry, pEventBuffer, DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER);
#endif
            }
        }
        iloop++;
    }
    Dem_Pending = FALSE;
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_OperationCycleStart
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      OpId && IsRestart
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_OperationCycleStart(uint8 OpId, boolean IsRestart) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg = DemPbCfgPtr->DemEventParameter;
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent = DemEventRelateInformation;
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint16 iloop = 0;
    while (iloop < DEM_EVENT_PARAMETER_NUM)
    {
        Dem_EventHealingProcess(pEvent, OpId); /*SWS_Dem_00506*/
        if (IsRestart == TRUE)
        {
            Dem_ClearUdsStatusOfPDTC(pEvent);
            Dem_EventAgingProcess(pEvent, OpId);
        }
        if (pEventCfg->DemOperationCycleRef == OpId)
        {
            /* req SWS_Dem_00679 Monitor re-initialization */
            if (pEventCfg->DemCallbackInitMForE != NULL_PTR)
            {
                pEventCfg->DemCallbackInitMForE(DEM_INIT_MONITOR_RESTART);
            }
            DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_FDC_TRIGGERED);
            pEvent->FDC_Trigger = FALSE;
            if (IsRestart == TRUE)
            {
                Dem_OperationCycleCounterProcess(pEvent); /*SWS_Dem_00773 SWS_Dem_00781 SWS_Dem_00777 */
            }
            pEvent->ThisOpIsFiled = FALSE;
            DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_TFTOC);  /* bit1 1 => 0 SWS_Dem_00389 */
            DEM_FLAGS_SET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCTOC); /* bit6 0 => 1 SWS_Dem_00394 */
                                                                     /*SWS_Dem_00344*/
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
            if ((DemPbCfgPtr->DemEventParameter[iloop].AlgorithmType == DEM_DEBOUNCE_COUNTER_BASED)
                && (DemPbCfgPtr->DemEventParameter[iloop].AlgorithmIndex < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM))
            {
                DemDebounceCounterInfo[DemPbCfgPtr->DemEventParameter[iloop].AlgorithmIndex].InternalDebounceCounter =
                    0;
                DemDebounceCounterInfo[DemPbCfgPtr->DemEventParameter[iloop].AlgorithmIndex].CurStatus =
                    DEM_EVENT_STATUS_PREPASSED;
            }
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
            if ((DemPbCfgPtr->DemEventParameter[iloop].AlgorithmType == DEM_DEBOUNCE_TIME_BASE)
                && (DemPbCfgPtr->DemEventParameter[iloop].AlgorithmIndex < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM))
            {
                DemDebounceTimerInfo[DemPbCfgPtr->DemEventParameter[iloop].AlgorithmIndex].Timeout = 0;
                DemDebounceTimerInfo[DemPbCfgPtr->DemEventParameter[iloop].AlgorithmIndex].Triggered = FALSE;
                DemDebounceTimerInfo[DemPbCfgPtr->DemEventParameter[iloop].AlgorithmIndex].CurStatus =
                    DEM_EVENT_STATUS_PREPASSED;
            }
#endif

            if (pEventCfg->DemDTCRef != DEM_DTC_REF_INVALID)
            {
                FDCInfo[pEventCfg->DemDTCRef].MaxFDCDuringCurrentCycle = 0; /*SWS_Dem_00790*/
            }
        }
        if (DemInitState != DEM_STATE_PRE_INIT) /*first init shall not update and trigger the callback*/
        {
            Dem_UpdateCombinedDtcStatus(iloop); /* update the combination event dtc status*/
            Dem_ResponseOnDtcStatusChange(iloop);
        }

        pEventCfg++;
        pEvent++;
        iloop++;
    }
    if (DemAgingCycle == OpId)
    {
        DemAgingCycle = DEM_OPERATION_CYCLE_INVALID;
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_OperationCycleEnd
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      OpId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_OperationCycleEnd(uint8 OpId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg = DemPbCfgPtr->DemEventParameter;
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent = DemEventRelateInformation;
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint16 iloop = 0;

    while (iloop < DEM_EVENT_PARAMETER_NUM)
    {
        if (pEventCfg->DemOperationCycleRef == OpId)
        {
            /* Process Operation Cycle Counters */
            Dem_OperationCycleCounterProcess(pEvent); /*SWS_Dem_00773 SWS_Dem_00781 SWS_Dem_00777 */
        }

        Dem_EventAgingProcess(pEvent, OpId);
        Dem_ClearUdsStatusOfPDTC(pEvent);
        Dem_UpdateCombinedDtcStatus(iloop);   /*update the combination event dtc status*/
        Dem_ResponseOnDtcStatusChange(iloop); /*trigger ROE invoking*/

        pEventCfg++;
        pEvent++;
        iloop++;
    }
    if (DemAgingCycle == OpId)
    {
        DemAgingCycle = DEM_OPERATION_CYCLE_INVALID;
    }
#if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) || (DEM_J1939_SUPPORT == STD_ON))
    Dem_CalOBDRelatedValue(OpId);
#endif
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_MemEntryGet
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ExtId && MemDestIndex
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Dem_EventMemEntryType*
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR), DEM_CODE) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
Dem_MemEntryGet(Dem_EventIdType ExtId, uint8 memDest)
{
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry = DemMemDestCfg[memDest].EntryList;
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint16 iloop = 0;

    while (iloop < DemMemDestCfg[memDest].EntryNum) /*primary total number such as 7 */
    {
        if (pEntry->EventId == ExtId)
        {
            return pEntry;
        }
        pEntry++;
        iloop++;
    }
    return NULL_PTR;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
**                      Private Function Definitions                         **
*******************************************************************************/
/*************************************************************************/
/*
 * Brief               Dem_MemEntryAllocate
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && MemDestIndex
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Dem_EventMemEntryType*
 */
/*************************************************************************/

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR), DEM_CODE) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
Dem_MemEntryAllocate(Dem_EventIdType IntId, uint8 memDest) /* PRQA S 1505 */       /* MISRA Rule 8.7 */
{
    uint8 iloop;
    Dem_ReturnCheckEntryIsStoredType retVal;
    uint8 MaxAbsTimeInMemory = 0u;
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry = NULL_PTR; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    /* PRQA S 3432++ */                                                                   /* MISRA Rule 20.7 */
    P2VAR(Dem_MemDestInfoType, AUTOMATIC, DEM_VAR) pMem = &DemMemDestInfo[memDest];
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent = &DemEventRelateInformation[IntId];
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) Entry = DemMemDestCfg[memDest].EntryList;
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */

    retVal = Dem_CheckEntryAlreadyAllocated(IntId, memDest, &pEntry, Entry);

    if (retVal != DEM_CHECK_STORED_OK)
    {
        return NULL_PTR;
    }
#if (DEM_COMPONENT_NUM > 0u)
    if (DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_CONSECUTIVE_FAULT) != 0x00u)
    {
        /*SWS_Dem_01130*/
        return pEntry;
    }
#endif
#if (DEM_STORAGE_CONDITION_NUM > 0u)
    if ((0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_STORAGE_CONDICTION))
        && (DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_TFBITCHANGE) != 0x00u))
    {
        /*SWS_Dem_00458 SWS_Dem_00455 SWS_Dem_00591 */
        DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_TFBITCHANGE);
        return NULL_PTR;
    }
#endif
    /*SWS_Dem_00242] Defines the group of DTC that shall be disabled to store in event memory*/
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_DTC_SETTING))
    {
        return pEntry;
    }

    /* Entry already stored */
    if (pEntry == NULL_PTR)
    {
        pEntry = Dem_MemEntryGet(0x00, memDest); /*return NULL_PTR means no idle memory*/

        if (pEntry == NULL_PTR)
        {
            pMem->OverFlow = TRUE;
#if (DEM_EVENT_DISPLACEMENT_STRATEGY != DEM_DISPLACEMENT_NONE)
            /* SWS_Dem_00401 SWS_Dem_00402 SWS_Dem_00407 */
            pEntry = Dem_EventDisplacementProcess(IntId, memDest);
#endif
        }
#if (DEM_EXTERAL_DATA_ELEMENT_CLASS_NUM > 0)
        else
        {
            if (DemPbCfgPtr->DemEventParameter[IntId].DemCallbackEventDataChanged != NULL_PTR) /*SWS_Dem_00475] */
            {
                (void)DemPbCfgPtr->DemEventParameter[IntId].DemCallbackEventDataChanged(Dem_GetEventExternalId(IntId));
            }
        }
#endif
        if (pEntry != NULL_PTR) /**/
        {
            if (pMem->RecordNum < DemMemDestCfg[memDest].EntryNum)
            {
                pMem->RecordNum++;
            }
            pEntry->EventId = Dem_GetEventExternalId(IntId);
            /*SWS_Dem_00412]search the time order,give the newer time order*/
            iloop = 0;
            while (iloop < DemMemDestCfg[memDest].EntryNum)
            {
                if (MaxAbsTimeInMemory < DemMemDestCfg[memDest].EntryList[iloop].AbsTime)
                {
                    MaxAbsTimeInMemory = DemMemDestCfg[memDest].EntryList[iloop].AbsTime;
                }
                iloop++;
            }
            pEntry->AbsTime = MaxAbsTimeInMemory + 1u;
#if ((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0))
            pEntry->FFNum = 0;
            pEntry->LatestFF = 0;
#endif
            /* req SWS_Dem_00523 */
            pEvent->OccurrenceCounter = 0;
            pEvent->CyclesSinceFirstFailed = 0; /*SWS_Dem_00776] */
            pEvent->CycleCounterFlag = TRUE;
            pEvent->CyclesSinceLastFailed = 0;  /*SWS_Dem_00771*/
            pEvent->FailureCounter = 0;         /*SWS_Dem_00780*/
        }
    }
    else
    {
        /*SWS_Dem_00787] */
        if (DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_TFBITCHANGE) != 0x00u)
        {
            pEvent->CyclesSinceLastFailed = 0; /*SWS_Dem_00772] */
            /*Update the time order*/
            Dem_EntryChronologicalOrderUpdate(IntId, memDest, pEntry);
        }
    }
    return pEntry;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_MirrorEntryAllocate
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && MemDestIndex
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Dem_EventMemEntryType*
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR), DEM_CODE) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
Dem_MirrorEntryAllocate(Dem_EventIdType IntId, uint8 memDest) /* PRQA S 1532 */    /* MISRA Rule 8.7 */
{
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry; /* PRQA S 3432 */     /* MISRA Rule 20.7 */

    pEntry = Dem_MemEntryAllocate(IntId, memDest);

    return pEntry;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_MemEntryDelete
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      memDest
 * Param-Name[out]     None
 * Param-Name[in/out]  pEntry
 * Return              None
 */
/*************************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
static void Dem_ClearEventRelateInformation(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    pEvent->FailureCounter = 0;
    pEvent->OCC6 = 0;
    pEvent->OCC4 = 0;
    pEvent->OccurrenceCounter = 0;
    pEvent->AgingCounter = 0;
    pEvent->CyclesSinceFirstFailed = 0;
    pEvent->CyclesSinceLastFailed = 0;
    pEvent->CycleCounterFlag = FALSE;
    pEvent->HealingCounter = 0;
    pEvent->FDC_Trigger = FALSE;
    if(AgedFlag == 0)
    {
        pEvent->AgedCounter = 0;
    }

}

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
Dem_MemEntryDelete(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry, uint8 memDest)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint8 index = 0;
    if (pEntry == NULL_PTR)
    {
        return;
    }

    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

    /*delete the time order and update others*/
    while (index < DemMemDestCfg[memDest].EntryNum)
    {
        if (pEntry->AbsTime < DemMemDestCfg[memDest].EntryList[index].AbsTime)
        {
            DemMemDestCfg[memDest].EntryList[index].AbsTime--;
        }
        index++;
    }
    pEntry->AbsTime = 0;
#if ((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0))
    pEntry->FFNum = 0x00;
    pEntry->LatestFF = 0x00;
    Dem_MemSet((uint8*)pEntry->FFList, 0xFFu, sizeof(Dem_FreezeFrameInfoType) * DEM_MAX_NUMBER_FF_RECORDS);
#endif
#if (DEM_EXTENDED_DATA_CLASS_NUM > 0)
#if (DEM_EXTENDED_DATA_MAX_LEN > 0u)
    Dem_MemSet(pEntry->ExtData, 0xFFu, DEM_EXTENDED_DATA_MAX_LEN);
#endif
    Dem_MemSet(pEntry->ExtStatus, 0x00u, DEM_EXTENDED_DATA_MAX_REF_NUM_BYTE);
#endif
    if ((0u != pEntry->EventId) && (pEntry->EventId <= DEM_EVENT_PARAMETER_NUM))
    {
        /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        pEvent = &DemEventRelateInformation[Dem_GetEventInternalId(pEntry->EventId)];
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        Dem_ClearEventRelateInformation(pEvent);
        if(AgedFlag == 1)
	    {
	        pEntry->FailureCounter = 0x00;
	        pEntry->AgingCounter = 0x00;
	        pEntry->UdsStatus = 0x00;
	        AgedFlag = 0;
	    }
	    else
	    {
                pEntry->EventId = 0x00;
                if (DemMemDestInfo[memDest].RecordNum > 0u)
                {
                    DemMemDestInfo[memDest].RecordNum--;
                }
	    }

    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (                                                                                                        \
    (((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0)) \
     && (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED))                            \
    || (DEM_EXTENDED_DATA_CLASS_NUM > 0))
/*************************************************************************/
/*
 * Brief               Dem_EventDataStorageTrigger
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && pEventBuffer && Trigger
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
FUNC(void, DEM_CODE)
Dem_EventDataStorageTrigger(
    Dem_EventIdType IntId,
    CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer,
    uint8 Trigger)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pMemDest;
    uint16 iloop = 0;
    uint16 TempRef = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    boolean FFStorage;
    boolean ExtDataStorage = FALSE; /* PRQA S 2981 */                          /* MISRA Rule 2.2 */

    if (TempRef == DEM_DTC_REF_INVALID)
    {
        return;
    }
    Dem_Pending = TRUE;
#if (                                                                                                       \
    ((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0)) \
    && (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED))

    FFStorage = Dem_CheckFreezeFrameIsStorage(
#if (                                                                        \
    (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED) \
    && (DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0))
        IntId,
        Trigger
#else
        void
#endif
    );
#endif
#if (DEM_EXTENDED_DATA_CLASS_NUM > 0)
    ExtDataStorage = Dem_CheckExtendedDataIsStorage(IntId, Trigger);
#endif

    if ((FFStorage == FALSE) && (ExtDataStorage == FALSE))
    {
        Dem_Pending = FALSE;
        return;
    }

    pMemDest = DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[TempRef].DemDTCAttributesRef].DemMemoryDestinationRef;
    while (iloop < DEM_MEM_DEST_MAX_NUM_OF_DTC) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
    {
        if ((pMemDest[iloop] != DEM_MEM_DEST_INVALID)
            && (0x00u == DEM_BITS_ISSET(DemMemDestInfo[pMemDest[iloop]].DisableDTCRecordUpdate, TempRef)))
        {
            if (Trigger == DEM_EVENT_MEMORY_ENTRY_STORAGE_TRIGGER)
            {
                pEntry = Dem_MemEntryAllocate(IntId, pMemDest[iloop]);
            }
            else
            {
                pEntry = Dem_MemEntryGet(Dem_GetEventExternalId(IntId), pMemDest[iloop]);
            }
            if (pEntry != NULL_PTR) /*whether get the entry to store*/
            {
#if (                                                                                                       \
    ((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0)) \
    && (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED))
                if (FFStorage == TRUE)
                {
                    Dem_FreezeFrameStorage(IntId, pEntry, pEventBuffer, Trigger);
                }
#endif
#if (DEM_EXTENDED_DATA_CLASS_NUM > 0)
                if (ExtDataStorage == TRUE)
                {
                    Dem_ExtendedDataStorage(IntId, pEntry, pEventBuffer, Trigger);
                }
#endif
#if (DEM_NVRAM_BLOCKID_NUM > 0)
                if ((DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[TempRef].DemDTCAttributesRef]
                         .DemImmediateNvStorage
                     == TRUE)
                    && (DemEventRelateInformation[IntId].OccurrenceCounter < DEM_IMMEDIATE_NV_STORAGE_LIMIT))
                {
#if (DEM_NVRAM_DIVADED == STD_ON)
                    Dem_IntWriteOneNvRAM(IntId);
#else
                    Dem_IntWriteNvRAM();
#endif
                }
#endif
            }
        }
        iloop++;
    }
    Dem_Pending = FALSE;
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif

/*************************************************************************/
/*
 * Brief               Dem_GetEventPriority
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint8
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(uint8, DEM_CODE) Dem_GetEventPriority(Dem_EventIdType IntId)
{
    uint8 res = 0xFF;
    uint16 ref = DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef;

    if (ref != DEM_DTC_REF_INVALID)
    {
        res = DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[ref].DemDTCAttributesRef].DemDTCPriority;
    }
    return res;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_EntryChronologicalOrderUpdate
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_EntryChronologicalOrderUpdate(
    Dem_EventIdType IntId,
    uint8 memDest,
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 index;
    uint8 iloop = 0u;

    while (iloop < DemMemDestCfg[memDest].EntryNum)
    {
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
        if (DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(DemMemDestCfg[memDest].EntryList[iloop].EventId)]
                .DemDTCRef
            == DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(pEntry->EventId)].DemDTCRef)
        {
            index = 0;
            while (index < DemMemDestCfg[memDest].EntryNum)
            {
                if (pEntry->AbsTime < DemMemDestCfg[memDest].EntryList[index].AbsTime)
                {
                    DemMemDestCfg[memDest].EntryList[index].AbsTime--;
                }
                index++;
            }
            pEntry->AbsTime = DemMemDestCfg[memDest].EntryNum;
            /*Update the DEM_EVENT_COMBINATION event new ID*/
            pEntry->EventId = Dem_GetEventExternalId(IntId);
            break;
        }
#else
        DEM_UNUSED(IntId);
#endif
        if (pEntry->EventId == DemMemDestCfg[memDest].EntryList[iloop].EventId)
        {
            index = 0;
            while (index < DemMemDestCfg[memDest].EntryNum)
            {
                if (pEntry->AbsTime < DemMemDestCfg[memDest].EntryList[index].AbsTime)
                {
                    DemMemDestCfg[memDest].EntryList[index].AbsTime--;
                }
                index++;
            }
            pEntry->AbsTime = DemMemDestInfo[memDest].RecordNum;
            break;
        }
        iloop++;
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_CheckEntryAlreadyAllocated
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Dem_ReturnCheckEntryIsStoredType
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(Dem_ReturnCheckEntryIsStoredType, DEM_CODE) Dem_CheckEntryAlreadyAllocated(
    Dem_EventIdType IntId,
    uint8 memDest,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) * pEntry,
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) Entry)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint8 iloop = 0u;

    while ((iloop < DemMemDestCfg[memDest].EntryNum) && (*pEntry == NULL_PTR))
    {
        /*check if event is already stored*/
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
        if ((Entry->EventId != 0u)
            && ((DemPbCfgPtr->DemEventParameter[IntId].DemDTCRef
                 == DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(Entry->EventId)].DemDTCRef)
                && (Entry->EventId != Dem_GetEventExternalId(IntId))))
        {
            *pEntry = Entry;
            /*SWS_Dem_01051*/
            if (DEM_FLAGS_ISSET(
                    DemEventRelateInformation[Dem_GetEventInternalId(Entry->EventId)].UdsStatus,
                    DEM_UDS_STATUS_CDTC)
                != 0x00u)
            {
                return DEM_CHECK_STORED_NOT_OK;
            }
        }
#endif
        if (Entry->EventId == Dem_GetEventExternalId(IntId))
        {
            *pEntry = Entry;
        }
        Entry++;
        iloop++;
    }

    return DEM_CHECK_STORED_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_COMPONENT_NUM > 0)
/*************************************************************************/
/*
 * Brief               Dem_EventTestFailedProcessOfComponent
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_EventTestFailedProcessOfComponent(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg)
{
    uint16 ComponentID;
    uint16 iloop = 0u;
    P2CONST(uint16, AUTOMATIC, DEM_CONST) pComponentIndex;

    ComponentID = pEventCfg->DemComponentClassRef;
    if (ComponentID != DEM_COMPONENT_INVALID)                     /*check whether event ref the component*/
    {
        if (DemComponentStatus[ComponentID].availability == TRUE) /*check the component availability*/
        {
            if (DemPbCfgPtr->DemComponent[ComponentID].DemParentComponentRef != DEM_COMPONENT_INVALID)
            {
                while (ComponentID != DEM_COMPONENT_INVALID)
                {
                    /*SWS_Dem_01126 SWS_Dem_01127 SWS_Dem_01128*/
                    if (((DemComponentStatus[ComponentID].Status == TRUE)
                         && (DemComponentStatus[ComponentID].FailurePriority < pEventCfg->DemComponentPriority)
                         && (DemPbCfgPtr->DemComponent[ComponentID].DemComponentIgnoresPriority == FALSE))
                        || ((DemPbCfgPtr->DemComponent[ComponentID].DemParentComponentRef != DEM_COMPONENT_INVALID)
                            && (DemComponentStatus[DemPbCfgPtr->DemComponent[ComponentID].DemParentComponentRef].Status
                                == TRUE)))
                    {
                        DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_CONSECUTIVE_FAULT);
                    }
                    ComponentID =
                        DemPbCfgPtr->DemComponent[ComponentID].DemParentComponentRef; /* next parent component*/
                }
                ComponentID = pEventCfg->DemComponentClassRef;
                if (DemComponentStatus[ComponentID].FailurePriority > pEventCfg->DemComponentPriority)
                {
                    DemComponentStatus[ComponentID].FailurePriority = pEventCfg->DemComponentPriority;
                }
                if (DemComponentStatus[ComponentID].Status == FALSE)
                {
                    DemComponentStatus[ComponentID].Status = TRUE;
                    /*SWS_Dem_01133*/
                    if (DemPbCfgPtr->DemComponent[ComponentID].DemComponentFailedCallbackFnc != NULL_PTR)
                    {
                        DemPbCfgPtr->DemComponent[ComponentID].DemComponentFailedCallbackFnc(ComponentID + 1u, TRUE);
                    }
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
                    /*SWS_Dem_01132] */
                    (void)FiM_DemTriggerOnComponentStatus(ComponentID + 1u, TRUE);
#endif
                }
            }
            else
            {
                /*SWS_Dem_01126 SWS_Dem_01128*/
                if ((DemComponentStatus[ComponentID].Status == TRUE)
                    && (DemComponentStatus[ComponentID].FailurePriority < pEventCfg->DemComponentPriority)
                    && (DemPbCfgPtr->DemComponent[ComponentID].DemComponentIgnoresPriority == FALSE))
                {
                    DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_CONSECUTIVE_FAULT);
                    DemComponentStatus[ComponentID].Status = TRUE;
                }
                else
                {
                    if (DemComponentStatus[ComponentID].Status == FALSE)
                    {
                        DemComponentStatus[ComponentID].Status = TRUE;
                        /*SWS_Dem_01133*/
                        if (DemPbCfgPtr->DemComponent[ComponentID].DemComponentFailedCallbackFnc != NULL_PTR)
                        {
                            DemPbCfgPtr->DemComponent[ComponentID].DemComponentFailedCallbackFnc(
                                ComponentID + 1u,
                                TRUE);
                        }
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
                        /*SWS_Dem_01132] */
                        (void)FiM_DemTriggerOnComponentStatus(ComponentID + 1u, TRUE);
#endif
                    }
                }
                if (DemComponentStatus[ComponentID].FailurePriority > pEventCfg->DemComponentPriority)
                {
                    DemComponentStatus[ComponentID].FailurePriority = pEventCfg->DemComponentPriority;
                }
            }
            /*SWS_Dem_01124*/
            pComponentIndex = DemPbCfgPtr->DemComponent[ComponentID].DemImmediateChildComponentRef;
            while ((iloop < DEM_IMMEDITE_CHILD_COMPONENT_MAX_NUM) && (*pComponentIndex != DEM_COMPONENT_INVALID))
            {
                DemComponentStatus[*pComponentIndex].Status = TRUE;
                iloop++;
                pComponentIndex++;
            }
        }
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

#if (DEM_EVENT_DISPLACEMENT_STRATEGY != DEM_DISPLACEMENT_NONE)
/*************************************************************************/
/*
 * Brief               Dem_DeleteDisplacementEntry
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      InternalId && MemIndex
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_DeleteDisplacementEntry(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pResEntry, VAR(uint8, DEM_VAR) memDest)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
#if ((DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_ON) || (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE))
    uint16 iloop = 0u;
#endif

#if (DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_ON)
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

    pEvent = &DemEventRelateInformation[Dem_GetEventInternalId(pResEntry->EventId)];
    /* SWS_Dem_00409 Reset bit2 bit3 to 0 */

    while (iloop < DEM_EVENT_PARAMETER_NUM) /*SWS_Dem_00443 */
    {
        if (DemPbCfgPtr->DemEventParameter[pEvent->IntId].DemDTCRef == DemPbCfgPtr->DemEventParameter[iloop].DemDTCRef)
        {
            DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_PDTC | DEM_UDS_STATUS_CDTC);
        }
        iloop++;
    }
#if (DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
    /*SWS_Dem_01186*/
    iloop = 0;
    while (iloop < DEM_EVENT_PARAMETER_NUM) /*SWS_Dem_00443] */
    {
        if (DemPbCfgPtr->DemEventParameter[pEvent->IntId].DemDTCRef == DemPbCfgPtr->DemEventParameter[iloop].DemDTCRef)
        {
            DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_TFSLC);
        }
        iloop++;
    }
#endif
    Dem_UpdateCombinedDtcStatus(pEvent->IntId); /* update the combination event dtc status*/
    Dem_ResponseOnDtcStatusChange(pEvent->IntId);
#endif
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
    DemDTCGeneralStatus[DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(pResEntry->EventId)].DemDTCRef]
        .CbUdsStatus =
        DemEventRelateInformation[Dem_GetEventInternalId(pResEntry->EventId)].UdsStatus; /*SWS_Dem_00443*/
    iloop = 0;
    while (iloop < DEM_EVENT_PARAMETER_NUM)
    {
        if (DemPbCfgPtr->DemEventParameter[iloop].DemDTCRef
            == DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(pResEntry->EventId)].DemDTCRef)
        {
            DemEventRelateInformation[iloop].UdsStatus =
                DemDTCGeneralStatus[DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(pResEntry->EventId)]
                                        .DemDTCRef]
                    .CbUdsStatus;
        }
        iloop++;
    }
#endif
    Dem_MemEntryDelete(pResEntry, memDest);
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_EventDisplacementProcess
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      InternalId && MemIndex
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Dem_EventMemEntryType*
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR), DEM_CODE) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    Dem_EventDisplacementProcess(Dem_EventIdType InternalId, uint8 memDest)
{
    /* Search entries with lowest priority */
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pResEntry = NULL_PTR; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    /* PRQA S 3432++ */                                                                      /* MISRA Rule 20.7 */
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry = DemMemDestCfg[memDest].EntryList;
    /* PRQA S 3432-- */                                                                      /* MISRA Rule 20.7 */
    uint16 iloop = 0u;
    uint8 EventNewPriority = Dem_GetEventPriority(InternalId);
    uint8 EntryPriority;
#if (DEM_EVENT_DISPLACEMENT_STRATEGY == DEM_DISPLACEMENT_FULL)
    boolean PassiveFound = FALSE;
#endif
    boolean LowPriorityFound = FALSE;
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint16 TempEventIntId;

    while (iloop < DemMemDestCfg[memDest].EntryNum)
    {
        /* find the needed entry in the Entry list */
        TempEventIntId = Dem_GetEventInternalId(pEntry->EventId);
        EntryPriority = Dem_GetEventPriority(TempEventIntId);
        /* Check CurrentDTC Disable Record Update */
        if (0x00u
            != DEM_BITS_ISSET(
                DemMemDestInfo[memDest].DisableDTCRecordUpdate,
                DemPbCfgPtr->DemEventParameter[TempEventIntId].DemDTCRef))
        {
            pEntry++;
        }
#if (                                                                                     \
    ((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) || (DEM_OBD_SUPPORT == DEM_OBD_PRIMARY_ECU)) \
    && (DEM_OBD_EVENT_DISPLACEMENT == STD_ON))
        /*SWS_Dem_00695] */
        /* PRQA S 3415++ */ /* MISRA Rule 13.5 */
        else if (
            (DemPbCfgPtr->DemEventParameter[TempEventIntId].DemDTCRef != DEM_DTC_REF_INVALID)
            && (DemPbCfgPtr->DemDTC[DemPbCfgPtr->DemEventParameter[TempEventIntId].DemDTCRef].DTCKind
                == DEM_DTC_KIND_EMISSION_REL_DTCS)
            && (
#if (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
                (Dem_CheckEventAllIndicator(TempEventIntId) == FALSE) ||
#endif
                ((pEntry->FFNum != 0u) && (EntryPriority <= EventNewPriority))
                || (0x00u
                    != DEM_FLAGS_ISSET(DemEventRelateInformation[TempEventIntId].UdsStatus, DEM_UDS_STATUS_PDTC))))
        /* PRQA S 3415-- */ /* MISRA Rule 13.5 */
        {
            pEntry++;
        }
#endif
        else
        {
            pEvent = &DemEventRelateInformation[TempEventIntId];
#if (DEM_EVENT_DISPLACEMENT_STRATEGY == DEM_DISPLACEMENT_FULL)
            if (EventNewPriority <= EntryPriority) /* SWS_Dem_00403*/
            {
                /*SWS_Dem_00404*/
                if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_ACTIVE))
                {
                    if (PassiveFound == FALSE)
                    {
                        /* The First Passive Mode Entry Found */
                        pResEntry = pEntry;
                        PassiveFound = TRUE;
                    }
                    else
                    {
                        /* SWS_Dem_00405 Already found  Get The Oldest One */
                        if (pResEntry->AbsTime > pEntry->AbsTime)
                        {
                            pResEntry = pEntry;
                        }
                    }
                }

                if (PassiveFound == FALSE) /* not found passive */
                {
#endif
                    if (EventNewPriority < EntryPriority)
                    {
                        /* SWS_Dem_00403 */
                        if (LowPriorityFound == FALSE)
                        {
                            LowPriorityFound = TRUE;
                            pResEntry = pEntry;
                        }
                        /* SWS_Dem_00405 Already found Get The Oldest One*/
                        if (pResEntry->AbsTime > pEntry->AbsTime)
                        {
                            pResEntry = pEntry;
                        }
                    }
                    else
                    {
                        /* SWS_Dem_00692 TestNotCompletedThisOperationCycle bit == 1 */
                        if (LowPriorityFound == FALSE)
                        {
                            if (0x00u != DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCTOC))
                            {
                                if (pResEntry == NULL_PTR)
                                {
                                    pResEntry = pEntry;
                                }
                                /* SWS_Dem_00405 Already found  Get The Oldest One*/
                                if (pResEntry->AbsTime > pEntry->AbsTime)
                                {
                                    pResEntry = pEntry;
                                }
                            }
                        }
                    }
#if (DEM_EVENT_DISPLACEMENT_STRATEGY == DEM_DISPLACEMENT_FULL)
                }
            }
#endif
            pEntry++;
        }
        iloop++;
    }
    /*SWS_Dem_00408*/
    if ((pResEntry != NULL_PTR)
        && (DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(pResEntry->EventId)].DemDTCRef
            != DEM_DTC_REF_INVALID))
    {
        Dem_DeleteDisplacementEntry(pResEntry, memDest);
    }
    return pResEntry;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

#if ((DEM_INDICATOR_NUM > 0) && (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0))
/*************************************************************************/
/*
 * Brief               Dem_CheckWIROn
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEvent && pEventCfg
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(boolean, DEM_CODE) Dem_CheckWIROn(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg)
{
    boolean res = FALSE;
    uint16 iloop = 0;
    P2CONST(Dem_IndicatorAttributeType, AUTOMATIC, DEM_CONST)
    pWIRAttr = &DemIndicatorAttribute[pEventCfg->AttrStartIndex];
    while (iloop < pEventCfg->AttrNum)
    {
        if ((pWIRAttr->DemIndicatorFailureCycleCounterThreshold <= pEvent->FailureCounter)
            || ((DemPbCfgPtr->DemEventParameter[pEvent->IntId].DemOBDGroupingAssociativeEventsRef
                 != DEM_EVENT_PARAMETER_INVALID)
                && (pWIRAttr->DemIndicatorFailureCycleCounterThreshold
                    <= DemEventRelateInformation[DemPbCfgPtr->DemEventParameter[pEvent->IntId]
                                                     .DemOBDGroupingAssociativeEventsRef]
                           .FailureCounter))) /*reach the threshold activate the mil SWS_Dem_00967 SWS_Dem_00501*/
        {
#if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
            uint16 DemDTCRef = DemPbCfgPtr->DemEventParameter[pEvent->IntId].DemDTCRef;
            uint16 DemObdDTCRef = DemPbCfgPtr->DemDTC[DemDTCRef].DemObdDTCRef;
#endif
            res = TRUE;
            DemWIRStatus[pWIRAttr->DemIndicatorRef] = pWIRAttr->DemIndicatorBehaviour;
#if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
            if ((((DemDTCRef != DEM_DTC_REF_INVALID) && (DemPbCfgPtr->DemDTC[DemDTCRef].DemDtcValue < 0xFFFF33UL)
                  && (DemPbCfgPtr->DemDTC[DemDTCRef].DemDtcValue > 0UL))
                 || ((DEM_OBD_DTC_INVALID != DemObdDTCRef)
                     && ((DemPbCfgPtr->DemObdDTC[DemObdDTCRef].DemDtcValue != DEM_OBD_DTC_CFG_INVALID)
                         || (DemPbCfgPtr->DemObdDTC[DemObdDTCRef].DemJ1939DTCValue != DEM_J1939_DTC_CFG_INVALID)))))
            { /*SWS_Dem_01139 SWS_Dem_00703 */
                Dem_UpdateOBDMilStatus(pWIRAttr->DemIndicatorRef, pEvent->IntId);
            }
#endif
        }
        pWIRAttr++;
        iloop++;
    }
    return res;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_CheckWIROff
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEvent && pEventCfg
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(boolean, DEM_CODE) Dem_CheckWIROff(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg)
{
    boolean res = TRUE;
    uint16 iloop = 0;
    P2CONST(Dem_IndicatorAttributeType, AUTOMATIC, DEM_CONST)
    pWIRAttr = &DemIndicatorAttribute[pEventCfg->AttrStartIndex];
    uint16 index;
    uint16 cnt;
    boolean Find = FALSE;
#if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    uint16 DemDTCRef;
    uint16 DemObdDTCRef;
#endif

    while (iloop < pEventCfg->AttrNum)
    {
        if (pWIRAttr->DemIndicatorHealingCycleCounterThreshold <= pEvent->HealingCounter) /*SWS_Dem_00503] */
        {
            for (index = 0; ((index < DEM_EVENT_PARAMETER_NUM) && (Find == FALSE)); index++)
            {
                for (cnt = 0; ((cnt < DemPbCfgPtr->DemEventParameter[index].AttrNum) && (Find == FALSE)); cnt++)
                {
                    if ((pWIRAttr->DemIndicatorRef
                         == DemIndicatorAttribute[DemPbCfgPtr->DemEventParameter[index].AttrStartIndex + cnt]
                                .DemIndicatorRef)
                        && (DemEventRelateInformation[index].HealingCounter
                            < DemIndicatorAttribute[DemPbCfgPtr->DemEventParameter[index].AttrStartIndex + cnt]
                                  .DemIndicatorHealingCycleCounterThreshold)
                        && (0x00u != DEM_FLAGS_ISSET(DemEventRelateInformation[index].UdsStatus, DEM_UDS_STATUS_WIR)))
                    {
                        Find = TRUE;
                    }
                }
            }
            if (Find == FALSE)
            {
                DemWIRStatus[pWIRAttr->DemIndicatorRef] = DEM_INDICATOR_OFF;
            }
#if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
            DemDTCRef = DemPbCfgPtr->DemEventParameter[pEvent->IntId].DemDTCRef;
            DemObdDTCRef = DemPbCfgPtr->DemDTC[DemDTCRef].DemObdDTCRef;
            if ((((DemDTCRef != DEM_DTC_REF_INVALID) && (DemPbCfgPtr->DemDTC[DemDTCRef].DemDtcValue < 0xFFFF33UL)
                  && (DemPbCfgPtr->DemDTC[DemDTCRef].DemDtcValue > 0UL))
                 || ((DEM_OBD_DTC_INVALID != DemObdDTCRef)
                     && ((DemPbCfgPtr->DemObdDTC[DemObdDTCRef].DemDtcValue != DEM_OBD_DTC_CFG_INVALID)
                         || (DemPbCfgPtr->DemObdDTC[DemObdDTCRef].DemJ1939DTCValue != DEM_J1939_DTC_CFG_INVALID)))))
            { /*SWS_Dem_01139 SWS_Dem_00703 */
                Dem_UpdateOBDMilStatus(pWIRAttr->DemIndicatorRef, pEvent->IntId);
            }
#endif
        }
        else
        {
            res = FALSE;
        }
        pWIRAttr++;
        iloop++;
    }
    return res;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif

/*************************************************************************/
/*
 * Brief               Dem_ClearUdsStatusOfPDTC
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      OpId
 * Param-Name[out]     None
 * Param-Name[in/out]  pEvent
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
static FUNC(void, DEM_CODE) Dem_ClearUdsStatusOfPDTC(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    if ((0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCTOC))
        && (0x00u != DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_PDTC))
        && (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TFTOC)))
    {
        DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_PDTC);
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_EventAgingProcess
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      OpId
 * Param-Name[out]     None
 * Param-Name[in/out]  pEvent
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_EventAgingProcess(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent, uint8 OpId)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint16 iloop = 0;
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pMemDest;
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry = NULL_PTR; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(Dem_DTCAttributesType, AUTOMATIC, DEM_CONST) pDTCAttrCfg = NULL_PTR;
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg = &DemPbCfgPtr->DemEventParameter[pEvent->IntId];
    uint16 index;
    uint8 AgingCycleCounterThreshold;
#if (DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_OFF)
    uint8 MemIndex = 0;
    uint8 EntryIndex = 0;
    uint8 MinAbsTimeInMemory = 0xf;
    P2CONST(uint8, AUTOMATIC, DEM_CONST) memDest;
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) Entry = NULL_PTR;
#endif

    Dem_Pending = TRUE;

    if (pEventCfg->DemDTCRef != DEM_DTC_REF_INVALID)
    {
        pDTCAttrCfg = &DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[pEventCfg->DemDTCRef].DemDTCAttributesRef];
    }
    if (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TFTOC))
    {
        if ((0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_WIR)) && (pDTCAttrCfg != NULL_PTR))
        {                                                                 /*SWS_Dem_00698] aging*/
            pMemDest = pDTCAttrCfg->DemMemoryDestinationRef;
            while (iloop < DEM_MEM_DEST_MAX_NUM_OF_DTC) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
            {
                if (pMemDest[iloop] != DEM_MEM_DEST_INVALID)
                {
                    pEntry = Dem_MemEntryGet(Dem_GetEventExternalId(pEvent->IntId), pMemDest[iloop]);
                }
                if ((pEntry != NULL_PTR) && (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TFTOC)))
                {
                    if (((pDTCAttrCfg->DemAgingCycleRef == OpId) || (DemAgingCycle == OpId)
                         || ((DemOperationCycle[pEventCfg->DemOperationCycleRef].DemOperationCycleType
                              == DEM_OPCYC_OBD_DCY)
                             && (0x00u == DEM_BITS_ISSET(DemOperationCycleStatus, pEventCfg->DemOperationCycleRef))
                             && (DemOperationCycle[OpId].DemOperationCycleType == DEM_OPCYC_WARMUP)))
                        && (pDTCAttrCfg->DemAgingAllowed == TRUE)
#if (DEM_AGING_REQUIERES_TESTED_CYCLE == STD_ON) /*SWS_Dem_00490 SWS_Dem_00826*/
                        && (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCTOC))
#endif
                    )
                    { /*SWS_Dem_00985 SWS_Dem_00494*/
                        if ((0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TF))
                    && (0x08u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_CDTC)))
                        {
                            pEvent->AgingCounter++; /*SWS_Dem_00489*/
#if (DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
                            AgingCycleCounterThreshold = (pDTCAttrCfg->DemAgingCycleCounterThreshold
                                                          > pDTCAttrCfg->DemAgingCycleCounterThresholdForTFSLC)
                                                             ? pDTCAttrCfg->DemAgingCycleCounterThreshold
                                                             : pDTCAttrCfg->DemAgingCycleCounterThresholdForTFSLC;
#else
                            AgingCycleCounterThreshold = pDTCAttrCfg->DemAgingCycleCounterThreshold;
#endif
#if (DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR == DEM_STATUS_BIT_AGING_AND_DISPLACEMENT)
                            if (pEvent->AgingCounter >= pDTCAttrCfg->DemAgingCycleCounterThresholdForTFSLC)
                            {
                                DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_TFSLC); /*SWS_Dem_01054*/
                            }
#endif
                            if (pEvent->AgingCounter >= pDTCAttrCfg->DemAgingCycleCounterThreshold) /*SWS_Dem_00391*/
                            {
                                /* clear bit3 at next operation cycle end */
                                if( pEvent->AgedCounter < 0xff)
                                {
                                    pEvent->AgedCounter++;
                                }
                                AgedFlag = 1;
                                index = 0;
                                while (index < DEM_EVENT_PARAMETER_NUM) /*SWS_Dem_00443*/
                                {
                                    if (DemPbCfgPtr->DemEventParameter[pEvent->IntId].DemDTCRef
                                        == DemPbCfgPtr->DemEventParameter[index].DemDTCRef)
                                    {
                                        DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_CDTC);
                                    }
                                    index++;
                                }
                                DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_CDTC); /*SWS_Dem_00498*/
                            }
                            if (pEvent->AgingCounter >= AgingCycleCounterThreshold)
                            {
#if (DEM_NVRAM_BLOCKID_NUM > 0)
                                DemAgingStorageTrigger =
                                    TRUE; /* process storage in Dem_SetCycleState or Dem_MainFunction */
#endif
                                if (pMemDest[iloop] != DEM_MEM_DEST_INVALID)
                                {
                                    Dem_MemEntryDelete(pEntry, pMemDest[iloop]); /*SWS_Dem_00493 SWS_Dem_01075 */
                                }
#if (DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW == STD_OFF)
                                index = 0;
                                while (index < DEM_EVENT_PARAMETER_NUM)
                                { /*SWS_Dem_00824] */
                                    if ((DEM_FLAGS_ISSET(
                                             DemEventRelateInformation[index].UdsStatus,
                                             DEM_UDS_STATUS_CDTC)
                                         != 0x00u)
                                        && (DEM_FLAGS_ISSET(
                                                DemEventRelateInformation[index].UdsStatus,
                                                DEM_UDS_STATUS_TF)
                                            == 0x00u)
                                        && (Dem_MemEntryGet(Dem_GetEventExternalId(index), pMemDest[iloop])
                                            == NULL_PTR))
                                    { /*not stored in an event memory entry  UDS status bit 3 (ConfirmedDTC) set  UDS
                                         status bit 0 (TestFailed) set to 0*/
                                        memDest = DemPbCfgPtr
                                                      ->DemDTCAttributes[DemPbCfgPtr->DemDTC[pEventCfg->DemDTCRef]
                                                                             .DemDTCAttributesRef]
                                                      .DemMemoryDestinationRef;
                                        MemIndex = 0;
                                        while (MemIndex < DEM_MEM_DEST_MAX_NUM_OF_DTC)
                                        {
                                            if (memDest[MemIndex] == pMemDest[iloop])
                                            {
                                                Entry = Dem_MemEntryGet(
                                                    0x00u,
                                                    pMemDest[iloop]); /*return NULL_PTR means no idle memory*/
                                                if (Entry != NULL_PTR)
                                                {                     /*SWS_Dem_00824] */
                                                    if (DemMemDestInfo[pMemDest[iloop]].RecordNum
                                                        < DemMemDestCfg[pMemDest[iloop]].EntryNum)
                                                    {
                                                        DemMemDestInfo[pMemDest[iloop]].RecordNum++;
                                                    }
                                                    Entry->EventId = index;
                                                    EntryIndex = 0;
                                                    while (EntryIndex < DemMemDestCfg[pMemDest[iloop]].EntryNum)
                                                    {
                                                        if (MinAbsTimeInMemory > DemMemDestCfg[pMemDest[iloop]]
                                                                                     .EntryList[EntryIndex]
                                                                                     .AbsTime)
                                                        {
                                                            MinAbsTimeInMemory = DemMemDestCfg[pMemDest[iloop]]
                                                                                     .EntryList[EntryIndex]
                                                                                     .AbsTime;
                                                        }
                                                        DemMemDestCfg[pMemDest[iloop]].EntryList[EntryIndex].AbsTime +=
                                                            1u;
                                                        EntryIndex++;
                                                    }
                                                    Entry->AbsTime = MinAbsTimeInMemory;
                                                }
                                            }
                                            MemIndex++;
                                        }
                                    }
                                    index++;
                                }
#endif
                            }
                        }
                    }
                }
                iloop++;
            }
        }
    }
    else
    {
        pEvent->HealingCounter = 0;
        pEvent->AgingCounter = 0;
    }
    Dem_Pending = FALSE;
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_EventHealingProcess
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      OpId
 * Param-Name[out]     None
 * Param-Name[in/out]  pEvent
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_EventHealingProcess(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent, uint8 OpId)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg = &DemPbCfgPtr->DemEventParameter[pEvent->IntId];
    if ((0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TFTOC)) && (pEventCfg != NULL_PTR))
    {
        if (0x00u != DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_WIR))
        { /*healing*/
            pEvent->AgingCounter = 0;
            if (((pEventCfg->DemOperationCycleRef == OpId)
                 || ((DemOperationCycle[pEventCfg->DemOperationCycleRef].DemOperationCycleType == DEM_OPCYC_OBD_DCY)
                     && (0x00u == DEM_BITS_ISSET(DemOperationCycleStatus, pEventCfg->DemOperationCycleRef))
                     && (DemOperationCycle[OpId].DemOperationCycleType == DEM_OPCYC_WARMUP))) /*SWS_Dem_01056]*/
                && (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCTOC)))
            {
                pEvent->HealingCounter++;
                /* The counter shall be cleared in the beginning of the operation cycle following an operation cycle
                 * where FDC10 did not reach the value +127 at any time but -128 (the counter shall maintain its value
                 * if did not reach the value -128). */
                pEvent->OCC6 = 0;
#if ((DEM_INDICATOR_NUM > 0) && (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0))
                if (TRUE == Dem_CheckWIROff(pEvent, pEventCfg))
                {
                    DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_WIR); /* SWS_Dem_00533*/
                }
#endif
            }
        }
    }
    else
    {
        pEvent->HealingCounter = 0;
        pEvent->AgingCounter = 0;
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*************************************************************************/
/*
 * Brief               Dem_OperationCycleCounterProcess
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  pEvent
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_OperationCycleCounterProcess(Dem_EventRelateInformationType* pEvent)
{
    if (0x00u != DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TFTOC))
    {
        if (pEvent->FailureCounter < 0xFFu)
        {
            pEvent->FailureCounter++; /*SWS_Dem_00782*/
            /* Test Failed This Operation Cycle */
            pEvent->CyclesSinceLastFailed = 0u;
        }
    }
    if (pEvent->CycleCounterFlag == TRUE)
    {
        if (pEvent->CyclesSinceFirstFailed < 0xFFu)
        {
            pEvent->CyclesSinceFirstFailed++; /* SWS_Dem_00778*/
        }
        if (pEvent->CyclesSinceLastFailed < 0xFFu)
        { /*SWS_Dem_00774*/
            pEvent->CyclesSinceLastFailed++;
        }
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_EventStatusProcessByDTC(
    uint16 dtcIndex,
    uint16 iloop,
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint16 index = 0;

    if (DEM_DTC_REF_INVALID != dtcIndex)
    {
        if (DemPbCfgPtr->DemEventParameter[iloop].DemEventAvailable == TRUE)
        {
            DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE);
            DemDTCGeneralStatus[dtcIndex].SuppressionStatus = FALSE;
        }
        else
        {
            /* SWS_Dem_00915 */
            while (index < DEM_EVENT_PARAMETER_NUM)
            {
                if ((dtcIndex == DemPbCfgPtr->DemEventParameter[index].DemDTCRef)
                    && (0x00u != DemEventRelateInformation[index].Status))
                {
                    dtcIndex = DEM_DTC_REF_INVALID;
                    break;
                }
                index++;
            }
            if (dtcIndex != DEM_DTC_REF_INVALID)
            {
                DemDTCGeneralStatus[dtcIndex].SuppressionStatus = TRUE;
            }
        }
    }
    else
    {
        if (DemPbCfgPtr->DemEventParameter[iloop].DemEventAvailable == TRUE)
        {
            DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE);
        }
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_NVRAM_BLOCKID_NUM > 0)

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/*************************************************************************/
/*
 * Brief               Dem_CopyInfoFromEntry
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  pEvent
 * Return              None
 */
/*************************************************************************/
static FUNC(void, DEM_CODE) Dem_CopyInfoFromInfo(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_APPL_DATA) Info,
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_APPL_DATA) Entry)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Entry->UdsStatus = Info->UdsStatus;
    Entry->AgingCounter = Info->AgingCounter;
    Entry->OccurrenceCounter = Info->OccurrenceCounter;
    Entry->HealingCounter = Info->HealingCounter;
    Entry->FailureCounter = Info->FailureCounter;
    Entry->AgedCounter = Info->AgedCounter;
    Entry->OCC6 = Info->OCC6;
    Entry->OCC4 = Info->OCC4;
    Entry->CyclesSinceFirstFailed = Info->CyclesSinceFirstFailed;
    Entry->CyclesSinceLastFailed = Info->CyclesSinceLastFailed;
    Entry->CycleCounterFlag = Info->CycleCounterFlag;
}

#if (DEM_NVRAM_DIVADED == STD_ON)
/*************************************************************************/
/*
 * Brief               Dem_IntWriteOneNvRAM
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  pEvent
 * Return              None
 */
/*************************************************************************/
static FUNC(void, DEM_CODE) Dem_IntWriteOneNvRAM(uint16 IntId)
{
    uint16 blockRef;
    uint8 DemMemDestindex;
    uint16 iloop = 0;
    uint16 tempEventId = 0;
    uint16 blockIndex = 0;
    for (DemMemDestindex = 0; DemMemDestindex < DEM_MEM_DEST_TOTAL_NUM; DemMemDestindex++)
    {
        if (DemMemDestCfg[DemMemDestindex].ExtId == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
        {
            for (iloop = 0; iloop < DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY; iloop++)
            {
                tempEventId = DemMemDestCfg[DemMemDestindex].EntryList[iloop].EventId;
                if (tempEventId != 0u)
                {
                    tempEventId = tempEventId - 1u;
                    if (IntId == tempEventId)
                    {
                        Dem_CopyInfoFromInfo(
                            &DemEventRelateInformation[tempEventId],
                            &DemMemDestCfg[DemMemDestindex].EntryList[iloop]);
                        blockRef = DemNvRamBlockId[blockIndex];
                        Dem_MemCopy(
                            NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
                            &DemMemDestCfg[DemMemDestindex].EntryList[iloop],
                            ENTRY_STORAGE_LEN);
                        (void)NvM_CancelJobs(blockRef);
                        (void)NvM_WriteBlock(blockRef, NULL_PTR);
                        break;
                    }
                }
                blockIndex++;
            }
            break;
        }
    }
#if (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > 0)
    for (DemMemDestindex = 0; DemMemDestindex < DEM_MEM_DEST_TOTAL_NUM; DemMemDestindex++)
    {
        if (DemMemDestCfg[DemMemDestindex].ExtId == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
        {
            for (iloop = 0; iloop < DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT; iloop++)
            {
                tempEventId = DemMemDestCfg[DemMemDestindex].EntryList[iloop].EventId;
                if (tempEventId != 0u)
                {
                    tempEventId = tempEventId - 1u;
                    if (IntId == tempEventId)
                    {
                        Dem_CopyInfoFromInfo(
                            &DemEventRelateInformation[tempEventId],
                            &DemMemDestCfg[DemMemDestindex].EntryList[iloop]);
                        blockRef = DemNvRamBlockId[blockIndex];
                        Dem_MemCopy(
                            NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
                            &DemMemDestCfg[DemMemDestindex].EntryList[iloop],
                            ENTRY_STORAGE_LEN);
                        (void)NvM_CancelJobs(blockRef);
                        (void)NvM_WriteBlock(blockRef, NULL_PTR);
                        break;
                    }
                }
                blockIndex++;
            }
            break;
        }
    }
#endif
/***************add for Gecko******************/
    for (iloop = 0; iloop < DEM_EVENT_PARAMETER_NUM; iloop++)
        {
            DemEventRelateInformationStorage.UdsStatus[iloop] = DemEventRelateInformation[iloop].UdsStatus;
        }
            DemEventRelateInformationStorage.FirstDtcConfirmed = DemDTCByOccurrenceTimeInfo.FirstDtcConfirmed;
            DemEventRelateInformationStorage.FirstFailed = DemDTCByOccurrenceTimeInfo.FirstFailed;
            DemEventRelateInformationStorage.MostRecDtcConfirmed = DemDTCByOccurrenceTimeInfo.MostRecDtcConfirmed;
            DemEventRelateInformationStorage.MostRecentFailed = DemDTCByOccurrenceTimeInfo.MostRecentFailed;

    blockRef = DemNvRamBlockId[DEM_NVRAM_BLOCKID_NUM-2];
    Dem_MemCopy(
        NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
        &DemEventRelateInformationStorage,
        sizeof(Dem_EventRelateInformationStorageType));
    (void)NvM_CancelJobs(blockRef);
    (void)NvM_WriteBlock(blockRef, NULL_PTR);
}
#endif /* DEM_NVRAM_DIVADED == STD_ON */

/*************************************************************************/
/*
 * Brief               Dem_IntWriteNvRAM
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  pEvent
 * Return              None
 */
/*************************************************************************/
FUNC(void, DEM_CODE) Dem_IntWriteNvRAM(void)
{
    uint16 blockRef;
    uint8 DemMemDestindex;
    uint16 iloop;
    uint16 tempEventId = 0;
    uint16 blockIndex = 0;
#if (DEM_NVRAM_DIVADED == STD_ON)
    for (DemMemDestindex = 0; DemMemDestindex < DEM_MEM_DEST_TOTAL_NUM; DemMemDestindex++)
    {
        if (DemMemDestCfg[DemMemDestindex].ExtId == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
        {
            for (iloop = 0; iloop < DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY; iloop++)
            {
                tempEventId = DemMemDestCfg[DemMemDestindex].EntryList[iloop].EventId;
                if (tempEventId != 0u)
                {
                    tempEventId = tempEventId - 1u;
                    Dem_CopyInfoFromInfo(
                        &DemEventRelateInformation[tempEventId],
                        &DemMemDestCfg[DemMemDestindex].EntryList[iloop]);
                }
                blockRef = DemNvRamBlockId[blockIndex];
                blockIndex++;
                Dem_MemCopy(
                    NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
                    &DemMemDestCfg[DemMemDestindex].EntryList[iloop],
                    ENTRY_STORAGE_LEN);
                (void)NvM_CancelJobs(blockRef);
                (void)NvM_WriteBlock(blockRef, NULL_PTR);
            }
            break;
        }
    }
#if (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > 0)
    for (DemMemDestindex = 0; DemMemDestindex < DEM_MEM_DEST_TOTAL_NUM; DemMemDestindex++)
    {
        if (DemMemDestCfg[DemMemDestindex].ExtId == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
        {
            for (iloop = 0; iloop < DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT; iloop++)
            {
                tempEventId = DemMemDestCfg[DemMemDestindex].EntryList[iloop].EventId;
                if (tempEventId != 0u)
                {
                    tempEventId = tempEventId - 1u;
                    Dem_CopyInfoFromInfo(
                        &DemEventRelateInformation[tempEventId],
                        &DemMemDestCfg[DemMemDestindex].EntryList[iloop]);
                }
                blockRef = DemNvRamBlockId[blockIndex];
                blockIndex++;
                Dem_MemCopy(
                    NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
                    &DemMemDestCfg[DemMemDestindex].EntryList[iloop],
                    ENTRY_STORAGE_LEN);
                (void)NvM_CancelJobs(blockRef);
                (void)NvM_WriteBlock(blockRef, NULL_PTR);
            }
            break;
        }
    }
#endif
#else
    for (iloop = 0; iloop < DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY; iloop++)
    {
        /* PRQA S 2877++ */ /* MISRA Dir 4.1 */
        for (DemMemDestindex = 0; DemMemDestindex < DEM_MEM_DEST_TOTAL_NUM; DemMemDestindex++)
        /* PRQA S 2877-- */ /* MISRA Dir 4.1 */
        {
            if (DemMemDestCfg[DemMemDestindex].ExtId == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
            {
                DemEventMemoryEntryStorage[iloop] = DemMemDestCfg[DemMemDestindex].EntryList[iloop];
                tempEventId = DemMemDestCfg[DemMemDestindex].EntryList[iloop].EventId;
            }
        }
        if (tempEventId != 0u)
        {
            tempEventId = tempEventId - 1u;
            Dem_CopyInfoFromInfo(&DemEventRelateInformation[tempEventId], &DemEventMemoryEntryStorage[iloop]);
        }
    }
#if (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > 0)
    for (; iloop < ENTRY_STORAGE_NUM; iloop++)
    {
        for (DemMemDestindex = 0; DemMemDestindex < DEM_MEM_DEST_TOTAL_NUM; DemMemDestindex++)
        {
            if (DemMemDestCfg[DemMemDestindex].ExtId == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
            {
                DemEventMemoryEntryStorage[iloop] =
                    DemMemDestCfg[DemMemDestindex].EntryList[iloop - DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY];
                tempEventId =
                    DemMemDestCfg[DemMemDestindex].EntryList[iloop - DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY].EventId;
            }
        }
        if (tempEventId != 0u)
        {
            tempEventId = tempEventId - 1u;
            Dem_CopyInfoFromInfo(&DemEventRelateInformation[tempEventId], &DemEventMemoryEntryStorage[iloop]);
        }
    }
#endif
    blockRef = DemNvRamBlockId[blockIndex];
    blockIndex++;
    Dem_MemCopy(
        NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
        DemEventMemoryEntryStorage,
        TOTAL_ENTRY_STORAGE_LEN);
    (void)NvM_CancelJobs(blockRef);
    (void)NvM_WriteBlock(blockRef, NULL_PTR);
#endif

    /* req SWS_Dem_00525 SWS_Dem_00389 SWS_Dem_01183 SWS_Dem_00391 SWS_Dem_00392 SWS_Dem_00393
     * SWS_Dem_00394 SWS_Dem_00395*/
    for (iloop = 0; iloop < DEM_EVENT_PARAMETER_NUM; iloop++)
    {
        DemEventRelateInformationStorage.UdsStatus[iloop] = DemEventRelateInformation[iloop].UdsStatus;
#if (DEM_DEBOUNCE_COUNTER_STORAGE_NUM > 0)
        /*SWS_Dem_00674*/
        if (DemPbCfgPtr->DemDebounceCounterBasedClass[DemPbCfgPtr->DemEventParameter[iloop].AlgorithmRef]
                .DemDebounceCounterStorage
            == TRUE)
        {
            DemEventRelateInformationStorage.DebounceCounter[iloop] =
                (sint16)DemDebounceCounterInfo[DemPbCfgPtr->DemEventParameter[iloop].AlgorithmIndex]
                    .InternalDebounceCounter;
        }
#endif
    }
#if (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON)
    /* req SWS_Dem_00577*/
    for (iloop = 0; iloop < DEM_OPERATION_CYCLE_NUM_BYTE; iloop++)
    {
        DemEventRelateInformationStorage.DemOperationCycleStatus[iloop] = DemOperationCycleStatus[iloop];
    }
#endif
    DemEventRelateInformationStorage.FirstDtcConfirmed = DemDTCByOccurrenceTimeInfo.FirstDtcConfirmed;
    DemEventRelateInformationStorage.FirstFailed = DemDTCByOccurrenceTimeInfo.FirstFailed;
    DemEventRelateInformationStorage.MostRecDtcConfirmed = DemDTCByOccurrenceTimeInfo.MostRecDtcConfirmed;
    DemEventRelateInformationStorage.MostRecentFailed = DemDTCByOccurrenceTimeInfo.MostRecentFailed;

    blockRef = DemNvRamBlockId[blockIndex];
    Dem_MemCopy(
        NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
        &DemEventRelateInformationStorage,
        sizeof(Dem_EventRelateInformationStorageType));
    (void)NvM_CancelJobs(blockRef);
    (void)NvM_WriteBlock(blockRef, NULL_PTR);

#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    DemOBDDataStorage.IgnUpCycleCounter = IgnUpCycleCounter;
    DemOBDDataStorage.ContinuousMICounter = ContinuousMICounter;
    DemOBDDataStorage.WarmUpCycleCounter = WarmUpCycleCounter;
    DemOBDDataStorage.OBDDistanceMILOn = OBDDistanceMILOn;
    DemOBDDataStorage.DistSinceDtcCleared = DistSinceDtcCleared;
    DemOBDDataStorage.OBDTimeMILOn = OBDTimeMILOn;
    DemOBDDataStorage.OBDTimeDTCClear = OBDTimeDTCClear;
    DemOBDDataStorage.OBDB1Counter = OBDB1Counter;
#if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    DemOBDDataStorage.MasterContinuousMICounter = MasterContinuousMICounter;
#endif
    blockIndex++;
    blockRef = DemNvRamBlockId[blockIndex];
    Dem_MemCopy(
        NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
        &DemOBDDataStorage,
        sizeof(DemOBDDataStorageType));
    (void)NvM_CancelJobs(blockRef);
    (void)NvM_WriteBlock(blockRef, NULL_PTR);
#endif
}

/*************************************************************************/
/*
 * Brief               Dem_CopyInfoFromEntry
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  pEvent
 * Return              None
 */
/*************************************************************************/
static FUNC(void, DEM_CODE) Dem_CopyInfoFromEntry(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_APPL_DATA) Info,
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_APPL_DATA) Entry)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Info->UdsStatus = Entry->UdsStatus;
    Info->AgingCounter = Entry->AgingCounter;
    Info->OccurrenceCounter = Entry->OccurrenceCounter;
    Info->HealingCounter = Entry->HealingCounter;
    Info->FailureCounter = Entry->FailureCounter;
    Info->AgedCounter = Entry->AgedCounter;
    Info->OCC6 = Entry->OCC6;
    Info->OCC4 = Entry->OCC4;
    Info->CyclesSinceFirstFailed = Entry->CyclesSinceFirstFailed;
    Info->CyclesSinceLastFailed = Entry->CyclesSinceLastFailed;
    Info->CycleCounterFlag = Entry->CycleCounterFlag;
}

/*************************************************************************/
/*
 * Brief               Dem_IntReadNvRAM
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  pEvent
 * Return              None
 */
/*************************************************************************/
FUNC(Std_ReturnType, DEM_CODE) Dem_IntReadNvRAM(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType retVal = E_NOT_OK;
    uint16 iloop;
    uint16 tempEventId = 0;
    uint16 blockIndex = 0;
    uint16 blockRef;
    NvM_RequestResultType RequestResultPtr;
    uint8 DemMemDestindex;
#if (DEM_NVRAM_DIVADED == STD_ON)
    /*the NvRAM data should be validated*/
    for (iloop = 0; iloop < DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY; iloop++)
    {
        blockRef = DemNvRamBlockId[blockIndex];
        blockIndex++;
        (void)NvM_GetErrorStatus(blockRef, &RequestResultPtr);
        if (RequestResultPtr == NVM_REQ_OK)
        {
            for (DemMemDestindex = 0; DemMemDestindex < DEM_MEM_DEST_TOTAL_NUM; DemMemDestindex++)
            {
                if (DemMemDestCfg[DemMemDestindex].ExtId == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
                {
                    Dem_MemCopy(
                        &DemMemDestCfg[DemMemDestindex].EntryList[iloop],
                        NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
                        ENTRY_STORAGE_LEN);
                    tempEventId = DemMemDestCfg[DemMemDestindex].EntryList[iloop].EventId;
                    break;
                }
            }
            if ((tempEventId != 0u) && (tempEventId <= DEM_EVENT_PARAMETER_NUM))
            {
                tempEventId = tempEventId - 1u;
                Dem_CopyInfoFromEntry(
                    &DemEventRelateInformation[tempEventId],
                    &DemMemDestCfg[DemMemDestindex].EntryList[iloop]);
                retVal = E_OK;
                DemMemDestInfo[DemMemDestindex].RecordNum++;
            }
            else
            {
                DemMemDestCfg[DemMemDestindex].EntryList[iloop].EventId = 0u;
            }
        }
    }
#if (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > 0)
    for (iloop = 0; iloop < DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT; iloop++)
    {
        blockRef = DemNvRamBlockId[blockIndex];
        blockIndex++;
        (void)NvM_GetErrorStatus(blockRef, &RequestResultPtr);
        if (RequestResultPtr == NVM_REQ_OK)
        {
            for (DemMemDestindex = 0; DemMemDestindex < DEM_MEM_DEST_TOTAL_NUM; DemMemDestindex++)
            {
                if (DemMemDestCfg[DemMemDestindex].ExtId == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
                {
                    Dem_MemCopy(
                        &DemMemDestCfg[DemMemDestindex].EntryList[iloop],
                        NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
                        ENTRY_STORAGE_LEN);
                    tempEventId = DemMemDestCfg[DemMemDestindex].EntryList[iloop].EventId;
                    break;
                }
            }
            if ((tempEventId != 0u) && (tempEventId <= DEM_EVENT_PARAMETER_NUM))
            {
                tempEventId = tempEventId - 1u;
                Dem_CopyInfoFromEntry(
                    &DemEventRelateInformation[tempEventId],
                    &DemMemDestCfg[DemMemDestindex].EntryList[iloop]);
                retVal = E_OK;
                DemMemDestInfo[DemMemDestindex].RecordNum++;
            }
            else
            {
                DemMemDestCfg[DemMemDestindex].EntryList[iloop].EventId = 0u;
            }
        }
    }
#endif
#else
    /*the NvRAM data should be validated*/
    blockRef = DemNvRamBlockId[blockIndex];
    (void)NvM_GetErrorStatus(blockRef, &RequestResultPtr);
    if (RequestResultPtr == NVM_REQ_OK)
    {
        Dem_MemCopy(
            DemEventMemoryEntryStorage,
            NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
            TOTAL_ENTRY_STORAGE_LEN);
        for (iloop = 0; iloop < DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY; iloop++)
        {
            /* PRQA S 2877++ */ /* MISRA Dir 4.1 */
            for (DemMemDestindex = 0; DemMemDestindex < DEM_MEM_DEST_TOTAL_NUM; DemMemDestindex++)
            /* PRQA S 2877-- */ /* MISRA Dir 4.1 */
            {
                if (DemMemDestCfg[DemMemDestindex].ExtId == DEM_DTC_ORIGIN_PRIMARY_MEMORY)
                {
                    DemMemDestCfg[DemMemDestindex].EntryList[iloop] = DemEventMemoryEntryStorage[iloop];
                    tempEventId = DemMemDestCfg[DemMemDestindex].EntryList[iloop].EventId;
                    break;
                }
            }
            if ((tempEventId != 0u) && (tempEventId <= DEM_EVENT_PARAMETER_NUM))
            {
                tempEventId = tempEventId - 1u;
                Dem_CopyInfoFromEntry(&DemEventRelateInformation[tempEventId], &DemEventMemoryEntryStorage[iloop]);
                DemMemDestInfo[DemMemDestindex].RecordNum++;
            }
            else
            {
                DemEventMemoryEntryStorage[iloop].EventId = 0u;
            }
        }
#if (DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT > 0)
        for (; iloop < ENTRY_STORAGE_NUM; iloop++)
        {
            for (DemMemDestindex = 0; DemMemDestindex < DEM_MEM_DEST_TOTAL_NUM; DemMemDestindex++)
            {
                if (DemMemDestCfg[DemMemDestindex].ExtId == DEM_DTC_ORIGIN_PERMANENT_MEMORY)
                {
                    DemMemDestCfg[DemMemDestindex].EntryList[iloop - DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY] =
                        DemEventMemoryEntryStorage[iloop];
                    tempEventId =
                        DemMemDestCfg[DemMemDestindex].EntryList[iloop - DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY].EventId;
                    break;
                }
            }
            if ((tempEventId != 0u) && (tempEventId <= DEM_EVENT_PARAMETER_NUM))
            {
                tempEventId = tempEventId - 1u;
                Dem_CopyInfoFromEntry(&DemEventRelateInformation[tempEventId], &DemEventMemoryEntryStorage[iloop]);
                DemMemDestInfo[DemMemDestindex].RecordNum++;
            }
            else
            {
                DemEventMemoryEntryStorage[iloop].EventId = 0u;
            }
        }
#endif
        retVal = E_OK;
    }
#endif
    blockIndex++;
    blockRef = DemNvRamBlockId[blockIndex - 1];
    (void)NvM_GetErrorStatus(blockRef, &RequestResultPtr);
    if (RequestResultPtr == NVM_REQ_OK)
    {
        Dem_MemCopy(
            &DemEventRelateInformationStorage,
            NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
            sizeof(Dem_EventRelateInformationStorageType));
        for (iloop = 0; iloop < DEM_EVENT_PARAMETER_NUM; iloop++)
        {
            DemEventRelateInformation[iloop].UdsStatus = DemEventRelateInformationStorage.UdsStatus[iloop];
#if (DEM_DEBOUNCE_COUNTER_STORAGE_NUM > 0)
            /*SWS_Dem_00674*/
            if (DemPbCfgPtr->DemDebounceCounterBasedClass[DemPbCfgPtr->DemEventParameter[iloop].AlgorithmRef]
                    .DemDebounceCounterStorage
                == TRUE)
            {
                DemDebounceCounterInfo[DemPbCfgPtr->DemEventParameter[iloop].AlgorithmIndex].InternalDebounceCounter =
                    (sint32)DemEventRelateInformationStorage.DebounceCounter[iloop];
            }
#endif
        }
#if (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON) /* req SWS_Dem_00577 */
        for (iloop = 0; iloop < DEM_OPERATION_CYCLE_NUM_BYTE; iloop++)
        {
            DemOperationCycleStatus[iloop] = DemEventRelateInformationStorage.DemOperationCycleStatus[iloop];
        }
#endif
        retVal = E_OK;
        DemDTCByOccurrenceTimeInfo.FirstDtcConfirmed = DemEventRelateInformationStorage.FirstDtcConfirmed;
        DemDTCByOccurrenceTimeInfo.FirstFailed = DemEventRelateInformationStorage.FirstFailed;
        DemDTCByOccurrenceTimeInfo.MostRecDtcConfirmed = DemEventRelateInformationStorage.MostRecDtcConfirmed;
        DemDTCByOccurrenceTimeInfo.MostRecentFailed = DemEventRelateInformationStorage.MostRecentFailed;
    }
#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    blockIndex++;
    blockRef = DemNvRamBlockId[blockIndex];
    (void)NvM_GetErrorStatus(blockRef, &RequestResultPtr);
    if (RequestResultPtr == NVM_REQ_OK)
    {
        Dem_MemCopy(
            &DemOBDDataStorage,
            NvM_BlockDescriptor[blockRef - 1u].NvmRamBlockDataAddress,
            sizeof(DemOBDDataStorageType));
#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
        IgnUpCycleCounter = DemOBDDataStorage.IgnUpCycleCounter;
#endif
        WarmUpCycleCounter = DemOBDDataStorage.WarmUpCycleCounter;
        OBDDistanceMILOn = DemOBDDataStorage.OBDDistanceMILOn;
        DistSinceDtcCleared = DemOBDDataStorage.DistSinceDtcCleared;
        OBDTimeMILOn = DemOBDDataStorage.OBDTimeMILOn;
        OBDTimeDTCClear = DemOBDDataStorage.OBDTimeDTCClear;
        ContinuousMICounter = DemOBDDataStorage.ContinuousMICounter;
        OBDB1Counter = DemOBDDataStorage.OBDB1Counter;
#if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
        MasterContinuousMICounter = DemOBDDataStorage.MasterContinuousMICounter;
#endif
        retVal = E_OK;
    }
#endif
    return retVal;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif
/*************************************************************************/
/*
 * Brief               Dem_StorageInit
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
FUNC(void, DEM_CODE) Dem_EntryInit(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 iloop = 0;
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint8 entryNum;
    while (iloop < DEM_MEM_DEST_TOTAL_NUM)
    {
        entryNum = 0;
        pEntry = DemMemDestCfg[iloop].EntryList;
        while (entryNum < DemMemDestCfg[iloop].EntryNum)
        {
            Dem_MemEntryDelete(pEntry, iloop);
            pEntry++;
            entryNum++;
        }
        iloop++;
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/
