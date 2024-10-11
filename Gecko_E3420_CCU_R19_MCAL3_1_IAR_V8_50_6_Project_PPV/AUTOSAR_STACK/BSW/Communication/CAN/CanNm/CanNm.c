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
**  FILENAME    : CanNm.c                                                     **
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
 *  V1.0.0    20190926  darren.zhang   Initial version(ff version 1.16)
 *  V1.0.1    20200311  lili.wang
 *      1.EIRA and ERA buffer initialization modification in CanNm_Init
 *      (simplified initialization complexity)
 *      2.CanNm_GetLocalNodeIdentifier compile abstract problem problem modification
 *      3.Solve the problem of closing the communication first and then releasing the
 *      network, resulting in the inability to release the network for hibernation
 *  V1.0.2    20200518  lili.wang
 *      1.in CanNm_TimerManagement modify the logic of Rp or No state NmTimer timeout
 *      error report to DET
 *  V1.0.3    20200615  lili.wang
 *      1.Compile abstract update
 *      2.Tool generates configuration structure declaration modification
 *  V2.0.0    2020-07-29  lili.wang    R19_11 initial version.
 *  V2.0.1    2020-10-19  lili.wang    QAC check,code update
 *  V2.0.2    2020-11-30  lili.wang    1.PduInfoType MetaDataPtr set to NULL_PTR
 *                                     2.Cantata detection modification
 *  V2.0.3    2020-12-11  lili.wang    cantata check,code update
 *  V2.0.4    2021-03-10  lili.wang
 *      1.UnitTest bug update,cannm immediate transmit and Pnresetime bug update
 *      2.4.2.2&R19-11 define switch control modify
 *      3.CanNmUserDataEnabled and CanNmComUserDataSupport switch control modify
 *  V2.0.5    2021-04-23  lili.wang
 *      1.Modify compilation errors
 *  V2.0.6    2021-04-26  lili.wang
 *      1. Solve the problem that data cannot be transmitted when UdpNmMsgCycleOffset
 *      is 0 and the immediate transmission is disabled.
 *  V2.0.7    2021-06-2  lili.wang
 *      1. when UDPNM_IMMEDIATE_RESTART_ENABLED is STD_ON,UDPNM_IMMEDIATE_TRANSMIT_ENABLED
 *      STD_OFF,modify compilation error
 *  V2.0.8    2021-06-9  lili.wang
 *      1. delete in ready sleep state call CanNm_NetworkRequest() switch to Normal Operation
 *      State.
 *      2. delete in CanNm_EnableCommunication clear immedMsgTxCnt.
 *      3. modify UserDataTxPdu macro switch
 *  V2.0.9    2021-08-5  lili.wang
 *      1.CanNm_RxPnFilter compilation error modification.
 *  V2.0.10    2021-08-10  lili.wang
 *      1.Bug modification of Nm coordination function.
 *      2.In ready sleep state,switch to Normal operation state when network request.
 *  V2.0.11    2021-08-16  lili.wang
 *      1.The state switching after the network is released is an asynchronous
 *      operation, and it is should judged whether the network is released or in
 *      the repeat msg state at the position where the message is sent.
 *  V2.0.12    2022-04-24  darren.zhang
 *      1.Adjust the header file inclusion order
 *  V2.0.13    2022-05-05  darren.zhang
 *      1.resolve build warnings
 *      2.ImmediateTxConf logic modified
 *  V2.0.14    2022-05-17  darren.zhang
 *      1.allow PduR_CanNmTriggerTransmit return E_NOT_OK transmit nm pdu
 *  V2.0.15    2022-12-16  darren.zhang
 *      1. CanNm_RxIndication Increases DET check of the length of the received pdu
 *  V2.0.16    2023-02-10  darren.zhang
 *      1. Solve the occasional frame loss problem
 *  V2.0.17    2023-06-12  xiaojian.liang
 *      Fixed issue CPT-644 - CanNm_SetUserData null pointer exception
 *  V2.0.18   2023-06-30   darren.zhang
 *      modify network release handle
 */

/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:CanNm<br>
  RuleSorce:puhua-rule.rcf 2.3.1

    \li PRQA S 2877 MISRA Dir 4.1 .<br>
    Reason:The exception is that the number of loops is configurable.

    \li PRQA S 1531, 1532 MISRA Rule 8.7 .<br>
    Reason:The exception is global configuration data(1531) and API(1532).
 */
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
#define CANNM_C_AR_RELEASE_MAJOR_VERSION 4u
#define CANNM_C_AR_RELEASE_MINOR_VERSION 5u
#define CANNM_C_AR_RELEASE_PATCH_VERSION 0u
#define CANNM_C_SW_MAJOR_VERSION         2u
#define CANNM_C_SW_MINOR_VERSION         0u
#define CANNM_C_SW_PATCH_VERSION         18u
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm.h"
#include "CanNm_Internal.h"
#include "Nm_Cbk.h"
#include "Schm_CanNm.h"
#if (STD_ON == CANNM_COM_USERDATA_SUPPORT) || (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
#include "PduR_CanNm.h"
#endif /* (STD_ON == CANNM_COM_USERDATA_SUPPORT)||(STD_ON == CANNM_GLOBAL_PN_SUPPORT) */
#include "CanIf.h"
#include "CanSM_TxTimeoutException.h"
#include "BswM_Check_Action.h"

#if (STD_ON == CANNM_DEV_ERROR_DETECT)
#include "Det.h"
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */

/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
#if (CANNM_C_AR_RELEASE_MAJOR_VERSION != CANNM_H_AR_RELEASE_MAJOR_VERSION)
#error "CanNm.c : Mismatch in Specification Major Version"
#endif
#if (CANNM_C_AR_RELEASE_MINOR_VERSION != CANNM_H_AR_RELEASE_MINOR_VERSION)
#error "CanNm.c : Mismatch in Specification _MINOR Version"
#endif
#if (CANNM_C_AR_RELEASE_PATCH_VERSION != CANNM_H_AR_RELEASE_PATCH_VERSION)
#error "CanNm.c : Mismatch in Specification PATCH Version"
#endif

/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
#define CANNM_UNUSED(v) (void)(v)
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/

/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
#define CANNM_START_SEC_CODE
#include "CanNm_MemMap.h"

#if (STD_ON == CANNM_CAR_WAKEUP_RX_ENABLED)
static FUNC(void, CANNM_CODE) CanNm_RxCarWakeUpHadle(uint8 chIndex);
#endif /* STD_ON == CANNM_CAR_WAKEUP_RX_ENABLED */

static FUNC(boolean, CANNM_CODE) CanNm_FindChannelIndex(NetworkHandleType nmChannelHandle, uint8* chIndexPtr);

static FUNC(void, CANNM_CODE) CanNm_StateChange(uint8 chIndex, Nm_StateType nmNewState);

static FUNC(void, CANNM_CODE) CanNm_EntryRepeatMessageState(uint8 chIndex, boolean isNetWorkRequest);

#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
static FUNC(void, CANNM_CODE) CanNm_MsgcycleTimerManage(uint8 chIndex);
#endif /*STD_OFF == CANNM_PASSIVE_MODE_ENABLED*/

static FUNC(void, CANNM_CODE) CanNm_TimerManagement(uint8 chIndex);

#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
static FUNC(boolean, CANNM_CODE) CanNm_RxPnFilter(
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST) chCfgPtr,
    CanNm_InnerChannelType* chRTPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr);
#endif

#if (                                   \
    (STD_ON == CANNM_GLOBAL_PN_SUPPORT) \
    && ((STD_ON == CANNM_PN_ERA_CALC_ENABLED) || (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)))
static FUNC(void, CANNM_CODE) CanNm_RxPnEiraEraHandle(uint8 chIndex);
#endif /*((STD_ON == CANNM_GLOBAL_PN_SUPPORT)&&   \
         ((STD_ON == CANNM_PN_ERA_CALC_ENABLED)|| \
          (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)))*/

#if (STD_ON == CANNM_PN_ERA_CALC_ENABLED)
static FUNC(void, CANNM_CODE) CanNm_PnEraResetTimerHandle(uint8 chIndex);
#endif /*STD_ON == CANNM_PN_ERA_CALC_ENABLED*/

#if (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
static FUNC(void, CANNM_CODE) CanNm_PnEiraResetTimerHandle(void);
#endif /* (STD_ON == CANNM_PN_EIRA_CALC_ENABLED) */

#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
static FUNC(Std_ReturnType, CANNM_CODE) CanNm_SendNmPdu(uint8 chIndex, boolean addTransFlag);
#endif /*STD_OFF == CANNM_PASSIVE_MODE_ENABLED*/

#if ((STD_ON == CANNM_PN_EIRA_CALC_ENABLED) && (STD_ON == CANNM_COM_USERDATA_SUPPORT))
static FUNC(void, CANNM_CODE) CanNm_TxPnEiraHandle(P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA) txDta);
#endif

static FUNC(void, CANNM_CODE) CanNm_StateManagement(uint8 chIndex);

static FUNC(void, CANNM_CODE) CanNm_BusSleepStateHandle(uint8 chIndex);

static FUNC(void, CANNM_CODE) CanNm_PrepareBusSleepStateHandle(uint8 chIndex);

static FUNC(void, CANNM_CODE) CanNm_RepeatMessageStateHandle(uint8 chIndex);

static FUNC(void, CANNM_CODE) CanNm_NormalOperationStateHandle(uint8 chIndex);

static FUNC(void, CANNM_CODE) CanNm_ReadySleepStateHandle(uint8 chIndex);

static FUNC(void, CANNM_CODE) CanNm_RxDataMainHandle(uint8 chIndex);

static FUNC(void, CANNM_CODE) CanNm_SendMsgMainHandle(uint8 chIndex);

#if (STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT)
static FUNC(void, CANNM_CODE) CanNm_CoordReadyToSleepIndHandle(uint8 chIndex);
#endif /* STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT */

static FUNC(void, CANNM_CODE) CanNm_EnterPrepareBusSleepModeHandle(uint8 chIndex);

static FUNC(void, CANNM_CODE)
    CanNm_MemCpy(uint8* destPtr, P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA) srcPtr, uint16 len);
#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
static FUNC(void, CANNM_CODE) CanNm_InnerTxConfHandle(uint8 chIndex);
#endif /* (STD_OFF == CANNM_PASSIVE_MODE_ENABLED) */
#define CANNM_STOP_SEC_CODE
#include "CanNm_MemMap.h"
/******************************************************************************
**                      Private Variable Definitions                         **
******************************************************************************/
#define CANNM_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanNm_MemMap.h"
static VAR(CanNm_InitStatusType, CANNM_VAR_POWER_ON_INIT) CanNm_InitStatus = CANNM_UNINIT;
#define CANNM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanNm_MemMap.h"

#define CANNM_START_SEC_VAR_INIT_PTR
#include "CanNm_MemMap.h"
//static P2CONST(CanNm_ConfigType, AUTOMATIC, CANNM_APPL_CONST) CanNm_CfgPtr = NULL_PTR;
P2CONST(CanNm_ConfigType, AUTOMATIC, CANNM_APPL_CONST) CanNm_CfgPtr = NULL_PTR;
#define CANNM_STOP_SEC_VAR_INIT_PTR
#include "CanNm_MemMap.h"

#define CANNM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanNm_MemMap.h"
//static VAR(CanNm_InnerChannelType, CANNM_VAR) CanNm_ChRunTime[CANNM_NUMBER_OF_CHANNEL];

#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT) && (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
static VAR(CanNm_InnerGlobalType, CANNM_VAR) CanNm_InnerGlobal;
#endif /* (STD_ON == CANNM_GLOBAL_PN_SUPPORT) && (STD_ON == CANNM_PN_EIRA_CALC_ENABLED) */
#define CANNM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "CanNm_MemMap.h"
VAR(CanNm_InnerChannelType, CANNM_VAR) CanNm_ChRunTime[CANNM_NUMBER_OF_CHANNEL];


/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/

/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
#define CANNM_START_SEC_CODE
#include "CanNm_MemMap.h"

/******************************************************************************/
/*
 * Brief               Initialize the CanNm module.
 * ServiceId           0x00
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      CanNmConfigPtr, Pointer to a selected configuration
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, CANNM_CODE)
CanNm_Init(P2CONST(CanNm_ConfigType, AUTOMATIC, CANNM_APPL_CONST) CanNmConfigPtr) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 chIndex;
    uint8 loop;
    CanNm_InnerChannelType* chRTPtr;
#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
    CanNm_PnInfoType pnInfo;
#endif /* #if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)*/

    if (NULL_PTR == CanNmConfigPtr)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_INIT, CANNM_E_PARAM_POINTER);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */

        CanNm_InitStatus = CANNM_INIT_FAIL;
    }
    else
    {
        /* @req SWS_CanNm_00060 */
        CanNm_CfgPtr = CanNmConfigPtr;
#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
        pnInfo = CanNm_GetPnInfo();
#endif /* #if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)*/
        for (chIndex = 0u; chIndex < CANNM_NUMBER_OF_CHANNEL; chIndex++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            chRTPtr = &CanNm_GetChannelRTData(chIndex);

            /* @req SWS_CanNm_00141 */
            /* Set state to NM_STATE_BUS_SLEEP */
            chRTPtr->canNmState = NM_STATE_BUS_SLEEP;
            /* @req SWS_CanNm_00144 */
            /* Mode enter Bus_Sleep Mode */
            chRTPtr->cannmMode = NM_MODE_BUS_SLEEP;
            /* @req SWS_CanNm_00143 */
            /* Set network to released */
            chRTPtr->netRequestStatus = CANNM_NETWORK_RELEASED;
            chRTPtr->netRequestFlg = FALSE;

            /* Passive startup flag */
            chRTPtr->passiveStartUp = FALSE;

#if (STD_ON == CANNM_COM_CONTROL_ENABLED)
            /* @req SWS_CanNm_00169*/
            chRTPtr->canNmTxEnable = TRUE;
#endif /* STD_ON == CANNM_COM_CONTROL_ENABLED */

#if (STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT)
            chRTPtr->coordReadyToSleepInd = CANNM_CSR_IND_INIT;
#endif /* STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT */

#if (STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED)
            chRTPtr->remoteSleepInd = FALSE;
            chRTPtr->remoteTimer = 0x0u;
            chRTPtr->remoteTimerpassed = 0x0u;
#endif /* STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED */

#if (STD_ON == CANNM_IMMEDIATE_TRANSMIT_ENABLED)
            chRTPtr->immedMsgTxCnt = 0u;
#endif /* STD_ON == CANNM_IMMEDIATE_TRANSMIT_ENABLED */

            chRTPtr->stateTimer = 0x0u;
            chRTPtr->stateToutFlg = FALSE;
            /* @req SWS_CanNm_00206 */
            /* Reset nm-timeout timer */
            chRTPtr->nmTimeoutTimer = 0x0u;
            chRTPtr->nmToutFlg = FALSE;

#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
            /* @req SWS_CanNm_00061 */
            /* Stop the transmission nm pdu message cycle timer */
            chRTPtr->msgTxCylceTimer = 0u;
            chRTPtr->retrySendMsgFlag = FALSE;
            chRTPtr->msgTimeoutTimer = 0u;
            chRTPtr->msgToutFlg = FALSE;
            chRTPtr->sendNmMsgFlg = FALSE;
#endif /* STD_OFF == CANNM_PASSIVE_MODE_ENABLED */

            /* @req SWS_CanNm_00025 */
            /* Set each byte of user data to 0xff */
            for (loop = 0u; loop < CANNM_DEFAULT_PDU_LENGTH; loop++)
            {
                chRTPtr->txPduData[loop] = 0xffu;
            }

#if (STD_ON == CANNM_NODE_DETECTION_ENABLED)
            /* Set NodeId to config data */
            if (CANNM_PDU_OFF != CanNm_GetPduNidPosition(chIndex))
            {
                chRTPtr->txPduData[(uint8)CanNm_GetPduNidPosition(chIndex)] = CanNm_GetNodeId(chIndex);
            }
#endif /* #if (STD_ON == CANNM_NODE_DETECTION_ENABLED)*/

            /* Set CBV to config data */
            if (CANNM_PDU_OFF != CanNm_GetPduCbvPosition(chIndex))
            {
                chRTPtr->txPduData[(uint8)CanNm_GetPduCbvPosition(chIndex)] = 0x00;
            }

/* pn fill PNI bit */
#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
            /* @req SWS_CanNm_00413,@req SWS_CanNm_00414 */
            /* pnenable=true,shall set transmit PNI bit=1 */
            if ((boolean)TRUE == CanNm_CfgPtr->ChannelConfig[chIndex].PnEnabled)
            {
                uint8 pnIdx;

                for (pnIdx = 0; pnIdx < pnInfo.CanNmPnInfoLength; pnIdx++)
                {
                    /*
                     * Because transmit immediately,the first msg should not
                     * request the PNC,so the PN Info data cannot set to 0xff.
                     */
                    chRTPtr->txPduData[pnInfo.CanNmPnInfoOffset + pnIdx] = 0x0u;
                }

                CanNm_SetTxPduCbvBit(chIndex, CANNM_CBV_BIT_PNI_MASK);

                chRTPtr->pnRxIndFlg = FALSE;
                chRTPtr->pnFilterEnable = FALSE;
            }
#endif /* STD_ON == CANNM_GLOBAL_PN_SUPPORT */

#if (STD_ON == CANNM_PN_ERA_CALC_ENABLED)
            /* Clear pn ERA info buffer */
            for (loop = 0u; loop < pnInfo.CanNmPnInfoLength; loop++)
            {
                chRTPtr->pnInfoEra[loop] = 0x0u;
            }

            /* Clear pn ERA reset timer */
            for (loop = 0u; loop < CANNM_PN_NUM; loop++)
            {
                chRTPtr->pnEraResetTimer[loop] = 0x0u;
            }
#endif /* (STD_ON == CANNM_PN_ERA_CALC_ENABLED) */
        }

#if (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
        /* Clear pn EIRA info buffer */
        for (loop = 0u; loop < pnInfo.CanNmPnInfoLength; loop++)
        {
            CanNm_InnerGlobal.pnEiraInfo[loop] = 0x0u;
        }

        /* Clear pn EIRA reset timer */
        for (loop = 0u; loop < CANNM_PN_NUM; loop++)
        {
            CanNm_InnerGlobal.pnEiraResetTimer[loop] = 0x0u;
        }
#endif /* (STD_ON == CANNM_PN_EIRA_CALC_ENABLED) */

        CanNm_InitStatus = CANNM_INIT_SUCCESS;
    }
}

/******************************************************************************/
/*
 * Brief               De-initializes the CanNm module.
 * ServiceId           0x10
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, CANNM_CODE) CanNm_DeInit(void)
{
    uint8 chIndex;
    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_DEINIT, CANNM_E_UNINIT);
#endif
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_DEINIT, CANNM_E_INIT_FAILED);
#endif
    }
    else
    {
        boolean detNoErr = TRUE;
        CanNm_InnerChannelType* chRTPtr;
        for (chIndex = 0u; chIndex < CANNM_NUMBER_OF_CHANNEL; chIndex++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            chRTPtr = &CanNm_GetChannelRTData(chIndex);
            if (NM_STATE_BUS_SLEEP != chRTPtr->canNmState)
            {
                detNoErr = FALSE;
                break;
            }
        }
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        if ((boolean)FALSE == detNoErr)
        {
            CANNM_DET_REPORT(CANNM_SERVICE_ID_DEINIT, CANNM_E_NOT_IN_BUS_SLEEP);
        }
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
        if ((boolean)TRUE == detNoErr)
        {
            CanNm_InitStatus = CANNM_UNINIT;
        }
    }
}

/******************************************************************************/
/*
 * Brief               Passive startup of the AUTOSAR CAN NM.
 * ServiceId           0x01
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant (but not for the same NM-Channel)
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Passive startup of network management has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_PassiveStartUp(NetworkHandleType nmChannelHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 chIndex = 0xffu;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_PASSIVESTARUP, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_PASSIVESTARUP, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_PASSIVESTARUP, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);

        /* @req SWS_CanNm_00147
         * In network mode,shall not execute this service,
         * return E_NOT_OK.
         */
        if (NM_MODE_NETWORK != chRTPtr->cannmMode)
        {
            SchM_Enter_CanNm_Network(chIndex);
            chRTPtr->passiveStartUp = TRUE;
            SchM_Exit_CanNm_Network(chIndex);

            ret = E_OK;
        }
    }
    return ret;
}

/* @ SWS_CanNm_00257 */
/* optional avaliable */
#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
/******************************************************************************/
/*
 * Brief               Request the network, since ECU needs to communicate on
 *                     the bus.
 * ServiceId           0x02
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant (but not for the same NM-Channel)
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Requesting of network has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_NetworkRequest(NetworkHandleType nmChannelHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 chIndex = 0xffu;
    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_NETWORKREQUEST, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_NETWORKREQUEST, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_NETWORKREQUEST, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);

        SchM_Enter_CanNm_Network(chIndex);

        /* @req SWS_CanNm_00104 */
        /* Change network state to request */
        chRTPtr->netRequestStatus = CANNM_NETWORK_REQUESTED;
        chRTPtr->netRequestFlg = TRUE;
#if (STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT)
        chRTPtr->coordReadyToSleepInd = CANNM_CSR_IND_INIT;
#endif
        SchM_Exit_CanNm_Network(chIndex);

        ret = E_OK;
    }

    return ret;
}
#endif /* STD_OFF == CANNM_PASSIVE_MODE_ENABLED */

#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
/******************************************************************************/
/*
 * Brief               Release the network, since ECU doesn't have to communicate
 *                     on the bus.
 * ServiceId           0x03
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant (but not for the same NM-Channel)
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Releasing of network has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_NetworkRelease(NetworkHandleType nmChannelHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 chIndex = 0xffu;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_NETWORKRELEASE, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_NETWORKRELEASE, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_NETWORKRELEASE, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);

        SchM_Enter_CanNm_Network(chIndex);

        /* @req SWS_CanNm_00105 */
        /* Change network state to release */
        chRTPtr->netRequestStatus = CANNM_NETWORK_RELEASED;

        SchM_Exit_CanNm_Network(chIndex);
        ret = E_OK;
    }

    return ret;
}
#endif /* STD_OFF == CANNM_PASSIVE_MODE_ENABLED */

/* @SWS_CanNm_00262
optional avaliable */
#if (STD_ON == CANNM_COM_CONTROL_ENABLED)
/******************************************************************************/
/*
 * Brief               Disable the NM PDU transmission ability due to a ISO14229
 *                     Communication Control (28hex) service.
 * ServiceId           0x0c
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant (but not for the same NM-Channel)
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Disabling of NM PDU transmission ability has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_DisableCommunication(NetworkHandleType nmChannelHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret = E_NOT_OK;

/* @req SWS_CanNm_00307 */
/* In passive mode,the Service shall have no effect and return E_NOT_OK*/
#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
    uint8 chIndex = 0xffu;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_DISABLECOMMUNICATION, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_DISABLECOMMUNICATION, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_DISABLECOMMUNICATION, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);

        SchM_Enter_CanNm_Network(chIndex);

        if (NM_MODE_NETWORK == chRTPtr->cannmMode)
        {
            /* @req SWS_CanNm_00170 */
            /* Disable the NM PDU transmission ability */
            chRTPtr->canNmTxEnable = FALSE;

            /* @req SWS_CanNm_00173 */
            /*
             * Stop the CanNm Message Cycle Timer in order to stop the
             * transmission of Network Management PDUs.
             */
            chRTPtr->msgTxCylceTimer = 0u;

            /* @req SWS_CanNm_00174 */
            /* Transmit ability disable,shall stop nm timeout timer */
            chRTPtr->nmTimeoutTimer = 0u;

#if (STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED)
            /* @req SWS_CanNm_00175 */
            /*
             * When the NM PDU transmission ability is disabled,the
             * detection of Remote Sleep Indication Timer shall be
             * suspended.
             */
            chRTPtr->remoteTimerpassed = chRTPtr->remoteTimer;
            chRTPtr->remoteTimer = 0u;
#endif /* STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED */

            ret = E_OK;
        }
        else
        {
            /* @req SWS_CanNm_00172 */
            /* Current mode is not network mode,shall return E_NOT_OK */
        }

        SchM_Exit_CanNm_Network(chIndex);
    }
#endif /* STD_OFF == CANNM_PASSIVE_MODE_ENABLED */

    return ret;
}
#endif /* STD_OFF == CANNM_COM_CONTROL_ENABLED */

/* @SWS_CanNm_00264 */
#if (STD_ON == CANNM_COM_CONTROL_ENABLED)
/******************************************************************************/
/*
 * Brief               Enable the NM PDU transmission ability due to a ISO14229
 *                     Communication Control (28hex) service.
 * ServiceId           0x0d
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant (but not for the same NM-Channel)
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Enabling of NM PDU transmission ability has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_EnableCommunication(NetworkHandleType nmChannelHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret = E_NOT_OK;

/* @req SWS_CanNm_00306 */
/* In passive mode,the Service shall have no effect and return E_NOT_OK*/
#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
    uint8 chIndex = 0xffu;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_ENABLECOMMUNICATION, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_ENABLECOMMUNICATION, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_ENABLECOMMUNICATION, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
        chCfgPtr = &CanNm_GetChannelConfig(chIndex);
        CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);

        SchM_Enter_CanNm_Network(chIndex);
        if (((boolean)FALSE == chRTPtr->canNmTxEnable) && (NM_MODE_NETWORK == chRTPtr->cannmMode))
        {
            chRTPtr->canNmTxEnable = TRUE;
            /* @req SWS_CanNm_00178 */
            /* Start transmission of NM PDUs within the next NM
             * main function. */
            chRTPtr->msgTxCylceTimer = 1u;
            /* @req SWS_CanNm_00179 */
            /* Restart NM-Timeout Timer */
            chRTPtr->nmTimeoutTimer = chCfgPtr->TimeoutTime / CanNm_CfgPtr->MainFunctionPeriod;

/* @req SWS_CanNm_00180 */
/* Resumed remote sleep indication timer */
#if (STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED)
            chRTPtr->remoteTimer = chRTPtr->remoteTimerpassed;
            chRTPtr->remoteTimerpassed = 0u;
#endif /* STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED */
            ret = E_OK;
        }
        else
        {
            /* @req SWS_CanNm_00177 */
            /* Transmission ability is enable,return E_NOT_OK */
            /* @req SWS_CanNm_00305 */
            /* Current mode is not network mode,return E_NOT_OK */
        }
        SchM_Exit_CanNm_Network(chIndex);
    }
#endif /* STD_OFF == CANNM_PASSIVE_MODE_ENABLED */

    return ret;
}
#endif /* STD_ON == CANNM_COM_CONTROL_ENABLED */

/* @SWS_CanNm_00266
optional avaliable
@SWS_CanNm_00327
COM user data is not need this api */
#if (                                                                              \
    (STD_ON == CANNM_USER_DATA_ENABLED) && (STD_OFF == CANNM_PASSIVE_MODE_ENABLED) \
    && (STD_OFF == CANNM_COM_USERDATA_SUPPORT))
/******************************************************************************/
/*
 * Brief               Set user data for NM PDUs transmitted next on the bus.
 * ServiceId           0x04
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (but not for the same NM-Channel)
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 *                     nmUserDataPtr,Pointer where the user data for the next
 *                     transmitted NM PDU shall be copied from
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Setting of user data has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_SetUserData(NetworkHandleType nmChannelHandle, P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA) nmUserDataPtr)
{
    uint8 chIndex = 0xffu;
    Std_ReturnType ret = E_NOT_OK;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_SETUSERDATA, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_SETUSERDATA, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_SETUSERDATA, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (NULL_PTR == nmUserDataPtr)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_SETUSERDATA, CANNM_E_PARAM_POINTER);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
        chCfgPtr = &CanNm_GetChannelConfig(chIndex);
        /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
        P2VAR(CanNm_InnerChannelType, AUTOMATIC, CANNM_APPL_DATA)
        chRTPtr = &CanNm_GetChannelRTData(chIndex);
        /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

        /* @req SWS_CanNm_00159 */
        /* Set NM user data*/
        uint8 userDataLength = chCfgPtr->UserDataLength;
        uint8 userDataOffset = chCfgPtr->UserDataOffset;
        uint8* userDtaPtr = &chRTPtr->txPduData[userDataOffset];

        SchM_Enter_CanNm_Network(chIndex);
        CanNm_MemCpy(userDtaPtr, nmUserDataPtr, userDataLength);
        SchM_Exit_CanNm_Network(chIndex);

        ret = E_OK;
    }

    return ret;
}
#endif /*((STD_ON == CANNM_USER_DATA_ENABLED) &&    \
          (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)&& \
          (STD_OFF == CANNM_COM_USERDATA_SUPPORT))*/

/* @SWS_CanNm_00268
option avaliable*/
#if (STD_ON == CANNM_USER_DATA_ENABLED)
/******************************************************************************/
/*
 * Brief               Get user data out of the most recently received NM PDU.
 * ServiceId           0x05
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     nmUserDataPtr,Pointer where user data out of the most
 *                     recently received NM PDU shall be copied to
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Getting of user data has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_GetUserData(NetworkHandleType nmChannelHandle, uint8* nmUserDataPtr) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 chIndex = 0xffu;
    Std_ReturnType ret = E_NOT_OK;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETUSERDATA, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETUSERDATA, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETUSERDATA, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (NULL_PTR == nmUserDataPtr)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETUSERDATA, CANNM_E_PARAM_POINTER);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
        chCfgPtr = &CanNm_GetChannelConfig(chIndex);
        CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);

        /* @req SWS_CanNm_00160 */
        /* Provided most recently received NM PDU user data*/
        uint8 userDataLength = chCfgPtr->UserDataLength;
        uint8 userDataOffset = chCfgPtr->UserDataOffset;
        uint8* userDtaPtr = &chRTPtr->rxPduData[userDataOffset];

        SchM_Enter_CanNm_Network(chIndex);
        CanNm_MemCpy(nmUserDataPtr, userDtaPtr, userDataLength);
        SchM_Exit_CanNm_Network(chIndex);

        ret = E_OK;
    }

    return ret;
}
#endif /* STD_ON == CANNM_USER_DATA_ENABLED */

/* @SWS_CanNm_00330 */
#if ((TRUE == CANNM_COM_USERDATA_SUPPORT) || (TRUE == CANNM_GLOBAL_PN_SUPPORT))
/******************************************************************************/
/*
 * Brief               Requests transmission of a PDU.
 * ServiceId           0x49
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same
 *                     PduId.
 * Param-Name[in]      TxPduId, Identifier of the PDU to be transmitted
 * Param-Name[out]     PduInfoPtr, Length of and pointer to the PDU data and pointer
 *                     to MetaData.
 * Param-Name[in/out]  None
 * Return              E_OK: Transmit request has been accepted.
 *                     E_NOT_OK: Transmit request has not been accepted.
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_Transmit(PduIdType CanNmTxPduId, const PduInfoType* PduInfoPtr) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret = E_NOT_OK;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_TRANSMIT, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_TRANSMIT, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CanNmTxPduId >= CANNM_TX_PDU_NUMBER_MAX)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_TRANSMIT, CANNM_E_INVALID_PDUID);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_TRANSMIT, CANNM_E_PARAM_POINTER);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST) chCfgPtr;
        CanNm_InnerChannelType* chRTPtr = NULL_PTR;
        uint8 chIndex;

        for (chIndex = 0; chIndex < CANNM_NUMBER_OF_CHANNEL; chIndex++)
        {
            if (CanNmTxPduId == CanNm_GetChannelConfig(chIndex).TxPdu->TxConfirmationPduId)
            {
                chCfgPtr = &CanNm_GetChannelConfig(chIndex);
                chRTPtr = &CanNm_GetChannelRTData(chIndex);
                break;
            }
        }
        if (chRTPtr != NULL_PTR) /* && (chCfgPtr != NULL_PTR) */
        {
            /* @req SWS_CanNm_00464 */
            if (((NM_STATE_NORMAL_OPERATION == chRTPtr->canNmState) || (NM_STATE_REPEAT_MESSAGE == chRTPtr->canNmState))
                && (PduInfoPtr->SduLength >= chCfgPtr->UserDataLength))
            {
                /* Copy tx data to tx buffer */
                CanNm_MemCpy(
                    &chRTPtr->txPduData[chCfgPtr->UserDataOffset],
                    PduInfoPtr->SduDataPtr,
                    chCfgPtr->UserDataLength);

                /*
                 * Request an additional transmission of the NM PDU with the current
                 * user data.
                 */
                (void)CanNm_SendNmPdu(chIndex, TRUE);

                ret = E_OK;
            }
        }
    }

    return ret;
}
#endif /* (TRUE == CANNM_COM_USERDATA_SUPPORT)|| \
(TRUE == CANNM_GLOBAL_PN_SUPPORT) */

/* optional avaliable @SWS_CanNm_00270 */
#if (STD_ON == CANNM_NODE_ID_ENABLED)
/******************************************************************************/
/*
 * Brief               Get node identifier out of the most recently received NM
 *                     PDU.
 * ServiceId           0x06
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     nmNodeIdPtr,Pointer where node identifier out of the
 *                     most recently received NM PDU shall be copied to
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Getting of the node identifier out of the most
 *                     recently received NM PDU has failed or is not configured
 *                     for this network handle.
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_GetNodeIdentifier(NetworkHandleType nmChannelHandle, uint8* nmNodeIdPtr) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 chIndex = 0xffu;
    Std_ReturnType ret = E_NOT_OK;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETNODEIDENTIFIER, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETNODEIDENTIFIER, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETNODEIDENTIFIER, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (NULL_PTR == nmNodeIdPtr)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETNODEIDENTIFIER, CANNM_E_PARAM_POINTER);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
        chCfgPtr = &CanNm_GetChannelConfig(chIndex);
        CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);

        /* @req SWS_CanNm_00132 */
        if ((CANNM_PDU_OFF != chCfgPtr->PduNidPosition)
#if (STD_ON != CANNM_VER_4_2_2)
            && (TRUE == CanNm_GetNodeIdEnabled(chIndex))
#endif /* (STD_ON != CANNM_VER_4_2_2) */
        )
        {
            SchM_Enter_CanNm_Network(chIndex);
            *nmNodeIdPtr = chRTPtr->rxPduData[(uint8)chCfgPtr->PduNidPosition];
            SchM_Exit_CanNm_Network(chIndex);
            ret = E_OK;
        }
    }

    return ret;
}
#endif /* STD_ON == CANNM_NODE_ID_ENABLED */

/* optional avaliable @SWS_CanNm_00272 */
#if (STD_ON == CANNM_NODE_ID_ENABLED)
/******************************************************************************/
/*
 * Brief               Get node identifier configured for the local node.
 * ServiceId           0x07
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     nmNodeIdPtr,Pointer where node identifier of the local node
 *                     shall be copied to
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Getting of the node identifier of the local node
 *                     has failed or is not configured for this network handle.
 */
/******************************************************************************/
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_GetLocalNodeIdentifier(NetworkHandleType nmChannelHandle, uint8* nmNodeIdPtr)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    uint8 chIndex = 0xffu;
    Std_ReturnType ret = E_NOT_OK;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETLOCALNODEIDENTIFIER, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETLOCALNODEIDENTIFIER, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETLOCALNODEIDENTIFIER, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (NULL_PTR == nmNodeIdPtr)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETLOCALNODEIDENTIFIER, CANNM_E_PARAM_POINTER);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
        chCfgPtr = &CanNm_GetChannelConfig(chIndex);

#if (STD_ON != CANNM_VER_4_2_2)
        /* @req SWS_CanNm_00133 */
        if (TRUE == CanNm_GetNodeIdEnabled(chIndex))
#endif /* (STD_ON != CANNM_VER_4_2_2) */
        {
#if (STD_ON == CANNM_NODE_ID_ENABLED)
            *nmNodeIdPtr = chCfgPtr->NodeId;

            ret = E_OK;
#endif /* (STD_ON == CANNM_NODE_ID_ENABLED) */
        }
    }

    return ret;
}
#endif /* STD_ON == CANNM_NODE_ID_ENABLED */

/* optional avaliable @SWS_CanNm_00274 */
#if (STD_ON == CANNM_NODE_DETECTION_ENABLED)
/******************************************************************************/
/*
 * Brief               Set Repeat Message Request Bit for NM PDUs transmitted
 *                     next on the bus.
 * ServiceId           0x08
 * Sync/Async          Asynchronous
 * Reentrancy          Reentrant (but not for the same NM-Channel)
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Setting of Repeat Message Request Bit has failed
 *                     or is not configured for this network handle.
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_RepeatMessageRequest(NetworkHandleType nmChannelHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 chIndex = 0xffu;
    Std_ReturnType ret = E_NOT_OK;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_REPEATMESSAGEREQUEST, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_REPEATMESSAGEREQUEST, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_REPEATMESSAGEREQUEST, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);

        SchM_Enter_CanNm_Network(chIndex);
        if ((NM_STATE_NORMAL_OPERATION == chRTPtr->canNmState) || (NM_STATE_READY_SLEEP == chRTPtr->canNmState))
        {
            chRTPtr->repeatMessageRequest = TRUE;

            ret = E_OK;
        }
        else
        {
            /*@req SWS_CanNm_00137 */
            /*
             * If the service is called in Repeat Message State,
             * Prepare Bus-Sleep Mode or Bus-Sleep Mode,the CanNm module
             * shall not execute the service and return E_NOT_OK.
             */
        }
        SchM_Exit_CanNm_Network(chIndex);
    }

    return ret;
}
#endif /* STD_ON == CANNM_NODE_DETECTION_ENABLED */

/******************************************************************************/
/*
 * Brief               Get the whole PDU data out of the most recently received
 *                     NM message.
 * ServiceId           0x0a
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     nmPduDataPtr, Pointer where NM PDU shall be copied to
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Getting of NM PDU Data has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_GetPduData(NetworkHandleType nmChannelHandle, uint8* nmPduDataPtr) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 chIndex = 0xffu;
    Std_ReturnType ret = E_NOT_OK;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETPDUDATA, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETPDUDATA, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETPDUDATA, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (NULL_PTR == nmPduDataPtr)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETPDUDATA, CANNM_E_PARAM_POINTER);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        /* @req SWS_CanNm_00138 @req SWS_CanNm_00407 */
        /* Provide whole payload of the most recently received NM PDU */
#if (STD_ON == CANNM_USER_DATA_ENABLED) || (STD_ON == CANNM_NODE_DETECTION_ENABLED)
        CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
#if (STD_ON != CANNM_VER_4_2_2)
        if ((TRUE == CanNm_GetNodeIdEnabled(chIndex)) || (TRUE == CanNm_GetNodeDetectionEnabled(chIndex)))
#endif /* (STD_ON != CANNM_VER_4_2_2) */
        {
            SchM_Enter_CanNm_Network(chIndex);
            CanNm_MemCpy(nmPduDataPtr, chRTPtr->rxPduData, CANNM_DEFAULT_PDU_LENGTH);
            SchM_Exit_CanNm_Network(chIndex);

            ret = E_OK;
        }
#endif /* (STD_ON == CANNM_USER_DATA_ENABLED) || (STD_ON == CANNM_NODE_DETECTION_ENABLED) */
    }

    return ret;
}

/******************************************************************************/
/*
 * Brief               Returns the state and the mode of the network management.
 * ServiceId           0x0b
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     nmStatePtr, Pointer where state of the network
 *                                 management shall be copied to
 *                     nmModePtr, Pointer where the mode of the network
 *                                management shall be copied to
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Getting of NM state has failed
 */
/******************************************************************************/
/* PRQA S 1532 ++ */ /* MISRA Rule 8.7 */
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_GetState(NetworkHandleType nmChannelHandle, Nm_StateType* nmStatePtr, Nm_ModeType* nmModePtr)
/* PRQA S 1532 -- */ /* MISRA Rule 8.7 */
{
    Std_ReturnType ret = E_NOT_OK;
#if (STD_ON == CANNM_DEV_ERROR_DETECT)

    if ((NULL_PTR == nmStatePtr) || (NULL_PTR == nmModePtr))
    {
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETSTATE, CANNM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    {
        /* @SWS_CanNm_00277 */
        if (CANNM_UNINIT == CanNm_InitStatus)
        {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
            CANNM_DET_REPORT(CANNM_SERVICE_ID_GETSTATE, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
        }
        else if (CANNM_INIT_FAIL == CanNm_InitStatus)
        {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
            CANNM_DET_REPORT(CANNM_SERVICE_ID_GETSTATE, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
        }
        else
        {
            uint8 chIndex = 0xffu;

            if ((boolean)TRUE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
            {
                SchM_Enter_CanNm_Network(chIndex);
                *nmStatePtr = CanNm_ChRunTime[chIndex].canNmState;
                *nmModePtr = CanNm_ChRunTime[chIndex].cannmMode;
                SchM_Exit_CanNm_Network(chIndex);
                ret = E_OK;
            }

#if (STD_ON == CANNM_DEV_ERROR_DETECT)
            else
            {
                CANNM_DET_REPORT(CANNM_SERVICE_ID_GETSTATE, CANNM_E_INVALID_CHANNEL);
            }

#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
        }
    }

    return ret;
}

#if (STD_ON == CANNM_VERSION_INFO_API)
/******************************************************************************/
/*
 * Brief               This service returns the version information of this module.
 * ServiceId           0xf1
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     versioninfo, Pointer to where to store the version information
 *                     of this module
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, CANNM_CODE)
CanNm_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
#if (STD_ON == CANNM_DEV_ERROR_DETECT)

    if (NULL_PTR == versioninfo)
    {
        CANNM_DET_REPORT(CANNM_SERVICE_ID_GETVERSIONINFO, CANNM_E_PARAM_POINTER);
    }
    else
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    {
        (versioninfo)->vendorID = CANNM_VENDOR_ID;
        (versioninfo)->moduleID = CANNM_MODULE_ID;
        (versioninfo)->sw_major_version = CANNM_C_SW_MAJOR_VERSION;
        (versioninfo)->sw_minor_version = CANNM_C_SW_MINOR_VERSION;
        (versioninfo)->sw_patch_version = CANNM_C_SW_PATCH_VERSION;
    }
}
#endif /* STD_ON == CANNM_VERSION_INFO_API */

/* optional avaliable @SWS_CanNm_00280 */
#if ((STD_ON == CANNM_BUS_SYNCHRONIZATION_ENABLED) && (STD_OFF == CANNM_PASSIVE_MODE_ENABLED))
/******************************************************************************/
/*
 * Brief               Request bus synchronization.
 * ServiceId           0xc0
 * Sync/Async          Synchronous
 * Reentrancy          Non Reentrant
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Requesting of bus synchronization has failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_RequestBusSynchronization(NetworkHandleType nmChannelHandle)
{
    uint8 chIndex = 0xffu;
    Std_ReturnType ret = E_NOT_OK;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_REQUESTBUSSYNCHRONIZATION, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_REQUESTBUSSYNCHRONIZATION, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_REQUESTBUSSYNCHRONIZATION, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
        P2VAR(CanNm_InnerChannelType, AUTOMATIC, CANNM_APPL_DATA)
        chRTPtr = &CanNm_GetChannelRTData(chIndex);
        /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

        SchM_Enter_CanNm_Network(chIndex);
        if ((NM_MODE_NETWORK == chRTPtr->cannmMode)
#if (STD_ON == CANNM_COM_CONTROL_ENABLED)
            && ((boolean)TRUE == chRTPtr->canNmTxEnable)
#endif /* STD_ON == CANNM_COM_CONTROL_ENABLED */
        )
        {
            /* @req SWS_CanNm_00130 */
            /*
             * This service shall trigger transmission of a single
             * Network Management PDU
             */
            ret = CanNm_SendNmPdu(chIndex, FALSE);
        }
        else
        {
            /* @req SWS_CanNm_00187 */
            /*
             * If CanNm is in Bus-Sleep Mode and Prepare Bus-Sleep Mode
             * the Service shall not execute and Return E_NOT_OK.
             */

            /* @req SWS_CanNm_00181 */
            /*
             * If the NM PDU transmission ability is disabled,the service
             * shall return E_NOT_OK.
             */
        }
        SchM_Exit_CanNm_Network(chIndex);
    }

    return ret;
}
#endif /* (STD_ON == CANNM_BUS_SYNCHRONIZATION_ENABLED) && \
(STD_OFF == CANNM_PASSIVE_MODE_ENABLED) */

/* optional avaliable @SWS_CanNm_00282 */
#if (STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED)
/******************************************************************************/
/*
 * Brief               Check if remote sleep indication takes place or not.
 * ServiceId           0xd0
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     nmRemoteSleepIndPtr, Pointer where check result of remote
 *                     sleep indication shall be copied to
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Checking of remote sleep indication bits has
                       failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_CheckRemoteSleepIndication(
    NetworkHandleType nmChannelHandle,
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(boolean, AUTOMATIC, CANNM_APPL_DATA) nmRemoteSleepIndPtr
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
)
{
    uint8 chIndex = 0xffu;
    Std_ReturnType ret = E_NOT_OK;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_CHECKREMOTESLEEPINDICATION, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_CHECKREMOTESLEEPINDICATION, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_CHECKREMOTESLEEPINDICATION, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (NULL_PTR == nmRemoteSleepIndPtr)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_CHECKREMOTESLEEPINDICATION, CANNM_E_PARAM_POINTER);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
        P2VAR(CanNm_InnerChannelType, AUTOMATIC, CANNM_APPL_DATA)
        chRTPtr = &CanNm_GetChannelRTData(chIndex);
        /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */

        SchM_Enter_CanNm_Network(chIndex);
        if ((NM_STATE_NORMAL_OPERATION == chRTPtr->canNmState) || (NM_STATE_READY_SLEEP == chRTPtr->canNmState))
        {
            *nmRemoteSleepIndPtr = chRTPtr->remoteSleepInd;
            ret = E_OK;
        }
        else
        {
            /* @req SWS_CanNm_00154 */
            /*
             * If CanNm in Bus-Sleep Mode, Prepare Bus-Sleep Mode or
             * Repeat Message State,the service shall not be executed.
             * And E_NOT_OK shall be returned.
             */
        }
        SchM_Exit_CanNm_Network(chIndex);
    }

    return ret;
}
#endif /* STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED */

/* optional avaliable @SWS_CanNm_00340 */
#if (STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT)
/******************************************************************************/
/*
 * Brief               Set the NM Coordinator Sleep Ready bit in the Control Bit
 *                     Vector.
 * ServiceId           0x17
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (but not for the same NM-channel)
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 *                     nmSleepReadyBit, Value written to ReadySleep Bit in CBV
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: No error
 *                     E_NOT_OK: Writing of remote sleep indication bit has
                       failed
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_SetSleepReadyBit(NetworkHandleType nmChannelHandle, boolean nmSleepReadyBit)
{
    uint8 chIndex = 0xffu;
    Std_ReturnType ret = E_NOT_OK;
    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_SETSLEEPREADYBIT, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_SETSLEEPREADYBIT, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_SETSLEEPREADYBIT, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        SchM_Enter_CanNm_Network(chIndex);

        /* @req SWS_CanNm_00321 */
        /*
         * CanNm shall set the "NM Coordinator Sleep Ready Bit" bit to
         * passed value and trigger a single Network Management PDU.
         */
        if ((boolean)TRUE == nmSleepReadyBit)
        {
            CanNm_SetTxPduCbvBit(chIndex, CANNM_CBV_BIT_CSR_MASK);
        }
        else
        {
            CanNm_ClrTxPduCbvBit(chIndex, CANNM_CBV_BIT_CSR_MASK);
        }
        (void)CanNm_SendNmPdu(chIndex, FALSE);

        SchM_Exit_CanNm_Network(chIndex);
        ret = E_OK;
    }

    return ret;
}
#endif /* STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT */
#define CANNM_STOP_SEC_CODE
#include "CanNm_MemMap.h"

#if ((STD_OFF == CANNM_IMMEDIATE_TXCONF_ENABLED) && (STD_OFF == CANNM_PASSIVE_MODE_ENABLED))
#define CANNM_START_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE
#include "CanNm_MemMap.h"
/******************************************************************************/
/*
 * Brief               The lower layer communication interface module confirms
 *                     the transmission of a PDU, or the failure to transmit a PDU.
 * ServiceId           0x40
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same
 *                     PduId.
 * Param-Name[in]      TxPduId, ID of the PDU that has been transmitted.
 *                     result, E_OK: The PDU was transmitted. E_NOT_OK: Transmission
 *                     of the PDU failed.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, CANNM_CODE)
CanNm_TxConfirmation(PduIdType TxPduID) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_TXCONFIRMATION, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_TXCONFIRMATION, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (TxPduID >= CANNM_TX_PDU_NUMBER_MAX)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_TXCONFIRMATION, CANNM_E_INVALID_PDUID);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {

        uint8 chIndex;

        for (chIndex = 0; chIndex < CANNM_NUMBER_OF_CHANNEL; chIndex++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            if (TxPduID == CanNm_GetChannelConfig(chIndex).TxPdu->TxConfirmationPduId)
            {
                break;
            }
        }
        CanNm_InnerTxConfHandle(chIndex);
    }
}
#define CANNM_STOP_SEC_CANNM_TXCONFIRMATION_CALLBACK_CODE
#include "CanNm_MemMap.h"
#endif /* #if((STD_OFF == CANNM_IMMEDIATE_TXCONF_ENABLED) && \
         (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)) */

#define CANNM_START_SEC_CANNM_RXINDICATION_CALLBACK_CODE
#include "CanNm_MemMap.h"
/******************************************************************************/
/*
 * Brief               Indication of a received PDU from a lower layer communication
 *                     interface module.
 * ServiceId           0x42
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same
 *                     PduId.
 * Param-Name[in]      RxPduId, ID of the received PDU.
 *                     PduInfoPtr, Contains the length (SduLength) of the received
 *                     PDU, a pointer to a buffer (SduDataPtr) containing the PDU,
 *                     and the MetaData related to this PDU.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, CANNM_CODE)
CanNm_RxIndication(PduIdType RxPduId, const PduInfoType* PduInfoPtr) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_RXINDICATION, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_RXINDICATION, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_RX_PDU_NUMBER_MAX <= RxPduId)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_RXINDICATION, CANNM_E_INVALID_PDUID);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (
        (NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr)
        /*|| (PduInfoPtr->SduLength != CANNM_DEFAULT_PDU_LENGTH)*/)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_RXINDICATION, CANNM_E_PARAM_POINTER);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST) chCfgPtr;
        CanNm_InnerChannelType* chRTPtr;
        uint8 chIndex;
        PduIdType pduIdx;

        for (chIndex = 0; chIndex < CANNM_NUMBER_OF_CHANNEL; chIndex++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            chCfgPtr = &CanNm_GetChannelConfig(chIndex);
            for (pduIdx = 0; pduIdx < chCfgPtr->RxPduNum; pduIdx++)
            {
                if (RxPduId == chCfgPtr->RxPdu[pduIdx].RxPduId)
                {
                    break;
                }
            }

            if (chCfgPtr->RxPduNum != pduIdx)
            {
                break;
            }
        }

        chRTPtr = &CanNm_GetChannelRTData(chIndex);

/* @req SWS_CanNm_00337, @req SWS_CanNm_00339*/
#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
        if ((boolean)TRUE == CanNm_RxPnFilter(chCfgPtr, chRTPtr, PduInfoPtr))
#endif
        {
            if(PduInfoPtr->SduLength == CANNM_DEFAULT_PDU_LENGTH)
            {
            /* @req SWS_CanNm_00035 */
                CanNm_MemCpy(chRTPtr->rxPduData, PduInfoPtr->SduDataPtr, (uint16)PduInfoPtr->SduLength);
            }
            else
            {
                const uint8 TempSource[8]={0};
                CanNm_MemCpy(chRTPtr->rxPduData, &TempSource[0], 8);
            }
            chRTPtr->rxPduFlg = TRUE;

/* @req SWS_CanNm_00037 */
/* Notify nm layer,if rx pdu */
#if (STD_ON == CANNM_PDU_RX_INDICATION_ENABLED)
            SuspendAllInterrupts();
            Nm_PduRxIndication(CanNm_GetComMNetworkHandle(chIndex));
            ResumeAllInterrupts();
#endif /* STD_ON == CANNM_PDU_RX_INDICATION_ENABLED */

            /* @req SWS_CanNm_00127 */
            if (NM_MODE_BUS_SLEEP == chRTPtr->cannmMode)
            {
                Nm_NetworkStartIndication(CanNm_GetComMNetworkHandle(chIndex));
#if ((STD_ON == CANNM_DEV_ERROR_DETECT) && (STD_ON == CANNM_VER_R19_11))
                CANNM_DET_REPORTRUNTIMEERROR(CANNM_SERVICE_ID_RXINDICATION, CANNM_E_NET_START_IND);
#endif /*#if ((STD_ON == CANNM_DEV_ERROR_DETECT) && \
         (STD_ON == CANNM_VER_R19_11))*/
            }
        }
    }
}
#define CANNM_STOP_SEC_CANNM_RXINDICATION_CALLBACK_CODE
#include "CanNm_MemMap.h"

#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
#define CANNM_START_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
#include "CanNm_MemMap.h"
/******************************************************************************/
/*
 * Brief               Enables the PN filter functionality on the indicated NM
 *                     channel.
 * ServiceId           0x16
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant (but not for the same NM-channel)
 * Param-Name[in]      nmChannelHandle, Identification of the NM-channel
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, CANNM_CODE)
CanNm_ConfirmPnAvailability(NetworkHandleType nmChannelHandle) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    uint8 chIndex = 0xffu;
    if (CANNM_UNINIT == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_CONFIRMPNAVAILABILITY, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_CONFIRMPNAVAILABILITY, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else if ((boolean)FALSE == CanNm_FindChannelIndex(nmChannelHandle, &chIndex))
    {
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_CONFIRMPNAVAILABILITY, CANNM_E_INVALID_CHANNEL);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    else
    {
        P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
        chCfgPtr = &CanNm_GetChannelConfig(chIndex);
        CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
        if ((boolean)TRUE == chCfgPtr->PnEnabled)
        {
            /* @SWS_CanNm_00404
            enbale pdu filter ability */
            chRTPtr->pnFilterEnable = TRUE;
        }
    }
}
#define CANNM_STOP_SEC_CANNM_CONFIRMPNAVAILABILITY_CALLBACK_CODE
#include "CanNm_MemMap.h"
#endif /* STD_ON == CANNM_GLOBAL_PN_SUPPORT */

#define CANNM_START_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE
#include "CanNm_MemMap.h"
/******************************************************************************/
/*
 * Brief               Within this API,the upper layer module (called module) shall
 *                     check whether the available data fits into the buffer size
 *                     reported by PduInfoPtr->SduLength. If it fits, it shall copy
 *                     its data into the buffer provided by PduInfoPtr->SduDataPtr
 *                     and update the length of the actual copied data in
 *                     PduInfoPtr->SduLength.
 * ServiceId           0x41
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different PduIds. Non reentrant for the same
 *                     PduId.
 * Param-Name[in]      TxPduId, ID of the SDU that is requested to be transmitted.
 * Param-Name[out]     None
 * Param-Name[in/out]  PduInfoPtr, Contains a pointer to a buffer (SduDataPtr) to
 *                     where the SDU data shall be copied, and the available buffer
 *                     size in SduLengh.
 * Return              E_OK: SDU has been copied and SduLength indicates the number
 *                     of copied bytes.
 *                     E_NOT_OK: No SDU data has been copied. PduInfoPtr must not be
                       used since it may contain a NULL pointer or point to invalid
                       data.
 */
/******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE)
CanNm_TriggerTransmit(PduIdType TxPduId, PduInfoType* PduInfoPtr)
{
    boolean detNoErr = TRUE;
    Std_ReturnType ret = E_NOT_OK;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
        detNoErr = FALSE;
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_TRIGGERTRANSMIT, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
        detNoErr = FALSE;
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_TRIGGERTRANSMIT, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    if (CANNM_TX_PDU_NUMBER_MAX <= TxPduId)
    {
        detNoErr = FALSE;
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_TRIGGERTRANSMIT, CANNM_E_INVALID_PDUID);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
    {
        detNoErr = FALSE;
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_TRIGGERTRANSMIT, CANNM_E_PARAM_POINTER);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }

    if ((boolean)TRUE == detNoErr)
    {
        CanNm_InnerChannelType* chRTPtr = NULL_PTR;
        uint8 chIndex;
#if (STD_ON == CANNM_COM_USERDATA_SUPPORT)
        PduInfoType pduInfo;
        P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST) chCfgPtr;
#endif

        if (PduInfoPtr->SduLength >= CANNM_DEFAULT_PDU_LENGTH)
        {
            for (chIndex = 0; chIndex < CANNM_NUMBER_OF_CHANNEL; chIndex++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
            {
                if (TxPduId == CanNm_GetChannelConfig(chIndex).TxPdu->TxConfirmationPduId)
                {
#if (STD_ON == CANNM_COM_USERDATA_SUPPORT)
                    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
#endif
                    chRTPtr = &CanNm_GetChannelRTData(chIndex);
                    break;
                }
            }
            if (chRTPtr != NULL_PTR) /* && (chCfgPtr != NULL_PTR) */
            {
#if (STD_ON == CANNM_COM_USERDATA_SUPPORT)
                /* @req SWS_CanNm_00350 */
                pduInfo.SduLength = chCfgPtr->UserDataLength;
                pduInfo.SduDataPtr = &chRTPtr->txPduData[chCfgPtr->UserDataOffset];
                pduInfo.MetaDataPtr = NULL_PTR;
                ret = PduR_CanNmTriggerTransmit(chCfgPtr->UserDataTxPdu->UpperLayerPduId, &pduInfo);
                if ((uint8)E_OK == ret)
#else
                ret = E_OK;
#endif
                {
                    /* @req SWS_CanNm_00351 */
                    CanNm_MemCpy(PduInfoPtr->SduDataPtr, chRTPtr->txPduData, CANNM_DEFAULT_PDU_LENGTH);
                }
            }
        }
    }

    return ret;
}
#define CANNM_STOP_SEC_CANNM_TRIGGERTRANSMIT_CALLBACK_CODE
#include "CanNm_MemMap.h"

#define CANNM_START_SEC_CODE
#include "CanNm_MemMap.h"
/******************************************************************************/
/*
 * Brief               Main function of the CanNm which processes the algorithm
 *                     describes in that document.
 * ServiceId           0x13
 * Sync/Async          None
 * Reentrancy          None
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
FUNC(void, CANNM_CODE) CanNm_MainFunction(void) /* PRQA S 1532 */ /* MISRA Rule 8.7 */
{
    boolean detNoErr = TRUE;

    if (CANNM_UNINIT == CanNm_InitStatus)
    {
        detNoErr = FALSE;
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_MAINFUNCTION, CANNM_E_UNINIT);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }
    if (CANNM_INIT_FAIL == CanNm_InitStatus)
    {
        detNoErr = FALSE;
#if (STD_ON == CANNM_DEV_ERROR_DETECT)
        CANNM_DET_REPORT(CANNM_SERVICE_ID_MAINFUNCTION, CANNM_E_INIT_FAILED);
#endif /* STD_ON == CANNM_DEV_ERROR_DETECT */
    }

    if ((boolean)TRUE == detNoErr)
    {
        uint8 chIndex;
        for (chIndex = 0u; chIndex < CANNM_NUMBER_OF_CHANNEL; chIndex++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
            if ((boolean)TRUE == chRTPtr->rxPduFlg)
            {
                chRTPtr->rxPduExtFlg = (boolean)TRUE;
                chRTPtr->rxPduFlg = (boolean)FALSE;
                CanNm_RxDataMainHandle(chIndex);
            }

            CanNm_TimerManagement(chIndex);
            CanNm_StateManagement(chIndex);
            CanNm_SendMsgMainHandle(chIndex);

            /* Clear Flags */
            chRTPtr->rxPduExtFlg = FALSE;
            chRTPtr->netRequestFlg = FALSE;
            chRTPtr->passiveStartUp = FALSE;
#if (STD_ON == CANNM_NODE_DETECTION_ENABLED)
            chRTPtr->repeatMessageRequest = FALSE;
#endif
            chRTPtr->nmToutFlg = FALSE;
            chRTPtr->stateToutFlg = FALSE;
        }
    }
}

/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
/******************************************************************************/
/*
 * Brief               Handle of Car Wakeup function
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_ON == CANNM_CAR_WAKEUP_RX_ENABLED)
static FUNC(void, CANNM_CODE) CanNm_RxCarWakeUpHadle(uint8 chIndex)
{
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(CanNm_InnerChannelType, AUTOMATIC, CANNM_APPL_DATA)
    chRTPtr = &CanNm_GetChannelRTData(chIndex);
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
    uint8 carWakeupMask = (1u << (chCfgPtr->CarWakeUpBitPosition));
    SchM_Enter_CanNm_Network(chIndex);
    uint8 carWakeupByte = chRTPtr->rxPduData[chCfgPtr->CarWakeUpBytePosition];
    SchM_Exit_CanNm_Network(chIndex);

#if (STD_ON == CANNM_CAR_WAKEUP_RX_ENABLED)
    if (((boolean)TRUE == CanNm_GetCarWakeUpRxEnabled(chIndex)) && ((carWakeupByte & carWakeupMask) > 0u))
    {
#if (STD_ON == CANNM_CAR_WAKEUP_FILTER_ENABLED)
        if ((boolean)TRUE == CanNm_GetCarWakeUpFilterEnabled(chIndex))
        {
            /* @req SWS_CanNm_00408 */
            if (CANNM_PDU_OFF != chCfgPtr->PduNidPosition)
            {
                SchM_Enter_CanNm_Network(chIndex);
                uint8 rxNodeId = chRTPtr->rxPduData[(uint8)chCfgPtr->PduNidPosition];
                SchM_Exit_CanNm_Network(chIndex);

                if (CanNm_GetCarWakeUpFilterNodeId(chIndex) == rxNodeId)
                {
                    Nm_CarWakeUpIndication(CanNm_GetComMNetworkHandle(chIndex));
                }
            }
        }
        else
#endif /* STD_ON == CANNM_CAR_WAKEUP_FILTER_ENABLED */
        {
            /* @req SWS_CanNm_00406 */
            /*Nm_CarWakeUpIndication(CanNm_GetComMNetworkHandle(chIndex));*/
        }
    }
#endif /* STD_ON == CANNM_CAR_WAKEUP_RX_ENABLED */
}
#endif /* STD_ON == CANNM_CAR_WAKEUP_RX_ENABLED */

/******************************************************************************/
/*
 * Brief               Return channel index in CanNm corresponding to
 *                     nmChanelHandle from ComM
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      nmChannelHandle, Channel index in ComM
 * Param-Name[out]     chIndexPtr, Pointer where the channel index in CanNm
 *                                 shall be copied to
 * Param-Name[in/out]  None
 * Return              TRUE: ComM channel configed in CanNm
                       FALSE: ComM channel not configed in CanNm
 */
/******************************************************************************/
static FUNC(boolean, CANNM_CODE) CanNm_FindChannelIndex(NetworkHandleType nmChannelHandle, uint8* chIndexPtr)
{
    uint8 chIndex;
    boolean findChannelFlg = FALSE;

    if (CANNM_INIT_SUCCESS == CanNm_InitStatus)
    {
        for (chIndex = 0u; chIndex < CANNM_NUMBER_OF_CHANNEL; chIndex++) /* PRQA S 2877 */ /* MISRA Dir 4.1 */
        {
            if (nmChannelHandle == CanNm_GetComMNetworkHandle(chIndex))
            {
                findChannelFlg = TRUE;
                *chIndexPtr = chIndex;
                break;
            }
        }
    }
    return findChannelFlg;
}

/******************************************************************************/
/*
 * Brief               Store new state and notify new state to NM module
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 *                     nmNewState, new state of CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_StateChange(uint8 chIndex, Nm_StateType nmNewState)
{
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
#if (STD_ON == CANNM_STATE_CHANGE_IND_ENABLED)
    /* @req SWS_CanNm_00166 */
    /* CanNm states shall be notified to the upper layer.*/
    Nm_StateChangeNotification(CanNm_GetComMNetworkHandle(chIndex), chRTPtr->canNmState, nmNewState);
#endif /* STD_ON == CANNM_STATE_CHANGE_IND_ENABLED */ 
    SchM_Enter_CanNm_Network(chIndex);
    chRTPtr->canNmState = nmNewState;
    SchM_Exit_CanNm_Network(chIndex);
    if((NM_STATE_PREPARE_BUS_SLEEP == CanNm_ChRunTime[0].canNmState)&&(NM_STATE_PREPARE_BUS_SLEEP == CanNm_ChRunTime[1].canNmState)
    &&(NM_STATE_PREPARE_BUS_SLEEP == CanNm_ChRunTime[2].canNmState)&&(NM_STATE_PREPARE_BUS_SLEEP == CanNm_ChRunTime[3].canNmState)) 
    {
            BswM_RequestMode(30,2); /*Disable all the Routing excepet the NM*/
            FirstNMFlag = 0;
    }
    else if((NM_STATE_READY_SLEEP <= CanNm_ChRunTime[0].canNmState)&&(NM_STATE_READY_SLEEP <=  CanNm_ChRunTime[1].canNmState)
    &&(NM_STATE_READY_SLEEP <=  CanNm_ChRunTime[2].canNmState)&&(NM_STATE_READY_SLEEP <=  CanNm_ChRunTime[3].canNmState))
    {
            BswM_RequestMode(30,3); /*Enable all Routing*/
    }
}

/******************************************************************************/
/*
 * Brief               Process when enter from other state to repeat msg state
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 *                     isNetWorkRequest, Indicate whether enter repeate message
 *                                       state triggered by NetworkRequest
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_EntryRepeatMessageState(uint8 chIndex, boolean isNetWorkRequest)
{
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
    /* Load CanNmRepeatMessageTime to stateTimer */
    /* @req SWS_CanNm_00102 */
    chRTPtr->stateTimer = chCfgPtr->RepeatMessageTime / CanNm_CfgPtr->MainFunctionPeriod;

#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
    /* @req SWS_CanNm_00100 */
    /* Enter Repeat Message State,transmission shall start*/
    if (((boolean)TRUE != isNetWorkRequest) || (0u == chCfgPtr->ImmediateNmTransmissions))
    {
        /* @req SWS_CanNm_00005 */
        /*
         * If the Repeat Message State is not entered via CanNm_NetworkRequest
         * OR CanNmImmediateNmTransmissions is zero the transmission of NM PDU
         * shall be delayed by CANNM_MSG_CYCLE_OFFSET after entering the
         * repeat message state.
         */
        // chRTPtr->msgTxCylceTimer = chCfgPtr->MsgCycleOffset / CanNm_CfgPtr->MainFunctionPeriod;

        // if (0u == chRTPtr->msgTxCylceTimer)
        // {
        //     chRTPtr->msgTxCylceTimer = 1;
        // }

        chRTPtr->sendNmMsgFlg = TRUE;


        chRTPtr->msgTxCylceTimer = chCfgPtr->MsgCycleTime / CanNm_CfgPtr->MainFunctionPeriod;

#if (STD_ON == CANNM_VER_4_2_2)
        /* @req SWS_CanNm_00007 */
        if ((NM_MODE_BUS_SLEEP == chRTPtr->cannmMode) && ((boolean)TRUE == chCfgPtr->RetryFirstMessageRequest))
        {
            chRTPtr->retrySendMsgFlag = TRUE;
        }
#endif /* #if (STD_ON == CANNM_VER_4_2_2)*/

#if (STD_ON == CANNM_IMMEDIATE_RESTART_ENABLED)
        if ((TRUE == isNetWorkRequest) && (NM_MODE_PREPARE_BUS_SLEEP == chRTPtr->cannmMode))
        {
            /* @req SWS_CanNm_00122 */
            /* Set send NM message flag */
            chRTPtr->sendNmMsgFlg = TRUE;
        }
#endif /*(STD_ON == CANNM_IMMEDIATE_RESTART_ENABLED)*/
    }
#if (STD_ON == CANNM_IMMEDIATE_TRANSMIT_ENABLED)
    else
    {
        /* @req SWS_CanNm_00334 @req SWS_CanNm_00454 @req SWS_CanNm_00122 */
        /*
         * The NM PDUs shall be transmitted using CanNmImmediateNmCycleTime
         * as cycle time.
         * The first NM PDU shall be triggered as soon as possible.
         */
        if ((NM_MODE_BUS_SLEEP == chRTPtr->cannmMode) || (NM_MODE_PREPARE_BUS_SLEEP == chRTPtr->cannmMode)
#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
            || ((NM_MODE_NETWORK == chRTPtr->cannmMode) && ((boolean)TRUE == chCfgPtr->PnHandleMultipleNetworkRequests))
#endif /* STD_ON == CANNM_GLOBAL_PN_SUPPORT */
        )
        {
            /* Set send NM message flag */
            chRTPtr->sendNmMsgFlg = TRUE;


            chRTPtr->msgTxCylceTimer = chCfgPtr->ImmediateNmCycleTime / CanNm_CfgPtr->MainFunctionPeriod;
            chRTPtr->immedMsgTxCnt = chCfgPtr->ImmediateNmTransmissions;

            /* @req SWS_CanNm_00335 */
            /*
             * If immediate transmit Nm Pdu failed, retry in next
             * MainFunction.
             */
            chRTPtr->retrySendMsgFlag = TRUE;
        }
    }
#endif /* (STD_ON == CANNM_IMMEDIATE_TRANSMIT_ENABLED) */
#endif /* STD_OFF == CANNM_PASSIVE_MODE_ENABLED*/

#if (STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED)
    /* @req SWS_CanNm_00152 */
    /*
     * Entry Repeat Message state from Normal Operation State or Ready
     * Sleep State,shall cancel remote notify.
     */
    if (((boolean)TRUE == chRTPtr->remoteSleepInd)
        && ((NM_STATE_NORMAL_OPERATION == chRTPtr->canNmState) || (NM_STATE_READY_SLEEP == chRTPtr->canNmState)))
    {
        chRTPtr->remoteSleepInd = FALSE;
        Nm_RemoteSleepCancellation(CanNm_GetComMNetworkHandle(chIndex));
    }
#endif /*STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED */

    CanNm_StateChange(chIndex, NM_STATE_REPEAT_MESSAGE);

    if (NM_MODE_NETWORK != chRTPtr->cannmMode)
    {

#if (STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT)
        CanNm_ChRunTime[chIndex].coordReadyToSleepInd = CANNM_CSR_IND_INIT;
        CanNm_ClrTxPduCbvBit(chIndex, CANNM_CBV_BIT_CSR_MASK);
#endif /* STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT */

        /* @req SWS_CanNm_00096 */
        /* Network Mode is entered,NM-Timeout Timer started.*/
        chRTPtr->nmTimeoutTimer = chCfgPtr->TimeoutTime / CanNm_CfgPtr->MainFunctionPeriod;

        /* @req SWS_CanNm_00097 @req SWS_CanNm_00093 */
        /* Network Mode is entered, notify the upper layer by Nm_NetworkMode.*/
        chRTPtr->cannmMode = NM_MODE_NETWORK;
        Nm_NetworkMode(CanNm_GetComMNetworkHandle(chIndex));
    }
}

/******************************************************************************/
/*
 * Brief               Process used timers
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
static FUNC(void, CANNM_CODE) CanNm_MsgcycleTimerManage(uint8 chIndex)
{
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
    if ((chRTPtr->msgTxCylceTimer > 0u)
#if (STD_ON == CANNM_COM_CONTROL_ENABLED)
        /* @req SWS_CanNm_00173 */
        && ((boolean)TRUE == chRTPtr->canNmTxEnable)
#endif /* STD_ON == CANNM_COM_CONTROL_ENABLED */
    )
    {
        chRTPtr->msgTxCylceTimer--;
        if ((0u == chRTPtr->msgTxCylceTimer)
            && (((CANNM_NETWORK_REQUESTED == chRTPtr->netRequestStatus))
                || (NM_STATE_REPEAT_MESSAGE == chRTPtr->canNmState)))
        {
            /* @req SWS_CanNm_00032 */
            /* Set send NM message flag */
            chRTPtr->sendNmMsgFlg = TRUE;


#if (STD_ON == CANNM_IMMEDIATE_TRANSMIT_ENABLED)
            if (chRTPtr->immedMsgTxCnt > 0u)
            {
                chRTPtr->msgTxCylceTimer = chCfgPtr->ImmediateNmCycleTime / CanNm_CfgPtr->MainFunctionPeriod;
            }
            else
#endif
            {
                /* @req SWS_CanNm_00040 */
                chRTPtr->msgTxCylceTimer = chCfgPtr->MsgCycleTime / CanNm_CfgPtr->MainFunctionPeriod;
            }
        }
    }
}
#endif /* STD_ON == CANNM_PASSIVE_MODE_ENABLED */

/******************************************************************************/
/*
 * Brief               Process used timers
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_TimerManagement(uint8 chIndex)
{
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);

/* Message timeout timer */
#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
    if (chRTPtr->msgTimeoutTimer > 0u)
    {
        chRTPtr->msgTimeoutTimer--;
        if (0u == chRTPtr->msgTimeoutTimer)
        {
            chRTPtr->msgToutFlg = TRUE;

            /* @req SWS_CanNm_00446  @req SWS_CanNm_00066*/
            /*CanNmGlobalPnSupport = TRUE, Msg Tx timer expired,
             *call  Nm_TxTimeoutException  CanSM_TxTimeoutException*/

#if (STD_ON == CANNM_VER_4_2_2)
            Nm_TxTimeoutException(CanNm_GetComMNetworkHandle(chIndex));
            CanSM_TxTimeoutException(CanNm_GetComMNetworkHandle(chIndex));
#endif /*#if (STD_ON == CANNM_VER_4_2_2) */

#if (STD_ON == CANNM_VER_R19_11)
#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
            if ((boolean)TRUE == chCfgPtr->PnEnabled)
            {
                Nm_TxTimeoutException(CanNm_GetComMNetworkHandle(chIndex));
                CanSM_TxTimeoutException(CanNm_GetComMNetworkHandle(chIndex));
            }
#endif /* STD_ON == CANNM_GLOBAL_PN_SUPPORT*/
#endif /*#if (STD_ON == CANNM_VER_R19_11)*/
        }
    }
#endif /* STD_OFF == CANNM_PASSIVE_MODE_ENABLED */

/* NM time out timer */
#if (STD_ON == CANNM_COM_CONTROL_ENABLED)
    /* @req SWS_CanNm_00174 */
    /* Transmit ability disable,shall stop nm timeout timer */
    if ((boolean)TRUE == chRTPtr->canNmTxEnable)
#endif /* STD_ON == CANNM_COM_CONTROL_ENABLED */
    {
        if (chRTPtr->nmTimeoutTimer > 0u)
        {
            chRTPtr->nmTimeoutTimer--;
            if (0u == chRTPtr->nmTimeoutTimer)
            {
                chRTPtr->nmToutFlg = TRUE;

                if ((NM_STATE_NORMAL_OPERATION == chRTPtr->canNmState)
                    || (NM_STATE_REPEAT_MESSAGE == chRTPtr->canNmState))
                {
                    /* @req SWS_CanNm_00117,@req SWS_CanNm_00101 */
                    /*
                     * When the NM-Timeout Timer expires in the Normal
                     * Operation State or Repeat Message State,the
                     * NM-Timeout Timer shall be restarted.
                     */
                    chRTPtr->nmTimeoutTimer = chCfgPtr->TimeoutTime / CanNm_CfgPtr->MainFunctionPeriod;

/* @req SWS_CanNm_00194 @req SWS_CanNm_00193*/
/*
 * When the NM-Timeout Timer expires in the Repeat Message
 * State or Normal Operation State, the NM shall report
 * CANNM_E_NETWORK_TIMEOUT as Run Time Error.
 */
#if (STD_ON == CANNM_VER_4_2_2)
                    CANNM_DET_REPORT(CANNM_SERVICE_ID_MAINFUNCTION, CANNM_E_NETWORK_TIMEOUT);
#else
                    CANNM_DET_REPORTRUNTIMEERROR(CANNM_SERVICE_ID_MAINFUNCTION, CANNM_E_NETWORK_TIMEOUT);
#endif /*#if (STD_ON == CANNM_VER_4_2_2)*/
                }
            }
        }
    }

    /* State timer */
    if (chRTPtr->stateTimer > 0u)
    {
        chRTPtr->stateTimer--;
        if (0u == chRTPtr->stateTimer)
        {
            chRTPtr->stateToutFlg = TRUE;
        }
    }

/* Remote sleep timer and detected logic calculate */
#if (STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED)
    if ((NM_STATE_NORMAL_OPERATION == chRTPtr->canNmState) && (chRTPtr->remoteTimer > 0u))
    {
        chRTPtr->remoteTimer--;
        if (0u == chRTPtr->remoteTimer)
        {
            /* @req SWS_CanNm_00150 */
            chRTPtr->remoteSleepInd = TRUE;
            Nm_RemoteSleepIndication(CanNm_GetComMNetworkHandle(chIndex));
        }
    }
#endif /* STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED */

/* Msg cycle timer */
#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
    CanNm_MsgcycleTimerManage(chIndex);
#endif /* STD_ON == CANNM_PASSIVE_MODE_ENABLED */

#if (STD_ON == CANNM_PN_ERA_CALC_ENABLED)
    if ((boolean)TRUE == chCfgPtr->PnEraCalcEnabled)
    {
        CanNm_PnEraResetTimerHandle(chIndex);
    }
#endif /* STD_ON == CANNM_PN_ERA_CALC_ENABLED */

#if (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
    if (CANNM_EIRA_HANDLE_CHANNEL == chIndex)
    {
        CanNm_PnEiraResetTimerHandle();
    }
#endif /* STD_ON == CANNM_PN_EIRA_CALC_ENABLED */
}

#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
/******************************************************************************/
/*
 * Brief               Determine whether have relevant PN information to this
 *                     channel according CBV data and channel config data
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chCfgPtr, Channel config data pointer
 *                     chRTPtr, Channel runtime data pointer
 *                     PduInfoPtr, Received pduInfo pointer
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              TRUE: Have relevant PN information
 *                     FALSE: No relevant PN information
 */
/******************************************************************************/
static FUNC(boolean, CANNM_CODE) CanNm_RxPnFilter(
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST) chCfgPtr,
    CanNm_InnerChannelType* chRTPtr,
    P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr)
{
    boolean ret = TRUE;

    /*@req SWS_CanNm_00409*/
    if ((boolean)TRUE == chCfgPtr->PnEnabled)
    {
        /* @req SWS_CanNm_00410 */
        if ((boolean)TRUE == chCfgPtr->AllNmMessagesKeepAwake)
        {
            chRTPtr->pnRxIndFlg = TRUE;
        }
        else if (CANNM_PDU_OFF != chCfgPtr->PduCbvPosition)
        {
            uint8 cbv = PduInfoPtr->SduDataPtr[(uint8)chCfgPtr->PduCbvPosition];
            /*@req SWS_CanNm_00412 @req SWS_CanNm_00411*/
            if ((cbv & CANNM_CBV_BIT_PNI_MASK) > 0u)
            {
                if ((boolean)TRUE == chRTPtr->pnFilterEnable)
                {
                    uint8 pduIdx;
                    P2CONST(CanNm_PnInfoType, AUTOMATIC, CANNM_APPL_CONST)
                    pnInfoPtr = &CanNm_GetPnInfo();
                    P2CONST(CanNm_PnFilterMaskByteType, AUTOMATIC, CANNM_APPL_CONST)
                    pnFilMaskByte = pnInfoPtr->PnFilterMaskByte;

                    ret = FALSE;
                    for (pduIdx = 0u; pduIdx < pnInfoPtr->CanNmPnFilterMaskByteNum; pduIdx++)
                    {
                        uint8 byteIndex = pnInfoPtr->CanNmPnInfoOffset + pnFilMaskByte[pduIdx].PnFilterMaskByteIndex;

                        if ((PduInfoPtr->SduDataPtr[byteIndex] & pnFilMaskByte[pduIdx].PnFilterMaskByteValue) > 0u)
                        {
                            chRTPtr->pnRxIndFlg = TRUE;
                            ret = TRUE;
                            break;
                        }
                    }
                }
                else
                {
                    /*@req SWS_CanNm_00404 note*/
                    chRTPtr->nmTimeoutTimer = chCfgPtr->TimeoutTime / CanNm_CfgPtr->MainFunctionPeriod;
                    chRTPtr->pnRxIndFlg = FALSE;
                }
            }
            else
            {
                /* not accept this nm pdu*/
                chRTPtr->pnRxIndFlg = FALSE;
                ret = FALSE;
            }
        }
        else
        {
            /*@req SWS_CanNm_00409*/
            /* Nothing to do here*/
        }
    }
    return ret;
}
#endif /* STD_ON == CANNM_GLOBAL_PN_SUPPORT*/

#if (                                   \
    (STD_ON == CANNM_GLOBAL_PN_SUPPORT) \
    && ((STD_ON == CANNM_PN_ERA_CALC_ENABLED) || (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)))
/******************************************************************************/
/*
 * Brief               Handle EIRA and ERA according received data
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_RxPnEiraEraHandle(uint8 chIndex)
{
#if (STD_ON == CANNM_PN_ERA_CALC_ENABLED)
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
#endif
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
    P2CONST(CanNm_PnInfoType, AUTOMATIC, CANNM_APPL_CONST)
    pnInfoPtr = &CanNm_GetPnInfo();
    uint8* pnEiraInfoPtr = CanNm_GetPnEiraInfo();
    uint16* pnEiraResetTimerPtr = CanNm_GetPnEiraResetTimer();
    uint8 rxPnInfoDta;
    uint8 bitMask;
#if (STD_ON == CANNM_PN_ERA_CALC_ENABLED)
    boolean rxIndEraFlag = FALSE;
#endif /* (STD_ON == CANNM_PN_ERA_CALC_ENABLED) */
#if (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
    boolean rxIndEiraFlag = FALSE;
#endif /* (STD_ON == CANNM_PN_EIRA_CALC_ENABLED) */
    uint8 index;
    P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA) rxPnDtaPtr = &(chRTPtr->rxPduData[pnInfoPtr->CanNmPnInfoOffset]);
    uint8 filterMaskData;
    uint8 pnIdx = 0u;
    uint8 find0To1;

    /* Handle ERA and EIRA resetTimer */
    for (index = 0u; index < (pnInfoPtr->CanNmPnInfoLength * 8u); index++)
    {
        bitMask = (0x1u << (index % 8u));
        filterMaskData = pnInfoPtr->PnFilterMaskByte[index / 8u].PnFilterMaskByteValue;

        if ((filterMaskData & bitMask) > 0u)
        {
            rxPnInfoDta = rxPnDtaPtr[index / 8u];

            if (0u != (rxPnInfoDta & bitMask))
            {
#if (STD_ON == CANNM_PN_ERA_CALC_ENABLED)
                if ((boolean)TRUE == chCfgPtr->PnEraCalcEnabled)
                {
                    /* @req SWS_CanNm_00359 */
                    /*
                     * A PN is requested by reception the monitoring for
                     * this PN shall be restarted.
                     */
                    chRTPtr->pnEraResetTimer[pnIdx] = CanNm_GetPnResetTime() / CanNm_CfgPtr->MainFunctionPeriod;
                }
#endif /* (STD_ON == CANNM_PN_ERA_CALC_ENABLED) */

#if (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
                /* @req SWS_CanNm_00349 */
                pnEiraResetTimerPtr[pnIdx] = CanNm_GetPnResetTime() / CanNm_CfgPtr->MainFunctionPeriod;
#endif /* (STD_ON == CANNM_PN_EIRA_CALC_ENABLED) */
            }
            pnIdx++;
        }
    }

#if (STD_ON == CANNM_PN_ERA_CALC_ENABLED)
    if ((boolean)TRUE == chCfgPtr->PnEraCalcEnabled)
    {
        for (index = 0u; index < pnInfoPtr->CanNmPnInfoLength; index++)
        {
            filterMaskData = pnInfoPtr->PnFilterMaskByte[index].PnFilterMaskByteValue;
            find0To1 = rxPnDtaPtr[index] & filterMaskData;

            find0To1 = find0To1 & (~chRTPtr->pnInfoEra[index]);

            if (find0To1 > 0u)
            {
                /* Find rx pdu pninfo bit 0--->1 */
                rxIndEraFlag = TRUE;
                break;
            }
        }
    }
#endif /* (STD_ON == CANNM_PN_ERA_CALC_ENABLED) */

#if (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
    for (index = 0u; index < pnInfoPtr->CanNmPnInfoLength; index++)
    {
        filterMaskData = pnInfoPtr->PnFilterMaskByte[index].PnFilterMaskByteValue;
        find0To1 = rxPnDtaPtr[index] & filterMaskData;
        find0To1 = find0To1 & (~pnEiraInfoPtr[index]);

        if (find0To1 > 0u)
        {
            /* Find rx pdu pninfo bit 0--->1 */
            rxIndEiraFlag = TRUE;
            break;
        }
    }
#endif /* (STD_ON == CANNM_PN_EIRA_CALC_ENABLED) */

    /* @req SWS_CanNm_00347 @req SWS_CanNm_00357 */
    /*
     * PNs are requested within received message, CanNm shall store
     * the request information
     */
    for (index = 0u; index < pnInfoPtr->CanNmPnInfoLength; index++)
    {
        filterMaskData = pnInfoPtr->PnFilterMaskByte[index].PnFilterMaskByteValue;
        uint8 relatedPnData = rxPnDtaPtr[index] & filterMaskData;

#if (STD_ON == CANNM_PN_ERA_CALC_ENABLED)
        if ((boolean)TRUE == chCfgPtr->PnEraCalcEnabled)
        {
            chRTPtr->pnInfoEra[index] |= relatedPnData;
        }
#endif /* (STD_ON == CANNM_PN_ERA_CALC_ENABLED) */

#if (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
        pnEiraInfoPtr[index] |= relatedPnData;
#endif /* (STD_ON == CANNM_PN_EIRA_CALC_ENABLED) */
    }

    /* @req SWS_CanNm_00352,@req SWS_CanNm_00361 */
    /*
     * If the stored value for a PN is set to requested,CanNm
     * shall inform upper layers.
     */
    PduIdType upRxPduId;
    PduInfoType PduInfo;
#if (STD_ON == CANNM_PN_ERA_CALC_ENABLED)
    if ((boolean)TRUE == rxIndEraFlag)
    {
        upRxPduId = chCfgPtr->PnEraRxNSduRef;
        PduInfo.SduLength = pnInfoPtr->CanNmPnInfoLength;
        PduInfo.SduDataPtr = chRTPtr->pnInfoEra;
        PduInfo.MetaDataPtr = NULL_PTR;
        PduR_CanNmRxIndication(upRxPduId, &PduInfo);
    }
#endif /* (STD_ON == CANNM_PN_ERA_CALC_ENABLED) */

#if (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
    if ((boolean)TRUE == rxIndEiraFlag)
    {
        upRxPduId = CanNm_GetPnEiraRxNSduId();
        PduInfo.SduLength = pnInfoPtr->CanNmPnInfoLength;
        PduInfo.SduDataPtr = pnEiraInfoPtr;
        PduInfo.MetaDataPtr = NULL_PTR;
        PduR_CanNmRxIndication(upRxPduId, &PduInfo);
    }
#endif /* (STD_ON == CANNM_PN_EIRA_CALC_ENABLED) */
}
#endif /*((STD_ON == CANNM_GLOBAL_PN_SUPPORT)&&   \
         ((STD_ON == CANNM_PN_ERA_CALC_ENABLED)|| \
          (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)))*/

#if (STD_ON == CANNM_PN_ERA_CALC_ENABLED)
/******************************************************************************/
/*
 * Brief               Handle ERA reset timer,when timer expired,notify PduR
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_PnEraResetTimerHandle(uint8 chIndex)
{
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
    P2CONST(CanNm_PnInfoType, AUTOMATIC, CANNM_APPL_CONST)
    pnInfoPtr = &CanNm_GetPnInfo();
    uint8 bitMask;
    boolean eraIndFlag = FALSE;
    uint8 index;
    uint8 filterMaskData;
    uint8 pnIdx = 0u;

    for (index = 0u; index < (pnInfoPtr->CanNmPnInfoLength * 8u); index++)
    {
        bitMask = (0x1u << (index % 8u));
        filterMaskData = pnInfoPtr->PnFilterMaskByte[index / 8u].PnFilterMaskByteValue;

        if ((filterMaskData & bitMask) > 0u)
        {
            if (chRTPtr->pnEraResetTimer[pnIdx] > 0u)
            {
                chRTPtr->pnEraResetTimer[pnIdx]--;
                if (0u == chRTPtr->pnEraResetTimer[pnIdx])
                {
                    /* @req SWS_CanNm_00360 */
                    /*
                     * PN is not requested again within CanNmPnResetTime
                     * then the corresponding stored value for this PN
                     * shall be set to not requested (value 0).
                     */
                    chRTPtr->pnInfoEra[index / 8u] &= (~bitMask);
                    eraIndFlag = TRUE;
                }
            }

            pnIdx++;
        }
    }

    /* @req SWS_CanNm_00361 */
    if ((boolean)TRUE == eraIndFlag)
    {
        PduIdType upRxPduId = chCfgPtr->PnEraRxNSduRef;
        PduInfoType PduInfoPtr;
        PduInfoPtr.SduLength = pnInfoPtr->CanNmPnInfoLength;
        PduInfoPtr.SduDataPtr = chRTPtr->pnInfoEra;
        PduInfoPtr.MetaDataPtr = NULL_PTR;
        PduR_CanNmRxIndication(upRxPduId, &PduInfoPtr);
    }
}
#endif /*STD_ON == CANNM_PN_ERA_CALC_ENABLED*/

#if (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
/******************************************************************************/
/*
 * Brief               Handle EIRA reset timer,when timer expired,notify PduR
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_PnEiraResetTimerHandle(void)
{
    P2CONST(CanNm_PnInfoType, AUTOMATIC, CANNM_APPL_CONST)
    pnInfoPtr = &CanNm_GetPnInfo();
    uint8* pnEiraInfoPtr = CanNm_GetPnEiraInfo();
    uint16* pnEiraResetTimerPtr = CanNm_GetPnEiraResetTimer();
    uint8 bitMask;
    boolean eiraIndFlag = FALSE;
    uint8 index;
    uint8 filterMaskData;
    uint8 pnIdx = 0u;

    for (index = 0u; index < (pnInfoPtr->CanNmPnInfoLength * 8u); index++)
    {
        bitMask = (0x1u << (index % 8u));
        filterMaskData = pnInfoPtr->PnFilterMaskByte[index / 8u].PnFilterMaskByteValue;

        if ((filterMaskData & bitMask) > 0u)
        {
            if (pnEiraResetTimerPtr[pnIdx] > 0u)
            {
                pnEiraResetTimerPtr[pnIdx]--;
                if (0u == pnEiraResetTimerPtr[pnIdx])
                {
                    /* @req SWS_CanNm_00351 */
                    /*
                     * PN is not requested again within CanNmPnResetTime
                     * then the corresponding stored value for this PN
                     * shall be set to not requested (value 0).
                     */
                    pnEiraInfoPtr[index / 8u] &= (~bitMask);
                    eiraIndFlag = TRUE;
                }
            }

            pnIdx++;
        }
    }

    /* @req SWS_CanNm_00352 */
    if ((boolean)TRUE == eiraIndFlag)
    {
        PduIdType upRxPduId = CanNm_GetPnEiraRxNSduId();
        PduInfoType PduInfoPtr;
        PduInfoPtr.SduLength = pnInfoPtr->CanNmPnInfoLength;
        PduInfoPtr.SduDataPtr = pnEiraInfoPtr;
        PduInfoPtr.MetaDataPtr = NULL_PTR;
        PduR_CanNmRxIndication(upRxPduId, &PduInfoPtr);
    }
}
#endif /* (STD_ON == CANNM_PN_EIRA_CALC_ENABLED) */

#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
static FUNC(Std_ReturnType, CANNM_CODE) CanNm_SendNmPdu(uint8 chIndex, boolean addTransFlag)
{
    Std_ReturnType ret;
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
#if (STD_ON == CANNM_COM_CONTROL_ENABLED)
    if ((boolean)FALSE == chRTPtr->canNmTxEnable)
    {
        ret = E_NOT_OK;
    }
    else
#endif /* (STD_ON == CANNM_COM_CONTROL_ENABLED) */
    {
        P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
        chCfgPtr = &CanNm_GetChannelConfig(chIndex);
        PduInfoType pduInfo;

/* @req SWS_CanNm_00317 */
#if (STD_ON == CANNM_COM_USERDATA_SUPPORT)
        if ((addTransFlag == (boolean)FALSE) && ((boolean)FALSE == chCfgPtr->TxPdu->TxPduIsTriggerTrans))
        {
            PduIdType pdurTxSduId = chCfgPtr->UserDataTxPdu->UpperLayerPduId;
            pduInfo.SduDataPtr = &chRTPtr->txPduData[chCfgPtr->UserDataOffset];
            pduInfo.SduLength = chCfgPtr->UserDataLength;
            pduInfo.MetaDataPtr = NULL_PTR;
            ret = PduR_CanNmTriggerTransmit(pdurTxSduId, &pduInfo);
            if ((uint8)E_OK == ret)
            {
/** @req SWS_CanNm_00450
 * If CanNmComUserDataSupport is enabled and PduR_CanNmTriggerTransmit returns E_NOT_OK,
 *  the NM shall use the last transmitted value for NmUserData
 */
#if (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)
                if ((boolean)TRUE == chCfgPtr->PnEnabled)
                {
                    /* @req SWS_CanNm_00348 @req SWS_CanNm_00345 */
                    CanNm_TxPnEiraHandle(chRTPtr->txPduData);
                }
#endif /* STD_ON == CANNM_PN_EIRA_CALC_ENABLED */
            }
            else
            {
                /* clear copy data */
                for (uint8 index = 0u; index < pduInfo.SduLength; index++)
                {
                    pduInfo.SduDataPtr[index] = 0u;
                }
            }
        }
#else
        CANNM_UNUSED(addTransFlag);
#endif /* STD_OFF==CANNM_COM_USERDATA_SUPPORT */

#if (0u < CANNM_TX_PDU_NUMBER_MAX)
        /* if PduR_CanNmTriggerTransmit return E_NOT_OK allow transmit nm pdu */
        PduIdType canIfTxSduId = chCfgPtr->TxPdu->LowerLayerPduId;
        pduInfo.SduDataPtr = chRTPtr->txPduData;
        pduInfo.SduLength = CANNM_DEFAULT_PDU_LENGTH;

        /* @req SWS_CanNm_00032 */
        ret = CanIf_Transmit(canIfTxSduId, &pduInfo);

        if ((uint8)E_OK == ret)
        {
#if (STD_OFF == CANNM_IMMEDIATE_TXCONF_ENABLED)
            chRTPtr->msgTimeoutTimer = chCfgPtr->MsgTimeoutTime / CanNm_CfgPtr->MainFunctionPeriod;
            chRTPtr->msgToutFlg = FALSE;
#else
            CanNm_InnerTxConfHandle(chIndex);
#endif /* (STD_OFF == CANNM_IMMEDIATE_TXCONF_ENABLED) */
        }

#endif /* 0u < CANNM_TX_PDU_NUMBER */
    }
    return ret;
}
#endif /* STD_OFF == CANNM_PASSIVE_MODE_ENABLED */

#if ((STD_ON == CANNM_PN_EIRA_CALC_ENABLED) && (STD_ON == CANNM_COM_USERDATA_SUPPORT))
/******************************************************************************/
/*
 * Brief               Handle EIRA according tx data
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      txDta, Tx data
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_TxPnEiraHandle(P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA) txDta)
{
    P2CONST(CanNm_PnInfoType, AUTOMATIC, CANNM_APPL_CONST)
    pnInfoPtr = &CanNm_GetPnInfo();
    uint8* pnEiraInfoPtr = CanNm_GetPnEiraInfo();
    uint16* pnEiraResetTimerPtr = CanNm_GetPnEiraResetTimer();
    boolean rxIndEiraFlag = FALSE;
    uint8 bitMask;
    uint8 txPnInfoDta, localPnInfoDta;
    P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA)
    txPnDta = &(txDta[pnInfoPtr->CanNmPnInfoOffset]);
    uint8 index;
    uint8 pnIdx = 0u;
    uint8 filterMaskData;
    uint8 relatedPnData;

    for (index = 0u; index < (pnInfoPtr->CanNmPnInfoLength * 8u); index++)
    {
        bitMask = (0x1u << (index % 8u));
        filterMaskData = pnInfoPtr->PnFilterMaskByte[index / 8u].PnFilterMaskByteValue;

        if ((filterMaskData & bitMask) > 0u)
        {
            txPnInfoDta = txPnDta[index / 8u];
            localPnInfoDta = pnEiraInfoPtr[index / 8u];

            if ((txPnInfoDta & bitMask) > 0u)
            {
                /* @req SWS_CanNm_00349 */
                pnEiraResetTimerPtr[pnIdx] = CanNm_GetPnResetTime() / CanNm_CfgPtr->MainFunctionPeriod;

                if (((boolean)FALSE == rxIndEiraFlag) && ((localPnInfoDta & bitMask) == 0u))
                {
                    rxIndEiraFlag = TRUE;
                }
            }

            pnIdx++;
        }
    }

    for (index = 0u; index < pnInfoPtr->CanNmPnInfoLength; index++)
    {
        filterMaskData = pnInfoPtr->PnFilterMaskByte[index].PnFilterMaskByteValue;
        relatedPnData = txPnDta[index] & filterMaskData;
        if (relatedPnData > 0u)
        {
            pnEiraInfoPtr[index] |= relatedPnData;
        }
    }

    /* @req SWS_CanNm_00352 */
    if ((boolean)TRUE == rxIndEiraFlag)
    {
        PduIdType upRxPduId = CanNm_GetPnEiraRxNSduId();
        PduInfoType PduInfoPtr;
        PduInfoPtr.SduLength = pnInfoPtr->CanNmPnInfoLength;
        PduInfoPtr.SduDataPtr = pnEiraInfoPtr;
        PduInfoPtr.MetaDataPtr = NULL_PTR;
        PduR_CanNmRxIndication(upRxPduId, &PduInfoPtr);
    }
}
#endif

/******************************************************************************/
/*
 * Brief               Handle state transition of CanNm
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_StateManagement(uint8 chIndex)
{
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
    switch (chRTPtr->canNmState)
    {
    case NM_STATE_BUS_SLEEP:
        CanNm_BusSleepStateHandle(chIndex);
        break;

    case NM_STATE_PREPARE_BUS_SLEEP:
        CanNm_PrepareBusSleepStateHandle(chIndex);
        break;

    case NM_STATE_REPEAT_MESSAGE:
        CanNm_RepeatMessageStateHandle(chIndex);
        break;

    case NM_STATE_NORMAL_OPERATION:
        CanNm_NormalOperationStateHandle(chIndex);
        break;

    case NM_STATE_READY_SLEEP:
        CanNm_ReadySleepStateHandle(chIndex);
        break;

    default:
        /*nothing*/
        break;
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Bus Sleep State
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_BusSleepStateHandle(uint8 chIndex)
{
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
    if ((boolean)TRUE == chRTPtr->passiveStartUp)
    {
        /* @req SWS_CanNm_00128 */
        /* Entry repeat message Mode */
        CanNm_EntryRepeatMessageState(chIndex, FALSE);
    }

    /* Network Request */
    if ((boolean)TRUE == chRTPtr->netRequestFlg)
    {
        if ((boolean)TRUE == chCfgPtr->ActiveWakeupBitEnabled)
        {
            /* @req SWS_CanNm_00401 */
            /* Set ActiveWakeupBit in CBV */
            CanNm_SetTxPduCbvBit(chIndex, CANNM_CBV_BIT_AW_MASK);
        }

        /* @req SWS_CanNm_00129 */
        /*
         * Network is requested in Bus-Sleep Mode, the CanNm module shall
         * enter Repeat Message State.
         */
        CanNm_EntryRepeatMessageState(chIndex, TRUE);
    }
    else
    {
        /* Network Release */
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Prepare Bus Sleep State
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_PrepareBusSleepStateHandle(uint8 chIndex)
{
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
    if ((boolean)TRUE == chRTPtr->passiveStartUp)
    {
        /* @req SWS_CanNm_00128 */
        /* Entry repeat message Mode */
        CanNm_EntryRepeatMessageState(chIndex, FALSE);
    }

    if ((boolean)TRUE == chRTPtr->netRequestFlg)
    {
        if ((boolean)TRUE == chCfgPtr->ActiveWakeupBitEnabled)
        {
            /* @req SWS_CanNm_00401 */
            /* Set ActiveWakeupBit in CBV */
            CanNm_SetTxPduCbvBit(chIndex, CANNM_CBV_BIT_AW_MASK);
        }

        /* @req SWS_CanNm_00123 */
        /* network  requset,will be entry Repeat Message state */
        CanNm_EntryRepeatMessageState(chIndex, TRUE);
    }
    else if ((boolean)TRUE == chRTPtr->rxPduExtFlg)
    {
        /* @req SWS_CanNm_00124 */
        /* Receive NM pdu in Prepare Bus-Sleep Mode,enter Repeat Message state*/
        CanNm_EntryRepeatMessageState(chIndex, FALSE);
    }
    else if ((boolean)TRUE == chRTPtr->stateToutFlg)
    {
        /* @req SWS_CanNm_00115 */
        /* State timer timeout,enter bus-sleep mode */
        CanNm_StateChange(chIndex, NM_STATE_BUS_SLEEP);
        chRTPtr->cannmMode = NM_MODE_BUS_SLEEP;

        /* @SWS_CanNm_00126 @req SWS_CanNm_00093 */
        Nm_BusSleepMode(CanNm_GetComMNetworkHandle(chIndex));
    }
    else
    {
        /* Nothing to do here */
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Repeat Message State
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_RepeatMessageStateHandle(uint8 chIndex)
{
#if ((STD_OFF == CANNM_PASSIVE_MODE_ENABLED) && (STD_ON == CANNM_GLOBAL_PN_SUPPORT)) \
    || ((STD_ON == CANNM_IMMEDIATE_TRANSMIT_ENABLED) && (STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED))
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
#endif
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);

#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
    boolean stateChanged = FALSE;
    /* @req SWS_CanNm_00454 */
    if (((boolean)TRUE == chRTPtr->netRequestFlg) && ((boolean)TRUE == chCfgPtr->PnHandleMultipleNetworkRequests))
    {
        CanNm_EntryRepeatMessageState(chIndex, TRUE);

        stateChanged = TRUE;
    }
    if (!stateChanged)
#endif /*STD_ON == CANNM_GLOBAL_PN_SUPPORT*/
#endif /* #if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)*/
    {
        /* @req SWS_CanNm_00102 */
        if ((boolean)TRUE == chRTPtr->stateToutFlg)
        {
#if (STD_ON == CANNM_IMMEDIATE_TRANSMIT_ENABLED)
            chRTPtr->immedMsgTxCnt = 0u;
#endif /* STD_ON == CANNM_IMMEDIATE_TRANSMIT_ENABLED */
            if (CANNM_NETWORK_REQUESTED == chRTPtr->netRequestStatus)
            {
                /* @req SWS_CanNm_00103 */
                /*
                 * If the network has been requested,normal opertation state
                 * shall be entered.
                 */
                CanNm_StateChange(chIndex, NM_STATE_NORMAL_OPERATION);

#if (STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED)
                /* @req SWS_CanNm_00150 */
                /* Enter NORMAL OPERATION,reset the RemoteSleepIndTimer */
                chRTPtr->remoteTimer = chCfgPtr->RemoteSleepIndTime / CanNm_CfgPtr->MainFunctionPeriod;
#endif /*STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED*/
            }
            else
            {
                /* @req SWS_CanNm_00106 */
                /*
                 * If the network has been released,Ready Sleep State
                 * shall be entered
                 */
                CanNm_StateChange(chIndex, NM_STATE_READY_SLEEP);

                /* @req SWS_CanNm_00108 @req SWS_CanNm_00051 */
                /*
                 * When the Ready Sleep State is entered from Repeat Message
                 * State,transmission of NM PDUs shall be stopped.
                 */
                chRTPtr->msgTxCylceTimer = 0u;
            }

/* @req SWS_CanNm_00107 */
/*
 * CanNm shall clear the Repeat Message Bit when leaving
 * Repeat Message State.
 */
#if (STD_ON == CANNM_NODE_DETECTION_ENABLED)
#if (STD_ON != CANNM_VER_4_2_2)
            if (TRUE == CanNm_GetNodeDetectionEnabled(chIndex))
#endif /* (STD_ON != CANNM_VER_4_2_2) */
            {
                CanNm_ClrTxPduCbvBit(chIndex, CANNM_CBV_BIT_RMP_MASK);
            }
#endif /* (STD_ON == CANNM_NODE_DETECTION_ENABLED) */
        }
    }
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Normal Operation State
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_NormalOperationStateHandle(uint8 chIndex)
{
#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT) || (STD_ON == CANNM_NODE_DETECTION_ENABLED)
    const CanNm_ChannelConfigType* chCfgPtr = &CanNm_GetChannelConfig(chIndex);
#endif /* (STD_ON == CANNM_GLOBAL_PN_SUPPORT) || \
         (STD_ON == CANNM_NODE_DETECTION_ENABLED) */
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
    /* @req SWS_CanNm_00118 */
    /* Left normal operation state,enter ready sleep state*/
    if (CANNM_NETWORK_RELEASED == chRTPtr->netRequestStatus)
    {
        CanNm_StateChange(chIndex, NM_STATE_READY_SLEEP);

        /* @req SWS_CanNm_00108 @req SWS_CanNm_00051 */
        /*
         * When the Ready Sleep State is entered from Normal Operation
         * State,transmission of NM PDUs shall be stopped.
         */
        chRTPtr->msgTxCylceTimer = 0u;
    }
    else
    {
/* @req SWS_CanNm_00454 */
#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
        boolean stateChanged = FALSE;
        if (((boolean)TRUE == chRTPtr->netRequestFlg) && ((boolean)TRUE == chCfgPtr->PnHandleMultipleNetworkRequests))
        {
            CanNm_EntryRepeatMessageState(chIndex, TRUE);

            stateChanged = TRUE;
        }
        if (!stateChanged)
#endif /* #if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)*/
        {
#if (STD_ON == CANNM_NODE_DETECTION_ENABLED)
            if (TRUE == CanNm_GetNodeDetectionEnabled(chIndex))
            {
                if ((boolean)TRUE == chRTPtr->repeatMessageRequest)
                {
                    /* @req SWS_CanNm_00120 */
                    CanNm_EntryRepeatMessageState(chIndex, FALSE);
                    /* @req SWS_CanNm_00121 */
                    CanNm_SetTxPduCbvBit(chIndex, CANNM_CBV_BIT_RMP_MASK);
                }
                else if (((boolean)TRUE == chRTPtr->rxPduExtFlg) && (CANNM_PDU_OFF != chCfgPtr->PduCbvPosition))
                {
                    uint8 cbvPos = (uint8)chCfgPtr->PduCbvPosition;
                    uint8 cbvDta = chRTPtr->rxPduData[cbvPos];
                    /* @req SWS_CanNm_00119 */
                    /*
                     * If CanNmNodeDetectionEnabled is set to TRUE and Repeat
                     * Message Request bit is received in Normal Operation State,
                     * CanNm shall enter Repeat Message State.
                     */
                    if ((cbvDta & CANNM_CBV_BIT_RMP_MASK) > 0u)
                    {
                        CanNm_EntryRepeatMessageState(chIndex, FALSE);
                    }
                }
                else
                {
                    /* Nothing to do here */
                }
            }
#endif /* STD_ON == CANNM_NODE_DETECTION_ENABLED */
        }
    }

/* @req SWS_CanNm_00156  SWS_CanNm_00157*/
/*the busload reduction is only work in Normal operation mode*/
#if (STD_ON == CANNM_BUSLOAD_REDUCTION_ENABLED)
    if ((NM_STATE_NORMAL_OPERATION == chRTPtr->canNmState) && (TRUE == chRTPtr->rxPduExtFlg))
    {
        /* @req SWS_CanNm_00069 */
        /* when busload reduction enbale,reload msgTxCylceTimer */
        if (TRUE == CanNm_GetBusLoadReduceEnabled(chIndex))
        {
            chRTPtr->msgTxCylceTimer = chCfgPtr->MsgReducedTime / CanNm_CfgPtr->MainFunctionPeriod;
        }
    }
#endif /* STD_ON == CANNM_BUSLOAD_REDUCTION_ENABLED */
#endif /* #if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED) */
}

/******************************************************************************/
/*
 * Brief               Handle state transition in Ready Sleep State
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_ReadySleepStateHandle(uint8 chIndex)
{
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
    boolean stateChanged = FALSE;

#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)

    if ((boolean)TRUE == chRTPtr->netRequestFlg)
    {
#if (STD_ON == CANNM_GLOBAL_PN_SUPPORT)
        if ((boolean)TRUE == chCfgPtr->PnHandleMultipleNetworkRequests)
        {
            /* @req SWS_CanNm_00454 */
            CanNm_EntryRepeatMessageState(chIndex, TRUE);
        }
        else
#endif /*(STD_ON == CANNM_GLOBAL_PN_SUPPORT)*/
        {
            /* @SWS_CanNm_00110
             network is request ,will entry normal operation mode */
            CanNm_StateChange(chIndex, NM_STATE_NORMAL_OPERATION);

/* @req SWS_CanNm_00116 @req SWS_CanNm_00006 */
/*
 * When the Normal Operation State is entered from Ready Sleep
 * State, transmission of NM PDUs shall be started immediately
 * unless passive mode is enabled or the NM message transmission
 * ability has been disabled.
 */
#if (STD_ON == CANNM_COM_CONTROL_ENABLED)
            if ((boolean)TRUE == chRTPtr->canNmTxEnable)
#endif /* STD_ON == CANNM_COM_CONTROL_ENABLED */
            {
                chRTPtr->msgTxCylceTimer = chCfgPtr->MsgCycleTime / CanNm_CfgPtr->MainFunctionPeriod;
                chRTPtr->sendNmMsgFlg = TRUE;
            }

#if (STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED)
            /* @req SWS_CanNm_00150 */
            /* Enter NORMAL OPERATION,reset the remoteTimer */
            chRTPtr->remoteTimer = chCfgPtr->RemoteSleepIndTime / CanNm_CfgPtr->MainFunctionPeriod;
#endif /* STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED*/
        }
        stateChanged = TRUE;
    }

#if (STD_ON == CANNM_NODE_DETECTION_ENABLED)
    if ((TRUE == CanNm_GetNodeDetectionEnabled(chIndex)) && ((boolean)TRUE == chRTPtr->repeatMessageRequest)
        && ((boolean)FALSE == stateChanged))
    {
        /* @req SWS_CanNm_00112 */
        CanNm_EntryRepeatMessageState(chIndex, FALSE);
        /* @req SWS_CanNm_00113 */
        CanNm_SetTxPduCbvBit(chIndex, CANNM_CBV_BIT_RMP_MASK);

        stateChanged = TRUE;
    }
#endif /* STD_ON == CANNM_NODE_DETECTION_ENABLED */
#endif /* STD_OFF == CANNM_PASSIVE_MODE_ENABLED */

#if (STD_ON == CANNM_NODE_DETECTION_ENABLED)
    if ((TRUE == CanNm_GetNodeDetectionEnabled(chIndex)) && ((boolean)TRUE == chRTPtr->rxPduExtFlg)
        && (CANNM_PDU_OFF != chCfgPtr->PduCbvPosition) && ((boolean)FALSE == stateChanged))
    {
        uint8 cbvPos = (uint8)chCfgPtr->PduCbvPosition;
        uint8 cbvDta = chRTPtr->rxPduData[cbvPos];
        /* @req SWS_CanNm_00111 */
        /*
         * If CanNmNodeDetectionEnabled is set to TRUE and Repeat
         * Message Request bit is received in the Ready Sleep State,
         * CanNm shall enter Repeat Message State.
         */
        if ((cbvDta & CANNM_CBV_BIT_RMP_MASK) > 0u)
        {
            CanNm_EntryRepeatMessageState(chIndex, FALSE);
        }
    }
#endif /* STD_ON == CANNM_NODE_DETECTION_ENABLED */

    if (((boolean)TRUE == chRTPtr->nmToutFlg) && ((boolean)FALSE == stateChanged))
    {
        /* @req SWS_CanNm_00109 */
        CanNm_EnterPrepareBusSleepModeHandle(chIndex);
    }

#if (STD_ON == CANNM_COM_CONTROL_ENABLED)
    if (((boolean)FALSE == chRTPtr->canNmTxEnable) && (CANNM_NETWORK_RELEASED == chRTPtr->netRequestStatus)
        && ((boolean)FALSE == stateChanged))
    {
        /* @req SWS_CanNm_00170 note*/
        /*this function is delete in the R19-11,but I think this point
         *should reserve for wrong usage of communication control */
        CanNm_EnterPrepareBusSleepModeHandle(chIndex);
    }
#endif /* #if (STD_ON == CANNM_COM_CONTROL_ENABLED)*/
}

/******************************************************************************/
/*
 * Brief               Asynchronous process received data in MainFunction
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_RxDataMainHandle(uint8 chIndex)
{
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
/* Detection of Remote Sleep Indication Handle */
#if (STD_ON == CANNM_REMOTE_SLEEP_IND_ENABLED)
    /* @req SWS_CanNm_00150 */
    /* Reset RemoteSleepInd timer */
    chRTPtr->remoteTimer = chCfgPtr->RemoteSleepIndTime / CanNm_CfgPtr->MainFunctionPeriod;

    /* @req SWS_CanNm_00151*/
    /*
     * If an NM PDU is received in the Normal Operation State or Ready Sleep
     * State,shall notify the NM that some nodes in the cluster are not ready
     * to sleep anymore.
     */
    if (((boolean)TRUE == chRTPtr->remoteSleepInd)
        && ((NM_STATE_NORMAL_OPERATION == chRTPtr->canNmState) || (NM_STATE_READY_SLEEP == chRTPtr->canNmState)))
    {
        chRTPtr->remoteSleepInd = FALSE;
        Nm_RemoteSleepCancellation(CanNm_GetComMNetworkHandle(chIndex));
    }
#endif /* CANNM_REMOTE_SLEEP_IND_ENABLED */

    /* @req SWS_CanNm_00098 */
    /*
     * Successful reception of an NM PDU in Network Mode, the
     * NM-Timeout Timer shall be restarted.
     */
    if (NM_MODE_NETWORK == chRTPtr->cannmMode)
    {
        chRTPtr->nmTimeoutTimer = chCfgPtr->TimeoutTime / CanNm_CfgPtr->MainFunctionPeriod;
    }

#if ((STD_ON == CANNM_REPEAT_MSG_IND_ENABLED) && (STD_ON == CANNM_NODE_DETECTION_ENABLED))
    /* @req SWS_CanNm_00014 */
    /*
     * If CanNmNodeDetectionEnabled and CanNmRepeatMsgIndEnabled are set
     * to TRUE and Repeat Message Request bit is received, CanNm module
     * shall call the callback function Nm_RepeatMessageIndication.
     */
    if ((CANNM_PDU_OFF != chCfgPtr->PduCbvPosition)
#if (STD_ON != CANNM_VER_4_2_2)
        && (TRUE == CanNm_GetNodeDetectionEnabled(chIndex)) && (TRUE == CanNm_GetRepeatMsgIndEnabled(chIndex))
#endif /* (STD_ON != CANNM_VER_4_2_2) */
    )
    {
        uint8 cbvPos = (uint8)chCfgPtr->PduCbvPosition;
        uint8 cbvDta = chRTPtr->rxPduData[cbvPos];

        if ((cbvDta & CANNM_CBV_BIT_RMP_MASK) > 0u)
        {
            Nm_RepeatMessageIndication(CanNm_GetComMNetworkHandle(chIndex));
        }
    }
#endif /* STD_ON == CANNM_REPEAT_MSG_IND_ENABLED && \
          STD_ON == CANNM_NODE_DETECTION_ENABLED */

#if (STD_ON == CANNM_CAR_WAKEUP_RX_ENABLED)
    if ((boolean)TRUE == CanNm_GetCarWakeUpRxEnabled(chIndex))
    {
        CanNm_RxCarWakeUpHadle(chIndex);
    }
#endif /* STD_ON == CANNM_CAR_WAKEUP_RX_ENABLED */

#if (STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT)
    if (CANNM_PDU_OFF != chCfgPtr->PduCbvPosition)
    {
        /* NM Coordinator synchronization support */
        CanNm_CoordReadyToSleepIndHandle(chIndex);
    }
#endif /* STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT */

#if (                                   \
    (STD_ON == CANNM_GLOBAL_PN_SUPPORT) \
    && ((STD_ON == CANNM_PN_ERA_CALC_ENABLED) || (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)))
    if (((boolean)TRUE == chCfgPtr->PnEnabled) && ((boolean)TRUE == chRTPtr->pnRxIndFlg))
    {
        /* @req SWS_CanNm_00428 @req SWS_CanNm_00429 */
        CanNm_RxPnEiraEraHandle(chIndex);
    }
#endif /*((STD_ON == CANNM_GLOBAL_PN_SUPPORT)&&    \
          ((STD_ON == CANNM_PN_ERA_CALC_ENABLED)|| \
           (STD_ON == CANNM_PN_EIRA_CALC_ENABLED)))*/
}

/******************************************************************************/
/*
 * Brief               Send message in MainFunction.The purpose of this function
 *                     is to aggregate multiple send requests,Only one frame
 *                     will be sent out when there are multiple send requests in
 *                     a MainFunction.
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_SendMsgMainHandle(uint8 chIndex)
{
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
    Std_ReturnType ret;
    // static uint8 nmSendFalg = 0;
    //  static uint8 nmSendokFalg = 0;

    if ((boolean)TRUE == chRTPtr->sendNmMsgFlg)
    {
        // if(0 == nmSendFalg)
        // {
        //     //NMCounter1MS =  Counter1ms;
        //     //NMCounter5MS =  Counter5ms;
        //     nmSendFalg = 1;
        // }  
        // if(3 == chIndex)
        // {
        //     Nm_Counter++;
        //     if(Nm_Counter>=Nm_CounterThre)
        //     {
        //         volatile  uint8 test = 1;
        //     }

        // }      
        ret = CanNm_SendNmPdu(chIndex, FALSE);
        chRTPtr->sendNmMsgFlg = FALSE;
        if ((uint8)E_OK == ret)
        {
            // if(0 == nmSendokFalg)
            // {
            //     //NMCounterOK1MS =  Counter1ms;
            //     nmSendokFalg = 1;
            // }                                
            chRTPtr->retrySendMsgFlag = FALSE;
            // if (1 == NM_Sleep2Wakeup)
            // {
            //     TXAllow = 1; 
            //     NM_Sleep2Wakeup = 0;     
            // }
#if (STD_ON == CANNM_IMMEDIATE_TRANSMIT_ENABLED)
            if (chRTPtr->immedMsgTxCnt > 0u)
            {
                chRTPtr->immedMsgTxCnt--;
                if (0u == chRTPtr->immedMsgTxCnt)
                {
                    chRTPtr->msgTxCylceTimer = chCfgPtr->MsgCycleTime / CanNm_CfgPtr->MainFunctionPeriod;
                }
            }
#endif
        }
        else
        {
            //NMCounter5MS++;
            if ((boolean)TRUE == chRTPtr->retrySendMsgFlag)
            {
                /*@req SWS_CanNm_00335*/
                /*if transmit fail,retry in the next main function and modify
                 *the transmit timer to CanNmMsgCycleTime*/
                chRTPtr->retrySendMsgFlag = FALSE;
#if (STD_ON == CANNM_IMMEDIATE_TRANSMIT_ENABLED)
                //chRTPtr->immedMsgTxCnt = 0u;
#endif
                /*timeout in the next main function*/
                chRTPtr->msgTxCylceTimer = 1u;
            }
        }
    }
}

#if (STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT)
/******************************************************************************/
/*
 * Brief               NM Coordinator synchronization support handle
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_CoordReadyToSleepIndHandle(uint8 chIndex)
{
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    /* PRQA S 3432 ++ */ /* MISRA Rule 20.7 */
    P2VAR(CanNm_InnerChannelType, AUTOMATIC, CANNM_APPL_DATA)
    chRTPtr = &CanNm_GetChannelRTData(chIndex);
    /* PRQA S 3432 -- */ /* MISRA Rule 20.7 */
    uint8 cbvPos = (uint8)chCfgPtr->PduCbvPosition;
    uint8 cbvDta = chRTPtr->rxPduData[cbvPos];

    if (0u == (cbvDta & CANNM_CBV_BIT_CSR_MASK))
    {
        /* @req SWS_CanNm_00348 */
        /* First reception csr=0 ,shall notify upper layer */
        if ((NM_MODE_NETWORK == chRTPtr->cannmMode) && (CANNM_CSR_IND_INDICATED == chRTPtr->coordReadyToSleepInd))
        {
            chRTPtr->coordReadyToSleepInd = CANNM_CSR_IND_CANCELLED;
            /* notify upper layer */
            Nm_CoordReadyToSleepCancellation(CanNm_GetComMNetworkHandle(chIndex));
        }
    }
    else
    {
        /* @req SWS_CanNm_00341 */
        /* First reception csr=1,shall notify upper layer */
        if (((NM_MODE_NETWORK == chRTPtr->cannmMode) && (CANNM_CSR_IND_INIT == chRTPtr->coordReadyToSleepInd))
            || (CANNM_CSR_IND_CANCELLED == chRTPtr->coordReadyToSleepInd))
        {
            chRTPtr->coordReadyToSleepInd = CANNM_CSR_IND_INDICATED;
            /* notify upper layer */
            Nm_CoordReadyToSleepIndication(CanNm_GetComMNetworkHandle(chIndex));
        }
    }
}
#endif /* STD_ON == CANNM_COORDINATOR_SYNC_SUPPORT */

/******************************************************************************/
/*
 * Brief               Processes when enter Bus-Sleep Mode from other state
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_EnterPrepareBusSleepModeHandle(uint8 chIndex)
{
    P2CONST(CanNm_ChannelConfigType, AUTOMATIC, CANNM_APPL_CONST)
    chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);

    /* @req SWS_CanNm_00109 */
    /* NM-timeout timer expires,shall entry the Prepare Bus-sleep mode*/
    CanNm_StateChange(chIndex, NM_STATE_PREPARE_BUS_SLEEP);
    chRTPtr->cannmMode = NM_MODE_PREPARE_BUS_SLEEP;

    /* @req SWS_CanNm_00114 @req SWS_CanNm_00093 */
    Nm_PrepareBusSleepMode(CanNm_GetComMNetworkHandle(chIndex));

    /* @req SWS_CanNm_00115 */
    /*
     * If CanNmStayInPbsEnabled is disabled CanNm shall stay in the
     * Prepare Bus-Sleep Mode for a configurable amount of time
     * determined by the CanNmWaitBusSleepTime.
     */
    if ((boolean)FALSE == chCfgPtr->StayInPbsEnabled)
    {
        chRTPtr->stateTimer = chCfgPtr->WaitBusSleepTime / CanNm_CfgPtr->MainFunctionPeriod;
    }

#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
    /* @req SWS_CanNm_00367 */
    /* Clear activeWakeupbit in CBV */
    if ((boolean)TRUE == chCfgPtr->ActiveWakeupBitEnabled)
    {
        CanNm_ClrTxPduCbvBit(chIndex, CANNM_CBV_BIT_AW_MASK);
    }
#endif /* STD_OFF == CANNM_PASSIVE_MODE_ENABLED */
}

/******************************************************************************/
/*
 * Brief               Memory copy function used in CanNm implement
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      destPtr, Pointer to the destination array where the
                                content is to be copied.
 *                     srcPtr, Pointer to the source of data to be copied.
 *                     len, Number of bytes to be copied.
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE)
    CanNm_MemCpy(uint8* destPtr, P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA) srcPtr, uint16 len)
{
    while (len > 0u)
    {
        *destPtr = *srcPtr;
        destPtr++;
        srcPtr++;
        len--;
    }
}
#if (STD_OFF == CANNM_PASSIVE_MODE_ENABLED)
/******************************************************************************/
/*
 * Brief               inner txconf handle,call CanNm_TxConfirmation or transmit
 *                      ok
 * Sync/Async          Synchronous
 * Reentrancy          Reentrant for different channel.
 * Param-Name[in]      chIndex, Channel index in CanNm
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 */
/******************************************************************************/
static FUNC(void, CANNM_CODE) CanNm_InnerTxConfHandle(uint8 chIndex)
{
    const CanNm_ChannelConfigType* chCfgPtr = &CanNm_GetChannelConfig(chIndex);
    CanNm_InnerChannelType* chRTPtr = &CanNm_GetChannelRTData(chIndex);
    SchM_Enter_CanNm_Network(chIndex);
    /* @req SWS_CanNm_00099 */
    /* Nm pdu transmit success,restart the nm-timeout timer */
    if (NM_MODE_NETWORK == chRTPtr->cannmMode)
    {
        chRTPtr->nmTimeoutTimer = chCfgPtr->TimeoutTime / CanNm_CfgPtr->MainFunctionPeriod;
    }

    /* @req SWS_CanNm_00065 */
    chRTPtr->msgTimeoutTimer = 0u;
    chRTPtr->msgToutFlg = FALSE;
    SchM_Exit_CanNm_Network(chIndex);

#if (STD_ON == CANNM_COM_USERDATA_SUPPORT)
#if (0u < CANNM_USER_DATA_TX_PDU_MAX)
    if (NULL_PTR != chCfgPtr->UserDataTxPdu)
    {
        /* @req SWS_CanNm_00329 */
        /* Call PduR_CanNmTxConfirmation */
        PduR_CanNmTxConfirmation(chCfgPtr->UserDataTxPdu->UpperLayerPduId);
    }
#endif /*0 < CANNM_USER_DATA_TX_PDU_MAX */
#endif /* STD_ON == CANNM_COM_USERDATA_SUPPORT */
}
#endif /* (STD_OFF == CANNM_PASSIVE_MODE_ENABLED) */
#define CANNM_STOP_SEC_CODE
#include "CanNm_MemMap.h"
