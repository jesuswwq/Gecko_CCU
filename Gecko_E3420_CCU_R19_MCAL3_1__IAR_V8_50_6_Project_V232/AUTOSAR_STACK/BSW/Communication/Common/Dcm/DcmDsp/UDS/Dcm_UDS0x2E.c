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
         UDS:WriteDataByIdentifier (2E hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X2E_ENABLED)

typedef struct
{
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pRangeDidCfgIndex; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) pDidCfgIndex; /* PRQA S 3432 */           /* MISRA Rule 20.7 */
    P2VAR(boolean, AUTOMATIC, DCM_VAR_NOINIT) pRangeDidFlag; /* PRQA S 3432 */   /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DidInfoCfgIndex; /* PRQA S 3432 */        /* MISRA Rule 20.7 */
} Dcm_0x2ETypes;
/***************************/
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static Std_ReturnType DspInternalUDS0x2E_DidCheck(
    Dcm_OpStatusType OpStatus,
    uint16 RecDid,
    Dcm_0x2ETypes* Dcm_0x2EType,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Dcm_DidSupportedType DidSupported;
    uint8 Index;
    uint8 Idx;
    boolean Flag = FALSE;
    boolean Flagx = FALSE;
    Std_ReturnType ret = E_NOT_OK;

    *Dcm_0x2EType->pRangeDidFlag = FALSE;
    /*find the corresponding DID in configuration*/
    /*first check whether the receiveDid is single did*/
    for (Index = 0; (Index < Dcm_DspCfg.DcmDspDidNum) && (FALSE == Flag); Index++)
    {
        /*single did check*/
        if ((RecDid == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId)
            && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed))
        {
            Flag = TRUE;
            (*Dcm_0x2EType->pDidCfgIndex) = Index;
            ret = E_OK;
        }
    }
    /*if the receiveDid is not single did,the check whether the receiveDid is range did*/
    if (FALSE == Flag)
    {
        /*range did check*/
        if ((RecDid < 0xF200u) || (RecDid > 0xF3FFu))
        {
            /*range did can not be DDDid*/
            for (Idx = 0; (Idx < Dcm_DspCfg.DcmDspDidRangeNum) && (FALSE == Flagx); Idx++)
            {
                /*this range not have gaps*/
                if ((RecDid >= Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeIdentifierLowerLimit)
                    && (RecDid <= Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeIdentifierUpperLimit))
                {
                    if (TRUE == Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeHasGaps)
                    {
                        if (Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeIsDidAvailableFnc != NULL_PTR)
                        {
                            ret = Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeIsDidAvailableFnc(
                                RecDid,
                                OpStatus,
                                &DidSupported);
                            if ((ret == E_OK) && (DCM_DID_SUPPORTED == DidSupported))
                            {
                                *Dcm_0x2EType->pRangeDidCfgIndex = Idx;
                                *Dcm_0x2EType->pRangeDidFlag = TRUE;
                                Flagx = TRUE;
                            }
                            else
                            {
                                ret = E_NOT_OK;
                            }
                        }
                    }
                    else
                    {
                        *Dcm_0x2EType->pRangeDidCfgIndex = Idx;
                        *Dcm_0x2EType->pRangeDidFlag = TRUE;
                        Flagx = TRUE;
                    }
                }
            }
        }

        if (TRUE == Flagx)
        {
            (*Dcm_0x2EType->pDidCfgIndex) = Index;
            ret = E_OK;
        }
    }
    if (E_OK != ret)
    {
        /*if not found,send NRC 0x31*/
        *pNrc = DCM_E_REQUESTOUTOFRANGE;
    }

    return ret;
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
/***************************/
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static Std_ReturnType DspInternalUDS0x2E_DidSesCheck(uint8 DidInfoCfgIndex)
{
    uint8 Index;
    Std_ReturnType ret = E_NOT_OK;
    P2CONST(Dcm_DspDidWriteType, AUTOMATIC, DCM_APPL_CONST) pDspDidWrite;

    pDspDidWrite = Dcm_DspCfg.pDcmDspDidInfo[DidInfoCfgIndex].pDcmDspDidWrite;
    if ((NULL_PTR == pDspDidWrite))
    {
        /*Judge DID the configuration items pDcmDspDidWrite whether NULL_PTR,
         *if not supported,send Nrc 0x31*/
        ret = E_NOT_OK;
    }
    else
    {
        if (pDspDidWrite->DcmDspDidWriteSessionRefNum != 0u)
        {
            for (Index = 0; (Index < (pDspDidWrite->DcmDspDidWriteSessionRefNum)) && (E_NOT_OK == ret); Index++)
            {
                if (Dcm_MkCtrl.Dcm_ActiveSes == pDspDidWrite->pDcmDspDidWriteSessionRow[Index])
                {
                    ret = E_OK;
                }
            }
        }
        else
        {
            ret = E_OK;
        }
    }
    return ret;
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
/***************************/
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static Std_ReturnType DspInternalUDS0x2E_DidSecCheck(
    uint8 DidInfoCfgIndex,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    P2CONST(Dcm_DspDidWriteType, AUTOMATIC, DCM_APPL_CONST) pDspDidWrite;
    Std_ReturnType ret = E_NOT_OK;
    uint8 Index;

    pDspDidWrite = Dcm_DspCfg.pDcmDspDidInfo[DidInfoCfgIndex].pDcmDspDidWrite;
    if ((NULL_PTR == pDspDidWrite))
    {
        /*Judge DID the configuration items pDcmDspDidWrite whether NULL_PTR,
         *if not supported,send Nrc 0x31*/
        *pNrc = DCM_E_REQUESTOUTOFRANGE;
    }
    else
    {
        if (pDspDidWrite->DcmDspDidWriteSecurityLevelRefNum != 0u)
        {
            for (Index = 0; (Index < (pDspDidWrite->DcmDspDidWriteSecurityLevelRefNum)) && (E_NOT_OK == ret); Index++)
            {
                if (Dcm_MkCtrl.Dcm_ActiveSec == pDspDidWrite->pDcmDspDidWriteSecurityLevelRow[Index])
                {
                    ret = E_OK;
                }
            }
            if (E_NOT_OK == ret)
            {
                /*if the current security is not supported,send NRC 0x33*/
                *pNrc = DCM_E_SECURITYACCESSDENIED;
            }
        }
        else
        {
            ret = E_OK;
        }
    }
    return ret;
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
/**************************************************/
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static Std_ReturnType DspInternalUDS0x2E_DidWriteDataLength(
    uint8 DidCfgIndex,
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) pDidSize) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 DidSignalIndex;
    P2CONST(Dcm_DspDataType, TYPEDEF, DCM_CONST) pDspDidData;
    Std_ReturnType ret = E_OK;

    *pDidSize = 0;
    for (DidSignalIndex = 0; DidSignalIndex < Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidSignalNum; DidSignalIndex++)
    {
        pDspDidData = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].pDcmDspDidSignal[DidSignalIndex].pDcmDspDidData;
        if (pDspDidData->DcmDspDataType != DCM_UINT8_DYN)
        {
            (*pDidSize) += ((pDspDidData->DcmDspDataSize + 7u) >> 3u);
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    return ret;
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
/***************************/
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static Std_ReturnType DspInternalUDS0x2E_DidWrite(
    Dcm_OpStatusType OpStatus,
    uint8 MsgCtrlId,
    uint8 DidCfgIndex,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 DidSignalIndex;
    uint8 DidSignalNum;
    uint16 DidSignalPos;
    uint16 Offest = 0;
    P2CONST(Dcm_DspDataType, TYPEDEF, DCM_CONST) pDspDidData;
    Std_ReturnType ret = E_OK;
#if (NVM_ENABLE == STD_ON)
    NvM_RequestResultType NvmRet;
#endif
    DidSignalNum = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidSignalNum;
    for (DidSignalIndex = 0; ((DidSignalIndex < DidSignalNum) && (ret == E_OK)); DidSignalIndex++)
    {
        pDspDidData = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].pDcmDspDidSignal[DidSignalIndex].pDcmDspDidData;
        DidSignalPos =
            Offest
            + ((Dcm_DspCfg.pDcmDspDid[DidCfgIndex].pDcmDspDidSignal[DidSignalIndex].DcmDspDidDataPos + 7u) >> 3u);
        if (USE_BLOCK_ID != pDspDidData->DcmDspDataUsePort)
        {
            if (pDspDidData->DcmDspDataWriteFnc == NULL_PTR)
            {
                /*if DcmDspDidWriteFnc is NULL,send NRC 0x22*/
                *pNrc = DCM_E_CONDITIONSNOTCORRECT;
                ret = E_NOT_OK;
            }
            else
            {
                ret = pDspDidData->DcmDspDataWriteFnc(
                    &Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u + DidSignalPos],
                    ((pDspDidData->DcmDspDataSize + 7u) >> 3u),
                    OpStatus,
                    pNrc);
            }
        }
        Offest += ((pDspDidData->DcmDspDataSize + 7u) >> 3u);
        switch (ret)
        {
        case E_OK:
        case E_NOT_OK:
            break;
        case DCM_E_PENDING:
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            break;
        default:
            *pNrc = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
            break;
        }
#if (NVM_ENABLE == STD_ON)
        if ((USE_BLOCK_ID == pDspDidData->DcmDspDataUsePort) && (ret == E_OK))
        {
            if (OpStatus != DCM_PENDING)
            {
                NvM_SetBlockLockStatus(pDspDidData->DcmDspDataBlockId, FALSE);
                ret = NvM_WriteBlock(
                    pDspDidData->DcmDspDataBlockId,
                    (void*)&Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u + DidSignalPos]);
                if (E_OK == ret)
                {
                    SchM_Enter_Dcm(Dcm_MsgCtrl);
                    Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                    SchM_Exit_Dcm(Dcm_MsgCtrl);
                    ret = DCM_E_PENDING;
                }
            }
            else
            {
                ret = NvM_GetErrorStatus(pDspDidData->DcmDspDataBlockId, &NvmRet);
                if (E_OK == ret)
                {
                    if ((NVM_REQ_OK == NvmRet) || (NVM_REQ_BLOCK_SKIPPED == NvmRet))
                    {
                        NvM_SetBlockLockStatus(pDspDidData->DcmDspDataBlockId, TRUE);
                        ret = E_OK;
                    }
                    else if (NVM_REQ_PENDING == NvmRet)
                    {
                        SchM_Enter_Dcm(Dcm_MsgCtrl);
                        Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                        SchM_Exit_Dcm(Dcm_MsgCtrl);
                        ret = DCM_E_PENDING;
                    }
                    else
                    {
                        *pNrc = DCM_E_GENERALREJECT;
                        ret = E_NOT_OK;
                    }
                }
            }
        }
#endif
    }
    return ret;
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
/***************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x2EServiceConditionCheck(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    Dcm_0x2ETypes* Dcm_0x2EType,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */                                         /* MISRA Rule 2.2 */
    uint8 MsgCtrlId;
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    uint16 RecDid;
#endif

    /*if the required protocol is configured,get the index of runtime datum*/
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_WRITE_DATA_BY_IDENTIFIER);
    if (E_NOT_OK == ret)
    {
        /*the current session does not support the request service,send NRC = 0x7F*/
        *ErrorCode = DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION;
    }
#endif
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    /*security check,check whether the current security supports the request service*/
    if (E_OK == ret)
    {
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_WRITE_DATA_BY_IDENTIFIER);
        if (E_NOT_OK == ret)
        {
            *ErrorCode = DCM_E_SECURITYACCESSDENIED; /*NRC = 0x33*/
        }
    }
#endif
    /*check the massage length*/
    if (E_OK == ret)
    {
        if (Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen < DCM_UDS0X2E_REQ_DATA_MINLENGTH)
        {
            /*the length of massage is not correct,send NRC 0x13*/
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            ret = E_NOT_OK;
        }
    }
#if (STD_OFF == DCM_DSP_DID_FUNC_ENABLED)
    /*NRC 0x31:request out of range*/
    if (E_OK == ret)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
#else
    /*get the required DID from request message*/
    if (E_OK == ret)
    {
        RecDid = (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1]) << 8u)
                 | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2]);

        /*Determine if the DID is configured*/
        ret = DspInternalUDS0x2E_DidCheck(OpStatus, RecDid, Dcm_0x2EType, ErrorCode);
        if (DCM_E_PENDING == ret)
        {
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
        }
    }

    if (E_OK == ret)
    {
        if (TRUE == *Dcm_0x2EType->pRangeDidFlag)
        {
            *Dcm_0x2EType->DidInfoCfgIndex =
                Dcm_DspCfg.pDcmDspDidRange[*Dcm_0x2EType->pRangeDidCfgIndex].DcmDspDidRangeInfoIndex;
        }
        else
        {
            *Dcm_0x2EType->DidInfoCfgIndex = Dcm_DspCfg.pDcmDspDid[*Dcm_0x2EType->pDidCfgIndex].DcmDspDidInfoIndex;
        }
        /*check whether the Did can be configured*/
        if ((TRUE == (Dcm_DspCfg.pDcmDspDidInfo[*Dcm_0x2EType->DidInfoCfgIndex].DcmDspDidDynamicallyDefined))
            || (Dcm_DspCfg.pDcmDspDidInfo[*Dcm_0x2EType->DidInfoCfgIndex].pDcmDspDidWrite == NULL_PTR))
        {
            /*if the Did can be dynamically defined,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
    }
#endif
    /*check the current session*/
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    if (E_OK == ret)
    {
        ret = DspInternalUDS0x2E_DidSesCheck(*Dcm_0x2EType->DidInfoCfgIndex);
        if (E_NOT_OK == ret)
        {
            /*if the current session is not support the Did,send NRC 31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
#endif
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

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
/***************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE)
Dcm_UDS0x2E(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    uint16 RecDid;
    uint16 DidSize = 0;
    uint32 Offset;
    uint8 DidCfgIndex;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 RangeDidCfgIndex;
    boolean RangeDidFlag;
    uint8 DidInfoCfgIndex;
#endif
    uint8 MsgCtrlId;
    Std_ReturnType ret;
    Dcm_0x2ETypes Dcm_0x2EType;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    RecDid = (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1]) << 8u)
             | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2]);

    Dcm_0x2EType.pDidCfgIndex = &DidCfgIndex;
    Dcm_0x2EType.pRangeDidCfgIndex = &RangeDidCfgIndex;
    Dcm_0x2EType.pRangeDidFlag = &RangeDidFlag;
    Dcm_0x2EType.DidInfoCfgIndex = &DidInfoCfgIndex;
    ret = Dcm_Uds0x2EServiceConditionCheck(OpStatus, ProtocolCtrlId, &Dcm_0x2EType, ErrorCode);

#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    if (E_OK == ret)
    {
        if (FALSE == RangeDidFlag)
        {
            ret = DspInternalUDS0x2E_DidWriteDataLength(DidCfgIndex, &DidSize);
            if ((E_OK == ret) && ((3u + DidSize) != (uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen))
            {
                /*check message length*/
                /*if the message length is not correct,send NRC 0x13*/
                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                ret = E_NOT_OK;
            }

            if (E_OK == ret)
            {
                ret = RTE_PreConditonCheck(Dcm_MsgCtrl[MsgCtrlId].SID,Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData);
                if (E_OK != ret)
                {
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                    ret = E_NOT_OK;
                }
            }

#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
            if (E_OK == ret)
            {
                /*check the current security level*/
                ret = DspInternalUDS0x2E_DidSecCheck(DidInfoCfgIndex, ErrorCode);
            }
#endif

            if (E_OK == ret)
            {
                ret = DspInternalUDS0x2E_DidWrite(OpStatus, MsgCtrlId, DidCfgIndex, ErrorCode);
            }
        }
        else
        {
            /*read data length to be writen*/
            if (NULL_PTR == Dcm_DspCfg.pDcmDspDidRange[RangeDidCfgIndex].DcmDspDidRangeReadDataLengthFnc)
            {
                /*DcmDspDidReadDataLengthFnc is NULL,send NRC 0x22*/
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                ret = E_NOT_OK;
            }
            if (E_OK == ret)
            {
                ret = Dcm_DspCfg.pDcmDspDidRange[RangeDidCfgIndex].DcmDspDidRangeReadDataLengthFnc(
                    RecDid,
                    OpStatus,
                    &DidSize);
                if (E_NOT_OK == ret)
                {
                    *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                    ret = E_NOT_OK;
                }
                else if (DCM_E_PENDING == ret)
                {
                    SchM_Enter_Dcm(Dcm_MsgCtrl);
                    Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                    SchM_Exit_Dcm(Dcm_MsgCtrl);
                }
                else
                {
                    /*idle*/
                }
            }

#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
            if (E_OK == ret)
            {
                /*check the current security level*/
                ret = DspInternalUDS0x2E_DidSecCheck(DidInfoCfgIndex, ErrorCode);
            }
#endif

            /*write data*/
            if ((E_OK == ret) && (NULL_PTR == Dcm_DspCfg.pDcmDspDidRange[RangeDidCfgIndex].DcmDspDidRangeWriteDidFnc))
            {
                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                ret = E_NOT_OK;
            }

            if (E_OK == ret)
            {
                ret = Dcm_DspCfg.pDcmDspDidRange[RangeDidCfgIndex].DcmDspDidRangeWriteDidFnc(
                    RecDid,
                    &(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3]),
                    OpStatus,
                    DidSize,
                    ErrorCode);
                if (DCM_E_PENDING == ret)
                {
                    SchM_Enter_Dcm(Dcm_MsgCtrl);
                    Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                    SchM_Exit_Dcm(Dcm_MsgCtrl);
                }
            }
        }
    }

    if (E_OK == ret)
    {
        /*assemble and send positive response*/
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
        /* check tx data length */
        if ((3u) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
        {
            /*Pdu length is bigger than buffer size,ignore the request message */
            *ErrorCode = DCM_E_RESPONSETOOLONG;
            ret = E_NOT_OK;
        }
    }
    if (E_OK == ret)
    {
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x6E;
        Dcm_Channel[Offset + 1u] = (uint8)(RecDid >> 8u);
        Dcm_Channel[Offset + 2u] = (uint8)RecDid;
        SchM_Exit_Dcm(Dcm_Channel);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = 3u;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = 3u;
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
