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
**  FILENAME    : CanIf_Cbk.h                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Callback declaration supplied by CANIF                      **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
#ifndef CANIF_CBK_H
#define CANIF_CBK_H
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "CanIf.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define CANIF_CBK_H_AR_MAJOR_VERSION 4u
#define CANIF_CBK_H_AR_MINOR_VERSION 2u
#define CANIF_CBK_H_AR_PATCH_VERSION 2u
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#if (STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT)
/*************************************************************************/
/*
 * Brief               Within this API, the upper layer module (called module) shall check
 *                     whether the available data fits into the buffer size reported by PduInfoPtr-
 *                     >SduLength. If it fits, it shall copy its data into the buffer provided by
 *                     PduInfoPtr->SduDataPtr and update the length of the actual copied data in
 *                     PduInfoPtr->SduLength. If not, it returns E_NOT_OK without changing PduInfoPtr.
 * ServiceId           0x41
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same PduId.
 * Param-Name[in]      TxPduId: ID of the SDU that is requested to be transmitted.
 * Param-Name[out]     None
 * Param-Name[in/out]  PduInfoPtr: Contains a pointer to a buffer (SduDataPtr) to where the SDU data
 *                     shall be copied, and the available buffer size in SduLengh.On return, the
 *                     service will indicate the length of the copied SDU data in SduLength.
 * Return              Std_ReturnType
 *                     E_OK: SDU has been copied and SduLength indicates the number of copied bytes.
 *                     E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be used since it may
 *                     contain a NULL pointer or point to invalid data.
 * PreCondition        CANIF_TRIGGER_TRANSMIT_SUPPORT is TRUE
 * CallByAPI           Lo layer
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, CANIF_CODE)
    CanIf_TriggerTransmit(PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr);

#endif /*STD_ON == CANIF_TRIGGER_TRANSMIT_SUPPORT*/
/*************************************************************************/
/*
 * Brief               This service confirms a previously successfully processed transmission of a CAN TxPDU.
 * ServiceId           0x13
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CanTxPduId: L-PDU handle of CAN L-PDU successfully transmitted.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Can driver
 */
/*************************************************************************/

extern FUNC(void, CANIF_CODE) CanIf_TxConfirmation(PduIdType CanTxPduId);

/*************************************************************************/
/*
 * Brief               This service indicates a successful reception of a received CAN Rx LPDU
 *                     to the CanIf after passing all filters and validation checks.
 * ServiceId           0x14
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Mailbox: Identifies the HRH and its corresponding CAN Controller
 *                     PduInfoPtr: Pointer to the received L-PDU
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Can driver
 */
/*************************************************************************/

extern FUNC(void, CANIF_CODE) CanIf_RxIndication(
    P2CONST(Can_HwType, AUTOMATIC, CANIF_APPL_DATA) Mailbox,
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_DATA) PduInfoPtr);

/*************************************************************************/
/*
 * Brief               This service indicates a Controller BusOff event referring to
 *                     the corresponding CAN Controller with the abstract CanIf ControllerId.
 * ServiceId           0x16
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ControllerId: Abstract CanIf ControllerId which is assigned to a CAN
 *                     controller, where a BusOff occured.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Can driver
 */
/*************************************************************************/

extern FUNC(void, CANIF_CODE) CanIf_ControllerBusOff(uint8 ControllerId);

#if (STD_ON == CANIF_PUBLIC_PN_SUPPORT)
/*************************************************************************/
/*
 * Brief               This service indicates that the transceiver is running in PN
 *                     communication mode referring to the corresponding CAN transceiver
 *                     with the abstract CanIf TransceiverId.
 * ServiceId           0x1a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      TransceiverId: Abstract CanIf TransceiverId, which is assigned to
 *                     a CAN transceiver, which was checked for PN availability.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_PUBLIC_PN_SUPPORT is TRUE
 * CallByAPI           CanTrcv driver
 */
/*************************************************************************/

extern FUNC(void, CANIF_CODE) CanIf_ConfirmPnAvailability(uint8 TransceiverId);

/*************************************************************************/
/*
 * Brief               This service indicates that the transceiver has cleared the WufFlag
 *                     referring to the corresponding CAN transceiver with the abstract CanIf TransceiverId.
 * ServiceId           0x20
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      TransceiverId: Abstract CanIf TransceiverId, which is assigned to a CAN transceiver,
 *                     for which this function was called.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_PUBLIC_PN_SUPPORT is TRUE
 * CallByAPI           CanTrcv driver
 */
/*************************************************************************/

extern FUNC(void, CANIF_CODE) CanIf_ClearTrcvWufFlagIndication(uint8 TransceiverId);

/*************************************************************************/
/*
 * Brief               This service indicates that the check of the transceiver's wake-up flag
 *                     has been finished by the corresponding CAN transceiver with the abstract
 *                     CanIf TransceiverId. This indication is used to cope with the asynchronous
 *                     transceiver communication.
 * ServiceId           0x21
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      TransceiverId: Abstract CanIf TransceiverId, which is assigned to a CAN
 *                     transceiver, for which this function was called.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_PUBLIC_PN_SUPPORT is TRUE
 * CallByAPI           CanTrcv driver
 */
/*************************************************************************/

extern FUNC(void, CANIF_CODE) CanIf_CheckTrcvWakeFlagIndication(uint8 TransceiverId);

#endif /*STD_ON == CANIF_PUBLIC_PN_SUPPORT*/
/*************************************************************************/
/*
 * Brief               This service indicates a controller state transition referring
 *                     to the corresponding CAN controller with the abstract CanIf ControllerId.
 * ServiceId           0x17
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ControllerId: Abstract CanIf ControllerId which is assigned to a
 *                     CAN controller, which state has been transitioned.
 *                     ControllerMode: Mode to which the CAN controller transitioned
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        None
 * CallByAPI           Can driver
 */
/*************************************************************************/

extern FUNC(void, CANIF_CODE)
    CanIf_ControllerModeIndication(uint8 ControllerId, CanIf_ControllerModeType ControllerMode);

#if (CANIF_TRCV_NUMBER > 0u)
/*************************************************************************/
/*
 * Brief               This service indicates a transceiver state transition referring
 *                     to the corresponding CAN transceiver with the abstract CanIf TransceiverId.
 * ServiceId           0x22
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      TransceiverId: Abstract CanIf TransceiverId, which is assigned to a
 *                     CAN transceiver, which state has been transitioned.
 *                     TransceiverMode Mode to which the CAN transceiver transitioned
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_TRCV_NUMBER > 0
 * CallByAPI           CanTrcv driver
 */
/*************************************************************************/

extern FUNC(void, CANIF_CODE) CanIf_TrcvModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode);

#endif /*CANIF_TRCV_NUMBER > 0u*/
#if (STD_ON == CANIF_PUBLIC_ICOM_SUPPORT)
/*************************************************************************/
/*
 * Brief               This service shall inform about the change of the Icom Configuration of
 *                     a CAN controller using the abstract CanIf ControllerId.
 * ServiceId           0x26
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant only for different controller Ids
 * Param-Name[in]      ControllerId: Abstract CanIf ControllerId which is assigned to a CAN
 *                     controller, which informs about the Configuration Id.
 *                     ConfigurationId: Active Configuration Id.
 *                     Error:
 *                     ICOM_SWITCH_E_OK: No Error
 *                     ICOM_SWITCH_E_FAILED: Switch to requested Configuration failed. Severe Error.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * PreCondition        CANIF_PUBLIC_ICOM_SUPPORT is TRUE
 * CallByAPI           Can driver
 */
/*************************************************************************/

extern FUNC(void, CANIF_CODE)
    CanIf_CurrentIcomConfiguration(uint8 ControllerId, IcomConfigIdType ConfigurationId, IcomSwitch_ErrorType Error);

#endif /*STD_ON == CANIF_PUBLIC_ICOM_SUPPORT*/

#endif /* CANIF_CBK_H */
