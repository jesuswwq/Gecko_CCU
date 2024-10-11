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
**  FILENAME    : Com_GwInternal.c                                            **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : internal implementation for COM gateway signal              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Com_Internal.h"
#if (                                                                                   \
    (0u < COM_GWMAPPING_NUMBER) && (0u < COM_RXIPDU_NUMBER) && (0u < COM_TXIPDU_NUMBER) \
    && (STD_ON == COM_SIGNAL_GW_ENABLE))

/*==============================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==============================================================================*/
typedef struct
{
    PduIdType TxIpduId;
    uint32 BitPosition;
    Com_SignalType SignalType;
    Com_SignalEndiannessType SignalEndianness;
    uint8 BitSize;
    uint8 SignalByteLength;
} Com_Pack_Parameter;

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/* called by Com_GwSignal.
 * gateway signal/group signal/description signal which signal type isn't COM_UINT8_N and COM_UINT8_DYN*/
static FUNC(void, COM_CODE) Com_GwNotArraySignal(
    Com_SignalType SignalType,
    uint16 GWSignalBufferId,
    Com_GWSignalType DestSignalType,
    Com_SignalIdType DestSignalId);
/* called by Com_GwSignal.
 * gateway signal/group signal/description signal which signal type is COM_UINT8_N*/
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)                                                                      \
    && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) \
        || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE))
static FUNC(void, COM_CODE) Com_GwUint8NSignal(
    uint16 SignalBufferId,
    uint16 SignalLength,
    Com_GWSignalType DestSignalType,
    Com_SignalIdType DestSignalId);
#endif
/* called by Com_GwSignal.
 * gateway signal/group signal/description signal which signal type is COM_UINT8_DYN*/
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)                                                                          \
    && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
        || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE))
static FUNC(void, COM_CODE) Com_GwUint8DYNSignal(
    uint16 SignalBufferId,
    uint16 SignalLength,
    Com_GWSignalType DestSignalType,
    Com_SignalIdType DestSignalId);
#endif
/* called by Com_GwNotArraySignal.
 * gateway dest signal is packed to dest tx pdu buffer*/
#if (0u < COM_TXIPDUBUFF_SIZE)
static FUNC(void, COM_CODE) Com_DestSignalPack(Com_Pack_Parameter* PackPara, uint64 SignalValue);
#endif
/* called by Com_GwNotArraySignal.
 * calculate dest signal/group signal/description signal TMC*/
#if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE)
static FUNC(boolean, COM_CODE) Com_DestSignalTMCCalculate(
    Com_SignalType SignalType,
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
    uint64 NewSignalValue,
    uint64 OldSignalValue);
#endif /* (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE) */
/* called by Com_GwNotArraySignal,Com_GwUint8NSignal,Com_GwUint8DYNSignal.
 * gateway pdu(which include gateway signal) handle*/
#if ((0u < COM_TXSIGNAL_NUMBER) || (0u < COM_GW_DESTINATION_DESCRIPTION_NUMBER))
static FUNC(void, COM_CODE) Com_GwSignalOfPduHandle(
    PduIdType TxPduId,
    Com_TransferPropertyType SignalTxProperty,
    uint16 RptNum,
    boolean ValueChanged);
#endif
/* called by Com_GwNotArraySignal,Com_GwUint8NSignal,Com_GwUint8DYNSignal.
 * gateway pdu(which include gateway group signal) handle*/
#if ((0u < COM_TXGROUPSIGNAL_NUMBER) && (0u < COM_TXSIGNALGROUP_NUMBER))
static FUNC(void, COM_CODE) Com_GwGroupSignalOfPduHandle(
    Com_SignalGroupIdType TxSignalGroupId,
    Com_SignalIdType TxGroupSignalId,
    uint16 RptNum,
    boolean ValueChanged);
#endif
/* called by Com_GwUint8DYNSignal.
 * gateway uint8_dyn signal handle*/
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)                                                                          \
    && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
        || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE))
static FUNC(uint16, COM_CODE) Com_GwUint8DYNSignalHandle(
    uint16 SignalBufferId,
    uint16 SignalLength,
    Com_GwUint8DynSignalType* Parameter,
    boolean* valueChanged);
#endif
/*Called by Com_GwNotArraySignal.
 *Get the GW Signal's New value and Old value*/
static FUNC(uint64, COM_CODE) Com_GwSignalNewOldValueGet(
    Com_SignalType SignalType,
    uint16 GWSignalBufferId,
    uint16 txSignalValueId,
    uint64* sourceSignalValue);
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/******************************************************************************/
/*
 * Brief               Called by Com_MainFunctionRouteSignals.
 *                     gateway signal/group signal/signal group/description signal
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      GWMappingId,GWSourceSignalType,GWSourceSignalId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, COM_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Com_GwSignal(Com_SignalIdType GWMappingId, Com_GWSignalType GWSourceSignalType, Com_SignalIdType GWSourceSignalId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    Com_SignalIdType gwDestNumber;
    Com_SignalIdType gwDestCounter;
    Com_SignalType signalType;
    uint16 gwSignalBufferId;
    Com_GWSignalType gwDestSignalType;
    Com_SignalIdType gwDestSignalId;
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)
    uint16 signalLength;
    uint16 rxIpduId;
#endif
#if ((0u < COM_RXGROUPSIGNAL_NUMBER) && (0u < COM_GWSIGNAL_8BITBUFF_SIZE))
    const Com_RxGroupSignalType* rxGroupSignalPtr;
#endif
    const Com_GwDestType* gwDestPtr;
#if (0u < COM_GW_SOURCE_DESCRIPTION_NUMBER)
    const Com_GwSourceSignalType* gwSourceSignalPtr;
#endif /*0u < COM_GW_SOURCE_DESCRIPTION_NUMBER*/
    const Com_RxSignalType* rxSignalPtr;
    const Com_GwMappingType* gwMappingPtr = &Com_ConfigStd->ComGwMapping[GWMappingId];

    switch (GWSourceSignalType)
    {
#if (0u < COM_RXSIGNAL_NUMBER)
    case COM_SIGNAL:
        rxSignalPtr = &Com_ConfigStd->ComRxSignal[GWSourceSignalId];
        signalType = rxSignalPtr->ComSignalType;
        gwSignalBufferId = rxSignalPtr->GWSignalBufferId;
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE) \
    && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE))
        if ((COM_UINT8_N == signalType) || (COM_UINT8_DYN == signalType))
        {
            rxIpduId = rxSignalPtr->ComIpduRefIndex;
            signalLength = (COM_UINT8_N == signalType) ? (rxSignalPtr->ComSignalLength)
                                                       : (Com_RxIPduRunTimeState[rxIpduId].GWDynamicSignalLength);
        }
#endif /* #if (0u < COM_GWSIGNAL_8BITBUFF_SIZE) && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == \
          COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)) */
        break;

#endif /* (0u < COM_RXSIGNAL_NUMBER) */
#if (0u < COM_RXGROUPSIGNAL_NUMBER)
    case COM_GROUP_SIGNAL:
        rxGroupSignalPtr = &Com_ConfigStd->ComRxGroupSignal[GWSourceSignalId];
        signalType = rxGroupSignalPtr->ComSignalType;
        gwSignalBufferId = rxGroupSignalPtr->GWSignalBufferId;
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE) \
    && ((STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE))
        if ((COM_UINT8_N == signalType) || (COM_UINT8_DYN == signalType))
        {
            rxIpduId = Com_ConfigStd->ComRxSignalGroup[rxGroupSignalPtr->ComSignalGroupRef].ComIpduRefIndex;
            signalLength = (COM_UINT8_N == signalType) ? (rxGroupSignalPtr->ComSignalLength)
                                                       : (Com_RxIPduRunTimeState[rxIpduId].GWDynamicSignalLength);
        }
#endif /* #if (0u < COM_GWSIGNAL_8BITBUFF_SIZE) && ((STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == \
          COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE)) */
        break;
#endif /* (0u < COM_RXGROUPSIGNAL_NUMBER) */
#if (0u < COM_GW_SOURCE_DESCRIPTION_NUMBER)
    case COM_DESCRIPTION:
        gwSourceSignalPtr = &Com_ConfigStd->ComSourceSignal[GWSourceSignalId];
        signalType = gwSourceSignalPtr->ComSignalType;
        gwSignalBufferId = gwSourceSignalPtr->GWSignalBufferId;
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE) \
    && ((STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE))
        if ((COM_UINT8_N == signalType) || (COM_UINT8_DYN == signalType))
        {
            rxIpduId = gwSourceSignalPtr->ComGwIPduRef;
            signalLength = (COM_UINT8_N == signalType) ? (gwSourceSignalPtr->ComSignalLength)
                                                       : (Com_RxIPduRunTimeState[rxIpduId].GWDynamicSignalLength);
        }
#endif /* #if (0u < COM_GWSIGNAL_8BITBUFF_SIZE) && ((STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE) || (STD_ON == \
          COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE)) */
        break;
#endif /*0u < COM_GW_SOURCE_DESCRIPTION_NUMBER*/
    default:
        /*do nothing*/
        break;
    }

    gwDestNumber = gwMappingPtr->ComGwDestNumber;
    for (gwDestCounter = 0u; gwDestCounter < gwDestNumber; gwDestCounter++)
    {
        gwDestPtr = &gwMappingPtr->ComGwDest[gwDestCounter];
        gwDestSignalType = gwDestPtr->ComGwDestSignalType;
        gwDestSignalId = gwDestPtr->ComGwDestSignalId;
/*Except COM_UINT8_N,COM_UINT8_DYN Type Signal*/
#if (                                                                                                           \
    (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)            \
    || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
    || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE))
        if ((COM_UINT8_N != signalType) && (COM_UINT8_DYN != signalType))
#endif /* #if ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) ||    \
          (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) || \
          (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE)) \
        */
        {
            Com_GwNotArraySignal(signalType, gwSignalBufferId, gwDestSignalType, gwDestSignalId);
        }
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)                                                                               \
    && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE)            \
        || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
        || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE))
        /*COM_UINT8_N or COM_UINT8_DYN Type Signal*/
        else
        {
#if (                                                                                                  \
    (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) \
    || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE))
            if (COM_UINT8_N == signalType)
            {
                Com_GwUint8NSignal(gwSignalBufferId, signalLength, gwDestSignalType, gwDestSignalId);
            }
#endif /* #if ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || \
          (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE)) */
#if (                                                                                                      \
    (STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
    || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE))
            if (COM_UINT8_DYN == signalType)
            {
                Com_GwUint8DYNSignal(gwSignalBufferId, signalLength, gwDestSignalType, gwDestSignalId);
            }
#endif /* #if ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
          || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE)) */
        }
#endif /* #if (0u < COM_GWSIGNAL_8BITBUFF_SIZE) && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON ==        \
          COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON ==      \
          COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE) || (STD_ON == \
          COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE)) */
    }
    return;
}
#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/******************************************************************************/
/*
 * Brief               Called by Com_GwSignal.
 *                     gateway signal/group signal/description signal which
 *                     signal type isn't COM_UINT8_N and COM_UINT8_DYN
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalType,GWSignalBufferId,DestSignalType,
 *                     DestSignalId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, COM_CODE) Com_GwNotArraySignal(
    Com_SignalType SignalType,
    uint16 GWSignalBufferId,
    Com_GWSignalType DestSignalType,
    Com_SignalIdType DestSignalId)
{
    boolean valueChanged = FALSE;
    uint64 sourceSignalValue = 0u;
    uint64 destSignalValue;
    PduIdType txPduId = 0u;
    uint16 txSignalValueId = 0u;
    uint32 updateBitPosition = COM_UNUSED_UINT32;
    Com_TransferPropertyType signalTxProperty;
#if (0u < COM_TMCTXSIGNAL_NUMBER)
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) comFilter = NULL_PTR;
#endif
    uint16 rptNum;
#if ((0u < COM_TXGROUPSIGNAL_NUMBER) && (0u < COM_TXSIGNALGROUP_NUMBER))
    Com_SignalGroupIdType txSignalGroupId;
    const Com_TxGroupSignalType* txGroupSignalPtr;
#endif
#if ((0u < COM_TXSIGNAL_NUMBER) || (0u < COM_GW_DESTINATION_DESCRIPTION_NUMBER))
    const Com_TxSignalType* txSignalPtr;
    const Com_GwDestSignalType* gwDestSignalPtr;
#endif
    Com_Pack_Parameter PackParameter;
    switch (DestSignalType)
    {
#if (0u < COM_TXSIGNAL_NUMBER)
    case COM_SIGNAL:
        txSignalPtr = &Com_ConfigStd->ComTxSignal[DestSignalId];
        txSignalValueId = txSignalPtr->ComSignalInitValueId;
        txPduId = txSignalPtr->ComIpduRefIndex;
        updateBitPosition = txSignalPtr->ComUpdateBitPosition;
        signalTxProperty = txSignalPtr->ComTransferProperty;
#if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE)
        comFilter = txSignalPtr->ComFilter;
#endif /* #if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE) */
        PackParameter.TxIpduId = txPduId;
        PackParameter.BitPosition = txSignalPtr->ComBitPosition;
        PackParameter.SignalType = txSignalPtr->ComSignalType;
        PackParameter.SignalEndianness = txSignalPtr->ComSignalEndianness;
        PackParameter.BitSize = txSignalPtr->ComBitSize;
        PackParameter.SignalByteLength = txSignalPtr->ComSignalByteLength;
        break;
#endif
#if ((0u < COM_TXGROUPSIGNAL_NUMBER) && (0u < COM_TXSIGNALGROUP_NUMBER))
    case COM_GROUP_SIGNAL:
        txGroupSignalPtr = &Com_ConfigStd->ComTxGroupSignal[DestSignalId];
        txSignalValueId = txGroupSignalPtr->ComSignalInitValueId;
        txSignalGroupId = txGroupSignalPtr->ComSignalGroupRef;
        txPduId = Com_ConfigStd->ComTxSignalGroup[txSignalGroupId].ComIpduRefIndex;
        updateBitPosition = Com_ConfigStd->ComTxSignalGroup[txSignalGroupId].ComUpdateBitPosition;
#if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE)
        comFilter = txGroupSignalPtr->ComFilter;
#endif /* #if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE) */
        PackParameter.TxIpduId = txPduId;
        PackParameter.BitPosition = txGroupSignalPtr->ComBitPosition;
        PackParameter.SignalType = txGroupSignalPtr->ComSignalType;
        PackParameter.SignalEndianness = txGroupSignalPtr->ComSignalEndianness;
        PackParameter.BitSize = txGroupSignalPtr->ComBitSize;
        PackParameter.SignalByteLength = txGroupSignalPtr->ComSignalByteLength;
        break;
#endif
#if (0u < COM_GW_DESTINATION_DESCRIPTION_NUMBER)
    case COM_DESCRIPTION:
        gwDestSignalPtr = &Com_ConfigStd->ComDestSignal[DestSignalId];
        txSignalValueId = gwDestSignalPtr->ComSignalInitValueId;
        txPduId = gwDestSignalPtr->ComGwIPduRef;
        updateBitPosition = gwDestSignalPtr->ComUpdateBitPosition;
        signalTxProperty = gwDestSignalPtr->ComTransferProperty;
#if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE)
        comFilter = gwDestSignalPtr->ComFilter;
#endif /* #if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE) */
        PackParameter.TxIpduId = txPduId;
        PackParameter.BitPosition = gwDestSignalPtr->ComBitPosition;
        PackParameter.SignalType = gwDestSignalPtr->ComSignalType;
        PackParameter.SignalEndianness = gwDestSignalPtr->ComSignalEndianness;
        PackParameter.BitSize = gwDestSignalPtr->ComBitSize;
        PackParameter.SignalByteLength = gwDestSignalPtr->ComSignalByteLength;
        break;
#endif
    default:
        /*do nothing*/
        break;
    }
    destSignalValue = Com_GwSignalNewOldValueGet(SignalType, GWSignalBufferId, txSignalValueId, &sourceSignalValue);
    if (sourceSignalValue != destSignalValue)
    {
        valueChanged = TRUE;
/*pack the new value*/
#if (0u < COM_TXIPDUBUFF_SIZE)
        Com_DestSignalPack(&PackParameter, sourceSignalValue);
#endif
    }
#if (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
    /*if configuration update bit,set update bit to 1*/
    Com_SetSignalUpdateBit(txPduId, updateBitPosition);
#endif /* (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE) */
#if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE)
    if (NULL_PTR != comFilter)
    {
        /*calculate the TMC of the signal*/
        TxSignalTMCRunTime[comFilter->ComTMCBufferId] =
            Com_DestSignalTMCCalculate(SignalType, comFilter, sourceSignalValue, destSignalValue);
    }
#endif /* (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON== COM_TMS_ENABLE) */
    /*calculate the TMS,store new Tx mode,get rptNum value for DIRECT/MIXED tx mode,if TMS changed will reset periodic
     * mode counter.*/
    Com_TxIpduTMSHandle(txPduId, &rptNum);
    switch (DestSignalType)
    {
#if (0u < COM_TXSIGNAL_NUMBER)
    case COM_SIGNAL:
        /*handle the tx pdu (which include the gateway signal) transmit parameter*/
        Com_GwSignalOfPduHandle(txPduId, signalTxProperty, rptNum, valueChanged);
/*the tx signal configuration timeout*/
#if (STD_ON == COM_TX_SIGNAL_TIMEOUT_ENABLE)
        if (0u != txSignalPtr->ComTimeout)
        {
            if ((0u == Com_TxIPduRunTimeState[txPduId].DMCnt) || (1u < Com_TxIPduRunTimeState[txPduId].RptNum))
            {
                Com_TxIPduRunTimeState[txPduId].DMCnt = Com_ConfigStd->ComTxIPdu[txPduId].ComTxIpduDM;
            }
        }
#endif /* #if (STD_ON == COM_TX_SIGNAL_TIMEOUT_ENABLE) */
        break;
#endif
#if ((0u < COM_TXGROUPSIGNAL_NUMBER) && (0u < COM_TXSIGNALGROUP_NUMBER))
    case COM_GROUP_SIGNAL:
        /*handle the tx pdu (which include the gateway group signal) transmit parameter*/
        Com_GwGroupSignalOfPduHandle(txSignalGroupId, DestSignalId, rptNum, valueChanged);
/*the tx signal group(include the gateway group signal)configuration timeout*/
#if (STD_ON == COM_TX_SIG_GROUP_TIMEOUT_ENABLE)
        if (0u != Com_ConfigStd->ComTxSignalGroup[txSignalGroupId].ComTimeout)
        {
            if ((0u == Com_TxIPduRunTimeState[txPduId].DMCnt) || (1u < Com_TxIPduRunTimeState[txPduId].RptNum))
            {
                Com_TxIPduRunTimeState[txPduId].DMCnt = Com_ConfigStd->ComTxIPdu[txPduId].ComTxIpduDM;
            }
        }
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_TIMEOUT_ENABLE) */
        break;
#endif
#if (0u < COM_GW_DESTINATION_DESCRIPTION_NUMBER)
    case COM_DESCRIPTION:
        /*handle the tx pdu (which include the gateway signal) transmit parameter*/
        Com_GwSignalOfPduHandle(txPduId, signalTxProperty, rptNum, valueChanged);
        break;
#endif
    default:
        /*do nothing*/
        break;
    }
    return;
}
/******************************************************************************/
/*
 * Brief               Called by Com_GwSignal.
 *                     gateway signal/group signal/description signal which
 *                     signal type is COM_UINT8_N
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalBufferId,SignalLength,DestSignalType,
 *                     DestSignalId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
/* called by Com_GwSignal.
 * gateway signal/group signal/description signal which signal type is COM_UINT8_N*/
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)                                                                      \
    && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) \
        || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE))
static FUNC(void, COM_CODE) Com_GwUint8NSignal(
    uint16 SignalBufferId,
    uint16 SignalLength,
    Com_GWSignalType DestSignalType,
    Com_SignalIdType DestSignalId)
{
#if (0u < COM_TXIPDUBUFF_SIZE)
    boolean valueChanged = FALSE;
    uint16 cnt;
    PduIdType txPduId;
    uint16 txIPduBufId;
    uint32 destSignalBitPosition;
    uint32 updateBitPosition;
    uint16 rptNum;
#if ((0u < COM_TXSIGNAL_NUMBER) || (0u < COM_GW_DESTINATION_DESCRIPTION_NUMBER))
    Com_TransferPropertyType signalTxProperty;
    const Com_TxSignalType* txSignalPtr;
    const Com_GwDestSignalType* gwDestSignalPtr;
#endif
#if ((0u < COM_TXGROUPSIGNAL_NUMBER) && (COM_TXSIGNALGROUP_NUMBER))
    Com_SignalGroupIdType txSignalGroupId;
    const Com_TxSignalGroupType* txSignalGroupPtr;
    const Com_TxGroupSignalType* txGroupSignalPtr;
#endif
    uint16 txIPduBuffPos;
    switch (DestSignalType)
    {
#if (0u < COM_TXSIGNAL_NUMBER)
    case COM_SIGNAL:
        txSignalPtr = &Com_ConfigStd->ComTxSignal[DestSignalId];
        txPduId = txSignalPtr->ComIpduRefIndex;
        destSignalBitPosition = txSignalPtr->ComBitPosition;
        updateBitPosition = txSignalPtr->ComUpdateBitPosition;
        txIPduBufId = Com_ConfigStd->ComTxIPdu[txPduId].ComTxIPduBufIndex;
        txIPduBuffPos = txIPduBufId + (uint16)(destSignalBitPosition >> 3u);
        for (cnt = 0u; cnt < SignalLength; cnt++)
        {
            if ((Com_TxIPduRuntimeBuff[txIPduBuffPos + cnt]) != (Com_GWSignal8BitBuff[SignalBufferId + cnt]))
            {
                valueChanged = TRUE;
                Com_TxIPduRuntimeBuff[txIPduBuffPos + cnt] = Com_GWSignal8BitBuff[SignalBufferId + cnt];
            }
        }
#if (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
        /*if configuration update bit,set update bit to 1*/
        Com_SetSignalUpdateBit(txPduId, updateBitPosition);
#endif /* (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE) */
        /*calculate the TMS,store new Tx mode,get rptNum value for DIRECT/MIXED tx mode,if TMS changed will reset
         * periodic mode counter.*/
        Com_TxIpduTMSHandle(txPduId, &rptNum);
        signalTxProperty = txSignalPtr->ComTransferProperty;
        /*handle the tx pdu (which include the gateway signal) transmit parameter*/
        Com_GwSignalOfPduHandle(txPduId, signalTxProperty, rptNum, valueChanged);
/*the tx signal configuration timeout*/
#if (STD_ON == COM_TX_SIGNAL_TIMEOUT_ENABLE)
        if (0u != txSignalPtr->ComTimeout)
        {
            if ((0u == Com_TxIPduRunTimeState[txPduId].DMCnt) || (1u < Com_TxIPduRunTimeState[txPduId].RptNum))
            {
                Com_TxIPduRunTimeState[txPduId].DMCnt = Com_ConfigStd->ComTxIPdu[txPduId].ComTxIpduDM;
            }
        }
#endif /* #if (STD_ON == COM_TX_SIGNAL_TIMEOUT_ENABLE) */
        break;
#endif
#if ((0u < COM_TXGROUPSIGNAL_NUMBER) && (0u < COM_TXSIGNALGROUP_NUMBER))
    case COM_GROUP_SIGNAL:
        txGroupSignalPtr = &Com_ConfigStd->ComTxGroupSignal[DestSignalId];
        txSignalGroupId = txGroupSignalPtr->ComSignalGroupRef;
        txSignalGroupPtr = &Com_ConfigStd->ComTxSignalGroup[txSignalGroupId];
        txPduId = txSignalGroupPtr->ComIpduRefIndex;
        destSignalBitPosition = txGroupSignalPtr->ComBitPosition;
        updateBitPosition = txSignalGroupPtr->ComUpdateBitPosition;
        txIPduBufId = Com_ConfigStd->ComTxIPdu[txPduId].ComTxIPduBufIndex;
        txIPduBuffPos = txIPduBufId + (uint16)(destSignalBitPosition >> 3u);
        for (cnt = 0u; cnt < SignalLength; cnt++)
        {
            if ((Com_TxIPduRuntimeBuff[txIPduBuffPos + cnt]) != (Com_GWSignal8BitBuff[SignalBufferId + cnt]))
            {
                valueChanged = TRUE;
                Com_TxIPduRuntimeBuff[txIPduBuffPos + cnt] = Com_GWSignal8BitBuff[SignalBufferId + cnt];
            }
        }
#if (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
        /*if configuration update bit,set update bit to 1*/
        Com_SetSignalUpdateBit(txPduId, updateBitPosition);
#endif /* (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE) */
        /*calculate the TMS,store new Tx mode,get rptNum value for DIRECT/MIXED tx mode,if TMS changed will reset
         * periodic mode counter.*/
        Com_TxIpduTMSHandle(txPduId, &rptNum);
        /*handle the tx pdu (which include the gateway group signal) transmit parameter*/
        Com_GwGroupSignalOfPduHandle(txSignalGroupId, DestSignalId, rptNum, valueChanged);
/*the tx signal group(include the gateway group signal)configuration timeout*/
#if (STD_ON == COM_TX_SIG_GROUP_TIMEOUT_ENABLE)
        if (0u != txSignalGroupPtr->ComTimeout)
        {
            if ((0u == Com_TxIPduRunTimeState[txPduId].DMCnt) || (1u < Com_TxIPduRunTimeState[txPduId].RptNum))
            {
                Com_TxIPduRunTimeState[txPduId].DMCnt = Com_ConfigStd->ComTxIPdu[txPduId].ComTxIpduDM;
            }
        }
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_TIMEOUT_ENABLE) */
        break;
#endif
#if (0u < COM_GW_DESTINATION_DESCRIPTION_NUMBER)
    case COM_DESCRIPTION:
        gwDestSignalPtr = &Com_ConfigStd->ComDestSignal[DestSignalId];
        txPduId = gwDestSignalPtr->ComGwIPduRef;
        destSignalBitPosition = gwDestSignalPtr->ComBitPosition;
        updateBitPosition = gwDestSignalPtr->ComUpdateBitPosition;
        txIPduBufId = Com_ConfigStd->ComTxIPdu[txPduId].ComTxIPduBufIndex;
        txIPduBuffPos = txIPduBufId + (uint16)(destSignalBitPosition >> 3u);
        for (cnt = 0u; cnt < SignalLength; cnt++)
        {
            if ((Com_TxIPduRuntimeBuff[txIPduBuffPos + cnt]) != (Com_GWSignal8BitBuff[SignalBufferId + cnt]))
            {
                valueChanged = TRUE;
                Com_TxIPduRuntimeBuff[txIPduBuffPos + cnt] = Com_GWSignal8BitBuff[SignalBufferId + cnt];
            }
        }
#if (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
        /*if configuration update bit,set update bit to 1*/
        Com_SetSignalUpdateBit(txPduId, updateBitPosition);
#endif /* (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE) */
        /*calculate the TMS,store new Tx mode,get rptNum value for DIRECT/MIXED tx mode,if TMS changed will reset
         * periodic mode counter.*/
        Com_TxIpduTMSHandle(txPduId, &rptNum);
        signalTxProperty = gwDestSignalPtr->ComTransferProperty;
        /*handle the tx pdu (which include the gateway description signal) transmit parameter*/
        Com_GwSignalOfPduHandle(txPduId, signalTxProperty, rptNum, valueChanged);
        break;
#endif
    default:
        /*do nothing*/
        break;
    }
#endif
    return;
}
#endif /*#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE) && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == \
          COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE) || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE)) */
/******************************************************************************/
/*
 * Brief               Called by Com_GwSignal.
 *                     gateway signal/group signal/description signal which
 *                     signal type is COM_UINT8_DYN
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalBufferId,SignalLength,DestSignalType,
 *                     DestSignalId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)                                                                          \
    && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
        || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE))
static FUNC(void, COM_CODE) Com_GwUint8DYNSignal(
    uint16 SignalBufferId,
    uint16 SignalLength,
    Com_GWSignalType DestSignalType,
    Com_SignalIdType DestSignalId)
{
#if (0u < COM_TXIPDUBUFF_SIZE)
    boolean valueChanged = FALSE;
    PduIdType txPduId;
    Com_GwUint8DynSignalType parameter;
    uint16 rptNum;
#if ((0u < COM_TXSIGNAL_NUMBER) || (0u < COM_GW_DESTINATION_DESCRIPTION_NUMBER))
    Com_TransferPropertyType signalTxProperty;
    const Com_TxSignalType* txSignalPtr;
    const Com_GwDestSignalType* gwDestSignalPtr;
#endif
#if ((0u < COM_TXGROUPSIGNAL_NUMBER) && (COM_TXSIGNALGROUP_NUMBER))
    Com_SignalGroupIdType txSignalGroupId;
    const Com_TxSignalGroupType* txSignalGroupPtr;
    const Com_TxGroupSignalType* txGroupSignalPtr;
#endif
    switch (DestSignalType)
    {
#if (0u < COM_TXSIGNAL_NUMBER)
    case COM_SIGNAL:
        txSignalPtr = &Com_ConfigStd->ComTxSignal[DestSignalId];
        txPduId = txSignalPtr->ComIpduRefIndex;
        parameter.TxPduId = txPduId;
        parameter.DestSignalBitPosition = txSignalPtr->ComBitPosition;
        parameter.UpdateBitPosition = txSignalPtr->ComUpdateBitPosition;
        rptNum = Com_GwUint8DYNSignalHandle(SignalBufferId, SignalLength, &parameter, &valueChanged);
        signalTxProperty = txSignalPtr->ComTransferProperty;
        /*handle the tx pdu (which include the gateway signal) transmit parameter*/
        Com_GwSignalOfPduHandle(txPduId, signalTxProperty, rptNum, valueChanged);
/*the tx signal configuration timeout*/
#if (STD_ON == COM_TX_SIGNAL_TIMEOUT_ENABLE)
        if (0u != txSignalPtr->ComTimeout)
        {
            if ((0u == Com_TxIPduRunTimeState[txPduId].DMCnt) || (1u < Com_TxIPduRunTimeState[txPduId].RptNum))
            {
                Com_TxIPduRunTimeState[txPduId].DMCnt = Com_ConfigStd->ComTxIPdu[txPduId].ComTxIpduDM;
            }
        }
#endif /* #if (STD_ON == COM_TX_SIGNAL_TIMEOUT_ENABLE) */
        break;
#endif
#if ((0u < COM_TXGROUPSIGNAL_NUMBER) && (0u < COM_TXSIGNALGROUP_NUMBER))
    case COM_GROUP_SIGNAL:
        txGroupSignalPtr = &Com_ConfigStd->ComTxGroupSignal[DestSignalId];
        txSignalGroupId = txGroupSignalPtr->ComSignalGroupRef;
        txSignalGroupPtr = &Com_ConfigStd->ComTxSignalGroup[txSignalGroupId];
        txPduId = txSignalGroupPtr->ComIpduRefIndex;
        parameter.TxPduId = txPduId;
        parameter.DestSignalBitPosition = txGroupSignalPtr->ComBitPosition;
        parameter.UpdateBitPosition = txSignalGroupPtr->ComUpdateBitPosition;
        rptNum = Com_GwUint8DYNSignalHandle(SignalBufferId, SignalLength, &parameter, &valueChanged);
        /*handle the tx pdu (which include the gateway group signal) transmit parameter*/
        Com_GwGroupSignalOfPduHandle(txSignalGroupId, DestSignalId, rptNum, valueChanged);
/*the tx signal group(include the gateway group signal)configuration timeout*/
#if (STD_ON == COM_TX_SIG_GROUP_TIMEOUT_ENABLE)
        if (0u != txSignalGroupPtr->ComTimeout)
        {
            if ((0u == Com_TxIPduRunTimeState[txPduId].DMCnt) || (1u < Com_TxIPduRunTimeState[txPduId].RptNum))
            {
                Com_TxIPduRunTimeState[txPduId].DMCnt = Com_ConfigStd->ComTxIPdu[txPduId].ComTxIpduDM;
            }
        }
#endif /* #if (STD_ON == COM_TX_SIG_GROUP_TIMEOUT_ENABLE) */
        break;
#endif
#if (0u < COM_GW_DESTINATION_DESCRIPTION_NUMBER)
    case COM_DESCRIPTION:
        gwDestSignalPtr = &Com_ConfigStd->ComDestSignal[DestSignalId];
        txPduId = gwDestSignalPtr->ComGwIPduRef;
        parameter.TxPduId = txPduId;
        parameter.DestSignalBitPosition = gwDestSignalPtr->ComBitPosition;
        parameter.UpdateBitPosition = gwDestSignalPtr->ComUpdateBitPosition;
        rptNum = Com_GwUint8DYNSignalHandle(SignalBufferId, SignalLength, &parameter, &valueChanged);
        signalTxProperty = gwDestSignalPtr->ComTransferProperty;
        /*handle the tx pdu (which include the gateway description signal) transmit parameter*/
        Com_GwSignalOfPduHandle(txPduId, signalTxProperty, rptNum, valueChanged);
        break;
#endif
    default:
        /*do nothing*/
        break;
    }
#endif /*0u < COM_TXIPDUBUFF_SIZE*/
    return;
}
#endif /* #if (0u < COM_GWSIGNAL_8BITBUFF_SIZE) && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == \
          COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE)) */
/******************************************************************************/
/*
 * Brief               Called by Com_GwNotArraySignal.
 *                     gateway dest signal is packed to dest tx pdu buffer
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      PackPara,SignalValue
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (0u < COM_TXIPDUBUFF_SIZE)
static FUNC(void, COM_CODE) Com_DestSignalPack(Com_Pack_Parameter* PackPara, uint64 SignalValue)
{
    uint32 bitPosition = PackPara->BitPosition;
    uint16 ipduBufferIndex = Com_ConfigStd->ComTxIPdu[PackPara->TxIpduId].ComTxIPduBufIndex;
#if ((0u < COM_TXGROUPSIGNAL_NUMBER) && (COM_TXSIGNALGROUP_NUMBER))
    Com_SignalGroupIdType signalGroupId;
#endif
    uint8 bitSize = PackPara->BitSize;
    uint8 signalByteLength;
    uint64 dataMSBByte;
    Com_TxSignalPackType parameter;
    uint8 bitPosInByte = (uint8)(bitPosition & 0x07u);
    uint16 ipduBufferPos = ipduBufferIndex + (uint16)(bitPosition >> 3u);

    if (COM_BOOLEAN == PackPara->SignalType)
    {
        if (0u < SignalValue)
        {
            Com_TxIPduRuntimeBuff[ipduBufferPos] |= (uint8)(0x01u << bitPosInByte);
        }
        else
        {
            Com_TxIPduRuntimeBuff[ipduBufferPos] &= (uint8)(~(uint8)(0x01u << bitPosInByte));
        }
    }
    else
    {
        /* signal MSB byte value used for the signal value bits cover 9 bytes */
        dataMSBByte = SignalValue;
        /* Align LSB of txData and signal_value in IPdu */
        SignalValue = SignalValue << bitPosInByte;
        /*signalByteLength:1-9*/
        signalByteLength = PackPara->SignalByteLength;
        /*the tx signal all value bits are in one byte*/
        if (1u == signalByteLength)
        {
            /*Clear corresponding bits in IPdu*/
            Com_TxIPduRuntimeBuff[ipduBufferPos] &=
                (0xFFu >> (8u - bitPosInByte)) | (uint8)(0xFFu << (bitPosInByte + bitSize));
            /*write corresponding bits to IPdu buffer*/
            Com_TxIPduRuntimeBuff[ipduBufferPos] |= (0xFFu >> (8u - (bitPosInByte + bitSize))) & ((uint8)SignalValue);
        }
        /*the tx signal all value bits are included in 2-9 byte*/
        else if ((1u < signalByteLength) && (signalByteLength < 10u))
        {
            parameter.SignalByteLength = signalByteLength;
            parameter.SignalEndianness = PackPara->SignalEndianness;
            parameter.IpduBufferIndex = ipduBufferIndex;
            parameter.BitPosition = bitPosition;
            parameter.BitSize = bitSize;
            Com_TxSignalPackHandle(&parameter, SignalValue, dataMSBByte);
        }
        /*this case will not happen*/
        else
        {
            /*do nothing*/
        }
    }
    return;
}
#endif /*0u < COM_TXIPDUBUFF_SIZE*/
/******************************************************************************/
/*
 * Brief               Called by Com_GwNotArraySignal.
 *                     calculate dest signal/group signal/description signal TMC
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalType,ComFilter,NewSignalValue,OldSignalValue
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              boolean
 */
/******************************************************************************/
#if (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON == COM_TMS_ENABLE)
static FUNC(boolean, COM_CODE) Com_DestSignalTMCCalculate(
    Com_SignalType SignalType,
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
    uint64 NewSignalValue,
    uint64 OldSignalValue)
{
    boolean ret = FALSE;
    Com_FilterAlgorithmType filterType = ComFilter->ComFilterAlgorithm;
#if (COM_ONEEVERYNFILTERSIGNAL_NUMBER > 0u)
    Com_SignalIdType oneEveryNId;
    uint32 filterOffset;
    uint32 filterPeriod;
#endif

    switch (filterType)
    {
    case COM_ALWAYS:
        ret = TRUE;
        break;
    case COM_MASKED_NEW_EQUALS_X:
        if (((NewSignalValue) & (ComFilter->ComFilterMask)) == (ComFilter->ComFilterX))
        {
            ret = TRUE;
        }
        break;
    case COM_MASKED_NEW_DIFFERS_X:
        if (((NewSignalValue) & (ComFilter->ComFilterMask)) != (ComFilter->ComFilterX))
        {
            ret = TRUE;
        }
        break;
    /*COM_BOOLEAN not support WITHIN and WITHOUT*/
    case COM_NEW_IS_WITHIN:
        Com_NewIsWithinFilterCalculate(SignalType, NewSignalValue, ComFilter, &ret);
        break;
    /*COM_BOOLEAN not support WITHIN and WITHOUT*/
    case COM_NEW_IS_OUTSIDE:
        Com_NewIsWithoutFilterCalculate(SignalType, NewSignalValue, ComFilter, &ret);
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
        if (((NewSignalValue) & (ComFilter->ComFilterMask)) != ((OldSignalValue) & (ComFilter->ComFilterMask)))
        {
            ret = TRUE;
        }
        break;
    default:
        /*do nothing*/
        break;
    }
    return ret;
}
#endif /* (0u < COM_TMCTXSIGNAL_NUMBER) && (STD_ON== COM_TMS_ENABLE) */
/******************************************************************************/
/*
 * Brief               Called by Com_GwNotArraySignal,Com_GwUint8NSignal,
 *                     Com_GwUint8DYNSignal.
 *                     gateway pdu(which include gateway signal) handle
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxPduId,SignalTxProperty,RptNum,ValueChanged
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((0u < COM_TXSIGNAL_NUMBER) || (0u < COM_GW_DESTINATION_DESCRIPTION_NUMBER))
static FUNC(void, COM_CODE) Com_GwSignalOfPduHandle(
    PduIdType TxPduId,
    Com_TransferPropertyType SignalTxProperty,
    uint16 RptNum,
    boolean ValueChanged)
{
    Com_TxIPduRunTimeStateType* txIpduStatePtr = &Com_TxIPduRunTimeState[TxPduId];
    Com_TxModeModeType ipduTxMode = txIpduStatePtr->ipduTxMode;

#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) || (STD_ON == COM_TX_MODE_MIXED_ENABLE)
    if ((COM_TX_MODE_DIRECT == ipduTxMode) || (COM_TX_MODE_MIXED == ipduTxMode))
    {
        switch (SignalTxProperty)
        {
        case COM_TRIGGERED:
            txIpduStatePtr->NTimeCnt = 0u;
            txIpduStatePtr->RptNum = RptNum;
            break;
        case COM_TRIGGERED_ON_CHANGE:
            if (TRUE == ValueChanged)
            {
                txIpduStatePtr->NTimeCnt = 0u;
                txIpduStatePtr->RptNum = RptNum;
            }
            break;
        case COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
            if (TRUE == ValueChanged)
            {
                txIpduStatePtr->NTimeCnt = 0u;
                txIpduStatePtr->RptNum = 1u;
            }
            break;
        case COM_TRIGGERED_WITHOUT_REPETITION:
            txIpduStatePtr->NTimeCnt = 0u;
            txIpduStatePtr->RptNum = 1u;
            break;
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
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               Called by Com_GwNotArraySignal,Com_GwUint8NSignal,
 *                     Com_GwUint8DYNSignal.
 *                     gateway pdu(which include gateway group signal) handle
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxPduId,SignalGroupTxProperty,TxGroupSignalId,RptNum,
 *                     ValueChanged
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((0u < COM_TXGROUPSIGNAL_NUMBER) && (0u < COM_TXSIGNALGROUP_NUMBER))
static FUNC(void, COM_CODE) Com_GwGroupSignalOfPduHandle(
    Com_SignalGroupIdType TxSignalGroupId,
    Com_SignalIdType TxGroupSignalId,
    uint16 RptNum,
    boolean ValueChanged)
{
    const Com_TxSignalGroupType* txSignalGroupPtr = &Com_ConfigStd->ComTxSignalGroup[TxSignalGroupId];
    PduIdType txPduId = txSignalGroupPtr->ComIpduRefIndex;
    Com_TxIPduRunTimeStateType* txIpduStatePtr = &Com_TxIPduRunTimeState[txPduId];
    Com_TransferPropertyType signalGroupTxProperty;
    Com_TransferPropertyType signalTxProperty;
    Com_TxModeModeType ipduTxMode = txIpduStatePtr->ipduTxMode;

#if (STD_ON == COM_TX_MODE_DIRECT_ENABLE) || (STD_ON == COM_TX_MODE_MIXED_ENABLE)
    if ((COM_TX_MODE_DIRECT == ipduTxMode) || (COM_TX_MODE_MIXED == ipduTxMode))
    {
        signalGroupTxProperty = txSignalGroupPtr->ComTransferProperty;
        switch (signalGroupTxProperty)
        {
        case COM_TRIGGERED:
            txIpduStatePtr->NTimeCnt = 0u;
            txIpduStatePtr->RptNum = RptNum;
            break;
        case COM_TRIGGERED_ON_CHANGE:
            if (TRUE == Com_ConfigStd->ComTxGroupSignal[TxGroupSignalId].ComTxGroupSignalUsedTransferProperty)
            {
                signalTxProperty = Com_ConfigStd->ComTxGroupSignal[TxGroupSignalId].ComTransferProperty;
                if ((TRUE == ValueChanged) && (COM_TRIGGERED_ON_CHANGE == signalTxProperty))
                {
                    txIpduStatePtr->NTimeCnt = 0u;
                    txIpduStatePtr->RptNum = RptNum;
                }
            }
            else
            {
                if (TRUE == ValueChanged)
                {
                    txIpduStatePtr->NTimeCnt = 0u;
                    txIpduStatePtr->RptNum = RptNum;
                }
            }
            break;
        case COM_TRIGGERED_ON_CHANGE_WITHOUT_REPETITION:
            if (TRUE == ValueChanged)
            {
                txIpduStatePtr->NTimeCnt = 0u;
                txIpduStatePtr->RptNum = 1u;
            }
            break;
        case COM_TRIGGERED_WITHOUT_REPETITION:
            txIpduStatePtr->NTimeCnt = 0u;
            txIpduStatePtr->RptNum = 1u;
            break;
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
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               Called by Com_GwUint8DYNSignal.
 *                     gateway uint8_dyn signal handle
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalBufferId,SignalLength,parameter,valueChanged
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint16
 */
/******************************************************************************/
#if (0u < COM_GWSIGNAL_8BITBUFF_SIZE)                                                                          \
    && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) \
        || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE))
static FUNC(uint16, COM_CODE) Com_GwUint8DYNSignalHandle(
    uint16 SignalBufferId,
    uint16 SignalLength,
    Com_GwUint8DynSignalType* Parameter,
    boolean* valueChanged)
{
    PduIdType txPduId = Parameter->TxPduId;
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[txPduId];
    uint16 destSignalByteLength = (uint16)(Parameter->DestSignalBitPosition >> 3u);
    uint16 iPduNoDynSignalLength = (uint16)txIpduPtr->IPduNoDynSignalLength;
    uint16 destSignalLength = Com_TxIPduRunTimeState[txPduId].TxIpduLength - iPduNoDynSignalLength;
    uint16 txIPduBufId = txIpduPtr->ComTxIPduBufIndex + destSignalByteLength;
    uint16 rptNum;
    uint16 cnt;

    *valueChanged = FALSE;
    for (cnt = 0u; cnt < SignalLength; cnt++)
    {
        if ((Com_TxIPduRuntimeBuff[txIPduBufId + cnt]) != (Com_GWSignal8BitBuff[SignalBufferId + cnt]))
        {
            *valueChanged = TRUE;
            Com_TxIPduRuntimeBuff[txIPduBufId + cnt] = Com_GWSignal8BitBuff[SignalBufferId + cnt];
        }
    }
    if (SignalLength != destSignalLength)
    {
        *valueChanged = TRUE;
        Com_TxIPduRunTimeState[txPduId].TxIpduLength = iPduNoDynSignalLength + SignalLength;
    }
#if (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)
    /*if configuration update bit,set update bit to 1*/
    Com_SetSignalUpdateBit(txPduId, Parameter->UpdateBitPosition);
#endif /* (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE) */
    /*calculate the TMS,store new Tx mode,get rptNum value for DIRECT/MIXED tx mode,if TMS changed will reset
     * periodic mode counter.*/
    Com_TxIpduTMSHandle(txPduId, &rptNum);
    return rptNum;
}
#endif /* #if (0u < COM_GWSIGNAL_8BITBUFF_SIZE) && ((STD_ON == COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == \
          COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE) || (STD_ON == COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE)) */

/*Called by Com_GwNotArraySignal.
 *Get the GW Signal's New value and Old value*/
static FUNC(uint64, COM_CODE) Com_GwSignalNewOldValueGet(
    Com_SignalType SignalType,
    uint16 GWSignalBufferId,
    uint16 txSignalValueId,
    uint64* sourceSignalValue)
{
    uint64 destSignalValue = 0u;
    switch (SignalType)
    {
#if ((0u < COM_SIGNAL_BOOLBUFF_SIZE) && (0u < COM_GWSIGNAL_BOOLBUFF_SIZE))
    case COM_BOOLEAN:
        *sourceSignalValue = (uint64)Com_GWSignalBoolBuff[GWSignalBufferId];
        destSignalValue = (uint64)Com_SignalBoolRuntimeBuff[txSignalValueId];
        Com_SignalBoolRuntimeBuff[txSignalValueId] = Com_GWSignalBoolBuff[GWSignalBufferId];
        break;
#endif
#if ((0u < COM_SIGNAL_8BITBUFF_SIZE) && (0u < COM_GWSIGNAL_8BITBUFF_SIZE))
    case COM_UINT8:
    case COM_SINT8:
        *sourceSignalValue = (uint64)Com_GWSignal8BitBuff[GWSignalBufferId];
        destSignalValue = (uint64)Com_Signal8BitRuntimeBuff[txSignalValueId];
        Com_Signal8BitRuntimeBuff[txSignalValueId] = Com_GWSignal8BitBuff[GWSignalBufferId];
        break;
#endif
#if ((0u < COM_SIGNAL_16BITBUFF_SIZE) && (0u < COM_GWSIGNAL_16BITBUFF_SIZE))
    case COM_UINT16:
    case COM_SINT16:
        *sourceSignalValue = (uint64)Com_GWSignal16BitBuff[GWSignalBufferId];
        destSignalValue = (uint64)Com_Signal16BitRuntimeBuff[txSignalValueId];
        Com_Signal16BitRuntimeBuff[txSignalValueId] = Com_GWSignal16BitBuff[GWSignalBufferId];
        break;
#endif
#if ((0u < COM_SIGNAL_32BITBUFF_SIZE) && (0u < COM_GWSIGNAL_32BITBUFF_SIZE))
    case COM_UINT32:
    case COM_SINT32:
    case COM_FLOAT32:
        *sourceSignalValue = (uint64)Com_GWSignal32BitBuff[GWSignalBufferId];
        destSignalValue = (uint64)Com_Signal32BitRuntimeBuff[txSignalValueId];
        Com_Signal32BitRuntimeBuff[txSignalValueId] = Com_GWSignal32BitBuff[GWSignalBufferId];
        break;
#endif
#if ((0u < COM_SIGNAL_64BITBUFF_SIZE) && (0u < COM_GWSIGNAL_64BITBUFF_SIZE))
    case COM_UINT64:
    case COM_SINT64:
    case COM_FLOAT64:
        *sourceSignalValue = Com_GWSignal64BitBuff[GWSignalBufferId];
        destSignalValue = Com_Signal64BitRuntimeBuff[txSignalValueId];
        Com_Signal64BitRuntimeBuff[txSignalValueId] = Com_GWSignal64BitBuff[GWSignalBufferId];
        break;
#endif
    default:
        /*do nothing*/
        break;
    }
    return destSignalValue;
}

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"
#endif /*#if ((0u < COM_GWMAPPING_NUMBER) && (0u < COM_RXIPDU_NUMBER) && (0u < COM_TXIPDU_NUMBER) && (STD_ON == \
          COM_SIGNAL_GW_ENABLE))*/
