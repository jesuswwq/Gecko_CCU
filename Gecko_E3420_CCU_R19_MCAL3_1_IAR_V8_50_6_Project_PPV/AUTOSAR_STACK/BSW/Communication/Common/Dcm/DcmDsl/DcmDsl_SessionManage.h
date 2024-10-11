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

#ifndef DCMDSL_SESSIONMANAGE_H
#define DCMDSL_SESSIONMANAGE_H

/****************************** references *********************************/
#include "Dcm_Types.h"

#if (STD_ON == DCM_SESSION_FUNC_ENABLED)
/****************************** declarations *********************************/
/*****************************************************************
 **********Session Management sub-function data structure*******
 *****************************************************************/
typedef enum
{
    DCM_S3TIMER_ON = 0,
    DCM_S3TIMER_OFF = 1
} Dcm_S3StateType;

typedef struct
{
    uint32 Dcm_S3CurTimer;
    uint32 Dcm_S3ExpiredTimer;   /*S3Timer,timeout Timer*/
    Dcm_S3StateType Dcm_S3State; /*S3timer status */
} Dcm_S3CtrlType;

typedef enum
{
    DCM_SESSION_DEFAULT = 0,  /*default session*/
    DCM_SESSION_UNDEFAULT = 1 /*undefault session*/
} Dcm_SesStateType;

typedef struct
{
    Dcm_SesCtrlType Dcm_ActiveSes; /*Module current session-state values;*/
    Dcm_SesCtrlType Dcm_NewSes;
    /*The session control value of the module to be changed;*/
    Dcm_S3CtrlType Dcm_S3Ctrl;         /*S3Timer control block*/
    Dcm_SesStateType Dcm_SessionState; /*DCM module session state*/
} Dcm_SesCtrlCBType;

/********************************************************
 *******************resource statement*******************
 ********************************************************/

extern VAR(Dcm_SesCtrlCBType, DCM_VAR_NOINIT) Dcm_SesCtrl; /*Session management control block*/

/*******************************************************************************
 **************Session Management sub-function function declaration*************
 *******************************************************************************/
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

extern FUNC(void, DCM_CODE) DslInternal_InitSesCtrl(void);

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

extern FUNC(void, DCM_CODE) DslInternal_S3ServerStart(void);

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

extern FUNC(void, DCM_CODE) DslInternal_S3ServerStop(void);

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

extern FUNC(void, DCM_CODE) DslInternal_S3ServerTimeout(void);

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

extern FUNC(void, DCM_CODE) DslInternal_SesRefresh(Dcm_SesCtrlType NewSes);

#endif

#endif /* DCMDSL_SESSIONMANAGE_H_ */
