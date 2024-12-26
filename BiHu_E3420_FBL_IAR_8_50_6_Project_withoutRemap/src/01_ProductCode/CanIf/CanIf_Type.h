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
**  FILENAME    : CanIf_Type.h                                                **
**                                                                            **
**  Created on  :                                                             **
**  Author      : long.zhu                                               	  **
**  Vendor      :                                                             **
**  DESCRIPTION : Type define decalrations for canif			              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR_SWS_CANInterface R19-11                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0      20230816   long.zhu	          Initial Version
 */
#ifndef CANIF_TYPE_H_
#define CANIF_TYPE_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "ComStack_Types.h"
#include "Can_GeneralTypes.h"
#include "CanIf_Types.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
typedef enum
{
	/* extended 29 */
	CANIF_TX_EXTENDED_CAN = 0u,
	CANIF_TX_EXTENDED_FD_CAN = 1u,
	/* standard 11 */
	CANIF_TX_STANDARD_CAN = 2u,
	CANIF_TX_STANDARD_FD_CAN = 3u
} CanIf_TxPduCanIdMode;

typedef enum
{
	/* extended 29 */
	CANIF_RX_EXTENDED_CAN = 0u,
	CANIF_RX_EXTENDED_FD_CAN = 1u,
	CANIF_RX_EXTENDED_NO_FD_CAN = 2u,
	/* standard 11 */
	CANIF_RX_STANDARD_CAN = 3u,
	CANIF_RX_STANDARD_FD_CAN = 4u,
	CANIF_RX_STANDARD_NO_FD_CAN = 5u
} CanIf_RxPduCanIdMode;

typedef void (*CanIf_TxConfirmationFct)(const PduIdType TpPduId);
typedef void (*RxIndicationFct)(const PduIdType TpPduId, const PduInfoType* const CanTp_objRxPtr);

typedef struct
{
	/* symbolic handle for transmit CAN L_PDU */
	const PduIdType PduId;
	/* symbolic handle of TP layer */
	const PduIdType TpPduId;
	/* CAN Identifier of transmit CAN L-PDUs used by the CAN Driver for CAN L-PDU transmission */
	const Can_IdType CanId;
	/* symbolic handle of hardware */
	const uint8 ObjectId;
	const CanIf_TxPduCanIdMode TxcanIdMode;
	/* name of target confirmation services to target upper layers */
	CanIf_TxConfirmationFct TxConf;
} CanIf_TxChannelType;

typedef struct
{
	/* symbolic handle for receive CAN L-PDU */
	const PduIdType PduId;
	/* symbolic handle of TP layer */
	const PduIdType TpPduId;
	/* CAN Identifier of receive CAN L-PDUs used by the CAN Driver for CAN L-PDU reception */
	const Can_IdType CanId;
	/* symbolic handle of hardware */
	const uint8 ObjectId;
	const CanIf_RxPduCanIdMode RxcanIdMode;
	const uint32 Mask;
	/* name of target indication services to target upper layers */
	RxIndicationFct RxInd;
} CanIf_RxChannelType;

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/

/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/

#endif/* endif of CANIF_TYPE_H_ */
