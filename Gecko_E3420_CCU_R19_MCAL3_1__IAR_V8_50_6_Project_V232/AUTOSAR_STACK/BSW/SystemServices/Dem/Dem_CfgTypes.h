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
**  FILENAME    : Dem_CfgTypes.h                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : tao.yu                                                      **
**  Vendor      : i-soft                                                      **
**  DESCRIPTION : CfgType definitions of DEM                                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef DEM_CFGTYPES_H_
#define DEM_CFGTYPES_H_

/*******************************************************************************
**                           Include Section                                  **
*******************************************************************************/
#include "Rte_Dem.h"
#include "Dem_Cfg.h"
/*******************************************************************************
 *                          General Configuration                              **
 *******************************************************************************/
typedef Std_ReturnType (*Dem_ReadDataFncType)(uint8* Buffer, uint16 BufSize);

typedef Std_ReturnType (*DataServicesType)(uint8* Buffer);

/*******************************************************************************
 *                             Global Data Types                               **
 *******************************************************************************/
/* DemGeneral/DemOperationCycle 1-256 */
typedef struct
{
    /* DemOperationCycleAutomaticEnd Range: true or false */
    const boolean DemOperationCycleAutomaticEnd;

    /* DemOperationCycleAutostart Range: true or false */
    const boolean DemOperationCycleAutostart;

    /* DemOperationCycleType type:
    Enum{
    DEM_OPCYC_IGNITION
    DEM_OPCYC_OBD_DCY
    DEM_OPCYC_OTHER
    DEM_OPCYC_POWER
    DEM_OPCYC_TIME
    DEM_OPCYC_WARMUP
    } */
    const uint8 DemOperationCycleType;
} Dem_OperationCycleType;

#if (DEM_OPERATION_CYCLE_NUM > 0)

extern CONST(Dem_OperationCycleType, AUTOMATIC) DemOperationCycle[DEM_OPERATION_CYCLE_NUM];

#endif

#if (DEM_ENABLE_CONDITION_NUM > 0)

/* DemGeneral/DemEnableCondition 0-255 */
extern CONST(uint8, AUTOMATIC) DemEnableCondition[DEM_ENABLE_CONDITION_NUM_BYTE];

#endif

#if (DEM_ENABLE_CONDITION_GROUP_NUM > 0)

/* DemGeneral/DemEnableConditionGroup 0-255 */
extern CONST(uint8, AUTOMATIC)
    DemEnableConditionGroup[DEM_ENABLE_CONDITION_GROUP_NUM][DEM_ENABLE_CONDITION_NUM_BYTE]; /*[row] [column]*/

#endif

#if (DEM_STORAGE_CONDITION_NUM > 0)
/* DemGeneral/DemStorageCondition 0-255 */
typedef struct
{
    /* DemStorageConditionReplacementEventRef Reference: DemEventParameter MULTI:0-1*/
    const uint16 DemStorageConditionReplacementEventRef;

    /* DemStorageConditionStatus Range: true or false */
    const boolean DemStorageConditionStatus;
} Dem_StorageConditionType;

extern const Dem_StorageConditionType DemStorageCondition[DEM_STORAGE_CONDITION_NUM];

#endif

#if (DEM_STORAGE_CONDITION_GROUP_NUM > 0)

/* DemGeneral/DemStorageConditionGroup 0-255 */
extern CONST(uint8, AUTOMATIC)
    DemStorageConditionGroup[DEM_STORAGE_CONDITION_GROUP_NUM][DEM_STORAGE_CONDITION_NUM_BYTE]; /*[row] [column]*/

#endif

/*******************************************************************************
 *                          FreezeFrame Configuration                          **
 *******************************************************************************/
/* DemGeneral/DemPidClass 0-0xFFFF */
typedef struct
{
    const uint16 DemPidIdentifier;
    const uint16 StartIndex;
    const uint8 RefNum;
    const uint8 DataSize; /*added by yt  means the total size of dataelement*/
} Dem_PidClassType;

#if (DEM_FREEZE_FRAME_CLASS_NUM > 0)
/* DemGeneral/DemFreezeFrameClass 0-65535 */
typedef struct
{
    const uint16 DataSize;
    const uint16 StartIndex;
    const uint8 RefNum;
} Dem_FreezeFrameClassType;

extern CONST(Dem_FreezeFrameClassType, AUTOMATIC) DemFreezeFrameClass[DEM_FREEZE_FRAME_CLASS_NUM];

#if (DEM_DID_CLASS_NUM > 0)
/* DemGeneral/DemDidClass 0-0xFFFF */
typedef struct
{
    const uint16 DemDidIdentifier;
    const uint16 StartIndex;
    const uint8 RefNum;
    const uint8 DataSize; /*added by yt  means the total size of dataelement*/
} Dem_DidClassType;

extern CONST(Dem_DidClassType, AUTOMATIC) DemDidClass[DEM_DID_CLASS_NUM];

extern CONST(uint16, AUTOMATIC) DemDidClassRef[DEM_DID_CLASS_REF_TOTAL_NUM];

#endif
#endif

#if (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0)
typedef struct
{
    const uint16 DataSize;
    const uint16 StartIndex;
    const uint8 RefNum;
} Dem_J1939FreezeFrameClassType;

extern CONST(Dem_J1939FreezeFrameClassType, AUTOMATIC) DemJ1939FreezeFrameClass[DEM_J1939_FREEZE_FRAME_CLASS_NUM];

#if (DEM_SPN_CLASS_NUM > 0)
/* DemGeneral/DemDidClass 0-0xFFFF */
typedef struct
{
    const uint16 DemSPNIdentifier;
    const uint16 StartIndex;
    const uint8 DataSize; /*added by yt  means the total size of dataelement*/
} Dem_SPNClassType;

extern CONST(Dem_SPNClassType, AUTOMATIC) DemSPNClass[DEM_SPN_CLASS_NUM];

extern CONST(uint16, AUTOMATIC) DemSPNClassRef[DEM_SPN_CLASS_REF_TOTAL_NUM];

#endif
#endif

#if (DEM_FREEZE_FRAME_RECORD_CLASS_NUM > 0)
/* DemGeneral/DemFreezeFrameRecordClass 0-255 */
typedef struct
{
    /* DemFreezeFrameRecordNumber Range:0~254 */
    const uint8 DemFreezeFrameRecordNumber;

    /* DemFreezeFrameRecordTrigger type:
    Enum{
    DEM_TRIGGER_ON_CONFIRMED
    DEM_TRIGGER_ON_FDC_THRESHOLD
    DEM_TRIGGER_ON_PENDING
    DEM_TRIGGER_ON_TEST_FAILED
    } */
    const uint8 DemFreezeFrameRecordTrigger;

    /* DemFreezeFrameRecordUpdate type:
    Enum{
    DEM_UPDATE_RECORD_NO
    DEM_UPDATE_RECORD_YES
    } */
    const uint8 DemFreezeFrameRecordUpdate;
} Dem_FreezeFrameRecordClassType;

extern CONST(Dem_FreezeFrameRecordClassType, AUTOMATIC) DemFreezeFrameRecordClass[DEM_FREEZE_FRAME_RECORD_CLASS_NUM];

#endif

#if (DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM > 0)
/* DemGeneral/DemFreezeFrameRecNumClass 0-255 */
typedef struct
{
    /* DemFreezeFrameRecordClassRef 1-254 */
    const uint16 StartIndex;
    const uint8 RefNum;
} Dem_FreezeFrameRecNumClassType;

/* DemFreezeFrameRecNumClass 0-255 */

extern CONST(Dem_FreezeFrameRecNumClassType, AUTOMATIC) DemFreezeFrameRecNumClass[DEM_FREEZE_FRAME_REC_NUM_CLASS_NUM];

extern CONST(uint8, AUTOMATIC) DemFreezeFrameRecordClassRef[DEM_FREEZE_FRAME_RECORD_CLASS_REF_TOTAL_NUM];

#endif

/*******************************************************************************
 *                          ExtendedData Configuration                         **
 *******************************************************************************/

#if (DEM_EXTENDED_DATA_RECORD_CLASS_NUM > 0)
/* DemGeneral/DemExtendedDataRecordClass 0-253 */
typedef struct
{
    /* DemExtendedDataRecordNumber Range:1~239 */
    const uint8 DemExtendedDataRecordNumber;

    /* DemExtendedDataRecordTrigger type:
     Enum{
     DEM_TRIGGER_ON_CONFIRMED
     DEM_TRIGGER_ON_FDC_THRESHOLD
     DEM_TRIGGER_ON_MIRROR
     DEM_TRIGGER_ON_PASSED
     DEM_TRIGGER_ON_PENDING
     DEM_TRIGGER_ON_TEST_FAILED
     } */
    const uint8 DemExtendedDataRecordTrigger;

    /* DemExtendedDataRecordUpdate type:
     Enum{
     DEM_UPDATE_RECORD_NO
     DEM_UPDATE_RECORD_YES
     } */
    const uint8 DemExtendedDataRecordUpdate;

    /* DemDataElementClassRef Reference: DemDataElementClass MULTI:1-255*/
    const uint16 DemDataElementClassIndex;
    const uint8 DemDataElementClassNum;
    const uint8 DataSize; /*total size of all DataElementClass*/
} Dem_ExtendedDataRecordClassType;

/* DemGeneral/DemExtendedDataClass 0-* */
typedef struct
{
    /* DemExtendedDataRecordClassRef 1-253 */
    const uint16 StartIndex;
    const uint8 RefNum;
} Dem_ExtendedDataClassType;

extern CONST(Dem_ExtendedDataRecordClassType, AUTOMATIC) DemExtendedDataRecordClass[DEM_EXTENDED_DATA_RECORD_CLASS_NUM];

#endif

#if (DEM_EXTENDED_DATA_CLASS_NUM > 0)

extern CONST(Dem_ExtendedDataClassType, AUTOMATIC) DemExtendedDataClass[DEM_EXTENDED_DATA_CLASS_NUM];

extern CONST(uint8, AUTOMATIC) DemExtendedDataRecordClassRef[DEM_EXTENDED_DATA_RECORD_CLASS_REF_TOTAL_NUM];

#endif

/*******************************************************************************
 *                          DTC Configuration                                  **
 *******************************************************************************/
/* DemGeneral/DemCallbackDTCStatusChanged 0..* */
typedef Std_ReturnType (
    *Dem_TriggerOnDTCStatusType)(uint32 DTC, Dem_UdsStatusByteType DTCStatusOld, Dem_UdsStatusByteType DTCStatusNew);

#if (DEM_CALLBACK_DTC_STATUS_CHANGED_NUM > 0)

extern CONST(Dem_TriggerOnDTCStatusType, AUTOMATIC) DemCallbackDTCStatusChanged[DEM_CALLBACK_DTC_STATUS_CHANGED_NUM];

#endif

#if (DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM > 0)

extern CONST(Dem_TriggerOnDTCStatusType, AUTOMATIC)
    DemCallbackObdDTCStatusChanged[DEM_CALLBACK_OBD_DTC_STATUS_CHANGED_NUM];

#endif

#if (DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM > 0)

extern CONST(Dem_TriggerOnDTCStatusType, AUTOMATIC)
    DemCallbackJ1939DTCStatusChanged[DEM_CALLBACK_J1939_DTC_STATUS_CHANGED_NUM];

#endif

#if (DEM_GROUP_OF_DTC_NUM > 0)
/* DemGeneral/DemGroupOfDTC 0-255 */

extern CONST(uint32, AUTOMATIC) DemGroupOfDTC[DEM_GROUP_OF_DTC_NUM];

#endif

#if (DEM_DTC_NUM > 0)
/* DemConfigSet/DemDTC 0-65535 */
typedef struct
{
    /* DemDtcValue Range:1~16777214 */
    const uint32 DemDtcValue;
    /* DemDTCAttributesRef Reference: DemDTCAttributes MULTI:1-1*/
    const uint16 DemDTCAttributesRef;
    /*Reference to DemObdDTC MULTI:0-1 */
    const uint16 DemObdDTCRef;

    const Dem_DTCKindType DTCKind;
    /* DemDTCFunctionalUnit Range:0~255 */
    const uint8 DemDTCFunctionalUnit;
    /* DemDTCSeverity type:
     Enum{
     DEM_SEVERITY_CHECK_AT_NEXT_HALT
     DEM_SEVERITY_CHECK_IMMEDIATELY
     DEM_SEVERITY_MAINTENANCE_ONLY
     DEM_SEVERITY_NO_SEVERITY
     } */
    const uint8 DemDTCSeverity; /*TODO: shall include the WWHOBDDTCCLASS info?*/
    /* DemDTCGroupRef */
    const uint8 GroupRef; /* DTC GroupIndex added by yt */

    const uint8 DemWWHOBDDTCClass;
} Dem_DTCType;

typedef struct
{
    const boolean DemConsiderPtoStatus;
    const uint16 DemDtcValue;
    const uint32 DemJ1939DTCValue;
    const uint8 DemEventOBDReadinessGroup;
} DemObdDTCType;

typedef struct
{
#if (DEM_J1939_NODEID_MAX_NUM > 0)
    const uint8 NodeIDRef[DEM_J1939_NODEID_MAX_NUM];
#endif
    const uint8 NodeNum;
} J1939NodeType;
#endif

#if (DEM_DTC_ATTRIBUTES_NUM > 0)
/* DemConfigSet/DemDTCAttributes 0-65535 */
typedef struct
{
    /* DemAgingAllowed Range: true or false */
    const boolean DemAgingAllowed;

    /* DemAgingCycleRef Reference: DemOperationCycle MULTI:0-1*/
    const uint8 DemAgingCycleRef;

    /* DemAgingCycleCounterThreshold Range:1~256 */
    const uint8 DemAgingCycleCounterThreshold;

    /* DemAgingCycleCounterThresholdForTFSLC Range:1~256 */
    const uint8 DemAgingCycleCounterThresholdForTFSLC;

    /* DemDTCPriority Range:1~256 */
    const uint8 DemDTCPriority;

    /* DemEventMemoryEntryFdcThresholdStorageValue Range:1~126 */
    const uint8 DemEventMemoryEntryFdcThresholdStorageValue;

#if (DEM_TYPE_OF_FREEZE_FRAME_RECORD_NUMERATION == DEM_FF_RECNUM_CONFIGURED)
    /* DemFreezeFrameRecNumClassRef Reference: DemFreezeFrameRecNumClass MULTI:0-1
     */
    const uint8 DemFreezeFrameRecNumClassRef;
#else
    /* DemMaxNumberFreezeFrameRecords Range:0~255 */
    const uint8 DemMaxNumberFreezeFrameRecords;
#endif

    /* DemImmediateNvStorage Range: true or false */
    const boolean DemImmediateNvStorage;

    /* DemDTCSignificance type:
    Enum{
    DEM_EVENT_SIGNIFICANCE_FAULT
    DEM_EVENT_SIGNIFICANCE_OCCURRENCE
    } */
    const uint8 DemDTCSignificance;

    /* DemExtendedDataClassRef Reference: DemExtendedDataClass MULTI:0-1*/
    const uint16 DemExtendedDataClassRef;

    /* DemFreezeFrameClassRef Reference: DemFreezeFrameClass MULTI:0-1*/
    const uint16 DemFreezeFrameClassRef;

    /* DemMemoryDestinationRef ChoiceReference: TOOL shall TODO: 2 The same event shall not be configured two
     * destinations if one is not DemMirrorMemory. */
    const uint8 DemMemoryDestinationRef[DEM_MEM_DEST_MAX_NUM_OF_DTC];

    /*DemJ1939DTC_J1939NodeRef*/
    const uint8 DemJ1939DTC_J1939NodeRef;

    /*DemJ1939ExpandedFreezeFrameClassRef*/
    const uint8 DemJ1939ExpandedFreezeFrameClassRef;

    /*DemJ1939FreezeFrameClassRef*/
    const uint8 DemJ1939FreezeFrameClassRef;

    /*DemWWHOBDFreezeFrameClassRef*/
    const uint8 DemWWHOBDFreezeFrameClassRef;
} Dem_DTCAttributesType;
#endif

typedef struct
{
    /* DemIndicatorFailureCycleCounterThreshold Range:0~255 */
    const uint8 DemIndicatorFailureCycleCounterThreshold;

    /* DemIndicatorHealingCycleCounterThreshold Range:0~255 */
    const uint8 DemIndicatorHealingCycleCounterThreshold;

    /* DemIndicatorRef Reference: DemIndicator MULTI:1-1*/
    const uint8 DemIndicatorRef;

    /* DemIndicatorBehaviour type:
    Enum{
    DEM_INDICATOR_BLINKING
    DEM_INDICATOR_BLINK_CONT
    DEM_INDICATOR_CONTINUOUS
    DEM_INDICATOR_FAST_FLASH
    DEM_INDICATOR_SLOW_FLASH
    } */
    const uint8 DemIndicatorBehaviour;
} Dem_IndicatorAttributeType;

/*******************************************************************************
 *                          Indicator Configuration                            **
 *******************************************************************************/
#if (DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM > 0)
/* DemConfigSet/DemEventParameter/DemIndicatorAttribute */

extern CONST(Dem_IndicatorAttributeType, AUTOMATIC) DemIndicatorAttribute[DEM_INDICATOR_ATTRIBUTE_TOTAL_NUM];

#endif

/*******************************************************************************
 *                          Debounce Configuration                             **
 *******************************************************************************/
/* DemConfigSet/DemDebounceCounterBasedClass 0-65535 */
typedef struct
{
    /* DemDebounceCounterDecrementStepSize Range:1~32768 */
    const uint16 DemDebounceCounterDecrementStepSize;

    /* DemDebounceCounterIncrementStepSize Range:1~32767 */
    const uint16 DemDebounceCounterIncrementStepSize;

    /* DemDebounceCounterJumpDownValue Range:-32768~32767 */
    const sint16 DemDebounceCounterJumpDownValue;

    /* DemDebounceCounterJumpUpValue Range:-32768~32767 */
    const sint16 DemDebounceCounterJumpUpValue;

    /* DemDebounceCounterFailedThreshold Range:1~32767 */
    const sint16 DemDebounceCounterFailedThreshold;

    /* DemDebounceCounterPassedThreshold Range:-32768~-1 */
    const sint16 DemDebounceCounterPassedThreshold;

    /* DemDebounceCounterJumpDown Range: true or false */
    const boolean DemDebounceCounterJumpDown;

    /* DemDebounceCounterJumpUp Range: true or false */
    const boolean DemDebounceCounterJumpUp;

    /* DemDebounceCounterStorage Range: true or false */
    const boolean DemDebounceCounterStorage;

    /* DemDebounceBehavior type:
    Enum{
    DEM_DEBOUNCE_FREEZE
    DEM_DEBOUNCE_RESET
    } */
    const uint8 DemDebounceBehavior;
} Dem_DebounceCounterBasedClassType;

/* DemConfigSet/DemDebounceTimeBaseClass 0-65535 */
typedef struct
{
    /* DemDebounceTimeFailedThreshold Range:0.001~3600 */
    const uint32 DemDebounceTimeFailedThreshold;

    /* DemDebounceTimePassedThreshold Range:0.001~3600 */
    const uint32 DemDebounceTimePassedThreshold;

    /* DemDebounceBehavior type:
     Enum{
     DEM_DEBOUNCE_FREEZE
     DEM_DEBOUNCE_RESET
     } */
    const uint8 DemDebounceBehavior;
} Dem_DebounceTimeBaseClassType;

#if (DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM > 0)
/* DemConfigSet/DemEventParameter/DemDebounceAlgorithmClass/DemDebounceMonitorInternal */
typedef Std_ReturnType (*Dem_GetFDCFncType)(sint8* FDC);

extern CONST(Dem_GetFDCFncType, AUTOMATIC) DemGetFDCFncs[DEM_DEBOUNCE_MONITOR_INTERNAL_EVENT_NUM];

#endif
/*******************************************************************************
 *                          Event Configuration                                **
 *******************************************************************************/
#ifndef _DEFINED_TYPEDEF_FOR_Dem_InitMonitorReasonType_
typedef uint8 Dem_InitMonitorReasonType;
#define DEM_INIT_MONITOR_CLEAR             0x01u
#define DEM_INIT_MONITOR_RESTART           0x02u
#define DEM_INIT_MONITOR_REENABLED         0x03u
#define DEM_INIT_MONITOR_STORAGE_REENABLED 0x04u
#endif /* _DEFINED_TYPEDEF_FOR_Dem_InitMonitorReasonType_ */

#ifndef _DEFINED_TYPEDEF_FOR_Dem_IndicatorStatusType_
typedef uint8 Dem_IndicatorStatusType;
#define DEM_INDICATOR_OFF        0x00u
#define DEM_INDICATOR_CONTINUOUS 0x01u
#define DEM_INDICATOR_BLINKING   0x02u
#define DEM_INDICATOR_BLINK_CONT 0x03u
#define DEM_INDICATOR_SLOW_FLASH 0x04u
#define DEM_INDICATOR_FAST_FLASH 0x05u
#define DEM_INDICATOR_ON_DEMAND  0x06u
#define DEM_INDICATOR_SHORT      0x07u
#endif /* _DEFINED_TYPEDEF_FOR_Dem_IndicatorStatusType_ */

/* DemConfigSet/DemEventParameter/DemCallbackInitMForE */
typedef Std_ReturnType (*Dem_CallbackInitMForEType)(Dem_InitMonitorReasonType InitMonitorReason);

/* DemConfigSet/DemEventParameter/DemCallbackEventDataChanged */
typedef Std_ReturnType (*Dem_CallbackEventDataChangedType)(Dem_EventIdType EventId);

#if (DEM_CALLBACK_EVENT_STATUS_CHANGED_TOTAL_NUM > 0)
/* DemConfigSet/DemEventParameter/DemCallbackEventStatusChanged */
typedef void (*Dem_TriggerOnEventStatusType)(
    Dem_EventIdType EventId,
    Dem_UdsStatusByteType EventStatusByteOld,
    Dem_UdsStatusByteType EventStatusByteNew);

extern CONST(Dem_TriggerOnEventStatusType, AUTOMATIC)
    DemCallbackEventStatusChanged[DEM_CALLBACK_EVENT_STATUS_CHANGED_TOTAL_NUM];

#endif

typedef Std_ReturnType (*ClearEventAllowedType)(boolean* Allowed);

/* DemConfigSet/DemEventParameter/DemCallbackClearEventAllowed */
typedef struct
{
    /* DemCallbackClearEventAllowedFnc type: FunctionName */
    const ClearEventAllowedType ClearEventAllowed;
    /* DemClearEventAllowedBehavior type:
    Enum{
    DEM_NO_STATUS_BYTE_CHANGE
    DEM_ONLY_THIS_CYCLE_AND_READINESS
    } */
    const uint8 DemClearEventAllowedBehavior;
} Dem_CallbackClearEventAllowedType;

#if (DEM_CALLBACK_CLEAR_EVENT_ALLOWED_TOTAL_NUM > 0)

extern CONST(Dem_CallbackClearEventAllowedType, AUTOMATIC)
    DemCallbackClearEventAllowed[DEM_CALLBACK_CLEAR_EVENT_ALLOWED_TOTAL_NUM];

#endif

typedef Std_ReturnType (*DemComponentFailedCallbackFnc)(Dem_ComponentIdType ComponentId, boolean ComponentFailedStatus);
typedef struct
{
    const DemComponentFailedCallbackFnc DemComponentFailedCallbackFnc;
    const boolean DemComponentIgnoresPriority; /*whether the priority of events at this component shall be ignored*/
    const uint16 DemParentComponentRef;        /* parent component added by yt*/
    const uint16
        DemImmediateChildComponentRef[DEM_IMMEDITE_CHILD_COMPONENT_MAX_NUM]; /*Reference to all immediate children of
                                                                                the current component*/
} DemComponentTypes;

/* DemConfigSet/DemEventParameter 0-65535 */
typedef struct
{
    /* DemCallbackInitMForE 0-1 */
    const Dem_CallbackInitMForEType DemCallbackInitMForE;

    /* DemCallbackEventDataChanged 0-1 */
    const Dem_CallbackEventDataChangedType DemCallbackEventDataChanged;

    /* DemCallbackClearEventAllowed 0-1 */
    P2CONST(Dem_CallbackClearEventAllowedType, AUTOMATIC, DEM_CONST_PBCFG) DemCallbackClearEventAllowed;

    /* DemCallbackEventStatusChanged 0-* */
    const uint16 StatusChangedCbkStartIndex;
    const uint8 StatusChangedCbkNum;

    /* DemDTCRef Reference: DemDTC MULTI:0-1*/
    const uint16 DemDTCRef;
    /* DemDebounceAlgorithmClass 1-1 -CHOICES */
    const uint16 AlgorithmRef; /* Index Of AlgirithmClass */
    const uint16 AlgorithmIndex;
    const uint8 AlgorithmType;

    /* DemIndicatorAttribute 0-255 */
    const uint16 AttrStartIndex;
    const uint8 AttrNum;

    /* DemEventFailureCycleCounterThreshold Range:0~255 */
    const uint8 DemEventFailureCycleCounterThreshold;
    /* DemEventAvailable Range: true or false */
    const boolean DemEventAvailable;
    /* DemFFPrestorageSupported Range: true or false */
    const boolean DemFFPrestorageSupported; /*SWS_Dem_00002*/

    /* DemEventKind type:
    Enum{
    DEM_EVENT_KIND_BSW
    DEM_EVENT_KIND_SWC
    } */
    const uint8 DemEventKind;

    /* DemReportBehavior type:
    Enum{
    REPORT_AFTER_INIT
    REPORT_BEFORE_INIT
    } */
    const uint8 DemReportBehavior;

    /* DemOperationCycleRef Reference: DemOperationCycle MULTI:1-1*/
    const uint8 DemOperationCycleRef;

    /* DemEnableConditionGroupRef Reference: DemEnableConditionGroup MULTI:0-1*/
    const uint8 DemEnableConditionGroupRef;

    /* DemStorageConditionGroupRef Reference: DemStorageConditionGroup MULTI:0-1*/
    const uint8 DemStorageConditionGroupRef;

    /*DemComponentClassRef Reference: DemComponent */
    const uint16 DemComponentClassRef;

    const uint8 DemComponentPriority;

    /*The "reverence event" must refer to it self. Note: One event is only allowed
     * to be reverenced to only one group of associate events.*/
    const uint16 DemOBDGroupingAssociativeEventsRef;
} Dem_EventParameterType;

/*******************************************************************************
 *                          Memory Configuration                               **
 *******************************************************************************/
#if ((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0))
/* FreezeFrameInfo Define */
typedef struct
{
    uint8 RecordNum; /*total number = DEM_MAX_NUMBER_FF_RECORDS*/
#if (DEM_FREEZE_FRAME_MAX_LEN > 0u)
    uint8 Data[DEM_FREEZE_FRAME_MAX_LEN];
#endif
} Dem_FreezeFrameInfoType;
#endif

/* EventMemoryEntry Define */
typedef struct
{
    uint8 AbsTime;
    Dem_EventIdType EventId;
    uint8 UdsStatus;
    uint8 AgingCounter;
    uint8 HealingCounter;
    uint8 FailureCounter;
    uint8 OCC6;
    uint8 OCC4;
    uint8 OccurrenceCounter;
    /* Operation Cycle Counter */
    uint8 CyclesSinceFirstFailed;
    uint8 CyclesSinceLastFailed;
    boolean CycleCounterFlag;
    uint8 AgedCounter;
#if ((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0))
    uint8 FFNum;
    uint8 LatestFF;
    Dem_FreezeFrameInfoType FFList[DEM_MAX_NUMBER_FF_RECORDS];
#endif
#if (DEM_EXTENDED_DATA_CLASS_NUM > 0)
    uint8 ExtStatus[DEM_EXTENDED_DATA_MAX_REF_NUM_BYTE];
#if (DEM_EXTENDED_DATA_MAX_LEN > 0u)
    uint8 ExtData[DEM_EXTENDED_DATA_MAX_LEN];
#endif
#endif
} Dem_EventMemEntryType;

/* EventMemoryDest Define */
typedef struct
{
    Dem_EventMemEntryType* EntryList;
    const uint8 EntryNum;
    const Dem_DTCOriginType ExtId;
} Dem_MemDestConfigType;

#if (DEM_MEM_DEST_TOTAL_NUM > 0)

extern CONST(Dem_MemDestConfigType, AUTOMATIC) DemMemDestCfg[DEM_MEM_DEST_TOTAL_NUM];

#endif

#if (DEM_NVRAM_BLOCKID_NUM > 0)

extern CONST(uint16, AUTOMATIC) DemNvRamBlockId[DEM_NVRAM_BLOCKID_NUM];

#endif

/*************************************************************************************
                                OBD Configuration                                   **
**************************************************************************************/
#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
typedef struct
{
    /*Configuration value to define the appropriate value to PID1C "OBD
      requirements to which vehicle or engine is certified*/
    const uint8 DemOBDCompliancy;

    /*Switch to provide either Gasoline or Diesel parameters*/
    const uint8 DemOBDEngineType;

    /*Input variable for the accelerator padal information, which is assigned
      to a specific data element used as interface for the Dem-internal PID calculations. */
    const uint8 DemOBDInputAcceleratorPedalInformation;

    /*Input variable for the ambient pressure*/
    const uint8 DemOBDInputAmbientPressure;

    /*Input variable for the ambient temperature*/
    const uint8 DemOBDInputAmbientTemperature;

    /*Input variable for the distance information*/
    const uint8 DemOBDInputDistanceInformation;

    /*Input variable for the engine speed*/
    const uint8 DemOBDInputEngineSpeed;

    /*Input variable for the engine temperature*/
    const uint8 DemOBDInputEngineTemperature;

    /*Input variable for the programming event*/
    const uint8 DemOBDInputProgrammingEvent;

    /*Input variable for the vehicle speed*/
    const uint8 DemOBDInputVehicleSpeed;

    /*Input variable for the Time Since Engine Start information*/
    const uint8 DemOBDTimeSinceEngineStart;

} DemGeneralOBDType;

extern CONST(DemGeneralOBDType, AUTOMATIC) DemGeneralOBD;

typedef struct
{
    const uint8 DemSecondaryFunctionIdRefNum;
    const uint8 DemSecondaryFunctionIdRef[DEM_SECONDARY_FUNCTIONID_REF_MAX_NUM];
} DemSecondaryFunctionIdType;

typedef struct
{
    const uint8 DemDiagnosticEventRef;
    const uint8 DemFunctionIdRef;
    const uint8 DemIUMPRDenGroup;
    const uint8 DemIUMPRGroup; /*Dem_IUMPRGroupType*/
    const uint8 DemRatioId;
    const uint8 DemRatioKind;
    P2CONST(DemSecondaryFunctionIdType, AUTOMATIC, DEM_CONST_PBCFG) DemSecondaryFunctionIdRef;
} DemRatioType;

#endif /*#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)*/
typedef struct
{
    const sint16 DemDtrCompuDenominator0;
    const sint16 DemDtrCompuNumerator0;
    const sint16 DemDtrCompuNumerator1;
    const uint16 DemDtrEventRef;
    const uint8 DemDtrMid;
    const uint8 DemDtrTid;
    const uint8 DemDtrUasid;
    const uint8 DemDtrUpdateKind;
} DTRType;

typedef Std_ReturnType (*DemDataElementReadFncType)(uint8* Buffer);

typedef struct
{
    boolean DemInterFlag;
    uint8 DemDataElementDataSize;
    DemDataElementReadFncType DemDataElementReadFnc;
} DemDataElementClassTypes;

#if (DEM_DATA_ELEMENT_CLASS_NUM > 0)

extern CONST(DemDataElementClassTypes, AUTOMATIC) DemDataElementClass[DEM_DATA_ELEMENT_CLASS_NUM];

#endif

#if (DEM_RATIO_NUM > 0)

extern CONST(DemRatioType, AUTOMATIC) DemRatio[DEM_RATIO_NUM];

#endif

/*******************************************************************************
 *                          PostBuild Configuration                            **
 *******************************************************************************/

typedef struct
{
    P2CONST(DemComponentTypes, AUTOMATIC, DEM_CONST_PBCFG) DemComponent;
    P2CONST(Dem_DTCType, AUTOMATIC, DEM_CONST_PBCFG) DemDTC;
    P2CONST(Dem_DTCAttributesType, AUTOMATIC, DEM_CONST_PBCFG) DemDTCAttributes;
    P2CONST(Dem_DebounceCounterBasedClassType, AUTOMATIC, DEM_CONST_PBCFG) DemDebounceCounterBasedClass;
    P2CONST(Dem_DebounceTimeBaseClassType, AUTOMATIC, DEM_CONST_PBCFG) DemDebounceTimeBaseClass;
    P2CONST(DTRType, AUTOMATIC, DEM_CONST_PBCFG) DTR;
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST_PBCFG) DemEventParameter;
    P2CONST(J1939NodeType, AUTOMATIC, DEM_CONST_PBCFG) J1939Node;
    P2CONST(DemObdDTCType, AUTOMATIC, DEM_CONST_PBCFG) DemObdDTC;
    P2CONST(Dem_PidClassType, AUTOMATIC, DEM_CONST_PBCFG) DemPidClass;
} Dem_ConfigType;

#endif /* DEM_CFGNEW_DEM_CFGTYPES_H_ */

/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/
