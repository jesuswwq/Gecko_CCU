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
**  FILENAME    : Os_Alarm.c                                                  **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yaoxuan.zhang                                               **
**  Vendor      :                                                             **
**  DESCRIPTION : alarm manager                                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2013-04-15  yaoxuan.zhang   Initial version.
 *  V0.2.0       2013-07-09  huaming         modified the format of Os_AlarmCfg,
 *                                         change the included file.
 *  V0.3.0       2013-07-23  yaoxuan.zhang   Modified the code to adapt MISRA C.
 *                                         specification.
 *  V0.4.0       2014-11-11  bo.zeng         code refactor.
 *  V0.5.0       2016-12-13  shi.shu         Multi-core Initial version.
 *  V0.6.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li         Functional safety version.
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

/*=======[E X T E R N A L   D A T A]==========================================*/
#if (CFG_ALARM_MAX > 0)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static P2CONST(Os_AlarmCfgType, AUTOMATIC, OS_VAR) Os_AlarmCfg = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static P2VAR(Os_ACBType volatile, AUTOMATIC, OS_VAR) Os_ACB = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(Os_AlarmType, OS_VAR) Os_CfgAlarmMax = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif /* #if (CFG_ALARM_MAX > 0) */
/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[I N T E R N A L   D A T A]==========================================*/

#if (CFG_ALARM_MAX > 0)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
static FUNC(void, OS_CODE) Os_InsertAlarm(Os_AlarmType alarmid, Os_AlarmRefType almque, Os_TickType curTick);
static FUNC(void, OS_CODE) Os_DeleteAlarm(Os_AlarmType alarmid, Os_AlarmRefType almque);
/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
/******************************************************************************/
/*
 * Brief                <Init the alarm control block>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0771, DD_1_0772, DD_1_1352, DD_1_1373>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InitAlarm(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (CFG_ALARM_MAX > 0)
    Os_AlarmType i;
    P2VAR(Os_ACBType volatile, AUTOMATIC, OS_VAR) pACB;
#endif /* CFG_ALARM_MAX > 0 */

#if (CFG_AUTO_ALARM_MAX > 0U)
    P2CONST(Os_AlarmCfgType, AUTOMATIC, OS_VAR) pAlarmCfg = NULL_PTR; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
    Os_CounterType alarmCounter;
    Os_AppModeType alarmAppModeMask;
    Os_AlarmType AlarmQue;
#endif /* CFG_AUTO_ALARM_MAX > 0U */

    switch (Os_SCB.sysCore)
    {
#if (CFG_ALARM_MAX_CORE0 > 0U)
    case 0:
        Os_AlarmCfg = Os_AlarmCfgCore0;
        Os_ACB = Os_ACBCore0;
        Os_CfgAlarmMax = CFG_ALARM_MAX_CORE0;
        break;
#endif /* CFG_ALARM_MAX_CORE0 > 0U */

#if (CFG_ALARM_MAX_CORE1 > 0U)
    case 1:
        Os_AlarmCfg = Os_AlarmCfgCore1;
        Os_ACB = Os_ACBCore1;
        Os_CfgAlarmMax = CFG_ALARM_MAX_CORE1;
        break;
#endif /* CFG_ALARM_MAX_CORE1 > 0U */

#if (CFG_ALARM_MAX_CORE2 > 0U)
    case 2:
        Os_AlarmCfg = Os_AlarmCfgCore2;
        Os_ACB = Os_ACBCore2;
        Os_CfgAlarmMax = CFG_ALARM_MAX_CORE2;
        break;
#endif /* CFG_ALARM_MAX_CORE2 > 0U */

#if (CFG_ALARM_MAX_CORE3 > 0U)
    case 3:
        Os_AlarmCfg = Os_AlarmCfgCore3;
        Os_ACB = Os_ACBCore3;
        Os_CfgAlarmMax = CFG_ALARM_MAX_CORE3;
        break;
#endif /* CFG_ALARM_MAX_CORE3 > 0U */

#if (CFG_ALARM_MAX_CORE4 > 0U)
    case 4:
        Os_AlarmCfg = Os_AlarmCfgCore4;
        Os_ACB = Os_ACBCore4;
        Os_CfgAlarmMax = CFG_ALARM_MAX_CORE4;
        break;
#endif /* CFG_ALARM_MAX_CORE4 > 0U */

#if (CFG_ALARM_MAX_CORE5 > 0U)
    case 5:
        Os_AlarmCfg = Os_AlarmCfgCore5;
        Os_ACB = Os_ACBCore5;
        Os_CfgAlarmMax = CFG_ALARM_MAX_CORE5;
        break;
#endif /* CFG_ALARM_MAX_CORE5 > 0U */

    /*add comments to pass QAC.*/
    default:
        /* Nothing to do */
        break;
    }

    if (Os_AlarmCfg != NULL_PTR)
    {
#if (CFG_ALARM_MAX > 0)
        for (i = 0U; i < Os_CfgAlarmMax; i++)
        {
            pACB = &Os_ACB[i];
            pACB->alarmStart = 0U;
            pACB->alarmCycle = 0U;
            pACB->alarmPre = i;
            pACB->alarmNext = i;

#if (CFG_AUTO_ALARM_MAX > 0U)
            pAlarmCfg = &Os_AlarmCfg[i];
            if (NULL_PTR != pAlarmCfg->osAlarmAutostartRef)
            {
                alarmAppModeMask = pAlarmCfg->osAlarmAutostartRef->osAlarmAppMode;
                if (0U != (alarmAppModeMask & Os_SCB.sysActiveAppMode))
                {
                    alarmCounter = pAlarmCfg->osAlarmCounter;
                    pACB->alarmStart = pAlarmCfg->osAlarmAutostartRef->osAlarmStartTime;
                    pACB->alarmCycle = pAlarmCfg->osAlarmAutostartRef->osAlarmCycleTime;
                    AlarmQue = Os_CCB[alarmCounter].counterAlmQue;
                    Os_InsertAlarm(i, &AlarmQue, Os_CCB[alarmCounter].counterCurVal);
                    Os_CCB[alarmCounter].counterAlmQue = AlarmQue; /*to pass QAC*/
                }
            }
#endif /* CFG_AUTO_ALARM_MAX > 0U */
        }
#endif /* CFG_ALARM_MAX > 0 */
    }

    return; /*this core has no alarm*/
}

/******************************************************************************/
/*
 * Brief                <The system service GetAlarm returns the relative value
 *                       in ticksbefore the alarm <AlarmID> expires>
 * Service ID           <OSServiceId_GetAlarm>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-AlarmID[in]    <reference to alarm>
 * Param-Tick[out]      <Relative value in ticks before the alarm <AlarmID>
 *                       expires>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0693, DD_1_0694, DD_1_1070, DD_1_1351, DD_1_1382,
 *                       DD_1_1473, DD_1_1555, DD_1_1638>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) GetAlarm(AlarmType AlarmID, TickRefType Tick) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    StatusType OsReturnErr = E_OK;
    Os_CounterType osCounterId;
    Os_TickType counterCurval;
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */
    OS_GA_ENTRY();

    OS_ARCH_DECLARE_CRITICAL();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_ALARM) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_AddressWritable((uint8*)Tick) != TRUE)
    {
        OsReturnErr = E_OS_ILLEGAL_ADDRESS;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_ALARM, AlarmID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
/* SWS_Os_00640:GetAlarm shall also work on an
 * ALARM that is bound to another core. */
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(AlarmID);
        if (coreId != Os_SCB.sysCore)
        {
            if (Os_CoreCB.coreStatus[coreId] != OS_RUN)
            {
                OsReturnErr = E_OS_CORE;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_GetAlarm;
                Os_InterCore[Os_SCB.sysCore].interParam.alarmId = AlarmID;
                Os_InterCore[Os_SCB.sysCore].interParam.alarmTickRef = Tick;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do */
                }

                OsReturnErr = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
#if (OS_AUTOSAR_CORES > 1)
            AlarmID = Os_GetObjLocalId(AlarmID);
#endif /*OS_AUTOSAR_CORES > 1*/

#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (AlarmID >= Os_CfgAlarmMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_GetAlarm);
                OSError_Save_GetAlarm(AlarmID, Tick);
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            {
                if (Os_ACB[AlarmID].alarmNext == AlarmID)
                {
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_GetAlarm);
                    OSError_Save_GetAlarm(AlarmID, Tick);
                    Os_CallErrorHook(E_OS_NOFUNC);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_NOFUNC;
                }
                else
                {
                    osCounterId = Os_AlarmCfg[AlarmID].osAlarmCounter;

                    OS_ARCH_ENTRY_CRITICAL();
                    /* Driven by hardware counter or sofrware counter. */
                    counterCurval = Os_CCB[osCounterId].counterCurVal;
                    *Tick = Os_GetDistance(counterCurval, Os_ACB[AlarmID].alarmStart, osCounterId);
                    OS_ARCH_EXIT_CRITICAL();
                }
            }
        }
    }

    OS_GA_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <The system service GetAlarmBase reads the alarm base
 *                       characteristics. The return value <Info> is a structure in which
 *                       the information of data type Os_AlarmBaseType is stored.>
 * Service ID           <OSServiceId_GetAlarmBase>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-AlarmID[in]    <reference to alarm>
 * Param-Info[out]      <Reference to structure with constants of the alarm base>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0691, DD_1_0692, DD_1_1069, DD_1_1350, DD_1_1383,
 *                       DD_1_1474, DD_1_1475, DD_1_1556, DD_1_1639>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_CounterType alarmCounter;
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */
    StatusType OsReturnErr = E_OK;
    OS_GAB_ENTRY();

#if (OS_AUTOSAR_CORES > 1)
    OS_ARCH_DECLARE_CRITICAL();
#endif /* (OS_AUTOSAR_CORES > 1) */

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_ALARM_BASE) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_AddressWritable((uint8*)Info) != TRUE)
    {
        OsReturnErr = E_OS_ILLEGAL_ADDRESS;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_ALARM, AlarmID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
/* SWS_Os_00639:GetAlarmBase shall also work on an
 * ALARM that is bound to another core. */
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(AlarmID);
        if (coreId != Os_SCB.sysCore)
        {
            if (Os_CoreCB.coreStatus[coreId] != OS_RUN)
            {
                OsReturnErr = E_OS_CORE;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_GetAlarmBase;
                Os_InterCore[Os_SCB.sysCore].interParam.alarmId = AlarmID;
                Os_InterCore[Os_SCB.sysCore].interParam.alarmBaseRef = Info;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do */
                }

                OsReturnErr = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
#if (OS_AUTOSAR_CORES > 1)
            AlarmID = Os_GetObjLocalId(AlarmID);
#endif /*OS_AUTOSAR_CORES > 1*/

#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (AlarmID >= Os_CfgAlarmMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_GetAlarmBase);
                OSError_Save_GetAlarmBase(AlarmID, Info);
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            {
                alarmCounter = Os_AlarmCfg[AlarmID].osAlarmCounter;

                Info->maxallowedvalue = Os_CounterCfg[alarmCounter].osCounterMaxAllowedValue;
                Info->mincycle = Os_CounterCfg[alarmCounter].osCounterMinCycle;
                Info->ticksperbase = Os_CounterCfg[alarmCounter].osCounterTicksPerBase;
            }
        }
    }

    OS_GAB_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <The system service cancels the alarm <AlarmID>>
 * Service ID           <OSServiceId_CancelAlarm>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-AlarmID[in]    <reference to alarm>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0699, DD_1_0700, DD_1_1073, DD_1_1349, DD_1_1384,
 *                       DD_1_1470, DD_1_1471, DD_1_1557, DD_1_1640>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) CancelAlarm(AlarmType AlarmID)
{
    StatusType OsReturnErr = E_OK;
    Os_CounterType alarmCounter;
    Os_AlarmType AlarmQue;
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */

    OS_ARCH_DECLARE_CRITICAL();
    OS_CA_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_CANCEL_ALARM) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_ALARM, AlarmID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
/* SWS_Os_00638:CancelAlarm shall also work on an
 * ALARM that is bound to another core. */
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(AlarmID);
        if (coreId != Os_SCB.sysCore)
        {
            if (Os_CoreCB.coreStatus[coreId] != OS_RUN)
            {
                OsReturnErr = E_OS_CORE;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_CancelAlarm;
                Os_InterCore[Os_SCB.sysCore].interParam.alarmId = AlarmID;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do */
                }

                OsReturnErr = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
#if (OS_AUTOSAR_CORES > 1)
            AlarmID = Os_GetObjLocalId(AlarmID);
#endif /*OS_AUTOSAR_CORES > 1*/

#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (AlarmID >= Os_CfgAlarmMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_CancelAlarm);
                OSError_Save_CancelAlarm(AlarmID);
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            {
                OS_ARCH_ENTRY_CRITICAL();
                OS_CA_START_CRITICAL();

                /* Standard Status */
                if (Os_ACB[AlarmID].alarmNext == AlarmID)
                {
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_CancelAlarm);
                    OSError_Save_CancelAlarm(AlarmID);
                    Os_CallErrorHook(E_OS_NOFUNC);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_NOFUNC;
                }
                else
                {
                    alarmCounter = Os_AlarmCfg[AlarmID].osAlarmCounter;
                    AlarmQue = Os_CCB[alarmCounter].counterAlmQue;
                    Os_DeleteAlarm(AlarmID, &AlarmQue);
                    Os_CCB[alarmCounter].counterAlmQue = AlarmQue; /*to pass QAC*/
                }

                OS_ARCH_EXIT_CRITICAL();
                OS_CA_END_CRITICAL();
            }
        }
    }

    OS_CA_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <The system service occupies the alarm <AlarmID> element.
 *                       After <increment> ticks have elapsed, the task assigned
 *                       to the alarm <AlarmID> is activated or the assigned
 *                       event (only for extended tasks) is set or the
 *                       alarm-callback routine is called>
 * Service ID           <OSServiceId_SetRelAlarm>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-AlarmID[in]    <reference to alarm>
 * param-increment[in]  <Relative value in ticks>
 * param-cycle[in]      <Cycle value in case of cyclic alarm. In case of single
 *                       alarms,cycle has to be zero.>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0695, DD_1_0696, DD_1_0009, DD_1_1071, DD_1_1347, DD_1_1385,
 *                       DD_1_1479, DD_1_1480, DD_1_1481, DD_1_1558, DD_1_1641>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE)
SetRelAlarm /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    (AlarmType AlarmID, TickType increment, TickType cycle)
{
    StatusType OsReturnErr = E_OK;
    Os_AlarmType AlarmQue;
    Os_CounterType alarmCounter;
#if (OS_STATUS_EXTENDED == CFG_STATUS)
    Os_TickType counterMinCycle;
    Os_TickType counterMaxAllowedValue;
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */

    OS_ARCH_DECLARE_CRITICAL();
    OS_SRA_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_SET_REL_ALARM) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_ALARM, AlarmID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
    {
        /*nothing to do*/
    }
    if ((StatusType)E_OK == OsReturnErr)
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
/* SWS_Os_00636:SetRelAlarm shall also work on an
 * ALARM that is bound to another core. */
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(AlarmID);
        if (coreId != Os_SCB.sysCore)
        {
            if (Os_CoreCB.coreStatus[coreId] != OS_RUN)
            {
                OsReturnErr = E_OS_CORE;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_SetRelAlarm;
                Os_InterCore[Os_SCB.sysCore].interParam.alarmId = AlarmID;
                Os_InterCore[Os_SCB.sysCore].interParam.alarmTime = increment;
                Os_InterCore[Os_SCB.sysCore].interParam.alarmCycle = cycle;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do */
                }

                OsReturnErr = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
#if (OS_AUTOSAR_CORES > 1)
            AlarmID = Os_GetObjLocalId(AlarmID);
#endif /*OS_AUTOSAR_CORES > 1*/

#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (AlarmID >= Os_CfgAlarmMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_SetRelAlarm);
                OSError_Save_SetRelAlarm(AlarmID, increment, cycle);
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            {
                /*
                 * OSEKOS223: the behaviour of this case is up to the implementation
                 * AutoSarOS, @SWS_Os_00304: If in a call to SetRelAlarm() the
                 * parameter increment is set to zero, the service shall
                 * return E_OS_VALUE in standard and extended status
                 *
                 * we meet SWS_Os_00304 requirement in here.
                 */
                if (0U == increment)
                {
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_SetRelAlarm);
                    OSError_Save_SetRelAlarm(AlarmID, increment, cycle);
                    Os_CallErrorHook(E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_VALUE;
                }
                else
                {
                    alarmCounter = Os_AlarmCfg[AlarmID].osAlarmCounter;

#if (OS_STATUS_EXTENDED == CFG_STATUS)
                    counterMinCycle = Os_CounterCfg[alarmCounter].osCounterMinCycle;
                    counterMaxAllowedValue = Os_CounterCfg[alarmCounter].osCounterMaxAllowedValue;

                    if (increment > counterMaxAllowedValue)
                    {
#if (TRUE == CFG_ERRORHOOK)
                        OSError_Save_ServiceId(OSServiceId_SetRelAlarm);
                        OSError_Save_SetRelAlarm(AlarmID, increment, cycle);
                        Os_CallErrorHook(E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

                        OsReturnErr = E_OS_VALUE;
                    }
                    else if ((cycle != 0U) && ((cycle > counterMaxAllowedValue) || (cycle < counterMinCycle)))
                    {
#if (TRUE == CFG_ERRORHOOK)
                        OSError_Save_ServiceId(OSServiceId_SetRelAlarm);
                        OSError_Save_SetRelAlarm(AlarmID, increment, cycle);
                        Os_CallErrorHook(E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

                        OsReturnErr = E_OS_VALUE;
                    }
                    else
                    {
                        /*nothing to do*/
                    }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
                }

                if ((StatusType)E_OK == OsReturnErr)
                {
                    OS_ARCH_ENTRY_CRITICAL();
                    OS_SRA_START_CRITICAL();

                    if (Os_ACB[AlarmID].alarmNext != AlarmID)
                    {
                        OS_ARCH_EXIT_CRITICAL();
                        OS_SRA_END_CRITICAL();

#if (TRUE == CFG_ERRORHOOK)
                        OSError_Save_ServiceId(OSServiceId_SetRelAlarm);
                        OSError_Save_SetRelAlarm(AlarmID, increment, cycle);
                        Os_CallErrorHook(E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */

                        OsReturnErr = E_OS_STATE;
                    }
                    else
                    {
                        /* Timer type. */
                        Os_ACB[AlarmID].alarmStart =
                            Os_CalcAbsTicks(Os_CCB[alarmCounter].counterCurVal, increment, alarmCounter);

                        Os_ACB[AlarmID].alarmCycle = cycle;

                        AlarmQue = Os_CCB[alarmCounter].counterAlmQue;
                        Os_InsertAlarm(AlarmID, &AlarmQue, Os_CCB[alarmCounter].counterCurVal);
                        Os_CCB[alarmCounter].counterAlmQue = AlarmQue; /*to pass QAC*/

                        OS_ARCH_EXIT_CRITICAL();
                        OS_SRA_END_CRITICAL();
                    }
                }
            }
        }
    }

    OS_SRA_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <The system service occupies the alarm <AlarmID> element.
 *                       When <start> ticks are reached, the task assigned to
 *                       the alarm <AlarmID> is activated or the assigned event
 *                       (only for extendedtasks) is set or the alarm-callback
 *                       routine is called.>
 * Service ID           <OSServiceId_SetAbsAlarm>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-AlarmID[in]    <reference to alarm>
 * param-start[in]      <Absolute value in ticks>
 * param-cycle[in]      <Cycle value in case of cyclic alarm. In case of single
 *                       alarms,cycle has to be zero.>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0697, DD_1_0698, DD_1_1072, DD_1_1348, DD_1_1386,
 *                       DD_1_1476, DD_1_1477, DD_1_1478, DD_1_1559, DD_1_1642>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE)
SetAbsAlarm /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    (AlarmType AlarmID, TickType start, TickType cycle)
{
    StatusType OsReturnErr = E_OK;
    Os_AlarmType AlarmQue;
    Os_TickType osCounterCurVal;
    Os_CounterType alarmCounter;
    Os_TickType counterMaxAllowedValue;
#if (OS_STATUS_EXTENDED == CFG_STATUS)
    Os_TickType counterMinCycle;
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */

    OS_ARCH_DECLARE_CRITICAL();
    OS_SAA_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_SET_ABS_ALARM) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_ALARM, AlarmID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
    {
        /* nothing to do */
    }
    if ((StatusType)E_OK == OsReturnErr)
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
/* SWS_Os_00637:SetAbsAlarm shall also work on an
 * ALARM that is bound to another core. */
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(AlarmID);
        if (coreId != Os_SCB.sysCore)
        {
            if (Os_CoreCB.coreStatus[coreId] != OS_RUN)
            {
                OsReturnErr = E_OS_CORE;
            }
            else
            {
                OS_ARCH_ENTRY_CRITICAL();
                Os_InterCore[Os_SCB.sysCore].interState = E_NOT_OK;
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_SetAbsAlarm;
                Os_InterCore[Os_SCB.sysCore].interParam.alarmId = AlarmID;
                Os_InterCore[Os_SCB.sysCore].interParam.alarmTime = start;
                Os_InterCore[Os_SCB.sysCore].interParam.alarmCycle = cycle;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do */
                }

                OsReturnErr = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
#if (OS_AUTOSAR_CORES > 1)
            AlarmID = Os_GetObjLocalId(AlarmID);
#endif /*OS_AUTOSAR_CORES > 1*/

#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (AlarmID >= Os_CfgAlarmMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_ServiceId(OSServiceId_SetAbsAlarm);
                OSError_Save_SetAbsAlarm(AlarmID, start, cycle);
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            {
                alarmCounter = Os_AlarmCfg[AlarmID].osAlarmCounter;
                counterMaxAllowedValue = Os_CounterCfg[alarmCounter].osCounterMaxAllowedValue;

#if (OS_STATUS_EXTENDED == CFG_STATUS)
                counterMinCycle = Os_CounterCfg[alarmCounter].osCounterMinCycle;

                /*start is unsigned long integer, so not check smaller than 0*/
                if ((0U == start) || (start > counterMaxAllowedValue))
                {
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_SetAbsAlarm);
                    OSError_Save_SetAbsAlarm(AlarmID, start, cycle);
                    Os_CallErrorHook(E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_VALUE;
                }
                else if ((cycle != 0U) && ((cycle > counterMaxAllowedValue) || (cycle < counterMinCycle)))
                {
#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_SetAbsAlarm);
                    OSError_Save_SetAbsAlarm(AlarmID, start, cycle);
                    Os_CallErrorHook(E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_VALUE;
                }
                else
                {
                    /*nothing to do*/
                }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            }

            if ((StatusType)E_OK == OsReturnErr)
            {
                OS_ARCH_ENTRY_CRITICAL();
                OS_SAA_START_CRITICAL();

                if (Os_ACB[AlarmID].alarmNext != AlarmID)
                {
                    OS_ARCH_EXIT_CRITICAL();
                    OS_SAA_END_CRITICAL();

#if (TRUE == CFG_ERRORHOOK)
                    OSError_Save_ServiceId(OSServiceId_SetAbsAlarm);
                    OSError_Save_SetAbsAlarm(AlarmID, start, cycle);
                    Os_CallErrorHook(E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_STATE;
                }
                else
                {
                    osCounterCurVal = Os_CCB[alarmCounter].counterCurVal;

                    if (Os_GetDistance(osCounterCurVal, start, alarmCounter) <= counterMaxAllowedValue)
                    {
                        Os_ACB[AlarmID].alarmStart = start;
                    }
                    else
                    {
                        Os_ACB[AlarmID].alarmStart = start + counterMaxAllowedValue + 1U;
                    }

                    Os_ACB[AlarmID].alarmCycle = cycle;
                    AlarmQue = Os_CCB[alarmCounter].counterAlmQue;
                    Os_InsertAlarm(AlarmID, &AlarmQue, Os_CCB[alarmCounter].counterCurVal);
                    Os_CCB[alarmCounter].counterAlmQue = AlarmQue; /*to pass QAC*/

                    OS_ARCH_EXIT_CRITICAL();
                    OS_SAA_END_CRITICAL();
                }
            }
        }
    }

    OS_SAA_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <Os_WorkAlarm>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-CounterID[in]  <reference to counter>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0773, DD_1_0774, DD_1_1364>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_WorkAlarm(Os_CounterType CounterID) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_TickType counterCurval;
    Os_TickType counterMaxAllowedValue;
    boolean done = FALSE;
    Os_AlarmType AlarmQue;
    Os_AlarmType alarmCurVal;
    Os_AlarmType alarmNextVal;

    OS_ARCH_DECLARE_CRITICAL();

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    Os_ApplicationType bakappID;
    bakappID = Os_SCB.sysRunningAppID;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

    counterMaxAllowedValue = Os_CounterCfg[CounterID].osCounterMaxAllowedValue;

    OS_ARCH_ENTRY_CRITICAL();
    counterCurval = Os_CCB[CounterID].counterCurVal;
    alarmNextVal = Os_CCB[CounterID].counterAlmQue;

    while (FALSE == done)
    {
        if (OS_ALARM_INVALID == alarmNextVal)
        {
            done = TRUE;
        }
        else if (Os_GetDistance(Os_ACB[alarmNextVal].alarmStart, counterCurval, CounterID) <= counterMaxAllowedValue)
        {
            alarmCurVal = alarmNextVal;
            alarmNextVal = Os_ACB[alarmNextVal].alarmNext;
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
            Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_ALARM][alarmCurVal].hostApp;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
            Os_CCB[CounterID].counterAlmQue = alarmNextVal;

            if (OS_ALARM_INVALID != alarmNextVal)
            {
                Os_ACB[alarmNextVal].alarmPre = OS_ALARM_INVALID;
            }

            Os_ACB[alarmCurVal].alarmPre = alarmCurVal;
            Os_ACB[alarmCurVal].alarmNext = alarmCurVal;

            if (NULL_PTR != Os_AlarmCfg[alarmCurVal].osAlarmCallback)
            {
                OS_ARCH_EXIT_CRITICAL();
                Os_AlarmCfg[alarmCurVal].osAlarmCallback();
                OS_ARCH_ENTRY_CRITICAL();
            }

            if (Os_ACB[alarmCurVal].alarmCycle > 0U)
            {
                Os_ACB[alarmCurVal].alarmStart =
                    Os_CalcAbsTicks(Os_ACB[alarmCurVal].alarmStart, Os_ACB[alarmCurVal].alarmCycle, CounterID);
                AlarmQue = Os_CCB[CounterID].counterAlmQue;
                Os_InsertAlarm(alarmCurVal, &AlarmQue, Os_CCB[CounterID].counterLastVal);
                Os_CCB[CounterID].counterAlmQue = AlarmQue; /*to pass QAC*/
            }
        }
        else
        {
            done = TRUE;
        }
    }
    OS_ARCH_EXIT_CRITICAL();

#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    Os_SCB.sysRunningAppID = bakappID;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
}

/******************************************************************************/
/*
 * Brief                <Insert an alarm in alarm queue>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-alarmid[in]    <reference to alarm>
 * param-curTick[in]    <current tick value>
 * Param-Name[out]      <None>
 * Param-almque[in/out] <reference to alarm queue>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_1011, DD_1_1012>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_InsertAlarm(Os_AlarmType alarmid, Os_AlarmRefType almque, Os_TickType curTick)
{
    Os_TickType alarmTick;
    Os_AlarmType pre, next;
    boolean done = FALSE;

    if (alarmid < Os_CfgAlarmMax)
    {
        alarmTick = Os_ACB[alarmid].alarmStart;

        pre = OS_ALARM_INVALID;
        next = *almque;

        if (curTick < alarmTick)
        {
            while (done != TRUE)
            {
                if (OS_ALARM_INVALID == next)
                {
                    done = TRUE;
                }
                else if ((Os_ACB[next].alarmStart >= curTick) && (Os_ACB[next].alarmStart <= alarmTick))
                {
                    pre = next;
                    next = Os_ACB[next].alarmNext;
                }
                else
                {
                    done = TRUE;
                }
            }
        }
        else
        {
            while (done != TRUE)
            {
                if (OS_ALARM_INVALID == next)
                {
                    done = TRUE;
                }
                else if ((Os_ACB[next].alarmStart >= curTick) || (Os_ACB[next].alarmStart <= alarmTick))
                {
                    pre = next;
                    next = Os_ACB[next].alarmNext;
                }
                else
                {
                    done = TRUE;
                }
            }
        }

        Os_ACB[alarmid].alarmPre = pre;
        Os_ACB[alarmid].alarmNext = next;

        if (pre != OS_ALARM_INVALID)
        {
            Os_ACB[pre].alarmNext = alarmid;
        }
        else
        {
            *almque = alarmid;
        }

        if (next != OS_ALARM_INVALID)
        {
            Os_ACB[next].alarmPre = alarmid;
        }
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <Delete an alarm in alarm queue>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-alarmid[in]    <reference to alarm>
 * Param-Name[out]      <None>
 * Param-almque[in/out] <reference to alarm queue>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0775, DD_1_0776>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_DeleteAlarm(Os_AlarmType alarmid, Os_AlarmRefType almque)
{
    Os_AlarmType pre, next;

    if (alarmid >= Os_CfgAlarmMax)
    {
        /*nothing to do*/
    }
    else
    {
        pre = Os_ACB[alarmid].alarmPre;
        next = Os_ACB[alarmid].alarmNext;

        if (pre != OS_ALARM_INVALID)
        {
            Os_ACB[pre].alarmNext = next;
        }
        else
        {
            *almque = next;
        }

        if (next != OS_ALARM_INVALID)
        {
            Os_ACB[next].alarmPre = pre;
        }

        Os_ACB[alarmid].alarmPre = alarmid;
        Os_ACB[alarmid].alarmNext = alarmid;
    }

    return;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

#endif /* #if (CFG_ALARM_MAX > 0) */

/*=======[E N D   O F   F I L E]==============================================*/
