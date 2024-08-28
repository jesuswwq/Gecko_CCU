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
**  FILENAME    : CanNm_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2023/10/10 15:11:46                                         **
**  Author      : wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration data for CanNm                                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm.h"
#include "PduR_Cfg.h"
#include "CanIf_Cfg.h"
#include "ComM_Cfg.h"
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
#define CANNM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanNm_MemMap.h"

static CONST(CanNm_RxPduType, CANNM_CONST) CanNm_RxPduData[CANNM_RX_PDU_NUMBER_MAX] =
{
        {
            0u,           /* RxPduId */
        },
        {
            1u,           /* RxPduId */
        },
        {
            2u,           /* RxPduId */
        },
        {
            3u,           /* RxPduId */
        },
};

static CONST(CanNm_TxPduType, CANNM_CONST)  CanNm_TxPduData[CANNM_TX_PDU_NUMBER_MAX] =
{
        {
            0u,           /* TxConfirmationPduId*/
            CANIF_TXPDU_CanNm_CAN1_CANFD8_TX,      /* CanNmTxPduRef */
            FALSE        /*TxPduIsTriggerTrans*/
        },
        {
            1u,           /* TxConfirmationPduId*/
            CANIF_TXPDU_CanNm_CAN2_CANFD6_TX,      /* CanNmTxPduRef */
            FALSE        /*TxPduIsTriggerTrans*/
        },
        {
            2u,           /* TxConfirmationPduId*/
            CANIF_TXPDU_CanNm_CAN5_CANFD3_TX,      /* CanNmTxPduRef */
            FALSE        /*TxPduIsTriggerTrans*/
        },
        {
            3u,           /* TxConfirmationPduId*/
            CANIF_TXPDU_CanNm_CAN6_CANFD5_TX,      /* CanNmTxPduRef */
            FALSE        /*TxPduIsTriggerTrans*/
        },
};

static CONST(CanNm_UserDataTxPduType, CANNM_CONST) CanNM_UserDataTxPdu[CANNM_USER_DATA_TX_PDU_MAX]=
{
        {
             0u,                 /* CanNmTxUserDataPduId*/
             PDUR_DESTPDU_CanNm_CAN1_CANFD8_user,       /* CanNmTxUserDataPduRef */
        },
        {
             1u,                 /* CanNmTxUserDataPduId*/
             PDUR_DESTPDU_CanNm_CAN2_CANFD6_user,       /* CanNmTxUserDataPduRef */
        },
        {
             2u,                 /* CanNmTxUserDataPduId*/
             PDUR_DESTPDU_CanNm_CAN5_CANFD3_user,       /* CanNmTxUserDataPduRef */
        },
        {
             3u,                 /* CanNmTxUserDataPduId*/
             PDUR_DESTPDU_CanNm_CAN6_CANFD5_user,       /* CanNmTxUserDataPduRef */
        },
};

static CONST(CanNm_ChannelConfigType, CANNM_CONST)
CanNm_ChannelCfgData[CANNM_NUMBER_OF_CHANNEL]=
{
    {
        TRUE,    /* CanNmActiveWakeupBitEnabled */
        20u,        /* CanNmImmediateNmCycleTime */
        5u,        /* CanNmImmediateNmTransmissions */
        0u,        /* CanNmMsgCycleOffset */
        500u,        /* CanNmMsgCycleTime */
        0u,        /* CanNmMsgTimeoutTime */
        33u,        /* CanNmNodeId */
        CANNM_PDU_BYTE_1,    /* CanNmPduCbvPosition */
        CANNM_PDU_BYTE_0,    /* CanNmPduNidPosition */
        1500u,                    /* CanNmRepeatMessageTime */
        FALSE,                /* CanNmRetryFirstMessageRequest */
        FALSE,    /* CanNmStayInPbsEnabled */
        2000u,                    /* CanNmTimeoutTime */
        2000u,                    /* CanNmWaitBusSleepTime */
        Channel_CANFD8,    /* CanNmComMNetworkHandleRef */
        &CanNm_RxPduData[0],    /* CanNmRxPdu */
        1u,              /* RxPduNum */
        &CanNm_TxPduData[0],   /* CanNmTxPdu */
        6u,  /* CanNm_UserDataLen */
        2u,  /* CanNm_UserDataOffsetPos */
        &CanNM_UserDataTxPdu[0],   /* CanNmUserDataTxPdu */
    },
    {
        TRUE,    /* CanNmActiveWakeupBitEnabled */
        20u,        /* CanNmImmediateNmCycleTime */
        5u,        /* CanNmImmediateNmTransmissions */
        0u,        /* CanNmMsgCycleOffset */
        500u,        /* CanNmMsgCycleTime */
        0u,        /* CanNmMsgTimeoutTime */
        1u,        /* CanNmNodeId */
        CANNM_PDU_BYTE_1,    /* CanNmPduCbvPosition */
        CANNM_PDU_BYTE_0,    /* CanNmPduNidPosition */
        1500u,                    /* CanNmRepeatMessageTime */
        FALSE,                /* CanNmRetryFirstMessageRequest */
        FALSE,    /* CanNmStayInPbsEnabled */
        2000u,                    /* CanNmTimeoutTime */
        2000u,                    /* CanNmWaitBusSleepTime */
        Channel_CANFD6,    /* CanNmComMNetworkHandleRef */
        &CanNm_RxPduData[1],    /* CanNmRxPdu */
        1u,              /* RxPduNum */
        &CanNm_TxPduData[1],   /* CanNmTxPdu */
        6u,  /* CanNm_UserDataLen */
        2u,  /* CanNm_UserDataOffsetPos */
        &CanNM_UserDataTxPdu[1],   /* CanNmUserDataTxPdu */
    },
    {
        TRUE,    /* CanNmActiveWakeupBitEnabled */
        20u,        /* CanNmImmediateNmCycleTime */
        5u,        /* CanNmImmediateNmTransmissions */
        0u,        /* CanNmMsgCycleOffset */
        500u,        /* CanNmMsgCycleTime */
        0u,        /* CanNmMsgTimeoutTime */
        49u,        /* CanNmNodeId */
        CANNM_PDU_BYTE_1,    /* CanNmPduCbvPosition */
        CANNM_PDU_BYTE_0,    /* CanNmPduNidPosition */
        1500u,                    /* CanNmRepeatMessageTime */
        FALSE,                /* CanNmRetryFirstMessageRequest */
        FALSE,    /* CanNmStayInPbsEnabled */
        2000u,                    /* CanNmTimeoutTime */
        2000u,                    /* CanNmWaitBusSleepTime */
        Channel_CANFD3,    /* CanNmComMNetworkHandleRef */
        &CanNm_RxPduData[2],    /* CanNmRxPdu */
        1u,              /* RxPduNum */
        &CanNm_TxPduData[2],   /* CanNmTxPdu */
        6u,  /* CanNm_UserDataLen */
        2u,  /* CanNm_UserDataOffsetPos */
        &CanNM_UserDataTxPdu[2],   /* CanNmUserDataTxPdu */
    },
    {
        TRUE,    /* CanNmActiveWakeupBitEnabled */
        20u,        /* CanNmImmediateNmCycleTime */
        5u,        /* CanNmImmediateNmTransmissions */
        0u,        /* CanNmMsgCycleOffset */
        500u,        /* CanNmMsgCycleTime */
        0u,        /* CanNmMsgTimeoutTime */
        17u,        /* CanNmNodeId */
        CANNM_PDU_BYTE_1,    /* CanNmPduCbvPosition */
        CANNM_PDU_BYTE_0,    /* CanNmPduNidPosition */
        1500u,                    /* CanNmRepeatMessageTime */
        FALSE,                /* CanNmRetryFirstMessageRequest */
        FALSE,    /* CanNmStayInPbsEnabled */
        2000u,                    /* CanNmTimeoutTime */
        2000u,                    /* CanNmWaitBusSleepTime */
        Channel_CANFD5,    /* CanNmComMNetworkHandleRef */
        &CanNm_RxPduData[3],    /* CanNmRxPdu */
        1u,              /* RxPduNum */
        &CanNm_TxPduData[3],   /* CanNmTxPdu */
        6u,  /* CanNm_UserDataLen */
        2u,  /* CanNm_UserDataOffsetPos */
        &CanNM_UserDataTxPdu[3],   /* CanNmUserDataTxPdu */
    },

};

CONST(CanNm_ConfigType, CANNM_CONST) CanNm_Config =  /* PRQA S 1531 */ /* MISRA Rule 8.7 */
{
    0x5u,    /* CanNmMainFunctionPeriod */
    CanNm_ChannelCfgData,       /* CanNmChannelConfig */
};
#define CANNM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanNm_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/

