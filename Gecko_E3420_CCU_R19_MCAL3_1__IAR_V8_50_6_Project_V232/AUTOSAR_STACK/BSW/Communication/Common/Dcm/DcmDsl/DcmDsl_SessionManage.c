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
#if (DCM_BSWM_ENABLE == STD_ON)
#include "BswM_Dcm.h"
#endif
#include "UDS.h"
#include "ComM_Dcm.h"
#if (STD_ON == DCM_SESSION_FUNC_ENABLED)

/********************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_SetSesCtrlType(Dcm_SesCtrlType NewSes);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*****************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DslInternal_GetSesTimingValues(
    Dcm_SesCtrlType NewSes,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, DCM_VAR) P2ServerTimer,
    P2VAR(uint32, AUTOMATIC, DCM_VAR) P2StarServerTimer);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*****************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_SetSesTimingValues(Dcm_SesCtrlType NewSes);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*****************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_DefaultToDefault(Dcm_SesCtrlType NewSes);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*****************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_DefaultToUndefault(Dcm_SesCtrlType NewSes);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*****************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_UndefaultToUndefault(Dcm_SesCtrlType NewSes);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*****************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_UndefaultTodefault(Dcm_SesCtrlType NewSes);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*****************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_SesTranslation(Dcm_SesCtrlType NewSes);
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/********************************************************
 **********************resource define*******************
 ********************************************************/
#define DCM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"
VAR(Dcm_SesCtrlCBType, DCM_VAR_NOINIT) Dcm_SesCtrl; /*Session management control block*/
#define DCM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <The initialization of session management control block>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_InitSesCtrl(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    SchM_Enter_Dcm(Dcm_SesCtrl);
    Dcm_SesCtrl.Dcm_ActiveSes = DCM_DEFAULT_SESSION;
    Dcm_SesCtrl.Dcm_NewSes = DCM_DEFAULT_SESSION;
    Dcm_SesCtrl.Dcm_S3Ctrl.Dcm_S3CurTimer = DCM_INVALID_UINT32;
    Dcm_SesCtrl.Dcm_S3Ctrl.Dcm_S3ExpiredTimer = DCM_INVALID_UINT32;
    Dcm_SesCtrl.Dcm_S3Ctrl.Dcm_S3State = DCM_S3TIMER_OFF;
    Dcm_SesCtrl.Dcm_SessionState = DCM_SESSION_DEFAULT;
    SchM_Exit_Dcm(Dcm_SesCtrl);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <start S3Timer>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_S3ServerStart(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    SchM_Enter_Dcm(Dcm_SesCtrl);
    Dcm_ResetTime(&Dcm_SesCtrl.Dcm_S3Ctrl.Dcm_S3CurTimer);
    Dcm_SesCtrl.Dcm_S3Ctrl.Dcm_S3ExpiredTimer = 5000UL; /* ms converted to tick */
    Dcm_SesCtrl.Dcm_S3Ctrl.Dcm_S3State = DCM_S3TIMER_ON;
    SchM_Exit_Dcm(Dcm_SesCtrl);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <stop S3Timer>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_S3ServerStop(void)
{
    SchM_Enter_Dcm(Dcm_SesCtrl);
    Dcm_SesCtrl.Dcm_S3Ctrl.Dcm_S3State = DCM_S3TIMER_OFF;
    SchM_Exit_Dcm(Dcm_SesCtrl);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <timeout of S3Timer>
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
FUNC(void, DCM_CODE) DslInternal_S3ServerTimeout(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    SchM_Enter_Dcm(Dcm_SesCtrl);
    Dcm_SesCtrl.Dcm_NewSes = DCM_DEFAULT_SESSION;
    SchM_Exit_Dcm(Dcm_SesCtrl);
    DslInternal_SesRefresh(Dcm_SesCtrl.Dcm_NewSes);
    /***stop S3Timer***/
    DslInternal_S3ServerStop();
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <Refresh session>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <NewSes:Session control state to be refreshed>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
FUNC(void, DCM_CODE) DslInternal_SesRefresh(Dcm_SesCtrlType NewSes)
{
    DslInternal_SesTranslation(NewSes);
#if (STD_ON == DCM_UDS_SERVICE0X2A_ENABLED)
    /*check 2A is supported in NewSes*/
    Dcm_UDS0x2ACheckNewSession(NewSes);
#endif
#if ((DCM_DSP_DID_FOR_2F_NUM > 0) && (STD_ON == DCM_UDS_SERVICE0X2F_ENABLED))
    /*check 2F is supported in NewSes*/
    Dcm_UDS0x2FCheckNewSession(NewSes);
#endif
#if (STD_ON == DCM_UDS_SERVICE0X28_ENABLED)
    /*check 28 is supported in NewSes*/
    DspInternalUDS0x28_CheckNewSes(NewSes);
#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/************************internal functions*****************************/
/*************************************************************************/
/*
 * Brief               <Set the session control state>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <NewSes:the Latest session status>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_SetSesCtrlType(Dcm_SesCtrlType NewSes)
{
    SchM_Enter_Dcm(Dcm_SesCtrl);
    Dcm_SesCtrl.Dcm_ActiveSes = NewSes;
    SchM_Exit_Dcm(Dcm_SesCtrl);

    SchM_Enter_Dcm(Dcm_MkCtrl);
    Dcm_MkCtrl.Dcm_ActiveSes = NewSes;
    SchM_Exit_Dcm(Dcm_MkCtrl);
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"
/*************************************************************************/
/*
 * Brief               <The set NewSes corresponding configuration session time parameters>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <NewSes:the Latest session status>
 * Param-Name[out]     <(*P2ServerTimer):P2ServerTimer which corresponding to NewSes
 *                      (*P2StarServerTimer):P2StarServerTimer which corresponding to NewSes>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(Std_ReturnType, DCM_CODE) DslInternal_GetSesTimingValues(
    Dcm_SesCtrlType NewSes,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, DCM_VAR) P2ServerTimer,
    P2VAR(uint32, AUTOMATIC, DCM_VAR) P2StarServerTimer)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint8 Number;
    uint8 Index;
    boolean Flag;
    P2CONST(Dcm_DspSessionRowType, AUTOMATIC, DCM_CONST) pDspSessionRow;
    Std_ReturnType ret = E_OK;

    if ((NULL_PTR != P2ServerTimer) && (NULL_PTR != P2StarServerTimer))
    {
        pDspSessionRow = (Dcm_DspCfg.pDcm_DspSession)->pDcmDspSessionRow;
        Number = (Dcm_DspCfg.pDcm_DspSession)->DcmDspSessionRow_Num;
        Flag = FALSE;
        for (Index = 0; (Index < Number) && (FALSE == Flag); Index++)
        {
            if (NewSes == (pDspSessionRow[Index].DcmDspSessionLevel))
            {
                Flag = TRUE;
            }
        }
        if (FALSE == Flag)
        {
            /*do not configured DcmDspSessionRow container ,or
             * do not find the corresponding NewSes in DcmDspSessionRows*/
            ret = E_NOT_OK;
        }
        else
        {
            *P2ServerTimer = (uint32)pDspSessionRow[Index - 1u].DcmDspSessionP2ServerMax;
            *P2StarServerTimer = (uint32)pDspSessionRow[Index - 1u].DcmDspSessionP2StarServerMax;
        }
    }
    else
    {
        ret = E_NOT_OK;
    }
    return ret;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <Set the module support each protocol
 * link layer parameters ,which is in protocol control block>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <NewSes:the Latest session status>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_SetSesTimingValues(Dcm_SesCtrlType NewSes)
{
    uint32 P2ServerTimer;
    uint32 P2StarServerTimer;
    Std_ReturnType ret;

    /*Get the new session configuration corresponding to the time parameters of Dsp module*/
    ret = DslInternal_GetSesTimingValues(NewSes, &P2ServerTimer, &P2StarServerTimer);
    if (E_OK == ret)
    {
        /*set all protocols which are configured,corresponding
         * link layer Time parameters of Dsl module*/
        DslInternal_SetProtocolLinkLayerTimer(P2ServerTimer, P2StarServerTimer);
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <session change from default to default>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <NewSes:the Latest session status>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_DefaultToDefault(Dcm_SesCtrlType NewSes)
{
    DslInternal_SetSesCtrlType(NewSes);

    DslInternal_SetSesTimingValues(NewSes);
    /************************************************************
     * The session state from the default to the default,
     * specific needs to be done temporarily unclear, to be added
     ************************************************************/

#if DCM_DELAY_COMM_INACTIVE
    if (DCM_S3TIMER_ON == Dcm_SesCtrl.Dcm_S3Ctrl.Dcm_S3State)
    {
        /*Notice ComM exit "FULL Communication"*/
        ComM_DCM_InactiveDiagnostic(Dcm_MkCtrl.Dcm_ActiveNetwork);
        SchM_Enter_Dcm(Dcm_MkCtrl);
        Dcm_MkCtrl.Dcm_ActiveNetwork = DCM_INVALID_UINT8;
        SchM_Exit_Dcm(Dcm_MkCtrl);
    }
#endif
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <session change from default to undefault>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <NewSes:the Latest session status>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_DefaultToUndefault(Dcm_SesCtrlType NewSes)
{
    NetworkHandleType NetworkChannel;
    uint8 Index;
    NetworkChannel = Dcm_MkCtrl.Dcm_ActiveNetwork;

    SchM_Enter_Dcm(Dcm_SesCtrl);
    Dcm_SesCtrl.Dcm_SessionState = DCM_SESSION_UNDEFAULT;
    SchM_Exit_Dcm(Dcm_SesCtrl);

    DslInternal_SetSesCtrlType(NewSes);
    DslInternal_SetSesTimingValues(NewSes);
    /* Notice Comm module into "Full Communication" */
    for (Index = 0; Index < DCM_MAINCONNECTION_NUM; Index++)
    {
        if ((DCM_COMM_ACTIVE == Dcm_CommCtrl[Index].Dcm_ActiveDiagnostic)
            && (NetworkChannel == Dcm_CommCtrl[Index].DcmDslProtocolComMChannelId))
        {
            ComM_DCM_ActiveDiagnostic(NetworkChannel);
        }
    }
    /************************************************************
     * The session state from the default to the undefault,
     * specific needs to be done temporarily unclear, to be added
     ************************************************************/
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <session change from undefault to undefault>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <NewSes:the Latest session status>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_UndefaultToUndefault(Dcm_SesCtrlType NewSes)
{
    DslInternal_SetSesCtrlType(NewSes);
    DslInternal_SetSesTimingValues(NewSes);
#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    DslInternal_SetSecurityLevel(DCM_SEC_LEV_LOCKED);
    DslInternal_SetSecurityAccessStatus(DCM_SERVICE_IDLE);
#endif
    /************************************************************
     * The session state from the undefault to the undefault,
     * specific needs to be done temporarily unclear, to be added
     ************************************************************/
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <session change from undefault to default>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <NewSes:the Latest session status>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_UndefaultTodefault(Dcm_SesCtrlType NewSes)
{
    NetworkHandleType NetworkChannel;

    NetworkChannel = Dcm_MkCtrl.Dcm_ActiveNetwork;

    SchM_Enter_Dcm(Dcm_SesCtrl);
    Dcm_SesCtrl.Dcm_SessionState = DCM_SESSION_DEFAULT;
    SchM_Exit_Dcm(Dcm_SesCtrl);

    DslInternal_SetSesCtrlType(NewSes);
    DslInternal_SetSesTimingValues(NewSes);

#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
    DslInternal_SetSecurityLevel(DCM_SEC_LEV_LOCKED);
    DslInternal_SetSecurityAccessStatus(DCM_SERVICE_IDLE);
#endif

#if ((STD_ON == DCM_UDS_FUNC_ENABLED) && (STD_ON == DCM_UDS_SERVICE0X85_ENABLED))
    /*The update of the DTC status will be re-enabled*/
    Rte_EnableAllDtcsRecord();
#endif

    /*Notice Comm Module exit "Full Communication"*/
    ComM_DCM_InactiveDiagnostic(NetworkChannel);
    /************************************************************
     * The session state from the undefault to the default,
     * specific needs to be done temporarily unclear, to be added
     ************************************************************/
    /*this is add for FOTA,when download is break,notifi FOTA*/
    (void)DslInternal_ProtocolStop(Dcm_MkCtrl.Dcm_ActiveProtocolCfgCtrlId);

    CheckRoutineFlag = FALSE;
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

/*************************************************************************/
/*
 * Brief               <When the session is changed, the specific processing>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <NewSes:the Latest session status>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/
#define DCM_START_SEC_CODE
#include "Dcm_MemMap.h"
static FUNC(void, DCM_CODE) DslInternal_SesTranslation(Dcm_SesCtrlType NewSes)
{

#if (STD_ON == DCM_UDS_SERVICE0X86_ENABLED)
    Dcm_UDS0x86_SesTranslation(NewSes);
#endif

    DslInternal_InitDspProgramInfo();
    if (DCM_SESSION_DEFAULT == Dcm_SesCtrl.Dcm_SessionState)
    {
        if (DCM_DEFAULT_SESSION == NewSes)
        {
            /*from the default session to the default session */
            DslInternal_DefaultToDefault(NewSes);
        }
        else
        {
            /*from the default session to the undefault session */
            DslInternal_DefaultToUndefault(NewSes);
        }
    }
    else
    {
        if (DCM_DEFAULT_SESSION == NewSes)
        {
            /*from the undefault session to the default session */
            DslInternal_UndefaultTodefault(NewSes);
        }
        else
        {
            /*from the undefault session to the undefault session */
            DslInternal_UndefaultToUndefault(NewSes);
        }
    }
}
#define DCM_STOP_SEC_CODE
#include "Dcm_MemMap.h"

#endif
