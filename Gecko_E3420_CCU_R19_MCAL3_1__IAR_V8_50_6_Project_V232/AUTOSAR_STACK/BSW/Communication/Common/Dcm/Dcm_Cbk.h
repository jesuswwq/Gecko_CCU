/******************************************************************************
**                                                                           **
** Copyright (C) iSOFT   (2022)                                              **
**                                                                           **
** All rights reserved.                                                      **
**                                                                           **
** This document contains proprietary information belonging to iSOFT.        **
** Passing on and copying of this document, and communication                **
** of its contents is not permitted without prior written authorization.     **
**                                                                           **
**************************************************************************** **
**                                                                           **
**  FILENAME    :                                                            **
**                                                                           **
**  Created on  : 2020/5/6 14:29:43                                          **
**  Author      : tao.yu                                                     **
**  Vendor      :                                                            **
**  DESCRIPTION :                                                            **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                      **
**                                                                           **
**************************************************************************** */

#ifndef COMMUNICATION_DCM_DCM_CBK_H_
#define COMMUNICATION_DCM_DCM_CBK_H_

#include "ComStack_Types.h"
/*************************************************************************/
/*
 * Brief               <This function is called at the start
                        of receiving an N-SDU. The N-SDU might be
                        fragmented into multiple N-PDUs
                        (FF with one or more following CFs) or might
                        consist of a single N-PDU (SF)>
 * ServiceId           <0x46>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <DcmRxPduId:  the received data PduId;
 *                      TpSduLength: This length identifies the overall
 *                      number of bytes to be received.>
 * Param-Name[out]     <PduInfoPtr:  Pointer to pointer to PduInfoType
 * containing data pointer and length of a receive buffe>
 * Param-Name[in/out]  <None>
 * Return              <BUFREQ_OK:
 *                      BUFREQ_E_NOT_OK:
 *                      BUFREQ_E_OVFL:
 *                      BUFREQ_E_BUSY:>
 * PreCondition        <None>
 * CallByAPI           <>
 */
/*************************************************************************/

extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_StartOfReception(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_CONST) info,
    PduLengthType TpSduLength,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, DCM_VAR) bufferSizePtr);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

/*************************************************************************/
/*
 * Brief               <This function is called to provide the received data
 *                      of an I-PDU segment (N-PDU) to the upper layer.Each
 *                      call to this function provides the next part of the
 *                      I-PDU data.The size of the remaining data is written
 *                      to the position indicated by bufferSizePtr>
 * ServiceId           <0x44>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <DcmRxPduId:  the received data PduId;
 * Param-Name[out]     <PduInfoPtr:  Pointer to pointer to PduInfoType
 * containing data pointer and length of a receive buffe>
 * Param-Name[in/out]  <None>
 * Return              <BUFREQ_OK:
 *                      BUFREQ_E_NOT_OK:
 *                      BUFREQ_E_OVFL:
 *                      BUFREQ_E_BUSY:>
 * PreCondition        <None>
 * CallByAPI           <>
 */
/*************************************************************************/

extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyRxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_CONST) info,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, DCM_VAR) bufferSizePtr);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

/*************************************************************************/
/*
 * Brief               <Called after an I-PDU has been received via the
 *                      TP API, the result indicates whether the
 *                      transmission was successful or not.>
 * ServiceId           <0x45>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <DcmRxPduId:ID of DCM I-PDU that has been received
 *                      Result: The result of the diagnostic request message received>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <this function must be called after
 * call of Dcm_StartOfReception() and Dcm_CopyRxData()>
 * CallByAPI           <None>
 */
/*************************************************************************/

extern FUNC(void, DCM_CODE) Dcm_TpRxIndication(PduIdType id, Std_ReturnType result);

/*************************************************************************/
/*
 * Brief               <This function is called to provide the received data
 *                      of an I-PDU segment (N-PDU) to the upper layer.Each
 *                      call to this function provides the next part of the
 *                      I-PDU data.The size of the remaining data is written
 *                      to the position indicated by bufferSizePtr>
 * ServiceId           <0x43>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <DcmRxPduId:  the received data PduId;
 * Param-Name[out]     <PduInfoPtr:  Pointer to pointer to PduInfoType
 * containing data pointer and length of a receive buffe>
 *                     <retry:This parameter is used to acknowledge transmitted
 *                      data or to retransmit data after transmission problems.>
 * Param-Name[in/out]  <None>
 * Return              <BUFREQ_OK:
 *                      BUFREQ_E_NOT_OK:
 *                      BUFREQ_E_OVFL:
 *                      BUFREQ_E_BUSY:>
 * PreCondition        <None>
 * CallByAPI           <>
 */
/*************************************************************************/

extern FUNC(BufReq_ReturnType, DCM_CODE) Dcm_CopyTxData(
    PduIdType id,
    P2CONST(PduInfoType, AUTOMATIC, DCM_CONST) info,
    P2CONST(RetryInfoType, AUTOMATIC, DCM_VAR) retry,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, DCM_VAR) availableDataPtr);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

/*************************************************************************/
/*
 * Brief               <This is called by the PduR to confirm a Transmit>
 * ServiceId           <0x48>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <DcmTxPduId:ID of DCM I-PDU that has been transmitted.
 *                      Result: NTFRSLT_OK: the complete N-PDU has been transmitted.
 *                              NTFRSLT_E_CANCELATION_OK: the N-PDU has been successfully
 *                              cancelled.
 *                              NTFRSLT_E_CANCELATION_NOT_OK: an error occurred when
 *                              cancelling the N-PDU.
 *                              any other value: an error occurred during transmission>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <this function must be called after call of DcmProvideTxBuffer().>
 * CallByAPI           <>
 */
/*************************************************************************/

extern FUNC(void, DCM_CODE) Dcm_TpTxConfirmation(PduIdType id, Std_ReturnType result);

/*************************************************************************/
/*
 * Brief               <The lower layer communication interface module
 *                       confirms the transmission of an IPDU.>
 * ServiceId           <0x40>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <DcmTxPduId:ID of DCM I-PDU that has been transmitted.
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <>
 */
/*************************************************************************/

extern FUNC(void, DCM_CODE) Dcm_TxConfirmation(PduIdType DcmTxPduId);

/*************************************************************************/
/*
 * Brief               <ComM module notice DCM modules,
 * network communication mode is DCM_COMM_NO_COMMUNICATION>
 * ServiceId           <0x21>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/

extern FUNC(void, DCM_CODE) Dcm_ComM_NoComModeEntered(uint8 NetworkId);

/*************************************************************************/
/*
 * Brief               <ComM module notice DCM modules,
 * network communication mode is DCM_COMM_SILENT_COMMUNICATION>
 * ServiceId           <0x22>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/

extern FUNC(void, DCM_CODE) Dcm_ComM_SilentComModeEntered(uint8 NetworkId);

/*************************************************************************/
/*
 * Brief               <ComM module notice DCM modules,
 * network communication mode is DCM_COMM_FULL_COMMUNICATION>
 * ServiceId           <0x23>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <>
 */
/*************************************************************************/

extern FUNC(void, DCM_CODE) Dcm_ComM_FullComModeEntered(uint8 NetworkId);

#endif /* COMMUNICATION_DCM_DCM_CBK_H_ */
