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

/********************************public functions******************************/
/*************************************************************************/
/*
 * Brief               <Start P2Timer>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:Protocol control block index number.>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_P2ServerStart(uint8 ProtocolCtrlId)
{
    uint8 MsgCtrlIndexx;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    if (DCM_P2TIMER_OFF == Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_P2Ctrl.Dcm_P2State)
    {
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_P2Ctrl.PendingNum = 0u;
        Dcm_ResetTime(&Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_P2Ctrl.Dcm_P2CurTimer);
        Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_P2Ctrl.Dcm_P2ExpiredTimer = Dcm_ProtocolCtrl[ProtocolCtrlId].P2ServerMax;
        Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_P2Ctrl.Dcm_P2State = DCM_P2TIMER_ON;
        SchM_Exit_Dcm(Dcm_MsgCtrl);
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <stop P2timer>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:Protocol control block index number.>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_P2ServerStop(uint8 ProtocolCtrlId)
{
    uint8 MsgCtrlIndexx;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    if (DCM_P2TIMER_ON == Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_P2Ctrl.Dcm_P2State)
    {
        SchM_Enter_Dcm(Dcm_MsgCtrl);
        Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_P2Ctrl.Dcm_P2State = DCM_P2TIMER_OFF;
        SchM_Exit_Dcm(Dcm_MsgCtrl);
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <P2Timer timeout processing>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:Protocol control block index number.>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_P2ServerTimeout(uint8 ProtocolCtrlId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 PendingNumx;
    uint8 MsgCtrlId;
    uint8 PendingMaxTimes;

    MsgCtrlId = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    PendingMaxTimes = Dcm_DslCfg.pDcmDslDiagRespCfg->DcmDslDiagRespMaxNumRespPend;
    PendingNumx = Dcm_MsgCtrl[MsgCtrlId].Dcm_P2Ctrl.PendingNum;
    if ((PendingNumx < PendingMaxTimes) || (PendingMaxTimes == 0u))
    {
        /*Send Nrc=0x78*/
        DsdInternal_SetNrc(ProtocolCtrlId, DCM_E_RESPONSE_PENDING);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
    }
    else
    {
        /*Send Nrc=0x10*/
        DsdInternal_SetNrc(ProtocolCtrlId, DCM_E_GENERALREJECT);
        DsdInternal_ProcessingDone(ProtocolCtrlId);
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <Judgment P2Timer run time is more than P2ServerMin>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:Protocol control block index number.>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
FUNC(Std_ReturnType, DCM_CODE) DslInternal_MinIsLargerThanP2Server(uint8 ProtocolCtrlId)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    uint8 MsgCtrlIndexx;
    uint32 P2ServerMinx;
    uint32 OldTimer;
    uint32 Timer;
    Std_ReturnType ret = E_OK;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    OldTimer = Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_P2Ctrl.Dcm_P2CurTimer;
    Dcm_GetTimeSpan(OldTimer, &Timer);
    P2ServerMinx = Dcm_ProtocolCtrl[ProtocolCtrlId].P2ServerMin;
    if (Timer < P2ServerMinx)
    {
        ret = E_NOT_OK;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
/* PRQA S 1532++ */ /* MISRA Rule 8.7 */
FUNC(Std_ReturnType, DCM_CODE) DslInternal_MaxIsLargerThanP2Server(uint8 ProtocolCtrlId)
/* PRQA S 1532-- */ /* MISRA Rule 8.7 */
{
    uint8 MsgCtrlIndexx;
    uint32 P2ServerMaxx;
    uint32 OldTimer;
    uint32 Timer;
    Std_ReturnType ret = E_OK;

    MsgCtrlIndexx = Dcm_ProtocolCtrl[ProtocolCtrlId].MsgCtrlIndex;
    OldTimer = Dcm_MsgCtrl[MsgCtrlIndexx].Dcm_P2Ctrl.Dcm_P2CurTimer;
    Dcm_GetTimeSpan(OldTimer, &Timer);
    P2ServerMaxx = Dcm_ProtocolCtrl[ProtocolCtrlId].P2ServerMax;
    if (Timer < P2ServerMaxx)
    {
        ret = E_NOT_OK;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
