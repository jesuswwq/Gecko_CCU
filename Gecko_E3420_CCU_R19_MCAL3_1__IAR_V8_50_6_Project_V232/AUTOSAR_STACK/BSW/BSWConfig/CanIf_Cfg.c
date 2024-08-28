
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
**  FILENAME    : CanIf_Cfg.c                                                 **
**                                                                            **
**  Created on  : 2024/03/14 21:38:08                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION :parameter declaration of CanIf                               **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define CANIF_CFG_C_AR_MAJOR_VERSION  4u
#define CANIF_CFG_C_AR_MINOR_VERSION  2u
#define CANIF_CFG_C_AR_PATCH_VERSION  2u
#define CANIF_CFG_C_SW_MAJOR_VERSION  2u
#define CANIF_CFG_C_SW_MINOR_VERSION  0u
#define CANIF_CFG_C_SW_PATCH_VERSION  0u

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf.h"
#include "CanSM_Cbk.h"
#include "EcuM_Cbk.h"
#include "XcpOnCan_Cbk.h"
#include "CanNm_Cbk.h"
#include "PduR_CanIf.h"
#include "CanTp_Cbk.h"
#include "CanTp.h"
#include "Can.h"
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (CANIF_CFG_C_AR_MAJOR_VERSION != CANIF_CFG_H_AR_MAJOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Major Version"
#endif

#if (CANIF_CFG_C_AR_MINOR_VERSION != CANIF_CFG_H_AR_MINOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Minor Version"
#endif

#if (CANIF_CFG_C_AR_PATCH_VERSION != CANIF_CFG_H_AR_PATCH_VERSION)
    #error "CanIf.c:Mismatch in Specification Patch Version"
#endif

#if (CANIF_CFG_C_SW_MAJOR_VERSION != CANIF_CFG_H_SW_MAJOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Major Version"
#endif

#if (CANIF_CFG_C_SW_MINOR_VERSION != CANIF_CFG_H_SW_MINOR_VERSION)
    #error "CanIf.c:Mismatch in Specification Minor Version"
#endif

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
CONST(CanIf_DispatchConfigType,CANIF_CONST) CanIf_DispatchConfigData =
/* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
{
    /* void XXX_ControllerBusOff(uint8 ControllerId) */
    &CanSM_ControllerBusOff,
    /* void XXX_ControllerModeIndication(uint8 ControllerId,CanIf_ControllerModeType ControllerMode)  */
    &CanSM_ControllerModeIndication,
    /* void XXX_TransceiverModeIndication(uint8 TransceiverId,CanTrcv_TrcvModeType TransceiverMode) */
    NULL_PTR,
    /* void XXX_ValidateWakeupEvent(EcuM_WakeupSourceType sources)*/
    &EcuM_ValidateWakeupEvent,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
CONST(Can_DriverApiType,CANIF_CONST_PBCFG) Can_DriverApi[CANIF_CANDRIVER_NUMBER] =
/* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
{
    {
        &Can_SetControllerMode,
        &Can_Write,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfCtrlCanCtrlRefType,CANIF_CONST_PBCFG) CanIf_CtrlRef[CANIF_CANCONTROLLER_NUMBER] =
{
    {
        0u,EcuMWakeupSource_CHA
    },
    {
        1u,0u|0u
    },
    {
        2u,EcuMWakeupSource_BOD
    },
    {
        3u,EcuMWakeupSource_EPT
    },
    {
        4u,0u|0u
    },
    {
        5u,EcuMWakeupSource_BAC
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIf_ControllerCfgType,CANIF_CONST) CanIf_CtrlCfgData[CANIF_CANCONTROLLER_NUMBER] =
{
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA,
        CANIF_CAN,
        FALSE,
        &CanIf_CtrlRef[0],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD4_XCP,
        CANIF_CAN,
        FALSE,
        &CanIf_CtrlRef[1],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,
        CANIF_CAN,
        FALSE,
        &CanIf_CtrlRef[2],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,
        CANIF_CAN,
        FALSE,
        &CanIf_CtrlRef[3],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,
        CANIF_CAN,
        FALSE,
        &CanIf_CtrlRef[4],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC,
        CANIF_CAN,
        FALSE,
        &CanIf_CtrlRef[5],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfHrhIdSymRefType,CANIF_CONST_PBCFG) CanIf_HrhRef[CANIF_HRH_NUMBER] =
{
    {
        11u,
        CANIF_FULL_CAN,
    },
    {
        32u,
        CANIF_BASIC_CAN,
    },
    {
        87u,
        CANIF_BASIC_CAN,
    },
    {
        6u,
        CANIF_BASIC_CAN,
    },
    {
        13u,
        CANIF_BASIC_CAN,
    },
    {
        16u,
        CANIF_FULL_CAN,
    },
    {
        29u,
        CANIF_FULL_CAN,
    },
    {
        28u,
        CANIF_FULL_CAN,
    },
    {
        30u,
        CANIF_FULL_CAN,
    },
    {
        25u,
        CANIF_FULL_CAN,
    },
    {
        15u,
        CANIF_FULL_CAN,
    },
    {
        17u,
        CANIF_FULL_CAN,
    },
    {
        14u,
        CANIF_FULL_CAN,
    },
    {
        26u,
        CANIF_FULL_CAN,
    },
    {
        27u,
        CANIF_FULL_CAN,
    },
    {
        34u,
        CANIF_FULL_CAN,
    },
    {
        35u,
        CANIF_FULL_CAN,
    },
    {
        36u,
        CANIF_FULL_CAN,
    },
    {
        37u,
        CANIF_FULL_CAN,
    },
    {
        33u,
        CANIF_FULL_CAN,
    },
    {
        38u,
        CANIF_FULL_CAN,
    },
    {
        39u,
        CANIF_FULL_CAN,
    },
    {
        40u,
        CANIF_FULL_CAN,
    },
    {
        41u,
        CANIF_FULL_CAN,
    },
    {
        42u,
        CANIF_FULL_CAN,
    },
    {
        43u,
        CANIF_FULL_CAN,
    },
    {
        44u,
        CANIF_FULL_CAN,
    },
    {
        45u,
        CANIF_FULL_CAN,
    },
    {
        46u,
        CANIF_FULL_CAN,
    },
    {
        60u,
        CANIF_FULL_CAN,
    },
    {
        56u,
        CANIF_FULL_CAN,
    },
    {
        58u,
        CANIF_FULL_CAN,
    },
    {
        57u,
        CANIF_FULL_CAN,
    },
    {
        59u,
        CANIF_FULL_CAN,
    },
    {
        61u,
        CANIF_FULL_CAN,
    },
    {
        50u,
        CANIF_FULL_CAN,
    },
    {
        51u,
        CANIF_FULL_CAN,
    },
    {
        52u,
        CANIF_FULL_CAN,
    },
    {
        53u,
        CANIF_FULL_CAN,
    },
    {
        54u,
        CANIF_FULL_CAN,
    },
    {
        55u,
        CANIF_FULL_CAN,
    },
    {
        18u,
        CANIF_FULL_CAN,
    },
    {
        19u,
        CANIF_FULL_CAN,
    },
    {
        20u,
        CANIF_FULL_CAN,
    },
    {
        21u,
        CANIF_FULL_CAN,
    },
    {
        22u,
        CANIF_FULL_CAN,
    },
    {
        23u,
        CANIF_FULL_CAN,
    },
    {
        24u,
        CANIF_FULL_CAN,
    },
    {
        47u,
        CANIF_FULL_CAN,
    },
    {
        48u,
        CANIF_FULL_CAN,
    },
    {
        49u,
        CANIF_FULL_CAN,
    },
    {
        63u,
        CANIF_FULL_CAN,
    },
    {
        64u,
        CANIF_FULL_CAN,
    },
    {
        65u,
        CANIF_FULL_CAN,
    },
    {
        66u,
        CANIF_FULL_CAN,
    },
    {
        67u,
        CANIF_FULL_CAN,
    },
    {
        68u,
        CANIF_FULL_CAN,
    },
    {
        69u,
        CANIF_FULL_CAN,
    },
    {
        70u,
        CANIF_FULL_CAN,
    },
    {
        71u,
        CANIF_FULL_CAN,
    },
    {
        72u,
        CANIF_FULL_CAN,
    },
    {
        73u,
        CANIF_FULL_CAN,
    },
    {
        74u,
        CANIF_FULL_CAN,
    },
    {
        75u,
        CANIF_FULL_CAN,
    },
    {
        76u,
        CANIF_FULL_CAN,
    },
    {
        77u,
        CANIF_FULL_CAN,
    },
    {
        78u,
        CANIF_FULL_CAN,
    },
    {
        79u,
        CANIF_FULL_CAN,
    },
    {
        80u,
        CANIF_FULL_CAN,
    },
    {
        81u,
        CANIF_FULL_CAN,
    },
    {
        82u,
        CANIF_FULL_CAN,
    },
    {
        83u,
        CANIF_FULL_CAN,
    },
    {
        84u,
        CANIF_FULL_CAN,
    },
    {
        85u,
        CANIF_FULL_CAN,
    },
    {
        94u,
        CANIF_BASIC_CAN,
    },
    {
        88u,
        CANIF_FULL_CAN,
    },
    {
        89u,
        CANIF_FULL_CAN,
    },
    {
        90u,
        CANIF_FULL_CAN,
    },
    {
        91u,
        CANIF_FULL_CAN,
    },
    {
        92u,
        CANIF_FULL_CAN,
    },
    {
        93u,
        CANIF_FULL_CAN,
    },
    {
        7u,
        CANIF_BASIC_CAN,
    },
    {
        0u,
        CANIF_BASIC_CAN,
    },
    {
        3u,
        CANIF_BASIC_CAN,
    },
    {
        1u,
        CANIF_BASIC_CAN,
    },
    {
        5u,
        CANIF_BASIC_CAN,
    },
    {
        2u,
        CANIF_BASIC_CAN,
    },
    {
        8u,
        CANIF_BASIC_CAN,
    },
    {
        9u,
        CANIF_BASIC_CAN,
    },
    {
        4u,
        CANIF_FULL_CAN,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef0[1] =
{
    CANIF_RXPDU_TMSR_DTO_XCP,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef1[1] =
{
    CANIF_RXPDU_CanNm_CAN2_CANFD6_RX,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef2[1] =
{
    CANIF_RXPDU_CanNm_CAN1_CANFD8_RX,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef3[1] =
{
    CANIF_RXPDU_CanNm_CAN5_CANFD3_RX,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef4[1] =
{
    CANIF_RXPDU_CanNm_CAN6_CANFD5_RX,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef5[1] =
{
    CANIF_RXPDU_CCP_PanelStatus_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef6[1] =
{
    CANIF_RXPDU_SCS_RiSwitchSts_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef7[1] =
{
    CANIF_RXPDU_SCS_LeSwitchSts_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef8[1] =
{
    CANIF_RXPDU_TPMS_Info_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef9[1] =
{
    CANIF_RXPDU_ESCL_ESCLStatus_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef10[1] =
{
    CANIF_RXPDU_AVAS_State_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef11[1] =
{
    CANIF_RXPDU_COMP_AC_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef12[1] =
{
    CANIF_RXPDU_ACCM_Version_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef13[1] =
{
    CANIF_RXPDU_HVCH_Status1_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef14[1] =
{
    CANIF_RXPDU_HVCH_Status2_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef15[1] =
{
    CANIF_RXPDU_BMS_1_MainState_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef16[1] =
{
    CANIF_RXPDU_BMS_2_BatState_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef17[1] =
{
    CANIF_RXPDU_BMS_3_DC_ChargeState_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef18[1] =
{
    CANIF_RXPDU_BMS_4_AC_ChargeState_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef19[1] =
{
    CANIF_RXPDU_BMS_10_DC_ChargeStates_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef20[1] =
{
    CANIF_RXPDU_BMS_5_BatTemp_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef21[1] =
{
    CANIF_RXPDU_BMS_6_DischrgRecup_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef22[1] =
{
    CANIF_RXPDU_BMS_7_CellVolt_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef23[1] =
{
    CANIF_RXPDU_BMS_8_TempVoltLimit_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef24[1] =
{
    CANIF_RXPDU_BMS_9_BattInfo_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef25[1] =
{
    CANIF_RXPDU_BMS_A_GB_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef26[1] =
{
    CANIF_RXPDU_BMS_B_GB_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef27[1] =
{
    CANIF_RXPDU_BMS_C_GB_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef28[1] =
{
    CANIF_RXPDU_BMS_D_GB_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef29[1] =
{
    CANIF_RXPDU_IPU_OBC_3_CP_CC_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef30[1] =
{
    CANIF_RXPDU_IPU_DCC_1_State_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef31[1] =
{
    CANIF_RXPDU_IPU_OBC_1_State_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef32[1] =
{
    CANIF_RXPDU_IPU_DCC_2_ChrgInValue_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef33[1] =
{
    CANIF_RXPDU_IPU_OBC_2_Inlet_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef34[1] =
{
    CANIF_RXPDU_IPU_OBC_4_state_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef35[1] =
{
    CANIF_RXPDU_INV_1_Value_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef36[1] =
{
    CANIF_RXPDU_INV_2_Value_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef37[1] =
{
    CANIF_RXPDU_INV_3_Value_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef38[1] =
{
    CANIF_RXPDU_INV_4_Value_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef39[1] =
{
    CANIF_RXPDU_INV_5_Values_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef40[1] =
{
    CANIF_RXPDU_INV_IMMO_Req_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef41[1] =
{
    CANIF_RXPDU_CANIF_Diag_Resp_ACCM_RX_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef42[1] =
{
    CANIF_RXPDU_CANIF_Diag_Resp_AVAS_RX_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef43[1] =
{
    CANIF_RXPDU_CANIF_Diag_Resp_CCP_RX_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef44[1] =
{
    CANIF_RXPDU_CANIF_Diag_Resp_ESCL_RX_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef45[1] =
{
    CANIF_RXPDU_CANIF_Diag_Resp_PTC_RX_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef46[1] =
{
    CANIF_RXPDU_CANIF_Diag_Resp_SCS_RX_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef47[1] =
{
    CANIF_RXPDU_CANIF_Diag_Resp_TPMS_RX_BOD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef48[1] =
{
    CANIF_RXPDU_CANIF_Diag_Resp_BMS_RX_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef49[1] =
{
    CANIF_RXPDU_CANIF_Diag_Resp_IPUDCC_RX_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef50[1] =
{
    CANIF_RXPDU_CANIF_Diag_Resp_MCU_RX_EPT,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef51[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CCU_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef52[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_MCU_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef53[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_BMS_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef54[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_IPUDCC_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef55[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PTC_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef56[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SCS_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef57[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CCP_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef58[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_AVAS_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef59[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESCL_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef60[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ACCM_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef61[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_TPMS_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef62[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CDCICU_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef63[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESC_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef64[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EHB_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef65[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EPS_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef66[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PP_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef67[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FCM_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef68[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FRM_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef69[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRL_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef70[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRR_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef71[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SRS_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef72[1] =
{
    CANIF_RXPDU_CANIF_RX_Diag_FuncReq_OBD,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef73[22] =
{
    CANIF_RXPDU_CANIF_RX_Diag_FuncReq_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ACCM_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_AVAS_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_BMS_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CCP_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_Resp_CDCICU_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRL_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRR_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EHB_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EPS_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESC_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESCL_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FCM_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FRM_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_IPUDCC_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_MCU_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PP_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PTC_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SCS_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SRS_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_TPMS_BAC,
    CANIF_RXPDU_CANIF_RX_Diag_PhyReq_BAC,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef74[1] =
{
    CANIF_RXPDU_HU_A_BAC,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef75[1] =
{
    CANIF_RXPDU_HU_B_BAC,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef76[1] =
{
    CANIF_RXPDU_HU_C_BAC,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef77[1] =
{
    CANIF_RXPDU_ICU_2_Odo_BAC,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef78[1] =
{
    CANIF_RXPDU_ICU_Info_BAC,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef79[1] =
{
    CANIF_RXPDU_TBOX_BJS_Time_BAC,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef80[5] =
{
    CANIF_RXPDU_ESC_WheelPulseTime_CHA,
    CANIF_RXPDU_SRS_2_YRSOriginalSts_CHA,
    CANIF_RXPDU_SRS_3_YRSActualSts_CHA,
    CANIF_RXPDU_EPS_3_LatDrvAndEPSSts_CHA,
    CANIF_RXPDU_EPS_2_StrWhlAng_CHA,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef81[4] =
{
    CANIF_RXPDU_SRS_1_Status_CHA,
    CANIF_RXPDU_EPS_1_Status_CHA,
    CANIF_RXPDU_PP_InformAndStatus_CHA,
    CANIF_RXPDU_CRRR_A_CHA,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef82[4] =
{
    CANIF_RXPDU_FCM_D_CHA,
    CANIF_RXPDU_FCM_B_CHA,
    CANIF_RXPDU_FCM_A_CHA,
    CANIF_RXPDU_EHB_B_CHA,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef83[3] =
{
    CANIF_RXPDU_ESC_A_CHA,
    CANIF_RXPDU_ESC_7_FuncStatus_CHA,
    CANIF_RXPDU_EHB_A_CHA,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef84[2] =
{
    CANIF_RXPDU_FCM_23_Obj0109_CHA,
    CANIF_RXPDU_FCM_ObjTrackID_CHA,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef85[1] =
{
    CANIF_RXPDU_FCM_25_Line123_CHA,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef86[1] =
{
    CANIF_RXPDU_CRRR_10_Posn_CHA,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef87[9] =
{
    CANIF_RXPDU_CANIF_Diag_Resp_CRRL_RX_CHA,
    CANIF_RXPDU_CANIF_Diag_Resp_CRRR_RX_CHA,
    CANIF_RXPDU_CANIF_Diag_Resp_EHB_RX_CHA,
    CANIF_RXPDU_CANIF_Diag_Resp_EPS_RX_CHA,
    CANIF_RXPDU_CANIF_Diag_Resp_ESC_RX_CHA,
    CANIF_RXPDU_CANIF_Diag_Resp_FCM_RX_CHA,
    CANIF_RXPDU_CANIF_Diag_Resp_FRM_RX_CHA,
    CANIF_RXPDU_CANIF_Diag_Resp_PP_RX_CHA,
    CANIF_RXPDU_CANIF_Diag_Resp_SRS_RX_CHA,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(PduIdType,CANIF_CONST) CanIf_HrhRxPduRef88[1] =
{
    CANIF_RXPDU_FCM_24_Obj1018_CHA,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfHrhCfgType,CANIF_CONST) CanIf_HrhCfgData[CANIF_HRH_NUMBER] =
{
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD4_XCP,

        1u,
        &CanIf_HrhRxPduRef0[0],

        &CanIf_HrhRef[0],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef1[0],

        &CanIf_HrhRef[1],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC,

        1u,
        &CanIf_HrhRxPduRef2[0],

        &CanIf_HrhRef[2],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA,

        1u,
        &CanIf_HrhRxPduRef3[0],

        &CanIf_HrhRef[3],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef4[0],

        &CanIf_HrhRef[4],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef5[0],

        &CanIf_HrhRef[5],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef6[0],

        &CanIf_HrhRef[6],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef7[0],

        &CanIf_HrhRef[7],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef8[0],

        &CanIf_HrhRef[8],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef9[0],

        &CanIf_HrhRef[9],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef10[0],

        &CanIf_HrhRef[10],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef11[0],

        &CanIf_HrhRef[11],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef12[0],

        &CanIf_HrhRef[12],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef13[0],

        &CanIf_HrhRef[13],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef14[0],

        &CanIf_HrhRef[14],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef15[0],

        &CanIf_HrhRef[15],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef16[0],

        &CanIf_HrhRef[16],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef17[0],

        &CanIf_HrhRef[17],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef18[0],

        &CanIf_HrhRef[18],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef19[0],

        &CanIf_HrhRef[19],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef20[0],

        &CanIf_HrhRef[20],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef21[0],

        &CanIf_HrhRef[21],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef22[0],

        &CanIf_HrhRef[22],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef23[0],

        &CanIf_HrhRef[23],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef24[0],

        &CanIf_HrhRef[24],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef25[0],

        &CanIf_HrhRef[25],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef26[0],

        &CanIf_HrhRef[26],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef27[0],

        &CanIf_HrhRef[27],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef28[0],

        &CanIf_HrhRef[28],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef29[0],

        &CanIf_HrhRef[29],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef30[0],

        &CanIf_HrhRef[30],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef31[0],

        &CanIf_HrhRef[31],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef32[0],

        &CanIf_HrhRef[32],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef33[0],

        &CanIf_HrhRef[33],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef34[0],

        &CanIf_HrhRef[34],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef35[0],

        &CanIf_HrhRef[35],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef36[0],

        &CanIf_HrhRef[36],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef37[0],

        &CanIf_HrhRef[37],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef38[0],

        &CanIf_HrhRef[38],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef39[0],

        &CanIf_HrhRef[39],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef40[0],

        &CanIf_HrhRef[40],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef41[0],

        &CanIf_HrhRef[41],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef42[0],

        &CanIf_HrhRef[42],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef43[0],

        &CanIf_HrhRef[43],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef44[0],

        &CanIf_HrhRef[44],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef45[0],

        &CanIf_HrhRef[45],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef46[0],

        &CanIf_HrhRef[46],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,

        1u,
        &CanIf_HrhRxPduRef47[0],

        &CanIf_HrhRef[47],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef48[0],

        &CanIf_HrhRef[48],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef49[0],

        &CanIf_HrhRef[49],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,

        1u,
        &CanIf_HrhRxPduRef50[0],

        &CanIf_HrhRef[50],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef51[0],

        &CanIf_HrhRef[51],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef52[0],

        &CanIf_HrhRef[52],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef53[0],

        &CanIf_HrhRef[53],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef54[0],

        &CanIf_HrhRef[54],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef55[0],

        &CanIf_HrhRef[55],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef56[0],

        &CanIf_HrhRef[56],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef57[0],

        &CanIf_HrhRef[57],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef58[0],

        &CanIf_HrhRef[58],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef59[0],

        &CanIf_HrhRef[59],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef60[0],

        &CanIf_HrhRef[60],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef61[0],

        &CanIf_HrhRef[61],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef62[0],

        &CanIf_HrhRef[62],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef63[0],

        &CanIf_HrhRef[63],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef64[0],

        &CanIf_HrhRef[64],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef65[0],

        &CanIf_HrhRef[65],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef66[0],

        &CanIf_HrhRef[66],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef67[0],

        &CanIf_HrhRef[67],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef68[0],

        &CanIf_HrhRef[68],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef69[0],

        &CanIf_HrhRef[69],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef70[0],

        &CanIf_HrhRef[70],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        0u,
        NULL_PTR,

        &CanIf_HrhRef[71],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef71[0],

        &CanIf_HrhRef[72],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD,

        1u,
        &CanIf_HrhRxPduRef72[0],

        &CanIf_HrhRef[73],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC,

        22u,
        &CanIf_HrhRxPduRef73[0],

        &CanIf_HrhRef[74],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC,

        1u,
        &CanIf_HrhRxPduRef74[0],

        &CanIf_HrhRef[75],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC,

        1u,
        &CanIf_HrhRxPduRef75[0],

        &CanIf_HrhRef[76],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC,

        1u,
        &CanIf_HrhRxPduRef76[0],

        &CanIf_HrhRef[77],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC,

        1u,
        &CanIf_HrhRxPduRef77[0],

        &CanIf_HrhRef[78],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC,

        1u,
        &CanIf_HrhRxPduRef78[0],

        &CanIf_HrhRef[79],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC,

        1u,
        &CanIf_HrhRxPduRef79[0],

        &CanIf_HrhRef[80],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA,

        5u,
        &CanIf_HrhRxPduRef80[0],

        &CanIf_HrhRef[81],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA,

        4u,
        &CanIf_HrhRxPduRef81[0],

        &CanIf_HrhRef[82],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA,

        4u,
        &CanIf_HrhRxPduRef82[0],

        &CanIf_HrhRef[83],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA,

        3u,
        &CanIf_HrhRxPduRef83[0],

        &CanIf_HrhRef[84],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA,

        2u,
        &CanIf_HrhRxPduRef84[0],

        &CanIf_HrhRef[85],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA,

        1u,
        &CanIf_HrhRxPduRef85[0],

        &CanIf_HrhRef[86],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA,

        1u,
        &CanIf_HrhRxPduRef86[0],

        &CanIf_HrhRef[87],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA,

        9u,
        &CanIf_HrhRxPduRef87[0],

        &CanIf_HrhRef[88],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA,

        1u,
        &CanIf_HrhRxPduRef88[0],

        &CanIf_HrhRef[89],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfHthIdSymRefType,CANIF_CONST_PBCFG) CanIf_HthRef[CANIF_HTH_NUMBER] =
{
    {
        12u,
        CANIF_FULL_CAN,
    },
    {
        62u,
        CANIF_FULL_CAN,
    },
    {
        95u,
        CANIF_BASIC_CAN,
    },
    {
        96u,
        CANIF_BASIC_CAN,
    },
    {
        31u,
        CANIF_FULL_CAN,
    },
    {
        86u,
        CANIF_BASIC_CAN,
    },
    {
        10u,
        CANIF_FULL_CAN,
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfHthCfgType,CANIF_CONST) CanIf_HthCfgData[CANIF_HTH_NUMBER] =
{
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD4_XCP,
        &CanIf_HthRef[0],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT,
        &CanIf_HthRef[1],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC,
        &CanIf_HthRef[2],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC,
        &CanIf_HthRef[3],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,
        &CanIf_HthRef[4],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_BOD,
        &CanIf_HthRef[5],
    },
    {
        CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA,
        &CanIf_HthRef[6],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIf_InitHohCfgType,CANIF_CONST) CanIf_InitHohCfgData =
{
    CanIf_HrhCfgData,
    CanIf_HthCfgData,
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfRxPduRefType,CANIF_CONST_PBCFG) CanIf_RxPduRef[CANIF_RXPDU_NUMBER] =
{
    {
        XCP_TMSR_DTO_XCP,
        FALSE
    },
    {
        CANNM_RX_PDU_1,
        FALSE
    },
    {
        CANNM_RX_PDU_0,
        FALSE
    },
    {
        CANNM_RX_PDU_2,
        FALSE
    },
    {
        CANNM_RX_PDU_3,
        FALSE
    },
    {
        PDUR_SRCPDU_CCP_PanelStatus_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_SCS_RiSwitchSts_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_SCS_LeSwitchSts_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_TPMS_Info_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_ESCL_ESCLStatus_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_AVAS_State_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_COMP_AC_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_ACCM_Version_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_HVCH_Status1_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_HVCH_Status2_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_1_MainState_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_2_BatState_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_3_DC_ChargeState_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_4_AC_ChargeState_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_10_DC_ChargeStates_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_5_BatTemp_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_6_DischrgRecup_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_7_CellVolt_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_8_TempVoltLimit_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_9_BattInfo_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_A_GB_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_B_GB_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_C_GB_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_BMS_D_GB_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_IPU_OBC_3_CP_CC_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_IPU_DCC_1_State_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_IPU_OBC_1_State_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_IPU_DCC_2_ChrgInValue_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_IPU_OBC_2_Inlet_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_IPU_OBC_4_state_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_INV_1_Value_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_INV_2_Value_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_INV_3_Value_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_INV_4_Value_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_INV_5_Values_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_INV_IMMO_Req_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_ACCM_RX_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_AVAS_RX_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_CCP_RX_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_ESCL_RX_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_PTC_RX_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_SCS_RX_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_TPMS_RX_BOD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_BMS_RX_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_IPUDCC_RX_EPT,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_MCU_RX_EPT,
        FALSE
    },
    {
        CANTP_CANIF_RX_Diag_PhyReq_CCU_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_MCU_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_BMS_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_IPUDCC_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PTC_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SCS_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CCP_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_AVAS_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESCL_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ACCM_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_TPMS_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CDCICU_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESC_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EHB_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EPS_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PP_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FCM_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FRM_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRL_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRR_OBD,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SRS_OBD,
        FALSE
    },
    {
        CANTP_CANIF_RX_Diag_FuncReq_OBD,
        FALSE
    },
    {
        CANTP_CANIF_RX_Diag_FuncReq_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ACCM_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_AVAS_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_BMS_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CCP_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_Resp_CDCICU_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRL_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRR_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EHB_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EPS_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESC_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESCL_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FCM_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FRM_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_IPUDCC_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_MCU_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PP_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PTC_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SCS_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SRS_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_TPMS_BAC,
        FALSE
    },
    {
        CANTP_CANIF_RX_Diag_PhyReq_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_HU_A_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_HU_B_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_HU_C_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_ICU_2_Odo_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_ICU_Info_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_TBOX_BJS_Time_BAC,
        FALSE
    },
    {
        PDUR_SRCPDU_ESC_WheelPulseTime_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_SRS_2_YRSOriginalSts_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_SRS_3_YRSActualSts_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_EPS_3_LatDrvAndEPSSts_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_EPS_2_StrWhlAng_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_SRS_1_Status_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_EPS_1_Status_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_PP_InformAndStatus_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_CRRR_A_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_FCM_D_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_FCM_B_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_FCM_A_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_EHB_B_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_ESC_A_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_ESC_7_FuncStatus_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_EHB_A_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_FCM_23_Obj0109_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_FCM_ObjTrackID_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_FCM_25_Line123_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_CRRR_10_Posn_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_CRRL_RX_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_CRRR_RX_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_EHB_RX_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_EPS_RX_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_ESC_RX_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_FCM_RX_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_FRM_RX_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_PP_RX_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_CANIF_Diag_Resp_SRS_RX_CHA,
        FALSE
    },
    {
        PDUR_SRCPDU_FCM_24_Obj1018_CHA,
        FALSE
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIf_RxPduConfigType,CANIF_CONST) CanIf_RxPduConfigData[CANIF_RXPDU_NUMBER] =
{
    {
        CANIF_RXPDU_TMSR_DTO_XCP,
        0x667u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_0,
        FALSE,
        &Xcp_CanIfRxIndication,
        &CanIf_RxPduRef[0]
    },
    {
        CANIF_RXPDU_CanNm_CAN2_CANFD6_RX,
        0x400u,
        0x780u,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_1,
        TRUE,
        &CanNm_RxIndication,
        &CanIf_RxPduRef[1]
    },
    {
        CANIF_RXPDU_CanNm_CAN1_CANFD8_RX,
        0x400u,
        0x780u,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_2,
        TRUE,
        &CanNm_RxIndication,
        &CanIf_RxPduRef[2]
    },
    {
        CANIF_RXPDU_CanNm_CAN5_CANFD3_RX,
        0x400u,
        0x780u,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_3,
        TRUE,
        &CanNm_RxIndication,
        &CanIf_RxPduRef[3]
    },
    {
        CANIF_RXPDU_CanNm_CAN6_CANFD5_RX,
        0x400u,
        0x780u,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_4,
        TRUE,
        &CanNm_RxIndication,
        &CanIf_RxPduRef[4]
    },
    {
        CANIF_RXPDU_CCP_PanelStatus_BOD,
        0x1b0u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_5,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[5]
    },
    {
        CANIF_RXPDU_SCS_RiSwitchSts_BOD,
        0x16au,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_6,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[6]
    },
    {
        CANIF_RXPDU_SCS_LeSwitchSts_BOD,
        0x1fau,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_7,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[7]
    },
    {
        CANIF_RXPDU_TPMS_Info_BOD,
        0x332u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_8,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[8]
    },
    {
        CANIF_RXPDU_ESCL_ESCLStatus_BOD,
        0x18cu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_9,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[9]
    },
    {
        CANIF_RXPDU_AVAS_State_BOD,
        0x311u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_10,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[10]
    },
    {
        CANIF_RXPDU_COMP_AC_BOD,
        0x20bu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_11,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[11]
    },
    {
        CANIF_RXPDU_ACCM_Version_BOD,
        0x597u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_12,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[12]
    },
    {
        CANIF_RXPDU_HVCH_Status1_BOD,
        0x268u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_13,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[13]
    },
    {
        CANIF_RXPDU_HVCH_Status2_BOD,
        0x269u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_14,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[14]
    },
    {
        CANIF_RXPDU_BMS_1_MainState_EPT,
        0x11du,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_15,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[15]
    },
    {
        CANIF_RXPDU_BMS_2_BatState_EPT,
        0x12au,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_16,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[16]
    },
    {
        CANIF_RXPDU_BMS_3_DC_ChargeState_EPT,
        0x13au,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_17,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[17]
    },
    {
        CANIF_RXPDU_BMS_4_AC_ChargeState_EPT,
        0x145u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_18,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[18]
    },
    {
        CANIF_RXPDU_BMS_10_DC_ChargeStates_EPT,
        0x15au,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_19,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[19]
    },
    {
        CANIF_RXPDU_BMS_5_BatTemp_EPT,
        0x1bau,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_20,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[20]
    },
    {
        CANIF_RXPDU_BMS_6_DischrgRecup_EPT,
        0x21du,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_21,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[21]
    },
    {
        CANIF_RXPDU_BMS_7_CellVolt_EPT,
        0x22eu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_22,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[22]
    },
    {
        CANIF_RXPDU_BMS_8_TempVoltLimit_EPT,
        0x239u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_23,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[23]
    },
    {
        CANIF_RXPDU_BMS_9_BattInfo_EPT,
        0x271u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_24,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[24]
    },
    {
        CANIF_RXPDU_BMS_A_GB_EPT,
        0x3fcu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_25,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[25]
    },
    {
        CANIF_RXPDU_BMS_B_GB_EPT,
        0x3fdu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_26,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[26]
    },
    {
        CANIF_RXPDU_BMS_C_GB_EPT,
        0x3feu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_27,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[27]
    },
    {
        CANIF_RXPDU_BMS_D_GB_EPT,
        0x3ffu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_28,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[28]
    },
    {
        CANIF_RXPDU_IPU_OBC_3_CP_CC_EPT,
        0x22au,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_29,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[29]
    },
    {
        CANIF_RXPDU_IPU_DCC_1_State_EPT,
        0x230u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_30,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[30]
    },
    {
        CANIF_RXPDU_IPU_OBC_1_State_EPT,
        0x238u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_31,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[31]
    },
    {
        CANIF_RXPDU_IPU_DCC_2_ChrgInValue_EPT,
        0x280u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_32,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[32]
    },
    {
        CANIF_RXPDU_IPU_OBC_2_Inlet_EPT,
        0x329u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_33,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[33]
    },
    {
        CANIF_RXPDU_IPU_OBC_4_state_EPT,
        0x32au,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_34,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[34]
    },
    {
        CANIF_RXPDU_INV_1_Value_EPT,
        0xf1u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_35,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[35]
    },
    {
        CANIF_RXPDU_INV_2_Value_EPT,
        0xf2u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_36,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[36]
    },
    {
        CANIF_RXPDU_INV_3_Value_EPT,
        0xf3u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_37,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[37]
    },
    {
        CANIF_RXPDU_INV_4_Value_EPT,
        0xf4u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_38,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[38]
    },
    {
        CANIF_RXPDU_INV_5_Values_EPT,
        0x101u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_39,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[39]
    },
    {
        CANIF_RXPDU_INV_IMMO_Req_EPT,
        0x338u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_40,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[40]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_ACCM_RX_BOD,
        0x797u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_41,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[41]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_AVAS_RX_BOD,
        0x795u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_42,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[42]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_CCP_RX_BOD,
        0x794u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_43,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[43]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_ESCL_RX_BOD,
        0x796u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_44,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[44]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_PTC_RX_BOD,
        0x792u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_45,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[45]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_SCS_RX_BOD,
        0x793u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_46,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[46]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_TPMS_RX_BOD,
        0x799u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_47,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[47]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_BMS_RX_EPT,
        0x783u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_48,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[48]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_IPUDCC_RX_EPT,
        0x78du,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_49,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[49]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_MCU_RX_EPT,
        0x782u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_50,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[50]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CCU_OBD,
        0x701u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_51,
        FALSE,
        &CanTp_RxIndication,
        &CanIf_RxPduRef[51]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_MCU_OBD,
        0x702u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_52,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[52]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_BMS_OBD,
        0x703u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_53,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[53]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_IPUDCC_OBD,
        0x70du,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_54,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[54]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PTC_OBD,
        0x712u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_55,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[55]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SCS_OBD,
        0x713u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_56,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[56]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CCP_OBD,
        0x714u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_57,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[57]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_AVAS_OBD,
        0x715u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_58,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[58]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESCL_OBD,
        0x716u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_59,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[59]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ACCM_OBD,
        0x717u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_60,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[60]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_TPMS_OBD,
        0x719u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_61,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[61]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CDCICU_OBD,
        0x722u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_62,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[62]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESC_OBD,
        0x732u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_63,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[63]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EHB_OBD,
        0x733u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_64,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[64]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EPS_OBD,
        0x734u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_65,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[65]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PP_OBD,
        0x735u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_66,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[66]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FCM_OBD,
        0x736u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_67,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[67]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FRM_OBD,
        0x737u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_68,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[68]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRL_OBD,
        0x73eu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_69,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[69]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRR_OBD,
        0x73fu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_70,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[70]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SRS_OBD,
        0x7f1u,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_72,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[71]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_FuncReq_OBD,
        0x7dfu,
        0x7ffu,
        CANIF_RX_STANDARD_CAN,
        8u,
        CANIF_HOH0_HRH_73,
        FALSE,
        &CanTp_RxIndication,
        &CanIf_RxPduRef[72]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_FuncReq_BAC,
        0x7dfu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &CanTp_RxIndication,
        &CanIf_RxPduRef[73]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ACCM_BAC,
        0x717u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[74]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_AVAS_BAC,
        0x715u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[75]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_BMS_BAC,
        0x703u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[76]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CCP_BAC,
        0x714u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[77]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_Resp_CDCICU_BAC,
        0x7a2u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[78]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRL_BAC,
        0x73eu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[79]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRR_BAC,
        0x73fu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[80]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EHB_BAC,
        0x733u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[81]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EPS_BAC,
        0x734u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[82]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESC_BAC,
        0x732u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[83]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESCL_BAC,
        0x716u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[84]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FCM_BAC,
        0x736u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[85]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FRM_BAC,
        0x737u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[86]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_IPUDCC_BAC,
        0x70du,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[87]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_MCU_BAC,
        0x702u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[88]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PP_BAC,
        0x735u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[89]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PTC_BAC,
        0x712u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[90]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SCS_BAC,
        0x713u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[91]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SRS_BAC,
        0x7f1u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[92]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_TPMS_BAC,
        0x719u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[93]
    },
    {
        CANIF_RXPDU_CANIF_RX_Diag_PhyReq_BAC,
        0x701u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_74,
        FALSE,
        &CanTp_RxIndication,
        &CanIf_RxPduRef[94]
    },
    {
        CANIF_RXPDU_HU_A_BAC,
        0x1ebu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        64u,
        CANIF_HOH0_HRH_75,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[95]
    },
    {
        CANIF_RXPDU_HU_B_BAC,
        0x1d0u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        16u,
        CANIF_HOH0_HRH_76,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[96]
    },
    {
        CANIF_RXPDU_HU_C_BAC,
        0x2fbu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_77,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[97]
    },
    {
        CANIF_RXPDU_ICU_2_Odo_BAC,
        0x26eu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_78,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[98]
    },
    {
        CANIF_RXPDU_ICU_Info_BAC,
        0x12fu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_79,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[99]
    },
    {
        CANIF_RXPDU_TBOX_BJS_Time_BAC,
        0x3b3u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_80,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[100]
    },
    {
        CANIF_RXPDU_ESC_WheelPulseTime_CHA,
        0xa3u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        64u,
        CANIF_HOH0_HRH_81,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[101]
    },
    {
        CANIF_RXPDU_SRS_2_YRSOriginalSts_CHA,
        0xa5u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_81,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[102]
    },
    {
        CANIF_RXPDU_SRS_3_YRSActualSts_CHA,
        0xa6u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_81,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[103]
    },
    {
        CANIF_RXPDU_EPS_3_LatDrvAndEPSSts_CHA,
        0xa1u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        16u,
        CANIF_HOH0_HRH_81,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[104]
    },
    {
        CANIF_RXPDU_EPS_2_StrWhlAng_CHA,
        0xa2u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_81,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[105]
    },
    {
        CANIF_RXPDU_SRS_1_Status_CHA,
        0x180u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_82,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[106]
    },
    {
        CANIF_RXPDU_EPS_1_Status_CHA,
        0x150u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_82,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[107]
    },
    {
        CANIF_RXPDU_PP_InformAndStatus_CHA,
        0x186u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        48u,
        CANIF_HOH0_HRH_82,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[108]
    },
    {
        CANIF_RXPDU_CRRR_A_CHA,
        0x193u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_82,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[109]
    },
    {
        CANIF_RXPDU_FCM_D_CHA,
        0x134u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        16u,
        CANIF_HOH0_HRH_83,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[110]
    },
    {
        CANIF_RXPDU_FCM_B_CHA,
        0x174u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        64u,
        CANIF_HOH0_HRH_83,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[111]
    },
    {
        CANIF_RXPDU_FCM_A_CHA,
        0x175u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        48u,
        CANIF_HOH0_HRH_83,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[112]
    },
    {
        CANIF_RXPDU_EHB_B_CHA,
        0x138u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        24u,
        CANIF_HOH0_HRH_83,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[113]
    },
    {
        CANIF_RXPDU_ESC_A_CHA,
        0x120u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        64u,
        CANIF_HOH0_HRH_84,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[114]
    },
    {
        CANIF_RXPDU_ESC_7_FuncStatus_CHA,
        0x125u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_84,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[115]
    },
    {
        CANIF_RXPDU_EHB_A_CHA,
        0x165u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_84,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[116]
    },
    {
        CANIF_RXPDU_FCM_23_Obj0109_CHA,
        0x2b8u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        64u,
        CANIF_HOH0_HRH_85,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[117]
    },
    {
        CANIF_RXPDU_FCM_ObjTrackID_CHA,
        0x2c1u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_85,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[118]
    },
    {
        CANIF_RXPDU_FCM_25_Line123_CHA,
        0x2bfu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        64u,
        CANIF_HOH0_HRH_86,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[119]
    },
    {
        CANIF_RXPDU_CRRR_10_Posn_CHA,
        0x363u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        32u,
        CANIF_HOH0_HRH_87,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[120]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_CRRL_RX_CHA,
        0x7beu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_88,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[121]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_CRRR_RX_CHA,
        0x7bfu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_88,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[122]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_EHB_RX_CHA,
        0x7b3u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_88,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[123]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_EPS_RX_CHA,
        0x7b4u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_88,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[124]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_ESC_RX_CHA,
        0x7b2u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_88,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[125]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_FCM_RX_CHA,
        0x7b6u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_88,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[126]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_FRM_RX_CHA,
        0x7b7u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_88,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[127]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_PP_RX_CHA,
        0x7b5u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_88,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[128]
    },
    {
        CANIF_RXPDU_CANIF_Diag_Resp_SRS_RX_CHA,
        0x7f9u,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        8u,
        CANIF_HOH0_HRH_88,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[129]
    },
    {
        CANIF_RXPDU_FCM_24_Obj1018_CHA,
        0x2beu,
        0x7ffu,
        CANIF_RX_STANDARD_FD_CAN,
        64u,
        CANIF_HOH0_HRH_89,
        FALSE,
        &PduR_CanIfRxIndication,
        &CanIf_RxPduRef[130]
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIfTxPduRefType,CANIF_CONST_PBCFG) CanIf_TxPduRef[CANIF_TXPDU_NUMBER] =
{
    {
        XCP_INCA_CRO_XCP,
        FALSE,
        64u
    },
    {
        CANNM_TX_PDU_2,
        FALSE,
        8u
    },
    {
        CANNM_TX_PDU_1,
        FALSE,
        8u
    },
    {
        CANNM_TX_PDU_0,
        FALSE,
        8u
    },
    {
        CANNM_TX_PDU_3,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_VCU_10_Torque_CHA,
        FALSE,
        32u
    },
    {
        PDUR_DESTPDU_BCM_4_CruiseSw_PM_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_ICU_Info_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_SCS_RiSwitchSts_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CCU_VehInfo_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CCP_PanelStatus_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_VCU_D_Status_CHA,
        FALSE,
        32u
    },
    {
        PDUR_DESTPDU_HU_A_CHA,
        FALSE,
        64u
    },
    {
        PDUR_DESTPDU_BCM_B_Package_CHA,
        FALSE,
        64u
    },
    {
        PDUR_DESTPDU_SCS_LeSwitchSts_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_ICU_2_Odo_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_AC_3_State_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TPMS_Info_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TBOX_BJS_Time_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_ESC_7_FuncStatus_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_EHB_A_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CCU_VehInfo_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_AC_ACStatuts_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_AC_COMP_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_VCU_7_DrvRange_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_AC_1_Command_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_HVCH_Command_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_ICU_2_Odo_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_AC_3_State_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_AC_2_State_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_AC_8_status_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_HU_C_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_BCM_ESCLCommand_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TBOX_BJS_Time_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TMS_LINTestData1_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TMS_LINTestData2_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TMS_LINTestData3_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_VCU_3_OprtCmd_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_VCU_4_ChrgCmd_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_VCU_B_AcclPedal_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_VCU_1_InvCmd_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_VCU_0_Value_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_VCU_C_OprtCmd_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_ESC_7_FuncStatus_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_SRS_1_Status_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CCU_VehInfo_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_ICU_2_Odo_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_BCM_IMMOAuthResp1_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TBOX_BJS_Time_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_INV_1_Value_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_VCU_DispInfo_BAC,
        FALSE,
        32u
    },
    {
        PDUR_DESTPDU_BMS_1_MainState_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_ESC_7_FuncStatus_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_BMS_2_BatState_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_EPS_1_Status_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_BMS_10_DC_ChargeStates_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_EHB_A_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_SCS_RiSwitchSts_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_SRS_1_Status_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CRRR_A_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CCU_VehInfo_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_VCU_D_Status_BAC,
        FALSE,
        32u
    },
    {
        PDUR_DESTPDU_AC_ACStatuts_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_SCS_LeSwitchSts_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_BCM_B_Package_BAC,
        FALSE,
        64u
    },
    {
        PDUR_DESTPDU_IPU_OBC_1_State_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_AC_3_State_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_BCM_HFSData_BAC,
        FALSE,
        16u
    },
    {
        PDUR_DESTPDU_AVAS_State_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_IPU_OBC_4_state_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_TPMS_Info_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_BMS_A_GB_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_BMS_B_GB_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_BMS_C_GB_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_BMS_D_GB_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_EHB_TX_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_EPS_TX_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_ESC_TX_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_FCM_TX_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_FRM_TX_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_PP_TX_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_SRS_TX_CHA,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_BMS_TX_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_MCU_TX_EPT,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_ACCM_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_AVAS_OBD,
        FALSE,
        8u
    },
    {
        CANTP_CANIF_TX_Diag_Resp_CCU_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_BMS_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCP_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CDCICU_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRL_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRR_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_EHB_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_EPS_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESC_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESCL_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_FCM_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_FRM_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_IPUDCC_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_MCU_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_PP_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_PTC_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_SCS_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_SRS_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_TPMS_OBD,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_ACCM_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_AVAS_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_BMS_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCP_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_PhyReq_CDCICU_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRL_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRR_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_EHB_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_EPS_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESC_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESCL_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_FCM_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_FRM_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_IPUDCC_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_MCU_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_PP_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_PTC_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_SCS_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_SRS_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_TPMS_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_FuncReq_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_EPT_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_BMS_TX_EPT_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_MCU_TX_EPT_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_CHA_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_EHB_TX_CHA_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_EPS_TX_CHA_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_ESC_TX_CHA_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_FCM_TX_CHA_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_FRM_TX_CHA_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_PP_TX_CHA_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_SRS_TX_CHA_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_BOD_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD_1,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD_1,
        FALSE,
        8u
    },
    {
        CANTP_CANIF_TX_Diag_Resp_BAC,
        FALSE,
        8u
    },
    {
        PDUR_DESTPDU_FCM_D_CHA_2_BAC,
        FALSE,
        16u
    },
    {
        PDUR_DESTPDU_FCM_A_CHA_2_BAC,
        FALSE,
        48u
    },
    {
        PDUR_DESTPDU_FCM_23_Obj0109_2_BAC,
        FALSE,
        64u
    },
    {
        PDUR_DESTPDU_FCM_24_Obj1018_CHA_2_BAC,
        FALSE,
        64u
    },
    {
        PDUR_DESTPDU_FCM_25_Line123_CHA_2_BAC,
        FALSE,
        64u
    },
    {
        PDUR_DESTPDU_FCM_ObjTrackID_CHA_2_BAC,
        FALSE,
        32u
    },
    {
        PDUR_DESTPDU_PP_InformAndStatus_CHA_2_BAC,
        FALSE,
        48u
    },
    {
        PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCU_OBD_2A,
        FALSE,
        8u
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
static CONST(CanIf_TxPduConfigType,CANIF_CONST) CanIf_TxPduConfigData[CANIF_TXPDU_NUMBER] =
{
    {
        CANIF_TXPDU_INCA_CRO_XCP,
        0x760u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_0,
        4u,
        CANID_STATIC,
        0xffffu,
        &Xcp_CanIfTxConfirmation,
        &CanIf_TxPduRef[0],
    },
    {
        CANIF_TXPDU_CanNm_CAN5_CANFD3_TX,
        0x431u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &CanNm_TxConfirmation,
        &CanIf_TxPduRef[1],
    },
    {
        CANIF_TXPDU_CanNm_CAN2_CANFD6_TX,
        0x401u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &CanNm_TxConfirmation,
        &CanIf_TxPduRef[2],
    },
    {
        CANIF_TXPDU_CanNm_CAN1_CANFD8_TX,
        0x421u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &CanNm_TxConfirmation,
        &CanIf_TxPduRef[3],
    },
    {
        CANIF_TXPDU_CanNm_CAN6_CANFD5_TX,
        0x411u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &CanNm_TxConfirmation,
        &CanIf_TxPduRef[4],
    },
    {
        CANIF_TXPDU_VCU_10_Torque_CHA,
        0x71u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[5],
    },
    {
        CANIF_TXPDU_BCM_4_CruiseSw_PM_CHA,
        0x119u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[6],
    },
    {
        CANIF_TXPDU_ICU_Info_CHA,
        0x12fu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[7],
    },
    {
        CANIF_TXPDU_SCS_RiSwitchSts_CHA,
        0x16au,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[8],
    },
    {
        CANIF_TXPDU_CCU_VehInfo_CHA,
        0x1a0u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[9],
    },
    {
        CANIF_TXPDU_CCP_PanelStatus_CHA,
        0x1b0u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[10],
    },
    {
        CANIF_TXPDU_VCU_D_Status_CHA,
        0x1b6u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[11],
    },
    {
        CANIF_TXPDU_HU_A_CHA,
        0x1ebu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[12],
    },
    {
        CANIF_TXPDU_BCM_B_Package_CHA,
        0x21au,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[13],
    },
    {
        CANIF_TXPDU_SCS_LeSwitchSts_CHA,
        0x1fau,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[14],
    },
    {
        CANIF_TXPDU_ICU_2_Odo_CHA,
        0x26eu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[15],
    },
    {
        CANIF_TXPDU_AC_3_State_CHA,
        0x29fu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[16],
    },
    {
        CANIF_TXPDU_TPMS_Info_CHA,
        0x332u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[17],
    },
    {
        CANIF_TXPDU_TBOX_BJS_Time_CHA,
        0x3b3u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[18],
    },
    {
        CANIF_TXPDU_ESC_7_FuncStatus_BOD,
        0x125u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[19],
    },
    {
        CANIF_TXPDU_EHB_A_BOD,
        0x165u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[20],
    },
    {
        CANIF_TXPDU_CCU_VehInfo_BOD,
        0x1a0u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[21],
    },
    {
        CANIF_TXPDU_AC_ACStatuts_BOD,
        0x1f8u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[22],
    },
    {
        CANIF_TXPDU_AC_COMP_BOD,
        0x20au,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[23],
    },
    {
        CANIF_TXPDU_VCU_7_DrvRange_BOD,
        0x211u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[24],
    },
    {
        CANIF_TXPDU_AC_1_Command_BOD,
        0x218u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[25],
    },
    {
        CANIF_TXPDU_HVCH_Command_BOD,
        0x258u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[26],
    },
    {
        CANIF_TXPDU_ICU_2_Odo_BOD,
        0x26eu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[27],
    },
    {
        CANIF_TXPDU_AC_3_State_BOD,
        0x29fu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[28],
    },
    {
        CANIF_TXPDU_AC_2_State_BOD,
        0x2f1u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[29],
    },
    {
        CANIF_TXPDU_AC_8_status_BOD,
        0x2f9u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[30],
    },
    {
        CANIF_TXPDU_HU_C_BOD,
        0x2fbu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[31],
    },
    {
        CANIF_TXPDU_BCM_ESCLCommand_BOD,
        0x388u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[32],
    },
    {
        CANIF_TXPDU_TBOX_BJS_Time_BOD,
        0x3b3u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[33],
    },
    {
        CANIF_TXPDU_TMS_LINTestData1_BOD,
        0x521u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[34],
    },
    {
        CANIF_TXPDU_TMS_LINTestData2_BOD,
        0x522u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[35],
    },
    {
        CANIF_TXPDU_TMS_LINTestData3_BOD,
        0x523u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[36],
    },
    {
        CANIF_TXPDU_VCU_3_OprtCmd_EPT,
        0x77u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[37],
    },
    {
        CANIF_TXPDU_VCU_4_ChrgCmd_EPT,
        0x81u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[38],
    },
    {
        CANIF_TXPDU_VCU_B_AcclPedal_EPT,
        0x82u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[39],
    },
    {
        CANIF_TXPDU_VCU_1_InvCmd_EPT,
        0xf0u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[40],
    },
    {
        CANIF_TXPDU_VCU_0_Value_EPT,
        0x100u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[41],
    },
    {
        CANIF_TXPDU_VCU_C_OprtCmd_EPT,
        0x113u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[42],
    },
    {
        CANIF_TXPDU_ESC_7_FuncStatus_EPT,
        0x125u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[43],
    },
    {
        CANIF_TXPDU_SRS_1_Status_EPT,
        0x180u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[44],
    },
    {
        CANIF_TXPDU_CCU_VehInfo_EPT,
        0x1a0u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[45],
    },
    {
        CANIF_TXPDU_ICU_2_Odo_EPT,
        0x26eu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[46],
    },
    {
        CANIF_TXPDU_BCM_IMMOAuthResp1_EPT,
        0x330u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[47],
    },
    {
        CANIF_TXPDU_TBOX_BJS_Time_EPT,
        0x3b3u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[48],
    },
    {
        CANIF_TXPDU_INV_1_Value_BAC,
        0xf1u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[49],
    },
    {
        CANIF_TXPDU_VCU_DispInfo_BAC,
        0x106u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[50],
    },
    {
        CANIF_TXPDU_BMS_1_MainState_BAC,
        0x11du,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[51],
    },
    {
        CANIF_TXPDU_ESC_7_FuncStatus_BAC,
        0x125u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[52],
    },
    {
        CANIF_TXPDU_BMS_2_BatState_BAC,
        0x12au,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[53],
    },
    {
        CANIF_TXPDU_EPS_1_Status_BAC,
        0x150u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[54],
    },
    {
        CANIF_TXPDU_BMS_10_DC_ChargeStates_BAC,
        0x15au,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[55],
    },
    {
        CANIF_TXPDU_EHB_A_BAC,
        0x165u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[56],
    },
    {
        CANIF_TXPDU_SCS_RiSwitchSts_BAC,
        0x16au,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[57],
    },
    {
        CANIF_TXPDU_SRS_1_Status_BAC,
        0x180u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[58],
    },
    {
        CANIF_TXPDU_CRRR_A_BAC,
        0x193u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[59],
    },
    {
        CANIF_TXPDU_CCU_VehInfo_BAC,
        0x1a0u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[60],
    },
    {
        CANIF_TXPDU_VCU_D_Status_BAC,
        0x1b6u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[61],
    },
    {
        CANIF_TXPDU_AC_ACStatuts_BAC,
        0x1f8u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[62],
    },
    {
        CANIF_TXPDU_SCS_LeSwitchSts_BAC,
        0x1fau,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[63],
    },
    {
        CANIF_TXPDU_BCM_B_Package_BAC,
        0x21au,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[64],
    },
    {
        CANIF_TXPDU_IPU_OBC_1_State_BAC,
        0x238u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[65],
    },
    {
        CANIF_TXPDU_AC_3_State_BAC,
        0x29fu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[66],
    },
    {
        CANIF_TXPDU_BCM_HFSData_BAC,
        0x2a0u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[67],
    },
    {
        CANIF_TXPDU_AVAS_State_BAC,
        0x311u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[68],
    },
    {
        CANIF_TXPDU_IPU_OBC_4_state_BAC,
        0x32au,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[69],
    },
    {
        CANIF_TXPDU_TPMS_Info_BAC,
        0x332u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[70],
    },
    {
        CANIF_TXPDU_BMS_A_GB_BAC,
        0x3fcu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[71],
    },
    {
        CANIF_TXPDU_BMS_B_GB_BAC,
        0x3fdu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[72],
    },
    {
        CANIF_TXPDU_BMS_C_GB_BAC,
        0x3feu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[73],
    },
    {
        CANIF_TXPDU_BMS_D_GB_BAC,
        0x3ffu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[74],
    },
    {
        CANIF_TXPDU_CANIF_Diag_FuncReq_TX_CHA,
        0x7dfu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[75],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA,
        0x73eu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[76],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA,
        0x73fu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[77],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_EHB_TX_CHA,
        0x733u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[78],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_EPS_TX_CHA,
        0x734u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[79],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_ESC_TX_CHA,
        0x732u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[80],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_FCM_TX_CHA,
        0x736u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[81],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_FRM_TX_CHA,
        0x737u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[82],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_PP_TX_CHA,
        0x735u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[83],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_SRS_TX_CHA,
        0x7f1u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[84],
    },
    {
        CANIF_TXPDU_CANIF_Diag_FuncReq_TX_BOD,
        0x7dfu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[85],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD,
        0x717u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[86],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD,
        0x715u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[87],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD,
        0x714u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[88],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD,
        0x716u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[89],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD,
        0x712u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[90],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD,
        0x713u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[91],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD,
        0x719u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[92],
    },
    {
        CANIF_TXPDU_CANIF_Diag_FuncReq_TX_EPT,
        0x7dfu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[93],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_BMS_TX_EPT,
        0x703u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[94],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT,
        0x70du,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[95],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_MCU_TX_EPT,
        0x702u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[96],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_ACCM_OBD,
        0x797u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[97],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_AVAS_OBD,
        0x795u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[98],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CCU_OBD,
        0x781u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &CanTp_TxConfirmation,
        &CanIf_TxPduRef[99],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_BMS_OBD,
        0x783u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[100],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CCP_OBD,
        0x794u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[101],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CDCICU_OBD,
        0x7a2u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[102],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CRRL_OBD,
        0x7beu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[103],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CRRR_OBD,
        0x7bfu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[104],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_EHB_OBD,
        0x7b3u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[105],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_EPS_OBD,
        0x7b4u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[106],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_ESC_OBD,
        0x7b2u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[107],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_ESCL_OBD,
        0x796u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[108],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_FCM_OBD,
        0x7b6u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[109],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_FRM_OBD,
        0x7b7u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[110],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_IPUDCC_OBD,
        0x78du,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[111],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_MCU_OBD,
        0x782u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[112],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_PP_OBD,
        0x7b5u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[113],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_PTC_OBD,
        0x792u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[114],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_SCS_OBD,
        0x793u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[115],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_SRS_OBD,
        0x7f9u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[116],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_TPMS_OBD,
        0x799u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[117],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_ACCM_BAC,
        0x797u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[118],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_AVAS_BAC,
        0x795u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[119],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_BMS_BAC,
        0x783u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[120],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CCP_BAC,
        0x794u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[121],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_PhyReq_CDCICU_BAC,
        0x722u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[122],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CRRL_BAC,
        0x7beu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[123],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CRRR_BAC,
        0x7bfu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[124],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_EHB_BAC,
        0x7b3u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[125],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_EPS_BAC,
        0x7b4u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[126],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_ESC_BAC,
        0x7b2u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[127],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_ESCL_BAC,
        0x796u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[128],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_FCM_BAC,
        0x7b6u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[129],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_FRM_BAC,
        0x7b7u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[130],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_IPUDCC_BAC,
        0x78du,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[131],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_MCU_BAC,
        0x782u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[132],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_PP_BAC,
        0x7b5u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[133],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_PTC_BAC,
        0x792u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[134],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_SCS_BAC,
        0x793u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[135],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_SRS_BAC,
        0x7f9u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[136],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_TPMS_BAC,
        0x799u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[137],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_FuncReq_BAC,
        0x7dfu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[138],
    },
    {
        CANIF_TXPDU_CANIF_Diag_FuncReq_TX_EPT_1,
        0x7dfu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[139],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_BMS_TX_EPT_1,
        0x703u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[140],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT_1,
        0x70du,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[141],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_MCU_TX_EPT_1,
        0x702u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_1,
        5u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[142],
    },
    {
        CANIF_TXPDU_CANIF_Diag_FuncReq_TX_CHA_1,
        0x7dfu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[143],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA_1,
        0x73eu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[144],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA_1,
        0x73fu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[145],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_EHB_TX_CHA_1,
        0x733u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[146],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_EPS_TX_CHA_1,
        0x734u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[147],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_ESC_TX_CHA_1,
        0x732u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[148],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_FCM_TX_CHA_1,
        0x736u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[149],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_FRM_TX_CHA_1,
        0x737u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[150],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_PP_TX_CHA_1,
        0x735u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[151],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_SRS_TX_CHA_1,
        0x7f1u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_6,
        1u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[152],
    },
    {
        CANIF_TXPDU_CANIF_Diag_FuncReq_TX_BOD_1,
        0x7dfu,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[153],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD_1,
        0x717u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[154],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD_1,
        0x715u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[155],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD_1,
        0x714u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[156],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD_1,
        0x716u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[157],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD_1,
        0x712u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[158],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD_1,
        0x713u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[159],
    },
    {
        CANIF_TXPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD_1,
        0x719u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_4,
        3u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[160],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_BAC,
        0x781u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &CanTp_TxConfirmation,
        &CanIf_TxPduRef[161],
    },
    {
        CANIF_TXPDU_FCM_D_CHA_2_BAC,
        0x134u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[162],
    },
    {
        CANIF_TXPDU_FCM_A_CHA_2_BAC,
        0x175u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[163],
    },
    {
        CANIF_TXPDU_FCM_23_Obj0109_2_BAC,
        0x2b8u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[164],
    },
    {
        CANIF_TXPDU_FCM_24_Obj1018_CHA_2_BAC,
        0x2beu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[165],
    },
    {
        CANIF_TXPDU_FCM_25_Line123_CHA_2_BAC,
        0x2bfu,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[166],
    },
    {
        CANIF_TXPDU_FCM_ObjTrackID_CHA_2_BAC,
        0x2c1u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_2,
        0u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[167],
    },
    {
        CANIF_TXPDU_PP_InformAndStatus_CHA_2_BAC,
        0x186u,
        0x7ffu,
        CANIF_TX_STANDARD_FD_CAN,
        CANIF_HOH0_HTH_3,
        6u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[168],
    },
    {
        CANIF_TXPDU_CANIF_TX_Diag_Resp_CCU_OBD_2A,
        0x781u,
        0x7ffu,
        CANIF_TX_STANDARD_CAN,
        CANIF_HOH0_HTH_5,
        2u,
        CANID_STATIC,
        0xffffu,
        &PduR_CanIfTxConfirmation,
        &CanIf_TxPduRef[169],
    },
};
#define CANIF_STOP_SEC_CONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer0[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer1[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer2[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer3[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer4[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer5[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer6[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer7[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer8[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer9[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer10[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer11[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer12[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer13[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer14[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer15[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer16[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer17[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer18[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer19[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer20[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer21[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer22[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer23[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer24[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer25[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer26[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer27[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer28[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer29[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer30[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer31[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer32[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer33[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer34[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer35[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer36[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer37[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer38[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer39[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer40[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer41[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer42[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer43[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer44[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer45[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer46[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer47[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer48[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer49[32];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer50[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer51[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer52[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer53[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer54[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer55[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer56[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer57[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer58[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer59[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer60[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer61[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer62[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer63[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer64[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer65[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer66[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer67[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer68[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer69[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer70[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer71[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer72[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer73[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer74[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer75[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer76[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer77[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer78[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer79[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer80[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer81[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer82[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer83[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer84[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer85[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer86[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer87[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer88[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer89[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer90[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer91[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer92[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer93[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer94[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer95[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer96[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer97[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer98[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer99[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer100[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer101[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer102[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer103[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer104[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer105[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer106[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer107[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer108[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer109[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer110[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer111[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer112[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer113[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer114[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer115[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer116[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer117[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer118[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer119[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer120[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer121[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer122[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer123[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer124[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer125[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer126[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer127[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer128[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer129[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer130[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer131[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer132[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer133[8];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer134[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer135[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer136[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer137[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer138[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"
static uint8 TxPduBuffer139[64];
#define CANIF_STOP_SEC_VAR_NO_INIT_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
static VAR(CanIf_TxPduBufferType, CANIF_VAR) CanIf_TxPduBuffer0[50] =
{
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer0
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer1
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer2
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer3
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer4
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer5
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer6
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer7
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer8
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer9
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer10
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer11
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer12
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer13
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer14
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer15
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer16
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer17
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer18
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer19
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer20
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer21
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer22
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer23
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer24
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer25
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer26
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer27
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer28
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer29
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer30
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer31
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer32
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer33
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer34
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer35
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer36
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer37
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer38
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer39
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer40
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer41
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer42
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer43
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer44
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer45
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer46
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer47
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer48
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer49
    },
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
static VAR(CanIf_TxPduBufferType, CANIF_VAR) CanIf_TxPduBuffer1[25] =
{
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer50
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer51
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer52
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer53
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer54
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer55
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer56
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer57
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer58
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer59
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer60
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer61
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer62
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer63
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer64
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer65
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer66
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer67
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer68
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer69
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer70
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer71
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer72
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer73
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer74
    },
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
static VAR(CanIf_TxPduBufferType, CANIF_VAR) CanIf_TxPduBuffer2[10] =
{
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer75
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer76
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer77
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer78
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer79
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer80
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer81
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer82
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer83
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer84
    },
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
static VAR(CanIf_TxPduBufferType, CANIF_VAR) CanIf_TxPduBuffer3[27] =
{
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer85
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer86
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer87
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer88
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer89
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer90
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer91
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer92
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer93
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer94
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer95
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer96
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer97
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer98
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer99
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer100
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer101
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer102
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer103
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer104
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer105
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer106
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer107
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer108
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer109
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer110
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer111
    },
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
static VAR(CanIf_TxPduBufferType, CANIF_VAR) CanIf_TxPduBuffer4[5] =
{
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer112
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer113
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer114
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer115
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer116
    },
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
static VAR(CanIf_TxPduBufferType, CANIF_VAR) CanIf_TxPduBuffer5[17] =
{
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer117
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer118
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer119
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer120
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer121
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer122
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer123
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer124
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer125
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer126
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer127
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer128
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer129
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer130
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer131
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer132
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer133
    },
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
static VAR(CanIf_TxPduBufferType, CANIF_VAR) CanIf_TxPduBuffer6[6] =
{
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer134
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer135
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer136
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer137
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer138
    },
    {
        FALSE,
        0u,
        0xffffu,
        0xffffffffu,
        TxPduBuffer139
    },
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
VAR(CanIf_TxBufferType, CANIF_VAR) CanIf_TxBuffer[CANIF_TXBUFFER_NUMBER] =
/* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
{
    {CanIf_TxPduBuffer0},
    {CanIf_TxPduBuffer1},
    {CanIf_TxPduBuffer2},
    {CanIf_TxPduBuffer3},
    {CanIf_TxPduBuffer4},
    {CanIf_TxPduBuffer5},
    {CanIf_TxPduBuffer6},
};
#define CANIF_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_CONFIG_DATA_8
#include "CanIf_MemMap.h"
static CONST(uint8,CANIF_CONST) CanIf_TxBufferSizeCfg[CANIF_TXBUFFER_NUMBER] ={50,25,10,27,5,17,6};
#define CANIF_STOP_SEC_CONFIG_DATA_8
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1531 ++ */ /* MISRA Rule 8.7 */
CONST(CanIf_ConfigType,CANIF_CONST) CanIf_InitCfgSet =
/* PRQA S 1531 -- */ /* MISRA Rule 8.7 */
{
    NULL_PTR,
    CanIf_CtrlCfgData,
    &CanIf_InitHohCfgData,
    CanIf_RxPduConfigData,
    CanIf_TxPduConfigData,
    CanIf_TxBufferSizeCfg,
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"

#if (STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER)
#define CANIF_START_SEC_PBCONFIG_DATA_16
#include "CanIf_MemMap.h"
static CONST(uint16,CANIF_CONST_PBCFG) CanIf_Can0Hoh2HrhId[95u] =
{
    0x52u,0x54u,0x56u,0x53u,0x59u,0x55u,0x3u,0x51u,0x57u,0x58u,
    0xFFFFu,0x0u,0xFFFFu,0x4u,0xCu,0xAu,0x5u,0xBu,0x29u,0x2Au,
    0x2Bu,0x2Cu,0x2Du,0x2Eu,0x2Fu,0x9u,0xDu,0xEu,0x7u,0x6u,
    0x8u,0xFFFFu,0x1u,0x13u,0xFu,0x10u,0x11u,0x12u,0x14u,0x15u,
    0x16u,0x17u,0x18u,0x19u,0x1Au,0x1Bu,0x1Cu,0x30u,0x31u,0x32u,
    0x23u,0x24u,0x25u,0x26u,0x27u,0x28u,0x1Eu,0x20u,0x1Fu,0x21u,
    0x1Du,0x22u,0xFFFFu,0x33u,0x34u,0x35u,0x36u,0x37u,0x38u,0x39u,
    0x3Au,0x3Bu,0x3Cu,0x3Du,0x3Eu,0x3Fu,0x40u,0x41u,0x42u,0x43u,
    0x44u,0x45u,0x46u,0x47u,0x48u,0x49u,0xFFFFu,0x2u,0x4Bu,0x4Cu,
    0x4Du,0x4Eu,0x4Fu,0x50u,0x4Au
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_16
#include "CanIf_MemMap.h"

#define CANIF_START_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
/* PRQA S 1533 ++ */ /* MISRA Rule 8.9 */
CONST(CanIf_CanHOH2HRHType,CANIF_CONST) CanIf_CanHoh2Hrh[1] =
/* PRQA S 1533 -- */ /* MISRA Rule 8.9 */
{
    {
        CanIf_Can0Hoh2HrhId,
        95u
    }
};
#define CANIF_STOP_SEC_PBCONFIG_DATA_UNSPECIFIED
#include "CanIf_MemMap.h"
#endif/*STD_OFF == CANIF_RXINDICATION_AUTOSAR_PARAMETER*/
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/
