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
**  FILENAME    : Com_Internal.c                                              **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : COM internal API definitions                                **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Com_Internal.h"
#if (COM_MEMCPY_FUN_SELECT == COM_USE_STD_LIB_MEMCPY)
#include <string.h>
#endif /* #if (COM_MEMCPY_FUN_SELECT == COM_USE_STD_LIB_MEMCPY) */
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define COM_START_SEC_CODE
#include "Com_MemMap.h"
/******************************************************************************/
/*
 * Brief               Called by Com_MainFunctionRx,
 *                     Com_ResetRxPduBufferAndSignalBuffer,
 *                     Com_ResetTxPduBufferAndSignalBuffer.
 *                     init rx signal/group signal buffer
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalType,SignalInitValueId,SignalLength
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((0u < COM_IPDUGROUP_NUMBER) || (0u < COM_RXIPDU_NUMBER))
FUNC(void, COM_CODE)
Com_InitSignalBuffer(Com_SignalType SignalType, uint16 SignalInitValueId, uint16 SignalLength)
{
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    uint16 cnt;
#endif
    switch (SignalType)
    {
/*According to the signal type,
 *Copy the init signal value to signal runtime buffer*/
#if (0u < COM_SIGNAL_BOOLBUFF_SIZE)
    case COM_BOOLEAN:
        Com_SignalBoolRuntimeBuff[SignalInitValueId] = Com_SignalBoolInitValue[SignalInitValueId];
        break;
#endif
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    case COM_UINT8_N:
    case COM_UINT8_DYN:
        for (cnt = 0u; cnt < SignalLength; cnt++)
        {
            Com_Signal8BitRuntimeBuff[SignalInitValueId + cnt] = Com_Signal8BitInitValue[SignalInitValueId + cnt];
        }
        break;
    case COM_UINT8:
    case COM_SINT8:
        Com_Signal8BitRuntimeBuff[SignalInitValueId] = Com_Signal8BitInitValue[SignalInitValueId];
        break;
#endif
#if (0u < COM_SIGNAL_16BITBUFF_SIZE)
    case COM_UINT16:
    case COM_SINT16:
        Com_Signal16BitRuntimeBuff[SignalInitValueId] = Com_Signal16BitInitValue[SignalInitValueId];
        break;
#endif
#if (0u < COM_SIGNAL_32BITBUFF_SIZE)
    case COM_UINT32:
    case COM_SINT32:
    case COM_FLOAT32:
        Com_Signal32BitRuntimeBuff[SignalInitValueId] = Com_Signal32BitInitValue[SignalInitValueId];
        break;
#endif
#if (0u < COM_SIGNAL_64BITBUFF_SIZE)
    case COM_UINT64:
    case COM_SINT64:
    case COM_FLOAT64:
        Com_Signal64BitRuntimeBuff[SignalInitValueId] = Com_Signal64BitInitValue[SignalInitValueId];
        break;
#endif
    default:
        /*do nothing*/
        break;
    }
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               Called by Com_UnPackTxArrayGroupSignalValue,
 *                     Com_RxGroupSignalUnPack,Com_RxSignalUnPack,
 *                     Com_SourceSignalNotArrayUnPack
 *                     unpack all byte value(group signal/signal cover,except MSB byte).
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalEndianness,SignalByteLength,IPduBufferPtr,ComBitPosition
 *                     ComBitSize,signalType
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint64
 */
/******************************************************************************/
#if (0u < COM_RXIPDUBUFF_SIZE) || ((STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && (COM_TXSIGNALGROUP_NUMBER > 0u))
FUNC(uint64, COM_CODE)
Com_SignalUnPackHandle(
    Com_SignalEndiannessType SignalEndianness,
    uint8 SignalByteLength,
    uint8* IPduBufferPtr,
    uint32 ComBitPosition,
    uint8 ComBitSize,
    Com_SignalType signalType)
{
    uint64 signalValue = 0u;
    uint8* bufPtr = (uint8*)&signalValue;
    uint16 destStartIdx;
    uint16 srcStartIdx;
    uint8 tSignalByteLength = SignalByteLength;
    uint16 sigByteStartPos = (uint16)(ComBitPosition >> 3u);
    uint64 msbByteValue = 0u;
    uint8 msbByteBitSize;

    if (SignalByteLength > 8u)
    {
        tSignalByteLength = 8u;
    }

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST) /* Little endian byte order */
    destStartIdx = 0u;
#else
    destStartIdx = 8u - tSignalByteLength;
#endif /* #if (CPU_BYTE_ORDER == LOW_BYTE_FIRST) */
    if (COM_BIG_ENDIAN == SignalEndianness)
    {
        srcStartIdx = sigByteStartPos - (uint16)tSignalByteLength + (uint16)1u;
    }
    else
    {
        srcStartIdx = sigByteStartPos;
    }

    Com_MemCpy(&bufPtr[destStartIdx], &IPduBufferPtr[srcStartIdx], tSignalByteLength);

#if (CPU_BYTE_ORDER == LOW_BYTE_FIRST) /* Little endian byte order */
    if (COM_BIG_ENDIAN == SignalEndianness)
    {
        Com_EndianSwap(&bufPtr[destStartIdx], tSignalByteLength);
    }
#else
    if (COM_LITTLE_ENDIAN == SignalEndianness)
    {
        Com_EndianSwap(&bufPtr[destStartIdx], tSignalByteLength);
    }
#endif /* #if (CPU_BYTE_ORDER == LOW_BYTE_FIRST) */

    signalValue = (signalValue >> (ComBitPosition & 0x07u)) & (COM_UNUSED_UINT64 >> (64u - ComBitSize));

    /* SignalByteLength range 1..9 */
    if (SignalByteLength == 9u)
    {
        /* Handle MSB byte, MSB Byte is byte 0(BigEndian) or byte 8(LittleEndian) */
        msbByteBitSize = (uint8)((ComBitPosition + ComBitSize) & 0x07u);
        if (COM_BIG_ENDIAN == SignalEndianness)
        {
            msbByteValue = IPduBufferPtr[sigByteStartPos - 8u];
        }
        else
        {
            msbByteValue = IPduBufferPtr[sigByteStartPos];
        }
        msbByteValue &= ((uint64)0xFFu >> (8u - msbByteBitSize));
        signalValue |= (msbByteValue << (ComBitSize - msbByteBitSize));
    }

    /* Flag extension */
#if (STD_ON == COM_SIGNAL_SIGNED_TYPE_ENABLE)
    if (((COM_SINT8 == signalType) || (COM_SINT16 == signalType) || (COM_SINT32 == signalType)
         || (COM_SINT64 == signalType))
        && ((signalValue >> (ComBitSize - 1u)) > 0u))
    {
        signalValue = (COM_UNUSED_UINT64 << ComBitSize) | signalValue;
    }
#endif /* #if (STD_ON == COM_SIGNAL_SIGNED_TYPE_ENABLE) */

    return signalValue;
}
/******************************************************************************/
/*
 * Brief               Called by Com_SignalUnPackHandle
 *                     for Endian convert,Swap byte mirror
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalEndianness,SignalByteLength,IPduBufferPtr,ComBitPosition
 *                     ComBitSize,signalType
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              uint64
 */
/******************************************************************************/
void Com_EndianSwap(void* dataPtr, uint8 size)
{
    uint8* data = (uint8*)dataPtr;
    uint8 i;
    uint8 temp;
    uint8 loopEndIdx = size / 2u;
    uint8 arrayEndIdx = size - 1u;
    uint8 offset;

    for (i = 0u; i < loopEndIdx; i++)
    {
        offset = arrayEndIdx - i;
        temp = data[offset];
        data[offset] = data[i];
        data[i] = temp;
    }
}
#endif /* #if (0u < COM_RXIPDUBUFF_SIZE) || ((STD_ON == COM_ENABLE_SIGNAL_GROUP_ARRAY_API) && \
          (COM_TXSIGNALGROUP_NUMBER > 0u)) */
/******************************************************************************/
/*
 * Brief               Called by Com_TxSignalPack,Com_TxGroupSignalPack,
 *                     Com_DestSignalPack.
 *                     pack signal which signal type is not boolean,COM_UINT8_N,
 *                     COM_UINT8_DYN,and the signal value bits cover 2-9 bytes
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Parameter,TxValue,TxMSBValue
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((0u < COM_TXSIGNALGROUP_NUMBER) || (0u < COM_TXSIGNAL_NUMBER) || (0u < COM_GWMAPPING_NUMBER))
FUNC(void, COM_CODE)
Com_TxSignalPackHandle(Com_TxSignalPackType* Parameter, uint64 TxValue, uint64 TxMSBValue)
{
#if (0u < COM_TXIPDUBUFF_SIZE)
    uint8 cnt;
    uint32 bitPosition = Parameter->BitPosition;
    uint16 ipduBuffPos = Parameter->IpduBufferIndex + (uint16)(bitPosition >> 3u);
    uint8 signalByteLength = Parameter->SignalByteLength;
    uint8 bitPosInByte = (uint8)bitPosition & 0x07u;
    uint8 offset = bitPosInByte + Parameter->BitSize;

    if (COM_BIG_ENDIAN == Parameter->SignalEndianness)
    {
        for (cnt = 0u; cnt < signalByteLength; cnt++)
        {
            if (0u == cnt)
            {
                /* Clear corresponding bits in IPdu */
                Com_TxIPduRuntimeBuff[ipduBuffPos] &= (0xFFu >> (8u - bitPosInByte));
                /* write LSB byte in IPdu */
                Com_TxIPduRuntimeBuff[ipduBuffPos] |= ((uint8)(TxValue));
            }
            else if (signalByteLength == (cnt + 1u))
            {
                if (8u == cnt)
                {
                    /* Clear corresponding bits in IPdu */
                    Com_TxIPduRuntimeBuff[ipduBuffPos - 8u] &= (uint8)(0xFFu << (offset - 64u));
                    /* write MSB byte in IPdu */
                    Com_TxIPduRuntimeBuff[ipduBuffPos - 8u] |= ((uint8)(TxMSBValue)) & (0xFFu >> (72u - offset));
                }
                else
                {
                    TxValue = TxValue >> 8u;
                    /* Clear corresponding bits in IPdu */
                    Com_TxIPduRuntimeBuff[ipduBuffPos - cnt] &= (uint8)(0xFFu << (offset - (cnt * 8u)));
                    /* write MSB byte in IPdu */
                    Com_TxIPduRuntimeBuff[ipduBuffPos - cnt] |=
                        ((uint8)(TxValue)) & (0xFFu >> ((signalByteLength * 8u) - offset));
                }
            }
            else
            {
                TxValue = TxValue >> 8u;
                /* write txIPduBuffer next byte directly by copy value */
                Com_TxIPduRuntimeBuff[ipduBuffPos - cnt] = (uint8)(TxValue);
            }
        }
    }
    else
    {
        for (cnt = 0u; cnt < signalByteLength; cnt++)
        {
            if (0u == cnt)
            {
                /* Clear corresponding bits in IPdu */
                Com_TxIPduRuntimeBuff[ipduBuffPos] &= (0xFFu >> (8u - bitPosInByte));
                /* write LSB byte in IPdu */
                Com_TxIPduRuntimeBuff[ipduBuffPos] |= ((uint8)(TxValue));
            }
            else if (signalByteLength == (cnt + 1u))
            {
                if (8u == cnt)
                {
                    /* Clear corresponding bits in IPdu */
                    Com_TxIPduRuntimeBuff[ipduBuffPos + 8u] &= (uint8)(0xFFu << (offset - 64u));
                    /* write MSB byte in IPdu */
                    Com_TxIPduRuntimeBuff[ipduBuffPos + 8u] |= ((uint8)(TxMSBValue)) & (0xFFu >> (72u - offset));
                }
                else
                {
                    TxValue = TxValue >> 8u;
                    /* Clear corresponding bits in IPdu */
                    Com_TxIPduRuntimeBuff[ipduBuffPos + cnt] &= (uint8)(0xFFu << (offset - (cnt * 8u)));
                    /* write MSB byte in IPdu */
                    Com_TxIPduRuntimeBuff[ipduBuffPos + cnt] |=
                        ((uint8)(TxValue)) & (0xFFu >> ((signalByteLength * 8u) - offset));
                }
            }
            else
            {
                TxValue = TxValue >> 8u;
                /* write txIPduBuffer next byte directly by copy value */
                Com_TxIPduRuntimeBuff[ipduBuffPos + cnt] = (uint8)(TxValue);
            }
        }
    }
#endif
    return;
}
#endif /*(0u < COM_TXSIGNALGROUP_NUMBER) || (0u < COM_TXSIGNAL_NUMBER) || (0u < COM_GWMAPPING_NUMBER)*/
/******************************************************************************/
/*
 * Brief               Called by Com_TxSignalTMCCalculate,
 *                     Com_DestSignalTMCCalculate,Com_RxSignalFilter.
 *                     when FilterAlgorithm is NEW_IS_WITHIN,calculate
 *                     the signal's TMC
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalType,SignalValue,ComFilter,FilterOk
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (                                                                                                 \
    (0u < COM_TMCTXSIGNAL_NUMBER) || (0u < COM_TMCTXGROUPSIGNAL_NUMBER) || (0u < COM_RXSIGNAL_NUMBER) \
    || (0u < COM_RXGROUPSIGNAL_NUMBER))
FUNC(void, COM_CODE)
Com_NewIsWithinFilterCalculate(
    Com_SignalType SignalType,
    uint64 SignalValue,
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
    boolean* FilterOk)
{
    *FilterOk = FALSE;
    switch (SignalType)
    {
    /*According to the signal type,
     *Calculated the signal value is filtered or not?*/
    case COM_SINT8:
        if ((((sint8)(SignalValue)) <= ((sint8)(ComFilter->ComFilterMax)))
            && (((sint8)(SignalValue)) >= ((sint8)(ComFilter->ComFilterMin))))
        {
            *FilterOk = TRUE;
        }
        break;
    case COM_SINT16:
        if ((((sint16)(SignalValue)) <= ((sint16)(ComFilter->ComFilterMax)))
            && (((sint16)(SignalValue)) >= ((sint16)(ComFilter->ComFilterMin))))
        {
            *FilterOk = TRUE;
        }
        break;
    case COM_SINT32:
        if ((((sint32)(SignalValue)) <= ((sint32)(ComFilter->ComFilterMax)))
            && (((sint32)(SignalValue)) >= ((sint32)(ComFilter->ComFilterMin))))
        {
            *FilterOk = TRUE;
        }
        break;
    case COM_SINT64:
        if ((((sint64)(SignalValue)) <= ((sint64)(ComFilter->ComFilterMax)))
            && (((sint64)(SignalValue)) >= ((sint64)(ComFilter->ComFilterMin))))
        {
            *FilterOk = TRUE;
        }
        break;
    case COM_UINT8:
    case COM_UINT16:
    case COM_UINT32:
    case COM_UINT64:
        if (((SignalValue) <= (ComFilter->ComFilterMax)) && ((SignalValue) >= (ComFilter->ComFilterMin)))
        {
            *FilterOk = TRUE;
        }
        break;
    default:
        /*do nothing*/
        break;
    }
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               Called by Com_TxSignalTMCCalculate,
 *                     Com_DestSignalTMCCalculate,Com_RxSignalFilter.
 *                     when FilterAlgorithm is NEW_IS_WITHOUT,
 *                     calculate the signal's TMC
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalType,SignalValue,ComFilter,FilterOk
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (                                                                                                 \
    (0u < COM_TMCTXSIGNAL_NUMBER) || (0u < COM_TMCTXGROUPSIGNAL_NUMBER) || (0u < COM_RXSIGNAL_NUMBER) \
    || (0u < COM_RXGROUPSIGNAL_NUMBER))
FUNC(void, COM_CODE)
Com_NewIsWithoutFilterCalculate(
    Com_SignalType SignalType,
    uint64 SignalValue,
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
    boolean* FilterOk)
{
    *FilterOk = FALSE;
    switch (SignalType)
    {
    /*According to the signal type,
     *Calculated the signal value is filtered or not?*/
    case COM_SINT8:
        if ((((sint8)(SignalValue)) > ((sint8)(ComFilter->ComFilterMax)))
            || (((sint8)(SignalValue)) < ((sint8)(ComFilter->ComFilterMin))))
        {
            *FilterOk = TRUE;
        }
        break;
    case COM_SINT16:
        if ((((sint16)(SignalValue)) > ((sint16)(ComFilter->ComFilterMax)))
            || (((sint16)(SignalValue)) < ((sint16)(ComFilter->ComFilterMin))))
        {
            *FilterOk = TRUE;
        }
        break;
    case COM_SINT32:
        if ((((sint32)(SignalValue)) > ((sint32)(ComFilter->ComFilterMax)))
            || (((sint32)(SignalValue)) < ((sint32)(ComFilter->ComFilterMin))))
        {
            *FilterOk = TRUE;
        }
        break;
    case COM_SINT64:
        if ((((sint64)(SignalValue)) > ((sint64)(ComFilter->ComFilterMax)))
            || (((sint64)(SignalValue)) < ((sint64)(ComFilter->ComFilterMin))))
        {
            *FilterOk = TRUE;
        }
        break;
    case COM_UINT8:
    case COM_UINT16:
    case COM_UINT32:
    case COM_UINT64:
        if (((SignalValue) > (ComFilter->ComFilterMax)) || ((SignalValue) < (ComFilter->ComFilterMin)))
        {
            *FilterOk = TRUE;
        }
        break;
    default:
        /*do nothing*/
        break;
    }
    return;
}
#endif
/******************************************************************************/
/*
 * Brief               Called by Com_TxSignalTMHandle,Com_TxIpduTMSHandle.
 *                     calculate the tx ipdu TMS(signal/Group signal/Dest signal)
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxIpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (                                                                                           \
    (0u < COM_TXSIGNAL_NUMBER) || ((0u < COM_TXSIGNALGROUP_NUMBER) && (0u < COM_TXIPDU_NUMBER)) \
    || (0u < COM_GWMAPPING_NUMBER))                                                             \
    && (STD_ON == COM_TMS_ENABLE)
FUNC(boolean, COM_CODE)
Com_TxIpduTMSCalculate(PduIdType TxIpduId)
{
    boolean ret = TRUE;
#if (0u < COM_TMCTXSIGNAL_NUMBER)
    uint16 cnt;
    uint16 counter;
    Com_SignalIdType txSignalNumber;
    Com_SignalIdType txSignalId;
    Com_SignalIdType destSignalNumber;
    Com_SignalIdType destSignalId;
    Com_SignalGroupIdType signalGroupNumber;
    Com_SignalGroupIdType signalGroupId;
    Com_SignalIdType groupSignalNumber;
    Com_SignalIdType groupSignalId;
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[TxIpduId];

    /*just configuration two TxMode,need to Calculate the TMS of TxPdu.
     *ComTxModeTrue must be configured,ComTxModeFalse select configuration*/
    if (NULL_PTR != txIpduPtr->ComTxModeFalse)
    {
        ret = FALSE;
        /*Calculate TMS based on all signals contained in this TxPdu*/
        txSignalNumber = txIpduPtr->ComIPduSignalsRefNumber;
        for (cnt = 0u; (cnt < txSignalNumber) && (FALSE == ret); cnt++)
        {
            txSignalId = txIpduPtr->ComIPduSignalsRef[cnt];
            if (NULL_PTR != Com_ConfigStd->ComTxSignal[txSignalId].ComFilter)
            {
                if (TRUE == TxSignalTMCRunTime[Com_ConfigStd->ComTxSignal[txSignalId].ComFilter->ComTMCBufferId])
                {
                    ret = TRUE;
                }
            }
        }
        if (FALSE == ret)
        {
            /*Calculate TMS based on all dest description signals contained in this TxPdu*/
            destSignalNumber = txIpduPtr->ComIPduDestSignalsRefNumber;
            for (cnt = 0u; (cnt < destSignalNumber) && (FALSE == ret); cnt++)
            {
                destSignalId = txIpduPtr->ComIPduDestSignalsRef[cnt];
                if (NULL_PTR != Com_ConfigStd->ComDestSignal[destSignalId].ComFilter)
                {
                    if (TRUE
                        == TxSignalTMCRunTime[Com_ConfigStd->ComDestSignal[destSignalId].ComFilter->ComTMCBufferId])
                    {
                        ret = TRUE;
                    }
                }
            }
        }
        if (FALSE == ret)
        {
            /*Calculate TMS based on all group signals contained in this TxPdu*/
            signalGroupNumber = txIpduPtr->ComIPduSignalGroupsRefNumber;
            for (cnt = 0u; (cnt < signalGroupNumber) && (FALSE == ret); cnt++)
            {
                signalGroupId = txIpduPtr->ComIPduSignalGroupsRef[cnt];
                groupSignalNumber = Com_ConfigStd->ComTxSignalGroup[signalGroupId].ComGroupSignalNumber;
                for (counter = 0u; (counter < groupSignalNumber) && (FALSE == ret); counter++)
                {
                    groupSignalId = Com_ConfigStd->ComTxSignalGroup[signalGroupId].ComTxGroupSignalId[counter];
                    if (NULL_PTR != Com_ConfigStd->ComTxGroupSignal[groupSignalId].ComFilter)
                    {
                        if (TRUE
                            == TxSignalTMCRunTime[Com_ConfigStd->ComTxGroupSignal[groupSignalId]
                                                      .ComFilter->ComTMCBufferId])
                        {
                            ret = TRUE;
                        }
                    }
                }
            }
        }
    }
#endif /* (0u < COM_TMCTXSIGNAL_NUMBER)*/
    COM_NOUSED(TxIpduId);
    return ret;
}
#endif /* #if ((0u < COM_TXSIGNAL_NUMBER) || ((0u < COM_TXSIGNALGROUP_NUMBER) && (0u < COM_TXIPDU_NUMBER)) || (0u < \
          COM_GWMAPPING_NUMBER))  && (STD_ON == COM_TMS_ENABLE) */
/******************************************************************************/
/*
 * Brief               Called by Com_SendSignalGroupArray,Com_SendSignalGroup,
 *                     Com_GwUint8DYNSignal,Com_GwNotArraySignal,Com_GwUint8NSignal.
 *                     calculate the TMS,store new Tx mode,get rptNum value for
 *                     DIRECT/MIXED tx mode,if TMS changed will reset periodic mode counter
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxPduId
 * Param-Name[out]     None
 * Param-Name[in/out]  RptNum
 * Return              None
 */
/******************************************************************************/
#if (((0u < COM_TXSIGNALGROUP_NUMBER) && (0u < COM_TXIPDU_NUMBER)) || (0u < COM_GWMAPPING_NUMBER))
FUNC(void, COM_CODE)
Com_TxIpduTMSHandle(PduIdType TxPduId, uint16* RptNum)
{
    const Com_TxIPduType* txIpduPtr = &Com_ConfigStd->ComTxIPdu[TxPduId];
    Com_TxIPduRunTimeStateType* txIpduStatePtr = &Com_TxIPduRunTimeState[TxPduId];
    boolean oldTMS = txIpduStatePtr->TMS;

#if (STD_ON == COM_TMS_ENABLE)
    /*calculate the TMS of the Ipdu,need to query every signal/group signal/dest signal,until find one TRUE TMC*/
    txIpduStatePtr->TMS = Com_TxIpduTMSCalculate(TxPduId);
    /*According to the TMS get send mode, event trigger send times, send cycles*/
    if (TRUE == txIpduStatePtr->TMS)
#endif /* (STD_ON == COM_TMS_ENABLE) */
    {
        txIpduStatePtr->ipduTxMode = txIpduPtr->ComTxModeTrue->ComTxModeMode;
        *RptNum = txIpduPtr->ComTxModeTrue->ComTxModeNumberOfRepetitions;
        if (FALSE == oldTMS)
        {
            txIpduStatePtr->PeriodCnt = txIpduPtr->ComTxModeTrue->ComTxModeTimeOffset;
        }
    }
#if (STD_ON == COM_TMS_ENABLE)
    else
    {
        txIpduStatePtr->ipduTxMode = txIpduPtr->ComTxModeFalse->ComTxModeMode;
        *RptNum = txIpduPtr->ComTxModeFalse->ComTxModeNumberOfRepetitions;
        if (TRUE == oldTMS)
        {
            txIpduStatePtr->PeriodCnt = txIpduPtr->ComTxModeFalse->ComTxModeTimeOffset;
        }
    }
#endif /* (STD_ON == COM_TMS_ENABLE) */
    return;
}
#endif /*(0u < COM_TXSIGNALGROUP_NUMBER) || (0u < COM_GWMAPPING_NUMBER)*/
/******************************************************************************/
/*
 * Brief               Called by Com_SendSignal,Com_SendDynSignal,
 *                     Com_SendSignalGroup,Com_SendSignalGroupArray.
 *                     set tx signal update bit to 1
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      TxIpduId,UpdateBitPosition
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (0u < COM_TXIPDU_NUMBER)                                                                          \
    && ((STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) || (STD_ON == COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE) \
        || (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE))
FUNC(void, COM_CODE)
Com_SetSignalUpdateBit(PduIdType TxIpduId, uint32 UpdateBitPosition)
{
    uint16 ipduBufferIndex;
    if (COM_UNUSED_UINT32 != UpdateBitPosition)
    {
        /*If the update bit is configured, the corresponding bit is set to 1*/
        ipduBufferIndex = Com_ConfigStd->ComTxIPdu[TxIpduId].ComTxIPduBufIndex;
#if (0u < COM_TXIPDUBUFF_SIZE)
        Com_TxIPduRuntimeBuff[ipduBufferIndex + (uint16)(UpdateBitPosition >> 3u)] |=
            (uint8)(0x01u << (((uint8)UpdateBitPosition) & 0x07u));
#endif
    }
    return;
}
#endif /* #if (0u < COM_TXIPDU_NUMBER) && ((STD_ON == COM_TX_SIGNAL_UPDATE_BIT_ENABLE) || (STD_ON == \
          COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE)|| (STD_ON == COM_GW_DEST_SIG_UPDATE_BIT_ENABLE)) */
/******************************************************************************/
/*
 * Brief               Called by Com_MainFunctionTx,Com_RxPduCounterValid,
 *                     Com_TriggerIPDUSend,Com_TriggerIPDUSendWithMetaData,
 *                     Com_RxPduReplicationValid.
 *                     update the expected counter
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IsTxPdu,IpduId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if ((0u < COM_TXIPDU_NUMBER) || (0u < COM_RXIPDU_NUMBER)) \
    && ((STD_ON == COM_RX_IPDU_COUNTER_ENABLE) || (STD_ON == COM_TX_IPDU_COUNTER_ENABLE))
FUNC(void, COM_CODE)
Com_PduCounterIncrease(boolean IsTxPdu, PduIdType IpduId)
{
    uint8 maxCounter;
    uint8 activeCounter;
    if (TRUE == IsTxPdu)
    {
/*Update TxPdu's counter value*/
#if (0u < COM_TXIPDU_NUMBER) && (STD_ON == COM_TX_IPDU_COUNTER_ENABLE)
        maxCounter = Com_ConfigStd->ComTxIPdu[IpduId].ComIPduCounter->ComIPduMaxCounter;
        activeCounter = Com_TxIPduRunTimeState[IpduId].TxIpduCounter;
        if (maxCounter == activeCounter)
        {
            Com_TxIPduRunTimeState[IpduId].TxIpduCounter = 0u;
        }
        else
        {
            (Com_TxIPduRunTimeState[IpduId].TxIpduCounter) += 1u;
        }
#endif /* (0u < COM_TXIPDU_NUMBER) && (STD_ON == COM_TX_IPDU_COUNTER_ENABLE) */
    }
    else
    {
/*Update RxPdu's counter value*/
#if (0u < COM_RXIPDU_NUMBER) && (STD_ON == COM_RX_IPDU_COUNTER_ENABLE)
        maxCounter = Com_ConfigStd->ComRxIPdu[IpduId].ComIPduCounter->ComIPduMaxCounter;
        activeCounter = Com_RxIPduRunTimeState[IpduId].RxIpduCounter;
        if (maxCounter == activeCounter)
        {
            Com_RxIPduRunTimeState[IpduId].RxIpduCounter = 0u;
        }
        else
        {
            (Com_RxIPduRunTimeState[IpduId].RxIpduCounter) += 1u;
        }
#endif /* (0u < COM_RXIPDU_NUMBER) && (STD_ON == COM_RX_IPDU_COUNTER_ENABLE) */
    }
    return;
}
#endif /* (0u < COM_TXIPDU_NUMBER) && (0u < COM_RXIPDU_NUMBER) && ((STD_ON == COM_RX_IPDU_COUNTER_ENABLE)||(STD_ON == \
          COM_TX_IPDU_COUNTER_ENABLE)) */
/******************************************************************************/
/*
 * Brief               Called by Com_TxSignalTMCCalculate,
 *                     Com_RxSignalFilter.
 *                     when FilterAlgorithm is MASKED_NEW_DIFFERS_MASKED_OLD,
 *                     calculate the signal's TMC
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalType,SignalValue,ComFilter,SignalBufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (                                                                   \
    (0u < COM_TMCTXSIGNAL_NUMBER) || (0u < COM_TMCTXGROUPSIGNAL_NUMBER) \
    || (COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER > 0u))
FUNC(boolean, COM_CODE)
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Com_MaskedNewDiffersMaskedOldFilterCalculate(
    Com_SignalType SignalType,
    uint64 SignalValue,
    P2CONST(Com_FilterType, AUTOMATIC, COM_APPL_CONST) ComFilter,
    uint16 SignalBufferId)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    boolean filterOk = FALSE;
    switch (SignalType)
    {
/*According to the signal type,
 *Calculated the signal value is filtered or not?*/
#if (0u < COM_SIGNAL_BOOLBUFF_SIZE)
    case COM_BOOLEAN:
        /* PRQA S 4502,4340 ++ */ /* MISRA Rule 10.1,10.5 */
        if ((((boolean)(SignalValue)) & ((boolean)(ComFilter->ComFilterMask)))
            != (Com_SignalBoolRuntimeBuff[SignalBufferId] & ((boolean)(ComFilter->ComFilterMask))))
        /* PRQA S 4502,4340 -- */ /* MISRA Rule 10.1,10.5 */
        {
            filterOk = TRUE;
        }
        break;
#endif
#if (0u < COM_SIGNAL_8BITBUFF_SIZE)
    case COM_UINT8:
    case COM_SINT8:
        if ((((uint8)(SignalValue)) & ((uint8)(ComFilter->ComFilterMask)))
            != (Com_Signal8BitRuntimeBuff[SignalBufferId] & ((uint8)(ComFilter->ComFilterMask))))
        {
            filterOk = TRUE;
        }
        break;
#endif
#if (0u < COM_SIGNAL_16BITBUFF_SIZE)
    case COM_UINT16:
    case COM_SINT16:
        if ((((uint16)(SignalValue)) & ((uint16)(ComFilter->ComFilterMask)))
            != (Com_Signal16BitRuntimeBuff[SignalBufferId] & ((uint16)(ComFilter->ComFilterMask))))
        {
            filterOk = TRUE;
        }
        break;
#endif
#if (0u < COM_SIGNAL_32BITBUFF_SIZE)
    case COM_UINT32:
    case COM_SINT32:
        if ((((uint32)(SignalValue)) & ((uint32)(ComFilter->ComFilterMask)))
            != (Com_Signal32BitRuntimeBuff[SignalBufferId] & ((uint32)(ComFilter->ComFilterMask))))
        {
            filterOk = TRUE;
        }
        break;
#endif
#if (0u < COM_SIGNAL_64BITBUFF_SIZE)
    case COM_UINT64:
    case COM_SINT64:
        if (((SignalValue) & (ComFilter->ComFilterMask))
            != (Com_Signal64BitRuntimeBuff[SignalBufferId] & (ComFilter->ComFilterMask)))
        {
            filterOk = TRUE;
        }
        break;
#endif
    default:
        /*do nothing*/
        break;
    }
    return filterOk;
}
#endif

/******************************************************************************/
/*
 * Brief               Called by Com_SignalUnPackHandle,
 *                     memory copy
 * ServiceId
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      SignalType,SignalValue,ComFilter,SignalBufferId
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
void Com_MemCpy(void* dest, const void* src, uint16 n)
{
#if (COM_MEMCPY_FUN_SELECT == COM_USE_STD_LIB_MEMCPY)
    memcpy(dest, src, n);
#else
    for (uint16 i = 0u; i < n; ++i)
    {
        ((uint8*)dest)[i] = ((const uint8*)src)[i];
    }
#endif /* #if (COM_MEMCPY_FUN_SELECT == COM_USE_STD_LIB_MEMCPY) */
}

#define COM_STOP_SEC_CODE
#include "Com_MemMap.h"

/*******************************************************************************
**                            General Notes                                   **
*******************************************************************************/
