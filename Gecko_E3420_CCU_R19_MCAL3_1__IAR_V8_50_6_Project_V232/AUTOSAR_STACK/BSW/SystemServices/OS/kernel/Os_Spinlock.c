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
**  FILENAME    : Os_Spinlock.c                                               **
**                                                                            **
**  Created on  :                                                             **
**  Author      : shi.shu                                                     **
**  Vendor      :                                                             **
**  DESCRIPTION : spinlock manager                                            **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/

/*=======[R E V I S I O N   H I S T O R Y]====================================*/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V0.1.0     2016-10-19    shi.shu     Initial version.
 *  V0.2.0     2019-08-21    shun.li & zhiqiang.huang   Functional safety initial version.
 *  V1.0.0     2019-11-21    shun.li     Functional safety version.
 *  V1.0.1     2021-5-12     shun.li     Repair release spinlock error problem.
 *  v1.0.2     2021-8-19     shun.li     Modify the suspend and release OS interrupts interface
 *                                       in getspinlock and releasespinlock function.
 */
/*============================================================================*/

/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 */
/*============================================================================*/

/*=======[I N C L U D E S]====================================================*/
#include "Os_Internal.h"

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/

/*=======[V E R S I O N  C H E C K]===========================================*/

/*=======[M A C R O S]========================================================*/
/* DD_1_0178 */
#define OS_SPINLOCK_UNLOCK 0x0u
/* DD_1_0179 */
#define OS_SPINLOCK_LOCK 0x1u
/* DD_1_0180 */
#define OS_SPINLOCK_OCCUPY_SUCCESS 0x0u
/* DD_1_0181 */
#define OS_SPINLOCK_OCCUPY_NO_SUCCESS 0x1u

/*=======[T Y P E   D E F I N I T I O N S]====================================*/

/*=======[E X T E R N A L   D A T A]==========================================*/

/*=======[E X T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[I N T E R N A L   D A T A]==========================================*/

#define OS_START_SEC_CODE
#include "Os_MemMap.h"
/*=======[I N T E R N A L   F U N C T I O N   D E C L A R A T I O N S]========*/

/*=======[F U N C T I O N   I M P L E M E N T A T I O N S]====================*/
#if (CFG_SPINLOCK_MAX > 0U)
/******************************************************************************/
/*
 * Brief                <Initialize the spin lock>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <None>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <Os_InitSystem>
 * REQ ID               <DD_1_0858, DD_1_0859>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_InitSpinlock(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Os_SpinlockIdType i;

    for (i = 0u; i < CFG_SPINLOCK_MAX; i++)
    {
        Os_SLCB[i].objOccupyType = OBJECT_MAX;
        Os_SLCB[i].objOccupyId = OS_OBJECT_INVALID;
    }
}

/******************************************************************************/
/*
 * Brief                <The get spin lock function inside the OS>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <SpinlockId>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0590, DD_1_0591, DD_1_0592, DD_1_0593, DD_1_0594, DD_1_0595,
 *                       DD_1_0596, DD_1_0599, DD_1_1046, DD_1_1232, DD_1_1233, DD_1_1234,
 *                       DD_1_1270, DD_1_1594, DD_1_1676>
 */
/******************************************************************************/
FUNC(StatusType, OS_CODE) GetSpinlock(SpinlockIdType SpinlockId) /* PRQA S 1503 */ /* MISRA Rule 2.1 */
{
    uint32 result;
#if (CFG_STD_RESOURCE_MAX > 0U)
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTCB;
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pICB;
#endif /* CFG_STD_RESOURCE_MAX > 0U */
    StatusType OsReturnErr = E_OK;
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
    ApplicationType appCfgId;
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
    Os_CoreIdType Core_Id;
    Os_CoreIdType Core_Index;
    OS_GETSPINLOCK_DEFINE();
#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

    Core_Id = Os_SCB.sysCore;
    Core_Index = Core_Id << 12;

/*service protection*/
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_GET_SPINLOCK) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_CheckObjAcs(OBJECT_SPINLOCK, SpinlockId) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
#endif /* (TRUE == CFG_SERVICE_PROTECTION_ENABLE) */
    {
#if (CFG_STD_RESOURCE_MAX > 0U)
        pTCB = Os_SCB.sysRunningTCB;
        pICB = &Os_ICB[Os_SCB.sysRunningIsrCat2Id]; /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
#endif                                                                /* CFG_STD_RESOURCE_MAX > 0U */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        /*Os_00689*/
        if (SpinlockId >= CFG_SPINLOCK_MAX)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ID;
        }
        /*Os_00691*/
        else if (
            (OS_SPINLOCK_INVALID != Os_CoreCB.currentSpinlockOccupyLevel)
            && (Os_CoreCB.currentSpinlockOccupyLevel > SpinlockId))
        {
            OsReturnErr = E_OS_NESTING_DEADLOCK;
        }
/*Os_00690*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
        else if (Os_SLCB[SpinlockId].objOccupyId != OS_OBJECT_INVALID)
        {
            appCfgId = CheckObjectOwnership(Os_SLCB[SpinlockId].objOccupyType, Os_SLCB[SpinlockId].objOccupyId);
            if (Os_AppCfg[appCfgId].OsHostCore == Os_SCB.sysCore)
            {
                OsReturnErr = E_OS_INTERFERENCE_DEADLOCK;
            }
        }
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
        else
        {
            /*nothing to do*/
        }
#endif /* OS_STATUS_EXTENDED == CFG_STATUS */

        if ((StatusType)E_OK == OsReturnErr)
        {
            switch (Os_SpinlockCfg[SpinlockId].osSpinlockMethod)
            {
            case LOCK_ALL_INTERRUPTS:
                Os_ArchDisableInt(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */
                break;

            case LOCK_CAT2_INTERRUPTS:
                Os_SpinlockSuspendOsIsr();
                break;

            case LOCK_WITH_RES_SCHEDULER:
#if (TRUE == CFG_USERESSCHEDULER)
                (void)GetResource(RES_SCHEDULER);
#endif /* TRUE == CFG_USERESSCHEDULER */
                break;

            case LOCK_NOTHING:
                /* Nothing to do. */
                break;

            /*add to pass QAC*/
            default:
                /* Nothing to do. */
                break;
            }

            do
            {
                result = Os_CmpSwapW(&Os_Spinlock[SpinlockId], OS_SPINLOCK_UNLOCK, OS_SPINLOCK_LOCK);
            } while (result > 0u); /*Os_00687*/

            Os_SLCB[SpinlockId].occupied = TRUE;
            Os_CoreCB.currentSpinlockOccupyLevel = SpinlockId;
            if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
            {
                Os_SLCB[SpinlockId].objOccupyId = (Core_Index | Os_SCB.sysRunningTaskID);
                Os_SLCB[SpinlockId].objOccupyType = OBJECT_TASK;

#if (CFG_STD_RESOURCE_MAX > 0U)
                /*res and spinlock should together release as LIFO order*/
                pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount] = OBJECT_SPINLOCK;
                pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount] = SpinlockId;
                pTCB->taskCriticalZoneCount = pTCB->taskCriticalZoneCount + 1u;
#endif /* CFG_STD_RESOURCE_MAX > 0U */
            }
            else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
            {
                Os_SLCB[SpinlockId].objOccupyId = (Core_Index | Os_SCB.sysRunningIsrCat2Id);
                Os_SLCB[SpinlockId].objOccupyType = OBJECT_ISR;

#if (CFG_STD_RESOURCE_MAX > 0U)
                /*res and spinlock should together release as LIFO order*/
                pICB->isr2CriticalZoneType[pICB->isr2CriticalZoneCount] = OBJECT_SPINLOCK;
                pICB->isr2CriticalZoneStack[pICB->isr2CriticalZoneCount] = SpinlockId;
                pICB->isr2CriticalZoneCount = pICB->isr2CriticalZoneCount + 1u;
#endif /* CFG_STD_RESOURCE_MAX > 0U */
            }
            else
            {
                /* Intentionally Empty */
            }
        }
    }

    OS_GETSPINLOCK_EXIT();
    /*Os_00688*/
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <ReleaseSpinlock releases a spinlock variable that was occupied before.
 *                       Before terminating a TASK all spinlock variables that have been occupied with
 *                       GetSpinlock() shall be released. Before calling WaitEVENT all Spinlocks
 *                       shall be released>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <SpinlockId>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0600, DD_1_0601, DD_1_0602, DD_1_0603, DD_1_0604, DD_1_0605,
 *                       DD_1_0606, DD_1_0609, DD_1_1047, DD_1_1237, DD_1_1238, DD_1_1271,
 *                       DD_1_1595, DD_1_1677>
 */
/******************************************************************************/

FUNC(StatusType, OS_CODE) ReleaseSpinlock(SpinlockIdType SpinlockId)
{
#if (CFG_STD_RESOURCE_MAX > 0U)
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTCB;
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pICB;
#endif /* CFG_STD_RESOURCE_MAX > 0U */
    Os_SpinlockIdType preSpinlockId;
    StatusType OsReturnErr = E_OK;
    Os_CoreIdType Core_Id;
    Os_CoreIdType Core_Index;
    uint32 result;

    OS_RELEASESPINLOCK_DEFINE();
#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

    Core_Id = Os_SCB.sysCore;
    Core_Index = Core_Id << 12;

/*service protection*/
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_RELEASE_SPINLOCK) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (FALSE == Os_CheckObjAcs(OBJECT_SPINLOCK, SpinlockId))
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
#endif /* (TRUE == CFG_SERVICE_PROTECTION_ENABLE) */
    {
#if (CFG_STD_RESOURCE_MAX > 0U)
        pTCB = Os_SCB.sysRunningTCB;
        pICB = &Os_ICB[Os_SCB.sysRunningIsrCat2Id]; /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
#endif                                                                /* CFG_STD_RESOURCE_MAX > 0U */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        /*Os_00698*/
        if (SpinlockId >= CFG_SPINLOCK_MAX)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ID;
        }
        /*Os_00701*/
        else if (
            (SpinlockId != Os_CoreCB.currentSpinlockOccupyLevel)
            && (OS_SPINLOCK_INVALID != Os_CoreCB.currentSpinlockOccupyLevel))
        {
            OsReturnErr = E_OS_NOFUNC;
        }
        else if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
        {
            /*Os_00696,Os_00699*/
            if (((Os_SLCB[SpinlockId].objOccupyId != (Core_Index | Os_SCB.sysRunningTaskID))
                 && (Os_SLCB[SpinlockId].objOccupyType == OBJECT_TASK))
                || (OS_SPINLOCK_INVALID == Os_CoreCB.currentSpinlockOccupyLevel))
            {
                OsReturnErr = E_OS_STATE;
            }
/*res and spinlock should together release as LIFO order*/
#if (CFG_STD_RESOURCE_MAX > 0U)
            else if (
                (pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount - 1u] != OBJECT_SPINLOCK)
                || (pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount - 1u] != SpinlockId))
            {
                OsReturnErr = E_OS_NOFUNC;
            }
#endif /* CFG_STD_RESOURCE_MAX > 0U */
            else
            {
                /*nothing to do*/
            }
        }
        else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
        {
            /*Os_00696,Os_00699*/
            if ((((Os_SLCB[SpinlockId].objOccupyId != (Core_Index | Os_SCB.sysRunningIsrCat2Id))
                  && (Os_SLCB[SpinlockId].objOccupyType == OBJECT_ISR)))
                || (OS_SPINLOCK_INVALID == Os_CoreCB.currentSpinlockOccupyLevel))
            {
                OsReturnErr = E_OS_STATE;
            }
/*res and spinlock should together release as LIFO order*/
#if (CFG_STD_RESOURCE_MAX > 0U)
            else if (
                (pICB->isr2CriticalZoneType[pICB->isr2CriticalZoneCount - 1u] != OBJECT_SPINLOCK)
                || (pICB->isr2CriticalZoneStack[pICB->isr2CriticalZoneCount - 1u] != SpinlockId))
            {
                OsReturnErr = E_OS_NOFUNC;
            }
#endif /* CFG_STD_RESOURCE_MAX > 0U */
            else
            {
                /*nothing to do*/
            }
        }
        else
        {
            /* Intentionally Empty */
        }
        if ((StatusType)E_OK == OsReturnErr)
#endif /*    #if ( OS_STATUS_EXTENDED == CFG_STATUS )*/
        {
            preSpinlockId = SpinlockId;
            Os_SLCB[SpinlockId].objOccupyId = OS_TASK_INVALID;
            Os_SLCB[SpinlockId].objOccupyType = OBJECT_MAX;
            Os_SLCB[SpinlockId].occupied = FALSE;

            while (SpinlockId > 0u) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
            {
                SpinlockId--;
                if ((boolean)TRUE == Os_SLCB[SpinlockId].occupied)
                {
                    break;
                }
            }

            if ((boolean)TRUE == Os_SLCB[SpinlockId].occupied)
            {
                Os_CoreCB.currentSpinlockOccupyLevel = SpinlockId;
            }
            else
            {
                Os_CoreCB.currentSpinlockOccupyLevel = OS_SPINLOCK_INVALID;
            }

#if (CFG_STD_RESOURCE_MAX > 0U)
            if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
            {
                /*res and spinlock should together release as LIFO order*/
                pTCB->taskCriticalZoneCount = pTCB->taskCriticalZoneCount - 1u;
                pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount] = OBJECT_MAX;
                pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount] = OS_OBJECT_INVALID;
            }
            else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
            {
                /*res and spinlock should together release as LIFO order*/
                pICB->isr2CriticalZoneCount = pICB->isr2CriticalZoneCount - 1u;
                pICB->isr2CriticalZoneType[pICB->isr2CriticalZoneCount] = OBJECT_MAX;
                pICB->isr2CriticalZoneStack[pICB->isr2CriticalZoneCount] = OS_OBJECT_INVALID;
            }
            else
            {
                /* Intentionally Empty */
            }
#endif /* CFG_STD_RESOURCE_MAX > 0U */

            /*Os_00696*/
            do
            {
                result = Os_CmpSwapW(&Os_Spinlock[preSpinlockId], OS_SPINLOCK_LOCK, OS_SPINLOCK_UNLOCK);
            } while (result > 0u); /*Os_00687*/
            /*Os_00696*/
            switch (Os_SpinlockCfg[preSpinlockId].osSpinlockMethod)
            {
            case LOCK_ALL_INTERRUPTS:
                Os_ArchEnableInt(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */
                break;

            case LOCK_CAT2_INTERRUPTS:
                Os_SpinlockResumeOsIsr();
                break;

            case LOCK_WITH_RES_SCHEDULER:
#if (TRUE == CFG_USERESSCHEDULER)
                (void)ReleaseResource(RES_SCHEDULER);
#endif /* TRUE == CFG_USERESSCHEDULER */
                break;

            case LOCK_NOTHING:
                /* Nothing to do. */
                break;

            /*add to pass QAC*/
            default:
                /* Nothing to do. */
                break;
            }
        }
    }

    OS_RELEASESPINLOCK_EXIT();
    /*Os_00697*/
    return OsReturnErr;
}

/******************************************************************************/
/*
 * Brief                <TryToGetSpinlock has the same functionality as GetSpinlock with
 *                       the difference that if the spinlock is already occupied by
 *                       a TASK on a different core the function sets the OUT parameter
 *                       "Success" and returns with E_OK>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <SpinlockId>
 * param[out]           <Success>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <None>
 * REQ ID               <DD_1_0610, DD_1_0620, DD_1_0611, DD_1_0612, DD_1_0613, DD_1_0614,
 *                       DD_1_0615, DD_1_0616, DD_1_0617, DD_1_1048, DD_1_1235, DD_1_1236,
 *                       DD_1_1272, DD_1_1596, DD_1_1636, DD_1_1678>
 */
/******************************************************************************/
/* PRQA S 1503++ */ /* MISRA Rule 2.1 */
FUNC(StatusType, OS_CODE) TryToGetSpinlock(SpinlockIdType SpinlockId, TryToGetSpinlockType* Success)
/* PRQA S 1503-- */ /* MISRA Rule 2.1 */
{
    uint32 result;
#if (CFG_STD_RESOURCE_MAX > 0U)
    P2VAR(Os_TCBType volatile, AUTOMATIC, OS_VAR) pTCB;
    P2VAR(Os_ICBType volatile, AUTOMATIC, OS_VAR) pICB;
#endif /* CFG_STD_RESOURCE_MAX > 0U */
    ApplicationType appCfgId;
    StatusType OsReturnErr = E_OK;
    Os_CoreIdType Core_Id;
    Os_CoreIdType Core_Index;

    OS_TRYTOSPINLOCK_DEFINE();
#if (TRUE == CFG_SRV_SHELLOS)
    /* PRQA S 3200,3335,2742,2880,2741++ */ /* MISRA Rule 17.7,17.3,14.3,2.1 */
    OS_CHANGCPUMODE(OS_CPUMODE_SUPERVISOR);
/* PRQA S 3200,3335,2742,2880,2741-- */     /* MISRA Rule 17.7,17.3,14.3,2.1 */
#endif                                      /* TRUE == CFG_SRV_SHELLOS */

    Core_Id = Os_SCB.sysCore;
    Core_Index = Core_Id << 12;

/*service protection*/
#if (TRUE == CFG_SERVICE_PROTECTION_ENABLE)
    if (Os_WrongContext(OS_CONTEXT_TRY_TO_GET_SPINLOCK) != TRUE)
    {
        OsReturnErr = E_OS_CALLEVEL;
    }
    else if (Os_AddressWritable((uint8*)Success) != TRUE)
    {
        OsReturnErr = E_OS_ILLEGAL_ADDRESS;
    }
    else if (Os_CheckObjAcs(OBJECT_SPINLOCK, SpinlockId) != TRUE)
    {
        OsReturnErr = E_OS_ACCESS;
    }
    else
#endif /* (TRUE == CFG_SERVICE_PROTECTION_ENABLE) */
    {
#if (CFG_STD_RESOURCE_MAX > 0U)
        pTCB = Os_SCB.sysRunningTCB;
        pICB = &Os_ICB[Os_SCB.sysRunningIsrCat2Id]; /* PRQA S 0404 */ /* MISRA Rule 1.3,13.2 */
#endif                                                                /* CFG_STD_RESOURCE_MAX > 0U */
#if (OS_STATUS_EXTENDED == CFG_STATUS)
        /*Os_00707*/
        if (SpinlockId >= CFG_SPINLOCK_MAX)
        {
#if (TRUE == CFG_ERRORHOOK)
            Os_CallErrorHook(E_OS_ID);
#endif /* TRUE == CFG_ERRORHOOK */

            OsReturnErr = E_OS_ID;
        }
        /*Os_00709*/
        else if (
            (OS_SPINLOCK_INVALID != Os_CoreCB.currentSpinlockOccupyLevel)
            && (Os_CoreCB.currentSpinlockOccupyLevel >= SpinlockId))
        {
            OsReturnErr = E_OS_NESTING_DEADLOCK;
        }
/*Os_00708*/
#if ((OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC))
        else if (Os_SLCB[SpinlockId].objOccupyId != OS_OBJECT_INVALID)
        {
            appCfgId = CheckObjectOwnership(Os_SLCB[SpinlockId].objOccupyType, Os_SLCB[SpinlockId].objOccupyId);
            if (Os_AppCfg[appCfgId].OsHostCore == Os_SCB.sysCore)
            {
                OsReturnErr = E_OS_INTERFERENCE_DEADLOCK;
            }
        }
#endif /* (OS_SC3 == CFG_SC) || (OS_SC4 == CFG_SC) */
        else
        {
            /*nothing to do*/
        }
        if ((StatusType)E_OK == OsReturnErr)
#endif /*#if ( OS_STATUS_EXTENDED == CFG_STATUS )*/
        {
            switch (Os_SpinlockCfg[SpinlockId].osSpinlockMethod)
            {
            case LOCK_ALL_INTERRUPTS:
                Os_ArchDisableInt(); /* PRQA S 3335 */ /* MISRA Rule 17.3 */
                break;

            case LOCK_CAT2_INTERRUPTS:
                Os_SpinlockSuspendOsIsr();
                break;

            case LOCK_WITH_RES_SCHEDULER:
#if (TRUE == CFG_USERESSCHEDULER)
                (void)GetResource(RES_SCHEDULER);
#endif /* TRUE == CFG_USERESSCHEDULER */
                break;

            case LOCK_NOTHING:
                /* Nothing to do. */
                break;

            /*add to pass QAC*/
            default:
                /* Nothing to do. */
                break;
            }

            /*Os_00705*/
            result = Os_CmpSwapW(&Os_Spinlock[SpinlockId], OS_SPINLOCK_UNLOCK, OS_SPINLOCK_LOCK);
            /*Os_00706*/
            if (OS_SPINLOCK_OCCUPY_SUCCESS == result)
            {
                *Success = TRYTOGETSPINLOCK_SUCCESS;

                Os_SLCB[SpinlockId].occupied = TRUE;
                Os_CoreCB.currentSpinlockOccupyLevel = SpinlockId;
                if (OS_LEVEL_TASK == Os_SCB.sysOsLevel)
                {
                    Os_SLCB[SpinlockId].objOccupyId = (Core_Index | Os_SCB.sysRunningTaskID);
                    Os_SLCB[SpinlockId].objOccupyType = OBJECT_TASK;

#if (CFG_STD_RESOURCE_MAX > 0U)
                    /*res and spinlock should together release as LIFO order*/
                    pTCB->taskCriticalZoneType[pTCB->taskCriticalZoneCount] = OBJECT_SPINLOCK;
                    pTCB->taskCriticalZoneStack[pTCB->taskCriticalZoneCount] = SpinlockId;
                    pTCB->taskCriticalZoneCount = pTCB->taskCriticalZoneCount + 1u;
#endif /* CFG_STD_RESOURCE_MAX > 0U */
                }
                else if (OS_LEVEL_ISR2 == Os_SCB.sysOsLevel)
                {
                    Os_SLCB[SpinlockId].objOccupyId = (Core_Index | Os_SCB.sysRunningIsrCat2Id);
                    Os_SLCB[SpinlockId].objOccupyType = OBJECT_ISR;

#if (CFG_STD_RESOURCE_MAX > 0U)
                    /*res and spinlock should together release as LIFO order*/
                    pICB->isr2CriticalZoneType[pICB->isr2CriticalZoneCount] = OBJECT_SPINLOCK;
                    pICB->isr2CriticalZoneStack[pICB->isr2CriticalZoneCount] = SpinlockId;
                    pICB->isr2CriticalZoneCount = pICB->isr2CriticalZoneCount + 1u;
#endif /* CFG_STD_RESOURCE_MAX > 0U */
                }
                else
                {
                    /* Intentionally Empty */
                }
            }
            else
            {
                *Success = TRYTOGETSPINLOCK_NOSUCCESS;
            }
        }
    }

    OS_TRYTOSPINLOCK_EXIT();
    /*Os_00704*/
    return OsReturnErr;
}
#endif /* CFG_SPINLOCK_MAX > 0U */

/******************************************************************************/
/*
 * Brief                <The get spin lock function inside the OS>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <spinlock>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <ShutdownAllCores and so on>
 * REQ ID               <DD_1_0860, DD_1_0861, DD_1_1612>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_GetSpinlock(Os_SpinlockRefType spinlock)
{
    uint32 result;

    /*Os_00687*/
    do
    {
        result = Os_CmpSwapW(spinlock, OS_SPINLOCK_UNLOCK, OS_SPINLOCK_LOCK);
    } while (result > 0u);
}

/******************************************************************************/
/*
 * Brief                <The release spin lock function inside the OS>
 * Service ID           <None>
 * Sync/Async           <Synchronous>
 * Reentrancy           <Reentrant>
 * param[in]            <spinlock>
 * param[out]           <None>
 * param[in/out]        <None>
 * return               <None>
 * CallByAPI            <ShutdownAllCores and so on>
 * REQ ID               <DD_1_0862, DD_1_0863>
 */
/******************************************************************************/
FUNC(void, OS_CODE) Os_ReleaseSpinlock(Os_SpinlockRefType spinlock)
{
    uint32 result;

    do
    {
        result = Os_CmpSwapW(spinlock, OS_SPINLOCK_LOCK, OS_SPINLOCK_UNLOCK);
    } while (result > 0u);
}

#define OS_STOP_SEC_CODE
#include "Os_MemMap.h"

/*=======[E N D   O F   F I L E]==============================================*/
