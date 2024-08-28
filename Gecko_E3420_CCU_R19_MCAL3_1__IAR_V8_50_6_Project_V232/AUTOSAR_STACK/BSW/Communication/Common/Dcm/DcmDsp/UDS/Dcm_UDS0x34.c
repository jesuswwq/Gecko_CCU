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
     UDS: RequestDownload (34 hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X34_ENABLED)
typedef struct
{
    uint32 MemoryAddress;
    uint32 Memorysize;
} Dcm_0x34Types;
/******************************/

/*************************************************************************/
/*
 * Brief               <UDS  0x34 service Memory Read Session Check>
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
static FUNC(Std_ReturnType, DCM_CODE) Dcm_0x34MemorySessionCheck(uint8 MemoryIdInfoIndex, uint8 MemoryRangeInfoIndex)
{
    uint8 index;
    Std_ReturnType ret = E_NOT_OK;
    P2CONST(Dcm_DspWriteMemoryRangeInfoType, AUTOMATIC, DCM_VAR_NOINIT)
    pDcmDspWriteMemoryRangeInfo = &(Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfo[MemoryIdInfoIndex]
                                        .DcmDspWriteMemoryRangeInfo[MemoryRangeInfoIndex]);

    if (pDcmDspWriteMemoryRangeInfo->DcmDspWriteMemoryRangeSessionLevelRefNum != 0u)
    {
        for (index = 0; index < pDcmDspWriteMemoryRangeInfo->DcmDspWriteMemoryRangeSessionLevelRefNum; index++)
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

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_0x34MemorySecurityCheck(uint8 MemoryIdInfoIndex, uint8 MemoryRangeInfoIndex)
{
    uint8 index;
    Std_ReturnType ret = E_NOT_OK;
    P2CONST(Dcm_DspWriteMemoryRangeInfoType, AUTOMATIC, DCM_VAR_NOINIT)
    pDcmDspWriteMemoryRangeInfo;

    pDcmDspWriteMemoryRangeInfo = &(Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfo[MemoryIdInfoIndex]
                                        .DcmDspWriteMemoryRangeInfo[MemoryRangeInfoIndex]);
    if (pDcmDspWriteMemoryRangeInfo->DcmDspWriteMemorySecurityLevelRefNum != 0u)
    {
        for (index = 0;
             (index < pDcmDspWriteMemoryRangeInfo->DcmDspWriteMemorySecurityLevelRefNum) && (E_NOT_OK == ret);
             index++)
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

/******************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_0x34MemoryRangeCheck(
    Dcm_0x34Types* Dcm_0x34Type,
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
                    if ((pDcmDspWriteMemoryRangeInfo->DcmDspWriteMemoryRangeLow <= Dcm_0x34Type->MemoryAddress)
                        && (pDcmDspWriteMemoryRangeInfo->DcmDspWriteMemoryRangeHigh
                            >= (Dcm_0x34Type->MemoryAddress + Dcm_0x34Type->Memorysize - 1u)))
                    {
                        *MemoryIdInfoIndex = IdInfoIndex;
                        *MemoryRangeInfoIndex = RangeInfoIndex;
                        *MemoryAddressMatchNum += 1u;
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

/***************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x34ServiceConditionCheck(
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint8 AddressAndLengthFormatIdentifier;
    uint8 DataFormatIdentifier;

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_REQUEST_DOWNLOAD);
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
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_REQUEST_DOWNLOAD);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif
    /*min-length check*/
    if ((E_OK == ret) && (DCM_UDS0X34_REQ_DATA_MINLENGTH > Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen))
    {
        /*the min length of message is not correct,send NRC 0x13*/
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
        /*if the required protocol is configured,get the index of runtime datum*/
        AddressAndLengthFormatIdentifier = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2];
        ret = DsdInternal_ServiceAddressAndLengthFormatIdentifierCheck(AddressAndLengthFormatIdentifier);
        if (E_NOT_OK == ret)
        {
            /*the processing is not successful,send NRC 0x31 */
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    if (E_OK == ret)
    {
        DataFormatIdentifier = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1];
        ret = Dcm_DataFormatIdentifierCheck(DataFormatIdentifier);
        if (E_NOT_OK == ret)
        {
            /*the processing is not successful,send NRC 0x31 */
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*******************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE)
Dcm_UDS0x34(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 MsgCtrlId;
    Std_ReturnType ret;
    uint8 AddressAndLengthFormatIdentifier;
    uint32 MemoryAddress = 0u;
    uint32 Memorysize = 0u;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint32 Offset;
    uint8 MemoryIdInfoIndex = 0u;
    uint8 MemoryRangeInfoIndex = 0u;
    uint8 MemoryAddressSize;
    uint8 MemoryLengthSize;
    uint8 index;
    uint8 MemoryAddressMatchNum = 0;
    uint8 DataFormatIdentifier;
    uint32 BlockLength = 0;
    Dcm_0x34Types Dcm_0x34Type;

    /*if the required protocol is configured,get the index of runtime datum*/
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    ret = Dcm_Uds0x34ServiceConditionCheck(ProtocolCtrlId, ErrorCode);

    if (E_OK == ret)
    {
        AddressAndLengthFormatIdentifier = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2];
        MemoryAddressSize = AddressAndLengthFormatIdentifier & 0x0Fu;
        MemoryLengthSize = (AddressAndLengthFormatIdentifier & 0xF0u) >> 4u;
        /*total length check*/
        if ((Dcm_MsgLenType)((Dcm_MsgLenType)3u + MemoryAddressSize + MemoryLengthSize)
            != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
        {
            /*the length of message is not correct,send NRC 0x13*/
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            ret = E_NOT_OK;
        }
    }

    if (E_OK == ret)
    {
        /*caculate the MemoryAddress of the request message*/
        for (index = 0u; index < MemoryAddressSize; index++)
        {
            MemoryAddress = MemoryAddress << 8u;
            MemoryAddress = MemoryAddress | (uint32)(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u + index]);
        }

        for (index = 0u; index < MemoryLengthSize; index++)
        {
            Memorysize = Memorysize << 8u;
            Memorysize =
                Memorysize | (uint32)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u + MemoryAddressSize + index];
        }
        /*MemoryAddress Range Check*/
        Dcm_0x34Type.MemoryAddress = MemoryAddress;
        Dcm_0x34Type.Memorysize = Memorysize;
        ret =
            Dcm_0x34MemoryRangeCheck(&Dcm_0x34Type, &MemoryIdInfoIndex, &MemoryRangeInfoIndex, &MemoryAddressMatchNum);
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
        ret = Dcm_0x34MemorySessionCheck(MemoryIdInfoIndex, MemoryRangeInfoIndex);
        if (E_NOT_OK == ret)
        {
            /*security check not ok for requested memory interval,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
        }
    }

    if (E_OK == ret)
    {
        /*MemoryAddress Security Accsess Check*/
        ret = Dcm_0x34MemorySecurityCheck(MemoryIdInfoIndex, MemoryRangeInfoIndex);
        if (E_NOT_OK == ret)
        {
            /*security check not ok for requested memory interval,send NRC 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
    if (E_OK == ret)
    {
        /*check program status*/
        if (Dcm_DspProgram.Status != DCM_UDS0X36_INIT)
        {
            /*send NRC 0x22*/
            *ErrorCode = DCM_E_CONDITIONSNOTCORRECT;
            ret = E_NOT_OK;
        }
    }
    if (E_OK == ret)
    {
        DataFormatIdentifier = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1];
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
        ret = Dcm_ProcessRequestDownload(
            OpStatus,
            DataFormatIdentifier,
            MemoryAddress,
            Memorysize,
            &BlockLength,
            ErrorCode);
        if (DCM_E_PENDING == ret)
        {
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
        }
        if (BlockLength
            > Dcm_DslCfg
                  .pDcmChannelCfg[Dcm_ChannelCtrl[Dcm_MsgCtrl[MsgCtrlId].Dcm_RxCtrlChannelIndex].Dcm_ChannelCfgIndex]
                  .Dcm_DslBufferSize)
        {
#if (STD_ON == DCM_DEV_ERROR_DETECT)
            /*If the function call Xxx_ProcessRequestDownload returns
             * a requested buffer length larger than the supported
             * buffer length of the current protocol connection,
             * the Dcm shall report the Det error DCM_E_INTERFACE_BUFFER_OVERFLOW.*/
            DCM_DET_REPORTERROR(DCM_MAIN_FUNCTION_ID, DCM_E_INTERFACE_BUFFER_OVERFLOW);
#endif
        }
    }

    /* check tx data length */
    if ((E_OK == ret) && ((6u) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize)))
    {
        /*Pdu length is bigger than buffer size */
        *ErrorCode = DCM_E_RESPONSETOOLONG;
        ret = E_NOT_OK;
    }

    if (E_OK == ret)
    {
        SchM_Enter_Dcm(Dcm_DspProgram);
        /* get address */
        Dcm_DspProgram.address = MemoryAddress;
        /* set index to 0, for service 0x36 */
        Dcm_DspProgram.blockId = 0x00;
        /* set 0x36 service status to DCM_UDS0X36_TO_DOWNLOAD*/
        Dcm_DspProgram.Status = DCM_UDS0X36_TO_DOWNLOAD;
        /*memory the MemoryIdInfoIndex*/
        Dcm_DspProgram.MemoryIdInfoIndex = MemoryIdInfoIndex;
        /*memory one block size*/
        Dcm_DspProgram.BlockLength = BlockLength;
        Dcm_DspProgram.MemorySize = Memorysize;
        Dcm_DspProgram.FirstFlag = TRUE;
        SchM_Exit_Dcm(Dcm_DspProgram);
        /*the processing is successful,assemble positive response*/
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x74;
        /*response SID*/
        Dcm_Channel[Offset + 1u] = 0x40;
        /*lengthFormatIdentifier*/
        Dcm_Channel[Offset + 2u] = (uint8)(BlockLength >> (uint8)24);
        /*maxNumberOfBlockLength*/
        Dcm_Channel[Offset + 3u] = (uint8)(BlockLength >> (uint8)16);
        /*maxNumberOfBlockLength*/
        Dcm_Channel[Offset + 4u] = (uint8)(BlockLength >> (uint8)8);
        /*maxNumberOfBlockLength*/
        Dcm_Channel[Offset + 5u] = (uint8)BlockLength;
        /*maxNumberOfBlockLength*/
        SchM_Exit_Dcm(Dcm_Channel);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = 6u;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = 6u;
        Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
    }
    else if (E_NOT_OK == ret)
    {
        DslInternal_InitDspProgramInfo();
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
