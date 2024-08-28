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
                 UDS:RoutineControl (31 hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X31_ENABLED)
typedef struct
{
    boolean Find;
    Dcm_OpStatusType OpStatus;
    uint8* pRoutineCfgId;
    uint32* ResLen;
    uint16 currentDataLength;
} Dcm_0x31Types;

/********************************/
/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#if (STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UdsSesAndSecCheck(
    P2CONST(Dcm_DspCommonAuthorizationType, AUTOMATIC, DCM_APPL_CONST) pDspCommonAuthorization,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
#if ((STD_ON == DCM_SESSION_FUNC_ENABLED) || (STD_ON == DCM_SECURITY_FUNC_ENABLED))
    uint8 Index;
    boolean Flag = FALSE;
#endif
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    uint8 RoutineSesNum;
#endif
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    uint8 RoutineSecNum;
#endif
    Std_ReturnType Ret = E_OK;

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    RoutineSesNum = pDspCommonAuthorization->DcmDspCommonAuthorizationSessionRefNum;
    if (RoutineSesNum != 0u)
    {
        for (Index = 0; (Index < RoutineSesNum) && (FALSE == Flag); Index++)
        {
            if (Dcm_MkCtrl.Dcm_ActiveSes == pDspCommonAuthorization->DcmDspCommonAuthorizationSessionRef[Index])
            {
                Flag = TRUE;
            }
        }
        if (FALSE == Flag)
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            Ret = E_NOT_OK;
        }
    }
#endif
    /*check security*/
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    Flag = FALSE;
    RoutineSecNum = pDspCommonAuthorization->DcmDspCommonAuthorizationSecurityLevelRefNum;
    if ((RoutineSecNum != 0u) && (E_OK == Ret))
    {
        for (Index = 0; (Index < RoutineSecNum) && (FALSE == Flag); Index++)
        {
            if (Dcm_MkCtrl.Dcm_ActiveSec == pDspCommonAuthorization->DcmDspCommonAuthorizationSecurityLevelRef[Index])
            {
                Flag = TRUE;
            }
        }
        if (FALSE == Flag)
        {
            /*the processing is not supported in current security level,send NRC 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
            Ret = E_NOT_OK;
        }
    }
#endif
    return Ret;
}

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
static FUNC(Std_ReturnType, DCM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dcm_UdsRCSesAndSecCheck(uint8 RoutineCfgIdx, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    P2CONST(Dcm_DspCommonAuthorizationType, AUTOMATIC, DCM_APPL_CONST)
    pDspRoutineAuthorization;
    P2CONST(Dcm_DspCommonAuthorizationType, AUTOMATIC, DCM_APPL_CONST)
    pDspStartRoutineAuthorization;
    P2CONST(Dcm_DspCommonAuthorizationType, AUTOMATIC, DCM_APPL_CONST)
    pDspStopRoutineAuthorization;
    P2CONST(Dcm_DspCommonAuthorizationType, AUTOMATIC, DCM_APPL_CONST)
    pDspRequestRoutineResultsAuthorization;
    Std_ReturnType Ret = E_OK;

    pDspRoutineAuthorization = Dcm_DspCfg.pDcmDspRoutine[RoutineCfgIdx].DcmDspCommonAuthorizationRef;
    if (pDspRoutineAuthorization != NULL_PTR)
    {
        Ret = Dcm_UdsSesAndSecCheck(pDspRoutineAuthorization, ErrorCode);
    }

    if ((E_OK == Ret) && (Dcm_DspCfg.pDcmDspRoutine[RoutineCfgIdx].DcmDspStartRoutine != NULL_PTR))
    {
        pDspStartRoutineAuthorization =
            Dcm_DspCfg.pDcmDspRoutine[RoutineCfgIdx].DcmDspStartRoutine->DcmDspStartRoutineCommonAuthorizationRef;
        if (pDspStartRoutineAuthorization != NULL_PTR)
        {
            Ret = Dcm_UdsSesAndSecCheck(pDspStartRoutineAuthorization, ErrorCode);
        }
    }

    if ((E_OK == Ret) && (Dcm_DspCfg.pDcmDspRoutine[RoutineCfgIdx].DcmDspStopRoutine != NULL_PTR))
    {
        pDspStopRoutineAuthorization =
            Dcm_DspCfg.pDcmDspRoutine[RoutineCfgIdx].DcmDspStopRoutine->DcmDspStopRoutineCommonAuthorizationRef;
        if (pDspStopRoutineAuthorization != NULL_PTR)
        {
            Ret = Dcm_UdsSesAndSecCheck(pDspStopRoutineAuthorization, ErrorCode);
        }
    }

    if ((E_OK == Ret) && (Dcm_DspCfg.pDcmDspRoutine[RoutineCfgIdx].DcmDspRequestRoutineResults != NULL_PTR))
    {
        pDspRequestRoutineResultsAuthorization =
            Dcm_DspCfg.pDcmDspRoutine[RoutineCfgIdx]
                .DcmDspRequestRoutineResults->DcmDspRequestRoutineResultsCommonAuthorizationRef;
        if (pDspRequestRoutineResultsAuthorization != NULL_PTR)
        {
            Ret = Dcm_UdsSesAndSecCheck(pDspRequestRoutineResultsAuthorization, ErrorCode);
        }
    }
    if ((E_OK == Ret) && (Dcm_DspCfg.pDcmDspRoutine[RoutineCfgIdx].DcmDspRequestRoutineResults == NULL_PTR)
        && (Dcm_DspCfg.pDcmDspRoutine[RoutineCfgIdx].DcmDspStopRoutine == NULL_PTR)
        && (Dcm_DspCfg.pDcmDspRoutine[RoutineCfgIdx].DcmDspStartRoutine == NULL_PTR))
    {
        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
        Ret = E_NOT_OK;
    }
    return Ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
/********************************/
#if (STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(uint32, DCM_CODE) Dcm_UdsRCStartRoutine(
    uint8 MsgCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_0x31Types, AUTOMATIC, AUTOMATIC) Dcm_0x31Type,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) Ret,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint32 ReqLen = 0;
    uint32 ResLen = 0;
    uint8 Index;
    Dcm_StartRoutineFncType StartRoutineFnc;
    P2CONST(Dcm_DspStartRoutineType, TYPEDEF, DCM_CONST) StartRoutine;
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pInbuffer; /* PRQA S 3432 */  /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pOutBuffer; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint32 Offset =
        (Dcm_DslCfg.pDcmChannelCfg)[Dcm_ChannelCtrl[Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex].Dcm_ChannelCfgIndex]
            .offset;

    StartRoutine = Dcm_DspCfg.pDcmDspRoutine[*Dcm_0x31Type->pRoutineCfgId].DcmDspStartRoutine;
    if (NULL_PTR == StartRoutine)
    {
        /*StartRoutineFnc is NULL,send NRC 0x12*/
        *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        *Ret = E_NOT_OK;
    }
    if (E_OK == *Ret)
    {
        if (NULL_PTR != StartRoutine->DcmDspStartRoutineIn)
        {
            for (Index = 0; Index < StartRoutine->DcmDspStartRoutineIn->RoutineInOutSignalNum; Index++)
            {
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
                ReqLen = ReqLen
                         + (uint32)((StartRoutine->DcmDspStartRoutineIn->DcmDspRoutineInOutSignal[Index]
                                         .DcmDspRoutineSignalLength
                                     + 7u)
                                    >> 3u);
                /* PRQA S 4391-- */ /* MISRA Rule 10.8 */
            }
        }
        else
        {
            ReqLen = 0;
        }
        if (NULL_PTR != StartRoutine->DcmDspStartRoutineOut)
        {
            for (Index = 0; Index < StartRoutine->DcmDspStartRoutineOut->RoutineInOutSignalNum; Index++)
            {
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
                ResLen = ResLen
                         + (uint32)((StartRoutine->DcmDspStartRoutineOut->DcmDspRoutineInOutSignal[Index]
                                         .DcmDspRoutineSignalLength
                                     + 7u)
                                    >> 3u);
                /* PRQA S 4391-- */ /* MISRA Rule 10.8 */
            }
        }
        else
        {
            ResLen = 0;
        }

        /*check the request message length*/
        if ((NULL_PTR == StartRoutine->DcmDspStartRoutineIn)
            || (DCM_VARIABLE_LENGTH
                != StartRoutine->DcmDspStartRoutineIn
                       ->DcmDspRoutineInOutSignal[StartRoutine->DcmDspStartRoutineIn->RoutineInOutSignalNum - 1u]
                       .DcmDspRoutineSignalType))
        {
            if ((ReqLen + DCM_UDS0X31_REQ_DATA_MINLENGTH) != ((uint8)Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen))
            {
                /*the request message length is not correct,send NRC 0x13*/
                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                *Ret = E_NOT_OK;
            }
        }
    }

    if (E_OK == *Ret)
    {
        StartRoutineFnc = StartRoutine->DcmDspStartRoutineFnc;
        if (NULL_PTR == StartRoutineFnc)
        {
            /*StartRoutineFnc is NULL,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            *Ret = E_NOT_OK;
        }
    }
#if (STD_ON == DCM_DSP_ROUTINE_CHECK_RESTART)
    if ((E_OK == *Ret) && (DCM_DSP_ROUTINE_ON == Dcm_RoutineControlState[*Dcm_0x31Type->pRoutineCfgId]))
    {
        /*the request sequence error,send NRC 0x24*/
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        *Ret = E_NOT_OK;
    }
#endif /* STD_ON == DCM_DSP_ROUTINE_CHECK_RESTART */
    if (E_OK == *Ret)
    {
        pInbuffer = NULL_PTR;
        if (0u != ReqLen)
        {
            pInbuffer = &Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4];
        }
        pOutBuffer = NULL_PTR;
        if (0u != ResLen)
        {
            pOutBuffer = &Dcm_Channel[Offset + 4u];
        }
        Dcm_0x31Type->currentDataLength = (uint16)ReqLen;
        *Ret = (*StartRoutineFnc)(
            pInbuffer,
            Dcm_0x31Type->OpStatus,
            pOutBuffer,
            &Dcm_0x31Type->currentDataLength,
            ErrorCode);

        if (E_OK == *Ret)
        {
            if ((NULL_PTR != StartRoutine->DcmDspStartRoutineOut)
                && (DCM_VARIABLE_LENGTH
                    == StartRoutine->DcmDspStartRoutineOut
                           ->DcmDspRoutineInOutSignal[StartRoutine->DcmDspStartRoutineOut->RoutineInOutSignalNum - 1u]
                           .DcmDspRoutineSignalType))
            {
                ResLen = Dcm_0x31Type->currentDataLength;
            }
            SchM_Enter_Dcm(Dcm_RoutineControlState);
            Dcm_RoutineControlState[*Dcm_0x31Type->pRoutineCfgId] = DCM_DSP_ROUTINE_ON;
            SchM_Exit_Dcm(Dcm_RoutineControlState);
        }
    }
    return ResLen;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
/********************************/
#if (STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(uint32, DCM_CODE) Dcm_UdsRCStopRoutine(
    uint8 MsgCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_0x31Types, AUTOMATIC, AUTOMATIC) Dcm_0x31Type,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) Ret,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint32 ReqLen = 0;
    uint32 ResLen = 0;
    uint8 Index;
    P2CONST(Dcm_DspStopRoutineType, TYPEDEF, DCM_CONST) StopRoutine;
    Dcm_StopRoutineFncType StopRoutineFnc;
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pInbuffer; /* PRQA S 3432 */  /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pOutBuffer; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint32 Offset =
        (Dcm_DslCfg.pDcmChannelCfg)[Dcm_ChannelCtrl[Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex].Dcm_ChannelCfgIndex]
            .offset;

    if (Dcm_DspCfg.pDcmDspRoutine[*Dcm_0x31Type->pRoutineCfgId].DcmDspStopRoutine == NULL_PTR)
    {
        /*StopRoutineFnc is NULL,send NRC 0x12*/
        *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        *Ret = E_NOT_OK;
    }

    if (E_OK == *Ret)
    {
        StopRoutine = Dcm_DspCfg.pDcmDspRoutine[*Dcm_0x31Type->pRoutineCfgId].DcmDspStopRoutine;
        if (StopRoutine->DcmDspStopRoutineIn != NULL_PTR)
        {
            for (Index = 0; Index < StopRoutine->DcmDspStopRoutineIn->RoutineInOutSignalNum; Index++)
            {
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
                ReqLen = ReqLen
                         + (uint32)((StopRoutine->DcmDspStopRoutineIn->DcmDspRoutineInOutSignal[Index]
                                         .DcmDspRoutineSignalLength
                                     + 7u)
                                    >> 3u);
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
            }
        }
        else
        {
            ReqLen = 0;
        }
        if (StopRoutine->DcmDspStopRoutineOut != NULL_PTR)
        {
            for (Index = 0; Index < StopRoutine->DcmDspStopRoutineOut->RoutineInOutSignalNum; Index++)
            {
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
                ResLen = ResLen
                         + (uint32)((StopRoutine->DcmDspStopRoutineOut->DcmDspRoutineInOutSignal[Index]
                                         .DcmDspRoutineSignalLength
                                     + 7u)
                                    >> 3u);
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
            }
        }
        else
        {
            ResLen = 0;
        }

        if ((NULL_PTR == StopRoutine->DcmDspStopRoutineIn)
            || (DCM_VARIABLE_LENGTH
                != StopRoutine->DcmDspStopRoutineIn
                       ->DcmDspRoutineInOutSignal[StopRoutine->DcmDspStopRoutineIn->RoutineInOutSignalNum - 1u]
                       .DcmDspRoutineSignalType))
        {
            if ((ReqLen + DCM_UDS0X31_REQ_DATA_MINLENGTH) != ((uint8)Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen))
            {
                /*the request message length is not correct,send NRC 0x13*/
                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                *Ret = E_NOT_OK;
            }
        }
    }

    if (E_OK == *Ret)
    {
        StopRoutineFnc = StopRoutine->DcmDspRoutineStopFnc;
        if (NULL_PTR == StopRoutineFnc)
        {
            /*StopRoutineFnc is NULL,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            *Ret = E_NOT_OK;
        }
    }

    if ((E_OK == *Ret) && (DCM_DSP_ROUTINE_ON != Dcm_RoutineControlState[*Dcm_0x31Type->pRoutineCfgId]))
    {
        /*the request sequence error,send NRC 0x24*/
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        *Ret = E_NOT_OK;
    }
    if (E_OK == *Ret)
    {
        pInbuffer = NULL_PTR;
        if (0u != ReqLen)
        {
            pInbuffer = &Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4];
        }
        pOutBuffer = NULL_PTR;
        if (0u != ResLen)
        {
            pOutBuffer = &Dcm_Channel[Offset + 4u];
        }
        Dcm_0x31Type->currentDataLength = (uint16)ReqLen;
        *Ret = (*StopRoutineFnc)(
            pInbuffer,
            Dcm_0x31Type->OpStatus,
            pOutBuffer,
            &Dcm_0x31Type->currentDataLength,
            ErrorCode);
        if (E_OK == *Ret)
        {
            if ((NULL_PTR != StopRoutine->DcmDspStopRoutineOut)
                && (DCM_VARIABLE_LENGTH
                    == StopRoutine->DcmDspStopRoutineOut
                           ->DcmDspRoutineInOutSignal[StopRoutine->DcmDspStopRoutineOut->RoutineInOutSignalNum - 1u]
                           .DcmDspRoutineSignalType))
            {
                ResLen = Dcm_0x31Type->currentDataLength;
            }
            SchM_Enter_Dcm(Dcm_RoutineControlState);
            Dcm_RoutineControlState[*Dcm_0x31Type->pRoutineCfgId] = DCM_DSP_ROUTINE_OFF;
            SchM_Exit_Dcm(Dcm_RoutineControlState);
        }
    }
    return ResLen;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
/********************************/
#if (STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(uint32, DCM_CODE) Dcm_UdsRCReqRoutineResult(
    uint8 MsgCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_0x31Types, AUTOMATIC, AUTOMATIC) Dcm_0x31Type,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) Ret,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint32 ReqLen = 0;
    uint32 ResLen = 0;
    uint8 Index;
    P2CONST(Dcm_DspRequestRoutineResultsType, TYPEDEF, DCM_CONST) RequestRoutineResults;
    Dcm_RequestResultsRoutineFncType RequestResultsFnc;
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pOutBuffer; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pInbuffer; /* PRQA S 3432 */  /* MISRA Rule 20.7 */
    uint32 Offset =
        (Dcm_DslCfg.pDcmChannelCfg)[Dcm_ChannelCtrl[Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex].Dcm_ChannelCfgIndex]
            .offset;

    RequestRoutineResults = Dcm_DspCfg.pDcmDspRoutine[*Dcm_0x31Type->pRoutineCfgId].DcmDspRequestRoutineResults;
    if (NULL_PTR == RequestRoutineResults)
    {
        *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
        *Ret = E_NOT_OK;
    }

    if (E_OK == *Ret)
    {
        if (NULL_PTR != RequestRoutineResults->DcmDspRequestRoutineResultsIn)
        {
            for (Index = 0; Index < RequestRoutineResults->DcmDspRequestRoutineResultsIn->RoutineInOutSignalNum;
                 Index++)
            {
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
                ReqLen =
                    ReqLen
                    + (uint32)((RequestRoutineResults->DcmDspRequestRoutineResultsIn->DcmDspRoutineInOutSignal[Index]
                                    .DcmDspRoutineSignalLength
                                + 7u)
                               >> 3u);
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
            }
        }
        else
        {
            ReqLen = 0;
        }
        if (RequestRoutineResults->DcmDspRequestRoutineResultsOut != NULL_PTR)
        {
            for (Index = 0; Index < RequestRoutineResults->DcmDspRequestRoutineResultsOut->RoutineInOutSignalNum;
                 Index++)
            {
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
                ResLen =
                    ResLen
                    + (uint32)((RequestRoutineResults->DcmDspRequestRoutineResultsOut->DcmDspRoutineInOutSignal[Index]
                                    .DcmDspRoutineSignalLength
                                + 7u)
                               >> 3u);
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
            }
        }
        else
        {
            ResLen = 0;
        }
        if ((NULL_PTR == RequestRoutineResults->DcmDspRequestRoutineResultsIn)
            || (DCM_VARIABLE_LENGTH
                != RequestRoutineResults->DcmDspRequestRoutineResultsIn
                       ->DcmDspRoutineInOutSignal
                           [RequestRoutineResults->DcmDspRequestRoutineResultsIn->RoutineInOutSignalNum - 1u]
                       .DcmDspRoutineSignalType))
        {
            if ((ReqLen + DCM_UDS0X31_REQ_DATA_MINLENGTH) != ((uint8)Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen))
            {
                /*the request message length is not correct,send NRC 0x13*/
                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                *Ret = E_NOT_OK;
            }
        }
    }

    if (E_OK == *Ret)
    {
        RequestResultsFnc = RequestRoutineResults->DcmDspRequestResultsRoutineFnc;
        if (NULL_PTR == RequestResultsFnc)
        {
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            *Ret = E_NOT_OK;
        }
    }
    if ((E_OK == *Ret) && (DCM_DSP_ROUTINE_INIT == Dcm_RoutineControlState[*Dcm_0x31Type->pRoutineCfgId]))
    {
        /*the request sequence error,send NRC 0x24*/
        *ErrorCode = DCM_E_REQUESTSEQUENCEERROR;
        *Ret = E_NOT_OK;
    }
    if (E_OK == *Ret)
    {
        pInbuffer = NULL_PTR;
        if (0u != ReqLen)
        {
            pInbuffer = &Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4];
        }
        pOutBuffer = NULL_PTR;
        if (0u != ResLen)
        {
            pOutBuffer = &Dcm_Channel[Offset + 4u];
        }
        Dcm_0x31Type->currentDataLength = (uint16)ReqLen;
        *Ret = (*RequestResultsFnc)(
            pInbuffer,
            Dcm_0x31Type->OpStatus,
            pOutBuffer,
            &Dcm_0x31Type->currentDataLength,
            ErrorCode);
        if ((NULL_PTR != RequestRoutineResults->DcmDspRequestRoutineResultsOut)
            && (DCM_VARIABLE_LENGTH
                == RequestRoutineResults->DcmDspRequestRoutineResultsOut
                       ->DcmDspRoutineInOutSignal
                           [RequestRoutineResults->DcmDspRequestRoutineResultsOut->RoutineInOutSignalNum - 1u]
                       .DcmDspRoutineSignalType))
        {
            ResLen = Dcm_0x31Type->currentDataLength;
        }
    }
    return ResLen;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#if ((STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED) && (STD_ON == DCM_DSP_REQUESTCONTROL_FUNC_ENABLED))
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(uint32, DCM_CODE) Dcm_UdsOBDStartRoutine(
    uint8 MsgCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_0x31Types, AUTOMATIC, AUTOMATIC) Dcm_0x31Type,
    P2VAR(Std_ReturnType, AUTOMATIC, AUTOMATIC) Ret,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint32 ReqLen = 0;
    uint32 ResLen = 0;
    uint8 Index;
    Dcm_StartRoutineFncType StartRoutineFnc;
    P2CONST(Dcm_DspStartRoutineType, TYPEDEF, DCM_CONST) StartRoutine;
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pInbuffer; /* PRQA S 3432 */  /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pOutBuffer; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint32 Offset =
        (Dcm_DslCfg.pDcmChannelCfg)[Dcm_ChannelCtrl[Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex].Dcm_ChannelCfgIndex]
            .offset;

    StartRoutine = Dcm_DspCfg.pDcmDspRoutine[*Dcm_0x31Type->pRoutineCfgId].DcmDspStartRoutine;
    if (NULL_PTR == StartRoutine)
    {
        *Ret = E_NOT_OK;
    }
    if (E_OK == *Ret)
    {
        if (NULL_PTR != StartRoutine->DcmDspStartRoutineIn)
        {
            for (Index = 0; Index < StartRoutine->DcmDspStartRoutineIn->RoutineInOutSignalNum; Index++)
            {
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
                ReqLen = ReqLen
                         + (uint32)((StartRoutine->DcmDspStartRoutineIn->DcmDspRoutineInOutSignal[Index]
                                         .DcmDspRoutineSignalLength
                                     + 7u)
                                    >> 3u);
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
            }
        }
        else
        {
            ReqLen = 0;
        }
        if (NULL_PTR != StartRoutine->DcmDspStartRoutineOut)
        {
            for (Index = 0; Index < StartRoutine->DcmDspStartRoutineOut->RoutineInOutSignalNum; Index++)
            {
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
                ResLen = ResLen
                         + (uint32)((StartRoutine->DcmDspStartRoutineOut->DcmDspRoutineInOutSignal[Index]
                                         .DcmDspRoutineSignalLength
                                     + 7u)
                                    >> 3u);
                /* PRQA S 4391++ */ /* MISRA Rule 10.8 */
            }
        }
        else
        {
            ResLen = 0;
        }
        /*check the request message length*/
        if ((NULL_PTR == StartRoutine->DcmDspStartRoutineIn)
            || (DCM_VARIABLE_LENGTH
                != StartRoutine->DcmDspStartRoutineIn
                       ->DcmDspRoutineInOutSignal[StartRoutine->DcmDspStartRoutineIn->RoutineInOutSignalNum - 1u]
                       .DcmDspRoutineSignalType))
        {
            if ((ReqLen + DCM_UDS0X31_REQ_DATA_MINLENGTH) != ((uint8)Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen))
            {
                /*the request message length is not correct,send NRC 0x13*/
                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                *Ret = E_NOT_OK;
            }
        }
    }

    if (E_OK == *Ret)
    {
        StartRoutineFnc = StartRoutine->DcmDspStartRoutineFnc;
        if (NULL_PTR == StartRoutineFnc)
        {
            *Ret = E_NOT_OK;
        }
    }
    if (E_OK == *Ret)
    {
        pInbuffer = NULL_PTR;
        if (0u != ReqLen)
        {
            pInbuffer = &Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4];
        }
        pOutBuffer = NULL_PTR;
        if (0u != ResLen)
        {
            pOutBuffer = &Dcm_Channel[Offset + 4u];
        }
        Dcm_0x31Type->currentDataLength = (uint16)ReqLen;
        *Ret = (*StartRoutineFnc)(
            pInbuffer,
            Dcm_0x31Type->OpStatus,
            pOutBuffer,
            &Dcm_0x31Type->currentDataLength,
            ErrorCode);
        if ((NULL_PTR != StartRoutine->DcmDspStartRoutineOut)
            && (DCM_VARIABLE_LENGTH
                == StartRoutine->DcmDspStartRoutineOut
                       ->DcmDspRoutineInOutSignal[StartRoutine->DcmDspStartRoutineOut->RoutineInOutSignalNum - 1u]
                       .DcmDspRoutineSignalType))
        {
            ResLen = Dcm_0x31Type->currentDataLength;
        }
    }
    return ResLen;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#if ((STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED) && (STD_ON == DCM_DSP_REQUESTCONTROL_FUNC_ENABLED))
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x31OBDDeal(
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_0x31Types, AUTOMATIC, DCM_VAR) Dcm_0x31Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType Ret = E_OK;
    uint32 SupportBuffer = 0;
    uint8 CtrlIndex;
    uint8 iloop;
    uint8 index;
    uint8 routineIdNum;
    boolean Find = FALSE;
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint32 Offset =
        (Dcm_DslCfg.pDcmChannelCfg)[Dcm_ChannelCtrl[Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex].Dcm_ChannelCfgIndex]
            .offset;
    uint16 routineId = (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2]) << 8u)
                       | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3]);

    switch (routineId)
    {
    case 0xE000u:
    case 0xE020u:
    case 0xE040u:
    case 0xE060u:
    case 0xE080u:
    case 0xE0A0u:
    case 0xE0C0u:
    case 0xE0E0u:
        if ((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen % 2u) == 0u)
        {
            routineIdNum = (uint8)((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen - 2u) >> 1u);
            for (index = 0; index < routineIdNum; index++)
            {
                routineId =
                    (uint16)(((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u + (2u * index)]) << 8u)
                             | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u + (2u * index)]));
                switch (routineId)
                {
                case 0xE000u:
                case 0xE020u:
                case 0xE040u:
                case 0xE060u:
                case 0xE080u:
                case 0xE0A0u:
                case 0xE0C0u:
                case 0xE0E0u:
                    if ((Dcm_DspCfg.DcmDspEnableObdMirror == TRUE) && (FALSE == Dcm_0x31Type->Find))
                    {
                        OBD_CheckSupportedTIDs((uint8)(routineId & 0xFFu), &SupportBuffer);
                        if (SupportBuffer != 0UL)
                        {
                            SchM_Enter_Dcm(Dcm_Channel);
                            if (index > 0u)
                            {
                                Dcm_Channel[Offset + 4u] = (uint8)(routineId >> 8u);
                                Offset++;
                                Dcm_Channel[Offset + 4u] = (uint8)(routineId);
                                Offset++;
                                (*Dcm_0x31Type->ResLen) += 2u;
                            }
                            Dcm_FillTo4bytes(&(Dcm_Channel[Offset + 4u]), &SupportBuffer);
                            SchM_Exit_Dcm(Dcm_Channel);
                            Offset += 4u;
                            (*Dcm_0x31Type->ResLen) += 4u;
                        }
                    }
                    else
                    {
                        for (iloop = 0; iloop < Dcm_DspCfg.DcmDspRoutineNum; iloop++)
                        {
                            if ((Dcm_DspCfg.pDcmDspRoutine[iloop].DcmDspRoutineId >= (routineId + 0x01u))
                                && (Dcm_DspCfg.pDcmDspRoutine[iloop].DcmDspRoutineId <= (routineId + 0x20u)))
                            {
                                SupportBuffer |=
                                    (uint32)1UL
                                    << (0x20u - (Dcm_DspCfg.pDcmDspRoutine[iloop].DcmDspRoutineId - routineId));
                            }
                            if (Dcm_DspCfg.pDcmDspRoutine[iloop].DcmDspRoutineId == routineId)
                            {
                                Find = TRUE;
                            }
                        }
                        if (Find != TRUE)
                        {
                            SupportBuffer = 0;
                        }
                        if (SupportBuffer != 0UL)
                        {
                            SchM_Enter_Dcm(Dcm_Channel);
                            if (index > 0u)
                            {
                                Dcm_Channel[Offset + 4u] = (uint8)(routineId >> 8u);
                                Offset++;
                                Dcm_Channel[Offset + 4u] = (uint8)(routineId);
                                Offset++;
                                (*Dcm_0x31Type->ResLen) += 2u;
                            }
                            Dcm_FillTo4bytes(&(Dcm_Channel[Offset + 4u]), &SupportBuffer);
                            SchM_Exit_Dcm(Dcm_Channel);
                            Offset += 4u;
                            (*Dcm_0x31Type->ResLen) += 4u;
                        }
                    }
                    break;
                default:
                    Ret = E_NOT_OK;
                    break;
                }
            }
            if (*Dcm_0x31Type->ResLen == 0u)
            {
                Ret = E_NOT_OK;
            }
        }
        else
        {
            /*the request message length is not correct,send NRC 0x13*/
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            Ret = E_NOT_OK;
        }
        break;
    default:
        if ((Dcm_DspCfg.DcmDspEnableObdMirror == TRUE) && (FALSE == Dcm_0x31Type->Find))
        {
            if (E_OK == OBD_FindCfgIndexOfTestID((uint8)(routineId & 0xFFu), &CtrlIndex))
            {
                SchM_Enter_Dcm(Dcm_Channel);
#if (STD_ON == DCM_OBD_SERVICE0X08_ENABLED)
                if (Dcm_DspCfg.pDcmDspRequestControl[CtrlIndex].DcmDspRequestControlInBufferSize
                    == (Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen - 4u))
                {
                    if (E_OK
                        == Rte_RequestControl(
                            (uint8)(routineId & 0xFFu),
                            &(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4]),
                            &(Dcm_Channel[Offset + 4u])))
                    {
                        *Dcm_0x31Type->ResLen =
                            Dcm_DspCfg.pDcmDspRequestControl[CtrlIndex].DcmDspRequestControlOutBufferSize;
                    }
                    else
#endif
                    {
                        /* the conditions of the system are not proper to run,send NRC 0x22*/
                        *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                        Ret = E_NOT_OK;
                    }
#if (STD_ON == DCM_OBD_SERVICE0X08_ENABLED)
                }
                else
                {
                    Ret = E_NOT_OK;
                }
#endif
                SchM_Exit_Dcm(Dcm_Channel);
            }
            else
            {
                /* there is no supported VehInfotype,ignore the request message */
                Ret = E_NOT_OK;
            }
        }
        else
        {
            if (TRUE == Dcm_0x31Type->Find)
            {
                (*Dcm_0x31Type->ResLen) = Dcm_UdsOBDStartRoutine(MsgCtrlId, Dcm_0x31Type, &Ret, ErrorCode);
                if (Ret == E_NOT_OK)
                {
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                }
            }
            else
            {
                /*if not found,send NRC 0x31*/
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Ret = E_NOT_OK;
            }
        }
        break;
    }
    return Ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
/********************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_RCConditonCheck(
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dcm_0x31Types, AUTOMATIC, DCM_VAR) Dcm_0x31Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */                              /* MISRA Rule 20.7 */
{
    Std_ReturnType Ret = E_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
#if ((STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED) && (DCM_DSP_ROUTINE_MAX_NUM > 0))
    boolean Find = FALSE;
    uint16 routineId;
    uint8 Index;
#endif

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current session supports the request service*/
    Ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_ROUTINE_CONTROL);
    if (E_NOT_OK == Ret)
    {
        /*the current session does not support the request service,send NRC = 0x7F*/
        *ErrorCode = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
    }
#endif
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    if (E_OK == Ret)
    {
        /*security check,check whether the current security supports the request service*/
        Ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_ROUTINE_CONTROL);
        if (E_NOT_OK == Ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif
    if ((E_OK == Ret) && (Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen < DCM_UDS0X31_REQ_DATA_MINLENGTH))
    {
        /*the length of massage is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        Ret = E_NOT_OK;
    }
    if (E_OK == Ret)
	{
		Ret = RTE_PreConditonCheck(Dcm_MsgCtrl[MsgCtrlId].SID,Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData);
		if (E_OK != Ret)
		{
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			Ret = E_NOT_OK;
		}
	}

#if ((STD_OFF == DCM_DSP_ROUTINE_FUNC_ENABLED) || (DCM_DSP_ROUTINE_MAX_NUM == 0))
    /*NRC 0x31:request out of range*/
    if (E_OK == Ret)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Ret = E_NOT_OK;
    }
#else
    if (E_OK == Ret)
    {
        /*find the required RoutineID in configuration*/
        routineId = (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2]) << 8u)
                    | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3]);
        for (Index = 0; (Index < Dcm_DspCfg.DcmDspRoutineNum) && (Find == FALSE); Index++)
        {
            if ((routineId == Dcm_DspCfg.pDcmDspRoutine[Index].DcmDspRoutineId)
                && (TRUE == Dcm_DspCfg.pDcmDspRoutine[Index].DcmDspRoutineUsed))
            {
                *Dcm_0x31Type->pRoutineCfgId = Index;
                Find = TRUE;
            }
        }

#if (STD_ON == DCM_DSP_REQUESTCONTROL_FUNC_ENABLED)
        if ((0xE000u <= routineId) && (0xE0FFu >= routineId))
        {
            Dcm_0x31Type->Find = Find;
            Ret = Dcm_UDS0x31OBDDeal(ProtocolCtrlId, Dcm_0x31Type, ErrorCode);
        }
        else
#endif
        {
            if (Find == FALSE)
            {
                /*if not found,send NRC 0x31*/
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                Ret = E_NOT_OK;
            }
        }
    }
#endif
    return Ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/********************************/
/**********************************************************************/
/*
 * Brief
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/***********************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
extern  uint8 reposflg;
extern uint8 u8KeyTempBuffVal[256];
FUNC(Std_ReturnType, DCM_CODE)
Dcm_UDS0x31(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 MsgCtrlId;
    uint32 Offset;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 SubFunction;
    uint32 ResLen = 0;
    uint8 RoutineCfgId;
#if ((STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED) && (DCM_DSP_ROUTINE_MAX_NUM > 0))
    uint16 routineId;
#endif
    Std_ReturnType Ret;
    Dcm_0x31Types Dcm_0x31Type;

    DCM_UNUSED(OpStatus);
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    /*get the Tx buffer*/
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
    SubFunction = Dcm_MsgCtrl[MsgCtrlId].Subfunction;

    Dcm_0x31Type.OpStatus = OpStatus;
    Dcm_0x31Type.pRoutineCfgId = &RoutineCfgId;
    Dcm_0x31Type.ResLen = &ResLen;
    Ret = Dcm_RCConditonCheck(ProtocolCtrlId, &Dcm_0x31Type, ErrorCode);

#if ((STD_OFF == DCM_DSP_ROUTINE_FUNC_ENABLED) || (DCM_DSP_ROUTINE_MAX_NUM == 0))
    /*NRC 0x31:request out of range*/
    if (E_OK == Ret)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        Ret = E_NOT_OK;
    }
#else
    if (E_OK == Ret)
    {
        /*find the required RoutineID in configuration*/
        routineId = (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2]) << 8u)
                    | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3]);
#if (STD_ON == DCM_DSP_REQUESTCONTROL_FUNC_ENABLED)
        if ((0xE000u > routineId) || (0xE0FFu < routineId))
        {
#endif
            /*check session and security*/
            Ret = Dcm_UdsRCSesAndSecCheck(RoutineCfgId, ErrorCode);
            if (E_OK == Ret)
            {
                /*check whether the sub-function is supported*/
                if ((SubFunction != DCM_UDS0X31_STARTROUTINE) && (SubFunction != DCM_UDS0X31_STOPROUTINE)
                    && (SubFunction != DCM_UDS0X31_REQUESTROUTINERESULTS))
                {
                    /*if the required sub-function is not supported,send NRC 0x12*/
                    *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                    Ret = E_NOT_OK;
                }
            }

            if (E_OK == Ret)
            {
                switch (SubFunction)
                {
                case DCM_UDS0X31_STARTROUTINE:
                    ResLen = Dcm_UdsRCStartRoutine(MsgCtrlId, &Dcm_0x31Type, &Ret, ErrorCode);
                    break;
                case DCM_UDS0X31_STOPROUTINE:
                    ResLen = Dcm_UdsRCStopRoutine(MsgCtrlId, &Dcm_0x31Type, &Ret, ErrorCode);
                    break;
                case DCM_UDS0X31_REQUESTROUTINERESULTS:
                    ResLen = Dcm_UdsRCReqRoutineResult(MsgCtrlId, &Dcm_0x31Type, &Ret, ErrorCode);
                    break;
                default:
                    *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
                    Ret = E_NOT_OK;
                    break;
                }
            }
#if (STD_ON == DCM_DSP_REQUESTCONTROL_FUNC_ENABLED)
        }
#endif
    }
    /* check tx data length */
    if ((E_OK == Ret) && ((ResLen + 4u) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize)))
    {
        /*Pdu length is bigger than buffer size,ignore the request message */
        *ErrorCode = DCM_E_RESPONSETOOLONG;
        Ret = E_NOT_OK;
    }
    /*check the return value*/
    switch (Ret)
    {
    case E_OK:
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x71;
        Dcm_Channel[Offset + 1u] = SubFunction;
        Dcm_Channel[Offset + 2u] = (uint8)(routineId >> 8u);
        Dcm_Channel[Offset + 3u] = (uint8)(routineId);
        SchM_Exit_Dcm(Dcm_Channel);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = (uint32)ResLen + 4u;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = (uint32)ResLen + 4u;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
        break;
    case E_NOT_OK:
        break;
    case DCM_E_PENDING:
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        break;
#if (STD_ON == DCM_DSLDIAGRESP_FORCERESPENDEN)
    case DCM_E_FORCE_RCRRP:
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].Dcm_Ret = DCM_E_FORCE_RCRRP;
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DsdInternal_SetNrc(ProtocolCtrlId, DCM_E_RESPONSE_PENDING);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
        break;
#endif
    default:
        /*unexpected return value,send NRC 0x22*/
        DsdInternal_SetNrc(ProtocolCtrlId, DCM_E_CONDITIONSNOTCORRECT);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
        Ret = E_NOT_OK;
        break;
    }
#endif
    return Ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
