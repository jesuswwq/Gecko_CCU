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
/******************************* references ************************************/
#include "Dcm_Internal.h"
#include "UDS.h"

/******************************* references ************************************/
/*****/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_SuppressPosRsp(uint8 ProtocolCtrlId);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*****/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_SidCheck(uint8 ProtocolCtrlId);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_AddressingFormatCheck(uint8 ProtocolCtrlId, uint8 Sid);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#if (STD_ON == DCM_DSD_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_ManufacturerIndication(uint8 ProtocolCtrlId);
static FUNC(void, DCM_CODE) DsdInternal_ManufacturerConfirmation(uint8 ProtocolCtrlId);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

#if (STD_ON == DCM_DSD_REQUEST_SUPPLIER_NOTIFICATION_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_SupplierIndication(uint8 ProtocolCtrlId);
static FUNC(void, DCM_CODE) DsdInternal_SupplierConfirmation(uint8 ProtocolCtrlId);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/*******************internal functions****************************/
/*************************************************************************/
/*
 * Brief               <Find SID corresponding service configuration table index
 *                      and the service index in corresponding service configuration table.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <Sid: Service Id;
 *                      ProtocolCtrlId: The corresponding protocol control block ID number>
 * Param-Name[out]     <(*pSidTabIndex):Request packet index number
 * in the service configuration table;
 *                      (*pSidTabServieCfgIndex): the service index
 *                      in corresponding service configuration table>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
DsdInternal_SearchSidTabServiceIndex(
    uint8 Sid,
    uint8 ProtocolCtrlId,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) pSidTabIndex,

    P2VAR(uint16, AUTOMATIC, DCM_VAR) pSidTabServieCfgIndex)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint8 SidTabId;
    uint8 Service_Num;
    uint16 SidTabIndex;
    uint16 ServiceIndex;
    boolean Flag = FALSE;
    P2CONST(Dcm_DsdServiceCfgType, AUTOMATIC, DCM_CONST) pDsdSidTab;
    Std_ReturnType ret = E_OK;

    if ((NULL_PTR != pSidTabIndex) && (NULL_PTR != pSidTabServieCfgIndex))
    {
        /*Read the protocol includes the service table ID */
        SidTabId = (Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow)[ProtocolCtrlId].DcmDslServiceTableID;
        /*find SidTabId configuration position in the service configuration table*/
        for (SidTabIndex = 0; (SidTabIndex < Dcm_DsdCfg.DcmDsdServiceTable_Num) && (FALSE == Flag); SidTabIndex++)
        {
            if (SidTabId == ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex].DcmDsdSidTabId))
            {
                Flag = TRUE;
            }
        }
        if (FALSE == Flag)
        {
            /*Did not find the service table ID,in the configuration table*/
            ret = E_NOT_OK;
        }
        else
        {
            (*pSidTabIndex) = SidTabIndex - (uint16)1;
        }
        if (E_OK == ret)
        {
            /*Read the first address of the corresponding service table*/
            pDsdSidTab = (Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex - 1u].pDcmDsdService;
            /*Read the number of services,in the corresponding service table*/
            Service_Num = (Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex - 1u].DcmDsdSidTab_ServiceNum;
            Flag = FALSE;
            for (ServiceIndex = 0; (ServiceIndex < Service_Num) && (FALSE == Flag); ServiceIndex++)
            {
                if ((Sid == pDsdSidTab[ServiceIndex].DcmDsdServiceId)
                    && (pDsdSidTab[ServiceIndex].DcmDsdServiceUsed == TRUE))
                {
                    Flag = TRUE;
                }
            }
            if (FALSE == Flag)
            {
                /*Did not find the service ID,in the corresponding service table*/
                ret = E_NOT_OK;
            }
            else
            {
                (*pSidTabServieCfgIndex) = (ServiceIndex - (uint16)1);
            }
        }
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}

FUNC(Std_ReturnType, DCM_CODE)
DsdInternal_SearchSidTabSubServiceIndex(
    uint8 ProtocolCtrlId,
    uint16 SidTabIndex,
    uint16 ServiceIndex,
    P2VAR(uint16, AUTOMATIC, DCM_VAR) pSubServieCfgIndex) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 MsgCtrlId;
    uint8 SubFunctionId;
    uint8 SubService_Num;
    uint16 SubServiceIndex;
    boolean Flag = FALSE;
    Std_ReturnType ret = E_OK;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    SubFunctionId = Dcm_MsgCtrl[MsgCtrlId].Subfunction;
    SubService_Num = ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex].pDcmDsdService)[ServiceIndex].DcmDsdSubService_Num;
    if (SubService_Num > 0u)
    {
        for (SubServiceIndex = 0; (SubServiceIndex < SubService_Num) && (FALSE == Flag); SubServiceIndex++)
        {
            if (SubFunctionId
                == (((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex].pDcmDsdService)[ServiceIndex]
                        .DcmDsdSubService)[SubServiceIndex]
                       .DcmDsdSubServiceId)
            {
                Flag = TRUE;
            }
        }
        if (FALSE == Flag)
        {
            ret = E_NOT_OK;
        }
        (*pSubServieCfgIndex) = SubServiceIndex - (uint16)1;
    }
    else
    {
        (*pSubServieCfgIndex) = DCM_INVALID_UINT16;
        ret = E_NOT_OK;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/*************************************************************************/
/*
 * Brief               <Save a positive response prohibit information>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <Sid: Service Id;
 *                      ProtocolCtrlId:The corresponding protocol control block ID number;>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_SuppressPosRsp(uint8 ProtocolCtrlId)
{
    uint8 MsgCtrlIndexx;
    uint8 SubFunction;
    uint8 Sid;
    uint16 SidTabCfgIndex;
    uint16 SidTabServiceCfgIndex;
    Std_ReturnType ret;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    Sid = Dcm_MsgCtrl[MsgCtrlIndexx].SID;
    ret = DsdInternal_SearchSidTabServiceIndex(Sid, ProtocolCtrlId, &SidTabCfgIndex, &SidTabServiceCfgIndex);
    if ((E_OK == ret)
        && (TRUE
            == ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabCfgIndex].pDcmDsdService)[SidTabServiceCfgIndex]
                   .DcmDsdSubfuncAvial))
    {
        SubFunction = Dcm_MsgCtrl[MsgCtrlIndexx].Subfunction;
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.MsgAddInfo.SuppressPosResponse = FALSE;
        if ((0x80u == (SubFunction & 0x80u))
            && (TRUE
                == ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabCfgIndex].pDcmDsdService)[SidTabServiceCfgIndex]
                       .DcmDsdSuppressPosRsp))
        {
            Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.MsgAddInfo.SuppressPosResponse = TRUE;
            /*Set response type "DCM_POS_RSP_SUPPRESS"*/
            Dcm_MsgCtrl[MsgCtrlIndexx].RspStyle = DCM_POS_RSP_SUPPRESS;
            /*Clear positive response Prohibition information*/
            (Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.pReqData)[1] = (SubFunction & 0x7Fu);
            Dcm_MsgCtrl[MsgCtrlIndexx].Subfunction = (SubFunction & 0x7Fu);
        }
        SchM_Exit_Dcm(Dcm_MsgCtrl);
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <Check request packet whether the SID is configured in the service table>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number;
 *                      Sid: Service Id;>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_SidCheck(uint8 ProtocolCtrlId)
{
    uint16 SidTabCfgIndex;
    uint16 SidTabServiceCfgIndex;
    uint8 MsgCtrlIndexx;
    uint8 Sid;
    Std_ReturnType ret;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    Sid = Dcm_MsgCtrl[MsgCtrlIndexx].SID;
    ret = DsdInternal_SearchSidTabServiceIndex(Sid, ProtocolCtrlId, &SidTabCfgIndex, &SidTabServiceCfgIndex);
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <Check request packet addressing type whether is correct.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number;
 *                      Sid: Service Id;>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_AddressingFormatCheck(uint8 ProtocolCtrlId, uint8 Sid)
{
    uint8 Subfunction;
    uint8 MsgCtrlIndexx;
    uint16 SidTabCfgIndex;
    uint16 SidTabServiceCfgIndex;
    uint8 RxServiceAddressingFormat;
    Dcm_DslProtocolRxAddrType CfgServiceAddressingFormat;
    Std_ReturnType ret;

    /*******************************************************/
    ret = DsdInternal_SearchSidTabServiceIndex(Sid, ProtocolCtrlId, &SidTabCfgIndex, &SidTabServiceCfgIndex);
    if (E_OK == ret)
    {
        /*Read the service configuration support addressing*/
        CfgServiceAddressingFormat =
            ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabCfgIndex].pDcmDsdService)[SidTabServiceCfgIndex].AddressingFormat;
        if (DCM_PHYANDFUNC != CfgServiceAddressingFormat)
        {
            /*Read request packet addressing type*/
            MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
            RxServiceAddressingFormat = Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.MsgAddInfo.ReqType;
            if ((uint8)CfgServiceAddressingFormat != RxServiceAddressingFormat)
            {
                /*Configure addressing type is different from the actual addressing type*/
                ret = E_NOT_OK;
            }
        }
        /*else The service supports functional addressing and physical addressing*/
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#if (STD_ON == DCM_DSD_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED)
/*************************************************************************/
/*
 * Brief               <Diagnostic request packet is whether
 * allowed in the current application environment>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant/Non Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number;
 *                      Sid: Service Id;>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_ManufacturerIndication(uint8 ProtocolCtrlId)
{
    uint8 MsgCtrlIndexx;
    uint16 PortIndex;
    uint8 NotAcceptNum = 0u;
    uint8 Env_NokNum = 0u;
    uint16 ReqDatalen;
    uint8 ReqType;
    uint8 Sid;
    PduIdType RxPduId;
    uint8 ConnectionCfgId;
    uint16 SourceAddress;
    boolean Flag = FALSE;
    Std_ReturnType ret;
    P2VAR(uint8, AUTOMATIC, DCM_VAR) pReqDatax;
    Dcm_NegativeResponseCodeType ErrorCode;
    Dcm_NegativeResponseCodeType FirstErrorCode = DCM_INVALID_UINT8;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    Sid = Dcm_MsgCtrl[MsgCtrlIndexx].SID;
    pReqDatax = &Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.pReqData[0];
    ReqDatalen = (uint16)(Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.ReqDataLen - 1u);
    ReqType = Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.MsgAddInfo.ReqType;
    /*find out the source address of request message */
    RxPduId = Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.DcmRxPduId;
    ConnectionCfgId = Dsl_Protocol_Connection_RxCfg[RxPduId].DcmDslParentConnectionCtrlId;
    SourceAddress = Dsl_Protocol_ConnectionCfg[ConnectionCfgId].pDcmDslMainConnection->DcmDslProtocolRxTesterSourceAddr;
    for (PortIndex = 0; (PortIndex < Dcm_DsdCfg.DcmDsdServiceReqManufacturerNoti_PortNum) && (FALSE == Flag);
         PortIndex++)
    {
        if (NULL_PTR == ((Dcm_DsdCfg.pDcmDsdServiceReqManufacturerNoti)[PortIndex].Indication))
        {
            Flag = TRUE;
        }
        else
        {
            ret = (*((Dcm_DsdCfg.pDcmDsdServiceReqManufacturerNoti)[PortIndex]
                         .Indication))(Sid, pReqDatax, ReqDatalen, ReqType, SourceAddress, &ErrorCode);
            switch (ret)
            {
            case E_OK:
                break;
            case E_REQUEST_NOT_ACCEPTED:
                NotAcceptNum++;
                break;
            case E_NOT_OK:
            default:
                if (FirstErrorCode == DCM_INVALID_UINT8)
                {
                    FirstErrorCode = ErrorCode;
                }
                Env_NokNum++;
                break;
            }
        }
    }
    if (0u != NotAcceptNum)
    {
        /*the request is not accepted*/
        DsdInternal_ManufacturerConfirmation(ProtocolCtrlId);
        DslInternal_ResetResource(ProtocolCtrlId);
        ret = E_NOT_OK;
    }
    else if ((0u != Env_NokNum) || (TRUE == Flag))
    {
        DsdInternal_SetNrc(ProtocolCtrlId, FirstErrorCode);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
        ret = E_NOT_OK;
    }
    else
    {
        ret = E_OK;
    }
    return ret;
}

static FUNC(void, DCM_CODE) DsdInternal_ManufacturerConfirmation(uint8 ProtocolCtrlId)
{
    uint8 MsgCtrlIndexx;
    uint16 PortIndex;
    uint8 Sid;
    uint8 ReqType;
    PduIdType RxPduId;
    uint8 ConnectionCfgId;
    uint16 SourceAddress;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    Sid = Dcm_MsgCtrl[MsgCtrlIndexx].SID;
    ReqType = Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.MsgAddInfo.ReqType;
    /*find out the source address of request message */
    RxPduId = Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.DcmRxPduId;
    ConnectionCfgId = Dsl_Protocol_Connection_RxCfg[RxPduId].DcmDslParentConnectionCtrlId;
    SourceAddress = Dsl_Protocol_ConnectionCfg[ConnectionCfgId].pDcmDslMainConnection->DcmDslProtocolRxTesterSourceAddr;
    for (PortIndex = 0; PortIndex < Dcm_DsdCfg.DcmDsdServiceReqManufacturerNoti_PortNum; PortIndex++)
    {
        (void)(*((Dcm_DsdCfg.pDcmDsdServiceReqManufacturerNoti)[PortIndex].Confirmation))(
            Sid,
            ReqType,
            SourceAddress,
            DCM_RES_NEG_NOT_OK);
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

#if (STD_ON == DCM_DSD_REQUEST_SUPPLIER_NOTIFICATION_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_SupplierIndication(uint8 ProtocolCtrlId)
{
    uint8 MsgCtrlIndexx;
    uint16 PortIndex;
    uint8 NotAcceptNum = 0u;
    uint8 Env_NokNum = 0u;
    uint16 ReqDatalen;
    uint8 ReqType;
    uint8 Sid;
    PduIdType RxPduId;
    uint8 ConnectionCfgId;
    uint16 SourceAddress;
    boolean Flag = FALSE;
    Std_ReturnType ret;
    P2VAR(uint8, AUTOMATIC, DCM_VAR) pReqDatax;
    Dcm_NegativeResponseCodeType ErrorCode;
    Dcm_NegativeResponseCodeType FirstErrorCode = DCM_INVALID_UINT8;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    Sid = Dcm_MsgCtrl[MsgCtrlIndexx].SID;
    pReqDatax = &Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.pReqData[0];
    ReqDatalen = (uint16)(Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.ReqDataLen - 1u);
    ReqType = Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.MsgAddInfo.ReqType;
    /*find out the source address of request message */
    RxPduId = Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.DcmRxPduId;
    ConnectionCfgId = Dsl_Protocol_Connection_RxCfg[RxPduId].DcmDslParentConnectionCtrlId;
    SourceAddress = Dsl_Protocol_ConnectionCfg[ConnectionCfgId].pDcmDslMainConnection->DcmDslProtocolRxTesterSourceAddr;
    for (PortIndex = 0; (PortIndex < Dcm_DsdCfg.DcmDsdServiceReqSupplierNoti_PortNum) && (FALSE == Flag); PortIndex++)
    {
        if (NULL_PTR == ((Dcm_DsdCfg.pDcmDsdServiceReqSupplierNoti)[PortIndex].Indication))
        {
            Flag = TRUE;
        }
        else
        {
            ret = (*((Dcm_DsdCfg.pDcmDsdServiceReqSupplierNoti)[PortIndex]
                         .Indication))(Sid, pReqDatax, ReqDatalen, ReqType, SourceAddress, &ErrorCode);
            switch (ret)
            {
            case E_OK:
                break;
            case E_REQUEST_NOT_ACCEPTED:
                NotAcceptNum++;
                break;
            case E_NOT_OK:
            default:
                if (FirstErrorCode == DCM_INVALID_UINT8)
                {
                    FirstErrorCode = ErrorCode;
                }
                Env_NokNum++;
                break;
            }
        }
    }
    if (0u != NotAcceptNum)
    {
        /*the request is not accepted*/
        DslInternal_ResetResource(ProtocolCtrlId);
        ret = E_NOT_OK;
    }
    else if ((0u != Env_NokNum) || (TRUE == Flag))
    {
        DsdInternal_SetNrc(ProtocolCtrlId, FirstErrorCode);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
        ret = E_NOT_OK;
    }
    else
    {
        ret = E_OK;
    }
    return ret;
}

static FUNC(void, DCM_CODE) DsdInternal_SupplierConfirmation(uint8 ProtocolCtrlId)
{
    uint8 MsgCtrlIndexx;
    uint16 PortIndex;
    uint8 Sid;
    uint8 ReqType;
    PduIdType RxPduId;
    uint8 ConnectionCfgId;
    uint16 SourceAddress;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    Sid = Dcm_MsgCtrl[MsgCtrlIndexx].SID;
    ReqType = Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.MsgAddInfo.ReqType;
    /*find out the source address of request message */
    RxPduId = Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.DcmRxPduId;
    ConnectionCfgId = Dsl_Protocol_Connection_RxCfg[RxPduId].DcmDslParentConnectionCtrlId;
    SourceAddress = Dsl_Protocol_ConnectionCfg[ConnectionCfgId].pDcmDslMainConnection->DcmDslProtocolRxTesterSourceAddr;
    for (PortIndex = 0; PortIndex < Dcm_DsdCfg.DcmDsdServiceReqSupplierNoti_PortNum; PortIndex++)
    {
        (void)(*((Dcm_DsdCfg.pDcmDsdServiceReqSupplierNoti)[PortIndex].Confirmation))(
            Sid,
            ReqType,
            SourceAddress,
            DCM_RES_NEG_NOT_OK);
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/*************************************************************************/
/*
 * Brief               <Determine the diagnostic request
 * packet is allowed in the current session state.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number;
 *                      Sid: Service Id;>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE) DsdInternal_SesCheck(uint8 ProtocolCtrlId, uint8 Sid)
{
    uint8 ActiveSes;
    uint8 SesRefNum;
    uint8 SesCfgIndex;
    uint16 SidTabCfgIndex;
    uint16 SidTabServiceCfgIndex;
    boolean Flag = FALSE;
    Std_ReturnType ret;

    ret = DsdInternal_SearchSidTabServiceIndex(Sid, ProtocolCtrlId, &SidTabCfgIndex, &SidTabServiceCfgIndex);
    if (E_OK == ret)
    {
        SesRefNum = ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabCfgIndex].pDcmDsdService)[SidTabServiceCfgIndex]
                        .DcmDsdSessionLevel_Num;
        if (0u != SesRefNum)
        {
            /*get Currently valid session state*/
            ActiveSes = Dcm_MkCtrl.Dcm_ActiveSes;
            for (SesCfgIndex = 0; (SesCfgIndex < SesRefNum) && (FALSE == Flag); SesCfgIndex++)
            {
                if (ActiveSes
                    == ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabCfgIndex].pDcmDsdService)[SidTabServiceCfgIndex]
                           .pDcmDsdSessionLevelRef[SesCfgIndex])
                {
                    Flag = TRUE;
                }
            }
            if (FALSE == Flag)
            {
                /*this service is not supported in the current valid session status*/
                ret = E_NOT_OK;
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE) DsdInternal_SubSesCheck(uint8 ProtocolCtrlId, uint8 Sid)
{
    uint8 ActiveSes;
    uint8 SubSesRefNum;
    uint8 SubServiceNum;
    uint8 SesCfgIndex;
    uint16 SidTabCfgIndex;
    uint16 SidTabServiceCfgIndex;
    uint16 SubServieCfgIndex;
    P2CONST(Dcm_DsdSubServiceCfgType, AUTOMATIC, DCM_VAR) pDcmDsdSubService;
    boolean Flag = FALSE;
    Std_ReturnType ret;

    ret = DsdInternal_SearchSidTabServiceIndex(Sid, ProtocolCtrlId, &SidTabCfgIndex, &SidTabServiceCfgIndex);
    if (E_OK == ret)
    {
        ret = DsdInternal_SearchSidTabSubServiceIndex(
            ProtocolCtrlId,
            SidTabCfgIndex,
            SidTabServiceCfgIndex,
            &SubServieCfgIndex);
    }
    if (E_OK == ret)
    {
        SubServiceNum = ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabCfgIndex].pDcmDsdService)[SidTabServiceCfgIndex]
                            .DcmDsdSubService_Num;
        if (0u != SubServiceNum)
        {
            pDcmDsdSubService = ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabCfgIndex].pDcmDsdService)[SidTabServiceCfgIndex]
                                    .DcmDsdSubService;
            SubSesRefNum = pDcmDsdSubService[SubServieCfgIndex].DcmDsdSubServiceSessionLevel_Num;
            if (0u != SubSesRefNum)
            {
                /*get Currently valid session state*/
                ActiveSes = Dcm_MkCtrl.Dcm_ActiveSes;
                for (SesCfgIndex = 0; (SesCfgIndex < SubSesRefNum) && (FALSE == Flag); SesCfgIndex++)
                {
                    if (ActiveSes == pDcmDsdSubService[SubServieCfgIndex].DcmDsdSubServiceSessionLevelRef[SesCfgIndex])
                    {
                        Flag = TRUE;
                    }
                }
                if (FALSE == Flag)
                {
                    /*this service is not supported in the current valid session status*/
                    ret = E_NOT_OK;
                }
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/*************************************************************************/
/*
 * Brief               <determine the diagnostic request packet is
 * allowed in the current security level>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number;
 *                      Sid: Service Id;>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE) DsdInternal_SecurityCheck(uint8 ProtocolCtrlId, uint8 Sid)
{
    uint8 ActiveSec;
    uint8 SecRefNum;
    uint8 SecCfgIndex;
    uint16 SidTabCfgIndex;
    uint16 SidTabServiceCfgIndex;
    P2CONST(uint8, AUTOMATIC, DCM_CONST) pSecCfg;
    boolean Flag = FALSE;
    Std_ReturnType ret;

    ret = DsdInternal_SearchSidTabServiceIndex(Sid, ProtocolCtrlId, &SidTabCfgIndex, &SidTabServiceCfgIndex);
    if (E_OK == ret)
    {
        /*get Currently valid security level*/
        ActiveSec = Dcm_MkCtrl.Dcm_ActiveSec;
        SecRefNum = ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabCfgIndex].pDcmDsdService)[SidTabServiceCfgIndex]
                        .DcmDsdSecurityLevel_Num;
        if (SecRefNum != 0u)
        {
            pSecCfg = ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabCfgIndex].pDcmDsdService)[SidTabServiceCfgIndex]
                          .pDcmDsdSecurityLevelRef;
            for (SecCfgIndex = 0; (SecCfgIndex < SecRefNum) && (FALSE == Flag); SecCfgIndex++)
            {
                if (ActiveSec == pSecCfg[SecCfgIndex])
                {
                    Flag = TRUE;
                }
            }
            if (FALSE == Flag)
            {
                /*this service is not supported in the current valid security level*/
                ret = E_NOT_OK;
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE) DsdInternal_SubSecurityCheck(uint8 ProtocolCtrlId, uint8 Sid)
{
    uint8 ActiveSec;
    uint8 SubSecRefNum;
    uint8 SubServiceNum;
    uint8 SecCfgIndex;
    uint16 SidTabCfgIndex;
    uint16 SidTabServiceCfgIndex;
    uint16 SubServieCfgIndex;
    P2CONST(Dcm_DsdSubServiceCfgType, AUTOMATIC, DCM_CONST) pSubService;
    boolean Flag = FALSE;
    Std_ReturnType ret;

    ret = DsdInternal_SearchSidTabServiceIndex(Sid, ProtocolCtrlId, &SidTabCfgIndex, &SidTabServiceCfgIndex);
    if (E_OK == ret)
    {
        ret = DsdInternal_SearchSidTabSubServiceIndex(
            ProtocolCtrlId,
            SidTabCfgIndex,
            SidTabServiceCfgIndex,
            &SubServieCfgIndex);
        if (E_OK == ret)
        {
            /*get Currently valid security level*/
            ActiveSec = Dcm_MkCtrl.Dcm_ActiveSec;
            SubServiceNum = ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabCfgIndex].pDcmDsdService)[SidTabServiceCfgIndex]
                                .DcmDsdSubService_Num;
            if (0u != SubServiceNum)
            {
                pSubService = ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabCfgIndex].pDcmDsdService)[SidTabServiceCfgIndex]
                                  .DcmDsdSubService;
                SubSecRefNum = pSubService[SubServieCfgIndex].DcmDsdSubServiceSecurityLevel_Num;
                if (0u != SubSecRefNum)
                {
                    for (SecCfgIndex = 0; (SecCfgIndex < SubSecRefNum) && (FALSE == Flag); SecCfgIndex++)
                    {
                        if (ActiveSec == pSubService[SubServieCfgIndex].DcmDsdSubServiceSecurityLevelRef[SecCfgIndex])
                        {
                            Flag = TRUE;
                        }
                    }
                    if (FALSE == Flag)
                    {
                        /*this service is not supported in the current valid security level*/
                        ret = E_NOT_OK;
                    }
                }
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/*******************public functions******************************/
/*************************************************************************/
/*
 * Brief               <Set the negative response code NRC;>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number;
 *                      Nrc: the negative response code;>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DsdInternal_SetNrc(uint8 ProtocolCtrlId, Dcm_NegativeResponseCodeType Nrc)
{
    uint8 MsgCtrlIndexx;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    SchM_Enter_Dcm(Dcm_MsgCtrl);
    Dcm_MsgCtrl[MsgCtrlIndexx].NRC = Nrc;
    Dcm_MsgCtrl[MsgCtrlIndexx].RspStyle = DCM_NEG_RSP;
    SchM_Exit_Dcm(Dcm_MsgCtrl);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/*************************************************************************/
/*
 * Brief               <Set corresponding message processing state>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number;
 *                      MsgState: message processing state>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DsdInternal_SetMsgState(uint8 ProtocolCtrlId, Dcm_MsgStateType MsgState)
{
    uint8 MsgCtrlIndexx;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    SchM_Enter_Dcm(Dcm_MsgCtrl);
    Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MsgState = MsgState;
    SchM_Exit_Dcm(Dcm_MsgCtrl);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <The diagnostic request processing in DSD layer>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number;>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_RxIndication_Check(uint8 ProtocolCtrlId)
{
    uint8 Sid;
    uint8 MsgCtrlId;
    Dcm_ProtocolStateType ProtocolState;
    Std_ReturnType ret = E_OK;

    ProtocolState = Dcm_ProtocolCtrl[ProtocolCtrlId].Dcm_ProtocolState;
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    Sid = Dcm_MsgCtrl[MsgCtrlId].SID;
    if (DCM_PROTOCOL_VALID != ProtocolState)
    {
        /*xxx_startProtocol in DslInternal_ProtocolStart not return all ok */
        DsdInternal_SetNrc(ProtocolCtrlId, DCM_E_CONDITIONSNOTCORRECT);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
        ret = E_NOT_OK;
    }
    /*SID range checks*/
#if (STD_OFF == DCM_RESPOND_ALL_REQUEST)
    if ((E_OK == ret) && (((Sid >= 0x40u) && (Sid <= 0x7Fu)) || (Sid >= 0xC0u)))
    {
        /*(0x40=<SID<=0x7F)||(0xC0=<SID<=0xFF)*/
        DslInternal_ResetResource(ProtocolCtrlId);
        ret = E_NOT_OK;
    }
#endif
    if (E_OK == ret)
    {
        /*Check whether the SID is configured in the corresponding service table*/
        ret = DsdInternal_SidCheck(ProtocolCtrlId);
        if (E_NOT_OK == ret)
        {
            /*Set Nrc=0x11(service not supported )*/
            DsdInternal_SetNrc(ProtocolCtrlId, DCM_E_SERVICENOTSUPPORTED);
            DsdInternal_ProcessingDone(ProtocolCtrlId);
        }
    }
    if (E_OK == ret)
    {
        /*Check whether received packets addressing modes support*/
        ret = DsdInternal_AddressingFormatCheck(ProtocolCtrlId, Sid);
        if (E_NOT_OK == ret)
        {
            /*Set Nrc=0x11(service not supported )*/
            DsdInternal_SetNrc(ProtocolCtrlId, DCM_E_SERVICENOTSUPPORTED);
            DsdInternal_ProcessingDone(ProtocolCtrlId);
        }
    }
    if (E_OK == ret)
    {
        /*positive response  Suppress bit processing*/
        ret = DsdInternal_SuppressPosRsp(ProtocolCtrlId);
        if (E_NOT_OK == ret)
        {
            DslInternal_ResetResource(ProtocolCtrlId);
        }
    }
    /*Application environment and permissions verification*/
#if (STD_ON == DCM_DSD_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED)
    if (E_OK == ret)
    {
        ret = DsdInternal_ManufacturerIndication(ProtocolCtrlId);
    }
#endif
#if (STD_ON == DCM_DSD_REQUEST_SUPPLIER_NOTIFICATION_ENABLED)
    if (E_OK == ret)
    {
        ret = DsdInternal_SupplierIndication(ProtocolCtrlId);
    }
#endif
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <The diagnostic request processing in DSD layer>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number;>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE) DsdInternal_RxIndication(uint8 ProtocolCtrlId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 MsgCtrlId;
    Std_ReturnType ret;

    ret = DsdInternal_RxIndication_Check(ProtocolCtrlId);
    if (E_OK == ret)
    {
        MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].Dcm_MsgState = DCM_MSG_PROCESSED;
        SchM_Exit_Dcm(Dcm_MsgCtrl);
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DsdInternal_ProcessPage(uint8 ProtocolCtrlId)
{
    PduInfoType PduInfo;
    PduIdType DcmTxPduIdx;
    uint8 MsgCtrlIndexx;
#if (STD_ON == DCM_GENERIC_CONNECTION)
    PduIdType DcmRxPduIdx;
    uint8 Metadata[5];

    PduInfo.MetaDataPtr = Metadata;
#endif
    /*check the pagebuffer timer whether timeout*/
    if (Dcm_PageBufferData.TimeOut != TRUE)
    {
        /*DSP requests transmission of filled page*/
        MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
        DcmTxPduIdx = Dcm_MsgCtrl[MsgCtrlIndexx].DcmTxPduId;
#if (STD_ON == DCM_GENERIC_CONNECTION)
        DcmRxPduIdx = Dcm_MsgCtrl[MsgCtrlIndexx].DcmRxPduId;
        if ((Dsl_Protocol_Connection_RxCfg[DcmRxPduIdx].DcmDslMetaDataFlag & DCM_METADATA_LENGTH_MASK) > 0u)
        {
            if ((Dsl_Protocol_Connection_RxCfg[DcmRxPduIdx].DcmDslMetaDataFlag & DCM_ADDRESS_EXTENSION_8_MASK)
                == DCM_ADDRESS_EXTENSION_8_MASK)
            {
                PduInfo.MetaDataPtr[4u] = Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_AE;
            }
            if ((Dsl_Protocol_Connection_RxCfg[DcmRxPduIdx].DcmDslMetaDataFlag & DCM_SA16_AND_TA16_MASK)
                == DCM_SA16_AND_TA16_MASK)
            {
#if (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)
                PduInfo.MetaDataPtr[0u] = (uint8)((Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_TA & 0xFF00u) >> 8u);
                PduInfo.MetaDataPtr[1u] = (uint8)(Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_TA & 0xFFu);
                PduInfo.MetaDataPtr[2u] = (uint8)((Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_SA & 0xFF00u) >> 8u);
                PduInfo.MetaDataPtr[3u] = (uint8)(Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_SA & 0xFFu);
#else
                PduInfo.MetaDataPtr[0u] = (uint8)(Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_TA & 0xFFu);
                PduInfo.MetaDataPtr[1u] = (uint8)((Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_TA & 0xFF00u) >> 8u);
                PduInfo.MetaDataPtr[2u] = (uint8)(Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_SA & 0xFFu);
                PduInfo.MetaDataPtr[3u] = (uint8)((Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MetaData_SA & 0xFF00u) >> 8u);
#endif
            }
        }
#else
        PduInfo.MetaDataPtr = NULL_PTR;
#endif
        /*total length to be transmit of all pages*/
        PduInfo.SduLength = (PduLengthType)Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.ResMaxDataLen;
        (void)PduR_DcmTransmit(DcmTxPduIdx, &PduInfo);
        /****Close P2Server Timer****/
        DslInternal_P2ServerStop(ProtocolCtrlId);
    }
    return;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DsdInternal_StartPagedProcessing(uint8 ProtocolCtrlId)
{
    /****Close P2Server Timer****/
    DslInternal_P2ServerStop(ProtocolCtrlId);
    SchM_Enter_Dcm(Dcm_PageBufferData);
    Dcm_PageBufferData.PageIndex = 0;
    Dcm_PageBufferData.Filled = FALSE;
    SchM_Exit_Dcm(Dcm_PageBufferData);
    DspInternal_DcmUpdatePage(ProtocolCtrlId);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
/*************************************************************************/
/*
 * Brief               <Response to a diagnosis request processing>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number;>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DsdInternal_ProcessingDone(uint8 ProtocolCtrlId)
{
    uint8 Nrc;
    uint8 MsgCtrlIndexx;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint32 Offset;
    Dcm_RspType RspStylex;
    uint8 ReqTypex;
    /*Send NRC = 0x78 channel (Note: The channel length range: 8 ~ 4095)*/
    static VAR(uint8, DCM_VAR_POWER_ON_INIT) Dcm_Nrc78Channel[8] = {0};

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    /*Set message status "DCM_MSG_TRANSMISSION "*/
    SchM_Enter_Dcm(Dcm_MsgCtrl);
    Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_MsgState = DCM_MSG_TRANSMISSION;
    SchM_Exit_Dcm(Dcm_MsgCtrl);
    TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_TxCtrlChannelIndex;
    RspStylex = Dcm_MsgCtrl[MsgCtrlIndexx].RspStyle;
    switch (RspStylex)
    {
    case DCM_POS_RSP: /*--------------positive response---------------*/
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
        /*Store the response data to the corresponding transmit channel*/
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.pResData = &Dcm_Channel[Offset];
        SchM_Exit_Dcm(Dcm_MsgCtrl);
        DslInternal_ProcessingDone(ProtocolCtrlId);
        break;
    case DCM_NEG_RSP: /*---------------Negative response---------------*/
        /* Diagnosis  request type */
        ReqTypex = Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.MsgAddInfo.ReqType;
        Nrc = Dcm_MsgCtrl[MsgCtrlIndexx].NRC;
        if (((uint8)DCM_FUNCTIONAL == ReqTypex)
            && ((DCM_E_SERVICENOTSUPPORTED == Nrc) || (DCM_E_SUBFUNCTIONNOTSUPPORTED == Nrc)
                || (DCM_E_REQUESTOUTOFRANGE == Nrc) || (DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION == Nrc)
                || (DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION == Nrc)))
        {
            DslInternal_ResetResource(ProtocolCtrlId);
        }
        else if (DCM_E_RESPONSE_PENDING == Nrc)
        {
            /*NRC=0x78*/
            Dcm_Nrc78Channel[0] = 0x7Fu;
            Dcm_Nrc78Channel[1] = Dcm_MsgCtrl[MsgCtrlIndexx].SID;
            Dcm_Nrc78Channel[2] = DCM_E_RESPONSE_PENDING;
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.pResData = &Dcm_Nrc78Channel[0];
            Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.ResDataLen = 3u;
            Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.ResMaxDataLen = 3u;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            DslInternal_ProcessingDone(ProtocolCtrlId);
        }
        else
        {
            /*Other Nrc code*/
            TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
            Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
            SchM_Enter_Dcm(Dcm_Channel);
            Dcm_Channel[Offset] = 0x7Fu;
            Dcm_Channel[Offset + 1u] = Dcm_MsgCtrl[MsgCtrlIndexx].SID;
            Dcm_Channel[Offset + 2u] = (uint8)(Dcm_MsgCtrl[MsgCtrlIndexx].NRC);
            SchM_Exit_Dcm(Dcm_Channel);
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.pResData = &Dcm_Channel[Offset];
            Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.ResDataLen = 3u;
            Dcm_MsgCtrl[MsgCtrlIndexx].MsgContext.ResMaxDataLen = 3u;
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            DslInternal_ProcessingDone(ProtocolCtrlId);
        }
        break;
    case DCM_POS_RSP_SUPPRESS: /*-----positive response suppress---------------*/
#if (STD_ON == DCM_DSD_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED)
        DsdInternal_ManufacturerConfirmation(ProtocolCtrlId);
#endif
#if (STD_ON == DCM_DSD_REQUEST_SUPPLIER_NOTIFICATION_ENABLED)
        DsdInternal_SupplierConfirmation(ProtocolCtrlId);
#endif
        DspInternal_DcmConfirmation(ProtocolCtrlId);
        break;
    default:
        DslInternal_ResetResource(ProtocolCtrlId);
        break;
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <Notify the DSD layer, respond to the confirmation>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number;>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DsdInternal_TxConfirmation(uint8 ProtocolCtrlId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (STD_ON == DCM_DSD_REQUEST_MANUFACTURER_NOTIFICATION_ENABLED)
    DsdInternal_ManufacturerConfirmation(ProtocolCtrlId);
#endif
#if (STD_ON == DCM_DSD_REQUEST_SUPPLIER_NOTIFICATION_ENABLED)
    DsdInternal_SupplierConfirmation(ProtocolCtrlId);
#endif
    DspInternal_DcmConfirmation(ProtocolCtrlId);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#if ((STD_ON == DCM_SECURITY_FUNC_ENABLED) && (STD_ON == DCM_DSP_DID_FUNC_ENABLED))
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
DsdInternal_DidSecurityCheck(uint16 DidInfoCfgIndex, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    P2CONST(Dcm_DspDidReadType, AUTOMATIC, DCM_APPL_CONST) pDspDidRead;
    uint8 SecNum;
    uint8 Index;
    Std_ReturnType ret = E_OK;
    boolean Flag = FALSE;

    pDspDidRead = Dcm_DspCfg.pDcmDspDidInfo[DidInfoCfgIndex].pDcmDspDidRead;
    if (NULL_PTR == pDspDidRead)
    {
        /*if the DcmDspDidRead of required Did is not configured,send NRC 0x31*/
        *pNrc = DCM_E_REQUESTOUTOFRANGE;
        ret = E_NOT_OK;
    }
    else
    {
        SecNum = pDspDidRead->DcmDspDidReadSecurityLevelRefNum;
        if (SecNum != 0u)
        {
            for (Index = 0; (Index < SecNum) && (FALSE == Flag); Index++)
            {
                if (Dcm_MkCtrl.Dcm_ActiveSec == pDspDidRead->pDcmDspDidReadSecurityLevelRow[Index])
                {
                    Flag = TRUE;
                }
            }
            if (FALSE == Flag)
            {
                /*:the reading processing is not supported in current
                 * security level,send NRC 0x33*/
                *pNrc = DCM_E_SECURITYACCESSDENIED;
                ret = E_NOT_OK;
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

#if ((STD_ON == DCM_SESSION_FUNC_ENABLED) && (STD_ON == DCM_DSP_DID_FUNC_ENABLED))
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
DsdInternal_DidSessionCheck(uint16 DidInfoCfgIndex, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc)
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
                }
            }
            if (FALSE == Flag)
            {
                /*the reading processing is not supported in current security level,send NRC 0x31*/
                (*pNrc) = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/************************/
#if ((STD_ON == DCM_DSP_DID_FUNC_ENABLED) && (STD_ON == DCM_UDS_SERVICE0X2C_ENABLED))
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_DidCheck(
    uint16 receiveDid,
    P2VAR(uint8, AUTOMATIC, DCM_VAR_NOINIT) pRangeDidCfgIndex,
    P2VAR(uint16, AUTOMATIC, DCM_VAR_NOINIT) pDidCfgIndex,
    P2VAR(boolean, AUTOMATIC, DCM_VAR_NOINIT) pRangeDidFlag)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Dcm_DidSupportedType DidSupported;
    uint16 Index;
    uint8 Idx;
    boolean Flag = FALSE;
    boolean Flagx = FALSE;
    Std_ReturnType ret = E_NOT_OK;
#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
    uint8 iloop;
#endif

    *pRangeDidFlag = FALSE;
    /*first check whether the receiveDid is single did*/
    for (Index = 0; (Index < Dcm_DspCfg.DcmDspDidNum) && (FALSE == Flag); Index++)
    {
        /*single did check*/
        if ((receiveDid == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId)
            && (TRUE == Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidUsed))
        {
            if ((receiveDid > 0xF200u) && (receiveDid < 0xF3FFu)
                && (Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidInfoIndex]
                        .DcmDspDidDynamicallyDefined
                    == TRUE)
                && (Dcm_DspCfg.pDcmDspDidInfo[Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidInfoIndex].DcmDspDDDIDMaxElements
                    > 0u))
            {
#if (DCM_DSP_DDDID_MAX_NUMBER > 0u)
                for (iloop = 0; (iloop < DCM_DSP_DDDID_MAX_NUMBER) && (Flag == FALSE); iloop++)
                {
                    if (Dcm_DspCfg.pDcmDspDid[Index].DcmDspDidId == Dcm_DDDid[iloop].DDDid)
                    {
                        Flag = TRUE;
                        (*pDidCfgIndex) = Index;
                        ret = E_OK;
                    }
                }
#endif
            }
            else
            {
                Flag = TRUE;
                (*pDidCfgIndex) = Index;
                ret = E_OK;
            }
        }
    }
    /*if the receiveDid is not single did,the check whether the receiveDid is range did*/
    if (FALSE == Flag)
    {
        /*range did check*/
        if ((receiveDid < 0xF200u) || (receiveDid > 0xF3FFu))
        {
            /*range did can not be DDDid*/
            for (Idx = 0; (Idx < Dcm_DspCfg.DcmDspDidRangeNum) && (FALSE == Flagx); Idx++)
            {
                /*this range not have gaps*/
                if ((receiveDid >= Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeIdentifierLowerLimit)
                    && (receiveDid <= Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeIdentifierUpperLimit))
                {
                    if (TRUE == Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeHasGaps)
                    {
                        if (Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeIsDidAvailableFnc != NULL_PTR)
                        {
                            ret = Dcm_DspCfg.pDcmDspDidRange[Idx].DcmDspDidRangeIsDidAvailableFnc(
                                receiveDid,
                                DCM_INITIAL,
                                &DidSupported);
                            if ((ret == E_OK) && (DCM_DID_SUPPORTED == DidSupported))
                            {
                                *pRangeDidCfgIndex = Idx;
                                *pRangeDidFlag = TRUE;
                                Flagx = TRUE;
                            }
                        }
                    }
                    else
                    {
                        *pRangeDidCfgIndex = Idx;
                        *pRangeDidFlag = TRUE;
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
            (*pDidCfgIndex) = Index;
            ret = E_OK;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DsdInternal_DDDIDcheckMemory(void)
{
    Std_ReturnType ret = E_OK;
    uint8 IdInfoIndex;
    P2CONST(Dcm_DspReadMemoryRangeInfoType, AUTOMATIC, DCM_VAR_NOINIT)
    pDcmDspReadMemoryRangeInfo;
    P2CONST(Dcm_DspMemoryIdInfoType, AUTOMATIC, DCM_VAR_NOINIT)
    pDcmDspMemoryIdInfo;
    uint8 RangeInfoIndex;
    uint8 index;
    uint8 Num;
    boolean Find;

    for (IdInfoIndex = 0u; (E_OK == ret) && (IdInfoIndex < Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfoNum);
         IdInfoIndex++)
    {
        pDcmDspMemoryIdInfo = &(Dcm_DspCfg.pDcmDspMemory->DcmDspMemoryIdInfo[IdInfoIndex]);
        if (pDcmDspMemoryIdInfo != NULL_PTR)
        {
            for (RangeInfoIndex = 0;
                 (RangeInfoIndex < pDcmDspMemoryIdInfo->DcmDspReadMemoryRangeInfoNum) && (E_OK == ret);
                 RangeInfoIndex++)
            {
                pDcmDspReadMemoryRangeInfo = &(pDcmDspMemoryIdInfo->DcmDspReadMemoryRangeInfo[RangeInfoIndex]);
                Num = pDcmDspReadMemoryRangeInfo->DcmDspReadMemorySecurityLevelRefNum;
                if (Num != 0u)
                {
                    Find = FALSE;
                    for (index = 0; (index < Num) && (Find == FALSE); index++)
                    {
                        if (Dcm_MkCtrl.Dcm_ActiveSec
                            == pDcmDspReadMemoryRangeInfo->pDcmDspReadMemorySecurityLevelRow[index])
                        {
                            Find = TRUE;
                        }
                    }
                    if (Find == FALSE)
                    {
                        ret = E_NOT_OK;
                    }
                }
                if (E_OK == ret)
                {
                    Num = pDcmDspReadMemoryRangeInfo->DcmDspReadMemoryRangeSessionLevelRefNum;
                    if (Num != 0u)
                    {
                        Find = FALSE;
                        for (index = 0; (index < Num) && (Find == FALSE); index++)
                        {
                            if (Dcm_MkCtrl.Dcm_ActiveSes
                                == pDcmDspReadMemoryRangeInfo->pDcmDspReadMemoryRangeSessionLevelRow[index])
                            {
                                Find = TRUE;
                            }
                        }
                        if (Find == FALSE)
                        {
                            ret = E_NOT_OK;
                        }
                    }
                }
            }
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(Std_ReturnType, DCM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
DsdInternal_DDDIDcheckPerSourceDID(uint16 DDDidIdx, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, AUTOMATIC) pNrc)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    Std_ReturnType ret = E_OK;
    P2CONST(Dcm_DDDidElementsDataTypes, TYPEDEF, DCM_CONST) DDDid;
    uint8 DDDidNum;
    uint8 iloop;
    uint16 Did;
    uint8 RangeDidCfgIndex = 0;
    uint16 DidCfgIndex;
    boolean RangeDidFlag;
    uint8 DidInfoCfgIndex;

    if ((Dcm_DspCfg.DcmDspDDDIDcheckPerSourceDID != NULL_PTR) && (TRUE == *Dcm_DspCfg.DcmDspDDDIDcheckPerSourceDID))
    {
        DDDidNum = Dcm_DDDid[DDDidIdx].DDDIDNumOfElements;
        DDDid = Dcm_DDDid[DDDidIdx].DcmDspAlternativeArgumentData;
        for (iloop = 0; (iloop < DDDidNum) && (E_OK == ret); iloop++)
        {
            if (DDDid->Subfunction == DCM_UDS0X2C_01_DDBYDID)
            {
                Did = (uint16)(DDDid->Data & 0xFFFFu);
                ret = DsdInternal_DidCheck(Did, &RangeDidCfgIndex, &DidCfgIndex, &RangeDidFlag);
                if (E_OK == ret)
                {
                    if (TRUE == RangeDidFlag)
                    {
                        DidInfoCfgIndex = Dcm_DspCfg.pDcmDspDidRange[RangeDidCfgIndex].DcmDspDidRangeInfoIndex;
                    }
                    else
                    {
                        DidInfoCfgIndex = Dcm_DspCfg.pDcmDspDid[DidCfgIndex].DcmDspDidInfoIndex;
                    }
                    /*check the current session*/
#if ((STD_ON == DCM_SESSION_FUNC_ENABLED) && (STD_ON == DCM_DSP_DID_FUNC_ENABLED))
                    ret = DsdInternal_DidSessionCheck(DidInfoCfgIndex, pNrc);
#endif
                    /*check the current security level*/
#if ((STD_ON == DCM_SECURITY_FUNC_ENABLED) && (STD_ON == DCM_DSP_DID_FUNC_ENABLED))
                    if (E_OK == ret)
                    {
                        ret = DsdInternal_DidSecurityCheck(DidInfoCfgIndex, pNrc);
                    }
#endif
                }
            }
            else if (DDDid->Subfunction == DCM_UDS0X2C_02_DDBYMEMORY)
            {
                ret = DsdInternal_DDDIDcheckMemory();
                if (ret == E_NOT_OK)
                {
                    (*pNrc) = DCM_E_REQUESTOUTOFRANGE;
                }
            }
            else
            {
                /*idle*/
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
FUNC(Std_ReturnType, DCM_CODE)
DsdInternal_ServiceAddressAndLengthFormatIdentifierCheck(const uint8 addressAndLengthFormatIdentifier)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 iloop;

    for (iloop = 0; (iloop < Dcm_DspCfg.pDcmDspMemory->DcmDspAddressAndLengthFormatIdentifierNum) && (ret == E_NOT_OK);
         iloop++)
    {
        if (addressAndLengthFormatIdentifier
            == Dcm_DspCfg.pDcmDspMemory->DcmDspAddressAndLengthFormatIdentifier[iloop]
                   .DcmDspSupportedAddressAndLengthFormatIdentifier)
        {
            ret = E_OK;
        }
    }
    if (Dcm_DspCfg.pDcmDspMemory->DcmDspAddressAndLengthFormatIdentifierNum == 0u)
    {
        ret = E_OK;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
