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

#if (STD_ON == DCM_UDS_SERVICE0X3D_ENABLED)
typedef struct
{
    uint32 MemoryAddress;
    uint32 Memorysize;
} Dcm_0x3DTypes;
/****************************************************************
             UDS:WriteMemoryByAddress (3D hex) service
 ***************************************************************/
/******************************/
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
static FUNC(Std_ReturnType, DCM_CODE)
    Dcm_0x3DMemoryWriteSecurityCheck(uint8 MemoryIdInfoIndex, uint8 MemoryRangeInfoIndex)
{
    uint8 index;
    Std_ReturnType ret = E_NOT_OK;
    P2CONST(Dcm_DspWriteMemoryRangeInfoType, AUTOMATIC, DCM_VAR_NOINIT)
    pDcmDspWriteMemoryRangeInfo;

    pDcmDspWriteMemoryRangeInfo = &(Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfo[MemoryIdInfoIndex]
                                        .DcmDspWriteMemoryRangeInfo[MemoryRangeInfoIndex]);
    if (pDcmDspWriteMemoryRangeInfo->DcmDspWriteMemorySecurityLevelRefNum != 0u)
    {
        for (index = 0; (index < pDcmDspWriteMemoryRangeInfo->DcmDspWriteMemorySecurityLevelRefNum); index++)
        {
            if (Dcm_MkCtrl.Dcm_ActiveSec == pDcmDspWriteMemoryRangeInfo->pDcmDspWriteMemorySecurityLevelRow[index])
            {
                ret = E_OK;
            }
        }
    }
    else
    {
        ret = E_OK;
    }
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
/******************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE)
    Dcm_0x3DMemoryWriteSessionCheck(uint8 MemoryIdInfoIndex, uint8 MemoryRangeInfoIndex)
{
    uint8 index;
    Std_ReturnType ret = E_NOT_OK;
    P2CONST(Dcm_DspWriteMemoryRangeInfoType, AUTOMATIC, DCM_VAR_NOINIT)
    pDcmDspWriteMemoryRangeInfo;

    pDcmDspWriteMemoryRangeInfo = &(Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfo[MemoryIdInfoIndex]
                                        .DcmDspWriteMemoryRangeInfo[MemoryRangeInfoIndex]);
    if (pDcmDspWriteMemoryRangeInfo->DcmDspWriteMemoryRangeSessionLevelRefNum != 0u)
    {
        for (index = 0; (index < pDcmDspWriteMemoryRangeInfo->DcmDspWriteMemoryRangeSessionLevelRefNum); index++)
        {
            if (Dcm_MkCtrl.Dcm_ActiveSes == pDcmDspWriteMemoryRangeInfo->pDcmDspWriteMemoryRangeSessionLevelRow[index])
            {
                ret = E_OK;
            }
        }
    }
    else
    {
        ret = E_OK;
    }
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
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x3DServiceConditionCheck(
    uint8 ProtocolCtrlId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, DCM_VAR) MemoryAddress,
    P2VAR(uint32, AUTOMATIC, DCM_VAR) Memorysize,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */                              /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint8 AddressAndLengthFormatIdentifier;
    uint8 MemoryAddressSize;
    uint8 MemoryLengthSize;
    uint8 index;

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_WIRTE_DATA_BY_MEMORYADDRESS);
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
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_WIRTE_DATA_BY_MEMORYADDRESS);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif
    /*min-length check*/
    if ((E_OK == ret) && (DCM_UDS0X3D_REQ_DATA_MINLENGTH > Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen))
    {
        /*the length of message is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }

    if (E_OK == ret)
    {
        AddressAndLengthFormatIdentifier = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1];
        ret = DsdInternal_ServiceAddressAndLengthFormatIdentifierCheck(AddressAndLengthFormatIdentifier);
        if (E_NOT_OK == ret)
        {
            /*the processing is not successful,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    if (E_OK == ret)
    {
        MemoryAddressSize = AddressAndLengthFormatIdentifier & 0x0Fu;
        MemoryLengthSize = (AddressAndLengthFormatIdentifier & 0xF0u) >> 4u;
        /*caculate the MemoryAddress of the request message*/
        for (index = 0u; index < MemoryAddressSize; index++)
        {
            *MemoryAddress = *MemoryAddress << 8u;
            *MemoryAddress = *MemoryAddress | (uint32)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u + index]);
        }
        for (index = 0u; index < MemoryLengthSize; index++)
        {
            *Memorysize = *Memorysize << 8u;
            *Memorysize =
                *Memorysize | (uint32)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u + MemoryAddressSize + index]);
        }
        /*total length check*/
        if ((2UL + (uint32)MemoryAddressSize + (uint32)MemoryLengthSize + *Memorysize)
            != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
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
/*******************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_0x3DWriteMemoryRangeCheck(
    Dcm_0x3DTypes* Dcm_0x3DType,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) MemoryIdInfoIndex,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) MemoryRangeInfoIndex,
    P2VAR(uint8, AUTOMATIC, AUTOMATIC) MemoryAddressMatchNum)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint8 IdInfoIndex;
    uint8 RangeInfoIndex;
    Std_ReturnType ret = E_NOT_OK;
    P2CONST(Dcm_DspWriteMemoryRangeInfoType, AUTOMATIC, DCM_VAR_NOINIT)
    pDcmDspWriteMemoryRangeInfo;
    P2CONST(Dcm_DspMemoryIdInfoType, AUTOMATIC, DCM_VAR_NOINIT)
    pDcmDspMemoryIdInfo;

    for (IdInfoIndex = 0u; IdInfoIndex < Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfoNum; IdInfoIndex++)
    {
        pDcmDspMemoryIdInfo = &(Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfo[IdInfoIndex]);
        if (pDcmDspMemoryIdInfo != NULL_PTR)
        {
            for (RangeInfoIndex = 0; RangeInfoIndex < pDcmDspMemoryIdInfo->DcmDspWriteMemoryRangeInfoNum;
                 RangeInfoIndex++)
            {
                pDcmDspWriteMemoryRangeInfo = &(pDcmDspMemoryIdInfo->DcmDspWriteMemoryRangeInfo[RangeInfoIndex]);
                if (pDcmDspWriteMemoryRangeInfo != NULL_PTR)
                {
                    if ((pDcmDspWriteMemoryRangeInfo->DcmDspWriteMemoryRangeLow <= Dcm_0x3DType->MemoryAddress)
                        && (pDcmDspWriteMemoryRangeInfo->DcmDspWriteMemoryRangeHigh
                            >= (Dcm_0x3DType->MemoryAddress + Dcm_0x3DType->Memorysize - 1u)))
                    {
                        *MemoryIdInfoIndex = IdInfoIndex;
                        *MemoryRangeInfoIndex = RangeInfoIndex;
                        (*MemoryAddressMatchNum) += 1u;
                        ret = E_OK;
                    }
                }
            }
        }
    }
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
/*******************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE)
/* PRQA S 3432,1532++ */ /* MISRA Rule 20.7,8.7 */
Dcm_UDS0x3D(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432,1532-- */ /* MISRA Rule 20.7,8.7 */
{
    uint8 MsgCtrlId;
    Std_ReturnType ret;
    uint8 AddressAndLengthFormatIdentifier;
    uint32 MemoryAddress = 0u;
    uint32 Memorysize = 0u;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint32 Offset;
    uint8* DCM_MemoryData;
    uint8 MemoryAddressSize;
    uint8 MemoryLengthSize;
    uint8 index;
    uint8 MemoryIdInfoIndex = 0u;
    uint8 MemoryRangeInfoIndex = 0u;
    uint8 MemoryAddressMatchNum = 0;
    uint8 MemoryIdentifier;
    Dcm_0x3DTypes Dcm_0x3DType;

    /*if the required protocol is configured,get the index of runtime datum*/
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    AddressAndLengthFormatIdentifier = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1];
    ret = Dcm_Uds0x3DServiceConditionCheck(ProtocolCtrlId, &MemoryAddress, &Memorysize, ErrorCode);

    if (E_OK == ret)
    {
        MemoryAddressSize = AddressAndLengthFormatIdentifier & 0x0Fu;
        MemoryLengthSize = (AddressAndLengthFormatIdentifier & 0xF0u) >> 4u;
        /*MemoryAddress Range Check*/
        Dcm_0x3DType.MemoryAddress = MemoryAddress;
        Dcm_0x3DType.Memorysize = Memorysize;
        ret = DsdInternal_0x3DWriteMemoryRangeCheck(
            &Dcm_0x3DType,
            &MemoryIdInfoIndex,
            &MemoryRangeInfoIndex,
            &MemoryAddressMatchNum);
        if ((E_NOT_OK == ret) || (MemoryAddressMatchNum > 1u) || (Memorysize == 0u))
        {
            /*different MemoryIdValue compare to the request memoryAddress,send NRC 0x31*/
            /*memoryAddress is not inside the allowed memory ranges,send NRC 0x31 */
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
    }
    if (E_OK == ret)
    {
        /*MemoryAddress session Accsess Check*/
        ret = Dcm_0x3DMemoryWriteSessionCheck(MemoryIdInfoIndex, MemoryRangeInfoIndex);
        if (E_NOT_OK == ret)
        {
            /*session check not ok for requested memory interval,send NRC 0x33*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    if (E_OK == ret)
    {
        /*MemoryAddress Security Accsess Check*/
        ret = Dcm_0x3DMemoryWriteSecurityCheck(MemoryIdInfoIndex, MemoryRangeInfoIndex);
        if (E_NOT_OK == ret)
        {
            /*security check not ok for requested memory interval,send NRC 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }

    if (E_OK == ret)
    {
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
        DCM_MemoryData = &(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u + MemoryAddressSize + MemoryLengthSize]);
        MemoryIdentifier = Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfo[MemoryIdInfoIndex].DcmDspMemoryIdValue;
        ret = Dcm_WriteMemory(OpStatus, MemoryIdentifier, MemoryAddress, Memorysize, DCM_MemoryData, ErrorCode);

        if (DCM_WRITE_FAILED == ret)
        {
            ret = E_NOT_OK;
        }
#if (STD_ON == DCM_DSLDIAGRESP_FORCERESPENDEN)
        else if (DCM_WRITE_FORCE_RCRRP == ret)
        {
            /*the processing is pending,send NRC 0x78 */
            DsdInternal_SetNrc(ProtocolCtrlId, DCM_E_RESPONSE_PENDING);
            DsdInternal_ProcessingDone(ProtocolCtrlId);
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].Dcm_Ret = DCM_E_FORCE_RCRRP;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
        }
#endif
        else if (DCM_WRITE_PENDING == ret)
        {
            ret = DCM_E_PENDING;
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
        }
        else
        {
        }
    }
    /* check tx data length */
    if ((E_OK == ret)
        && (((uint32)((uint32)2 + (uint32)MemoryAddressSize + (uint32)MemoryLengthSize))
            > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize)))
    {
        /*Pdu length is bigger than buffer size */
        *ErrorCode = DCM_E_RESPONSETOOLONG;
        ret = E_NOT_OK;
    }

    if (E_OK == ret)
    {
        /*the processing is successful,assemble positive response*/
        SchM_Enter_Dcm(Dcm_Channel);
        for (index = 0; index < (MemoryAddressSize + MemoryLengthSize); index++)
        {
            Dcm_Channel[Offset + 2u + (uint32)index] = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u + index];
        }
        Dcm_Channel[Offset] = 0x7D; /*response SID*/
        Dcm_Channel[Offset + 1u] = AddressAndLengthFormatIdentifier;
        /*response AddressAndLengthFormatIdentifier*/
        SchM_Exit_Dcm(Dcm_Channel);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = (uint32)((uint32)2 + MemoryAddressSize + MemoryLengthSize);
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = (uint32)((uint32)2 + MemoryAddressSize + MemoryLengthSize);
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
