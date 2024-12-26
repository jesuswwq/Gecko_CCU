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
**  FILENAME    : CanTp.h                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                               	  **
**  Vendor      :                                                             **
**  DESCRIPTION : TP (ISO 15765-2) source component.                          **
**                                                                            **
**  SPECIFICATION(S) : ISO15765-2-2016.pdf       		                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20121228    Tommy Yu          Initial version
 *  V1.0.1     20180511    CChen             update
 *  V1.0.2     20190101    Lianren Wu        QAC Test Pass
 *  V1.0.3     20190403    Lianren Wu        delete the invalid type and.
 */
#ifndef CAN_TP_H
#define CAN_TP_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanTp_Type.h"
#include "CanTp_Cfg.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
extern const CanTp_RxSduType CanTp_RxSdu[CANTP_RX_CHANNEL_NUM];
extern const CanTp_TxSduType CanTp_TxSdu[CANTP_TX_CHANNEL_NUM];

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/********************************************************************************/
/****
 * brief            : CanTp_Init
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <NONE>
 * param[out]       : <NONE>
 * param[in/out]    : <NONE>
 * return           : <NONE>
 */
/********************************************************************************/
extern void CanTp_Init(void);

/********************************************************************************/
/****
 * brief            : CanTp_RxIndication
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <CanTp_pduId:ID of the received PDU.
 * 					   CanTp_objRxPtr:Contains the length (SduLength) of the received PDU, a pointer to a
 *						buffer (SduDataPtr) containing the PDU, and the MetaData related to this
 *						PDU.>
 * param[out]       : <NONE>
 * param[in/out]    : <NONE>
 * return           : <NONE>
 */
/********************************************************************************/
extern void CanTp_RxIndication(PduIdType CanTp_pduId, const PduInfoType* CanTp_objRxPtr);

/********************************************************************************/
/****
 * brief            : CanTp_Transmit
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <CanTp_txSduId:Identifier of the PDU to be transmitted.
 * 					   CanTp_txInfoPtr: Length of and pointer to the PDU data and pointer to Meta
 *										Data.>
 * param[out]       : <NONE>
 * param[in/out]    : <NONE>
 * return           : <Std_ReturnType:
 * 						E_OK: Transmit request has been accepted.
 *						E_NOT_OK: Transmit request has not been accepted.>
 */
/********************************************************************************/
extern Std_ReturnType CanTp_Transmit(const PduIdType CanTp_txSduId, const PduInfoType* CanTp_txInfoPtr);

/********************************************************************************/
/****
 * brief            :CanTp_TxConfirmation
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <CanTp_pduId:ID of the PDU that has been transmitted.>
 * param[out]       : <NONE>
 * param[in/out]    : <NONE>
 * return           : <NONE>
 */
/********************************************************************************/
extern void CanTp_TxConfirmation(const PduIdType CanTp_pduId);

/********************************************************************************/
/****
 * brief            :The main function for scheduling the CAN TP.
 * Sync/Async       : <Synchronous>
 * Reentrancy       : <Reentrant>
 * param[in]        : <NONE>
 * param[out]       : <NONE>
 * param[in/out]    : <NONE>
 * return           : <NONE>
 */
/********************************************************************************/
extern void CanTp_MainFunction(void);

#endif /* endif of CAN_TP_H */
