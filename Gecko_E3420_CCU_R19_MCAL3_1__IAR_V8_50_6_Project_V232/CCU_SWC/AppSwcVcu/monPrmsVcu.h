/*
 * File: monPrmsVcu.h
 *
 * Code generated for Simulink model 'AppSwcVcu'.
 *
 * Model version                  : 9.466
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Aug 16 15:36:12 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_monPrmsVcu_h_
#define RTW_HEADER_monPrmsVcu_h_
#include "rtwtypes.h"
#include "AppSwcVcu_types.h"

/* Exported data declaration */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Declaration for custom storage class: Volatile */
extern MONPRM volatile boolean BSW_RTCWakeup_flg;/* '<S915>/Compare' */

/* RTC唤醒标志位_versteckt */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Day;/* '<S97>/Data Type Conversion45' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Hour;/* '<S97>/Data Type Conversion1' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Min;/* '<S97>/Data Type Conversion2' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Month;/* '<S97>/Data Type Conversion34' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Sec;/* '<S97>/Switch2' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Year;/* '<S97>/Data Type Conversion33' */
extern MONPRM volatile uint8 VBSW_WakeupReasn_enum;/* '<S1387>/EcuWakeupReasn' */

/* _versteckt */
extern MONPRM volatile float32 VCPT_MotorDrgMaxTq_Nm;/* '<S971>/MinMax6' */
extern MONPRM volatile float32 VCPT_MotorDrvMaxTq_Nm;/* '<S971>/MinMax7' */
extern MONPRM volatile float32 VCPT_MotorGenMaxTq_Nm;/* '<S983>/Switch1' */
extern MONPRM volatile float32 VCPT_MotorMotMaxTq_Nm;/* '<S982>/Switch1' */
extern MONPRM volatile boolean VCPT_MotorSpdRvrs_flg;/* '<S971>/Switch3' */
extern MONPRM volatile float32 VCPT_MotorSpd_rpm;/* '<S977>/Switch' */
extern MONPRM volatile float32 VCPT_WhlDrgMaxTq_Nm;/* '<S971>/MinMax1' */
extern MONPRM volatile float32 VCPT_WhlDrvMaxTq_Nm;/* '<S971>/MinMax8' */
extern MONPRM volatile boolean VDAC_ACCAvail_flg;/* '<S992>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_ACCDeltaAcceltn_mps2;/* '<S998>/Add5' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqFF_Nm;/* '<S998>/Add3' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqI_N;/* '<S998>/Saturation1' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqPID_Nm;/* '<S998>/Product6' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqP_N;/* '<S998>/Product3' */
extern MONPRM volatile boolean VDAC_ACCEnbl_flg;/* '<S992>/Logical Operator3' */
extern MONPRM volatile boolean VDAC_ACCOvrd_flg;/* '<S993>/Logical Operator22' */
extern MONPRM volatile float32 VDAC_ACCTqReqWhl_Nm;/* '<S994>/Merge3' */
extern MONPRM volatile uint8 VDAC_AutoBrkReq_enum;/* '<S1099>/Switch' */
extern MONPRM volatile boolean VDAC_CCActv2Stby_flg;/* '<S1033>/Logical Operator15' */
extern MONPRM volatile boolean VDAC_CCActvBascCond_flg;/* '<S1033>/Logical Operator1' */
extern MONPRM volatile float32 VDAC_CCDeltaAcceltn_mps2;/* '<S1020>/Add3' */
extern MONPRM volatile float32 VDAC_CCDsrdAcceltnRaw_mps2;/* '<S1013>/Saturation1' */
extern MONPRM volatile float32 VDAC_CCDsrdAcceltn_mps2;/* '<S1011>/Merge1' */
extern MONPRM volatile float32 VDAC_CCDsrdTqFF_N;/* '<S1019>/Add3' */
extern MONPRM volatile float32 VDAC_CCDsrdTqI_N;/* '<S1020>/Saturation1' */
extern MONPRM volatile float32 VDAC_CCDsrdTqPID_N;/* '<S1020>/Add2' */
extern MONPRM volatile float32 VDAC_CCDsrdTqP_N;/* '<S1020>/Product2' */
extern MONPRM volatile boolean VDAC_CCEnbl_flg;/* '<S1034>/Logical Operator2' */
extern MONPRM volatile uint16 VDAC_CCNoActvCond_enum;/* '<S1036>/Add' */
extern MONPRM volatile boolean VDAC_CCOvrd_flg;/* '<S1007>/Logical Operator22' */
extern MONPRM volatile uint16 VDAC_CCQuitCond_enum;/* '<S1037>/Add' */
extern MONPRM volatile float32 VDAC_CCSpdUnstabTm_s;/* '<S1049>/Saturation' */
extern MONPRM volatile boolean VDAC_CCSpdUnstab_flg;/* '<S1049>/Relational Operator8' */
extern MONPRM volatile EnumCCState VDAC_CCSt_enum;/* '<S1008>/CC_State_Chart' */
extern MONPRM volatile boolean VDAC_CCStby2Actv_flg;/* '<S1033>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_CCTgtSpdCtrl_kph;/* '<S1058>/Switch1' */
extern MONPRM volatile uint8 VDAC_CCTgtSpdHU_kph;/* '<S1009>/TgtSpdCalc' */
extern MONPRM volatile EnumCCTgtSpdSt VDAC_CCTgtSpdSt_enum;/* '<S1009>/TgtSpdCalc' */
extern MONPRM volatile float32 VDAC_CCTgtSpd_kph;/* '<S1009>/MinMax7' */
extern MONPRM volatile float32 VDAC_CCTqReqWhl_Nm;/* '<S1012>/Merge2' */
extern MONPRM volatile float32 VDAC_CCVehSpdNonDrvn_kph;/* '<S1015>/Switch' */
extern MONPRM volatile boolean VDAC_CruzCncl_flg;/* '<S1074>/Chart' */
extern MONPRM volatile EnumCruiseStatus VDAC_CruzCtrlStat_enum;/* '<S1007>/Switch2' */
extern MONPRM volatile boolean VDAC_CruzCtrlSwVld_flg;/* '<S1010>/Signal Conversion1' */
extern MONPRM volatile boolean VDAC_CruzOn_flg;/* '<S1010>/Signal Conversion2' */
extern MONPRM volatile boolean VDAC_CruzRsmActv_flg;/* '<S1071>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSetActv_flg;/* '<S1069>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSpdDecActv_flg;/* '<S1070>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSpdIncActv_flg;/* '<S1072>/Switch4' */
extern MONPRM volatile float32 VDAC_DrvAsstTqSplitEHB_Nm;/* '<S988>/MinMax2' */
extern MONPRM volatile float32 VDAC_DrvAsstTqSplitINV_Nm;/* '<S988>/Add1' */
extern MONPRM volatile uint8 VDAC_DrvAsstTqSts_enum;/* '<S988>/Switch1' */
extern MONPRM volatile float32 VDAC_DrvAsstTqTgt_Nm;/* '<S988>/Switch2' */
extern MONPRM volatile boolean VDAC_EnblEHBBrkRun_flg;/* '<S1181>/Switch4' */
extern MONPRM volatile boolean VDAC_HDCActv2Idle_flg;/* '<S1081>/Logical Operator11' */
extern MONPRM volatile boolean VDAC_HDCActv2Stdby_flg;/* '<S1081>/Logical Operator8' */
extern MONPRM volatile float32 VDAC_HDCDeltaAcceltn_mps2;/* '<S1086>/Add5' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqFF_Nm;/* '<S1086>/Add3' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqI_N;/* '<S1086>/Saturation1' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqPID_Nm;/* '<S1086>/Product6' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqP_N;/* '<S1086>/Product3' */
extern MONPRM volatile boolean VDAC_HDCIdle2Stdby_flg;/* '<S1081>/Logical Operator2' */
extern MONPRM volatile EnumHDCState VDAC_HDCSt_enum;/* '<S986>/HDC_State_Chart' */
extern MONPRM volatile boolean VDAC_HDCStdby2Actv_flg;/* '<S1081>/Logical Operator13' */
extern MONPRM volatile boolean VDAC_HDCStdby2Idle_flg;/* '<S1081>/Logical Operator3' */
extern MONPRM volatile float32 VDAC_HDCTgtAcceltn_mps2;/* '<S1078>/Merge1' */
extern MONPRM volatile float32 VDAC_HDCTgtSpd_kph;/* '<S986>/HDC_State_Chart' */
extern MONPRM volatile float32 VDAC_HDCTqReqWhl_Nm;/* '<S1078>/Merge2' */
extern MONPRM volatile uint8 VDAC_HDCVehSpdHU_kph;/* '<S1079>/Switch1' */
extern MONPRM volatile boolean VDAC_MstrCylPresDec_flg;/* '<S1107>/Relational Operator' */
extern MONPRM volatile float32 VDAC_MstrCylPresrReq_bar;/* '<S988>/Switch13' */
extern MONPRM volatile boolean VDAC_OPDActv_flg;/* '<S1122>/Switch4' */
extern MONPRM volatile boolean VDAC_OPDAvail_flg;/* '<S1100>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_OPDDeltaAcceltn_mps2;/* '<S1139>/Add3' */
extern MONPRM volatile float32 VDAC_OPDDeltaSpd_kph;/* '<S1139>/Add4' */
extern MONPRM volatile float32 VDAC_OPDDsrdTqD_N;/* '<S1153>/Switch' */
extern MONPRM volatile float32 VDAC_OPDDsrdTqFF_Nm;/* '<S1138>/Add3' */
extern MONPRM volatile boolean VDAC_OPDDsrdTqFstI_flg;/* '<S1150>/Logical Operator9' */
extern MONPRM volatile boolean VDAC_OPDDsrdTqHldI_flg;/* '<S1150>/Logical Operator3' */
extern MONPRM volatile float32 VDAC_OPDDsrdTqI_N;/* '<S1139>/Saturation1' */
extern MONPRM volatile float32 VDAC_OPDDsrdTqPID_Nm;/* '<S1139>/Product4' */
extern MONPRM volatile float32 VDAC_OPDDsrdTqP_N;/* '<S1145>/Switch2' */
extern MONPRM volatile float32 VDAC_OPDMaxDrgTqWhl_Nm;/* '<S1150>/MinMax1' */
extern MONPRM volatile float32 VDAC_OPDMaxDrvTqWhl_Nm;/* '<S1150>/MinMax3' */
extern MONPRM volatile boolean VDAC_OPDOvrd_flg;/* '<S1099>/Logical Operator22' */
extern MONPRM volatile float32 VDAC_OPDRtdTq_Nm;/* '<S1138>/Add1' */
extern MONPRM volatile boolean VDAC_OPDSpdClsLoop_flg;/* '<S1139>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_OPDTgtAcceltn_mps2;/* '<S1101>/Merge3' */
extern MONPRM volatile float32 VDAC_OPDTgtSpd_kph;/* '<S1101>/Merge1' */
extern MONPRM volatile boolean VDAC_OPDTqReqUnload_flg;/* '<S1099>/Logical Operator1' */
extern MONPRM volatile float32 VDAC_OPDTqReqWhlFilt_Nm;/* '<S1173>/Switch3' */
extern MONPRM volatile float32 VDAC_OPDTqReqWhlLmt_Nm;/* '<S1102>/Merge3' */
extern MONPRM volatile float32 VDAC_OPDTqReqWhl_Nm;/* '<S1110>/Switch3' */
extern MONPRM volatile float32 VDAC_OPDVehAcceltn2_mps2;/* '<S1129>/Switch' */
extern MONPRM volatile float32 VDAC_OPDVehAcceltn_mps2;/* '<S1101>/Switch2' */
extern MONPRM volatile float32 VDAC_OPDVehSpdMotorFac_rat;/* '<S1128>/Switch' */
extern MONPRM volatile float32 VDAC_OPDVehSpdMotor_kph;/* '<S1101>/Product1' */
extern MONPRM volatile float32 VDAC_OPDVehSpd_kph;/* '<S1101>/Switch1' */
extern MONPRM volatile uint8 VDAC_VehSpdHU_kph;/* '<S1060>/Switch1' */
extern MONPRM volatile uint8 VDAC_VirtAccPedPstnSta_enum;/* '<S988>/Switch11' */
extern MONPRM volatile float32 VDAC_VirtAccPedPstn_pct;/* '<S988>/Switch8' */
extern MONPRM volatile float32 VDAC_VirtAccelPedPstnRaw_pct;/* '<S988>/Switch9' */
extern MONPRM volatile float32 VDAC_VirtPedPstn_pct;/* '<S988>/Switch4' */
extern MONPRM volatile uint8 VDAG_ACChrgStFailFltSt_enum;/* '<S326>/FltStDeb' */

/* ACChargeStateFail故障状态 */
extern MONPRM volatile uint8 VDAG_ACDchaBMSPwrLoFltSt_enum;/* '<S332>/FltStDeb' */

/* AC放电BMS功率低故障状态 */
extern MONPRM volatile uint8 VDAG_ACDchaBMSSOCLoFltSt_enum;/* '<S331>/FltStDeb' */

/* AC放电BMSSOC低故障状态 */
extern MONPRM volatile uint8 VDAG_ACDchaOverPwrFltSt_enum;/* '<S325>/FltStDeb' */

/* AC放电功率超限故障 */
extern MONPRM volatile uint8 VDAG_ACSCmdTmOutFltSt_enum;/* '<S130>/FltStDeb' */

/* ACSCmd超时故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed1ShtBattFltSt_enum;/* '<S441>/FltStDeb' */

/* 加速踏板1路短电源故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed1ShtGndFltSt_enum;/* '<S438>/FltStDeb' */

/* 加速踏板1路短地故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed1SuplyShtCircFltSt_enum;/* '<S439>/FltStDeb' */

/* 加速踏板1路供电短路故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed2ShtBattFltSt_enum;/* '<S434>/FltStDeb' */

/* 加速踏板2路短电源故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed2ShtGndFltSt_enum;/* '<S442>/FltStDeb' */

/* 加速踏板2路短地故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed2SuplyShtCircFltSt_enum;/* '<S440>/FltStDeb' */

/* 加速踏板2路供电短路故障状态 */
extern MONPRM volatile uint8 VDAG_AccPedBothFailFltSt_enum;/* '<S436>/FltStDeb' */

/* 加速踏板双路失效故障状态 */
extern MONPRM volatile uint8 VDAG_AccPedCrsChkFltSt_enum;/* '<S435>/FltStDeb' */

/* 加速踏板相互校验故障状态 */
extern MONPRM volatile uint8 VDAG_BMSCmdTmOutFltSt_enum;/* '<S124>/FltStDeb' */

/* BMS继电器指令响应超时故障状态 */
extern MONPRM volatile uint8 VDAG_BMSEmgcySdnFltSt_enum;/* '<S135>/FltStDeb' */

/* BMS紧急下电故障状态 */
extern MONPRM volatile uint8 VDAG_BMSSOCLoFltSt_enum;/* '<S134>/FltStDeb' */

/* BMSSOC低故障状态 */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl1FltSt_enum;/* '<S131>/FltStDeb' */

/* BMSFailLevel1故障状态 */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl2FltSt_enum;/* '<S132>/FltStDeb' */

/* BMSFailLevel2故障状态 */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl3FltSt_enum;/* '<S133>/FltStDeb' */

/* BMSFailLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_BMSUndrVoltFltSt_enum;/* '<S136>/FltStDeb' */

/* BMSPack欠压故障状态 */
extern MONPRM volatile uint8 VDAG_BrkPedShtBattFltSt_enum;/* '<S461>/FltStDeb' */

/* 制动踏板短电源故障状态 */
extern MONPRM volatile uint8 VDAG_BrkPedShtGndFltSt_enum;/* '<S459>/FltStDeb' */

/* 制动踏板短地故障状态 */
extern MONPRM volatile uint8 VDAG_BrkSwCrsChkCnt_cnt;/* '<S454>/Data Type Conversion' */

/* 制动开关相互校验错误计数 */
extern MONPRM volatile uint8 VDAG_BrkSwCrsChkFltSt_enum;/* '<S460>/FltStDeb' */

/* 制动开关相互校验故障状态 */
extern MONPRM volatile uint8 VDAG_CellUndrVoltFltSt_enum;/* '<S137>/FltStDeb' */

/* BMSCell欠压故障状态 */
extern MONPRM volatile uint8 VDAG_DCCCmdTmOutFltSt_enum;/* '<S228>/FltStDeb' */

/* DCDC模式指令响应超时故障状态 */
extern MONPRM volatile uint8 VDAG_DCCInVoltLoFltSt_enum;/* '<S229>/FltStDeb' */

/* DCDC输入电压低故障状态 */
extern MONPRM volatile uint8 VDAG_DCCModeFltFltSt_enum;/* '<S227>/FltStDeb' */

/* DCDCModeFault故障状态 */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl1FltSt_enum;/* '<S223>/FltStDeb' */

/* DCDCFailLevel1故障状态 */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl2FltSt_enum;/* '<S224>/FltStDeb' */

/* DCDCFailLevel2故障状态 */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl3FltSt_enum;/* '<S225>/FltStDeb' */

/* DCDCFailLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl4FltSt_enum;/* '<S226>/FltStDeb' */

/* DCDCFailLevel4故障状态 */
extern MONPRM volatile uint8 VDAG_DCSChrgReqFltSt_enum;/* '<S128>/FltStDeb' */

/* DCSChargeRequest故障状态 */
extern MONPRM volatile uint8 VDAG_DCSCmdTmOutFltSt_enum;/* '<S138>/FltStDeb' */

/* DCSCmd超时故障状态 */
extern MONPRM volatile uint8 VDAG_DCSFailStaFltSt_enum;/* '<S126>/FltStDeb' */

/* DCSFailState故障状态 */
extern MONPRM volatile uint8 VDAG_DCSInletConnectFltSt_enum;/* '<S127>/FltStDeb' */

/* DCS插枪故障状态 */
extern MONPRM volatile uint8 VDAG_DCSModeFailFltSt_enum;/* '<S129>/FltStDeb' */

/* DCSModeFail故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl1FltSt_enum;/* '<S386>/FltStDeb' */

/* EHB1级故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl2FltSt_enum;/* '<S387>/FltStDeb' */

/* EHB2级故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl3FltSt_enum;/* '<S388>/FltStDeb' */

/* EHB3级故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl4FltSt_enum;/* '<S380>/FltStDeb' */

/* EHB4级故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl5FltSt_enum;/* '<S389>/FltStDeb' */

/* EHB5级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl1FltSt_enum;/* '<S391>/FltStDeb' */

/* ESC1级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl2FltSt_enum;/* '<S381>/FltStDeb' */

/* ESC2级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl3FltSt_enum;/* '<S382>/FltStDeb' */

/* ESC3级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl4FltSt_enum;/* '<S390>/FltStDeb' */

/* ESC4级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl5FltSt_enum;/* '<S383>/FltStDeb' */

/* ESC5级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCVehSpdInvldFltSt_enum;/* '<S385>/FltStDeb' */

/* 车速失效故障状态 */
extern MONPRM volatile boolean VDAG_EmgcyShtdwn_flg;/* '<S88>/Switch30' */
extern MONPRM volatile uint16 VDAG_ErrCode_enum;/* '<S86>/Err_State' */
extern MONPRM volatile boolean VDAG_FanFullSpdOn_flg;/* '<S88>/Switch3' */
extern MONPRM volatile boolean VDAG_FbdACC_flg;/* '<S88>/Switch28' */
extern MONPRM volatile boolean VDAG_FbdACChrg_flg;/* '<S88>/Switch32' */
extern MONPRM volatile boolean VDAG_FbdACDcha_flg;/* '<S88>/Switch34' */
extern MONPRM volatile boolean VDAG_FbdAC_flg;/* '<S88>/Switch35' */
extern MONPRM volatile boolean VDAG_FbdCC_flg;/* '<S88>/Switch26' */
extern MONPRM volatile boolean VDAG_FbdDCChrg_flg;/* '<S88>/Switch33' */
extern MONPRM volatile boolean VDAG_FbdDCDC_flg;/* '<S88>/Switch31' */
extern MONPRM volatile boolean VDAG_FbdDRGr_flg;/* '<S88>/Switch25' */
extern MONPRM volatile boolean VDAG_FbdDrvTq_flg;/* '<S88>/Switch23' */
extern MONPRM volatile boolean VDAG_FbdHV_flg;/* '<S88>/Switch29' */
extern MONPRM volatile boolean VDAG_FbdLSP_flg;/* '<S88>/Switch27' */
extern MONPRM volatile boolean VDAG_FltLampOn_flg;/* '<S88>/Switch36' */
extern MONPRM volatile uint8 VDAG_FltLvl_enum;/* '<S88>/MinMax' */
extern MONPRM volatile uint8 VDAG_GearShftInvldFltSt_enum;/* '<S384>/FltStDeb' */

/* 换挡输入失效故障状态 */
extern MONPRM volatile uint8 VDAG_HVILVoltHiFltSt_enum;/* '<S463>/FltStDeb' */

/* 高压互锁电压高故障状态 */
extern MONPRM volatile uint8 VDAG_HVILVoltLoFltSt_enum;/* '<S462>/FltStDeb' */

/* 高压互锁电压低故障状态 */
extern MONPRM volatile uint8 VDAG_HVIsoResistLoFltSt_enum;/* '<S125>/FltStDeb' */

/* 高压电池绝缘故障状态 */
extern MONPRM volatile uint8 VDAG_INVFltLvl1FltSt_enum;/* '<S292>/FltStDeb' */

/* INVFaultLevel1故障状态 */
extern MONPRM volatile uint8 VDAG_INVFltLvl2FltSt_enum;/* '<S293>/FltStDeb' */

/* INVFaultLevel2故障状态 */
extern MONPRM volatile uint8 VDAG_INVFltLvl3FltSt_enum;/* '<S294>/FltStDeb' */

/* INVFaultLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_INVFltLvl4FltSt_enum;/* '<S295>/FltStDeb' */

/* INVFaultLevel4故障状态 */
extern MONPRM volatile uint8 VDAG_INVInVoltLoFltSt_enum;/* '<S230>/FltStDeb' */

/* INV输入电压低故障状态 */
extern MONPRM volatile uint8 VDAG_INVRunCmdRespFltSt_enum;/* '<S296>/FltStDeb' */

/* INVRun指令响应超时故障状态 */
extern MONPRM volatile boolean VDAG_LVBatLampOn_flg;/* '<S88>/Switch1' */
extern MONPRM volatile uint8 VDAG_LVBattSOCLoFltSt_enum;/* '<S414>/FltStDeb' */

/* 蓄电池SOC低的故障状态 */
extern MONPRM volatile uint8 VDAG_LVBattSOHLoFltSt_enum;/* '<S410>/FltStDeb' */

/* 蓄电池SOH低的故障状态 */
extern MONPRM volatile uint8 VDAG_LVBattTempHiFltSt_enum;/* '<S411>/FltStDeb' */

/* 蓄电池过温故障状态 */
extern MONPRM volatile uint8 VDAG_LVBattVoltHiFltSt_enum;/* '<S413>/FltStDeb' */

/* 蓄电池电压高故障状态 */
extern MONPRM volatile uint8 VDAG_LVBattVoltLoFltSt_enum;/* '<S412>/FltStDeb' */

/* 蓄电池电压低故障状态 */
extern MONPRM volatile boolean VDAG_LimpHome_flg;/* '<S88>/Switch2' */
extern MONPRM volatile boolean VDAG_LmtDrvTq_flg;/* '<S88>/Switch24' */
extern MONPRM volatile uint8 VDAG_OBCChrgReqFltSt_enum;/* '<S330>/FltStDeb' */

/* OBCChargeRequest故障状态 */
extern MONPRM volatile uint8 VDAG_OBCConnectTmOutFltSt_enum;/* '<S328>/FltStDeb' */

/* OBC连接超时故障状态 */
extern MONPRM volatile uint8 VDAG_OBCInletConnectFltSt_enum;/* '<S333>/FltStDeb' */

/* OBC插枪故障状态 */
extern MONPRM volatile uint8 VDAG_OBCModeMsmtchFltSt_enum;/* '<S327>/FltStDeb' */

/* OBC模式不匹配故障状态 */
extern MONPRM volatile uint8 VDAG_OBCS2StatFltSt_enum;/* '<S329>/FltStDeb' */

/* OBCS2连接超时故障状态 */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl1FltSt_enum;/* '<S334>/FltStDeb' */

/* OBCFailLevel1故障状态 */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl2FltSt_enum;/* '<S335>/FltStDeb' */

/* OBCFailLevel2故障状态 */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl3FltSt_enum;/* '<S336>/FltStDeb' */

/* OBCFailLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl4FltSt_enum;/* '<S324>/FltStDeb' */

/* OBCFailLevel4故障状态 */
extern MONPRM volatile uint8 VDAG_SysPwrModeInvldFltSt_enum;/* '<S378>/FltStDeb' */

/* PowerMode失效故障状态 */
extern MONPRM volatile uint8 VDAG_TMSFailLvl3FltSt_enum;/* '<S379>/FltStDeb' */

/* TMSRFailLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_VehCrashFltSt_enum;/* '<S433>/FltStDeb' */

/* 碰撞故障状态 */
extern MONPRM volatile boolean VDAG_WakeUp_flg;/* '<S254>/Chart' */

/* 硬线唤醒或者IBSLIN唤醒标志 */
extern MONPRM volatile uint8 VDAG_WaterTempAbvThrFltSt_enum;/* '<S478>/FltStDeb' */

/* 冷却水温过高故障状态 */
extern MONPRM volatile uint8 VDAG_WaterTempBlwThrFltSt_enum;/* '<S477>/FltStDeb' */

/* 冷却水温过低故障状态 */
extern MONPRM volatile float32 VDSA_AcceltnIdxAvg_pct;/* '<S16>/AvgAcceltnIdx' */
extern MONPRM volatile float32 VDSA_AcceltnIdxRaw_pct;/* '<S16>/Saturation1' */
extern MONPRM volatile float32 VDSA_BrkPedPstnAvg_pct;/* '<S16>/AvgBrkPedPstn' */
extern MONPRM volatile float32 VDSA_DrvSprtIdx_pct;/* '<S16>/Saturation2' */
extern MONPRM volatile boolean VDSA_SprtIdxHldAcc_flg;/* '<S16>/Logical Operator3' */
extern MONPRM volatile boolean VDSA_SprtIdxHldBrk_flg;/* '<S16>/Logical Operator6' */
extern MONPRM volatile float32 VDSA_TqCalcAcceltn_mps2;/* '<S16>/Divide1' */
extern MONPRM volatile boolean VEMS_ACCMOprtCmd_flg;/* '<S29>/ACCMEnble' */

/* 使能ACCM */
extern MONPRM volatile float32 VEMS_AccPwrRaw_kW;/* '<S30>/MinMax4' */
extern MONPRM volatile float32 VEMS_CellTempSyn_C;/* '<S82>/Switch1' */
extern MONPRM volatile float32 VEMS_CellUndrVoltDrtFac_c;/* '<S27>/Saturation3' */
extern MONPRM volatile float32 VEMS_ChrgCurFbKi_A;/* '<S79>/Saturation' */
extern MONPRM volatile float32 VEMS_ChrgCurFbKp_A;/* '<S79>/Product2' */
extern MONPRM volatile float32 VEMS_ChrgCurFb_A;/* '<S79>/Saturation2' */
extern MONPRM volatile float32 VEMS_ChrgOvrshtPwr_kW;/* '<S26>/Add1' */
extern MONPRM volatile float32 VEMS_ChrgPwrFbKi_kW;/* '<S45>/Saturation' */
extern MONPRM volatile float32 VEMS_ChrgPwrFbKp_kW;/* '<S45>/Product2' */
extern MONPRM volatile float32 VEMS_ChrgPwrFb_kW;/* '<S26>/Merge' */
extern MONPRM volatile float32 VEMS_DchaCurFbKi_A;/* '<S80>/Saturation' */
extern MONPRM volatile float32 VEMS_DchaCurFbKp_A;/* '<S80>/Product2' */
extern MONPRM volatile float32 VEMS_DchaCurFb_A;/* '<S80>/Saturation2' */
extern MONPRM volatile float32 VEMS_DchaOvrshtPwr_kW;/* '<S28>/Add1' */
extern MONPRM volatile float32 VEMS_DchaPwrFbKi_kW;/* '<S63>/Saturation' */
extern MONPRM volatile float32 VEMS_DchaPwrFbKp_kW;/* '<S63>/Product2' */
extern MONPRM volatile float32 VEMS_DchaPwrFb_kW;/* '<S28>/Merge' */
extern MONPRM volatile float32 VEMS_HVBatPwrAct_kW;/* '<S30>/Gain1' */
extern MONPRM volatile float32 VEMS_MaxChrgCur_A;/* '<S25>/Saturation4' */
extern MONPRM volatile float32 VEMS_MaxChrgPwr2MotRaw_kW;/* '<S25>/Add7' */
extern MONPRM volatile float32 VEMS_MaxChrgPwr2Mot_kW;/* '<S26>/MinMax2' */
extern MONPRM volatile float32 VEMS_MaxChrgPwr_kW;/* '<S25>/Product2' */
extern MONPRM volatile float32 VEMS_MaxConChrgCur_A;/* '<S25>/MinMax1' */
extern MONPRM volatile float32 VEMS_MaxConDchaCur_A;/* '<S27>/MinMax1' */
extern MONPRM volatile float32 VEMS_MaxDchaCur_A;/* '<S27>/Saturation4' */
extern MONPRM volatile float32 VEMS_MaxDchaPwr2MotRaw_kW;/* '<S27>/Add7' */
extern MONPRM volatile float32 VEMS_MaxDchaPwr2Mot_kW;/* '<S28>/MinMax2' */
extern MONPRM volatile float32 VEMS_MaxDchaPwr_kW;/* '<S27>/Product2' */
extern MONPRM volatile float32 VEMS_MaxInsChrgCur_A;/* '<S25>/MinMax3' */
extern MONPRM volatile float32 VEMS_MaxInsDchaCur_A;/* '<S27>/MinMax3' */
extern MONPRM volatile boolean VEMS_TMSActSOCEnbl_flg;/* '<S76>/Switch1' */

/* SOC是否限制TMS */
extern MONPRM volatile boolean VEMS_TMSPwrEnbl_flg;/* '<S29>/Switch3' */

/* 功率是否限制TMS */
extern MONPRM volatile float32 VEMS_TMSUsePwr_kW;/* '<S29>/Subtract' */

/* TMS可用功率 */
extern MONPRM volatile boolean VEMS_UseConChrgCur_flg;/* '<S36>/Switch4' */
extern MONPRM volatile boolean VEMS_UseConDchaCur_flg;/* '<S54>/Switch4' */
extern MONPRM volatile boolean VGSM_AsstDrvFbShft_flg;/* '<S1439>/Logical Operator2' */

/* 规范：ACC/CC禁止档位解析 */
extern MONPRM volatile boolean VGSM_DRFlt2N_flg;/* '<S1438>/Switch1' */

/* 规范：退至非驱动档标志位 */
extern MONPRM volatile boolean VGSM_EPBAplyFlt_flg;/* '<S1431>/EPBLogical' */

/* 故障P-EPB拉起故障 */
extern MONPRM volatile boolean VGSM_EPBRelsFlt_flg;/* '<S1431>/EPBLogical' */

/* 故障P-EPB释放故障 */
extern MONPRM volatile boolean VGSM_GrD2PExcdTm_flg;/* '<S1593>/Chart' */

/* D档入P请求超时入N */
extern MONPRM volatile boolean VGSM_GrNReq2P_flg;/* '<S1438>/Switch2' */

/* N档非换挡请求进P档请求 */
extern MONPRM volatile boolean VGSM_GrR2PExcdTm_flg;/* '<S1590>/Chart' */

/* R档入P请求超时入N */
extern MONPRM volatile boolean VGSM_HldGearP_flg;/* '<S1438>/Switch' */

/* 规范：保持P档标志位 */
extern MONPRM volatile boolean VGSM_INVRunEnbl_flg;/* '<S1441>/Chart' */

/* 规范：INV使能控制（允许扭矩控制）-VCU_1_EnaInvRun */
extern MONPRM volatile uint8 VGSM_PGrSwSts_enum;/* '<S1439>/Switch2' */

/* 规范：P按键触发标志位-VCU_PGearSwcst */
extern MONPRM volatile boolean VGSM_ReqEPBAply_flg;/* '<S1440>/Logical Operator6' */

/* 规范：EPB拉起请求标志位 */
extern MONPRM volatile boolean VGSM_ReqEPBRels_flg;/* '<S1440>/Logical Operator4' */

/* 规范：EPB释放请求标志位 */
extern MONPRM volatile EnumEPBReq VGSM_ReqEPB_enum;/* '<S1431>/Switch' */

/* 规范：EPB操作信号-VCUF_ReqEPB */
extern MONPRM volatile EnumTgtGearPstn VGSM_ShftTgtGrReq_enum;/* '<S1439>/Data Type Conversion1' */

/* 换挡杆目标档位 0-NoCmd 1-P 2-N 3-D 4-R  */
extern MONPRM volatile EnumGearPstn VGSM_VehActGearPstn_enum;/* '<S1432>/Switch1' */

/* 规范：实际档位-VCU_VhclActlGearPos */
extern MONPRM volatile boolean VGSM_VehEPBStErr_flg;/* '<S1431>/Logical Operator' */

/* 规范：P档故障PGear error-VCU_VhclPGearError */
extern MONPRM volatile EnumTgtGearPstn VGSM_VehTgtGrReq_enum;/* '<S1440>/Data Type Conversion1' */

/* 规范:目标档位 */
extern MONPRM volatile uint8 VGSM_VehTgtGrTrnsfr_enum;/* '<S1479>/Switch' */

/* 规范：换档请求信号 */
extern MONPRM volatile uint8 VHMI_12VBatLowVolSta_enum;/* '<S522>/Switch' */
extern MONPRM volatile float32 VHMI_GrDSldDist_m;/* '<S536>/Saturation' */

/* D档后溜距离 */
extern MONPRM volatile boolean VHMI_GrDSldSw_flg;/* '<S536>/Logical Operator' */

/* D档溜坡计速/距离标志 */
extern MONPRM volatile float32 VHMI_GrRSldDist_m;/* '<S536>/Saturation1' */

/* R档前溜距离 */
extern MONPRM volatile boolean VHMI_GrRSldSw_flg;/* '<S536>/Logical Operator4' */

/* R档溜坡计速/距离标志 */
extern MONPRM volatile uint8 VHMI_InfoDisp_enum;/* '<S525>/Arbitration' */

/* 仪表弹窗值 */
extern MONPRM volatile boolean VHVM_ACChrgEnbl_flg;/* '<S674>/Logical Operator8' */

/* 交流充电基本条件满足 */
extern MONPRM volatile boolean VHVM_ACChrging2Stop_flg;/* '<S668>/AND' */

/* 交流充电中转移到充电停止标志位 */
extern MONPRM volatile boolean VHVM_ACDchaEnbl_flg;/* '<S674>/Logical Operator10' */

/* 交流放电基本条件满足 */
extern MONPRM volatile boolean VHVM_ACDschrging2Stop_flg;/* '<S668>/AND7' */

/* 交流放电中转移到放电停止标志位 */
extern MONPRM volatile EnumBMSSdnCmd VHVM_BMSShutdown_enum;/* '<S647>/Data Type Conversion10' */

/* VCU关闭BMS指令对应CAN信号：VCU_BMS_Shutdown */
extern MONPRM volatile EnumBMSWakeUpMd VHVM_BMSWakeUpMode_enum;/* '<S647>/Data Type Conversion8' */

/* VCU唤醒BMS的方式对应CAN信号：VCU_BMS_WakeupMode */
extern MONPRM volatile boolean VHVM_Bat2DrvTrainEnbl_flg;/* '<S647>/MainState' */

/* VCU控制主继电器指令对应CAN信号：VCU_Bat2DrvTrainEnb */
extern MONPRM volatile EnumChrgAllwCmd VHVM_ChrgAllowCmd_enum;/* '<S647>/Data Type Conversion12' */

/* VCU发送允许充电指令对应CAN信号：VCU_ChrgAllowCmd */
extern MONPRM volatile uint8 VHVM_ChrgEnaAC_enum;/* '<S647>/MainState' */

/* VCU控制OBC交流充电使能指令对应CAN信号：VCU_ChrgEna_AC */
extern MONPRM volatile boolean VHVM_ChrgEnaDC_flg;/* '<S647>/MainState' */

/* VCU控制BMS直流充电使能指令对应CAN信号：VCU_ChrgEna_DC */
extern MONPRM volatile float32 VHVM_DCCBuckLVVolt_V;/* '<S647>/MainState' */

/* VCU控制DCDC BUCK电压值对应CAN信号：VCU_DCCBuckLV_Vol */
extern MONPRM volatile EnumDCCOprtCmd VHVM_DCCOprtCmd_enum;/* '<S647>/Data Type Conversion6' */

/* VCU控制DCDC工作模式指令对应CAN信号：VCU_DCCOprtCmd */
extern MONPRM volatile boolean VHVM_DCChrgEnbl_flg;/* '<S674>/Logical Operator2' */

/* 直流充电基本条件满足 */
extern MONPRM volatile boolean VHVM_DCChrging2Over_flg;/* '<S668>/AND1' */

/* 直流充电中转移到充电结束标志位 */
extern MONPRM volatile boolean VHVM_ECUSleepAllwd_flg;/* '<S647>/MainState' */

/* 允许底层休眠标志位 */
extern MONPRM volatile boolean VHVM_EmgcySdn_flg;/* '<S647>/MainState' */

/* VCU给INV发送紧急下电指令(INV强制停机)对应CAN信号：VCU_1_EmShutDown */
extern MONPRM volatile boolean VHVM_EnaDisChg_flg;/* '<S647>/MainState' */

/* VCU控制INV泄放指令对应CAN信号：VCU_1_EnaDisChg */
extern MONPRM volatile boolean VHVM_EngyExtrmLo_flg;/* '<S650>/Logical Operator17' */

/* 电池能量极低标志位 */
extern MONPRM volatile boolean VHVM_INVEnbl_flg;/* '<S647>/MainState' */

/* VCU硬线唤醒INV */
extern MONPRM volatile boolean VHVM_INVPreprogmFlg_flg;/* '<S669>/Switch1' */

/* INV预编程条件满足 */
extern MONPRM volatile float32 VHVM_MaxChrgCurntDC_A;/* '<S647>/MainState' */

/* VCU允许BMS直流充电最大电流对应CAN信号：VCU_MaxChrgCrnt_DC */
extern MONPRM volatile float32 VHVM_MaxChrgVoltDC_V;/* '<S647>/MainState' */

/* VCU允许BMS直流充电最大电压对应CAN信号：VCU_MaxChrgVol_DC */
extern MONPRM volatile float32 VHVM_MaxHVDCCurntAC_A;/* '<S647>/MainState' */

/* VCU允许OBC交流充电最大电流对应CAN信号：VCU_MaxHVDC_Cur_AC */
extern MONPRM volatile float32 VHVM_MaxHVDCVoltAC_V;/* '<S647>/MainState' */

/* VCU允许OBC交流充电最大电压对应CAN信号：VCU_MaxHVDC_Vol_AC */
extern MONPRM volatile EnumOBCOprtCmd VHVM_OBCOprtCmd_enum;/* '<S648>/Data Type Conversion4' */

/* VCU控制OBC工作模式指令对应CAN信号：VCU_OBCOprtCmd */
extern MONPRM volatile EnumPTActMd VHVM_PTActOprtMode_enum;/* '<S647>/Data Type Conversion4' */

/* 高压PT状态 */
extern MONPRM volatile boolean VHVM_PTRdy2PTStdby_flg;/* '<S671>/Switch1' */

/* PTRdy到PTStdby标志位 */
extern MONPRM volatile boolean VHVM_PTStdby2PTRdy_flg;/* '<S671>/Switch' */

/* PTStdby到PTRdy标志位 */
extern MONPRM volatile boolean VHVM_PowUpSelfChek_flg;/* '<S672>/Switch' */

/* 高压自检标志位 */
extern MONPRM volatile boolean VHVM_PwrOn2PwrDwn_flg;/* '<S673>/Switch' */

/* 高压下电条件满足标志位（正常/故障/紧急） */
extern MONPRM volatile boolean VHVM_SOPExtrmLo_flg;/* '<S650>/Relational Operator4' */

/* 电池SOP极低，用于关闭DCDC */
extern MONPRM volatile EnumSysSta VHVM_SysSta_enum;/* '<S647>/Data Type Conversion2' */

/* 高压子状态 */
extern MONPRM volatile uint8 VHVM_TBOX2OBC_emun;/* '<S648>/Switch1' */

/* TBOX远程充放电指令 */
extern MONPRM volatile EnumVCUMode VHVM_VCUMode_enum;/* '<S647>/Data Type Conversion' */

/* 高压主转态 */
extern MONPRM volatile boolean VHVM_VehHalt_flg;/* '<S663>/Switch4' */

/* 车辆停止标志位（车速极其） */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpACChrg_flg;/* '<S674>/Logical Operator16' */

/* 交流充电唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpACDcha_flg;/* '<S674>/Logical Operator26' */

/* 交流放电唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpDCChrg_flg;/* '<S674>/Logical Operator4' */

/* 直流充电唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpIBS_flg;/* '<S674>/Logical Operator6' */

/* IBS唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpKL15_flg;/* '<S674>/Logical Operator' */

/* K15唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUp_flg;/* '<S674>/Switch' */

/* 唤醒到上高压条件满足（唤醒源上升沿+高压自检通过） */
extern MONPRM volatile boolean VHVM_WakeUpBMS_flg;/* '<S647>/MainState' */

/* VCU硬线唤醒BMS */
extern MONPRM volatile boolean VHVM_WakeUpVCU_flg;/* '<S675>/Switch' */

/* 休眠到唤醒条件满足 */
extern MONPRM volatile boolean VIBS_BMSBatSOCAllow_flg;/* '<S900>/Switch3' */

/* 动力电池SOC允许补电标志位_versteckt */
extern MONPRM volatile boolean VIBS_ChgNumAllow_flg;/* '<S900>/AND' */

/* 补电次数允许标志位_versteckt */
extern MONPRM volatile uint8 VIBS_ChgNum_cnt;/* '<S900>/Switch2' */

/* IBS补电次数_versteckt */
extern MONPRM volatile boolean VIBS_ChrgBascCond_flg;/* '<S900>/Logical Operator2' */

/* 补电基本条件满足（补电次数及电压）_versteckt */
extern MONPRM volatile boolean VIBS_ChrgEnbl_flg;/* '<S900>/Logical Operator7' */

/* IBS充电使能标志位_versteckt */
extern MONPRM volatile boolean VIBS_ChrgOver_flg;/* '<S898>/ChrgSt' */

/* IBS补电结束标志位_versteckt */
extern MONPRM volatile float32 VIBS_ChrgVoltThr_V;/* '<S901>/VoltState' */

/* 补电电压阈值_versteckt */
extern MONPRM volatile float32 VIBS_EnvirTemp_C;/* '<S918>/Switch' */

/* IBS环境温度_versteckt */
extern MONPRM volatile uint8 VIBS_FailChgNum_cnt;/* '<S900>/Switch5' */

/* IBS补电失败次数_versteckt */
extern MONPRM volatile boolean VIBS_FbRctWup_flg;/* '<S900>/Logical Operator6' */

/* IBS禁止RTC唤醒标志位_versteckt */
extern MONPRM volatile boolean VIBS_HVReq_flg;/* '<S900>/Switch' */

/* IBS请求上高压标志位_versteckt */
extern MONPRM volatile float32 VIBS_HwKL30_V;/* '<S917>/Switch' */

/* 滤波后的KL30电压_versteckt */
extern MONPRM volatile boolean VIBS_NMReq_flg;/* '<S907>/Switch4' */

/* IBS请求网络标志位_versteckt */
extern MONPRM volatile uint16 VIBS_NextRtcWupThr_min;/* '<S901>/Switch1' */

/* 下次补电唤醒RTC的时间_versteckt */
extern MONPRM volatile EnumIBSChrgSt VIBS_RTCChrgSt_enum;/* '<S898>/Data Type Conversion' */

/* IBS补电状态_versteckt */
extern MONPRM volatile boolean VIBS_RTCWakeup_flg;/* '<S921>/Chart' */

/* RTC唤醒标志位（含延迟时间）_versteckt */
extern MONPRM volatile boolean VIBS_SleepAllwd_flg;/* '<S900>/SleepAllwd' */

/* IBS允许底层休眠标志位_versteckt */
extern MONPRM volatile uint16 VIBS_WupChgTmThr_min;/* '<S901>/Switch2' */

/* IBS补电时间阈值_versteckt */
extern MONPRM volatile boolean VIBS_WupVoltAllow_flg;/* '<S919>/Switch4' */

/* KL30电压允许标志位_versteckt */
extern MONPRM volatile boolean VIPC_ACCCfgd_flg;/* '<S774>/Switch8' */
extern MONPRM volatile boolean VIPC_AccPed1Flt_flg;/* '<S778>/Logical Operator1' */
extern MONPRM volatile boolean VIPC_AccPed1LrnDwnActv_flg;/* '<S788>/Relational Operator' */
extern MONPRM volatile boolean VIPC_AccPed1LrnUpActv_flg;/* '<S781>/Logical Operator5' */
extern MONPRM volatile float32 VIPC_AccPed1MinPstnLrnd_pct;/* '<S781>/Switch2' */
extern MONPRM volatile float32 VIPC_AccPed1NormzAvg_pct;/* '<S787>/Switch' */
extern MONPRM volatile float32 VIPC_AccPed1NormzPstn_pct;/* '<S778>/Switch5' */
extern MONPRM volatile float32 VIPC_AccPed1SclPstn_pct;/* '<S782>/Divide1' */
extern MONPRM volatile boolean VIPC_AccPed2Flt_flg;/* '<S778>/Logical Operator2' */
extern MONPRM volatile boolean VIPC_AccPed2LrnDwnActv_flg;/* '<S792>/Relational Operator' */
extern MONPRM volatile boolean VIPC_AccPed2LrnUpActv_flg;/* '<S783>/Logical Operator5' */
extern MONPRM volatile float32 VIPC_AccPed2MinPstnLrnd_pct;/* '<S783>/Switch2' */
extern MONPRM volatile float32 VIPC_AccPed2NormzAvg_pct;/* '<S791>/Switch' */
extern MONPRM volatile float32 VIPC_AccPed2NormzPstn_pct;/* '<S778>/Switch7' */
extern MONPRM volatile float32 VIPC_AccPed2SclPstn_pct;/* '<S784>/Divide5' */
extern MONPRM volatile boolean VIPC_AccPedPstnVld_flg;/* '<S780>/Switch3' */
extern MONPRM volatile float32 VIPC_AccPedPstn_pct;/* '<S776>/MinMax3' */
extern MONPRM volatile uint8 VIPC_AccPedSnsrSta_enum;/* '<S780>/Switch3' */
extern MONPRM volatile boolean VIPC_AccPedStkActv_flg;/* '<S779>/Logical Operator6' */
extern MONPRM volatile boolean VIPC_AccPedStkBrkPrsd_flg;/* '<S806>/Switch4' */
extern MONPRM volatile float32 VIPC_AccPedStkPstn_pct;/* '<S779>/MinMax' */
extern MONPRM volatile boolean VIPC_AccPedStkStab_flg;/* '<S808>/Relational Operator' */
extern MONPRM volatile float32 VIPC_AccPedWghtAvg_pct;/* '<S805>/Switch' */
extern MONPRM volatile float32 VIPC_AccPedWghtPstn_pct;/* '<S780>/Switch3' */
extern MONPRM volatile float32 VIPC_AccPedZeroPstn_pct;/* '<S779>/Switch' */
extern MONPRM volatile boolean VIPC_BrkPedPstnVld_flg;/* '<S771>/Logical Operator8' */
extern MONPRM volatile float32 VIPC_BrkPedPstn_pct;/* '<S771>/Saturation1' */
extern MONPRM volatile boolean VIPC_BrkSwActv_flg;/* '<S771>/Logical Operator' */
extern MONPRM volatile boolean VIPC_CCSCfgd_flg;/* '<S774>/Switch1' */
extern MONPRM volatile boolean VIPC_CrpCtrlCfgd_flg;/* '<S774>/Switch2' */
extern MONPRM volatile EnumCrpModeAct VIPC_CrpModeAct_enum;/* '<S773>/Switch12' */
extern MONPRM volatile EnumDrvModeAct VIPC_DrvModeAct_enum;/* '<S773>/Switch13' */
extern MONPRM volatile uint8 VIPC_DrvPwrIntnsty_pct;/* '<S773>/Switch25' */
extern MONPRM volatile boolean VIPC_DrvSw_flg;/* '<S776>/Relational Operator3' */
extern MONPRM volatile boolean VIPC_EPBAppld_flg;/* '<S772>/Logical Operator4' */
extern MONPRM volatile boolean VIPC_EPBReld_flg;/* '<S772>/Logical Operator5' */
extern MONPRM volatile boolean VIPC_HDCCfgd_flg;/* '<S774>/Switch3' */
extern MONPRM volatile EnumRegenModeAct VIPC_RegenModeAct_enum;/* '<S773>/Switch15' */
extern MONPRM volatile uint8 VIPC_RegenPwrIntnsty_pct;/* '<S773>/Switch28' */
extern MONPRM volatile boolean VIPC_SnowMode_flg;/* '<S773>/Switch14' */
extern MONPRM volatile float32 VIPC_TireRadius_m;/* '<S774>/TireSizeTable' */
extern MONPRM volatile uint8 VIPC_VehHiddenMode_enum;/* '<S773>/VehHiddenMode' */
extern MONPRM volatile float32 VIPC_VehSpdDrvnMotor_kph;/* '<S775>/Product1' */
extern MONPRM volatile boolean VIPC_VehSpdDrvnVld_flg;/* '<S844>/Logical Operator2' */
extern MONPRM volatile float32 VIPC_VehSpdDrvn_kph;/* '<S844>/Switch7' */
extern MONPRM volatile boolean VIPC_VehSpdNonDrvnVld_flg;/* '<S845>/Logical Operator2' */
extern MONPRM volatile float32 VIPC_VehSpdNonDrvn_kph;/* '<S845>/Switch7' */
extern MONPRM volatile boolean VIPC_VehSpdVld_flg;/* '<S844>/SignalConversion' */
extern MONPRM volatile float32 VIPC_VehSpd_kph;/* '<S844>/Switch4' */
extern MONPRM volatile boolean VIPC_VpedAutoCrp_flg;/* '<S830>/Switch4' */
extern MONPRM volatile boolean VIPC_ZeroPstnRst_flg;/* '<S779>/Logical Operator3' */
extern MONPRM volatile boolean VIPC_iTPMSCfgd_flg;/* '<S774>/Switch4' */
extern MONPRM volatile float32 VIPM_HwAccPedCh1SuplyVolt_mV;/* '<S1389>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh1Volt_mV;/* '<S1390>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh2SuplyVolt_mV;/* '<S1391>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh2Volt_mV;/* '<S1392>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwBMSWakeup_flg;/* '<S1393>/Switch4' */
extern MONPRM volatile boolean VIPM_HwBrkSwHi_flg;/* '<S1394>/Switch4' */
extern MONPRM volatile boolean VIPM_HwBrkSwLo_flg;/* '<S1395>/Switch4' */
extern MONPRM volatile boolean VIPM_HwCrpModeSw_flg;/* '<S1396>/Switch4' */
extern MONPRM volatile boolean VIPM_HwDrvModeSw_flg;/* '<S1397>/Switch4' */
extern MONPRM volatile boolean VIPM_HwEmgcyShutOff_flg;/* '<S1398>/Switch4' */
extern MONPRM volatile boolean VIPM_HwKL15A_flg;/* '<S1399>/Switch4' */
extern MONPRM volatile boolean VIPM_HwKL15B_flg;/* '<S1400>/Switch4' */
extern MONPRM volatile uint16 VIPM_HwKL30_mV;/* '<S1401>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwOBCWakeup_flg;/* '<S1402>/Switch4' */
extern MONPRM volatile boolean VIPM_HwRearFogLampSwt_flg;/* '<S1403>/Switch4' */
extern MONPRM volatile EnumPGearSwSts VIPM_HwShftPstnSwSts_enum;/* '<S1404>/Switch4' */
extern MONPRM volatile uint16 VIPM_HwShftPstnSw_Ohm;/* '<S1386>/HwShftPstnSw' */
extern MONPRM volatile boolean VIPM_HwVehCrash_flg;/* '<S1405>/Switch4' */
extern MONPRM volatile float32 VNVM_AvgPwrCnsm_kWh100km;/* '<S1387>/Add2' */

/* _versteckt */
extern MONPRM volatile float32 VNVM_AvgSOCCnsmWght_pctp100km;/* '<S1387>/Add6' */

/* _versteckt */
extern MONPRM volatile EnumCrpModeAct VNVM_CrpModeAct_enum;/* '<S1387>/Data Type Conversion1' */

/* _versteckt */
extern MONPRM volatile EnumDrvModeAct VNVM_DrvModeAct_enum;/* '<S1387>/Data Type Conversion23' */

/* _versteckt */
extern MONPRM volatile uint8 VNVM_DrvPwrIntnsty_pct;/* '<S1387>/Selector6' */

/* _versteckt */
extern MONPRM volatile float32 VNVM_DynRmnMilEst_km;/* '<S1387>/Gain2' */

/* _versteckt */
extern MONPRM volatile uint8 VNVM_IBSChrgFailNum_cnt;/* '<S1387>/Selector1' */

/* _versteckt */
extern MONPRM volatile uint8 VNVM_IBSChrgNum_cnt;/* '<S1387>/Selector' */

/* _versteckt */
extern MONPRM volatile EnumRegenModeAct VNVM_RegenModeAct_enum;/* '<S1387>/Data Type Conversion24' */

/* _versteckt */
extern MONPRM volatile uint8 VNVM_RegenPwrIntnsty_pct;/* '<S1387>/Selector7' */

/* _versteckt */
extern MONPRM volatile EnumXWhlDistErrRefSt VNVM_XWhlDistErrRefStat_enum;/* '<S1387>/Data Type Conversion22' */

/* _versteckt */
extern MONPRM volatile float32 VNVM_XWhlDistErrRef_mpkm;/* '<S1387>/Add1' */

/* _versteckt */
extern MONPRM volatile boolean VNVM_iTPMSWrng_flg;/* '<S1387>/Data Type Conversion21' */

/* _versteckt */
extern MONPRM volatile boolean VOPM_HwWakeupBMS_flg;/* '<S1418>/Switch4' */
extern MONPRM volatile float32 VRMEAvgPwrCnsm15km_kWhpkm;/* '<S858>/Signal Copy2' */

/* 15km平均Pwr能耗 */
extern MONPRM volatile float32 VRME_AvgPwrCnsm100km_kWhpkm;/* '<S858>/Signal Copy5' */

/* 100km平均Pwr能耗 */
extern MONPRM volatile float32 VRME_AvgPwrCnsm10km_kWhpkm;/* '<S858>/Signal Copy1' */

/* 10km平均Pwr能耗 */
extern MONPRM volatile float32 VRME_AvgPwrCnsm25km_kWhpkm;/* '<S858>/Signal Copy3' */

/* 25km平均Pwr能耗 */
extern MONPRM volatile float32 VRME_AvgPwrCnsm50km_kWhpkm;/* '<S858>/Signal Copy4' */

/* 50km平均Pwr能耗 */
extern MONPRM volatile float32 VRME_AvgPwrCnsm5km_kWhpkm;/* '<S858>/Signal Copy' */

/* 5km平均Pwr能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm100Num_pctpkm;/* '<S871>/Signal Copy5' */

/* 前100个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm10Num_pctpkm;/* '<S871>/Signal Copy1' */

/* 前10个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm15Num_pctpkm;/* '<S871>/Signal Copy2' */

/* 前15个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm25Num_pctpkm;/* '<S871>/Signal Copy3' */

/* 前25个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm50Num_pctpkm;/* '<S871>/Signal Copy4' */

/* 前50个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm5Num_pctpkm;/* '<S871>/Signal Copy' */

/* 前5个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsmWght_pctpkm;/* '<S871>/Switch1' */

/* 加权平均SOC能耗/km */
extern MONPRM volatile boolean VRME_CHTCRmnMilEstV_flg;/* '<S853>/Logical Operator' */

/* CHTC标准续航里程有效性 */
extern MONPRM volatile float32 VRME_CHTCRmnMilEst_km;/* '<S853>/MRME_CHTCStdRmnMil_km' */

/* CHTC标准续航查表值 */
extern MONPRM volatile float32 VRME_CalPwrCnsmPerTrig_kWhpkm;/* '<S857>/Switch4' */

/* Pwr消耗/单位里程（1km） */
extern MONPRM volatile boolean VRME_CalPwrCnsmTrig_flg;/* '<S857>/Relational Operator1' */

/* 累计里程大于单位里程（默认1km） */
extern MONPRM volatile float32 VRME_CalSOCCnsmPerTrig_pctptrig;/* '<S870>/Switch4' */

/* SOC消耗/目标里程 */
extern MONPRM volatile float32 VRME_CalSOCCnsmPerkm_pctpkm;/* '<S870>/Divide' */

/* 目标里程消耗折算为单位里程 */
extern MONPRM volatile float32 VRME_CalSOCCnsmTgtDist_m;/* '<S870>/Switch1' */

/* 单位目标行驶里程 */
extern MONPRM volatile boolean VRME_CalSOCCnsmTrig_flg;/* '<S870>/Relational Operator1' */

/* 累计里程大于目标里程 */
extern MONPRM volatile float32 VRME_DynRmnMilEstChgFac_c;/* '<S872>/MRME_DynEstRmnChgStp_c' */

/* 动态续航变化系数 */
extern MONPRM volatile float32 VRME_DynRmnMilEstTgt_km;/* '<S893>/Switch2' */

/* 动态续航目标值 */
extern MONPRM volatile boolean VRME_DynRmnMilEstUpdTrig_flg;/* '<S872>/Relational Operator2' */

/* 更新续航值 */
extern MONPRM volatile boolean VRME_DynRmnMilEstV_flg;/* '<S872>/Logical Operator1' */

/* 动态续航有效性 */
extern MONPRM volatile float32 VRME_DynRmnMilEst_km;/* '<S892>/Switch2' */

/* 动态续航限幅值 */
extern MONPRM volatile boolean VRME_VehStacEnbl_flg;/* '<S872>/Logical Operator4' */

/* 车辆静止状态 */
extern MONPRM volatile float32 VRME_VehTotDistCurrCyc_km;/* '<S870>/Gain2' */

/* 当前驾驶循环累计总里程 */
extern MONPRM volatile float32 VRME_VehTotPwrCurrCyc_kWh;/* '<S857>/Plus2' */

/* 当前驾驶循环车辆使用功率 */
extern MONPRM volatile float32 VRME_WLTPRmnMilEstDwLim_km;/* '<S870>/Product3' */

/* 动态续航下限值 */
extern MONPRM volatile float32 VRME_WLTPRmnMilEstUpLim_km;/* '<S870>/Product2' */

/* 动态续航上限值 */
extern MONPRM volatile float32 VRME_WLTPRmnMilEst_km;/* '<S870>/MRME_WLTPStdRmnMil_km' */

/* WLTP标准续航查表值 */
extern MONPRM volatile float32 VRME_WLTPStdPwrCnsm_kWhpkm;/* '<S857>/Gain5' */

/* 标准工况下电耗 */
extern MONPRM volatile float32 VRME_WLTPStdSOCCnsm_pctpkm;/* '<S870>/Gain3' */

/* 标准工况下SOC消耗/km */
extern MONPRM volatile float32 VTQC_ABSorESPActvTm_s;/* '<S1194>/MinMax' */
extern MONPRM volatile float32 VTQC_BrkRegenMaxTqWhl_Nm;/* '<S1189>/Switch17' */
extern MONPRM volatile float32 VTQC_BrkRegenTgtTqWhl_Nm;/* '<S1189>/Switch2' */
extern MONPRM volatile float32 VTQC_CstRegenLmtTq_Nm;/* '<S1187>/CstRegenLmtTq' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhlABS_Nm;/* '<S1187>/MinMax1' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhlRBS_Nm;/* '<S1196>/MinMax5' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhl_Nm;/* '<S1188>/Switch5' */
extern MONPRM volatile float32 VTQC_MotorTqReq_Nm;/* '<S1188>/Divide' */
extern MONPRM volatile boolean VTQC_RBSActv_flg;/* '<S1197>/Switch4' */
extern MONPRM volatile float32 VTQD_AccelPedPstnRescl_pct;/* '<S1208>/Product' */
extern MONPRM volatile float32 VTQD_AdaptCstDeltaAcceltn_mps2;/* '<S1224>/Add5' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqFF_Nm;/* '<S1224>/Add2' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqI_N;/* '<S1224>/Saturation2' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqPID_Nm;/* '<S1224>/Product6' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqP_N;/* '<S1224>/Product3' */
extern MONPRM volatile float32 VTQD_AdaptCstMaxTqWhl_Nm;/* '<S1220>/MinMax4' */
extern MONPRM volatile float32 VTQD_AdaptCstMinTqWhl_Nm;/* '<S1220>/MinMax5' */
extern MONPRM volatile boolean VTQD_AdaptCstRegenEnbl_flg;/* '<S1220>/Logical Operator9' */
extern MONPRM volatile float32 VTQD_AdaptCstTgtAcceltn_mps2;/* '<S1226>/Switch' */
extern MONPRM volatile float32 VTQD_AdaptCstTqReqWhl_Nm;/* '<S1224>/MinMax6' */
extern MONPRM volatile boolean VTQD_BkwdDrv_flg;/* '<S1247>/Switch4' */
extern MONPRM volatile boolean VTQD_BrkRegenEnbl_flg;/* '<S1219>/Logical Operator1' */
extern MONPRM volatile float32 VTQD_CrpTqReqWhl_Nm;/* '<S1210>/Switch2' */
extern MONPRM volatile boolean VTQD_CstRegenEnbl_flg;/* '<S1219>/Logical Operator13' */
extern MONPRM volatile float32 VTQD_CstRegenEndPstn_pct;/* '<S1219>/Switch2' */
extern MONPRM volatile float32 VTQD_CstRegenTqReqWhl_Nm;/* '<S1221>/Switch4' */
extern MONPRM volatile float32 VTQD_DrvTqDrtFac_c;/* '<S1248>/Saturation' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhlMrg_Nm;/* '<S1249>/Switch4' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhlRaw_Nm;/* '<S1208>/Merge' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhl_Nm;/* '<S1206>/Switch3' */
extern MONPRM volatile boolean VTQD_DsblCrp_flg;/* '<S1210>/Logical Operator12' */
extern MONPRM volatile float32 VTQD_FullPedDrvTqWhl_Nm;/* '<S1208>/Signal Conversion1' */
extern MONPRM volatile float32 VTQD_FwdPedMap_pct;/* '<S1211>/Switch9' */
extern MONPRM volatile float32 VTQD_PedalTqReqWhlRaw_Nm;/* '<S1205>/Add' */
extern MONPRM volatile uint16 VTQD_TaskRunCounter_cnt;/* '<S968>/Max1' */

/* test signal, to be deleted */
extern MONPRM volatile boolean VTQD_TqZeroFast_flg;/* '<S1240>/Logical Operator4' */
extern MONPRM volatile boolean VTQD_TqZeroSlow_flg;/* '<S1240>/Logical Operator2' */
extern MONPRM volatile boolean VTQD_TqZero_flg;/* '<S1240>/Logical Operator1' */
extern MONPRM volatile float32 VTQF_DrvTqReqWhl_Nm;/* '<S1264>/Switch2' */
extern MONPRM volatile float32 VTQF_TipOutTqDecRateCoeff_rat;/* '<S1266>/1-D Lookup Table1' */
extern MONPRM volatile boolean VTQF_TqInc_flg;/* '<S1276>/Switch4' */
extern MONPRM volatile float32 VTQF_TqOutChgRate_Nmps;/* '<S1286>/Switch' */
extern MONPRM volatile float32 VTQF_TqRateDecTgtMax_Nmps;/* '<S1266>/Switch3' */
extern MONPRM volatile float32 VTQF_TqRateDecTgtMin_Nmps;/* '<S1266>/MinMax4' */
extern MONPRM volatile float32 VTQF_TqRateIncTgtMax_Nmps;/* '<S1267>/Switch5' */
extern MONPRM volatile float32 VTQF_TqRateIncTgtMin_Nmps;/* '<S1267>/MinMax4' */
extern MONPRM volatile float32 VTQF_TqRateLimDec_Nmps;/* '<S1266>/MinMax3' */
extern MONPRM volatile boolean VTQF_TqRateLimEndg_flg;/* '<S1265>/Logical Operator9' */
extern MONPRM volatile float32 VTQF_TqRateLimInc_Nmps;/* '<S1267>/MinMax2' */
extern MONPRM volatile float32 VTQF_TqRawChgRate_Nmps;/* '<S1285>/Switch' */
extern MONPRM volatile float32 VTQF_WhlDrgMaxTqZX_Nm;/* '<S1284>/Switch1' */
extern MONPRM volatile float32 VTQF_WhlDrvMaxTqZX_Nm;/* '<S1284>/Switch7' */
extern MONPRM volatile boolean VTQR_ASDEnbl_flg;/* '<S1289>/Logical Operator14' */
extern MONPRM volatile float32 VTQR_ASDSpdFltHi_rpm;/* '<S1297>/Switch' */
extern MONPRM volatile float32 VTQR_ASDSpdOscRaw_rpm;/* '<S1293>/Add1' */
extern MONPRM volatile float32 VTQR_ASDSpdOsc_rpm;/* '<S1295>/Multiport Switch' */
extern MONPRM volatile float32 VTQR_ASDTqReqRaw_Nm;/* '<S1301>/MinMax5' */
extern MONPRM volatile float32 VTQR_ASDTqReq_Nm;/* '<S1294>/Switch3' */
extern MONPRM volatile boolean VTQR_MotDampngEnbl_flg;/* '<S1289>/Logical Operator1' */
extern MONPRM volatile float32 VTQR_MotDampngLmt_Nm;/* '<S1309>/MinMax5' */
extern MONPRM volatile EnumMotorDirReq VTQR_MotorDirReq_enum;/* '<S1290>/Switch4' */
extern MONPRM volatile EnumMotorModeReq VTQR_MotorModeReq_enum;/* '<S1287>/Signal Conversion15' */
extern MONPRM volatile float32 VTQR_MotorSpdReq_rpm;/* '<S1287>/Signal Conversion1' */
extern MONPRM volatile boolean VTQR_MotorStdby_flg;/* '<S1291>/Logical Operator1' */
extern MONPRM volatile float32 VTQR_MotorTqReq_Nm;/* '<S1287>/Signal Conversion2' */
extern MONPRM volatile float32 VTZX_AZDecRate_Nmps;/* '<S1325>/1-D Lookup Table4' */
extern MONPRM volatile float32 VTZX_AZIncRate_Nmps;/* '<S1325>/1-D Lookup Table3' */
extern MONPRM volatile float32 VTZX_BZDecRate_Nmps;/* '<S1325>/1-D Lookup Table2' */
extern MONPRM volatile float32 VTZX_BZIncRate_Nmps;/* '<S1325>/1-D Lookup Table1' */
extern MONPRM volatile boolean VTZX_BypZX_flg;/* '<S1329>/Logical Operator1' */
extern MONPRM volatile boolean VTZX_ClkActv_flg;/* '<S1328>/Switch4' */
extern MONPRM volatile float32 VTZX_ClkZXTm_s;/* '<S1321>/Switch1' */
extern MONPRM volatile float32 VTZX_MotorTqReqPrdt_Nm;/* '<S1341>/MinMax5' */
extern MONPRM volatile float32 VTZX_MotorTqReqZX_Nm;/* '<S1326>/TqZXSt' */
extern MONPRM volatile float32 VTZX_MotorTqReq_Nm;/* '<S1321>/Switch6' */
extern MONPRM volatile boolean VTZX_TqInc_flg;/* '<S1335>/Switch4' */
extern MONPRM volatile boolean VTZX_TqRateLimRamp_flg;/* '<S1342>/Switch4' */
extern MONPRM volatile EnumTZXStat VTZX_TqZXSt_enum;/* '<S1326>/Data Type Conversion1' */
extern MONPRM volatile float32 VTZX_ZeroTqHldDec_Nm;/* '<S1326>/TqZXSt' */
extern MONPRM volatile float32 VTZX_ZeroTqHldInc_Nm;/* '<S1326>/TqZXSt' */
extern MONPRM volatile float32 VTZX_ZeroTqOfstDec_Nm;/* '<S1325>/Switch3' */
extern MONPRM volatile float32 VTZX_ZeroTqOfstInc_Nm;/* '<S1325>/Switch2' */
extern MONPRM volatile float32 VTZX_ZeroTqOfst_Nm;/* '<S1325>/Switch4' */
extern MONPRM volatile float32 VTZX_ZeroXTm_s;/* '<S1325>/Switch8' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr1_mpkm;/* '<S936>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr2_mpkm;/* '<S936>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr3_mpkm;/* '<S936>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr4_mpkm;/* '<S936>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr5_mpkm;/* '<S936>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr_mpkm;/* '<S936>/Add3' */
extern MONPRM volatile float32 VVSO_DrvDist_m;/* '<S949>/Switch1' */
extern MONPRM volatile float32 VVSO_RoadSlopEst_pct;/* '<S930>/Product19' */
extern MONPRM volatile float32 VVSO_RoadSlopTqEst_Nm;/* '<S934>/MinMax5' */
extern MONPRM volatile float32 VVSO_SlopEst_rat;/* '<S958>/Switch' */
extern MONPRM volatile float32 VVSO_VehDrvResistTq_Nm;/* '<S930>/Switch4' */
extern MONPRM volatile float32 VVSO_VehMassEst_kg;/* '<S957>/Switch' */
extern MONPRM volatile float32 VVSO_VehSpd_kph;/* '<S940>/Gain1' */
extern MONPRM volatile boolean VVSO_WhlDistErrHld_flg;/* '<S940>/OR' */
extern MONPRM volatile EnumXWhlDistErrRefSt VVSO_XWhlDistErrRefStat_enum;/* '<S936>/Signal Conversion2' */
extern MONPRM volatile float32 VVSO_XWhlDistErrRef_mpkm;/* '<S936>/Signal Conversion1' */
extern MONPRM volatile float32 VVSO_XWhlDistErr_m;/* '<S949>/Switch4' */
extern MONPRM volatile boolean VVSO_iTPMSAvail_flg;/* '<S940>/Logical Operator' */
extern MONPRM volatile EnumiTPMSSt VVSO_iTPMSState_enum;/* '<S936>/Signal Conversion' */
extern MONPRM volatile boolean VVSO_iTPMSWrng_flg;/* '<S936>/Signal Conversion3' */
extern MONPRM volatile boolean VVTM_BrkPedReld_flg;/* '<S1367>/Logical Operator3' */
extern MONPRM volatile uint8 VVTM_DrvMotorSta_enum;/* '<S1374>/DriveMotorState' */
extern MONPRM volatile boolean VVTM_ESPIntvActv_flg;/* '<S1367>/Logical Operator4' */
extern MONPRM volatile float32 VVTM_MotorActPwr_kW;/* '<S1381>/Switch2' */
extern MONPRM volatile float32 VVTM_MotorSpd_rpm;/* '<S1369>/Switch' */
extern MONPRM volatile boolean VVTM_PCUFailSta_flg;/* '<S1374>/Logical Operator2' */
extern MONPRM volatile boolean VVTM_RegenReqBrkLampOn_flg;/* '<S1379>/Switch1' */
extern MONPRM volatile float32 VVTM_RsrvPwr_kW;/* '<S1376>/MinMax4' */
extern MONPRM volatile float32 VVTM_RsrvRecupPwr_kW;/* '<S1376>/MinMax1' */
extern MONPRM volatile float32 VVTM_VehAcceltn_mps2;/* '<S1372>/Switch' */
extern MONPRM volatile uint8 VVTM_VehActGrPstn_enum;/* '<S1367>/Switch1' */
extern MONPRM volatile float32 VVTM_VehSpd_kph;/* '<S1368>/Switch' */

#endif                                 /* RTW_HEADER_monPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
