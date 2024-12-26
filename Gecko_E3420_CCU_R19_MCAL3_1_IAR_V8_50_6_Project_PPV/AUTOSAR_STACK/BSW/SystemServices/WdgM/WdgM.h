/*******************************************************************************
**                                                                            **
** Copyright(C)iSOFT (2022)                                                   **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document,and communication                  **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : WdgM.h                                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      : haibin.shao                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S):   AUTOSAR classic Platform R19-11                       **
**                                                                            **
*******************************************************************************/

/*======================[R E V I S I O N   H I S T O R Y]=====================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V1.0.0     20180116     xinyu.J       Initial version
 *  V1.0.1     20180713     Xinyu.J       1. Modify the type definition base on the Req356/357/358
 *  V1.0.2     20190703     Xinyu.J       Add the Function WdgM_GetSupervisedEntityTabIndex
 *  V1.0.3     20190717     Xinyu.J       Update the note and code after CodeReview
 *  V1.0.4     20221222     peng.wu       Modify the head and version info
 *  V1.0.5     20230424     peng.wu       Fix the bugs during logic supervision
 */
/*============================================================================*/

#ifndef WDGM_H_
#define WDGM_H_

/******************************INCLUDE*********************************/
#include "WdgM_CfgType.h"
#include "WdgM_Cfg.h"
#include "Std_Types.h"

/*********************************WDGM Version Definition*************************************/
#define WDGM_VENDOR_ID          62u /*DD_2_212, Vendor ID*/
#define WDGM_INSTANCE_ID        0u  /*DD_2_213, Instance ID*/

#define WDGM_H_SW_MAJOR_VERSION 1u /*DD_2_214, Major Version*/
#define WDGM_H_SW_MINOR_VERSION 0u /*DD_2_215, Minor Version*/
#define WDGM_H_SW_PATCH_VERSION 6u /*DD_2_216, Patch Version*/
#define WDGM_H_AR_MAJOR_VERSION 4u /*DD_2_217, Autosar Major Version*/
#define WDGM_H_AR_MINOR_VERSION 5u /*DD_2_218, Autosar Minor Version*/
#define WDGM_H_AR_PATCH_VERSION 0u /*DD_2_219, Autosar Patch Version*/

#define WDGM_MODULE_ID          13u /*DD_2_220*/

#if (STD_ON == WDGM_IMMEDIATE_RESET)
#define WDGM_IMMEDIATE_RESET_VIA_OS 13u
#endif /*STD_ON == WDGM_IMMEDIATE_RESET*/

/******************************API ID Definition *********************************/
#define WDGM_INIT_ID                   (0x00u)  /*DD_2_221, WdgM_Init()*/
#define WDGM_DEINIT_ID                 (0x01u)  /*DD_2_222, WdgM_DeInit()*/
#define WDGM_GET_VERSION_INFO_ID       (0x02u)  /*DD_2_223, WdgM_GetVersionInfo()*/
#define WDGM_SET_MODE_ID               (0x03u)  /*DD_2_224, WdgM_SetMode()*/
#define WDGM_MAINFUNCTION_ID           (0x08u)  /*DD_2_225, WdgM_MainFunction()*/
#define WDGM_GET_MODE_ID               (0x0Bu)  /*DD_2_226, WdgM_GetMode()*/
#define WDGM_GET_LOCAL_STATUS_ID       (0x0Cu)  /*DD_2_227, WdgM_GetLocalStatus()*/
#define WDGM_GET_GLOBAL_STATUS_ID      (0x0Du)  /*DD_2_228, WdgM_GetGlobalStatus()*/
#define WDGM_CHECKPOINT_REACHED_ID     (0x0Eu)  /*DD_2_229, WdgM_CheckpointReached()*/
#define WDGM_PERFORM_RESET_ID          (0x0Fu)  /*DD_2_230, WdgM_PerformReset()*/
#define WDGM_GET_FIRST_EXPIRED_SEID_ID (0x010u) /*DD_2_231, WdgM_GetFirstExpiredSEID()*/
/*************************************************************************************/

/******************************Det Error Definition*********************************/
/*DD_2_183*/
#define WDGM_E_NO_INIT (0x10u) /*without module initialization*/
/*API service called with NULL pointer paramete*/
#define WDGM_E_PARAM_CONFIG (0x11u)
#define WDGM_E_PARAM_MODE   (0x12u) /*API service called with wrong mode paramete*/
/*API service called with wrong supervised entity identifier parameter*/
#define WDGM_E_PARAM_SEID (0x13u)
/*API service called with a null pointer parameter*/
#define WDGM_E_INV_POINTER (0x14u)
/*Disabling of watchdog not allowed (e.g. in safety relevant systems)*/
#define WDGM_E_DISABLE_NOT_ALLOWED (0x15u)
/*API service used with an invalid CheckpointId*/
#define WDGM_E_CPID (0x16u)
/*WdgM_UpdateAliveIndication cannot determine the CP,
 * because more than one alive supervisions in the current mode for the given SE*/
#define WDGM_E_AMBIGIOUS (0x18u)
/*SE is deactivated*/
#define WDGM_E_SEDEACTIVATED (0x19u)

/*************************************************************************************/

/*******************************The other Definition**********************************/
#define WDGM_TRIGGER_CONDITION_STOP 0u /*Trigger condition for Stop*/
#define WDG_FUNCTION_SWITCH  STD_ON

/*************************************************************************************/

/***************************extern variable********************************************/

/* WdgM configuration. Used by WdgMInit() */
extern const WdgM_ConfigType WdgMConfigRoot[1]; /*DD_2_079*/

/*************************************************************************************/

extern FUNC(void, WDGM_CODE) WdgM_Init(const WdgM_ConfigType* WdgMConfigPtr);
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetMode(WdgM_ModeType* Mode);
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_SetMode(WdgM_ModeType Mode);
extern FUNC(Std_ReturnType, WDGM_CODE)
    WdgM_CheckpointReached(WdgM_SupervisedEntityIdType SEID, WdgM_CheckpointIdType CheckpointID);
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetGlobalStatus(WdgM_GlobalStatusType* Status);
extern FUNC(void, WDGM_CODE) WdgM_PerformReset(void);
extern FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetFirstExpiredSEID(WdgM_SupervisedEntityIdType* SEID);
extern FUNC(void, WDGM_CODE) WdgM_MainFunction(void);
extern FUNC(Std_ReturnType, WDGM_CODE)
    WdgM_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, WdgM_LocalStatusType* Status);

#if (STD_ON == WDGM_OFF_MODE_EABLED)
extern FUNC(void, WDGM_CODE) WdgM_DeInit(void);
#endif /*STD_ON == WDGM_OFF_MODE_EABLED*/

#if (WDGM_VERSION_INFO_API == STD_ON)
extern FUNC(void, WDGM_CODE) WdgM_GetVersionInfo(Std_VersionInfoType* VersionInfo);
#endif /*WDGM_VERSION_INFO_API == STD_ON*/

#endif /* WDGM_H_ */
