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
**  FILENAME    : PduR_Internal.c                                             **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : PDUR internal API definitions                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "PduR_Internal.h"
#if (STD_OFF == PDUR_ZERO_COST_OPERATION)
#if (PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u)
#include "Det.h"
#endif
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#if (PDUR_SRC_UP_MULTICAST_TX_IF_SUM > 0u)
/*up module Tx 1:n(only If Pdu)*/
#define PDUR_START_SEC_VAR_NO_INIT_BOOLEAN
#include "PduR_MemMap.h"
static VAR(boolean, PDUR_VAR) PduR_UpTxState[PDUR_SRC_UP_MULTICAST_TX_IF_SUM];
#define PDUR_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "PduR_MemMap.h"
#endif

#if (PDUR_DEST_GATEWAY_TP_PDU_SUM > 0u)
/*gateway Tp routing path:all dest pdu(SF/MF,route to Tp or Up)*/
#define PDUR_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"
static VAR(PduR_GateWayDestTpRunTimeType, PDUR_VAR) PduR_GateWayDestTpRTSate[PDUR_DEST_GATEWAY_TP_PDU_SUM];
#define PDUR_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "PduR_MemMap.h"
#endif

#if (PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u)
/*If gateway:dest pdu(PduRDestPduDataProvision) is configuration PDUR_DIRECT,
 * and PduRDestTxBufferRef is configuration*/
#define PDUR_START_SEC_VAR_NO_INIT_8
#include "PduR_MemMap.h"
static VAR(PduR_DestStateType, PDUR_VAR) PduR_DestPduState[PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM];
#define PDUR_STOP_SEC_VAR_NO_INIT_8
#include "PduR_MemMap.h"
#endif
/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
/*all route dest pdus is enable or disable*/
#if (PDUR_DEST_PDU_SUM > 0u)
#define PDUR_START_SEC_VAR_NO_INIT_BOOLEAN
#include "PduR_MemMap.h"
VAR(boolean, PDUR_VAR)
PduRIsEnabled[PDUR_DEST_PDU_SUM];
#define PDUR_STOP_SEC_VAR_NO_INIT_BOOLEAN
#include "PduR_MemMap.h"
#else
#define PDUR_START_SEC_VAR_INIT_PTR
#include "PduR_MemMap.h"
P2VAR(boolean, PDUR_VAR, PDUR_APPL_DATA) PduRIsEnabled = NULL_PTR;
#define PDUR_STOP_SEC_VAR_INIT_PTR
#include "PduR_MemMap.h"
#endif
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#if (0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

#if ((STD_ON == PDUR_TP_COPYTXDATA) && (PDUR_TP_BUFFER_SUM > 0u))
/*copy the tx data from the tp buffer gateway on the fly*/
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CopyTxDataFromTpBufferFly(
    PduIdType DestPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr);
/* PRQA S 3432 -- */     /* MISRA Rule 20.7 */
#endif                   /*(STD_ON == PDUR_TP_COPYTXDATA) && (PDUR_TP_BUFFER_SUM > 0u)*/

#if ((STD_ON == PDUR_TP_COPYTXDATA) && (PDUR_TX_BUFFER_SUM > 0u))
/*copy the tx data from the tx buffer*/
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CopyTxDataFromTxBuffer(
    PduIdType DestPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr);
/* PRQA S 3432 -- */     /* MISRA Rule 20.7 */
#endif                   /*(STD_ON == PDUR_TP_COPYTXDATA) && (PDUR_TX_BUFFER_SUM > 0u)*/

#if (0u < PDUR_TP_BUFFER_SUM)
/*copy the rx pdu data to the tp buffer*/
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CopyRxTpDataToTpBuffer(
    uint8 TpBufferId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) Info,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr);
/* PRQA S 3432 -- */     /* MISRA Rule 20.7 */
#endif                   /*0u < PDUR_TP_BUFFER_SUM*/

#if (0u < PDUR_TP_BUFFER_SUM)
/*find one unused tp buffer.if no unused tp buffer,return 0xff*/
static FUNC(uint8, PDUR_CODE) PduR_FindNextValidTpBuffer(void);
#endif /*0u < PDUR_TP_BUFFER_SUM*/

#if (0u < PDUR_TP_BUFFER_SUM)
/*gateway MF pdu to Tp mode by LoTp_Transmit*/
static FUNC(Std_ReturnType, PDUR_CODE) PduR_GateWayMFToTp(PduIdType PduRDestPduId);
#endif /*0u < PDUR_TP_BUFFER_SUM*/

#if ((STD_ON == PDUR_TP_RXINDICATION) && (PDUR_TX_BUFFER_SUM > 0u))
/*gateway SF pdu to Tp mode by LoTp_Transmit*/
static FUNC(Std_ReturnType, PDUR_CODE) PduR_GateWaySFToTp(PduIdType PduRDestPduId);
#endif

#if (0u < PDUR_TP_BUFFER_SUM)
/*find one valid tp buffer.if not find,return 0xff*/
static FUNC(uint8, PDUR_CODE) PduR_FindValidTpBuffer(uint16 PduRSrcPduId, PduLengthType PduLength);
#endif /*0u < PDUR_TP_BUFFER_SUM*/

#if (0u < PDUR_TP_BUFFER_SUM)
/*find the rx tp pdu active store tp buffer*/
static FUNC(uint8, PDUR_CODE) PduR_FindTpBuffer(uint16 PduRSrcPduId);
#endif /*0u < PDUR_TP_BUFFER_SUM*/

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
#endif /*0u < PDUR_DEST_GATEWAY_TP_PDU_SUM*/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

#if (((STD_ON == PDUR_TRIGGER_TRANSMIT) || (PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u)) && (PDUR_TX_BUFFER_SUM > 0u))
/*clear the buffer(the buffer data have transmit,Whether or not it succeeds)*/
FUNC(void, PDUR_CODE)
PduR_DeQueueBuffer(PduIdType PduId)
{
    uint8 bufferDepth;
    uint16 bufferId;
    uint8 cnt;
    bufferId = PDUR_DESTPDU_CFG(PduId).PduRDestTxBufferRef;
    bufferDepth = PduR_TxBuffer[bufferId].PduRTxBufferDepth;
    if (1u == bufferDepth)
    {
        PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].used = FALSE;
    }
    if (bufferDepth > 1u)
    {
        PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].used = FALSE;
        for (cnt = 0u; cnt < (bufferDepth - 1u); cnt++)
        {
            if (PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt + 1u].used == TRUE)
            {
                PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt].SduLength =
                    PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt + 1u].SduLength;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
                PduR_Memcpy(
                    PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt].MetaData,
                    PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt + 1u].MetaData,
                    8u);
#endif
                PduR_Memcpy(
                    PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt].TxBufferData,
                    PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt + 1u].TxBufferData,
                    PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt + 1u].SduLength);
                PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt].used = TRUE;
                PduR_TxBuffer[bufferId].PduRTxBufferRef[cnt + 1u].used = FALSE;
            }
        }
        PduR_TxBuffer[bufferId].PduRTxBufferRef[bufferDepth - 1u].used = FALSE;
    }
    return;
}
#endif                                                        /*(((STD_ON == PDUR_TRIGGER_TRANSMIT)           \
                                                                || (PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u)) \
                                                                && (PDUR_TX_BUFFER_SUM > 0u))*/

FUNC(void, PDUR_CODE) PduR_InitHandle(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint16 index;
#if (0 < PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM)
    /*if source pdu gateway to other if dest pdus which configed PDUR_DIRECT */
    for (index = 0u; index < PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM; index++) /* PRQA S 2877 */ /* MISRA Rule 4.1 */
    {
        PduR_DestPduState[index] = PDUR_IDLE;
    }
#endif
#if (0 < PDUR_DEST_PDU_SUM)
    /* init all dest pdu state base on RoutingPathGroup parameter PduRIsEnabledAtInit.
     * default state is enabled for dest pdus not included any path group */
    for (index = 0u; index < PDUR_DEST_PDU_SUM; index++)
    {
        PduRIsEnabled[index] = TRUE;
    }
#if (0 < PDUR_ROUTING_PATH_GROUP_SUM)
    for (index = 0u; index < PDUR_ROUTING_PATH_GROUP_SUM; index++) /* PRQA S 2877 */ /* MISRA Rule 4.1 */
    {
        if (FALSE == PDUR_ROUTEPATHGROUP_CFG(index).PduRIsEnabledAtInit)
        {
            PduIdType cnt, destIndex, destPduNumber;
            destPduNumber = PDUR_ROUTEPATHGROUP_CFG(index).PduRDestPduRefNumber;
            for (cnt = 0u; cnt < destPduNumber; cnt++)
            {
                destIndex = PDUR_ROUTEPATHGROUP_CFG(index).PduRDestPduIdRef[cnt];
                PduRIsEnabled[destIndex] = FALSE;
            }
        }
    }
#endif /*(0 < PDUR_ROUTING_PATH_GROUP_SUM)*/
#endif /*(0 < PDUR_DEST_PDU_SUM)*/

#if (0u < PDUR_SRC_UP_MULTICAST_TX_IF_SUM)
    /*up module 1:n(n>1)transmit,used to handle up TxConfirmation*/
    for (index = 0u; index < PDUR_SRC_UP_MULTICAST_TX_IF_SUM; index++) /* PRQA S 2877 */ /* MISRA Rule 4.1 */
    {
        PduR_UpTxState[index] = TRUE;
    }
#endif

#if (0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)
    /*gateway tp routing path,Run Time State of all dest pdu(include up pdu and tp pdu)*/
    for (index = 0u; index < PDUR_DEST_GATEWAY_TP_PDU_SUM; index++)
    {
        PduR_GateWayDestTpRTSate[index].ActiveTpBufferId = PDUR_UNUSED_UINT8;
        PduR_GateWayDestTpRTSate[index].NeedGateWayOnTheFly = FALSE;
        PduR_GateWayDestTpRTSate[index].TpTxConfirmation = TRUE;
        PduR_GateWayDestTpRTSate[index].TxBufferOffset = 0u;
    }
#endif
    return;
}

#if ((0u < PDUR_ROUTING_PATH_GROUP_MAX) && (PDUR_TX_BUFFER_SUM > 0u))
FUNC(void, PDUR_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
PduR_DestPduDefaultValueSet(PduIdType DestPduId, uint16 TxBufferId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (PDUR_DEFAULT_VALUE_LENGTH > 0u)
    if (NULL_PTR != PDUR_DESTPDU_CFG(DestPduId).PduRDefaultValueRef)
    {
        PduR_TxBuffer[TxBufferId].PduRTxBufferRef[0u].SduLength =
            PDUR_DESTPDU_CFG(DestPduId).PduRDefaultValueRef->DefaultValueLength;
        PduR_Memcpy(
            PduR_TxBuffer[TxBufferId].PduRTxBufferRef[0u].TxBufferData,
            &PduR_Default_value[PDUR_DESTPDU_CFG(DestPduId).PduRDefaultValueRef->DefaultValueStart],
            PDUR_DESTPDU_CFG(DestPduId).PduRDefaultValueRef->DefaultValueLength);
        PduR_TxBuffer[TxBufferId].PduRTxBufferRef[0u].used = TRUE;
    }
#endif /*PDUR_DEFAULT_VALUE_LENGTH > 0u*/
    PDUR_NOUSED(DestPduId);
    PDUR_NOUSED(TxBufferId);
    return;
}
#endif /*(0u < PDUR_ROUTING_PATH_GROUP_MAX) && (PDUR_TX_BUFFER_SUM > 0u)*/

#if (STD_ON == PDUR_TRANSMIT_SUPPORT)
FUNC(void, PDUR_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
PduR_MulticastIfPduTxPending(PduIdType TxPduId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (PDUR_SRC_UP_MULTICAST_TX_IF_SUM > 0u)
    if (TRUE == PDUR_SRCEPDU_CFG(TxPduId).PduRSrcPduUpTxConf)
    {
        /*route 1:n,used to handle just the first dest TxConfirm will call up TxConfirm*/
        PduR_UpTxState[PDUR_SRCEPDU_CFG(TxPduId).UpTxconfirmStateIndex] = FALSE;
    }
#endif /*PDUR_SRC_UP_MULTICAST_TX_IF_SUM > 0u*/
    PDUR_NOUSED(TxPduId);
    return;
}
#endif /*(STD_ON == PDUR_TRANSMIT_SUPPORT)*/

#if ((STD_ON == PDUR_RX_INDICATION) && (PDUR_TX_BUFFER_SUM > 0u))
/*If pdu gateway(config buffer and direct) handle*/
FUNC(void, PDUR_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
PduR_GateWayDirectBufferHandle(
    PduR_LoIfTransmit_FuncPtrType pduR_LoIfTransmitApi,
    PduIdType DestPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) InfoPtr)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u)
    PduInfoType pduInfo;
    PduIdType gateWayIfPduDirectStateId;
    uint16 bufferId;
    PduIdType destModulePduId;
    destModulePduId = PDUR_DESTPDU_CFG(DestPduId).PduRDestModulePduIndex;
    bufferId = PDUR_DESTPDU_CFG(DestPduId).PduRDestTxBufferRef;
    gateWayIfPduDirectStateId = PDUR_DESTPDU_CFG(DestPduId).PduRGatewayDirectTxStateIndex;
    /*only 1 buffer,"Last is best" behavior*/
    if (1u == PduR_TxBuffer[bufferId].PduRTxBufferDepth)
    {
        if (PDUR_IDLE == PduR_DestPduState[gateWayIfPduDirectStateId])
        {
            /*transmit the old data in buffer,store the new data to buffer*/
            if (TRUE == PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].used)
            {
                pduInfo.SduDataPtr = PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].TxBufferData;
                pduInfo.SduLength = PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].SduLength;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
                if (0u < PDUR_DESTPDU_CFG(DestPduId).MetaDataLength)
                {
                    pduInfo.MetaDataPtr = PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].MetaData;
                }
                else
#endif
                {
                    pduInfo.MetaDataPtr = NULL_PTR;
                }
                if (E_OK == pduR_LoIfTransmitApi(destModulePduId, &pduInfo))
                {
                    PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_BUSY;
                }
                PduR_EnQueueBuffer(DestPduId, InfoPtr);
            }
            /*transmit the new data,don't store the data even the transmit not ok*/
            else
            {
                if (E_OK == pduR_LoIfTransmitApi(destModulePduId, InfoPtr))
                {
                    PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_BUSY;
                }
            }
        }
        /*gateway if pdu(direct),the pdu is busy.Store the data to buffer*/
        else
        {
            PduR_EnQueueBuffer(DestPduId, InfoPtr);
        }
    }
    /*FIFO*/
    else
    {
        if (PDUR_IDLE == PduR_DestPduState[gateWayIfPduDirectStateId])
        {
            /*transmit the oldest data in buffer,store the new data to buffer*/
            if (TRUE == PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].used)
            {
                pduInfo.SduDataPtr = PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].TxBufferData;
                pduInfo.SduLength = PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].SduLength;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
                if (0u < PDUR_DESTPDU_CFG(DestPduId).MetaDataLength)
                {
                    pduInfo.MetaDataPtr = PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].MetaData;
                }
#endif
                if (E_OK == pduR_LoIfTransmitApi(destModulePduId, &pduInfo))
                {
                    PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_BUSY;
                }
                else
                {
                    (void)Det_ReportRuntimeError(
                        PDUR_MODULE_ID,
                        PDUR_INSTANCE_ID,
                        PDUR_IFRXINDICATION_ID,
                        PDUR_E_PDU_INSTANCES_LOST);
                }
                PduR_DeQueueBuffer(DestPduId);
                PduR_EnQueueBuffer(DestPduId, InfoPtr);
            }
            /*transmit the new data,don't store the data even the transmit not ok*/
            else
            {
                if (E_OK == pduR_LoIfTransmitApi(destModulePduId, InfoPtr))
                {
                    PduR_DestPduState[gateWayIfPduDirectStateId] = PDUR_BUSY;
                }
                else
                {
                    (void)Det_ReportRuntimeError(
                        PDUR_MODULE_ID,
                        PDUR_INSTANCE_ID,
                        PDUR_IFRXINDICATION_ID,
                        PDUR_E_PDU_INSTANCES_LOST);
                }
            }
        }
        /*gateway if pdu(direct),the pdu is busy.Store the data to buffer*/
        else
        {
            PduR_EnQueueBuffer(DestPduId, InfoPtr);
        }
    }
#else
    PDUR_NOUSED(pduR_LoIfTransmitApi);
    PDUR_NOUSED(DestPduId);
    PDUR_NOUSED(InfoPtr);
#endif /*PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u*/
    return;
}
#endif /*(STD_ON == PDUR_RX_INDICATION) && (PDUR_TX_BUFFER_SUM > 0u)*/

#if (STD_ON == PDUR_TX_CONFIRMATION)
FUNC(void, PDUR_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
PduR_MulticastIfPduTxConfirmationHandle(
    PduIdType TxMPduStateId,
    PduIdType UpPduId,
    PduR_UpIfTxConfirmation_FuncPtrType UpIfTxConfirmationApi)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (PDUR_SRC_UP_MULTICAST_TX_IF_SUM > 0u)
    if (FALSE == PduR_UpTxState[TxMPduStateId])
    {
        UpIfTxConfirmationApi(UpPduId);
        PduR_UpTxState[TxMPduStateId] = TRUE;
    }
#else
    PDUR_NOUSED(TxMPduStateId);
    PDUR_NOUSED(UpPduId);
#endif /*PDUR_SRC_UP_MULTICAST_TX_IF_SUM > 0u*/
    return;
}
#endif /*STD_ON == PDUR_TX_CONFIRMATION*/

#if ((STD_ON == PDUR_TX_CONFIRMATION) && (PDUR_TX_BUFFER_SUM > 0u))
/******************************************************************************/
/*
 * Brief               If Pdu Gateway route,Dest Pdu TxConfirmation handle.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxPduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, PDUR_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
PduR_IfTxConfirmationGatewayHandle(PduIdType TxPduId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM > 0u)
    PduR_LoIfTransmit_FuncPtrType PduR_LoIfTransmitApi;
    uint8 moduleIndex;
    PduInfoType pduInfo;
    PduIdType destModulePduId;
    PduIdType gateWayStateId;
    uint16 bufferId = PDUR_DESTPDU_CFG(TxPduId).PduRDestTxBufferRef;
    /*the pdu config buffer and it's PDUR_DIRECT mode*/
    if ((PDUR_UNUSED_UINT16 != bufferId) && (PDUR_DIRECT == PDUR_DESTPDU_CFG(TxPduId).PduRDestPduDataProvision))
    {
        gateWayStateId = PDUR_DESTPDU_CFG(TxPduId).PduRGatewayDirectTxStateIndex;
        PduR_DestPduState[gateWayStateId] = PDUR_IDLE;
        if (TRUE == PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].used)
        {
            moduleIndex = PDUR_DESTPDU_CFG(TxPduId).BswModuleIndex;
            PduR_LoIfTransmitApi = PduR_BswModuleConfigData[moduleIndex].ModuleIfTransmitApi;
            pduInfo.SduDataPtr = PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].TxBufferData;
            pduInfo.SduLength = PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].SduLength;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
            if (0u < PDUR_DESTPDU_CFG(TxPduId).MetaDataLength)
            {
                pduInfo.MetaDataPtr = PduR_TxBuffer[bufferId].PduRTxBufferRef[0u].MetaData;
            }
            else
            {
                pduInfo.MetaDataPtr = NULL_PTR;
            }
#else  /*STD_ON == PDUR_META_DATA_SUPPORT*/
            {
                pduInfo.MetaDataPtr = NULL_PTR;
            }
#endif /*STD_ON == PDUR_META_DATA_SUPPORT*/
            destModulePduId = PDUR_DESTPDU_CFG(TxPduId).PduRDestModulePduIndex;
            if (E_OK == PduR_LoIfTransmitApi(destModulePduId, &pduInfo))
            {
                PduR_DestPduState[gateWayStateId] = PDUR_BUSY;
            }
            else
            {
                /*transmit not ok(FIFO),report det error*/
                if (1u < PduR_TxBuffer[bufferId].PduRTxBufferDepth)
                {
                    (void)Det_ReportRuntimeError(
                        PDUR_MODULE_ID,
                        PDUR_INSTANCE_ID,
                        PDUR_IFTXCONFIRMATION_ID,
                        PDUR_E_PDU_INSTANCES_LOST);
                }
            }
            PduR_DeQueueBuffer(TxPduId);
        }
    }
#else
    PDUR_NOUSED(TxPduId);
#endif
    return;
}
#endif /*(STD_ON == PDUR_TX_CONFIRMATION) && (PDUR_TX_BUFFER_SUM > 0u)*/

#if (STD_ON == PDUR_TP_STARTOFRECEPTION_TRANSMIT)
/******************************************************************************/
/*
 * Brief               Rx Tp Pdu gateway to only one Tp Module Pdu handle,
 *                     when start of reception.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SrcPduId,info,Length
 * Param-Name[out]     bufferSizePtr
 * Param-Name[in/out]  None
 * Return              BufReq_ReturnType
 */
/******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE)
/* PRQA S 1532,3432 ++ */ /* MISRA Rule 8.7,20.7 */
PduR_StartOfReceptionToOneTpHandle(
    PduIdType SrcPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    PduLengthType Length,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) bufferSizePtr)
/* PRQA S 1532,3432 -- */ /* MISRA Rule 8.7,20.7 */
{
#if (0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)
    BufReq_ReturnType bufQeqReturn = BUFREQ_OK;
#if (0u < PDUR_TP_BUFFER_SUM)
    uint8 findTpBuffer;
#endif
#if (PDUR_TX_BUFFER_SUM > 0u)
    uint16 pduRDestTxBuffeId;
#endif
    PduIdType gatewayTpRunTimeId;
    PduIdType destPduId;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
    uint8 metaDataLength;
    metaDataLength = PDUR_SRCEPDU_CFG(SrcPduId).MetaDataLength;
#endif
    destPduId = PDUR_ROUTINGPATH_CFG(SrcPduId).PduRDestPduIdRef[0u];
    gatewayTpRunTimeId = PDUR_DESTPDU_CFG(destPduId).GateWayTpRunTimeIndex;
    if (TRUE == PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TpTxConfirmation)
    {
#if (PDUR_TX_BUFFER_SUM > 0u)
        pduRDestTxBuffeId = PDUR_DESTPDU_CFG(destPduId).PduRDestTxBufferRef;
        /*SF tp pdu gateway,need store in dedicated buffer(BufferDepth is 1)*/
        if ((PDUR_UNUSED_UINT16 != pduRDestTxBuffeId) && (PduR_TxBuffer[pduRDestTxBuffeId].PduRPduMaxLength >= Length))
        {
            if (FALSE == PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].used)
            {
                PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].used = TRUE;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
                if ((0u < metaDataLength) && (NULL_PTR != info) && (NULL_PTR != info->MetaDataPtr))
                {
                    PduR_Memcpy(
                        PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].MetaData,
                        info->MetaDataPtr,
                        (PduLengthType)metaDataLength);
                }
#endif
                if ((NULL_PTR != info) && (NULL_PTR != info->SduDataPtr))
                {
                    PduR_Memcpy(
                        PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].TxBufferData,
                        info->SduDataPtr,
                        info->SduLength);
                    PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].SduLength = info->SduLength;
                }
                else
                {
                    PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].SduLength = 0u;
                }
                PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset = 0u;
                PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TpTxConfirmation = FALSE;
                *bufferSizePtr =
                    (PduR_TxBuffer[pduRDestTxBuffeId].PduRPduMaxLength
                     - PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].SduLength);
            }
            else
            {
                bufQeqReturn = BUFREQ_E_OVFL;
            }
        }
        /*MF tp pdu gateway,need store in tp buffer*/
        else
#endif /*PDUR_TX_BUFFER_SUM > 0u*/
        {
#if (0u < PDUR_TP_BUFFER_SUM)
            findTpBuffer = PduR_FindValidTpBuffer(SrcPduId, Length);
            /*find the valid tp buffer*/
            if (PDUR_UNUSED_UINT8 != findTpBuffer)
            {
                PduR_TpBuffer[findTpBuffer].used = TRUE;
                PduR_TpBuffer[findTpBuffer].RxBufferOffset = 0u;
                PduR_TpBuffer[findTpBuffer].SduLength = Length;
                PduR_TpBuffer[findTpBuffer].PduHandleId = SrcPduId;
                PduR_TpBuffer[findTpBuffer].NextTpBufferId = PDUR_UNUSED_UINT8;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
                if ((0u < metaDataLength) && (NULL_PTR != info) && (NULL_PTR != info->MetaDataPtr))
                {
                    PduR_Memcpy(PduR_TpBuffer[findTpBuffer].MetaData, info->MetaDataPtr, (PduLengthType)metaDataLength);
                }
#endif
                if ((NULL_PTR != info) && (NULL_PTR != info->SduDataPtr))
                {
                    bufQeqReturn = PduR_CopyRxTpDataToTpBuffer(findTpBuffer, info, bufferSizePtr);
                }
                else
                {
                    *bufferSizePtr = PduR_TpBuffer[findTpBuffer].TpBufferLength;
                }
                if (BUFREQ_OK == bufQeqReturn)
                {
                    PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].ActiveTpBufferId = findTpBuffer;
                    PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TpTxConfirmation = FALSE;
                    PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset = 0u;
                    /*gateway-on-the-fly*/
                    if (TRUE == PDUR_ROUTINGPATH_CFG(SrcPduId).GatewayOnTheFly)
                    {
                        PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].NeedGateWayOnTheFly = TRUE;
                        if (PduR_TpBuffer[findTpBuffer].RxBufferOffset >= PDUR_DESTPDU_CFG(destPduId).PduRTpThreshold)
                        {
                            /*gateway MF pdu to Tp mode by LoTp_Transmit*/
                            if (E_NOT_OK == PduR_GateWayMFToTp(destPduId))
                            {
                                PduR_ClearBufferAndStateOfGateWayTpPdu(SrcPduId);
                                bufQeqReturn = BUFREQ_E_NOT_OK;
                            }
                            PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].NeedGateWayOnTheFly = FALSE;
                        }
                    }
                }
                else
                {
                    PduR_ClearBufferAndStateOfGateWayTpPdu(SrcPduId);
                    bufQeqReturn = BUFREQ_E_NOT_OK;
                }
            }
            else
#endif /*0u < PDUR_TP_BUFFER_SUM*/
            {
                bufQeqReturn = BUFREQ_E_OVFL;
            }
        }
    }
    else
    {
        bufQeqReturn = BUFREQ_E_NOT_OK;
    }
    return bufQeqReturn;
#else  /*0u < PDUR_DEST_GATEWAY_TP_PDU_SUM*/
    PDUR_NOUSED(SrcPduId);
    PDUR_NOUSED(info);
    PDUR_NOUSED(Length);
    PDUR_NOUSED(bufferSizePtr);
    return BUFREQ_E_NOT_OK;
#endif /*0u < PDUR_DEST_GATEWAY_TP_PDU_SUM*/
}
#endif /*STD_ON == PDUR_TP_STARTOFRECEPTION_TRANSMIT*/

#if (STD_ON == PDUR_TP_COPYRXDATA)
/******************************************************************************/
/*
 * Brief               Rx Tp Pdu gateway to only one Tp Module Pdu handle,
 *                     when copy Rx Data.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SrcPduId,DestPduId,info,BufferSizePtr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE)
/* PRQA S 1532,3432 ++ */ /* MISRA Rule 8.7,20.7 */
PduR_CopyRxDataToOneTpHandle(
#if (0u < PDUR_TP_BUFFER_SUM)
    PduIdType SrcPduId,
#endif
    PduIdType DestPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr)
/* PRQA S 1532,3432 -- */ /* MISRA Rule 8.7,20.7 */
{
    BufReq_ReturnType bufQeqReturn = BUFREQ_E_NOT_OK;
#if (0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)
    PduIdType gateWayTpRunTimeId = PDUR_DESTPDU_CFG(DestPduId).GateWayTpRunTimeIndex;
#if (PDUR_TX_BUFFER_SUM > 0u)
    uint16 pduRDestTxBuffeId;
    PduLengthType rxOffset;
#endif
#if (0u < PDUR_TP_BUFFER_SUM)
    uint8 tpBufferId;
    uint16 pduRTpThreshold;
#endif
    if ((PDUR_UNUSED_UINT16 != gateWayTpRunTimeId)
        && (FALSE == PduR_GateWayDestTpRTSate[gateWayTpRunTimeId].TpTxConfirmation))
    {
#if (PDUR_TX_BUFFER_SUM > 0u)
        pduRDestTxBuffeId = PDUR_DESTPDU_CFG(DestPduId).PduRDestTxBufferRef;
        /*the tp data is stored in Dedicated buffer(SF)*/
        if ((PDUR_UNUSED_UINT16 != pduRDestTxBuffeId)
            && (TRUE == PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].used))
        {
            rxOffset = PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].SduLength;
            if ((rxOffset + info->SduLength) <= PduR_TxBuffer[pduRDestTxBuffeId].PduRPduMaxLength)
            {
                PduR_Memcpy(
                    &(PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].TxBufferData[rxOffset]),
                    info->SduDataPtr,
                    info->SduLength);
                PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].SduLength += info->SduLength;
                *BufferSizePtr = PduR_TxBuffer[pduRDestTxBuffeId].PduRPduMaxLength - (rxOffset + info->SduLength);
                bufQeqReturn = BUFREQ_OK;
            }
        }
        /*the tp data is stored in Tp buffer(FF and CF)*/
        else
#endif /*PDUR_TX_BUFFER_SUM > 0u*/
        {
#if (0u < PDUR_TP_BUFFER_SUM)
            /*find the valid tp buffer to copy the data*/
            tpBufferId = PduR_FindTpBuffer(SrcPduId);
            if (PDUR_UNUSED_UINT8 != tpBufferId)
            {
                /*copy the rx pdu data to the tp buffer*/
                bufQeqReturn = PduR_CopyRxTpDataToTpBuffer(tpBufferId, info, BufferSizePtr);
                if ((BUFREQ_OK == bufQeqReturn) && (TRUE == PDUR_ROUTINGPATH_CFG(SrcPduId).GatewayOnTheFly))
                {
                    pduRTpThreshold = PDUR_DESTPDU_CFG(DestPduId).PduRTpThreshold;
                    if ((TRUE == PduR_GateWayDestTpRTSate[gateWayTpRunTimeId].NeedGateWayOnTheFly)
                        && (PduR_TpBuffer[tpBufferId].RxBufferOffset >= pduRTpThreshold))
                    {
                        /*gateway MF pdu to Tp mode by LoTp_Transmit*/
                        if (E_NOT_OK == PduR_GateWayMFToTp(DestPduId))
                        {
                            bufQeqReturn = BUFREQ_E_NOT_OK;
                            PduR_ClearBufferAndStateOfGateWayTpPdu(SrcPduId);
                        }
                        PduR_GateWayDestTpRTSate[gateWayTpRunTimeId].NeedGateWayOnTheFly = FALSE;
                    }
                }
            }
#endif /*0u < PDUR_TP_BUFFER_SUM*/
        }
    }
#else /*(0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)*/
#if (0u < PDUR_TP_BUFFER_SUM)
    PDUR_NOUSED(SrcPduId);
#endif
    PDUR_NOUSED(DestPduId);
    PDUR_NOUSED(info);
    PDUR_NOUSED(BufferSizePtr);
#endif /*(0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)*/
    return bufQeqReturn;
}
#endif /*STD_ON == PDUR_TP_COPYRXDATA*/

#if (STD_ON == PDUR_TP_RXINDICATION)
/******************************************************************************/
/*
 * Brief               Rx Tp Pdu gateway to only one Tp Module Pdu handle,
 *                     when Rx Indication.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SrcPduId,DestPduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, PDUR_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
PduR_RxIndicationToOneTpHandle(PduIdType SrcPduId, PduIdType DestPduId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
#if (0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)
    PduIdType gatewayTpRunTimeId;
    gatewayTpRunTimeId = PDUR_DESTPDU_CFG(DestPduId).GateWayTpRunTimeIndex;
    /*pdu data stored in dedicated buffer(SF)*/
    if (PDUR_UNUSED_UINT8 == PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].ActiveTpBufferId)
    {
#if (PDUR_TX_BUFFER_SUM > 0u)
        /*gateway SF pdu to Tp mode by LoTp_Transmit*/
        if (E_NOT_OK == PduR_GateWaySFToTp(DestPduId))
        {
            PduR_ClearBufferAndStateOfGateWayTpPdu(SrcPduId);
        }
#endif
    }
#if (0u < PDUR_TP_BUFFER_SUM)
    /*pdu data stored in tp buffer*/
    else
    {
        /*gateway-on-the-fly mode,but the PduRTpThreshold is large than the pdu length*/
        if (TRUE == PDUR_ROUTINGPATH_CFG(SrcPduId).GatewayOnTheFly)
        {
            if (TRUE == PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].NeedGateWayOnTheFly)
            {
                /*gateway MF pdu to Tp mode by LoTp_Transmit*/
                if (E_OK == PduR_GateWayMFToTp(DestPduId))
                {
                    PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].NeedGateWayOnTheFly = FALSE;
                }
                else
                {
                    PduR_ClearBufferAndStateOfGateWayTpPdu(SrcPduId);
                }
            }
        }
        /*Receive all pdu data,then gateway to other tp module*/
        else
        {
            /*gateway MF pdu to Tp mode by LoTp_Transmit*/
            if (E_NOT_OK == PduR_GateWayMFToTp(DestPduId))
            {
                PduR_ClearBufferAndStateOfGateWayTpPdu(SrcPduId);
            }
        }
    }
#endif /*0u < PDUR_TP_BUFFER_SUM*/
#else  /*(0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)*/
    PDUR_NOUSED(SrcPduId);
    PDUR_NOUSED(DestPduId);
#endif /*(0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)*/
    return;
}
#endif /*STD_ON == PDUR_TP_RXINDICATION*/

#if (STD_ON == PDUR_TP_COPYTXDATA)
/******************************************************************************/
/*
 * Brief               one Tp Pdu route to one Tp Pdu,the dest pdu copy tx
 *                     data handle.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DestPduId,info,retry,availableDataPtr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(BufReq_ReturnType, PDUR_CODE)
/* PRQA S 1532,3432 ++ */ /* MISRA Rule 8.7,20.7 */
PduR_OneDestCopyTxDataFromTpHandle(
    PduIdType DestPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
/* PRQA S 1532,3432 -- */ /* MISRA Rule 8.7,20.7 */
{
    BufReq_ReturnType bufQeqReturn = BUFREQ_E_NOT_OK;
#if (0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)
    PduIdType gatewayTpRunTimeId;
    uint8 tpBufferId;
#if (PDUR_TP_BUFFER_SUM > 0u)
    PduIdType srcPduId;
    srcPduId = PDUR_DESTPDU_CFG(DestPduId).PduRSrcPduRef;
#endif
    gatewayTpRunTimeId = PDUR_DESTPDU_CFG(DestPduId).GateWayTpRunTimeIndex;
    if (FALSE == PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TpTxConfirmation)
    {
        tpBufferId = PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].ActiveTpBufferId;
/*Gateway Single-Frame I-PDU*/
#if (PDUR_TX_BUFFER_SUM > 0u)
        if (PDUR_UNUSED_UINT8 == tpBufferId)
        {
            bufQeqReturn = PduR_CopyTxDataFromTxBuffer(DestPduId, info, retry, availableDataPtr);
        }
        /*Gateway Multi-Frame I-PDU*/
        else
#endif /*PDUR_TX_BUFFER_SUM > 0u*/
        {
#if (PDUR_TP_BUFFER_SUM > 0u)
#if (STD_ON == PDUR_META_DATA_SUPPORT)
            if ((0u < PDUR_DESTPDU_CFG(DestPduId).MetaDataLength) && (NULL_PTR != info->MetaDataPtr))
            {
                PduR_Memcpy(
                    info->MetaDataPtr,
                    PduR_TpBuffer[tpBufferId].MetaData,
                    (PduLengthType)PDUR_DESTPDU_CFG(DestPduId).MetaDataLength);
            }
#endif /*STD_ON == PDUR_META_DATA_SUPPORT*/
            /*gateway-on-the-fly mode*/
            if (TRUE == PDUR_ROUTINGPATH_CFG(srcPduId).GatewayOnTheFly)
            {
                if ((NULL_PTR == retry) || (TP_DATACONF == retry->TpDataState))
                {
                    bufQeqReturn = PduR_CopyTxDataFromTpBufferFly(DestPduId, info, availableDataPtr);
                }
                else
                {
                    bufQeqReturn = BUFREQ_E_NOT_OK;
                }
            }
            /*not gateway-on-the-fly mode*/
            else
            {
                if ((NULL_PTR != retry) && (TP_DATARETRY == retry->TpDataState))
                {
                    if (PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset >= retry->TxTpDataCnt)
                    {
                        PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset -= retry->TxTpDataCnt;
                    }
                    /*will not happen general,TP module guarantee*/
                    else
                    {
                        /*re-copy data from 0*/
                        PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset = 0u;
                    }
                }
                /*don't copy data,just update the available data length and tell Lo Tp Module */
                if (0u == info->SduLength)
                {
                    *availableDataPtr = PduR_TpBuffer[tpBufferId].RxBufferOffset
                                        - PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset;
                    bufQeqReturn = BUFREQ_OK;
                }
                /*copy data and tell Lo Tp Module the available data length*/
                else
                {
                    if ((PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset + info->SduLength)
                        <= PduR_TpBuffer[tpBufferId].RxBufferOffset)
                    {
                        PduR_Memcpy(
                            info->SduDataPtr,
                            &(PduR_TpBuffer[tpBufferId]
                                  .TpBufferData[PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset]),
                            info->SduLength);
                        PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset += info->SduLength;
                        *availableDataPtr = PduR_TpBuffer[tpBufferId].RxBufferOffset
                                            - PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset;
                        bufQeqReturn = BUFREQ_OK;
                    }
                    /*will not happen general,TP module guarantee*/
                    else
                    {
                        bufQeqReturn = BUFREQ_E_NOT_OK;
                    }
                }
            }
#endif /*PDUR_TP_BUFFER_SUM > 0u*/
        }
    }
#else  /*(0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)*/
    PDUR_NOUSED(DestPduId);
    PDUR_NOUSED(info);
    PDUR_NOUSED(retry);
    PDUR_NOUSED(availableDataPtr);
#endif /*(0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)*/
    return bufQeqReturn;
}
#endif /*STD_ON == PDUR_TP_COPYTXDATA*/

#if ((0u < PDUR_DEST_GATEWAY_TP_PDU_SUM) || (STD_ON == PDUR_TP_RXINDICATION) || (STD_ON == PDUR_TP_TXCONFIRMATION))
/******************************************************************************/
/*
 * Brief               clear buffer and gateway state for gateway tp pdu.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      PduRSrcPduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, PDUR_CODE)
PduR_ClearBufferAndStateOfGateWayTpPdu(PduIdType PduRSrcPduId)
{
#if (0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)
#if (0u < PDUR_TP_BUFFER_SUM)
    uint8 cnt;
#endif
    PduIdType pduRDestPduId;
#if (PDUR_TX_BUFFER_SUM > 0u)
    uint16 pduRDestTxBuffeIndex;
#endif
    PduIdType gatewayTpRunTimeId;
    if (1u == PDUR_ROUTINGPATH_CFG(PduRSrcPduId).PduDestSum)
    {
        pduRDestPduId = PDUR_ROUTINGPATH_CFG(PduRSrcPduId).PduRDestPduIdRef[0u];
#if (PDUR_TX_BUFFER_SUM > 0u)
        pduRDestTxBuffeIndex = PDUR_DESTPDU_CFG(pduRDestPduId).PduRDestTxBufferRef;
        /*clear dedicated buffer*/
        if ((PDUR_UNUSED_UINT16 != pduRDestTxBuffeIndex)
            && (TRUE == PduR_TxBuffer[pduRDestTxBuffeIndex].PduRTxBufferRef[0u].used))
        {
            PduR_TxBuffer[pduRDestTxBuffeIndex].PduRTxBufferRef[0u].SduLength = 0u;
            PduR_TxBuffer[pduRDestTxBuffeIndex].PduRTxBufferRef[0u].used = FALSE;
        }
        else
#endif /*PDUR_TX_BUFFER_SUM > 0u*/
        {
#if (0u < PDUR_TP_BUFFER_SUM)
            /*clear tp buffer*/
            for (cnt = 0u; cnt < PDUR_TP_BUFFER_SUM; cnt++)
            {
                if ((TRUE == PduR_TpBuffer[cnt].used) && (PduRSrcPduId == PduR_TpBuffer[cnt].PduHandleId))
                {
                    PduR_TpBuffer[cnt].NextTpBufferId = PDUR_UNUSED_UINT8;
                    PduR_TpBuffer[cnt].PduHandleId = PDUR_UNUSED_UINT16;
                    PduR_TpBuffer[cnt].RxBufferOffset = 0u;
                    PduR_TpBuffer[cnt].SduLength = 0u;
                    PduR_TpBuffer[cnt].used = FALSE;
                }
            }
#endif /*0u < PDUR_TP_BUFFER_SUM*/
        }
        gatewayTpRunTimeId = PDUR_DESTPDU_CFG(pduRDestPduId).GateWayTpRunTimeIndex;
        PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].ActiveTpBufferId = PDUR_UNUSED_UINT8;
        PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TpTxConfirmation = TRUE;
        PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset = 0u;
        PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].NeedGateWayOnTheFly = FALSE;
    }
#else  /*(0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)*/
    PDUR_NOUSED(PduRSrcPduId);
#endif /*(0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)*/
    return;
}
#endif /*(0u < PDUR_DEST_GATEWAY_TP_PDU_SUM) || (STD_ON == PDUR_TP_RXINDICATION) || (STD_ON == \
          PDUR_TP_TXCONFIRMATION)*/

#if ((PDUR_TP_BUFFER_SUM > 0u) || (PDUR_TX_BUFFER_SUM > 0u))
/******************************************************************************/
/*
 * Brief               copy data from source to dest.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      dest,source,length
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, PDUR_CODE)
/* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
PduR_Memcpy(P2VAR(uint8, AUTOMATIC, AUTOMATIC) dest, P2CONST(uint8, AUTOMATIC, AUTOMATIC) source, PduLengthType length)
/* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
{
    PduLengthType dataLength;
    dataLength = length;
    while (dataLength > 0u)
    {
        *dest = *source;
        dest++;
        source++;
        dataLength--;
    }
    return;
}
#endif /*(PDUR_TP_BUFFER_SUM > 0u) || (PDUR_TX_BUFFER_SUM > 0u)*/
#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if (0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)
#define PDUR_START_SEC_CODE
#include "PduR_MemMap.h"

#if ((STD_ON == PDUR_TP_COPYTXDATA) && (PDUR_TP_BUFFER_SUM > 0u))
/******************************************************************************/
/*
 * Brief               copy the tx data from the tp buffer gateway on the fly.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DestPduId,info
 * Param-Name[out]     availableDataPtr
 * Param-Name[in/out]  None
 * Return              BufReq_ReturnType
 */
/******************************************************************************/
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CopyTxDataFromTpBufferFly(
    PduIdType DestPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
/* PRQA S 3432 -- */     /* MISRA Rule 20.7 */
{
    BufReq_ReturnType bufQeqReturn;
    uint8 tpBufferId;
    uint8 nextTpBufferId;
    PduLengthType nextTpBufferNeedCopyLength;
    PduIdType gatewayTpRunTimeId;
    gatewayTpRunTimeId = PDUR_DESTPDU_CFG(DestPduId).GateWayTpRunTimeIndex;
    tpBufferId = PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].ActiveTpBufferId;
    nextTpBufferId = PduR_TpBuffer[tpBufferId].NextTpBufferId;
    /*the active tp buffer have stored full and other tp buffer have start store Rx Tp Pdu data*/
    if (PDUR_UNUSED_UINT8 != nextTpBufferId)
    {
        /*don't copy data,just update the available data length and tell Lo Tp Module */
        if (0u == info->SduLength)
        {
            *availableDataPtr =
                (PduR_TpBuffer[tpBufferId].RxBufferOffset + PduR_TpBuffer[nextTpBufferId].RxBufferOffset
                 - PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset);
            bufQeqReturn = BUFREQ_OK;
        }
        /*copy data and tell Lo Tp Module the available data length*/
        else
        {
            /*the active buffer have not copy completely*/
            if ((PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset + info->SduLength)
                <= PduR_TpBuffer[tpBufferId].RxBufferOffset)
            {
                PduR_Memcpy(
                    info->SduDataPtr,
                    &PduR_TpBuffer[tpBufferId]
                         .TpBufferData[PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset],
                    info->SduLength);
                PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset += info->SduLength;
                *availableDataPtr =
                    (PduR_TpBuffer[tpBufferId].RxBufferOffset + PduR_TpBuffer[nextTpBufferId].RxBufferOffset
                     - PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset);
                bufQeqReturn = BUFREQ_OK;
            }
            /*the active buffer have copy completely,and next tp buffer also copy some data*/
            else
            {
                nextTpBufferNeedCopyLength =
                    (PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset + info->SduLength
                     - PduR_TpBuffer[tpBufferId].RxBufferOffset);
                /*don't have enough rx valid data for copy*/
                if (nextTpBufferNeedCopyLength > PduR_TpBuffer[nextTpBufferId].RxBufferOffset)
                {
                    bufQeqReturn = BUFREQ_E_BUSY;
                }
                /*have enough rx valid data for copy*/
                else
                {
                    PduR_Memcpy(
                        info->SduDataPtr,
                        &(PduR_TpBuffer[tpBufferId]
                              .TpBufferData[PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset]),
                        (info->SduLength - nextTpBufferNeedCopyLength));
                    PduR_Memcpy(
                        &(info->SduDataPtr[info->SduLength - nextTpBufferNeedCopyLength]),
                        &(PduR_TpBuffer[nextTpBufferId].TpBufferData[0u]),
                        nextTpBufferNeedCopyLength);
                    PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset = nextTpBufferNeedCopyLength;
                    PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].ActiveTpBufferId = nextTpBufferId;
                    *availableDataPtr = PduR_TpBuffer[nextTpBufferId].RxBufferOffset - nextTpBufferNeedCopyLength;
                    bufQeqReturn = BUFREQ_OK;
                    /*clear the tp buffer which have been copyed all data*/
                    PduR_TpBuffer[tpBufferId].NextTpBufferId = PDUR_UNUSED_UINT8;
                    PduR_TpBuffer[tpBufferId].PduHandleId = PDUR_UNUSED_UINT16;
                    PduR_TpBuffer[tpBufferId].RxBufferOffset = 0u;
                    PduR_TpBuffer[tpBufferId].SduLength = 0u;
                    PduR_TpBuffer[tpBufferId].used = FALSE;
                }
            }
        }
    }
    /*the active tp buffer have stored not full*/
    else
    {
        /*don't copy data,just update the available data length and tell Lo Tp Module */
        if (0u == info->SduLength)
        {
            *availableDataPtr =
                PduR_TpBuffer[tpBufferId].RxBufferOffset - PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset;
            bufQeqReturn = BUFREQ_OK;
        }
        /*copy data and tell Lo Tp Module the available data length*/
        else
        {
            if ((PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset + info->SduLength)
                <= PduR_TpBuffer[tpBufferId].RxBufferOffset)
            {
                PduR_Memcpy(
                    info->SduDataPtr,
                    &(PduR_TpBuffer[tpBufferId]
                          .TpBufferData[PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset]),
                    info->SduLength);
                PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset += info->SduLength;
                *availableDataPtr = PduR_TpBuffer[tpBufferId].RxBufferOffset
                                    - PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset;
                bufQeqReturn = BUFREQ_OK;
            }
            else
            {
                bufQeqReturn = BUFREQ_E_BUSY;
            }
        }
    }
    return bufQeqReturn;
}
#endif /*(STD_ON == PDUR_TP_COPYTXDATA) && (PDUR_TP_BUFFER_SUM > 0u)*/

#if ((STD_ON == PDUR_TP_COPYTXDATA) && (PDUR_TX_BUFFER_SUM > 0u))
/******************************************************************************/
/*
 * Brief               copy the tx data from the tx buffer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DestPduId,info,retry
 * Param-Name[out]     availableDataPtr
 * Param-Name[in/out]  None
 * Return              BufReq_ReturnType
 */
/******************************************************************************/
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CopyTxDataFromTxBuffer(
    PduIdType DestPduId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) info,
    P2CONST(RetryInfoType, AUTOMATIC, PDUR_APPL_DATA) retry,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) availableDataPtr)
/* PRQA S 3432 -- */     /* MISRA Rule 20.7 */
{
    BufReq_ReturnType bufQeqReturn;
    PduIdType gatewayTpRunTimeId;
    uint16 pduRDestTxBuffeId;
    PduLengthType copyOffset;
    PduLengthType pduTotalLength;
    gatewayTpRunTimeId = PDUR_DESTPDU_CFG(DestPduId).GateWayTpRunTimeIndex;
    if ((NULL_PTR != retry) && (TP_DATARETRY == retry->TpDataState))
    {
        if (PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset >= retry->TxTpDataCnt)
        {
            PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset -= retry->TxTpDataCnt;
        }
        /*will not happen general,TP module guarantee*/
        else
        {
            /*re-copy data from 0*/
            PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset = 0u;
        }
    }
    copyOffset = PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset;
    pduRDestTxBuffeId = PDUR_DESTPDU_CFG(DestPduId).PduRDestTxBufferRef;
    pduTotalLength = PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].SduLength;
    if (((copyOffset + info->SduLength) <= pduTotalLength)
        && (TRUE == PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].used))
    {
        PduR_Memcpy(
            info->SduDataPtr,
            &(PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].TxBufferData[copyOffset]),
            info->SduLength);
#if (STD_ON == PDUR_META_DATA_SUPPORT)
        if ((0u < PDUR_DESTPDU_CFG(DestPduId).MetaDataLength) && (NULL_PTR != info->MetaDataPtr))
        {
            PduR_Memcpy(
                info->MetaDataPtr,
                PduR_TxBuffer[pduRDestTxBuffeId].PduRTxBufferRef[0u].MetaData,
                (PduLengthType)PDUR_DESTPDU_CFG(DestPduId).MetaDataLength);
        }
#endif /*STD_ON == PDUR_META_DATA_SUPPORT*/
        *availableDataPtr = (pduTotalLength - copyOffset - info->SduLength);
        PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TxBufferOffset += info->SduLength;
        bufQeqReturn = BUFREQ_OK;
    }
    else
    {
        bufQeqReturn = BUFREQ_E_NOT_OK;
    }
    return bufQeqReturn;
}
#endif /*(STD_ON == PDUR_TP_COPYTXDATA) && (PDUR_TX_BUFFER_SUM > 0u)*/

#if (0u < PDUR_TP_BUFFER_SUM)
/******************************************************************************/
/*
 * Brief               copy the rx pdu data to the tp buffer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TpBufferId,Info
 * Param-Name[out]     BufferSizePtr
 * Param-Name[in/out]  None
 * Return              BufReq_ReturnType
 */
/******************************************************************************/
static FUNC(BufReq_ReturnType, PDUR_CODE) PduR_CopyRxTpDataToTpBuffer(
    uint8 TpBufferId,
    P2CONST(PduInfoType, AUTOMATIC, PDUR_APPL_DATA) Info,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(PduLengthType, AUTOMATIC, PDUR_APPL_DATA) BufferSizePtr)
/* PRQA S 3432 -- */     /* MISRA Rule 20.7 */
{
    BufReq_ReturnType bufQeqReturn;
    PduLengthType rxBufferOffset;
    uint8 nextValidTpBufferId;
    PduLengthType nextTpBufferStoreLength;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
    uint8 metaDataLength;
    metaDataLength = PDUR_SRCEPDU_CFG(PduR_TpBuffer[TpBufferId].PduHandleId).MetaDataLength;
#endif
    rxBufferOffset = PduR_TpBuffer[TpBufferId].RxBufferOffset;
    if ((rxBufferOffset + Info->SduLength) < PduR_TpBuffer[TpBufferId].TpBufferLength)
    {
        PduR_Memcpy(&PduR_TpBuffer[TpBufferId].TpBufferData[rxBufferOffset], Info->SduDataPtr, Info->SduLength);
        PduR_TpBuffer[TpBufferId].RxBufferOffset += Info->SduLength;
        *BufferSizePtr = PduR_TpBuffer[TpBufferId].TpBufferLength - PduR_TpBuffer[TpBufferId].RxBufferOffset;
        bufQeqReturn = BUFREQ_OK;
    }
    /*need another tp buffer to store the pdu(used for gateway-on-the-fly)*/
    else if ((rxBufferOffset + Info->SduLength) == PduR_TpBuffer[TpBufferId].TpBufferLength)
    {
        PduR_Memcpy(&PduR_TpBuffer[TpBufferId].TpBufferData[rxBufferOffset], Info->SduDataPtr, Info->SduLength);
        PduR_TpBuffer[TpBufferId].RxBufferOffset = PduR_TpBuffer[TpBufferId].TpBufferLength;
        /*find one unused tp buffer.if no unused tp buffer,return 0xff*/
        nextValidTpBufferId = PduR_FindNextValidTpBuffer();
        if (PDUR_UNUSED_UINT8 != nextValidTpBufferId)
        {
            PduR_TpBuffer[TpBufferId].NextTpBufferId = nextValidTpBufferId;
            PduR_TpBuffer[nextValidTpBufferId].PduHandleId = PduR_TpBuffer[TpBufferId].PduHandleId;
            PduR_TpBuffer[nextValidTpBufferId].RxBufferOffset = 0u;
            PduR_TpBuffer[nextValidTpBufferId].SduLength = PduR_TpBuffer[TpBufferId].SduLength;
            PduR_TpBuffer[nextValidTpBufferId].used = TRUE;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
            if (0u < metaDataLength)
            {
                PduR_Memcpy(
                    PduR_TpBuffer[nextValidTpBufferId].MetaData,
                    Info->MetaDataPtr,
                    (PduLengthType)metaDataLength);
            }
#endif
            *BufferSizePtr = PduR_TpBuffer[nextValidTpBufferId].TpBufferLength;
        }
        else
        {
            *BufferSizePtr = 0u;
        }
        bufQeqReturn = BUFREQ_OK;
    }
    /*need another tp buffer to store the pdu(used for gateway-on-the-fly)*/
    else
    {
        /*find one unused tp buffer.if no unused tp buffer,return 0xff*/
        nextValidTpBufferId = PduR_FindNextValidTpBuffer();
        if (PDUR_UNUSED_UINT8 != nextValidTpBufferId)
        {
            nextTpBufferStoreLength = (Info->SduLength - (PduR_TpBuffer[TpBufferId].TpBufferLength - rxBufferOffset));
            if (nextTpBufferStoreLength <= PduR_TpBuffer[nextValidTpBufferId].TpBufferLength)
            {
                PduR_Memcpy(
                    &PduR_TpBuffer[TpBufferId].TpBufferData[rxBufferOffset],
                    Info->SduDataPtr,
                    Info->SduLength - nextTpBufferStoreLength);
                PduR_TpBuffer[TpBufferId].RxBufferOffset = PduR_TpBuffer[TpBufferId].TpBufferLength;
                PduR_TpBuffer[TpBufferId].NextTpBufferId = nextValidTpBufferId;
                PduR_Memcpy(
                    &PduR_TpBuffer[nextValidTpBufferId].TpBufferData[0u],
                    &Info->SduDataPtr[Info->SduLength - nextTpBufferStoreLength],
                    nextTpBufferStoreLength);
                PduR_TpBuffer[nextValidTpBufferId].RxBufferOffset = nextTpBufferStoreLength;
                PduR_TpBuffer[nextValidTpBufferId].PduHandleId = PduR_TpBuffer[TpBufferId].PduHandleId;
                PduR_TpBuffer[nextValidTpBufferId].SduLength = PduR_TpBuffer[TpBufferId].SduLength;
                PduR_TpBuffer[nextValidTpBufferId].used = TRUE;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
                if (0u < metaDataLength)
                {
                    PduR_Memcpy(
                        PduR_TpBuffer[nextValidTpBufferId].MetaData,
                        Info->MetaDataPtr,
                        (PduLengthType)metaDataLength);
                }
#endif
                *BufferSizePtr = PduR_TpBuffer[nextValidTpBufferId].TpBufferLength - nextTpBufferStoreLength;
                bufQeqReturn = BUFREQ_OK;
            }
            else
            {
                bufQeqReturn = BUFREQ_E_NOT_OK;
            }
        }
        else
        {
            bufQeqReturn = BUFREQ_E_NOT_OK;
        }
    }
    return bufQeqReturn;
}
#endif /*0u < PDUR_TP_BUFFER_SUM*/

#if (0u < PDUR_TP_BUFFER_SUM)
/******************************************************************************/
/*
 * Brief               find one unused tp buffer.
 *                     if no unused tp buffer,return 0xff.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint8
 */
/******************************************************************************/
static FUNC(uint8, PDUR_CODE) PduR_FindNextValidTpBuffer(void)
{
    uint8 findTpBuffer = PDUR_UNUSED_UINT8;
    uint8 tpBufferIndex;
    for (tpBufferIndex = 0u; (tpBufferIndex < PDUR_TP_BUFFER_SUM) && (PDUR_UNUSED_UINT8 == findTpBuffer);
         tpBufferIndex++)
    {
        if (FALSE == PduR_TpBuffer[tpBufferIndex].used)
        {
            findTpBuffer = tpBufferIndex;
        }
    }
    return findTpBuffer;
}
#endif /*PDUR_TP_BUFFER_SUM*/

#if (0u < PDUR_TP_BUFFER_SUM)
/******************************************************************************/
/*
 * Brief               gateway MF pdu to Tp mode by LoTp_Transmit.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      PduRDestPduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 */
/******************************************************************************/
static FUNC(Std_ReturnType, PDUR_CODE) PduR_GateWayMFToTp(PduIdType PduRDestPduId)
{
    Std_ReturnType loTpTxReturn = E_NOT_OK;
    PduIdType gatewayTpRunTimeId;
    uint8 destModuleIndex;
    PduIdType loPduId;
    uint8 tpBufferId;
    PduInfoType pduRInfo;
    destModuleIndex = PDUR_DESTPDU_CFG(PduRDestPduId).BswModuleIndex;
    loPduId = PDUR_DESTPDU_CFG(PduRDestPduId).PduRDestModulePduIndex;
    gatewayTpRunTimeId = PDUR_DESTPDU_CFG(PduRDestPduId).GateWayTpRunTimeIndex;
    tpBufferId = PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].ActiveTpBufferId;
    if (FALSE == PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TpTxConfirmation)
    {
        if (NULL_PTR != PduR_BswModuleConfigData[destModuleIndex].ModuleTpTransmitApi)
        {
            pduRInfo.SduLength = PduR_TpBuffer[tpBufferId].SduLength;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
            if (PDUR_DESTPDU_CFG(PduRDestPduId).MetaDataLength > 0u)
            {
                pduRInfo.MetaDataPtr = PduR_TpBuffer[tpBufferId].MetaData;
            }
            else
#endif
            {
                pduRInfo.MetaDataPtr = NULL_PTR;
            }
            pduRInfo.SduDataPtr = NULL_PTR;
            loTpTxReturn = PduR_BswModuleConfigData[destModuleIndex].ModuleTpTransmitApi(loPduId, &pduRInfo);
        }
    }
    return loTpTxReturn;
}
#endif /*0u < PDUR_TP_BUFFER_SUM*/

#if ((STD_ON == PDUR_TP_RXINDICATION) && (PDUR_TX_BUFFER_SUM > 0u))
/******************************************************************************/
/*
 * Brief               gateway SF pdu to Tp mode by LoTp_Transmit.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      PduRDestPduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType
 */
/******************************************************************************/
static FUNC(Std_ReturnType, PDUR_CODE) PduR_GateWaySFToTp(PduIdType PduRDestPduId)
{
    Std_ReturnType loTpTxReturn = E_NOT_OK;
    PduIdType gatewayTpRunTimeId;
    uint8 destModuleIndex;
    PduIdType loPduId;
    uint16 txBufferId;
    PduInfoType pduRInfo;
    destModuleIndex = PDUR_DESTPDU_CFG(PduRDestPduId).BswModuleIndex;
    loPduId = PDUR_DESTPDU_CFG(PduRDestPduId).PduRDestModulePduIndex;
    txBufferId = PDUR_DESTPDU_CFG(PduRDestPduId).PduRDestTxBufferRef;
    gatewayTpRunTimeId = PDUR_DESTPDU_CFG(PduRDestPduId).GateWayTpRunTimeIndex;
    if (FALSE == PduR_GateWayDestTpRTSate[gatewayTpRunTimeId].TpTxConfirmation)
    {
        if (NULL_PTR != PduR_BswModuleConfigData[destModuleIndex].ModuleTpTransmitApi)
        {
            pduRInfo.SduLength = PduR_TxBuffer[txBufferId].PduRTxBufferRef[0u].SduLength;
#if (STD_ON == PDUR_META_DATA_SUPPORT)
            if (PDUR_DESTPDU_CFG(PduRDestPduId).MetaDataLength > 0u)
            {
                pduRInfo.MetaDataPtr = PduR_TxBuffer[txBufferId].PduRTxBufferRef[0u].MetaData;
            }
            else
#endif
            {
                pduRInfo.MetaDataPtr = NULL_PTR;
            }
            pduRInfo.SduDataPtr = NULL_PTR;
            loTpTxReturn = PduR_BswModuleConfigData[destModuleIndex].ModuleTpTransmitApi(loPduId, &pduRInfo);
        }
    }
    return loTpTxReturn;
}
#endif /*(STD_ON == PDUR_TP_RXINDICATION) && (PDUR_TX_BUFFER_SUM > 0u)*/

#if (0u < PDUR_TP_BUFFER_SUM)
/******************************************************************************/
/*
 * Brief               find one valid tp buffer.if not find,return 0xff.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      PduRSrcPduId,PduLength
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint8
 */
/******************************************************************************/
static FUNC(uint8, PDUR_CODE) PduR_FindValidTpBuffer(uint16 PduRSrcPduId, PduLengthType PduLength)
{
    uint8 findTpBuffer = PDUR_UNUSED_UINT8;
    uint8 tpBufferIndex;
    boolean rxPduGateWayNow = FALSE;
    for (tpBufferIndex = 0u; (tpBufferIndex < PDUR_TP_BUFFER_SUM) && (FALSE == rxPduGateWayNow); tpBufferIndex++)
    {
        if ((PduR_TpBuffer[tpBufferIndex].PduHandleId == PduRSrcPduId) && (TRUE == PduR_TpBuffer[tpBufferIndex].used))
        {
            rxPduGateWayNow = TRUE;
        }
    }
    if (FALSE == rxPduGateWayNow)
    {
        for (tpBufferIndex = 0u; tpBufferIndex < PDUR_TP_BUFFER_SUM; tpBufferIndex++)
        {
            if ((FALSE == PduR_TpBuffer[tpBufferIndex].used)
                && (PduLength <= PduR_TpBuffer[tpBufferIndex].TpBufferLength))
            {
                if (PDUR_UNUSED_UINT8 == findTpBuffer)
                {
                    findTpBuffer = tpBufferIndex;
                }
                else
                {
                    if (PduR_TpBuffer[findTpBuffer].TpBufferLength > PduR_TpBuffer[tpBufferIndex].TpBufferLength)
                    {
                        findTpBuffer = tpBufferIndex;
                    }
                }
            }
        }
        if ((TRUE == PDUR_ROUTINGPATH_CFG(PduRSrcPduId).GatewayOnTheFly) && (PDUR_UNUSED_UINT8 == findTpBuffer))
        {
            for (tpBufferIndex = 0u; (tpBufferIndex < PDUR_TP_BUFFER_SUM) && (PDUR_UNUSED_UINT8 == findTpBuffer);
                 tpBufferIndex++)
            {
                if ((PDUR_ROUTINGPATH_CFG(PduRSrcPduId).PduRTpMaxThreshold
                     <= PduR_TpBuffer[tpBufferIndex].TpBufferLength)
                    && (FALSE == PduR_TpBuffer[tpBufferIndex].used))
                {
                    findTpBuffer = tpBufferIndex;
                }
            }
        }
    }
    return findTpBuffer;
}
#endif /*0u < PDUR_TP_BUFFER_SUM*/

#if (0u < PDUR_TP_BUFFER_SUM)
/******************************************************************************/
/*
 * Brief               find the rx tp pdu active store tp buffer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      PduRSrcPduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint8
 */
/******************************************************************************/
static FUNC(uint8, PDUR_CODE) PduR_FindTpBuffer(uint16 PduRSrcPduId)
{
    uint8 tpBufferId = PDUR_UNUSED_UINT8;
    uint8 cnt;
    for (cnt = 0u; (cnt < PDUR_TP_BUFFER_SUM) && (PDUR_UNUSED_UINT8 == tpBufferId); cnt++)
    {
        if ((TRUE == PduR_TpBuffer[cnt].used) && (PduRSrcPduId == PduR_TpBuffer[cnt].PduHandleId))
        {
            if (PDUR_UNUSED_UINT8 == PduR_TpBuffer[cnt].NextTpBufferId)
            {
                tpBufferId = cnt;
            }
        }
    }
    return tpBufferId;
}
#endif /*0u < PDUR_TP_BUFFER_SUM*/

#define PDUR_STOP_SEC_CODE
#include "PduR_MemMap.h"
#endif /*(0u < PDUR_DEST_GATEWAY_TP_PDU_SUM)*/

#endif /*STD_OFF == PDUR_ZERO_COST_OPERATION*/
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/
