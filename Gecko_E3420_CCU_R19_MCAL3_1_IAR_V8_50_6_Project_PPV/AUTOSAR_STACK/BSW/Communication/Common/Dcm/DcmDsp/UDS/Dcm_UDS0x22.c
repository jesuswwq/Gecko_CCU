
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
         UDS:ReadDataByIdentifier (22 hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X22_ENABLED)

typedef struct
{
    uint16 RangeDidCfgIndex;
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) ResOffset; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint16 RecDid;
    uint16 DidSize;
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pRangeDidCfgIndex; /* PRQA S 3432 */    /* MISRA Rule 20.7 */
    P2VAR(uint16, AUTOMATIC, DCM_VAR_NOINIT) pDidCfgIndex; /* PRQA S 3432 */        /* MISRA Rule 20.7 */
    P2VAR(boolean, AUTOMATIC, DCM_VAR_NOINIT) pRangeDidFlag; /* PRQA S 3432 */      /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) NoFindDidReadNum; /* PRQA S 3432 */     /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) DidSessionSupportNum; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) NoFindDidNum; /* PRQA S 3432 */              /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) MixPid; /* PRQA S 3432 */                    /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) noFindPidNum; /* PRQA S 3432 */              /* MISRA Rule 20.7 */
    uint16 DidCfgIndex;
    P2VAR(boolean, AUTOMATIC, AUTOMATIC) readDidSignalFlag; /* PRQA S 3432 */       /* MISRA Rule 20.7 */
} Dcm_0x22Types;

#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UdsAssembleResponse(
    Dcm_OpStatusType OpStatus,
    uint16 DidCfgIndex,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) ResOffset,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc);
#endif
/************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  0x2C sub process>
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#if (STD_ON == DCM_UDS_SERVICE0X2C_ENABLED)
#if ((STD_ON == DCM_UDS_SERVICE0X2C_ENABLED) && (DCM_DSP_DDDID_MAX_NUMBER > 0u))
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UdsAssembleResponse_0x2CSubDeal(
    Dcm_OpStatusType OpStatus,
    P2CONST(Dcm_DDDidElementsDataTypes, TYPEDEF, DCM_CONST) DDDid,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) ResOffset,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    P2CONST(Dcm_DspDataType, TYPEDEF, DCM_CONST) pDspDidData;
    Std_ReturnType ret = E_OK;
    uint16 Did;
    uint8 Pos;
    uint8 Data[DCM_TEMP_BUFFER_LENGTH] = {0};
    uint8 Index;
    uint16 pDidCfgIndex = 0;
    uint16 DidSignalPos = 0;
    uint16 Size;

    Did = (uint16)(DDDid->Data & 0xFFFFUL);
    Pos = (uint8)((DDDid->Data & 0xFF0000UL) >> 16u);
    for (Index = 0; Index < Dcm_DspCfg.DcmDspDidNum; Index++)
    { /*single did check*/
        if ((Did == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId) && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed))
        {
            pDidCfgIndex = Index;
            break;
        }
    }
    for (Index = 0; (Index < Dcm_DspCfg.pDcmDspDid[pDidCfgIndex].DcmDspDidSignalNum) && (E_OK == ret); Index++)
    {
        pDspDidData = Dcm_DspCfg.pDcmDspDid[pDidCfgIndex].pDcmDspDidSignal[Index].pDcmDspDidData;
        Size = 0;
        if (DCM_UINT8_DYN == pDspDidData->DcmDspDataType)
        { /*DidDataSize is dynamic*/
            if (NULL_PTR == pDspDidData->DcmDspDataReadDataLengthFnc)
            {
                /*DcmDspDidReadDataLengthFnc is NULL,send NRC 0x22*/
                *pNrc = DCM_E_CONDITIONSNOTCORRECT;
                ret = E_NOT_OK;
            }
            else
            {
                ret = pDspDidData->DcmDspDataReadDataLengthFnc(OpStatus, &Size);
            }
        }
        else
        {
            /*DidDataSize is fixed*/
            Size = ((pDspDidData->DcmDspDataSize + 7u) >> 3u);
        }

        if (E_OK == ret)
        {
            DidSignalPos += ((Dcm_DspCfg.pDcmDspDid[pDidCfgIndex].pDcmDspDidSignal[Index].DcmDspDidDataPos + 7u) >> 3u);
            if ((NULL_PTR == pDspDidData->DcmDspDataReadFnc) || ((DidSignalPos + DDDid->Size) > DCM_TEMP_BUFFER_LENGTH))
            {
                /*DcmDspDataReadFnc is NULL,send NRC 0x22*/
                *pNrc = DCM_E_CONDITIONSNOTCORRECT;
                ret = E_NOT_OK;
            }
            else
            {
                ret = pDspDidData->DcmDspDataReadFnc(OpStatus, &Data[DidSignalPos], pNrc);
            }
        }
        DidSignalPos += Size;
    }
    SchM_Enter_Dcm(Dcm_Channel);
    Dcm_MemoryCopy(&(Data[Pos]), &(Dcm_Channel[*ResOffset]), DDDid->Size);
    SchM_Exit_Dcm(Dcm_Channel);
    *ResOffset += DDDid->Size;
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

#if ((STD_ON == DCM_UDS_SERVICE0X2C_ENABLED) && (DCM_DSP_DDDID_MAX_NUMBER > 0u))
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  0x2C sub process>
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
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UdsAssembleResponse_0x2C(
    Dcm_OpStatusType OpStatus,
    Dcm_0x22Types* Dcm_0x22Type,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret;
    P2VAR(Dcm_DDDidElementsDataTypes, TYPEDEF, DCM_CONST) DDDid; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint8 DDDidNum;
    uint8 index;
    uint8 RangeInfoIndex;
    P2CONST(Dcm_DspReadMemoryRangeInfoType, AUTOMATIC, DCM_VAR_NOINIT) pDcmDspReadMemoryRangeInfo;
    P2CONST(Dcm_DspMemoryIdInfoType, AUTOMATIC, DCM_VAR_NOINIT) pDcmDspMemoryIdInfo;
    uint8 MemoryIdentifier = 0;
    uint8 Index;
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint8 iloop;
    boolean Find = FALSE;

    for (index = 0; (index < DCM_DSP_DDDID_MAX_NUMBER) && (Find == FALSE); index++)
    {
        if (Dcm_0x22Type->RecDid == Dcm_DDDid[index].DDDid)
        {
            Find = TRUE;
        }
    }
    index--;
    if (Find == TRUE)
    {
        ret = DsdInternal_DDDIDcheckPerSourceDID(index, pNrc);
        /*set the response message*/
        if (E_OK == ret)
        {
            DDDidNum = Dcm_DDDid[index].DDDIDNumOfElements;
            for (iloop = 0; (iloop < DDDidNum) && (E_OK == ret); iloop++)
            {
                DDDid = &Dcm_DDDid[index].DcmDspAlternativeArgumentData[iloop];
                if (DDDid->Subfunction == DCM_UDS0X2C_01_DDBYDID)
                {
                    ret = Dcm_UdsAssembleResponse_0x2CSubDeal(OpStatus, DDDid, Dcm_0x22Type->ResOffset, pNrc);
                }
                else if (DDDid->Subfunction == DCM_UDS0X2C_02_DDBYMEMORY)
                {
                    for (Index = 0u; Index < Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfoNum; Index++)
                    {
                        pDcmDspMemoryIdInfo = &(Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfo[Index]);
                        for (RangeInfoIndex = 0; (RangeInfoIndex < pDcmDspMemoryIdInfo->DcmDspReadMemoryRangeInfoNum)
                                                 && (pDcmDspMemoryIdInfo != NULL_PTR);
                             RangeInfoIndex++)
                        {
                            pDcmDspReadMemoryRangeInfo =
                                &(pDcmDspMemoryIdInfo->DcmDspReadMemoryRangeInfo[RangeInfoIndex]);
                            if ((pDcmDspReadMemoryRangeInfo != NULL_PTR)
                                && ((pDcmDspReadMemoryRangeInfo->DcmDspReadMemoryRangeLow <= DDDid->Data)
                                    && (pDcmDspReadMemoryRangeInfo->DcmDspReadMemoryRangeHigh
                                        >= (DDDid->Data + DDDid->Size - 1u))))
                            {
                                MemoryIdentifier =
                                    Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfo[Index].DcmDspMemoryIdValue;
                            }
                        }
                    }
                    ret = Dcm_ReadMemory(
                        OpStatus,
                        MemoryIdentifier,
                        DDDid->Data,
                        (uint32)DDDid->Size,
                        &(Dcm_Channel[*Dcm_0x22Type->ResOffset]),
                        pNrc);
                    if (DCM_READ_FAILED == ret)
                    {
                        /*the processing is not successful,send NRC */
                        ret = E_NOT_OK;
                    }
#if (STD_ON == DCM_DSLDIAGRESP_FORCERESPENDEN)
                    else if (DCM_READ_FORCE_RCRRP == ret)
                    {
                        /*the processing is pending,send NRC 0x78 */
                        DsdInternal_SetNrc(ProtocolCtrlId, DCM_E_RESPONSE_PENDING);
                        DsdInternal_ProcessingDone(ProtocolCtrlId);
                        SchM_Enter_Dcm(Dcm_MsgCtrl);
                        Dcm_MsgCtrl[MsgCtrlId].Dcm_Ret = DCM_E_FORCE_RCRRP;
                        Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                        SchM_Exit_Dcm(Dcm_MsgCtrl);
                    }
#endif
                    else if (DCM_READ_PENDING == ret)
                    {
                        SchM_Enter_Dcm(Dcm_MsgCtrl);
                        Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                        SchM_Exit_Dcm(Dcm_MsgCtrl);
                    }
                    else
                    {
                        /*idle*/
                    }
                    (*Dcm_0x22Type->ResOffset) += DDDid->Size;
                }
                else
                {
                    *pNrc = DCM_E_CONDITIONSNOTCORRECT;
                    ret = E_NOT_OK;
                }
            }
        }
    }
    else
    {
        // *pNrc = DCM_E_REQUESTOUTOFRANGE;
        // ret = E_NOT_OK;
        /*set the response message*/
        ret = Dcm_UdsAssembleResponse(OpStatus, Dcm_0x22Type->DidCfgIndex, Dcm_0x22Type->ResOffset, pNrc);
        if (DCM_E_PENDING == ret)
        {
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
#endif
#endif
/************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Did Number check>
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
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x22_DidNumbercheck(uint8 numberOfDid)
{
    Std_ReturnType ret = E_OK;
    if (0u != (Dcm_DspCfg.DcmDspMaxDidToRead))
    {
        /*check the limitation of number of required DID*/
        if (numberOfDid > Dcm_DspCfg.DcmDspMaxDidToRead)
        {
            ret = E_NOT_OK;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Check Supported>
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#if (DCM_DSP_PID_FUNC_ENABLED == STD_ON)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    DspInternalUDS0x22_CheckSupported(uint16 Did, P2VAR(uint32, AUTOMATIC, AUTOMATIC) ResOffset)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
    uint32 SupportBuffer = 0;
    uint16 iloop;
    boolean Find = FALSE;
    for (iloop = 0; iloop < Dcm_DspCfg.DcmDspDidNum; iloop++)
    {
        if ((Dcm_DspCfg.pDcmDspDid[iloop].DcmDspDidId >= (Did + 0x01u))
            && (Dcm_DspCfg.pDcmDspDid[iloop].DcmDspDidId <= (Did + 0x20u)))
        {
            SupportBuffer |= (uint32)1UL << (0x20u - (Dcm_DspCfg.pDcmDspDid[iloop].DcmDspDidId - Did));
        }
        if (Dcm_DspCfg.pDcmDspDid[iloop].DcmDspDidId == Did)
        {
            Find = TRUE;
        }
    }

    if (Find == FALSE)
    {
        SupportBuffer = 0;
    }

    if (SupportBuffer != 0UL)
    {
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[*ResOffset] = (uint8)((Did) >> 8u); /*echo of DID MSB*/
        *ResOffset += 1u;
        Dcm_Channel[*ResOffset] = (uint8)(Did);
        *ResOffset += 1u;
        Dcm_FillTo4bytes(&(Dcm_Channel[*ResOffset]), &SupportBuffer);
        SchM_Exit_Dcm(Dcm_Channel);
        *ResOffset += 4u;
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
        SchM_Enter_Dcm(Dcm_PageBufferData);
        Dcm_PageBufferData.LastFilledSize = 6u;
        SchM_Exit_Dcm(Dcm_PageBufferData);
#endif
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
#endif
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Did Check >
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
/************************/
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE)
    DspInternalUDS0x22_DidCheck(Dcm_OpStatusType OpStatus, Dcm_0x22Types* Dcm_0x22Type)
{
    Dcm_DidSupportedType DidSupported;
    uint16 Index;
    uint8 Idx;
    boolean Flag = FALSE;
    boolean Flagx = FALSE;
    Std_ReturnType ret = E_NOT_OK;
#if ((STD_ON == DCM_UDS_SERVICE0X2C_ENABLED) && (DCM_DSP_DDDID_MAX_NUMBER > 0u))
    uint8 iloop;
#endif

    (*Dcm_0x22Type->pRangeDidFlag) = FALSE;
    /*first check whether the receiveDid is single did*/
    for (Index = 0; (Index < Dcm_DspCfg.DcmDspDidNum) && (FALSE == Flag); Index++)
    {
        /*single did check*/
        if ((Dcm_0x22Type->RecDid == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId)
            && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed))
        {
// #if ((STD_ON == DCM_UDS_SERVICE0X2C_ENABLED) && (DCM_DSP_DDDID_MAX_NUMBER > 0u))
//             if ((Dcm_0x22Type->RecDid >= 0xF200u) && (Dcm_0x22Type->RecDid <= 0xF3FFu)
//                 && (Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidInfoIndex]
//                         .DcmDspDidDynamicallyDefined
//                     == TRUE)
//                 && (Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidInfoIndex].DcmDspDDDIDMaxElements
//                     > 0u))
//             {
//                 for (iloop = 0; (iloop < DCM_DSP_DDDID_MAX_NUMBER) && (Flag == FALSE); iloop++)
//                 {
//                     if (Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId == Dcm_DDDid[iloop].DDDid)
//                     {
//                         Flag = TRUE;
//                         (*Dcm_0x22Type->pDidCfgIndex) = Index;
//                         ret = E_OK;
//                     }
//                 }
//             }
//             else
// #endif
            {
                Flag = TRUE;
                (*Dcm_0x22Type->pDidCfgIndex) = Index;
                ret = E_OK;
            }
        }
    }
    /*if the receiveDid is not single did,the check whether the receiveDid is range did*/
    if (FALSE == Flag)
    {
        /*range did check*/
        if ((Dcm_0x22Type->RecDid < 0xF200u) || (Dcm_0x22Type->RecDid > 0xF3FFu))
        {
            /*range did can not be DDDid*/
            for (Idx = 0; (Idx < Dcm_DspCfg.DcmDspDidRangeNum) && (FALSE == Flagx); Idx++)
            {
                /*this range not have gaps*/
                if ((Dcm_0x22Type->RecDid >= Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeIdentifierLowerLimit)
                    && (Dcm_0x22Type->RecDid <= Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeIdentifierUpperLimit))
                {
                    if (TRUE == Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeHasGaps)
                    {
                        if (Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeIsDidAvailableFnc != NULL_PTR)
                        {
                            ret = Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeIsDidAvailableFnc(
                                Dcm_0x22Type->RecDid,
                                OpStatus,
                                &DidSupported);
                            if ((ret == E_OK) && (DCM_DID_SUPPORTED == DidSupported))
                            {
                                *Dcm_0x22Type->pRangeDidCfgIndex = Idx;
                                *Dcm_0x22Type->pRangeDidFlag = TRUE;
                                Flagx = TRUE;
                            }
                        }
                    }
                    else
                    {
                        *Dcm_0x22Type->pRangeDidCfgIndex = Idx;
                        *Dcm_0x22Type->pRangeDidFlag = TRUE;
                        Flagx = TRUE;
                    }
                }
            }
        }
        if (FALSE == Flagx)
        {
            ret = E_NOT_OK;
        }
        else
        {
            (*Dcm_0x22Type->pDidCfgIndex) = Index;
            ret = E_OK;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Did  Info Check >
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x22_DidInfoCheck(uint8 DidInfoCfgIdx)
{
    Std_ReturnType ret = E_NOT_OK;
    if (Dcm_DspCfg.pDcmDspDidInfo[DidInfoCfgIdx].pDcmDspDidRead != NULL_PTR)
    {
        ret = E_OK;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Did  Session Check >
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x22_DidSessionCheck(
    uint8 DidInfoCfgIndex,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) DidSessionSupportNum,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint8 Index;
    boolean Flag = FALSE;
    P2CONST(Dcm_DspDidReadType, AUTOMATIC, DCM_APPL_CONST) pDspDidRead;
    Std_ReturnType ret = E_OK;
    pDspDidRead = Dcm_DspCfg.pDcmDspDidInfo[DidInfoCfgIndex].pDcmDspDidRead;
    if (NULL_PTR == pDspDidRead)
    {
        /*if the DcmDspDidRead of required Did is not configured,send NRC 0x31*/
        *pNrc = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
    else
    {
        if (pDspDidRead->DcmDspDidReadSessionRefNum != 0u)
        {
            for (Index = 0; (Index < (pDspDidRead->DcmDspDidReadSessionRefNum)) && (FALSE == Flag); Index++)
            {
                if (Dcm_MkCtrl.Dcm_ActiveSes == pDspDidRead->pDcmDspDidReadSessionRow[Index])
                {
                    Flag = TRUE;
                    (*DidSessionSupportNum) += 1u;
                }
            }
            if (FALSE == Flag)
            {
                ret = E_NOT_OK;
            }
        }
        else
        {
            (*DidSessionSupportNum) += 1u;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Did  Ecu  Signal Check >
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dsp_UDS0x22_DidEcuSignalCheck(
#if (NVM_ENABLE == STD_ON)
    Dcm_OpStatusType OpStatus,
    uint8 MsgCtrlId,
#endif
    Dcm_0x22Types* Dcm_0x22Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 DidSignalIndex;
    uint8 DidSignalNum;
    P2CONST(Dcm_DspDataType, TYPEDEF, DCM_CONST) pDspDidData;
    Std_ReturnType ret = E_NOT_OK;
#if (NVM_ENABLE == STD_ON)
    NvM_RequestResultType NvmRet;
#endif

    *Dcm_0x22Type->readDidSignalFlag = FALSE;
    DidSignalNum = Dcm_DspCfg.pDcmDspDid[Dcm_0x22Type->DidCfgIndex].DcmDspDidSignalNum;
    for (DidSignalIndex = 0; DidSignalIndex < DidSignalNum; DidSignalIndex++)
    {
        pDspDidData = Dcm_DspCfg.pDcmDspDid[Dcm_0x22Type->DidCfgIndex].pDcmDspDidSignal[DidSignalIndex].pDcmDspDidData;
        if (USE_ECU_SIGNAL == pDspDidData->DcmDspDataUsePort)
        {
            pDspDidData->DcmDspDataReadEcuSignalFnc(&Dcm_Channel[*Dcm_0x22Type->ResOffset]);
            (*Dcm_0x22Type->ResOffset) += (uint32)(((uint32)pDspDidData->DcmDspDataSize + 7u) >> 3u);
            *Dcm_0x22Type->readDidSignalFlag = TRUE;
            ret = E_OK;
        }
        else if (USE_BLOCK_ID == pDspDidData->DcmDspDataUsePort)
        {
#if (NVM_ENABLE == STD_ON)
            *Dcm_0x22Type->readDidSignalFlag = TRUE;
            if (DCM_PENDING != OpStatus)
            {
                (void)NvM_ReadBlock(pDspDidData->DcmDspDataBlockId, (void*)&Dcm_Channel[*Dcm_0x22Type->ResOffset]);
            }
            (void)NvM_GetErrorStatus(pDspDidData->DcmDspDataBlockId, &NvmRet);
            if ((NVM_REQ_OK == NvmRet) || (NVM_REQ_RESTORED_FROM_ROM == NvmRet))
            {
                (*Dcm_0x22Type->ResOffset) += (uint32)(((uint32)pDspDidData->DcmDspDataSize + 7u) >> 3u);
                ret = E_OK;
            }
            else if (NVM_REQ_PENDING == NvmRet)
            {
                (*Dcm_0x22Type->ResOffset) += (uint32)(((uint32)pDspDidData->DcmDspDataSize + 7u) >> 3u);
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                ret = DCM_E_PENDING;
            }
            else
            {
                *pNrc = DCM_E_CONDITIONSNOTCORRECT;
            }
#endif
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

/************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Did  Condition Check >
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x22_DidConditionCheck(
    Dcm_OpStatusType OpStatus,
    uint16 DidCfgIndex,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 DidSignalIndex;
    uint8 DidSignalNum;
    P2CONST(Dcm_DspDataType, TYPEDEF, DCM_CONST) pDspDidData;
    Std_ReturnType ret = E_OK;

    DidSignalNum = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidSignalNum;
    for (DidSignalIndex = 0; DidSignalIndex < DidSignalNum; DidSignalIndex++)
    {
        pDspDidData = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].pDcmDspDidSignal[DidSignalIndex].pDcmDspDidData;
        if ((TRUE == pDspDidData->DcmConditionCheckReadFncUsed)
            && (NULL_PTR != pDspDidData->DcmDspDataConditionCheckReadFnc))
        {

            ret = pDspDidData->DcmDspDataConditionCheckReadFnc(OpStatus, pNrc);
        }
        if ((TRUE == pDspDidData->DcmConditionCheckReadFncUsed)
            && (NULL_PTR == pDspDidData->DcmDspDataConditionCheckReadFnc))
        {
            *pNrc = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/***************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Read Range Did DataLength >
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x22_ReadRangeDidDataLength(
    Dcm_OpStatusType OpStatus,
    Dcm_0x22Types* Dcm_0x22Type,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint16, AUTOMATIC, AUTOMATIC) pDidSize,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret;

    if (NULL_PTR == Dcm_DspCfg.pDcmDspDidRange[Dcm_0x22Type->RangeDidCfgIndex].DcmDspDidRangeReadDataLengthFnc)
    {
        /*DcmDspDidReadDataLengthFnc is NULL,send NRC 0x22*/
        *pNrc = DCM_E_CONDITIONSNOTCORRECT;
        ret = E_NOT_OK;
    }
    else
    {
        ret = Dcm_DspCfg.pDcmDspDidRange[Dcm_0x22Type->RangeDidCfgIndex].DcmDspDidRangeReadDataLengthFnc(
            Dcm_0x22Type->RecDid,
            OpStatus,
            pDidSize);
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service   >
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
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x22ServiceConditonCheck(
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */                                         /* MISRA Rule 2.2 */
    uint8 MsgCtrlId;

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_READ_DATA_BY_IDENTIFIER);
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
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_READ_DATA_BY_IDENTIFIER);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif
    /*if the required protocol is configured,get the index of runtime datum*/
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    if (E_OK == ret)
    {
        /*check the message length*/
        if ((0u == (Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen & 1u))
            || (Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen < DCM_UDS0X22_REQ_DATA_MINLENGTH))
        {
            /*the length of message is not correct,send NRC 0x13*/
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            ret = E_NOT_OK;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Response >
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UdsAssembleResponse(
    Dcm_OpStatusType OpStatus,
    uint16 DidCfgIndex,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, AUTOMATIC) ResOffset,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint32 DidSignalPos;
    uint8 DidSignalIndex;
    uint8 DidSignalNum;
    P2CONST(Dcm_DspDataType, TYPEDEF, DCM_CONST) pDspDidData;
    Std_ReturnType ret = E_OK;
    uint16 Size;

    DidSignalNum = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidSignalNum;
    for (DidSignalIndex = 0; (DidSignalIndex < DidSignalNum) && (E_OK == ret); DidSignalIndex++)
    {
        pDspDidData = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].pDcmDspDidSignal[DidSignalIndex].pDcmDspDidData;
        Size = 0;
        if (DCM_UINT8_DYN == pDspDidData->DcmDspDataType)
        {
            /*DidDataSize is dynamic*/
            if (NULL_PTR == pDspDidData->DcmDspDataReadDataLengthFnc)
            {
                /*DcmDspDidReadDataLengthFnc is NULL,send NRC 0x22*/
                *pNrc = DCM_E_CONDITIONSNOTCORRECT;
                ret = E_NOT_OK;
            }
            else
            {
                ret = pDspDidData->DcmDspDataReadDataLengthFnc(OpStatus, &Size);
            }
        }
        else
        {
            /*DidDataSize is fixed*/
            Size = ((pDspDidData->DcmDspDataSize + 7u) >> 3u);
        }
        if (E_OK == ret)
        {
            DidSignalPos =
                *ResOffset
                + (uint32)(((uint32)Dcm_DspCfg.pDcmDspDid[DidCfgIndex].pDcmDspDidSignal[DidSignalIndex].DcmDspDidDataPos
                            + 7u)
                           >> 3u);
            if ((NULL_PTR == pDspDidData->DcmDspDataReadFnc) || ((DidSignalPos + (uint32)Size) > DCM_CHANNEL_LENGTH))
            {
                /*DcmDspDataReadFnc is NULL,send NRC 0x22*/
                *pNrc = DCM_E_CONDITIONSNOTCORRECT;
                ret = E_NOT_OK;
            }
            else
            {
                ret = pDspDidData->DcmDspDataReadFnc(OpStatus, &Dcm_Channel[DidSignalPos], pNrc);
            }
            /*ResOffset equal to last position add last size of the signal of did*/
            *ResOffset = DidSignalPos + (uint32)Size;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Response >
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UdsAssembleRangeDidResponse(
    Dcm_OpStatusType OpStatus,
    Dcm_0x22Types* Dcm_0x22Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;

    if (NULL_PTR == Dcm_DspCfg.pDcmDspDidRange[Dcm_0x22Type->RangeDidCfgIndex].DcmDspDidRangeReadDidFnc)
    {
        *pNrc = DCM_E_CONDITIONSNOTCORRECT;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    {
        ret = Dcm_DspCfg.pDcmDspDidRange[Dcm_0x22Type->RangeDidCfgIndex].DcmDspDidRangeReadDidFnc(
            Dcm_0x22Type->RecDid,
            &Dcm_Channel[*Dcm_0x22Type->ResOffset],
            OpStatus,
            Dcm_0x22Type->DidSize,
            pNrc);
        if (E_OK == ret)
        {
            (*Dcm_0x22Type->ResOffset) = (*Dcm_0x22Type->ResOffset) + Dcm_0x22Type->DidSize;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/***************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Obd Did Deal >
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#if (DCM_DSP_PID_FUNC_ENABLED == STD_ON)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x22_ObdDidDealF4(uint8 ProtocolCtrlId, Dcm_0x22Types* Dcm_0x22Type)
{
    Std_ReturnType ret = E_OK;
    uint32 SupportBuffer = 0;
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    uint32 Offset;
#endif
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 MsgCtrlId;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
#endif

    /* Service 01 */
    switch (Dcm_0x22Type->RecDid)
    {
    case 0xF400u:
    case 0xF420u:
    case 0xF440u:
    case 0xF460u:
    case 0xF480u:
    case 0xF4A0u:
    case 0xF4C0u:
    case 0xF4E0u:
        if ((*Dcm_0x22Type->MixPid == NORMAL_REQUEST) || (*Dcm_0x22Type->MixPid == NEED_CALL_UDS_API))
        {
            ret = E_NOT_OK;
        }
        else
        {
            if (Dcm_DspCfg.DcmDspEnableObdMirror == TRUE)
            {
#if (DCM_DSP_PID_FUNC_ENABLED == STD_ON)
                OBD_CheckSupportedPIDs((uint8)(Dcm_0x22Type->RecDid & 0xFFu), &SupportBuffer, 0x01);
#endif
                if (SupportBuffer != 0UL)
                {
                    SchM_Enter_Dcm(Dcm_Channel);
                    Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)((Dcm_0x22Type->RecDid) >> 8u); /*echo of DID MSB*/
                    (*Dcm_0x22Type->ResOffset) += 1u;
                    Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)(Dcm_0x22Type->RecDid);
                    (*Dcm_0x22Type->ResOffset) += 1u;
                    Dcm_FillTo4bytes(&(Dcm_Channel[*Dcm_0x22Type->ResOffset]), &SupportBuffer);
                    SchM_Exit_Dcm(Dcm_Channel);
                    (*Dcm_0x22Type->ResOffset) += 4u;
                }
                else
                {
                    *(Dcm_0x22Type->noFindPidNum) += 1u;
                }
            }
            else
            {
                if (E_OK != DspInternalUDS0x22_CheckSupported(Dcm_0x22Type->RecDid, Dcm_0x22Type->ResOffset))
                {
                    *(Dcm_0x22Type->noFindPidNum) += 1u;
                }
            }
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
            if ((*Dcm_0x22Type->ResOffset - Offset) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                Dcm_PageBufferData.LastFilled = FALSE;
                SchM_Exit_Dcm(Dcm_PageBufferData);
            }
#endif
            *Dcm_0x22Type->MixPid = SUPPORT_REQUEST;
        }
        break;
    default:
        if (*Dcm_0x22Type->MixPid == SUPPORT_REQUEST)
        {
            ret = E_NOT_OK;
        }
        else
        {
            *Dcm_0x22Type->MixPid = NEED_CALL_UDS_API;
        }
        break;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Obd Did Deal >
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
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x22_ObdDidDealF8(uint8 ProtocolCtrlId, Dcm_0x22Types* Dcm_0x22Type)
{
    Std_ReturnType ret = E_OK;
    uint32 SupportBuffer = 0;
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    uint32 Offset;
#endif
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 MsgCtrlId;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
#endif

    /* Service 01 */
    switch (Dcm_0x22Type->RecDid)
    {
    case 0xF800u:
    case 0xF820u:
    case 0xF840u:
    case 0xF860u:
    case 0xF880u:
    case 0xF8A0u:
    case 0xF8C0u:
    case 0xF8E0u:
        if ((*Dcm_0x22Type->MixPid == NORMAL_REQUEST) || (*Dcm_0x22Type->MixPid == NEED_CALL_UDS_API))
        {
            ret = E_NOT_OK;
        }
        else
        {
            if (Dcm_DspCfg.DcmDspEnableObdMirror == TRUE)
            {
#if (DCM_DSP_VEHINFO_FUNC_ENABLED == STD_ON)
                OBD_SetAvailabilityInfoTypeValue((uint8)(Dcm_0x22Type->RecDid & 0xFFu), &SupportBuffer);
#endif
                if (SupportBuffer != 0UL)
                {
                    SchM_Enter_Dcm(Dcm_Channel);
                    Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)((Dcm_0x22Type->RecDid) >> 8u); /*echo of DID MSB*/
                    (*Dcm_0x22Type->ResOffset) += 1u;
                    Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)(Dcm_0x22Type->RecDid);
                    (*Dcm_0x22Type->ResOffset) += 1u;
                    Dcm_FillTo4bytes(&(Dcm_Channel[*Dcm_0x22Type->ResOffset]), &SupportBuffer);
                    SchM_Exit_Dcm(Dcm_Channel);
                    (*Dcm_0x22Type->ResOffset) += 4u;
                }
                else
                {
                    *(Dcm_0x22Type->noFindPidNum) += 1u;
                }
            }
            else
            {
                if (E_OK != DspInternalUDS0x22_CheckSupported(Dcm_0x22Type->RecDid, Dcm_0x22Type->ResOffset))
                {
                    *(Dcm_0x22Type->noFindPidNum) += 1u;
                }
            }
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
            if ((*Dcm_0x22Type->ResOffset - Offset) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                Dcm_PageBufferData.LastFilled = FALSE;
                SchM_Exit_Dcm(Dcm_PageBufferData);
            }
#endif
            *Dcm_0x22Type->MixPid = SUPPORT_REQUEST;
        }
        break;
    default:
        if (*Dcm_0x22Type->MixPid == SUPPORT_REQUEST)
        {
            ret = E_NOT_OK;
        }
        else
        {
            *Dcm_0x22Type->MixPid = NEED_CALL_UDS_API;
        }
        break;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Obd Did Deal >
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
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x22_ObdDidDealF6(
    uint8 ProtocolCtrlId,
    Dcm_0x22Types* Dcm_0x22Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
    uint32 SupportBuffer = 0;
#ifdef DEM_OBD_SUPPORT
#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
    uint8 TIDvalue;
    uint8 UaSID;
    uint8 Mid = (uint8)(Dcm_0x22Type->RecDid & 0xFFu);
    uint8 TidNum = 0;
    uint8 iloop = 0;
    uint16 Testvalue;
    uint16 Lowlimvalue;
    uint16 Upplimvalue;
#endif
#endif
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    uint32 Offset;
#endif
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 MsgCtrlId;
    uint8 DidNum;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
#endif
    /*calculate the number of required DID*/
    DidNum = (uint8)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen >> 1u);

    /* Service 01 */
    switch (Dcm_0x22Type->RecDid)
    {
    case 0xF600u:
    case 0xF620u:
    case 0xF640u:
    case 0xF660u:
    case 0xF680u:
    case 0xF6A0u:
    case 0xF6C0u:
    case 0xF6E0u:
        if ((*Dcm_0x22Type->MixPid == NORMAL_REQUEST) || (*Dcm_0x22Type->MixPid == NEED_CALL_UDS_API))
        {
            ret = E_NOT_OK;
        }
        else
        {
#ifdef DEM_OBD_SUPPORT
#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
            (void)Dem_DcmGetAvailableOBDMIDs(Mid, &SupportBuffer);
#endif
#endif
            if (SupportBuffer != 0u)
            {
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)((Dcm_0x22Type->RecDid) >> 8u);
                /*echo of DID MSB*/
                *Dcm_0x22Type->ResOffset += 1u;
                Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)(Dcm_0x22Type->RecDid);
                *Dcm_0x22Type->ResOffset += 1u;
                Dcm_FillTo4bytes(&(Dcm_Channel[*Dcm_0x22Type->ResOffset]), &SupportBuffer);
                SchM_Exit_Dcm(Dcm_Channel);
                (*Dcm_0x22Type->ResOffset) += 4u;
            }
            else
            {
                *(Dcm_0x22Type->noFindPidNum) += 1u;
            }
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
            if ((*Dcm_0x22Type->ResOffset - Offset) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                Dcm_PageBufferData.LastFilled = FALSE;
                SchM_Exit_Dcm(Dcm_PageBufferData);
            }
#endif
            *Dcm_0x22Type->MixPid = SUPPORT_REQUEST;
        }
        break;
    default:
        if ((*Dcm_0x22Type->MixPid == SUPPORT_REQUEST) || (DidNum > 1u))
        {
            ret = E_NOT_OK;
        }
        else
        {
            if (Dcm_DspCfg.DcmDspEnableObdMirror == TRUE)
            {
#ifdef DEM_OBD_SUPPORT
#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
                ret = Dem_DcmGetNumTIDsOfOBDMID(Mid, &TidNum);
                if ((TidNum != 0u) && (ret == E_OK))
                {
                    for (; iloop < TidNum; iloop++)
                    {
                        ret = Dem_DcmGetDTRData(Mid, iloop, &TIDvalue, &UaSID, &Testvalue, &Lowlimvalue, &Upplimvalue);
                        if (ret == E_OK)
                        {
                            SchM_Enter_Dcm(Dcm_Channel);
                            Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)((Dcm_0x22Type->RecDid) >> 8u);
                            /*echo of DID MSB*/
                            (*Dcm_0x22Type->ResOffset) += 1u;
                            Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)(Dcm_0x22Type->RecDid);
                            (*Dcm_0x22Type->ResOffset) += 1u;
                            Dcm_Channel[*Dcm_0x22Type->ResOffset] = TIDvalue;
                            (*Dcm_0x22Type->ResOffset) += 1u;
                            Dcm_Channel[*Dcm_0x22Type->ResOffset] = UaSID;
                            (*Dcm_0x22Type->ResOffset) += 1u;
                            Dcm_Channel[*Dcm_0x22Type->ResOffset] =
                                (uint8)((Testvalue & (OBD_DATA_LSB_MASK << 8u)) >> 8u);
                            (*Dcm_0x22Type->ResOffset) += 1u;
                            Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)(Testvalue & OBD_DATA_LSB_MASK);
                            (*Dcm_0x22Type->ResOffset) += 1u;
                            Dcm_Channel[*Dcm_0x22Type->ResOffset] =
                                (uint8)((Lowlimvalue & (OBD_DATA_LSB_MASK << 8u)) >> 8u);
                            (*Dcm_0x22Type->ResOffset) += 1u;
                            Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)(Lowlimvalue & OBD_DATA_LSB_MASK);
                            (*Dcm_0x22Type->ResOffset) += 1u;
                            Dcm_Channel[*Dcm_0x22Type->ResOffset] =
                                (uint8)((Upplimvalue & (OBD_DATA_LSB_MASK << 8u)) >> 8u);
                            (*Dcm_0x22Type->ResOffset) += 1u;
                            Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)(Upplimvalue & OBD_DATA_LSB_MASK);
                            SchM_Exit_Dcm(Dcm_Channel);
                            (*Dcm_0x22Type->ResOffset) += 1u;
                        }
                    }
                }
                else
#endif
#endif
                {
                    /* there is no supported TID,send NRC 0x31 */
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    ret = E_NOT_OK;
                }
                *Dcm_0x22Type->MixPid = NORMAL_REQUEST;
            }
            else
            {
                *Dcm_0x22Type->MixPid = NEED_CALL_UDS_API;
            }
        }
        break;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Obd Did Deal >
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
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x22_ObdDidDeal(
    uint8 ProtocolCtrlId,
    Dcm_0x22Types* Dcm_0x22Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;

    if ((Dcm_0x22Type->RecDid >= 0xF400u) && (Dcm_0x22Type->RecDid <= 0xF4FFu))
    {
        ret = DspInternalUDS0x22_ObdDidDealF4(ProtocolCtrlId, Dcm_0x22Type);
    }
    else if ((Dcm_0x22Type->RecDid >= 0xF800u) && (Dcm_0x22Type->RecDid <= 0xF8FFu))
    {
        ret = DspInternalUDS0x22_ObdDidDealF8(ProtocolCtrlId, Dcm_0x22Type);
    }
    else if ((Dcm_0x22Type->RecDid >= 0xF600u) && (Dcm_0x22Type->RecDid <= 0xF6FFu))
    {
        ret = DspInternalUDS0x22_ObdDidDealF6(ProtocolCtrlId, Dcm_0x22Type, ErrorCode);
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
#endif
/***************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  none Obd Did Deal >
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x22_NonObdDidNOrangeDeal(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    Dcm_0x22Types* Dcm_0x22Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret;
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    uint8 TxChannelCfgIndex = Dcm_ChannelCtrl[Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex].Dcm_ChannelCfgIndex;
    uint32 Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
#endif
#if (STD_ON == DCM_UDS_SERVICE0X2C_ENABLED)
#endif

    ret = Dsp_UDS0x22_DidEcuSignalCheck(
#if (NVM_ENABLE == STD_ON)
        OpStatus,
        MsgCtrlId,
#endif
        Dcm_0x22Type,
        ErrorCode);
    if (FALSE == *Dcm_0x22Type->readDidSignalFlag)
    {
        /*check the current DID condition is OK*/
        ret = DspInternalUDS0x22_DidConditionCheck(OpStatus, Dcm_0x22Type->DidCfgIndex, ErrorCode);
        if (DCM_E_PENDING == ret)
        {
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
        }
        else if (E_OK == ret)
        {
#if ((STD_ON == DCM_UDS_SERVICE0X2C_ENABLED) && (DCM_DSP_DDDID_MAX_NUMBER > 0u))
            if ((Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[Dcm_0x22Type->DidCfgIndex].DcmDspDidInfoIndex]
                     .DcmDspDidDynamicallyDefined
                 == TRUE)
                && (Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[Dcm_0x22Type->DidCfgIndex].DcmDspDidInfoIndex]
                        .DcmDspDDDIDMaxElements
                    > 0u)
                && (Dcm_0x22Type->RecDid > 0xF200u) && (Dcm_0x22Type->RecDid < 0xF3FFu))
            {
                ret = Dcm_UdsAssembleResponse_0x2C(OpStatus, Dcm_0x22Type, ProtocolCtrlId, ErrorCode);
            }
            else
#endif
            {
                /*set the response message*/
                ret = Dcm_UdsAssembleResponse(OpStatus, Dcm_0x22Type->DidCfgIndex, Dcm_0x22Type->ResOffset, ErrorCode);
                if (DCM_E_PENDING == ret)
                {
                    SchM_Enter_Dcm(Dcm_MsgCtrl);
                    Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                    SchM_Exit_Dcm(Dcm_MsgCtrl);
                }
            }
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
            if ((E_OK == ret)
                && ((*Dcm_0x22Type->ResOffset - Offset)
                    > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize)))
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                Dcm_PageBufferData.LastFilled = FALSE;
                SchM_Exit_Dcm(Dcm_PageBufferData);
            }
#endif
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

/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  none Obd Did Deal >
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
static FUNC(Std_ReturnType, DCM_CODE) DspInternalUDS0x22_NonObdDidDeal(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    Dcm_0x22Types* Dcm_0x22Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret;
    uint8 DidInfoCfgIndex;
    uint16 DidSize = 0;
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    uint8 TxChannelCfgIndex = Dcm_ChannelCtrl[Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex].Dcm_ChannelCfgIndex;
    uint32 Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
#endif
    /*find the required DID in configuration*/
    ret = DspInternalUDS0x22_DidCheck(OpStatus, Dcm_0x22Type);
    if (E_NOT_OK == ret)
    {
        (*Dcm_0x22Type->NoFindDidNum) += 1u;
        ret = E_OK;
    }
    else
    {
        if (TRUE == *Dcm_0x22Type->pRangeDidFlag)
        {
            DidInfoCfgIndex = Dcm_DspCfg.pDcmDspDidRange[*Dcm_0x22Type->pRangeDidCfgIndex].DcmDspDidRangeInfoIndex;
        }
        else
        {
            DidInfoCfgIndex = Dcm_DspCfg.pDcmDspDid[*Dcm_0x22Type->pDidCfgIndex].DcmDspDidInfoIndex;
        }
        /*if the required DID is found,check whether the pDcmDspDidRead container is configured*/
        ret = DspInternalUDS0x22_DidInfoCheck(DidInfoCfgIndex);
        if (E_NOT_OK == ret)
        {
            (*Dcm_0x22Type->NoFindDidReadNum) += 1u;
            ret = E_OK; /* PRQA S 2982 */ /* MISRA Rule 2.2 */
        }
        else
        {
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
            /*check the current session*/
            ret = DspInternalUDS0x22_DidSessionCheck(DidInfoCfgIndex, Dcm_0x22Type->DidSessionSupportNum, ErrorCode);
            if (E_NOT_OK == ret)
            {
                ret = E_OK;
            }
            else
#endif /* check the current session */
            {
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
                /*check the current security level*/
                ret = DsdInternal_DidSecurityCheck(DidInfoCfgIndex, ErrorCode);
                if (E_OK == ret)
#endif
                { /*set the response message*/
                    SchM_Enter_Dcm(Dcm_Channel);
                    Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)((Dcm_0x22Type->RecDid) >> 8u);
                    /*echo of DID MSB*/
                    (*Dcm_0x22Type->ResOffset) += 1u;
                    Dcm_Channel[*Dcm_0x22Type->ResOffset] = (uint8)(Dcm_0x22Type->RecDid);
                    SchM_Exit_Dcm(Dcm_Channel);
                    (*Dcm_0x22Type->ResOffset) += 1u;
                    if (FALSE == *Dcm_0x22Type->pRangeDidFlag)
                    {
                        Dcm_0x22Type->DidCfgIndex = *Dcm_0x22Type->pDidCfgIndex;
                        ret =
                            DspInternalUDS0x22_NonObdDidNOrangeDeal(OpStatus, ProtocolCtrlId, Dcm_0x22Type, ErrorCode);
                    }
                    else
                    {
                        Dcm_0x22Type->RangeDidCfgIndex = *Dcm_0x22Type->pRangeDidCfgIndex;
                        /*Read the current length of the data in DID*/
                        ret = DspInternalUDS0x22_ReadRangeDidDataLength(OpStatus, Dcm_0x22Type, &DidSize, ErrorCode);
                        if (DCM_E_PENDING == ret)
                        {
                            SchM_Enter_Dcm(Dcm_MsgCtrl);
                            Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                            SchM_Exit_Dcm(Dcm_MsgCtrl);
                        }
                        else if (E_OK == ret)
                        {
                            /*DidSize over the DcmDspDidRangeMaxDataLength,Send NRC 0x22*/
                            if (DidSize > Dcm_DspCfg.pDcmDspDidRange[*Dcm_0x22Type->pRangeDidCfgIndex]
                                              .DcmDspDidRangeMaxDataLength)
                            {
                                *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
                                ret = E_NOT_OK;
                            }
                        }
                        else
                        {
                            /*idle*/
                        }
                        if (E_OK == ret)
                        {
                            Dcm_0x22Type->DidSize = DidSize;
                            Dcm_0x22Type->RangeDidCfgIndex = *Dcm_0x22Type->pRangeDidCfgIndex;
                            /*set the response message*/
                            ret = Dcm_UdsAssembleRangeDidResponse(OpStatus, Dcm_0x22Type, ErrorCode);
                            if (DCM_E_PENDING == ret)
                            {
                                SchM_Enter_Dcm(Dcm_MsgCtrl);
                                Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                                SchM_Exit_Dcm(Dcm_MsgCtrl);
                            }
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
                            if (((*Dcm_0x22Type->ResOffset) - Offset)
                                > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
                            {
                                SchM_Enter_Dcm(Dcm_PageBufferData);
                                Dcm_PageBufferData.LastFilled = FALSE;
                                SchM_Exit_Dcm(Dcm_PageBufferData);
                            }
#endif
                        }
                    }
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
                    SchM_Enter_Dcm(Dcm_PageBufferData);
                    Dcm_PageBufferData.LastFilledSize = DidSize;
                    SchM_Exit_Dcm(Dcm_PageBufferData);
#endif
                }
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service  Check Tx Length>
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
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x22_CheckTxLength(
    uint8 ProtocolCtrlId,
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
    uint16 Index0,
    uint32 ReqOffset,
#endif
    uint32 ResOffset)
{
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    uint32 Offset;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
#endif
    uint8 MsgCtrlId;
    Std_ReturnType ret = E_OK;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
    /* check tx data length */
    if
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
        (
#endif
            ((ResOffset - Offset) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
            || (0UL != Dcm_PageBufferData.TotalSize))
    {
        if (0UL == Dcm_PageBufferData.TotalSize)
        {
            SchM_Enter_Dcm(Dcm_PageBufferData);
            Dcm_PageBufferData.TotalSize = ResOffset - Offset;
            SchM_Exit_Dcm(Dcm_PageBufferData);
            DsdInternal_StartPagedProcessing(ProtocolCtrlId);
        }
        else
        {
            if (Dcm_PageBufferData.LastFilled == TRUE)
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                Dcm_PageBufferData.IloopOne = Index0;
                Dcm_PageBufferData.ReqOffset = ReqOffset;
                Dcm_PageBufferData.ThisPageSize = ResOffset - Offset;
                SchM_Exit_Dcm(Dcm_PageBufferData);
            }
            else
            {
                SchM_Enter_Dcm(Dcm_PageBufferData);
                Dcm_PageBufferData.IloopOne = Index0 - 1u;
                Dcm_PageBufferData.ReqOffset = ReqOffset - 2u;
                Dcm_PageBufferData.ThisPageSize = ResOffset - Offset - Dcm_PageBufferData.LastFilledSize;
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
            else
            {
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                ret = DCM_E_PENDING;
            }
        }
        if (ret == E_OK)
        {
            if (Dcm_PageBufferData.TotalSize
                > Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId].DcmDslProtocolMaximumResponseSize)
            {
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
    {
        /*Pdu length is bigger than buffer size */
        ret = E_NOT_OK;
    }
#endif
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x22 service>
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
Dcm_UDS0x22(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    uint16 RecDid;
    uint32 ResOffset;
    uint32 Offset;
    uint32 ReqOffset;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 DidNum;
    uint16 Index0;
    uint8 DidSessionSupportNum = 0;
    uint8 NoFindDidNum = 0;
    uint8 NoFindDidReadNum = 0;
#endif
    uint8 MsgCtrlId;
    uint8 MixPid = NONE_PID;
    uint8 noFindPidNum = 0;
    Std_ReturnType ret;
    Dcm_0x22Types Dcm_0x22Type;
    uint8 RangeDidCfgIndex;
    boolean RangeDidFlag;
    uint16 DidCfgIndex;
    boolean readDidSignalFlag;

#if (STD_OFF == DCM_DSP_DID_FUNC_ENABLED)
    /*NRC 0x31:request out of range*/
    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
    ret = E_NOT_OK;
#else
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
    /*calculate the number of required DID*/
    DidNum = (uint8)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen >> 1u);
    ret = DspInternalUDS0x22_DidNumbercheck(DidNum);
    if (E_NOT_OK == ret)
    {
        /*NRC = 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    } 
    else
    {
		ret = RTE_PreConditonCheck(Dcm_MsgCtrl[MsgCtrlId].SID,Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData);
		if (E_OK != ret)
		{
			*ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
			ret = E_NOT_OK;
		}
        /*get the runtime datum index*/
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
        SchM_Enter_Dcm(Dcm_PageBufferData);
        if (0u == Dcm_PageBufferData.PageIndex)
        {
            Dcm_PageBufferData.PageTxOK = FALSE;
#endif
            SchM_Enter_Dcm(Dcm_Channel);
            Dcm_Channel[Offset] = 0x62; /*response SID*/
            SchM_Exit_Dcm(Dcm_Channel);
            ResOffset = Offset + 1u;
            ReqOffset = 1;
            Index0 = 0u;
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
            Dcm_PageBufferData.LastFilled = TRUE;
        }
        else
        {
            if (Dcm_PageBufferData.PageTxOK != TRUE)
            {
                Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                ret = DCM_E_PENDING;
            }
            Index0 = Dcm_PageBufferData.IloopOne;
            ReqOffset = Dcm_PageBufferData.ReqOffset;
            ResOffset = Offset;
            Dcm_PageBufferData.PageTxOK = FALSE;
            Dcm_PageBufferData.LastFilled = TRUE;
        }
        SchM_Exit_Dcm(Dcm_PageBufferData);
#endif
        if ((OpStatus != DCM_PENDING) && (E_OK == ret))
        {
            ret = Dcm_Uds0x22ServiceConditonCheck(ProtocolCtrlId, ErrorCode);
        }
    }
    if (E_OK == ret)
    {
        for (; (Index0 < DidNum) && ((E_OK == ret) || (DCM_E_PENDING == ret))
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
               && ((Dcm_PageBufferData.LastFilled == TRUE) || (Dcm_PageBufferData.TotalSize == 0UL))
#endif
                 ;
             Index0++)
        {
            RecDid = (uint16)(((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[ReqOffset]) << 8u)
                     | ((uint16)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[ReqOffset + 1u]));
            ReqOffset = ReqOffset + 2u;
#if (DCM_DSP_PID_FUNC_ENABLED == STD_ON)
            if ((RecDid >= 0xF400u) && (RecDid <= 0xF8FFu))
            {
                Dcm_0x22Type.RecDid = RecDid;
                Dcm_0x22Type.MixPid = &MixPid;
                Dcm_0x22Type.noFindPidNum = &noFindPidNum;
                Dcm_0x22Type.ResOffset = &ResOffset;
                DidSessionSupportNum++;
                ret = DspInternalUDS0x22_ObdDidDeal(ProtocolCtrlId, &Dcm_0x22Type, ErrorCode);
            }
#endif
            if (((MixPid == NEED_CALL_UDS_API) || (MixPid == NONE_PID)) && ((E_OK == ret) || (DCM_E_PENDING == ret)))
            {
                Dcm_0x22Type.RecDid = RecDid;
                Dcm_0x22Type.NoFindDidReadNum = &NoFindDidReadNum;
                Dcm_0x22Type.DidSessionSupportNum = &DidSessionSupportNum;
                Dcm_0x22Type.NoFindDidNum = &NoFindDidNum;
                Dcm_0x22Type.ResOffset = &ResOffset;
                Dcm_0x22Type.pRangeDidCfgIndex = &RangeDidCfgIndex;
                Dcm_0x22Type.pDidCfgIndex = &DidCfgIndex;
                Dcm_0x22Type.pRangeDidFlag = &RangeDidFlag;
                Dcm_0x22Type.readDidSignalFlag = &readDidSignalFlag;
                ret = DspInternalUDS0x22_NonObdDidDeal(OpStatus, ProtocolCtrlId, &Dcm_0x22Type, ErrorCode);
            }
            /*if the requested DID reading is not completed, the subsequent DID reading is terminated*/
            if ((OpStatus == DCM_PENDING) && (DCM_E_PENDING == ret))
            {
                break;
            }
        }
        if (((NoFindDidNum == DidNum) || (NoFindDidReadNum == DidNum) || (noFindPidNum == DidNum)
             || (DidSessionSupportNum == 0u))
            && (E_OK == ret))
        {
            /*if the required DID is not found in DcmDspDid,send NRC 0x31*/
            /*at least one DID is supported in the active session,not then send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
    }

    if (E_OK == ret)
    {
        /* check tx data length */
        ret = Dcm_UDS0x22_CheckTxLength(
            ProtocolCtrlId,
#if (TRUE == DCM_PAGEDBUFFER_ENABLED)
            Index0,
            ReqOffset,
#endif
            ResOffset);
        if (E_NOT_OK == ret)
        {
            /*Pdu length is bigger than Page buffer max size */
            *ErrorCode = DCM_E_RESPONSETOOLONG;
        }
        else
        {
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = (Dcm_MsgLenType)ResOffset - Offset;
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = (Dcm_MsgLenType)ResOffset - Offset;
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            DsdInternal_ProcessingDone(ProtocolCtrlId);
        }
    }
#endif
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
