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

#ifndef DCMDSL_SECURITYMANAGE_H
#define DCMDSL_SECURITYMANAGE_H
/*============================================================================*/

/****************************** references *********************************/
#include "Dcm_Types.h"

#if (STD_ON == DCM_SECURITY_FUNC_ENABLED)
/****************************** declarations *********************************/
/**********************************************************************
 *************Security level management data structure****************
 *********************************************************************/
typedef enum
{
    DCM_SECTIMER_ON = 1u, /*Security level timer "on" state*/
    DCM_SECTIMER_OFF = 0u /*Security level timer "oFF" state*/
} Dcm_SecTimerStateType;

typedef struct
{
    uint32 Dcm_SecCurTimer[DCM_SECURITY_NUM];     /*Security level timer curent Timer*/
    uint32 Dcm_SecExpiredTimer[DCM_SECURITY_NUM]; /*Security level timer timeout Timer*/
    Dcm_SecTimerStateType Dcm_SecTimerState[DCM_SECURITY_NUM];
} Dcm_SecTimerCtrlType;

typedef enum
{
    DCM_SERVICE_IDLE = 0u, /* "Idle" */
    DCM_SERVICE_SEED = 1u, /* After "receiving seed"*/
    DCM_SERVICE_KEY = 2u   /* After "comparing key" */
} Dcm_SecServiceStateType;

typedef struct
{
    uint8 Dcm_SubfunctionForSeed; /*Request seed sub-functions.*/
    uint8 Dcm_FalseAcessCount[DCM_SECURITY_NUM];
    /*the number of Compare key failures and consecutive Request Seed*/
    Dcm_SecLevelType Dcm_ActiveSec;              /*DCM module current level of security*/
    Dcm_SecLevelType Dcm_NewSec;                 /*DCM module to be changed security level*/
    Dcm_SecServiceStateType Dcm_SecServiceState; /*Security level change process status*/
    Dcm_SecTimerCtrlType Dcm_RunDlyCtrl;
    /*When you reach the number of failure,the delay access control block*/
    Dcm_OpStatusType Dcm_OpStatus;
    uint8 Dcm_SecFlag;
    uint8 Dcm_SecCfgIndex;
    uint16 Dcm_MaxReadoutTime;
} Dcm_SecCtrlType;

#define DCM_SEC_RESUMECALL_MASK 0x01u
#define DCM_SEC_CALL_OVER_MASK  0x02u
/********************************************************
 ******************resource statement********************
 ********************************************************/

extern VAR(Dcm_SecCtrlType, DCM_VAR_NOINIT) Dcm_SecCtrl;
/*Security level management control block*/

/*************************************************************************/
/*
 * Brief               <initial of Security level control block>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <Dcm_Init()>
 */
/*************************************************************************/

extern FUNC(void, DCM_CODE) DslInternal_InitSecCtrl(void);

/*************************************************************************/
/*
 * Brief               <Setting the security level>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <NewSec:To be changed the security level>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/

extern FUNC(void, DCM_CODE) DslInternal_SetSecurityLevel(Dcm_SecLevelType NewSec);

/*************************************************************************/
/*
 * Brief               <Set SecurityAccess service process ,receives seed/key status>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <Status:State to be modified>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/

extern FUNC(void, DCM_CODE) DslInternal_SetSecurityAccessStatus(Dcm_SecServiceStateType Status);

extern FUNC(Std_ReturnType, DCM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    DslInternal_GetSecurityCfgBySecLevel(Dcm_SecLevelType Dcm_SecLevel, P2VAR(uint8, AUTOMATIC, AUTOMATIC) SecCfgIndex);
/* PRQA S 3432-- */     /* MISRA Rule 20.7 */

#endif

#endif /* DCMDSL_SECURITYMANAGE_H_ */
