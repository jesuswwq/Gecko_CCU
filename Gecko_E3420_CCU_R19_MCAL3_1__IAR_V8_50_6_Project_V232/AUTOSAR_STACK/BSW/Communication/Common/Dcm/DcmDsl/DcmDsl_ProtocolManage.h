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
#ifndef DCMDSL_PROTOCOLMANAGE_H
#define DCMDSL_PROTOCOLMANAGE_H
/*============================================================================*/

/****************************** references *********************************/
#include "Dcm_Types.h"

/****************************** declarations *********************************/
/*********************************************************
 *The operation of the protocol managment data structure
 *********************************************************/
typedef enum
{
    DCM_PROTOCOL_VALID = 1,  /*Protocol "valid" state*/
    DCM_PROTOCOL_INVALID = 0 /*Protocol "Invalid" state*/
} Dcm_ProtocolStateType;

typedef struct
{
    Dcm_ProtocolType ProtocolId;             /*The protocol ID number*/
    uint8 ProtocolPri;                       /*protocol priority*/
    uint8 MsgCtrlIndex;                      /*Message control block index number*/
    uint32 ProtocolPreemptTime;              /*protocol preempt time*/
    uint32 P2ServerMax;                      /*In the current session state P2ServerMax.*/
    uint32 P2ServerMin;                      /*In the current session state P2ServerMin.*/
    uint32 P2StarServerMax;                  /*In the current session state P2*ServerMax.*/
    uint32 P2StarServerMin;                  /*In the current session state P2*ServerMin.*/
    uint32 S3Server;                         /*S3Server value*/
    Dcm_ProtocolStateType Dcm_ProtocolState; /*Protocol state*/
} Dcm_ProtocolCtrlType;

/********************************************************
***************Resource statement************************
********************************************************/

extern VAR(Dcm_ProtocolCtrlType, DCM_VAR_NOINIT) Dcm_ProtocolCtrl[DCM_DSLPROTOCOLROW_NUM_MAX];
/*Protocol control block*/

/*************************************************************************/
/*
 * Brief               <Initializing the corresponding protocol control block>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ProtocolCtrlId:Protocol control block index number.>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType>
 * PreCondition        <None>
 * CallByAPI           <Dcm_init()>
 */
/*************************************************************************/

extern FUNC(void, DCM_CODE) DslInternal_InitProtocolCtrl(uint8 ProtocolCtrlId);

extern FUNC(void, DCM_CODE) DslInternal_InitConnectionCtrl(uint8 ConnectionCtrlId);

/*************************************************************************/
/*
 * Brief               <protocal start>
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

extern FUNC(Std_ReturnType, DCM_CODE) DslInternal_ProtocolStart(uint8 ProtocolCtrlId);

/*************************************************************************/
/*
 * Brief               <protocal stop>
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

extern FUNC(Std_ReturnType, DCM_CODE) DslInternal_ProtocolStop(uint8 ProtocolCtrlId);

/*************************************************************************/
/*
 * Brief               <Set the module support each protocol link layer parameters of time>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <P2ServerTimer:
 *                      P2StarServerTimer:>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <>
 * CallByAPI           <APIName>
 */
/*************************************************************************/

extern FUNC(void, DCM_CODE) DslInternal_SetProtocolLinkLayerTimer(uint32 P2ServerTimer, uint32 P2StarServerTimer);

#endif /* DCMDSL_PROTOCOLMANAGE_H_ */
