
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

/****************************************************************
     UDS: ReadScalingDataByIdentifier (24 hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X24_ENABLED)
/************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x24 service Did Check>
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
    DspInternalUDS0x24_DidCheck(uint16 receiveDid, P2VAR(uint16, AUTOMATIC, DCM_VAR_NOINIT) pDidCfgIndex)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8 Index;
    Std_ReturnType ret = E_NOT_OK;

    for (Index = 0; (Index < Dcm_DspCfg.DcmDspDidNum) && (E_NOT_OK == ret); Index++)
    {
        /*single did check*/
        if ((receiveDid == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId)
            && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed))
        {
            *pDidCfgIndex = Index;
            ret = E_OK;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/***************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x24 service Service Condition Check>
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
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x24ServiceConditionCheck(
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint16, AUTOMATIC, DCM_VAR) DidCfgIndex,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */                              /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    uint16 DidInfoCfgIndex;
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    uint16 RecDid;
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
#endif

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_READ_SCALING_DATA_BY_IDENTIFIER);
    if (E_NOT_OK == ret)
    {
        /*the current session does not support the request service,send NRC = 0x7F*/
        *ErrorCode = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
        ret = E_NOT_OK;
    }
#endif
    /*************************************************/
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*security check,check whether the current security supports the request service*/
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_READ_SCALING_DATA_BY_IDENTIFIER);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
            ret = E_NOT_OK;
        }
    }
#endif
    if (E_OK == ret)
    {
        /*length check*/
        if (DCM_UDS0X24_REQ_DATA_LENGTH
            != Dcm_MsgCtrl[Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex].MsgContext.ReqDataLen)
        {
            /*the length of message is not correct,send NRC 0x13*/
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            ret = E_NOT_OK;
        }
    }
#if (STD_OFF == DCM_DSP_DID_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*NRC 0x31:request out of range*/
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
#else
    if (E_OK == ret)
    {
        RecDid = (uint16)(((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1u]) << 8u)
                 | ((uint16)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u]));
        /*find the required DID in configuration*/
        ret = DspInternalUDS0x24_DidCheck(RecDid, DidCfgIndex);
        if (E_NOT_OK == ret)
        {
            /*if the required DID is not found in DcmDspDid,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    if (E_OK == ret)
    {
        DidInfoCfgIndex = Dcm_DspCfg.pDcmDspDid[*DidCfgIndex].DcmDspDidInfoIndex;
        /*check the current session*/
#if ((STD_ON == DCM_SESSION_FUNC_ENABLED) && (STD_ON == DCM_DSP_DID_FUNC_ENABLED))
        ret = DsdInternal_DidSessionCheck(DidInfoCfgIndex, ErrorCode);
#endif
    }

#if ((STD_ON == DCM_SECURITY_FUNC_ENABLED) && (STD_ON == DCM_DSP_DID_FUNC_ENABLED))
    /*check the current security level*/
    if (E_OK == ret)
    {
        ret = DsdInternal_DidSecurityCheck(DidInfoCfgIndex, ErrorCode);
    }
#endif
#endif
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*******************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x24 service>
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
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7,20.7 */
Dcm_UDS0x24(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 1532,3432-- */ /* MISRA Rule 8.7,20.7 */
{
    uint8 MsgCtrlId;
    Std_ReturnType ret;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint32 Offset;
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    uint16 DidCfgIndex;
    uint16 RecDid;
    uint8 SignalNum;
    uint8 iloop;
    P2CONST(Dcm_DspDidSignalType, TYPEDEF, DCM_CONST) pDcmDspDidSignal;
    uint32 DidSignalPos = 0;
    uint32 ResOffset;
    uint16 DataSize;
#endif

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    RecDid = (uint16)(((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1u]) << 8u)
             | ((uint16)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u]));
    /*************************************************/
    ret = Dcm_Uds0x24ServiceConditionCheck(ProtocolCtrlId, &DidCfgIndex, ErrorCode);

#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    if (E_OK == ret)
    {
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;

        SignalNum = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidSignalNum;
        pDcmDspDidSignal = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].pDcmDspDidSignal;
        ResOffset = Offset + 3u;
        for (iloop = 0; (iloop < SignalNum) && (E_OK == ret); iloop++)
        {
            if (pDcmDspDidSignal != NULL_PTR)
            {
                DataSize = 0;
                DidSignalPos += ResOffset + (uint32)(((uint32)pDcmDspDidSignal->DcmDspDidDataPos + 7u) >> 3u);
                if (pDcmDspDidSignal->pDcmDspDidData->DcmDspDataGetScalingInfoFnc != NULL_PTR)
                {
                    ret = pDcmDspDidSignal->pDcmDspDidData->DcmDspDataGetScalingInfoFnc(
                        &Dcm_Channel[DidSignalPos],
                        ErrorCode);
                }
                else
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    ret = E_NOT_OK;
                }
                if (E_OK == ret)
                {
                    if (DCM_UINT8_DYN == pDcmDspDidSignal->pDcmDspDidData->DcmDspDataType)
                    {
                        /*DidDataSize is dynamic*/
                        if (NULL_PTR == pDcmDspDidSignal->pDcmDspDidData->DcmDspDataReadDataLengthFnc)
                        {
                            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                            ret = E_NOT_OK;
                        }
                        else
                        {
                            (void)pDcmDspDidSignal->pDcmDspDidData->DcmDspDataReadDataLengthFnc(OpStatus, &DataSize);
                        }
                    }
                    else
                    {
                        /*DidDataSize is fixed*/
                        if (0xffu != pDcmDspDidSignal->pDcmDspDidData->DcmDspDataInfoIndex)
                        {
                            DataSize = Dcm_DspCfg.pDcmDspDataInfo[pDcmDspDidSignal->pDcmDspDidData->DcmDspDataInfoIndex]
                                           .DcmDspDataScalingInfoSize;
                        }
                        else
                        {
                            DataSize = 0;
                        }
                    }
                    ResOffset += DataSize;
                }
            }
            pDcmDspDidSignal++;
        }
    }

    if ((E_OK == ret) && ((ResOffset - Offset) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize)))
    {
        /* check tx data length */
        /*Pdu length is bigger than buffer size */
        *ErrorCode = DCM_E_RESPONSETOOLONG;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    {
        /*the processing is successful,assemble positive response*/
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x64; /*response SID*/
        Dcm_Channel[Offset + 1u] = (uint8)(RecDid >> 8u);
        Dcm_Channel[Offset + 2u] = (uint8)RecDid;
        SchM_Exit_Dcm(Dcm_Channel);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = (Dcm_MsgLenType)ResOffset - Offset;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = (Dcm_MsgLenType)ResOffset - Offset;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
    }
#endif
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif
