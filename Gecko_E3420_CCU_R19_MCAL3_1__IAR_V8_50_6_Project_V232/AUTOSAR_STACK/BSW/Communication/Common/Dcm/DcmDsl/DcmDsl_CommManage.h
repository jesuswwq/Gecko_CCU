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

#ifndef DCMDSL_COMMMANAGE_H
#define DCMDSL_COMMMANAGE_H
/*============================================================================*/

/**************************************************************/
#include "Dcm_Types.h"

/***************************************************************************************
 *************Communication Management sub-function data structure*****
 **************************************************************************************/
typedef enum
{
    DCM_COMM_NO_COMMUNICATION = 0,     /* conmmunication is "NO Communication"status */
    DCM_COMM_SILENT_COMMUNICATION = 1, /* conmmunication is "Silent Communication"status */
    DCM_COMM_FULL_COMMUNICATION = 2    /* conmmunication is "Full Communication"status*/
} Dcm_CommStateType;

typedef enum
{
    DCM_COMM_ACTIVE = 0,
    DCM_COMM_NOT_ACTIVE = 1,
} Dcm_ActiveDiagnosticType;

typedef struct
{
    Dcm_CommStateType Dcm_CommState;
    Dcm_ActiveDiagnosticType Dcm_ActiveDiagnostic;
    NetworkHandleType DcmDslProtocolComMChannelId;
} Dcm_CommCtrlType;

extern VAR(Dcm_CommCtrlType, DCM_VAR_NOINIT) Dcm_CommCtrl[DCM_MAINCONNECTION_NUM];
/*Diagnostic Communication Control*/

/*********************************************************************************
 *****************Communication Management function declarations******************
 ********************************************************************************/
/*************************************************************************/
/*
 * Brief               <initialization of Comm Submodule>
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

extern FUNC(void, DCM_CODE) DslInternal_InitComMCtrl(void);

#endif /* DCMDSL_COMMMANAGE_H_ */
