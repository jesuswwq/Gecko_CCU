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

/*=======[I N C L U D E S]====================================================*/
#include "Dcm_Internal.h"

/******************************* Define ************************************/
#if ((STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED) && (DCM_DSP_ROUTINE_MAX_NUM > 0))
#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
VAR(Dcm_RoutineControlStateType, DCM_VAR_NOINIT)
Dcm_RoutineControlState[DCM_DSP_ROUTINE_MAX_NUM];
#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
#endif

/****************************** Implement***********************************/
/*************************************************************************/
/*
 * Brief               <The Dsp layer response to the confirmation ReProgram>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DspInternal_DcmConfirmForRePrg(uint8 ProtocolCtrlId)
{
    uint8 MsgCtrlId;
    uint8 TxChannelCtrlId;
    Std_ReturnType ret;
    uint8 iloop;
    Dcm_OpStatusType OpStatus = DCM_INITIAL;
    uint32 Offset;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    TxChannelCtrlId = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    ProgConditions.ProtocolId = ProtocolCtrlId;
    ProgConditions.Sid = Dcm_MsgCtrl[MsgCtrlId].SID;
    ProgConditions.SubFncId = Dcm_MsgCtrl[MsgCtrlId].Subfunction;
    ProgConditions.BootSuppressPosResponse = Dcm_MsgCtrl[MsgCtrlId].MsgContext.MsgAddInfo.SuppressPosResponse;

    /*clear ReProgramingRequest Flag*/
    ReProgramingRequest = FALSE;
    for (iloop = 0; iloop < Dcm_DspCfg.pDcm_DspSession->DcmDspSessionRow_Num; iloop++)
    {
        if ((Dcm_SesCtrl.Dcm_NewSes == Dcm_DspCfg.pDcm_DspSession->pDcmDspSessionRow[iloop].DcmDspSessionLevel)
            && (Dcm_DslCfg.pDcmDslProtocol->pDcmDslProtocolRow[ProtocolCtrlId].DcmSendRespPendOnTransToBoot == TRUE))
        {
            if ((Dcm_DspCfg.pDcm_DspSession->pDcmDspSessionRow[iloop].DcmDspSessionForBoot == DCM_OEM_BOOT)
                || (Dcm_DspCfg.pDcm_DspSession->pDcmDspSessionRow[iloop].DcmDspSessionForBoot == DCM_SYS_BOOT))
            {
                ret = Dcm_SetProgConditions(OpStatus, &ProgConditions);
                if (ret == E_OK)
                {
                    /* By this mode switch the DCM
                     * informs the BswM to jump to the bootloader.*/
                    Set_FunOff_Appjumpboot();//turn off ig...
                    (void)SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE);
                }
                else if (ret == DCM_E_PENDING)
                {
                    Dcm_MsgCtrl[MsgCtrlId].Dcm_OpStatus = DCM_PENDING;
                }
                else
                {
                    /*idle*/
                }
            }
            else if (
                (Dcm_DspCfg.pDcm_DspSession->pDcmDspSessionRow[iloop].DcmDspSessionForBoot == DCM_OEM_BOOT_RESPAPP)
                || (Dcm_DspCfg.pDcm_DspSession->pDcmDspSessionRow[iloop].DcmDspSessionForBoot == DCM_SYS_BOOT_RESPAPP))
            {
                Offset = (Dcm_DslCfg.pDcmChannelCfg)[TxChannelCtrlId].offset;
                SchM_Enter_Dcm(Dcm_Channel);
                Dcm_Channel[Offset] = 0x50;
                Dcm_Channel[Offset + 1u] = Dcm_SesCtrl.Dcm_NewSes;
                Dcm_Channel[Offset + 2u] =
                    (uint8)(Dcm_DspCfg.pDcm_DspSession->pDcmDspSessionRow[iloop].DcmDspSessionP2ServerMax >> 8u);
                Dcm_Channel[Offset + 3u] =
                    (uint8)(Dcm_DspCfg.pDcm_DspSession->pDcmDspSessionRow[iloop].DcmDspSessionP2ServerMax);
                Dcm_Channel[Offset + 4u] =
                    (uint8)((Dcm_DspCfg.pDcm_DspSession->pDcmDspSessionRow[iloop].DcmDspSessionP2StarServerMax) >> 8u);
                Dcm_Channel[Offset + 5u] =
                    (uint8)(Dcm_DspCfg.pDcm_DspSession->pDcmDspSessionRow[iloop].DcmDspSessionP2StarServerMax);
                SchM_Exit_Dcm(Dcm_Channel);
                SchM_Enter_Dcm(Dcm_MsgCtrl);
                Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResMaxDataLen = 6u;
                Dcm_MsgCtrl[MsgCtrlId].MsgContext.ResDataLen = 6u;
                Dcm_MsgCtrl[MsgCtrlId].MsgContext.pResData = &Dcm_Channel[Offset];
                Dcm_MsgCtrl[Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex].RspStyle = DCM_POS_RSP;
                SchM_Enter_Dcm(Dcm_ChannelCtrl);
                Dcm_ChannelCtrl[TxChannelCtrlId].Dcm_BufferCunrentPosition = 0;
                SchM_Exit_Dcm(Dcm_ChannelCtrl);
                if (Dcm_MsgCtrl[MsgCtrlId].MsgContext.MsgAddInfo.SuppressPosResponse == TRUE)
                {
                    Dcm_MsgCtrl[Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex].RspStyle = DCM_POS_RSP_SUPPRESS;
                }
                Dcm_MsgCtrl[MsgCtrlId].NRC = 0xFFu;
                SchM_Exit_Dcm(Dcm_MsgCtrl);
                DsdInternal_ProcessingDone(ProtocolCtrlId);
                ret = Dcm_SetProgConditions(OpStatus, &ProgConditions);
                if (ret == E_OK)
                {
                    break;
                }
                else if (ret == DCM_E_PENDING)
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
            else
            {
                /*idle*/
            }
        }
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#if ((STD_ON == DCM_SECURITY_FUNC_ENABLED) && ((STD_ON == DCM_UDS_SERVICE0X27_ENABLED)))
/*************************************************************************/
/*
 * Brief               <The Dsp layer response to the confirmation>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
/*************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DspInternal_DcmConfirmation_0x27(uint8 ProtocolCtrlId)
{
    P2CONST(Dcm_DspSecurityRowType, AUTOMATIC, DCM_CONST) pSecurityRow;
    uint8 SecCfgIndex;
    uint8 MsgCtrlId;
    Std_ReturnType ret;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;

    /*securityAccess service*/
    if ((0x27u == Dcm_MsgCtrl[MsgCtrlId].SID) && (DCM_NEG_RSP == Dcm_MsgCtrl[MsgCtrlId].RspStyle)
        && (DCM_E_GENERALREJECT == Dcm_MsgCtrl[MsgCtrlId].NRC))
    {
        /*confirmation to reject SecurityAccess service*/
        DslInternal_SetSecurityAccessStatus(DCM_SERVICE_IDLE);
    }
    if ((0x27u == Dcm_MsgCtrl[MsgCtrlId].SID)
        && ((DCM_POS_RSP == Dcm_MsgCtrl[MsgCtrlId].RspStyle)
            || (DCM_POS_RSP_SUPPRESS == Dcm_MsgCtrl[MsgCtrlId].RspStyle))
        && (DCM_SERVICE_KEY == Dcm_SecCtrl.Dcm_SecServiceState))
    {
        /*Compare key success*/
        DslInternal_SetSecurityLevel(Dcm_SecCtrl.Dcm_NewSec);
        DslInternal_SetSecurityAccessStatus(DCM_SERVICE_IDLE);
        ret = DslInternal_GetSecurityCfgBySecLevel(Dcm_SecCtrl.Dcm_ActiveSec, &SecCfgIndex);
        if (E_OK == ret)
        {
            SchM_Enter_Dcm(Dcm_SecCtrl);
            Dcm_SecCtrl.Dcm_SubfunctionForSeed = 0u;
            Dcm_SecCtrl.Dcm_RunDlyCtrl.Dcm_SecTimerState[SecCfgIndex] = DCM_SECTIMER_OFF;
            Dcm_SecCtrl.Dcm_FalseAcessCount[SecCfgIndex] = 0u;
            SchM_Exit_Dcm(Dcm_SecCtrl);
            pSecurityRow = &(Dcm_DspCfg.pDcm_DspSecurity->pDcm_DspSecurityRow[SecCfgIndex]);
            if (pSecurityRow != NULL_PTR)
            {
                if ((TRUE == pSecurityRow->DcmDspSecurityAttemptCounterEnabled)
                    && ((
                        (USE_ASYNCH_FNC == pSecurityRow->DcmDspSecurityUsePort)
                        || (USE_ASYNCH_CLIENT_SERVER == pSecurityRow->DcmDspSecurityUsePort))))
                {
                    if (pSecurityRow->Dcm_SetSecurityAttemptCounterFnc != NULL_PTR)
                    {
                        (void)pSecurityRow->Dcm_SetSecurityAttemptCounterFnc(
                            Dcm_SecCtrl.Dcm_OpStatus,
                            Dcm_SecCtrl.Dcm_FalseAcessCount[SecCfgIndex]);
                    }
                }
            }
        }
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/*************************************************************************/
/*
 * Brief               <The Dsp layer response to the confirmation>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:The corresponding protocol control block ID number>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
/*************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DspInternal_DcmConfirmation(uint8 ProtocolCtrlId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 MsgCtrlId;
    uint8 RxChannelCtrlId;
    uint8 TxChannelCtrlId;
    Std_ReturnType ret;
    uint8 iloop;
    Dcm_OpStatusType OpStatus = DCM_INITIAL;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    RxChannelCtrlId = Dcm_MsgCtrl[MsgCtrlId].Dcm_RxCtrlChannelIndex;
    TxChannelCtrlId = Dcm_MsgCtrl[MsgCtrlId].Dcm_TxCtrlChannelIndex;
    /*NRC = 0x78 respond to the confirmation process*/
    if (DCM_E_RESPONSE_PENDING == (Dcm_MsgCtrl[MsgCtrlId].NRC))
    {
        /*Nrc=0x78,response to confirmation*/
        if (ReProgramingRequest == TRUE)
        {
            DspInternal_DcmConfirmForRePrg(ProtocolCtrlId);
        }
        SchM_Enter_Dcm(Dcm_ChannelCtrl);
        Dcm_ChannelCtrl[RxChannelCtrlId].Dcm_ChannelRxState = DCM_CH_OCCUPIED;
        Dcm_ChannelCtrl[TxChannelCtrlId].Dcm_ChannelTxState = DCM_CH_OCCUPIED;
        Dcm_ChannelCtrl[TxChannelCtrlId].Dcm_BufferCunrentPosition = 0;
        Dcm_ChannelCtrl[TxChannelCtrlId].Dcm_BufferErasePosition = 0;
        SchM_Exit_Dcm(Dcm_ChannelCtrl);
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlId].NRC = 0xFFu;
        Dcm_MsgCtrl[MsgCtrlId].SendFlag = FALSE;
        Dcm_MsgCtrl[MsgCtrlId].RspStyle = DCM_POS_RSP;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_MsgState = DCM_MSG_PROCESSED;
        /*restart P2*Timer*/
        Dcm_MsgCtrl[MsgCtrlId].Dcm_P2Ctrl.PendingNum++;
        Dcm_ResetTime(&Dcm_MsgCtrl[MsgCtrlId].Dcm_P2Ctrl.Dcm_P2CurTimer);
        Dcm_MsgCtrl[MsgCtrlId].Dcm_P2Ctrl.Dcm_P2ExpiredTimer = Dcm_ProtocolCtrl[ProtocolCtrlId].P2StarServerMax;
        Dcm_MsgCtrl[MsgCtrlId].Dcm_P2Ctrl.Dcm_P2State = DCM_P2TIMER_ON;
        SchM_Exit_Dcm(Dcm_MsgCtrl);
    }
    else
    {
#if ((STD_ON == DCM_SECURITY_FUNC_ENABLED) && ((STD_ON == DCM_UDS_SERVICE0X27_ENABLED)))
        DspInternal_DcmConfirmation_0x27(ProtocolCtrlId);
#endif
#if ((STD_ON == DCM_SESSION_FUNC_ENABLED) && ((STD_ON == DCM_UDS_SERVICE0X10_ENABLED)))
        /*session control sevice confirmation*/
        if (((DCM_POS_RSP == Dcm_MsgCtrl[MsgCtrlId].RspStyle)
             || (DCM_POS_RSP_SUPPRESS == Dcm_MsgCtrl[MsgCtrlId].RspStyle))
            && (0x10u == Dcm_MsgCtrl[MsgCtrlId].SID))
        {
            for (iloop = 0; iloop < Dcm_DspCfg.pDcm_DspSession->DcmDspSessionRow_Num; iloop++)
            {
                if (Dcm_SesCtrl.Dcm_NewSes == Dcm_DspCfg.pDcm_DspSession->pDcmDspSessionRow[iloop].DcmDspSessionLevel)
                {
                    if ((Dcm_DspCfg.pDcm_DspSession->pDcmDspSessionRow[iloop].DcmDspSessionForBoot
                         == DCM_SYS_BOOT_RESPAPP)
                        || (Dcm_DspCfg.pDcm_DspSession->pDcmDspSessionRow[iloop].DcmDspSessionForBoot
                            == DCM_OEM_BOOT_RESPAPP))
                    {
                        ret = Dcm_SetProgConditions(OpStatus, &ProgConditions);
                        if (ret == E_OK)
                        {
                            /* By this mode switch the DCM informs
                             * the BswM to jump to the bootloader.*/
                            (void)SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE);
                        }
                        else if (ret == DCM_E_PENDING)
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
                }
            }
            /*Uds 0x10 service*/
            DslInternal_SesRefresh(Dcm_SesCtrl.Dcm_NewSes);
        }
#endif
#if (STD_ON == DCM_DSP_ECU_RESET_FUNC_ENABLED)
        if (((DCM_POS_RSP == Dcm_MsgCtrl[MsgCtrlId].RspStyle)
             || (DCM_POS_RSP_SUPPRESS == Dcm_MsgCtrl[MsgCtrlId].RspStyle))
            && (0x11u == Dcm_MsgCtrl[MsgCtrlId].SID))
        {
            if (TRUE == gAppl_UpdataOK_ResponseFlag)
            {
                gAppl_UpdataOK_ResponseFlag = FALSE; /*clear app updata flag*/
                DslInternal_SesRefresh(DCM_DEFAULT_SESSION);
            }
            else
            {
                /*confirm to EcuReset service,call Mcu_PerformReset trigger reset*/
                (void)SchM_Switch_DcmEcuReset(RTE_MODE_DcmEcuReset_EXECUTE);
            }
        }
#endif
#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
        if (Dcm_PageBufferData.TotalSize != 0UL)
        {
            DslInternal_InitPageBuffer();
        }
#endif
        /*For the realization of the various sub-function,
         * the function code needs to be added here.*/
        DslInternal_ResetResource(ProtocolCtrlId);
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/****************************************************************************/
/*************************************************************************/
/*
 * Brief               <Init Routine States>
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
#if ((STD_ON == DCM_DSP_ROUTINE_FUNC_ENABLED) && (DCM_DSP_ROUTINE_MAX_NUM > 0))
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) Dsp_InitRoutineStates(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 index;
    SchM_Enter_Dcm(Dcm_RoutineControlState);
    for (index = 0; index < DCM_DSP_ROUTINE_MAX_NUM; index++)
    {
        Dcm_RoutineControlState[index] = DCM_DSP_ROUTINE_INIT;
    }
    SchM_Exit_Dcm(Dcm_RoutineControlState);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif

/*************************************************************************/
/*
 * Brief               <Uds SubServices Check>
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
FUNC(Std_ReturnType, DCM_CODE) Dcm_UdsSubServicesCheck(uint8 ProtocolCtrlId)
{
    uint16 SidTabCfgIndex;
    uint16 SidTabServiceCfgIndex;
    uint8 MsgCtrlIndexx;
    uint16 SubServieCfgIndex;
    uint8 Sid;
    Std_ReturnType ret;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    Sid = Dcm_MsgCtrl[MsgCtrlIndexx].SID;

    ret = DsdInternal_SearchSidTabServiceIndex(Sid, ProtocolCtrlId, &SidTabCfgIndex, &SidTabServiceCfgIndex);

    if (E_OK == ret)
    {
        ret = DsdInternal_SearchSidTabSubServiceIndex(
            ProtocolCtrlId,
            SidTabCfgIndex,
            SidTabServiceCfgIndex,
            &SubServieCfgIndex);
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#if (STD_ON == DCM_PAGEDBUFFER_ENABLED)
/*************************************************************************/
/*
 * Brief               <Dcm  Update  Page>
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
FUNC(void, DCM_CODE) DspInternal_DcmUpdatePage(uint8 ProtocolCtrlId)
{
    SchM_Enter_Dcm(Dcm_PageBufferData);
    Dcm_PageBufferData.PageTxOK = TRUE;
    Dcm_PageBufferData.ThisPageTxSize = 0;
    Dcm_ResetTime(&Dcm_PageBufferData.CurTimer);
    Dcm_PageBufferData.TimerStart = TRUE;
    Dcm_PageBufferData.ExpiredTimer = DCM_PAGEBUFFER_TIMEOUTVALUE;
    SchM_Exit_Dcm(Dcm_PageBufferData);
    /*Start P2Timer Timer*/
    DslInternal_P2ServerStart(ProtocolCtrlId);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
#endif
