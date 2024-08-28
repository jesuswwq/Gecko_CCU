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
**  FILENAME    : Dem_Internal.h                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : tao.yu                                                      **
**  Vendor      : i-soft                                                      **
**  DESCRIPTION : API declaration of DEM for internal                         **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

#ifndef DEM_INTERNAL_H_
#define DEM_INTERNAL_H_

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem.h"

/*******************************************************************************
**                      macros                                                **
*******************************************************************************/
/* Dem InitState Define  */
typedef enum
{
    DEM_STATE_UNINIT = 0u,
    DEM_STATE_PRE_INIT,
    DEM_STATE_INIT,
    DEM_STATE_SHUTDOWN
} Dem_StateType;

typedef enum
{
    DEM_CLEAR_LOCK = 0u,
    DEM_CLEAR_NOT_LOCK
} Dem_ClearLockStatus;

typedef struct
{
    uint16 DTCIndex;
    uint16 SaveDTCIndex;
    boolean ClearAllGroup;
    uint8 DTCGroupIndex;
    uint8 memDest;
    uint32 DTC;
    Dem_DTCFormatType DTCFormat;
    Dem_DTCFormatType SaveDTCFormat;
    Dem_DTCOriginType DTCOrigin;
    Dem_DTCOriginType SaveDTCOrigin;
    uint16 SID;
    Dem_J1939DcmSetClearFilterType DTCTypeFilter;
    uint8 node;
} Dem_ClearDTCInfoType;

typedef struct
{
    uint8 Occctr;
    uint8 AgingUpCnt;
    uint8 AgingDownCnt;
    uint8 Ovflind;
    uint8 Significance;
    uint8 CurrentFDC;
    uint8 MaxFDCSinceLastClear;
    uint8 MaxFDCDuringCurrentCycle;
    uint8 CyclesSinceLastFailed;
    uint8 CyclesSinceFirstFailed;
    uint8 FailedCycles;
    uint8 OCC6;
    uint8 OCC4;
    uint8 AgedCounter;
} Dem_InternalDataType;

typedef struct
{
    Dem_EventIdType IntId;
    uint8 Status;
    boolean FDC_Trigger;
    boolean ThisOpIsFiled;
    uint8 UdsStatus;
    uint8 OldUdsStatus;
    /* Counters */
    uint8 OccurrenceCounter; /*SWS_Dem_00011] */
    uint8 FailureCounter;
    uint8 OCC6;
    uint8 OCC4;
    uint8 AgingCounter;
    uint8 HealingCounter;
    /* Operation Cycle Counter */
    uint8 CyclesSinceFirstFailed;
    uint8 CyclesSinceLastFailed;
    boolean CycleCounterFlag;
    uint8 AgedCounter;
} Dem_EventRelateInformationType;

typedef struct
{
    uint8 CbUdsStatus;
    boolean SuppressionStatus;
} Dem_DTCGeneralStatusType;

typedef struct
{
    uint8 RecordNum;
    uint8 DisableDTCRecordUpdate[DEM_DTC_NUM_BYTE]; /* 1, Disable, 0:Enable */
    boolean OverFlow;
} Dem_MemDestInfoType;

#if (DEM_NVRAM_BLOCKID_NUM > 0)
typedef struct
{
    uint8 UdsStatus[DEM_EVENT_PARAMETER_NUM];
    sint16 DebounceCounter[DEM_EVENT_PARAMETER_NUM];
#if (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON)
    uint8 DemOperationCycleStatus[DEM_OPERATION_CYCLE_NUM_BYTE]; /*SWS_Dem_00577]*/
#endif
    Dem_EventIdType FirstFailed;
    Dem_EventIdType MostRecentFailed;
    Dem_EventIdType FirstDtcConfirmed;
    Dem_EventIdType MostRecDtcConfirmed;
} Dem_EventRelateInformationStorageType;

typedef struct
{
    uint16 IgnUpCycleCounter;
    uint8 WarmUpCycleCounter;
    uint16 OBDDistanceMILOn;
    uint16 DistSinceDtcCleared;
    uint16 OBDTimeMILOn;
    uint16 OBDTimeDTCClear;
    uint16 ContinuousMICounter;
    uint16 OBDB1Counter;
#if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
    uint16 MasterContinuousMICounter;
#endif
} DemOBDDataStorageType;
#endif /* DEM_NVRAM_BLOCKID_NUM > 0 */

typedef struct
{
    boolean Status;
    uint8 FailurePriority;
    boolean availability;
} DemComponentStatusType;

typedef struct
{
    boolean IUMPRDenStatus;
    boolean IUMPRNumStatus;
    uint16 Denominator; /*the number of times the vehicle operation conditions have been fulfilled */
    uint16 Numerator;   /*the number of times a fault could have been found*/
    uint16 General_Denominator;
} IUMPRType;

typedef struct
{
    sint32 TestResult;
    sint32 LowerLimit;
    sint32 UpperLimit;
} DTRInfoType;

typedef struct
{
    /* EventId, Status: Dem_ReportErrorStatus/Dem_SetEventStatus()*/
    Dem_EventIdType ExtId;
    Dem_EventStatusType Status;
#if ((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0))
    uint8 FFData[DEM_FREEZE_FRAME_MAX_LEN];
#endif
#if (DEM_EXTENDED_DATA_CLASS_NUM > 0)
    uint8 ExtData[DEM_EXTENDED_DATA_MAX_LEN];
#endif
} Dem_EventDataBufferType;

/* Debounce Counter Base Info Define */
typedef struct
{
    sint32 InternalDebounceCounter;
    Dem_EventStatusType CurStatus;
} Dem_DebounceCounterInfoType;

/* Debounce Time Base Info Define */
typedef struct
{
    uint64 Timeout;
    boolean Triggered;
    Dem_EventIdType IntId;
    Dem_EventStatusType CurStatus;
    boolean IsFreezing;
    Dem_EventDataBufferType Dem_EventBuffer;
} Dem_DebounceTimeInfoType;

typedef struct
{
    sint8 FDC;
    uint8 MaxFDCSinceLastClear;
    uint8 MaxFDCDuringCurrentCycle;
} FDCInfoType;

typedef struct
{
    Dem_EventIdType ExtId;
    uint8 FFData[DEM_FREEZE_FRAME_MAX_LEN];
} Dem_PreStoreFFInfoType;

/* Check Event Lock Status */
#define DEM_CHECK_ELOCK_ALL                  0xFFu
#define DEM_CHECK_ELOCK_OPCYC                0x01u
#define DEM_CHECK_ELOCK_ENABLECOND           0x02u
#define DEM_CHECK_ELOCK_DTCSETTING           0x04u
#define DEM_CHECK_ELOCK_AVAILABLE            0x08u
#define DEM_CHECK_ELOCK_COMPONENT            0x10u

#define DEM_CHECK_ELOCK_EXP_OPCYC            0xFEu
#define DEM_CHECK_ELOCK_EXP_ENABLECOND       0xFDu
#define DEM_CHECK_ELOCK_EXP_OPCYC_ENABLECOND 0xFCu

#define Dem_GetEventInternalId(ExtId)        ((ExtId)-1u)
#define Dem_GetEventExternalId(IntId)        ((IntId) + 1u)

#if (DEM_BSW_ERROR_BUFFER_SIZE > DEM_MAX_NUMBER_EVENT_ENTRY_EVENT_BUFFER)
#define DEM_EVENT_QUEUE_SIZE DEM_BSW_ERROR_BUFFER_SIZE
#else
#define DEM_EVENT_QUEUE_SIZE DEM_MAX_NUMBER_EVENT_ENTRY_EVENT_BUFFER
#endif

/* FLAGS*/
#define DEM_FLAGS_SET(_status, _val)   (_status) |= (_val)
#define DEM_FLAGS_CLR(_status, _val)   (_status) &= (uint8)(~(_val))
#define DEM_FLAGS_ISSET(_status, _val) ((_status) & (_val))

/* Status Bits Functions */
/* _p = &uint8_array[0] */
#define DEM_BITS_SET(_p, _n)                  ((_p)[((_n) >> 3u)] |= ((uint8)(1u << ((_n)&7u))))
#define DEM_BITS_CLR(_p, _n)                  ((_p)[((_n) >> 3u)] &= ((uint8)(~((uint8)(1u << ((_n)&7u))))))
#define DEM_BITS_ISSET(_p, _n)                ((_p)[((_n) >> 3u)] & ((uint8)(1u << ((_n)&7u))))

#define DEM_NUMBER_OF_READINESS_GROUPS_FOROBD 12u

/*Dem_EventRelateInformationType Status*/
#define DEM_EVENT_STATUS_DTC_SETTING        0x01u
#define DEM_EVENT_STATUS_FDC_TRIGGERED      0x02u
#define DEM_EVENT_STATUS_ENABLED_CONDICTION 0x04u
#define DEM_EVENT_STATUS_STORAGE_CONDICTION 0x08u
#define DEM_EVENT_STATUS_AVAILABLE          0x10u
#define DEM_EVENT_STATUS_TFBITCHANGE        0x20u
#define DEM_EVENT_STATUS_CONSECUTIVE_FAULT  0x40u
#define DEM_EVENT_STATUS_ACTIVE             0x80u

/* total length = priEntry + perEntry + eventdata + obddata + crc*/
#define ENTRY_STORAGE_LEN       (sizeof(Dem_EventMemEntryType))
#define ENTRY_STORAGE_NUM       (DEM_MAX_NUMBER_EVENT_ENTRY_PRIMARY + DEM_MAX_NUMBER_EVENT_ENTRY_PERMANENT)
#define TOTAL_ENTRY_STORAGE_LEN (ENTRY_STORAGE_LEN * ENTRY_STORAGE_NUM) /*(ENTRY_STORAGE_LEN * ENTRY_STORAGE_NUM)*/

/*******************************************************************************
**                      Global Variable declaration                           **
*******************************************************************************/
extern uint8 AgedFlag;

extern P2CONST(Dem_ConfigType, AUTOMATIC, DEM_CONST_PBCFG) DemPbCfgPtr;

extern VAR(boolean, AUTOMATIC) Dem_Pending;

extern VAR(Dem_StateType, AUTOMATIC) DemInitState;

extern VAR(FDCInfoType, AUTOMATIC) FDCInfo[DEM_DTC_NUM];
extern VAR(Dem_InternalDataType, AUTOMATIC) DemInternalData;
extern VAR(Dem_ClearDTCInfoType, AUTOMATIC) DemClearDTCInfo;
extern VAR(Dem_MemDestInfoType, AUTOMATIC) DemMemDestInfo[DEM_MEM_DEST_TOTAL_NUM];
extern VAR(Dem_EventRelateInformationType, AUTOMATIC) DemEventRelateInformation[DEM_EVENT_PARAMETER_NUM];
extern VAR(Dem_DTCGeneralStatusType, AUTOMATIC) DemDTCGeneralStatus[DEM_DTC_NUM];
#if (DEM_STORAGE_CONDITION_NUM > 0)
extern VAR(uint8, AUTOMATIC)
    DemStorageConditionStatus[DEM_STORAGE_CONDITION_NUM_BYTE]; /* Storage Conditions Status Define */
#endif
#if (DEM_ENABLE_CONDITION_NUM > 0)
extern VAR(uint8, AUTOMATIC)
    DemEnableConditionStatus[DEM_ENABLE_CONDITION_NUM_BYTE]; /* Enable Conditions Status Define */
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
extern VAR(Dem_DebounceTimeInfoType, AUTOMATIC) DemDebounceTimerInfo[DEM_DEBOUNCE_TIME_BASED_EVENT_NUM];
#endif
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
extern VAR(Dem_DebounceCounterInfoType, AUTOMATIC) DemDebounceCounterInfo[DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM];
#endif
#if (DEM_NVRAM_BLOCKID_NUM > 0)
extern VAR(boolean, AUTOMATIC) DemAgingStorageTrigger;
#endif
#if (DEM_INDICATOR_NUM > 0)
extern VAR(Dem_IndicatorStatusType, AUTOMATIC) DemWIRStatus[DEM_INDICATOR_NUM];
#endif
#if (DEM_COMPONENT_NUM > 0)
extern VAR(DemComponentStatusType, AUTOMATIC) DemComponentStatus[DEM_COMPONENT_NUM];
#endif
#if (DEM_RATIO_NUM > 0)
extern IUMPRType IUMPRValue[DEM_RATIO_NUM];
#endif

extern VAR(boolean, AUTOMATIC) DemDTCStatusChangedInd;

extern VAR(uint8, AUTOMATIC) DemOperationCycleStatus[DEM_OPERATION_CYCLE_NUM_BYTE]; /* OperationCycleStatus */

extern VAR(Dem_ClearLockStatus, AUTOMATIC) DemClearDTCLock;

#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)

extern Dem_IndicatorStatusType OBDMilStatus;
extern uint16 OBDDistanceMILOn;
extern uint16 OBDTimeMILOn;
extern uint16 OBDTimeDTCClear;
extern uint16 DistSinceDtcCleared;
extern uint16 IgnUpCycleCounter;
extern uint16 OBDDistanceMILLastOn;
extern uint16 OBDTimeMILLastOn;
extern uint16 OBDDistanceDTCClear;
extern uint16 OBDTimeDTCLastClear;

extern uint8 WarmUpCycleCounter;

extern boolean CurrentPTOStatus;

extern uint16 ContinuousMICounter;
#if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
extern uint16 MasterContinuousMICounter;
#endif
extern uint16 OBDB1Counter;

#endif

extern VAR(uint8, AUTOMATIC) DemClearNonvolatileOK;

extern VAR(uint8, AUTOMATIC) DemAgingCycle;

extern VAR(boolean, AUTOMATIC) DemClearNonvolatile;

#if ((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0))
#if (DEM_MAX_NUMBER_PRESTORED_FF > 0)

extern VAR(Dem_PreStoreFFInfoType, AUTOMATIC) DemPreStoreFFInfo[DEM_MAX_NUMBER_PRESTORED_FF];

#endif
#endif

/*******************************************************************************
**                      Global Function declaration                           **
*******************************************************************************/
/*************************************************************************/
/*
 * Brief               MemSet
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Val && Size
 * Param-Name[out]     none
 * Param-Name[in/out]  Dest
 * Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_MemSet(P2VAR(uint8, AUTOMATIC, DEM_VAR) Dest, uint8 Val, uint32 Size);

extern FUNC(void, DEM_CODE)
    Dem_EventQueueAddDebounceFailed(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent);

FUNC(void, DEM_CODE) Dem_EventQueueAddDebouncePassed(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent);

/*************************************************************************/
/*
 * Brief               MemCopy
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Src && Size
 * Param-Name[out]     Dest
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE)
    Dem_MemCopy(P2VAR(void, AUTOMATIC, DEM_VAR) Dest, P2CONST(void, AUTOMATIC, DEM_VAR) Src, uint32 Size);

/*************************************************************************/
/*
 * Brief               CheckCondictionFulfilled
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      cond && group && len
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              boolean
 */
/*************************************************************************/

extern FUNC(boolean, DEM_CODE) Dem_CheckCondictionFulfilled(
    P2CONST(uint8, AUTOMATIC, DEM_VAR) cond,
    P2CONST(uint8, AUTOMATIC, DEM_VAR) group,
    uint8 len);

#if (DEM_DTC_ATTRIBUTES_NUM > 0)
/*************************************************************************/
/*
 * Brief               Get EventDTCAttributesCfg
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              const Dem_DTCAttributesType*
 */
/*************************************************************************/

extern FUNC(P2CONST(Dem_DTCAttributesType, AUTOMATIC, DEM_CONST), DEM_CODE)
    Dem_EventDTCAttributesCfg(Dem_EventIdType IntId);

#else
#define Dem_EventDTCAttributesCfg(x) NULL_PTR
#endif
/*************************************************************************/
/*
 * Brief               GetInternalMemDest
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTCOrigin
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              uint8
 */
/*************************************************************************/

extern FUNC(uint8, DEM_CODE) Dem_GetInternalMemDest(Dem_DTCOriginType DTCOrigin);

/*************************************************************************/
/*
 * Brief               Dem_GetEventIdByDTC
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTC
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Dem_EventIdType
 */
/*************************************************************************/

extern FUNC(Dem_EventIdType, DEM_CODE) Dem_GetEventIdByDTC(uint32 DTC);

/*************************************************************************/
/*
 * Brief               Dem_SetOccurrenceEvent
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && Status
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_SetOccurrenceEvent(Dem_EventIdType IntId, uint8 Status);

/*************************************************************************/
/*
 * Brief               Dem_ClearDTCProcess
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_ClearDTCProcess(void);

/*************************************************************************/
/*
 * Brief               Dem_DcmInit
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_DcmInit(void);

/*************************************************************************/
/*
 * Brief               BRIEF DESCRIPTION
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE)
    Dem_TriggerOnEventStatus(Dem_EventIdType IntId, Dem_UdsStatusByteType OldStatus, Dem_UdsStatusByteType NewStatus);

/*************************************************************************/
/*
 * Brief               Dem_GetEventDTC
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && DTCFormat
 * Param-Name[out]     DTC
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE)
    Dem_GetEventDTC(Dem_EventIdType IntId, Dem_DTCFormatType DTCFormat, P2VAR(uint32, AUTOMATIC, DEM_VAR) DTC);

/*************************************************************************/
/*
 * Brief               BRIEF DESCRIPTION
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTC && DTCFormat
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              DTC Index
 */
/*************************************************************************/

extern FUNC(uint16, DEM_CODE) Dem_GetDTCIndex(uint32 DTC, Dem_DTCFormatType DTCFormat);

/*************************************************************************/
/*
 * Brief               GetDTCGroupIndex
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant/Non Reentrant
 * Param-Name[in]      Id
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              DTCGroupIndex
 */
/*************************************************************************/
#if (DEM_GROUP_OF_DTC_NUM > 0)

extern FUNC(uint8, DEM_CODE) Dem_GetDTCGroupIndex(uint32 Id);

#endif

/*************************************************************************/
/*
 * Brief               Dem_ResetDemClearDTCInfo
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant/Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              DTCGroupIndex
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_ResetDemClearDTCInfo(void);

/*************************************************************************/
/*
 * Brief               Dem_UpdateInternalData
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_UpdateInternalData(uint16 IntId);

#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
/*************************************************************************/
/*
 * Brief               Clear the OBD Information on clearing dtc.
 * ServiceId           Internal Function
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_ClearOBDInfo(void);

#endif

#if (DEM_J1939_SUPPORT == STD_ON)
/*************************************************************************/
/*
 * Brief               Dem_DcmInit
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_J1939Init(void);

#endif /*#if (DEM_J1939_SUPPORT == STD_ON)*/

/*******************************************************************************
**                      EventDebounce                                         **
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

extern FUNC(void, DEM_CODE) Dem_DebounceInit(void);

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

extern FUNC(void, DEM_CODE) Dem_DebounceReset(Dem_EventIdType IntId);

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

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_GetInteralFDC(Dem_EventIdType IntId, P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter);

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

extern FUNC(Dem_EventStatusType, DEM_CODE)
    Dem_DebounceProcess(CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer);

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

extern FUNC(void, DEM_CODE) Dem_DebounceFreeze(Dem_EventIdType IntId);

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

extern FUNC(void, DEM_CODE) Dem_DebounceTimerMain(void);

#else
#define Dem_DebounceFreeze(x)
#define Dem_DebounceTimerMain()
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

extern FUNC(void, DEM_CODE) Dem_UpdateFDC(Dem_EventIdType IntId);

#if ((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0))
/*************************************************************************/
/*
 * Brief               Dem_GetFreezeFrame
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     pBuffer
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(void, DEM_CODE) Dem_GetFreezeFrame(Dem_EventIdType IntId, P2VAR(uint8, AUTOMATIC, DEM_VAR) pBuffer);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
/*************************************************************************/
/*
 * Brief               Dem_CheckFreezeFrameIsStorage
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && Trigger
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/*************************************************************************/

extern FUNC(boolean, DEM_CODE) Dem_CheckFreezeFrameIsStorage(
#if (                                                                        \
    (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED) \
    && (DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0))
    Dem_EventIdType IntId,
    uint8 Trigger
#else
    void
#endif
);

/*************************************************************************/
/*
 * Brief               Dem_FreezeFrameStorage
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && pEventBuffer && Trigger
 * Param-Name[out]     None
 * Param-Name[in/out]  pEntry
 * Return              None
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_FreezeFrameStorage(
    Dem_EventIdType IntId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer,
    uint8 Trigger);

/*************************************************************************/
/*
 * Brief               Dem_FreezeFrameGetFromEntry
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEntry && RecordNum && Did
 * Param-Name[out]     None
 * Param-Name[in/out]  pBuffer && BufSize
 * Return              Std_ReturnType
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_FreezeFrameGetFromEntry(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry,
    uint8 RecordNum,
    uint16 Did,
    P2VAR(uint8, AUTOMATIC, DEM_VAR) pBuffer,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint16* BufSize);

/*************************************************************************/
/*
 * Brief               Dem_FreezeFrameGetByRecordNum
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEntry && RecordNum
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Dem_FreezeFrameInfoType*
 */
/*************************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(P2VAR(Dem_FreezeFrameInfoType, AUTOMATIC, DEM_VAR), DEM_CODE)
    Dem_FreezeFrameGetByRecordNum(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry, uint8 RecordNum);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
#if (DEM_MAX_NUMBER_PRESTORED_FF > 0)
/*************************************************************************/
/*
 * Brief               Dem_FreezeFrameInit
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_FreezeFrameInit(void);

/*************************************************************************/
/*
 * Brief               Dem_PreStoreFF
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ExtId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_PreStoreFF(Dem_EventIdType ExtId);

/*************************************************************************/
/*
 * Brief               Dem_ClearPreStoreFF
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ExtId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPreStoreFF(Dem_EventIdType ExtId);

#else
#define Dem_FreezeFrameInit()
#define Dem_PreStoreFF(x)      E_NOT_OK
#define Dem_ClearPreStoreFF(x) E_OK
#endif

#if (DEM_MAX_NUMBER_PRESTORED_FF > 0)
/*************************************************************************/
/*
 * Brief               Dem_PreStoreFFGet
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ExtId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Dem_PreStoreFFInfoType*
 */
/*************************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(P2VAR(Dem_PreStoreFFInfoType, AUTOMATIC, DEM_VAR), DEM_CODE) Dem_PreStoreFFGet(Dem_EventIdType ExtId);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
#endif

/*************************************************************************/
/*
 * Brief               Dem_FreezeFrameCopy
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && pEventBuffer
 * Param-Name[out]     pFFBuffer
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

FUNC(void, DEM_CODE)
Dem_FreezeFrameCopy(
    Dem_EventIdType IntId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DEM_VAR) pFFBuffer,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer
#if (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
    ,
    uint8 Trigger
#endif
);

#endif
/*******************************************************************************
**                      OBD                                                   **
*******************************************************************************/
/*************************************************************************/
/*
 * Brief               Init the OBD related data.
 * ServiceId           Internal Function
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_OBDInit(void);

/*************************************************************************/
/*
 * Brief               Update the Current OBD Mil Status.
 * ServiceId           Internal Function
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

FUNC(void, DEM_CODE) Dem_UpdateOBDMilStatus(uint8 indicatorRef, uint16 IntID);

#if (DEM_DTR_NUM > 0)
/*************************************************************************/
/*
 * Brief               Init the IUMPR.
 * ServiceId           Internal Function
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

FUNC(void, DEM_CODE) Dem_DTRInit(void);

#endif

#if (DEM_RATIO_NUM > 0)
/*************************************************************************/
/*
 * Brief               Init the IUMPR.
 * ServiceId           Internal Function
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

FUNC(void, DEM_CODE) Dem_IUMPRInit(void);

#endif

#if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) || (DEM_J1939_SUPPORT == STD_ON))
/*************************************************************************/
/*
 * Brief               Calculate the OBD related data.
 * ServiceId           Internal Function
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

FUNC(void, DEM_CODE) Dem_CalOBDRelatedValue(uint8 OperationId);

#endif

#if (DEM_DTR_NUM > 0)
/*************************************************************************/
/*
 * Brief               Clear DTRInfo By Clear Command
 * ServiceId           Internal Function
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_ClearDTRInfoByEventID(Dem_EventIdType IntId);

/*************************************************************************/
/*
 * Brief               Clear DTRInfo By Clear Command
 * ServiceId           Internal Function
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_ClearDTRInfoByDTRID(uint16 DTRID);

#endif

#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
/*************************************************************************/
/*
 * Brief               Get the Current Distance Information.
 * ServiceId           Internal Function
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

extern FUNC(uint16, DEM_CODE) Dem_ReadDistanceInformation(void);

/*************************************************************************/
/*
 * Brief               Get the Current Time Since Engine Start.
 * ServiceId           Internal Function
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

extern FUNC(uint16, DEM_CODE) Dem_ReadTimeInformation(void);

#endif
/*******************************************************************************
**                      EventQueue                                            **
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

extern FUNC(void, DEM_CODE) Dem_EventQueueInit(void);

/*************************************************************************/
/*
 * Brief               Dem_EventQueueAdd
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ExtId && Status
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_EventQueueAdd(Dem_EventIdType ExtId, Dem_EventStatusType Status);

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

extern FUNC(void, DEM_CODE) Dem_EventQueueProcess(void);

/*******************************************************************************
**                      EventMemory                                           **
*******************************************************************************/
/*************************************************************************/
/*
 *  Brief               Dem_EventMemInit
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Non Reentrant
 *  Param-Name[in]      none
 *  Param-Name[out]     none
 *  Param-Name[in/out]  none
 *  Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_EventMemInit(Std_ReturnType NvmResult);

/*************************************************************************/
/*
 *  Brief               Dem_GetEventInfo
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      IntId
 *  Param-Name[out]     none
 *  Param-Name[in/out]  none
 *  Return              Dem_EventRelateInformationType*
 */
/*************************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR), DEM_CODE)
    Dem_GetEventInfo(Dem_EventIdType IntId);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
/*************************************************************************/
/*
 *  Brief               Dem_EventTestFailed
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      IntId && pEventBuffer
 *  Param-Name[out]     none
 *  Param-Name[in/out]  none
 *  Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE)
    Dem_EventTestFailed(Dem_EventIdType IntId, CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer);

/*************************************************************************/
/*
 *  Brief               Dem_UpdateCombinedDtcStatus
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      IntId
 *  Param-Name[out]     None
 *  Param-Name[in/out]  None
 *  Return              None
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_UpdateCombinedDtcStatus(Dem_EventIdType IntId);

/*************************************************************************/
/*
 *  Brief               Dem_ResponseOnDtcStatusChange
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      IntId
 *  Param-Name[out]     None
 *  Param-Name[in/out]  None
 *  Return              None
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_ResponseOnDtcStatusChange(Dem_EventIdType IntId);

/*************************************************************************/
/*
 *  Brief               Dem_EventTestPassed
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      IntId && pEventBuffer
 *  Param-Name[out]     none
 *  Param-Name[in/out]  none
 *  Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE)
    Dem_EventTestPassed(Dem_EventIdType IntId, CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer);

/*************************************************************************/
/*
 *  Brief               Dem_EventRetention
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      IntId && pEventBuffer
 *  Param-Name[out]     none
 *  Param-Name[in/out]  none
 *  Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE)
    Dem_EventRetention(Dem_EventIdType IntId, CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer);

/*************************************************************************/
/*
 *  Brief               Dem_CheckEventMemEntryExistsAlready
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      IntId
 *  Param-Name[out]     none
 *  Param-Name[in/out]  none
 *  Return              Dem_EventMemEntryType*
 */
/*************************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR), DEM_CODE)
    Dem_CheckEventMemEntryExistsAlready(Dem_EventIdType IntId);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
/*************************************************************************/
/*
 *  Brief               Dem_MemEntryGet
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      ExtId && memDest
 *  Param-Name[out]     none
 *  Param-Name[in/out]  none
 *  Return              Dem_EventMemEntryType*
 */
/*************************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR), DEM_CODE)
    Dem_MemEntryGet(Dem_EventIdType ExtId, uint8 memDest);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
/*************************************************************************/
/*
 *  Brief               Dem_MemEntryDelete
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      none
 *  Param-Name[out]     none
 *  Param-Name[in/out]  pEntry
 *  Return              none
 */
/*************************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(void, DEM_CODE) Dem_MemEntryDelete(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry, uint8 memDest);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
/*************************************************************************/
/*
 *  Brief               Dem_OperationCycleStart
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      OpId && IsRestart
 *  Param-Name[out]     none
 *  Param-Name[in/out]  none
 *  Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_OperationCycleStart(uint8 OpId, boolean IsRestart);

/*************************************************************************/
/*
 *  Brief               Dem_OperationCycleEnd
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      OpId
 *  Param-Name[out]     none
 *  Param-Name[in/out]  none
 *  Return              none
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_OperationCycleEnd(uint8 OpId);

#if (DEM_NVRAM_BLOCKID_NUM > 0)
/*************************************************************************/
/*
 *  Brief               Dem_IntWriteNvRAM
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      None
 *  Param-Name[out]     None
 *  Param-Name[in/out]  pEvent
 *  Return              None
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_IntWriteNvRAM(void);

/*************************************************************************/
/*
 *  Brief               Dem_IntReadNvRAM
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      None
 *  Param-Name[out]     None
 *  Param-Name[in/out]  pEvent
 *  Return              None
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_IntReadNvRAM(void);

#endif

/*************************************************************************/
/*
 *  Brief               Dem_StorageInit
 *  ServiceId           --
 *  Sync/Async          Synchronous
 *  Reentrancy          Reentrant
 *  Param-Name[in]      None
 *  Param-Name[out]     None
 *  Param-Name[in/out]  None
 *  Return              None
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_EntryInit(void);

#if (DEM_EXTENDED_DATA_CLASS_NUM > 0)
/*************************************************************************/
/*
 * Brief               Dem_GetExtendedData
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId
 * Param-Name[out]     pBuffer
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(void, DEM_CODE) Dem_GetExtendedData(Dem_EventIdType IntId, P2VAR(uint8, AUTOMATIC, DEM_VAR) pBuffer);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
/*************************************************************************/
/*
 * Brief               Dem_ExtendedDataGetFromEntry
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEntry && RecordNum
 * Param-Name[out]     pBuffer
 * Param-Name[in/out]  BufSize
 * Return              pBuffer
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_ExtendedDataGetFromEntry(
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry,
    uint8 RecordNum,
    P2VAR(uint8, AUTOMATIC, DEM_VAR) pBuffer,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint16* BufSize);

/*************************************************************************/
/*
 * Brief               Dem_CheckExtendedDataIsStorage
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && Trigger
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/*************************************************************************/

extern FUNC(boolean, DEM_CODE) Dem_CheckExtendedDataIsStorage(Dem_EventIdType IntId, uint8 Trigger);

/*************************************************************************/
/*
 * Brief               Dem_ExtendedDataStorage
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      IntId && pEventBuffer && Trigger
 * Param-Name[out]     pEntry
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_ExtendedDataStorage(
    Dem_EventIdType IntId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer,
    uint8 Trigger);

#endif

/*************************************************************************/
/*
 * Brief               Dem_Clear
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      memDest && pEntry && pEvent
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(void, DEM_CODE) Dem_Clear(P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent, uint8 memDest);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
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

extern FUNC(void, DEM_CODE) Dem_EventDataStorageTrigger(
    Dem_EventIdType IntId,
    CONSTP2VAR(Dem_EventDataBufferType, AUTOMATIC, DEM_VAR) pEventBuffer,
    uint8 Trigger);

#else
#define Dem_EventDataStorageTrigger(a, b, c)
#endif

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
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR), DEM_CODE)
    Dem_MemEntryAllocate(Dem_EventIdType IntId, uint8 memDest);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
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
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
extern FUNC(P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR), DEM_CODE)
    Dem_MirrorEntryAllocate(Dem_EventIdType IntId, uint8 memDest);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
#if (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
/*************************************************************************/
/*
 * Brief               Dem_CheckEventAllIndicator
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEvent
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/*************************************************************************/
extern FUNC(boolean, DEM_CODE) Dem_CheckEventAllIndicator(uint16 IntId);
#endif
/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/

#endif
