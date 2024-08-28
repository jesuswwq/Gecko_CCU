/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2020)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : CanIf.h                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : API declaration and type definitions of CANIF               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#ifndef CANIF_H
#define CANIF_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "CanIf_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define CANIF_MODULE_ID          60u
#define CANIF_H_VENDOR_ID        62u
#define CANIF_H_AR_MAJOR_VERSION 4u
#define CANIF_H_AR_MINOR_VERSION 2u
#define CANIF_H_AR_PATCH_VERSION 2u
#define CANIF_H_SW_MAJOR_VERSION 2u
#define CANIF_H_SW_MINOR_VERSION 0u
#define CANIF_H_SW_PATCH_VERSION 3u

#define CANIF_INSTANCE_ID        (0u)

/*Service ID*/
#define CANIF_CHECKWAKEUP_ID  (0x11u)
#define CANIF_TRANSMIT_ID     (0x05u)
#define CANIF_RXINDICATION_ID (0x14u)
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
#define CANIF_INIT_ID                        (0x01u)
#define CANIF_SETCONTROLLER_MODE_ID          (0x03u)
#define CANIF_GETCONTROLLER_MODE_ID          (0x04u)
#define CANIF_CANCELTRANSMIT_ID              (0x18u)
#define CANIF_READRXPDUDATA_ID               (0x06u)
#define CANIF_READTXNOTIFSTATUS_ID           (0x07u)
#define CANIF_READRXNOTIFSTATUS_ID           (0x08u)
#define CANIF_SETPDUMODE_ID                  (0x09u)
#define CANIF_GETPDUMODE_ID                  (0x0Au)
#define CANIF_GETVERSIONINFO_ID              (0x0Bu)
#define CANIF_SETDYNAMICTXID_ID              (0x0Cu)
#define CANIF_SETTRCVMODE_ID                 (0x0Du)
#define CANIF_GETTRCVMODE_ID                 (0x0Eu)
#define CANIF_GETTRCVWAKEUPREASON_ID         (0x0Fu)
#define CANIF_SETTRCVWAKEUPMODE_ID           (0x10u)
#define CANIF_CHECKVALIDATION_ID             (0x12u)
#define CANIF_GETTXCONFIRMATIONSTATE         (0x19u)
#define CANIF_CLEARTRCVWUFFLAG_ID            (0x1Eu)
#define CANIF_CHECKTRCVWAKEFLAG_ID           (0x1Fu)
#define CANIF_SETBAUDRATE_ID                 (0x27u)
#define CANIF_SETICOMCONFIGURATION_ID        (0x25u)
#define CANIF_TRIGGERTRANSMIT_ID             (0x41u)
#define CANIF_TXCONFIRMATION_ID              (0x13u)
#define CANIF_CONTROLLERBUSOFF_ID            (0x16u)
#define CANIF_CONFIRMPNAVAILABILITY_ID       (0x1Au)
#define CANIF_CLEARTRCVWUFFLAGINDICATION_ID  (0x20u)
#define CANIF_CHECKTRCVWAKEFLAGINDICATION_ID (0x21u)
#define CANIF_CONTROLLERMODEINDICATION_ID    (0x17u)
#define CANIF_TRCVMODEINDICATION_ID          (0x22u)
#define CANIF_CURRENTICOMCONFIGURATION_ID    (0x26u)
/* Error detection */
#define CANIF_E_PARAM_CANID          (10u)
#define CANIF_E_PARAM_HOH            (12u)
#define CANIF_E_PARAM_LPDU           (13u)
#define CANIF_E_PARAM_CONTROLLERID   (15u)
#define CANIF_E_PARAM_WAKEUPSOURCE   (16u)
#define CANIF_E_PARAM_TRCV           (17u)
#define CANIF_E_PARAM_TRCVMODE       (18u)
#define CANIF_E_PARAM_TRCVWAKEUPMODE (19u)
#define CANIF_E_PARAM_CTRLMODE       (21u)
#define CANIF_E_PARAM_PDU_MODE       (22u)
#define CANIF_E_PARAM_POINTER        (20u)
#define CANIF_E_UNINIT               (30u)
#define CANIF_E_INVALID_TXPDUID      (50u)
#define CANIF_E_INVALID_RXPDUID      (60u)
#define CANIF_E_INIT_FAILED          (80u)
#endif /*STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT*/
#define CANIF_E_INVALID_DLC          (61u)
#define CANIF_E_DATA_LENGTH_MISMATCH (62u)
#define CANIF_E_STOPPED              (70u)
#define CANIF_E_NOT_SLEEP            (71u)

/* max extended can id */
#define CANIF_EXTENDED_CANID_MAX (0x1FFFFFFFu)
/* max standard can id */
#define CANIF_STANDARD_CANID_MAX (0x7FFu)

#define CANIF_UNUSED_UINT16      (0xFFFFu)
#define CANIF_UNUSED_UINT8       (0xFFu)

/*Set according to the situation,when integrating project*/
#define CANIF_RXINDICATION_AUTOSAR_PARAMETER STD_OFF
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
extern CONST(CanIf_ConfigType, CANIF_CONST_PBCFG) CanIf_InitCfgSet;

#if (STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER)
extern CONST(CanIf_CanHOH2HRHType, CANIF_CONST) CanIf_CanHoh2Hrh[CANIF_CANDRIVER_NUMBER];
#endif /*STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER*/

/* Callout functions with respect to the upper layers. */
extern CONST(CanIf_DispatchConfigType, CANIF_CONST) CanIf_DispatchConfigData;

/*Can Driver API*/
extern CONST(Can_DriverApiType, CANIF_CONST) Can_DriverApi[CANIF_CANDRIVER_NUMBER];

/*Can Trcv API*/
#if (CANIF_TRCVDRIVER_NUMBER > 0u)
extern CONST(Can_TrcvApiType, CANIF_CONST) Can_TrcvApi[CANIF_TRCVDRIVER_NUMBER];
#endif

#if (CANIF_TXBUFFER_NUMBER > 0u)
extern VAR(CanIf_TxBufferType, CANIF_VAR) CanIf_TxBuffer[CANIF_TXBUFFER_NUMBER];
#endif

#if (CANIF_RXBUFFER_NUMBER > 0u)
extern VAR(CanIf_RxPduBufferType, CANIF_VAR) CanIf_RxBuffer[CANIF_RXBUFFER_NUMBER];
#endif
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#if (STD_ON == CANIF_PUBLIC_VERSION_INFO_API)
/*************************************************************************/
/*
 * Brief               This service returns the version information of the called CAN Interface module.
 * ServiceId           0x0b
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     VersionInfo: Pointer to where to store the version information of this module.
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
#if (STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT)
#define CanIf_GetVersionInfo(VersionInfo)                                                                        \
    do                                                                                                           \
    {                                                                                                            \
        if (NULL_PTR == (VersionInfo))                                                                           \
        {                                                                                                        \
            Det_ReportError(CANIF_MODULE_ID, CANIF_INSTANCE_ID, CANIF_GETVERSIONINFO_ID, CANIF_E_PARAM_POINTER); \
        }                                                                                                        \
        else                                                                                                     \
        {                                                                                                        \
            (VersionInfo)->vendorID = CANIF_H_VENDOR_ID;                                                         \
            (VersionInfo)->moduleID = CANIF_MODULE_ID;                                                           \
            (VersionInfo)->sw_major_version = CANIF_H_SW_MAJOR_VERSION;                                          \
            (VersionInfo)->sw_minor_version = CANIF_H_SW_MINOR_VERSION;                                          \
            (VersionInfo)->sw_patch_version = CANIF_H_SW_PATCH_VERSION;                                          \
        }                                                                                                        \
    } while (0)
#else
#define CanIf_GetVersionInfo(VersionInfo)                           \
    do                                                              \
    {                                                               \
        (VersionInfo)->vendorID = CANIF_H_VENDOR_ID;                \
        (VersionInfo)->moduleID = CANIF_MODULE_ID;                  \
        (VersionInfo)->sw_major_version = CANIF_H_SW_MAJOR_VERSION; \
        (VersionInfo)->sw_minor_version = CANIF_H_SW_MINOR_VERSION; \
        (VersionInfo)->sw_patch_version = CANIF_H_SW_PATCH_VERSION; \
    } while (0)
#endif /* STD_ON == CANIF_PUBLIC_DEV_ERROR_DETECT */
#endif /* STD_ON == CANIF_PUBLIC_VERSION_INFO_API */
/*************************************************************************/
/*
 * Brief               This service Initializes internal and external interfaces of the CAN Interface for the further
 * processing. ServiceId           0x01 Sync/Async          Synchronous Reentrancy          Non Reentrant Param-Name[in]
 * ConfigPtr: Pointer to configuration parameter set, used e.g. for post build parameters Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_Init(P2CONST(CanIf_ConfigType, AUTOMATIC, CANIF_CONST_PBCFG) ConfigPtr);
/*************************************************************************/
/*
 * Brief               De-initializes the CanIf module.
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_DeInit(VAR(void, AUTOMATIC));
/*************************************************************************/
/*
 * Brief               This service calls the corresponding CAN Driver service
 *                     for changing of the CAN controller mode.
 * ServiceId           0x03
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant (Not for the same controller)
 * Param-Name[in]      ControllerId: Abstracted CanIf ControllerId which is assigned
 *                     to a CAN controller, which is requested for mode transition.
 *                     ControllerMode: Requested mode transition
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Controller mode request has been accepted
 *                     E_NOT_OK: Controller mode request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)
    CanIf_SetControllerMode(uint8 ControllerId, CanIf_ControllerModeType ControllerMode);
/*************************************************************************/
/*
 * Brief               This service reports about the current status of the requested CAN controller.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ControllerId: Abstracted CanIf ControllerId which is assigned to a
 *                     CAN controller, which is requested for current operation mode.
 * Param-Name[out]     ControllerModePtr: Pointer to a memory location, where the current
 *                     mode of the CAN controller will be stored.
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Controller mode request has been accepted.
 *                     E_NOT_OK: Controller mode request has not been accepted.
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetControllerMode(
    uint8 ControllerId,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(CanIf_ControllerModeType, AUTOMATIC, CANIF_APPL_DATA) ControllerModePtr);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
/*************************************************************************/
/*
 * Brief               This service initiates a request for transmission of the CAN L-PDU
 *                     specified by the CanTxSduId and CAN related data in the L-SDU structure.
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CanIfTxSduId: L-SDU handle to be transmitted.This handle specifies the
 *                     corresponding CAN LSDU ID and implicitly the CAN Driver instance as well
 *                     as the corresponding CAN controller device.
 *                     CanIfTxInfoPtr: Pointer to a structure with CAN L-SDU related data:
 *                     DLC and pointer to CAN L-SDU buffer including the MetaData of dynamic L-PDUs.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Transmit request has been accepted
 *                     E_NOT_OK: Transmit request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)
    CanIf_Transmit(PduIdType CanIfTxSduId, P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr);
#if (STD_ON == CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT)
/*************************************************************************/
/*
 * Brief               This is a dummy method introduced for interface compatibility.
 * ServiceId           0x18
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CanIfTxSduId: L-SDU handle to be transmitted.This handle specifies the
 *                     corresponding CAN LSDU ID and implicitly the CAN Driver instance as well
 *                     as the corresponding CAN controller device.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     Always return E_OK
 * PreCondition        CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CancelTransmit(PduIdType CanIfTxSduId);
#endif /*STD_ON == CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT*/
#if (STD_ON == CANIF_PUBLIC_READ_RX_PDU_DATA_API)
/*************************************************************************/
/*
 * Brief               This service provides the CAN DLC and the received data of the requested CanIfRxSduId to the
 * calling upper layer. ServiceId           0x06 Sync/Async          Synchronous Reentrancy          Non Reentrant
 * Param-Name[in]      CanIfRxSduId: Receive L-SDU handle specifying the corresponding CAN L-SDU ID and implicitly the
 * CAN Driver instance as well as the corresponding CAN controller device. Param-Name[out]     CanIfRxInfoPtr: Pointer
 * to a structure with CAN L-SDU related data:DLC and pointer to CAN L-SDU buffer including the MetaData of dynamic
 * L-PDUs. Param-Name[in/out]  None Return              Std_ReturnType E_OK: Request for L-SDU data has been accepted
 *                     E_NOT_OK: No valid data has been received
 * PreCondition        CANIF_PUBLIC_READ_RX_PDU_DATA_API is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)
    CanIf_ReadRxPduData(PduIdType CanIfRxSduId, P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) CanIfRxInfoPtr);
#endif /* STD_ON == CANIF_PUBLIC_READ_RX_PDU_DATA_API*/
#if (STD_ON == CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API)
/*************************************************************************/
/*
 * Brief               This service returns the confirmation status (confirmation occurred or
 *                     not) of a specific static or dynamic CAN Tx L-PDU, requested by the CanIfTxSduId.
 * ServiceId           0x07
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CanIfTxSduId: L-SDU handle to be transmitted.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              CanIf_NotifStatusType:Current confirmation status of the corresponding CAN Tx L-PDU.
 * PreCondition        CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadTxNotifStatus(PduIdType CanIfTxSduId);
#endif /* STD_ON == CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API */
#if (STD_ON == CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API)
/*************************************************************************/
/*
 * Brief               This service returns the indication status (indication occurred or not) of a
 *                     specific CAN Rx L-PDU, requested by the CanIfRxSduId.
 * ServiceId           0x08
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CanIfRxSduId: Receive L-SDU handle specifying the corresponding CAN L-SDU ID and implicitly
 *                     the CAN Driver instance as well as the corresponding CAN controller device.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              CanIf_NotifStatusType:Current indication status of the corresponding CAN Rx L-PDU.
 * PreCondition        CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_ReadRxNotifStatus(PduIdType CanIfRxSduId);
#endif /* STD_ON == CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API */
/*************************************************************************/
/*
 * Brief               This service sets the requested mode at the L-PDUs of a predefined logical PDU channel.
 * ServiceId           0x09
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ControllerId: All PDUs of the own ECU connected to the corresponding CanIf ControllerId,
 *                     which is assigned to a physical CAN controller are addressed.
 *                     PduModeRequest: Requested PDU mode change
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Request for mode transition has been accepted.
 *                     E_NOT_OK: Request for mode transition has not been accepted.
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetPduMode(uint8 ControllerId, CanIf_PduModeType PduModeRequest);
/*************************************************************************/
/*
 * Brief               This service reports the current mode of a requested PDU channel.
 * ServiceId           0x0a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (Not for the same channel)
 * Param-Name[in]      ControllerId: All PDUs of the own ECU connected to the corresponding CanIf
 *                     ControllerId, which is assigned to a physical CAN controller are addressed.
 * Param-Name[out]     PduModePtr: Pointer to a memory location, where the current mode of the
 *                     logical PDU channel will be stored.
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: PDU mode request has been accepted
 *                     E_NOT_OK: PDU mode request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    CanIf_GetPduMode(uint8 ControllerId, P2VAR(CanIf_PduModeType, AUTOMATIC, CANIF_APPL_DATA) PduModePtr);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
#if (STD_ON == CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API)
/*************************************************************************/
/*
 * Brief               This service reconfigures the corresponding CAN identifier of the requested CAN L-PDU.
 * ServiceId           0x0c
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CanIfTxSduId: L-SDU handle to be transmitted.This handle specifies the corresponding
 *                     CAN LSDU ID and implicitly the CAN Driver instance as well as the corresponding CAN controller
 * device. CanId: Standard/Extended CAN ID of CAN L-SDU that shall be transmitted as FD or conventional CAN frame.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_DYNAMIC_TXPDU_NUMBER > 0
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(void, CANIF_CODE) CanIf_SetDynamicTxId(PduIdType CanIfTxSduId, Can_IdType CanId);
#endif /* STD_ON == CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API */
#if (CANIF_TRCV_NUMBER > 0u)
/*************************************************************************/
/*
 * Brief               This service changes the operation mode of the tansceiver TransceiverId,
 *                     via calling the corresponding CAN Transceiver Driver service.
 * ServiceId           0x0d
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TransceiverId: Abstracted CanIf TransceiverId, which is assigned to a CAN
 *                     transceiver, which is requested for mode transition
 *                     TransceiverMode: Requested mode transition
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Transceiver mode request has been accepted.
 *                     E_NOT_OK: Transceiver mode request has not been accepted.
 * PreCondition        CANIF_TRCV_NUMBER > 0
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetTrcvMode(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);
/*************************************************************************/
/*
 * Brief               This function invokes CanTrcv_GetOpMode and updates the parameter
 *                     TransceiverModePtr with the value OpMode provided by CanTrcv.
 * ServiceId           0x0e
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TransceiverId: Abstracted CanIf TransceiverId, which is assigned to a
 *                     CAN transceiver, which is requested for current operation mode.
 * Param-Name[out]     TransceiverModePtr: Requested mode of requested network the Transceiver is connected to.
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Transceiver mode request has been accepted.
 *                     E_NOT_OK: Transceiver mode request has not been accepted.
 * PreCondition        CANIF_TRCV_NUMBER > 0
 * CallByAPI           Up layer
 */
/*************************************************************************/
/* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
extern FUNC(Std_ReturnType, CANIF_CODE)
    CanIf_GetTrcvMode(P2VAR(CanTrcv_TrcvModeType, AUTOMATIC, CANIF_APPL_DATA) TransceiverModePtr, uint8 TransceiverId);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
/*************************************************************************/
/*
 * Brief               This service returns the reason for the wake up of the transceiver
 *                     TransceiverId, via calling the corresponding CAN Transceiver Driver service.
 * ServiceId           0x0f
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TransceiverId: Abstracted CanIf TransceiverId, which is assigned to a CAN
 *                     transceiver, which is requested for wake up reason.
 * Param-Name[out]     TrcvWuReasonPtr: provided pointer to where the requested transceiver wake
 *                     up reason shall be returned
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Transceiver wake up reason request has been accepted.
 *                     E_NOT_OK: Transceiver wake up reason request has not been accepted.
 * PreCondition        CANIF_TRCV_NUMBER > 0
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_GetTrcvWakeupReason(
    uint8 TransceiverId,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(CanTrcv_TrcvWakeupReasonType, AUTOMATIC, CANIF_APPL_DATA) TrcvWuReasonPtr);
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
/*************************************************************************/
/*
 * Brief               This function shall call CanTrcv_SetTrcvWakeupMode.
 * ServiceId           0x10
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TransceiverId: Abstracted CanIf TransceiverId, which is assigned to a
 *                     CAN transceiver, which is requested for wake up notification mode transition.
 *                     TrcvWakeupMode: Requested transceiver wake up notification mode
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Will be returned, if the wake up notifications state has been changed to the requested
 * mode. E_NOT_OK: Will be returned, if the wake up notifications state change has failed or the parameter is out of the
 * allowed range. The previous state has not been changed. PreCondition        CANIF_TRCV_NUMBER > 0 CallByAPI Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)
    CanIf_SetTrcvWakeupMode(uint8 TransceiverId, CanTrcv_TrcvWakeupModeType TrcvWakeupMode);
#endif /*CANIF_TRCV_NUMBER > 0u*/
#if (STD_ON == CANIF_WAKE_UP_SUPPORT)
/*************************************************************************/
/*
 * Brief               This service checks, whether an underlying CAN driver or a CAN
 *                     transceiver driver already signals a wakeup event.
 * ServiceId           0x11
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      WakeupSource: Source device, which initiated the wake up event:CAN controller or CAN transceiver
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Will be returned, if the check wake up request has been accepted
 *                     E_NOT_OK: Will be returned, if the check wake up request has not been accepted
 * PreCondition        CANIF_WAKE_UP_SUPPORT is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckWakeup(EcuM_WakeupSourceType WakeupSource);
#endif /*STD_ON == CANIF_WAKE_UP_SUPPORT*/
#if (STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT)
/*************************************************************************/
/*
 * Brief               This service is performed to validate a previous wakeup event.
 * ServiceId           0x12
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      WakeupSource: Source device which initiated the wake-up event and
 *                     which has to be validated: CAN controller or CAN transceiver
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Will be returned, if the check validation request has been accepted.
 *                     E_NOT_OK: Will be returned, if the check validation request has not been accepted.
 * PreCondition        CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckValidation(EcuM_WakeupSourceType WakeupSource);
#endif /*STD_ON == CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT*/
#if (STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT)
/*************************************************************************/
/*
 * Brief               This service reports, if any TX confirmation has been done for the whole
 *                     CAN controller since the last CAN controller start.
 * ServiceId           0x19
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (Not for the same controller)
 * Param-Name[in]      ControllerId: Abstracted CanIf ControllerId which is assigned to a CAN controller
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              CanIf_NotifStatusType:Combined TX confirmation status for all TX PDUs of the CAN controller
 * PreCondition        CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT is TRUE
 * CallByAPI           Up layer(CanSM)
 */
/*************************************************************************/
extern FUNC(CanIf_NotifStatusType, CANIF_CODE) CanIf_GetTxConfirmationState(uint8 ControllerId);
#endif /*STD_ON == CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT*/
#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
/*************************************************************************/
/*
 * Brief               Requests the CanIf module to clear the WUF flag of the designated CAN transceiver.
 * ServiceId           0x1e
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant for different CAN transceivers
 * Param-Name[in]      TransceiverId: Abstract CanIf TransceiverId, which is assigned to the designated CAN transceiver.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Request has been accepted
 *                     E_NOT_OK: Request has not been accepted
 * PreCondition        CANIF_PUBLIC_PN_SUPPORT is TRUE
 * CallByAPI           Up layer(CanSM)
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_ClearTrcvWufFlag(uint8 TransceiverId);
/*************************************************************************/
/*
 * Brief               Requests the CanIf module to check the Wake flag of the designated CAN transceiver.
 * ServiceId           0x1f
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant for different CAN transceivers
 * Param-Name[in]      TransceiverId: Abstract CanIf TransceiverId, which is assigned to the designated CAN transceiver.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Request has been accepted
 *                     E_NOT_OK: Request has not been accepted
 * PreCondition        None
 * CallByAPI           Up layer(CanSM)
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_CheckTrcvWakeFlag(uint8 TransceiverId);
#endif /*STD_ON == CANIF_PUBLIC_PN_SUPPORT*/
#if (STD_ON == CANIF_SET_BAUDRATE_API)
/*************************************************************************/
/*
 * Brief               This service shall set the baud rate configuration of the CAN controller.
 *                     Depending on necessary baud rate modifications the controller might have to reset.
 * ServiceId           0x27
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different ControllerIds. Non reentrant for the same ControllerId.
 * Param-Name[in]      ControllerId: Abstract CanIf ControllerId which is assigned to a CAN controller, whose baud rate
 * shall be set. BaudRateConfigID: references a baud rate configuration by ID (see CanControllerBaudRateConfigID)
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Service request accepted, setting of (new) baud rate started
 *                     E_NOT_OK: Service request not accepted
 * PreCondition        CANIF_SET_BAUDRATE_API is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE) CanIf_SetBaudrate(uint8 ControllerId, uint16 BaudRateConfigID);
#endif /*STD_ON == CANIF_SET_BAUDRATE_API*/
#if (STD_ON == CANIF_PUBLIC_ICOM_SUPPORT)
/*************************************************************************/
/*
 * Brief               This service shall change the Icom Configuration of a CAN controller to the requested one.
 * ServiceId           0x25
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant only for different controller Ids
 * Param-Name[in]      ControllerId: Abstracted CanIf Controller Id which is assigned to a CAN controller.
 *                     ConfigurationId: Requested Configuration
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 *                     E_OK: Request accepted
 *                     E_NOT_OK: Request denied
 * PreCondition        CANIF_PUBLIC_ICOM_SUPPORT is TRUE
 * CallByAPI           Up layer
 */
/*************************************************************************/
extern FUNC(Std_ReturnType, CANIF_CODE)
    CanIf_SetIcomConfiguration(uint8 ControllerId, IcomConfigIdType ConfigurationId);
#endif /*STD_ON == CANIF_PUBLIC_ICOM_SUPPORT*/

extern VAR(boolean, CANIF_VAR) CanIf_FirstCallRxInd[CANIF_CANCONTROLLER_NUMBER];
#endif /* end of CANIF_H */
