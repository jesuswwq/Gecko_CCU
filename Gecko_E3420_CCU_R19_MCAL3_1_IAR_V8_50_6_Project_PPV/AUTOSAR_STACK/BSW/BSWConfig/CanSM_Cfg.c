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
**  FILENAME    : CanSM_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2024/01/10 17:30:22                                         ** 
**  Author      : wanglili                                                    **
**  Vendor      :                                                             **
**  DESCRIPTION : Post-build configuration parameter of CANSM                 **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform R19-11                      **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*******************************************************************************
**                      Imported Compiler Switch Check                        **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*=======[I N C L U D E S]====================================================*/
#include "CanSM_Cfg.h"
#include "CanSM.h"
#include "CanIf_Cfg.h"
#include "ComM_Cfg.h"
#include "Dem.h"
/*******************************************************************************
**                       Version  Check                                       **
*******************************************************************************/
/*******************************************************************************
**                      Private Macro Definitions                             **
*******************************************************************************/
/*******************************************************************************
**                      Private Type Definitions                              **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Declarations                         **
*******************************************************************************/
/*******************************************************************************
**                      Private Variable Definitions                          **
*******************************************************************************/
#define CANSM_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanSM_MemMap.h"

static CONST(uint8, CANSM_CONST) CanSM_MN_0ControllerId[1] = {CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA};/*CanSMControllerId*/
static CONST(uint8, CANSM_CONST) CanSM_MN_1ControllerId[1] = {CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_XCP};/*CanSMControllerId*/
static CONST(uint8, CANSM_CONST) CanSM_MN_2ControllerId[1] = {CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD4_BOD};/*CanSMControllerId*/
static CONST(uint8, CANSM_CONST) CanSM_MN_3ControllerId[1] = {CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT};/*CanSMControllerId*/
static CONST(uint8, CANSM_CONST) CanSM_MN_4ControllerId[1] = {CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD};/*CanSMControllerId*/
static CONST(uint8, CANSM_CONST) CanSM_MN_5ControllerId[1] = {CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC};/*CanSMControllerId*/

static CONST(CanSM_ControllerRefType, CANSM_CONST) CanSM_ControllerConfig[CANSM_NETWORK_NUM] =
{
    {
        0x1,
        &CanSM_MN_0ControllerId[0]
    },
    {
        0x1,
        &CanSM_MN_1ControllerId[0]
    },
    {
        0x1,
        &CanSM_MN_2ControllerId[0]
    },
    {
        0x1,
        &CanSM_MN_3ControllerId[0]
    },
    {
        0x1,
        &CanSM_MN_4ControllerId[0]
    },
    {
        0x1,
        &CanSM_MN_5ControllerId[0]
    },
};

static Dem_EventIdType CanSM_ManagerNetwork_CANFD3_DemEvtBusOff = DemEventParameter_0xC06488;
static Dem_EventIdType CanSM_ManagerNetwork_CANFD5_DemEvtBusOff = DemEventParameter_0xC05588;
static Dem_EventIdType CanSM_ManagerNetwork_CANFD6_DemEvtBusOff = DemEventParameter_0xC04688;
static Dem_EventIdType CanSM_ManagerNetwork_CANFD8_DemEvtBusOff = DemEventParameter_0xC07388;

static CONST(CanSM_DemEventParameterRefType, CANSM_CONST) CanSM_DemEventParameter [4] =
{
    {
        &CanSM_ManagerNetwork_CANFD3_DemEvtBusOff,     /*CANSM_E_BUS_OFF */
        NULL_PTR,     /*CANSM_E_MODE_REQUEST_TIMEOUT */
    },
    {
        &CanSM_ManagerNetwork_CANFD5_DemEvtBusOff,     /*CANSM_E_BUS_OFF */
        NULL_PTR,     /*CANSM_E_MODE_REQUEST_TIMEOUT */
    },
    {
        &CanSM_ManagerNetwork_CANFD6_DemEvtBusOff,     /*CANSM_E_BUS_OFF */
        NULL_PTR,     /*CANSM_E_MODE_REQUEST_TIMEOUT */
    },
    {
        &CanSM_ManagerNetwork_CANFD8_DemEvtBusOff,     /*CANSM_E_BUS_OFF */
        NULL_PTR,     /*CANSM_E_MODE_REQUEST_TIMEOUT */
    },
};

static CONST(CanSM_ManagerNetworkType, CANSM_CONST) CanSM_NetworkConfig [CANSM_NETWORK_NUM] =
{
    {
        0x5,    /*CanSMBorCounterL1ToL2 */
        0x32,           /*CanSMBorTimeL1 */
        0xc8,           /*CanSMBorTimeL2 */
        0x1e,           /*CanSMBorTimeTxEnsured */
        FALSE,          /*CanSMBorTxConfirmationPolling */
        FALSE,          /*CanSMEnableBusOffDelay */
        Channel_CANFD3,                        /*CanSMComMNetworkHandleRef*/
        NULL_PTR,
        &CanSM_ControllerConfig[0],
        &CanSM_DemEventParameter[0]
    },
    {
        0x5,    /*CanSMBorCounterL1ToL2 */
        0x32,           /*CanSMBorTimeL1 */
        0xc8,           /*CanSMBorTimeL2 */
        0x1e,           /*CanSMBorTimeTxEnsured */
        FALSE,          /*CanSMBorTxConfirmationPolling */
        FALSE,          /*CanSMEnableBusOffDelay */
        Channel_CANFD4,                        /*CanSMComMNetworkHandleRef*/
        NULL_PTR,
        &CanSM_ControllerConfig[1],

    },
    {
        0x5,    /*CanSMBorCounterL1ToL2 */
        0x32,           /*CanSMBorTimeL1 */
        0xc8,           /*CanSMBorTimeL2 */
        0x32,           /*CanSMBorTimeTxEnsured */
        FALSE,          /*CanSMBorTxConfirmationPolling */
        FALSE,          /*CanSMEnableBusOffDelay */
        Channel_CANFD5,                        /*CanSMComMNetworkHandleRef*/
        NULL_PTR,
        &CanSM_ControllerConfig[2],
        &CanSM_DemEventParameter[1]
    },
    {
        0x5,    /*CanSMBorCounterL1ToL2 */
        0x32,           /*CanSMBorTimeL1 */
        0xc8,           /*CanSMBorTimeL2 */
        0x1e,           /*CanSMBorTimeTxEnsured */
        FALSE,          /*CanSMBorTxConfirmationPolling */
        FALSE,          /*CanSMEnableBusOffDelay */
        Channel_CANFD6,                        /*CanSMComMNetworkHandleRef*/
        NULL_PTR,
        &CanSM_ControllerConfig[3],
        &CanSM_DemEventParameter[2]
    },
    {
        0x5,    /*CanSMBorCounterL1ToL2 */
        0x32,           /*CanSMBorTimeL1 */
        0xc8,           /*CanSMBorTimeL2 */
        0x1e,           /*CanSMBorTimeTxEnsured */
        FALSE,          /*CanSMBorTxConfirmationPolling */
        FALSE,          /*CanSMEnableBusOffDelay */
        Channel_CANFD7,                        /*CanSMComMNetworkHandleRef*/
        NULL_PTR,
        &CanSM_ControllerConfig[4],

    },
    {
        0x5,    /*CanSMBorCounterL1ToL2 */
        0x32,           /*CanSMBorTimeL1 */
        0xc8,           /*CanSMBorTimeL2 */
        0x1e,           /*CanSMBorTimeTxEnsured */
        FALSE,          /*CanSMBorTxConfirmationPolling */
        FALSE,          /*CanSMEnableBusOffDelay */
        Channel_CANFD8,                        /*CanSMComMNetworkHandleRef*/
        NULL_PTR,
        &CanSM_ControllerConfig[5],
        &CanSM_DemEventParameter[3]
    },
};

CONST(CanSM_ConfigType, CANSM_CONST) CanSM_Config =  /* PRQA S 1531 */ /* MISRA Rule 8.7 */
{
    0xa,    /*CanSMModeRequestRepetitionMax */
    0xa,    /*CanSMModeRequestRepetitionTime */
    &CanSM_NetworkConfig[0]
};

#define CANSM_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanSM_MemMap.h"
/*******************************************************************************
**                      Global Variable Definitions                          **
*******************************************************************************/
/*******************************************************************************
**                      Global Function Definitions                           **
*******************************************************************************/
/*******************************************************************************
**                      Private Function Definitions                          **
*******************************************************************************/
