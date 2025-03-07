
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
**  FILENAME    : CanIf_Cfg.h                                                 **
**                                                                            **
**  Created on  : 2024/12/10 11:20:57                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : cfg parameter declaration of CanIf                          **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef CANIF_CFG_H
#define CANIF_CFG_H

/*=======[V E R S I O N  I N F O R M A T I O N]===============================*/
#define CANIF_CFG_H_AR_MAJOR_VERSION    4u
#define CANIF_CFG_H_AR_MINOR_VERSION    2u
#define CANIF_CFG_H_AR_PATCH_VERSION    2u
#define CANIF_CFG_H_SW_MAJOR_VERSION    2u
#define CANIF_CFG_H_SW_MINOR_VERSION    0u
#define CANIF_CFG_H_SW_PATCH_VERSION    0u

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
#define CANIF_CAN_AUTOSAR_422                0u
#define CANIF_CAN_AUTOSAR_431                1u
#define CANIF_CAN_AUTOSAR_440                2u

#define CANIF_CAN_AUTOSAR_VERSION            CANIF_CAN_AUTOSAR_431

#define CANIF_SOFTWARE_FILTER_BINARY                0u
#define CANIF_SOFTWARE_FILTER_INDEX                 1u
#define CANIF_SOFTWARE_FILTER_LINEAR                2u
#define CANIF_SOFTWARE_FILTER_TABLE                 3u

#define CANIF_HRH_RANGE_SUPPORT     STD_OFF

#define CANIF_RXPDU_CANID_RANGE_SUPPORT     STD_OFF

#define CANIF_RX_STANDARD_CAN_SUPPORT     STD_ON

#define CANIF_RX_STANDARD_FD_CAN_SUPPORT     STD_ON

#define CANIF_RX_STANDARD_NO_FD_CAN_SUPPORT     STD_OFF

#define CANIF_RX_EXTENDED_CAN_SUPPORT     STD_OFF

#define CANIF_RX_EXTENDED_FD_CAN_SUPPORT     STD_OFF

#define CANIF_RX_EXTENDED_NO_FD_CAN_SUPPORT     STD_OFF

#define CANIF_TX_EXTENDED_CAN_SUPPORT       STD_OFF

#define CANIF_TX_EXTENDED_FD_CAN_SUPPORT        STD_OFF

#define CANIF_TX_STANDARD_CAN_SUPPORT           STD_ON

#define CANIF_TX_STANDARD_FD_CAN_SUPPORT        STD_ON

#define CANIF_FIXED_BUFFER            STD_ON

#define CANIF_PRIVATE_DLC_CHECK       STD_OFF

#define CANIF_SOFTWARE_FILTER_TYPE    CANIF_SOFTWARE_FILTER_LINEAR

#define CANIF_SUPPORT_TTCAN           STD_OFF

#define CANIF_META_DATA_SUPPORT       STD_OFF

#define CANIF_PUBLIC_CANCEL_TRANSMIT_SUPPORT               STD_OFF

#define CANIF_PUBLIC_DEV_ERROR_DETECT                      STD_ON

#define CANIF_PUBLIC_ICOM_SUPPORT                          STD_OFF

#define CANIF_PUBLIC_MULTIPLE_DRV_SUPPORT                  STD_ON

#define CANIF_PUBLIC_PN_SUPPORT                            STD_OFF

#define CANIF_PUBLIC_READ_RX_PDU_DATA_API                  STD_OFF

#define CANIF_PUBLIC_READ_RX_PDU_NOTIFY_STATUS_API         STD_OFF

#define CANIF_PUBLIC_READ_TX_PDU_NOTIFY_STATUS_API         STD_OFF

#define CANIF_PUBLIC_SET_DYNAMIC_TX_ID_API                 STD_OFF

#define CANIF_PUBLIC_TX_BUFFERING                          STD_ON

#define CANIF_PUBLIC_TX_CONFIRM_POLLING_SUPPORT            STD_ON

#define CANIF_PUBLIC_VERSION_INFO_API                      STD_ON

#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_BY_NM              STD_ON

#define CANIF_PUBLIC_WAKEUP_CHECK_VALID_SUPPORT            STD_ON/* PRQA S 0791 */ /* MISRA Rule 5.4 */

#define CANIF_SET_BAUDRATE_API                             STD_OFF

#define CANIF_TRIGGER_TRANSMIT_SUPPORT            STD_OFF

#define CANIF_TX_OFFLINE_ACTIVE_SUPPORT           STD_OFF

#define CANIF_WAKE_UP_SUPPORT                     STD_ON

#define CANIF_CANDRV_WAKE_UP_SUPPORT              STD_OFF

#define CANIF_CANTRCV_WAKE_UP_SUPPORT             STD_OFF

#define CANIF_WAKEUPSOURCE_MAX                    0x3FFu
/*******************************************************************************************/

#define CANIF_RXPDU_NUMBER              133u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define CANIF_RXPDU_TMSR_DTO_XCP         0u
#define CANIF_RXPDU_CanNm_CAN2_CANFD6_RX         1u
#define CANIF_RXPDU_CanNm_CAN1_CANFD8_RX         2u
#define CANIF_RXPDU_CanNm_CAN5_CANFD3_RX         3u
#define CANIF_RXPDU_CanNm_CAN6_CANFD5_RX         4u
#define CANIF_RXPDU_CCP_PanelStatus_BOD         5u
#define CANIF_RXPDU_SCS_RiSwitchSts_BOD         6u
#define CANIF_RXPDU_SCS_LeSwitchSts_BOD         7u
#define CANIF_RXPDU_TPMS_Info_BOD         8u
#define CANIF_RXPDU_ESCL_ESCLStatus_BOD         9u
#define CANIF_RXPDU_AVAS_State_BOD         10u
#define CANIF_RXPDU_COMP_AC_BOD         11u
#define CANIF_RXPDU_ACCM_Version_BOD         12u
#define CANIF_RXPDU_HVCH_Status1_BOD         13u
#define CANIF_RXPDU_HVCH_Status2_BOD         14u
#define CANIF_RXPDU_BMS_1_MainState_EPT         15u
#define CANIF_RXPDU_BMS_2_BatState_EPT         16u
#define CANIF_RXPDU_BMS_3_DC_ChargeState_EPT         17u
#define CANIF_RXPDU_BMS_4_AC_ChargeState_EPT         18u
#define CANIF_RXPDU_BMS_10_DC_ChargeStates_EPT         19u
#define CANIF_RXPDU_BMS_5_BatTemp_EPT         20u
#define CANIF_RXPDU_BMS_6_DischrgRecup_EPT         21u
#define CANIF_RXPDU_BMS_7_CellVolt_EPT         22u
#define CANIF_RXPDU_BMS_8_TempVoltLimit_EPT         23u
#define CANIF_RXPDU_BMS_9_BattInfo_EPT         24u
#define CANIF_RXPDU_BMS_A_GB_EPT         25u
#define CANIF_RXPDU_BMS_B_GB_EPT         26u
#define CANIF_RXPDU_BMS_C_GB_EPT         27u
#define CANIF_RXPDU_BMS_D_GB_EPT         28u
#define CANIF_RXPDU_IPU_OBC_3_CP_CC_EPT         29u
#define CANIF_RXPDU_IPU_DCC_1_State_EPT         30u
#define CANIF_RXPDU_IPU_OBC_1_State_EPT         31u
#define CANIF_RXPDU_IPU_DCC_2_ChrgInValue_EPT         32u
#define CANIF_RXPDU_IPU_OBC_2_Inlet_EPT         33u
#define CANIF_RXPDU_IPU_OBC_4_state_EPT         34u
#define CANIF_RXPDU_INV_1_Value_EPT         35u
#define CANIF_RXPDU_INV_2_Value_EPT         36u
#define CANIF_RXPDU_INV_3_Value_EPT         37u
#define CANIF_RXPDU_INV_4_Value_EPT         38u
#define CANIF_RXPDU_INV_5_Values_EPT         39u
#define CANIF_RXPDU_INV_IMMO_Req_EPT         40u
#define CANIF_RXPDU_CANIF_Diag_Resp_ACCM_RX_BOD         41u
#define CANIF_RXPDU_CANIF_Diag_Resp_AVAS_RX_BOD         42u
#define CANIF_RXPDU_CANIF_Diag_Resp_CCP_RX_BOD         43u
#define CANIF_RXPDU_CANIF_Diag_Resp_ESCL_RX_BOD         44u
#define CANIF_RXPDU_CANIF_Diag_Resp_PTC_RX_BOD         45u
#define CANIF_RXPDU_CANIF_Diag_Resp_SCS_RX_BOD         46u
#define CANIF_RXPDU_CANIF_Diag_Resp_TPMS_RX_BOD         47u
#define CANIF_RXPDU_CANIF_Diag_Resp_BMS_RX_EPT         48u
#define CANIF_RXPDU_CANIF_Diag_Resp_IPUDCC_RX_EPT         49u
#define CANIF_RXPDU_CANIF_Diag_Resp_MCU_RX_EPT         50u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CCU_OBD         51u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_MCU_OBD         52u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_BMS_OBD         53u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_IPUDCC_OBD         54u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PTC_OBD         55u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SCS_OBD         56u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CCP_OBD         57u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_AVAS_OBD         58u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESCL_OBD         59u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ACCM_OBD         60u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_TPMS_OBD         61u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CDCICU_OBD         62u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESC_OBD         63u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EHB_OBD         64u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EPS_OBD         65u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PP_OBD         66u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FCM_OBD         67u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRL_OBD         68u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRR_OBD         69u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SRS_OBD         70u
#define CANIF_RXPDU_CANIF_RX_Diag_FuncReq_OBD         71u
#define CANIF_RXPDU_CANIF_RX_Diag_FuncReq_BAC         72u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ACCM_BAC         73u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_AVAS_BAC         74u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_BMS_BAC         75u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CCP_BAC         76u
#define CANIF_RXPDU_CANIF_RX_Diag_Resp_CDCICU_BAC         77u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRL_BAC         78u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_CRRR_BAC         79u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EHB_BAC         80u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_EPS_BAC         81u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESC_BAC         82u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_ESCL_BAC         83u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_FCM_BAC         84u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_IPUDCC_BAC         85u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_MCU_BAC         86u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PP_BAC         87u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_PTC_BAC         88u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SCS_BAC         89u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_SRS_BAC         90u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_TPMS_BAC         91u
#define CANIF_RXPDU_CANIF_RX_Diag_PhyReq_BAC         92u
#define CANIF_RXPDU_HU_A_BAC         93u
#define CANIF_RXPDU_HU_C_BAC         94u
#define CANIF_RXPDU_ICU_2_Odo_BAC         95u
#define CANIF_RXPDU_ICU_Info_BAC         96u
#define CANIF_RXPDU_TBOX_BJS_Time_BAC         97u
#define CANIF_RXPDU_ESC_WheelPulseTime_CHA         98u
#define CANIF_RXPDU_SRS_2_YRSOriginalSts_CHA         99u
#define CANIF_RXPDU_SRS_3_YRSActualSts_CHA         100u
#define CANIF_RXPDU_EPS_3_LatDrvAndEPSSts_CHA         101u
#define CANIF_RXPDU_EPS_2_StrWhlAng_CHA         102u
#define CANIF_RXPDU_SRS_1_Status_CHA         103u
#define CANIF_RXPDU_EPS_1_Status_CHA         104u
#define CANIF_RXPDU_PP_InformAndStatus_CHA         105u
#define CANIF_RXPDU_CRRR_A_CHA         106u
#define CANIF_RXPDU_CANIF_RX_FCM_B_CHA_CANFD3_CHA_CAN5         107u
#define CANIF_RXPDU_CANIF_RX_FCM_A_CHA_CANFD3_CHA_CAN5         108u
#define CANIF_RXPDU_EHB_B_CHA         109u
#define CANIF_RXPDU_ESC_A_CHA         110u
#define CANIF_RXPDU_ESC_7_FuncStatus_CHA         111u
#define CANIF_RXPDU_CANIF_RX_EHB_A_CHA_CANFD3_CHA_CAN5         112u
#define CANIF_RXPDU_FCM_23_Obj0109_CHA         113u
#define CANIF_RXPDU_CANIF_RX_FCM_25_Line123_CHA_CANFD3_CHA_CAN5         114u
#define CANIF_RXPDU_CRRR_10_Posn_CHA         115u
#define CANIF_RXPDU_CANIF_RX_CRRR_OBJ12_CHA_CANFD3_CHA_CAN5         116u
#define CANIF_RXPDU_CANIF_RX_CRRL_OBJ12_CHA_CANFD3_CHA_CAN5         117u
#define CANIF_RXPDU_CANIF_Diag_Resp_CRRL_RX_CHA         118u
#define CANIF_RXPDU_CANIF_Diag_Resp_CRRR_RX_CHA         119u
#define CANIF_RXPDU_CANIF_Diag_Resp_EHB_RX_CHA         120u
#define CANIF_RXPDU_CANIF_Diag_Resp_EPS_RX_CHA         121u
#define CANIF_RXPDU_CANIF_Diag_Resp_ESC_RX_CHA         122u
#define CANIF_RXPDU_CANIF_Diag_Resp_FCM_RX_CHA         123u
#define CANIF_RXPDU_CANIF_Diag_Resp_PP_RX_CHA         124u
#define CANIF_RXPDU_CANIF_Diag_Resp_SRS_RX_CHA         125u
#define CANIF_RXPDU_FCM_24_Obj1018_CHA         126u
#define CANIF_RXPDU_CANIF_RX_BMS_HMI_EPT_CANFD6_EPT_CAN2         127u
#define CANIF_RXPDU_CANIF_RX_HU_B_BAC_CANFD8_BAC_CAN1         128u
#define CANIF_RXPDU_CANIF_RX_BMS_BEM_EPT_CANFD6_EPT_CAN2         129u
#define CANIF_RXPDU_CANIF_RX_BMS_CEM_EPT_CANFD6_EPT_CAN2         130u
#define CANIF_RXPDU_CANIF_RX_BMS_BST_EPT_CANFD6_EPT_CAN2         131u
#define CANIF_RXPDU_CANIF_RX_BMS_CST_EPT_CANFD6_EPT_CAN2         132u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */
#define CANIF_TXPDU_NUMBER              189u
#define CANIF_DYNAMIC_TXPDU_NUMBER      0u

/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define CANIF_TXPDU_INCA_CRO_XCP         0u
#define CANIF_TXPDU_CanNm_CAN5_CANFD3_TX         1u
#define CANIF_TXPDU_CanNm_CAN2_CANFD6_TX         2u
#define CANIF_TXPDU_CanNm_CAN1_CANFD8_TX         3u
#define CANIF_TXPDU_CanNm_CAN6_CANFD5_TX         4u
#define CANIF_TXPDU_ICU_Info_CHA         5u
#define CANIF_TXPDU_SCS_RiSwitchSts_CHA         6u
#define CANIF_TXPDU_CANIF_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5         7u
#define CANIF_TXPDU_CCP_PanelStatus_CHA         8u
#define CANIF_TXPDU_CANIF_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5         9u
#define CANIF_TXPDU_CANIF_TX_HU_A_CHA_CANFD3_CHA_CAN5         10u
#define CANIF_TXPDU_CANIF_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5         11u
#define CANIF_TXPDU_SCS_LeSwitchSts_CHA         12u
#define CANIF_TXPDU_ICU_2_Odo_CHA         13u
#define CANIF_TXPDU_AC_3_State_CHA         14u
#define CANIF_TXPDU_TPMS_Info_CHA         15u
#define CANIF_TXPDU_TBOX_BJS_Time_CHA         16u
#define CANIF_TXPDU_ESC_7_FuncStatus_BOD         17u
#define CANIF_TXPDU_EHB_A_BOD         18u
#define CANIF_TXPDU_CANIF_TX_CCU_VehInfo_BOD_CANFD4_BOD_CAN4         19u
#define CANIF_TXPDU_AC_ACStatuts_BOD         20u
#define CANIF_TXPDU_AC_COMP_BOD         21u
#define CANIF_TXPDU_AC_1_Command_BOD         22u
#define CANIF_TXPDU_HVCH_Command_BOD         23u
#define CANIF_TXPDU_ICU_2_Odo_BOD         24u
#define CANIF_TXPDU_AC_3_State_BOD         25u
#define CANIF_TXPDU_AC_2_State_BOD         26u
#define CANIF_TXPDU_CANIF_TX_AC_8_status_BOD_CANFD4_BOD_CAN4         27u
#define CANIF_TXPDU_HU_C_BOD         28u
#define CANIF_TXPDU_BCM_ESCLCommand_BOD         29u
#define CANIF_TXPDU_TBOX_BJS_Time_BOD         30u
#define CANIF_TXPDU_TMS_LINTestData1_BOD         31u
#define CANIF_TXPDU_TMS_LINTestData2_BOD         32u
#define CANIF_TXPDU_TMS_LINTestData3_BOD         33u
#define CANIF_TXPDU_VCU_3_OprtCmd_EPT         34u
#define CANIF_TXPDU_VCU_4_ChrgCmd_EPT         35u
#define CANIF_TXPDU_VCU_B_AcclPedal_EPT         36u
#define CANIF_TXPDU_VCU_1_InvCmd_EPT         37u
#define CANIF_TXPDU_VCU_0_Value_EPT         38u
#define CANIF_TXPDU_VCU_C_OprtCmd_EPT         39u
#define CANIF_TXPDU_ESC_7_FuncStatus_EPT         40u
#define CANIF_TXPDU_SRS_1_Status_EPT         41u
#define CANIF_TXPDU_CCU_VehInfo_EPT         42u
#define CANIF_TXPDU_ICU_2_Odo_EPT         43u
#define CANIF_TXPDU_BCM_IMMOAuthResp1_EPT         44u
#define CANIF_TXPDU_TBOX_BJS_Time_EPT         45u
#define CANIF_TXPDU_BMS_1_MainState_BAC         46u
#define CANIF_TXPDU_ESC_7_FuncStatus_BAC         47u
#define CANIF_TXPDU_BMS_2_BatState_BAC         48u
#define CANIF_TXPDU_EPS_1_Status_BAC         49u
#define CANIF_TXPDU_BMS_10_DC_ChargeStates_BAC         50u
#define CANIF_TXPDU_EHB_A_BAC         51u
#define CANIF_TXPDU_SCS_RiSwitchSts_BAC         52u
#define CANIF_TXPDU_SRS_1_Status_BAC         53u
#define CANIF_TXPDU_CRRR_A_BAC         54u
#define CANIF_TXPDU_AC_ACStatuts_BAC         55u
#define CANIF_TXPDU_SCS_LeSwitchSts_BAC         56u
#define CANIF_TXPDU_IPU_OBC_1_State_BAC         57u
#define CANIF_TXPDU_AC_3_State_BAC         58u
#define CANIF_TXPDU_BCM_HFSData_BAC         59u
#define CANIF_TXPDU_AVAS_State_BAC         60u
#define CANIF_TXPDU_IPU_OBC_4_state_BAC         61u
#define CANIF_TXPDU_TPMS_Info_BAC         62u
#define CANIF_TXPDU_BMS_A_GB_BAC         63u
#define CANIF_TXPDU_BMS_B_GB_BAC         64u
#define CANIF_TXPDU_BMS_C_GB_BAC         65u
#define CANIF_TXPDU_BMS_D_GB_BAC         66u
#define CANIF_TXPDU_CANIF_Diag_FuncReq_TX_CHA         67u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA         68u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA         69u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_EHB_TX_CHA         70u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_EPS_TX_CHA         71u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_ESC_TX_CHA         72u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_FCM_TX_CHA         73u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_PP_TX_CHA         74u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_SRS_TX_CHA         75u
#define CANIF_TXPDU_CANIF_Diag_FuncReq_TX_BOD         76u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD         77u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD         78u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD         79u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD         80u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD         81u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD         82u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD         83u
#define CANIF_TXPDU_CANIF_Diag_FuncReq_TX_EPT         84u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_BMS_TX_EPT         85u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT         86u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_MCU_TX_EPT         87u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_ACCM_OBD         88u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_AVAS_OBD         89u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_CCU_OBD         90u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_BMS_OBD         91u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_CCP_OBD         92u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_CDCICU_OBD         93u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_CRRL_OBD         94u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_CRRR_OBD         95u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_EHB_OBD         96u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_EPS_OBD         97u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_ESC_OBD         98u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_ESCL_OBD         99u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_FCM_OBD         100u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_IPUDCC_OBD         101u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_MCU_OBD         102u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_PP_OBD         103u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_PTC_OBD         104u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_SCS_OBD         105u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_SRS_OBD         106u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_TPMS_OBD         107u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_ACCM_BAC         108u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_AVAS_BAC         109u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_BMS_BAC         110u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_CCP_BAC         111u
#define CANIF_TXPDU_CANIF_TX_Diag_PhyReq_CDCICU_BAC         112u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_CRRL_BAC         113u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_CRRR_BAC         114u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_EHB_BAC         115u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_EPS_BAC         116u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_ESC_BAC         117u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_ESCL_BAC         118u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_FCM_BAC         119u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_IPUDCC_BAC         120u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_MCU_BAC         121u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_PP_BAC         122u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_PTC_BAC         123u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_SCS_BAC         124u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_SRS_BAC         125u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_TPMS_BAC         126u
#define CANIF_TXPDU_CANIF_TX_Diag_FuncReq_BAC         127u
#define CANIF_TXPDU_CANIF_Diag_FuncReq_TX_EPT_1         128u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_BMS_TX_EPT_1         129u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT_1         130u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_MCU_TX_EPT_1         131u
#define CANIF_TXPDU_CANIF_Diag_FuncReq_TX_CHA_1         132u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA_1         133u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA_1         134u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_EHB_TX_CHA_1         135u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_EPS_TX_CHA_1         136u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_ESC_TX_CHA_1         137u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_FCM_TX_CHA_1         138u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_PP_TX_CHA_1         139u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_SRS_TX_CHA_1         140u
#define CANIF_TXPDU_CANIF_Diag_FuncReq_TX_BOD_1         141u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD_1         142u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD_1         143u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD_1         144u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD_1         145u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD_1         146u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD_1         147u
#define CANIF_TXPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD_1         148u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_BAC         149u
#define CANIF_TXPDU_FCM_A_CHA_2_BAC         150u
#define CANIF_TXPDU_FCM_23_Obj0109_2_BAC         151u
#define CANIF_TXPDU_FCM_24_Obj1018_CHA_2_BAC         152u
#define CANIF_TXPDU_FCM_25_Line123_CHA_2_BAC         153u
#define CANIF_TXPDU_PP_InformAndStatus_CHA_2_BAC         154u
#define CANIF_TXPDU_CANIF_TX_Diag_Resp_CCU_OBD_2A         155u
#define CANIF_TXPDU_CANIF_TX_INV_4_Value_BAC_CANFD8_BAC_CAN1         156u
#define CANIF_TXPDU_CANIF_TX_BMS_HMI_BAC_CANFD8_BAC_CAN1         157u
#define CANIF_TXPDU_CANIF_TX_HU_C_EPT_CANFD6_EPT_CAN2         158u
#define CANIF_TXPDU_CANIF_TX_VCU_10_Torque_BAC_CANFD8_BAC_CAN1         159u
#define CANIF_TXPDU_CANIF_TX_EPS_3_LatDrvAndEPSSts_BAC_CANFD8_BAC_CAN1         160u
#define CANIF_TXPDU_CANIF_TX_EPS_2_StrWhlAng_BAC_CANFD8_BAC_CAN1         161u
#define CANIF_TXPDU_CANIF_TX_VCU_DispInfo_BAC_CANFD8_BAC_CAN1         162u
#define CANIF_TXPDU_CANIF_TX_ESC_A_BAC_CANFD8_BAC_CAN1         163u
#define CANIF_TXPDU_CANIF_TX_EHB_B_BAC_CANFD8_BAC_CAN1         164u
#define CANIF_TXPDU_CANIF_TX_BMS_3_DC_ChargeState_BAC_CANFD8_BAC_CAN1         165u
#define CANIF_TXPDU_CANIF_TX_BMS_4_AC_ChargeState_BAC_CANFD8_BAC_CAN1         166u
#define CANIF_TXPDU_CANIF_TX_FCM_B_BAC_CANFD8_BAC_CAN1         167u
#define CANIF_TXPDU_CANIF_TX_CCU_VehInfo_BAC_CANFD8_BAC_CAN1         168u
#define CANIF_TXPDU_CANIF_TX_VCU_D_Status_BAC_CANFD8_BAC_CAN1         169u
#define CANIF_TXPDU_CANIF_TX_BMS_5_BatTemp_BAC_CANFD8_BAC_CAN1         170u
#define CANIF_TXPDU_CANIF_TX_BCM_B_Package_BAC_CANFD8_BAC_CAN1         171u
#define CANIF_TXPDU_CANIF_TX_BMS_6_DischrgRecup_BAC_CANFD8_BAC_CAN1         172u
#define CANIF_TXPDU_CANIF_TX_IPU_OBC_3_CP_CC_BAC_CANFD8_BAC_CAN1         173u
#define CANIF_TXPDU_CANIF_TX_BMS_7_CellVolt_BAC_CANFD8_BAC_CAN1         174u
#define CANIF_TXPDU_CANIF_TX_IPU_DCC_1_State_BAC_CANFD8_BAC_CAN1         175u
#define CANIF_TXPDU_CANIF_TX_BMS_9_BattInfo_BAC_CANFD8_BAC_CAN1         176u
#define CANIF_TXPDU_CANIF_TX_IPU_DCC_2_ChrgInValue_BAC_CANFD8_BAC_CAN1         177u
#define CANIF_TXPDU_CANIF_TX_BMS_BEM_BAC_CANFD8_BAC_CAN1         178u
#define CANIF_TXPDU_CANIF_TX_BMS_CEM_BAC_CANFD8_BAC_CAN1         179u
#define CANIF_TXPDU_CANIF_TX_BMS_BST_BAC_CANFD8_BAC_CAN1         180u
#define CANIF_TXPDU_CANIF_TX_BMS_CST_BAC_CANFD8_BAC_CAN1         181u
#define CANIF_TXPDU_CANIF_TX_IPU_OBC_2_Inlet_BAC_CANFD8_BAC_CAN1         182u
#define CANIF_TXPDU_CANIF_TX_CRRL_OBJ12_BAC_CANFD8_BAC_CAN1         183u
#define CANIF_TXPDU_CANIF_TX_CRRR_OBJ12_BAC_CANFD8_BAC_CAN1         184u
#define CANIF_TXPDU_CANIF_TX_VCU_B_AcclPedal_BAC_CANFD8_BAC_CAN1         185u
#define CANIF_TXPDU_CANIF_TX_INV_1_Value_BAC_CANFD8_BAC_CAN1         186u
#define CANIF_TXPDU_CANIF_TX_INV_2_Value_BAC_CANFD8_BAC_CAN1         187u
#define CANIF_TXPDU_CANIF_TX_VCU_10_Torque_CHA_CANFD3_CHA_CAN5         188u
/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */

#define CANIF_HRH_NUMBER           94u
#define CANIF_HOH0_HRH_0           0u
#define CANIF_HOH0_HRH_1           1u
#define CANIF_HOH0_HRH_2           2u
#define CANIF_HOH0_HRH_3           3u
#define CANIF_HOH0_HRH_4           4u
#define CANIF_HOH0_HRH_5           5u
#define CANIF_HOH0_HRH_6           6u
#define CANIF_HOH0_HRH_7           7u
#define CANIF_HOH0_HRH_8           8u
#define CANIF_HOH0_HRH_9           9u
#define CANIF_HOH0_HRH_10           10u
#define CANIF_HOH0_HRH_11           11u
#define CANIF_HOH0_HRH_12           12u
#define CANIF_HOH0_HRH_13           13u
#define CANIF_HOH0_HRH_14           14u
#define CANIF_HOH0_HRH_15           15u
#define CANIF_HOH0_HRH_16           16u
#define CANIF_HOH0_HRH_17           17u
#define CANIF_HOH0_HRH_18           18u
#define CANIF_HOH0_HRH_19           19u
#define CANIF_HOH0_HRH_20           20u
#define CANIF_HOH0_HRH_21           21u
#define CANIF_HOH0_HRH_22           22u
#define CANIF_HOH0_HRH_23           23u
#define CANIF_HOH0_HRH_24           24u
#define CANIF_HOH0_HRH_25           25u
#define CANIF_HOH0_HRH_26           26u
#define CANIF_HOH0_HRH_27           27u
#define CANIF_HOH0_HRH_28           28u
#define CANIF_HOH0_HRH_29           29u
#define CANIF_HOH0_HRH_30           30u
#define CANIF_HOH0_HRH_31           31u
#define CANIF_HOH0_HRH_32           32u
#define CANIF_HOH0_HRH_33           33u
#define CANIF_HOH0_HRH_34           34u
#define CANIF_HOH0_HRH_35           35u
#define CANIF_HOH0_HRH_36           36u
#define CANIF_HOH0_HRH_37           37u
#define CANIF_HOH0_HRH_38           38u
#define CANIF_HOH0_HRH_39           39u
#define CANIF_HOH0_HRH_40           40u
#define CANIF_HOH0_HRH_41           41u
#define CANIF_HOH0_HRH_42           42u
#define CANIF_HOH0_HRH_43           43u
#define CANIF_HOH0_HRH_44           44u
#define CANIF_HOH0_HRH_45           45u
#define CANIF_HOH0_HRH_46           46u
#define CANIF_HOH0_HRH_47           47u
#define CANIF_HOH0_HRH_48           48u
#define CANIF_HOH0_HRH_49           49u
#define CANIF_HOH0_HRH_50           50u
#define CANIF_HOH0_HRH_51           51u
#define CANIF_HOH0_HRH_52           52u
#define CANIF_HOH0_HRH_53           53u
#define CANIF_HOH0_HRH_54           54u
#define CANIF_HOH0_HRH_55           55u
#define CANIF_HOH0_HRH_56           56u
#define CANIF_HOH0_HRH_57           57u
#define CANIF_HOH0_HRH_58           58u
#define CANIF_HOH0_HRH_59           59u
#define CANIF_HOH0_HRH_60           60u
#define CANIF_HOH0_HRH_61           61u
#define CANIF_HOH0_HRH_62           62u
#define CANIF_HOH0_HRH_63           63u
#define CANIF_HOH0_HRH_64           64u
#define CANIF_HOH0_HRH_65           65u
#define CANIF_HOH0_HRH_66           66u
#define CANIF_HOH0_HRH_67           67u
#define CANIF_HOH0_HRH_68           68u
#define CANIF_HOH0_HRH_69           69u
#define CANIF_HOH0_HRH_70           70u
#define CANIF_HOH0_HRH_71           71u
#define CANIF_HOH0_HRH_72           72u
#define CANIF_HOH0_HRH_73           73u
#define CANIF_HOH0_HRH_74           74u
#define CANIF_HOH0_HRH_75           75u
#define CANIF_HOH0_HRH_76           76u
#define CANIF_HOH0_HRH_77           77u
#define CANIF_HOH0_HRH_78           78u
#define CANIF_HOH0_HRH_79           79u
#define CANIF_HOH0_HRH_80           80u
#define CANIF_HOH0_HRH_81           81u
#define CANIF_HOH0_HRH_82           82u
#define CANIF_HOH0_HRH_83           83u
#define CANIF_HOH0_HRH_84           84u
#define CANIF_HOH0_HRH_85           85u
#define CANIF_HOH0_HRH_86           86u
#define CANIF_HOH0_HRH_87           87u
#define CANIF_HOH0_HRH_88           88u
#define CANIF_HOH0_HRH_89           89u
#define CANIF_HOH0_HRH_90           90u
#define CANIF_HOH0_HRH_91           91u
#define CANIF_HOH0_HRH_92           92u
#define CANIF_HOH0_HRH_93           93u

#define CANIF_HTH_NUMBER           7u
#define CANIF_HOH0_HTH_0           0u
#define CANIF_HOH0_HTH_1           1u
#define CANIF_HOH0_HTH_2           2u
#define CANIF_HOH0_HTH_3           3u
#define CANIF_HOH0_HTH_4           4u
#define CANIF_HOH0_HTH_5           5u
#define CANIF_HOH0_HTH_6           6u

#define CANIF_TXBUFFER_NUMBER          7u
#define CANIF_RXBUFFER_NUMBER          0u

#define CANIF_RXNOTIFYSTATUS_BUFFER    0u
#define CANIF_TXNOTIFYSTATUS_BUFFER    0u

#define CANIF_CANDRIVER_NUMBER      1u
#define CANIF_CAN    0u
#define CANIF_CANCONTROLLER_NUMBER      6u
#define CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD3_CHA    0u
#define CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD4_BOD    1u
#define CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD5_XCP    2u
#define CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD6_EPT    3u
#define CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD7_OBD    4u
#define CANIF_CANDRV_0_CANIF_CTR_DRV_CANFD8_BAC    5u

#define CANIF_TRCVDRIVER_NUMBER      0u
#define CANIF_TRCV_NUMBER      0u

#endif
/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/
