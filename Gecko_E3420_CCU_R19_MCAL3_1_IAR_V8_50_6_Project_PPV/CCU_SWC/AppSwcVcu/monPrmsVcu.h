/*
 * File: monPrmsVcu.h
 *
 * Code generated for Simulink model 'AppSwcVcu'.
 *
 * Model version                  : 9.619
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Nov 14 16:25:54 2024
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
extern MONPRM volatile boolean BSW_RTCWakeup_flg;/* '<S1053>/Switch4' */

/* RTC唤醒标志位_versteckt */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Day;/* '<S100>/Data Type Conversion45' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Hour;/* '<S100>/Data Type Conversion1' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Min;/* '<S100>/Data Type Conversion2' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Month;/* '<S100>/Data Type Conversion34' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Sec;/* '<S100>/Switch2' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Year;/* '<S100>/Data Type Conversion33' */
extern MONPRM volatile uint8 VBSW_WakeupReasn_enum;/* '<S1573>/EcuWakeupReasn' */
extern MONPRM volatile float32 VCPT_MotorDrgMaxTq_Nm;/* '<S1230>/MinMax6' */
extern MONPRM volatile float32 VCPT_MotorDrvMaxTq_Nm;/* '<S1230>/MinMax7' */
extern MONPRM volatile float32 VCPT_MotorGenMaxTq_Nm;/* '<S1242>/Switch1' */
extern MONPRM volatile float32 VCPT_MotorMotMaxTq_Nm;/* '<S1241>/Switch1' */
extern MONPRM volatile boolean VCPT_MotorSpdRvrs_flg;/* '<S1230>/Switch3' */
extern MONPRM volatile float32 VCPT_MotorSpd_rpm;/* '<S1236>/Switch' */
extern MONPRM volatile float32 VCPT_WhlDrgMaxTq_Nm;/* '<S1230>/MinMax1' */
extern MONPRM volatile float32 VCPT_WhlDrvMaxTq_Nm;/* '<S1230>/MinMax8' */
extern MONPRM volatile boolean VDAC_ACCAvail_flg;/* '<S1251>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_ACCDeltaAcceltn_mps2;/* '<S1258>/Add5' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqFF_Nm;/* '<S1258>/Add3' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqI_N;/* '<S1258>/Saturation1' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqPID_Nm;/* '<S1258>/Product6' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqP_N;/* '<S1258>/Product3' */
extern MONPRM volatile boolean VDAC_ACCEnbl_flg;/* '<S1251>/Logical Operator3' */
extern MONPRM volatile boolean VDAC_ACCOvrd_flg;/* '<S1252>/Logical Operator22' */
extern MONPRM volatile uint8 VDAC_ACCStat_enum;/* '<S1253>/Switch1' */
extern MONPRM volatile float32 VDAC_ACCTqReqWhl_Nm;/* '<S1254>/Merge3' */
extern MONPRM volatile boolean VDAC_CCActv2Stby_flg;/* '<S1294>/Logical Operator15' */
extern MONPRM volatile boolean VDAC_CCActvBascCond_flg;/* '<S1294>/Logical Operator1' */
extern MONPRM volatile float32 VDAC_CCDeltaAcceltn_mps2;/* '<S1281>/Add3' */
extern MONPRM volatile float32 VDAC_CCDsrdAcceltnRaw_mps2;/* '<S1274>/Saturation1' */
extern MONPRM volatile float32 VDAC_CCDsrdAcceltn_mps2;/* '<S1272>/Merge1' */
extern MONPRM volatile float32 VDAC_CCDsrdTqFF_N;/* '<S1280>/Add3' */
extern MONPRM volatile float32 VDAC_CCDsrdTqI_N;/* '<S1281>/Saturation1' */
extern MONPRM volatile float32 VDAC_CCDsrdTqPID_N;/* '<S1281>/Add2' */
extern MONPRM volatile float32 VDAC_CCDsrdTqP_N;/* '<S1281>/Product2' */
extern MONPRM volatile boolean VDAC_CCEnbl_flg;/* '<S1295>/Logical Operator2' */
extern MONPRM volatile uint16 VDAC_CCNoActvCond_enum;/* '<S1297>/Add' */
extern MONPRM volatile boolean VDAC_CCOvrd_flg;/* '<S1268>/Logical Operator22' */
extern MONPRM volatile uint16 VDAC_CCQuitCond_enum;/* '<S1298>/Add' */
extern MONPRM volatile float32 VDAC_CCSpdUnstabTm_s;/* '<S1310>/Saturation' */
extern MONPRM volatile boolean VDAC_CCSpdUnstab_flg;/* '<S1310>/Relational Operator8' */
extern MONPRM volatile EnumCCState VDAC_CCSt_enum;/* '<S1269>/CC_State_Chart' */
extern MONPRM volatile boolean VDAC_CCStby2Actv_flg;/* '<S1294>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_CCTgtSpdCtrl_kph;/* '<S1319>/Switch1' */
extern MONPRM volatile uint8 VDAC_CCTgtSpdHU_kph;/* '<S1270>/TgtSpdCalc' */
extern MONPRM volatile EnumCCTgtSpdSt VDAC_CCTgtSpdSt_enum;/* '<S1270>/TgtSpdCalc' */
extern MONPRM volatile float32 VDAC_CCTgtSpd_kph;/* '<S1270>/MinMax7' */
extern MONPRM volatile float32 VDAC_CCTqReqWhl_Nm;/* '<S1273>/Merge2' */
extern MONPRM volatile float32 VDAC_CCVehSpdNonDrvn_kph;/* '<S1276>/Switch' */
extern MONPRM volatile boolean VDAC_CruzCncl_flg;/* '<S1335>/Chart' */
extern MONPRM volatile EnumCruiseStatus VDAC_CruzCtrlStat_enum;/* '<S1268>/Switch2' */
extern MONPRM volatile boolean VDAC_CruzCtrlSwVld_flg;/* '<S1271>/Signal Conversion1' */
extern MONPRM volatile boolean VDAC_CruzOn_flg;/* '<S1271>/Signal Conversion2' */
extern MONPRM volatile boolean VDAC_CruzRsmActv_flg;/* '<S1332>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSetActv_flg;/* '<S1330>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSpdDecActv_flg;/* '<S1331>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSpdIncActv_flg;/* '<S1333>/Switch4' */
extern MONPRM volatile float32 VDAC_DrvAsstTqSplitEHB_Nm;/* '<S1247>/MinMax2' */
extern MONPRM volatile float32 VDAC_DrvAsstTqSplitINV_Nm;/* '<S1247>/Add1' */
extern MONPRM volatile uint8 VDAC_DrvAsstTqSts_enum;/* '<S1247>/Switch1' */
extern MONPRM volatile float32 VDAC_DrvAsstTqTgt_Nm;/* '<S1247>/Switch2' */
extern MONPRM volatile boolean VDAC_EnblEHBBrkRun_flg;/* '<S1366>/Switch4' */
extern MONPRM volatile boolean VDAC_HDCActv2Idle_flg;/* '<S1342>/Logical Operator11' */
extern MONPRM volatile boolean VDAC_HDCActv2Stdby_flg;/* '<S1342>/Logical Operator8' */
extern MONPRM volatile float32 VDAC_HDCDeltaAcceltn_mps2;/* '<S1347>/Add5' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqFF_Nm;/* '<S1347>/Add3' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqI_N;/* '<S1347>/Saturation1' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqPID_Nm;/* '<S1347>/Product6' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqP_N;/* '<S1347>/Product3' */
extern MONPRM volatile boolean VDAC_HDCIdle2Stdby_flg;/* '<S1342>/Logical Operator2' */
extern MONPRM volatile EnumHDCState VDAC_HDCSt_enum;/* '<S1245>/HDC_State_Chart' */
extern MONPRM volatile boolean VDAC_HDCStdby2Actv_flg;/* '<S1342>/Logical Operator13' */
extern MONPRM volatile boolean VDAC_HDCStdby2Idle_flg;/* '<S1342>/Logical Operator3' */
extern MONPRM volatile float32 VDAC_HDCTgtAcceltn_mps2;/* '<S1339>/Merge1' */
extern MONPRM volatile float32 VDAC_HDCTgtSpd_kph;/* '<S1245>/HDC_State_Chart' */
extern MONPRM volatile float32 VDAC_HDCTqReqWhl_Nm;/* '<S1339>/Merge2' */
extern MONPRM volatile uint8 VDAC_HDCVehSpdHU_kph;/* '<S1340>/Switch1' */
extern MONPRM volatile float32 VDAC_MstrCylPresrReq_bar;/* '<S1247>/Switch13' */
extern MONPRM volatile uint8 VDAC_VehSpdHU_kph;/* '<S1321>/Switch1' */
extern MONPRM volatile uint8 VDAC_VirtAccPedPstnSta_enum;/* '<S1247>/Switch11' */
extern MONPRM volatile float32 VDAC_VirtAccPedPstn_pct;/* '<S1247>/Switch8' */
extern MONPRM volatile float32 VDAC_VirtAccelPedPstnRaw_pct;/* '<S1247>/Switch9' */
extern MONPRM volatile float32 VDAC_VirtPedPstn_pct;/* '<S1247>/Switch4' */
extern MONPRM volatile uint8 VDAG_ACCMHVILFltSt_enum;/* '<S568>/FltStDeb' */

/* 压缩机高压互锁故障状态 */
extern MONPRM volatile uint8 VDAG_ACChrgStFailFltSt_enum;/* '<S401>/FltStDeb' */

/* ACChargeStateFail故障状态 */
extern MONPRM volatile uint8 VDAG_ACDchaBMSPwrLoFltSt_enum;/* '<S407>/FltStDeb' */

/* AC放电BMS功率低故障状态 */
extern MONPRM volatile uint8 VDAG_ACDchaBMSSOCLoFltSt_enum;/* '<S406>/FltStDeb' */

/* AC放电BMSSOC低故障状态 */
extern MONPRM volatile uint8 VDAG_ACDchaOverPwrFltSt_enum;/* '<S400>/FltStDeb' */

/* AC放电功率超限故障 */
extern MONPRM volatile uint8 VDAG_ACSCmdTmOutFltSt_enum;/* '<S133>/FltStDeb' */

/* ACSCmd超时故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed1ShtBattFltSt_enum;/* '<S542>/FltStDeb' */

/* 加速踏板1路短电源故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed1ShtGndFltSt_enum;/* '<S539>/FltStDeb' */

/* 加速踏板1路短地故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed1SuplyShtCircFltSt_enum;/* '<S540>/FltStDeb' */

/* 加速踏板1路供电短路故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed2ShtBattFltSt_enum;/* '<S535>/FltStDeb' */

/* 加速踏板2路短电源故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed2ShtGndFltSt_enum;/* '<S543>/FltStDeb' */

/* 加速踏板2路短地故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed2SuplyShtCircFltSt_enum;/* '<S541>/FltStDeb' */

/* 加速踏板2路供电短路故障状态 */
extern MONPRM volatile uint8 VDAG_AccPedBothFailFltSt_enum;/* '<S537>/FltStDeb' */

/* 加速踏板双路失效故障状态 */
extern MONPRM volatile uint8 VDAG_AccPedCrsChkFltSt_enum;/* '<S536>/FltStDeb' */

/* 加速踏板相互校验故障状态 */
extern MONPRM volatile uint8 VDAG_BMSCmdTmOutFltSt_enum;/* '<S127>/FltStDeb' */

/* BMS继电器指令响应超时故障状态 */
extern MONPRM volatile uint8 VDAG_BMSEmgcySdnFltSt_enum;/* '<S138>/FltStDeb' */

/* BMS紧急下电故障状态 */
extern MONPRM volatile uint8 VDAG_BMSSOCLoFltSt_enum;/* '<S137>/FltStDeb' */

/* BMSSOC低故障状态 */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl1FltSt_enum;/* '<S134>/FltStDeb' */

/* BMSFailLevel1故障状态 */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl2FltSt_enum;/* '<S135>/FltStDeb' */

/* BMSFailLevel2故障状态 */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl3FltSt_enum;/* '<S136>/FltStDeb' */

/* BMSFailLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_BMSUndrVoltFltSt_enum;/* '<S139>/FltStDeb' */

/* BMSPack欠压故障状态 */
extern MONPRM volatile uint8 VDAG_BrkPedShtBattFltSt_enum;/* '<S565>/FltStDeb' */

/* 制动踏板短电源故障状态 */
extern MONPRM volatile uint8 VDAG_BrkPedShtGndFltSt_enum;/* '<S563>/FltStDeb' */

/* 制动踏板短地故障状态 */
extern MONPRM volatile uint8 VDAG_BrkSwCrsChkCnt_cnt;/* '<S555>/Data Type Conversion' */

/* 制动开关相互校验错误计数 */
extern MONPRM volatile uint8 VDAG_BrkSwCrsChkFltSt_enum;/* '<S564>/FltStDeb' */

/* 制动开关相互校验故障状态 */
extern MONPRM volatile uint8 VDAG_CellUndrVoltFltSt_enum;/* '<S140>/FltStDeb' */

/* BMSCell欠压故障状态 */
extern MONPRM volatile uint8 VDAG_DCCCmdTmOutFltSt_enum;/* '<S301>/FltStDeb' */

/* DCDC模式指令响应超时故障状态 */
extern MONPRM volatile uint8 VDAG_DCCInVoltLoFltSt_enum;/* '<S302>/FltStDeb' */

/* DCDC输入电压低故障状态 */
extern MONPRM volatile uint8 VDAG_DCCModeFltFltSt_enum;/* '<S300>/FltStDeb' */

/* DCDCModeFault故障状态 */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl1FltSt_enum;/* '<S296>/FltStDeb' */

/* DCDCFailLevel1故障状态 */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl2FltSt_enum;/* '<S297>/FltStDeb' */

/* DCDCFailLevel2故障状态 */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl3FltSt_enum;/* '<S298>/FltStDeb' */

/* DCDCFailLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl4FltSt_enum;/* '<S299>/FltStDeb' */

/* DCDCFailLevel4故障状态 */
extern MONPRM volatile uint8 VDAG_DCSChrgReqFltSt_enum;/* '<S131>/FltStDeb' */

/* DCSChargeRequest故障状态 */
extern MONPRM volatile uint8 VDAG_DCSCmdTmOutFltSt_enum;/* '<S141>/FltStDeb' */

/* DCSCmd超时故障状态 */
extern MONPRM volatile uint8 VDAG_DCSFailStaFltSt_enum;/* '<S129>/FltStDeb' */

/* DCSFailState故障状态 */
extern MONPRM volatile uint8 VDAG_DCSInletConnectFltSt_enum;/* '<S130>/FltStDeb' */

/* DCS插枪故障状态 */
extern MONPRM volatile uint8 VDAG_DCSModeFailFltSt_enum;/* '<S132>/FltStDeb' */

/* DCSModeFail故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl1FltSt_enum;/* '<S473>/FltStDeb' */

/* EHB1级故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl2FltSt_enum;/* '<S474>/FltStDeb' */

/* EHB2级故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl3FltSt_enum;/* '<S475>/FltStDeb' */

/* EHB3级故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl4FltSt_enum;/* '<S467>/FltStDeb' */

/* EHB4级故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl5FltSt_enum;/* '<S476>/FltStDeb' */

/* EHB5级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl1FltSt_enum;/* '<S478>/FltStDeb' */

/* ESC1级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl2FltSt_enum;/* '<S468>/FltStDeb' */

/* ESC2级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl3FltSt_enum;/* '<S469>/FltStDeb' */

/* ESC3级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl4FltSt_enum;/* '<S477>/FltStDeb' */

/* ESC4级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl5FltSt_enum;/* '<S470>/FltStDeb' */

/* ESC5级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCVehSpdInvldFltSt_enum;/* '<S472>/FltStDeb' */

/* 车速失效故障状态 */
extern MONPRM volatile boolean VDAG_EmgcyShtdwn_flg;/* '<S91>/Switch30' */
extern MONPRM volatile uint16 VDAG_ErrCode_enum;/* '<S89>/Err_State' */
extern MONPRM volatile boolean VDAG_FanFullSpdOn_flg;/* '<S91>/Switch3' */
extern MONPRM volatile boolean VDAG_FbdACC_flg;/* '<S91>/Switch28' */
extern MONPRM volatile boolean VDAG_FbdACChrg_flg;/* '<S91>/Switch32' */
extern MONPRM volatile boolean VDAG_FbdACDcha_flg;/* '<S91>/Switch34' */
extern MONPRM volatile boolean VDAG_FbdAC_flg;/* '<S91>/Switch35' */
extern MONPRM volatile boolean VDAG_FbdCC_flg;/* '<S91>/Switch26' */
extern MONPRM volatile boolean VDAG_FbdDCChrg_flg;/* '<S91>/Switch33' */
extern MONPRM volatile boolean VDAG_FbdDCDC_flg;/* '<S91>/Switch31' */
extern MONPRM volatile boolean VDAG_FbdDRGr_flg;/* '<S91>/Switch25' */
extern MONPRM volatile boolean VDAG_FbdDrvTq_flg;/* '<S91>/Switch23' */
extern MONPRM volatile boolean VDAG_FbdHV_flg;/* '<S91>/Switch29' */
extern MONPRM volatile boolean VDAG_FbdLSP_flg;/* '<S91>/Switch27' */
extern MONPRM volatile boolean VDAG_FltLampOn_flg;/* '<S91>/Switch36' */
extern MONPRM volatile uint8 VDAG_FltLvl_enum;/* '<S91>/MinMax' */
extern MONPRM volatile uint8 VDAG_FrstHVILVoltHiFltSt_enum;/* '<S567>/FltStDeb' */

/* 主要高压互锁电压高故障状态 */
extern MONPRM volatile uint8 VDAG_FrstHVILVoltLoFltSt_enum;/* '<S566>/FltStDeb' */

/* 主要高压互锁电压低故障状态 */
extern MONPRM volatile uint8 VDAG_GearShftInvldFltSt_enum;/* '<S471>/FltStDeb' */

/* 换挡输入失效故障状态 */
extern MONPRM volatile uint8 VDAG_HVIsoResistLoFltSt_enum;/* '<S128>/FltStDeb' */

/* 高压电池绝缘故障状态 */
extern MONPRM volatile uint8 VDAG_INVFltLvl1FltSt_enum;/* '<S367>/FltStDeb' */

/* INVFaultLevel1故障状态 */
extern MONPRM volatile uint8 VDAG_INVFltLvl2FltSt_enum;/* '<S368>/FltStDeb' */

/* INVFaultLevel2故障状态 */
extern MONPRM volatile uint8 VDAG_INVFltLvl3FltSt_enum;/* '<S369>/FltStDeb' */

/* INVFaultLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_INVFltLvl4FltSt_enum;/* '<S370>/FltStDeb' */

/* INVFaultLevel4故障状态 */
extern MONPRM volatile uint8 VDAG_INVInVoltLoFltSt_enum;/* '<S303>/FltStDeb' */

/* INV输入电压低故障状态 */
extern MONPRM volatile uint8 VDAG_INVRunCmdRespFltSt_enum;/* '<S371>/FltStDeb' */

/* INVRun指令响应超时故障状态 */
extern MONPRM volatile boolean VDAG_LVBatLampOn_flg;/* '<S91>/Switch1' */
extern MONPRM volatile uint8 VDAG_LVBattSOCLoFltSt_enum;/* '<S515>/FltStDeb' */

/* 蓄电池SOC低的故障状态 */
extern MONPRM volatile uint8 VDAG_LVBattSOHLoFltSt_enum;/* '<S511>/FltStDeb' */

/* 蓄电池SOH低的故障状态 */
extern MONPRM volatile uint8 VDAG_LVBattTempHiFltSt_enum;/* '<S512>/FltStDeb' */

/* 蓄电池过温故障状态 */
extern MONPRM volatile uint8 VDAG_LVBattVoltHiFltSt_enum;/* '<S514>/FltStDeb' */

/* 蓄电池电压高故障状态 */
extern MONPRM volatile uint8 VDAG_LVBattVoltLoFltSt_enum;/* '<S513>/FltStDeb' */

/* 蓄电池电压低故障状态 */
extern MONPRM volatile boolean VDAG_LimpHome_flg;/* '<S91>/Switch2' */
extern MONPRM volatile boolean VDAG_LmtDrvTq_flg;/* '<S91>/Switch24' */
extern MONPRM volatile uint8 VDAG_OBCChrgReqFltSt_enum;/* '<S405>/FltStDeb' */

/* OBCChargeRequest故障状态 */
extern MONPRM volatile uint8 VDAG_OBCConnectTmOutFltSt_enum;/* '<S403>/FltStDeb' */

/* OBC连接超时故障状态 */
extern MONPRM volatile uint8 VDAG_OBCInletConnectFltSt_enum;/* '<S408>/FltStDeb' */

/* OBC插枪故障状态 */
extern MONPRM volatile uint8 VDAG_OBCModeMsmtchFltSt_enum;/* '<S402>/FltStDeb' */

/* OBC模式不匹配故障状态 */
extern MONPRM volatile uint8 VDAG_OBCS2StatFltSt_enum;/* '<S404>/FltStDeb' */

/* OBCS2连接超时故障状态 */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl1FltSt_enum;/* '<S409>/FltStDeb' */

/* OBCFailLevel1故障状态 */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl2FltSt_enum;/* '<S410>/FltStDeb' */

/* OBCFailLevel2故障状态 */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl3FltSt_enum;/* '<S411>/FltStDeb' */

/* OBCFailLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl4FltSt_enum;/* '<S399>/FltStDeb' */

/* OBCFailLevel4故障状态 */
extern MONPRM volatile uint8 VDAG_SecdHVILVoltHiFltSt_enum;/* '<S570>/FltStDeb' */

/* 次要高压互锁电压高故障状态 */
extern MONPRM volatile uint8 VDAG_SecdHVILVoltLoFltSt_enum;/* '<S569>/FltStDeb' */

/* 次要高压互锁电压低故障状态 */
extern MONPRM volatile uint8 VDAG_SysPwrModeInvldFltSt_enum;/* '<S465>/FltStDeb' */

/* PowerMode失效故障状态 */
extern MONPRM volatile uint8 VDAG_TMSFailLvl3FltSt_enum;/* '<S466>/FltStDeb' */

/* TMSRFailLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_VehCrashFltSt_enum;/* '<S534>/FltStDeb' */

/* 碰撞故障状态 */
extern MONPRM volatile boolean VDAG_WakeUp_flg;/* '<S327>/Chart' */

/* 硬线唤醒或者IBSLIN唤醒标志 */
extern MONPRM volatile uint8 VDAG_WaterTempAbvThrFltSt_enum;/* '<S590>/FltStDeb' */

/* 冷却水温过高故障状态 */
extern MONPRM volatile uint8 VDAG_WaterTempBlwThrFltSt_enum;/* '<S589>/FltStDeb' */

/* 冷却水温过低故障状态 */
extern MONPRM volatile float32 VDSA_AcceltnIdxAvg_pct;/* '<S17>/AvgAcceltnIdx' */
extern MONPRM volatile float32 VDSA_AcceltnIdxRaw_pct;/* '<S17>/Saturation1' */
extern MONPRM volatile float32 VDSA_BrkPedPstnAvg_pct;/* '<S17>/AvgBrkPedPstn' */
extern MONPRM volatile float32 VDSA_DrvSprtIdx_pct;/* '<S17>/Saturation2' */
extern MONPRM volatile boolean VDSA_SprtIdxHldAcc_flg;/* '<S17>/Logical Operator3' */
extern MONPRM volatile boolean VDSA_SprtIdxHldBrk_flg;/* '<S17>/Logical Operator6' */
extern MONPRM volatile float32 VDSA_TqCalcAcceltn_mps2;/* '<S17>/Divide1' */
extern MONPRM volatile boolean VEMS_ACCMOprtCmd_flg;/* '<S30>/ACCMEnble' */

/* 使能ACCM */
extern MONPRM volatile float32 VEMS_AccPwrRaw_kW;/* '<S31>/MinMax4' */
extern MONPRM volatile float32 VEMS_CellTempSyn_C;/* '<S85>/Switch1' */
extern MONPRM volatile float32 VEMS_CellUndrVoltDrtFac_c;/* '<S28>/Saturation3' */
extern MONPRM volatile float32 VEMS_ChrgCurFbKi_A;/* '<S82>/Saturation' */
extern MONPRM volatile float32 VEMS_ChrgCurFbKp_A;/* '<S82>/Product2' */
extern MONPRM volatile float32 VEMS_ChrgCurFb_A;/* '<S82>/Saturation2' */
extern MONPRM volatile float32 VEMS_ChrgOvrshtPwr_kW;/* '<S27>/Add1' */
extern MONPRM volatile float32 VEMS_ChrgPwrFbKi_kW;/* '<S46>/Saturation' */
extern MONPRM volatile float32 VEMS_ChrgPwrFbKp_kW;/* '<S46>/Product2' */
extern MONPRM volatile float32 VEMS_ChrgPwrFb_kW;/* '<S27>/Merge' */
extern MONPRM volatile float32 VEMS_DchaCurFbKi_A;/* '<S83>/Saturation' */
extern MONPRM volatile float32 VEMS_DchaCurFbKp_A;/* '<S83>/Product2' */
extern MONPRM volatile float32 VEMS_DchaCurFb_A;/* '<S83>/Saturation2' */
extern MONPRM volatile float32 VEMS_DchaOvrshtPwr_kW;/* '<S29>/Add1' */
extern MONPRM volatile float32 VEMS_DchaPwrFbKi_kW;/* '<S64>/Saturation' */
extern MONPRM volatile float32 VEMS_DchaPwrFbKp_kW;/* '<S64>/Product2' */
extern MONPRM volatile float32 VEMS_DchaPwrFb_kW;/* '<S29>/Merge' */
extern MONPRM volatile float32 VEMS_HVBatPwrAct_kW;/* '<S31>/Gain1' */
extern MONPRM volatile float32 VEMS_MaxChrgCur_A;/* '<S26>/Saturation4' */
extern MONPRM volatile float32 VEMS_MaxChrgPwr2MotRaw_kW;/* '<S26>/Add7' */
extern MONPRM volatile float32 VEMS_MaxChrgPwr2Mot_kW;/* '<S27>/MinMax2' */
extern MONPRM volatile float32 VEMS_MaxChrgPwr_kW;/* '<S26>/Product2' */
extern MONPRM volatile float32 VEMS_MaxConChrgCur_A;/* '<S26>/MinMax1' */
extern MONPRM volatile float32 VEMS_MaxConDchaCur_A;/* '<S28>/MinMax1' */
extern MONPRM volatile float32 VEMS_MaxDchaCur_A;/* '<S28>/Saturation4' */
extern MONPRM volatile float32 VEMS_MaxDchaPwr2MotRaw_kW;/* '<S28>/Add7' */
extern MONPRM volatile float32 VEMS_MaxDchaPwr2Mot_kW;/* '<S29>/MinMax2' */
extern MONPRM volatile float32 VEMS_MaxDchaPwr_kW;/* '<S28>/Product2' */
extern MONPRM volatile float32 VEMS_MaxInsChrgCur_A;/* '<S26>/MinMax3' */
extern MONPRM volatile float32 VEMS_MaxInsDchaCur_A;/* '<S28>/MinMax3' */
extern MONPRM volatile boolean VEMS_TMSActSOCEnbl_flg;/* '<S79>/Switch1' */

/* SOC是否限制TMS */
extern MONPRM volatile boolean VEMS_TMSPwrEnbl_flg;/* '<S30>/Switch3' */

/* 功率是否限制TMS */
extern MONPRM volatile float32 VEMS_TMSUsePwr_kW;/* '<S30>/Subtract' */

/* TMS可用功率 */
extern MONPRM volatile boolean VEMS_UseConChrgCur_flg;/* '<S37>/Switch4' */
extern MONPRM volatile boolean VEMS_UseConDchaCur_flg;/* '<S55>/Switch4' */
extern MONPRM volatile boolean VGSM_AsstDrvFbShft_flg;/* '<S1646>/Logical Operator2' */

/* 规范：ACC/CC禁止档位解析 */
extern MONPRM volatile boolean VGSM_AsstDrvReqEPB_flg;/* '<S1632>/Switch4' */

/* ACC通讯丢失或故障拉起EPB */
extern MONPRM volatile boolean VGSM_DRFlt2N_flg;/* '<S1645>/Switch1' */

/* 规范：退至非驱动档标志位 */
extern MONPRM volatile boolean VGSM_EPBAplyFlt_flg;/* '<S1622>/EPBLogical' */

/* 故障P-EPB拉起故障 */
extern MONPRM volatile boolean VGSM_EPBRelsFlt_flg;/* '<S1622>/EPBLogical' */

/* 故障P-EPB释放故障 */
extern MONPRM volatile boolean VGSM_GrD2PExcdTm_flg;/* '<S1799>/Chart' */

/* D档入P请求超时入N */
extern MONPRM volatile boolean VGSM_GrNReq2P_flg;/* '<S1645>/Switch2' */

/* N档非换挡请求进P档请求 */
extern MONPRM volatile boolean VGSM_GrR2PExcdTm_flg;/* '<S1796>/Chart' */

/* R档入P请求超时入N */
extern MONPRM volatile boolean VGSM_HldGearP_flg;/* '<S1645>/Switch' */

/* 规范：保持P档标志位 */
extern MONPRM volatile boolean VGSM_INVRunEnbl_flg;/* '<S1648>/Chart' */

/* 规范：INV使能控制（允许扭矩控制）-VCU_1_EnaInvRun */
extern MONPRM volatile uint8 VGSM_PGrSwSts_enum;/* '<S1646>/Switch2' */

/* 规范：P按键触发标志位-VCU_PGearSwcst */
extern MONPRM volatile boolean VGSM_ReqEPBAply_flg;/* '<S1647>/Logical Operator6' */

/* 规范：EPB拉起请求标志位 */
extern MONPRM volatile boolean VGSM_ReqEPBRels_flg;/* '<S1647>/Logical Operator4' */

/* 规范：EPB释放请求标志位 */
extern MONPRM volatile EnumEPBReq VGSM_ReqEPB_enum;/* '<S1622>/Switch' */

/* 规范：EPB操作信号-VCUF_ReqEPB */
extern MONPRM volatile EnumTgtGearPstn VGSM_ShftTgtGrReq_enum;/* '<S1646>/Data Type Conversion1' */

/* 换挡杆目标档位 0-NoCmd 1-P 2-N 3-D 4-R  */
extern MONPRM volatile EnumGearPstn VGSM_VehActGearPstn_enum;/* '<S1623>/Switch1' */

/* 规范：实际档位-VCU_VhclActlGearPos */
extern MONPRM volatile boolean VGSM_VehEPBStErr_flg;/* '<S1622>/Logical Operator' */

/* 规范：P档故障PGear error-VCU_VhclPGearError */
extern MONPRM volatile EnumTgtGearPstn VGSM_VehTgtGrReq_enum;/* '<S1647>/Data Type Conversion1' */

/* 规范:目标档位 */
extern MONPRM volatile uint8 VGSM_VehTgtGrTrnsfr_enum;/* '<S1685>/Switch' */

/* 规范：换档请求信号 */
extern MONPRM volatile uint8 VHMI_12VBatLowVolSta_enum;/* '<S638>/Switch' */
extern MONPRM volatile float32 VHMI_GrDSldDist_m;/* '<S652>/Saturation' */

/* D档后溜距离 */
extern MONPRM volatile boolean VHMI_GrDSldSw_flg;/* '<S652>/Logical Operator' */

/* D档溜坡计速/距离标志 */
extern MONPRM volatile float32 VHMI_GrRSldDist_m;/* '<S652>/Saturation1' */

/* R档前溜距离 */
extern MONPRM volatile boolean VHMI_GrRSldSw_flg;/* '<S652>/Logical Operator4' */

/* R档溜坡计速/距离标志 */
extern MONPRM volatile uint8 VHMI_InfoDisp_enum;/* '<S641>/Arbitration' */

/* 仪表弹窗值 */
extern MONPRM volatile boolean VHVM_ACChrgEnbl_flg;/* '<S793>/Logical Operator8' */

/* 交流充电基本条件满足 */
extern MONPRM volatile uint8 VHVM_ACChrgMaxCurrFb_A;/* '<S764>/Switch4' */

/* HU设置电流反馈 */
extern MONPRM volatile uint8 VHVM_ACChrgModeFb_enum;/* '<S764>/Switch7' */

/* HU设置充电模式反馈 */
extern MONPRM volatile boolean VHVM_ACChrging2Stop_flg;/* '<S787>/AND' */

/* 交流充电中转移到充电停止标志位 */
extern MONPRM volatile boolean VHVM_ACDchaEnbl_flg;/* '<S793>/Logical Operator10' */

/* 交流放电基本条件满足 */
extern MONPRM volatile boolean VHVM_ACDschrging2Stop_flg;/* '<S787>/AND7' */

/* 交流放电中转移到放电停止标志位 */
extern MONPRM volatile EnumBMSSdnCmd VHVM_BMSShutdown_enum;/* '<S763>/Data Type Conversion10' */

/* VCU关闭BMS指令对应CAN信号：VCU_BMS_Shutdown */
extern MONPRM volatile EnumBMSWakeUpMd VHVM_BMSWakeUpMode_enum;/* '<S763>/Data Type Conversion8' */

/* VCU唤醒BMS的方式对应CAN信号：VCU_BMS_WakeupMode */
extern MONPRM volatile boolean VHVM_Bat2DrvTrainEnbl_flg;/* '<S763>/MainState' */

/* VCU控制主继电器指令对应CAN信号：VCU_Bat2DrvTrainEnb */
extern MONPRM volatile EnumChrgAllwCmd VHVM_ChrgAllowCmd_enum;/* '<S763>/Data Type Conversion12' */

/* VCU发送允许充电指令对应CAN信号：VCU_ChrgAllowCmd */
extern MONPRM volatile uint8 VHVM_ChrgEnaAC_enum;/* '<S763>/MainState' */

/* VCU控制OBC交流充电使能指令对应CAN信号：VCU_ChrgEna_AC */
extern MONPRM volatile boolean VHVM_ChrgEnaDC_flg;/* '<S763>/MainState' */

/* VCU控制BMS直流充电使能指令对应CAN信号：VCU_ChrgEna_DC */
extern MONPRM volatile float32 VHVM_DCCBuckLVVolt_V;/* '<S763>/MainState' */

/* VCU控制DCDC BUCK电压值对应CAN信号：VCU_DCCBuckLV_Vol */
extern MONPRM volatile EnumDCCOprtCmd VHVM_DCCOprtCmd_enum;/* '<S763>/Data Type Conversion6' */

/* VCU控制DCDC工作模式指令对应CAN信号：VCU_DCCOprtCmd */
extern MONPRM volatile boolean VHVM_DCChrgEnbl_flg;/* '<S793>/Logical Operator2' */

/* 直流充电基本条件满足 */
extern MONPRM volatile boolean VHVM_DCChrging2Over_flg;/* '<S787>/AND1' */

/* 直流充电中转移到充电结束标志位 */
extern MONPRM volatile boolean VHVM_ECUSleepAllwd_flg;/* '<S763>/MainState' */

/* 允许底层休眠标志位 */
extern MONPRM volatile boolean VHVM_EmgcySdn_flg;/* '<S763>/MainState' */

/* VCU给INV发送紧急下电指令(INV强制停机)对应CAN信号：VCU_1_EmShutDown */
extern MONPRM volatile boolean VHVM_EnaDisChg_flg;/* '<S763>/MainState' */

/* VCU控制INV泄放指令对应CAN信号：VCU_1_EnaDisChg */
extern MONPRM volatile boolean VHVM_EngyExtrmLo_flg;/* '<S766>/Logical Operator17' */

/* 电池能量极低标志位 */
extern MONPRM volatile boolean VHVM_INVEnbl_flg;/* '<S763>/MainState' */

/* VCU硬线唤醒INV */
extern MONPRM volatile boolean VHVM_INVPreprogmFlg_flg;/* '<S788>/Switch1' */

/* INV预编程条件满足 */
extern MONPRM volatile float32 VHVM_MaxChrgCurntDC_A;/* '<S763>/MainState' */

/* VCU允许BMS直流充电最大电流对应CAN信号：VCU_MaxChrgCrnt_DC */
extern MONPRM volatile float32 VHVM_MaxChrgVoltDC_V;/* '<S763>/MainState' */

/* VCU允许BMS直流充电最大电压对应CAN信号：VCU_MaxChrgVol_DC */
extern MONPRM volatile float32 VHVM_MaxHVDCCurntAC_A;/* '<S763>/MainState' */

/* VCU允许OBC交流充电最大电流对应CAN信号：VCU_MaxHVDC_Cur_AC */
extern MONPRM volatile float32 VHVM_MaxHVDCVoltAC_V;/* '<S763>/MainState' */

/* VCU允许OBC交流充电最大电压对应CAN信号：VCU_MaxHVDC_Vol_AC */
extern MONPRM volatile EnumOBCOprtCmd VHVM_OBCOprtCmd_enum;/* '<S764>/Data Type Conversion4' */

/* VCU控制OBC工作模式指令对应CAN信号：VCU_OBCOprtCmd */
extern MONPRM volatile EnumPTActMd VHVM_PTActOprtMode_enum;/* '<S763>/Data Type Conversion4' */

/* 高压PT状态 */
extern MONPRM volatile boolean VHVM_PTRdy2PTStdby_flg;/* '<S790>/Switch1' */

/* PTRdy到PTStdby标志位 */
extern MONPRM volatile boolean VHVM_PTStdby2PTRdy_flg;/* '<S790>/Switch' */

/* PTStdby到PTRdy标志位 */
extern MONPRM volatile boolean VHVM_PowUpSelfChek_flg;/* '<S791>/Switch' */

/* 高压自检标志位 */
extern MONPRM volatile boolean VHVM_PwrOn2PwrDwn_flg;/* '<S792>/Switch' */

/* 高压下电条件满足标志位（正常/故障/紧急） */
extern MONPRM volatile boolean VHVM_SOPExtrmLo_flg;/* '<S766>/Relational Operator4' */

/* 电池SOP极低，用于关闭DCDC */
extern MONPRM volatile EnumSysSta VHVM_SysSta_enum;/* '<S763>/Data Type Conversion2' */

/* 高压子状态 */
extern MONPRM volatile uint8 VHVM_TBOX2OBC_emun;/* '<S764>/Switch1' */

/* TBOX远程充放电指令 */
extern MONPRM volatile EnumVCUMode VHVM_VCUMode_enum;/* '<S763>/Data Type Conversion' */

/* 高压主转态 */
extern MONPRM volatile boolean VHVM_VehHalt_flg;/* '<S782>/Switch4' */

/* 车辆停止标志位（车速极其） */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpACChrg_flg;/* '<S793>/Logical Operator16' */

/* 交流充电唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpACDcha_flg;/* '<S793>/Logical Operator26' */

/* 交流放电唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpDCChrg_flg;/* '<S793>/Logical Operator4' */

/* 直流充电唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpIBS_flg;/* '<S793>/Logical Operator6' */

/* IBS唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpKL15_flg;/* '<S793>/Logical Operator' */

/* K15唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUp_flg;/* '<S793>/Switch' */

/* 唤醒到上高压条件满足（唤醒源上升沿+高压自检通过） */
extern MONPRM volatile boolean VHVM_WakeUpBMS_flg;/* '<S763>/MainState' */

/* VCU硬线唤醒BMS */
extern MONPRM volatile boolean VHVM_WakeUpVCU_flg;/* '<S794>/Switch' */

/* 休眠到唤醒条件满足 */
extern MONPRM volatile boolean VIBS_BMSBatSOCAllow_flg;/* '<S1031>/Switch3' */

/* 动力电池SOC允许补电标志位_versteckt */
extern MONPRM volatile boolean VIBS_ChgNumAllow_flg;/* '<S1031>/AND' */

/* 补电次数允许标志位_versteckt */
extern MONPRM volatile uint8 VIBS_ChgNum_cnt;/* '<S1031>/Switch2' */

/* IBS补电次数_versteckt */
extern MONPRM volatile boolean VIBS_ChrgBascCond_flg;/* '<S1031>/Logical Operator2' */

/* 补电基本条件满足（补电次数及电压）_versteckt */
extern MONPRM volatile boolean VIBS_ChrgEnbl_flg;/* '<S1031>/Logical Operator7' */

/* IBS充电使能标志位_versteckt */
extern MONPRM volatile boolean VIBS_ChrgOver_flg;/* '<S1029>/ChrgSt' */

/* IBS补电结束标志位_versteckt */
extern MONPRM volatile float32 VIBS_ChrgVoltThr_V;/* '<S1032>/VoltState' */

/* 补电电压阈值_versteckt */
extern MONPRM volatile float32 VIBS_EnvirTemp_C;/* '<S1051>/Switch' */

/* IBS环境温度_versteckt */
extern MONPRM volatile uint8 VIBS_FailChgNum_cnt;/* '<S1031>/Switch5' */

/* IBS补电失败次数_versteckt */
extern MONPRM volatile boolean VIBS_FbRctWup_flg;/* '<S1031>/Logical Operator6' */

/* IBS禁止RTC唤醒标志位_versteckt */
extern MONPRM volatile boolean VIBS_HVReq_flg;/* '<S1031>/Switch' */

/* IBS请求上高压标志位_versteckt */
extern MONPRM volatile float32 VIBS_HwKL30_V;/* '<S1050>/Switch' */

/* 滤波后的KL30电压_versteckt */
extern MONPRM volatile boolean VIBS_NMReq_flg;/* '<S1038>/Switch4' */

/* IBS请求网络标志位_versteckt */
extern MONPRM volatile uint16 VIBS_NextRtcWupThr_min;/* '<S1032>/Switch1' */

/* 下次补电唤醒RTC的时间_versteckt */
extern MONPRM volatile EnumIBSChrgSt VIBS_RTCChrgSt_enum;/* '<S1029>/Data Type Conversion' */

/* IBS补电状态_versteckt */
extern MONPRM volatile boolean VIBS_RTCWakeup_flg;/* '<S1056>/Chart' */

/* RTC唤醒标志位（含延迟时间）_versteckt */
extern MONPRM volatile boolean VIBS_SleepAllwd_flg;/* '<S1031>/SleepAllwd' */

/* IBS允许底层休眠标志位_versteckt */
extern MONPRM volatile uint16 VIBS_WupChgTmThr_min;/* '<S1032>/Switch2' */

/* IBS补电时间阈值_versteckt */
extern MONPRM volatile boolean VIBS_WupVoltAllow_flg;/* '<S1052>/Switch4' */

/* KL30电压允许标志位_versteckt */
extern MONPRM volatile boolean VIPC_ACCCfgd_flg;/* '<S903>/Switch8' */
extern MONPRM volatile boolean VIPC_AccPed1Flt_flg;/* '<S907>/Logical Operator1' */
extern MONPRM volatile boolean VIPC_AccPed1LrnDwnActv_flg;/* '<S917>/Relational Operator' */
extern MONPRM volatile boolean VIPC_AccPed1LrnUpActv_flg;/* '<S910>/Logical Operator5' */
extern MONPRM volatile float32 VIPC_AccPed1MinPstnLrnd_pct;/* '<S910>/Switch2' */
extern MONPRM volatile float32 VIPC_AccPed1NormzAvg_pct;/* '<S916>/Switch' */
extern MONPRM volatile float32 VIPC_AccPed1NormzPstn_pct;/* '<S907>/Switch5' */
extern MONPRM volatile float32 VIPC_AccPed1SclPstn_pct;/* '<S911>/Divide1' */
extern MONPRM volatile boolean VIPC_AccPed2Flt_flg;/* '<S907>/Logical Operator2' */
extern MONPRM volatile boolean VIPC_AccPed2LrnDwnActv_flg;/* '<S921>/Relational Operator' */
extern MONPRM volatile boolean VIPC_AccPed2LrnUpActv_flg;/* '<S912>/Logical Operator5' */
extern MONPRM volatile float32 VIPC_AccPed2MinPstnLrnd_pct;/* '<S912>/Switch2' */
extern MONPRM volatile float32 VIPC_AccPed2NormzAvg_pct;/* '<S920>/Switch' */
extern MONPRM volatile float32 VIPC_AccPed2NormzPstn_pct;/* '<S907>/Switch7' */
extern MONPRM volatile float32 VIPC_AccPed2SclPstn_pct;/* '<S913>/Divide5' */
extern MONPRM volatile boolean VIPC_AccPedPstnVld_flg;/* '<S909>/Switch3' */
extern MONPRM volatile float32 VIPC_AccPedPstn_pct;/* '<S905>/MinMax3' */
extern MONPRM volatile uint8 VIPC_AccPedSnsrSta_enum;/* '<S909>/Switch3' */
extern MONPRM volatile boolean VIPC_AccPedStkActv_flg;/* '<S908>/Logical Operator6' */
extern MONPRM volatile boolean VIPC_AccPedStkBrkPrsd_flg;/* '<S935>/Switch4' */
extern MONPRM volatile float32 VIPC_AccPedStkPstn_pct;/* '<S908>/MinMax' */
extern MONPRM volatile boolean VIPC_AccPedStkStab_flg;/* '<S937>/Relational Operator' */
extern MONPRM volatile float32 VIPC_AccPedWghtAvg_pct;/* '<S934>/Switch' */
extern MONPRM volatile float32 VIPC_AccPedWghtPstn_pct;/* '<S909>/Switch3' */
extern MONPRM volatile float32 VIPC_AccPedZeroPstn_pct;/* '<S908>/Switch' */
extern MONPRM volatile boolean VIPC_BrkPedPstnVld_flg;/* '<S900>/Logical Operator8' */
extern MONPRM volatile float32 VIPC_BrkPedPstn_pct;/* '<S900>/Saturation1' */
extern MONPRM volatile boolean VIPC_BrkSwActv_flg;/* '<S900>/Logical Operator' */
extern MONPRM volatile boolean VIPC_CCSCfgd_flg;/* '<S903>/Switch1' */
extern MONPRM volatile boolean VIPC_CrpCtrlCfgd_flg;/* '<S903>/Switch2' */
extern MONPRM volatile EnumCrpModeAct VIPC_CrpModeAct_enum;/* '<S902>/Switch12' */
extern MONPRM volatile EnumDrvModeAct VIPC_DrvModeAct_enum;/* '<S902>/Switch13' */
extern MONPRM volatile uint8 VIPC_DrvPwrIntnsty_pct;/* '<S902>/Switch25' */
extern MONPRM volatile boolean VIPC_DrvSw_flg;/* '<S905>/Relational Operator3' */
extern MONPRM volatile boolean VIPC_EPBAppld_flg;/* '<S901>/Logical Operator2' */
extern MONPRM volatile boolean VIPC_EPBReld_flg;/* '<S901>/Logical Operator1' */
extern MONPRM volatile boolean VIPC_HDCCfgd_flg;/* '<S903>/Switch3' */
extern MONPRM volatile EnumRegenModeAct VIPC_RegenModeAct_enum;/* '<S902>/Switch15' */
extern MONPRM volatile uint8 VIPC_RegenPwrIntnsty_pct;/* '<S902>/Switch28' */
extern MONPRM volatile boolean VIPC_SnowMode_flg;/* '<S902>/Switch14' */
extern MONPRM volatile float32 VIPC_TireRadius_m;/* '<S903>/TireSizeTable' */
extern MONPRM volatile uint8 VIPC_VehHiddenMode_enum;/* '<S902>/VehHiddenMode' */
extern MONPRM volatile float32 VIPC_VehSpdDrvnMotor_kph;/* '<S904>/Product1' */
extern MONPRM volatile boolean VIPC_VehSpdDrvnVld_flg;/* '<S971>/Logical Operator2' */
extern MONPRM volatile float32 VIPC_VehSpdDrvn_kph;/* '<S971>/Switch7' */
extern MONPRM volatile boolean VIPC_VehSpdNonDrvnVld_flg;/* '<S972>/Logical Operator2' */
extern MONPRM volatile float32 VIPC_VehSpdNonDrvn_kph;/* '<S972>/Switch7' */
extern MONPRM volatile boolean VIPC_VehSpdVld_flg;/* '<S971>/SignalConversion' */
extern MONPRM volatile float32 VIPC_VehSpd_kph;/* '<S971>/Switch4' */
extern MONPRM volatile boolean VIPC_VpedAutoCrp_flg;/* '<S959>/Switch4' */
extern MONPRM volatile boolean VIPC_ZeroPstnRst_flg;/* '<S908>/Logical Operator3' */
extern MONPRM volatile boolean VIPC_iTPMSCfgd_flg;/* '<S903>/Switch4' */
extern MONPRM volatile float32 VIPM_HwAccPedCh1SuplyVolt_mV;/* '<S1575>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh1Volt_mV;/* '<S1576>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh2SuplyVolt_mV;/* '<S1577>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh2Volt_mV;/* '<S1578>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwBMSWakeup_flg;/* '<S1579>/Switch4' */
extern MONPRM volatile boolean VIPM_HwBrkSwHi_flg;/* '<S1580>/Switch4' */
extern MONPRM volatile boolean VIPM_HwBrkSwLo_flg;/* '<S1581>/Switch4' */
extern MONPRM volatile boolean VIPM_HwCrpModeSw_flg;/* '<S1582>/Switch4' */
extern MONPRM volatile boolean VIPM_HwDrvModeSw_flg;/* '<S1583>/Switch4' */
extern MONPRM volatile boolean VIPM_HwEmgcyShutOff_flg;/* '<S1584>/Switch4' */
extern MONPRM volatile float32 VIPM_HwHVIL1Volt_mV;/* '<S1585>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwHVIL2Volt_mV;/* '<S1586>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwKL15A_flg;/* '<S1587>/Switch4' */
extern MONPRM volatile boolean VIPM_HwKL15B_flg;/* '<S1588>/Switch4' */
extern MONPRM volatile uint16 VIPM_HwKL30_mV;/* '<S1589>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwOBCWakeup_flg;/* '<S1590>/Switch4' */
extern MONPRM volatile boolean VIPM_HwRearFogLampSwt_flg;/* '<S1591>/Switch4' */
extern MONPRM volatile EnumPGearSwSts VIPM_HwShftPstnSwSts_enum;/* '<S1592>/Switch4' */
extern MONPRM volatile uint16 VIPM_HwShftPstnSw_Ohm;/* '<S1572>/HwShftPstnSw' */
extern MONPRM volatile boolean VIPM_HwVehCrash_flg;/* '<S1593>/Switch4' */
extern MONPRM volatile uint8 VNVM_ACChrgMaxCurrFb_A;/* '<S1573>/Selector18' */
extern MONPRM volatile uint8 VNVM_ACChrgModeFb_enum;/* '<S1573>/Selector19' */
extern MONPRM volatile float32 VNVM_AvgPwrCnsm_kWh100km;/* '<S1573>/Add2' */
extern MONPRM volatile float32 VNVM_AvgSOCCnsmWght_pctp100km;/* '<S1573>/Add6' */
extern MONPRM volatile EnumCrpModeAct VNVM_CrpModeAct_enum;/* '<S1573>/Data Type Conversion1' */
extern MONPRM volatile EnumDrvModeAct VNVM_DrvModeAct_enum;/* '<S1573>/Data Type Conversion23' */
extern MONPRM volatile uint8 VNVM_DrvPwrIntnsty_pct;/* '<S1573>/Selector6' */
extern MONPRM volatile float32 VNVM_DynRmnMilEst_km;/* '<S1573>/Gain2' */
extern MONPRM volatile uint8 VNVM_EE01ReadOK_nu;/* '<S1573>/Selector13' */
extern MONPRM volatile uint8 VNVM_EEImdtReadOK_nu;/* '<S1573>/Selector14' */
extern MONPRM volatile uint8 VNVM_IBSChrgFailNum_cnt;/* '<S1573>/Selector1' */
extern MONPRM volatile uint8 VNVM_IBSChrgNum_cnt;/* '<S1573>/Selector' */
extern MONPRM volatile EnumRegenModeAct VNVM_RegenModeAct_enum;/* '<S1573>/Data Type Conversion24' */
extern MONPRM volatile uint8 VNVM_RegenPwrIntnsty_pct;/* '<S1573>/Selector7' */
extern MONPRM volatile boolean VNVM_TBOXOffline_flg;/* '<S1573>/Data Type Conversion11' */
extern MONPRM volatile EnumTBOXLimSt VNVM_VCUSpdLimSt_enum;/* '<S1573>/Data Type Conversion10' */
extern MONPRM volatile boolean VNVM_VCUVerFb_flg;/* '<S1573>/Data Type Conversion12' */
extern MONPRM volatile EnumXWhlDistErrRefSt VNVM_XWhlDistErrRefStat_enum;/* '<S1573>/Data Type Conversion22' */
extern MONPRM volatile float32 VNVM_XWhlDistErrRef_mpkm;/* '<S1573>/Add1' */
extern MONPRM volatile boolean VNVM_iTPMSWrng_flg;/* '<S1573>/Data Type Conversion21' */
extern MONPRM volatile boolean VOPM_HwWakeupBMS_flg;/* '<S1607>/Switch4' */
extern MONPRM volatile float32 VRME_AvgSOCCnsm100Num_pctpkm;/* '<S1010>/Signal Copy5' */

/* 前100个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm10Num_pctpkm;/* '<S1010>/Signal Copy1' */

/* 前10个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm15Num_pctpkm;/* '<S1010>/Signal Copy2' */

/* 前15个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm25Num_pctpkm;/* '<S1010>/Signal Copy3' */

/* 前25个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm50Num_pctpkm;/* '<S1010>/Signal Copy4' */

/* 前50个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm5Num_pctpkm;/* '<S1010>/Signal Copy' */

/* 前5个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsmWght_pctpkm;/* '<S1010>/Switch1' */

/* 加权平均SOC能耗/km */
extern MONPRM volatile boolean VRME_CHTCRmnMilEstV_flg;/* '<S980>/Logical Operator' */

/* CHTC标准续航里程有效性 */
extern MONPRM volatile float32 VRME_CHTCRmnMilEst_km;/* '<S980>/MRME_CHTCStdRmnMil_km' */

/* CHTC标准续航查表值 */
extern MONPRM volatile float32 VRME_CalPwrCnsmPerTrig_kWhptrig;/* '<S984>/Switch4' */

/* Pwr消耗/单位里程（trig） */
extern MONPRM volatile float32 VRME_CalPwrCnsmPerkm_kWhpkm;/* '<S984>/Divide' */

/* Pwr消耗/单位里程（1km） */
extern MONPRM volatile boolean VRME_CalPwrCnsmTrig_flg;/* '<S984>/Relational Operator1' */

/* 累计里程大于单位里程 */
extern MONPRM volatile float32 VRME_CalSOCCnsmPerTrig_pctptrig;/* '<S1009>/Switch4' */

/* SOC消耗/单位里程（trig） */
extern MONPRM volatile float32 VRME_CalSOCCnsmPerkm_pctpkm;/* '<S1009>/Divide' */

/* SOC消耗/单位里程（1km） */
extern MONPRM volatile float32 VRME_CalSOCCnsmTgtDist_m;/* '<S1009>/Switch1' */

/* 单位目标行驶里程 */
extern MONPRM volatile boolean VRME_CalSOCCnsmTrig_flg;/* '<S1009>/Relational Operator1' */

/* 累计里程大于目标里程 */
extern MONPRM volatile float32 VRME_ChrgRmnMilEstTgt_km;/* '<S1005>/Switch2' */

/* 充电模式动态续航目标值 */
extern MONPRM volatile float32 VRME_ChrgRmnMilEst_km;/* '<S1006>/Switch2' */

/* 充电工况动态续航值 */
extern MONPRM volatile float32 VRME_ChrgTgtFstRate_kmpsoc;/* '<S995>/Divide2' */

/* 充电工况目标续航追击速率 */
extern MONPRM volatile float32 VRME_ChrgTgtNormRate_kmpsoc;/* '<S995>/Divide1' */

/* 充电工况目标续航变化速率 */
extern MONPRM volatile float32 VRME_DchaRmnMilEstChgFac_c;/* '<S1008>/MRME_DynEstRmnChgStp_c' */

/* 非充电模式动态续航变化系数 */
extern MONPRM volatile float32 VRME_DchaRmnMilEstTgt_km;/* '<S1020>/Switch2' */

/* 非充电模式动态续航目标值 */
extern MONPRM volatile boolean VRME_DchaRmnMilEstUpdTrig_flg;/* '<S1008>/Relational Operator2' */

/* 更新续航值 */
extern MONPRM volatile float32 VRME_DchaRmnMilEst_km;/* '<S1019>/Switch2' */

/* 非充电模式动态续航值 */
extern MONPRM volatile boolean VRME_DchaVehStac_flg;/* '<S1007>/Logical Operator4' */

/* 非充电模式车辆驻车状态 */
extern MONPRM volatile boolean VRME_DynRmnMilEstV_flg;/* '<S987>/Logical Operator1' */

/* 动态续航有效性 */
extern MONPRM volatile float32 VRME_DynRmnMilEst_km;/* '<S992>/Switch2' */

/* 综合的动态续航值 */
extern MONPRM volatile float32 VRME_VehPwrCnsmAvg_kWhpkm;/* '<S984>/Switch7' */

/* 当前循环平均能耗 */
extern MONPRM volatile float32 VRME_VehTotMilCyc_km;/* '<S984>/Gain8' */

/* 当前驾驶循环车辆里程 */
extern MONPRM volatile float32 VRME_VehTotPwrCyc_kWh;/* '<S984>/Switch6' */

/* 当前驾驶循环车辆功率 */
extern MONPRM volatile float32 VRME_WLTPRmnMilEstDwLim_km;/* '<S989>/Product3' */

/* 动态续航下限值 */
extern MONPRM volatile float32 VRME_WLTPRmnMilEstUpLim_km;/* '<S989>/Product2' */

/* 动态续航上限值 */
extern MONPRM volatile float32 VRME_WLTPRmnMilEst_km;/* '<S989>/MRME_WLTPStdRmnMil_km' */

/* WLTP标准续航查表值 */
extern MONPRM volatile float32 VRME_WLTPStdPwrCnsm_kWhpkm;/* '<S984>/Gain5' */

/* 标准工况电耗（kWh/km） */
extern MONPRM volatile float32 VRME_WLTPStdSOCCnsm_pctpkm;/* '<S989>/Gain3' */

/* 标准工况下SOC消耗/km */
extern MONPRM volatile boolean VTBX_CnclSpdLim_flg;/* '<S1082>/Logical Operator12' */

/* TBOX解除限速 */
extern MONPRM volatile boolean VTBX_LckVer_flg;/* '<S1102>/Chart' */

/* 锁车版本 */
extern MONPRM volatile boolean VTBX_RecryTBOXHw_flg;/* '<S1082>/Logical Operator14' */

/* TBOX硬件通讯丢失恢复 */
extern MONPRM volatile boolean VTBX_ReqLimpHome_flg;/* '<S1081>/Data Type Conversion6' */

/* VCU请求跛行动作 */
extern MONPRM volatile boolean VTBX_RmvTBOXHw_flg;/* '<S1082>/Logical Operator3' */

/* TBOX硬件通讯丢失 */
extern MONPRM volatile boolean VTBX_SpdLimLvl1_flg;/* '<S1082>/Logical Operator5' */

/* TBOX一级限速 */
extern MONPRM volatile boolean VTBX_SpdLimLvl2_flg;/* '<S1082>/Logical Operator7' */

/* TBOX二级限速 */
extern MONPRM volatile boolean VTBX_SpdLimLvl3_flg;/* '<S1082>/Logical Operator9' */

/* TBOX三级限速 */
extern MONPRM volatile boolean VTBX_StorgSpdLim_flg;/* '<S1082>/Logical Operator11' */

/* TBOX库存限速 */
extern MONPRM volatile boolean VTBX_TBOXOffline_flg;/* '<S1081>/Signal Copy3' */

/* TBOX硬件状态-实时存储 */
extern MONPRM volatile boolean VTBX_UnlckVer_flg;/* '<S1101>/Chart' */

/* 非锁车版本 */
extern MONPRM volatile boolean VTBX_VCUChrgngCondsFb_flg;/* '<S1081>/Data Type Conversion5' */

/* VCU反馈判断充电条件 */
extern MONPRM volatile uint8 VTBX_VCULckVehWrn_enum;/* '<S1081>/Signal Copy5' */

/* VCU反馈锁存提醒 */
extern MONPRM volatile boolean VTBX_VCUOprtLicFb_flg;/* '<S1081>/Data Type Conversion4' */

/* VCU反馈运营状态 */
extern MONPRM volatile EnumTBOXLimGrd VTBX_VCUSpdLimLvlFb_enum;/* '<S1081>/Data Type Conversion3' */

/* VCU反馈限速等级-当前驾驶循环 */
extern MONPRM volatile uint8 VTBX_VCUSpdLimLvlSetFb_enum;/* '<S1081>/Data Type Conversion7' */

/* VCU反馈限速等级设置成功 */
extern MONPRM volatile EnumTBOXLimSt VTBX_VCUSpdLimSt_enum;/* '<S1081>/Data Type Conversion1' */

/* 当前循环限速状态-实时存储 */
extern MONPRM volatile boolean VTBX_VCUVerFb_flg;/* '<S1081>/Signal Copy' */

/* VCU反馈锁车版本-实时存储 */
extern MONPRM volatile uint8 VTBX_VCUVerSetFb_enum;/* '<S1081>/Signal Copy1' */

/* VCU反馈锁车版本设置成功 */
extern MONPRM volatile float32 VTQC_ABSorESPActvTm_s;/* '<S1379>/MinMax' */
extern MONPRM volatile float32 VTQC_BrkRegenMaxTqWhl_Nm;/* '<S1374>/Switch17' */
extern MONPRM volatile float32 VTQC_BrkRegenTgtTqWhl_Nm;/* '<S1374>/Switch2' */
extern MONPRM volatile float32 VTQC_CstRegenLmtTq_Nm;/* '<S1372>/CstRegenLmtTq' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhlABS_Nm;/* '<S1372>/MinMax1' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhlRBS_Nm;/* '<S1381>/MinMax5' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhl_Nm;/* '<S1373>/Switch5' */
extern MONPRM volatile float32 VTQC_MotorTqReq_Nm;/* '<S1373>/Divide' */
extern MONPRM volatile boolean VTQC_RBSActv_flg;/* '<S1382>/Switch4' */
extern MONPRM volatile float32 VTQD_AccelPedPstnRescl_pct;/* '<S1393>/Product' */
extern MONPRM volatile float32 VTQD_AdaptCstDeltaAcceltn_mps2;/* '<S1409>/Add5' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqFF_Nm;/* '<S1409>/Add2' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqI_N;/* '<S1409>/Saturation2' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqPID_Nm;/* '<S1409>/Product6' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqP_N;/* '<S1409>/Product3' */
extern MONPRM volatile float32 VTQD_AdaptCstMaxTqWhl_Nm;/* '<S1405>/MinMax4' */
extern MONPRM volatile float32 VTQD_AdaptCstMinTqWhl_Nm;/* '<S1405>/MinMax5' */
extern MONPRM volatile boolean VTQD_AdaptCstRegenEnbl_flg;/* '<S1405>/Logical Operator9' */
extern MONPRM volatile float32 VTQD_AdaptCstTgtAcceltn_mps2;/* '<S1411>/Switch' */
extern MONPRM volatile float32 VTQD_AdaptCstTqReqWhl_Nm;/* '<S1409>/MinMax6' */
extern MONPRM volatile boolean VTQD_BkwdDrv_flg;/* '<S1432>/Switch4' */
extern MONPRM volatile boolean VTQD_BrkRegenEnbl_flg;/* '<S1404>/Logical Operator1' */
extern MONPRM volatile float32 VTQD_CrpTqReqWhl_Nm;/* '<S1395>/Switch2' */
extern MONPRM volatile boolean VTQD_CstRegenEnbl_flg;/* '<S1404>/Logical Operator13' */
extern MONPRM volatile float32 VTQD_CstRegenEndPstn_pct;/* '<S1404>/Switch2' */
extern MONPRM volatile float32 VTQD_CstRegenTqReqWhl_Nm;/* '<S1406>/Switch4' */
extern MONPRM volatile float32 VTQD_DrvTqDrtFac_c;/* '<S1433>/Saturation' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhlMrg_Nm;/* '<S1434>/Switch4' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhlRaw_Nm;/* '<S1393>/Merge' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhl_Nm;/* '<S1391>/Switch3' */
extern MONPRM volatile boolean VTQD_DsblCrp_flg;/* '<S1395>/Logical Operator12' */
extern MONPRM volatile float32 VTQD_FullPedDrvTqWhl_Nm;/* '<S1393>/Signal Conversion1' */
extern MONPRM volatile float32 VTQD_FwdPedMap_pct;/* '<S1396>/Switch9' */
extern MONPRM volatile float32 VTQD_PedalTqReqWhlRaw_Nm;/* '<S1390>/Add' */
extern MONPRM volatile uint16 VTQD_TaskRunCounter_cnt;/* '<S1227>/Max1' */

/* test signal, to be deleted */
extern MONPRM volatile boolean VTQD_TqZeroFast_flg;/* '<S1425>/Logical Operator4' */
extern MONPRM volatile boolean VTQD_TqZeroSlow_flg;/* '<S1425>/Logical Operator2' */
extern MONPRM volatile boolean VTQD_TqZero_flg;/* '<S1425>/Logical Operator1' */
extern MONPRM volatile float32 VTQF_DrvTqReqWhl_Nm;/* '<S1450>/Switch2' */
extern MONPRM volatile float32 VTQF_TipOutTqDecRateCoeff_rat;/* '<S1452>/1-D Lookup Table1' */
extern MONPRM volatile boolean VTQF_TqInc_flg;/* '<S1462>/Switch4' */
extern MONPRM volatile float32 VTQF_TqOutChgRate_Nmps;/* '<S1472>/Switch' */
extern MONPRM volatile float32 VTQF_TqRateDecTgtMax_Nmps;/* '<S1452>/Switch3' */
extern MONPRM volatile float32 VTQF_TqRateDecTgtMin_Nmps;/* '<S1452>/MinMax4' */
extern MONPRM volatile float32 VTQF_TqRateIncTgtMax_Nmps;/* '<S1453>/Switch5' */
extern MONPRM volatile float32 VTQF_TqRateIncTgtMin_Nmps;/* '<S1453>/MinMax4' */
extern MONPRM volatile float32 VTQF_TqRateLimDec_Nmps;/* '<S1452>/MinMax3' */
extern MONPRM volatile boolean VTQF_TqRateLimEndg_flg;/* '<S1451>/Logical Operator9' */
extern MONPRM volatile float32 VTQF_TqRateLimInc_Nmps;/* '<S1453>/MinMax2' */
extern MONPRM volatile float32 VTQF_TqRawChgRate_Nmps;/* '<S1471>/Switch' */
extern MONPRM volatile float32 VTQF_WhlDrgMaxTqZX_Nm;/* '<S1470>/Switch1' */
extern MONPRM volatile float32 VTQF_WhlDrvMaxTqZX_Nm;/* '<S1470>/Switch7' */
extern MONPRM volatile boolean VTQR_ASDEnbl_flg;/* '<S1475>/Logical Operator14' */
extern MONPRM volatile float32 VTQR_ASDSpdFltHi_rpm;/* '<S1483>/Switch' */
extern MONPRM volatile float32 VTQR_ASDSpdOscRaw_rpm;/* '<S1479>/Add1' */
extern MONPRM volatile float32 VTQR_ASDSpdOsc_rpm;/* '<S1481>/Multiport Switch' */
extern MONPRM volatile float32 VTQR_ASDTqReqRaw_Nm;/* '<S1487>/MinMax5' */
extern MONPRM volatile float32 VTQR_ASDTqReq_Nm;/* '<S1480>/Switch3' */
extern MONPRM volatile boolean VTQR_MotDampngEnbl_flg;/* '<S1475>/Logical Operator1' */
extern MONPRM volatile float32 VTQR_MotDampngLmt_Nm;/* '<S1495>/MinMax5' */
extern MONPRM volatile EnumMotorDirReq VTQR_MotorDirReq_enum;/* '<S1476>/Switch4' */
extern MONPRM volatile EnumMotorModeReq VTQR_MotorModeReq_enum;/* '<S1473>/Signal Conversion15' */
extern MONPRM volatile float32 VTQR_MotorSpdReq_rpm;/* '<S1473>/Signal Conversion1' */
extern MONPRM volatile boolean VTQR_MotorStdby_flg;/* '<S1477>/Logical Operator1' */
extern MONPRM volatile float32 VTQR_MotorTqReq_Nm;/* '<S1473>/Signal Conversion2' */
extern MONPRM volatile float32 VTZX_AZDecRate_Nmps;/* '<S1511>/1-D Lookup Table4' */
extern MONPRM volatile float32 VTZX_AZIncRate_Nmps;/* '<S1511>/1-D Lookup Table3' */
extern MONPRM volatile float32 VTZX_BZDecRate_Nmps;/* '<S1511>/1-D Lookup Table2' */
extern MONPRM volatile float32 VTZX_BZIncRate_Nmps;/* '<S1511>/1-D Lookup Table1' */
extern MONPRM volatile boolean VTZX_BypZX_flg;/* '<S1515>/Logical Operator1' */
extern MONPRM volatile boolean VTZX_ClkActv_flg;/* '<S1514>/Switch4' */
extern MONPRM volatile float32 VTZX_ClkZXTm_s;/* '<S1507>/Switch1' */
extern MONPRM volatile float32 VTZX_MotorTqReqPrdt_Nm;/* '<S1527>/MinMax5' */
extern MONPRM volatile float32 VTZX_MotorTqReqZX_Nm;/* '<S1512>/TqZXSt' */
extern MONPRM volatile float32 VTZX_MotorTqReq_Nm;/* '<S1507>/Switch6' */
extern MONPRM volatile boolean VTZX_TqInc_flg;/* '<S1521>/Switch4' */
extern MONPRM volatile boolean VTZX_TqRateLimRamp_flg;/* '<S1528>/Switch4' */
extern MONPRM volatile EnumTZXStat VTZX_TqZXSt_enum;/* '<S1512>/Data Type Conversion1' */
extern MONPRM volatile float32 VTZX_ZeroTqHldDec_Nm;/* '<S1512>/TqZXSt' */
extern MONPRM volatile float32 VTZX_ZeroTqHldInc_Nm;/* '<S1512>/TqZXSt' */
extern MONPRM volatile float32 VTZX_ZeroTqOfstDec_Nm;/* '<S1511>/Switch3' */
extern MONPRM volatile float32 VTZX_ZeroTqOfstInc_Nm;/* '<S1511>/Switch2' */
extern MONPRM volatile float32 VTZX_ZeroTqOfst_Nm;/* '<S1511>/Switch4' */
extern MONPRM volatile float32 VTZX_ZeroXTm_s;/* '<S1511>/Switch8' */
extern MONPRM volatile float32 VVSO_ALatSnsr_mps2;/* '<S1131>/Switch1' */
extern MONPRM volatile float32 VVSO_ALgtSnsr_mps2;/* '<S1130>/Switch1' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr1_mpkm;/* '<S1192>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr2_mpkm;/* '<S1192>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr3_mpkm;/* '<S1192>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr4_mpkm;/* '<S1192>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr5_mpkm;/* '<S1192>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr_mpkm;/* '<S1192>/Add3' */
extern MONPRM volatile float32 VVSO_DrvDist_m;/* '<S1205>/Switch1' */
extern MONPRM volatile boolean VVSO_RSEBrkPresrConf_flg;/* '<S1177>/Relational Operator2' */
extern MONPRM volatile boolean VVSO_RSESigConf_flg;/* '<S1163>/Logical Operator3' */
extern MONPRM volatile boolean VVSO_RSEVehSpdConf_flg;/* '<S1179>/Logical Operator2' */
extern MONPRM volatile boolean VVSO_RSEWhlSlipConf_flg;/* '<S1180>/Logical Operator2' */
extern MONPRM volatile boolean VVSO_RSEYawRateConf_flg;/* '<S1181>/Logical Operator' */
extern MONPRM volatile float32 VVSO_RoadSlopCalcRaw_pct;/* '<S1161>/Product19' */
extern MONPRM volatile boolean VVSO_RoadSlopEstVld_flg;/* '<S1160>/Logical Operator1' */
extern MONPRM volatile float32 VVSO_RoadSlopEst_pct;/* '<S1160>/Switch2' */
extern MONPRM volatile float32 VVSO_RoadSlopTqEst_Nm;/* '<S1176>/MinMax5' */
extern MONPRM volatile float32 VVSO_VehDrvResistTq_Nm;/* '<S1162>/Switch5' */
extern MONPRM volatile boolean VVSO_VehMassConf_flg;/* '<S1208>/Logical Operator4' */
extern MONPRM volatile uint8 VVSO_VehMassDistb_enum;/* '<S1208>/Signal Conversion' */
extern MONPRM volatile float32 VVSO_VehMassEst_kg;/* '<S1211>/Switch' */
extern MONPRM volatile float32 VVSO_VehSpd_mps;/* '<S1208>/Gain3' */
extern MONPRM volatile float32 VVSO_WhlAcceltnFL_mps2;/* '<S1143>/Divide' */
extern MONPRM volatile float32 VVSO_WhlAcceltnFR_mps2;/* '<S1144>/Divide' */
extern MONPRM volatile float32 VVSO_WhlAcceltnRL_mps2;/* '<S1145>/Divide' */
extern MONPRM volatile float32 VVSO_WhlAcceltnRR_mps2;/* '<S1146>/Divide' */
extern MONPRM volatile boolean VVSO_WhlDistErrHld_flg;/* '<S1196>/OR' */
extern MONPRM volatile float32 VVSO_WhlLgtFrc_N;/* '<S1213>/Add' */
extern MONPRM volatile EnumXWhlDistErrRefSt VVSO_XWhlDistErrRefStat_enum;/* '<S1192>/Signal Conversion2' */
extern MONPRM volatile float32 VVSO_XWhlDistErrRef_mpkm;/* '<S1192>/Signal Conversion1' */
extern MONPRM volatile float32 VVSO_XWhlDistErr_m;/* '<S1205>/Switch4' */
extern MONPRM volatile float32 VVSO_YawRateBas_degps;/* '<S1137>/Switch' */
extern MONPRM volatile float32 VVSO_YawRateDer_radps2;/* '<S1132>/Add6' */
extern MONPRM volatile float32 VVSO_YawRateFilt_radps;/* '<S1136>/Switch' */
extern MONPRM volatile boolean VVSO_iTPMSAvail_flg;/* '<S1196>/Logical Operator' */
extern MONPRM volatile EnumiTPMSSt VVSO_iTPMSState_enum;/* '<S1192>/Signal Conversion' */
extern MONPRM volatile boolean VVSO_iTPMSWrng_flg;/* '<S1192>/Signal Conversion3' */
extern MONPRM volatile boolean VVTM_BrkPedReld_flg;/* '<S1553>/Logical Operator3' */
extern MONPRM volatile uint8 VVTM_DrvMotorSta_enum;/* '<S1560>/DriveMotorState' */
extern MONPRM volatile boolean VVTM_ESPIntvActv_flg;/* '<S1553>/Logical Operator4' */
extern MONPRM volatile float32 VVTM_MotorActPwr_kW;/* '<S1567>/Switch2' */
extern MONPRM volatile float32 VVTM_MotorSpd_rpm;/* '<S1555>/Switch' */
extern MONPRM volatile boolean VVTM_PCUFailSta_flg;/* '<S1560>/Logical Operator2' */
extern MONPRM volatile boolean VVTM_RegenReqBrkLampOn_flg;/* '<S1565>/Switch1' */
extern MONPRM volatile float32 VVTM_RsrvPwr_kW;/* '<S1562>/MinMax4' */
extern MONPRM volatile float32 VVTM_RsrvRecupPwr_kW;/* '<S1562>/MinMax1' */
extern MONPRM volatile float32 VVTM_VehAcceltn_mps2;/* '<S1558>/Switch' */
extern MONPRM volatile uint8 VVTM_VehActGrPstn_enum;/* '<S1553>/Switch1' */
extern MONPRM volatile float32 VVTM_VehSpd_kph;/* '<S1554>/Switch' */

#endif                                 /* RTW_HEADER_monPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
