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
**  FILENAME    : WdgExt.c                                                    **
**                                                                            **
**  Created on  :                                                             **
**  Author      : haibin.shao                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S):   AUTOSAR classic Platform R19-11                       **
**                                                                            **
*******************************************************************************/

/*===========================[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>         <REVISION LOG>
 *  V1.0.0     20220117     haibin.shao       Initial version
 *  V1.0.1     20221222     peng.wu           Modify the head and version info
 *
 */
/*================================================================================================*/

/*===========================[V E R S I O N  I N F O R M A T I O N]===============================*/
#define WDGEXT_C_AR_MAJOR_VERSION 4u
#define WDGEXT_C_AR_MINOR_VERSION 5u
#define WDGEXT_C_AR_PATCH_VERSION 0u
#define WDGEXT_C_SW_MAJOR_VERSION 1u
#define WDGEXT_C_SW_MINOR_VERSION 0u
#define WDGEXT_C_SW_PATCH_VERSION 1u

/*===========================[I N C L U D E S]====================================================*/
#include "Std_Types.h"
#include "WdgIf_Types.h"
#include "WdgExt.h"
#include "WdgIf.h"

/*===========================[V E R S I O N  C H E C K]===========================================*/
#if (WDGEXT_C_AR_MAJOR_VERSION != WDGIF_H_AR_MAJOR_VERSION)
#error "WdgExt.c:Mismatch in Specification Major Version"
#endif
#if (WDGEXT_C_AR_MINOR_VERSION != WDGIF_H_AR_MINOR_VERSION)
#error "WdgExt.c:Mismatch in Specification Minor Version"
#endif
#if (WDGEXT_C_AR_PATCH_VERSION != WDGIF_H_AR_PATCH_VERSION)
#error "WdgExt.c:Mismatch in Specification Patch Version"
#endif
#if (WDGEXT_C_SW_MAJOR_VERSION != WDGIF_H_SW_MAJOR_VERSION)
#error "WdgExt.c:Mismatch in Specification Major Version"
#endif
#if (WDGEXT_C_SW_MINOR_VERSION != WDGIF_H_SW_MINOR_VERSION)
#error "WdgExt.c:Mismatch in Specification Minor Version"
#endif

#define WDGIF_START_SEC_CODE
#include "WdgIf_MemMap.h"
/**************************************************************************************************/
/*
 * Brief               <Service for triggers the external watchdog hardware>
 * ServiceId           --
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <The WDGIF driver module must not be initialled>
 * CallByAPI           <None>
 * REQ ID              <None>
 */
/**************************************************************************************************/
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
void WdgExt_SetTriggerCondition(const uint16 timeout)
{
    WDGEXT_PARA_UNUSED(timeout);
    return;
}

/**************************************************************************************************/
/*
 * Brief               <Service for switches the external watchdog into the mode>
 * ServiceId           --
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <mode: 1.WDGIFIF_OFF_MODE; 2.WDGIFIF_SLOW_MODE; 3.WDGIFIF_FAST_MODE>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <Std_ReturnType: E_NOT_OK, or E_OK>
 * PreCondition        <The WDGIF driver module must not be initialled>
 * CallByAPI           <None>
 * REQ ID              <None>
 */
/**************************************************************************************************/
Std_ReturnType WdgExt_SetMode(const WdgIf_ModeType Mode)
{
    WDGEXT_PARA_UNUSED(Mode);
    return E_OK;
}
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
#define WDGIF_STOP_SEC_CODE
#include "WdgIf_MemMap.h"
