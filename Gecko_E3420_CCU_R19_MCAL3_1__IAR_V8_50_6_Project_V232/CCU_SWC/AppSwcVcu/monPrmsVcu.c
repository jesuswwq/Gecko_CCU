/*
 * File: monPrmsVcu.c
 *
 * Code generated for Simulink model 'AppSwcVcu'.
 *
 * Model version                  : 9.483
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Sep 19 15:42:51 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "monPrmsVcu.h"
#include "AppSwcVcu.h"

/* Exported data definition */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Definition for custom storage class: Volatile */
MONPRM volatile boolean BSW_RTCWakeup_flg = false;/* '<S973>/Switch4' */

/* RTC���ѱ�־λ_versteckt */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Day = ((uint8)0U);/* '<S97>/Data Type Conversion45' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Hour = ((uint8)0U);/* '<S97>/Data Type Conversion1' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Min = ((uint8)0U);/* '<S97>/Data Type Conversion2' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Month = ((uint8)0U);/* '<S97>/Data Type Conversion34' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Sec = ((uint8)0U);/* '<S97>/Switch2' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Year = ((uint8)0U);/* '<S97>/Data Type Conversion33' */
MONPRM volatile uint8 VBSW_WakeupReasn_enum = ((uint8)0U);/* '<S1443>/EcuWakeupReasn' */

/* _versteckt */
MONPRM volatile float32 VCPT_MotorDrgMaxTq_Nm = 0.0F;/* '<S1027>/MinMax6' */
MONPRM volatile float32 VCPT_MotorDrvMaxTq_Nm = 0.0F;/* '<S1027>/MinMax7' */
MONPRM volatile float32 VCPT_MotorGenMaxTq_Nm = 0.0F;/* '<S1039>/Switch1' */
MONPRM volatile float32 VCPT_MotorMotMaxTq_Nm = 0.0F;/* '<S1038>/Switch1' */
MONPRM volatile boolean VCPT_MotorSpdRvrs_flg = false;/* '<S1027>/Switch3' */
MONPRM volatile float32 VCPT_MotorSpd_rpm = 0.0F;/* '<S1033>/Switch' */
MONPRM volatile float32 VCPT_WhlDrgMaxTq_Nm = 0.0F;/* '<S1027>/MinMax1' */
MONPRM volatile float32 VCPT_WhlDrvMaxTq_Nm = 0.0F;/* '<S1027>/MinMax8' */
MONPRM volatile boolean VDAC_ACCAvail_flg = false;/* '<S1048>/Logical Operator9' */
MONPRM volatile float32 VDAC_ACCDeltaAcceltn_mps2 = 0.0F;/* '<S1054>/Add5' */
MONPRM volatile float32 VDAC_ACCDsrdTqFF_Nm = 0.0F;/* '<S1054>/Add3' */
MONPRM volatile float32 VDAC_ACCDsrdTqI_N = 0.0F;/* '<S1054>/Saturation1' */
MONPRM volatile float32 VDAC_ACCDsrdTqPID_Nm = 0.0F;/* '<S1054>/Product6' */
MONPRM volatile float32 VDAC_ACCDsrdTqP_N = 0.0F;/* '<S1054>/Product3' */
MONPRM volatile boolean VDAC_ACCEnbl_flg = false;/* '<S1048>/Logical Operator3' */
MONPRM volatile boolean VDAC_ACCOvrd_flg = false;/* '<S1049>/Logical Operator22' */
MONPRM volatile float32 VDAC_ACCTqReqWhl_Nm = 0.0F;/* '<S1050>/Merge3' */
MONPRM volatile uint8 VDAC_AutoBrkReq_enum = ((uint8)0U);/* '<S1155>/Switch' */
MONPRM volatile boolean VDAC_CCActv2Stby_flg = false;/* '<S1089>/Logical Operator15' */
MONPRM volatile boolean VDAC_CCActvBascCond_flg = false;/* '<S1089>/Logical Operator1' */
MONPRM volatile float32 VDAC_CCDeltaAcceltn_mps2 = 0.0F;/* '<S1076>/Add3' */
MONPRM volatile float32 VDAC_CCDsrdAcceltnRaw_mps2 = 0.0F;/* '<S1069>/Saturation1' */
MONPRM volatile float32 VDAC_CCDsrdAcceltn_mps2 = 0.0F;/* '<S1067>/Merge1' */
MONPRM volatile float32 VDAC_CCDsrdTqFF_N = 0.0F;/* '<S1075>/Add3' */
MONPRM volatile float32 VDAC_CCDsrdTqI_N = 0.0F;/* '<S1076>/Saturation1' */
MONPRM volatile float32 VDAC_CCDsrdTqPID_N = 0.0F;/* '<S1076>/Add2' */
MONPRM volatile float32 VDAC_CCDsrdTqP_N = 0.0F;/* '<S1076>/Product2' */
MONPRM volatile boolean VDAC_CCEnbl_flg = false;/* '<S1090>/Logical Operator2' */
MONPRM volatile uint16 VDAC_CCNoActvCond_enum = ((uint16)0U);/* '<S1092>/Add' */
MONPRM volatile boolean VDAC_CCOvrd_flg = false;/* '<S1063>/Logical Operator22' */
MONPRM volatile uint16 VDAC_CCQuitCond_enum = ((uint16)0U);/* '<S1093>/Add' */
MONPRM volatile float32 VDAC_CCSpdUnstabTm_s = 0.0F;/* '<S1105>/Saturation' */
MONPRM volatile boolean VDAC_CCSpdUnstab_flg = false;/* '<S1105>/Relational Operator8' */
MONPRM volatile EnumCCState VDAC_CCSt_enum = EnumCCState_Off;/* '<S1064>/CC_State_Chart' */
MONPRM volatile boolean VDAC_CCStby2Actv_flg = false;/* '<S1089>/Logical Operator9' */
MONPRM volatile float32 VDAC_CCTgtSpdCtrl_kph = 0.0F;/* '<S1114>/Switch1' */
MONPRM volatile uint8 VDAC_CCTgtSpdHU_kph = ((uint8)0U);/* '<S1065>/TgtSpdCalc' */
MONPRM volatile EnumCCTgtSpdSt VDAC_CCTgtSpdSt_enum = EnumCCTgtSpdSt_Reset;/* '<S1065>/TgtSpdCalc' */
MONPRM volatile float32 VDAC_CCTgtSpd_kph = 0.0F;/* '<S1065>/MinMax7' */
MONPRM volatile float32 VDAC_CCTqReqWhl_Nm = 0.0F;/* '<S1068>/Merge2' */
MONPRM volatile float32 VDAC_CCVehSpdNonDrvn_kph = 0.0F;/* '<S1071>/Switch' */
MONPRM volatile boolean VDAC_CruzCncl_flg = false;/* '<S1130>/Chart' */
MONPRM volatile EnumCruiseStatus VDAC_CruzCtrlStat_enum =
  EnumCruiseStatus_NormOff;            /* '<S1063>/Switch2' */
MONPRM volatile boolean VDAC_CruzCtrlSwVld_flg = false;/* '<S1066>/Signal Conversion1' */
MONPRM volatile boolean VDAC_CruzOn_flg = true;/* '<S1066>/Signal Conversion2' */
MONPRM volatile boolean VDAC_CruzRsmActv_flg = false;/* '<S1127>/Switch4' */
MONPRM volatile boolean VDAC_CruzSetActv_flg = false;/* '<S1125>/Switch4' */
MONPRM volatile boolean VDAC_CruzSpdDecActv_flg = false;/* '<S1126>/Switch4' */
MONPRM volatile boolean VDAC_CruzSpdIncActv_flg = false;/* '<S1128>/Switch4' */
MONPRM volatile float32 VDAC_DrvAsstTqSplitEHB_Nm = 0.0F;/* '<S1044>/MinMax2' */
MONPRM volatile float32 VDAC_DrvAsstTqSplitINV_Nm = 0.0F;/* '<S1044>/Add1' */
MONPRM volatile uint8 VDAC_DrvAsstTqSts_enum = ((uint8)0U);/* '<S1044>/Switch1' */
MONPRM volatile float32 VDAC_DrvAsstTqTgt_Nm = 0.0F;/* '<S1044>/Switch2' */
MONPRM volatile boolean VDAC_EnblEHBBrkRun_flg = false;/* '<S1237>/Switch4' */
MONPRM volatile boolean VDAC_HDCActv2Idle_flg = false;/* '<S1137>/Logical Operator11' */
MONPRM volatile boolean VDAC_HDCActv2Stdby_flg = false;/* '<S1137>/Logical Operator8' */
MONPRM volatile float32 VDAC_HDCDeltaAcceltn_mps2 = 0.0F;/* '<S1142>/Add5' */
MONPRM volatile float32 VDAC_HDCDsrdTqFF_Nm = 0.0F;/* '<S1142>/Add3' */
MONPRM volatile float32 VDAC_HDCDsrdTqI_N = 0.0F;/* '<S1142>/Saturation1' */
MONPRM volatile float32 VDAC_HDCDsrdTqPID_Nm = 0.0F;/* '<S1142>/Product6' */
MONPRM volatile float32 VDAC_HDCDsrdTqP_N = 0.0F;/* '<S1142>/Product3' */
MONPRM volatile boolean VDAC_HDCIdle2Stdby_flg = false;/* '<S1137>/Logical Operator2' */
MONPRM volatile EnumHDCState VDAC_HDCSt_enum = EnumHDCState_Idle;/* '<S1042>/HDC_State_Chart' */
MONPRM volatile boolean VDAC_HDCStdby2Actv_flg = false;/* '<S1137>/Logical Operator13' */
MONPRM volatile boolean VDAC_HDCStdby2Idle_flg = false;/* '<S1137>/Logical Operator3' */
MONPRM volatile float32 VDAC_HDCTgtAcceltn_mps2 = 0.0F;/* '<S1134>/Merge1' */
MONPRM volatile float32 VDAC_HDCTgtSpd_kph = 0.0F;/* '<S1042>/HDC_State_Chart' */
MONPRM volatile float32 VDAC_HDCTqReqWhl_Nm = 0.0F;/* '<S1134>/Merge2' */
MONPRM volatile uint8 VDAC_HDCVehSpdHU_kph = ((uint8)0U);/* '<S1135>/Switch1' */
MONPRM volatile boolean VDAC_MstrCylPresDec_flg = false;/* '<S1163>/Relational Operator' */
MONPRM volatile float32 VDAC_MstrCylPresrReq_bar = 0.0F;/* '<S1044>/Switch13' */
MONPRM volatile boolean VDAC_OPDActv_flg = false;/* '<S1178>/Switch4' */
MONPRM volatile boolean VDAC_OPDAvail_flg = false;/* '<S1156>/Logical Operator9' */
MONPRM volatile float32 VDAC_OPDDeltaAcceltn_mps2 = 0.0F;/* '<S1195>/Add3' */
MONPRM volatile float32 VDAC_OPDDeltaSpd_kph = 0.0F;/* '<S1195>/Add4' */
MONPRM volatile float32 VDAC_OPDDsrdTqD_N = 0.0F;/* '<S1209>/Switch' */
MONPRM volatile float32 VDAC_OPDDsrdTqFF_Nm = 0.0F;/* '<S1194>/Add3' */
MONPRM volatile boolean VDAC_OPDDsrdTqFstI_flg = false;/* '<S1206>/Logical Operator9' */
MONPRM volatile boolean VDAC_OPDDsrdTqHldI_flg = false;/* '<S1206>/Logical Operator3' */
MONPRM volatile float32 VDAC_OPDDsrdTqI_N = 0.0F;/* '<S1195>/Saturation1' */
MONPRM volatile float32 VDAC_OPDDsrdTqPID_Nm = 0.0F;/* '<S1195>/Product4' */
MONPRM volatile float32 VDAC_OPDDsrdTqP_N = 0.0F;/* '<S1201>/Switch2' */
MONPRM volatile float32 VDAC_OPDMaxDrgTqWhl_Nm = 0.0F;/* '<S1206>/MinMax1' */
MONPRM volatile float32 VDAC_OPDMaxDrvTqWhl_Nm = 0.0F;/* '<S1206>/MinMax3' */
MONPRM volatile boolean VDAC_OPDOvrd_flg = false;/* '<S1155>/Logical Operator22' */
MONPRM volatile float32 VDAC_OPDRtdTq_Nm = 0.0F;/* '<S1194>/Add1' */
MONPRM volatile boolean VDAC_OPDSpdClsLoop_flg = false;/* '<S1195>/Logical Operator9' */
MONPRM volatile float32 VDAC_OPDTgtAcceltn_mps2 = 0.0F;/* '<S1157>/Merge3' */
MONPRM volatile float32 VDAC_OPDTgtSpd_kph = 0.0F;/* '<S1157>/Merge1' */
MONPRM volatile boolean VDAC_OPDTqReqUnload_flg = false;/* '<S1155>/Logical Operator1' */
MONPRM volatile float32 VDAC_OPDTqReqWhlFilt_Nm = 0.0F;/* '<S1229>/Switch3' */
MONPRM volatile float32 VDAC_OPDTqReqWhlLmt_Nm = 0.0F;/* '<S1158>/Merge3' */
MONPRM volatile float32 VDAC_OPDTqReqWhl_Nm = 0.0F;/* '<S1166>/Switch3' */
MONPRM volatile float32 VDAC_OPDVehAcceltn2_mps2 = 0.0F;/* '<S1185>/Switch' */
MONPRM volatile float32 VDAC_OPDVehAcceltn_mps2 = 0.0F;/* '<S1157>/Switch2' */
MONPRM volatile float32 VDAC_OPDVehSpdMotorFac_rat = 0.0F;/* '<S1184>/Switch' */
MONPRM volatile float32 VDAC_OPDVehSpdMotor_kph = 0.0F;/* '<S1157>/Product1' */
MONPRM volatile float32 VDAC_OPDVehSpd_kph = 0.0F;/* '<S1157>/Switch1' */
MONPRM volatile uint8 VDAC_VehSpdHU_kph = ((uint8)0U);/* '<S1116>/Switch1' */
MONPRM volatile uint8 VDAC_VirtAccPedPstnSta_enum = ((uint8)0U);/* '<S1044>/Switch11' */
MONPRM volatile float32 VDAC_VirtAccPedPstn_pct = 0.0F;/* '<S1044>/Switch8' */
MONPRM volatile float32 VDAC_VirtAccelPedPstnRaw_pct = 0.0F;/* '<S1044>/Switch9' */
MONPRM volatile float32 VDAC_VirtPedPstn_pct = 0.0F;/* '<S1044>/Switch4' */
MONPRM volatile uint8 VDAG_ACChrgStFailFltSt_enum = ((uint8)0U);/* '<S377>/FltStDeb' */

/* ACChargeStateFail����״̬ */
MONPRM volatile uint8 VDAG_ACDchaBMSPwrLoFltSt_enum = ((uint8)0U);/* '<S383>/FltStDeb' */

/* AC�ŵ�BMS���ʵ͹���״̬ */
MONPRM volatile uint8 VDAG_ACDchaBMSSOCLoFltSt_enum = ((uint8)0U);/* '<S382>/FltStDeb' */

/* AC�ŵ�BMSSOC�͹���״̬ */
MONPRM volatile uint8 VDAG_ACDchaOverPwrFltSt_enum = ((uint8)0U);/* '<S376>/FltStDeb' */

/* AC�ŵ繦�ʳ��޹��� */
MONPRM volatile uint8 VDAG_ACSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S130>/FltStDeb' */

/* ACSCmd��ʱ����״̬ */
MONPRM volatile uint8 VDAG_AccPed1ShtBattFltSt_enum = ((uint8)0U);/* '<S494>/FltStDeb' */

/* ����̤��1·�̵�Դ����״̬ */
MONPRM volatile uint8 VDAG_AccPed1ShtGndFltSt_enum = ((uint8)0U);/* '<S491>/FltStDeb' */

/* ����̤��1·�̵ع���״̬ */
MONPRM volatile uint8 VDAG_AccPed1SuplyShtCircFltSt_enum = ((uint8)0U);/* '<S492>/FltStDeb' */

/* ����̤��1·�����·����״̬ */
MONPRM volatile uint8 VDAG_AccPed2ShtBattFltSt_enum = ((uint8)0U);/* '<S487>/FltStDeb' */

/* ����̤��2·�̵�Դ����״̬ */
MONPRM volatile uint8 VDAG_AccPed2ShtGndFltSt_enum = ((uint8)0U);/* '<S495>/FltStDeb' */

/* ����̤��2·�̵ع���״̬ */
MONPRM volatile uint8 VDAG_AccPed2SuplyShtCircFltSt_enum = ((uint8)0U);/* '<S493>/FltStDeb' */

/* ����̤��2·�����·����״̬ */
MONPRM volatile uint8 VDAG_AccPedBothFailFltSt_enum = ((uint8)0U);/* '<S489>/FltStDeb' */

/* ����̤��˫·ʧЧ����״̬ */
MONPRM volatile uint8 VDAG_AccPedCrsChkFltSt_enum = ((uint8)0U);/* '<S488>/FltStDeb' */

/* ����̤���໥У�����״̬ */
MONPRM volatile uint8 VDAG_BMSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S124>/FltStDeb' */

/* BMS�̵���ָ����Ӧ��ʱ����״̬ */
MONPRM volatile uint8 VDAG_BMSEmgcySdnFltSt_enum = ((uint8)0U);/* '<S135>/FltStDeb' */

/* BMS�����µ����״̬ */
MONPRM volatile uint8 VDAG_BMSSOCLoFltSt_enum = ((uint8)0U);/* '<S134>/FltStDeb' */

/* BMSSOC�͹���״̬ */
MONPRM volatile uint8 VDAG_BMSSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S131>/FltStDeb' */

/* BMSFailLevel1����״̬ */
MONPRM volatile uint8 VDAG_BMSSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S132>/FltStDeb' */

/* BMSFailLevel2����״̬ */
MONPRM volatile uint8 VDAG_BMSSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S133>/FltStDeb' */

/* BMSFailLevel3����״̬ */
MONPRM volatile uint8 VDAG_BMSUndrVoltFltSt_enum = ((uint8)0U);/* '<S136>/FltStDeb' */

/* BMSPackǷѹ����״̬ */
MONPRM volatile uint8 VDAG_BrkPedShtBattFltSt_enum = ((uint8)0U);/* '<S514>/FltStDeb' */

/* �ƶ�̤��̵�Դ����״̬ */
MONPRM volatile uint8 VDAG_BrkPedShtGndFltSt_enum = ((uint8)0U);/* '<S512>/FltStDeb' */

/* �ƶ�̤��̵ع���״̬ */
MONPRM volatile uint8 VDAG_BrkSwCrsChkCnt_cnt = ((uint8)0U);/* '<S507>/Data Type Conversion' */

/* �ƶ������໥У�������� */
MONPRM volatile uint8 VDAG_BrkSwCrsChkFltSt_enum = ((uint8)0U);/* '<S513>/FltStDeb' */

/* �ƶ������໥У�����״̬ */
MONPRM volatile uint8 VDAG_CellUndrVoltFltSt_enum = ((uint8)0U);/* '<S137>/FltStDeb' */

/* BMSCellǷѹ����״̬ */
MONPRM volatile uint8 VDAG_DCCCmdTmOutFltSt_enum = ((uint8)0U);/* '<S279>/FltStDeb' */

/* DCDCģʽָ����Ӧ��ʱ����״̬ */
MONPRM volatile uint8 VDAG_DCCInVoltLoFltSt_enum = ((uint8)0U);/* '<S280>/FltStDeb' */

/* DCDC�����ѹ�͹���״̬ */
MONPRM volatile uint8 VDAG_DCCModeFltFltSt_enum = ((uint8)0U);/* '<S278>/FltStDeb' */

/* DCDCModeFault����״̬ */
MONPRM volatile uint8 VDAG_DCCSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S274>/FltStDeb' */

/* DCDCFailLevel1����״̬ */
MONPRM volatile uint8 VDAG_DCCSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S275>/FltStDeb' */

/* DCDCFailLevel2����״̬ */
MONPRM volatile uint8 VDAG_DCCSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S276>/FltStDeb' */

/* DCDCFailLevel3����״̬ */
MONPRM volatile uint8 VDAG_DCCSysFailLvl4FltSt_enum = ((uint8)0U);/* '<S277>/FltStDeb' */

/* DCDCFailLevel4����״̬ */
MONPRM volatile uint8 VDAG_DCSChrgReqFltSt_enum = ((uint8)0U);/* '<S128>/FltStDeb' */

/* DCSChargeRequest����״̬ */
MONPRM volatile uint8 VDAG_DCSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S138>/FltStDeb' */

/* DCSCmd��ʱ����״̬ */
MONPRM volatile uint8 VDAG_DCSFailStaFltSt_enum = ((uint8)0U);/* '<S126>/FltStDeb' */

/* DCSFailState����״̬ */
MONPRM volatile uint8 VDAG_DCSInletConnectFltSt_enum = ((uint8)0U);/* '<S127>/FltStDeb' */

/* DCS��ǹ����״̬ */
MONPRM volatile uint8 VDAG_DCSModeFailFltSt_enum = ((uint8)0U);/* '<S129>/FltStDeb' */

/* DCSModeFail����״̬ */
MONPRM volatile uint8 VDAG_EHBFltLvl1FltSt_enum = ((uint8)0U);/* '<S439>/FltStDeb' */

/* EHB1������״̬ */
MONPRM volatile uint8 VDAG_EHBFltLvl2FltSt_enum = ((uint8)0U);/* '<S440>/FltStDeb' */

/* EHB2������״̬ */
MONPRM volatile uint8 VDAG_EHBFltLvl3FltSt_enum = ((uint8)0U);/* '<S441>/FltStDeb' */

/* EHB3������״̬ */
MONPRM volatile uint8 VDAG_EHBFltLvl4FltSt_enum = ((uint8)0U);/* '<S433>/FltStDeb' */

/* EHB4������״̬ */
MONPRM volatile uint8 VDAG_EHBFltLvl5FltSt_enum = ((uint8)0U);/* '<S442>/FltStDeb' */

/* EHB5������״̬ */
MONPRM volatile uint8 VDAG_ESCFltLvl1FltSt_enum = ((uint8)0U);/* '<S444>/FltStDeb' */

/* ESC1������״̬ */
MONPRM volatile uint8 VDAG_ESCFltLvl2FltSt_enum = ((uint8)0U);/* '<S434>/FltStDeb' */

/* ESC2������״̬ */
MONPRM volatile uint8 VDAG_ESCFltLvl3FltSt_enum = ((uint8)0U);/* '<S435>/FltStDeb' */

/* ESC3������״̬ */
MONPRM volatile uint8 VDAG_ESCFltLvl4FltSt_enum = ((uint8)0U);/* '<S443>/FltStDeb' */

/* ESC4������״̬ */
MONPRM volatile uint8 VDAG_ESCFltLvl5FltSt_enum = ((uint8)0U);/* '<S436>/FltStDeb' */

/* ESC5������״̬ */
MONPRM volatile uint8 VDAG_ESCVehSpdInvldFltSt_enum = ((uint8)0U);/* '<S438>/FltStDeb' */

/* ����ʧЧ����״̬ */
MONPRM volatile boolean VDAG_EmgcyShtdwn_flg = false;/* '<S88>/Switch30' */
MONPRM volatile uint16 VDAG_ErrCode_enum = ((uint16)0U);/* '<S86>/Err_State' */
MONPRM volatile boolean VDAG_FanFullSpdOn_flg = false;/* '<S88>/Switch3' */
MONPRM volatile boolean VDAG_FbdACC_flg = false;/* '<S88>/Switch28' */
MONPRM volatile boolean VDAG_FbdACChrg_flg = false;/* '<S88>/Switch32' */
MONPRM volatile boolean VDAG_FbdACDcha_flg = false;/* '<S88>/Switch34' */
MONPRM volatile boolean VDAG_FbdAC_flg = false;/* '<S88>/Switch35' */
MONPRM volatile boolean VDAG_FbdCC_flg = false;/* '<S88>/Switch26' */
MONPRM volatile boolean VDAG_FbdDCChrg_flg = false;/* '<S88>/Switch33' */
MONPRM volatile boolean VDAG_FbdDCDC_flg = false;/* '<S88>/Switch31' */
MONPRM volatile boolean VDAG_FbdDRGr_flg = false;/* '<S88>/Switch25' */
MONPRM volatile boolean VDAG_FbdDrvTq_flg = false;/* '<S88>/Switch23' */
MONPRM volatile boolean VDAG_FbdHV_flg = false;/* '<S88>/Switch29' */
MONPRM volatile boolean VDAG_FbdLSP_flg = false;/* '<S88>/Switch27' */
MONPRM volatile boolean VDAG_FltLampOn_flg = false;/* '<S88>/Switch36' */
MONPRM volatile uint8 VDAG_FltLvl_enum = ((uint8)0U);/* '<S88>/MinMax' */
MONPRM volatile uint8 VDAG_GearShftInvldFltSt_enum = ((uint8)0U);/* '<S437>/FltStDeb' */

/* ��������ʧЧ����״̬ */
MONPRM volatile uint8 VDAG_HVILVoltHiFltSt_enum = ((uint8)0U);/* '<S516>/FltStDeb' */

/* ��ѹ������ѹ�߹���״̬ */
MONPRM volatile uint8 VDAG_HVILVoltLoFltSt_enum = ((uint8)0U);/* '<S515>/FltStDeb' */

/* ��ѹ������ѹ�͹���״̬ */
MONPRM volatile uint8 VDAG_HVIsoResistLoFltSt_enum = ((uint8)0U);/* '<S125>/FltStDeb' */

/* ��ѹ��ؾ�Ե����״̬ */
MONPRM volatile uint8 VDAG_INVFltLvl1FltSt_enum = ((uint8)0U);/* '<S343>/FltStDeb' */

/* INVFaultLevel1����״̬ */
MONPRM volatile uint8 VDAG_INVFltLvl2FltSt_enum = ((uint8)0U);/* '<S344>/FltStDeb' */

/* INVFaultLevel2����״̬ */
MONPRM volatile uint8 VDAG_INVFltLvl3FltSt_enum = ((uint8)0U);/* '<S345>/FltStDeb' */

/* INVFaultLevel3����״̬ */
MONPRM volatile uint8 VDAG_INVFltLvl4FltSt_enum = ((uint8)0U);/* '<S346>/FltStDeb' */

/* INVFaultLevel4����״̬ */
MONPRM volatile uint8 VDAG_INVInVoltLoFltSt_enum = ((uint8)0U);/* '<S281>/FltStDeb' */

/* INV�����ѹ�͹���״̬ */
MONPRM volatile uint8 VDAG_INVRunCmdRespFltSt_enum = ((uint8)0U);/* '<S347>/FltStDeb' */

/* INVRunָ����Ӧ��ʱ����״̬ */
MONPRM volatile boolean VDAG_LVBatLampOn_flg = false;/* '<S88>/Switch1' */
MONPRM volatile uint8 VDAG_LVBattSOCLoFltSt_enum = ((uint8)0U);/* '<S467>/FltStDeb' */

/* ����SOC�͵Ĺ���״̬ */
MONPRM volatile uint8 VDAG_LVBattSOHLoFltSt_enum = ((uint8)0U);/* '<S463>/FltStDeb' */

/* ����SOH�͵Ĺ���״̬ */
MONPRM volatile uint8 VDAG_LVBattTempHiFltSt_enum = ((uint8)0U);/* '<S464>/FltStDeb' */

/* ���ع��¹���״̬ */
MONPRM volatile uint8 VDAG_LVBattVoltHiFltSt_enum = ((uint8)0U);/* '<S466>/FltStDeb' */

/* ���ص�ѹ�߹���״̬ */
MONPRM volatile uint8 VDAG_LVBattVoltLoFltSt_enum = ((uint8)0U);/* '<S465>/FltStDeb' */

/* ���ص�ѹ�͹���״̬ */
MONPRM volatile boolean VDAG_LimpHome_flg = false;/* '<S88>/Switch2' */
MONPRM volatile boolean VDAG_LmtDrvTq_flg = false;/* '<S88>/Switch24' */
MONPRM volatile uint8 VDAG_OBCChrgReqFltSt_enum = ((uint8)0U);/* '<S381>/FltStDeb' */

/* OBCChargeRequest����״̬ */
MONPRM volatile uint8 VDAG_OBCConnectTmOutFltSt_enum = ((uint8)0U);/* '<S379>/FltStDeb' */

/* OBC���ӳ�ʱ����״̬ */
MONPRM volatile uint8 VDAG_OBCInletConnectFltSt_enum = ((uint8)0U);/* '<S384>/FltStDeb' */

/* OBC��ǹ����״̬ */
MONPRM volatile uint8 VDAG_OBCModeMsmtchFltSt_enum = ((uint8)0U);/* '<S378>/FltStDeb' */

/* OBCģʽ��ƥ�����״̬ */
MONPRM volatile uint8 VDAG_OBCS2StatFltSt_enum = ((uint8)0U);/* '<S380>/FltStDeb' */

/* OBCS2���ӳ�ʱ����״̬ */
MONPRM volatile uint8 VDAG_OBCSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S385>/FltStDeb' */

/* OBCFailLevel1����״̬ */
MONPRM volatile uint8 VDAG_OBCSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S386>/FltStDeb' */

/* OBCFailLevel2����״̬ */
MONPRM volatile uint8 VDAG_OBCSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S387>/FltStDeb' */

/* OBCFailLevel3����״̬ */
MONPRM volatile uint8 VDAG_OBCSysFailLvl4FltSt_enum = ((uint8)0U);/* '<S375>/FltStDeb' */

/* OBCFailLevel4����״̬ */
MONPRM volatile uint8 VDAG_SysPwrModeInvldFltSt_enum = ((uint8)0U);/* '<S431>/FltStDeb' */

/* PowerModeʧЧ����״̬ */
MONPRM volatile uint8 VDAG_TMSFailLvl3FltSt_enum = ((uint8)0U);/* '<S432>/FltStDeb' */

/* TMSRFailLevel3����״̬ */
MONPRM volatile uint8 VDAG_VehCrashFltSt_enum = ((uint8)0U);/* '<S486>/FltStDeb' */

/* ��ײ����״̬ */
MONPRM volatile boolean VDAG_WakeUp_flg = false;/* '<S305>/Chart' */

/* Ӳ�߻��ѻ���IBSLIN���ѱ�־ */
MONPRM volatile uint8 VDAG_WaterTempAbvThrFltSt_enum = ((uint8)0U);/* '<S531>/FltStDeb' */

/* ��ȴˮ�¹��߹���״̬ */
MONPRM volatile uint8 VDAG_WaterTempBlwThrFltSt_enum = ((uint8)0U);/* '<S530>/FltStDeb' */

/* ��ȴˮ�¹��͹���״̬ */
MONPRM volatile float32 VDSA_AcceltnIdxAvg_pct = 0.0F;/* '<S16>/AvgAcceltnIdx' */
MONPRM volatile float32 VDSA_AcceltnIdxRaw_pct = 0.0F;/* '<S16>/Saturation1' */
MONPRM volatile float32 VDSA_BrkPedPstnAvg_pct = 0.0F;/* '<S16>/AvgBrkPedPstn' */
MONPRM volatile float32 VDSA_DrvSprtIdx_pct = 0.0F;/* '<S16>/Saturation2' */
MONPRM volatile boolean VDSA_SprtIdxHldAcc_flg = false;/* '<S16>/Logical Operator3' */
MONPRM volatile boolean VDSA_SprtIdxHldBrk_flg = false;/* '<S16>/Logical Operator6' */
MONPRM volatile float32 VDSA_TqCalcAcceltn_mps2 = 0.0F;/* '<S16>/Divide1' */
MONPRM volatile boolean VEMS_ACCMOprtCmd_flg = false;/* '<S29>/ACCMEnble' */

/* ʹ��ACCM */
MONPRM volatile float32 VEMS_AccPwrRaw_kW = 0.0F;/* '<S30>/MinMax4' */
MONPRM volatile float32 VEMS_CellTempSyn_C = 0.0F;/* '<S82>/Switch1' */
MONPRM volatile float32 VEMS_CellUndrVoltDrtFac_c = 0.0F;/* '<S27>/Saturation3' */
MONPRM volatile float32 VEMS_ChrgCurFbKi_A = 0.0F;/* '<S79>/Saturation' */
MONPRM volatile float32 VEMS_ChrgCurFbKp_A = 0.0F;/* '<S79>/Product2' */
MONPRM volatile float32 VEMS_ChrgCurFb_A = 0.0F;/* '<S79>/Saturation2' */
MONPRM volatile float32 VEMS_ChrgOvrshtPwr_kW = 0.0F;/* '<S26>/Add1' */
MONPRM volatile float32 VEMS_ChrgPwrFbKi_kW = 0.0F;/* '<S45>/Saturation' */
MONPRM volatile float32 VEMS_ChrgPwrFbKp_kW = 0.0F;/* '<S45>/Product2' */
MONPRM volatile float32 VEMS_ChrgPwrFb_kW = 0.0F;/* '<S26>/Merge' */
MONPRM volatile float32 VEMS_DchaCurFbKi_A = 0.0F;/* '<S80>/Saturation' */
MONPRM volatile float32 VEMS_DchaCurFbKp_A = 0.0F;/* '<S80>/Product2' */
MONPRM volatile float32 VEMS_DchaCurFb_A = 0.0F;/* '<S80>/Saturation2' */
MONPRM volatile float32 VEMS_DchaOvrshtPwr_kW = 0.0F;/* '<S28>/Add1' */
MONPRM volatile float32 VEMS_DchaPwrFbKi_kW = 0.0F;/* '<S63>/Saturation' */
MONPRM volatile float32 VEMS_DchaPwrFbKp_kW = 0.0F;/* '<S63>/Product2' */
MONPRM volatile float32 VEMS_DchaPwrFb_kW = 0.0F;/* '<S28>/Merge' */
MONPRM volatile float32 VEMS_HVBatPwrAct_kW = 0.0F;/* '<S30>/Gain1' */
MONPRM volatile float32 VEMS_MaxChrgCur_A = 0.0F;/* '<S25>/Saturation4' */
MONPRM volatile float32 VEMS_MaxChrgPwr2MotRaw_kW = 0.0F;/* '<S25>/Add7' */
MONPRM volatile float32 VEMS_MaxChrgPwr2Mot_kW = 0.0F;/* '<S26>/MinMax2' */
MONPRM volatile float32 VEMS_MaxChrgPwr_kW = 0.0F;/* '<S25>/Product2' */
MONPRM volatile float32 VEMS_MaxConChrgCur_A = 0.0F;/* '<S25>/MinMax1' */
MONPRM volatile float32 VEMS_MaxConDchaCur_A = 0.0F;/* '<S27>/MinMax1' */
MONPRM volatile float32 VEMS_MaxDchaCur_A = 0.0F;/* '<S27>/Saturation4' */
MONPRM volatile float32 VEMS_MaxDchaPwr2MotRaw_kW = 0.0F;/* '<S27>/Add7' */
MONPRM volatile float32 VEMS_MaxDchaPwr2Mot_kW = 0.0F;/* '<S28>/MinMax2' */
MONPRM volatile float32 VEMS_MaxDchaPwr_kW = 0.0F;/* '<S27>/Product2' */
MONPRM volatile float32 VEMS_MaxInsChrgCur_A = 0.0F;/* '<S25>/MinMax3' */
MONPRM volatile float32 VEMS_MaxInsDchaCur_A = 0.0F;/* '<S27>/MinMax3' */
MONPRM volatile boolean VEMS_TMSActSOCEnbl_flg = false;/* '<S76>/Switch1' */

/* SOC�Ƿ�����TMS */
MONPRM volatile boolean VEMS_TMSPwrEnbl_flg = false;/* '<S29>/Switch3' */

/* �����Ƿ�����TMS */
MONPRM volatile float32 VEMS_TMSUsePwr_kW = 0.0F;/* '<S29>/Subtract' */

/* TMS���ù��� */
MONPRM volatile boolean VEMS_UseConChrgCur_flg = false;/* '<S36>/Switch4' */
MONPRM volatile boolean VEMS_UseConDchaCur_flg = false;/* '<S54>/Switch4' */
MONPRM volatile boolean VGSM_AsstDrvFbShft_flg = false;/* '<S1495>/Logical Operator2' */

/* �淶��ACC/CC��ֹ��λ���� */
MONPRM volatile boolean VGSM_DRFlt2N_flg = false;/* '<S1494>/Switch1' */

/* �淶����������������־λ */
MONPRM volatile boolean VGSM_EPBAplyFlt_flg = false;/* '<S1487>/EPBLogical' */

/* ����P-EPB������� */
MONPRM volatile boolean VGSM_EPBRelsFlt_flg = false;/* '<S1487>/EPBLogical' */

/* ����P-EPB�ͷŹ��� */
MONPRM volatile boolean VGSM_GrD2PExcdTm_flg = false;/* '<S1649>/Chart' */

/* D����P����ʱ��N */
MONPRM volatile boolean VGSM_GrNReq2P_flg = false;/* '<S1494>/Switch2' */

/* N���ǻ��������P������ */
MONPRM volatile boolean VGSM_GrR2PExcdTm_flg = false;/* '<S1646>/Chart' */

/* R����P����ʱ��N */
MONPRM volatile boolean VGSM_HldGearP_flg = false;/* '<S1494>/Switch' */

/* �淶������P����־λ */
MONPRM volatile boolean VGSM_INVRunEnbl_flg = false;/* '<S1497>/Chart' */

/* �淶��INVʹ�ܿ��ƣ�����Ť�ؿ��ƣ�-VCU_1_EnaInvRun */
MONPRM volatile uint8 VGSM_PGrSwSts_enum = ((uint8)0U);/* '<S1495>/Switch2' */

/* �淶��P����������־λ-VCU_PGearSwcst */
MONPRM volatile boolean VGSM_ReqEPBAply_flg = false;/* '<S1496>/Logical Operator6' */

/* �淶��EPB���������־λ */
MONPRM volatile boolean VGSM_ReqEPBRels_flg = false;/* '<S1496>/Logical Operator4' */

/* �淶��EPB�ͷ������־λ */
MONPRM volatile EnumEPBReq VGSM_ReqEPB_enum = EnumEPBReq_NoCmd;/* '<S1487>/Switch' */

/* �淶��EPB�����ź�-VCUF_ReqEPB */
MONPRM volatile EnumTgtGearPstn VGSM_ShftTgtGrReq_enum = EnumTgtGearPstn_NoReq;/* '<S1495>/Data Type Conversion1' */

/* ������Ŀ�굵λ 0-NoCmd 1-P 2-N 3-D 4-R  */
MONPRM volatile EnumGearPstn VGSM_VehActGearPstn_enum = EnumGearPstn_P;/* '<S1488>/Switch1' */

/* �淶��ʵ�ʵ�λ-VCU_VhclActlGearPos */
MONPRM volatile boolean VGSM_VehEPBStErr_flg = false;/* '<S1487>/Logical Operator' */

/* �淶��P������PGear error-VCU_VhclPGearError */
MONPRM volatile EnumTgtGearPstn VGSM_VehTgtGrReq_enum = EnumTgtGearPstn_NoReq;/* '<S1496>/Data Type Conversion1' */

/* �淶:Ŀ�굵λ */
MONPRM volatile uint8 VGSM_VehTgtGrTrnsfr_enum = ((uint8)0U);/* '<S1535>/Switch' */

/* �淶�����������ź� */
MONPRM volatile uint8 VHMI_12VBatLowVolSta_enum = ((uint8)0U);/* '<S575>/Switch' */
MONPRM volatile float32 VHMI_GrDSldDist_m = 0.0F;/* '<S589>/Saturation' */

/* D��������� */
MONPRM volatile boolean VHMI_GrDSldSw_flg = false;/* '<S589>/Logical Operator' */

/* D�����¼���/�����־ */
MONPRM volatile float32 VHMI_GrRSldDist_m = 0.0F;/* '<S589>/Saturation1' */

/* R��ǰ����� */
MONPRM volatile boolean VHMI_GrRSldSw_flg = false;/* '<S589>/Logical Operator4' */

/* R�����¼���/�����־ */
MONPRM volatile uint8 VHMI_InfoDisp_enum = ((uint8)0U);/* '<S578>/Arbitration' */

/* �Ǳ���ֵ */
MONPRM volatile boolean VHVM_ACChrgEnbl_flg = false;/* '<S727>/Logical Operator8' */

/* ������������������ */
MONPRM volatile boolean VHVM_ACChrging2Stop_flg = false;/* '<S721>/AND' */

/* ���������ת�Ƶ����ֹͣ��־λ */
MONPRM volatile boolean VHVM_ACDchaEnbl_flg = false;/* '<S727>/Logical Operator10' */

/* �����ŵ������������ */
MONPRM volatile boolean VHVM_ACDschrging2Stop_flg = false;/* '<S721>/AND7' */

/* �����ŵ���ת�Ƶ��ŵ�ֹͣ��־λ */
MONPRM volatile EnumBMSSdnCmd VHVM_BMSShutdown_enum = EnumBMSSdnCmd_Normal;/* '<S700>/Data Type Conversion10' */

/* VCU�ر�BMSָ���ӦCAN�źţ�VCU_BMS_Shutdown */
MONPRM volatile EnumBMSWakeUpMd VHVM_BMSWakeUpMode_enum = EnumBMSWakeUpMd_Invld;/* '<S700>/Data Type Conversion8' */

/* VCU����BMS�ķ�ʽ��ӦCAN�źţ�VCU_BMS_WakeupMode */
MONPRM volatile boolean VHVM_Bat2DrvTrainEnbl_flg = false;/* '<S700>/MainState' */

/* VCU�������̵���ָ���ӦCAN�źţ�VCU_Bat2DrvTrainEnb */
MONPRM volatile EnumChrgAllwCmd VHVM_ChrgAllowCmd_enum =
  EnumChrgAllwCmd_NotAllwd;            /* '<S700>/Data Type Conversion12' */

/* VCU����������ָ���ӦCAN�źţ�VCU_ChrgAllowCmd */
MONPRM volatile uint8 VHVM_ChrgEnaAC_enum = ((uint8)0U);/* '<S700>/MainState' */

/* VCU����OBC�������ʹ��ָ���ӦCAN�źţ�VCU_ChrgEna_AC */
MONPRM volatile boolean VHVM_ChrgEnaDC_flg = false;/* '<S700>/MainState' */

/* VCU����BMSֱ�����ʹ��ָ���ӦCAN�źţ�VCU_ChrgEna_DC */
MONPRM volatile float32 VHVM_DCCBuckLVVolt_V = 0.0F;/* '<S700>/MainState' */

/* VCU����DCDC BUCK��ѹֵ��ӦCAN�źţ�VCU_DCCBuckLV_Vol */
MONPRM volatile EnumDCCOprtCmd VHVM_DCCOprtCmd_enum = EnumDCCOprtCmd_Off;/* '<S700>/Data Type Conversion6' */

/* VCU����DCDC����ģʽָ���ӦCAN�źţ�VCU_DCCOprtCmd */
MONPRM volatile boolean VHVM_DCChrgEnbl_flg = false;/* '<S727>/Logical Operator2' */

/* ֱ���������������� */
MONPRM volatile boolean VHVM_DCChrging2Over_flg = false;/* '<S721>/AND1' */

/* ֱ�������ת�Ƶ���������־λ */
MONPRM volatile boolean VHVM_ECUSleepAllwd_flg = false;/* '<S700>/MainState' */

/* ����ײ����߱�־λ */
MONPRM volatile boolean VHVM_EmgcySdn_flg = false;/* '<S700>/MainState' */

/* VCU��INV���ͽ����µ�ָ��(INVǿ��ͣ��)��ӦCAN�źţ�VCU_1_EmShutDown */
MONPRM volatile boolean VHVM_EnaDisChg_flg = false;/* '<S700>/MainState' */

/* VCU����INVй��ָ���ӦCAN�źţ�VCU_1_EnaDisChg */
MONPRM volatile boolean VHVM_EngyExtrmLo_flg = false;/* '<S703>/Logical Operator17' */

/* ����������ͱ�־λ */
MONPRM volatile boolean VHVM_INVEnbl_flg = false;/* '<S700>/MainState' */

/* VCUӲ�߻���INV */
MONPRM volatile boolean VHVM_INVPreprogmFlg_flg = false;/* '<S722>/Switch1' */

/* INVԤ����������� */
MONPRM volatile float32 VHVM_MaxChrgCurntDC_A = 0.0F;/* '<S700>/MainState' */

/* VCU����BMSֱ�������������ӦCAN�źţ�VCU_MaxChrgCrnt_DC */
MONPRM volatile float32 VHVM_MaxChrgVoltDC_V = 0.0F;/* '<S700>/MainState' */

/* VCU����BMSֱ���������ѹ��ӦCAN�źţ�VCU_MaxChrgVol_DC */
MONPRM volatile float32 VHVM_MaxHVDCCurntAC_A = 0.0F;/* '<S700>/MainState' */

/* VCU����OBC���������������ӦCAN�źţ�VCU_MaxHVDC_Cur_AC */
MONPRM volatile float32 VHVM_MaxHVDCVoltAC_V = 0.0F;/* '<S700>/MainState' */

/* VCU����OBC�����������ѹ��ӦCAN�źţ�VCU_MaxHVDC_Vol_AC */
MONPRM volatile EnumOBCOprtCmd VHVM_OBCOprtCmd_enum = EnumOBCOprtCmd_Standby;/* '<S701>/Data Type Conversion4' */

/* VCU����OBC����ģʽָ���ӦCAN�źţ�VCU_OBCOprtCmd */
MONPRM volatile EnumPTActMd VHVM_PTActOprtMode_enum = EnumPTActMd_OFF;/* '<S700>/Data Type Conversion4' */

/* ��ѹPT״̬ */
MONPRM volatile boolean VHVM_PTRdy2PTStdby_flg = false;/* '<S724>/Switch1' */

/* PTRdy��PTStdby��־λ */
MONPRM volatile boolean VHVM_PTStdby2PTRdy_flg = false;/* '<S724>/Switch' */

/* PTStdby��PTRdy��־λ */
MONPRM volatile boolean VHVM_PowUpSelfChek_flg = false;/* '<S725>/Switch' */

/* ��ѹ�Լ��־λ */
MONPRM volatile boolean VHVM_PwrOn2PwrDwn_flg = false;/* '<S726>/Switch' */

/* ��ѹ�µ����������־λ������/����/������ */
MONPRM volatile boolean VHVM_SOPExtrmLo_flg = false;/* '<S703>/Relational Operator4' */

/* ���SOP���ͣ����ڹر�DCDC */
MONPRM volatile EnumSysSta VHVM_SysSta_enum = EnumSysSta_Sleep;/* '<S700>/Data Type Conversion2' */

/* ��ѹ��״̬ */
MONPRM volatile uint8 VHVM_TBOX2OBC_emun = ((uint8)0U);/* '<S701>/Switch1' */

/* TBOXԶ�̳�ŵ�ָ�� */
MONPRM volatile EnumVCUMode VHVM_VCUMode_enum = EnumVCUMode_PwrOff;/* '<S700>/Data Type Conversion' */

/* ��ѹ��ת̬ */
MONPRM volatile boolean VHVM_VehHalt_flg = false;/* '<S716>/Switch4' */

/* ����ֹͣ��־λ�����ټ��䣩 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpACChrg_flg = false;/* '<S727>/Logical Operator16' */

/* ������绽���ϵ� */
MONPRM volatile boolean VHVM_WakeUp2PwrUpACDcha_flg = false;/* '<S727>/Logical Operator26' */

/* �����ŵ绽���ϵ� */
MONPRM volatile boolean VHVM_WakeUp2PwrUpDCChrg_flg = false;/* '<S727>/Logical Operator4' */

/* ֱ����绽���ϵ� */
MONPRM volatile boolean VHVM_WakeUp2PwrUpIBS_flg = false;/* '<S727>/Logical Operator6' */

/* IBS�����ϵ� */
MONPRM volatile boolean VHVM_WakeUp2PwrUpKL15_flg = false;/* '<S727>/Logical Operator' */

/* K15�����ϵ� */
MONPRM volatile boolean VHVM_WakeUp2PwrUp_flg = false;/* '<S727>/Switch' */

/* ���ѵ��ϸ�ѹ�������㣨����Դ������+��ѹ�Լ�ͨ���� */
MONPRM volatile boolean VHVM_WakeUpBMS_flg = false;/* '<S700>/MainState' */

/* VCUӲ�߻���BMS */
MONPRM volatile boolean VHVM_WakeUpVCU_flg = false;/* '<S728>/Switch' */

/* ���ߵ������������� */
MONPRM volatile boolean VIBS_BMSBatSOCAllow_flg = false;/* '<S951>/Switch3' */

/* �������SOC�������־λ_versteckt */
MONPRM volatile boolean VIBS_ChgNumAllow_flg = false;/* '<S951>/AND' */

/* ������������־λ_versteckt */
MONPRM volatile uint8 VIBS_ChgNum_cnt = ((uint8)0U);/* '<S951>/Switch2' */

/* IBS�������_versteckt */
MONPRM volatile boolean VIBS_ChrgBascCond_flg = false;/* '<S951>/Logical Operator2' */

/* ��������������㣨�����������ѹ��_versteckt */
MONPRM volatile boolean VIBS_ChrgEnbl_flg = false;/* '<S951>/Logical Operator7' */

/* IBS���ʹ�ܱ�־λ_versteckt */
MONPRM volatile boolean VIBS_ChrgOver_flg = false;/* '<S949>/ChrgSt' */

/* IBS���������־λ_versteckt */
MONPRM volatile float32 VIBS_ChrgVoltThr_V = 0.0F;/* '<S952>/VoltState' */

/* �����ѹ��ֵ_versteckt */
MONPRM volatile float32 VIBS_EnvirTemp_C = 0.0F;/* '<S971>/Switch' */

/* IBS�����¶�_versteckt */
MONPRM volatile uint8 VIBS_FailChgNum_cnt = ((uint8)0U);/* '<S951>/Switch5' */

/* IBS����ʧ�ܴ���_versteckt */
MONPRM volatile boolean VIBS_FbRctWup_flg = false;/* '<S951>/Logical Operator6' */

/* IBS��ֹRTC���ѱ�־λ_versteckt */
MONPRM volatile boolean VIBS_HVReq_flg = false;/* '<S951>/Switch' */

/* IBS�����ϸ�ѹ��־λ_versteckt */
MONPRM volatile float32 VIBS_HwKL30_V = 0.0F;/* '<S970>/Switch' */

/* �˲����KL30��ѹ_versteckt */
MONPRM volatile boolean VIBS_NMReq_flg = false;/* '<S958>/Switch4' */

/* IBS���������־λ_versteckt */
MONPRM volatile uint16 VIBS_NextRtcWupThr_min = ((uint16)0U);/* '<S952>/Switch1' */

/* �´β��绽��RTC��ʱ��_versteckt */
MONPRM volatile EnumIBSChrgSt VIBS_RTCChrgSt_enum = EnumIBSChrgSt_Idle;/* '<S949>/Data Type Conversion' */

/* IBS����״̬_versteckt */
MONPRM volatile boolean VIBS_RTCWakeup_flg = false;/* '<S976>/Chart' */

/* RTC���ѱ�־λ�����ӳ�ʱ�䣩_versteckt */
MONPRM volatile boolean VIBS_SleepAllwd_flg = false;/* '<S951>/SleepAllwd' */

/* IBS����ײ����߱�־λ_versteckt */
MONPRM volatile uint16 VIBS_WupChgTmThr_min = ((uint16)0U);/* '<S952>/Switch2' */

/* IBS����ʱ����ֵ_versteckt */
MONPRM volatile boolean VIBS_WupVoltAllow_flg = false;/* '<S972>/Switch4' */

/* KL30��ѹ�����־λ_versteckt */
MONPRM volatile boolean VIPC_ACCCfgd_flg = false;/* '<S827>/Switch8' */
MONPRM volatile boolean VIPC_AccPed1Flt_flg = false;/* '<S831>/Logical Operator1' */
MONPRM volatile boolean VIPC_AccPed1LrnDwnActv_flg = false;/* '<S841>/Relational Operator' */
MONPRM volatile boolean VIPC_AccPed1LrnUpActv_flg = false;/* '<S834>/Logical Operator5' */
MONPRM volatile float32 VIPC_AccPed1MinPstnLrnd_pct = 0.0F;/* '<S834>/Switch2' */
MONPRM volatile float32 VIPC_AccPed1NormzAvg_pct = 0.0F;/* '<S840>/Switch' */
MONPRM volatile float32 VIPC_AccPed1NormzPstn_pct = 0.0F;/* '<S831>/Switch5' */
MONPRM volatile float32 VIPC_AccPed1SclPstn_pct = 0.0F;/* '<S835>/Divide1' */
MONPRM volatile boolean VIPC_AccPed2Flt_flg = false;/* '<S831>/Logical Operator2' */
MONPRM volatile boolean VIPC_AccPed2LrnDwnActv_flg = false;/* '<S845>/Relational Operator' */
MONPRM volatile boolean VIPC_AccPed2LrnUpActv_flg = false;/* '<S836>/Logical Operator5' */
MONPRM volatile float32 VIPC_AccPed2MinPstnLrnd_pct = 0.0F;/* '<S836>/Switch2' */
MONPRM volatile float32 VIPC_AccPed2NormzAvg_pct = 0.0F;/* '<S844>/Switch' */
MONPRM volatile float32 VIPC_AccPed2NormzPstn_pct = 0.0F;/* '<S831>/Switch7' */
MONPRM volatile float32 VIPC_AccPed2SclPstn_pct = 0.0F;/* '<S837>/Divide5' */
MONPRM volatile boolean VIPC_AccPedPstnVld_flg = false;/* '<S833>/Switch3' */
MONPRM volatile float32 VIPC_AccPedPstn_pct = 0.0F;/* '<S829>/MinMax3' */
MONPRM volatile uint8 VIPC_AccPedSnsrSta_enum = ((uint8)0U);/* '<S833>/Switch3' */
MONPRM volatile boolean VIPC_AccPedStkActv_flg = false;/* '<S832>/Logical Operator6' */
MONPRM volatile boolean VIPC_AccPedStkBrkPrsd_flg = false;/* '<S859>/Switch4' */
MONPRM volatile float32 VIPC_AccPedStkPstn_pct = 0.0F;/* '<S832>/MinMax' */
MONPRM volatile boolean VIPC_AccPedStkStab_flg = false;/* '<S861>/Relational Operator' */
MONPRM volatile float32 VIPC_AccPedWghtAvg_pct = 0.0F;/* '<S858>/Switch' */
MONPRM volatile float32 VIPC_AccPedWghtPstn_pct = 0.0F;/* '<S833>/Switch3' */
MONPRM volatile float32 VIPC_AccPedZeroPstn_pct = 0.0F;/* '<S832>/Switch' */
MONPRM volatile boolean VIPC_BrkPedPstnVld_flg = false;/* '<S824>/Logical Operator8' */
MONPRM volatile float32 VIPC_BrkPedPstn_pct = 0.0F;/* '<S824>/Saturation1' */
MONPRM volatile boolean VIPC_BrkSwActv_flg = false;/* '<S824>/Logical Operator' */
MONPRM volatile boolean VIPC_CCSCfgd_flg = false;/* '<S827>/Switch1' */
MONPRM volatile boolean VIPC_CrpCtrlCfgd_flg = false;/* '<S827>/Switch2' */
MONPRM volatile EnumCrpModeAct VIPC_CrpModeAct_enum = EnumCrpModeAct_Open;/* '<S826>/Switch12' */
MONPRM volatile EnumDrvModeAct VIPC_DrvModeAct_enum = EnumDrvModeAct_Invalid;/* '<S826>/Switch13' */
MONPRM volatile uint8 VIPC_DrvPwrIntnsty_pct = ((uint8)0U);/* '<S826>/Switch25' */
MONPRM volatile boolean VIPC_DrvSw_flg = false;/* '<S829>/Relational Operator3' */
MONPRM volatile boolean VIPC_EPBAppld_flg = false;/* '<S825>/Logical Operator2' */
MONPRM volatile boolean VIPC_EPBReld_flg = false;/* '<S825>/Logical Operator1' */
MONPRM volatile boolean VIPC_HDCCfgd_flg = false;/* '<S827>/Switch3' */
MONPRM volatile EnumRegenModeAct VIPC_RegenModeAct_enum = EnumRegenModeAct_Off;/* '<S826>/Switch15' */
MONPRM volatile uint8 VIPC_RegenPwrIntnsty_pct = ((uint8)0U);/* '<S826>/Switch28' */
MONPRM volatile boolean VIPC_SnowMode_flg = false;/* '<S826>/Switch14' */
MONPRM volatile float32 VIPC_TireRadius_m = 0.0F;/* '<S827>/TireSizeTable' */
MONPRM volatile uint8 VIPC_VehHiddenMode_enum = ((uint8)0U);/* '<S826>/VehHiddenMode' */
MONPRM volatile float32 VIPC_VehSpdDrvnMotor_kph = 0.0F;/* '<S828>/Product1' */
MONPRM volatile boolean VIPC_VehSpdDrvnVld_flg = false;/* '<S895>/Logical Operator2' */
MONPRM volatile float32 VIPC_VehSpdDrvn_kph = 0.0F;/* '<S895>/Switch7' */
MONPRM volatile boolean VIPC_VehSpdNonDrvnVld_flg = false;/* '<S896>/Logical Operator2' */
MONPRM volatile float32 VIPC_VehSpdNonDrvn_kph = 0.0F;/* '<S896>/Switch7' */
MONPRM volatile boolean VIPC_VehSpdVld_flg = false;/* '<S895>/SignalConversion' */
MONPRM volatile float32 VIPC_VehSpd_kph = 0.0F;/* '<S895>/Switch4' */
MONPRM volatile boolean VIPC_VpedAutoCrp_flg = false;/* '<S883>/Switch4' */
MONPRM volatile boolean VIPC_ZeroPstnRst_flg = false;/* '<S832>/Logical Operator3' */
MONPRM volatile boolean VIPC_iTPMSCfgd_flg = false;/* '<S827>/Switch4' */
MONPRM volatile float32 VIPM_HwAccPedCh1SuplyVolt_mV = 0.0F;/* '<S1445>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh1Volt_mV = 0.0F;/* '<S1446>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh2SuplyVolt_mV = 0.0F;/* '<S1447>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh2Volt_mV = 0.0F;/* '<S1448>/MinMax1' */
MONPRM volatile boolean VIPM_HwBMSWakeup_flg = false;/* '<S1449>/Switch4' */
MONPRM volatile boolean VIPM_HwBrkSwHi_flg = false;/* '<S1450>/Switch4' */
MONPRM volatile boolean VIPM_HwBrkSwLo_flg = false;/* '<S1451>/Switch4' */
MONPRM volatile boolean VIPM_HwCrpModeSw_flg = false;/* '<S1452>/Switch4' */
MONPRM volatile boolean VIPM_HwDrvModeSw_flg = false;/* '<S1453>/Switch4' */
MONPRM volatile boolean VIPM_HwEmgcyShutOff_flg = false;/* '<S1454>/Switch4' */
MONPRM volatile boolean VIPM_HwKL15A_flg = false;/* '<S1455>/Switch4' */
MONPRM volatile boolean VIPM_HwKL15B_flg = false;/* '<S1456>/Switch4' */
MONPRM volatile uint16 VIPM_HwKL30_mV = ((uint16)0U);/* '<S1457>/MinMax1' */
MONPRM volatile boolean VIPM_HwOBCWakeup_flg = false;/* '<S1458>/Switch4' */
MONPRM volatile boolean VIPM_HwRearFogLampSwt_flg = false;/* '<S1459>/Switch4' */
MONPRM volatile EnumPGearSwSts VIPM_HwShftPstnSwSts_enum = EnumPGearSwSts_Reld;/* '<S1460>/Switch4' */
MONPRM volatile uint16 VIPM_HwShftPstnSw_Ohm = ((uint16)0U);/* '<S1442>/HwShftPstnSw' */
MONPRM volatile boolean VIPM_HwVehCrash_flg = false;/* '<S1461>/Switch4' */
MONPRM volatile float32 VNVM_AvgPwrCnsm_kWh100km = 0.0F;/* '<S1443>/Add2' */

/* _versteckt */
MONPRM volatile float32 VNVM_AvgSOCCnsmWght_pctp100km = 0.0F;/* '<S1443>/Add6' */

/* _versteckt */
MONPRM volatile EnumCrpModeAct VNVM_CrpModeAct_enum = EnumCrpModeAct_Open;/* '<S1443>/Data Type Conversion1' */

/* _versteckt */
MONPRM volatile EnumDrvModeAct VNVM_DrvModeAct_enum = EnumDrvModeAct_Invalid;/* '<S1443>/Data Type Conversion23' */

/* _versteckt */
MONPRM volatile uint8 VNVM_DrvPwrIntnsty_pct = ((uint8)0U);/* '<S1443>/Selector6' */

/* _versteckt */
MONPRM volatile float32 VNVM_DynRmnMilEst_km = 0.0F;/* '<S1443>/Gain2' */

/* _versteckt */
MONPRM volatile uint8 VNVM_EEWritten_nu = ((uint8)0U);/* '<S1443>/Selector13' */

/* _versteckt */
MONPRM volatile uint8 VNVM_IBSChrgFailNum_cnt = ((uint8)0U);/* '<S1443>/Selector1' */

/* _versteckt */
MONPRM volatile uint8 VNVM_IBSChrgNum_cnt = ((uint8)0U);/* '<S1443>/Selector' */

/* _versteckt */
MONPRM volatile EnumRegenModeAct VNVM_RegenModeAct_enum = EnumRegenModeAct_Off;/* '<S1443>/Data Type Conversion24' */

/* _versteckt */
MONPRM volatile uint8 VNVM_RegenPwrIntnsty_pct = ((uint8)0U);/* '<S1443>/Selector7' */

/* _versteckt */
MONPRM volatile EnumXWhlDistErrRefSt VNVM_XWhlDistErrRefStat_enum =
  EnumXWhlDistErrRefSt_Init;           /* '<S1443>/Data Type Conversion22' */

/* _versteckt */
MONPRM volatile float32 VNVM_XWhlDistErrRef_mpkm = 0.0F;/* '<S1443>/Add1' */

/* _versteckt */
MONPRM volatile boolean VNVM_iTPMSWrng_flg = false;/* '<S1443>/Data Type Conversion21' */

/* _versteckt */
MONPRM volatile boolean VOPM_HwWakeupBMS_flg = false;/* '<S1474>/Switch4' */
MONPRM volatile float32 VRMEAvgPwrCnsm15km_kWhpkm = 0.0F;/* '<S909>/Signal Copy2' */

/* 15kmƽ��Pwr�ܺ� */
MONPRM volatile float32 VRME_AvgPwrCnsm100km_kWhpkm = 0.0F;/* '<S909>/Signal Copy5' */

/* 100kmƽ��Pwr�ܺ� */
MONPRM volatile float32 VRME_AvgPwrCnsm10km_kWhpkm = 0.0F;/* '<S909>/Signal Copy1' */

/* 10kmƽ��Pwr�ܺ� */
MONPRM volatile float32 VRME_AvgPwrCnsm25km_kWhpkm = 0.0F;/* '<S909>/Signal Copy3' */

/* 25kmƽ��Pwr�ܺ� */
MONPRM volatile float32 VRME_AvgPwrCnsm50km_kWhpkm = 0.0F;/* '<S909>/Signal Copy4' */

/* 50kmƽ��Pwr�ܺ� */
MONPRM volatile float32 VRME_AvgPwrCnsm5km_kWhpkm = 0.0F;/* '<S909>/Signal Copy' */

/* 5kmƽ��Pwr�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsm100Num_pctpkm = 0.0F;/* '<S922>/Signal Copy5' */

/* ǰ100������ƽ��SOC�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsm10Num_pctpkm = 0.0F;/* '<S922>/Signal Copy1' */

/* ǰ10������ƽ��SOC�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsm15Num_pctpkm = 0.0F;/* '<S922>/Signal Copy2' */

/* ǰ15������ƽ��SOC�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsm25Num_pctpkm = 0.0F;/* '<S922>/Signal Copy3' */

/* ǰ25������ƽ��SOC�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsm50Num_pctpkm = 0.0F;/* '<S922>/Signal Copy4' */

/* ǰ50������ƽ��SOC�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsm5Num_pctpkm = 0.0F;/* '<S922>/Signal Copy' */

/* ǰ5������ƽ��SOC�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsmWght_pctpkm = 0.0F;/* '<S922>/Switch1' */

/* ��Ȩƽ��SOC�ܺ�/km */
MONPRM volatile boolean VRME_CHTCRmnMilEstV_flg = false;/* '<S904>/Logical Operator' */

/* CHTC��׼���������Ч�� */
MONPRM volatile float32 VRME_CHTCRmnMilEst_km = 0.0F;/* '<S904>/MRME_CHTCStdRmnMil_km' */

/* CHTC��׼�������ֵ */
MONPRM volatile float32 VRME_CalPwrCnsmPerTrig_kWhpkm = 0.0F;/* '<S908>/Switch4' */

/* Pwr����/��λ��̣�1km�� */
MONPRM volatile boolean VRME_CalPwrCnsmTrig_flg = false;/* '<S908>/Relational Operator1' */

/* �ۼ���̴��ڵ�λ��̣�Ĭ��1km�� */
MONPRM volatile float32 VRME_CalSOCCnsmPerTrig_pctptrig = 0.0F;/* '<S921>/Switch4' */

/* SOC����/Ŀ����� */
MONPRM volatile float32 VRME_CalSOCCnsmPerkm_pctpkm = 0.0F;/* '<S921>/Divide' */

/* Ŀ�������������Ϊ��λ��� */
MONPRM volatile float32 VRME_CalSOCCnsmTgtDist_m = 0.0F;/* '<S921>/Switch1' */

/* ��λĿ����ʻ��� */
MONPRM volatile boolean VRME_CalSOCCnsmTrig_flg = false;/* '<S921>/Relational Operator1' */

/* �ۼ���̴���Ŀ����� */
MONPRM volatile float32 VRME_DynRmnMilEstChgFac_c = 0.0F;/* '<S923>/MRME_DynEstRmnChgStp_c' */

/* ��̬�����仯ϵ�� */
MONPRM volatile float32 VRME_DynRmnMilEstTgt_km = 0.0F;/* '<S944>/Switch2' */

/* ��̬����Ŀ��ֵ */
MONPRM volatile boolean VRME_DynRmnMilEstUpdTrig_flg = false;/* '<S923>/Relational Operator2' */

/* ��������ֵ */
MONPRM volatile boolean VRME_DynRmnMilEstV_flg = false;/* '<S923>/Logical Operator1' */

/* ��̬������Ч�� */
MONPRM volatile float32 VRME_DynRmnMilEst_km = 0.0F;/* '<S943>/Switch2' */

/* ��̬�����޷�ֵ */
MONPRM volatile boolean VRME_VehStacEnbl_flg = false;/* '<S923>/Logical Operator4' */

/* ������ֹ״̬ */
MONPRM volatile float32 VRME_VehTotDistCurrCyc_km = 0.0F;/* '<S921>/Gain2' */

/* ��ǰ��ʻѭ���ۼ������ */
MONPRM volatile float32 VRME_VehTotPwrCurrCyc_kWh = 0.0F;/* '<S908>/Plus2' */

/* ��ǰ��ʻѭ������ʹ�ù��� */
MONPRM volatile float32 VRME_WLTPRmnMilEstDwLim_km = 0.0F;/* '<S921>/Product3' */

/* ��̬��������ֵ */
MONPRM volatile float32 VRME_WLTPRmnMilEstUpLim_km = 0.0F;/* '<S921>/Product2' */

/* ��̬��������ֵ */
MONPRM volatile float32 VRME_WLTPRmnMilEst_km = 0.0F;/* '<S921>/MRME_WLTPStdRmnMil_km' */

/* WLTP��׼�������ֵ */
MONPRM volatile float32 VRME_WLTPStdPwrCnsm_kWhpkm = 0.0F;/* '<S908>/Gain5' */

/* ��׼�����µ�� */
MONPRM volatile float32 VRME_WLTPStdSOCCnsm_pctpkm = 0.0F;/* '<S921>/Gain3' */

/* ��׼������SOC����/km */
MONPRM volatile float32 VTQC_ABSorESPActvTm_s = 0.0F;/* '<S1250>/MinMax' */
MONPRM volatile float32 VTQC_BrkRegenMaxTqWhl_Nm = 0.0F;/* '<S1245>/Switch17' */
MONPRM volatile float32 VTQC_BrkRegenTgtTqWhl_Nm = 0.0F;/* '<S1245>/Switch2' */
MONPRM volatile float32 VTQC_CstRegenLmtTq_Nm = 0.0F;/* '<S1243>/CstRegenLmtTq' */
MONPRM volatile float32 VTQC_DrvTqReqWhlABS_Nm = 0.0F;/* '<S1243>/MinMax1' */
MONPRM volatile float32 VTQC_DrvTqReqWhlRBS_Nm = 0.0F;/* '<S1252>/MinMax5' */
MONPRM volatile float32 VTQC_DrvTqReqWhl_Nm = 0.0F;/* '<S1244>/Switch5' */
MONPRM volatile float32 VTQC_MotorTqReq_Nm = 0.0F;/* '<S1244>/Divide' */
MONPRM volatile boolean VTQC_RBSActv_flg = false;/* '<S1253>/Switch4' */
MONPRM volatile float32 VTQD_AccelPedPstnRescl_pct = 0.0F;/* '<S1264>/Product' */
MONPRM volatile float32 VTQD_AdaptCstDeltaAcceltn_mps2 = 0.0F;/* '<S1280>/Add5' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqFF_Nm = 0.0F;/* '<S1280>/Add2' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqI_N = 0.0F;/* '<S1280>/Saturation2' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqPID_Nm = 0.0F;/* '<S1280>/Product6' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqP_N = 0.0F;/* '<S1280>/Product3' */
MONPRM volatile float32 VTQD_AdaptCstMaxTqWhl_Nm = 0.0F;/* '<S1276>/MinMax4' */
MONPRM volatile float32 VTQD_AdaptCstMinTqWhl_Nm = 0.0F;/* '<S1276>/MinMax5' */
MONPRM volatile boolean VTQD_AdaptCstRegenEnbl_flg = false;/* '<S1276>/Logical Operator9' */
MONPRM volatile float32 VTQD_AdaptCstTgtAcceltn_mps2 = 0.0F;/* '<S1282>/Switch' */
MONPRM volatile float32 VTQD_AdaptCstTqReqWhl_Nm = 0.0F;/* '<S1280>/MinMax6' */
MONPRM volatile boolean VTQD_BkwdDrv_flg = false;/* '<S1303>/Switch4' */
MONPRM volatile boolean VTQD_BrkRegenEnbl_flg = false;/* '<S1275>/Logical Operator1' */
MONPRM volatile float32 VTQD_CrpTqReqWhl_Nm = 0.0F;/* '<S1266>/Switch2' */
MONPRM volatile boolean VTQD_CstRegenEnbl_flg = false;/* '<S1275>/Logical Operator13' */
MONPRM volatile float32 VTQD_CstRegenEndPstn_pct = 0.0F;/* '<S1275>/Switch2' */
MONPRM volatile float32 VTQD_CstRegenTqReqWhl_Nm = 0.0F;/* '<S1277>/Switch4' */
MONPRM volatile float32 VTQD_DrvTqDrtFac_c = 0.0F;/* '<S1304>/Saturation' */
MONPRM volatile float32 VTQD_DrvTqReqWhlMrg_Nm = 0.0F;/* '<S1305>/Switch4' */
MONPRM volatile float32 VTQD_DrvTqReqWhlRaw_Nm = 0.0F;/* '<S1264>/Merge' */
MONPRM volatile float32 VTQD_DrvTqReqWhl_Nm = 0.0F;/* '<S1262>/Switch3' */
MONPRM volatile boolean VTQD_DsblCrp_flg = false;/* '<S1266>/Logical Operator12' */
MONPRM volatile float32 VTQD_FullPedDrvTqWhl_Nm = 0.0F;/* '<S1264>/Signal Conversion1' */
MONPRM volatile float32 VTQD_FwdPedMap_pct = 0.0F;/* '<S1267>/Switch9' */
MONPRM volatile float32 VTQD_PedalTqReqWhlRaw_Nm = 0.0F;/* '<S1261>/Add' */
MONPRM volatile uint16 VTQD_TaskRunCounter_cnt = ((uint16)0U);/* '<S1024>/Max1' */

/* test signal, to be deleted */
MONPRM volatile boolean VTQD_TqZeroFast_flg = false;/* '<S1296>/Logical Operator4' */
MONPRM volatile boolean VTQD_TqZeroSlow_flg = false;/* '<S1296>/Logical Operator2' */
MONPRM volatile boolean VTQD_TqZero_flg = false;/* '<S1296>/Logical Operator1' */
MONPRM volatile float32 VTQF_DrvTqReqWhl_Nm = 0.0F;/* '<S1320>/Switch2' */
MONPRM volatile float32 VTQF_TipOutTqDecRateCoeff_rat = 0.0F;/* '<S1322>/1-D Lookup Table1' */
MONPRM volatile boolean VTQF_TqInc_flg = false;/* '<S1332>/Switch4' */
MONPRM volatile float32 VTQF_TqOutChgRate_Nmps = 0.0F;/* '<S1342>/Switch' */
MONPRM volatile float32 VTQF_TqRateDecTgtMax_Nmps = 0.0F;/* '<S1322>/Switch3' */
MONPRM volatile float32 VTQF_TqRateDecTgtMin_Nmps = 0.0F;/* '<S1322>/MinMax4' */
MONPRM volatile float32 VTQF_TqRateIncTgtMax_Nmps = 0.0F;/* '<S1323>/Switch5' */
MONPRM volatile float32 VTQF_TqRateIncTgtMin_Nmps = 0.0F;/* '<S1323>/MinMax4' */
MONPRM volatile float32 VTQF_TqRateLimDec_Nmps = 0.0F;/* '<S1322>/MinMax3' */
MONPRM volatile boolean VTQF_TqRateLimEndg_flg = false;/* '<S1321>/Logical Operator9' */
MONPRM volatile float32 VTQF_TqRateLimInc_Nmps = 0.0F;/* '<S1323>/MinMax2' */
MONPRM volatile float32 VTQF_TqRawChgRate_Nmps = 0.0F;/* '<S1341>/Switch' */
MONPRM volatile float32 VTQF_WhlDrgMaxTqZX_Nm = 0.0F;/* '<S1340>/Switch1' */
MONPRM volatile float32 VTQF_WhlDrvMaxTqZX_Nm = 0.0F;/* '<S1340>/Switch7' */
MONPRM volatile boolean VTQR_ASDEnbl_flg = false;/* '<S1345>/Logical Operator14' */
MONPRM volatile float32 VTQR_ASDSpdFltHi_rpm = 0.0F;/* '<S1353>/Switch' */
MONPRM volatile float32 VTQR_ASDSpdOscRaw_rpm = 0.0F;/* '<S1349>/Add1' */
MONPRM volatile float32 VTQR_ASDSpdOsc_rpm = 0.0F;/* '<S1351>/Multiport Switch' */
MONPRM volatile float32 VTQR_ASDTqReqRaw_Nm = 0.0F;/* '<S1357>/MinMax5' */
MONPRM volatile float32 VTQR_ASDTqReq_Nm = 0.0F;/* '<S1350>/Switch3' */
MONPRM volatile boolean VTQR_MotDampngEnbl_flg = false;/* '<S1345>/Logical Operator1' */
MONPRM volatile float32 VTQR_MotDampngLmt_Nm = 0.0F;/* '<S1365>/MinMax5' */
MONPRM volatile EnumMotorDirReq VTQR_MotorDirReq_enum = EnumMotorDirReq_Stdby;/* '<S1346>/Switch4' */
MONPRM volatile EnumMotorModeReq VTQR_MotorModeReq_enum = EnumMotorModeReq_Stdby;/* '<S1343>/Signal Conversion15' */
MONPRM volatile float32 VTQR_MotorSpdReq_rpm = 0.0F;/* '<S1343>/Signal Conversion1' */
MONPRM volatile boolean VTQR_MotorStdby_flg = false;/* '<S1347>/Logical Operator1' */
MONPRM volatile float32 VTQR_MotorTqReq_Nm = 0.0F;/* '<S1343>/Signal Conversion2' */
MONPRM volatile float32 VTZX_AZDecRate_Nmps = 0.0F;/* '<S1381>/1-D Lookup Table4' */
MONPRM volatile float32 VTZX_AZIncRate_Nmps = 0.0F;/* '<S1381>/1-D Lookup Table3' */
MONPRM volatile float32 VTZX_BZDecRate_Nmps = 0.0F;/* '<S1381>/1-D Lookup Table2' */
MONPRM volatile float32 VTZX_BZIncRate_Nmps = 0.0F;/* '<S1381>/1-D Lookup Table1' */
MONPRM volatile boolean VTZX_BypZX_flg = false;/* '<S1385>/Logical Operator1' */
MONPRM volatile boolean VTZX_ClkActv_flg = false;/* '<S1384>/Switch4' */
MONPRM volatile float32 VTZX_ClkZXTm_s = 0.0F;/* '<S1377>/Switch1' */
MONPRM volatile float32 VTZX_MotorTqReqPrdt_Nm = 0.0F;/* '<S1397>/MinMax5' */
MONPRM volatile float32 VTZX_MotorTqReqZX_Nm = 0.0F;/* '<S1382>/TqZXSt' */
MONPRM volatile float32 VTZX_MotorTqReq_Nm = 0.0F;/* '<S1377>/Switch6' */
MONPRM volatile boolean VTZX_TqInc_flg = false;/* '<S1391>/Switch4' */
MONPRM volatile boolean VTZX_TqRateLimRamp_flg = false;/* '<S1398>/Switch4' */
MONPRM volatile EnumTZXStat VTZX_TqZXSt_enum = EnumTZXStat_NTRL;/* '<S1382>/Data Type Conversion1' */
MONPRM volatile float32 VTZX_ZeroTqHldDec_Nm = 0.0F;/* '<S1382>/TqZXSt' */
MONPRM volatile float32 VTZX_ZeroTqHldInc_Nm = 0.0F;/* '<S1382>/TqZXSt' */
MONPRM volatile float32 VTZX_ZeroTqOfstDec_Nm = 0.0F;/* '<S1381>/Switch3' */
MONPRM volatile float32 VTZX_ZeroTqOfstInc_Nm = 0.0F;/* '<S1381>/Switch2' */
MONPRM volatile float32 VTZX_ZeroTqOfst_Nm = 0.0F;/* '<S1381>/Switch4' */
MONPRM volatile float32 VTZX_ZeroXTm_s = 0.0F;/* '<S1381>/Switch8' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr1_mpkm = 0.0F;/* '<S992>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr2_mpkm = 0.0F;/* '<S992>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr3_mpkm = 0.0F;/* '<S992>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr4_mpkm = 0.0F;/* '<S992>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr5_mpkm = 0.0F;/* '<S992>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr_mpkm = 0.0F;/* '<S992>/Add3' */
MONPRM volatile float32 VVSO_DrvDist_m = 0.0F;/* '<S1005>/Switch1' */
MONPRM volatile float32 VVSO_RoadSlopEst_pct = 0.0F;/* '<S986>/Product19' */
MONPRM volatile float32 VVSO_RoadSlopTqEst_Nm = 0.0F;/* '<S990>/MinMax5' */
MONPRM volatile float32 VVSO_SlopEst_rat = 0.0F;/* '<S1014>/Switch' */
MONPRM volatile float32 VVSO_VehDrvResistTq_Nm = 0.0F;/* '<S986>/Switch4' */
MONPRM volatile float32 VVSO_VehMassEst_kg = 0.0F;/* '<S1013>/Switch' */
MONPRM volatile float32 VVSO_VehSpd_kph = 0.0F;/* '<S996>/Gain1' */
MONPRM volatile boolean VVSO_WhlDistErrHld_flg = false;/* '<S996>/OR' */
MONPRM volatile EnumXWhlDistErrRefSt VVSO_XWhlDistErrRefStat_enum =
  EnumXWhlDistErrRefSt_Init;           /* '<S992>/Signal Conversion2' */
MONPRM volatile float32 VVSO_XWhlDistErrRef_mpkm = 0.0F;/* '<S992>/Signal Conversion1' */
MONPRM volatile float32 VVSO_XWhlDistErr_m = 0.0F;/* '<S1005>/Switch4' */
MONPRM volatile boolean VVSO_iTPMSAvail_flg = false;/* '<S996>/Logical Operator' */
MONPRM volatile EnumiTPMSSt VVSO_iTPMSState_enum = EnumiTPMSSt_Init;/* '<S992>/Signal Conversion' */
MONPRM volatile boolean VVSO_iTPMSWrng_flg = false;/* '<S992>/Signal Conversion3' */
MONPRM volatile boolean VVTM_BrkPedReld_flg = false;/* '<S1423>/Logical Operator3' */
MONPRM volatile uint8 VVTM_DrvMotorSta_enum = ((uint8)0U);/* '<S1430>/DriveMotorState' */
MONPRM volatile boolean VVTM_ESPIntvActv_flg = false;/* '<S1423>/Logical Operator4' */
MONPRM volatile float32 VVTM_MotorActPwr_kW = 0.0F;/* '<S1437>/Switch2' */
MONPRM volatile float32 VVTM_MotorSpd_rpm = 0.0F;/* '<S1425>/Switch' */
MONPRM volatile boolean VVTM_PCUFailSta_flg = false;/* '<S1430>/Logical Operator2' */
MONPRM volatile boolean VVTM_RegenReqBrkLampOn_flg = false;/* '<S1435>/Switch1' */
MONPRM volatile float32 VVTM_RsrvPwr_kW = 0.0F;/* '<S1432>/MinMax4' */
MONPRM volatile float32 VVTM_RsrvRecupPwr_kW = 0.0F;/* '<S1432>/MinMax1' */
MONPRM volatile float32 VVTM_VehAcceltn_mps2 = 0.0F;/* '<S1428>/Switch' */
MONPRM volatile uint8 VVTM_VehActGrPstn_enum = ((uint8)0U);/* '<S1423>/Switch1' */
MONPRM volatile float32 VVTM_VehSpd_kph = 0.0F;/* '<S1424>/Switch' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
