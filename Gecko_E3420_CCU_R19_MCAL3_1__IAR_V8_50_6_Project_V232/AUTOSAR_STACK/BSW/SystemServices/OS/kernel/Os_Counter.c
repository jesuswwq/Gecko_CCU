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
**  FILENAME    : Os_Counter.c                                                **
**                                                                            **
**  Created on  :                                                             **
**  Author      : yaoxuan.zhang                                               **
**  Vendor      :                                                             **
**  DESCRIPTION : counter manager                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0       2013-04-15  yaoxuan.zhang       Initial version.
 *  V0.2.0       2013-07-09  huaming             modified the format of
 *                                             Os_CounterCfg,change the
 *                                             included file.
 *  V0.3.0       2013-07-23  yaoxuan.zhang       Modified the code to adapt MISRA
 *                                             C specification.
 *  V0.4.0       2014-11-16  bo.zeng             code refactor.
 *  V0.5.0       2016-12-13  shi.shu             Multi-core Initial version.
 *  V0.6.0       2019-08-21  shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0       2019-11-21  shun.li             Functional safety version.
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
#if (CFG_COUNTER_MAX > 0U)
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) Os_CounterCfg = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(Os_CCBType volatile, AUTOMATIC, OS_VAR) Os_CCB = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static VAR(Os_CounterType, OS_VAR) Os_CfgCounterMax = 0U; /* PRQA S 3218 */ /* MISRA Rule 8.9 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif /* #if (CFG_COUNTER_MAX > 0U) */

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[I N T E R N A L   D A T A]==========================================*/

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#if (CFG_COUNTER_MAX > 0U)
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <Init the counter control block>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0785, DD_1_0786, DD_1_1374>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InitCounter(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_CounterType i;
    P2VAR(Os_CCBType volatile, AUTOMATIC, OS_VAR) pCCB;

    switch (Os_SCB.sysCore)
    {
#if (CFG_COUNTER_MAX_CORE0 > 0U)
    case 0:
        Os_CounterCfg = Os_CounterCfgCore0;
        Os_CCB = Os_CCBCore0;
        Os_CfgCounterMax = CFG_COUNTER_MAX_CORE0;
        break;
#endif /* CFG_COUNTER_MAX_CORE0 > 0U */

#if (CFG_COUNTER_MAX_CORE1 > 0U)
    case 1:
        Os_CounterCfg = Os_CounterCfgCore1;
        Os_CCB = Os_CCBCore1;
        Os_CfgCounterMax = CFG_COUNTER_MAX_CORE1;
        break;
#endif /* CFG_COUNTER_MAX_CORE1 > 0U */

#if (CFG_COUNTER_MAX_CORE2 > 0U)
    case 2:
        Os_CounterCfg = Os_CounterCfgCore2;
        Os_CCB = Os_CCBCore2;
        Os_CfgCounterMax = CFG_COUNTER_MAX_CORE2;
        break;
#endif /* CFG_COUNTER_MAX_CORE2 > 0U */

#if (CFG_COUNTER_MAX_CORE3 > 0U)
    case 3:
        Os_CounterCfg = Os_CounterCfgCore3;
        Os_CCB = Os_CCBCore3;
        Os_CfgCounterMax = CFG_COUNTER_MAX_CORE3;
        break;
#endif /* CFG_COUNTER_MAX_CORE3 > 0U */

#if (CFG_COUNTER_MAX_CORE4 > 0U)
    case 4:
        Os_CounterCfg = Os_CounterCfgCore4;
        Os_CCB = Os_CCBCore4;
        Os_CfgCounterMax = CFG_COUNTER_MAX_CORE4;
        break;
#endif /* CFG_COUNTER_MAX_CORE4 > 0U */

#if (CFG_COUNTER_MAX_CORE5 > 0U)
    case 5:
        Os_CounterCfg = Os_CounterCfgCore5;
        Os_CCB = Os_CCBCore5;
        Os_CfgCounterMax = CFG_COUNTER_MAX_CORE5;
        break;
#endif /* CFG_COUNTER_MAX_CORE5 > 0U */

    /*add comments to pass QAC.*/
    default:
        /* Nothing to do. */
        while (1)
        {
            /*nothing to do*/
        }
        break; /* PRQA S 2880 */ /* MISRA Rule 2.1 */
    }

#if (CFG_COUNTER_MAX > 0)
    for (i = 0U; i < Os_CfgCounterMax; i++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
    {
        pCCB = &Os_CCB[i];
        pCCB->counterCurVal = 0u;
        pCCB->counterLastVal = 0u;
        pCCB->counterAlmQue = OS_ALARM_INVALID;
        pCCB->counterStListHead = NULL_PTR;
    }
#endif /* CFG_COUNTER_MAX > 0 */
}

/******************************************************************************/
/*
 * Brief                <Calculate the absolute ticks that baseTick add the
 *                       offset>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-baseTick[in]   <the begin point>
 * param-offset[in]     <the offset from begin point>
 * param-CounterID[in]  <counter id>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <Os_TickType>
 * PreCondition         <None>
 * CallByAPI            <SetRelAlarm and so on>
 * REQ ID               <DD_1_1007, DD_1_1008, DD_1_1420>
 */
/******************************************************************************/
FUNC(Os_TickType, OS_CODE) Os_CalcAbsTicks(Os_TickType baseTick, Os_TickType offset, Os_CounterType CounterID)
{
    Os_TickType counterTwiceMaxTicks;
    Os_TickType counterAbsTicks;
    counterTwiceMaxTicks = (Os_CounterCfg[CounterID].osCounterMaxAllowedValue * 2u) + 1u;
    if ((baseTick + offset) <= counterTwiceMaxTicks)
    {
        counterAbsTicks = baseTick + offset;
    }
    else
    {
        counterAbsTicks = (baseTick + offset) - (counterTwiceMaxTicks + 1u);
    }

    return counterAbsTicks;
}

/******************************************************************************/
/*
 * Brief                <Get the distance from baseTick to destTick>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-baseTick[in]   <the begin point >
 * param-destTick[in]   <the end point>
 * param-CounterID[in]  <counter id>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <Os_TickType>
 * PreCondition         <None>
 * CallByAPI            <GetAlarm and so on>
 * REQ ID               <DD_1_1009, DD_1_1010, DD_1_1421>
 */
/******************************************************************************/
FUNC(Os_TickType, OS_CODE) Os_GetDistance(Os_TickType baseTick, Os_TickType destTick, Os_CounterType CounterID)
{
    Os_TickType counterTwiceMaxTicks;
    Os_TickType counterDistanceTicks;
    counterTwiceMaxTicks = (Os_CounterCfg[CounterID].osCounterMaxAllowedValue * 2u) + 1u;
    if (baseTick <= destTick)
    {
        counterDistanceTicks = destTick - baseTick;
    }
    else
    {
        counterDistanceTicks = (destTick - baseTick) + (counterTwiceMaxTicks + 1u);
    }

    return counterDistanceTicks;
}

/******************************************************************************/
/*
 * Brief                <Increment Hardware counter>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-CounterID[in]  <reference to counter>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0787, DD_1_0788, DD_1_1359, DD_1_1365, DD_1_1375, DD_1_1414>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) Os_IncrementHardCounter(CounterType CounterID) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    P2VAR(Os_CCBType volatile, AUTOMATIC, OS_VAR) pCcb;
#if (OS_STATUS_EXTENDED == CFG_STATUS)
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) pCounterCfgRef;
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
    StatusType OsReturnErr = E_OK;

    /* SWS_Os_00629:A COUNTER belonging to an OS-Application shall be
     * incremented by the core on which the OS-Application resides. */
    if (Os_SCB.sysCore != Os_GetObjCoreId(CounterID))
    {
        OsReturnErr = E_OS_CORE;
    }
    else
    {
        CounterID = Os_GetObjLocalId(CounterID);

/* OS285 :check CounterID */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        if (CounterID >= Os_CfgCounterMax)
        {
            OsReturnErr = E_OS_ID;
        }
        else
        {
            /* OS285 :check configuration,the counter is a
             * hardware counter,shall return E_OS_ID */
            pCounterCfgRef = &Os_CounterCfg[CounterID];
            if (COUNTER_SOFTWARE == pCounterCfgRef->osCounterType)
            {
                OsReturnErr = E_OS_ID;
            }
        }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        if ((StatusType)E_OK == OsReturnErr)
        {
            /* update the Counter value. */
            pCcb = &Os_CCB[CounterID];
            pCcb->counterLastVal = pCcb->counterCurVal;
            pCcb->counterCurVal = Os_CalcAbsTicks(pCcb->counterCurVal, 1, CounterID);

/* Alarm. */
#if (CFG_ALARM_MAX > 0)
            Os_WorkAlarm(CounterID);
#endif /* CFG_ALARM_MAX > 0 */

/* Schedule table. */
#if (CFG_SCHEDTBL_MAX > 0U)
            Os_WorkSchedTbl(CounterID);
#endif /* CFG_SCHEDTBL_MAX > 0 */
        }
    }

    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <Increment counter>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-CounterID[in]  <reference to counter>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0531, DD_1_0532, DD_1_0533, DD_1_0534, DD_1_0537, DD_1_1036,
 *                       DD_1_1360, DD_1_1361, DD_1_1387, DD_1_1413, DD_1_1466, DD_1_1468,
 *                       DD_1_1469, DD_1_1573, DD_1_1653>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) IncrementCounter(CounterType CounterID) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    P2VAR(Os_CCBType volatile, AUTOMATIC, OS_VAR) pCcb;
#if (OS_STATUS_EXTENDED == CFG_STATUS)
    P2CONST(Os_CounterCfgType, AUTOMATIC, OS_VAR) pCounterCfgRef;
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
    StatusType OsReturnErr = E_OK;

    OS_INCC_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

    /* SWS_Os_00629:A COUNTER belonging to an OS-Application shall be
     * incremented by the core on which the OS-Application resides. */
    if (Os_SCB.sysCore != Os_GetObjCoreId(CounterID))
    {
#if (TRUE == CFG_ERRORHOOK)
        Os_CallErrorHook(E_OS_CORE);
#endif /* TRUE == CFG_ERRORHOOK */

        OsReturnErr = E_OS_CORE;
    }
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    else if (Os_WrongContext(OS_CONTEXT_INCREMENT_COUNTER) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_COUNTER, CounterID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */
    else
    {
#if (OS_AUTOSAR_CORES > 1)
        CounterID = Os_GetObjLocalId(CounterID);
#endif /* OS_AUTOSAR_CORES > 1 */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
        /* SWS_Os_00285:If the input parameter <CounterID> in a call of
         * IncrementCounter() is not valid OR the counter is a hardware
         * counter,IncrementCounter() shall return E_OS_ID.  */
        if (CounterID >= Os_CfgCounterMax)
        {
#if (TRUE == CFG_ERRORHOOK)
            OSError_Save_IncrementCounter(CounterID);
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ID;
        }
        else
        {
            pCounterCfgRef = &Os_CounterCfg[CounterID];
            if (COUNTER_HARDWARE == pCounterCfgRef->osCounterType)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_IncrementCounter(CounterID);
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
        }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        if ((StatusType)E_OK == OsReturnErr)
        {
            pCcb = &Os_CCB[CounterID];
            pCcb->counterLastVal = pCcb->counterCurVal;
            pCcb->counterCurVal = Os_CalcAbsTicks(pCcb->counterCurVal, 1, CounterID);

/* Alarm. */
#if (CFG_ALARM_MAX > 0)
            Os_WorkAlarm(CounterID);
#endif /* CFG_ALARM_MAX > 0 */

/* Schedule table. */
#if (CFG_SCHEDTBL_MAX > 0U)
            Os_WorkSchedTbl(CounterID);
#endif /* CFG_SCHEDTBL_MAX > 0 */
        }
    }

    OS_INCC_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <Get current counter value>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-CounterID[in]  <reference to counter>
 * Param-Value[out]     <current value of the counter>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0538, DD_1_0539, DD_1_0540, DD_1_0543, DD_1_1037, DD_1_1376,
 *                       DD_1_1377, DD_1_1388, DD_1_1461, DD_1_1462, DD_1_1573, DD_1_1654>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE)
GetCounterValue(CounterType CounterID, TickRefType Value) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */
    StatusType OsReturnErr = E_OK;

    OS_ARCH_DECLARE_CRITICAL();
    OS_GCV_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_COUNTER_VALUE) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_AddressWritable((uint8*)Value) != TRUE)
    {
        OsReturnErr = E_OS_ILLEGAL_ADDRESS;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_COUNTER, CounterID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */
    {
/* Cross core use shall be supported. */
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(CounterID);
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
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_GetCounterValue;
                Os_InterCore[Os_SCB.sysCore].interParam.counterId = CounterID;
                Os_InterCore[Os_SCB.sysCore].interParam.counterValue = Value;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do. */
                }

                OsReturnErr = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /* OS_AUTOSAR_CORES > 1 */
        {
#if (OS_AUTOSAR_CORES > 1)
            CounterID = Os_GetObjLocalId(CounterID);
#endif /* OS_AUTOSAR_CORES > 1 */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (CounterID >= Os_CfgCounterMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_GetCounterValue(CounterID, Value);
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            {
                if (NULL_PTR == Value)
                {
#if (TRUE == CFG_ERRORHOOK)
                    Os_CallErrorHook(E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

                    OsReturnErr = E_OS_VALUE;
                }
            }

            if ((StatusType)E_OK == OsReturnErr)
            {
                /* Timer type. */
                OS_ARCH_ENTRY_CRITICAL();
                *Value = Os_CCB[CounterID].counterCurVal % (Os_CounterCfg[CounterID].osCounterMaxAllowedValue + 1u);
                OS_ARCH_EXIT_CRITICAL();
            }
        }
    }

    OS_GCV_EXIT();
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <Get elapsed counter value>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-CounterID[in]      <reference to counter>
 * Param-Value[out]         <current value of the counter>
 * Param-ElapsedValue[out]  <Elapsed value of the counter>
 * Param-Name[in/out]   <None>
 * return               <StatusType>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0544, DD_1_0545, DD_1_0546, DD_1_0551, DD_1_1038, DD_1_1362
 *                       DD_1_1363, DD_1_1378, DD_1_1389, DD_1_1463, DD_1_1464, DD_1_1465
 *                       DD_1_1574, DD_1_1655>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE)
GetElapsedValue /* PRQA S 1532 */ /* MISRA Rule 8.7 */
    (CounterType CounterID, TickRefType Value, TickRefType ElapsedValue)
{
    Os_TickType counterCurval;
    Os_TickType counterMaxAllowedValue;
    StatusType OsReturnErr = E_OK;
#if (OS_AUTOSAR_CORES > 1)
    Os_CoreIdType coreId;
#endif /* OS_AUTOSAR_CORES > 1 */

    OS_ARCH_DECLARE_CRITICAL();
    OS_GECV_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_ELAPSED_COUNTER_VALUE) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_AddressWritable((uint8*)Value) != TRUE)
    {
        OsReturnErr = E_OS_ILLEGAL_ADDRESS;
    }
    else if (Os_AddressWritable((uint8*)ElapsedValue) != TRUE)
    {
        OsReturnErr = E_OS_ILLEGAL_ADDRESS;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsReturnErr = E_OS_DISABLEDINT;
    }
    else if (Os_CheckObjAcs(OBJECT_COUNTER, CounterID) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
#endif /* TRUE == CFG_SERVICE_PROTECTION_ENABLE */
    {
/* Cross core use shall be supported. */
#if (OS_AUTOSAR_CORES > 1)
        coreId = Os_GetObjCoreId(CounterID);
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
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_GetElapsedValue;
                Os_InterCore[Os_SCB.sysCore].interParam.counterId = CounterID;
                Os_InterCore[Os_SCB.sysCore].interParam.counterValue = Value;
                Os_InterCore[Os_SCB.sysCore].interParam.counterElapsedValue = ElapsedValue;
                /* PRQA S 0303++ */ /* MISRA Rule 11.4 */
                Os_ArchRemoteCall(coreId);
                /* PRQA S 0303-- */ /* MISRA Rule 11.4 */
                while ((StatusType)E_NOT_OK == Os_InterCore[Os_SCB.sysCore].interState)
                {
                    /* Nothing to do. */
                }

                OsReturnErr = Os_InterCore[Os_SCB.sysCore].interState;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
        else
#endif /*OS_AUTOSAR_CORES > 1*/
        {
#if (OS_AUTOSAR_CORES > 1)
            CounterID = Os_GetObjLocalId(CounterID);
#endif /* OS_AUTOSAR_CORES > 1 */

#if (OS_STATUS_EXTENDED == CFG_STATUS)
            if (CounterID >= Os_CfgCounterMax)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_GetElapsedValue(CounterID, Value, ElapsedValue);
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_ID;
            }
            else if ((NULL_PTR == Value) || (NULL_PTR == ElapsedValue))
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_CallErrorHook(E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_VALUE;
            }
            else if (*Value > Os_CounterCfg[CounterID].osCounterMaxAllowedValue)
            {
#if (TRUE == CFG_ERRORHOOK)
                OSError_Save_GetElapsedValue(CounterID, Value, ElapsedValue);
                Os_CallErrorHook(E_OS_VALUE);
#endif /* TRUE == CFG_ERRORHOOK */

                OsReturnErr = E_OS_VALUE;
            }
            else
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
            {
                counterMaxAllowedValue = Os_CounterCfg[CounterID].osCounterMaxAllowedValue;

                OS_ARCH_ENTRY_CRITICAL();
                counterCurval = Os_CCB[CounterID].counterCurVal % (counterMaxAllowedValue + 1u);

                *ElapsedValue = ((counterCurval + counterMaxAllowedValue) - (*Value)) % counterMaxAllowedValue;
                *Value = counterCurval;
                OS_ARCH_EXIT_CRITICAL();
            }
        }
    }

    OS_GECV_EXIT();
    return OsReturnErr;
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
#endif /* #if (CFG_COUNTER_MAX > 0U) */

/*=======[E N D   O F   F I L E]==============================================*/
