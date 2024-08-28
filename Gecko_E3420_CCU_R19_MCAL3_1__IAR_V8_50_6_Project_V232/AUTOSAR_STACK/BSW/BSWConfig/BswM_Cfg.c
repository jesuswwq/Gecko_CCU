
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
**  FILENAME    : BswM_Cfg.c                                                  **
**                                                                            **
**  Created on  : 2024/06/13 09:29:26                                         **
**  Author      :                                                              **
**  Vendor      :                                                             **
**  DESCRIPTION : pre-compile configure parameter definitions of BSWM         **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "BswM_Internal.h"

/* BswMConfig*/

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(NvM_RequestResultType, BSWM_CONST) BswM_NvmInitStatus_Core0_Par0 = NVM_REQ_PENDING;
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_ModeRqstPortPCCfgType, BSWM_CONST) BswM_ModeRqstSrc_Core0_Par0 =
{
    6u,    /*numOfCanSMInd*/
    NULL_PTR,
    2u,    /*numOfComMInd*/
    NULL_PTR,
    1u,    /*numOfDcmComModeReq*/
    NULL_PTR,
    0u,    /*numOfEcuMWakeupSource*/
    NULL_PTR,
    0u,    /*numOfEcuMRUNRequestIndications*/
    NULL_PTR,
    5u,    /*numOfGenericReq*/
    NULL_PTR,
    3u,    /*numOfLinSMInd*/
    NULL_PTR,
    0u,    /*numOfLinSchInd*/
    2u,    /*numOfNvMJob*/
    &BswM_NvmInitStatus_Core0_Par0,    /*nvmJobInitMode*/
    0u,    /*numOfNvMBlock*/
    NULL_PTR,
    3u,    /*numOfBswMTimer*/
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(CanSM_BswMCurrentStateType, BSWM_VAR_CLEARED) BswM_CanSMIndicationStatus_Core0_Par0[6u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(ComM_ModeType, BSWM_VAR_CLEARED) BswM_ComMIndicationStatus_Core0_Par0[2u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(Dcm_CommunicationModeType, BSWM_VAR_CLEARED) BswM_DcmComModeRequestStatus_Core0_Par0[1u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(uint16, BSWM_VAR_CLEARED) BswM_GenericRequestStatus_Core0_Par0[5u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(LinSM_ModeType, BSWM_VAR_CLEARED) BswM_LinSMIndicationStatus_Core0_Par0[3u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(NvM_RequestResultType, BSWM_VAR_CLEARED) BswM_NvMJobModeIndication_Core0_Par0[2u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(BswM_TimerEnumType, BSWM_VAR_CLEARED) BswM_Timer_Core0_Par0[3u];
static VAR(uint32, BSWM_VAR_CLEARED) BswM_TimerCycle_Core0_Par0[3u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_INIT_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(BswM_ModeRqstPortRuntimeType, BSWM_VAR_CLEARED) BswM_ModeRqstSrcSatus_Core0_Par0 =
{
    &(BswM_CanSMIndicationStatus_Core0_Par0[0u]),    /*BswMCanSMIndication*/
    &(BswM_ComMIndicationStatus_Core0_Par0[0u]),    /*BswMComMIndication*/
    &(BswM_DcmComModeRequestStatus_Core0_Par0[0u]),    /*BswMDcmComModeRequest*/
    NULL_PTR,    /*BswMEcuMWakeupSource*/
    NULL_PTR,    /*bswMEcuMRUNRequestIndications*/
    &(BswM_GenericRequestStatus_Core0_Par0[0u]),    /*BswMGenericRequest*/
    &(BswM_LinSMIndicationStatus_Core0_Par0[0u]),    /*BswMLinSMIndication*/
    NULL_PTR,    /*BswMLinScheduleIndication*/
    &(BswM_NvMJobModeIndication_Core0_Par0[0u]),    /*BswMNvMJobModeIndication*/
    NULL_PTR,    /*BswMNvMRequest*/
    &(BswM_Timer_Core0_Par0[0u]),    /*BswMTimer*/
    &(BswM_TimerCycle_Core0_Par0[0u]),    /*BswMTimerCycle*/
};
#define BSWM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"
static VAR(Com_IpduGroupVector, BSWM_VAR_CLEARED) BswM_ComIpduGroup_Ctrl[3u];
#define BSWM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_PartitionPCCfgType, BSWM_CONST) BswM_PartitionPCCfg_Core0[1u] =
{
    {
        0u,    /*evRqstSrcNum*/
        NULL_PTR,
        &BswM_ModeRqstSrc_Core0_Par0,    /*modeRqstPCCfg*/
        NULL_PTR,
        &BswM_ModeRqstSrcSatus_Core0_Par0,    /*modeRqstPortRunPtr*/
        &(BswM_ComIpduGroup_Ctrl[0u]),    /*comRxDmIpduGroupVector*/
        &(BswM_ComIpduGroup_Ctrl[1u]),    /*ipduGroupReinitVecotr*/
        &(BswM_ComIpduGroup_Ctrl[2u]),    /*ipduGroupAllVecotr*/
    },
};
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"

#define BSWM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "BswM_MemMap.h"
static CONST(BswM_PCCfgType, BSWM_CONST) BswM_PCCfg[1u] =
{
    {
        /* numOfPartitions */
        1U,
        /* bswmPartPCCfgs */
        &(BswM_PartitionPCCfg_Core0[0u]),
    },
};
#define BSWM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "BswM_MemMap.h"

/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
#define BSWM_START_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
CONSTP2CONST(BswM_PCCfgType, BSWM_CONST, BSWM_CONST) BswM_CorePCCfg = &(BswM_PCCfg[0]);
#define BSWM_STOP_SEC_CONST_UNSPECIFIED
#include "BswM_MemMap.h"
