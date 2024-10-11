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
**  FILENAME    : Dem.h                                                       **
**                                                                            **
**  Created on  :                                                             **
**  Author      : tao.yu                                                      **
**  Vendor      : i-soft                                                      **
**  DESCRIPTION : Type definition and API declaration of DEM                  **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

#ifndef DEM_H
#define DEM_H

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*  <VERSION>    <DATE>    <AUTHOR>    <REVISION LOG>
 *  V1.0.0       2018-4-20  tao.yu    Initial version
 *  V1.0.1       2019-9-17  tao.yu    fix some bug,change event callback
 *  V1.0.2       2019-12-25  tao.yu    QAC fix
 *  V1.0.3       2020-1-7   tao.yu    Commercial project problem modification
 *  V1.0.4       2020-3-10   tao.yu    enable condition has no impact on
 * Dem_ResetEventDebounceStatus,  Dem_ResetEventStatus and Dem_<...>ClearDTC.
 *  V2.0.0       2020-07-15  pengfei.zhu    fix bugs by PIM; optimized code
 *  V2.0.1       2020-09-15  pengfei.zhu    QAC test
 *  V2.0.2       2022-08-18  tao.yu         fix PRD0032020-213
 *  V2.0.3       2022-11-22  tao.yu         fix PRD0032020-442
 *  V2.0.4       2023-03-03  tao.yu         fix CPT-36
 *  V2.0.5       2023-03-29  tao.yu         fix PRD0042022-716 PRD0042022-718 CPT-49 CPT-50  CPT-56 remove
 * DemDTCDataBuffer,Modify precompilation
 *  V2.0.6       2023-05-18  peng.wu/tao.yu fix CPT-412/fix CPT-549、CPT-592、CPT-549（add OCC6、OCC4）
 *  V2.0.7       2023-06-12  xinrun.wang    1. fix CPT-5692, SetEventAvailable true restore suppression
 *                                          2. fix CPT-5698, GetNumberOfFilteredDTC and GetNextFilteredDTC
 *                                             fix for suppression
 *                                          3. fix CPT-5892, avoid macro redefinition
 *  V2.0.8       2023-07-04  peng.wu        1. fix CPT-6021, modify parameter type "CONSTP2VAR"
 *                                          2. fix CPT-6022, agingcounter read fail
 *  V2.0.9       2023-07-21  xue.han        1. fix CPT-6195, DTCSetting NRC
 *  V2.0.10      2023-07-26  tao.yu         fix CPT-6271 Dem_DcmGetNumberOfFilteredDTC uds status get from DTC
 *  V2.0.11      2023-8-3    tao.yu         QAC change
 *  V2.0.12      2023-8-11   peng.wu        fix CPT-6021 CPT-6375 CPT-6373
 *                                          Modify macro judgment in Dem_DebounceFreeze, Update Cfg Req
 *  V2.0.13      2023-8-11   xue.ham        QAC change
 *  V2.0.14      2023-08-21  peng.wu        1. fix CPT-6470, Update DTC status in Dem_EventQueueAddDebounceFailed
 *  V2.0.15      2023-08-23  tao.yu         Add DTC separate storage
 *  V2.0.16      2023-09-1   tao.yu         CPT-6784,remove prepass Soft Filter
 *  V2.0.17      2023-09-5   peng.wu        CPT-6806,Fix code format; Update version info and Dem_GetVersionInfo
 *******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Dem_Cfg.h"
#include "Dem_CfgTypes.h"
#include "Rte_Dcm_Type.h"
#include "Compiler.h"
#if (DEM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define DEM_VENDOR_ID                62U
#define DEM_MODULE_ID                54U
#define DEM_INSTANCE_ID              1U
#define DEM_AR_RELEASE_MAJOR_VERSION 4U
#define DEM_AR_RELEASE_MINOR_VERSION 2U
#define DEM_AR_RELEASE_PATCH_VERSION 2U
#define DEM_SW_MAJOR_VERSION         2U
#define DEM_SW_MINOR_VERSION         0U
#define DEM_SW_PATCH_VERSION         17U

#if (STD_ON == DEM_DEV_ERROR_DETECT)
#define DEM_DET_REPORT(ApiId, ErrorId) ((void)Det_ReportError(DEM_MODULE_ID, DEM_INSTANCE_ID, (ApiId), (ErrorId)))
#else
#define DEM_DET_REPORT(ApiId, ErrorId)
#endif

#define DEM_UNUSED(x) (void)(x)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

extern CONST(Dem_ConfigType, AUTOMATIC) DemPbCfg; /*for Dem_ReportErrorStatus*/
/*******************************************************************************
**                      Global Functions                                      **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               Initializes the internal states necessary to process events reported by BSW-modules.
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr: Pointer to Post build configuration data.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/

/* PRQA S 3451,3449,0624++ */ /* MISRA Rule 8.5,Rule 8.5,Rule 8.3 */
extern FUNC(void, DEM_CODE) Dem_PreInit(void);

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

extern FUNC(void, DEM_CODE) Dem_Init(P2CONST(Dem_ConfigType, AUTOMATIC, DEM_CONST_PBCFG) ConfigPtr);

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
extern FUNC(void, DEM_CODE) Dem_GetVersionInfo(Std_VersionInfoType* versionInfo);
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

extern FUNC(void, DEM_CODE) Dem_Shutdown(void);

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

extern FUNC(void, DEM_CODE) Dem_ReportErrorStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);

#if (DEM_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY) /*SWS_Dem_00687]*/
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

/* req SWS_Dem_01106 */
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventAvailable(Dem_EventIdType EventId, boolean AvailableStatus);

#endif /*#if (DEM_AVAILABILITY_SUPPORT == DEM_EVENT_AVAILABILITY)*/

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

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventStatus(Dem_EventIdType EventId, Dem_EventStatusType EventStatus);

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

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_ResetEventDebounceStatus(Dem_EventIdType EventId, Dem_DebounceResetStatusType DebounceResetStatus);

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
extern FUNC(Std_ReturnType, DEM_CODE) Dem_ResetEventStatus(Dem_EventIdType EventId);

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
extern FUNC(Std_ReturnType, DEM_CODE) Dem_PrestoreFreezeFrame(Dem_EventIdType EventId);

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
FUNC(Std_ReturnType, DEM_CODE) Dem_ClearPrestoredFreezeFrame(Dem_EventIdType EventId);
#endif /* DEM_FFPRESTORAGE_SUPPORT == STD_ON */

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

extern FUNC(Std_ReturnType, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_GetComponentFailed(Dem_ComponentIdType ComponentId, P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) ComponentFailed);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

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

extern FUNC(Std_ReturnType, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_GetEventStatus(Dem_EventIdType EventId, P2VAR(Dem_UdsStatusByteType, AUTOMATIC, DEM_APPL_DATA) EventStatusByte);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

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

extern FUNC(Std_ReturnType, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_GetEventFailed(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventFailed);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

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

extern FUNC(Std_ReturnType, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_GetEventTested(Dem_EventIdType EventId, P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) EventTested);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

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

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_SetOperationCycleState(uint8 OperationCycleId, Dem_OperationCycleStateType CycleState);

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

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetOperationCycleState(
    uint8 OperationCycleId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_OperationCycleStateType, AUTOMATIC, DEM_APPL_DATA) CycleState);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

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

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetAgingCycleState(uint8 OperationCycleId);

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

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetWIRStatus(Dem_EventIdType EventId, boolean WIRStatus);

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

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDebouncingOfEvent(
    Dem_EventIdType EventId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(Dem_DebouncingStateType, AUTOMATIC, DEM_APPL_DATA) DebouncingState);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

/*************************************************************************/
/*
 * Brief               Gets the DTC of an event.
 * ServiceId           0x0d
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      EventId:Identification of an event by assigned EventId.
 *                       DTCFormat: Defines the output-format of the requested DTCvalue.
 * Param-Name[out]     DTCOfEvent: Receives the DTC value in respective format returned
 *                                   by this function.
 * Param-Name[in/out]  None
 * Return              E_OK: get of DTC was successful
 *                       E_NOT_OK: the call was not successful
 *                       DEM_E_NO_DTC_AVAILABLE: there is no DTC configured in the requested format
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDTCOfEvent(
    Dem_EventIdType EventId,
    Dem_DTCFormatType DTCFormat,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint32, AUTOMATIC, DEM_APPL_DATA) DTCOfEvent);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

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
/* PRQA S 1330 ++ */ /* MISRA Rule 8.3*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEnableCondition(uint8 EnableConditionID, boolean ConditionFulfilled);
/* PRQA S 1330 -- */ /* MISRA Rule 8.3*/
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

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetStorageCondition(uint8 StorageConditionID, boolean ConditionFulfilled);

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

extern FUNC(Std_ReturnType, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_GetFaultDetectionCounter(Dem_EventIdType EventId, P2VAR(sint8, AUTOMATIC, DEM_APPL_DATA) FaultDetectionCounter);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

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

extern FUNC(Std_ReturnType, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_GetIndicatorStatus(uint8 IndicatorId, P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

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

extern FUNC(Std_ReturnType, DEM_CODE)
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    Dem_SetIndicatorStatus(uint8 IndicatorId, P2VAR(Dem_IndicatorStatusType, AUTOMATIC, DEM_APPL_DATA) IndicatorStatus);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

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

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventFreezeFrameDataEx(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    uint16 DataId,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint16* BufSize);

/*************************************************************************/
/*
 * Brief               Gets the data of an extended data record by event.
 * ServiceId           0x30
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      EventId : Identification of an event by assigned EventId.
 *                       RecordNumber: Identification of requested Extended data record.
 *                       Valid values are between 0x01 and 0xEF as defined in ISO14229-1.
 * Param-Name[out]     DestBuffer: This parameter contains a byte pointer that points
 *                          to the buffer, to which the extended data shall bewritten to.
 *                          The format is raw hexadecimal values and contains no header-information.
 * Param-Name[in/out]  BufSize:When the function is called this parameter contains
                            the maximum number of data bytes that can be written to the buffer.
                            The function returns the actual number of written
                            data bytes in this parameter.
 * Return              E_OK: Operation was successful
 *                       DEM_E_NODATAAVAILABLE: The requested event data is not currently
 *                              stored (but the request was valid)
 *                       DEM_E_WRONG_RECORDNUMBER: The requested record number is not supported by the event
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventExtendedDataRecordEx(
    Dem_EventIdType EventId,
    uint8 RecordNumber,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) DestBuffer,
    /* PRQA S 3432-- */ /* MISRA Rule 20.7 */
    uint16* BufSize);
/* PRQA S 1330 */ /* MISRA Rule 8.3*/

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

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetEventMemoryOverflow(
    Dem_DTCOriginType DTCOrigin,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(boolean, AUTOMATIC, DEM_APPL_DATA) OverflowIndication);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

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

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetNumberOfEventMemoryEntries(
    Dem_DTCOriginType DTCOrigin,
    /* PRQA S 3432++ */ /* MISRA Rule 20.7 */
    P2VAR(uint8, AUTOMATIC, DEM_APPL_DATA) NumberOfEventMemoryEntries);
/* PRQA S 3432-- */ /* MISRA Rule 20.7 */

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

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_SetComponentAvailable(Dem_ComponentIdType ComponentId, boolean AvailableStatus);

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
 * Return              E_OK (Operation was successful),
 *                       E_NOT_OK (operation failed or event entry for this DTC still exists)
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_SetDTCSuppression(uint32 DTC, Dem_DTCFormatType DTCFormat, boolean SuppressionStatus);

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
FUNC(Dem_ReturnClearDTCType, DEM_CODE)
Dem_ClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin);

/*************************************************************************/
/*
 * Brief               Gets the data of an most recent freeze frame record by event.
                        The OBD-II freeze frame is not returned by this function
 * ServiceId           0x41
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      EventId: Identification of an event by assigned EventId.
 *                          this parameter is used to select the source memory
 *                          the number of entries shall be read from.
 * Param-Name[out]     DestBuffer: This parameter contains a byte pointer that points
                        to the buffer, to which the freeze frame record shall
                        be written to. The format is raw hexadecimal values
                        and contains no header-information.
 *                          requested event memory.
 * Param-Name[in/out]  BufSize:When the function is called this parameter contains
                        the maximum number of data bytes that can be written to the buffer.
 * Return              E_OK: Operation was successful.
                        DEM_E_NODATAAVAILABLE: The requested event
                        data is not currently stored (but the request wasvalid).
                        DEM_E_PENDING: The requested data is currently
                        transported from NvM and needs to be requestedagain
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_DltGetMostRecentFreezeFrameRecordData(Dem_EventIdType EventId, uint8* DestBuffer, uint16* BufSize);

/*************************************************************************/
/*
 * Brief               Gets the data of all extended data records of an event.
 * ServiceId           0x40
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      EventId: Identification of an event by assigned EventId.
 *                          this parameter is used to select the source memory
 *                          the number of entries shall be read from.
 * Param-Name[out]     DestBuffer:This parameter contains a byte pointer that points
                            to the buffer, to which the extended data shall be
                            written to. The format is raw hexadecimal values
                            and contains no header-information.
 * Param-Name[in/out]  BufSize:When the function is called this parameter contains
                        the maximum number of data bytes that can be written to the buffer.
 * Return              E_OK: Operation was successful.
                        DEM_E_NODATAAVAILABLE: The requested event
                        data is not currently stored (but the request was valid).
                        DEM_E_PENDING: The requested data is currently
                        transported from NvM and needs to be requested again.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_DltGetAllExtendedDataRecords(Dem_EventIdType EventId, uint8* DestBuffer, uint16* BufSize);

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

extern FUNC(void, DEM_CODE) Dem_MainFunction(void);

#if (DEM_J1939_SUPPORT == STD_ON)
#if (DEM_J1939_READING_DTC_SUPPORT == STD_ON)
/*************************************************************************/
/*
 * Brief               The function sets the DTC filter for a specific node and returns the composite lamp status of the
 filtered DTCs
 * ServiceId           0x90
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTCStatusFilter: The following types are available:
                        DEM_J1939DTC_ACTIVE
                        DEM_J1939DTC_PREVIOUSLY_ACTIVE
                        DEM_J1939DTC_PENDING
                        DEM_J1939DTC_PERMANENT
                        DEM_J1939DTC_CURRENTLY_ACTIVE
 *                      DTCKind: Defines the functional group of DTCs to be reported
 *                      node:Nm node Id
 * Param-Name[out]     LampStatus:Receives the commulated lamp status
 * Param-Name[in/out]  none
 * Return              Status of the operation to (re-)set a DTC filter.
 */
/*************************************************************************/

extern FUNC(Dem_ReturnSetFilterType, DEM_CODE) Dem_J1939DcmSetDTCFilter(
    Dem_J1939DcmDTCStatusFilterType DTCStatusFilter,
    Dem_DTCKindType DTCKind,
    uint8 node,
    Dem_J1939DcmLampStatusType* LampStatus);

/*************************************************************************/
/*
 * Brief               Gets the number of currently filtered DTCs set by the function Dem_J1939DcmSetDTCFilter
 * ServiceId           0x91
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     NumberOfFilteredDTC: The number of DTCs matching the defined status mask.
 * Param-Name[in/out]  none
 * Return              Status of the operation to retrieve a number of DTC from the Dem
 */
/*************************************************************************/

extern FUNC(Dem_ReturnGetNumberOfFilteredDTCType, DEM_CODE)
    Dem_J1939DcmGetNumberOfFilteredDTC(uint16* NumberOfFilteredDTC);

/*************************************************************************/
/*
 * Brief               Gets the next filtered J1939 DTC.
 * ServiceId           0x92
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     J1939DTC: Receives the J1939DTC value. If the return value of
                        the function is other than DEM_FILTERED_OK this
                        parameter does not contain valid data.
                        OccurenceCounter:This parameter receives the corresponding occurrence counter. If the return
 value of the function call is other than DEM_FILTERED_OK this parameter does not contain valid data.
 * Param-Name[in/out]  none
 * Return              Status of the operation to retrieve a DTC from the Dem.
 */
/*************************************************************************/

extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
    Dem_J1939DcmGetNextFilteredDTC(uint32* J1939DTC, uint8* OccurenceCounter);

#endif

#if (DEM_J1939_DM31_SUPPORT == STD_ON)
/*************************************************************************/
/*
 * Brief               The function sets the filter to the first applicable DTC for the DM31 response for a specific
 * node ServiceId           0x93 Sync/Async          Synchronous Reentrancy          Non Reentrant Param-Name[in] Nm
 * node Id of requesting client Param-Name[out]     None Param-Name[in/out]  none Return              Status of the
 * operation to retrieve a DTC from the Dem.
 */
/*************************************************************************/

extern FUNC(void, DEM_CODE) Dem_J1939DcmFirstDTCwithLampStatus(uint8 node);

/*************************************************************************/
/*
 * Brief               Gets the next filtered J1939 DTC for DM31 including current LampStatus.
 * ServiceId           0x94
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     LampStatus:Receives the lamp status returned by this function.
 *                      If the return value of the function is other than
                        DEM_FILTERED_OK this parameter does not contain valid data.
                        J1939DTC:Receives the J1939DTC value. If the return value of
                        the function is other than DEM_FILTERED_OK this
                        parameter does not contain valid data.
                        OccurenceCounter:This parameter receives the corresponding occurrence counter.
                        If the return value of the function call
                        is other than DEM_FILTERED_OK this parameter
                        does not contain valid data.
 * Param-Name[in/out]  none
 * Return              Status of the operation to retrieve a DTC from the Dem.
 */
/*************************************************************************/

extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE) Dem_J1939DcmGetNextDTCwithLampStatus(
    Dem_J1939DcmLampStatusType* LampStatus,
    uint32* J1939DTC,
    uint8* OccurenceCounter);

#endif

#if (DEM_J1939_CLEAR_DTC_SUPPORT == STD_ON)
/*************************************************************************/
/*
 * Brief               Clears active DTCs as well as previously active DTCs
 * ServiceId           0x95
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTCTypeFilter:The following types are available:
                        DEM_J1939DTC_CLEAR_ALL
                        DEM_J1939DTC_CLEAR_PREVIOUSLY_ACTIVE
 *                      node: Nm node Id of requesting client
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Status of the operation of type Dem_ReturnClearDTCType.
 */
/*************************************************************************/

extern FUNC(Dem_ReturnClearDTCType, DEM_CODE)
    Dem_J1939DcmClearDTC(Dem_J1939DcmSetClearFilterType DTCTypeFilter, uint8 node);

#endif

#if (DEM_J1939_EXPANDED_FREEZE_FRAME_SUPPORT == STD_ON)
#if (DEM_J1939_FREEZE_FRAME_SUPPORT == STD_ON)
/*************************************************************************/
/*
 * Brief               The function sets the FreezeFrame filter for a specific node
 * ServiceId           0x96
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      FreezeFrameKind: The following types are available:
                        DEM_J1939DCM_FREEZEFRAME
                        DEM_J1939DCM_EXPANDED_FREEZEFRAME
                        DEM_J1939DCM_SPNS_IN_EXPANDED_
                        FREEZEFRAME
                        node:Nm node Id of requesting client
 * Param-Name[out]     None
 * Param-Name[in/out]  none
 * Return              Status of the operation to (re-)set a FreezeFrame filter.
 */
/*************************************************************************/

extern FUNC(Dem_ReturnSetFilterType, DEM_CODE)
    /* PRQA S 0779++ */ /* MISRA Rule 5.2 */
    Dem_J1939DcmSetFreezeFrameFilter(Dem_J1939DcmSetFreezeFrameFilterType FreezeFrameKind, uint8 node);
/* PRQA S 0779-- */ /* MISRA Rule 5.2 */

/*************************************************************************/
/*
 * Brief               Gets next freeze frame data. The function stores the data in the provided DestBuffer
 * ServiceId           0x97
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     J1939DTC:Receives the J1939DTC value. If the return value of
                        the function is other than DEM_FILTERED_OK this
                        parameter does not contain valid data
                        OccurenceCounter:This parameter receives the corresponding occurrence counter.
                        If the return value of the function call
                        is other than DEM_FILTERED_OK this parameter
                        does not contain valid data.
 * Param-Name[in/out]  DestBuffer:This parameter contains a byte pointer that points
                        to the buffer, to which the freeze frame data record
                        shall be written to.
                        BufSize:When the function is called this parameter contains
                        the maximum number of data bytes that can be written to the buffer.
 * Return              Status of the operation to retrieve freeze frame data by DTC.
 */
/*************************************************************************/

extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
    Dem_J1939DcmGetNextFreezeFrame(uint32* J1939DTC, uint8* OccurenceCounter, uint8* DestBuffer, uint16* BufSize);

#endif

/*************************************************************************/
/*
 * Brief               Gets next SPN.
 * ServiceId           0x98
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     SPNSupported: This parameter contains the next SPN in the ExpandedFreezeFrame
                        SPNDataLength: This parameter contains the corresponding dataLength of the SPN
 * Param-Name[in/out]  None
 * Return              Status of the operation to retrieve freeze frame data by DTC.
 */
/*************************************************************************/

extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
    Dem_J1939DcmGetNextSPNInFreezeFrame(uint32* SPNSupported, uint8* SPNDataLength);

#endif

#if (DEM_J1939_RATIO_SUPPORT == STD_ON)
/*************************************************************************/
/*
 * Brief               The function sets the Ratio filter for a specific node and returns the corresponding Ignition
 Cycle Counter and General Denominator.
 * ServiceId           0x99
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      node:Nm node Id of requesting client
 * Param-Name[out]     IgnitionCycleCounter: Ignition Cycle Counter
                        OBDMonitoringConditionsEncountered: OBD Monitoring Conditions Encountered
 * Param-Name[in/out]  None
 * Return              Status of the operation to (re-)set a DTC filter.
 */
/*************************************************************************/

extern FUNC(Dem_ReturnSetFilterType, DEM_CODE)
    Dem_J1939DcmSetRatioFilter(uint16* IgnitionCycleCounter, uint16* OBDMonitoringConditionsEncountered, uint8 node);

/*************************************************************************/
/*
 * Brief               The function sets the Ratio filter for a specific node and returns the corresponding Ignition
 Cycle Counter and General Denominator.
 * ServiceId           0x9a
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     SPN:Receives the SPN of the applicaple system monitor. If the return value of the function is
 other than DEM_FILTERED_OK this parameter does not contain valid data. Numerator:Receives the Numerator of the
 applicable system monitor. If the return value of the function is other than DEM_FILTERED_OK this parameter does not
                        contain valid data.
                        Denominator:Receives the Denominator of the applicable system
                        monitor. If the return value of the function is other
                        than DEM_FILTERED_OK this parameter does not
                        contain valid data.
 * Param-Name[in/out]  None
 * Return              Status of the operation to (re-)set a DTC filter.
 */
/*************************************************************************/

extern FUNC(Dem_ReturnGetNextFilteredElementType, DEM_CODE)
    Dem_J1939DcmGetNextFilteredRatio(uint16* SPN, uint16* Numerator, uint16* Denominator);

#endif

#if (DEM_J1939_READINESS1_SUPPORT == STD_ON)
/*************************************************************************/
/*
 * Brief               Service to report the value of Diagnostic Readiness 1 (DM05) computed by the Dem.
 * ServiceId           0x9b
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      node:Nm node Id of requesting client
 * Param-Name[out]     DataValue:Buffer of 8 bytes containing the contents of Diagnostic Readiness 1 (DM05) computed by
 the Dem.
 * Param-Name[in/out]  None
 * Return              E_OK: Operation was successful
                        E_NOT_OK: Operation failed
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_J1939DcmReadDiagnosticReadiness1(Dem_J1939DcmDiagnosticReadiness1Type* DataValue, uint8 node);

#endif

#if (DEM_J1939_READINESS2_SUPPORT == STD_ON)
/*************************************************************************/
/*
 * Brief               Service to report the value of Diagnostic Readiness 2 (DM21) computed by the Dem.
 * ServiceId           0x9c
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      node:Nm node Id of requesting client
 * Param-Name[out]     DataValue:Buffer of 8 bytes containing the contents of Diagnostic Readiness 2 (DM21) computed by
 the Dem.
 * Param-Name[in/out]  None
 * Return              E_OK: Operation was successful
                        E_NOT_OK: Operation failed
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    /* PRQA S 0779,0777++ */ /* MISRA Rule 5.2,5.1 */
    Dem_J1939DcmReadDiagnosticReadiness2(Dem_J1939DcmDiagnosticReadiness2Type* DataValue, uint8 node);
/* PRQA S 0779,0777-- */ /* MISRA Rule 5.2,5.1 */

#endif

#if (DEM_J1939_READINESS3_SUPPORT == STD_ON)
/*************************************************************************/
/*
 * Brief               Service to report the value of Diagnostic Readiness 3 (DM26) computed by the Dem.
 * ServiceId           0x9d
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      node:Nm node Id of requesting client
 * Param-Name[out]     DataValue:Buffer of 8 bytes containing the contents of Diagnostic Readiness 3 (DM26) computed by
 the Dem.
 * Param-Name[in/out]  None
 * Return              E_OK: Operation was successful
                        E_NOT_OK: Operation failed
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    /* PRQA S 0779,0777++ */ /* MISRA Rule 5.2,5.1 */
    Dem_J1939DcmReadDiagnosticReadiness3(Dem_J1939DcmDiagnosticReadiness3Type* DataValue, uint8 node);
/* PRQA S 0779,0777-- */ /* MISRA Rule 5.2,5.1 */

#endif
#endif /*#if (DEM_J1939_SUPPORT == STD_ON)*/

#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)
/*************************************************************************/
/*
 * Brief               Service is used for requesting IUMPR data according to InfoType 08.
 * ServiceId           0x6b
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      OpStatus Only DCM_INITIAL will appear, because this API
                        behaves synchronous.
 * Param-Name[out]     Iumprdata08 Buffer containing the number of data elements (as
                        defined in ISO-15031-5) and contents of InfoType
                        08. The buffer is provided by the Dcm.
 * Param-Name[in/out]  Iumprdata08BufferSize: The maximum number of data bytes that can be
                        written to the Iumprdata08 Buffer.
 * Return              Always E_OK is returned.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_DcmGetInfoTypeValue08(Dcm_OpStatusType OpStatus, uint8* Iumprdata08, uint8* Iumprdata08BufferSize);

/*************************************************************************/
/*
 * Brief               Service is used for requesting IUMPR data according to InfoType 0B.
 * ServiceId           0x6c
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      OpStatus Only DCM_INITIAL will appear, because this API
                        behaves synchronous.
 * Param-Name[out]     Iumprdata0B Buffer containing the number of data elements (as
                        defined in ISO-15031-5) and contents of InfoType
                        08. The buffer is provided by the Dcm.
 * Param-Name[in/out]  Iumprdata0BBufferSize: The maximum number of data bytes that can be
                        written to the Iumprdata08 Buffer.
 * Return              Always E_OK is returned.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_DcmGetInfoTypeValue0B(Dcm_OpStatusType OpStatus, uint8* Iumprdata0B, uint8* Iumprdata0BBufferSize);

/*************************************************************************/
/*
 * Brief               Reports the value of a requested "availability-OBDMID" to the DCM upon a Service 06 request.
 * ServiceId           0xa3
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Obdmid Availablity OBDMID (00,20, 40...)
 * Param-Name[out]     Obdmidvalue Bit coded information on the support of OBDMIDs.
 * Param-Name[in/out]  None
 * Return              E_OK: Report of DTR result successful
                        E_NOT_OK: Report of DTR result failed
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetAvailableOBDMIDs(uint8 Obdmid, uint32* Obdmidvalue);

/*************************************************************************/
/*
 * Brief               Gets the number of TIDs per (functional) OBDMID.
 * ServiceId           0xa4
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Obdmid OBDMID subject of the request to identify the number of assigned TIDs
 * Param-Name[out]     numberOfTIDs Number of assigned TIDs for the requested OBDMID.
 *                      Used as loop value for the DCM to retrieve all OBD/TID result data
 * Param-Name[in/out]  None
 * Return              E_OK: get number of TIDs successful
                        E_NOT_OK: get number of TIDs failed
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetNumTIDsOfOBDMID(uint8 Obdmid, uint8* numberOfTIDs);

/*************************************************************************/
/*
 * Brief               Service to report the value of PID 01 computed by the Dem.
 * ServiceId           0x61
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Buffer containing the contents of PID 01 computed by the Dem.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

/* Monitor status since DTCs cleared 4 byte*/
/* SWS_Dem_01103
   Unavailable events shall not be considered for computation of service 01 PID 41.*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID01(uint8* PID01value);

/*************************************************************************/
/*
 * Brief               Service to report the value of PID 1C computed by the Dem.
 * ServiceId           0x63
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Buffer containing the contents of PID 1C computed by the Dem.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

/*OBD requirements to which vehicle is designed*/
extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID1C(uint8* PID1Cvalue);

/*************************************************************************/
/*
 * Brief               Service to report the value of PID 21 computed by the Dem.
 * ServiceId           0x64
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Buffer containing the contents of PID 21 computed by the Dem.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID21(uint8* PID21value);

/*************************************************************************/
/*
 * Brief               Service to report the value of PID 30 computed by the Dem.
 * ServiceId           0x65
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Buffer containing the contents of PID 30 computed by the Dem.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID30(uint8* PID30value);

/*************************************************************************/
/*
 * Brief               Service to report the value of PID 31 computed by the Dem.
 * ServiceId           0x66
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Buffer containing the contents of PID 31 computed by the Dem.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID31(uint8* PID31value);

/*************************************************************************/
/*
 * Brief               Service to report the value of PID 41 computed by the Dem.
 * ServiceId           0x67
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Buffer containing the contents of PID 41 computed by the Dem.>
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID41(uint8* PID41value);

/*************************************************************************/
/*
 * Brief               Service to report the value of PID 4D computed by the Dem.
 * ServiceId           0x68
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Buffer containing the contents of PID 4D computed by the Dem.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4D(uint8* PID4Dvalue);

/*************************************************************************/
/*
 * Brief               Service to report the value of PID 4E computed by the Dem.
 * ServiceId           0x69
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     PID4Evalue Buffer containing the contents of PID 4E
                        computed by the Dem.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID4E(uint8* PID4Evalue);

/*************************************************************************/
/*
 * Brief               Service to report the value of PID 4E computed by the Dem.
 * ServiceId           0x6a
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     PID4Evalue Buffer containing the contents of PID 4E
                        computed by the Dem.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmReadDataOfPID91(uint8* PID91value);

#if (DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)

extern Std_ReturnType DemReadPID91(uint8* Buffer);

#endif

/*************************************************************************/
/*
 * Brief               Gets data element per PID and index of the most important freeze frame
                        being selected for the output of service 02. The function stores the data
                        in the provided DestBuffer.
 * ServiceId           0x52
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      PID: This parameter is an identifier for a PID as defined
                        in ISO15031-5.
                        DataElementIndexOfPID: Data element index of this PID according
                        to the Dcm configuration of service 02. It is zero-based and
                        consecutive, and ordered by the data element  positions
                        (configured in Dcm, refer to SWS_Dem_00597).>
 * Param-Name[out]     None
 * Param-Name[in/out]  DestBuffer: This parameter contains a byte pointer that points to
                        the buffer, to which the data element of the PID shall
                        be written to. The format is raw hexadecimal values
                        and contains no header-information.
                        BufSize: When the function is called this parameter contains
                        the maximum number of data bytes that can be written
                        to the buffer.
                        The function returns the actual number of written
                        data bytes in this parameter.
 * Return              E_OK Freeze frame data was successfully reported
                        E_NOT_OK Freeze frame data was not successfully reported
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_DcmReadDataOfOBDFreezeFrame(uint8 PID, uint8 DataElementIndexOfPID, uint8* DestBuffer, uint16* BufSize);

/*************************************************************************/
/*
 * Brief               Gets DTC by freeze frame record number.
 * ServiceId           0x53
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      FrameNumber: Unique identifier for a freeze frame
                        record as defined in ISO 15031-5. The value 0x00
                        indicates the complete OBD freeze frame. Other values
                        are reserved for future functionality.
                        DTCFormat: Output format of the DTC value.
 * Param-Name[out]     DTC Diagnostic Trouble Code in ODB format. If the return
                        value of the function is other than E_OK this
                        parameter does not contain valid data.
 * Param-Name[in/out]  None
 * Return              E_OK: operation was successful E_NOT_OK: no DTC available
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_DcmGetDTCOfOBDFreezeFrame(uint8 FrameNumber, uint32* DTC, Dem_DTCFormatType DTCFormat);

/*************************************************************************/
/*
 * Brief               Reports a DTR data along with TID-value, UaSID, test result with lower and upper limit.
 * ServiceId           0xa5
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Obdmid: Identification of a DTR element by assigned DTRId.
                        TIDindex: Index of the TID within the DEM. Runs from 0
                        to "numberOfTIDs" obtained in the call to Dem_
                        DcmGetNumTIDsOfOBDMID()
 * Param-Name[out]     TIDvalue: TID to be put on the tester reponse
                        UaSID: UaSID to be put on the tester reponse
                        Testvalue:Latest test result
                        Lowlimvalue:Lower limit value associated to the latest test result
                        Upplimvalue:Upper limit value associated to the latest test result
 * Param-Name[in/out]  None
 * Return              E_OK: Report of DTR result successful
                        E_NOT_OK: Report of DTR result failed
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_DcmGetDTRData(
    uint8 Obdmid,
    uint8 TIDindex,
    uint8* TIDvalue,
    uint8* UaSID,
    uint16* Testvalue,
    uint16* Lowlimvalue,
    uint16* Upplimvalue);

/*************************************************************************/
/*
 * Brief               Service for reporting the event as disabled to the
                        Dem for the PID 41 computation.
 * ServiceId           0x51
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different EventIds. Non reentrant for the same EventId.
 * Param-Name[in]      Identification of an event by assigned EventId.>
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK set of event to disabled was successfull.
                         E_NOT_OK set of event disabled failed
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetEventDisabled(Dem_EventIdType EventId);

/*************************************************************************/
/*
 * Brief               Service for reporting that faults are possibly found
                        because all conditions are fullfilled.
 * ServiceId           0x73
 * Sync/Async          Reentrant for different RatioIDs. Non reentrant for the same RatioID
 * Reentrancy          Non Reentrant
 * Param-Name[in]      Ratio Identifier reporting that a respective monitor
                        could have found a fault
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK report of IUMPR result was successfully reported
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRFaultDetect(Dem_RatioIdType RatioID);

/*************************************************************************/
/*
 * Brief               In order to communicate the status of the (additional) denominator
                        conditions among the OBD relevant ECUs, the API is used to forward
                        the condition status to a Dem of a particular ECU
 * ServiceId           0xae
 * Sync/Async          Synchronous /Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConditionId: Identification of a IUMPR denominator condition ID
                        ConditionStatus:Status of the IUMPR denominator condition
                        (Notreached, reached, not reachable / inhibited)
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: set of IUMPR denominator condition was successful
                        E_NOT_OK: set of IUMPR denominator condition
                        failed or could not be accepted.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_SetIUMPRDenCondition(Dem_IumprDenomCondIdType ConditionId, Dem_IumprDenomCondStatusType ConditionStatus);

/*************************************************************************/
/*
 * Brief               In order to communicate the status of the (additional) denominator
                        conditions among the OBD relevant ECUs, the API is used to retrieve
                        the condition status from the Dem of the ECU where the conditions are
                        computed.
 * ServiceId           0xaf
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ConditionId: Identification of a IUMPR denominator condition ID
 * Param-Name[out]     ConditionStatus:Status of the IUMPR denominator condition
 *                      (Notreached, reached, not reachable / inhibited)
 * Param-Name[in/out]  None
 * Return              E_OK: get of IUMPR denominator condition status was successful
                        E_NOT_OK: get of condition status failed
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_GetIUMPRDenCondition(Dem_IumprDenomCondIdType ConditionId, Dem_IumprDenomCondStatusType* ConditionStatus);

/*************************************************************************/
/*
 * Brief               Service is used to lock a denominator of a specific monitor.
 * ServiceId           0x71
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Ratio Identifier reporting that specific denominator
                        is locked
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK report of IUMPR denominator status was successfully reported
                        E_NOK report of IUMPR denominator status was
                        not successfully reported
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenLock(Dem_RatioIdType RatioID);

/*************************************************************************/
/*
 * Brief               Service is used to release a denominator of a
                        specific monitor.
 * ServiceId           0x72
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Ratio Identifier reporting that specific denominator
                        is released
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK report of IUMPR denominator status was successfully reported
                        E_NOK report of IUMPR denominator status was
                        not successfully reported
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_RepIUMPRDenRelease(Dem_RatioIdType RatioID);

/*************************************************************************/
/*
 * Brief               Set the status of the PTO.
 * ServiceId           0x79
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      PtoStatus sets the status of the PTO
                        (TRUE==active;FALSE==inactive)
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Std_ReturnType Returns E_OK when the new PTO-status has been
                        adopted by the Dem; returns E_NOT_OK in all other cases.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetPtoStatus(boolean PtoStatus);

/*************************************************************************/
/*
 * Brief               Service to report the value of PID 01 computed by the Dem.
 * ServiceId           0xb3
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     PID01value:Buffer containing the contents of PID 01 computed by the Dem.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_ReadDataOfPID01(uint8* PID01value);

#if ((DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU) && (DEM_OBD_CENTRALIZED_PID21_HANDLING == STD_ON))
/*************************************************************************/
/*
 * Brief               Service to get the value of PID 21 from the Dem by a software component.
 * ServiceId           0xb1
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     PID21value:Content of PID 21 as raw hex value.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetDataOfPID21(uint8* PID21value);

#endif

/*************************************************************************/
/*
 * Brief               Service to set the value of PID 31 in the Dem by a software component
 * ServiceId           0xa7
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     PID31value:Buffer containing the contents of PID 31.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID31(uint8* PID31value);

/*************************************************************************/
/*
 * Brief               Service to set the value of PID 4D in the Dem by a software component.
 * ServiceId           0xa8
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     PID4Dvalue:Buffer containing the contents of PID 4D.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4D(uint8* PID4Dvalue);

/*************************************************************************/
/*
 * Brief               Service to set the value of PID 4E in the Dem by a software component.
 * ServiceId           0xa9
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     PID4Evalue:Buffer containing the contents of PID 4E.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID4E(uint8* PID4Evalue);

/*************************************************************************/
/*
 * Brief               Marks the current OBD driving cycle as having met the criteria for the PFC cycle.
 * ServiceId           0xaa
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetPfcCycleQualified(void);

/*************************************************************************/
/*
 * Brief               Returns TRUE if the criteria for the PFC cycle have been met during the      current OBD driving
 cycle.
 * ServiceId           0xab
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     isqualified:TRUE: During the current OBD driving cycle the criteria for the PFC cycle have been
 met. FALSE: During the current OBD driving cycle the criteria for the PFC cycle have not been met.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_GetPfcCycleQualified(boolean* isqualified);

/*************************************************************************/
/*
 * Brief               API to inform the Dem (of a Dependend / Secondary ECU) about the
                       reception of service 04 execution by a software component.
                       API is needed in OBD Dependend / Secondary ECUs only.
 * ServiceId           0xac
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      DTC:Defines the DTC in respective format, that has been
 *                     cleared from the event memory.
 *                       DTCFormat:Format of the provided DTC value.
 *                       DTCOrigin:Event memory (e.g. MIRROR)
 * Param-Name[out]     none
 * Param-Name[in/out]  none
 * Return              Return value unused - only for compatibility with according RTE operation.
 */
/*************************************************************************/

extern FUNC(Dem_ReturnClearDTCType, DEM_CODE)
    Dem_SetClearDTC(uint32 DTC, Dem_DTCFormatType DTCFormat, Dem_DTCOriginType DTCOrigin);

/*************************************************************************/
/*
 * Brief              Reports a DTR result with lower and upper limit. The internal eventstatus
                        serves as master whether the DTR values are forwarded or ignored,
                        also taking the DTRUpdateKind into account.
 * ServiceId           0xa2
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      DTRId:Identification of a DTR element by assigned DTRId
 *                      TestResult:Test result of DTR
 *                      LowerLimit:Lower limit of DTR
 *                      UpperLimit:Upper limit of DTR
 *                      Ctrlval:Control value of the DTR to support its interpretation Dem-internally.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: Report of DTR result successful
                        E_NOT_OK: Report of DTR result failed
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE)
    Dem_SetDTR(uint16 DTRId, sint32 TestResult, sint32 LowerLimit, sint32 UpperLimit, Dem_DTRControlType Ctrlval);

#endif /*#if(DEM_OBD_SUPPORT != DEM_OBD_NO_OBD_SUPPORT)*/

#if (DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)
/*************************************************************************/
/*
 * Brief               Service to set the value of PID 21 in the Dem by a software component.
 * ServiceId           0xa6
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     PID21value:Buffer containing the contents of PID 21.
 * Param-Name[in/out]  None
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Std_ReturnType, DEM_CODE) Dem_SetDataOfPID21(uint8* PID21value);

#endif /*#if(DEM_OBD_SUPPORT == DEM_OBD_MASTER_ECU)*/

/*************************************************************************/
/*
 * Brief               Gets the DTC Severity availability mask.
 * ServiceId           0xb2
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     DTCSeverityMask:The value DTCSeverityMask indicates the
 *                      supported DTC severity bits from the Dem.
 * Param-Name[in/out]  none
 * Return              E_OK: get of DTC severity mask was successful
                        E_NOT_OK: get of DTC severity mask failed
 */
/*************************************************************************/

extern FUNC(Dem_ReturnClearDTCType, DEM_CODE)
    Dem_DcmGetDTCSeverityAvailabilityMask(Dem_DTCSeverityType* DTCSeverityMask);

#if (DEM_WWWOBD_NUM > 0)
/*************************************************************************/
/*
 * Brief               Service to report the value of the B1 counter computed by the Dem.
 * ServiceId           0xb4
 * Sync/Async          Asynchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      none
 * Param-Name[out]     B1Counter:Buffer containing the B1 counter.
 * Param-Name[in/out]  none
 * Return              Always E_OK is returned, as E_NOT_OK will never appear.
 */
/*************************************************************************/

extern FUNC(Dem_ReturnClearDTCType, DEM_CODE) Dem_GetB1Counter(uint16* B1Counter);

#endif
/* PRQA S 3451,3449,0624-- */ /* MISRA Rule 8.5,Rule 8.5,Rule 8.3 */

#endif /* DEM_H_ */

/*******************************************************************************
**                      end of file                                           **
*******************************************************************************/
