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
**  FILENAME    : WdgIf.h                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      : haibin.shao                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S):   AUTOSAR classic Platform R19-11                       **
**                                                                            **
*******************************************************************************/
#ifndef WDGIF_H
#define WDGIF_H
/*===========================[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>   <DATE>     <AUTHOR>        <REVISION LOG>
 *    V1.0.0     20180116     xinyu.J       Initial version
 *    V1.0.1     20180713     Xinyu.J       Update the WdgIf_SetMode and WdgIf_SetTriggerCondition.
 *    V1.0.2     20190717     Xinyu.J          Update the note  after CodeReview
 *    V1.0.3     20221222     peng.wu       Modify the head and version info
 */
/*================================================================================================*/

/*===========================[V E R S I O N  I N F O R M A T I O N]===============================*/
#define WDGIF_H_AR_MAJOR_VERSION 4u /*DD_2_217, Autosar Major Version*/
#define WDGIF_H_AR_MINOR_VERSION 5u /*DD_2_218, Autosar Minor Version*/
#define WDGIF_H_AR_PATCH_VERSION 0u /*DD_2_219, Autosar Patch Version*/
#define WDGIF_H_SW_MAJOR_VERSION 1u /*DD_2_214, Major Version*/
#define WDGIF_H_SW_MINOR_VERSION 0u /*DD_2_215, Minor Version*/
#define WDGIF_H_SW_PATCH_VERSION 3u /*DD_2_216, Patch Version*/

/*===========================VENDOR   I N F O R M A T I O N]==============*/
#define WDGIF_VENDOR_ID 62U /* Replace with a symbolic name once available*/
#define WDGIF_MODULE_ID 43U
#define WDGIF_INSTANCE  0U

/*===========================[I N C L U D E S]====================================================*/
#include "Std_Types.h"
#include "WdgIf_Types.h"
#include "WdgIf_Cfg.h"

/******************************API ID Definition *********************************/
/* Service ID */
#define WDGIF_SETMODE_ID        (0x01u) /*DD_2_242*/
#define WDGIF_TRIGGER_ID        (0x02u) /*DD_2_243*/
#define WDGIF_GETVERSIONINFO_ID (0x03u) /*DD_2_244*/

/* Error classification */
/* DD_2_188 */
#define WDGIF_E_PARAM_DEVICE (0x01u)
#define WDGIF_E_INV_POINTER  (0x02u)

/*===========================[T Y P E   D E F I N I T I O N S]====================================*/

/* Type for function macro of wdg driver */
/* DD_2_202 */
typedef struct
{
    /* PRQA S 3432 ++ */ /* MISRA Rule20.7 */
    P2FUNC(void, WDGIF_CONST, Wdg_SetTriggerCondition)(uint16 timeout);
    P2FUNC(Std_ReturnType, WDGIF_CONST, Wdg_SetMode)(WdgIf_ModeType Mode);
    /* PRQA S 3432 -- */ /* MISRA Rule20.7 */
} Wdg_GeneralType;

/* Type for wdg driver */
/* DD_2_203 */
typedef struct
{
    Wdg_GeneralType WdgRef;
} WdgIf_DeviceType;

/*===========================[E X T E R N A L   D A T A]==========================================*/
#if (WDGIF_NUMBER_OF_DEVICES > 1)
extern CONST(WdgIf_DeviceType, WDGIF_CONST) WdgIf_DeviceData[WDGIF_NUMBER_OF_DEVICES];
#endif /*WDGIF_NUMBER_OF_DEVICES > 1*/

/**************************************************************************************************/
/*
 * Brief               <Service for switches the watchdog into the mode>
 * ServiceId           <WDGIF_SETMODE_ID>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <mode: 1.WDGIFIF_OFF_MODE; 2.WDGIFIF_SLOW_MODE; 3.WDGIFIF_FAST_MODE>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType: E_NOT_OK, or E_OK>
 * PreCondition        <The WDGIF driver module must not be initialled>
 * CallByAPI           <None>
 */
/**************************************************************************************************/
extern FUNC(Std_ReturnType, WDGIF_CODE) WdgIf_SetMode(uint8 DeviceIndex, WdgIf_ModeType WdgMode);

/**************************************************************************************************/
/*
 * Brief               <Service for triggers the watchdog hardware>
 * ServiceId           <WDGIF_TRIGGER_ID>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <The WDGIF driver module must not be initialled>
 * CallByAPI           <None>
 */
/**************************************************************************************************/
extern FUNC(void, WDGIF_CODE) WdgIf_SetTriggerCondition(uint8 DeviceIndex, uint16 Timeout);

#if (STD_ON == WDGIF_VERSION_INFO_API)
extern FUNC(void, WDGIF_CODE) WdgIf_GetVersionInfo(Std_VersionInfoType* versionInfoPtr);
#endif /*STD_ON == WDGIF_VERSION_INFO_API*/

#endif /*WDGIF_H */
