
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
**  FILENAME    : CanIf_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2023/11/23 14:59:01                                         **
**  Author      : long.zhu                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Implementation for canif                                    **
**                                                                            **
**  SPECIFICATION(S) : NONE                                                   **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/* <VERSION>    <DATE>      <AUTHOR>         <REVISION LOG>
 *  V1.0.0     20230818     LONG.ZHU         Initial version
 ******************************************************************************/

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR_Cfg.h"
#include "CanIf.h"
#include "CanIf_Cfg.h"
#include "CanIf_Type.h"
#include "CanTp_Cfg.h"

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#define CAN_RX_ID_PHY                      0x701
#define CAN_RX_ID_FUNC                     0x7df
#define CAN_TX_ID_RESP                     0x781
#define CAN_RX_OBJECT_PHY                     CAN_HRH_RX_PHY
#define CAN_RX_OBJECT_FUNC                    CAN_HTH_RX_FUNC
#define CAN_TX_OBJECT_RESP                    CAN_HRH_TX_RESP
#define CAN_RX_ID_PHY_OTA                      0x701
#define CAN_RX_ID_FUNC_OTA                     0x7df
#define CAN_TX_ID_RESP_OTA                     0x781
#define CAN_RX_OBJECT_PHY_OTA                     CAN_HRH_RX_PHY_OTA
#define CAN_RX_OBJECT_FUNC_OTA                    CAN_HTH_RX_FUNC_OTA
#define CAN_TX_OBJECT_RESP_OTA                    CAN_HRH_TX_RESP_OTA



const CanIf_TxChannelType CanIfTxCh[CANIF_TX_CHANNEL_NUM] =
{
    {
        /* PduId */
        0x0u,
        /* TpPduId */
        0x0u,
        /* CanId */
        (uint32)CAN_TX_ID_RESP,
        /* ObjectId */
        CAN_TX_OBJECT_RESP,
        /* TxcanIdMode */
        CANIF_TX_STANDARD_FD_CAN,
        /* TxConf */
        &CanTp_TxConfirmation
    },
    {
        /* PduId */
        0x1u,
        /* TpPduId */
        0x1u,
        /* CanId */
        (uint32)CAN_TX_ID_RESP_OTA,
        /* ObjectId */
        (uint8)CAN_TX_OBJECT_RESP_OTA,
        /* TxcanIdMode */
        CANIF_TX_STANDARD_FD_CAN,
        /* TxConf */
        &CanTp_TxConfirmation
    },
};

const CanIf_RxChannelType CanIfRxCh[CANIF_RX_CHANNEL_NUM] =
{
    {
        /* PduId */
        0x0u,
        /* TpPduId */
        0x0u,
        /* CanId */
        (uint32)CAN_RX_ID_PHY,
        /* ObjectId */
        (uint8)CAN_RX_OBJECT_PHY,
        /* RxcanIdMode */
        CANIF_RX_STANDARD_FD_CAN,
        /* Mask */
        (uint32)0x1fffffff,
        /* RxInd */
        &CanTp_RxIndication
    },
    {
        /* PduId */
        0x1u,
        /* TpPduId */
        0x1u,
        /* CanId */
        (uint32)CAN_RX_ID_FUNC,
        /* ObjectId */
        (uint8)CAN_RX_OBJECT_FUNC,
        /* RxcanIdMode */
        CANIF_RX_STANDARD_FD_CAN,
        /* Mask */
        (uint32)0x1fffffff,
        /* RxInd */
        &CanTp_RxIndication
    },
	    {
        /* PduId */
        0x2u,
        /* TpPduId */
        0x2u,
        /* CanId */
        (uint32)CAN_RX_ID_PHY_OTA,
        /* ObjectId */
        (uint8)CAN_RX_OBJECT_PHY_OTA,
        /* RxcanIdMode */
        CANIF_RX_STANDARD_FD_CAN,
        /* Mask */
        (uint32)0x1fffffff,
        /* RxInd */
        &CanTp_RxIndication
    },
    {
        /* PduId */
        0x3u,
        /* TpPduId */
        0x3u,
        /* CanId */
        (uint32)CAN_RX_ID_FUNC_OTA,
        /* ObjectId */
        (uint8)CAN_RX_OBJECT_FUNC_OTA,
        /* RxcanIdMode */
        CANIF_RX_STANDARD_FD_CAN,
        /* Mask */
        (uint32)0x1fffffff,
        /* RxInd */
        &CanTp_RxIndication
    },
};

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

