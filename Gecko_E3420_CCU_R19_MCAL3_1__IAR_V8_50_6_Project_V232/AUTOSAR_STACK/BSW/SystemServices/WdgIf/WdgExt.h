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
**  FILENAME    : WdgExt.h                                                    **
**                                                                            **
**  Created on  :                                                             **
**  Author      : haibin.shao                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S):   AUTOSAR classic Platform R19-11                       **
**                                                                            **
*******************************************************************************/

#ifndef WDGEXT_H_
#define WDGEXT_H_

/*===========================[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>   <DATE>     <AUTHOR>        <REVISION LOG>
 *    V1.0.0     20220117   haibin.shao     Initial version
 *    V1.0.1     20221222   peng.wu         Modify the head and version info
 */
/*================================================================================================*/

/*===========================[V E R S I O N  I N F O R M A T I O N]===============================*/
#define WDGEXT_H_AR_MAJOR_VERSION 4u /*Autosar Major Version*/
#define WDGEXT_H_AR_MINOR_VERSION 5u /*Autosar Minor Version*/
#define WDGEXT_H_AR_PATCH_VERSION 0u /*Autosar Patch Version*/
#define WDGEXT_H_SW_MAJOR_VERSION 1u /*Major Version*/
#define WDGEXT_H_SW_MINOR_VERSION 0u /*Minor Version*/
#define WDGEXT_H_SW_PATCH_VERSION 1u /*Patch Version*/

/*===========================[I N C L U D E S]====================================================*/
#include "Std_Types.h"
#include "WdgIf_Types.h"

/*===========================[T Y P E   D E F I N I T I O N S]====================================*/

#if !defined(WDGEXT_PARA_UNUSED)
#define WDGEXT_PARA_UNUSED(x) ((void)(x))
#endif /* !defined(WDGEXT_PARA_UNUSED) */

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
extern void WdgExt_SetTriggerCondition(const uint16 timeout);
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
extern Std_ReturnType WdgExt_SetMode(const WdgIf_ModeType Mode);

#endif
