
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
**  FILENAME    :                                                            **
**                                                                           **
**  Created on  : 2020/5/6 14:29:43                                          **
**  Author      : tao.yu                                                     **
**  Vendor      :                                                            **
**  DESCRIPTION :                                                            **
**                                                                           **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                      **
**                                                                           **
**************************************************************************** */
#include "UDS.h"
#include "Dem_Internal.h"
/****************************************************************
         UDS:ReadDTCInformation (19 hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X19_ENABLED)
typedef struct
{
    P2VAR(boolean, AUTOMATIC, DCM_VAR) PendingFlag; /* PRQA S 3432 */    /* MISRA Rule 20.7 */
    P2VAR(boolean, AUTOMATIC, DCM_VAR) NotAllowedFlag; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_MsgLenType, AUTOMATIC, DCM_VAR) MsgLen; /* PRQA S 3432 */  /* MISRA Rule 20.7 */
    P2VAR(uint16, AUTOMATIC, DCM_VAR) Index; /* PRQA S 3432 */           /* MISRA Rule 20.7 */
    uint32 Offset;
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DtcCount; /* PRQA S 3432 */        /* MISRA Rule 20.7 */
} Dcm_UDS0x19Types;

#if (STD_ON == DCM_UDS_SERVICE0X19_01_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x01 sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dcm_UDS0x19_01(uint8 ProtocolCtrlId, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 DtcStatusMask;
    uint8 MsgCtrlId;
    uint16 DtcCount = 0;
    uint32 Offset;
    boolean NotAllowedFlag = FALSE;
    boolean PendingFlag = FALSE;
    Std_ReturnType ret = E_OK;
    Dcm_MsgLenType MsgLen;
    Dem_ReturnSetFilterType ReturnSetDTCFilter;
    Dem_ReturnGetNumberOfFilteredDTCType ReturnGetNumberOfFilteredDTC;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    /**************************************************/
    /*check the massage length*/
    if (DCM_UDS0X19_SUBFUNC0X01_REQ_DATA_LENGTH != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
    {
        /*the length of massage is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    {
        /*find Tx buffer and offset*/
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;

        /*Sub-function:0x01*/
        MsgLen = 2u;
        DtcStatusMask = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2];

        /*obtain DTCStatusAvailabilityMask*/
        ret = Dem_DcmGetDTCStatusAvailabilityMask(&Dcm_Channel[Offset + MsgLen]);
        if (E_OK == ret)
        {
            /*one byte for the storage of DTC status availability mask*/
            MsgLen = MsgLen + 1u;
            /*get and store DTCFormatIdentifier*/
            Dcm_Channel[Offset + MsgLen] = Dem_DcmGetTranslationType();
            MsgLen = MsgLen + 1u;
            if (DtcStatusMask == 0u)
            {
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_Channel[Offset + MsgLen] = (uint8)0;
                MsgLen = MsgLen + 1u;
                Dcm_Channel[Offset + MsgLen] = (uint8)0;
                SchM_Exit_Dcm(Dcm_Channel);
                MsgLen = MsgLen + 1u;
            }
            else
            {
                /*set DTC filter*/
                ReturnSetDTCFilter = Dem_DcmSetDTCFilter(
                    DtcStatusMask,
                    DEM_DTC_KIND_ALL_DTCS,
                    DEM_DTC_FORMAT_UDS,
                    DEM_DTC_ORIGIN_PRIMARY_MEMORY,
                    FALSE,
                    DEM_SEVERITY_NO_SEVERITY,
                    FALSE);
                if (DEM_FILTER_ACCEPTED == ReturnSetDTCFilter)
                {
                    /*get the number of required DTC*/
                    ReturnGetNumberOfFilteredDTC = Dem_DcmGetNumberOfFilteredDTC(&DtcCount);
                    switch (ReturnGetNumberOfFilteredDTC)
                    {
                    case DEM_NUMBER_OK:
                        SchM_Enter_Dcm(Dcm_Channel);
                        Dcm_Channel[Offset + MsgLen] = (uint8)(DtcCount >> 8u);
                        MsgLen = MsgLen + 1u;
                        Dcm_Channel[Offset + MsgLen] = (uint8)DtcCount;
                        SchM_Exit_Dcm(Dcm_Channel);
                        MsgLen = MsgLen + 1u;
                        break;
                    case DEM_NUMBER_FAILED:
                        NotAllowedFlag = TRUE;
                        break;
                    case DEM_NUMBER_PENDING:
                        PendingFlag = TRUE;
                        break;
                    default:
                        NotAllowedFlag = TRUE;
                        break;
                    }
                }
                else
                {
                    /*if fail to set DTC filter*/
                    NotAllowedFlag = TRUE;
                }
            }
        }
        else
        {
            NotAllowedFlag = TRUE;
        }

        if (TRUE == NotAllowedFlag)
        {
            /*if fail to get any request information,send NRC 0x22*/
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        }
        else if (TRUE == PendingFlag)
        {
            /*if some request info is not available yet,enter pending and wait for the next cycle*/
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            ret = DCM_E_PENDING;
        }
        else
        {
            /* check tx data length */
            if ((MsgLen) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
            {
                /*Pdu length is bigger than buffer size,ignore the request message */
                *ErrorCode = DCM_E_RESPONSETOOLONG;
                ret = E_NOT_OK;
            }
            if (E_OK == ret)
            {
                /*assemble positive response*/
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_Channel[Offset] = 0x59;
                Dcm_Channel[Offset + 1u] = 0x01;
                SchM_Exit_Dcm(Dcm_Channel);
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = MsgLen;
                Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = MsgLen;
                Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                DsdInternal_ProcessingDone(ProtocolCtrlId);
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/************************************/
#if (STD_ON == DCM_UDS_SERVICE0X19_02_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x02 sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x19_02_SubDealTwo(
    uint8 ProtocolCtrlId,
    Dcm_MsgLenType MsgLen,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 MsgCtrlId;
    uint32 Offset;
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
    uint16 Index = 0;
    uint16 DtcCount = 0;
#endif
    Std_ReturnType ret = E_OK;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    /*find Tx buffer and offset*/
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;

    if
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
        (
#endif
            ((MsgLen) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
            || (0UL != Dcm_PageBufferData.TotalSize))
    {
        if (0UL == Dcm_PageBufferData.TotalSize)
        {
            SchM_Enter_Dcm(Dcm_PageBufferData);
            Dcm_PageBufferData.TotalSize = MsgLen;
            Dcm_PageBufferData.TotalDtcCount = DtcCount;
            SchM_Exit_Dcm(Dcm_PageBufferData);
            DsdInternal_StartPagedProcessing(ProtocolCtrlId);
        }
        else
        {
            if (Dcm_PageBufferData.LastFilled == TRUE)
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                Dcm_PageBufferData.IloopOne = Index;
                Dcm_PageBufferData.ThisPageSize = (uint16)MsgLen;
                SchM_Exit_Dcm(Dcm_PageBufferData);
            }
            else
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                Dcm_PageBufferData.IloopOne = Index - 1u;
                Dcm_PageBufferData.ThisPageSize = (uint16)(MsgLen - 4u);
                SchM_Exit_Dcm(Dcm_PageBufferData);
            }
            SchM_Enter_Dcm(Dcm_PageBufferData);
            Dcm_PageBufferData.PageIndex += 1u;
            Dcm_PageBufferData.Filled = TRUE;
            SchM_Exit_Dcm(Dcm_PageBufferData);

            DsdInternal_ProcessPage(ProtocolCtrlId);
            if (Dcm_PageBufferData.TimeOut == TRUE)
            {
                ret = E_NOT_OK;
            }
            if (ret != E_NOT_OK)
            {
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                ret = DCM_E_PENDING;
            }
        }
        if (Dcm_PageBufferData.TotalSize
            > Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId].DcmDslProtocolMaximumResponseSize)
        {
            /*Pdu length is bigger than Page buffer max size */
            *ErrorCode = DCM_E_RESPONSETOOLONG;
            DslInternal_InitPageBuffer();
            ret = E_NOT_OK;
        }
        if (ret != E_NOT_OK)
        {
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            ret = DCM_E_PENDING;
        }
    }
#else
    {
        /*Pdu length is bigger than buffer size,ignore the request message */
        *ErrorCode = DCM_E_RESPONSETOOLONG;
        ret = E_NOT_OK;
    }
#endif
    if (E_OK == ret)
    {
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = MsgLen;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = MsgLen;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

#if (STD_ON == DCM_UDS_SERVICE0X19_02_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x02 sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) Dcm_UDS0x19_02_SubDealone(uint8 ProtocolCtrlId, Dcm_UDS0x19Types* Dcm_UDS0x19Type)
{
    boolean Flag;
    Dem_ReturnSetFilterType ReturnSetDTCFilter;
    Dem_ReturnGetNextFilteredElementType ReturnGetNextFilteredDTC;
    Dem_ReturnGetNumberOfFilteredDTCType ReturnGetNumberOfFilteredDTC;
    uint8 DtcStatus;
    uint32 Dtc;
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
#endif
    uint8 MsgCtrlId;
    uint8 DtcStatusMask;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    DtcStatusMask = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2];
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
#endif
    /*get DTCStatusAvailabilityMask*/

    ReturnSetDTCFilter = Dem_DcmSetDTCFilter(
        DtcStatusMask,
        DEM_DTC_KIND_ALL_DTCS,
        DEM_DTC_FORMAT_UDS,
        DEM_DTC_ORIGIN_PRIMARY_MEMORY,
        FALSE,
        DEM_SEVERITY_NO_SEVERITY,
        FALSE);
    if (DEM_FILTER_ACCEPTED == ReturnSetDTCFilter)
    {
        ReturnGetNumberOfFilteredDTC = Dem_DcmGetNumberOfFilteredDTC(Dcm_UDS0x19Type->DtcCount);
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
        if (Dcm_PageBufferData.TotalSize != 0UL)
        {
            *(Dcm_UDS0x19Type->DtcCount) = Dcm_PageBufferData.TotalDtcCount;
        }
#endif
        switch (ReturnGetNumberOfFilteredDTC)
        {
        case DEM_NUMBER_OK:
            Flag = FALSE;
            /* PRQA S 2462,2472,2463++ */ /* MISRA Rule 14.2 */
            for (*(Dcm_UDS0x19Type->Index) = 0;
                 (*(Dcm_UDS0x19Type->Index) < *(Dcm_UDS0x19Type->DtcCount)) && (FALSE == Flag)
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
                 && ((Dcm_PageBufferData.LastFilled == TRUE) || (Dcm_PageBufferData.TotalSize == 0UL))
#endif
                     ;
                 (*(Dcm_UDS0x19Type->Index))++)
            /* PRQA S 2462,2472,2463-- */ /* MISRA Rule 14.2 */
            {
                ReturnGetNextFilteredDTC = Dem_DcmGetNextFilteredDTC(&Dtc, &DtcStatus);
                switch (ReturnGetNextFilteredDTC)
                {
                case DEM_FILTERED_OK:
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
                    if (((Dcm_PageBufferData.TotalSize == 0UL)
                         || (*(Dcm_UDS0x19Type->Index) > Dcm_PageBufferData.IloopOne)
                         || (*(Dcm_UDS0x19Type->Index) == 0u))
                        && (((Dcm_PageBufferData.TotalSize != 0UL)
                             && (Dcm_PageBufferData.TotalDtcCount > *(Dcm_UDS0x19Type->Index)))
                            || (Dcm_PageBufferData.TotalSize == 0UL)))
#endif
                    {
                        SchM_Enter_Dcm(Dcm_Channel);
                        Dcm_Channel[Dcm_UDS0x19Type->Offset + *(Dcm_UDS0x19Type->MsgLen)] = (uint8)(Dtc >> 16u);
                        *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
                        Dcm_Channel[Dcm_UDS0x19Type->Offset + *(Dcm_UDS0x19Type->MsgLen)] = (uint8)(Dtc >> 8u);
                        *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
                        Dcm_Channel[Dcm_UDS0x19Type->Offset + *(Dcm_UDS0x19Type->MsgLen)] = (uint8)(Dtc);
                        *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
                        Dcm_Channel[Dcm_UDS0x19Type->Offset + *(Dcm_UDS0x19Type->MsgLen)] = DtcStatus;
                        SchM_Exit_Dcm(Dcm_Channel);
                        *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
                    }
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
                    if ((*(Dcm_UDS0x19Type->MsgLen)) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
                    {
                        SchM_Enter_Dcm(Dcm_PageBufferData);
                        Dcm_PageBufferData.LastFilled = FALSE;
                        SchM_Exit_Dcm(Dcm_PageBufferData);
                    }
#endif
                    break;
                case DEM_FILTERED_NO_MATCHING_ELEMENT:
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
                    if ((Dcm_PageBufferData.TotalSize != 0UL)
                        && (Dcm_PageBufferData.TotalDtcCount > *(Dcm_UDS0x19Type->Index)))
                    {
                        SchM_Enter_Dcm(Dcm_Channel);
                        Dcm_Channel[Dcm_UDS0x19Type->Offset + *(Dcm_UDS0x19Type->MsgLen)] = 0u;
                        *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
                        Dcm_Channel[Dcm_UDS0x19Type->Offset + *(Dcm_UDS0x19Type->MsgLen)] = 0u;
                        *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
                        Dcm_Channel[Dcm_UDS0x19Type->Offset + *(Dcm_UDS0x19Type->MsgLen)] = 0u;
                        *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
                        Dcm_Channel[Dcm_UDS0x19Type->Offset + *(Dcm_UDS0x19Type->MsgLen)] = 0u;
                        SchM_Exit_Dcm(Dcm_Channel);
                        *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
                        if ((*(Dcm_UDS0x19Type->MsgLen))
                            > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
                        {
                            SchM_Enter_Dcm(Dcm_PageBufferData);
                            Dcm_PageBufferData.LastFilled = FALSE;
                            SchM_Exit_Dcm(Dcm_PageBufferData);
                        }
                    }
                    else
#endif
                    {
                        *(Dcm_UDS0x19Type->NotAllowedFlag) = TRUE;
                        Flag = TRUE; /* PRQA S 2469 */ /* MISRA Rule 14.2 */
                    }
                    break;
                case DEM_FILTERED_PENDING:
                    *(Dcm_UDS0x19Type->PendingFlag) = TRUE;
                    Flag = TRUE; /* PRQA S 2469 */ /* MISRA Rule 14.2 */
                    break;
                case DEM_FILTERED_BUFFER_TOO_SMALL:
                default:
                    *(Dcm_UDS0x19Type->NotAllowedFlag) = TRUE;
                    Flag = TRUE; /* PRQA S 2469 */ /* MISRA Rule 14.2 */
                    break;
                }
            }
            break;
        case DEM_NUMBER_PENDING:
            *(Dcm_UDS0x19Type->PendingFlag) = TRUE;
            break;
        case DEM_NUMBER_FAILED:
        default:
            *(Dcm_UDS0x19Type->NotAllowedFlag) = TRUE;
            break;
        }
    }
    else
    {
        *(Dcm_UDS0x19Type->NotAllowedFlag) = TRUE;
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/************************************/
#if (STD_ON == DCM_UDS_SERVICE0X19_02_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x02 sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dcm_UDS0x19_02(uint8 ProtocolCtrlId, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 MsgCtrlId;
    uint32 Offset;
    uint16 Index = 0;
    uint16 DtcCount = 0;
    boolean NotAllowedFlag = FALSE;
    boolean PendingFlag = FALSE;
    Std_ReturnType ret = E_OK;
    Dcm_MsgLenType MsgLen;
    Dcm_UDS0x19Types Dcm_UDS0x19Type;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    /*check the massage length*/
    if (DCM_UDS0X19_SUBFUNC0X02_REQ_DATA_LENGTH != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
    {
        /*the length of massage is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    {
        /*find Tx buffer and offset*/
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
        MsgLen = 2u; /*keep two bytes to store response SID and echo of sub-function*/
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
        if (0u == Dcm_PageBufferData.PageIndex)
        {
            SchM_Enter_Dcm(Dcm_PageBufferData);
            Dcm_PageBufferData.PageTxOK = FALSE;
            SchM_Exit_Dcm(Dcm_PageBufferData);
#endif
            SchM_Enter_Dcm(Dcm_Channel);
            Dcm_Channel[Offset] = 0x59;
            Dcm_Channel[Offset + 1u] = 0x02;
            SchM_Exit_Dcm(Dcm_Channel);
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
            SchM_Enter_Dcm(Dcm_PageBufferData);
            Dcm_PageBufferData.LastFilled = TRUE;
            SchM_Exit_Dcm(Dcm_PageBufferData);
        }
        else
        {
            if (Dcm_PageBufferData.PageTxOK != TRUE)
            {
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                ret = DCM_E_PENDING;
            }
            MsgLen = 0u;
            Index = Dcm_PageBufferData.IloopOne;
            SchM_Enter_Dcm(Dcm_PageBufferData);
            Dcm_PageBufferData.PageTxOK = FALSE;
            Dcm_PageBufferData.LastFilled = TRUE;
            SchM_Exit_Dcm(Dcm_PageBufferData);
        }
#endif
        if (E_OK == ret)
        {
            ret = Dem_DcmGetDTCStatusAvailabilityMask(&Dcm_Channel[Offset + MsgLen]);
            if (E_OK == ret)
            {
                /*if DTCStatusAvailabilityMask = 0,no DTC*/
                if (0u == Dcm_Channel[Offset + MsgLen])
                {
                    MsgLen = MsgLen + 1u;
                }
                else
                {
                    MsgLen = MsgLen + 1u;
                    if (Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2] != 0u)
                    {
                        Dcm_UDS0x19Type.PendingFlag = &PendingFlag;
                        Dcm_UDS0x19Type.NotAllowedFlag = &NotAllowedFlag;
                        Dcm_UDS0x19Type.MsgLen = &MsgLen;
                        Dcm_UDS0x19Type.Index = &Index;
                        Dcm_UDS0x19Type.Offset = Offset;
                        Dcm_UDS0x19Type.DtcCount = &DtcCount;
                        Dcm_UDS0x19_02_SubDealone(ProtocolCtrlId, &Dcm_UDS0x19Type);
                    }
                }
            }
            else
            {
                NotAllowedFlag = TRUE;
            }
        }
        if (TRUE == NotAllowedFlag)
        {
            /*if fail to get any request information,send NRC 0x22*/
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        }
        else if (TRUE == PendingFlag)
        {
            /*if some request info is not available yet,enter pending and wait for the next cycle*/
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            ret = DCM_E_PENDING;
        }
        else
        {
            ret = Dcm_UDS0x19_02_SubDealTwo(ProtocolCtrlId, MsgLen, ErrorCode);
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/****************************************/
#if (STD_ON == DCM_UDS_SERVICE0X19_03_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x03 sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x19_03_SubDeal(
    uint8 ProtocolCtrlId,
    Dcm_MsgLenType MsgLen,
    uint16 iloop,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 MsgCtrlId;
    Std_ReturnType ret = E_OK;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    /*find Tx buffer and offset*/
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;

    /* check tx data length */
    if
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
        (
#endif
            ((MsgLen) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
            || (0UL != Dcm_PageBufferData.TotalSize))
    {
        if (0UL == Dcm_PageBufferData.TotalSize)
        {
            SchM_Enter_Dcm(Dcm_PageBufferData);
            Dcm_PageBufferData.TotalSize = MsgLen;
            SchM_Exit_Dcm(Dcm_PageBufferData);
            DsdInternal_StartPagedProcessing(ProtocolCtrlId);
        }
        else
        {
            if (Dcm_PageBufferData.LastFilled == TRUE)
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                Dcm_PageBufferData.IloopOne = iloop;
                Dcm_PageBufferData.ThisPageSize = (uint16)MsgLen;
                SchM_Exit_Dcm(Dcm_PageBufferData);
            }
            else
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                Dcm_PageBufferData.IloopOne = iloop - 1u;
                Dcm_PageBufferData.ThisPageSize = (uint16)(MsgLen - 4u);
                SchM_Exit_Dcm(Dcm_PageBufferData);
            }
            SchM_Enter_Dcm(Dcm_PageBufferData);
            Dcm_PageBufferData.PageIndex += 1u;
            Dcm_PageBufferData.Filled = TRUE;
            SchM_Exit_Dcm(Dcm_PageBufferData);
            DsdInternal_ProcessPage(ProtocolCtrlId);
            if (Dcm_PageBufferData.TimeOut == TRUE)
            {
                ret = E_NOT_OK;
            }
            if (E_OK == ret)
            {
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                ret = DCM_E_PENDING;
            }
        }
        if (Dcm_PageBufferData.TotalSize
            > Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId].DcmDslProtocolMaximumResponseSize)
        {
            /*Pdu length is bigger than Page buffer max size */
            *ErrorCode = DCM_E_RESPONSETOOLONG;
            DslInternal_InitPageBuffer();
            ret = E_NOT_OK;
        }
        if (E_OK == ret)
        {
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            ret = DCM_E_PENDING;
        }
    }
#else
    {
        /*Pdu length is bigger than buffer size,ignore the request message */
        *ErrorCode = DCM_E_RESPONSETOOLONG;
        ret = E_NOT_OK;
    }
#endif
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/****************************************/
#if (STD_ON == DCM_UDS_SERVICE0X19_03_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x03 sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE)
    Dcm_UDS0x19_03(uint8 ProtocolCtrlId, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
{
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 SnapshotRecord;
    uint8 MsgCtrlId;
    uint32 Offset;
    uint32 Dtc;
    Dcm_MsgLenType MsgLen;
    Dem_ReturnGetNextFilteredElementType ReturnGetNextFilteredElement = DEM_FILTERED_OK;
    uint16 NumberOfFilteredRecords = 0;
    uint16 iloop;
    Std_ReturnType ret = E_OK;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    /**************************************************/
    /*check the massage length*/
    if (DCM_UDS0X19_SUBFUNC0X03_REQ_DATA_LENGTH != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
    {
        /*the length of massage is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }

    if (E_OK == ret)
    {
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
        if (0u == Dcm_PageBufferData.PageIndex)
        {
            SchM_Enter_Dcm(Dcm_PageBufferData);
            Dcm_PageBufferData.PageTxOK = FALSE;
            Dcm_PageBufferData.LastFilled = TRUE;
            SchM_Exit_Dcm(Dcm_PageBufferData);
        }
        else
        {
            if (Dcm_PageBufferData.PageTxOK != TRUE)
            {
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                ret = DCM_E_PENDING;
            }
            else
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                Dcm_PageBufferData.PageTxOK = FALSE;
                Dcm_PageBufferData.LastFilled = TRUE;
                SchM_Exit_Dcm(Dcm_PageBufferData);
            }
        }
#endif
        if (E_OK == ret)
        {
            /*find Tx buffer and offset*/
            TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
            TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
            Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;

            if (DEM_WRONG_FILTER == Dem_DcmSetFreezeFrameRecordFilter(DEM_DTC_FORMAT_UDS, &NumberOfFilteredRecords))
            {
                /*if fail to set filter,send NRC 0x31*/
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
        }
    }

    if (E_OK == ret)
    {
        MsgLen = 2u;
        for (iloop = 0;
             ((iloop < NumberOfFilteredRecords) && (ReturnGetNextFilteredElement != DEM_FILTERED_NO_MATCHING_ELEMENT));
             iloop++)
        {
            /*read-out the corresponding FreezeFrameRecord*/
            ReturnGetNextFilteredElement = Dem_DcmGetNextFilteredRecord(&Dtc, &SnapshotRecord);
            if (ReturnGetNextFilteredElement == DEM_FILTERED_OK)
            {
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
                if (iloop >= Dcm_PageBufferData.IloopOne)
#endif
                {
                    SchM_Enter_Dcm(Dcm_Channel);
                    Dcm_Channel[Offset + MsgLen] = (uint8)(Dtc >> 16u);
                    MsgLen = MsgLen + 1u;
                    Dcm_Channel[Offset + MsgLen] = (uint8)(Dtc >> 8u);
                    MsgLen = MsgLen + 1u;
                    Dcm_Channel[Offset + MsgLen] = (uint8)(Dtc);
                    MsgLen = MsgLen + 1u;
                    Dcm_Channel[Offset + MsgLen] = SnapshotRecord;
                    SchM_Exit_Dcm(Dcm_Channel);
                    MsgLen = MsgLen + 1u;
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
                    if ((MsgLen) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
                    {
                        SchM_Enter_Dcm(Dcm_PageBufferData);
                        Dcm_PageBufferData.LastFilled = FALSE;
                        SchM_Exit_Dcm(Dcm_PageBufferData);
                    }
#endif
                }
            }
        }
        /* check tx data length */
        ret = Dcm_UDS0x19_03_SubDeal(ProtocolCtrlId, MsgLen, iloop, ErrorCode);
    }
    if (E_OK == ret)
    {
        /*assemble positive response*/
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x59;
        Dcm_Channel[Offset + 1u] = 0x03;
        SchM_Exit_Dcm(Dcm_Channel);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = MsgLen;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = MsgLen;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/****************************************/
#if (STD_ON == DCM_UDS_SERVICE0X19_04_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x04 sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x19_04_SubSubDeal(
    uint8 ProtocolCtrlId,
    Dcm_UDS0x19Types* Dcm_UDS0x19Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint32 CurBufferSize;
    uint16 BufferSize;
    uint8 DtcStatus;
    uint8 Index;
    uint8 MsgCtrlId;
    uint32 ChannelSize;
    uint32 Offset;
    uint32 Dtc;
    Dem_ReturnGetFreezeFrameDataByDTCType retGetFreezeFrameDataByDTC;
    Dem_ReturnDisableDTCRecordUpdateType ReturnDisableDTCRecordUpdate;
    uint8 cnt = 0;
    Std_ReturnType ret = E_OK;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    /*find Tx buffer and offset*/
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    ChannelSize = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].Dcm_DslBufferSize;
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
    /*get DTC and reoord number from request message*/
    Dtc = (((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2]) << 16u)
          | (((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3]) << 8u)
          | (((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4]));
    /*read-out the correspoding DtcStatus of required DTC*/
    (void)Dem_DcmGetStatusOfDTC(Dtc, DEM_DTC_ORIGIN_PRIMARY_MEMORY, &DtcStatus);
    *(Dcm_UDS0x19Type->MsgLen) = 2u;
    SchM_Enter_Dcm(Dcm_Channel);
    Dcm_Channel[Offset + *(Dcm_UDS0x19Type->MsgLen)] = (uint8)(Dtc >> 16u);
    *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
    Dcm_Channel[Offset + *(Dcm_UDS0x19Type->MsgLen)] = (uint8)(Dtc >> 8u);
    *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
    Dcm_Channel[Offset + *(Dcm_UDS0x19Type->MsgLen)] = (uint8)(Dtc);
    *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
    Dcm_Channel[Offset + *(Dcm_UDS0x19Type->MsgLen)] = DtcStatus;
    SchM_Exit_Dcm(Dcm_Channel);
    *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;

    ReturnDisableDTCRecordUpdate = Dem_DcmDisableDTCRecordUpdate(Dtc, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
    if (DEM_DISABLE_DTCRECUP_OK == ReturnDisableDTCRecordUpdate)
    {
        for (Index = 1u; (Index < 0xEFu) && (ret == E_OK); Index++)
        { /*reserve 1byte to store record number*/
            CurBufferSize = (ChannelSize - *(Dcm_UDS0x19Type->MsgLen) - 1u);
            BufferSize = (uint16)CurBufferSize;
            retGetFreezeFrameDataByDTC = Dem_DcmGetFreezeFrameDataByDTC(
                Dtc,
                DEM_DTC_ORIGIN_PRIMARY_MEMORY,
                Index,
                &Dcm_Channel[Offset + *(Dcm_UDS0x19Type->MsgLen) + 1u],
                &BufferSize);
            if (DEM_GET_FFDATABYDTC_OK == retGetFreezeFrameDataByDTC)
            {
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_Channel[Offset + *(Dcm_UDS0x19Type->MsgLen)] = Index;
                SchM_Exit_Dcm(Dcm_Channel);
                *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + (uint32)BufferSize + 1u;
            }
            else if (DEM_GET_FFDATABYDTC_PENDING == retGetFreezeFrameDataByDTC)
            {
                *(Dcm_UDS0x19Type->PendingFlag) = TRUE;
                break;
            }
            else if (
                (DEM_GET_FFDATABYDTC_WRONG_DTC == retGetFreezeFrameDataByDTC)
                || (DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN == retGetFreezeFrameDataByDTC))
            { /*if fail to get any request information,send NRC 0x31*/
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                (void)Dem_DcmEnableDTCRecordUpdate();
                ret = E_NOT_OK;
            }
            else
            {
                if (DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER == retGetFreezeFrameDataByDTC)
                {
                    cnt++;
                }
                if (cnt == 0xEFu)
                { /*if fail to get any request information,send NRC 0x31*/
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    (void)Dem_DcmEnableDTCRecordUpdate();
                    ret = E_NOT_OK;
                }
            }
        }
        if (E_OK != Dem_DcmEnableDTCRecordUpdate())
        {
            *(Dcm_UDS0x19Type->NotAllowedFlag) = TRUE;
        }
    }
    else if (DEM_DISABLE_DTCRECUP_WRONG_DTC == ReturnDisableDTCRecordUpdate)
    {
        *(Dcm_UDS0x19Type->NotAllowedFlag) = TRUE;
    }
    else
    {
        /*idle*/
    }

    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/****************************************/
#if (STD_ON == DCM_UDS_SERVICE0X19_04_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x04 sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x19_04_SubDeal(
    uint8 ProtocolCtrlId,
    Dcm_UDS0x19Types* Dcm_UDS0x19Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint32 CurBufferSize;
    uint16 BufferSize;
    uint8 DtcStatus;
    uint8 SnapshotRecord;
    uint8 MsgCtrlId;
    uint32 ChannelSize;
    uint32 Offset;
    uint32 Dtc;
    Dem_ReturnGetFreezeFrameDataByDTCType retGetFreezeFrameDataByDTC;
    Dem_ReturnDisableDTCRecordUpdateType ReturnDisableDTCRecordUpdate;
    Std_ReturnType ret = E_OK;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    /*find Tx buffer and offset*/
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    ChannelSize = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].Dcm_DslBufferSize;
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
    /*get DTC and reoord number from request message*/
    Dtc = (((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2]) << 16u)
          | (((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3]) << 8u)
          | (((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4]));
    SnapshotRecord = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[5];
    /*read-out the correspoding DtcStatus of required DTC*/
    (void)Dem_DcmGetStatusOfDTC(Dtc, DEM_DTC_ORIGIN_PRIMARY_MEMORY, &DtcStatus);
    *(Dcm_UDS0x19Type->MsgLen) = 2u;
    SchM_Enter_Dcm(Dcm_Channel);
    Dcm_Channel[Offset + *(Dcm_UDS0x19Type->MsgLen)] = (uint8)(Dtc >> 16u);
    *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
    Dcm_Channel[Offset + *(Dcm_UDS0x19Type->MsgLen)] = (uint8)(Dtc >> 8u);
    *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
    Dcm_Channel[Offset + *(Dcm_UDS0x19Type->MsgLen)] = (uint8)(Dtc);
    *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
    Dcm_Channel[Offset + *(Dcm_UDS0x19Type->MsgLen)] = DtcStatus;
    SchM_Exit_Dcm(Dcm_Channel);
    *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + 1u;
    if (0xFFu == SnapshotRecord)
    {
        ret = Dcm_UDS0x19_04_SubSubDeal(ProtocolCtrlId, Dcm_UDS0x19Type, ErrorCode);
    }
    else
    { /*read-out the correspoding snapshot by SnapshotRecord*/
        ReturnDisableDTCRecordUpdate = Dem_DcmDisableDTCRecordUpdate(Dtc, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
        if (DEM_DISABLE_DTCRECUP_OK == ReturnDisableDTCRecordUpdate)
        { /*reserve 1byte to store record number*/
            CurBufferSize = (ChannelSize - *(Dcm_UDS0x19Type->MsgLen) - 1u);
            BufferSize = (uint16)CurBufferSize;
            retGetFreezeFrameDataByDTC = Dem_DcmGetFreezeFrameDataByDTC(
                Dtc,
                DEM_DTC_ORIGIN_PRIMARY_MEMORY,
                SnapshotRecord,
                &Dcm_Channel[Offset + *(Dcm_UDS0x19Type->MsgLen) + 1u],
                &BufferSize);
            if (DEM_GET_FFDATABYDTC_OK == retGetFreezeFrameDataByDTC)
            {
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_Channel[Offset + *(Dcm_UDS0x19Type->MsgLen)] = SnapshotRecord;
                SchM_Exit_Dcm(Dcm_Channel);
                *(Dcm_UDS0x19Type->MsgLen) = *(Dcm_UDS0x19Type->MsgLen) + (uint32)BufferSize + 1u;
            }
            else if (DEM_GET_FFDATABYDTC_PENDING == retGetFreezeFrameDataByDTC)
            {
                *(Dcm_UDS0x19Type->PendingFlag) = TRUE;
            }
            else if (
                (DEM_GET_FFDATABYDTC_WRONG_DTC == retGetFreezeFrameDataByDTC)
                || (DEM_GET_FFDATABYDTC_WRONG_DTCORIGIN == retGetFreezeFrameDataByDTC)
                || (DEM_GET_FFDATABYDTC_WRONG_RECORDNUMBER == retGetFreezeFrameDataByDTC))
            { /*if fail to get any request information,send NRC 0x31*/
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                (void)Dem_DcmEnableDTCRecordUpdate();
                ret = E_NOT_OK;
            }
            else
            {
                /*idle*/
            }
            if (E_OK != Dem_DcmEnableDTCRecordUpdate())
            {
                *(Dcm_UDS0x19Type->NotAllowedFlag) = TRUE;
            }
        }
        else if (DEM_DISABLE_DTCRECUP_WRONG_DTC == ReturnDisableDTCRecordUpdate)
        {
            *(Dcm_UDS0x19Type->NotAllowedFlag) = TRUE;
        }
        else
        {
            /*idle*/
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/****************************************/
#if (STD_ON == DCM_UDS_SERVICE0X19_04_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x04 sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dcm_UDS0x19_04(uint8 ProtocolCtrlId, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 MsgCtrlId;
    uint32 Offset;
    boolean NotAllowedFlag = FALSE;
    boolean PendingFlag = FALSE;
    Dcm_MsgLenType MsgLen;
    Std_ReturnType ret = E_OK;
    Dcm_UDS0x19Types Dcm_UDS0x19Type;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    if (DCM_UDS0X19_SUBFUNC0X04_REQ_DATA_LENGTH != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
    { /*the length of massage is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    {
        /*find Tx buffer and offset*/
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
        Dcm_UDS0x19Type.MsgLen = &MsgLen;
        Dcm_UDS0x19Type.NotAllowedFlag = &NotAllowedFlag;
        Dcm_UDS0x19Type.PendingFlag = &PendingFlag;
        ret = Dcm_UDS0x19_04_SubDeal(ProtocolCtrlId, &Dcm_UDS0x19Type, ErrorCode);
        if (TRUE == NotAllowedFlag)
        { /*if fail to get any request information,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
        else if (TRUE == PendingFlag)
        { /*if some request info is not available yet,enter pending and wait for the next cycle*/
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            ret = DCM_E_PENDING;
        }
        else
        {
            if (E_OK == ret)
            {     /* check tx data length */
                if ((MsgLen) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
                { /*Pdu length is bigger than buffer size,ignore the request message */
                    *ErrorCode = DCM_E_RESPONSETOOLONG;
                    ret = E_NOT_OK;
                }
                if (E_OK == ret)
                { /*assemble positive response*/
                    SchM_Enter_Dcm(Dcm_Channel);
                    Dcm_Channel[Offset] = 0x59;
                    Dcm_Channel[Offset + 1u] = 0x04;
                    SchM_Exit_Dcm(Dcm_Channel);
                    SchM_Enter_Dcm(Dcm_MsgCtrl);
                    Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = MsgLen;
                    Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = MsgLen;
                    Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
                    SchM_Exit_Dcm(Dcm_MsgCtrl);
                    DsdInternal_ProcessingDone(ProtocolCtrlId);
                }
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/******************************************/
#if (STD_ON == DCM_UDS_SERVICE0X19_06_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x06 sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x19_06SubDeal(
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(boolean, AUTOMATIC, DCM_VAR) PendingFlag,
    P2VAR(Dcm_MsgLenType, AUTOMATIC, DCM_VAR) MsgLen,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint32 CurChannelSize;
    uint16 Size;
    uint8 Index;
    uint8 DtcExtendedDataRecordNumber;
    uint8 MsgCtrlId;
    uint32 ChannelSize;
    uint32 Offset;
    uint32 Dtc;
    Dem_EventIdType EventId = 0;
    uint16 dtcRef;
    Dem_ReturnGetExtendedDataRecordByDTCType ReturnGetExtendedDataRecord;
    uint8 cnt = 0;
    uint8 count = 0;
    Std_ReturnType ret = E_OK;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex; /*check the massage length*/

    /*find Tx buffer and offset*/
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    ChannelSize = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].Dcm_DslBufferSize;
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
    /*get DTC and record number from request message*/
    Dtc = (((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2]) << 16u)
          | (((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3]) << 8u)
          | (((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4]));
    DtcExtendedDataRecordNumber = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[5];

    /*DTC + (equal to 0xFF or 0xFE)*/
    /*read-out the corresponding extended data of required DTC*/
    if (0xFEu == DtcExtendedDataRecordNumber)
    {
        /*read-out OBD relative extended data of required DTC*/
        Index = 0x90u;
        count = 0x60u;
    }
    else
    {
        Index = 0x01u;
        count = 0xEFu;
    }

    for (; Index <= 0xEFu; Index++)
    {
        /*calculate the remained size of Tx buffer,keep one byte to store record number*/
        CurChannelSize = (ChannelSize - (*MsgLen) - 1u);
        Size = (uint16)CurChannelSize;
        ReturnGetExtendedDataRecord = Dem_DcmGetExtendedDataRecordByDTC(
            Dtc,
            DEM_DTC_ORIGIN_PRIMARY_MEMORY,
            Index,
            &Dcm_Channel[Offset + (*MsgLen) + 1u],
            &Size);
        if ((DEM_RECORD_OK == ReturnGetExtendedDataRecord) && (Size != 0u))
        {
            /*save DTCExtendDataRecordNumber to Tx buffer*/
            SchM_Enter_Dcm(Dcm_Channel);
            Dcm_Channel[Offset + (*MsgLen)] = Index;
            SchM_Exit_Dcm(Dcm_Channel);

            /*************add for Gecko ********************/
              while (EventId < DEM_EVENT_PARAMETER_NUM)
            {
                dtcRef = DemPbCfgPtr->DemEventParameter[EventId].DemDTCRef;
                if ((dtcRef != DEM_DTC_REF_INVALID) && (DemPbCfgPtr->DemDTC[dtcRef].DemDtcValue) == Dtc && (Index == 0x01))
                {
                  Dcm_Channel[Offset + (*MsgLen) + 1u] = DemEventRelateInformation[EventId].OccurrenceCounter;
                  Dcm_Channel[Offset + (*MsgLen) + 2u] = DemEventRelateInformation[EventId].AgedCounter;
                
                }
                EventId++;
            }
            (*MsgLen) = (*MsgLen) + 1u;
            /*successfully store extended data,increase MsgLen*/
            (*MsgLen) = (*MsgLen) + (uint32)Size;
        }
        else if (DEM_RECORD_PENDING == ReturnGetExtendedDataRecord)
        {
            *PendingFlag = TRUE;
            break;
        }
        else if (0xFFu == DtcExtendedDataRecordNumber)
        {
            if ((DEM_RECORD_WRONG_DTC == ReturnGetExtendedDataRecord)
                || (DEM_RECORD_WRONG_DTCORIGIN == ReturnGetExtendedDataRecord))
            {
                /*if fail to get any request information,send NRC 0x31*/
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                (void)Dem_DcmEnableDTCRecordUpdate();
                ret = E_NOT_OK;
            }
        }
        else
        {
            if (DEM_RECORD_WRONG_NUMBER == ReturnGetExtendedDataRecord)
            {
                cnt++;
            }
            if (cnt == count)
            {
                /*if fail to get any request information,send NRC 0x31*/
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                (void)Dem_DcmEnableDTCRecordUpdate();
                ret = E_NOT_OK;
            }
            /*nothing to do,just keep the format consistent*/
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/******************************************/
#if (STD_ON == DCM_UDS_SERVICE0X19_06_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x06 sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dcm_UDS0x19_06(uint8 ProtocolCtrlId, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint32 CurChannelSize;
    uint8 DtcStatus;
    uint8 DtcExtendedDataRecordNumber;
    uint8 MsgCtrlId;
    uint32 ChannelSize;
    uint32 Offset;
    uint32 Dtc;
    boolean NotAllowedFlag = FALSE;
    boolean PendingFlag = FALSE;
    Dem_EventIdType EventId = 0;
    uint16 dtcRef;
    Dcm_MsgLenType MsgLen;
    Dem_ReturnGetExtendedDataRecordByDTCType ReturnGetExtendedDataRecord;
    Dem_ReturnDisableDTCRecordUpdateType ReturnDisableDTCRecordUpdate;
    Std_ReturnType ret = E_OK;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex; /*check the massage length*/
    if (DCM_UDS0X19_SUBFUNC0X06_REQ_DATA_LENGTH != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
    {
        /*the length of massage is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }
    else
    {
        /*find Tx buffer and offset*/
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        ChannelSize = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].Dcm_DslBufferSize;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
        /*get DTC and record number from request message*/
        Dtc = (((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2]) << 16u)
              | (((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3]) << 8u)
              | (((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4]));
        DtcExtendedDataRecordNumber = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[5];
        /*read-out the corresponding DtcStatus of required DTC*/
        (void)Dem_DcmGetStatusOfDTC(Dtc, DEM_DTC_ORIGIN_PRIMARY_MEMORY, &DtcStatus);
        MsgLen = 2u;
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset + MsgLen] = (uint8)(Dtc >> 16u);
        MsgLen = MsgLen + 1u;
        Dcm_Channel[Offset + MsgLen] = (uint8)(Dtc >> 8u);
        MsgLen = MsgLen + 1u;
        Dcm_Channel[Offset + MsgLen] = (uint8)Dtc;
        MsgLen = MsgLen + 1u;
        Dcm_Channel[Offset + MsgLen] = DtcStatus;
        SchM_Exit_Dcm(Dcm_Channel);
        MsgLen = MsgLen + 1u;
        /*read-out the corresponding extended data of DtcExtendedDataRecordNumber*/
        /*disable DTC record update*/
        ReturnDisableDTCRecordUpdate = Dem_DcmDisableDTCRecordUpdate(Dtc, DEM_DTC_ORIGIN_PRIMARY_MEMORY);
        if (DEM_DISABLE_DTCRECUP_OK == ReturnDisableDTCRecordUpdate)
        {
            if ((0xFEu == DtcExtendedDataRecordNumber) || (0xFFu == DtcExtendedDataRecordNumber))
            {
                ret = Dcm_UDS0x19_06SubDeal(ProtocolCtrlId, &PendingFlag, &MsgLen, ErrorCode);
            }
            /*DTC + (not 0xFF nor 0xFE)*/
            else
            {
                /*calculate the remained size of Tx buffer,keep one byte to store record number*/
                CurChannelSize = ChannelSize - MsgLen - 1u;
                ReturnGetExtendedDataRecord = Dem_DcmGetExtendedDataRecordByDTC(
                    Dtc,
                    DEM_DTC_ORIGIN_PRIMARY_MEMORY,
                    DtcExtendedDataRecordNumber,
                    &Dcm_Channel[Offset + MsgLen + 1u],
                    (uint16*)&CurChannelSize);
                if ((DEM_RECORD_OK == ReturnGetExtendedDataRecord) && (CurChannelSize != 0u))
                {
                    /*store extended data record number*/
                    SchM_Enter_Dcm(Dcm_Channel);
                    Dcm_Channel[Offset + MsgLen] = DtcExtendedDataRecordNumber;
                    SchM_Exit_Dcm(Dcm_Channel);
                    /*************add for Gecko ********************/
                    while (EventId < DEM_EVENT_PARAMETER_NUM)
                {
                    dtcRef = DemPbCfgPtr->DemEventParameter[EventId].DemDTCRef;
                    if ((dtcRef != DEM_DTC_REF_INVALID) && (DemPbCfgPtr->DemDTC[dtcRef].DemDtcValue) == Dtc && (DtcExtendedDataRecordNumber == 0x01))
                    {
                      Dcm_Channel[Offset + MsgLen + 1u] = DemEventRelateInformation[EventId].OccurrenceCounter;
                      Dcm_Channel[Offset + MsgLen + 2u] = DemEventRelateInformation[EventId].AgedCounter;
                    
                    }
                     EventId++;
                }
                    MsgLen = MsgLen + 1u;
                    /*successfully store extended data,increase MsgLen*/
                    MsgLen = MsgLen + CurChannelSize;
                }
                else if (DEM_RECORD_PENDING == ReturnGetExtendedDataRecord)
                {
                    PendingFlag = TRUE;
                }
                else if (
                    (DEM_RECORD_WRONG_DTC == ReturnGetExtendedDataRecord)
                    || (DEM_RECORD_WRONG_DTCORIGIN == ReturnGetExtendedDataRecord)
                    || (DEM_RECORD_WRONG_NUMBER == ReturnGetExtendedDataRecord))
                { /*if fail to get any request information,send NRC 0x31*/
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    (void)Dem_DcmEnableDTCRecordUpdate();
                    ret = E_NOT_OK;
                }
                else
                {
                    /*idle*/
                }
            }
            /*enable DTC record update*/
            if (E_NOT_OK == Dem_DcmEnableDTCRecordUpdate())
            {
                NotAllowedFlag = TRUE;
            }
        }
        else if (DEM_DISABLE_DTCRECUP_WRONG_DTC == ReturnDisableDTCRecordUpdate)
        {
            NotAllowedFlag = TRUE;
        }
        else
        {
            /*idle*/
        }
        if (E_OK == ret)
        {
            if (TRUE == NotAllowedFlag)
            {
                /*if fail to get any request information,send NRC 0x31*/
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
            else if (TRUE == PendingFlag)
            { /*if some request info is not available yet,
             enter pending and wait for the next cycle*/
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                ret = DCM_E_PENDING;
            }
            else
            {
                /* check tx data length */
                if ((MsgLen) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
                {
                    /*Pdu length is bigger than buffer size,ignore the request message */
                    *ErrorCode = DCM_E_RESPONSETOOLONG;
                    ret = E_NOT_OK;
                }
                else
                {
                    /*assemble positive response*/
                    SchM_Enter_Dcm(Dcm_Channel);
                    Dcm_Channel[Offset] = 0x59;
                    Dcm_Channel[Offset + 1u] = 0x06;
                    SchM_Exit_Dcm(Dcm_Channel);
                    SchM_Enter_Dcm(Dcm_MsgCtrl);
                    Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = MsgLen;
                    Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = MsgLen;
                    Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
                    SchM_Exit_Dcm(Dcm_MsgCtrl);
                    DsdInternal_ProcessingDone(ProtocolCtrlId);
                }
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
#if (STD_ON == DCM_UDS_SERVICE0X19_0A_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x0A sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x19_0ADeal(
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DtcCount,
    P2VAR(Dcm_MsgLenType, AUTOMATIC, DCM_VAR) MsgLen,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
    boolean Flag;
    uint16 Index;
    uint8 DtcStatus;
    uint32 Dtc;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 MsgCtrlId;
    uint32 Offset;
    Dem_ReturnSetFilterType ReturnSetDTCFilter;
    Dem_ReturnGetNextFilteredElementType ReturnGetNextFilteredDTC;
    Dem_ReturnGetNumberOfFilteredDTCType ReturnGetNumberOfFilteredDTC;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    /*find Tx buffer and offset*/
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;

    if (0u == Dcm_Channel[Offset + (*MsgLen)])
    {
        (*MsgLen) = (*MsgLen) + 1u;
    }
    else
    {
        /*one byte for the storage of DTC status availability mask*/
        (*MsgLen) = (*MsgLen) + 1u;
        ReturnSetDTCFilter = Dem_DcmSetDTCFilter(
            0x00,
            DEM_DTC_KIND_ALL_DTCS,
            DEM_DTC_FORMAT_UDS,
            DEM_DTC_ORIGIN_PRIMARY_MEMORY,
            FALSE,
            DEM_SEVERITY_NO_SEVERITY,
            FALSE);
        if (DEM_FILTER_ACCEPTED == ReturnSetDTCFilter)
        {
            ReturnGetNumberOfFilteredDTC = Dem_DcmGetNumberOfFilteredDTC(DtcCount);
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
            if (Dcm_PageBufferData.TotalSize != 0UL)
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                *DtcCount = Dcm_PageBufferData.TotalDtcCount;
                SchM_Exit_Dcm(Dcm_PageBufferData);
            }
#endif
            switch (ReturnGetNumberOfFilteredDTC)
            {
            case DEM_NUMBER_OK:
                Flag = FALSE;
                for (Index = 0; (Index < *DtcCount) && (FALSE == Flag)
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
                                && ((Dcm_PageBufferData.LastFilled == TRUE) || (Dcm_PageBufferData.TotalSize == 0UL))
#endif
                         ;
                     Index++)
                {
                    ReturnGetNextFilteredDTC = Dem_DcmGetNextFilteredDTC(&Dtc, &DtcStatus);
                    switch (ReturnGetNextFilteredDTC)
                    {
                    case DEM_FILTERED_OK:
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
                        if (((Dcm_PageBufferData.TotalSize == 0UL) || (Index > Dcm_PageBufferData.IloopOne)
                             || (Index == 0u))
                            && (((Dcm_PageBufferData.TotalSize != 0UL) && (Dcm_PageBufferData.TotalDtcCount > Index))
                                || (Dcm_PageBufferData.TotalSize == 0UL)))
#endif
                        {
                            SchM_Enter_Dcm(Dcm_Channel);
                            Dcm_Channel[Offset + (*MsgLen)] = (uint8)(Dtc >> 16u);
                            (*MsgLen) = (*MsgLen) + 1u;
                            Dcm_Channel[Offset + (*MsgLen)] = (uint8)(Dtc >> 8u);
                            (*MsgLen) = (*MsgLen) + 1u;
                            Dcm_Channel[Offset + (*MsgLen)] = (uint8)(Dtc);
                            (*MsgLen) = (*MsgLen) + 1u;
                            Dcm_Channel[Offset + (*MsgLen)] = DtcStatus;
                            SchM_Exit_Dcm(Dcm_Channel);
                            *MsgLen = *MsgLen + 1u;
                        }
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
                        if ((*MsgLen) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
                        {
                            SchM_Enter_Dcm(Dcm_PageBufferData);
                            Dcm_PageBufferData.LastFilled = FALSE;
                            SchM_Exit_Dcm(Dcm_PageBufferData);
                        }
#endif
                        break;
                    case DEM_FILTERED_NO_MATCHING_ELEMENT:
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
                        if ((Dcm_PageBufferData.TotalSize != 0UL) && (Dcm_PageBufferData.TotalDtcCount > Index))
                        {
                            SchM_Enter_Dcm(Dcm_Channel);
                            Dcm_Channel[Offset + (*MsgLen)] = 0u;
                            (*MsgLen) = (*MsgLen) + 1u;
                            Dcm_Channel[Offset + (*MsgLen)] = 0u;
                            (*MsgLen) = (*MsgLen) + 1u;
                            Dcm_Channel[Offset + (*MsgLen)] = 0u;
                            (*MsgLen) = (*MsgLen) + 1u;
                            Dcm_Channel[Offset + (*MsgLen)] = 0u;
                            SchM_Exit_Dcm(Dcm_Channel);
                            (*MsgLen) = (*MsgLen) + 1u;
                            if ((*MsgLen) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
                            {
                                SchM_Enter_Dcm(Dcm_PageBufferData);
                                Dcm_PageBufferData.LastFilled = FALSE;
                                SchM_Exit_Dcm(Dcm_PageBufferData);
                            }
                        }
                        else
#endif
                        {
                            /*if fail to get any request information,send NRC 0x22*/
                            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                            ret = E_NOT_OK;
                            Flag = TRUE;
                        }
                        break;
                    case DEM_FILTERED_PENDING:
                        /*if some request info is not available yet,
                         * enter pending and wait for the next cycle*/
                        SchM_Enter_Dcm(Dcm_MsgCtrl);
                        Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                        SchM_Exit_Dcm(Dcm_MsgCtrl);
                        ret = DCM_E_PENDING;
                        Flag = TRUE;
                        break;
                    case DEM_FILTERED_BUFFER_TOO_SMALL:
                    default:
                        /*if fail to get any request information,send NRC 0x22*/
                        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                        ret = E_NOT_OK;
                        Flag = TRUE;
                        break;
                    }
                }
                break;
            case DEM_NUMBER_PENDING:
                /*if some request info is not available yet,
                 * enter pending and wait for the next cycle*/
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                ret = DCM_E_PENDING;
                break;
            case DEM_NUMBER_FAILED:
            default:
                /*if fail to get any request information,send NRC 0x22*/
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                ret = E_NOT_OK;
                break;
            }
        }
    }
    return ret;
}
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x0A sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
static FUNC(Std_ReturnType, DCM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dcm_UDS0x19_0A(uint8 ProtocolCtrlId, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 MsgCtrlId;
    uint32 Offset;
    uint16 DtcCount = 0;
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    uint16 Index = 0;
#endif
    Std_ReturnType ret = E_OK;
    Dcm_MsgLenType MsgLen = 2u; /*store response SID and echo of sub-function*/

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    if (DCM_UDS0X19_SUBFUNC0X0A_REQ_DATA_LENGTH != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
    { /*the length of massage is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    { /*find Tx buffer and offset*/
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
        if (0u == Dcm_PageBufferData.PageIndex)
        {
            SchM_Enter_Dcm(Dcm_PageBufferData);
            Dcm_PageBufferData.PageTxOK = FALSE;
            SchM_Exit_Dcm(Dcm_PageBufferData);
#endif
            SchM_Enter_Dcm(Dcm_Channel);
            Dcm_Channel[Offset] = 0x59u;
            Dcm_Channel[Offset + 1u] = 0x0Au;
            SchM_Exit_Dcm(Dcm_Channel);
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
            Dcm_PageBufferData.LastFilled = TRUE;
        }
        else
        {
            if (Dcm_PageBufferData.PageTxOK != TRUE)
            {
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                ret = DCM_E_PENDING;
            }
            MsgLen = 0;
            Index = Dcm_PageBufferData.IloopOne;
            SchM_Enter_Dcm(Dcm_PageBufferData);
            Dcm_PageBufferData.PageTxOK = FALSE;
            Dcm_PageBufferData.LastFilled = TRUE;
            SchM_Exit_Dcm(Dcm_PageBufferData);
        }
#endif
        /*get DTCStatusAvailabilityMask*/
        if (E_OK == ret)
        {
            ret = Dem_DcmGetDTCStatusAvailabilityMask(&Dcm_Channel[Offset + MsgLen]);
        }
        if (E_OK == ret)
        {
            ret = Dcm_UDS0x19_0ADeal(ProtocolCtrlId, &DtcCount, &MsgLen, ErrorCode);
        }
        if (E_OK == ret)
        {
            if
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
                (
#endif
                    ((MsgLen) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
                    || (0u != Dcm_PageBufferData.TotalSize))
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                if (0u == Dcm_PageBufferData.TotalSize)
                {
                    Dcm_PageBufferData.TotalSize = MsgLen;
                    Dcm_PageBufferData.TotalDtcCount = DtcCount;
                    DsdInternal_StartPagedProcessing(ProtocolCtrlId);
                }
                else
                {
                    if (Dcm_PageBufferData.LastFilled == TRUE)
                    {
                        Dcm_PageBufferData.IloopOne = Index;
                        Dcm_PageBufferData.ThisPageSize = (uint16)MsgLen;
                    }
                    else
                    {
                        Dcm_PageBufferData.IloopOne = Index - 1u;
                        Dcm_PageBufferData.ThisPageSize = (uint16)(MsgLen - 4u);
                    }
                    Dcm_PageBufferData.PageIndex += 1u;
                    Dcm_PageBufferData.Filled = TRUE;
                    DsdInternal_ProcessPage(ProtocolCtrlId);
                    if (Dcm_PageBufferData.TimeOut == TRUE)
                    {
                        ret = E_NOT_OK;
                    }
                    else
                    {
                        SchM_Enter_Dcm(Dcm_MsgCtrl);
                        Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                        SchM_Exit_Dcm(Dcm_MsgCtrl);
                        ret = DCM_E_PENDING;
                    }
                }
                SchM_Exit_Dcm(Dcm_PageBufferData);
                if (E_OK == ret)
                {
                    if (Dcm_PageBufferData.TotalSize > Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId]
                                                           .DcmDslProtocolMaximumResponseSize)
                    { /*Pdu length is bigger than Page buffer max size */
                        *ErrorCode = DCM_E_RESPONSETOOLONG;
                        DslInternal_InitPageBuffer();
                        ret = E_NOT_OK;
                    }
                    else
                    {
                        SchM_Enter_Dcm(Dcm_MsgCtrl);
                        Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                        SchM_Exit_Dcm(Dcm_MsgCtrl);
                        ret = DCM_E_PENDING;
                    }
                }
            }
#else
            { /*Pdu length is bigger than buffer size,ignore the request message */
                *ErrorCode = DCM_E_RESPONSETOOLONG;
                ret = E_NOT_OK;
            }
#endif
        }
        if (E_OK == ret)
        { /*assemble positive response*/
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = MsgLen;
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = MsgLen;
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            DsdInternal_ProcessingDone(ProtocolCtrlId);
        }
    }
    return ret;
}
#endif
#if (STD_ON == DCM_UDS_SERVICE0X19_0E_ENABLED)
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service  0x0E sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
/*******************************************/
static FUNC(Std_ReturnType, DCM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dcm_UDS0x19_0E(uint8 ProtocolCtrlId, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 MsgCtrlId;
    uint32 Offset;
    Std_ReturnType ret = E_OK;
    Dcm_MsgLenType MsgLen = 2u; /*store response SID and echo of sub-function*/
    uint32 DTC;
    uint8 DTCstatus;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    if (DCM_UDS0X19_SUBFUNC0X0E_REQ_DATA_LENGTH != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
    { /*the length of massage is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    { /*find Tx buffer and offset*/
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x59u;
        Dcm_Channel[Offset + 1u] = 0x0Eu;
        SchM_Exit_Dcm(Dcm_Channel);
        /*get DTCStatusAvailabilityMask*/
        ret = Dem_DcmGetDTCStatusAvailabilityMask(&Dcm_Channel[Offset + MsgLen]);
        MsgLen++;
        if (E_OK == ret)
        {
            ret = Dem_DcmGetDTCByOccurrenceTime(DEM_MOST_REC_DET_CONFIRMED_DTC, &DTC);
            if (ret == DEM_OCCURR_OK)
            {
                (void)Dem_DcmGetStatusOfDTC(DTC, DEM_DTC_ORIGIN_PRIMARY_MEMORY, &DTCstatus);
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_Channel[Offset + MsgLen] = (uint8)(DTC >> 16u);
                MsgLen++;
                Dcm_Channel[Offset + MsgLen] = (uint8)(DTC >> 8u);
                MsgLen++;
                Dcm_Channel[Offset + MsgLen] = (uint8)(DTC);
                MsgLen++;
                Dcm_Channel[Offset + MsgLen] = DTCstatus;
                SchM_Exit_Dcm(Dcm_Channel);
                MsgLen++;
            }
            else
            {
                ret = E_OK; /* response with a positive and empty response*/
            }
        }
        if (E_OK == ret)
        {
            if (MsgLen > Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize)
            { /*Pdu length is bigger than buffer size,ignore the request message */
                *ErrorCode = DCM_E_RESPONSETOOLONG;
                ret = E_NOT_OK;
            }
        }
        if (E_OK == ret)
        { /*assemble positive response*/
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = MsgLen;
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = MsgLen;
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            DsdInternal_ProcessingDone(ProtocolCtrlId);
        }
    }
    return ret;
}
#endif
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/************************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service sub service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x19SubfunctionAnalyse(
    uint8 ProtocolCtrlId,
    uint8 Subfunction,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret;

    /*check sub-function entrance*/
    switch (Subfunction)
    {
#if (STD_ON == DCM_UDS_SERVICE0X19_01_ENABLED)
    case DCM_REPORTNUMBEROFDTCBYSTATUSMASK:
        /*Sub-function:0x01*/
        ret = Dcm_UDS0x19_01(ProtocolCtrlId, ErrorCode);
        break;
#endif
#if (STD_ON == DCM_UDS_SERVICE0X19_02_ENABLED)
    case DCM_REPORTDTCBYSTATUSMASK:
        /*Sub-function:0x02*/
        ret = Dcm_UDS0x19_02(ProtocolCtrlId, ErrorCode);
        break;
#endif
#if (STD_ON == DCM_UDS_SERVICE0X19_03_ENABLED)
    case DCM_REPORTREPORTDTCSNAPSHOTIDENTIFICATION:
        /*Sub-function:0x03*/
        ret = Dcm_UDS0x19_03(ProtocolCtrlId, ErrorCode);
        break;
#endif
#if (STD_ON == DCM_UDS_SERVICE0X19_04_ENABLED)
    case DCM_REPORTDTCSNAPSHOTRECORDBYDTCNUMBER:
        /*Sub-function:0x04*/
        ret = Dcm_UDS0x19_04(ProtocolCtrlId, ErrorCode);
        break;
#endif
#if (STD_ON == DCM_UDS_SERVICE0X19_06_ENABLED)
    case DCM_REPORTDTCEXTENDEDDATARECORDBYDTCNUMBER:
        /*Sub-function:0x06*/
        ret = Dcm_UDS0x19_06(ProtocolCtrlId, ErrorCode);
        break;
#endif
#if (STD_ON == DCM_UDS_SERVICE0X19_0A_ENABLED)
    case DCM_REPORTSUPPORTEDDTC:
        /*Sub-function:0x0A*/
        ret = Dcm_UDS0x19_0A(ProtocolCtrlId, ErrorCode);
        break;
#endif
#if (STD_ON == DCM_UDS_SERVICE0X19_0E_ENABLED)
    case DCM_REPORTMOSTRECENTCONFIRMEDDTC:
        /*Sub-function:0x0E*/
        ret = Dcm_UDS0x19_0E(ProtocolCtrlId, ErrorCode);
        break;
#endif
    default:
        /*if the sub-function is not supported,reset 'control resource' and send NRC 0x12*/
        *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        ret = E_NOT_OK;
        break;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*****************************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x19 service process>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE)
Dcm_UDS0x19(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 MsgCtrlId;
    uint8 Subfunction;
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */

    DCM_UNUSED(OpStatus);
    /*************************************************/
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_READ_DTC_INFORMATION);
    if (E_NOT_OK == ret)
    {
        /*the current session does not support the request service,send NRC = 0x7F*/
        *ErrorCode = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
    }
#endif
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*security check,check whether the current security supports the request service*/
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_READ_DTC_INFORMATION);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif
    if (E_OK == ret)
    {
        /*if the required protocol is configuted,get the index of runtime datum*/
        MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
#if (STD_ON == DCM_MINIMUMLENGTH_CHECK_ENABLED)
        /*check the massage length*/
        if (Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen < DCM_UDS_REQ_DATA_MINLENGTH)
        {
            /*the length of massage is not correct,send NRC 0x13*/
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            ret = E_NOT_OK;
        }
#endif
    }

    if (E_OK == ret)
    {
        /*check whether the required sub-function is configured*/
        ret = Dcm_UdsSubServicesCheck(ProtocolCtrlId);
        if (E_NOT_OK == ret)
        {
            /*if the required reset type is not supported,send NRC 0x12*/
            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        }
    }
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    if (E_OK == ret)
    {
        ret = DsdInternal_SubSesCheck(ProtocolCtrlId, SID_READ_DTC_INFORMATION);
        if (E_NOT_OK == ret)
        {
            /*the current session does not support the request sub service,send NRC = 0x7E*/
            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
        }
    }
#endif
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*security check,check whether the current security supports the request service*/
        ret = DsdInternal_SubSecurityCheck(ProtocolCtrlId, SID_READ_DTC_INFORMATION);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif
    /**************************************************/
    if (E_OK == ret)
    {
        Subfunction = Dcm_MsgCtrl[MsgCtrlId].Subfunction;
        /*check sub-function entrance*/
        ret = Dcm_Uds0x19SubfunctionAnalyse(ProtocolCtrlId, Subfunction, ErrorCode);
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
