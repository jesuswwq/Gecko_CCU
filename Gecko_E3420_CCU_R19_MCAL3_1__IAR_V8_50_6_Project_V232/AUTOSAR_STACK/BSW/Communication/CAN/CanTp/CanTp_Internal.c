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
**  FILENAME    : CanTp_Internal.c                                           **
**                                                                           **
**  Created on  : 2021/7/30 14:29:43                                         **
**  Author      : tao.yu                                                     **
**  Vendor      :                                                            **
**  DESCRIPTION : Internal Source file of CanTp module.                      **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                     **
**                                                                           **
**************************************************************************** */

/*=======[I N C L U D E S]====================================================*/
#include "CanTp_Internal.h"

#define CANTP_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTp_MemMap.h"
/*CANTP global variable for runtime channel controlling information*/
CANTP_LOCAL VAR(CanTp_ConnectionChannelType, CANTP_VAR_NOINIT) CanTp_Channels[CANTP_CHANNEL_NUMBER];
#define CANTP_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "CanTp_MemMap.h"

/*=============Module Internal Function Implementation====================*/

#define CANTP_START_SEC_CODE
#include "CanTp_MemMap.h"
/*
 * Brief               get the Rx specific channel
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
FUNC(P2VAR(CanTp_ConnectionType, AUTOMATIC, CANTP_CONST), CANTP_CODE) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
CanTp_GetRxChannel(uint8 ChannelIdx)
{
    return &CanTp_Channels[ChannelIdx].RxConnection;
}

/*
 * Brief               get the Tx specific channel
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
FUNC(P2VAR(CanTp_TxConnectionType, AUTOMATIC, CANTP_CONST), CANTP_CODE) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
CanTp_GetTxChannel(uint8 ChannelIdx)
{
    return &CanTp_Channels[ChannelIdx].TxConnection;
}

/*
 * Brief               get the Tx specific sub channel
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
FUNC(P2VAR(CanTp_ConnectionType, AUTOMATIC, CANTP_CONST), CANTP_CODE) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
CanTp_GetTxSubChannel(uint8 ChannelIdx)
{
    return &CanTp_Channels[ChannelIdx].TxConnection.Connection;
}
/*
 * Brief               Get RX-SDU configuration by received NPDU information.
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
FUNC(P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST), CANTP_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7,20.7 */
CanTp_GetRxSduCfgByNpdu(
    PduIdType CanTpRxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) CanTpRxPduPtr,
    P2VAR(CanTp_FramePCIType, AUTOMATIC, AUTOMATIC) SduFrameType,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) channelIdx)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7, 20.7 */
{
    const CanTp_RxNSduType* result = NULL_PTR;
    const CanTp_ChannelType* channelPtr;
    uint8 rxNSduIdx;
    uint8 chnIdx;
    CanTp_FramePCIType frameType;

    for (chnIdx = 0; (NULL_PTR == result) && (chnIdx < CanTp_ConfigPtr->ChannelNum); chnIdx++)
    {
        channelPtr = &CanTp_ConfigPtr->CanTpChannel[chnIdx];
        for (rxNSduIdx = 0; (NULL_PTR == result) && (rxNSduIdx < channelPtr->RxNSduNum); rxNSduIdx++)
        {
            switch (channelPtr->RxNSdus[rxNSduIdx].AddressingFormat)
            {
            case CANTP_STANDARD:
            case CANTP_NORMALFIXED:
                frameType = CanTpRxPduPtr->SduDataPtr[CANTP_PCI_OFFSET_STD] & CANTP_FTYPE_MASK;
                if ((channelPtr->RxNSdus[rxNSduIdx].RxNPduId == CanTpRxPduId)
                    && ((CANTP_FTYPE_CF == frameType) || (CANTP_FTYPE_SF == frameType)
                        || (CANTP_FTYPE_FF == frameType)))
                {
                    result = &channelPtr->RxNSdus[rxNSduIdx];
                    *SduFrameType = frameType;
                    *channelIdx = chnIdx;
                }
                break;
#if (                                                                                          \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON))
            case CANTP_EXTENDED:
            case CANTP_MIXED:
            case CANTP_MIXED29BIT:
                if (CanTpRxPduPtr->SduLength > CANTP_PCI_OFFSET_EX)
                {
                    /*check this RX-SDU, which is configured as mix11 addressing
                     * format, and the CAN data at least includes AE and PCIType*/
                    /*check its TA and frame type*/
                    frameType = CanTpRxPduPtr->SduDataPtr[CANTP_PCI_OFFSET_EX] & CANTP_FTYPE_MASK;
                    if ((channelPtr->RxNSdus[rxNSduIdx].RxNPduId == CanTpRxPduId)
                        && ((CANTP_FTYPE_CF == frameType) || (CANTP_FTYPE_SF == frameType)
                            || (CANTP_FTYPE_FF == frameType)))
                    {
                        result = &channelPtr->RxNSdus[rxNSduIdx];
                        *SduFrameType = frameType;
                        *channelIdx = chnIdx;
                    }
                }
                break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
 || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) */
            default:
                /*idle*/
                break;
            }
        }
    }
    return result;
}

/*
 * Brief               Get SFF_DL information from the data content of SF.
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
FUNC(PduLengthType, CANTP_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7,20.7 */
CanTp_RxGetSFDl(
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
#if (STD_ON == CANTP_FD)
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) dataoffset,
#endif                   /* STD_ON == CANTP_FD */
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) totaloffset)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7,20.7 */
{
    uint8 sfDl;
    uint8 offset = 0xFF;

    /*check SF DL*/
    switch (RxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        /*PCI is byte[0]*/
        offset = CANTP_PCI_OFFSET_STD;
        *totaloffset = 1;
        break;
#if (                                                                                          \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON))
    case CANTP_EXTENDED:
    case CANTP_MIXED:
    case CANTP_MIXED29BIT:
        /*PCI is byte[1]*/
        offset = CANTP_PCI_OFFSET_EX;
        *totaloffset = 2;
        break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
 || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) */
    default:
        /*No further deal*/
        break;
    }
    sfDl = PduInfoPtr->SduDataPtr[offset] & CANTP_SF_DL_MASK;
#if (STD_ON == CANTP_FD)
    if ((0x0u == sfDl) && (8u < PduInfoPtr->SduLength))
    {
        /*CanFD only*/
        if (CAN_FD == RxNSduCfgPtr->CanFrameType)
        {
            sfDl = PduInfoPtr->SduDataPtr[offset + 1u];
            *totaloffset += 1u;
        }
    }
    else if ((0x0u != sfDl) && (8u < PduInfoPtr->SduLength))
    {
        sfDl = 0; /*invalid*/
    }
    else
    {
        /*idle*/
    }
    *dataoffset = offset;
#endif /* STD_ON == CANTP_FD */
    return sfDl;
}

#if (CANTP_DYN_ID_SUPPORT == STD_ON)
/*
 * Brief               store Rx meta data info.
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
FUNC(Std_ReturnType, CANTP_CODE)
/* PRQA S 1532++ */     /* MISRA Rule 8.7 */
CanTp_SaveRxMetaDataInfo(
    /* PRQA S 1532-- */ /* MISRA Rule 8.7 */
    uint8 channelId,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr)
{
    Std_ReturnType ret = E_OK;
    SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
#if (                                                                                             \
    (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON))
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(channelId);
    RxchannelPtr->MetaDataLength = (RxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK);
#endif /* (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON)   \
    || (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON)      \
    || (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON) */
    switch (RxNSduCfgPtr->AddressingFormat)
    {
#if (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_EXTENDED:
        RxchannelPtr->MetaDataN_TA = PduInfoPtr->SduDataPtr[CANTP_TA_OFFSET_META_EX];
#if (CANTP_GENERIC_CONNECTION_SUPPORT != STD_ON)
        if ((RxNSduCfgPtr->NTa == NULL_PTR) || (RxchannelPtr->MetaDataN_TA != *(RxNSduCfgPtr->NTa)))
        {
            ret = E_NOT_OK;
        }
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT != STD_ON */
        break;
#endif /* CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED:
        RxchannelPtr->MetaDataN_AE = PduInfoPtr->SduDataPtr[CANTP_AE_OFFSET_META_MIX];
#if (CANTP_GENERIC_CONNECTION_SUPPORT != STD_ON)
        if ((RxNSduCfgPtr->NAe == NULL_PTR) || (RxchannelPtr->MetaDataN_AE != *(RxNSduCfgPtr->NAe)))
        {
            ret = E_NOT_OK;
        }
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT != STD_ON */
        break;
#endif /* CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_NORMALFIXED:
        if ((RxchannelPtr->MetaDataLength >= 4u)
            && (CANTP_CAN_ID_32_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_CAN_ID_32_MASK)))
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
            RxchannelPtr->MetaDataN_SA = PduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_NF_MSB];
            RxchannelPtr->MetaDataN_TA = PduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_NF_MSB];
#else  /* Little endian bit ordering  CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            RxchannelPtr->MetaDataN_SA = PduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_NF_LSB];
            RxchannelPtr->MetaDataN_TA = PduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_NF_LSB];
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
#if (CANTP_GENERIC_CONNECTION_SUPPORT != STD_ON)
            if ((RxNSduCfgPtr->NSa == NULL_PTR) || (RxNSduCfgPtr->NTa == NULL_PTR)
                || (RxchannelPtr->MetaDataN_SA != *(RxNSduCfgPtr->NSa))
                || (RxchannelPtr->MetaDataN_TA != *(RxNSduCfgPtr->NTa)))
            {
                ret = E_NOT_OK;
            }
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT != STD_ON */
        }
        else
        {
            ret = E_NOT_OK;
        }
        break;
#endif /* CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED29BIT:
        RxchannelPtr->MetaDataN_AE = PduInfoPtr->SduDataPtr[CANTP_AE_OFFSET_META_MIX29];
#if (CANTP_GENERIC_CONNECTION_SUPPORT != STD_ON)
        if ((RxNSduCfgPtr->NAe == NULL_PTR) || (RxchannelPtr->MetaDataN_AE != *(RxNSduCfgPtr->NAe)))
        {
            ret = E_NOT_OK;
        }
        else
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT != STD_ON */
        {
            if ((RxchannelPtr->MetaDataLength >= 4u)
                && (CANTP_CAN_ID_32_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_CAN_ID_32_MASK)))
            {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
                RxchannelPtr->MetaDataN_SA = PduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_NF_MSB];
                RxchannelPtr->MetaDataN_TA = PduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_NF_MSB];
#else  /* Little endian bit ordering  */
                RxchannelPtr->MetaDataN_SA = PduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_NF_LSB];
                RxchannelPtr->MetaDataN_TA = PduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_NF_LSB];
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
#if (CANTP_GENERIC_CONNECTION_SUPPORT != STD_ON)
                if ((RxNSduCfgPtr->NSa == NULL_PTR) || (RxNSduCfgPtr->NTa == NULL_PTR)
                    || (RxchannelPtr->MetaDataN_SA != *(RxNSduCfgPtr->NSa))
                    || (RxchannelPtr->MetaDataN_TA != *(RxNSduCfgPtr->NTa)))
                {
                    ret = E_NOT_OK;
                }
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT != STD_ON */
            }
            else
            {
                ret = E_NOT_OK;
            }
        }
        break;
#endif /* CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON */
    default:
        /*idle*/
        break;
    }
    SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
    return ret;
}
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */

/*
 * Brief               Get FF_DL information from the data content of FF.
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
FUNC(PduLengthType, CANTP_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7, 20.7 */
CanTp_RxGetFFDl(
    P2CONST(uint8, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_APPL_CONST) offset,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7, 20.7 */
{
    /*because PduLengthType is uint16, so FFDL can not bigger than 65535*/
    uint32 ffDl;
    uint8 pcioffest = 0xFF;

    switch (RxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        pcioffest = CANTP_PCI_OFFSET_STD;
        *offset = CANTP_FF_DATA_OFFSET_LT4095_STD;
        break;
#if (                                                                                          \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON))
    case CANTP_EXTENDED:
    case CANTP_MIXED:
    case CANTP_MIXED29BIT:
        pcioffest = CANTP_PCI_OFFSET_EX;
        *offset = CANTP_FF_DATA_OFFSET_LT4095_EX;
        break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
|| (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) */
    default:
        /*idle*/
        break;
    }
    ffDl = (uint32)PduInfoPtr[pcioffest] & (uint32)CANTP_FF_DL_MASK;
    ffDl <<= CANTP_OFFSET_BYTE_PART;
    ffDl = ffDl + PduInfoPtr[pcioffest + 1u];
    /*FFDL > 4095*/
    if (0x0u == ffDl)
    {
        ffDl = PduInfoPtr[pcioffest + 2u];
        ffDl <<= CANTP_OFFSET_BYTE_PART;
        ffDl = ffDl + PduInfoPtr[pcioffest + 3u];
        ffDl <<= CANTP_OFFSET_BYTE_PART;
        ffDl = ffDl + PduInfoPtr[pcioffest + 4u];
        ffDl <<= CANTP_OFFSET_BYTE_PART;
        ffDl = ffDl + PduInfoPtr[pcioffest + 5u];
        if (ffDl <= CANTP_FF_DL_12bit_LENGTH)
        {
            ffDl = 0;
        }
        else
        {
            *offset += 4u;
        }
    }
    return (PduLengthType)ffDl;
}

/*
 * Brief               Calculate the BS value according to
 *  the buffer length and remain data length.
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
FUNC(void, CANTP_CODE)
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
CanTp_CalcBS(P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr, uint8 ChannelIdx)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    PduLengthType blockDataLen;
    uint8 length = 0xFF;
#if (STD_ON == CANTP_FD)
    uint8 offset = 0xFF;
#endif /* STD_ON == CANTP_FD */
    uint8 bs;
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(ChannelIdx);

    /*check changParameter of BS is done or not*/
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    bs = CANTP_FLAGISSET(RxchannelPtr->EventFlags, CANTP_EVENT_RXBSCHANGED)
             ? RxchannelPtr->ChangedBs
             : ((RxNSduCfgPtr->Bs != NULL_PTR) ? *(RxNSduCfgPtr->Bs) : 0xFFu);
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */

    if (0u == bs)
    {
        /*BS is 0, no more FC need from now on*/
        SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
        RxchannelPtr->CurrentBs = 0;
        SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL);  /*unlock channel*/
    }
    else
    {
        /*get the data length of this block using the minimum value between PDUR buffer length and SDU remain
        data length. If the minimum value is zero, I.E. the PDUR remain buffer is 0, use 1 as the BS*/
        blockDataLen = RxchannelPtr->SduDataRemaining;

        if (0u == blockDataLen)
        {
            /*no more upper buffer space left */
            SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
            RxchannelPtr->CurrentBs = 1U;
            SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL);  /*unlock channel*/
        }
        else
        {
            switch (RxNSduCfgPtr->AddressingFormat)
            {
            case CANTP_STANDARD:
            case CANTP_NORMALFIXED:
                length = CANTP_CF_DATALEN_STD;
#if (STD_ON == CANTP_FD)
                offset = CANTP_CF_DATA_OFFSET_STD;
#endif /* STD_ON == CANTP_FD */
                break;
#if (                                                                                          \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON))
            case CANTP_EXTENDED:
            case CANTP_MIXED:
            case CANTP_MIXED29BIT:
                length = CANTP_CF_DATALEN_EX;
#if (STD_ON == CANTP_FD)
                offset = CANTP_CF_DATA_OFFSET_EX;
#endif /* STD_ON == CANTP_FD */
                break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
|| (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) */
            default:
                /*idle*/
                break;
            }

            /*calculate CF block,CAN2.0 and CANFD is the same format,just different with length*/
            SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
            if (CAN20_tp == RxNSduCfgPtr->CanFrameType)
            {
                RxchannelPtr->CurrentBs = (uint8)((blockDataLen + length) / length);
            }
#if (STD_ON == CANTP_FD)
            else
            {
                /*CAN_FD*/
                RxchannelPtr->CurrentBs = (uint8)((blockDataLen + RxchannelPtr->FDDlc - offset) / RxchannelPtr->FDDlc);
            }
#endif /* STD_ON == CANTP_FD */
            /*use the minimum value between calculated and the configured maximum value*/
            if (RxchannelPtr->CurrentBs > bs)
            {
                RxchannelPtr->CurrentBs = bs;
            }
            SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*unlock channel*/
        }
    }                                                                       /*END OF BS needed*/
}

/*
 * Brief               Compare Buffer With Bs
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
FUNC(Std_ReturnType, CANTP_CODE)
/* PRQA S 1532++ */     /* MISRA Rule 8.7 */
CanTp_CompareBufferWithBs(
    /* PRQA S 1532-- */ /* MISRA Rule 8.7 */
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 ChannelIdx,
    PduLengthType bufferSize)
{
    PduLengthType blockDataLen;
    PduLengthType offset = 0xFF;
    Std_ReturnType ret = E_NOT_OK;
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(ChannelIdx);

    switch (RxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        offset = CANTP_CF_DATA_OFFSET_STD;
        break;
#if (                                                                                          \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON))
    case CANTP_EXTENDED:
    case CANTP_MIXED:
    case CANTP_MIXED29BIT:
        offset = CANTP_CF_DATA_OFFSET_EX;
        break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
|| (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) */
    default:
        /*idle*/
        break;
    }

    /*CF composed of this block,CAN2.0 and CANFD is the same format,just different with length*/
    if (CAN20_tp == RxNSduCfgPtr->CanFrameType)
    {
        blockDataLen = (PduLengthType)RxchannelPtr->CurrentBs * (CANTP_CAN20_FRAME_LEN_MAX - offset);
    }
#if (STD_ON == CANTP_FD)
    else
    {
        /*CAN_FD*/
        blockDataLen = (PduLengthType)RxchannelPtr->CurrentBs * (RxchannelPtr->FDDlc - offset);
    }
#else  /* STD_ON == CANTP_FD */
    else
    {
        blockDataLen = 0xFFFFu;
    }
#endif /* STD_ON == CANTP_FD */
    if (bufferSize > blockDataLen)
    {
        ret = E_OK;
    }
    else
    {
        if (bufferSize >= RxchannelPtr->SduDataRemaining)
        {
            ret = E_OK;
        }
    }

    return ret;
}

/*
 * Brief               send FC
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
FUNC(Std_ReturnType, CANTP_CODE)
/* PRQA S 1532++ */     /* MISRA Rule 8.7 */
CanTp_SendFC(
    /* PRQA S 1532-- */ /* MISRA Rule 8.7 */
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    uint8 ChannelIdx,
    CanTp_FCInfoType CanTp_FC)

{
    PduInfoType pduInfo;
    PduLengthType offset = 0xFF;
    uint16 fcFrameLen = 0u;
    Std_ReturnType ret;
#if (STD_ON == CANTP_FD)
    uint8 FcBuf[CANTP_CANFD_FRAME_LEN_MAX];
#else  /* STD_ON == CANTP_FD */
    uint8 FcBuf[CANTP_CAN20_FRAME_LEN_MAX];
#endif /* STD_ON == CANTP_FD */
#if (                                                                                                       \
    ((CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON)             \
     || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON)) \
    && (CANTP_DYN_ID_SUPPORT == STD_ON))
    const CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(ChannelIdx);
#else
    CANTP_UNUSED(ChannelIdx);
#endif /* ((CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON)      \
    || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON)) \
&& (CANTP_DYN_ID_SUPPORT == STD_ON) */
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
    uint8 Metadata[4];

    pduInfo.MetaDataPtr = Metadata;
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
    switch (RxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        offset = CANTP_PCI_OFFSET_STD;
        fcFrameLen = (uint16)CANTP_FC_LEN_STD;
        break;
#if (                                                                                          \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON))
    case CANTP_EXTENDED:
    case CANTP_MIXED:
    case CANTP_MIXED29BIT:
        offset = CANTP_PCI_OFFSET_EX;
        fcFrameLen = (uint16)CANTP_FC_LEN_EX;
        break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
 || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) */
    default:
        /*idle*/
        break;
    }
    if (offset != (PduLengthType)0xFF)
    {
        FcBuf[offset] = CANTP_FTYPE_FC | CanTp_FC.FcFs;
        FcBuf[offset + 1u] = CanTp_FC.FcBS;
        FcBuf[offset + 2u] = (uint8)CanTp_FC.FcSTMin;
    }
#if (CANTP_DYN_ID_SUPPORT == STD_ON)
    switch (RxNSduCfgPtr->AddressingFormat)
    {
#if (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_EXTENDED:
        FcBuf[CANTP_TA_OFFSET_META_EX] = RxchannelPtr->MetaDataN_TA;
        break;
#endif /* CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED:
        FcBuf[CANTP_AE_OFFSET_META_MIX] = RxchannelPtr->MetaDataN_AE;
        break;
#endif /* CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_NORMALFIXED:
        if (((RxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK) >= 4u)
            && (CANTP_CAN_ID_32_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_CAN_ID_32_MASK)))
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
            Metadata[CANTP_SA_OFFSET_META_MIX29_MSB] = RxchannelPtr->MetaDataN_TA;
            Metadata[CANTP_TA_OFFSET_META_MIX29_MSB] = RxchannelPtr->MetaDataN_SA;
#else  /* Little endian bit ordering  CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            Metadata[CANTP_SA_OFFSET_META_MIX29_LSB] = RxchannelPtr->MetaDataN_TA;
            Metadata[CANTP_TA_OFFSET_META_MIX29_LSB] = RxchannelPtr->MetaDataN_SA;
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        }
        break;
#endif /* CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED29BIT:
        if (((RxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK) >= 4u)
            && (CANTP_CAN_ID_32_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_CAN_ID_32_MASK)))
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
            Metadata[CANTP_SA_OFFSET_META_MIX29_MSB] = RxchannelPtr->MetaDataN_TA;
            Metadata[CANTP_TA_OFFSET_META_MIX29_MSB] = RxchannelPtr->MetaDataN_SA;
#else  /* Little endian bit ordering  CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            Metadata[CANTP_SA_OFFSET_META_MIX29_LSB] = RxchannelPtr->MetaDataN_TA;
            Metadata[CANTP_TA_OFFSET_META_MIX29_LSB] = RxchannelPtr->MetaDataN_SA;
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        }
        FcBuf[CANTP_AE_OFFSET_META_MIX29] = RxchannelPtr->MetaDataN_AE;
        break;
#endif /* CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON */
    default:
        /*idle*/
        break;
    }
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */
    if (CANTP_PADDING_ON == RxNSduCfgPtr->RxPaddingActivation)
    {
        CanTp_MemorySet(&FcBuf[fcFrameLen], CANTP_PADDING_BYTE, ((uint16)CANTP_CAN20_FRAME_LEN_MAX - fcFrameLen));
        fcFrameLen = (uint16)CANTP_CAN20_FRAME_LEN_MAX;
    }
    pduInfo.SduLength = (PduLengthType)fcFrameLen;
    pduInfo.SduDataPtr = FcBuf;
    ret = CanIf_Transmit(RxNSduCfgPtr->TxFcLPduId, &pduInfo);
    return ret;
}

/*
 * Brief               Utility function: Set memory with specific value.
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
FUNC(void, CANTP_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
CanTp_MemorySet(P2VAR(uint8, AUTOMATIC, CANTP_APPL_DATA) Address, uint8 Value, uint16 Length)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint16 DL;
    for (DL = 0; DL < Length; DL++)
    {
        Address[DL] = Value;
    }
}

#if (CANTP_DYN_ID_SUPPORT == STD_ON)
/*
 * Brief               check RxCF meta data
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
FUNC(Std_ReturnType, CANTP_CODE)
/* PRQA S 1532++ */     /* MISRA Rule 8.7 */
CanTp_CheckRxCFMetaData(
    /* PRQA S 1532-- */ /* MISRA Rule 8.7 */
    uint8 channelIdx,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr)
{
    Std_ReturnType result = E_OK;
#if (                                                                                             \
    (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON))
    CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(channelIdx);

    SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
    RxchannelPtr->MetaDataLength = (RxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK);
    SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL);  /*unlock channel*/
#endif /* (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
 || (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON) */
    switch (RxNSduCfgPtr->AddressingFormat)
    {
#if (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_EXTENDED: {
        if (PduInfoPtr->SduDataPtr[CANTP_TA_OFFSET_META_EX] != RxchannelPtr->MetaDataN_TA)
        {
            result = E_NOT_OK;
        }
        break;
    }
#endif /* CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED: {
        if (PduInfoPtr->SduDataPtr[CANTP_AE_OFFSET_META_MIX] != RxchannelPtr->MetaDataN_AE)
        {
            result = E_NOT_OK;
        }
        break;
    }
#endif /* CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_NORMALFIXED: {
        if ((RxchannelPtr->MetaDataLength >= 4u)
            && (CANTP_CAN_ID_32_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_CAN_ID_32_MASK)))
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
            if ((RxchannelPtr->MetaDataN_SA != PduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_MIX29_MSB])
                || (RxchannelPtr->MetaDataN_TA != PduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_MIX29_MSB]))
#else  /* Little endian bit ordering  CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            if ((RxchannelPtr->MetaDataN_SA != PduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_MIX29_LSB])
                || (RxchannelPtr->MetaDataN_TA != PduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_MIX29_LSB]))
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            {
                result = E_NOT_OK;
            }
        }
        else
        {
            result = E_NOT_OK;
        }
        break;
    }
#endif /* CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED29BIT: {
        if (PduInfoPtr->SduDataPtr[CANTP_AE_OFFSET_META_MIX29] != RxchannelPtr->MetaDataN_AE)
        {
            result = E_NOT_OK;
        }
        if ((RxchannelPtr->MetaDataLength >= 4u)
            && (CANTP_CAN_ID_32_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_CAN_ID_32_MASK)))
        {
            if (
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
                (RxchannelPtr->MetaDataN_SA != PduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_MIX29_MSB])
                || (RxchannelPtr->MetaDataN_TA != PduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_MIX29_MSB])
#else  /* Little endian bit ordering CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
                (RxchannelPtr->MetaDataN_SA != PduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_MIX29_LSB])
                || (RxchannelPtr->MetaDataN_TA != PduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_MIX29_LSB])
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            )
            {
                result = E_NOT_OK;
            }
        }
        else
        {
            result = E_NOT_OK;
        }
        break;
    }
#endif /* CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON */
    default:
        /*idle*/
        break;
    }
    return result;
}
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */

/*
 * Brief               Get CF Offset
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
FUNC(void, CANTP_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7, 20.7 */
CanTp_RxGetCFOffset(
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) dataoffset,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) pcioffset)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7, 20.7 */
{
    switch (RxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        *pcioffset = CANTP_PCI_OFFSET_STD;
        *dataoffset = CANTP_CF_DATA_OFFSET_STD;
        break;
#if (                                                                                          \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON))
    case CANTP_EXTENDED:
    case CANTP_MIXED:
    case CANTP_MIXED29BIT:
        *pcioffset = CANTP_PCI_OFFSET_EX;
        *dataoffset = CANTP_CF_DATA_OFFSET_EX;
        break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
|| (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) */
    default:
        /*idle*/
        break;
    }
}

/*
 * Brief               Get TX-SDU configuration by received FC NPDU information.
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
FUNC(P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST), CANTP_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7, 20.7 */
CanTp_GetTxSduCfgByFCNpdu(
    PduIdType CanTpRxPduId,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) CanTpRxPduPtr,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) channelIdx)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7, 20.7 */
{
    const CanTp_TxNSduType* result = NULL_PTR;
    const CanTp_ChannelType* channelPtr;
    uint8 txNSduIdx;
    uint8 chnIdx;
    CanTp_FramePCIType frameType;

    for (chnIdx = 0; (NULL_PTR == result) && (chnIdx < CanTp_ConfigPtr->ChannelNum); chnIdx++)
    {
        channelPtr = &CanTp_ConfigPtr->CanTpChannel[chnIdx];
        for (txNSduIdx = 0; (NULL_PTR == result) && (txNSduIdx < channelPtr->TxNsduNum); txNSduIdx++)
        {
            /*only physical TX NSDU need configure RX FCNPDUID*/
            if ((CANTP_PHYSICAL_TX == channelPtr->TxNSdus[txNSduIdx].TxTaType)
                && (channelPtr->TxNSdus[txNSduIdx].RxFcNPduId == CanTpRxPduId))
            {
                switch (channelPtr->TxNSdus[txNSduIdx].AddressingFormat)
                {
                case CANTP_STANDARD:
                case CANTP_NORMALFIXED:
                    /*check the standard addressing TX-NSDU, only FC accepted*/
                    frameType = CanTpRxPduPtr->SduDataPtr[CANTP_PCI_OFFSET_STD] & CANTP_FTYPE_MASK;
                    if (CANTP_FTYPE_FC == frameType)
                    {
                        result = &channelPtr->TxNSdus[txNSduIdx];
                        *channelIdx = chnIdx;
                    }
                    break;
#if (                                                                                          \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON))
                case CANTP_MIXED:
                case CANTP_MIXED29BIT:
                case CANTP_EXTENDED:
                    if (CanTpRxPduPtr->SduLength > CANTP_PCI_OFFSET_MIX11)
                    {
                        /*check the mix11 addressing TX-NSDU, only FC accepted*/
                        frameType = CanTpRxPduPtr->SduDataPtr[CANTP_PCI_OFFSET_MIX11] & CANTP_FTYPE_MASK;
                        if (CANTP_FTYPE_FC == frameType)
                        {
                            result = &channelPtr->TxNSdus[txNSduIdx];
                            *channelIdx = chnIdx;
                        }
                    }
                    else
                    {
                        /*configured as extended addressing format, but the received NPDU not has enough data space*/
                    }
                    break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
 || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) */
                default:
                    /*idle*/
                    break;
                } /*END OF switch*/
            }     /*END OF if (CANTP_PHYSICAL == CanTp_CfgData.TxNSdus[txNSduIdx].TxTaType)*/
        }         /*END OF for loop*/
    }             /*END OF for loop*/
    return result;
}

#if (CANTP_DYN_ID_SUPPORT == STD_ON)
/*
 * Brief               check RxFc meta data.
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
FUNC(Std_ReturnType, CANTP_CODE)
/* PRQA S 1532++ */     /* MISRA Rule 8.7 */
CanTp_CheckRxFCMetaData(
    /* PRQA S 1532-- */ /* MISRA Rule 8.7 */
    uint8 channelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) TxNSduCfgPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr)
{
    Std_ReturnType result = E_OK;
#if (                                                                                             \
    (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON))
    CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(channelIdx);
    SchM_Enter_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL); /*lock channel*/
    TxSubchannelPtr->MetaDataLength = (TxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK);
    SchM_Exit_CanTp(CANTP_MODULE_ID, CANTP_EXCLUSIVE_AREA_CHANNEL);  /*unlock channel*/
#endif /* (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
 || (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON) */
    switch (TxNSduCfgPtr->AddressingFormat)
    {
#if (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_EXTENDED:
        if (TxSubchannelPtr->MetaDataN_TA != PduInfoPtr->SduDataPtr[CANTP_TA_OFFSET_META_EX])
        {
            result = E_NOT_OK;
        }
        break;
#endif /* CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED:
        if (TxSubchannelPtr->MetaDataN_AE != PduInfoPtr->SduDataPtr[CANTP_AE_OFFSET_META_MIX])
        {
            result = E_NOT_OK;
        }
        break;
#endif /* CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_NORMALFIXED:
        if ((TxSubchannelPtr->MetaDataLength >= 4u)
            && (CANTP_CAN_ID_32_MASK == (TxNSduCfgPtr->CanTpPduFlag & CANTP_CAN_ID_32_MASK)))
        {
            if (
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
                (TxSubchannelPtr->MetaDataN_SA != PduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_NF_MSB])
                || (TxSubchannelPtr->MetaDataN_TA != PduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_NF_MSB])
#else  /* Little endian bit ordering CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
                (TxSubchannelPtr->MetaDataN_SA != PduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_NF_LSB])
                || (TxSubchannelPtr->MetaDataN_TA != PduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_NF_LSB])
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            )
            {
                result = E_NOT_OK;
            }
        }
        else
        {
            result = E_NOT_OK;
        }
        break;
#endif /* CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED29BIT:
        if ((TxSubchannelPtr->MetaDataLength >= 4u)
            && (CANTP_CAN_ID_32_MASK == (TxNSduCfgPtr->CanTpPduFlag & CANTP_CAN_ID_32_MASK)))
        {
            if (
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
                (TxSubchannelPtr->MetaDataN_SA != PduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_NF_MSB])
                || (TxSubchannelPtr->MetaDataN_TA != PduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_NF_MSB])
#else  /* Little endian bit ordering CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
                (TxSubchannelPtr->MetaDataN_SA != PduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_NF_LSB])
                || (TxSubchannelPtr->MetaDataN_TA != PduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_NF_LSB])
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            )
            {
                result = E_NOT_OK;
            }
        }
        else
        {
            result = E_NOT_OK;
        }
        if (TxSubchannelPtr->MetaDataN_AE != PduInfoPtr->SduDataPtr[CANTP_AE_OFFSET_META_MIX29])
        {
            result = E_NOT_OK;
        }
        break;
#endif /* CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON */
    default:
        /*idle*/
        break;
    }
    return result;
}
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */

/*
 * Brief               Get the information of received FC frame.
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
FUNC(void, CANTP_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7, 20.7 */
CanTp_GetChannelFCInfo(
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) TxNSduCfgPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr,
    P2VAR(CanTp_FCInfoType, AUTOMATIC, AUTOMATIC) FcInfoPtr)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7, 20.7 */
{
    uint32 stMinUs;
    PduLengthType offset = 0;
    uint8 stMinRaw;

    switch (TxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        offset = CANTP_PCI_OFFSET_STD;
        break;
#if (                                                                                          \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON))
    case CANTP_EXTENDED:
    case CANTP_MIXED:
    case CANTP_MIXED29BIT:
        offset = CANTP_PCI_OFFSET_EX;
        break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) \
 || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) */
    default:
        /*idle*/
        break;
    }
    FcInfoPtr->FcFs = PduInfoPtr->SduDataPtr[offset] & CANTP_FC_FS_MASK;
    FcInfoPtr->FcBS = PduInfoPtr->SduDataPtr[offset + 1u];
    /*calculate the STMin in tick unit. Round the value to the nearest integer, that is
     * if it is 0.49, then the integer will be 0, 0.50 will be 1.*/
    stMinRaw = PduInfoPtr->SduDataPtr[offset + 2u];
    if (CANTP_FC_STMIN_MS_LIMIT >= stMinRaw)
    {
        /*ms per bit*/
        stMinUs = (uint32)stMinRaw * CANTP_FC_STMIN_MS_UNIT;
    }
    else if ((CANTP_FC_STMIN_US_LOW <= stMinRaw) && (CANTP_FC_STMIN_US_UPPER >= stMinRaw))
    {
        /*F1-F9 100us per step*/
        stMinUs = ((uint32)((uint32)stMinRaw - 0xF0UL)) * CANTP_FC_STMIN_US_UNIT;
    }
    else
    {
        /*invalid value, use 7F*/
        stMinUs = (uint32)CANTP_FC_STMIN_MS_LIMIT * CANTP_FC_STMIN_MS_UNIT;
    }
    /*transit to value in unit tick*/
    FcInfoPtr->FcSTMin = (stMinUs + (uint32)((uint32)1000 >> (uint32)1)) / (uint32)1000;
}

/*
 * Brief               check Tx Length In Address Mode.
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
FUNC(Std_ReturnType, CANTP_CODE)
/* PRQA S 1532++ */     /* MISRA Rule 8.7 */
CanTp_CheckTxLengthInAddressMode(
    /* PRQA S 1532-- */ /* MISRA Rule 8.7 */
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) TxNSduCfgPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    PduLengthType len;

    switch (TxNSduCfgPtr->TxTaType)
    {
        /*functional addressing mode can only use SF*/
    case CANTP_FUNCTIONAL_TX:
        switch (TxNSduCfgPtr->AddressingFormat)
        {
        case CANTP_STANDARD:
        case CANTP_NORMALFIXED:
            if (CANTP_SF_LEN_MAX_STD >= PduInfoPtr->SduLength)
            {
                /*CAN2.0 or small CAN FD can send this single frame*/
                ret = E_OK;
            }
            else
            {
                /*large CAN FD only*/
                len = TxNSduCfgPtr->TxNPduDLC - CANTP_SF_DATA_OFFSET_CANFD_STD;
                if (CAN_FD == TxNSduCfgPtr->CanFrameType)
                {
                    if (len > PduInfoPtr->SduLength)
                    {
                        /*transmit each sdu length should less than DLC which configuration in Canif module*/
                        ret = E_OK;
                    }
                }
            }
            break;
#if (                                                                                           \
    (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON))
        case CANTP_EXTENDED:
        case CANTP_MIXED:
        case CANTP_MIXED29BIT:
            if (CANTP_SF_LEN_MAX_EX >= PduInfoPtr->SduLength)
            {
                /*CAN2.0 or small CAN FD*/
                ret = E_OK;
            }
            else
            {
                /*large CAN FD only*/
                len = TxNSduCfgPtr->TxNPduDLC - CANTP_SF_DATA_OFFSET_CANFD_EX;
                if (CAN_FD == TxNSduCfgPtr->CanFrameType)
                {
                    if (len > PduInfoPtr->SduLength)
                    {
                        /*transmit each sdu length should less than DLC which configuration in Canif module*/
                        ret = E_OK;
                    }
                }
            }
            break;
#endif /* (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) \
 || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) */
        default:
            /*idle*/
            break;
        }
        break;
    case CANTP_PHYSICAL_TX:
        ret = E_OK;
        break;
    default:
        /*idle*/
        break;
    }
    return ret;
}

#if (CANTP_DYN_ID_SUPPORT == STD_ON)
/*
 * Brief               store Tx meta data info.
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
FUNC(void, CANTP_CODE)
/* PRQA S 1532++ */     /* MISRA Rule 8.7 */
CanTp_SaveTxMetaDataInfo(
    /* PRQA S 1532-- */ /* MISRA Rule 8.7 */
    uint8 channelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) TxNSduCfgPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_APPL_CONST) PduInfoPtr)
{
#if (                                                                                             \
    (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON))
    CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(channelIdx);
    TxSubchannelPtr->MetaDataLength = (TxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK);
#endif /* (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
|| (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON) */
    switch (TxNSduCfgPtr->AddressingFormat)
    {
#if (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_EXTENDED:
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
        if (((TxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK) > 0u)
            && (CANTP_SA16_AND_TA16_MASK == (TxNSduCfgPtr->CanTpPduFlag & CANTP_SA16_AND_TA16_MASK)))
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
            TxSubchannelPtr->MetaDataN_TA = PduInfoPtr->MetaDataPtr[CANTP_TA_FOR_DCM_MSB];
#else                                   /* Little endian bit ordering CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            TxSubchannelPtr->MetaDataN_TA = PduInfoPtr->MetaDataPtr[CANTP_TA_FOR_DCM_LSB];
#endif                                  /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        }
#else                                   /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
        TxSubchannelPtr->MetaDataN_TA = *(TxNSduCfgPtr->NTa);
#endif                                  /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
        break;
#endif                                  /* CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED:
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
        if (((TxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK) > 0u)
            && (CANTP_ADDRESS_EXTENSION_8_MASK == (TxNSduCfgPtr->CanTpPduFlag & CANTP_ADDRESS_EXTENSION_8_MASK)))
        {
            TxSubchannelPtr->MetaDataN_AE = PduInfoPtr->MetaDataPtr[CANTP_AE_FOR_DCM];
        }
#else  /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
        TxSubchannelPtr->MetaDataN_AE = *(TxNSduCfgPtr->NAe);
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
        break;
#endif /* CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_NORMALFIXED:
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
        if (((TxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK) > 0u)
            && (CANTP_SA16_AND_TA16_MASK == (TxNSduCfgPtr->CanTpPduFlag & CANTP_SA16_AND_TA16_MASK)))
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
            TxSubchannelPtr->MetaDataN_SA = PduInfoPtr->MetaDataPtr[CANTP_SA_FOR_DCM_MSB];
            TxSubchannelPtr->MetaDataN_TA = PduInfoPtr->MetaDataPtr[CANTP_TA_FOR_DCM_MSB];
#else  /* Little endian bit ordering CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            TxSubchannelPtr->MetaDataN_SA = PduInfoPtr->MetaDataPtr[CANTP_SA_FOR_DCM_LSB];
            TxSubchannelPtr->MetaDataN_TA = PduInfoPtr->MetaDataPtr[CANTP_TA_FOR_DCM_LSB];
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        }
#else  /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
        TxSubchannelPtr->MetaDataN_SA = *(TxNSduCfgPtr->NSa);
        TxSubchannelPtr->MetaDataN_TA = *(TxNSduCfgPtr->NTa);
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
        break;
#endif /* CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED29BIT:
#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
        if (((TxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK) > 0u)
            && (CANTP_SA16_AND_TA16_MASK == (TxNSduCfgPtr->CanTpPduFlag & CANTP_SA16_AND_TA16_MASK))
            && (CANTP_ADDRESS_EXTENSION_8_MASK == (TxNSduCfgPtr->CanTpPduFlag & CANTP_ADDRESS_EXTENSION_8_MASK)))
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
            TxSubchannelPtr->MetaDataN_SA = PduInfoPtr->MetaDataPtr[CANTP_SA_FOR_DCM_MSB];
            TxSubchannelPtr->MetaDataN_TA = PduInfoPtr->MetaDataPtr[CANTP_TA_FOR_DCM_MSB];
#else  /* Little endian bit ordering CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            TxSubchannelPtr->MetaDataN_SA = PduInfoPtr->MetaDataPtr[CANTP_SA_FOR_DCM_LSB];
            TxSubchannelPtr->MetaDataN_TA = PduInfoPtr->MetaDataPtr[CANTP_TA_FOR_DCM_LSB];
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            TxSubchannelPtr->MetaDataN_AE = PduInfoPtr->MetaDataPtr[CANTP_AE_FOR_DCM];
        }
#else  /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
        TxSubchannelPtr->MetaDataN_SA = *(TxNSduCfgPtr->NSa);
        TxSubchannelPtr->MetaDataN_TA = *(TxNSduCfgPtr->NTa);
        TxSubchannelPtr->MetaDataN_AE = *(TxNSduCfgPtr->NAe);
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */
        break;
#endif /* CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON */
    default:
        /*idle*/
        break;
    }
}
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */

/*
 * Brief               Handle transmit request.
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
FUNC(void, CANTP_CODE)
/* PRQA S 1532++ */     /* MISRA Rule 8.7 */
CanTp_TxHandleTransmitReq(
    /* PRQA S 1532-- */ /* MISRA Rule 8.7 */
    uint8 ChannelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) TxNSduCfgPtr)
{
    PduLengthType len;
    uint8 offset = 0xFF;
    CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);

    switch (TxNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        /*Can2.0 or small Can Fd*/
        offset = CANTP_SF_DATA_OFFSET_STD;
#if (STD_ON == CANTP_FD)
        if (CAN_FD == TxNSduCfgPtr->CanFrameType)
        {
            /*small CanFD data offset same as Can 2.0,CANTP_SF_DATA_OFFSET_STD,small
            Can FD data field length less than large Can FD, so len = bigger one*/
            if (TxSubchannelPtr->SduDataTotalCount > 7u)
            {
                offset = CANTP_SF_DATA_OFFSET_CANFD_STD;
            }
        }
#endif /* STD_ON == CANTP_FD */
        break;
#if (                                                                                           \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON))
    case CANTP_MIXED:
    case CANTP_MIXED29BIT:
    case CANTP_EXTENDED:
        offset = CANTP_SF_DATA_OFFSET_EX;
#if (STD_ON == CANTP_FD)
        if (CAN_FD == TxNSduCfgPtr->CanFrameType)
        {
            /*small CanFD data offset same as Can 2.0,CANTP_SF_DATA_OFFSET_STD,small
            Can FD data field length less than large Can FD, so len = bigger one*/
            if (TxSubchannelPtr->SduDataTotalCount > 6u)
            {
                offset = CANTP_SF_DATA_OFFSET_CANFD_EX;
            }
        }
#endif /* STD_ON == CANTP_FD */
        break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
|| (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) */
    default:
        /*idle*/
        break;
    }
    if (offset != 0xFFu)
    {
        len = TxNSduCfgPtr->TxNPduDLC - offset;
        if (len < TxSubchannelPtr->SduDataTotalCount)
        {
            /*larger SDU transmit request*/
            TxSubchannelPtr->HandleType = CANTP_FTYPE_FF;
            TxSubchannelPtr->RootState = CANTP_LARGE_TRANSMITTING;
            TxSubchannelPtr->Substate = CANTP_TX_LARGE_START;
        }
        else
        {
            /*SF transmit request*/
            TxSubchannelPtr->HandleType = CANTP_FTYPE_SF;
            TxSubchannelPtr->RootState = CANTP_SF_TRANSIMITTING;
            TxSubchannelPtr->Substate = CANTP_TX_SF_START;
        }
    }
}
/*
 * Brief               construct FF PCI information in local buffer for channel.
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
FUNC(void, CANTP_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7,20.7 */
CanTp_ConstructFFPci(
    uint8 ChannelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) txNSduCfgPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) dataPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) totalOffset)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7,20.7 */
{
    uint32 pciDl;
    uint8 offset = 0xFF;
    const CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);

    pciDl = TxSubchannelPtr->SduDataTotalCount;
    switch (txNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        /*Can2.0 or small Can Fd*/
        offset = CANTP_PCI_OFFSET_STD;
        break;
#if (                                                                                           \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON))
    case CANTP_MIXED:
    case CANTP_MIXED29BIT:
    case CANTP_EXTENDED:
        offset = CANTP_PCI_OFFSET_EX;
        break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
 || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) */
    default:
        /*idle*/
        break;
    }

    if (pciDl <= CANTP_FF_DL_12bit_LENGTH)
    {
        /*FF_DL less than or equal to 4095*/
        /*SDU length high nibble and Frame type*/
        dataPtr[offset] = CANTP_FTYPE_FF | (uint8)(pciDl >> 8u);
        offset++;
        /*SDU length low nibble*/
        dataPtr[offset] = (uint8)pciDl;
        offset++;
        *totalOffset = offset;
    }
    else
    {
        /*FF_DL bigger than 4095*/
        /*SDU length from high to low nibble*/
        dataPtr[offset] = CANTP_FTYPE_FF;
        offset++;
        dataPtr[offset] = 0x00;
        offset++;
        dataPtr[offset] = (uint8)(pciDl >> 24u);
        offset++;
        dataPtr[offset] = (uint8)(pciDl >> 16u);
        offset++;
        dataPtr[offset] = (uint8)(pciDl >> 8u);
        offset++;
        dataPtr[offset] = (uint8)pciDl;
        offset++;
        *totalOffset = offset;
    }
}
/*
 * Brief               construct CF PCI information in local buffer for channel.
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
FUNC(void, CANTP_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7,20.7 */
CanTp_ConstructCFPci(
    uint8 ChannelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) txNSduCfgPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) dataPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) totalOffset)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7,20.7 */
{
    uint8 offset = 0xFF;
    const CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);

    switch (txNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        /*Can2.0 or small Can Fd*/
        offset = CANTP_PCI_OFFSET_STD;
        break;
#if (                                                                                           \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON))
    case CANTP_MIXED:
    case CANTP_MIXED29BIT:
    case CANTP_EXTENDED:
        offset = CANTP_PCI_OFFSET_EX;
        break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
|| (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) */
    default:
        /*idle*/
        break;
    }
    dataPtr[offset] = CANTP_FTYPE_CF | TxSubchannelPtr->CurrentCfSn;
    offset++;
    *totalOffset = offset;
}

/*
 * Brief               construct SF PCI information in local buffer for channel.
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
FUNC(void, CANTP_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7,20.7 */
CanTp_ConstructSFPci(
    uint8 ChannelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) txNSduCfgPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) dataPtr,
    P2VAR(uint8, AUTOMATIC, CANTP_CONST) totalOffset)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7,20.7 */
{
    PduLengthType pciDl;
#if (STD_ON == CANTP_FD)
    PduLengthType CANDL;
#endif /* STD_ON == CANTP_FD */
    const CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);
    uint8 offset = 0xFF;

    pciDl = TxSubchannelPtr->SduDataTotalCount;
#if (STD_ON == CANTP_FD)
    if ((pciDl >= 8u) && (pciDl <= 10u))
    {
        CANDL = 12;
    }
    else if ((pciDl >= 11u) && (pciDl <= 14u))
    {
        CANDL = 16;
    }
    else if ((pciDl >= 15u) && (pciDl <= 18u))
    {
        CANDL = 20;
    }
    else if ((pciDl >= 19u) && (pciDl <= 22u))
    {
        CANDL = 24;
    }
    else if ((pciDl >= 23u) && (pciDl <= 30u))
    {
        CANDL = 32;
    }
    else if ((pciDl >= 31u) && (pciDl <= 46u))
    {
        CANDL = 48;
    }
    else if ((pciDl >= 47u) && (pciDl <= 62u))
    {
        CANDL = 64;
    }
    else
    {
        CANDL = 8;
    }
#endif /* STD_ON == CANTP_FD */

    switch (txNSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        /*Can2.0 or small Can Fd*/
        offset = CANTP_PCI_OFFSET_STD;
        break;
#if (                                                                                           \
    (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON))
    case CANTP_MIXED:
    case CANTP_MIXED29BIT:
    case CANTP_EXTENDED:
        offset = CANTP_PCI_OFFSET_EX;
        break;
#endif /* (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
|| (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) */
    default:
        /*idle*/
        break;
    }

#if (STD_ON == CANTP_FD)
    if (CANDL <= 8u)
#endif /* STD_ON == CANTP_FD */
    {
        /*SF_DL less than or equal to 7, Frame type and SF DL*/
        dataPtr[offset] = ((uint8)pciDl & CANTP_SF_DL_MASK); /*CANTP_FTYPE_SF*/
        offset++;
        *totalOffset = offset;
    }
#if (STD_ON == CANTP_FD)
    else
    {
        /*SF_DL bigger than 7, Frame type and SF DL*/
        dataPtr[offset] = CANTP_FTYPE_SF;
        offset++;
        dataPtr[offset] = (uint8)pciDl;
        offset++;
        *totalOffset = offset;
    }
#endif /* STD_ON == CANTP_FD */
}

#if (CANTP_DYN_ID_SUPPORT == STD_ON)
/*
 * Brief               Construct Tx meta data info.
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
FUNC(void, CANTP_CODE)
/* PRQA S 1532++ */     /* MISRA Rule 8.7 */
CanTp_ConstructTxMetaDataInfo(
    /* PRQA S 1532-- */ /* MISRA Rule 8.7 */
    uint8 ChannelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) TxNSduCfgPtr,
    P2CONST(PduInfoType, AUTOMATIC, AUTOMATIC) pduInfoPtr)
{
    const CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);
    switch (TxNSduCfgPtr->AddressingFormat)
    {
#if (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_EXTENDED:
        pduInfoPtr->SduDataPtr[CANTP_TA_OFFSET_META_EX] = TxSubchannelPtr->MetaDataN_TA;
        break;
#endif /* CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED:
        pduInfoPtr->SduDataPtr[CANTP_AE_OFFSET_META_MIX] = TxSubchannelPtr->MetaDataN_AE;
        break;
#endif /* CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_NORMALFIXED:
        if (((TxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK) >= 4u)
            && (CANTP_CAN_ID_32_MASK == (TxNSduCfgPtr->CanTpPduFlag & CANTP_CAN_ID_32_MASK)))
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
            pduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_NF_MSB] = TxSubchannelPtr->MetaDataN_SA;
            pduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_NF_MSB] = TxSubchannelPtr->MetaDataN_TA;
#else  /* Little endian bit ordering CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            pduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_NF_LSB] = TxSubchannelPtr->MetaDataN_SA;
            pduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_NF_LSB] = TxSubchannelPtr->MetaDataN_TA;
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        }
        break;
#endif /* CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED29BIT:
        if (((TxNSduCfgPtr->CanTpPduFlag & CANTP_METADATA_LENGTH_MASK) >= 4u)
            && (CANTP_CAN_ID_32_MASK == (TxNSduCfgPtr->CanTpPduFlag & CANTP_CAN_ID_32_MASK)))
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
            pduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_NF_MSB] = TxSubchannelPtr->MetaDataN_SA;
            pduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_NF_MSB] = TxSubchannelPtr->MetaDataN_TA;
#else  /* Little endian bit ordering CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            pduInfoPtr->MetaDataPtr[CANTP_SA_OFFSET_META_NF_LSB] = TxSubchannelPtr->MetaDataN_SA;
            pduInfoPtr->MetaDataPtr[CANTP_TA_OFFSET_META_NF_LSB] = TxSubchannelPtr->MetaDataN_TA;
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        }
        pduInfoPtr->SduDataPtr[CANTP_AE_OFFSET_META_MIX] = TxSubchannelPtr->MetaDataN_AE;
        break;
#endif /* CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON */
    default:
        /*idle*/
        break;
    }
}
#endif /* CANTP_DYN_ID_SUPPORT == STD_ON */

/*
 * Brief               Tx SF Padding.
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
FUNC(void, CANTP_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7,20.7 */
CanTp_TxSFPadding(
    uint8 ChannelIdx,
    P2CONST(CanTp_TxNSduType, AUTOMATIC, CANTP_CONST) txSduCfgPtr,
    P2VAR(PduInfoType, AUTOMATIC, AUTOMATIC) pduInfoPtr)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7,20.7 */
{
    PduLengthType frameDL;
#if (STD_ON == CANTP_FD)
    PduLengthType can20DataFieldLen = 0;
    PduLengthType canFdDataOffset = 0;
    const CanTp_ConnectionType* TxSubchannelPtr = CanTp_GetTxSubChannel(ChannelIdx);

    switch (txSduCfgPtr->AddressingFormat)
    {
    case CANTP_STANDARD:
    case CANTP_NORMALFIXED:
        can20DataFieldLen = CANTP_SF_LEN_MAX_STD;
        canFdDataOffset = CANTP_SF_DATA_OFFSET_CANFD_STD;
        break;
#if (                                                                                           \
    (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON))
    case CANTP_MIXED:
    case CANTP_MIXED29BIT:
    case CANTP_EXTENDED: {
        can20DataFieldLen = CANTP_SF_LEN_MAX_EX;
        canFdDataOffset = CANTP_SF_DATA_OFFSET_CANFD_EX;
        break;
    }
#endif /* (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) \
|| (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) */
    default:
        /*idle*/
        break;
    }

    if ((TxSubchannelPtr->SduDataTotalCount > can20DataFieldLen) && (CAN_FD == txSduCfgPtr->CanFrameType))
    {
        /*CANFD frame length >8*/
        frameDL = TxSubchannelPtr->SduDataTotalCount + canFdDataOffset;
        /*frameDL here is less than or equal to the DLC which configuration in the CANFI module*/
        frameDL = CanTp_MatchDLC(frameDL);
        CanTp_MemorySet(
            &pduInfoPtr->SduDataPtr[pduInfoPtr->SduLength],
            CANTP_PADDING_BYTE,
            (frameDL - pduInfoPtr->SduLength));
        pduInfoPtr->SduLength = frameDL;
    }
    else
#else
    CANTP_UNUSED(ChannelIdx);
#endif /*ENDOF #if (STD_ON == CANTP_FD)*/
    {
        if (CANTP_PADDING_ON == txSduCfgPtr->TxPaddingActivation)
        {
            /*CAN2.0 or small CAN FD*/
            frameDL = CANTP_CAN20_FRAME_LEN_MAX;
            CanTp_MemorySet(
                &pduInfoPtr->SduDataPtr[pduInfoPtr->SduLength],
                CANTP_PADDING_BYTE,
                (frameDL - pduInfoPtr->SduLength));
            pduInfoPtr->SduLength = frameDL;
        }
    }
}

#if (CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON)
/*
 * Brief               Construct Rx meta data.
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
FUNC(void, CANTP_CODE)
/* PRQA S 1532++ */     /* MISRA Rule 8.7 */
CanTp_ConstructForwardRxMetaData(
    /* PRQA S 1532++ */ /* MISRA Rule 8.7 */
    uint8 channelId,
    P2CONST(CanTp_RxNSduType, AUTOMATIC, CANTP_CONST) RxNSduCfgPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANTP_VAR) CanTpRxInfoPtr)
{
#if (                                                                                             \
    (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
    || (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON))
    const CanTp_ConnectionType* RxchannelPtr = CanTp_GetRxChannel(channelId);
#endif /* (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON) || (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON) \
|| (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON) || (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON) */

    switch (RxNSduCfgPtr->AddressingFormat)
    {
#if (CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_EXTENDED:
        if (CANTP_SA16_AND_TA16_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_SA16_AND_TA16_MASK))
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
            CanTpRxInfoPtr->MetaDataPtr[CANTP_TA_FOR_DCM_MSB] = RxchannelPtr->MetaDataN_TA;
#else                                   /* Little endian bit ordering CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            CanTpRxInfoPtr->MetaDataPtr[CANTP_TA_FOR_DCM_LSB] = RxchannelPtr->MetaDataN_TA;
#endif                                  /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        }
        break;
#endif /* CANTP_EXTENDED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_NORMALFIXED:
        if (CANTP_SA16_AND_TA16_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_SA16_AND_TA16_MASK))
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
            CanTpRxInfoPtr->MetaDataPtr[CANTP_SA_FOR_DCM_MSB] = RxchannelPtr->MetaDataN_SA;
            CanTpRxInfoPtr->MetaDataPtr[CANTP_TA_FOR_DCM_MSB] = RxchannelPtr->MetaDataN_TA;
#else  /* Little endian bit ordering CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            CanTpRxInfoPtr->MetaDataPtr[CANTP_SA_FOR_DCM_LSB] = RxchannelPtr->MetaDataN_SA;
            CanTpRxInfoPtr->MetaDataPtr[CANTP_TA_FOR_DCM_LSB] = RxchannelPtr->MetaDataN_TA;
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        }
        break;
#endif /* CANTP_NORMAL_FIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED:
        if (CANTP_ADDRESS_EXTENSION_8_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_ADDRESS_EXTENSION_8_MASK))
        {
            CanTpRxInfoPtr->MetaDataPtr[CANTP_AE_FOR_DCM] = RxchannelPtr->MetaDataN_AE;
        }
        break;
#endif /* CANTP_MIXED_ADDRESSING_SUPPORT == STD_ON */
#if (CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON)
    case CANTP_MIXED29BIT:
        if (CANTP_SA16_AND_TA16_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_SA16_AND_TA16_MASK))
        {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST) /* Big endian bit ordering*/
            CanTpRxInfoPtr->MetaDataPtr[CANTP_SA_FOR_DCM_MSB] = RxchannelPtr->MetaDataN_SA;
            CanTpRxInfoPtr->MetaDataPtr[CANTP_TA_FOR_DCM_MSB] = RxchannelPtr->MetaDataN_TA;
#else  /* Little endian bit ordering CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
            CanTpRxInfoPtr->MetaDataPtr[CANTP_SA_FOR_DCM_LSB] = RxchannelPtr->MetaDataN_SA;
            CanTpRxInfoPtr->MetaDataPtr[CANTP_TA_FOR_DCM_LSB] = RxchannelPtr->MetaDataN_TA;
#endif /* CPU_BYTE_ORDER == HIGH_BYTE_FIRST */
        }
        if (CANTP_ADDRESS_EXTENSION_8_MASK == (RxNSduCfgPtr->CanTpPduFlag & CANTP_ADDRESS_EXTENSION_8_MASK))
        {
            CanTpRxInfoPtr->MetaDataPtr[CANTP_AE_FOR_DCM] = RxchannelPtr->MetaDataN_AE;
        }
        break;
#endif /* CANTP_MIXED29_ADDRESSING_SUPPORT == STD_ON */
    default:
        /*idle*/
        break;
    }
}
#endif /* CANTP_GENERIC_CONNECTION_SUPPORT == STD_ON */

#define CANTP_STOP_SEC_CODE
#include "CanTp_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/
