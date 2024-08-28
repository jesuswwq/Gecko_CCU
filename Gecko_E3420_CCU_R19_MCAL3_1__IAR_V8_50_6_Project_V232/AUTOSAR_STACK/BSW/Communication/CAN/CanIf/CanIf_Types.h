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
**  FILENAME    : CanIf_Types.h                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Type definitions of CANIF                                   **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef CANIF_TYPES_H
#define CANIF_TYPES_H

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
#include "CanIf_Cfg.h"
#if (STD_ON == CANIF_WAKE_UP_SUPPORT)
#include "EcuM.h"
#endif
/*******************************************************************************
**                      Local Data Types                                      **
*******************************************************************************/
/* USER define data structure,TxPDU structure */
typedef struct
{
    boolean used;
    uint8 length;
    PduIdType TxPduIndex;
    Can_IdType canId;
    uint8* data;
} CanIf_TxPduBufferType;

/* USER define data structure,RxPDU structure */
typedef struct
{
    /* length */
    uint8 length;
    /* data */
    uint8* data;
    Can_IdType metaData;
} CanIf_RxPduBufferType;

typedef struct
{
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(CanIf_TxPduBufferType, AUTOMATIC, CANIF_CONST) CanIf_TxPduBufferRef;
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
} CanIf_TxBufferType;
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* define CANIF module initiation status */
typedef enum
{
    CANIF_INITED = 0u,
    CANIF_UNINIT
} CanIf_InitStatusType;

/*version 4.3.1 or version 4.4.0*/
#if ((CANIF_CAN_AUTOSAR_VERSION == CANIF_CAN_AUTOSAR_431) || (CANIF_CAN_AUTOSAR_VERSION == CANIF_CAN_AUTOSAR_440))
#define Can_ReturnType           Std_ReturnType
#define CAN_OK                   E_OK
#define CAN_NOT_OK               E_NOT_OK

#define Can_StateTransitionType  Can_ControllerStateType
#define CAN_T_START              CAN_CS_STARTED
#define CAN_T_STOP               CAN_CS_STOPPED
#define CAN_T_SLEEP              CAN_CS_SLEEP
#define CAN_T_WAKEUP             CAN_CS_STOPPED

#define CanIf_ControllerModeType Can_ControllerStateType
#define CANIF_CS_UNINIT          CAN_CS_UNINIT
#define CANIF_CS_STOPPED         CAN_CS_STOPPED
#define CANIF_CS_STARTED         CAN_CS_STARTED
#define CANIF_CS_SLEEP           CAN_CS_SLEEP

#else /*The default version is 4.2.2*/
/* Operating modes of a CAN controller. */
typedef enum
{
    CANIF_CS_UNINIT = 0u,
    CANIF_CS_STOPPED,
    CANIF_CS_STARTED,
    CANIF_CS_SLEEP
} CanIf_ControllerModeType;
#endif

/* Return value of CAN L-PDU notification status */
typedef enum
{
    CANIF_TX_RX_NOTIFICATION = 0u,
    CANIF_NO_NOTIFICATION
} CanIf_NotifStatusType;

typedef enum
{
/* extended 29 */
#if (STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT)
    CANIF_TX_EXTENDED_CAN,
#endif /* STD_ON == CANIF_TX_EXTENDED_CAN_SUPPORT */
#if (STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT)
    CANIF_TX_EXTENDED_FD_CAN,
#endif /* STD_ON == CANIF_TX_EXTENDED_FD_CAN_SUPPORT */
    /* standard 11 */
#if (STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT)
    CANIF_TX_STANDARD_CAN,
#endif /* STD_ON == CANIF_TX_STANDARD_CAN_SUPPORT */
#if (STD_ON == CANIF_TX_STANDARD_FD_CAN_SUPPORT)
    CANIF_TX_STANDARD_FD_CAN
#endif /* STD_ON == CANIF_TX_STANDARD_FD_CAN_SUPPORT */
} CanIf_TxPduCanIdMode;
typedef enum
{
/* extended 29 */
#if (STD_ON == CANIF_RX_EXTENDED_CAN_SUPPORT)
    CANIF_RX_EXTENDED_CAN,
#endif /* STD_ON == CANIF_RX_EXTENDED_CAN_SUPPORT */
#if (STD_ON == CANIF_RX_EXTENDED_FD_CAN_SUPPORT)
    CANIF_RX_EXTENDED_FD_CAN,
#endif /* STD_ON == CANIF_RX_EXTENDED_FD_CAN_SUPPORT */
#if (STD_ON == CANIF_RX_EXTENDED_NO_FD_CAN_SUPPORT)
    CANIF_RX_EXTENDED_NO_FD_CAN,
#endif /* STD_ON == CANIF_RX_EXTENDED_NO_FD_CAN_SUPPORT */
    /* standard 11 */
#if (STD_ON == CANIF_RX_STANDARD_CAN_SUPPORT)
    CANIF_RX_STANDARD_CAN,
#endif /* STD_ON == CANIF_RX_STANDARD_CAN_SUPPORT */
#if (STD_ON == CANIF_RX_STANDARD_FD_CAN_SUPPORT)
    CANIF_RX_STANDARD_FD_CAN,
#endif /* STD_ON == CANIF_RX_STANDARD_FD_CAN_SUPPORT */
#if (STD_ON == CANIF_RX_STANDARD_NO_FD_CAN_SUPPORT)
    CANIF_RX_STANDARD_NO_FD_CAN
#endif /* STD_ON == CANIF_RX_STANDARD_NO_FD_CAN_SUPPORT */
} CanIf_RxPduCanIdMode;

#if 0
typedef enum
{
    CANIF_HRH_EXTENDED_CAN = 0u,
    CANIF_HRH_STANDARD_CAN
} CanIfHrhCanIdType;
#endif

/*Defines the HRH type*/
typedef enum
{
    CANIF_BASIC_CAN = 0u,
    CANIF_FULL_CAN
} CanIf_HohType;

/**
 * The PduMode of a channel defines its transmit or receive activity.
 * Communication direction (transmission and/or reception) of the channel can
 * be controlled separately or together by upper layers.
 */
typedef enum
{
    CANIF_OFFLINE = 0u,
    CANIF_TX_OFFLINE,
    CANIF_TX_OFFLINE_ACTIVE,
    CANIF_ONLINE
} CanIf_PduModeType;

typedef enum
{
    CANID_DYNAMIC = 0u,
    CANID_STATIC
} CanIfTxPduMode;

typedef struct
{
    /*Symbolic name reference to CanTrcvChannel,the lower Trcv id*/
    uint8 CanTrcvId;
#if (STD_ON == CANIF_CANTRCV_WAKE_UP_SUPPORT)
    EcuM_WakeupSourceType CanIfWakeUpSource;
#endif
} CanIfTrcvCanTrcvRefType;

typedef struct
{
    /*CanIf uniform definition all CanTrcv Id*/
    uint8 CanIfTrcvId;
    /*the id of TrcvDriver*/
    uint8 CanTrcvDriverId;
    /*Support wake up or not*/
    boolean CanIfTrcvWakeupSupport;
    P2CONST(CanIfTrcvCanTrcvRefType, CANIF_CONST, CANIF_CONST) CanIfTrcvCanTrcvRef;
} CanIf_TrcvCfgType;

typedef struct
{
    /*Symbolic name reference to CanCtrl,the lower CanCtrl id*/
    uint8 CanCtrlId;
#if (STD_ON == CANIF_WAKE_UP_SUPPORT)
    /*Controller WakeUpSource | Controller Ref Trcv WakeUpSource*/
    EcuM_WakeupSourceType CanIfWakeUpSource;
#endif
} CanIfCtrlCanCtrlRefType;

typedef struct
{
    /*CanIf uniform definition all controller Id*/
    uint8 CanIfCtrlId;
    /*the id of CanDriver*/
    uint8 CanDriverId;
    /* This parameter defines if a respective controller of the referenced CAN Driver modules is queriable for wake up
     * events*/
    boolean CanIfCtrlWakeupSupport;
/*if more than zero Tx L-PDUs per CAN Controller are configured as CanIfTxPduPnFilterPdu is TRUE*/
#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
    boolean CanIfPnFilter;
#endif
    P2CONST(CanIfCtrlCanCtrlRefType, CANIF_CONST, CANIF_CONST) CanIfCtrlCanCtrlRef;
} CanIf_ControllerCfgType;

typedef struct
{
    /*The parameter refers to a particular HRH object in the CanDrv configuration*/
    Can_HwHandleType CanObjectId;
    CanIf_HohType CanIfHrhType;
} CanIfHrhIdSymRefType;

typedef struct
{
    /*Lower CAN Identifier of a receive CAN L-PDU for identifier range definition*/
    Can_IdType CanIfHrhRangeRxPduLowerCanId;
    /*Upper CAN Identifier of a receive CAN L-PDU for identifier range definition*/
    Can_IdType CanIfHrhRangeRxPduUpperCanId;
} CanIfHrhRangeType;

typedef struct
{
    /* Reference to controller Id to which the HRH belongs to*/
    uint8 CanIfHrhCanCtrlId;
#if (STD_ON == CANIF_HRH_RANGE_SUPPORT)
    uint8 CanIfHrhCanIdRangeNum;
#endif
    PduIdType CanIfRxPduRefNum;
    P2CONST(PduIdType, CANIF_CONST, CANIF_CONST) CanIfRxPduIdRef;
#if (STD_ON == CANIF_HRH_RANGE_SUPPORT)
    P2CONST(CanIfHrhRangeType, CANIF_CONST, CANIF_CONST) CanIfHrhCanIdRange;
#endif
    P2CONST(CanIfHrhIdSymRefType, CANIF_CONST, CANIF_CONST) CanIfHrhIdSymRef;
} CanIfHrhCfgType;

typedef struct
{
    /*The parameter refers to a particular HTH object in the CanDrv configuration*/
    Can_HwHandleType CanObjectId;
    CanIf_HohType CanIfHthType;
} CanIfHthIdSymRefType;

typedef struct
{
    /* Reference to controller Id to which the HTH belongs to*/
    uint8 CanIfHthCanCtrlId;
    P2CONST(CanIfHthIdSymRefType, CANIF_CONST, CANIF_CONST) CanIfHthIdSymRef;
} CanIfHthCfgType;

/* contains the references to the configuration setup of each underlying CAN Driver. */
typedef struct
{
    P2CONST(CanIfHrhCfgType, AUTOMATIC, CANIF_APPL_CONST) CanIfHrhCfgRef;
    P2CONST(CanIfHthCfgType, AUTOMATIC, CANIF_APPL_CONST) CanIfHthCfgRef;
} CanIf_InitHohCfgType;

typedef struct
{
    /*the up layer pdu id.*/
    PduIdType CanIfUpPduId;
    boolean TxMetaDataEnable;
    uint8 CanIfTxPduDlc; /*take from Ecu config*/
} CanIfTxPduRefType;

/*  contains the configur ation (parameters) of each transmit CAN L-PDU */
typedef struct
{
    /*Symbolic Name generated for this parameter*/
    PduIdType CanIfTxPduId;
    /* CAN Identifier of transmit CAN L-PDUs used by the CAN Driver for CAN L-PDU transmission */
    Can_IdType CanIfTxPduCanId; /*if no config,the default data is 0xffffffff*/
    /* Identifier mask which denotes relevant bits in the CAN Identifier.*/
    Can_IdType CanIfTxPduCanIdMask; /*when mask is 0x00000000,the tx canid is all metadata,0-0x1fffffff*/
    /* Defines the type of each transmit CAN L-PDU */
    CanIf_TxPduCanIdMode CanIfTxPduCanIdType;
    /* from the configuration parameter CanIfTxPduBufferRef */
    Can_HwHandleType CanIfTxPduHthId;
    /*Tx buffer index for CanIf_TxPduBuffer,not support the defaut data is 0xffff*/
    PduIdType TxBufferIdndex;
#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
    /* If CanIfPublicPnFilterSupport is enabled, by this parameter PDUs could be configured which will pass the
     * CanIfPnFilter */
    boolean CanIfTxPduPnFilterPdu;
#endif
#if (STD_ON == CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API)
    /* Enables and disables transmit confirmation for each transmit CAN L-SDU for reading its notification status. */
    boolean CanIfTxPduReadNotifyStatus;
    /*if CanIfTxPduReadNotifyStatus is TRUE ,then this pdu has a Notify buffer,mark the buffer index*/
    PduIdType CanIfTxNotifyIndex;
#endif
#if (STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT)
    /*Determines if or if not CanIf shall use the trigger transmit API for this PDU. */
    boolean CanIfTxPduTriggerTransmit;
    /*This parameter defines the name of the <User_TriggerTransmit>*/
    P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanIfTxPduUserTriggerTransmitName)
    (PduIdType TxPduId, PduInfoType* PduInfoPtr);
#endif
    /*Defines the type of each transmit CAN L-PDU*/
    CanIfTxPduMode CanIfTxPduType;
    /*If CanIfTxPduType is CANID_DYNAMIC,Dynamic CanId index for CanIf_DynamicTxPduCanId buffer*/
    PduIdType CanIfDynamicCanIdIndex;
    /*This parameter defines the name of the <User_TxConfirmation>*/
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2FUNC(void, CANIF_APPL_CODE, CanIfTxPduUserTxConfirmationName)(PduIdType TxPduId);
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
    P2CONST(CanIfTxPduRefType, CANIF_CONST, CANIF_CONST) CanIfTxPduRef;
} CanIf_TxPduConfigType;

typedef struct
{
    /*the up layer pdu id.*/
    PduIdType CanIfUpPduId;
    /*used for DLC check*/
    boolean RxMetaDataEnable;
} CanIfRxPduRefType;

/* contains the configur ation (parameters) of each receive CAN L-PDU */
typedef struct
{
    /*Symbolic Name generated for this parameter*/
    PduIdType CanIfRxPduId;
    /* CAN ID */
    Can_IdType CanIfRxPduCanId;
    /* Identifier mask which denotes relevant bits in the CAN Identifier*/
    Can_IdType CanIfRxPduCanIdMask; /*0-0x1fffffff*/
    /* CAN Identifier of receive CAN L-PDUs used by the CAN Driver for CAN L-PDU reception.*/
    CanIf_RxPduCanIdMode CanIfRxPduCanIdType;
    /* Data length of the received CAN L-PDUs used by the CAN Interface */
    PduLengthType CanIfRxPduDlc; /*the receive length need >= the Dlc is OK*/
    /* The HRH to which Rx L-PDU belongs to, is referred through this parameter. */
    Can_HwHandleType
        CanIfRxPduHrhId; /*dependency: This information has to be derived from the CAN Driver configuration.*/
#if (STD_ON == CANIF_PUBLIC_READ_RX_PDU_DATA_API)
    /*CanIfRxPduReadData is FALSE,the CanIfRxBufferRef is NULL_PTR*/
    P2VAR(CanIf_RxPduBufferType, AUTOMATIC, CANIF_APPL_CONST) CanIfRxBufferRef;
#endif
#if (STD_ON == CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API)
    /* Enables and disables receive indication for each receive CAN L-SDU for reading its notification status. */
    boolean CanIfRxPduReadNotifyStatus;
    /*if CanIfRxPduReadNotifyStatus is TRUE ,then this pdu has a Notify buffer,mark the buffer index*/
    PduIdType CanIfRxNotifyIndex;
#endif
    boolean CanIfRxPduForNM;
    /*This parameter defines the name of the <User_RxIndication>*/
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2FUNC(void, CANIF_APPL_CODE, CanIfRxPduUserRxIndicationName)(PduIdType RxPduId, const PduInfoType* PduInfoPtr);
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
    P2CONST(CanIfRxPduRefType, CANIF_CONST, CANIF_CONST) CanIfRxPduRef;
#if (STD_ON == CANIF_RXPDU_CANID_RANGE_SUPPORT)
    Can_IdType CanIfRxPduLowerCanId;
    Can_IdType CanIfRxPduUpperCanId;
#endif
} CanIf_RxPduConfigType;

/* Callout functions with respect to the upper layers */
typedef struct
{
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
    /* void CanSM_CheckTransceiverWakeFlagIndication(uint8 Transceiver)  */
    P2FUNC(void, CANIF_APPL_CODE, CanIfDispatchUserCheckTrcvWakeFlagIndicationName)(uint8 Transceiver);
    /* void CanSM_ClearTrcvWufFlagIndication(uint8 Transceiver)  */
    P2FUNC(void, CANIF_APPL_CODE, CanIfDispatchUserClearTrcvWufFlagIndicationName)(uint8 Transceiver);
    /* void CanSM_ConfirmPnAvailability(uint8 TransceiverId)  */
    P2FUNC(void, CANIF_APPL_CODE, CanIfDispatchUserConfirmPnAvailabilityName)(uint8 TransceiverId);
#endif
    /* void CanSM_ControllerBusOff(uint8 ControllerId)  */
    P2FUNC(void, CANIF_APPL_CODE, CanIfDispatchUserCtrlBusOffName)(uint8 ControllerId);
    /* void CanSM_ControllerModeIndication(uint8 ControllerId,CanIf_ControllerModeType ControllerMode)  */
    P2FUNC(void, CANIF_APPL_CODE, CanIfDispatchUserCtrlModeIndicationName)
    (uint8 ControllerId, CanIf_ControllerModeType ControllerMode);
    /* void CanSM_TransceiverModeIndication(uint8 TransceiverId,CanTrcv_TrcvModeType TransceiverMode) */
    P2FUNC(void, CANIF_APPL_CODE, CanIfDispatchUserTrcvModeIndicationName)
    (uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);
#if (STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT)
    /* void EcuM_ValidateWakeupEvent(EcuM_WakeupSourceType sources)*/
    P2FUNC(void, CANIF_APPL_CODE, CanIfDispatchUserValidateWakeupEventName)(EcuM_WakeupSourceType sources);
#endif
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
} CanIf_DispatchConfigType;

/**
 * This type defines a data structure for the post build parameters of the CAN
 * interface for all underlying CAN drivers. At initialization the CanIf gets a
 * pointer to a structure of this type to get access to its configuration data, which
 * is necessary for initialization.
 */
typedef struct
{
    P2CONST(CanIf_TrcvCfgType, AUTOMATIC, CANIF_CONST) CanIfTrcvConfigRef;
    P2CONST(CanIf_ControllerCfgType, AUTOMATIC, CANIF_CONST) CanIfCtrlConfigRef;
    P2CONST(CanIf_InitHohCfgType, AUTOMATIC, CANIF_CONST) CanIfInitHohConfigRef;
    P2CONST(CanIf_RxPduConfigType, AUTOMATIC, CANIF_CONST) CanIfRxPduConfigRef;
    P2CONST(CanIf_TxPduConfigType, AUTOMATIC, CANIF_CONST) CanIfTxPduConfigRef;
    P2CONST(uint8, AUTOMATIC, CANIF_CONST) CanIfBufferSize; /*CanIfBufferSize need > 0*/
} CanIf_ConfigType;

typedef struct
{
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2FUNC(Can_ReturnType, CANIF_APPL_CODE, CanSetControllerModeApi)
    (uint8 Controller, Can_StateTransitionType Transition);
    P2FUNC(Can_ReturnType, CANIF_APPL_CODE, CanWriteApi)
    (Can_HwHandleType Hth, P2CONST(Can_PduType, AUTOMATIC, CANIF_APPL_DATA) PduInfo);
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
#if (STD_ON == CANIF_SET_BAUDRATE_API)
    P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanSetBaudrateApi)(uint8 Controller, uint16 BaudRateConfigID);
#endif /*STD_ON == CANIF_SET_BAUDRATE_API*/
#if (STD_ON == CANIF_PUBLIC_ICOM_SUPPORT)
    P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanSetIcomConfigurationApi)
    (uint8 Controller, IcomConfigIdType ConfigurationId);
#endif /*STD_ON == CANIF_PUBLIC_ICOM_SUPPORT*/
#if (STD_ON == CANIF_CANDRV_WAKE_UP_SUPPORT)
    P2FUNC(Can_ReturnType, CANIF_APPL_CODE, CanCheckWakeupApi)(uint8 Controller);
#endif /*TRUE == CANIF_CANDRV_WAKE_UP_SUPPORT*/
} Can_DriverApiType;

typedef struct
{
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanTrcvSetOpModeApi)(uint8 Transceiver, CanTrcv_TrcvModeType OpMode);
    P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanTrcvGetOpModeApi)
    (uint8 Transceiver, P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_CONST) OpMode);
    P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanTrcvGetBusWuReasonApi)
    (uint8 Transceiver, P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_CONST) reason);
    P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanTrcvSetWakeupModeApi)
    (uint8 Transceiver, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
    P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanTrcvClearTrcvWufFlagApi)(uint8 Transceiver);
    P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanTrcvCheckWakeFlagApi)(uint8 Transceiver);
#endif
#if (STD_ON == CANIF_CANTRCV_WAKE_UP_SUPPORT)
    P2FUNC(Std_ReturnType, CANIF_APPL_CODE, CanTrcvCheckWakeupApi)(uint8 Transceiver);
#endif                   /*TRUE == CANIF_CANTRCV_WAKE_UP_SUPPORT*/
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
} Can_TrcvApiType;

typedef struct
{
    P2CONST(uint16, AUTOMATIC, CANIF_CONST) CanIfCanHoh2HrhRef;
    uint32 CanIfCanHohLen;
} CanIf_CanHOH2HRHType;

#endif /* end of CANIF_TYPES_H */
