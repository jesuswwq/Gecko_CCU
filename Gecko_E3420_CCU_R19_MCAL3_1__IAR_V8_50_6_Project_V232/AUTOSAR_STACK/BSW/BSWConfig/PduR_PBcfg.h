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
**  Created on  : 2024/06/17 10:36:47                                         **
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
#define PDUR_SRC_PDU_SUM           213u

/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define PDUR_SRCPDU_COM_INCA_CRO_XCP          0u
#define PDUR_SRCPDU_TMSR_DTO_XCP          1u
#define PDUR_SRCPDU_Com_CAN5_CANFD3_user          2u
#define PDUR_SRCPDU_Com_CAN2_CANFD6_user          3u
#define PDUR_SRCPDU_Com_CAN1_CANFD8_user          4u
#define PDUR_SRCPDU_COM_VCU_10_Torque_CHA          5u
#define PDUR_SRCPDU_COM_BCM_4_CruiseSw_PM_CHA          6u
#define PDUR_SRCPDU_COM_CCU_VehInfo_CHA          7u
#define PDUR_SRCPDU_COM_VCU_D_Status_CHA          8u
#define PDUR_SRCPDU_COM_BCM_B_Package_CHA          9u
#define PDUR_SRCPDU_COM_AC_3_State_CHA          10u
#define PDUR_SRCPDU_FCM_D_CHA          11u
#define PDUR_SRCPDU_FCM_B_CHA          12u
#define PDUR_SRCPDU_FCM_A_CHA          13u
#define PDUR_SRCPDU_FCM_23_Obj0109_CHA          14u
#define PDUR_SRCPDU_FCM_24_Obj1018_CHA          15u
#define PDUR_SRCPDU_FCM_25_Line123_CHA          16u
#define PDUR_SRCPDU_FCM_ObjTrackID_CHA          17u
#define PDUR_SRCPDU_ESC_WheelPulseTime_CHA          18u
#define PDUR_SRCPDU_ESC_A_CHA          19u
#define PDUR_SRCPDU_ESC_7_FuncStatus_CHA          20u
#define PDUR_SRCPDU_EHB_B_CHA          21u
#define PDUR_SRCPDU_EHB_A_CHA          22u
#define PDUR_SRCPDU_SRS_2_YRSOriginalSts_CHA          23u
#define PDUR_SRCPDU_SRS_3_YRSActualSts_CHA          24u
#define PDUR_SRCPDU_SRS_1_Status_CHA          25u
#define PDUR_SRCPDU_EPS_3_LatDrvAndEPSSts_CHA          26u
#define PDUR_SRCPDU_EPS_2_StrWhlAng_CHA          27u
#define PDUR_SRCPDU_EPS_1_Status_CHA          28u
#define PDUR_SRCPDU_PP_InformAndStatus_CHA          29u
#define PDUR_SRCPDU_CRRR_A_CHA          30u
#define PDUR_SRCPDU_CRRR_10_Posn_CHA          31u
#define PDUR_SRCPDU_COM_CCU_VehInfo_BOD          32u
#define PDUR_SRCPDU_COM_AC_ACStatuts_BOD          33u
#define PDUR_SRCPDU_COM_AC_COMP_BOD          34u
#define PDUR_SRCPDU_COM_VCU_7_DrvRange_BOD          35u
#define PDUR_SRCPDU_COM_AC_1_Command_BOD          36u
#define PDUR_SRCPDU_COM_HVCH_Command_BOD          37u
#define PDUR_SRCPDU_COM_AC_3_State_BOD          38u
#define PDUR_SRCPDU_COM_AC_2_State_BOD          39u
#define PDUR_SRCPDU_COM_AC_8_status_BOD          40u
#define PDUR_SRCPDU_COM_BCM_ESCLCommand_BOD          41u
#define PDUR_SRCPDU_COM_TMS_LINTestData1_BOD          42u
#define PDUR_SRCPDU_COM_TMS_LINTestData2_BOD          43u
#define PDUR_SRCPDU_COM_TMS_LINTestData3_BOD          44u
#define PDUR_SRCPDU_CCP_PanelStatus_BOD          45u
#define PDUR_SRCPDU_SCS_RiSwitchSts_BOD          46u
#define PDUR_SRCPDU_SCS_LeSwitchSts_BOD          47u
#define PDUR_SRCPDU_TPMS_Info_BOD          48u
#define PDUR_SRCPDU_ESCL_ESCLStatus_BOD          49u
#define PDUR_SRCPDU_AVAS_State_BOD          50u
#define PDUR_SRCPDU_COMP_AC_BOD          51u
#define PDUR_SRCPDU_ACCM_Version_BOD          52u
#define PDUR_SRCPDU_HVCH_Status1_BOD          53u
#define PDUR_SRCPDU_HVCH_Status2_BOD          54u
#define PDUR_SRCPDU_COM_VCU_3_OprtCmd_EPT          55u
#define PDUR_SRCPDU_COM_VCU_4_ChrgCmd_EPT          56u
#define PDUR_SRCPDU_COM_VCU_B_AcclPedal_EPT          57u
#define PDUR_SRCPDU_COM_VCU_1_InvCmd_EPT          58u
#define PDUR_SRCPDU_COM_VCU_0_Value_EPT          59u
#define PDUR_SRCPDU_COM_VCU_C_OprtCmd_EPT          60u
#define PDUR_SRCPDU_COM_CCU_VehInfo_EPT          61u
#define PDUR_SRCPDU_COM_BCM_IMMOAuthResp1_EPT          62u
#define PDUR_SRCPDU_BMS_1_MainState_EPT          63u
#define PDUR_SRCPDU_BMS_2_BatState_EPT          64u
#define PDUR_SRCPDU_BMS_3_DC_ChargeState_EPT          65u
#define PDUR_SRCPDU_BMS_4_AC_ChargeState_EPT          66u
#define PDUR_SRCPDU_BMS_10_DC_ChargeStates_EPT          67u
#define PDUR_SRCPDU_BMS_5_BatTemp_EPT          68u
#define PDUR_SRCPDU_BMS_6_DischrgRecup_EPT          69u
#define PDUR_SRCPDU_BMS_7_CellVolt_EPT          70u
#define PDUR_SRCPDU_BMS_8_TempVoltLimit_EPT          71u
#define PDUR_SRCPDU_BMS_9_BattInfo_EPT          72u
#define PDUR_SRCPDU_BMS_A_GB_EPT          73u
#define PDUR_SRCPDU_BMS_B_GB_EPT          74u
#define PDUR_SRCPDU_BMS_C_GB_EPT          75u
#define PDUR_SRCPDU_BMS_D_GB_EPT          76u
#define PDUR_SRCPDU_IPU_OBC_3_CP_CC_EPT          77u
#define PDUR_SRCPDU_IPU_DCC_1_State_EPT          78u
#define PDUR_SRCPDU_IPU_OBC_1_State_EPT          79u
#define PDUR_SRCPDU_IPU_DCC_2_ChrgInValue_EPT          80u
#define PDUR_SRCPDU_IPU_OBC_2_Inlet_EPT          81u
#define PDUR_SRCPDU_IPU_OBC_4_state_EPT          82u
#define PDUR_SRCPDU_INV_1_Value_EPT          83u
#define PDUR_SRCPDU_INV_2_Value_EPT          84u
#define PDUR_SRCPDU_INV_3_Value_EPT          85u
#define PDUR_SRCPDU_INV_4_Value_EPT          86u
#define PDUR_SRCPDU_INV_5_Values_EPT          87u
#define PDUR_SRCPDU_INV_IMMO_Req_EPT          88u
#define PDUR_SRCPDU_COM_VCU_DispInfo_BAC          89u
#define PDUR_SRCPDU_COM_CCU_VehInfo_BAC          90u
#define PDUR_SRCPDU_COM_VCU_D_Status_BAC          91u
#define PDUR_SRCPDU_COM_AC_ACStatuts_BAC          92u
#define PDUR_SRCPDU_COM_BCM_B_Package_BAC          93u
#define PDUR_SRCPDU_COM_AC_3_State_BAC          94u
#define PDUR_SRCPDU_COM_BCM_HFSData_BAC          95u
#define PDUR_SRCPDU_ICU_Info_BAC          96u
#define PDUR_SRCPDU_HU_B_BAC          97u
#define PDUR_SRCPDU_HU_A_BAC          98u
#define PDUR_SRCPDU_ICU_2_Odo_BAC          99u
#define PDUR_SRCPDU_HU_C_BAC          100u
#define PDUR_SRCPDU_TBOX_BJS_Time_BAC          101u
#define PDUR_SRCPDU_CANTP_RX_Diag_PhyReq_CCU_OBD          102u
#define PDUR_SRCPDU_CANTP_RX_Diag_FuncReq_OBD          103u
#define PDUR_SRCPDU_DCM_TX_Diag_Resp_CCU_OBD          104u
#define PDUR_SRCPDU_CANIF_Diag_Resp_MCU_RX_EPT          105u
#define PDUR_SRCPDU_CANIF_Diag_Resp_BMS_RX_EPT          106u
#define PDUR_SRCPDU_CANIF_Diag_Resp_IPUDCC_RX_EPT          107u
#define PDUR_SRCPDU_CANIF_Diag_Resp_ESC_RX_CHA          108u
#define PDUR_SRCPDU_CANIF_Diag_Resp_EHB_RX_CHA          109u
#define PDUR_SRCPDU_CANIF_Diag_Resp_EPS_RX_CHA          110u
#define PDUR_SRCPDU_CANIF_Diag_Resp_PP_RX_CHA          111u
#define PDUR_SRCPDU_CANIF_Diag_Resp_FCM_RX_CHA          112u
#define PDUR_SRCPDU_CANIF_Diag_Resp_FRM_RX_CHA          113u
#define PDUR_SRCPDU_CANIF_Diag_Resp_CRRL_RX_CHA          114u
#define PDUR_SRCPDU_CANIF_Diag_Resp_CRRR_RX_CHA          115u
#define PDUR_SRCPDU_CANIF_Diag_Resp_SRS_RX_CHA          116u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CDCICU_OBD          117u
#define PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_OBD          118u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PTC_OBD          119u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SCS_OBD          120u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CCP_OBD          121u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_AVAS_OBD          122u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESCL_OBD          123u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ACCM_OBD          124u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_TPMS_OBD          125u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESC_OBD          126u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EHB_OBD          127u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EPS_OBD          128u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PP_OBD          129u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FCM_OBD          130u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FRM_OBD          131u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRL_OBD          132u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRR_OBD          133u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SRS_OBD          134u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_MCU_OBD          135u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_BMS_OBD          136u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_IPUDCC_OBD          137u
#define PDUR_SRCPDU_CANIF_Diag_Resp_PTC_RX_BOD          138u
#define PDUR_SRCPDU_CANIF_Diag_Resp_SCS_RX_BOD          139u
#define PDUR_SRCPDU_CANIF_Diag_Resp_CCP_RX_BOD          140u
#define PDUR_SRCPDU_CANIF_Diag_Resp_AVAS_RX_BOD          141u
#define PDUR_SRCPDU_CANIF_Diag_Resp_ESCL_RX_BOD          142u
#define PDUR_SRCPDU_CANIF_Diag_Resp_ACCM_RX_BOD          143u
#define PDUR_SRCPDU_CANIF_Diag_Resp_TPMS_RX_BOD          144u
#define PDUR_SRCPDU_CANIF_RX_Diag_Resp_CDCICU_BAC          145u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_MCU_BAC          146u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_BMS_BAC          147u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_IPUDCC_BAC          148u
#define PDUR_SRCPDU_CANIF_RX_Diag_FuncReq_BAC          149u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESC_BAC          150u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EHB_BAC          151u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_EPS_BAC          152u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PP_BAC          153u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FCM_BAC          154u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_FRM_BAC          155u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRL_BAC          156u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CRRR_BAC          157u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SRS_BAC          158u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_PTC_BAC          159u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_SCS_BAC          160u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_CCP_BAC          161u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_AVAS_BAC          162u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ESCL_BAC          163u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_ACCM_BAC          164u
#define PDUR_SRCPDU_CANIF_RX_Diag_PhyReq_TPMS_BAC          165u
#define PDUR_SRCPDU_Com_HP_EXV_Cmd_LIN1          166u
#define PDUR_SRCPDU_HP_EXV__Rsp_LIN1          167u
#define PDUR_SRCPDU_Com_BAT_EXV_Cmd_LIN1          168u
#define PDUR_SRCPDU_BAT_EXV_Rsp_LIN1          169u
#define PDUR_SRCPDU_Com_AC_EXV_Cmd_LIN1          170u
#define PDUR_SRCPDU_AC_EXV_Rsp_LIN1          171u
#define PDUR_SRCPDU_Com_MCV_Cmd_LIN1          172u
#define PDUR_SRCPDU_MCV_Sts_LIN1          173u
#define PDUR_SRCPDU_Com_BCV_Cmd_LIN1          174u
#define PDUR_SRCPDU_BCV_Sts_LIN1          175u
#define PDUR_SRCPDU_Com_PMP_Cmd_LIN1          176u
#define PDUR_SRCPDU_MotPMP_Sts_LIN1          177u
#define PDUR_SRCPDU_BatPMP_Sts_LIN1          178u
#define PDUR_SRCPDU_AcPMP_Sts_LIN1          179u
#define PDUR_SRCPDU_HP_EXV_Version_LIN1          180u
#define PDUR_SRCPDU_Bat_EXV_Version_LIN1          181u
#define PDUR_SRCPDU_MCV_Version_LIN1          182u
#define PDUR_SRCPDU_BCV_Version_LIN1          183u
#define PDUR_SRCPDU_AcPMP_Version_LIN1          184u
#define PDUR_SRCPDU_Com_AC_EXV_Cmd_LIN2          185u
#define PDUR_SRCPDU_AC_EXV_Rsp_LIN2          186u
#define PDUR_SRCPDU_AcPMP_Sts_LIN2          187u
#define PDUR_SRCPDU_AcPMP_Version_LIN2          188u
#define PDUR_SRCPDU_Com_BAT_EXV_Cmd_LIN2          189u
#define PDUR_SRCPDU_BAT_EXV_Rsp_LIN2          190u
#define PDUR_SRCPDU_BatPMP_Sts_LIN2          191u
#define PDUR_SRCPDU_Bat_EXV_Version_LIN2          192u
#define PDUR_SRCPDU_Com_C3WV_Cmd_LIN2          193u
#define PDUR_SRCPDU_C3WV_Sts_LIN2          194u
#define PDUR_SRCPDU_Com_C5WV_Cmd_LIN2          195u
#define PDUR_SRCPDU_C5WV_Sts_LIN2          196u
#define PDUR_SRCPDU_Com_HP_EXV_Cmd_LIN2          197u
#define PDUR_SRCPDU_HP_EXV_Rsp_LIN2          198u
#define PDUR_SRCPDU_HP_EXV_Version_LIN2          199u
#define PDUR_SRCPDU_MotPMP_Sts_LIN2          200u
#define PDUR_SRCPDU_Com_PMP_Cmd_LIN2          201u
#define PDUR_SRCPDU_Com_CCU_FCLCommand_LIN3          202u
#define PDUR_SRCPDU_FCLL_Status_LIN3          203u
#define PDUR_SRCPDU_FCLR_Status_LIN3          204u
#define PDUR_SRCPDU_Frm_InterlockStatus_LIN3          205u
#define PDUR_SRCPDU_Frm_InterlockToVehicle_LIN3          206u
#define PDUR_SRCPDU_Com_Frm_VehicleToInterlock_LIN3          207u
#define PDUR_SRCPDU_CANTP_RX_Diag_PhyReq_BAC          208u
#define PDUR_SRCPDU_CANTP_RX_Diag_FuncReq_BAC          209u
#define PDUR_SRCPDU_DCM_TX_Diag_Resp_BAC          210u
#define PDUR_SRCPDU_Com_CAN6_CANFD5_user          211u
#define PDUR_SRCPDU_DCM_TX_Diag_Resp_CCU_OBD_2A          212u
/* PRQA S 0791 -- */ /* MISRA Rule 5.4 */

#define PDUR_DEST_PDU_SUM              280u

#define PDUR_DEST_GATEWAY_TP_PDU_SUM   0u

/* PRQA S 0791 ++ */ /* MISRA Rule 5.4 */
#define PDUR_DESTPDU_INCA_CRO_XCP          0u
#define PDUR_DESTPDU_COM_TMSR_DTO_XCP          1u
#define PDUR_DESTPDU_CanNm_CAN5_CANFD3_user          2u
#define PDUR_DESTPDU_CanNm_CAN2_CANFD6_user          3u
#define PDUR_DESTPDU_CanNm_CAN1_CANFD8_user          4u
#define PDUR_DESTPDU_VCU_10_Torque_CHA          5u
#define PDUR_DESTPDU_BCM_4_CruiseSw_PM_CHA          6u
#define PDUR_DESTPDU_CCU_VehInfo_CHA          7u
#define PDUR_DESTPDU_VCU_D_Status_CHA          8u
#define PDUR_DESTPDU_BCM_B_Package_CHA          9u
#define PDUR_DESTPDU_AC_3_State_CHA          10u
#define PDUR_DESTPDU_FCM_D_CHA_2_BAC          11u
#define PDUR_DESTPDU_COM_FCM_D_CHA          12u
#define PDUR_DESTPDU_COM_FCM_B_CHA          13u
#define PDUR_DESTPDU_FCM_A_CHA_2_BAC          14u
#define PDUR_DESTPDU_COM_FCM_A_CHA          15u
#define PDUR_DESTPDU_FCM_23_Obj0109_2_BAC          16u
#define PDUR_DESTPDU_COM_FCM_23_Obj0109_CHA          17u
#define PDUR_DESTPDU_FCM_24_Obj1018_CHA_2_BAC          18u
#define PDUR_DESTPDU_COM_FCM_24_Obj1018_CHA          19u
#define PDUR_DESTPDU_FCM_25_Line123_CHA_2_BAC          20u
#define PDUR_DESTPDU_COM_FCM_25_Line123_CHA          21u
#define PDUR_DESTPDU_FCM_ObjTrackID_CHA_2_BAC          22u
#define PDUR_DESTPDU_COM_FCM_ObjTrackID_CHA          23u
#define PDUR_DESTPDU_COM_ESC_WheelPulseTime_CHA          24u
#define PDUR_DESTPDU_COM_ESC_A_CHA          25u
#define PDUR_DESTPDU_ESC_7_FuncStatus_EPT          26u
#define PDUR_DESTPDU_ESC_7_FuncStatus_BOD          27u
#define PDUR_DESTPDU_ESC_7_FuncStatus_BAC          28u
#define PDUR_DESTPDU_COM_ESC_7_FuncStatus_CHA          29u
#define PDUR_DESTPDU_COM_EHB_B_CHA          30u
#define PDUR_DESTPDU_EHB_A_BOD          31u
#define PDUR_DESTPDU_EHB_A_BAC          32u
#define PDUR_DESTPDU_COM_EHB_A_CHA          33u
#define PDUR_DESTPDU_COM_SRS_2_YRSOriginalSts_CHA          34u
#define PDUR_DESTPDU_COM_SRS_3_YRSActualSts_CHA          35u
#define PDUR_DESTPDU_SRS_1_Status_EPT          36u
#define PDUR_DESTPDU_SRS_1_Status_BAC          37u
#define PDUR_DESTPDU_COM_SRS_1_Status_CHA          38u
#define PDUR_DESTPDU_COM_EPS_3_LatDrvAndEPSSts_CHA          39u
#define PDUR_DESTPDU_COM_EPS_2_StrWhlAng_CHA          40u
#define PDUR_DESTPDU_EPS_1_Status_BAC          41u
#define PDUR_DESTPDU_COM_EPS_1_Status_CHA          42u
#define PDUR_DESTPDU_PP_InformAndStatus_CHA_2_BAC          43u
#define PDUR_DESTPDU_COM_PP_InformAndStatus_CHA          44u
#define PDUR_DESTPDU_CRRR_A_BAC          45u
#define PDUR_DESTPDU_COM_CRRR_A_CHA          46u
#define PDUR_DESTPDU_COM_CRRR_10_Posn_CHA          47u
#define PDUR_DESTPDU_CCU_VehInfo_BOD          48u
#define PDUR_DESTPDU_AC_ACStatuts_BOD          49u
#define PDUR_DESTPDU_AC_COMP_BOD          50u
#define PDUR_DESTPDU_VCU_7_DrvRange_BOD          51u
#define PDUR_DESTPDU_AC_1_Command_BOD          52u
#define PDUR_DESTPDU_HVCH_Command_BOD          53u
#define PDUR_DESTPDU_AC_3_State_BOD          54u
#define PDUR_DESTPDU_AC_2_State_BOD          55u
#define PDUR_DESTPDU_AC_8_status_BOD          56u
#define PDUR_DESTPDU_BCM_ESCLCommand_BOD          57u
#define PDUR_DESTPDU_TMS_LINTestData1_BOD          58u
#define PDUR_DESTPDU_TMS_LINTestData2_BOD          59u
#define PDUR_DESTPDU_TMS_LINTestData3_BOD          60u
#define PDUR_DESTPDU_COM_CCP_PanelStatus_BOD          61u
#define PDUR_DESTPDU_CCP_PanelStatus_CHA          62u
#define PDUR_DESTPDU_COM_SCS_RiSwitchSts_BOD          63u
#define PDUR_DESTPDU_SCS_RiSwitchSts_CHA          64u
#define PDUR_DESTPDU_SCS_RiSwitchSts_BAC          65u
#define PDUR_DESTPDU_COM_SCS_LeSwitchSts_BOD          66u
#define PDUR_DESTPDU_SCS_LeSwitchSts_CHA          67u
#define PDUR_DESTPDU_SCS_LeSwitchSts_BAC          68u
#define PDUR_DESTPDU_COM_TPMS_Info_BOD          69u
#define PDUR_DESTPDU_TPMS_Info_CHA          70u
#define PDUR_DESTPDU_TPMS_Info_BAC          71u
#define PDUR_DESTPDU_COM_ESCL_ESCLStatus_BOD          72u
#define PDUR_DESTPDU_COM_AVAS_State_BOD          73u
#define PDUR_DESTPDU_AVAS_State_BAC          74u
#define PDUR_DESTPDU_COM_COMP_AC_BOD          75u
#define PDUR_DESTPDU_COM_ACCM_Version_BOD          76u
#define PDUR_DESTPDU_COM_HVCH_Status1_BOD          77u
#define PDUR_DESTPDU_COM_HVCH_Status2_BOD          78u
#define PDUR_DESTPDU_VCU_3_OprtCmd_EPT          79u
#define PDUR_DESTPDU_VCU_4_ChrgCmd_EPT          80u
#define PDUR_DESTPDU_VCU_B_AcclPedal_EPT          81u
#define PDUR_DESTPDU_VCU_1_InvCmd_EPT          82u
#define PDUR_DESTPDU_VCU_0_Value_EPT          83u
#define PDUR_DESTPDU_VCU_C_OprtCmd_EPT          84u
#define PDUR_DESTPDU_CCU_VehInfo_EPT          85u
#define PDUR_DESTPDU_BCM_IMMOAuthResp1_EPT          86u
#define PDUR_DESTPDU_COM_BMS_1_MainState_EPT          87u
#define PDUR_DESTPDU_BMS_1_MainState_BAC          88u
#define PDUR_DESTPDU_COM_BMS_2_BatState_EPT          89u
#define PDUR_DESTPDU_BMS_2_BatState_BAC          90u
#define PDUR_DESTPDU_COM_BMS_3_DC_ChargeState_EPT          91u
#define PDUR_DESTPDU_COM_BMS_4_AC_ChargeState_EPT          92u
#define PDUR_DESTPDU_COM_BMS_10_DC_ChargeStates_EPT          93u
#define PDUR_DESTPDU_BMS_10_DC_ChargeStates_BAC          94u
#define PDUR_DESTPDU_COM_BMS_5_BatTemp_EPT          95u
#define PDUR_DESTPDU_COM_BMS_6_DischrgRecup_EPT          96u
#define PDUR_DESTPDU_COM_BMS_7_CellVolt_EPT          97u
#define PDUR_DESTPDU_COM_BMS_8_TempVoltLimit_EPT          98u
#define PDUR_DESTPDU_COM_BMS_9_BattInfo_EPT          99u
#define PDUR_DESTPDU_COM_BMS_A_GB_EPT          100u
#define PDUR_DESTPDU_BMS_A_GB_BAC          101u
#define PDUR_DESTPDU_COM_BMS_B_GB_EPT          102u
#define PDUR_DESTPDU_BMS_B_GB_BAC          103u
#define PDUR_DESTPDU_COM_BMS_C_GB_EPT          104u
#define PDUR_DESTPDU_BMS_C_GB_BAC          105u
#define PDUR_DESTPDU_COM_BMS_D_GB_EPT          106u
#define PDUR_DESTPDU_BMS_D_GB_BAC          107u
#define PDUR_DESTPDU_COM_IPU_OBC_3_CP_CC_EPT          108u
#define PDUR_DESTPDU_COM_IPU_DCC_1_State_EPT          109u
#define PDUR_DESTPDU_COM_IPU_OBC_1_State_EPT          110u
#define PDUR_DESTPDU_IPU_OBC_1_State_BAC          111u
#define PDUR_DESTPDU_COM_IPU_DCC_2_ChrgInValue_EPT          112u
#define PDUR_DESTPDU_COM_IPU_OBC_2_Inlet_EPT          113u
#define PDUR_DESTPDU_COM_IPU_OBC_4_state_EPT          114u
#define PDUR_DESTPDU_IPU_OBC_4_state_BAC          115u
#define PDUR_DESTPDU_COM_INV_1_Value_EPT          116u
#define PDUR_DESTPDU_INV_1_Value_BAC          117u
#define PDUR_DESTPDU_COM_INV_2_Value_EPT          118u
#define PDUR_DESTPDU_COM_INV_3_Value_EPT          119u
#define PDUR_DESTPDU_COM_INV_4_Value_EPT          120u
#define PDUR_DESTPDU_COM_INV_5_Values_EPT          121u
#define PDUR_DESTPDU_COM_INV_IMMO_Req_EPT          122u
#define PDUR_DESTPDU_VCU_DispInfo_BAC          123u
#define PDUR_DESTPDU_CCU_VehInfo_BAC          124u
#define PDUR_DESTPDU_VCU_D_Status_BAC          125u
#define PDUR_DESTPDU_AC_ACStatuts_BAC          126u
#define PDUR_DESTPDU_BCM_B_Package_BAC          127u
#define PDUR_DESTPDU_AC_3_State_BAC          128u
#define PDUR_DESTPDU_BCM_HFSData_BAC          129u
#define PDUR_DESTPDU_COM_ICU_Info_BAC          130u
#define PDUR_DESTPDU_ICU_Info_CHA          131u
#define PDUR_DESTPDU_COM_HU_B_BAC          132u
#define PDUR_DESTPDU_COM_HU_A_BAC          133u
#define PDUR_DESTPDU_HU_A_CHA          134u
#define PDUR_DESTPDU_COM_ICU_2_Odo_BAC          135u
#define PDUR_DESTPDU_ICU_2_Odo_EPT          136u
#define PDUR_DESTPDU_ICU_2_Odo_CHA          137u
#define PDUR_DESTPDU_ICU_2_Odo_BOD          138u
#define PDUR_DESTPDU_COM_HU_C_BAC          139u
#define PDUR_DESTPDU_HU_C_BOD          140u
#define PDUR_DESTPDU_COM_TBOX_BJS_Time_BAC          141u
#define PDUR_DESTPDU_TBOX_BJS_Time_EPT          142u
#define PDUR_DESTPDU_TBOX_BJS_Time_CHA          143u
#define PDUR_DESTPDU_TBOX_BJS_Time_BOD          144u
#define PDUR_DESTPDU_DCM_RX_Phy_Diag_PhyReq_CCU_OBD          145u
#define PDUR_DESTPDU_DCM_RX_Diag_FuncReq_OBD          146u
#define PDUR_DESTPDU_CANTP_TX_Diag_Resp_CCU_OBD          147u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_MCU_OBD          148u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_MCU_BAC          149u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_BMS_OBD          150u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_BMS_BAC          151u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_IPUDCC_OBD          152u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_IPUDCC_BAC          153u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESC_OBD          154u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESC_BAC          155u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_EHB_BAC          156u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_EHB_OBD          157u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_EPS_BAC          158u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_EPS_OBD          159u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_PP_BAC          160u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_PP_OBD          161u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_FCM_BAC          162u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_FCM_OBD          163u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_FRM_BAC          164u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_FRM_OBD          165u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRL_BAC          166u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRL_OBD          167u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRR_BAC          168u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CRRR_OBD          169u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_SRS_BAC          170u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_SRS_OBD          171u
#define PDUR_DESTPDU_CANIF_TX_Diag_PhyReq_CDCICU_BAC          172u
#define PDUR_DESTPDU_CANIF_TX_Diag_FuncReq_BAC          173u
#define PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_BOD          174u
#define PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_CHA          175u
#define PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_EPT          176u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD          177u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD          178u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD          179u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD          180u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD          181u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD          182u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD          183u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_ESC_TX_CHA          184u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_EHB_TX_CHA          185u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_EPS_TX_CHA          186u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_PP_TX_CHA          187u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_FCM_TX_CHA          188u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_FRM_TX_CHA          189u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA          190u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA          191u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_SRS_TX_CHA          192u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_MCU_TX_EPT          193u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_BMS_TX_EPT          194u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT          195u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_PTC_BAC          196u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_PTC_OBD          197u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_SCS_BAC          198u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_SCS_OBD          199u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCP_BAC          200u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCP_OBD          201u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_AVAS_BAC          202u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_AVAS_OBD          203u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESCL_BAC          204u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_ESCL_OBD          205u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_ACCM_BAC          206u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_ACCM_OBD          207u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_TPMS_BAC          208u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_TPMS_OBD          209u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CDCICU_OBD          210u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_MCU_TX_EPT_1          211u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_BMS_TX_EPT_1          212u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_IPUDCC_TX_EPT_1          213u
#define PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_EPT_1          214u
#define PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_CHA_1          215u
#define PDUR_DESTPDU_CANIF_Diag_FuncReq_TX_BOD_1          216u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_ESC_TX_CHA_1          217u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_EHB_TX_CHA_1          218u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_EPS_TX_CHA_1          219u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_PP_TX_CHA_1          220u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_FCM_TX_CHA_1          221u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_FRM_TX_CHA_1          222u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRL_TX_CHA_1          223u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_CRRR_TX_CHA_1          224u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_SRS_TX_CHA_1          225u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_PTC_BOD_TX_BOD_1          226u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_SCS_BOD_TX_BOD_1          227u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_CCP_BOD_TX_BOD_1          228u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_AVAS_BOD_TX_BOD_1          229u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_ESCL_BOD_TX_BOD_1          230u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_ACCM_BOD_TX_BOD_1          231u
#define PDUR_DESTPDU_CANIF_Diag_PhyReq_TPMS_BOD_TX_BOD_1          232u
#define PDUR_DESTPDU_HP_EXV_Cmd_LIN1          233u
#define PDUR_DESTPDU_Com_HP_EXV__Rsp_LIN1          234u
#define PDUR_DESTPDU_BAT_EXV_Cmd_LIN1          235u
#define PDUR_DESTPDU_Com_BAT_EXV_Rsp_LIN1          236u
#define PDUR_DESTPDU_AC_EXV_Cmd_LIN1          237u
#define PDUR_DESTPDU_Com_AC_EXV_Rsp_LIN1          238u
#define PDUR_DESTPDU_MCV_Cmd_LIN1          239u
#define PDUR_DESTPDU_Com_MCV_Sts_LIN1          240u
#define PDUR_DESTPDU_BCV_Cmd_LIN1          241u
#define PDUR_DESTPDU_Com_BCV_Sts_LIN1          242u
#define PDUR_DESTPDU_PMP_Cmd_LIN1          243u
#define PDUR_DESTPDU_Com_MotPMP_Sts_LIN1          244u
#define PDUR_DESTPDU_Com_BatPMP_Sts_LIN1          245u
#define PDUR_DESTPDU_Com_AcPMP_Sts_LIN1          246u
#define PDUR_DESTPDU_Com_HP_EXV_Version_LIN1          247u
#define PDUR_DESTPDU_Com_Bat_EXV_Version_LIN1          248u
#define PDUR_DESTPDU_Com_MCV_Version_LIN1          249u
#define PDUR_DESTPDU_Com_BCV_Version_LIN1          250u
#define PDUR_DESTPDU_Com_AcPMP_Version_LIN1          251u
#define PDUR_DESTPDU_AC_EXV_Cmd_LIN2          252u
#define PDUR_DESTPDU_Com_AC_EXV_Rsp_LIN2          253u
#define PDUR_DESTPDU_Com_AcPMP_Sts_LIN2          254u
#define PDUR_DESTPDU_Com_AcPMP_Version_LIN2          255u
#define PDUR_DESTPDU_BAT_EXV_Cmd_LIN2          256u
#define PDUR_DESTPDU_Com_BAT_EXV_Rsp_LIN2          257u
#define PDUR_DESTPDU_Com_BatPMP_Sts_LIN2          258u
#define PDUR_DESTPDU_Com_Bat_EXV_Version_LIN2          259u
#define PDUR_DESTPDU_C3WV_Cmd_LIN2          260u
#define PDUR_DESTPDU_Com_C3WV_Sts_LIN2          261u
#define PDUR_DESTPDU_C5WV_Cmd_LIN2          262u
#define PDUR_DESTPDU_Com_C5WV_Sts_LIN2          263u
#define PDUR_DESTPDU_HP_EXV_Cmd_LIN2          264u
#define PDUR_DESTPDU_Com_HP_EXV_Rsp_LIN2          265u
#define PDUR_DESTPDU_Com_HP_EXV_Version_LIN2          266u
#define PDUR_DESTPDU_Com_MotPMP_Sts_LIN2          267u
#define PDUR_DESTPDU_PMP_Cmd_LIN2          268u
#define PDUR_DESTPDU_CCU_FCLCommand_LIN3          269u
#define PDUR_DESTPDU_Com_FCLL_Status_LIN3          270u
#define PDUR_DESTPDU_Com_FCLR_Status_LIN3          271u
#define PDUR_DESTPDU_Com_Frm_InterlockStatus_LIN3          272u
#define PDUR_DESTPDU_Com_Frm_InterlockToVehicle_LIN3          273u
#define PDUR_DESTPDU_Frm_VehicleToInterlock_LIN3          274u
#define PDUR_DESTPDU_DCM_RX_Phy_Diag_PhyReq_BAC          275u
#define PDUR_DESTPDU_DCM_RX_Diag_FuncReq_BAC          276u
#define PDUR_DESTPDU_CANTP_TX_Diag_Resp_BAC          277u
#define PDUR_DESTPDU_CanNm_CAN6_CANFD5_user          278u
#define PDUR_DESTPDU_CANIF_TX_Diag_Resp_CCU_OBD_2A          279u
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

