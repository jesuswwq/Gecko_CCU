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
**  FILENAME    : Com_TxInternal.c                                            **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : internal implementation for COM transmit                    **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Com_Internal.h"
#if (STD_ON == COM_DEV_ERROR_DETECT)
#include "Det.h"
#endif
#if (0u < COM_TXIPDU_NUMBER)
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* called by Com_TxIpduController
 * reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N*/
#if (COM_ONEEVERYNFILTERSIGNAL_NUMBER > 0u)
static FUNC(void, COM_CODE) Com_ResetTxOccurrenceOfPduFilter(PduIdType IpduId);
#endif
/* called by Com_TxIpduController
 * init the tx ipdu buffer,all signal buffer(included in the ipdu) and init the TMC*/
#if (COM_IPDUGROUP_NUMBER > 0u)
static FUNC(void, COM_CODE) Com_ResetTxPduBufferAndSignalBuffer(PduIdType IpduId);
#endif
/* called by Com_TxSignalGroupPack.
 * pack tx group signal(not dynamic)*/
#if (COM_TXSIGNALGROUP_NUMBER > 0u)
static FUNC(void, COM_CODE) Com_TxGroupSignalPack(Com_SignalIdType GroupSignalId);
#endif /* COM_TXSIGNALGROUP_NUMBER > 0u */
/* called by Com_UpdateTxBufferAndCalculateTMCOfEveryGroupSignal.
 * unpack the tx array group signal*/
#if ((STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (COM_TXSIGNALGROUP_NUMBER > 0u))
static FUNC(uint64, COM_CODE) Com_UnPackTxArrayGroupSignalValue(Com_SignalIdType SignalId, uint16 IpduBufferId);
#endif
/* called by Com_UpdateTxBufferAndCalculateTMCOfEveryGroupSignal.
 * the group signal value changed,judge it will trigger the TxPdu transmit(DIRECT/MIXED mode) or not. */
#if ((STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (COM_TXSIGNALGROUP_NUMBER > 0u))
static FUNC(void, COM_CODE)
    Com_TxArrayGroupSignalTriggerOnChange(Com_SignalIdType GroupSignalId, boolean* TriggerOnChange);
#endif
/* called by Com_TxSignalTMHandle,Com_SendTxGroupSignalHandle,Com_UpdateTxBufferAndCalculateTMCOfEveryGroupSignal.
 * calculate the new TMC of the signal new value*/
#if ((0u < COM_TMCTXSIGNAL_NUMBER) || (0u < COM_TMCTXGROUPSIGNAL_NUMBER)) && (STD_ON == COM_TMS_ENABLE)
static FUNC(boolean, COM_CODE) Com_TxSignalTMCCalculate(
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalValuePtr,
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
    Com_SignalType SignalType,
    uint16 SignalBufferId);
#endif /* ((0u < COM_TMCTXSIGNAL_NUMBER) || (0u < COM_TMCTXGROUPSIGNAL_NUMBER)) && (STD_ON == COM_TMS_ENABLE) */
/* called by Com_TxSignalTMCCalculate.
 * change the signal value to uint64 type*/
#if ((0u < COM_TMCTXSIGNAL_NUMBER) || (0u < COM_TMCTXGROUPSIGNAL_NUMBER)) && (STD_ON == COM_TMS_ENABLE)
static FUNC(uint64, COM_CODE)
    Com_GetTxSignalValue(Com_SignalType SignalType, P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalValuePtr);
#endif /* #if ((0u < COM_TMCTXSIGNAL_NUMBER) || (0u < COM_TMCTXGROUPSIGNAL_NUMBER)) && (STD_ON == COM_TMS_ENABLE) */
/* called by Com_UpdateTxBufferAndCalculateTMCOfEveryGroupSignal.
 * update the uint8_n signal value*/
#if ((STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (COM_TXSIGNALGROUP_NUMBER > 0u))
#if ((0u < COM_TXIPDUBUFF_SIZE) && (0u < COM_SIGNAL_8BITBUFF_SIZE))
static FUNC(boolean, COM_CODE)
    Com_TxGroupSignalUpdateUint8N(uint16 TxIPduBufferId, Com_SignalIdType groupSignalId, uint16 groupSignalInitValueId);
#endif
#endif
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/******************************************************************************/
/*
 * Brief               Called by Com_IpduGroupControl.
 *                     used to handle Tx Ipdu state change or not.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxPduId,initialize
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (COM_IPDUGROUP_NUMBER > 0u)
FUNC(void, COM_CODE)
Com_TxIpduController(PduIdType TxPduId, boolean initialize) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Com_IpduGroupIdType ipduGroupRefNumber;
    Com_IpduGroupIdType ipduGroupRefIndex;
    Com_IpduGroupIdType ipduGroupId;
    boolean findActiveIpduGroup = FALSE;
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[TxPduId];
    ipduGroupRefNumber = txIpduPtr->ComIPduGroupsRefNumber;
    /*if the Pdu not included in any Ipdu Group,the state is always start*/
    if (ipduGroupRefNumber > 0u)
    {
        for (ipduGroupRefIndex = 0u; (ipduGroupRefIndex < ipduGroupRefNumber) && (FALSE == findActiveIpduGroup);
             ipduGroupRefIndex++)
        {
            ipduGroupId = txIpduPtr->ComIPduGroupsRef[ipduGroupRefIndex];
            if (TRUE == Com_IpduGroupEnable[ipduGroupId])
            {
                findActiveIpduGroup = TRUE;
            }
        }
        /*at least one Ipdu Group is start,the Pdu shall be active*/
        if (TRUE == findActiveIpduGroup)
        {
            /*the pdu restart*/
            if (FALSE == Com_TxIPduRunTimeState[TxPduId].ActiveEnable)
            {
                Com_TxIPduRunTimeState[TxPduId].ActiveEnable = TRUE;
                /*reset ComMinimumDelayTime of I-PDUs in transmission*/
                Com_TxIPduRunTimeState[TxPduId].MDTCnt = 0u;
                /*reset Tx time out counter*/
                if ((NULL_PTR == txIpduPtr->ComTxModeFalse)
                    && (COM_TX_MODE_NONE == txIpduPtr->ComTxModeTrue->ComTxModeMode))
                {
                    Com_TxIPduRunTimeState[TxPduId].DMCnt = txIpduPtr->ComTxIpduDM;
                }
                else
                {
                    Com_TxIPduRunTimeState[TxPduId].DMCnt = 0u;
                }
                /*clear all signal/signal group/dest description signal's update bit of the tx Ipdu*/
#if (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) \
    || (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
                Com_ClearTxIPduUpdates(TxPduId);
#endif /* (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) || (STD_ON == \
          COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)*/
/*reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N*/
#if (COM_ONEEVERYNFILTERSIGNAL_NUMBER > 0u)
                Com_ResetTxOccurrenceOfPduFilter(TxPduId);
#endif
                if (TRUE == initialize)
                {
                    /*init the tx ipdu buffer,,all signal buffer(included in the ipdu) and init the TMC,TMS*/
                    Com_ResetTxPduBufferAndSignalBuffer(TxPduId);
                    /*reset the Tx Time Period of I-PDUs in Periodic or MIXED transmission mode*/
                    if (TRUE == Com_TxIPduRunTimeState[TxPduId].TMS)
                    {
                        Com_TxIPduRunTimeState[TxPduId].PeriodCnt = txIpduPtr->ComTxModeTrue->ComTxModeTimeOffset;
                    }
                    else
                    {
                        Com_TxIPduRunTimeState[TxPduId].PeriodCnt = txIpduPtr->ComTxModeFalse->ComTxModeTimeOffset;
                    }
                    if (NULL_PTR != txIpduPtr->ComIPduCounter)
                    {
                        /*set the I-PDU counter to 0 for I-PDUs with ComIPduDirection configured to SEND*/
                        Com_TxIPduRunTimeState[TxPduId].TxIpduCounter = 0u;
                    }
                }
            }
        }
        else
        {
            if (TRUE == Com_TxIPduRunTimeState[TxPduId].ActiveEnable)
            {
                Com_TxIPduRunTimeState[TxPduId].ActiveEnable = FALSE;
                if (TRUE == Com_TxIPduRunTimeState[TxPduId].Transmiting)
                {
#if (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE)
                    Com_InvokeErrorNotification(TxPduId);
#endif /* (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) || (STD_ON == \
          COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE) */
#if (STD_ON == COM_CANCELLATION_SUPPORT)
                    if (TRUE == txIpduPtr->ComIPduCancellationSupport)
                    {
                        (void)PduR_ComCancelTransmit(txIpduPtr->ComPduIdRef);
                    }
#endif
                    Com_TxIPduRunTimeState[TxPduId].Transmiting = FALSE;
                }
                Com_TxIPduRunTimeState[TxPduId].DMCnt = 0u;
            }
        }
    }
}
#endif /*COM_IPDUGROUP_NUMBER > 0u*/
/******************************************************************************/
/*
 * Brief               Called by Com_SendSignal.
 *                     the tx signal value change,calculate the new TMC and TMS.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxSignalId,TxPduId,TxSignalDataPtr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (0u < COM_TXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
FUNC(void, COM_CODE)
Com_TxSignalTMHandle(
    /* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
    Com_SignalIdType TxSignalId,
    PduIdType TxPduId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) TxSignalDataPtr)
{
    boolean oldTMS;
#if (0u < COM_TMCTXSIGNAL_NUMBER)
    Com_SignalIdType txSignalTMCId;
    const Com_TxSignalType* txSignalPtr = &Com_ConfigStd->ComTxSignal[TxSignalId];
    if (NULL_PTR != txSignalPtr->ComFilter)
    {
        txSignalTMCId = txSignalPtr->ComFilter->ComTMCBufferId;
        /*calculate the TMC of the signal*/
        TxSignalTMCRunTime[txSignalTMCId] = Com_TxSignalTMCCalculate(
            TxSignalDataPtr,
            txSignalPtr->ComFilter,
            txSignalPtr->ComSignalType,
            txSignalPtr->ComSignalInitValueId);
    }
#endif
    oldTMS = Com_TxIPduRunTimeState[TxPduId].TMS;
    Com_TxIPduRunTimeState[TxPduId].TMS = Com_TxIpduTMSCalculate(TxPduId);
    if (TRUE == Com_TxIPduRunTimeState[TxPduId].TMS)
    {
        const Com_TxModeType* txModeTruePtr = Com_ConfigStd->ComTxIPdu[TxPduId].ComTxModeTrue;
        Com_TxIPduRunTimeState[TxPduId].ipduTxMode = txModeTruePtr->ComTxModeMode;
        /*TMS changed,reset PeriodCnt for PERIODIC/MIXED Tx Mode*/
        if (FALSE == oldTMS)
        {
            Com_TxIPduRunTimeState[TxPduId].PeriodCnt = txModeTruePtr->ComTxModeTimeOffset;
        }
    }
#if (STD_ON == COM_TMS_ENABLE)
    else
    {
        const Com_TxModeType* txModeFalsePtr = Com_ConfigStd->ComTxIPdu[TxPduId].ComTxModeFalse;
        Com_TxIPduRunTimeState[TxPduId].ipduTxMode = txModeFalsePtr->ComTxModeMode;
        /*TMS changed,reset PeriodCnt for PERIODIC/MIXED Tx Mode*/
        if (TRUE == oldTMS)
        {
            Com_TxIPduRunTimeState[TxPduId].PeriodCnt = txModeFalsePtr->ComTxModeTimeOffset;
        }
    }
#endif /* (STD_ON == COM_TMS_ENABLE) */
    COM_NOUSED(TxSignalId);
    COM_NOUSED(TxSignalDataPtr);
    return;
}
#endif /*0u < COM_TXSIGNAL_NUMBER*/
/******************************************************************************/
/*
 * Brief               Called by Com_SendSignal,Com_SendTxGroupSignalHandle.
 *                     set Tx signal(not dynamic signal) to signalbuffer,return
 *                     the buffer value is changed or not.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalType,SignalLength,SignalBufferId,SignalNewDataPtr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/******************************************************************************/
#if ((COM_TXSIGNALGROUP_NUMBER > 0u) || (0u < COM_TXSIGNAL_NUMBER))
FUNC(boolean, COM_CODE)
Com_SetTxSignalBuff(
    Com_SignalType SignalType,
    uint16 SignalLength,
    uint16 SignalBufferId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalNewDataPtr)
{
    boolean ret = FALSE;
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    uint16 valueLoop;
#endif
    switch (SignalType)
    {
#if (0u < COM_SIGNAL_BOOLBUFF_SIZE)
    case COM_BOOLEAN:
        if (*((const boolean*)(SignalNewDataPtr)) != Com_SignalBoolRuntimeBuff[SignalBufferId])
        {
            Com_SignalBoolRuntimeBuff[SignalBufferId] = *((const boolean*)(SignalNewDataPtr));
            ret = TRUE;
        }
        break;
#endif
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    case COM_UINT8:
    case COM_SINT8:
        if (*((const uint8*)(SignalNewDataPtr)) != Com_Signal8BitRuntimeBuff[SignalBufferId])
        {
            Com_Signal8BitRuntimeBuff[SignalBufferId] = *((const uint8*)(SignalNewDataPtr));
            ret = TRUE;
        }
        break;
    case COM_UINT8_N:
        /* Copy Uint8N signal value one byte by one */
        for (valueLoop = 0u; valueLoop < SignalLength; valueLoop++)
        {
            if (((const uint8*)SignalNewDataPtr)[valueLoop] != Com_Signal8BitRuntimeBuff[SignalBufferId + valueLoop])
            {
                Com_Signal8BitRuntimeBuff[SignalBufferId + valueLoop] = ((const uint8*)SignalNewDataPtr)[valueLoop];
                ret = TRUE;
            }
        }
        break;
#endif
#if (0u < COM_SIGNAL_16BITBUFF_SIZE)
    case COM_UINT16:
    case COM_SINT16:
        if (*((const uint16*)(SignalNewDataPtr)) != Com_Signal16BitRuntimeBuff[SignalBufferId])
        {
            Com_Signal16BitRuntimeBuff[SignalBufferId] = *((const uint16*)(SignalNewDataPtr));
            ret = TRUE;
        }
        break;
#endif
#if (0u < COM_SIGNAL_32BITBUFF_SIZE)
    case COM_SINT32:
    case COM_UINT32:
    case COM_FLOAT32:
        if (*((const uint32*)(SignalNewDataPtr)) != Com_Signal32BitRuntimeBuff[SignalBufferId])
        {
            Com_Signal32BitRuntimeBuff[SignalBufferId] = *((const uint32*)(SignalNewDataPtr));
            ret = TRUE;
        }
        break;
#endif
#if (0u < COM_SIGNAL_64BITBUFF_SIZE)
    case COM_SINT64:
    case COM_UINT64:
    case COM_FLOAT64:
        if (*((const uint64*)(SignalNewDataPtr)) != Com_Signal64BitRuntimeBuff[SignalBufferId])
        {
            Com_Signal64BitRuntimeBuff[SignalBufferId] = *((const uint64*)(SignalNewDataPtr));
            ret = TRUE;
        }
        break;
#endif
    default:
        /*do nothing*/
        break;
    }
    return ret;
}
#endif /*(COM_TXSIGNALGROUP_NUMBER > 0u) || (0u < COM_TXSIGNAL_NUMBER)*/
/******************************************************************************/
/*
 * Brief               Called by Com_SendSignal.
 *                     pack the Tx signal into ipdu Tx buffer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxSignalId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (0u < COM_TXSIGNAL_NUMBER)
FUNC(void, COM_CODE)
Com_TxSignalPack(Com_SignalIdType TxSignalId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    const Com_TxSignalType* txSignalPtr = &Com_ConfigStd->ComTxSignal[TxSignalId];
    PduIdType txIpduId = txSignalPtr->ComIpduRefIndex;
    uint32 bitPosition = txSignalPtr->ComBitPosition;
    Com_SignalType signalType = txSignalPtr->ComSignalType;
    uint16 ipduBufferIndex = Com_ConfigStd->ComTxIPdu[txIpduId].ComTxIPduBufIndex;
    uint16 signalBufferId = txSignalPtr->ComSignalInitValueId;
    uint16 ipduBuffPos = ipduBufferIndex + (uint16)(bitPosition >> 3u);
#if ((0u < COM_SIGNAL_BOOLBUFF_SIZE) && (0u < COM_TXIPDUBUFF_SIZE))
    uint8 value = 0x01u;
#endif
#if ((0u < COM_SIGNAL_8BITBUFF_SIZE) && (0u < COM_TXIPDUBUFF_SIZE))
    uint16 signalLength;
    uint16 cnt;
#endif
    uint64 txData = 0u;
    uint8 signalByteLength;
    uint64 dataMSBByte;
    uint8 bitSize;
    Com_TxSignalPackType parameter;
    uint8 bitPosInByte = (uint8)(bitPosition & 0x07u);

    /*pack boolean type signal*/
    if (COM_BOOLEAN == signalType)
    {
#if ((0u < COM_SIGNAL_BOOLBUFF_SIZE) && (0u < COM_TXIPDUBUFF_SIZE))
        if (TRUE == Com_SignalBoolRuntimeBuff[signalBufferId])
        {
            Com_TxIPduRuntimeBuff[ipduBuffPos] |= (uint8)(value << bitPosInByte);
        }
        else
        {
            Com_TxIPduRuntimeBuff[ipduBuffPos] &= (uint8)(~(uint8)(value << bitPosInByte));
        }
#endif
    }
    /*pack COM_UINT8_N type signal*/
    else if (COM_UINT8_N == signalType)
    {
#if ((0u < COM_SIGNAL_8BITBUFF_SIZE) && (0u < COM_TXIPDUBUFF_SIZE))
        signalLength = txSignalPtr->ComSignalLength;
        for (cnt = 0u; cnt < signalLength; cnt++)
        {
            Com_TxIPduRuntimeBuff[ipduBuffPos + cnt] = Com_Signal8BitRuntimeBuff[signalBufferId + cnt];
        }
#endif
    }
    /*pack signal expect signal type(boolean,COM_UINT8_N,COM_UINT8_DYN)*/
    else
    {
        /*get the signal value need to be packed*/
        switch (signalType)
        {
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
        case COM_UINT8:
        case COM_SINT8:
            txData = (uint64)(Com_Signal8BitRuntimeBuff[signalBufferId]);
            break;
#endif
#if (0u < COM_SIGNAL_16BITBUFF_SIZE)
        case COM_UINT16:
        case COM_SINT16:
            txData = (uint64)(Com_Signal16BitRuntimeBuff[signalBufferId]);
            break;
#endif
#if (0u < COM_SIGNAL_32BITBUFF_SIZE)
        case COM_SINT32:
        case COM_UINT32:
        case COM_FLOAT32:
            txData = (uint64)(Com_Signal32BitRuntimeBuff[signalBufferId]);
            break;
#endif
#if (0u < COM_SIGNAL_64BITBUFF_SIZE)
        case COM_SINT64:
        case COM_UINT64:
        case COM_FLOAT64:
            txData = Com_Signal64BitRuntimeBuff[signalBufferId];
            break;
#endif
        default:
            /*do nothing*/
            break;
        }
        /* signal MSB byte value used for the signal value bits cover 9 bytes */
        dataMSBByte = txData;
        /* Align LSB of txData and signal_value in IPdu */
        txData = txData << bitPosInByte;
        bitSize = txSignalPtr->ComBitSize;
        /*signalByteLength:1-9*/
        signalByteLength = txSignalPtr->ComSignalByteLength;
        /*the tx signal all value bits are in one byte*/
        if (1u == signalByteLength)
        {
#if (0u < COM_TXIPDUBUFF_SIZE)
            /*Clear corresponding bits in IPdu*/
            Com_TxIPduRuntimeBuff[ipduBuffPos] &=
                (0xFFu >> (8u - bitPosInByte)) | (uint8)(0xFFu << (bitPosInByte + bitSize));
            /*write corresponding bits to IPdu buffer*/
            Com_TxIPduRuntimeBuff[ipduBuffPos] |= (0xFFu >> (8u - (bitPosInByte + bitSize))) & ((uint8)txData);
#endif
        }
        /*the tx signal all value bits are included in 2-9 byte*/
        else if ((1u < signalByteLength) && (signalByteLength < 10u))
        {
            parameter.SignalByteLength = signalByteLength;
            parameter.SignalEndianness = txSignalPtr->ComSignalEndianness;
            parameter.IpduBufferIndex = ipduBufferIndex;
            parameter.BitPosition = bitPosition;
            parameter.BitSize = bitSize;
            Com_TxSignalPackHandle(&parameter, txData, dataMSBByte);
        }
        /*this case will not happen*/
        else
        {
            /*do nothing*/
        }
    }
    return;
}
#endif /*0u < COM_TXSIGNAL_NUMBER*/
/******************************************************************************/
/*
 * Brief               Called by Com_SendSignal,Com_SendDynSignal.
 *                     send Tx signal handle.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxIpduId,SignalTxProperty,DMSignal,ValueChanged
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint8
 */
/******************************************************************************/
#if (0u < COM_TXSIGNAL_NUMBER)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
FUNC(uint8, COM_CODE)
Com_SendTxSignalHandle(
    /* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
    PduIdType TxIpduId,
    Com_TransferPropertyType SignalTxProperty,
    boolean DMSignal,
    boolean ValueChanged)
{
    uint16 rptNum;
    boolean initDMCnt = FALSE;
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[TxIpduId];
    uint16 txIpduDM = txIpduPtr->ComTxIpduDM;
    Com_TxIPduRunTimeStateType* txIpduStatePtr = &Com_TxIPduRunTimeState[TxIpduId];
    /*the signal config timeout,the DM timer isn't start by other signals,the Tx mode is not NONE.then start the DM
     * timer here*/
    if ((0u == txIpduStatePtr->DMCnt) && (TRUE == DMSignal) && (COM_TX_MODE_NONE != txIpduStatePtr->ipduTxMode))
    {
        txIpduStatePtr->DMCnt = txIpduDM;
        initDMCnt = TRUE;
    }
#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) || (STD_ON == COM_TX_MODE_MIXED_ENABLE)
    if ((COM_TX_MODE_DIRECT == txIpduStatePtr->ipduTxMode) || (COM_TX_MODE_MIXED == txIpduStatePtr->ipduTxMode))
    {
#if (STD_ON == COM_TMS_ENABLE)
        if (TRUE == txIpduStatePtr->TMS)
#endif /* #if (STD_ON == COM_TMS_ENABLE) */
        {
            rptNum = txIpduPtr->ComTxModeTrue->ComTxModeNumberOfRepetitions;
        }
#if (STD_ON == COM_TMS_ENABLE)
        else
        {
            rptNum = txIpduPtr->ComTxModeFalse->ComTxModeNumberOfRepetitions;
        }
#endif /* #if (STD_ON == COM_TMS_ENABLE) */
        switch (SignalTxProperty)
        {
#if (STD_ON == COM_TX_SIG_PROP_TRIGGERED_ENABLE)
        case COM_TRIGGERED:
            txIpduStatePtr->NTimeCnt = 0u;
            txIpduStatePtr->RptNum = rptNum;
            /*For an I-PDU with ComTxModeMode DIRECT and ComTxModeNumberOfRepetitions > 0, the AUTOSAR COM module shall
              reset an already running transmission deadline monitoring timer in case another send request for this
              I-PDU is initiated*/
            if ((1u < rptNum) && (FALSE == initDMCnt) && (TRUE == DMSignal))
            {
                txIpduStatePtr->DMCnt = txIpduDM;
            }
            break;
#endif /* #if (STD_ON == COM_TX_SIG_PROP_TRIGGERED_ENABLE) */
#if (STD_ON == COM_TX_SIG_PROP_TRIGGERED_ON_CHANGE_ENABLE)
        case COM_TRIGGERED_ON_CHANGE:
            if (TRUE == ValueChanged)
            {
                txIpduStatePtr->NTimeCnt = 0u;
                txIpduStatePtr->RptNum = rptNum;
                /*For an I-PDU with ComTxModeMode DIRECT and ComTxModeNumberOfRepetitions > 0, the AUTOSAR COM module
                  shall reset an already running transmission deadline monitoring timer in case another send request for
                  this I-PDU is initiated*/
                if ((1u < rptNum) && (FALSE == initDMCnt) && (TRUE == DMSignal))
                {
                    txIpduStatePtr->DMCnt = txIpduDM;
                }
            }
            break;
#endif /* #if (STD_ON == COM_TX_SIG_PROP_TRIGGERED_ON_CHANGE_ENABLE) */
#if (STD_ON == COM_TX_SIG_PROP_TRIG_ON_CH_NO_REPETITION_ENABLE)
        case COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
            if (TRUE == ValueChanged)
            {
                txIpduStatePtr->NTimeCnt = 0u;
                txIpduStatePtr->RptNum = 1u;
            }
            break;
#endif /* #if (STD_ON == COM_TX_SIG_PROP_TRIG_ON_CH_NO_REPETITION_ENABLE) */
#if (STD_ON == COM_TX_SIG_PROP_TRIG_NO_REPETITION_ENABLE)
        case COM_TRIGGERED_WITHOUT_REPETITION:
            txIpduStatePtr->NTimeCnt = 0u;
            txIpduStatePtr->RptNum = 1u;
            break;
#endif /* #if (STD_ON == COM_TX_SIG_PROP_TRIG_NO_REPETITION_ENABLE) */
        default:
            /*do nothing*/
            break;
        }
    }
    else
#endif /* #if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) || (STD_ON == COM_TX_MODE_MIXED_ENABLE) */
    {
        txIpduStatePtr->NTimeCnt = 0u;
        txIpduStatePtr->RptNum = 0u;
    }
    return E_OK;
}
#endif /*0u < COM_TXSIGNAL_NUMBER*/
/******************************************************************************/
/*
 * Brief               Called by Com_SendSignal,Com_InvalidateSignalGroup.
 *                     send Tx group signal handle.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxGroupSignalId,SignalDataPtr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK,COM_SERVICE_NOT_AVAILABLE
 */
/******************************************************************************/
#if (COM_TXSIGNALGROUP_NUMBER > 0u)
FUNC(uint8, COM_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Com_SendTxGroupSignalHandle(Com_SignalIdType TxGroupSignalId, P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    uint8 ret;
    Com_SignalGroupIdType signalGroupId;
#if (0u < COM_TMCTXGROUPSIGNAL_NUMBER)
    Com_SignalIdType txSignalTMCId;
#endif
    boolean valueChanged;
    Com_SignalType groupSignalType;
    uint16 groupSignalLength;
    uint16 groupSignalBufferId;
    const Com_TxGroupSignalType* txGroupSignalPtr = &Com_ConfigStd->ComTxGroupSignal[TxGroupSignalId];
    signalGroupId = txGroupSignalPtr->ComSignalGroupRef;
    const Com_TxSignalGroupType* txSignalGroupPtr = &Com_ConfigStd->ComTxSignalGroup[signalGroupId];
    groupSignalType = txGroupSignalPtr->ComSignalType;
/*dynamic signal isn't send by the API,InitialValueOnly signal group don't expect to be called by any API*/
#if (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_INITIAL_VALUE_ONLY_ENABLE)
    if ((COM_UINT8_DYN == groupSignalType) || (TRUE == txSignalGroupPtr->ComInitialValueOnly))
    {
        ret = COM_SERVICE_NOT_AVAILABLE;
    }
    else
#endif /* #if (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == \
          COM_TX_SIG_GROUP_INITIAL_VALUE_ONLY_ENABLE) */
    {
        groupSignalBufferId = txGroupSignalPtr->ComSignalInitValueId;
#if (0u < COM_TMCTXGROUPSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE)
        if (NULL_PTR != txGroupSignalPtr->ComFilter)
        {
            txSignalTMCId = txGroupSignalPtr->ComFilter->ComTMCBufferId;
            /*calculate the TMC of the signal*/
            TxGroupSignalTMCBuffer[txSignalTMCId] = Com_TxSignalTMCCalculate(
                SignalDataPtr,
                txGroupSignalPtr->ComFilter,
                groupSignalType,
                groupSignalBufferId);
        }
#endif /* #if (0u < COM_TMCTXGROUPSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE) */
        /*groupSignalLength is used when the signal type is COM_UINT8_N*/
        groupSignalLength = txGroupSignalPtr->ComSignalLength;
        /*update tx signal buffer and check if the sending signal value changed*/
        valueChanged = Com_SetTxSignalBuff(groupSignalType, groupSignalLength, groupSignalBufferId, SignalDataPtr);
        switch (txSignalGroupPtr->ComTransferProperty)
        {
#if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIGGERED_ENABLE)
        case COM_TRIGGERED:
            Com_TxSignalGroupState[signalGroupId].NTimesTransmitNeed = TRUE;
            Com_TxSignalGroupState[signalGroupId].WithoutRepetition = FALSE;
            break;
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIGGERED_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIGGERED_ON_CHANGE_ENABLE)
        case COM_TRIGGERED_ON_CHANGE:
            if (TRUE == txGroupSignalPtr->ComTxGroupSignalUsedTransferProperty)
            {
                if ((TRUE == valueChanged) && (COM_TRIGGERED_ON_CHANGE == txGroupSignalPtr->ComTransferProperty))
                {
                    Com_TxSignalGroupState[signalGroupId].NTimesTransmitNeed = TRUE;
                    Com_TxSignalGroupState[signalGroupId].WithoutRepetition = FALSE;
                }
            }
            else
            {
                if (TRUE == valueChanged)
                {
                    Com_TxSignalGroupState[signalGroupId].NTimesTransmitNeed = TRUE;
                    Com_TxSignalGroupState[signalGroupId].WithoutRepetition = FALSE;
                }
            }
            break;
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIGGERED_ON_CHANGE_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIG_ON_CH_NO_REPETITION_ENABLE)
        case COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
            if (TRUE == valueChanged)
            {
                Com_TxSignalGroupState[signalGroupId].NTimesTransmitNeed = TRUE;
                Com_TxSignalGroupState[signalGroupId].WithoutRepetition = TRUE;
            }
            break;
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIG_ON_CH_NO_REPETITION_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIG_NO_REPETITION_ENABLE)
        case COM_TRIGGERED_WITHOUT_REPETITION:
            Com_TxSignalGroupState[signalGroupId].NTimesTransmitNeed = TRUE;
            Com_TxSignalGroupState[signalGroupId].WithoutRepetition = TRUE;
            break;
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIG_NO_REPETITION_ENABLE) */
        default:
            /*do nothing*/
            break;
        }
        ret = E_OK;
    }
    return ret;
}
#endif
/******************************************************************************/
/*
 * Brief               Called by Com_SendDynSignal.
 *                     set Tx dynamic signal to signalbuffer,return the buffer
 *                     value is changed or not.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxPduId,SignalBufferId,SignalNewDataPtr,Length
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/******************************************************************************/
#if ((0u < COM_TXSIGNALGROUP_NUMBER) || (0u < COM_TXSIGNAL_NUMBER)) \
    && ((STD_ON == COM_TX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE))
FUNC(boolean, COM_CODE)
Com_SetDynTxSignalBuff(
    PduIdType TxPduId,
    uint16 SignalBufferId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalNewDataPtr,
    uint16 Length)
{
    boolean ret = FALSE;
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    uint16 valueLoop;
#endif
    uint16 oldSignalLength;
/* Copy Uint8N signal value one byte by one */
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    for (valueLoop = 0u; valueLoop < Length; valueLoop++)
    {
        if (((const uint8*)SignalNewDataPtr)[valueLoop] != Com_Signal8BitRuntimeBuff[SignalBufferId + valueLoop])
        {
            Com_Signal8BitRuntimeBuff[SignalBufferId + valueLoop] = ((const uint8*)SignalNewDataPtr)[valueLoop];
            ret = TRUE;
        }
    }
#endif
    if (FALSE == ret)
    {
        oldSignalLength = Com_TxIPduRunTimeState[TxPduId].TxIpduLength
                          - (uint16)Com_ConfigStd->ComTxIPdu[TxPduId].IPduNoDynSignalLength;
        if (oldSignalLength != Length)
        {
            ret = TRUE;
        }
    }
    return ret;
}
#endif /* #if ((0u < COM_TXSIGNALGROUP_NUMBER) || (0u < COM_TXSIGNAL_NUMBER)) && ((STD_ON == \
          COM_TX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)) */
/******************************************************************************/
/*
 * Brief               Called by Com_SendDynSignal,Com_TxSignalGroupPack.
 *                     dynamic signal pack to tx pdu buffer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxPduId,BitPosition,SignalBufferId,Length
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((0u < COM_TXSIGNALGROUP_NUMBER) || (0u < COM_TXSIGNAL_NUMBER)) \
    && ((STD_ON == COM_TX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE))
FUNC(void, COM_CODE)
Com_TxDynSignalPack(PduIdType TxPduId, uint32 BitPosition, uint16 SignalBufferId, uint16 Length)
{
#if ((0u < COM_TXIPDUBUFF_SIZE) && (0u < COM_SIGNAL_8BITBUFF_SIZE))
    uint16 ipduBufferIndex;
    uint16 cnt;
    ipduBufferIndex = Com_ConfigStd->ComTxIPdu[TxPduId].ComTxIPduBufIndex + (uint16)(BitPosition >> 3u);

    for (cnt = 0u; cnt < Length; cnt++)
    {
        Com_TxIPduRuntimeBuff[ipduBufferIndex + cnt] = Com_Signal8BitRuntimeBuff[SignalBufferId + cnt];
    }
#endif
    return;
}
#endif /* #if ((0u < COM_TXSIGNALGROUP_NUMBER) || (0u < COM_TXSIGNAL_NUMBER)) && ((STD_ON == \
          COM_TX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)) */
/******************************************************************************/
/*
 * Brief               Called by Com_SendDynSignal,Com_InvalidateSignalGroup.
 *                     send dynamic Tx group signal handle.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxGroupSignalId,SignalDataPtr,DynLength
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK,COM_SERVICE_NOT_AVAILABLE
 */
/******************************************************************************/
#if (COM_TXSIGNALGROUP_NUMBER > 0u) && (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
FUNC(uint8, COM_CODE)
Com_SendTxDynGroupSignalHandle(
    /* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
    Com_SignalIdType TxGroupSignalId,
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalDataPtr,
    uint16 DynLength)
{
    uint8 ret;
    Com_SignalGroupIdType signalGroupId;
    PduIdType ipduRef;
    Com_TransferPropertyType groupSignalTxProperty;
    boolean valueChanged;
    uint16 groupSignalBufferId;
    const Com_TxGroupSignalType* txGroupSignalPtr = &Com_ConfigStd->ComTxGroupSignal[TxGroupSignalId];
    signalGroupId = txGroupSignalPtr->ComSignalGroupRef;
    const Com_TxSignalGroupType* txSignalGroup = &Com_ConfigStd->ComTxSignalGroup[signalGroupId];
    /*group signal(not dynamic) isn't send by the API,InitialValueOnly signal group don't expect to be called by any
     * API*/
    if ((COM_UINT8_DYN != txGroupSignalPtr->ComSignalType) || (TRUE == txSignalGroup->ComInitialValueOnly))
    {
        ret = COM_SERVICE_NOT_AVAILABLE;
    }
    else
    {
        if (DynLength > txGroupSignalPtr->ComSignalLength)
        {
#if (STD_ON == COM_DEV_ERROR_DETECT)
            (void)Det_ReportError(COM_MODULE_ID, COM_INSTANCE_ID, COM_SENDDYNSIGNAL_ID, COM_E_PARAM);
#endif
            ret = E_NOT_OK;
        }
        else
        {
            ipduRef = txSignalGroup->ComIpduRefIndex;
            groupSignalBufferId = txGroupSignalPtr->ComSignalInitValueId;
            /*update Dynamic tx group signal buffer and check if the sending signal value changed*/
            valueChanged = Com_SetDynTxSignalBuff(ipduRef, groupSignalBufferId, SignalDataPtr, DynLength);
            Com_TxSignalGroupState[signalGroupId].DynamicSignalLength = DynLength;
            switch (txSignalGroup->ComTransferProperty)
            {
#if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIGGERED_ENABLE)
            case COM_TRIGGERED:
                Com_TxSignalGroupState[signalGroupId].NTimesTransmitNeed = TRUE;
                Com_TxSignalGroupState[signalGroupId].WithoutRepetition = FALSE;
                break;
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIGGERED_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIGGERED_ON_CHANGE_ENABLE)
            case COM_TRIGGERED_ON_CHANGE:
                if (TRUE == txGroupSignalPtr->ComTxGroupSignalUsedTransferProperty)
                {
                    groupSignalTxProperty = txGroupSignalPtr->ComTransferProperty;
                    if ((TRUE == valueChanged) && (COM_TRIGGERED_ON_CHANGE == groupSignalTxProperty))
                    {
                        Com_TxSignalGroupState[signalGroupId].NTimesTransmitNeed = TRUE;
                        Com_TxSignalGroupState[signalGroupId].WithoutRepetition = FALSE;
                    }
                }
                else
                {
                    if (TRUE == valueChanged)
                    {
                        Com_TxSignalGroupState[signalGroupId].NTimesTransmitNeed = TRUE;
                        Com_TxSignalGroupState[signalGroupId].WithoutRepetition = FALSE;
                    }
                }
                break;
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIGGERED_ON_CHANGE_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIG_ON_CH_NO_REPETITION_ENABLE)
            case COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
                if (TRUE == valueChanged)
                {
                    Com_TxSignalGroupState[signalGroupId].NTimesTransmitNeed = TRUE;
                    Com_TxSignalGroupState[signalGroupId].WithoutRepetition = TRUE;
                }
                break;
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIG_ON_CH_NO_REPETITION_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIG_NO_REPETITION_ENABLE)
            case COM_TRIGGERED_WITHOUT_REPETITION:
                Com_TxSignalGroupState[signalGroupId].NTimesTransmitNeed = TRUE;
                Com_TxSignalGroupState[signalGroupId].WithoutRepetition = TRUE;
                break;
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_PROP_TRIG_NO_REPETITION_ENABLE) */
            default:
                /*do nothing*/
                break;
            }
            ret = E_OK;
        }
    }
    return ret;
}
#endif /* #if (COM_TXSIGNALGROUP_NUMBER > 0u) && (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
/******************************************************************************/
/*
 * Brief               Called by Com_SendSignalGroup.
 *                     pack the Tx signal group into ipdu Tx buffer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalGroupId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (COM_TXSIGNALGROUP_NUMBER > 0u)
FUNC(void, COM_CODE)
Com_TxSignalGroupPack(Com_SignalGroupIdType SignalGroupId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    const Com_TxSignalGroupType* txSignalGroupPtr = &Com_ConfigStd->ComTxSignalGroup[SignalGroupId];
    Com_SignalIdType groupSignalNumber = txSignalGroupPtr->ComGroupSignalNumber;
    Com_SignalIdType cnt;
    Com_SignalIdType groupSignalId;
#if ((0u < COM_TMCTXGROUPSIGNAL_NUMBER) && (0u < COM_TMCTXSIGNAL_NUMBER))
    Com_SignalIdType groupSignalTMCId;
#endif
#if (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
    uint16 length;
    PduIdType txPduId;
    uint32 bitPosition;
    uint16 signalBufferId;
#endif /* #if (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
    const Com_TxGroupSignalType* txGroupSignalPtr;

    for (cnt = 0u; cnt < groupSignalNumber; cnt++)
    {
        groupSignalId = txSignalGroupPtr->ComTxGroupSignalId[cnt];
        txGroupSignalPtr = &Com_ConfigStd->ComTxGroupSignal[groupSignalId];
#if ((0u < COM_TMCTXGROUPSIGNAL_NUMBER) && (0u < COM_TMCTXSIGNAL_NUMBER))
        if (NULL_PTR != txGroupSignalPtr->ComFilter)
        {
            groupSignalTMCId = txGroupSignalPtr->ComFilter->ComTMCBufferId;
            TxSignalTMCRunTime[groupSignalTMCId] = TxGroupSignalTMCBuffer[groupSignalTMCId];
        }
#endif
#if (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)
        if (COM_UINT8_DYN == txGroupSignalPtr->ComSignalType)
        {
            txPduId = txSignalGroupPtr->ComIpduRefIndex;
            bitPosition = txGroupSignalPtr->ComBitPosition;
            signalBufferId = txGroupSignalPtr->ComSignalInitValueId;
            length = Com_TxSignalGroupState[SignalGroupId].DynamicSignalLength;
            Com_TxDynSignalPack(txPduId, bitPosition, signalBufferId, length);
        }
        else
#endif /* #if (STD_ON == COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) */
        {
            Com_TxGroupSignalPack(groupSignalId);
        }
    }
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               Called by Com_SendSignalGroupArray.
 *                     update every group signal buffer,calculate every TMC,
 *                     return the signal group is changed or not for trigger
 *                     transmit.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxSignalGroupId,GroupSignalNumber,TxIPduBufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/******************************************************************************/
#if ((STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (COM_TXSIGNALGROUP_NUMBER > 0u))
FUNC(boolean, COM_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Com_UpdateTxBufferAndCalculateTMCOfEveryGroupSignal(
    /* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
    Com_SignalGroupIdType TxSignalGroupId,
    Com_SignalIdType GroupSignalNumber,
    uint16 TxIPduBufferId)
{
    boolean triggerOnChange = FALSE;
    Com_SignalIdType groupSignalId;
    Com_SignalType groupSignalType;
    uint16 groupSignalInitValueId;
    uint16 cnt;
    uint64 groupSignalValue;
#if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE)
    Com_SignalIdType txSignalTMCId;
#endif /* #if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE) */
    const Com_TxGroupSignalType* txGroupSignalPtr;
    const Com_TxSignalGroupType* txSignalGroupPtr = &Com_ConfigStd->ComTxSignalGroup[TxSignalGroupId];

    for (cnt = 0u; cnt < GroupSignalNumber; cnt++)
    {
        groupSignalId = txSignalGroupPtr->ComTxGroupSignalId[cnt];
        txGroupSignalPtr = &Com_ConfigStd->ComTxGroupSignal[groupSignalId];
        groupSignalType = txGroupSignalPtr->ComSignalType;
        groupSignalInitValueId = txGroupSignalPtr->ComSignalInitValueId;
        if (COM_UINT8_N == groupSignalType)
        {
#if ((0u < COM_TXIPDUBUFF_SIZE) && (0u < COM_SIGNAL_8BITBUFF_SIZE))
            triggerOnChange = Com_TxGroupSignalUpdateUint8N(TxIPduBufferId, groupSignalId, groupSignalInitValueId);
#endif
        }
        else
        {
            /*UnPack tx group signal from signal group array,used to calculate the TMC of the signal and judge the
             * signal value if changed or not,if changed update the signal value*/
            groupSignalValue = Com_UnPackTxArrayGroupSignalValue(groupSignalId, TxIPduBufferId);
#if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE)
            if (NULL_PTR != txGroupSignalPtr->ComFilter)
            {
                txSignalTMCId = txGroupSignalPtr->ComFilter->ComTMCBufferId;
                TxSignalTMCRunTime[txSignalTMCId] = Com_TxSignalTMCCalculate(
                    &groupSignalValue,
                    txGroupSignalPtr->ComFilter,
                    groupSignalType,
                    groupSignalInitValueId);
            }
#endif /* #if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE) */
            switch (groupSignalType)
            {
#if (0u < COM_SIGNAL_BOOLBUFF_SIZE)
            case COM_BOOLEAN:
                /* PRQA S 4304,4340 ++ */ /* MISRA Rule 10.5,10.5 */
                if (Com_SignalBoolRuntimeBuff[groupSignalInitValueId] != (boolean)groupSignalValue)
                {
                    Com_SignalBoolRuntimeBuff[groupSignalInitValueId] = (boolean)groupSignalValue;
                    Com_TxArrayGroupSignalTriggerOnChange(groupSignalId, &triggerOnChange);
                }
                /* PRQA S 4304,4340 -- */ /* MISRA Rule 10.5,10.5 */
                break;
#endif
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
            case COM_UINT8:
            case COM_SINT8:
                if (Com_Signal8BitRuntimeBuff[groupSignalInitValueId] != (uint8)groupSignalValue)
                {
                    Com_Signal8BitRuntimeBuff[groupSignalInitValueId] = (uint8)groupSignalValue;
                    Com_TxArrayGroupSignalTriggerOnChange(groupSignalId, &triggerOnChange);
                }
                break;
#endif
#if (0u < COM_SIGNAL_16BITBUFF_SIZE)
            case COM_UINT16:
            case COM_SINT16:
                if (Com_Signal16BitRuntimeBuff[groupSignalInitValueId] != (uint16)groupSignalValue)
                {
                    Com_Signal16BitRuntimeBuff[groupSignalInitValueId] = (uint16)groupSignalValue;
                    Com_TxArrayGroupSignalTriggerOnChange(groupSignalId, &triggerOnChange);
                }
                break;
#endif
#if (0u < COM_SIGNAL_32BITBUFF_SIZE)
            case COM_UINT32:
            case COM_SINT32:
            case COM_FLOAT32:
                if (Com_Signal32BitRuntimeBuff[groupSignalInitValueId] != (uint32)groupSignalValue)
                {
                    Com_Signal32BitRuntimeBuff[groupSignalInitValueId] = (uint32)groupSignalValue;
                    Com_TxArrayGroupSignalTriggerOnChange(groupSignalId, &triggerOnChange);
                }
                break;
#endif
#if (0u < COM_SIGNAL_64BITBUFF_SIZE)
            case COM_UINT64:
            case COM_SINT64:
            case COM_FLOAT64:
                if (Com_Signal64BitRuntimeBuff[groupSignalInitValueId] != (uint64)groupSignalValue)
                {
                    Com_Signal64BitRuntimeBuff[groupSignalInitValueId] = (uint64)groupSignalValue;
                    Com_TxArrayGroupSignalTriggerOnChange(groupSignalId, &triggerOnChange);
                }
                break;
#endif
            default:
                /*do nothing*/
                break;
            }
        }
    }
    return triggerOnChange;
}
#endif /*(STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (COM_TXSIGNALGROUP_NUMBER > 0)*/
/******************************************************************************/
/*
 * Brief               Called by Com_TriggerIPDUSend,Com_TriggerIPDUSendWithMetaData,
 *                     Com_TriggerTransmit,Com_TxConfirmation,Com_TpTxConfirmation,
 *                     Com_MainFunctionTx,Com_TxIpduController.
 *                     clear all signal group/signal/dest description signal
 *                     update bit of the Tx Pdu
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxIpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) \
    || (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
FUNC(void, COM_CODE)
Com_ClearTxIPduUpdates(PduIdType TxIpduId)
{
#if (0u < COM_TXIPDUBUFF_SIZE)
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[TxIpduId];
    uint16 cnt;
    uint32 updateBitValue = COM_UNUSED_UINT32;
    uint16 ipduBufferIndex = txIpduPtr->ComTxIPduBufIndex;
    uint32 updateBitPosition;

#if (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE)
    Com_SignalGroupIdType signalGroupNumber = txIpduPtr->ComIPduSignalGroupsRefNumber;
    const Com_TxSignalGroupType* txSignalGroupPtr;
    uint16 signalGroupRef;
    for (cnt = 0u; cnt < signalGroupNumber; cnt++)
    {
        signalGroupRef = txIpduPtr->ComIPduSignalGroupsRef[cnt];
        txSignalGroupPtr = &Com_ConfigStd->ComTxSignalGroup[signalGroupRef];
        updateBitPosition = txSignalGroupPtr->ComUpdateBitPosition;
        if (updateBitValue != updateBitPosition)
        {
            Com_TxIPduRuntimeBuff[ipduBufferIndex + (updateBitPosition >> 3u)] &=
                (uint8)(~(txSignalGroupPtr->ComUpdateBitMask));
        }
    }
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) */
#if (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE)
    Com_SignalIdType signalNumber = txIpduPtr->ComIPduSignalsRefNumber;
    const Com_TxSignalType* txSignalPtr;
    uint16 signalRef;
    for (cnt = 0u; cnt < signalNumber; cnt++)
    {
        signalRef = txIpduPtr->ComIPduSignalsRef[cnt];
        txSignalPtr = &Com_ConfigStd->ComTxSignal[signalRef];
        updateBitPosition = txSignalPtr->ComUpdateBitPosition;
        if (updateBitValue != updateBitPosition)
        {
            Com_TxIPduRuntimeBuff[ipduBufferIndex + (updateBitPosition >> 3u)] &=
                (uint8)(~(txSignalPtr->ComUpdateBitMask));
        }
    }
#endif /* #if (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) */
#if (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
    Com_SignalIdType gwDestSignalNumber = txIpduPtr->ComIPduDestSignalsRefNumber;
    const Com_GwDestSignalType* gwDestSignalPtr;
    uint16 DestSignalRef;
    for (cnt = 0u; cnt < gwDestSignalNumber; cnt++)
    {
        DestSignalRef = txIpduPtr->ComIPduDestSignalsRef[cnt];
        gwDestSignalPtr = &Com_ConfigStd->ComDestSignal[DestSignalRef];
        updateBitPosition = gwDestSignalPtr->ComUpdateBitPosition;
        if (updateBitValue != updateBitPosition)
        {
            Com_TxIPduRuntimeBuff[ipduBufferIndex + (updateBitPosition >> 3u)] &=
                (uint8)(~(gwDestSignalPtr->ComUpdateBitMask));
        }
    }
#endif /* #if (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE) */
#endif
    return;
}
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) || (STD_ON \
          == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE) */
/******************************************************************************/
/*
 * Brief               Called by Com_TxConfirmation,Com_TpTxConfirmation,
 *                     Com_MainFunctionTx.
 *                     Tx notification for all signals/signal groups of the Tx Pdu
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxIpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == COM_TX_SIGNAL_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_NOTIFICATION_ENABLE)
FUNC(void, COM_CODE)
Com_ConfirmationProcess(PduIdType TxIpduId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[TxIpduId];
    uint16 cnt;

#if (STD_ON == COM_TX_SIGNAL_NOTIFICATION_ENABLE)
    Com_SignalIdType signalNumber = txIpduPtr->ComIPduSignalsRefNumber;
    Com_SignalIdType txSignalId;
    for (cnt = 0u; cnt < signalNumber; cnt++)
    {
        txSignalId = txIpduPtr->ComIPduSignalsRef[cnt];
        if (NULL_PTR != Com_ConfigStd->ComTxSignal[txSignalId].ComNotification)
        {
            Com_ConfigStd->ComTxSignal[txSignalId].ComNotification();
        }
    }
#endif /* #if (STD_ON == COM_TX_SIGNAL_NOTIFICATION_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_NOTIFICATION_ENABLE)
    Com_SignalGroupIdType siganlGroupNumber = txIpduPtr->ComIPduSignalGroupsRefNumber;
    Com_SignalGroupIdType txSignalGroupId;
    for (cnt = 0u; cnt < siganlGroupNumber; cnt++)
    {
        txSignalGroupId = txIpduPtr->ComIPduSignalGroupsRef[cnt];
        if (NULL_PTR != Com_ConfigStd->ComTxSignalGroup[txSignalGroupId].ComNotification)
        {
            Com_ConfigStd->ComTxSignalGroup[txSignalGroupId].ComNotification();
        }
    }
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_NOTIFICATION_ENABLE) */
    return;
}
#endif /* #if (STD_ON == COM_TX_SIGNAL_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_NOTIFICATION_ENABLE) */
/******************************************************************************/
/*
 * Brief               Called by Com_MainFunctionTx.
 *                     tx pdu DM timeout notification.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxIpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == COM_TX_SIGNAL_TIMEOUT_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_TIMEOUT_NOTIFICATION_ENABLE)
FUNC(void, COM_CODE)
Com_TxDMTimeOutNotification(PduIdType TxIpduId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[TxIpduId];
    uint16 cnt;

#if (STD_ON == COM_TX_SIGNAL_TIMEOUT_NOTIFICATION_ENABLE)
    Com_SignalIdType signalNumber = txIpduPtr->ComIPduSignalsRefNumber;
    Com_SignalIdType txSignalId;
    for (cnt = 0u; cnt < signalNumber; cnt++)
    {
        txSignalId = txIpduPtr->ComIPduSignalsRef[cnt];
        if (NULL_PTR != Com_ConfigStd->ComTxSignal[txSignalId].ComTimeoutNotification)
        {
            Com_ConfigStd->ComTxSignal[txSignalId].ComTimeoutNotification();
        }
    }
#endif /* #if (STD_ON == COM_TX_SIGNAL_TIMEOUT_NOTIFICATION_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_TIMEOUT_NOTIFICATION_ENABLE)
    Com_SignalGroupIdType signalGroupNumber = txIpduPtr->ComIPduSignalGroupsRefNumber;
    Com_SignalGroupIdType txSignalGroupId;
    for (cnt = 0u; cnt < signalGroupNumber; cnt++)
    {
        txSignalGroupId = txIpduPtr->ComIPduSignalGroupsRef[cnt];
        if (NULL_PTR != Com_ConfigStd->ComTxSignalGroup[txSignalGroupId].ComTimeoutNotification)
        {
            Com_ConfigStd->ComTxSignalGroup[txSignalGroupId].ComTimeoutNotification();
        }
    }
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_TIMEOUT_NOTIFICATION_ENABLE) */
    return;
}
#endif /* #if (STD_ON == COM_TX_SIGNAL_TIMEOUT_NOTIFICATION_ENABLE) || (STD_ON == \
          COM_TX_SIG_GROUP_TIMEOUT_NOTIFICATION_ENABLE) */
/******************************************************************************/
/*
 * Brief               Called by Com_MainFunctionTx.
 *                     the handle of Com_MainFunctionTx,when the tx mode is direct.
 *                     return the boolean value for the tx pdu need to transmit or not.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId,MDTRun
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE)
FUNC(boolean, COM_CODE)
Com_MainFuncTxDirect(PduIdType IPduId, boolean MDTRun) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    boolean ret = FALSE;
    Com_TxIPduRunTimeStateType* txIpduRunTimesStatePtr = &Com_TxIPduRunTimeState[IPduId];
#if (STD_ON == COM_TX_MODE_DIRECT_N_TIMES_ENABLE)
    if (txIpduRunTimesStatePtr->NTimeCnt > 0u)
    {
        (txIpduRunTimesStatePtr->NTimeCnt) -= 1u;
    }
#endif /* #if (STD_ON == COM_TX_MODE_DIRECT_N_TIMES_ENABLE) */
    if ((0u == txIpduRunTimesStatePtr->NTimeCnt) && (txIpduRunTimesStatePtr->RptNum > 0u)
        && (FALSE == txIpduRunTimesStatePtr->Transmiting))
    {
/*delay transmit of the MDT */
#if (STD_ON == COM_MDT_ENABLE)
        if (TRUE == MDTRun)
        {
            txIpduRunTimesStatePtr->TxDelay = TRUE;
        }
        else
#endif /* #if (STD_ON == COM_MDT_ENABLE) */
        {
            ret = TRUE;
        }
        /*reset NTimes counter*/
#if (STD_ON == COM_TMS_ENABLE)
        if (TRUE == txIpduRunTimesStatePtr->TMS)
#endif /* #if (STD_ON == COM_TMS_ENABLE) */
        {
            txIpduRunTimesStatePtr->NTimeCnt =
                Com_ConfigStd->ComTxIPdu[IPduId].ComTxModeTrue->ComTxModeRepetitionPeriod;
        }
#if (STD_ON == COM_TMS_ENABLE)
        else
        {
            txIpduRunTimesStatePtr->NTimeCnt =
                Com_ConfigStd->ComTxIPdu[IPduId].ComTxModeFalse->ComTxModeRepetitionPeriod;
        }
#endif /* #if (STD_ON == COM_TMS_ENABLE) */
    }
    if ((FALSE == MDTRun) && (TRUE == txIpduRunTimesStatePtr->TxDelay))
    {
        ret = TRUE;
    }
    return ret;
}
#endif /* #if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) */
/******************************************************************************/
/*
 * Brief               Called by Com_MainFunctionTx.
 *                     the handle of Com_MainFunctionTx,when the tx mode is period.
 *                     return the boolean value for the tx pdu need to transmit or not.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId,MDTRun
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(boolean, COM_CODE)
Com_MainFuncTxPeriod(PduIdType IPduId, boolean MDTRun) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    boolean ret = FALSE;
    Com_TxIPduRunTimeStateType* txIpduRunTimesStatePtr = &Com_TxIPduRunTimeState[IPduId];
    if (txIpduRunTimesStatePtr->PeriodCnt > 0u)
    {
        (txIpduRunTimesStatePtr->PeriodCnt) -= 1u;
    }
    if (0u == txIpduRunTimesStatePtr->PeriodCnt)
    {
/*delay transmit of the MDT */
#if (STD_ON == COM_MDT_ENABLE)
        if (TRUE == MDTRun)
        {
            txIpduRunTimesStatePtr->TxDelay = TRUE;
        }
        else
#endif /* #if (STD_ON == COM_MDT_ENABLE) */
        {
            ret = TRUE;
        }
        /*reset Period counter*/
#if (STD_ON == COM_TMS_ENABLE)
        if (TRUE == txIpduRunTimesStatePtr->TMS)
#endif /* #if (STD_ON == COM_TMS_ENABLE) */
        {
            txIpduRunTimesStatePtr->PeriodCnt = Com_ConfigStd->ComTxIPdu[IPduId].ComTxModeTrue->ComTxModeTimePeriod;
        }
#if (STD_ON == COM_TMS_ENABLE)
        else
        {
            txIpduRunTimesStatePtr->PeriodCnt = Com_ConfigStd->ComTxIPdu[IPduId].ComTxModeFalse->ComTxModeTimePeriod;
        }
#endif /* #if (STD_ON == COM_TMS_ENABLE) */
    }
    if ((FALSE == MDTRun) && (TRUE == txIpduRunTimesStatePtr->TxDelay))
    {
        ret = TRUE;
    }
    if ((TRUE == ret) && (0u == txIpduRunTimesStatePtr->DMCnt))
    {
        /*reset the tx MD counter*/
        txIpduRunTimesStatePtr->DMCnt = Com_ConfigStd->ComTxIPdu[IPduId].ComTxIpduDM;
    }
    return ret;
}
/******************************************************************************/
/*
 * Brief               Called by Com_MainFunctionTx.
 *                     the handle of Com_MainFunctionTx,when the tx mode is mixed.
 *                     return the boolean value for the tx pdu need to transmit or not
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId,MDTRun
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == COM_TX_MODE_MIXED_ENABLE)
FUNC(boolean, COM_CODE)
Com_MainFuncTxMixed(PduIdType IPduId, boolean MDTRun) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    boolean ret = FALSE;
    Com_TxIPduRunTimeStateType* txIpduRunTimesStatePtr = &Com_TxIPduRunTimeState[IPduId];
    /*DIRECT mode*/
#if (STD_ON == COM_TX_MODE_MIXED_N_TIMES_ENABLE)
    if (txIpduRunTimesStatePtr->NTimeCnt > 0u)
    {
        (txIpduRunTimesStatePtr->NTimeCnt) -= 1u;
    }
#endif /* #if (STD_ON == COM_TX_MODE_MIXED_N_TIMES_ENABLE) */
    if ((0u == txIpduRunTimesStatePtr->NTimeCnt) && (txIpduRunTimesStatePtr->RptNum > 0u)
        && (FALSE == txIpduRunTimesStatePtr->Transmiting))
    {
/*delay transmit of the MDT */
#if (STD_ON == COM_MDT_ENABLE)
        if (TRUE == MDTRun)
        {
            txIpduRunTimesStatePtr->TxDelay = TRUE;
        }
        else
#endif /* #if (STD_ON == COM_MDT_ENABLE) */
        {
            ret = TRUE;
        }
/*reset NTimes counter*/
#if (STD_ON == COM_TMS_ENABLE)
        if (TRUE == txIpduRunTimesStatePtr->TMS)
#endif /* #if (STD_ON == COM_TMS_ENABLE) */
        {
            txIpduRunTimesStatePtr->NTimeCnt =
                Com_ConfigStd->ComTxIPdu[IPduId].ComTxModeTrue->ComTxModeRepetitionPeriod;
        }
#if (STD_ON == COM_TMS_ENABLE)
        else
        {
            txIpduRunTimesStatePtr->NTimeCnt =
                Com_ConfigStd->ComTxIPdu[IPduId].ComTxModeFalse->ComTxModeRepetitionPeriod;
        }
#endif /* #if (STD_ON == COM_TMS_ENABLE) */
    }
    /*PERIODIC mode*/
    if (txIpduRunTimesStatePtr->PeriodCnt > 0u)
    {
        (txIpduRunTimesStatePtr->PeriodCnt) -= 1u;
    }
    if (0u == txIpduRunTimesStatePtr->PeriodCnt)
    {
/*delay transmit of the MDT */
#if (STD_ON == COM_MDT_ENABLE)
        if (TRUE == MDTRun)
        {
            txIpduRunTimesStatePtr->TxDelay = TRUE;
        }
        else
#endif /* #if (STD_ON == COM_MDT_ENABLE) */
        {
            ret = TRUE;
        }
/*reset Period counter*/
#if (STD_ON == COM_TMS_ENABLE)
        if (TRUE == txIpduRunTimesStatePtr->TMS)
#endif /* #if (STD_ON == COM_TMS_ENABLE) */
        {
            txIpduRunTimesStatePtr->PeriodCnt = Com_ConfigStd->ComTxIPdu[IPduId].ComTxModeTrue->ComTxModeTimePeriod;
        }
#if (STD_ON == COM_TMS_ENABLE)
        else
        {
            txIpduRunTimesStatePtr->PeriodCnt = Com_ConfigStd->ComTxIPdu[IPduId].ComTxModeFalse->ComTxModeTimePeriod;
        }
#endif /* #if (STD_ON == COM_TMS_ENABLE) */
    }
    if ((FALSE == MDTRun) && (TRUE == txIpduRunTimesStatePtr->TxDelay))
    {
        ret = TRUE;
    }
    if ((TRUE == ret) && (0u == txIpduRunTimesStatePtr->RptNum) && (0u == txIpduRunTimesStatePtr->DMCnt))
    {
        /*reset the tx MD counter,when active mode is PERIODIC*/
        txIpduRunTimesStatePtr->DMCnt = Com_ConfigStd->ComTxIPdu[IPduId].ComTxIpduDM;
    }
    return ret;
}
#endif /* #if (STD_ON == COM_TX_MODE_MIXED_ENABLE) */
/******************************************************************************/
/*
 * Brief               Called by Com_TriggerTransmit,Com_TriggerIPDUSend,
 *                     Com_TriggerIPDUSendWithMetaData,Com_TxIpduController.
 *                     It is called in case the transmission is not possible
 *                     because the corresponding I-PDU group is stopped.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE)
FUNC(void, COM_CODE)
Com_InvokeErrorNotification(PduIdType IpduId)
{
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[IpduId];
    uint16 cnt;

#if (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE)
    Com_SignalIdType ipduSignalNumber = txIpduPtr->ComIPduSignalsRefNumber;
    Com_SignalIdType signalId;
    for (cnt = 0u; cnt < ipduSignalNumber; cnt++)
    {
        signalId = txIpduPtr->ComIPduSignalsRef[cnt];
        /*call signal Tx Err Notification*/
        if (NULL_PTR != Com_ConfigStd->ComTxSignal[signalId].ComErrorNotification)
        {
            Com_ConfigStd->ComTxSignal[signalId].ComErrorNotification();
        }
    }
#endif /* #if (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) */
#if (STD_ON == COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE)
    Com_SignalGroupIdType ipduSignalGroupNumber = txIpduPtr->ComIPduSignalGroupsRefNumber;
    Com_SignalGroupIdType signalGroupId;
    for (cnt = 0u; cnt < ipduSignalGroupNumber; cnt++)
    {
        signalGroupId = txIpduPtr->ComIPduSignalGroupsRef[cnt];
        /*call signal group Tx Err Notification*/
        if (NULL_PTR != Com_ConfigStd->ComTxSignalGroup[signalGroupId].ComErrorNotification)
        {
            Com_ConfigStd->ComTxSignalGroup[signalGroupId].ComErrorNotification();
        }
    }
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE) */
    return;
}
#endif /* #if (STD_ON == COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE) || (STD_ON == \
          COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE) */
/******************************************************************************/
/*
 * Brief               Called by Com_MainFunctionTx,Com_TriggerIPDUSend,
 *                     Com_TriggerIPDUSendWithMetaData.
 *                     Pack the counter value in the pdu buffer.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxIpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == COM_TX_IPDU_COUNTER_ENABLE)
FUNC(void, COM_CODE)
Com_PackCounterValue(PduIdType TxIpduId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (0u < COM_TXIPDUBUFF_SIZE)
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[TxIpduId];
    uint8 txCounter = Com_TxIPduRunTimeState[TxIpduId].TxIpduCounter;
    uint16 ipduBufferIndex = txIpduPtr->ComTxIPduBufIndex;
    uint32 bitPosition = txIpduPtr->ComIPduCounter->ComIPduCounterStartPosition;
    uint8 bitSize = txIpduPtr->ComIPduCounter->ComIPduCounterSize;
    uint8 bitPosInByte = (uint8)(bitPosition & 0x07u);

    ipduBufferIndex = ipduBufferIndex + (uint16)(bitPosition >> 3u);
    /* Align LSB of txData and signal_value in IPdu */
    txCounter = txCounter << bitPosInByte;
    /*Clear corresponding bits in IPdu*/
    Com_TxIPduRuntimeBuff[ipduBufferIndex] &=
        (0xFFu >> (8u - bitPosInByte)) | (uint8)(0xFFu << (bitPosInByte + bitSize));
    /*write corresponding bits to IPdu buffer*/
    Com_TxIPduRuntimeBuff[ipduBufferIndex] |= ((0xFFu >> (8u - (bitPosInByte + bitSize))) & txCounter);
#endif
    return;
}
#endif /* #if (STD_ON == COM_TX_IPDU_COUNTER_ENABLE) */
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/******************************************************************************/
/*
 * Brief               called by Com_TxIpduController.
 *                     reset OCCURRENCE of filter with ComFilterAlgorithm ONE_EVERY_N.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (COM_ONEEVERYNFILTERSIGNAL_NUMBER > 0u)
static FUNC(void, COM_CODE) Com_ResetTxOccurrenceOfPduFilter(PduIdType IpduId)
{
    uint16 cnt;
    Com_SignalIdType ipduSignalNumber;
    Com_SignalGroupIdType ipduSignalGroupNumber;
    Com_SignalGroupIdType signalGroupId;
    Com_SignalIdType ipduDestSignalNumber;
    Com_SignalIdType signalId;
    Com_SignalIdType oneEveryNId;
    uint16 counter;
    uint16 groupSignalNumber;
    uint16 groupSignalId;
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[IpduId];
    /*reset signal/group signal/dest description signal of tx pdu which ComFilterAlgorithm is ONE_EVERY_N*/
    ipduSignalNumber = txIpduPtr->ComIPduSignalsRefNumber;
    for (cnt = 0u; cnt < ipduSignalNumber; cnt++)
    {
        signalId = txIpduPtr->ComIPduSignalsRef[cnt];
        if (NULL_PTR != Com_ConfigStd->ComTxSignal[signalId].ComFilter)
        {
            oneEveryNId = Com_ConfigStd->ComTxSignal[signalId].ComFilter->ComOneEveryNId;
            if (COM_UNUSED_UINT16 != oneEveryNId)
            {
                Com_OneEveryNcnt[oneEveryNId] = 0u;
            }
        }
    }
    ipduDestSignalNumber = txIpduPtr->ComIPduDestSignalsRefNumber;
    for (cnt = 0u; cnt < ipduDestSignalNumber; cnt++)
    {
        signalId = txIpduPtr->ComIPduDestSignalsRef[cnt];
        if (NULL_PTR != Com_ConfigStd->ComDestSignal[signalId].ComFilter)
        {
            oneEveryNId = Com_ConfigStd->ComDestSignal[signalId].ComFilter->ComOneEveryNId;
            if (COM_UNUSED_UINT16 != oneEveryNId)
            {
                Com_OneEveryNcnt[oneEveryNId] = 0u;
            }
        }
    }
    ipduSignalGroupNumber = txIpduPtr->ComIPduSignalGroupsRefNumber;
    for (cnt = 0u; cnt < ipduSignalGroupNumber; cnt++)
    {
        signalGroupId = txIpduPtr->ComIPduSignalGroupsRef[cnt];
        groupSignalNumber = Com_ConfigStd->ComTxSignalGroup[signalGroupId].ComGroupSignalNumber;
        for (counter = 0u; counter < groupSignalNumber; counter++)
        {
            groupSignalId = Com_ConfigStd->ComTxSignalGroup[signalGroupId].ComTxGroupSignalId[counter];
            if (NULL_PTR != Com_ConfigStd->ComTxGroupSignal[groupSignalId].ComFilter)
            {
                oneEveryNId = Com_ConfigStd->ComTxGroupSignal[groupSignalId].ComFilter->ComOneEveryNId;
                if (COM_UNUSED_UINT16 != oneEveryNId)
                {
                    Com_OneEveryNcnt[oneEveryNId] = 0u;
                }
            }
        }
    }
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               called by Com_TxIpduController.
 *                     init the tx ipdu buffer,all signal buffer
 *                     (included in the ipdu) and init the TMC.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (COM_IPDUGROUP_NUMBER > 0u)
static FUNC(void, COM_CODE) Com_ResetTxPduBufferAndSignalBuffer(PduIdType IpduId)
{
#if (0u < COM_TXIPDUBUFF_SIZE)
    uint16 pduBufferId;
    uint16 initPduLength;
#endif
    uint16 cnt;
#if (0u < COM_TMCTXSIGNAL_NUMBER)
    Com_SignalIdType txSignalTMCId;
#endif
    Com_SignalIdType ipduSignalNumber;
    Com_SignalGroupIdType ipduSignalGroupNumber;
    Com_SignalGroupIdType signalGroupId;
    Com_SignalIdType ipduDestSignalNumber;
    Com_SignalIdType signalId;
    uint16 signalInitValueId;
    Com_SignalType signalType;
    uint16 signalLength;
    uint16 counter;
    uint16 groupSignalNumber;
    uint16 groupSignalId;
    const Com_TxSignalType* txSignalPtr;
    const Com_GwDestSignalType* gwDestSignalPtr;
    const Com_TxSignalGroupType* txSignalGroupPtr;
    const Com_TxGroupSignalType* txGroupSignalPtr;
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[IpduId];

/*init the tx ipdu buffer,all signal buffer(included in the ipdu) and init the TMC*/
#if (0u < COM_TXIPDUBUFF_SIZE)
    pduBufferId = txIpduPtr->ComTxIPduBufIndex;
    initPduLength = Com_TxIPduInitState[IpduId].TxIpduLength;
    for (cnt = 0u; cnt < initPduLength; cnt++)
    {
        Com_TxIPduRuntimeBuff[pduBufferId + cnt] = Com_TxIPduInitValue[pduBufferId + cnt];
    }
#endif
    /*init signal buffer and TMC*/
    ipduSignalNumber = txIpduPtr->ComIPduSignalsRefNumber;
    for (cnt = 0u; cnt < ipduSignalNumber; cnt++)
    {
        signalId = txIpduPtr->ComIPduSignalsRef[cnt];
        txSignalPtr = &Com_ConfigStd->ComTxSignal[signalId];
        signalInitValueId = txSignalPtr->ComSignalInitValueId;
        signalType = txSignalPtr->ComSignalType;
        if ((COM_UINT8_DYN != signalType) && (COM_UINT8_N != signalType))
        {
            signalLength = 0u;
        }
        else
        {
            signalLength = (COM_UINT8_DYN == signalType) ? (txSignalPtr->ComSignalDataInitValueLength)
                                                         : (txSignalPtr->ComSignalLength);
        }
        Com_InitSignalBuffer(signalType, signalInitValueId, signalLength);
#if (0u < COM_TMCTXSIGNAL_NUMBER)
        if (NULL_PTR != txSignalPtr->ComFilter)
        {
            txSignalTMCId = txSignalPtr->ComFilter->ComTMCBufferId;
            TxSignalTMCRunTime[txSignalTMCId] = Com_TxSignalInitTMC[txSignalTMCId];
        }
#endif
    }
    /*init dest description signal buffer and TMC*/
    ipduDestSignalNumber = txIpduPtr->ComIPduDestSignalsRefNumber;
    for (cnt = 0u; cnt < ipduDestSignalNumber; cnt++)
    {
        signalId = txIpduPtr->ComIPduDestSignalsRef[cnt];
        gwDestSignalPtr = &Com_ConfigStd->ComDestSignal[signalId];
        signalInitValueId = gwDestSignalPtr->ComSignalInitValueId;
        signalType = gwDestSignalPtr->ComSignalType;
        if ((COM_UINT8_DYN != signalType) && (COM_UINT8_N != signalType))
        {
            signalLength = 0u;
        }
        else
        {
            signalLength = (COM_UINT8_DYN == signalType) ? (gwDestSignalPtr->ComSignalDataInitValueLength)
                                                         : (gwDestSignalPtr->ComSignalLength);
        }
        Com_InitSignalBuffer(signalType, signalInitValueId, signalLength);
#if (0u < COM_TMCTXSIGNAL_NUMBER)
        if (NULL_PTR != gwDestSignalPtr->ComFilter)
        {
            txSignalTMCId = gwDestSignalPtr->ComFilter->ComTMCBufferId;
            TxSignalTMCRunTime[txSignalTMCId] = Com_TxSignalInitTMC[txSignalTMCId];
        }
#endif
    }
    /*init group signal buffer and TMC*/
    ipduSignalGroupNumber = txIpduPtr->ComIPduSignalGroupsRefNumber;
    for (cnt = 0u; cnt < ipduSignalGroupNumber; cnt++)
    {
        signalGroupId = txIpduPtr->ComIPduSignalGroupsRef[cnt];
        txSignalGroupPtr = &Com_ConfigStd->ComTxSignalGroup[signalGroupId];
        groupSignalNumber = txSignalGroupPtr->ComGroupSignalNumber;
        for (counter = 0u; counter < groupSignalNumber; counter++)
        {
            groupSignalId = txSignalGroupPtr->ComTxGroupSignalId[counter];
            txGroupSignalPtr = &Com_ConfigStd->ComTxGroupSignal[groupSignalId];
            signalInitValueId = txGroupSignalPtr->ComSignalInitValueId;
            signalType = txGroupSignalPtr->ComSignalType;
            if ((COM_UINT8_DYN != signalType) && (COM_UINT8_N != signalType))
            {
                signalLength = 0u;
            }
            else
            {
                signalLength = (COM_UINT8_DYN == signalType) ? (txGroupSignalPtr->ComSignalDataInitValueLength)
                                                             : (txGroupSignalPtr->ComSignalLength);
            }
            Com_InitSignalBuffer(signalType, signalInitValueId, signalLength);
#if ((0u < COM_TMCTXSIGNAL_NUMBER) && (0u < COM_TMCTXGROUPSIGNAL_NUMBER))
            if (NULL_PTR != txGroupSignalPtr->ComFilter)
            {
                txSignalTMCId = txGroupSignalPtr->ComFilter->ComTMCBufferId;
                TxGroupSignalTMCBuffer[txSignalTMCId] = Com_TxSignalInitTMC[txSignalTMCId];
                TxSignalTMCRunTime[txSignalTMCId] = Com_TxSignalInitTMC[txSignalTMCId];
            }
#endif
        }
    }
    Com_TxIPduRunTimeState[IpduId].TMS = Com_TxIPduInitState[IpduId].TMS;
    Com_TxIPduRunTimeState[IpduId].ipduTxMode = Com_TxIPduInitState[IpduId].ipduTxMode;
    Com_TxIPduRunTimeState[IpduId].TxConfirm = FALSE;
    Com_TxIPduRunTimeState[IpduId].NTimeCnt = 0u;
    Com_TxIPduRunTimeState[IpduId].RptNum = 0u;
    Com_TxIPduRunTimeState[IpduId].Transmiting = FALSE;
    Com_TxIPduRunTimeState[IpduId].TxDelay = FALSE;
    Com_TxIPduRunTimeState[IpduId].TxIpduLength = Com_TxIPduInitState[IpduId].TxIpduLength;
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               called by Com_TxSignalGroupPack.
 *                     pack tx group signal(not dynamic).
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      GroupSignalId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (COM_TXSIGNALGROUP_NUMBER > 0u)
static FUNC(void, COM_CODE) Com_TxGroupSignalPack(Com_SignalIdType GroupSignalId)
{
    const Com_TxGroupSignalType* txGroupSignalPtr = &Com_ConfigStd->ComTxGroupSignal[GroupSignalId];
    Com_SignalGroupIdType signalGroupRef = txGroupSignalPtr->ComSignalGroupRef;
    PduIdType txIpduId = Com_ConfigStd->ComTxSignalGroup[signalGroupRef].ComIpduRefIndex;
    uint32 bitPosition = txGroupSignalPtr->ComBitPosition;
    Com_SignalType signalType = txGroupSignalPtr->ComSignalType;
    uint16 ipduBufferIndex = Com_ConfigStd->ComTxIPdu[txIpduId].ComTxIPduBufIndex;
    uint16 ipduBuffPos = ipduBufferIndex + (uint16)(bitPosition >> 3u);
    Com_TxSignalPackType parameter;
    uint16 signalBufferId = txGroupSignalPtr->ComSignalInitValueId;
#if ((0u < COM_SIGNAL_BOOLBUFF_SIZE) && (0u < COM_TXIPDUBUFF_SIZE))
    uint8 value = 0x01u;
#endif
#if ((0u < COM_SIGNAL_8BITBUFF_SIZE) && (0u < COM_TXIPDUBUFF_SIZE))
    uint16 signalLength;
    uint16 cnt;
#endif
    uint64 txData;
    uint8 signalByteLength;
    uint64 dataMSBByte;
    uint8 bitSize;
    uint8 bitPosInByte = (uint8)(bitPosition & 0x07u);

    /*pack boolean type group signal*/
#if ((0u < COM_SIGNAL_BOOLBUFF_SIZE) && (0u < COM_TXIPDUBUFF_SIZE))
    if (COM_BOOLEAN == signalType)
    {
        if (TRUE == Com_SignalBoolRuntimeBuff[signalBufferId])
        {
            Com_TxIPduRuntimeBuff[ipduBuffPos] |= (uint8)(value << bitPosInByte);
        }
        else
        {
            Com_TxIPduRuntimeBuff[ipduBuffPos] &= (uint8)(~((uint8)(value << bitPosInByte)));
        }
    }
    else
#endif /* #if ((0u < COM_SIGNAL_BOOLBUFF_SIZE) && (0u < COM_TXIPDUBUFF_SIZE)) */
#if ((0u < COM_SIGNAL_8BITBUFF_SIZE) && (0u < COM_TXIPDUBUFF_SIZE))
        /*pack COM_UINT8_N type group signal*/
        if (COM_UINT8_N == signalType)
        {
            signalLength = txGroupSignalPtr->ComSignalLength;
            for (cnt = 0u; cnt < signalLength; cnt++)
            {
                Com_TxIPduRuntimeBuff[ipduBuffPos + cnt] = Com_Signal8BitRuntimeBuff[signalBufferId + cnt];
            }
        }
        /*pack group signal expect signal type(boolean,COM_UINT8_N,COM_UINT8_DYN)*/
        else
#endif /* #if ((0u < COM_SIGNAL_8BITBUFF_SIZE) && (0u < COM_TXIPDUBUFF_SIZE)) */
        {
            /*get the group signal value need to be packed*/
            switch (signalType)
            {
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
            case COM_UINT8:
            case COM_SINT8:
                txData = (uint64)(Com_Signal8BitRuntimeBuff[signalBufferId]);
                break;
#endif
#if (0u < COM_SIGNAL_16BITBUFF_SIZE)
            case COM_UINT16:
            case COM_SINT16:
                txData = (uint64)(Com_Signal16BitRuntimeBuff[signalBufferId]);
                break;
#endif
#if (0u < COM_SIGNAL_32BITBUFF_SIZE)
            case COM_SINT32:
            case COM_UINT32:
            case COM_FLOAT32:
                txData = (uint64)(Com_Signal32BitRuntimeBuff[signalBufferId]);
                break;
#endif
#if (0u < COM_SIGNAL_64BITBUFF_SIZE)
            case COM_SINT64:
            case COM_UINT64:
            case COM_FLOAT64:
                txData = Com_Signal64BitRuntimeBuff[signalBufferId];
                break;
#endif
            default:
                /*reach here,the signal type is error*/
                txData = 0u;
                break;
            }
            /* group signal MSB byte value used for the signal value bits cover 9 bytes */
            dataMSBByte = txData;
            /* Align LSB of txData and signal_value in IPdu */
            txData = txData << bitPosInByte;
            bitSize = txGroupSignalPtr->ComBitSize;
            /*signalByteLength:1-9*/
            signalByteLength = txGroupSignalPtr->ComSignalByteLength;
            /*the tx signal all value bits are in one byte*/
            if (1u == signalByteLength)
            {
#if (0u < COM_TXIPDUBUFF_SIZE)
                /*Clear corresponding bits in IPdu*/
                Com_TxIPduRuntimeBuff[ipduBuffPos] &=
                    (0xFFu >> (8u - bitPosInByte)) | (uint8)(0xFFu << (bitPosInByte + bitSize));
                /*write corresponding bits to IPdu buffer*/
                Com_TxIPduRuntimeBuff[ipduBuffPos] |= (0xFFu >> (8u - (bitPosInByte + bitSize))) & ((uint8)txData);
#endif
            }
            /*the tx signal all value bits are included in 2-9 byte*/
            else if ((1u < signalByteLength) && (signalByteLength < 10u))
            {
                parameter.SignalByteLength = signalByteLength;
                parameter.SignalEndianness = txGroupSignalPtr->ComSignalEndianness;
                parameter.IpduBufferIndex = ipduBufferIndex;
                parameter.BitPosition = bitPosition;
                parameter.BitSize = bitSize;
                Com_TxSignalPackHandle(&parameter, txData, dataMSBByte);
            }
            /*this case will not happen*/
            else
            {
                /*do nothing*/
            }
        }
    return;
}
#endif /* COM_TXSIGNALGROUP_NUMBER > 0u */
/******************************************************************************/
/*
 * Brief               called by Com_UpdateTxBufferAndCalculateTMCOfEveryGroupSignal.
 *                     pack tx group signal(not dynamic).
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalId,IpduBufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint64
 */
/******************************************************************************/
#if ((STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (COM_TXSIGNALGROUP_NUMBER > 0u))
static FUNC(uint64, COM_CODE) Com_UnPackTxArrayGroupSignalValue(Com_SignalIdType SignalId, uint16 IpduBufferId)
{
    const Com_TxGroupSignalType* txGroupSignalPtr = &Com_ConfigStd->ComTxGroupSignal[SignalId];
    uint64 signalValue;

    signalValue = Com_SignalUnPackHandle(
        txGroupSignalPtr->ComSignalEndianness,
        txGroupSignalPtr->ComSignalByteLength,
        &Com_TxIPduRuntimeBuff[IpduBufferId],
        txGroupSignalPtr->ComBitPosition,
        txGroupSignalPtr->ComBitSize,
        txGroupSignalPtr->ComSignalType);
    return signalValue;
}
#endif
/******************************************************************************/
/*
 * Brief               called by Com_UpdateTxBufferAndCalculateTMCOfEveryGroupSignal.
 *                     the group signal value changed,judge it will trigger
 *                     the TxPdu transmit(DIRECT/MIXED mode) or not.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      GroupSignalId
 * Param-Name[out]     TriggerOnChange
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (COM_TXSIGNALGROUP_NUMBER > 0u))
static FUNC(void, COM_CODE)
    Com_TxArrayGroupSignalTriggerOnChange(Com_SignalIdType GroupSignalId, boolean* TriggerOnChange)
{
    if (TRUE == Com_ConfigStd->ComTxGroupSignal[GroupSignalId].ComTxGroupSignalUsedTransferProperty)
    {
        if (COM_TRIGGERED_ON_CHANGE == Com_ConfigStd->ComTxGroupSignal[GroupSignalId].ComTransferProperty)
        {
            *TriggerOnChange = TRUE;
        }
    }
    else
    {
        *TriggerOnChange = TRUE;
    }
}
#endif
/******************************************************************************/
/*
 * Brief               called by Com_TxSignalTMHandle,Com_SendTxGroupSignalHandle,
 *                     Com_UpdateTxBufferAndCalculateTMCOfEveryGroupSignal.
 *                     the group signal value changed,judge it will trigger
 *                     calculate the new TMC of the signal new value.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalValuePtr,ComFilter,SignalType,SignalBufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/******************************************************************************/
#if ((0u < COM_TMCTXSIGNAL_NUMBER) || (0u < COM_TMCTXGROUPSIGNAL_NUMBER)) && (STD_ON == COM_TMS_ENABLE)
static FUNC(boolean, COM_CODE) Com_TxSignalTMCCalculate(
    P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalValuePtr,
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
    Com_SignalType SignalType,
    uint16 SignalBufferId)
{
    boolean ret = FALSE;
    Com_FilterAlgorithmType filterType;
    uint64 signalNewValue;
#if (COM_ONEEVERYNFILTERSIGNAL_NUMBER > 0u)
    Com_SignalIdType oneEveryNId;
    uint32 filterOffset;
    uint32 filterPeriod;
#endif
    filterType = ComFilter->ComFilterAlgorithm;
    /*COM_UINT8_N just support ALWAYS and NEVER FilterAlgorithm*/
    if (COM_UINT8_N == SignalType)
    {
        if (COM_ALWAYS == filterType)
        {
            ret = TRUE;
        }
    }
    else
    {
        /*tx signal changed to uint64 type*/
        signalNewValue = Com_GetTxSignalValue(SignalType, SignalValuePtr);
        switch (filterType)
        {
        case COM_ALWAYS:
            ret = TRUE;
            break;
        case COM_MASKED_NEW_EQUALS_X:
            if (((signalNewValue) & (ComFilter->ComFilterMask)) == (ComFilter->ComFilterX))
            {
                ret = TRUE;
            }
            break;
        case COM_MASKED_NEW_DIFFERS_X:
            if (((signalNewValue) & (ComFilter->ComFilterMask)) != (ComFilter->ComFilterX))
            {
                ret = TRUE;
            }
            break;
        /*COM_BOOLEAN type not support WITHIN and WITHOUT*/
        case COM_NEW_IS_WITHIN:
            Com_NewIsWithinFilterCalculate(SignalType, signalNewValue, ComFilter, &ret);
            break;
        /*COM_BOOLEAN type not support WITHIN and WITHOUT*/
        case COM_NEW_IS_OUTSIDE:
            Com_NewIsWithoutFilterCalculate(SignalType, signalNewValue, ComFilter, &ret);
            break;
#if (COM_ONEEVERYNFILTERSIGNAL_NUMBER > 0u)
        case COM_ONE_EVERY_N:
            filterOffset = ComFilter->ComFilterOffset;
            filterPeriod = ComFilter->ComFilterPeriod;
            oneEveryNId = ComFilter->ComOneEveryNId;
            if (filterPeriod == Com_OneEveryNcnt[oneEveryNId])
            {
                Com_OneEveryNcnt[oneEveryNId] = 0u;
            }
            if (filterOffset == Com_OneEveryNcnt[oneEveryNId])
            {
                ret = TRUE;
            }
            Com_OneEveryNcnt[oneEveryNId]++;
            break;
#endif
        case COM_MASKED_NEW_DIFFERS_MASKED_OLD:
            ret = Com_MaskedNewDiffersMaskedOldFilterCalculate(SignalType, signalNewValue, ComFilter, SignalBufferId);
            break;
        default: /*include NEVER*/
            /*do nothing*/
            break;
        }
    }
    return ret;
}
#endif /* #if ((0u < COM_TMCTXSIGNAL_NUMBER) || (0u < COM_TMCTXGROUPSIGNAL_NUMBER)) && (STD_ON == COM_TMS_ENABLE) */
/******************************************************************************/
/*
 * Brief               called by Com_TxSignalTMCCalculate.
 *                     change the signal value to uint64 type.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalType,SignalValuePtr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint64
 */
/******************************************************************************/
#if ((0u < COM_TMCTXSIGNAL_NUMBER) || (0u < COM_TMCTXGROUPSIGNAL_NUMBER)) && (STD_ON == COM_TMS_ENABLE)
static FUNC(uint64, COM_CODE)
    Com_GetTxSignalValue(Com_SignalType SignalType, P2CONST(void, AUTOMATIC, COM_APPL_CONST) SignalValuePtr)
{
    uint64 signalNewValue = 0u;
    switch (SignalType)
    {
    case COM_BOOLEAN:
        /* PRQA S 4304 ++ */ /* MISRA Rule 10.5 */
        signalNewValue = (uint64)(*((const boolean*)SignalValuePtr));
        /* PRQA S 4304 ++ */ /* MISRA Rule 10.5 */
        break;
    case COM_UINT8:
    case COM_SINT8:
        signalNewValue = (uint64)(*((const uint8*)SignalValuePtr));
        break;
    case COM_SINT16:
    case COM_UINT16:
        signalNewValue = (uint64)(*((const uint16*)SignalValuePtr));
        break;
    case COM_SINT32:
    case COM_UINT32:
        signalNewValue = (uint64)(*((const uint32*)SignalValuePtr));
        break;
    case COM_SINT64:
    case COM_UINT64:
        signalNewValue = (*((const uint64*)SignalValuePtr));
        break;
    default:
        /*do nothing*/
        break;
    }
    return signalNewValue;
}
#endif /* #if ((0u < COM_TMCTXSIGNAL_NUMBER) || (0u < COM_TMCTXGROUPSIGNAL_NUMBER)) && (STD_ON == COM_TMS_ENABLE) */
/******************************************************************************/
/*
 * Brief               called by Com_UpdateTxBufferAndCalculateTMCOfEveryGroupSignal.
 *                     update the uint8_n signal value.
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxIPduBufferId,groupSignalId,groupSignalInitValueId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/******************************************************************************/
#if ((STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (COM_TXSIGNALGROUP_NUMBER > 0u))
#if ((0u < COM_TXIPDUBUFF_SIZE) && (0u < COM_SIGNAL_8BITBUFF_SIZE))
static FUNC(boolean, COM_CODE)
    Com_TxGroupSignalUpdateUint8N(uint16 TxIPduBufferId, Com_SignalIdType groupSignalId, uint16 groupSignalInitValueId)
{
    const Com_TxGroupSignalType* txGroupSignalPtr = &Com_ConfigStd->ComTxGroupSignal[groupSignalId];
    boolean triggerOnChange = FALSE;
    uint16 counter;
    uint16 groupSignalLength = txGroupSignalPtr->ComSignalLength;
    uint16 sigBufPosBase = TxIPduBufferId + (uint16)(txGroupSignalPtr->ComBitPosition >> 3u);
    uint16 sigBufPos;
    uint16 sigInitValueId;

    for (counter = 0u; counter < groupSignalLength; counter++)
    {
        sigBufPos = sigBufPosBase + counter;
        sigInitValueId = groupSignalInitValueId + counter;
        if (Com_TxIPduRuntimeBuff[sigBufPos] != Com_Signal8BitRuntimeBuff[sigInitValueId])
        {
            /*if the group signal changed,then update the signal buffer*/
            Com_Signal8BitRuntimeBuff[sigInitValueId] = Com_TxIPduRuntimeBuff[sigBufPos];
            Com_TxArrayGroupSignalTriggerOnChange(groupSignalId, &triggerOnChange);
        }
    }
    return triggerOnChange;
}
#endif /* ((0u < COM_TXIPDUBUFF_SIZE) && (0u < COM_SIGNAL_8BITBUFF_SIZE)) */
#endif /* ((STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (COM_TXSIGNALGROUP_NUMBER > 0u)) */

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

#endif /*0u < COM_TXIPDU_NUMBER*/
