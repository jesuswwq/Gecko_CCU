/*******************************************************************************
**                                                                            **
** Copyright(C)iSOFT (2022)                                                   **
**                                                                            **
** All rights reserved.                                                       **
**                                                                            **
** This document contains proprietary information belonging to iSOFT.         **
** Passing on and copying of this document,and communication                  **
** of its contents is not permitted without prior written authorization.      **
**                                                                            **
********************************************************************************
**                                                                            **
**  FILENAME    : WdgM.c                                                      **
**                                                                            **
**  Created on  :                                                             **
**  Author      : haibin.shao                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION :                                                             **
**                                                                            **
**  SPECIFICATION(S):   AUTOSAR classic Platform R19-11                       **
**                                                                            **
*******************************************************************************/

/*======================[R E V I S I O N   H I S T O R Y]=====================*/
/*  <VERSION>    <DATE>    <AUTHOR>   <REVISION LOG>
 *  V1.0.0     20180116     xinyu.J   Initial version
 *  V1.0.1     20180713     Xinyu.J   1. Modify the type definition base on the Req356/357/358
 *                                    2. Delete the function of checking SE deactivate or activate,
 *                                    which is realized by the ORIENTAIS.
 *  V1.0.2     20190703     Xinyu.J   Add the Function WdgM_GetSupervisedEntityTabIndex
 *  V1.0.3     20190717     Xinyu.J   Update the note and code after CodeReview
 *  V1.0.4     20221222     peng.wu   Modify the head and version info
 *  V1.0.5     20230424     peng.wu   Fix the bugs during logic supervision
 *  V1.0.6     20230817     peng.wu   1.Fix CPT-6093 CPT-6205;
 *  V1.0.7     20231122     Jerry.Liang   Optimize code performance
 *  V1.0.7     20231120     haibin.shao Update the SchM for WdgM's interaction with ShutDownOS
 */
/*============================================================================*/
/**
  \page ISOFT_MISRA_Exceptions  MISRA-C:2012 Compliance Exceptions
    ModeName:BswM<br>
  RuleSorce:puhua-rule.rcf 2.3.1

    \li PRQA S 0791 MISRA Rule 5.4 .<br>
    Reason:According to the segment name definition rules of the autosar specification, segment names may be
            very long and only a few characters may differ between segment names.

    \li PRQA S 0303 MISRA Rule 11.4 .<br>
    Reason:Converts between pointers to volatile objects and integer types for address assignment.

    \li PRQA S 2987,2983 MISRA Rule 2.2 .<br>
    Reason:Configuration file design implementation needs.

    \li PRQA S 2877 MISRA Dir 4.1 .<br>
    Reason:Configuration file design implementation needs.

    \li PRQA S 0779 MISRA Rule 1.3,Rule 5.2 .<br>
    Reason:The name of the variable is dynamically generated,
    consisting of some fixed characters and dynamic characters,
    resulting in the same characterst.

    \li PRQA S 0562 MISRA Rule 1.1 .<br>
    Reason:Right operand of assignment points to a more heavily qualified type..

 */

/*=======[I N C L U D E S]====================================================*/
#include "WdgIf.h"
#include "WdgM.h"
#include "BswM_Cfg.h"
#if (BSWM_WDGM_ENABLED == STD_ON)
#if (BSWM_MAX_NUM_PARTITION > 1)
#include "BswM_WdgM.h"
#endif
#endif
#include <SchM_WdgM.h>
#if (STD_ON == WDGM_IMMEDIATE_RESET)
#include "Os.h"
#endif /*STD_ON == WDGM_IMMEDIATE_RESET*/
#if (STD_ON == WDGM_DEV_ERROR_DETECT)
#include "Det.h"
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
#if ((STD_ON == WDGM_E_SET_MODE_ENABLE) || (STD_ON == WDGM_E_SUPERVISION_ENABLE))
#include "Dem.h"
#endif /*STD_ON == WDGM_E_SET_MODE_ENABLE or STD_ON == WDGM_E_SUPERVISION_ENABLE */
#if (WDGM_DEADLINE_SUP_NUM > 0)
#include "FreeRTimer.h"
#endif /*WDGM_DEADLINE_SUP_NUM lager than 0*/

/*******************************************************************/

#define WDGM_C_SW_MAJOR_VERSION 1u /*Major Version*/
#define WDGM_C_SW_MINOR_VERSION 0u /*Minor Version*/
#define WDGM_C_SW_PATCH_VERSION 7u /*Patch Version*/
#define WDGM_C_AR_MAJOR_VERSION 4u /*Autosar Major Version*/
#define WDGM_C_AR_MINOR_VERSION 5u /*Autosar Minor Version*/
#define WDGM_C_AR_PATCH_VERSION 0u /*Autosar Patch Version*/

/*=======[V E R S I O N  C H E C K]===========================================*/
/* DD_2_259:(1)*/
#if (WDGM_C_AR_MAJOR_VERSION != WDGM_H_AR_MAJOR_VERSION)
#error "WdgM.c : Mismatch in Specification Major Version"
#endif /*WDGM_C_AR_MAJOR_VERSION != WDGM_H_AR_MAJOR_VERSION*/
#if (WDGM_C_AR_MINOR_VERSION != WDGM_H_AR_MINOR_VERSION)
#error "WdgM.c : Mismatch in Specification Minor Version"
#endif /*WDGM_C_AR_MINOR_VERSION != WDGM_H_AR_MINOR_VERSION*/
#if (WDGM_C_AR_PATCH_VERSION != WDGM_H_AR_PATCH_VERSION)
#error "WdgM.c : Mismatch in Specification Patch Version"
#endif /*WDGM_C_AR_PATCH_VERSION != WDGM_H_AR_PATCH_VERSION*/
#if (WDGM_C_SW_MAJOR_VERSION != WDGM_H_SW_MAJOR_VERSION)
#error "WdgM.c : Mismatch in Specification Major Version"
#endif /*WDGM_C_SW_MAJOR_VERSION != WDGM_H_SW_MAJOR_VERSION*/
#if (WDGM_C_SW_MINOR_VERSION != WDGM_H_SW_MINOR_VERSION)
#error "WdgM.c : Mismatch in Specification Minor Version"
#endif /*WDGM_C_SW_MINOR_VERSION != WDGM_H_SW_MINOR_VERSION*/

#define WDGM_TIME_RESOLUTION       1000UL /*DD_2_211*/
#define WDGM_NO_OS_APPLICAITON_REF 0xFFFF
#define WDGM_NO_CP_REACH           0xFFFF
#define WDGM_NO_SE_REACH           0

/***************************Static variable********************************************/

#define WDGM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "WdgM_MemMap.h"
#if (WDGM_SE_NUM > 0)
/*Save the status of the supervision entities*/
/*used by     WdgM_CheckpointReached
            WdgM_GetLocalStatus
            WdgM_ConfirmAliveSupResultEachSE
            WdgM_ConfirmDeadlineSupResultEachSE
            WdgM_ConfirmIntLogSupResultEachSE
            WdgM_InitAllTabStatus
            WdgM_InitSEStatus
            WdgM_ChangeSEStatus
            WdgM_SEDeactivateInternal
            WdgM_MainFunction
            WdgM_ConfirmExtLogSupResultEachSE
            WdgM_ConfirmSELoacalStatus
            WdgM_ConfirmGlobalStatus             */

static WdgM_SEInfoType WdgMSEInfoRelated[WDGM_SE_NUM]; /*DD_2_034, DD_2_205*/
#endif                                                 /*WDGM_SE_NUM > 0*/

#if (WDGM_ALIVE_NUM > 0)
/*Save the status of the alive supervision*/
/*used by     WdgM_UpdateAICounter
            WdgM_ConfirmAliveSupResultEachSE
            WdgM_ConfirmAliveSupResult
            WdgM_InitAllTabStatus
            WdgM_ClearNoUseAliveDeadlineStatus
            WdgM_SEDeactivateInternal            */
static WdgM_AliveSupInfoType WdgM_AliveSupInfoTab[WDGM_ALIVE_NUM]; /*DD_2_002, DD_2_207*/
#endif                                                             /*WDGM_ALIVE_NUM > 0*/

#if (WDGM_DEADLINE_SUP_NUM > 0)
/*Save the status of the deadline supervision*/
/*used by     WdgM_UpdateDeadlineSup
            WdgM_UpdateDeadlineSupResult
            WdgM_ConfirmDeadlineSupResultEachSE
            WdgM_InitAllTabStatus
            WdgM_ClearNoUseAliveDeadlineStatus
            WdgM_SEDeactivateInternal    */

/*DD_2_020, DD_2_028*/
static WdgM_DeadlineSupInfoType WdgM_DeadlineSupInfoTab[WDGM_DEADLINE_SUP_NUM];
#endif /*WDGM_DEADLINE_SUP_NUM > 0*/

#if (WDGM_INTLOG_SUP_NUM > 0)
/*Save the status of the internal logical supervision*/
/*used by     WdgM_UpdateIntLogSup
            WdgM_ConfirmIntLogSupResultEachSE
            WdgM_InitAllTabStatus
            WdgM_SEDeactivateInternal            */
/*DD_2_021, DD_2_023, DD_2_029*/
static WdgM_IntLogSupInfoType WdgM_IntLogSupInfoTab[WDGM_INTLOG_SUP_NUM];
#endif /*WDGM_INTLOG_SUP_NUM > 0*/

#if (WDGM_EXTLOG_SUP_NUM > 0)
/*Save the status of the external logical supervision*/
/*used by     WdgM_UpdateExtLogSup
            WdgM_ClearExtlogStatus
            WdgM_InitAllTabStatus
            WdgM_ConfirmExtLogSupResultEachSE */
/*DD_2_021, DD_2_023, DD_2_026*/
static WdgM_ExtLogSupInfoType WdgMExtLogSupInfoRelated[WDGM_EXTLOG_SUP_NUM];
#endif /*WDGM_EXTLOG_SUP_NUM > 0*/
#define WDGM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "WdgM_MemMap.h"
/***********************************************************************/

/***********************************************************************/
#define WDGM_START_SEC_VAR_POWER_ON_INIT_8 /* PRQA S 0791 */ /* MISAR Rule-5.4 */
#include "WdgM_MemMap.h"
#if (WDGM_SE_NUM > 0)
/*The flag for WdgM De-initialization.*/
/* used by     WdgM_Init
            WdgM_DeInit
            WdgM_SetMode          */
static Std_ReturnType WdgMDeInitFlag = E_NOT_OK;
#endif                                                      /*WDGM_SE_NUM > 0*/
#define WDGM_STOP_SEC_VAR_POWER_ON_INIT_8 /* PRQA S 0791 */ /* MISAR Rule-5.4 */
#include "WdgM_MemMap.h"

#define WDGM_START_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "WdgM_MemMap.h"

/*Point to the WdgM_ModeCfgType from configuration*/
static const WdgM_ModeCfgType* CurModeCfg = NULL_PTR;
/*Point to the WdgM_ConfigType from configuration*/
static const WdgM_ConfigType* WdgMConfig = NULL_PTR;

/*Save the status of the WdgM Mode*/
/*used by     WdgM_CheckpointReached
            WdgM_ConfirmGlobalStatus
            WdgM_DeInit
            WdgM_GetGlobalStatus
            WdgM_GetLocalStatus
            WdgM_GetMode
            WdgM_Init
            WdgM_MainFunction
            WdgM_PerformReset
            WdgM_SetMode          */
static WdgM_ModeInfoType WdgMModeInfo = {WDGM_INIT_NOT, 0, 0}; /*DD_2_204*/
/*Save the status of the WdgM Global information*/
/*used by     WdgM_Init
            WdgM_DeInit
            WdgM_SetMode
            WdgM_GetGlobalStatus
            WdgM_PerformReset
            WdgM_MainFunction
            WdgM_ConfirmSELoacalStatus
            WdgM_ConfirmGlobalStatus
            WdgM_SetTrigger                        */
/*DD_2_035, DD_2_036, DD_2_210*/
static WdgM_GlobalInfoType WdgMGlobalInfo = {E_NOT_OK, WDGM_GLOBAL_STATUS_DEACTIVATED};
#define WDGM_STOP_SEC_VAR_POWER_ON_INIT_UNSPECIFIED
#include "WdgM_MemMap.h"
/***********************************************************************/

/***************************Internal  API********************************************/
#define WDGM_START_SEC_CODE
#include "WdgM_MemMap.h"
#if (WDGM_SE_NUM > 0)
static FUNC(void, WDGM_CODE) WdgM_InitSEStatus(const WdgM_ModeCfgType* CerModeCfgPtr);
static FUNC(void, WDGM_CODE)
    WdgM_ChangeSEStatus(const WdgM_ModeCfgType* Old_ModeCfg, const WdgM_ModeCfgType* New_ModeCfg);
static FUNC(void, WDGM_CODE)
    WdgM_SEDeactivateInternal(const WdgM_ModeCfgType* CerModeCfg, uint16 SE_Index, uint16 SEStatusTabIndex);
static FUNC(void, WDGM_CODE) WdgM_ConfirmSELoacalStatus(const WdgM_SECfgType* CerSEInfo);
static FUNC(void, WDGM_CODE) WdgM_DeinitSEStatus(const WdgM_ModeCfgType* CerModeCfgPtr);
static FUNC(void, WDGM_CODE) WdgM_ConfirmGlobalStatus(void);
static FUNC(Std_ReturnType, WDGM_CODE)
    WdgM_GetModeSEIndex(WdgM_SupervisedEntityIdType SEID, uint16* ModeSEIndex, const WdgM_ModeCfgType* CerModeCfgPtr);
static FUNC(Std_ReturnType, WDGM_CODE)
    WdgM_GetSECheckpointIndex(WdgM_CheckpointIdType CPID, const WdgM_SECfgType* CertSECfg, uint16* CPTabIndex);
static FUNC(void, WDGM_CODE) WdgM_InitAllTabStatus(void);
static FUNC(void, WDGM_CODE) WdgM_StopStatusErrorHanding(void);
static FUNC(void, WDGM_CODE) WdgM_RestartOSApplication(const WdgM_SECfgType* CerSEInfo);
static FUNC(void, WDGM_CODE) WdgM_SetTrigger(void);
static FUNC(uint16, WDGM_CODE) WdgM_GetSupervisedEntityTabIndex(WdgM_SupervisedEntityIdType CerSEID);
#if (STD_ON == WDGM_DEV_ERROR_DETECT)
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_ModeExistenceConfirmation(WdgM_ModeType ModeID);
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_InitModeConfirmation(const WdgM_ConfigType* ConfigPtr);
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
#if (STD_OFF == WDGM_OFF_MODE_EABLED)
#if (STD_ON == WDGM_DEV_ERROR_DETECT)
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_OffModeConfirmation(const WdgM_ConfigType* ConfigPtr);
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_OffModeConfirmationForRequestMode(WdgM_ModeType ModeID);
#endif
#endif /*WDGM_SE_NUM > 0*/

#if (WDGM_ALIVE_NUM > 0)
static FUNC(void, WDGM_CODE) WdgM_UpdateAICounter(uint16 CPIndex, const WdgM_SECfgType* CertSECfg);
static FUNC(void, WDGM_CODE) WdgM_ConfirmAliveSupResultEachSE(const WdgM_SECfgType* CerSEInfo);
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_ConfirmAliveSupResult(uint16 SupIndex, uint16 RefCycle);
#endif /*WDGM_ALIVE_NUM > 0*/

#if (WDGM_DEADLINE_SUP_NUM > 0)
static FUNC(void, WDGM_CODE) WdgM_UpdateDeadlineSup(uint16 CPIndex, const WdgM_SECfgType* CertSECfg);
static FUNC(void, WDGM_CODE)
    WdgM_UpdateDeadlineSupResult(WdgM_DeadlineTimeType TimeGap, const WdgM_DeadlineSupCfgType* DeadlineSupCfg);
static FUNC(void, WDGM_CODE) WdgM_PerformDeadlineTimeoutDetection(const WdgM_SECfgType* CerSEInfo);
static FUNC(void, WDGM_CODE) WdgM_ConfirmDeadlineSupResultEachSE(const WdgM_SECfgType* CerSEInfo);
#endif /*WDGM_DEADLINE_SUP_NUM > 0*/

#if (WDGM_INTLOG_SUP_NUM > 0)
static FUNC(void, WDGM_CODE) WdgM_UpdateIntLogSup(uint16 CPIndex, const WdgM_SECfgType* CertSECfg);
static FUNC(void, WDGM_CODE) WdgM_ConfirmIntLogSupResultEachSE(const WdgM_SECfgType* CerSEInfo);
#endif /*WDGM_INTLOG_SUP_NUM > 0*/

#if (WDGM_EXTLOG_SUP_NUM > 0)
static FUNC(void, WDGM_CODE)
    WdgM_UpdateExtLogSup(uint16 CPIndex, const WdgM_SECfgType* CertSECfg, const WdgM_ModeCfgType* CerModeCfg);
static FUNC(void, WDGM_CODE) WdgM_ConfirmExtLogSupResultEachSE(const WdgM_ModeCfgType* CerModeCfgPtr);
static FUNC(void, WDGM_CODE) WdgM_ClearExtlogStatus(const WdgM_ModeCfgType* Old_ModeCfg);
#endif /*WDGM_EXTLOG_SUP_NUM > 0*/

#if ((WDGM_ALIVE_NUM > 0) || (WDGM_DEADLINE_SUP_NUM > 0))
static FUNC(void, WDGM_CODE)
    WdgM_ClearNoUseAliveDeadlineStatus(const WdgM_SECfgType* OldSE, const WdgM_SECfgType* NewSE);
#endif /*WDGM_ALIVE_NUM > 0 || WDGM_DEADLINE_SUP_NUM > 0*/

static FUNC(uint8, WDGM_CODE) WdgM_GetWordBitState(uint16 WordNum, uint8 GetBit);

/***********************************************************************/
#define WDGM_STOP_SEC_CODE
#include "WdgM_MemMap.h"

#define WDGM_START_SEC_CODE
#include "WdgM_MemMap.h"
/***************************************************************/
/*
 * Brief               Initializes the Watchdog Manager.
 * ServiceId           0x00
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      WdgMConfigPtr
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           Up layer
 * REQ ID              DD_2_061,DD_2_088,DD_2_089,DD_2_144~DD_2_149
 */
/**************************************************************/
FUNC(void, WDGM_CODE) WdgM_Init(const WdgM_ConfigType* WdgMConfigPtr) /* PRQA S 1532*/ /* MISRA Rule 8.7 */
{
#if (WDGM_SE_NUM > 0)
    uint8 dev_index; /*Rule-2.2     This initialization is redundant.*/
    Std_ReturnType retVal = E_OK;
    uint8 ModeTriggerCnt;
    WdgIf_ModeType WatchdogMode;
#if (STD_ON == WDGM_DEV_ERROR_DETECT)
    if (NULL_PTR == WdgMConfigPtr)
    {
        /*req WDGM-FUNR-091[WDGM048]*/
        (void)Det_ReportError(WDGM_MODULE_ID, WDGM_INSTANCE_ID, WDGM_INIT_ID, WDGM_E_INV_POINTER);
    }
    else if ((Std_ReturnType)E_NOT_OK == WdgM_InitModeConfirmation(WdgMConfigPtr))
    {
        (void)Det_ReportError(WDGM_MODULE_ID, WDGM_INSTANCE_ID, WDGM_INIT_ID, WDGM_E_PARAM_CONFIG); /*req WdgM 010*/
    }
#if (STD_OFF == WDGM_OFF_MODE_EABLED)
    else if ((Std_ReturnType)E_NOT_OK == WdgM_OffModeConfirmation(WdgMConfigPtr))
    {
        (void)Det_ReportError(
            WDGM_MODULE_ID,
            WDGM_INSTANCE_ID,
            WDGM_INIT_ID,
            WDGM_E_DISABLE_NOT_ALLOWED); /*req WdgM 030*/
    }
#endif /*STD_OFF == WDGM_OFF_MODE_EABLED*/
    else
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
    {
        WdgMConfig = WdgMConfigPtr;

        *(volatile uint16*)WDGM_FIRST_EXPIRED_SEID = 0; /* PRQA S 0303*/         /* MISRA Rule 11.4 */
        *(volatile uint16*)WDGM_FIRST_EXPIRED_INVERSE_SEID = 0; /* PRQA S 0303*/ /* MISRA Rule 11.4 */

        WdgMGlobalInfo.WdgM_FirstExpiredSEIDSaved = E_NOT_OK;

        WdgM_InitAllTabStatus();

        CurModeCfg = (const WdgM_ModeCfgType*)&WdgMConfigPtr->WdgMMode[WdgMConfigPtr->WdgMInitialModeId];

        ModeTriggerCnt = WdgMConfig->WdgMMode[CurModeCfg->WdgMModeID].ModeTriggerCnt;
        WatchdogMode = CurModeCfg->WdgMTriggerRelated->WdgMWatchdogMode;

        for (dev_index = 0U; dev_index < ModeTriggerCnt; dev_index++)
        {
            retVal = WdgIf_SetMode(dev_index, WatchdogMode);
            if ((Std_ReturnType)E_NOT_OK == retVal)
            {
                break;
            }
        }
        if ((Std_ReturnType)E_NOT_OK == retVal)
        {
            WdgM_DeinitSEStatus(CurModeCfg);

            WdgMGlobalInfo.WdgMGlobalResult = WDGM_GLOBAL_STATUS_STOPPED;

            WdgMModeInfo.WdgMModeInitStatus = WDGM_INIT_NOT;

            WdgMDeInitFlag = (Std_ReturnType)E_OK;
        }
        else
        {
            WdgM_InitSEStatus(CurModeCfg);

            WdgMGlobalInfo.WdgMGlobalResult = WDGM_GLOBAL_STATUS_OK;

            WdgMModeInfo.WdgMModeCurrentID = CurModeCfg->WdgMModeID;

            WdgMModeInfo.WdgMModeInitStatus = WDGM_INIT_OK;

            WdgMModeInfo.WdgMExpiredSupTolCounter = 0u;

            WdgMDeInitFlag = (Std_ReturnType)E_NOT_OK;
        }
    }
#endif /*WDGM_SE_NUM > 0*/
}

#if (STD_ON == WDGM_OFF_MODE_EABLED)
/*************************************************************************/
/*
 * Brief               De-initializes the Watchdog Manager.
 * ServiceId           0x01
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           Up layer
 * REQ ID              DD_2_062,DD_2_150,DD_2_151
 */
/*************************************************************************/
FUNC(void, WDGM_CODE) WdgM_DeInit(void)
{
#if (WDGM_SE_NUM > 0)
#if (STD_ON == WDGM_DEV_ERROR_DETECT)
    if (WDGM_INIT_NOT == WdgMModeInfo.WdgMModeInitStatus)
    {
        (void)Det_ReportError(WDGM_MODULE_ID, WDGM_INSTANCE_ID, WDGM_DEINIT_ID, WDGM_E_NO_INIT); /*req WdgM 288*/
    }
    else
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
    {
        WdgMDeInitFlag = E_OK;
        if ((Std_ReturnType)E_OK == WdgM_SetMode((WdgM_ModeType)WDGM_SLEEP_MODE_ID))
        {
            /*req WdgM 286 : Fig 4-14*/
            WdgMGlobalInfo.WdgMGlobalResult = WDGM_GLOBAL_STATUS_DEACTIVATED;
            WdgMModeInfo.WdgMModeInitStatus = WDGM_INIT_NOT;
        }
        else
        {
            /*MISRA-C*/
        }
    }
#endif /*WDGM_SE_NUM > 0*/
}
#endif /*STD_ON == WDGM_OFF_MODE_EABLED*/

#if (STD_ON == WDGM_VERSION_INFO_API)
/*DD_2_250,DD_2_128,DD_2_129*/
FUNC(void, WDGM_CODE) WdgM_GetVersionInfo(Std_VersionInfoType* VersionInfo)
{
#if (STD_ON == WDGM_DEV_ERROR_DETECT)
    if (NULL_PTR == VersionInfo)
    {
        /*req WDGM-FUNR-091[WDGM048]*/
        (void)Det_ReportError(WDGM_MODULE_ID, WDGM_INSTANCE_ID, WDGM_GET_VERSION_INFO_ID, WDGM_E_INV_POINTER);
    }
    else
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
    {
        /*req WDGM-APIR-008[WDGM110]*/
        VersionInfo->vendorID = WDGM_VENDOR_ID;
        VersionInfo->moduleID = WDGM_MODULE_ID;
        VersionInfo->instanceID = WDGM_INSTANCE_ID;
        VersionInfo->sw_major_version = WDGM_C_SW_MAJOR_VERSION;
        VersionInfo->sw_minor_version = WDGM_C_SW_MINOR_VERSION;
        VersionInfo->sw_patch_version = WDGM_C_SW_PATCH_VERSION;
    }
}
#endif /*STD_ON == WDGM_VERSION_INFO_API*/

/*************************************************************************/
/*
 * Brief               Sets the current mode of Watchdog Manager.
 * ServiceId           0x03
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Mode: One of the configured Watchdog Manager modes.
 * Param-Name[in/out]  None
 * Return              E_OK: Successfully changed to the new mode
 *                     E_NOT_OK: Changing to the new mode failed
 * CallByAPI           Up layer
 * REQ ID              DD_2_046,DD_2_074,DD_2_077,DD_2_078,DD_2_121,DD_2_122,DD_2_123
 * REQ ID              DD_2_124,DD_2_125,DD_2_126
 */
/*************************************************************************/
FUNC(Std_ReturnType, WDGM_CODE) WdgM_SetMode(WdgM_ModeType Mode) /* PRQA S 1505*/ /* MISRA Rule 8.7 */
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    WdgM_ModeCfgType* modeCfg;
    uint8 modeTriggerCnt;
    WdgM_TriggerType* TriggerRelated;
#if (WDGM_SE_NUM > 0)
    Std_ReturnType l_Ret = E_NOT_OK;
    uint8 triggerIndex;
    /*device index*/
    WdgM_WatchdogDeviceType Deviceid;
    /*wdg mode*/
    WdgIf_ModeType WdgIf_Mode;

#if (STD_ON == WDGM_DEV_ERROR_DETECT)
    if (WDGM_INIT_NOT == WdgMModeInfo.WdgMModeInitStatus)
    {
        (void)Det_ReportError(WDGM_MODULE_ID, WDGM_INSTANCE_ID, WDGM_SET_MODE_ID, WDGM_E_NO_INIT); /*req WdgM 021*/
        l_ReturnValue = E_NOT_OK;
    }
    else if ((Std_ReturnType)E_NOT_OK == WdgM_ModeExistenceConfirmation(Mode))
    {
        (void)Det_ReportError(WDGM_MODULE_ID, WDGM_INSTANCE_ID, WDGM_SET_MODE_ID, WDGM_E_PARAM_MODE); /*req WdgM 020*/
        l_ReturnValue = E_NOT_OK;
    }
#if (STD_OFF == WDGM_OFF_MODE_EABLED)
    else if ((Std_ReturnType)E_NOT_OK == WdgM_OffModeConfirmationForRequestMode(Mode))
    {
        (void)Det_ReportError(
            WDGM_MODULE_ID,
            WDGM_INSTANCE_ID,
            WDGM_SET_MODE_ID,
            WDGM_E_DISABLE_NOT_ALLOWED); /*req WdgM 031*/
        l_ReturnValue = E_NOT_OK;
    }
#endif /*STD_OFF == WDGM_OFF_MODE_EABLED*/
#else  /*STD_OFF == WDGM_DEV_ERROR_DETECT*/
#if (STD_OFF == WDGM_OFF_MODE_EABLED)
    if ((Std_ReturnType)E_NOT_OK == WdgM_OffModeConfirmationForRequestMode(Mode))
    {
        l_ReturnValue = E_NOT_OK;
    }
#endif /*STD_OFF == WDGM_OFF_MODE_EABLED*/
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/

#if ((STD_ON == WDGM_OFF_MODE_EABLED) && (STD_OFF == WDGM_DEV_ERROR_DETECT))
    if (Mode == WdgMModeInfo.WdgMModeCurrentID)
#else
    else if (Mode == WdgMModeInfo.WdgMModeCurrentID)
#endif /*STD_ON == WDGM_OFF_MODE_EABLED && STD_OFF == WDGM_DEV_ERROR_DETECT*/
    {
        l_ReturnValue = E_OK;
    }
    else
    {
        if (((Std_ReturnType)E_OK == WdgMDeInitFlag)
            || ((WDGM_SLEEP_MODE_ID != Mode)
                && ((WDGM_GLOBAL_STATUS_OK == WdgMGlobalInfo.WdgMGlobalResult)
                    || (WDGM_GLOBAL_STATUS_FAILED == WdgMGlobalInfo.WdgMGlobalResult))))
        {

            if ((Std_ReturnType)E_OK == WdgMDeInitFlag)
            {
                WdgMDeInitFlag = E_NOT_OK; /* PRQA S 0562 */ /* MISRA Rule 1.1 */
            }

            modeCfg = (WdgM_ModeCfgType*)&WdgMConfig->WdgMMode[Mode]; /* PRQA S 0562 */ /* MISRA Rule 1.1 */
            modeTriggerCnt = modeCfg->ModeTriggerCnt;
            TriggerRelated = (WdgM_TriggerType*)modeCfg->WdgMTriggerRelated; /* PRQA S 0562 */ /* MISRA Rule 1.1 */

            for (triggerIndex = 0; triggerIndex < modeTriggerCnt; triggerIndex++)
            {
                Deviceid = TriggerRelated[triggerIndex].WdgM_WatchdogDevice;
                WdgIf_Mode = TriggerRelated[triggerIndex].WdgMWatchdogMode;
                l_Ret = WdgIf_SetMode(Deviceid, WdgIf_Mode); /*req WdgM 186*/
                if ((Std_ReturnType)E_NOT_OK == l_Ret)
                {
#if (STD_ON == WDGM_E_SET_MODE_ENABLE)
                    /*req WdgM 142*/
                    Dem_ReportErrorStatus(WDGM_E_SET_MODE, DEM_EVENT_STATUS_FAILED);
#endif /*STD_ON == WDGM_E_SET_MODE_ENABLE*/
                    /*req WdgM 139*/
                    WdgMGlobalInfo.WdgMGlobalResult = WDGM_GLOBAL_STATUS_STOPPED;
                    l_ReturnValue = E_NOT_OK;
                    break;
                }
            }
            if ((Std_ReturnType)E_OK == l_Ret)
            {
                WdgM_ChangeSEStatus(CurModeCfg, modeCfg);
                WdgMModeInfo.WdgMModeCurrentID = Mode;
                CurModeCfg = modeCfg;
                l_ReturnValue = E_OK;
            }
        }
        else
        {
            l_ReturnValue = E_NOT_OK; /*req WdgM 316*/
        }
    }
#endif /*WDGM_SE_NUM > 0*/
    return l_ReturnValue;
}

/*************************************************************************/
/*
 * Brief               Returns the current mode of the Watchdog Manager
 * ServiceId           0x0b
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Mode: One of the configured Watchdog Manager modes.
 * Param-Name[in/out]  None
 * Return              E_OK: Success
 *                     E_NOT_OK: failure
 * CallByAPI           Up layer
 * REQ ID              DD_2_080,DD_2_130,DD_2_131,DD_2_132
 */
/*************************************************************************/
FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetMode(WdgM_ModeType* Mode)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK; /* PRQA S 2981 */ /* MISAR Rule-2.2 */
#if (WDGM_SE_NUM > 0)
#if (STD_ON == WDGM_DEV_ERROR_DETECT)
    if (WDGM_INIT_NOT == WdgMModeInfo.WdgMModeInitStatus)
    {
        (void)Det_ReportError(WDGM_MODULE_ID, WDGM_INSTANCE_ID, WDGM_GET_MODE_ID, WDGM_E_NO_INIT); /*req WdgM 253*/
        l_ReturnValue = E_NOT_OK;
    }
    else if (NULL_PTR == Mode)
    {
        (void)Det_ReportError(WDGM_MODULE_ID, WDGM_INSTANCE_ID, WDGM_GET_MODE_ID, WDGM_E_INV_POINTER); /*req WdgM 254*/
        l_ReturnValue = E_NOT_OK;
    }
    else
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
    {
        *Mode = WdgMModeInfo.WdgMModeCurrentID;
        l_ReturnValue = E_OK;
    }
#endif /*WDGM_SE_NUM > 0*/
    return l_ReturnValue;
}

/*************************************************************************/
/*
 * Brief                Indicates to the Watchdog Manager that a Checkpoint
 *                      within a Supervised Entity has been reached
 * ServiceId            0x0e
 * Sync/Async           synchronous
 * Reentrancy           Reentrant
 * Param-Name[in]       SEID: Identifier of the Supervised Entity that reports a Checkpoint
 * Param-Name[in]       CheckpointID: Identifier of the Checkpoint within a Supervised Entity
 *                      that has been reached
 * Param-Name[in/out]   None
 * Return               E_OK: Successfully updated alive counter
 *                      E_NOT_OK: updated failed
 * CallByAPI            Up layer
 * REQ ID               DD_2_058,DD_2_113,DD_2_117,DD_2_118,DD_2_119
 */
/*************************************************************************/
FUNC(Std_ReturnType, WDGM_CODE)
WdgM_CheckpointReached(WdgM_SupervisedEntityIdType SEID, WdgM_CheckpointIdType CheckpointID)
{
    Std_ReturnType l_ReturnValue;
    /*Point to the WdgM_SECfgType from configuration*/
    const WdgM_SECfgType* CurSECfg;

#if (WDGM_SE_NUM > 0)
    uint16 SECPIndex = 0;
    uint16 WdgM_ModeSETabIndex = 0;
    uint16 SEStatusTabIndex;
    SEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(SEID);

#if (STD_ON == WDGM_DEV_ERROR_DETECT)
    /*req WdgM 319 282 realized by the ORIENTAIS*/
    if (WDGM_INIT_NOT == WdgMModeInfo.WdgMModeInitStatus)
    {
        (void)Det_ReportError(
            WDGM_MODULE_ID,
            WDGM_INSTANCE_ID,
            WDGM_CHECKPOINT_REACHED_ID,
            WDGM_E_NO_INIT); /*req WdgM 279*/
        l_ReturnValue = E_NOT_OK;
    }
    else if (WDGM_SE_NUM <= SEStatusTabIndex)
    {
        (void)Det_ReportError(
            WDGM_MODULE_ID,
            WDGM_INSTANCE_ID,
            WDGM_CHECKPOINT_REACHED_ID,
            WDGM_E_PARAM_SEID); /*req WdgM 278*/
        l_ReturnValue = E_NOT_OK;
    }
    else if ((Std_ReturnType)E_NOT_OK == WdgM_GetModeSEIndex(SEID, &WdgM_ModeSETabIndex, CurModeCfg))
    {
        (void)Det_ReportError(
            WDGM_MODULE_ID,
            WDGM_INSTANCE_ID,
            WDGM_CHECKPOINT_REACHED_ID,
            WDGM_E_SEDEACTIVATED); /*req WdgM 319*/
        l_ReturnValue = E_NOT_OK;
    }
    else if ((CheckpointID + (WdgM_CheckpointIdType)1) > WdgM_CheckpointQuantityInSE[SEStatusTabIndex])
    {
        (void)
            Det_ReportError(WDGM_MODULE_ID, WDGM_INSTANCE_ID, WDGM_CHECKPOINT_REACHED_ID, WDGM_E_CPID); /*req WdgM 284*/
        l_ReturnValue = E_NOT_OK;
    }
    else if (WDGM_LOCAL_STATUS_DEACTIVATED == WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus)
#else
    if (((Std_ReturnType)E_NOT_OK == WdgM_GetModeSEIndex(SEID, &WdgM_ModeSETabIndex, CurModeCfg))
        || (WDGM_LOCAL_STATUS_DEACTIVATED == WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus))
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
    {
        l_ReturnValue = E_NOT_OK;
    }
    else
    {
        CurSECfg = (const WdgM_SECfgType*)&CurModeCfg->WdgMSERelated[WdgM_ModeSETabIndex];
        /*The Checkpoint index in the SE*/
        l_ReturnValue = WdgM_GetSECheckpointIndex(CheckpointID, CurSECfg, &SECPIndex);
        if ((Std_ReturnType)E_OK == l_ReturnValue)
        {
#if (WDGM_ALIVE_NUM > 0)
            /*Confirm whether has AliveSup,then update AI Cnt*/
            WdgM_UpdateAICounter(SECPIndex, CurSECfg);
#endif /*WDGM_ALIVE_NUM > 0*/

            if ((WDGM_GLOBAL_STATUS_OK == WdgMGlobalInfo.WdgMGlobalResult)
                || (WDGM_GLOBAL_STATUS_FAILED == WdgMGlobalInfo.WdgMGlobalResult))
            {
#if (WDGM_EXTLOG_SUP_NUM > 0)
                WdgM_UpdateExtLogSup(SECPIndex, CurSECfg, CurModeCfg);
#endif /*WDGM_EXTLOG_SUP_NUM > 0*/

#if (WDGM_DEADLINE_SUP_NUM > 0)
                WdgM_UpdateDeadlineSup(SECPIndex, CurSECfg);
#endif /*WDGM_DEADLINE_SUP_NUM > 0*/

#if (WDGM_INTLOG_SUP_NUM > 0)
                WdgM_UpdateIntLogSup(SECPIndex, CurSECfg);
#endif /*WDGM_INTLOG_SUP_NUM > 0*/
            }
        }
        else
        {
            /*MISRAC*/
        }
    }
#endif /*WDGM_SE_NUM > 0*/
    return l_ReturnValue;
}

/*************************************************************************/
/*
 * Brief                Returns the supervision status of an individual Supervised Entity
 * ServiceId            0x0C
 * Sync/Async           synchronous
 * Reentrancy           Reentrant
 * Param-Name[in]       SEId: Identifier of the supervised entity
 *                      whose supervision status shall be returned.
 * Param-Name[out]      Status :Supervision status of the given supervised entity.
 * Param-Name[in/out]   None
 * Return               E_OK: Current supervision status successfully returned
 *                      E_NOT_OK: Returning current supervision status failed
 * CallByAPI            Up layer
 * REQ ID               DD_2_081,DD_2_137,DD_2_138,DD_2_139,DD_2_140
 */
/*************************************************************************/
Std_ReturnType WdgM_GetLocalStatus(WdgM_SupervisedEntityIdType SEID, WdgM_LocalStatusType* Status)
{

    Std_ReturnType l_ReturnValue;
#if (WDGM_SE_NUM > 0)
    uint16 SEStatusTabIndex;
    /*The SEID index in the Mode is the same as in the WdgMModeInfo*/
    uint16 l_ModeSETabIndex = 0;

    SEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(SEID);
#if (STD_ON == WDGM_DEV_ERROR_DETECT)

    if (WDGM_INIT_NOT == WdgMModeInfo.WdgMModeInitStatus)
    {
        (void)Det_ReportError(
            WDGM_MODULE_ID,
            WDGM_INSTANCE_ID,
            WDGM_GET_LOCAL_STATUS_ID,
            WDGM_E_NO_INIT); /*req WdgM 173*/
        l_ReturnValue = E_NOT_OK;
    }
    else if (WDGM_SE_NUM <= SEStatusTabIndex)
    {
        (void)Det_ReportError(
            WDGM_MODULE_ID,
            WDGM_INSTANCE_ID,
            WDGM_GET_LOCAL_STATUS_ID,
            WDGM_E_PARAM_SEID); /*req WdgM 172*/
        l_ReturnValue = E_NOT_OK;
    }
    else if (NULL_PTR == Status)
    {
        (void)Det_ReportError(
            WDGM_MODULE_ID,
            WDGM_INSTANCE_ID,
            WDGM_GET_LOCAL_STATUS_ID,
            WDGM_E_INV_POINTER); /*req WdgM 257*/
        l_ReturnValue = E_NOT_OK;
    }
    else if ((Std_ReturnType)E_OK == WdgM_GetModeSEIndex(SEID, &l_ModeSETabIndex, CurModeCfg))
#else  /*STD_OFF == WDGM_DEV_ERROR_DETECT*/
    if ((Std_ReturnType)E_OK == WdgM_GetModeSEIndex(SEID, &l_ModeSETabIndex, CurModeCfg))
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
    {
        *Status = WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus;
        l_ReturnValue = E_OK;
    }
    else
    {
        *Status = WDGM_LOCAL_STATUS_DEACTIVATED;
        l_ReturnValue = E_OK;
    }
#endif /*WDGM_SE_NUM > 0*/

    return l_ReturnValue;
}

/*************************************************************************/
/*
 * Brief               Returns the global supervision status of the Watchdog Manager
 * ServiceId           0x0d
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     Status :Global supervision status of the Watchdog Manager
 * Param-Name[in/out]  None
 * Return              E_OK: Current supervision status successfully returned
 *                     E_NOT_OK: Returning current supervision status failed
 * CallByAPI           Up layer
 * REQ ID              DD_2_082,DD_2_133,DD_2_134,DD_2_136
 */
/*************************************************************************/
Std_ReturnType WdgM_GetGlobalStatus(WdgM_GlobalStatusType* Status)
{
    Std_ReturnType l_ReturnValue;
#if (STD_ON == WDGM_DEV_ERROR_DETECT)
    if (WDGM_INIT_NOT == WdgMModeInfo.WdgMModeInitStatus)
    {
        (void)Det_ReportError(
            WDGM_MODULE_ID,
            WDGM_INSTANCE_ID,
            WDGM_GET_GLOBAL_STATUS_ID,
            WDGM_E_NO_INIT); /*req WdgM 176*/
        l_ReturnValue = E_NOT_OK;
    }
    else if (NULL_PTR == Status)
    {
        (void)Det_ReportError(
            WDGM_MODULE_ID,
            WDGM_INSTANCE_ID,
            WDGM_GET_GLOBAL_STATUS_ID,
            WDGM_E_INV_POINTER); /*req WdgM 334*/
        l_ReturnValue = E_NOT_OK;
    }
    else
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
    {
        *Status = WdgMGlobalInfo.WdgMGlobalResult;
        l_ReturnValue = E_OK;
    }
    return l_ReturnValue;
}

/*************************************************************************/
/*
 * Brief               Instructs the Watchdog Manager to cause a watchdog reset.
 * ServiceId           0x0F
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           Up layer
 * REQ ID              DD_2_254,DD_2_255,DD_2_256,DD_2_257
 */
/*************************************************************************/
FUNC(void, WDGM_CODE) WdgM_PerformReset(void)
{
    uint8 triggerIndex;
    uint8 modeTriggerCnt;
    WdgM_TriggerType* triggerRelated;
    WdgIf_ModeType watchdogMode;

#if (STD_ON == WDGM_DEV_ERROR_DETECT)
    if (WDGM_INIT_NOT == WdgMModeInfo.WdgMModeInitStatus)
    {
        (void)Det_ReportError(WDGM_MODULE_ID, WDGM_INSTANCE_ID, WDGM_PERFORM_RESET_ID, WDGM_E_NO_INIT); /*req WdgM 270*/
    }
    else
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
    {
        modeTriggerCnt = CurModeCfg->ModeTriggerCnt;
        triggerRelated = (WdgM_TriggerType*)CurModeCfg->WdgMTriggerRelated; /* PRQA S 0562 */ /* MISRA Rule 1.1 */
        /*req WdgM 223-1*/
        for (triggerIndex = 0; triggerIndex < modeTriggerCnt; triggerIndex++)
        {
            watchdogMode = triggerRelated[triggerIndex].WdgMWatchdogMode;
            if (WDGIF_OFF_MODE != watchdogMode)
            {
                /*req WdgM 232 : Trigger value is 0*/
                WdgIf_SetTriggerCondition(
                    triggerRelated[triggerIndex].WdgM_WatchdogDevice,
                    WDGM_TRIGGER_CONDITION_STOP);
            }
        }
        DisableAllInterrupts();
        while (1)
        {
            /*Nothing to do*/
            /*req WdgM 233 : Never update the trigger after WdgM_PerformReset*/
        }
    }
}

/*************************************************************************/
/*
 * Brief               Returns SEID that first reached the state WDGM_LOCAL_STATUS_EXPIRED
 * ServiceId           0x10
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     SEID : Identifier of the supervised entity
 *                     that first reached the state WDGM_LOCAL_STATUS_EXPIRED
 * Param-Name[in/out]  None
 * Return              E_OK: Success
 *                     E_NOT_OK: failure
 * CallByAPI           Up layer
 * REQ ID              DD_2_083,DD_2_141,DD_2_142,DD_2_143
 */
/*************************************************************************/
FUNC(Std_ReturnType, WDGM_CODE) WdgM_GetFirstExpiredSEID(WdgM_SupervisedEntityIdType* SEID)
{
    Std_ReturnType l_ReturnValue;
#if (WDGM_SE_NUM > 0)
    /* PRQA S 0303 ++*/ /* MISRA Rule 11.4 */
    uint16 FirstExpiredSEID = *(volatile uint16*)WDGM_FIRST_EXPIRED_SEID;
    uint16 FirstExpiredInverseSEID = *(volatile uint16*)WDGM_FIRST_EXPIRED_INVERSE_SEID;
    /* PRQA S 0303 --*/ /* MISRA Rule 11.4 */

#if (STD_ON == WDGM_DEV_ERROR_DETECT)
    if (NULL_PTR == SEID)
    {
        (void)Det_ReportError(
            WDGM_MODULE_ID,
            WDGM_INSTANCE_ID,
            WDGM_GET_FIRST_EXPIRED_SEID_ID,
            WDGM_E_INV_POINTER); /*req WdgM 347*/
        l_ReturnValue = E_NOT_OK;
    }
    else
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
    {
        /*req WdgM 349*/
        if ((uint16)0xFFFF == (FirstExpiredSEID + FirstExpiredInverseSEID))
        {
            *SEID = FirstExpiredSEID; /* PRQA S 4461  */ /* MISRA Rule 10.3 */
            l_ReturnValue = E_OK;
        }
        else
        {
            *(volatile uint16*)WDGM_FIRST_EXPIRED_SEID = 0; /* PRQA S 0303*/         /* MISRA Rule 11.4 */
            *(volatile uint16*)WDGM_FIRST_EXPIRED_INVERSE_SEID = 0; /* PRQA S 0303*/ /* MISRA Rule 11.4 */
            *SEID = 0;
            l_ReturnValue = E_NOT_OK;
        }
    }
#endif /*WDGM_SE_NUM > 0*/
    return l_ReturnValue;
}

#if (WDGM_ALIVE_NUM > 0)
/***************************************************************/
/*
 * Brief               Update the alive supervision counter
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CPIndex : the array index of the CP in the configuration of the certain SE
 *                     CertSECfg: the configuration of the certain SE
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_CheckpointReached
 * REQ ID              DD_2_114,DD_2_170
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_UpdateAICounter(uint16 CPIndex, const WdgM_SECfgType* CertSECfg)
{
    if ((uint8)STD_ON
        == WdgM_GetWordBitState(CertSECfg->WdgMCheckpointRelated[CPIndex].WdgMSupSupportGroup, (uint8)ALIVE_SUPPORT))
    {
        WdgM_AliveSupInfoTab[CertSECfg->WdgMCheckpointRelated[CPIndex].WdgM_AliveSupID].WdgMAliveIndicationCounter++;
    }
}

/***************************************************************/
/*
 * Brief               Confirm the results of alive supervision  in the SE.
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CerSEInfo: the configuration of the certain SE
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_MainFunction
 * REQ ID              DD_2_003, DD_2_004, DD_2_005, DD_2_006, DD_2_007,DD_2_104,DD_2_157
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_ConfirmAliveSupResultEachSE(const WdgM_SECfgType* CerSEInfo)
{
    uint16 Tab_Index;
    uint16 Index;
    uint16 AliveRefCycle;
    uint16 SEStatusTabIndex;
    sint32 AliveSupTempCnt;
    sint32 AliveSupTempResult;
    sint32 AliveSupTempConfigCnt;

    const uint16 seAliveCnt = CerSEInfo->SEAliveCnt;
    const WdgM_AliveSupCfgType* aliveSupCfg = CerSEInfo->WdgMAliveSupCfg;

    if ((uint16)0 < seAliveCnt)
    {
        /*update certain AliveSup result*/
        for (Index = 0; Index < seAliveCnt; Index++)
        {
            AliveRefCycle = aliveSupCfg[Index].WdgMSupRefCycle;
            Tab_Index = aliveSupCfg[Index].WdgMAliveSupID;
            /*req WdgM 098 : Reach to the RefCycle, determine the related Alive Sup result*/
            if ((Std_ReturnType)E_OK == WdgM_ConfirmAliveSupResult(Tab_Index, AliveRefCycle))
            {
                /*f(EAI,SRC)= SRC - EAI */
                AliveSupTempConfigCnt = (sint32)(aliveSupCfg[Index].WdgMSupRefCycle)
                                        - (sint32)(aliveSupCfg[Index].WdgMExpectedAliveSupIndication);
                /*n(AI)-n(SC)*/
                AliveSupTempCnt = (sint32)(WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveIndicationCounter)
                                  - (sint32)(WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveCycleCounter);
                AliveSupTempResult = AliveSupTempConfigCnt + AliveSupTempCnt;

                WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveCycleCounter = 0;
                WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveIndicationCounter = 0;

                if (((AliveSupTempResult + (sint32)(aliveSupCfg[Index].WdgMMinMargin)) >= 0)
                    && (AliveSupTempResult <= (sint32)(aliveSupCfg[Index].WdgMMaxMargin)))
                {
                    WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveSupResult = WDGM_CORRECT;
                }
                else
                {
                    WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveSupResult = WDGM_INCORRECT;
                }
            }
        }

        SEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(CerSEInfo->WdgMSEId);

        WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_ALIVE_SUP] = WDGM_CORRECT;

        /*update the AliveSup result of Certain SE including several AliveSup */
        for (Index = 0; Index < seAliveCnt; Index++)
        {
            Tab_Index = aliveSupCfg[Index].WdgMAliveSupID;
            if (WDGM_INCORRECT == WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveSupResult)
            {
                WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_ALIVE_SUP] = WDGM_INCORRECT;
                break;
            }
        }
    }
}

/***************************************************************/
/*
 * Brief               confirm the result of alive supervision
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      SupIndex: the array index of the WdgM_AliveSupInfoTab
 *                     RefCycle: The threshold cycle defined in the configuration
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: Success
 *                     E_NOT_OK: failure
 * CallByAPI           WdgM_ConfirmAliveSupResultEachSE
 */
/**************************************************************/
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_ConfirmAliveSupResult(uint16 SupIndex, uint16 RefCycle)
{
    Std_ReturnType l_ReturnValue;

    WdgM_AliveSupInfoTab[SupIndex].WdgMAliveCycleCounter++;
    if (WdgM_AliveSupInfoTab[SupIndex].WdgMAliveCycleCounter >= RefCycle)
    {
        /*The AliveSup Result base on the attachment*/
        l_ReturnValue = E_OK;
    }
    else
    {
        l_ReturnValue = E_NOT_OK;
    }
    return l_ReturnValue;
}

#endif /*WDGM_ALIVE_NUM > 0*/

#if (WDGM_DEADLINE_SUP_NUM > 0)

/***************************************************************/
/*
 * Brief               Update the status of the deadline supervision
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CPIndex: the array index of the CP in the configuration of the certain SE
 *                     CertSECfg: the configuration of the certain SE
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_CheckpointReached
 * REQ ID              DD_2_009, DD_2_010, DD_2_012, DD_2_013, DD_2_014, DD_2_015, DD_2_016,
 *                     DD_2_019,DD_2_115,DD_2_171
 */
/**************************************************************/

static FUNC(void, WDGM_CODE) WdgM_UpdateDeadlineSup(uint16 CPIndex, const WdgM_SECfgType* CertSECfg)
{
    volatile WdgM_DeadlineTimeType DeadlineTimeGap = 0;
    uint16 CPSupportDeadlineIndex;
    volatile WdgM_DeadlineTimeType WdgTimeStart = 0;
    const WdgM_CheckpointCfgType* CertCheckpoint =
        (const WdgM_CheckpointCfgType*)&CertSECfg->WdgMCheckpointRelated[CPIndex];
    const WdgM_CPSupprotDeadLineInfoType* CPSupportDeadlineInfo;
    const WdgM_DeadlineSupCfgType* DeadlineSupCfgInfo;
    uint16 DealineTab_Index;
    const uint16 seDealineCnt = CertSECfg->SEDealineCnt;
    const WdgM_DeadlineSupCfgType* DeadlineSupCfg = CertSECfg->WdgMDeadlineSupCfg;

    if ((uint8)STD_ON == WdgM_GetWordBitState(CertCheckpoint->WdgMSupSupportGroup, (uint8)DEADLINE_SUPPORT))
    {
        /******One Checkpoint may map several Deadline Sup********/
        for (CPSupportDeadlineIndex = 0; CPSupportDeadlineIndex < CertCheckpoint->WdgM_CPSupportDeadLineCnt;
             CPSupportDeadlineIndex++)
        {
            CPSupportDeadlineInfo = (const WdgM_CPSupprotDeadLineInfoType*)&CertCheckpoint
                                        ->WdgM_CPSupprotDeadLineInfo[CPSupportDeadlineIndex];
            if (WDGM_INCORRECT
                == WdgM_DeadlineSupInfoTab[CPSupportDeadlineInfo->WdgM_DeadlineSupID].WdgMDeadlineSupResult)
            {
                break;
            }
            else
            {
                /**Deadline Sup Start**/
                if ((uint8)STD_ON
                    == WdgM_GetWordBitState(
                        CPSupportDeadlineInfo->WdgMCPSupportDeadlineGroup,
                        (uint8)CP_DEADLINE_SUPPORT_START))
                {
                    WdgTimeStart = Frt_ReadOutMS();
                    WdgM_DeadlineSupInfoTab[CPSupportDeadlineInfo->WdgM_DeadlineSupID].WdgMTimeStampStart =
                        WdgTimeStart;
                }

                /**Deadline Sup Stop**/
                if ((uint8)STD_ON
                    == WdgM_GetWordBitState(
                        CPSupportDeadlineInfo->WdgMCPSupportDeadlineGroup,
                        (uint8)CP_DEADLINE_SUPPORT_STOP))
                {
                    if ((WdgM_DeadlineTimeType)0
                        != WdgM_DeadlineSupInfoTab[CPSupportDeadlineInfo->WdgM_DeadlineSupID].WdgMTimeStampStart)
                    {
                        /*req WdgM 229*/

                        for (DealineTab_Index = 0; DealineTab_Index < seDealineCnt; DealineTab_Index++)
                        {
                            if (DeadlineSupCfg[DealineTab_Index].WdgMDeadlineSupID
                                == CPSupportDeadlineInfo->WdgM_DeadlineSupID)
                            {
                                break;
                            }
                        }
                        DeadlineSupCfgInfo = (const WdgM_DeadlineSupCfgType*)&DeadlineSupCfg[DealineTab_Index];
                        DeadlineTimeGap = Frt_CalculateElapsedMS(
                            WdgM_DeadlineSupInfoTab[CPSupportDeadlineInfo->WdgM_DeadlineSupID].WdgMTimeStampStart);
                        /*req WdgM 294*/
                        WdgM_UpdateDeadlineSupResult(DeadlineTimeGap, DeadlineSupCfgInfo);
                        WdgM_DeadlineSupInfoTab[CPSupportDeadlineInfo->WdgM_DeadlineSupID].WdgMTimeStampStart = 0;
                    }
                    else
                    {
                        /*req WdgM 354: No action, if TimeStamp is 0*/
                    }
                }
            }
        }
    }
}

/***************************************************************/
/*
 * Brief               Update the result of the deadline supervision
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      TimeGap: the time span from the start CP to the end CP.
 *                     DeadlineSupCfg: the configuration of the certain deadline supervision
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_UpdateDeadlineSup
 * REQ ID              DD_2_011, DD_2_017, DD_2_018,DD_2_159
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_UpdateDeadlineSupResult(
    WdgM_DeadlineTimeType TimeGap,
    const WdgM_DeadlineSupCfgType* DeadlineSupCfg) /*req WdgM 294*/
{
    if ((((DeadlineSupCfg->WdgMDeadlineMin) * (WdgM_DeadlineTimeFloatType)WDGM_TIME_RESOLUTION)
         <= (WdgM_DeadlineTimeFloatType)TimeGap)
        && (((DeadlineSupCfg->WdgMDeadlineMax) * (WdgM_DeadlineTimeFloatType)WDGM_TIME_RESOLUTION)
            >= (WdgM_DeadlineTimeFloatType)TimeGap))
    {
        WdgM_DeadlineSupInfoTab[DeadlineSupCfg->WdgMDeadlineSupID].WdgMDeadlineSupResult = WDGM_CORRECT;
    }
    else
    {
        WdgM_DeadlineSupInfoTab[DeadlineSupCfg->WdgMDeadlineSupID].WdgMDeadlineSupResult = WDGM_INCORRECT;
    }
}

/***************************************************************/
/*
 * Brief               Perform timeout detection of deadline supervision in SE.
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]       CerSEInfo: the configuration of the certain supervision
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_MainFunction
 * REQ ID              DD_2_158
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_PerformDeadlineTimeoutDetection(const WdgM_SECfgType* CerSEInfo)
{
    uint16 Index;
    uint32 TempStartTime;
    volatile WdgM_DeadlineTimeType DeadlineTimeGap = 0u;
    const WdgM_DeadlineSupCfgType* DeadlineSupCfgInfo;
    const uint16 seDealineCnt = CerSEInfo->SEDealineCnt;
    const WdgM_DeadlineSupCfgType* DeadlineSupCfg = CerSEInfo->WdgMDeadlineSupCfg;

    for (Index = 0u; Index < seDealineCnt; Index++)
    {
        if ((boolean)TRUE == DeadlineSupCfg[Index].WdgMEnableTimeoutDetection)
        {
            DeadlineSupCfgInfo = (const WdgM_DeadlineSupCfgType*)&DeadlineSupCfg[Index];
            TempStartTime = WdgM_DeadlineSupInfoTab[DeadlineSupCfgInfo->WdgMDeadlineSupID].WdgMTimeStampStart;
            if ((WdgM_DeadlineTimeType)0 != TempStartTime)
            {
                DeadlineTimeGap = Frt_CalculateElapsedMS(TempStartTime);

                if (((DeadlineSupCfgInfo->WdgMDeadlineMax) * (WdgM_DeadlineTimeFloatType)WDGM_TIME_RESOLUTION)
                    < ((WdgM_DeadlineTimeFloatType)DeadlineTimeGap))
                {
                    WdgM_DeadlineSupInfoTab[DeadlineSupCfgInfo->WdgMDeadlineSupID].WdgMDeadlineSupResult =
                        WDGM_INCORRECT;
                    WdgM_DeadlineSupInfoTab[DeadlineSupCfgInfo->WdgMDeadlineSupID].WdgMTimeStampStart = 0;
                }
                else
                {
                    /*MISRA C*/
                }
            }
        }
    }
}

/***************************************************************/
/*
 * Brief               Confirm the results of deadline supervision in SE.
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]       CerSEInfo: the configuration of the certain supervision
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_MainFunction
 * REQ ID              DD_2_158
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_ConfirmDeadlineSupResultEachSE(const WdgM_SECfgType* CerSEInfo)
{
    uint16 Tab_Index;
    uint16 Index;
    uint16 SEStatusTabIndex;
    const uint16 seDealineCnt = CerSEInfo->SEDealineCnt;
    const WdgM_DeadlineSupCfgType* DeadlineSupCfg = CerSEInfo->WdgMDeadlineSupCfg;
    /*If Alive Sup is false, may jump the determination of the Deadline Sup*/
    if ((uint16)0 < seDealineCnt)
    {
        SEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(CerSEInfo->WdgMSEId);

        WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_DEADLINE_SUP] = WDGM_CORRECT;

        for (Index = 0; Index < seDealineCnt; Index++)
        {
            Tab_Index = DeadlineSupCfg[Index].WdgMDeadlineSupID;
            if (WDGM_INCORRECT == WdgM_DeadlineSupInfoTab[Tab_Index].WdgMDeadlineSupResult)
            {
                /*one Deadline Sup incorrect*/
                WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_DEADLINE_SUP] = WDGM_INCORRECT;
                break;
            }
        }
    }
}
#endif /*WDGM_DEADLINE_SUP_NUM > 0*/

#if (WDGM_INTLOG_SUP_NUM > 0)

/***************************************************************/
/*
 * Brief               Update the status of the internal logical supervision
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CertSECfg: the configuration of the certain supervision
 *                     CPIndex: the array index of the CP in the configuration of the certain SE
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_CheckpointReached
 * REQ ID              DD_2_022, DD_2_024, DD_2_026,DD_2_027, DD_2_028, DD_2_029,
 *                     DD_2_031, DD_2_032, DD_2_033,DD_2_116,DD_2_172
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_UpdateIntLogSup(uint16 CPIndex, const WdgM_SECfgType* CertSECfg)
{
    const WdgM_CheckpointCfgType* CertCheckpoint =
        (const WdgM_CheckpointCfgType*)&CertSECfg->WdgMCheckpointRelated[CPIndex];
    uint16 TransitionIndex;
    uint16 TransitionMax;
    const WdgM_IntLogSupCfgType* IntLogSupCfg = CertSECfg->WdgMIntLogSupCfg;

    if (((uint8)STD_ON == WdgM_GetWordBitState(CertCheckpoint->WdgMSupSupportGroup, (uint8)LOG_SUPPORT))
        && ((uint8)STD_ON == WdgM_GetWordBitState(CertCheckpoint->WdgMSupSupportGroup, (uint8)LOG_SUPPORT_INT_OR_EXT))
        && (WDGM_CORRECT == WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLogSupResult)) /*Interlog Sup*/
    {
        if (WDGM_AF_FALSE == WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLogActiveFlag)
        {
            /*req WdgM 274-1*/
            if ((uint8)STD_ON == WdgM_GetWordBitState(CertCheckpoint->WdgMSupSupportGroup, (uint8)LOG_SUP_SUPPORT_INIT))
            {
                WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLastReachedCPID =
                    CertCheckpoint->WdgMCheckpointID;
                WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLogActiveFlag =
                    WDGM_AF_TRUE; /*req WdgM 273,332*/
                WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLogSupResult =
                    WDGM_CORRECT; /*req WdgM 274-1*/
            }
            else
            {
                WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLogSupResult =
                    WDGM_INCORRECT; /*req WdgM 274-1*/
            }
        }
        else
        {
            TransitionMax = IntLogSupCfg[0].WdgMIntTransitionCnt;
            for (TransitionIndex = 0; TransitionIndex < TransitionMax; TransitionIndex++)
            {
                if (WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLastReachedCPID
                    == IntLogSupCfg[0].WdgMIntTransition[TransitionIndex].WdgMTransitionSourCPID)
                {
                    if (CertCheckpoint->WdgMCheckpointID
                        == IntLogSupCfg[0].WdgMIntTransition[TransitionIndex].WdgMTransitionDestCPID)
                    {
                        WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLogSupResult = WDGM_CORRECT;
                        break;
                    }
                    else
                    {
                        WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLogSupResult = WDGM_INCORRECT;
                    }
                }
            }
            if (TransitionIndex >= TransitionMax)
            {
                WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLogSupResult = WDGM_INCORRECT;
            }
            else if (WDGM_CORRECT == WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLogSupResult)
            {
                WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLastReachedCPID =
                    CertCheckpoint->WdgMCheckpointID;
                if ((uint8)STD_ON
                    == WdgM_GetWordBitState(CertCheckpoint->WdgMSupSupportGroup, (uint8)LOG_SUP_SUPPORT_FINAL))
                {
                    WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLogActiveFlag =
                        WDGM_AF_FALSE; /*req WdgM 331*/
                    WdgM_IntLogSupInfoTab[CertCheckpoint->WdgMLogSupID].WdgMIntLastReachedCPID = WDGM_NO_CP_REACH;
                }
            }
            else
            {
                /*MISRAC*/
            }
        }
    }
    else
    {
        /*req WdgM 297 : Nothing*/
    }
}

/***************************************************************/
/*
 * Brief               Confirm the results of internal logical supervision in SE
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CertSECfg: the configuration of the certain supervision
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_MainFunction
 * REQ ID              DD_2_160
 */
/**************************************************************/
/*req WdgM 324 : Determine the Alive Sup Result*/
static FUNC(void, WDGM_CODE) WdgM_ConfirmIntLogSupResultEachSE(const WdgM_SECfgType* CerSEInfo)
{
    uint16 Tab_Index;
    uint16 SEStatusTabIndex;

    /*If Sup above is false, may jump the determination of the Internal log Sup*/
    if ((uint16)0 < CerSEInfo->SEIntLogCnt)
    {
        Tab_Index = CerSEInfo->WdgMIntLogSupCfg[0].WdgMIntLogSupID;

        SEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(CerSEInfo->WdgMSEId);

        WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_INTLOG_SUP] =
            WdgM_IntLogSupInfoTab[Tab_Index].WdgMIntLogSupResult;
    }
}

#endif /*WDGM_INTLOG_SUP_NUM > 0*/

#if (WDGM_EXTLOG_SUP_NUM > 0)

/***************************************************************/
/*
 * Brief               Confirm the results of External logical supervision in Mode
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CertSECfg: the configuration of the certain supervision
 *                     CPIndex: the array index of the CP in the configuration of the certain SE
 *                     CerModeCfg : the configuration of the certain Mode
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_MainFunction
 * REQ ID              DD_2_022, DD_2_025, DD_2_026, DD_2_027, DD_2_028, DD_2_029,
 *                     DD_2_031, DD_2_032, DD_2_033,DD_2_116,DD_2_169
 */
/**************************************************************/
static FUNC(void, WDGM_CODE)
    WdgM_UpdateExtLogSup(uint16 CPIndex, const WdgM_SECfgType* CertSECfg, const WdgM_ModeCfgType* CerModeCfg)
{
    uint16 TransitionIndex;
    uint16 ExtlogSupModeConfigIndex;
    const WdgM_CheckpointCfgType* CertCheckpoint =
        (const WdgM_CheckpointCfgType*)&CertSECfg->WdgMCheckpointRelated[CPIndex];
    const uint16 modeExtLogCnt = CerModeCfg->ModeExtLogCnt;
    const WdgM_ExtLogSupCfgType* ExtLogSupRelated = CerModeCfg->WdgMExtLogSupRelated;

    if (((uint8)STD_ON == WdgM_GetWordBitState(CertCheckpoint->WdgMSupSupportGroup, (uint8)LOG_SUPPORT))
        && ((uint8)STD_OFF == WdgM_GetWordBitState(CertCheckpoint->WdgMSupSupportGroup, (uint8)LOG_SUPPORT_INT_OR_EXT))
        && (WDGM_CORRECT == WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLogSupResult))
    {
        /*req WdgM 252 - 1*/
        if (WDGM_AF_FALSE == WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLogActiveFlag)
        {
            if ((uint8)STD_ON == WdgM_GetWordBitState(CertCheckpoint->WdgMSupSupportGroup, (uint8)LOG_SUP_SUPPORT_INIT))
            {
                WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLastReachedCPID =
                    CertCheckpoint->WdgMCheckpointID;
                WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLastReachedSEID = CertSECfg->WdgMSEId;
                WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLogActiveFlag = WDGM_AF_TRUE;
                WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLogSupResult =
                    WDGM_CORRECT; /*req WdgM 252-1*/
            }
            else
            {
                WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLogSupResult =
                    WDGM_INCORRECT; /*req WdgM 252-1*/
            }
        }
        else
        {
            /****Find the ExtLog Sup index in the Mode Config *****/
            for (ExtlogSupModeConfigIndex = 0; ExtlogSupModeConfigIndex < modeExtLogCnt; ExtlogSupModeConfigIndex++)
            {
                if (ExtLogSupRelated[ExtlogSupModeConfigIndex].WdgMExtLogSupID
                    == CertCheckpoint->WdgMLogSupID) /*One CPID only belong to one Logsup*/
                {
                    break; /**/
                }
            }

            if (modeExtLogCnt <= ExtlogSupModeConfigIndex)
            {
                WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLogSupResult = WDGM_INCORRECT;
            }
            else
            {
                for (TransitionIndex = 0;
                     TransitionIndex < ExtLogSupRelated[ExtlogSupModeConfigIndex].WdgExtTransitionCnt;
                     TransitionIndex++)
                {
                    if ((WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLastReachedCPID
                         == ExtLogSupRelated[ExtlogSupModeConfigIndex]
                                .WdgMExtTransition[TransitionIndex]
                                .WdgMTransitionSourCPID)
                        && (WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLastReachedSEID
                            == ExtLogSupRelated[ExtlogSupModeConfigIndex]
                                   .WdgMExtTransition[TransitionIndex]
                                   .WdgMTransitionSourSEID))
                    {
                        if ((CertCheckpoint->WdgMCheckpointID
                             == ExtLogSupRelated[ExtlogSupModeConfigIndex]
                                    .WdgMExtTransition[TransitionIndex]
                                    .WdgMTransitionDestCPID)
                            && (CertSECfg->WdgMSEId
                                == ExtLogSupRelated[ExtlogSupModeConfigIndex]
                                       .WdgMExtTransition[TransitionIndex]
                                       .WdgMTransitionDestSEID))
                        {
                            WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLogSupResult = WDGM_CORRECT;
                            break;
                        }
                        else
                        {
                            WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLogSupResult = WDGM_INCORRECT;
                        }
                    }
                }
                if (ExtLogSupRelated[ExtlogSupModeConfigIndex].WdgExtTransitionCnt <= TransitionIndex)
                {
                    WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLogSupResult = WDGM_INCORRECT;
                }
                else if (WDGM_CORRECT == WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLogSupResult)
                {
                    WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLastReachedCPID =
                        CertCheckpoint->WdgMCheckpointID;
                    WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLastReachedSEID = CertSECfg->WdgMSEId;

                    if ((uint8)STD_ON
                        == WdgM_GetWordBitState(CertCheckpoint->WdgMSupSupportGroup, (uint8)LOG_SUP_SUPPORT_FINAL))
                    {
                        WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLogActiveFlag = WDGM_AF_FALSE;
                        WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLastReachedSEID =
                            WDGM_NO_SE_REACH;
                        WdgMExtLogSupInfoRelated[CertCheckpoint->WdgMLogSupID].WdgMExtLastReachedCPID =
                            WDGM_NO_CP_REACH;
                    }
                }
                else
                {
                    /*MISRAC*/
                }
            }
        }
    }
}

/***************************************************************/
/*
 * Brief               Clear the status of the external logical supervision in the old mode.
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Old_ModeCfg: the configuration of the old Mode
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_ChangeSEStatus
 * REQ ID              DD_2_177
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_ClearExtlogStatus(const WdgM_ModeCfgType* Old_ModeCfg)
{
    uint16 Old_Index;
    uint16 Tab_Index;
    volatile uint16 Old_IndexMax = 0;
    const WdgM_ExtLogSupCfgType* ExtLogSupRelated = Old_ModeCfg->WdgMExtLogSupRelated;

    Old_IndexMax = Old_ModeCfg->ModeExtLogCnt;

    for (Old_Index = 0; Old_Index < Old_IndexMax; Old_Index++)
    {
        Tab_Index = ExtLogSupRelated[Old_Index].WdgMExtLogSupID;
        WdgMExtLogSupInfoRelated[Tab_Index].WdgMExtLogActiveFlag = WDGM_AF_FALSE;
        WdgMExtLogSupInfoRelated[Tab_Index].WdgMExtLastReachedCPID = WDGM_NO_CP_REACH;
        WdgMExtLogSupInfoRelated[Tab_Index].WdgMExtLastReachedSEID = WDGM_NO_SE_REACH;
        WdgMExtLogSupInfoRelated[Tab_Index].WdgMExtLogSupResult = WDGM_CORRECT;
    }
}

/***************************************************************/
/*
 * Brief               confirm the result of external logical supervision for each SE
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CerModeCfg: the configuration of Mode
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_MainFunction
 * REQ ID              DD_2_252
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_ConfirmExtLogSupResultEachSE(const WdgM_ModeCfgType* CerModeCfgPtr)
{
    uint16 Index;
    uint16 ExtLogIndex;
    const uint16 ExtLogIndexMax = CerModeCfgPtr->ModeExtLogCnt;
    uint16 SERelatedIndex;
    const uint16 IndexMax = CerModeCfgPtr->ModeSECnt;
    uint16 SERelatedIndexMax;
    uint16 LogSupIndex;
    uint16 SEStatusTabIndex;
    WdgM_SupervisedEntityIdType SEId;
    const WdgM_SECfgType* SERelated = CerModeCfgPtr->WdgMSERelated;
    const WdgM_ExtLogSupCfgType* ExtLogSupRelated = CerModeCfgPtr->WdgMExtLogSupRelated;

    for (Index = 0; Index < IndexMax; Index++) /*SE quantity*/
    {
        SEId = SERelated[Index].WdgMSEId;

        SEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(SEId);

        for (ExtLogIndex = 0; ExtLogIndex < ExtLogIndexMax; ExtLogIndex++) /*ExtLogSup quantity*/
        {
            SERelatedIndexMax = ExtLogSupRelated[ExtLogIndex].SEIdRelatedCnt;
            /*Related SE quantity of each ExtLog Sup*/
            for (SERelatedIndex = 0; SERelatedIndex < SERelatedIndexMax; SERelatedIndex++)
            {
                /*Find the SE related to the ExtLog Sup via SEID*/
                if (SEId == ExtLogSupRelated[ExtLogIndex].WdgMSEIdImpacted[SERelatedIndex])
                {
                    LogSupIndex = ExtLogSupRelated[ExtLogIndex].WdgMExtLogSupID;
                    /*One ExtLog Sup Error in this SE*/
                    if (WDGM_INCORRECT == WdgMExtLogSupInfoRelated[LogSupIndex].WdgMExtLogSupResult)
                    {
                        break;
                    }
                }
            }
            if (SERelatedIndexMax > SERelatedIndex)
            {
                break;
            }
        }

        if (ExtLogIndexMax > ExtLogIndex)
        {
            WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_EXTLOG_SUP] = WDGM_INCORRECT;
        }
        else
        {
            WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_EXTLOG_SUP] = WDGM_CORRECT;
        }
    }
}

#endif /*WDGM_EXTLOG_SUP_NUM > 0*/

#if ((WDGM_ALIVE_NUM > 0) || (WDGM_DEADLINE_SUP_NUM > 0))

/***************************************************************/
/*
 * Brief               change the status of all kinds of supervision in the SE
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Old_ModeCfg: the configuration of old Mode
 *                     New_ModeCfg: the configuration of new Mode
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_CheckpointReached, WdgM_GetLocalStatus
 * REQ ID              DD_2_176
 */
/**************************************************************/
static FUNC(void, WDGM_CODE)
    WdgM_ClearNoUseAliveDeadlineStatus(const WdgM_SECfgType* OldSE, const WdgM_SECfgType* NewSE)
{
    uint16 Old_Index;
    uint16 Tab_Index;
    uint16 New_Index;
    uint16 InnerCycle_Index = 0;
    volatile uint16 Old_IndexMax = 0;
    volatile uint16 New_IndexMax = 0;
    const WdgM_AliveSupCfgType* OldSE_AliveSupCfg = OldSE->WdgMAliveSupCfg;
    const WdgM_DeadlineSupCfgType* OldSE_DeadlineSupCfg = OldSE->WdgMDeadlineSupCfg;
    const WdgM_AliveSupCfgType* NewSE_AliveSupCfg = NewSE->WdgMAliveSupCfg;
    const WdgM_DeadlineSupCfgType* NewSE_DeadlineSupCfg = NewSE->WdgMDeadlineSupCfg;

#if (WDGM_ALIVE_NUM > 0)
    Old_IndexMax = OldSE->SEAliveCnt;
    New_IndexMax = NewSE->SEAliveCnt;
    for (Old_Index = 0; Old_Index < Old_IndexMax; Old_Index++)
    {
        /*AliveID sorts from same to big*/
        for (New_Index = InnerCycle_Index; New_Index < New_IndexMax; New_Index++)
        {
            if (OldSE_AliveSupCfg[Old_Index].WdgMAliveSupID == NewSE_AliveSupCfg[New_Index].WdgMAliveSupID)
            {
                InnerCycle_Index = New_Index + (uint16)1;
                break;
            }
        }
        if (New_Index >= New_IndexMax)
        {
            Tab_Index = OldSE_AliveSupCfg[Old_Index].WdgMAliveSupID;
            WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveCycleCounter = 0;
            WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveIndicationCounter = 0;
            WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveSupResult = WDGM_CORRECT;
        }
    }
#endif /*WDGM_ALIVE_NUM > 0*/

#if (WDGM_DEADLINE_SUP_NUM > 0)
    Old_IndexMax = OldSE->SEDealineCnt;
    New_IndexMax = NewSE->SEDealineCnt;
    InnerCycle_Index = 0;
    for (Old_Index = 0; Old_Index < Old_IndexMax; Old_Index++)
    {
        for (New_Index = InnerCycle_Index; New_Index < New_IndexMax; New_Index++)
        {
            if (OldSE_DeadlineSupCfg[Old_Index].WdgMDeadlineSupID == NewSE_DeadlineSupCfg[New_Index].WdgMDeadlineSupID)
            {
                InnerCycle_Index = New_Index + (uint16)1;
                break;
            }
        }
        if (New_Index >= New_IndexMax)
        {
            Tab_Index = OldSE_DeadlineSupCfg[Old_Index].WdgMDeadlineSupID;
            WdgM_DeadlineSupInfoTab[Tab_Index].WdgMTimeStampStart = 0;
            WdgM_DeadlineSupInfoTab[Tab_Index].WdgMDeadlineSupResult = WDGM_CORRECT;
        }
    }
#endif /*WDGM_DEADLINE_SUP_NUM > 0*/
}
#endif /*WDGM_ALIVE_NUM > 0 || WDGM_DEADLINE_SUP_NUM > 0*/

/***************************************************************/
/*
 * Brief               Performs the processing of the cyclic Watchdog Manager jobs
 * ServiceId           0x08
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           Up layer
 * REQ ID              DD_2_058,DD_2_103,DD_2_107,DD_2_108,DD_2_109,DD_2_112
 */
/**************************************************************/
void WdgM_MainFunction(void)
{
#if (WDGM_SE_NUM > 0)
    uint16 SEStatusTabIndex;
    uint16 SE_Index;
    const WdgM_SECfgType* ModeSEInfo;

    if (WDGM_GLOBAL_STATUS_DEACTIVATED != WdgMGlobalInfo.WdgMGlobalResult) /*req WdgM 0063*/
    {
#if (STD_ON == WDGM_DEV_ERROR_DETECT)
        if (WDGM_INIT_NOT == WdgMModeInfo.WdgMModeInitStatus)
        {
            (void)Det_ReportError(
                WDGM_MODULE_ID,
                WDGM_INSTANCE_ID,
                WDGM_MAINFUNCTION_ID,
                WDGM_E_NO_INIT); /*req WdgM 039*/
        }
        else
#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/
        {
/*Determine the External Log Sup status of each SE*/
#if (WDGM_EXTLOG_SUP_NUM > 0)
            WdgM_ConfirmExtLogSupResultEachSE(CurModeCfg);
#endif /*WDGM_EXTLOG_SUP_NUM > 0*/

            for (SE_Index = 0; SE_Index < CurModeCfg->ModeSECnt; SE_Index++)
            {
                ModeSEInfo = (const WdgM_SECfgType*)&CurModeCfg->WdgMSERelated[SE_Index];

                SEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(ModeSEInfo->WdgMSEId);

                if ((WDGM_LOCAL_STATUS_OK == WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus)
                    || (WDGM_LOCAL_STATUS_FAILED == WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus))
                {
#if (WDGM_ALIVE_NUM > 0)
                    /*req WdgM 324 : Determine the Alive Sup Result*/
                    WdgM_ConfirmAliveSupResultEachSE(ModeSEInfo);
#endif /*WDGM_ALIVE_NUM > 0*/

#if (WDGM_DEADLINE_SUP_NUM > 0)
                    /* req WdgM 403 : Deadline Timeout Detection */
                    WdgM_PerformDeadlineTimeoutDetection(ModeSEInfo);
                    /*req WdgM 324 : Determine the Alive Sup Result*/
                    WdgM_ConfirmDeadlineSupResultEachSE(ModeSEInfo);
#endif /*WDGM_DEADLINE_SUP_NUM > 0*/

#if (WDGM_INTLOG_SUP_NUM > 0)
                    /*req WdgM 324 : Determine the Alive Sup Result*/
                    WdgM_ConfirmIntLogSupResultEachSE(ModeSEInfo);
#endif /*WDGM_INTLOG_SUP_NUM > 0*/
                    /*req WdgM 325 : Determine the Local Sup status of each SE*/
                    WdgM_ConfirmSELoacalStatus(ModeSEInfo);
                }
            }

            /*req WdgM 326 : Determine the Global Sup status*/
            /*req WdgM 214*/
            WdgM_ConfirmGlobalStatus();

            /*req WdgM 328 : Set trigger condition base on the Global Status*/
            WdgM_SetTrigger();
        }
    }
#endif /*WDGM_SE_NUM > 0*/
}

#if (WDGM_SE_NUM > 0)
/***************************************************************/
/*
 * Brief               confirm the local status of the SE
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CerSEInfo: the configuration of SE
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_MainFunction
 * REQ ID              DD_2_034,DD_2_253,DD_2_049,DD_2_050,DD_2_051,DD_2_052,
 *                     DD_2_053,DD_2_054,DD_2_055,DD_2_105,DD_2_106,DD_2_161
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_ConfirmSELoacalStatus(const WdgM_SECfgType* CerSEInfo)
{
    uint16 SEStatusTabIndex;
    Std_ReturnType l_Ret = E_OK;
    const uint8 AliveFailedTol = CerSEInfo->WdgMFailedAliveSupervisionRefCycleTol;

    SEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(CerSEInfo->WdgMSEId);

    if (WDGM_LOCAL_STATUS_OK == WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus)
    {
        if ((WDGM_CORRECT == WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_INTLOG_SUP])
            && (WDGM_CORRECT == WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_EXTLOG_SUP])
            && (WDGM_CORRECT == WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_DEADLINE_SUP]))
        {
            if (WDGM_INCORRECT == WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_ALIVE_SUP])
            {
                if ((uint8)0 < AliveFailedTol)
                {
                    /*req WdgM 203 : Fig3-3*/
                    WdgMSEInfoRelated[SEStatusTabIndex].WdgMFailedAliveSupCounter++;
                    WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus = WDGM_LOCAL_STATUS_FAILED;
                    /*DD_2_038*/
                    WdgM_RestartOSApplication(CerSEInfo);
                }
                else
                {
                    l_Ret = E_NOT_OK;
                }
            }
        }
        else
        {
            l_Ret = E_NOT_OK;
        }
    }
    else if (WDGM_LOCAL_STATUS_FAILED == WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus)
    {
        if ((WDGM_INCORRECT == WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_INTLOG_SUP])
            || (WDGM_INCORRECT == WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_EXTLOG_SUP])
            || (WDGM_INCORRECT == WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_DEADLINE_SUP]))
        {
            /*req WdgM 206 : Failed  to Expired*/
            l_Ret = E_NOT_OK;
        }
        else if (WDGM_INCORRECT == WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_ALIVE_SUP])
        {
            WdgMSEInfoRelated[SEStatusTabIndex].WdgMFailedAliveSupCounter++;
            if (AliveFailedTol < WdgMSEInfoRelated[SEStatusTabIndex].WdgMFailedAliveSupCounter)
            {
                l_Ret = E_NOT_OK;
            }
        }
        else
        {
            if ((uint8)1 >= WdgMSEInfoRelated[SEStatusTabIndex].WdgMFailedAliveSupCounter)
            {
                WdgMSEInfoRelated[SEStatusTabIndex].WdgMFailedAliveSupCounter = 0;
                /*req WdgM 205 :Fig3-5 */
                WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus = WDGM_LOCAL_STATUS_OK;
            }
            else
            {
                /*req WdgM 300 : Fig3-4 Reamin the Failed, ErrorCnt--*/
                WdgMSEInfoRelated[SEStatusTabIndex].WdgMFailedAliveSupCounter--;
            }
        }
    }
    else
    {
        /*MISRA-C*/
    }

    if ((Std_ReturnType)E_NOT_OK == l_Ret)
    {
        WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus = WDGM_LOCAL_STATUS_EXPIRED;
        if ((Std_ReturnType)E_NOT_OK == WdgMGlobalInfo.WdgM_FirstExpiredSEIDSaved)
        {
            /* PRQA S 0303 ++*/ /* MISRA Rule 11.4 */
            *(volatile uint16*)WDGM_FIRST_EXPIRED_SEID = CerSEInfo->WdgMSEId;
            /* PRQA S 4499 ++ */ /* MISRA Rule 10.6 */
            *(volatile uint16*)WDGM_FIRST_EXPIRED_INVERSE_SEID = ~(CerSEInfo->WdgMSEId);
            /* PRQA S 4499 -- */ /* MISRA Rule 10.6 */
            /* PRQA S 0303 -- */ /* MISRA Rule 11.4 */
            WdgMGlobalInfo.WdgM_FirstExpiredSEIDSaved = E_OK;
        }
    }
}

/***************************************************************/
/*
 * Brief               confirm the Global status
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_MainFunction
 * REQ ID              DD_2_035, DD_2_060, DD_2_063, DD_2_064, DD_2_065, DD_2_066
 *                     DD_2_067, DD_2_068, DD_2_069, DD_2_070,DD_2_071,DD_2_072,
 *                     DD_2_073,DD_2_162
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_ConfirmGlobalStatus(void)
{
    uint16 SE_Index;
    uint16 SEStatusTabIndex;
    Std_ReturnType SEExpiredFlag = E_NOT_OK;
    Std_ReturnType SEFailedFlag = E_NOT_OK;

    if ((WDGM_GLOBAL_STATUS_STOPPED != WdgMGlobalInfo.WdgMGlobalResult)
        && (WDGM_GLOBAL_STATUS_DEACTIVATED != WdgMGlobalInfo.WdgMGlobalResult))
    {
        for (SE_Index = 0; SE_Index < CurModeCfg->ModeSECnt; SE_Index++)
        {
            SEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(CurModeCfg->WdgMSERelated[SE_Index].WdgMSEId);
            if (WDGM_LOCAL_STATUS_EXPIRED == WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus)
            {
                SEExpiredFlag = E_OK;
                break;
            }
            else if (WDGM_LOCAL_STATUS_FAILED == WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus)
            {
                SEFailedFlag = E_OK; /* PRQA S 2983 */ /* MISRA Rule 2.2 */
            }
            else
            {
                /*MISRAC*/
            }
        }

        if ((Std_ReturnType)E_OK == SEExpiredFlag)
        {
            WdgMModeInfo.WdgMExpiredSupTolCounter++;
            if ((WdgMModeInfo.WdgMExpiredSupTolCounter > CurModeCfg->WdgMExpiredSupervisionCycleTol))
            {
                /*req WdgM 216 :Fig4-4 / WdgM 117 :Fig4-8*/
                WdgMGlobalInfo.WdgMGlobalResult = WDGM_GLOBAL_STATUS_STOPPED;
                WdgMModeInfo.WdgMExpiredSupTolCounter = 0;
                /*DD_2_037*/
                WdgM_StopStatusErrorHanding(); /* PRQA S 2987 */ /* MISRA Rule 2.2 */
            }
            else
            {
                /*req WdgM 219 :Fig4-9*/
                WdgMGlobalInfo.WdgMGlobalResult = WDGM_GLOBAL_STATUS_EXPIRED;
            }
        }
        else if ((Std_ReturnType)E_OK == SEFailedFlag)
        {
            /*req WdgM 76 :Fig4-2 /WdgM 217 :Fig4-5*/
            WdgMGlobalInfo.WdgMGlobalResult = WDGM_GLOBAL_STATUS_FAILED;
        }
        else
        {
            /*req WdgM 78 :Fig4-1 /WdgM 218 :Fig4-6*/
            WdgMGlobalInfo.WdgMGlobalResult = WDGM_GLOBAL_STATUS_OK;
        }
    }
}

/***************************************************************/
/*
 * Brief               Error operation when the global status is stop.
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_ConfirmGlobalStatus
 * REQ ID              DD_2_163
 */
/**************************************************************/

static FUNC(void, WDGM_CODE) WdgM_StopStatusErrorHanding(void)
{
#if (STD_ON == WDGM_E_SUPERVISION_ENABLE)
    Dem_ReportErrorStatus(WDGM_E_SUPERVISION, DEM_EVENT_STATUS_FAILED); /* req WdgM 129*/
#endif                                                                  /*STD_ON == WDGM_E_SUPERVISION_ENABLE*/

#if (STD_ON == WDGM_IMMEDIATE_RESET)
    /*DD_2_039:(1)*/
    /*ShutdownOS shall Deinit the RAM for OS, this shall forbid the fail of startOS*/
    ShutdownOS(WDGM_IMMEDIATE_RESET_VIA_OS);
/*req WdgM 134: no notification to the application via the RTE */
#endif /*STD_ON == WDGM_IMMEDIATE_RESET*/
}

/***************************************************************/
/*
 * Brief               OS-Application Reset when SE in this OS-Application in error.
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CerSEInfo : the configuration of the SE
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_ConfirmSELocalStatus
 * REQ ID              DD_2_258
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_RestartOSApplication(const WdgM_SECfgType* CerSEInfo)
{
    if ((uint16)WDGM_NO_OS_APPLICAITON_REF != CerSEInfo->WdgMOsApplicationRef)
    {
#if (BSWM_WDGM_ENABLED == STD_ON)
#if (BSWM_MAX_NUM_PARTITION > 1)
        BswM_WdgM_RequestPartitionReset(CerSEInfo->WdgMOsApplicationRef);
#endif
#endif
    }
}

/***************************************************************/
/*
 * Brief               Set Trigger condition
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_MainFunction
 * REQ ID              DD_2_041, DD_2_042, DD_2_043, DD_2_044, DD_2_045, DD_2_046,DD_2_165
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_SetTrigger(void)
{
    uint8 triggerIndex;
    const uint8 modeTriggerCnt = CurModeCfg->ModeTriggerCnt;
    const WdgM_TriggerType* TriggerRelated = CurModeCfg->WdgMTriggerRelated;

    if ((WDGM_GLOBAL_STATUS_OK == WdgMGlobalInfo.WdgMGlobalResult)
        || (WDGM_GLOBAL_STATUS_FAILED == WdgMGlobalInfo.WdgMGlobalResult)
        || (WDGM_GLOBAL_STATUS_EXPIRED == WdgMGlobalInfo.WdgMGlobalResult))
    {
        /*req WdgM 223-1*/
        /*req WdgM 119*/
        /*req WdgM 120*/
        /*req WdgM 121*/
        for (triggerIndex = 0; triggerIndex < modeTriggerCnt; triggerIndex++)
        {
            if (WDGIF_OFF_MODE != TriggerRelated[triggerIndex].WdgMWatchdogMode)
            {
                WdgIf_SetTriggerCondition(
                    TriggerRelated[triggerIndex].WdgM_WatchdogDevice,
                    TriggerRelated[triggerIndex].WdgMTriggerConditionValue);
            }
        }
    }
    else if (WDGM_GLOBAL_STATUS_STOPPED == WdgMGlobalInfo.WdgMGlobalResult)
    {
        /*req WdgM 223-2*/
        /*req WdgM 122*/
        for (triggerIndex = 0; triggerIndex < modeTriggerCnt; triggerIndex++)
        {
            if (WDGIF_OFF_MODE != TriggerRelated[triggerIndex].WdgMWatchdogMode)
            {
                WdgIf_SetTriggerCondition(
                    TriggerRelated[triggerIndex].WdgM_WatchdogDevice,
                    WDGM_TRIGGER_CONDITION_STOP);
            }
        }
    }
    else
    {
        /*req WdgM 223-3 : do nothing*/
    }
}

/***************************************************************/
/*
 * Brief               Get the array index of the CP in the SE
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CPID: the Checkpoint ID
 *                     CertSECfg: the configuration of the SE
 * Param-Name[out]     CPTabIndex: the array index of the CP in the SE
 * Param-Name[in/out]  None
 * Return              E_NOT_OK,E_OK
 * CallByAPI           WdgM_CheckpointReached
 * REQ ID              DD_2_168
 */
/**************************************************************/
static FUNC(Std_ReturnType, WDGM_CODE)
    WdgM_GetSECheckpointIndex(WdgM_CheckpointIdType CPID, const WdgM_SECfgType* CertSECfg, uint16* CPTabIndex)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint16 CP_Index;
    const uint16 seCPCnt = CertSECfg->SECPCnt;
    const WdgM_CheckpointCfgType* CheckpointRelated = CertSECfg->WdgMCheckpointRelated;

    for (CP_Index = 0; CP_Index < seCPCnt; CP_Index++)
    {
        if (CheckpointRelated[CP_Index].WdgMCheckpointID == CPID)
        {
            *CPTabIndex = CP_Index;
            l_ReturnValue = E_OK;
            break;
        }
    }

    return l_ReturnValue;
}

/***************************************************************/
/*
 * Brief               Init the status of all the array ralated to the SE.
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_Init
 * REQ ID              DD_2_048,DD_2_084,DD_2_085,DD_2_086,DD_2_087,DD_2_179
 */
/**************************************************************/
static FUNC(void, WDGM_CODE) WdgM_InitAllTabStatus(void)
{
    uint16 Index;

    for (Index = 0; Index < WDGM_SE_NUM; Index++)
    {
        /*req WdgM 269*/
        WdgMSEInfoRelated[Index].WdgMLocalStatus = WDGM_LOCAL_STATUS_DEACTIVATED;
        WdgMSEInfoRelated[Index].WdgMFailedAliveSupCounter = 0;
        WdgMSEInfoRelated[Index].WdgMEachSupResult[WDGM_ALIVE_SUP] = WDGM_CORRECT;
        WdgMSEInfoRelated[Index].WdgMEachSupResult[WDGM_DEADLINE_SUP] = WDGM_CORRECT;
        WdgMSEInfoRelated[Index].WdgMEachSupResult[WDGM_INTLOG_SUP] = WDGM_CORRECT;
        WdgMSEInfoRelated[Index].WdgMEachSupResult[WDGM_EXTLOG_SUP] = WDGM_CORRECT;
    }

#if (WDGM_ALIVE_NUM > 0)
    for (Index = 0; Index < WDGM_ALIVE_NUM; Index++) /* PRQA S 2877 */ /* MISAR Dir 4.1 */
    {
        WdgM_AliveSupInfoTab[Index].WdgMAliveCycleCounter = 0;
        WdgM_AliveSupInfoTab[Index].WdgMAliveIndicationCounter = 0;
        WdgM_AliveSupInfoTab[Index].WdgMAliveSupResult = WDGM_CORRECT;
    }
#endif /*WDGM_ALIVE_NUM  > 0*/

#if (WDGM_DEADLINE_SUP_NUM > 0)
    for (Index = 0; Index < WDGM_DEADLINE_SUP_NUM; Index++) /* PRQA S 2877 */ /* MISAR Dir 4.1 */
    {
        WdgM_DeadlineSupInfoTab[Index].WdgMTimeStampStart = 0;
        WdgM_DeadlineSupInfoTab[Index].WdgMDeadlineSupResult = WDGM_CORRECT;
    }
#endif /*WDGM_DEADLINE_SUP_NUM  > 0*/

#if (WDGM_INTLOG_SUP_NUM > 0)
    for (Index = 0; Index < WDGM_INTLOG_SUP_NUM; Index++) /* PRQA S 2877 */ /* MISAR Dir 4.1 */
    {
        WdgM_IntLogSupInfoTab[Index].WdgMIntLogActiveFlag = WDGM_AF_FALSE; /*DD_2_021*/
        WdgM_IntLogSupInfoTab[Index].WdgMIntLastReachedCPID = WDGM_NO_CP_REACH;
        WdgM_IntLogSupInfoTab[Index].WdgMIntLogSupResult = WDGM_CORRECT;
    }
#endif /*WDGM_INTLOG_SUP_NUM  > 0*/

#if (WDGM_EXTLOG_SUP_NUM > 0)
    for (Index = 0; Index < WDGM_EXTLOG_SUP_NUM; Index++)
    {
        WdgMExtLogSupInfoRelated[Index].WdgMExtLogActiveFlag = WDGM_AF_FALSE; /*DD_2_021*/
        WdgMExtLogSupInfoRelated[Index].WdgMExtLastReachedCPID = WDGM_NO_CP_REACH;
        WdgMExtLogSupInfoRelated[Index].WdgMExtLastReachedSEID = WDGM_NO_SE_REACH;
        WdgMExtLogSupInfoRelated[Index].WdgMExtLogSupResult = WDGM_CORRECT;
    }
#endif /*WDGM_EXTLOG_SUP_NUM  > 0*/
}

/***************************************************************/
/*
 * Brief               Init the local status of all SE in the Mode
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CerModeCfgPtr: the configuration of certain Mode
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_Init
 * REQ ID              DD_2_047,DD_2_180
 */
/**************************************************************/

static FUNC(void, WDGM_CODE) WdgM_InitSEStatus(const WdgM_ModeCfgType* CerModeCfgPtr)
{
    uint16 SE_Index;
    uint16 SEStatusTabIndex;
    const WdgM_SECfgType* ModeSEInfo;
    const uint16 modeSECnt = CerModeCfgPtr->ModeSECnt;
    const WdgM_SECfgType* SERelated = CerModeCfgPtr->WdgMSERelated;

    for (SE_Index = 0; SE_Index < modeSECnt; SE_Index++)
    {
        ModeSEInfo = (const WdgM_SECfgType*)&SERelated[SE_Index];
        SEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(ModeSEInfo->WdgMSEId);
        /*req WdgM 268*/
        WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus = WDGM_LOCAL_STATUS_OK;
    }
}

/***************************************************************/
/*
 * Brief               Deinit the local status of all SE in the Mode
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CerModeCfgPtr: the configuration of certain Mode
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_Init
 * REQ ID              DD_2_047,DD_2_180
 */
/**************************************************************/

static FUNC(void, WDGM_CODE) WdgM_DeinitSEStatus(const WdgM_ModeCfgType* CerModeCfgPtr)
{
    uint16 SE_Index;
    uint16 SEStatusTabIndex;
    const WdgM_SECfgType* ModeSEInfo;
    const uint16 modeSECnt = CerModeCfgPtr->ModeSECnt;
    const WdgM_SECfgType* SERelated = CerModeCfgPtr->WdgMSERelated;
    for (SE_Index = 0; SE_Index < modeSECnt; SE_Index++)
    {
        ModeSEInfo = (const WdgM_SECfgType*)&SERelated[SE_Index];
        SEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(ModeSEInfo->WdgMSEId);
        /*req WdgM 268*/
        WdgMSEInfoRelated[SEStatusTabIndex].WdgMLocalStatus = WDGM_LOCAL_STATUS_FAILED;
    }
}

/***************************************************************/
/*
 * Brief               Get the index of the SE in the array of the configured SE Tab
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CerModeCfgPtr: the configuration of certain Mode
 *                     SEID: The supervision Entity ID
 * Param-Name[out]     ModeSEIndex: the index of the SE in the array of the configured SE Tab
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_CheckpointReached, WdgM_GetLocalStatus
 * REQ ID              DD_2_166
 */
/**************************************************************/

static FUNC(Std_ReturnType, WDGM_CODE)
    WdgM_GetModeSEIndex(WdgM_SupervisedEntityIdType SEID, uint16* ModeSEIndex, const WdgM_ModeCfgType* CerModeCfgPtr)
{
    uint16 SE_Index;
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    const uint16 modeSECnt = CerModeCfgPtr->ModeSECnt;
    const WdgM_SECfgType* SERelated = CerModeCfgPtr->WdgMSERelated;

    for (SE_Index = 0; SE_Index < modeSECnt; SE_Index++)
    {
        if (SERelated[SE_Index].WdgMSEId == SEID)
        {
            *ModeSEIndex = SE_Index;
            l_ReturnValue = E_OK;
            break;
        }
    }
    return l_ReturnValue;
}

/***************************************************************/
/*
 * Brief               change the status of all kinds of supervision in the SE
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      Old_ModeCfg: the configuration of old Mode
 *                     New_ModeCfg: the configuration of new Mode
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_CheckpointReached, WdgM_GetLocalStatus
 * REQ ID              DD_2_056,DD_2_057,DD_2_059,DD_2_075,DD_2_076,DD_2_175
 */
/**************************************************************/
static FUNC(void, WDGM_CODE)
    WdgM_ChangeSEStatus(const WdgM_ModeCfgType* Old_ModeCfg, const WdgM_ModeCfgType* New_ModeCfg)
{
    uint16 InnerCycle_Index = 0;
    uint16 Old_Index;
    uint16 OldSEStatusTabIndex;
    uint16 Old_IndexMax = Old_ModeCfg->ModeSECnt; /* Quantities for previous SE */
    uint16 New_Index;
    uint16 NewSETabStatusIndex;
    uint16 New_IndexMax = New_ModeCfg->ModeSECnt; /* Quantities for new SE */
    volatile Std_ReturnType l_AlreadyActive = E_NOT_OK;
    const WdgM_SECfgType* Old_SERelated = Old_ModeCfg->WdgMSERelated;
    const uint16 modeExtLogCnt = Old_ModeCfg->ModeExtLogCnt;
    const WdgM_SECfgType* New_SERelated = New_ModeCfg->WdgMSERelated;
    /* temporal variable for previous SE information  */
    WdgM_LocalStatusType l_OldSEStatus[WDGM_SE_NUM] = {0};

    for (Old_Index = 0; Old_Index < Old_IndexMax; Old_Index++)
    {
        OldSEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(Old_SERelated[Old_Index].WdgMSEId);
        /*Save the old SE in temporary variable*/
        l_OldSEStatus[OldSEStatusTabIndex] = WdgMSEInfoRelated[OldSEStatusTabIndex].WdgMLocalStatus;
    }

    for (New_Index = 0; New_Index < New_IndexMax; New_Index++)
    {
        NewSETabStatusIndex = WdgM_GetSupervisedEntityTabIndex(New_SERelated[New_Index].WdgMSEId);
        /* req WdgM 209 Old Active != New Active, the new SE should be deault OK*/
        WdgMSEInfoRelated[NewSETabStatusIndex].WdgMLocalStatus = WDGM_LOCAL_STATUS_OK;
    }

    /*SE should sort from small to large in config*/
    for (Old_Index = 0; Old_Index < Old_IndexMax; Old_Index++)
    {
        l_AlreadyActive = E_NOT_OK;
        for (New_Index = InnerCycle_Index; New_Index < New_IndexMax; New_Index++)
        {
            NewSETabStatusIndex = WdgM_GetSupervisedEntityTabIndex(New_SERelated[New_Index].WdgMSEId);

            if (Old_SERelated[Old_Index].WdgMSEId == New_SERelated[New_Index].WdgMSEId) /*Both Mode Active */
            {
                WdgMSEInfoRelated[NewSETabStatusIndex].WdgMLocalStatus = l_OldSEStatus[NewSETabStatusIndex];
#if ((WDGM_ALIVE_NUM > 0) || (WDGM_DEADLINE_SUP_NUM > 0))
                WdgM_ClearNoUseAliveDeadlineStatus(
                    (const WdgM_SECfgType*)&Old_SERelated[Old_Index],
                    (const WdgM_SECfgType*)&New_SERelated[New_Index]);
#endif /*WDGM_ALIVE_NUM > 0  ||  WDGM_DEADLINE_SUP_NUM > 0*/
                InnerCycle_Index = New_Index + (uint16)1;
                /*WdgMLocalStatusSupervisedEntityRef already active in old mode */
                l_AlreadyActive = E_OK;
                break;
            }
            else
            {
                /*MISAR-C*/
            }
        }
        if ((Std_ReturnType)E_NOT_OK == l_AlreadyActive)
        {
            OldSEStatusTabIndex = WdgM_GetSupervisedEntityTabIndex(Old_SERelated[Old_Index].WdgMSEId);
            /*req WdgM 207 208 291*/
            WdgMSEInfoRelated[OldSEStatusTabIndex].WdgMLocalStatus = WDGM_LOCAL_STATUS_DEACTIVATED;
            WdgM_SEDeactivateInternal(Old_ModeCfg, Old_Index, OldSEStatusTabIndex); /*req WdgM 315*/
        }
    }

#if (WDGM_EXTLOG_SUP_NUM > 0)
    if ((uint16)0 < modeExtLogCnt) /*Mode contains the ExtLogSup*/
    {
        WdgM_ClearExtlogStatus(Old_ModeCfg);
    }
#endif /*WDGM_EXTLOG_SUP_NUM > 0*/
}

/***************************************************************/
/*
 * Brief               Get the index of the SE in the array in the WdgM_SupervisedEntityToTabIndex
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CerSEID: the supervision entity ID
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              the index of the SE in the array in the WdgM_SupervisedEntityToTabIndex
 * CallByAPI           WdgM_CheckpointReached, WdgM_ChangeSEStatus,
 *                     WdgM_ConfirmAliveSupResultEachSE,
 *                     WdgM_ConfirmDeadlineSupResultEachSE,WdgM_ConfirmExtlogSupResultEachSE,
 *                     WdgM_ConfirmIntlogSupResultEachSE,WdgM_ConfirmGlobalStatus,
 *                     WdgM_ConfirmSELocalStatus,WdgM_InitSEStatus,WdgM_MainFunction
 * REQ ID              DD_2_267
 */
/**************************************************************/
static FUNC(uint16, WDGM_CODE) WdgM_GetSupervisedEntityTabIndex(WdgM_SupervisedEntityIdType CerSEID)
{
    uint16 tabindex;

    for (tabindex = 0; tabindex < WDGM_SE_NUM; tabindex++)
    {
        if (CerSEID == WdgM_SupervisedEntityToTabIndex[tabindex])
        {
            break;
        }
    }
    return tabindex;
}

/***************************************************************/
/*
 * Brief               Clear the status of SE that deactivate in the new Mode
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      CerModeCfg: the configuration of new Mode
 *                     SE_Index: The index in the array of the SE configuration
 *                     SEStatusTabIndex : The index in the array of the WdgMSEInfoRelated
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_ChangeSEStatus
 * REQ ID              DD_2_127
 */
/**************************************************************/
static FUNC(void, WDGM_CODE)
    WdgM_SEDeactivateInternal(const WdgM_ModeCfgType* CerModeCfg, uint16 SE_Index, uint16 SEStatusTabIndex)
{
#if ((WDGM_ALIVE_NUM > 0) || (WDGM_DEADLINE_SUP_NUM > 0) || (WDGM_INTLOG_SUP_NUM > 0))
    const WdgM_SECfgType* ModeSEInfo;
    uint16 Tab_Index;
    uint16 Index;
#endif /*WDGM_ALIVE_NUM or WDGM_DEADLINE_SUP_NUM or WDGM_INTLOG_SUP_NUM*/

    WdgMSEInfoRelated[SEStatusTabIndex].WdgMFailedAliveSupCounter = 0;
    WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_ALIVE_SUP] = WDGM_CORRECT;
    WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_DEADLINE_SUP] = WDGM_CORRECT;
    WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_INTLOG_SUP] = WDGM_CORRECT;
    WdgMSEInfoRelated[SEStatusTabIndex].WdgMEachSupResult[WDGM_EXTLOG_SUP] = WDGM_CORRECT;

#if ((WDGM_ALIVE_NUM > 0) || (WDGM_DEADLINE_SUP_NUM > 0) || (WDGM_INTLOG_SUP_NUM > 0))
    ModeSEInfo = (const WdgM_SECfgType*)&CerModeCfg->WdgMSERelated[SE_Index];
#endif /*WDGM_ALIVE_NUM or WDGM_DEADLINE_SUP_NUM or WDGM_INTLOG_SUP_NUM*/

#if (WDGM_ALIVE_NUM > 0)
    if ((uint16)0 < ModeSEInfo->SEAliveCnt)
    {
        for (Index = 0; Index < ModeSEInfo->SEAliveCnt; Index++)
        {
            Tab_Index = ModeSEInfo->WdgMAliveSupCfg[Index].WdgMAliveSupID;
            WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveCycleCounter = 0;
            WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveIndicationCounter = 0;
            WdgM_AliveSupInfoTab[Tab_Index].WdgMAliveSupResult = WDGM_CORRECT;
        }
    }
#endif /*WDGM_ALIVE_NUM > 0*/

#if (WDGM_DEADLINE_SUP_NUM > 0)
    if ((uint16)0 < ModeSEInfo->SEDealineCnt)
    {
        for (Index = 0; Index < ModeSEInfo->SEDealineCnt; Index++)
        {
            Tab_Index = ModeSEInfo->WdgMDeadlineSupCfg[Index].WdgMDeadlineSupID;
            WdgM_DeadlineSupInfoTab[Tab_Index].WdgMTimeStampStart = 0;
            WdgM_DeadlineSupInfoTab[Tab_Index].WdgMDeadlineSupResult = WDGM_CORRECT;
        }
    }
#endif /*WDGM_DEADLINE_SUP_NUM > 0*/

#if (WDGM_INTLOG_SUP_NUM > 0)
    if ((uint16)0 < ModeSEInfo->SEIntLogCnt)
    {
        Tab_Index = ModeSEInfo->WdgMIntLogSupCfg[0].WdgMIntLogSupID;
        WdgM_IntLogSupInfoTab[Tab_Index].WdgMIntLogActiveFlag = WDGM_AF_FALSE;
        WdgM_IntLogSupInfoTab[Tab_Index].WdgMIntLastReachedCPID = WDGM_NO_CP_REACH;
        WdgM_IntLogSupInfoTab[Tab_Index].WdgMIntLogSupResult = WDGM_CORRECT;
    }
#endif /*WDGM_INTLOG_SUP_NUM > 0*/
}

#if (STD_ON == WDGM_DEV_ERROR_DETECT)
/***************************************************************/
/*
 * Brief               confirm whether the Mode ID in the configuration
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ModeID: the Mode ID
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_NOT_OK,E_OK
 * CallByAPI           WdgM_SetMode
 * REQ ID              DD_2_173
 */
/**************************************************************/
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_ModeExistenceConfirmation(WdgM_ModeType ModeID)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 Index;
    uint8 IndexMax = WdgMConfig->WdgM_ModeCnt;

    for (Index = 0; Index < IndexMax; Index++)
    {
        if (ModeID == WdgMConfig->WdgMMode[Index].WdgMModeID)
        {
            l_ReturnValue = E_OK;
            break;
        }
    }
    return l_ReturnValue;
}

/***************************************************************/
/*
 * Brief               Confirm whether contain the OFF MODE
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ConfigPtr :
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: Success
 *                     E_NOT_OK: failure
 * CallByAPI           WdgM_Init
 * REQ ID              DD_2_147
 */
/**************************************************************/
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_InitModeConfirmation(const WdgM_ConfigType* ConfigPtr)
{
    Std_ReturnType l_ReturnValue;

    /*Whether the address of the  initial Mode */
    if (ConfigPtr == &(WdgMConfigRoot[0]))
    {
        l_ReturnValue = E_OK;
    }
    else
    {
        l_ReturnValue = E_NOT_OK;
    }
    return l_ReturnValue;
}

#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/

#if (STD_OFF == WDGM_OFF_MODE_EABLED)
/***************************************************************/
/*
 * Brief               Set Trigger condition
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      None
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              None
 * CallByAPI           WdgM_SetMode
 * REQ ID              DD_2_174
 */
/**************************************************************/
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_OffModeConfirmationForRequestMode(WdgM_ModeType ModeID)
{

    Std_ReturnType l_ReturnValue = E_OK;
    uint8 triggerIndex = 0;
    uint8 triggerIndexMax = WdgMConfig->WdgMMode[ModeID].ModeTriggerCnt;

    /*Trigger quantities in certain Mode*/
    for (triggerIndex = 0; triggerIndex < triggerIndexMax; triggerIndex++)
    {
        if (WDGIF_OFF_MODE == WdgMConfig->WdgMMode[ModeID].WdgMTriggerRelated[triggerIndex].WdgMWatchdogMode)
        {
            l_ReturnValue = E_NOT_OK;
            break;
        }
    }

    return l_ReturnValue;
}

#if (STD_ON == WDGM_DEV_ERROR_DETECT)
/***************************************************************/
/*
 * Brief               Confirm whether contain the OFF MODE
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      ConfigPtr :
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              E_OK: Success
 *                     E_NOT_OK: failure
 * CallByAPI           WdgM_Init
 * REQ ID              DD_2_178
 */
/**************************************************************/
static FUNC(Std_ReturnType, WDGM_CODE) WdgM_OffModeConfirmation(const WdgM_ConfigType* ConfigPtr)
{
    Std_ReturnType l_ReturnValue = E_NOT_OK;
    uint8 triggerIndex = 0;

    /****************************************/
    if ((uint8)0 == ConfigPtr->WdgM_ModeCnt)
    {
        l_ReturnValue = E_OK;
    }
    else
    {
        /*Trigger quantities in each Mode*/
        l_ReturnValue = E_OK;
        for (triggerIndex = 0; triggerIndex < ConfigPtr->WdgMMode[ConfigPtr->WdgMInitialModeId].ModeTriggerCnt;
             triggerIndex++)
        {
            if (WDGIF_OFF_MODE
                == ConfigPtr->WdgMMode[ConfigPtr->WdgMInitialModeId].WdgMTriggerRelated[triggerIndex].WdgMWatchdogMode)
            {
                l_ReturnValue = E_NOT_OK;
                break;
            }
        }
    }
    return l_ReturnValue;
}

#endif /*STD_ON == WDGM_DEV_ERROR_DETECT*/

#endif /*STD_OFF == WDGM_OFF_MODE_EABLED*/

#endif /*WDGM_SE_NUM > 0*/

/***************************************************************/
/*
 * Brief               Get the bit value in the word
 * ServiceId           None
 * Sync/Async          synchronous
 * Reentrancy          Reentrant
 * Param-Name[in]      WordNum: Word Value
 *                     GetBit : Bit Position
 * Param-Name[out]     None
 * Param-Name[in/out]  None
 * Return              1 : this bit value is 1; 0: this bit value is 0
 * CallByAPI           WdgM_SetMode
 * REQ ID              DD_2_264
 */
/**************************************************************/
static FUNC(uint8, WDGM_CODE) WdgM_GetWordBitState(uint16 WordNum, uint8 GetBit)
{
    uint8 bitvalue;

    if ((uint16)0U != (WordNum & (uint16)((uint16)0x0001U << GetBit)))
    {
        bitvalue = 1;
    }
    else
    {
        bitvalue = 0;
    }
    return bitvalue;
}

#define WDGM_STOP_SEC_CODE
#include "WdgM_MemMap.h"
/* PRQA S 3200 --*/ /* MISAR Rule-17.7 */
/* PRQA S 3335 --*/ /* MISAR Rule-17.3 */
/* PRQA S 4434 --*/ /* MISAR Rule-10.3 */
/* PRQA S 1503 --*/ /* MISAR Rule-2.1 */
/*=======[M I S R A C  R U L E  V I O L A T I O N]============================*/
/*  <MESSAGE ID>    <CODE LINE>    <REASON>
 *  ISOFT_026        2524          The input parameter shall be enumerated by OS,
 *                                 then use the enumeration here.
 *
 */
/*============================================================================*/
