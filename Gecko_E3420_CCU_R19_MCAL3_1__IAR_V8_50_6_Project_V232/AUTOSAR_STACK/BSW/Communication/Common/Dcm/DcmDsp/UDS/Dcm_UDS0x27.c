
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
     UDS:SecurityAccess(27 hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X27_ENABLED)

typedef struct
{
    uint8 SecCfgIndex;
    Dcm_CompareKeyFncType ComparedKey;
    Dcm_GetSeedFncType GottSeed;
} Dcm_0x27Types;
/*******************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x27 service Service Condition Check>
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
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x27ServiceConditionCheck(
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */                                         /* MISRA Rule 2.2 */

    /*************************************************/
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current
     * session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_SECURITY_ACCESS);
    if (E_NOT_OK == ret)
    {
        /*the current session does not support the request service,send NRC = 0x7F*/
        *ErrorCode = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
        ret = E_NOT_OK;
    }
#endif

#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*security check,check whether the current security supports the request service*/
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_SECURITY_ACCESS);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
            ret = E_NOT_OK;
        }
    }
#endif
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/********************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x27 service Sub function Check>
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
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x27ServiceSubfunctionCheck(
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_VAR) SecCfgIndex,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
    uint8 MsgCtrlID;
    uint8 ReqSecLevel;

    /********************************/
    /*try to find the corresponding security level in configuration*/
    MsgCtrlID = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    ReqSecLevel = (Dcm_MsgCtrl[MsgCtrlID].Subfunction + 1u) / 2u;
    /*********************************************/
    if (ReqSecLevel == 0x00u)
    {
        /*if not found in DcmDspSecurityRow,send NRC 0x12*/
        *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        ret = E_NOT_OK;
    }
    /*********************************************/
    if (E_OK == ret)
    {
        ret = DslInternal_GetSecurityCfgBySecLevel(ReqSecLevel, SecCfgIndex);
        if (E_NOT_OK == ret)
        {
            /*if not found in DcmDspSecurityRow,send NRC 0x12*/
            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/********************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x27 service Active SecLevel Check>
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
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x27ServiceActiveSecLevelCheck(uint8 ProtocolCtrlId, uint8 SeedSize)
{
    uint8 Index;
    Std_ReturnType ret = E_OK;
    uint8 MsgCtrlID = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint8 TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlID].Dcm_TxCtrlChannelIndex;
    uint8 TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    uint32 Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
    uint8 SubFunction = Dcm_MsgCtrl[MsgCtrlID].Subfunction;
    uint8 ReqSecLevel = (SubFunction + 1u) / 2u;

    if (ReqSecLevel == Dcm_SecCtrl.Dcm_ActiveSec)
    {
        /*if the server is on the request security level,set seed to zero*/
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x67;
        Dcm_Channel[Offset + 1u] = SubFunction;
        for (Index = 0; Index < SeedSize; Index++)
        {
            Dcm_Channel[Offset + (uint16)Index + 2u] = 0x00u;
        }
        SchM_Exit_Dcm(Dcm_Channel);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlID].MsgContext.ResMaxDataLen = ((uint32)SeedSize + 2u);
        Dcm_MsgCtrl[MsgCtrlID].MsgContext.ResDataLen = ((uint32)SeedSize + 2u);
        Dcm_MsgCtrl[MsgCtrlID].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
        ret = DCM_E_PENDING;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/********************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x27 service Service MsgLen Check>
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
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x27ServiceMsgLenCheck(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    uint8 SecCfgIndex,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 ReqCfgLen;
    Std_ReturnType ret = E_OK;
    uint8 ReqLen;
    uint8 AdrSize;
    uint8 KeySize;
    P2CONST(Dcm_DspSecurityRowType, AUTOMATIC, DCM_CONST) pSecurityRow;
    uint8 MsgCtrlID;
    uint8 SubFunction;

    pSecurityRow = &(Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow[SecCfgIndex]);

    if (pSecurityRow != NULL_PTR)
    {
        MsgCtrlID = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
        SubFunction = Dcm_MsgCtrl[MsgCtrlID].Subfunction;
        AdrSize = pSecurityRow->DcmDspSecurityADRSize;
        KeySize = pSecurityRow->DcmDspSecurityKeySize;
        ReqLen = (uint8)(Dcm_MsgCtrl[MsgCtrlID].MsgContext.ReqDataLen);

        if (1u == (SubFunction & 0x01u))
        {
            ReqCfgLen = (uint8)(AdrSize + 2u);
        }
        else
        {
            ReqCfgLen = (uint8)(KeySize + 2u);
        }
        if (ReqLen != ReqCfgLen)
        {
            /*if the request message length is not correct,send NRC 0x13*/
            /*deal with 'send key'*/
            if ((0x01u != (SubFunction & 0x01u)) && (SubFunction == (Dcm_SecCtrl.Dcm_SubfunctionForSeed + 1u))
                && (Dcm_SecCtrl.Dcm_SecServiceState == DCM_SERVICE_SEED))
            {
                SchM_Enter_Dcm(Dcm_SecCtrl);
                Dcm_SecCtrl.Dcm_FalseAcessCount[SecCfgIndex] += (uint8)1;
                if (Dcm_SecCtrl.Dcm_FalseAcessCount[SecCfgIndex] >= pSecurityRow->DcmDspSecurityNumAttDelay)
                {
                    Dcm_ResetTime(&Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecCurTimer[SecCfgIndex]);
                    Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecExpiredTimer[SecCfgIndex] = pSecurityRow->DcmDspSecurityDelayTime;
                    Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecTimerState[SecCfgIndex] = DCM_SECTIMER_ON;
                }
                SchM_Exit_Dcm(Dcm_SecCtrl);
                if ((TRUE == pSecurityRow->DcmDspSecurityAttemptCounterEnabled)
                    && ((USE_ASYNCH_FNC == pSecurityRow->DcmDspSecurityUsePort)
                        || (USE_ASYNCH_CLIENT_SERVER == pSecurityRow->DcmDspSecurityUsePort)))
                {
                    if (pSecurityRow->Dcm_SetSecurityAttemptCounterFnc != NULL_PTR)
                    {
                        (void)pSecurityRow->Dcm_SetSecurityAttemptCounterFnc(
                            OpStatus,
                            Dcm_SecCtrl.Dcm_FalseAcessCount[SecCfgIndex]);
                    }
                }
            }
            DslInternal_SetSecurityAccessStatus(DCM_SERVICE_IDLE);
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            ret = E_NOT_OK;
        }
    }
    else
    {
        ret = E_NOT_OK;
    }

    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/*************************************************************************/
/*
 * Brief               <UDS  0x27 service Sub Request Seed>
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
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x27_SubReqSeed(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    Dcm_0x27Types* Dcm_0x27Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret;
    uint8 Index;
    uint8 MsgCtrlID = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint8 TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlID].Dcm_TxCtrlChannelIndex;
    uint8 TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    uint32 Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
    uint8 SubFunction = Dcm_MsgCtrl[MsgCtrlID].Subfunction;
    P2CONST(Dcm_DspSecurityRowType, AUTOMATIC, DCM_CONST) pSecurityRow;
    static uint8 Last_Seed[DCM_SEED_MAX_SIZE] = {0};
#if (DCM_SECURITY_ADR_MAXSIZE > 0)
    uint8 Dcm_Adr[DCM_SECURITY_ADR_MAXSIZE] = {0};
    uint8 AdrSize;
#endif
    uint8 SeedSize;

    pSecurityRow = &(Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow[Dcm_0x27Type->SecCfgIndex]);
    if (pSecurityRow == NULL_PTR)
    {
        ret = E_NOT_OK;
    }
    else
    {
#if (DCM_SECURITY_ADR_MAXSIZE > 0)
        AdrSize = pSecurityRow->DcmDspSecurityADRSize;
#endif
        SeedSize = pSecurityRow->DcmDspSecuritySeedSize;
        ret = E_OK;
    }
    /*check whether the Continuous request*/
    if (ret == E_OK)
    {
        /*to avoid requirement consecutive seed request,
         * same seed is returned.there to clear ServiceState*/
        if (DCM_SEC_CALL_OVER_MASK != (Dcm_SecCtrl.Dcm_SecFlag & DCM_SEC_CALL_OVER_MASK))
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        }
        else
        {
            /*check whether the security service state is idle*/
            ret = Dcm_Uds0x27ServiceActiveSecLevelCheck(ProtocolCtrlId, SeedSize);
        }
    }
    if (E_OK == ret)
    {
        /*if the server is on the other security level,
         * check the size of security access data record*/
#if (DCM_SECURITY_ADR_MAXSIZE > 0)
        if (0u == AdrSize)
        {
#endif
            if (DCM_SERVICE_IDLE == Dcm_SecCtrl.Dcm_SecServiceState)
            {
                ret = (*Dcm_0x27Type->GottSeed)(
#if (DCM_SECURITY_ADR_MAXSIZE > 0)
                    NULL_PTR,
#endif
                    OpStatus,
                    &Dcm_Channel[Offset + 2u],
                    ErrorCode);
                if (DCM_E_PENDING == ret)
                {
                    SchM_Enter_Dcm(Dcm_MsgCtrl);
                    Dcm_MsgCtrl[MsgCtrlID].Dcm_OpStatus = DCM_PENDING;
                    SchM_Exit_Dcm(Dcm_MsgCtrl);
                }
                for (Index = 0; Index < SeedSize; Index++)
                {
                    Last_Seed[Index] = Dcm_Channel[Offset + 2u + (uint32)Index];
                }
            }
            else
            {
                for (Index = 0; Index < SeedSize; Index++)
                {
                    SchM_Enter_Dcm(Dcm_Channel);
                    Dcm_Channel[Offset + 2u + (uint32)Index] = Last_Seed[Index];
                    SchM_Exit_Dcm(Dcm_Channel);
                }
            }
#if (DCM_SECURITY_ADR_MAXSIZE > 0)
        }
        else
        { /*read-out ADR  from request message*/
            for (Index = 0; Index < AdrSize; Index++)
            {
                Dcm_Adr[Index] = (Dcm_MsgCtrl[MsgCtrlID].MsgContext.pReqData)[Index + 2u];
            }
            if (DCM_SERVICE_IDLE == Dcm_SecCtrl.Dcm_SecServiceState)
            {
                ret = (*Dcm_0x27Type->GottSeed)(&Dcm_Adr[0], OpStatus, &Dcm_Channel[Offset + 2u], ErrorCode);
                if (DCM_E_PENDING == ret)
                {
                    SchM_Enter_Dcm(Dcm_MsgCtrl);
                    Dcm_MsgCtrl[MsgCtrlID].Dcm_OpStatus = DCM_PENDING;
                    SchM_Exit_Dcm(Dcm_MsgCtrl);
                }
            }
        }
#endif
    }
    if ((E_OK == ret)
        && (((uint32)0x02u + (uint32)SeedSize) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize)))
    {
        /* check tx data length */
        /*Pdu length is bigger than buffer size,ignore the request message */
        *ErrorCode = DCM_E_RESPONSETOOLONG;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    {
        /* send message */
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x67;
        Dcm_Channel[Offset + 1u] = SubFunction;
        SchM_Exit_Dcm(Dcm_Channel);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlID].MsgContext.ResMaxDataLen = ((uint32)SeedSize + 2UL);
        Dcm_MsgCtrl[MsgCtrlID].MsgContext.ResDataLen = ((uint32)SeedSize + 2UL);
        Dcm_MsgCtrl[MsgCtrlID].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
        SchM_Enter_Dcm(Dcm_SecCtrl);
        /*seed has been sent,set the status to DCM_SERVICE_SEED*/
        Dcm_SecCtrl.Dcm_SecServiceState = DCM_SERVICE_SEED;
        Dcm_SecCtrl.Dcm_SubfunctionForSeed = SubFunction;
        SchM_Exit_Dcm(Dcm_SecCtrl);
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/*************************************************************************/
/*
 * Brief               <UDS  0x27 service Sub Compare Key>
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
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x27_SubCompareKey(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    Dcm_0x27Types* Dcm_0x27Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
    uint8 MsgCtrlID = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint8 TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlID].Dcm_TxCtrlChannelIndex;
    uint8 TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    uint32 Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
    uint8 SubFunction = Dcm_MsgCtrl[MsgCtrlID].Subfunction;
    uint8 ReqSecLevel = (SubFunction + 1u) / 2u;
    P2CONST(Dcm_DspSecurityRowType, AUTOMATIC, DCM_CONST) pSecurityRow;
    pSecurityRow = &(Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow[Dcm_0x27Type->SecCfgIndex]);
    if (pSecurityRow == NULL_PTR)
    {
        ret = E_NOT_OK;
    }
    if ((E_OK == ret)
        && ((SubFunction <= Dcm_SecCtrl.Dcm_SubfunctionForSeed)
            || (1u != (SubFunction - Dcm_SecCtrl.Dcm_SubfunctionForSeed))))
    {
        /*'requestSeed' and 'seedKey' don't  match*/
        SchM_Enter_Dcm(Dcm_SecCtrl);
        Dcm_SecCtrl.Dcm_FalseAcessCount[Dcm_0x27Type->SecCfgIndex] += (uint8)1;
        if (Dcm_SecCtrl.Dcm_FalseAcessCount[Dcm_0x27Type->SecCfgIndex] >= pSecurityRow->DcmDspSecurityNumAttDelay)
        {
            Dcm_ResetTime(&Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecCurTimer[Dcm_0x27Type->SecCfgIndex]);
            Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecExpiredTimer[Dcm_0x27Type->SecCfgIndex] =
                pSecurityRow->DcmDspSecurityDelayTime;
            Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecTimerState[Dcm_0x27Type->SecCfgIndex] = DCM_SECTIMER_ON;
        }
        SchM_Exit_Dcm(Dcm_SecCtrl);
        if (((TRUE == pSecurityRow->DcmDspSecurityAttemptCounterEnabled)
             && ((USE_ASYNCH_FNC == pSecurityRow->DcmDspSecurityUsePort)
                 || (USE_ASYNCH_CLIENT_SERVER == pSecurityRow->DcmDspSecurityUsePort)))
            && (pSecurityRow->Dcm_SetSecurityAttemptCounterFnc != NULL_PTR))
        {
            (void)pSecurityRow->Dcm_SetSecurityAttemptCounterFnc(
                OpStatus,
                Dcm_SecCtrl.Dcm_FalseAcessCount[Dcm_0x27Type->SecCfgIndex]);
        }
        DslInternal_SetSecurityAccessStatus(DCM_SERVICE_IDLE);
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    {
        /*if 'requestSeed' and 'seedKey' match,compare the key*/
        ret = (*Dcm_0x27Type->ComparedKey)(&(Dcm_MsgCtrl[MsgCtrlID].MsgContext.pReqData[2]), OpStatus, ErrorCode);
        if (DCM_E_PENDING == ret)
        {
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlID].Dcm_OpStatus = DCM_PENDING;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
        }
        else if (E_COMPARE_KEY_FAILED == ret)
        { /*'compare key' is failed,increase the false count*/
            SchM_Enter_Dcm(Dcm_SecCtrl);
            Dcm_SecCtrl.Dcm_SubfunctionForSeed = 0u;
            Dcm_SecCtrl.Dcm_FalseAcessCount[Dcm_0x27Type->SecCfgIndex] += (uint8)1;
            SchM_Exit_Dcm(Dcm_SecCtrl);
            if ((TRUE == pSecurityRow->DcmDspSecurityAttemptCounterEnabled)
                && ((USE_ASYNCH_FNC == pSecurityRow->DcmDspSecurityUsePort)
                    || (USE_ASYNCH_CLIENT_SERVER == pSecurityRow->DcmDspSecurityUsePort))
                && (pSecurityRow->Dcm_SetSecurityAttemptCounterFnc != NULL_PTR))
            {
                (void)pSecurityRow->Dcm_SetSecurityAttemptCounterFnc(
                    OpStatus,
                    Dcm_SecCtrl.Dcm_FalseAcessCount[Dcm_0x27Type->SecCfgIndex]);
            }
            if (Dcm_SecCtrl.Dcm_FalseAcessCount[Dcm_0x27Type->SecCfgIndex] >= pSecurityRow->DcmDspSecurityNumAttDelay)
            {
                SchM_Enter_Dcm(Dcm_SecCtrl);
                Dcm_ResetTime(&Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecCurTimer[Dcm_0x27Type->SecCfgIndex]);
                Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecExpiredTimer[Dcm_0x27Type->SecCfgIndex] =
                    pSecurityRow->DcmDspSecurityDelayTime;
                Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecTimerState[Dcm_0x27Type->SecCfgIndex] = DCM_SECTIMER_ON;
                SchM_Exit_Dcm(Dcm_SecCtrl);
                DslInternal_SetSecurityAccessStatus(DCM_SERVICE_IDLE);
                *ErrorCode = DCM_E_EXCEEDNUMBEROFATTEMPTS; /*NRC=0x36*/
                ret = E_NOT_OK;
            }
            else
            {
                DslInternal_SetSecurityAccessStatus(DCM_SERVICE_IDLE);
                *ErrorCode = DCM_E_INVALIDKEY; /*NRC=0x35*/
                ret = E_NOT_OK;
            }
        }
        else
        {
            /*idle*/
        }
    }
    if ((E_OK == ret) && ((2u) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize)))
    {
        /* check tx data length */
        /*Pdu length is bigger than buffer size,ignore the request message */
        *ErrorCode = DCM_E_RESPONSETOOLONG;
        ret = E_NOT_OK;
    }
    /* send message*/
    if (E_OK == ret)
    {
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x67;
        Dcm_Channel[Offset + 1u] = SubFunction;
        SchM_Exit_Dcm(Dcm_Channel);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlID].MsgContext.ResMaxDataLen = 2UL;
        Dcm_MsgCtrl[MsgCtrlID].MsgContext.ResDataLen = 2UL;
        Dcm_MsgCtrl[MsgCtrlID].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        SchM_Enter_Dcm(Dcm_SecCtrl);
        Dcm_SecCtrl.Dcm_NewSec = ReqSecLevel;
        Dcm_SecCtrl.Dcm_SecServiceState = DCM_SERVICE_KEY;
        SchM_Exit_Dcm(Dcm_SecCtrl);
        DsdInternal_ProcessingDone(ProtocolCtrlId);

        SchM_Enter_Dcm(Dcm_SecCtrl);
        Dcm_SecCtrl.Dcm_FalseAcessCount[Dcm_0x27Type->SecCfgIndex] = 0u;
        Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecTimerState[Dcm_0x27Type->SecCfgIndex] = DCM_SECTIMER_OFF;
        SchM_Exit_Dcm(Dcm_SecCtrl);
        pSecurityRow = &(Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow[Dcm_0x27Type->SecCfgIndex]);
        if (((TRUE == pSecurityRow->DcmDspSecurityAttemptCounterEnabled)
             && ((USE_ASYNCH_FNC == pSecurityRow->DcmDspSecurityUsePort)
                 || (USE_ASYNCH_CLIENT_SERVER == pSecurityRow->DcmDspSecurityUsePort)))
            && (pSecurityRow->Dcm_SetSecurityAttemptCounterFnc != NULL_PTR))
        {
            (void)pSecurityRow->Dcm_SetSecurityAttemptCounterFnc(
                OpStatus,
                Dcm_SecCtrl.Dcm_FalseAcessCount[Dcm_0x27Type->SecCfgIndex]);
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/********************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x27 service>
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
Dcm_UDS0x27(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    uint8 SubFunction;
    uint8 MsgCtrlID;
    uint8 SecCfgIndex = 0u;
    Dcm_CompareKeyFncType ComparedKey = NULL_PTR;
    Dcm_GetSeedFncType GottSeed = NULL_PTR;
    Dcm_0x27Types Dcm_0x27Type;
#endif
    Std_ReturnType ret;

    ret = Dcm_Uds0x27ServiceConditionCheck(ProtocolCtrlId, ErrorCode);

#if (STD_ON == DCM_MINIMUMLENGTH_CHECK_ENABLED)
    if ((E_OK == ret)
        && ((uint16)Dcm_MsgCtrl[Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex].MsgContext.ReqDataLen
            < DCM_UDS_REQ_DATA_MINLENGTH))
    {
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }
#endif
    if (E_OK == ret)
    {
        MsgCtrlID = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
        SubFunction = Dcm_MsgCtrl[MsgCtrlID].Subfunction;
        ret = Dcm_Uds0x27ServiceSubfunctionCheck(ProtocolCtrlId, &SecCfgIndex, ErrorCode);
    }
    if (E_OK == ret)
    {
        ret = RTE_PreConditonCheck(Dcm_MsgCtrl[MsgCtrlID].SID,Dcm_MsgCtrl[MsgCtrlID].MsgContext.pReqData);
        if (E_OK != ret)
        {
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        }
    }
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*session check,check whether the current session supports the request service*/
        ret = DsdInternal_SubSesCheck(ProtocolCtrlId, SID_SECURITY_ACCESS);
        if (E_NOT_OK == ret)
        {
            /*the current session does not support the request service,send NRC = 0x7E*/
            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
        }
    }
#endif
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*security check,check whether the current security supports the request service*/
        ret = DsdInternal_SubSecurityCheck(ProtocolCtrlId, SID_SECURITY_ACCESS);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif

    
    if (E_OK == ret)
    {
        /*check the request message length*/
        ret = Dcm_Uds0x27ServiceMsgLenCheck(OpStatus, ProtocolCtrlId, SecCfgIndex, ErrorCode);
    }
    /*check the status*/
    if ((E_OK == ret) && (DCM_SERVICE_SEED != Dcm_SecCtrl.Dcm_SecServiceState) && (0x01u != (SubFunction & 0x01u)))
    {
        /*if the server is not on the status DCM_SERVICE_SEED,
         * send NRC 0x24:request sequence error*/
        DslInternal_SetSecurityAccessStatus(DCM_SERVICE_IDLE);
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        ret = E_NOT_OK;
    }

#if (STD_OFF == DCM_SECURITY_FUNC_ENABLED)
    if (E_OK == ret)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
#else
    /*if the delay timer is active and a request is transmitted,send NRC 0x37*/
    if ((E_OK == ret) && (DCM_SECTIMER_ON == Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecTimerState[SecCfgIndex])
        && (Dcm_SecCtrl.Dcm_FalseAcessCount[SecCfgIndex]
            >= Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow[SecCfgIndex].DcmDspSecurityNumAttDelay))
    {
        *ErrorCode = DCM_E_REQUIREDTIMEDELAYNOTEXPIRED;
        ret = E_NOT_OK;
    }
    /*check whether the corresponding callouts are configured*/
    if (E_OK == ret)
    {
        if ((USE_ASYNCH_FNC == (Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow)[SecCfgIndex].DcmDspSecurityUsePort)
            || (USE_ASYNCH_CLIENT_SERVER
                == (Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow)[SecCfgIndex].DcmDspSecurityUsePort))
        {
            ComparedKey = (Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow)[SecCfgIndex].Dcm_CompareKeyFnc;
            GottSeed = (Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow)[SecCfgIndex].Dcm_GetSeedFnc;
        }
        if ((NULL_PTR == ComparedKey) || (NULL_PTR == GottSeed))
        {
            /*if not configured,send NRC 0x22*/
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        }
    }
    if (E_OK == ret)
    {
        /*deal with 'request seed'*/
        if (0x01u == (SubFunction & 0x01u))
        {
            Dcm_0x27Type.GottSeed = GottSeed;
            Dcm_0x27Type.SecCfgIndex = SecCfgIndex;
            ret = Dcm_UDS0x27_SubReqSeed(OpStatus, ProtocolCtrlId, &Dcm_0x27Type, ErrorCode);
        } /*ENDOF if(0x01 == (SubFunction & 0x01u))*/
        /*deal with 'send key'*/
        else
        {
            Dcm_0x27Type.ComparedKey = ComparedKey;
            Dcm_0x27Type.SecCfgIndex = SecCfgIndex;
            ret = Dcm_UDS0x27_SubCompareKey(OpStatus, ProtocolCtrlId, &Dcm_0x27Type, ErrorCode);
        }
    }
    return ret;
#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
