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
**  FILENAME    : Os.h                                                        **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yaoxuan.zhang                                               **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

#ifndef OS_H
#define OS_H

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2013-04-15  yaoxuan.zhang       Initial version.
 *  V0.2.0       2013-06-19  huaming             modified the format of macro definition,and
 *                                             added the information about MISRAC rule.
 *  V0.3.0       2013-07-02  yaoxuan.zhang       Add the declare of error hook function.
 *  V0.4.0       2013-07-23  yaoxuan.zhang       Modified the code to adapt MISRA C specification.
 *  V0.5.0       2014-11-11  bo.zeng             code refactor.
 *  V0.6.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li             Functional safety version.
 *  V1.1.0       2020-04-21  shun.li             Add IOC function.
 */
/*============================================================================*/

/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
  ModeName:Alarm<br>
  RuleSorce:puhua-rule.rcf 2.3.1

    \li PRQA S 3415 MISRA Rule 13.5
    .<br> Reason:function in && comparison does not need to be called when the first condition fails.

    \li PRQA S 0488 MISRA Rule 18.4
    .<br> Reason:The offending items are pointer operations on arrays or addresses.

    \li PRQA S 2986 MISRA Rule 2.2
    .<br> Reason:If condition is a macro definition, which varies in different projs.

    \li PRQA S 3200,1840,0306 MISRA Rule 17.7,10.4,11.4
    .<br> Reason:Rely on C embedded assembly implementation, different platform solutions are different.

    \li PRQA S 0306 MISRA Rule 11.4
    .<br> Reason:Realize needs.

    \li PRQA S 2741,2742 MISRA Rule 17.3
    .<br> Reason:Macro function implementation, different callers have different conditions.

    \li PRQA S 3206,2982 MISRA Dir 2.7,2.2
    .<br> Reason:The program body is a precompiled macro, which will be different in different projects or
            Rely on C embedded assembly implementation, different platform solutions are different.

    \li PRQA S 1514 MISRA Rule 8.9
    .<br> Reason:Global variables that need to be updated by dependent applications.

    \li PRQA S 1514 MISRA Rule 8.9
    .<br> Reason:Open up memory space and operate by pointer to the space.

    \li PRQA S 2983 MISRA Rule 2.2
    .<br> Reason:Reserved for easy expansion Or In assembly code use.

    \li PRQA S 1505 MISRA Rule 8.7
    .<br> Reason:Functions may be used in other projects.

    \li PRQA S 3200 MISRA Rule 17.7
    .<br> Reason:Rely on C embedded assembly implementation, different platform solutions are different.

    \li PRQA S 1504 MISRA Rule 8.7
    .<br> Reason:Configuration file design implementation needs.

    \li PRQA S 3335,MISRA Rule 17.3
    .<br> Reason:The porting part calls the compiler library function, and the solutions of different
            platforms are different.

    \li PRQA S 0303 MISRA Rule 11.4
    .<br> Reason:Realize needs.

    \li PRQA S 2872 MISRA Dir 4.1 .<br>
    Reason:Realize needs.

    \li PRQA S 2877 MISRA Dir 4.1
    .<br> Reason:for loop condition is a macro definition, which varies in different projs.

    \li PRQA S 3335,2880 MISRA Rule 17.3,2.1
    .<br> Reason:The porting part calls the compiler library function, and the solutions of different
            platforms are different.

    \li PRQA S 2981 MISRA Rule 2.2
    .<br> Reason:Init may be necessary for different macro definition.

    \li PRQA S 1503 MISRA Rule 2.1
    .<br> Reason:Functions may be used in other projects.

    \li PRQA S 0404 MISRA Rule 1.3,13.2
    .<br> Reason:The design avoids the possible impact of access timing.

    \li PRQA S 1532 MISRA Rule 8.7
    .<br> Reason:Functions may be used in other projects.

    \li PRQA S 2880 MISRA Rule 2.1
    .<br> Reason:Authentication requires further implementation.

    \li PRQA S 3432 MISRA Rule 20.7
    .<br> Reason:Function-like macros are used to allow more efficient code.

    \li PRQA S 1533 MISRA Rule 8.9 .<br>
    Reason:Configuration data design is required.

    \li PRQA S 0779 MISRA Rule 1.3, Rule 5.2 .<br>
    Reason:Since the variable name is dynamically generated, the previous name
            is consistent.

    \li PRQA S 4499 MISRA Rule 10.6 .<br>
    Reason:The design scheme ensures that arithmetic left shift will not cause data corruption.

    \li PRQA S 3408 MISRA Rule 8.4 .<br>
    Reason:Define the interrupt entry function, which will not be directly called by the outside.

    \li PRQA S 0791 MISRA Rule 5.4 .<br>
    Reason:Configuration data design is required.

    \li PRQA S 3684,0632 MISRA Rule 8.11,1.3 .<br>
    Reason:The array name is only used to identify the memory address, and the design scheme
            determines that there will be no accidental risk.

    \li PRQA S 2810 MISRA Rule 1.3 .<br>
    Reason:The null pointer is used to obtain the relative position of the structure variable.

    \li PRQA S 2810 MISRA Rule 1.3 .<br>
    Reason:The ++ or -- operation is performed on the address, and the operation will not be
            performed multiple times at the same time, and the result will not be confusing.

    \li PRQA S 2962 MISRA Rule 9.1 .<br>
    Reason:The scheme design guarantees that it will be initialized at least once.

    \li PRQA S 3218 MISRA Rule 8.9 .<br>
    Reason:Variables will be used in functions and compilation.

    \li PRQA S 2961 MISRA Rule 2.1 .<br>
    Reason:Will be assigned in assembly.

    \li PRQA S 0499 MISRA Rule 12.2 .<br>
    Reason:Shift operations will not exceed the width of the destination type.

    \li PRQA S 0341 MISRA Rule 20.10 .<br>
    Reason:The string "#" is a specific compiler syntax.

    \li PRQA S 0342 MISRA Rule 20.10 .<br>
    Reason:Currently commonly used compiler versions support this preprocessing symbol.

   \li PRQA S 0883 MISRA Dir 4.10 .<br>
    Reason:<module>_MemMap.h needs to be dynamically referenced multiple times based on pre compiled macros,
            so that duplicate inclusion protection cannot be used.

    \li PRQA S 2306 MISRA Rule 2.7 .<br>
    Reason:The input parameters will be used in C embedded assembly.

    \li PRQA S 2318 MISRA Rule 8.9 .<br>
    Reason:This parameter is not only used in one function but also utilized in other assemblies.

    \li PRQA S 4543,4542,4532,4559,4523, MISRA Rule 10.1 .<br>
    Reason:Necessary data type conversion

    \li PRQA S 3332 MISRA Rule 20.9 .<br>
    Reason:Different configurations produce variations.
*/

/*=======[M I S R A C  R U L E  V I O L A TI O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Err.h"
#include "Os_CfgData.h"

/*=======[M A C R O S]========================================================*/
#define OS_VENDOR_ID 62
#define OS_MODULE_ID 1
/*=======[T Y P E   D E F I N I T I O N S]====================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/
#if (CFG_STD_RESOURCE_MAX > 0U)
extern VAR(Os_ResourceType, OS_VAR) RES_SCHEDULER;
#endif /* CFG_STD_RESOURCE_MAX > 0U */
/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
#if (CFG_TASK_MAX > 0U)
/******************************************************************************/
/*
 * Brief               <The task<TaskID> is transferred from the  suspended
 *                      state into the  ready  state>
 * ServiceId           <0x00>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <TaskID: Task reference>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <StatusType:>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) ActivateTask(TaskType TaskID);

/******************************************************************************/
/*
 * Brief               <This service causes the termination of the calling task. The
                        calling task is transferred from the  running state into the
                        suspended  state>
 * ServiceId           <0x01>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <StatusType:>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) TerminateTask(void);

/******************************************************************************/
/*
 * Brief               <This service causes the  termination of the calling task. After
                        termination of the calling task  a succeeding task <TaskID> is
                        activated>
 * ServiceId           <0x02>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <StatusType:>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) ChainTask(TaskType TaskID);

/******************************************************************************/
/*
 * Brief               <If a higher-priority task is ready , the internal resource
 *                      of the task is released, the current task is put into the
 *                      ready  state, its context is saved and the highe r-priority
 *                      task is executed. Otherwise the calling task is continued.>
 * ServiceId           <0x03>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) Schedule(void);

/******************************************************************************/
/*
 * Brief               <GetTaskID  returns the information about the TaskID of
 *                      the task which is currently  running>
 * ServiceId           <0x04>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) GetTaskID(TaskRefType TaskID);

/******************************************************************************/
/*
 * Brief               <Returns the state of a task (running, ready, waiting,
 *                      suspended)at the time of calling GetTaskState.>
 * ServiceId           <0x23>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) GetTaskState(TaskType TaskID, TaskStateRefType State);
#endif /* (CFG_TASK_MAX > 0U) */

#if (CFG_STD_RESOURCE_MAX > 0U)
/******************************************************************************/
/*
 * Brief               <This call serves to enter critical sections in the code
 *                      that are assigned to the resource referenced by <ResID>.
 *                      A critical section shall always be left using ReleaseResource.>
 * ServiceId           <0x05>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) GetResource(ResourceType ResID);

/******************************************************************************/
/*
 * Brief               <ReleaseResource  is the counterpart of  GetResource  and
 *                      serves to leave critical sections in the code that are
 *                      assigned to the resource referenced by <ResID>.>
 * ServiceId           <0x06>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) ReleaseResource(ResourceType ResID);
#endif /* (CFG_STD_RESOURCE_MAX > 0U)*/

#if (CFG_EXTENDED_TASK_MAX > 0U)
/******************************************************************************/
/*
 * Brief               <The events of task <TaskID> are set according to the event
 *                      mask <Mask>. Calling SetEvent causes the task <TaskID> to
 *                      be transferred to the  ready  state, if it was waiting for
 *                      at least one of the events specified in <Mask>.>
 * ServiceId           <0x07>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) SetEvent(TaskType TaskID, EventMaskType Mask);

/******************************************************************************/
/*
 * Brief               <The events of the extended task calling ClearEvent are
 *                      cleared according to the event mask <Mask>.>
 * ServiceId           <0x08>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) ClearEvent(EventMaskType Mask);

/******************************************************************************/
/*
 * Brief               <This service returns the current state of all event bits
 *                      of the task <TaskID>, not the events that the task is
 *                      waiting for.>
 * ServiceId           <0x09>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) GetEvent(TaskType TaskID, EventMaskRefType Event);

/******************************************************************************/
/*
 * Brief               <The state of the calling task is set to waiting, unless
 *                      at least one of the events specified in <Mask> has
 *                      already been set.>
 * ServiceId           <0x10>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) WaitEvent(EventMaskType Mask);
#endif /* (CFG_EXTENDED_TASK_MAX > 0U) */

#if (CFG_ALARM_MAX > 0U)
/******************************************************************************/
/*
 * Brief               <The system service GetAlarm returns the relative value in
 *                     ticks before the alarm <AlarmID> expires.>
 * ServiceId           <0x12>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) GetAlarm(AlarmType AlarmID, TickRefType Tick);

/******************************************************************************/
/*
 * Brief               <The system service  GetAlarmBase  reads the alarm base
 *                      characteristics. The return value  <Info> is a structure
 *                      in which the information of data type AlarmBaseType
 *                      is stored.>
 * ServiceId           <0x11>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info);

/******************************************************************************/
/*
 * Brief               <The system service cancels the alarm <AlarmID>.>
 * ServiceId           <0x15>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) CancelAlarm(AlarmType AlarmID);

/******************************************************************************/
/*
 * Brief               <The system service occupies the alarm <AlarmID> element.
 *                      After <increment> ticks have elapsed, the task assigned
 *                      to the alarm <AlarmID> is activated or  the assigned event
 *                      (only for extended tasks) is set or the alarm-callback
 *                      routine is called.>
 * ServiceId           <0x13>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) SetRelAlarm(AlarmType AlarmID, TickType increment, TickType cycle);

/******************************************************************************/
/*
 * Brief               <The system service occupies the alarm <AlarmID> element.
 *                      When <start> ticks are reached, the task assigned to the
 *                      alarm <AlarmID> is activated or the assigned event (only
 *                      for extended tasks) is set or the alarm-callback routine
 *                      is called.>
 * ServiceId           <0x14>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) SetAbsAlarm(AlarmType AlarmID, TickType start, TickType cycle);
#endif /* (CFG_ALARM_MAX > 0U) */

#if (CFG_COUNTER_MAX > 0U)
/******************************************************************************/
/*
 * Brief               <>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) IncrementCounter(CounterType CounterID);

/******************************************************************************/
/*
 * Brief               <>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) GetCounterValue(CounterType CounterID, TickRefType Value);

/******************************************************************************/
/*
 * Brief               <>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) GetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue);
#endif /* (CFG_COUNTER_MAX > 0U) */

/******************************************************************************/
/*
 * Brief               <This service returns t he current application mode. It
 *                      may be used to write mode dependent code.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(AppModeType, OS_CODE) GetActiveApplicationMode(void);

/******************************************************************************/
/*
 * Brief               <This service disables  all interrupts for which the hardware
 *                      supports disabling. The state before is saved for the
 *                      EnableAllInterrupts call.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) DisableAllInterrupts(void);

/******************************************************************************/
/*
 * Brief               <This service restores the state saved by  DisableAllInterrupts.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) EnableAllInterrupts(void);

/******************************************************************************/
/*
 * Brief               <This service restores t he recognition status of all
 *                      interrupts saved by the  SuspendAllInterrupts service.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) ResumeAllInterrupts(void);

/******************************************************************************/
/*
 * Brief               <This service saves the re cognition status of all
 *                      interrupts and disables all interrupts for which the
 *                      hardware supports.>
disabling.
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) SuspendAllInterrupts(void);

/******************************************************************************/
/*
 * Brief               <>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) ResumeOSInterrupts(void);

/******************************************************************************/
/*
 * Brief               <This service restores the recognition status of interrupts
 *                     saved by the SuspendOSInterrupts service.>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) SuspendOSInterrupts(void);

/******************************************************************************/
/*
 * Brief               <The user can call this  system service to start the
 *                      operating system in a specific mode.>
 * ServiceId           <0x16>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) StartOS(AppModeType Mode);

/******************************************************************************/
/*
 * Brief               <The user can call this system service to abort the overall
 *                      system (e.g. emergency off).>
 * ServiceId           <0x17>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) ShutdownOS(StatusType Error);

/******************************************************************************/
/*
 * Brief               <OS_ShutdownAllCores.>
 * ServiceId           <0x17>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) OS_ShutdownAllCores(StatusType Error);

#if (CFG_SCHEDTBL_MAX > 0U)
#if ((OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC))
/******************************************************************************/
/*
 * Brief               <Start schedule table before getting sync counter.>
 * ServiceId           <0x1C>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ScheduleTableID>
 * Param-Name[out]     <StatusType>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) StartScheduleTableSynchron(ScheduleTableType ScheduleTableID);

/******************************************************************************/
/*
 * Brief               <Set sync counter value to schedule table.>
 * ServiceId           <0x1E>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ScheduleTableID, value>
 * Param-Name[out]     <StatusType>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) SyncScheduleTable(ScheduleTableType ScheduleTableID, TickType value);

/******************************************************************************/
/*
 * Brief               <Stop schedule table explicit sync and set state to running.>
 * ServiceId           <0x1F>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ScheduleTableID>
 * Param-Name[out]     <StatusType>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) SetScheduleTableAsync(ScheduleTableType ScheduleTableID);
#endif /* (OS_SC2 == CFG_SC) || (OS_SC4 == CFG_SC) */

/******************************************************************************/
/*
 * Brief               <Stop schedule table and set state to stop.>
 * ServiceId           <0x1A>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ScheduleTableID>
 * Param-Name[out]     <StatusType>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) StopScheduleTable(ScheduleTableType ScheduleTableID);

/******************************************************************************/
/*
 * Brief               <Start schedule table using abs tick value.>
 * ServiceId           <0x19>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ScheduleTableID, Start>
 * Param-Name[out]     <StatusType>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) StartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start);

/******************************************************************************/
/*
 * Brief               <Start schedule table using relative tick value.>
 * ServiceId           <0x18>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ScheduleTableID, Offset>
 * Param-Name[out]     <StatusType>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) StartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset);

/******************************************************************************/
/*
 * Brief               <Set next schedule table of ScheduleTableID_From.>
 * ServiceId           <0x1B>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ScheduleTableID_From, ScheduleTableID_To>
 * Param-Name[out]     <StatusType>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE)
    NextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);

/******************************************************************************/
/*
 * Brief               <Get status of schedule table.>
 * ServiceId           <0x1D>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <ScheduleTableID>
 * Param-Name[out]     <ScheduleStatus>
 * Param-Name[in/out]  <None>
 * Return              <StatusType>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE)
    GetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus);
#endif /* (CFG_SCHEDTBL_MAX > 0U) */

/******************************************************************************/
/*
 * Brief               <Get ID of ISR.>
 * ServiceId           <0x>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <ISRType>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(ISRType, OS_CODE) GetISRID(void);

/******************************************************************************/
/*
 * Brief               <This hook routine is called  by the operating system  at
 *                      the end of a system service which return s StatusType not
 *                      equal E_OK. It is called before returning to the task level>
 * ServiceId           <0x00>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
#if (TRUE == CFG_ERRORHOOK)
extern FUNC(void, OS_APPL_CODE) ErrorHook(StatusType Error);
#endif /* #if (TRUE == CFG_ERRORHOOK) */

/******************************************************************************/
/*
 * Brief               <This hook routine is  called by the operat ing system before
 *                      executing a new task, but after t he transition of the task to
 *                      the running state (to allow evaluation of the TaskID by
 *                      GetTaskID).>
 * ServiceId           <0x00>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
#if (TRUE == CFG_PRETASKHOOK)
extern FUNC(void, OS_APPL_CODE) PreTaskHook(void);
#endif /* (TRUE == CFG_PRETASKHOOK) */

/******************************************************************************/
/*
 * Brief               <This hook routine is called by the operating system after
 *                      executing the current task, but before leaving the task's
 *                      running state (to allow evaluation of the TaskID by
 *                      GetTaskID).>
 * ServiceId           <0x00>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
#if (TRUE == CFG_POSTTASKHOOK)
extern FUNC(void, OS_APPL_CODE) PostTaskHook(void);
#endif /* (TRUE == CFG_POSTTASKHOOK) */

/******************************************************************************/
/*
 * Brief               <This hook routine is called  by the operating system at
 *                      the end of the operating system in itialisation and before
 *                      the scheduler is running. At this time the application
 *                      can initialise device drivers etc.>
 * ServiceId           <0x00>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
#if (TRUE == CFG_STARTUPHOOK)
extern FUNC(void, OS_APPL_CODE) StartupHook(void);
#endif /* (TRUE == CFG_STARTUPHOOK) */

/******************************************************************************/
/*
 * Brief               <This hook routine is ca lled by the operating system when
 *                      the OS service ShutdownOS  has been called. This routine is
 *                      called during the operating system shut down.>
 * ServiceId           <0x00>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
#if (TRUE == CFG_SHUTDOWNHOOK)
extern FUNC(void, OS_APPL_CODE) ShutdownHook(StatusType Error);
#endif /* (TRUE == CFG_SHUTDOWNHOOK) */

/******************************************************************************/
/*
 * Brief               <This hook routine is called by the operating system when
 *                      the OS service idle task.>
 * ServiceId           <0x00>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
#if (CFG_TASK_MAX_CORE0 > 0U)
extern FUNC(void, OS_APPL_CODE) IdleHook_Core0(void);
#endif /* CFG_TASK_MAX_CORE0 > 0U */
#if (CFG_TASK_MAX_CORE1 > 0U)
extern FUNC(void, OS_APPL_CODE) IdleHook_Core1(void);
#endif /* CFG_TASK_MAX_CORE1 > 0U */
#if (CFG_TASK_MAX_CORE2 > 0U)
extern FUNC(void, OS_APPL_CODE) IdleHook_Core2(void);
#endif /* CFG_TASK_MAX_CORE2 > 0U */
#if (CFG_TASK_MAX_CORE3 > 0U)
extern FUNC(void, OS_APPL_CODE) IdleHook_Core3(void);
#endif /* CFG_TASK_MAX_CORE3 > 0U */
#if (CFG_TASK_MAX_CORE4 > 0U)
extern FUNC(void, OS_APPL_CODE) IdleHook_Core4(void);
#endif /* CFG_TASK_MAX_CORE4 > 0U */
#if (CFG_TASK_MAX_CORE5 > 0U)
extern FUNC(void, OS_APPL_CODE) IdleHook_Core5(void);
#endif /* CFG_TASK_MAX_CORE5 > 0U */
/******************************************************************************/
/*
 * Brief               <This hook routine is called by the operating system when
 *                      the OS service protection functions.>
 * ServiceId           <0x00>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <None>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
#if ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_PROTECTIONHOOK)
extern FUNC(ProtectionReturnType, OS_CODE) ProtectionHook(StatusType Fatalerror);
#endif /* TRUE == CFG_PROTECTIONHOO */
#endif /* (OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC */

#if (CFG_OSAPPLICATION_MAX > 0)
/******************************************************************************/
/*
 * Brief               <This service determines the currently running
                        OS-Application (a unique identifierhas to be
                        allocated to each application)>
 * Service ID          <OSServiceId_GetApplicationID>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * param-Name[in]      <None>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <OS-Application>
                       <INVALID_OSAPPLICATION>
 * Caveats             <None>
 * Configuration       <SC3 and SC4>
 */
/******************************************************************************/
extern FUNC(ApplicationType, OS_CODE) GetApplicationID(void);

/******************************************************************************/
/*
 * Brief               <This service determines the currently running
 *                      OS-Application (a unique identifier has to be
 *                      allocated to each application)>
 * Service ID          <OSServiceId_GetCurrentApplicationID>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Return              <OS-Application id>
 * PreCondition        <SC3 and SC4>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(ApplicationType, OS_CODE) GetCurrentApplicationID(void);

/******************************************************************************/
/*
 * Brief               <This service sets the own state of an OS-Application
 *                      from APPLICATION_RESTARTING to APPLICATION_ACCESSIBLE.>
 * Service ID          <OSServiceId_AllowAccess>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Return              <StatusType>
 * PreCondition        <SC3 and SC4>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) AllowAccess(void);

/******************************************************************************/
/*
 * Brief               <This service returns the current state of an OS-Application.>
 * Service ID          <OSServiceId_GetApplicationState>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * Return              <StatusType>
 * PreCondition        <SC3 and SC4>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) GetApplicationState(ApplicationType Application, ApplicationStateRefType Value);

/******************************************************************************/
/*
 * Brief               <This service determines if the OS-Applications,
                        given by ApplID, is allowed to use the IDs of a
                        Task, ISR, Resource,Counter, Alarm or Schedule
                        Table in API calls.>
 * Service ID          <OSServiceId_CheckObjectAccess>
 * Sync/Async          <Synchronous>
 * Reentrancy          < Reentrant>
 * param-Name[in]      <ApplID>
                       <ObjectType>
                       <...>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <ACCESS>
                       <NO_ACCESS>
 * Caveats             <None>
 * Configuration       <SC3 and SC4>
 */
/******************************************************************************/
extern FUNC(ObjectAccessType, OS_CODE)
    CheckObjectAccess(ApplicationType ApplID, ObjectTypeType ObjectType, AppObjectId ObjectID);

/******************************************************************************/
/*
 * Brief               <This service determines to which OS-Application
                        a given Task, ISR, Resource, Counter, Alarm or
                        Schedule Table belongs>
 * Service ID          <OSServiceId_CheckObjectOwnership>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * param-Name[in]      <ObjectType>
                       <...>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <OS-Application>
                       <INVALID_APPLICATION>
 * Cavests             <None>
 * Configuration       <SC3 and SC4>
 */
/******************************************************************************/
extern FUNC(ApplicationType, OS_CODE) CheckObjectOwnership(ObjectTypeType ObjectType, AppObjectId ObjectID);

/******************************************************************************/
/*
 * Brief               <Terminate Application>
 * ServiceId           <OSServiceId_TerminateApplication>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Yes>
 * Param-Name[in]      <RestartOption>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <E_OS_CALLEVEL>
 *                     <E_OS_VALUE>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) TerminateApplication(ApplicationType Application, RestartType RestartOption);
#endif /* CFG_OSAPPLICATION_MAX > 0 */

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
/******************************************************************************/
/*
 * Brief               <This service determines some ISR can or not access some memory range>
 * Service ID          <OSServiceId_CheckISRMemoryAccess>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * param-Name[in]      <ISRID>
 *                     <Address>
 *                     <Size>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <NO_ACCESS>
                       <ACCESS>
 * Caveats             <None>
 * Configuration       <SC3 and SC4>
 */
/******************************************************************************/
extern FUNC(AccessType, OS_CODE)
    CheckISRMemoryAccess(ISRType ISRID, MemoryStartAddressType Address, MemorySizeType Size);

/******************************************************************************/
/*
 * Brief               <This service determines some task can or not access some memory range>
 * Service ID          <OSServiceId_CheckISRMemoryAccess>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * param-Name[in]      <TaskID>
 *                     <Address>
 *                     <Size>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <NO_ACCESS>
                       <ACCESS>
 * Caveats             <None>
 * Configuration       <SC3 and SC4>
 */
/******************************************************************************/
extern FUNC(AccessType, OS_CODE)
    CheckTaskMemoryAccess(TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size);
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */

#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0U)
/******************************************************************************/
/*
 * Brief               <This service call trusted function>
 * Service ID          <OSServiceId_CallTrustedFunction>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * param-Name[in]      <FunctionIndex>
 *                     <FunctionParams>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <E_OK>
                       <E_OS_SERVICEID>
 * Caveats             <None>
 * Configuration       <SC3 and SC4>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE)
    CallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
#endif /* (CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0U) */

#if (CFG_SPINLOCK_MAX > 0U)
/******************************************************************************/
/*
 * Brief               <GetSpinlock>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <SpinlockId>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <StatusType>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) GetSpinlock(SpinlockIdType SpinlockId);

/******************************************************************************/
/*
 * Brief               <ReleaseSpinlock>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <SpinlockId>
 * Param-Name[out]     <None>
 * Param-Name[in/out]  <None>
 * Return              <StatusType>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) ReleaseSpinlock(SpinlockIdType SpinlockId);

/******************************************************************************/
/*
 * Brief               <TryToGetSpinlock>
 * ServiceId           <None>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Non Reentrant>
 * Param-Name[in]      <SpinlockId>
 * Param-Name[out]     <Success>
 * Param-Name[in/out]  <None>
 * Return              <StatusType>
 * PreCondition        <None>
 * CallByAPI           <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) TryToGetSpinlock(SpinlockIdType SpinlockId, TryToGetSpinlockType* Success);
#endif /* CFG_SPINLOCK_MAX > 0U */

/******************************************************************************/
/*
 * Brief               <The function starts the core specified by the CoreID. >
 * Service ID          <OSServiceId_StartCore>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * param-CoreID[in]    <Reference to the core>
 * Param-Status[out]   <Return value of the function>
 * return              <StatusType>
 * PreCondition        <Not support calling the API after calling StartOS.>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) StartCore(CoreIdType CoreID, StatusType* Status);

/******************************************************************************/
/*
 * Brief               <The function starts the core specified by the parameter
 *                      CoreID. It is allowed to call this function after StartOS().>
 * Service ID          <OSServiceId_StartNonAutosarCore>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * param-CoreID[in]    <Reference to the core>
 * Param-Status[out]   <Return value of the function>
 * return              <StatusType>
 * PreCondition        <None>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) StartNonAutosarCore(CoreIdType CoreID, StatusType* Status);

/******************************************************************************/
/*
 * Brief               <This API allows the caller to select the idle mode
 *                      action which is performed during idle time of the OS>
 * Service ID          <OSServiceId_ControlIdle>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * param-CoreID[in]    <selects the core which idle mode is set>
 * param-IdleMode[in]  <the mode which shall be performed during idle time>
 * return              <StatusType, Return result of the function>
 * PreCondition        <None>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) ControlIdle(CoreIdType CoreID, IdleModeType IdleMode);

/******************************************************************************/
/*
 * Brief               <The function returns the number of cores activated by
 *                      the StartCore function.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * return              <Number of cores activated by the StartCore function.>
 * PreCondition        <None>
 */
/******************************************************************************/
extern FUNC(uint32, OS_CODE) GetNumberOfActivatedCores(void);

/******************************************************************************/
/*
 * Brief               <The function returns a unique core identifier.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * return              <CoreIdType, The return value is the unique ID of the core.>
 * PreCondition        <None>
 */
/******************************************************************************/
extern FUNC(CoreIdType, OS_CODE) GetCoreID(void);

/******************************************************************************/
/*
 * Brief               <After this service the OS on all AUTOSAR cores is shut down.>
 * Sync/Async          <Synchronous>
 * Reentrancy          <Reentrant>
 * param-Error[in]     <needs to be a valid error code supported by the AUTOSAR OS.>
 * return              <None>
 * PreCondition        <Allowed at TASK and ISR level and internally by the OS.>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) ShutdownAllCores(StatusType Error);

/******************************************************************************/
/*
 * Brief                <Init the IOC control block list>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <>
 */
/******************************************************************************/
extern FUNC(void, OS_CODE) Os_InitIoc(void);

/******************************************************************************/
/*
 * Brief                <In case of queued communication identified by the <IocId>
 *                       in the function name, the content of the IOC internal
 *                       communication queue shall be deleted.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <>
 * REQ ID               <>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) Os_IocHLEmptyQueue(Os_IocAbsIdType absId);

/******************************************************************************/
/*
 * Brief                <>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) Os_IocHLTransmit(Os_IocAbsIdType absId, const Os_IocDataSourceType* pData);

/******************************************************************************/
/*
 * Brief                <>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <>
 */
/******************************************************************************/
extern FUNC(StatusType, OS_CODE) Os_IocHLReceive(Os_IocAbsIdType absId, const Os_IocDataSourceType* pData);

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[I N T E R N A L   D A T A]==========================================*/

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

#endif /* #ifndef OS_H */

/*=======[E N D   O F   F I L E]==============================================*/
