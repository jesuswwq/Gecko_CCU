/*
 * File: monPrmsVcu.c
 *
 * Code generated for Simulink model 'AppSwcVcu'.
 *
 * Model version                  : 9.584
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Oct  9 14:32:43 2024
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
MONPRM volatile boolean BSW_RTCWakeup_flg = false;/* '<S974>/Switch4' */

/* RTC唤醒标志位_versteckt */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Day = ((uint8)0U);/* '<S98>/Data Type Conversion45' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Hour = ((uint8)0U);/* '<S98>/Data Type Conversion1' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Min = ((uint8)0U);/* '<S98>/Data Type Conversion2' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Month = ((uint8)0U);/* '<S98>/Data Type Conversion34' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Sec = ((uint8)0U);/* '<S98>/Switch2' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Year = ((uint8)0U);/* '<S98>/Data Type Conversion33' */
MONPRM volatile uint8 VBSW_WakeupReasn_enum = ((uint8)0U);/* '<S1449>/EcuWakeupReasn' */

/* _versteckt */
MONPRM volatile float32 VCPT_MotorDrgMaxTq_Nm = 0.0F;/* '<S1033>/MinMax6' */
MONPRM volatile float32 VCPT_MotorDrvMaxTq_Nm = 0.0F;/* '<S1033>/MinMax7' */
MONPRM volatile float32 VCPT_MotorGenMaxTq_Nm = 0.0F;/* '<S1045>/Switch1' */
MONPRM volatile float32 VCPT_MotorMotMaxTq_Nm = 0.0F;/* '<S1044>/Switch1' */
MONPRM volatile boolean VCPT_MotorSpdRvrs_flg = false;/* '<S1033>/Switch3' */
MONPRM volatile float32 VCPT_MotorSpd_rpm = 0.0F;/* '<S1039>/Switch' */
MONPRM volatile float32 VCPT_WhlDrgMaxTq_Nm = 0.0F;/* '<S1033>/MinMax1' */
MONPRM volatile float32 VCPT_WhlDrvMaxTq_Nm = 0.0F;/* '<S1033>/MinMax8' */
MONPRM volatile boolean VDAC_ACCAvail_flg = false;/* '<S1054>/Logical Operator9' */
MONPRM volatile float32 VDAC_ACCDeltaAcceltn_mps2 = 0.0F;/* '<S1060>/Add5' */
MONPRM volatile float32 VDAC_ACCDsrdTqFF_Nm = 0.0F;/* '<S1060>/Add3' */
MONPRM volatile float32 VDAC_ACCDsrdTqI_N = 0.0F;/* '<S1060>/Saturation1' */
MONPRM volatile float32 VDAC_ACCDsrdTqPID_Nm = 0.0F;/* '<S1060>/Product6' */
MONPRM volatile float32 VDAC_ACCDsrdTqP_N = 0.0F;/* '<S1060>/Product3' */
MONPRM volatile boolean VDAC_ACCEnbl_flg = false;/* '<S1054>/Logical Operator3' */
MONPRM volatile boolean VDAC_ACCOvrd_flg = false;/* '<S1055>/Logical Operator22' */
MONPRM volatile float32 VDAC_ACCTqReqWhl_Nm = 0.0F;/* '<S1056>/Merge3' */
MONPRM volatile uint8 VDAC_AutoBrkReq_enum = ((uint8)0U);/* '<S1161>/Switch' */
MONPRM volatile boolean VDAC_CCActv2Stby_flg = false;/* '<S1095>/Logical Operator15' */
MONPRM volatile boolean VDAC_CCActvBascCond_flg = false;/* '<S1095>/Logical Operator1' */
MONPRM volatile float32 VDAC_CCDeltaAcceltn_mps2 = 0.0F;/* '<S1082>/Add3' */
MONPRM volatile float32 VDAC_CCDsrdAcceltnRaw_mps2 = 0.0F;/* '<S1075>/Saturation1' */
MONPRM volatile float32 VDAC_CCDsrdAcceltn_mps2 = 0.0F;/* '<S1073>/Merge1' */
MONPRM volatile float32 VDAC_CCDsrdTqFF_N = 0.0F;/* '<S1081>/Add3' */
MONPRM volatile float32 VDAC_CCDsrdTqI_N = 0.0F;/* '<S1082>/Saturation1' */
MONPRM volatile float32 VDAC_CCDsrdTqPID_N = 0.0F;/* '<S1082>/Add2' */
MONPRM volatile float32 VDAC_CCDsrdTqP_N = 0.0F;/* '<S1082>/Product2' */
MONPRM volatile boolean VDAC_CCEnbl_flg = false;/* '<S1096>/Logical Operator2' */
MONPRM volatile uint16 VDAC_CCNoActvCond_enum = ((uint16)0U);/* '<S1098>/Add' */
MONPRM volatile boolean VDAC_CCOvrd_flg = false;/* '<S1069>/Logical Operator22' */
MONPRM volatile uint16 VDAC_CCQuitCond_enum = ((uint16)0U);/* '<S1099>/Add' */
MONPRM volatile float32 VDAC_CCSpdUnstabTm_s = 0.0F;/* '<S1111>/Saturation' */
MONPRM volatile boolean VDAC_CCSpdUnstab_flg = false;/* '<S1111>/Relational Operator8' */
MONPRM volatile EnumCCState VDAC_CCSt_enum = EnumCCState_Off;/* '<S1070>/CC_State_Chart' */
MONPRM volatile boolean VDAC_CCStby2Actv_flg = false;/* '<S1095>/Logical Operator9' */
MONPRM volatile float32 VDAC_CCTgtSpdCtrl_kph = 0.0F;/* '<S1120>/Switch1' */
MONPRM volatile uint8 VDAC_CCTgtSpdHU_kph = ((uint8)0U);/* '<S1071>/TgtSpdCalc' */
MONPRM volatile EnumCCTgtSpdSt VDAC_CCTgtSpdSt_enum = EnumCCTgtSpdSt_Reset;/* '<S1071>/TgtSpdCalc' */
MONPRM volatile float32 VDAC_CCTgtSpd_kph = 0.0F;/* '<S1071>/MinMax7' */
MONPRM volatile float32 VDAC_CCTqReqWhl_Nm = 0.0F;/* '<S1074>/Merge2' */
MONPRM volatile float32 VDAC_CCVehSpdNonDrvn_kph = 0.0F;/* '<S1077>/Switch' */
MONPRM volatile boolean VDAC_CruzCncl_flg = false;/* '<S1136>/Chart' */
MONPRM volatile EnumCruiseStatus VDAC_CruzCtrlStat_enum =
  EnumCruiseStatus_NormOff;            /* '<S1069>/Switch2' */
MONPRM volatile boolean VDAC_CruzCtrlSwVld_flg = false;/* '<S1072>/Signal Conversion1' */
MONPRM volatile boolean VDAC_CruzOn_flg = true;/* '<S1072>/Signal Conversion2' */
MONPRM volatile boolean VDAC_CruzRsmActv_flg = false;/* '<S1133>/Switch4' */
MONPRM volatile boolean VDAC_CruzSetActv_flg = false;/* '<S1131>/Switch4' */
MONPRM volatile boolean VDAC_CruzSpdDecActv_flg = false;/* '<S1132>/Switch4' */
MONPRM volatile boolean VDAC_CruzSpdIncActv_flg = false;/* '<S1134>/Switch4' */
MONPRM volatile float32 VDAC_DrvAsstTqSplitEHB_Nm = 0.0F;/* '<S1050>/MinMax2' */
MONPRM volatile float32 VDAC_DrvAsstTqSplitINV_Nm = 0.0F;/* '<S1050>/Add1' */
MONPRM volatile uint8 VDAC_DrvAsstTqSts_enum = ((uint8)0U);/* '<S1050>/Switch1' */
MONPRM volatile float32 VDAC_DrvAsstTqTgt_Nm = 0.0F;/* '<S1050>/Switch2' */
MONPRM volatile boolean VDAC_EnblEHBBrkRun_flg = false;/* '<S1243>/Switch4' */
MONPRM volatile boolean VDAC_HDCActv2Idle_flg = false;/* '<S1143>/Logical Operator11' */
MONPRM volatile boolean VDAC_HDCActv2Stdby_flg = false;/* '<S1143>/Logical Operator8' */
MONPRM volatile float32 VDAC_HDCDeltaAcceltn_mps2 = 0.0F;/* '<S1148>/Add5' */
MONPRM volatile float32 VDAC_HDCDsrdTqFF_Nm = 0.0F;/* '<S1148>/Add3' */
MONPRM volatile float32 VDAC_HDCDsrdTqI_N = 0.0F;/* '<S1148>/Saturation1' */
MONPRM volatile float32 VDAC_HDCDsrdTqPID_Nm = 0.0F;/* '<S1148>/Product6' */
MONPRM volatile float32 VDAC_HDCDsrdTqP_N = 0.0F;/* '<S1148>/Product3' */
MONPRM volatile boolean VDAC_HDCIdle2Stdby_flg = false;/* '<S1143>/Logical Operator2' */
MONPRM volatile EnumHDCState VDAC_HDCSt_enum = EnumHDCState_Idle;/* '<S1048>/HDC_State_Chart' */
MONPRM volatile boolean VDAC_HDCStdby2Actv_flg = false;/* '<S1143>/Logical Operator13' */
MONPRM volatile boolean VDAC_HDCStdby2Idle_flg = false;/* '<S1143>/Logical Operator3' */
MONPRM volatile float32 VDAC_HDCTgtAcceltn_mps2 = 0.0F;/* '<S1140>/Merge1' */
MONPRM volatile float32 VDAC_HDCTgtSpd_kph = 0.0F;/* '<S1048>/HDC_State_Chart' */
MONPRM volatile float32 VDAC_HDCTqReqWhl_Nm = 0.0F;/* '<S1140>/Merge2' */
MONPRM volatile uint8 VDAC_HDCVehSpdHU_kph = ((uint8)0U);/* '<S1141>/Switch1' */
MONPRM volatile boolean VDAC_MstrCylPresDec_flg = false;/* '<S1169>/Relational Operator' */
MONPRM volatile float32 VDAC_MstrCylPresrReq_bar = 0.0F;/* '<S1050>/Switch13' */
MONPRM volatile boolean VDAC_OPDActv_flg = false;/* '<S1184>/Switch4' */
MONPRM volatile boolean VDAC_OPDAvail_flg = false;/* '<S1162>/Logical Operator9' */
MONPRM volatile float32 VDAC_OPDDeltaAcceltn_mps2 = 0.0F;/* '<S1201>/Add3' */
MONPRM volatile float32 VDAC_OPDDeltaSpd_kph = 0.0F;/* '<S1201>/Add4' */
MONPRM volatile float32 VDAC_OPDDsrdTqD_N = 0.0F;/* '<S1215>/Switch' */
MONPRM volatile float32 VDAC_OPDDsrdTqFF_Nm = 0.0F;/* '<S1200>/Add3' */
MONPRM volatile boolean VDAC_OPDDsrdTqFstI_flg = false;/* '<S1212>/Logical Operator9' */
MONPRM volatile boolean VDAC_OPDDsrdTqHldI_flg = false;/* '<S1212>/Logical Operator3' */
MONPRM volatile float32 VDAC_OPDDsrdTqI_N = 0.0F;/* '<S1201>/Saturation1' */
MONPRM volatile float32 VDAC_OPDDsrdTqPID_Nm = 0.0F;/* '<S1201>/Product4' */
MONPRM volatile float32 VDAC_OPDDsrdTqP_N = 0.0F;/* '<S1207>/Switch2' */
MONPRM volatile float32 VDAC_OPDMaxDrgTqWhl_Nm = 0.0F;/* '<S1212>/MinMax1' */
MONPRM volatile float32 VDAC_OPDMaxDrvTqWhl_Nm = 0.0F;/* '<S1212>/MinMax3' */
MONPRM volatile boolean VDAC_OPDOvrd_flg = false;/* '<S1161>/Logical Operator22' */
MONPRM volatile float32 VDAC_OPDRtdTq_Nm = 0.0F;/* '<S1200>/Add1' */
MONPRM volatile boolean VDAC_OPDSpdClsLoop_flg = false;/* '<S1201>/Logical Operator9' */
MONPRM volatile float32 VDAC_OPDTgtAcceltn_mps2 = 0.0F;/* '<S1163>/Merge3' */
MONPRM volatile float32 VDAC_OPDTgtSpd_kph = 0.0F;/* '<S1163>/Merge1' */
MONPRM volatile boolean VDAC_OPDTqReqUnload_flg = false;/* '<S1161>/Logical Operator1' */
MONPRM volatile float32 VDAC_OPDTqReqWhlFilt_Nm = 0.0F;/* '<S1235>/Switch3' */
MONPRM volatile float32 VDAC_OPDTqReqWhlLmt_Nm = 0.0F;/* '<S1164>/Merge3' */
MONPRM volatile float32 VDAC_OPDTqReqWhl_Nm = 0.0F;/* '<S1172>/Switch3' */
MONPRM volatile float32 VDAC_OPDVehAcceltn2_mps2 = 0.0F;/* '<S1191>/Switch' */
MONPRM volatile float32 VDAC_OPDVehAcceltn_mps2 = 0.0F;/* '<S1163>/Switch2' */
MONPRM volatile float32 VDAC_OPDVehSpdMotorFac_rat = 0.0F;/* '<S1190>/Switch' */
MONPRM volatile float32 VDAC_OPDVehSpdMotor_kph = 0.0F;/* '<S1163>/Product1' */
MONPRM volatile float32 VDAC_OPDVehSpd_kph = 0.0F;/* '<S1163>/Switch1' */
MONPRM volatile uint8 VDAC_VehSpdHU_kph = ((uint8)0U);/* '<S1122>/Switch1' */
MONPRM volatile uint8 VDAC_VirtAccPedPstnSta_enum = ((uint8)0U);/* '<S1050>/Switch11' */
MONPRM volatile float32 VDAC_VirtAccPedPstn_pct = 0.0F;/* '<S1050>/Switch8' */
MONPRM volatile float32 VDAC_VirtAccelPedPstnRaw_pct = 0.0F;/* '<S1050>/Switch9' */
MONPRM volatile float32 VDAC_VirtPedPstn_pct = 0.0F;/* '<S1050>/Switch4' */
MONPRM volatile uint8 VDAG_ACChrgStFailFltSt_enum = ((uint8)0U);/* '<S378>/FltStDeb' */

/* ACChargeStateFail故障状态 */
MONPRM volatile uint8 VDAG_ACDchaBMSPwrLoFltSt_enum = ((uint8)0U);/* '<S384>/FltStDeb' */

/* AC放电BMS功率低故障状态 */
MONPRM volatile uint8 VDAG_ACDchaBMSSOCLoFltSt_enum = ((uint8)0U);/* '<S383>/FltStDeb' */

/* AC放电BMSSOC低故障状态 */
MONPRM volatile uint8 VDAG_ACDchaOverPwrFltSt_enum = ((uint8)0U);/* '<S377>/FltStDeb' */

/* AC放电功率超限故障 */
MONPRM volatile uint8 VDAG_ACSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S131>/FltStDeb' */

/* ACSCmd超时故障状态 */
MONPRM volatile uint8 VDAG_AccPed1ShtBattFltSt_enum = ((uint8)0U);/* '<S495>/FltStDeb' */

/* 加速踏板1路短电源故障状态 */
MONPRM volatile uint8 VDAG_AccPed1ShtGndFltSt_enum = ((uint8)0U);/* '<S492>/FltStDeb' */

/* 加速踏板1路短地故障状态 */
MONPRM volatile uint8 VDAG_AccPed1SuplyShtCircFltSt_enum = ((uint8)0U);/* '<S493>/FltStDeb' */

/* 加速踏板1路供电短路故障状态 */
MONPRM volatile uint8 VDAG_AccPed2ShtBattFltSt_enum = ((uint8)0U);/* '<S488>/FltStDeb' */

/* 加速踏板2路短电源故障状态 */
MONPRM volatile uint8 VDAG_AccPed2ShtGndFltSt_enum = ((uint8)0U);/* '<S496>/FltStDeb' */

/* 加速踏板2路短地故障状态 */
MONPRM volatile uint8 VDAG_AccPed2SuplyShtCircFltSt_enum = ((uint8)0U);/* '<S494>/FltStDeb' */

/* 加速踏板2路供电短路故障状态 */
MONPRM volatile uint8 VDAG_AccPedBothFailFltSt_enum = ((uint8)0U);/* '<S490>/FltStDeb' */

/* 加速踏板双路失效故障状态 */
MONPRM volatile uint8 VDAG_AccPedCrsChkFltSt_enum = ((uint8)0U);/* '<S489>/FltStDeb' */

/* 加速踏板相互校验故障状态 */
MONPRM volatile uint8 VDAG_BMSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S125>/FltStDeb' */

/* BMS继电器指令响应超时故障状态 */
MONPRM volatile uint8 VDAG_BMSEmgcySdnFltSt_enum = ((uint8)0U);/* '<S136>/FltStDeb' */

/* BMS紧急下电故障状态 */
MONPRM volatile uint8 VDAG_BMSSOCLoFltSt_enum = ((uint8)0U);/* '<S135>/FltStDeb' */

/* BMSSOC低故障状态 */
MONPRM volatile uint8 VDAG_BMSSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S132>/FltStDeb' */

/* BMSFailLevel1故障状态 */
MONPRM volatile uint8 VDAG_BMSSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S133>/FltStDeb' */

/* BMSFailLevel2故障状态 */
MONPRM volatile uint8 VDAG_BMSSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S134>/FltStDeb' */

/* BMSFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_BMSUndrVoltFltSt_enum = ((uint8)0U);/* '<S137>/FltStDeb' */

/* BMSPack欠压故障状态 */
MONPRM volatile uint8 VDAG_BrkPedShtBattFltSt_enum = ((uint8)0U);/* '<S515>/FltStDeb' */

/* 制动踏板短电源故障状态 */
MONPRM volatile uint8 VDAG_BrkPedShtGndFltSt_enum = ((uint8)0U);/* '<S513>/FltStDeb' */

/* 制动踏板短地故障状态 */
MONPRM volatile uint8 VDAG_BrkSwCrsChkCnt_cnt = ((uint8)0U);/* '<S508>/Data Type Conversion' */

/* 制动开关相互校验错误计数 */
MONPRM volatile uint8 VDAG_BrkSwCrsChkFltSt_enum = ((uint8)0U);/* '<S514>/FltStDeb' */

/* 制动开关相互校验故障状态 */
MONPRM volatile uint8 VDAG_CellUndrVoltFltSt_enum = ((uint8)0U);/* '<S138>/FltStDeb' */

/* BMSCell欠压故障状态 */
MONPRM volatile uint8 VDAG_DCCCmdTmOutFltSt_enum = ((uint8)0U);/* '<S280>/FltStDeb' */

/* DCDC模式指令响应超时故障状态 */
MONPRM volatile uint8 VDAG_DCCInVoltLoFltSt_enum = ((uint8)0U);/* '<S281>/FltStDeb' */

/* DCDC输入电压低故障状态 */
MONPRM volatile uint8 VDAG_DCCModeFltFltSt_enum = ((uint8)0U);/* '<S279>/FltStDeb' */

/* DCDCModeFault故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S275>/FltStDeb' */

/* DCDCFailLevel1故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S276>/FltStDeb' */

/* DCDCFailLevel2故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S277>/FltStDeb' */

/* DCDCFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl4FltSt_enum = ((uint8)0U);/* '<S278>/FltStDeb' */

/* DCDCFailLevel4故障状态 */
MONPRM volatile uint8 VDAG_DCSChrgReqFltSt_enum = ((uint8)0U);/* '<S129>/FltStDeb' */

/* DCSChargeRequest故障状态 */
MONPRM volatile uint8 VDAG_DCSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S139>/FltStDeb' */

/* DCSCmd超时故障状态 */
MONPRM volatile uint8 VDAG_DCSFailStaFltSt_enum = ((uint8)0U);/* '<S127>/FltStDeb' */

/* DCSFailState故障状态 */
MONPRM volatile uint8 VDAG_DCSInletConnectFltSt_enum = ((uint8)0U);/* '<S128>/FltStDeb' */

/* DCS插枪故障状态 */
MONPRM volatile uint8 VDAG_DCSModeFailFltSt_enum = ((uint8)0U);/* '<S130>/FltStDeb' */

/* DCSModeFail故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl1FltSt_enum = ((uint8)0U);/* '<S440>/FltStDeb' */

/* EHB1级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl2FltSt_enum = ((uint8)0U);/* '<S441>/FltStDeb' */

/* EHB2级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl3FltSt_enum = ((uint8)0U);/* '<S442>/FltStDeb' */

/* EHB3级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl4FltSt_enum = ((uint8)0U);/* '<S434>/FltStDeb' */

/* EHB4级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl5FltSt_enum = ((uint8)0U);/* '<S443>/FltStDeb' */

/* EHB5级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl1FltSt_enum = ((uint8)0U);/* '<S445>/FltStDeb' */

/* ESC1级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl2FltSt_enum = ((uint8)0U);/* '<S435>/FltStDeb' */

/* ESC2级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl3FltSt_enum = ((uint8)0U);/* '<S436>/FltStDeb' */

/* ESC3级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl4FltSt_enum = ((uint8)0U);/* '<S444>/FltStDeb' */

/* ESC4级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl5FltSt_enum = ((uint8)0U);/* '<S437>/FltStDeb' */

/* ESC5级故障状态 */
MONPRM volatile uint8 VDAG_ESCVehSpdInvldFltSt_enum = ((uint8)0U);/* '<S439>/FltStDeb' */

/* 车速失效故障状态 */
MONPRM volatile boolean VDAG_EmgcyShtdwn_flg = false;/* '<S89>/Switch30' */
MONPRM volatile uint16 VDAG_ErrCode_enum = ((uint16)0U);/* '<S87>/Err_State' */
MONPRM volatile boolean VDAG_FanFullSpdOn_flg = false;/* '<S89>/Switch3' */
MONPRM volatile boolean VDAG_FbdACC_flg = false;/* '<S89>/Switch28' */
MONPRM volatile boolean VDAG_FbdACChrg_flg = false;/* '<S89>/Switch32' */
MONPRM volatile boolean VDAG_FbdACDcha_flg = false;/* '<S89>/Switch34' */
MONPRM volatile boolean VDAG_FbdAC_flg = false;/* '<S89>/Switch35' */
MONPRM volatile boolean VDAG_FbdCC_flg = false;/* '<S89>/Switch26' */
MONPRM volatile boolean VDAG_FbdDCChrg_flg = false;/* '<S89>/Switch33' */
MONPRM volatile boolean VDAG_FbdDCDC_flg = false;/* '<S89>/Switch31' */
MONPRM volatile boolean VDAG_FbdDRGr_flg = false;/* '<S89>/Switch25' */
MONPRM volatile boolean VDAG_FbdDrvTq_flg = false;/* '<S89>/Switch23' */
MONPRM volatile boolean VDAG_FbdHV_flg = false;/* '<S89>/Switch29' */
MONPRM volatile boolean VDAG_FbdLSP_flg = false;/* '<S89>/Switch27' */
MONPRM volatile boolean VDAG_FltLampOn_flg = false;/* '<S89>/Switch36' */
MONPRM volatile uint8 VDAG_FltLvl_enum = ((uint8)0U);/* '<S89>/MinMax' */
MONPRM volatile uint8 VDAG_GearShftInvldFltSt_enum = ((uint8)0U);/* '<S438>/FltStDeb' */

/* 换挡输入失效故障状态 */
MONPRM volatile uint8 VDAG_HVILVoltHiFltSt_enum = ((uint8)0U);/* '<S517>/FltStDeb' */

/* 高压互锁电压高故障状态 */
MONPRM volatile uint8 VDAG_HVILVoltLoFltSt_enum = ((uint8)0U);/* '<S516>/FltStDeb' */

/* 高压互锁电压低故障状态 */
MONPRM volatile uint8 VDAG_HVIsoResistLoFltSt_enum = ((uint8)0U);/* '<S126>/FltStDeb' */

/* 高压电池绝缘故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl1FltSt_enum = ((uint8)0U);/* '<S344>/FltStDeb' */

/* INVFaultLevel1故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl2FltSt_enum = ((uint8)0U);/* '<S345>/FltStDeb' */

/* INVFaultLevel2故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl3FltSt_enum = ((uint8)0U);/* '<S346>/FltStDeb' */

/* INVFaultLevel3故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl4FltSt_enum = ((uint8)0U);/* '<S347>/FltStDeb' */

/* INVFaultLevel4故障状态 */
MONPRM volatile uint8 VDAG_INVInVoltLoFltSt_enum = ((uint8)0U);/* '<S282>/FltStDeb' */

/* INV输入电压低故障状态 */
MONPRM volatile uint8 VDAG_INVRunCmdRespFltSt_enum = ((uint8)0U);/* '<S348>/FltStDeb' */

/* INVRun指令响应超时故障状态 */
MONPRM volatile boolean VDAG_LVBatLampOn_flg = false;/* '<S89>/Switch1' */
MONPRM volatile uint8 VDAG_LVBattSOCLoFltSt_enum = ((uint8)0U);/* '<S468>/FltStDeb' */

/* 蓄电池SOC低的故障状态 */
MONPRM volatile uint8 VDAG_LVBattSOHLoFltSt_enum = ((uint8)0U);/* '<S464>/FltStDeb' */

/* 蓄电池SOH低的故障状态 */
MONPRM volatile uint8 VDAG_LVBattTempHiFltSt_enum = ((uint8)0U);/* '<S465>/FltStDeb' */

/* 蓄电池过温故障状态 */
MONPRM volatile uint8 VDAG_LVBattVoltHiFltSt_enum = ((uint8)0U);/* '<S467>/FltStDeb' */

/* 蓄电池电压高故障状态 */
MONPRM volatile uint8 VDAG_LVBattVoltLoFltSt_enum = ((uint8)0U);/* '<S466>/FltStDeb' */

/* 蓄电池电压低故障状态 */
MONPRM volatile boolean VDAG_LimpHome_flg = false;/* '<S89>/Switch2' */
MONPRM volatile boolean VDAG_LmtDrvTq_flg = false;/* '<S89>/Switch24' */
MONPRM volatile uint8 VDAG_OBCChrgReqFltSt_enum = ((uint8)0U);/* '<S382>/FltStDeb' */

/* OBCChargeRequest故障状态 */
MONPRM volatile uint8 VDAG_OBCConnectTmOutFltSt_enum = ((uint8)0U);/* '<S380>/FltStDeb' */

/* OBC连接超时故障状态 */
MONPRM volatile uint8 VDAG_OBCInletConnectFltSt_enum = ((uint8)0U);/* '<S385>/FltStDeb' */

/* OBC插枪故障状态 */
MONPRM volatile uint8 VDAG_OBCModeMsmtchFltSt_enum = ((uint8)0U);/* '<S379>/FltStDeb' */

/* OBC模式不匹配故障状态 */
MONPRM volatile uint8 VDAG_OBCS2StatFltSt_enum = ((uint8)0U);/* '<S381>/FltStDeb' */

/* OBCS2连接超时故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S386>/FltStDeb' */

/* OBCFailLevel1故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S387>/FltStDeb' */

/* OBCFailLevel2故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S388>/FltStDeb' */

/* OBCFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl4FltSt_enum = ((uint8)0U);/* '<S376>/FltStDeb' */

/* OBCFailLevel4故障状态 */
MONPRM volatile uint8 VDAG_SysPwrModeInvldFltSt_enum = ((uint8)0U);/* '<S432>/FltStDeb' */

/* PowerMode失效故障状态 */
MONPRM volatile uint8 VDAG_TMSFailLvl3FltSt_enum = ((uint8)0U);/* '<S433>/FltStDeb' */

/* TMSRFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_VehCrashFltSt_enum = ((uint8)0U);/* '<S487>/FltStDeb' */

/* 碰撞故障状态 */
MONPRM volatile boolean VDAG_WakeUp_flg = false;/* '<S306>/Chart' */

/* 硬线唤醒或者IBSLIN唤醒标志 */
MONPRM volatile uint8 VDAG_WaterTempAbvThrFltSt_enum = ((uint8)0U);/* '<S532>/FltStDeb' */

/* 冷却水温过高故障状态 */
MONPRM volatile uint8 VDAG_WaterTempBlwThrFltSt_enum = ((uint8)0U);/* '<S531>/FltStDeb' */

/* 冷却水温过低故障状态 */
MONPRM volatile float32 VDSA_AcceltnIdxAvg_pct = 0.0F;/* '<S17>/AvgAcceltnIdx' */
MONPRM volatile float32 VDSA_AcceltnIdxRaw_pct = 0.0F;/* '<S17>/Saturation1' */
MONPRM volatile float32 VDSA_BrkPedPstnAvg_pct = 0.0F;/* '<S17>/AvgBrkPedPstn' */
MONPRM volatile float32 VDSA_DrvSprtIdx_pct = 0.0F;/* '<S17>/Saturation2' */
MONPRM volatile boolean VDSA_SprtIdxHldAcc_flg = false;/* '<S17>/Logical Operator3' */
MONPRM volatile boolean VDSA_SprtIdxHldBrk_flg = false;/* '<S17>/Logical Operator6' */
MONPRM volatile float32 VDSA_TqCalcAcceltn_mps2 = 0.0F;/* '<S17>/Divide1' */
MONPRM volatile boolean VEMS_ACCMOprtCmd_flg = false;/* '<S30>/ACCMEnble' */

/* 使能ACCM */
MONPRM volatile float32 VEMS_AccPwrRaw_kW = 0.0F;/* '<S31>/MinMax4' */
MONPRM volatile float32 VEMS_CellTempSyn_C = 0.0F;/* '<S83>/Switch1' */
MONPRM volatile float32 VEMS_CellUndrVoltDrtFac_c = 0.0F;/* '<S28>/Saturation3' */
MONPRM volatile float32 VEMS_ChrgCurFbKi_A = 0.0F;/* '<S80>/Saturation' */
MONPRM volatile float32 VEMS_ChrgCurFbKp_A = 0.0F;/* '<S80>/Product2' */
MONPRM volatile float32 VEMS_ChrgCurFb_A = 0.0F;/* '<S80>/Saturation2' */
MONPRM volatile float32 VEMS_ChrgOvrshtPwr_kW = 0.0F;/* '<S27>/Add1' */
MONPRM volatile float32 VEMS_ChrgPwrFbKi_kW = 0.0F;/* '<S46>/Saturation' */
MONPRM volatile float32 VEMS_ChrgPwrFbKp_kW = 0.0F;/* '<S46>/Product2' */
MONPRM volatile float32 VEMS_ChrgPwrFb_kW = 0.0F;/* '<S27>/Merge' */
MONPRM volatile float32 VEMS_DchaCurFbKi_A = 0.0F;/* '<S81>/Saturation' */
MONPRM volatile float32 VEMS_DchaCurFbKp_A = 0.0F;/* '<S81>/Product2' */
MONPRM volatile float32 VEMS_DchaCurFb_A = 0.0F;/* '<S81>/Saturation2' */
MONPRM volatile float32 VEMS_DchaOvrshtPwr_kW = 0.0F;/* '<S29>/Add1' */
MONPRM volatile float32 VEMS_DchaPwrFbKi_kW = 0.0F;/* '<S64>/Saturation' */
MONPRM volatile float32 VEMS_DchaPwrFbKp_kW = 0.0F;/* '<S64>/Product2' */
MONPRM volatile float32 VEMS_DchaPwrFb_kW = 0.0F;/* '<S29>/Merge' */
MONPRM volatile float32 VEMS_HVBatPwrAct_kW = 0.0F;/* '<S31>/Gain1' */
MONPRM volatile float32 VEMS_MaxChrgCur_A = 0.0F;/* '<S26>/Saturation4' */
MONPRM volatile float32 VEMS_MaxChrgPwr2MotRaw_kW = 0.0F;/* '<S26>/Add7' */
MONPRM volatile float32 VEMS_MaxChrgPwr2Mot_kW = 0.0F;/* '<S27>/MinMax2' */
MONPRM volatile float32 VEMS_MaxChrgPwr_kW = 0.0F;/* '<S26>/Product2' */
MONPRM volatile float32 VEMS_MaxConChrgCur_A = 0.0F;/* '<S26>/MinMax1' */
MONPRM volatile float32 VEMS_MaxConDchaCur_A = 0.0F;/* '<S28>/MinMax1' */
MONPRM volatile float32 VEMS_MaxDchaCur_A = 0.0F;/* '<S28>/Saturation4' */
MONPRM volatile float32 VEMS_MaxDchaPwr2MotRaw_kW = 0.0F;/* '<S28>/Add7' */
MONPRM volatile float32 VEMS_MaxDchaPwr2Mot_kW = 0.0F;/* '<S29>/MinMax2' */
MONPRM volatile float32 VEMS_MaxDchaPwr_kW = 0.0F;/* '<S28>/Product2' */
MONPRM volatile float32 VEMS_MaxInsChrgCur_A = 0.0F;/* '<S26>/MinMax3' */
MONPRM volatile float32 VEMS_MaxInsDchaCur_A = 0.0F;/* '<S28>/MinMax3' */
MONPRM volatile boolean VEMS_TMSActSOCEnbl_flg = false;/* '<S77>/Switch1' */

/* SOC是否限制TMS */
MONPRM volatile boolean VEMS_TMSPwrEnbl_flg = false;/* '<S30>/Switch3' */

/* 功率是否限制TMS */
MONPRM volatile float32 VEMS_TMSUsePwr_kW = 0.0F;/* '<S30>/Subtract' */

/* TMS可用功率 */
MONPRM volatile boolean VEMS_UseConChrgCur_flg = false;/* '<S37>/Switch4' */
MONPRM volatile boolean VEMS_UseConDchaCur_flg = false;/* '<S55>/Switch4' */
MONPRM volatile boolean VGSM_AsstDrvFbShft_flg = false;/* '<S1501>/Logical Operator2' */

/* 规范：ACC/CC禁止档位解析 */
MONPRM volatile boolean VGSM_DRFlt2N_flg = false;/* '<S1500>/Switch1' */

/* 规范：退至非驱动档标志位 */
MONPRM volatile boolean VGSM_EPBAplyFlt_flg = false;/* '<S1493>/EPBLogical' */

/* 故障P-EPB拉起故障 */
MONPRM volatile boolean VGSM_EPBRelsFlt_flg = false;/* '<S1493>/EPBLogical' */

/* 故障P-EPB释放故障 */
MONPRM volatile boolean VGSM_GrD2PExcdTm_flg = false;/* '<S1655>/Chart' */

/* D档入P请求超时入N */
MONPRM volatile boolean VGSM_GrNReq2P_flg = false;/* '<S1500>/Switch2' */

/* N档非换挡请求进P档请求 */
MONPRM volatile boolean VGSM_GrR2PExcdTm_flg = false;/* '<S1652>/Chart' */

/* R档入P请求超时入N */
MONPRM volatile boolean VGSM_HldGearP_flg = false;/* '<S1500>/Switch' */

/* 规范：保持P档标志位 */
MONPRM volatile boolean VGSM_INVRunEnbl_flg = false;/* '<S1503>/Chart' */

/* 规范：INV使能控制（允许扭矩控制）-VCU_1_EnaInvRun */
MONPRM volatile uint8 VGSM_PGrSwSts_enum = ((uint8)0U);/* '<S1501>/Switch2' */

/* 规范：P按键触发标志位-VCU_PGearSwcst */
MONPRM volatile boolean VGSM_ReqEPBAply_flg = false;/* '<S1502>/Logical Operator6' */

/* 规范：EPB拉起请求标志位 */
MONPRM volatile boolean VGSM_ReqEPBRels_flg = false;/* '<S1502>/Logical Operator4' */

/* 规范：EPB释放请求标志位 */
MONPRM volatile EnumEPBReq VGSM_ReqEPB_enum = EnumEPBReq_NoCmd;/* '<S1493>/Switch' */

/* 规范：EPB操作信号-VCUF_ReqEPB */
MONPRM volatile EnumTgtGearPstn VGSM_ShftTgtGrReq_enum = EnumTgtGearPstn_NoReq;/* '<S1501>/Data Type Conversion1' */

/* 换挡杆目标档位 0-NoCmd 1-P 2-N 3-D 4-R  */
MONPRM volatile EnumGearPstn VGSM_VehActGearPstn_enum = EnumGearPstn_P;/* '<S1494>/Switch1' */

/* 规范：实际档位-VCU_VhclActlGearPos */
MONPRM volatile boolean VGSM_VehEPBStErr_flg = false;/* '<S1493>/Logical Operator' */

/* 规范：P档故障PGear error-VCU_VhclPGearError */
MONPRM volatile EnumTgtGearPstn VGSM_VehTgtGrReq_enum = EnumTgtGearPstn_NoReq;/* '<S1502>/Data Type Conversion1' */

/* 规范:目标档位 */
MONPRM volatile uint8 VGSM_VehTgtGrTrnsfr_enum = ((uint8)0U);/* '<S1541>/Switch' */

/* 规范：换档请求信号 */
MONPRM volatile uint8 VHMI_12VBatLowVolSta_enum = ((uint8)0U);/* '<S576>/Switch' */
MONPRM volatile float32 VHMI_GrDSldDist_m = 0.0F;/* '<S590>/Saturation' */

/* D档后溜距离 */
MONPRM volatile boolean VHMI_GrDSldSw_flg = false;/* '<S590>/Logical Operator' */

/* D档溜坡计速/距离标志 */
MONPRM volatile float32 VHMI_GrRSldDist_m = 0.0F;/* '<S590>/Saturation1' */

/* R档前溜距离 */
MONPRM volatile boolean VHMI_GrRSldSw_flg = false;/* '<S590>/Logical Operator4' */

/* R档溜坡计速/距离标志 */
MONPRM volatile uint8 VHMI_InfoDisp_enum = ((uint8)0U);/* '<S579>/Arbitration' */

/* 仪表弹窗值 */
MONPRM volatile boolean VHVM_ACChrgEnbl_flg = false;/* '<S728>/Logical Operator8' */

/* 交流充电基本条件满足 */
MONPRM volatile boolean VHVM_ACChrging2Stop_flg = false;/* '<S722>/AND' */

/* 交流充电中转移到充电停止标志位 */
MONPRM volatile boolean VHVM_ACDchaEnbl_flg = false;/* '<S728>/Logical Operator10' */

/* 交流放电基本条件满足 */
MONPRM volatile boolean VHVM_ACDschrging2Stop_flg = false;/* '<S722>/AND7' */

/* 交流放电中转移到放电停止标志位 */
MONPRM volatile EnumBMSSdnCmd VHVM_BMSShutdown_enum = EnumBMSSdnCmd_Normal;/* '<S701>/Data Type Conversion10' */

/* VCU关闭BMS指令对应CAN信号：VCU_BMS_Shutdown */
MONPRM volatile EnumBMSWakeUpMd VHVM_BMSWakeUpMode_enum = EnumBMSWakeUpMd_Invld;/* '<S701>/Data Type Conversion8' */

/* VCU唤醒BMS的方式对应CAN信号：VCU_BMS_WakeupMode */
MONPRM volatile boolean VHVM_Bat2DrvTrainEnbl_flg = false;/* '<S701>/MainState' */

/* VCU控制主继电器指令对应CAN信号：VCU_Bat2DrvTrainEnb */
MONPRM volatile EnumChrgAllwCmd VHVM_ChrgAllowCmd_enum =
  EnumChrgAllwCmd_NotAllwd;            /* '<S701>/Data Type Conversion12' */

/* VCU发送允许充电指令对应CAN信号：VCU_ChrgAllowCmd */
MONPRM volatile uint8 VHVM_ChrgEnaAC_enum = ((uint8)0U);/* '<S701>/MainState' */

/* VCU控制OBC交流充电使能指令对应CAN信号：VCU_ChrgEna_AC */
MONPRM volatile boolean VHVM_ChrgEnaDC_flg = false;/* '<S701>/MainState' */

/* VCU控制BMS直流充电使能指令对应CAN信号：VCU_ChrgEna_DC */
MONPRM volatile float32 VHVM_DCCBuckLVVolt_V = 0.0F;/* '<S701>/MainState' */

/* VCU控制DCDC BUCK电压值对应CAN信号：VCU_DCCBuckLV_Vol */
MONPRM volatile EnumDCCOprtCmd VHVM_DCCOprtCmd_enum = EnumDCCOprtCmd_Off;/* '<S701>/Data Type Conversion6' */

/* VCU控制DCDC工作模式指令对应CAN信号：VCU_DCCOprtCmd */
MONPRM volatile boolean VHVM_DCChrgEnbl_flg = false;/* '<S728>/Logical Operator2' */

/* 直流充电基本条件满足 */
MONPRM volatile boolean VHVM_DCChrging2Over_flg = false;/* '<S722>/AND1' */

/* 直流充电中转移到充电结束标志位 */
MONPRM volatile boolean VHVM_ECUSleepAllwd_flg = false;/* '<S701>/MainState' */

/* 允许底层休眠标志位 */
MONPRM volatile boolean VHVM_EmgcySdn_flg = false;/* '<S701>/MainState' */

/* VCU给INV发送紧急下电指令(INV强制停机)对应CAN信号：VCU_1_EmShutDown */
MONPRM volatile boolean VHVM_EnaDisChg_flg = false;/* '<S701>/MainState' */

/* VCU控制INV泄放指令对应CAN信号：VCU_1_EnaDisChg */
MONPRM volatile boolean VHVM_EngyExtrmLo_flg = false;/* '<S704>/Logical Operator17' */

/* 电池能量极低标志位 */
MONPRM volatile boolean VHVM_INVEnbl_flg = false;/* '<S701>/MainState' */

/* VCU硬线唤醒INV */
MONPRM volatile boolean VHVM_INVPreprogmFlg_flg = false;/* '<S723>/Switch1' */

/* INV预编程条件满足 */
MONPRM volatile float32 VHVM_MaxChrgCurntDC_A = 0.0F;/* '<S701>/MainState' */

/* VCU允许BMS直流充电最大电流对应CAN信号：VCU_MaxChrgCrnt_DC */
MONPRM volatile float32 VHVM_MaxChrgVoltDC_V = 0.0F;/* '<S701>/MainState' */

/* VCU允许BMS直流充电最大电压对应CAN信号：VCU_MaxChrgVol_DC */
MONPRM volatile float32 VHVM_MaxHVDCCurntAC_A = 0.0F;/* '<S701>/MainState' */

/* VCU允许OBC交流充电最大电流对应CAN信号：VCU_MaxHVDC_Cur_AC */
MONPRM volatile float32 VHVM_MaxHVDCVoltAC_V = 0.0F;/* '<S701>/MainState' */

/* VCU允许OBC交流充电最大电压对应CAN信号：VCU_MaxHVDC_Vol_AC */
MONPRM volatile EnumOBCOprtCmd VHVM_OBCOprtCmd_enum = EnumOBCOprtCmd_Standby;/* '<S702>/Data Type Conversion4' */

/* VCU控制OBC工作模式指令对应CAN信号：VCU_OBCOprtCmd */
MONPRM volatile EnumPTActMd VHVM_PTActOprtMode_enum = EnumPTActMd_OFF;/* '<S701>/Data Type Conversion4' */

/* 高压PT状态 */
MONPRM volatile boolean VHVM_PTRdy2PTStdby_flg = false;/* '<S725>/Switch1' */

/* PTRdy到PTStdby标志位 */
MONPRM volatile boolean VHVM_PTStdby2PTRdy_flg = false;/* '<S725>/Switch' */

/* PTStdby到PTRdy标志位 */
MONPRM volatile boolean VHVM_PowUpSelfChek_flg = false;/* '<S726>/Switch' */

/* 高压自检标志位 */
MONPRM volatile boolean VHVM_PwrOn2PwrDwn_flg = false;/* '<S727>/Switch' */

/* 高压下电条件满足标志位（正常/故障/紧急） */
MONPRM volatile boolean VHVM_SOPExtrmLo_flg = false;/* '<S704>/Relational Operator4' */

/* 电池SOP极低，用于关闭DCDC */
MONPRM volatile EnumSysSta VHVM_SysSta_enum = EnumSysSta_Sleep;/* '<S701>/Data Type Conversion2' */

/* 高压子状态 */
MONPRM volatile uint8 VHVM_TBOX2OBC_emun = ((uint8)0U);/* '<S702>/Switch1' */

/* TBOX远程充放电指令 */
MONPRM volatile EnumVCUMode VHVM_VCUMode_enum = EnumVCUMode_PwrOff;/* '<S701>/Data Type Conversion' */

/* 高压主转态 */
MONPRM volatile boolean VHVM_VehHalt_flg = false;/* '<S717>/Switch4' */

/* 车辆停止标志位（车速极其） */
MONPRM volatile boolean VHVM_WakeUp2PwrUpACChrg_flg = false;/* '<S728>/Logical Operator16' */

/* 交流充电唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpACDcha_flg = false;/* '<S728>/Logical Operator26' */

/* 交流放电唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpDCChrg_flg = false;/* '<S728>/Logical Operator4' */

/* 直流充电唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpIBS_flg = false;/* '<S728>/Logical Operator6' */

/* IBS唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpKL15_flg = false;/* '<S728>/Logical Operator' */

/* K15唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUp_flg = false;/* '<S728>/Switch' */

/* 唤醒到上高压条件满足（唤醒源上升沿+高压自检通过） */
MONPRM volatile boolean VHVM_WakeUpBMS_flg = false;/* '<S701>/MainState' */

/* VCU硬线唤醒BMS */
MONPRM volatile boolean VHVM_WakeUpVCU_flg = false;/* '<S729>/Switch' */

/* 休眠到唤醒条件满足 */
MONPRM volatile boolean VIBS_BMSBatSOCAllow_flg = false;/* '<S952>/Switch3' */

/* 动力电池SOC允许补电标志位_versteckt */
MONPRM volatile boolean VIBS_ChgNumAllow_flg = false;/* '<S952>/AND' */

/* 补电次数允许标志位_versteckt */
MONPRM volatile uint8 VIBS_ChgNum_cnt = ((uint8)0U);/* '<S952>/Switch2' */

/* IBS补电次数_versteckt */
MONPRM volatile boolean VIBS_ChrgBascCond_flg = false;/* '<S952>/Logical Operator2' */

/* 补电基本条件满足（补电次数及电压）_versteckt */
MONPRM volatile boolean VIBS_ChrgEnbl_flg = false;/* '<S952>/Logical Operator7' */

/* IBS充电使能标志位_versteckt */
MONPRM volatile boolean VIBS_ChrgOver_flg = false;/* '<S950>/ChrgSt' */

/* IBS补电结束标志位_versteckt */
MONPRM volatile float32 VIBS_ChrgVoltThr_V = 0.0F;/* '<S953>/VoltState' */

/* 补电电压阈值_versteckt */
MONPRM volatile float32 VIBS_EnvirTemp_C = 0.0F;/* '<S972>/Switch' */

/* IBS环境温度_versteckt */
MONPRM volatile uint8 VIBS_FailChgNum_cnt = ((uint8)0U);/* '<S952>/Switch5' */

/* IBS补电失败次数_versteckt */
MONPRM volatile boolean VIBS_FbRctWup_flg = false;/* '<S952>/Logical Operator6' */

/* IBS禁止RTC唤醒标志位_versteckt */
MONPRM volatile boolean VIBS_HVReq_flg = false;/* '<S952>/Switch' */

/* IBS请求上高压标志位_versteckt */
MONPRM volatile float32 VIBS_HwKL30_V = 0.0F;/* '<S971>/Switch' */

/* 滤波后的KL30电压_versteckt */
MONPRM volatile boolean VIBS_NMReq_flg = false;/* '<S959>/Switch4' */

/* IBS请求网络标志位_versteckt */
MONPRM volatile uint16 VIBS_NextRtcWupThr_min = ((uint16)0U);/* '<S953>/Switch1' */

/* 下次补电唤醒RTC的时间_versteckt */
MONPRM volatile EnumIBSChrgSt VIBS_RTCChrgSt_enum = EnumIBSChrgSt_Idle;/* '<S950>/Data Type Conversion' */

/* IBS补电状态_versteckt */
MONPRM volatile boolean VIBS_RTCWakeup_flg = false;/* '<S977>/Chart' */

/* RTC唤醒标志位（含延迟时间）_versteckt */
MONPRM volatile boolean VIBS_SleepAllwd_flg = false;/* '<S952>/SleepAllwd' */

/* IBS允许底层休眠标志位_versteckt */
MONPRM volatile uint16 VIBS_WupChgTmThr_min = ((uint16)0U);/* '<S953>/Switch2' */

/* IBS补电时间阈值_versteckt */
MONPRM volatile boolean VIBS_WupVoltAllow_flg = false;/* '<S973>/Switch4' */

/* KL30电压允许标志位_versteckt */
MONPRM volatile boolean VIPC_ACCCfgd_flg = false;/* '<S828>/Switch8' */
MONPRM volatile boolean VIPC_AccPed1Flt_flg = false;/* '<S832>/Logical Operator1' */
MONPRM volatile boolean VIPC_AccPed1LrnDwnActv_flg = false;/* '<S842>/Relational Operator' */
MONPRM volatile boolean VIPC_AccPed1LrnUpActv_flg = false;/* '<S835>/Logical Operator5' */
MONPRM volatile float32 VIPC_AccPed1MinPstnLrnd_pct = 0.0F;/* '<S835>/Switch2' */
MONPRM volatile float32 VIPC_AccPed1NormzAvg_pct = 0.0F;/* '<S841>/Switch' */
MONPRM volatile float32 VIPC_AccPed1NormzPstn_pct = 0.0F;/* '<S832>/Switch5' */
MONPRM volatile float32 VIPC_AccPed1SclPstn_pct = 0.0F;/* '<S836>/Divide1' */
MONPRM volatile boolean VIPC_AccPed2Flt_flg = false;/* '<S832>/Logical Operator2' */
MONPRM volatile boolean VIPC_AccPed2LrnDwnActv_flg = false;/* '<S846>/Relational Operator' */
MONPRM volatile boolean VIPC_AccPed2LrnUpActv_flg = false;/* '<S837>/Logical Operator5' */
MONPRM volatile float32 VIPC_AccPed2MinPstnLrnd_pct = 0.0F;/* '<S837>/Switch2' */
MONPRM volatile float32 VIPC_AccPed2NormzAvg_pct = 0.0F;/* '<S845>/Switch' */
MONPRM volatile float32 VIPC_AccPed2NormzPstn_pct = 0.0F;/* '<S832>/Switch7' */
MONPRM volatile float32 VIPC_AccPed2SclPstn_pct = 0.0F;/* '<S838>/Divide5' */
MONPRM volatile boolean VIPC_AccPedPstnVld_flg = false;/* '<S834>/Switch3' */
MONPRM volatile float32 VIPC_AccPedPstn_pct = 0.0F;/* '<S830>/MinMax3' */
MONPRM volatile uint8 VIPC_AccPedSnsrSta_enum = ((uint8)0U);/* '<S834>/Switch3' */
MONPRM volatile boolean VIPC_AccPedStkActv_flg = false;/* '<S833>/Logical Operator6' */
MONPRM volatile boolean VIPC_AccPedStkBrkPrsd_flg = false;/* '<S860>/Switch4' */
MONPRM volatile float32 VIPC_AccPedStkPstn_pct = 0.0F;/* '<S833>/MinMax' */
MONPRM volatile boolean VIPC_AccPedStkStab_flg = false;/* '<S862>/Relational Operator' */
MONPRM volatile float32 VIPC_AccPedWghtAvg_pct = 0.0F;/* '<S859>/Switch' */
MONPRM volatile float32 VIPC_AccPedWghtPstn_pct = 0.0F;/* '<S834>/Switch3' */
MONPRM volatile float32 VIPC_AccPedZeroPstn_pct = 0.0F;/* '<S833>/Switch' */
MONPRM volatile boolean VIPC_BrkPedPstnVld_flg = false;/* '<S825>/Logical Operator8' */
MONPRM volatile float32 VIPC_BrkPedPstn_pct = 0.0F;/* '<S825>/Saturation1' */
MONPRM volatile boolean VIPC_BrkSwActv_flg = false;/* '<S825>/Logical Operator' */
MONPRM volatile boolean VIPC_CCSCfgd_flg = false;/* '<S828>/Switch1' */
MONPRM volatile boolean VIPC_CrpCtrlCfgd_flg = false;/* '<S828>/Switch2' */
MONPRM volatile EnumCrpModeAct VIPC_CrpModeAct_enum = EnumCrpModeAct_Open;/* '<S827>/Switch12' */
MONPRM volatile EnumDrvModeAct VIPC_DrvModeAct_enum = EnumDrvModeAct_Invalid;/* '<S827>/Switch13' */
MONPRM volatile uint8 VIPC_DrvPwrIntnsty_pct = ((uint8)0U);/* '<S827>/Switch25' */
MONPRM volatile boolean VIPC_DrvSw_flg = false;/* '<S830>/Relational Operator3' */
MONPRM volatile boolean VIPC_EPBAppld_flg = false;/* '<S826>/Logical Operator2' */
MONPRM volatile boolean VIPC_EPBReld_flg = false;/* '<S826>/Logical Operator1' */
MONPRM volatile boolean VIPC_HDCCfgd_flg = false;/* '<S828>/Switch3' */
MONPRM volatile EnumRegenModeAct VIPC_RegenModeAct_enum = EnumRegenModeAct_Off;/* '<S827>/Switch15' */
MONPRM volatile uint8 VIPC_RegenPwrIntnsty_pct = ((uint8)0U);/* '<S827>/Switch28' */
MONPRM volatile boolean VIPC_SnowMode_flg = false;/* '<S827>/Switch14' */
MONPRM volatile float32 VIPC_TireRadius_m = 0.0F;/* '<S828>/TireSizeTable' */
MONPRM volatile uint8 VIPC_VehHiddenMode_enum = ((uint8)0U);/* '<S827>/VehHiddenMode' */
MONPRM volatile float32 VIPC_VehSpdDrvnMotor_kph = 0.0F;/* '<S829>/Product1' */
MONPRM volatile boolean VIPC_VehSpdDrvnVld_flg = false;/* '<S896>/Logical Operator2' */
MONPRM volatile float32 VIPC_VehSpdDrvn_kph = 0.0F;/* '<S896>/Switch7' */
MONPRM volatile boolean VIPC_VehSpdNonDrvnVld_flg = false;/* '<S897>/Logical Operator2' */
MONPRM volatile float32 VIPC_VehSpdNonDrvn_kph = 0.0F;/* '<S897>/Switch7' */
MONPRM volatile boolean VIPC_VehSpdVld_flg = false;/* '<S896>/SignalConversion' */
MONPRM volatile float32 VIPC_VehSpd_kph = 0.0F;/* '<S896>/Switch4' */
MONPRM volatile boolean VIPC_VpedAutoCrp_flg = false;/* '<S884>/Switch4' */
MONPRM volatile boolean VIPC_ZeroPstnRst_flg = false;/* '<S833>/Logical Operator3' */
MONPRM volatile boolean VIPC_iTPMSCfgd_flg = false;/* '<S828>/Switch4' */
MONPRM volatile float32 VIPM_HwAccPedCh1SuplyVolt_mV = 0.0F;/* '<S1451>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh1Volt_mV = 0.0F;/* '<S1452>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh2SuplyVolt_mV = 0.0F;/* '<S1453>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh2Volt_mV = 0.0F;/* '<S1454>/MinMax1' */
MONPRM volatile boolean VIPM_HwBMSWakeup_flg = false;/* '<S1455>/Switch4' */
MONPRM volatile boolean VIPM_HwBrkSwHi_flg = false;/* '<S1456>/Switch4' */
MONPRM volatile boolean VIPM_HwBrkSwLo_flg = false;/* '<S1457>/Switch4' */
MONPRM volatile boolean VIPM_HwCrpModeSw_flg = false;/* '<S1458>/Switch4' */
MONPRM volatile boolean VIPM_HwDrvModeSw_flg = false;/* '<S1459>/Switch4' */
MONPRM volatile boolean VIPM_HwEmgcyShutOff_flg = false;/* '<S1460>/Switch4' */
MONPRM volatile boolean VIPM_HwKL15A_flg = false;/* '<S1461>/Switch4' */
MONPRM volatile boolean VIPM_HwKL15B_flg = false;/* '<S1462>/Switch4' */
MONPRM volatile uint16 VIPM_HwKL30_mV = ((uint16)0U);/* '<S1463>/MinMax1' */
MONPRM volatile boolean VIPM_HwOBCWakeup_flg = false;/* '<S1464>/Switch4' */
MONPRM volatile boolean VIPM_HwRearFogLampSwt_flg = false;/* '<S1465>/Switch4' */
MONPRM volatile EnumPGearSwSts VIPM_HwShftPstnSwSts_enum = EnumPGearSwSts_Reld;/* '<S1466>/Switch4' */
MONPRM volatile uint16 VIPM_HwShftPstnSw_Ohm = ((uint16)0U);/* '<S1448>/HwShftPstnSw' */
MONPRM volatile boolean VIPM_HwVehCrash_flg = false;/* '<S1467>/Switch4' */
MONPRM volatile float32 VNVM_AvgPwrCnsm_kWh100km = 0.0F;/* '<S1449>/Add2' */

/* _versteckt */
MONPRM volatile float32 VNVM_AvgSOCCnsmWght_pctp100km = 0.0F;/* '<S1449>/Add6' */

/* _versteckt */
MONPRM volatile EnumCrpModeAct VNVM_CrpModeAct_enum = EnumCrpModeAct_Open;/* '<S1449>/Data Type Conversion1' */

/* _versteckt */
MONPRM volatile EnumDrvModeAct VNVM_DrvModeAct_enum = EnumDrvModeAct_Invalid;/* '<S1449>/Data Type Conversion23' */

/* _versteckt */
MONPRM volatile uint8 VNVM_DrvPwrIntnsty_pct = ((uint8)0U);/* '<S1449>/Selector6' */

/* _versteckt */
MONPRM volatile float32 VNVM_DynRmnMilEst_km = 0.0F;/* '<S1449>/Gain2' */

/* _versteckt */
MONPRM volatile uint8 VNVM_EEWritten_nu = ((uint8)0U);/* '<S1449>/Selector13' */

/* _versteckt */
MONPRM volatile uint8 VNVM_IBSChrgFailNum_cnt = ((uint8)0U);/* '<S1449>/Selector1' */

/* _versteckt */
MONPRM volatile uint8 VNVM_IBSChrgNum_cnt = ((uint8)0U);/* '<S1449>/Selector' */

/* _versteckt */
MONPRM volatile EnumRegenModeAct VNVM_RegenModeAct_enum = EnumRegenModeAct_Off;/* '<S1449>/Data Type Conversion24' */

/* _versteckt */
MONPRM volatile uint8 VNVM_RegenPwrIntnsty_pct = ((uint8)0U);/* '<S1449>/Selector7' */

/* _versteckt */
MONPRM volatile EnumXWhlDistErrRefSt VNVM_XWhlDistErrRefStat_enum =
  EnumXWhlDistErrRefSt_Init;           /* '<S1449>/Data Type Conversion22' */

/* _versteckt */
MONPRM volatile float32 VNVM_XWhlDistErrRef_mpkm = 0.0F;/* '<S1449>/Add1' */

/* _versteckt */
MONPRM volatile boolean VNVM_iTPMSWrng_flg = false;/* '<S1449>/Data Type Conversion21' */

/* _versteckt */
MONPRM volatile boolean VOPM_HwWakeupBMS_flg = false;/* '<S1480>/Switch4' */
MONPRM volatile float32 VRMEAvgPwrCnsm15km_kWhpkm = 0.0F;/* '<S910>/Signal Copy2' */

/* 15km平均Pwr能耗 */
MONPRM volatile float32 VRME_AvgPwrCnsm100km_kWhpkm = 0.0F;/* '<S910>/Signal Copy5' */

/* 100km平均Pwr能耗 */
MONPRM volatile float32 VRME_AvgPwrCnsm10km_kWhpkm = 0.0F;/* '<S910>/Signal Copy1' */

/* 10km平均Pwr能耗 */
MONPRM volatile float32 VRME_AvgPwrCnsm25km_kWhpkm = 0.0F;/* '<S910>/Signal Copy3' */

/* 25km平均Pwr能耗 */
MONPRM volatile float32 VRME_AvgPwrCnsm50km_kWhpkm = 0.0F;/* '<S910>/Signal Copy4' */

/* 50km平均Pwr能耗 */
MONPRM volatile float32 VRME_AvgPwrCnsm5km_kWhpkm = 0.0F;/* '<S910>/Signal Copy' */

/* 5km平均Pwr能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm100Num_pctpkm = 0.0F;/* '<S923>/Signal Copy5' */

/* 前100个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm10Num_pctpkm = 0.0F;/* '<S923>/Signal Copy1' */

/* 前10个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm15Num_pctpkm = 0.0F;/* '<S923>/Signal Copy2' */

/* 前15个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm25Num_pctpkm = 0.0F;/* '<S923>/Signal Copy3' */

/* 前25个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm50Num_pctpkm = 0.0F;/* '<S923>/Signal Copy4' */

/* 前50个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm5Num_pctpkm = 0.0F;/* '<S923>/Signal Copy' */

/* 前5个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsmWght_pctpkm = 0.0F;/* '<S923>/Switch1' */

/* 加权平均SOC能耗/km */
MONPRM volatile boolean VRME_CHTCRmnMilEstV_flg = false;/* '<S905>/Logical Operator' */

/* CHTC标准续航里程有效性 */
MONPRM volatile float32 VRME_CHTCRmnMilEst_km = 0.0F;/* '<S905>/MRME_CHTCStdRmnMil_km' */

/* CHTC标准续航查表值 */
MONPRM volatile float32 VRME_CalPwrCnsmPerTrig_kWhpkm = 0.0F;/* '<S909>/Switch4' */

/* Pwr消耗/单位里程（1km） */
MONPRM volatile boolean VRME_CalPwrCnsmTrig_flg = false;/* '<S909>/Relational Operator1' */

/* 累计里程大于单位里程（默认1km） */
MONPRM volatile float32 VRME_CalSOCCnsmPerTrig_pctptrig = 0.0F;/* '<S922>/Switch4' */

/* SOC消耗/目标里程 */
MONPRM volatile float32 VRME_CalSOCCnsmPerkm_pctpkm = 0.0F;/* '<S922>/Divide' */

/* 目标里程消耗折算为单位里程 */
MONPRM volatile float32 VRME_CalSOCCnsmTgtDist_m = 0.0F;/* '<S922>/Switch1' */

/* 单位目标行驶里程 */
MONPRM volatile boolean VRME_CalSOCCnsmTrig_flg = false;/* '<S922>/Relational Operator1' */

/* 累计里程大于目标里程 */
MONPRM volatile float32 VRME_DynRmnMilEstChgFac_c = 0.0F;/* '<S924>/MRME_DynEstRmnChgStp_c' */

/* 动态续航变化系数 */
MONPRM volatile float32 VRME_DynRmnMilEstTgt_km = 0.0F;/* '<S945>/Switch2' */

/* 动态续航目标值 */
MONPRM volatile boolean VRME_DynRmnMilEstUpdTrig_flg = false;/* '<S924>/Relational Operator2' */

/* 更新续航值 */
MONPRM volatile boolean VRME_DynRmnMilEstV_flg = false;/* '<S924>/Logical Operator1' */

/* 动态续航有效性 */
MONPRM volatile float32 VRME_DynRmnMilEst_km = 0.0F;/* '<S944>/Switch2' */

/* 动态续航限幅值 */
MONPRM volatile boolean VRME_VehStacEnbl_flg = false;/* '<S924>/Logical Operator4' */

/* 车辆静止状态 */
MONPRM volatile float32 VRME_VehTotDistCurrCyc_km = 0.0F;/* '<S922>/Gain2' */

/* 当前驾驶循环累计总里程 */
MONPRM volatile float32 VRME_VehTotPwrCurrCyc_kWh = 0.0F;/* '<S909>/Plus2' */

/* 当前驾驶循环车辆使用功率 */
MONPRM volatile float32 VRME_WLTPRmnMilEstDwLim_km = 0.0F;/* '<S922>/Product3' */

/* 动态续航下限值 */
MONPRM volatile float32 VRME_WLTPRmnMilEstUpLim_km = 0.0F;/* '<S922>/Product2' */

/* 动态续航上限值 */
MONPRM volatile float32 VRME_WLTPRmnMilEst_km = 0.0F;/* '<S922>/MRME_WLTPStdRmnMil_km' */

/* WLTP标准续航查表值 */
MONPRM volatile float32 VRME_WLTPStdPwrCnsm_kWhpkm = 0.0F;/* '<S909>/Gain5' */

/* 标准工况下电耗 */
MONPRM volatile float32 VRME_WLTPStdSOCCnsm_pctpkm = 0.0F;/* '<S922>/Gain3' */

/* 标准工况下SOC消耗/km */
MONPRM volatile boolean VTBX_VCUChrgngCondsFb_flg = false;/* '<S983>/Compare' */
MONPRM volatile uint8 VTBX_VCULckVehWrn_enum = ((uint8)0U);/* '<S982>/Switch3' */
MONPRM volatile boolean VTBX_VCUOprtLicFb_flg = false;/* '<S984>/Compare' */
MONPRM volatile uint8 VTBX_VCUSpdLimLvlFb_enum = ((uint8)0U);/* '<S982>/Switch2' */
MONPRM volatile uint8 VTBX_VCUSpdLimLvlSetFb_enum = ((uint8)0U);/* '<S982>/Switch1' */
MONPRM volatile boolean VTBX_VCUVerFb_flg = false;/* '<S985>/Chart' */
MONPRM volatile uint8 VTBX_VCUVerSetFb_enum = ((uint8)0U);/* '<S982>/Switch6' */
MONPRM volatile float32 VTQC_ABSorESPActvTm_s = 0.0F;/* '<S1256>/MinMax' */
MONPRM volatile float32 VTQC_BrkRegenMaxTqWhl_Nm = 0.0F;/* '<S1251>/Switch17' */
MONPRM volatile float32 VTQC_BrkRegenTgtTqWhl_Nm = 0.0F;/* '<S1251>/Switch2' */
MONPRM volatile float32 VTQC_CstRegenLmtTq_Nm = 0.0F;/* '<S1249>/CstRegenLmtTq' */
MONPRM volatile float32 VTQC_DrvTqReqWhlABS_Nm = 0.0F;/* '<S1249>/MinMax1' */
MONPRM volatile float32 VTQC_DrvTqReqWhlRBS_Nm = 0.0F;/* '<S1258>/MinMax5' */
MONPRM volatile float32 VTQC_DrvTqReqWhl_Nm = 0.0F;/* '<S1250>/Switch5' */
MONPRM volatile float32 VTQC_MotorTqReq_Nm = 0.0F;/* '<S1250>/Divide' */
MONPRM volatile boolean VTQC_RBSActv_flg = false;/* '<S1259>/Switch4' */
MONPRM volatile float32 VTQD_AccelPedPstnRescl_pct = 0.0F;/* '<S1270>/Product' */
MONPRM volatile float32 VTQD_AdaptCstDeltaAcceltn_mps2 = 0.0F;/* '<S1286>/Add5' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqFF_Nm = 0.0F;/* '<S1286>/Add2' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqI_N = 0.0F;/* '<S1286>/Saturation2' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqPID_Nm = 0.0F;/* '<S1286>/Product6' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqP_N = 0.0F;/* '<S1286>/Product3' */
MONPRM volatile float32 VTQD_AdaptCstMaxTqWhl_Nm = 0.0F;/* '<S1282>/MinMax4' */
MONPRM volatile float32 VTQD_AdaptCstMinTqWhl_Nm = 0.0F;/* '<S1282>/MinMax5' */
MONPRM volatile boolean VTQD_AdaptCstRegenEnbl_flg = false;/* '<S1282>/Logical Operator9' */
MONPRM volatile float32 VTQD_AdaptCstTgtAcceltn_mps2 = 0.0F;/* '<S1288>/Switch' */
MONPRM volatile float32 VTQD_AdaptCstTqReqWhl_Nm = 0.0F;/* '<S1286>/MinMax6' */
MONPRM volatile boolean VTQD_BkwdDrv_flg = false;/* '<S1309>/Switch4' */
MONPRM volatile boolean VTQD_BrkRegenEnbl_flg = false;/* '<S1281>/Logical Operator1' */
MONPRM volatile float32 VTQD_CrpTqReqWhl_Nm = 0.0F;/* '<S1272>/Switch2' */
MONPRM volatile boolean VTQD_CstRegenEnbl_flg = false;/* '<S1281>/Logical Operator13' */
MONPRM volatile float32 VTQD_CstRegenEndPstn_pct = 0.0F;/* '<S1281>/Switch2' */
MONPRM volatile float32 VTQD_CstRegenTqReqWhl_Nm = 0.0F;/* '<S1283>/Switch4' */
MONPRM volatile float32 VTQD_DrvTqDrtFac_c = 0.0F;/* '<S1310>/Saturation' */
MONPRM volatile float32 VTQD_DrvTqReqWhlMrg_Nm = 0.0F;/* '<S1311>/Switch4' */
MONPRM volatile float32 VTQD_DrvTqReqWhlRaw_Nm = 0.0F;/* '<S1270>/Merge' */
MONPRM volatile float32 VTQD_DrvTqReqWhl_Nm = 0.0F;/* '<S1268>/Switch3' */
MONPRM volatile boolean VTQD_DsblCrp_flg = false;/* '<S1272>/Logical Operator12' */
MONPRM volatile float32 VTQD_FullPedDrvTqWhl_Nm = 0.0F;/* '<S1270>/Signal Conversion1' */
MONPRM volatile float32 VTQD_FwdPedMap_pct = 0.0F;/* '<S1273>/Switch9' */
MONPRM volatile float32 VTQD_PedalTqReqWhlRaw_Nm = 0.0F;/* '<S1267>/Add' */
MONPRM volatile uint16 VTQD_TaskRunCounter_cnt = ((uint16)0U);/* '<S1030>/Max1' */

/* test signal, to be deleted */
MONPRM volatile boolean VTQD_TqZeroFast_flg = false;/* '<S1302>/Logical Operator4' */
MONPRM volatile boolean VTQD_TqZeroSlow_flg = false;/* '<S1302>/Logical Operator2' */
MONPRM volatile boolean VTQD_TqZero_flg = false;/* '<S1302>/Logical Operator1' */
MONPRM volatile float32 VTQF_DrvTqReqWhl_Nm = 0.0F;/* '<S1326>/Switch2' */
MONPRM volatile float32 VTQF_TipOutTqDecRateCoeff_rat = 0.0F;/* '<S1328>/1-D Lookup Table1' */
MONPRM volatile boolean VTQF_TqInc_flg = false;/* '<S1338>/Switch4' */
MONPRM volatile float32 VTQF_TqOutChgRate_Nmps = 0.0F;/* '<S1348>/Switch' */
MONPRM volatile float32 VTQF_TqRateDecTgtMax_Nmps = 0.0F;/* '<S1328>/Switch3' */
MONPRM volatile float32 VTQF_TqRateDecTgtMin_Nmps = 0.0F;/* '<S1328>/MinMax4' */
MONPRM volatile float32 VTQF_TqRateIncTgtMax_Nmps = 0.0F;/* '<S1329>/Switch5' */
MONPRM volatile float32 VTQF_TqRateIncTgtMin_Nmps = 0.0F;/* '<S1329>/MinMax4' */
MONPRM volatile float32 VTQF_TqRateLimDec_Nmps = 0.0F;/* '<S1328>/MinMax3' */
MONPRM volatile boolean VTQF_TqRateLimEndg_flg = false;/* '<S1327>/Logical Operator9' */
MONPRM volatile float32 VTQF_TqRateLimInc_Nmps = 0.0F;/* '<S1329>/MinMax2' */
MONPRM volatile float32 VTQF_TqRawChgRate_Nmps = 0.0F;/* '<S1347>/Switch' */
MONPRM volatile float32 VTQF_WhlDrgMaxTqZX_Nm = 0.0F;/* '<S1346>/Switch1' */
MONPRM volatile float32 VTQF_WhlDrvMaxTqZX_Nm = 0.0F;/* '<S1346>/Switch7' */
MONPRM volatile boolean VTQR_ASDEnbl_flg = false;/* '<S1351>/Logical Operator14' */
MONPRM volatile float32 VTQR_ASDSpdFltHi_rpm = 0.0F;/* '<S1359>/Switch' */
MONPRM volatile float32 VTQR_ASDSpdOscRaw_rpm = 0.0F;/* '<S1355>/Add1' */
MONPRM volatile float32 VTQR_ASDSpdOsc_rpm = 0.0F;/* '<S1357>/Multiport Switch' */
MONPRM volatile float32 VTQR_ASDTqReqRaw_Nm = 0.0F;/* '<S1363>/MinMax5' */
MONPRM volatile float32 VTQR_ASDTqReq_Nm = 0.0F;/* '<S1356>/Switch3' */
MONPRM volatile boolean VTQR_MotDampngEnbl_flg = false;/* '<S1351>/Logical Operator1' */
MONPRM volatile float32 VTQR_MotDampngLmt_Nm = 0.0F;/* '<S1371>/MinMax5' */
MONPRM volatile EnumMotorDirReq VTQR_MotorDirReq_enum = EnumMotorDirReq_Stdby;/* '<S1352>/Switch4' */
MONPRM volatile EnumMotorModeReq VTQR_MotorModeReq_enum = EnumMotorModeReq_Stdby;/* '<S1349>/Signal Conversion15' */
MONPRM volatile float32 VTQR_MotorSpdReq_rpm = 0.0F;/* '<S1349>/Signal Conversion1' */
MONPRM volatile boolean VTQR_MotorStdby_flg = false;/* '<S1353>/Logical Operator1' */
MONPRM volatile float32 VTQR_MotorTqReq_Nm = 0.0F;/* '<S1349>/Signal Conversion2' */
MONPRM volatile float32 VTZX_AZDecRate_Nmps = 0.0F;/* '<S1387>/1-D Lookup Table4' */
MONPRM volatile float32 VTZX_AZIncRate_Nmps = 0.0F;/* '<S1387>/1-D Lookup Table3' */
MONPRM volatile float32 VTZX_BZDecRate_Nmps = 0.0F;/* '<S1387>/1-D Lookup Table2' */
MONPRM volatile float32 VTZX_BZIncRate_Nmps = 0.0F;/* '<S1387>/1-D Lookup Table1' */
MONPRM volatile boolean VTZX_BypZX_flg = false;/* '<S1391>/Logical Operator1' */
MONPRM volatile boolean VTZX_ClkActv_flg = false;/* '<S1390>/Switch4' */
MONPRM volatile float32 VTZX_ClkZXTm_s = 0.0F;/* '<S1383>/Switch1' */
MONPRM volatile float32 VTZX_MotorTqReqPrdt_Nm = 0.0F;/* '<S1403>/MinMax5' */
MONPRM volatile float32 VTZX_MotorTqReqZX_Nm = 0.0F;/* '<S1388>/TqZXSt' */
MONPRM volatile float32 VTZX_MotorTqReq_Nm = 0.0F;/* '<S1383>/Switch6' */
MONPRM volatile boolean VTZX_TqInc_flg = false;/* '<S1397>/Switch4' */
MONPRM volatile boolean VTZX_TqRateLimRamp_flg = false;/* '<S1404>/Switch4' */
MONPRM volatile EnumTZXStat VTZX_TqZXSt_enum = EnumTZXStat_NTRL;/* '<S1388>/Data Type Conversion1' */
MONPRM volatile float32 VTZX_ZeroTqHldDec_Nm = 0.0F;/* '<S1388>/TqZXSt' */
MONPRM volatile float32 VTZX_ZeroTqHldInc_Nm = 0.0F;/* '<S1388>/TqZXSt' */
MONPRM volatile float32 VTZX_ZeroTqOfstDec_Nm = 0.0F;/* '<S1387>/Switch3' */
MONPRM volatile float32 VTZX_ZeroTqOfstInc_Nm = 0.0F;/* '<S1387>/Switch2' */
MONPRM volatile float32 VTZX_ZeroTqOfst_Nm = 0.0F;/* '<S1387>/Switch4' */
MONPRM volatile float32 VTZX_ZeroXTm_s = 0.0F;/* '<S1387>/Switch8' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr1_mpkm = 0.0F;/* '<S998>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr2_mpkm = 0.0F;/* '<S998>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr3_mpkm = 0.0F;/* '<S998>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr4_mpkm = 0.0F;/* '<S998>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr5_mpkm = 0.0F;/* '<S998>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr_mpkm = 0.0F;/* '<S998>/Add3' */
MONPRM volatile float32 VVSO_DrvDist_m = 0.0F;/* '<S1011>/Switch1' */
MONPRM volatile float32 VVSO_RoadSlopEst_pct = 0.0F;/* '<S992>/Product19' */
MONPRM volatile float32 VVSO_RoadSlopTqEst_Nm = 0.0F;/* '<S996>/MinMax5' */
MONPRM volatile float32 VVSO_SlopEst_rat = 0.0F;/* '<S1020>/Switch' */
MONPRM volatile float32 VVSO_VehDrvResistTq_Nm = 0.0F;/* '<S992>/Switch4' */
MONPRM volatile float32 VVSO_VehMassEst_kg = 0.0F;/* '<S1019>/Switch' */
MONPRM volatile float32 VVSO_VehSpd_kph = 0.0F;/* '<S1002>/Gain1' */
MONPRM volatile boolean VVSO_WhlDistErrHld_flg = false;/* '<S1002>/OR' */
MONPRM volatile EnumXWhlDistErrRefSt VVSO_XWhlDistErrRefStat_enum =
  EnumXWhlDistErrRefSt_Init;           /* '<S998>/Signal Conversion2' */
MONPRM volatile float32 VVSO_XWhlDistErrRef_mpkm = 0.0F;/* '<S998>/Signal Conversion1' */
MONPRM volatile float32 VVSO_XWhlDistErr_m = 0.0F;/* '<S1011>/Switch4' */
MONPRM volatile boolean VVSO_iTPMSAvail_flg = false;/* '<S1002>/Logical Operator' */
MONPRM volatile EnumiTPMSSt VVSO_iTPMSState_enum = EnumiTPMSSt_Init;/* '<S998>/Signal Conversion' */
MONPRM volatile boolean VVSO_iTPMSWrng_flg = false;/* '<S998>/Signal Conversion3' */
MONPRM volatile boolean VVTM_BrkPedReld_flg = false;/* '<S1429>/Logical Operator3' */
MONPRM volatile uint8 VVTM_DrvMotorSta_enum = ((uint8)0U);/* '<S1436>/DriveMotorState' */
MONPRM volatile boolean VVTM_ESPIntvActv_flg = false;/* '<S1429>/Logical Operator4' */
MONPRM volatile float32 VVTM_MotorActPwr_kW = 0.0F;/* '<S1443>/Switch2' */
MONPRM volatile float32 VVTM_MotorSpd_rpm = 0.0F;/* '<S1431>/Switch' */
MONPRM volatile boolean VVTM_PCUFailSta_flg = false;/* '<S1436>/Logical Operator2' */
MONPRM volatile boolean VVTM_RegenReqBrkLampOn_flg = false;/* '<S1441>/Switch1' */
MONPRM volatile float32 VVTM_RsrvPwr_kW = 0.0F;/* '<S1438>/MinMax4' */
MONPRM volatile float32 VVTM_RsrvRecupPwr_kW = 0.0F;/* '<S1438>/MinMax1' */
MONPRM volatile float32 VVTM_VehAcceltn_mps2 = 0.0F;/* '<S1434>/Switch' */
MONPRM volatile uint8 VVTM_VehActGrPstn_enum = ((uint8)0U);/* '<S1429>/Switch1' */
MONPRM volatile float32 VVTM_VehSpd_kph = 0.0F;/* '<S1430>/Switch' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
