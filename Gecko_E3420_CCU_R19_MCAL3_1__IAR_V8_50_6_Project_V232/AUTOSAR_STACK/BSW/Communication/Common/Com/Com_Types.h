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
**  FILENAME    : Com_Types.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Type definitions of COM                                     **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef COM_TYPES_H
#define COM_TYPES_H
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define COM_TYPES_H_AR_MAJOR_VERSION 4u
#define COM_TYPES_H_AR_MINOR_VERSION 2u
#define COM_TYPES_H_AR_PATCH_VERSION 2u
#define COM_TYPES_H_SW_MAJOR_VERSION 2u
#define COM_TYPES_H_SW_MINOR_VERSION 0u
#define COM_TYPES_H_SW_PATCH_VERSION 1u
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Com_Cfg.h"
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* AutoSAR COM Com_Module_Status_Type, Range COM_UNINIT/COM_INIT */
typedef enum
{
    COM_UNINIT = 0u,
    COM_INIT
} Com_StatusType;

/* Defines the endianness of the signal's network representation */
typedef enum
{
    COM_BIG_ENDIAN = 0u,
    COM_LITTLE_ENDIAN,
    COM_OPAQUE
} Com_SignalEndiannessType;

/*The AUTOSAR type of the signal*/
typedef enum
{
    COM_BOOLEAN = 0u,
    COM_FLOAT32,
    COM_FLOAT64,
    COM_SINT16,
    COM_SINT32,
    COM_SINT64,
    COM_SINT8,
    COM_UINT16,
    COM_UINT32,
    COM_UINT64,
    COM_UINT8,
    COM_UINT8_DYN,
    COM_UINT8_N
} Com_SignalType;

/*Defines if a write access to this signal can trigger the transmission of the corresponding I-PDU*/
typedef enum
{
    COM_PENDING = 0u,
    COM_TRIGGERED,
    COM_TRIGGERED_ON_CHANGE,
    COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION,
    COM_TRIGGERED_WITHOUT_REPETITION
} Com_TransferPropertyType;

/*Defines if a write access to this signal can trigger the transmission of the corresponding I-PDU*/
typedef enum
{
    COM_ALWAYS = 0u,
    COM_MASKED_NEW_DIFFERS_MASKED_OLD,
    COM_MASKED_NEW_DIFFERS_X,
    COM_MASKED_NEW_EQUALS_X,
    COM_NEVER,
    COM_NEW_IS_OUTSIDE,
    COM_NEW_IS_WITHIN,
    COM_ONE_EVERY_N
} Com_FilterAlgorithmType;

typedef enum
{
    COM_TX_MODE_DIRECT = 0u,
    COM_TX_MODE_MIXED,
    COM_TX_MODE_NONE,
    COM_TX_MODE_PERIODIC
} Com_TxModeModeType;

typedef enum
{
    COM_CONFIRMATION = 0u,
    COM_TRANSMIT,
    COM_TRIGGER_TRANSMIT
} Com_TxIPduClearUpdateBitType;

typedef enum
{
    COM_DEFERRED = 0u,
    COM_IMMEDIATE
} Com_IPduSignalProcessingType;

typedef enum
{
    COM_PDU_NORMAL = 0u,
    COM_PDU_TP
} Com_IPduType;

typedef enum
{
    COM_INVALID_ACTION_NOTIFY = 0u,
    COM_INVALID_ACTION_REPLACE
} Com_DataInvalidActionType;

typedef enum
{
    COM_TIMEOUT_ACTION_NONE = 0u,
    COM_TIMEOUT_ACTION_REPLACE
} Com_RxDataTimeoutActionType;

typedef enum
{
    COM_SIGNAL = 0u,
    COM_GROUP_SIGNAL,
    COM_DESCRIPTION
} Com_GWSignalType;

/* AUTOSAR COM signal object identifier, Range 0-SingalIdMax */
typedef uint16 Com_SignalIdType;

/* AUTOSAR COM signal group object identifier, Range 0-SingalGroupIdMax */
typedef uint16 Com_SignalGroupIdType;

/* AUTOSAR COM IPdu group object identifier, Range 0-PduGroupIdMax */
typedef uint16 Com_IpduGroupIdType;

#if (COM_IPDUGROUP_NUMBER > 0u)
typedef uint8 Com_IpduGroupVector[((COM_IPDUGROUP_NUMBER - 1u) / 8u) + 1u];
#else
typedef uint8 Com_IpduGroupVector[1u];
#endif

/*the configuration parameters of PDU Counter*/
typedef struct
{
    P2FUNC(void, COM_APPL_CODE, ComIPduCounterErrorNotification) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    (PduIdType ComPduId, uint8 ExpectedCounter, uint8 ReceivedCounter);
    uint8 ComIPduCounterSize; /*all bits in same byte*/
    uint32 ComIPduCounterStartPosition;
    uint8 ComIPduCounterThreshold;
    uint8 ComIPduMaxCounter;
} Com_IPduCounterType;

/*the information needed for each I-PDU replicated*/
typedef struct
{
    uint8 ComIPduReplicationQuorum;
} Com_IPduReplicationType;

typedef struct
{
    Com_GWSignalType ComGwDestSignalType;
    Com_SignalIdType ComGwDestSignalId;
} Com_GwDestType;

/*Each instance of this container defines one mapping of the integrated Signal Gateway*/
typedef struct
{
    Com_GWSignalType ComGwSourceSignalType;
    Com_SignalIdType ComGwSourceSignalId;
    Com_SignalIdType ComGwDestNumber;
    P2CONST(Com_GwDestType, AUTOMATIC, COM_APPL_CONST) ComGwDest;
} Com_GwMappingType;

/*Description of a gateway source*/
typedef struct
{
    uint32 ComBitPosition;
    uint8 ComBitSize;
    uint8 ComSignalByteLength;
    Com_SignalEndiannessType ComSignalEndianness;
    uint16 ComSignalLength;
    Com_SignalType ComSignalType;
    uint32 ComUpdateBitPosition;
    uint8 ComUpdateBitMask;
    uint16 ComGwIPduRef;
    uint16 GWSignalBufferId;
    uint16 GWUpdataStateId;
} Com_GwSourceSignalType;

/*This container contains the configuration parameters of the AUTOSAR COM module's Filters*/
typedef struct
{
    Com_FilterAlgorithmType ComFilterAlgorithm;
    uint64 ComFilterMask;
    uint64 ComFilterX;
    uint64 ComFilterMax;
    uint64 ComFilterMin;
    uint32 ComFilterOffset;
    uint32 ComFilterPeriod;
    Com_SignalIdType ComOneEveryNId;
    Com_SignalIdType ComMaskNewDifferMaskOldId;
    Com_SignalIdType ComTMCBufferId;
} Com_FilterType;

/*Description of a gateway destination*/
typedef struct
{
    uint32 ComBitPosition;
    Com_SignalEndiannessType ComSignalEndianness;
    Com_TransferPropertyType ComTransferProperty;
    uint32 ComUpdateBitPosition;
    uint8 ComUpdateBitMask;
    uint16 ComGwIPduRef;
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter;
    uint16 ComSignalInitValueId;
    uint16 ComSignalDataInitValueLength;
    uint8 ComBitSize;
    uint8 ComSignalByteLength;
    Com_SignalType ComSignalType;
    uint16 ComSignalLength;
} Com_GwDestSignalType;

/*This container contains the configuration parameters of the AUTOSAR COM module's transmission modes*/
typedef struct
{
    Com_TxModeModeType ComTxModeMode;
    uint8 ComTxModeNumberOfRepetitions;
    uint16 ComTxModeRepetitionPeriod;
    uint16 ComTxModeTimeOffset;
    uint16 ComTxModeTimePeriod;
} Com_TxModeType;

typedef struct
{
    P2FUNC(boolean, COM_APPL_CODE, ComIPduCallout) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    (PduIdType PduId, P2CONST(PduInfoType, AUTOMATIC, COM_APPL_CONST) PduInfoPtr);
#if (STD_ON == COM_CANCELLATION_SUPPORT)
    boolean ComIPduCancellationSupport;
#endif
    uint16 ComIPduHandleId;
    Com_IPduSignalProcessingType ComIPduSignalProcessing;
    Com_IPduType ComIPduType;
    Com_IpduGroupIdType ComIPduGroupsRefNumber;
    P2CONST(Com_IpduGroupIdType, AUTOMATIC, COM_APPL_CONST) ComIPduGroupsRef;
    Com_SignalGroupIdType ComIPduSignalGroupsRefNumber;
    P2CONST(Com_SignalGroupIdType, AUTOMATIC, COM_APPL_CONST) ComIPduSignalGroupsRef;
    Com_SignalIdType ComIPduSignalsRefNumber;
    P2CONST(Com_SignalIdType, AUTOMATIC, COM_APPL_CONST) ComIPduSignalsRef;
    Com_SignalIdType ComIPduSourceSignalsRefNumber;
    P2CONST(Com_SignalIdType, AUTOMATIC, COM_APPL_CONST) ComIPduSourceSignalsRef;
    uint8 MetaDataLength;
    PduLengthType IPduNoDynSignalLength;
    PduLengthType IPduMaxDynSignalLength;
    uint16 ComRxIPduBufIndex;
    P2CONST(Com_IPduCounterType, AUTOMATIC, COM_APPL_CONST) ComIPduCounter;
    P2CONST(Com_IPduReplicationType, AUTOMATIC, COM_APPL_CONST) ComIPduReplication;
    boolean IPduGW;
} Com_RxIPduType;

typedef struct
{
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2FUNC(boolean, COM_APPL_CODE, ComIPduCallout)
    (PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) PduInfoPtr);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
#if (STD_ON == COM_CANCELLATION_SUPPORT)
    boolean ComIPduCancellationSupport;
#endif
    uint16 ComIPduHandleId;
    Com_IPduSignalProcessingType ComIPduSignalProcessing;
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2FUNC(boolean, COM_APPL_CODE, ComIPduTriggerTransmitCallout)
    (PduIdType PduId, P2VAR(PduInfoType, AUTOMATIC, COM_APPL_CONST) PduInfoPtr);
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
    Com_IPduType ComIPduType;
    Com_IpduGroupIdType ComIPduGroupsRefNumber;
    P2CONST(Com_IpduGroupIdType, AUTOMATIC, COM_APPL_CONST) ComIPduGroupsRef;
    Com_SignalGroupIdType ComIPduSignalGroupsRefNumber;
    P2CONST(Com_SignalGroupIdType, AUTOMATIC, COM_APPL_CONST) ComIPduSignalGroupsRef;
    Com_SignalIdType ComIPduSignalsRefNumber;
    P2CONST(Com_SignalIdType, AUTOMATIC, COM_APPL_CONST) ComIPduSignalsRef;
    Com_SignalIdType ComIPduDestSignalsRefNumber;
    P2CONST(Com_SignalIdType, AUTOMATIC, COM_APPL_CONST) ComIPduDestSignalsRef;
    PduIdType ComPduIdRef;
    uint8 MetaDataLength;
    PduLengthType IPduNoDynSignalLength;
    PduLengthType IPduMaxDynSignalLength;
    uint16 ComTxIPduBufIndex;
    P2CONST(Com_IPduCounterType, AUTOMATIC, COM_APPL_CONST) ComIPduCounter;
    P2CONST(Com_IPduReplicationType, AUTOMATIC, COM_APPL_CONST) ComIPduReplication;
    uint16 ComMinimumDelayTime;
    Com_TxIPduClearUpdateBitType ComTxIPduClearUpdateBit;
    P2CONST(Com_TxModeType, AUTOMATIC, COM_APPL_CONST) ComTxModeTrue;
    P2CONST(Com_TxModeType, AUTOMATIC, COM_APPL_CONST) ComTxModeFalse;
    uint16 ComTxIpduDM;
} Com_TxIPduType;

typedef struct
{
    uint32 ComBitPosition;
    uint8 ComBitSize;
    uint8 ComSignalByteLength;
    uint16 ComFirstTimeout;
    uint16 ComTimeout;
    uint16 ComTimeCntIndex;
    PduIdType ComIpduRefIndex;
    Com_SignalIdType ComSignalId;
    Com_DataInvalidActionType ComDataInvalidAction;
    P2FUNC(void, COM_APPL_CODE, ComInvalidNotification)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2FUNC(void, COM_APPL_CODE, ComNotification)(void); /* PRQA S 3432 */        /* MISRA Rule 20.7 */
    Com_RxDataTimeoutActionType ComRxDataTimeoutAction;
    uint16 ComSignalDataInvalidValueId;
    Com_SignalEndiannessType ComSignalEndianness;
    uint16 ComSignalInitValueId;
    uint16 ComSignalLength;
    Com_SignalType ComSignalType;
    P2FUNC(void, COM_APPL_CODE, ComTimeoutNotification)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint32 ComUpdateBitPosition;
    uint8 ComUpdateBitMask;
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter;
    uint16 ComSignalDataInvalidValueLength;
    uint16 ComSignalDataInitValueLength;
    uint16 GWUpdataStateId;
    uint16 GWSignalBufferId;
} Com_RxSignalType;

typedef struct
{
    uint32 ComBitPosition;
    uint8 ComBitSize;
    uint8 ComSignalByteLength;
    P2FUNC(void, COM_APPL_CODE, ComErrorNotification)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    Com_SignalIdType ComSignalId;
    boolean ComInitialValueOnly;
    P2FUNC(void, COM_APPL_CODE, ComNotification)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint16 ComSignalDataInvalidValueId;
    Com_SignalEndiannessType ComSignalEndianness;
    uint16 ComSignalInitValueId;
    uint16 ComSignalLength;
    Com_SignalType ComSignalType;
    uint16 ComTimeout;
    PduIdType ComIpduRefIndex;
    P2FUNC(void, COM_APPL_CODE, ComTimeoutNotification)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    Com_TransferPropertyType ComTransferProperty;
    uint32 ComUpdateBitPosition;
    uint8 ComUpdateBitMask;
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter;
    uint16 ComSignalDataInvalidValueLength;
    uint16 ComSignalDataInitValueLength;
} Com_TxSignalType;

typedef struct
{
    uint16 ComIPduStartBufIndex;
    uint16 SignalGroupArrayLength;
} Com_SignalGroupArrayType;

typedef struct
{
    Com_DataInvalidActionType ComDataInvalidAction;
    uint16 ComFirstTimeout;
    uint16 ComTimeout;
    Com_SignalGroupIdType ComSignalGroupId;
    P2FUNC(void, COM_APPL_CODE, ComInvalidNotification)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2FUNC(void, COM_APPL_CODE, ComNotification)(void); /* PRQA S 3432 */        /* MISRA Rule 20.7 */
    Com_RxDataTimeoutActionType ComRxDataTimeoutAction;
    P2CONST(Com_SignalGroupArrayType, AUTOMATIC, COM_APPL_CONST) ComSignalGroupArray;
    P2FUNC(void, COM_APPL_CODE, ComTimeoutNotification)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint32 ComUpdateBitPosition;
    uint8 ComUpdateBitMask;
    Com_SignalIdType ComGroupSignalNumber;
    P2CONST(Com_SignalIdType, AUTOMATIC, COM_APPL_CONST) ComRxGroupSignalId;
    PduIdType ComIpduRefIndex;
    uint16 ComTimeoutCntIndex;
    uint16 GWUpdataStateId;
} Com_RxSignalGroupType;

typedef struct
{
    P2FUNC(void, COM_APPL_CODE, ComErrorNotification)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    Com_SignalGroupIdType ComSignalGroupId;
    boolean ComInitialValueOnly;
    P2FUNC(void, COM_APPL_CODE, ComNotification)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(Com_SignalGroupArrayType, AUTOMATIC, COM_APPL_CONST) ComSignalGroupArray;
    uint16 ComTimeout;
    P2FUNC(void, COM_APPL_CODE, ComTimeoutNotification)(void); /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    Com_TransferPropertyType ComTransferProperty;
    uint32 ComUpdateBitPosition;
    uint8 ComUpdateBitMask;
    Com_SignalIdType ComGroupSignalNumber;
    P2CONST(Com_SignalIdType, AUTOMATIC, COM_APPL_CONST) ComTxGroupSignalId;
    PduIdType ComIpduRefIndex;
} Com_TxSignalGroupType;

typedef struct
{
    uint32 ComBitPosition;
    uint8 ComBitSize;
    uint8 ComSignalByteLength;
    Com_SignalIdType ComGroupSignalId;
    uint16 ComSignalDataInvalidValueId;
    Com_SignalEndiannessType ComSignalEndianness;
    uint16 ComSignalInitValueId;
    uint16 ComSignalLength;
    Com_SignalType ComSignalType;
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter;
    boolean ComTxGroupSignalUsedTransferProperty;
    Com_TransferPropertyType ComTransferProperty;
    Com_SignalGroupIdType ComSignalGroupRef;
    uint16 ComSignalDataInvalidValueLength;
    uint16 ComSignalDataInitValueLength;
} Com_TxGroupSignalType;

typedef struct
{
    uint32 ComBitPosition;
    uint8 ComBitSize;
    uint8 ComSignalByteLength;
    Com_SignalIdType ComGroupSignalId;
    uint16 ComSignalDataInvalidValueId;
    Com_SignalEndiannessType ComSignalEndianness;
    uint16 ComSignalInitValueId;
    uint16 ComSignalLength;
    Com_SignalType ComSignalType;
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter;
    Com_SignalGroupIdType ComSignalGroupRef;
    uint16 ComSignalDataInvalidValueLength;
    uint16 ComSignalDataInitValueLength;
    uint16 GWSignalBufferId;
} Com_RxGroupSignalType;

typedef struct
{
    boolean ActiveEnable;
    boolean DMEnable;
    boolean Receiving;
    uint16 RxIpduLength;
    uint16 GWDynamicSignalLength;
    boolean NeedGW;
    boolean RxIndication;
    uint16 RxOffset;
    boolean RxAnyCounterPdu;
    uint8 RxIpduCounter;
    uint8 RxReplicationNumber;
} Com_RxIPduRunTimeStateType;

typedef struct
{
    boolean ActiveEnable;
    boolean TxConfirm;
    boolean TMS;
    boolean Transmiting;
    uint16 TxIpduLength;
    uint16 MDTCnt;
    Com_TxModeModeType ipduTxMode;
    uint16 RptNum;
    uint16 NTimeCnt;
    uint16 DMCnt;
    uint16 PeriodCnt;
    boolean TxDelay;
    uint16 TxOffset;
    uint8 TxIpduCounter;
} Com_TxIPduRunTimeStateType;

typedef struct
{
    boolean NTimesTransmitNeed;
    boolean WithoutRepetition;
    uint16 DynamicSignalLength;
} Com_TxSignalGroupRunTimeStateType;

typedef struct
{
    P2CONST(Com_RxIPduType, AUTOMATIC, COM_APPL_CONST) ComRxIPdu;
    P2CONST(Com_TxIPduType, AUTOMATIC, COM_APPL_CONST) ComTxIPdu;
    P2CONST(Com_RxSignalType, AUTOMATIC, COM_APPL_CONST) ComRxSignal;
    P2CONST(Com_TxSignalType, AUTOMATIC, COM_APPL_CONST) ComTxSignal;
    P2CONST(Com_RxSignalGroupType, AUTOMATIC, COM_APPL_CONST) ComRxSignalGroup;
    P2CONST(Com_TxSignalGroupType, AUTOMATIC, COM_APPL_CONST) ComTxSignalGroup;
    P2CONST(Com_RxGroupSignalType, AUTOMATIC, COM_APPL_CONST) ComRxGroupSignal;
    P2CONST(Com_TxGroupSignalType, AUTOMATIC, COM_APPL_CONST) ComTxGroupSignal;
    P2CONST(Com_GwMappingType, AUTOMATIC, COM_APPL_CONST) ComGwMapping;
    P2CONST(Com_GwSourceSignalType, AUTOMATIC, COM_APPL_CONST) ComSourceSignal;
    P2CONST(Com_GwDestSignalType, AUTOMATIC, COM_APPL_CONST) ComDestSignal;
} Com_ConfigType;

#endif /* end of COM_TYPES_H */
