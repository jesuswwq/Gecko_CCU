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
**  FILENAME    : Dem.c                                                       **
**                                                                            **
**  Created on  :                                                             **
**  Author      : tao.yu                                                      **
**  Vendor      : i-soft                                                      **
**  DESCRIPTION : Implementation for DEM                                      **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:Dem<br>
  RuleSorce:puhua-rule.rcf 2.3.1

    \li PRQA S 3432 MISRA Rule 20.7 .<br>
    Reason:Function-like macros are used to allow more efficient code.

    \li PRQA S 0777 MISRA Rule 5.1 .<br>
    Reason:function name, design needs, namelength set to 63 in C99.

    \li PRQA S 0779 MISRA Rule 5.2 .<br>
    Reason:parameter name, design needs, namelength set to 63 in C99.

    \li PRQA S 0791 MISRA Rule 5.2 .<br>
    Reason:Memmap section, design needs, namelength set to 63 in C99.

    \li PRQA S 1532 MISRA Rule 8.7 .<br>
    Reason:Functions may be used in other projects.

    \li PRQA S 1505 MISRA Rule 8.7 .<br>
    Reason:Functions may be used in other projects.

    \li PRQA S 2985 MISRA Rule 2.2 .<br>
    Reason:StatusMaskType is not necessarily u8 for every project.

    \li PRQA S 2983 MISRA Rule 2.2 .<br>
    Reason:for loop condition is a macro definition, which varies in different projs.

    \li PRQA S 3415 MISRA Rule 13.5 .<br>
    Reason:function in && comparison does not need to be called when the first condition fails.

    \li PRQA S 2877 MISRA Dir 4.1 .<br>
    Reason:for loop condition is a macro definition, which varies in different projs.

    \li PRQA S 2812 MISRA Dir 4.1 .<br>
    Reason:Configuration Parameter varies in different projs.

    \li PRQA S 2995 MISRA Rule 2.2 .<br>
    Reason:If statement may be optimized, but kept for better Readability.

    \li PRQA S 2996 MISRA Rule 2.2 .<br>
    Reason:If statement may be optimized, but kept for better Readability.

    \li PRQA S 4394 MISRA Rule 10.8 .<br>
    Reason:Data conversion to a different range is necessary for design purpose.

    \li PRQA S 2003 MISRA Rule 16.3 .<br>
    Reason:Switch case is designed to skip over for design purpose.

    \li PRQA S 2981 MISRA Rule 2.2 .<br>
    Reason:Init may be necessary for different macro definition.

    \li PRQA S 2982 MISRA Rule 2.2 .<br>
    Reason:for loop condition is a macro definition, which varies in different projs.

    \li PRQA S 2741 MISRA Rule 14.3 .<br>
    Reason:Macro definition varies in different projs.

    \li PRQA S 2742 MISRA Rule 14.3 .<br>
    Reason:Macro definition varies in different projs.

    \li PRQA S 2755 MISRA CMN 0.4 .<br>
    Reason:Functions name is by design purpose.

    \li PRQA S 1330 MISRA Rule 8.3 .<br>
    Reason:Different configurations produce variations
 */

/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
#include "Dem.h"
#include "Dem_Dcm.h"
#include "Dem_Internal.h"
// #include "SchM_Dem.h"
#if (DEM_NVRAM_BLOCKID_NUM > 0)
#include "NvM.h"
#endif
#if (STD_ON == DEM_TRIGGER_FIM_REPORTS)
#include "FiM.h"
#endif
#if (STD_ON == DEM_J1939_SUPPORT)
#include "J1939Dcm_Types.h"
#endif

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#ifndef DEM_AR_RELEASE_MAJOR_VERSION
#error " Dem version miss"
#endif
#ifndef DEM_AR_RELEASE_MINOR_VERSION
#error " Dem version miss"
#endif
#ifndef DEM_AR_RELEASE_PATCH_VERSION
#error " Dem version miss"
#endif

/*******************************************************************************
**                      Global Variable Definitions                           **
*******************************************************************************/
#define DEM_START_SEC_VAR_INIT_PTR
#include "Dem_MemMap.h"
P2CONST(Dem_ConfigType, AUTOMATIC, DEM_CONST_PBCFG) DemPbCfgPtr = NULL_PTR;
#define DEM_STOP_SEC_VAR_INIT_PTR
#include "Dem_MemMap.h"

/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define DEM_START_SEC_VAR_INIT_8
#include "Dem_MemMap.h"
VAR(Dem_StateType, AUTOMATIC) DemInitState = DEM_STATE_UNINIT;
#define DEM_STOP_SEC_VAR_INIT_8
#include "Dem_MemMap.h"

/* OperationCycleStatus */
#define DEM_START_SEC_VAR_NO_INIT_8
#include "Dem_MemMap.h"
VAR(uint8, AUTOMATIC) DemOperationCycleStatus[DEM_OPERATION_CYCLE_NUM_BYTE];
#define DEM_STOP_SEC_VAR_NO_INIT_8
#include "Dem_MemMap.h"

#if (DEM_ENABLE_CONDITION_NUM > 0)
/* Enable Conditions Status Define */
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(uint8, AUTOMATIC) DemEnableConditionStatus[DEM_ENABLE_CONDITION_NUM_BYTE];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_INIT_8
#include "Dem_MemMap.h"
static VAR(boolean, AUTOMATIC) DemCheckEnableCondition = FALSE;
#define DEM_STOP_SEC_VAR_INIT_8
#include "Dem_MemMap.h"
#endif

#if (DEM_STORAGE_CONDITION_NUM > 0)
/* Storage Conditions Status Define */
#define DEM_START_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"
VAR(uint8, AUTOMATIC) DemStorageConditionStatus[DEM_STORAGE_CONDITION_NUM_BYTE];
#define DEM_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#include "Dem_MemMap.h"

#define DEM_START_SEC_VAR_INIT_8
#include "Dem_MemMap.h"
static VAR(boolean, AUTOMATIC) DemCheckStorageCondition = FALSE;
#define DEM_STOP_SEC_VAR_INIT_8
#include "Dem_MemMap.h"
#endif

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#if (DEM_ENABLE_CONDITION_NUM > 0)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_SetEnableCondictionProcess(void);
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

#if (DEM_STORAGE_CONDITION_NUM > 0)
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_SetStorageCondictionProcess(void);
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_EventStatusPrepassedDebounce(
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_EventStatusPrefailedDebounce(
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_ProcessEventStatus(
    Dem_EventStatusType EventStatus,
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               Initializes the internal states necessary to process events reported by BSW-modules.
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_PreInit(void)
{
    uint16 iloop;
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent = DemEventRelateInformation;
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    /* OperationCycleStatus */
    Dem_MemSet(DemOperationCycleStatus, 0x00u, DEM_OPERATION_CYCLE_NUM_BYTE);
#if (DEM_ENABLE_CONDITION_NUM > 0)
    /* Init Enable Conditions */
    Dem_MemCopy(DemEnableConditionStatus, DemEnableCondition, DEM_ENABLE_CONDITION_NUM_BYTE);
#endif
#if (DEM_STORAGE_CONDITION_NUM > 0)
    /* Init Storage Conditions */
    Dem_MemSet(DemStorageConditionStatus, 0x00u, DEM_STORAGE_CONDITION_NUM_BYTE);
    iloop = 0;
    while (iloop < DEM_STORAGE_CONDITION_NUM) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
    {
        if (DemStorageCondition[iloop].DemStorageConditionStatus == TRUE)
        {
            DEM_BITS_SET(DemStorageConditionStatus, iloop);
        }
        iloop++;
    }
#endif
    /* SWS_Dem_00180 */
    iloop = 0u;
    while (iloop < DEM_EVENT_PARAMETER_NUM)
    {
        Dem_MemSet((uint8*)pEvent, 0x00u, sizeof(Dem_EventRelateInformationType));
        pEvent++;
        iloop++;
    }
    /*SWS_Dem_00167*/
    Dem_EventQueueInit();
    /*SWS_Dem_00180*/ /*SWS_Dem_00438*/
    Dem_DebounceInit();
#if ((DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT) || (DEM_J1939_SUPPORT == STD_ON))
#if (DEM_RATIO_NUM > 0)
    Dem_IUMPRInit();
#endif
#if (DEM_DTR_NUM > 0)
    Dem_DTRInit();
#endif
    Dem_OBDInit();
#endif
    DemInitState = DEM_STATE_PRE_INIT;
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Initializes or reinitializes this module.
 * ServiceId           0x02
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr:Pointer to the configuration set in VARIANT-POSTBUILD.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_Init(P2CONST(Dem_ConfigType, AUTOMATIC, DEM_CONST_PBCFG) ConfigPtr)
{
    uint16 iloop;
    Std_ReturnType NvmResult = E_NOT_OK; /* PRQA S 2981 */ /* MISRA Rule 2.2 */
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg;
#endif
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
    static VAR(boolean, AUTOMATIC) FirstStartUp = FALSE;
#endif

    DemPbCfgPtr = ConfigPtr;
    if (NULL_PTR == ConfigPtr)
    {
        DEM_DET_REPORT(DEM_SID_INIT, DEM_E_PARAM_POINTER);
        return;
    }

    Dem_DcmInit();

    Dem_EntryInit();
#if (DEM_NVRAM_BLOCKID_NUM > 0)
    NvmResult = Dem_IntReadNvRAM();
#endif
    Dem_EventMemInit(NvmResult);
    iloop = 0u;
    /*SWS_Dem_00854 */
    while (iloop < DEM_OPERATION_CYCLE_NUM)
    {
        if (DemOperationCycle[iloop].DemOperationCycleAutostart == TRUE)
        {                                                                   /*SWS_Dem_00853 */
            DEM_BITS_SET(DemOperationCycleStatus, iloop); /* PRQA S 2985 */ /* MISRA Rule 2.2 */
            Dem_OperationCycleStart((uint8)iloop, TRUE);
        }
        iloop++;
    }
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    iloop = 0u;
    pEventCfg = DemPbCfgPtr->DemEventParameter;
    while (iloop < DEM_EVENT_PARAMETER_NUM)
    {
        if ((pEventCfg->AlgorithmType == DEM_DEBOUNCE_TIME_BASE)
            && (pEventCfg->AlgorithmIndex < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM))
        {
            DemDebounceTimerInfo[pEventCfg->AlgorithmIndex].IntId = iloop;
        }
        pEventCfg++;
        iloop++;
    }
#endif
#if (DEM_MAX_NUMBER_PRESTORED_FF > 0)
    Dem_FreezeFrameInit();
#endif
    Dem_ResetDemClearDTCInfo();
#if (DEM_J1939_SUPPORT == STD_ON)
    Dem_J1939Init();
#endif
    DemInitState = DEM_STATE_INIT;
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
    if (FirstStartUp == FALSE) /*SWS_Fim_00103*/
    {
        (void)FiM_DemInit();
        FirstStartUp = TRUE;
    }
#endif
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_VERSION_INFO_API == STD_ON)
/*************************************************************************/
/*
 * Brief               Provide Version information to other BSWs
 * ServiceId           0x00
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     versionInfo
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
FUNC(void, DEM_CODE)
Dem_GetVersionInfo(Std_VersionInfoType* versionInfo)
{
    if (NULL_PTR == (versionInfo))
    {
        DEM_DET_REPORT(DEM_SID_GETVERSIONINFO, DEM_E_PARAM_POINTER);
        return;
    }
    versionInfo->vendorID = DEM_VENDOR_ID;
    versionInfo->moduleID = DEM_MODULE_ID;
    versionInfo->sw_major_version = DEM_SW_MAJOR_VERSION;
    versionInfo->sw_minor_version = DEM_SW_MINOR_VERSION;
    versionInfo->sw_patch_version = DEM_SW_PATCH_VERSION;
    return;
}
#endif

/*************************************************************************/
/*
 * Brief               Shuts down this module.
 * ServiceId           0x03
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_Shutdown(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 iloop;
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_SHUTDOWN, DEM_E_UNINIT);
        return;
    }
    /* OperationCycleStatus */
    iloop = 0;
#if (DEM_OPERATION_CYCLE_STATUS_STORAGE == STD_ON)
    while (iloop < DEM_OPERATION_CYCLE_NUM)
    { /*SWS_Dem_00697*/
        if ((DemOperationCycle[iloop].DemOperationCycleAutomaticEnd == TRUE)
            && (0x00u != DEM_BITS_ISSET(DemOperationCycleStatus, iloop)))
        {
            Dem_OperationCycleEnd(iloop);
            DEM_BITS_CLR(DemOperationCycleStatus, iloop);
        }
        iloop++;
    }
#else
    while (iloop < DEM_OPERATION_CYCLE_NUM)
    {
        /*SWS_Dem_01078*/
        if (0x00u != DEM_BITS_ISSET(DemOperationCycleStatus, iloop))
        {
            Dem_OperationCycleEnd(iloop);
            DEM_BITS_CLR(DemOperationCycleStatus, iloop); /* PRQA S 2985 */ /* MISRA Rule 2.2 */
        }
        iloop++;
    }
#endif
#if (DEM_NVRAM_BLOCKID_NUM > 0)
    Dem_IntWriteNvRAM();
#endif
    //DemInitState = DEM_STATE_SHUTDOWN;
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Queues the reported events from the BSW modules (API is only used by
                        BSW modules). The interface has an asynchronous behavior, because
                        the processing of the event is done within the Dem main function.
                        OBD Events Suppression shall be ignored for this computation.
 * ServiceId           0x0f
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant for different EventIds. Non reentrant for the same EventId.
 * Param-Name[in]      EventId: Identification of an event by assigned Event ID.
 *                       EventStatus: Monitor test result
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_ReportErrorStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg;
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint8 OperationCycleId;

    if (EventId < 1u)
    {
        return;
    }
    EventId = Dem_GetEventInternalId(EventId);
    if (DemInitState == DEM_STATE_UNINIT)
    {
        DEM_DET_REPORT(DEM_SID_REPORTERRORSTATUS, DEM_E_UNINIT);
        return;
    }
    if (EventId >= DEM_EVENT_PARAMETER_NUM)
    {
        DEM_DET_REPORT(DEM_SID_REPORTERRORSTATUS, DEM_E_WRONG_CONFIGURATION);
        return;
    }
    pEventCfg = &DemPbCfg.DemEventParameter[EventId];
    if (pEventCfg->DemEventKind != DEM_EVENT_KIND_BSW)
    {
        DEM_DET_REPORT(DEM_SID_REPORTERRORSTATUS, DEM_E_WRONG_CONFIGURATION);
        return;
    }
    if ((pEventCfg->AlgorithmType == DEM_DEBOUNCE_MONITOR_INTERNAL) && (EventStatus != DEM_EVENT_STATUS_FAILED)
        && (EventStatus != DEM_EVENT_STATUS_PASSED))
    {
        DEM_DET_REPORT(DEM_SID_REPORTERRORSTATUS, DEM_E_WRONG_CONFIGURATION);
        return;
    }
    if ((DemInitState == DEM_STATE_PRE_INIT) && (pEventCfg->DemReportBehavior != REPORT_BEFORE_INIT))
    {
        DEM_DET_REPORT(DEM_SID_REPORTERRORSTATUS, DEM_E_WRONG_CONFIGURATION);
        return;
    }
    /*SWS_Dem_00676*/
    if ((DemInitState != DEM_STATE_INIT)
        && (DemPbCfg.DemDebounceCounterBasedClass[pEventCfg->AlgorithmRef].DemDebounceCounterStorage == TRUE))
    {
        DEM_DET_REPORT(DEM_SID_REPORTERRORSTATUS, DEM_E_WRONG_CONDITION);
        return;
    }
    pEventCfg = &DemPbCfg.DemEventParameter[EventId];
    pEvent = Dem_GetEventInfo(EventId);
    if ((NULL_PTR == pEvent) || (NULL_PTR == pEventCfg))
    {
        return;
    }
#if (DEM_ENABLE_SOFT_FILTER_OF_PASS == STD_ON)
    /*soft filter when pass,if TF/TNCLSC or TNCTOC is flaged then return e_ok whith no deal*/
    if (((0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TF))
         && (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCSLC))
         && (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCTOC)))
        && (EventStatus == DEM_EVENT_STATUS_PASSED))
    {
        return;
    }
#endif
    if (DemInitState != DEM_STATE_PRE_INIT) /*SWS_Dem_00851*/
    {
#if (DEM_ENABLE_CONDITION_NUM > 0)
        if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_ENABLED_CONDICTION))
        {                                /*SWS_Dem_00447 SWS_Dem_00449 SWS_Dem_01091*/
            Dem_DebounceFreeze(EventId); /*In case of Dem-internal debouncing the related fault detection counter will
                                            be frozen or reset*/
            return;
        }
#endif
        OperationCycleId = pEventCfg->DemOperationCycleRef;
        if ((0x00u == DEM_BITS_ISSET(DemOperationCycleStatus, OperationCycleId))
            && (DemOperationCycle[OperationCycleId].DemOperationCycleType != DEM_OPCYC_OBD_DCY)) /*SWS_Dem_00700*/
        {
            return;
        }
        if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_DTC_SETTING))
        {
            return;
        }
        /*SWS_Dem_01108*/
        if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
        {
            return;
        }
    }

    Dem_ProcessEventStatus(EventStatus, pEventCfg, pEvent);
    Dem_UpdateCombinedDtcStatus(EventId);
    (void)Dem_EventQueueAdd(Dem_GetEventExternalId(EventId), EventStatus);
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY) /*SWS_Dem_00687*/
/*************************************************************************/
/*
 * Brief               Set the available status of a specific Event.
 * ServiceId           0x37
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      EventId : Identification of an event by assigned EventId.
 *                       AvailableStatus: This parameter specifies whether the respective
 *                       Event shall be available (TRUE) or not (FALSE).
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: Operation was successful.
 *                       E_NOT_OK:change of available status not accepted
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* req SWS_Dem_01106 */
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventAvailable(Dem_EventIdType EventId, boolean AvailableStatus)
{
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint16 dtcIndex;
    uint16 index = 0;
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
    Dem_UdsStatusByteType oldStatus;
#endif
    EventId = Dem_GetEventInternalId(EventId);
    if (DemInitState == DEM_STATE_UNINIT)
    {
        DEM_DET_REPORT(DEM_SID_SETEVENTAVAILABLE, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (EventId >= DEM_EVENT_PARAMETER_NUM)
    {
        DEM_DET_REPORT(DEM_SID_SETEVENTAVAILABLE, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    pEvent = Dem_GetEventInfo(EventId);
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
    oldStatus = pEvent->UdsStatus;
#endif
    /*SWS_Dem_01109*/
    if ((NULL_PTR != Dem_CheckEventMemEntryExistsAlready(EventId))
        || (DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TF) == 0x01u))
    {
        return E_NOT_OK;
    }
    dtcIndex = DemPbCfgPtr->DemEventParameter[EventId].DemDTCRef;
    if (AvailableStatus == TRUE)
    {
        DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE);
        /*SWS_Dem_01111*/
        DEM_FLAGS_SET(
            pEvent->UdsStatus,
            DEM_UDS_STATUS_TNCSLC | DEM_UDS_STATUS_TNCTOC); /* bit 4 6 the initialized value 0x50 */
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
        (void)FiM_DemTriggerOnEventStatus(EventId + 1u, oldStatus, pEvent->UdsStatus);
#endif
        DemDTCGeneralStatus[dtcIndex].SuppressionStatus = FALSE;
    }
    else
    {
        DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE);
        /*SWS_Dem_01110 */
        pEvent->UdsStatus = 0x00;
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
        (void)FiM_DemTriggerOnEventStatus(EventId + 1u, oldStatus, pEvent->UdsStatus);
#endif
        /*SWS_Dem_00915 */
        while (index < DEM_EVENT_PARAMETER_NUM)
        {
            if ((dtcIndex == DemPbCfgPtr->DemEventParameter[index].DemDTCRef)
                && (DEM_FLAGS_ISSET(DemEventRelateInformation[index].Status, DEM_EVENT_STATUS_AVAILABLE) != 0x00u))
            {
                dtcIndex = DEM_DTC_REF_INVALID;
                break;
            }
            index++;
        }
        if (dtcIndex != DEM_DTC_REF_INVALID)
        {
            DemDTCGeneralStatus[dtcIndex].SuppressionStatus = TRUE;
        }
    }
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif

/*************************************************************************/
/*
 * Brief               Processes the events reported by SW-Cs via RTE.
 * ServiceId           0x04
 * Sync/Async          Synchronous/Asynchronous
 * Reentrancy          Reentrant for different EventIds.
 *                       Non reentrant for the same EventId.
 * Param-Name[in]      EventId:Identification of an event by assigned EventId.
 *                       EventStatus: Monitor test result
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: set of event status was successful
 *                       E_NOT_OK: set of event status failed or could not be accepted
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus)
{
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg;
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint8 OperationCycleId;
#if (DEM_STORAGE_CONDITION_NUM > 0)
    uint8 index;
    uint8 Conditionindex;
    uint8 Counter;
    uint8 Mask;
    boolean IsReplacement = FALSE;
#endif

    if (EventId < 1u)
    {
        return E_NOT_OK;
    }
    EventId = Dem_GetEventInternalId(EventId);
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_SETEVENTSTATUS, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (EventId >= DEM_EVENT_PARAMETER_NUM)
    {
        DEM_DET_REPORT(DEM_SID_SETEVENTSTATUS, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    pEventCfg = &DemPbCfgPtr->DemEventParameter[EventId];
    if (pEventCfg->DemEventKind != DEM_EVENT_KIND_SWC)
    {
        DEM_DET_REPORT(DEM_SID_SETEVENTSTATUS, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if ((pEventCfg->AlgorithmType == DEM_DEBOUNCE_MONITOR_INTERNAL) && (EventStatus != DEM_EVENT_STATUS_FAILED)
        && (EventStatus != DEM_EVENT_STATUS_PASSED))
    {
        DEM_DET_REPORT(DEM_SID_SETEVENTSTATUS, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    pEvent = Dem_GetEventInfo(EventId);
    pEventCfg = &DemPbCfgPtr->DemEventParameter[EventId];
    if ((NULL_PTR == pEvent) || (NULL_PTR == pEventCfg))
    {
        return E_NOT_OK;
    }
#if (DEM_ENABLE_SOFT_FILTER_OF_PASS == STD_ON)
    /*soft filter when pass,if TF/TNCLSC or TNCTOC is flaged then return e_ok whith no deal*/
    if (((0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TF))
         && (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCSLC))
         && (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCTOC)))
        && (EventStatus == DEM_EVENT_STATUS_PASSED))
    {
        return E_OK;
    }
#endif

#if (DEM_ENABLE_CONDITION_NUM > 0)
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_ENABLED_CONDICTION))
    { /*SWS_Dem_00447 SWS_Dem_00449 */
        Dem_DebounceFreeze(
            EventId); /*In case of Dem-internal debouncing the related fault detection counter will be frozen or reset*/
        return E_NOT_OK;
    }
#endif
#if (DEM_STORAGE_CONDITION_NUM > 0)
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_STORAGE_CONDICTION))
    {
        index = 0;
        Conditionindex = 0;
        /* PRQA S 2877++ */ /* MISRA Dir 4.1 */
        while ((index < DEM_STORAGE_CONDITION_NUM_BYTE) && (IsReplacement == FALSE))
        /* PRQA S 2877-- */ /* MISRA Dir 4.1 */
        {
            Counter = 0;
            Mask = 0x01;
            /* PRQA S 2877++ */ /* MISRA Dir 4.1 */
            while ((Conditionindex < DEM_STORAGE_CONDITION_NUM) && (IsReplacement == FALSE) && (Counter < 8u))
            /* PRQA S 2877-- */ /* MISRA Dir 4.1 */
            {                   /*SWS_Dem_01086*/
                if (((DemStorageConditionGroup[DemPbCfgPtr->DemEventParameter[EventId].DemStorageConditionGroupRef]
                                              [index]
                      & Mask)
                     != 0u)
                    && (DemStorageCondition[Conditionindex].DemStorageConditionReplacementEventRef
                        != DEM_EVENT_PARAMETER_INVALID)
                    && (EventStatus == DEM_EVENT_STATUS_FAILED))
                {
                    EventId = DemStorageCondition[Conditionindex].DemStorageConditionReplacementEventRef;
                    pEvent = Dem_GetEventInfo(EventId); /*SWS_Dem_01086*/
                    IsReplacement = TRUE;
                }
                Counter++; /* PRQA S 2983 */ /* MISRA Rule 2.2 */
                Conditionindex++;
                Mask = Mask << 1u; /* PRQA S 2983 */ /* MISRA Rule 2.2 */
            }
            index++;
        }
        if (IsReplacement == FALSE)
        {
            return E_NOT_OK;
        }
    }
#endif
    OperationCycleId = pEventCfg->DemOperationCycleRef;
    if ((0x00u == DEM_BITS_ISSET(DemOperationCycleStatus, OperationCycleId))
        && (DemOperationCycle[OperationCycleId].DemOperationCycleType != DEM_OPCYC_OBD_DCY)) /*SWS_Dem_00700*/
    {
        return E_NOT_OK;
    }
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_DTC_SETTING))
    {
        return E_NOT_OK;
    }
    /*SWS_Dem_01108*/
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }

    Dem_ProcessEventStatus(EventStatus, pEventCfg, pEvent);
    Dem_UpdateCombinedDtcStatus(EventId);
    return Dem_EventQueueAdd(Dem_GetEventExternalId(EventId), EventStatus);
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Control the internal debounce counter/timer by BSW modules and SW-Cs.
 * ServiceId           0x09
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different EventIds.
 *                       Non reentrant for the same EventId.
 * Param-Name[in]      EventId:Identification of an event by assigned EventId.
 *                       DebounceResetStatus :  Freeze or reset the internal debounce counter
 *                       /timer of the specified event.
 * Param-Name[out]     None...
 * Param-Name[in/out]  None...
 * Return              None...
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
Dem_ResetEventDebounceStatus(Dem_EventIdType EventId, Dem_DebounceResetStatusType DebounceResetStatus)
{
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    EventId = Dem_GetEventInternalId(EventId);
    if (DemInitState < DEM_STATE_PRE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_RESETEVENTDEBOUNCESTATUS, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (EventId >= DEM_EVENT_PARAMETER_NUM)
    {
        DEM_DET_REPORT(DEM_SID_RESETEVENTDEBOUNCESTATUS, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    /*SWS_Dem_00676*/
    if ((DemInitState != DEM_STATE_INIT)
        && (DemPbCfgPtr->DemDebounceCounterBasedClass[DemPbCfgPtr->DemEventParameter[EventId].AlgorithmRef]
                .DemDebounceCounterStorage
            == TRUE))
    {
        DEM_DET_REPORT(DEM_SID_RESETEVENTDEBOUNCESTATUS, DEM_E_WRONG_CONDITION);
        return E_NOT_OK;
    }
    pEvent = Dem_GetEventInfo(EventId);
    /*SWS_Dem_01108*/
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }
    if (DebounceResetStatus == DEM_DEBOUNCE_STATUS_RESET)
    { /*SWS_Dem_00684*/
        if (DemPbCfgPtr->DemEventParameter[EventId].AlgorithmType == DEM_DEBOUNCE_COUNTER_BASED)
        {
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
            if (DemPbCfgPtr->DemEventParameter[EventId].AlgorithmIndex < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM)
            {
                DemDebounceCounterInfo[DemPbCfgPtr->DemEventParameter[EventId].AlgorithmIndex].InternalDebounceCounter =
                    0;
                DemDebounceCounterInfo[DemPbCfgPtr->DemEventParameter[EventId].AlgorithmIndex].CurStatus =
                    DEM_EVENT_STATUS_PREPASSED;
            }
#endif
        }
        else if (DemPbCfgPtr->DemEventParameter[EventId].AlgorithmType == DEM_DEBOUNCE_TIME_BASE)
        {
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
            if (DemPbCfgPtr->DemEventParameter[EventId].AlgorithmIndex < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM)
            {
                DemDebounceTimerInfo[DemPbCfgPtr->DemEventParameter[EventId].AlgorithmIndex].Timeout = 0u;
                DemDebounceTimerInfo[DemPbCfgPtr->DemEventParameter[EventId].AlgorithmIndex].Triggered = FALSE;
                DemDebounceTimerInfo[DemPbCfgPtr->DemEventParameter[EventId].AlgorithmIndex].CurStatus =
                    DEM_EVENT_STATUS_PREPASSED;
            }
#endif
        }
        else
        {
            /*idle*/
        }
    }
    else if (DebounceResetStatus == DEM_DEBOUNCE_STATUS_FREEZE)
    { /*SWS_Dem_00685*/
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
        if (DemPbCfgPtr->DemEventParameter[EventId].AlgorithmIndex < DEM_DEBOUNCE_TIME_BASED_EVENT_NUM)
        {
            DemDebounceTimerInfo[DemPbCfgPtr->DemEventParameter[EventId].AlgorithmIndex].IsFreezing = TRUE;
        }
#endif
    }
    else
    {
        /*idle*/
    }
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Resets the event failed status.
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different EventIds.
 *                       Non reentrant for the same EventId.
 * Param-Name[in]      EventId Identification of an event by assigned EventId.
 * Param-Name[out]     None...
 * Param-Name[in/out]  None...
 * Return              E_OK: reset of event status was successful
 *                       E_NOT_OK: reset of event status failed or is not allowed,
 *                       because the event is already tested in this operation cycle
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus(Dem_EventIdType EventId)
{
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

    if (DemInitState < DEM_STATE_PRE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_RESETEVENTSTATUS, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if ((EventId > DEM_EVENT_PARAMETER_NUM) || (EventId == 0u))
    {
        DEM_DET_REPORT(DEM_SID_RESETEVENTSTATUS, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }

    EventId = Dem_GetEventInternalId(EventId);
    pEvent = Dem_GetEventInfo(EventId);
    /* SWS_Dem_00638*/
    if (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCTOC))
    {
        return E_NOT_OK;
    }
    /*SWS_Dem_01108*/
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }
    /*SWS_Dem_00187*/
    DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_TF);
    Dem_UpdateCombinedDtcStatus(EventId); /* update the combination event dtc status*/
    Dem_ResponseOnDtcStatusChange(EventId);
    Dem_DebounceReset(EventId);
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_FFPRESTORAGE_SUPPORT == STD_ON)
/*************************************************************************/
/*
 * Brief               Captures the freeze frame data for a specific event.
 * ServiceId           0x06
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different EventIds.
 *                       Non reentrant for the sameEventId.
 * Param-Name[in]      EventId:Identification of an event by assigned EventId
 * Param-Name[out]     None...
 * Param-Name[in/out]  None...
 * Return              None...
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE) Dem_PrestoreFreezeFrame(Dem_EventIdType EventId)
{
#if (DEM_MAX_NUMBER_PRESTORED_FF > 0)
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg;
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

    EventId = Dem_GetEventInternalId(EventId);
    if (DemInitState < DEM_STATE_PRE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_PRESTOREFREEZEFRAME, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (EventId >= DEM_EVENT_PARAMETER_NUM)
    {
        DEM_DET_REPORT(DEM_SID_PRESTOREFREEZEFRAME, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    pEventCfg = &DemPbCfgPtr->DemEventParameter[EventId];
    if (pEventCfg->DemFFPrestorageSupported == FALSE)
    {
        DEM_DET_REPORT(DEM_SID_PRESTOREFREEZEFRAME, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    pEvent = Dem_GetEventInfo(EventId);
    /*SWS_Dem_01108*/
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }
    return Dem_PreStoreFF(Dem_GetEventExternalId(EventId));
#else
    return E_NOT_OK;
#endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Clears a prestored freeze frame of a specific event.
 * ServiceId           0x07
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different EventIds.
 *                       Non reentrant for the same EventId.
 * Param-Name[in]      EventId : Identification of an event by assigned EventId.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPrestoredFreezeFrame(Dem_EventIdType EventId)
{
#if (DEM_MAX_NUMBER_PRESTORED_FF > 0)

    EventId = Dem_GetEventInternalId(EventId);
    if (DemInitState < DEM_STATE_PRE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_CLEARPRESTOREDFREEZEFRAME, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if ((EventId > DEM_EVENT_PARAMETER_NUM) || (EventId == 0u))
    {
        DEM_DET_REPORT(DEM_SID_CLEARPRESTOREDFREEZEFRAME, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (DemPbCfgPtr->DemEventParameter[EventId].DemFFPrestorageSupported == FALSE)
    {
        DEM_DET_REPORT(DEM_SID_CLEARPRESTOREDFREEZEFRAME, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }

    return Dem_ClearPreStoreFF(Dem_GetEventExternalId(EventId));
#else
    return E_NOT_OK;
#endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
#endif

/*************************************************************************/
/*
 * Brief               Sets an operation cycle state.
 * ServiceId           0x08
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      OperationCycleId: Identification of operation cycle, like power cycle,
 *                                         driving cycle.
 *                       CycleState: New operation cycle state: (re-)start or end
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: set of operation cycle was accepted and will be handled asynchronously
 *                       E_NOT_OK: set of operation cycle was rejected>
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
Dem_SetOperationCycleState(uint8 OperationCycleId, Dem_OperationCycleStateType CycleState)
{
    boolean IsRestart = FALSE;
    if (DemInitState == DEM_STATE_UNINIT)
    {
        DEM_DET_REPORT(DEM_SID_SETOPERATIONCYCLESTATE, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (OperationCycleId >= DEM_OPERATION_CYCLE_NUM)
    {
        DEM_DET_REPORT(DEM_SID_SETOPERATIONCYCLESTATE, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (CycleState == DEM_CYCLE_STATE_START)
    {                                                                                             /*SWS_Dem_00853*/
        if (0x00u != DEM_BITS_ISSET(DemOperationCycleStatus, OperationCycleId)) /* PRQA S 2985 */ /* MISRA Rule 2.2 */
        {
            IsRestart = TRUE; /*SWS_Dem_00483*/
        }
        else
        {
            DEM_BITS_SET(DemOperationCycleStatus, OperationCycleId); /* PRQA S 2985 */ /* MISRA Rule 2.2 */
        }
        Dem_OperationCycleStart(OperationCycleId, IsRestart);
    }
    else
    {
        if (0x00u != DEM_BITS_ISSET(DemOperationCycleStatus, OperationCycleId)) /* PRQA S 2985 */ /* MISRA Rule 2.2 */
        {
            Dem_OperationCycleEnd(OperationCycleId);
            DEM_BITS_CLR(DemOperationCycleStatus, OperationCycleId); /* PRQA S 2985 */ /* MISRA Rule 2.2 */
        }                                                                              /*SWS_Dem_00484 */
    }

#if (DEM_NVRAM_BLOCKID_NUM > 0)
    /* process storage */
    if (TRUE == DemAgingStorageTrigger)
    {
        Dem_IntWriteNvRAM();
        DemAgingStorageTrigger = FALSE;
    }
#endif

    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets information about the status of a specific operation cycle.
 * ServiceId           0x9e
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      OperationCycleId : Identification of operation cycle, like power cycle,
 *                                          driving cycle.
 * Param-Name[out]     CycleState : Cycle status information
 * Param-Name[in/out]  None
 * Return              E_OK: read out of operation cycle was successful
 *                       E_NOT_OK: read out of operation cycle failed
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetOperationCycleState(
    uint8 OperationCycleId,
    P2VAR(Dem_OperationCycleStateType, AUTOMATIC, DEM_APPL_DATA) CycleState) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    if (DemInitState == DEM_STATE_UNINIT)
    {
        DEM_DET_REPORT(DEM_SID_GETOPERATIONCYCLESTATE, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (OperationCycleId >= DEM_OPERATION_CYCLE_NUM)
    {
        DEM_DET_REPORT(DEM_SID_GETOPERATIONCYCLESTATE, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (CycleState == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETOPERATIONCYCLESTATE, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }

    if (0x00u == DEM_BITS_ISSET(DemOperationCycleStatus, OperationCycleId)) /* PRQA S 2985 */ /* MISRA Rule 2.2 */
    {
        *CycleState = DEM_CYCLE_STATE_END;
    }
    else
    {
        *CycleState = DEM_CYCLE_STATE_START;
    }
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Triggers the next aging cycle state.
 * ServiceId           0x11
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      OperationCycleId:Identification of aging cycle.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: set of aging cycle was successful
 *                       E_NOT_OK: set of aging cycle failed
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE) Dem_SetAgingCycleState(uint8 OperationCycleId)
{
    if (DemInitState == DEM_STATE_UNINIT)
    {
        DEM_DET_REPORT(DEM_SID_SETAGINGCYCLESTATE, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (OperationCycleId >= DEM_OPERATION_CYCLE_NUM)
    {
        DEM_DET_REPORT(DEM_SID_SETAGINGCYCLESTATE, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }

    DemAgingCycle = OperationCycleId;
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"
/*************************************************************************/
/*
 * Brief               Sets the WIR status bit via failsafe SW-Cs.
 * ServiceId           0x7a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different EventIds.
 *                       Non reentrant for the same EventId.
 * Param-Name[in]      EventId: Identification of an event by assigned EventId.
 *                       WIRStatus: Requested status of event related WIR-bit
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: The request is accepted
 *                       E_NOT_OK: not be accepted
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE) Dem_SetWIRStatus(Dem_EventIdType EventId, boolean WIRStatus)
{
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    if (DemInitState < DEM_STATE_PRE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_SETWIRSTATUS, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if ((EventId > DEM_EVENT_PARAMETER_NUM) || (EventId == 0u))
    {
        DEM_DET_REPORT(DEM_SID_SETWIRSTATUS, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }

    pEvent = Dem_GetEventInfo(Dem_GetEventInternalId(EventId));
    /*SWS_Dem_01108 */
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_DTC_SETTING))
    {
        return E_NOT_OK; /*SWS_Dem_00836*/
    }
    if (WIRStatus == TRUE)
    {
        DEM_FLAGS_SET(pEvent->UdsStatus, DEM_UDS_STATUS_WIR); /*SWS_Dem_00833*/
    }
    else
    {
        DEM_FLAGS_CLR(pEvent->UdsStatus, DEM_UDS_STATUS_WIR); /*SWS_Dem_00834*/
    }
    Dem_UpdateCombinedDtcStatus(Dem_GetEventInternalId(EventId)); /* update the combination event dtc status*/
    Dem_ResponseOnDtcStatusChange(Dem_GetEventInternalId(EventId));
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the failed status of a DemComponent.
 * ServiceId           0x2a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ComponentId:Identification of a DemComponent
 * Param-Name[out]     ComponentFailed: TRUE: failed FALSE: not failed
 * Param-Name[in/out]  None
 * Return              E_OK: getting "ComponentFailed" was successful
 *                       E_NOT_OK: getting "ComponentFailed" was not successful
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
/* PRQA S 3432,1532++ */ /* MISRA Rule 20.7,8.7 */
Dem_GetComponentFailed(Dem_ComponentIdType ComponentId, P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) ComponentFailed)
/* PRQA S 3432,1532-- */ /* MISRA Rule 20.7,8.7 */
{
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_GETCOMPONENTFAILED, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (ComponentId > DEM_COMPONENT_NUM)
    {
        DEM_DET_REPORT(DEM_SID_GETCOMPONENTFAILED, DEM_E_WRONG_RECORDNUMBER);
        return E_NOT_OK;
    }
    if (ComponentFailed == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETCOMPONENTFAILED, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }
#if (DEM_COMPONENT_NUM > 0)
    ComponentId = Dem_GetEventInternalId(ComponentId);
    /*SWS_Dem_01134 */
    if (DemComponentStatus[ComponentId].availability == TRUE)
    {
        /*SWS_Dem_01131 */
        *ComponentFailed = DemComponentStatus[ComponentId].Status;
        return E_OK;
    }
    else
    {
        return E_NOT_OK;
    }
#else
    (void)ComponentId;
    (void)ComponentFailed;
    return E_NOT_OK;
#endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the current extended event status of an event.
 * ServiceId           0x0a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      EventId:Identification of an event by assigned EventId.
 * Param-Name[out]     EventStatusByte:UDS DTC status byte of the requested event
 * Param-Name[in/out]  None
 * Return              E_OK: get of event status was successful
 *                       E_NOT_OK: get of event status failed
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
/* PRQA S 3432,1532++ */ /* MISRA Rule 20.7,8.7 */
Dem_GetEventStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventStatusByte)
/* PRQA S 3432,1532-- */ /* MISRA Rule 20.7,8.7 */
{
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTSTATUS, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if ((EventId > DEM_EVENT_PARAMETER_NUM) || (EventId == 0u))
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTSTATUS, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (EventStatusByte == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTSTATUS, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }

    pEvent = Dem_GetEventInfo(Dem_GetEventInternalId(EventId));
    /*SWS_Dem_01108*/
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }
    *EventStatusByte = pEvent->UdsStatus;
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the event failed status of an event.
 * ServiceId           0x0b
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      EventId: Identification of an event by assigned EventId.
 * Param-Name[out]     EventFailed: TRUE - Last Failed FALSE - not Last Failed
 * Param-Name[in/out]  None
 * Return              E_OK: get of "EventFailed" was successful
 *                       E_NOT_OK: get of "EventFailed" was not successful
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
Dem_GetEventFailed(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventFailed)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTFAILED, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if ((EventId > DEM_EVENT_PARAMETER_NUM) || (EventId == 0u))
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTFAILED, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (EventFailed == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTFAILED, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }

    pEvent = Dem_GetEventInfo(Dem_GetEventInternalId(EventId));
    /*SWS_Dem_01108*/
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }
    if (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TF))
    {
        *EventFailed = FALSE;
    }
    else
    {
        *EventFailed = TRUE;
    }
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the event tested status of an event.
 * ServiceId           0x0c
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      EventId:Identification of an event by assigned EventId.
 * Param-Name[out]     EventTested: TRUE - event tested this cycle
 *                                    FALSE - event not tested this cycle
 * Param-Name[in/out]  None
 * Return              E_OK: get of event state "tested" successful
 *                       E_NOT_OK: get of event state "tested" failed
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
Dem_GetEventTested(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventTested)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTTESTED, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if ((EventId > DEM_EVENT_PARAMETER_NUM) || (EventId == 0u))
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTTESTED, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (EventTested == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTTESTED, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }

    pEvent = Dem_GetEventInfo(Dem_GetEventInternalId(EventId));
    /*SWS_Dem_01108*/
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }
    if (0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCTOC))
    {
        *EventTested = TRUE;
    }
    else
    {
        *EventTested = FALSE;
    }
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the debouncing status of an event.
 * ServiceId           0x9f
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      EventId:Identification of an event by assigned EventId.
 * Param-Name[out]     DebouncingState
 * Param-Name[in/out]  None
 * Return              E_OK: get of debouncing status per event state successful
 *                       E_NOT_OK: get of debouncing per event state failed
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetDebouncingOfEvent(
    Dem_EventIdType EventId,
    P2VAR(Dem_DebouncingStateType, AUTOMATIC, DEM_APPL_DATA) DebouncingState) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    sint8 FDC = 0;
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_GETDEBOUNCINGOFEVENT, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if ((EventId > DEM_EVENT_PARAMETER_NUM) || (EventId == 0u))
    {
        DEM_DET_REPORT(DEM_SID_GETDEBOUNCINGOFEVENT, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (DebouncingState == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETDEBOUNCINGOFEVENT, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }

    pEvent = Dem_GetEventInfo(Dem_GetEventInternalId(EventId));
    /*SWS_Dem_01108*/
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }
    (void)Dem_GetInteralFDC(Dem_GetEventInternalId(EventId), &FDC);

    *DebouncingState = 0x00;
    /*SWS_Dem_00844*/
    if ((FDC < 127) && (FDC > 0))
    {
        *DebouncingState |= DEM_TEMPORARILY_DEFECTIVE;
    }

    if (FDC == 127)
    {
        *DebouncingState |= DEM_FINALLY_DEFECTIVE;
    }

    if ((FDC < 0) && (FDC > -128))
    {
        *DebouncingState |= DEM_TEMPORARILY_HEALED;
    }

    if ((FDC == -128) || (FDC == 127))
    {
        *DebouncingState |= DEM_TEST_COMPLETE;
    }
    if ((0x00u == DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TNCTOC))
        && ((0x00u != DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_ENABLED_CONDICTION))
            || (0x00u != DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_STORAGE_CONDICTION))))
    {
        *DebouncingState |= DEM_DTR_UPDATE;
    }
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the DTC of an event.
 * ServiceId           0x0d
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      EventId:Identification of an event by assigned EventId.
 *                       DTCFormat: Defines the output-format of the requested DTCvalue.>
 * Param-Name[out]     DTCOfEvent: Receives the DTC value in respective format returned
 *                                   by this function.
 * Param-Name[in/out]  None
 * Return              E_OK: get of DTC was successful
 *                       E_NOT_OK: the call was not successful
 *                       DEM_E_NO_DTC_AVAILABLE: there is no DTC configured in the requested format
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetDTCOfEvent(
    Dem_EventIdType EventId,
    Dem_DTCFormatType DTCFormat,
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTCOfEvent) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    Std_ReturnType res = DEM_E_NO_DTC_AVAILABLE;
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg;
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_GETDTCOFEVENT, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if ((EventId > DEM_EVENT_PARAMETER_NUM) || (EventId == 0u))
    {
        DEM_DET_REPORT(DEM_SID_GETDTCOFEVENT, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (DTCOfEvent == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETDTCOFEVENT, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }
    pEvent = Dem_GetEventInfo(Dem_GetEventInternalId(EventId));
    /*SWS_Dem_01108*/
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }
    *DTCOfEvent = 0x00u;
    EventId = Dem_GetEventInternalId(EventId);
    pEventCfg = &DemPbCfgPtr->DemEventParameter[EventId];
    if (pEventCfg->DemDTCRef != DEM_DTC_REF_INVALID)
    {
        /*SWS_Dem_00269*/
        switch (DTCFormat)
        {
        case DEM_DTC_FORMAT_OBD:
            if ((DemPbCfgPtr->DemDTC[pEventCfg->DemDTCRef].DemObdDTCRef != DEM_OBD_DTC_INVALID)
                && (DemPbCfgPtr->DemObdDTC[DemPbCfgPtr->DemDTC[pEventCfg->DemDTCRef].DemObdDTCRef].DemDtcValue
                    != DEM_OBD_DTC_CFG_INVALID))
            {
                *DTCOfEvent =
                    DemPbCfgPtr->DemObdDTC[DemPbCfgPtr->DemDTC[pEventCfg->DemDTCRef].DemObdDTCRef].DemDtcValue;
                res = E_OK;
            }
            break;
        case DEM_DTC_FORMAT_UDS:
            if (DemPbCfgPtr->DemDTC[pEventCfg->DemDTCRef].DemDtcValue != DEM_DTC_CFG_INVALID)
            {
                *DTCOfEvent = DemPbCfgPtr->DemDTC[pEventCfg->DemDTCRef].DemDtcValue;
                res = E_OK;
            }
            break;
        case DEM_DTC_FORMAT_J1939:
            if ((DemPbCfgPtr->DemDTC[pEventCfg->DemDTCRef].DemObdDTCRef != DEM_OBD_DTC_INVALID)
                && (DemPbCfgPtr->DemObdDTC[DemPbCfgPtr->DemDTC[pEventCfg->DemDTCRef].DemObdDTCRef].DemJ1939DTCValue
                    != DEM_J1939_DTC_CFG_INVALID))
            {
                *DTCOfEvent =
                    DemPbCfgPtr->DemObdDTC[DemPbCfgPtr->DemDTC[pEventCfg->DemDTCRef].DemObdDTCRef].DemJ1939DTCValue;
                res = E_OK;
            }
            break;
        default:
            res = DEM_E_NO_DTC_AVAILABLE;
            break;
        }
    }

    return res;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Sets an enable condition.
 * ServiceId           0x39
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      EnableConditionID:This parameter identifies the enable condition.
 *                       ConditionFulfilled: This parameter specifies whether the enable condition
 *                       assigned to the EnableConditionID is fulfilled
 *                       (TRUE) or not fulfilled (FALSE).
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              In case the enable condition could be set successfully the API call returns E_OK.
 *                      If the setting of the enable condition failed the return value of the
 *                      function is E_NOT_OK.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition(uint8 EnableConditionID, boolean ConditionFulfilled)
{
#if (DEM_ENABLE_CONDITION_NUM > 0)
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_SETENABLECONDITION, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (EnableConditionID >= DEM_ENABLE_CONDITION_NUM)
    {
        DEM_DET_REPORT(DEM_SID_SETENABLECONDITION, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }

    if (ConditionFulfilled == FALSE)
    {
        DEM_BITS_CLR(DemEnableConditionStatus, EnableConditionID);
    }
    else
    {
        DEM_BITS_SET(DemEnableConditionStatus, EnableConditionID);
    }
    DemCheckEnableCondition = TRUE;
    return E_OK;
#else
    DEM_UNUSED(EnableConditionID);
    DEM_UNUSED(ConditionFulfilled);
    return E_NOT_OK;
#endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Sets a storage condition.
 * ServiceId           0x38
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      StorageConditionID: This parameter identifies the storage condition.
 *                       ConditionFulfilled: This parameter specifies whether the storage condition
 *                       assigned to the StorageConditionID is fulfilled (TRUE) or not
 *                       fulfilled (FALSE).
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              In case the storage condition could be set successfully the API call
 *                      returns E_OK. If the setting of the storage condition failed the
 *                      return value of the function is E_NOT_OK.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE) Dem_SetStorageCondition(uint8 StorageConditionID, boolean ConditionFulfilled)
{
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_SETSTORAGECONDITION, DEM_E_UNINIT);
        return E_NOT_OK;
    }
#if (DEM_STORAGE_CONDITION_NUM > 0)
    if (StorageConditionID >= DEM_STORAGE_CONDITION_NUM)
    {
        DEM_DET_REPORT(DEM_SID_SETSTORAGECONDITION, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
#endif
#if (DEM_STORAGE_CONDITION_NUM > 0)
    if (ConditionFulfilled == FALSE)
    {
        DEM_BITS_CLR(DemStorageConditionStatus, StorageConditionID);
    }
    else
    {
        DEM_BITS_SET(DemStorageConditionStatus, StorageConditionID);
    }
    DemCheckStorageCondition = TRUE;
    return E_OK;
#else
    (void)StorageConditionID;
    (void)ConditionFulfilled;
    return E_NOT_OK;
#endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the fault detection counter of an event.
 * ServiceId           0x3e
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      EventId : Identification of an event by assigned EventId.>
 * Param-Name[out]     FaultDetectionCounter: This parameter receives the Fault Detection Counter
 *                      information of the requested EventId. If the return value of the function
 *                      call is other than E_OK this parameter does not contain valid data.
 *                      -128dec...127dec PASSED... FAILED according to ISO 14229-1
 * Param-Name[in/out]  None
 * Return              E_OK: request was successful
 *                       E_NOT_OK: request failed
 *                       DEM_E_NO_FDC_AVAILABLE: there is no fault detection counter available
 *                       for the requested event
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
Dem_GetFaultDetectionCounter(Dem_EventIdType EventId, P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    Std_ReturnType ret;

    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_GETFAULTDETECTIONCOUNTER, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if ((EventId > DEM_EVENT_PARAMETER_NUM) || (EventId == 0u))
    {
        DEM_DET_REPORT(DEM_SID_GETFAULTDETECTIONCOUNTER, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (FaultDetectionCounter == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETFAULTDETECTIONCOUNTER, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }
    pEvent = Dem_GetEventInfo(Dem_GetEventInternalId(EventId));
    /*SWS_Dem_01108*/
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }
    ret = Dem_GetInteralFDC(Dem_GetEventInternalId(EventId), FaultDetectionCounter);
    return ret;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the indicator status derived from the event status.
 * ServiceId           0x29
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IndicatorId: Number of indicator
 * Param-Name[out]     IndicatorStatus: Status of the indicator, like off, on, or blinking.
 * Param-Name[in/out]  None
 * Return              E_OK: Operation was successful E_NOT_OK: Operation failed
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
Dem_GetIndicatorStatus(uint8 IndicatorId, P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_GETINDICATORSTATUS, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (IndicatorId >= DEM_INDICATOR_NUM)
    {
        DEM_DET_REPORT(DEM_SID_GETINDICATORSTATUS, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (IndicatorStatus == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETINDICATORSTATUS, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }
#if (DEM_INDICATOR_NUM > 0)
    *IndicatorStatus = DemWIRStatus[IndicatorId];
    return E_OK;
#else
    return E_NOT_OK;
#endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Sets the indicator status included in the event status.
 * ServiceId           0xa1
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      IndicatorId : Number of indicator
 *                      IndicatorStatus Status of the indicator, like off, on, or blinking.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: Operation was successful
 *                       E_NOT_OK: Operation failed or is not supported
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
Dem_SetIndicatorStatus(uint8 IndicatorId, P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_SETINDICATORSTATUS, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (IndicatorId >= DEM_INDICATOR_NUM)
    {
        DEM_DET_REPORT(DEM_SID_SETINDICATORSTATUS, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (IndicatorStatus == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_SETINDICATORSTATUS, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }
#if (DEM_INDICATOR_NUM > 0)
    DemWIRStatus[IndicatorId] = *IndicatorStatus;
    return E_OK;
#else
    return E_NOT_OK;
#endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the data of a freeze frame by event.
 * ServiceId           0x6e
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      EventId: Identification of an event by assigned EventId.
 *                       RecordNumber: This parameter is a unique identifier for a freeze
 *                       frame record as defined in ISO15031-5 and ISO14229-1.
 *                       0xFF means most recent freeze frame record is returned.
 *                       DataId : This parameter specifies the PID (ISO15031-5 mapped in UDS range
 *                       0xF400 - 0xF4FF) or DID (ISO14229-1) that shall be copied to
 *                       the destination buffer.
 * Param-Name[out]     DestBuffer : This parameter contains a byte pointer that points to the
 *                       buffer, to which the freeze frame data record shall be written to.
 *                       The format is raw hexadecimal values and contains no header-information.
 * Param-Name[in/out]   BufSize: When the function is called this parameter contains
                            the maximum number of data bytes that can be written to the buffer.
                            The function returns the actual number of written
                            data bytes in this parameter
 * Return              E_OK: Operation was successful
 *                       DEM_E_NODATAAVAILABLE: The requested event data is not currently stored
 *                                              (but the request was valid)
 *                       DEM_E_WRONG_RECORDNUMBER: The requested record number is not supported
 *                                              by the event
 *                       DEM_E_WRONG_DIDNUMBER: The requested DID is not supported by the freeze frame
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 0624++ */ /* MISRA Rule 8.3 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetEventFreezeFrameDataEx(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint16* BufSize)
/* PRQA S 0624-- */ /* MISRA Rule 8.3 */
{
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry; /* PRQA S 3432 */          /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pMemDest;
    uint8 iloop;
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
    uint16 dtcRef;
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) Entry; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint8 index = 0;
#endif
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTFREEZEFRAMEDATAEX, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if ((EventId > DEM_EVENT_PARAMETER_NUM) || (EventId == 0u))
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTFREEZEFRAMEDATAEX, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (DestBuffer == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTFREEZEFRAMEDATAEX, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }
    pEvent = Dem_GetEventInfo(Dem_GetEventInternalId(EventId));
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
    dtcRef = DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(EventId)].DemDTCRef;
    pMemDest = DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[dtcRef].DemDTCAttributesRef].DemMemoryDestinationRef;
    if (*pMemDest != DEM_MEM_DEST_INVALID)
    {
        Entry = DemMemDestCfg[*pMemDest].EntryList;
        pEntry = NULL_PTR;
        while (index < DEM_MEM_DEST_MAX_NUM_OF_DTC) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            iloop = 0;
            while (iloop < DemMemDestCfg[*pMemDest].EntryNum)
            {
                if ((Entry->EventId != 0u)
                    && (DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(Entry->EventId)].DemDTCRef == dtcRef))
                {
                    pEntry = Dem_MemEntryGet(Entry->EventId, *pMemDest);
                }
                iloop++;
                Entry++;
            }
            index++;
            pMemDest++; /* PRQA S 2982 */ /* MISRA Rule 2.2 */
        }
    }
#else
    pEntry = Dem_CheckEventMemEntryExistsAlready(Dem_GetEventInternalId(EventId));
#endif
    if (pEntry == NULL_PTR)
    {
        return E_NOT_OK; /*SWS_Dem_00996 */
    }
    iloop = 0;
    pMemDest =
        DemPbCfgPtr
            ->DemDTCAttributes[DemPbCfgPtr
                                   ->DemDTC[DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(EventId)].DemDTCRef]
                                   .DemDTCAttributesRef]
            .DemMemoryDestinationRef;
    while (iloop < DEM_MEM_DEST_MAX_NUM_OF_DTC) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
    {
        if (*pMemDest != DEM_MEM_DEST_INVALID)
        {
            if ((*pMemDest != DEM_DTC_ORIGIN_PERMANENT_MEMORY)
                && (*pMemDest != DEM_DTC_ORIGIN_MIRROR_MEMORY)) /*SWS_Dem_01062 */
            {
#if ((DEM_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_J1939_FREEZE_FRAME_CLASS_NUM > 0) || (DEM_PID_CLASS_NUM > 0))
                return Dem_FreezeFrameGetFromEntry(pEntry, RecordNumber, DataId, DestBuffer, BufSize);
#endif
            }
        }
        iloop++;
        pMemDest++; /* PRQA S 2983 */ /* MISRA Rule 2.2 */
    }
    return E_NOT_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the data of an extended data record by event.
 * ServiceId           0x6d
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      EventId : Identification of an event by assigned EventId.
 *                       RecordNumber: Identification of requested Extended data record.
 *                       Valid values are between 0x01 and 0xEF as defined in ISO14229-1.
 * Param-Name[out]     DestBuffer: This parameter contains a byte pointer that points
 *                          to the buffer, to which the extended data shall bewritten to.
 *                          The format is raw hexadecimal values and contains no header-information.
 * Param-Name[in/out]  None
 * Return              E_OK: Operation was successful
 *                       DEM_E_NODATAAVAILABLE: The requested event data is not currently
 *                              stored (but the request was valid)
 *                       DEM_E_WRONG_RECORDNUMBER: The requested record number is not supported by the event
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 0624++ */ /* MISRA Rule 8.3 */
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetEventExtendedDataRecordEx(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint16* BufSize)
/* PRQA S 0624-- */ /* MISRA Rule 8.3 */
{
#if (DEM_EXTENDED_DATA_CLASS_NUM > 0)
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) pEntry; /* PRQA S 3432 */          /* MISRA Rule 20.7 */
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pMemDest;
    uint8 iloop;
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
    uint16 dtcRef;
    P2VAR(Dem_EventMemEntryType, AUTOMATIC, DEM_VAR) Entry; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    uint8 index = 0;
#endif
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTEXTENDEDDATARECORDEX, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if ((EventId > DEM_EVENT_PARAMETER_NUM) || (EventId == 0u))
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTEXTENDEDDATARECORDEX, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    if (DestBuffer == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTEXTENDEDDATARECORDEX, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }
    pEvent = Dem_GetEventInfo(Dem_GetEventInternalId(EventId));
    if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE))
    {
        return E_NOT_OK;
    }
#if (DEM_EVENT_COMBINATION_SUPPORT == DEM_EVCOMB_ONSTORAGE)
    dtcRef = DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(EventId)].DemDTCRef;
    pMemDest = DemPbCfgPtr->DemDTCAttributes[DemPbCfgPtr->DemDTC[dtcRef].DemDTCAttributesRef].DemMemoryDestinationRef;
    Entry = DemMemDestCfg[*pMemDest].EntryList;
    pEntry = NULL_PTR;
    while (index < DEM_MEM_DEST_MAX_NUM_OF_DTC) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
    {
        iloop = 0;
        while (iloop < DemMemDestCfg[*pMemDest].EntryNum)
        {
            if ((Entry->EventId != 0u)
                && (DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(Entry->EventId)].DemDTCRef == dtcRef))
            {
                pEntry = Dem_MemEntryGet(Entry->EventId, *pMemDest);
            }
            iloop++;
            Entry++;
        }
        index++;
        pMemDest++; /* PRQA S 2982 */ /* MISRA Rule 2.2 */
    }
#else
    pEntry = Dem_CheckEventMemEntryExistsAlready(Dem_GetEventInternalId(EventId));
#endif
    if (pEntry == NULL_PTR)
    {
        return E_NOT_OK; /*SWS_Dem_00997*/
    }
    iloop = 0;
    pMemDest =
        DemPbCfgPtr
            ->DemDTCAttributes[DemPbCfgPtr
                                   ->DemDTC[DemPbCfgPtr->DemEventParameter[Dem_GetEventInternalId(EventId)].DemDTCRef]
                                   .DemDTCAttributesRef]
            .DemMemoryDestinationRef;
    while (iloop < DEM_MEM_DEST_MAX_NUM_OF_DTC) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
    {
        if (*pMemDest != DEM_MEM_DEST_INVALID)
        {
            if ((*pMemDest != DEM_DTC_ORIGIN_PERMANENT_MEMORY)
                && (*pMemDest != DEM_DTC_ORIGIN_MIRROR_MEMORY)) /*SWS_Dem_01062 */
            {
                return Dem_ExtendedDataGetFromEntry(pEntry, RecordNumber, DestBuffer, BufSize);
            }
        }
        iloop++;
        pMemDest++; /* PRQA S 2983 */ /* MISRA Rule 2.2 */
    }
    return E_NOT_OK;
#else
    return E_NOT_OK;
#endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Gets the event memory overflow indication status.
 * ServiceId           0x32
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTCOrigin: If the Dem supports more than one event memory this parameter
 *                          is used to select the source memory the overflow indication shall be read from.>
 * Param-Name[out]     OverflowIndication: This parameter returns TRUE if the according
 *                          event memory was overflowed, otherwise it returns FALSE.
 * Param-Name[in/out]  None
 * Return              E_OK: Operation was successful
 *                       E_NOT_OK: Operation failed or is not supported
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
/* PRQA S 3432++ */ /* MISRA Rule 20.7 */
Dem_GetEventMemoryOverflow(Dem_DTCOriginType DTCOrigin, P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) OverflowIndication)
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */
{
    uint8 memDest;
    memDest = Dem_GetInternalMemDest(DTCOrigin);
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTMEMORYOVERFLOW, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (OverflowIndication == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTMEMORYOVERFLOW, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }
    if (memDest == DEM_MEM_DEST_INVALID)
    {
        DEM_DET_REPORT(DEM_SID_GETEVENTMEMORYOVERFLOW, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    /*SWS_Dem_00398*/
    *OverflowIndication = DemMemDestInfo[memDest].OverFlow;
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Returns the number of entries currently stored in the requested event memory.
 * ServiceId           0x35
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTCOrigin: If the Dem supports more than one event memory
 *                          this parameter is used to select the source memory
 *                          the number of entries shall be read from.
 * Param-Name[out]     NumberOfEventMemoryEntries: Number of entries currently stored in the
 *                          requested event memory.
 * Param-Name[in/out]  None
 * Return              E_OK: Operation was successful E_NOT_OK: Operation failed
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE)
Dem_GetNumberOfEventMemoryEntries(
    Dem_DTCOriginType DTCOrigin,
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) NumberOfEventMemoryEntries) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    uint8 memDest;
    memDest = Dem_GetInternalMemDest(DTCOrigin);
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_GETNUMBEROFEVENTMEMORYENTRIES, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (NumberOfEventMemoryEntries == NULL_PTR)
    {
        DEM_DET_REPORT(DEM_SID_GETNUMBEROFEVENTMEMORYENTRIES, DEM_E_PARAM_POINTER);
        return E_NOT_OK;
    }
    if (memDest == DEM_MEM_DEST_INVALID)
    {
        DEM_DET_REPORT(DEM_SID_GETNUMBEROFEVENTMEMORYENTRIES, DEM_E_WRONG_CONFIGURATION);
        return E_NOT_OK;
    }
    /*SWS_Dem_00651*/
    *NumberOfEventMemoryEntries = DemMemDestInfo[memDest].RecordNum;
    return E_OK;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Set the availability of a specific DemComponent.
 * ServiceId           0x2b
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ComponentId: Identification of a DemComponent.
 *                       AvailableStatus: This parameter specifies whether the respective
 *                          Component shall be available (TRUE) or not (FALSE).
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              E_OK: Operation was successful
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE) Dem_SetComponentAvailable(Dem_ComponentIdType ComponentId, boolean AvailableStatus)
{
#if (DEM_COMPONENT_NUM > 0)
    uint16 iloop = 0;
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg;
#endif

    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_SETCOMPONENTAVAILABLE, DEM_E_UNINIT);
        return E_NOT_OK;
    }
    if (ComponentId > DEM_COMPONENT_NUM)
    {
        DEM_DET_REPORT(DEM_SID_SETCOMPONENTAVAILABLE, DEM_E_WRONG_RECORDNUMBER);
        return E_NOT_OK;
    }
#if (DEM_COMPONENT_NUM > 0)
    ComponentId = Dem_GetEventInternalId(ComponentId);
    /*SWS_Dem_01135 */
    DemComponentStatus[ComponentId].availability = AvailableStatus;
    /*SWS_Dem_01136*/
    if (AvailableStatus == FALSE)
    {
        while (iloop < DEM_EVENT_PARAMETER_NUM)
        {
            pEventCfg = &DemPbCfgPtr->DemEventParameter[iloop];
            pEvent = Dem_GetEventInfo(iloop);
            if (pEventCfg->DemComponentClassRef == ComponentId)
            {
                if ((NULL_PTR != Dem_CheckEventMemEntryExistsAlready(iloop))
                    || (DEM_FLAGS_ISSET(pEvent->UdsStatus, DEM_UDS_STATUS_TF) == 0x01u))
                {
                    ;
                }
                else
                {
                    DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_AVAILABLE);
                }
            }
            iloop++;
        }
    }
    return E_OK;
#else
    (void)ComponentId;
    (void)AvailableStatus;
    return E_NOT_OK;
#endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#if (DEM_SUPPRESSION_SUPPORT == DEM_DTC_SUPPRESSION)
/*************************************************************************/
/*
 * Brief               Set the suppression status of a specific DTC.
 * ServiceId           0x33
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTC: Diagnostic Trouble Code
 *                       DTCFormat: Defines the input-format of the provided DTC value.
 *                       SuppressionStatus: This parameter specifies whether the respective
 *                       DTC shall be disabled (TRUE) or enabled (FALSE).
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK (Operation was successful)
 *                       E_NOT_OK (operation failed or event entry for this DTC still exists)
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(Std_ReturnType, DEM_CODE) Dem_SetDTCSuppression(uint32 DTC, Dem_DTCFormatType DTCFormat, boolean SuppressionStatus)
{
    uint16 iloop = 0;
    Std_ReturnType res = E_NOT_OK;
    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_SETDTCSUPPRESSION, DEM_E_UNINIT);
        return res;
    }
    if (DTC == DEM_DTC_CFG_INVALID)
    {
        DEM_DET_REPORT(DEM_SID_SETDTCSUPPRESSION, DEM_E_WRONG_RECORDNUMBER);
        return res;
    }
    DTC = Dem_GetDTCIndex(DTC, DTCFormat);
    while (iloop < DEM_EVENT_PARAMETER_NUM)
    {
        if (DemPbCfgPtr->DemEventParameter[iloop].DemDTCRef == DTC)
        {
            if (NULL_PTR != Dem_CheckEventMemEntryExistsAlready(iloop))
            {
                return res;
            }
            else
            {
                DemDTCGeneralStatus[DTC].SuppressionStatus = SuppressionStatus;
                res = E_OK;
            }
        }
        iloop++;
    }
    return res;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif

/*************************************************************************/
/*
 * Brief               Clears single DTCs, as well as groups of DTCs. This API is intended
                       for complex device driver. It can only be used through the RTE (due
                       to work-around described below SWS_Dem_00659), and therefore no
                       declaration is exported via Dem.h.
 * ServiceId           0x23
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTC:Defines the DTC in respective format, that shall be
 *                          cleared from the event memory. If the DTC fits to a
 *                          DTC group number, all DTCs of the group shall be cleared.
 *                       DTCFormat:Defines the input-format of the provided DTC value.
 *                       DTCOrigin:If the Dem supports more than one event memory
 *                          this parameter is used to select the source memory
 *                          the DTCs shall be read from.
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Status of the operation of type Dem_ReturnClearDTCType.
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
/* PRQA S 0624++ */ /* MISRA Rule 8.3 */
FUNC(Dem_ReturnClearDTCType, DEM_CODE)
Dem_ClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin)
/* PRQA S 0624-- */ /* MISRA Rule 8.3 */
{
    P2VAR(Dem_ClearDTCInfoType, AUTOMATIC, DEM_VAR) pClr; /* PRQA S 3432 */ /* MISRA Rule 20.7 */

    if (DemInitState != DEM_STATE_INIT)
    {
        DEM_DET_REPORT(DEM_SID_CLEARDTC, DEM_E_UNINIT);
        return DEM_CLEAR_FAILED;
    }

    pClr = &DemClearDTCInfo;
    if (DemClearDTCLock == DEM_CLEAR_LOCK)
    {
        if ((pClr->SaveDTCIndex == Dem_GetDTCIndex(DTC, DTCFormat)) && (pClr->SaveDTCFormat == DTCFormat)
            && (pClr->SaveDTCOrigin == DTCOrigin) && (pClr->SID == DEM_SID_CLEARDTC))
        {
            /*SWS_Dem_00663*/
            return DEM_CLEAR_PENDING;
        }
        else
        {
            /*SWS_Dem_00662 SWS_Dem_00664*/
            return DEM_CLEAR_BUSY;
        }
    }
    else if (DemClearDTCLock == DEM_CLEAR_NOT_LOCK)
    {
        DemClearDTCLock = DEM_CLEAR_LOCK; /*SWS_Dem_00661*/
        pClr->DTCIndex = Dem_GetDTCIndex(DTC, DTCFormat);
        pClr->DTCFormat = DTCFormat;
        pClr->DTCOrigin = DTCOrigin;
        pClr->SaveDTCIndex = Dem_GetDTCIndex(DTC, DTCFormat);
        pClr->SaveDTCFormat = DTCFormat;
        pClr->SaveDTCOrigin = DTCOrigin;
        pClr->SID = DEM_SID_CLEARDTC;
    }
    else
    {
        /*idle*/
    }
    /*SWS_Dem_00670 */
#if (DEM_CLEAR_DTCLIMITATION == DEM_ONLY_CLEAR_ALL_DTCS)
    if (DTCFormat != DEM_DTC_FORMAT_UDS || (DTC & 0xFFFFFF) != 0xFFFFFF)
    {
        Dem_ResetDemClearDTCInfo();
        return DEM_CLEAR_WRONG_DTC;
    }
#endif

    DTCOrigin = Dem_GetInternalMemDest(DTCOrigin);
    if (DTCOrigin == DEM_MEM_DEST_INVALID)
    {
        Dem_ResetDemClearDTCInfo();
        return DEM_CLEAR_WRONG_DTCORIGIN;
    }

    if ((DTC & 0xFFFFFFUL) == 0xFFFFFFUL)
    {
        pClr->ClearAllGroup = TRUE;
    }
#if (DEM_CLEAR_DTCLIMITATION == DEM_ALL_SUPPORTED_DTCS)
    else
    {

        pClr->ClearAllGroup = FALSE;
#if (DEM_GROUP_OF_DTC_NUM > 0)
        pClr->DTCGroupIndex = Dem_GetDTCGroupIndex(DTC);
        if (pClr->DTCGroupIndex == DEM_GROUP_OF_DTC_INVALID)
#endif
        {
            pClr->DTCIndex = Dem_GetDTCIndex(DTC, DTCFormat);
            if (pClr->DTCIndex == DEM_DTC_REF_INVALID)
            {
                Dem_ResetDemClearDTCInfo();
                return DEM_CLEAR_WRONG_DTC;
            }
        }
    }
#endif
    pClr->memDest = DTCOrigin;
    Dem_Pending = TRUE;
    Dem_ClearDTCProcess();
#if (DEM_CLEAR_DTCBEHAVIOR == DEM_CLRRESP_VOLATILE)
    /*SWS_Dem_00570*/
    Dem_ResetDemClearDTCInfo();
    return DEM_CLEAR_OK;
#elif (DEM_CLEAR_DTCBEHAVIOR == DEM_CLRRESP_NONVOLATILE_TRIGGER)
    /*SWS_Dem_00571*/
    DemClearNonvolatile = TRUE;
    Dem_ResetDemClearDTCInfo();
    return DEM_CLEAR_OK;
#elif (DEM_CLEAR_DTCBEHAVIOR == DEM_CLRRESP_NONVOLATILE_FINISH)
    DemClearNonvolatile = TRUE;
    if (DemClearNonvolatileOK == 0x00u)
    {
        /*SWS_Dem_00572*/
        DemClearNonvolatileOK = 0x02;
        Dem_ResetDemClearDTCInfo();
        return DEM_CLEAR_OK;
    }
    else if (DemClearNonvolatileOK == 0x01u)
    {
        /*SWS_Dem_01057*/
        DemClearNonvolatileOK = 0x02;
        return DEM_CLEAR_MEMORY_ERROR;
    }
    else
    {
        /*SWS_Dem_00663*/
        return DEM_CLEAR_PENDING;
    }
    return DEM_CLEAR_PENDING;
#endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/********[Scheduled functions]*********/
/*************************************************************************/
/*
 * Brief               Processes all not event based Dem internal functions.
 * ServiceId           0x55
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
FUNC(void, DEM_CODE) Dem_MainFunction(void)
{
    if (DemInitState == DEM_STATE_INIT)
    {
#if (DEM_ENABLE_CONDITION_NUM > 0)
        if (DemCheckEnableCondition != FALSE)
        {
            DemCheckEnableCondition = FALSE;
            Dem_SetEnableCondictionProcess();
        }
#endif
#if (DEM_STORAGE_CONDITION_NUM > 0)
        if (DemCheckStorageCondition != FALSE)
        {
            DemCheckStorageCondition = FALSE;
            Dem_SetStorageCondictionProcess();
        }
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
        Dem_DebounceTimerMain();
#endif
        Dem_EventQueueProcess();
#if (DEM_NVRAM_BLOCKID_NUM > 0)
        if (DemClearNonvolatile == TRUE)
        {
            /*clear done ,to write*/
            Dem_IntWriteNvRAM();
            DemClearNonvolatileOK = 0x00;
            DemClearNonvolatile = FALSE;
        }
#endif
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/********[I N T E R N A L F U N C T I O N   I M P L E M E N T A T I O N S]*****/
#if (DEM_ENABLE_CONDITION_NUM > 0)
/*************************************************************************/
/*
 * Brief               BRIEF DESCRIPTION
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              none
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_SetEnableCondictionProcess(void)
{
    uint16 iloop = 0;
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    boolean IsFulfilled;
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pGroup;
    while (iloop < DEM_EVENT_PARAMETER_NUM)
    {
        pEvent = Dem_GetEventInfo(iloop);
        IsFulfilled = TRUE;
        if (DemPbCfgPtr->DemEventParameter[iloop].DemEnableConditionGroupRef != DEM_ENABLE_CONDITION_GROUP_INVALID)
        {
            pGroup = &DemEnableConditionGroup[DemPbCfgPtr->DemEventParameter[iloop].DemEnableConditionGroupRef][0];
            IsFulfilled = Dem_CheckCondictionFulfilled(DemEnableConditionStatus, pGroup, DEM_ENABLE_CONDITION_NUM_BYTE);
        }
        if (IsFulfilled == TRUE)
        {
            if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_ENABLED_CONDICTION))
            {
                DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_ENABLED_CONDICTION);
                /* req SWS_Dem_00681 Monitor re-initialization  */
                if (DemPbCfgPtr->DemEventParameter[(iloop)].DemCallbackInitMForE != NULL_PTR)
                {
                    DemPbCfgPtr->DemEventParameter[(iloop)].DemCallbackInitMForE(DEM_INIT_MONITOR_REENABLED);
                }
            }
        }
        else
        {
            DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_ENABLED_CONDICTION);
            Dem_DebounceFreeze(iloop); /*SWS_Dem_00655*/
        }
        iloop++;
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif
#if (DEM_STORAGE_CONDITION_NUM > 0)
/*************************************************************************/
/*
 * Brief               Dem_SetStorageCondictionProcess
 * ServiceId           --
 * Sync/Async          Synchronous-
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_SetStorageCondictionProcess(void)
{
    uint16 iloop = 0;
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent; /* PRQA S 3432 */ /* MISRA Rule 20.7 */
    boolean IsFulfilled;
    boolean IsReplacement;
    P2CONST(uint8, AUTOMATIC, DEM_CONST) pGroup;
    uint8 index;
    uint8 Conditionindex;
    uint8 Counter;
    uint8 Mask;
    while (iloop < DEM_EVENT_PARAMETER_NUM)
    {
        pEvent = Dem_GetEventInfo(iloop);
        IsReplacement = FALSE;
        IsFulfilled = TRUE;
        if (DemPbCfgPtr->DemEventParameter[iloop].DemStorageConditionGroupRef != DEM_STORAGE_CONDITION_GROUP_INVALID)
        {
            pGroup = &DemStorageConditionGroup[DemPbCfgPtr->DemEventParameter[iloop].DemStorageConditionGroupRef][0];
            IsFulfilled =
                Dem_CheckCondictionFulfilled(DemStorageConditionStatus, pGroup, DEM_STORAGE_CONDITION_NUM_BYTE);
        }
        if (IsFulfilled == TRUE)
        {
            if (0x00u == DEM_FLAGS_ISSET(pEvent->Status, DEM_EVENT_STATUS_STORAGE_CONDICTION))
            {
                DEM_FLAGS_SET(pEvent->Status, DEM_EVENT_STATUS_STORAGE_CONDICTION);
                /*SWS_Dem_01089 */
                index = 0;
                Conditionindex = 0;
                /* PRQA S 2877++ */ /* MISRA Dir 4.1 */
                while ((index < DEM_STORAGE_CONDITION_NUM_BYTE) && (IsReplacement == FALSE))
                /* PRQA S 2877-- */ /* MISRA Dir 4.1 */
                {
                    Counter = 0;
                    Mask = 0x01;
                    /* PRQA S 2877++ */ /* MISRA Dir 4.1 */
                    while ((Conditionindex < DEM_STORAGE_CONDITION_NUM) && (IsReplacement == FALSE) && (Counter < 8u))
                    /* PRQA S 2877-- */ /* MISRA Dir 4.1 */
                    {
                        if (((DemStorageConditionGroup[DemPbCfgPtr->DemEventParameter[iloop]
                                                           .DemStorageConditionGroupRef][index]
                              & Mask)
                             != 0u)
                            && (DemStorageCondition[Conditionindex].DemStorageConditionReplacementEventRef
                                != DEM_EVENT_PARAMETER_INVALID))
                        {
                            (void)Dem_EventQueueAdd(
                                Dem_GetEventExternalId(
                                    DemStorageCondition[Conditionindex].DemStorageConditionReplacementEventRef),
                                DEM_EVENT_STATUS_PASSED);
                            /* SWS_Dem_01113  Monitor re-initialization  */
                            if (DemPbCfgPtr->DemEventParameter[(iloop)].DemCallbackInitMForE != NULL_PTR)
                            {
                                DemPbCfgPtr->DemEventParameter[(iloop)].DemCallbackInitMForE(
                                    DEM_INIT_MONITOR_STORAGE_REENABLED);
                            }
                            IsReplacement = TRUE; /* PRQA S 2982 */ /* MISRA Rule 2.2 */
                        }
                        Counter++; /* PRQA S 2982 */ /* MISRA Rule 2.2 */
                        Conditionindex++;
                        Mask = Mask << 1u; /* PRQA S 2982 */ /* MISRA Rule 2.2 */
                    }
                    index++; /* PRQA S 2982 */ /* MISRA Rule 2.2 */
                }
            }
        }
        else
        {
            DEM_FLAGS_CLR(pEvent->Status, DEM_EVENT_STATUS_STORAGE_CONDICTION);
        }
        iloop++;
    }
    return;
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

#endif

/*************************************************************************/
/*
 * Brief               Dem_EventStatusPrepassedDebounce
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEvent
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_EventStatusPrepassedDebounce(
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg,
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    switch (pEventCfg->AlgorithmType)
    {
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0u)
    case DEM_DEBOUNCE_COUNTER_BASED:
        if (DemDebounceCounterInfo[pEventCfg->AlgorithmIndex].CurStatus == DEM_EVENT_STATUS_PASSED)
        {
            Dem_EventQueueAddDebouncePassed(pEvent);
        }
        break;
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0u)
    case DEM_DEBOUNCE_TIME_BASE:
        if (DemDebounceTimerInfo[pEventCfg->AlgorithmIndex].CurStatus == DEM_EVENT_STATUS_PASSED)
        {
            Dem_EventQueueAddDebouncePassed(pEvent);
        }
        break;
#endif
    default:
        /*idle*/
        break;
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_EventStatusPrefailedDebounce
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEvent
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_EventStatusPrefailedDebounce(
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg,
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
    switch (pEventCfg->AlgorithmType)
    {
#if (DEM_DEBOUNCE_COUNTER_BASED_CLASS_NUM > 0)
    case DEM_DEBOUNCE_COUNTER_BASED:
        if ((pEventCfg->AlgorithmIndex < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM)
            && (DemDebounceCounterInfo[pEventCfg->AlgorithmIndex].CurStatus == DEM_EVENT_STATUS_FAILED))
        {
            Dem_EventQueueAddDebounceFailed(pEvent);
        }
        break;
#endif
#if (DEM_DEBOUNCE_TIME_BASE_CLASS_NUM > 0)
    case DEM_DEBOUNCE_TIME_BASE:
        if ((pEventCfg->AlgorithmIndex < DEM_DEBOUNCE_COUNTER_BASED_EVENT_NUM)
            && (DemDebounceTimerInfo[pEventCfg->AlgorithmIndex].CurStatus == DEM_EVENT_STATUS_FAILED))
        {
            Dem_EventQueueAddDebounceFailed(pEvent);
        }
        break;
#endif
    default:
        /*idle*/
        break;
    }
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*************************************************************************/
/*
 * Brief               Dem_ProcessEventStatus
 * ServiceId           --
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      pEvent
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/*************************************************************************/
#define DEM_START_SEC_CODE
#include "Dem_MemMap.h"
static FUNC(void, DEM_CODE) Dem_ProcessEventStatus(
    Dem_EventStatusType EventStatus,
    P2CONST(Dem_EventParameterType, AUTOMATIC, DEM_CONST) pEventCfg,
    P2VAR(Dem_EventRelateInformationType, AUTOMATIC, DEM_VAR) pEvent) /* PRQA S 3432 */ /* MISRA Rule 20.7 */
{
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
    uint8 OldStatus;
    OldStatus = pEvent->UdsStatus;
#endif
    /*SWS_Dem_00036*/
    if (EventStatus == DEM_EVENT_STATUS_FAILED)
    {
        Dem_EventQueueAddDebounceFailed(pEvent);
    }
    else if (EventStatus == DEM_EVENT_STATUS_PASSED)
    {
        Dem_EventQueueAddDebouncePassed(pEvent);
    }
    else if (EventStatus == DEM_EVENT_STATUS_PREPASSED)
    {
        Dem_EventStatusPrepassedDebounce(pEventCfg, pEvent);
    }
    else if (EventStatus == DEM_EVENT_STATUS_PREFAILED)
    {
        Dem_EventStatusPrefailedDebounce(pEventCfg, pEvent);
    }
    else
    {
        /*do nothing*/
    }
#if (DEM_TRIGGER_FIM_REPORTS == STD_ON)
    if (OldStatus != pEvent->UdsStatus)
    {
        (void)FiM_DemTriggerOnEventStatus(pEvent->IntId + 1u, OldStatus, pEvent->UdsStatus);
    }
#endif
}
#define DEM_STOP_SEC_CODE
#include "Dem_MemMap.h"

/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/
