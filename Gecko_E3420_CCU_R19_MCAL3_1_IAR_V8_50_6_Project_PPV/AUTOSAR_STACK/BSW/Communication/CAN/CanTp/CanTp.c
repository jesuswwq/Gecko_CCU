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
**  FILENAME    : CanTp.c                                                    **
**                                                                           **
**  Created on  : 2021/7/30 14:29:43                                         **
**  Author      : tao.yu                                                     **
**  Vendor      :                                                            **
**  DESCRIPTION : Public functions implementation                            **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                     **
**                                                                           **
**************************************************************************** */
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:CanTp<br>
  RuleSorce:puhua-rule.rcf 2.3.1

    \li PRQA S 3432 MISRA Rule 20.7 .<br>
    Reason:Function-like macros are used to allow more efficient code.

    \li PRQA S 1532 MISRA Rule 8.7 .<br>
    Reason:Functions may be used in other projects.
 */

/*=======[I N C L U D E S]====================================================*/
#include "CanTp.h"
#include "CanTp_Internal.h"
#include "CanTp_Cbk.h"

extern boolean Diag_Init2s_Flag;
extern boolean turn_off_flg;
/*=======[V E R S I O N  C H E C K]===========================================*/
/*check version information with CanTp*/
#if (                                                                                                           \
    (CANTP_AR_RELEASE_MAJOR_VERSION != CANTP_CFG_H_AR_MAJOR_VERSION)                                            \
    || (CANTP_AR_RELEASE_MINOR_VERSION != CANTP_CFG_H_AR_MINOR_VERSION)                                         \
    || (CANTP_AR_RELEASE_PATCH_VERSION != CANTP_CFG_H_AR_PATCH_VERSION) || (2u != CANTP_CFG_H_SW_MAJOR_VERSION) \
    || (1u != CANTP_CFG_H_SW_MINOR_VERSION) || (1u != CANTP_CFG_H_SW_PATCH_VERSION))
#error " CanTp cfg file version mismatching with CanTp"
#endif
/*=======[M A C R O S]========================================================*/
/*=======[T Y P E   D E F I N I T I O N S]====================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/
#define CANTP_START_SEC_VAR_POWER_ON_INIT_8
#include "CanTp_MemMap.h"
/*CANTP global variable for module state:CANTP_ON, CANTP_OFF*/
CANTP_LOCAL VAR(CanTp_StateType, CANTP_VAR_POWER_ON_INIT) CanTp_ModuleState = CANTP_OFF;
CANTP_LOCAL VAR(uint8, CANTP_VAR_POWER_ON_INIT) CanTp_RxQueueCurrentIndex = 0u;
#define CANTP_STOP_SEC_VAR_POWER_ON_INIT_8
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED /* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "CanTp_MemMap.h"
/*CANTP cfg ptr*/
P2CONST(CanTp_ConfigType, AUTOMATIC, CANTP_APPL_CONST) CanTp_ConfigPtr = NULL_PTR;
#define CANTP_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED /* PRQA S 0791 */ /* MISRA Rule 5.4 */
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_VAR_NO_INIT_8
#include "CanTp_MemMap.h"
CANTP_LOCAL VAR(uint8, CANTP_VAR_NO_INIT) CanTp_RxQueue[CANTP_CHANNEL_NUMBER];
#define CANTP_STOP_SEC_VAR_NO_INIT_8
#include "CanTp_MemMap.h"
/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[I N T E R N A L   D A T A]==========================================*/

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
/*Initialize the specific channel.*/
static FUNC(void, CANTP_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    CanTp_InitSubChannel(P2VAR(CanTp_ConnectionType, AUTOMATIC, CANTP_VAR_POWER_ON_INIT) SubchannelPtr);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

/*Initialize the Rx specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_InitRxChannel(uint8 ChannelIdx);

/*Initialize the Tx specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_InitTxChannel(uint8 ChannelIdx);

/*Initialize the specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_InitChannel(uint8 ChannelIdx);

/*This function is called by the CanTp_RxIndication after a successful
reception of a RX CAN L-PDU, put the PDU into pool.*/
static FUNC(void, CANTP_CODE)
    CanTp_RxSubDeal(PduIdType CanTpRxPduId, P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr);

/* SF come, just execute one time of PduR_CanTpCopyRxData.*/
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithSF(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 channelIdx);

/* SF come, just execute one time of PduR_CanTpCopyRxData.*/
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithSFToUp(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 channelIdx);

/* FC come, just execute one time of PduR_CanTpCopyRxData.*/
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithFC(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) TxNSduCfgPtr,
    uint8 channelIdx);

/* CF come, just execute one time of PduR_CanTpCopyRxData.*/
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithCF(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 channelIdx);

/* CF come, just execute one time of PduR_CanTpCopyRxData.*/
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithCFToUp(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 channelIdx);

/*FF come, just execute one time of PduR_CanTpCopyRxData.*/
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithFF(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 channelIdx);

/*FF come, just execute one time of PduR_CanTpCopyRxData.*/
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithFFToUp(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 channelIdx);

#if (STD_ON == CANTP_FD)
static FUNC(boolean, CANTP_CODE) CanTp_checkSF(PduLengthType SF_DL, PduLengthType CAN_DL, PduLengthType Offset);
static FUNC(boolean, CANTP_CODE) CanTp_checkLastCF(PduLengthType CF_DL, PduLengthType CAN_DL, PduLengthType Offset);
#endif /* STD_ON == CANTP_FD */

static FUNC(void, CANTP_CODE) CanTp_ReleaseRxChannel(uint8 ChannelIdx);

static FUNC(void, CANTP_CODE) CanTp_ReleaseTxChannel(uint8 ChannelIdx);

/*Start a block by sending FC_CTS if needed.*/
static FUNC(Std_ReturnType, CANTP_CODE)
    CanTp_RxBlockStart(P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr, uint8 ChannelIdx);

/*Handle RX event occurred to the specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_DispatchRxEvent(uint8 ChannelIdx);
/*Handle RX event occurred to the specific channel.*/
static FUNC(void, CANTP_CODE)
    CanTp_DispatchRxEventSubDeal(uint8 ChannelIdx, P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr);

/* Get SDU configuration by N-SDU ID.*/
static FUNC(P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST), CANTP_CODE)
    CanTp_GetRxSduCfgByNSduId(PduIdType CanTpRxSduId, uint8* channelId);

/*Handle TX event occurred to the specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_DispatchTxEvent(uint8 ChannelIdx);

/*handling for SF transmitting.*/
static FUNC(void, CANTP_CODE) CanTp_TxHandleSFStart(uint8 ChannelIdx);

/*Get TX-SDU configuration by TX-NSduId.*/
static FUNC(P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST), CANTP_CODE)
    CanTp_GetTxSduCfgByTxSduId(PduIdType TxSduId, uint8* channelId);

/*Get Tx-SDU configuration by Tx NPDUID.*/
static FUNC(P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST), CANTP_CODE)
    CanTp_GetTxSduCfgByTxNPdu(PduIdType CanTpTxPduId, uint8* channelId);

/* Get Rx-SDU configuration by Tx-FC NPDUID.*/
static FUNC(P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST), CANTP_CODE)
    CanTp_GetRxSduCfgByTxFCNPdu(PduIdType CanTpTxPduId, uint8* channelId);

#if (CANTP_DIAG_GW_RES_ENABLE == STD_ON)
/*Handle the diag gateway timer for specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_HandleGatewayTimers(uint8 ChannelIdx);
#endif /* CANTP_DIAG_GW_RES_ENABLE == STD_ON */

/*Handle the timer for specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_HandleTimers(uint8 ChannelIdx);

/*Handle the tx timer for specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_HandleTxTimers(uint8 ChannelIdx);

#if (CANTP_CHANGE_PARAMETER == STD_ON)
/*check Rx ChangeParameter*/
static FUNC(boolean, CANTP_CODE) CanTP_CheckRxChangeParameter(TPParameterType canTpParam, uint16 value);
#endif /* CANTP_CHANGE_PARAMETER == STD_ON */

/* handling for large SDU transmitting, trying to get TX buffer.*/
static FUNC(void, CANTP_CODE) CanTp_TxHandleLargeStart(uint8 ChannelIdx);

static FUNC(void, CANTP_CODE) CanTp_AddRxQueue(uint8* buffer, uint8 ChannelIdx, uint8* accIndex);
#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CANTPTXCONFIRMATION_CALLBACK_CODE
#include "CanTp_MemMap.h"
static FUNC(void, CANTP_APPL_CODE) CanTp_SFCFTxConfirmationSubDealWith(
    uint8 ChannelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) txNSduCfgPtr);

static FUNC(void, CANTP_APPL_CODE) CanTp_FCTxConfirmationSubDealWith(PduIdType TxPduId);
#define CANTP_STOP_SEC_CANTPTXCONFIRMATION_CALLBACK_CODE
#include "CanTp_MemMap.h"
/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
/*
 * Brief               This function initializes the CanTp module.
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI           COM Manager
 */
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
FUNC(void, CANTP_APPL_CODE)
CanTp_Init(P2CONST(CanTp_ConfigType, AUTOMATIC, CANTP_APPL_CONST) CfgPtr)
{
    uint8 channelIdx;
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
    if (NULL_PTR == CfgPtr)
    {
        /*invalid transmit request information pointer*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_INIT, CANTP_E_PARAM_POINTER);
    }
    else if (CfgPtr->ChannelNum > CANTP_MAX_CHANNEL_NUMBER)
    {
        /*invalid channel number*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_INIT, CANTP_E_INIT_FAILED);
    }
    else
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
    {
        SchM_Enter_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_STATE); /*lock state*/
        /*if the module is working, turn off it, then it can not receive or transmit new N-SDUs*/
        if (CANTP_ON == CanTp_ModuleState)
        {
            CanTp_ModuleState = CANTP_OFF;
        }
        SchM_Exit_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_STATE); /*unlock state*/

        /*Initialize all the channels to stop all the working channels*/
        for (channelIdx = 0; channelIdx < CfgPtr->ChannelNum; channelIdx++)
        {
            CanTp_InitChannel(channelIdx);
        }
        CanTp_ConfigPtr = CfgPtr;
        /*turn the switch of module state on*/
        SchM_Enter_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_STATE); /*lock state*/
        /*CanTp start to work*/
        CanTp_ModuleState = CANTP_ON;
        SchM_Exit_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_STATE); /*unlock state*/
    }
}
#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"

/*
 * Brief               This function to shutdown the CanTp module.
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI           COM Manager
 */
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
FUNC(void, CANTP_APPL_CODE) CanTp_Shutdown(void)
{
    SchM_Enter_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_STATE); /*lock state*/
    /*CanTp stops working*/
    CanTp_ModuleState = CANTP_OFF;
    SchM_Exit_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_STATE); /*unlock state*/
}
#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"

/*
 * Brief               This service is used to request the transfer of segmented data.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CanTpTxSduId ID of the CAN N-SDU to be transmitted.
 *                     CanTpTxInfoPtr indicator of a structure with CAN N-SDU related
 *                                    data:indicator of a CAN N-SDU buffer and the length
 *                                    of this buffer.
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              E_OK:request can be started successfully
 *                     E_NOT_OK:request cannot be started
 * PreCondition        CanTp module initialized
 * CallByAPI           Upper Layer module
 */
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
FUNC(Std_ReturnType, CANTP_APPL_CODE)
CanTp_Transmit(PduIdType TxPduId, P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr)
{
    const CanTp_TxNSduType* TxNSduCfgPtr;
    Std_ReturnType result = E_NOT_OK;
    uint8 channelIdx;
    CanTp_ConnectionType* TxSubchannelPtr;
    const CanTp_ConnectionType* RxchannelPtr;

#if (STD_ON == CANTP_DEV_ERROR_DETECT)
    /*check module state, handle the request only when module started*/
    if (CANTP_ON != CanTp_ModuleState)
    {
        /*CanTp module not started*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_TRANSMIT, CANTP_E_UNINIT);
    }
    else if (NULL_PTR == PduInfoPtr)
    {
        /*invalid transmit request information pointer*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_TRANSMIT, CANTP_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
    {
        /*information pointer OK*/
        TxNSduCfgPtr = CanTp_GetTxSduCfgByTxSduId(TxPduId, &channelIdx);
        if (NULL_PTR != TxNSduCfgPtr)
        {
            /*A configured TX SDU matched. Try to accepted the transmit request*/
            /*check sdu data total length of the transmit request*/
            if (E_NOT_OK == CanTp_CheckTxLengthInAddressMode(TxNSduCfgPtr, PduInfoPtr))
            {
                /*check TxTaType type, invalid*/
                CANTP_DET_REPORTRUNTIMEERROR(CANTP_SERVICEID_TRANSMIT, CANTP_E_INVALID_TATYPE);
            }
            else /*All request parameters are valid*/
            {
                /*check if the channel is free*/
                TxSubchannelPtr = CanTp_GetTxSubChannel(channelIdx);
                RxchannelPtr = CanTp_GetRxChannel(channelIdx);
                SchM_Enter_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
#if (CANTP_DIAG_GW_RES_ENABLE == STD_ON)
                CanTp_TxConnectionType* TxchannelPtr = CanTp_GetTxChannel(channelIdx);
                TxchannelPtr->NeedRes.Started =
                    (TxchannelPtr->NeedRes.Started == TRUE) ? FALSE : TxchannelPtr->NeedRes.Started;
#endif /* CANTP_DIAG_GW_RES_ENABLE == STD_ON */
                if ((CanTp_ConfigPtr->CanTpChannel[channelIdx].ChannelMode == CANTP_MODE_HALF_DUPLEX)
                    && ((RxchannelPtr->RootState != CANTP_IDLE) && (RxchannelPtr->RootState != CANTP_OCCUPIED)))
                {
                    /*half duplex, if Rx is in processing,
                    the same channel can not transmit data at the same time*/
                }
                else if (CANTP_IDLE == TxSubchannelPtr->RootState)
                {
                    /*channel is free, and no event happened to it*/
                    TxSubchannelPtr->NSduId = TxNSduCfgPtr->TxNSduId;
                    TxSubchannelPtr->SduDataRemaining = PduInfoPtr->SduLength;
                    TxSubchannelPtr->SduDataTotalCount = PduInfoPtr->SduLength;
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
                    CanTp_SaveTxMetaDataInfo(channelIdx, TxNSduCfgPtr, PduInfoPtr);
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
                    /*set channel as sender to avoid unexpected PDU reception,here can not make sure
                     * of SF*/
                    CanTp_TxHandleTransmitReq(channelIdx, TxNSduCfgPtr);
                    /*start CS timer*/
                    if (TxNSduCfgPtr->Ncs != NULL_PTR)
                    {
                        TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_NC;
                        TxSubchannelPtr->ChannelTimer.RemainTime = *(TxNSduCfgPtr->Ncs);
                        CanTp_ResetTime(&(TxSubchannelPtr->ChannelTimer.StartTime));
                    }
                    else
                    {
                        TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_TIMER_NONE;
                    }
                    result = E_OK;
                }
                else
                {
                    /*idle*/
                }
                SchM_Exit_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
            }
        } /*END OF if (NULL_PTR != txNSduCfgPtr)*/
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
        else
        {
            /*No configured TX SDU matched with this TxSduId*/
            CANTP_DET_REPORTERROR(CANTP_SERVICEID_TRANSMIT, CANTP_E_INVALID_TX_ID);
        }
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
    }  /* END OF if (CANTP_ON == CanTp_RuntimeControl.ModuleState)*/
    return result;
}
#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"

#if (CANTP_TC == STD_ON)
/*
 * Brief               This service is used to cancel the transfer of pending
 *                     CAN N-SDUs. The connection is identified by CanTpTxPduId.
 * ServiceId           0x08
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CanTpTxSduId ID of the CAN N-SDU to be canceled.
 *                     CanTpCancelReason The reason for cancelation.
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              E_OK:Cancelation request is accepted
 *                     E_NOT_OK:Cancelation request is rejected.
 * PreCondition        CanTp module initialized
 * CallByAPI           Upper Layer module
 */
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
FUNC(Std_ReturnType, CANTP_APPL_CODE) CanTp_CancelTransmit(PduIdType TxPduId)
{

    const CanTp_TxNSduType* txNSduCfgPtr;
    Std_ReturnType result = E_NOT_OK;
    uint8 channelIdx;
    CanTp_ConnectionType* TxSubchannelPtr;

#if (STD_ON == CANTP_DEV_ERROR_DETECT)
    /*check module state, handle the request only when module started*/
    if (CANTP_ON != CanTp_ModuleState)
    {
        /*CanTp module not started*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_CANCELTRANSMITREQUEST, CANTP_E_UNINIT);
    }
    else
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
    {
        /*Get configuration of the specified TX-NSDU*/
        txNSduCfgPtr = CanTp_GetTxSduCfgByTxSduId(TxPduId, &channelIdx);
        if (NULL_PTR == txNSduCfgPtr)
        {
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
            /*Invalid TxNSduId, no configuration matched*/
            CANTP_DET_REPORTERROR(CANTP_SERVICEID_CANCELTRANSMITREQUEST, CANTP_E_PARAM_ID);
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
        }
        else if (CANTP_TC_MASK == (txNSduCfgPtr->CanTpPduFlag & CANTP_TC_MASK))
        {
            TxSubchannelPtr = CanTp_GetTxSubChannel(channelIdx);
            if ((CANTP_LARGE_TRANSMITTING != TxSubchannelPtr->RootState)
                && (CANTP_SF_TRANSIMITTING != TxSubchannelPtr->RootState))
            {
                CANTP_DET_REPORTRUNTIMEERROR(CANTP_SERVICEID_CANCELTRANSMITREQUEST, CANTP_E_OPER_NOT_SUPPORTED);
            }
            else
            {
                /*A matched configuration matched*/ /*lock channel*/
                if (TxSubchannelPtr->NSduId == TxPduId)
                {
                    /* change tx RootState to idle , avoid release call the txconfiramation with
                     * E_NOT_OK*/
                    TxSubchannelPtr->RootState = CANTP_IDLE;
                    /*turn off the sub-state to reject the following events for this channel
                     * transmitting*/
                    CanTp_ReleaseTxChannel(channelIdx);
                    PduR_CanTpTxConfirmation(txNSduCfgPtr->TxIPduId, E_NOT_OK);
                    result = E_OK;
                }
            }
        }
        else
        {
            /*idle*/
        }
    }
    return result;
}
#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"

/*
 * Brief               This service is used to cancel the reception of an ongoing N-SDU.
 * ServiceId           0x09
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      This parameter contains the unique CanTp module identifier
 *                     of the N-SDU to be cancelled for transmission.
 *                     Range: 0..(maximum number of L-PDU IDs received ) - 1
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              E_OK:Cancelation request is accepted
 *                     E_NOT_OK:Cancelation request is rejected.
 * PreCondition        CanTp module initialized
 * CallByAPI           Upper Layer module
 */
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
FUNC(Std_ReturnType, CANTP_APPL_CODE) CanTp_CancelReceive(PduIdType RxPduId)
{

    const CanTp_RxNSduType* rxNSduCfgPtr;
    Std_ReturnType result = E_NOT_OK;
    uint8 channelIdx;
    const CanTp_ConnectionType* RxchannelPtr;

#if (STD_ON == CANTP_DEV_ERROR_DETECT)
    /*check module state, handle the request only when module started*/
    if (CANTP_ON != CanTp_ModuleState)
    {
        /*CanTp module not started*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_CANCELRECEIVEREQUEST, CANTP_E_UNINIT);
    }
    else
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
    {
        /*Get configuration of the specified TX-NSDU*/
        rxNSduCfgPtr = CanTp_GetRxSduCfgByNSduId(RxPduId, &channelIdx);
        if (NULL_PTR == rxNSduCfgPtr)
        {
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
            /*Invalid RxNSduId, no configuration matched*/
            CANTP_DET_REPORTERROR(CANTP_SERVICEID_CANCELRECEIVEREQUEST, CANTP_E_PARAM_ID);
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
        }
        else
        {
            /*A matched configuration matched*/
            RxchannelPtr = CanTp_GetRxChannel(channelIdx);
            if (CANTP_LARGE_RECEIVING == RxchannelPtr->RootState)
            {
                /*last Consecutive Frame can not cancel*/
                if ((RxchannelPtr->NSduId == RxPduId) && (RxchannelPtr->SduDataRemaining > 0u))
                {
                    /*Release the resource related with the channel and Notify the upper*/
                    CanTp_ReleaseRxChannel(channelIdx);
                    PduR_CanTpRxIndication(rxNSduCfgPtr->RxIPduId, E_NOT_OK);
                    result = E_OK;
                }
            }
            else
            {
                CANTP_DET_REPORTRUNTIMEERROR(CANTP_SERVICEID_CANCELRECEIVEREQUEST, CANTP_E_OPER_NOT_SUPPORTED);
            }
        }
    }
    return result;
}
#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"
#endif /* CANTP_TC == STD_ON */

#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"

#if (CANTP_CHANGE_PARAMETER == STD_ON)
/*
 * Brief               Request to change a specific transport protocol parameter (e.g. block size).
 * ServiceId           0x4b
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      id:Identification of the PDU which the parameter change shall affect.
 *                     parameter:ID of the parameter that shall be changed.
 *                     value: The new value of the parameter.
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              E_OK:The parameter was changed successfully.
 *                     E_NOT_OK:The parameter change was rejected.
 * PreCondition        CanTp module initialized
 * CallByAPI           Upper Layer module
 */
FUNC(Std_ReturnType, CANTP_APPL_CODE)
CanTp_ChangeParameter(PduIdType id, TPParameterType parameter, uint16 value)
{
    Std_ReturnType result = E_NOT_OK;
    const CanTp_RxNSduType* rxNSduCfgPtr;
    uint8 channelIdx;

#if (STD_ON == CANTP_DEV_ERROR_DETECT)
    /*check module state, handle only when module started*/
    if (CANTP_ON != CanTp_ModuleState)
    {
        /*CanTp module not started*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_CHANGEPARAMETER, CANTP_E_UNINIT);
    }
    else
    {
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
        rxNSduCfgPtr = CanTp_GetRxSduCfgByNSduId(id, &channelIdx);
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
        if ((FALSE == CanTP_CheckRxChangeParameter(parameter, value)) || (NULL_PTR == rxNSduCfgPtr))
        {
            CANTP_DET_REPORTERROR(CANTP_SERVICEID_CHANGEPARAMETER, CANTP_E_PARAM_ID);
        }
        else /*All request parameters are valid*/
#endif       /* STD_ON == CANTP_DEV_ERROR_DETECT */
        {
            CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(channelIdx);
            if (RxchannelPtr->RootState != CANTP_LARGE_RECEIVING)
            {
                if (TP_BS == parameter)
                {
                    RxchannelPtr->ChangedBs = (uint8)value;
                    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
                    CANTP_SETFLAG(RxchannelPtr->EventFlags, CANTP_EVENT_RXBSCHANGED);
                    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
                    result = E_OK;
                }
                else if (TP_STMIN == parameter)
                {
                    RxchannelPtr->ChangedSTmin = (uint8)value;
                    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
                    CANTP_SETFLAG(RxchannelPtr->EventFlags, CANTP_EVENT_RXSTMINCHANGED);
                    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
                    result = E_OK;
                }
                else
                {
                    /*idle*/
                }
            }
        }
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
    }
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
    return result;
}
#endif /* CANTP_CHANGE_PARAMETER == STD_ON */

#if (CANTP_READ_PARAMETER == STD_ON)
/*
 * Brief               This service is used to read the current value of
                       reception parameters BS and STmin for a specified N-SDU.
 * ServiceId           0x0b
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      id:Identification of the PDU which the parameter change shall affect.
 *                     parameter:ID of the parameter that shall be changed.
 * Param-Name[out]     value:Pointer where the parameter value will be provided.
 * Param-Name[in/out]  N/A
 * Return              E_OK:request is accepted
 *                     E_NOT_OK:request is not accepted.
 * PreCondition        CanTp module initialized
 * CallByAPI           Upper Layer module
 */
FUNC(Std_ReturnType, CANTP_APPL_CODE)
CanTp_ReadParameter(PduIdType id, TPParameterType parameter, uint16* value)
{

    Std_ReturnType result = E_NOT_OK;
    const CanTp_RxNSduType* rxNSduCfgPtr;
    uint8 channelIdx;

#if (STD_ON == CANTP_DEV_ERROR_DETECT)
    /*check module state, handle only when module started*/
    if (CANTP_ON != CanTp_ModuleState)
    {
        /*CanTp module not started*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_READPARAMETER, CANTP_E_UNINIT);
    }
    else
    {
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
        rxNSduCfgPtr = CanTp_GetRxSduCfgByNSduId(id, &channelIdx);
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
        if (((parameter != TP_STMIN) && (parameter != TP_BS)) || (NULL_PTR == rxNSduCfgPtr))
        {
            CANTP_DET_REPORTERROR(CANTP_SERVICEID_READPARAMETER, CANTP_E_PARAM_ID);
        }
        else if (NULL_PTR == value)
        {
            CANTP_DET_REPORTERROR(CANTP_SERVICEID_READPARAMETER, CANTP_E_PARAM_POINTER);
        }
        else /*All request parameters are valid*/
#endif       /* STD_ON == CANTP_DEV_ERROR_DETECT */
        {
            const CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(channelIdx);
            if (TP_BS == parameter)
            {
                /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
                *value = CANTP_FLAGISSET(RxchannelPtr->EventFlags, CANTP_EVENT_RXSTMINCHANGED)
                             ? (uint16)RxchannelPtr->ChangedBs
                             : (uint16)RxchannelPtr->CurrentBs;
                /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
                result = E_OK;
            }
            else
#if (STD_OFF == CANTP_DEV_ERROR_DETECT)
                if (TP_STMIN == parameter) /* TP_STMIN == parameter */
#endif                                     /* STD_OFF == CANTP_DEV_ERROR_DETECT */
            {
                /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
                if (CANTP_FLAGISSET(RxchannelPtr->EventFlags, CANTP_EVENT_RXSTMINCHANGED))
                /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
                {
                    /*STmin have been changed*/
                    *value = (uint16)RxchannelPtr->ChangedSTmin;
                }
                else
                {
                    *value = (rxNSduCfgPtr->STmin != NULL_PTR) ? (*(rxNSduCfgPtr->STmin)) : 0u;
                }
                result = E_OK;
            }
#if (STD_OFF == CANTP_DEV_ERROR_DETECT)
            else
            {
                /*idle*/
            }
#endif /* STD_OFF == CANTP_DEV_ERROR_DETECT */
        }
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
    }
#endif /* STD_OFF == CANTP_DEV_ERROR_DETECT */
    return result;
}
#endif /* CANTP_READ_PARAMETER == STD_ON */

#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"
/*
 * Brief               The main function for scheduling the CANTP.
 * ServiceId           0x06
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        CanTp module initialized
 * CallByAPI           SchM
 */
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
FUNC(void, CANTP_APPL_CODE) CanTp_MainFunction(void)
{
    uint8 tempQueue[CANTP_CHANNEL_NUMBER];
    uint8 tempQueueSize = 0u;
    uint8 tempQueueIndex;
    uint8 channelIdx;
    uint8 index;
    /*check module state, handle only when module started*/
    if (CANTP_ON == CanTp_ModuleState)
    {
        SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
        for (index = 0; index < CanTp_RxQueueCurrentIndex; index++)
        {
            tempQueue[index] = CanTp_RxQueue[index];
            tempQueueSize++;
        }
        tempQueueIndex = tempQueueSize;
        CanTp_RxQueueCurrentIndex = 0u;
        SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
        for (channelIdx = 0; channelIdx < CanTp_ConfigPtr->ChannelNum; channelIdx++)
        {
            CanTp_AddRxQueue(tempQueue, channelIdx, &tempQueueIndex);
        }
        for (channelIdx = 0; channelIdx < CanTp_ConfigPtr->ChannelNum; channelIdx++)
        {
            SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
            /*handle channel timers*/
            CanTp_HandleTimers(tempQueue[channelIdx]);

#if (CANTP_DIAG_GW_RES_ENABLE == STD_ON)
            /*handle channel diag gateway timers*/
            CanTp_HandleGatewayTimers(tempQueue[channelIdx]);
#endif /* CANTP_DIAG_GW_RES_ENABLE == STD_ON */

            /*handle receive events*/
            CanTp_DispatchRxEvent(tempQueue[channelIdx]);

            /*handle transmit events*/
            CanTp_DispatchTxEvent(tempQueue[channelIdx]);
            SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
        }
    }
}
#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"

#if (CANTP_VERSION_INFO_API == STD_ON)
/*
 * Brief               This function return the version information of the CANTP module.
 * ServiceId           0x07
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     versioninfo indicator as to where to store the
 * version information of this module.
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
FUNC(void, CANTP_APPL_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
CanTp_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, CANTP_APPL_DATA) versioninfo)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
    if (NULL_PTR == versioninfo)
    {
        /*report development error*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_GETVERSIONINFO, CANTP_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
    {
        /*NULL_PTR != versioninfo*/
        versioninfo->moduleID = CANTP_MODULE_ID;
        versioninfo->sw_major_version = CANTP_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = CANTP_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = CANTP_SW_PATCH_VERSION;
        versioninfo->vendorID = CANTP_VENDOR_ID;
    }
}
#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"
#endif /* CANTP_VERSION_INFO_API == STD_ON */

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
#define CANTP_START_SEC_CANTPRXINDICATION_CALLBACK_CODE
#include "CanTp_MemMap.h"
FUNC(void, CANTP_APPL_CODE)
CanTp_RxIndication(PduIdType RxPduId, P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr)
{
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
    /*check module state, handle the reception indication only when module started*/
    if (CANTP_ON != CanTp_ModuleState)
    {
        /*CanTp module not started*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_RXINDICATION, CANTP_E_UNINIT);
    }
    else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        /*INVALID pointer parameter*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_RXINDICATION, CANTP_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
    {

        if((turn_off_flg == FALSE) && (Diag_Init2s_Flag == TRUE))
        {
            CanTp_RxSubDeal(RxPduId, PduInfoPtr);
        }
        /*fill the received NPDU into channel*/
        else
        {
            
        }


        
    }
}
#define CANTP_STOP_SEC_CANTPRXINDICATION_CALLBACK_CODE
#include "CanTp_MemMap.h"

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
uint16 CantpTxCounter = 0;
#define CANTP_START_SEC_CANTPTXCONFIRMATION_CALLBACK_CODE
#include "CanTp_MemMap.h"
FUNC(void, CANTP_APPL_CODE) CanTp_TxConfirmation(PduIdType TxPduId)
{
    const CanTp_TxNSduType* txNSduCfgPtr;
    uint8 ChannelIdx;
    CanTp_ConnectionType* TxSubchannelPtr;

#if (STD_ON == CANTP_DEV_ERROR_DETECT)
    /*check module state, handle the reception indication only when module started*/
    if (CANTP_ON != CanTp_ModuleState)
    {
        /*CanTp module not started*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_TXCONFIRMATION, CANTP_E_UNINIT);
    }
    else
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
    {
        /*first check if it is a transmitted data NPDU*/
        txNSduCfgPtr = CanTp_GetTxSduCfgByTxNPdu(TxPduId, &ChannelIdx);
        TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);
        if (NULL_PTR != txNSduCfgPtr)
        {
            /*A transmitted data PDU confirmed, Store the confirmation event only when the
            channel related with this TX SDU is transmitting this SDU and
            it is waiting for the confirmation*/
            if (((CANTP_TX_SF_V4SF_CFM == TxSubchannelPtr->Substate)
                 || (CANTP_TX_LARGE_V4DATA_CFM == TxSubchannelPtr->Substate))
                && (txNSduCfgPtr->TxNSduId == TxSubchannelPtr->NSduId))
            {
                CanTp_SFCFTxConfirmationSubDealWith(ChannelIdx, txNSduCfgPtr);
                CantpTxCounter++;
            }
            else
            {
                /*then check if it is a transmitted FC NPDU*/
                CanTp_FCTxConfirmationSubDealWith(TxPduId);
            }
        } /*END OF handling data frame confirmation*/
        else
        {
            CanTp_FCTxConfirmationSubDealWith(TxPduId);
        }
    }
}
#define CANTP_STOP_SEC_CANTPTXCONFIRMATION_CALLBACK_CODE
#include "CanTp_MemMap.h"

/*=============Module Internal Function Implementation====================*/
/*All transmitted CAN frames belonging to the CAN Transport Layer will be confirmed by this
 * function.*/
#define CANTP_START_SEC_CANTPTXCONFIRMATION_CALLBACK_CODE
#include "CanTp_MemMap.h"
static FUNC(void, CANTP_APPL_CODE) CanTp_SFCFTxConfirmationSubDealWith(
    uint8 ChannelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) txNSduCfgPtr)
{

    CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);
    /*A data frame transmit confirmed*/
    if (CANTP_TX_SF_V4SF_CFM == TxSubchannelPtr->Substate)
    {
        /* change tx RootState to idle , avoid release call the txconfiramation with E_NOT_OK*/
        TxSubchannelPtr->RootState = CANTP_IDLE;
        /*Confirmation for SF data transmit. The end of the SF transmitting, Release the channel
         * resource*/
        CanTp_ReleaseTxChannel(ChannelIdx);
        /*Notify the upper*/
        PduR_CanTpTxConfirmation(txNSduCfgPtr->TxIPduId, E_OK);
    }
    else /*Confirmation for large SDU data transmit*/
    {
        /*update next SN number*/
        TxSubchannelPtr->CurrentCfSn = (uint8)(TxSubchannelPtr->CurrentCfSn + 1u) & CANTP_CF_SN_MASK;
        if (CANTP_FTYPE_FF == TxSubchannelPtr->HandleType)
        {
            /*confirmation for FF, transit to state V4FC and start BS timer*/
            TxSubchannelPtr->Substate = CANTP_TX_LARGE_V4FC;
            if (txNSduCfgPtr->Nbs != NULL_PTR)
            {
                TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_NB;
                TxSubchannelPtr->ChannelTimer.RemainTime = *(txNSduCfgPtr->Nbs);
                CanTp_ResetTime(&(TxSubchannelPtr->ChannelTimer.StartTime));
            }
            else
            {
                TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_TIMER_NONE;
            }
        }
        else /*confirmation for CF*/
        {
            if (0u == TxSubchannelPtr->SduDataRemaining)
            {
                /* change tx RootState to idle , avoid release call the txconfiramation with
                 * E_NOT_OK*/
                TxSubchannelPtr->RootState = CANTP_IDLE;
                /*SDU transmitting finished, release resource of channel and notify the upper*/
                CanTp_ReleaseTxChannel(ChannelIdx);
                PduR_CanTpTxConfirmation(txNSduCfgPtr->TxIPduId, E_OK);
            }
            else /*whole SDU transmitting not finished*/
            {
                /*update handled CF count*/
                if (0xFFu > TxSubchannelPtr->HandledCfCount)
                {
                    TxSubchannelPtr->HandledCfCount++;
                }
                if (TxSubchannelPtr->HandledCfCount == TxSubchannelPtr->CurrentBs)
                {
                    /*current block finished, wait another FC*/
                    TxSubchannelPtr->Substate = CANTP_TX_LARGE_V4FC;
                    if (txNSduCfgPtr->Nbs != NULL_PTR)
                    {
                        TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_NB;
                        TxSubchannelPtr->ChannelTimer.RemainTime = *(txNSduCfgPtr->Nbs);
                        CanTp_ResetTime(&(TxSubchannelPtr->ChannelTimer.StartTime));
                    }
                    else
                    {
                        TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_TIMER_NONE;
                    }
                }
                else /*current block not finished yet*/
                {
                    /*construct the next CF PCI, and transit to SENDCF, start STmin and CS*/
                    TxSubchannelPtr->Substate = CANTP_TX_LARGE_START;
                    if (txNSduCfgPtr->Ncs != NULL_PTR)
                    {
                        TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_NC;
                        TxSubchannelPtr->ChannelTimer.RemainTime = *(txNSduCfgPtr->Ncs);
                        CanTp_ResetTime(&(TxSubchannelPtr->ChannelTimer.StartTime));
                    }
                    else
                    {
                        TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_TIMER_NONE;
                    }
                    TxSubchannelPtr->STminTimer.Started = TRUE;
                    TxSubchannelPtr->STminTimer.RemainTime = TxSubchannelPtr->STminTimer.FcSTMin;
                    CanTp_ResetTime(&(TxSubchannelPtr->STminTimer.StartTime));
                }
            } /*ENDOF whole SDU transmitting not finished*/
        }     /*END OF confirmation for CF*/
    }         /*END OF Confirmation for large SDU data transmit*/
}

static FUNC(void, CANTP_APPL_CODE) CanTp_FCTxConfirmationSubDealWith(PduIdType TxPduId)
{
    const CanTp_RxNSduType* rxNSduCfgPtr;
    CanTp_ConnectionType* RxchannelPtr;
    uint8 ChannelIdx;

    rxNSduCfgPtr = CanTp_GetRxSduCfgByTxFCNPdu(TxPduId, &ChannelIdx);
    RxchannelPtr = CanTp_GetRxChannel(ChannelIdx);
    if (NULL_PTR != rxNSduCfgPtr)
    {
        /*A transmitted FC PDU confirmed,Store the confirmation event only when the channel related
        with this RX SDU is receiving this SDU and it is waiting for the FC confirmation*/
        if (((CANTP_RX_LARGE_V4FCCTS_CFM == RxchannelPtr->Substate)
             || (CANTP_RX_LARGE_V4FCWT_CFM == RxchannelPtr->Substate))
            && (rxNSduCfgPtr->RxNSduId == RxchannelPtr->NSduId))
        {
            /*A data frame transmit confirmed*/
            if (CANTP_RX_LARGE_V4FCWT_CFM == RxchannelPtr->Substate)
            {
                /*transit to RX_LARGE_START, which will try to get buffer again*/
                RxchannelPtr->Substate = CANTP_RX_LARGE_START;
                CanTp_AddRxQueue(CanTp_RxQueue, ChannelIdx, &CanTp_RxQueueCurrentIndex);
                RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_NB;
                RxchannelPtr->ChannelTimer.RemainTime = rxNSduCfgPtr->Nbr;
                CanTp_ResetTime(&(RxchannelPtr->ChannelTimer.StartTime));
            }
            else if (CANTP_RX_LARGE_V4FCCTS_CFM == RxchannelPtr->Substate)
            {
                /*FC_CTS sent, start to waiting for CFs*/
                RxchannelPtr->Substate = CANTP_RX_LARGE_V4CF;
                if (rxNSduCfgPtr->Ncr != NULL_PTR)
                {
                    RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_NC;
                    RxchannelPtr->ChannelTimer.RemainTime = *(rxNSduCfgPtr->Ncr);
                    CanTp_ResetTime(&(RxchannelPtr->ChannelTimer.StartTime));
                }
                else
                {
                    RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_TIMER_NONE;
                }
            }
            else
            {
                /*will not happen with handling of filtering when indicated by CanIf*/
            }
        }
    }
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
    else
    {
        /*invalid confirmation*/
        CANTP_DET_REPORTERROR(CANTP_SERVICEID_TXCONFIRMATION, CANTP_E_INVALID_TX_ID);
    }
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
}
#define CANTP_STOP_SEC_CANTPTXCONFIRMATION_CALLBACK_CODE
#include "CanTp_MemMap.h"

#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
/*Initialize the specific channel.*/
static FUNC(void, CANTP_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    CanTp_InitSubChannel(P2VAR(CanTp_ConnectionType, AUTOMATIC, CANTP_VAR_POWER_ON_INIT) SubchannelPtr)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
    /*initialize channel state information of RxConnection*/
    SubchannelPtr->RootState = CANTP_IDLE;
    SubchannelPtr->Substate = CANTP_SUBSTATE_NONE;
    SubchannelPtr->HandleType = CANTP_FTYPE_RESEVED;
    /*initialize channel ABC timer*/
    SubchannelPtr->ChannelTimer.EnabledTimer = CANTP_TIMER_NONE;
    SubchannelPtr->ChannelTimer.RemainTime = 0;
    SubchannelPtr->ChannelTimer.StartTime = 0;
    /*initialize channel flow control parameter*/
    SubchannelPtr->CurrentBs = 0;
#if (STD_ON == CANTP_FD)
    SubchannelPtr->FDDlc = 0;
#endif /* STD_ON == CANTP_FD */
    SubchannelPtr->ChangedBs = 0;
    SubchannelPtr->ChangedSTmin = 0;
    SubchannelPtr->CurrentCfSn = 0;
    SubchannelPtr->HandledCfCount = 0;
    SubchannelPtr->SentWftCount = 0;
    SubchannelPtr->STminTimer.Started = FALSE;
    SubchannelPtr->STminTimer.RemainTime = 0;
    SubchannelPtr->STminTimer.StartTime = 0;
    SubchannelPtr->STminTimer.FcSTMin = 0;
    /*initialize SDU information*/
    SubchannelPtr->NSduId = 0;
    SubchannelPtr->SduDataRemaining = 0;
    SubchannelPtr->SduDataTotalCount = 0;
    /*initialize event flags*/
    SubchannelPtr->EventFlags = 0;
#if ((CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON) || (CANTP_DYN_ID_SUPPORT == STD_ON))
    /*initialize address information of SDU with MetaData*/
    SubchannelPtr->MetaDataN_TA = 0;
    SubchannelPtr->MetaDataN_SA = 0;
    SubchannelPtr->MetaDataN_AE = 0;
    SubchannelPtr->MetaDataLength = 0;
#endif /* (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON) || (CANTP_DYN_ID_SUPPORT == STD_ON) */
    SchM_Exit_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
}

/*Initialize the Rx specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_InitRxChannel(uint8 ChannelIdx)
{
    CanTp_ConnectionType* RxchannelPtr;

    RxchannelPtr = CanTp_GetRxChannel(ChannelIdx);
    CanTp_InitSubChannel(RxchannelPtr);
}

/*Initialize the Tx specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_InitTxChannel(uint8 ChannelIdx)
{
    CanTp_ConnectionType* TxSubchannelPtr;
    CanTp_TxConnectionType* TxchannelPtr;
    uint8 unusedchannelId;
    const CanTp_TxNSduType* txSduCfgPtr;

    TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);
    if (TxSubchannelPtr->RootState != CANTP_IDLE)
    {
        txSduCfgPtr = CanTp_GetTxSduCfgByTxSduId(TxSubchannelPtr->NSduId, &unusedchannelId);
        if (txSduCfgPtr != NULL_PTR)
        {
            PduR_CanTpTxConfirmation(txSduCfgPtr->TxIPduId, E_NOT_OK);
        }
    }
    CanTp_InitSubChannel(TxSubchannelPtr);
    TxchannelPtr = CanTp_GetTxChannel(ChannelIdx);
    for (uint8 iloop = 0; iloop <
#if (STD_ON == CANTP_FD)
                          CANTP_CANFD_FRAME_LEN_MAX
#else  /* STD_ON == CANTP_FD */
                          CANTP_CAN20_FRAME_LEN_MAX
#endif /* STD_ON == CANTP_FD */
         ;
         iloop++)
    {
        TxchannelPtr->LocalBuf[iloop] = 0;
    }
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
    for (uint8 iloop = 0; iloop < 5u; iloop++)
    {
        TxchannelPtr->Metadata[iloop] = 0;
    }
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
#if (CANTP_DIAG_GW_RES_ENABLE == STD_ON)
    /*initialize channel diag gateway timer*/
    SubchannelPtr->NeedRes.Started = FALSE;
    SubchannelPtr->NeedRes.StartTime = 0;
    SubchannelPtr->NeedRes.RemainTime = 0;
    SubchannelPtr->NeedRes.ResponseTimer = 0;
    SubchannelPtr->NeedRes.Sid = 0;
    SubchannelPtr->NeedRes.PendingSid = 0;
#endif /* CANTP_DIAG_GW_RES_ENABLE == STD_ON */
}

/*Initialize the specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_InitChannel(uint8 ChannelIdx)
{
    CanTp_InitRxChannel(ChannelIdx);
    CanTp_InitTxChannel(ChannelIdx);
}

static FUNC(void, CANTP_CODE) CanTp_ReleaseRxChannel(uint8 ChannelIdx)
{
    if (CanTp_ConfigPtr->CanTpChannel[ChannelIdx].ChannelMode != CANTP_MODE_FULL_DUPLEX)
    {
        CanTp_InitChannel(ChannelIdx);
    }
    else
    {
        CanTp_InitRxChannel(ChannelIdx);
    }
}

static FUNC(void, CANTP_CODE) CanTp_ReleaseTxChannel(uint8 ChannelIdx)
{
    if (CanTp_ConfigPtr->CanTpChannel[ChannelIdx].ChannelMode != CANTP_MODE_FULL_DUPLEX)
    {
        CanTp_InitChannel(ChannelIdx);
    }
    else
    {
        CanTp_InitTxChannel(ChannelIdx);
    }
}

#if (STD_ON == CANTP_FD)
/*
 * Brief               match CanFd Data length.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
FUNC(PduLengthType, CANTP_CODE) CanTp_MatchDLC(PduLengthType frameDL)
{
    uint8 i;
    PduLengthType len = frameDL;

    /*ISO 11898-1:2014 define the DLC table*/
    const uint8 canDL[8] = {8, 12, 16, 20, 24, 32, 48, 64};
    if (frameDL > CANTP_CAN20_FRAME_LEN_MAX)
    {
        for (i = 0; i < 8u; i++)
        {
            if (frameDL <= canDL[i])
            {
                len = canDL[i];
                break;
            }
        }
    }
    return len;
}
#endif /* STD_ON == CANTP_FD */

/*This function is called by the CanTp_RxIndication after a successful
reception of a RX CAN L-PDU, put the PDU into pool.*/
static FUNC(void, CANTP_CODE)
    CanTp_RxSubDeal(PduIdType CanTpRxPduId, P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr)
{

    const CanTp_RxNSduType* rxNSduCfgPtr;
    const CanTp_TxNSduType* txNSduCfgPtr;
    CanTp_FramePCIType FrameType = CANTP_FTYPE_RESEVED;
    uint8 chnIdx;

    /*first try to check if the received NPDU whether is CF SF or FF*/
    rxNSduCfgPtr = CanTp_GetRxSduCfgByNpdu(CanTpRxPduId, PduInfoPtr, &FrameType, &chnIdx);
    if (NULL_PTR != rxNSduCfgPtr)
    {
        SchM_Enter_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
        switch (FrameType)
        {
        case CANTP_FTYPE_CF:
            CanTp_RxSubDealWithCF(PduInfoPtr, rxNSduCfgPtr, chnIdx);
            break;
        case CANTP_FTYPE_FF:
            CanTp_RxSubDealWithFF(PduInfoPtr, rxNSduCfgPtr, chnIdx);
            break;
        case CANTP_FTYPE_SF:
            CanTp_RxSubDealWithSF(PduInfoPtr, rxNSduCfgPtr, chnIdx);
            break;
        default:
            /*this will never happen*/
            break;
        }
        SchM_Exit_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
    }

    if (CANTP_FTYPE_RESEVED == FrameType)
    {
        /*then check whether it is FC, if FC received that means this is sender*/
        txNSduCfgPtr = CanTp_GetTxSduCfgByFCNpdu(CanTpRxPduId, PduInfoPtr, &chnIdx);
        if (NULL_PTR != txNSduCfgPtr)
        {
            /*A FC received*/
            CanTp_RxSubDealWithFC(PduInfoPtr, txNSduCfgPtr, chnIdx);
        }
    }
}

/*
 * Brief               FC come, just execute one time of PduR_CanTpCopyRxData.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithFC(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) TxNSduCfgPtr,
    uint8 channelIdx)
{
    CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(channelIdx);
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
    Std_ReturnType result;
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
    CanTp_FCInfoType fcInfo;
#if (STD_ON == CANTP_FD)
    PduLengthType MatchDLC = CanTp_MatchDLC(PduInfoPtr->SduLength);
#endif /* STD_ON == CANTP_FD */
    /*min-length check*/
    if ((PduInfoPtr->SduLength < 3u)
#if (STD_ON == CANTP_FD)
        || (((MatchDLC != PduInfoPtr->SduLength) && (PduInfoPtr->SduLength >= 8u)))
        || (PduInfoPtr->SduLength > TxNSduCfgPtr->TxNPduDLC)
#endif /* STD_ON == CANTP_FD */
    )
    {
        /*idle*/
    }
    else
    {
        /*only accepted the received FC when the channel is transmitting a large SDU related with
        the FC NPDU, and it is waiting for a FC. Otherwise ignore the frame*/
        if ((TxNSduCfgPtr->TxNSduId == TxSubchannelPtr->NSduId) && (CANTP_TX_LARGE_V4FC == TxSubchannelPtr->Substate)
            && (CANTP_LARGE_TRANSMITTING == TxSubchannelPtr->RootState))
        {
            if ((8u > PduInfoPtr->SduLength) && (TxNSduCfgPtr->TxPaddingActivation == CANTP_PADDING_ON))
            {
                CANTP_DET_REPORTRUNTIMEERROR(CANTP_SERVICEID_RXINDICATION, CANTP_E_PADDING);
                CanTp_ReleaseTxChannel(channelIdx);
                /*notify upper with E_NOT_OK*/
                PduR_CanTpTxConfirmation(TxNSduCfgPtr->TxIPduId, E_NOT_OK);
            }
            else
            {
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
                /*SWS_CanTp_00336,the CanTp module shall check the addressing information contained
                  in the MetaData (at the end of the data referenced by PduInfoPtr) against the stored values.*/
                result = CanTp_CheckRxFCMetaData(channelIdx, TxNSduCfgPtr, PduInfoPtr);
                if (result == E_OK)
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
                {
                    CanTp_GetChannelFCInfo(TxNSduCfgPtr, PduInfoPtr, &fcInfo);
                    SchM_Enter_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
                    switch (fcInfo.FcFs)
                    {
                    case CANTP_FC_FS_CTS:
                        /*Clear to send. Get the channel ready to send CF, and make STmin timer timeout*/
                        TxSubchannelPtr->CurrentBs = fcInfo.FcBS;
                        TxSubchannelPtr->HandledCfCount = 0;
                        TxSubchannelPtr->STminTimer.Started = TRUE;
                        TxSubchannelPtr->STminTimer.RemainTime = fcInfo.FcSTMin;
                        CanTp_ResetTime(&(TxSubchannelPtr->STminTimer.StartTime));
                        TxSubchannelPtr->STminTimer.FcSTMin = fcInfo.FcSTMin;
                        /*transit to state SENDCF*/
                        if (TxNSduCfgPtr->Ncs != NULL_PTR)
                        {
                            TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_NC;
                            TxSubchannelPtr->ChannelTimer.RemainTime = *(TxNSduCfgPtr->Ncs);
                            CanTp_ResetTime(&(TxSubchannelPtr->ChannelTimer.StartTime));
                        }
                        else
                        {
                            TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_TIMER_NONE;
                        }
                        TxSubchannelPtr->HandleType = CANTP_FTYPE_CF;
                        TxSubchannelPtr->Substate = CANTP_TX_LARGE_START;
                        break;
                    case CANTP_FC_FS_WT:
                        /*reset the BS timer*/
                        if (TxNSduCfgPtr->Nbs != NULL_PTR)
                        {
                            TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_NB;
                            TxSubchannelPtr->ChannelTimer.RemainTime = *(TxNSduCfgPtr->Nbs);
                            CanTp_ResetTime(&(TxSubchannelPtr->ChannelTimer.StartTime));
                        }
                        else
                        {
                            TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_TIMER_NONE;
                        }
                        break;
                    case CANTP_FC_FS_OVFLW:
                    default:
                        /* change tx RootState to idle ,
                        avoid release call the txconfiramation with E_NOT_OK*/
                        TxSubchannelPtr->RootState = CANTP_IDLE;
                        /*release resource of channel*/
                        CanTp_ReleaseTxChannel(channelIdx);
                        /*notify upper with NO_BUFFER*/
                        PduR_CanTpTxConfirmation(TxNSduCfgPtr->TxIPduId, E_NOT_OK);
                        break;
                    }                                                                 /*ENDOF switch (fcInfo.FcFs)*/
                    SchM_Exit_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
                }
            }
        }
    }
}
/*
 * Brief               CF come, just execute one time of PduR_CanTpCopyRxData.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithCF(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 channelIdx)
{
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
    Std_ReturnType result;
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
#if (STD_ON == CANTP_FD)
    PduLengthType MatchDLC = CanTp_MatchDLC(PduInfoPtr->SduLength);
#endif /* STD_ON == CANTP_FD */
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(channelIdx);
    uint8 cfSN;
    uint8 pcioffset;
    uint8 dataoffset;

    /*min-length check*/
    if ((PduInfoPtr->SduLength < 1u)
#if (STD_ON == CANTP_FD)
        || (((PduInfoPtr->SduLength != MatchDLC) && (PduInfoPtr->SduLength >= 8u)))
        || (PduInfoPtr->SduLength > RxNSduCfgPtr->RxNPduDLC)
#endif /* STD_ON == CANTP_FD */
    )
    {
        /*idle*/
    }
    else
    {
        /*only accept it when the channel is receiving a large
        SDU related with this CF, and it is waiting a CF.*/
        if ((CANTP_FUNCTIONAL_RX == RxNSduCfgPtr->RxTaType)
#if (STD_ON == CANTP_FD)
            || (CANTP_CANFD_FUNCTIONAL == RxNSduCfgPtr->RxTaType)
#endif /* STD_ON == CANTP_FD */
        )
        {
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
            /*invalid TAType with CF frame, wrong configuration*/
            CANTP_DET_REPORTRUNTIMEERROR(CANTP_SERVICEID_RXINDICATION, CANTP_E_INVALID_TATYPE);
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
        }
        else if (
            (RxNSduCfgPtr->RxNSduId == RxchannelPtr->NSduId) && (CANTP_LARGE_RECEIVING == RxchannelPtr->RootState)
            && (CANTP_RX_LARGE_V4CF == RxchannelPtr->Substate))
        {
            if ((8u > PduInfoPtr->SduLength) && (RxNSduCfgPtr->RxPaddingActivation == CANTP_PADDING_ON))
            {
                CANTP_DET_REPORTRUNTIMEERROR(CANTP_SERVICEID_RXINDICATION, CANTP_E_PADDING);
                CanTp_ReleaseRxChannel(channelIdx);
                PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
            }
            else
            {
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
                /*SWS_CanTp_00333,check the addressing information contained in the MetaData of the
                N-PDU (at the end of the data referenced by PduInfoPtr) against the stored values from the FF.*/
                result = CanTp_CheckRxCFMetaData(channelIdx, RxNSduCfgPtr, PduInfoPtr);
                if (E_OK == result)
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
                {
                    CanTp_RxGetCFOffset(RxNSduCfgPtr, &dataoffset, &pcioffset);
                    cfSN = PduInfoPtr->SduDataPtr[pcioffset] & CANTP_CF_SN_MASK;
                    if (cfSN != RxchannelPtr->CurrentCfSn)
                    {
                        /*check SN value*/ /*wrong SN*/ /*release resource of channel*/
                        CanTp_ReleaseRxChannel(channelIdx);
                        PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
                    }
                    else
                    {
                        CanTp_RxSubDealWithCFToUp(PduInfoPtr, RxNSduCfgPtr, channelIdx);
                    } /*END OF handling expected CF*/
                }
            }
        }
        else
        {
            /*CF not expected*/
        }
    }
}

/*
 * Brief               CF come, just execute one time of PduR_CanTpCopyRxData.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithCFToUp(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 channelIdx)
{
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(channelIdx);
    uint32 N_Cr;
    PduInfoType upperpduInfo;
    const PduInfoType* upperpduInfoPtr = &upperpduInfo;
    PduLengthType bufferSize;
    Std_ReturnType result;
    BufReq_ReturnType bufRslt;
    PduLengthType DataLength;
    uint8 pcioffset;
    uint8 dataoffset;

    /*It is the expected CF*/
    CanTp_RxGetCFOffset(RxNSduCfgPtr, &dataoffset, &pcioffset);
    DataLength = PduInfoPtr->SduLength - dataoffset;
    SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
    RxchannelPtr->HandleType = CANTP_FTYPE_CF;
    RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_TIMER_NONE;
    if (0xFFu > RxchannelPtr->HandledCfCount)
    {
        RxchannelPtr->HandledCfCount++;
    }
    /*consider rx padding*/
    if (DataLength > RxchannelPtr->SduDataRemaining)
    {
        DataLength = RxchannelPtr->SduDataRemaining;
    }
    SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/

    upperpduInfo.SduDataPtr = &(PduInfoPtr->SduDataPtr[dataoffset]);
    upperpduInfo.SduLength = DataLength;
    bufRslt = PduR_CanTpCopyRxData(RxNSduCfgPtr->RxIPduId, upperpduInfoPtr, &bufferSize);
    if (BUFREQ_E_NOT_OK == bufRslt)
    {
        /*release resource of channel*/
        CanTp_ReleaseRxChannel(channelIdx);
        PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
    }
    else
    {
        SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
        RxchannelPtr->SduDataRemaining -= DataLength;
        SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
        if (((DataLength < (PduLengthType)((PduLengthType)8u - (PduLengthType)dataoffset))
#if (STD_ON == CANTP_FD)
             || (PduInfoPtr->SduLength != RxchannelPtr->FDDlc)
#endif /* STD_ON == CANTP_FD */
                 )
            && (0u != RxchannelPtr->SduDataRemaining))
        {
            /*this CF is not the last and length is not match ,release resource of channel*/
            CanTp_ReleaseRxChannel(channelIdx);
            PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
        }
        else
        {
            if (0u == RxchannelPtr->SduDataRemaining)
            {
                /*the whole SDU reception finished*/
#if (STD_ON == CANTP_FD)
                if (FALSE == CanTp_checkLastCF(DataLength, PduInfoPtr->SduLength, pcioffset))
                {
                    /*release resource of channel*/
                    CanTp_ReleaseRxChannel(channelIdx);
                    PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
                }
                else
#endif /* STD_ON == CANTP_FD */
                {
                    SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
#if (STD_ON == CANTP_SYNCHRONOUS_RXINDICATION)
                    RxchannelPtr->RootState = CANTP_OCCUPIED;
                    PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_OK);
                    RxchannelPtr->RootState = CANTP_IDLE;
                    CanTp_ReleaseRxChannel(channelIdx);
#else  /* STD_ON == CANTP_SYNCHRONOUS_RXINDICATION */
                    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
                    CANTP_SETFLAG(RxchannelPtr->EventFlags, CANTP_EVENT_RXNOTIFIUPPER);
                    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
                    CanTp_AddRxQueue(CanTp_RxQueue, channelIdx, &CanTp_RxQueueCurrentIndex);
#endif /* STD_ON == CANTP_SYNCHRONOUS_RXINDICATION */
                    SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
                }
            }
            else
            {
                /*SDU whole reception not finished*/
                if (RxchannelPtr->CurrentBs == RxchannelPtr->HandledCfCount)
                {
                    /*current block finished, check upper buffer is enough or not*/
                    result = CanTp_CompareBufferWithBs(RxNSduCfgPtr, channelIdx, bufferSize);
                    if (E_NOT_OK == result)
                    {
                        /*the upper buffer is not enough to store the next block,so need to get more buffer*/
                        SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
                        RxchannelPtr->Substate = CANTP_RX_LARGE_START;
                        CanTp_AddRxQueue(CanTp_RxQueue, channelIdx, &CanTp_RxQueueCurrentIndex);
                        RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_NB;
                        RxchannelPtr->ChannelTimer.RemainTime = RxNSduCfgPtr->Nbr;
                        CanTp_ResetTime(&(RxchannelPtr->ChannelTimer.StartTime));
                        SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
                    }
                    else
                    {
                        /*buffer enough, start a new block*/ /*calculate block size*/
                        CanTp_CalcBS(RxNSduCfgPtr, channelIdx);
                        result = CanTp_RxBlockStart(RxNSduCfgPtr, channelIdx);
                        if (E_NOT_OK == result)
                        {
                            CanTp_ReleaseRxChannel(channelIdx);
                            PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
                        }
                    }
                }
                else
                {
                    /*continue to wait another CF*/
                    SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
                    RxchannelPtr->Substate = CANTP_RX_LARGE_V4CF;
                    if (RxNSduCfgPtr->Ncr != NULL_PTR)
                    {
                        N_Cr = *(RxNSduCfgPtr->Ncr);
                        RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_NC;
                        RxchannelPtr->ChannelTimer.RemainTime = N_Cr;
                        CanTp_ResetTime(&(RxchannelPtr->ChannelTimer.StartTime));
                    }
                    else
                    {
                        RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_TIMER_NONE;
                    }
                    SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
                }
                /*update SN,expect next CF*/
                SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
                RxchannelPtr->CurrentCfSn = (RxchannelPtr->CurrentCfSn + 1u) & CANTP_CF_SN_MASK;
                SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
            } /*END OF SDU whole reception not finished*/
        }
    } /*END OF if (BUFREQ_E_NOT_OK == bufRslt)*/
}

/*
 * Brief               FF come, just execute one time of PduR_CanTpStartOfReception.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithFF(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 channelIdx)
{
    uint8 Offset = 0;
    PduLengthType frameDl;
    const CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(channelIdx);
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(channelIdx);
#if (STD_ON == CANTP_FD)
    PduLengthType MatchDLC = CanTp_MatchDLC(PduInfoPtr->SduLength);
#endif /* STD_ON == CANTP_FD */
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
    Std_ReturnType result;
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */

    /*min-length check*/
    /*half duplex, if Tx is in processing, the same channel can not receiving data at the same time*/
    /*Only accept FF when the channel is IDLE or it is handling SDU receiving*/
    /*Function addressing mode not support multiple frames*/
    if ((PduInfoPtr->SduLength < 8u)
        || ((CanTp_ConfigPtr->CanTpChannel[channelIdx].ChannelMode == CANTP_MODE_HALF_DUPLEX)
            && (TxSubchannelPtr->RootState != CANTP_IDLE))
#if (STD_ON == CANTP_FD)
        || (((PduInfoPtr->SduLength != MatchDLC) && (PduInfoPtr->SduLength > 8u)))
        || (PduInfoPtr->SduLength > RxNSduCfgPtr->RxNPduDLC)
#endif /* STD_ON == CANTP_FD */
    )
    {
        /*idle*/
    }
    else
    {
        if ((CANTP_FUNCTIONAL_RX == RxNSduCfgPtr->RxTaType)
#if (STD_ON == CANTP_FD)
            || (CANTP_CANFD_FUNCTIONAL == RxNSduCfgPtr->RxTaType)
#endif /* STD_ON == CANTP_FD */
        )
        {
#if (STD_ON == CANTP_DEV_ERROR_DETECT)
            /*invalid TAType with FF frame, wrong configuration*/
            CANTP_DET_REPORTRUNTIMEERROR(CANTP_SERVICEID_RXINDICATION, CANTP_E_INVALID_TATYPE);
#endif /* STD_ON == CANTP_DEV_ERROR_DETECT */
        }
        else if ((CANTP_IDLE == RxchannelPtr->RootState) || (CANTP_LARGE_RECEIVING == RxchannelPtr->RootState))
        {
            /*check data length of the FF, ignore the frame if invalid length*/
            frameDl = CanTp_RxGetFFDl((const uint8*)PduInfoPtr->SduDataPtr, &Offset, RxNSduCfgPtr);

#if (STD_ON == CANTP_FD)
            /* If CAN_DL > 8, SF needs one extra offset as the escape sequence */
            if (PduInfoPtr->SduLength > 8u)
            {
                Offset++;
            }
#endif /* STD_ON == CANTP_FD */
            /*+ 1u means this FF can be send by SF*/
            if (frameDl > (PduInfoPtr->SduLength - (PduLengthType)Offset + 1u))
            {
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
                result = CanTp_SaveRxMetaDataInfo(channelIdx, RxNSduCfgPtr, PduInfoPtr);
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
                if ((CANTP_LARGE_RECEIVING == RxchannelPtr->RootState) && (RxchannelPtr->MetaDataLength >= 4u)
                    && (CANTP_CAN_ID_32_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_CAN_ID_32_MASK)))
                {
                    /*When an SF or FF N-PDU with MetaData (indicating
                     a generic connection) is received,
                     * and the corresponding connection channel is
                      currently receiving, the SF or FF shall be ignored.*/
                }
                else
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
                    if (E_OK == result)
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
                    {
                        if ((CANTP_SF_RECEIVING == RxchannelPtr->RootState)
                            || (CANTP_LARGE_RECEIVING == RxchannelPtr->RootState))
                        {
                            /*Another SF or large received when the channel is receiving a SDU*/
                            /*Notify error for old SDU reception*/
                            PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
                        }
                        /*update channel runtime information*/
                        SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
                        RxchannelPtr->RootState = CANTP_LARGE_RECEIVING;
                        RxchannelPtr->Substate = CANTP_RX_FF_START;
                        RxchannelPtr->NSduId = RxNSduCfgPtr->RxNSduId;
                        /*SWS_CanTp_00166,the CanTp module shall start a
                        time-out N_Br before calling PduR_CanTpStartOfReception*/
                        RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_NB;
                        RxchannelPtr->ChannelTimer.RemainTime = RxNSduCfgPtr->Nbr;
                        CanTp_ResetTime(&(RxchannelPtr->ChannelTimer.StartTime));
                        RxchannelPtr->HandleType = CANTP_FTYPE_FF;
                        RxchannelPtr->SduDataRemaining = frameDl;
                        RxchannelPtr->SduDataTotalCount = frameDl;
                        /*initialize Flow control information*/
                        RxchannelPtr->CurrentBs = 0;
#if (STD_ON == CANTP_FD)
                        RxchannelPtr->FDDlc = MatchDLC;
#endif /* STD_ON == CANTP_FD */
                        RxchannelPtr->CurrentCfSn = 0;
                        RxchannelPtr->HandledCfCount = 0;
                        RxchannelPtr->SentWftCount = 0;
                        SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
                        CanTp_RxSubDealWithFFToUp(PduInfoPtr, RxNSduCfgPtr, channelIdx);
                    }
#if ((CANTP_DYN_ID_SUPPORT == STD_ON) && (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON))
                    else
                    {
                        /*idle*/
                    }
#endif /* (CANTP_DYN_ID_SUPPORT == STD_ON) && (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON) */
            }
        }
        else
        {
            /*idle*/
        }
    }
}

/*
 * Brief               FF come, just execute one time of PduR_CanTpStartOfReception.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithFFToUp(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 channelIdx)
{
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(channelIdx);
    CanTp_FCInfoType CanTp_FC;
    uint8 Offset = 0;
    PduLengthType frameDl;
    PduLengthType bufferSize;
    BufReq_ReturnType bufRslt;
    PduInfoType upperpduInfo;
    Std_ReturnType result;
    const PduInfoType* upperpduInfoPtr = &upperpduInfo;
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
    uint8 data[5];

    upperpduInfo.MetaDataPtr = data;
    if (((RxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK) > 0u)
        && ((CANTP_ADDRESS_EXTENSION_8_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_ADDRESS_EXTENSION_8_MASK))
            || (CANTP_SA16_AND_TA16_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_SA16_AND_TA16_MASK))))
    {
        CanTp_ConstructForwardRxMetaData(channelIdx, RxNSduCfgPtr, upperpduInfoPtr);
    }
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
    upperpduInfo.SduLength = 0;
    frameDl = CanTp_RxGetFFDl((const uint8*)PduInfoPtr->SduDataPtr, &Offset, RxNSduCfgPtr);
    bufRslt = PduR_CanTpStartOfReception(RxNSduCfgPtr->RxIPduId, upperpduInfoPtr, frameDl, &bufferSize);
    switch (bufRslt)
    {
    case BUFREQ_OK:
        upperpduInfo.SduDataPtr = &PduInfoPtr->SduDataPtr[Offset];
        upperpduInfo.SduLength = PduInfoPtr->SduLength - (PduLengthType)Offset;
        bufRslt = PduR_CanTpCopyRxData(RxNSduCfgPtr->RxIPduId, upperpduInfoPtr, &bufferSize);
        if (BUFREQ_E_NOT_OK == bufRslt)
        {
            CanTp_ReleaseRxChannel(channelIdx);
            PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
        }
        else
        {
#if (CANTP_DIAG_GW_RES_ENABLE == STD_ON)
            CanTp_TxConnectionType* TxchannelPtr = CanTp_GetTxChannel(channelIdx);
            SchM_Enter_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
            TxchannelPtr->NeedRes.Sid = upperpduInfo.SduDataPtr[0];
            SchM_Exit_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
#endif                                                                        /* CANTP_DIAG_GW_RES_ENABLE == STD_ON */
            SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL);  /*lock channel*/
            RxchannelPtr->SduDataRemaining -= (PduInfoPtr->SduLength - (PduLengthType)Offset);
            /*calculate block size*/
            CanTp_CalcBS(RxNSduCfgPtr, channelIdx);
            /*SWS_CanTp_00082,check upper layer buffer is enough or not for next block*/
            result = CanTp_CompareBufferWithBs(RxNSduCfgPtr, channelIdx, bufferSize);
            if (E_NOT_OK == result)
            {
                /*the upper buffer is not enough to store the next block, so need to get more buffer*/
                RxchannelPtr->Substate = CANTP_RX_LARGE_START;
                CanTp_AddRxQueue(CanTp_RxQueue, channelIdx, &CanTp_RxQueueCurrentIndex);
                RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_NB;
                RxchannelPtr->ChannelTimer.RemainTime = RxNSduCfgPtr->Nbr;
                CanTp_ResetTime(&(RxchannelPtr->ChannelTimer.StartTime));
            }
            else
            {
                /*buffer enough, start a new block*/
                result = CanTp_RxBlockStart(RxNSduCfgPtr, channelIdx);
                if (E_NOT_OK == result)
                {
                    CanTp_ReleaseRxChannel(channelIdx);
                    PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
                }
            }
            SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
        }
        /*update expected next SN*/
        SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
        RxchannelPtr->CurrentCfSn = (uint8)(RxchannelPtr->CurrentCfSn + 1u) & CANTP_CF_SN_MASK;
        SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
        break;
    case BUFREQ_E_NOT_OK:
        CanTp_InitRxChannel(channelIdx);
        break;
    case BUFREQ_E_OVFL:
        /*the CanTp module shall send a Flow Control N-PDU with overflow
         status (FC(OVFLW)) and abort the N-SDU reception*/
        /*when handling FF, send FC_OVFL*/
        CanTp_FC.FcFs = CANTP_FC_FS_OVFLW;
        CanTp_FC.FcBS = 0;
        CanTp_FC.FcSTMin = 0;
        SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
        (void)CanTp_SendFC(RxNSduCfgPtr, channelIdx, CanTp_FC);
        SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
        /*release resource of the channel*/
        CanTp_ReleaseRxChannel(channelIdx);
        break;
    default:
        /*idle*/
        break;
    }
}

/*
 * Brief               SF come, just execute one time of PduR_CanTpStartOfReception.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithSF(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 channelIdx)
{
    uint8 totaloffset = 0;
    PduLengthType frameDl;
    const CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(channelIdx);
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(channelIdx);
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
#if (STD_ON == CANTP_FD)
    uint8 DataOffset = 0;
    PduLengthType MatchDLC = CanTp_MatchDLC(PduInfoPtr->SduLength);
#endif /* STD_ON == CANTP_FD */
    /*min-length check*/
    if (PduInfoPtr->SduLength >= 1u)
    {
        /*Handle FF and SF with the same strategy*/
        /*Only accept SF when the channel is IDLE or it is handling SDU receiving*/
        if ((CanTp_ConfigPtr->CanTpChannel[channelIdx].ChannelMode == CANTP_MODE_HALF_DUPLEX)
            && (TxSubchannelPtr->RootState != CANTP_IDLE))
        {
            /*half duplex, if Tx is in processing, the same channel can not receiving data at the same time*/
        }
        else if ((CANTP_IDLE == RxchannelPtr->RootState) || (CANTP_LARGE_RECEIVING == RxchannelPtr->RootState))
        {
            /*check data length of the SF, ignore the frame if invalid length*/
            frameDl = CanTp_RxGetSFDl(
                PduInfoPtr,
                RxNSduCfgPtr,
#if (STD_ON == CANTP_FD)
                &DataOffset,
#endif /* STD_ON == CANTP_FD */
                &totaloffset);
#if (STD_ON == CANTP_FD)
            if (((PduInfoPtr->SduLength != MatchDLC) && (PduInfoPtr->SduLength >= 8u))
                || (PduInfoPtr->SduLength > RxNSduCfgPtr->RxNPduDLC))
            {
                /*No further deal*/
            }
            else
#endif /* STD_ON == CANTP_FD */
            {
                if ((8u > PduInfoPtr->SduLength) && (RxNSduCfgPtr->RxPaddingActivation == CANTP_PADDING_ON))
                {
                    CANTP_DET_REPORTRUNTIMEERROR(CANTP_SERVICEID_RXINDICATION, CANTP_E_PADDING);
                }
                else
                {
                    /*frameDl valid*/
                    if (frameDl != 0x0u)
                    {
#if (STD_ON == CANTP_FD)
                        if (FALSE == CanTp_checkSF(frameDl, MatchDLC, DataOffset))
                        {
                            /*No further deal*/
                        }
                        else
#endif /* STD_ON == CANTP_FD */
                            if (frameDl <= (PduInfoPtr->SduLength - totaloffset))
                            {
                                CanTp_RxSubDealWithSFToUp(PduInfoPtr, RxNSduCfgPtr, channelIdx);
                            }
                            else
                            {
                                /*No further deal*/
                            }
                    }
                }
            }
        }
        else
        {
            /*idle*/
        }
    }
}

/*
 * Brief               SF come, just execute one time of PduR_CanTpStartOfReception.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
static FUNC(void, CANTP_CODE) CanTp_RxSubDealWithSFToUp(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 channelIdx)
{
    PduLengthType bufferSize;
    BufReq_ReturnType bufRslt;
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(channelIdx);
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    PduInfoType upperpduInfo;
    uint8 totaloffset = 0;
    PduLengthType frameDl;
    const PduInfoType* upperpduInfoPtr = &upperpduInfo;
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
    Std_ReturnType result;
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
#if (STD_ON == CANTP_FD)
    uint8 DataOffset = 0;
#endif /* STD_ON == CANTP_FD */
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
    uint8 data[5];

    upperpduInfo.MetaDataPtr = data;
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */

    upperpduInfo.SduLength = 0;
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
    result = CanTp_SaveRxMetaDataInfo(channelIdx, RxNSduCfgPtr, PduInfoPtr);
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
    if ((CANTP_LARGE_RECEIVING == RxchannelPtr->RootState) && (RxchannelPtr->MetaDataLength >= 4u)
        && (CANTP_CAN_ID_32_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_CAN_ID_32_MASK)))
    {
        /*When an SF or FF N-PDU with MetaData (indicating a generic connection) is received,
         * and the corresponding connection channel is currently receiving, the SF or FF shall be ignored.*/
    }
    else
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
        if (E_OK == result)
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
        {
            frameDl = CanTp_RxGetSFDl(
                PduInfoPtr,
                RxNSduCfgPtr,
#if (STD_ON == CANTP_FD)
                &DataOffset,
#endif /* STD_ON == CANTP_FD */
                &totaloffset);

            if (((CANTP_SF_RECEIVING == RxchannelPtr->RootState) || (CANTP_LARGE_RECEIVING == RxchannelPtr->RootState))
                && (!(
                    (PduInfoPtr->SduDataPtr[totaloffset] == 0x3Eu)
                    && (PduInfoPtr->SduDataPtr[totaloffset + 1u] == 0x80u)
                    && ((RxNSduCfgPtr->RxTaType == CANTP_FUNCTIONAL_RX)
                        || (RxNSduCfgPtr->RxTaType == CANTP_CANFD_FUNCTIONAL))
                    && (frameDl == 2u))))
            {
                /*Another SF or large received when the channel is receiving a SDU*/
                /*Notify error for old SDU reception*/
                PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
            }
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
            if (((RxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK) > 0u)
                && ((CANTP_ADDRESS_EXTENSION_8_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_ADDRESS_EXTENSION_8_MASK))
                    || (CANTP_SA16_AND_TA16_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_SA16_AND_TA16_MASK))))
            {
                CanTp_ConstructForwardRxMetaData(channelIdx, RxNSduCfgPtr, upperpduInfoPtr);
            }
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
            bufRslt = PduR_CanTpStartOfReception(RxNSduCfgPtr->RxIPduId, upperpduInfoPtr, frameDl, &bufferSize);
            /*handle according the result of request RX buffer*/
            switch (bufRslt)
            {
            case BUFREQ_OK:
                upperpduInfo.SduDataPtr = &PduInfoPtr->SduDataPtr[totaloffset];
                upperpduInfo.SduLength = frameDl;
                bufRslt = PduR_CanTpCopyRxData(RxNSduCfgPtr->RxIPduId, upperpduInfoPtr, &bufferSize);
                if (bufRslt == BUFREQ_OK)
                {
                    if ((PduInfoPtr->SduDataPtr[totaloffset] == 0x3Eu)
                        && (PduInfoPtr->SduDataPtr[totaloffset + 1u] == 0x80u)
                        && ((RxNSduCfgPtr->RxTaType == CANTP_FUNCTIONAL_RX)
                            || (RxNSduCfgPtr->RxTaType == CANTP_CANFD_FUNCTIONAL))
                        && (frameDl == 2u))
                    {
                        PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_OK);
                    }
                    else
                    {
#if (CANTP_DIAG_GW_RES_ENABLE == STD_ON)
                        CanTp_TxConnectionType* TxchannelPtr = CanTp_GetTxChannel(channelIdx);
                        SchM_Enter_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
                        TxchannelPtr->NeedRes.Sid = upperpduInfo.SduDataPtr[0];
                        SchM_Exit_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
#endif /* CANTP_DIAG_GW_RES_ENABLE == STD_ON */
                        SchM_Enter_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
                        /*update channel runtime information*/
                        RxchannelPtr->RootState = CANTP_SF_RECEIVING;
                        RxchannelPtr->Substate = CANTP_RX_SF_START;
                        RxchannelPtr->NSduId = RxNSduCfgPtr->RxNSduId;
                        RxchannelPtr->HandleType = CANTP_FTYPE_SF;
#if (STD_ON == CANTP_SYNCHRONOUS_RXINDICATION)
                        RxchannelPtr->RootState = CANTP_OCCUPIED;
                        PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_OK);
                        RxchannelPtr->RootState = CANTP_IDLE;
                        CanTp_ReleaseRxChannel(channelIdx);
#else  /* STD_ON == CANTP_SYNCHRONOUS_RXINDICATION */
                    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
                    CANTP_SETFLAG(RxchannelPtr->EventFlags, CANTP_EVENT_RXNOTIFIUPPER);
                    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
                    CanTp_AddRxQueue(CanTp_RxQueue, channelIdx, &CanTp_RxQueueCurrentIndex);
#endif /* STD_ON == CANTP_SYNCHRONOUS_RXINDICATION */
                        SchM_Exit_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
                    }
                }
                else
                {
                    CanTp_ReleaseRxChannel(channelIdx);
                    PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
                }
                break;
            case BUFREQ_E_NOT_OK:
                /*Release the resource of the channel*/
                CanTp_InitRxChannel(channelIdx);
                break;
            case BUFREQ_E_OVFL:
            default:
                /*Release the resource of the channel*/
                CanTp_ReleaseRxChannel(channelIdx);
                /*Notify the upper for error*/
                PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
                break;
            } /*END OF switch (bufRslt)*/
        }
#if ((CANTP_DYN_ID_SUPPORT == STD_ON) && (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON))
        else
        {
            /*idle*/
        }
#endif /* (CANTP_DYN_ID_SUPPORT == STD_ON) && (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON) */
}

#if (STD_ON == CANTP_FD)
static FUNC(boolean, CANTP_CODE) CanTp_checkSF(PduLengthType SF_DL, PduLengthType CAN_DL, PduLengthType Offset)
{
    boolean ret = FALSE;
    switch (CAN_DL)
    {
    case 12u:
        if ((SF_DL >= (8u - Offset)) && (SF_DL <= (10u - Offset)))
        {
            ret = TRUE;
        }
        break;
    case 16u:
    case 20u:
    case 24u:
        if ((SF_DL >= ((CAN_DL - 5u) - Offset)) && (SF_DL <= ((CAN_DL - 2u) - Offset)))
        {
            ret = TRUE;
        }
        break;
    case 32u:
        if ((SF_DL >= (23u - Offset)) && (SF_DL <= (30u - Offset)))
        {
            ret = TRUE;
        }
        break;
    case 48u:
        if ((SF_DL >= (31u - Offset)) && (SF_DL <= (46u - Offset)))
        {
            ret = TRUE;
        }
        break;
    case 64u:
        if ((SF_DL >= (47u - Offset)) && (SF_DL <= (62u - Offset)))
        {
            ret = TRUE;
        }
        break;
    default:
        if (CAN_DL <= 8u)
        {
            ret = TRUE;
        }
        break;
    }
    return ret;
}

static FUNC(boolean, CANTP_CODE) CanTp_checkLastCF(PduLengthType CF_DL, PduLengthType CAN_DL, PduLengthType Offset)
{
    boolean ret = FALSE;
    switch (CAN_DL)
    {
    case 12u:
        if ((CF_DL >= (8u - Offset)) && (CF_DL <= (11u - Offset)))
        {
            ret = TRUE;
        }
        break;
    case 16u:
    case 20u:
    case 24u:
        if ((CF_DL >= ((CAN_DL - 4u) - Offset)) && (CF_DL <= ((CAN_DL - 1u) - Offset)))
        {
            ret = TRUE;
        }
        break;
    case 32u:
        if ((CF_DL >= (24u - Offset)) && (CF_DL <= (31u - Offset)))
        {
            ret = TRUE;
        }
        break;
    case 48u:
        if ((CF_DL >= (32u - Offset)) && (CF_DL <= (47u - Offset)))
        {
            ret = TRUE;
        }
        break;
    case 64u:
        if ((CF_DL >= (48u - Offset)) && (CF_DL <= (63u - Offset)))
        {
            ret = TRUE;
        }
        break;
    default:
        if (CAN_DL <= 8u)
        {
            ret = TRUE;
        }
        break;
    }
    return ret;
}
#endif /* STD_ON == CANTP_FD */

/*Start a block by sending FC_CTS if needed.*/
static FUNC(Std_ReturnType, CANTP_CODE)
    CanTp_RxBlockStart(P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr, uint8 ChannelIdx)
{
    Std_ReturnType ret;
    uint8 stMin;
    uint32 N_Ar;
    CanTp_FCInfoType CanTp_FC;
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(ChannelIdx);

    /*check changParameter of STmin is done or not*/
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    if (CANTP_FLAGISSET(RxchannelPtr->EventFlags, CANTP_EVENT_RXSTMINCHANGED))
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    {
        stMin = RxchannelPtr->ChangedSTmin;
    }
    else
    {
        /*stmin is not changed by api*/
        stMin = (RxNSduCfgPtr->STmin != NULL_PTR) ? (*(RxNSduCfgPtr->STmin)) : 0u;
    }
    /*send FC_CTS*/
    CanTp_FC.FcFs = CANTP_FC_FS_CTS;
    CanTp_FC.FcBS = RxchannelPtr->CurrentBs;
    CanTp_FC.FcSTMin = stMin;
    SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
    /*transit to waiting for confirmation of FC_CTS*/
    RxchannelPtr->Substate = CANTP_RX_LARGE_V4FCCTS_CFM;
    if (RxNSduCfgPtr->Nar != NULL_PTR)
    {
        N_Ar = *(RxNSduCfgPtr->Nar);
        RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_NA;
        RxchannelPtr->ChannelTimer.RemainTime = N_Ar;
        CanTp_ResetTime(&(RxchannelPtr->ChannelTimer.StartTime));
    }
    else
    {
        RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_TIMER_NONE;
    }
    RxchannelPtr->SentWftCount = 0;
    RxchannelPtr->HandledCfCount = 0;
    ret = CanTp_SendFC(RxNSduCfgPtr, ChannelIdx, CanTp_FC);
    SchM_Exit_CanTp(CANTP_INSTANCE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
    return ret;
}

/*Handle RX event occurred to the specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_DispatchRxEvent(uint8 ChannelIdx)
{
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(ChannelIdx);
    const CanTp_RxNSduType* RxNSduCfgPtr;
    PduLengthType buffersize;
    PduInfoType pduInfo;
    Std_ReturnType ret;
    uint8 unusedChannelId;
#if (STD_OFF == CANTP_SYNCHRONOUS_RXINDICATION)
    /*A receive has been finish */
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    if (CANTP_FLAGISSET(RxchannelPtr->EventFlags, CANTP_EVENT_RXNOTIFIUPPER))
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    {
        RxNSduCfgPtr = CanTp_GetRxSduCfgByNSduId(RxchannelPtr->NSduId, &unusedChannelId);
        if (RxNSduCfgPtr != NULL_PTR)
        {
#if (CANTP_DIAG_GW_RES_ENABLE == STD_ON)
            const CanTp_ChannelType* channelCfgPtr = &CanTp_ConfigPtr->CanTpChannel[unusedChannelId];
            if (channelCfgPtr->DiagGatewayResponseEnable == TRUE)
            {
#if ((CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON) || (CANTP_DYN_ID_SUPPORT == STD_ON))
                CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);
#endif /* (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON) || (CANTP_DYN_ID_SUPPORT == STD_ON) */
                CanTp_TxConnectionType* TxchannelPtr = CanTp_GetTxChannel(ChannelIdx);
                TxchannelPtr->NeedRes.Started = TRUE;
                TxchannelPtr->NeedRes.RemainTime = channelCfgPtr->DiagGatewayResponseP2;
                TxchannelPtr->NeedRes.ResponseTimer = 0;
                TxchannelPtr->NeedRes.PendingSid = TxchannelPtr->NeedRes.Sid;
                CanTp_ResetTime(&(TxchannelPtr->NeedRes.StartTime));
#if ((CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON) || (CANTP_DYN_ID_SUPPORT == STD_ON))
                /*initialize address information of SDU with MetaData*/
                TxSubchannelPtr->MetaDataN_TA = RxchannelPtr->MetaDataN_SA;
                TxSubchannelPtr->MetaDataN_SA = RxchannelPtr->MetaDataN_TA;
                TxSubchannelPtr->MetaDataN_AE = RxchannelPtr->MetaDataN_AE;
                TxSubchannelPtr->MetaDataLength = RxchannelPtr->MetaDataLength;
#endif /* (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON) || (CANTP_DYN_ID_SUPPORT == STD_ON) */
            }
#endif /* CANTP_DIAG_GW_RES_ENABLE == STD_ON */
            RxchannelPtr->RootState = CANTP_OCCUPIED;
            PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_OK);
            RxchannelPtr->RootState = CANTP_IDLE;
        }
        /*release resource of channel*/
        CanTp_InitRxChannel(ChannelIdx);
    }
#endif /* STD_OFF == CANTP_SYNCHRONOUS_RXINDICATION */
    /*receiving large SDU, trying to get buffer*/
    if (CANTP_RX_LARGE_START == RxchannelPtr->Substate)
    {
        RxNSduCfgPtr = CanTp_GetRxSduCfgByNSduId(RxchannelPtr->NSduId, &unusedChannelId);
        if ((RxNSduCfgPtr != NULL_PTR) && ((RxchannelPtr->ChannelTimer.EnabledTimer == CANTP_NB)))
        {
            pduInfo.SduDataPtr = NULL_PTR;
            pduInfo.SduLength = 0;
            /*query the upper layer about the available buffer size*/
            (void)PduR_CanTpCopyRxData(RxNSduCfgPtr->RxIPduId, &pduInfo, &buffersize);
            /*if or not have enough buffer size in the upper layer to store the next block*/
            ret = CanTp_CompareBufferWithBs(RxNSduCfgPtr, ChannelIdx, buffersize);
            if (E_NOT_OK == ret)
            {
                CanTp_DispatchRxEventSubDeal(ChannelIdx, RxNSduCfgPtr);
            }
            else
            {
                /*upper buffer bigger than next block size*/
                /*FF reception finished or current BS reception finished, send FC_CTS to start a block*/
                ret = CanTp_RxBlockStart(RxNSduCfgPtr, ChannelIdx);
                if (E_NOT_OK == ret)
                {
                    CanTp_ReleaseRxChannel(ChannelIdx);
                    PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
                }
            }
        }
    }
}

/*Handle RX event occurred to the specific channel.*/
static FUNC(void, CANTP_CODE)
    CanTp_DispatchRxEventSubDeal(uint8 ChannelIdx, P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr)
{
    uint8 wtfMax;
    Std_ReturnType ret = E_NOT_OK;
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(ChannelIdx);
    CanTp_FCInfoType CanTp_FC;

    /*upper buffer smaller than next block size, can not receive*/
    if (0u == RxchannelPtr->ChannelTimer.RemainTime)
    {
        wtfMax = (RxNSduCfgPtr->RxWftMax != NULL_PTR) ? (*(RxNSduCfgPtr->RxWftMax)) : 0xFFu;
        /*Nbr expires*/
        if (0u != wtfMax)
        {
            /*If the whole SDU will be send in more than one single
            block(I.E. BS is not zero) and it the end of
            current block but not the last block, or if currently it
            is handling First Frame, it is allowed to send FC_WAIT*/
            if ((CANTP_FTYPE_FF == RxchannelPtr->HandleType)
                || ((RxchannelPtr->CurrentBs == RxchannelPtr->HandledCfCount) && (RxchannelPtr->SduDataRemaining > 0u)))
            {
                /*Try to send FC_WAIT*/
                if (wtfMax <= RxchannelPtr->SentWftCount)
                {
                    /*Can not send any more FC_WAIT. Abort this reception*/
                    /*release resource of this channel*/
                    CanTp_ReleaseRxChannel(ChannelIdx);
                    PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
                }
                else
                {
                    /*Send FC_WAIT and then wait for the confirmation*/
                    CanTp_FC.FcFs = CANTP_FC_FS_WT;
                    CanTp_FC.FcBS = 0;
                    CanTp_FC.FcSTMin = 0;
                    /*send FC OK*/
                    RxchannelPtr->SentWftCount++;
                    /*transit to waiting for confirmation of FC_WAIT*/
                    RxchannelPtr->Substate = CANTP_RX_LARGE_V4FCWT_CFM;
                    if (RxNSduCfgPtr->Nar != NULL_PTR)
                    {
                        RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_NA;
                        RxchannelPtr->ChannelTimer.RemainTime = *(RxNSduCfgPtr->Nar);
                        CanTp_ResetTime(&(RxchannelPtr->ChannelTimer.StartTime));
                    }
                    else
                    {
                        RxchannelPtr->ChannelTimer.EnabledTimer = CANTP_TIMER_NONE;
                    }
                    ret = CanTp_SendFC(RxNSduCfgPtr, ChannelIdx, CanTp_FC);
                }
            } /*END OF try to send FC_WAIT*/
        }
        else
        {
            ret = E_NOT_OK;
        }
        if (E_NOT_OK == ret)
        {
            /*send FC filed or wtfMax is 0,release resource of channel*/
            CanTp_ReleaseRxChannel(ChannelIdx);
            PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
        }
    } /*End of Nbr expires*/
}

/*Handle TX event occurred to the specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_DispatchTxEvent(uint8 ChannelIdx)
{
    const CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);
    const CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(ChannelIdx);

    if ((CANTP_RX_LARGE_V4FCWT_CFM != RxchannelPtr->Substate) && (CANTP_RX_LARGE_V4FCCTS_CFM != RxchannelPtr->Substate))
    {
        switch (TxSubchannelPtr->Substate)
        {
        case CANTP_TX_SF_START:
            /*transmitting SF, trying to get buffer*/
            CanTp_TxHandleSFStart(ChannelIdx);
            break;
        case CANTP_TX_LARGE_START:
            /*transmitting large SDU, trying to get buffer*/
            CanTp_TxHandleLargeStart(ChannelIdx);
            break;
        default:
            /*No special handling needed*/
            break;
        }
    }
}

/*handling for SF transmitting.*/
static FUNC(void, CANTP_CODE) CanTp_TxHandleSFStart(uint8 ChannelIdx)
{
    CanTp_TxConnectionType* TxchannelPtr = CanTp_GetTxChannel(ChannelIdx);
    CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);
    PduInfoType pduInfo;
    const CanTp_TxNSduType* txSduCfgPtr;
    BufReq_ReturnType bufRslt;
    Std_ReturnType rslt;
    uint8 totalOffset;
    uint8 unusedchannelId;
    PduLengthType unusedavailableDataPtr;
    /*local buffer of channel*/
    uint8* pLocalBuf = TxchannelPtr->LocalBuf;
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
    pduInfo.MetaDataPtr = TxchannelPtr->Metadata;
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
    txSduCfgPtr = CanTp_GetTxSduCfgByTxSduId(TxSubchannelPtr->NSduId, &unusedchannelId);

    /*construct SF PCI information*/
    CanTp_ConstructSFPci(ChannelIdx, txSduCfgPtr, pLocalBuf, &totalOffset);
    pduInfo.SduDataPtr = &pLocalBuf[totalOffset];
    pduInfo.SduLength = TxSubchannelPtr->SduDataRemaining;
    /*upperBufRemaining is upper layer data left after copy data*/
    bufRslt = PduR_CanTpCopyTxData(txSduCfgPtr->TxIPduId, &pduInfo, NULL_PTR, &unusedavailableDataPtr);
    /*Handle according to the request buffer result*/
    switch (bufRslt)
    {
    case BUFREQ_OK: {
        /*get length of the data copy*/
        TxSubchannelPtr->SduDataRemaining -= pduInfo.SduLength;
        if (0u == TxSubchannelPtr->SduDataRemaining)
        {
            /*SF data copy finished, send it*/
            /*construct CANIF transmit request*/
            pduInfo.SduDataPtr = pLocalBuf;
            pduInfo.SduLength += (PduLengthType)totalOffset;
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
            CanTp_ConstructTxMetaDataInfo(ChannelIdx, txSduCfgPtr, &pduInfo);
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
            /*pduInfo.SduLength will be set in the api below, if padding*/
            CanTp_TxSFPadding(ChannelIdx, txSduCfgPtr, &pduInfo);
            /*Transit channel to wait for confirmation of SF*/
            TxSubchannelPtr->Substate = CANTP_TX_SF_V4SF_CFM;
            TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_NA;
            TxSubchannelPtr->ChannelTimer.RemainTime = txSduCfgPtr->Nas;
            CanTp_ResetTime(&(TxSubchannelPtr->ChannelTimer.StartTime));
            /*Request CANIF to transmit the SF frame*/
            rslt = CanIf_Transmit(txSduCfgPtr->TxLPduId, &pduInfo);
            if (E_NOT_OK == rslt)
            {
                /* change tx RootState to idle , avoid release call the txconfiramation with E_NOT_OK*/
                TxSubchannelPtr->RootState = CANTP_IDLE;
                /*Release resources related to the channel*/
                CanTp_ReleaseTxChannel(ChannelIdx);
                /*Notify the upper*/
                PduR_CanTpTxConfirmation(txSduCfgPtr->TxIPduId, E_NOT_OK);
            }
            else
            {
                /* do nothing */
            }
        } /*END OF SF data copy finished*/
        break;
    } /*ENDOF case BUFREQ_OK*/
    case BUFREQ_E_NOT_OK: {
        /* change tx RootState to idle , avoid release call the txconfiramation with E_NOT_OK*/
        TxSubchannelPtr->RootState = CANTP_IDLE;
        /*Fail to get TX buffer, Release resources related to the channel*/
        CanTp_ReleaseTxChannel(ChannelIdx);
        /*Notify the upper*/
        PduR_CanTpTxConfirmation(txSduCfgPtr->TxIPduId, E_NOT_OK);
        break;
    }
    case BUFREQ_E_BUSY:
        /*The upper is busy, no buffer provided. Try to get buffer next round*/
        break;
    default:
        /*invalid return value for PduR_CanTpProvideTxBuffer*/
        break;
    } /*END OF switch*/
}

/* handling for large SDU transmitting, trying to get TX buffer.*/
static FUNC(void, CANTP_CODE) CanTp_TxHandleLargeStart(uint8 ChannelIdx)
{
    CanTp_TxConnectionType* TxchannelPtr = CanTp_GetTxChannel(ChannelIdx);
    CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);
    PduInfoType pduInfo;
    const CanTp_TxNSduType* txSduCfgPtr;
    BufReq_ReturnType bufRslt = BUFREQ_OK;
    Std_ReturnType rslt;
    uint8 totalOffset;
    uint8 unusedchannelId;
    PduLengthType unusedavailableDataPtr;
    PduLengthType CAN_DL;
    /*local buffer of channel*/
    uint8* pLocalBuf = TxchannelPtr->LocalBuf;
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
    pduInfo.MetaDataPtr = TxchannelPtr->Metadata;
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
    txSduCfgPtr = CanTp_GetTxSduCfgByTxSduId(TxSubchannelPtr->NSduId, &unusedchannelId);
    if (CANTP_FTYPE_FF == TxSubchannelPtr->HandleType)
    {
        /*construct FF PCI information*/
        CanTp_ConstructFFPci(ChannelIdx, txSduCfgPtr, pLocalBuf, &totalOffset);
    }
    else
    {
        /*construct CF PCI information*/
        CanTp_ConstructCFPci(ChannelIdx, txSduCfgPtr, pLocalBuf, &totalOffset);
    }

    /*calculate the length which need to be copied*/
    CAN_DL = (txSduCfgPtr->TxNPduDLC <= CANTP_CAN20_FRAME_LEN_MAX) ? txSduCfgPtr->TxNPduDLC :
#if (STD_OFF == CANTP_FD)
                                                                   /*CAN2.0*/
                 CANTP_CAN20_FRAME_LEN_MAX;
#else
                                                                   /*CANFD*/
                 ((CAN20_tp == txSduCfgPtr->CanFrameType) ? CANTP_CAN20_FRAME_LEN_MAX
                                                       : CanTp_MatchDLC(txSduCfgPtr->TxNPduDLC));
#endif /* (STD_OFF == CANTP_FD) */

    pduInfo.SduLength = CAN_DL - totalOffset;
    /*the last CF may less than the length of CAN Frame*/
    if (pduInfo.SduLength > TxSubchannelPtr->SduDataRemaining)
    {
        pduInfo.SduLength = TxSubchannelPtr->SduDataRemaining;
#if (STD_ON == CANTP_FD)
        CAN_DL = CanTp_MatchDLC((pduInfo.SduLength + totalOffset));
#endif /* (STD_ON == CANTP_FD) */
    }
    pduInfo.SduDataPtr = &pLocalBuf[totalOffset];

    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    if ((CANTP_FTYPE_FF == TxSubchannelPtr->HandleType)
        || ((!CANTP_FLAGISSET(TxSubchannelPtr->EventFlags, CANTP_EVENT_COPYANDWAITSTMIN))
            && (CANTP_FTYPE_CF == TxSubchannelPtr->HandleType)))
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    {
        bufRslt = PduR_CanTpCopyTxData(txSduCfgPtr->TxIPduId, &pduInfo, NULL_PTR, &unusedavailableDataPtr);
    }

    switch (bufRslt)
    {
    case BUFREQ_OK:
        /*Set CopyandWaitStminFlg*/
        /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
        CANTP_SETFLAG(TxSubchannelPtr->EventFlags, CANTP_EVENT_COPYANDWAITSTMIN);
        /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
        if (CANTP_FTYPE_FF == TxSubchannelPtr->HandleType)
        {
            /*update channel runtime information, get length of the data copy*/
            TxSubchannelPtr->SduDataRemaining -= pduInfo.SduLength;
            /*send the FF immediately*/
            pduInfo.SduDataPtr = pLocalBuf;
            /*the length include pci info*/
            pduInfo.SduLength += totalOffset;
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
            CanTp_ConstructTxMetaDataInfo(ChannelIdx, txSduCfgPtr, &pduInfo);
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
            /*Transit channel to wait for confirmation of FF*/
            TxSubchannelPtr->Substate = CANTP_TX_LARGE_V4DATA_CFM;
            TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_NA;
            TxSubchannelPtr->ChannelTimer.RemainTime = txSduCfgPtr->Nas;
            CanTp_ResetTime(&(TxSubchannelPtr->ChannelTimer.StartTime));
            rslt = CanIf_Transmit(txSduCfgPtr->TxLPduId, &pduInfo);
            /*Clear CopyandWaitStminFlg*/
            /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
            CANTP_CLEARFLAG(TxSubchannelPtr->EventFlags, CANTP_EVENT_COPYANDWAITSTMIN);
            /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
            if (E_NOT_OK == rslt)
            {
                /* change tx RootState to idle , avoid release call the txconfiramation with E_NOT_OK*/
                TxSubchannelPtr->RootState = CANTP_IDLE;
                CanTp_ReleaseTxChannel(ChannelIdx);
                /*Notify the upper*/
                PduR_CanTpTxConfirmation(txSduCfgPtr->TxIPduId, E_NOT_OK);
            }
            else
            {
                /* do nothing */
            }
        }
        else /*handle the CF transmitting data copy*/
        {
            /*STmin timeout, send the CF immediately*/
            if ((TRUE == TxSubchannelPtr->STminTimer.Started) && (0u == TxSubchannelPtr->STminTimer.RemainTime))
            {
                /*update channel runtime information, get length of the data copy*/
                TxSubchannelPtr->SduDataRemaining -= pduInfo.SduLength;
                pduInfo.SduDataPtr = pLocalBuf;
                pduInfo.SduLength += totalOffset;
                /*pduInfo.SduLength will be set in the api below*/
                if ((0u == TxSubchannelPtr->SduDataRemaining) && (CANTP_PADDING_ON == txSduCfgPtr->TxPaddingActivation))
                {
                    /*CAN2.0 or small CAN FD*/
                    CAN_DL = (CAN_DL < CANTP_CAN20_FRAME_LEN_MAX) ? CANTP_CAN20_FRAME_LEN_MAX : CAN_DL;
                    CanTp_MemorySet(
                        &pduInfo.SduDataPtr[pduInfo.SduLength],
                        CANTP_PADDING_BYTE,
                        (CAN_DL - pduInfo.SduLength));
                    pduInfo.SduLength = CAN_DL;
                }
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
                CanTp_ConstructTxMetaDataInfo(ChannelIdx, txSduCfgPtr, &pduInfo);
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
                /*Transit channel to wait for confirmation of CF*/
                TxSubchannelPtr->Substate = CANTP_TX_LARGE_V4DATA_CFM;
                TxSubchannelPtr->ChannelTimer.EnabledTimer = CANTP_NA;
                TxSubchannelPtr->ChannelTimer.RemainTime = txSduCfgPtr->Nas;
                CanTp_ResetTime(&(TxSubchannelPtr->ChannelTimer.StartTime));
                TxSubchannelPtr->STminTimer.Started = FALSE;
                rslt = CanIf_Transmit(txSduCfgPtr->TxLPduId, &pduInfo);
                /*Clear CopyandWaitStminFlg*/
                /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
                CANTP_CLEARFLAG(TxSubchannelPtr->EventFlags, CANTP_EVENT_COPYANDWAITSTMIN);
                /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
                if (E_NOT_OK == rslt)
                {
                    /* change tx RootState to idle , avoid release call the txconfiramation with E_NOT_OK*/
                    TxSubchannelPtr->RootState = CANTP_IDLE;
                    CanTp_ReleaseTxChannel(ChannelIdx);
                    /*Notify the upper*/
                    PduR_CanTpTxConfirmation(txSduCfgPtr->TxIPduId, E_NOT_OK);
                }
                else
                {
                    /* do nothing */
                }
                
            }
            else /*STmin not time out*/
            {
                /*transit to state SENDCF, wait for sending next round*/
            }
        } /*END OF handle the CF transmitting data copy*/
        break;
    case BUFREQ_E_NOT_OK:
        /* change tx RootState to idle , avoid release call the txconfiramation with E_NOT_OK*/
        TxSubchannelPtr->RootState = CANTP_IDLE;
        /*Fail to get TX buffer, Release resources related to the channel*/
        CanTp_ReleaseTxChannel(ChannelIdx);
        /*Notify the upper*/
        PduR_CanTpTxConfirmation(txSduCfgPtr->TxIPduId, E_NOT_OK);
        break;
    case BUFREQ_E_BUSY:
        if ((CANTP_NC == TxSubchannelPtr->ChannelTimer.EnabledTimer)
            && (0u == TxSubchannelPtr->ChannelTimer.RemainTime))
        {
            /* change tx RootState to idle , avoid release call the txconfiramation with E_NOT_OK*/
            TxSubchannelPtr->RootState = CANTP_IDLE;
            /*STmin timeout, abort send, Release resources related to the channel*/
            CanTp_ReleaseTxChannel(ChannelIdx);
            /*Notify the upper*/
            PduR_CanTpTxConfirmation(txSduCfgPtr->TxIPduId, E_NOT_OK);
        }
        /*The upper is busy, no buffer provided. Try to get buffer next round*/
        break;
    default:
        /*invalid return value*/
        break;
    } /*END OF switch (bufRslt)*/
}

/* Add new request to Rx Queue */
static FUNC(void, CANTP_CODE) CanTp_AddRxQueue(uint8* buffer, uint8 ChannelIdx, uint8* accIndex)
{
    uint8 index;
    uint8 tempCount = *accIndex;
    boolean find = FALSE;
    for (index = 0; index < tempCount; index++)
    {
        if (buffer[index] == ChannelIdx)
        {
            find = TRUE;
            break;
        }
    }
    if (FALSE == find)
    {
        buffer[*accIndex] = ChannelIdx;
        (*accIndex)++;
    }
}

#if (CANTP_DIAG_GW_RES_ENABLE == STD_ON)
/*Handle the diag gateway timer for specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_HandleGatewayTimers(uint8 ChannelIdx)
{
    CanTp_TxConnectionType* TxchannelPtr = CanTp_GetTxChannel(ChannelIdx);
    CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);
    CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);
    uint32 elapsedTick;
    uint8 unusedchannelId;

    if (TRUE == TxchannelPtr->NeedRes.Started)
    {
        uint32 elapsedTick;
        /*update the time information*/
        CanTp_GetTimeSpan(TxchannelPtr->NeedRes.StartTime, &elapsedTick);
        if (TxchannelPtr->NeedRes.RemainTime <= elapsedTick)
        {
            const CanTp_ChannelType* channelCfgPtr = &CanTp_ConfigPtr->CanTpChannel[ChannelIdx];
            PduInfoType pduInfo;
            uint8 totalOffset;
            const CanTp_TxNSduType* txSduCfgPtr = channelCfgPtr->TxNSdus;
            Std_ReturnType rslt;
            /*local buffer of channel*/
            uint8* pLocalBuf = TxchannelPtr->LocalBuf;
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
            pduInfo.MetaDataPtr = TxchannelPtr->Metadata;
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
            TxSubchannelPtr->SduDataTotalCount = 3u;
            /*construct SF PCI information*/
            CanTp_ConstructSFPci(ChannelIdx, txSduCfgPtr, pLocalBuf, &totalOffset);
            pLocalBuf[totalOffset] = 0x7F;
            totalOffset++;
            pLocalBuf[totalOffset] = TxchannelPtr->NeedRes.PendingSid;
            totalOffset++;
            /* updata NeedRes */
            if ((TxchannelPtr->NeedRes.ResponseTimer < channelCfgPtr->DiagGatewayResponseMaxNum)
                || (channelCfgPtr->DiagGatewayResponseMaxNum == 0u))
            {
                /* need to send NRC 78*/
                TxchannelPtr->NeedRes.ResponseTimer++;
                TxchannelPtr->NeedRes.RemainTime = channelCfgPtr->DiagGatewayResponseP2Star;
                CanTp_ResetTime(&(TxchannelPtr->NeedRes.StartTime));
                pLocalBuf[totalOffset] = 0x78;
                totalOffset++;
            }
            else
            {
                /* need to send NRC 10*/
                pLocalBuf[totalOffset] = 0x10;
                totalOffset++;
                TxchannelPtr->NeedRes.Started = FALSE;
            }

            pduInfo.SduDataPtr = pLocalBuf;
            pduInfo.SduLength = (PduLengthType)totalOffset;
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
            CanTp_ConstructTxMetaDataInfo(ChannelIdx, txSduCfgPtr, &pduInfo);
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
            /*pduInfo.SduLength will be set in the api below, if padding*/
            CanTp_TxSFPadding(ChannelIdx, txSduCfgPtr, &pduInfo);
            /*Request CANIF to transmit the SF frame*/
            rslt = CanIf_Transmit(txSduCfgPtr->TxLPduId, &pduInfo);
            if (E_NOT_OK == rslt)
            {
                /* change tx RootState to idle , avoid release call the txconfiramation with E_NOT_OK*/
                TxSubchannelPtr->RootState = CANTP_IDLE;
                /*Release resources related to the channel*/
                CanTp_ReleaseTxChannel(ChannelIdx);
            }
        }
    }
}
#endif /* CANTP_DIAG_GW_RES_ENABLE == STD_ON */

/*Handle the timer for specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_HandleTimers(uint8 ChannelIdx)
{
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(ChannelIdx);
    const CanTp_RxNSduType* RxNSduCfgPtr;
    uint32 elapsedTick;
    uint8 unusedchannelId;

    if (CANTP_LARGE_RECEIVING == RxchannelPtr->RootState)
    {
        /*channel is receiving SDU, Handle ABC timer*/
        if (CANTP_TIMER_NONE != RxchannelPtr->ChannelTimer.EnabledTimer)
        {
            /*update the time information*/
            CanTp_GetTimeSpan(RxchannelPtr->ChannelTimer.StartTime, &elapsedTick);
            if (RxchannelPtr->ChannelTimer.RemainTime <= elapsedTick)
            {
                RxchannelPtr->ChannelTimer.RemainTime = 0;
                /*Channel timer timeout occurred*/
                RxNSduCfgPtr = CanTp_GetRxSduCfgByNSduId(RxchannelPtr->NSduId, &unusedchannelId);
                if (NULL_PTR != RxNSduCfgPtr)
                {
                    /*CANTP_NB deal in CanTp_DispatchRxEvent*/
                    if (CANTP_NB != RxchannelPtr->ChannelTimer.EnabledTimer)
                    {
                        /*release resource of channel*/
                        CanTp_ReleaseRxChannel(ChannelIdx);
                        /*notify upper,receiving failed*/
                        PduR_CanTpRxIndication(RxNSduCfgPtr->RxIPduId, E_NOT_OK);
                    }
                    /*report development error*/
                    CANTP_DET_REPORTRUNTIMEERROR(CANTP_SERVICEID_MAINFUNCTION, CANTP_E_COM);
                }
            }
        }
    }
    CanTp_HandleTxTimers(ChannelIdx);
}

/*Handle the tx timer for specific channel.*/
static FUNC(void, CANTP_CODE) CanTp_HandleTxTimers(uint8 ChannelIdx)
{
    CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);
    const CanTp_TxNSduType* TxSduCfgPtr;
    uint32 elapsedTick;
    uint8 unusedchannelId;

    if ((CANTP_SF_TRANSIMITTING == TxSubchannelPtr->RootState)
        || (CANTP_LARGE_TRANSMITTING == TxSubchannelPtr->RootState))
    {
        /*channel is transmitting SDU*/
        if (CANTP_TIMER_NONE != TxSubchannelPtr->ChannelTimer.EnabledTimer)
        {
            /*update the time information*/
            CanTp_GetTimeSpan(TxSubchannelPtr->ChannelTimer.StartTime, &elapsedTick);
            if (TxSubchannelPtr->ChannelTimer.RemainTime <= elapsedTick)
            {
                TxSubchannelPtr->ChannelTimer.RemainTime = 0;
                /*Channel timer timeout occurred*/
                TxSduCfgPtr = CanTp_GetTxSduCfgByTxSduId(TxSubchannelPtr->NSduId, &unusedchannelId);
                if (NULL_PTR != TxSduCfgPtr)
                {
                    /*CANTP_NC deal in LargeStart*/
                    if (CANTP_NC != TxSubchannelPtr->ChannelTimer.EnabledTimer)
                    {
                        /* change tx RootState to idle , avoid
                        release call the txconfiramation with E_NOT_OK*/
                        TxSubchannelPtr->RootState = CANTP_IDLE;
                        /*release resource of channel*/
                        CanTp_ReleaseTxChannel(ChannelIdx);
                        /*notify upper,transmitting failed*/
                        PduR_CanTpTxConfirmation(TxSduCfgPtr->TxIPduId, E_NOT_OK);
                    }
                    /*report development error*/
                    CANTP_DET_REPORTRUNTIMEERROR(CANTP_SERVICEID_MAINFUNCTION, CANTP_E_COM);
                }
            }
        }

        /*handle STmin timer for transmitter if needed*/
        if ((CANTP_LARGE_TRANSMITTING == TxSubchannelPtr->RootState) && (TRUE == TxSubchannelPtr->STminTimer.Started))
        {
            CanTp_GetTimeSpan(TxSubchannelPtr->STminTimer.StartTime, &elapsedTick);
            if ((TxSubchannelPtr->STminTimer.RemainTime+1) <= elapsedTick)
            {
                TxSubchannelPtr->STminTimer.RemainTime = 0;
            }
        } /*END OF STMin timer handling*/
    }
}

/*
 * Brief               Get SDU configuration by N-SDU ID.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
static FUNC(P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST), CANTP_CODE)
    CanTp_GetRxSduCfgByNSduId(PduIdType CanTpRxSduId, uint8* channelId)
{
    uint8 i;
    uint8 j;
    const CanTp_RxNSduType* RxNSduCfgPtr = NULL_PTR;
    const CanTp_ChannelType* channelCfgPtr;

    for (i = 0; (NULL_PTR == RxNSduCfgPtr) && (i < CanTp_ConfigPtr->ChannelNum); i++)
    {
        channelCfgPtr = &CanTp_ConfigPtr->CanTpChannel[i];
        for (j = 0; (NULL_PTR == RxNSduCfgPtr) && (j < channelCfgPtr->RxNSduNum); j++)
        {
            if (channelCfgPtr->RxNSdus[j].RxNSduId == CanTpRxSduId)
            {
                RxNSduCfgPtr = &channelCfgPtr->RxNSdus[j];
                *channelId = i;
            }
        }
    }
    return RxNSduCfgPtr;
}

/*Get TX-SDU configuration by TX-NSduId.*/
static FUNC(P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST), CANTP_CODE)
    CanTp_GetTxSduCfgByTxSduId(PduIdType TxSduId, uint8* channelId)
{
    const CanTp_TxNSduType* TxSduCfgPtr = NULL_PTR;
    const CanTp_ChannelType* channelCfgPtr;
    uint8 i;
    uint8 j;

    for (i = 0; (NULL_PTR == TxSduCfgPtr) && (i < CANTP_CHANNEL_NUMBER); i++)
    {
        channelCfgPtr = &CanTp_ConfigPtr->CanTpChannel[i];
        for (j = 0; (NULL_PTR == TxSduCfgPtr) && (j < channelCfgPtr->TxNsduNum); j++)
        {
            if (TxSduId == channelCfgPtr->TxNSdus[j].TxNSduId)
            {
                TxSduCfgPtr = &channelCfgPtr->TxNSdus[j];
                *channelId = i;
            }
        }
    }
    return TxSduCfgPtr;
}

/*
 * Brief               Get Tx-SDU configuration by Tx NPDUID.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
static FUNC(P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST), CANTP_CODE)
    CanTp_GetTxSduCfgByTxNPdu(PduIdType CanTpTxPduId, uint8* channelId)
{
    const CanTp_TxNSduType* TxSduCfgPtr = NULL_PTR;
    const CanTp_ChannelType* channelPtr;
    uint8 i;
    uint8 j;

    for (i = 0; (NULL_PTR == TxSduCfgPtr) && (i < CANTP_CHANNEL_NUMBER); i++)
    {
        channelPtr = &CanTp_ConfigPtr->CanTpChannel[i];
        for (j = 0; (NULL_PTR == TxSduCfgPtr) && (j < channelPtr->TxNsduNum); j++)
        {
            if (CanTpTxPduId == channelPtr->TxNSdus[j].TxNPduId)
            {
                TxSduCfgPtr = &channelPtr->TxNSdus[j];
                *channelId = i;
            }
        }
    }
    return TxSduCfgPtr;
}

/*
 * Brief               Get Rx-SDU configuration by Tx-FC NPDUID.
 * ServiceId           N/A
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      N/A
 * Param-Name[out]     N/A
 * Param-Name[in/out]  N/A
 * Return              N/A
 * PreCondition        N/A
 * CallByAPI
 */
static FUNC(P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST), CANTP_CODE)
    CanTp_GetRxSduCfgByTxFCNPdu(PduIdType CanTpTxPduId, uint8* channelId)
{
    const CanTp_RxNSduType* RxNSduCfgPtr = NULL_PTR;
    const CanTp_ChannelType* channelPtr;
    uint8 i;
    uint8 j;

    for (i = 0; (NULL_PTR == RxNSduCfgPtr) && (i < CANTP_CHANNEL_NUMBER); i++)
    {
        channelPtr = &CanTp_ConfigPtr->CanTpChannel[i];
        for (j = 0; (NULL_PTR == RxNSduCfgPtr) && (j < channelPtr->RxNSduNum); j++)
        {
            if ((channelPtr->RxNSdus[j].TxFcNPduId == CanTpTxPduId)
                && ((CANTP_PHYSICAL_RX == channelPtr->RxNSdus[j].RxTaType)
#if (STD_ON == CANTP_FD)
                    || (CANTP_CANFD_PHYSICAL == channelPtr->RxNSdus[j].RxTaType)
#endif /* STD_ON == CANTP_FD */
                        ))
            {
                RxNSduCfgPtr = &channelPtr->RxNSdus[j];
                *channelId = i;
            }
        }
    }
    return RxNSduCfgPtr;
}

#if (CANTP_CHANGE_PARAMETER == STD_ON)
/*check Rx ChangeParameter*/
static FUNC(boolean, CANTP_CODE) CanTP_CheckRxChangeParameter(TPParameterType canTpParam, uint16 value)
{
    boolean paramValid = FALSE;

    if (((TP_BS == canTpParam) && (value < 256u)) || ((TP_STMIN == canTpParam) && ((value > 0x0u) && (value < 0xFFu))))
    {
        paramValid = TRUE;
    }

    return paramValid;
}
#endif /* CANTP_CHANGE_PARAMETER == STD_ON */

#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
