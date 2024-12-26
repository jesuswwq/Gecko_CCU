/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2023)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : CanIf.c                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : The CAN Interface module provides a unique interface to     **
**  manage different CAN hardware device types like CAN Controllers used by   **
**  the definedECU hardware layout.                    						  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR_SWS_CANInterface R19-11	                  **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20130522     WBN	            Initial Version
 *  V1.0.1     20180511    CChen            update
 *  V1.0.2     20200310   Lianren.Wu        QAC-9.5.0 test
 */
#ifndef CANIF_H_
#define CANIF_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf_Type.h"
#include "CanIf_Cfg.h"
#include "CanTp.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
extern const CanIf_TxChannelType CanIfTxCh[CANIF_TX_CHANNEL_NUM];
extern const CanIf_RxChannelType CanIfRxCh[CANIF_RX_CHANNEL_NUM];


/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               <This service Initializes internal and external interfaces
 * 						of the CAN Interface for the further processing.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 */
/******************************************************************************/
extern void CanIf_Init(void);
/******************************************************************************/
/*
 * @brief              [CanIf_DeInit description]
 * @sync/async         [Synchronous]
 * @reentrancy         [NoReentrant]
 * @param-name[in]     [NONE]
 * @param-name[out]    [NONE]
 * @param-name[in/out] [NONE]
 * @return             [NONE]
 */
/******************************************************************************/
extern void CanIf_DeInit(void);
/******************************************************************************/
/*
 * Brief               <Requests transmission of a PDU.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <PduId: Identifier of the PDU to be transmitted.
 * 					    *PduInfoPtr: Length of and pointer to the PDU data and pointer to MetaData.>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType:E_OK: Transmit request has been accepted.
 *									   E_NOT_OK: Transmit request has not been accepted>
 */
/******************************************************************************/
extern Std_ReturnType CanIf_Transmit(PduIdType PduId, const PduInfoType* PduInfoPtr);

/******************************************************************************/
/*
 * Brief               <This service confirms a previously successfully processed transmission of a CAN TxPDU.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <CanTxPduId:L-PDU handle of CAN L-PDU successfully transmitted.>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 */
/******************************************************************************/
extern void CanIf_TxConfirmation(PduIdType CanTxPduId);

/******************************************************************************/
/*
 * Brief               CAN If Rx Indication
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <Hrh, CanId, CanDlc, *CanSduPtr>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 */
/******************************************************************************/
extern void CanIf_RxIndication(const Can_HwType * Mailbox,const PduInfoType *PduInfoPtr);
/******************************************************************************/
/*
 * Brief               <CAN If Main Function>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 */
/******************************************************************************/
extern void CanIf_MainFunction(void);

#endif /* endif of CANIF_H_ */
