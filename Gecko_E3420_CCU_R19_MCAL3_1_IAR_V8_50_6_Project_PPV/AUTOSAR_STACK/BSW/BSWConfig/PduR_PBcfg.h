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
**  FILENAME    : PduR_PBcfg.h                                                **
**                                                                            **
**  Created on  : 2024/09/17 09:42:28                                         **
**  Author      : zhengfei.li                                                 **
**  Vendor      :                                                             **
**  DESCRIPTION : Configuration parameter of PDUR                             **
**                                                                            **
**  SPECIFICATION(S) :   AUTOSAR classic Platform 4.2.2                       **
**                                                                            **
*******************************************************************************/
#ifndef  PDUR_PBCFG_H
#define  PDUR_PBCFG_H
/*******************************************************************************
**                      Revision Control History                              **
*******************************************************************************/
/*******************************************************************************
**                      Includes                                              **
*******************************************************************************/
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define PDUR_PBCFG_H_AR_MAJOR_VERSION  4u
#define PDUR_PBCFG_H_AR_MINOR_VERSION  2u
#define PDUR_PBCFG_H_AR_PATCH_VERSION  2u
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
#define PDUR_SRC_PDU_SUM           207u

/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define PDUR_SRCPDU_COM_INCA_CRO_XCP          0u
#define PDUR_SRCPDU_TMSR_DTO_XCP          1u
#define PDUR_SRCPDU_Com_CAN5_CANFD3_user          2u
#define PDUR_SRCPDU_Com_CAN2_CANFD6_user          3u
#define PDUR_SRCPDU_Com_CAN1_CANFD8_user          4u
#define PDUR_SRCPDU_COM_VCU_10_Torque_CHA          5u
#define PDUR_SRCPDU_COM_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5          6u
#define PDUR_SRCPDU_CANIF_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5          7u
#define PDUR_SRCPDU_COM_AC_3_State_CHA          8u
#define PDUR_SRCPDU_CANIF_RX_FCM_B_CHA_CANFD3_CHA_CAN5          9u
#define PDUR_SRCPDU_CANIF_RX_FCM_A_CHA_CANFD3_CHA_CAN5          10u
#define PDUR_SRCPDU_FCM_23_Obj0109_CHA          11u
#define PDUR_SRCPDU_FCM_24_Obj1018_CHA          12u
#define PDUR_SRCPDU_CANIF_RX_FCM_25_Line123_CHA_CANFD3_CHA_CAN5          13u
#define PDUR_SRCPDU_ESC_WheelPulseTime_CHA          14u
#define PDUR_SRCPDU_ESC_A_CHA          15u
#define PDUR_SRCPDU_ESC_7_FuncStatus_CHA          16u
#define PDUR_SRCPDU_EHB_B_CHA          17u
#define PDUR_SRCPDU_CANIF_RX_EHB_A_CHA_CANFD3_CHA_CAN5          18u
#define PDUR_SRCPDU_SRS_2_YRSOriginalSts_CHA          19u
#define PDUR_SRCPDU_SRS_3_YRSActualSts_CHA          20u
#define PDUR_SRCPDU_SRS_1_Status_CHA          21u
#define PDUR_SRCPDU_EPS_3_LatDrvAndEPSSts_CHA          22u
#define PDUR_SRCPDU_EPS_2_StrWhlAng_CHA          23u
#define PDUR_SRCPDU_EPS_1_Status_CHA          24u
#define PDUR_SRCPDU_PP_InformAndStatus_CHA          25u
#define PDUR_SRCPDU_CRRR_A_CHA          26u
#define PDUR_SRCPDU_CRRR_10_Posn_CHA          27u
#define PDUR_SRCPDU_COM_TX_CCU_VehInfo_BOD_CANFD4_BOD_CAN4          28u
#define PDUR_SRCPDU_COM_AC_ACStatuts_BOD          29u
#define PDUR_SRCPDU_COM_AC_COMP_BOD          30u
#define PDUR_SRCPDU_COM_AC_1_Command_BOD          31u
#define PDUR_SRCPDU_COM_HVCH_Command_BOD          32u
#define PDUR_SRCPDU_COM_AC_3_State_BOD          33u
#define PDUR_SRCPDU_COM_AC_2_State_BOD          34u
#define PDUR_SRCPDU_COM_TX_AC_8_status_BOD_CANFD4_BOD_CAN4          35u
#define PDUR_SRCPDU_COM_BCM_ESCLCommand_BOD          36u
#define PDUR_SRCPDU_COM_TMS_LINTestData1_BOD          37u
#define PDUR_SRCPDU_COM_TMS_LINTestData2_BOD          38u
#define PDUR_SRCPDU_COM_TMS_LINTestData3_BOD          39u
#define PDUR_SRCPDU_CCP_PanelStatus_BOD          40u
#define PDUR_SRCPDU_SCS_RiSwitchSts_BOD          41u
#define PDUR_SRCPDU_SCS_LeSwitchSts_BOD          42u
#define PDUR_SRCPDU_TPMS_Info_BOD          43u
#define PDUR_SRCPDU_ESCL_ESCLStatus_BOD          44u
#define PDUR_SRCPDU_AVAS_State_BOD          45u
#define PDUR_SRCPDU_COMP_AC_BOD          46u
#define PDUR_SRCPDU_ACCM_Version_BOD          47u
#define PDUR_SRCPDU_HVCH_Status1_BOD          48u
#define PDUR_SRCPDU_HVCH_Status2_BOD          49u
#define PDUR_SRCPDU_COM_VCU_3_OprtCmd_EPT          50u
#define PDUR_SRCPDU_COM_VCU_4_ChrgCmd_EPT          51u
#define PDUR_SRCPDU_COM_VCU_B_AcclPedal_EPT          52u
#define PDUR_SRCPDU_COM_VCU_1_InvCmd_EPT          53u
#define PDUR_SRCPDU_COM_VCU_0_Value_EPT          54u
#define PDUR_SRCPDU_COM_VCU_C_OprtCmd_EPT          55u
#define PDUR_SRCPDU_COM_CCU_VehInfo_EPT          56u
#define PDUR_SRCPDU_COM_BCM_IMMOAuthResp1_EPT          57u
#define PDUR_SRCPDU_BMS_1_MainState_EPT          58u
#define PDUR_SRCPDU_BMS_2_BatState_EPT          59u
#define PDUR_SRCPDU_BMS_3_DC_ChargeState_EPT          60u
#define PDUR_SRCPDU_BMS_4_AC_ChargeState_EPT          61u
#define PDUR_SRCPDU_BMS_10_DC_ChargeStates_EPT          62u
#define PDUR_SRCPDU_BMS_5_BatTemp_EPT          63u
#define PDUR_SRCPDU_BMS_6_DischrgRecup_EPT          64u
#define PDUR_SRCPDU_BMS_7_CellVolt_EPT          65u
#define PDUR_SRCPDU_BMS_8_TempVoltLimit_EPT          66u
#define PDUR_SRCPDU_BMS_9_BattInfo_EPT          67u
#define PDUR_SRCPDU_BMS_A_GB_EPT          68u
#define PDUR_SRCPDU_BMS_B_GB_EPT          69u
#define PDUR_SRCPDU_BMS_C_GB_EPT          70u
#define PDUR_SRCPDU_BMS_D_GB_EPT          71u
#define PDUR_SRCPDU_IPU_OBC_3_CP_CC_EPT          72u
#define PDUR_SRCPDU_IPU_DCC_1_State_EPT          73u
#define PDUR_SRCPDU_IPU_OBC_1_State_EPT          74u
#define PDUR_SRCPDU_IPU_DCC_2_ChrgInValue_EPT          75u
#define PDUR_SRCPDU_IPU_OBC_2_Inlet_EPT          76u
#define PDUR_SRCPDU_IPU_OBC_4_state_EPT          77u
#define PDUR_SRCPDU_INV_1_Value_EPT          78u
#define PDUR_SRCPDU_INV_2_Value_EPT          79u
#define PDUR_SRCPDU_INV_3_Value_EPT          80u
#define PDUR_SRCPDU_INV_4_Value_EPT          81u
#define PDUR_SRCPDU_INV_5_Values_EPT          82u
#define PDUR_SRCPDU_INV_IMMO_Req_EPT          83u
#define PDUR_SRCPDU_COM_VCU_DispInfo_BAC          84u
#define PDUR_SRCPDU_COM_CCU_VehInfo_BAC          85u
#define PDUR_SRCPDU_COM_AC_ACStatuts_BAC          86u
#define PDUR_SRCPDU_COM_BCM_B_Package_BAC          87u
#define PDUR_SRCPDU_COM_AC_3_State_BAC          88u
#define PDUR_SRCPDU_COM_BCM_HFSData_BAC          89u
#define PDUR_SRCPDU_ICU_Info_BAC          90u
#define PDUR_SRCPDU_HU_B_BAC          91u
#define PDUR_SRCPDU_HU_A_BAC          92u
#define PDUR_SRCPDU_ICU_2_Odo_BAC          93u
#define PDUR_SRCPDU_HU_C_BAC          94u
#define PDUR_SRCPDU_TBOX_BJS_Time_BAC          95u
#define PDUR_SRCPDU_CANTP_RX_Diag_PhyReq_CCU_OBD          96u
#define PDUR_SRCPDU_CANTP_RX_Diag_FuncReq_OBD          97u
#define PDUR_SRCPDU_DCM_TX_Diag_Resp_CCU_OBD          98u
#define PDUR_SRCPDU_CANIF_Diag_Resp_MCU_RX_EPT          99u
#define PDUR_SRCPDU_CANIF_Diag_Resp_BMS_RX_EPT          100u
#define PDUR_SRCPDU_CANIF_Diag_Resp_IPUDCC_RX_EPT          101u
#define PDUR_SRCPDU_CANIF_Diag_Resp_ESC_RX_CHA          102u
#define PDUR_SRCPDU_CANIF_Diag_Resp_EHB_RX_CHA          103u
#define PDUR_SRCPDU_CANIF_Diag_Resp_EPS_RX_CHA          104u
#define PDUR_SRCPDU_CANIF_Diag_Resp_PP_RX_CHA          105u
#define PDUR_SRCPDU_CANIF_Diag_Resp_FCM_RX_CHA          106u
#define PDUR_SRCPDU_CANIF_Diag_Resp_CRRL_RX_CHA          107u
#define PDUR_SRCPDU_CANIF_Diag_Resp_CRRR_RX_CHA          108u
#define PDUR_SRCPDU_CANIF_Diag_Resp_SRS_RX_CHA          109u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CDCICU_OBD          110u
#define PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_OBD          111u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PTC_OBD          112u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SCS_OBD          113u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CCP_OBD          114u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_AVAS_OBD          115u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESCL_OBD          116u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ACCM_OBD          117u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_TPMS_OBD          118u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESC_OBD          119u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EHB_OBD          120u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EPS_OBD          121u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PP_OBD          122u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FCM_OBD          123u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRL_OBD          124u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRR_OBD          125u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SRS_OBD          126u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_MCU_OBD          127u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_BMS_OBD          128u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_IPUDCC_OBD          129u
#define PDUR_SRCPDU_CANIF_Diag_Resp_PTC_RX_BOD          130u
#define PDUR_SRCPDU_CANIF_Diag_Resp_SCS_RX_BOD          131u
#define PDUR_SRCPDU_CANIF_Diag_Resp_CCP_RX_BOD          132u
#define PDUR_SRCPDU_CANIF_Diag_Resp_AVAS_RX_BOD          133u
#define PDUR_SRCPDU_CANIF_Diag_Resp_ESCL_RX_BOD          134u
#define PDUR_SRCPDU_CANIF_Diag_Resp_ACCM_RX_BOD          135u
#define PDUR_SRCPDU_CANIF_Diag_Resp_TPMS_RX_BOD          136u
#define PDUR_SRCPDU_CANIF_RX_Diag_Resp_CDCICU_BAC          137u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_MCU_BAC          138u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_BMS_BAC          139u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_IPUDCC_BAC          140u
#define PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_BAC          141u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESC_BAC          142u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EHB_BAC          143u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EPS_BAC          144u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PP_BAC          145u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FCM_BAC          146u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRL_BAC          147u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRR_BAC          148u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SRS_BAC          149u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PTC_BAC          150u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SCS_BAC          151u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CCP_BAC          152u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_AVAS_BAC          153u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESCL_BAC          154u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ACCM_BAC          155u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_TPMS_BAC          156u
#define PDUR_SRCPDU_Com_HP_EXV_Cmd_LIN1          157u
#define PDUR_SRCPDU_HP_EXV__Rsp_LIN1          158u
#define PDUR_SRCPDU_Com_BAT_EXV_Cmd_LIN1          159u
#define PDUR_SRCPDU_BAT_EXV_Rsp_LIN1          160u
#define PDUR_SRCPDU_Com_AC_EXV_Cmd_LIN1          161u
#define PDUR_SRCPDU_AC_EXV_Rsp_LIN1          162u
#define PDUR_SRCPDU_Com_MCV_Cmd_LIN1          163u
#define PDUR_SRCPDU_MCV_Sts_LIN1          164u
#define PDUR_SRCPDU_Com_BCV_Cmd_LIN1          165u
#define PDUR_SRCPDU_BCV_Sts_LIN1          166u
#define PDUR_SRCPDU_Com_PMP_Cmd_LIN1          167u
#define PDUR_SRCPDU_MotPMP_Sts_LIN1          168u
#define PDUR_SRCPDU_BatPMP_Sts_LIN1          169u
#define PDUR_SRCPDU_AcPMP_Sts_LIN1          170u
#define PDUR_SRCPDU_HP_EXV_Version_LIN1          171u
#define PDUR_SRCPDU_Bat_EXV_Version_LIN1          172u
#define PDUR_SRCPDU_MCV_Version_LIN1          173u
#define PDUR_SRCPDU_BCV_Version_LIN1          174u
#define PDUR_SRCPDU_AcPMP_Version_LIN1          175u
#define PDUR_SRCPDU_Com_AC_EXV_Cmd_LIN2          176u
#define PDUR_SRCPDU_AC_EXV_Rsp_LIN2          177u
#define PDUR_SRCPDU_AcPMP_Sts_LIN2          178u
#define PDUR_SRCPDU_AcPMP_Version_LIN2          179u
#define PDUR_SRCPDU_Com_BAT_EXV_Cmd_LIN2          180u
#define PDUR_SRCPDU_BAT_EXV_Rsp_LIN2          181u
#define PDUR_SRCPDU_BatPMP_Sts_LIN2          182u
#define PDUR_SRCPDU_Bat_EXV_Version_LIN2          183u
#define PDUR_SRCPDU_Com_C3WV_Cmd_LIN2          184u
#define PDUR_SRCPDU_C3WV_Sts_LIN2          185u
#define PDUR_SRCPDU_Com_C5WV_Cmd_LIN2          186u
#define PDUR_SRCPDU_C5WV_Sts_LIN2          187u
#define PDUR_SRCPDU_Com_HP_EXV_Cmd_LIN2          188u
#define PDUR_SRCPDU_HP_EXV_Rsp_LIN2          189u
#define PDUR_SRCPDU_HP_EXV_Version_LIN2          190u
#define PDUR_SRCPDU_MotPMP_Sts_LIN2          191u
#define PDUR_SRCPDU_Com_PMP_Cmd_LIN2          192u
#define PDUR_SRCPDU_Com_CCU_FCLCommand_LIN3          193u
#define PDUR_SRCPDU_FCLL_Status_LIN3          194u
#define PDUR_SRCPDU_FCLR_Status_LIN3          195u
#define PDUR_SRCPDU_Frm_InterlockStatus_LIN3          196u
#define PDUR_SRCPDU_Frm_InterlockToVehicle_LIN3          197u
#define PDUR_SRCPDU_Com_Frm_VehicleToInterlock_LIN3          198u
#define PDUR_SRCPDU_CANTP_RX_Diag_PhyReq_BAC          199u
#define PDUR_SRCPDU_CANTP_RX_Diag_FuncReq_BAC          200u
#define PDUR_SRCPDU_DCM_TX_Diag_Resp_BAC          201u
#define PDUR_SRCPDU_Com_CAN6_CANFD5_user          202u
#define PDUR_SRCPDU_DCM_TX_Diag_Resp_CCU_OBD_2A          203u
#define PDUR_SRCPDU_COM_TX_VCU_B_AcclPedal_BAC_CANFD8_BAC_CAN1          204u
#define PDUR_SRCPDU_CANIF_RX_BMS_HMI_EPT_CANFD6_EPT_CAN2          205u
#define PDUR_SRCPDU_COM_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5          206u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define PDUR_DEST_PDU_SUM              274u

#define PDUR_DEST_GATEWAY_TP_PDU_SUM   0u

/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define PDUR_DESTPDU_INCA_CRO_XCP          0u
#define PDUR_DESTPDU_COM_TMSR_DTO_XCP          1u
#define PDUR_DESTPDU_CanNm_CAN5_CANFD3_user          2u
#define PDUR_DESTPDU_CanNm_CAN2_CANFD6_user          3u
#define PDUR_DESTPDU_CanNm_CAN1_CANFD8_user          4u
#define PDUR_DESTPDU_VCU_10_Torque_CHA          5u
#define PDUR_DESTPDU_CANIF_TX_CCU_VehInfo_CHA_CANFD3_CHA_CAN5          6u
#define PDUR_DESTPDU_COM_TX_VCU_D_Status_CHA_CANFD3_CHA_CAN5          7u
#define PDUR_DESTPDU_AC_3_State_CHA          8u
#define PDUR_DESTPDU_COM_RX_FCM_B_CHA_CANFD3_CHA_CAN5          9u
#define PDUR_DESTPDU_FCM_A_CHA_2_BAC          10u
#define PDUR_DESTPDU_COM_RX_FCM_A_CHA_CANFD3_CHA_CAN5          11u
#define PDUR_DESTPDU_FCM_23_Obj0109_2_BAC          12u
#define PDUR_DESTPDU_COM_FCM_23_Obj0109_CHA          13u
#define PDUR_DESTPDU_FCM_24_Obj1018_CHA_2_BAC          14u
#define PDUR_DESTPDU_COM_FCM_24_Obj1018_CHA          15u
#define PDUR_DESTPDU_FCM_25_Line123_CHA_2_BAC          16u
#define PDUR_DESTPDU_COM_RX_FCM_25_Line123_CHA_CANFD3_CHA_CAN5          17u
#define PDUR_DESTPDU_COM_ESC_WheelPulseTime_CHA          18u
#define PDUR_DESTPDU_COM_ESC_A_CHA          19u
#define PDUR_DESTPDU_ESC_7_FuncStatus_EPT          20u
#define PDUR_DESTPDU_ESC_7_FuncStatus_BOD          21u
#define PDUR_DESTPDU_ESC_7_FuncStatus_BAC          22u
#define PDUR_DESTPDU_COM_ESC_7_FuncStatus_CHA          23u
#define PDUR_DESTPDU_COM_EHB_B_CHA          24u
#define PDUR_DESTPDU_EHB_A_BOD          25u
#define PDUR_DESTPDU_EHB_A_BAC          26u
#define PDUR_DESTPDU_COM_RX_EHB_A_CHA_CANFD3_CHA_CAN5          27u
#define PDUR_DESTPDU_COM_SRS_2_YRSOriginalSts_CHA          28u
#define PDUR_DESTPDU_COM_SRS_3_YRSActualSts_CHA          29u
#define PDUR_DESTPDU_SRS_1_Status_EPT          30u
#define PDUR_DESTPDU_SRS_1_Status_BAC          31u
#define PDUR_DESTPDU_COM_SRS_1_Status_CHA          32u
#define PDUR_DESTPDU_COM_EPS_3_LatDrvAndEPSSts_CHA          33u
#define PDUR_DESTPDU_COM_EPS_2_StrWhlAng_CHA          34u
#define PDUR_DESTPDU_EPS_1_Status_BAC          35u
#define PDUR_DESTPDU_COM_EPS_1_Status_CHA          36u
#define PDUR_DESTPDU_PP_InformAndStatus_CHA_2_BAC          37u
#define PDUR_DESTPDU_COM_PP_InformAndStatus_CHA          38u
#define PDUR_DESTPDU_CRRR_A_BAC          39u
#define PDUR_DESTPDU_COM_CRRR_A_CHA          40u
#define PDUR_DESTPDU_COM_CRRR_10_Posn_CHA          41u
#define PDUR_DESTPDU_CANIF_TX_CCU_VehInfo_BOD_CANFD4_BOD_CAN4          42u
#define PDUR_DESTPDU_AC_ACStatuts_BOD          43u
#define PDUR_DESTPDU_AC_COMP_BOD          44u
#define PDUR_DESTPDU_AC_1_Command_BOD          45u
#define PDUR_DESTPDU_HVCH_Command_BOD          46u
#define PDUR_DESTPDU_AC_3_State_BOD          47u
#define PDUR_DESTPDU_AC_2_State_BOD          48u
#define PDUR_DESTPDU_CANIF_TX_AC_8_status_BOD_CANFD4_BOD_CAN4          49u
#define PDUR_DESTPDU_BCM_ESCLCommand_BOD          50u
#define PDUR_DESTPDU_TMS_LINTestData1_BOD          51u
#define PDUR_DESTPDU_TMS_LINTestData2_BOD          52u
#define PDUR_DESTPDU_TMS_LINTestData3_BOD          53u
#define PDUR_DESTPDU_COM_CCP_PanelStatus_BOD          54u
#define PDUR_DESTPDU_CCP_PanelStatus_CHA          55u
#define PDUR_DESTPDU_COM_SCS_RiSwitchSts_BOD          56u
#define PDUR_DESTPDU_SCS_RiSwitchSts_CHA          57u
#define PDUR_DESTPDU_SCS_RiSwitchSts_BAC          58u
#define PDUR_DESTPDU_COM_SCS_LeSwitchSts_BOD          59u
#define PDUR_DESTPDU_SCS_LeSwitchSts_CHA          60u
#define PDUR_DESTPDU_SCS_LeSwitchSts_BAC          61u
#define PDUR_DESTPDU_COM_TPMS_Info_BOD          62u
#define PDUR_DESTPDU_TPMS_Info_CHA          63u
#define PDUR_DESTPDU_TPMS_Info_BAC          64u
#define PDUR_DESTPDU_COM_ESCL_ESCLStatus_BOD          65u
#define PDUR_DESTPDU_COM_AVAS_State_BOD          66u
#define PDUR_DESTPDU_AVAS_State_BAC          67u
#define PDUR_DESTPDU_COM_COMP_AC_BOD          68u
#define PDUR_DESTPDU_COM_ACCM_Version_BOD          69u
#define PDUR_DESTPDU_COM_HVCH_Status1_BOD          70u
#define PDUR_DESTPDU_COM_HVCH_Status2_BOD          71u
#define PDUR_DESTPDU_VCU_3_OprtCmd_EPT          72u
#define PDUR_DESTPDU_VCU_4_ChrgCmd_EPT          73u
#define PDUR_DESTPDU_VCU_B_AcclPedal_EPT          74u
#define PDUR_DESTPDU_VCU_1_InvCmd_EPT          75u
#define PDUR_DESTPDU_VCU_0_Value_EPT          76u
#define PDUR_DESTPDU_VCU_C_OprtCmd_EPT          77u
#define PDUR_DESTPDU_CCU_VehInfo_EPT          78u
#define PDUR_DESTPDU_BCM_IMMOAuthResp1_EPT          79u
#define PDUR_DESTPDU_COM_BMS_1_MainState_EPT          80u
#define PDUR_DESTPDU_BMS_1_MainState_BAC          81u
#define PDUR_DESTPDU_COM_BMS_2_BatState_EPT          82u
#define PDUR_DESTPDU_BMS_2_BatState_BAC          83u
#define PDUR_DESTPDU_COM_BMS_3_DC_ChargeState_EPT          84u
#define PDUR_DESTPDU_COM_BMS_4_AC_ChargeState_EPT          85u
#define PDUR_DESTPDU_COM_BMS_10_DC_ChargeStates_EPT          86u
#define PDUR_DESTPDU_BMS_10_DC_ChargeStates_BAC          87u
#define PDUR_DESTPDU_COM_BMS_5_BatTemp_EPT          88u
#define PDUR_DESTPDU_COM_BMS_6_DischrgRecup_EPT          89u
#define PDUR_DESTPDU_COM_BMS_7_CellVolt_EPT          90u
#define PDUR_DESTPDU_COM_BMS_8_TempVoltLimit_EPT          91u
#define PDUR_DESTPDU_COM_BMS_9_BattInfo_EPT          92u
#define PDUR_DESTPDU_COM_BMS_A_GB_EPT          93u
#define PDUR_DESTPDU_BMS_A_GB_BAC          94u
#define PDUR_DESTPDU_COM_BMS_B_GB_EPT          95u
#define PDUR_DESTPDU_BMS_B_GB_BAC          96u
#define PDUR_DESTPDU_COM_BMS_C_GB_EPT          97u
#define PDUR_DESTPDU_BMS_C_GB_BAC          98u
#define PDUR_DESTPDU_COM_BMS_D_GB_EPT          99u
#define PDUR_DESTPDU_BMS_D_GB_BAC          100u
#define PDUR_DESTPDU_COM_IPU_OBC_3_CP_CC_EPT          101u
#define PDUR_DESTPDU_COM_IPU_DCC_1_State_EPT          102u
#define PDUR_DESTPDU_COM_IPU_OBC_1_State_EPT          103u
#define PDUR_DESTPDU_IPU_OBC_1_State_BAC          104u
#define PDUR_DESTPDU_COM_IPU_DCC_2_ChrgInValue_EPT          105u
#define PDUR_DESTPDU_COM_IPU_OBC_2_Inlet_EPT          106u
#define PDUR_DESTPDU_COM_IPU_OBC_4_state_EPT          107u
#define PDUR_DESTPDU_IPU_OBC_4_state_BAC          108u
#define PDUR_DESTPDU_COM_INV_1_Value_EPT          109u
#define PDUR_DESTPDU_INV_1_Value_BAC          110u
#define PDUR_DESTPDU_COM_INV_2_Value_EPT          111u
#define PDUR_DESTPDU_COM_INV_3_Value_EPT          112u
#define PDUR_DESTPDU_COM_INV_4_Value_EPT          113u
#define PDUR_DESTPDU_CANIF_TX_INV_4_Value_BAC_CANFD8_BAC_CAN1          114u
#define PDUR_DESTPDU_COM_INV_5_Values_EPT          115u
#define PDUR_DESTPDU_COM_INV_IMMO_Req_EPT          116u
#define PDUR_DESTPDU_VCU_DispInfo_BAC          117u
#define PDUR_DESTPDU_CCU_VehInfo_BAC          118u
#define PDUR_DESTPDU_AC_ACStatuts_BAC          119u
#define PDUR_DESTPDU_BCM_B_Package_BAC          120u
#define PDUR_DESTPDU_AC_3_State_BAC          121u
#define PDUR_DESTPDU_BCM_HFSData_BAC          122u
#define PDUR_DESTPDU_COM_ICU_Info_BAC          123u
#define PDUR_DESTPDU_ICU_Info_CHA          124u
#define PDUR_DESTPDU_COM_HU_B_BAC          125u
#define PDUR_DESTPDU_COM_HU_A_BAC          126u
#define PDUR_DESTPDU_CANIF_TX_HU_A_CHA_CANFD3_CHA_CAN5          127u
#define PDUR_DESTPDU_COM_ICU_2_Odo_BAC          128u
#define PDUR_DESTPDU_ICU_2_Odo_EPT          129u
#define PDUR_DESTPDU_ICU_2_Odo_CHA          130u
#define PDUR_DESTPDU_ICU_2_Odo_BOD          131u
#define PDUR_DESTPDU_COM_HU_C_BAC          132u
#define PDUR_DESTPDU_HU_C_BOD          133u
#define PDUR_DESTPDU_CANIF_TX_HU_C_EPT_CANFD6_EPT_CAN2          134u
#define PDUR_DESTPDU_COM_TBOX_BJS_Time_BAC          135u
#define PDUR_DESTPDU_TBOX_BJS_Time_EPT          136u
#define PDUR_DESTPDU_TBOX_BJS_Time_CHA          137u
#define PDUR_DESTPDU_TBOX_BJS_Time_BOD          138u
#define PDUR_DESTPDU_DCM_RX_Phy_Diag_PhyReq_CCU_OBD          139u
#define PDUR_DESTPDU_DCM_RX_Diag_FuncReq_OBD          140u
#define PDUR_DESTPDU_CANTP_TX_Diag_Resp_CCU_OBD          141u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_MCU_OBD          142u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_MCU_BAC          143u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_BMS_OBD          144u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_BMS_BAC          145u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_IPUDCC_OBD          146u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_IPUDCC_BAC          147u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESC_OBD          148u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESC_BAC          149u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_EHB_BAC          150u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_EHB_OBD          151u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_EPS_BAC          152u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_EPS_OBD          153u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_PP_BAC          154u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_PP_OBD          155u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_FCM_BAC          156u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_FCM_OBD          157u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRL_BAC          158u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRL_OBD          159u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRR_BAC          160u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRR_OBD          161u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_SRS_BAC          162u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_SRS_OBD          163u
#define PDUR_DESTPDU_CANIF_TX_Diag_PhyReq_CDCICU_BAC          164u
#define PDUR_DESTPDU_CANIF_TX_Diag_FuncReq_BAC          165u
#define PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_BOD          166u
#define PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_CHA          167u
#define PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_EPT          168u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD          169u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD          170u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD          171u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD          172u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD          173u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD          174u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD          175u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_ESC_TX_CHA          176u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_EHB_TX_CHA          177u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_EPS_TX_CHA          178u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_PP_TX_CHA          179u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_FCM_TX_CHA          180u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA          181u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA          182u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_SRS_TX_CHA          183u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_MCU_TX_EPT          184u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_BMS_TX_EPT          185u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT          186u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_PTC_BAC          187u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_PTC_OBD          188u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_SCS_BAC          189u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_SCS_OBD          190u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCP_BAC          191u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCP_OBD          192u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_AVAS_BAC          193u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_AVAS_OBD          194u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESCL_BAC          195u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESCL_OBD          196u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_ACCM_BAC          197u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_ACCM_OBD          198u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_TPMS_BAC          199u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_TPMS_OBD          200u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CDCICU_OBD          201u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_MCU_TX_EPT_1          202u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_BMS_TX_EPT_1          203u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT_1          204u
#define PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_EPT_1          205u
#define PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_CHA_1          206u
#define PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_BOD_1          207u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_ESC_TX_CHA_1          208u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_EHB_TX_CHA_1          209u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_EPS_TX_CHA_1          210u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_PP_TX_CHA_1          211u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_FCM_TX_CHA_1          212u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA_1          213u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA_1          214u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_SRS_TX_CHA_1          215u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD_1          216u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD_1          217u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD_1          218u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD_1          219u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD_1          220u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD_1          221u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD_1          222u
#define PDUR_DESTPDU_HP_EXV_Cmd_LIN1          223u
#define PDUR_DESTPDU_Com_HP_EXV__Rsp_LIN1          224u
#define PDUR_DESTPDU_BAT_EXV_Cmd_LIN1          225u
#define PDUR_DESTPDU_Com_BAT_EXV_Rsp_LIN1          226u
#define PDUR_DESTPDU_AC_EXV_Cmd_LIN1          227u
#define PDUR_DESTPDU_Com_AC_EXV_Rsp_LIN1          228u
#define PDUR_DESTPDU_MCV_Cmd_LIN1          229u
#define PDUR_DESTPDU_Com_MCV_Sts_LIN1          230u
#define PDUR_DESTPDU_BCV_Cmd_LIN1          231u
#define PDUR_DESTPDU_Com_BCV_Sts_LIN1          232u
#define PDUR_DESTPDU_PMP_Cmd_LIN1          233u
#define PDUR_DESTPDU_Com_MotPMP_Sts_LIN1          234u
#define PDUR_DESTPDU_Com_BatPMP_Sts_LIN1          235u
#define PDUR_DESTPDU_Com_AcPMP_Sts_LIN1          236u
#define PDUR_DESTPDU_Com_HP_EXV_Version_LIN1          237u
#define PDUR_DESTPDU_Com_Bat_EXV_Version_LIN1          238u
#define PDUR_DESTPDU_Com_MCV_Version_LIN1          239u
#define PDUR_DESTPDU_Com_BCV_Version_LIN1          240u
#define PDUR_DESTPDU_Com_AcPMP_Version_LIN1          241u
#define PDUR_DESTPDU_AC_EXV_Cmd_LIN2          242u
#define PDUR_DESTPDU_Com_AC_EXV_Rsp_LIN2          243u
#define PDUR_DESTPDU_Com_AcPMP_Sts_LIN2          244u
#define PDUR_DESTPDU_Com_AcPMP_Version_LIN2          245u
#define PDUR_DESTPDU_BAT_EXV_Cmd_LIN2          246u
#define PDUR_DESTPDU_Com_BAT_EXV_Rsp_LIN2          247u
#define PDUR_DESTPDU_Com_BatPMP_Sts_LIN2          248u
#define PDUR_DESTPDU_Com_Bat_EXV_Version_LIN2          249u
#define PDUR_DESTPDU_C3WV_Cmd_LIN2          250u
#define PDUR_DESTPDU_Com_C3WV_Sts_LIN2          251u
#define PDUR_DESTPDU_C5WV_Cmd_LIN2          252u
#define PDUR_DESTPDU_Com_C5WV_Sts_LIN2          253u
#define PDUR_DESTPDU_HP_EXV_Cmd_LIN2          254u
#define PDUR_DESTPDU_Com_HP_EXV_Rsp_LIN2          255u
#define PDUR_DESTPDU_Com_HP_EXV_Version_LIN2          256u
#define PDUR_DESTPDU_Com_MotPMP_Sts_LIN2          257u
#define PDUR_DESTPDU_PMP_Cmd_LIN2          258u
#define PDUR_DESTPDU_CCU_FCLCommand_LIN3          259u
#define PDUR_DESTPDU_Com_FCLL_Status_LIN3          260u
#define PDUR_DESTPDU_Com_FCLR_Status_LIN3          261u
#define PDUR_DESTPDU_Com_Frm_InterlockStatus_LIN3          262u
#define PDUR_DESTPDU_Com_Frm_InterlockToVehicle_LIN3          263u
#define PDUR_DESTPDU_Frm_VehicleToInterlock_LIN3          264u
#define PDUR_DESTPDU_DCM_RX_Phy_Diag_PhyReq_BAC          265u
#define PDUR_DESTPDU_DCM_RX_Diag_FuncReq_BAC          266u
#define PDUR_DESTPDU_CANTP_TX_Diag_Resp_BAC          267u
#define PDUR_DESTPDU_CanNm_CAN6_CANFD5_user          268u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCU_OBD_2A          269u
#define PDUR_DESTPDU_CANIF_TX_VCU_B_AcclPedal_BAC_CANFD8_BAC_CAN1          270u
#define PDUR_DESTPDU_COM_RX_BMS_HMI_EPT_CANFD6_EPT_CAN2          271u
#define PDUR_DESTPDU_CANIF_TX_BMS_HMI_BAC_CANFD8_BAC_CAN1          272u
#define PDUR_DESTPDU_CANIF_TX_BCM_B_Package_CHA_CANFD3_CHA_CAN5          273u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define PDUR_ROUTING_PATH_GROUP_SUM        2u

#define PduRRoutingPathGroup_DIAG          0u
#define PduRRoutingPathGroup_COMRouting          1u

#define PDUR_SRC_UP_MULTICAST_TX_IF_SUM              0u
#define PDUR_GATEWAY_DIRECT_BUFFER_PDU_SUM           0u

#define PDUR_DEFAULT_VALUE_LENGTH           0u
#define PDUR_DEFAULT_VALUE_PDU                  0u

#endif  /* end of PDUR_CFG_H */

/*******************************************************************************
**                      End of file                                           **
*******************************************************************************/

