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
**  FILENAME    : CanNm_Cbk.h                                            **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>      <AUTHOR>       <REVISION LOG>
 *  V2.0.0       2020-07-29  Wanglili       R19_11 initial version.
 */
#ifndef CANNM_CBK_H_
#define CANNM_CBK_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm_Cfg.h"
#include "ComStack_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/******************************************************************************/
/*
 * Brief               Indication of a received PDU from a lower layer communication
 *                     interface module.
 * ServiceId           0x42
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same
 *                     PduId.
 * Param-Name[in]      RxPduId, ID of the received PDU.
 *                     PduInfoPtr, Contains the length (SduLength) of the received
 *                     PDU, a pointer to a buffer (SduDataPtr) containing the PDU,
 *                     and the MetaData related to this PDU.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, CANNM_CODE)
CanNm_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr);

#if ((STD_OFF == CANNM_IMMEDIATE_TXCONF_ENABLED) && (STD_OFF == CANNM_PASSIVE_MODE_ENABLED))

/******************************************************************************/
/*
 * Brief               The lower layer communication interface module confirms
 *                     the transmission of a PDU, or the failure to transmit a PDU.
 * ServiceId           0x40
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same
 *                     PduId.
 * Param-Name[in]      TxPduId, ID of the PDU that has been transmitted.
 *                     result, E_OK: The PDU was transmitted. E_NOT_OK: Transmission
 *                     of the PDU failed.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, CANNM_CODE)
CanNm_TxConfirmation(PduIdType TxPduID);

#endif /* #if((STD_OFF == CANNM_IMMEDIATE_TXCONF_ENABLED) && \
         (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)) */

#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)

/******************************************************************************/
/*
 * Brief               Enables the PN filter functionality on the indicated NM
 *                     channel.
 * ServiceId           0x16
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (but not for the same NM-channel)
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, CANNM_CODE)
CanNm_ConfirmPnAvailability(NetworkHandleType nmChannelHandle);

#endif /* STD_ON == CANNM_GLOBAL_PN_SUPPORT */

/******************************************************************************/
/*
 * Brief               Within this API,the upper layer module (called module) shall
 *                     check whether the available data fits into the buffer size
 *                     reported by PduInfoPtr->SduLength. If it fits, it shall copy
 *                     its data into the buffer provided by PduInfoPtr->SduDataPtr
 *                     and update the length of the actual copied data in
 *                     PduInfoPtr->SduLength.
 * ServiceId           0x41
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same
 *                     PduId.
 * Param-Name[in]      TxPduId, ID of the SDU that is requested to be transmitted.
 * Param-Name[out]     None
 * Param-Name[in/out]  PduInfoPtr, Contains a pointer to a buffer (SduDataPtr) to
 *                     where the SDU data shall be copied, and the available buffer
 *                     size in SduLengh.
 * Return              E_OK: SDU has been copied and SduLength indicates the number
 *                     of copied bytes.
 *                     E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be
                       used since it may contain a NULL pointer or point to invalid
                       data.
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_TriggerTransmit(PduIdType TxPduId, PduInfoType* PduInfoPtr);

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
#endif /* CANNM_CBK_H_ */
