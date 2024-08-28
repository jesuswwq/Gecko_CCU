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
**  FILENAME    : Os_Err.h                                                    **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yaoxuan.zhang                                               **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2013-04-15  yaoxuan.zhang       Initial version.
 *  V0.2.0       2013-06-19  huaming             modified the format of macro definition,and
 *                                             added the information about MISRAC rule.
 *  V0.3.0       2013-07-22  yaoxuan.zhang       Add error hook reference macro definition.
 *  V0.4.0       2013-07-23  yaoxuan.zhang       Modified the code to adapt MISRA C specification.
 *  V0.5.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li             Functional safety version.
 *  V1.0.1       2021-5-6    shun.li             Repair interrupt disable problem caused by
 *                                               "OsUseGetServiceId" and "OsUseParameterAccess" functions.
 */
/*========================================================================*/

#ifndef OS_ERR_H
#define OS_ERR_H

/*=======[M I S R A C  R U L E  V I O L A T I O N]========================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*========================================================================*/

/*=======[I N C L U D E S]=================================================*/
#include "Os_Cfg.h"

/*=======[M A C R O S]=====================================================*/

/*=======[T Y P E   D E F I N I T I O N S]==================================*/

/*=======[E X T E R N A L   D A T A]========================================*/

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]======*/
#if (TRUE == CFG_USEGETSERVICEID)
#define OSErrorGetServiceId()             Os_SCB.sysOsServiceId;

#define OSError_Save_ServiceId(ServiceId) Os_SCB.sysOsServiceId = (ServiceId);

#else
#define OSErrorGetServiceId()
#define OSError_Save_ServiceId(ServiceId)
#endif /* #if (TRUE == CFG_USEGETSERVICEID) */

#if (TRUE == CFG_USEPARAMETERACCESS)
#define OSError_ActivateTask_TaskID()     Os_SCB.sysRunTimeSrvPrarm.taskId;

#define OSError_ChainTask_TaskID()        Os_SCB.sysRunTimeSrvPrarm.taskId;

#define OSError_GetTaskID_TaskID()        Os_SCB.sysRunTimeSrvPrarm.taskRef;

#define OSError_GetTaskState_TaskID()     Os_SCB.sysRunTimeSrvPrarm.taskId;

#define OSError_GetTaskState_State()      Os_SCB.sysRunTimeSrvPrarm.taskState;

#define OSError_GetResource_ResID()       Os_SCB.sysRunTimeSrvPrarm.resourceId;

#define OSError_ReleaseResource_ResID()   Os_SCB.sysRunTimeSrvPrarm.resourceId;

#define OSError_SetEvent_TaskID()         Os_SCB.sysRunTimeSrvPrarm.taskId;

#define OSError_SetEvent_Mask()           Os_SCB.sysRunTimeSrvPrarm.eventMask;

#define OSError_ClearEvent_Mask()         Os_SCB.sysRunTimeSrvPrarm.eventMask;

#define OSError_GetEvent_TaskID()         Os_SCB.sysRunTimeSrvPrarm.taskId;

#define OSError_GetEvent_Mask()           Os_SCB.sysRunTimeSrvPrarm.eventRef;

#define OSError_WaitEvent_Mask()          Os_SCB.sysRunTimeSrvPrarm.eventMask;

#define OSError_GetAlarmBase_AlarmID()    Os_SCB.sysRunTimeSrvPrarm.alarmId;

#define OSError_GetAlarmBase_Info()       Os_SCB.sysRunTimeSrvPrarm.alarmBaseRef;

#define OSError_GetAlarm_AlarmID()        Os_SCB.sysRunTimeSrvPrarm.alarmId;

#define OSError_GetAlarm_Tick()           Os_SCB.sysRunTimeSrvPrarm.alarmTickRef;

#define OSError_SetRelAlarm_AlarmID()     Os_SCB.sysRunTimeSrvPrarm.alarmId;

#define OSError_SetRelAlarm_tickement()   Os_SCB.sysRunTimeSrvPrarm.alarmTime;

#define OSError_SetRelAlarm_tick()        Os_SCB.sysRunTimeSrvPrarm.alarmCycle;

#define OSError_SetAbsAlarm_AlarmID()     Os_SCB.sysRunTimeSrvPrarm.alarmId;

#define OSError_SetAbsAlarm_start()       Os_SCB.sysRunTimeSrvPrarm.alarmTime;

#define OSError_SetAbsAlarm_tick()        Os_SCB.sysRunTimeSrvPrarm.alarmCycle;

#define OSError_CancelAlarm_AlarmID()     Os_SCB.sysRunTimeSrvPrarm.alarmId;

#define OSError_Save_ActivateTask(param1) Os_SCB.sysRunTimeSrvPrarm.taskId = (param1);

#define OSError_Save_TerminateTask()

#define OSError_Save_ChainTask(param1) Os_SCB.sysRunTimeSrvPrarm.taskId = (param1);

#define OSError_Save_Schedule()

#define OSError_Save_GetTaskID(param1) Os_SCB.sysRunTimeSrvPrarm.taskRef = (param1);

#define OSError_Save_GetTaskState(param1, param2) \
    Os_SCB.sysRunTimeSrvPrarm.taskId = (param1);  \
    Os_SCB.sysRunTimeSrvPrarm.taskState = (param2);

#define OSError_Save_GetResource(param1)     Os_SCB.sysRunTimeSrvPrarm.resourceId = (param1);

#define OSError_Save_ReleaseResource(param1) Os_SCB.sysRunTimeSrvPrarm.resourceId = (param1);

#define OSError_Save_SetEvent(param1, param2)    \
    Os_SCB.sysRunTimeSrvPrarm.taskId = (param1); \
    Os_SCB.sysRunTimeSrvPrarm.eventMask = (param2);

#define OSError_Save_ClearEvent(param1) Os_SCB.sysRunTimeSrvPrarm.eventMask = (param1);

#define OSError_Save_GetEvent(param1, param2)    \
    Os_SCB.sysRunTimeSrvPrarm.taskId = (param1); \
    Os_SCB.sysRunTimeSrvPrarm.eventRef = (param2);

#define OSError_Save_WaitEvent(param1) Os_SCB.sysRunTimeSrvPrarm.eventMask = (param1);

#define OSError_Save_GetAlarm(param1, param2)     \
    Os_SCB.sysRunTimeSrvPrarm.alarmId = (param1); \
    Os_SCB.sysRunTimeSrvPrarm.alarmTickRef = (param2);

#define OSError_Save_GetAlarmBase(param1, param2) \
    Os_SCB.sysRunTimeSrvPrarm.alarmId = (param1); \
    Os_SCB.sysRunTimeSrvPrarm.alarmBaseRef = (param2);

#define OSError_Save_CancelAlarm(param1) Os_SCB.sysRunTimeSrvPrarm.alarmId = (param1);

#define OSError_Save_SetRelAlarm(param1, param2, param3) \
    Os_SCB.sysRunTimeSrvPrarm.alarmId = (param1);        \
    Os_SCB.sysRunTimeSrvPrarm.alarmTime = (param2);      \
    Os_SCB.sysRunTimeSrvPrarm.alarmCycle = (param3);

#define OSError_Save_SetAbsAlarm(param1, param2, param3) \
    Os_SCB.sysRunTimeSrvPrarm.alarmId = (param1);        \
    Os_SCB.sysRunTimeSrvPrarm.alarmTime = (param2);      \
    Os_SCB.sysRunTimeSrvPrarm.alarmCycle = (param3);

#define OSError_Save_IncrementCounter(param1) Os_SCB.sysRunTimeSrvPrarm.counterId = (param1);

#define OSError_Save_GetCounterValue(param1, param2) \
    Os_SCB.sysRunTimeSrvPrarm.counterId = (param1);  \
    Os_SCB.sysRunTimeSrvPrarm.counterValue = (param2);

#define OSError_Save_GetElapsedValue(param1, param2, param3) \
    Os_SCB.sysRunTimeSrvPrarm.counterId = (param1);          \
    Os_SCB.sysRunTimeSrvPrarm.counterValue = (param2);       \
    Os_SCB.sysRunTimeSrvPrarm.counterElapsedValue = (param3);

#define OSError_Save_GetApplicationID()

#define OSError_Save_CheckObjectAccess(param1, param2, param3) \
    Os_SCB.sysRunTimeSrvPrarm.ApplID = (param1);               \
    Os_SCB.sysRunTimeSrvPrarm.ObjectType = (param2);           \
    Os_SCB.sysRunTimeSrvPrarm.ObjectID = (param3);

#define OSError_Save_CheckObjectOwnership(param1, param2) \
    Os_SCB.sysRunTimeSrvPrarm.ObjectType = (param1);      \
    Os_SCB.sysRunTimeSrvPrarm.ObjectID = (param2);

#define OSError_Save_TerminateApplication(param1, param2) \
    Os_SCB.sysRunTimeSrvPrarm.ApplID = (param1);          \
    Os_SCB.sysRunTimeSrvPrarm.RestartOption = (param2);

#define OSError_Save_CheckISRMemoryAccess(param1, param2, param3) \
    Os_SCB.sysRunTimeSrvPrarm.ISRID = (param1);                   \
    Os_SCB.sysRunTimeSrvPrarm.MemStartAddress = (param2);         \
    Os_SCB.sysRunTimeSrvPrarm.MemSize = (param3);

#define OSError_Save_CheckTaskMemoryAccess(param1, param2, param3) \
    Os_SCB.sysRunTimeSrvPrarm.taskId = (param1);                   \
    Os_SCB.sysRunTimeSrvPrarm.MemStartAddress = (param2);          \
    Os_SCB.sysRunTimeSrvPrarm.MemSize = (param3);

#else
#define OSError_ActivateTask_TaskID()
#define OSError_ChainTask_TaskID()
#define OSError_GetTaskID_TaskID()
#define OSError_GetTaskState_TaskID()
#define OSError_GetTaskState_State()
#define OSError_GetResource_ResID()
#define OSError_ReleaseResource_ResID()
#define OSError_SetEvent_TaskID()
#define OSError_SetEvent_Mask()
#define OSError_ClearEvent_Mask()
#define OSError_GetEvent_TaskID()
#define OSError_GetEvent_Mask()
#define OSError_WaitEvent_Mask()
#define OSError_GetAlarmBase_AlarmID()
#define OSError_GetAlarmBase_Info()
#define OSError_GetAlarm_AlarmID()
#define OSError_GetAlarm_Tick()
#define OSError_SetRelAlarm_AlarmID()
#define OSError_SetRelAlarm_tickement()
#define OSError_SetRelAlarm_tick()
#define OSError_SetAbsAlarm_AlarmID()
#define OSError_SetAbsAlarm_start()
#define OSError_SetAbsAlarm_tick()
#define OSError_CancelAlarm_AlarmID()
#define OSError_Save_ActivateTask(param1)
#define OSError_Save_TerminateTask()
#define OSError_Save_ChainTask(param1)
#define OSError_Save_Schedule()
#define OSError_Save_GetTaskID(param1)
#define OSError_Save_GetTaskState(param1, param2)
#define OSError_Save_GetResource(param1)
#define OSError_Save_ReleaseResource(param1)
#define OSError_Save_SetEvent(param1, param2)
#define OSError_Save_ClearEvent(param1)
#define OSError_Save_GetEvent(param1, param2)
#define OSError_Save_WaitEvent(param1)
#define OSError_Save_GetAlarm(param1, param2)
#define OSError_Save_GetAlarmBase(param1, param2)
#define OSError_Save_CancelAlarm(param1)
#define OSError_Save_SetRelAlarm(param1, param2, param3)
#define OSError_Save_SetAbsAlarm(param1, param2, param3)
#define OSError_Save_IncrementCounter(param1)
#define OSError_Save_GetCounterValue(param1, param2)
#define OSError_Save_GetElapsedValue(param1, param2, param3)
#define OSError_Save_GetApplicationID()
#define OSError_Save_CheckObjectAccess(param1, param2, param3)
#define OSError_Save_CheckObjectOwnership(param1, param2)
#define OSError_Save_TerminateApplication(param1, param2)
#define OSError_Save_CheckISRMemoryAccess(param1, param2, param3)
#define OSError_Save_CheckTaskMemoryAccess(param1, param2, param3)
#endif /* TRUE == CFG_USEPARAMETERACCESS */

/*=======[I N T E R N A L   D A T A]========================================*/

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]======*/

#endif /* #ifndef OS_ERR_H */

/*=======[E N D   O F   F I L E]============================================*/
