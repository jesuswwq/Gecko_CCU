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
**  FILENAME    : Os_Core.c                                                   **
**                                                                            **
**  Created on  :                                                             **
**  Author      : zuxiong.ding                                                **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>        <REVISION LOG>
 *  V0.1.0     2016-10-25    zuxiong.ding    Initial version.
 *  V0.2.0     2019-08-21    shun.li & zhiqiang.huang Functional safety initial version.
 *  V1.0.0     2019-11-21    shun.li         Functional safety version.
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

/*=======[M A C R O S]========================================================*/

/*=======[T Y P E   D E F I N I T I O N S]====================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/
/* Multi-core Shared variables */
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
Os_InterCoreType volatile Os_InterCore[OS_AUTOSAR_CORES];
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[I N T E R N A L   D A T A]==========================================*/

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
static FUNC(void, OS_CODE) Os_InterCoreAction(Os_CoreIdType osCoreId);

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <The function starts the core specified by the CoreID. >
 * Service ID           <OSServiceId_StartCore>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-CoreID[in]     <Reference to the core>
 * Param-Status[out]    <Return value of the function>
 * return               <StatusType>
 * PreCondition         <Not support calling the API after calling StartOS.>
 * REQ ID               <DD_1_0578, DD_1_1044, DD_1_0580, DD_1_0581, DD_1_0582, DD_1_1277,
 *                       DD_1_1279, DD_1_1280, DD_1_1281, DD_1_1567, DD_1_0584>
 */
/******************************************************************************/
FUNC(void, OS_CODE) StartCore(CoreIdType CoreID, StatusType* Status) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    CoreIdType logCoreId = Os_GetCoreLogID(CoreID);

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_START_CORE) != TRUE)
    {
        /*nothing to do*/
    }
    else
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        /*null ptr check*/
        if (NULL_PTR == Status)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */
        }
        /* SWS_Os_00606,SWS_Os_00678:StartCore is called after StartOS.*/
        else if (TRUE == Os_CoreCB.coreStateSynPoint2[Os_SCB.sysCore]) /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
        {
            *Status = E_OS_ACCESS;
        }
        /* SWS_Os_00677:The function StartCore shall start one core
         * that shall run under the control of the AUTOSAR OS.*/
        else if (OS_AUTOSAR_CORES <= logCoreId)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            *Status = E_OS_ID;
        }
        /* SWS_Os_00679,SWS_Os_00680:If the parameter CoreIDs refers to a core
         * that was already started by the function StartCore the related core
         * is ignored and E_OS_STATE shall be returned.*/
        else if ((Os_CoreCB.coreStateActive & ((CoreIdType)1U << logCoreId)) > 0u)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */

            *Status = E_OS_STATE;
        }
        else
#endif /*#if (OS_STATUS_EXTENDED == CFG_STATUS)*/
        {
            Os_ArchStartCore(CoreID);

            /* Set Activated core flag bit */
            Os_CoreCB.coreStateActive |= (uint8)(1U << logCoreId);
            Os_CoreCB.coreStatus[logCoreId] = OS_RUN;

            *Status = E_OK;
        }
    }
}

/******************************************************************************/
/*
 * Brief                <The function starts the core specified by the parameter
 *                       CoreID. It is allowed to call this function after
 *                       StartOS().>
 * Service ID           <OSServiceId_StartNonAutosarCore>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-CoreID[in]     <Reference to the core>
 * Param-Status[out]    <Return value of the function>
 * return               <StatusType>
 * PreCondition         <None>
 * REQ ID               <DD_1_0585, DD_1_1545, DD_1_1045, DD_1_0586, DD_1_0587, DD_1_0588,
 *                       DD_1_1275, DD_1_1568, DD_1_0589, DD_1_1613>
 */
/******************************************************************************/
FUNC(void, OS_CODE) StartNonAutosarCore(CoreIdType CoreID, StatusType* Status) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    StatusType OsReturnErr = E_OK;
#if (OS_STATUS_EXTENDED == CFG_STATUS)
    CoreIdType logCoreId;
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */
    OS_SNAC_DEFINE();
    OS_SNAC_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_START_NON_AUTOSAR_CORE) != TRUE)
    {
        /*nothing to do*/
    }
    else
#endif                          /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
        if (NULL_PTR == Status) /*null ptr check*/
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_STATE);
#endif /* TRUE == CFG_ERRORHOOK */
            OsReturnErr = E_NOT_OK;
        }
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        /* SWS_Os_00685:If the parameter CoreID refers to an unknown core the
         * function StartNonAutosarCore has no effect and sets Status to E_OS_ID. */
        else if (CFG_CORE_MAX <= CoreID)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            *Status = E_OS_ID;
            OsReturnErr = E_NOT_OK;
        }
        else
        {
            /* SWS_Os_00683:The function StartNonAutosarCore shall
             * start a core that is not controlled by the AUTOSAR OS. */
            logCoreId = Os_GetCoreLogID(CoreID);
            if (OS_CORE_INVALID != logCoreId)
            {
#if (TRUE == CFG_ERRORHOOK)
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                *Status = E_OS_ID;
                OsReturnErr = E_NOT_OK;
            }
        }

        if ((StatusType)E_OK == OsReturnErr)
        {
            /* SWS_Os_00684:If the parameter CoreID refers to a core
             * that was already started by the function StartNonAutosarCore
             * has no effect and sets "Status" to E_OS_STATE.*/
            if (OS_CORE_MODE_HALT != Os_GetCoreMode(CoreID))
            {
                *Status = E_OS_STATE;
                OsReturnErr = E_NOT_OK;
            }
        }
#endif /*OS_STATUS_EXTENDED == CFG_STATUS*/

        if ((StatusType)E_OK == OsReturnErr)
        {
            Os_ArchStartCore(CoreID);
            *Status = E_OK;
        }
    }
    OS_SNAC_EXIT();
}

/******************************************************************************/
/*
 * Brief                <This API allows the caller to select the idle mode
 *                       action which is performed during idle time of the OS>
 * Service ID           <OSServiceId_ControlIdle>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-CoreID[in]     <selects the core which idle mode is set>
 * param-IdleMode[in]   <the mode which shall be performed during idle time>
 * return               <StatusType, Return result of the function>
 * PreCondition         <None>
 * REQ ID               <DD_1_0626, DD_1_1542, DD_1_0627, DD_1_0628, DD_1_0629,
 *                       DD_1_1569, DD_1_0630, DD_1_1650>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) ControlIdle(CoreIdType CoreID, IdleModeType IdleMode) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    CoreIdType logCoreId = Os_GetCoreLogID(CoreID);
    StatusType rst = E_OK;
    OS_CIL_DEFINE();
    OS_ARCH_DECLARE_CRITICAL();

    OS_CIL_ENTRY();
#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_CONTROL_IDLE) != TRUE)
    {
        rst = E_OS_CALLEVEL;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        rst = E_OS_DISABLEDINT;
    }
    else
    {
        /* nothing to do*/
    }
    if ((StatusType)E_OK == rst)
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        /* SWS_Os_00771:The function ControlIdle shall return E_OS_ID,
         * if the parameter CoreID or IdleMode is invalid. */
        if (OS_AUTOSAR_CORES <= logCoreId)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            rst = E_OS_ID;
        }
        else
#endif /*#if (OS_STATUS_EXTENDED == CFG_STATUS)*/
        {
            Os_GetSpinlock(&Os_SpinlockSync);
            OS_ARCH_ENTRY_CRITICAL();
            /* SWS_Os_00802:the new IdleMode shall become effective
             * the next time that core enters the idle mode. */
            if ((Os_CoreCB.coreStateActive & ((CoreIdType)1U << logCoreId)) > 0u)
            {
                switch (IdleMode)
                {
                case OS_IDLE_NO_HALT:
                    while (FALSE == Os_SetCoreMode(CoreID, OS_CORE_MODE_IDLE))
                    {
                        /* Nothing to do. */
                    }
                    Os_CoreCB.coreStatus[logCoreId] = OS_IDLE_NO_HALT;
                    OS_ARCH_EXIT_CRITICAL();
                    Os_ReleaseSpinlock(&Os_SpinlockSync);
                    break;

                case OS_RUN:
                    while (FALSE == Os_SetCoreMode(CoreID, OS_CORE_MODE_RUN))
                    {
                        /* Nothing to do. */
                    }
                    Os_CoreCB.coreStatus[logCoreId] = OS_RUN;
                    OS_ARCH_EXIT_CRITICAL();
                    Os_ReleaseSpinlock(&Os_SpinlockSync);
                    break;

                default:
                    OS_ARCH_EXIT_CRITICAL();
                    Os_ReleaseSpinlock(&Os_SpinlockSync);
#if (TRUE == CFG_ERRORHOOK)
                    Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                    rst = (StatusType)E_OS_ID;
                    break;
                }
            }
            else
            {
                OS_ARCH_EXIT_CRITICAL();
                Os_ReleaseSpinlock(&Os_SpinlockSync);
#if (TRUE == CFG_ERRORHOOK)
                Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

                rst = (StatusType)E_OS_ID;
            }
        }
    }

    OS_CIL_EXIT();
    /* SWS_Os_00770:The function ControlIdle shall return E_OK,
     * if no error wasdetected and the parameters are valid*/
    return rst;
}

/******************************************************************************/
/*
 * Brief                <The function returns a unique core identifier.>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * return               <CoreIdType, The return value is the unique logical
 *                       CoreID of the core.>
 * PreCondition         <None>
 * REQ ID               <DD_1_0575, DD_1_0576, DD_1_1278, DD_1_1570, DD_1_0577>
 */
/******************************************************************************/
FUNC(CoreIdType, OS_CODE) GetCoreID(void) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    CoreIdType phyCoreId;
    CoreIdType logCoreId;

    phyCoreId = Os_ArchGetCoreID();
    logCoreId = Os_GetCoreLogID(phyCoreId);

    /* SWS_Os_00675:return the unique logical CoreID...*/
    return logCoreId;
}

/******************************************************************************/
/*
 * Brief                <The function returns a unique logical Core ID .>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-phyCoreId[in]  <A valid physical Core ID defined by the AUTOSAR OS.>
 * return               <CoreIdType, The return value is the unique logical
 *                       CoreID map to the input physical core.>
 * PreCondition         <None>
 * CallByAPI            <StartCore>
 * REQ ID               <DD_1_0779, DD_1_0780, DD_1_1543, DD_1_1544>
 */
/******************************************************************************/
FUNC(CoreIdType, OS_CODE) Os_GetCoreLogID(CoreIdType phyCoreId)
{
    CoreIdType logCoreId;

    switch (phyCoreId)
    {
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
    case OS_CORE_ID_0:
        logCoreId = 0u;
        break;
#endif /* CFG_CORE0_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
    case OS_CORE_ID_1:
        logCoreId = 1u;
        break;
#endif /* CFG_CORE1_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
    case OS_CORE_ID_2:
        logCoreId = 2u;
        break;
#endif /* CFG_CORE2_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
    case OS_CORE_ID_3:
        logCoreId = 3u;
        break;
#endif /* CFG_CORE3_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
    case OS_CORE_ID_4:
        logCoreId = 4u;
        break;
#endif /* CFG_CORE4_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
    case OS_CORE_ID_5:
        logCoreId = 5u;
        break;
#endif /* CFG_CORE5_AUTOSAROS_ENABLE */

    default:
        logCoreId = OS_CORE_INVALID;
        break;
    }

    return logCoreId;
}

/******************************************************************************/
/*
 * Brief                <The function returns a unique physical Core ID .>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-logCoreId[in]  <A valid logical Core ID from GetCoreID,Os_GetCoreLogID.>
 * return               <CoreIdType, The return value is the unique physical
 *                       CoreID map to the input logical core.>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0781, DD_1_0782>
 */
/******************************************************************************/
FUNC(CoreIdType, OS_CODE) Os_GetCorePhyID(CoreIdType logCoreId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    CoreIdType phyCoreId;

    switch (logCoreId)
    {
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
    case 0:
        phyCoreId = OS_CORE_ID_0;
        break;
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
    case 1:
        phyCoreId = OS_CORE_ID_1;
        break;
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
    case 2:
        phyCoreId = OS_CORE_ID_2;
        break;
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
    case 3:
        phyCoreId = OS_CORE_ID_3;
        break;
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
    case 4:
        phyCoreId = OS_CORE_ID_4;
        break;
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
    case 5:
        phyCoreId = OS_CORE_ID_5;
        break;
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */

    default:
        phyCoreId = OS_CORE_INVALID;
        break;
    }

    return phyCoreId;
}

/******************************************************************************/
/*
 * Brief                <The function returns the number of cores activated by
 *                          the StartCore function.>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * return               <Number of cores activated by the StartCore function.>
 * PreCondition         <None>
 * REQ ID               <DD_1_0571, DD_1_0572, DD_1_0573, DD_1_0574, DD_1_1651>
 */
/******************************************************************************/
FUNC(uint32, OS_CODE) GetNumberOfActivatedCores(void) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    VAR(uint32, OS_VAR) numOfActivatedCores = 0U;
    Os_CoreIdType loop_core;
    OS_GNOAC_DEFINE();

    OS_GNOAC_ENTRY();
#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

/*service protection*/
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_NUMBER_OF_ACTIVATED_CORES) != TRUE)
    {
        numOfActivatedCores = NULL_PARA;
    }
    else if (FALSE == Os_IgnoreService())
    {
        numOfActivatedCores = NULL_PARA;
    }
    else
#endif /*TRUE == CFG_SERVICE_PROTECTION_ENABLE*/
    {
        for (loop_core = 0u; loop_core < OS_AUTOSAR_CORES; loop_core++)
        {
            if ((Os_CoreCB.coreStateActive & ((Os_CoreIdType)1u << loop_core)) > 0u)
            {
                numOfActivatedCores++;
            }
        }
    }

    OS_GNOAC_EXIT();
    return numOfActivatedCores;
}

/******************************************************************************/
/*
 * Brief                <After this service the OS on all AUTOSAR cores is shut down.>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param-Error[in]      <needs to be a valid error code supported by the AUTOSAR OS.>
 * return               <None>
 * PreCondition         <Allowed at TASK and ISR level and internally by the OS.>
 * REQ ID               <DD_1_0621, DD_1_0622, DD_1_0624, DD_1_1276, DD_1_1207, DD_1_1572,
 *                       DD_1_0625, DD_1_1652>
 */
/******************************************************************************/
FUNC(void, OS_CODE) ShutdownAllCores(StatusType Error) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    Os_TaskType i;
#if (CFG_SPINLOCK_MAX > 0U)
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTCB;
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pICB;
    SpinlockIdType SpinlockId;
    Os_SpinlockType spinLockIdx;
#endif /* CFG_SPINLOCK_MAX > 0U */

    OS_SHUTDOWNOS_ENTRY();

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_SHUTDOWN_ALLCORES) != TRUE)
    {
        /*nothing to do*/
    }
    else if (Os_IgnoreService() != TRUE)
    {
        /*nothing to do*/
    }
    else
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
/* SWS_Os_00716:If ShutdownAllCores is called from
 * non trusted code the call shall be ignored.*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
        if (FALSE == Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted)
        {
            /*nothing to do*/
        }
        else
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
        {
            /* SWS_Os_00762,SWS_Os_00714. */
            switch (Os_SCB.sysCore)
            {
            /* PRQA S 0303,4404++ */ /* MISRA Rule 11.4,10.3 */
            case 0:
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_ShutdownOS;
                Os_InterCore[Os_SCB.sysCore].interParam.ShutdownError = Error;
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(1);
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(2);
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(3);
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(4);
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(5);
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */
                break;

            case 1:
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_ShutdownOS;
                Os_InterCore[Os_SCB.sysCore].interParam.ShutdownError = Error;
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(0);
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(2);
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(3);
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(4);
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(5);
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */
                break;

            case 2:
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_ShutdownOS;
                Os_InterCore[Os_SCB.sysCore].interParam.ShutdownError = Error;
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(1);
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(0);
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(3);
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(4);
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(5);
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */
                break;

            case 3:
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_ShutdownOS;
                Os_InterCore[Os_SCB.sysCore].interParam.ShutdownError = Error;
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(1);
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(2);
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(0);
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(4);
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(5);
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */
                break;

            case 4:
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_ShutdownOS;
                Os_InterCore[Os_SCB.sysCore].interParam.ShutdownError = Error;
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(1);
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(2);
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(3);
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(0);
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(5);
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */
                break;

            case 5:
                Os_InterCore[Os_SCB.sysCore].serviceId = OSServiceId_ShutdownOS;
                Os_InterCore[Os_SCB.sysCore].interParam.ShutdownError = Error;
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(1);
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(2);
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(3);
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(4);
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
                Os_ArchRemoteCall(0);
#endif                                   /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */
                break;
                /* PRQA S 0303,4404-- */ /* MISRA Rule 11.4,10.3 */
            /*add comments to pass QAC.*/
            default:
                while (1)
                {
                    /*nothing to do*/
                }
                break; /* PRQA S 2880 */ /* MISRA Rule 2.1 */
            }

/* SWS_Os_00586: Application specific hook. */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_APPL_SHUTDOWNHOOK)
            Os_ApplShutdownHook(Error);
#endif /* TRUE == CFG_APPL_SHUTDOWNHOOK */
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

            /*Os_SynPoint(3);*/
            Os_CoreCB.coreStateSynPoint3[Os_SCB.sysCore] = TRUE;
            while ((FALSE == Os_CoreCB.coreStateSynPoint3[0])
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
                   || (FALSE == Os_CoreCB.coreStateSynPoint3[1])
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
                   || (FALSE == Os_CoreCB.coreStateSynPoint3[2])
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
                   || (FALSE == Os_CoreCB.coreStateSynPoint3[3])
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
                   || (FALSE == Os_CoreCB.coreStateSynPoint3[4])
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
                   || (FALSE == Os_CoreCB.coreStateSynPoint3[5])
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */
            )
            {
                /* Nothing to do. */
            }
            /* PRQA S 3335++ */ /* MISRA Rule 17.3 */
            OS_DisableInterrupts();
/* PRQA S 3335-- */             /* MISRA Rule 17.3 */

/* SWS_Os_00588: Global ShutdownHook. */
#if (TRUE == CFG_SHUTDOWNHOOK)
            Os_CallShutdownHook(Error);
#endif /* TRUE == CFG_SHUTDOWNHOOK */

/*Os_00620*/
#if (CFG_SPINLOCK_MAX > 0U)
            for (i = 0; i < (Os_CfgTaskMax - 1u); i++)
            {
                pTCB = &Os_TCB[i];
                for (spinLockIdx = pTCB->taskCriticalZoneCount; spinLockIdx > 0u; spinLockIdx--)
                {
                    if (OBJECT_SPINLOCK == pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount - 1u])
                    {
                        SpinlockId = pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount - 1u];
                        (void)ReleaseSpinlock(SpinlockId);
                    }
                }
            }

            for (i = 0; i < Os_CfgIsr2Max; i++)
            {
                pICB = &Os_ICB[i];
                for (spinLockIdx = pICB->isr2CriticalZoneCount; spinLockIdx > 0u; spinLockIdx--)
                {
                    if (OBJECT_SPINLOCK == pICB->isr2CriticalZoneType[pICB->isr2CriticalZoneCount - 1u])
                    {
                        SpinlockId = pICB->isr2CriticalZoneStack[pICB->isr2CriticalZoneCount - 1u];
                        (void)ReleaseSpinlock(SpinlockId);
                    }
                }
            }
#endif /* CFG_SPINLOCK_MAX > 0U */

            /*clear the CoreCB info*/
            Os_GetSpinlock(&Os_SpinlockSync);
            Os_CoreCB.coreStateActive &= (Os_CoreIdType)(~((Os_CoreIdType)1u << Os_SCB.sysCore));
            for (i = 0; i < OS_AUTOSAR_CORES; i++)
            {
                Os_CoreCB.coreStateSynPoint0[i] = FALSE;
                Os_CoreCB.coreStateSynPoint1[i] = FALSE;
                Os_CoreCB.coreStateSynPoint2[i] = FALSE;
                Os_CoreCB.coreStateSynPoint3[i] = FALSE;
            }
            Os_CoreCB.osAppMode[Os_SCB.sysCore] = OS_NULL_APPMODE;
            Os_CoreCB.coreStatus[Os_SCB.sysCore] = OS_CORE_STATUS_INVALID;
            Os_ReleaseSpinlock(&Os_SpinlockSync);

            OS_SHUTDOWNOS_EXIT();

            /* SWS_Os_00715*/
            for (;;)
            {
            }
        }
    }
}

#if (OS_AUTOSAR_CORES > 1)
/********************************************************************/
/*
 * Brief                <The function is used by multicore>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <osCoreId>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0783, DD_1_0784>
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_InterCoreAction(Os_CoreIdType osCoreId)
{
    Os_CoreIdType OsLocalCore = Os_SCB.sysCore;
    if (osCoreId < OS_AUTOSAR_CORES)
    {
        switch (Os_InterCore[osCoreId].serviceId)
        {
#if (CFG_TASK_MAX > 0U)
        case OSServiceId_ActivateTask:
            /*SWS_Os_00596*/
            Os_InterCore[osCoreId].interState = ActivateTask(Os_InterCore[osCoreId].interParam.taskId);
            break;

        case OSServiceId_ChainTask:
            /*SWS_Os_00600*/
            /*the second part of ChainTask is ActivateTask*/
            Os_InterCore[osCoreId].interState = ActivateTask(Os_InterCore[osCoreId].interParam.taskId);
            break;

        case OSServiceId_GetTaskState:
            Os_InterCore[osCoreId].interState =
                GetTaskState(Os_InterCore[osCoreId].interParam.taskId, Os_InterCore[osCoreId].interParam.taskState);
            break;
#endif /*CFG_TASK_MAX > 0U*/

#if (CFG_EXTENDED_TASK_MAX > 0)
        case OSServiceId_SetEvent:
            Os_InterCore[osCoreId].interState =
                SetEvent(Os_InterCore[osCoreId].interParam.taskId, Os_InterCore[osCoreId].interParam.eventMask);
            break;
#endif /*CFG_EXTENDED_TASK_MAX > 0*/

        case OSServiceId_GetCounterValue:
            Os_InterCore[osCoreId].interState = GetCounterValue(
                Os_InterCore[osCoreId].interParam.counterId,
                Os_InterCore[osCoreId].interParam.counterValue);
            break;

        case OSServiceId_GetElapsedValue:
            Os_InterCore[osCoreId].interState = GetElapsedValue(
                Os_InterCore[osCoreId].interParam.counterId,
                Os_InterCore[osCoreId].interParam.counterValue,
                Os_InterCore[osCoreId].interParam.counterElapsedValue);
            break;

#if (CFG_ALARM_MAX > 0)
        case OSServiceId_GetAlarm:
            Os_InterCore[osCoreId].interState =
                GetAlarm(Os_InterCore[osCoreId].interParam.alarmId, Os_InterCore[osCoreId].interParam.alarmTickRef);
            break;

        case OSServiceId_GetAlarmBase:
            Os_InterCore[osCoreId].interState =
                GetAlarmBase(Os_InterCore[osCoreId].interParam.alarmId, Os_InterCore[osCoreId].interParam.alarmBaseRef);
            break;

        case OSServiceId_CancelAlarm:
            Os_InterCore[osCoreId].interState = CancelAlarm(Os_InterCore[osCoreId].interParam.alarmId);
            break;

        case OSServiceId_SetRelAlarm:
            Os_InterCore[osCoreId].interState = SetRelAlarm(
                Os_InterCore[osCoreId].interParam.alarmId,
                Os_InterCore[osCoreId].interParam.alarmTime,
                Os_InterCore[osCoreId].interParam.alarmCycle);
            break;

        case OSServiceId_SetAbsAlarm:
            Os_InterCore[osCoreId].interState = SetAbsAlarm(
                Os_InterCore[osCoreId].interParam.alarmId,
                Os_InterCore[osCoreId].interParam.alarmTime,
                Os_InterCore[osCoreId].interParam.alarmCycle);
            break;
#endif /*CFG_ALARM_MAX > 0*/

#if (CFG_SCHEDTBL_MAX > 0U)
        case OSServiceId_GetScheduleTableStatus:
            Os_InterCore[osCoreId].interState = GetScheduleTableStatus(
                Os_InterCore[osCoreId].interParam.ScheduleTableId,
                Os_InterCore[osCoreId].interParam.ScheduleStatus);
            break;

        case OSServiceId_StartScheduleTableRel:
            Os_InterCore[osCoreId].interState = StartScheduleTableRel(
                Os_InterCore[osCoreId].interParam.ScheduleTableId,
                Os_InterCore[osCoreId].interParam.ScheduleTableOffset);
            break;

        case OSServiceId_StartScheduleTableAbs:
            Os_InterCore[osCoreId].interState = StartScheduleTableAbs(
                Os_InterCore[osCoreId].interParam.ScheduleTableId,
                Os_InterCore[osCoreId].interParam.ScheduleTableStart);
            break;

        case OSServiceId_StopScheduleTable:
            Os_InterCore[osCoreId].interState = StopScheduleTable(Os_InterCore[osCoreId].interParam.ScheduleTableId);
            break;
#endif /* CFG_SCHEDTBL_MAX > 0U */

        case OSServiceId_ShutdownOS:
            OS_ShutdownAllCores(Os_InterCore[osCoreId].interParam.ShutdownError);
            break;

        /*add comments to pass QAC.*/
        default:
            /* Nothing to do. */
            break;
        }

        Os_InterCore[osCoreId].remoteCoreRequest[OsLocalCore] = FALSE;
    }
}

/********************************************************************/
/*
 * Brief                <The function is used by multicore>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <osCoreId>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0783, DD_1_0784>
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_InterCoreOperation(Os_CoreIdType osCoreId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_CoreIdType ix;

    for (ix = (Os_CoreIdType)0; ix < OS_AUTOSAR_CORES; ix++)
    {
        if (TRUE == Os_InterCore[ix].remoteCoreRequest[osCoreId])
        {
            Os_InterCoreAction(ix);
        }
    }
}
#endif /* OS_AUTOSAR_CORES > 1 */
#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/
