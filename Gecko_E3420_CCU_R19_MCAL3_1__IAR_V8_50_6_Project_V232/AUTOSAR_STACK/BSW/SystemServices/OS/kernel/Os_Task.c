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
**  FILENAME    : Os_Task.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : bo.zeng                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION : task  manager                                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2013-04-15  yaoxuan.zhang       Initial version.
 *  V0.2.0       2013-07-08  huaming             modified the task state of
 *                                             TerminateTask and ChainTask.
 *                                             in fact,TASK_STATE_START is
 *                                             necessary.
 *                                             add the code of ChainTask that
 *                                             use to insert the task to ready
 *                                             queue
 *  V0.3.0       2013-07-09  huaming             modified the format of parameter
 *                                             base on rule of i-soft.
 *  V0.4.0       2013-07-23  yaoxuan.zhang       Modified the code to adapt MISRA
 *                                             C specification.
 *  V0.5.0       2013-08-02  huaming             add the code about internal
 *                                             resource.
 *  V0.6.0       2014-11-11  bo.zeng             code refactor.
 *  V0.7.0       2016-01-14  shi.shu             new code SC3 and SC4.
 *  V0.8.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li             Functional safety version.
 *  V1.0.1       2021-08-19  shun.li             Modify release spinlock in mutlti-core.
 */
/*============================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 *  Rule 1.1        all the file   This in-line assembler construct is a
 *                                 language extension. The code has been ignored.
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"
/*=======[M A C R O S]========================================================*/

/*=======[T Y P E   D E F I N I T I O N S]====================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/
#if (CFG_TASK_MAX > 0U)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(Os_TaskCfgType, AUTOMATIC, OS_VAR) Os_TaskCfg = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(Os_StackType, AUTOMATIC, OS_VAR) Os_TaskStack = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) Os_TCB = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint16, OS_VAR) OS_TASK_IDLE = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint16, OS_VAR) Os_CfgTaskMax = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif /* #if (CFG_TASK_MAX > 0U) */
/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
/* PRQA S 1514++ */ /* MISRA Rule 8.9 */
#if (CFG_STD_RESOURCE_MAX_CORE0 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_ResourceType Os_TCBTaskResourceStackCore0[CFG_TASK_MAX_CORE0][CFG_STD_RESOURCE_MAX_CORE0];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_STD_RESOURCE_MAX_CORE0 > 0U */

#if (CFG_STD_RESOURCE_MAX_CORE1 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_ResourceType Os_TCBTaskResourceStackCore1[CFG_TASK_MAX_CORE1][CFG_STD_RESOURCE_MAX_CORE1];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_STD_RESOURCE_MAX_CORE1 > 0U */

#if (CFG_STD_RESOURCE_MAX_CORE2 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_ResourceType Os_TCBTaskResourceStackCore2[CFG_TASK_MAX_CORE2][CFG_STD_RESOURCE_MAX_CORE2];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_STD_RESOURCE_MAX_CORE2 > 0U */

#if (CFG_STD_RESOURCE_MAX_CORE3 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_ResourceType Os_TCBTaskResourceStackCore3[CFG_TASK_MAX_CORE3][CFG_STD_RESOURCE_MAX_CORE3];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_STD_RESOURCE_MAX_CORE3 > 0U */

#if (CFG_STD_RESOURCE_MAX_CORE4 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_ResourceType Os_TCBTaskResourceStackCore4[CFG_TASK_MAX_CORE4][CFG_STD_RESOURCE_MAX_CORE4];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif /* CFG_STD_RESOURCE_MAX_CORE4 > 0U */

#if (CFG_STD_RESOURCE_MAX_CORE5 > 0U)
#define OS_START_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
Os_ResourceType Os_TCBTaskResourceStackCore5[CFG_TASK_MAX_CORE5][CFG_STD_RESOURCE_MAX_CORE5];
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "Os_MemMap.h"
#endif              /* CFG_STD_RESOURCE_MAX_CORE5 > 0U */
/* PRQA S 1514-- */ /* MISRA Rule 8.9 */
/*=======[I N T E R N A L   D A T A]==========================================*/

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#if (CFG_TASK_MAX > 0U)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <Init the task control block>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0878, DD_1_0879, DD_1_1358, DD_1_1371, DD_1_0155, DD_1_0156>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InitTask(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_TaskType i;
#if (CFG_TASK_MAX > 0)
#if ((CFG_SPINLOCK_MAX > 0U) && (CFG_STD_RESOURCE_MAX > 0U))
    uint16 j;
#endif /* (CFG_SPINLOCK_MAX > 0U) && (CFG_STD_RESOURCE_MAX > 0U) */
#endif /* CFG_TASK_MAX > 0 */

    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTCB;
    P2CONST(Os_TaskCfgType, AUTOMATIC, OS_VAR) pTaskCfg;

    switch (Os_SCB.sysCore)
    {
#if (CFG_TASK_MAX_CORE0 > 0U)
    case 0:
        Os_TaskCfg = Os_TaskCfgCore0;
        Os_TaskStack = Os_TaskStackCore0;
        Os_TCB = Os_TCBCore0;
        OS_TASK_IDLE = Os_GetObjLocalId(OS_TASK_IDLE_CORE0);
        Os_CfgTaskMax = CFG_TASK_MAX_CORE0;

#if (CFG_STD_RESOURCE_MAX_CORE0 > 0U)
        for (i = 0U; i < CFG_TASK_MAX_CORE0; i++)
        {
            Os_TCBCore0[i].taskResourceStack = Os_TCBTaskResourceStackCore0[i];
        }
#endif /* CFG_STD_RESOURCE_MAX_CORE0 > 0U */
        break;
#endif /* CFG_TASK_MAX_CORE0 > 0U */

#if (CFG_TASK_MAX_CORE1 > 0U)
    case 1:
        Os_TaskCfg = Os_TaskCfgCore1;
        Os_TaskStack = Os_TaskStackCore1;
        Os_TCB = Os_TCBCore1;
        OS_TASK_IDLE = Os_GetObjLocalId(OS_TASK_IDLE_CORE1);
        Os_CfgTaskMax = CFG_TASK_MAX_CORE1;

#if (CFG_STD_RESOURCE_MAX_CORE1 > 0U)
        for (i = 0U; i < CFG_TASK_MAX_CORE1; i++)
        {
            Os_TCBCore1[i].taskResourceStack = Os_TCBTaskResourceStackCore1[i];
        }
#endif /* CFG_STD_RESOURCE_MAX_CORE1 > 0U */
        break;
#endif /* CFG_STD_RESOURCE_MAX_CORE1 > 0U */

#if (CFG_TASK_MAX_CORE2 > 0U)
    case 2:
        Os_TaskCfg = Os_TaskCfgCore2;
        Os_TaskStack = Os_TaskStackCore2;
        Os_TCB = Os_TCBCore2;
        OS_TASK_IDLE = Os_GetObjLocalId(OS_TASK_IDLE_CORE2);
        Os_CfgTaskMax = CFG_TASK_MAX_CORE2;

#if (CFG_STD_RESOURCE_MAX_CORE2 > 0U)
        for (i = 0U; i < CFG_TASK_MAX_CORE2; i++)
        {
            Os_TCBCore2[i].taskResourceStack = Os_TCBTaskResourceStackCore2[i];
        }
#endif /* CFG_STD_RESOURCE_MAX_CORE2 > 0U */
        break;
#endif /* CFG_TASK_MAX_CORE2 > 0U */

#if (CFG_TASK_MAX_CORE3 > 0U)
    case 3:
        Os_TaskCfg = Os_TaskCfgCore3;
        Os_TaskStack = Os_TaskStackCore3;
        Os_TCB = Os_TCBCore3;
        OS_TASK_IDLE = Os_GetObjLocalId(OS_TASK_IDLE_CORE3);
        Os_CfgTaskMax = CFG_TASK_MAX_CORE3;

#if (CFG_STD_RESOURCE_MAX_CORE3 > 0U)
        for (i = 0U; i < CFG_TASK_MAX_CORE3; i++)
        {
            Os_TCBCore3[i].taskResourceStack = Os_TCBTaskResourceStackCore3[i];
        }
#endif /* CFG_STD_RESOURCE_MAX_CORE3 > 0U */
        break;
#endif /* CFG_TASK_MAX_CORE3 > 0U */

#if (CFG_TASK_MAX_CORE4 > 0U)
    case 4:
        Os_TaskCfg = Os_TaskCfgCore4;
        Os_TaskStack = Os_TaskStackCore4;
        Os_TCB = Os_TCBCore4;
        OS_TASK_IDLE = Os_GetObjLocalId(OS_TASK_IDLE_CORE4);
        Os_CfgTaskMax = CFG_TASK_MAX_CORE4;

#if (CFG_STD_RESOURCE_MAX_CORE4 > 0U)
        for (i = 0U; i < CFG_TASK_MAX_CORE4; i++)
        {
            Os_TCBCore4[i].taskResourceStack = Os_TCBTaskResourceStackCore4[i];
        }
#endif /* CFG_STD_RESOURCE_MAX_CORE4 > 0U */
        break;
#endif /* CFG_TASK_MAX_CORE4 > 0U */

#if (CFG_TASK_MAX_CORE5 > 0U)
    case 5:
        Os_TaskCfg = Os_TaskCfgCore5;
        Os_TaskStack = Os_TaskStackCore5;
        Os_TCB = Os_TCBCore5;
        OS_TASK_IDLE = Os_GetObjLocalId(OS_TASK_IDLE_CORE5);
        Os_CfgTaskMax = CFG_TASK_MAX_CORE5;

#if (CFG_STD_RESOURCE_MAX_CORE5 > 0U)
        for (i = 0U; i < CFG_TASK_MAX_CORE5; i++)
        {
            Os_TCBCore5[i].taskResourceStack = Os_TCBTaskResourceStackCore5[i];
        }
#endif /* CFG_STD_RESOURCE_MAX_CORE5 > 0U */
        break;
#endif /* CFG_TASK_MAX_CORE5 > 0U */
    /*add comments to pass QAC.*/
    default:
        while (1)
        {
            /*nothing to do*/
        }
        break; /* PRQA S 2880 */ /* MISRA Rule 2.1 */
    }

#if (CFG_TASK_MAX > 0)
    for (i = 0u; i < Os_CfgTaskMax; i++)
    {
        pTCB = &Os_TCB[i];
        pTaskCfg = &Os_TaskCfg[i];

        pTCB->taskTop = Os_TaskStack[pTaskCfg->osTaskStackId].stackTop;
        pTCB->taskStackBottom = Os_TaskStack[pTaskCfg->osTaskStackId].stackBottom;

#if ((OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC))
        pTCB->taskActCount = 0u;
        pTCB->taskSelfActCount = 0u;
#endif /* (OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC) */

        pTCB->taskRunPrio = pTaskCfg->osTaskPriority;

/*multi-core for res and spinlock release as LIFO*/
#if ((CFG_SPINLOCK_MAX > 0U) && (CFG_STD_RESOURCE_MAX > 0U))
        pTCB->taskCriticalZoneCount = 0u;
        for (j = 0u; j < (uint16)CFG_CRITICAL_ZONE_MAX; j++)
        {
            pTCB->taskCriticalZoneStack[j] = OS_OBJECT_INVALID;
            pTCB->taskCriticalZoneType[j] = OBJECT_MAX;
        }
#endif /* (CFG_SPINLOCK_MAX > 0U) && (CFG_STD_RESOURCE_MAX > 0U) */

        if (0U != (pTaskCfg->osTaskAutoStartMode & Os_SCB.sysActiveAppMode))
        {
#if ((OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC))
            pTCB->taskActCount = pTCB->taskActCount + 1U;
#endif /* (OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC) */

            pTCB->taskState = TASK_STATE_START;

            Os_ReadyQueueInsert(i, OS_LEVEL_TASK, pTCB->taskRunPrio);
            /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
            if ((Os_SCB.sysHighPrio == OS_PRIORITY_INVALID) || (pTCB->taskRunPrio > Os_SCB.sysHighPrio))
            /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
            {
                Os_SCB.sysHighTaskID = i;
                Os_SCB.sysHighPrio = pTCB->taskRunPrio;
            }
        }
        else
        {
            pTCB->taskState = TASK_STATE_SUSPENDED;
        }

/* Init task stack */
#if ((TRUE == CFG_STACK_CHECK) && (CFG_TASK_MAX > 0U))
        Os_FillStack(Os_TaskStack[i]);
#endif /* (TRUE == CFG_STACK_CHECK) && (CFG_TASK_MAX > 0U) */
    }
#endif /* CFG_TASK_MAX > 0 */

    return;
}

/******************************************************************************/
/*
 * Brief                <The task <TaskID> is transferred from the suspended state into
 *                       the ready state>
 * Service ID           <OSServiceId_ActivateTask>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-TaskID[in]     <Reference to the task>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0005, DD_1_0006, DD_1_0631, DD_1_0632, DD_1_0633, DD_1_0634,
 *                       DD_1_0635, DD_1_1051, DD_1_1336, DD_1_1337, DD_1_1341, DD_1_1342,
 *                       DD_1_1344, DD_1_1345, DD_1_1354, DD_1_1357, DD_1_1370, DD_1_1372,
 *                       DD_1_1379, DD_1_1159, DD_1_1598, DD_1_1680>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) ActivateTask(TaskType TaskID)
{
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */
    StatusType Status = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_AT_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
    switch (Os_GetObjCoreId(TaskID))
    {
#if (CFG_TASK_MAX_CORE0 > 0U)
    case 0:
        if (Os_GetObjLocalId(TaskID) >= CFG_TASK_MAX_CORE0) /* PRQA S 2986 */ /* MISRA Rule 2.2 */
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_ActivateTask);
            OSError_Save_ActivateTask(TaskID);
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            Status = E_OS_ID;
        }
        break;
#endif /* CFG_TASK_MAX_CORE0 > 0U */

#if (CFG_TASK_MAX_CORE1 > 0U)
    case 1:
        if (Os_GetObjLocalId(TaskID) >= CFG_TASK_MAX_CORE1) /* PRQA S 2986 */ /* MISRA Rule 2.2 */
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_ActivateTask);
            OSError_Save_ActivateTask(TaskID);
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            Status = E_OS_ID;
        }
        break;
#endif /* CFG_TASK_MAX_CORE1 > 0U */

#if (CFG_TASK_MAX_CORE2 > 0U)
    case 2:
        if (Os_GetObjLocalId(TaskID) >= CFG_TASK_MAX_CORE2) /* PRQA S 2986 */ /* MISRA Rule 2.2 */
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_ActivateTask);
            OSError_Save_ActivateTask(TaskID);
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            Status = E_OS_ID;
        }
        break;
#endif /* CFG_TASK_MAX_CORE2 > 0U */

#if (CFG_TASK_MAX_CORE3 > 0U)
    case 3:
        if (Os_GetObjLocalId(TaskID) >= CFG_TASK_MAX_CORE3) /* PRQA S 2986 */ /* MISRA Rule 2.2 */
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_ActivateTask);
            OSError_Save_ActivateTask(TaskID);
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            Status = E_OS_ID;
        }
        break;
#endif /* CFG_TASK_MAX_CORE3 > 0U */

#if (CFG_TASK_MAX_CORE4 > 0U)
    case 4:
        if (Os_GetObjLocalId(TaskID) >= CFG_TASK_MAX_CORE4) /* PRQA S 2986 */ /* MISRA Rule 2.2 */
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_ActivateTask);
            OSError_Save_ActivateTask(TaskID);
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            Status = E_OS_ID;
        }
        break;
#endif /* CFG_TASK_MAX_CORE4 > 0U */

#if (CFG_TASK_MAX_CORE5 > 0U)
    case 5:
        if (Os_GetObjLocalId(TaskID) >= CFG_TASK_MAX_CORE5) /* PRQA S 2986 */ /* MISRA Rule 2.2 */
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_ActivateTask);
            OSError_Save_ActivateTask(TaskID);
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            Status = E_OS_ID;
        }
        break;
#endif /* CFG_TASK_MAX_CORE5 > 0U */
    default:
#if (TRUE == CFG_ERRORHOOK)
        OSError_Save_ServiceId(OSServiceId_ActivateTask);
        OSError_Save_ActivateTask(TaskID);
        Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

        Status = E_OS_ID;
        break;
    }

    if ((StatusType)E_OK == Status)
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
    {
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
        if (Os_WrongContext(OS_CONTEXT_ACTIVATE_TASK) != TRUE)
        {
            Status = E_OS_CALLEVEL;
        }
        else if (Os_IgnoreService() != TRUE)
        {
            Status = E_OS_DISABLEDINT;
        }
        else if (APPLICATION_ACCESSIBLE != Os_AppCB[Os_SCB.sysRunningAppID].appState)
        {
            Status = E_OS_ACCESS;
        }
        else if (Os_CheckObjAcs(OBJECT_TASK, TaskID) != TRUE)
        {
            Status = E_OS_ACCESS;
        }
        else
        {
            /*nothing to do*/
        }
#endif /* #if (TRUE == CFG_SERVICE_PROTECTION_ENABLE) */
    }

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if ((StatusType)E_OK == Status)
#endif /* #if (TRUE == CFG_SERVICE_PROTECTION_ENABLE) */
    {
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(TaskID);
        if (coreId != Os_SCB.sysCore)
        {
            if (Os_CoreCB.coreStatus[coreId] != OS_RUN)
            {
/*SWS_Os_00599*/
#if (TRUE == CFG_ERRORHOOK)
                Os_CallErrorHook(E_OS_CORE);
#endif /* TRUE == CFG_ERRORHOOK */

                Status = E_OS_CORE;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_ActivateTask;
                Os_InterCore[Os_SCB.sysCore].interParam.taskId = TaskID;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                /*SWS_Os_00598*/
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do. */
                }

                Status = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
#if (OS_AUTOSAR_CORES > 1)
            TaskID = Os_GetObjLocalId(TaskID);
#endif /*OS_AUTOSAR_CORES > 1*/

            OS_ARCH_ENTRY_CRITICAL();
            OS_AT_START_CRITICAL();

/* Timing protection: Check inter-arrival time. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
            if ((StatusType)E_OK != Os_TmProtTaskFrameChk(TaskID))
            {
                OS_ARCH_EXIT_CRITICAL();
                OS_AT_END_CRITICAL();

                Status = E_OS_ID;
            }
            else
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
            {
/* Basic Status */
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
                if (Os_TCB[TaskID].taskState != TASK_STATE_SUSPENDED)
#else
                if (Os_TCB[TaskID].taskActCount >= Os_TaskCfg[TaskID].osTaskActivation)
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */
                {
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_ActivateTask);
                    OSError_Save_ActivateTask(TaskID);
                    Os_CallErrorHook(E_OS_LIMIT);
#endif /* TRUE == CFG_ERRORHOOK */
                    OS_ARCH_EXIT_CRITICAL();
                    OS_AT_END_CRITICAL();

                    Status = E_OS_LIMIT;
                }
            }

            if ((StatusType)E_OK == Status)
            {
#if ((OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC))
                Os_TCB[TaskID].taskActCount = Os_TCB[TaskID].taskActCount + 1U;
                if (TaskID == Os_SCB.sysRunningTaskID)
                {
                    Os_TCB[TaskID].taskSelfActCount = Os_TCB[TaskID].taskSelfActCount + 1U;
                }
#endif /* (OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC) */

                if (TASK_STATE_SUSPENDED == Os_TCB[TaskID].taskState)
                {
                    Os_TCB[TaskID].taskState = TASK_STATE_START;
                }

                Os_ReadyQueueInsert(TaskID, OS_LEVEL_TASK, Os_TaskCfg[TaskID].osTaskPriority);

                if (Os_TaskCfg[TaskID].osTaskPriority > Os_SCB.sysHighPrio)
                {
                    Os_SCB.sysHighTaskID = TaskID;
                    Os_SCB.sysHighPrio = Os_TaskCfg[TaskID].osTaskPriority;

#if (CFG_SCHED_POLICY != OS_PREEMPTIVE_NON)
                    if (0U == Os_SCB.sysDispatchLocker)
                    {
                        OS_START_DISPATCH();
                        Os_Dispatch(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */
                    }
#endif                                                   /* #if (CFG_SCHED_POLICY != OS_PREEMPTIVE_NON) */
                }

                OS_ARCH_EXIT_CRITICAL();
                OS_AT_END_CRITICAL();
            }
        }
    }

    OS_AT_EXIT();
    return Status;
}

/******************************************************************************/
/*
 * Brief                <This service causes the termination of the calling task.>
 * Service ID           <OSServiceId_TerminateTask>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0007, DD_1_0012, DD_1_0636, DD_1_0640, DD_1_0637, DD_1_0638,
 *                       DD_1_0639, DD_1_1338, DD_1_1353, DD_1_1168, DD_1_1173, DD_1_1451,
 *                       DD_1_1599, DD_1_1681>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) TerminateTask(void) /* PRQA S 1505 */ /* MISRA Rule 8.7 */
{
#if (CFG_SPINLOCK_MAX > 0U)
    uint8 i;
    uint16 obj_id;
#endif /*#if (CFG_SPINLOCK_MAX > 0U)*/

    StatusType Status = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_TT_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
    if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel) /*only checked in extender status*/
    {
        Status = E_OS_CALLEVEL;
    }
    else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
        if (Os_WrongContext(OS_CONTEXT_TERMINATE_TASK) != TRUE)
    {
        Status = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        Status = E_OS_DISABLEDINT;
    }
    else
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */
    {
/* Extended Status */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
#if ((OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC))
        if (Os_SCB.sysOsLevel != OS_LEVEL_TASK)
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_TerminateTask);
            Os_CallErrorHook(E_OS_CALLEVEL);
#endif /* TRUE == CFG_ERRORHOOK */

            Status = E_OS_CALLEVEL;
        }
        else
#endif /* (OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC)*/
        {
#if (CFG_STD_RESOURCE_MAX > 0U)
            if (Os_TCB[Os_SCB.sysRunningTaskID].taskResCount > 0U)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_TerminateTask);
                Os_CallErrorHook(E_OS_RESOURCE);
#endif /* TRUE == CFG_ERRORHOOK */

                Status = E_OS_RESOURCE;
            }
            else
#endif /* CFG_STD_RESOURCE_MAX > 0U */
            {
#if (CFG_SPINLOCK_MAX > 0U)
                /*Os_00612*/
                for (i = 0u; i < CFG_SPINLOCK_MAX; i++)
                {
                    if (OBJECT_TASK == Os_SLCB[i].objOccupyType)
                    {
                        obj_id = Os_SLCB[i].objOccupyId;
                        if ((Os_GetObjLocalId(obj_id) == Os_SCB.sysRunningTaskID)
                            && (Os_SCB.sysCore == Os_GetObjCoreId(obj_id)))
                        {
#if (TRUE == CFG_PROTECTIONHOOK)
                            (void)Os_CallProtectionHook(E_OS_SPINLOCK, OS_NO_CARE);
#endif /* TRUE == CFG_PROTECTIONHOOK */

                            Status = E_OS_SPINLOCK;
                            break;
                        }
                    }
                }
#endif /*#if (CFG_SPINLOCK_MAX > 0U)*/
            }
        }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        if ((StatusType)E_OK == Status)
        {
            OS_ARCH_ENTRY_CRITICAL();
            OS_TT_START_CRITICAL();

#if (TRUE == CFG_POSTTASKHOOK)
            Os_CallPostTaskHook();
#endif /* TRUE == CFG_POSTTASKHOOK */

#if (CFG_INTERNAL_RESOURCE_MAX > 0U)
            Os_ReleaseInternalResource(Os_SCB.sysRunningTaskID);
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0U */

#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
            Os_SCB.sysRunningTCB->taskState = TASK_STATE_SUSPENDED;

#else
            if (Os_SCB.sysRunningTCB->taskSelfActCount > 0U)
            {
                Os_SCB.sysRunningTCB->taskSelfActCount = Os_SCB.sysRunningTCB->taskSelfActCount - 1U;
            }
            if (Os_SCB.sysRunningTCB->taskActCount > 0U)
            {
                Os_SCB.sysRunningTCB->taskActCount = Os_SCB.sysRunningTCB->taskActCount - 1U;
            }

            if (Os_SCB.sysRunningTCB->taskActCount > 0U)
            {
                Os_SCB.sysRunningTCB->taskState = TASK_STATE_START;
            }
            else
            {
                Os_SCB.sysRunningTCB->taskState = TASK_STATE_SUSPENDED;
            }
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */

            Os_ReadyQueueRemove(OS_LEVEL_TASK, Os_TCB[Os_SCB.sysRunningTaskID].taskRunPrio);

#if (CFG_STD_RESOURCE_MAX > 0U)
            Os_SCB.sysRunningTCB->taskResCount = 0U;
#endif /* CFG_STD_RESOURCE_MAX > 0U */

            Os_SCB.sysRunningTCB->taskRunPrio = Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskPriority;

#if (CFG_EXTENDED_TASK_MAX > 0U)
            if (Os_SCB.sysRunningTaskID < Os_CfgExtendTaskMax)
            {
                Os_ECB[Os_SCB.sysRunningTaskID].eventSetEvent = 0U;
                Os_ECB[Os_SCB.sysRunningTaskID].eventWaitEvent = 0U;
            }
#endif                                                                             /* CFG_EXTENDED_TASK_MAX > 0U */

            if (Os_SCB.sysHighTaskID == Os_SCB.sysRunningTaskID) /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
            {
                Os_SCB.sysHighPrio = Os_GetHighPrio();
                Os_SCB.sysHighTaskID = Os_ReadyQueueGetFirst(Os_SCB.sysHighPrio);
            }

/* Timing protection: reset task exe time. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
            Os_TmProtTaskEnd(Os_SCB.sysRunningTaskID, TP_TASK_EXE);
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

            Os_SCB.sysDispatchLocker = 0U;

            OS_START_DISPATCH();
            Os_Dispatch(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */

            OS_ARCH_EXIT_CRITICAL();
            OS_TT_END_CRITICAL();
        }
    }

    OS_TT_EXIT();
    return Status;
}

/******************************************************************************/
/*
 * Brief                <This service causes the termination of the calling task. After
 *                       termination of the calling task a succeeding task <TaskID> is
 *                       activated. Using this service, it ensures that the succeeding
 *                       task starts to run at the earliest after the calling task has been
 *                       terminated.>
 * Service ID           <OSServiceId_TerminateTask>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-TaskID[in]     <Reference to the task>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0641, DD_1_0642, DD_1_0643, DD_1_0644, DD_1_0645, DD_1_0646,
 *                       DD_1_0647, DD_1_1053, DD_1_0012, DD_1_1339, DD_1_1346, DD_1_1355,
 *                       DD_1_1380, DD_1_1165, DD_1_1169, DD_1_1174, DD_1_1453, DD_1_1552,
 *                       DD_1_1600, DD_1_1682>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) ChainTask(TaskType TaskID) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */
#if (CFG_SPINLOCK_MAX > 0U)
    uint8 i;
    uint16 obj_id;
#endif /* CFG_SPINLOCK_MAX > 0U */
    StatusType Status = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_CT_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
    if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel) /*only checked in extender status*/
    {

        OSError_Save_ServiceId(OSServiceId_ChainTask);
        OSError_Save_ChainTask(TaskID);
        Status = E_OS_CALLEVEL;
    }
    else
#endif /*#if (OS_STATUS_EXTENDED == CFG_STATUS)*/
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
        if (Os_WrongContext(OS_CONTEXT_CHAIN_TASK) != TRUE)
    {
        OSError_Save_ServiceId(OSServiceId_ChainTask);
        OSError_Save_ChainTask(TaskID);

        Status = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        Status = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_TASK, TaskID) != TRUE)
    {
        Status = E_OS_ACCESS;
    }
    else
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */
    {
#if (OS_STATUS_EXTENDED == CFG_STATUS)
#if (CFG_STD_RESOURCE_MAX > 0U)
        if (Os_TCB[Os_SCB.sysRunningTaskID].taskResCount > (Os_ResourceType)0)
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_ChainTask);
            OSError_Save_ChainTask(TaskID);
            Os_CallErrorHook(E_OS_RESOURCE);
#endif /* TRUE == CFG_ERRORHOOK */

            Status = E_OS_RESOURCE;
        }
        else
#endif /* #if (CFG_STD_RESOURCE_MAX > 0U) */
        {
#if (CFG_SPINLOCK_MAX > 0U)
            /*Os_00612*/
            for (i = 0u; i < CFG_SPINLOCK_MAX; i++)
            {
                if (OBJECT_TASK == Os_SLCB[i].objOccupyType)
                {
                    obj_id = Os_SLCB[i].objOccupyId;
                    if ((Os_GetObjLocalId(obj_id) == Os_SCB.sysRunningTaskID)
                        && (Os_SCB.sysCore == Os_GetObjCoreId(obj_id)))
                    {
#if (TRUE == CFG_PROTECTIONHOOK)
                        (void)Os_CallProtectionHook(E_OS_SPINLOCK, OS_NO_CARE);
#endif /* TRUE == CFG_PROTECTIONHOOK */

                        Status = E_OS_SPINLOCK;
                        break;
                    }
                }
            }
#endif /*#if (CFG_SPINLOCK_MAX > 0U)*/
        }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        if ((StatusType)E_OK == Status)
        {
#if (OS_AUTOSAR_CORES > 1)
            coreId = Os_GetObjCoreId(TaskID);
            if (coreId != Os_SCB.sysCore)
            {
                if (Os_CoreCB.coreStatus[coreId] != OS_RUN)
                {
#if (TRUE == CFG_ERRORHOOK)
                    Os_CallErrorHook(E_OS_CORE);
#endif /* TRUE == CFG_ERRORHOOK */

                    Status = E_OS_CORE;
                }
                else
                {
                    OS_ARCH_ENTRY_CRITICAL();
                    Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                    Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_ChainTask;
                    Os_InterCore[Os_SCB.sysCore].interParam.taskId = TaskID;
                    /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                    Os_ArchRemoteCall(coreId);
                    /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                    while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                    {
                        /* Nothing to do. */
                    }

                    if ((StatusType)E_OK == Os_InterCore[Os_SCB.sysCore].interState)
                    {
                        Os_InterCore[Os_SCB.sysCore].interState = TerminateTask();
                    }

                    Status = Os_InterCore[Os_SCB.sysCore].interState;
                    OS_ARCH_EXIT_CRITICAL();
                }
            }
            else
#endif /*#if (OS_AUTOSAR_CORES > 1)*/
            {
#if (OS_AUTOSAR_CORES > 1)
                TaskID = Os_GetObjLocalId(TaskID);
#endif

/* Extended Status */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
                if (TaskID >= Os_CfgTaskMax)
                {
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_ChainTask);
                    OSError_Save_ChainTask(TaskID);
                    Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                    Status = E_OS_ID;
                }
                else
#endif /* (OS_STATUS_EXTENDED == CFG_STATUS) */
                {
/* Basic Status */
#if ((OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC))
                    if ((Os_TCB[TaskID].taskActCount >= Os_TaskCfg[TaskID].osTaskActivation)
                        && (TaskID != Os_SCB.sysRunningTaskID))
#else
                    if ((Os_TCB[TaskID].taskState != TASK_STATE_SUSPENDED) && (TaskID != Os_SCB.sysRunningTaskID))
#endif /* (OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC) */
                    {
#if (TRUE == CFG_ERRORHOOK)
                        OSError_Save_ServiceId(OSServiceId_ChainTask);
                        OSError_Save_ChainTask(TaskID);
                        Os_CallErrorHook(E_OS_LIMIT);
#endif /* TRUE == CFG_ERRORHOOK */

                        Status = E_OS_LIMIT;
                    }
                }

                if ((StatusType)E_OK == Status)
                {
#if (TRUE == CFG_POSTTASKHOOK)
                    Os_CallPostTaskHook();
#endif /* TRUE == CFG_POSTTASKHOOK */

                    OS_ARCH_ENTRY_CRITICAL();
                    OS_CT_START_CRITICAL();

#if (CFG_INTERNAL_RESOURCE_MAX > 0)
                    Os_ReleaseInternalResource(Os_SCB.sysRunningTaskID);
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0 */

#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
                    Os_SCB.sysRunningTCB->taskState = TASK_STATE_SUSPENDED;
#else
                    if (Os_SCB.sysRunningTCB->taskSelfActCount > 0U)
                    {
                        Os_SCB.sysRunningTCB->taskSelfActCount = Os_SCB.sysRunningTCB->taskSelfActCount - 1U;
                    }
                    if (Os_SCB.sysRunningTCB->taskActCount > 0U)
                    {
                        Os_SCB.sysRunningTCB->taskActCount = Os_SCB.sysRunningTCB->taskActCount - 1U;
                    }

                    if (Os_SCB.sysRunningTCB->taskActCount > 0U)
                    {
                        Os_SCB.sysRunningTCB->taskState = TASK_STATE_START;
                    }
                    else
                    {
                        Os_SCB.sysRunningTCB->taskState = TASK_STATE_SUSPENDED;
                    }
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */

                    Os_ReadyQueueRemove(OS_LEVEL_TASK, Os_TCB[Os_SCB.sysRunningTaskID].taskRunPrio);

#if (CFG_STD_RESOURCE_MAX > 0U)
                    Os_SCB.sysRunningTCB->taskResCount = 0u;
#endif /* CFG_STD_RESOURCE_MAX > 0U */

                    Os_SCB.sysRunningTCB->taskRunPrio = Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskPriority;

#if (CFG_EXTENDED_TASK_MAX > 0)
                    if (Os_SCB.sysRunningTaskID < Os_CfgExtendTaskMax)
                    {
                        Os_ECB[Os_SCB.sysRunningTaskID].eventSetEvent = 0u;
                        Os_ECB[Os_SCB.sysRunningTaskID].eventWaitEvent = 0u;
                    }
#endif /* CFG_EXTENDED_TASK_MAX > 0U */

/* Timing protection: reset task exe time. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
                    Os_TmProtTaskEnd(Os_SCB.sysRunningTaskID, TP_TASK_EXE);
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

/* Timing protection: Check inter-arrival time. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
                    if ((StatusType)E_OK != Os_TmProtTaskFrameChk(TaskID))
                    {
                        Status = E_OS_ID;
                    }
                    else
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
                    {
#if ((OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC))
                        Os_TCB[TaskID].taskActCount = Os_TCB[TaskID].taskActCount + 1U;

                        if (TASK_STATE_SUSPENDED == Os_TCB[TaskID].taskState)
                        {
                            Os_TCB[TaskID].taskState = TASK_STATE_START;
                        }
#else
                        Os_TCB[TaskID].taskState = TASK_STATE_START;
#endif /* (OS_BCC2 == CFG_CC) || (OS_ECC2 == CFG_CC) */

                        Os_ReadyQueueInsert(TaskID, OS_LEVEL_TASK, Os_TaskCfg[TaskID].osTaskPriority);

                        if (Os_SCB.sysHighTaskID == Os_SCB.sysRunningTaskID) /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
                        {
                            Os_SCB.sysHighPrio = Os_GetHighPrio();
                            Os_SCB.sysHighTaskID = Os_ReadyQueueGetFirst(Os_SCB.sysHighPrio);
                        }

                        Os_SCB.sysDispatchLocker = 0u;

                        OS_START_DISPATCH();
                        Os_Dispatch(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */
                    }
                    OS_ARCH_EXIT_CRITICAL();
                    OS_CT_END_CRITICAL();
                }
            }
        }
    }

    OS_CT_EXIT();
    return Status;
}

/******************************************************************************/
/*
 * Brief                <If a higher-priority task is ready, the internal
 *                       resource of the task is released, the current task
 *                       is put into the ready state, its context is saved and
 *                       the higher-priority task is executed.
 *                       Otherwise the calling task is continued.>
 * Service ID           <OSServiceId_Schedule>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-Name[in]       <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0648, DD_1_0649, DD_1_1340, DD_1_1343, DD_1_1356, DD_1_1452,
 *                       DD_1_1601, DD_1_1683>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) Schedule(void) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
#if (CFG_SPINLOCK_MAX > 0U)
    uint8 i;
    uint16 obj_id;
#endif /*#if (CFG_SPINLOCK_MAX > 0U)*/

    StatusType Status = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_SCHEDULE_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
    if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
    {
        /*only checked in extend status*/
        Status = E_OS_CALLEVEL;
    }
    else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
        if (Os_WrongContext(OS_CONTEXT_SCHEDULE) != TRUE)
    {
        Status = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        Status = E_OS_DISABLEDINT;
    }
    else
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE) */
    {
/* Extended Status */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
#if ((OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC))
        if (Os_SCB.sysOsLevel != OS_LEVEL_TASK)
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_Schedule);
            Os_CallErrorHook(E_OS_CALLEVEL);
#endif /* TRUE == CFG_ERRORHOOK */

            Status = E_OS_CALLEVEL;
        }
        else
#endif /*if ((OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC))*/
        {
#if (CFG_STD_RESOURCE_MAX > 0U)
            if (Os_TCB[Os_SCB.sysRunningTaskID].taskResCount > (Os_ResourceType)0)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_Schedule);
                Os_CallErrorHook(E_OS_RESOURCE);
#endif /* TRUE == CFG_ERRORHOOK */

                Status = E_OS_RESOURCE;
            }
            else
#endif /* #if (CFG_STD_RESOURCE_MAX > 0U) */
            {
#if (CFG_SPINLOCK_MAX > 0U)
                /*Os_00612*/
                for (i = 0u; i < CFG_SPINLOCK_MAX; i++)
                {
                    if (OBJECT_TASK == Os_SLCB[i].objOccupyType)
                    {
                        obj_id = Os_SLCB[i].objOccupyId;
                        if ((Os_GetObjLocalId(obj_id) == Os_SCB.sysRunningTaskID)
                            && (Os_SCB.sysCore == Os_GetObjCoreId(obj_id)))
                        {
#if (TRUE == CFG_PROTECTIONHOOK)
                            (void)Os_CallProtectionHook(E_OS_SPINLOCK, OS_NO_CARE);
#endif /* TRUE == CFG_PROTECTIONHOOK */

                            Status = E_OS_SPINLOCK;
                            break;
                        }
                    }
                }
#endif /*#if (CFG_SPINLOCK_MAX > 0U)*/
            }
        }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        if ((StatusType)E_OK == Status)
        {
            OS_ARCH_ENTRY_CRITICAL();
            OS_SCHEDULE_START_CRITICAL();

/* Basic Status */
#if (CFG_INTERNAL_RESOURCE_MAX > 0)
            if (Os_InterResCeiling[Os_SCB.sysRunningTaskID] != (Os_PriorityType)0)
            {
                Os_ReleaseInternalResource(Os_SCB.sysRunningTaskID);
                Os_SCB.sysRunningTCB->taskRunPrio = Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskPriority;
            }
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0 */

            Os_SCB.sysHighPrio = Os_GetHighPrio();
            Os_SCB.sysHighTaskID = Os_ReadyQueueGetFirst(Os_SCB.sysHighPrio);

            if (Os_SCB.sysHighTaskID != Os_SCB.sysRunningTaskID) /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
            {
                Os_SCB.sysDispatchLocker = 0u;

                OS_START_DISPATCH();
                Os_Dispatch(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */
            }

#if (CFG_INTERNAL_RESOURCE_MAX > 0)
            Os_GetInternalResource();
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0 */

            OS_ARCH_EXIT_CRITICAL();
            OS_SCHEDULE_END_CRITICAL();
        }
    }

    OS_SCHEDULE_EXIT();
    return Status;
}

/******************************************************************************/
/*
 * Brief                <TaskID Reference to the task which is currently running
 *                       Description: GetTaskID returns the information about the
 *                       TaskID of the task which is currently running.>
 * Service ID           <OSServiceId_GetTaskID>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-TaskID[in]     <Reference to the task>
 * Param-Name[out]      <TaskID>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0650, DD_1_0652, DD_1_0651, DD_1_1055, DD_1_1602, DD_1_1637,
 *                       DD_1_1684>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) GetTaskID(TaskRefType TaskID) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    OS_GTI_ENTRY();
    StatusType Status = E_OK;

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_TASK_ID) != TRUE)
    {
        Status = E_OS_CALLEVEL;
    }
    else if (Os_AddressWritable((uint8*)TaskID) != TRUE)
    {
        Status = E_OS_ILLEGAL_ADDRESS;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        Status = E_OS_DISABLEDINT;
    }
    else
#endif /*TRUE == CFG_SERVICE_PROTECTION_ENABLE*/
    {
        /*null pointer check*/
        if (NULL_PTR == TaskID)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_ILLEGAL_ADDRESS);
#endif /* TRUE == CFG_ERRORHOOK */

            Status = E_NOT_OK;
        }
        else
        {
            if (OS_TASK_IDLE == Os_SCB.sysRunningTaskID)
            {
                *TaskID = OS_TASK_INVALID;
            }
            else
            {
                /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
                *TaskID = Os_SCB.sysRunningTaskID | (Os_SCB.sysCore << 12u);
                /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
            }
        }
    }

    OS_GTI_EXIT();

    return Status;
}

/******************************************************************************/
/*
 * Brief                <Returns the state of a task (running, ready, waiting, suspended)
 *                       at the time of calling GetTaskState.>
 * Service ID           <OSServiceId_GetTaskState>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-TaskID[in]     <Reference to the task>
 * Param-State[out]     <Reference to the state of the task <TaskID>>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0653, DD_1_0654, DD_1_0655, DD_1_1056, DD_1_1381, DD_1_1177,
 *                       DD_1_1175, DD_1_1603, DD_1_1685>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) GetTaskState(TaskType TaskID, TaskStateRefType State) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */
    StatusType Status = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_GTS_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
    /*null pointer check*/
    if (NULL_PTR == State)
    {
#if (TRUE == CFG_ERRORHOOK)
        Os_CallErrorHook(E_OS_ILLEGAL_ADDRESS);
#endif /* TRUE == CFG_ERRORHOOK */

        Status = E_NOT_OK;
    }
    else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
        if (Os_WrongContext(OS_CONTEXT_GET_TASK_STATE) != TRUE)
    {
        Status = E_OS_CALLEVEL;
    }
    else if (Os_AddressWritable((uint8*)State) != TRUE)
    {
        Status = E_OS_ILLEGAL_ADDRESS;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        Status = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_TASK, TaskID) != TRUE)
    {
        Status = E_OS_ACCESS;
    }
    else
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */
    {
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(TaskID);
        if (coreId != Os_SCB.sysCore)
        {
            if (Os_CoreCB.coreStatus[coreId] != OS_RUN)
            {
/*SWS_Os_00599*/
#if (TRUE == CFG_ERRORHOOK)
                Os_CallErrorHook(E_OS_CORE);
#endif /* TRUE == CFG_ERRORHOOK */

                Status = E_OS_CORE;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_GetTaskState;
                Os_InterCore[Os_SCB.sysCore].interParam.taskId = TaskID;
                Os_InterCore[Os_SCB.sysCore].interParam.taskState = State;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                /*SWS_Os_00598*/
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do. */
                }

                Status = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /* #if (OS_AUTOSAR_CORES > 1)*/
        {
#if (OS_AUTOSAR_CORES > 1)
            TaskID = Os_GetObjLocalId(TaskID);
#endif

/* Extended Status */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (TaskID >= Os_CfgTaskMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_GetTaskState);
                OSError_Save_GetTaskState(TaskID, State);
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                Status = E_OS_ID;
            }
            else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            {
                OS_ARCH_ENTRY_CRITICAL();
                if (TASK_STATE_START == Os_TCB[TaskID].taskState)
                {
                    *State = TASK_STATE_READY;
                }
                else
                {
                    *State = Os_TCB[TaskID].taskState;
                }
                OS_ARCH_EXIT_CRITICAL();
            }
        }
    }

    OS_GTS_EXIT();
    return Status;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if (CFG_TASK_MAX > 0U) */
/*=======[E N D   O F   F I L E]==============================================*/
