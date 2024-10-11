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
**  FILENAME    : CanTp_Cbk.h                                                **
**                                                                           **
**  Created on  : 2021/7/30 14:29:43                                         **
**  Author      : tao.yu                                                     **
**  Vendor      :                                                            **
**  DESCRIPTION : Call-back function declarations                            **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                     **
**                                                                           **
**************************************************************************** */

#ifndef CANTP_CBK_H
#define CANTP_CBK_H

/*=======[I N C L U D E S]====================================================*/
#include "CanTp_Types.h"

BEGIN_C_DECLS

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
/*
 * Brief               This function is called by the CAN Interface after a successful
 *                     reception of a RX CAN L-PDU.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CanTpRxPduId the received N-PDU ID
 *                     CanTpRxPduPtr indicator of structure with received
 *                                   L-SDU(payload) and data length
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        CanTp initialized
 * CallByAPI           CAN Interface Receiving handling
 */
extern FUNC(void, CANTP_APPL_CODE)
    CanTp_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr);

/*
 * Brief               All transmitted CAN frames belonging to the CAN Transport
 *                     Layer will be confirmed by this function.
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CanTpTxPduId ID of CAN L-PDU that has been transmitted
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        CanTp initialized
 * CallByAPI           CAN Interface transmitting confirmation
 */
extern FUNC(void, CANTP_APPL_CODE) CanTp_TxConfirmation(PduIdType TxPduId);

END_C_DECLS

#endif /* CANTP_CBK_H */

/*=======[E N D   O F   F I L E]==============================================*/
