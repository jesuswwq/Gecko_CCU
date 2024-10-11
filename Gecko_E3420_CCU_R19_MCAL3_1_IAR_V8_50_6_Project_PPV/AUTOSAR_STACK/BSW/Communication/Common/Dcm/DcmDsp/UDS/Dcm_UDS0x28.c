
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
#if (DCM_BSWM_ENABLE == STD_ON)
#include "BswM_Dcm.h"
#endif
/****************************************************************
             UDS:CommunicationControl (28 hex) service
 ***************************************************************/
#if (STD_ON == DCM_UDS_SERVICE0X28_ENABLED)
/********************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x28 service Get Request Mode>
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
static FUNC(Dcm_CommunicationModeType, DCM_CODE) DspInternalUDS0x28GetReqMode_0x01(uint8 subFunc)
{
    Dcm_CommunicationModeType RequestedMode = DCM_ENABLE_RX_TX_NORM;

    switch (subFunc)
    {
    case 0x00u:
        RequestedMode = DCM_ENABLE_RX_TX_NORM;
        break;
    case 0x01u:
        RequestedMode = DCM_ENABLE_RX_DISABLE_TX_NORM;
        break;
    case 0x02u:
        RequestedMode = DCM_DISABLE_RX_ENABLE_TX_NORM;
        break;
    case 0x03u:
        RequestedMode = DCM_DISABLE_RX_TX_NORMAL;
        break;
    default:
        /*idle*/
        break;
    }
    return RequestedMode;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/********************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x28 service Get Request Mode>
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
static FUNC(Dcm_CommunicationModeType, DCM_CODE) DspInternalUDS0x28GetReqMode_0x02(uint8 subFunc)
{
    Dcm_CommunicationModeType RequestedMode = DCM_ENABLE_RX_TX_NORM;

    switch (subFunc)
    {
    case 0x00u:
        RequestedMode = DCM_ENABLE_RX_TX_NM;
        break;
    case 0x01u:
        RequestedMode = DCM_ENABLE_RX_DISABLE_TX_NM;
        break;
    case 0x02u:
        RequestedMode = DCM_DISABLE_RX_ENABLE_TX_NM;
        break;
    case 0x03u:
        RequestedMode = DCM_DISABLE_RX_TX_NM;
        break;
    default:
        /*idle*/
        break;
    }
    return RequestedMode;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/********************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x28 service Get Request Mode>
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
static FUNC(Dcm_CommunicationModeType, DCM_CODE) DspInternalUDS0x28GetReqMode_0x03(uint8 subFunc)
{
    Dcm_CommunicationModeType RequestedMode = DCM_ENABLE_RX_TX_NORM;

    switch (subFunc)
    {
    case 0x00u:
        RequestedMode = DCM_ENABLE_RX_TX_NORM_NM;
        break;
    case 0x01u:
        RequestedMode = DCM_ENABLE_RX_DISABLE_TX_NORM_NM;
        break;
    case 0x02u:
        RequestedMode = DCM_DISABLE_RX_ENABLE_TX_NORM_NM;
        break;
    case 0x03u:
        RequestedMode = DCM_DISABLE_RX_TX_NORM_NM;
        break;
    default:
        /*idle*/
        break;
    }
    return RequestedMode;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/*************************************************************************/
/*
 * Brief               <UDS  0x28 service Get Request Mode>
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
static FUNC(Dcm_CommunicationModeType, DCM_CODE) DspInternalUDS0x28_0x00_0x03_GetReqMode(uint8 subFunc, uint8 comType)
{
    Dcm_CommunicationModeType RequestedMode = DCM_ENABLE_RX_TX_NORM;

    switch (comType)
    {
    case 0x01u:
        RequestedMode = DspInternalUDS0x28GetReqMode_0x01(subFunc);
        break;
    case 0x02u:
        RequestedMode = DspInternalUDS0x28GetReqMode_0x02(subFunc);
        break;
    case 0x03u:
        RequestedMode = DspInternalUDS0x28GetReqMode_0x03(subFunc);
        break;
    default:
        /*idle*/
        break;
    }
    return RequestedMode;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/********************************/
/*************************************************************************/
/*
 * Brief               <DspInternalUDS0x28_CheckNewSes>
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
FUNC(void, DCM_CODE) DspInternalUDS0x28_CheckNewSes(Dcm_SesCtrlType NewSes) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 iloop;
    Dcm_CommunicationModeType RequestedMode = DCM_ENABLE_RX_TX_NORM_NM;
    Std_ReturnType ret;
    uint8 ProtocolCtrlId = Dcm_MkCtrl.Dcm_ActiveProtocolCfgCtrlId;

    if (DCM_INVALID_UINT8 != ProtocolCtrlId)
    {
        ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_COMMUNICATION_CONTROL);
        if (((E_NOT_OK == ret) || (DCM_DEFAULT_SESSION == NewSes))
            && ((NULL_PTR != Dcm_Cfg.pDcmDspCfg) && (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl)))
        {

            if (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannel)
            {
                for (iloop = 0; iloop < Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannelNum; iloop++)
                {
                    if (TRUE
                        == Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannel[iloop]
                               .DcmDspComControlAllChannelUsed)
                    {
#if (DCM_BSWM_ENABLE == STD_ON)
                        BswM_Dcm_CommunicationMode_CurrentState(
                            Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannel[iloop]
                                .DcmDspComMChannelId,
                            RequestedMode);
#else
                        Rte_DcmControlCommunicationMode(
                            Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannel[iloop]
                                .DcmDspComMChannelId,
                            RequestedMode);
#endif
                    }
                }
            }
            if ((NULL_PTR != Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow)
                && (NULL_PTR
                    != Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId].pDcmDslConnection)
                && (NULL_PTR
                    != Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId]
                           .pDcmDslConnection->pDcmDslMainConnection))
            {
#if (DCM_BSWM_ENABLE == STD_ON)
                BswM_Dcm_CommunicationMode_CurrentState(
                    Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId]
                        .pDcmDslConnection->pDcmDslMainConnection->DcmDslProtocolComMChannelId,
                    RequestedMode);
#else
                Rte_DcmControlCommunicationMode(
                    Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId]
                        .pDcmDslConnection->pDcmDslMainConnection->DcmDslProtocolComMChannelId,
                    RequestedMode);
#endif
            }
            if (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel)
            {
                for (iloop = 0; iloop < Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannelNum;
                     iloop++)
                {
                    if (TRUE
                        == Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel[iloop]
                               .DcmDspComControlSpecificChannelUsed)
                    {
#if (DCM_BSWM_ENABLE == STD_ON)
                        BswM_Dcm_CommunicationMode_CurrentState(
                            Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel[iloop]
                                .DcmDspSpecificComMChannelId,
                            RequestedMode);
#else
                        Rte_DcmControlCommunicationMode(
                            Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel[iloop]
                                .DcmDspSpecificComMChannelId,
                            RequestedMode);
#endif
                    }
                }
            }
            if (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode)
            {
                for (iloop = 0; iloop < Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNodeNum; iloop++)
                {
                    if (TRUE
                        == Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode[iloop]
                               .DcmDspComControlSubNodeUsed)
                    {
#if (DCM_BSWM_ENABLE == STD_ON)
                        BswM_Dcm_CommunicationMode_CurrentState(
                            Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode[iloop]
                                .DcmDspComMSubNodeChannelId,
                            RequestedMode);
#else
                        Rte_DcmControlCommunicationMode(
                            Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode[iloop]
                                .DcmDspComMSubNodeChannelId,
                            RequestedMode);
#endif
                    }
                }
            }
        }
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/********************************/
/*************************************************************************/
/*
 * Brief               <UDS  0x28 service Get Request Mode>
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
static FUNC(void, DCM_CODE) DspInternalUDS0x28_0x00_0x03_SubFuction(uint8 ProtocolCtrlId, uint8 subFunc, uint8 comType)
{
    uint8 iloop;
    Dcm_CommunicationModeType RequestedMode;

    RequestedMode = DspInternalUDS0x28_0x00_0x03_GetReqMode(subFunc, comType);
    if ((NULL_PTR != Dcm_Cfg.pDcmDspCfg) && (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl))
    {
        if (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannel)
        {
            for (iloop = 0; iloop < Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannelNum; iloop++)
            {
                if (TRUE
                    == Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannel[iloop]
                           .DcmDspComControlAllChannelUsed)
                {
#if (DCM_BSWM_ENABLE == STD_ON)
                    BswM_Dcm_CommunicationMode_CurrentState(
                        Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannel[iloop].DcmDspComMChannelId,
                        RequestedMode);
#else
                    Rte_DcmControlCommunicationMode(
                        Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannel[iloop].DcmDspComMChannelId,
                        RequestedMode);
#endif
                }
            }
        }
        if ((NULL_PTR != Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow)
            && (NULL_PTR != Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId].pDcmDslConnection)
            && (NULL_PTR
                != Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId]
                       .pDcmDslConnection->pDcmDslMainConnection))
        {
#if (DCM_BSWM_ENABLE == STD_ON)
            BswM_Dcm_CommunicationMode_CurrentState(
                Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId]
                    .pDcmDslConnection->pDcmDslMainConnection->DcmDslProtocolComMChannelId,
                RequestedMode);
#else
            Rte_DcmControlCommunicationMode(
                Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId]
                    .pDcmDslConnection->pDcmDslMainConnection->DcmDslProtocolComMChannelId,
                RequestedMode);
#endif
        }
        if (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel)
        {
            for (iloop = 0; iloop < Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannelNum; iloop++)
            {
                if (TRUE
                    == Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel[iloop]
                           .DcmDspComControlSpecificChannelUsed)
                {
#if (DCM_BSWM_ENABLE == STD_ON)
                    BswM_Dcm_CommunicationMode_CurrentState(
                        Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel[iloop]
                            .DcmDspSpecificComMChannelId,
                        RequestedMode);
#else
                    Rte_DcmControlCommunicationMode(
                        Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel[iloop]
                            .DcmDspSpecificComMChannelId,
                        RequestedMode);
#endif
                }
            }
        }
        if (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode)
        {
            for (iloop = 0; iloop < Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNodeNum; iloop++)
            {
                if (TRUE
                    == Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode[iloop]
                           .DcmDspComControlSubNodeUsed)
                {
#if (DCM_BSWM_ENABLE == STD_ON)
                    BswM_Dcm_CommunicationMode_CurrentState(
                        Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode[iloop]
                            .DcmDspComMSubNodeChannelId,
                        RequestedMode);
#else
                    Rte_DcmControlCommunicationMode(
                        Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode[iloop]
                            .DcmDspComMSubNodeChannelId,
                        RequestedMode);
#endif
                }
            }
        }
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <UDS  0x28 service Get Request Mode>
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
static FUNC(Dcm_CommunicationModeType, DCM_CODE) DspInternalUDS0x28_0x04_0x05_GetReqMode(uint8 subFunc, uint8 comType)
{
    Dcm_CommunicationModeType RequestedMode = DCM_ENABLE_RX_TX_NORM;

    if ((subFunc == 0x04u) && (comType == 0x01u))
    {
        RequestedMode = DCM_ENABLE_RX_DISABLE_TX_NORM;
    }
    else if ((subFunc == 0x04u) && (comType == 0x02u))
    {
        RequestedMode = DCM_ENABLE_RX_DISABLE_TX_NM;
    }
    else if ((subFunc == 0x04u) && (comType == 0x03u))
    {
        RequestedMode = DCM_ENABLE_RX_DISABLE_TX_NORM_NM;
    }
    else if ((subFunc == 0x05u) && (comType == 0x01u))
    {
        RequestedMode = DCM_ENABLE_RX_TX_NORM;
    }
    else if ((subFunc == 0x05u) && (comType == 0x02u))
    {
        RequestedMode = DCM_ENABLE_RX_TX_NM;
    }
    else if ((subFunc == 0x05u) && (comType == 0x03u))
    {
        RequestedMode = DCM_ENABLE_RX_TX_NORM_NM;
    }
    else
    {
        /*idle*/
    }
    return RequestedMode;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <UDS  0x28 service Get Request Mode>
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
    DspInternalUDS0x28_0x04_0x05_SubFuction(uint16 Subnet, uint8 ProtocolCtrlId, uint8 subFunc, uint8 comType)
{
    uint8 iloop;
    boolean Find = FALSE;
    Dcm_CommunicationModeType RequestedMode;
    Std_ReturnType ret = E_OK;
    RequestedMode = DspInternalUDS0x28_0x04_0x05_GetReqMode(subFunc, comType);
    if ((Subnet == 0x00u)
        && ((NULL_PTR != Dcm_Cfg.pDcmDspCfg) && (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl)
            && (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannel)))
    {
        for (iloop = 0; iloop < Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannelNum; iloop++)
        {
            if (TRUE
                == Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannel[iloop]
                       .DcmDspComControlAllChannelUsed)
            {
#if (DCM_BSWM_ENABLE == STD_ON)
                BswM_Dcm_CommunicationMode_CurrentState(
                    Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannel[iloop].DcmDspComMChannelId,
                    RequestedMode);
#else
                Rte_DcmControlCommunicationMode(
                    Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlAllChannel[iloop].DcmDspComMChannelId,
                    RequestedMode);
#endif
            }
        }
    }
    if ((Subnet == 0x0Fu)
        && ((NULL_PTR != Dcm_Cfg.pDcmDslCfg) && (NULL_PTR != Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol)
            && (NULL_PTR != Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow)
            && (NULL_PTR != Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId].pDcmDslConnection)
            && (NULL_PTR
                != Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId]
                       .pDcmDslConnection->pDcmDslMainConnection)))
    {
#if (DCM_BSWM_ENABLE == STD_ON)
        BswM_Dcm_CommunicationMode_CurrentState(
            Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId]
                .pDcmDslConnection->pDcmDslMainConnection->DcmDslProtocolComMChannelId,
            RequestedMode);
#else
        Rte_DcmControlCommunicationMode(
            Dcm_Cfg.pDcmDslCfg->pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId]
                .pDcmDslConnection->pDcmDslMainConnection->DcmDslProtocolComMChannelId,
            RequestedMode);
#endif
    }
    if ((Subnet > 0x00u) && (Subnet < 0x0Fu))
    {
        if ((NULL_PTR != Dcm_Cfg.pDcmDspCfg) && (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl)
            && (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel))
        {
            for (iloop = 0;
                 (iloop < Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannelNum) && (Find == FALSE);
                 iloop++)
            {
                if ((TRUE
                     == Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel[iloop]
                            .DcmDspComControlSpecificChannelUsed)
                    && (Subnet
                        == Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel[iloop]
                               .DcmDspSubnetNumber))
                {
#if (DCM_BSWM_ENABLE == STD_ON)
                    BswM_Dcm_CommunicationMode_CurrentState(
                        Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel[iloop]
                            .DcmDspSpecificComMChannelId,
                        RequestedMode);
#else
                    Rte_DcmControlCommunicationMode(
                        Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSpecificChannel[iloop]
                            .DcmDspSpecificComMChannelId,
                        RequestedMode);
#endif
                    Find = TRUE;
                }
            }
        }
        if (Find == FALSE)
        {
            ret = E_NOT_OK;
        }
    }
    else
    {
        if ((NULL_PTR != Dcm_Cfg.pDcmDspCfg) && (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl)
            && (NULL_PTR != Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode))
        {
            for (iloop = 0;
                 (iloop < Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNodeNum) && (Find == FALSE);
                 iloop++)
            {
                if ((TRUE
                     == Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode->DcmDspComControlSubNodeUsed)
                    && (Subnet
                        == Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode[iloop]
                               .DcmDspComControlSubNodeId))
                {
#if (DCM_BSWM_ENABLE == STD_ON)
                    BswM_Dcm_CommunicationMode_CurrentState(
                        Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode[iloop]
                            .DcmDspComMSubNodeChannelId,
                        RequestedMode);
#else
                    Rte_DcmControlCommunicationMode(
                        Dcm_Cfg.pDcmDspCfg->pDcmDspComControl->DcmDspComControlSubNode[iloop]
                            .DcmDspComMSubNodeChannelId,
                        RequestedMode);
#endif
                    Find = TRUE;
                }
            }
        }
        if (Find == FALSE)
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
 * Brief               <UDS  0x28 service Get Request Mode>
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
    Dcm_UDS0x28_ConditionCheck(uint8 ProtocolCtrlId, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode)
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */
{
    uint8 MsgCtrlId;
    uint8 subFunc;
    uint8 iloop;
    Std_ReturnType ret = E_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    uint8 SidTabId;
    uint16 SidTabIndex;
    uint16 ServiceIndex;
    boolean Flag = FALSE;

    /*if the required protocol is configuted,get the index of runtime datum*/
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    /*session check,check whether the current session supports the request service*/
    ret = DsdInternal_SesCheck(ProtocolCtrlId, SID_COMMUNICATION_CONTROL);
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
        ret = DsdInternal_SecurityCheck(ProtocolCtrlId, SID_COMMUNICATION_CONTROL);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif
    /*check the massage length*/
    if (((E_OK == ret)) && (DCM_UDS_REQ_DATA_MINLENGTH > Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen))
    {
        /*the length of massage is not correct,send NRC 0x13*/
        *ErrorCode = DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT;
        ret = E_NOT_OK;
    }
    if (E_OK == ret)
    {
        /*get the sub-function */
        subFunc = Dcm_MsgCtrl[MsgCtrlId].Subfunction;
        SidTabId = (Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow)[ProtocolCtrlId].DcmDslServiceTableID;
        /*find SidTabId configuration position in the service configuration table*/
        for (SidTabIndex = 0; (SidTabIndex < Dcm_DsdCfg.DcmDsdServiceTable_Num) && (FALSE == Flag); SidTabIndex++)
        {
            if (SidTabId == ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex].DcmDsdSidTabId))
            {
                for (ServiceIndex = 0;
                     (ServiceIndex < (Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex].DcmDsdSidTab_ServiceNum)
                     && (FALSE == Flag);
                     ServiceIndex++)
                {
                    if ((0x28u
                         == ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex]
                                 .pDcmDsdService[ServiceIndex]
                                 .DcmDsdServiceId))
                        && ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex]
                                .pDcmDsdService[ServiceIndex]
                                .DcmDsdSubfuncAvial
                            == TRUE))
                    {
                        for (iloop = 0;
                             ((iloop < ((Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex]
                                            .pDcmDsdService[ServiceIndex]
                                            .DcmDsdSubService_Num))
                              && (Flag == FALSE));
                             iloop++)
                        {
                            if (subFunc
                                == (Dcm_DsdCfg.pDcmDsdServiceTable)[SidTabIndex]
                                       .pDcmDsdService[ServiceIndex]
                                       .DcmDsdSubService[iloop]
                                       .DcmDsdSubServiceId)
                            {
                                Flag = TRUE;
                            }
                        }
                    }
                }
            }
        }
        if (Flag == FALSE)
        {
            /*the required sub-function is not supported,send NRC 0x12*/
            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTED;
            ret = E_NOT_OK;
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <UDS  0x28 service>
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
Dcm_UDS0x28(
    Dcm_OpStatusType OpStatus,
    uint8 ProtocolCtrlId,
    P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, DCM_VAR) ErrorCode) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 MsgCtrlId;
    uint8 TxChannelCtrlIndex;
    uint8 TxChannelCfgIndex;
    uint8 subFunc;
    uint8 comType;
    uint32 Offset;
    Std_ReturnType ret;
    uint16 Subnet;

    DCM_UNUSED(OpStatus);
    /*if the required protocol is configuted,get the index of runtime datum*/
    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    /*get the communicationType*/
    comType = Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[2];
    /*get the sub-function */
    subFunc = Dcm_MsgCtrl[MsgCtrlId].Subfunction;

    ret = Dcm_UDS0x28_ConditionCheck(ProtocolCtrlId, ErrorCode);

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*session check,check whether the current session supports the request service*/
        ret = DsdInternal_SubSesCheck(ProtocolCtrlId, SID_COMMUNICATION_CONTROL);
        if (E_NOT_OK == ret)
        {
            /*the current session does not support the request sub service,send NRC = 0x7E*/
            *ErrorCode = DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION;
        }
    }
#endif

#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    if (E_OK == ret)
    {
        /*security check,check whether the current security supports the request service*/
        ret = DsdInternal_SubSecurityCheck(ProtocolCtrlId, SID_COMMUNICATION_CONTROL);
        if (E_NOT_OK == ret)
        {
            /*the current security does not support the request service,send NRC = 0x33*/
            *ErrorCode = DCM_E_SECURITYACCESSDENIED;
        }
    }
#endif
    /*check the massage length*/
    if ((E_OK == ret)
        && (((DCM_UDS0X28_REQ_DATA_MAXLENGTH != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
             && ((subFunc == 0x04u) || (subFunc == 0x05u)))
            || ((DCM_UDS0X28_REQ_DATA_MINLENGTH != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen) && (subFunc < 0x04u))
            || (((DCM_UDS0X28_REQ_DATA_MINLENGTH != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen)
                 || (DCM_UDS0X28_REQ_DATA_MAXLENGTH != Dcm_MsgCtrl[MsgCtrlId].MsgContext.ReqDataLen))
                && (subFunc > 0x05u))))
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
        if ((comType < COMTYPE_NORM) || (comType > COMTYPE_NORM_AND_NM))
        {
            /*communicationType is not supported,send NRC 0x31*/
            *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
            ret = E_NOT_OK;
        }
    }
    /*callback function make communicaiton control*/
    if (E_OK == ret)
    {
        if (subFunc < 0x04u)
        {
            DspInternalUDS0x28_0x00_0x03_SubFuction(ProtocolCtrlId, subFunc, comType);
        }
        else if ((subFunc == 0x04u) || (subFunc == 0x05u))
        {
            Subnet = (uint16)((uint16)((uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[3] << 8u)
                              | (uint16)Dcm_MsgCtrl[MsgCtrlId].MsgContext.pReqData[4]);
            if (E_NOT_OK == DspInternalUDS0x28_0x04_0x05_SubFuction(Subnet, ProtocolCtrlId, subFunc, comType))
            {
                /*NO DcmDspSubnetNumber Finded ,send NRC 0x31*/
                *ErrorCode = DCM_E_REQUESTOUTOFRANGE;
                ret = E_NOT_OK;
            }
        }
        else
        {
            /*idle*/
        }
    }
    if (E_OK == ret)
    {
        /* assemble positive response*/
        /*the processing is successful,assemble positive response*/
        TxChannelCtrlIndex = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
        TxChannelCfgIndex = Dcm_ChannelCtrl[TxChannelCtrlIndex].Dcm_ChannelCfgIndex;
        Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCfgIndex].offset;
        /* check tx data length */
        if ((0x02u) > (Dcm_DslCfg.pDcmChannelCfg[TxChannelCfgIndex].Dcm_DslBufferSize))
        {
            /*Pdu length is bigger than buffer size,ignore the request message */
            *ErrorCode = DCM_E_RESPONSETOOLONG;
            ret = E_NOT_OK;
        }
        else
        {
            SchM_Enter_Dcm(Dcm_Channel);
            Dcm_Channel[Offset] = 0x68;         /*response SID*/
            Dcm_Channel[Offset + 1u] = subFunc; /*echo of 0 - 6 bits of sub-function*/
            SchM_Exit_Dcm(Dcm_Channel);
            SchM_Enter_Dcm(Dcm_MsgCtrl);
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = 0x02;
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = 0x02;
            Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
            SchM_Exit_Dcm(Dcm_MsgCtrl);
            DsdInternal_ProcessingDone(ProtocolCtrlId);
        }
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
