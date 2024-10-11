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
     UDS: RequestFileTransfer (38 hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X38_ENABLED)
typedef struct
{
    P2VAR(uint32, AUTOMATIC, DCM_VAR) BlockLength; /* PRQA S 3432 */                        /* MISRA Rule 20.7 */
    P2VAR(uint16, AUTOMATIC, DCM_VAR) fileSizeParameterLength; /* PRQA S 3432 */            /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_VAR) fileSizeUncompressedOrDirInfoLength; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_VAR) fileSizeCompressed; /* PRQA S 3432 */                  /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DCM_VAR) dataFormatIdentifier; /* PRQA S 3432 */                /* MISRA Rule 20.7 */
} Dcm_0x38Types;
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
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) Dcm_Uds0x38ServiceConditionCheck(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    Dcm_0x38Types* Dcm_0x38Type,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */                                         /* MISRA Rule 2.2 */
    uint8 MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    uint16 filePathAndNameLength;
    uint8 modeOfOperation;
    uint8* filePathAndName;
    uint16 ReqOffset;

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_REQUEST_FILE_TRANSFER);
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
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_REQUEST_FILE_TRANSFER);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif
    /*min-length check*/
    if ((E_OK == ret) && (DCM_UDS0X38_REQ_DATA_MINLENGTH > Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen))
    {
        /*the min length of message is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    {
        modeOfOperation = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1];
        if ((modeOfOperation < 0x01u) || (modeOfOperation > 0x05u))
        { /*the modeOfOperation is not correct,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
    }
    if (E_OK == ret)
    {
        filePathAndNameLength = (uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3u]
                                         | (uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2u] << 8u));
        filePathAndName = &(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4u]);
        ReqOffset = 4u + filePathAndNameLength;
        if ((modeOfOperation != 0x02u) && (modeOfOperation != 0x05u))
        {
            *Dcm_0x38Type->dataFormatIdentifier = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[ReqOffset];
            ReqOffset += 1u;
            if (modeOfOperation != 0x04u)
            {
                if (Dcm_DspCfg.DcmDspRequestFileTransfer != NULL_PTR)
                {
                    *Dcm_0x38Type->fileSizeParameterLength =
                        (uint16)Dcm_DspCfg.DcmDspRequestFileTransfer->DcmRequestFileTransferFileSizeParameterLength;
                }
                else
                {
                    *Dcm_0x38Type->fileSizeParameterLength =
                        (uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[ReqOffset];
                }
                ReqOffset += 1u;
                Dcm_0x38Type->fileSizeUncompressedOrDirInfoLength =
                    &(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[ReqOffset]);
                ReqOffset += *Dcm_0x38Type->fileSizeParameterLength;
                Dcm_0x38Type->fileSizeCompressed = &(Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[ReqOffset]);
                ReqOffset += *Dcm_0x38Type->fileSizeParameterLength;
            }
            else
            {
                if (Dcm_DspCfg.DcmDspRequestFileTransfer != NULL_PTR)
                {
                    *Dcm_0x38Type->fileSizeParameterLength =
                        (uint16)Dcm_DspCfg.DcmDspRequestFileTransfer->DcmRequestFileTransferFileSizeParameterLength;
                }
            }
        }
        else
        {
            if (Dcm_DspCfg.DcmDspRequestFileTransfer != NULL_PTR)
            {
                *Dcm_0x38Type->fileSizeParameterLength =
                    (uint16)Dcm_DspCfg.DcmDspRequestFileTransfer->DcmRequestFileTransferFileSizeParameterLength;
            }
        }
        if (ReqOffset != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
        { /*the length of message is not correct,send NRC 0x13*/
            *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
            ret = E_NOT_OK;
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
        ret = Dcm_ProcessRequestFileTransfer(
            OpStatus,
            modeOfOperation,
            *Dcm_0x38Type->fileSizeParameterLength,
            filePathAndName,
            *Dcm_0x38Type->dataFormatIdentifier,
            Dcm_0x38Type->fileSizeUncompressedOrDirInfoLength,
            Dcm_0x38Type->fileSizeCompressed,
            Dcm_0x38Type->BlockLength,
            ErrorCode);
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
static FUNC(void, DCM_CODE) Dcm_UDS0x38_Tx(uint8 ProtocolCtrlId, uint32 ResOffset, uint32 BlockLength)
{
    uint8 MsgCtrlId;
    uint8 modeOfOperation;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint32 Offset;

    /*if the required protocol is configured,get the index of runtime datum*/
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
    Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
    modeOfOperation = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1];

    SchM_Enter_Dcm(Dcm_DspProgram); /* get address */
    Dcm_DspProgram.address = 0UL;   /* set index to 0, for service 0x36 */
    Dcm_DspProgram.blockId = 0x00;  /* set 0x36 service status to DCM_UDS0X36_TO_UPLOAD*/
    switch (modeOfOperation)
    {
    case 0x01u:
        Dcm_DspProgram.Status = DCM_UDS0X38_0x01;
        break;
    case 0x02u:
        Dcm_DspProgram.Status = DCM_UDS0X38_0x02;
        break;
    case 0x03u:
        Dcm_DspProgram.Status = DCM_UDS0X38_0x03;
        break;
    case 0x04u:
        Dcm_DspProgram.Status = DCM_UDS0X38_0x04;
        break;
    case 0x05u:
        Dcm_DspProgram.Status = DCM_UDS0X38_0x05;
        break;
    default:
        /*idle*/
        break;
    }
    Dcm_DspProgram.MemoryIdInfoIndex = 0xFF;  /*memory the MemoryIdInfoIndex*/
    Dcm_DspProgram.BlockLength = BlockLength; /*memory one block size*/
    SchM_Exit_Dcm(Dcm_DspProgram);
    SchM_Enter_Dcm(Dcm_MsgCtrl);
    Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = (Dcm_MsgLenType)ResOffset - Offset;
    Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = (Dcm_MsgLenType)ResOffset - Offset;
    Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
    SchM_Exit_Dcm(Dcm_MsgCtrl);
    DsdInternal_ProcessingDone(ProtocolCtrlId);
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
FUNC(Std_ReturnType, DCM_CODE)
/* PRQA S 1532,3432++ */ /* MISRA Rule 8.7,20.7 */
Dcm_UDS0x38(
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
    uint16 fileSizeParameterLength = 0;
    uint8 index;
    uint8 modeOfOperation;
    uint8 dataFormatIdentifier;
    uint32 ResOffset;
    uint8 fileSizeUncompressedOrDirInfoLength = 0;
    uint8 fileSizeCompressed;
    uint32 BlockLength = 0;
    uint8 lengthFormatIdentifier;
    Dcm_0x38Types Dcm_0x38Type;

    /*if the required protocol is configured,get the index of runtime datum*/
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    Dcm_0x38Type.BlockLength = &BlockLength;
    Dcm_0x38Type.fileSizeParameterLength = &fileSizeParameterLength;
    Dcm_0x38Type.fileSizeUncompressedOrDirInfoLength = &fileSizeUncompressedOrDirInfoLength;
    Dcm_0x38Type.fileSizeCompressed = &fileSizeCompressed;
    Dcm_0x38Type.dataFormatIdentifier = &dataFormatIdentifier;
    ret = Dcm_Uds0x38ServiceConditionCheck(OpStatus, ProtocolCtrlId, &Dcm_0x38Type, ErrorCode);
    if (E_OK == ret)
    {
        modeOfOperation = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[1];
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
        /*the processing is successful,assemble positive response*/
        SchM_Enter_Dcm(Dcm_Channel);
        Dcm_Channel[Offset] = 0x78;                 /*response SID*/
        Dcm_Channel[Offset + 1u] = modeOfOperation; /*modeOfOperation*/
        SchM_Exit_Dcm(Dcm_Channel);
        ResOffset = Offset + 2u;
        if (modeOfOperation != 0x02u)
        {
            if (Dcm_DspCfg.DcmDspRequestFileTransfer != NULL_PTR)
            {
                lengthFormatIdentifier =
                    Dcm_DspCfg.DcmDspRequestFileTransfer->DcmRequestFileTransferLengthFormatIdentifier;
            }
            else
            {
                lengthFormatIdentifier = 4u;
            }
            SchM_Enter_Dcm(Dcm_Channel);
            Dcm_Channel[ResOffset] = lengthFormatIdentifier;
            SchM_Exit_Dcm(Dcm_Channel);
            ResOffset += 1u;
            for (index = 0; index < lengthFormatIdentifier; index++)
            {
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_Channel[ResOffset] = (uint8)(BlockLength >> (uint8)((lengthFormatIdentifier - index - 1u) * 8u));
                SchM_Exit_Dcm(Dcm_Channel); /*maxNumberOfBlockLength*/
                ResOffset += 1u;
            }
            if (modeOfOperation == 0x05u)
            {
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_Channel[ResOffset] = 0x00u;
                SchM_Exit_Dcm(Dcm_Channel);
            }
            else
            {
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_Channel[ResOffset] = dataFormatIdentifier;
                SchM_Exit_Dcm(Dcm_Channel);
            }
            ResOffset += 1u;
            if ((modeOfOperation != 0x01u) && (modeOfOperation != 0x03u))
            {
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_Channel[ResOffset] = (uint8)fileSizeParameterLength;
                SchM_Exit_Dcm(Dcm_Channel);
                ResOffset += 1u;
                for (index = 0; index < fileSizeParameterLength; index++)
                {
                    SchM_Enter_Dcm(Dcm_Channel);
                    Dcm_Channel[ResOffset] = *Dcm_0x38Type.fileSizeUncompressedOrDirInfoLength;
                    SchM_Exit_Dcm(Dcm_Channel);
                    (*Dcm_0x38Type.fileSizeUncompressedOrDirInfoLength)++;
                    ResOffset += 1u;
                }
                if (modeOfOperation != 0x05u)
                {
                    for (index = 0; index < fileSizeParameterLength; index++)
                    {
                        SchM_Enter_Dcm(Dcm_Channel);
                        Dcm_Channel[ResOffset] = *Dcm_0x38Type.fileSizeCompressed;
                        SchM_Exit_Dcm(Dcm_Channel);
                        (*Dcm_0x38Type.fileSizeCompressed)++;
                        ResOffset += 1u;
                    }
                }
            }
        } /* check tx data length */
        if ((ResOffset - Offset) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
        { /*Pdu length is bigger than buffer size */
            *ErrorCode = DCM_E_RESPONSETOOLONG;
            ret = E_NOT_OK;
        }
    }
    if (E_OK == ret)
    {
        Dcm_UDS0x38_Tx(ProtocolCtrlId, ResOffset, BlockLength);
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
