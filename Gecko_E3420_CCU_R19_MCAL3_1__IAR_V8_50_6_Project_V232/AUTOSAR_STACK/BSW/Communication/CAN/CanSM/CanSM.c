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
**  FILENAME    : CanSM.c                                                     **
**                                                                            **
**  Created on  :                                                             **
**  Author      : Wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      REVISION   HISTORY                                    **
*******************************************************************************/
/* <VERSION>  <DATE>    <AUTHOR>      <REVISION LOG>
 *  V2.0.0    2020-08-17  lili.wang    R19_11 initial version.
 *  V2.0.1    2020-10-19  lili.wang    QAC check,code update
 *  V2.0.2    2021-02-02  lili.wang
 *    1.Modify the timing mechanism for MainFunction timing.
 *    2.ComM_BusSM_ModeIndication pass parameter modification.
 *  V2.0.3    2021-02-23  lili.wang
 *    1.Modification of retry mechanism after CanIf request fails
 *    2.not include FreeRTTimer.h any more
 *  V2.0.4    2021-03-23  lili.wang
 *    1.Modify the macro control conditions of the Dem parameter,
 *    and some compilation warnings
 *  V2.0.5    2021-04-23  lili.wang
 *    1.delete CanSM_TxTimeoutException macro control CANSM_PNC_SUPPORT.
 *  V2.0.6    2021-06-16  lili.wang
 *    1.In CanSM_FullCom_S_CC_Started_Wait,get T_CC_STARTED_INDICATED,call
 *    CanIf_SetPduMode(controllerID,CANIF_ONLINE);
 *  V2.0.7    2021-06-24  lili.wang
 *    1.In CanSM_FullCom_S_CC_Started,get T_CC_STARTED_INDICATED,call
 *    CanIf_SetPduMode(controllerID,CANIF_ONLINE);
 *  V2.0.8    2022-03-17  darren
 *      1. Adjust header files and interface macro switches
 *  V2.0.9    2022-04-24  darren.zhang
 *      1.Adjust the header file inclusion order
 *  V2.0.10    2022-07-26  darren.zhang
 *      1.modify memap
 *  V2.0.11    2023-01-05  darren.zhang
 *      1.support pending comm reqeust
 */

/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:CanSM<br>
  RuleSorce:puhua-rule.rcf 2.3.1

    \li PRQA S 2877 MISRA Dir 4.1 .<br>
    Reason:The exception is that the number of loops is configurable.

    \li PRQA S 1531, 1532 MISRA Rule 8.7 .<br>
    Reason:The exception is global configuration data(1531) and API(1532).
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define CANSM_C_AR_RELEASE_MAJOR_VERSION 4u
#define CANSM_C_AR_RELEASE_MINOR_VERSION 5u
#define CANSM_C_AR_RELEASE_PATCH_VERSION 0u
#define CANSM_C_SW_MAJOR_VERSION         2u
#define CANSM_C_SW_MINOR_VERSION         0u
#define CANSM_C_SW_PATCH_VERSION         11u
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf.h"
#include "CanSM.h"
#include "ComM_BusSM.h"
#include "BswM_CanSM.h"
#if (STD_ON == CANSM_CANNM_CONF_PN_AVA)
#include "CanNm_Cbk.h"
#endif /* (STD_ON == CANSM_CANNM_CONF_PN_AVA) */
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
#include "Det.h"
#endif /* if (STD_ON == CANSM_DEV_ERROR_DETECT) */
#include "CanSM_Cbk.h"
#include "CanSM_TxTimeoutException.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (CANSM_C_AR_RELEASE_MAJOR_VERSION != CANSM_H_AR_RELEASE_MAJOR_VERSION)
#error "CanSM.c : Mismatch in Specification Major Version"
#endif
#if (CANSM_C_AR_RELEASE_MINOR_VERSION != CANSM_H_AR_RELEASE_MINOR_VERSION)
#error "CanSM.c : Mismatch in Specification _MINOR Version"
#endif
#if (CANSM_C_AR_RELEASE_PATCH_VERSION != CANSM_H_AR_RELEASE_PATCH_VERSION)
#error "CanSM.c : Mismatch in Specification PATCH Version"
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define BUS_OFF_COUNTER_UP_LIMIT 255u

/* get network handle of assigned configuration index */
#define CANSM_NETWORK_HANDLE(NetworkHandle_Index) \
    (CanSM_ConfigPtr->CanSMManagerNetworkRef[NetworkHandle_Index].CanSMComMNetworkHandleRef)

#define CANSM_NETWORK_CONFIGURATION(NetworkHandle_Index) (CanSM_ConfigPtr->CanSMManagerNetworkRef[NetworkHandle_Index])

#define CANSM_NETWORK_CONTROLLER(NetworkHandle_Index) \
    (CanSM_ConfigPtr->CanSMManagerNetworkRef[NetworkHandle_Index].ControllerRef)

#define CANSM_NETWORK_TRANSCEIVER(NetworkHandle_Index) \
    (CanSM_ConfigPtr->CanSMManagerNetworkRef[NetworkHandle_Index].TrcvRef)

#define CANSM_MODEREQREPEAT_MAINFUNCTIONTIME \
    (uint32)((uint32)(CanSM_ConfigPtr->CanSMModeRequestRepetitionTime) / (uint32)(CANSM_MAINFUNCTION_PERIOD))

#define CANSM_NETWORK_BORTXENSUREDTIME(NetworkHandle_Index)                                \
    (uint32)(                                                                              \
        CanSM_ConfigPtr->CanSMManagerNetworkRef[NetworkHandle_Index].CanSMBorTimeTxEnsured \
        / (uint32)(CANSM_MAINFUNCTION_PERIOD))

#if (STD_ON == CANSM_DEV_ERROR_DETECT)
#define CANSM_DET_REPORT(ApiId, ErrorId) ((void)Det_ReportError(CANSM_MODULE_ID, CANSM_INSTANCE_ID, (ApiId), (ErrorId)))
#else
#define CANSM_DET_REPORT(ApiId, ErrorId)
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT */

#define CANSM_DET_REPORTRUNTIMEERROR(ApiId, ErrorId) \
    ((void)Det_ReportRuntimeError(CANSM_MODULE_ID, CANSM_INSTANCE_ID, (ApiId), (ErrorId)))
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.h"

static FUNC(void, CANSM_CODE) CanSM_PnNot_CC_Stopped(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_PnNot_CC_Stopped_Wait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_PnNot_CC_Sleep(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_PnNot_CC_Sleep_Wait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

#if (CANSM_TRCV_NUM > 0)
static FUNC(void, CANSM_CODE) CanSM_PnNot_Trcv_Normal(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_PnNot_Trcv_Normal_Wait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_PnNot_Trcv_Standby(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_PnNot_Trcv_Standby_Wait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);
#endif

static FUNC(void, CANSM_CODE) CanSM_DeinitPnNotSupported(uint8 netID);

#if (STD_ON == CANSM_PNC_SUPPORT)
static FUNC(void, CANSM_CODE) CanSM_Pn_S_Pn_Clear_WUF(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_S_Pn_Clear_WUF_Wait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_S_Pn_CC_Stopped(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_S_Pn_CC_Stopped_Wait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_S_Trcv_Normal(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_S_Trcv_Normal_Wait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_S_Trcv_Standby(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_S_Trcv_Standby_Wait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_S_CC_Sleep(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_S_CC_Sleep_Wait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_Check_Wflag_InCCSleep(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_Check_Wflag_InCCSleepWait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_CheckWflag_InNotCCSleep(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Pn_CheckWFlag_InNotCCSleepWait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_DeinitPnSupported(uint8 netID);
#endif

static FUNC(void, CANSM_CODE) CanSM_BsmSNoCom(uint8 netID);

#if (CANSM_TRCV_NUM > 0)
static FUNC(void, CANSM_CODE) CanSM_WUVAL_S_Trcv_Normal(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_WUVAL_S_Trcv_Normal_Wait(CanSM_NetWorkRunTimeType* networkPtr);
#endif

static FUNC(void, CANSM_CODE) CanSM_WUVAL_S_CC_Stopped(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_WUVAL_S_CC_Stopped_Wait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_WUVAL_S_CC_Started(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_WUVAL_S_CC_Started_Wait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_BsmWuValidation(uint8 netID);

#if (CANSM_TRCV_NUM > 0)
static FUNC(void, CANSM_CODE) CanSM_Prefullcom_S_Trcv_Normal(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Prefullcom_S_Trcv_Normal_Wait(CanSM_NetWorkRunTimeType* networkPtr);
#endif
static FUNC(void, CANSM_CODE) CanSM_Prefullcom_S_CC_Stopped(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Prefullcom_S_CC_Stopped_Wait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Prefullcom_S_CC_Started(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_Prefullcom_S_CC_Started_Wait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_BsmSPreFullCom(uint8 netID);

static FUNC(void, CANSM_CODE) CanSM_FullCom_S_Bus_off_Check(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_FullCom_S_CC_Stopped(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_FullCom_S_CC_Stopped_Wait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_FullCom_S_CC_Started(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_FullCom_S_CC_Started_Wait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_FullCom_S_Restart_CC(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_FullCom_S_Restart_CC_Wait(CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_FullCom_S_Tx_Off(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_BsmSFullCom(uint8 netID);

#if (STD_ON == CANSM_SET_BAUDRATE_API)
static FUNC(void, CANSM_CODE) CanSM_ChangeBR_Change_BR_Sync(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_ChangeBR_S_CC_Stopped(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_ChangeBR_S_CC_Stopped_Wait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_ChangeBR_S_CC_Started(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_ChangeBR_S_CC_Started_Wait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr);

static FUNC(void, CANSM_CODE) CanSM_BsmSChangeBaudrate(uint8 netID);
#endif

static FUNC(void, CANSM_CODE) CanSM_BsmSSilentCom(uint8 netID);

static FUNC(void, CANSM_CODE) CanSM_BsmSSilentComBor(uint8 netID);

static FUNC(void, CANSM_CODE) CanSM_EFullComAction(uint8 netID);

static FUNC(void, CANSM_CODE) CanSM_EFullToSilentComAction(uint8 netID);

static FUNC(void, CANSM_CODE) CanSM_EPreNoComAction(uint8 netID);

static FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetControllerModeRepeat(
    uint8 netID,
    CanSM_NetWorkRunTimeType* networkPtr,
    CanIf_ControllerModeType requestContorllerMode);

static FUNC(void, CANSM_CODE) CanSM_TimerHandler(CanSM_NetWorkRunTimeType* networkPtr);
#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.h"
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define CANSM_START_SEC_VAR_INIT_8
#include "CanSM_MemMap.h"
static VAR(CanSM_StateType, CANSM_VAR_POWER_ON_INIT) CanSM_Status = CANSM_UNINITED;
#define CANSM_STOP_SEC_VAR_INIT_8
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_VAR_NO_INIT_PTR
#include "CanSM_MemMap.h"
static P2CONST(CanSM_ConfigType, AUTOMATIC, CANSM_CONFIG_DATA) CanSM_ConfigPtr;
#define CANSM_STOP_SEC_VAR_NO_INIT_PTR
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.h"
static VAR(CanSM_NetWorkRunTimeType, CANSM_VAR) CanSM_NetWorkRunTime[CANSM_NETWORK_NUM];
static VAR(CanIf_ControllerModeType, CANSM_VAR) CanSM_ControllerMode[CANIF_CANCONTROLLER_NUMBER];
#define CANSM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.h"
#if (STD_ON == CANSM_TX_OFFLINE_ACTIVE_SUPPORT)
static VAR(boolean, CANSM_VAR) CanSM_EcuPassive = FALSE;
#endif /* (STD_ON == CANSM_TX_OFFLINE_ACTIVE_SUPPORT)*/
#define CANSM_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "CanSM_MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.h"
/******************************************************************************/
/*
 * Brief               This service initializes the CanSM module.
 * ServiceId           0x00
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      ConfigPtr, Pointer to init structure for the post build
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CODE)
CanSM_Init(P2CONST(CanSM_ConfigType, AUTOMATIC, CANSM_CONFIG_DATA) ConfigPtr) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 netLoop;
    uint8 controller;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (NULL_PTR == ConfigPtr)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_INIT, CANSM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        if (CANSM_UNINITED == CanSM_Status)
        {
            CanSM_Status = CANSM_INITED;
            CanSM_ConfigPtr = ConfigPtr;
            /* initialize run time structure variable for every network */
            for (netLoop = 0u; netLoop < CANSM_NETWORK_NUM; netLoop++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
            {
#if (STD_ON == CANSM_PNC_SUPPORT)
                if ((NULL_PTR != CANSM_NETWORK_CONFIGURATION(netLoop).TrcvRef)
                    && ((boolean)TRUE == CANSM_NETWORK_CONFIGURATION(netLoop).TrcvRef->CanSMCanTrcvPnEnabled))
                {
                    CanSM_NetWorkRunTime[netLoop].curBsmState = CANSM_BSM_DEINITPNSUPPORTED;
                    CanSM_NetWorkRunTime[netLoop].deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;
                }
                else
#endif /*STD_ON == CANSM_PNC_SUPPORT*/
                {
                    CanSM_NetWorkRunTime[netLoop].curBsmState = CANSM_BSM_DEINITPNNOTSUPPORTED;
                    CanSM_NetWorkRunTime[netLoop].deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;
                }
                CanSM_NetWorkRunTime[netLoop].ModeRequestRepetitionTime = 0u;
                CanSM_NetWorkRunTime[netLoop].waitCanIfIndicatedStartTime = 0u;
                CanSM_NetWorkRunTime[netLoop].busOffEventStartTime = 0u;
                CanSM_NetWorkRunTime[netLoop].borTimeTxEnsuredTime = 0u;
                CanSM_NetWorkRunTime[netLoop].busOffCounter = 0u;
                CanSM_NetWorkRunTime[netLoop].repeatCounter = 0u;
                CanSM_NetWorkRunTime[netLoop].canIfIndicated = T_NO_INDICATED;
                CanSM_NetWorkRunTime[netLoop].requestComMode = CANSM_NO_REQUEST;
                CanSM_NetWorkRunTime[netLoop].curComMode = COMM_NO_COMMUNICATION;
#if (STD_ON == CANSM_SET_BAUDRATE_API)
                CanSM_NetWorkRunTime[netLoop].baudRateConfigID = 0u;
#endif
#if (STD_ON == CANSM_GET_BUSOFF_DELAY_FUNCTION_USED)
                CanSM_NetWorkRunTime[netLoop].busOffDelayTime = 0u;
#endif
            }
            /* PRQA S 2877 ++ */ /* MISRA Dir 4.1 */
            for (controller = 0u; controller < (uint8)CANIF_CANCONTROLLER_NUMBER; controller++)
            /* PRQA S 2877 -- */ /* MISRA Dir 4.1 */
            {
                CanSM_ControllerMode[controller] = CANIF_CS_UNINIT;
            }
        }
    }
    return;
}

/******************************************************************************/
/*
 * Brief               This service de-initializes the CanSM module.
 * ServiceId           0x14
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      NA
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CODE)
CanSM_DeInit(void)
{
    uint8 netLoop;
    boolean AllNetInNoCom = TRUE;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_DEINIT, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
    {
        for (netLoop = 0u; netLoop < CANSM_NETWORK_NUM; netLoop++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            if (CANSM_BSM_S_NOCOM != CanSM_NetWorkRunTime[netLoop].curBsmState)
            {
                AllNetInNoCom = FALSE;
/*@req <SWS_CanSM_00660>*/
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
                CANSM_DET_REPORT(SERVICE_ID_CANSM_DEINIT, CANSM_E_NOT_IN_NO_COM);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
                break;
            }
        }
    }
    if ((boolean)TRUE == AllNetInNoCom)
    {
        for (netLoop = 0u; netLoop < CANSM_NETWORK_NUM; netLoop++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            /*@req <SWS_CanSM_00658>*/
            CanSM_NetWorkRunTime[netLoop].curBsmState = CANSM_BSM_S_NOT_INITIALIZED;
        }
        CanSM_Status = CANSM_UNINITED;
    }
}

#if (STD_ON == CANSM_VERSION_INFO_API)
/******************************************************************************/
/*
 * Brief               This service puts out the version information of this
 *                     module
 * ServiceId           0x01
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      NA
 * Param-Name[out]     VersionInfo, Pointer to where to store the version
 *                     information of this module
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CODE)
CanSM_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (NULL_PTR == VersionInfo)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_GETVERSIONINFO, CANSM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        VersionInfo->moduleID = CANSM_MODULE_ID;
        VersionInfo->sw_major_version = CANSM_C_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = CANSM_C_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = CANSM_C_SW_PATCH_VERSION;
        VersionInfo->vendorID = CANSM_VENDOR_ID;
    }
    return;
}
#endif /*STD_ON == CANSM_VERSION_INFO_API*/

#if (STD_ON == CANSM_SET_BAUDRATE_API)
/******************************************************************************/
/*
 * Brief               This service shall start an asynchronous process to change
 *                     the baud rate for the configured CAN controllers of a
 *                     certain CAN network.Depending on necessary baud rate
 *                     modifications the controllers might have to reset.
 * ServiceId           0x0d
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different Networks. Non reentrant for the same
 *                     Network
 * Param-Name[in]      Network, Handle of the addressed CAN network for the baud
 *                     rate change
 *                     BaudRateConfigID, a baud rate configuration by ID
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: Service request accepted, setting of new baud rate
 *                     started
 *                     E_NOT_OK: Service request not accepted
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANSM_CODE)
CanSM_SetBaudrate(NetworkHandleType Network, uint16 BaudRateConfigID)
{
    uint8 netLoop;
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(CanSM_NetWorkRunTimeType, AUTOMATIC, CANSM_VAR) networkPtr;
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
    Std_ReturnType ret = E_NOT_OK;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_SETBAUDRATE, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        for (netLoop = 0u; (netLoop < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); netLoop++)
        {
            if (Network == CANSM_NETWORK_HANDLE(netLoop))
            {
                networkPtr = &CanSM_NetWorkRunTime[netLoop];
                ret = E_OK;
            }
        }
        if ((uint8)E_OK == ret)
        {
            if ((CANSM_BSM_S_FULLCOM == networkPtr->curBsmState) && (FULLCOM_S_NO_BUS_OFF == networkPtr->fullComState))
            {
                networkPtr->curBsmState = CANSM_BSM_S_CHANGE_BAUDRATE;
                networkPtr->changeBaudrateState = CHANGEBR_CHANGE_BR_SYNC;
                (void)BswM_CanSM_CurrentState(Network, CANSM_BSWM_CHANGE_BAUDRATE);
                networkPtr->baudRateConfigID = BaudRateConfigID;
            }
            else
            {
                ret = E_NOT_OK;
            }
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_SETBAUDRATE, CANSM_E_INVALID_NETWORK_HANDLE);
        }
#endif
    }
    return ret;
}
#endif /*STD_ON == CANSM_SET_BAUDRATE_API*/

#if (STD_ON == CANSM_ICOM_SUPPORT)
/******************************************************************************/
/*
 * Brief               This service shall change the Icom Configuration of a CAN
 *                     network to the requested one.
 * ServiceId           0x0f
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant for different Networks
 * Param-Name[in]      Network, Handle of destined communication network for request
 *                     ConfigurationId, Requested Configuration
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: Request accepted
 *                     E_NOT_OK: Request denied
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANSM_CODE)
CanSM_SetIcomConfiguration(NetworkHandleType Network, IcomConfigIdType ConfigurationId)
{
    uint8 cnt;
    uint8 netID;
    uint8 netWorkRefControllerNum;
    Std_ReturnType ret = E_NOT_OK;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_SETICOMCONFIGURATION, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        for (cnt = 0u; (cnt < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); cnt++)
        {
            if (Network == CANSM_NETWORK_HANDLE(cnt))
            {
                netID = cnt;
                ret = E_OK;
            }
        }
        if ((uint8)E_OK == ret)
        {
            netWorkRefControllerNum = CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber;
            /*if at least one controller SetIcomConfiguration E_NOT_OK,the API return E_NOT_OK*/
            for (cnt = 0u; (cnt < netWorkRefControllerNum) && ((uint8)E_OK == ret); cnt++)
            {
                ret = CanIf_SetIcomConfiguration(
                    CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt],
                    ConfigurationId);
            }
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_SETICOMCONFIGURATION, CANSM_E_INVALID_NETWORK_HANDLE);
        }
#endif
    }
    return ret;
}
#endif /*STD_ON == CANSM_ICOM_SUPPORT*/

#if (STD_ON == CANSM_TX_OFFLINE_ACTIVE_SUPPORT)
/******************************************************************************/
/*
 * Brief               This function can be used to set all CanSM channels of
 *                     the ECU to a receive only mode. This mode will be kept
 *                     either until it is set back, or the ECU is reset.
 * ServiceId           0x13
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CanSM_Passive, TRUE: set all CanSM channels to passive,
 *                     i.e. receive only
 *                     FALSE: set all CanSM channels back to non-passive
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: Request accepted
 *                     E_NOT_OK: Request denied
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANSM_CODE)
CanSM_SetEcuPassive(boolean CanSM_Passive)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 netLoop;
    uint8 cnt;
    uint8 netWorkRefControllerNum;
    CanIf_PduModeType controllerPduMode = CANIF_OFFLINE;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_SETECUPASSIVE, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        if (((boolean)TRUE == CanSM_Passive) && ((boolean)FALSE == CanSM_EcuPassive))
        {
            CanSM_EcuPassive = TRUE;
            for (netLoop = 0u; netLoop < CANSM_NETWORK_NUM; netLoop++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
            {
                netWorkRefControllerNum = CANSM_NETWORK_CONTROLLER(netLoop)->NetWorkRefControllerNumber;
                for (cnt = 0u; cnt < netWorkRefControllerNum; cnt++)
                {
                    (void)CanIf_GetPduMode(
                        CANSM_NETWORK_CONTROLLER(netLoop)->CanSMControllerId[cnt],
                        &controllerPduMode);
                    if (CANIF_ONLINE == controllerPduMode)
                    {
                        (void)CanIf_SetPduMode(
                            CANSM_NETWORK_CONTROLLER(netLoop)->CanSMControllerId[cnt],
                            CANIF_TX_OFFLINE_ACTIVE);
                    }
                }
            }
        }
        else if (((boolean)FALSE == CanSM_Passive) && ((boolean)TRUE == CanSM_EcuPassive))
        {
            CanSM_EcuPassive = FALSE;
            for (netLoop = 0u; netLoop < CANSM_NETWORK_NUM; netLoop++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
            {
                netWorkRefControllerNum = CANSM_NETWORK_CONTROLLER(netLoop)->NetWorkRefControllerNumber;
                for (cnt = 0u; cnt < netWorkRefControllerNum; cnt++)
                {
                    (void)CanIf_GetPduMode(
                        CANSM_NETWORK_CONTROLLER(netLoop)->CanSMControllerId[cnt],
                        &controllerPduMode);
                    if (CANIF_TX_OFFLINE_ACTIVE == controllerPduMode)
                    {
                        (void)CanIf_SetPduMode(
                            CANSM_NETWORK_CONFIGURATION(netLoop).ControllerRef->CanSMControllerId[cnt],
                            CANIF_ONLINE);
                    }
                }
            }
        }
        else
        {
            /*nothing*/
        }
        ret = E_OK;
    }
    return ret;
}
#endif /*STD_ON == CANSM_TX_OFFLINE_ACTIVE_SUPPORT*/

static FUNC(void, CANSM_CODE) CanSM_TimerHandler(CanSM_NetWorkRunTimeType* networkPtr)
{
    if (networkPtr->ModeRequestRepetitionTime > 0u)
    {
        networkPtr->ModeRequestRepetitionTime--;
    }
    if (networkPtr->waitCanIfIndicatedStartTime > 0u)
    {
        networkPtr->waitCanIfIndicatedStartTime--;
    }
}

/******************************************************************************/
/*
 * Brief               Scheduled function of the CanSM
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      NA
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CODE)
CanSM_MainFunction(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    if (CANSM_UNINITED == CanSM_Status)
    {
        return;
    }

    for (uint8 netLoop = 0u; netLoop < CANSM_NETWORK_NUM; netLoop++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
    {
        CanSM_TimerHandler(&CanSM_NetWorkRunTime[netLoop]);
        switch (CanSM_NetWorkRunTime[netLoop].curBsmState)
        {
        case CANSM_BSM_DEINITPNNOTSUPPORTED:
            CanSM_DeinitPnNotSupported(netLoop);
            break;
#if (STD_ON == CANSM_PNC_SUPPORT)
        case CANSM_BSM_DEINITPNSUPPORTED:
            CanSM_DeinitPnSupported(netLoop);
            break;
#endif
        case CANSM_BSM_S_NOCOM:
            CanSM_BsmSNoCom(netLoop);
            break;
        case CANSM_BSM_WUVALIDATION:
            CanSM_BsmWuValidation(netLoop);
            break;
        case CANSM_BSM_S_PRE_FULLCOM:
            CanSM_BsmSPreFullCom(netLoop);
            break;
        case CANSM_BSM_S_FULLCOM:
            CanSM_BsmSFullCom(netLoop);
            break;
#if (STD_ON == CANSM_SET_BAUDRATE_API)
        case CANSM_BSM_S_CHANGE_BAUDRATE:
            CanSM_BsmSChangeBaudrate(netLoop);
            break;
#endif
        case CANSM_BSM_S_SILENTCOM:
            CanSM_BsmSSilentCom(netLoop);
            break;
        case CANSM_BSM_S_SILENTCOM_BOR:
            CanSM_BsmSSilentComBor(netLoop);
            break;
        default:
            /*This logic does not require any processing*/
            break;
        }
    }
}

/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Std_ReturnType CanSM_RequestComMode(NetworkHandleType network, ComM_ModeType comMMode)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    uint8 cnt;
    Std_ReturnType ret = E_NOT_OK;
    CanSM_NetWorkRunTimeType* networkPtr;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_REQUESTCOMMODE, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if (detNoErr)
#endif
    {
        /* PRQA S 2877 ++ */ /* MISRA Dir 4.1 */
        for (cnt = 0u; (cnt < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); cnt++)
        /* PRQA S 2877 -- */ /* MISRA Dir 4.1 */
        {
            if (network == CANSM_NETWORK_HANDLE(cnt))
            {
                networkPtr = &CanSM_NetWorkRunTime[cnt];
                ret = E_OK;
            }
        }
        if ((uint8)E_OK == ret)
        {
            switch (comMMode)
            {
            case COMM_NO_COMMUNICATION:
                if ((CANSM_BSM_S_FULLCOM == networkPtr->curBsmState)
#if (STD_ON == CANSM_SET_BAUDRATE_API)
                    || (CANSM_BSM_S_CHANGE_BAUDRATE == networkPtr->curBsmState)
#endif
                    || (CANSM_BSM_S_SILENTCOM == networkPtr->curBsmState)
                    || (CANSM_BSM_S_SILENTCOM_BOR == networkPtr->curBsmState))
                {
                    networkPtr->requestComMode = CANSM_NO_COMMUNICATION;
                }
                else
                {
                    ret = E_NOT_OK;
                }
                break;
            case COMM_SILENT_COMMUNICATION:
                if (CANSM_BSM_S_FULLCOM == networkPtr->curBsmState)
                {
                    networkPtr->requestComMode = CANSM_SILENT_COMMUNICATION;
                    CanSM_EFullToSilentComAction(cnt - 1u);
                }
#if (STD_ON == CANSM_SET_BAUDRATE_API)
                else if (CANSM_BSM_S_CHANGE_BAUDRATE == networkPtr->curBsmState)
                {
                    networkPtr->requestComMode = CANSM_SILENT_COMMUNICATION;
                }
#endif /* (STD_ON == CANSM_SET_BAUDRATE_API) */
                else
                {
                    ret = E_NOT_OK;
                }
                break;
            case COMM_FULL_COMMUNICATION:
                if (CANSM_BSM_S_SILENTCOM == networkPtr->curBsmState)
                {
                    networkPtr->requestComMode = CANSM_FULL_COMMUNICATION;
                    CanSM_EFullComAction(cnt - 1u);
                }
                else if (
                    (CANSM_BSM_S_NOCOM == networkPtr->curBsmState)
                    || (CANSM_BSM_WUVALIDATION == networkPtr->curBsmState) ||
#if (STD_ON == CANSM_PNC_SUPPORT)
                    (CANSM_BSM_DEINITPNSUPPORTED == networkPtr->curBsmState) ||
#endif /* (STD_ON == CANSM_PNC_SUPPORT) */
                    (CANSM_BSM_DEINITPNNOTSUPPORTED == networkPtr->curBsmState))
                {
                    networkPtr->requestComMode = CANSM_FULL_COMMUNICATION;
                }
                else
                {
                    ret = E_NOT_OK;
                }
                break;
            default:
                ret = E_NOT_OK;
                break;
            }
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_REQUESTCOMMODE, CANSM_E_INVALID_NETWORK_HANDLE);
        }
#endif
    }
    return ret;
}

/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
Std_ReturnType CanSM_GetCurrentComMode(NetworkHandleType network, ComM_ModeType* comMModePtr)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    uint8 cnt;
    Std_ReturnType ret = E_NOT_OK;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_GETCURRENTCOMMODE, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if (NULL_PTR == comMModePtr)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_GETCURRENTCOMMODE, CANSM_E_PARAM_POINTER);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        /* PRQA S 2877 ++ */ /* MISRA Dir 4.1 */
        for (cnt = 0u; (cnt < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); cnt++)
        /* PRQA S 2877 -- */ /* MISRA Dir 4.1 */
        {
            if (network == CANSM_NETWORK_HANDLE(cnt))
            {
                *comMModePtr = CanSM_NetWorkRunTime[cnt].curComMode;
                ret = E_OK;
            }
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        if ((uint8)E_NOT_OK == ret)
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_GETCURRENTCOMMODE, CANSM_E_INVALID_NETWORK_HANDLE);
        }
#endif
    }
    return ret;
}

/******************************************************************************/
/*
 * Brief               This function shall be called by EcuM when a wakeup source
 *                     shall be started.
 * ServiceId           0x11
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      network, Affected CAN network
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: Request accepted E_NOT_OK: Request denied
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANSM_ECUM_CODE)
CanSM_StartWakeupSource(NetworkHandleType network) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 cnt;
#if (CANSM_TRCV_NUM > 0)
    uint8 netID;
#endif
    Std_ReturnType ret = E_NOT_OK;
    CanSM_NetWorkRunTimeType* networkPtr;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_STARTWAKEUPSOURCE, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        /* PRQA S 2877 ++ */ /* MISRA Dir 4.1 */
        for (cnt = 0u; (cnt < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); cnt++)
        /* PRQA S 2877 -- */ /* MISRA Dir 4.1 */
        {
            if (network == CANSM_NETWORK_HANDLE(cnt))
            {
                networkPtr = &CanSM_NetWorkRunTime[cnt];
#if (CANSM_TRCV_NUM > 0)
                netID = cnt;
#endif
                ret = E_OK;
            }
        }
        if ((uint8)E_OK == ret)
        {
            if ((CANSM_BSM_DEINITPNNOTSUPPORTED <= networkPtr->curBsmState)
                && (networkPtr->curBsmState <= CANSM_BSM_S_NOCOM))
            {
                networkPtr->curBsmState = CANSM_BSM_WUVALIDATION;
#if (CANSM_TRCV_NUM > 0)
                if (NULL_PTR != CANSM_NETWORK_TRANSCEIVER(netID))
                {
                    networkPtr->wuValidationState = WUVALIDATION_S_TRCV_NORMAL;
                }
                else
#endif
                {
                    networkPtr->wuValidationState = WUVALIDATION_S_CC_STOPPED;
                }
                networkPtr->repeatCounter = 0u;
            }
            else
            {
                ret = E_NOT_OK;
            }
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_STARTWAKEUPSOURCE, CANSM_E_INVALID_NETWORK_HANDLE);
        }
#endif
    }
    return ret;
}

/******************************************************************************/
/*
 * Brief               This function shall be called by EcuM when a wakeup source
 *                     shall be stopped
 * ServiceId           0x12
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      network, Affected CAN network
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              E_OK: Request accepted E_NOT_OK: Request denied
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANSM_ECUM_CODE)
CanSM_StopWakeupSource(NetworkHandleType network) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 cnt;
#if (STD_ON == CANSM_PNC_SUPPORT)
    uint8 netID;
#endif
    Std_ReturnType ret = E_NOT_OK;
    CanSM_NetWorkRunTimeType* networkPtr;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_STOPWAKEUPSOURCE, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        /* PRQA S 2877 ++ */ /* MISRA Dir 4.1 */
        for (cnt = 0u; (cnt < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); cnt++)
        /* PRQA S 2877 -- */ /* MISRA Dir 4.1 */
        {
            if (network == CANSM_NETWORK_HANDLE(cnt))
            {
                networkPtr = &CanSM_NetWorkRunTime[cnt];
#if (STD_ON == CANSM_PNC_SUPPORT)
                netID = cnt;
#endif
                ret = E_OK;
            }
        }
        if ((uint8)E_OK == ret)
        {
            if (CANSM_BSM_WUVALIDATION == networkPtr->curBsmState)
            {
#if (STD_ON == CANSM_PNC_SUPPORT)
                if ((NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).TrcvRef)
                    && ((boolean)TRUE == CANSM_NETWORK_CONFIGURATION(netID).TrcvRef->CanSMCanTrcvPnEnabled))
                {
                    networkPtr->curBsmState = CANSM_BSM_DEINITPNSUPPORTED;
                    networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;
                }
                else
#endif
                {
                    networkPtr->curBsmState = CANSM_BSM_DEINITPNNOTSUPPORTED;
                    networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;
                }
                networkPtr->repeatCounter = 0u;
            }
            else
            {
                ret = E_NOT_OK;
            }
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_STOPWAKEUPSOURCE, CANSM_E_INVALID_NETWORK_HANDLE);
        }
#endif
    }
    return ret;
}
#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE
#include "CanSM_MemMap.h"
/******************************************************************************/
/*
 * Brief               This callback function notifies the CanSM about a bus-off
 *                     event on a certain CAN controller, which needs to be
 *                     considered with the specified bus-off recovery handling
 *                     for the impacted CAN network.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (only for different CanControllers)
 * Param-Name[in]      ControllerId, CAN controller, which detected a bus-off event
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CONTROLLERBUSOFF_CODE)
CanSM_ControllerBusOff(uint8 ControllerId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 netLoop;
    uint8 cnt;
    uint8 netID = 0u;
#if (STD_ON == CANSM_GET_BUSOFF_DELAY_FUNCTION_USED)
    uint8 delayCycleNum = 0u;
#endif
    Std_ReturnType ret = E_NOT_OK;
    uint8 netWorkControllerNum;
    ComM_ModeType ComMode;
    CanSM_NetWorkRunTimeType* networkPtr;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_CONTROLLERBUSOFF, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        /* PRQA S 2877 ++ */ /* MISRA Dir 4.1 */
        for (netLoop = 0u; (netLoop < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); netLoop++)
        /* PRQA S 2877 -- */ /* MISRA Dir 4.1 */
        {
            netWorkControllerNum = CANSM_NETWORK_CONTROLLER(netLoop)->NetWorkRefControllerNumber;
            for (cnt = 0u; cnt < netWorkControllerNum; cnt++)
            {
                if (ControllerId == CANSM_NETWORK_CONTROLLER(netLoop)->CanSMControllerId[cnt])
                {
                    ret = E_OK;
                    networkPtr = &CanSM_NetWorkRunTime[netLoop];
                    netID = CANSM_NETWORK_HANDLE(netLoop);
                    //netID = CANSM_NETWORK_CONTROLLER(netLoop);
                }
            }
        }
        if ((uint8)E_OK == ret)
        {
            if ((CANSM_BSM_S_FULLCOM == networkPtr->curBsmState)
                && ((FULLCOM_S_BUS_OFF_CHECK == networkPtr->fullComState)
                    || (FULLCOM_S_NO_BUS_OFF == networkPtr->fullComState)
                    || (FULLCOM_S_TX_OFF == networkPtr->fullComState)))
            {
                (void)BswM_CanSM_CurrentState(netID, CANSM_BSWM_BUS_OFF);
                ComMode = COMM_SILENT_COMMUNICATION;
                ComM_BusSM_ModeIndication(netID, ComMode);
#if (STD_ON == CANSM_DEM_SUPPORT)
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
                {
                    if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->BusOffPara)
                    {
                        Dem_ReportErrorStatus(
                            *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->BusOffPara,
                            DEM_EVENT_STATUS_PREFAILED);
                    }
                }
#endif /*if (STD_ON == CANSM_DEM_SUPPORT)*/
                networkPtr->fullComState = FULLCOM_S_RESTART_CC;
                networkPtr->repeatCounter = 0u;
                CanSM_ControllerMode[ControllerId] = CANIF_CS_STOPPED;
#if (STD_ON == CANSM_GET_BUSOFF_DELAY_FUNCTION_USED)
                if (TRUE == CANSM_NETWORK_CONFIGURATION(netID).CanSMEnableBusOffDelay)
                {
                    CANSM_GET_BUSOFF_DELAY_FUNCTION(CANSM_NETWORK_HANDLE(netID), &delayCycleNum);
                    networkPtr->busOffDelayTime = (uint16)delayCycleNum;
                }
#endif /*STD_ON == CANSM_GET_BUSOFF_DELAY_FUNCTION_USED*/
                networkPtr->busOffEventStartTime = 0u;
            }
            if (CANSM_BSM_S_SILENTCOM == networkPtr->curBsmState)
            {
#if (STD_ON == CANSM_DEM_SUPPORT)
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
                {
                    if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->BusOffPara)
                    {
                        Dem_ReportErrorStatus(
                            *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->BusOffPara,
                            DEM_EVENT_STATUS_PREFAILED);
                    }
                }
#endif /*if (STD_ON == CANSM_DEM_SUPPORT)*/
                networkPtr->curBsmState = CANSM_BSM_S_SILENTCOM_BOR;
                networkPtr->silentComBORState = SILENTBOR_S_RESTART_CC;
                CanSM_ControllerMode[ControllerId] = CANIF_CS_STOPPED;
                networkPtr->repeatCounter = 0u;
            }
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_CONTROLLERBUSOFF, CANSM_E_PARAM_CONTROLLER);
        }
#endif
    }
    return;
}
#define CANSM_STOP_SEC_CANSM_CONTROLLERBUSOFF_CALLBACK_CODE
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE
#include "CanSM_MemMap.h"
/******************************************************************************/
/*
 * Brief               This callback shall notify the CanSM module about a CAN
 *                     controller mode change.
 * ServiceId           0x07
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (only for different CanControllers)
 * Param-Name[in]      ControllerId, CAN controller, whose mode has changed
 *                     ControllerMode, Notified CAN controller mode
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
FUNC(void, CANSM_CONTROLLERNODEINDICATION_CODE)
CanSM_ControllerModeIndication(uint8 ControllerId, CanIf_ControllerModeType ControllerMode)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    uint8 netLoop;
    uint8 cnt;
    uint8 netID = 0u;
    Std_ReturnType ret = E_NOT_OK;
    uint8 netWorkControllerNum;
    uint8 netWorkControllerID;
    CanSM_NetWorkRunTimeType* networkPtr;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_CONTROLLERMODEINDICATION, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        /* PRQA S 2877 ++ */ /* MISRA Dir 4.1 */
        for (netLoop = 0u; (netLoop < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); netLoop++)
        /* PRQA S 2877 -- */ /* MISRA Dir 4.1 */
        {
            netWorkControllerNum = CANSM_NETWORK_CONTROLLER(netLoop)->NetWorkRefControllerNumber;
            for (cnt = 0u; cnt < netWorkControllerNum; cnt++)
            {
                if (ControllerId == CANSM_NETWORK_CONTROLLER(netLoop)->CanSMControllerId[cnt])
                {
                    ret = E_OK;
                    networkPtr = &CanSM_NetWorkRunTime[netLoop];
                    netID = netLoop;
                    CanSM_ControllerMode[ControllerId] = ControllerMode;
                }
            }
        }
        if ((uint8)E_OK == ret)
        {
            for (cnt = 0u; (cnt < netWorkControllerNum) && ((uint8)E_OK == ret); cnt++)
            {
                netWorkControllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
                if (ControllerMode != CanSM_ControllerMode[netWorkControllerID])
                {
                    ret = E_NOT_OK;
                }
            }
            if ((uint8)E_OK == ret)
            {
                switch (ControllerMode)
                {
                case CANIF_CS_STARTED:
                    networkPtr->canIfIndicated = T_CC_STARTED_INDICATED;
                    break;
                case CANIF_CS_STOPPED:
                    networkPtr->canIfIndicated = T_CC_STOPED_INDICATED;
                    break;
                case CANIF_CS_SLEEP:
                    networkPtr->canIfIndicated = T_CC_SLEEP_INDICATED;
                    break;
                default:
                    /*This logic does not require any processing*/
                    break;
                }
            }
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_CONTROLLERMODEINDICATION, CANSM_E_PARAM_CONTROLLER);
        }
#endif
    }
    return;
}
#define CANSM_STOP_SEC_CANSM_CONTROLLERMODEINDICATION_CALLBACK_CODE
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE
#include "CanSM_MemMap.h"
/******************************************************************************/
/*
 * Brief               This callback shall notify the CanSM module about a CAN
 *                     transceiver mode change.
 * ServiceId           0x09
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different CAN Transceivers
 * Param-Name[in]      TransceiverId, CAN transceiver, whose mode has changed
 *                     TransceiverMode, Notified CAN transceiver mode
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
FUNC(void, CANSM_TRANSCEIVERMODEINDICATION_CODE)
CanSM_TransceiverModeIndication(uint8 TransceiverId, CanTrcv_TrcvModeType TransceiverMode)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    uint8 netLoop;
    Std_ReturnType ret = E_NOT_OK;
    CanSM_NetWorkRunTimeType* networkPtr;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_TRANCEIVERMODEINDICATION, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        /* PRQA S 2877 ++ */ /* MISRA Dir 4.1 */
        for (netLoop = 0u; (netLoop < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); netLoop++)
        /* PRQA S 2877 -- */ /* MISRA Dir 4.1 */
        {
            if (NULL_PTR != CANSM_NETWORK_TRANSCEIVER(netLoop))
            {
                if (TransceiverId == CANSM_NETWORK_TRANSCEIVER(netLoop)->CanSMTransceiverId)
                {
                    ret = E_OK;
                    networkPtr = &CanSM_NetWorkRunTime[netLoop];
                }
            }
        }
        if ((uint8)E_OK == ret)
        {
            switch (TransceiverMode)
            {
            case CANTRCV_TRCVMODE_NORMAL:
                networkPtr->canIfIndicated = T_TRCV_NORMAL_INDICATED;
                break;
            case CANTRCV_TRCVMODE_STANDBY:
                networkPtr->canIfIndicated = T_TRCV_STANDBY_INDICATED;
                break;
            default:
                /*This logic does not require any processing*/
                break;
            }
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_TRANCEIVERMODEINDICATION, CANSM_E_PARAM_TRANSCEIVER);
        }
#endif
    }
    return;
}
#define CANSM_STOP_SEC_CANSM_TRANSCEIVERMODEINDICATION_CALLBACK_CODE
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
#include "CanSM_MemMap.h"
/******************************************************************************/
/*
 * Brief               This function shall notify the CanSM module, that the
 *                     CanNm has detected for the affected partial CAN network
 *                     CAN network a tx timeout exception, which shall be
 *                     recovered within the respective network state machine of
 *                     the CanSM module.
 * ServiceId           0x0b
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Channel, Affected CAN network
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_TXTIMEOUTEXCEPTION_CODE)
CanSM_TxTimeoutException(NetworkHandleType Channel) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 cnt;
    Std_ReturnType ret = E_NOT_OK;
    CanSM_NetWorkRunTimeType* networkPtr;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_TXTIMEOUTEXCEPTION, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        /* PRQA S 2877 ++ */ /* MISRA Dir 4.1 */
        for (cnt = 0u; (cnt < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); cnt++)
        /* PRQA S 2877 -- */ /* MISRA Dir 4.1 */
        {
            if (Channel == CANSM_NETWORK_HANDLE(cnt))
            {
                networkPtr = &CanSM_NetWorkRunTime[cnt];
                ret = E_OK;
            }
        }
        if ((uint8)E_OK == ret)
        {
            if ((CANSM_BSM_S_FULLCOM == networkPtr->curBsmState) && (FULLCOM_S_NO_BUS_OFF == networkPtr->fullComState))
            {
                networkPtr->fullComState = FULLCOM_S_CC_STOPPED;
                networkPtr->repeatCounter = 0u;
            }
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_TXTIMEOUTEXCEPTION, CANSM_E_INVALID_NETWORK_HANDLE);
        }
#endif
    }
    return;
}
#define CANSM_STOP_SEC_CANSM_TXTIMEOUTEXCEPTION_CALLBACK_CODE
#include "CanSM_MemMap.h"

#if (STD_ON == CANSM_PNC_SUPPORT)
#define CANSM_START_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
#include "CanSM_MemMap.h"
/******************************************************************************/
/*
 * Brief               This callback function shall indicate the CanIf_ClearTrcvWufFlag
 *                     API process end for the notified CAN Transceiver.
 * ServiceId           0x08
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different CAN Transceivers
 * Param-Name[in]      Transceiver, Requested Transceiver
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CLEARTRCVWUFFLAGINDICATION_CODE)
CanSM_ClearTrcvWufFlagIndication(uint8 Transceiver) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 netLoop;
    Std_ReturnType ret = E_NOT_OK;
    CanSM_NetWorkRunTimeType* networkPtr;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_CLEARTRCVWUFFLAGINDICATION, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        for (netLoop = 0u; (netLoop < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); netLoop++)
        {
            if (NULL_PTR != CANSM_NETWORK_TRANSCEIVER(netLoop))
            {
                if (Transceiver == CANSM_NETWORK_TRANSCEIVER(netLoop)->CanSMTransceiverId)
                {
                    ret = E_OK;
                    networkPtr = &CanSM_NetWorkRunTime[netLoop];
                }
            }
        }
        if ((uint8)E_OK == ret)
        {
            networkPtr->canIfIndicated = T_CLEAR_WUF_INDICATED;
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_CLEARTRCVWUFFLAGINDICATION, CANSM_E_PARAM_TRANSCEIVER);
        }
#endif
    }
    return;
}
#define CANSM_STOP_SEC_CANSM_CLEARTRCVWUFFLAGINDICATION_CALLBACK_CODE
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE
#include "CanSM_MemMap.h"
/******************************************************************************/
/*
 * Brief               This callback function indicates the CheckTransceiverWakeFlag
 *                     API process end for the notified CAN Transceiver
 * ServiceId           0x0a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different CAN Transceivers
 * Param-Name[in]      Transceiver, Requested Transceiver
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CODE)
CanSM_CheckTransceiverWakeFlagIndication(uint8 Transceiver) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 netLoop;
    Std_ReturnType ret = E_NOT_OK;
    CanSM_NetWorkRunTimeType* networkPtr;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        for (netLoop = 0u; (netLoop < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); netLoop++)
        {
            if (NULL_PTR != CANSM_NETWORK_TRANSCEIVER(netLoop))
            {
                if (Transceiver == CANSM_NETWORK_TRANSCEIVER(netLoop)->CanSMTransceiverId)
                {
                    ret = E_OK;
                    networkPtr = &CanSM_NetWorkRunTime[netLoop];
                }
            }
        }
        if ((uint8)E_OK == ret)
        {
            networkPtr->canIfIndicated = T_CHECK_WFLAG_INDICATED;
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION, CANSM_E_PARAM_TRANSCEIVER);
        }
#endif
    }
    return;
}
#define CANSM_STOP_SEC_CANSM_CHECKTRANSCEIVERWAKEFLAGINDICATION_CALLBACK_CODE
#include "CanSM_MemMap.h"

#define CANSM_START_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
#include "CanSM_MemMap.h"
/******************************************************************************/
/*
 * Brief               This callback function indicates that the transceiver is
 *                     running in PN communication mode
 * ServiceId           0x06
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      TransceiverId, CAN transceiver, which was checked for PN
 *                     availability
 * Param-Name[out]     NA
 * Param-Name[in/out]  NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CONFIRMPNAVAILABILITY_CODE)
CanSM_ConfirmPnAvailability(uint8 TransceiverId) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 netLoop;
    uint8 netID;
    Std_ReturnType ret = E_NOT_OK;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_CONFIRMPNAVAILABILITY, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        for (netLoop = 0u; (netLoop < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); netLoop++)
        {
            if (NULL_PTR != CANSM_NETWORK_TRANSCEIVER(netLoop))
            {
                if (TransceiverId == CANSM_NETWORK_TRANSCEIVER(netLoop)->CanSMTransceiverId)
                {
                    ret = E_OK;
                    netID = netLoop;
                }
            }
        }
        if ((uint8)E_OK == ret)
        {
#if (STD_ON == CANSM_CANNM_CONF_PN_AVA)
            CanNm_ConfirmPnAvailability(CANSM_NETWORK_HANDLE(netID));
#endif /* (STD_ON == CANSM_CANNM_CONF_PN_AVA) */
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_CONFIRMPNAVAILABILITY, CANSM_E_PARAM_TRANSCEIVER);
        }
#endif
    }
    return;
}
#define CANSM_STOP_SEC_CANSM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
#include "CanSM_MemMap.h"
#endif /*STD_ON == CANSM_PNC_SUPPORT*/

#if (STD_ON == CANSM_ICOM_SUPPORT)
#define CANSM_START_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE
#include "CanSM_MemMap.h"
/******************************************************************************/
/*
 * Brief               This service shall inform about the change of the Icom
 *                     Configuration of a CAN network.
 * ServiceId           0x10
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant only for different network handles
 * Param-Name[in]      ControllerId, CAN Controller Id, whose configuration has
 *                     changed.
 *                     ConfigurationId, Changed Configuration Id
 *                     Error, ICOM_SWITCH_E_OK: No Error
 *                            ICOM_SWITCH_E_FAILED: Switch to requested
 *                            Configuration failed. Severe Error.
 * Param-Name[in/out]  NA
 * Param-Name[out]     NA
 * Return              NA
 */
/******************************************************************************/
FUNC(void, CANSM_CURRENTICOMCONFIGURATION_CODE)
CanSM_CurrentIcomConfiguration(uint8 ControllerId, IcomConfigIdType ConfigurationId, IcomSwitch_ErrorType Error)
{
    uint8 netLoop;
    uint8 cnt;
    uint8 netID = 0u;
    Std_ReturnType ret = E_NOT_OK;
    uint8 netWorkControllerNum;
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
    boolean detNoErr = TRUE;
    if (CANSM_UNINITED == CanSM_Status)
    {
        CANSM_DET_REPORT(SERVICE_ID_CANSM_CURRENTICOMCONFIGURATION, CANSM_E_UNINIT);
        detNoErr = FALSE;
    }
    if ((boolean)TRUE == detNoErr)
#endif
    {
        for (netLoop = 0u; (netLoop < CANSM_NETWORK_NUM) && ((uint8)E_NOT_OK == ret); netLoop++)
        {
            netWorkControllerNum = CANSM_NETWORK_CONTROLLER(netLoop)->NetWorkRefControllerNumber;
            for (cnt = 0u; cnt < netWorkControllerNum; cnt++)
            {
                if (ControllerId == CANSM_NETWORK_CONTROLLER(netLoop)->CanSMControllerId[cnt])
                {
                    ret = E_OK;
                    netID = netLoop;
                }
            }
        }
        if ((uint8)E_OK == ret)
        {
            BswM_CanSM_CurrentIcomConfiguration(CANSM_NETWORK_HANDLE(netID), ConfigurationId, Error);
        }
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
        else
        {
            CANSM_DET_REPORT(SERVICE_ID_CANSM_CURRENTICOMCONFIGURATION, CANSM_E_PARAM_CONTROLLER);
        }
#endif
    }
    return;
}
#define CANSM_STOP_SEC_CANSM_CURRENTICOMCONFIGURATION_CALLBACK_CODE
#include "CanSM_MemMap.h"
#endif /*STD_ON == CANSM_ICOM_SUPPORT*/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
#define CANSM_START_SEC_CODE
#include "CanSM_MemMap.h"
/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPNNOT_S_CC_STOPPED
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_PnNot_CC_Stopped(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret;
    /*set all controllers of the network to request mode repeat*/
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_STOPPED);
    /*enter DEINITPNNOT_S_CC_SLEEP state*/
    if (T_CC_STOPED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_SLEEP;
        networkPtr->repeatCounter = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
        }
        /*enter DEINITPNNOT_S_CC_STOPPED_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPNNOT_S_CC_STOPPED_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_PnNot_CC_Stopped_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    if (T_CC_STOPED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_SLEEP;
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*T_CC_STOPPED_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPNNOT_S_CC_SLEEP
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_PnNot_CC_Sleep(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret;
    ComM_ModeType ComMode;
    /*set all controllers of the network to request mode repeat*/
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_SLEEP);
    /*enter DEINITPNNOT_S_TRCV_NORMAL or CANSM_BSM_S_NOCOM state*/
    if (T_CC_SLEEP_INDICATED == networkPtr->canIfIndicated)
    {
#if (CANSM_TRCV_NUM > 0)
        if (NULL_PTR != CANSM_NETWORK_TRANSCEIVER(netID))
        {
            networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_TRCV_NORMAL;
        }
        else
#endif
        {
            networkPtr->curBsmState = CANSM_BSM_S_NOCOM;
            ComMode = COMM_NO_COMMUNICATION;
            /*do E_NOCOM action*/
            ComM_BusSM_ModeIndication(CANSM_NETWORK_HANDLE(netID), ComMode);
        }
        networkPtr->repeatCounter = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;*/
        }
        /*enter DEINITPNNOT_S_CC_SLEEP_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_SLEEP_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPNNOT_S_CC_SLEEP_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_PnNot_CC_Sleep_Wait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    ComM_ModeType ComMode;
    if (T_CC_SLEEP_INDICATED == networkPtr->canIfIndicated)
    {
#if (CANSM_TRCV_NUM > 0)
        if (NULL_PTR != CANSM_NETWORK_TRANSCEIVER(netID))
        {
            networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_TRCV_NORMAL;
        }
        else
#endif
        {
            networkPtr->curBsmState = CANSM_BSM_S_NOCOM;
            ComMode = COMM_NO_COMMUNICATION;
            /*do E_NOCOM action*/
            ComM_BusSM_ModeIndication(CANSM_NETWORK_HANDLE(netID), ComMode);
        }
        networkPtr->waitCanIfIndicatedStartTime = 0u;
    }
    else
    {
        /*T_CC_SLEEP_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_SLEEP;
        }
    }
}

#if (CANSM_TRCV_NUM > 0)
/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPNNOT_S_TRCV_NORMAL
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_PnNot_Trcv_Normal(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    if ((0u == networkPtr->ModeRequestRepetitionTime)
        && (networkPtr->repeatCounter <= CanSM_ConfigPtr->CanSMModeRequestRepetitionMax))
    {
        ret = CanIf_SetTrcvMode(CANSM_NETWORK_TRANSCEIVER(netID)->CanSMTransceiverId, CANTRCV_TRCVMODE_NORMAL);
        if ((uint8)E_NOT_OK == ret)
        {
            networkPtr->ModeRequestRepetitionTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
        }
        networkPtr->repeatCounter++;
    }

    /*enter DEINITPNNOT_S_TRCV_STANDBY state*/
    if (T_TRCV_NORMAL_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_TRCV_STANDBY;
        networkPtr->repeatCounter = 0u;
        networkPtr->ModeRequestRepetitionTime = 0;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;*/
        }
        /*enter DEINITPNNOT_S_TRCV_NORMAL_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_TRCV_NORMAL_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPNNOT_S_TRCV_NORMAL_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_PnNot_Trcv_Normal_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    if (T_TRCV_NORMAL_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_TRCV_STANDBY;
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*T_TRCV_NORMAL_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_TRCV_NORMAL;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPNNOT_S_TRCV_STANDBY
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_PnNot_Trcv_Standby(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    ComM_ModeType ComMode;

    if ((0u == networkPtr->ModeRequestRepetitionTime)
        && (networkPtr->repeatCounter <= CanSM_ConfigPtr->CanSMModeRequestRepetitionMax))
    {
        ret = CanIf_SetTrcvMode(CANSM_NETWORK_TRANSCEIVER(netID)->CanSMTransceiverId, CANTRCV_TRCVMODE_STANDBY);
        if ((uint8)E_NOT_OK == ret)
        {
            networkPtr->ModeRequestRepetitionTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
        }
        networkPtr->repeatCounter++;
    }

    /*enter CANSM_BSM_S_NOCOM state*/
    if (T_TRCV_STANDBY_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->curBsmState = CANSM_BSM_S_NOCOM;
        ComMode = COMM_NO_COMMUNICATION;
        /*do E_NOCOM action*/
        ComM_BusSM_ModeIndication(CANSM_NETWORK_HANDLE(netID), ComMode);
        networkPtr->repeatCounter = 0u;
        networkPtr->ModeRequestRepetitionTime = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;*/
        }
        /*enter DEINITPNNOT_S_TRCV_STANDBY_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_TRCV_STANDBY_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPNNOT_S_TRCV_STANDBY_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_PnNot_Trcv_Standby_Wait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    ComM_ModeType ComMode;
    if (T_TRCV_STANDBY_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->curBsmState = CANSM_BSM_S_NOCOM;
        ComMode = COMM_NO_COMMUNICATION;
        /*do E_NOCOM action*/
        ComM_BusSM_ModeIndication(CANSM_NETWORK_HANDLE(netID), ComMode);
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*CANSM_BSM_T_TRCV_STANDBY_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_TRCV_STANDBY;
        }
    }
}
#endif

/******************************************************************************/
/*
 * Brief               Handle state transition in DeinitPnNotSupported
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_DeinitPnNotSupported(uint8 netID)
{
    CanSM_NetWorkRunTimeType* networkPtr = &CanSM_NetWorkRunTime[netID];
    switch (networkPtr->deinitPnNotSupportedState)
    {
    case DEINITPNNOT_S_CC_STOPPED:
        CanSM_PnNot_CC_Stopped(netID, networkPtr);
        break;
    case DEINITPNNOT_S_CC_STOPPED_WAIT:
        /*enter DEINITPNNOT_S_CC_SLEEP state*/
        CanSM_PnNot_CC_Stopped_Wait(networkPtr);
        break;
    case DEINITPNNOT_S_CC_SLEEP:
        CanSM_PnNot_CC_Sleep(netID, networkPtr);

        break;
    case DEINITPNNOT_S_CC_SLEEP_WAIT:
        /*enter DEINITPNNOT_S_TRCV_NORMAL or CANSM_BSM_S_NOCOM state*/
        CanSM_PnNot_CC_Sleep_Wait(netID, networkPtr);
        break;
#if (CANSM_TRCV_NUM > 0)
    case DEINITPNNOT_S_TRCV_NORMAL:
        CanSM_PnNot_Trcv_Normal(netID, networkPtr);
        break;
    case DEINITPNNOT_S_TRCV_NORMAL_WAIT:
        /*enter DEINITPNNOT_S_TRCV_STANDBY state*/
        CanSM_PnNot_Trcv_Normal_Wait(networkPtr);
        break;
    case DEINITPNNOT_S_TRCV_STANDBY:
        CanSM_PnNot_Trcv_Standby(netID, networkPtr);
        break;
    case DEINITPNNOT_S_TRCV_STANDBY_WAIT:
        /*enter CANSM_BSM_S_NOCOM state*/
        CanSM_PnNot_Trcv_Standby_Wait(netID, networkPtr);
        break;
#endif
    default:
        /*This logic does not require any processing*/
        break;
    }
    return;
}

#if (STD_ON == CANSM_PNC_SUPPORT)
/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_PN_CLEAR_WUF
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_S_Pn_Clear_WUF(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    if ((0u == networkPtr->ModeRequestRepetitionTime)
        && (networkPtr->repeatCounter <= CanSM_ConfigPtr->CanSMModeRequestRepetitionMax))
    {
        ret = CanIf_ClearTrcvWufFlag(CANSM_NETWORK_TRANSCEIVER(netID)->CanSMTransceiverId);
        if ((uint8)E_NOT_OK == ret)
        {
            networkPtr->ModeRequestRepetitionTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
        }
        networkPtr->repeatCounter++;
    }
    /*enter DEINITPN_S_PN_CC_STOPPED state*/
    if (T_CLEAR_WUF_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CC_STOPPED;
        networkPtr->repeatCounter = 0u;
        networkPtr->ModeRequestRepetitionTime = 0;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;*/
        }
        /*enter DEINITPN_S_PN_CLEAR_WUF_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_PN_CLEAR_WUF_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_S_Pn_Clear_WUF_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    if (T_CLEAR_WUF_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CC_STOPPED;
        networkPtr->waitCanIfIndicatedStartTime = 0u;
    }
    else
    {
        /*T_CLEAR_WUF_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_PN_CC_STOPPED
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_S_Pn_CC_Stopped(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret;
    /*set all controllers of the network to request mode repeat*/
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_STOPPED);
    /*enter DEINITPN_S_TRCV_NORMAL state*/
    if (T_CC_STOPED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnSupportedState = DEINITPN_S_TRCV_NORMAL;
        networkPtr->repeatCounter = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;*/
        }
        /*enter DEINITPN_S_CC_STOPPED_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->deinitPnSupportedState = DEINITPN_S_CC_STOPPED_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_CC_STOPPED_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_S_Pn_CC_Stopped_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    if (T_CC_STOPED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnSupportedState = DEINITPN_S_TRCV_NORMAL;
        networkPtr->waitCanIfIndicatedStartTime = 0u;
    }
    else
    {
        /*T_CC_STOPPED_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CC_STOPPED;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_TRCV_NORMAL
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_S_Trcv_Normal(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    if ((0u == networkPtr->ModeRequestRepetitionTime)
        && (networkPtr->repeatCounter <= CanSM_ConfigPtr->CanSMModeRequestRepetitionMax))
    {
        ret = CanIf_SetTrcvMode(CANSM_NETWORK_TRANSCEIVER(netID)->CanSMTransceiverId, CANTRCV_TRCVMODE_NORMAL);
        if ((uint8)E_NOT_OK == ret)
        {
            networkPtr->ModeRequestRepetitionTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
        }
        networkPtr->repeatCounter++;
    }
    /*enter DEINITPN_S_TRCV_STANDBY state*/
    if (T_TRCV_NORMAL_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnSupportedState = DEINITPN_S_TRCV_STANDBY;
        networkPtr->repeatCounter = 0u;
        networkPtr->ModeRequestRepetitionTime = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;*/
        }
        /*enter DEINITPN_S_TRCV_NORMAL_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->deinitPnSupportedState = DEINITPN_S_TRCV_NORMAL_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_TRCV_NORMAL_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_S_Trcv_Normal_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    if (T_TRCV_NORMAL_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnSupportedState = DEINITPN_S_TRCV_STANDBY;
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*T_TRCV_NORMAL_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->deinitPnSupportedState = DEINITPN_S_TRCV_NORMAL;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_TRCV_STANDBY
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_S_Trcv_Standby(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    if ((0u == networkPtr->ModeRequestRepetitionTime)
        && (networkPtr->repeatCounter <= CanSM_ConfigPtr->CanSMModeRequestRepetitionMax))
    {
        ret = CanIf_SetTrcvMode(CANSM_NETWORK_TRANSCEIVER(netID)->CanSMTransceiverId, CANTRCV_TRCVMODE_STANDBY);
        if ((uint8)E_NOT_OK == ret)
        {
            networkPtr->ModeRequestRepetitionTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
            networkPtr->repeatCounter++;
        }
    }
    /*enter DEINITPN_S_CC_SLEEP state*/
    if (T_TRCV_STANDBY_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnSupportedState = DEINITPN_S_CC_SLEEP;
        networkPtr->repeatCounter = 0u;
        networkPtr->ModeRequestRepetitionTime = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;*/
        }
        /*enter DEINITPN_S_TRCV_STANDBY_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->deinitPnSupportedState = DEINITPN_S_TRCV_STANDBY_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_TRCV_STANDBY_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_S_Trcv_Standby_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    if (T_TRCV_STANDBY_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnSupportedState = DEINITPN_S_CC_SLEEP;
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*CANSM_BSM_T_TRCV_STANDBY_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->deinitPnSupportedState = DEINITPN_S_TRCV_STANDBY;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_CC_SLEEP
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_S_CC_Sleep(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret;
    /*set all controllers of the network to request mode repeat*/
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_SLEEP);
    /*enter DEINITPN_S_CHECK_WFLAG_IN_CC_SLEEP state*/
    if (T_CC_SLEEP_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnSupportedState = DEINITPN_S_CHECK_WFLAG_IN_CC_SLEEP;
        networkPtr->repeatCounter = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;*/
        }
        /*enter DEINITPN_S_CC_SLEEP_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->deinitPnSupportedState = DEINITPN_S_CC_SLEEP_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_CC_SLEEP_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_S_CC_Sleep_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    if (T_CC_SLEEP_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->deinitPnSupportedState = DEINITPN_S_CHECK_WFLAG_IN_CC_SLEEP;
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*CANSM_BSM_T_CC_SLEEP_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->deinitPnSupportedState = DEINITPN_S_CHECK_WFLAG_IN_NOT_CC_SLEEP;
            networkPtr->repeatCounter = 0u;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_CHECK_WFLAG_IN_CC_SLEEP
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_Check_Wflag_InCCSleep(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    ComM_ModeType ComMode;
    if ((0u == networkPtr->ModeRequestRepetitionTime)
        && (networkPtr->repeatCounter <= CanSM_ConfigPtr->CanSMModeRequestRepetitionMax))
    {
        ret = CanIf_CheckTrcvWakeFlag(CANSM_NETWORK_TRANSCEIVER(netID)->CanSMTransceiverId);
        if ((uint8)E_NOT_OK == ret)
        {
            networkPtr->ModeRequestRepetitionTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
        }
        networkPtr->repeatCounter++;
    }
    /*enter CANSM_BSM_S_NOCOM state*/
    if (T_CHECK_WFLAG_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->curBsmState = CANSM_BSM_S_NOCOM;
        ComMode = COMM_NO_COMMUNICATION;
        /*do E_NOCOM action*/
        ComM_BusSM_ModeIndication(CANSM_NETWORK_HANDLE(netID), ComMode);
        networkPtr->repeatCounter = 0u;
        networkPtr->ModeRequestRepetitionTime = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;*/
        }
        /*enter DEINITPN_S_CHECK_WUF_IN_CC_SLEEP_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->deinitPnSupportedState = DEINITPN_S_CHECK_WUF_IN_CC_SLEEP_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_CHECK_WUF_IN_CC_SLEEP_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_Check_Wflag_InCCSleepWait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    ComM_ModeType ComMode;
    if (T_CHECK_WFLAG_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->curBsmState = CANSM_BSM_S_NOCOM;
        ComMode = COMM_NO_COMMUNICATION;
        /*do E_NOCOM action*/
        ComM_BusSM_ModeIndication(CANSM_NETWORK_HANDLE(netID), ComMode);
        networkPtr->waitCanIfIndicatedStartTime = 0u;
    }
    else
    {
        /*T_CHECK_WFLAG_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->deinitPnSupportedState = DEINITPN_S_CHECK_WFLAG_IN_CC_SLEEP;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_CHECK_WFLAG_IN_NOT_CC_SLEEP
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_CheckWflag_InNotCCSleep(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    if ((0u == networkPtr->ModeRequestRepetitionTime)
        && (networkPtr->repeatCounter <= CanSM_ConfigPtr->CanSMModeRequestRepetitionMax))
    {
        ret = CanIf_CheckTrcvWakeFlag(CANSM_NETWORK_TRANSCEIVER(netID)->CanSMTransceiverId);
        if ((uint8)E_NOT_OK == ret)
        {
            networkPtr->ModeRequestRepetitionTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
        }
        networkPtr->repeatCounter++;
    }
    /*enter DEINITPN_S_PN_CLEAR_WUF state*/
    if (T_CHECK_WFLAG_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->repeatCounter = 0u;
        networkPtr->ModeRequestRepetitionTime = 0u;
        networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;*/
        }
        /*enter DEINITPN_S_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->deinitPnSupportedState = DEINITPN_S_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DEINITPN_S_CHECK_WFLAG_IN_NOT_CC_SLEEP
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Pn_CheckWFlag_InNotCCSleepWait(CanSM_NetWorkRunTimeType* networkPtr)
{
    if (T_CHECK_WFLAG_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->waitCanIfIndicatedStartTime = 0;
        networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;
    }
    else
    {
        /*T_CHECK_WFLAG_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->deinitPnSupportedState = DEINITPN_S_CHECK_WFLAG_IN_NOT_CC_SLEEP;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in DeinitPnSupported
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_DeinitPnSupported(uint8 netID)
{
    CanSM_NetWorkRunTimeType* networkPtr = &CanSM_NetWorkRunTime[netID];
    switch (networkPtr->deinitPnSupportedState)
    {
    case DEINITPN_S_PN_CLEAR_WUF:
        CanSM_Pn_S_Pn_Clear_WUF(netID, networkPtr);
        break;
    case DEINITPN_S_PN_CLEAR_WUF_WAIT:
        /*enter DEINITPN_S_PN_CC_STOPPED state*/
        CanSM_Pn_S_Pn_Clear_WUF_Wait(networkPtr);
        break;
    case DEINITPN_S_PN_CC_STOPPED:
        CanSM_Pn_S_Pn_CC_Stopped(netID, networkPtr);
        break;
    case DEINITPN_S_CC_STOPPED_WAIT:
        /*enter DEINITPN_S_TRCV_NORMAL state*/
        CanSM_Pn_S_Pn_CC_Stopped_Wait(networkPtr);
        break;
    case DEINITPN_S_TRCV_NORMAL:
        CanSM_Pn_S_Trcv_Normal(netID, networkPtr);
        break;
    case DEINITPN_S_TRCV_NORMAL_WAIT:
        /*enter DEINITPN_S_TRCV_STANDBY state*/
        CanSM_Pn_S_Trcv_Normal_Wait(networkPtr);
        break;
    case DEINITPN_S_TRCV_STANDBY:
        CanSM_Pn_S_Trcv_Standby(netID, networkPtr);
        break;
    case DEINITPN_S_TRCV_STANDBY_WAIT:
        /*enter DEINITPN_S_CC_SLEEP state*/
        CanSM_Pn_S_Trcv_Standby_Wait(networkPtr);
        break;
    case DEINITPN_S_CC_SLEEP:
        CanSM_Pn_S_CC_Sleep(netID, networkPtr);
        break;
    case DEINITPN_S_CC_SLEEP_WAIT:
        /*enter DEINITPN_S_CHECK_WFLAG_IN_CC_SLEEP state*/
        CanSM_Pn_S_CC_Sleep_Wait(networkPtr);
        break;
    case DEINITPN_S_CHECK_WFLAG_IN_CC_SLEEP:
        CanSM_Pn_Check_Wflag_InCCSleep(netID, networkPtr);
        break;
    case DEINITPN_S_CHECK_WUF_IN_CC_SLEEP_WAIT:
        /*enter CANSM_BSM_S_NOCOM state*/
        CanSM_Pn_Check_Wflag_InCCSleepWait(netID, networkPtr);
        break;
    case DEINITPN_S_CHECK_WFLAG_IN_NOT_CC_SLEEP:
        CanSM_Pn_CheckWflag_InNotCCSleep(netID, networkPtr);
        break;
    case DEINITPN_S_CHECK_WUF_IN_NOT_CC_SLEEP_WAIT:
        /*enter DEINITPN_S_PN_CLEAR_WUF state*/
        CanSM_Pn_CheckWFlag_InNotCCSleepWait(networkPtr);
        break;
    default:
        /*nothing*/
        break;
    }
    return;
}
#endif

/******************************************************************************/
/*
 * Brief               Handle state transition in Bsm_S_NoCom
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_BsmSNoCom(uint8 netID)
{
    if (CANSM_FULL_COMMUNICATION == CanSM_NetWorkRunTime[netID].requestComMode)
    {
        /*enter CANSM_BSM_S_PRE_FULLCOM state*/
        CanSM_NetWorkRunTime[netID].curBsmState = CANSM_BSM_S_PRE_FULLCOM;
#if (CANSM_TRCV_NUM > 0)
        /*enter sub PREFULLCOM_S_TRCV_NORMAL state*/
        if (NULL_PTR != CANSM_NETWORK_TRANSCEIVER(netID))
        {
            CanSM_NetWorkRunTime[netID].preFullComState = PREFULLCOM_S_TRCV_NORMAL;
            CanSM_NetWorkRunTime[netID].repeatCounter = 0u;
        }
        /*enter sub PREFULLCOM_S_CC_STOPPED state*/
        else
#endif
        {
            CanSM_NetWorkRunTime[netID].preFullComState = PREFULLCOM_S_CC_STOPPED;
            CanSM_NetWorkRunTime[netID].repeatCounter = 0u;
        }
    }
    return;
}

#if (CANSM_TRCV_NUM > 0)
/******************************************************************************/
/*
 * Brief               Handle state transition in WUVALIDATION_S_TRCV_NORMAL
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_WUVAL_S_Trcv_Normal(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    if ((0u == networkPtr->ModeRequestRepetitionTime)
        && (networkPtr->repeatCounter <= CanSM_ConfigPtr->CanSMModeRequestRepetitionMax))
    {
        ret = CanIf_SetTrcvMode(CANSM_NETWORK_TRANSCEIVER(netID)->CanSMTransceiverId, CANTRCV_TRCVMODE_NORMAL);
        if ((uint8)E_NOT_OK == ret)
        {
            networkPtr->ModeRequestRepetitionTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
        }
        networkPtr->repeatCounter++;
    }
    /*enter WUVALIDATION_S_CC_STOPPED state*/
    if (T_TRCV_NORMAL_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->wuValidationState = WUVALIDATION_S_CC_STOPPED;
        networkPtr->repeatCounter = 0u;
        networkPtr->ModeRequestRepetitionTime = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            /*                        #if(STD_ON == CANSM_PNC_SUPPORT)
                        if((NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).TrcvRef)
                            && (TRUE == CANSM_NETWORK_CONFIGURATION(netID).TrcvRef->CanSMCanTrcvPnEnabled))
                        {
                            networkPtr->curBsmState = CANSM_BSM_DEINITPNSUPPORTED;
                            networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;
                        }
                        else
                        #endif
                        {
                            networkPtr->curBsmState = CANSM_BSM_DEINITPNNOTSUPPORTED;
                            networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;
                        }*/
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
        }
        /*enter WUVALIDATION_S_TRCV_NORMAL_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->wuValidationState = WUVALIDATION_S_TRCV_NORMAL_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in WUVALIDATION_S_TRCV_NORMAL_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_WUVAL_S_Trcv_Normal_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    if (T_TRCV_NORMAL_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->wuValidationState = WUVALIDATION_S_CC_STOPPED;
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*T_TRCV_NORMAL_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->wuValidationState = WUVALIDATION_S_TRCV_NORMAL;
        }
    }
}
#endif

/******************************************************************************/
/*
 * Brief               Handle state transition in WUVALIDATION_S_CC_STOPPED
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_WUVAL_S_CC_Stopped(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret;
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_STOPPED);
    /*enter WUVALIDATION_S_CC_STARTED state*/
    if (T_CC_STOPED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->wuValidationState = WUVALIDATION_S_CC_STARTED;
        networkPtr->repeatCounter = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            /*                        #if(STD_ON == CANSM_PNC_SUPPORT)
                    if((NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).TrcvRef)
                        && (TRUE == CANSM_NETWORK_CONFIGURATION(netID).TrcvRef->CanSMCanTrcvPnEnabled))
                    {
                        networkPtr->curBsmState = CANSM_BSM_DEINITPNSUPPORTED;
                        networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;
                    }
                    else
                    #endif
                    {
                        networkPtr->curBsmState = CANSM_BSM_DEINITPNNOTSUPPORTED;
                        networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;
                    }*/
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
        }
        /*enter WUVALIDATION_S_CC_STOPPED_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->wuValidationState = WUVALIDATION_S_CC_STOPPED_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in WUVALIDATION_S_CC_STOPPED_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_WUVAL_S_CC_Stopped_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    if (T_CC_STOPED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->wuValidationState = WUVALIDATION_S_CC_STARTED;
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*T_CC_STOPPED_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->wuValidationState = WUVALIDATION_S_CC_STOPPED;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in WUVALIDATION_S_CC_STARTED
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_WUVAL_S_CC_Started(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret;
    /*set all controllers of the network to request mode repeat*/
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_STARTED);
    /*enter WUVALIDATION_WAIT_WUVALIDATION_LEAVE state*/
    if (T_CC_STARTED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->wuValidationState = WUVALIDATION_WAIT_WUVALIDATION_LEAVE;
        networkPtr->repeatCounter = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            /*                        #if(STD_ON == CANSM_PNC_SUPPORT)
                        if((NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).TrcvRef)
                            && (TRUE == CANSM_NETWORK_CONFIGURATION(netID).TrcvRef->CanSMCanTrcvPnEnabled))
                        {
                            networkPtr->curBsmState = CANSM_BSM_DEINITPNSUPPORTED;
                            networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;
                        }
                        else
                        #endif
                        {
                            networkPtr->curBsmState = CANSM_BSM_DEINITPNNOTSUPPORTED;
                            networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;
                        }*/
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
        }
        /*enter WUVALIDATION_S_CC_STARTED_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->wuValidationState = WUVALIDATION_S_CC_STARTED_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in WUVALIDATION_S_CC_STARTED_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_WUVAL_S_CC_Started_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    if (T_CC_STARTED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->wuValidationState = WUVALIDATION_WAIT_WUVALIDATION_LEAVE;
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*T_CC_STARTED_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->wuValidationState = WUVALIDATION_S_CC_STARTED;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Bsm_WuValidation
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_BsmWuValidation(uint8 netID)
{
    CanSM_NetWorkRunTimeType* networkPtr = &CanSM_NetWorkRunTime[netID];
    if (CANSM_FULL_COMMUNICATION == networkPtr->requestComMode)
    {
        /*enter CANSM_BSM_S_PRE_FULLCOM state*/
        networkPtr->curBsmState = CANSM_BSM_S_PRE_FULLCOM;
#if (CANSM_TRCV_NUM > 0)
        /*enter sub PREFULLCOM_S_TRCV_NORMAL state*/
        if (NULL_PTR != CANSM_NETWORK_TRANSCEIVER(netID))
        {
            networkPtr->preFullComState = PREFULLCOM_S_TRCV_NORMAL;
            networkPtr->repeatCounter = 0u;
        }
        /*enter sub PREFULLCOM_S_CC_STOPPED state*/
        else
#endif
        {
            networkPtr->preFullComState = PREFULLCOM_S_CC_STOPPED;
            networkPtr->repeatCounter = 0u;
        }
    }
    else
    {
        switch (networkPtr->wuValidationState)
        {
#if (CANSM_TRCV_NUM > 0)
        case WUVALIDATION_S_TRCV_NORMAL:
            CanSM_WUVAL_S_Trcv_Normal(netID, networkPtr);
            break;
        case WUVALIDATION_S_TRCV_NORMAL_WAIT:
            /*enter WUVALIDATION_S_CC_STOPPED state*/
            CanSM_WUVAL_S_Trcv_Normal_Wait(networkPtr);
            break;
#endif
        case WUVALIDATION_S_CC_STOPPED:
            /*set all controllers of the network to request mode repeat*/
            CanSM_WUVAL_S_CC_Stopped(netID, networkPtr);
            break;
        case WUVALIDATION_S_CC_STOPPED_WAIT:
            /*enter WUVALIDATION_S_CC_STARTED state*/
            CanSM_WUVAL_S_CC_Stopped_Wait(networkPtr);
            break;
        case WUVALIDATION_S_CC_STARTED:
            CanSM_WUVAL_S_CC_Started(netID, networkPtr);
            break;
        case WUVALIDATION_S_CC_STARTED_WAIT:
            /*enter WUVALIDATION_WAIT_WUVALIDATION_LEAVE state*/
            CanSM_WUVAL_S_CC_Started_Wait(networkPtr);
            break;
        default:
            /*WUVALIDATION_WAIT_WUVALIDATION_LEAVE state will do nothing*/
            break;
        }
    }
    return;
}

#if (CANSM_TRCV_NUM > 0)
/******************************************************************************/
/*
 * Brief               Handle state transition in PREFULLCOM_S_TRCV_NORMAL
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Prefullcom_S_Trcv_Normal(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret = E_NOT_OK;
    if ((0u == networkPtr->ModeRequestRepetitionTime)
        && (networkPtr->repeatCounter <= CanSM_ConfigPtr->CanSMModeRequestRepetitionMax))
    {
        ret = CanIf_SetTrcvMode(CANSM_NETWORK_TRANSCEIVER(netID)->CanSMTransceiverId, CANTRCV_TRCVMODE_NORMAL);
        if ((uint8)E_NOT_OK == ret)
        {
            networkPtr->ModeRequestRepetitionTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
        }
        networkPtr->repeatCounter++;
    }
    /*enter PREFULLCOM_S_CC_STOPPED state*/
    if (T_TRCV_NORMAL_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->preFullComState = PREFULLCOM_S_CC_STOPPED;
        networkPtr->repeatCounter = 0u;
        networkPtr->ModeRequestRepetitionTime = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            /*                    #if(STD_ON == CANSM_PNC_SUPPORT)
                        if((NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).TrcvRef)
                            && (TRUE == CANSM_NETWORK_CONFIGURATION(netID).TrcvRef->CanSMCanTrcvPnEnabled))
                        {
                            networkPtr->curBsmState = CANSM_BSM_DEINITPNSUPPORTED;
                            networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;
                        }
                        else
                        #endif
                        {
                            networkPtr->curBsmState = CANSM_BSM_DEINITPNNOTSUPPORTED;
                            networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;
                        }*/
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
        }
        /*enter PREFULLCOM_S_TRCV_NORMAL_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->preFullComState = PREFULLCOM_S_TRCV_NORMAL_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in PREFULLCOM_S_TRCV_NORMAL_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Prefullcom_S_Trcv_Normal_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    /*enter PREFULLCOM_S_CC_STOPPED state*/
    if (T_TRCV_NORMAL_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->preFullComState = PREFULLCOM_S_CC_STOPPED;
        networkPtr->waitCanIfIndicatedStartTime = 0u;
    }
    else
    {
        /*T_TRCV_NORMAL_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->preFullComState = PREFULLCOM_S_TRCV_NORMAL;
        }
    }
}
#endif

/******************************************************************************/
/*
 * Brief               Handle state transition in PREFULLCOM_S_CC_STOPPED
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Prefullcom_S_CC_Stopped(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret;
    /*set all controllers of the network to request mode repeat*/
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_STOPPED);
    /*enter PREFULLCOM_S_CC_STARTED state*/
    if (T_CC_STOPED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->preFullComState = PREFULLCOM_S_CC_STARTED;
        networkPtr->repeatCounter = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            /*          #if(STD_ON == CANSM_PNC_SUPPORT)
                        if((NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).TrcvRef)
                            && (TRUE == CANSM_NETWORK_CONFIGURATION(netID).TrcvRef->CanSMCanTrcvPnEnabled))
                        {
                            networkPtr->curBsmState = CANSM_BSM_DEINITPNSUPPORTED;
                            networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;
                        }
                        else
                        #endif
                        {
                            networkPtr->curBsmState = CANSM_BSM_DEINITPNNOTSUPPORTED;
                            networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;
                        }*/
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
        }
        /*enter PREFULLCOM_S_CC_STOPPED_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->preFullComState = PREFULLCOM_S_CC_STOPPED_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in PREFULLCOM_S_CC_STOPPED_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Prefullcom_S_CC_Stopped_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    /*enter PREFULLCOM_S_CC_STARTED state*/
    if (T_CC_STOPED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->preFullComState = PREFULLCOM_S_CC_STARTED;
        networkPtr->waitCanIfIndicatedStartTime = 0u;
    }
    else
    {
        /*T_CC_STOPPED_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->preFullComState = PREFULLCOM_S_CC_STOPPED;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in PREFULLCOM_S_CC_STARTED
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Prefullcom_S_CC_Started(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret;
    /*set all controllers of the network to request mode repeat*/
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_STARTED);
    /*do E_FULL_COM action,enter CANSM_BSM_S_FULLCOM,sub FULLCOM_S_BUS_OFF_CHECK state*/
    if (T_CC_STARTED_INDICATED == networkPtr->canIfIndicated)
    {
        CanSM_EFullComAction(netID);
        networkPtr->repeatCounter = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            /*                    #if(STD_ON == CANSM_PNC_SUPPORT)
                        if((NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).TrcvRef)
                            && (TRUE == CANSM_NETWORK_CONFIGURATION(netID).TrcvRef->CanSMCanTrcvPnEnabled))
                        {
                            networkPtr->curBsmState = CANSM_BSM_DEINITPNSUPPORTED;
                            networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;
                        }
                        else
                        #endif
                        {
                            networkPtr->curBsmState = CANSM_BSM_DEINITPNNOTSUPPORTED;
                            networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;
                        }*/
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
        }
        /*enter PREFULLCOM_S_CC_STARTED_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->preFullComState = PREFULLCOM_S_CC_STARTED_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in PREFULLCOM_S_CC_STARTED_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_Prefullcom_S_CC_Started_Wait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    /*do E_FULL_COM action,enter CANSM_BSM_S_FULLCOM,sub FULLCOM_S_BUS_OFF_CHECK state*/
    if (T_CC_STARTED_INDICATED == networkPtr->canIfIndicated)
    {
        CanSM_EFullComAction(netID);
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*T_CC_STARTED_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->preFullComState = PREFULLCOM_S_CC_STARTED;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Bsm_S_Pre_FullCom
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_BsmSPreFullCom(uint8 netID)
{
    CanSM_NetWorkRunTimeType* networkPtr = &CanSM_NetWorkRunTime[netID];
    switch (networkPtr->preFullComState)
    {
#if (CANSM_TRCV_NUM > 0)
    case PREFULLCOM_S_TRCV_NORMAL:
        CanSM_Prefullcom_S_Trcv_Normal(netID, networkPtr);
        break;
    case PREFULLCOM_S_TRCV_NORMAL_WAIT:
        CanSM_Prefullcom_S_Trcv_Normal_Wait(networkPtr);
        break;
#endif
    case PREFULLCOM_S_CC_STOPPED:
        CanSM_Prefullcom_S_CC_Stopped(netID, networkPtr);
        break;
    case PREFULLCOM_S_CC_STOPPED_WAIT:
        CanSM_Prefullcom_S_CC_Stopped_Wait(networkPtr);
        break;
    case PREFULLCOM_S_CC_STARTED:
        CanSM_Prefullcom_S_CC_Started(netID, networkPtr);
        break;
    case PREFULLCOM_S_CC_STARTED_WAIT:
        CanSM_Prefullcom_S_CC_Started_Wait(netID, networkPtr);
        break;
    default:
        /*This logic does not require any processing*/
        break;
    }
    return;
}

/******************************************************************************/
/*
 * Brief               Handle state transition in FULLCOM_S_BUS_OFF_CHECK
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     networkPtr,NetWork RunTime struct ptr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_FullCom_S_Bus_off_Check(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    uint8 cnt;
    uint8 controllerID;
    boolean gBusOffPassive = FALSE;
    if ((boolean)FALSE == CANSM_NETWORK_CONFIGURATION(netID).CanSMBorTxConfirmationPolling)
    {
        if (networkPtr->borTimeTxEnsuredTime > 0u)
        {
            networkPtr->borTimeTxEnsuredTime--;
        }
        /*the time duration since the effect E_TX_ON is greater or equal the configuration parameter
         * CANSM_BOR_TIME_TX_ENSURED*/
        if (0u == networkPtr->borTimeTxEnsuredTime)
        {
            gBusOffPassive = TRUE;
        }
    }
    else
    {
        gBusOffPassive = TRUE;
        for (cnt = 0u;
             (cnt < CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber) && ((boolean)TRUE == gBusOffPassive);
             cnt++)
        {
            controllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
            if (CANIF_TX_RX_NOTIFICATION != CanIf_GetTxConfirmationState(controllerID))
            {
                gBusOffPassive = FALSE;
            }
        }
    }
    if ((boolean)TRUE == gBusOffPassive)
    {
#if (STD_ON == CANSM_DEM_SUPPORT)
        if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
        {
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->BusOffPara)
            {
                Dem_ReportErrorStatus(
                    *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->BusOffPara,
                    DEM_EVENT_STATUS_PASSED);
            }
        }
#endif /*if (STD_ON == CANSM_DEM_SUPPORT)*/
        networkPtr->fullComState = FULLCOM_S_NO_BUS_OFF;
        networkPtr->busOffCounter = 0u;
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in FULLCOM_S_CC_STOPPED
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     networkPtr,NetWork RunTime struct ptr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_FullCom_S_CC_Stopped(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret;
    /*set all controllers of the network to request mode repeat*/
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_STOPPED);
    /*enter FULLCOM_S_CC_STARTED state*/
    if (T_CC_STOPED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->fullComState = FULLCOM_S_CC_STARTED;
        networkPtr->repeatCounter = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*CanSM_EPreNoComAction(netID);*/
        }
        /*enter FULLCOM_S_CC_STOPPED_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->fullComState = FULLCOM_S_CC_STOPPED_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in FULLCOM_S_CC_STOPPED_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     networkPtr,NetWork RunTime struct ptr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_FullCom_S_CC_Stopped_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    /*enter FULLCOM_S_CC_STARTED state*/
    if (T_CC_STOPED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->fullComState = FULLCOM_S_CC_STARTED;
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*T_CC_STOPPED_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->fullComState = FULLCOM_S_CC_STOPPED;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in FULLCOM_S_CC_STARTED
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     networkPtr,NetWork RunTime struct ptr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_FullCom_S_CC_Started(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret;
    /*set all controllers of the network to request mode repeat*/
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_STARTED);
    /*enter FULLCOM_S_BUS_OFF_CHECK state,clear BusOff counter*/
    if (T_CC_STARTED_INDICATED == networkPtr->canIfIndicated)
    {
        uint8 cnt;
        uint8 controllerID;
        networkPtr->fullComState = FULLCOM_S_NO_BUS_OFF;
        networkPtr->busOffCounter = 0u;
        networkPtr->repeatCounter = 0u;
        for (cnt = 0u; cnt < CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber; cnt++)
        {
            controllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
            (void)CanIf_SetPduMode(controllerID, CANIF_ONLINE);
        }
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*CanSM_EPreNoComAction(netID);*/
        }
        /*enter FULLCOM_S_CC_STARTED_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->fullComState = FULLCOM_S_CC_STARTED_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in FULLCOM_S_CC_STARTED_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     networkPtr,NetWork RunTime struct ptr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_FullCom_S_CC_Started_Wait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    /*enter FULLCOM_S_BUS_OFF_CHECK state,clear BusOff counter*/
    if (T_CC_STARTED_INDICATED == networkPtr->canIfIndicated)
    {
        uint8 cnt;
        uint8 controllerID;
        networkPtr->fullComState = FULLCOM_S_NO_BUS_OFF;
        networkPtr->busOffCounter = 0u;
        networkPtr->waitCanIfIndicatedStartTime = 0;
        for (cnt = 0u; cnt < CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber; cnt++)
        {
            controllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
            (void)CanIf_SetPduMode(controllerID, CANIF_ONLINE);
        }
    }
    else
    {
        /*T_CC_STARTED_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->fullComState = FULLCOM_S_CC_STARTED;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in FULLCOM_S_RESTART_CC
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     networkPtr,NetWork RunTime struct ptr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_FullCom_S_Restart_CC(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret;
    /*set all controllers of the network to request mode repeat*/
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_STARTED);
    /*enter FULLCOM_S_TX_OFF state*/
    if (T_CC_STARTED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->fullComState = FULLCOM_S_TX_OFF;
        networkPtr->repeatCounter = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /* CanSM_EPreNoComAction(netID);*/
        }
        /*enter FULLCOM_S_RESTART_CC_WAIT state*/
        else
        {
            if (E_NOT_OK == ret)
            {
                networkPtr->fullComState = FULLCOM_S_RESTART_CC_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in FULLCOM_S_RESTART_CC_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     networkPtr,NetWork RunTime struct ptr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_FullCom_S_Restart_CC_Wait(CanSM_NetWorkRunTimeType* networkPtr)
{
    /*enter FULLCOM_S_TX_OFF state*/
    if (T_CC_STARTED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->fullComState = FULLCOM_S_TX_OFF;
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*T_RESTART_CC_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->fullComState = FULLCOM_S_RESTART_CC;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in FULLCOM_S_TX_OFF
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     networkPtr,NetWork RunTime struct ptr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_FullCom_S_Tx_Off(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    uint8 cnt;
    uint8 controllerID;
    uint32 busOffContinueTime;
    ComM_ModeType ComMode;
    networkPtr->busOffEventStartTime++;
    if (networkPtr->busOffCounter >= CANSM_NETWORK_CONFIGURATION(netID).CanSMBorCounterL1ToL2)
    {
        busOffContinueTime =
            (uint32)(CANSM_NETWORK_CONFIGURATION(netID).CanSMBorTimeL2) / (uint32)(CANSM_MAINFUNCTION_PERIOD)
#if (STD_ON == CANSM_GET_BUSOFF_DELAY_FUNCTION_USED)
            + (uint32)networkPtr->busOffDelayTime
#endif
            ;
    }
    else
    {
        busOffContinueTime =
            (uint32)(CANSM_NETWORK_CONFIGURATION(netID).CanSMBorTimeL1) / (uint32)(CANSM_MAINFUNCTION_PERIOD)
#if (STD_ON == CANSM_GET_BUSOFF_DELAY_FUNCTION_USED)
            + (uint32)networkPtr->busOffDelayTime
#endif
            ;
    }
    /*G_TX_ON state is OK*/
    if (networkPtr->busOffEventStartTime >= busOffContinueTime)
    {
/*do the E_TX_ON action*/
#if (STD_ON == CANSM_TX_OFFLINE_ACTIVE_SUPPORT)
        if ((boolean)TRUE == CanSM_EcuPassive)
        {
            for (cnt = 0u; cnt < CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber; cnt++)
            {
                controllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
                (void)CanIf_SetPduMode(controllerID, CANIF_TX_OFFLINE_ACTIVE);
            }
        }
        else
#endif /*STD_ON == CANSM_TX_OFFLINE_ACTIVE_SUPPORT*/
        {
            for (cnt = 0u; cnt < CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber; cnt++)
            {
                controllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
                (void)CanIf_SetPduMode(controllerID, CANIF_ONLINE);
            }
        }
        (void)BswM_CanSM_CurrentState(CANSM_NETWORK_HANDLE(netID), CANSM_BSWM_FULL_COMMUNICATION);
        ComMode = COMM_FULL_COMMUNICATION;
        ComM_BusSM_ModeIndication(CANSM_NETWORK_HANDLE(netID), ComMode);
        /*enter FULLCOM_S_BUS_OFF_CHECK state*/
        networkPtr->fullComState = FULLCOM_S_BUS_OFF_CHECK;
        if (networkPtr->busOffCounter < BUS_OFF_COUNTER_UP_LIMIT)
        {
            networkPtr->busOffCounter++;
        }
        if ((boolean)FALSE == CANSM_NETWORK_CONFIGURATION(netID).CanSMBorTxConfirmationPolling)
        {
            networkPtr->borTimeTxEnsuredTime = CANSM_NETWORK_BORTXENSUREDTIME(netID);
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Bsm_S_FullCom
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_BsmSFullCom(uint8 netID)
{
    CanSM_NetWorkRunTimeType* networkPtr = &CanSM_NetWorkRunTime[netID];

    if (CANSM_NO_COMMUNICATION == networkPtr->requestComMode)
    {
        CanSM_EPreNoComAction(netID);
    }
    else if (CANSM_SILENT_COMMUNICATION == networkPtr->requestComMode)
    {
        CanSM_EFullToSilentComAction(netID);
    }
    else
    {
        switch (networkPtr->fullComState)
        {
        case FULLCOM_S_BUS_OFF_CHECK:
            CanSM_FullCom_S_Bus_off_Check(netID, networkPtr);
            break;
        case FULLCOM_S_NO_BUS_OFF:
            /*keep the FULLCOM_S_NO_BUS_OFF state until T_TX_TIMEOUT_EXCEPTION,T_BUS_OFF,T_CHANGE_BR_REQUEST happen*/
            break;
        case FULLCOM_S_CC_STOPPED:
            CanSM_FullCom_S_CC_Stopped(netID, networkPtr);
            break;
        case FULLCOM_S_CC_STOPPED_WAIT:
            CanSM_FullCom_S_CC_Stopped_Wait(networkPtr);
            break;
        case FULLCOM_S_CC_STARTED:
            CanSM_FullCom_S_CC_Started(netID, networkPtr);
            break;
        case FULLCOM_S_CC_STARTED_WAIT:
            CanSM_FullCom_S_CC_Started_Wait(netID, networkPtr);
            break;
        case FULLCOM_S_RESTART_CC:
            CanSM_FullCom_S_Restart_CC(netID, networkPtr);
            break;
        case FULLCOM_S_RESTART_CC_WAIT:
            CanSM_FullCom_S_Restart_CC_Wait(networkPtr);
            break;
        case FULLCOM_S_TX_OFF:
            CanSM_FullCom_S_Tx_Off(netID, networkPtr);
            break;
        default:
            /*This logic does not require any processing*/
            break;
        }
    }
    return;
}

#if (STD_ON == CANSM_SET_BAUDRATE_API)
/******************************************************************************/
/*
 * Brief               Handle state transition in Substate CHANGEBR_CHANGE_BR_SYNC
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_ChangeBR_Change_BR_Sync(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    uint8 cnt;
    uint8 controllerID;
    Std_ReturnType ret;
    ret = E_OK;
    for (cnt = 0u; (cnt < CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber) && ((uint8)E_OK == ret); cnt++)
    {
        controllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
        if ((uint8)E_NOT_OK == CanIf_SetBaudrate(controllerID, networkPtr->baudRateConfigID))
        {
            ret = E_NOT_OK;
        }
    }
    /*all CanIf_SetBaudrate requests returned with E_OK*/
    if ((uint8)E_OK == ret)
    {
        if (CANSM_NO_COMMUNICATION == networkPtr->requestComMode)
        {
            CanSM_EPreNoComAction(netID);
        }
        else if (CANSM_SILENT_COMMUNICATION == networkPtr->requestComMode)
        {
            CanSM_EFullToSilentComAction(netID);
        }
        else
        {
            CanSM_EFullComAction(netID);
        }
    }
    /*not all CanIf_SetBaudrate requests returned with E_OK,
     * enter CHANGEBR_S_CC_STOPPED state*/
    else
    {
        networkPtr->changeBaudrateState = CHANGEBR_S_CC_STOPPED;
        networkPtr->repeatCounter = 0u;
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Substate CHANGEBR_S_CC_STOPPED
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     networkPtr,NetWork RunTime struct ptr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_ChangeBR_S_CC_Stopped(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    uint8 cnt;
    uint8 controllerID;
    ComM_ModeType ComMode;
    Std_ReturnType ret;
    /*set all controllers of the network to request mode repeat*/
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_STOPPED);
    /*enter CHANGEBR_S_CC_STARTED state*/
    if (T_CC_STOPED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->changeBaudrateState = CHANGEBR_S_CC_STARTED;
        networkPtr->repeatCounter = 0u;
        ComMode = COMM_NO_COMMUNICATION;
        /*do E_CHANGE_BAUDRATE action*/
        ComM_BusSM_ModeIndication(CANSM_NETWORK_HANDLE(netID), ComMode);
        for (cnt = 0u; cnt < CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber; cnt++)
        {
            controllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
            (void)CanIf_SetBaudrate(controllerID, networkPtr->baudRateConfigID);
        }
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*CanSM_EPreNoComAction(netID);*/
        }
        /*enter CHANGEBR_S_CC_STOPPED_WAIT state*/
        else
        {
            if (E_OK == ret)
            {
                networkPtr->changeBaudrateState = CHANGEBR_S_CC_STOPPED_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Substate CHANGEBR_S_CC_STOPPED_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     networkPtr,NetWork RunTime struct ptr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_ChangeBR_S_CC_Stopped_Wait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    uint8 cnt;
    uint8 controllerID;
    ComM_ModeType ComMode;
    /*enter CHANGEBR_S_CC_STARTED state*/
    if (T_CC_STOPED_INDICATED == networkPtr->canIfIndicated)
    {
        networkPtr->changeBaudrateState = CHANGEBR_S_CC_STARTED;
        networkPtr->repeatCounter = 0u;
        ComMode = COMM_NO_COMMUNICATION;
        /*do E_CHANGE_BAUDRATE action*/
        ComM_BusSM_ModeIndication(CANSM_NETWORK_HANDLE(netID), ComMode);
        for (cnt = 0u; cnt < CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber; cnt++)
        {
            controllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
            (void)CanIf_SetBaudrate(controllerID, networkPtr->baudRateConfigID);
        }
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*T_CC_STOPPED_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->changeBaudrateState = CHANGEBR_S_CC_STOPPED;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Substate CHANGEBR_S_CC_STARTED
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     networkPtr,NetWork RunTime struct ptr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_ChangeBR_S_CC_Started(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    Std_ReturnType ret;
    /*set all controllers of the network to request mode repeat*/
    ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_STARTED);
    /*exit CANSM_BSM_S_CHANGE_BAUDRATE state*/
    if (T_CC_STARTED_INDICATED == networkPtr->canIfIndicated)
    {
        if (CANSM_NO_COMMUNICATION == networkPtr->requestComMode)
        {
            CanSM_EPreNoComAction(netID);
        }
        else if (CANSM_SILENT_COMMUNICATION == networkPtr->requestComMode)
        {
            CanSM_EFullToSilentComAction(netID);
        }
        else
        {
            CanSM_EFullComAction(netID);
        }
        networkPtr->repeatCounter = 0u;
    }
    else
    {
        /*T_REPEAT_MAX*/
        if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
        {
            networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
            if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
            {
                if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                {
                    Dem_ReportErrorStatus(
                        *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                        DEM_EVENT_STATUS_PREFAILED);
                }
            }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
            CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
            /*CanSM_EPreNoComAction(netID);*/
        }
        /*enter CHANGEBR_S_CC_STARTED_WAIT state*/
        else
        {
            if (E_OK == ret)
            {
                networkPtr->changeBaudrateState = CHANGEBR_S_CC_STARTED_WAIT;
                networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                networkPtr->repeatCounter = 0u;
            }
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Substate CHANGEBR_S_CC_STARTED_WAIT
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     networkPtr,NetWork RunTime struct ptr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_ChangeBR_S_CC_Started_Wait(uint8 netID, CanSM_NetWorkRunTimeType* networkPtr)
{
    /*exit CANSM_BSM_S_CHANGE_BAUDRATE state*/
    if (T_CC_STARTED_INDICATED == networkPtr->canIfIndicated)
    {
        if (CANSM_NO_COMMUNICATION == networkPtr->requestComMode)
        {
            CanSM_EPreNoComAction(netID);
        }
        else if (CANSM_SILENT_COMMUNICATION == networkPtr->requestComMode)
        {
            CanSM_EFullToSilentComAction(netID);
        }
        else
        {
            CanSM_EFullComAction(netID);
        }
        networkPtr->waitCanIfIndicatedStartTime = 0;
    }
    else
    {
        /*T_CC_STARTED_TIMEOUT*/
        if (0u == networkPtr->waitCanIfIndicatedStartTime)
        {
            networkPtr->changeBaudrateState = CHANGEBR_S_CC_STARTED;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Bsm_S_Change_Baudrate
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_BsmSChangeBaudrate(uint8 netID)
{
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(CanSM_NetWorkRunTimeType, AUTOMATIC, CANSM_VAR) networkPtr = &CanSM_NetWorkRunTime[netID];
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
    switch (networkPtr->changeBaudrateState)
    {
    case CHANGEBR_CHANGE_BR_SYNC:
        CanSM_ChangeBR_Change_BR_Sync(netID, networkPtr);
        break;
    case CHANGEBR_S_CC_STOPPED:
        CanSM_ChangeBR_S_CC_Stopped(netID, networkPtr);
        break;
    case CHANGEBR_S_CC_STOPPED_WAIT:
        CanSM_ChangeBR_S_CC_Stopped_Wait(netID, networkPtr);
        break;
    case CHANGEBR_S_CC_STARTED:
        CanSM_ChangeBR_S_CC_Started(netID, networkPtr);
        break;
    case CHANGEBR_S_CC_STARTED_WAIT:
        CanSM_ChangeBR_S_CC_Started_Wait(netID, networkPtr);
        break;
    default:
        /*nothing*/
        break;
    }
}
#endif

/******************************************************************************/
/*
 * Brief               Handle state transition in Bsm_S_SilentCom
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_BsmSSilentCom(uint8 netID)
{
    if (CANSM_NO_COMMUNICATION == CanSM_NetWorkRunTime[netID].requestComMode)
    {
        CanSM_EPreNoComAction(netID);
    }
    else if (CANSM_FULL_COMMUNICATION == CanSM_NetWorkRunTime[netID].requestComMode)
    {
        CanSM_EFullComAction(netID);
    }
    else
    {
        /*This logic does not require any processing*/
    }
    return;
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Bsm_S_SilentCom_Bor
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_BsmSSilentComBor(uint8 netID)
{
    Std_ReturnType ret;
    CanSM_NetWorkRunTimeType* networkPtr = &CanSM_NetWorkRunTime[netID];
    if (CANSM_NO_COMMUNICATION == networkPtr->requestComMode)
    {
        CanSM_EPreNoComAction(netID);
    }
    else
    {
        switch (networkPtr->silentComBORState)
        {
        case SILENTBOR_S_RESTART_CC:
            /*set all controllers of the network to request mode repeat*/
            ret = CanSM_SetControllerModeRepeat(netID, networkPtr, CANIF_CS_STARTED);
            /*exit CANSM_BSM_S_SILENTCOM_BOR state,enter CANSM_BSM_S_SILENTCOM state*/
            if (T_CC_STARTED_INDICATED == networkPtr->canIfIndicated)
            {
                networkPtr->curBsmState = CANSM_BSM_S_SILENTCOM;
                networkPtr->repeatCounter = 0u;
            }
            else
            {
                /*T_REPEAT_MAX*/
                if (networkPtr->repeatCounter > CanSM_ConfigPtr->CanSMModeRequestRepetitionMax)
                {
                    networkPtr->repeatCounter = 0u;
#if (STD_ON == CANSM_DEM_SUPPORT)
                    if (NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs)
                    {
                        if (NULL_PTR
                            != CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara)
                        {
                            Dem_ReportErrorStatus(
                                *CANSM_NETWORK_CONFIGURATION(netID).CanSMDemEventParameterRefs->ModeReqTimeoutPara,
                                DEM_EVENT_STATUS_PREFAILED);
                        }
                    }
#endif
#if (STD_ON == CANSM_DEV_ERROR_DETECT)
                    CANSM_DET_REPORTRUNTIMEERROR(SERVICE_ID_CANSM_MAINFUNCTION, CANSM_E_MODE_REQUEST_TIMEOUT);
#endif /* STD_ON == CANSM_DEV_ERROR_DETECT*/
                    /*CanSM_EPreNoComAction(netID);*/
                }
                /*enter SILENTBOR_S_RESTART_CC_WAIT state*/
                else
                {
                    if (E_NOT_OK == ret)
                    {
                        networkPtr->silentComBORState = SILENTBOR_S_RESTART_CC_WAIT;
                        networkPtr->waitCanIfIndicatedStartTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                        networkPtr->repeatCounter = 0u;
                    }
                }
            }
            break;
        case SILENTBOR_S_RESTART_CC_WAIT:
            /*exit CANSM_BSM_S_SILENTCOM_BOR state,enter CANSM_BSM_S_SILENTCOM state*/
            if (T_CC_STARTED_INDICATED == networkPtr->canIfIndicated)
            {
                networkPtr->curBsmState = CANSM_BSM_S_SILENTCOM;
                networkPtr->waitCanIfIndicatedStartTime = 0;
            }
            else
            {
                /*T_RESTART_CC_TIMEOUT*/
                if (0u == networkPtr->waitCanIfIndicatedStartTime)
                {
                    networkPtr->silentComBORState = SILENTBOR_S_RESTART_CC;
                }
            }
            break;
        default:
            /*This logic does not require any processing*/
            break;
        }
    }
    return;
}

/******************************************************************************/
/*
 * Brief               action of effect E_FULL_COM
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_EFullComAction(uint8 netID)
{
    uint8 cnt;
    uint8 controllerID;
    CanSM_NetWorkRunTimeType* networkPtr = &CanSM_NetWorkRunTime[netID];
    ComM_ModeType ComMode;
/*do E_FULL_COM action*/
#if (STD_ON == CANSM_TX_OFFLINE_ACTIVE_SUPPORT)
    if ((boolean)TRUE == CanSM_EcuPassive)
    {
        for (cnt = 0u; cnt < CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber; cnt++)
        {
            controllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
            (void)CanIf_SetPduMode(controllerID, CANIF_TX_OFFLINE_ACTIVE);
        }
    }
    else
#endif /*STD_ON == CANSM_TX_OFFLINE_ACTIVE_SUPPORT*/
    {
        for (cnt = 0u; cnt < CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber; cnt++)
        {
            controllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
            (void)CanIf_SetPduMode(controllerID, CANIF_ONLINE);
        }
    }
    ComMode = COMM_FULL_COMMUNICATION;
    ComM_BusSM_ModeIndication(CANSM_NETWORK_HANDLE(netID), ComMode);
    (void)BswM_CanSM_CurrentState(CANSM_NETWORK_HANDLE(netID), CANSM_BSWM_FULL_COMMUNICATION);
    /*enter CANSM_BSM_S_FULLCOM,sub FULLCOM_S_BUS_OFF_CHECK state*/
    networkPtr->curBsmState = CANSM_BSM_S_FULLCOM;
    networkPtr->fullComState = FULLCOM_S_BUS_OFF_CHECK;
    if ((boolean)FALSE == CANSM_NETWORK_CONFIGURATION(netID).CanSMBorTxConfirmationPolling)
    {
        networkPtr->borTimeTxEnsuredTime = CANSM_NETWORK_BORTXENSUREDTIME(netID);
    }
    /*Com Mode change to COMM_FULL_COMMUNICATION*/
    networkPtr->curComMode = COMM_FULL_COMMUNICATION;
}

/******************************************************************************/
/*
 * Brief               action of effect E_FULL_TO_SILENT_COM
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_EFullToSilentComAction(uint8 netID)
{
    ComM_ModeType ComMode;
    uint8 cnt;
    uint8 controllerID;
    CanSM_NetWorkRunTimeType* networkPtr = &CanSM_NetWorkRunTime[netID];
    /*enter CANSM_BSM_S_SILENTCOM state*/
    networkPtr->curBsmState = CANSM_BSM_S_SILENTCOM;
    /*do the E_FULL_TO_SILENT_COM action*/
    (void)BswM_CanSM_CurrentState(CANSM_NETWORK_HANDLE(netID), CANSM_BSWM_SILENT_COMMUNICATION);
    for (cnt = 0u; cnt < CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber; cnt++)
    {
        controllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
        (void)CanIf_SetPduMode(controllerID, CANIF_TX_OFFLINE);
    }
    ComMode = COMM_SILENT_COMMUNICATION;
    ComM_BusSM_ModeIndication(CANSM_NETWORK_HANDLE(netID), ComMode);
    networkPtr->curComMode = COMM_SILENT_COMMUNICATION;
}

/******************************************************************************/
/*
 * Brief               action of effect E_PRE_NOCOM
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANSM_CODE) CanSM_EPreNoComAction(uint8 netID)
{
    CanSM_NetWorkRunTimeType* networkPtr = &CanSM_NetWorkRunTime[netID];
/*enter CANSM_BSM_S_PRE_NOCOM state*/
#if (STD_ON == CANSM_PNC_SUPPORT)
    if ((NULL_PTR != CANSM_NETWORK_CONFIGURATION(netID).TrcvRef)
        && ((boolean)TRUE == CANSM_NETWORK_CONFIGURATION(netID).TrcvRef->CanSMCanTrcvPnEnabled))
    {
        networkPtr->curBsmState = CANSM_BSM_DEINITPNSUPPORTED;
        networkPtr->deinitPnSupportedState = DEINITPN_S_PN_CLEAR_WUF;
    }
    else
#endif
    {
        networkPtr->curBsmState = CANSM_BSM_DEINITPNNOTSUPPORTED;
        networkPtr->deinitPnNotSupportedState = DEINITPNNOT_S_CC_STOPPED;
    }
    networkPtr->repeatCounter = 0u;
    /*do the E_PRE_NOCOM action*/
    (void)BswM_CanSM_CurrentState(CANSM_NETWORK_HANDLE(netID), CANSM_BSWM_NO_COMMUNICATION);
    networkPtr->curComMode = COMM_NO_COMMUNICATION;
}

/******************************************************************************/
/*
 * Brief               Switch the state of the controller
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different netID.
 * Param-Name[in]      netID, network Id
 *                     requestContorllerMode, requested controller state
 * Param-Name[out]     networkPtr,runtime network state pointer
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(Std_ReturnType, CANSM_CODE) CanSM_SetControllerModeRepeat(
    uint8 netID,
    CanSM_NetWorkRunTimeType* networkPtr,
    CanIf_ControllerModeType requestContorllerMode)
{
    uint8 cnt;
    uint8 controllerID;
    Std_ReturnType ContorllerRet = E_OK;
    switch (requestContorllerMode)
    {
    case CANIF_CS_STOPPED:
        networkPtr->canIfIndicated = T_CC_STOPED_INDICATED;
        break;
    case CANIF_CS_STARTED:
        networkPtr->canIfIndicated = T_CC_STARTED_INDICATED;
        break;
    case CANIF_CS_SLEEP:
        networkPtr->canIfIndicated = T_CC_SLEEP_INDICATED;
        break;
    default:
        /*This logic does not require any processing*/
        break;
    }
    if ((CANIF_CS_UNINIT != requestContorllerMode) && (0u == networkPtr->ModeRequestRepetitionTime)
        && (networkPtr->repeatCounter <= CanSM_ConfigPtr->CanSMModeRequestRepetitionMax))
    {
        for (cnt = 0u; cnt < CANSM_NETWORK_CONTROLLER(netID)->NetWorkRefControllerNumber; cnt++)
        {
            controllerID = CANSM_NETWORK_CONTROLLER(netID)->CanSMControllerId[cnt];
            if (requestContorllerMode != CanSM_ControllerMode[controllerID])
            {
                networkPtr->canIfIndicated = T_NO_INDICATED;
                Std_ReturnType ret = CanIf_SetControllerMode(controllerID, requestContorllerMode);
                if ((uint8)E_NOT_OK == ret)
                {
                    ContorllerRet = E_NOT_OK;
                    networkPtr->ModeRequestRepetitionTime = CANSM_MODEREQREPEAT_MAINFUNCTIONTIME;
                }
            }
        }
        networkPtr->repeatCounter++;
    }
    return ContorllerRet;
}

#define CANSM_STOP_SEC_CODE
#include "CanSM_MemMap.h"
