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
         UDS:DynamicallyDefineDataIdentifier  (2C hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X2C_ENABLED)

#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
VAR(Dcm_DDDidTypes, DCM_VAR_NOINIT) Dcm_DDDid[DCM_DSP_DDDID_MAX_NUMBER];
#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
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
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
static Std_ReturnType DspInternalUDS0x2C_DidCheck(uint16 RecDid, P2VAR(uint8, AUTOMATIC, AUTOMATIC) pDidCfgIndex)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint8 Index;
    Std_ReturnType ret = E_NOT_OK;

    if ((RecDid >= 0xF200u) && (RecDid <= 0xF3FFu))
    {
        /*find the corresponding DID in configuration*/
        for (Index = 0; (Index < Dcm_DspCfg.DcmDspDidNum) && (E_NOT_OK == ret); Index++)
        {
            /*single did check*/
            if ((RecDid == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId)
                && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed)
                && (Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidInfoIndex]
                        .DcmDspDidDynamicallyDefined
                    == TRUE)
                && (Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidInfoIndex].DcmDspDDDIDMaxElements
                    > 0u))
            {
                (*pDidCfgIndex) = Index;
                ret = E_OK;
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

#if ((STD_ON == DCM_DSP_DID_FUNC_ENABLED) && (DCM_DSP_DDDID_MAX_NUMBER > 0u))
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
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
static Std_ReturnType DspInternalUDS0x2C_SourceDidCheck(uint16 RecDid, P2VAR(uint8, AUTOMATIC, AUTOMATIC) pDidCfgIndex)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint8 Index;
    Std_ReturnType ret = E_NOT_OK;

    /*find the corresponding DID in configuration*/
    for (Index = 0; (Index < Dcm_DspCfg.DcmDspDidNum) && (E_NOT_OK == ret); Index++)
    {
        /*single did check*/
        if ((RecDid == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId)
            && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed))
        {
            (*pDidCfgIndex) = Index;
            ret = E_OK;
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
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
static Std_ReturnType DspInternalUDS0x2C_SourceDidLength(uint8 DidCfgIndex, P2VAR(uint16, AUTOMATIC, AUTOMATIC) Length)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
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
                ret = E_NOT_OK;
            }
            else
            {
                ret = pDspDidData->DcmDspDataReadDataLengthFnc(DCM_INITIAL, &Size);
            }
        }
        else
        {
            /*DidDataSize is fixed*/
            Size = ((pDspDidData->DcmDspDataSize + 7u) >> 3u);
        }
        (*Length) += Size;
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
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x2CServiceConditionCheck(
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */                                         /* MISRA Rule 2.2 */
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint8 Subfunction;
    uint8 addressAndLengthFormatIdentifier;
    uint8 memoryAddressByteLength;
    uint8 memorySizeByteLength;

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_DYNAMICALLY_DEFINE_DATA_IDENTIFER);
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
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_DYNAMICALLY_DEFINE_DATA_IDENTIFER);
        if (E_NOT_OK == ret)
        {
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif
    /*check the massage length*/
    if ((E_OK == ret)
        && (Dcm_MsgCtrl[Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex].MsgContext.ReqDataLen
            < DCM_UDS_REQ_DATA_MINLENGTH))
    {
        /*the length of massage is not correct,send NRC 0x13*/
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
    if (E_OK == ret)
    {
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
        ret = DsdInternal_SubSesCheck(ProtocolCtrlId, SID_DYNAMICALLY_DEFINE_DATA_IDENTIFER);
        if (E_NOT_OK == ret)
        {
            /*the current session does not support the request sub service,send NRC = 0x7E*/
            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
        }
    }
#endif /* STD_ON == DCM_SESSION_FUNC_ENABLED */
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*security check,check whether the current security supports the request service*/
        ret = DsdInternal_SubSecurityCheck(ProtocolCtrlId, SID_DYNAMICALLY_DEFINE_DATA_IDENTIFER);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif /* STD_ON == DCM_SECURITY_FUNC_ENABLED */
    if (E_OK == ret)
    {
        Subfunction = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1u];
        if (Subfunction == DCM_UDS0X2C_01_DDBYDID)
        {
            /*check the massage length*/
            if ((Dcm_MsgCtrl[Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex].MsgContext.ReqDataLen
                 < DCM_UDS0X2C_SUBFUNC0X01_REQ_DATA_MINLENGTH)
                || ((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen % 4u) != 0u))
            {
                /*the length of massage is not correct,send NRC 0x13*/
                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                ret = E_NOT_OK;
            }
        }
        else if (Subfunction == DCM_UDS0X2C_02_DDBYMEMORY)
        {
            if (Dcm_MsgCtrl[Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex].MsgContext.ReqDataLen
                < DCM_UDS0X2C_SUBFUNC0X02_REQ_DATA_MINLENGTH)
            {
                /*the length of massage is not correct,send NRC 0x13*/
                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                ret = E_NOT_OK;
            }
            else
            {
                addressAndLengthFormatIdentifier = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u];
                ret = DsdInternal_ServiceAddressAndLengthFormatIdentifierCheck(addressAndLengthFormatIdentifier);
                if (E_NOT_OK == ret)
                {
                    /*the processing is not successful,send NRC 0x31 */
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    ret = E_NOT_OK;
                }
                else
                {
                    memoryAddressByteLength = addressAndLengthFormatIdentifier & 0x0Fu;
                    memorySizeByteLength = (addressAndLengthFormatIdentifier & 0xF0u) >> 4u;
                    /*check the massage length*/
                    if ((addressAndLengthFormatIdentifier == 0u)
                        || (((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen - 5UL)
                             % ((uint32)((uint32)memorySizeByteLength + memoryAddressByteLength)))
                            != 0UL))
                    {
                        /*the length of massage is not correct,send NRC 0x13*/
                        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                        ret = E_NOT_OK;
                    }
                }
            }
        }
        else if (Subfunction == DCM_UDS0X2C_03_CLEARDDDID)
        {
            /*check the massage length*/
            if ((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen != DCM_UDS0X2C_REQ_DATA_MINLENGTH)
                && (Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen != DCM_UDS0X2C_SUBFUNC0X03_REQ_DATA_MINLENGTH))
            {
                /*the length of massage is not correct,send NRC 0x13*/
                *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
                ret = E_NOT_OK;
            }
        }
        else
        {
            /*the sub-function of massage is not correct,send NRC 0x12*/
            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
            ret = E_NOT_OK;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
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
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x2CSubDeal_NoFind(
    uint8 ProtocolCtrlId,
    uint8 DidCfgIndex,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
    uint32 MemoryAddress;
    uint32 Memorysize;
    boolean Find = FALSE;
    uint8 iloop;
    uint8 index;
    uint8 Cnt;
    uint16 Length = 0;
    uint8 pDidCfgIndex = 0xFF;
    uint8 addressAndLengthFormatIdentifier;
    uint8 memoryAddressByteLength;
    uint8 memorySizeByteLength;
    uint8 RequestNum;
    uint32 TotalSize = 0;
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint8 Subfunction = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1u];
    uint16 RecDid = (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2]) << 8u)
                    | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3]);

    for (iloop = 0; (iloop < DCM_DSP_DDDID_MAX_NUMBER) && (Find == FALSE); iloop++)
    {
        if (0u == Dcm_DDDid[iloop].DDDid)
        {
            Find = TRUE;
        }
    }
    iloop--;
    if (Find == TRUE)
    {
        Dcm_DDDid[iloop].DDDid = RecDid;
        if (Subfunction == DCM_UDS0X2C_01_DDBYDID)
        {
            RequestNum = (uint8)((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen >> 2u) - 1UL);
            if ((Dcm_DDDid[iloop].DDDIDNumOfElements + RequestNum)
                > Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidInfoIndex]
                      .DcmDspDDDIDMaxElements)
            {
                /*over DcmDspDDDIDMaxElements,send NRC 0x31*/
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
            else
            {
                for (Cnt = 0u; (Cnt < RequestNum) && (ret == E_OK); Cnt++)
                {
                    Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements].Subfunction =
                        Subfunction;
                    RecDid =
                        (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u + (Cnt * (4u))]) << 8u)
                        | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[5u + (Cnt * (4u))]);
                    ret = DspInternalUDS0x2C_SourceDidCheck(RecDid, &pDidCfgIndex);
                    if (pDidCfgIndex != 0xFFu)
                    {
                        (void)DspInternalUDS0x2C_SourceDidLength(pDidCfgIndex, &Length);
                    }
                    if ((ret == E_NOT_OK)
                        || (Length
                            < (uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[6u + (Cnt * (4u))]
                                       + (uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[7u + (Cnt * (4u))] - 1u))
                        || (Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[6u + (Cnt * (4u))] == 0u))
                    {
                        /*Source Did not support,send NRC 0x31*/
                        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                        ret = E_NOT_OK;
                    }
                    else
                    {
                        MemoryAddress =
                            (uint32)(((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u + (Cnt * (4u))]) << 8u);
                        MemoryAddress =
                            MemoryAddress
                            | (uint32)(((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[5u + (Cnt * (4u))]));
                        MemoryAddress =
                            MemoryAddress
                            | (uint32)(((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[6u + (Cnt * (4u))] - 1u)
                                       << 16u);
                        Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements].Data =
                            MemoryAddress;
                        Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements].Size =
                            (uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[7u + (Cnt * (4u))];
                        TotalSize +=
                            Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements].Size;
                        if (((TotalSize > 7u) && (Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2] == 0xF2u))
                            || (Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements].Size
                                == 0u))
                        {
                            /*total Did size over 7,send NRC 0x31*/
                            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                            ret = E_NOT_OK;
                        }
                        else
                        {
                            Dcm_DDDid[iloop].DDDIDNumOfElements++;
                        }
                    }
                }
            }
        }
        else if (Subfunction == DCM_UDS0X2C_02_DDBYMEMORY)
        {
            addressAndLengthFormatIdentifier = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u];
            memoryAddressByteLength = addressAndLengthFormatIdentifier & 0x0Fu;
            memorySizeByteLength = (addressAndLengthFormatIdentifier & 0xF0u) >> 4u;
            RequestNum = (uint8)((uint8)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen - 5u)
                                 / (memorySizeByteLength + memoryAddressByteLength));
            if (((Dcm_DDDid[iloop].DDDIDNumOfElements + RequestNum)
                 > Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidInfoIndex]
                       .DcmDspDDDIDMaxElements)
                || (memorySizeByteLength == 0u))
            {
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
            else
            {
                for (Cnt = 0u; (Cnt < RequestNum) && (ret == E_OK); Cnt++)
                {
                    Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements].Subfunction =
                        Subfunction;
                    /*caculate the MemoryAddress of the request message*/
                    MemoryAddress = 0;
                    for (index = 0u; index < memoryAddressByteLength; index++)
                    {
                        MemoryAddress = MemoryAddress << 8u;
                        MemoryAddress =
                            MemoryAddress
                            | ((uint32)Dcm_MsgCtrl[MsgCtrlId]
                                   .MsgContext
                                   .pReqData[5u + index + (Cnt * (memorySizeByteLength + memoryAddressByteLength))]);
                    }
                    Memorysize = 0;
                    for (index = 0u; index < memorySizeByteLength; index++)
                    {
                        Memorysize = Memorysize << 8u;
                        Memorysize = Memorysize
                                     | ((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData
                                            [5u + memoryAddressByteLength + index
                                             + (Cnt * (memorySizeByteLength + memoryAddressByteLength))]);
                    }
                    Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements].Data =
                        MemoryAddress;
                    Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements].Size =
                        (uint16)Memorysize;
                    TotalSize += Memorysize;
                    if (((TotalSize > 7u) && (Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2] == 0xF2u))
                        || (Memorysize == 0u))
                    {
                        /*total Did size over 7,send NRC 0x31*/
                        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                        ret = E_NOT_OK;
                    }
                    else
                    {
                        Dcm_DDDid[iloop].DDDIDNumOfElements++;
                    }
                }
            }
        }
        else if (Subfunction == DCM_UDS0X2C_03_CLEARDDDID)
        {
            Dcm_DDDid[iloop].DDDid = 0u; /*clear DDDID*/
            Dcm_DDDid[iloop].DDDIDNumOfElements = 0;
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

#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
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
static FUNC(Std_ReturnType, DCM_CODE) Dcm_UDS0x2CSubDeal(
    uint8 ProtocolCtrlId,
    uint8 DidCfgIndex,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
    uint32 MemoryAddress;
    uint32 Memorysize;
    boolean Find = FALSE;
    uint8 iloop;
    uint8 index;
    uint8 Cnt;
    uint16 Length = 0;
    uint8 pDidCfgIndex = 0xFF;
    uint8 addressAndLengthFormatIdentifier;
    uint8 memoryAddressByteLength;
    uint8 memorySizeByteLength;
    uint8 RequestNum;
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint8 Subfunction = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1u];
    uint16 RecDid;
    uint32 TotalSize = 0;

    if (DidCfgIndex != 0xFFu)
    {
        RecDid = (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2]) << 8u)
                 | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3]);

        for (iloop = 0; (iloop < DCM_DSP_DDDID_MAX_NUMBER) && (Find == FALSE); iloop++)
        {
            if (RecDid == Dcm_DDDid[iloop].DDDid)
            {
                Find = TRUE;
            }
        }
        iloop--;
        if (Find == FALSE)
        {
            ret = Dcm_UDS0x2CSubDeal_NoFind(ProtocolCtrlId, DidCfgIndex, ErrorCode);
        }
        else
        {
            if (Subfunction == DCM_UDS0X2C_01_DDBYDID)
            {
                RequestNum = (uint8)((Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen >> 2u) - 1UL);
                if ((Dcm_DDDid[iloop].DDDIDNumOfElements + RequestNum)
                    > Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidInfoIndex]
                          .DcmDspDDDIDMaxElements)
                {
                    /*over DcmDspDDDIDMaxElements,send NRC 0x31*/
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    ret = E_NOT_OK;
                }
                else
                {
                    for (Cnt = 0u; Cnt < Dcm_DDDid[iloop].DDDIDNumOfElements; Cnt++)
                    {
                        TotalSize += Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Cnt].Size;
                    }
                    for (Cnt = 0u; (Cnt < RequestNum) && (ret == E_OK); Cnt++)
                    {
                        Dcm_DDDid[iloop]
                            .DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements]
                            .Subfunction = Subfunction;
                        RecDid =
                            (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u + (Cnt * (4u))])
                                     << 8u)
                            | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[5u + (Cnt * (4u))]);
                        ret = DspInternalUDS0x2C_SourceDidCheck(RecDid, &pDidCfgIndex);
                        if (pDidCfgIndex != 0xFFu)
                        {
                            (void)DspInternalUDS0x2C_SourceDidLength(pDidCfgIndex, &Length);
                        }
                        if ((ret == E_NOT_OK)
                            || (Length
                                < (uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[6u + (Cnt * (4u))]
                                           + (uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[7u + (Cnt * (4u))]
                                           - 1u))
                            || (Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[6u + (Cnt * (4u))] == 0u))
                        {
                            /*Source Did not support,send NRC 0x31*/
                            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                            ret = E_NOT_OK;
                        }
                        else
                        {
                            MemoryAddress =
                                (uint32)(((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u + (Cnt * (4u))]) << 8u);
                            MemoryAddress =
                                MemoryAddress
                                | (uint32)(((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[5u + (Cnt * (4u))]));
                            MemoryAddress =
                                MemoryAddress
                                | (uint32)(((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[6u + (Cnt * (4u))] - 1u)
                                           << 16u);
                            Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements].Data =
                                MemoryAddress;
                            Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements].Size =
                                (uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[7u + (Cnt * (4u))]);
                            TotalSize += Dcm_DDDid[iloop]
                                             .DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements]
                                             .Size;
                            if (((TotalSize > 7u) && (Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2] == 0xF2u))
                                || (Dcm_DDDid[iloop]
                                        .DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements]
                                        .Size
                                    == 0u))
                            {
                                /*total Did size over 7,send NRC 0x31*/
                                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                                ret = E_NOT_OK;
                            }
                            else
                            {
                                Dcm_DDDid[iloop].DDDIDNumOfElements++;
                            }
                        }
                    }
                }
            }
            else if (Subfunction == DCM_UDS0X2C_02_DDBYMEMORY)
            {
                addressAndLengthFormatIdentifier = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u];
                memoryAddressByteLength = addressAndLengthFormatIdentifier & 0x0Fu;
                memorySizeByteLength = (addressAndLengthFormatIdentifier & 0xF0u) >> 4u;
                RequestNum = (uint8)((uint8)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen - 5u)
                                     / (memorySizeByteLength + memoryAddressByteLength));
                if (((Dcm_DDDid[iloop].DDDIDNumOfElements + RequestNum)
                     > Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidInfoIndex]
                           .DcmDspDDDIDMaxElements)
                    || (memorySizeByteLength == 0u))
                {
                    *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                    ret = E_NOT_OK;
                }
                else
                {
                    for (Cnt = 0u; Cnt < Dcm_DDDid[iloop].DDDIDNumOfElements; Cnt++)
                    {
                        TotalSize += Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Cnt].Size;
                    }
                    for (Cnt = 0u; (Cnt < RequestNum) && (ret == E_OK); Cnt++)
                    {
                        Dcm_DDDid[iloop]
                            .DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements]
                            .Subfunction = Subfunction;
                        /*caculate the MemoryAddress of the request message*/
                        MemoryAddress = 0;
                        for (index = 0u; index < memoryAddressByteLength; index++)
                        {
                            MemoryAddress = MemoryAddress << 8u;
                            MemoryAddress =
                                MemoryAddress
                                | (uint32)((
                                    (uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData
                                        [5u + index + (Cnt * (memorySizeByteLength + memoryAddressByteLength))]));
                        }
                        Memorysize = 0;
                        for (index = 0u; index < memorySizeByteLength; index++)
                        {
                            Memorysize = Memorysize << 8u;
                            Memorysize = Memorysize
                                         | (uint32)(((uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData
                                                         [5u + memoryAddressByteLength + index
                                                          + (Cnt * (memorySizeByteLength + memoryAddressByteLength))]));
                        }
                        Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements].Data =
                            MemoryAddress;
                        Dcm_DDDid[iloop].DcmDspAlternativeArgumentData[Dcm_DDDid[iloop].DDDIDNumOfElements].Size =
                            (uint16)Memorysize;
                        TotalSize += Memorysize;
                        if (((TotalSize > 7u) && (Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2] == 0xF2u))
                            || (Memorysize == 0u))
                        {
                            /*total Did size over 7,send NRC 0x31*/
                            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                            ret = E_NOT_OK;
                        }
                        else
                        {
                            Dcm_DDDid[iloop].DDDIDNumOfElements++;
                        }
                    }
                }
            }
            else if (Subfunction == DCM_UDS0X2C_03_CLEARDDDID)
            {
                Dcm_DDDid[iloop].DDDid = 0u; /*clear DDDID*/
                Dcm_DDDid[iloop].DDDIDNumOfElements = 0;
            }
            else
            {
                /*idle*/
            }
        }
    }
    else
    {
        if (Subfunction == DCM_UDS0X2C_03_CLEARDDDID)
        {
            for (iloop = 0; iloop < DCM_DSP_DDDID_MAX_NUMBER; iloop++)
            {
                Dcm_DDDid[iloop].DDDid = 0u; /*clear DDDID*/
                Dcm_DDDid[iloop].DDDIDNumOfElements = 0;
            }
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
#if (DCM_DDDID_STORAGE == STD_ON)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) Dcm_UDS0x2C_Init(void)
{
#if (NVM_ENABLE == STD_OFF)
    uint16 Index;
#endif
#if (DCM_DDDID_STORAGE == STD_ON)
#if (NVM_ENABLE == STD_ON)
    NvM_RequestResultType NvmRet;

    (void)NvM_GetErrorStatus(DCM_DDDID_STORAGE_BLOCKID, &NvmRet);
    if (NVM_REQ_OK == NvmRet)
    {
        (void)NvM_ReadBlock(DCM_DDDID_STORAGE_BLOCKID, (void*)&Dcm_DDDid);
    }
#else
#if (NVM_ENABLE == STD_ON)
    else
    {
#endif
        for (Index = 0; Index < DCM_DSP_DDDID_MAX_NUMBER; Index++)
        {
            Dcm_DDDid[Index].DDDid = 0;
            Dcm_DDDid[Index].DDDIDNumOfElements = 0;
        }
#if (NVM_ENABLE == STD_ON)
    }
#endif
#endif
#endif
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
FUNC(Std_ReturnType, DCM_CODE)
/* PRQA S 3432,1532++ */ /* MISRA Rule 20.7,8.7 */
Dcm_UDS0x2C(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432,1532-- */ /* MISRA Rule 20.7,8.7 */
{
#if (STD_ON == DCM_DSP_DID_FUNC_ENABLED)
    uint16 RecDid = 0;
    uint32 Offset;
    uint8 DidCfgIndex = 0xFF;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
#endif
    uint8 MsgCtrlId;
    Std_ReturnType ret;
    uint8 Subfunction;

    DCM_UNUSED(OpStatus);
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    Subfunction = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1u];
    ret = Dcm_Uds0x2CServiceConditionCheck(ProtocolCtrlId, ErrorCode);

#if (STD_OFF == DCM_DSP_DID_FUNC_ENABLED)
    /*NRC 0x31:request out of range*/
    if (E_OK == ret)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
#else
    if ((E_OK == ret) && (Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen > DCM_UDS0X2C_REQ_DATA_MINLENGTH))
    {
        /*get the required DID from request message*/
        RecDid = (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2]) << 8u)
                 | ((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3]);
        /*Determine if the DID is configured*/
        ret = DspInternalUDS0x2C_DidCheck(RecDid, &DidCfgIndex);
        if (E_NOT_OK == ret)
        {
            /*if not found,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }

#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
    if (E_OK == ret)
    {
        ret = Dcm_UDS0x2CSubDeal(ProtocolCtrlId, DidCfgIndex, ErrorCode);
    }
#else
    /*NRC 0x31:request out of range*/
    if (E_OK == ret)
    {
        *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
#endif

    if (E_OK == ret)
    {
        /*assemble and send positive response*/
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
        /* check tx data length */
        if ((4u) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
        {
            /*Pdu length is bigger than buffer size,ignore the request message */
            *ErrorCode = DCM_E_RESPONSETOOLONG;
            ret = E_NOT_OK;
        }
    }
    if (E_OK == ret)
    {
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x6C;
        Dcm_Channel[Offset + 1u] = Subfunction;
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        if (Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen > DCM_UDS0X2C_REQ_DATA_MINLENGTH)
        {
            Dcm_Channel[Offset + 2u] = (uint8)(RecDid >> 8u);
            Dcm_Channel[Offset + 3u] = (uint8)RecDid;
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = 4u;
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = 4u;
        }
        else
        {
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = 2u;
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = 2u;
        }
        SchM_Exit_Dcm(Dcm_Channel);
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
#if ((NVM_ENABLE == STD_ON) && ((DCM_DDDID_STORAGE == STD_ON) && (DCM_DSP_DDDID_MAX_NUMBER > 0u)))
        (void)NvM_WriteBlock(DCM_DDDID_STORAGE_BLOCKID, (void*)&Dcm_DDDid);
#endif
    }
#endif
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
