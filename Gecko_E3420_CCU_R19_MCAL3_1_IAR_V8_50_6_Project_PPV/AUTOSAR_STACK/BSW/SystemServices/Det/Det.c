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
**  FILENAME    : Det.c                                                       **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Haibin.shao                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Type definition and API declaration for DET                 **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Det_Types.h"
#include "Det.h"
#include "Det_Cfg.h"

#if (DET_FORWARD_TO_DLT == STD_ON)
#include "Dlt.h"
#include "CanTp.h"
#include "TcpIp.h"
#include "SoAd.h"
#include "Gpt.h"
#endif

/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define DET_C_AR_MAJOR_VERSION (4U)
#define DET_C_AR_MINOR_VERSION (5U)
#define DET_C_AR_PATCH_VERSION (0U)
#define DET_C_SW_MAJOR_VERSION (1U)
#define DET_C_SW_MINOR_VERSION (0U)
#define DET_C_SW_PATCH_VERSION (0U)

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (DET_C_AR_MAJOR_VERSION != DET_H_AR_MAJOR_VERSION)
#error "Det.c : Mismatch in Specification Major Version"
#endif
#if (DET_C_AR_MINOR_VERSION != DET_H_AR_MINOR_VERSION)
#error "Det.c : Mismatch in Specification Major Version"
#endif
#if (DET_C_AR_PATCH_VERSION != DET_H_AR_PATCH_VERSION)
#error "Det.c : Mismatch in Specification Major Version"
#endif
#if (DET_C_SW_MAJOR_VERSION != DET_H_SW_MAJOR_VERSION)
#error "Det.c : Mismatch in Specification Major Version"
#endif
#if (DET_C_SW_MINOR_VERSION != DET_H_SW_MINOR_VERSION)
#error "Det.c : Mismatch in Specification Major Version"
#endif

/*******************************************************************************
**                      Private Data Definitions                              **
*******************************************************************************/
#define DET_START_SEC_VAR_POWER_ON_INIT_BOOLEAN
#include "Det_MemMap.h"
static VAR(boolean, DET_VAR) detModuleInit = (boolean)FALSE;
#define DET_STOP_SEC_VAR_POWER_ON_INIT_BOOLEAN
#include "Det_MemMap.h"

#define DET_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Det_MemMap.h"
static VAR(Det_StateType, DET_VAR) Det_RunState = DET_UNINITIALIZED;
#define DET_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "Det_MemMap.h"

#define DET_START_SEC_VAR_NO_INIT_8BIT
#include "Det_MemMap.h"
/* recursion limit counter \trace DSGN-Det22792 */
static VAR(uint8, DET_VAR) detRecursionCounterReportError;
/* recursion limit counter \trace DSGN-Det22792 */
static VAR(uint8, DET_VAR) detRecursionCounterReportRuntimeError;
/* recursion limit counter \trace DSGN-Det22792 */
static VAR(uint8, DET_VAR) detRecursionCounterReportTransientFault;
#define DET_STOP_SEC_VAR_NO_INIT_8BIT
#include "Det_MemMap.h"

#if (STD_ON == DET_FORWARD_TO_DLT)
#define DET_START_SEC_VAR_NO_INIT_32BIT
#include "Det_MemMap.h"
static VAR(uint32, DET_VAR) Det_GptLastTime;
static VAR(uint32, DET_VAR) Det_GptCurrentTime;
#define DET_STOP_SEC_VAR_NO_INIT_32BIT
#include "Det_MemMap.h"
#endif /* STD_ON == DET_FORWARD_TO_DLT */

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)

#define DET_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"
/* global variables, should be put in a watch window */
#if (DET_SIZE_OF_GLOBAL_FILTER > 0)
/* use this variable to configure global filters */
volatile VAR(DetInfoType, DET_VAR) detGlobalFilter[DET_SIZE_OF_GLOBAL_FILTER];
#endif /* DET_GLOBALFILTERSIZE > 0 */

#if (DET_SIZE_OF_BREAK_FILTER > 0)
/* use this variable to configure break filters */
volatile VAR(DetInfoType, DET_VAR) detBreakFilter[DET_SIZE_OF_BREAK_FILTER];
#endif /* DET_BREAKFILTERSIZE > 0 */

#if (DET_SIZE_OF_DLT_FILTER > 0)
/* use this variable to configure dlt filters */
volatile VAR(DetInfoType, DET_VAR) detDltFilter[DET_SIZE_OF_DLT_FILTER];
#endif /* DET_DLTFILTERSIZE > 0 */

#if (DET_SIZE_OF_LOG_BUFFER > 0)
/* use this variable to view log buffer */
volatile VAR(DetInfoType, DET_VAR) detLogBuffer[DET_SIZE_OF_LOG_BUFFER];
#endif /* DET_LOGBUFFERSIZE > 0 */
#define DET_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"

#if (DET_SIZE_OF_ERROR_HOOK_TABLE > 0)
#define DET_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"
Det_CallbackFncType Det_CallbackList[DET_SIZE_OF_ERROR_HOOK_TABLE];
#define DET_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"

#if (DET_MAX_RAMLOG_SIZE > 0)
#define DET_START_SEC_VAR_NO_INIT_32BIT
#include "Det_MemMap.h"
/* Ram log variables in uninitialized memory */
SECTION_RAMLOG uint32 Det_RamlogIndex;
#define DET_STOP_SEC_VAR_NO_INIT_32BIT
#include "Det_MemMap.h"

#define DET_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"
/* Supress lintwarning about Det_Ramlog not being accessed */
SECTION_RAMLOG Det_EntryType Det_RamLog[DET_MAX_RAMLOG_SIZE];
#define DET_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"
#endif /* DET_MAX_RAMLOG_SIZE > 0 */

#endif /* DET_SIZE_OF_ERROR_HOOK_TABLE > 0 */

#if (DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE > 0)

#define DET_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"
Det_CallbackFncType Det_RunTimeCallbackList[DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE];
#define DET_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"

#if (DET_RUNTIME_MAX_RAMLOG_SIZE > 0)
#define DET_START_SEC_VAR_NO_INIT_32BIT
#include "Det_MemMap.h"
/* Ram log variables in uninitialized memory */
SECTION_RAMLOG uint32 Det_RunTimeRamlogIndex;
#define DET_STOP_SEC_VAR_NO_INIT_32BIT
#include "Det_MemMap.h"

#define DET_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"
/* Supress lintwarning about Det_Ramlog not being accessed */
SECTION_RAMLOG Det_EntryType Det_RunTimeRamLog[DET_RUNTIME_MAX_RAMLOG_SIZE];
#define DET_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"
#endif /* DET_RUNTIME_MAX_RAMLOG_SIZE > 0 */
#endif /* DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE > 0 */

#if (DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE > 0)
#define DET_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"
Det_CallbackFncType Det_TransientCallbackList[DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE];
#define DET_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"

#if (DET_TRANSIENT_MAX_RAMLOG_SIZE > 0)
#define DET_START_SEC_VAR_NO_INIT_32BIT
#include "Det_MemMap.h"
/* Ram log variables in uninitialized memory */
SECTION_RAMLOG uint32 Det_TransientRamlogIndex;
#define DET_STOP_SEC_VAR_NO_INIT_32BIT
#include "Det_MemMap.h"

#define DET_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"
/* Supress lintwarning about Det_Ramlog not being accessed */
SECTION_RAMLOG Det_EntryType Det_TransientRamLog[DET_TRANSIENT_MAX_RAMLOG_SIZE];
#define DET_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"

#endif /* DET_TRANSIENT_MAX_RAMLOG_SIZE > 0 */
#endif /* DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE > 0 */

#endif /* STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT */

#define DET_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"
/* use this variable to configure DET debug operation */
volatile VAR(DetStatusType, DET_VAR) detStatus;
#define DET_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Det_MemMap.h"

#define DET_START_SEC_VAR_NO_INIT_8BIT
#include "Det_MemMap.h"
volatile VAR(uint8, DET_VAR) Det_ErrorCodeId;
volatile VAR(uint8, DET_VAR) Det_FaultCodeId;
#define DET_STOP_SEC_VAR_NO_INIT_8BIT
#include "Det_MemMap.h"

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define DET_START_SEC_CODE
#include "Det_MemMap.h"

#if (STD_ON == DET_FORWARD_TO_DLT)
static boolean Det_GetGptFlag_1ms(void);
#endif /* STD_ON == DET_FORWARD_TO_DLT */

#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
static FUNC(boolean, DET_CODE) Det_CheckFilterMatch(
    volatile P2CONST(DetInfoType, AUTOMATIC, DET_VAR) filter,
    VAR(uint8, AUTOMATIC) size,
    VAR(boolean, AUTOMATIC) active,
    P2CONST(DetInfoType, AUTOMATIC, DET_VAR) detInfo);
static FUNC(boolean, DET_CODE)
    Det_LogError(VAR(boolean, AUTOMATIC) active, P2CONST(DetInfoType, AUTOMATIC, DET_VAR) detInfo);
#endif /* STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT */

static FUNC(void, DET_CODE) Det_EndlessLoop(void);

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"

#define DET_START_SEC_CODE
#include "Det_MemMap.h"
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#if (STD_ON == DET_FORWARD_TO_DLT)
static boolean Det_GetGptFlag_1ms(void)
{
    boolean ret = (boolean)FALSE;
    uint32 time;
    (void)Gpt_GetPredefTimerValue(GPT_PREDEF_TIMER_100US_32BIT, (uint32* const)&Det_GptCurrentTime);
    time = (uint32)(Det_GptCurrentTime - Det_GptLastTime);
    if (time >= (uint32)9u)
    {
        Det_GptLastTime = Det_GptCurrentTime;
        ret = (boolean)TRUE;
    }
    return ret;
}
#endif /* STD_ON == DET_FORWARD_TO_DLT */

#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)

/******************************************************************************/
/*
 * Brief               Check if a DET error matches filter conditions
 * details             A filter match is detected if all structure members of at least one filter and
                       detInfo are identical or the non-identical ones are don't care (0xFF).
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      filter: pointer to an array of filters
                       size: number of filters
                       active: flag to indicate if filter is active
                       detInfo: pointer to structure holding DET error for filtering
 * Param-Name[out]     None:
 * Param-Name[in/out]  None:
 * Return              boolean: FALSE: no filter match, TRUE: filter match
 */
/******************************************************************************/
static FUNC(boolean, DET_CODE) Det_CheckFilterMatch(
    volatile P2CONST(DetInfoType, AUTOMATIC, DET_VAR) filter,
    VAR(uint8, AUTOMATIC) size,
    VAR(boolean, AUTOMATIC) active,
    P2CONST(DetInfoType, AUTOMATIC, DET_VAR) detInfo)
{
    VAR(boolean, AUTOMATIC) retval = (boolean)FALSE;
#if (STD_ON == DET_CHECK_FILTER_MATCH_ENABLE)
    VAR(uint32, AUTOMATIC) iloop;
    /* if filter is active */
    if ((boolean)TRUE == active)
    {
        /* linear search over all filters */
        for (iloop = 0U; iloop < size; iloop++)
        {
            /* compare each structure member if it is identical or if filter is set to don't care */
            if (((filter[iloop].mModuleId == detInfo->mModuleId) || (filter[iloop].mModuleId == DET_DONTCARE_16))
                && ((filter[iloop].mInstanceId == detInfo->mInstanceId)
                    || (filter[iloop].mInstanceId == DET_DONTCARE_8))
                && ((filter[iloop].mApiId == detInfo->mApiId) || (filter[iloop].mApiId == DET_DONTCARE_8))
                && ((filter[iloop].mErrorId == detInfo->mErrorId) || (filter[iloop].mErrorId == DET_DONTCARE_8)))
            {
                retval = (boolean)TRUE;
                break;
            }
        }
    }
    else
    {
        retval = (boolean)TRUE;
    }
#else
    (void)filter;
    (void)size;
    (void)active;
    (void)detInfo;
#endif /* STD_ON == DET_CHECK_FILTER_MATCH_ENABLE */
    return retval;
}

/******************************************************************************/
/*
 * Brief               Store a DET error in the log buffer
 * details             It is further detected if an overrun occurs and if a forced break handler call is required.
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      active:flag to indicate if logging is active
                       detInfo: pointer to structure holding DET error for filtering
 * Param-Name[out]     None:
 * Param-Name[in/out]  None:
 * Return              boolean: FALSE: do not force break handler call, TRUE: force break handler call
 */
/******************************************************************************/
static FUNC(boolean, DET_CODE)
    Det_LogError(VAR(boolean, AUTOMATIC) active, P2CONST(DetInfoType, AUTOMATIC, DET_VAR) detInfo)
{
    /* do not force break handler call */
    VAR(boolean, AUTOMATIC) forceBreakHandler = (boolean)FALSE;
    /* if logging is active */
    if ((boolean)TRUE == active)
    {
        detStatus.logIndex++;
        /* if overrun of circular buffer occurs */
        if (detStatus.logIndex >= (uint8)DET_SIZE_OF_LOG_BUFFER)
        {
            detStatus.logIndex = 0U;
            /* if break on overrun is active set return value to force break handler call */
            if ((boolean)TRUE == detStatus.breakOnLogOverrun)
            {
                forceBreakHandler = (boolean)TRUE;
            }
        }
        /* store DET error in log buffer */
        detLogBuffer[detStatus.logIndex].mModuleId = detInfo->mModuleId;
        detLogBuffer[detStatus.logIndex].mInstanceId = detInfo->mInstanceId;
        detLogBuffer[detStatus.logIndex].mApiId = detInfo->mApiId;
        detLogBuffer[detStatus.logIndex].mErrorId = detInfo->mErrorId;
    }
    return forceBreakHandler;
}

#endif /* STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT */

/******************************************************************************/
/*
 * Brief               Enter endless loop
 * details             Used to stop further processing.
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None:
 * Param-Name[out]     None:
 * Param-Name[in/out]  None:
 * Return              None:
 */
/******************************************************************************/
static FUNC(void, DET_CODE) Det_EndlessLoop(void)
{
    /* set this variable to 0 to unlock breakpoint */
    while (detStatus.unlockBreak == (boolean)FALSE)
    {
#if (STD_ON == DET_FORWARD_TO_DLT)
        if ((boolean)TRUE == Det_GetGptFlag_1ms())
        {
            CanTp_MainFunction();
            TcpIp_MainFunction();
            SoAd_MainFunction();
            Dlt_TxFunction();
        }
#endif /* STD_ON == DET_FORWARD_TO_DLT */
    }
    detStatus.unlockBreak = (boolean)FALSE;
}

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define DET_START_SEC_CODE
#include "Det_MemMap.h"
/******************************************************************************/
/*
 * Brief               Initializes the DET
 * details             Global function as an interface from EcuM to DET for initialization.
 * note                Shall be called during startup by EcuM in a safe context.
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr: Pointer to the selected configuration set.
 * Param-Name[out]     None:
 * Param-Name[in/out]  None:
 * Return              None:
 */
/******************************************************************************/
FUNC(void, DET_CODE) Det_Init(P2CONST(Det_ConfigType, AUTOMATIC, DET_APPL_CONST) ConfigPtr)
{
    (void)ConfigPtr;
    VAR(uint32, AUTOMATIC) iloop;
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
#if (DET_SIZE_OF_ERROR_HOOK_TABLE > 0)
    for (iloop = 0; iloop < DET_SIZE_OF_ERROR_HOOK_TABLE; iloop++)
    {
        Det_CallbackList[iloop] = NULL_PTR;
    }
#if (DET_MAX_RAMLOG_SIZE > 0)
    for (iloop = 0; iloop < DET_MAX_RAMLOG_SIZE; iloop++)
    {
        Det_RamLog[iloop].moduleId = 0;
        Det_RamLog[iloop].instanceId = 0;
        Det_RamLog[iloop].apiId = 0;
        Det_RamLog[iloop].errorId = 0;
    }
    Det_RamlogIndex = 0;
#endif /* DET_MAX_RAMLOG_SIZE > 0 */
#endif /* DET_SIZE_OF_ERROR_HOOK_TABLE > 0 */
#if (DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE > 0)
    for (iloop = 0; iloop < DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE; iloop++)
    {
        Det_RunTimeCallbackList[iloop] = NULL_PTR;
    }
#if (DET_RUNTIME_MAX_RAMLOG_SIZE > 0)
    for (iloop = 0; iloop < DET_RUNTIME_MAX_RAMLOG_SIZE; iloop++)
    {
        Det_RunTimeRamLog[iloop].moduleId = 0;
        Det_RunTimeRamLog[iloop].instanceId = 0;
        Det_RunTimeRamLog[iloop].apiId = 0;
        Det_RunTimeRamLog[iloop].errorId = 0;
    }
    Det_RunTimeRamlogIndex = 0;
#endif /* DET_RUNTIME_MAX_RAMLOG_SIZE > 0 */
#endif /* DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE > 0 */
#if (DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE > 0)
    for (iloop = 0; iloop < DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE; iloop++)
    {
        Det_TransientCallbackList[iloop] = NULL_PTR;
    }
#if (DET_TRANSIENT_MAX_RAMLOG_SIZE > 0)
    for (iloop = 0; iloop < DET_TRANSIENT_MAX_RAMLOG_SIZE; iloop++)
    {
        Det_TransientRamLog[iloop].moduleId = 0;
        Det_TransientRamLog[iloop].instanceId = 0;
        Det_TransientRamLog[iloop].apiId = 0;
        Det_TransientRamLog[iloop].errorId = 0;
    }
    Det_TransientRamlogIndex = 0;
#endif /* DET_TRANSIENT_MAX_RAMLOG_SIZE > 0 */
#endif /* DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE > 0 */
#if (DET_SIZE_OF_GLOBAL_FILTER > 0)
    for (iloop = 0U; iloop < (uint32)DET_SIZE_OF_GLOBAL_FILTER; iloop++)
    {
        detGlobalFilter[iloop].mModuleId = 0U;
        detGlobalFilter[iloop].mInstanceId = 0U;
        detGlobalFilter[iloop].mApiId = 0U;
        detGlobalFilter[iloop].mErrorId = 0U;
    }
#endif /* DET_GLOBALFILTERSIZE > 0 */
#if (DET_SIZE_OF_BREAK_FILTER > 0)
    for (iloop = 0U; iloop < (uint32)DET_SIZE_OF_BREAK_FILTER; iloop++)
    {
        detBreakFilter[iloop].mModuleId = 0U;
        detBreakFilter[iloop].mInstanceId = 0U;
        detBreakFilter[iloop].mApiId = 0U;
        detBreakFilter[iloop].mErrorId = 0U;
    }
#endif /* DET_BREAKFILTERSIZE > 0 */
#if (DET_SIZE_OF_DLT_FILTER > 0)
    for (iloop = 0U; iloop < (uint32)DET_SIZE_OF_DLT_FILTER; iloop++)
    {
        detDltFilter[iloop].mModuleId = 0U;
        detDltFilter[iloop].mInstanceId = 0U;
        detDltFilter[iloop].mApiId = 0U;
        detDltFilter[iloop].mErrorId = 0U;
    }
#endif /* DET_DLTFILTERSIZE > 0 */
#if (DET_SIZE_OF_LOG_BUFFER > 0)
    for (iloop = 0U; iloop < (uint32)DET_SIZE_OF_LOG_BUFFER; iloop++)
    {
        detLogBuffer[iloop].mModuleId = 0U;
        detLogBuffer[iloop].mInstanceId = 0U;
        detLogBuffer[iloop].mApiId = 0U;
        detLogBuffer[iloop].mErrorId = 0U;
    }
#endif /* DET_LOGBUFFERSIZE > 0 */
#endif /* STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT */
    detStatus.globalFilterActive = (boolean)FALSE;
    detStatus.logActive = (boolean)FALSE;
    detStatus.logIndex = 0U;
    detStatus.breakOnLogOverrun = (boolean)FALSE;
    detStatus.breakFilterActive = (boolean)FALSE;
    detStatus.unlockBreak = (boolean)FALSE;
    /* reset recursion limit counter */
    detRecursionCounterReportError = 0U;
    /* reset recursion limit counter */
    detRecursionCounterReportRuntimeError = 0U;
    /* reset recursion limit counter */
    detRecursionCounterReportTransientFault = 0U;
    detModuleInit = (boolean)TRUE;
    Det_ErrorCodeId = 0x00;
    Det_FaultCodeId = 0x00;
    Det_RunState = DET_INITIALIZED;
}

void Det_DeInit(void)
{
    Det_RunState = DET_UNINITIALIZED;
}

/******************************************************************************/
/*
 * Brief               Starts the DET
 * details             Global function as an interface from EcuM to DET for start
 * note                This API has no functionality in this DET implementation. Therefore its call is optional.
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None:
 * Param-Name[out]     None:
 * Param-Name[in/out]  None:
 * Return              None:
 */
/******************************************************************************/
FUNC(void, DET_CODE) Det_Start(void)
{
    Det_RunState = DET_STARTED;
}

/******************************************************************************/
/*
 * Brief               Initializes the DET
 * details             Global function as an interface from EcuM to DET for initialization
 * note                Shall be called during startup by EcuM in a safe context.
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None:
 * Param-Name[out]     None:
 * Param-Name[in/out]  None:
 * Return              None:
 */
/******************************************************************************/
FUNC(void, DET_CODE) Det_InitMemory(void)
{
    detModuleInit = (boolean)FALSE;
}

/******************************************************************************/
/*
 * Brief               Development error reporting function
 * details             Global function for BSW-Modules to report errors to the DET
 * note                If filtering is active the default settings of the filter discard error reports of ModuleId 0
 (zero).
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ModuleId: Module ID of calling module
                       InstanceId: The identifier of the index based instance of a module
                       ApiId: ID of API service in which error is detected
                       ErrorId: ID of detected development error
 * Param-Name[out]     None:
 * Param-Name[in/out]  None:
 * Return              Std_ReturnType: E_OK (always)
 */
/******************************************************************************/
FUNC(Std_ReturnType, DET_CODE)
Det_ReportError(
    VAR(uint16, AUTOMATIC) ModuleId,
    VAR(uint8, AUTOMATIC) InstanceId,
    VAR(uint8, AUTOMATIC) ApiId,
    VAR(uint8, AUTOMATIC) ErrorId)
{
    VAR(uint32, AUTOMATIC) iloop;
    VAR(Std_ReturnType, AUTOMATIC) calloutReturn = (Std_ReturnType)E_OK;
    VAR(boolean, AUTOMATIC) forceBreakHandler;
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
    VAR(DetInfoType, AUTOMATIC) detInfo;
    detInfo.mModuleId = ModuleId;
    detInfo.mInstanceId = InstanceId;
    detInfo.mApiId = ApiId;
    detInfo.mErrorId = ErrorId;
#endif /* STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT */
    Det_ErrorCodeId = ErrorId;
    detStatus.unlockBreak = (boolean)FALSE;
    forceBreakHandler = (boolean)FALSE;
    /* if DET is initialized: in case of call to uninitialized DET return */
    if ((boolean)TRUE == detModuleInit)
    {
        /* increment nesting counter for recursion detection */
        detRecursionCounterReportError++;
        if (detRecursionCounterReportError > DET_REPORT_ERROR_RECURSIONLIMIT)
        {
            Det_EndlessLoop();
        }
        else
        {
            /* call error hooks (if configured) */
#if ((STD_ON == DET_ERROR_HOOK_ENABLED) && (DET_SIZE_OF_ERROR_HOOK_TABLE > 0))
            for (iloop = 0; iloop < DET_SIZE_OF_ERROR_HOOK_TABLE; iloop++)
            {
                if (NULL_PTR != Det_GetErrorHookTable[iloop])
                {
                    calloutReturn = Det_GetErrorHookTable[iloop](ModuleId, InstanceId, ApiId, ErrorId);
                }
            }
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
            /* No action is taken if the module is not started */
            if (DET_STARTED == Det_RunState)
            {
                for (iloop = 0; iloop < DET_SIZE_OF_ERROR_HOOK_TABLE; iloop++)
                {
                    if (NULL_PTR != Det_CallbackList[iloop])
                    {
                        (*Det_CallbackList[iloop])(ModuleId, InstanceId, ApiId, ErrorId);
                    }
                }
#if (DET_MAX_RAMLOG_SIZE > 0)
                if (Det_RamlogIndex < DET_MAX_RAMLOG_SIZE)
                {
                    Det_RamLog[Det_RamlogIndex].moduleId = ModuleId;
                    Det_RamLog[Det_RamlogIndex].instanceId = InstanceId;
                    Det_RamLog[Det_RamlogIndex].apiId = ApiId;
                    Det_RamLog[Det_RamlogIndex].errorId = ErrorId;
                    Det_RamlogIndex++;
                    if (Det_RamlogIndex == DET_MAX_RAMLOG_SIZE)
                    {
                        Det_RamlogIndex = 0;
                    }
                }
#endif /* DET_MAX_RAMLOG_SIZE > 0 */
            }
#endif /* STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT */
#endif /* STD_ON == DET_ERROR_HOOK_ENABLED */

#if (STD_ON == DET_FORWARD_TO_DLT)
            /* forward DET error to DLT module (if configured) unless filtered out by a DLT filter */
#if ((DET_DLTFILTERSIZE > 0) && (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT))
            if ((boolean)FALSE
                == Det_CheckFilterMatch(detDltFilter, (uint8)DET_DLTFILTERSIZE, detStatus.dltFilterActive, &detInfo))
#endif /* (DET_DLTFILTERSIZE > 0) && (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT) */
            {
                Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
            }
#endif /* STD_ON == DET_FORWARD_TO_DLT */
            /* if last error hook (if configured) returned E_OK: */
            if ((Std_ReturnType)E_OK == calloutReturn)
            {
                /* check for global filter match (if configured), in case of no match continue */
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
                if ((boolean)FALSE
                    == Det_CheckFilterMatch(
                        detGlobalFilter,
                        (uint8)DET_SIZE_OF_GLOBAL_FILTER,
                        detStatus.globalFilterActive,
                        &detInfo))
#endif /* (DET_GLOBALFILTERSIZE > 0) && (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT) */
                {
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
                    /* store DET error in log buffer (if configured) */
                    forceBreakHandler = Det_LogError(detStatus.logActive, &detInfo);
#endif              /* (DET_LOGBUFFERSIZE > 0) && (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT) */
                    /* check for break filter match or forced break handler call (if configured), in case of no match
                     * continue */
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
                    if ((Det_CheckFilterMatch(
                             detBreakFilter,
                             DET_SIZE_OF_BREAK_FILTER,
                             detStatus.breakFilterActive,
                             &detInfo)
                         == (boolean)FALSE)
                        || (forceBreakHandler == (boolean)TRUE))
#endif /* (DET_LOGBUFFERSIZE > 0) && (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT) */
                    {
                        /* enter endless loop - in variant with debug support loop can be left by setting a flag */
                        Det_EndlessLoop();
                    }
                }
            }
        }
        /* decrement nesting counter for recursion detection */
        detRecursionCounterReportError--;
    }
    return (Std_ReturnType)E_OK;
}

/******************************************************************************/
/*
 * Brief               Runtime error reporting function
 * details             Global function for BSW-Modules to report errors to the DET
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ModuleId: Module ID of calling module
                       InstanceId: The identifier of the index based instance of a module
                       ApiId: ID of API service in which error is detected
                       ErrorId: ID of detected development error
 * Param-Name[out]     None:
 * Param-Name[in/out]  None:
 * Return              Std_ReturnType: E_OK (always)
 */
/******************************************************************************/
FUNC(Std_ReturnType, DET_CODE)
Det_ReportRuntimeError(
    VAR(uint16, AUTOMATIC) ModuleId,
    VAR(uint8, AUTOMATIC) InstanceId,
    VAR(uint8, AUTOMATIC) ApiId,
    VAR(uint8, AUTOMATIC) ErrorId)
{
    VAR(uint32, AUTOMATIC) iloop;
    VAR(Std_ReturnType, AUTOMATIC) calloutReturn = E_OK;
    VAR(DetInfoType, AUTOMATIC) detInfo;
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
    detInfo.mModuleId = ModuleId;
    detInfo.mInstanceId = InstanceId;
    detInfo.mApiId = ApiId;
    detInfo.mErrorId = ErrorId;
#endif /* STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT */
    Det_ErrorCodeId = ErrorId;
    detStatus.unlockBreak = (boolean)TRUE;
    /* if DET is initialized: in case of call to uninitialized DET return */
    if ((boolean)TRUE == detModuleInit)
    {
        /* increment nesting counter for recursion detection */
        detRecursionCounterReportRuntimeError++;
        if (detRecursionCounterReportRuntimeError > DET_REPORT_RUNTIMEERROR_RECURSIONLIMIT)
        {
            Det_EndlessLoop();
        }
        else
        {
            /* call runtime error callouts (if configured) */
#if ((STD_ON == DET_RUNTIME_ERROR_CALLOUT_ENABLED) && (DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE > 0))
            for (iloop = 0; iloop < DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE; iloop++)
            {
                if (Det_GetRuntimeErrorCalloutTable[iloop] != NULL_PTR)
                {
                    calloutReturn = Det_GetRuntimeErrorCalloutTable[iloop](ModuleId, InstanceId, ApiId, ErrorId);
                }
            }
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
            /* No action is taken if the module is not started */
            if (DET_STARTED == Det_RunState)
            {
                for (iloop = 0; iloop < DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE; iloop++)
                {
                    if (NULL_PTR != Det_RunTimeCallbackList[iloop])
                    {
                        (*Det_RunTimeCallbackList[iloop])(ModuleId, InstanceId, ApiId, ErrorId);
                    }
                }
#if (DET_RUNTIME_MAX_RAMLOG_SIZE > 0)
                if (Det_RunTimeRamlogIndex < DET_RUNTIME_MAX_RAMLOG_SIZE)
                {
                    Det_RunTimeRamLog[Det_RunTimeRamlogIndex].moduleId = ModuleId;
                    Det_RunTimeRamLog[Det_RunTimeRamlogIndex].instanceId = InstanceId;
                    Det_RunTimeRamLog[Det_RunTimeRamlogIndex].apiId = ApiId;
                    Det_RunTimeRamLog[Det_RunTimeRamlogIndex].errorId = ErrorId;
                    Det_RunTimeRamlogIndex++;
                    if (Det_RunTimeRamlogIndex == DET_RUNTIME_MAX_RAMLOG_SIZE)
                    {
                        Det_RunTimeRamlogIndex = 0;
                    }
                }
#endif /* DET_RUNTIME_MAX_RAMLOG_SIZE > 0 */
            }
#endif /* STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT */
#endif /* STD_ON == DET_RUNTIME_ERROR_CALLOUT_ENABLED */

#if (STD_ON == DET_FORWARD_TO_DLT)
            /* forward DET error to DLT module (if configured) unless filtered out by a DLT filter */
#if ((DET_DLTFILTERSIZE > 0) && (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT))
            if (Det_CheckFilterMatch(detDltFilter, DET_DLTFILTERSIZE, detStatus.dltFilterActive, &detInfo)
                == (boolean)FALSE)
#endif /* (DET_DLTFILTERSIZE > 0) && (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT) */
            {
                Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, ErrorId);
            }
#endif /* STD_ON == DET_FORWARD_TO_DLT */
            /* if last runtime error callout (if configured) returned E_OK: */
            if ((Std_ReturnType)E_OK == calloutReturn)
            {
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
                /* store DET error in log buffer (if configured) */
                (void)Det_LogError(detStatus.logActive, &detInfo);
#endif /* (DET_LOGBUFFERSIZE > 0) && (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT) */
            }
        }
        /* decrement nesting counter for recursion detection */
        detRecursionCounterReportRuntimeError--;
    }
    return (Std_ReturnType)E_OK;
}

/******************************************************************************/
/*
 * Brief               Transient fault reporting function
 * details             Global function for BSW-Modules to report errors to the DET
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ModuleId: Module ID of calling module
                       InstanceId: The identifier of the index based instance of a module
                       ApiId: ID of API service in which error is detected
                       ErrorId: ID of detected development error
 * Param-Name[out]     None:
 * Param-Name[in/out]  None:
 * Return              Std_ReturnType: E_OK (always) if no callouts are configured - return value of last callout if
 callouts are configured
 */
/******************************************************************************/
FUNC(Std_ReturnType, DET_CODE)
Det_ReportTransientFault(
    VAR(uint16, AUTOMATIC) ModuleId,
    VAR(uint8, AUTOMATIC) InstanceId,
    VAR(uint8, AUTOMATIC) ApiId,
    VAR(uint8, AUTOMATIC) FaultId)
{
    VAR(uint32, AUTOMATIC) iloop;
    VAR(Std_ReturnType, AUTOMATIC) calloutReturn = (Std_ReturnType)E_OK;
    VAR(DetInfoType, AUTOMATIC) detInfo;
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
    detInfo.mModuleId = ModuleId;
    detInfo.mInstanceId = InstanceId;
    detInfo.mApiId = ApiId;
    detInfo.mErrorId = FaultId;
#endif /* STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT */
    Det_FaultCodeId = FaultId;
    detStatus.unlockBreak = (boolean)TRUE;
    /* if DET is initialized: in case of call to uninitialized DET return */
    if ((boolean)TRUE == detModuleInit)
    {
        /* increment nesting counter for recursion detection */
        detRecursionCounterReportTransientFault++;
        if (detRecursionCounterReportTransientFault > DET_REPORT_TRANSIENTFAULT_RECURSIONLIMIT)
        {
            Det_EndlessLoop();
        }
        else
        {
            /* call transient fault callouts (if configured) */
#if ((STD_ON == DET_TRANSIENT_FAULT_CALLOUT_ENABLED) && (DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE > 0))
            for (iloop = 0; iloop < DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE; iloop++)
            {
                if (Det_GetTransientFaultCalloutTable[iloop] != NULL_PTR)
                {
                    calloutReturn = Det_GetTransientFaultCalloutTable[iloop](ModuleId, InstanceId, ApiId, FaultId);
                }
            }
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
            /* No action is taken if the module is not started */
            if (Det_RunState == DET_STARTED)
            {
                for (iloop = 0; iloop < DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE; iloop++)
                {
                    if (NULL_PTR != Det_TransientCallbackList[iloop])
                    {
                        (*Det_TransientCallbackList[iloop])(ModuleId, InstanceId, ApiId, FaultId);
                    }
                }
#if (DET_TRANSIENT_MAX_RAMLOG_SIZE > 0)
                if (Det_TransientRamlogIndex < DET_TRANSIENT_MAX_RAMLOG_SIZE)
                {
                    Det_TransientRamLog[Det_TransientRamlogIndex].moduleId = ModuleId;
                    Det_TransientRamLog[Det_TransientRamlogIndex].instanceId = InstanceId;
                    Det_TransientRamLog[Det_TransientRamlogIndex].apiId = ApiId;
                    Det_TransientRamLog[Det_TransientRamlogIndex].errorId = FaultId;
                    Det_TransientRamlogIndex++;
                    if (Det_TransientRamlogIndex == DET_TRANSIENT_MAX_RAMLOG_SIZE)
                    {
                        Det_TransientRamlogIndex = 0;
                    }
                }
#endif /* DET_TRANSIENT_MAX_RAMLOG_SIZE > 0 */
            }
#endif /* STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT*/
#endif /* STD_ON == DET_TRANSIENT_FAULT_CALLOUT_ENABLED */

#if (DET_FORWARD_TO_DLT == STD_ON)
            /* forward DET error to DLT module (if configured) unless filtered out by a DLT filter */
#if ((DET_DLTFILTERSIZE > 0) && (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT))
            if (Det_CheckFilterMatch(detDltFilter, DET_DLTFILTERSIZE, detStatus.dltFilterActive, &detInfo)
                == (boolean)FALSE)
#endif /* (DET_DLTFILTERSIZE > 0) && (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT) */
            {
                Dlt_DetForwardErrorTrace(ModuleId, InstanceId, ApiId, FaultId);
            }
#endif /* STD_ON == DET_FORWARD_TO_DLT */
            if ((Std_ReturnType)E_OK == calloutReturn)
            {
#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)
                /* store DET error in log buffer (if configured) */
                (void)Det_LogError(detStatus.logActive, &detInfo);
#endif /* (DET_LOGBUFFERSIZE > 0) && (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT) */
            }
        }
        /* decrement nesting counter for recursion detection */
        detRecursionCounterReportTransientFault--;
    }
    return (Std_ReturnType)E_OK;
}

#if (STD_ON == DET_VERSION_INFO_API)
/******************************************************************************/
/*
 * Brief               Read the DET version information
 * details             Global function for BSW-Modules to get the Version of DET
 * config              DET_VERSION_INFO_API
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None:
 * Param-Name[out]     versioninfo: Version information of the DET
 * Param-Name[in/out]  None:
 * Return              None:
 */
/******************************************************************************/
FUNC(void, DET_CODE) Det_GetVersionInfo(P2VAR(Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA) versioninfo)
{
    /* if versioninfo is no NULL pointer */
    if (NULL_PTR != versioninfo)
    {
        /* fill versions from defines into versioninfo structure */
        versioninfo->vendorID = DET_VENDOR_ID;
        versioninfo->moduleID = DET_MODULE_ID;
        versioninfo->sw_major_version = DET_SW_MAJOR_VERSION;
        versioninfo->sw_minor_version = DET_SW_MINOR_VERSION;
        versioninfo->sw_patch_version = DET_SW_PATCH_VERSION;
    }
    else
    {
        (void)Det_ReportError(
            (uint16)DET_MODULE_ID,
            (uint8)DET_INSTANCE_ID,
            (uint8)DET_SID_GETVERSIONINFO,
            (uint8)DET_E_PARAM_POINTER);
    }
}
#endif

#if (STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT)

#if (DET_SIZE_OF_ERROR_HOOK_TABLE > 0)
/* Add a callback function to the array of callback. After a call to Det_ReportError the callback is called.
 * This can be used in for instance unit tests to verify that correct errors are reported when sending invalid
 * parameters to a function. This function returns the index of the callback in the array when registration is
 * successful. If not DET_CBK_REGISTRATION_FAILED_INDEX is returned. The index can be used to remove a callback with the
 * Det_RemoveCbk.*/
FUNC(uint8, DET_CODE) Det_AddCallback(Det_CallbackFncType detCbk)
{
    uint8 iloop;
    uint8 retVal = DET_CBK_REGISTRATION_FAILED_INDEX;
    if (DET_UNINITIALIZED != Det_RunState)
    {
        for (iloop = 0; iloop < DET_SIZE_OF_ERROR_HOOK_TABLE; iloop++)
        {
            if (NULL_PTR == Det_CallbackList[iloop])
            {
                Det_CallbackList[iloop] = detCbk;
                retVal = iloop;
                break;
            }
        }
    }
    if (DET_CBK_REGISTRATION_FAILED_INDEX == retVal)
    {
        Det_ReportError(DET_MODULE_ID, 0, DET_CALLBACK_API, DET_E_CBK_REGISTRATION_FAILED);
    }
    return retVal;
}

FUNC(void, DET_CODE) Det_RemoveCallback(uint8 detCbkIndex)
{
    if (detCbkIndex >= DET_SIZE_OF_ERROR_HOOK_TABLE)
    {
        Det_ReportError(DET_MODULE_ID, 0, DET_CALLBACK_API, DET_E_INDEX_OUT_OF_RANGE);
    }
    else
    {
        Det_CallbackList[detCbkIndex] = NULL_PTR;
    }
}
#endif /* DET_SIZE_OF_ERROR_HOOK_TABLE > 0 */

#if (DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE > 0)
/* Add a callback function to the array of callback. After a call to Det_ReportRunTimeError the callback is called.
 * This can be used in for instance unit tests to verify that correct errors are reported when sending invalid
 * parameters to a function. This function returns the index of the callback in the array when registration is
 * successful. If not DET_CBK_REGISTRATION_FAILED_INDEX is returned. The index can be used to remove a callback with the
 * Det_RemoveRunTimeCbk.*/
FUNC(uint8, DET_CODE) Det_AddRunTimeCallback(Det_CallbackFncType detCbk)
{
    uint8 iloop;
    uint8 retVal = DET_CBK_REGISTRATION_FAILED_INDEX;
    if (Det_RunState != DET_UNINITIALIZED)
    {
        for (iloop = 0; iloop < DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE; iloop++)
        {
            if (NULL_PTR == Det_RunTimeCallbackList[iloop])
            {
                Det_RunTimeCallbackList[iloop] = detCbk;
                retVal = iloop;
                break;
            }
        }
    }
    if (retVal == DET_CBK_REGISTRATION_FAILED_INDEX)
    {
        Det_ReportError(DET_MODULE_ID, 0, DET_CALLBACK_API, DET_E_CBK_REGISTRATION_FAILED);
    }
    return retVal;
}

FUNC(void, DET_CODE) Det_RemoveRunTimeCallback(uint8 detCbkIndex)
{
    if (detCbkIndex >= DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE)
    {
        Det_ReportError(DET_MODULE_ID, 0, DET_CALLBACK_API, DET_E_INDEX_OUT_OF_RANGE);
    }
    else
    {
        Det_RunTimeCallbackList[detCbkIndex] = NULL_PTR;
    }
}
#endif /* DET_SIZE_OF_RUNTIME_ERROR_CALLOUT_TABLE > 0 */

#if (DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE > 0)
/* Add a callback function to the array of callback. After a call to Det_ReportTransientFault the callback is called.
 * This can be used in for instance unit tests to verify that correct errors are reported when sending invalid
 * parameters to a function. This function returns the index of the callback in the array when registration is
 * successful. If not DET_CBK_REGISTRATION_FAILED_INDEX is returned. The index can be used to remove a callback with the
 * Det_RemoveTransientCbk.*/
FUNC(uint8, DET_CODE) Det_AddTransientCallback(Det_CallbackFncType detCbk)
{
    uint8 iloop;
    uint8 retVal = DET_CBK_REGISTRATION_FAILED_INDEX;
    if (Det_RunState != DET_UNINITIALIZED)
    {
        for (iloop = 0; iloop < DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE; iloop++)
        {
            if (NULL_PTR == Det_TransientCallbackList[iloop])
            {
                Det_TransientCallbackList[iloop] = detCbk;
                retVal = iloop;
                break;
            }
        }
    }
    if (retVal == DET_CBK_REGISTRATION_FAILED_INDEX)
    {
        Det_ReportError(DET_MODULE_ID, 0, DET_CALLBACK_API, DET_E_CBK_REGISTRATION_FAILED);
    }
    return retVal;
}

FUNC(void, DET_CODE) Det_RemoveTransientCallback(uint8 detCbkIndex)
{
    if (detCbkIndex >= DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE)
    {
        Det_ReportError(DET_MODULE_ID, 0, DET_CALLBACK_API, DET_E_INDEX_OUT_OF_RANGE);
    }
    else
    {
        Det_TransientCallbackList[detCbkIndex] = NULL_PTR;
    }
}
#endif /* DET_SIZE_OF_TRANSIENT_FAULT_CALLOUT_TABLE > 0 */

#endif /* STD_ON == DET_USE_EXTENDED_DEBUG_SUPPORT */

#define DET_STOP_SEC_CODE
#include "Det_MemMap.h"
