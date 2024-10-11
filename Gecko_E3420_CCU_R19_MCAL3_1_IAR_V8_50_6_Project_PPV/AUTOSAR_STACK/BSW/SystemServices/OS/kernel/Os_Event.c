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
**  FILENAME    : Os_Event.c                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yaoxuan.zhang                                               **
**  Vendor      :                                                             **
**  DESCRIPTION : event manager                                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2013-04-15  yaoxuan.zhang       Initial version.
 *  V0.2.0       2013-07-23  yaoxuan.zhang       Modified the code to adapt MISRA
 *                                             C specification.
 *  V0.3.0       2014-11-16  bo.zeng             code refactor.
 *  V0.4.0       2016-12-13  shi.shu             Multi-core Initial version.
 *  V0.5.0       2019-08-21  shun.li & zhiqiang.huang  Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li             Functional safety version.
 *  V1.0.1       2021-08-19  shun.li             Modify release spinlock in mutlti-core.
 */
/*============================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

/*=======[M A C R O S]========================================================*/

/*=======[T Y P E   D E F I N I T I O N S]====================================*/
#if (CFG_EXTENDED_TASK_MAX > 0)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint16, OS_VAR) Os_CfgExtendTaskMax = 0;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
/*=======[E X T E R N A L   D A T A]==========================================*/

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[I N T E R N A L   D A T A]==========================================*/

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
/******************************************************************************/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
/******************************************************************************/
/*
 * Brief                <Init the Event control block>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * param-eventId[in]    <Event control block id>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0789, DD_1_0790>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InitEvent(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_TaskType i;

    for (i = 0U; i < CFG_EXTENDED_TASK_MAX; i++)
    {
        Os_ECB[i].eventSetEvent = 0U;
        Os_ECB[i].eventWaitEvent = 0U;
    }

    switch (Os_SCB.sysCore)
    {
#if (CFG_EXTENDED_TASK_MAX_CORE0 > 0U)
    case 0:
        Os_CfgExtendTaskMax = CFG_EXTENDED_TASK_MAX_CORE0;
        break;
#endif /* CFG_EXTENDED_TASK_MAX_CORE0 > 0U */

#if (CFG_EXTENDED_TASK_MAX_CORE1 > 0U)
    case 1:
        Os_CfgExtendTaskMax = CFG_EXTENDED_TASK_MAX_CORE1;
        break;
#endif /* CFG_EXTENDED_TASK_MAX_CORE1 > 0U */

#if (CFG_EXTENDED_TASK_MAX_CORE2 > 0U)
    case 2:
        Os_CfgExtendTaskMax = CFG_EXTENDED_TASK_MAX_CORE2;
        break;
#endif /* CFG_EXTENDED_TASK_MAX_CORE2 > 0U */

#if (CFG_EXTENDED_TASK_MAX_CORE3 > 0U)
    case 3:
        Os_CfgExtendTaskMax = CFG_EXTENDED_TASK_MAX_CORE3;
        break;
#endif /* CFG_EXTENDED_TASK_MAX_CORE3 > 0U */

#if (CFG_EXTENDED_TASK_MAX_CORE4 > 0U)
    case 4:
        Os_CfgExtendTaskMax = CFG_EXTENDED_TASK_MAX_CORE4;
        break;
#endif /* CFG_EXTENDED_TASK_MAX_CORE4 > 0U */

#if (CFG_EXTENDED_TASK_MAX_CORE5 > 0U)
    case 5:
        Os_CfgExtendTaskMax = CFG_EXTENDED_TASK_MAX_CORE5;
        break;
#endif /* CFG_EXTENDED_TASK_MAX_CORE5 > 0U */

    default:
        Os_CfgExtendTaskMax = 0;
        break;
    }
}

/******************************************************************************/
/*
 * Brief                <The service may be called from an interrupt service routine and
 *                       from the task level, but not from hook routines.
 *                       The events of task <TaskID> are set according to the event
 *                       mask <Mask>. Calling SetEvent causes the task <TaskID> to
 *                       be transferred to the ready state, if it was waiting for at least
 *                       one of the events specified in <Mask>>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-TaskID[in]     <Reference to the task for which one or several events are to be set.>
 * param-Mask[in]       <Mask of the events to be set>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0008, DD_1_0681, DD_1_1065, DD_1_0684, DD_1_0682, DD_1_0683,
 *                       DD_1_1179, DD_1_1180, DD_1_1181, DD_1_1182, DD_1_1183, DD_1_1459,
 *                       DD_1_1460, DD_1_1575, DD_1_1656, DD_1_0684>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) SetEvent(TaskType TaskID, EventMaskType Mask)
{
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */
    StatusType OsReturnErr = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_SE_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_SET_EVENT) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_TASK, TaskID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
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

                OsReturnErr = E_OS_CORE;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_SetEvent;
                Os_InterCore[Os_SCB.sysCore].interParam.taskId = TaskID;
                Os_InterCore[Os_SCB.sysCore].interParam.eventMask = Mask;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                /*SWS_Os_00598*/
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do. */
                }

                OsReturnErr = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /* #if (OS_AUTOSAR_CORES > 1) */
        {
#if (OS_AUTOSAR_CORES > 1)
            TaskID = Os_GetObjLocalId(TaskID);
#endif /* OS_AUTOSAR_CORES > 1 */

/* Extended Status */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (TaskID >= Os_CfgTaskMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_SetEvent);
                OSError_Save_SetEvent(TaskID, Mask);
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else if (TaskID >= Os_CfgExtendTaskMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_SetEvent);
                OSError_Save_SetEvent(TaskID, Mask);
                Os_CallErrorHook(E_OS_ACCESS);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ACCESS;
            }
            else if (TASK_STATE_SUSPENDED == Os_TCB[TaskID].taskState)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_SetEvent);
                OSError_Save_SetEvent(TaskID, Mask);
                Os_CallErrorHook(E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_STATE;
            }
            else
            {
                /*nothing to do*/
            }
            if ((StatusType)E_OK == OsReturnErr)
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            {
                OS_ARCH_ENTRY_CRITICAL();
                OS_SE_START_CRITICAL();

/* Timing protection: Check inter-arrival time. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
                if ((StatusType)E_OK != Os_TmProtTaskFrameChk(TaskID))
                {
                    OsReturnErr = E_OS_ID;
                }
                else
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */
                {
                    /* Standard Status */
                    Os_ECB[TaskID].eventSetEvent |= Mask;

                    if (TASK_STATE_WAITING == Os_TCB[TaskID].taskState)
                    {
                        if ((Os_ECB[TaskID].eventSetEvent & Os_ECB[TaskID].eventWaitEvent) != 0u)
                        {
                            Os_TCB[TaskID].taskState = TASK_STATE_READY;

                            Os_ReadyQueueInsert(TaskID, OS_LEVEL_TASK, Os_TCB[TaskID].taskRunPrio);

                            if (Os_TCB[TaskID].taskRunPrio > Os_SCB.sysHighPrio)
                            {
                                Os_SCB.sysHighTaskID = TaskID;
                                Os_SCB.sysHighPrio = Os_TCB[TaskID].taskRunPrio;

#if (CFG_SCHED_POLICY != OS_PREEMPTIVE_NON)
                                if (Os_SCB.sysDispatchLocker == 0u)
                                {
                                    OS_START_DISPATCH();
                                    Os_Dispatch(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */
                                }
#endif                                                               /* CFG_SCHED_POLICY != OS_PREEMPTIVE_NON */
                            }
                        }
                    }
                }
                OS_SE_END_CRITICAL();
                OS_ARCH_EXIT_CRITICAL();
            }
        }
    }

    OS_SE_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <The state of the calling task is set to waiting, unless
 *                       at least one of the events specified in <Mask> has
 *                       already been set.
 *                       Particularities: This call enforces rescheduling,
 *                       if the wait condition occurs. If rescheduling takes
 *                       place, the internal resource of the task is released
 *                       while the task is in the waiting state.
 *                       This service must only be called from the extended task
 *                       owning the event.
 *                       The system service ClearEvent is restricted to extended
 *                       taskswhich own the event.>
 * Service ID           <OSServiceId_WaitEvent>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-Mask[in]       <Mask of the events to be set>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_1019, DD_1_0689, DD_1_0690, DD_1_1186, DD_1_1229, DD_1_1454,
 *                       DD_1_1455, DD_1_1576, DD_1_1657, DD_1_1018>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) WaitEvent(EventMaskType Mask) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
#if (CFG_SPINLOCK_MAX > 0U)
    SpinlockIdType i;
    uint16 obj_id;
#endif /* CFG_SPINLOCK_MAX > 0U */
    StatusType OsReturnErr = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_WE_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
    if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel) /*only checked in extender status*/
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
        if (Os_WrongContext(OS_CONTEXT_WAIT_EVENT) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */
    {
#if (OS_STATUS_EXTENDED == CFG_STATUS)
#if ((OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC))
        if (Os_SCB.sysOsLevel != OS_LEVEL_TASK)
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_WaitEvent);
            OSError_Save_WaitEvent(Mask);
            Os_CallErrorHook(E_OS_CALLEVEL);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_CALLEVEL;
        }
        else
#endif /*if ((OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC))*/
        {
            if (Os_SCB.sysRunningTaskID >= Os_CfgExtendTaskMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_WaitEvent);
                OSError_Save_WaitEvent(Mask);
                Os_CallErrorHook(E_OS_ACCESS);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ACCESS;
            }
#if (CFG_STD_RESOURCE_MAX > 0U)
            else if (Os_TCB[Os_SCB.sysRunningTaskID].taskResCount > 0u)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_WaitEvent);
                OSError_Save_WaitEvent(Mask);
                Os_CallErrorHook(E_OS_RESOURCE);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_RESOURCE;
            }
#endif /* #if (CFG_STD_RESOURCE_MAX > 0U) */
            else
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

                            OsReturnErr = E_OS_SPINLOCK;
                            break;
                        }
                    }
                }
#endif /* CFG_SPINLOCK_MAX > 0U */
            }
        }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        if ((StatusType)E_OK == OsReturnErr)
        {
            OS_ARCH_ENTRY_CRITICAL();
            OS_WE_START_CRITICAL();

            /* Standard Status */
            Os_ECB[Os_SCB.sysRunningTaskID].eventWaitEvent = Mask;

            if (0u == (Os_ECB[Os_SCB.sysRunningTaskID].eventSetEvent & Mask))
            {
#if (TRUE == CFG_POSTTASKHOOK)
                Os_CallPostTaskHook();
#endif /* TRUE == CFG_POSTTASKHOOK */

#if (CFG_INTERNAL_RESOURCE_MAX > 0)
                Os_ReleaseInternalResource(Os_SCB.sysRunningTaskID);
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0 */

                Os_TCB[Os_SCB.sysRunningTaskID].taskState = TASK_STATE_WAITING;

                Os_ReadyQueueRemove(OS_LEVEL_TASK, Os_TCB[Os_SCB.sysRunningTaskID].taskRunPrio);

                Os_TCB[Os_SCB.sysRunningTaskID].taskRunPrio = Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskPriority;

/* Timing protection: reset task exe time. OS473. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
                Os_TmProtTaskEnd(Os_SCB.sysRunningTaskID, TP_TASK_EXE);
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

                Os_SCB.sysHighPrio = Os_GetHighPrio();
                Os_SCB.sysHighTaskID = Os_ReadyQueueGetFirst(Os_SCB.sysHighPrio);
                Os_SCB.sysDispatchLocker = 0u;

                OS_START_DISPATCH();
                Os_Dispatch(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */
            }

            OS_ARCH_EXIT_CRITICAL();
            OS_WE_END_CRITICAL();
        }
    }

    OS_WE_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <This service returns the current state of all event
 *                       bits of the task
 *                       <TaskID>, not the events that the task is waiting for.
 *                       The service may be called from interrupt service
 *                       routines, task level and some hook routines
 *                       (see Figure 12-1).
 *                       The current status of the event mask of task <TaskID>
 *                       is copied to <Event>.
 *                       The referenced task must be an extended task.>
 * Service ID           <OSServiceId_GetEvent>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-TaskID[in]     <Reference to the task for which one or several events
 *                       are to be set.>
 * Param-Event[out]     <Reference to the memory of the return data>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0687, DD_1_1067, DD_1_1185, DD_1_1456, DD_1_1457, DD_1_1458,
 *                       DD_1_1577, DD_1_1635, DD_1_1658, DD_1_0688>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) GetEvent(TaskType TaskID, EventMaskRefType Event) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    StatusType OsReturnErr = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_GE_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_EVENT) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_AddressWritable((uint8*)Event) != TRUE)
    {
        OsReturnErr = E_OS_ILLEGAL_ADDRESS;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */
    {
#if (OS_AUTOSAR_CORES > 1)
        if (Os_SCB.sysCore != Os_GetObjCoreId(TaskID))
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_CORE);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_CORE;
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
#if (OS_AUTOSAR_CORES > 1)
            TaskID = Os_GetObjLocalId(TaskID);
#endif /*OS_AUTOSAR_CORES > 1*/

/* Extended Status */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (TaskID >= Os_CfgTaskMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_GetEvent);
                OSError_Save_GetEvent(TaskID, Event);
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else if (TaskID >= Os_CfgExtendTaskMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_GetEvent);
                OSError_Save_GetEvent(TaskID, Event);
                Os_CallErrorHook(E_OS_ACCESS);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ACCESS;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                if (TASK_STATE_SUSPENDED == Os_TCB[TaskID].taskState)
                {
                    OS_ARCH_EXIT_CRITICAL();
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_GetEvent);
                    OSError_Save_GetEvent(TaskID, Event);
                    Os_CallErrorHook(E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_STATE;
                }

                if ((StatusType)E_OK == OsReturnErr)
                {
                    *Event = Os_ECB[TaskID].eventSetEvent;
                    OS_ARCH_EXIT_CRITICAL();
                }
            }
#else
            if ((StatusType)E_OK == OsReturnErr)
            {
                /* Standard Status */
                OS_ARCH_ENTRY_CRITICAL();
                *Event = Os_ECB[TaskID].eventSetEvent;
                OS_ARCH_EXIT_CRITICAL();
            }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
        }
    }

    OS_GE_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <The events of the extended task calling ClearEvent are cleared
 *                       according to the event mask <Mask>.
 *                       The system service ClearEvent is restricted to extended tasks which own the event.>
 * Service ID           <OSServiceId_ClearEvent>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-Mask[in]       <Mask of the events to be set>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0685, DD_1_1184, DD_1_1578, DD_1_1659, DD_1_0686>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) ClearEvent(EventMaskType Mask) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    StatusType OsReturnErr = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_CE_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
    if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel) /*only checked in extender status*/
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
        if (Os_WrongContext(OS_CONTEXT_CLEAR_EVENT) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */
    {
#if (OS_STATUS_EXTENDED == CFG_STATUS)
#if ((OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC))
        if (Os_SCB.sysOsLevel != OS_LEVEL_TASK)
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_ServiceId(OSServiceId_ClearEvent);
            OSError_Save_ClearEvent(Mask);
            Os_CallErrorHook(E_OS_CALLEVEL);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_CALLEVEL;
        }
        else
#endif /* (OS_NOSC == CFG_SC) || (OS_SC1 == CFG_SC) || (OS_SC2 == CFG_SC) */
        {
            if (Os_SCB.sysRunningTaskID >= Os_CfgExtendTaskMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_ClearEvent);
                OSError_Save_ClearEvent(Mask);
                Os_CallErrorHook(E_OS_ACCESS);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ACCESS;
            }
        }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        if ((StatusType)E_OK == OsReturnErr)
        {
            OS_ARCH_ENTRY_CRITICAL();
            Os_ECB[Os_SCB.sysRunningTaskID].eventSetEvent &= (~Mask);
            OS_ARCH_EXIT_CRITICAL();
        }
    }

    OS_CE_EXIT();
    return OsReturnErr;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if (CFG_EXTENDED_TASK_MAX > 0) */
/*=======[E N D   O F   F I L E]==============================================*/
