/*
 * File: monPrmsVcu.c
 *
 * Code generated for Simulink model 'AppSwcVcu'.
 *
 * Model version                  : 9.604
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Oct 30 14:09:32 2024
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
MONPRM volatile boolean BSW_RTCWakeup_flg = false;/* '<S1024>/Switch4' */

/* RTC唤醒标志位_versteckt */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Day = ((uint8)0U);/* '<S99>/Data Type Conversion45' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Hour = ((uint8)0U);/* '<S99>/Data Type Conversion1' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Min = ((uint8)0U);/* '<S99>/Data Type Conversion2' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Month = ((uint8)0U);/* '<S99>/Data Type Conversion34' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Sec = ((uint8)0U);/* '<S99>/Switch2' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Year = ((uint8)0U);/* '<S99>/Data Type Conversion33' */
MONPRM volatile uint8 VBSW_WakeupReasn_enum = ((uint8)0U);/* '<S1460>/EcuWakeupReasn' */

/* _versteckt */
MONPRM volatile float32 VCPT_MotorDrgMaxTq_Nm = 0.0F;/* '<S1117>/MinMax6' */
MONPRM volatile float32 VCPT_MotorDrvMaxTq_Nm = 0.0F;/* '<S1117>/MinMax7' */
MONPRM volatile float32 VCPT_MotorGenMaxTq_Nm = 0.0F;/* '<S1129>/Switch1' */
MONPRM volatile float32 VCPT_MotorMotMaxTq_Nm = 0.0F;/* '<S1128>/Switch1' */
MONPRM volatile boolean VCPT_MotorSpdRvrs_flg = false;/* '<S1117>/Switch3' */
MONPRM volatile float32 VCPT_MotorSpd_rpm = 0.0F;/* '<S1123>/Switch' */
MONPRM volatile float32 VCPT_WhlDrgMaxTq_Nm = 0.0F;/* '<S1117>/MinMax1' */
MONPRM volatile float32 VCPT_WhlDrvMaxTq_Nm = 0.0F;/* '<S1117>/MinMax8' */
MONPRM volatile boolean VDAC_ACCAvail_flg = false;/* '<S1138>/Logical Operator9' */
MONPRM volatile float32 VDAC_ACCDeltaAcceltn_mps2 = 0.0F;/* '<S1145>/Add5' */
MONPRM volatile float32 VDAC_ACCDsrdTqFF_Nm = 0.0F;/* '<S1145>/Add3' */
MONPRM volatile float32 VDAC_ACCDsrdTqI_N = 0.0F;/* '<S1145>/Saturation1' */
MONPRM volatile float32 VDAC_ACCDsrdTqPID_Nm = 0.0F;/* '<S1145>/Product6' */
MONPRM volatile float32 VDAC_ACCDsrdTqP_N = 0.0F;/* '<S1145>/Product3' */
MONPRM volatile boolean VDAC_ACCEnbl_flg = false;/* '<S1138>/Logical Operator3' */
MONPRM volatile boolean VDAC_ACCOvrd_flg = false;/* '<S1139>/Logical Operator22' */
MONPRM volatile uint8 VDAC_ACCStat_enum = ((uint8)0U);/* '<S1140>/Switch1' */
MONPRM volatile float32 VDAC_ACCTqReqWhl_Nm = 0.0F;/* '<S1141>/Merge3' */
MONPRM volatile boolean VDAC_CCActv2Stby_flg = false;/* '<S1181>/Logical Operator15' */
MONPRM volatile boolean VDAC_CCActvBascCond_flg = false;/* '<S1181>/Logical Operator1' */
MONPRM volatile float32 VDAC_CCDeltaAcceltn_mps2 = 0.0F;/* '<S1168>/Add3' */
MONPRM volatile float32 VDAC_CCDsrdAcceltnRaw_mps2 = 0.0F;/* '<S1161>/Saturation1' */
MONPRM volatile float32 VDAC_CCDsrdAcceltn_mps2 = 0.0F;/* '<S1159>/Merge1' */
MONPRM volatile float32 VDAC_CCDsrdTqFF_N = 0.0F;/* '<S1167>/Add3' */
MONPRM volatile float32 VDAC_CCDsrdTqI_N = 0.0F;/* '<S1168>/Saturation1' */
MONPRM volatile float32 VDAC_CCDsrdTqPID_N = 0.0F;/* '<S1168>/Add2' */
MONPRM volatile float32 VDAC_CCDsrdTqP_N = 0.0F;/* '<S1168>/Product2' */
MONPRM volatile boolean VDAC_CCEnbl_flg = false;/* '<S1182>/Logical Operator2' */
MONPRM volatile uint16 VDAC_CCNoActvCond_enum = ((uint16)0U);/* '<S1184>/Add' */
MONPRM volatile boolean VDAC_CCOvrd_flg = false;/* '<S1155>/Logical Operator22' */
MONPRM volatile uint16 VDAC_CCQuitCond_enum = ((uint16)0U);/* '<S1185>/Add' */
MONPRM volatile float32 VDAC_CCSpdUnstabTm_s = 0.0F;/* '<S1197>/Saturation' */
MONPRM volatile boolean VDAC_CCSpdUnstab_flg = false;/* '<S1197>/Relational Operator8' */
MONPRM volatile EnumCCState VDAC_CCSt_enum = EnumCCState_Off;/* '<S1156>/CC_State_Chart' */
MONPRM volatile boolean VDAC_CCStby2Actv_flg = false;/* '<S1181>/Logical Operator9' */
MONPRM volatile float32 VDAC_CCTgtSpdCtrl_kph = 0.0F;/* '<S1206>/Switch1' */
MONPRM volatile uint8 VDAC_CCTgtSpdHU_kph = ((uint8)0U);/* '<S1157>/TgtSpdCalc' */
MONPRM volatile EnumCCTgtSpdSt VDAC_CCTgtSpdSt_enum = EnumCCTgtSpdSt_Reset;/* '<S1157>/TgtSpdCalc' */
MONPRM volatile float32 VDAC_CCTgtSpd_kph = 0.0F;/* '<S1157>/MinMax7' */
MONPRM volatile float32 VDAC_CCTqReqWhl_Nm = 0.0F;/* '<S1160>/Merge2' */
MONPRM volatile float32 VDAC_CCVehSpdNonDrvn_kph = 0.0F;/* '<S1163>/Switch' */
MONPRM volatile boolean VDAC_CruzCncl_flg = false;/* '<S1222>/Chart' */
MONPRM volatile EnumCruiseStatus VDAC_CruzCtrlStat_enum =
  EnumCruiseStatus_NormOff;            /* '<S1155>/Switch2' */
MONPRM volatile boolean VDAC_CruzCtrlSwVld_flg = false;/* '<S1158>/Signal Conversion1' */
MONPRM volatile boolean VDAC_CruzOn_flg = true;/* '<S1158>/Signal Conversion2' */
MONPRM volatile boolean VDAC_CruzRsmActv_flg = false;/* '<S1219>/Switch4' */
MONPRM volatile boolean VDAC_CruzSetActv_flg = false;/* '<S1217>/Switch4' */
MONPRM volatile boolean VDAC_CruzSpdDecActv_flg = false;/* '<S1218>/Switch4' */
MONPRM volatile boolean VDAC_CruzSpdIncActv_flg = false;/* '<S1220>/Switch4' */
MONPRM volatile float32 VDAC_DrvAsstTqSplitEHB_Nm = 0.0F;/* '<S1134>/MinMax2' */
MONPRM volatile float32 VDAC_DrvAsstTqSplitINV_Nm = 0.0F;/* '<S1134>/Add1' */
MONPRM volatile uint8 VDAC_DrvAsstTqSts_enum = ((uint8)0U);/* '<S1134>/Switch1' */
MONPRM volatile float32 VDAC_DrvAsstTqTgt_Nm = 0.0F;/* '<S1134>/Switch2' */
MONPRM volatile boolean VDAC_EnblEHBBrkRun_flg = false;/* '<S1253>/Switch4' */
MONPRM volatile boolean VDAC_HDCActv2Idle_flg = false;/* '<S1229>/Logical Operator11' */
MONPRM volatile boolean VDAC_HDCActv2Stdby_flg = false;/* '<S1229>/Logical Operator8' */
MONPRM volatile float32 VDAC_HDCDeltaAcceltn_mps2 = 0.0F;/* '<S1234>/Add5' */
MONPRM volatile float32 VDAC_HDCDsrdTqFF_Nm = 0.0F;/* '<S1234>/Add3' */
MONPRM volatile float32 VDAC_HDCDsrdTqI_N = 0.0F;/* '<S1234>/Saturation1' */
MONPRM volatile float32 VDAC_HDCDsrdTqPID_Nm = 0.0F;/* '<S1234>/Product6' */
MONPRM volatile float32 VDAC_HDCDsrdTqP_N = 0.0F;/* '<S1234>/Product3' */
MONPRM volatile boolean VDAC_HDCIdle2Stdby_flg = false;/* '<S1229>/Logical Operator2' */
MONPRM volatile EnumHDCState VDAC_HDCSt_enum = EnumHDCState_Idle;/* '<S1132>/HDC_State_Chart' */
MONPRM volatile boolean VDAC_HDCStdby2Actv_flg = false;/* '<S1229>/Logical Operator13' */
MONPRM volatile boolean VDAC_HDCStdby2Idle_flg = false;/* '<S1229>/Logical Operator3' */
MONPRM volatile float32 VDAC_HDCTgtAcceltn_mps2 = 0.0F;/* '<S1226>/Merge1' */
MONPRM volatile float32 VDAC_HDCTgtSpd_kph = 0.0F;/* '<S1132>/HDC_State_Chart' */
MONPRM volatile float32 VDAC_HDCTqReqWhl_Nm = 0.0F;/* '<S1226>/Merge2' */
MONPRM volatile uint8 VDAC_HDCVehSpdHU_kph = ((uint8)0U);/* '<S1227>/Switch1' */
MONPRM volatile float32 VDAC_MstrCylPresrReq_bar = 0.0F;/* '<S1134>/Switch13' */
MONPRM volatile uint8 VDAC_VehSpdHU_kph = ((uint8)0U);/* '<S1208>/Switch1' */
MONPRM volatile uint8 VDAC_VirtAccPedPstnSta_enum = ((uint8)0U);/* '<S1134>/Switch11' */
MONPRM volatile float32 VDAC_VirtAccPedPstn_pct = 0.0F;/* '<S1134>/Switch8' */
MONPRM volatile float32 VDAC_VirtAccelPedPstnRaw_pct = 0.0F;/* '<S1134>/Switch9' */
MONPRM volatile float32 VDAC_VirtPedPstn_pct = 0.0F;/* '<S1134>/Switch4' */
MONPRM volatile uint8 VDAG_ACCMHVILFltSt_enum = ((uint8)0U);/* '<S558>/FltStDeb' */

/* 压缩机高压互锁故障状态 */
MONPRM volatile uint8 VDAG_ACChrgStFailFltSt_enum = ((uint8)0U);/* '<S398>/FltStDeb' */

/* ACChargeStateFail故障状态 */
MONPRM volatile uint8 VDAG_ACDchaBMSPwrLoFltSt_enum = ((uint8)0U);/* '<S404>/FltStDeb' */

/* AC放电BMS功率低故障状态 */
MONPRM volatile uint8 VDAG_ACDchaBMSSOCLoFltSt_enum = ((uint8)0U);/* '<S403>/FltStDeb' */

/* AC放电BMSSOC低故障状态 */
MONPRM volatile uint8 VDAG_ACDchaOverPwrFltSt_enum = ((uint8)0U);/* '<S397>/FltStDeb' */

/* AC放电功率超限故障 */
MONPRM volatile uint8 VDAG_ACSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S132>/FltStDeb' */

/* ACSCmd超时故障状态 */
MONPRM volatile uint8 VDAG_AccPed1ShtBattFltSt_enum = ((uint8)0U);/* '<S532>/FltStDeb' */

/* 加速踏板1路短电源故障状态 */
MONPRM volatile uint8 VDAG_AccPed1ShtGndFltSt_enum = ((uint8)0U);/* '<S529>/FltStDeb' */

/* 加速踏板1路短地故障状态 */
MONPRM volatile uint8 VDAG_AccPed1SuplyShtCircFltSt_enum = ((uint8)0U);/* '<S530>/FltStDeb' */

/* 加速踏板1路供电短路故障状态 */
MONPRM volatile uint8 VDAG_AccPed2ShtBattFltSt_enum = ((uint8)0U);/* '<S525>/FltStDeb' */

/* 加速踏板2路短电源故障状态 */
MONPRM volatile uint8 VDAG_AccPed2ShtGndFltSt_enum = ((uint8)0U);/* '<S533>/FltStDeb' */

/* 加速踏板2路短地故障状态 */
MONPRM volatile uint8 VDAG_AccPed2SuplyShtCircFltSt_enum = ((uint8)0U);/* '<S531>/FltStDeb' */

/* 加速踏板2路供电短路故障状态 */
MONPRM volatile uint8 VDAG_AccPedBothFailFltSt_enum = ((uint8)0U);/* '<S527>/FltStDeb' */

/* 加速踏板双路失效故障状态 */
MONPRM volatile uint8 VDAG_AccPedCrsChkFltSt_enum = ((uint8)0U);/* '<S526>/FltStDeb' */

/* 加速踏板相互校验故障状态 */
MONPRM volatile uint8 VDAG_BMSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S126>/FltStDeb' */

/* BMS继电器指令响应超时故障状态 */
MONPRM volatile uint8 VDAG_BMSEmgcySdnFltSt_enum = ((uint8)0U);/* '<S137>/FltStDeb' */

/* BMS紧急下电故障状态 */
MONPRM volatile uint8 VDAG_BMSSOCLoFltSt_enum = ((uint8)0U);/* '<S136>/FltStDeb' */

/* BMSSOC低故障状态 */
MONPRM volatile uint8 VDAG_BMSSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S133>/FltStDeb' */

/* BMSFailLevel1故障状态 */
MONPRM volatile uint8 VDAG_BMSSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S134>/FltStDeb' */

/* BMSFailLevel2故障状态 */
MONPRM volatile uint8 VDAG_BMSSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S135>/FltStDeb' */

/* BMSFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_BMSUndrVoltFltSt_enum = ((uint8)0U);/* '<S138>/FltStDeb' */

/* BMSPack欠压故障状态 */
MONPRM volatile uint8 VDAG_BrkPedShtBattFltSt_enum = ((uint8)0U);/* '<S555>/FltStDeb' */

/* 制动踏板短电源故障状态 */
MONPRM volatile uint8 VDAG_BrkPedShtGndFltSt_enum = ((uint8)0U);/* '<S553>/FltStDeb' */

/* 制动踏板短地故障状态 */
MONPRM volatile uint8 VDAG_BrkSwCrsChkCnt_cnt = ((uint8)0U);/* '<S545>/Data Type Conversion' */

/* 制动开关相互校验错误计数 */
MONPRM volatile uint8 VDAG_BrkSwCrsChkFltSt_enum = ((uint8)0U);/* '<S554>/FltStDeb' */

/* 制动开关相互校验故障状态 */
MONPRM volatile uint8 VDAG_CellUndrVoltFltSt_enum = ((uint8)0U);/* '<S139>/FltStDeb' */

/* BMSCell欠压故障状态 */
MONPRM volatile uint8 VDAG_DCCCmdTmOutFltSt_enum = ((uint8)0U);/* '<S300>/FltStDeb' */

/* DCDC模式指令响应超时故障状态 */
MONPRM volatile uint8 VDAG_DCCInVoltLoFltSt_enum = ((uint8)0U);/* '<S301>/FltStDeb' */

/* DCDC输入电压低故障状态 */
MONPRM volatile uint8 VDAG_DCCModeFltFltSt_enum = ((uint8)0U);/* '<S299>/FltStDeb' */

/* DCDCModeFault故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S295>/FltStDeb' */

/* DCDCFailLevel1故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S296>/FltStDeb' */

/* DCDCFailLevel2故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S297>/FltStDeb' */

/* DCDCFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl4FltSt_enum = ((uint8)0U);/* '<S298>/FltStDeb' */

/* DCDCFailLevel4故障状态 */
MONPRM volatile uint8 VDAG_DCSChrgReqFltSt_enum = ((uint8)0U);/* '<S130>/FltStDeb' */

/* DCSChargeRequest故障状态 */
MONPRM volatile uint8 VDAG_DCSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S140>/FltStDeb' */

/* DCSCmd超时故障状态 */
MONPRM volatile uint8 VDAG_DCSFailStaFltSt_enum = ((uint8)0U);/* '<S128>/FltStDeb' */

/* DCSFailState故障状态 */
MONPRM volatile uint8 VDAG_DCSInletConnectFltSt_enum = ((uint8)0U);/* '<S129>/FltStDeb' */

/* DCS插枪故障状态 */
MONPRM volatile uint8 VDAG_DCSModeFailFltSt_enum = ((uint8)0U);/* '<S131>/FltStDeb' */

/* DCSModeFail故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl1FltSt_enum = ((uint8)0U);/* '<S470>/FltStDeb' */

/* EHB1级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl2FltSt_enum = ((uint8)0U);/* '<S471>/FltStDeb' */

/* EHB2级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl3FltSt_enum = ((uint8)0U);/* '<S472>/FltStDeb' */

/* EHB3级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl4FltSt_enum = ((uint8)0U);/* '<S464>/FltStDeb' */

/* EHB4级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl5FltSt_enum = ((uint8)0U);/* '<S473>/FltStDeb' */

/* EHB5级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl1FltSt_enum = ((uint8)0U);/* '<S475>/FltStDeb' */

/* ESC1级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl2FltSt_enum = ((uint8)0U);/* '<S465>/FltStDeb' */

/* ESC2级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl3FltSt_enum = ((uint8)0U);/* '<S466>/FltStDeb' */

/* ESC3级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl4FltSt_enum = ((uint8)0U);/* '<S474>/FltStDeb' */

/* ESC4级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl5FltSt_enum = ((uint8)0U);/* '<S467>/FltStDeb' */

/* ESC5级故障状态 */
MONPRM volatile uint8 VDAG_ESCVehSpdInvldFltSt_enum = ((uint8)0U);/* '<S469>/FltStDeb' */

/* 车速失效故障状态 */
MONPRM volatile boolean VDAG_EmgcyShtdwn_flg = false;/* '<S90>/Switch30' */
MONPRM volatile uint16 VDAG_ErrCode_enum = ((uint16)0U);/* '<S88>/Err_State' */
MONPRM volatile boolean VDAG_FanFullSpdOn_flg = false;/* '<S90>/Switch3' */
MONPRM volatile boolean VDAG_FbdACC_flg = false;/* '<S90>/Switch28' */
MONPRM volatile boolean VDAG_FbdACChrg_flg = false;/* '<S90>/Switch32' */
MONPRM volatile boolean VDAG_FbdACDcha_flg = false;/* '<S90>/Switch34' */
MONPRM volatile boolean VDAG_FbdAC_flg = false;/* '<S90>/Switch35' */
MONPRM volatile boolean VDAG_FbdCC_flg = false;/* '<S90>/Switch26' */
MONPRM volatile boolean VDAG_FbdDCChrg_flg = false;/* '<S90>/Switch33' */
MONPRM volatile boolean VDAG_FbdDCDC_flg = false;/* '<S90>/Switch31' */
MONPRM volatile boolean VDAG_FbdDRGr_flg = false;/* '<S90>/Switch25' */
MONPRM volatile boolean VDAG_FbdDrvTq_flg = false;/* '<S90>/Switch23' */
MONPRM volatile boolean VDAG_FbdHV_flg = false;/* '<S90>/Switch29' */
MONPRM volatile boolean VDAG_FbdLSP_flg = false;/* '<S90>/Switch27' */
MONPRM volatile boolean VDAG_FltLampOn_flg = false;/* '<S90>/Switch36' */
MONPRM volatile uint8 VDAG_FltLvl_enum = ((uint8)0U);/* '<S90>/MinMax' */
MONPRM volatile uint8 VDAG_FrstHVILVoltHiFltSt_enum = ((uint8)0U);/* '<S557>/FltStDeb' */

/* 主要高压互锁电压高故障状态 */
MONPRM volatile uint8 VDAG_FrstHVILVoltLoFltSt_enum = ((uint8)0U);/* '<S556>/FltStDeb' */

/* 主要高压互锁电压低故障状态 */
MONPRM volatile uint8 VDAG_GearShftInvldFltSt_enum = ((uint8)0U);/* '<S468>/FltStDeb' */

/* 换挡输入失效故障状态 */
MONPRM volatile uint8 VDAG_HVIsoResistLoFltSt_enum = ((uint8)0U);/* '<S127>/FltStDeb' */

/* 高压电池绝缘故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl1FltSt_enum = ((uint8)0U);/* '<S364>/FltStDeb' */

/* INVFaultLevel1故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl2FltSt_enum = ((uint8)0U);/* '<S365>/FltStDeb' */

/* INVFaultLevel2故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl3FltSt_enum = ((uint8)0U);/* '<S366>/FltStDeb' */

/* INVFaultLevel3故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl4FltSt_enum = ((uint8)0U);/* '<S367>/FltStDeb' */

/* INVFaultLevel4故障状态 */
MONPRM volatile uint8 VDAG_INVInVoltLoFltSt_enum = ((uint8)0U);/* '<S302>/FltStDeb' */

/* INV输入电压低故障状态 */
MONPRM volatile uint8 VDAG_INVRunCmdRespFltSt_enum = ((uint8)0U);/* '<S368>/FltStDeb' */

/* INVRun指令响应超时故障状态 */
MONPRM volatile boolean VDAG_LVBatLampOn_flg = false;/* '<S90>/Switch1' */
MONPRM volatile uint8 VDAG_LVBattSOCLoFltSt_enum = ((uint8)0U);/* '<S505>/FltStDeb' */

/* 蓄电池SOC低的故障状态 */
MONPRM volatile uint8 VDAG_LVBattSOHLoFltSt_enum = ((uint8)0U);/* '<S501>/FltStDeb' */

/* 蓄电池SOH低的故障状态 */
MONPRM volatile uint8 VDAG_LVBattTempHiFltSt_enum = ((uint8)0U);/* '<S502>/FltStDeb' */

/* 蓄电池过温故障状态 */
MONPRM volatile uint8 VDAG_LVBattVoltHiFltSt_enum = ((uint8)0U);/* '<S504>/FltStDeb' */

/* 蓄电池电压高故障状态 */
MONPRM volatile uint8 VDAG_LVBattVoltLoFltSt_enum = ((uint8)0U);/* '<S503>/FltStDeb' */

/* 蓄电池电压低故障状态 */
MONPRM volatile boolean VDAG_LimpHome_flg = false;/* '<S90>/Switch2' */
MONPRM volatile boolean VDAG_LmtDrvTq_flg = false;/* '<S90>/Switch24' */
MONPRM volatile uint8 VDAG_OBCChrgReqFltSt_enum = ((uint8)0U);/* '<S402>/FltStDeb' */

/* OBCChargeRequest故障状态 */
MONPRM volatile uint8 VDAG_OBCConnectTmOutFltSt_enum = ((uint8)0U);/* '<S400>/FltStDeb' */

/* OBC连接超时故障状态 */
MONPRM volatile uint8 VDAG_OBCInletConnectFltSt_enum = ((uint8)0U);/* '<S405>/FltStDeb' */

/* OBC插枪故障状态 */
MONPRM volatile uint8 VDAG_OBCModeMsmtchFltSt_enum = ((uint8)0U);/* '<S399>/FltStDeb' */

/* OBC模式不匹配故障状态 */
MONPRM volatile uint8 VDAG_OBCS2StatFltSt_enum = ((uint8)0U);/* '<S401>/FltStDeb' */

/* OBCS2连接超时故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S406>/FltStDeb' */

/* OBCFailLevel1故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S407>/FltStDeb' */

/* OBCFailLevel2故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S408>/FltStDeb' */

/* OBCFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl4FltSt_enum = ((uint8)0U);/* '<S396>/FltStDeb' */

/* OBCFailLevel4故障状态 */
MONPRM volatile uint8 VDAG_SecdHVILVoltHiFltSt_enum = ((uint8)0U);/* '<S560>/FltStDeb' */

/* 次要高压互锁电压高故障状态 */
MONPRM volatile uint8 VDAG_SecdHVILVoltLoFltSt_enum = ((uint8)0U);/* '<S559>/FltStDeb' */

/* 次要高压互锁电压低故障状态 */
MONPRM volatile uint8 VDAG_SysPwrModeInvldFltSt_enum = ((uint8)0U);/* '<S462>/FltStDeb' */

/* PowerMode失效故障状态 */
MONPRM volatile uint8 VDAG_TMSFailLvl3FltSt_enum = ((uint8)0U);/* '<S463>/FltStDeb' */

/* TMSRFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_VehCrashFltSt_enum = ((uint8)0U);/* '<S524>/FltStDeb' */

/* 碰撞故障状态 */
MONPRM volatile boolean VDAG_WakeUp_flg = false;/* '<S326>/Chart' */

/* 硬线唤醒或者IBSLIN唤醒标志 */
MONPRM volatile uint8 VDAG_WaterTempAbvThrFltSt_enum = ((uint8)0U);/* '<S580>/FltStDeb' */

/* 冷却水温过高故障状态 */
MONPRM volatile uint8 VDAG_WaterTempBlwThrFltSt_enum = ((uint8)0U);/* '<S579>/FltStDeb' */

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
MONPRM volatile float32 VEMS_CellTempSyn_C = 0.0F;/* '<S84>/Switch1' */
MONPRM volatile float32 VEMS_CellUndrVoltDrtFac_c = 0.0F;/* '<S28>/Saturation3' */
MONPRM volatile float32 VEMS_ChrgCurFbKi_A = 0.0F;/* '<S81>/Saturation' */
MONPRM volatile float32 VEMS_ChrgCurFbKp_A = 0.0F;/* '<S81>/Product2' */
MONPRM volatile float32 VEMS_ChrgCurFb_A = 0.0F;/* '<S81>/Saturation2' */
MONPRM volatile float32 VEMS_ChrgOvrshtPwr_kW = 0.0F;/* '<S27>/Add1' */
MONPRM volatile float32 VEMS_ChrgPwrFbKi_kW = 0.0F;/* '<S46>/Saturation' */
MONPRM volatile float32 VEMS_ChrgPwrFbKp_kW = 0.0F;/* '<S46>/Product2' */
MONPRM volatile float32 VEMS_ChrgPwrFb_kW = 0.0F;/* '<S27>/Merge' */
MONPRM volatile float32 VEMS_DchaCurFbKi_A = 0.0F;/* '<S82>/Saturation' */
MONPRM volatile float32 VEMS_DchaCurFbKp_A = 0.0F;/* '<S82>/Product2' */
MONPRM volatile float32 VEMS_DchaCurFb_A = 0.0F;/* '<S82>/Saturation2' */
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
MONPRM volatile boolean VEMS_TMSActSOCEnbl_flg = false;/* '<S78>/Switch1' */

/* SOC是否限制TMS */
MONPRM volatile boolean VEMS_TMSPwrEnbl_flg = false;/* '<S30>/Switch3' */

/* 功率是否限制TMS */
MONPRM volatile float32 VEMS_TMSUsePwr_kW = 0.0F;/* '<S30>/Subtract' */

/* TMS可用功率 */
MONPRM volatile boolean VEMS_UseConChrgCur_flg = false;/* '<S37>/Switch4' */
MONPRM volatile boolean VEMS_UseConDchaCur_flg = false;/* '<S55>/Switch4' */
MONPRM volatile boolean VGSM_AsstDrvFbShft_flg = false;/* '<S1532>/Logical Operator2' */

/* 规范：ACC/CC禁止档位解析 */
MONPRM volatile boolean VGSM_AsstDrvReqEPB_flg = false;/* '<S1518>/Switch4' */

/* ACC通讯丢失或故障拉起EPB */
MONPRM volatile boolean VGSM_DRFlt2N_flg = false;/* '<S1531>/Switch1' */

/* 规范：退至非驱动档标志位 */
MONPRM volatile boolean VGSM_EPBAplyFlt_flg = false;/* '<S1508>/EPBLogical' */

/* 故障P-EPB拉起故障 */
MONPRM volatile boolean VGSM_EPBRelsFlt_flg = false;/* '<S1508>/EPBLogical' */

/* 故障P-EPB释放故障 */
MONPRM volatile boolean VGSM_GrD2PExcdTm_flg = false;/* '<S1685>/Chart' */

/* D档入P请求超时入N */
MONPRM volatile boolean VGSM_GrNReq2P_flg = false;/* '<S1531>/Switch2' */

/* N档非换挡请求进P档请求 */
MONPRM volatile boolean VGSM_GrR2PExcdTm_flg = false;/* '<S1682>/Chart' */

/* R档入P请求超时入N */
MONPRM volatile boolean VGSM_HldGearP_flg = false;/* '<S1531>/Switch' */

/* 规范：保持P档标志位 */
MONPRM volatile boolean VGSM_INVRunEnbl_flg = false;/* '<S1534>/Chart' */

/* 规范：INV使能控制（允许扭矩控制）-VCU_1_EnaInvRun */
MONPRM volatile uint8 VGSM_PGrSwSts_enum = ((uint8)0U);/* '<S1532>/Switch2' */

/* 规范：P按键触发标志位-VCU_PGearSwcst */
MONPRM volatile boolean VGSM_ReqEPBAply_flg = false;/* '<S1533>/Logical Operator6' */

/* 规范：EPB拉起请求标志位 */
MONPRM volatile boolean VGSM_ReqEPBRels_flg = false;/* '<S1533>/Logical Operator4' */

/* 规范：EPB释放请求标志位 */
MONPRM volatile EnumEPBReq VGSM_ReqEPB_enum = EnumEPBReq_NoCmd;/* '<S1508>/Switch' */

/* 规范：EPB操作信号-VCUF_ReqEPB */
MONPRM volatile EnumTgtGearPstn VGSM_ShftTgtGrReq_enum = EnumTgtGearPstn_NoReq;/* '<S1532>/Data Type Conversion1' */

/* 换挡杆目标档位 0-NoCmd 1-P 2-N 3-D 4-R  */
MONPRM volatile EnumGearPstn VGSM_VehActGearPstn_enum = EnumGearPstn_P;/* '<S1509>/Switch1' */

/* 规范：实际档位-VCU_VhclActlGearPos */
MONPRM volatile boolean VGSM_VehEPBStErr_flg = false;/* '<S1508>/Logical Operator' */

/* 规范：P档故障PGear error-VCU_VhclPGearError */
MONPRM volatile EnumTgtGearPstn VGSM_VehTgtGrReq_enum = EnumTgtGearPstn_NoReq;/* '<S1533>/Data Type Conversion1' */

/* 规范:目标档位 */
MONPRM volatile uint8 VGSM_VehTgtGrTrnsfr_enum = ((uint8)0U);/* '<S1571>/Switch' */

/* 规范：换档请求信号 */
MONPRM volatile uint8 VHMI_12VBatLowVolSta_enum = ((uint8)0U);/* '<S624>/Switch' */
MONPRM volatile float32 VHMI_GrDSldDist_m = 0.0F;/* '<S638>/Saturation' */

/* D档后溜距离 */
MONPRM volatile boolean VHMI_GrDSldSw_flg = false;/* '<S638>/Logical Operator' */

/* D档溜坡计速/距离标志 */
MONPRM volatile float32 VHMI_GrRSldDist_m = 0.0F;/* '<S638>/Saturation1' */

/* R档前溜距离 */
MONPRM volatile boolean VHMI_GrRSldSw_flg = false;/* '<S638>/Logical Operator4' */

/* R档溜坡计速/距离标志 */
MONPRM volatile uint8 VHMI_InfoDisp_enum = ((uint8)0U);/* '<S627>/Arbitration' */

/* 仪表弹窗值 */
MONPRM volatile boolean VHVM_ACChrgEnbl_flg = false;/* '<S776>/Logical Operator8' */

/* 交流充电基本条件满足 */
MONPRM volatile boolean VHVM_ACChrging2Stop_flg = false;/* '<S770>/AND' */

/* 交流充电中转移到充电停止标志位 */
MONPRM volatile boolean VHVM_ACDchaEnbl_flg = false;/* '<S776>/Logical Operator10' */

/* 交流放电基本条件满足 */
MONPRM volatile boolean VHVM_ACDschrging2Stop_flg = false;/* '<S770>/AND7' */

/* 交流放电中转移到放电停止标志位 */
MONPRM volatile EnumBMSSdnCmd VHVM_BMSShutdown_enum = EnumBMSSdnCmd_Normal;/* '<S749>/Data Type Conversion10' */

/* VCU关闭BMS指令对应CAN信号：VCU_BMS_Shutdown */
MONPRM volatile EnumBMSWakeUpMd VHVM_BMSWakeUpMode_enum = EnumBMSWakeUpMd_Invld;/* '<S749>/Data Type Conversion8' */

/* VCU唤醒BMS的方式对应CAN信号：VCU_BMS_WakeupMode */
MONPRM volatile boolean VHVM_Bat2DrvTrainEnbl_flg = false;/* '<S749>/MainState' */

/* VCU控制主继电器指令对应CAN信号：VCU_Bat2DrvTrainEnb */
MONPRM volatile EnumChrgAllwCmd VHVM_ChrgAllowCmd_enum =
  EnumChrgAllwCmd_NotAllwd;            /* '<S749>/Data Type Conversion12' */

/* VCU发送允许充电指令对应CAN信号：VCU_ChrgAllowCmd */
MONPRM volatile uint8 VHVM_ChrgEnaAC_enum = ((uint8)0U);/* '<S749>/MainState' */

/* VCU控制OBC交流充电使能指令对应CAN信号：VCU_ChrgEna_AC */
MONPRM volatile boolean VHVM_ChrgEnaDC_flg = false;/* '<S749>/MainState' */

/* VCU控制BMS直流充电使能指令对应CAN信号：VCU_ChrgEna_DC */
MONPRM volatile float32 VHVM_DCCBuckLVVolt_V = 0.0F;/* '<S749>/MainState' */

/* VCU控制DCDC BUCK电压值对应CAN信号：VCU_DCCBuckLV_Vol */
MONPRM volatile EnumDCCOprtCmd VHVM_DCCOprtCmd_enum = EnumDCCOprtCmd_Off;/* '<S749>/Data Type Conversion6' */

/* VCU控制DCDC工作模式指令对应CAN信号：VCU_DCCOprtCmd */
MONPRM volatile boolean VHVM_DCChrgEnbl_flg = false;/* '<S776>/Logical Operator2' */

/* 直流充电基本条件满足 */
MONPRM volatile boolean VHVM_DCChrging2Over_flg = false;/* '<S770>/AND1' */

/* 直流充电中转移到充电结束标志位 */
MONPRM volatile boolean VHVM_ECUSleepAllwd_flg = false;/* '<S749>/MainState' */

/* 允许底层休眠标志位 */
MONPRM volatile boolean VHVM_EmgcySdn_flg = false;/* '<S749>/MainState' */

/* VCU给INV发送紧急下电指令(INV强制停机)对应CAN信号：VCU_1_EmShutDown */
MONPRM volatile boolean VHVM_EnaDisChg_flg = false;/* '<S749>/MainState' */

/* VCU控制INV泄放指令对应CAN信号：VCU_1_EnaDisChg */
MONPRM volatile boolean VHVM_EngyExtrmLo_flg = false;/* '<S752>/Logical Operator17' */

/* 电池能量极低标志位 */
MONPRM volatile boolean VHVM_INVEnbl_flg = false;/* '<S749>/MainState' */

/* VCU硬线唤醒INV */
MONPRM volatile boolean VHVM_INVPreprogmFlg_flg = false;/* '<S771>/Switch1' */

/* INV预编程条件满足 */
MONPRM volatile float32 VHVM_MaxChrgCurntDC_A = 0.0F;/* '<S749>/MainState' */

/* VCU允许BMS直流充电最大电流对应CAN信号：VCU_MaxChrgCrnt_DC */
MONPRM volatile float32 VHVM_MaxChrgVoltDC_V = 0.0F;/* '<S749>/MainState' */

/* VCU允许BMS直流充电最大电压对应CAN信号：VCU_MaxChrgVol_DC */
MONPRM volatile float32 VHVM_MaxHVDCCurntAC_A = 0.0F;/* '<S749>/MainState' */

/* VCU允许OBC交流充电最大电流对应CAN信号：VCU_MaxHVDC_Cur_AC */
MONPRM volatile float32 VHVM_MaxHVDCVoltAC_V = 0.0F;/* '<S749>/MainState' */

/* VCU允许OBC交流充电最大电压对应CAN信号：VCU_MaxHVDC_Vol_AC */
MONPRM volatile EnumOBCOprtCmd VHVM_OBCOprtCmd_enum = EnumOBCOprtCmd_Standby;/* '<S750>/Data Type Conversion4' */

/* VCU控制OBC工作模式指令对应CAN信号：VCU_OBCOprtCmd */
MONPRM volatile EnumPTActMd VHVM_PTActOprtMode_enum = EnumPTActMd_OFF;/* '<S749>/Data Type Conversion4' */

/* 高压PT状态 */
MONPRM volatile boolean VHVM_PTRdy2PTStdby_flg = false;/* '<S773>/Switch1' */

/* PTRdy到PTStdby标志位 */
MONPRM volatile boolean VHVM_PTStdby2PTRdy_flg = false;/* '<S773>/Switch' */

/* PTStdby到PTRdy标志位 */
MONPRM volatile boolean VHVM_PowUpSelfChek_flg = false;/* '<S774>/Switch' */

/* 高压自检标志位 */
MONPRM volatile boolean VHVM_PwrOn2PwrDwn_flg = false;/* '<S775>/Switch' */

/* 高压下电条件满足标志位（正常/故障/紧急） */
MONPRM volatile boolean VHVM_SOPExtrmLo_flg = false;/* '<S752>/Relational Operator4' */

/* 电池SOP极低，用于关闭DCDC */
MONPRM volatile EnumSysSta VHVM_SysSta_enum = EnumSysSta_Sleep;/* '<S749>/Data Type Conversion2' */

/* 高压子状态 */
MONPRM volatile uint8 VHVM_TBOX2OBC_emun = ((uint8)0U);/* '<S750>/Switch1' */

/* TBOX远程充放电指令 */
MONPRM volatile EnumVCUMode VHVM_VCUMode_enum = EnumVCUMode_PwrOff;/* '<S749>/Data Type Conversion' */

/* 高压主转态 */
MONPRM volatile boolean VHVM_VehHalt_flg = false;/* '<S765>/Switch4' */

/* 车辆停止标志位（车速极其） */
MONPRM volatile boolean VHVM_WakeUp2PwrUpACChrg_flg = false;/* '<S776>/Logical Operator16' */

/* 交流充电唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpACDcha_flg = false;/* '<S776>/Logical Operator26' */

/* 交流放电唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpDCChrg_flg = false;/* '<S776>/Logical Operator4' */

/* 直流充电唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpIBS_flg = false;/* '<S776>/Logical Operator6' */

/* IBS唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpKL15_flg = false;/* '<S776>/Logical Operator' */

/* K15唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUp_flg = false;/* '<S776>/Switch' */

/* 唤醒到上高压条件满足（唤醒源上升沿+高压自检通过） */
MONPRM volatile boolean VHVM_WakeUpBMS_flg = false;/* '<S749>/MainState' */

/* VCU硬线唤醒BMS */
MONPRM volatile boolean VHVM_WakeUpVCU_flg = false;/* '<S777>/Switch' */

/* 休眠到唤醒条件满足 */
MONPRM volatile boolean VIBS_BMSBatSOCAllow_flg = false;/* '<S1002>/Switch3' */

/* 动力电池SOC允许补电标志位_versteckt */
MONPRM volatile boolean VIBS_ChgNumAllow_flg = false;/* '<S1002>/AND' */

/* 补电次数允许标志位_versteckt */
MONPRM volatile uint8 VIBS_ChgNum_cnt = ((uint8)0U);/* '<S1002>/Switch2' */

/* IBS补电次数_versteckt */
MONPRM volatile boolean VIBS_ChrgBascCond_flg = false;/* '<S1002>/Logical Operator2' */

/* 补电基本条件满足（补电次数及电压）_versteckt */
MONPRM volatile boolean VIBS_ChrgEnbl_flg = false;/* '<S1002>/Logical Operator7' */

/* IBS充电使能标志位_versteckt */
MONPRM volatile boolean VIBS_ChrgOver_flg = false;/* '<S1000>/ChrgSt' */

/* IBS补电结束标志位_versteckt */
MONPRM volatile float32 VIBS_ChrgVoltThr_V = 0.0F;/* '<S1003>/VoltState' */

/* 补电电压阈值_versteckt */
MONPRM volatile float32 VIBS_EnvirTemp_C = 0.0F;/* '<S1022>/Switch' */

/* IBS环境温度_versteckt */
MONPRM volatile uint8 VIBS_FailChgNum_cnt = ((uint8)0U);/* '<S1002>/Switch5' */

/* IBS补电失败次数_versteckt */
MONPRM volatile boolean VIBS_FbRctWup_flg = false;/* '<S1002>/Logical Operator6' */

/* IBS禁止RTC唤醒标志位_versteckt */
MONPRM volatile boolean VIBS_HVReq_flg = false;/* '<S1002>/Switch' */

/* IBS请求上高压标志位_versteckt */
MONPRM volatile float32 VIBS_HwKL30_V = 0.0F;/* '<S1021>/Switch' */

/* 滤波后的KL30电压_versteckt */
MONPRM volatile boolean VIBS_NMReq_flg = false;/* '<S1009>/Switch4' */

/* IBS请求网络标志位_versteckt */
MONPRM volatile uint16 VIBS_NextRtcWupThr_min = ((uint16)0U);/* '<S1003>/Switch1' */

/* 下次补电唤醒RTC的时间_versteckt */
MONPRM volatile EnumIBSChrgSt VIBS_RTCChrgSt_enum = EnumIBSChrgSt_Idle;/* '<S1000>/Data Type Conversion' */

/* IBS补电状态_versteckt */
MONPRM volatile boolean VIBS_RTCWakeup_flg = false;/* '<S1027>/Chart' */

/* RTC唤醒标志位（含延迟时间）_versteckt */
MONPRM volatile boolean VIBS_SleepAllwd_flg = false;/* '<S1002>/SleepAllwd' */

/* IBS允许底层休眠标志位_versteckt */
MONPRM volatile uint16 VIBS_WupChgTmThr_min = ((uint16)0U);/* '<S1003>/Switch2' */

/* IBS补电时间阈值_versteckt */
MONPRM volatile boolean VIBS_WupVoltAllow_flg = false;/* '<S1023>/Switch4' */

/* KL30电压允许标志位_versteckt */
MONPRM volatile boolean VIPC_ACCCfgd_flg = false;/* '<S874>/Switch8' */
MONPRM volatile boolean VIPC_AccPed1Flt_flg = false;/* '<S878>/Logical Operator1' */
MONPRM volatile boolean VIPC_AccPed1LrnDwnActv_flg = false;/* '<S888>/Relational Operator' */
MONPRM volatile boolean VIPC_AccPed1LrnUpActv_flg = false;/* '<S881>/Logical Operator5' */
MONPRM volatile float32 VIPC_AccPed1MinPstnLrnd_pct = 0.0F;/* '<S881>/Switch2' */
MONPRM volatile float32 VIPC_AccPed1NormzAvg_pct = 0.0F;/* '<S887>/Switch' */
MONPRM volatile float32 VIPC_AccPed1NormzPstn_pct = 0.0F;/* '<S878>/Switch5' */
MONPRM volatile float32 VIPC_AccPed1SclPstn_pct = 0.0F;/* '<S882>/Divide1' */
MONPRM volatile boolean VIPC_AccPed2Flt_flg = false;/* '<S878>/Logical Operator2' */
MONPRM volatile boolean VIPC_AccPed2LrnDwnActv_flg = false;/* '<S892>/Relational Operator' */
MONPRM volatile boolean VIPC_AccPed2LrnUpActv_flg = false;/* '<S883>/Logical Operator5' */
MONPRM volatile float32 VIPC_AccPed2MinPstnLrnd_pct = 0.0F;/* '<S883>/Switch2' */
MONPRM volatile float32 VIPC_AccPed2NormzAvg_pct = 0.0F;/* '<S891>/Switch' */
MONPRM volatile float32 VIPC_AccPed2NormzPstn_pct = 0.0F;/* '<S878>/Switch7' */
MONPRM volatile float32 VIPC_AccPed2SclPstn_pct = 0.0F;/* '<S884>/Divide5' */
MONPRM volatile boolean VIPC_AccPedPstnVld_flg = false;/* '<S880>/Switch3' */
MONPRM volatile float32 VIPC_AccPedPstn_pct = 0.0F;/* '<S876>/MinMax3' */
MONPRM volatile uint8 VIPC_AccPedSnsrSta_enum = ((uint8)0U);/* '<S880>/Switch3' */
MONPRM volatile boolean VIPC_AccPedStkActv_flg = false;/* '<S879>/Logical Operator6' */
MONPRM volatile boolean VIPC_AccPedStkBrkPrsd_flg = false;/* '<S906>/Switch4' */
MONPRM volatile float32 VIPC_AccPedStkPstn_pct = 0.0F;/* '<S879>/MinMax' */
MONPRM volatile boolean VIPC_AccPedStkStab_flg = false;/* '<S908>/Relational Operator' */
MONPRM volatile float32 VIPC_AccPedWghtAvg_pct = 0.0F;/* '<S905>/Switch' */
MONPRM volatile float32 VIPC_AccPedWghtPstn_pct = 0.0F;/* '<S880>/Switch3' */
MONPRM volatile float32 VIPC_AccPedZeroPstn_pct = 0.0F;/* '<S879>/Switch' */
MONPRM volatile boolean VIPC_BrkPedPstnVld_flg = false;/* '<S871>/Logical Operator8' */
MONPRM volatile float32 VIPC_BrkPedPstn_pct = 0.0F;/* '<S871>/Saturation1' */
MONPRM volatile boolean VIPC_BrkSwActv_flg = false;/* '<S871>/Logical Operator' */
MONPRM volatile boolean VIPC_CCSCfgd_flg = false;/* '<S874>/Switch1' */
MONPRM volatile boolean VIPC_CrpCtrlCfgd_flg = false;/* '<S874>/Switch2' */
MONPRM volatile EnumCrpModeAct VIPC_CrpModeAct_enum = EnumCrpModeAct_Open;/* '<S873>/Switch12' */
MONPRM volatile EnumDrvModeAct VIPC_DrvModeAct_enum = EnumDrvModeAct_Invalid;/* '<S873>/Switch13' */
MONPRM volatile uint8 VIPC_DrvPwrIntnsty_pct = ((uint8)0U);/* '<S873>/Switch25' */
MONPRM volatile boolean VIPC_DrvSw_flg = false;/* '<S876>/Relational Operator3' */
MONPRM volatile boolean VIPC_EPBAppld_flg = false;/* '<S872>/Logical Operator2' */
MONPRM volatile boolean VIPC_EPBReld_flg = false;/* '<S872>/Logical Operator1' */
MONPRM volatile boolean VIPC_HDCCfgd_flg = false;/* '<S874>/Switch3' */
MONPRM volatile EnumRegenModeAct VIPC_RegenModeAct_enum = EnumRegenModeAct_Off;/* '<S873>/Switch15' */
MONPRM volatile uint8 VIPC_RegenPwrIntnsty_pct = ((uint8)0U);/* '<S873>/Switch28' */
MONPRM volatile boolean VIPC_SnowMode_flg = false;/* '<S873>/Switch14' */
MONPRM volatile float32 VIPC_TireRadius_m = 0.0F;/* '<S874>/TireSizeTable' */
MONPRM volatile uint8 VIPC_VehHiddenMode_enum = ((uint8)0U);/* '<S873>/VehHiddenMode' */
MONPRM volatile float32 VIPC_VehSpdDrvnMotor_kph = 0.0F;/* '<S875>/Product1' */
MONPRM volatile boolean VIPC_VehSpdDrvnVld_flg = false;/* '<S942>/Logical Operator2' */
MONPRM volatile float32 VIPC_VehSpdDrvn_kph = 0.0F;/* '<S942>/Switch7' */
MONPRM volatile boolean VIPC_VehSpdNonDrvnVld_flg = false;/* '<S943>/Logical Operator2' */
MONPRM volatile float32 VIPC_VehSpdNonDrvn_kph = 0.0F;/* '<S943>/Switch7' */
MONPRM volatile boolean VIPC_VehSpdVld_flg = false;/* '<S942>/SignalConversion' */
MONPRM volatile float32 VIPC_VehSpd_kph = 0.0F;/* '<S942>/Switch4' */
MONPRM volatile boolean VIPC_VpedAutoCrp_flg = false;/* '<S930>/Switch4' */
MONPRM volatile boolean VIPC_ZeroPstnRst_flg = false;/* '<S879>/Logical Operator3' */
MONPRM volatile boolean VIPC_iTPMSCfgd_flg = false;/* '<S874>/Switch4' */
MONPRM volatile float32 VIPM_HwAccPedCh1SuplyVolt_mV = 0.0F;/* '<S1462>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh1Volt_mV = 0.0F;/* '<S1463>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh2SuplyVolt_mV = 0.0F;/* '<S1464>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh2Volt_mV = 0.0F;/* '<S1465>/MinMax1' */
MONPRM volatile boolean VIPM_HwBMSWakeup_flg = false;/* '<S1466>/Switch4' */
MONPRM volatile boolean VIPM_HwBrkSwHi_flg = false;/* '<S1467>/Switch4' */
MONPRM volatile boolean VIPM_HwBrkSwLo_flg = false;/* '<S1468>/Switch4' */
MONPRM volatile boolean VIPM_HwCrpModeSw_flg = false;/* '<S1469>/Switch4' */
MONPRM volatile boolean VIPM_HwDrvModeSw_flg = false;/* '<S1470>/Switch4' */
MONPRM volatile boolean VIPM_HwEmgcyShutOff_flg = false;/* '<S1471>/Switch4' */
MONPRM volatile float32 VIPM_HwHVIL1Volt_mV = 0.0F;/* '<S1472>/MinMax1' */
MONPRM volatile float32 VIPM_HwHVIL2Volt_mV = 0.0F;/* '<S1473>/MinMax1' */
MONPRM volatile boolean VIPM_HwKL15A_flg = false;/* '<S1474>/Switch4' */
MONPRM volatile boolean VIPM_HwKL15B_flg = false;/* '<S1475>/Switch4' */
MONPRM volatile uint16 VIPM_HwKL30_mV = ((uint16)0U);/* '<S1476>/MinMax1' */
MONPRM volatile boolean VIPM_HwOBCWakeup_flg = false;/* '<S1477>/Switch4' */
MONPRM volatile boolean VIPM_HwRearFogLampSwt_flg = false;/* '<S1478>/Switch4' */
MONPRM volatile EnumPGearSwSts VIPM_HwShftPstnSwSts_enum = EnumPGearSwSts_Reld;/* '<S1479>/Switch4' */
MONPRM volatile uint16 VIPM_HwShftPstnSw_Ohm = ((uint16)0U);/* '<S1459>/HwShftPstnSw' */
MONPRM volatile boolean VIPM_HwVehCrash_flg = false;/* '<S1480>/Switch4' */
MONPRM volatile float32 VNVM_AvgPwrCnsm_kWh100km = 0.0F;/* '<S1460>/Add2' */

/* _versteckt */
MONPRM volatile float32 VNVM_AvgSOCCnsmWght_pctp100km = 0.0F;/* '<S1460>/Add6' */

/* _versteckt */
MONPRM volatile EnumCrpModeAct VNVM_CrpModeAct_enum = EnumCrpModeAct_Open;/* '<S1460>/Data Type Conversion1' */

/* _versteckt */
MONPRM volatile EnumDrvModeAct VNVM_DrvModeAct_enum = EnumDrvModeAct_Invalid;/* '<S1460>/Data Type Conversion23' */

/* _versteckt */
MONPRM volatile uint8 VNVM_DrvPwrIntnsty_pct = ((uint8)0U);/* '<S1460>/Selector6' */

/* _versteckt */
MONPRM volatile float32 VNVM_DynRmnMilEst_km = 0.0F;/* '<S1460>/Gain2' */

/* _versteckt */
MONPRM volatile uint8 VNVM_EE01ReadOK_nu = ((uint8)0U);/* '<S1460>/Selector13' */

/* _versteckt */
MONPRM volatile uint8 VNVM_EEImdtReadOK_nu = ((uint8)0U);/* '<S1460>/Selector14' */

/* _versteckt */
MONPRM volatile uint8 VNVM_IBSChrgFailNum_cnt = ((uint8)0U);/* '<S1460>/Selector1' */

/* _versteckt */
MONPRM volatile uint8 VNVM_IBSChrgNum_cnt = ((uint8)0U);/* '<S1460>/Selector' */

/* _versteckt */
MONPRM volatile EnumRegenModeAct VNVM_RegenModeAct_enum = EnumRegenModeAct_Off;/* '<S1460>/Data Type Conversion24' */

/* _versteckt */
MONPRM volatile uint8 VNVM_RegenPwrIntnsty_pct = ((uint8)0U);/* '<S1460>/Selector7' */

/* _versteckt */
MONPRM volatile boolean VNVM_TBOXOffline_flg = false;/* '<S1460>/Data Type Conversion11' */

/* _versteckt */
MONPRM volatile EnumTBOXLimSt VNVM_VCUSpdLimSt_enum = EnumTBOXLimSt_Normal;/* '<S1460>/Data Type Conversion10' */

/* _versteckt */
MONPRM volatile boolean VNVM_VCUVerFb_flg = false;/* '<S1460>/Data Type Conversion12' */

/* _versteckt */
MONPRM volatile EnumXWhlDistErrRefSt VNVM_XWhlDistErrRefStat_enum =
  EnumXWhlDistErrRefSt_Init;           /* '<S1460>/Data Type Conversion22' */

/* _versteckt */
MONPRM volatile float32 VNVM_XWhlDistErrRef_mpkm = 0.0F;/* '<S1460>/Add1' */

/* _versteckt */
MONPRM volatile boolean VNVM_iTPMSWrng_flg = false;/* '<S1460>/Data Type Conversion21' */

/* _versteckt */
MONPRM volatile boolean VOPM_HwWakeupBMS_flg = false;/* '<S1494>/Switch4' */
MONPRM volatile float32 VRME_AvgSOCCnsm100Num_pctpkm = 0.0F;/* '<S981>/Signal Copy5' */

/* 前100个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm10Num_pctpkm = 0.0F;/* '<S981>/Signal Copy1' */

/* 前10个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm15Num_pctpkm = 0.0F;/* '<S981>/Signal Copy2' */

/* 前15个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm25Num_pctpkm = 0.0F;/* '<S981>/Signal Copy3' */

/* 前25个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm50Num_pctpkm = 0.0F;/* '<S981>/Signal Copy4' */

/* 前50个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm5Num_pctpkm = 0.0F;/* '<S981>/Signal Copy' */

/* 前5个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsmWght_pctpkm = 0.0F;/* '<S981>/Switch1' */

/* 加权平均SOC能耗/km */
MONPRM volatile boolean VRME_CHTCRmnMilEstV_flg = false;/* '<S951>/Logical Operator' */

/* CHTC标准续航里程有效性 */
MONPRM volatile float32 VRME_CHTCRmnMilEst_km = 0.0F;/* '<S951>/MRME_CHTCStdRmnMil_km' */

/* CHTC标准续航查表值 */
MONPRM volatile float32 VRME_CalPwrCnsmPerTrig_kWhptrig = 0.0F;/* '<S955>/Switch4' */

/* Pwr消耗/单位里程（trig） */
MONPRM volatile float32 VRME_CalPwrCnsmPerkm_kWhpkm = 0.0F;/* '<S955>/Divide' */

/* Pwr消耗/单位里程（1km） */
MONPRM volatile boolean VRME_CalPwrCnsmTrig_flg = false;/* '<S955>/Relational Operator1' */

/* 累计里程大于单位里程 */
MONPRM volatile float32 VRME_CalSOCCnsmPerTrig_pctptrig = 0.0F;/* '<S980>/Switch4' */

/* SOC消耗/单位里程（trig） */
MONPRM volatile float32 VRME_CalSOCCnsmPerkm_pctpkm = 0.0F;/* '<S980>/Divide' */

/* SOC消耗/单位里程（1km） */
MONPRM volatile float32 VRME_CalSOCCnsmTgtDist_m = 0.0F;/* '<S980>/Switch1' */

/* 单位目标行驶里程 */
MONPRM volatile boolean VRME_CalSOCCnsmTrig_flg = false;/* '<S980>/Relational Operator1' */

/* 累计里程大于目标里程 */
MONPRM volatile float32 VRME_ChrgRmnMilEstTgt_km = 0.0F;/* '<S976>/Switch2' */

/* 充电模式动态续航目标值 */
MONPRM volatile float32 VRME_ChrgRmnMilEst_km = 0.0F;/* '<S977>/Switch2' */

/* 充电工况动态续航值 */
MONPRM volatile float32 VRME_ChrgTgtFstRate_kmpsoc = 0.0F;/* '<S966>/Divide2' */

/* 充电工况目标续航追击速率 */
MONPRM volatile float32 VRME_ChrgTgtNormRate_kmpsoc = 0.0F;/* '<S966>/Divide1' */

/* 充电工况目标续航变化速率 */
MONPRM volatile float32 VRME_DchaRmnMilEstChgFac_c = 0.0F;/* '<S979>/MRME_DynEstRmnChgStp_c' */

/* 非充电模式动态续航变化系数 */
MONPRM volatile float32 VRME_DchaRmnMilEstTgt_km = 0.0F;/* '<S991>/Switch2' */

/* 非充电模式动态续航目标值 */
MONPRM volatile boolean VRME_DchaRmnMilEstUpdTrig_flg = false;/* '<S979>/Relational Operator2' */

/* 更新续航值 */
MONPRM volatile float32 VRME_DchaRmnMilEst_km = 0.0F;/* '<S990>/Switch2' */

/* 非充电模式动态续航值 */
MONPRM volatile boolean VRME_DchaVehStac_flg = false;/* '<S978>/Logical Operator4' */

/* 非充电模式车辆驻车状态 */
MONPRM volatile boolean VRME_DynRmnMilEstV_flg = false;/* '<S958>/Logical Operator1' */

/* 动态续航有效性 */
MONPRM volatile float32 VRME_DynRmnMilEst_km = 0.0F;/* '<S963>/Switch2' */

/* 综合的动态续航值 */
MONPRM volatile float32 VRME_VehPwrCnsmAvg_kWhpkm = 0.0F;/* '<S955>/Switch7' */

/* 当前循环平均能耗 */
MONPRM volatile float32 VRME_VehTotMilCyc_km = 0.0F;/* '<S955>/Gain8' */

/* 当前驾驶循环车辆里程 */
MONPRM volatile float32 VRME_VehTotPwrCyc_kWh = 0.0F;/* '<S955>/Switch6' */

/* 当前驾驶循环车辆功率 */
MONPRM volatile float32 VRME_WLTPRmnMilEstDwLim_km = 0.0F;/* '<S960>/Product3' */

/* 动态续航下限值 */
MONPRM volatile float32 VRME_WLTPRmnMilEstUpLim_km = 0.0F;/* '<S960>/Product2' */

/* 动态续航上限值 */
MONPRM volatile float32 VRME_WLTPRmnMilEst_km = 0.0F;/* '<S960>/MRME_WLTPStdRmnMil_km' */

/* WLTP标准续航查表值 */
MONPRM volatile float32 VRME_WLTPStdPwrCnsm_kWhpkm = 0.0F;/* '<S955>/Gain5' */

/* 标准工况电耗（kWh/km） */
MONPRM volatile float32 VRME_WLTPStdSOCCnsm_pctpkm = 0.0F;/* '<S960>/Gain3' */

/* 标准工况下SOC消耗/km */
MONPRM volatile boolean VTBX_CnclSpdLim_flg = false;/* '<S1034>/Logical Operator12' */

/* TBOX解除限速 */
MONPRM volatile boolean VTBX_LckVer_flg = false;/* '<S1052>/Chart' */

/* 锁车版本 */
MONPRM volatile boolean VTBX_RecryTBOXHw_flg = false;/* '<S1034>/Logical Operator14' */

/* TBOX硬件通讯丢失恢复 */
MONPRM volatile boolean VTBX_ReqLimpHome_flg = false;/* '<S1033>/Data Type Conversion6' */

/* VCU请求跛行动作 */
MONPRM volatile boolean VTBX_RmvTBOXHw_flg = false;/* '<S1034>/Logical Operator3' */

/* TBOX硬件通讯丢失 */
MONPRM volatile boolean VTBX_SpdLimLvl1_flg = false;/* '<S1034>/Logical Operator5' */

/* TBOX一级限速 */
MONPRM volatile boolean VTBX_SpdLimLvl2_flg = false;/* '<S1034>/Logical Operator7' */

/* TBOX二级限速 */
MONPRM volatile boolean VTBX_SpdLimLvl3_flg = false;/* '<S1034>/Logical Operator9' */

/* TBOX三级限速 */
MONPRM volatile boolean VTBX_StorgSpdLim_flg = false;/* '<S1034>/Logical Operator11' */

/* TBOX库存限速 */
MONPRM volatile boolean VTBX_TBOXOffline_flg = false;/* '<S1033>/Signal Copy3' */

/* TBOX硬件状态-实时存储 */
MONPRM volatile boolean VTBX_UnlckVer_flg = false;/* '<S1051>/Chart' */

/* 非锁车版本 */
MONPRM volatile boolean VTBX_VCUChrgngCondsFb_flg = false;/* '<S1033>/Data Type Conversion5' */

/* VCU反馈判断充电条件 */
MONPRM volatile uint8 VTBX_VCULckVehWrn_enum = ((uint8)0U);/* '<S1033>/Signal Copy5' */

/* VCU反馈锁存提醒 */
MONPRM volatile boolean VTBX_VCUOprtLicFb_flg = false;/* '<S1033>/Data Type Conversion4' */

/* VCU反馈运营状态 */
MONPRM volatile EnumTBOXLimGrd VTBX_VCUSpdLimLvlFb_enum = EnumTBOXLimGrd_Normal;/* '<S1033>/Data Type Conversion3' */

/* VCU反馈限速等级-当前驾驶循环 */
MONPRM volatile uint8 VTBX_VCUSpdLimLvlSetFb_enum = ((uint8)0U);/* '<S1033>/Data Type Conversion7' */

/* VCU反馈限速等级设置成功 */
MONPRM volatile EnumTBOXLimSt VTBX_VCUSpdLimSt_enum = EnumTBOXLimSt_Normal;/* '<S1033>/Data Type Conversion1' */

/* 当前循环限速状态-实时存储 */
MONPRM volatile boolean VTBX_VCUVerFb_flg = false;/* '<S1033>/Signal Copy' */

/* VCU反馈锁车版本-实时存储 */
MONPRM volatile uint8 VTBX_VCUVerSetFb_enum = ((uint8)0U);/* '<S1033>/Signal Copy1' */

/* VCU反馈锁车版本设置成功 */
MONPRM volatile float32 VTQC_ABSorESPActvTm_s = 0.0F;/* '<S1266>/MinMax' */
MONPRM volatile float32 VTQC_BrkRegenMaxTqWhl_Nm = 0.0F;/* '<S1261>/Switch17' */
MONPRM volatile float32 VTQC_BrkRegenTgtTqWhl_Nm = 0.0F;/* '<S1261>/Switch2' */
MONPRM volatile float32 VTQC_CstRegenLmtTq_Nm = 0.0F;/* '<S1259>/CstRegenLmtTq' */
MONPRM volatile float32 VTQC_DrvTqReqWhlABS_Nm = 0.0F;/* '<S1259>/MinMax1' */
MONPRM volatile float32 VTQC_DrvTqReqWhlRBS_Nm = 0.0F;/* '<S1268>/MinMax5' */
MONPRM volatile float32 VTQC_DrvTqReqWhl_Nm = 0.0F;/* '<S1260>/Switch5' */
MONPRM volatile float32 VTQC_MotorTqReq_Nm = 0.0F;/* '<S1260>/Divide' */
MONPRM volatile boolean VTQC_RBSActv_flg = false;/* '<S1269>/Switch4' */
MONPRM volatile float32 VTQD_AccelPedPstnRescl_pct = 0.0F;/* '<S1280>/Product' */
MONPRM volatile float32 VTQD_AdaptCstDeltaAcceltn_mps2 = 0.0F;/* '<S1296>/Add5' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqFF_Nm = 0.0F;/* '<S1296>/Add2' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqI_N = 0.0F;/* '<S1296>/Saturation2' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqPID_Nm = 0.0F;/* '<S1296>/Product6' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqP_N = 0.0F;/* '<S1296>/Product3' */
MONPRM volatile float32 VTQD_AdaptCstMaxTqWhl_Nm = 0.0F;/* '<S1292>/MinMax4' */
MONPRM volatile float32 VTQD_AdaptCstMinTqWhl_Nm = 0.0F;/* '<S1292>/MinMax5' */
MONPRM volatile boolean VTQD_AdaptCstRegenEnbl_flg = false;/* '<S1292>/Logical Operator9' */
MONPRM volatile float32 VTQD_AdaptCstTgtAcceltn_mps2 = 0.0F;/* '<S1298>/Switch' */
MONPRM volatile float32 VTQD_AdaptCstTqReqWhl_Nm = 0.0F;/* '<S1296>/MinMax6' */
MONPRM volatile boolean VTQD_BkwdDrv_flg = false;/* '<S1319>/Switch4' */
MONPRM volatile boolean VTQD_BrkRegenEnbl_flg = false;/* '<S1291>/Logical Operator1' */
MONPRM volatile float32 VTQD_CrpTqReqWhl_Nm = 0.0F;/* '<S1282>/Switch2' */
MONPRM volatile boolean VTQD_CstRegenEnbl_flg = false;/* '<S1291>/Logical Operator13' */
MONPRM volatile float32 VTQD_CstRegenEndPstn_pct = 0.0F;/* '<S1291>/Switch2' */
MONPRM volatile float32 VTQD_CstRegenTqReqWhl_Nm = 0.0F;/* '<S1293>/Switch4' */
MONPRM volatile float32 VTQD_DrvTqDrtFac_c = 0.0F;/* '<S1320>/Saturation' */
MONPRM volatile float32 VTQD_DrvTqReqWhlMrg_Nm = 0.0F;/* '<S1321>/Switch4' */
MONPRM volatile float32 VTQD_DrvTqReqWhlRaw_Nm = 0.0F;/* '<S1280>/Merge' */
MONPRM volatile float32 VTQD_DrvTqReqWhl_Nm = 0.0F;/* '<S1278>/Switch3' */
MONPRM volatile boolean VTQD_DsblCrp_flg = false;/* '<S1282>/Logical Operator12' */
MONPRM volatile float32 VTQD_FullPedDrvTqWhl_Nm = 0.0F;/* '<S1280>/Signal Conversion1' */
MONPRM volatile float32 VTQD_FwdPedMap_pct = 0.0F;/* '<S1283>/Switch9' */
MONPRM volatile float32 VTQD_PedalTqReqWhlRaw_Nm = 0.0F;/* '<S1277>/Add' */
MONPRM volatile uint16 VTQD_TaskRunCounter_cnt = ((uint16)0U);/* '<S1114>/Max1' */

/* test signal, to be deleted */
MONPRM volatile boolean VTQD_TqZeroFast_flg = false;/* '<S1312>/Logical Operator4' */
MONPRM volatile boolean VTQD_TqZeroSlow_flg = false;/* '<S1312>/Logical Operator2' */
MONPRM volatile boolean VTQD_TqZero_flg = false;/* '<S1312>/Logical Operator1' */
MONPRM volatile float32 VTQF_DrvTqReqWhl_Nm = 0.0F;/* '<S1337>/Switch2' */
MONPRM volatile float32 VTQF_TipOutTqDecRateCoeff_rat = 0.0F;/* '<S1339>/1-D Lookup Table1' */
MONPRM volatile boolean VTQF_TqInc_flg = false;/* '<S1349>/Switch4' */
MONPRM volatile float32 VTQF_TqOutChgRate_Nmps = 0.0F;/* '<S1359>/Switch' */
MONPRM volatile float32 VTQF_TqRateDecTgtMax_Nmps = 0.0F;/* '<S1339>/Switch3' */
MONPRM volatile float32 VTQF_TqRateDecTgtMin_Nmps = 0.0F;/* '<S1339>/MinMax4' */
MONPRM volatile float32 VTQF_TqRateIncTgtMax_Nmps = 0.0F;/* '<S1340>/Switch5' */
MONPRM volatile float32 VTQF_TqRateIncTgtMin_Nmps = 0.0F;/* '<S1340>/MinMax4' */
MONPRM volatile float32 VTQF_TqRateLimDec_Nmps = 0.0F;/* '<S1339>/MinMax3' */
MONPRM volatile boolean VTQF_TqRateLimEndg_flg = false;/* '<S1338>/Logical Operator9' */
MONPRM volatile float32 VTQF_TqRateLimInc_Nmps = 0.0F;/* '<S1340>/MinMax2' */
MONPRM volatile float32 VTQF_TqRawChgRate_Nmps = 0.0F;/* '<S1358>/Switch' */
MONPRM volatile float32 VTQF_WhlDrgMaxTqZX_Nm = 0.0F;/* '<S1357>/Switch1' */
MONPRM volatile float32 VTQF_WhlDrvMaxTqZX_Nm = 0.0F;/* '<S1357>/Switch7' */
MONPRM volatile boolean VTQR_ASDEnbl_flg = false;/* '<S1362>/Logical Operator14' */
MONPRM volatile float32 VTQR_ASDSpdFltHi_rpm = 0.0F;/* '<S1370>/Switch' */
MONPRM volatile float32 VTQR_ASDSpdOscRaw_rpm = 0.0F;/* '<S1366>/Add1' */
MONPRM volatile float32 VTQR_ASDSpdOsc_rpm = 0.0F;/* '<S1368>/Multiport Switch' */
MONPRM volatile float32 VTQR_ASDTqReqRaw_Nm = 0.0F;/* '<S1374>/MinMax5' */
MONPRM volatile float32 VTQR_ASDTqReq_Nm = 0.0F;/* '<S1367>/Switch3' */
MONPRM volatile boolean VTQR_MotDampngEnbl_flg = false;/* '<S1362>/Logical Operator1' */
MONPRM volatile float32 VTQR_MotDampngLmt_Nm = 0.0F;/* '<S1382>/MinMax5' */
MONPRM volatile EnumMotorDirReq VTQR_MotorDirReq_enum = EnumMotorDirReq_Stdby;/* '<S1363>/Switch4' */
MONPRM volatile EnumMotorModeReq VTQR_MotorModeReq_enum = EnumMotorModeReq_Stdby;/* '<S1360>/Signal Conversion15' */
MONPRM volatile float32 VTQR_MotorSpdReq_rpm = 0.0F;/* '<S1360>/Signal Conversion1' */
MONPRM volatile boolean VTQR_MotorStdby_flg = false;/* '<S1364>/Logical Operator1' */
MONPRM volatile float32 VTQR_MotorTqReq_Nm = 0.0F;/* '<S1360>/Signal Conversion2' */
MONPRM volatile float32 VTZX_AZDecRate_Nmps = 0.0F;/* '<S1398>/1-D Lookup Table4' */
MONPRM volatile float32 VTZX_AZIncRate_Nmps = 0.0F;/* '<S1398>/1-D Lookup Table3' */
MONPRM volatile float32 VTZX_BZDecRate_Nmps = 0.0F;/* '<S1398>/1-D Lookup Table2' */
MONPRM volatile float32 VTZX_BZIncRate_Nmps = 0.0F;/* '<S1398>/1-D Lookup Table1' */
MONPRM volatile boolean VTZX_BypZX_flg = false;/* '<S1402>/Logical Operator1' */
MONPRM volatile boolean VTZX_ClkActv_flg = false;/* '<S1401>/Switch4' */
MONPRM volatile float32 VTZX_ClkZXTm_s = 0.0F;/* '<S1394>/Switch1' */
MONPRM volatile float32 VTZX_MotorTqReqPrdt_Nm = 0.0F;/* '<S1414>/MinMax5' */
MONPRM volatile float32 VTZX_MotorTqReqZX_Nm = 0.0F;/* '<S1399>/TqZXSt' */
MONPRM volatile float32 VTZX_MotorTqReq_Nm = 0.0F;/* '<S1394>/Switch6' */
MONPRM volatile boolean VTZX_TqInc_flg = false;/* '<S1408>/Switch4' */
MONPRM volatile boolean VTZX_TqRateLimRamp_flg = false;/* '<S1415>/Switch4' */
MONPRM volatile EnumTZXStat VTZX_TqZXSt_enum = EnumTZXStat_NTRL;/* '<S1399>/Data Type Conversion1' */
MONPRM volatile float32 VTZX_ZeroTqHldDec_Nm = 0.0F;/* '<S1399>/TqZXSt' */
MONPRM volatile float32 VTZX_ZeroTqHldInc_Nm = 0.0F;/* '<S1399>/TqZXSt' */
MONPRM volatile float32 VTZX_ZeroTqOfstDec_Nm = 0.0F;/* '<S1398>/Switch3' */
MONPRM volatile float32 VTZX_ZeroTqOfstInc_Nm = 0.0F;/* '<S1398>/Switch2' */
MONPRM volatile float32 VTZX_ZeroTqOfst_Nm = 0.0F;/* '<S1398>/Switch4' */
MONPRM volatile float32 VTZX_ZeroXTm_s = 0.0F;/* '<S1398>/Switch8' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr1_mpkm = 0.0F;/* '<S1082>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr2_mpkm = 0.0F;/* '<S1082>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr3_mpkm = 0.0F;/* '<S1082>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr4_mpkm = 0.0F;/* '<S1082>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr5_mpkm = 0.0F;/* '<S1082>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr_mpkm = 0.0F;/* '<S1082>/Add3' */
MONPRM volatile float32 VVSO_DrvDist_m = 0.0F;/* '<S1095>/Switch1' */
MONPRM volatile float32 VVSO_RoadSlopEst_pct = 0.0F;/* '<S1076>/Product19' */
MONPRM volatile float32 VVSO_RoadSlopTqEst_Nm = 0.0F;/* '<S1080>/MinMax5' */
MONPRM volatile float32 VVSO_SlopEst_rat = 0.0F;/* '<S1104>/Switch' */
MONPRM volatile float32 VVSO_VehDrvResistTq_Nm = 0.0F;/* '<S1076>/Switch4' */
MONPRM volatile float32 VVSO_VehMassEst_kg = 0.0F;/* '<S1103>/Switch' */
MONPRM volatile float32 VVSO_VehSpd_kph = 0.0F;/* '<S1086>/Gain1' */
MONPRM volatile boolean VVSO_WhlDistErrHld_flg = false;/* '<S1086>/OR' */
MONPRM volatile EnumXWhlDistErrRefSt VVSO_XWhlDistErrRefStat_enum =
  EnumXWhlDistErrRefSt_Init;           /* '<S1082>/Signal Conversion2' */
MONPRM volatile float32 VVSO_XWhlDistErrRef_mpkm = 0.0F;/* '<S1082>/Signal Conversion1' */
MONPRM volatile float32 VVSO_XWhlDistErr_m = 0.0F;/* '<S1095>/Switch4' */
MONPRM volatile boolean VVSO_iTPMSAvail_flg = false;/* '<S1086>/Logical Operator' */
MONPRM volatile EnumiTPMSSt VVSO_iTPMSState_enum = EnumiTPMSSt_Init;/* '<S1082>/Signal Conversion' */
MONPRM volatile boolean VVSO_iTPMSWrng_flg = false;/* '<S1082>/Signal Conversion3' */
MONPRM volatile boolean VVTM_BrkPedReld_flg = false;/* '<S1440>/Logical Operator3' */
MONPRM volatile uint8 VVTM_DrvMotorSta_enum = ((uint8)0U);/* '<S1447>/DriveMotorState' */
MONPRM volatile boolean VVTM_ESPIntvActv_flg = false;/* '<S1440>/Logical Operator4' */
MONPRM volatile float32 VVTM_MotorActPwr_kW = 0.0F;/* '<S1454>/Switch2' */
MONPRM volatile float32 VVTM_MotorSpd_rpm = 0.0F;/* '<S1442>/Switch' */
MONPRM volatile boolean VVTM_PCUFailSta_flg = false;/* '<S1447>/Logical Operator2' */
MONPRM volatile boolean VVTM_RegenReqBrkLampOn_flg = false;/* '<S1452>/Switch1' */
MONPRM volatile float32 VVTM_RsrvPwr_kW = 0.0F;/* '<S1449>/MinMax4' */
MONPRM volatile float32 VVTM_RsrvRecupPwr_kW = 0.0F;/* '<S1449>/MinMax1' */
MONPRM volatile float32 VVTM_VehAcceltn_mps2 = 0.0F;/* '<S1445>/Switch' */
MONPRM volatile uint8 VVTM_VehActGrPstn_enum = ((uint8)0U);/* '<S1440>/Switch1' */
MONPRM volatile float32 VVTM_VehSpd_kph = 0.0F;/* '<S1441>/Switch' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
