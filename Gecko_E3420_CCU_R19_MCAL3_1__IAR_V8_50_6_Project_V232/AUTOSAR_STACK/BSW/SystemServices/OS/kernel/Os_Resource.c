/*******************************************************************************
**                                                                            **
** Copyright (C) iSOFT   (2022)                                               **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document, and communication                 **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : Os_Resource.c                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : i-soft-os                                                   **
**  Vendor      :                                                             **
**  DESCRIPTION : resource manager                                            **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/**
 *  <VERSION>  <DATE>    <AUTHOR>       <REVISION LOG>
 *  V0.1.0     2013-06-21  huaming        Initial version:define the format of
 *                                      data type and function.
 *  V0.2.0     2013-06-24  huaming        designed the program about ceiling
 *                                      priority,resource inserting and resource
 *                                      releasing.
 *  V0.3.0     2013-06-28  huaming        add the conditions whether a task or
 *                                      interrupt has the right to occupy a
 *                                      resource.
 *  V0.4.0     2013-07-23  yaoxuan.zhang  Modified the code to adapt MISRA C
 *                                      specification.
 *  V0.4.0     2013-07-30  huaming        Modified the code about Os_RCB[ResID].
 *                                      saveCount in ReleaseResource.
 *  V0.5.0     2013-08-02  huaming        add the code about internal resource.
 *  V0.6.0     2014-11-16  bo.zeng        code refactor.
 *  V0.7.0     2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0     2019-11-21  shun.li        Functional safety version.
 *  V1.1.0     2021-12-29  shun.li        Repaire the resource bug of interrupt priority ceiling protocol.
 */
/*============================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

/*=======[M A C R O S]========================================================*/

/*=======[I N T E R N A L   D A T A]==========================================*/
/*=======[E X T E R N A L   D A T A]==========================================*/
#if (CFG_STD_RESOURCE_MAX > 0U)
/* PRQA S 1514++ */ /* MISRA Rule 8.9 */
#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0) && (CFG_TASK_MAX_CORE0 > 0U))
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_TickType Os_RCBTmProtResBgtTaskCore0[CFG_STD_RESOURCE_MAX_CORE0][CFG_TASK_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0) && (CFG_TASK_MAX_CORE0 > 0U) */

#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1) && (CFG_TASK_MAX_CORE1 > 0U))
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_TickType Os_RCBTmProtResBgtTaskCore1[CFG_STD_RESOURCE_MAX_CORE1][CFG_TASK_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1) && (CFG_TASK_MAX_CORE1 > 0U) */

#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2) && (CFG_TASK_MAX_CORE2 > 0U))
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_TickType Os_RCBTmProtResBgtTaskCore2[CFG_STD_RESOURCE_MAX_CORE2][CFG_TASK_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2) && (CFG_TASK_MAX_CORE2 > 0U) */

#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE3) && (CFG_TASK_MAX_CORE3 > 0U))
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_TickType Os_RCBTmProtResBgtTaskCore3[CFG_STD_RESOURCE_MAX_CORE3][CFG_TASK_MAX_CORE3];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE3) && (CFG_TASK_MAX_CORE3 > 0U) */

#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE4) && (CFG_TASK_MAX_CORE4 > 0U))
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_TickType Os_RCBTmProtResBgtTaskCore4[CFG_STD_RESOURCE_MAX_CORE4][CFG_TASK_MAX_CORE4];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE4) && (CFG_TASK_MAX_CORE4 > 0U) */

#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE5) && (CFG_TASK_MAX_CORE5 > 0U))
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_TickType Os_RCBTmProtResBgtTaskCore5[CFG_STD_RESOURCE_MAX_CORE5][CFG_TASK_MAX_CORE5];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE5) && (CFG_TASK_MAX_CORE5 > 0U) */

#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0) && (CFG_ISR_MAX_CORE0 > 0U))
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_TickType Os_RCBTmProtResBgtIsrCore0[CFG_STD_RESOURCE_MAX_CORE0][CFG_ISR_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0) && (CFG_TASK_MAX_CORE0 > 0U) */

#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1) && (CFG_ISR_MAX_CORE1 > 0U))
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_TickType Os_RCBTmProtResBgtIsrCore1[CFG_STD_RESOURCE_MAX_CORE1][CFG_ISR_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1) && (CFG_TASK_MAX_CORE1 > 0U) */

#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2) && (CFG_ISR_MAX_CORE2 > 0U))
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_TickType Os_RCBTmProtResBgtIsrCore2[CFG_STD_RESOURCE_MAX_CORE2][CFG_ISR_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2) && (CFG_TASK_MAX_CORE2 > 0U) */

#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE3) && (CFG_ISR_MAX_CORE3 > 0U))
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_TickType Os_RCBTmProtResBgtIsrCore3[CFG_STD_RESOURCE_MAX_CORE3][CFG_ISR_MAX_CORE3];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE3) && (CFG_TASK_MAX_CORE3 > 0U) */

#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE4) && (CFG_ISR_MAX_CORE4 > 0U))
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_TickType Os_RCBTmProtResBgtIsrCore4[CFG_STD_RESOURCE_MAX_CORE4][CFG_ISR_MAX_CORE4];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE4) && (CFG_TASK_MAX_CORE4 > 0U) */

#if ((TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE5) && (CFG_ISR_MAX_CORE5 > 0U))
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_TickType Os_RCBTmProtResBgtIsrCore5[CFG_STD_RESOURCE_MAX_CORE5][CFG_ISR_MAX_CORE5];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif              /* (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE5) && (CFG_TASK_MAX_CORE5 > 0U) */
/* PRQA S 1514-- */ /* MISRA Rule 8.9 */
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(Os_ResourceType, OS_VAR) RES_SCHEDULER = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(Os_ResourceCfgType, AUTOMATIC, OS_VAR) Os_ResourceCfg = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(Os_RCBType volatile, AUTOMATIC, OS_VAR) Os_RCB = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint16, OS_VAR) Os_CfgResourceMax = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static VAR(uint16, OS_VAR) Os_CfgStdResourceMax = 0U; /* PRQA S 3218 */ /* MISRA Rule 8.9 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#if (OS_STATUS_EXTENDED == CFG_STATUS)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static P2CONST(uint16*, OS_VAR, OS_CONST) Os_TaskResourceAccessMask = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static P2CONST(uint16*, OS_VAR, OS_CONST) Os_IsrResourceAccessMask = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
#endif /* CFG_STD_RESOURCE_MAX > 0U */

#if (CFG_INTERNAL_RESOURCE_MAX > 0U)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(Os_PriorityType, AUTOMATIC, OS_VAR) Os_InterResCeiling = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static P2VAR(Os_PriorityType, AUTOMATIC, OS_VAR) Os_OccupyInterRes = NULL_PTR; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0U */

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
#if (CFG_RESOURCE_MAX > 0U)
/******************************************************************************/
/*
 * Brief                <Init the resource control block>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <ResID>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0848,DD_1_0849>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InitResource(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    uint16 i = 0U;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
#if (CFG_STD_RESOURCE_MAX > 0U)
    Os_ResourceType resId;
    P2VAR(Os_RCBType volatile, AUTOMATIC, OS_VAR) pRcb;
#endif /* CFG_STD_RESOURCE_MAX > 0 */

    switch (Os_SCB.sysCore)
    {
    case 0:
#if ((CFG_INTERNAL_RESOURCE_MAX > 0U) && (TRUE == CFG_CORE0_AUTOSAROS_ENABLE))
        Os_InterResCeiling = Os_InterResCeilingCore0;
        Os_OccupyInterRes = Os_OccupyInterResCore0;
#endif /* CFG_INTERNAL_RESOURCE_MAX_CORE0 > 0U && TRUE == CFG_CORE0_AUTOSAROS_ENABLE*/
#if (CFG_STD_RESOURCE_MAX_CORE0 > 0U)
#if (TRUE == CFG_USERESSCHEDULER)
        RES_SCHEDULER = RES_SCHEDULER_CORE0;
#endif /* TRUE == CFG_USERESSCHEDULER */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        Os_TaskResourceAccessMask = Os_TaskResourceAccessMaskCore0;
        Os_IsrResourceAccessMask = Os_IsrResourceAccessMaskCore0;
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
        Os_ResourceCfg = Os_ResourceCfgCore0;
        Os_RCB = Os_RCBCore0;
        Os_CfgResourceMax = CFG_RESOURCE_MAX_CORE0;
        Os_CfgStdResourceMax = CFG_STD_RESOURCE_MAX_CORE0;
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0)
        Os_RCBCore0[i].osTmProtResBgtTask = NULL_PTR;
        Os_RCBCore0[i].osTmProtResBgtIsr = NULL_PTR;
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE0; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore0[i].saveLevel = OS_LEVEL_MAIN;
        }

#if (CFG_TASK_MAX_CORE0 > 0)
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE0; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore0[i].osTmProtResBgtTask = Os_RCBTmProtResBgtTaskCore0[i];
        }
#endif /* CFG_TASK_MAX_CORE0 > 0 */

#if (CFG_ISR_MAX_CORE0 > 0)
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE0; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore0[i].osTmProtResBgtIsr = Os_RCBTmProtResBgtIsrCore0[i];
        }
#endif /* CFG_ISR_MAX_CORE0 > 0 */
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE0) */
#endif /* CFG_STD_RESOURCE_MAX_CORE0 > 0U */
        break;

    case 1:
#if ((CFG_INTERNAL_RESOURCE_MAX > 0U) && (TRUE == CFG_CORE1_AUTOSAROS_ENABLE))
        Os_InterResCeiling = Os_InterResCeilingCore1;
        Os_OccupyInterRes = Os_OccupyInterResCore1;
#endif /* CFG_INTERNAL_RESOURCE_MAX_CORE1 > 0U && TRUE == CFG_CORE1_AUTOSAROS_ENABLE*/
#if (CFG_STD_RESOURCE_MAX_CORE1 > 0U)
#if (TRUE == CFG_USERESSCHEDULER)
        RES_SCHEDULER = RES_SCHEDULER_CORE1;
#endif /* TRUE == CFG_USERESSCHEDULER */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        Os_TaskResourceAccessMask = Os_TaskResourceAccessMaskCore1;
        Os_IsrResourceAccessMask = Os_IsrResourceAccessMaskCore1;
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        Os_ResourceCfg = Os_ResourceCfgCore1;
        Os_RCB = Os_RCBCore1;
        Os_CfgResourceMax = CFG_RESOURCE_MAX_CORE1;
        Os_CfgStdResourceMax = CFG_STD_RESOURCE_MAX_CORE1;

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1)
        Os_RCBCore1[i].osTmProtResBgtTask = NULL_PTR;
        Os_RCBCore1[i].osTmProtResBgtIsr = NULL_PTR;
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE1; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore1[i].saveLevel = OS_LEVEL_MAIN;
        }

#if (CFG_TASK_MAX_CORE1 > 0)
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE1; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore1[i].osTmProtResBgtTask = Os_RCBTmProtResBgtTaskCore1[i];
        }
#endif /* CFG_TASK_MAX_CORE1 > 0 */

#if (CFG_ISR_MAX_CORE1 > 0)
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE1; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore1[i].osTmProtResBgtIsr = Os_RCBTmProtResBgtIsrCore1[i];
        }
#endif /* CFG_ISR_MAX_CORE1 > 0 */
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE1) */
#endif /* CFG_STD_RESOURCE_MAX_CORE1 > 0U */
        break;

    case 2:
#if ((CFG_INTERNAL_RESOURCE_MAX > 0U) && (TRUE == CFG_CORE2_AUTOSAROS_ENABLE))
        Os_InterResCeiling = Os_InterResCeilingCore2;
        Os_OccupyInterRes = Os_OccupyInterResCore2;
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0U && TRUE == CFG_CORE2_AUTOSAROS_ENABLE*/
#if (CFG_STD_RESOURCE_MAX_CORE2 > 0U)
#if (TRUE == CFG_USERESSCHEDULER)
        RES_SCHEDULER = RES_SCHEDULER_CORE2;
#endif /* TRUE == CFG_USERESSCHEDULER */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
        Os_TaskResourceAccessMask = Os_TaskResourceAccessMaskCore2;
        Os_IsrResourceAccessMask = Os_IsrResourceAccessMaskCore2;
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        Os_ResourceCfg = Os_ResourceCfgCore2;
        Os_RCB = Os_RCBCore2;
        Os_CfgResourceMax = CFG_RESOURCE_MAX_CORE2;
        Os_CfgStdResourceMax = CFG_STD_RESOURCE_MAX_CORE2;

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2)
        Os_RCBCore2[i].osTmProtResBgtTask = NULL_PTR;
        Os_RCBCore2[i].osTmProtResBgtIsr = NULL_PTR;
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE2; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore2[i].saveLevel = OS_LEVEL_MAIN;
        }

#if (CFG_TASK_MAX_CORE2 > 0)
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE2; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore2[i].osTmProtResBgtTask = Os_RCBTmProtResBgtTaskCore2[i];
        }
#endif /* CFG_TASK_MAX_CORE2 > 0 */

#if (CFG_ISR_MAX_CORE2 > 0)
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE2; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore2[i].osTmProtResBgtIsr = Os_RCBTmProtResBgtIsrCore2[i];
        }
#endif /* CFG_ISR_MAX_CORE2 > 0 */
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE2) */
#endif /* CFG_STD_RESOURCE_MAX_CORE2 > 0U */
        break;

    case 3:
#if ((CFG_INTERNAL_RESOURCE_MAX > 0U) && (TRUE == CFG_CORE3_AUTOSAROS_ENABLE))
        Os_InterResCeiling = Os_InterResCeilingCore3;
        Os_OccupyInterRes = Os_OccupyInterResCore3;
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0U && TRUE == CFG_CORE3_AUTOSAROS_ENABLE*/
#if (CFG_STD_RESOURCE_MAX_CORE3 > 0U)
#if (TRUE == CFG_USERESSCHEDULER)
        RES_SCHEDULER = RES_SCHEDULER_CORE3;
#endif /* TRUE == CFG_USERESSCHEDULER */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
        Os_TaskResourceAccessMask = Os_TaskResourceAccessMaskCore3;
        Os_IsrResourceAccessMask = Os_IsrResourceAccessMaskCore3;
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        Os_ResourceCfg = Os_ResourceCfgCore3;
        Os_RCB = Os_RCBCore3;
        Os_CfgResourceMax = CFG_RESOURCE_MAX_CORE3;
        Os_CfgStdResourceMax = CFG_STD_RESOURCE_MAX_CORE3;

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE3)
        Os_RCBCore3[i].osTmProtResBgtTask = NULL_PTR;
        Os_RCBCore3[i].osTmProtResBgtIsr = NULL_PTR;
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE3; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore3[i].saveLevel = OS_LEVEL_MAIN;
        }

#if (CFG_TASK_MAX_CORE3 > 0)
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE3; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore3[i].osTmProtResBgtTask = Os_RCBTmProtResBgtTaskCore3[i];
        }
#endif /* CFG_TASK_MAX_CORE3 > 0 */

#if (CFG_ISR_MAX_CORE3 > 0)
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE3; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore3[i].osTmProtResBgtIsr = Os_RCBTmProtResBgtIsrCore3[i];
        }
#endif /* CFG_ISR_MAX_CORE3 > 0 */
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE3) */
#endif /* CFG_STD_RESOURCE_MAX_CORE3 > 0U */
        break;

    case 4:
#if ((CFG_INTERNAL_RESOURCE_MAX > 0U) && (TRUE == CFG_CORE4_AUTOSAROS_ENABLE))
        Os_InterResCeiling = Os_InterResCeilingCore4;
        Os_OccupyInterRes = Os_OccupyInterResCore4;
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0U && TRUE == CFG_CORE4_AUTOSAROS_ENABLE*/
#if (CFG_STD_RESOURCE_MAX_CORE4 > 0U)
#if (TRUE == CFG_USERESSCHEDULER)
        RES_SCHEDULER = RES_SCHEDULER_CORE4;
#endif /* TRUE == CFG_USERESSCHEDULER */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
        Os_TaskResourceAccessMask = Os_TaskResourceAccessMaskCore4;
        Os_IsrResourceAccessMask = Os_IsrResourceAccessMaskCore4;
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        Os_ResourceCfg = Os_ResourceCfgCore4;
        Os_RCB = Os_RCBCore4;
        Os_CfgResourceMax = CFG_RESOURCE_MAX_CORE4;
        Os_CfgStdResourceMax = CFG_STD_RESOURCE_MAX_CORE4;

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE4)
        Os_RCBCore4[i].osTmProtResBgtTask = NULL_PTR;
        Os_RCBCore4[i].osTmProtResBgtIsr = NULL_PTR;
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE4; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore4[i].saveLevel = OS_LEVEL_MAIN;
        }

#if (CFG_TASK_MAX_CORE4 > 0)
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE4; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore4[i].osTmProtResBgtTask = Os_RCBTmProtResBgtTaskCore4[i];
        }
#endif /* CFG_TASK_MAX_CORE4 > 0 */

#if (CFG_ISR_MAX_CORE4 > 0)
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE4; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore4[i].osTmProtResBgtIsr = Os_RCBTmProtResBgtIsrCore4[i];
        }
#endif /* CFG_ISR_MAX_CORE4 > 0 */
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE4) */
#endif /* CFG_STD_RESOURCE_MAX_CORE4 > 0U */
        break;

    case 5:
#if ((CFG_INTERNAL_RESOURCE_MAX > 0U) && (TRUE == CFG_CORE5_AUTOSAROS_ENABLE))
        Os_InterResCeiling = Os_InterResCeilingCore5;
        Os_OccupyInterRes = Os_OccupyInterResCore5;
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0U && TRUE == CFG_CORE5_AUTOSAROS_ENABLE*/
#if (CFG_STD_RESOURCE_MAX_CORE5 > 0U)
#if (TRUE == CFG_USERESSCHEDULER)
        RES_SCHEDULER = RES_SCHEDULER_CORE5;
#endif /* TRUE == CFG_USERESSCHEDULER */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
        Os_TaskResourceAccessMask = Os_TaskResourceAccessMaskCore5;
        Os_IsrResourceAccessMask = Os_IsrResourceAccessMaskCore5;
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        Os_ResourceCfg = Os_ResourceCfgCore5;
        Os_RCB = Os_RCBCore5;
        Os_CfgResourceMax = CFG_RESOURCE_MAX_CORE5;
        Os_CfgStdResourceMax = CFG_STD_RESOURCE_MAX_CORE5;

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE5)
        Os_RCBCore5[i].osTmProtResBgtTask = NULL_PTR;
        Os_RCBCore5[i].osTmProtResBgtIsr = NULL_PTR;
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE5; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore5[i].saveLevel = OS_LEVEL_MAIN;
        }

#if (CFG_TASK_MAX_CORE5 > 0)
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE5; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore5[i].osTmProtResBgtTask = Os_RCBTmProtResBgtTaskCore5[i];
        }
#endif /* CFG_TASK_MAX_CORE5 > 0 */

#if (CFG_ISR_MAX_CORE5 > 0)
        for (i = 0U; i < CFG_STD_RESOURCE_MAX_CORE5; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            Os_RCBCore5[i].osTmProtResBgtIsr = Os_RCBTmProtResBgtIsrCore5[i];
        }
#endif /* CFG_ISR_MAX_CORE5 > 0 */
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE_CORE5) */
#endif /* CFG_STD_RESOURCE_MAX_CORE5 > 0U */
        break;

    /*add comments to pass QAC.*/
    default:
        while (1)
        {
            /* Nothing to do. */
        }
        break; /* PRQA S 2880 */ /* MISRA Rule 2.1 */
    }

#if (CFG_STD_RESOURCE_MAX > 0U)
    for (resId = 0U; resId < Os_CfgStdResourceMax; resId++)
    {
        pRcb = &Os_RCB[resId];

        pRcb->saveCount = 0u;
        pRcb->savePrio = OS_PRIORITY_INVALID;

#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
        pRcb->osWhichTaskOccupy = OS_TASK_INVALID;
        pRcb->osWhichIsrOccupy = OS_ISR_INVALID;

/* Autosar SC2: for timing protection. Budget for resoruce lock init
 * to invalid. Invalid means not be configed. */
#if (CFG_TASK_MAX > 0)
        if (NULL_PTR != pRcb->osTmProtResBgtTask)
        {
            for (i = 0U; i < Os_CfgTaskMax; i++)
            {
                pRcb->osTmProtResBgtTask[i] = OS_TICK_INVALID;
            }
        }
#endif /* #if (CFG_TASK_MAX > 0) */

#if (CFG_ISR_MAX > 0)
        if (NULL_PTR != pRcb->osTmProtResBgtIsr)
        {
            for (i = 0U; i < Os_CfgIsrMax; i++)
            {
                pRcb->osTmProtResBgtIsr[i] = OS_TICK_INVALID;
            }
        }
#endif /* CFG_ISR_MAX > 0 */

        pRcb->osResTpData.osIsTpStart = FALSE;
        pRcb->osResTpData.osTpBudget = 0u;
        pRcb->osResTpData.osTpTime = 0u;
#endif /* #if (TRUE == CFG_TIMING_PROTECTION_ENABLE) */
    }
#endif /* CFG_STD_RESOURCE_MAX > 0 */

    return;
}
#endif /* CFG_RESOURCE_MAX > 0U */

#if (CFG_STD_RESOURCE_MAX > 0U)
/******************************************************************************/
/*
 * Brief                <task or ISR ocuupy a resource referenced by <ResID >
 *                      <This call serves to enter critical sections in the code
 *                      that are assigned to the resource referenced by <ResID>.
 *                      A critical section shall always be left using
 *                      ReleaseResource.>
 * Service ID           <OSServiceId_GetResource>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <ResID>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <StatusType>
 * PreCondition         <None>
 * CallByAPI            <task or ISR>
 * REQ ID               <DD_1_0674, DD_1_1536, DD_1_1537, DD_1_1540, DD_1_1063, DD_1_0675,
 *                       DD_1_0676, DD_1_1187, DD_1_1188, DD_1_1553, DD_1_1585, DD_1_1666,
 *                       DD_1_0677, DD_1_0018, DD_1_0023, DD_1_0025>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) GetResource(ResourceType ResID) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_PriorityType prio;
    Os_PriorityType savePrioTemp = 0U;
    StatusType OsReturnErr = E_OK;
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTCB;
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pICB;
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    Os_TmProtResOccupyType osTmResOccupyType = TP_RES_OCCUPY_BUTT;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

    OS_ARCH_DECLARE_CRITICAL();
    OS_GR_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

    if (Os_SCB.sysCore != Os_GetObjCoreId(ResID))
    {
#if (TRUE == CFG_ERRORHOOK)
        Os_CallErrorHook(E_OS_CORE);
#endif /* TRUE == CFG_ERRORHOOK */
        OsReturnErr = E_OS_CORE;
    }
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    else if (Os_WrongContext(OS_CONTEXT_GET_RESOURCE) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_RESOURCE, ResID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
#endif /* (TRUE == CFG_SERVICE_PROTECTION_ENABLE) */
    else
    {
        pTCB = Os_SCB.sysRunningTCB;
        pICB = &Os_ICB[Os_SCB.sysRunningIsrCat2Id]; /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
        ResID = Os_GetObjLocalId(ResID);

        OS_ARCH_ENTRY_CRITICAL();
        OS_GR_START_CRITICAL();
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        if (ResID >= Os_CfgStdResourceMax)
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_GetResource);
            OSError_Save_GetResource(ResID);
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ID;
        }
        /* the resource was occupied already */
        else if (Os_RCB[ResID].saveCount > 0U)
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_GetResource);
            OSError_Save_GetResource(ResID);
            Os_CallErrorHook(E_OS_ACCESS);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ACCESS;
        }
        /* resource has no accessing authentication. */
        else if (
            (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
            && (0U
                == (Os_TaskResourceAccessMask[Os_SCB.sysRunningTaskID][ResID >> 4u] & ((uint32)1u << (ResID & 0x0Fu)))))
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_GetResource);
            OSError_Save_GetResource(ResID);
            Os_CallErrorHook(E_OS_ACCESS);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ACCESS;
        }
        else if (
            (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
            && (0U
                == (Os_IsrResourceAccessMask[Os_SCB.sysRunningIsrCat2Id][ResID >> 4u]
                    & ((uint32)1u << (ResID & 0x0Fu)))))
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_GetResource);
            OSError_Save_GetResource(ResID);
            Os_CallErrorHook(E_OS_ACCESS);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ACCESS;
        }
        else
        {
            /* nothing to do */
        }
        OS_ARCH_EXIT_CRITICAL();
        OS_GR_END_CRITICAL();

        if ((StatusType)E_OK == OsReturnErr)
#endif /* #if (OS_STATUS_EXTENDED == CFG_STATUS) */
        {
            prio = Os_ResourceCfg[ResID].ceiling;

            OS_ARCH_ENTRY_CRITICAL();
            OS_GR_START_CRITICAL();
            switch (Os_ResourceCfg[ResID].resourceOccupyType)
            {
            case OCCUPIED_BY_TASK:
#if (OS_STATUS_EXTENDED == CFG_STATUS)
                if (Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskPriority > prio)
                {
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_GetResource);
                    OSError_Save_GetResource(ResID);
                    Os_CallErrorHook(E_OS_ACCESS);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_ACCESS;
                }
                else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
                {
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_GetResource);
                    OSError_Save_GetResource(ResID);
                    Os_CallErrorHook(E_OS_ACCESS);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_ACCESS;
                }
                else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
                {
                    /* AutoSar: add ResID to stack. For protection hook. */
                    if (pTCB->taskResCount < Os_CfgResourceMax)
                    {
                        /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
                        pTCB->taskResourceStack[pTCB->taskResCount] = ResID;
                        /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
                    }
                    pTCB->taskResCount = pTCB->taskResCount + 1u;
                    Os_RCB[ResID].saveCount = pTCB->taskResCount;
/* Multi core res and spinlock should together release as
 * LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                    pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount] = OBJECT_RESOURCE;
                    pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount] = ResID;
                    pTCB->taskCriticalZoneCount = pTCB->taskCriticalZoneCount + 1u;
#endif /* CFG_SPINLOCK_MAX > 0U */

                    /* it's need to change these codes about CFG_PRIORITY_MAX.in fact,
                     * the ceiling priority is related with CFG_PRIORITY_MAX but not
                     * CFG_PRIORITY_MAX.otherwise this way will restrict the space of
                     * TASK_STATE_READY map
                     */
                    savePrioTemp = pTCB->taskRunPrio;
                    if (prio > pTCB->taskRunPrio)
                    {
                        Os_ReadyQueueInsert(ResID, OS_LEVEL_STANDARD_RESOURCE, prio);
                        pTCB->taskRunPrio = prio;
                    }
                    if (prio > Os_SCB.sysHighPrio)
                    {
                        Os_SCB.sysHighPrio = prio;
                        Os_SCB.sysHighTaskID = Os_SCB.sysRunningTaskID;
                    }
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
                    /* Occupy type. */
                    osTmResOccupyType = TP_RES_OCCUPY_TASK;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
                }
                break;
            case OCCUPIED_BY_TASK_OR_INTERRUPT:
                /* it's necessary to distinguish the call level of task or ISR,
                 * but the current means what use only Os_ResourceOccupyType
                 * can't resolve it. in fact the way of old kernel is effective
                 */
                if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
                {
                    Os_RCB[ResID].saveLevel = Os_SCB.sysOsLevel;
                    /* AutoSar: add ResID to stack. For protection hook. */
                    if (pTCB->taskResCount < Os_CfgResourceMax)
                    {
                        /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
                        pTCB->taskResourceStack[pTCB->taskResCount] = ResID;
                        /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
                    }
                    pTCB->taskResCount = pTCB->taskResCount + 1u;
                    Os_RCB[ResID].saveCount = pTCB->taskResCount;
/* Multi core res and spinlock should together release as
 * LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                    pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount] = OBJECT_RESOURCE;
                    pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount] = ResID;
                    pTCB->taskCriticalZoneCount = pTCB->taskCriticalZoneCount + 1u;
#endif /* CFG_SPINLOCK_MAX > 0U */
                    savePrioTemp = Os_IplToPrio(Os_ArchGetIpl());
                    Os_ArchSetIpl(Os_PrioToIpl(prio), OS_ISR_DISABLE);
                    Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker + 1u;
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
                    /* Resource occupy type. */
                    osTmResOccupyType = TP_RES_OCCUPY_TASK;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
                }
                else
                {
/* AutoSar: add ResID to stack. For protection hook. */
#if (CFG_ISR2_MAX > 0)
                    if (TRUE == Os_SCB.sysInIsrCat2)
                    {
                        if (pICB->IsrC2ResCount < Os_CfgResourceMax)
                        {
                            /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
                            pICB->IsrC2ResourceStack[pICB->IsrC2ResCount] = ResID;
                            /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
                        }
                        pICB->IsrC2ResCount = pICB->IsrC2ResCount + 1u;
                        Os_RCB[ResID].saveCount = pICB->IsrC2ResCount; /* PRQA S 4461 */ /* MISRA Rule 10.3 */
/* Multi core res and spinlock should together release as
 * LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                        pICB->isr2CriticalZoneType[pICB->isr2CriticalZoneCount] = OBJECT_RESOURCE;
                        pICB->isr2CriticalZoneStack[pICB->isr2CriticalZoneCount] = ResID;
                        pICB->isr2CriticalZoneCount = pICB->isr2CriticalZoneCount + 1u;
#endif /* CFG_SPINLOCK_MAX > 0U */
                    }
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
                    /* Resource occupy type. */
                    osTmResOccupyType = TP_RES_OCCUPY_ISR;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
#endif /* CFG_ISR2_MAX > 0 */

#if (TRUE == CFG_INT_NEST_ENABLE)
                    savePrioTemp = Os_IplToPrio(Os_ArchGetIpl());
                    if (prio > savePrioTemp)
                    {
                        Os_ArchSetIpl(Os_PrioToIpl(prio), OS_ISR_DISABLE);
                    }
#endif /* #if (TRUE == CFG_INT_NEST_ENABLE) */
                }
                break;
            case OCCUPIED_BY_INTERRUPT:
#if (TRUE == CFG_INT_NEST_ENABLE)
                savePrioTemp = Os_IplToPrio(Os_ArchGetIpl());
                if (prio > savePrioTemp)
                {
                    Os_ArchSetIpl(Os_PrioToIpl(prio), OS_ISR_DISABLE);
                }
#endif /* #if (TRUE == CFG_INT_NEST_ENABLE) */
/* AutoSar: add ResID to stack. For protection hook. */
#if (CFG_ISR2_MAX > 0)
                if (TRUE == Os_SCB.sysInIsrCat2)
                {
                    if (pICB->IsrC2ResCount < Os_CfgResourceMax)
                    {
                        /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
                        pICB->IsrC2ResourceStack[pICB->IsrC2ResCount] = ResID;
                        /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
                    }
                    pICB->IsrC2ResCount = pICB->IsrC2ResCount + 1u;
                    Os_RCB[ResID].saveCount = pICB->IsrC2ResCount; /* PRQA S 4461 */ /* MISRA Rule 10.3 */
/* Multi core res and spinlock should together release as
 * LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                    pICB->isr2CriticalZoneType[pICB->isr2CriticalZoneCount] = OBJECT_RESOURCE;
                    pICB->isr2CriticalZoneStack[pICB->isr2CriticalZoneCount] = ResID;
                    pICB->isr2CriticalZoneCount = pICB->isr2CriticalZoneCount + 1u;
#endif /* CFG_SPINLOCK_MAX > 0U */
                }
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
                /* Resource occupy type. */
                osTmResOccupyType = TP_RES_OCCUPY_ISR;
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
#endif /* CFG_ISR2_MAX > 0 */
                break;
            /*add comments to pass QAC.*/
            default:
                /* Nothing to do. */
                break;
            }
            if ((StatusType)E_OK == OsReturnErr)
            {
                Os_RCB[ResID].savePrio = savePrioTemp;
/* AutoSar SC2: Timing protection, resource lock. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
                Os_TmProtResStart(ResID, osTmResOccupyType);
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
            }
            OS_ARCH_EXIT_CRITICAL();
            OS_GR_END_CRITICAL();
        }
    }

    OS_GR_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <task or ISR release a resource occupied before>
 *                      <ReleaseResource is the counterpart of  GetResource and
 *                      serves to leave critical sections in the code that are
 *                      assigned to the resource referenced by <ResID>. > .
 * Service ID   :       <OSServiceId_ReleaseResource>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <ResID>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <StatusType>
 * PreCondition         <None>
 * CallByAPI            <task or ISR>
 * REQ ID               <DD_1_0678, DD_1_1538, DD_1_1541, DD_1_1064, DD_1_0679, DD_1_0680,
 *                       DD_1_1189, DD_1_1190, DD_1_1554, DD_1_1586, DD_1_1667, DD_1_1015,
 *                       DD_1_0021, DD_1_0024, DD_1_0025>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) ReleaseResource(ResourceType ResID)
{
    Os_PriorityType prio;
    Os_PriorityType savePrioTemp;
    StatusType OsReturnErr = E_OK;
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTCB;
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pICB;

    OS_ARCH_DECLARE_CRITICAL();
    OS_RR_ENTRY();
#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

    if (Os_SCB.sysCore != Os_GetObjCoreId(ResID))
    {
#if (TRUE == CFG_ERRORHOOK)
        Os_CallErrorHook(E_OS_CORE);
#endif /* TRUE == CFG_ERRORHOOK */

        OsReturnErr = E_OS_CORE;
    }
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    else if (Os_WrongContext(OS_CONTEXT_RELEASE_RESOURCE) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_RESOURCE, ResID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
#endif /* (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    else
    {
        pTCB = Os_SCB.sysRunningTCB;
        pICB = &Os_ICB[Os_SCB.sysRunningIsrCat2Id]; /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
        ResID = Os_GetObjLocalId(ResID);

        OS_ARCH_ENTRY_CRITICAL();
        OS_RR_START_CRITICAL();
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        if (ResID >= Os_CfgStdResourceMax)
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_ReleaseResource);
            OSError_Save_ReleaseResource(ResID);
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ID;
        }
        /* means that no any resource to release */
        else if (0U == Os_RCB[ResID].saveCount)
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_ReleaseResource);
            OSError_Save_ReleaseResource(ResID);
            Os_CallErrorHook(E_OS_NOFUNC);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_NOFUNC;
        }
        else
        {
            /* nothing to do */
        }
        OS_ARCH_EXIT_CRITICAL();
        OS_RR_END_CRITICAL();

        if ((StatusType)E_OK == OsReturnErr)
#endif /* #if (OS_STATUS_EXTENDED == CFG_STATUS) */
        {
            OS_ARCH_ENTRY_CRITICAL();
            OS_RR_START_CRITICAL();
            prio = Os_ResourceCfg[ResID].ceiling;
            savePrioTemp = Os_RCB[ResID].savePrio;

            switch (Os_ResourceCfg[ResID].resourceOccupyType)
            {
            case OCCUPIED_BY_TASK:
                if (Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskPriority > prio)
                {
                    OS_ARCH_EXIT_CRITICAL();
                    OS_RR_END_CRITICAL();
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_ReleaseResource);
                    OSError_Save_ReleaseResource(ResID);
                    Os_CallErrorHook(E_OS_ACCESS);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_ACCESS;
                }
                else if (Os_RCB[ResID].saveCount != pTCB->taskResCount)
                {
                    OS_ARCH_EXIT_CRITICAL();
                    OS_RR_END_CRITICAL();
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_ReleaseResource);
                    OSError_Save_ReleaseResource(ResID);
                    Os_CallErrorHook(E_OS_NOFUNC);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_NOFUNC;
                }
/*res and spinlock should together release as LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                else if (
                    (pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount - 1u] != OBJECT_RESOURCE)
                    || (pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount - 1u] != ResID))
                {
                    OS_ARCH_EXIT_CRITICAL();
                    OS_RR_END_CRITICAL();

                    OsReturnErr = E_OS_NOFUNC;
                }
#endif /* CFG_SPINLOCK_MAX > 0U */
                else
                {
                    pTCB->taskResCount = pTCB->taskResCount - 1u; /*pTCB->taskResCount--;*/
                    if (prio > savePrioTemp)
                    {
                        Os_ReadyQueueRemove(OS_LEVEL_STANDARD_RESOURCE, pTCB->taskRunPrio);
                        pTCB->taskRunPrio = savePrioTemp;
                    }
/*res and spinlock should together release as LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                    /*pTCB->taskCriticalZoneCount--;*/
                    pTCB->taskCriticalZoneCount = pTCB->taskCriticalZoneCount - 1u;
                    pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount] = OBJECT_MAX;
                    pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount] = OS_OBJECT_INVALID;
#endif /* CFG_SPINLOCK_MAX > 0U */
                }
                break;
            case OCCUPIED_BY_TASK_OR_INTERRUPT:
                if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
                {
                    if (Os_RCB[ResID].saveCount != pTCB->taskResCount)
                    {
                        OS_ARCH_EXIT_CRITICAL();
                        OS_RR_END_CRITICAL();
#if (TRUE == CFG_ERRORHOOK)
                        OSError_Save_ServiceId(OSServiceId_ReleaseResource);
                        OSError_Save_ReleaseResource(ResID);
                        Os_CallErrorHook(E_OS_NOFUNC);
#endif /* TRUE == CFG_ERRORHOOK */

                        OsReturnErr = E_OS_NOFUNC;
                    }
/*res and spinlock should together release as LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                    else if (
                        (pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount - 1u] != OBJECT_RESOURCE)
                        || (pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount - 1u] != ResID))
                    {
                        OS_ARCH_EXIT_CRITICAL();
                        OS_RR_END_CRITICAL();
                        OsReturnErr = E_OS_NOFUNC;
                    }
#endif /* CFG_SPINLOCK_MAX > 0U */
                    else
                    {
                        /*pTCB->taskResCount--;*/
                        pTCB->taskResCount = pTCB->taskResCount - 1u;
                        Os_RCB[ResID].saveCount = pTCB->taskResCount;
/*res and spinlock should together release as LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                        /*pTCB->taskCriticalZoneCount--;*/
                        pTCB->taskCriticalZoneCount = pTCB->taskCriticalZoneCount - 1u;
                        pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount] = OBJECT_MAX;
                        pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount] = OS_OBJECT_INVALID;
#endif /* CFG_SPINLOCK_MAX > 0U */
                        Os_ArchSetIpl(Os_PrioToIpl(savePrioTemp), OS_ISR_ENABLE);
                        /*Os_SCB.sysDispatchLocker--;*/
                        Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker - 1u;
                        Os_RCB[ResID].saveLevel = OS_LEVEL_MAIN;
                    }
                }
                else
                {
                    if (OS_LEVEL_TASK == Os_RCB[ResID].saveLevel)
                    {
                        if (Os_RCB[ResID].saveCount != pTCB->taskResCount)
                        {
                            OS_ARCH_EXIT_CRITICAL();
                            OS_RR_END_CRITICAL();
#if (TRUE == CFG_ERRORHOOK)
                            OSError_Save_ServiceId(OSServiceId_ReleaseResource);
                            OSError_Save_ReleaseResource(ResID);
                            Os_CallErrorHook(E_OS_NOFUNC);
#endif /* TRUE == CFG_ERRORHOOK */

                            OsReturnErr = E_OS_NOFUNC;
                        }
                        /*res and spinlock should together release as LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                        else if (
                            (pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount - 1u] != OBJECT_RESOURCE)
                            || (pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount - 1u] != ResID))
                        {
                            OS_ARCH_EXIT_CRITICAL();
                            OS_RR_END_CRITICAL();

                            OsReturnErr = E_OS_NOFUNC;
                        }
#endif /* CFG_SPINLOCK_MAX > 0U */
                        else
                        {
                            pTCB->taskResCount = pTCB->taskResCount - 1u; /*pTCB->taskResCount--;*/
                            Os_RCB[ResID].saveCount = pTCB->taskResCount;
/*res and spinlock should together release as LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                            pTCB->taskCriticalZoneCount = pTCB->taskCriticalZoneCount - 1u;
                            pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount] = OBJECT_MAX;
                            pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount] = OS_OBJECT_INVALID;
#endif /* CFG_SPINLOCK_MAX > 0U */
                            Os_ArchSetIpl(Os_PrioToIpl(savePrioTemp), OS_ISR_ENABLE);
                            Os_SCB.sysDispatchLocker = Os_SCB.sysDispatchLocker - 1u;
                            Os_RCB[ResID].saveLevel = OS_LEVEL_MAIN;
                        }
                    }
                    else
                    {
                        if (Os_RCB[ResID].saveCount != pICB->IsrC2ResCount)
                        {
                            OS_ARCH_EXIT_CRITICAL();
                            OS_RR_END_CRITICAL();
#if (TRUE == CFG_ERRORHOOK)
                            OSError_Save_ServiceId(OSServiceId_ReleaseResource);
                            OSError_Save_ReleaseResource(ResID);
                            Os_CallErrorHook(E_OS_NOFUNC);
#endif /* TRUE == CFG_ERRORHOOK */

                            OsReturnErr = E_OS_NOFUNC;
                        }
/*res and spinlock should together release as LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                        else if (
                            (pICB->isr2CriticalZoneType[pICB->isr2CriticalZoneCount - 1u] != OBJECT_RESOURCE)
                            || (pICB->isr2CriticalZoneStack[pICB->isr2CriticalZoneCount - 1u] != ResID))
                        {
                            OS_ARCH_EXIT_CRITICAL();
                            OS_RR_END_CRITICAL();

                            OsReturnErr = E_OS_NOFUNC;
                        }
#endif /* CFG_SPINLOCK_MAX > 0U */
                        else
                        {
#if (TRUE == CFG_INT_NEST_ENABLE)
                            if (prio > savePrioTemp)
                            {
                                Os_ArchSetIpl(Os_PrioToIpl(savePrioTemp), OS_ISR_ENABLE);
                            }
#endif /* TRUE == CFG_INT_NEST_ENABLE */
/* AutoSar: add ResID to stack. For protection hook. */
#if (CFG_ISR2_MAX > 0)
                            if (TRUE == Os_SCB.sysInIsrCat2)
                            {
                                pICB->IsrC2ResCount = pICB->IsrC2ResCount - 1u; /*pICB->IsrC2ResCount--;*/
/*res and spinlock should together release as
 * LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                                /*pICB->isr2CriticalZoneCount--;*/
                                pICB->isr2CriticalZoneCount = pICB->isr2CriticalZoneCount - 1u;
                                pICB->isr2CriticalZoneType[pICB->isr2CriticalZoneCount] = OBJECT_MAX;
                                pICB->isr2CriticalZoneStack[pICB->isr2CriticalZoneCount] = OS_OBJECT_INVALID;
#endif /* CFG_SPINLOCK_MAX > 0U */
                            }
#endif /* CFG_ISR2_MAX > 0 */
                            Os_RCB[ResID].saveLevel = OS_LEVEL_MAIN;
                        }
                    }
                }
                break;
            case OCCUPIED_BY_INTERRUPT:
                if (Os_RCB[ResID].saveCount != pICB->IsrC2ResCount)
                {
                    OS_ARCH_EXIT_CRITICAL();
                    OS_RR_END_CRITICAL();
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_ReleaseResource);
                    OSError_Save_ReleaseResource(ResID);
                    Os_CallErrorHook(E_OS_NOFUNC);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_NOFUNC;
                }
/*res and spinlock should together release as LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                else if (
                    (pICB->isr2CriticalZoneType[pICB->isr2CriticalZoneCount - 1u] != OBJECT_RESOURCE)
                    || (pICB->isr2CriticalZoneStack[pICB->isr2CriticalZoneCount - 1u] != ResID))
                {
                    OS_ARCH_EXIT_CRITICAL();
                    OS_RR_END_CRITICAL();
                    OsReturnErr = E_OS_NOFUNC;
                }
#endif /* CFG_SPINLOCK_MAX > 0U */
                else
                {
#if (TRUE == CFG_INT_NEST_ENABLE)
                    if (prio > savePrioTemp)
                    {
                        Os_ArchSetIpl(Os_PrioToIpl(savePrioTemp), OS_ISR_ENABLE);
                    }
#endif /* #if (TRUE == CFG_INT_NEST_ENABLE) */
/* AutoSar: add ResID to stack. For protection hook. */
#if (CFG_ISR2_MAX > 0)
                    if (TRUE == Os_SCB.sysInIsrCat2)
                    {
                        /*pICB->IsrC2ResCount--;*/
                        pICB->IsrC2ResCount = pICB->IsrC2ResCount - 1u;
/*res and spinlock should together release as LIFO order*/
#if (CFG_SPINLOCK_MAX > 0U)
                        /*pICB->isr2CriticalZoneCount--;*/
                        pICB->isr2CriticalZoneCount = pICB->isr2CriticalZoneCount - 1u;
                        pICB->isr2CriticalZoneType[pICB->isr2CriticalZoneCount] = OBJECT_MAX;
                        pICB->isr2CriticalZoneStack[pICB->isr2CriticalZoneCount] = OS_OBJECT_INVALID;
#endif /* CFG_SPINLOCK_MAX > 0U */
                    }
#endif /* CFG_ISR2_MAX > 0U */
                }
                break;
            default: /* Nothing to do. */
                break;
            }

            if ((StatusType)E_OK == OsReturnErr)
            {
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
                Os_TmProtResEnd(ResID); /*Timing protection, resource lock. */
#endif                                  /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
                Os_RCB[ResID].saveCount = 0u;
                Os_RCB[ResID].savePrio = OS_PRIORITY_INVALID;
                Os_SCB.sysHighPrio = Os_GetHighPrio();
                Os_SCB.sysHighTaskID = Os_ReadyQueueGetFirst(Os_SCB.sysHighPrio);
#if (CFG_SCHED_POLICY != OS_PREEMPTIVE_NON)
                if (Os_SCB.sysHighTaskID != Os_SCB.sysRunningTaskID) /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
                {
                    if (0u == Os_SCB.sysDispatchLocker)
                    {
                        OS_START_DISPATCH();
                        Os_Dispatch(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */
                    }
                }
#endif /* CFG_SCHED_POLICY != OS_PREEMPTIVE_NON */

                OS_ARCH_EXIT_CRITICAL();
                OS_RR_END_CRITICAL();
            }
        }
    }

    OS_RR_EXIT();
    return OsReturnErr;
}
#endif /* #if (CFG_STD_RESOURCE_MAX > 0U) */

#if (CFG_INTERNAL_RESOURCE_MAX > 0U)
/******************************************************************************/
/*
 * Brief                <get the internal resource >
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_ArchExitISR2 and so on>
 * REQ ID               <DD_1_0850, DD_1_1191, DD_1_0851>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_GetInternalResource(void)
{
    Os_PriorityType prio;

    if (Os_InterResCeiling[Os_SCB.sysRunningTaskID] > Os_TCB[Os_SCB.sysRunningTaskID].taskRunPrio)
    {

        prio = Os_InterResCeiling[Os_SCB.sysRunningTaskID];

        Os_TCB[Os_SCB.sysRunningTaskID].taskRunPrio = prio;

        Os_ReadyQueueInsert(Os_SCB.sysRunningTaskID, OS_LEVEL_INTERNAL_RESOURCE, prio);

        if (prio > Os_SCB.sysHighPrio)
        {
            Os_SCB.sysHighPrio = prio;
            Os_SCB.sysHighTaskID = Os_SCB.sysRunningTaskID;
        }

        /* Os_TCB[Os_SCB.sysRunningTaskID].taskResCount++; */
        Os_OccupyInterRes[Os_SCB.sysRunningTaskID] = 1u;
    }
}

/******************************************************************************/
/*
 * Brief                <Release the internal resource >
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <TerminateTask and so on>
 * REQ ID               <DD_1_0852, DD_1_1192, DD_1_0853>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ReleaseInternalResource(Os_TaskType osTaskId)
{
    if ((Os_InterResCeiling[osTaskId] != 0u) && (Os_OccupyInterRes[osTaskId] == 1u))
    {
        Os_TCB[osTaskId].taskRunPrio = Os_TaskCfg[osTaskId].osTaskPriority;

        Os_ReadyQueueRemove(OS_LEVEL_INTERNAL_RESOURCE, Os_InterResCeiling[osTaskId]);

        Os_OccupyInterRes[osTaskId] = 0u;
    }
}
#endif /* #if (CFG_INTERNAL_RESOURCE_MAX>0) */

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
