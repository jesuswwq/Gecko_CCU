/*
 * File: monPrmsVcu.c
 *
 * Code generated for Simulink model 'AppSwcVcu'.
 *
 * Model version                  : 9.704
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Dec 25 17:16:37 2024
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
MONPRM volatile boolean BSW_RTCWakeup_flg = false;/* '<S284>/Switch4' */

/* RTC唤醒标志位_versteckt */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Day = ((uint8)0U);/* '<S978>/Data Type Conversion45' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Hour = ((uint8)0U);/* '<S978>/Data Type Conversion1' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Min = ((uint8)0U);/* '<S978>/Data Type Conversion2' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Month = ((uint8)0U);/* '<S978>/Data Type Conversion34' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Sec = ((uint8)0U);/* '<S978>/Switch2' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Year = ((uint8)0U);/* '<S978>/Data Type Conversion33' */
MONPRM volatile boolean VBSW_ECURst_flg = false;/* '<S7>/Relational Operator3' */
MONPRM volatile boolean VBSW_F1B1PwrOffReq_flg = false;/* '<S12>/Chart' */

/* F1B1请求下高压 */
MONPRM volatile boolean VBSW_F1B1PwrOnReq_flg = false;/* '<S11>/Chart' */

/* F1B1请求上高压 */
MONPRM volatile uint16 VBSW_RTCWupRmningT_min = ((uint16)0U);/* '<S7>/Data Type Conversion1' */

/* RTC唤醒剩余时间 */
MONPRM volatile uint8 VBSW_RoutineF1B1_enum = ((uint8)0U);/* '<S7>/Selector' */

/* F1B1例程控制 */
MONPRM volatile uint8 VBSW_WakeupReasn_enum = ((uint8)0U);/* '<S7>/EcuWakeupReasn' */
MONPRM volatile float32 VCPT_MotorDrgMaxTq_Nm = 0.0F;/* '<S550>/MinMax6' */
MONPRM volatile float32 VCPT_MotorDrvMaxTq_Nm = 0.0F;/* '<S550>/MinMax7' */
MONPRM volatile float32 VCPT_MotorGenMaxTq_Nm = 0.0F;/* '<S562>/Switch1' */
MONPRM volatile float32 VCPT_MotorMotMaxTq_Nm = 0.0F;/* '<S561>/Switch1' */
MONPRM volatile boolean VCPT_MotorSpdRvrs_flg = false;/* '<S550>/Switch3' */
MONPRM volatile float32 VCPT_MotorSpd_rpm = 0.0F;/* '<S556>/Switch' */
MONPRM volatile float32 VCPT_WhlDrgMaxTq_Nm = 0.0F;/* '<S550>/MinMax1' */
MONPRM volatile float32 VCPT_WhlDrvMaxTq_Nm = 0.0F;/* '<S550>/MinMax8' */
MONPRM volatile boolean VDAC_ACCAvail_flg = false;/* '<S571>/Logical Operator9' */
MONPRM volatile float32 VDAC_ACCDeltaAcceltn_mps2 = 0.0F;/* '<S578>/Add5' */
MONPRM volatile float32 VDAC_ACCDsrdTqFF_Nm = 0.0F;/* '<S578>/Add3' */
MONPRM volatile float32 VDAC_ACCDsrdTqI_N = 0.0F;/* '<S578>/Saturation1' */
MONPRM volatile float32 VDAC_ACCDsrdTqPID_Nm = 0.0F;/* '<S578>/Product6' */
MONPRM volatile float32 VDAC_ACCDsrdTqP_N = 0.0F;/* '<S578>/Product3' */
MONPRM volatile boolean VDAC_ACCEnbl_flg = false;/* '<S571>/Logical Operator3' */
MONPRM volatile boolean VDAC_ACCOvrd_flg = false;/* '<S572>/Logical Operator22' */
MONPRM volatile uint8 VDAC_ACCStat_enum = ((uint8)0U);/* '<S573>/Switch1' */
MONPRM volatile float32 VDAC_ACCTqReqWhl_Nm = 0.0F;/* '<S574>/Merge3' */
MONPRM volatile boolean VDAC_CCActv2Stby_flg = false;/* '<S618>/Logical Operator15' */
MONPRM volatile boolean VDAC_CCActvBascCond_flg = false;/* '<S618>/Logical Operator1' */
MONPRM volatile float32 VDAC_CCDeltaAcceltn_mps2 = 0.0F;/* '<S605>/Add3' */
MONPRM volatile float32 VDAC_CCDsrdAcceltnRaw_mps2 = 0.0F;/* '<S598>/Saturation1' */
MONPRM volatile float32 VDAC_CCDsrdAcceltn_mps2 = 0.0F;/* '<S596>/Merge1' */
MONPRM volatile float32 VDAC_CCDsrdTqFF_N = 0.0F;/* '<S604>/Add3' */
MONPRM volatile float32 VDAC_CCDsrdTqI_N = 0.0F;/* '<S605>/Saturation1' */
MONPRM volatile float32 VDAC_CCDsrdTqPID_N = 0.0F;/* '<S605>/Add2' */
MONPRM volatile float32 VDAC_CCDsrdTqP_N = 0.0F;/* '<S605>/Product2' */
MONPRM volatile boolean VDAC_CCEnbl_flg = false;/* '<S619>/Logical Operator2' */
MONPRM volatile uint16 VDAC_CCNoActvCond_enum = ((uint16)0U);/* '<S621>/Add' */
MONPRM volatile boolean VDAC_CCOvrd_flg = false;/* '<S592>/Logical Operator22' */
MONPRM volatile uint16 VDAC_CCQuitCond_enum = ((uint16)0U);/* '<S622>/Add' */
MONPRM volatile float32 VDAC_CCSpdUnstabTm_s = 0.0F;/* '<S634>/Saturation' */
MONPRM volatile boolean VDAC_CCSpdUnstab_flg = false;/* '<S634>/Relational Operator8' */
MONPRM volatile EnumCCState VDAC_CCSt_enum = EnumCCState_Off;/* '<S593>/CC_State_Chart' */
MONPRM volatile boolean VDAC_CCStby2Actv_flg = false;/* '<S618>/Logical Operator9' */
MONPRM volatile float32 VDAC_CCTgtSpdCtrl_kph = 0.0F;/* '<S643>/Switch1' */
MONPRM volatile uint8 VDAC_CCTgtSpdHU_kph = ((uint8)0U);/* '<S594>/TgtSpdCalc' */
MONPRM volatile EnumCCTgtSpdSt VDAC_CCTgtSpdSt_enum = EnumCCTgtSpdSt_Reset;/* '<S594>/TgtSpdCalc' */
MONPRM volatile float32 VDAC_CCTgtSpd_kph = 0.0F;/* '<S594>/MinMax7' */
MONPRM volatile float32 VDAC_CCTqReqWhl_Nm = 0.0F;/* '<S597>/Merge2' */
MONPRM volatile float32 VDAC_CCVehSpdNonDrvn_kph = 0.0F;/* '<S600>/Switch' */
MONPRM volatile boolean VDAC_CruzCncl_flg = false;/* '<S659>/Chart' */
MONPRM volatile EnumCruiseStatus VDAC_CruzCtrlStat_enum =
  EnumCruiseStatus_NormOff;            /* '<S592>/Switch2' */
MONPRM volatile boolean VDAC_CruzCtrlSwVld_flg = false;/* '<S595>/Signal Conversion1' */
MONPRM volatile boolean VDAC_CruzOn_flg = true;/* '<S595>/Signal Conversion2' */
MONPRM volatile boolean VDAC_CruzRsmActv_flg = false;/* '<S656>/Switch4' */
MONPRM volatile boolean VDAC_CruzSetActv_flg = false;/* '<S654>/Switch4' */
MONPRM volatile boolean VDAC_CruzSpdDecActv_flg = false;/* '<S655>/Switch4' */
MONPRM volatile boolean VDAC_CruzSpdIncActv_flg = false;/* '<S657>/Switch4' */
MONPRM volatile float32 VDAC_DrvAsstTqSplitEHB_Nm = 0.0F;/* '<S567>/MinMax2' */
MONPRM volatile float32 VDAC_DrvAsstTqSplitINV_Nm = 0.0F;/* '<S567>/Add1' */
MONPRM volatile uint8 VDAC_DrvAsstTqSts_enum = ((uint8)0U);/* '<S567>/Switch1' */
MONPRM volatile float32 VDAC_DrvAsstTqTgt_Nm = 0.0F;/* '<S567>/Switch2' */
MONPRM volatile boolean VDAC_EnblEHBBrkRun_flg = false;/* '<S690>/Switch4' */
MONPRM volatile boolean VDAC_HDCActv2Idle_flg = false;/* '<S666>/Logical Operator11' */
MONPRM volatile boolean VDAC_HDCActv2Stdby_flg = false;/* '<S666>/Logical Operator8' */
MONPRM volatile float32 VDAC_HDCDeltaAcceltn_mps2 = 0.0F;/* '<S671>/Add5' */
MONPRM volatile float32 VDAC_HDCDsrdTqFF_Nm = 0.0F;/* '<S671>/Add3' */
MONPRM volatile float32 VDAC_HDCDsrdTqI_N = 0.0F;/* '<S671>/Saturation1' */
MONPRM volatile float32 VDAC_HDCDsrdTqPID_Nm = 0.0F;/* '<S671>/Product6' */
MONPRM volatile float32 VDAC_HDCDsrdTqP_N = 0.0F;/* '<S671>/Product3' */
MONPRM volatile boolean VDAC_HDCIdle2Stdby_flg = false;/* '<S666>/Logical Operator2' */
MONPRM volatile EnumHDCState VDAC_HDCSt_enum = EnumHDCState_Idle;/* '<S565>/HDC_State_Chart' */
MONPRM volatile boolean VDAC_HDCStdby2Actv_flg = false;/* '<S666>/Logical Operator13' */
MONPRM volatile boolean VDAC_HDCStdby2Idle_flg = false;/* '<S666>/Logical Operator3' */
MONPRM volatile float32 VDAC_HDCTgtAcceltn_mps2 = 0.0F;/* '<S663>/Merge1' */
MONPRM volatile float32 VDAC_HDCTgtSpd_kph = 0.0F;/* '<S565>/HDC_State_Chart' */
MONPRM volatile float32 VDAC_HDCTqReqWhl_Nm = 0.0F;/* '<S663>/Merge2' */
MONPRM volatile uint8 VDAC_HDCVehSpdHU_kph = ((uint8)0U);/* '<S664>/Switch1' */
MONPRM volatile float32 VDAC_MstrCylPresrReq_bar = 0.0F;/* '<S567>/Switch13' */
MONPRM volatile uint8 VDAC_VehSpdHU_kph = ((uint8)0U);/* '<S645>/Switch1' */
MONPRM volatile uint8 VDAC_VirtAccPedPstnSta_enum = ((uint8)0U);/* '<S567>/Switch11' */
MONPRM volatile float32 VDAC_VirtAccPedPstn_pct = 0.0F;/* '<S567>/Switch8' */
MONPRM volatile float32 VDAC_VirtAccelPedPstnRaw_pct = 0.0F;/* '<S567>/Switch9' */
MONPRM volatile float32 VDAC_VirtPedPstn_pct = 0.0F;/* '<S567>/Switch4' */
MONPRM volatile uint8 VDAG_ACCMHVILFltSt_enum = ((uint8)0U);/* '<S1448>/FltStDeb' */

/* 压缩机高压互锁故障状态 */
MONPRM volatile uint8 VDAG_ACChrgStFailFltSt_enum = ((uint8)0U);/* '<S1281>/FltStDeb' */

/* ACChargeStateFail故障状态 */
MONPRM volatile uint8 VDAG_ACDchaBMSPwrLoFltSt_enum = ((uint8)0U);/* '<S1287>/FltStDeb' */

/* AC放电BMS功率低故障状态 */
MONPRM volatile uint8 VDAG_ACDchaBMSSOCLoFltSt_enum = ((uint8)0U);/* '<S1286>/FltStDeb' */

/* AC放电BMSSOC低故障状态 */
MONPRM volatile uint8 VDAG_ACDchaOverPwrFltSt_enum = ((uint8)0U);/* '<S1280>/FltStDeb' */

/* AC放电功率超限故障 */
MONPRM volatile uint8 VDAG_ACSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S1011>/FltStDeb' */

/* ACSCmd超时故障状态 */
MONPRM volatile uint8 VDAG_AccPed1ShtBattFltSt_enum = ((uint8)0U);/* '<S1422>/FltStDeb' */

/* 加速踏板1路短电源故障状态 */
MONPRM volatile uint8 VDAG_AccPed1ShtGndFltSt_enum = ((uint8)0U);/* '<S1419>/FltStDeb' */

/* 加速踏板1路短地故障状态 */
MONPRM volatile uint8 VDAG_AccPed1SuplyShtCircFltSt_enum = ((uint8)0U);/* '<S1420>/FltStDeb' */

/* 加速踏板1路供电短路故障状态 */
MONPRM volatile uint8 VDAG_AccPed2ShtBattFltSt_enum = ((uint8)0U);/* '<S1415>/FltStDeb' */

/* 加速踏板2路短电源故障状态 */
MONPRM volatile uint8 VDAG_AccPed2ShtGndFltSt_enum = ((uint8)0U);/* '<S1423>/FltStDeb' */

/* 加速踏板2路短地故障状态 */
MONPRM volatile uint8 VDAG_AccPed2SuplyShtCircFltSt_enum = ((uint8)0U);/* '<S1421>/FltStDeb' */

/* 加速踏板2路供电短路故障状态 */
MONPRM volatile uint8 VDAG_AccPedBothFailFltSt_enum = ((uint8)0U);/* '<S1417>/FltStDeb' */

/* 加速踏板双路失效故障状态 */
MONPRM volatile uint8 VDAG_AccPedCrsChkFltSt_enum = ((uint8)0U);/* '<S1416>/FltStDeb' */

/* 加速踏板相互校验故障状态 */
MONPRM volatile uint8 VDAG_BMSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S1005>/FltStDeb' */

/* BMS继电器指令响应超时故障状态 */
MONPRM volatile uint8 VDAG_BMSEmgcySdnFltSt_enum = ((uint8)0U);/* '<S1016>/FltStDeb' */

/* BMS紧急下电故障状态 */
MONPRM volatile uint8 VDAG_BMSSOCLoFltSt_enum = ((uint8)0U);/* '<S1015>/FltStDeb' */

/* BMSSOC低故障状态 */
MONPRM volatile uint8 VDAG_BMSSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S1012>/FltStDeb' */

/* BMSFailLevel1故障状态 */
MONPRM volatile uint8 VDAG_BMSSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S1013>/FltStDeb' */

/* BMSFailLevel2故障状态 */
MONPRM volatile uint8 VDAG_BMSSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S1014>/FltStDeb' */

/* BMSFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_BMSUndrVoltFltSt_enum = ((uint8)0U);/* '<S1017>/FltStDeb' */

/* BMSPack欠压故障状态 */
MONPRM volatile uint8 VDAG_BrkPedShtBattFltSt_enum = ((uint8)0U);/* '<S1445>/FltStDeb' */

/* 制动踏板短电源故障状态 */
MONPRM volatile uint8 VDAG_BrkPedShtGndFltSt_enum = ((uint8)0U);/* '<S1443>/FltStDeb' */

/* 制动踏板短地故障状态 */
MONPRM volatile uint8 VDAG_BrkSwCrsChkCnt_cnt = ((uint8)0U);/* '<S1435>/Data Type Conversion' */

/* 制动开关相互校验错误计数 */
MONPRM volatile uint8 VDAG_BrkSwCrsChkFltSt_enum = ((uint8)0U);/* '<S1444>/FltStDeb' */

/* 制动开关相互校验故障状态 */
MONPRM volatile uint8 VDAG_CellUndrVoltFltSt_enum = ((uint8)0U);/* '<S1018>/FltStDeb' */

/* BMSCell欠压故障状态 */
MONPRM volatile uint8 VDAG_DCCCmdTmOutFltSt_enum = ((uint8)0U);/* '<S1179>/FltStDeb' */

/* DCDC模式指令响应超时故障状态 */
MONPRM volatile uint8 VDAG_DCCInVoltLoFltSt_enum = ((uint8)0U);/* '<S1180>/FltStDeb' */

/* DCDC输入电压低故障状态 */
MONPRM volatile uint8 VDAG_DCCModeFltFltSt_enum = ((uint8)0U);/* '<S1178>/FltStDeb' */

/* DCDCModeFault故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S1174>/FltStDeb' */

/* DCDCFailLevel1故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S1175>/FltStDeb' */

/* DCDCFailLevel2故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S1176>/FltStDeb' */

/* DCDCFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl4FltSt_enum = ((uint8)0U);/* '<S1177>/FltStDeb' */

/* DCDCFailLevel4故障状态 */
MONPRM volatile uint8 VDAG_DCSChrgReqFltSt_enum = ((uint8)0U);/* '<S1009>/FltStDeb' */

/* DCSChargeRequest故障状态 */
MONPRM volatile uint8 VDAG_DCSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S1019>/FltStDeb' */

/* DCSCmd超时故障状态 */
MONPRM volatile uint8 VDAG_DCSFailStaFltSt_enum = ((uint8)0U);/* '<S1007>/FltStDeb' */

/* DCSFailState故障状态 */
MONPRM volatile uint8 VDAG_DCSInletConnectFltSt_enum = ((uint8)0U);/* '<S1008>/FltStDeb' */

/* DCS插枪故障状态 */
MONPRM volatile uint8 VDAG_DCSModeFailFltSt_enum = ((uint8)0U);/* '<S1010>/FltStDeb' */

/* DCSModeFail故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl1FltSt_enum = ((uint8)0U);/* '<S1353>/FltStDeb' */

/* EHB1级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl2FltSt_enum = ((uint8)0U);/* '<S1354>/FltStDeb' */

/* EHB2级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl3FltSt_enum = ((uint8)0U);/* '<S1355>/FltStDeb' */

/* EHB3级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl4FltSt_enum = ((uint8)0U);/* '<S1347>/FltStDeb' */

/* EHB4级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl5FltSt_enum = ((uint8)0U);/* '<S1356>/FltStDeb' */

/* EHB5级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl1FltSt_enum = ((uint8)0U);/* '<S1358>/FltStDeb' */

/* ESC1级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl2FltSt_enum = ((uint8)0U);/* '<S1348>/FltStDeb' */

/* ESC2级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl3FltSt_enum = ((uint8)0U);/* '<S1349>/FltStDeb' */

/* ESC3级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl4FltSt_enum = ((uint8)0U);/* '<S1357>/FltStDeb' */

/* ESC4级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl5FltSt_enum = ((uint8)0U);/* '<S1350>/FltStDeb' */

/* ESC5级故障状态 */
MONPRM volatile uint8 VDAG_ESCVehSpdInvldFltSt_enum = ((uint8)0U);/* '<S1352>/FltStDeb' */

/* 车速失效故障状态 */
MONPRM volatile boolean VDAG_EmgcyShtdwn_flg = false;/* '<S969>/Switch30' */
MONPRM volatile uint16 VDAG_ErrCode_enum = ((uint16)0U);/* '<S967>/Err_State' */
MONPRM volatile boolean VDAG_FanFullSpdOn_flg = false;/* '<S969>/Switch3' */
MONPRM volatile boolean VDAG_FbdACC_flg = false;/* '<S969>/Switch28' */
MONPRM volatile boolean VDAG_FbdACChrg_flg = false;/* '<S969>/Switch32' */
MONPRM volatile boolean VDAG_FbdACDcha_flg = false;/* '<S969>/Switch34' */
MONPRM volatile boolean VDAG_FbdAC_flg = false;/* '<S969>/Switch35' */
MONPRM volatile boolean VDAG_FbdCC_flg = false;/* '<S969>/Switch26' */
MONPRM volatile boolean VDAG_FbdDCChrg_flg = false;/* '<S969>/Switch33' */
MONPRM volatile boolean VDAG_FbdDCDC_flg = false;/* '<S969>/Switch31' */
MONPRM volatile boolean VDAG_FbdDRGr_flg = false;/* '<S969>/Switch25' */
MONPRM volatile boolean VDAG_FbdDrvTq_flg = false;/* '<S969>/Switch23' */
MONPRM volatile boolean VDAG_FbdHV_flg = false;/* '<S969>/Switch29' */
MONPRM volatile boolean VDAG_FbdLSP_flg = false;/* '<S969>/Switch27' */
MONPRM volatile boolean VDAG_FltLampOn_flg = false;/* '<S969>/Switch36' */
MONPRM volatile uint8 VDAG_FltLvl_enum = ((uint8)0U);/* '<S969>/MinMax' */
MONPRM volatile uint8 VDAG_FrstHVILVoltHiFltSt_enum = ((uint8)0U);/* '<S1447>/FltStDeb' */

/* 主要高压互锁电压高故障状态 */
MONPRM volatile uint8 VDAG_FrstHVILVoltLoFltSt_enum = ((uint8)0U);/* '<S1446>/FltStDeb' */

/* 主要高压互锁电压低故障状态 */
MONPRM volatile uint8 VDAG_GearShftInvldFltSt_enum = ((uint8)0U);/* '<S1351>/FltStDeb' */

/* 换挡输入失效故障状态 */
MONPRM volatile uint8 VDAG_HVIsoResistLoFltSt_enum = ((uint8)0U);/* '<S1006>/FltStDeb' */

/* 高压电池绝缘故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl1FltSt_enum = ((uint8)0U);/* '<S1247>/FltStDeb' */

/* INVFaultLevel1故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl2FltSt_enum = ((uint8)0U);/* '<S1248>/FltStDeb' */

/* INVFaultLevel2故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl3FltSt_enum = ((uint8)0U);/* '<S1249>/FltStDeb' */

/* INVFaultLevel3故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl4FltSt_enum = ((uint8)0U);/* '<S1250>/FltStDeb' */

/* INVFaultLevel4故障状态 */
MONPRM volatile uint8 VDAG_INVInVoltLoFltSt_enum = ((uint8)0U);/* '<S1181>/FltStDeb' */

/* INV输入电压低故障状态 */
MONPRM volatile uint8 VDAG_INVRunCmdRespFltSt_enum = ((uint8)0U);/* '<S1251>/FltStDeb' */

/* INVRun指令响应超时故障状态 */
MONPRM volatile boolean VDAG_LVBatLampOn_flg = false;/* '<S969>/Switch1' */
MONPRM volatile uint8 VDAG_LVBattSOCLoFltSt_enum = ((uint8)0U);/* '<S1395>/FltStDeb' */

/* 蓄电池SOC低的故障状态 */
MONPRM volatile uint8 VDAG_LVBattSOHLoFltSt_enum = ((uint8)0U);/* '<S1391>/FltStDeb' */

/* 蓄电池SOH低的故障状态 */
MONPRM volatile uint8 VDAG_LVBattTempHiFltSt_enum = ((uint8)0U);/* '<S1392>/FltStDeb' */

/* 蓄电池过温故障状态 */
MONPRM volatile uint8 VDAG_LVBattVoltHiFltSt_enum = ((uint8)0U);/* '<S1394>/FltStDeb' */

/* 蓄电池电压高故障状态 */
MONPRM volatile uint8 VDAG_LVBattVoltLoFltSt_enum = ((uint8)0U);/* '<S1393>/FltStDeb' */

/* 蓄电池电压低故障状态 */
MONPRM volatile boolean VDAG_LimpHome_flg = false;/* '<S969>/Switch2' */
MONPRM volatile boolean VDAG_LmtDrvTq_flg = false;/* '<S969>/Switch24' */
MONPRM volatile uint8 VDAG_OBCChrgReqFltSt_enum = ((uint8)0U);/* '<S1285>/FltStDeb' */

/* OBCChargeRequest故障状态 */
MONPRM volatile uint8 VDAG_OBCConnectTmOutFltSt_enum = ((uint8)0U);/* '<S1283>/FltStDeb' */

/* OBC连接超时故障状态 */
MONPRM volatile uint8 VDAG_OBCInletConnectFltSt_enum = ((uint8)0U);/* '<S1288>/FltStDeb' */

/* OBC插枪故障状态 */
MONPRM volatile uint8 VDAG_OBCModeMsmtchFltSt_enum = ((uint8)0U);/* '<S1282>/FltStDeb' */

/* OBC模式不匹配故障状态 */
MONPRM volatile uint8 VDAG_OBCS2StatFltSt_enum = ((uint8)0U);/* '<S1284>/FltStDeb' */

/* OBCS2连接超时故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S1289>/FltStDeb' */

/* OBCFailLevel1故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S1290>/FltStDeb' */

/* OBCFailLevel2故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S1291>/FltStDeb' */

/* OBCFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl4FltSt_enum = ((uint8)0U);/* '<S1279>/FltStDeb' */

/* OBCFailLevel4故障状态 */
MONPRM volatile uint8 VDAG_SecdHVILVoltHiFltSt_enum = ((uint8)0U);/* '<S1450>/FltStDeb' */

/* 次要高压互锁电压高故障状态 */
MONPRM volatile uint8 VDAG_SecdHVILVoltLoFltSt_enum = ((uint8)0U);/* '<S1449>/FltStDeb' */

/* 次要高压互锁电压低故障状态 */
MONPRM volatile uint8 VDAG_SysPwrModeInvldFltSt_enum = ((uint8)0U);/* '<S1345>/FltStDeb' */

/* PowerMode失效故障状态 */
MONPRM volatile uint8 VDAG_TMSFailLvl3FltSt_enum = ((uint8)0U);/* '<S1346>/FltStDeb' */

/* TMSRFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_VehCrashFltSt_enum = ((uint8)0U);/* '<S1414>/FltStDeb' */

/* 碰撞故障状态 */
MONPRM volatile boolean VDAG_WakeUp_flg = false;/* '<S968>/Logical Operator9' */

/* 硬线唤醒或者IBSLIN唤醒标志 */
MONPRM volatile uint8 VDAG_WaterTempAbvThrFltSt_enum = ((uint8)0U);/* '<S1470>/FltStDeb' */

/* 冷却水温过高故障状态 */
MONPRM volatile uint8 VDAG_WaterTempBlwThrFltSt_enum = ((uint8)0U);/* '<S1469>/FltStDeb' */

/* 冷却水温过低故障状态 */
MONPRM volatile float32 VDSA_AcceltnIdxAvg_pct = 0.0F;/* '<S71>/AvgAcceltnIdx' */
MONPRM volatile float32 VDSA_AcceltnIdxRaw_pct = 0.0F;/* '<S71>/Saturation1' */
MONPRM volatile float32 VDSA_BrkPedPstnAvg_pct = 0.0F;/* '<S71>/AvgBrkPedPstn' */
MONPRM volatile float32 VDSA_DrvSprtIdx_pct = 0.0F;/* '<S71>/Saturation2' */
MONPRM volatile boolean VDSA_SprtIdxHldAcc_flg = false;/* '<S71>/Logical Operator3' */
MONPRM volatile boolean VDSA_SprtIdxHldBrk_flg = false;/* '<S71>/Logical Operator6' */
MONPRM volatile float32 VDSA_TqCalcAcceltn_mps2 = 0.0F;/* '<S71>/Divide1' */
MONPRM volatile boolean VEMS_ACCMOprtCmd_flg = false;/* '<S906>/ACCMEnble' */

/* 使能ACCM */
MONPRM volatile float32 VEMS_AccPwrRaw_kW = 0.0F;/* '<S907>/MinMax4' */
MONPRM volatile float32 VEMS_CellTempSyn_C = 0.0F;/* '<S963>/Switch1' */
MONPRM volatile float32 VEMS_CellUndrVoltDrtFac_c = 0.0F;/* '<S904>/Saturation3' */
MONPRM volatile float32 VEMS_ChrgCurFbKi_A = 0.0F;/* '<S960>/Saturation' */
MONPRM volatile float32 VEMS_ChrgCurFbKp_A = 0.0F;/* '<S960>/Product2' */
MONPRM volatile float32 VEMS_ChrgCurFb_A = 0.0F;/* '<S960>/Saturation2' */
MONPRM volatile float32 VEMS_ChrgOvrshtPwr_kW = 0.0F;/* '<S903>/Add1' */
MONPRM volatile float32 VEMS_ChrgPwrFbKi_kW = 0.0F;/* '<S922>/Saturation' */
MONPRM volatile float32 VEMS_ChrgPwrFbKp_kW = 0.0F;/* '<S922>/Product2' */
MONPRM volatile float32 VEMS_ChrgPwrFb_kW = 0.0F;/* '<S903>/Merge' */
MONPRM volatile float32 VEMS_DchaCurFbKi_A = 0.0F;/* '<S961>/Saturation' */
MONPRM volatile float32 VEMS_DchaCurFbKp_A = 0.0F;/* '<S961>/Product2' */
MONPRM volatile float32 VEMS_DchaCurFb_A = 0.0F;/* '<S961>/Saturation2' */
MONPRM volatile float32 VEMS_DchaOvrshtPwr_kW = 0.0F;/* '<S905>/Add1' */
MONPRM volatile float32 VEMS_DchaPwrFbKi_kW = 0.0F;/* '<S940>/Saturation' */
MONPRM volatile float32 VEMS_DchaPwrFbKp_kW = 0.0F;/* '<S940>/Product2' */
MONPRM volatile float32 VEMS_DchaPwrFb_kW = 0.0F;/* '<S905>/Merge' */
MONPRM volatile float32 VEMS_HVBatPwrAct_kW = 0.0F;/* '<S907>/Gain1' */
MONPRM volatile float32 VEMS_MaxChrgCur_A = 0.0F;/* '<S902>/Saturation4' */
MONPRM volatile float32 VEMS_MaxChrgPwr2MotRaw_kW = 0.0F;/* '<S902>/Add7' */
MONPRM volatile float32 VEMS_MaxChrgPwr2Mot_kW = 0.0F;/* '<S903>/MinMax2' */
MONPRM volatile float32 VEMS_MaxChrgPwr_kW = 0.0F;/* '<S902>/Product2' */
MONPRM volatile float32 VEMS_MaxConChrgCur_A = 0.0F;/* '<S902>/MinMax1' */
MONPRM volatile float32 VEMS_MaxConDchaCur_A = 0.0F;/* '<S904>/MinMax1' */
MONPRM volatile float32 VEMS_MaxDchaCur_A = 0.0F;/* '<S904>/Saturation4' */
MONPRM volatile float32 VEMS_MaxDchaPwr2MotRaw_kW = 0.0F;/* '<S904>/Add7' */
MONPRM volatile float32 VEMS_MaxDchaPwr2Mot_kW = 0.0F;/* '<S905>/MinMax2' */
MONPRM volatile float32 VEMS_MaxDchaPwr_kW = 0.0F;/* '<S904>/Product2' */
MONPRM volatile float32 VEMS_MaxInsChrgCur_A = 0.0F;/* '<S902>/MinMax3' */
MONPRM volatile float32 VEMS_MaxInsDchaCur_A = 0.0F;/* '<S904>/MinMax3' */
MONPRM volatile boolean VEMS_TMSActSOCEnbl_flg = false;/* '<S957>/Switch1' */

/* SOC是否限制TMS */
MONPRM volatile boolean VEMS_TMSPwrEnbl_flg = false;/* '<S906>/Switch3' */

/* 功率是否限制TMS */
MONPRM volatile float32 VEMS_TMSUsePwrRaw_kW = 0.0F;/* '<S906>/Subtract' */

/* TMS原始可用功率（BMS持续功率-DCDC实际功率） */
MONPRM volatile float32 VEMS_TMSUsePwr_kW = 0.0F;/* '<S906>/Switch2' */

/* TMS限制后可用功率(故障条件、TBOX远程、纯加热模式、SOC限制) */
MONPRM volatile boolean VEMS_UseConChrgCur_flg = false;/* '<S913>/Switch4' */
MONPRM volatile boolean VEMS_UseConDchaCur_flg = false;/* '<S931>/Switch4' */
MONPRM volatile boolean VGSM_AsstDrvFbShft_flg = false;/* '<S1677>/Logical Operator2' */

/* 规范：ACC/CC禁止档位解析 */
MONPRM volatile boolean VGSM_AsstDrvReqEPB_flg = false;/* '<S1663>/Switch4' */

/* ACC通讯丢失或故障拉起EPB */
MONPRM volatile boolean VGSM_DRFlt2N_flg = false;/* '<S1676>/Switch1' */

/* 规范：退至非驱动档标志位 */
MONPRM volatile boolean VGSM_EPBAplyFlt_flg = false;/* '<S1653>/EPBLogical' */

/* 故障P-EPB拉起故障 */
MONPRM volatile boolean VGSM_EPBRelsFlt_flg = false;/* '<S1653>/EPBLogical' */

/* 故障P-EPB释放故障 */
MONPRM volatile boolean VGSM_GrD2PExcdTm_flg = false;/* '<S1831>/Chart' */

/* D档入P请求超时入N */
MONPRM volatile boolean VGSM_GrNReq2P_flg = false;/* '<S1676>/Switch2' */

/* N档非换挡请求进P档请求 */
MONPRM volatile boolean VGSM_GrR2PExcdTm_flg = false;/* '<S1828>/Chart' */

/* R档入P请求超时入N */
MONPRM volatile boolean VGSM_HldGearP_flg = false;/* '<S1676>/Switch' */

/* 规范：保持P档标志位 */
MONPRM volatile boolean VGSM_INVRunEnbl_flg = false;/* '<S1679>/Chart' */

/* 规范：INV使能控制（允许扭矩控制）-VCU_1_EnaInvRun */
MONPRM volatile uint8 VGSM_PGrSwSts_enum = ((uint8)0U);/* '<S1677>/Switch2' */

/* 规范：P按键触发标志位-VCU_PGearSwcst */
MONPRM volatile boolean VGSM_ReqEPBAply_flg = false;/* '<S1678>/Logical Operator6' */

/* 规范：EPB拉起请求标志位 */
MONPRM volatile boolean VGSM_ReqEPBRels_flg = false;/* '<S1678>/Logical Operator4' */

/* 规范：EPB释放请求标志位 */
MONPRM volatile EnumEPBReq VGSM_ReqEPB_enum = EnumEPBReq_NoCmd;/* '<S1653>/Switch' */

/* 规范：EPB操作信号-VCUF_ReqEPB */
MONPRM volatile EnumTgtGearPstn VGSM_ShftTgtGrReq_enum = EnumTgtGearPstn_NoReq;/* '<S1677>/Data Type Conversion1' */

/* 换挡杆目标档位 0-NoCmd 1-P 2-N 3-D 4-R  */
MONPRM volatile EnumGearPstn VGSM_VehActGearPstn_enum = EnumGearPstn_P;/* '<S1654>/Switch1' */

/* 规范：实际档位-VCU_VhclActlGearPos */
MONPRM volatile boolean VGSM_VehEPBStErr_flg = false;/* '<S1653>/Logical Operator' */

/* 规范：P档故障PGear error-VCU_VhclPGearError */
MONPRM volatile EnumTgtGearPstn VGSM_VehTgtGrReq_enum = EnumTgtGearPstn_NoReq;/* '<S1678>/Data Type Conversion1' */

/* 规范:目标档位 */
MONPRM volatile uint8 VGSM_VehTgtGrTrnsfr_enum = ((uint8)0U);/* '<S1716>/Switch' */

/* 规范：换档请求信号 */
MONPRM volatile uint8 VHMI_12VBatLowVolSta_enum = ((uint8)0U);/* '<S80>/Switch' */
MONPRM volatile float32 VHMI_GrDSldDist_m = 0.0F;/* '<S94>/Saturation' */

/* D档后溜距离 */
MONPRM volatile boolean VHMI_GrDSldSw_flg = false;/* '<S94>/Logical Operator' */

/* D档溜坡计速/距离标志 */
MONPRM volatile float32 VHMI_GrRSldDist_m = 0.0F;/* '<S94>/Saturation1' */

/* R档前溜距离 */
MONPRM volatile boolean VHMI_GrRSldSw_flg = false;/* '<S94>/Logical Operator4' */

/* R档溜坡计速/距离标志 */
MONPRM volatile uint8 VHMI_InfoDisp_enum = ((uint8)0U);/* '<S83>/Arbitration' */

/* 仪表弹窗值 */
MONPRM volatile boolean VHVM_ACChrgEnbl_flg = false;/* '<S1547>/Logical Operator8' */

/* 交流充电基本条件满足 */
MONPRM volatile uint8 VHVM_ACChrgMaxCurrFb_A = ((uint8)0U);/* '<S1518>/Switch5' */

/* HU设置电流反馈 */
MONPRM volatile uint8 VHVM_ACChrgModeFb_enum = ((uint8)0U);/* '<S1518>/Switch7' */

/* HU设置充电模式反馈 */
MONPRM volatile boolean VHVM_ACChrging2Stop_flg = false;/* '<S1541>/AND' */

/* 交流充电中转移到充电停止标志位 */
MONPRM volatile boolean VHVM_ACDchaEnbl_flg = false;/* '<S1547>/Logical Operator10' */

/* 交流放电基本条件满足 */
MONPRM volatile boolean VHVM_ACDschrging2Stop_flg = false;/* '<S1541>/AND7' */

/* 交流放电中转移到放电停止标志位 */
MONPRM volatile EnumBMSSdnCmd VHVM_BMSShutdown_enum = EnumBMSSdnCmd_Normal;/* '<S1517>/Data Type Conversion10' */

/* VCU关闭BMS指令对应CAN信号：VCU_BMS_Shutdown */
MONPRM volatile EnumBMSWakeUpMd VHVM_BMSWakeUpMode_enum = EnumBMSWakeUpMd_Invld;/* '<S1517>/Data Type Conversion8' */

/* VCU唤醒BMS的方式对应CAN信号：VCU_BMS_WakeupMode */
MONPRM volatile boolean VHVM_Bat2DrvTrainEnbl_flg = false;/* '<S1517>/MainState' */

/* VCU控制主继电器指令对应CAN信号：VCU_Bat2DrvTrainEnb */
MONPRM volatile EnumChrgAllwCmd VHVM_ChrgAllowCmd_enum =
  EnumChrgAllwCmd_NotAllwd;            /* '<S1517>/Data Type Conversion12' */

/* VCU发送允许充电指令对应CAN信号：VCU_ChrgAllowCmd */
MONPRM volatile uint8 VHVM_ChrgEnaAC_enum = ((uint8)0U);/* '<S1517>/MainState' */

/* VCU控制OBC交流充电使能指令对应CAN信号：VCU_ChrgEna_AC */
MONPRM volatile boolean VHVM_ChrgEnaDC_flg = false;/* '<S1517>/MainState' */

/* VCU控制BMS直流充电使能指令对应CAN信号：VCU_ChrgEna_DC */
MONPRM volatile float32 VHVM_DCCBuckLVVolt_V = 0.0F;/* '<S1517>/MainState' */

/* VCU控制DCDC BUCK电压值对应CAN信号：VCU_DCCBuckLV_Vol */
MONPRM volatile EnumDCCOprtCmd VHVM_DCCOprtCmd_enum = EnumDCCOprtCmd_Off;/* '<S1517>/Data Type Conversion6' */

/* VCU控制DCDC工作模式指令对应CAN信号：VCU_DCCOprtCmd */
MONPRM volatile boolean VHVM_DCChrgEnbl_flg = false;/* '<S1547>/Logical Operator2' */

/* 直流充电基本条件满足 */
MONPRM volatile boolean VHVM_DCChrging2Over_flg = false;/* '<S1541>/AND1' */

/* 直流充电中转移到充电结束标志位 */
MONPRM volatile boolean VHVM_ECUSleepAllwd_flg = false;/* '<S1517>/MainState' */

/* 允许底层休眠标志位 */
MONPRM volatile boolean VHVM_EmgcySdn_flg = false;/* '<S1517>/MainState' */

/* VCU给INV发送紧急下电指令(INV强制停机)对应CAN信号：VCU_1_EmShutDown */
MONPRM volatile boolean VHVM_EnaDisChg_flg = false;/* '<S1517>/MainState' */

/* VCU控制INV泄放指令对应CAN信号：VCU_1_EnaDisChg */
MONPRM volatile boolean VHVM_EngyExtrmLo_flg = false;/* '<S1520>/Logical Operator17' */

/* 电池能量极低标志位 */
MONPRM volatile boolean VHVM_F1B1HVOffReq_flg = false;/* '<S1546>/Logical Operator45' */

/* F1B1下电请求 */
MONPRM volatile boolean VHVM_F1B1HVOnReq_flg = false;/* '<S1547>/Logical Operator45' */

/* F1B1上电请求 */
MONPRM volatile boolean VHVM_HVRdy_flg = false;/* '<S1517>/MainState' */

/* DCDC&INV预充完成 */
MONPRM volatile boolean VHVM_INVEnbl_flg = false;/* '<S1517>/MainState' */

/* VCU硬线唤醒INV */
MONPRM volatile boolean VHVM_INVPreprogmFlg_flg = false;/* '<S1542>/Switch1' */

/* INV预编程条件满足 */
MONPRM volatile float32 VHVM_MaxChrgCurntDC_A = 0.0F;/* '<S1517>/MainState' */

/* VCU允许BMS直流充电最大电流对应CAN信号：VCU_MaxChrgCrnt_DC */
MONPRM volatile float32 VHVM_MaxChrgVoltDC_V = 0.0F;/* '<S1517>/MainState' */

/* VCU允许BMS直流充电最大电压对应CAN信号：VCU_MaxChrgVol_DC */
MONPRM volatile float32 VHVM_MaxHVDCCurntAC_A = 0.0F;/* '<S1517>/MainState' */

/* VCU允许OBC交流充电最大电流对应CAN信号：VCU_MaxHVDC_Cur_AC */
MONPRM volatile float32 VHVM_MaxHVDCVoltAC_V = 0.0F;/* '<S1517>/MainState' */

/* VCU允许OBC交流充电最大电压对应CAN信号：VCU_MaxHVDC_Vol_AC */
MONPRM volatile EnumOBCOprtCmd VHVM_OBCOprtCmd_enum = EnumOBCOprtCmd_Standby;/* '<S1518>/Data Type Conversion4' */

/* VCU控制OBC工作模式指令对应CAN信号：VCU_OBCOprtCmd */
MONPRM volatile EnumPTActMd VHVM_PTActOprtMode_enum = EnumPTActMd_OFF;/* '<S1517>/Data Type Conversion4' */

/* 高压PT状态 */
MONPRM volatile boolean VHVM_PTRdy2PTStdby_flg = false;/* '<S1544>/Switch1' */

/* PTRdy到PTStdby标志位 */
MONPRM volatile boolean VHVM_PTStdby2PTRdy_flg = false;/* '<S1544>/Switch' */

/* PTStdby到PTRdy标志位 */
MONPRM volatile boolean VHVM_PowUpSelfChek_flg = false;/* '<S1545>/Switch' */

/* 高压自检标志位 */
MONPRM volatile boolean VHVM_PwrOn2PwrDwn_flg = false;/* '<S1546>/Switch' */

/* 高压下电条件满足标志位（正常/故障/紧急） */
MONPRM volatile boolean VHVM_SOPExtrmLo_flg = false;/* '<S1520>/Relational Operator4' */

/* 电池SOP极低，用于关闭DCDC */
MONPRM volatile EnumSysSta VHVM_SysSta_enum = EnumSysSta_Sleep;/* '<S1517>/Data Type Conversion2' */

/* 高压子状态 */
MONPRM volatile uint8 VHVM_TBOX2OBC_emun = ((uint8)0U);/* '<S1518>/Switch1' */

/* TBOX远程充放电指令 */
MONPRM volatile EnumVCUMode VHVM_VCUMode_enum = EnumVCUMode_PwrOff;/* '<S1517>/Data Type Conversion' */

/* 高压主转态 */
MONPRM volatile boolean VHVM_VehHalt_flg = false;/* '<S1536>/Switch4' */

/* 车辆停止标志位（车速极其） */
MONPRM volatile boolean VHVM_WakeUp2PwrUpACChrg_flg = false;/* '<S1547>/Logical Operator16' */

/* 交流充电唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpACDcha_flg = false;/* '<S1547>/Logical Operator26' */

/* 交流放电唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpDCChrg_flg = false;/* '<S1547>/Logical Operator4' */

/* 直流充电唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpIBS_flg = false;/* '<S1547>/Logical Operator6' */

/* IBS唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpKL15_flg = false;/* '<S1547>/Logical Operator' */

/* K15唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUp_flg = false;/* '<S1547>/Switch' */

/* 唤醒到上高压条件满足（唤醒源上升沿+高压自检通过） */
MONPRM volatile boolean VHVM_WakeUpBMS_flg = false;/* '<S1517>/MainState' */

/* VCU硬线唤醒BMS */
MONPRM volatile boolean VHVM_WakeUpVCU_flg = false;/* '<S1548>/Switch' */

/* 休眠到唤醒条件满足 */
MONPRM volatile boolean VIBS_BMSBatSOCAllow_flg = false;/* '<S259>/Switch3' */

/* 动力电池SOC允许补电标志位_versteckt */
MONPRM volatile boolean VIBS_ChgNumAllow_flg = false;/* '<S259>/AND' */

/* 补电次数允许标志位_versteckt */
MONPRM volatile uint8 VIBS_ChgNum_cnt = ((uint8)0U);/* '<S259>/Switch2' */

/* IBS补电次数_versteckt */
MONPRM volatile boolean VIBS_ChrgBascCond_flg = false;/* '<S259>/Logical Operator2' */

/* 补电基本条件满足（补电次数及电压）_versteckt */
MONPRM volatile boolean VIBS_ChrgEnbl_flg = false;/* '<S259>/Logical Operator7' */

/* IBS充电使能标志位_versteckt */
MONPRM volatile boolean VIBS_ChrgOver_flg = false;/* '<S257>/ChrgSt' */

/* IBS补电结束标志位_versteckt */
MONPRM volatile float32 VIBS_ChrgVoltThr_V = 0.0F;/* '<S260>/VoltState' */

/* 补电电压阈值_versteckt */
MONPRM volatile float32 VIBS_EnvirTemp_C = 0.0F;/* '<S282>/Switch' */

/* IBS环境温度_versteckt */
MONPRM volatile uint8 VIBS_FailChgNum_cnt = ((uint8)0U);/* '<S259>/Switch5' */

/* IBS补电失败次数_versteckt */
MONPRM volatile boolean VIBS_FbRctWup_flg = false;/* '<S259>/Logical Operator6' */

/* IBS禁止RTC唤醒标志位_versteckt */
MONPRM volatile boolean VIBS_HVReq_flg = false;/* '<S259>/Switch' */

/* IBS请求上高压标志位_versteckt */
MONPRM volatile float32 VIBS_HwKL30_V = 0.0F;/* '<S281>/Switch' */

/* 滤波后的KL30电压_versteckt */
MONPRM volatile float32 VIBS_MustChrgVolt_V = 0.0F;/* '<S260>/MIBS_MustChrgVolt_V' */

/* 兜底电压_versteckt */
MONPRM volatile boolean VIBS_MustChrg_flg = false;/* '<S290>/Chart' */

/* 兜底电压激活标志位_versteckt */
MONPRM volatile boolean VIBS_NMReq_flg = false;/* '<S266>/Switch4' */

/* IBS请求网络标志位_versteckt */
MONPRM volatile uint16 VIBS_NextRtcWupThr_min = ((uint16)0U);/* '<S260>/Switch1' */

/* 下次补电唤醒RTC的时间_versteckt */
MONPRM volatile EnumIBSChrgSt VIBS_RTCChrgSt_enum = EnumIBSChrgSt_Idle;/* '<S257>/Data Type Conversion' */

/* IBS补电状态_versteckt */
MONPRM volatile boolean VIBS_RTCWakeup_flg = false;/* '<S260>/Switch3' */

/* RTC唤醒标志位（含延迟时间）_versteckt */
MONPRM volatile boolean VIBS_SleepAllwd_flg = false;/* '<S259>/SleepAllwd' */

/* IBS允许底层休眠标志位_versteckt */
MONPRM volatile uint16 VIBS_WupChgTmThr_min = ((uint16)0U);/* '<S260>/Switch2' */

/* IBS补电时间阈值_versteckt */
MONPRM volatile boolean VIBS_WupVoltAllow_flg = false;/* '<S283>/Switch4' */

/* KL30电压允许标志位_versteckt */
MONPRM volatile boolean VIPC_ACCCfgd_flg = false;/* '<S365>/Switch8' */
MONPRM volatile boolean VIPC_AccPed1Flt_flg = false;/* '<S369>/Logical Operator1' */
MONPRM volatile boolean VIPC_AccPed1LrnDwnActv_flg = false;/* '<S379>/Relational Operator' */
MONPRM volatile boolean VIPC_AccPed1LrnUpActv_flg = false;/* '<S372>/Logical Operator5' */
MONPRM volatile float32 VIPC_AccPed1MinPstnLrnd_pct = 0.0F;/* '<S372>/Switch2' */
MONPRM volatile float32 VIPC_AccPed1NormzAvg_pct = 0.0F;/* '<S378>/Switch' */
MONPRM volatile float32 VIPC_AccPed1NormzPstn_pct = 0.0F;/* '<S369>/Switch5' */
MONPRM volatile float32 VIPC_AccPed1SclPstn_pct = 0.0F;/* '<S373>/Divide1' */
MONPRM volatile boolean VIPC_AccPed2Flt_flg = false;/* '<S369>/Logical Operator2' */
MONPRM volatile boolean VIPC_AccPed2LrnDwnActv_flg = false;/* '<S383>/Relational Operator' */
MONPRM volatile boolean VIPC_AccPed2LrnUpActv_flg = false;/* '<S374>/Logical Operator5' */
MONPRM volatile float32 VIPC_AccPed2MinPstnLrnd_pct = 0.0F;/* '<S374>/Switch2' */
MONPRM volatile float32 VIPC_AccPed2NormzAvg_pct = 0.0F;/* '<S382>/Switch' */
MONPRM volatile float32 VIPC_AccPed2NormzPstn_pct = 0.0F;/* '<S369>/Switch7' */
MONPRM volatile float32 VIPC_AccPed2SclPstn_pct = 0.0F;/* '<S375>/Divide5' */
MONPRM volatile boolean VIPC_AccPedPstnVld_flg = false;/* '<S371>/Switch3' */
MONPRM volatile float32 VIPC_AccPedPstn_pct = 0.0F;/* '<S367>/MinMax3' */
MONPRM volatile uint8 VIPC_AccPedSnsrSta_enum = ((uint8)0U);/* '<S371>/Switch3' */
MONPRM volatile boolean VIPC_AccPedStkActv_flg = false;/* '<S370>/Logical Operator6' */
MONPRM volatile boolean VIPC_AccPedStkBrkPrsd_flg = false;/* '<S397>/Switch4' */
MONPRM volatile float32 VIPC_AccPedStkPstn_pct = 0.0F;/* '<S370>/MinMax' */
MONPRM volatile boolean VIPC_AccPedStkStab_flg = false;/* '<S399>/Relational Operator' */
MONPRM volatile float32 VIPC_AccPedWghtAvg_pct = 0.0F;/* '<S396>/Switch' */
MONPRM volatile float32 VIPC_AccPedWghtPstn_pct = 0.0F;/* '<S371>/Switch3' */
MONPRM volatile float32 VIPC_AccPedZeroPstn_pct = 0.0F;/* '<S370>/Switch' */
MONPRM volatile boolean VIPC_BrkPedPstnVld_flg = false;/* '<S362>/Logical Operator8' */
MONPRM volatile float32 VIPC_BrkPedPstn_pct = 0.0F;/* '<S362>/Saturation1' */
MONPRM volatile boolean VIPC_BrkSwActv_flg = false;/* '<S362>/Logical Operator' */
MONPRM volatile boolean VIPC_CCSCfgd_flg = false;/* '<S365>/Switch1' */
MONPRM volatile boolean VIPC_CrpCtrlCfgd_flg = false;/* '<S365>/Switch2' */
MONPRM volatile EnumCrpModeAct VIPC_CrpModeAct_enum = EnumCrpModeAct_Open;/* '<S364>/Switch12' */
MONPRM volatile EnumDrvModeAct VIPC_DrvModeAct_enum = EnumDrvModeAct_Invalid;/* '<S364>/Switch13' */
MONPRM volatile uint8 VIPC_DrvPwrIntnsty_pct = ((uint8)0U);/* '<S364>/Switch25' */
MONPRM volatile boolean VIPC_DrvSw_flg = false;/* '<S367>/Relational Operator3' */
MONPRM volatile boolean VIPC_EPBAppld_flg = false;/* '<S363>/Logical Operator2' */
MONPRM volatile boolean VIPC_EPBReld_flg = false;/* '<S363>/Logical Operator1' */
MONPRM volatile boolean VIPC_HDCCfgd_flg = false;/* '<S365>/Switch3' */
MONPRM volatile EnumRegenModeAct VIPC_RegenModeAct_enum = EnumRegenModeAct_Off;/* '<S364>/Switch15' */
MONPRM volatile uint8 VIPC_RegenPwrIntnsty_pct = ((uint8)0U);/* '<S364>/Switch28' */
MONPRM volatile boolean VIPC_SnowMode_flg = false;/* '<S364>/Switch14' */
MONPRM volatile float32 VIPC_TireRadius_m = 0.0F;/* '<S365>/TireSizeTable' */
MONPRM volatile uint8 VIPC_VehHiddenMode_enum = ((uint8)0U);/* '<S364>/VehHiddenMode' */
MONPRM volatile float32 VIPC_VehSpdDrvnMotor_kph = 0.0F;/* '<S366>/Product1' */
MONPRM volatile boolean VIPC_VehSpdDrvnVld_flg = false;/* '<S433>/Logical Operator2' */
MONPRM volatile float32 VIPC_VehSpdDrvn_kph = 0.0F;/* '<S433>/Switch7' */
MONPRM volatile boolean VIPC_VehSpdNonDrvnVld_flg = false;/* '<S434>/Logical Operator2' */
MONPRM volatile float32 VIPC_VehSpdNonDrvn_kph = 0.0F;/* '<S434>/Switch7' */
MONPRM volatile boolean VIPC_VehSpdVld_flg = false;/* '<S433>/SignalConversion' */
MONPRM volatile float32 VIPC_VehSpd_kph = 0.0F;/* '<S433>/Switch4' */
MONPRM volatile boolean VIPC_VpedAutoCrp_flg = false;/* '<S421>/Switch4' */
MONPRM volatile boolean VIPC_ZeroPstnRst_flg = false;/* '<S370>/Logical Operator3' */
MONPRM volatile boolean VIPC_iTPMSCfgd_flg = false;/* '<S365>/Switch4' */
MONPRM volatile float32 VIPM_HwAccPedCh1SuplyVolt_mV = 0.0F;/* '<S15>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh1Volt_mV = 0.0F;/* '<S16>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh2SuplyVolt_mV = 0.0F;/* '<S17>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh2Volt_mV = 0.0F;/* '<S18>/MinMax1' */
MONPRM volatile boolean VIPM_HwBMSWakeup_flg = false;/* '<S19>/Switch4' */
MONPRM volatile boolean VIPM_HwBrkSwHi_flg = false;/* '<S20>/Switch4' */
MONPRM volatile boolean VIPM_HwBrkSwLo_flg = false;/* '<S21>/Switch4' */
MONPRM volatile boolean VIPM_HwCrpModeSw_flg = false;/* '<S22>/Switch4' */
MONPRM volatile boolean VIPM_HwDrvModeSw_flg = false;/* '<S23>/Switch4' */
MONPRM volatile boolean VIPM_HwEmgcyShutOff_flg = false;/* '<S24>/Switch4' */
MONPRM volatile float32 VIPM_HwHVIL1Volt_mV = 0.0F;/* '<S25>/MinMax1' */
MONPRM volatile float32 VIPM_HwHVIL2Volt_mV = 0.0F;/* '<S26>/MinMax1' */
MONPRM volatile boolean VIPM_HwKL15A_flg = false;/* '<S27>/Switch4' */
MONPRM volatile boolean VIPM_HwKL15B_flg = false;/* '<S28>/Switch4' */
MONPRM volatile uint16 VIPM_HwKL30_mV = ((uint16)0U);/* '<S29>/MinMax1' */
MONPRM volatile boolean VIPM_HwOBCWakeup_flg = false;/* '<S30>/Switch4' */
MONPRM volatile boolean VIPM_HwRearFogLampSwt_flg = false;/* '<S31>/Switch4' */
MONPRM volatile EnumPGearSwSts VIPM_HwShftPstnSwSts_enum = EnumPGearSwSts_Reld;/* '<S32>/Switch4' */
MONPRM volatile uint16 VIPM_HwShftPstnSw_Ohm = ((uint16)0U);/* '<S8>/HwShftPstnSw' */
MONPRM volatile boolean VIPM_HwVehCrash_flg = false;/* '<S33>/Switch4' */
MONPRM volatile uint8 VNVM_ACChrgMaxCurrFb_A = ((uint8)0U);/* '<S9>/Selector18' */
MONPRM volatile uint8 VNVM_ACChrgModeFb_enum = ((uint8)0U);/* '<S9>/Selector19' */
MONPRM volatile float32 VNVM_AvgPwrCnsm_kWh100km = 0.0F;/* '<S9>/Add2' */
MONPRM volatile float32 VNVM_AvgSOCCnsmWght_pctp100km = 0.0F;/* '<S9>/Add6' */
MONPRM volatile EnumCrpModeAct VNVM_CrpModeAct_enum = EnumCrpModeAct_Open;/* '<S9>/Data Type Conversion1' */
MONPRM volatile EnumDrvModeAct VNVM_DrvModeAct_enum = EnumDrvModeAct_Invalid;/* '<S9>/Data Type Conversion23' */
MONPRM volatile uint8 VNVM_DrvPwrIntnsty_pct = ((uint8)0U);/* '<S9>/Selector6' */
MONPRM volatile float32 VNVM_DynRmnMilEst_km = 0.0F;/* '<S9>/Gain2' */
MONPRM volatile uint8 VNVM_EE01ReadOK_nu = ((uint8)0U);/* '<S9>/Selector13' */
MONPRM volatile uint8 VNVM_EEImdtReadOK_nu = ((uint8)0U);/* '<S9>/Selector14' */
MONPRM volatile boolean VNVM_HVRdy_flg = false;/* '<S9>/Data Type Conversion27' */
MONPRM volatile uint8 VNVM_IBSChrgFailNum_cnt = ((uint8)0U);/* '<S9>/Selector1' */
MONPRM volatile uint8 VNVM_IBSChrgNum_cnt = ((uint8)0U);/* '<S9>/Selector' */
MONPRM volatile EnumPTActMd VNVM_PTActOprtMode_enum = EnumPTActMd_OFF;/* '<S9>/Data Type Conversion30' */
MONPRM volatile EnumRegenModeAct VNVM_RegenModeAct_enum = EnumRegenModeAct_Off;/* '<S9>/Data Type Conversion24' */
MONPRM volatile uint8 VNVM_RegenPwrIntnsty_pct = ((uint8)0U);/* '<S9>/Selector7' */
MONPRM volatile boolean VNVM_TBOXOffline_flg = false;/* '<S9>/Data Type Conversion11' */
MONPRM volatile EnumTBOXLimSt VNVM_VCUSpdLimSt_enum = EnumTBOXLimSt_Normal;/* '<S9>/Data Type Conversion10' */
MONPRM volatile boolean VNVM_VCUVerFb_flg = false;/* '<S9>/Data Type Conversion12' */
MONPRM volatile EnumGearPstn VNVM_VehActGearPstn_enum = EnumGearPstn_P;/* '<S9>/Data Type Conversion31' */
MONPRM volatile EnumXWhlDistErrRefSt VNVM_XWhlDistErrRefStat_enum =
  EnumXWhlDistErrRefSt_Init;           /* '<S9>/Data Type Conversion22' */
MONPRM volatile float32 VNVM_XWhlDistErrRef_mpkm = 0.0F;/* '<S9>/Add1' */
MONPRM volatile boolean VNVM_iTPMSWrng_flg = false;/* '<S9>/Data Type Conversion21' */
MONPRM volatile boolean VOPM_HwWakeupBMS_flg = false;/* '<S47>/Switch4' */
MONPRM volatile float32 VRME_AvgSOCCnsm100Num_pctpkm = 0.0F;/* '<S240>/Signal Copy5' */

/* 前100个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm10Num_pctpkm = 0.0F;/* '<S240>/Signal Copy1' */

/* 前10个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm15Num_pctpkm = 0.0F;/* '<S240>/Signal Copy2' */

/* 前15个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm25Num_pctpkm = 0.0F;/* '<S240>/Signal Copy3' */

/* 前25个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm50Num_pctpkm = 0.0F;/* '<S240>/Signal Copy4' */

/* 前50个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm5Num_pctpkm = 0.0F;/* '<S240>/Signal Copy' */

/* 前5个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsmWght_pctpkm = 0.0F;/* '<S240>/Switch1' */

/* 加权平均SOC能耗 */
MONPRM volatile boolean VRME_CHTCRmnMilEstV_flg = false;/* '<S206>/Logical Operator' */

/* CHTC标准续航里程有效性 */
MONPRM volatile float32 VRME_CHTCRmnMilEst_km = 0.0F;/* '<S206>/MRME_CHTCStdRmnMil_km' */

/* CHTC标准续航查表值 */
MONPRM volatile float32 VRME_CalPwrCnsmPerTrig_kWhptrig = 0.0F;/* '<S210>/Switch4' */

/* Pwr消耗/单位里程（trig） */
MONPRM volatile boolean VRME_CalPwrCnsmTrig_flg = false;/* '<S210>/Relational Operator1' */

/* 累计里程大于单位里程 */
MONPRM volatile float32 VRME_CalSOCCnsmDrvDist_m = 0.0F;/* '<S239>/Switch1' */

/* 单位目标行驶里程 */
MONPRM volatile float32 VRME_CalSOCCnsmPerTrig_pctptrig = 0.0F;/* '<S239>/Switch4' */

/* SOC消耗/单位里程（trig） */
MONPRM volatile float32 VRME_CalSOCCnsmPerkm_pctpkm = 0.0F;/* '<S239>/Divide' */

/* SOC消耗/单位里程（1km） */
MONPRM volatile boolean VRME_CalSOCCnsmTrig_flg = false;/* '<S239>/Relational Operator1' */

/* 累计里程大于目标里程 */
MONPRM volatile float32 VRME_ChrgRmnMilEstTgt_km = 0.0F;/* '<S235>/Switch2' */

/* 充电模式动态续航目标值 */
MONPRM volatile float32 VRME_ChrgRmnMilEst_km = 0.0F;/* '<S219>/Different Slops' */

/* 充电工况动态续航值 */
MONPRM volatile float32 VRME_ChrgTgtFstRate_kmpsoc = 0.0F;/* '<S219>/Divide2' */

/* 充电工况目标续航追击速率 */
MONPRM volatile float32 VRME_ChrgTgtNormRate_kmpsoc = 0.0F;/* '<S219>/Divide1' */

/* 充电工况目标续航变化速率 */
MONPRM volatile float32 VRME_DchaRmnMilEstChgFac_c = 0.0F;/* '<S238>/MRME_DynEstRmnChgStp_c' */

/* 非充电模式动态续航变化系数 */
MONPRM volatile float32 VRME_DchaRmnMilEstTgt_km = 0.0F;/* '<S247>/Switch2' */

/* 非充电模式动态续航目标值 */
MONPRM volatile boolean VRME_DchaRmnMilEstUpdTrig_flg = false;/* '<S238>/Relational Operator2' */

/* 更新续航值 */
MONPRM volatile float32 VRME_DchaRmnMilEst_km = 0.0F;/* '<S238>/Signal Copy1' */

/* 非充电模式动态续航值 */
MONPRM volatile boolean VRME_DchaVehStall_flg = false;/* '<S237>/Logical Operator4' */

/* 非充电模式车辆驻车状态 */
MONPRM volatile boolean VRME_DynRmnMilEstV_flg = false;/* '<S208>/Logical Operator1' */

/* 动态续航有效性 */
MONPRM volatile float32 VRME_VehPwrCnsmAvg_kWhpkm = 0.0F;/* '<S210>/Switch7' */

/* 当前循环平均能耗 */
MONPRM volatile float32 VRME_VehPwrCnsmIns_kWhpkm = 0.0F;/* '<S210>/Divide' */

/* 当前循环瞬间能耗 */
MONPRM volatile float32 VRME_VehTotMilCyc_km = 0.0F;/* '<S210>/Gain8' */

/* 当前驾驶循环车辆里程 */
MONPRM volatile float32 VRME_VehTotPwrCyc_kWh = 0.0F;/* '<S210>/Switch8' */

/* 当前驾驶循环车辆功率 */
MONPRM volatile float32 VRME_WLTPRmnMilEstDwLim_km = 0.0F;/* '<S215>/Product3' */

/* 动态续航下限值 */
MONPRM volatile float32 VRME_WLTPRmnMilEstUpLim_km = 0.0F;/* '<S215>/Product2' */

/* 动态续航上限值 */
MONPRM volatile float32 VRME_WLTPRmnMilEst_km = 0.0F;/* '<S215>/MRME_WLTPStdRmnMil_km' */

/* WLTP标准续航查表值 */
MONPRM volatile float32 VRME_WLTPStdPwrCnsm_kWhpkm = 0.0F;/* '<S210>/Gain5' */

/* 标准工况电耗（kWh/km） */
MONPRM volatile float32 VRME_WLTPStdSOCCnsm_pctpkm = 0.0F;/* '<S239>/Gain3' */

/* 标准工况下SOC消耗/km */
MONPRM volatile boolean VTBX_CnclSpdLim_flg = false;/* '<S317>/Logical Operator12' */

/* TBOX解除限速 */
MONPRM volatile boolean VTBX_LckVer_flg = false;/* '<S337>/Chart' */

/* 锁车版本 */
MONPRM volatile boolean VTBX_RecryTBOXHw_flg = false;/* '<S317>/Logical Operator14' */

/* TBOX硬件通讯丢失恢复 */
MONPRM volatile boolean VTBX_ReqLimpHome_flg = false;/* '<S316>/Data Type Conversion6' */

/* VCU请求跛行动作 */
MONPRM volatile boolean VTBX_RmvTBOXHw_flg = false;/* '<S317>/Logical Operator3' */

/* TBOX硬件通讯丢失 */
MONPRM volatile boolean VTBX_SpdLimLvl1_flg = false;/* '<S317>/Logical Operator5' */

/* TBOX一级限速 */
MONPRM volatile boolean VTBX_SpdLimLvl2_flg = false;/* '<S317>/Logical Operator7' */

/* TBOX二级限速 */
MONPRM volatile boolean VTBX_SpdLimLvl3_flg = false;/* '<S317>/Logical Operator9' */

/* TBOX三级限速 */
MONPRM volatile boolean VTBX_StorgSpdLim_flg = false;/* '<S317>/Logical Operator11' */

/* TBOX库存限速 */
MONPRM volatile boolean VTBX_TBOXOffline_flg = false;/* '<S316>/Signal Copy3' */

/* TBOX硬件状态-实时存储 */
MONPRM volatile boolean VTBX_UnlckVer_flg = false;/* '<S336>/Chart' */

/* 非锁车版本 */
MONPRM volatile boolean VTBX_VCUChrgngCondsFb_flg = false;/* '<S316>/Data Type Conversion5' */

/* VCU反馈判断充电条件 */
MONPRM volatile uint8 VTBX_VCULckVehWrn_enum = ((uint8)0U);/* '<S316>/Signal Copy5' */

/* VCU反馈锁存提醒 */
MONPRM volatile boolean VTBX_VCUOprtLicFb_flg = false;/* '<S316>/Data Type Conversion4' */

/* VCU反馈运营状态 */
MONPRM volatile EnumTBOXLimGrd VTBX_VCUSpdLimLvlFb_enum = EnumTBOXLimGrd_Normal;/* '<S316>/Data Type Conversion3' */

/* VCU反馈限速等级-当前驾驶循环 */
MONPRM volatile uint8 VTBX_VCUSpdLimLvlSetFb_enum = ((uint8)0U);/* '<S316>/Data Type Conversion7' */

/* VCU反馈限速等级设置成功 */
MONPRM volatile EnumTBOXLimSt VTBX_VCUSpdLimSt_enum = EnumTBOXLimSt_Normal;/* '<S316>/Data Type Conversion1' */

/* 当前循环限速状态-实时存储 */
MONPRM volatile boolean VTBX_VCUVerFb_flg = false;/* '<S316>/Signal Copy' */

/* VCU反馈锁车版本-实时存储 */
MONPRM volatile uint8 VTBX_VCUVerSetFb_enum = ((uint8)0U);/* '<S316>/Signal Copy1' */

/* VCU反馈锁车版本设置成功 */
MONPRM volatile float32 VTQC_ABSorESPActvTm_s = 0.0F;/* '<S703>/MinMax' */
MONPRM volatile float32 VTQC_BrkRegenMaxTqWhl_Nm = 0.0F;/* '<S698>/Switch17' */
MONPRM volatile float32 VTQC_BrkRegenTgtTqWhl_Nm = 0.0F;/* '<S698>/Switch2' */
MONPRM volatile float32 VTQC_CstRegenLmtTq_Nm = 0.0F;/* '<S696>/CstRegenLmtTq' */
MONPRM volatile float32 VTQC_DrvTqReqWhlABS_Nm = 0.0F;/* '<S696>/MinMax1' */
MONPRM volatile float32 VTQC_DrvTqReqWhlRBS_Nm = 0.0F;/* '<S705>/MinMax5' */
MONPRM volatile float32 VTQC_DrvTqReqWhl_Nm = 0.0F;/* '<S697>/Switch5' */
MONPRM volatile float32 VTQC_MotorTqReq_Nm = 0.0F;/* '<S697>/Divide' */
MONPRM volatile boolean VTQC_RBSActv_flg = false;/* '<S706>/Switch4' */
MONPRM volatile float32 VTQD_AccelPedPstnRescl_pct = 0.0F;/* '<S717>/Product' */
MONPRM volatile float32 VTQD_AdaptCstDeltaAcceltn_mps2 = 0.0F;/* '<S733>/Add5' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqFF_Nm = 0.0F;/* '<S733>/Add2' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqI_N = 0.0F;/* '<S733>/Saturation2' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqPID_Nm = 0.0F;/* '<S733>/Product6' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqP_N = 0.0F;/* '<S733>/Product3' */
MONPRM volatile float32 VTQD_AdaptCstMaxTqWhl_Nm = 0.0F;/* '<S729>/MinMax4' */
MONPRM volatile float32 VTQD_AdaptCstMinTqWhl_Nm = 0.0F;/* '<S729>/MinMax5' */
MONPRM volatile boolean VTQD_AdaptCstRegenEnbl_flg = false;/* '<S729>/Logical Operator9' */
MONPRM volatile float32 VTQD_AdaptCstTgtAcceltn_mps2 = 0.0F;/* '<S735>/Switch' */
MONPRM volatile float32 VTQD_AdaptCstTqReqWhl_Nm = 0.0F;/* '<S733>/MinMax6' */
MONPRM volatile boolean VTQD_BkwdDrv_flg = false;/* '<S756>/Switch4' */
MONPRM volatile boolean VTQD_BrkRegenEnbl_flg = false;/* '<S728>/Logical Operator1' */
MONPRM volatile float32 VTQD_CrpTqReqWhl_Nm = 0.0F;/* '<S719>/Switch2' */
MONPRM volatile boolean VTQD_CstRegenEnbl_flg = false;/* '<S728>/Logical Operator13' */
MONPRM volatile float32 VTQD_CstRegenEndPstn_pct = 0.0F;/* '<S728>/Switch2' */
MONPRM volatile float32 VTQD_CstRegenTqReqWhl_Nm = 0.0F;/* '<S730>/Switch4' */
MONPRM volatile float32 VTQD_DrvTqDrtFac_c = 0.0F;/* '<S757>/Saturation' */
MONPRM volatile float32 VTQD_DrvTqReqWhlMrg_Nm = 0.0F;/* '<S758>/Switch4' */
MONPRM volatile float32 VTQD_DrvTqReqWhlRaw_Nm = 0.0F;/* '<S717>/Merge' */
MONPRM volatile float32 VTQD_DrvTqReqWhl_Nm = 0.0F;/* '<S715>/Switch3' */
MONPRM volatile boolean VTQD_DsblCrp_flg = false;/* '<S719>/Logical Operator12' */
MONPRM volatile float32 VTQD_FullPedDrvTqWhl_Nm = 0.0F;/* '<S717>/Signal Conversion1' */
MONPRM volatile float32 VTQD_FwdPedMap_pct = 0.0F;/* '<S720>/Switch9' */
MONPRM volatile float32 VTQD_PedalTqReqWhlRaw_Nm = 0.0F;/* '<S714>/Add' */
MONPRM volatile uint16 VTQD_TaskRunCounter_cnt = ((uint16)0U);/* '<S547>/Max1' */

/* test signal, to be deleted */
MONPRM volatile boolean VTQD_TqZeroFast_flg = false;/* '<S749>/Logical Operator4' */
MONPRM volatile boolean VTQD_TqZeroSlow_flg = false;/* '<S749>/Logical Operator2' */
MONPRM volatile boolean VTQD_TqZero_flg = false;/* '<S749>/Logical Operator1' */
MONPRM volatile float32 VTQF_DrvTqReqWhl_Nm = 0.0F;/* '<S774>/Switch2' */
MONPRM volatile float32 VTQF_TipOutTqDecRateCoeff_rat = 0.0F;/* '<S776>/1-D Lookup Table1' */
MONPRM volatile boolean VTQF_TqInc_flg = false;/* '<S786>/Switch4' */
MONPRM volatile float32 VTQF_TqOutChgRate_Nmps = 0.0F;/* '<S796>/Switch' */
MONPRM volatile float32 VTQF_TqRateDecTgtMax_Nmps = 0.0F;/* '<S776>/Switch3' */
MONPRM volatile float32 VTQF_TqRateDecTgtMin_Nmps = 0.0F;/* '<S776>/MinMax4' */
MONPRM volatile float32 VTQF_TqRateIncTgtMax_Nmps = 0.0F;/* '<S777>/Switch5' */
MONPRM volatile float32 VTQF_TqRateIncTgtMin_Nmps = 0.0F;/* '<S777>/MinMax4' */
MONPRM volatile float32 VTQF_TqRateLimDec_Nmps = 0.0F;/* '<S776>/MinMax3' */
MONPRM volatile boolean VTQF_TqRateLimEndg_flg = false;/* '<S775>/Logical Operator9' */
MONPRM volatile float32 VTQF_TqRateLimInc_Nmps = 0.0F;/* '<S777>/MinMax2' */
MONPRM volatile float32 VTQF_TqRawChgRate_Nmps = 0.0F;/* '<S795>/Switch' */
MONPRM volatile float32 VTQF_WhlDrgMaxTqZX_Nm = 0.0F;/* '<S794>/Switch1' */
MONPRM volatile float32 VTQF_WhlDrvMaxTqZX_Nm = 0.0F;/* '<S794>/Switch7' */
MONPRM volatile boolean VTQR_ASDEnbl_flg = false;/* '<S799>/Logical Operator14' */
MONPRM volatile float32 VTQR_ASDSpdFltHi_rpm = 0.0F;/* '<S807>/Switch' */
MONPRM volatile float32 VTQR_ASDSpdOscRaw_rpm = 0.0F;/* '<S803>/Add1' */
MONPRM volatile float32 VTQR_ASDSpdOsc_rpm = 0.0F;/* '<S805>/Multiport Switch' */
MONPRM volatile float32 VTQR_ASDTqReqRaw_Nm = 0.0F;/* '<S811>/MinMax5' */
MONPRM volatile float32 VTQR_ASDTqReq_Nm = 0.0F;/* '<S804>/Switch3' */
MONPRM volatile boolean VTQR_MotDampngEnbl_flg = false;/* '<S799>/Logical Operator1' */
MONPRM volatile float32 VTQR_MotDampngLmt_Nm = 0.0F;/* '<S819>/MinMax5' */
MONPRM volatile EnumMotorDirReq VTQR_MotorDirReq_enum = EnumMotorDirReq_Stdby;/* '<S800>/Switch4' */
MONPRM volatile EnumMotorModeReq VTQR_MotorModeReq_enum = EnumMotorModeReq_Stdby;/* '<S797>/Signal Conversion15' */
MONPRM volatile float32 VTQR_MotorSpdReq_rpm = 0.0F;/* '<S797>/Signal Conversion1' */
MONPRM volatile boolean VTQR_MotorStdby_flg = false;/* '<S801>/Logical Operator1' */
MONPRM volatile float32 VTQR_MotorTqReq_Nm = 0.0F;/* '<S797>/Signal Conversion2' */
MONPRM volatile float32 VTZX_AZDecRate_Nmps = 0.0F;/* '<S835>/1-D Lookup Table4' */
MONPRM volatile float32 VTZX_AZIncRate_Nmps = 0.0F;/* '<S835>/1-D Lookup Table3' */
MONPRM volatile float32 VTZX_BZDecRate_Nmps = 0.0F;/* '<S835>/1-D Lookup Table2' */
MONPRM volatile float32 VTZX_BZIncRate_Nmps = 0.0F;/* '<S835>/1-D Lookup Table1' */
MONPRM volatile boolean VTZX_BypZX_flg = false;/* '<S839>/Logical Operator1' */
MONPRM volatile boolean VTZX_ClkActv_flg = false;/* '<S838>/Switch4' */
MONPRM volatile float32 VTZX_ClkZXTm_s = 0.0F;/* '<S831>/Switch1' */
MONPRM volatile float32 VTZX_MotorTqReqPrdt_Nm = 0.0F;/* '<S851>/MinMax5' */
MONPRM volatile float32 VTZX_MotorTqReqZX_Nm = 0.0F;/* '<S836>/TqZXSt' */
MONPRM volatile float32 VTZX_MotorTqReq_Nm = 0.0F;/* '<S831>/Switch6' */
MONPRM volatile boolean VTZX_TqInc_flg = false;/* '<S845>/Switch4' */
MONPRM volatile boolean VTZX_TqRateLimRamp_flg = false;/* '<S852>/Switch4' */
MONPRM volatile EnumTZXStat VTZX_TqZXSt_enum = EnumTZXStat_NTRL;/* '<S836>/Data Type Conversion1' */
MONPRM volatile float32 VTZX_ZeroTqHldDec_Nm = 0.0F;/* '<S836>/TqZXSt' */
MONPRM volatile float32 VTZX_ZeroTqHldInc_Nm = 0.0F;/* '<S836>/TqZXSt' */
MONPRM volatile float32 VTZX_ZeroTqOfstDec_Nm = 0.0F;/* '<S835>/Switch3' */
MONPRM volatile float32 VTZX_ZeroTqOfstInc_Nm = 0.0F;/* '<S835>/Switch2' */
MONPRM volatile float32 VTZX_ZeroTqOfst_Nm = 0.0F;/* '<S835>/Switch4' */
MONPRM volatile float32 VTZX_ZeroXTm_s = 0.0F;/* '<S835>/Switch8' */
MONPRM volatile uint8 VVCU_ECURstCntr_cnt = ((uint8)0U);/* '<S44>/Switch2' */

/* 控制器Reset计数器 */
MONPRM volatile float32 VVSO_ALatSnsr_mps2 = 0.0F;/* '<S451>/Switch1' */
MONPRM volatile float32 VVSO_ALgtSnsr_mps2 = 0.0F;/* '<S450>/Switch1' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr1_mpkm = 0.0F;/* '<S512>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr2_mpkm = 0.0F;/* '<S512>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr3_mpkm = 0.0F;/* '<S512>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr4_mpkm = 0.0F;/* '<S512>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr5_mpkm = 0.0F;/* '<S512>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr_mpkm = 0.0F;/* '<S512>/Add3' */
MONPRM volatile float32 VVSO_DrvDist_m = 0.0F;/* '<S525>/Switch1' */
MONPRM volatile boolean VVSO_RSEBrkPresrConf_flg = false;/* '<S497>/Relational Operator2' */
MONPRM volatile boolean VVSO_RSESigConf_flg = false;/* '<S483>/Logical Operator3' */
MONPRM volatile boolean VVSO_RSEVehSpdConf_flg = false;/* '<S499>/Logical Operator2' */
MONPRM volatile boolean VVSO_RSEWhlSlipConf_flg = false;/* '<S500>/Logical Operator2' */
MONPRM volatile boolean VVSO_RSEYawRateConf_flg = false;/* '<S501>/Logical Operator' */
MONPRM volatile float32 VVSO_RoadSlopCalcRaw_pct = 0.0F;/* '<S481>/Product19' */
MONPRM volatile boolean VVSO_RoadSlopEstVld_flg = false;/* '<S480>/Logical Operator1' */
MONPRM volatile float32 VVSO_RoadSlopEst_pct = 0.0F;/* '<S480>/Switch2' */
MONPRM volatile float32 VVSO_RoadSlopTqEst_Nm = 0.0F;/* '<S496>/MinMax5' */
MONPRM volatile float32 VVSO_VehDrvResistTq_Nm = 0.0F;/* '<S482>/Switch5' */
MONPRM volatile boolean VVSO_VehMassConf_flg = false;/* '<S528>/Logical Operator4' */
MONPRM volatile uint8 VVSO_VehMassDistb_enum = ((uint8)0U);/* '<S528>/Signal Conversion' */
MONPRM volatile float32 VVSO_VehMassEst_kg = 0.0F;/* '<S531>/Switch' */
MONPRM volatile float32 VVSO_VehSpd_mps = 0.0F;/* '<S528>/Gain3' */
MONPRM volatile float32 VVSO_WhlAcceltnFL_mps2 = 0.0F;/* '<S463>/Divide' */
MONPRM volatile float32 VVSO_WhlAcceltnFR_mps2 = 0.0F;/* '<S464>/Divide' */
MONPRM volatile float32 VVSO_WhlAcceltnRL_mps2 = 0.0F;/* '<S465>/Divide' */
MONPRM volatile float32 VVSO_WhlAcceltnRR_mps2 = 0.0F;/* '<S466>/Divide' */
MONPRM volatile boolean VVSO_WhlDistErrHld_flg = false;/* '<S516>/OR' */
MONPRM volatile float32 VVSO_WhlLgtFrc_N = 0.0F;/* '<S533>/Add' */
MONPRM volatile EnumXWhlDistErrRefSt VVSO_XWhlDistErrRefStat_enum =
  EnumXWhlDistErrRefSt_Init;           /* '<S512>/Signal Conversion2' */
MONPRM volatile float32 VVSO_XWhlDistErrRef_mpkm = 0.0F;/* '<S512>/Signal Conversion1' */
MONPRM volatile float32 VVSO_XWhlDistErr_m = 0.0F;/* '<S525>/Switch4' */
MONPRM volatile float32 VVSO_YawRateBas_degps = 0.0F;/* '<S457>/Switch' */
MONPRM volatile float32 VVSO_YawRateDer_radps2 = 0.0F;/* '<S452>/Add6' */
MONPRM volatile float32 VVSO_YawRateFilt_radps = 0.0F;/* '<S456>/Switch' */
MONPRM volatile boolean VVSO_iTPMSAvail_flg = false;/* '<S516>/Logical Operator' */
MONPRM volatile EnumiTPMSSt VVSO_iTPMSState_enum = EnumiTPMSSt_Init;/* '<S512>/Signal Conversion' */
MONPRM volatile boolean VVSO_iTPMSWrng_flg = false;/* '<S512>/Signal Conversion3' */
MONPRM volatile boolean VVTM_BrkPedReld_flg = false;/* '<S877>/Logical Operator3' */
MONPRM volatile uint8 VVTM_DrvMotorSta_enum = ((uint8)0U);/* '<S884>/DriveMotorState' */
MONPRM volatile boolean VVTM_ESPIntvActv_flg = false;/* '<S877>/Logical Operator4' */
MONPRM volatile float32 VVTM_MotorActPwr_kW = 0.0F;/* '<S891>/Switch2' */
MONPRM volatile float32 VVTM_MotorSpd_rpm = 0.0F;/* '<S879>/Switch' */
MONPRM volatile boolean VVTM_PCUFailSta_flg = false;/* '<S884>/Logical Operator2' */
MONPRM volatile boolean VVTM_RegenReqBrkLampOn_flg = false;/* '<S889>/Switch1' */
MONPRM volatile float32 VVTM_RsrvPwr_kW = 0.0F;/* '<S886>/MinMax4' */
MONPRM volatile float32 VVTM_RsrvRecupPwr_kW = 0.0F;/* '<S886>/MinMax1' */
MONPRM volatile float32 VVTM_VehAcceltn_mps2 = 0.0F;/* '<S882>/Switch' */
MONPRM volatile uint8 VVTM_VehActGrPstn_enum = ((uint8)0U);/* '<S877>/Switch1' */
MONPRM volatile float32 VVTM_VehSpd_kph = 0.0F;/* '<S878>/Switch' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
