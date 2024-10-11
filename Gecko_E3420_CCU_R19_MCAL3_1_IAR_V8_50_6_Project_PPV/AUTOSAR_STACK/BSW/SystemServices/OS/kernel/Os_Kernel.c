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
**  FILENAME    : Os_Kernel.c                                                 **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Huaming                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION : code about priority processing and ready queue              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/**
 *  <VERSION>  <DATE>    <AUTHOR>       <REVISION LOG>
 *  V0.1.0     2013-05-02  huaming        Initial version:design the core
 *                                      algorithm about priority and ready queue.
 *  V0.2.0     2013-06-14  yaoxuan.zhang  redefine the data type and macro base
 *                                      the code rule of I-SOFT and the review
 *                                      about OS kernel architecture.
 *  V0.3.0     2013-06-19  huaming        modified the format of data type and
 *                                      macro definition,and added the
 *                                      information about MISRAC rule.
 *  V0.4.0     2013-07-01  huaming        modified the core algorithm about
 *                                      priority and ready queue in function
 *                                      of Os_GetHighPrio().
 *  V0.5.0     2013-07-02  yaoxuan.zhang  Modified Call_ErrorHook function .
 *  V0.6.0     2013-07-11  huaming        add the information about API .
 *  V0.7.0     2013-07-22  yaoxuan.zhang  Modified Call_ErrorHook function.
 *  V0.8.0     2013-07-23  yaoxuan.zhang  Modified the code to adapt MISRA C
 *                                      specification.
 *  V0.9.0     2013-07-30  huaming        Modified the code in Os_GetHighPrio.
 *  V1.0.0     2013-08-02  huaming        Modified the code about internal
 *                                      resource such as Os_ReadyQueueInsert
 *                                      and Os_ReadyQueueRemove.
 *  V1.1.0     2014-11-16  bo.zeng        code refactor.
 *  V1.2.0     2016-12-13  shi.shu        Multi-core Initial version.
 *  V1.3.0     2019-08-21  shun.li & zhiqiang.huang  Functional safety initial version.
 *  V2.0.0     2019-11-21  shun.li        Functional safety version.
 *  V2.1.0     2020-05-12  shun.li        Add IOC function.
 */
/*============================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

/*=======[V E R S I O N  C H E C K]===========================================*/
/* DD_1_0162, DD_1_0163, DD_1_0164, DD_1_0165, DD_1_0166, DD_1_0167 */
#if (4U != OS_CFG_H_AR_MAJOR_VERSION)
#error "Os_Kernel.c:Mismatch with OS_CFG_H_AR_MAJOR_VERSION"
#endif /* #if (4U != OS_CFG_H_AR_MAJOR_VERSION) */
#if (2U != OS_CFG_H_AR_MINOR_VERSION)
#error "Os_Kernel.c:Mismatch with OS_CFG_H_AR_MINOR_VERSION"
#endif /* #if (2U != OS_CFG_H_AR_MINOR_VERSION) */
#if (2U != OS_CFG_H_AR_PATCH_VERSION)
#error "Os_Kernel.c:Mismatch with OS_CFG_H_AR_PATCH_VERSION"
#endif /* #if (2U != OS_CFG_H_AR_PATCH_VERSION) */
#if (1U != OS_CFG_H_SW_MAJOR_VERSION)
#error "Os_Kernel.c:Mismatch with OS_CFG_H_SW_MAJOR_VERSION"
#endif /* #if (1U != OS_CFG_H_SW_MAJOR_VERSION) */
#if (0U != OS_CFG_H_SW_MINOR_VERSION)
#error "Os_Kernel.c:Mismatch with OS_CFG_H_SW_MINOR_VERSION"
#endif /* #if (0U != OS_CFG_H_SW_MINOR_VERSION) */
#if (0U != OS_CFG_H_SW_PATCH_VERSION)
#error "Os_Kernel.c:Mismatch with OS_CFG_H_SW_PATCH_VERSION"
#endif /* #if (0U != OS_CFG_H_SW_PATCH_VERSION) */
/*=======[M A C R O S]========================================================*/
#define NUM_PRIORITYBITS_PERWORD 16u /* DD_1_0177, Priority calculation parameters. */

/*=======[T Y P E   D E F I N I T I O N S]====================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/
/* Used to compile abstractions.
This requirement covers all macro similar to "OS_START_SEC_[Section]" in the OS module */
/* DD_1_0312 */
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static VAR(uint16, OS_VAR) Os_ReadyMapSize = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint16, OS_VAR) Os_CfgPriorityMax = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
/* PRQA S 3432,1504++ */ /* MISRA Rule 20.7,8.7 */
P2VAR(Os_PriorityType, AUTOMATIC, OS_VAR) Os_ReadyMap = NULL_PTR;
/* PRQA S 3432,1504-- */ /* MISRA Rule 20.7,8.7 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2VAR(Os_TaskType, AUTOMATIC, OS_VAR) Os_ReadyTable = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#else
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
P2VAR(Os_ReadyQueueType, AUTOMATIC, OS_VAR) Os_ReadyQueueMark = NULL_PTR;
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(uint32, AUTOMATIC, OS_VAR) Os_ActivateQueueSize = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(Os_TaskRefType, AUTOMATIC, OS_VAR) Os_ReadyQueue = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#endif /* #if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))*/
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
/* PRQA S 1504++ */ /* MISRA Rule 8.7 */
P2CONST(Os_PriorityType, AUTOMATIC, OS_VAR) Os_PrioGroup = NULL_PTR;
/* PRQA S 1504-- */ /* MISRA Rule 8.7 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
/* PRQA S 1504++ */ /* MISRA Rule 8.7 */
P2CONST(Os_PriorityType, AUTOMATIC, OS_VAR) Os_PrioMask = NULL_PTR;
/* PRQA S 1504-- */ /* MISRA Rule 8.7 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
static VAR(uint8, OS_VAR) Os_CfgPriorityGroup = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
P2CONST(Os_StackType, AUTOMATIC, OS_VAR) Os_SystemStack = NULL_PTR;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint8 volatile, OS_VAR) Os_SuspendAllCount = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(uint8 volatile, OS_VAR) Os_SuspendOsCount = 0U;
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"
#define OS_START_SEC_VAR_CLONE
#include "Os_MemMap.h"
VAR(Os_IPLType, OS_VAR) Os_SaveOsIntNested = 0U;
/* Used to compile abstractions.
This requirement covers all macro similar to "OS_STOP_SEC_[Section]" in the OS module */
/* DD_1_0313 */
#define OS_STOP_SEC_VAR_CLONE
#include "Os_MemMap.h"

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
#define OS_START_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"
VAR(Os_SpinlockType, OS_VAR) Os_SpinlockSync;
#define OS_STOP_SEC_VAR_NOINIT_GLOBAL
#include "Os_MemMap.h"

/*=======[I N T E R N A L   D A T A]==========================================*/
/* PRQA S 1514++ */ /* MISRA Rule 8.9 */
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_NO_INIT_CORE0_16
#include "Os_MemMap.h"
VAR(Os_PriorityType, OS_VAR) Os_ReadyMap_Core0[READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE0))];
#define OS_STOP_SEC_VAR_NO_INIT_CORE0_16
#include "Os_MemMap.h"
#endif /*TRUE == CFG_CORE0_AUTOSAROS_ENABLE*/

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_NO_INIT_CORE1_16
#include "Os_MemMap.h"
VAR(Os_PriorityType, OS_VAR) Os_ReadyMap_Core1[READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE1))];
#define OS_STOP_SEC_VAR_NO_INIT_CORE1_16
#include "Os_MemMap.h"
#endif /*TRUE == CFG_CORE1_AUTOSAROS_ENABLE*/

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_NO_INIT_CORE2_16
#include "Os_MemMap.h"
VAR(Os_PriorityType, OS_VAR) Os_ReadyMap_Core2[READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE2))];
#define OS_STOP_SEC_VAR_NO_INIT_CORE2_16
#include "Os_MemMap.h"
#endif /*TRUE == CFG_CORE2_AUTOSAROS_ENABLE*/

#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_NO_INIT_CORE3_16
#include "Os_MemMap.h"
VAR(Os_PriorityType, OS_VAR) Os_ReadyMap_Core3[READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE3))];
#define OS_STOP_SEC_VAR_NO_INIT_CORE3_16
#include "Os_MemMap.h"
#endif /*TRUE == CFG_CORE3_AUTOSAROS_ENABLE*/

#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_NO_INIT_CORE4_16
#include "Os_MemMap.h"
VAR(Os_PriorityType, OS_VAR) Os_ReadyMap_Core4[READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE4))];
#define OS_STOP_SEC_VAR_NO_INIT_CORE4_16
#include "Os_MemMap.h"
#endif /*TRUE == CFG_CORE4_AUTOSAROS_ENABLE*/

#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
#define OS_START_SEC_VAR_NO_INIT_CORE5_16
#include "Os_MemMap.h"
VAR(Os_PriorityType, OS_VAR) Os_ReadyMap_Core5[READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE5))];
#define OS_STOP_SEC_VAR_NO_INIT_CORE5_16
#include "Os_MemMap.h"
#endif              /*TRUE == CFG_CORE5_AUTOSAROS_ENABLE*/
/* PRQA S 1514-- */ /* MISRA Rule 8.9 */

/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/
static FUNC(void, OS_CODE) Os_InitSystem(void);
#if (TRUE == CFG_STACK_CHECK)
static FUNC(void, OS_CODE) Os_InitSystemStack(void);
#endif /* TRUE == CFG_STACK_CHECK */
static FUNC(void, OS_CODE) Os_InitReadyTable(void);
static FUNC(Os_PriorityType, OS_CODE) Os_GetHighPrioBit(Os_PriorityType HighPriReadyTaskInQueue);
static FUNC(void, OS_CODE) Os_MultiCoreInitKernel(void);
static FUNC(Os_AppModeType, OS_CODE) Os_CheckAppMode(Os_AppModeType mode);
static FUNC(void, OS_CODE) Os_DeInitCoreInfo(void);
static FUNC(void, OS_CODE) Os_SynPoint(uint8 point);

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/******************************************************************************/
/*
 * Brief                <The user can call this  system service to start the
 *                     operating system in a specific mode.>
 * ServiceId           <0x16>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * Param-Name[in]      <Mode: application mode>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * Return              <None>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0703, DD_1_1529, DD_1_1193, DD_1_1201, DD_1_1203, DD_1_1204,
 *                       DD_1_1209, DD_1_1227, DD_1_1580, DD_1_1661, DD_1_0704>
 */
/******************************************************************************/
FUNC(void, OS_CODE) StartOS(AppModeType Mode) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    OS_STARTOS_ENTRY();
    StatusType OsReturnErr = E_OK;

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

    /* Get the unique logical CoreID.The operation must
     * be in the front, Will be used in the process of
     * the system is running. */
    Os_SCB.sysCore = Os_GetCoreLogID(Os_ArchGetCoreID());

    /* The Core is Non AUTOSAR Core. */
    if (OS_CORE_INVALID == Os_SCB.sysCore)
    {
        OS_STARTOS_EXIT();
        OsReturnErr = E_NOT_OK;
    }
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    else if (Os_SCB.sysOsLevel != OS_LEVEL_MAIN)
    {
        if (Os_WrongContext(OS_CONTEXT_START_OS) != TRUE)
        {
            OS_STARTOS_EXIT();
            OsReturnErr = E_NOT_OK;
        }
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OS_STARTOS_EXIT();
        OsReturnErr = E_NOT_OK;
    }
    else
    {
        /*nothing to do*/
    }
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/

    if ((StatusType)E_OK == OsReturnErr)
    {
        /* 1. must disable all interrupts during start os */
        /* PRQA S 3335++ */ /* MISRA Rule 17.3 */
        OS_DisableInterrupts();
        /* PRQA S 3335-- */ /* MISRA Rule 17.3 */

        /*
         * 2. note: this action must before switch sp,
         * because the parameter Mode will be change
         */
        Os_SCB.sysActiveAppMode = Os_CheckAppMode(Mode);

        Os_MultiCoreInitProcessor();

        Os_MultiCoreInitKernel();

/* 3. init system stack and switch to system stack */
#if (TRUE == CFG_STACK_CHECK)
        Os_InitSystemStack();
#endif /* #if (TRUE == CFG_STACK_CHECK) */

        /* 4. pre switch system stack */
        /* PRQA S 3200,0303,3335++ */ /* MISRA Rule 17.7,11.4,17.3 */
        Os_PreSwitch2System();
        /* PRQA S 3200,0303,3335-- */ /* MISRA Rule 17.7,11.4,17.3 */

        /* 5.switch to system stack */
        /* PRQA S 1840,0306,3200++ */ /* MISRA Rule 10.4,11.4,17.7 */
        Os_Switch2System();
        /* PRQA S 1840,0306,3200-- */ /* MISRA Rule 10.4,11.4,17.7 */

        /* 6. Init os. */
        Os_InitSystem();

        /* 7. Init OS CPU arch. */
        Os_InitCPU();

/* 8. Init IOC. */
#if (CFG_IOC_MAX > 0U) /* PRQA S 3332 */ /* MISRA Rule 20.9 */
        Os_InitIoc();
#endif                                   /* CFG_IOC_MAX > 0U */

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
        Os_InitMemProt();
        /* PRQA S 3200,2981++ */ /* MISRA Rule 17.7,2.2 */
        Os_ArchMemProtEnable();
/* PRQA S 3200,2981-- */         /* MISRA Rule 17.7,2.2 */
#endif                           /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */

        /* SWS_Os_00580:synchronize before the global StartupHook. */
        //Os_SynPoint(1);
/* 8. Startup hook. */
#if (TRUE == CFG_STARTUPHOOK)
        Os_CallStartupHook();
#endif /* #if (TRUE == CFG_STARTUPHOOK) */

/* 9. Application specific hook. */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_APPL_STARTUPHOOK)
        Os_ApplStartupHook();
#endif /* TRUE == CFG_APPL_STARTUPHOOK */
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

        /* SWS_Os_00579:synchronize after the global StartupHook. */
        //Os_SynPoint(2);

        /* 10. Task Schedule. */
        OS_STARTOS_EXIT();
        OS_START_DISPATCH();
        Os_StartScheduler();
    }
}

/******************************************************************************/
/*
 * Brief                <terminate the os,the system will enter the background program>
 * Service ID           <OSServiceId_ShutdownOS>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ErrorHook>
 * REQ ID               <DD_1_0705, DD_1_1194, DD_1_1196, DD_1_1198, DD_1_1208, DD_1_1215,
 *                       DD_1_1228, DD_1_1581, DD_1_1662, DD_1_0706>
 */
/******************************************************************************/
FUNC(void, OS_CODE) ShutdownOS(StatusType Error) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (CFG_SPINLOCK_MAX > 0U)
    Os_TaskType i;
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
    if (Os_WrongContext(OS_CONTEXT_SHUTDOWN_OS) != TRUE)
    {
        OS_SHUTDOWNOS_EXIT();
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OS_SHUTDOWNOS_EXIT();
    }
    /*OS054*/
    else if (FALSE == Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted)
    {
        OS_SHUTDOWNOS_EXIT();
    }
    else
#endif /*TRUE == CFG_SERVICE_PROTECTION_ENABLE*/
    {
/* SWS_Os_00586: Application specific hook. */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_APPL_SHUTDOWNHOOK)
        Os_ApplShutdownHook(Error);
#endif /* TRUE == CFG_APPL_SHUTDOWNHOOK */
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

        OS_DisableInterrupts();
/* SWS_Os_00588: Global ShutdownHook. */
#if (TRUE == CFG_SHUTDOWNHOOK)
        Os_CallShutdownHook(Error);
#endif /* #if (TRUE == CFG_SHUTDOWNHOOK) */
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
        Os_DeInitCoreInfo();

        OS_SHUTDOWNOS_EXIT();

        /* SWS_Os_00715*/
        for (;;)
        {
            /* Nothing to do. */
        }
    }

    (void)Error;
}

/******************************************************************************/
/*
 * Brief                <OS_ShutdownAllCores is not provide user >
 * Service ID           <OSServiceId_ShutdownAllCores>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ErrorHook>
 * REQ ID               <DD_1_1074, DD_1_1197, DD_1_1199, DD_1_1206, DD_1_1216, DD_1_1075>
 */
/******************************************************************************/
FUNC(void, OS_CODE) OS_ShutdownAllCores(StatusType Error) /* PRQA S 1532,3206 */ /* MISRA Rule 8.7,2.7 */
{
#if (CFG_SPINLOCK_MAX > 0U)
    Os_TaskType i;
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTCB;
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pICB;

    SpinlockIdType SpinlockId;
    Os_SpinlockType spinLockIdx;
#endif                     /* CFG_SPINLOCK_MAX > 0U */
    OS_SHUTDOWNOS_ENTRY(); /* OS_SHUTDOWNAC_ENTRY(); */

#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

/* SWS_Os_00586: Application specific hook. */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
#if (TRUE == CFG_APPL_SHUTDOWNHOOK)
    Os_ApplShutdownHook(Error);
#endif /* TRUE == CFG_APPL_SHUTDOWNHOOK */
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

    Os_SynPoint(3);

    OS_DisableInterrupts();
/* SWS_Os_00588: Global ShutdownHook. */
#if (TRUE == CFG_SHUTDOWNHOOK)
    Os_CallShutdownHook(Error);
#endif /* #if (TRUE == CFG_SHUTDOWNHOOK) */

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
    Os_DeInitCoreInfo();

    OS_SHUTDOWNOS_EXIT(); /* OS_SHUTDOWNAC_EXIT(); */

    /* SWS_Os_00715*/
    for (;;)
    {
        /* Nothing to do. */
    }
}

/******************************************************************************/
/*
 * Brief                <get the active application mode of os>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <the active application mode>
 * PreCondition         <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0701, DD_1_1582, DD_1_1663, DD_1_0702>
 */
/******************************************************************************/
FUNC(AppModeType, OS_CODE) GetActiveApplicationMode(void) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    AppModeType OsAppMode;
    OS_GAAPM_DEFINE();

    OS_GAAPM_ENTRY();
#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_ACTIV_APPLICATION_MODE) != TRUE)
    {
        OsAppMode = OS_NULL_APPMODE;
    }
    else if (Os_IgnoreService() != TRUE)
    {
        OsAppMode = OS_NULL_APPMODE;
    }
    else
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)*/
    {
        OsAppMode = Os_SCB.sysActiveAppMode;
    }

    OS_GAAPM_EXIT();
    return OsAppMode;
}

/******************************************************************************/
/*
 * Brief                <init the os module>
 * Service ID:          <None>
 * Sync/Async:          <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0931, DD_1_1202>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_InitSystem(void)
{

    /*01.Init Os_SCB */
    Os_SCB.sysDispatchLocker = 0U;
    Os_SCB.sysOsLevel = OS_LEVEL_TASK;
    Os_SCB.sysHighPrio = OS_PRIORITY_INVALID;
    Os_SCB.sysHighTaskID = OS_TASK_INVALID;
    Os_SCB.sysRunningTaskID = OS_TASK_INVALID;
    Os_SCB.sysRunningTCB = NULL_PTR;

#if (CFG_ISR2_MAX > 0)
    Os_SCB.sysInIsrCat2 = FALSE;
    Os_SCB.sysRunningIsrCat2Id = OS_ISR_INVALID;
#endif /* CFG_ISR2_MAX > 0U */

#if (CFG_OSAPPLICATION_MAX > 0)
    Os_SCB.sysRunningAppObj = OBJECT_MAX;
    Os_SCB.sysRunningAppID = OS_APPLICATION_INVALID;
#endif /* CFG_OSAPPLICATION_MAX > 0U */

    /*02.Init Os_CoreCB, OS_CORE_ID_MASTER is auto start, don't by means of
     * StartCore.*/
    if (OS_CORE_ID_MASTER == Os_GetCorePhyID(Os_SCB.sysCore))
    {
        Os_CoreCB.coreStateActive |= (uint8)(1u << OS_CORE_ID_MASTER);
        Os_CoreCB.coreStatus[OS_CORE_ID_MASTER] = OS_RUN;
        Os_CoreCB.currentSpinlockOccupyLevel = OS_SPINLOCK_INVALID;
    }

    /* 03.Init ready table */
    Os_InitReadyTable();

/* 04.Init TCB */
#if (CFG_TASK_MAX > 0U)
    Os_InitTask();
#endif /* (CFG_TASK_MAX > 0U) */

/* 05.Init ICB */
#if (CFG_ISR2_MAX > 0)
    Os_InitInterrupt();
#endif /* CFG_ISR2_MAX > 0U */

/* 06.Init Counter */
#if (CFG_COUNTER_MAX > 0U)
    Os_InitCounter();
#endif /* (CFG_COUNTER_MAX > 0U) */

/* 07.Init Alarm */
#if (CFG_ALARM_MAX > 0U)
    Os_InitAlarm();
#endif /* #if (CFG_ALARM_MAX > 0U) */

/* 08.Init Event */
#if (CFG_EXTENDED_TASK_MAX > 0)
    Os_InitEvent();
#endif /* CFG_EXTENDED_TASK_MAX > 0 */

/* 09.Init Resource */
#if (CFG_RESOURCE_MAX > 0)
    Os_InitResource();
#endif /* CFG_STD_RESOURCE_MAX > 0 */

/* 10.Init schedule table. */
#if (CFG_SCHEDTBL_MAX > 0)
    Os_InitScheduleTable();
#endif /* CFG_SCHEDTBL_MAX > 0 */

/* 11.Init protection. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    Os_InitTmProt();
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

/* 12.Init spinlock*/
#if (CFG_SPINLOCK_MAX > 0U)
    Os_InitSpinlock();
#endif /* CFG_SPINLOCK_MAX > 0 */

/* 13.Init application. */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    Os_InitApplication();
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

/* Init TrustedFunction. */
#if (CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0U) /* PRQA S 3332 */ /* MISRA Rule 20.9 */
    Os_InitTrustedFunction();
#endif                                                      /* CFG_TRUSTED_SYSTEM_SERVICE_MAX > 0 */

    return;
}

/******************************************************************************/
/*
 * Brief                <get the highest priority>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <the highest priority>
 * PreCondition         <None>
 * CallByAPI            <TerminateTask and so on>
 * REQ ID               <DD_1_0823, DD_1_1225, DD_1_0824>
 */
/******************************************************************************/
FUNC(Os_PriorityType, OS_CODE) Os_GetHighPrio(void)
{
    Os_PriorityType highPrio;

    if (Os_CfgPriorityGroup > 1u)
    {
        Os_PriorityType const* ptr;
        Os_PriorityType priorityTemp;

        ptr = &Os_ReadyMap[Os_CfgPriorityGroup - 1u];
        priorityTemp = *ptr;
        highPrio = (((Os_PriorityType)Os_CfgPriorityGroup - 1u) << 4u);

        /*
         * MISRA-C:2004 Rule 17.4
         * Msg(4:0489) The integer value 1 is being added or subtracted from
         * a pointer.
         */
        while (0u == priorityTemp)
        {
            ptr--;

            if (ptr < &Os_ReadyMap[0])
            {
                while (1)
                {
                    /* Nothing to do. */
                }
            }

            priorityTemp = *ptr;
            /*here have a potential bug in the first version,here must be
             * decrease but not increase*/
            highPrio -= NUM_PRIORITYBITS_PERWORD;
        }

        highPrio += Os_GetHighPrioBit(priorityTemp);
    }
    else
    {
        if (NULL_PTR == Os_ReadyMap)
        {
            while (1)
            {
                /* Nothing to do. */
            }
        }

        highPrio = Os_GetHighPrioBit(Os_ReadyMap[0]);
    }

    return highPrio;
}

/******************************************************************************/
/*
 * Brief                <insert a priority to ready queue>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <object:the ID of task or resource, level: the call level,
 *                                                          prio:inserted priority>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <TerminateTask and so on>
 * REQ ID               <DD_1_0825, DD_1_1218, DD_1_0826>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ReadyQueueInsert(Os_TaskType object, Os_CallLevelType level, Os_PriorityType prio)
{
    switch (level)
    {
#if (CFG_STD_RESOURCE_MAX > 0U)
    case OS_LEVEL_STANDARD_RESOURCE:
/*  make the prio related with the calling task*/
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyTable[prio] = Os_SCB.sysRunningTaskID;
#else

        if (Os_ReadyQueueMark[prio].queueHead == 0u)
        {
            Os_ReadyQueueMark[prio].queueHead = Os_ActivateQueueSize[prio] - 1u;
        }
        else
        {
            Os_ReadyQueueMark[prio].queueHead--;
        }

        Os_ReadyQueue[prio][Os_ReadyQueueMark[prio].queueHead] = Os_SCB.sysRunningTaskID;
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */

        Os_ReadyMap[Os_PrioGroup[prio]] |= Os_PrioMask[prio];
        break;
#endif /* #if (CFG_STD_RESOURCE_MAX > 0U) */

    case OS_LEVEL_TASK:
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyTable[prio] = object;
#else

        Os_ReadyQueue[prio][Os_ReadyQueueMark[prio].queueTail] = object;
        Os_ReadyQueueMark[prio].queueTail++;

        if (Os_ReadyQueueMark[prio].queueTail == Os_ActivateQueueSize[prio])
        {
            Os_ReadyQueueMark[prio].queueTail = 0u;
        }
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */

        Os_ReadyMap[Os_PrioGroup[prio]] |= Os_PrioMask[prio];
        break;

#if (CFG_INTERNAL_RESOURCE_MAX > 0)
    case OS_LEVEL_INTERNAL_RESOURCE:
/*  make the prio related with the calling task*/
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyTable[prio] = object;
#else

        if (Os_ReadyQueueMark[prio].queueHead == 0u)
        {
            Os_ReadyQueueMark[prio].queueHead = Os_ActivateQueueSize[prio] - 1u;
        }
        else
        {
            Os_ReadyQueueMark[prio].queueHead--;
        }

        Os_ReadyQueue[prio][Os_ReadyQueueMark[prio].queueHead] = object;
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */

        Os_ReadyMap[Os_PrioGroup[prio]] |= Os_PrioMask[prio];
        break;
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0 */

    /*add comments to pass QAC.*/
    default:
        /* Nothing to do. */
        break;
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <remove a priority from ready queue>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <object:the ID of task or resource, level: the call level,
 *                                                          prio:removed priority>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <TerminateTask and so on>
 * REQ ID               <DD_1_0827, DD_1_1219, DD_1_0828>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ReadyQueueRemove(Os_CallLevelType level, Os_PriorityType prio)
{
    switch (level)
    {
#if (CFG_STD_RESOURCE_MAX > 0U)
    case OS_LEVEL_STANDARD_RESOURCE:
/*make the prio related with the calling task */
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyMap[Os_PrioGroup[prio]] &= ~Os_PrioMask[prio];
        Os_ReadyTable[prio] = OS_TASK_INVALID;
#else

        Os_ReadyQueue[prio][Os_ReadyQueueMark[prio].queueHead] = OS_TASK_INVALID;
        Os_ReadyQueueMark[prio].queueHead++;

        if (Os_ReadyQueueMark[prio].queueHead == Os_ActivateQueueSize[prio])
        {
            Os_ReadyQueueMark[prio].queueHead = 0u;
        }

        if (Os_ReadyQueueMark[prio].queueHead == Os_ReadyQueueMark[prio].queueTail)
        {
            Os_ReadyMap[Os_PrioGroup[prio]] &= ~Os_PrioMask[prio];
        }
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */
        break;
#endif /* #if (CFG_STD_RESOURCE_MAX > 0U) */

    case OS_LEVEL_TASK:
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyTable[prio] = OS_TASK_INVALID;
        Os_ReadyMap[Os_PrioGroup[prio]] &= ~Os_PrioMask[prio];
#else

        Os_ReadyQueue[prio][Os_ReadyQueueMark[prio].queueHead] = OS_TASK_INVALID;
        Os_ReadyQueueMark[prio].queueHead++;

        if (Os_ReadyQueueMark[prio].queueHead == Os_ActivateQueueSize[prio])
        {
            Os_ReadyQueueMark[prio].queueHead = 0u;
        }

        if (Os_ReadyQueueMark[prio].queueHead == Os_ReadyQueueMark[prio].queueTail)
        {
            Os_ReadyMap[Os_PrioGroup[prio]] &= ~Os_PrioMask[prio];
        }
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */

        break;

#if (CFG_INTERNAL_RESOURCE_MAX > 0U)
    case OS_LEVEL_INTERNAL_RESOURCE:

#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyMap[Os_PrioGroup[prio]] &= ~Os_PrioMask[prio];
        Os_ReadyTable[prio] = OS_TASK_INVALID;
#else

        Os_ReadyQueue[prio][Os_ReadyQueueMark[prio].queueHead] = OS_TASK_INVALID;
        Os_ReadyQueueMark[prio].queueHead++;

        if (Os_ReadyQueueMark[prio].queueHead == Os_ActivateQueueSize[prio])
        {
            Os_ReadyQueueMark[prio].queueHead = 0u;
        }

        if (Os_ReadyQueueMark[prio].queueHead == Os_ReadyQueueMark[prio].queueTail)
        {
            Os_ReadyMap[Os_PrioGroup[prio]] &= ~Os_PrioMask[prio];
        }
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */

        break;
#endif /* #if (CFG_INTERNAL_RESOURCE_MAX > 0U) */

    /*add comments to pass QAC.*/
    default:
        /* Nothing to do. */
        break;
    }

    return;
}

/******************************************************************************/
/*
 * Brief                <get the first task of a ready queue that the value of
 *                      priority is equal to prio>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <prio:the priority value of the ready queue >
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <the first task of a ready queue >
 * PreCondition         <None>
 * CallByAPI            <TerminateTask and so on>
 * REQ ID               <DD_1_0829, DD_1_1220, DD_1_0830>
 */
/******************************************************************************/
FUNC(Os_TaskType, OS_CODE) Os_ReadyQueueGetFirst(Os_PriorityType prio)
{
    Os_TaskType Os_FirstTask;
    if (prio >= Os_CfgPriorityMax)
    {
        Os_FirstTask = OS_TASK_INVALID;
    }
    else
    {
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_FirstTask = Os_ReadyTable[prio];
#else

        Os_FirstTask = Os_ReadyQueue[prio][Os_ReadyQueueMark[prio].queueHead];
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */
    }

    return Os_FirstTask;
}

/******************************************************************************/
/*
 * Brief                <pre entry highest priority task>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <ISR>
 * REQ ID               <DD_1_0831, DD_1_1195, DD_1_1200, DD_1_1230, DD_1_1231,
 *                       DD_1_1160, DD_1_1172, DD_1_1167, DD_1_1164, DD_1_1166,
 *                       DD_1_0832>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_SwitchTask(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_TaskStateType tempState;
    Os_SCB.sysPrevTaskID = Os_SCB.sysRunningTaskID;
#if (TRUE == CFG_STACK_CHECK)
    Os_StackPtrType StackPtr;
#endif

    if (NULL_PTR != Os_SCB.sysRunningTCB)
    {
/* check running task stack overflow. */
#if (TRUE == CFG_STACK_CHECK)
        StackPtr = Os_SCB.sysRunningTCB->taskStackBottom;
        /* PRQA S 0488++ */          /* MISRA Rule 18.4 */
        IF_STACK_CHECK_SWITCH_TASK() /* STACK CHECK */
        /* PRQA S 0488-- */          /* MISRA Rule 18.4 */
        {
#if (TRUE == CFG_ERRORHOOK)
            (void)Os_CallErrorHook(E_OS_STACKFAULT);
#endif
#if (TRUE == CFG_PROTECTIONHOOK && ((OS_SC2 == CFG_SC) || (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC)))
            (void)Os_CallProtectionHook(E_OS_STACKFAULT, OS_TMPROT_HOOK_TASK);
#else
            ShutdownOS(E_OS_STACKFAULT);
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
        }
#endif /* #if (TRUE == CFG_STACK_CHECK) */

        if (TASK_STATE_RUNNING == Os_SCB.sysRunningTCB->taskState)
        {
            Os_SCB.sysRunningTCB->taskState = TASK_STATE_READY;

#if (TRUE == CFG_POSTTASKHOOK)
            Os_CallPostTaskHook();
#endif /* TRUE == CFG_POSTTASKHOOK */
        }
    }

    Os_SCB.sysRunningTaskID = Os_SCB.sysHighTaskID;
    /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
    Os_SCB.sysRunningTCB = &Os_TCB[Os_SCB.sysRunningTaskID];
/* PRQA S 0404-- */     /* MISRA Rule 1.3,13.2 */
/*Writing the running ApplID and Object */
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    Os_SCB.sysRunningAppID = Os_ObjectAppCfg[OBJECT_TASK][Os_SCB.sysRunningTaskID].hostApp;
    Os_SCB.sysRunningAppObj = OBJECT_TASK;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */

#if (OS_PREEMPTIVE_MIXED == CFG_SCHED_POLICY)
    if (OS_PREEMPTIVE_NON == Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskSchedule)
    {
        Os_SCB.sysDispatchLocker = 1U;
    }
#endif /* OS_PREEMPTIVE_MIXED == CFG_SCHED_POLICY */

#if (CFG_INTERNAL_RESOURCE_MAX > 0)
    Os_GetInternalResource();
#endif /* CFG_INTERNAL_RESOURCE_MAX > 0 */

    tempState = Os_SCB.sysRunningTCB->taskState;

    Os_SCB.sysRunningTCB->taskState = TASK_STATE_RUNNING;

#if (TRUE == CFG_PRETASKHOOK)
    Os_CallPreTaskHook();
#endif /* TRUE == CFG_PRETASKHOOK */

/* Timing protection: start task exe time. */
#if (TRUE == CFG_TIMING_PROTECTION_ENABLE)
    Os_TmProtTaskStart(Os_SCB.sysRunningTaskID, TP_TASK_EXE);
#endif /* TRUE == CFG_TIMING_PROTECTION_ENABLE */

    if (TASK_STATE_START == tempState)
    {
        Os_SCB.sysRunningTCB->taskTop =
            Os_TaskStack[Os_GetObjLocalId(Os_TaskCfg[Os_SCB.sysRunningTaskID].osTaskStackId)].stackTop;

#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
        if (Os_AppSysCfg != Os_SCB.sysRunningAppID)
        {
            /* Memory protection: Set memory map according to new running task. */
            /*new task,default set register 03*/
            Os_ArchSetMemProtSet(0x01U);
            /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
            Os_ArchSetTaskMemMap(
                Os_GetObjLocalId(Os_SCB.sysRunningTaskID),
                Os_SCB.sysRunningAppID,
                (uint32)Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted);
            /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
        }
        else
        {
            /*SYS_APP, as OS kernel, have all access rights*/
            Os_ArchInitKnMemMap();
        }
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
        Os_ArchFirstEnterTask();
    }
    else
    {
#if (TRUE == CFG_MEMORY_PROTECTION_ENABLE)
        if (Os_AppSysCfg != Os_SCB.sysRunningAppID)
        {
            /* Memory protection: Set memory map according to new running task. */
            Os_ArchSetMemProtSet(0x01U);
            /* PRQA S 0404++ */ /* MISRA Rule 1.3,13.2 */
            Os_ArchSetTaskMemMap(
                Os_GetObjLocalId(Os_SCB.sysRunningTaskID),
                Os_SCB.sysRunningAppID,
                (uint32)Os_AppCfg[Os_SCB.sysRunningAppID].OsTrusted);
            /* PRQA S 0404-- */ /* MISRA Rule 1.3,13.2 */
        }
        else
        {
            /*SYS_APP, as OS kernel, have all access rights*/
            Os_ArchSetMemProtSet(0x00U);
        }
#endif /* TRUE == CFG_MEMORY_PROTECTION_ENABLE */
    }
}

/******************************************************************************/
/*
 * Brief                <get the highest priority bit>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <HighPriReadyTaskInQueue: a mixed value of a priority queue>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <the highest bit value of the priority queue >
 * PreCondition         <None>
 * CallByAPI            <Os_GetHighPrio>
 * REQ ID               <DD_1_0932>
 */
/******************************************************************************/
static FUNC(Os_PriorityType, OS_CODE) Os_GetHighPrioBit(Os_PriorityType HighPriReadyTaskInQueue)
{
    /* Index into table is bit pattern to resolve highest priority. */
    /* DD_1_0149 */
    static CONST(uint8, OS_CONST) Os_MapTable[16] = {0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3};
    Os_PriorityType highPrio = 0u;

/*means that the value of Priority is proportional to Priority */
#if (NUM_PRIORITYBITS_PERWORD >= 32)
    if ((HighPriReadyTaskInQueue & 0xFFFF0000U) != 0u)
    {
        highPrio += 16u;

        HighPriReadyTaskInQueue >>= 16u;
    }
#endif /* NUM_PRIORITYBITS_PERWORD >= 32 */

#if (NUM_PRIORITYBITS_PERWORD >= 16)
    if ((HighPriReadyTaskInQueue & 0xFF00U) != 0u)
    {
        highPrio += 8u;

        HighPriReadyTaskInQueue >>= 8u;
    }
#endif /* NUM_PRIORITYBITS_PERWORD >= 16 */

    if ((HighPriReadyTaskInQueue & 0xF0U) != 0u)
    {
        highPrio += 4u;

        HighPriReadyTaskInQueue >>= 4u;
    }

    return (uint16)(highPrio + Os_MapTable[HighPriReadyTaskInQueue]);
}

/******************************************************************************/
/*
 * Brief                <init the system stack with the value of 0xcc>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0933>
 */
/******************************************************************************/
#if (TRUE == CFG_STACK_CHECK)
static FUNC(void, OS_CODE) Os_InitSystemStack(void)
{
    Os_FillStack(*Os_SystemStack);
}
#endif /* TRUE == CFG_STACK_CHECK */

/******************************************************************************/
/*
 * Brief                <fill the stack of task or system with the value of 0xCC>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <stack:the stack of task or system>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0833, DD_1_0834>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_FillStack(Os_StackType stack)
{
    Os_StackPtrType ptr;
#if (CHECK_STACK_USAGE > 0u)
    /*
     * MISRA-C:2004 Rule 17.4
     * Msg(4:0489) The integer value 1 is being added or subtracted from a pointer.
     */
    for (ptr = (Os_StackDataType*)stack.stackBottom; ptr < (Os_StackDataType*)stack.stackTop; ptr++)
    {
        *ptr = OS_STACK_FILL_PATTERN;
    }
#else
    ptr = (Os_StackDataType*)stack.stackBottom;
    OS_FILL_SAFET_STACK(); /* fill stack to ensure safety*/
#endif
}

/******************************************************************************/
/*
 * Brief                <init the ready queue or ready table>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <None>
 * PreCondition         <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0934>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_InitReadyTable(void)
{
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
    uint16 i;
#else
    uint16 i;
    uint32 j;
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */

    for (i = 0U; i < Os_ReadyMapSize; i++)
    {
        Os_ReadyMap[i] = 0U;
    }

    for (i = 0U; i < Os_CfgPriorityMax; i++)
    {
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyTable[i] = OS_TASK_INVALID;
#else

        Os_ReadyQueueMark[i].queueHead = 0U;
        Os_ReadyQueueMark[i].queueTail = 0U;

        for (j = 0U; j < Os_ActivateQueueSize[i]; j++)
        {
            Os_ReadyQueue[i][j] = OS_TASK_INVALID;
        }
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */
    }
}

/********************************************************************/
/*
 * Brief                <Clear priority ready map>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <OsPrio>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * REQ ID               <DD_1_0835>
 *
 */
/********************************************************************/
FUNC(void, OS_CODE) Os_ClearPrioReadyMap(Os_PriorityType OsPrio) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_ReadyMap[Os_PrioGroup[OsPrio]] &= ~Os_PrioMask[OsPrio];

    return;
}

/******************************************************************************/
/*
 * Brief                <Os_TaskErrBack>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <the priority value>
 * PreCondition         <None>
 * CallByAPI            <GetResource and so on >
 * REQ ID               <DD_1_0836, DD_1_0837>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_TaskErrBack(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    Os_TaskEndNoTerminate();
#endif /*#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)  */
    while (1)
    {
        /* Nothing to do. */
    }
}

/******************************************************************************/
/*
 * Brief                <idle task>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <the priority value>
 * PreCondition         <None>
 * CallByAPI            <GetResource and so on >
 * REQ ID               <DD_1_0838, DD_1_1217, DD_1_0839>
 */
/******************************************************************************/
#if (CFG_TASK_MAX_CORE0 > 0U)
FUNC(void, OS_CODE) Os_TaskEntry_IdleCore0(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    while (1)
    {
        IdleHook_Core0();
    }
}
#endif /* CFG_TASK_MAX_CORE0 > 0U */

/******************************************************************************/
/*
 * Brief                <idle task>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <the priority value>
 * PreCondition         <None>
 * CallByAPI            <GetResource and so on >
 * REQ ID               <DD_1_0838, DD_1_1217, DD_1_0839>
 */
/******************************************************************************/
#if (CFG_TASK_MAX_CORE1 > 0U)
FUNC(void, OS_CODE) Os_TaskEntry_IdleCore1(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    while (1)
    {
        IdleHook_Core1();
    }
}
#endif /* CFG_TASK_MAX_CORE1 > 0U */

/******************************************************************************/
/*
 * Brief                <idle task>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <the priority value>
 * PreCondition         <None>
 * CallByAPI            <GetResource and so on >
 * REQ ID               <DD_1_0838, DD_1_1217, DD_1_0839>
 */
/******************************************************************************/
#if (CFG_TASK_MAX_CORE2 > 0U)
FUNC(void, OS_CODE) Os_TaskEntry_IdleCore2(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    while (1)
    {
        IdleHook_Core2();
    }
}
#endif /* CFG_TASK_MAX_CORE2 > 0U */

/******************************************************************************/
/*
 * Brief                <idle task>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <the priority value>
 * PreCondition         <None>
 * CallByAPI            <GetResource and so on >
 * REQ ID               <DD_1_0838, DD_1_1217, DD_1_0839>
 */
/******************************************************************************/
#if (CFG_TASK_MAX_CORE3 > 0U)
FUNC(void, OS_CODE) Os_TaskEntry_IdleCore3(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    while (1)
    {
        IdleHook_Core3();
    }
}
#endif /* CFG_TASK_MAX_CORE3 > 0U */

/******************************************************************************/
/*
 * Brief                <idle task>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <the priority value>
 * PreCondition         <None>
 * CallByAPI            <GetResource and so on >
 * REQ ID               <DD_1_0838, DD_1_1217, DD_1_0839>
 */
/******************************************************************************/
#if (CFG_TASK_MAX_CORE4 > 0U)
FUNC(void, OS_CODE) Os_TaskEntry_IdleCore4(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    while (1)
    {
        IdleHook_Core4();
    }
}
#endif /* CFG_TASK_MAX_CORE4 > 0U */

/******************************************************************************/
/*
 * Brief                <idle task>
 * Service ID   :       <None>
 * Sync/Async   :       <Synchronous>
 * Reentrancy           <Non Reentrant>
 * @param[in]           <None>
 * @param[out]          <None>
 * @param[in/out]       <None>
 * @return              <the priority value>
 * PreCondition         <None>
 * CallByAPI            <GetResource and so on >
 * REQ ID               <DD_1_0838, DD_1_1217, DD_1_0839>
 */
/******************************************************************************/
#if (CFG_TASK_MAX_CORE5 > 0U)
FUNC(void, OS_CODE) Os_TaskEntry_IdleCore5(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    while (1)
    {
        IdleHook_Core5();
    }
}
#endif /* CFG_TASK_MAX_CORE5 > 0U */

/*===========================Multi Core API===================================*/
/******************************************************************************/
/*
 * Brief                <The function init os kernel variable in MultiCore.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0840, DD_1_0841, DD_1_0153, DD_1_0154>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_MultiCoreInitKernel(void)
{
    switch (Os_SCB.sysCore)
    {
#if (TRUE == CFG_CORE0_AUTOSAROS_ENABLE)
    case 0:
        Os_SCB.sysIsrNestQueue = Os_SysIsrNestQueueCore0;
        /*add () to pass QAC*/
        Os_ReadyMapSize = READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE0));
        Os_CfgPriorityMax = CFG_PRIORITY_MAX_CORE0;
        Os_ReadyMap = Os_ReadyMap_Core0;
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyTable = Os_ReadyTable_CORE0;
#else
        Os_ReadyQueueMark = Os_ReadyQueueMark_Core0;
        Os_ActivateQueueSize = Os_ActivateQueueSize_Core0;
        Os_ReadyQueue = Os_ReadyQueue_Core0;
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */
        Os_PrioGroup = Os_PrioGroupCore0;
        Os_PrioMask = Os_PrioMaskCore0;
        Os_CfgPriorityGroup = CFG_PRIORITY_GROUP_CORE0;
        Os_SystemStack = &Os_SystemStackCore0;
        break;
#endif /* TRUE == CFG_CORE0_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
    case 1:
        Os_SCB.sysIsrNestQueue = Os_SysIsrNestQueueCore1;
        /*add () to pass QAC*/
        Os_ReadyMapSize = READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE1));
        Os_CfgPriorityMax = CFG_PRIORITY_MAX_CORE1;
        Os_ReadyMap = Os_ReadyMap_Core1;
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyTable = Os_ReadyTable_CORE1;
#else
        Os_ReadyQueueMark = Os_ReadyQueueMark_Core1;
        Os_ActivateQueueSize = Os_ActivateQueueSize_Core1;
        Os_ReadyQueue = Os_ReadyQueue_Core1;
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */
        Os_PrioGroup = Os_PrioGroupCore1;
        Os_PrioMask = Os_PrioMaskCore1;
        Os_CfgPriorityGroup = CFG_PRIORITY_GROUP_CORE1;
        Os_SystemStack = &Os_SystemStackCore1;
        break;
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
    case 2:
        Os_SCB.sysIsrNestQueue = Os_SysIsrNestQueueCore2;
        /*add () to pass QAC*/
        Os_ReadyMapSize = READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE2));
        Os_CfgPriorityMax = CFG_PRIORITY_MAX_CORE2;
        Os_ReadyMap = Os_ReadyMap_Core2;
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyTable = Os_ReadyTable_CORE2;
#else
        Os_ReadyQueueMark = Os_ReadyQueueMark_Core2;
        Os_ActivateQueueSize = Os_ActivateQueueSize_Core2;
        Os_ReadyQueue = Os_ReadyQueue_Core2;
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */
        Os_PrioGroup = Os_PrioGroupCore2;
        Os_PrioMask = Os_PrioMaskCore2;
        Os_CfgPriorityGroup = CFG_PRIORITY_GROUP_CORE2;
        Os_SystemStack = &Os_SystemStackCore2;
        break;
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
    case 3:
        Os_SCB.sysIsrNestQueue = Os_SysIsrNestQueueCore3;
        /*add () to pass QAC*/
        Os_ReadyMapSize = READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE3));
        Os_CfgPriorityMax = CFG_PRIORITY_MAX_CORE3;
        Os_ReadyMap = Os_ReadyMap_Core3;
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyTable = Os_ReadyTable_CORE3;
#else
        Os_ReadyQueueMark = Os_ReadyQueueMark_Core3;
        Os_ActivateQueueSize = Os_ActivateQueueSize_Core3;
        Os_ReadyQueue = Os_ReadyQueue_Core3;
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */
        Os_PrioGroup = Os_PrioGroupCore3;
        Os_PrioMask = Os_PrioMaskCore3;
        Os_CfgPriorityGroup = CFG_PRIORITY_GROUP_CORE3;
        Os_SystemStack = &Os_SystemStackCore3;
        break;
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
    case 4:
        Os_SCB.sysIsrNestQueue = Os_SysIsrNestQueueCore4;
        /*add () to pass QAC*/
        Os_ReadyMapSize = READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE4));
        Os_CfgPriorityMax = CFG_PRIORITY_MAX_CORE4;
        Os_ReadyMap = Os_ReadyMap_Core4;
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyTable = Os_ReadyTable_CORE4;
#else
        Os_ReadyQueueMark = Os_ReadyQueueMark_Core4;
        Os_ActivateQueueSize = Os_ActivateQueueSize_Core4;
        Os_ReadyQueue = Os_ReadyQueue_Core4;
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */
        Os_PrioGroup = Os_PrioGroupCore4;
        Os_PrioMask = Os_PrioMaskCore4;
        Os_CfgPriorityGroup = CFG_PRIORITY_GROUP_CORE4;
        Os_SystemStack = &Os_SystemStackCore4;
        break;
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */

#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
    case 5:
        Os_SCB.sysIsrNestQueue = Os_SysIsrNestQueueCore5;
        /*add () to pass QAC*/
        Os_ReadyMapSize = READY_MAP_SIZE((CFG_PRIORITY_MAX_CORE5));
        Os_CfgPriorityMax = CFG_PRIORITY_MAX_CORE5;
        Os_ReadyMap = Os_ReadyMap_Core5;
#if ((OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC))
        Os_ReadyTable = Os_ReadyTable_CORE5;
#else
        Os_ReadyQueueMark = Os_ReadyQueueMark_Core5;
        Os_ActivateQueueSize = Os_ActivateQueueSize_Core5;
        Os_ReadyQueue = Os_ReadyQueue_Core5;
#endif /* (OS_BCC1 == CFG_CC) || (OS_ECC1 == CFG_CC) */
        Os_PrioGroup = Os_PrioGroupCore5;
        Os_PrioMask = Os_PrioMaskCore5;
        Os_CfgPriorityGroup = CFG_PRIORITY_GROUP_CORE5;
        Os_SystemStack = &Os_SystemStackCore5;
        break;
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */

    /*add comments to pass QAC.*/
    default:
        /* Nothing to do. */
        break;
    }
}

/******************************************************************************/
/*
 * Brief                <StartOS synchronizes all cores twice. The first
 *                         synchronization point is located before the StartupHooks
 *                         are executed, the second after the OS-Application specific
 *                         StartupHooks have finished and before the scheduler is started.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0842, DD_1_1205, DD_1_0843>
 */
/******************************************************************************/
static FUNC(void, OS_CODE) Os_SynPoint(uint8 point)
{
    switch (point)
    {
    /* Multi core state Synchronous point0 ,for check start os appmode. */
    case 0:
        Os_CoreCB.coreStateSynPoint0[Os_SCB.sysCore] = TRUE;
        while ((FALSE == Os_CoreCB.coreStateSynPoint0[0])
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint0[1])
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint0[2])
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint0[3])
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint0[4])
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint0[5])
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */
        )
        {
            /* Nothing to do. */
        }
        break;

    /* SWS_Os_00580:synchronize before the global StartupHook. */
    case 1:
        Os_CoreCB.coreStateSynPoint1[Os_SCB.sysCore] = TRUE;
        while ((FALSE == Os_CoreCB.coreStateSynPoint1[0])
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint1[1])
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint1[2])
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint1[3])
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint1[4])
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint1[5])
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */
        )
        {
            /* Nothing to do. */
        }
        break;

    /* SWS_Os_00579:synchronize after the global StartupHook. */
    case 2:
        Os_CoreCB.coreStateSynPoint2[Os_SCB.sysCore] = TRUE;
        while ((FALSE == Os_CoreCB.coreStateSynPoint2[0])
#if (TRUE == CFG_CORE1_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint2[1])
#endif /* TRUE == CFG_CORE1_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE2_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint2[2])
#endif /* TRUE == CFG_CORE2_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE3_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint2[3])
#endif /* TRUE == CFG_CORE3_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE4_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint2[4])
#endif /* TRUE == CFG_CORE4_AUTOSAROS_ENABLE */
#if (TRUE == CFG_CORE5_AUTOSAROS_ENABLE)
               || (FALSE == Os_CoreCB.coreStateSynPoint2[5])
#endif /* TRUE == CFG_CORE5_AUTOSAROS_ENABLE */
        )
        {
            /* Nothing to do. */
        }
        break;

    /* SWS_Os_00587:synchronize before calling the global ShutdownHook. */
    case 3:
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
        break;

    /*add comments to pass QAC.*/
    default:
        /* Nothing to do. */
        break;
    }
}

/******************************************************************************/
/*
 * Brief                <Check the AppMode when calling StartOS in multicore.>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <StartOS>
 * REQ ID               <DD_1_0936, DD_1_1210, DD_1_1211, DD_1_1530, DD_1_0845>
 */
/******************************************************************************/
static FUNC(Os_AppModeType, OS_CODE) Os_CheckAppMode(Os_AppModeType mode)
{
    Os_AppModeType retAppMode = DONOTCARE;
    Os_CoreIdType loop_core;

    /* It is not allowed to call StartOS on cores
     * activated by StartNonAutosarCore.*/
    if (OS_AUTOSAR_CORES <= Os_SCB.sysCore)
    {
        while (1)
        {
            /* Nothing to do. */
        }
    }

    /* Multi core state Synchronous point0, for check start os appmode. */
    Os_CoreCB.osAppMode[Os_SCB.sysCore] = mode;
    //Os_SynPoint(0);

    /* SWS_Os_00609: if StartOS is called with the AppMode "DONOTCARE"
     * the application mode of the other core(s) (differing from
     * "DONOTCARE") shall be used. */
    for (loop_core = 0u; loop_core < OS_AUTOSAR_CORES; loop_core++)
    {
        if (DONOTCARE != Os_CoreCB.osAppMode[loop_core])
        {
            if (DONOTCARE == retAppMode)
            {
                retAppMode = Os_CoreCB.osAppMode[loop_core];
            }
            else
            {
                if (retAppMode != Os_CoreCB.osAppMode[loop_core])
                {
                    while (1)
                    {
                        /* Nothing to do. */
                    }
                }
            }
        }
    }

    /* SWS_Os_00610: At least one core shall define an AppMode other than
     * "DONOTCARE". */
    if (DONOTCARE == retAppMode)
    {
        while (1)
        {
            /* Nothing to do. */
        }
    }
    else
    {
        for (loop_core = 0u; loop_core < OS_AUTOSAR_CORES; loop_core++)
        {
            Os_CoreCB.osAppMode[loop_core] = retAppMode;
        }
    }

    return retAppMode;
}

/********************************************************************/
/*
 * Brief                <Clear the CoreCB info>
 * Service ID           <none>
 * Sync/Async           <none>
 * Reentrancy           <none>
 * param-eventId[in]    <None>
 * Param-Name[out]      <None>
 * Param-Name[in/out]   <None>
 * return               <None>
 * PreCondition         <None>
 * CallByAPI            <ShutdownOS>
 * REQ ID               <DD_1_0935, DD_1_1531>
 *
 */
/********************************************************************/
static FUNC(void, OS_CODE) Os_DeInitCoreInfo(void)
{
    VAR(uint16, OS_VAR) vCoreId = Os_SCB.sysCore;
    /*clear the CoreCB info*/
    Os_GetSpinlock(&Os_SpinlockSync);
    Os_CoreCB.coreStateActive &= (Os_CoreIdType)(~((Os_CoreIdType)1 << vCoreId));
    Os_CoreCB.osAppMode[vCoreId] = OS_NULL_APPMODE;
    Os_CoreCB.coreStatus[vCoreId] = OS_CORE_STATUS_INVALID;
    Os_ReleaseSpinlock(&Os_SpinlockSync);
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"
/*=======[E N D   O F   F I L E]==============================================*/
