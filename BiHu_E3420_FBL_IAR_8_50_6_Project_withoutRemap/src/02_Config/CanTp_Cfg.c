
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
**  FILENAME    : CanTp_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2024/01/05 14:43:47                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : TP (ISO 15765-2) Configration file.                         **
**                                                                            **
**  SPECIFICATION(S) :  ISO 15765-2                                           **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/** <VERSION>   <DATE>     <AUTHOR>          <REVISION LOG>
 *  V1.0.0     20230817    long.zhu          Initial Version
 *
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR_Cfg.h"
#include "CanTp_Cfg.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
/* RX SDU Configure */
const CanTp_RxSduType CanTp_RxSdu[CANTP_RX_CHANNEL_NUM] =
{
    {
        /* rxDcmId */
        /* @type:uint16 range:0x0000~0xFFFF note:auto generate */
        (uint16)PDUR_CANTP_RX_PHY_PDU_ID,
        /* rxPduId */
        /* @type:uint16 range:0x0000~0xFFFF note:reference to Can_RxPdu->pduId */
        0,
        /* addressingFormat */
        CANTP_STANDARD,
        /* nSa */
        /* @type:uint8 range:0x00~0xFF note:NONE */
        (uint8)0x0u,
        /* txFcPduId */
        /* @type:uint16 range:0x0000~0xFFFF note:reference to Can_TxPdu->pduId */
        0x0u,
        /*CanFrameType*/
        CAN_FD,
        /*RxNPduDLC*/
        (uint16)64u,
        RX_PHYSICAL_ADDRESSING
    },
    {
        /* rxDcmId */
        /* @type:uint16 range:0x0000~0xFFFF note:auto generate */
        (uint16)PDUR_CANTP_RX_FUNC_PDU_ID,
        /* rxPduId */
        /* @type:uint16 range:0x0000~0xFFFF note:reference to Can_RxPdu->pduId */
        1,
        /* addressingFormat */
        CANTP_STANDARD,
        /* nSa */
        /* @type:uint8 range:0x00~0xFF note:NONE */
        (uint8)0x0u,
        /* txFcPduId */
        /* @type:uint16 range:0x0000~0xFFFF note:reference to Can_TxPdu->pduId */
        0x0u,
        /*CanFrameType*/
        CAN_FD,
        /*RxNPduDLC*/
        (uint16)64u,
        RX_FUNCTIONAL_ADDRESSING,
    },
        {
        /* rxDcmId */
        /* @type:uint16 range:0x0000~0xFFFF note:auto generate */
        (uint16)PDUR_CANTP_FD_RX_PHY_PDU_ID,
        /* rxPduId */
        /* @type:uint16 range:0x0000~0xFFFF note:reference to Can_RxPdu->pduId */
        2,
        /* addressingFormat */
        CANTP_STANDARD,
        /* nSa */
        /* @type:uint8 range:0x00~0xFF note:NONE */
        (uint8)0x0u,
        /* txFcPduId */
        /* @type:uint16 range:0x0000~0xFFFF note:reference to Can_TxPdu->pduId */
        0x1u,
        /*CanFrameType*/
        CAN_FD,
        /*RxNPduDLC*/
        (uint16)64u,
        RX_PHYSICAL_ADDRESSING,
    },
    {
        /* rxDcmId */
        /* @type:uint16 range:0x0000~0xFFFF note:auto generate */
        (uint16)PDUR_CANTP_FD_RX_FUNC_PDU_ID,
        /* rxPduId */
        /* @type:uint16 range:0x0000~0xFFFF note:reference to Can_RxPdu->pduId */
        3,
        /* addressingFormat */
        CANTP_STANDARD,
        /* nSa */
        /* @type:uint8 range:0x00~0xFF note:NONE */
        (uint8)0x0u,
        /* txFcPduId */
        /* @type:uint16 range:0x0000~0xFFFF note:reference to Can_TxPdu->pduId */
        0x1u,
        /*CanFrameType*/
        CAN_FD,
        /*RxNPduDLC*/
        (uint16)64u,
        RX_FUNCTIONAL_ADDRESSING,
    },
};

/* TX SDU Configure */
const CanTp_TxSduType CanTp_TxSdu[CANTP_TX_CHANNEL_NUM] =
{
    {
        /* txDcmId */
        /* @type:uint16 range:0x0000~0xFFFF note:auto generate */
        PDUR_CANTP_TX_PDU_ID,
        /* txPduId */
        /* @type:uint16 range:0x0000~0xFFFF note:reference to Can_TxPdu->pduId */
        0x00u,
        /* rxFcPduId */
        /* @type:uint16 range:0x0000~0xFFFF note:reference to Can_RxPdu->pduId */
        0x00u,
        /* addressingFormat */
        CANTP_STANDARD,
        /*CanFrameType*/
        CAN_FD,
        /* nTa */
        /* @type:uint8 range:0x00~0xFF note:NONE */
        (uint8)0x0u,
        /*TxNPduDLC*/
        (uint16)64u,
        /*Padding*/
        0xCC,
    },
    {
        /* txDcmId */
        /* @type:uint16 range:0x0000~0xFFFF note:auto generate */
        PDUR_CANTP_FD_TX_PDU_ID,
        /* txPduId */
        /* @type:uint16 range:0x0000~0xFFFF note:reference to Can_TxPdu->pduId */
        0x01u,
        /* rxFcPduId */
        /* @type:uint16 range:0x0000~0xFFFF note:reference to Can_RxPdu->pduId */
        0x02u,
        /* addressingFormat */
        CANTP_STANDARD,
        /*CanFrameType*/
        CAN_FD,
        /* nTa */
        /* @type:uint8 range:0x00~0xFF note:NONE */
        (uint8)0x0u,
        /*TxNPduDLC*/
        (uint16)64u,
        /*Padding*/
        0xCC,
    }
    
};

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

