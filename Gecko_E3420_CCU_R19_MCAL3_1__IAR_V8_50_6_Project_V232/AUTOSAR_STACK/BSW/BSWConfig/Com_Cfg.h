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
**  FILENAME    : Com_Cfg.h                                                   **
**                                                                            **
**  Created on  : 2024/07/08 11:15:25                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of Com                              **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#ifndef  COM_CFG_H
#define  COM_CFG_H

#include "ComStack_Types.h"
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define COM_CFG_H_AR_MAJOR_VERSION    4u
#define COM_CFG_H_AR_MINOR_VERSION    2u
#define COM_CFG_H_AR_PATCH_VERSION    2u
#define COM_CFG_H_SW_MAJOR_VERSION    2u
#define COM_CFG_H_SW_MINOR_VERSION    0u
#define COM_CFG_H_SW_PATCH_VERSION    0u

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

#define COM_CANCELLATION_SUPPORT                     STD_OFF
#define COM_DEV_ERROR_DETECT                         STD_ON
#define COM_ENABLE_SIGNAL_GROUP_ARRAY_API            STD_OFF
#define COM_VERSION_INFO_API                         STD_OFF
#define COM_ENABLE_MDT_FOR_CYCLIC_TRANSMISSION       STD_ON
#define COM_METADATA_SUPPORT                         STD_OFF
#define COM_RETRY_FAILED_TRANSMIT_REQUESTS           STD_OFF

#define COM_IPDUGROUP_NUMBER                         18u
#define Com_RxPduGroup_CANFD4        0u
#define Com_TxPduGroup_CANFD4        1u
#define Com_RxPduGroup_CANFD3        2u
#define Com_TxPduGroup_CANFD3        3u
#define Com_RxPduGroup_CANFD5_BOD_CAN6        4u
#define Com_TxPduGroup_CANFD5_BOD_CAN6        5u
#define Com_RxPduGroup_CANFD6_EPT_CAN2        6u
#define Com_TxPduGroup_CANFD6_EPT_CAN2        7u
#define Com_RxPduGroup_CANFD8_BAC_CAN1        8u
#define Com_TxPduGroup_CANFD8_BAC_CAN1        9u
#define Com_RxPduGroup_CANFD7        10u
#define Com_TxPduGroup_CANFD7        11u
#define ComIPduGroup_CCU_Tx_LIN1        12u
#define ComIPduGroup_CCU_Rx_LIN1        13u
#define ComIPduGroup_CCU_Tx_LIN2        14u
#define ComIPduGroup_CCU_Rx_LIN2        15u
#define ComIPduGroup_CCU_Tx_LIN3        16u
#define ComIPduGroup_CCU_Rx_LIN3        17u

#define COM_RXIPDU_NUMBER        92u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define COM_RXPDU_COM_TMSR_DTO_XCP        0u
#define COM_RXPDU_COM_FCM_23_Obj0109_CHA        1u
#define COM_RXPDU_COM_FCM_24_Obj1018_CHA        2u
#define COM_RXPDU_COM_FCM_25_Line123_CHA        3u
#define COM_RXPDU_COM_FCM_ObjTrackID_CHA        4u
#define COM_RXPDU_COM_ESC_WheelPulseTime_CHA        5u
#define COM_RXPDU_COM_SRS_2_YRSOriginalSts_CHA        6u
#define COM_RXPDU_COM_SRS_3_YRSActualSts_CHA        7u
#define COM_RXPDU_COM_EPS_3_LatDrvAndEPSSts_CHA        8u
#define COM_RXPDU_COM_EPS_2_StrWhlAng_CHA        9u
#define COM_RXPDU_COM_EPS_1_Status_CHA        10u
#define COM_RXPDU_COM_CRRR_A_CHA        11u
#define COM_RXPDU_COM_CRRR_10_Posn_CHA        12u
#define COM_RXPDU_COM_CCP_PanelStatus_BOD        13u
#define COM_RXPDU_COM_SCS_LeSwitchSts_BOD        14u
#define COM_RXPDU_COM_TPMS_Info_BOD        15u
#define COM_RXPDU_COM_ESCL_ESCLStatus_BOD        16u
#define COM_RXPDU_COM_AVAS_State_BOD        17u
#define COM_RXPDU_COM_COMP_AC_BOD        18u
#define COM_RXPDU_COM_ACCM_Version_BOD        19u
#define COM_RXPDU_COM_HVCH_Status1_BOD        20u
#define COM_RXPDU_COM_HVCH_Status2_BOD        21u
#define COM_RXPDU_COM_BMS_1_MainState_EPT        22u
#define COM_RXPDU_COM_BMS_2_BatState_EPT        23u
#define COM_RXPDU_COM_BMS_3_DC_ChargeState_EPT        24u
#define COM_RXPDU_COM_BMS_4_AC_ChargeState_EPT        25u
#define COM_RXPDU_COM_BMS_10_DC_ChargeStates_EPT        26u
#define COM_RXPDU_COM_BMS_5_BatTemp_EPT        27u
#define COM_RXPDU_COM_BMS_6_DischrgRecup_EPT        28u
#define COM_RXPDU_COM_BMS_7_CellVolt_EPT        29u
#define COM_RXPDU_COM_BMS_8_TempVoltLimit_EPT        30u
#define COM_RXPDU_COM_BMS_9_BattInfo_EPT        31u
#define COM_RXPDU_COM_BMS_A_GB_EPT        32u
#define COM_RXPDU_COM_BMS_B_GB_EPT        33u
#define COM_RXPDU_COM_BMS_C_GB_EPT        34u
#define COM_RXPDU_COM_BMS_D_GB_EPT        35u
#define COM_RXPDU_COM_IPU_OBC_3_CP_CC_EPT        36u
#define COM_RXPDU_COM_IPU_DCC_1_State_EPT        37u
#define COM_RXPDU_COM_IPU_OBC_1_State_EPT        38u
#define COM_RXPDU_COM_IPU_DCC_2_ChrgInValue_EPT        39u
#define COM_RXPDU_COM_IPU_OBC_2_Inlet_EPT        40u
#define COM_RXPDU_COM_IPU_OBC_4_state_EPT        41u
#define COM_RXPDU_COM_INV_1_Value_EPT        42u
#define COM_RXPDU_COM_INV_2_Value_EPT        43u
#define COM_RXPDU_COM_INV_3_Value_EPT        44u
#define COM_RXPDU_COM_INV_4_Value_EPT        45u
#define COM_RXPDU_COM_INV_5_Values_EPT        46u
#define COM_RXPDU_COM_INV_IMMO_Req_EPT        47u
#define COM_RXPDU_COM_ICU_Info_BAC        48u
#define COM_RXPDU_COM_ICU_2_Odo_BAC        49u
#define COM_RXPDU_COM_HU_C_BAC        50u
#define COM_RXPDU_COM_TBOX_BJS_Time_BAC        51u
#define COM_RXPDU_Com_HP_EXV__Rsp_LIN1        52u
#define COM_RXPDU_Com_BAT_EXV_Rsp_LIN1        53u
#define COM_RXPDU_Com_AC_EXV_Rsp_LIN1        54u
#define COM_RXPDU_Com_MCV_Sts_LIN1        55u
#define COM_RXPDU_Com_BCV_Sts_LIN1        56u
#define COM_RXPDU_Com_MotPMP_Sts_LIN1        57u
#define COM_RXPDU_Com_BatPMP_Sts_LIN1        58u
#define COM_RXPDU_Com_AcPMP_Sts_LIN1        59u
#define COM_RXPDU_Com_HP_EXV_Version_LIN1        60u
#define COM_RXPDU_Com_Bat_EXV_Version_LIN1        61u
#define COM_RXPDU_Com_MCV_Version_LIN1        62u
#define COM_RXPDU_Com_BCV_Version_LIN1        63u
#define COM_RXPDU_Com_AcPMP_Version_LIN1        64u
#define COM_RXPDU_Com_AC_EXV_Rsp_LIN2        65u
#define COM_RXPDU_Com_AcPMP_Sts_LIN2        66u
#define COM_RXPDU_Com_AcPMP_Version_LIN2        67u
#define COM_RXPDU_Com_BAT_EXV_Rsp_LIN2        68u
#define COM_RXPDU_Com_BatPMP_Sts_LIN2        69u
#define COM_RXPDU_Com_Bat_EXV_Version_LIN2        70u
#define COM_RXPDU_Com_C3WV_Sts_LIN2        71u
#define COM_RXPDU_Com_C5WV_Sts_LIN2        72u
#define COM_RXPDU_Com_HP_EXV_Rsp_LIN2        73u
#define COM_RXPDU_Com_HP_EXV_Version_LIN2        74u
#define COM_RXPDU_Com_MotPMP_Sts_LIN2        75u
#define COM_RXPDU_Com_FCLL_Status_LIN3        76u
#define COM_RXPDU_Com_FCLR_Status_LIN3        77u
#define COM_RXPDU_Com_Frm_InterlockStatus_LIN3        78u
#define COM_RXPDU_Com_Frm_InterlockToVehicle_LIN3        79u
#define COM_RXPDU_COM_HU_B_BAC        80u
#define COM_RXPDU_COM_HU_A_BAC        81u
#define COM_RXPDU_COM_SCS_RiSwitchSts_BOD        82u
#define COM_RXPDU_COM_FCM_D_CHA        83u
#define COM_RXPDU_COM_FCM_B_CHA        84u
#define COM_RXPDU_COM_FCM_A_CHA        85u
#define COM_RXPDU_COM_ESC_A_CHA        86u
#define COM_RXPDU_COM_ESC_7_FuncStatus_CHA        87u
#define COM_RXPDU_COM_EHB_B_CHA        88u
#define COM_RXPDU_COM_EHB_A_CHA        89u
#define COM_RXPDU_COM_SRS_1_Status_CHA        90u
#define COM_RXPDU_COM_PP_InformAndStatus_CHA        91u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define COM_TXIPDU_NUMBER    53u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define COM_TXPDU_COM_INCA_CRO_XCP        92u
#define COM_TXPDU_COM_VCU_0_Value_EPT        93u
#define COM_TXPDU_COM_VCU_D_Status_CHA        94u
#define COM_TXPDU_COM_VCU_10_Torque_CHA        95u
#define COM_TXPDU_COM_BCM_4_CruiseSw_PM_CHA        96u
#define COM_TXPDU_COM_AC_3_State_CHA        97u
#define COM_TXPDU_COM_AC_ACStatuts_BOD        98u
#define COM_TXPDU_COM_AC_COMP_BOD        99u
#define COM_TXPDU_COM_VCU_7_DrvRange_BOD        100u
#define COM_TXPDU_COM_AC_1_Command_BOD        101u
#define COM_TXPDU_COM_HVCH_Command_BOD        102u
#define COM_TXPDU_COM_AC_3_State_BOD        103u
#define COM_TXPDU_COM_AC_2_State_BOD        104u
#define COM_TXPDU_COM_AC_8_status_BOD        105u
#define COM_TXPDU_COM_TMS_LINTestData1_BOD        106u
#define COM_TXPDU_COM_TMS_LINTestData2_BOD        107u
#define COM_TXPDU_COM_TMS_LINTestData3_BOD        108u
#define COM_TXPDU_COM_VCU_3_OprtCmd_EPT        109u
#define COM_TXPDU_COM_VCU_4_ChrgCmd_EPT        110u
#define COM_TXPDU_COM_VCU_B_AcclPedal_EPT        111u
#define COM_TXPDU_COM_VCU_1_InvCmd_EPT        112u
#define COM_TXPDU_COM_VCU_C_OprtCmd_EPT        113u
#define COM_TXPDU_COM_BCM_IMMOAuthResp1_EPT        114u
#define COM_TXPDU_COM_AC_ACStatuts_BAC        115u
#define COM_TXPDU_COM_AC_3_State_BAC        116u
#define COM_TXPDU_COM_BCM_HFSData_BAC        117u
#define COM_TXPDU_Com_HP_EXV_Cmd_LIN1        118u
#define COM_TXPDU_Com_BAT_EXV_Cmd_LIN1        119u
#define COM_TXPDU_Com_AC_EXV_Cmd_LIN1        120u
#define COM_TXPDU_Com_MCV_Cmd_LIN1        121u
#define COM_TXPDU_Com_BCV_Cmd_LIN1        122u
#define COM_TXPDU_Com_PMP_Cmd_LIN1        123u
#define COM_TXPDU_Com_AC_EXV_Cmd_LIN2        124u
#define COM_TXPDU_Com_BAT_EXV_Cmd_LIN2        125u
#define COM_TXPDU_Com_C3WV_Cmd_LIN2        126u
#define COM_TXPDU_Com_C5WV_Cmd_LIN2        127u
#define COM_TXPDU_Com_HP_EXV_Cmd_LIN2        128u
#define COM_TXPDU_Com_PMP_Cmd_LIN2        129u
#define COM_TXPDU_Com_CCU_FCLCommand_LIN3        130u
#define COM_TXPDU_Com_Frm_VehicleToInterlock_LIN3        131u
#define COM_TXPDU_Com_CAN1_CANFD8_user        132u
#define COM_TXPDU_Com_CAN6_CANFD5_user        133u
#define COM_TXPDU_Com_CAN5_CANFD3_user        134u
#define COM_TXPDU_Com_CAN2_CANFD6_user        135u
#define COM_TXPDU_COM_VCU_DispInfo_BAC        136u
#define COM_TXPDU_COM_CCU_VehInfo_BAC        137u
#define COM_TXPDU_COM_VCU_D_Status_BAC        138u
#define COM_TXPDU_COM_BCM_B_Package_BAC        139u
#define COM_TXPDU_COM_CCU_VehInfo_BOD        140u
#define COM_TXPDU_COM_BCM_ESCLCommand_BOD        141u
#define COM_TXPDU_COM_CCU_VehInfo_CHA        142u
#define COM_TXPDU_COM_BCM_B_Package_CHA        143u
#define COM_TXPDU_COM_CCU_VehInfo_EPT        144u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */
#define COM_RXIPDUBUFF_SIZE        1284u
#define COM_TXIPDUBUFF_SIZE        632u

#define COM_SIGNAL_BOOLBUFF_SIZE            656u
#define COM_RXGROUPSIGNAL_BOOLBUFF_SIZE     317u
#define COM_SIGNAL_BOOL_INVALID_SIZE        0u

#define COM_SIGNAL_8BITBUFF_SIZE            1326u
#define COM_RXGROUPSIGNAL_8BITBUFF_SIZE     722u
#define COM_SIGNAL_8BIT_INVALID_SIZE        1u

#define COM_SIGNAL_16BITBUFF_SIZE           278u
#define COM_RXGROUPSIGNAL_16BITBUFF_SIZE    214u
#define COM_SIGNAL_16BIT_INVALID_SIZE       0u

#define COM_SIGNAL_32BITBUFF_SIZE           4u
#define COM_RXGROUPSIGNAL_32BITBUFF_SIZE    4u
#define COM_SIGNAL_32BIT_INVALID_SIZE       0u

#define COM_SIGNAL_64BITBUFF_SIZE           2u
#define COM_RXGROUPSIGNAL_64BITBUFF_SIZE    1u
#define COM_SIGNAL_64BIT_INVALID_SIZE       0u

#define COM_TMCTXSIGNAL_NUMBER              0u
#define COM_TMCTXGROUPSIGNAL_NUMBER         0u

#define COM_TXSIGNALGROUP_NUMBER            34u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA               0u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA               1u
#define AC_3_State_CHA_IPDU_COM_AC_3_State_CHA               2u
#define AC_ACStatuts_BOD_IPDU_COM_AC_ACStatuts_BOD               3u
#define AC_COMP_BOD_IPDU_COM_AC_COMP_BOD               4u
#define VCU_7_DrvRange_BOD_IPDU_COM_VCU_7_DrvRange_BOD               5u
#define AC_1_Command_BOD_IPDU_COM_AC_1_Command_BOD               6u
#define HVCH_Command_BOD_IPDU_COM_HVCH_Command_BOD               7u
#define AC_3_State_BOD_IPDU_COM_AC_3_State_BOD               8u
#define AC_2_State_BOD_IPDU_COM_AC_2_State_BOD               9u
#define AC_8_status_BOD_IPDU_COM_AC_8_status_BOD               10u
#define TMS_LINTestData1_BOD_IPDU_COM_TMS_LINTestData1_BOD               11u
#define TMS_LINTestData2_BOD_IPDU_COM_TMS_LINTestData2_BOD               12u
#define TMS_LINTestData3_BOD_IPDU_COM_TMS_LINTestData3_BOD               13u
#define VCU_3_OprtCmd_EPT_IPDU_COM_VCU_3_OprtCmd_EPT               14u
#define VCU_4_ChrgCmd_EPT_IPDU_COM_VCU_4_ChrgCmd_EPT               15u
#define VCU_B_AcclPedal_EPT_IPDU_COM_VCU_B_AcclPedal_EPT               16u
#define VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT               17u
#define VCU_0_Value_EPT_IPDU_COM_VCU_0_Value_EPT               18u
#define VCU_C_OprtCmd_EPT_IPDU_COM_VCU_C_OprtCmd_EPT               19u
#define BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT               20u
#define AC_ACStatuts_BAC_IPDU_COM_AC_ACStatuts_BAC               21u
#define AC_3_State_BAC_IPDU_COM_AC_3_State_BAC               22u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC               23u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1               24u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1               25u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1               26u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               27u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6               28u
#define BCM_ESCLCommand_BOD_IPDU_COM_TX_BCM_ESCLCommand_BOD_CANFD5_BOD_CAN6               29u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5               30u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5               31u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               32u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2               33u

#define COM_RXSIGNALGROUP_NUMBER            63u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA               0u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA               1u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA               2u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA               3u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA               4u
#define SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA               5u
#define SRS_3_YRSActualSts_CHA_IPDU_COM_SRS_3_YRSActualSts_CHA               6u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA               7u
#define EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA               8u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA               9u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA               10u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA               11u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD               12u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD               13u
#define TPMS_Info_BOD_IPDU_COM_TPMS_Info_BOD               14u
#define ESCL_ESCLStatus_BOD_IPDU_COM_ESCL_ESCLStatus_BOD               15u
#define AVAS_State_BOD_IPDU_COM_AVAS_State_BOD               16u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD               17u
#define ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD               18u
#define HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD               19u
#define HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD               20u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT               21u
#define BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT               22u
#define BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT               23u
#define BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT               24u
#define BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT               25u
#define BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT               26u
#define BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT               27u
#define BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT               28u
#define BMS_8_TempVoltLimit_EPT_IPDU_COM_BMS_8_TempVoltLimit_EPT               29u
#define BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT               30u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT               31u
#define BMS_B_GB_EPT_IPDU_COM_BMS_B_GB_EPT               32u
#define BMS_C_GB_EPT_IPDU_COM_BMS_C_GB_EPT               33u
#define BMS_D_GB_EPT_IPDU_COM_BMS_D_GB_EPT               34u
#define IPU_OBC_3_CP_CC_EPT_IPDU_COM_IPU_OBC_3_CP_CC_EPT               35u
#define IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT               36u
#define IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT               37u
#define IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT               38u
#define IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT               39u
#define IPU_OBC_4_state_EPT_IPDU_COM_IPU_OBC_4_state_EPT               40u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT               41u
#define INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT               42u
#define INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT               43u
#define INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT               44u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT               45u
#define INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT               46u
#define ICU_Info_BAC_IPDU_COM_ICU_Info_BAC               47u
#define ICU_2_Odo_BAC_IPDU_COM_ICU_2_Odo_BAC               48u
#define HU_C_BAC_IPDU_COM_HU_C_BAC               49u
#define TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC               50u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1               51u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1               52u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6               53u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5               54u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5               55u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5               56u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5               57u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5               58u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5               59u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5               60u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5               61u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5               62u

#define COM_TXSIGNAL_NUMBER                  179u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define Inca_Byte7_IPDU_COM_INCA_CRO               0u
#define Inca_Byte6_IPDU_COM_INCA_CRO               1u
#define Inca_Byte5_IPDU_COM_INCA_CRO               2u
#define Inca_Byte4_IPDU_COM_INCA_CRO               3u
#define Inca_Byte3_IPDU_COM_INCA_CRO               4u
#define Inca_Byte2_IPDU_COM_INCA_CRO               5u
#define Inca_Byte1_IPDU_COM_INCA_CRO               6u
#define Inca_Byte0_IPDU_COM_INCA_CRO               7u
#define HP_EXV_position_command_B_HP_EXV_Cmd_LIN1               8u
#define HP_EXV_movenable_command_B_HP_EXV_Cmd_LIN1               9u
#define HP_EXV_initialize_command_B_HP_EXV_Cmd_LIN1               10u
#define BAT_EXV_position_command_B_BAT_EXV_Cmd_LIN1               11u
#define BAT_EXV_movenable_command_B_BAT_EXV_Cmd_LIN1               12u
#define BAT_EXV_initialize_command_B_BAT_EXV_Cmd_LIN1               13u
#define TMM_EXV_PositionRequest_AC_EXV_Cmd_LIN1               14u
#define TMM_EXV_EnableRequest_AC_EXV_Cmd_LIN1               15u
#define TMM_EXV_initRequest_AC_EXV_Cmd_LIN1               16u
#define MCV_PosSetReq_MCV_Cmd_LIN1               17u
#define MCV_RefDrvReq_MCV_Cmd_LIN1               18u
#define MCV_SpdLvlReq_MCV_Cmd_LIN1               19u
#define BCV_PosSetReq_BCV_Cmd_LIN1               20u
#define BCV_RefDrvReq_BCV_Cmd_LIN1               21u
#define BCV_SpdLvlReq_BCV_Cmd_LIN1               22u
#define AcPMP_SpdSet_PMP_Cmd_LIN1               23u
#define BatPMP_SpdSet_PMP_Cmd_LIN1               24u
#define MotPMP_SpdSet_PMP_Cmd_LIN1               25u
#define TMM_EXV_PositionRequest_AC_EXV_Cmd_LIN2               26u
#define TMM_EXV_EnableRequest_AC_EXV_Cmd_LIN2               27u
#define TMM_EXV_initRequest_AC_EXV_Cmd_LIN2               28u
#define BAT_EXV_position_command_B_BAT_EXV_Cmd_LIN2               29u
#define BAT_EXV_movenable_command_B_BAT_EXV_Cmd_LIN2               30u
#define BAT_EXV_initialize_command_B_BAT_EXV_Cmd_LIN2               31u
#define C3WV_BPosSetReq_C3WV_Cmd_LIN2               32u
#define C3WV_RefDrvReq_C3WV_Cmd_LIN2               33u
#define C3WV_SpdLvlReq_C3WV_Cmd_LIN2               34u
#define C5WV_BPosSetReq_C5WV_Cmd_LIN2               35u
#define C5WV_RefDrvReq_C5WV_Cmd_LIN2               36u
#define C5WV_SpdLvlReq_C5WV_Cmd_LIN2               37u
#define HP_EXV_position_command_B_HP_EXV_Cmd_LIN2               38u
#define HP_EXV_movenable_command_B_HP_EXV_Cmd_LIN2               39u
#define HP_EXV_initialize_command_B_HP_EXV_Cmd_LIN2               40u
#define AcPMP_SpdSet_PMP_Cmd_LIN2               41u
#define BatPMP_SpdSet_PMP_Cmd_LIN2               42u
#define MotPMP_SpdSet_PMP_Cmd_LIN2               43u
#define Sig_Cmd_TiLeLightReq_CCU_FCLCommand_LIN3               44u
#define Sig_Cmd_TiRiLightReq_CCU_FCLCommand_LIN3               45u
#define Sig_Cmd_TiWngFBSt_CCU_FCLCommand_LIN3               46u
#define Sig_Cmd_PosLightReq_CCU_FCLCommand_LIN3               47u
#define Sig_Cmd_DrlLightReq_CCU_FCLCommand_LIN3               48u
#define CCU_ToInterlock_Status_Frm_VehicleToInterlock_LIN3               49u
#define CCU_ToInterlock_Payload1_Frm_VehicleToInterlock_LIN3               50u
#define CCU_ToInterlock_Payload2_Frm_VehicleToInterlock_LIN3               51u
#define CCU_ToInterlock_Payload3_Frm_VehicleToInterlock_LIN3               52u
#define CCU_ToInterlock_Payload4_Frm_VehicleToInterlock_LIN3               53u
#define CCU_ToInterlock_Payload5_Frm_VehicleToInterlock_LIN3               54u
#define CCU_ToInterlock_Payload6_Frm_VehicleToInterlock_LIN3               55u
#define CCU_ToInterlock_Payload7_Frm_VehicleToInterlock_LIN3               56u
#define VCU_WheelTorque_Chksum_IPDU_COM_VCU_10_Torque_CHA               57u
#define VCU_WheelTorque_AliveCnt_IPDU_COM_VCU_10_Torque_CHA               58u
#define VCU_PwrRecup_Chksum_IPDU_COM_VCU_10_Torque_CHA               59u
#define VCU_PwrRecup_AliveCnt_IPDU_COM_VCU_10_Torque_CHA               60u
#define VCU_Torque_Chksum_IPDU_COM_VCU_10_Torque_CHA               61u
#define VCU_Torque_AliveCnt_IPDU_COM_VCU_10_Torque_CHA               62u
#define VCU_SigToEHB_Chksum_IPDU_COM_VCU_10_Torque_CHA               63u
#define VCU_SigToEHB_AliveCnt_IPDU_COM_VCU_10_Torque_CHA               64u
#define BCM_4_Chksum_IPDU_COM_BCM_4_CruiseSw_PM_CHA               65u
#define BCM_4_AliveCnt_IPDU_COM_BCM_4_CruiseSw_PM_CHA               66u
#define AC_3_Chksum_IPDU_COM_AC_3_State_CHA               67u
#define AC_3_AliveCnt_IPDU_COM_AC_3_State_CHA               68u
#define AC_ACStatus_Chksum_IPDU_COM_AC_ACStatuts_BOD               69u
#define AC_ACStatus_AliveCnt_IPDU_COM_AC_ACStatuts_BOD               70u
#define AC_Checksum_IPDU_COM_AC_COMP_BOD               71u
#define AC_RollingCounter_IPDU_COM_AC_COMP_BOD               72u
#define VCU_7_Chksum_IPDU_COM_VCU_7_DrvRange_BOD               73u
#define VCU_7_AliveCnt_IPDU_COM_VCU_7_DrvRange_BOD               74u
#define AC_1_Chksum_IPDU_COM_AC_1_Command_BOD               75u
#define AC_1_AliveCnt_IPDU_COM_AC_1_Command_BOD               76u
#define HVCHCmd_Checksum_IPDU_COM_HVCH_Command_BOD               77u
#define HVCHCmd_RollingCounter_IPDU_COM_HVCH_Command_BOD               78u
#define AC_3_Chksum_IPDU_COM_AC_3_State_BOD               79u
#define AC_3_AliveCnt_IPDU_COM_AC_3_State_BOD               80u
#define AC_2_Chksum_IPDU_COM_AC_2_State_BOD               81u
#define AC_2_AliveCnt_IPDU_COM_AC_2_State_BOD               82u
#define AC_8_Checksum_IPDU_COM_AC_8_status_BOD               83u
#define AC_8_RollingCounter_IPDU_COM_AC_8_status_BOD               84u
#define VCU_3_Chksum_IPDU_COM_VCU_3_OprtCmd_EPT               85u
#define VCU_3_AliveCnt_IPDU_COM_VCU_3_OprtCmd_EPT               86u
#define VCU_4_Chksum_IPDU_COM_VCU_4_ChrgCmd_EPT               87u
#define VCU_4_AliveCnt_IPDU_COM_VCU_4_ChrgCmd_EPT               88u
#define VCU_B_Chksum_IPDU_COM_VCU_B_AcclPedal_EPT               89u
#define VCU_B_AliveCnt_IPDU_COM_VCU_B_AcclPedal_EPT               90u
#define VCU_1_MsgCrc_IPDU_COM_VCU_1_InvCmd_EPT               91u
#define VCU_1_MsgCnt_IPDU_COM_VCU_1_InvCmd_EPT               92u
#define VCU_0_Chksum_IPDU_COM_VCU_0_Value_EPT               93u
#define VCU_0_AliveCnt_IPDU_COM_VCU_0_Value_EPT               94u
#define VCU_C_Chksum_IPDU_COM_VCU_C_OprtCmd_EPT               95u
#define VCU_C_AliveCnt_IPDU_COM_VCU_C_OprtCmd_EPT               96u
#define AC_ACStatus_Chksum_IPDU_COM_AC_ACStatuts_BAC               97u
#define AC_ACStatus_AliveCnt_IPDU_COM_AC_ACStatuts_BAC               98u
#define AC_3_Chksum_IPDU_COM_AC_3_State_BAC               99u
#define AC_3_AliveCnt_IPDU_COM_AC_3_State_BAC               100u
#define CCU_RepeatSts_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1               101u
#define CCU_WakeupReas_IGN_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1               102u
#define CCU_WakeupReas_OBC_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1               103u
#define CCU_WakeupReas_BMS_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1               104u
#define CCU_WakeupReas_Others_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1               105u
#define CCU_KeepAwakePwrMode_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1               106u
#define CCU_KeepAwakeReasDiag_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1               107u
#define CCU_KeepAwakeReasOBC_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1               108u
#define CCU_KeepAwakeReasBMS_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1               109u
#define CCU_KeepAwakeSta_IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1               110u
#define CCU_RepeatSts_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6               111u
#define CCU_WakeupReas_IGN_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6               112u
#define CCU_WakeupReas_OBC_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6               113u
#define CCU_WakeupReas_BMS_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6               114u
#define CCU_WakeupReas_Others_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6               115u
#define CCU_KeepAwakePwrMode_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6               116u
#define CCU_KeepAwakeReasDiag_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6               117u
#define CCU_KeepAwakeReasOBC_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6               118u
#define CCU_KeepAwakeReasBMS_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6               119u
#define CCU_KeepAwakeSta_IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6               120u
#define CCU_RepeatSts_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5               121u
#define CCU_WakeupReas_IGN_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5               122u
#define CCU_WakeupReas_OBC_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5               123u
#define CCU_WakeupReas_BMS_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5               124u
#define CCU_WakeupReas_Others_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5               125u
#define CCU_KeepAwakePwrMode_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5               126u
#define CCU_KeepAwakeReasDiag_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5               127u
#define CCU_KeepAwakeReasOBC_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5               128u
#define CCU_KeepAwakeReasBMS_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5               129u
#define CCU_KeepAwakeSta_IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5               130u
#define CCU_RepeatSts_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2               131u
#define CCU_WakeupReas_IGN_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2               132u
#define CCU_WakeupReas_OBC_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2               133u
#define CCU_WakeupReas_BMS_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2               134u
#define CCU_WakeupReas_Others_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2               135u
#define CCU_KeepAwakePwrMode_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2               136u
#define CCU_KeepAwakeReasDiag_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2               137u
#define CCU_KeepAwakeReasOBC_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2               138u
#define CCU_KeepAwakeReasBMS_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2               139u
#define CCU_KeepAwakeSta_IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2               140u
#define CCU_Info_Chksum_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1               141u
#define CCU_Info_AliveCnt_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1               142u
#define VCU_12_Chksum_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1               143u
#define VCU_12_AliveCnt_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1               144u
#define BCM_B_LampDoorHorn_Chksum_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               145u
#define BCM_B_LampDoorHorn_AliveCnt_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               146u
#define BCM_B_FrntTPMS_Chksum_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               147u
#define BCM_B_FrntTPMS_AliveCnt_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               148u
#define BCM_B_RearTPMS_Chksum_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               149u
#define BCM_B_WIperWindow_Chksum_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               150u
#define BCM_B_WiperWIndow_AliveCnt_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               151u
#define BCM_B_PEPS_Chksum_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               152u
#define BCM_B_PEPS_AliveCnt_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               153u
#define BCM_B_PEPS2_Chksum_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               154u
#define BCM_B_PEPS2_AliveCnt_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               155u
#define BCM_B_Heating_Chksum_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               156u
#define BCM_B_Heating_AliveCnt_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1               157u
#define CCU_Info_Chksum_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6               158u
#define CCU_Info_AliveCnt_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6               159u
#define CCU_Info_Chksum_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5               160u
#define CCU_Info_AliveCnt_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5               161u
#define VCU_12_Chksum_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5               162u
#define VCU_12_AliveCnt_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5               163u
#define BCM_B_LampDoorHorn_Chksum_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               164u
#define BCM_B_LampDoorHorn_AliveCnt_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               165u
#define BCM_B_FrntTPMS_Chksum_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               166u
#define BCM_B_FrntTPMS_AliveCnt_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               167u
#define BCM_B_RearTPMS_Chksum_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               168u
#define BCM_B_WIperWindow_Chksum_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               169u
#define BCM_B_WiperWIndow_AliveCnt_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               170u
#define BCM_B_PEPS_Chksum_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               171u
#define BCM_B_PEPS_AliveCnt_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               172u
#define BCM_B_PEPS2_Chksum_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               173u
#define BCM_B_PEPS2_AliveCnt_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               174u
#define BCM_B_Heating_Chksum_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               175u
#define BCM_B_Heating_AliveCnt_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5               176u
#define CCU_Info_Chksum_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2               177u
#define CCU_Info_AliveCnt_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2               178u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */
#define COM_RXSIGNAL_NUMBER               205u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define Tmsr_Byte3_IPDU_COM_TMSR_DTO             0u
#define Tmsr_Byte7_IPDU_COM_TMSR_DTO             1u
#define Tmsr_Byte6_IPDU_COM_TMSR_DTO             2u
#define Tmsr_Byte5_IPDU_COM_TMSR_DTO             3u
#define Tmsr_Byte4_IPDU_COM_TMSR_DTO             4u
#define Tmsr_Byte2_IPDU_COM_TMSR_DTO             5u
#define Tmsr_Byte1_IPDU_COM_TMSR_DTO             6u
#define Tmsr_Byte0_IPDU_COM_TMSR_DTO             7u
#define HP_EXV_initialize_status_HP_EXV__Rsp_LIN1             8u
#define HP_EXV_SupplierLabel_HP_EXV__Rsp_LIN1             9u
#define HP_EXV_Warning_OverTemp_HP_EXV__Rsp_LIN1             10u
#define HP_EXV_ResponseError_B_HP_EXV__Rsp_LIN1             11u
#define HP_EXV_RunState_B_HP_EXV__Rsp_LIN1             12u
#define HP_EXV_FaultState_B_HP_EXV__Rsp_LIN1             13u
#define HP_EXV_VoltageState_B_HP_EXV__Rsp_LIN1             14u
#define HP_EXV_CurrentPosition_B_HP_EXV__Rsp_LIN1             15u
#define BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN1             16u
#define BAT_EXV_CurrentInitState_B_BAT_EXV_Rsp_LIN1             17u
#define BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN1             18u
#define BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN1             19u
#define BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN1             20u
#define BAT_EXV_TemperatureWarn_B_BAT_EXV_Rsp_LIN1             21u
#define BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN1             22u
#define BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN1             23u
#define EXV_ResponseError_AC_EXV_Rsp_LIN1             24u
#define EXV_CurrentInitState_AC_EXV_Rsp_LIN1             25u
#define EXV_RunState_AC_EXV_Rsp_LIN1             26u
#define EXV_FaultState_AC_EXV_Rsp_LIN1             27u
#define EXV_VoltageState_AC_EXV_Rsp_LIN1             28u
#define EXV_TemperatureWarn_AC_EXV_Rsp_LIN1             29u
#define EXV_CurrentPosition_AC_EXV_Rsp_LIN1             30u
#define MCV_FltSts_MCV_Sts_LIN1             31u
#define MCV_Mode_MCV_Sts_LIN1             32u
#define MCV_PosRec_MCV_Sts_LIN1             33u
#define MCV_RunSts_MCV_Sts_LIN1             34u
#define MCV_SpdLvl_MCV_Sts_LIN1             35u
#define MCV_TempSts_MCV_Sts_LIN1             36u
#define MCV_VoltSts_MCV_Sts_LIN1             37u
#define MCV_ErrResp_MCV_Sts_LIN1             38u
#define BCV_FltSts_BCV_Sts_LIN1             39u
#define BCV_Mode_BCV_Sts_LIN1             40u
#define BCV_PosRec_BCV_Sts_LIN1             41u
#define BCV_RunSts_BCV_Sts_LIN1             42u
#define BCV_SpdLvl_BCV_Sts_LIN1             43u
#define BCV_TempSts_BCV_Sts_LIN1             44u
#define BCV_VoltSts_BCV_Sts_LIN1             45u
#define BCV_ErrResp_BCV_Sts_LIN1             46u
#define MotPMP_RESP_ERROR_MotPMP_Sts_LIN1             47u
#define MotPMP_PumpMotorSta_MotPMP_Sts_LIN1             48u
#define MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN1             49u
#define MotPMP_PumpPowerSta_MotPMP_Sts_LIN1             50u
#define MotPMP_PumpTempSta_MotPMP_Sts_LIN1             51u
#define MotPMP_PumpInputVolt_MotPMP_Sts_LIN1             52u
#define MotPMP_RealRPM_MotPMP_Sts_LIN1             53u
#define BatPMP_RESP_ERROR_BatPMP_Sts_LIN1             54u
#define BatPMP_PumpMotorSta_BatPMP_Sts_LIN1             55u
#define BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN1             56u
#define BatPMP_PumpPowerSta_BatPMP_Sts_LIN1             57u
#define BatPMP_PumpTempSta_BatPMP_Sts_LIN1             58u
#define BatPMP_PumpInputVolt_BatPMP_Sts_LIN1             59u
#define BatPMP_RealRPM_BatPMP_Sts_LIN1             60u
#define AcPMP_RESP_ERROR_AcPMP_Sts_LIN1             61u
#define AcPMP_PumpMotorSta_AcPMP_Sts_LIN1             62u
#define AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN1             63u
#define AcPMP_PumpPowerSta_AcPMP_Sts_LIN1             64u
#define AcPMP_PumpTempSta_AcPMP_Sts_LIN1             65u
#define AcPMP_PumpInputVolt_AcPMP_Sts_LIN1             66u
#define AcPMP_RealRPM_AcPMP_Sts_LIN1             67u
#define HP_EXV_ProjectCode1_HP_EXV_Version_LIN1             68u
#define HP_EXV_ProjectCode2_HP_EXV_Version_LIN1             69u
#define HP_EXV_SupplierNumber_HP_EXV_Version_LIN1             70u
#define HP_EXV_PartNumber_HP_EXV_Version_LIN1             71u
#define HP_EXV_HWVersion_HP_EXV_Version_LIN1             72u
#define HP_EXV_SWVersion_Main_HP_EXV_Version_LIN1             73u
#define HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN1             74u
#define HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN1             75u
#define Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN1             76u
#define Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN1             77u
#define Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN1             78u
#define Bat_EXV_PartNumber_Bat_EXV_Version_LIN1             79u
#define Bat_EXV_HWVersion_Bat_EXV_Version_LIN1             80u
#define Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN1             81u
#define Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN1             82u
#define Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN1             83u
#define MCV_ProjectCode1_MCV_Version_LIN1             84u
#define MCV_ProjectCode2_MCV_Version_LIN1             85u
#define MCV_SupplierNumber_MCV_Version_LIN1             86u
#define MCV_PartNumber_MCV_Version_LIN1             87u
#define MCV_HWVersion_MCV_Version_LIN1             88u
#define MCV_SWVersion_Main_MCV_Version_LIN1             89u
#define MCV_SWVersion_Sub_MCV_Version_LIN1             90u
#define MCV_SWVersion_Patch_MCV_Version_LIN1             91u
#define BCV_ProjectCode1_BCV_Version_LIN1             92u
#define BCV_ProjectCode2_BCV_Version_LIN1             93u
#define BCV_SupplierNumber_BCV_Version_LIN1             94u
#define BCV_PartNumber_BCV_Version_LIN1             95u
#define BCV_HWVersion_BCV_Version_LIN1             96u
#define BCV_SWVersion_Main_BCV_Version_LIN1             97u
#define BCV_SWVersion_Sub_BCV_Version_LIN1             98u
#define BCV_SWVersion_Patch_BCV_Version_LIN1             99u
#define AcPMP_ProjectCode1_AcPMP_Version_LIN1             100u
#define AcPMP_ProjectCode2_AcPMP_Version_LIN1             101u
#define AcPMP_SupplierNumber_AcPMP_Version_LIN1             102u
#define AcPMP_PartNumber_AcPMP_Version_LIN1             103u
#define AcPMP_HWVersion_AcPMP_Version_LIN1             104u
#define AcPMP_SWVersion_Main_AcPMP_Version_LIN1             105u
#define AcPMP_SWVersion_Sub_AcPMP_Version_LIN1             106u
#define AcPMP_SWVersion_Patch_AcPMP_Version_LIN1             107u
#define EXV_ResponseError_AC_EXV_Rsp_LIN2             108u
#define EXV_CurrentInitState_AC_EXV_Rsp_LIN2             109u
#define EXV_RunState_AC_EXV_Rsp_LIN2             110u
#define EXV_FaultState_AC_EXV_Rsp_LIN2             111u
#define EXV_VoltageState_AC_EXV_Rsp_LIN2             112u
#define EXV_TemperatureWarn_AC_EXV_Rsp_LIN2             113u
#define EXV_CurrentPosition_AC_EXV_Rsp_LIN2             114u
#define AcPMP_RESP_ERROR_AcPMP_Sts_LIN2             115u
#define AcPMP_PumpMotorSta_AcPMP_Sts_LIN2             116u
#define AcPMP_PumpDryRunningSta_AcPMP_Sts_LIN2             117u
#define AcPMP_PumpPowerSta_AcPMP_Sts_LIN2             118u
#define AcPMP_PumpTempSta_AcPMP_Sts_LIN2             119u
#define AcPMP_PumpInputVolt_AcPMP_Sts_LIN2             120u
#define AcPMP_RealRPM_AcPMP_Sts_LIN2             121u
#define AcPMP_ProjectCode1_AcPMP_Version_LIN2             122u
#define AcPMP_ProjectCode2_AcPMP_Version_LIN2             123u
#define AcPMP_SupplierNumber_AcPMP_Version_LIN2             124u
#define AcPMP_PartNumber_AcPMP_Version_LIN2             125u
#define AcPMP_HWVersion_AcPMP_Version_LIN2             126u
#define AcPMP_SWVersion_Main_AcPMP_Version_LIN2             127u
#define AcPMP_SWVersion_Sub_AcPMP_Version_LIN2             128u
#define AcPMP_SWVersion_Patch_AcPMP_Version_LIN2             129u
#define BAT_EXV_initialize_status_BAT_EXV_Rsp_LIN2             130u
#define BAT_EXV_SupplierLabel_BAT_EXV_Rsp_LIN2             131u
#define BAT_EXV_Warning_OverTemp_BAT_EXV_Rsp_LIN2             132u
#define BAT_EXV_ResponseError_B_BAT_EXV_Rsp_LIN2             133u
#define BAT_EXV_RunState_B_BAT_EXV_Rsp_LIN2             134u
#define BAT_EXV_FaultState_B_BAT_EXV_Rsp_LIN2             135u
#define BAT_EXV_VoltageState_B_BAT_EXV_Rsp_LIN2             136u
#define BAT_EXV_CurrentPosition_B_BAT_EXV_Rsp_LIN2             137u
#define BatPMP_RESP_ERROR_BatPMP_Sts_LIN2             138u
#define BatPMP_PumpMotorSta_BatPMP_Sts_LIN2             139u
#define BatPMP_PumpDryRunningSta_BatPMP_Sts_LIN2             140u
#define BatPMP_PumpPowerSta_BatPMP_Sts_LIN2             141u
#define BatPMP_PumpTempSta_BatPMP_Sts_LIN2             142u
#define BatPMP_PumpInputVolt_BatPMP_Sts_LIN2             143u
#define BatPMP_RealRPM_BatPMP_Sts_LIN2             144u
#define Bat_EXV_ProjectCode1_Bat_EXV_Version_LIN2             145u
#define Bat_EXV_ProjectCode2_Bat_EXV_Version_LIN2             146u
#define Bat_EXV_SupplierNumber_Bat_EXV_Version_LIN2             147u
#define Bat_EXV_PartNumber_Bat_EXV_Version_LIN2             148u
#define Bat_EXV_HWVersion_Bat_EXV_Version_LIN2             149u
#define Bat_EXV_SWVersion_Main_Bat_EXV_Version_LIN2             150u
#define Bat_EXV_SWVersion_Sub_Bat_EXV_Version_LIN2             151u
#define Bat_EXV_SWVersion_Patch_Bat_EXV_Version_LIN2             152u
#define C3WV_FltSts_C3WV_Sts_LIN2             153u
#define C3WV_Mode_C3WV_Sts_LIN2             154u
#define C3WV_PosRec_C3WV_Sts_LIN2             155u
#define C3WV_RunSts_C3WV_Sts_LIN2             156u
#define C3WV_SpdLvl_C3WV_Sts_LIN2             157u
#define C3WV_TempSts_C3WV_Sts_LIN2             158u
#define C3WV_VoltSts_C3WV_Sts_LIN2             159u
#define C3WV_ErrResp_C3WV_Sts_LIN2             160u
#define C5WVFltSts_C5WV_Sts_LIN2             161u
#define C5WVMode_C5WV_Sts_LIN2             162u
#define C5WVPosRec_C5WV_Sts_LIN2             163u
#define C5WVRunSts_C5WV_Sts_LIN2             164u
#define C5WVSpdLvl_C5WV_Sts_LIN2             165u
#define C5WVTempSts_C5WV_Sts_LIN2             166u
#define C5WVVoltSts_C5WV_Sts_LIN2             167u
#define ErrRespC5WV_C5WV_Sts_LIN2             168u
#define HP_EXV_initialize_status_HP_EXV_Rsp_LIN2             169u
#define HP_EXV_SupplierLabel_HP_EXV_Rsp_LIN2             170u
#define HP_EXV_Warning_OverTemp_HP_EXV_Rsp_LIN2             171u
#define HP_EXV_ResponseError_B_HP_EXV_Rsp_LIN2             172u
#define HP_EXV_RunState_B_HP_EXV_Rsp_LIN2             173u
#define HP_EXV_FaultState_B_HP_EXV_Rsp_LIN2             174u
#define HP_EXV_VoltageState_B_HP_EXV_Rsp_LIN2             175u
#define HP_EXV_CurrentPosition_B_HP_EXV_Rsp_LIN2             176u
#define HP_EXV_ProjectCode1_HP_EXV_Version_LIN2             177u
#define HP_EXV_ProjectCode2_HP_EXV_Version_LIN2             178u
#define HP_EXV_SupplierNumber_HP_EXV_Version_LIN2             179u
#define HP_EXV_PartNumber_HP_EXV_Version_LIN2             180u
#define HP_EXV_HWVersion_HP_EXV_Version_LIN2             181u
#define HP_EXV_SWVersion_Main_HP_EXV_Version_LIN2             182u
#define HP_EXV_SWVersion_Sub_HP_EXV_Version_LIN2             183u
#define HP_EXV_SWVersion_Patch_HP_EXV_Version_LIN2             184u
#define MotPMP_RESP_ERROR_MotPMP_Sts_LIN2             185u
#define MotPMP_PumpMotorSta_MotPMP_Sts_LIN2             186u
#define MotPMP_PumpDryRunningSta_MotPMP_Sts_LIN2             187u
#define MotPMP_PumpPowerSta_MotPMP_Sts_LIN2             188u
#define MotPMP_PumpTempSta_MotPMP_Sts_LIN2             189u
#define MotPMP_PumpInputVolt_MotPMP_Sts_LIN2             190u
#define MotPMP_RealRPM_MotPMP_Sts_LIN2             191u
#define FCLL_TiWngSt_FCLL_Status_LIN3             192u
#define FCLL_RespError_FCLL_Status_LIN3             193u
#define FCLR_TiWngSt_FCLR_Status_LIN3             194u
#define FCLR_RespError_FCLR_Status_LIN3             195u
#define AIL_Interlock_RespError_Frm_InterlockStatus_LIN3             196u
#define AIL_FromInterlock_Status_Frm_InterlockToVehicle_LIN3             197u
#define AIL_FromInterlock_BlockingLSB_Frm_InterlockToVehicle_LIN3             198u
#define AIL_FromInterlock_BlockingMSB_Frm_InterlockToVehicle_LIN3             199u
#define AIL_FromInterlock_Payload1_Frm_InterlockToVehicle_LIN3             200u
#define AIL_FromInterlock_Payload2_Frm_InterlockToVehicle_LIN3             201u
#define AIL_FromInterlock_Payload3_Frm_InterlockToVehicle_LIN3             202u
#define AIL_FromInterlock_Payload4_Frm_InterlockToVehicle_LIN3             203u
#define AIL_FromInterlock_Payload5_Frm_InterlockToVehicle_LIN3             204u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */
#define COM_GWSOURCESIGNAL_UPDATE_NUMBER           0u
#define COM_ONEEVERYNFILTERSIGNAL_NUMBER           0u
#define COM_RXSIGNALMASKNEWDIFFERMASKOLD_NUMBER    0u

#define COM_GWSIGNAL_BOOLBUFF_SIZE          0u
#define COM_GWSIGNAL_8BITBUFF_SIZE          0u
#define COM_GWSIGNAL_16BITBUFF_SIZE         0u
#define COM_GWSIGNAL_32BITBUFF_SIZE         0u
#define COM_GWSIGNAL_64BITBUFF_SIZE         0u

#define COM_TXGROUPSIGNAL_NUMBER        624u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_ActWhlTqVld_IPDU_COM_VCU_10_Torque_CHA             179u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_ActWhlTq_IPDU_COM_VCU_10_Torque_CHA             180u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_DrvReqWhlTqVld_IPDU_COM_VCU_10_Torque_CHA             181u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_DrvReqWhlTq_IPDU_COM_VCU_10_Torque_CHA             182u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_DrvWhlTqAllwdMax_IPDU_COM_VCU_10_Torque_CHA             183u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_PwrRecupActlWhlTqSts_IPDU_COM_VCU_10_Torque_CHA             184u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_PwrRecupMaxAvlbWhlTqSts_IPDU_COM_VCU_10_Torque_CHA             185u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_BrkPwrRecupMaxAvlbWhlTq_IPDU_COM_VCU_10_Torque_CHA             186u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_PwrRecupActWhlTq_IPDU_COM_VCU_10_Torque_CHA             187u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_AccReqDriveOff_IPDU_COM_VCU_10_Torque_CHA             188u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_BrkPwrRecupActlWhlTqSts_IPDU_COM_VCU_10_Torque_CHA             189u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_BrkPwrRecupActWhlTq_IPDU_COM_VCU_10_Torque_CHA             190u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_Actl_MotorRotateSpdV_IPDU_COM_VCU_10_Torque_CHA             191u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_Actl_MotorRotateSpd_IPDU_COM_VCU_10_Torque_CHA             192u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_Actl_MotorTorque_IPDU_COM_VCU_10_Torque_CHA             193u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_DrvReq_MotorTorq_IPDU_COM_VCU_10_Torque_CHA             194u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_Actl_MotorTorqueV_IPDU_COM_VCU_10_Torque_CHA             195u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_EparkSysSta_IPDU_COM_VCU_10_Torque_CHA             196u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_VhclSpeedFastWarn_IPDU_COM_VCU_10_Torque_CHA             197u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_DrvReq_MotorTorqV_IPDU_COM_VCU_10_Torque_CHA             198u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_EnaEHBBrkRun_IPDU_COM_VCU_10_Torque_CHA             199u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_AccReqStandstill_IPDU_COM_VCU_10_Torque_CHA             200u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_1_MotTorqueReqToEHB_IPDU_COM_VCU_10_Torque_CHA             201u
#define VCU_10_Torque_CHA_IPDU_COM_VCU_10_Torque_CHA_VCU_MasterCylinderPreReq_IPDU_COM_VCU_10_Torque_CHA             202u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_CruiseDistanceSet_IPDU_COM_BCM_4_CruiseSw_PM_CHA             203u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_CruiseDistanceDecre_IPDU_COM_BCM_4_CruiseSw_PM_CHA             204u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_CruiseModeCancel_IPDU_COM_BCM_4_CruiseSw_PM_CHA             205u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_SpeedUp_IPDU_COM_BCM_4_CruiseSw_PM_CHA             206u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_SpeedDown_IPDU_COM_BCM_4_CruiseSw_PM_CHA             207u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_CruiseModeChange_IPDU_COM_BCM_4_CruiseSw_PM_CHA             208u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_SpeedUp_Valid_IPDU_COM_BCM_4_CruiseSw_PM_CHA             209u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_Cruise_limit_reserved_IPDU_COM_BCM_4_CruiseSw_PM_CHA             210u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_CruiseMainSwitch_IPDU_COM_BCM_4_CruiseSw_PM_CHA             211u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_IMMOFailWarn_IPDU_COM_BCM_4_CruiseSw_PM_CHA             212u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_ThermRunawayVlvSt_IPDU_COM_BCM_4_CruiseSw_PM_CHA             213u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_ThermRunawaySnsrFlt_IPDU_COM_BCM_4_CruiseSw_PM_CHA             214u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_ThermRunawayWarn_IPDU_COM_BCM_4_CruiseSw_PM_CHA             215u
#define BCM_4_CruiseSw_PM_CHA_IPDU_COM_BCM_4_CruiseSw_PM_CHA_BCM_vSetDis_IPDU_COM_BCM_4_CruiseSw_PM_CHA             216u
#define AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_AC_ExtdDefrostActvReq_IPDU_COM_AC_3_State_CHA             217u
#define AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_AC_EnvirTempV_IPDU_COM_AC_3_State_CHA             218u
#define AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_AC_IndoorTemp_IPDU_COM_AC_3_State_CHA             219u
#define AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_AC_EnvirTemp_IPDU_COM_AC_3_State_CHA             220u
#define AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_TMS_OHXOutTmp_IPDU_COM_AC_3_State_CHA             221u
#define AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_TMS_EvapTmp_IPDU_COM_AC_3_State_CHA             222u
#define AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_TMS_EvapOutTmp_IPDU_COM_AC_3_State_CHA             223u
#define AC_3_State_CHA_IPDU_COM_AC_3_State_CHA_TMS_ChillerOutTmp_IPDU_COM_AC_3_State_CHA             224u
#define AC_ACStatuts_BOD_IPDU_COM_AC_ACStatuts_BOD_AC_leftTempValue_IPDU_COM_AC_ACStatuts_BOD             225u
#define AC_ACStatuts_BOD_IPDU_COM_AC_ACStatuts_BOD_AC_ManualDefrostFb_IPDU_COM_AC_ACStatuts_BOD             226u
#define AC_ACStatuts_BOD_IPDU_COM_AC_ACStatuts_BOD_AC_ACAutoFb_IPDU_COM_AC_ACStatuts_BOD             227u
#define AC_ACStatuts_BOD_IPDU_COM_AC_ACStatuts_BOD_AC_BlowerModeSta_IPDU_COM_AC_ACStatuts_BOD             228u
#define AC_ACStatuts_BOD_IPDU_COM_AC_ACStatuts_BOD_AC_FrontFanSpdValue_IPDU_COM_AC_ACStatuts_BOD             229u
#define AC_ACStatuts_BOD_IPDU_COM_AC_ACStatuts_BOD_AC_ACPowerFb_IPDU_COM_AC_ACStatuts_BOD             230u
#define AC_ACStatuts_BOD_IPDU_COM_AC_ACStatuts_BOD_AC_AutoBlowerModeSta_IPDU_COM_AC_ACStatuts_BOD             231u
#define AC_ACStatuts_BOD_IPDU_COM_AC_ACStatuts_BOD_AC_HybridEcoModeSta_IPDU_COM_AC_ACStatuts_BOD             232u
#define AC_ACStatuts_BOD_IPDU_COM_AC_ACStatuts_BOD_AC_AirInletModeSta_IPDU_COM_AC_ACStatuts_BOD             233u
#define AC_ACStatuts_BOD_IPDU_COM_AC_ACStatuts_BOD_BCM_RearViewMirrHeatingSts_IPDU_COM_AC_ACStatuts_BOD             234u
#define AC_COMP_BOD_IPDU_COM_AC_COMP_BOD_COMP_EcompSpeedCtrl_IPDU_COM_AC_COMP_BOD             235u
#define AC_COMP_BOD_IPDU_COM_AC_COMP_BOD_COMP_EcompEnable_IPDU_COM_AC_COMP_BOD             236u
#define AC_COMP_BOD_IPDU_COM_AC_COMP_BOD_COMP_EcompHVSt_IPDU_COM_AC_COMP_BOD             237u
#define AC_COMP_BOD_IPDU_COM_AC_COMP_BOD_COMP_EcompErrorClean_IPDU_COM_AC_COMP_BOD             238u
#define AC_COMP_BOD_IPDU_COM_AC_COMP_BOD_COMP_CompInputPowerLimit_IPDU_COM_AC_COMP_BOD             239u
#define AC_COMP_BOD_IPDU_COM_AC_COMP_BOD_TMS_ACPExhaustTmp_IPDU_COM_AC_COMP_BOD             240u
#define AC_COMP_BOD_IPDU_COM_AC_COMP_BOD_TMS_ACPInletPressure_IPDU_COM_AC_COMP_BOD             241u
#define VCU_7_DrvRange_BOD_IPDU_COM_VCU_7_DrvRange_BOD_TMS_PCUInletCooltTemp_IPDU_COM_VCU_7_DrvRange_BOD             242u
#define VCU_7_DrvRange_BOD_IPDU_COM_VCU_7_DrvRange_BOD_TMS_PwrCoolFanSpdDuty_IPDU_COM_VCU_7_DrvRange_BOD             243u
#define VCU_7_DrvRange_BOD_IPDU_COM_VCU_7_DrvRange_BOD_TMS_PCUInletCooltTempV_IPDU_COM_VCU_7_DrvRange_BOD             244u
#define VCU_7_DrvRange_BOD_IPDU_COM_VCU_7_DrvRange_BOD_VCU_PtReadyEna_IPDU_COM_VCU_7_DrvRange_BOD             245u
#define VCU_7_DrvRange_BOD_IPDU_COM_VCU_7_DrvRange_BOD_VCU_IBSWakeup_IPDU_COM_VCU_7_DrvRange_BOD             246u
#define VCU_7_DrvRange_BOD_IPDU_COM_VCU_7_DrvRange_BOD_VCU_ACCMOprtCmd_IPDU_COM_VCU_7_DrvRange_BOD             247u
#define AC_1_Command_BOD_IPDU_COM_AC_1_Command_BOD_AC_CompFailModeOprtSta_IPDU_COM_AC_1_Command_BOD             248u
#define AC_1_Command_BOD_IPDU_COM_AC_1_Command_BOD_AC_CompOprtReq_IPDU_COM_AC_1_Command_BOD             249u
#define AC_1_Command_BOD_IPDU_COM_AC_1_Command_BOD_AC_CompOprtEnaCmd_IPDU_COM_AC_1_Command_BOD             250u
#define AC_1_Command_BOD_IPDU_COM_AC_1_Command_BOD_AC_CompTgtSpd_IPDU_COM_AC_1_Command_BOD             251u
#define AC_1_Command_BOD_IPDU_COM_AC_1_Command_BOD_AC_CompMaxAllowPwrCmsp_IPDU_COM_AC_1_Command_BOD             252u
#define AC_1_Command_BOD_IPDU_COM_AC_1_Command_BOD_AC_PumpActlSpdDuty_IPDU_COM_AC_1_Command_BOD             253u
#define AC_1_Command_BOD_IPDU_COM_AC_1_Command_BOD_AC_HighVolDCTolalPwr_IPDU_COM_AC_1_Command_BOD             254u
#define AC_1_Command_BOD_IPDU_COM_AC_1_Command_BOD_AC_PumpActlSpdDutyV_IPDU_COM_AC_1_Command_BOD             255u
#define HVCH_Command_BOD_IPDU_COM_HVCH_Command_BOD_HVCH_RequestTemp_IPDU_COM_HVCH_Command_BOD             256u
#define HVCH_Command_BOD_IPDU_COM_HVCH_Command_BOD_HVCH_RequestPower_IPDU_COM_HVCH_Command_BOD             257u
#define HVCH_Command_BOD_IPDU_COM_HVCH_Command_BOD_HVCH_Enabled_IPDU_COM_HVCH_Command_BOD             258u
#define AC_3_State_BOD_IPDU_COM_AC_3_State_BOD_AC_ExtdDefrostActvReq_IPDU_COM_AC_3_State_BOD             259u
#define AC_3_State_BOD_IPDU_COM_AC_3_State_BOD_AC_EnvirTempV_IPDU_COM_AC_3_State_BOD             260u
#define AC_3_State_BOD_IPDU_COM_AC_3_State_BOD_AC_IndoorTemp_IPDU_COM_AC_3_State_BOD             261u
#define AC_3_State_BOD_IPDU_COM_AC_3_State_BOD_AC_EnvirTemp_IPDU_COM_AC_3_State_BOD             262u
#define AC_3_State_BOD_IPDU_COM_AC_3_State_BOD_TMS_OHXOutTmp_IPDU_COM_AC_3_State_BOD             263u
#define AC_3_State_BOD_IPDU_COM_AC_3_State_BOD_TMS_EvapTmp_IPDU_COM_AC_3_State_BOD             264u
#define AC_3_State_BOD_IPDU_COM_AC_3_State_BOD_TMS_EvapOutTmp_IPDU_COM_AC_3_State_BOD             265u
#define AC_3_State_BOD_IPDU_COM_AC_3_State_BOD_TMS_ChillerOutTmp_IPDU_COM_AC_3_State_BOD             266u
#define AC_2_State_BOD_IPDU_COM_AC_2_State_BOD_AC_HVHActlPwr_HVAC_IPDU_COM_AC_2_State_BOD             267u
#define AC_2_State_BOD_IPDU_COM_AC_2_State_BOD_AC_HVHDeviceInternTemp_HVAC_IPDU_COM_AC_2_State_BOD             268u
#define AC_2_State_BOD_IPDU_COM_AC_2_State_BOD_TMS_PTPressure_IPDU_COM_AC_2_State_BOD             269u
#define AC_2_State_BOD_IPDU_COM_AC_2_State_BOD_AC_ActTotalPower_IPDU_COM_AC_2_State_BOD             270u
#define AC_2_State_BOD_IPDU_COM_AC_2_State_BOD_AC_HVHFailSta_HVAC_IPDU_COM_AC_2_State_BOD             271u
#define AC_2_State_BOD_IPDU_COM_AC_2_State_BOD_AC_FailSta_IPDU_COM_AC_2_State_BOD             272u
#define AC_2_State_BOD_IPDU_COM_AC_2_State_BOD_TMSR_BattTempCtrlRmnSwtFb_IPDU_COM_AC_2_State_BOD             273u
#define AC_2_State_BOD_IPDU_COM_AC_2_State_BOD_AC_BatPumpFailSta_IPDU_COM_AC_2_State_BOD             274u
#define AC_2_State_BOD_IPDU_COM_AC_2_State_BOD_AC_HVHActlOprtMode_HVAC_IPDU_COM_AC_2_State_BOD             275u
#define AC_2_State_BOD_IPDU_COM_AC_2_State_BOD_AC_ActlOprtMode_IPDU_COM_AC_2_State_BOD             276u
#define AC_2_State_BOD_IPDU_COM_AC_2_State_BOD_TMS_PTTemp_IPDU_COM_AC_2_State_BOD             277u
#define AC_8_status_BOD_IPDU_COM_AC_8_status_BOD_AC_RefrgLoPressureV_IPDU_COM_AC_8_status_BOD             278u
#define AC_8_status_BOD_IPDU_COM_AC_8_status_BOD_AC_RefrgLoPressure_IPDU_COM_AC_8_status_BOD             279u
#define AC_8_status_BOD_IPDU_COM_AC_8_status_BOD_AC_L_Currt_Slct_Frg_Dirct_IPDU_COM_AC_8_status_BOD             280u
#define AC_8_status_BOD_IPDU_COM_AC_8_status_BOD_AC_HV_PTC_heating_rq_IPDU_COM_AC_8_status_BOD             281u
#define AC_8_status_BOD_IPDU_COM_AC_8_status_BOD_AC_HV_PTC_MediumTemp_IPDU_COM_AC_8_status_BOD             282u
#define AC_8_status_BOD_IPDU_COM_AC_8_status_BOD_AC_HV_PTC_InternalPCBTemp_IPDU_COM_AC_8_status_BOD             283u
#define AC_8_status_BOD_IPDU_COM_AC_8_status_BOD_AC_EvapTgtTemp_IPDU_COM_AC_8_status_BOD             284u
#define AC_8_status_BOD_IPDU_COM_AC_8_status_BOD_AC_HV_PTC_On_Rq_IPDU_COM_AC_8_status_BOD             285u
#define AC_8_status_BOD_IPDU_COM_AC_8_status_BOD_AC_Auto_FrontFanSpd_IPDU_COM_AC_8_status_BOD             286u
#define TMS_LINTestData1_BOD_IPDU_COM_TMS_LINTestData1_BOD_TMS_AcPMPSpdSet_IPDU_COM_TMS_LINTestData1_BOD             287u
#define TMS_LINTestData1_BOD_IPDU_COM_TMS_LINTestData1_BOD_TMS_BatPMPSpdSet_IPDU_COM_TMS_LINTestData1_BOD             288u
#define TMS_LINTestData1_BOD_IPDU_COM_TMS_LINTestData1_BOD_TMS_MotPMPSpdSet_IPDU_COM_TMS_LINTestData1_BOD             289u
#define TMS_LINTestData1_BOD_IPDU_COM_TMS_LINTestData1_BOD_TMS_MotPMPRealRPM_IPDU_COM_TMS_LINTestData1_BOD             290u
#define TMS_LINTestData1_BOD_IPDU_COM_TMS_LINTestData1_BOD_TMS_BatPMPRealRPM_IPDU_COM_TMS_LINTestData1_BOD             291u
#define TMS_LINTestData1_BOD_IPDU_COM_TMS_LINTestData1_BOD_TMS_AcPMPRealRPM_IPDU_COM_TMS_LINTestData1_BOD             292u
#define TMS_LINTestData1_BOD_IPDU_COM_TMS_LINTestData1_BOD_TMS_HPEXVPositionCmd_IPDU_COM_TMS_LINTestData1_BOD             293u
#define TMS_LINTestData2_BOD_IPDU_COM_TMS_LINTestData2_BOD_TMS_BEXVPositionCmd_IPDU_COM_TMS_LINTestData2_BOD             294u
#define TMS_LINTestData2_BOD_IPDU_COM_TMS_LINTestData2_BOD_TMS_BEXVCurrentPosition_IPDU_COM_TMS_LINTestData2_BOD             295u
#define TMS_LINTestData2_BOD_IPDU_COM_TMS_LINTestData2_BOD_TMS_AEXVPositionReq_IPDU_COM_TMS_LINTestData2_BOD             296u
#define TMS_LINTestData2_BOD_IPDU_COM_TMS_LINTestData2_BOD_TMS_AEXVCurrentPosition_IPDU_COM_TMS_LINTestData2_BOD             297u
#define TMS_LINTestData3_BOD_IPDU_COM_TMS_LINTestData3_BOD_TMS_HPEXVCurrentPosition_IPDU_COM_TMS_LINTestData3_BOD             298u
#define TMS_LINTestData3_BOD_IPDU_COM_TMS_LINTestData3_BOD_TMS_C5WVBPosSetReq_IPDU_COM_TMS_LINTestData3_BOD             299u
#define TMS_LINTestData3_BOD_IPDU_COM_TMS_LINTestData3_BOD_TMS_C3WVBPosSetReq_IPDU_COM_TMS_LINTestData3_BOD             300u
#define TMS_LINTestData3_BOD_IPDU_COM_TMS_LINTestData3_BOD_TMS_HPEXVEnableCmd_IPDU_COM_TMS_LINTestData3_BOD             301u
#define TMS_LINTestData3_BOD_IPDU_COM_TMS_LINTestData3_BOD_TMS_BEXVEnableCmd_IPDU_COM_TMS_LINTestData3_BOD             302u
#define TMS_LINTestData3_BOD_IPDU_COM_TMS_LINTestData3_BOD_TMS_AEXVEnableReq_IPDU_COM_TMS_LINTestData3_BOD             303u
#define TMS_LINTestData3_BOD_IPDU_COM_TMS_LINTestData3_BOD_TMS_C5WVPosRec_IPDU_COM_TMS_LINTestData3_BOD             304u
#define TMS_LINTestData3_BOD_IPDU_COM_TMS_LINTestData3_BOD_TMS_C3WVPosRec_IPDU_COM_TMS_LINTestData3_BOD             305u
#define TMS_LINTestData3_BOD_IPDU_COM_TMS_LINTestData3_BOD_TMS_C5WVMode_IPDU_COM_TMS_LINTestData3_BOD             306u
#define TMS_LINTestData3_BOD_IPDU_COM_TMS_LINTestData3_BOD_TMS_C3WVMode_IPDU_COM_TMS_LINTestData3_BOD             307u
#define VCU_3_OprtCmd_EPT_IPDU_COM_VCU_3_OprtCmd_EPT_VCU_MotoroutputCoolantTemp_IPDU_COM_VCU_3_OprtCmd_EPT             308u
#define VCU_3_OprtCmd_EPT_IPDU_COM_VCU_3_OprtCmd_EPT_VCU_AllowHeatCoolMaxPwrCmsp_IPDU_COM_VCU_3_OprtCmd_EPT             309u
#define VCU_3_OprtCmd_EPT_IPDU_COM_VCU_3_OprtCmd_EPT_VCU_Bat2DrvTrainEnb_IPDU_COM_VCU_3_OprtCmd_EPT             310u
#define VCU_3_OprtCmd_EPT_IPDU_COM_VCU_3_OprtCmd_EPT_VCU_ChrgEna_AC_IPDU_COM_VCU_3_OprtCmd_EPT             311u
#define VCU_3_OprtCmd_EPT_IPDU_COM_VCU_3_OprtCmd_EPT_VCU_BMS_WakeupMode_IPDU_COM_VCU_3_OprtCmd_EPT             312u
#define VCU_4_ChrgCmd_EPT_IPDU_COM_VCU_4_ChrgCmd_EPT_VCU_BMS_Shutdown_IPDU_COM_VCU_4_ChrgCmd_EPT             313u
#define VCU_4_ChrgCmd_EPT_IPDU_COM_VCU_4_ChrgCmd_EPT_VCU_ChrgAllowCmd_IPDU_COM_VCU_4_ChrgCmd_EPT             314u
#define VCU_4_ChrgCmd_EPT_IPDU_COM_VCU_4_ChrgCmd_EPT_VCU_ChrgEna_DC_IPDU_COM_VCU_4_ChrgCmd_EPT             315u
#define VCU_4_ChrgCmd_EPT_IPDU_COM_VCU_4_ChrgCmd_EPT_VCU_MaxChrgCrnt_DC_IPDU_COM_VCU_4_ChrgCmd_EPT             316u
#define VCU_4_ChrgCmd_EPT_IPDU_COM_VCU_4_ChrgCmd_EPT_VCU_MaxChrgVol_DC_IPDU_COM_VCU_4_ChrgCmd_EPT             317u
#define VCU_4_ChrgCmd_EPT_IPDU_COM_VCU_4_ChrgCmd_EPT_VCU_OBCOprtCmd_IPDU_COM_VCU_4_ChrgCmd_EPT             318u
#define VCU_B_AcclPedal_EPT_IPDU_COM_VCU_B_AcclPedal_EPT_VCU_ErrAmount_IPDU_COM_VCU_B_AcclPedal_EPT             319u
#define VCU_B_AcclPedal_EPT_IPDU_COM_VCU_B_AcclPedal_EPT_VCU_EPK_ParkLock_IPDU_COM_VCU_B_AcclPedal_EPT             320u
#define VCU_B_AcclPedal_EPT_IPDU_COM_VCU_B_AcclPedal_EPT_VCU_DCCOprtCmd_IPDU_COM_VCU_B_AcclPedal_EPT             321u
#define VCU_B_AcclPedal_EPT_IPDU_COM_VCU_B_AcclPedal_EPT_VCU_SysFailSta_IPDU_COM_VCU_B_AcclPedal_EPT             322u
#define VCU_B_AcclPedal_EPT_IPDU_COM_VCU_B_AcclPedal_EPT_VCU_ErrBit_IPDU_COM_VCU_B_AcclPedal_EPT             323u
#define VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT_VCU_1_MotDirReq_IPDU_COM_VCU_1_InvCmd_EPT             324u
#define VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT_VCU_1_MotTorqueReq_IPDU_COM_VCU_1_InvCmd_EPT             325u
#define VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT_VCU_1_EmShutDown_IPDU_COM_VCU_1_InvCmd_EPT             326u
#define VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT_VCU_1_MotSpdReq_IPDU_COM_VCU_1_InvCmd_EPT             327u
#define VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT_VCU_INVSkid_IPDU_COM_VCU_1_InvCmd_EPT             328u
#define VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT_VCU_1_EnaInvRun_IPDU_COM_VCU_1_InvCmd_EPT             329u
#define VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT_VCU_ShiftMotorParkReq_IPDU_COM_VCU_1_InvCmd_EPT             330u
#define VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT_VCU_1_EnaDisChg_IPDU_COM_VCU_1_InvCmd_EPT             331u
#define VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT_VCU_1_MotModeReq_IPDU_COM_VCU_1_InvCmd_EPT             332u
#define VCU_1_InvCmd_EPT_IPDU_COM_VCU_1_InvCmd_EPT_VCU_VhclTrgtGearPos_IPDU_COM_VCU_1_InvCmd_EPT             333u
#define VCU_0_Value_EPT_IPDU_COM_VCU_0_Value_EPT_VCU_0_BraSwi_IPDU_COM_VCU_0_Value_EPT             334u
#define VCU_0_Value_EPT_IPDU_COM_VCU_0_Value_EPT_VCU_0_DrvSwi_IPDU_COM_VCU_0_Value_EPT             335u
#define VCU_0_Value_EPT_IPDU_COM_VCU_0_Value_EPT_VCU_0_Zdznswi_IPDU_COM_VCU_0_Value_EPT             336u
#define VCU_0_Value_EPT_IPDU_COM_VCU_0_Value_EPT_VCU_0_DrvPed_IPDU_COM_VCU_0_Value_EPT             337u
#define VCU_0_Value_EPT_IPDU_COM_VCU_0_Value_EPT_VCU_MotDampngLmt_IPDU_COM_VCU_0_Value_EPT             338u
#define VCU_0_Value_EPT_IPDU_COM_VCU_0_Value_EPT_VCU_AppSoftNumb_IPDU_COM_VCU_0_Value_EPT             339u
#define VCU_C_OprtCmd_EPT_IPDU_COM_VCU_C_OprtCmd_EPT_VCU_DCCBuckLV_Vol_IPDU_COM_VCU_C_OprtCmd_EPT             340u
#define VCU_C_OprtCmd_EPT_IPDU_COM_VCU_C_OprtCmd_EPT_VCU_OBCIntDischargeEnable_IPDU_COM_VCU_C_OprtCmd_EPT             341u
#define VCU_C_OprtCmd_EPT_IPDU_COM_VCU_C_OprtCmd_EPT_VCU_MaxHVDC_Cur_AC_IPDU_COM_VCU_C_OprtCmd_EPT             342u
#define VCU_C_OprtCmd_EPT_IPDU_COM_VCU_C_OprtCmd_EPT_VCU_DCCBoostHv_Vol_IPDU_COM_VCU_C_OprtCmd_EPT             343u
#define VCU_C_OprtCmd_EPT_IPDU_COM_VCU_C_OprtCmd_EPT_VCU_MaxHVDC_Vol_AC_IPDU_COM_VCU_C_OprtCmd_EPT             344u
#define BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_subID_IPDU_COM_BCM_IMMOAuthResp1_EPT             345u
#define BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Status_IPDU_COM_BCM_IMMOAuthResp1_EPT             346u
#define BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Data_02_IPDU_COM_BCM_IMMOAuthResp1_EPT             347u
#define BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Data_03_IPDU_COM_BCM_IMMOAuthResp1_EPT             348u
#define BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Data_04_IPDU_COM_BCM_IMMOAuthResp1_EPT             349u
#define BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Data_05_IPDU_COM_BCM_IMMOAuthResp1_EPT             350u
#define BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Data_06_IPDU_COM_BCM_IMMOAuthResp1_EPT             351u
#define BCM_IMMOAuthResp1_EPT_IPDU_COM_BCM_IMMOAuthResp1_EPT_BCM_Learning_Data_07_IPDU_COM_BCM_IMMOAuthResp1_EPT             352u
#define AC_ACStatuts_BAC_IPDU_COM_AC_ACStatuts_BAC_AC_leftTempValue_IPDU_COM_AC_ACStatuts_BAC             353u
#define AC_ACStatuts_BAC_IPDU_COM_AC_ACStatuts_BAC_AC_ManualDefrostFb_IPDU_COM_AC_ACStatuts_BAC             354u
#define AC_ACStatuts_BAC_IPDU_COM_AC_ACStatuts_BAC_AC_ACAutoFb_IPDU_COM_AC_ACStatuts_BAC             355u
#define AC_ACStatuts_BAC_IPDU_COM_AC_ACStatuts_BAC_AC_BlowerModeSta_IPDU_COM_AC_ACStatuts_BAC             356u
#define AC_ACStatuts_BAC_IPDU_COM_AC_ACStatuts_BAC_AC_FrontFanSpdValue_IPDU_COM_AC_ACStatuts_BAC             357u
#define AC_ACStatuts_BAC_IPDU_COM_AC_ACStatuts_BAC_AC_ACPowerFb_IPDU_COM_AC_ACStatuts_BAC             358u
#define AC_ACStatuts_BAC_IPDU_COM_AC_ACStatuts_BAC_AC_AutoBlowerModeSta_IPDU_COM_AC_ACStatuts_BAC             359u
#define AC_ACStatuts_BAC_IPDU_COM_AC_ACStatuts_BAC_AC_HybridEcoModeSta_IPDU_COM_AC_ACStatuts_BAC             360u
#define AC_ACStatuts_BAC_IPDU_COM_AC_ACStatuts_BAC_AC_AirInletModeSta_IPDU_COM_AC_ACStatuts_BAC             361u
#define AC_ACStatuts_BAC_IPDU_COM_AC_ACStatuts_BAC_BCM_RearViewMirrHeatingSts_IPDU_COM_AC_ACStatuts_BAC             362u
#define AC_3_State_BAC_IPDU_COM_AC_3_State_BAC_AC_ExtdDefrostActvReq_IPDU_COM_AC_3_State_BAC             363u
#define AC_3_State_BAC_IPDU_COM_AC_3_State_BAC_AC_EnvirTempV_IPDU_COM_AC_3_State_BAC             364u
#define AC_3_State_BAC_IPDU_COM_AC_3_State_BAC_AC_IndoorTemp_IPDU_COM_AC_3_State_BAC             365u
#define AC_3_State_BAC_IPDU_COM_AC_3_State_BAC_AC_EnvirTemp_IPDU_COM_AC_3_State_BAC             366u
#define AC_3_State_BAC_IPDU_COM_AC_3_State_BAC_TMS_OHXOutTmp_IPDU_COM_AC_3_State_BAC             367u
#define AC_3_State_BAC_IPDU_COM_AC_3_State_BAC_TMS_EvapTmp_IPDU_COM_AC_3_State_BAC             368u
#define AC_3_State_BAC_IPDU_COM_AC_3_State_BAC_TMS_EvapOutTmp_IPDU_COM_AC_3_State_BAC             369u
#define AC_3_State_BAC_IPDU_COM_AC_3_State_BAC_TMS_ChillerOutTmp_IPDU_COM_AC_3_State_BAC             370u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte0_IPDU_COM_BCM_HFSData_BAC             371u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte1_IPDU_COM_BCM_HFSData_BAC             372u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte2_IPDU_COM_BCM_HFSData_BAC             373u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte3_IPDU_COM_BCM_HFSData_BAC             374u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte4_IPDU_COM_BCM_HFSData_BAC             375u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte5_IPDU_COM_BCM_HFSData_BAC             376u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte6_IPDU_COM_BCM_HFSData_BAC             377u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte7_IPDU_COM_BCM_HFSData_BAC             378u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte8_IPDU_COM_BCM_HFSData_BAC             379u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte9_IPDU_COM_BCM_HFSData_BAC             380u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte10_IPDU_COM_BCM_HFSData_BAC             381u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte11_IPDU_COM_BCM_HFSData_BAC             382u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte12_IPDU_COM_BCM_HFSData_BAC             383u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte13_IPDU_COM_BCM_HFSData_BAC             384u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte14_IPDU_COM_BCM_HFSData_BAC             385u
#define BCM_HFSData_BAC_IPDU_COM_BCM_HFSData_BAC_BCM_HighFreqSigData_Byte15_IPDU_COM_BCM_HFSData_BAC             386u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_DispInfo_Chksum1_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             387u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_DispInfo_AliveCnt1_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             388u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_MotorActualPowerType_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             389u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_DrvRangeDistEstV_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             390u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_WLTPDrvgRngDstVldty_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             391u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_WLTPDrvgRngDst_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             392u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_ReservePower_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             393u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_DrvRangeDistEst_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             394u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_MotorActualPower_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             395u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_DispInfo_Chksum2_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             396u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_DispInfo_AliveCnt2_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             397u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_DrvMotorSta_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             398u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_InfoDisp_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             399u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_VhclPGearError_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             400u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_VhclActlCnsmPwr_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             401u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_VhclSpeedFastWarn_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             402u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_OBCOprtCmdToICU_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             403u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_MotorHighTempWrning_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             404u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_MCUHighTempWrning_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             405u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_VhclPwrCnsmpAvrg_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             406u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_ShiftKeyStagnation_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             407u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_CCKeyStagnation_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             408u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_DriveModeKeyStagnation_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             409u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_DispInfo_Chksum3_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             410u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_DispInfo_AliveCnt3_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             411u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_SIBS_KL30Voltage_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             412u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_SIBS_ChgNumAllow_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             413u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_SIBS_RTCWUChgNum_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             414u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_SIBS_RTCChrgSt_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             415u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_SIBS_RTCWUChgFailNum_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             416u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_BCM_IllmndLockStsFb_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             417u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_BCM_IllmndUnlockStsFb_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             418u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_SIBS_FbRTCWupFlg_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             419u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_SIBS_BMSBatSOCAllow_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             420u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_SIBS_WupVoltAllow_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             421u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_VehActDrivingPwr_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             422u
#define VCU_DispInfo_BAC_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_VCU_VehActRecuperatePwr_IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1             423u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_VCU_PTActlOprtMode_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             424u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_VCU_VhclActlGearPosV_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             425u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_VCU_VhclActlGearPos_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             426u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_BCM_BrakePedalSta_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             427u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_BCM_SysPwrMode_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             428u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_BCM_SysPwrModeV_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             429u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_VCU_12VBatLowVolSta_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             430u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_VCU_LimpHomeSta_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             431u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_VCU_PCUFailSta_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             432u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_BCM_CentralLockSwCtrlFb_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             433u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_BCM_CentralLockSts_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             434u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_BCM_SysPowerSts_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             435u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_VCU_PwrRecupIntensity_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             436u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_BCM_DoorLockSta_FL_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             437u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_VCU_PrstlsStaFb_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             438u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_VCU_VehActDrvMod1_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             439u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_CCU_DiagTesterOnline_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             440u
#define CCU_VehInfo_BAC_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_VCU_HDCStatus_IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1             441u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_D_Chksum1_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             442u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_D_AliveCnt1_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             443u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_AcclPedalPos_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             444u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_BrkPedalPos_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             445u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_OTAModeSts_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             446u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_DrvReqTorqOverrideESC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             447u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_BrkPedalSnsrPosV_Reserved_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             448u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_ACCTrqCtrlAvl_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             449u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_StandStilDecelReq_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             450u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_AcclPedalPosSnsrSta_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             451u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_PGearSwcSt_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             452u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_DrvReqTorqOverrideFCM_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             453u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_StandStilOverride_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             454u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_StandStilTarDecelVal_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             455u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_D_Chksum2_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             456u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_D_AliveCnt2_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             457u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_AcclPedalPosToESC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             458u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_PwrRecupMaxAvlbMotorTorqSta_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             459u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_ReqEPB_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             460u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_ReqEPBV_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             461u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_AcclPedalPosToESCSta_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             462u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_ParkSwStaV_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             463u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_ParkSwSta_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             464u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_StrgRecupReqBrkLampOn_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             465u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_GearShiftInhibited_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             466u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_EPK_ParkLocktoCHA_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             467u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_EPBApplyForbid_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             468u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_D_Chksum3_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             469u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_D_AliveCnt3_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             470u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_AccTgtAx_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             471u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_AccTgtAxReq_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             472u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_BraTorReq_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             473u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_ACCStandstillReq_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             474u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_PreKeReq_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             475u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_CruiseCtrlSta_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             476u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_CruiseCtrTgtSpd_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             477u
#define VCU_D_Status_BAC_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_VCU_ReqAutoBrk_IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1             478u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_TurnLampSta_Left_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             479u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_TurnLampSta_Right_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             480u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FogLampSta_Rear_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             481u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_PosLampSta_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             482u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_HazardLampSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             483u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_HighBeamSta_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             484u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_LowBeamSta_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             485u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FogLampSta_Front_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             486u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_AutoLampStatus_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             487u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_DayRunLightSta_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             488u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_ReverseLampSta_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             489u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_BrakeLampSta_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             490u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_DayRunLiSwSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             491u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_TurnLiSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             492u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_TurnngLiSwSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             493u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_LightIntensity_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             494u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_LightSwSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             495u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_HighBeamSwSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             496u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_AjarStaV_Hood_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             497u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_AjarSta_Hood_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             498u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_HazardWarningLightSwSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             499u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FrntFogLiSwSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             500u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_RearFogLiSwSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             501u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FlwrMeHmCtrlFb_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             502u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_BassHornReq_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             503u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_AjarSta_Trunk_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             504u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_DoorAjarSta_FL_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             505u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_DoorAjarSta_FR_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             506u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_DoorAjarSta_RL_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             507u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_DoorAjarSta_RR_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             508u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_LockHornOnStFb_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             509u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_AlrmHornReq_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             510u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_TempSts_FL_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             511u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_PressureSta_FL_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             512u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_TempSts_FR_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             513u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_PressureSta_FR_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             514u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_PressureValue_FL_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             515u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_PressureValue_FR_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             516u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_TireTempValue_FL_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             517u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_TireTempValue_FR_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             518u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_TPMSResetSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             519u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TMPS_AbnmPrsrWarn_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             520u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_B_RearTPMS_Counter_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             521u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_TempSts_RL_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             522u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_PressureSta_RL_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             523u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_TempSts_RR_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             524u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_PressureSta_RR_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             525u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_PressureValue_RL_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             526u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_PressureValue_RR_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             527u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_TireTempValue_RL_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             528u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TPMS_TireTempValue_RR_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             529u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_WiperCtrl_Front_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             530u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_WashLiquidLevelWarn_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             531u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_DrvSeatOccupantSensorSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             532u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_HeavyRainInd_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             533u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FrntWshrSwSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             534u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_Pas_wdw_Init_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             535u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FrontWashSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             536u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_WiprIntlGearSwtSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             537u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_WiperSwSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             538u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_WinLockSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             539u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_WinLockSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             540u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_DriverWinSwSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             541u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_PassWinSwSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             542u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FLWindowSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             543u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FRWindowSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             544u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FLWindowmotorSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             545u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FRWindowmotorSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             546u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FrontWiperMotorSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             547u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FrntLeDoorHndlSwt_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             548u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FrntRiDoorHndlSwt_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             549u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_TrunkSwtSig_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             550u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_WarnNoKeyFound_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             551u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_BodyWarnSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             552u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_PSAuthentRes_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             553u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_ChrgLidLockReq_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             554u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_RKEReq_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             555u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_KeyInCarSta_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             556u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_DrvPEAuthentAcsd_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             557u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FRPEAuthentAcsd_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             558u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_PSReq_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             559u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_WiprIntlTimeSetFb_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             560u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_StartReq_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             561u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_ChgWiperMtMdSwSetFb_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             562u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_ParkAutoUnlockSetFb_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             563u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_OverspdCntrlLockSetFb_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             564u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_TrunkLockSta_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             565u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_TrunkLockSwCtrlFb_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             566u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_AuthentKeyNr_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             567u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_KeyFrbdn_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             568u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_FrbdnKeyNr_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             569u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_KeyIDFb_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             570u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_KeyLocn_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             571u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_IllmndEntryStsFb_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             572u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_AvaluebleKeyInCar_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             573u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_KeyBattLvlSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             574u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_KeyLoBattLvlWarn_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             575u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_KeySta_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             576u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_KeyBattLvl_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             577u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_IllmndLampReq_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             578u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_IllmndLockReq_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             579u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_IndicationShifttoNeutral_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             580u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_WarnKeyOutReminder_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             581u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_IndicationKeyCloser_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             582u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_IllmndSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             583u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_SteerWhlHeatSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             584u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_SteerWhlTemp_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             585u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_MaiDrvrSeatTemp_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             586u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_RearMirrorHeatSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             587u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_LogoActiveFlag_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             588u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_VhclSeek_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             589u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_BackLadjvalFb_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             590u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_MaiDrvrSeatSts_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             591u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_RFInitSta_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             592u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_RiTurnLiFaultFb_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             593u
#define BCM_B_Package_BAC_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_BCM_LeTurnLiFaultFb_IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1             594u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_VCU_PTActlOprtMode_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             595u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_VCU_VhclActlGearPosV_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             596u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_VCU_VhclActlGearPos_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             597u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_BCM_BrakePedalSta_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             598u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_BCM_SysPwrMode_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             599u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_BCM_SysPwrModeV_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             600u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_VCU_12VBatLowVolSta_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             601u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_VCU_LimpHomeSta_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             602u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_VCU_PCUFailSta_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             603u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_BCM_CentralLockSwCtrlFb_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             604u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_BCM_CentralLockSts_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             605u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_BCM_SysPowerSts_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             606u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_VCU_PwrRecupIntensity_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             607u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_BCM_DoorLockSta_FL_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             608u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_VCU_PrstlsStaFb_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             609u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_VCU_VehActDrvMod1_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             610u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_CCU_DiagTesterOnline_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             611u
#define CCU_VehInfo_BOD_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_VCU_HDCStatus_IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6             612u
#define BCM_ESCLCommand_BOD_IPDU_COM_TX_BCM_ESCLCommand_BOD_CANFD5_BOD_CAN6_ESCL_UnOrLockCrtl_IPDU_COM_TX_BCM_ESCLCommand_BOD_CANFD5_BOD_CAN6             613u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_VCU_PTActlOprtMode_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             614u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_VCU_VhclActlGearPosV_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             615u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_VCU_VhclActlGearPos_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             616u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_BCM_BrakePedalSta_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             617u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_BCM_SysPwrMode_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             618u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_BCM_SysPwrModeV_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             619u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_VCU_12VBatLowVolSta_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             620u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_VCU_LimpHomeSta_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             621u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_VCU_PCUFailSta_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             622u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_BCM_CentralLockSwCtrlFb_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             623u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_BCM_CentralLockSts_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             624u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_BCM_SysPowerSts_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             625u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_VCU_PwrRecupIntensity_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             626u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_BCM_DoorLockSta_FL_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             627u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_VCU_PrstlsStaFb_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             628u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_VCU_VehActDrvMod1_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             629u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_CCU_DiagTesterOnline_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             630u
#define CCU_VehInfo_CHA_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_VCU_HDCStatus_IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5             631u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_D_Chksum1_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             632u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_D_AliveCnt1_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             633u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_AcclPedalPos_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             634u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_BrkPedalPos_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             635u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_OTAModeSts_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             636u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_DrvReqTorqOverrideESC_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             637u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_BrkPedalSnsrPosV_Reserved_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             638u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_ACCTrqCtrlAvl_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             639u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_StandStilDecelReq_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             640u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_AcclPedalPosSnsrSta_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             641u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_PGearSwcSt_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             642u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_DrvReqTorqOverrideFCM_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             643u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_StandStilOverride_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             644u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_StandStilTarDecelVal_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             645u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_D_Chksum2_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             646u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_D_AliveCnt2_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             647u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_AcclPedalPosToESC_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             648u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_PwrRecupMaxAvlbMotorTorqSta_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             649u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_ReqEPB_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             650u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_ReqEPBV_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             651u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_AcclPedalPosToESCSta_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             652u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_ParkSwStaV_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             653u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_ParkSwSta_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             654u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_StrgRecupReqBrkLampOn_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             655u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_GearShiftInhibited_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             656u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_EPK_ParkLocktoCHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             657u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_EPBApplyForbid_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             658u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_D_Chksum3_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             659u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_D_AliveCnt3_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             660u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_AccTgtAx_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             661u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_AccTgtAxReq_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             662u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_BraTorReq_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             663u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_ACCStandstillReq_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             664u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_PreKeReq_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             665u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_CruiseCtrlSta_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             666u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_CruiseCtrTgtSpd_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             667u
#define VCU_D_Status_CHA_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_VCU_ReqAutoBrk_IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5             668u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_TurnLampSta_Left_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             669u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_TurnLampSta_Right_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             670u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FogLampSta_Rear_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             671u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_PosLampSta_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             672u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_HazardLampSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             673u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_HighBeamSta_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             674u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_LowBeamSta_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             675u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FogLampSta_Front_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             676u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_AutoLampStatus_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             677u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_DayRunLightSta_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             678u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_ReverseLampSta_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             679u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_BrakeLampSta_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             680u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_DayRunLiSwSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             681u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_TurnLiSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             682u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_TurnngLiSwSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             683u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_LightIntensity_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             684u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_LightSwSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             685u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_HighBeamSwSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             686u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_AjarStaV_Hood_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             687u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_AjarSta_Hood_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             688u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_HazardWarningLightSwSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             689u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FrntFogLiSwSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             690u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_RearFogLiSwSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             691u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FlwrMeHmCtrlFb_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             692u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_BassHornReq_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             693u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_AjarSta_Trunk_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             694u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_DoorAjarSta_FL_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             695u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_DoorAjarSta_FR_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             696u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_DoorAjarSta_RL_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             697u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_DoorAjarSta_RR_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             698u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_LockHornOnStFb_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             699u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_AlrmHornReq_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             700u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_TempSts_FL_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             701u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_PressureSta_FL_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             702u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_TempSts_FR_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             703u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_PressureSta_FR_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             704u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_PressureValue_FL_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             705u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_PressureValue_FR_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             706u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_TireTempValue_FL_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             707u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_TireTempValue_FR_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             708u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_TPMSResetSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             709u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TMPS_AbnmPrsrWarn_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             710u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_B_RearTPMS_Counter_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             711u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_TempSts_RL_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             712u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_PressureSta_RL_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             713u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_TempSts_RR_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             714u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_PressureSta_RR_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             715u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_PressureValue_RL_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             716u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_PressureValue_RR_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             717u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_TireTempValue_RL_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             718u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TPMS_TireTempValue_RR_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             719u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_WiperCtrl_Front_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             720u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_WashLiquidLevelWarn_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             721u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_DrvSeatOccupantSensorSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             722u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_HeavyRainInd_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             723u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FrntWshrSwSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             724u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_Pas_wdw_Init_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             725u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FrontWashSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             726u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_WiprIntlGearSwtSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             727u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_WiperSwSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             728u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_WinLockSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             729u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_WinLockSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             730u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_DriverWinSwSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             731u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_PassWinSwSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             732u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FLWindowSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             733u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FRWindowSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             734u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FLWindowmotorSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             735u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FRWindowmotorSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             736u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FrontWiperMotorSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             737u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FrntLeDoorHndlSwt_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             738u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FrntRiDoorHndlSwt_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             739u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_TrunkSwtSig_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             740u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_WarnNoKeyFound_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             741u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_BodyWarnSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             742u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_PSAuthentRes_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             743u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_ChrgLidLockReq_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             744u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_RKEReq_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             745u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_KeyInCarSta_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             746u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_DrvPEAuthentAcsd_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             747u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FRPEAuthentAcsd_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             748u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_PSReq_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             749u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_WiprIntlTimeSetFb_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             750u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_StartReq_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             751u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_ChgWiperMtMdSwSetFb_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             752u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_ParkAutoUnlockSetFb_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             753u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_OverspdCntrlLockSetFb_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             754u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_TrunkLockSta_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             755u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_TrunkLockSwCtrlFb_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             756u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_AuthentKeyNr_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             757u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_KeyFrbdn_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             758u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_FrbdnKeyNr_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             759u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_KeyIDFb_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             760u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_KeyLocn_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             761u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_IllmndEntryStsFb_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             762u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_AvaluebleKeyInCar_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             763u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_KeyBattLvlSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             764u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_KeyLoBattLvlWarn_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             765u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_KeySta_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             766u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_KeyBattLvl_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             767u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_IllmndLampReq_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             768u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_IllmndLockReq_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             769u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_IndicationShifttoNeutral_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             770u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_WarnKeyOutReminder_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             771u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_IndicationKeyCloser_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             772u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_IllmndSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             773u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_SteerWhlHeatSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             774u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_SteerWhlTemp_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             775u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_MaiDrvrSeatTemp_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             776u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_RearMirrorHeatSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             777u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_LogoActiveFlag_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             778u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_VhclSeek_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             779u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_BackLadjvalFb_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             780u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_MaiDrvrSeatSts_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             781u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_RFInitSta_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             782u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_RiTurnLiFaultFb_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             783u
#define BCM_B_Package_CHA_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_BCM_LeTurnLiFaultFb_IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5             784u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_VCU_PTActlOprtMode_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             785u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_VCU_VhclActlGearPosV_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             786u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_VCU_VhclActlGearPos_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             787u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_BCM_BrakePedalSta_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             788u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_BCM_SysPwrMode_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             789u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_BCM_SysPwrModeV_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             790u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_VCU_12VBatLowVolSta_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             791u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_VCU_LimpHomeSta_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             792u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_VCU_PCUFailSta_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             793u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_BCM_CentralLockSwCtrlFb_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             794u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_BCM_CentralLockSts_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             795u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_BCM_SysPowerSts_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             796u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_VCU_PwrRecupIntensity_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             797u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_BCM_DoorLockSta_FL_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             798u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_VCU_PrstlsStaFb_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             799u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_VCU_VehActDrvMod1_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             800u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_CCU_DiagTesterOnline_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             801u
#define CCU_VehInfo_EPT_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_VCU_HDCStatus_IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2             802u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define COM_RXGROUPSIGNAL_NUMBER        1258u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_Chksum1_IPDU_COM_FCM_23_Obj0109_CHA             205u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_AliveCnt1_IPDU_COM_FCM_23_Obj0109_CHA             206u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjTyp1_IPDU_COM_FCM_23_Obj0109_CHA             207u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLatDst1_IPDU_COM_FCM_23_Obj0109_CHA             208u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLgtDst1_IPDU_COM_FCM_23_Obj0109_CHA             209u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_LgtRelSpd1_IPDU_COM_FCM_23_Obj0109_CHA             210u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjPosnAgl1_IPDU_COM_FCM_23_Obj0109_CHA             211u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtDir1_IPDU_COM_FCM_23_Obj0109_CHA             212u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_LgtRelSpd7_IPDU_COM_FCM_23_Obj0109_CHA             213u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtSta1_IPDU_COM_FCM_23_Obj0109_CHA             214u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_LgtRelSpd8_IPDU_COM_FCM_23_Obj0109_CHA             215u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_Chksum2_IPDU_COM_FCM_23_Obj0109_CHA             216u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_AliveCnt2_IPDU_COM_FCM_23_Obj0109_CHA             217u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjTyp2_IPDU_COM_FCM_23_Obj0109_CHA             218u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLatDst2_IPDU_COM_FCM_23_Obj0109_CHA             219u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLgtDst2_IPDU_COM_FCM_23_Obj0109_CHA             220u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_LgtRelSpd2_IPDU_COM_FCM_23_Obj0109_CHA             221u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjPosnAgl2_IPDU_COM_FCM_23_Obj0109_CHA             222u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtDir2_IPDU_COM_FCM_23_Obj0109_CHA             223u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_LgtRelSpd9_IPDU_COM_FCM_23_Obj0109_CHA             224u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtSta2_IPDU_COM_FCM_23_Obj0109_CHA             225u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_Chksum3_IPDU_COM_FCM_23_Obj0109_CHA             226u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_AliveCnt3_IPDU_COM_FCM_23_Obj0109_CHA             227u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjTyp3_IPDU_COM_FCM_23_Obj0109_CHA             228u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLatDst3_IPDU_COM_FCM_23_Obj0109_CHA             229u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLgtDst3_IPDU_COM_FCM_23_Obj0109_CHA             230u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_LgtRelSpd3_IPDU_COM_FCM_23_Obj0109_CHA             231u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjPosnAgl3_IPDU_COM_FCM_23_Obj0109_CHA             232u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtSta3_IPDU_COM_FCM_23_Obj0109_CHA             233u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtDir3_IPDU_COM_FCM_23_Obj0109_CHA             234u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_Chksum4_IPDU_COM_FCM_23_Obj0109_CHA             235u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_AliveCnt4_IPDU_COM_FCM_23_Obj0109_CHA             236u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjTyp4_IPDU_COM_FCM_23_Obj0109_CHA             237u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLatDst4_IPDU_COM_FCM_23_Obj0109_CHA             238u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLgtDst4_IPDU_COM_FCM_23_Obj0109_CHA             239u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_LgtRelSpd4_IPDU_COM_FCM_23_Obj0109_CHA             240u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjPosnAgl4_IPDU_COM_FCM_23_Obj0109_CHA             241u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtDir7_IPDU_COM_FCM_23_Obj0109_CHA             242u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtSta4_IPDU_COM_FCM_23_Obj0109_CHA             243u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtDir4_IPDU_COM_FCM_23_Obj0109_CHA             244u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_Chksum5_IPDU_COM_FCM_23_Obj0109_CHA             245u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_AliveCnt5_IPDU_COM_FCM_23_Obj0109_CHA             246u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjTyp5_IPDU_COM_FCM_23_Obj0109_CHA             247u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLatDst5_IPDU_COM_FCM_23_Obj0109_CHA             248u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLgtDst5_IPDU_COM_FCM_23_Obj0109_CHA             249u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_LgtRelSpd5_IPDU_COM_FCM_23_Obj0109_CHA             250u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjPosnAgl5_IPDU_COM_FCM_23_Obj0109_CHA             251u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtSta9_IPDU_COM_FCM_23_Obj0109_CHA             252u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtSta5_IPDU_COM_FCM_23_Obj0109_CHA             253u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtDir5_IPDU_COM_FCM_23_Obj0109_CHA             254u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_Chksum6_IPDU_COM_FCM_23_Obj0109_CHA             255u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_AliveCnt6_IPDU_COM_FCM_23_Obj0109_CHA             256u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjTyp6_IPDU_COM_FCM_23_Obj0109_CHA             257u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLatDst6_IPDU_COM_FCM_23_Obj0109_CHA             258u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLgtDst6_IPDU_COM_FCM_23_Obj0109_CHA             259u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_LgtRelSpd6_IPDU_COM_FCM_23_Obj0109_CHA             260u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjPosnAgl6_IPDU_COM_FCM_23_Obj0109_CHA             261u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtDir6_IPDU_COM_FCM_23_Obj0109_CHA             262u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtSta6_IPDU_COM_FCM_23_Obj0109_CHA             263u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtDir9_IPDU_COM_FCM_23_Obj0109_CHA             264u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_Chksum7_IPDU_COM_FCM_23_Obj0109_CHA             265u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_AliveCnt7_IPDU_COM_FCM_23_Obj0109_CHA             266u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjTyp7_IPDU_COM_FCM_23_Obj0109_CHA             267u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLatDst7_IPDU_COM_FCM_23_Obj0109_CHA             268u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLgtDst7_IPDU_COM_FCM_23_Obj0109_CHA             269u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtSta7_IPDU_COM_FCM_23_Obj0109_CHA             270u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjPosnAgl7_IPDU_COM_FCM_23_Obj0109_CHA             271u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLatDst8_IPDU_COM_FCM_23_Obj0109_CHA             272u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLgtDst8_IPDU_COM_FCM_23_Obj0109_CHA             273u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_Chksum8_IPDU_COM_FCM_23_Obj0109_CHA             274u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_23_AliveCnt8_IPDU_COM_FCM_23_Obj0109_CHA             275u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjTyp8_IPDU_COM_FCM_23_Obj0109_CHA             276u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtSta8_IPDU_COM_FCM_23_Obj0109_CHA             277u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjTyp9_IPDU_COM_FCM_23_Obj0109_CHA             278u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjPosnAgl8_IPDU_COM_FCM_23_Obj0109_CHA             279u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLatDst9_IPDU_COM_FCM_23_Obj0109_CHA             280u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjLgtDst9_IPDU_COM_FCM_23_Obj0109_CHA             281u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjMovmtDir8_IPDU_COM_FCM_23_Obj0109_CHA             282u
#define FCM_23_Obj0109_CHA_IPDU_COM_FCM_23_Obj0109_CHA_FCM_ObjPosnAgl9_IPDU_COM_FCM_23_Obj0109_CHA             283u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_Chksum1_IPDU_COM_FCM_24_Obj1018_CHA             284u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_AliveCnt1_IPDU_COM_FCM_24_Obj1018_CHA             285u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjTyp10_IPDU_COM_FCM_24_Obj1018_CHA             286u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLatDst10_IPDU_COM_FCM_24_Obj1018_CHA             287u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLgtDst10_IPDU_COM_FCM_24_Obj1018_CHA             288u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtSta10_IPDU_COM_FCM_24_Obj1018_CHA             289u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjPosnAgl10_IPDU_COM_FCM_24_Obj1018_CHA             290u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLatDst11_IPDU_COM_FCM_24_Obj1018_CHA             291u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLgtDst11_IPDU_COM_FCM_24_Obj1018_CHA             292u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_Chksum2_IPDU_COM_FCM_24_Obj1018_CHA             293u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_AliveCnt2_IPDU_COM_FCM_24_Obj1018_CHA             294u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjTyp11_IPDU_COM_FCM_24_Obj1018_CHA             295u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtSta11_IPDU_COM_FCM_24_Obj1018_CHA             296u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjPosnAgl11_IPDU_COM_FCM_24_Obj1018_CHA             297u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLatDst12_IPDU_COM_FCM_24_Obj1018_CHA             298u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLgtDst12_IPDU_COM_FCM_24_Obj1018_CHA             299u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtDir11_IPDU_COM_FCM_24_Obj1018_CHA             300u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjTyp12_IPDU_COM_FCM_24_Obj1018_CHA             301u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjPosnAgl12_IPDU_COM_FCM_24_Obj1018_CHA             302u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_Chksum3_IPDU_COM_FCM_24_Obj1018_CHA             303u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_AliveCnt3_IPDU_COM_FCM_24_Obj1018_CHA             304u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjTyp13_IPDU_COM_FCM_24_Obj1018_CHA             305u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLatDst13_IPDU_COM_FCM_24_Obj1018_CHA             306u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLgtDst13_IPDU_COM_FCM_24_Obj1018_CHA             307u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtSta13_IPDU_COM_FCM_24_Obj1018_CHA             308u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjPosnAgl13_IPDU_COM_FCM_24_Obj1018_CHA             309u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLatDst14_IPDU_COM_FCM_24_Obj1018_CHA             310u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLgtDst14_IPDU_COM_FCM_24_Obj1018_CHA             311u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_Chksum4_IPDU_COM_FCM_24_Obj1018_CHA             312u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_AliveCnt4_IPDU_COM_FCM_24_Obj1018_CHA             313u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjTyp14_IPDU_COM_FCM_24_Obj1018_CHA             314u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtSta14_IPDU_COM_FCM_24_Obj1018_CHA             315u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjPosnAgl14_IPDU_COM_FCM_24_Obj1018_CHA             316u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLatDst15_IPDU_COM_FCM_24_Obj1018_CHA             317u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLgtDst15_IPDU_COM_FCM_24_Obj1018_CHA             318u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtDir14_IPDU_COM_FCM_24_Obj1018_CHA             319u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjTyp15_IPDU_COM_FCM_24_Obj1018_CHA             320u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjPosnAgl15_IPDU_COM_FCM_24_Obj1018_CHA             321u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_Chksum5_IPDU_COM_FCM_24_Obj1018_CHA             322u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_AliveCnt5_IPDU_COM_FCM_24_Obj1018_CHA             323u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjTyp16_IPDU_COM_FCM_24_Obj1018_CHA             324u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLatDst16_IPDU_COM_FCM_24_Obj1018_CHA             325u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLgtDst16_IPDU_COM_FCM_24_Obj1018_CHA             326u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLatDst17_IPDU_COM_FCM_24_Obj1018_CHA             327u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLgtDst17_IPDU_COM_FCM_24_Obj1018_CHA             328u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtDir16_IPDU_COM_FCM_24_Obj1018_CHA             329u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtSta16_IPDU_COM_FCM_24_Obj1018_CHA             330u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_Chksum6_IPDU_COM_FCM_24_Obj1018_CHA             331u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_AliveCnt6_IPDU_COM_FCM_24_Obj1018_CHA             332u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjTyp17_IPDU_COM_FCM_24_Obj1018_CHA             333u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtDir17_IPDU_COM_FCM_24_Obj1018_CHA             334u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtSta17_IPDU_COM_FCM_24_Obj1018_CHA             335u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjTyp18_IPDU_COM_FCM_24_Obj1018_CHA             336u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLatDst18_IPDU_COM_FCM_24_Obj1018_CHA             337u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjLgtDst18_IPDU_COM_FCM_24_Obj1018_CHA             338u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtSta18_IPDU_COM_FCM_24_Obj1018_CHA             339u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtDir18_IPDU_COM_FCM_24_Obj1018_CHA             340u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjPosnAgl18_IPDU_COM_FCM_24_Obj1018_CHA             341u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_Chksum7_IPDU_COM_FCM_24_Obj1018_CHA             342u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_AliveCnt7_IPDU_COM_FCM_24_Obj1018_CHA             343u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_LgtRelSpd10_IPDU_COM_FCM_24_Obj1018_CHA             344u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjPosnAgl16_IPDU_COM_FCM_24_Obj1018_CHA             345u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_LgtRelSpd11_IPDU_COM_FCM_24_Obj1018_CHA             346u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjPosnAgl17_IPDU_COM_FCM_24_Obj1018_CHA             347u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_LgtRelSpd12_IPDU_COM_FCM_24_Obj1018_CHA             348u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_Chksum8_IPDU_COM_FCM_24_Obj1018_CHA             349u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_24_AliveCnt8_IPDU_COM_FCM_24_Obj1018_CHA             350u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtDir10_IPDU_COM_FCM_24_Obj1018_CHA             351u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_LgtRelSpd13_IPDU_COM_FCM_24_Obj1018_CHA             352u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtSta12_IPDU_COM_FCM_24_Obj1018_CHA             353u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_LgtRelSpd14_IPDU_COM_FCM_24_Obj1018_CHA             354u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtDir12_IPDU_COM_FCM_24_Obj1018_CHA             355u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_LgtRelSpd15_IPDU_COM_FCM_24_Obj1018_CHA             356u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtDir13_IPDU_COM_FCM_24_Obj1018_CHA             357u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_LgtRelSpd16_IPDU_COM_FCM_24_Obj1018_CHA             358u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtSta15_IPDU_COM_FCM_24_Obj1018_CHA             359u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_LgtRelSpd17_IPDU_COM_FCM_24_Obj1018_CHA             360u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_ObjMovmtDir15_IPDU_COM_FCM_24_Obj1018_CHA             361u
#define FCM_24_Obj1018_CHA_IPDU_COM_FCM_24_Obj1018_CHA_FCM_LgtRelSpd18_IPDU_COM_FCM_24_Obj1018_CHA             362u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_Chksum1_IPDU_COM_FCM_25_Line123_CHA             363u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_AliveCnt1_IPDU_COM_FCM_25_Line123_CHA             364u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLineTyp_IPDU_COM_FCM_25_Line123_CHA             365u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLineTrueColor_IPDU_COM_FCM_25_Line123_CHA             366u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_NrOfLine_IPDU_COM_FCM_25_Line123_CHA             367u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLineExist_IPDU_COM_FCM_25_Line123_CHA             368u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLineRd_IPDU_COM_FCM_25_Line123_CHA             369u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLineDst_IPDU_COM_FCM_25_Line123_CHA             370u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLineC1_IPDU_COM_FCM_25_Line123_CHA             371u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_Chksum2_IPDU_COM_FCM_25_Line123_CHA             372u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_AliveCnt2_IPDU_COM_FCM_25_Line123_CHA             373u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiLineTyp_IPDU_COM_FCM_25_Line123_CHA             374u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLineC2_IPDU_COM_FCM_25_Line123_CHA             375u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLineC3_IPDU_COM_FCM_25_Line123_CHA             376u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiLineExist_IPDU_COM_FCM_25_Line123_CHA             377u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiLineRd_IPDU_COM_FCM_25_Line123_CHA             378u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiLineDst_IPDU_COM_FCM_25_Line123_CHA             379u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_Chksum3_IPDU_COM_FCM_25_Line123_CHA             380u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_AliveCnt3_IPDU_COM_FCM_25_Line123_CHA             381u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiLineC1_IPDU_COM_FCM_25_Line123_CHA             382u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiLineC3_IPDU_COM_FCM_25_Line123_CHA             383u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLeLineExist_IPDU_COM_FCM_25_Line123_CHA             384u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiLineC2_IPDU_COM_FCM_25_Line123_CHA             385u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLeLineTrueColor_IPDU_COM_FCM_25_Line123_CHA             386u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLeLineTyp_IPDU_COM_FCM_25_Line123_CHA             387u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_Chksum4_IPDU_COM_FCM_25_Line123_CHA             388u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_AliveCnt4_IPDU_COM_FCM_25_Line123_CHA             389u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLeLineC1_IPDU_COM_FCM_25_Line123_CHA             390u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLeLineC3_IPDU_COM_FCM_25_Line123_CHA             391u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLeLineRd_IPDU_COM_FCM_25_Line123_CHA             392u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLeLineDst_IPDU_COM_FCM_25_Line123_CHA             393u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_Chksum5_IPDU_COM_FCM_25_Line123_CHA             394u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_AliveCnt5_IPDU_COM_FCM_25_Line123_CHA             395u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiRiLineC1_IPDU_COM_FCM_25_Line123_CHA             396u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiRiLineC3_IPDU_COM_FCM_25_Line123_CHA             397u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiRiLineExist_IPDU_COM_FCM_25_Line123_CHA             398u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiRiLineRd_IPDU_COM_FCM_25_Line123_CHA             399u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiRiLineDst_IPDU_COM_FCM_25_Line123_CHA             400u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_Chksum6_IPDU_COM_FCM_25_Line123_CHA             401u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_AliveCnt6_IPDU_COM_FCM_25_Line123_CHA             402u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiLineTrueColor_IPDU_COM_FCM_25_Line123_CHA             403u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiRiLineTyp_IPDU_COM_FCM_25_Line123_CHA             404u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiRiLineTrueColor_IPDU_COM_FCM_25_Line123_CHA             405u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLeLineC2_IPDU_COM_FCM_25_Line123_CHA             406u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LaneOffsDst_IPDU_COM_FCM_25_Line123_CHA             407u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiRiLineC2_IPDU_COM_FCM_25_Line123_CHA             408u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_Chksum7_IPDU_COM_FCM_25_Line123_CHA             409u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_AliveCnt7_IPDU_COM_FCM_25_Line123_CHA             410u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLaneDstStrt_IPDU_COM_FCM_25_Line123_CHA             411u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiLaneDstStrt_IPDU_COM_FCM_25_Line123_CHA             412u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLeLaneDstStrt_IPDU_COM_FCM_25_Line123_CHA             413u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiRiLaneDstStrt_IPDU_COM_FCM_25_Line123_CHA             414u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_Chksum8_IPDU_COM_FCM_25_Line123_CHA             415u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_25_AliveCnt8_IPDU_COM_FCM_25_Line123_CHA             416u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLaneDstEnd_IPDU_COM_FCM_25_Line123_CHA             417u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiLaneDstEnd_IPDU_COM_FCM_25_Line123_CHA             418u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_LeLeLaneDstEnd_IPDU_COM_FCM_25_Line123_CHA             419u
#define FCM_25_Line123_CHA_IPDU_COM_FCM_25_Line123_CHA_FCM_RiRiLaneDstEnd_IPDU_COM_FCM_25_Line123_CHA             420u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_TrackID_Chksum1_IPDU_COM_FCM_ObjTrackID_CHA             421u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_TrackID_AliveCnt1_IPDU_COM_FCM_ObjTrackID_CHA             422u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID1_IPDU_COM_FCM_ObjTrackID_CHA             423u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID2_IPDU_COM_FCM_ObjTrackID_CHA             424u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID3_IPDU_COM_FCM_ObjTrackID_CHA             425u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID4_IPDU_COM_FCM_ObjTrackID_CHA             426u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID5_IPDU_COM_FCM_ObjTrackID_CHA             427u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID6_IPDU_COM_FCM_ObjTrackID_CHA             428u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_TrackID_Chksum2_IPDU_COM_FCM_ObjTrackID_CHA             429u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_TrackID_AliveCnt2_IPDU_COM_FCM_ObjTrackID_CHA             430u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID7_IPDU_COM_FCM_ObjTrackID_CHA             431u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID8_IPDU_COM_FCM_ObjTrackID_CHA             432u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID9_IPDU_COM_FCM_ObjTrackID_CHA             433u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID10_IPDU_COM_FCM_ObjTrackID_CHA             434u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID11_IPDU_COM_FCM_ObjTrackID_CHA             435u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID12_IPDU_COM_FCM_ObjTrackID_CHA             436u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_TrackID_Chksum3_IPDU_COM_FCM_ObjTrackID_CHA             437u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_TrackID_AliveCnt3_IPDU_COM_FCM_ObjTrackID_CHA             438u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID13_IPDU_COM_FCM_ObjTrackID_CHA             439u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID14_IPDU_COM_FCM_ObjTrackID_CHA             440u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID15_IPDU_COM_FCM_ObjTrackID_CHA             441u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID16_IPDU_COM_FCM_ObjTrackID_CHA             442u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID17_IPDU_COM_FCM_ObjTrackID_CHA             443u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjTrckID18_IPDU_COM_FCM_ObjTrackID_CHA             444u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_TrackID_Chksum4_IPDU_COM_FCM_ObjTrackID_CHA             445u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_TrackID_AliveCnt4_IPDU_COM_FCM_ObjTrackID_CHA             446u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_ObjRiskSta_IPDU_COM_FCM_ObjTrackID_CHA             447u
#define FCM_ObjTrackID_CHA_IPDU_COM_FCM_ObjTrackID_CHA_FCM_NrOfObj_IPDU_COM_FCM_ObjTrackID_CHA             448u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelPulseNumber_FL_IPDU_COM_ESC_WheelPulseTime_CHA             449u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp1_FL_IPDU_COM_ESC_WheelPulseTime_CHA             450u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp2_FL_IPDU_COM_ESC_WheelPulseTime_CHA             451u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp3_FL_IPDU_COM_ESC_WheelPulseTime_CHA             452u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp4_FL_IPDU_COM_ESC_WheelPulseTime_CHA             453u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp5_FL_IPDU_COM_ESC_WheelPulseTime_CHA             454u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp6_FL_IPDU_COM_ESC_WheelPulseTime_CHA             455u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp7_FL_IPDU_COM_ESC_WheelPulseTime_CHA             456u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp8_FL_IPDU_COM_ESC_WheelPulseTime_CHA             457u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp9_FL_IPDU_COM_ESC_WheelPulseTime_CHA             458u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp10_FL_IPDU_COM_ESC_WheelPulseTime_CHA             459u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelPulseNumber_FR_IPDU_COM_ESC_WheelPulseTime_CHA             460u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp1_FR_IPDU_COM_ESC_WheelPulseTime_CHA             461u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp2_FR_IPDU_COM_ESC_WheelPulseTime_CHA             462u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp3_FR_IPDU_COM_ESC_WheelPulseTime_CHA             463u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp4_FR_IPDU_COM_ESC_WheelPulseTime_CHA             464u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp5_FR_IPDU_COM_ESC_WheelPulseTime_CHA             465u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp6_FR_IPDU_COM_ESC_WheelPulseTime_CHA             466u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp7_FR_IPDU_COM_ESC_WheelPulseTime_CHA             467u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp8_FR_IPDU_COM_ESC_WheelPulseTime_CHA             468u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp9_FR_IPDU_COM_ESC_WheelPulseTime_CHA             469u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp10_FR_IPDU_COM_ESC_WheelPulseTime_CHA             470u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelPulseNumber_RL_IPDU_COM_ESC_WheelPulseTime_CHA             471u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp1_RL_IPDU_COM_ESC_WheelPulseTime_CHA             472u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp2_RL_IPDU_COM_ESC_WheelPulseTime_CHA             473u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp3_RL_IPDU_COM_ESC_WheelPulseTime_CHA             474u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp4_RL_IPDU_COM_ESC_WheelPulseTime_CHA             475u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp5_RL_IPDU_COM_ESC_WheelPulseTime_CHA             476u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp6_RL_IPDU_COM_ESC_WheelPulseTime_CHA             477u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp7_RL_IPDU_COM_ESC_WheelPulseTime_CHA             478u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp8_RL_IPDU_COM_ESC_WheelPulseTime_CHA             479u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp9_RL_IPDU_COM_ESC_WheelPulseTime_CHA             480u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp10_RL_IPDU_COM_ESC_WheelPulseTime_CHA             481u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelPulseNumber_RR_IPDU_COM_ESC_WheelPulseTime_CHA             482u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp1_RR_IPDU_COM_ESC_WheelPulseTime_CHA             483u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp2_RR_IPDU_COM_ESC_WheelPulseTime_CHA             484u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp3_RR_IPDU_COM_ESC_WheelPulseTime_CHA             485u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp4_RR_IPDU_COM_ESC_WheelPulseTime_CHA             486u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp5_RR_IPDU_COM_ESC_WheelPulseTime_CHA             487u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp6_RR_IPDU_COM_ESC_WheelPulseTime_CHA             488u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp7_RR_IPDU_COM_ESC_WheelPulseTime_CHA             489u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp8_RR_IPDU_COM_ESC_WheelPulseTime_CHA             490u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp9_RR_IPDU_COM_ESC_WheelPulseTime_CHA             491u
#define ESC_WheelPulseTime_CHA_IPDU_COM_ESC_WheelPulseTime_CHA_ESC_WheelTimeStamp10_RR_IPDU_COM_ESC_WheelPulseTime_CHA             492u
#define SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA_SRS_2_Chksum_IPDU_COM_SRS_2_YRSOriginalSts_CHA             493u
#define SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA_SRS_2_AliveCnt_IPDU_COM_SRS_2_YRSOriginalSts_CHA             494u
#define SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA_SRS_YRSOrgnlYawRate_IPDU_COM_SRS_2_YRSOriginalSts_CHA             495u
#define SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA_SRS_YRSOrgnlLatAccrn_IPDU_COM_SRS_2_YRSOriginalSts_CHA             496u
#define SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA_SRS_YRSOrgnlLgtAccrn_IPDU_COM_SRS_2_YRSOriginalSts_CHA             497u
#define SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA_SRS_YRSOrgnlLagtSnsrSts_IPDU_COM_SRS_2_YRSOriginalSts_CHA             498u
#define SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA_SRS_YRSOrgnlLgtSnsrSts_IPDU_COM_SRS_2_YRSOriginalSts_CHA             499u
#define SRS_2_YRSOriginalSts_CHA_IPDU_COM_SRS_2_YRSOriginalSts_CHA_SRS_YRSOrgnlYawRateSnsrSts_IPDU_COM_SRS_2_YRSOriginalSts_CHA             500u
#define SRS_3_YRSActualSts_CHA_IPDU_COM_SRS_3_YRSActualSts_CHA_SRS_3_Chksum_IPDU_COM_SRS_3_YRSActualSts_CHA             501u
#define SRS_3_YRSActualSts_CHA_IPDU_COM_SRS_3_YRSActualSts_CHA_SRS_3_AliveCnt_IPDU_COM_SRS_3_YRSActualSts_CHA             502u
#define SRS_3_YRSActualSts_CHA_IPDU_COM_SRS_3_YRSActualSts_CHA_SRS_YRSYawRate_IPDU_COM_SRS_3_YRSActualSts_CHA             503u
#define SRS_3_YRSActualSts_CHA_IPDU_COM_SRS_3_YRSActualSts_CHA_SRS_YRSLatAccrn_IPDU_COM_SRS_3_YRSActualSts_CHA             504u
#define SRS_3_YRSActualSts_CHA_IPDU_COM_SRS_3_YRSActualSts_CHA_SRS_YRSLgtAccrn_IPDU_COM_SRS_3_YRSActualSts_CHA             505u
#define SRS_3_YRSActualSts_CHA_IPDU_COM_SRS_3_YRSActualSts_CHA_SRS_YRSCalSts_IPDU_COM_SRS_3_YRSActualSts_CHA             506u
#define SRS_3_YRSActualSts_CHA_IPDU_COM_SRS_3_YRSActualSts_CHA_SRS_YRSLatSnsrSts_IPDU_COM_SRS_3_YRSActualSts_CHA             507u
#define SRS_3_YRSActualSts_CHA_IPDU_COM_SRS_3_YRSActualSts_CHA_SRS_YRSLgtSnsrSts_IPDU_COM_SRS_3_YRSActualSts_CHA             508u
#define SRS_3_YRSActualSts_CHA_IPDU_COM_SRS_3_YRSActualSts_CHA_SRS_YRSYawRateSnsrSts_IPDU_COM_SRS_3_YRSActualSts_CHA             509u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_3_LatDrv_Chksum_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             510u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_3_LatDrv_AliveCnt_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             511u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_LatMCHptcWrnSrvAvl_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             512u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_LatDrvLvl12SrvAvl_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             513u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_MotTq_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             514u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_TorsionBarTorqueQF_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             515u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_PSCMIntRPCMaxTrq_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             516u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_PSCMIntRPCMinTrq_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             517u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_LatMCHptcWrnActive_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             518u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_LatMCSteerTqActive_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             519u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_3EPSSts_Chksum_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             520u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_3EPSSts_AliveCnt_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             521u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_LKSAglSysSts_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             522u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_MaxAllwdRotSpd_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             523u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_MaxAllwdAgl_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             524u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_steerTq_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             525u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_LKSAglCtrlAvlSts_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             526u
#define EPS_3_LatDrvAndEPSSts_CHA_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_EPS_LKSAbortFb_IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA             527u
#define EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_2_Chksum_IPDU_COM_EPS_2_StrWhlAng_CHA             528u
#define EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_2_AliveCnt_IPDU_COM_EPS_2_StrWhlAng_CHA             529u
#define EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_SteerWheelAngle_IPDU_COM_EPS_2_StrWhlAng_CHA             530u
#define EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_SteerWheelAngleValid_IPDU_COM_EPS_2_StrWhlAng_CHA             531u
#define EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_RotSpeed_IPDU_COM_EPS_2_StrWhlAng_CHA             532u
#define EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_SteerWheelAngleCalibrated_IPDU_COM_EPS_2_StrWhlAng_CHA             533u
#define EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_SteerWheelAngleFailure_IPDU_COM_EPS_2_StrWhlAng_CHA             534u
#define EPS_2_StrWhlAng_CHA_IPDU_COM_EPS_2_StrWhlAng_CHA_EPS_ElectricPowerSta_IPDU_COM_EPS_2_StrWhlAng_CHA             535u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA_EPS_1_Chksum_IPDU_COM_EPS_1_Status_CHA             536u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA_EPS_1_AliveCnt_IPDU_COM_EPS_1_Status_CHA             537u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA_EPS_TorsionBarTorqueValid_IPDU_COM_EPS_1_Status_CHA             538u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA_EPS_TorsionBarTorqueDir_IPDU_COM_EPS_1_Status_CHA             539u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA_EPS_ElecSteerModeSta_IPDU_COM_EPS_1_Status_CHA             540u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA_EPS_ModeSetInhibitFb_IPDU_COM_EPS_1_Status_CHA             541u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA_EPS_BasicElecSteerFailed_IPDU_COM_EPS_1_Status_CHA             542u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA_EPS_TorsionBarTorque_IPDU_COM_EPS_1_Status_CHA             543u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA_EPS_ElectPowerConsumption_IPDU_COM_EPS_1_Status_CHA             544u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA_EPS_AdvancedModeStatus_IPDU_COM_EPS_1_Status_CHA             545u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA_EPS_FaultLvl_IPDU_COM_EPS_1_Status_CHA             546u
#define EPS_1_Status_CHA_IPDU_COM_EPS_1_Status_CHA_EPS_SWS_HODHandsOffSts_IPDU_COM_EPS_1_Status_CHA             547u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_A_Chksum1_IPDU_COM_CRRR_A_CHA             548u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_A_AliveCnt1_IPDU_COM_CRRR_A_CHA             549u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_RCTA_Warn_Right_IPDU_COM_CRRR_A_CHA             550u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_RCTA_SetFb_IPDU_COM_CRRR_A_CHA             551u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_BSD_SetFb_IPDU_COM_CRRR_A_CHA             552u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_BSD_Warn_Left_IPDU_COM_CRRR_A_CHA             553u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_BSD_Warn_Right_IPDU_COM_CRRR_A_CHA             554u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_RCTBDecelaration_IPDU_COM_CRRR_A_CHA             555u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_RCW_Warning_IPDU_COM_CRRR_A_CHA             556u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_FOVChgSetFb_IPDU_COM_CRRR_A_CHA             557u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_RCTB_BrkgVld_IPDU_COM_CRRR_A_CHA             558u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_RCTBReq_IPDU_COM_CRRR_A_CHA             559u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_RCTA_Warn_Left_IPDU_COM_CRRR_A_CHA             560u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_DOWSetFB_IPDU_COM_CRRR_A_CHA             561u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_RearCornerBlindness_IPDU_COM_CRRR_A_CHA             562u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_RearCornerFailure_IPDU_COM_CRRR_A_CHA             563u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_RCW_SetFb_IPDU_COM_CRRR_A_CHA             564u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_DOWWarnRL_IPDU_COM_CRRR_A_CHA             565u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_DOWWarnRR_IPDU_COM_CRRR_A_CHA             566u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_DOWWarnFL_IPDU_COM_CRRR_A_CHA             567u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_DOWWarnFR_IPDU_COM_CRRR_A_CHA             568u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_DOW_Warn_Left_IPDU_COM_CRRR_A_CHA             569u
#define CRRR_A_CHA_IPDU_COM_CRRR_A_CHA_CRRR_DOW_Warn_Right_IPDU_COM_CRRR_A_CHA             570u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_10_Chksum1_IPDU_COM_CRRR_10_Posn_CHA             571u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_10_AliveCnt1_IPDU_COM_CRRR_10_Posn_CHA             572u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_ObjDirYLeft00_IPDU_COM_CRRR_10_Posn_CHA             573u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_ObjDirXLeft00_IPDU_COM_CRRR_10_Posn_CHA             574u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_ObjDirYLeft01_IPDU_COM_CRRR_10_Posn_CHA             575u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_ObjDirXLeft01_IPDU_COM_CRRR_10_Posn_CHA             576u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_ObjDirYRight00_IPDU_COM_CRRR_10_Posn_CHA             577u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_ObjDirXRight00_IPDU_COM_CRRR_10_Posn_CHA             578u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_10_Chksum2_IPDU_COM_CRRR_10_Posn_CHA             579u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_10_AliveCnt2_IPDU_COM_CRRR_10_Posn_CHA             580u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_ObjDirYRight01_IPDU_COM_CRRR_10_Posn_CHA             581u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_ObjDirXRight01_IPDU_COM_CRRR_10_Posn_CHA             582u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_ObjDirYRear00_IPDU_COM_CRRR_10_Posn_CHA             583u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_ObjDirXRear00_IPDU_COM_CRRR_10_Posn_CHA             584u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_ObjDirYRear01_IPDU_COM_CRRR_10_Posn_CHA             585u
#define CRRR_10_Posn_CHA_IPDU_COM_CRRR_10_Posn_CHA_CRRR_ObjDirXRear01_IPDU_COM_CRRR_10_Posn_CHA             586u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_Checksum_IPDU_COM_CCP_PanelStatus_BOD             587u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_RollingCounter_IPDU_COM_CCP_PanelStatus_BOD             588u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_TempAddKey_IPDU_COM_CCP_PanelStatus_BOD             589u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_TempDecreaseKey_IPDU_COM_CCP_PanelStatus_BOD             590u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_BlowerLevelAddKey_IPDU_COM_CCP_PanelStatus_BOD             591u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_BlowerLvlDecreaseKey_IPDU_COM_CCP_PanelStatus_BOD             592u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_BlowingModeNextKey_IPDU_COM_CCP_PanelStatus_BOD             593u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_BlowingModePreviousKey_IPDU_COM_CCP_PanelStatus_BOD             594u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_ACSwitchKey_IPDU_COM_CCP_PanelStatus_BOD             595u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_ACAutoKey_IPDU_COM_CCP_PanelStatus_BOD             596u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_RearViewMirrHeatingKey_IPDU_COM_CCP_PanelStatus_BOD             597u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_AirInletModeKey_IPDU_COM_CCP_PanelStatus_BOD             598u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_FrontWindDefrostKey_IPDU_COM_CCP_PanelStatus_BOD             599u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_ModeKey_IPDU_COM_CCP_PanelStatus_BOD             600u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_HazardKey_IPDU_COM_CCP_PanelStatus_BOD             601u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_CentralLockKey_IPDU_COM_CCP_PanelStatus_BOD             602u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_TPMSKey_IPDU_COM_CCP_PanelStatus_BOD             603u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_ESCOFFKey_IPDU_COM_CCP_PanelStatus_BOD             604u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_AVASOffKey_IPDU_COM_CCP_PanelStatus_BOD             605u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_HDCKey_IPDU_COM_CCP_PanelStatus_BOD             606u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_AVHKey_IPDU_COM_CCP_PanelStatus_BOD             607u
#define CCP_PanelStatus_BOD_IPDU_COM_CCP_PanelStatus_BOD_CCP_PwrRecupLevelKey_IPDU_COM_CCP_PanelStatus_BOD             608u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_Chksum_IPDU_COM_SCS_LeSwitchSts_BOD             609u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_LeSwitchSts_AliveCnt_IPDU_COM_SCS_LeSwitchSts_BOD             610u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_FrntWshrSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD             611u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_FrntWshrSwtStVD_IPDU_COM_SCS_LeSwitchSts_BOD             612u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_RearWiprSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD             613u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_FrntWiprSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD             614u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_WasrSwtStVD_IPDU_COM_SCS_LeSwitchSts_BOD             615u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_WiprSwtStVD_IPDU_COM_SCS_LeSwitchSts_BOD             616u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_PositionLightswitchSt_IPDU_COM_SCS_LeSwitchSts_BOD             617u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_LowBeamSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD             618u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_HiBeamSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD             619u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_OverVehBeamSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD             620u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_LampAutoSt_IPDU_COM_SCS_LeSwitchSts_BOD             621u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_LeTurnLmpSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD             622u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_RiTurnLmpSwtSt_IPDU_COM_SCS_LeSwitchSts_BOD             623u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_1Swt_IPDU_COM_SCS_LeSwitchSts_BOD             624u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_2Swt_IPDU_COM_SCS_LeSwitchSts_BOD             625u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_3Swt_IPDU_COM_SCS_LeSwitchSts_BOD             626u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_4Swt_IPDU_COM_SCS_LeSwitchSts_BOD             627u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_5Swt_IPDU_COM_SCS_LeSwitchSts_BOD             628u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_6Swt_IPDU_COM_SCS_LeSwitchSts_BOD             629u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_KnobBeamSwtStVD_IPDU_COM_SCS_LeSwitchSts_BOD             630u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_RodBeamSwtStVD_IPDU_COM_SCS_LeSwitchSts_BOD             631u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_7Swt_IPDU_COM_SCS_LeSwitchSts_BOD             632u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_Left_8Swt_IPDU_COM_SCS_LeSwitchSts_BOD             633u
#define SCS_LeSwitchSts_BOD_IPDU_COM_SCS_LeSwitchSts_BOD_SCS_LeftSwtVD_IPDU_COM_SCS_LeSwitchSts_BOD             634u
#define TPMS_Info_BOD_IPDU_COM_TPMS_Info_BOD_TPMS_TransducerLocation_IPDU_COM_TPMS_Info_BOD             635u
#define TPMS_Info_BOD_IPDU_COM_TPMS_Info_BOD_TPMS_receiverstate_IPDU_COM_TPMS_Info_BOD             636u
#define TPMS_Info_BOD_IPDU_COM_TPMS_Info_BOD_TPMS_tyrestate_FL_IPDU_COM_TPMS_Info_BOD             637u
#define TPMS_Info_BOD_IPDU_COM_TPMS_Info_BOD_TPMS_tyrestate_FR_IPDU_COM_TPMS_Info_BOD             638u
#define TPMS_Info_BOD_IPDU_COM_TPMS_Info_BOD_TPMS_tyrestate_RR_IPDU_COM_TPMS_Info_BOD             639u
#define TPMS_Info_BOD_IPDU_COM_TPMS_Info_BOD_TPMS_tyrestate_RL_IPDU_COM_TPMS_Info_BOD             640u
#define TPMS_Info_BOD_IPDU_COM_TPMS_Info_BOD_TPMS_tyretemperature_IPDU_COM_TPMS_Info_BOD             641u
#define TPMS_Info_BOD_IPDU_COM_TPMS_Info_BOD_TPMS_tyrepressure_FL_IPDU_COM_TPMS_Info_BOD             642u
#define TPMS_Info_BOD_IPDU_COM_TPMS_Info_BOD_TPMS_tyrepressure_FR_IPDU_COM_TPMS_Info_BOD             643u
#define TPMS_Info_BOD_IPDU_COM_TPMS_Info_BOD_TPMS_tyrepressure_RR_IPDU_COM_TPMS_Info_BOD             644u
#define TPMS_Info_BOD_IPDU_COM_TPMS_Info_BOD_TPMS_tyrepressure_RL_IPDU_COM_TPMS_Info_BOD             645u
#define ESCL_ESCLStatus_BOD_IPDU_COM_ESCL_ESCLStatus_BOD_ESCL_UnOrLock_feedback_IPDU_COM_ESCL_ESCLStatus_BOD             646u
#define AVAS_State_BOD_IPDU_COM_AVAS_State_BOD_AVAS_State_Checksum_IPDU_COM_AVAS_State_BOD             647u
#define AVAS_State_BOD_IPDU_COM_AVAS_State_BOD_AVAS_State_RollingCounter_IPDU_COM_AVAS_State_BOD             648u
#define AVAS_State_BOD_IPDU_COM_AVAS_State_BOD_AVAS_State_IPDU_COM_AVAS_State_BOD             649u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_Checksum_IPDU_COM_COMP_AC_BOD             650u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_RollingCounter_IPDU_COM_COMP_AC_BOD             651u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_OverDuty_IPDU_COM_COMP_AC_BOD             652u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_Commu_Error_IPDU_COM_COMP_AC_BOD             653u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_PI_Saturation_IPDU_COM_COMP_AC_BOD             654u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_LoseStep_IPDU_COM_COMP_AC_BOD             655u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_SelfCheckError_IPDU_COM_COMP_AC_BOD             656u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_IPM_Error_IPDU_COM_COMP_AC_BOD             657u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_TempError_IPDU_COM_COMP_AC_BOD             658u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_LvError_IPDU_COM_COMP_AC_BOD             659u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_HvError_IPDU_COM_COMP_AC_BOD             660u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_OverCurrent_IPDU_COM_COMP_AC_BOD             661u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_EcompST_IPDU_COM_COMP_AC_BOD             662u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_CurrentOffset_IPDU_COM_COMP_AC_BOD             663u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_CANBusOff_IPDU_COM_COMP_AC_BOD             664u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_ECUHighVoltInterlockSignal_IPDU_COM_COMP_AC_BOD             665u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_Temperature_IPDU_COM_COMP_AC_BOD             666u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_InputCurrent_IPDU_COM_COMP_AC_BOD             667u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_High_Voltage_IPDU_COM_COMP_AC_BOD             668u
#define COMP_AC_BOD_IPDU_COM_COMP_AC_BOD_COMP_EcompActSpd_IPDU_COM_COMP_AC_BOD             669u
#define ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD_Client_Number_IPDU_COM_ACCM_Version_BOD             670u
#define ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD_APP_Version_Max_IPDU_COM_ACCM_Version_BOD             671u
#define ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD_APP_Version_Min_IPDU_COM_ACCM_Version_BOD             672u
#define ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD_Hardware_Version_Max_IPDU_COM_ACCM_Version_BOD             673u
#define ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD_Hardware_Version_Min_IPDU_COM_ACCM_Version_BOD             674u
#define ACCM_Version_BOD_IPDU_COM_ACCM_Version_BOD_Boot_Version_IPDU_COM_ACCM_Version_BOD             675u
#define HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCHSts1_Checksum_IPDU_COM_HVCH_Status1_BOD             676u
#define HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCHSts1_RollingCounter_IPDU_COM_HVCH_Status1_BOD             677u
#define HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCH_InletTemp_IPDU_COM_HVCH_Status1_BOD             678u
#define HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCH_OutletTemp_IPDU_COM_HVCH_Status1_BOD             679u
#define HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCH_PCBTemp_IPDU_COM_HVCH_Status1_BOD             680u
#define HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCH_State_IPDU_COM_HVCH_Status1_BOD             681u
#define HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCH_HVState_IPDU_COM_HVCH_Status1_BOD             682u
#define HVCH_Status1_BOD_IPDU_COM_HVCH_Status1_BOD_HVCH_WorkMode_IPDU_COM_HVCH_Status1_BOD             683u
#define HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCHSts2_Checksum_IPDU_COM_HVCH_Status2_BOD             684u
#define HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCHSts2_RollingCounter_IPDU_COM_HVCH_Status2_BOD             685u
#define HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCH_FaultCode_IPDU_COM_HVCH_Status2_BOD             686u
#define HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCH_HV_Volts_IPDU_COM_HVCH_Status2_BOD             687u
#define HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCH_Current_IPDU_COM_HVCH_Status2_BOD             688u
#define HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCH_Power_IPDU_COM_HVCH_Status2_BOD             689u
#define HVCH_Status2_BOD_IPDU_COM_HVCH_Status2_BOD_HVCH_WorkState_IPDU_COM_HVCH_Status2_BOD             690u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_1_Chksum_IPDU_COM_BMS_1_MainState_EPT             691u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_1_AliveCnt_IPDU_COM_BMS_1_MainState_EPT             692u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_ThermalrunawayWrn_IPDU_COM_BMS_1_MainState_EPT             693u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_InsulationWrningDistgsh_IPDU_COM_BMS_1_MainState_EPT             694u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_ActlExchgCurnt_IPDU_COM_BMS_1_MainState_EPT             695u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_SupplyVoltageStatus_IPDU_COM_BMS_1_MainState_EPT             696u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_Contactor_state_Precharge_IPDU_COM_BMS_1_MainState_EPT             697u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_Contactor_state_Positive_IPDU_COM_BMS_1_MainState_EPT             698u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_Contactor_state_Negative_IPDU_COM_BMS_1_MainState_EPT             699u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_RunState_IPDU_COM_BMS_1_MainState_EPT             700u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_DisChargeInterlockSta_IPDU_COM_BMS_1_MainState_EPT             701u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_ChargeInterlockSta_IPDU_COM_BMS_1_MainState_EPT             702u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_Emeshutdown_Req_IPDU_COM_BMS_1_MainState_EPT             703u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_PwrTrainConnectSta_IPDU_COM_BMS_1_MainState_EPT             704u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_ErrTabIndex_IPDU_COM_BMS_1_MainState_EPT             705u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_BAS_WakeUp_IPDU_COM_BMS_1_MainState_EPT             706u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_ThermRunawayVlvSt_IPDU_COM_BMS_1_MainState_EPT             707u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_ThermRunawaySnsrFlt_IPDU_COM_BMS_1_MainState_EPT             708u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_Batt_BalanceSta_IPDU_COM_BMS_1_MainState_EPT             709u
#define BMS_1_MainState_EPT_IPDU_COM_BMS_1_MainState_EPT_BMS_SysFailSta_IPDU_COM_BMS_1_MainState_EPT             710u
#define BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_2_Chksum_IPDU_COM_BMS_2_BatState_EPT             711u
#define BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_2_AliveCnt_IPDU_COM_BMS_2_BatState_EPT             712u
#define BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_HVBatActlVoltage_IPDU_COM_BMS_2_BatState_EPT             713u
#define BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_BatSOC_Rpt_IPDU_COM_BMS_2_BatState_EPT             714u
#define BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_BatSOH_IPDU_COM_BMS_2_BatState_EPT             715u
#define BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_HVBatActlVoltageV_IPDU_COM_BMS_2_BatState_EPT             716u
#define BMS_2_BatState_EPT_IPDU_COM_BMS_2_BatState_EPT_BMS_BatSOC_Actl_IPDU_COM_BMS_2_BatState_EPT             717u
#define BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_3_Chksum_IPDU_COM_BMS_3_DC_ChargeState_EPT             718u
#define BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_3_AliveCnt_IPDU_COM_BMS_3_DC_ChargeState_EPT             719u
#define BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_TempMax_DCChargeSocket_IPDU_COM_BMS_3_DC_ChargeState_EPT             720u
#define BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_PCB_TempMax_IPDU_COM_BMS_3_DC_ChargeState_EPT             721u
#define BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_MaxAllowChrgCur_DC_IPDU_COM_BMS_3_DC_ChargeState_EPT             722u
#define BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_Electronic_Lock_Ctrl_IPDU_COM_BMS_3_DC_ChargeState_EPT             723u
#define BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_MaxAllowChrgVol_DC_IPDU_COM_BMS_3_DC_ChargeState_EPT             724u
#define BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_DCS_ChrgAPlus_IPDU_COM_BMS_3_DC_ChargeState_EPT             725u
#define BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_DCS_ChargeRequest_IPDU_COM_BMS_3_DC_ChargeState_EPT             726u
#define BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_Contactor_state_DCCharger_IPDU_COM_BMS_3_DC_ChargeState_EPT             727u
#define BMS_3_DC_ChargeState_EPT_IPDU_COM_BMS_3_DC_ChargeState_EPT_BMS_Electronic_Lock_State_IPDU_COM_BMS_3_DC_ChargeState_EPT             728u
#define BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_4_Chksum_IPDU_COM_BMS_4_AC_ChargeState_EPT             729u
#define BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_4_AliveCnt_IPDU_COM_BMS_4_AC_ChargeState_EPT             730u
#define BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_ACChrgAtclSta_IPDU_COM_BMS_4_AC_ChargeState_EPT             731u
#define BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_OutletCoolantActlTempValid_IPDU_COM_BMS_4_AC_ChargeState_EPT             732u
#define BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_OutletCoolantActlTemp_IPDU_COM_BMS_4_AC_ChargeState_EPT             733u
#define BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_InletCoolantActlTempValid_IPDU_COM_BMS_4_AC_ChargeState_EPT             734u
#define BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_InletCoolantActlTemp_IPDU_COM_BMS_4_AC_ChargeState_EPT             735u
#define BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_IsoResistance_IPDU_COM_BMS_4_AC_ChargeState_EPT             736u
#define BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_MaxChrgVoltage_AC_IPDU_COM_BMS_4_AC_ChargeState_EPT             737u
#define BMS_4_AC_ChargeState_EPT_IPDU_COM_BMS_4_AC_ChargeState_EPT_BMS_MaxChrgCurrent_AC_IPDU_COM_BMS_4_AC_ChargeState_EPT             738u
#define BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_10_Chksum_IPDU_COM_BMS_10_DC_ChargeStates_EPT             739u
#define BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_10_AliveCnt_IPDU_COM_BMS_10_DC_ChargeStates_EPT             740u
#define BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_DCS_InletConnectSta_IPDU_COM_BMS_10_DC_ChargeStates_EPT             741u
#define BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_DC_AC_RemChrgTime_IPDU_COM_BMS_10_DC_ChargeStates_EPT             742u
#define BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_DCS_ActlChrgCurrent_IPDU_COM_BMS_10_DC_ChargeStates_EPT             743u
#define BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_DCS_ActOprtMode_IPDU_COM_BMS_10_DC_ChargeStates_EPT             744u
#define BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_DCS_ActlChrgVoltage_IPDU_COM_BMS_10_DC_ChargeStates_EPT             745u
#define BMS_10_DC_ChargeStates_EPT_IPDU_COM_BMS_10_DC_ChargeStates_EPT_BMS_DCS_ActlChrgPower_IPDU_COM_BMS_10_DC_ChargeStates_EPT             746u
#define BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_5_Chksum_IPDU_COM_BMS_5_BatTemp_EPT             747u
#define BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_5_AliveCnt_IPDU_COM_BMS_5_BatTemp_EPT             748u
#define BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_HVBatCellTempValid_IPDU_COM_BMS_5_BatTemp_EPT             749u
#define BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_MinTempProbeCod_IPDU_COM_BMS_5_BatTemp_EPT             750u
#define BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_HVBatCellTempAve_IPDU_COM_BMS_5_BatTemp_EPT             751u
#define BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_HVBatCellTempMax_IPDU_COM_BMS_5_BatTemp_EPT             752u
#define BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_HVBatCellTempMin_IPDU_COM_BMS_5_BatTemp_EPT             753u
#define BMS_5_BatTemp_EPT_IPDU_COM_BMS_5_BatTemp_EPT_BMS_MaxTempProbeCod_IPDU_COM_BMS_5_BatTemp_EPT             754u
#define BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT_BMS_MaxConDisCurnt_IPDU_COM_BMS_6_DischrgRecup_EPT             755u
#define BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT_BMS_PwrRecupMaxConChrgCurnt_IPDU_COM_BMS_6_DischrgRecup_EPT             756u
#define BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT_BMS_MaxInstanDisCurnt_IPDU_COM_BMS_6_DischrgRecup_EPT             757u
#define BMS_6_DischrgRecup_EPT_IPDU_COM_BMS_6_DischrgRecup_EPT_BMS_PwrRecupMaxInstanChrgCurnt_IPDU_COM_BMS_6_DischrgRecup_EPT             758u
#define BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT_BMS_CellVolMax_IPDU_COM_BMS_7_CellVolt_EPT             759u
#define BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT_BMS_MaxVolCellCod_IPDU_COM_BMS_7_CellVolt_EPT             760u
#define BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT_BMS_CellVolAve_IPDU_COM_BMS_7_CellVolt_EPT             761u
#define BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT_BMS_CellVolMin_IPDU_COM_BMS_7_CellVolt_EPT             762u
#define BMS_7_CellVolt_EPT_IPDU_COM_BMS_7_CellVolt_EPT_BMS_MinVolCellCod_IPDU_COM_BMS_7_CellVolt_EPT             763u
#define BMS_8_TempVoltLimit_EPT_IPDU_COM_BMS_8_TempVoltLimit_EPT_BMS_ContactorTemp_Negative_IPDU_COM_BMS_8_TempVoltLimit_EPT             764u
#define BMS_8_TempVoltLimit_EPT_IPDU_COM_BMS_8_TempVoltLimit_EPT_BMS_MaxCellTempLimit_IPDU_COM_BMS_8_TempVoltLimit_EPT             765u
#define BMS_8_TempVoltLimit_EPT_IPDU_COM_BMS_8_TempVoltLimit_EPT_BMS_MaxCellVolLimit_IPDU_COM_BMS_8_TempVoltLimit_EPT             766u
#define BMS_8_TempVoltLimit_EPT_IPDU_COM_BMS_8_TempVoltLimit_EPT_BMS_MinCellTempLimit_IPDU_COM_BMS_8_TempVoltLimit_EPT             767u
#define BMS_8_TempVoltLimit_EPT_IPDU_COM_BMS_8_TempVoltLimit_EPT_BMS_PwrLimdFlg_IPDU_COM_BMS_8_TempVoltLimit_EPT             768u
#define BMS_8_TempVoltLimit_EPT_IPDU_COM_BMS_8_TempVoltLimit_EPT_BMS_MinCellVolLimit_IPDU_COM_BMS_8_TempVoltLimit_EPT             769u
#define BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT_BMS_BatteryType_IPDU_COM_BMS_9_BattInfo_EPT             770u
#define BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT_BMS_HW_Version_IPDU_COM_BMS_9_BattInfo_EPT             771u
#define BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT_BMS_Pack_Identity_IPDU_COM_BMS_9_BattInfo_EPT             772u
#define BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT_BMS_SW_Version_IPDU_COM_BMS_9_BattInfo_EPT             773u
#define BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT_BMS_BatCapacity_IPDU_COM_BMS_9_BattInfo_EPT             774u
#define BMS_9_BattInfo_EPT_IPDU_COM_BMS_9_BattInfo_EPT_BMS_NomCellCap_IPDU_COM_BMS_9_BattInfo_EPT             775u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_CellUnderrVolWrning_IPDU_COM_BMS_A_GB_EPT             776u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_HighSOCWrning_IPDU_COM_BMS_A_GB_EPT             777u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_AbnormallSOCWrning_IPDU_COM_BMS_A_GB_EPT             778u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_BatterytSysMismatchingWrning_IPDU_COM_BMS_A_GB_EPT             779u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_CellInconsistencyWrning_IPDU_COM_BMS_A_GB_EPT             780u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_InsulationWrning_IPDU_COM_BMS_A_GB_EPT             781u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_HighVolInterLockWrning_IPDU_COM_BMS_A_GB_EPT             782u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_BatteryOverChrgWrning_IPDU_COM_BMS_A_GB_EPT             783u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_CurrentOverWrning_IPDU_COM_BMS_A_GB_EPT             784u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_TempDifferWrning_IPDU_COM_BMS_A_GB_EPT             785u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_HighTempWrning_IPDU_COM_BMS_A_GB_EPT             786u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_BatteryOverVolWrning_IPDU_COM_BMS_A_GB_EPT             787u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_BatteryUnderrVolWrning_IPDU_COM_BMS_A_GB_EPT             788u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_LowSOCWrning_IPDU_COM_BMS_A_GB_EPT             789u
#define BMS_A_GB_EPT_IPDU_COM_BMS_A_GB_EPT_BMS_CellOverVolWrning_IPDU_COM_BMS_A_GB_EPT             790u
#define BMS_B_GB_EPT_IPDU_COM_BMS_B_GB_EPT_BMS_BatteryDTC_Num_IPDU_COM_BMS_B_GB_EPT             791u
#define BMS_B_GB_EPT_IPDU_COM_BMS_B_GB_EPT_BMS_BatteryDTC_List_IPDU_COM_BMS_B_GB_EPT             792u
#define BMS_B_GB_EPT_IPDU_COM_BMS_B_GB_EPT_BMS_BatterySubSysNum_IPDU_COM_BMS_B_GB_EPT             793u
#define BMS_B_GB_EPT_IPDU_COM_BMS_B_GB_EPT_BMS_BatterySubSysCod_IPDU_COM_BMS_B_GB_EPT             794u
#define BMS_B_GB_EPT_IPDU_COM_BMS_B_GB_EPT_BMS_BatteryDTC_Index_IPDU_COM_BMS_B_GB_EPT             795u
#define BMS_C_GB_EPT_IPDU_COM_BMS_C_GB_EPT_BMS_Cell_Index_IPDU_COM_BMS_C_GB_EPT             796u
#define BMS_C_GB_EPT_IPDU_COM_BMS_C_GB_EPT_BMS_CellVol0_IPDU_COM_BMS_C_GB_EPT             797u
#define BMS_C_GB_EPT_IPDU_COM_BMS_C_GB_EPT_BMS_CellVol1_IPDU_COM_BMS_C_GB_EPT             798u
#define BMS_C_GB_EPT_IPDU_COM_BMS_C_GB_EPT_BMS_CellVol2_IPDU_COM_BMS_C_GB_EPT             799u
#define BMS_C_GB_EPT_IPDU_COM_BMS_C_GB_EPT_BMS_TotalCellNo_IPDU_COM_BMS_C_GB_EPT             800u
#define BMS_D_GB_EPT_IPDU_COM_BMS_D_GB_EPT_BMS_TotalTempProbe_IPDU_COM_BMS_D_GB_EPT             801u
#define BMS_D_GB_EPT_IPDU_COM_BMS_D_GB_EPT_BMS_TempProbe_Index_IPDU_COM_BMS_D_GB_EPT             802u
#define BMS_D_GB_EPT_IPDU_COM_BMS_D_GB_EPT_BMS_TempProbe0_IPDU_COM_BMS_D_GB_EPT             803u
#define BMS_D_GB_EPT_IPDU_COM_BMS_D_GB_EPT_BMS_TempProbe1_IPDU_COM_BMS_D_GB_EPT             804u
#define BMS_D_GB_EPT_IPDU_COM_BMS_D_GB_EPT_BMS_TempProbe2_IPDU_COM_BMS_D_GB_EPT             805u
#define BMS_D_GB_EPT_IPDU_COM_BMS_D_GB_EPT_BMS_TempProbe3_IPDU_COM_BMS_D_GB_EPT             806u
#define BMS_D_GB_EPT_IPDU_COM_BMS_D_GB_EPT_BMS_TempProbe4_IPDU_COM_BMS_D_GB_EPT             807u
#define BMS_D_GB_EPT_IPDU_COM_BMS_D_GB_EPT_BMS_TempProbe5_IPDU_COM_BMS_D_GB_EPT             808u
#define IPU_OBC_3_CP_CC_EPT_IPDU_COM_IPU_OBC_3_CP_CC_EPT_IPU_OBC_3_Chksum_IPDU_COM_IPU_OBC_3_CP_CC_EPT             809u
#define IPU_OBC_3_CP_CC_EPT_IPDU_COM_IPU_OBC_3_CP_CC_EPT_IPU_OBC_3_AliveCnt_IPDU_COM_IPU_OBC_3_CP_CC_EPT             810u
#define IPU_OBC_3_CP_CC_EPT_IPDU_COM_IPU_OBC_3_CP_CC_EPT_IPU_OBC_CCorCPCnctdSts_IPDU_COM_IPU_OBC_3_CP_CC_EPT             811u
#define IPU_OBC_3_CP_CC_EPT_IPDU_COM_IPU_OBC_3_CP_CC_EPT_IPU_OBC_CCResisdent_IPDU_COM_IPU_OBC_3_CP_CC_EPT             812u
#define IPU_OBC_3_CP_CC_EPT_IPDU_COM_IPU_OBC_3_CP_CC_EPT_IPU_OBC_CPDuty_IPDU_COM_IPU_OBC_3_CP_CC_EPT             813u
#define IPU_OBC_3_CP_CC_EPT_IPDU_COM_IPU_OBC_3_CP_CC_EPT_IPU_OBC_CPMaxVolt_IPDU_COM_IPU_OBC_3_CP_CC_EPT             814u
#define IPU_OBC_3_CP_CC_EPT_IPDU_COM_IPU_OBC_3_CP_CC_EPT_IPU_OBC_ProcessCode_IPDU_COM_IPU_OBC_3_CP_CC_EPT             815u
#define IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_1_Chksum_IPDU_COM_IPU_DCC_1_State_EPT             816u
#define IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_1_AliveCnt_IPDU_COM_IPU_DCC_1_State_EPT             817u
#define IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_LowVolActlVol_IPDU_COM_IPU_DCC_1_State_EPT             818u
#define IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_ActlOprtMode_IPDU_COM_IPU_DCC_1_State_EPT             819u
#define IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_LowVolActlCur_IPDU_COM_IPU_DCC_1_State_EPT             820u
#define IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_HVILFailSta_IPDU_COM_IPU_DCC_1_State_EPT             821u
#define IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_SysFailSta_IPDU_COM_IPU_DCC_1_State_EPT             822u
#define IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_OverTemperatureFail_IPDU_COM_IPU_DCC_1_State_EPT             823u
#define IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_DeratingOprtSta_IPDU_COM_IPU_DCC_1_State_EPT             824u
#define IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_PrechargeComplete_IPDU_COM_IPU_DCC_1_State_EPT             825u
#define IPU_DCC_1_State_EPT_IPDU_COM_IPU_DCC_1_State_EPT_IPU_DCC_Errbit_IPDU_COM_IPU_DCC_1_State_EPT             826u
#define IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_1_Chksum_IPDU_COM_IPU_OBC_1_State_EPT             827u
#define IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_1_AliveCnt_IPDU_COM_IPU_OBC_1_State_EPT             828u
#define IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_ConnectMainSta_IPDU_COM_IPU_OBC_1_State_EPT             829u
#define IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_HVDC_ActlCur_IPDU_COM_IPU_OBC_1_State_EPT             830u
#define IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_SysFailSta_IPDU_COM_IPU_OBC_1_State_EPT             831u
#define IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_InletConnctSta_IPDU_COM_IPU_OBC_1_State_EPT             832u
#define IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_Request_IPDU_COM_IPU_OBC_1_State_EPT             833u
#define IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_HVDC_ActlVol_IPDU_COM_IPU_OBC_1_State_EPT             834u
#define IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_ActlOprtMode_IPDU_COM_IPU_OBC_1_State_EPT             835u
#define IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_InleltActlPower_IPDU_COM_IPU_OBC_1_State_EPT             836u
#define IPU_OBC_1_State_EPT_IPDU_COM_IPU_OBC_1_State_EPT_IPU_OBC_Errbit_IPDU_COM_IPU_OBC_1_State_EPT             837u
#define IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_Chksum_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT             838u
#define IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_2_AliveCnt_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT             839u
#define IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_HighVoltActlCur_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT             840u
#define IPU_DCC_2_ChrgInValue_EPT_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT_IPU_DCC_HighVoltActlVol_IPDU_COM_IPU_DCC_2_ChrgInValue_EPT             841u
#define IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_Chksum_IPDU_COM_IPU_OBC_2_Inlet_EPT             842u
#define IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_2_AliveCnt_IPDU_COM_IPU_OBC_2_Inlet_EPT             843u
#define IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_DeviceIntTemp_IPDU_COM_IPU_OBC_2_Inlet_EPT             844u
#define IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_TempInlet_IPDU_COM_IPU_OBC_2_Inlet_EPT             845u
#define IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_S2_State_IPDU_COM_IPU_OBC_2_Inlet_EPT             846u
#define IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_Wake_Up_Mode_IPDU_COM_IPU_OBC_2_Inlet_EPT             847u
#define IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_Inlet_Electronic_Lock_IPDU_COM_IPU_OBC_2_Inlet_EPT             848u
#define IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_ACMaxPwAllow_IPDU_COM_IPU_OBC_2_Inlet_EPT             849u
#define IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_VoltageOkL3_IPDU_COM_IPU_OBC_2_Inlet_EPT             850u
#define IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_VoltageOkL2_IPDU_COM_IPU_OBC_2_Inlet_EPT             851u
#define IPU_OBC_2_Inlet_EPT_IPDU_COM_IPU_OBC_2_Inlet_EPT_IPU_OBC_VoltageOkL1_IPDU_COM_IPU_OBC_2_Inlet_EPT             852u
#define IPU_OBC_4_state_EPT_IPDU_COM_IPU_OBC_4_state_EPT_IPU_OBC_UacActL1_IPDU_COM_IPU_OBC_4_state_EPT             853u
#define IPU_OBC_4_state_EPT_IPDU_COM_IPU_OBC_4_state_EPT_IPU_OBC_UacActL2_IPDU_COM_IPU_OBC_4_state_EPT             854u
#define IPU_OBC_4_state_EPT_IPDU_COM_IPU_OBC_4_state_EPT_IPU_OBC_UacActL3_IPDU_COM_IPU_OBC_4_state_EPT             855u
#define IPU_OBC_4_state_EPT_IPDU_COM_IPU_OBC_4_state_EPT_IPU_OBC_IacActL1_IPDU_COM_IPU_OBC_4_state_EPT             856u
#define IPU_OBC_4_state_EPT_IPDU_COM_IPU_OBC_4_state_EPT_IPU_OBC_IacActL2_IPDU_COM_IPU_OBC_4_state_EPT             857u
#define IPU_OBC_4_state_EPT_IPDU_COM_IPU_OBC_4_state_EPT_IPU_OBC_IacActL3_IPDU_COM_IPU_OBC_4_state_EPT             858u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_CheckSum_IPDU_COM_INV_1_Value_EPT             859u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_RollingCounter_IPDU_COM_INV_1_Value_EPT             860u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_MotMode_IPDU_COM_INV_1_Value_EPT             861u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_ActTorque_IPDU_COM_INV_1_Value_EPT             862u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_HasDerating_IPDU_COM_INV_1_Value_EPT             863u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_MotSpeed_IPDU_COM_INV_1_Value_EPT             864u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_PreprogmFlg_IPDU_COM_INV_1_Value_EPT             865u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_SkidStaus_IPDU_COM_INV_1_Value_EPT             866u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_PreChargeAllowed_IPDU_COM_INV_1_Value_EPT             867u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_ShutdownAllowed_IPDU_COM_INV_1_Value_EPT             868u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_ActiveDischarge_Status_IPDU_COM_INV_1_Value_EPT             869u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_AntithftAuthRslt_IPDU_COM_INV_1_Value_EPT             870u
#define INV_1_Value_EPT_IPDU_COM_INV_1_Value_EPT_INV_1_ActMode_IPDU_COM_INV_1_Value_EPT             871u
#define INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_CheckSum_IPDU_COM_INV_2_Value_EPT             872u
#define INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_RollingCounter_IPDU_COM_INV_2_Value_EPT             873u
#define INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_Derating_IPDU_COM_INV_2_Value_EPT             874u
#define INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_MotorMaxTem_IPDU_COM_INV_2_Value_EPT             875u
#define INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_IgbtMaxTem_IPDU_COM_INV_2_Value_EPT             876u
#define INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_InpCurrent_IPDU_COM_INV_2_Value_EPT             877u
#define INV_2_Value_EPT_IPDU_COM_INV_2_Value_EPT_INV_2_InpVoltage_IPDU_COM_INV_2_Value_EPT             878u
#define INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT_INV_3_CheckSum_IPDU_COM_INV_3_Value_EPT             879u
#define INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT_INV_3_RollingCounter_IPDU_COM_INV_3_Value_EPT             880u
#define INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT_INV_3_DriveTqAllowedMax_IPDU_COM_INV_3_Value_EPT             881u
#define INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT_INV_ActiveDampingMark_IPDU_COM_INV_3_Value_EPT             882u
#define INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT_INV_3_RecuperationTqAllowedMax_IPDU_COM_INV_3_Value_EPT             883u
#define INV_3_Value_EPT_IPDU_COM_INV_3_Value_EPT_INV_ActiveDampingValue_IPDU_COM_INV_3_Value_EPT             884u
#define INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT_INV_4_CheckSum_IPDU_COM_INV_4_Value_EPT             885u
#define INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT_INV_4_RollingCounter_IPDU_COM_INV_4_Value_EPT             886u
#define INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT_INV_4_FaultLevl_IPDU_COM_INV_4_Value_EPT             887u
#define INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT_INV_4_ErrBits_IPDU_COM_INV_4_Value_EPT             888u
#define INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT_INV_4_PhaseV_AC_Current_IPDU_COM_INV_4_Value_EPT             889u
#define INV_4_Value_EPT_IPDU_COM_INV_4_Value_EPT_INV_4_PhaseU_AC_Current_IPDU_COM_INV_4_Value_EPT             890u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_05_CheckSum_IPDU_COM_INV_5_Values_EPT             891u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_05_RollingCounter_IPDU_COM_INV_5_Values_EPT             892u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err1Overcurrent_IPDU_COM_INV_5_Values_EPT             893u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err2IGBTFlt_IPDU_COM_INV_5_Values_EPT             894u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err3RDCFlt_IPDU_COM_INV_5_Values_EPT             895u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err4PhaseSamplingFlt_IPDU_COM_INV_5_Values_EPT             896u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err5ContrOverTemp_IPDU_COM_INV_5_Values_EPT             897u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err6MotTemp_IPDU_COM_INV_5_Values_EPT             898u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err7DCLinkOverVoltg_IPDU_COM_INV_5_Values_EPT             899u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err8DCLinkUnderVoltg_IPDU_COM_INV_5_Values_EPT             900u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err10LockedRotorFlt_IPDU_COM_INV_5_Values_EPT             901u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err11SWOvercur_IPDU_COM_INV_5_Values_EPT             902u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err12CtrlModuleComBusOff_IPDU_COM_INV_5_Values_EPT             903u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err14LostComWithVCU_IPDU_COM_INV_5_Values_EPT             904u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err16VcuChksErr_IPDU_COM_INV_5_Values_EPT             905u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err18OverSpd_IPDU_COM_INV_5_Values_EPT             906u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err19ContrTempSnsrFlt_IPDU_COM_INV_5_Values_EPT             907u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err20MotTempSnsrFlt_IPDU_COM_INV_5_Values_EPT             908u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err21DCLinkVolDetdFault_IPDU_COM_INV_5_Values_EPT             909u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err22TqFbFlt_IPDU_COM_INV_5_Values_EPT             910u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err23Zero_DriftFlt_IPDU_COM_INV_5_Values_EPT             911u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err24ContrOverTempWarn_IPDU_COM_INV_5_Values_EPT             912u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err25MotOverTempWarn_IPDU_COM_INV_5_Values_EPT             913u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err26CtrlModuleInpPwr_High_IPDU_COM_INV_5_Values_EPT             914u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err27CtrlModuleInpPwr_low_IPDU_COM_INV_5_Values_EPT             915u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err28ResolverInpClipped_IPDU_COM_INV_5_Values_EPT             916u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err29ResolverInpBelowLOS_IPDU_COM_INV_5_Values_EPT             917u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err30ResolverInpExcdDOSOver_IPDU_COM_INV_5_Values_EPT             918u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err31ResolverInpExcdDOSMisma_IPDU_COM_INV_5_Values_EPT             919u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err32ResolverTrackingExcdLOT_IPDU_COM_INV_5_Values_EPT             920u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err33ResolverVelExcdMaxTrack_IPDU_COM_INV_5_Values_EPT             921u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err34ResolverPhaseErr_IPDU_COM_INV_5_Values_EPT             922u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err35ResolverCfgParErr_IPDU_COM_INV_5_Values_EPT             923u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err36LostComWithTBOX_IPDU_COM_INV_5_Values_EPT             924u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err37LostComWithHU_IPDU_COM_INV_5_Values_EPT             925u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err38LostComWithESCIDB_IPDU_COM_INV_5_Values_EPT             926u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err39LostComWithBCM_IPDU_COM_INV_5_Values_EPT             927u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err40LostComWithEPK_IPDU_COM_INV_5_Values_EPT             928u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err41DCLinkOverVoltgWarn_IPDU_COM_INV_5_Values_EPT             929u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_Err42DCLinkUnderVoltgWarn_IPDU_COM_INV_5_Values_EPT             930u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_ErrRsvd43_IPDU_COM_INV_5_Values_EPT             931u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_ErrRsvd44_IPDU_COM_INV_5_Values_EPT             932u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_ErrRsvd45_IPDU_COM_INV_5_Values_EPT             933u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_ErrRsvd46_IPDU_COM_INV_5_Values_EPT             934u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_ErrRsvd47_IPDU_COM_INV_5_Values_EPT             935u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_ErrRsvd48_IPDU_COM_INV_5_Values_EPT             936u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_ErrRsvd49_IPDU_COM_INV_5_Values_EPT             937u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_ErrRsvd50_IPDU_COM_INV_5_Values_EPT             938u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_ErrRsvd51_IPDU_COM_INV_5_Values_EPT             939u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_ErrRsvd52_IPDU_COM_INV_5_Values_EPT             940u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_ErrRsvd53_IPDU_COM_INV_5_Values_EPT             941u
#define INV_5_Values_EPT_IPDU_COM_INV_5_Values_EPT_INV_ErrRsvd54_IPDU_COM_INV_5_Values_EPT             942u
#define INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngSubID_IPDU_COM_INV_IMMO_Req_EPT             943u
#define INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngSts_IPDU_COM_INV_IMMO_Req_EPT             944u
#define INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngData02_IPDU_COM_INV_IMMO_Req_EPT             945u
#define INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngData03_IPDU_COM_INV_IMMO_Req_EPT             946u
#define INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngData04_IPDU_COM_INV_IMMO_Req_EPT             947u
#define INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngData05_IPDU_COM_INV_IMMO_Req_EPT             948u
#define INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngData06_IPDU_COM_INV_IMMO_Req_EPT             949u
#define INV_IMMO_Req_EPT_IPDU_COM_INV_IMMO_Req_EPT_INV_LrngData07_IPDU_COM_INV_IMMO_Req_EPT             950u
#define ICU_Info_BAC_IPDU_COM_ICU_Info_BAC_ICU_Info_Chhsum_IPDU_COM_ICU_Info_BAC             951u
#define ICU_Info_BAC_IPDU_COM_ICU_Info_BAC_ICU_Info_AliveCnt_IPDU_COM_ICU_Info_BAC             952u
#define ICU_Info_BAC_IPDU_COM_ICU_Info_BAC_ICU_VehicleSpeedDisplayedV_IPDU_COM_ICU_Info_BAC             953u
#define ICU_Info_BAC_IPDU_COM_ICU_Info_BAC_ICU_VehicleSpeedDisplayed_IPDU_COM_ICU_Info_BAC             954u
#define ICU_2_Odo_BAC_IPDU_COM_ICU_2_Odo_BAC_ICU_ICUTotalOdometer_IPDU_COM_ICU_2_Odo_BAC             955u
#define ICU_2_Odo_BAC_IPDU_COM_ICU_2_Odo_BAC_ICU_ICUTripAOdometer_IPDU_COM_ICU_2_Odo_BAC             956u
#define ICU_2_Odo_BAC_IPDU_COM_ICU_2_Odo_BAC_ICU_ICUTripBOdometer_IPDU_COM_ICU_2_Odo_BAC             957u
#define HU_C_BAC_IPDU_COM_HU_C_BAC_HU_C_Chksum_IPDU_COM_HU_C_BAC             958u
#define HU_C_BAC_IPDU_COM_HU_C_BAC_HU_C_AliveCnt_IPDU_COM_HU_C_BAC             959u
#define HU_C_BAC_IPDU_COM_HU_C_BAC_HU_AVASSet_IPDU_COM_HU_C_BAC             960u
#define HU_C_BAC_IPDU_COM_HU_C_BAC_HU_TPMSLearningReq_IPDU_COM_HU_C_BAC             961u
#define TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Chksum_IPDU_COM_TBOX_BJS_Time_BAC             962u
#define TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_AliveCnt_IPDU_COM_TBOX_BJS_Time_BAC             963u
#define TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Time_Year_IPDU_COM_TBOX_BJS_Time_BAC             964u
#define TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Time_Month_IPDU_COM_TBOX_BJS_Time_BAC             965u
#define TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Time_Day_IPDU_COM_TBOX_BJS_Time_BAC             966u
#define TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Time_Hour_IPDU_COM_TBOX_BJS_Time_BAC             967u
#define TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Time_Min_IPDU_COM_TBOX_BJS_Time_BAC             968u
#define TBOX_BJS_Time_BAC_IPDU_COM_TBOX_BJS_Time_BAC_TBOX_BJS_Time_Sec_IPDU_COM_TBOX_BJS_Time_BAC             969u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_B_Chksum1_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             970u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_B_AliveCnt1_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             971u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_HybridEcoModeSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             972u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_LeftTempSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             973u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_ACPowerCtl_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             974u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_AirInletModeSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             975u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_FrontFanSpdSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             976u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_ManualDefrostCtl_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             977u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_BlowerModeSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             978u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_FlwrMeHmCtrl_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             979u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_IllmndEntrySts_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             980u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_LockHornOnSt_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             981u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_ACAutoCtl_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             982u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_DrivingModeSelect_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             983u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_B_Chksum2_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             984u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_B_AliveCnt2_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             985u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_ParkAutoUnlckSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             986u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_OverspdCntrlLockSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             987u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_TrunkLockSwCtrl_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             988u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_ChgWiperMtMdSwSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             989u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_TPMSResetReq_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             990u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_MaiDrvrSeatHeat_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             991u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_PwrOFFReq_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             992u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_WiprIntlTimeSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             993u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_CDC_BackLadjval_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             994u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_RearMirrorHeat_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             995u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_SteerWhlHeat_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             996u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_IllmndUnlockSts_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             997u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_IllmndLockSts_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             998u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_CoastRecupModeSelect_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             999u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_PeristalsisModeEnb_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             1000u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_RecuperatePowerSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             1001u
#define HU_B_BAC_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_HU_DrivingPowerSet_IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1             1002u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_Chksum1_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1003u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_AliveCnt1_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1004u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_LDW_Enable_Sw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1005u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_LDW_AlertMethodSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1006u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_RCW_EnableSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1007u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_RCTA_EnableSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1008u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_BSD_EnableSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1009u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DOWEnaSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1010u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_LKA_EnableSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1011u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ASL_EnableSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1012u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ALC_EnableSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1013u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ALCRmnModeSwt_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1014u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ALCSnvtySw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1015u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_HMA_EnableSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1016u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ICAAvdTruckSet_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1017u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ICAEnaSwt_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1018u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ICASwtReq_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1019u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_TJAAutoResuSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1020u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_TJAICASwtReq_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1021u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_TSR_EnableSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1022u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_AEB_EnableSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1023u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_SpdDowninCorEnableSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1024u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_PPSwtPsd_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1025u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DrvrCfmASLDisp_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1026u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ELKEnbSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1027u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_Chksum2_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1028u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_AliveCnt2_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1029u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_NaviCountryCode_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1030u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_NaviSpeedLimit_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1031u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_NaviCurrentRoadType_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1032u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_Navigation_TSI_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1033u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_NaviSpeedLimitUnit_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1034u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_NaviSpeedLimitStatus_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1035u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_Chksum3_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1036u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_AliveCnt3_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1037u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_SpdLimAckmtReq_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1038u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_vSetDis_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1039u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_TimeGapCtrlReq_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1040u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_SpdCtrlReq_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1041u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ACCSwtReq1_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1042u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ACCSwtReq_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1043u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ADASSwtReq_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1044u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DrvOffReq_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1045u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_TimeGapDis_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1046u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_Chksum4_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1047u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_AliveCnt4_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1048u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSHeadRollAgl_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1049u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSClsEyeContnsTime_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1050u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSHeartJmpFlg_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1051u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSDrvrOnSeatFlg_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1052u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSDrwnsLvl_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1053u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSDistracLvl_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1054u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_Chksum5_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1055u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_AliveCnt5_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1056u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSSts_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1057u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSRearViewDetd_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1058u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSHeadYawAgl_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1059u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSHeadPitchAgl_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1060u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSEmotnDetd_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1061u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSKeyCoverageSts_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1062u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSSgtHozlAgl_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1063u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSSgtVertAgl_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1064u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_Chksum6_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1065u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_AliveCnt6_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1066u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSSmkDetd_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1067u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSSmkCfdce_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1068u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSPhnDetd_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1069u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSPhnCfdce_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1070u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSDrinkDetd_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1071u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSDrinkCfdce_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1072u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSClsEyeCfdce_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1073u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSYawnCfdce_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1074u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DMSDistracCfdce_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1075u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_Chksum7_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1076u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_A_AliveCnt7_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1077u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_IB_brakePedalfeelmode_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1078u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_HDC_EnableSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1079u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ESCFuncEnaSta_Resvd_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1080u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_AVH_Enb_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1081u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_EPB_Modal_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1082u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ElecSteerModeSet_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1083u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ReqEPB_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1084u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_ReqEPBVld_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1085u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_DrivingModeWarn_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1086u
#define HU_A_BAC_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_HU_BrkDisWipSw_IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1             1087u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_RiSwitchSts_Chksum_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1088u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_RiSwitchSts_AliveCnt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1089u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_9Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1090u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_10Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1091u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_GearShiftLeverPstReqVD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1092u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_GearShiftLeverPstReq_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1093u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_RightSwtVD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1094u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_11Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1095u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_12Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1096u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_13Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1097u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_14Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1098u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_15Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1099u
#define SCS_RiSwitchSts_BOD_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_SCS_Right_16Swt_IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6             1100u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_D_Chksum1_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1101u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_D_AliveCnt1_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1102u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_AEBObjID_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1103u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_AEBObjObstcl_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1104u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_AEBObjDirY_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1105u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_AEBTarTyp_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1106u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_AEBObjDirX_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1107u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_SpdDowninCorActive_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1108u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_AEBObjExistnc_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1109u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_D_Chksum2_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1110u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_D_AliveCnt2_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1111u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_AEBObjDirVX_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1112u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_AEBObjDirVY_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1113u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_AEBObjDirAX_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1114u
#define FCM_D_CHA_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_FCM_AEBObjDirAY_IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5             1115u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_Chksum1_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1116u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_AliveCnt1_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1117u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_LgtFctActvFlg_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1118u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ELKLaneOverSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1119u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_SteerTqReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1120u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ELKMode_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1121u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ELKoSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1122u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ELKRoadEdgeSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1123u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_EPSSetSteerWhlAgl_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1124u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_DAEPSModeReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1125u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_DrvrWarnVibReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1126u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_EPSCtrlReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1127u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_SteerTqReqActive_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1128u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_Chksum2_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1129u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_AliveCnt2_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1130u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ActDrvAsstSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1131u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_SpdLimKeepDst_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1132u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_TJAICASuppsAbortn_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1133u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_TurnLampReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1134u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_OvertakeAssSysSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1135u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_LKALDWSuppsAbortn_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1136u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_HMASuppsAbortn_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1137u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ELKSuppsAbortn_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1138u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_FltSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1139u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_Chksum3_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1140u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_AliveCnt3_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1141u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ACCWhlTqReqActv_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1142u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ACCWhlTqReqVal_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1143u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ACCWhlDece_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1144u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccTarAccrn_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1145u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_EPBReqV_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1146u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_CrvDecelSta_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1147u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccTarAccrnReqActv_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1148u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ACCSuppAbort_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1149u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_EPBReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1150u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_Chksum4_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1151u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_AliveCnt4_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1152u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AhdObjID_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1153u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AhdObjTyp_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1154u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AhdObjLgtRelSpd_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1155u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AhdObjLatDst_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1156u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AhdObjLgtDst_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1157u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_Chksum5_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1158u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_B_AliveCnt5_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1159u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccTgtAx_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1160u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccReqStandstill_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1161u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccReqDriveOff_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1162u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccTgtAxReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1163u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccMode_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1164u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AEBTgtAx_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1165u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AEBStandstillStsV_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1166u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AEBStandstillSts_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1167u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AEBReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1168u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AccPreKeReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1169u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ABAReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1170u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_EBAReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1171u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AWBLevel_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1172u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ABALevel_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1173u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_ABPReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1174u
#define FCM_B_CHA_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_FCM_AWBReq_IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5             1175u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_A_Chksum1_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1176u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_A_AliveCnt1_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1177u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ELKFrntLatDst_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1178u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ELKFrntLgtDst_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1179u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ELKRecReq_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1180u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ELKTakeOverReq_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1181u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ELKRearObjLocn_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1182u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ELKFrntTyp_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1183u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_HMASts_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1184u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_HMA_HighbeamReq_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1185u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_AEBSetFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1186u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_AEBRecReq_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1187u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ELKSetFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1188u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_SpdDowninCorSfk_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1189u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_HMASetFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1190u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TurnLightReq_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1191u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_AmbLampreq_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1192u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_A_Chksum2_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1193u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_A_AliveCnt2_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1194u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_RiLaneOccpd_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1195u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ALCLeLineTyp_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1196u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ALCRiLineTyp_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1197u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TxtInfoALC1_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1198u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_LeLaneOccpd_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1199u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ALCArrowDir_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1200u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ALCStaHMI_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1201u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ALCNotAvlReas_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1202u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ALCSetFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1203u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ALCDrvrReq_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1204u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ALCSnvtySetFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1205u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ALCRmnModFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1206u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSRSpdLimSts_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1207u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSRSpdLimWarnAu_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1208u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSRSpdLimWarn_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1209u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_A_Chksum3_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1210u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_A_AliveCnt3_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1211u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TrfcSign_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1212u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSRLgtDst_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1213u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSR_SetFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1214u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSRLatDst_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1215u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSRCnvtnTyp_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1216u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSRSpdLim_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1217u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSRSpdLimUnit_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1218u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSRShape_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1219u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSROperSts_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1220u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TrfcSign1_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1221u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSRHei_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1222u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TSRCfdce_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1223u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_A_Chksum4_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1224u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_A_AliveCnt4_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1225u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_DrvrHandsoffRmn_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1226u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TJATakeoverReq_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1227u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TJAAutoResuSwFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1228u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TJATrafficType_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1229u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_DriverHandsOff_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1230u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_AudioWarnHandsOff_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1231u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_StrtTimeRmn1_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1232u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ActDrvAsstStsHMI_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1233u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_LimTextInfo_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1234u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_FaultTextInfo_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1235u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_HeatReq_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1236u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_HeatgWireErrSts_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1237u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_A_Chksum5_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1238u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_A_AliveCnt5_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1239u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TarObjACC_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1240u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ICATruckSetFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1241u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ACCStart_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1242u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ADASNotAvlReas_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1243u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_vSetDis_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1244u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ACCTakeOverReq_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1245u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ICASetFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1246u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ADASDrvrReq_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1247u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TauGapSet_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1248u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_ADASQuitReas_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1249u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_PCWLatentWarn_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1250u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_PCWPreWarn_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1251u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_AccModeHMI_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1252u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_dxTarObj_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1253u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_PEBSFailInfo_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1254u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_A_Chksum6_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1255u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_A_AliveCnt6_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1256u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_LDWSetFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1257u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_LDWSts_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1258u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TextInfoLKA1_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1259u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_LKASetFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1260u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_LeLineColorFct_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1261u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_LKASts_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1262u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_LDWAlertMethodSetFb_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1263u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_TextInfoLKA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1264u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_LDWAudioWarn_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1265u
#define FCM_A_CHA_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_FCM_RiLineColorFct_IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5             1266u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum1_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1267u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt1_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1268u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_DTC_ActiveSts_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1269u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_BrakeTempOverHeat_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1270u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_DTCFailureSts_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1271u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_DTCRequestRBSSts_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1272u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_VhclStandstillSta_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1273u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum2_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1274u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt2_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1275u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelDirection_FL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1276u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKphV_FL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1277u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKph_FL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1278u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelDirection_FR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1279u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKphV_FR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1280u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKph_FR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1281u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_MasterCylinderPresr_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1282u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_MasterCylinderPresrV_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1283u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum3_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1284u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt3_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1285u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelDirection_RL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1286u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKphV_RL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1287u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKph_RL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1288u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelDirection_RR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1289u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKphV_RR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1290u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedKph_RR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1291u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum4_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1292u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt4_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1293u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRCSts_RR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1294u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRCSts_RL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1295u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRCSts_FR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1296u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRCSts_FL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1297u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRC_FL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1298u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRC_FR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1299u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRC_RL_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1300u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WheelSpeedRC_RR_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1301u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum5_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1302u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt5_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1303u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_LatAccSensorValueVld_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1304u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_LongAccSensorValueVld_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1305u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_LongAccSensorValue_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1306u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_YawRateVld_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1307u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_LatAccSensorValue_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1308u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_YawRate_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1309u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum6_RihgtEPB_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1310u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt6_RihgtEPB_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1311u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_EPB_RightFaultState_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1312u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_EPB_Right_Current_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1313u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_EPB_ActuatorSt_R_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1314u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_Chksum7_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1315u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_A_AliveCnt7_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1316u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WhlTqDecReqActv_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1317u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WhlTqDecReqVal_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1318u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WhlTqIncReqActv_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1319u
#define ESC_A_CHA_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_ESC_WhlTqIncReqVal_IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5             1320u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_7_Chksum_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1321u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_7_AliveCnt_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1322u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ESCorTCSFailed_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1323u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ABSActiveSta_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1324u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_VehicleSpeedV_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1325u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_VehicleSpeed_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1326u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_EBDFailed_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1327u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ABSFailed_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1328u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_TCSActiveSta_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1329u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ESPActiveSta_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1330u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ReqBrakeLightOn_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1331u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_RMIActiveSta_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1332u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_HMI_WarningOn_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1333u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_CDPAvailable_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1334u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_CDPActive_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1335u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ESSAvailable_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1336u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ESSActive_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1337u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_EBDActiveSta_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1338u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_FaultLevel_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1339u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_ESCDisable_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1340u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_SlopePercentV_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1341u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_PALAResponse_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1342u
#define ESC_7_FuncStatus_CHA_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_ESC_SlopePercent_IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5             1343u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_B_Chksum1_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1344u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_B_AliveCnt1_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1345u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_PBCInApplyRelsReq_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1346u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_PedlTrvlSnsrPlauSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1347u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_EPB_DynamicApplySta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1348u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_BrkPedlValPercVld_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1349u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_PBCRollrBenchActvVldty_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1350u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_PBCRollrBenchActv_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1351u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_BrkPedlValVld_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1352u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_BrkPedlVal_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1353u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_BrkPedlValPerc_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1354u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_FaultLevel_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1355u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_PedlTrvlSnsrFail_PDT_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1356u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_ReqBrkLiOn_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1357u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_PedlTrvlSnsrFail_PDF_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1358u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_B_Chksum2_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1359u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_B_AliveCnt2_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1360u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_CDDTempOff_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1361u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_B_Chksum3_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1362u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_B_AliveCnt3_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1363u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_BrkPwrRecupTarWhlTq_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1364u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_BrkPwrRecupTarWhlTqSts_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1365u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_ABP_ActiveSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1366u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_ABP_AvailableSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1367u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_NoBrakeForce_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1368u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_EPB_ActuatorSt_R_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1369u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_CDDAvailable_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1370u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_CDDActive_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1371u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_ABA_AvailableSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1372u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_ABA_ActiveSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1373u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_AWB_AvailableSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1374u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_AWB_ActiveSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1375u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_AEB_AvailableSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1376u
#define EHB_B_CHA_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_EHB_AEB_ActiveSta_IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5             1377u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_A_Chksum_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1378u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_A_AliveCnt_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1379u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_BrkDisWipAc_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1380u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_AVHDispMSG_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1381u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_CDPRequest_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1382u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_ActuatorSt_L_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1383u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_WarnLampSta_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1384u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_FltSts_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1385u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_RequestEcho_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1386u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_ParkLampSta_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1387u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_Left_FailStatus_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1388u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_SwitchSts_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1389u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_SystemState_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1390u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_DisplayMsgID_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1391u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_ExtReqPrio_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1392u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_HDCFucFault_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1393u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_BBSDfctv_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1394u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_BrakeLiquidLevelWarn_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1395u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_FailureSts_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1396u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_EPB_Right_MotComd_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1397u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_AVHLampReq_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1398u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_HHC_ActiveSta_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1399u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_RgnBrkSt_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1400u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_AVHAppldSt_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1401u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_ExtReqStatus_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1402u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_BLA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1403u
#define EHB_A_CHA_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_EHB_HMI_WarningOn_IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5             1404u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_1_Chksum_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1405u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_1_AliveCnt_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1406u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_DrvSeatbeltBucklestatus_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1407u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_DrvSeatbeltBuckleValid_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1408u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_PassSeatbeltBucklestatus_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1409u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_PassSeatbeltBuckleValid_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1410u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_MidSeatBeltBucklestatus_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1411u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_MidSeatBeltBuckleValid_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1412u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_PassengerAirbagSta_Rsvr_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1413u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_PassSeatOccupantSensorSts_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1414u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_PassAirbSts_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1415u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_CrashOutputSts_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1416u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_MidSeatOccupantSensorSts_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1417u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_DrvSeatBeltRSt_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1418u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_PsSeatBeltRSt_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1419u
#define SRS_1_Status_CHA_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_SRS_AirbagWarningLampSts_IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5             1420u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RearDist_Chksum_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1421u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RearDist_AliveCnt_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1422u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RLDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1423u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RLMDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1424u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RRMDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1425u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RRDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1426u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RearArea_Chksum_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1427u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RearArea_AliveCnt_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1428u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SensorFaultStsRLM_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1429u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SensorFaultStsRL_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1430u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SDWRSLDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1431u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SDWRSLMidDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1432u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SensorFaultStsRR_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1433u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SensorFaultStsRRM_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1434u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SDWRSRMidDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1435u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SDWRSRDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1436u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_FrontDist_Chksum_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1437u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_FrontDist_AliveCnt_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1438u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_FLDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1439u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_FMLDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1440u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_FMRDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1441u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_FRDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1442u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_FrontArea_Chksum_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1443u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_FrontArea_AliveCnt_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1444u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SensorFaultStsFLM_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1445u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SensorFaultStsFL_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1446u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SDWFSLDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1447u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SDWFSLMidDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1448u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SensorFaultStsFR_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1449u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SensorFaultStsFRM_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1450u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SDWFSRMidDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1451u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SDWFSRDist_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1452u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SysSts_Chksum_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1453u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SysSts_AliveCnt_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1454u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_Buzzer_Alarm_Pattern_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1455u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_SwFdbk_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1456u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_Sta_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1457u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RAEB_WorkSts_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1458u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RAEB_SetFb_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1459u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RAEB_BrkgReq_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1460u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RAEB_BrkgReqVal_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1461u
#define PP_InformAndStatus_CHA_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_PP_RAEB_DistanceToCollision_IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5             1462u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define COM_GWMAPPING_NUMBER         0u
#define COM_GW_SOURCE_DESCRIPTION_NUMBER     0u
#define COM_GW_DESTINATION_DESCRIPTION_NUMBER        0u

#define COM_TXTPPDU_SUPPORT          STD_OFF
#define COM_RXTPPDU_SUPPORT          STD_OFF

boolean IPDU_COM_VCU_0_Value_EPT_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_VCU_10_Torque_CHA_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_BCM_4_CruiseSw_PM_CHA_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_AC_3_State_CHA_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_AC_ACStatuts_BOD_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_AC_COMP_BOD_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_VCU_7_DrvRange_BOD_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_AC_1_Command_BOD_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_HVCH_Command_BOD_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_AC_3_State_BOD_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_AC_2_State_BOD_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_AC_8_status_BOD_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TMS_LINTestData1_BOD_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TMS_LINTestData2_BOD_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TMS_LINTestData3_BOD_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_VCU_3_OprtCmd_EPT_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_VCU_4_ChrgCmd_EPT_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_VCU_B_AcclPedal_EPT_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_VCU_1_InvCmd_EPT_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_VCU_C_OprtCmd_EPT_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_BCM_IMMOAuthResp1_EPT_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_AC_ACStatuts_BAC_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_AC_3_State_BAC_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_BCM_HFSData_BAC_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_NM_ASR_CCU_BAC_CANFD8_BAC_CAN1_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_NM_ASR_CCU_BOD_CANFD5_BOD_CAN6_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_NM_ASR_CCU_CHA_CANFD3_CHA_CAN5_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_NM_ASR_CCU_EPT_CANFD6_EPT_CAN2_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_CCU_VehInfo_BOD_CANFD5_BOD_CAN6_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_BCM_ESCLCommand_BOD_CANFD5_BOD_CAN6_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_TX_CCU_VehInfo_EPT_CANFD6_EPT_CAN2_TxCallout(PduIdType PduId, PduInfoType* PduInfoPtr);

boolean IPDU_COM_FCM_23_Obj0109_CHA_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_FCM_24_Obj1018_CHA_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_FCM_25_Line123_CHA_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_FCM_ObjTrackID_CHA_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_ESC_WheelPulseTime_CHA_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_SRS_2_YRSOriginalSts_CHA_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_SRS_3_YRSActualSts_CHA_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_EPS_3_LatDrvAndEPSSts_CHA_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_EPS_2_StrWhlAng_CHA_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_EPS_1_Status_CHA_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_CRRR_A_CHA_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_CRRR_10_Posn_CHA_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_CCP_PanelStatus_BOD_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_SCS_LeSwitchSts_BOD_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_TPMS_Info_BOD_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_ESCL_ESCLStatus_BOD_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_AVAS_State_BOD_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_COMP_AC_BOD_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_ACCM_Version_BOD_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_HVCH_Status1_BOD_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_HVCH_Status2_BOD_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_1_MainState_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_2_BatState_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_3_DC_ChargeState_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_4_AC_ChargeState_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_10_DC_ChargeStates_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_5_BatTemp_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_6_DischrgRecup_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_7_CellVolt_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_8_TempVoltLimit_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_9_BattInfo_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_A_GB_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_B_GB_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_C_GB_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_BMS_D_GB_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_IPU_OBC_3_CP_CC_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_IPU_DCC_1_State_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_IPU_OBC_1_State_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_IPU_DCC_2_ChrgInValue_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_IPU_OBC_2_Inlet_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_IPU_OBC_4_state_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_INV_1_Value_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_INV_2_Value_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_INV_3_Value_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_INV_4_Value_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_INV_5_Values_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_INV_IMMO_Req_EPT_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_ICU_Info_BAC_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_ICU_2_Odo_BAC_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_HU_C_BAC_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_TBOX_BJS_Time_BAC_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_RX_HU_B_BAC_CANFD8_BAC_CAN1_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_RX_HU_A_BAC_CANFD8_BAC_CAN1_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_RX_SCS_RiSwitchSts_BOD_CANFD5_BOD_CAN6_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_RX_FCM_D_CHA_CANFD3_CHA_CAN5_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_RX_ESC_A_CHA_CANFD3_CHA_CAN5_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_RX_ESC_7_FuncStatus_CHA_CANFD3_CHA_CAN5_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_RX_EHB_B_CHA_CANFD3_CHA_CAN5_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_RX_SRS_1_Status_CHA_CANFD3_CHA_CAN5_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

boolean IPDU_COM_RX_PP_InformAndStatus_CHA_CANFD3_CHA_CAN5_RxCallout(PduIdType PduId, const PduInfoType* PduInfoPtr);

/* Macro for Optimize */
#define COM_SIGNAL_GW_ENABLE    STD_OFF

#define COM_TMS_ENABLE    STD_OFF

#define COM_TX_MODE_DIRECT_ENABLE    STD_ON

#define COM_TX_MODE_MIXED_ENABLE    STD_ON

#define COM_TX_MODE_DIRECT_N_TIMES_ENABLE   STD_OFF

#define COM_TX_MODE_MIXED_N_TIMES_ENABLE    STD_OFF

#define COM_MDT_ENABLE  STD_OFF

#define COM_TX_IPDU_COUNTER_ENABLE  STD_OFF

#define COM_RX_IPDU_COUNTER_ENABLE  STD_OFF

#define COM_IPDU_REPLICATION_ENABLE      STD_OFF

#define COM_TX_SIGNAL_NOTIFICATION_ENABLE   STD_OFF

#define COM_RX_SIGNAL_NOTIFICATION_ENABLE   STD_ON

#define COM_RX_SIGNAL_TIMEOUT_ENABLE    STD_OFF

#define COM_TX_SIGNAL_TIMEOUT_ENABLE    STD_OFF

#define COM_RX_SIGNAL_TIMEOUT_NOTIFICATION_ENABLE      STD_OFF

#define COM_TX_SIGNAL_TIMEOUT_NOTIFICATION_ENABLE     STD_OFF

#define COM_RX_SIGNAL_UPDATE_BIT_ENABLE     STD_OFF

#define COM_TX_SIGNAL_UPDATE_BIT_ENABLE     STD_OFF

#define COM_RX_SIGNAL_INVALID_DATA_ENABLE   STD_OFF

#define COM_RX_SIGNAL_INVALID_DATA_ACTION_NOTIFY_ENABLE     STD_ON

#define COM_TX_SIG_PROP_TRIGGERED_ENABLE    STD_OFF

#define COM_TX_SIG_PROP_TRIGGERED_ON_CHANGE_ENABLE  STD_OFF

#define COM_TX_SIG_PROP_TRIG_ON_CH_NO_REPETITION_ENABLE     STD_OFF

#define COM_TX_SIG_PROP_TRIG_NO_REPETITION_ENABLE   STD_ON

#define COM_TX_SIGNAL_ERROR_NOTIFICATION_ENABLE     STD_OFF

#define COM_RX_SIGNAL_FILTER_ENABLE     STD_OFF

#define COM_TX_SIGNAL_TYPE_UINT8_DYN_ENABLE     STD_OFF

#define COM_RX_SIGNAL_TYPE_UINT8_DYN_ENABLE     STD_OFF

#define COM_RX_SIGNAL_TYPE_UINT8_N_ENABLE   STD_OFF

#define COM_TX_SIG_GROUP_NOTIFICATION_ENABLE    STD_ON

#define COM_RX_SIG_GROUP_NOTIFICATION_ENABLE    STD_ON

#define COM_RX_SIG_GROUP_TIMEOUT_ENABLE     STD_ON

#define COM_TX_SIG_GROUP_TIMEOUT_ENABLE     STD_ON

#define COM_RX_SIG_GROUP_TIMEOUT_NOTIFICATION_ENABLE    STD_ON

#define COM_TX_SIG_GROUP_TIMEOUT_NOTIFICATION_ENABLE    STD_ON

#define COM_RX_SIG_GROUP_UPDATE_BIT_ENABLE  STD_OFF

#define COM_TX_SIG_GROUP_UPDATE_BIT_ENABLE  STD_OFF

#define COM_TX_SIG_GROUP_PROP_TRIGGERED_ENABLE  STD_OFF

#define COM_TX_SIG_GROUP_PROP_TRIGGERED_ON_CHANGE_ENABLE    STD_OFF

#define COM_TX_SIG_GROUP_PROP_TRIG_ON_CH_NO_REPETITION_ENABLE   STD_OFF

#define COM_TX_SIG_GROUP_PROP_TRIG_NO_REPETITION_ENABLE     STD_OFF

#define COM_TX_SIG_GROUP_ERROR_NOTIFICATION_ENABLE  STD_OFF

#define COM_TX_SIG_GROUP_INITIAL_VALUE_ONLY_ENABLE  STD_OFF

#define COM_RX_SIG_GROUP_INVALID_DATA_ACTION_NOTIFY_ENABLE  STD_ON

#define COM_TX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE      STD_OFF

#define COM_RX_GRP_SIGNAL_TYPE_UINT8_DYN_ENABLE     STD_OFF

#define COM_RX_GRP_SIGNAL_TYPE_UINT8_N_ENABLE   STD_OFF

#define COM_RX_GRP_SIGNAL_INVALID_DATA_ENABLE   STD_OFF

#define COM_RX_GRP_SIGNAL_FILTER_ENABLE     STD_OFF

#define COM_GW_DEST_SIG_UPDATE_BIT_ENABLE   STD_OFF

#define COM_GW_SRC_SIG_UPDATE_BIT_ENABLE    STD_OFF

#define COM_TX_IPDU_CALLOUT_ENABLE     STD_ON

#define COM_RX_IPDU_CALLOUT_ENABLE     STD_ON

#define COM_TX_SIG_INITIAL_VALUE_ONLY_ENABLE  STD_OFF

#define COM_RX_IPDU_SIGNAL_PROCESS_IMMEDIATE_ENABLE     STD_OFF

#define COM_TX_IPDU_SIGNAL_PROCESS_IMMEDIATE_ENABLE     STD_OFF

#define COM_TX_IPDU_TYPE_TP_ENABLE     STD_OFF

#define COM_RX_SIGNAL_TIMEOUT_ACTION_REPLACE_ENABLE     STD_OFF

#define COM_RX_SIG_GROUP_TIMEOUT_ACTION_REPLACE_ENABLE     STD_OFF

#define COM_GW_SRC_DSP_SIG_TYPE_UINT8_N_ENABLE     STD_OFF

#define COM_GW_SRC_DSP_SIG_TYPE_UINT8_DYN_ENABLE     STD_OFF

#define COM_SIGNAL_SIGNED_TYPE_ENABLE     STD_OFF

#endif


