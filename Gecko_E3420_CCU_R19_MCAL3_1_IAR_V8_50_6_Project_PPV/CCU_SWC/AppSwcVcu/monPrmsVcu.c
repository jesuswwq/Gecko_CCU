/*
 * File: monPrmsVcu.c
 *
 * Code generated for Simulink model 'AppSwcVcu'.
 *
 * Model version                  : 9.746
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Feb 20 15:34:25 2025
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
MONPRM volatile boolean BSW_RTCWakeup_flg = false;/* '<S290>/Switch4' */

/* RTC唤醒标志位_versteckt */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Day = ((uint8)0U);/* '<S988>/Data Type Conversion45' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Hour = ((uint8)0U);/* '<S988>/Data Type Conversion1' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Min = ((uint8)0U);/* '<S988>/Data Type Conversion2' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Month = ((uint8)0U);/* '<S988>/Data Type Conversion34' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Sec = ((uint8)0U);/* '<S988>/Switch2' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Year = ((uint8)0U);/* '<S988>/Data Type Conversion33' */
MONPRM volatile boolean VBSW_ECURst_flg = false;/* '<S11>/Relational Operator3' */
MONPRM volatile boolean VBSW_F1B1PwrOffReq_flg = false;/* '<S15>/Chart' */

/* F1B1请求下高压 */
MONPRM volatile boolean VBSW_F1B1PwrOnReq_flg = false;/* '<S14>/Chart' */

/* F1B1请求上高压 */
MONPRM volatile boolean VBSW_NetWorkWakeup_flg = false;/* '<S7>/Relational Operator17' */
MONPRM volatile uint16 VBSW_RTCWupRmningT_min = ((uint16)0U);/* '<S11>/Data Type Conversion1' */

/* RTC唤醒剩余时间 */
MONPRM volatile uint8 VBSW_RoutineF1B1_enum = ((uint8)0U);/* '<S7>/Selector' */

/* F1B1例程控制 */
MONPRM volatile boolean VBSW_SrvClrDTCReq_flg = false;/* '<S7>/Relational Operator4' */
MONPRM volatile uint8 VBSW_WakeupReasn_enum = ((uint8)0U);/* '<S11>/Data Type Conversion2' */
MONPRM volatile float32 VCPT_MotorDrgMaxTq_Nm = 0.0F;/* '<S558>/MinMax6' */
MONPRM volatile float32 VCPT_MotorDrvMaxTq_Nm = 0.0F;/* '<S558>/MinMax7' */
MONPRM volatile float32 VCPT_MotorGenMaxTq_Nm = 0.0F;/* '<S570>/Switch1' */
MONPRM volatile float32 VCPT_MotorMotMaxTq_Nm = 0.0F;/* '<S569>/Switch1' */
MONPRM volatile boolean VCPT_MotorSpdRvrs_flg = false;/* '<S558>/Switch3' */
MONPRM volatile float32 VCPT_MotorSpd_rpm = 0.0F;/* '<S564>/Switch' */
MONPRM volatile float32 VCPT_WhlDrgMaxTq_Nm = 0.0F;/* '<S558>/MinMax1' */
MONPRM volatile float32 VCPT_WhlDrvMaxTq_Nm = 0.0F;/* '<S558>/MinMax8' */
MONPRM volatile boolean VDAC_ACCAvail_flg = false;/* '<S579>/Logical Operator9' */
MONPRM volatile float32 VDAC_ACCDeltaAcceltn_mps2 = 0.0F;/* '<S586>/Add5' */
MONPRM volatile float32 VDAC_ACCDsrdTqFF_Nm = 0.0F;/* '<S586>/Add3' */
MONPRM volatile float32 VDAC_ACCDsrdTqI_N = 0.0F;/* '<S586>/Saturation1' */
MONPRM volatile float32 VDAC_ACCDsrdTqPID_Nm = 0.0F;/* '<S586>/Product6' */
MONPRM volatile float32 VDAC_ACCDsrdTqP_N = 0.0F;/* '<S586>/Product3' */
MONPRM volatile boolean VDAC_ACCEnbl_flg = false;/* '<S579>/Logical Operator3' */
MONPRM volatile boolean VDAC_ACCOvrd_flg = false;/* '<S580>/Logical Operator22' */
MONPRM volatile uint8 VDAC_ACCStat_enum = ((uint8)0U);/* '<S581>/Switch1' */
MONPRM volatile float32 VDAC_ACCTqReqWhl_Nm = 0.0F;/* '<S582>/Merge3' */
MONPRM volatile boolean VDAC_CCActv2Stby_flg = false;/* '<S626>/Logical Operator15' */
MONPRM volatile boolean VDAC_CCActvBascCond_flg = false;/* '<S626>/Logical Operator1' */
MONPRM volatile float32 VDAC_CCDeltaAcceltn_mps2 = 0.0F;/* '<S613>/Add3' */
MONPRM volatile float32 VDAC_CCDsrdAcceltnRaw_mps2 = 0.0F;/* '<S606>/Saturation1' */
MONPRM volatile float32 VDAC_CCDsrdAcceltn_mps2 = 0.0F;/* '<S604>/Merge1' */
MONPRM volatile float32 VDAC_CCDsrdTqFF_N = 0.0F;/* '<S612>/Add3' */
MONPRM volatile float32 VDAC_CCDsrdTqI_N = 0.0F;/* '<S613>/Saturation1' */
MONPRM volatile float32 VDAC_CCDsrdTqPID_N = 0.0F;/* '<S613>/Add2' */
MONPRM volatile float32 VDAC_CCDsrdTqP_N = 0.0F;/* '<S613>/Product2' */
MONPRM volatile boolean VDAC_CCEnbl_flg = false;/* '<S627>/Logical Operator2' */
MONPRM volatile uint16 VDAC_CCNoActvCond_enum = ((uint16)0U);/* '<S629>/Add' */
MONPRM volatile boolean VDAC_CCOvrd_flg = false;/* '<S600>/Logical Operator22' */
MONPRM volatile uint16 VDAC_CCQuitCond_enum = ((uint16)0U);/* '<S630>/Add' */
MONPRM volatile float32 VDAC_CCSpdUnstabTm_s = 0.0F;/* '<S642>/Saturation' */
MONPRM volatile boolean VDAC_CCSpdUnstab_flg = false;/* '<S642>/Relational Operator8' */
MONPRM volatile EnumCCState VDAC_CCSt_enum = EnumCCState_Off;/* '<S601>/CC_State_Chart' */
MONPRM volatile boolean VDAC_CCStby2Actv_flg = false;/* '<S626>/Logical Operator9' */
MONPRM volatile float32 VDAC_CCTgtSpdCtrl_kph = 0.0F;/* '<S651>/Switch1' */
MONPRM volatile uint8 VDAC_CCTgtSpdHU_kph = ((uint8)0U);/* '<S602>/TgtSpdCalc' */
MONPRM volatile EnumCCTgtSpdSt VDAC_CCTgtSpdSt_enum = EnumCCTgtSpdSt_Reset;/* '<S602>/TgtSpdCalc' */
MONPRM volatile float32 VDAC_CCTgtSpd_kph = 0.0F;/* '<S602>/MinMax7' */
MONPRM volatile float32 VDAC_CCTqReqWhl_Nm = 0.0F;/* '<S605>/Merge2' */
MONPRM volatile float32 VDAC_CCVehSpdNonDrvn_kph = 0.0F;/* '<S608>/Switch' */
MONPRM volatile boolean VDAC_CruzCncl_flg = false;/* '<S667>/Chart' */
MONPRM volatile EnumCruiseStatus VDAC_CruzCtrlStat_enum =
  EnumCruiseStatus_NormOff;            /* '<S600>/Switch2' */
MONPRM volatile boolean VDAC_CruzCtrlSwVld_flg = false;/* '<S603>/Signal Conversion1' */
MONPRM volatile boolean VDAC_CruzOn_flg = true;/* '<S603>/Signal Conversion2' */
MONPRM volatile boolean VDAC_CruzRsmActv_flg = false;/* '<S664>/Switch4' */
MONPRM volatile boolean VDAC_CruzSetActv_flg = false;/* '<S662>/Switch4' */
MONPRM volatile boolean VDAC_CruzSpdDecActv_flg = false;/* '<S663>/Switch4' */
MONPRM volatile boolean VDAC_CruzSpdIncActv_flg = false;/* '<S665>/Switch4' */
MONPRM volatile float32 VDAC_DrvAsstTqSplitEHB_Nm = 0.0F;/* '<S575>/MinMax2' */
MONPRM volatile float32 VDAC_DrvAsstTqSplitINV_Nm = 0.0F;/* '<S575>/Add1' */
MONPRM volatile uint8 VDAC_DrvAsstTqSts_enum = ((uint8)0U);/* '<S575>/Switch1' */
MONPRM volatile float32 VDAC_DrvAsstTqTgt_Nm = 0.0F;/* '<S575>/Switch2' */
MONPRM volatile boolean VDAC_EnblEHBBrkRun_flg = false;/* '<S698>/Switch4' */
MONPRM volatile boolean VDAC_HDCActv2Idle_flg = false;/* '<S674>/Logical Operator11' */
MONPRM volatile boolean VDAC_HDCActv2Stdby_flg = false;/* '<S674>/Logical Operator8' */
MONPRM volatile float32 VDAC_HDCDeltaAcceltn_mps2 = 0.0F;/* '<S679>/Add5' */
MONPRM volatile float32 VDAC_HDCDsrdTqFF_Nm = 0.0F;/* '<S679>/Add3' */
MONPRM volatile float32 VDAC_HDCDsrdTqI_N = 0.0F;/* '<S679>/Saturation1' */
MONPRM volatile float32 VDAC_HDCDsrdTqPID_Nm = 0.0F;/* '<S679>/Product6' */
MONPRM volatile float32 VDAC_HDCDsrdTqP_N = 0.0F;/* '<S679>/Product3' */
MONPRM volatile boolean VDAC_HDCIdle2Stdby_flg = false;/* '<S674>/Logical Operator2' */
MONPRM volatile EnumHDCState VDAC_HDCSt_enum = EnumHDCState_Idle;/* '<S573>/HDC_State_Chart' */
MONPRM volatile boolean VDAC_HDCStdby2Actv_flg = false;/* '<S674>/Logical Operator13' */
MONPRM volatile boolean VDAC_HDCStdby2Idle_flg = false;/* '<S674>/Logical Operator3' */
MONPRM volatile float32 VDAC_HDCTgtAcceltn_mps2 = 0.0F;/* '<S671>/Merge1' */
MONPRM volatile float32 VDAC_HDCTgtSpd_kph = 0.0F;/* '<S573>/HDC_State_Chart' */
MONPRM volatile float32 VDAC_HDCTqReqWhl_Nm = 0.0F;/* '<S671>/Merge2' */
MONPRM volatile uint8 VDAC_HDCVehSpdHU_kph = ((uint8)0U);/* '<S672>/Switch1' */
MONPRM volatile float32 VDAC_MstrCylPresrReq_bar = 0.0F;/* '<S575>/Switch13' */
MONPRM volatile uint8 VDAC_VehSpdHU_kph = ((uint8)0U);/* '<S653>/Switch1' */
MONPRM volatile uint8 VDAC_VirtAccPedPstnSta_enum = ((uint8)0U);/* '<S575>/Switch11' */
MONPRM volatile float32 VDAC_VirtAccPedPstn_pct = 0.0F;/* '<S575>/Switch8' */
MONPRM volatile float32 VDAC_VirtAccelPedPstnRaw_pct = 0.0F;/* '<S575>/Switch9' */
MONPRM volatile float32 VDAC_VirtPedPstn_pct = 0.0F;/* '<S575>/Switch4' */
MONPRM volatile uint8 VDAG_ACCMHVILFltSt_enum = ((uint8)0U);/* '<S1471>/FltStDeb' */

/* 压缩机高压互锁故障状态 */
MONPRM volatile uint8 VDAG_ACChrgStFailFltSt_enum = ((uint8)0U);/* '<S1303>/FltStDeb' */

/* ACChargeStateFail故障状态 */
MONPRM volatile uint8 VDAG_ACDchaBMSPwrLoFltSt_enum = ((uint8)0U);/* '<S1309>/FltStDeb' */

/* AC放电BMS功率低故障状态 */
MONPRM volatile uint8 VDAG_ACDchaBMSSOCLoFltSt_enum = ((uint8)0U);/* '<S1308>/FltStDeb' */

/* AC放电BMSSOC低故障状态 */
MONPRM volatile uint8 VDAG_ACDchaOverPwrFltSt_enum = ((uint8)0U);/* '<S1302>/FltStDeb' */

/* AC放电功率超限故障 */
MONPRM volatile uint8 VDAG_ACSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S1021>/FltStDeb' */

/* ACSCmd超时故障状态 */
MONPRM volatile uint8 VDAG_AccPed1ShtBattFltSt_enum = ((uint8)0U);/* '<S1444>/FltStDeb' */

/* 加速踏板1路短电源故障状态 */
MONPRM volatile uint8 VDAG_AccPed1ShtGndFltSt_enum = ((uint8)0U);/* '<S1441>/FltStDeb' */

/* 加速踏板1路短地故障状态 */
MONPRM volatile uint8 VDAG_AccPed1SuplyShtCircFltSt_enum = ((uint8)0U);/* '<S1442>/FltStDeb' */

/* 加速踏板1路供电短路故障状态 */
MONPRM volatile uint8 VDAG_AccPed2ShtBattFltSt_enum = ((uint8)0U);/* '<S1437>/FltStDeb' */

/* 加速踏板2路短电源故障状态 */
MONPRM volatile uint8 VDAG_AccPed2ShtGndFltSt_enum = ((uint8)0U);/* '<S1445>/FltStDeb' */

/* 加速踏板2路短地故障状态 */
MONPRM volatile uint8 VDAG_AccPed2SuplyShtCircFltSt_enum = ((uint8)0U);/* '<S1443>/FltStDeb' */

/* 加速踏板2路供电短路故障状态 */
MONPRM volatile uint8 VDAG_AccPedBothFailFltSt_enum = ((uint8)0U);/* '<S1439>/FltStDeb' */

/* 加速踏板双路失效故障状态 */
MONPRM volatile uint8 VDAG_AccPedCrsChkFltSt_enum = ((uint8)0U);/* '<S1438>/FltStDeb' */

/* 加速踏板相互校验故障状态 */
MONPRM volatile uint8 VDAG_BMSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S1015>/FltStDeb' */

/* BMS继电器指令响应超时故障状态 */
MONPRM volatile uint8 VDAG_BMSEmgcySdnFltSt_enum = ((uint8)0U);/* '<S1026>/FltStDeb' */

/* BMS紧急下电故障状态 */
MONPRM volatile uint8 VDAG_BMSSOCLoFltSt_enum = ((uint8)0U);/* '<S1025>/FltStDeb' */

/* BMSSOC低故障状态 */
MONPRM volatile uint8 VDAG_BMSSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S1022>/FltStDeb' */

/* BMSFailLevel1故障状态 */
MONPRM volatile uint8 VDAG_BMSSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S1023>/FltStDeb' */

/* BMSFailLevel2故障状态 */
MONPRM volatile uint8 VDAG_BMSSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S1024>/FltStDeb' */

/* BMSFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_BMSUndrVoltFltSt_enum = ((uint8)0U);/* '<S1027>/FltStDeb' */

/* BMSPack欠压故障状态 */
MONPRM volatile uint8 VDAG_BrkPedShtBattFltSt_enum = ((uint8)0U);/* '<S1468>/FltStDeb' */

/* 制动踏板短电源故障状态 */
MONPRM volatile uint8 VDAG_BrkPedShtGndFltSt_enum = ((uint8)0U);/* '<S1466>/FltStDeb' */

/* 制动踏板短地故障状态 */
MONPRM volatile uint8 VDAG_BrkSwCrsChkCnt_cnt = ((uint8)0U);/* '<S1458>/Data Type Conversion' */

/* 制动开关相互校验错误计数 */
MONPRM volatile uint8 VDAG_BrkSwCrsChkFltSt_enum = ((uint8)0U);/* '<S1467>/FltStDeb' */

/* 制动开关相互校验故障状态 */
MONPRM volatile uint8 VDAG_CellUndrVoltFltSt_enum = ((uint8)0U);/* '<S1028>/FltStDeb' */

/* BMSCell欠压故障状态 */
MONPRM volatile uint8 VDAG_DCCCmdTmOutFltSt_enum = ((uint8)0U);/* '<S1197>/FltStDeb' */

/* DCDC模式指令响应超时故障状态 */
MONPRM volatile uint8 VDAG_DCCInVoltLoFltSt_enum = ((uint8)0U);/* '<S1198>/FltStDeb' */

/* DCDC输入电压低故障状态 */
MONPRM volatile uint8 VDAG_DCCModeFltFltSt_enum = ((uint8)0U);/* '<S1196>/FltStDeb' */

/* DCDCModeFault故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S1192>/FltStDeb' */

/* DCDCFailLevel1故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S1193>/FltStDeb' */

/* DCDCFailLevel2故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S1194>/FltStDeb' */

/* DCDCFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_DCCSysFailLvl4FltSt_enum = ((uint8)0U);/* '<S1195>/FltStDeb' */

/* DCDCFailLevel4故障状态 */
MONPRM volatile uint8 VDAG_DCSChrgReqFltSt_enum = ((uint8)0U);/* '<S1019>/FltStDeb' */

/* DCSChargeRequest故障状态 */
MONPRM volatile uint8 VDAG_DCSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S1029>/FltStDeb' */

/* DCSCmd超时故障状态 */
MONPRM volatile uint8 VDAG_DCSFailStaFltSt_enum = ((uint8)0U);/* '<S1017>/FltStDeb' */

/* DCSFailState故障状态 */
MONPRM volatile uint8 VDAG_DCSInletConnectFltSt_enum = ((uint8)0U);/* '<S1018>/FltStDeb' */

/* DCS插枪故障状态 */
MONPRM volatile uint8 VDAG_DCSModeFailFltSt_enum = ((uint8)0U);/* '<S1020>/FltStDeb' */

/* DCSModeFail故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl1FltSt_enum = ((uint8)0U);/* '<S1375>/FltStDeb' */

/* EHB1级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl2FltSt_enum = ((uint8)0U);/* '<S1376>/FltStDeb' */

/* EHB2级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl3FltSt_enum = ((uint8)0U);/* '<S1377>/FltStDeb' */

/* EHB3级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl4FltSt_enum = ((uint8)0U);/* '<S1369>/FltStDeb' */

/* EHB4级故障状态 */
MONPRM volatile uint8 VDAG_EHBFltLvl5FltSt_enum = ((uint8)0U);/* '<S1378>/FltStDeb' */

/* EHB5级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl1FltSt_enum = ((uint8)0U);/* '<S1380>/FltStDeb' */

/* ESC1级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl2FltSt_enum = ((uint8)0U);/* '<S1370>/FltStDeb' */

/* ESC2级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl3FltSt_enum = ((uint8)0U);/* '<S1371>/FltStDeb' */

/* ESC3级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl4FltSt_enum = ((uint8)0U);/* '<S1379>/FltStDeb' */

/* ESC4级故障状态 */
MONPRM volatile uint8 VDAG_ESCFltLvl5FltSt_enum = ((uint8)0U);/* '<S1372>/FltStDeb' */

/* ESC5级故障状态 */
MONPRM volatile uint8 VDAG_ESCVehSpdInvldFltSt_enum = ((uint8)0U);/* '<S1374>/FltStDeb' */

/* 车速失效故障状态 */
MONPRM volatile boolean VDAG_EmgcyShtdwn_flg = false;/* '<S979>/Switch30' */
MONPRM volatile uint16 VDAG_ErrCode_enum = ((uint16)0U);/* '<S977>/Err_State' */
MONPRM volatile boolean VDAG_FanFullSpdOn_flg = false;/* '<S979>/Switch3' */
MONPRM volatile boolean VDAG_FbdACC_flg = false;/* '<S979>/Switch28' */
MONPRM volatile boolean VDAG_FbdACChrg_flg = false;/* '<S979>/Switch32' */
MONPRM volatile boolean VDAG_FbdACDcha_flg = false;/* '<S979>/Switch34' */
MONPRM volatile boolean VDAG_FbdAC_flg = false;/* '<S979>/Switch35' */
MONPRM volatile boolean VDAG_FbdCC_flg = false;/* '<S979>/Switch26' */
MONPRM volatile boolean VDAG_FbdDCChrg_flg = false;/* '<S979>/Switch33' */
MONPRM volatile boolean VDAG_FbdDCDC_flg = false;/* '<S979>/Switch31' */
MONPRM volatile boolean VDAG_FbdDRGr_flg = false;/* '<S979>/Switch25' */
MONPRM volatile boolean VDAG_FbdDrvTq_flg = false;/* '<S979>/Switch23' */
MONPRM volatile boolean VDAG_FbdHV_flg = false;/* '<S979>/Switch29' */
MONPRM volatile boolean VDAG_FbdLSP_flg = false;/* '<S979>/Switch27' */
MONPRM volatile boolean VDAG_FltLampOn_flg = false;/* '<S979>/Switch36' */
MONPRM volatile uint8 VDAG_FltLvl_enum = ((uint8)0U);/* '<S979>/MinMax' */
MONPRM volatile uint8 VDAG_FrstHVILVoltHiFltSt_enum = ((uint8)0U);/* '<S1470>/FltStDeb' */

/* 主要高压互锁电压高故障状态 */
MONPRM volatile uint8 VDAG_FrstHVILVoltLoFltSt_enum = ((uint8)0U);/* '<S1469>/FltStDeb' */

/* 主要高压互锁电压低故障状态 */
MONPRM volatile uint8 VDAG_GearShftInvldFltSt_enum = ((uint8)0U);/* '<S1373>/FltStDeb' */

/* 换挡输入失效故障状态 */
MONPRM volatile uint8 VDAG_HVIsoResistLoFltSt_enum = ((uint8)0U);/* '<S1016>/FltStDeb' */

/* 高压电池绝缘故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl1FltSt_enum = ((uint8)0U);/* '<S1269>/FltStDeb' */

/* INVFaultLevel1故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl2FltSt_enum = ((uint8)0U);/* '<S1270>/FltStDeb' */

/* INVFaultLevel2故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl3FltSt_enum = ((uint8)0U);/* '<S1271>/FltStDeb' */

/* INVFaultLevel3故障状态 */
MONPRM volatile uint8 VDAG_INVFltLvl4FltSt_enum = ((uint8)0U);/* '<S1272>/FltStDeb' */

/* INVFaultLevel4故障状态 */
MONPRM volatile uint8 VDAG_INVInVoltLoFltSt_enum = ((uint8)0U);/* '<S1199>/FltStDeb' */

/* INV输入电压低故障状态 */
MONPRM volatile uint8 VDAG_INVRunCmdRespFltSt_enum = ((uint8)0U);/* '<S1273>/FltStDeb' */

/* INVRun指令响应超时故障状态 */
MONPRM volatile boolean VDAG_LVBatLampOn_flg = false;/* '<S979>/Switch1' */
MONPRM volatile uint8 VDAG_LVBattSOCLoFltSt_enum = ((uint8)0U);/* '<S1417>/FltStDeb' */

/* 蓄电池SOC低的故障状态 */
MONPRM volatile uint8 VDAG_LVBattSOHLoFltSt_enum = ((uint8)0U);/* '<S1413>/FltStDeb' */

/* 蓄电池SOH低的故障状态 */
MONPRM volatile uint8 VDAG_LVBattTempHiFltSt_enum = ((uint8)0U);/* '<S1414>/FltStDeb' */

/* 蓄电池过温故障状态 */
MONPRM volatile uint8 VDAG_LVBattVoltHiFltSt_enum = ((uint8)0U);/* '<S1416>/FltStDeb' */

/* 蓄电池电压高故障状态 */
MONPRM volatile uint8 VDAG_LVBattVoltLoFltSt_enum = ((uint8)0U);/* '<S1415>/FltStDeb' */

/* 蓄电池电压低故障状态 */
MONPRM volatile boolean VDAG_LimpHome_flg = false;/* '<S979>/Switch2' */
MONPRM volatile boolean VDAG_LmtDrvTq_flg = false;/* '<S979>/Switch24' */
MONPRM volatile uint8 VDAG_OBCChrgReqFltSt_enum = ((uint8)0U);/* '<S1307>/FltStDeb' */

/* OBCChargeRequest故障状态 */
MONPRM volatile uint8 VDAG_OBCConnectTmOutFltSt_enum = ((uint8)0U);/* '<S1305>/FltStDeb' */

/* OBC连接超时故障状态 */
MONPRM volatile uint8 VDAG_OBCInletConnectFltSt_enum = ((uint8)0U);/* '<S1310>/FltStDeb' */

/* OBC插枪故障状态 */
MONPRM volatile uint8 VDAG_OBCModeMsmtchFltSt_enum = ((uint8)0U);/* '<S1304>/FltStDeb' */

/* OBC模式不匹配故障状态 */
MONPRM volatile uint8 VDAG_OBCS2StatFltSt_enum = ((uint8)0U);/* '<S1306>/FltStDeb' */

/* OBCS2连接超时故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S1311>/FltStDeb' */

/* OBCFailLevel1故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S1312>/FltStDeb' */

/* OBCFailLevel2故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S1313>/FltStDeb' */

/* OBCFailLevel3故障状态 */
MONPRM volatile uint8 VDAG_OBCSysFailLvl4FltSt_enum = ((uint8)0U);/* '<S1301>/FltStDeb' */

/* OBCFailLevel4故障状态 */
MONPRM volatile uint8 VDAG_SecdHVILVoltHiFltSt_enum = ((uint8)0U);/* '<S1473>/FltStDeb' */

/* 次要高压互锁电压高故障状态 */
MONPRM volatile uint8 VDAG_SecdHVILVoltLoFltSt_enum = ((uint8)0U);/* '<S1472>/FltStDeb' */

/* 次要高压互锁电压低故障状态 */
MONPRM volatile uint8 VDAG_SysPwrModeInvldFltSt_enum = ((uint8)0U);/* '<S1367>/FltStDeb' */

/* PowerMode失效故障状态 */
MONPRM volatile uint8 VDAG_TMSFailLvl3FltSt_enum = ((uint8)0U);/* '<S1368>/FltStDeb' */

/* TMSRFailLevel3故障状态 */
MONPRM volatile boolean VDAG_TMSbPwrHVPart_flg = false;/* '<S978>/Signal Conversion1' */

/* TMS唤醒PTC和ACCM */
MONPRM volatile uint8 VDAG_VehCrashFltSt_enum = ((uint8)0U);/* '<S1436>/FltStDeb' */

/* 碰撞故障状态 */
MONPRM volatile uint8 VDAG_WaterTempAbvThrFltSt_enum = ((uint8)0U);/* '<S1504>/FltStDeb' */

/* 冷却水温过高故障状态 */
MONPRM volatile uint8 VDAG_WaterTempBlwThrFltSt_enum = ((uint8)0U);/* '<S1503>/FltStDeb' */

/* 冷却水温过低故障状态 */
MONPRM volatile float32 VDSA_AcceltnIdxAvg_pct = 0.0F;/* '<S75>/AvgAcceltnIdx' */
MONPRM volatile float32 VDSA_AcceltnIdxRaw_pct = 0.0F;/* '<S75>/Saturation1' */
MONPRM volatile float32 VDSA_BrkPedPstnAvg_pct = 0.0F;/* '<S75>/AvgBrkPedPstn' */
MONPRM volatile float32 VDSA_DrvSprtIdx_pct = 0.0F;/* '<S75>/Saturation2' */
MONPRM volatile boolean VDSA_SprtIdxHldAcc_flg = false;/* '<S75>/Logical Operator3' */
MONPRM volatile boolean VDSA_SprtIdxHldBrk_flg = false;/* '<S75>/Logical Operator6' */
MONPRM volatile float32 VDSA_TqCalcAcceltn_mps2 = 0.0F;/* '<S75>/Divide1' */
MONPRM volatile boolean VEMS_ACCMOprtCmd_flg = false;/* '<S914>/ACCMEnble' */

/* 使能ACCM（目前未使用） */
MONPRM volatile float32 VEMS_AccPwrRaw_kW = 0.0F;/* '<S915>/MinMax4' */

/* 原始附件功率（ACCM、PTC和DCC） */
MONPRM volatile boolean VEMS_CellTempLo_flg = false;/* '<S915>/Relational Operator6' */

/* 电芯低温标志位 */
MONPRM volatile float32 VEMS_CellTempSyn_C = 0.0F;/* '<S973>/Switch1' */

/* 电芯温度限幅 */
MONPRM volatile float32 VEMS_CellUndrVoltDrtFac_c = 0.0F;/* '<S912>/Saturation3' */

/* 放电单体开环电压修正系数（欠压兜底阀值） */
MONPRM volatile float32 VEMS_ChrgCurFbKi_A = 0.0F;/* '<S970>/Saturation' */

/* 回收单体电压闭环I项 */
MONPRM volatile float32 VEMS_ChrgCurFbKp_A = 0.0F;/* '<S970>/Product2' */

/* 回收单体电压闭环P项 */
MONPRM volatile float32 VEMS_ChrgCurFb_A = 0.0F;/* '<S970>/Saturation2' */

/* 回收单体电压闭环P项+I项 */
MONPRM volatile float32 VEMS_ChrgOvrshtPwr_kW = 0.0F;/* '<S911>/Add1' */

/* 回收功率闭环差值  VEMS_MaxChrgPwr_kW-VEMS_HVBatPwrAct_kW */
MONPRM volatile float32 VEMS_ChrgPwrFbKi_kW = 0.0F;/* '<S931>/Saturation' */

/* 回收功率闭环I项 */
MONPRM volatile float32 VEMS_ChrgPwrFbKp_kW = 0.0F;/* '<S931>/Product2' */

/* 回收功率闭环P项 */
MONPRM volatile float32 VEMS_ChrgPwrFb_kW = 0.0F;/* '<S911>/Merge' */

/* 回收功率闭环P项+I项 */
MONPRM volatile float32 VEMS_DchaCurFbKi_A = 0.0F;/* '<S971>/Saturation' */

/* 放电单体电压闭环I项 */
MONPRM volatile float32 VEMS_DchaCurFbKp_A = 0.0F;/* '<S971>/Product2' */

/* 放电单体电压闭环P项 */
MONPRM volatile float32 VEMS_DchaCurFb_A = 0.0F;/* '<S971>/Saturation2' */

/* 放电单体电压闭环P项+I项 */
MONPRM volatile float32 VEMS_DchaOvrshtPwr_kW = 0.0F;/* '<S913>/Add1' */

/* 放电功率闭环差值  VEMS_MaxDchaPwr_kW-VEMS_HVBatPwrAct_kW */
MONPRM volatile float32 VEMS_DchaPwrFbKi_kW = 0.0F;/* '<S950>/Saturation' */

/* 放电功率闭环I项 */
MONPRM volatile float32 VEMS_DchaPwrFbKp_kW = 0.0F;/* '<S950>/Product2' */

/* 放电功率闭环P项 */
MONPRM volatile float32 VEMS_DchaPwrFb_kW = 0.0F;/* '<S913>/Merge' */

/* 放电功率闭环P项+I项 */
MONPRM volatile float32 VEMS_HVBatPwrAct_kW = 0.0F;/* '<S915>/Gain1' */

/* 实际母线功率 */
MONPRM volatile float32 VEMS_MaxChrgCur_A = 0.0F;/* '<S910>/Saturation4' */

/* 回收最大允许电流 （瞬时/持续电流切换）*VEMS_CellOverVoltDrtFac_c */
MONPRM volatile float32 VEMS_MaxChrgPwr2MotRaw_kW = 0.0F;/* '<S910>/Add7' */

/* 电机回收最大原始功率  VEMS_MaxChrgPwr_kW（滤波）-VEMS_AccPwrRaw_kW（滤波） */
MONPRM volatile float32 VEMS_MaxChrgPwr2Mot_kW = 0.0F;/* '<S911>/Switch' */

/* 电机回收最大功率 VEMS_MaxChrgPwr2MotRaw_kW+VEMS_ChrgPwrFb_kW */
MONPRM volatile float32 VEMS_MaxChrgPwr_kW = 0.0F;/* '<S910>/Product2' */

/* 回收最大允许功率 VEMS_MaxChrgCur_A*VIPM_BMSHVBatActVolt_V */
MONPRM volatile float32 VEMS_MaxConChrgCur_A = 0.0F;/* '<S910>/MinMax1' */

/* 回收持续电流限制 min{VEMS_MaxConChrgVoltCls_A-偏移电流,查表电流} */
MONPRM volatile float32 VEMS_MaxConChrgVoltCls_A = 0.0F;/* '<S915>/Saturation4' */

/* 回收单体电压闭环持续修正电流（VIPM_BMSMaxConChrgCurnt_A+VEMS_ChrgCurFb_A） */
MONPRM volatile float32 VEMS_MaxConDchaCur_A = 0.0F;/* '<S912>/MinMax1' */

/* 放电持续电流限制 min{VEMS_MaxConDchaVoltCls_A-偏移电流,查表电流} */
MONPRM volatile float32 VEMS_MaxConDchaVoltCls_A = 0.0F;/* '<S915>/Saturation2' */

/* 放电单体电压闭环持续修正电流（VIPM_BMSMaxConDisCurnt_A+VEMS_DchaCurFb_A） */
MONPRM volatile float32 VEMS_MaxDchaCur_A = 0.0F;/* '<S912>/Saturation4' */

/* 放电最大允许电流 （瞬时/持续电流切换）*VEMS_CellUndrVoltDrtFac_c */
MONPRM volatile float32 VEMS_MaxDchaPwr2MotRaw_kW = 0.0F;/* '<S912>/Add7' */

/* 电机放电最大原始功率  VEMS_MaxDchaPwr_kW（滤波）-VEMS_AccPwrRaw_kW（滤波） */
MONPRM volatile float32 VEMS_MaxDchaPwr2Mot_kW = 0.0F;/* '<S913>/Switch' */

/* 电机放电最大功率 VEMS_MaxDchaPwr2MotRaw_kW+VEMS_DchaPwrFb_kW */
MONPRM volatile float32 VEMS_MaxDchaPwr_kW = 0.0F;/* '<S912>/Product2' */

/* 放电最大允许功率  VEMS_MaxDchaCur_A*VIPM_BMSHVBatActVolt_V */
MONPRM volatile float32 VEMS_MaxInsChrgCur_A = 0.0F;/* '<S910>/MinMax3' */

/* 回收瞬时电流限制 min{VEMS_MaxInsChrgVoltCls_A-偏移电流,查表电流} */
MONPRM volatile float32 VEMS_MaxInsChrgVoltCls_A = 0.0F;/* '<S915>/Saturation3' */

/* 回收单体电压闭环瞬时修正电流（VIPM_BMSMaxInsChrgCurnt_A+VEMS_ChrgCurFb_A） */
MONPRM volatile float32 VEMS_MaxInsDchaCur_A = 0.0F;/* '<S912>/MinMax3' */

/* 放电瞬时电流限制 min{VEMS_MaxInsDchaVoltCls_A-偏移电流,查表电流} */
MONPRM volatile float32 VEMS_MaxInsDchaVoltCls_A = 0.0F;/* '<S915>/Saturation1' */

/* 放电单体电压闭环瞬时修正电流（VIPM_BMSMaxInsDisCurnt_A+VEMS_DchaCurFb_A） */
MONPRM volatile boolean VEMS_TMSActSOCEnbl_flg = false;/* '<S967>/Switch1' */

/* SOC限制TMS（放电） */
MONPRM volatile boolean VEMS_TMSPwrEnbl_flg = false;/* '<S914>/Switch3' */

/* 功率限制TMS（充电+放电） */
MONPRM volatile float32 VEMS_TMSUsePwrRaw_kW = 0.0F;/* '<S914>/Subtract' */

/* TMS原始可用功率（BMS持续功率（VEMS_MaxConDchaVoltCls_A*VIPM_BMSHVBatActVolt_V）-DCDC实际功率） */
MONPRM volatile float32 VEMS_TMSUsePwr_kW = 0.0F;/* '<S914>/Switch2' */

/* TMS限制后可用功率(故障条件、TBOX远程、纯加热模式、SOC限制) */
MONPRM volatile boolean VEMS_UseConChrgCur_flg = false;/* '<S921>/Switch4' */

/* 使用持续回收电流标志位 */
MONPRM volatile boolean VEMS_UseConDchaCur_flg = false;/* '<S940>/Switch4' */

/* 使用持续放电电流标志位 */
MONPRM volatile boolean VGSM_AsstDrvFbShft_flg = false;/* '<S1714>/Logical Operator2' */

/* 规范：ACC/CC禁止档位解析 */
MONPRM volatile boolean VGSM_AsstDrvReqEPB_flg = false;/* '<S1700>/Switch4' */

/* ACC通讯丢失或故障拉起EPB */
MONPRM volatile boolean VGSM_DRFlt2N_flg = false;/* '<S1713>/Switch1' */

/* 规范：退至非驱动档标志位 */
MONPRM volatile boolean VGSM_EPBAplyFlt_flg = false;/* '<S1690>/EPBLogical' */

/* 故障P-EPB拉起故障 */
MONPRM volatile boolean VGSM_EPBRelsFlt_flg = false;/* '<S1690>/EPBLogical' */

/* 故障P-EPB释放故障 */
MONPRM volatile boolean VGSM_GrD2PExcdTm_flg = false;/* '<S1868>/Chart' */

/* D档入P请求超时入N */
MONPRM volatile boolean VGSM_GrNReq2P_flg = false;/* '<S1713>/Switch2' */

/* N档非换挡请求进P档请求 */
MONPRM volatile boolean VGSM_GrR2PExcdTm_flg = false;/* '<S1865>/Chart' */

/* R档入P请求超时入N */
MONPRM volatile boolean VGSM_HldGearP_flg = false;/* '<S1713>/Switch' */

/* 规范：保持P档标志位 */
MONPRM volatile boolean VGSM_INVRunEnbl_flg = false;/* '<S1716>/Chart' */

/* 规范：INV使能控制（允许扭矩控制）-VCU_1_EnaInvRun */
MONPRM volatile uint8 VGSM_PGrSwSts_enum = ((uint8)0U);/* '<S1714>/Switch2' */

/* 规范：P按键触发标志位-VCU_PGearSwcst */
MONPRM volatile boolean VGSM_ReqEPBAply_flg = false;/* '<S1715>/Logical Operator6' */

/* 规范：EPB拉起请求标志位 */
MONPRM volatile boolean VGSM_ReqEPBRels_flg = false;/* '<S1715>/Logical Operator4' */

/* 规范：EPB释放请求标志位 */
MONPRM volatile EnumEPBReq VGSM_ReqEPB_enum = EnumEPBReq_NoCmd;/* '<S1690>/Switch' */

/* 规范：EPB操作信号-VCUF_ReqEPB */
MONPRM volatile EnumTgtGearPstn VGSM_ShftTgtGrReq_enum = EnumTgtGearPstn_NoReq;/* '<S1714>/Data Type Conversion1' */

/* 换挡杆目标档位 0-NoCmd 1-P 2-N 3-D 4-R  */
MONPRM volatile EnumGearPstn VGSM_VehActGearPstn_enum = EnumGearPstn_P;/* '<S1691>/Switch1' */

/* 规范：实际档位-VCU_VhclActlGearPos */
MONPRM volatile boolean VGSM_VehEPBStErr_flg = false;/* '<S1690>/Logical Operator' */

/* 规范：P档故障PGear error-VCU_VhclPGearError */
MONPRM volatile EnumTgtGearPstn VGSM_VehTgtGrReq_enum = EnumTgtGearPstn_NoReq;/* '<S1715>/Data Type Conversion1' */

/* 规范:目标档位 */
MONPRM volatile uint8 VGSM_VehTgtGrTrnsfr_enum = ((uint8)0U);/* '<S1753>/Switch' */

/* 规范：换档请求信号 */
MONPRM volatile uint8 VHMI_12VBatLowVolSta_enum = ((uint8)0U);/* '<S84>/Switch' */
MONPRM volatile float32 VHMI_GrDSldDist_m = 0.0F;/* '<S98>/Saturation' */

/* D档后溜距离 */
MONPRM volatile boolean VHMI_GrDSldSw_flg = false;/* '<S98>/Logical Operator' */

/* D档溜坡计速/距离标志 */
MONPRM volatile float32 VHMI_GrRSldDist_m = 0.0F;/* '<S98>/Saturation1' */

/* R档前溜距离 */
MONPRM volatile boolean VHMI_GrRSldSw_flg = false;/* '<S98>/Logical Operator4' */

/* R档溜坡计速/距离标志 */
MONPRM volatile uint8 VHMI_InfoDisp_enum = ((uint8)0U);/* '<S87>/Arbitration' */

/* 仪表弹窗值 */
MONPRM volatile boolean VHVM_ACChrgEnbl_flg = false;/* '<S1582>/Logical Operator8' */

/* 交流充电基本条件满足 */
MONPRM volatile uint8 VHVM_ACChrgMaxCurrFb_A = ((uint8)0U);/* '<S1552>/Switch5' */

/* HU设置电流反馈 */
MONPRM volatile uint8 VHVM_ACChrgModeFb_enum = ((uint8)0U);/* '<S1552>/Switch7' */

/* HU设置充电模式反馈 */
MONPRM volatile boolean VHVM_ACChrging2Stop_flg = false;/* '<S1576>/AND' */

/* 交流充电中转移到充电停止标志位 */
MONPRM volatile boolean VHVM_ACDchaEnbl_flg = false;/* '<S1582>/Logical Operator10' */

/* 交流放电基本条件满足 */
MONPRM volatile boolean VHVM_ACDschrging2Stop_flg = false;/* '<S1576>/AND7' */

/* 交流放电中转移到放电停止标志位 */
MONPRM volatile EnumBMSSdnCmd VHVM_BMSShutdown_enum = EnumBMSSdnCmd_Normal;/* '<S1551>/Data Type Conversion10' */

/* VCU关闭BMS指令对应CAN信号：VCU_BMS_Shutdown */
MONPRM volatile EnumBMSWakeUpMd VHVM_BMSWakeUpMode_enum = EnumBMSWakeUpMd_Invld;/* '<S1551>/Data Type Conversion8' */

/* VCU唤醒BMS的方式对应CAN信号：VCU_BMS_WakeupMode */
MONPRM volatile boolean VHVM_Bat2DrvTrainEnbl_flg = false;/* '<S1551>/MainState' */

/* VCU控制主继电器指令对应CAN信号：VCU_Bat2DrvTrainEnb */
MONPRM volatile EnumChrgAllwCmd VHVM_ChrgAllowCmd_enum =
  EnumChrgAllwCmd_NotAllwd;            /* '<S1551>/Data Type Conversion12' */

/* VCU发送允许充电指令对应CAN信号：VCU_ChrgAllowCmd */
MONPRM volatile uint8 VHVM_ChrgEnaAC_enum = ((uint8)0U);/* '<S1551>/MainState' */

/* VCU控制OBC交流充电使能指令对应CAN信号：VCU_ChrgEna_AC */
MONPRM volatile boolean VHVM_ChrgEnaDC_flg = false;/* '<S1551>/MainState' */

/* VCU控制BMS直流充电使能指令对应CAN信号：VCU_ChrgEna_DC */
MONPRM volatile float32 VHVM_DCCBuckLVVolt_V = 0.0F;/* '<S1551>/MainState' */

/* VCU控制DCDC BUCK电压值对应CAN信号：VCU_DCCBuckLV_Vol */
MONPRM volatile EnumDCCOprtCmd VHVM_DCCOprtCmd_enum = EnumDCCOprtCmd_Off;/* '<S1551>/Data Type Conversion6' */

/* VCU控制DCDC工作模式指令对应CAN信号：VCU_DCCOprtCmd */
MONPRM volatile boolean VHVM_DCChrgEnbl_flg = false;/* '<S1582>/Logical Operator2' */

/* 直流充电基本条件满足 */
MONPRM volatile boolean VHVM_DCChrging2Over_flg = false;/* '<S1576>/AND1' */

/* 直流充电中转移到充电结束标志位 */
MONPRM volatile boolean VHVM_ECUSleepAllwd_flg = false;/* '<S1551>/MainState' */

/* 允许底层休眠标志位 */
MONPRM volatile boolean VHVM_EmgcySdn_flg = false;/* '<S1551>/MainState' */

/* VCU给INV发送紧急下电指令(INV强制停机)对应CAN信号：VCU_1_EmShutDown */
MONPRM volatile boolean VHVM_EnaDisChg_flg = false;/* '<S1551>/MainState' */

/* VCU控制INV泄放指令对应CAN信号：VCU_1_EnaDisChg */
MONPRM volatile boolean VHVM_EngyExtrmLo_flg = false;/* '<S1554>/Logical Operator17' */

/* 电池能量极低标志位 */
MONPRM volatile boolean VHVM_F1B1HVOffReq_flg = false;/* '<S1581>/Logical Operator45' */

/* F1B1下电请求 */
MONPRM volatile boolean VHVM_F1B1HVOnReq_flg = false;/* '<S1582>/Logical Operator45' */

/* F1B1上电请求 */
MONPRM volatile boolean VHVM_HVRdy_flg = false;/* '<S1551>/MainState' */

/* DCDC&INV预充完成 */
MONPRM volatile boolean VHVM_INVEnbl_flg = false;/* '<S1551>/MainState' */

/* VCU硬线唤醒INV */
MONPRM volatile boolean VHVM_INVPreprogmFlg_flg = false;/* '<S1577>/Switch1' */

/* INV预编程条件满足 */
MONPRM volatile float32 VHVM_MaxChrgCurntDC_A = 0.0F;/* '<S1551>/MainState' */

/* VCU允许BMS直流充电最大电流对应CAN信号：VCU_MaxChrgCrnt_DC */
MONPRM volatile float32 VHVM_MaxChrgVoltDC_V = 0.0F;/* '<S1551>/MainState' */

/* VCU允许BMS直流充电最大电压对应CAN信号：VCU_MaxChrgVol_DC */
MONPRM volatile float32 VHVM_MaxHVDCCurntAC_A = 0.0F;/* '<S1551>/MainState' */

/* VCU允许OBC交流充电最大电流对应CAN信号：VCU_MaxHVDC_Cur_AC */
MONPRM volatile float32 VHVM_MaxHVDCVoltAC_V = 0.0F;/* '<S1551>/MainState' */

/* VCU允许OBC交流充电最大电压对应CAN信号：VCU_MaxHVDC_Vol_AC */
MONPRM volatile EnumOBCOprtCmd VHVM_OBCOprtCmd_enum = EnumOBCOprtCmd_Standby;/* '<S1552>/Data Type Conversion4' */

/* VCU控制OBC工作模式指令对应CAN信号：VCU_OBCOprtCmd */
MONPRM volatile EnumPTActMd VHVM_PTActOprtMode_enum = EnumPTActMd_OFF;/* '<S1551>/Data Type Conversion4' */

/* 高压PT状态 */
MONPRM volatile boolean VHVM_PTRdy2PTStdby_flg = false;/* '<S1579>/Switch1' */

/* PTRdy到PTStdby标志位 */
MONPRM volatile boolean VHVM_PTStdby2PTRdy_flg = false;/* '<S1579>/Switch' */

/* PTStdby到PTRdy标志位 */
MONPRM volatile boolean VHVM_PowUpSelfChek_flg = false;/* '<S1580>/Switch' */

/* 高压自检标志位 */
MONPRM volatile boolean VHVM_PwrOn2PwrDwn_flg = false;/* '<S1581>/Switch' */

/* 高压下电条件满足标志位（正常/故障/紧急） */
MONPRM volatile boolean VHVM_SOPExtrmLo_flg = false;/* '<S1554>/Relational Operator4' */

/* 电池SOP极低，用于关闭DCDC */
MONPRM volatile EnumSysSta VHVM_SysSta_enum = EnumSysSta_Sleep;/* '<S1551>/Data Type Conversion2' */

/* 高压子状态 */
MONPRM volatile EnumVCUMode VHVM_VCUMode_enum = EnumVCUMode_PwrOff;/* '<S1551>/Data Type Conversion' */

/* 高压主转态 */
MONPRM volatile boolean VHVM_VehHalt_flg = false;/* '<S1571>/Switch4' */

/* 车辆停止标志位（车速极其） */
MONPRM volatile boolean VHVM_WakeUp2PwrUpACChrg_flg = false;/* '<S1582>/Logical Operator16' */

/* 交流充电唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpACDcha_flg = false;/* '<S1582>/Logical Operator26' */

/* 交流放电唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpDCChrg_flg = false;/* '<S1582>/Logical Operator4' */

/* 直流充电唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpIBS_flg = false;/* '<S1582>/Logical Operator6' */

/* IBS唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpKL15_flg = false;/* '<S1582>/Logical Operator' */

/* K15唤醒上电 */
MONPRM volatile boolean VHVM_WakeUp2PwrUp_flg = false;/* '<S1582>/Switch' */

/* 唤醒到上高压条件满足（唤醒源上升沿+高压自检通过） */
MONPRM volatile boolean VHVM_WakeUpBMS_flg = false;/* '<S1551>/MainState' */

/* VCU硬线唤醒BMS */
MONPRM volatile boolean VHVM_WakeUpVCU_flg = false;/* '<S1583>/Switch' */

/* 休眠到唤醒条件满足 */
MONPRM volatile boolean VIBS_BMSBatSOCAllow_flg = false;/* '<S263>/Switch3' */

/* 动力电池SOC允许补电标志位_versteckt */
MONPRM volatile boolean VIBS_ChgNumAllow_flg = false;/* '<S263>/AND' */

/* 补电次数允许标志位_versteckt */
MONPRM volatile uint8 VIBS_ChgNum_cnt = ((uint8)0U);/* '<S263>/Switch2' */

/* IBS补电次数_versteckt */
MONPRM volatile boolean VIBS_ChrgBascCond_flg = false;/* '<S263>/Logical Operator2' */

/* 补电基本条件满足（补电次数及电压）_versteckt */
MONPRM volatile boolean VIBS_ChrgEnbl_flg = false;/* '<S263>/Logical Operator7' */

/* IBS充电使能标志位_versteckt */
MONPRM volatile boolean VIBS_ChrgOver_flg = false;/* '<S261>/ChrgSt' */

/* IBS补电结束标志位_versteckt */
MONPRM volatile float32 VIBS_ChrgVoltThr_V = 0.0F;/* '<S264>/VoltState' */

/* 补电电压阈值_versteckt */
MONPRM volatile float32 VIBS_EnvirTemp_C = 0.0F;/* '<S288>/Switch' */

/* IBS环境温度_versteckt */
MONPRM volatile uint8 VIBS_FailChgNum_cnt = ((uint8)0U);/* '<S263>/Switch5' */

/* IBS补电失败次数_versteckt */
MONPRM volatile boolean VIBS_FbRctWup_flg = false;/* '<S263>/Logical Operator6' */

/* IBS禁止RTC唤醒标志位_versteckt */
MONPRM volatile boolean VIBS_HVReq_flg = false;/* '<S263>/Switch' */

/* IBS请求上高压标志位_versteckt */
MONPRM volatile float32 VIBS_HwKL30_V = 0.0F;/* '<S287>/Switch' */

/* 滤波后的KL30电压_versteckt */
MONPRM volatile float32 VIBS_MustChrgVolt_V = 0.0F;/* '<S264>/MIBS_MustChrgVolt_V' */

/* 兜底电压_versteckt */
MONPRM volatile boolean VIBS_MustChrg_flg = false;/* '<S295>/Chart' */

/* 兜底电压激活标志位_versteckt */
MONPRM volatile boolean VIBS_NMReq_flg = false;/* '<S270>/Switch4' */

/* IBS请求网络标志位_versteckt */
MONPRM volatile uint16 VIBS_NextRtcWupThr_min = ((uint16)0U);/* '<S264>/Switch1' */

/* 下次补电唤醒RTC的时间_versteckt */
MONPRM volatile EnumIBSChrgSt VIBS_RTCChrgSt_enum = EnumIBSChrgSt_Idle;/* '<S261>/Data Type Conversion' */

/* IBS补电状态_versteckt */
MONPRM volatile boolean VIBS_RTCWakeup_flg = false;/* '<S296>/Chart' */

/* RTC唤醒标志位（含延迟时间）_versteckt */
MONPRM volatile boolean VIBS_SleepAllwd_flg = false;/* '<S263>/SleepAllwd' */

/* IBS允许底层休眠标志位_versteckt */
MONPRM volatile uint16 VIBS_WupChgTmThr_min = ((uint16)0U);/* '<S264>/Switch2' */

/* IBS补电时间阈值_versteckt */
MONPRM volatile boolean VIBS_WupVoltAllow_flg = false;/* '<S289>/Switch4' */

/* KL30电压允许标志位_versteckt */
MONPRM volatile boolean VIPC_ACCCfgd_flg = false;/* '<S373>/Switch8' */
MONPRM volatile boolean VIPC_AccPed1Flt_flg = false;/* '<S377>/Logical Operator1' */
MONPRM volatile boolean VIPC_AccPed1LrnDwnActv_flg = false;/* '<S387>/Relational Operator' */
MONPRM volatile boolean VIPC_AccPed1LrnUpActv_flg = false;/* '<S380>/Logical Operator5' */
MONPRM volatile float32 VIPC_AccPed1MinPstnLrnd_pct = 0.0F;/* '<S380>/Switch2' */
MONPRM volatile float32 VIPC_AccPed1NormzAvg_pct = 0.0F;/* '<S386>/Switch' */
MONPRM volatile float32 VIPC_AccPed1NormzPstn_pct = 0.0F;/* '<S377>/Switch5' */
MONPRM volatile float32 VIPC_AccPed1SclPstn_pct = 0.0F;/* '<S381>/Divide1' */
MONPRM volatile boolean VIPC_AccPed2Flt_flg = false;/* '<S377>/Logical Operator2' */
MONPRM volatile boolean VIPC_AccPed2LrnDwnActv_flg = false;/* '<S391>/Relational Operator' */
MONPRM volatile boolean VIPC_AccPed2LrnUpActv_flg = false;/* '<S382>/Logical Operator5' */
MONPRM volatile float32 VIPC_AccPed2MinPstnLrnd_pct = 0.0F;/* '<S382>/Switch2' */
MONPRM volatile float32 VIPC_AccPed2NormzAvg_pct = 0.0F;/* '<S390>/Switch' */
MONPRM volatile float32 VIPC_AccPed2NormzPstn_pct = 0.0F;/* '<S377>/Switch7' */
MONPRM volatile float32 VIPC_AccPed2SclPstn_pct = 0.0F;/* '<S383>/Divide5' */
MONPRM volatile boolean VIPC_AccPedPstnVld_flg = false;/* '<S379>/Switch3' */
MONPRM volatile float32 VIPC_AccPedPstn_pct = 0.0F;/* '<S375>/MinMax3' */
MONPRM volatile uint8 VIPC_AccPedSnsrSta_enum = ((uint8)0U);/* '<S379>/Switch3' */
MONPRM volatile boolean VIPC_AccPedStkActv_flg = false;/* '<S378>/Logical Operator6' */
MONPRM volatile boolean VIPC_AccPedStkBrkPrsd_flg = false;/* '<S405>/Switch4' */
MONPRM volatile float32 VIPC_AccPedStkPstn_pct = 0.0F;/* '<S378>/MinMax' */
MONPRM volatile boolean VIPC_AccPedStkStab_flg = false;/* '<S407>/Relational Operator' */
MONPRM volatile float32 VIPC_AccPedWghtAvg_pct = 0.0F;/* '<S404>/Switch' */
MONPRM volatile float32 VIPC_AccPedWghtPstn_pct = 0.0F;/* '<S379>/Switch3' */
MONPRM volatile float32 VIPC_AccPedZeroPstn_pct = 0.0F;/* '<S378>/Switch2' */
MONPRM volatile boolean VIPC_BrkPedPstnVld_flg = false;/* '<S370>/Logical Operator8' */
MONPRM volatile float32 VIPC_BrkPedPstn_pct = 0.0F;/* '<S370>/Saturation1' */
MONPRM volatile boolean VIPC_BrkSwActv_flg = false;/* '<S370>/Logical Operator' */
MONPRM volatile boolean VIPC_CCSCfgd_flg = false;/* '<S373>/Switch1' */
MONPRM volatile boolean VIPC_CrpCtrlCfgd_flg = false;/* '<S373>/Switch2' */
MONPRM volatile EnumCrpModeAct VIPC_CrpModeAct_enum = EnumCrpModeAct_Open;/* '<S372>/Switch12' */
MONPRM volatile EnumDrvModeAct VIPC_DrvModeAct_enum = EnumDrvModeAct_Invalid;/* '<S372>/Switch13' */
MONPRM volatile uint8 VIPC_DrvPwrIntnsty_pct = ((uint8)0U);/* '<S372>/Switch25' */
MONPRM volatile boolean VIPC_DrvSw_flg = false;/* '<S375>/Relational Operator3' */
MONPRM volatile boolean VIPC_EPBAppld_flg = false;/* '<S371>/Logical Operator2' */
MONPRM volatile boolean VIPC_EPBReld_flg = false;/* '<S371>/Logical Operator1' */
MONPRM volatile boolean VIPC_HDCCfgd_flg = false;/* '<S373>/Switch3' */
MONPRM volatile EnumRegenModeAct VIPC_RegenModeAct_enum = EnumRegenModeAct_Off;/* '<S372>/Switch15' */
MONPRM volatile uint8 VIPC_RegenPwrIntnsty_pct = ((uint8)0U);/* '<S372>/Switch28' */
MONPRM volatile boolean VIPC_SnowMode_flg = false;/* '<S372>/Switch14' */
MONPRM volatile float32 VIPC_TireRadius_m = 0.0F;/* '<S373>/TireSizeTable' */
MONPRM volatile uint8 VIPC_VehHiddenMode_enum = ((uint8)0U);/* '<S372>/VehHiddenMode' */
MONPRM volatile float32 VIPC_VehSpdDrvnMotor_kph = 0.0F;/* '<S374>/Product1' */
MONPRM volatile boolean VIPC_VehSpdDrvnVld_flg = false;/* '<S441>/Logical Operator2' */
MONPRM volatile float32 VIPC_VehSpdDrvn_kph = 0.0F;/* '<S441>/Switch7' */
MONPRM volatile boolean VIPC_VehSpdNonDrvnVld_flg = false;/* '<S442>/Logical Operator2' */
MONPRM volatile float32 VIPC_VehSpdNonDrvn_kph = 0.0F;/* '<S442>/Switch7' */
MONPRM volatile boolean VIPC_VehSpdVld_flg = false;/* '<S441>/SignalConversion' */
MONPRM volatile float32 VIPC_VehSpd_kph = 0.0F;/* '<S441>/Switch4' */
MONPRM volatile boolean VIPC_VpedAutoCrp_flg = false;/* '<S429>/Switch4' */
MONPRM volatile boolean VIPC_ZeroPstnRst_flg = false;/* '<S378>/Logical Operator3' */
MONPRM volatile boolean VIPC_iTPMSCfgd_flg = false;/* '<S373>/Switch4' */
MONPRM volatile float32 VIPM_HwAccPedCh1SuplyVolt_mV = 0.0F;/* '<S18>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh1Volt_mV = 0.0F;/* '<S19>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh2SuplyVolt_mV = 0.0F;/* '<S20>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh2Volt_mV = 0.0F;/* '<S21>/MinMax1' */
MONPRM volatile boolean VIPM_HwBMSWakeup_flg = false;/* '<S22>/Switch4' */
MONPRM volatile boolean VIPM_HwBrkSwHi_flg = false;/* '<S23>/Switch4' */
MONPRM volatile boolean VIPM_HwBrkSwLo_flg = false;/* '<S24>/Switch4' */
MONPRM volatile boolean VIPM_HwCrpModeSw_flg = false;/* '<S25>/Switch4' */
MONPRM volatile boolean VIPM_HwDrvModeSw_flg = false;/* '<S26>/Switch4' */
MONPRM volatile boolean VIPM_HwEmgcyShutOff_flg = false;/* '<S27>/Switch4' */
MONPRM volatile float32 VIPM_HwHVIL1Volt_mV = 0.0F;/* '<S28>/MinMax1' */
MONPRM volatile float32 VIPM_HwHVIL2Volt_mV = 0.0F;/* '<S29>/MinMax1' */
MONPRM volatile boolean VIPM_HwKL15A_flg = false;/* '<S30>/Switch4' */
MONPRM volatile boolean VIPM_HwKL15B_flg = false;/* '<S31>/Switch4' */
MONPRM volatile uint16 VIPM_HwKL30_mV = ((uint16)0U);/* '<S32>/MinMax1' */
MONPRM volatile boolean VIPM_HwOBCWakeup_flg = false;/* '<S33>/Switch4' */
MONPRM volatile boolean VIPM_HwRearFogLampSwt_flg = false;/* '<S34>/Switch4' */
MONPRM volatile EnumPGearSwSts VIPM_HwShftPstnSwSts_enum = EnumPGearSwSts_Reld;/* '<S35>/Switch4' */
MONPRM volatile uint16 VIPM_HwShftPstnSw_Ohm = ((uint16)0U);/* '<S8>/HwShftPstnSw' */
MONPRM volatile boolean VIPM_HwVehCrash_flg = false;/* '<S36>/Switch4' */
MONPRM volatile uint8 VNVM_ACChrgMaxCurrFb_A = ((uint8)0U);/* '<S9>/Selector18' */
MONPRM volatile uint8 VNVM_ACChrgModeFb_enum = ((uint8)0U);/* '<S9>/Selector19' */
MONPRM volatile uint8 VNVM_AccPedZeroPstn_pct = ((uint8)0U);/* '<S9>/Selector24' */
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
MONPRM volatile boolean VOPM_HwWakeupBMS_flg = false;/* '<S50>/Switch4' */
MONPRM volatile float32 VRME_AvgSOCCnsm100Num_pctpkm = 0.0F;/* '<S244>/Signal Copy5' */

/* 前100个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm10Num_pctpkm = 0.0F;/* '<S244>/Signal Copy1' */

/* 前10个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm15Num_pctpkm = 0.0F;/* '<S244>/Signal Copy2' */

/* 前15个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm25Num_pctpkm = 0.0F;/* '<S244>/Signal Copy3' */

/* 前25个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm50Num_pctpkm = 0.0F;/* '<S244>/Signal Copy4' */

/* 前50个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsm5Num_pctpkm = 0.0F;/* '<S244>/Signal Copy' */

/* 前5个数组平均SOC能耗 */
MONPRM volatile float32 VRME_AvgSOCCnsmWght_pctpkm = 0.0F;/* '<S244>/Switch1' */

/* 加权平均SOC能耗 */
MONPRM volatile boolean VRME_CHTCRmnMilEstV_flg = false;/* '<S210>/Logical Operator' */

/* CHTC标准续航里程有效性 */
MONPRM volatile float32 VRME_CHTCRmnMilEst_km = 0.0F;/* '<S210>/MRME_CHTCStdRmnMil_km' */

/* CHTC标准续航查表值 */
MONPRM volatile float32 VRME_CalPwrCnsmPerTrig_kWhptrig = 0.0F;/* '<S214>/Switch4' */

/* Pwr消耗/单位里程（trig） */
MONPRM volatile boolean VRME_CalPwrCnsmTrig_flg = false;/* '<S214>/Relational Operator1' */

/* 累计里程大于单位里程 */
MONPRM volatile float32 VRME_CalSOCCnsmDrvDist_m = 0.0F;/* '<S243>/Switch1' */

/* 单位目标行驶里程 */
MONPRM volatile float32 VRME_CalSOCCnsmPerTrig_pctptrig = 0.0F;/* '<S243>/Switch4' */

/* SOC消耗/单位里程（trig） */
MONPRM volatile float32 VRME_CalSOCCnsmPerkm_pctpkm = 0.0F;/* '<S243>/Divide' */

/* SOC消耗/单位里程（1km） */
MONPRM volatile boolean VRME_CalSOCCnsmTrig_flg = false;/* '<S243>/Relational Operator1' */

/* 累计里程大于目标里程 */
MONPRM volatile float32 VRME_ChrgRmnMilEstTgt_km = 0.0F;/* '<S239>/Switch2' */

/* 充电模式动态续航目标值 */
MONPRM volatile float32 VRME_ChrgRmnMilEst_km = 0.0F;/* '<S223>/Different Slops' */

/* 充电工况动态续航值 */
MONPRM volatile float32 VRME_ChrgTgtFstRate_kmpsoc = 0.0F;/* '<S223>/Divide2' */

/* 充电工况目标续航追击速率 */
MONPRM volatile float32 VRME_ChrgTgtNormRate_kmpsoc = 0.0F;/* '<S223>/Divide1' */

/* 充电工况目标续航变化速率 */
MONPRM volatile float32 VRME_DchaRmnMilEstChgFac_c = 0.0F;/* '<S242>/MRME_DynEstRmnChgStp_c' */

/* 非充电模式动态续航变化系数 */
MONPRM volatile float32 VRME_DchaRmnMilEstTgt_km = 0.0F;/* '<S251>/Switch2' */

/* 非充电模式动态续航目标值 */
MONPRM volatile boolean VRME_DchaRmnMilEstUpdTrig_flg = false;/* '<S242>/Relational Operator2' */

/* 更新续航值 */
MONPRM volatile float32 VRME_DchaRmnMilEst_km = 0.0F;/* '<S242>/Signal Copy1' */

/* 非充电模式动态续航值 */
MONPRM volatile boolean VRME_DchaVehStall_flg = false;/* '<S241>/Logical Operator4' */

/* 非充电模式车辆驻车状态 */
MONPRM volatile boolean VRME_DynRmnMilEstV_flg = false;/* '<S212>/Logical Operator1' */

/* 动态续航有效性 */
MONPRM volatile float32 VRME_VehPwrCnsmAvg_kWhpkm = 0.0F;/* '<S214>/Switch7' */

/* 当前循环平均能耗 */
MONPRM volatile float32 VRME_VehPwrCnsmIns_kWhpkm = 0.0F;/* '<S214>/Divide' */

/* 当前循环瞬间能耗 */
MONPRM volatile float32 VRME_VehTotMilCyc_km = 0.0F;/* '<S214>/Gain8' */

/* 当前驾驶循环车辆里程 */
MONPRM volatile float32 VRME_VehTotPwrCyc_kWh = 0.0F;/* '<S214>/Switch8' */

/* 当前驾驶循环车辆功率 */
MONPRM volatile float32 VRME_WLTPRmnMilEstDwLim_km = 0.0F;/* '<S219>/Product3' */

/* 动态续航下限值 */
MONPRM volatile float32 VRME_WLTPRmnMilEstUpLim_km = 0.0F;/* '<S219>/Product2' */

/* 动态续航上限值 */
MONPRM volatile float32 VRME_WLTPRmnMilEst_km = 0.0F;/* '<S219>/MRME_WLTPStdRmnMil_km' */

/* WLTP标准续航查表值 */
MONPRM volatile float32 VRME_WLTPStdPwrCnsm_kWhpkm = 0.0F;/* '<S214>/Gain5' */

/* 标准工况电耗（kWh/km） */
MONPRM volatile float32 VRME_WLTPStdSOCCnsm_pctpkm = 0.0F;/* '<S243>/Gain3' */

/* 标准工况下SOC消耗/km */
MONPRM volatile boolean VTBX_CnclSpdLim_flg = false;/* '<S323>/Logical Operator12' */

/* TBOX解除限速 */
MONPRM volatile boolean VTBX_LckVer_flg = false;/* '<S345>/Chart' */

/* 锁车版本 */
MONPRM volatile boolean VTBX_RecryTBOXHw_flg = false;/* '<S323>/Logical Operator14' */

/* TBOX硬件通讯丢失恢复 */
MONPRM volatile boolean VTBX_ReqLimpHome_flg = false;/* '<S322>/Data Type Conversion6' */

/* VCU请求跛行动作 */
MONPRM volatile boolean VTBX_RmvTBOXHw_flg = false;/* '<S323>/Logical Operator3' */

/* TBOX硬件通讯丢失 */
MONPRM volatile boolean VTBX_SpdLimLvl1_flg = false;/* '<S323>/Logical Operator5' */

/* TBOX一级限速 */
MONPRM volatile boolean VTBX_SpdLimLvl2_flg = false;/* '<S323>/Logical Operator7' */

/* TBOX二级限速 */
MONPRM volatile boolean VTBX_SpdLimLvl3_flg = false;/* '<S323>/Logical Operator9' */

/* TBOX三级限速 */
MONPRM volatile boolean VTBX_StorgSpdLim_flg = false;/* '<S323>/Logical Operator11' */

/* TBOX库存限速 */
MONPRM volatile boolean VTBX_TBOXOffline_flg = false;/* '<S322>/Signal Copy3' */

/* TBOX硬件状态-实时存储 */
MONPRM volatile boolean VTBX_UnlckVer_flg = false;/* '<S344>/Chart' */

/* 非锁车版本 */
MONPRM volatile boolean VTBX_VCUChrgngCondsFb_flg = false;/* '<S322>/Data Type Conversion5' */

/* VCU反馈判断充电条件 */
MONPRM volatile uint8 VTBX_VCULckVehWrn_enum = ((uint8)0U);/* '<S322>/Signal Copy5' */

/* VCU反馈锁存提醒 */
MONPRM volatile boolean VTBX_VCUOprtLicFb_flg = false;/* '<S322>/Data Type Conversion4' */

/* VCU反馈运营状态 */
MONPRM volatile EnumTBOXLimGrd VTBX_VCUSpdLimLvlFb_enum = EnumTBOXLimGrd_Normal;/* '<S322>/Data Type Conversion3' */

/* VCU反馈限速等级-当前驾驶循环 */
MONPRM volatile uint8 VTBX_VCUSpdLimLvlSetFb_enum = ((uint8)0U);/* '<S322>/Data Type Conversion7' */

/* VCU反馈限速等级设置成功 */
MONPRM volatile EnumTBOXLimSt VTBX_VCUSpdLimSt_enum = EnumTBOXLimSt_Normal;/* '<S322>/Data Type Conversion1' */

/* 当前循环限速状态-实时存储 */
MONPRM volatile boolean VTBX_VCUVerFb_flg = false;/* '<S322>/Signal Copy' */

/* VCU反馈锁车版本-实时存储 */
MONPRM volatile uint8 VTBX_VCUVerSetFb_enum = ((uint8)0U);/* '<S322>/Signal Copy1' */

/* VCU反馈锁车版本设置成功 */
MONPRM volatile float32 VTQC_ABSorESPActvTm_s = 0.0F;/* '<S711>/MinMax' */
MONPRM volatile float32 VTQC_BrkRegenMaxTqWhl_Nm = 0.0F;/* '<S706>/Switch17' */
MONPRM volatile float32 VTQC_BrkRegenTgtTqWhl_Nm = 0.0F;/* '<S706>/Switch2' */
MONPRM volatile float32 VTQC_CstRegenLmtTq_Nm = 0.0F;/* '<S704>/CstRegenLmtTq' */
MONPRM volatile float32 VTQC_DrvTqReqWhlABS_Nm = 0.0F;/* '<S704>/MinMax1' */
MONPRM volatile float32 VTQC_DrvTqReqWhlRBS_Nm = 0.0F;/* '<S713>/MinMax5' */
MONPRM volatile float32 VTQC_DrvTqReqWhl_Nm = 0.0F;/* '<S705>/Switch5' */
MONPRM volatile float32 VTQC_MotorTqReq_Nm = 0.0F;/* '<S705>/Divide' */
MONPRM volatile boolean VTQC_RBSActv_flg = false;/* '<S714>/Switch4' */
MONPRM volatile float32 VTQD_AccelPedPstnRescl_pct = 0.0F;/* '<S725>/Product' */
MONPRM volatile float32 VTQD_AdaptCstDeltaAcceltn_mps2 = 0.0F;/* '<S741>/Add5' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqFF_Nm = 0.0F;/* '<S741>/Add2' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqI_N = 0.0F;/* '<S741>/Saturation2' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqPID_Nm = 0.0F;/* '<S741>/Product6' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqP_N = 0.0F;/* '<S741>/Product3' */
MONPRM volatile float32 VTQD_AdaptCstMaxTqWhl_Nm = 0.0F;/* '<S737>/MinMax4' */
MONPRM volatile float32 VTQD_AdaptCstMinTqWhl_Nm = 0.0F;/* '<S737>/MinMax5' */
MONPRM volatile boolean VTQD_AdaptCstRegenEnbl_flg = false;/* '<S737>/Logical Operator9' */
MONPRM volatile float32 VTQD_AdaptCstTgtAcceltn_mps2 = 0.0F;/* '<S743>/Switch' */
MONPRM volatile float32 VTQD_AdaptCstTqReqWhl_Nm = 0.0F;/* '<S741>/MinMax6' */
MONPRM volatile boolean VTQD_BkwdDrv_flg = false;/* '<S764>/Switch4' */
MONPRM volatile boolean VTQD_BrkRegenEnbl_flg = false;/* '<S736>/Logical Operator1' */
MONPRM volatile float32 VTQD_CrpTqReqWhl_Nm = 0.0F;/* '<S727>/Switch2' */
MONPRM volatile boolean VTQD_CstRegenEnbl_flg = false;/* '<S736>/Logical Operator13' */
MONPRM volatile float32 VTQD_CstRegenEndPstn_pct = 0.0F;/* '<S736>/Switch2' */
MONPRM volatile float32 VTQD_CstRegenTqReqWhl_Nm = 0.0F;/* '<S738>/Switch4' */
MONPRM volatile float32 VTQD_DrvTqDrtFac_c = 0.0F;/* '<S765>/Saturation' */
MONPRM volatile float32 VTQD_DrvTqReqWhlMrg_Nm = 0.0F;/* '<S766>/Switch4' */
MONPRM volatile float32 VTQD_DrvTqReqWhlRaw_Nm = 0.0F;/* '<S725>/Merge' */
MONPRM volatile float32 VTQD_DrvTqReqWhl_Nm = 0.0F;/* '<S723>/Switch3' */
MONPRM volatile boolean VTQD_DsblCrp_flg = false;/* '<S727>/Logical Operator12' */
MONPRM volatile float32 VTQD_FullPedDrvTqWhl_Nm = 0.0F;/* '<S725>/Signal Conversion1' */
MONPRM volatile float32 VTQD_FwdPedMap_pct = 0.0F;/* '<S728>/Switch9' */
MONPRM volatile float32 VTQD_PedalTqReqWhlRaw_Nm = 0.0F;/* '<S722>/Add' */
MONPRM volatile uint16 VTQD_TaskRunCounter_cnt = ((uint16)0U);/* '<S555>/Max1' */

/* test signal, to be deleted */
MONPRM volatile boolean VTQD_TqZeroFast_flg = false;/* '<S757>/Logical Operator4' */
MONPRM volatile boolean VTQD_TqZeroSlow_flg = false;/* '<S757>/Logical Operator2' */
MONPRM volatile boolean VTQD_TqZero_flg = false;/* '<S757>/Logical Operator1' */
MONPRM volatile float32 VTQF_DrvTqReqWhl_Nm = 0.0F;/* '<S782>/Switch2' */
MONPRM volatile float32 VTQF_TipOutTqDecRateCoeff_rat = 0.0F;/* '<S784>/1-D Lookup Table1' */
MONPRM volatile boolean VTQF_TqInc_flg = false;/* '<S794>/Switch4' */
MONPRM volatile float32 VTQF_TqOutChgRate_Nmps = 0.0F;/* '<S804>/Switch' */
MONPRM volatile float32 VTQF_TqRateDecTgtMax_Nmps = 0.0F;/* '<S784>/Switch3' */
MONPRM volatile float32 VTQF_TqRateDecTgtMin_Nmps = 0.0F;/* '<S784>/MinMax4' */
MONPRM volatile float32 VTQF_TqRateIncTgtMax_Nmps = 0.0F;/* '<S785>/Switch5' */
MONPRM volatile float32 VTQF_TqRateIncTgtMin_Nmps = 0.0F;/* '<S785>/MinMax4' */
MONPRM volatile float32 VTQF_TqRateLimDec_Nmps = 0.0F;/* '<S784>/MinMax3' */
MONPRM volatile boolean VTQF_TqRateLimEndg_flg = false;/* '<S783>/Logical Operator9' */
MONPRM volatile float32 VTQF_TqRateLimInc_Nmps = 0.0F;/* '<S785>/MinMax2' */
MONPRM volatile float32 VTQF_TqRawChgRate_Nmps = 0.0F;/* '<S803>/Switch' */
MONPRM volatile float32 VTQF_WhlDrgMaxTqZX_Nm = 0.0F;/* '<S802>/Switch1' */
MONPRM volatile float32 VTQF_WhlDrvMaxTqZX_Nm = 0.0F;/* '<S802>/Switch7' */
MONPRM volatile boolean VTQR_ASDEnbl_flg = false;/* '<S807>/Logical Operator14' */
MONPRM volatile float32 VTQR_ASDSpdFltHi_rpm = 0.0F;/* '<S815>/Switch' */
MONPRM volatile float32 VTQR_ASDSpdOscRaw_rpm = 0.0F;/* '<S811>/Add1' */
MONPRM volatile float32 VTQR_ASDSpdOsc_rpm = 0.0F;/* '<S813>/Multiport Switch' */
MONPRM volatile float32 VTQR_ASDTqReqRaw_Nm = 0.0F;/* '<S819>/MinMax5' */
MONPRM volatile float32 VTQR_ASDTqReq_Nm = 0.0F;/* '<S812>/Switch3' */
MONPRM volatile boolean VTQR_MotDampngEnbl_flg = false;/* '<S807>/Logical Operator1' */
MONPRM volatile float32 VTQR_MotDampngLmt_Nm = 0.0F;/* '<S827>/MinMax5' */
MONPRM volatile EnumMotorDirReq VTQR_MotorDirReq_enum = EnumMotorDirReq_Stdby;/* '<S808>/Switch4' */
MONPRM volatile EnumMotorModeReq VTQR_MotorModeReq_enum = EnumMotorModeReq_Stdby;/* '<S805>/Signal Conversion15' */
MONPRM volatile float32 VTQR_MotorSpdReq_rpm = 0.0F;/* '<S805>/Signal Conversion1' */
MONPRM volatile boolean VTQR_MotorStdby_flg = false;/* '<S809>/Logical Operator1' */
MONPRM volatile float32 VTQR_MotorTqReq_Nm = 0.0F;/* '<S805>/Signal Conversion2' */
MONPRM volatile float32 VTZX_AZDecRate_Nmps = 0.0F;/* '<S843>/1-D Lookup Table4' */
MONPRM volatile float32 VTZX_AZIncRate_Nmps = 0.0F;/* '<S843>/1-D Lookup Table3' */
MONPRM volatile float32 VTZX_BZDecRate_Nmps = 0.0F;/* '<S843>/1-D Lookup Table2' */
MONPRM volatile float32 VTZX_BZIncRate_Nmps = 0.0F;/* '<S843>/1-D Lookup Table1' */
MONPRM volatile boolean VTZX_BypZX_flg = false;/* '<S847>/Logical Operator1' */
MONPRM volatile boolean VTZX_ClkActv_flg = false;/* '<S846>/Switch4' */
MONPRM volatile float32 VTZX_ClkZXTm_s = 0.0F;/* '<S839>/Switch1' */
MONPRM volatile float32 VTZX_MotorTqReqPrdt_Nm = 0.0F;/* '<S859>/MinMax5' */
MONPRM volatile float32 VTZX_MotorTqReqZX_Nm = 0.0F;/* '<S844>/TqZXSt' */
MONPRM volatile float32 VTZX_MotorTqReq_Nm = 0.0F;/* '<S839>/Switch6' */
MONPRM volatile boolean VTZX_TqInc_flg = false;/* '<S853>/Switch4' */
MONPRM volatile boolean VTZX_TqRateLimRamp_flg = false;/* '<S860>/Switch4' */
MONPRM volatile EnumTZXStat VTZX_TqZXSt_enum = EnumTZXStat_NTRL;/* '<S844>/Data Type Conversion1' */
MONPRM volatile float32 VTZX_ZeroTqHldDec_Nm = 0.0F;/* '<S844>/TqZXSt' */
MONPRM volatile float32 VTZX_ZeroTqHldInc_Nm = 0.0F;/* '<S844>/TqZXSt' */
MONPRM volatile float32 VTZX_ZeroTqOfstDec_Nm = 0.0F;/* '<S843>/Switch3' */
MONPRM volatile float32 VTZX_ZeroTqOfstInc_Nm = 0.0F;/* '<S843>/Switch2' */
MONPRM volatile float32 VTZX_ZeroTqOfst_Nm = 0.0F;/* '<S843>/Switch4' */
MONPRM volatile float32 VTZX_ZeroXTm_s = 0.0F;/* '<S843>/Switch8' */
MONPRM volatile uint8 VVCU_ECURstCntr_cnt = ((uint8)0U);/* '<S47>/Switch2' */

/* 控制器Reset计数器 */
MONPRM volatile float32 VVSO_ALatSnsr_mps2 = 0.0F;/* '<S459>/Switch1' */
MONPRM volatile float32 VVSO_ALgtSnsr_mps2 = 0.0F;/* '<S458>/Switch1' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr1_mpkm = 0.0F;/* '<S520>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr2_mpkm = 0.0F;/* '<S520>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr3_mpkm = 0.0F;/* '<S520>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr4_mpkm = 0.0F;/* '<S520>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr5_mpkm = 0.0F;/* '<S520>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr_mpkm = 0.0F;/* '<S520>/Add3' */
MONPRM volatile float32 VVSO_DrvDist_m = 0.0F;/* '<S533>/Switch1' */
MONPRM volatile boolean VVSO_RSEBrkPresrConf_flg = false;/* '<S505>/Relational Operator2' */
MONPRM volatile boolean VVSO_RSESigConf_flg = false;/* '<S491>/Logical Operator3' */
MONPRM volatile boolean VVSO_RSEVehSpdConf_flg = false;/* '<S507>/Logical Operator2' */
MONPRM volatile boolean VVSO_RSEWhlSlipConf_flg = false;/* '<S508>/Logical Operator2' */
MONPRM volatile boolean VVSO_RSEYawRateConf_flg = false;/* '<S509>/Logical Operator' */
MONPRM volatile float32 VVSO_RoadSlopCalcRaw_pct = 0.0F;/* '<S489>/Product19' */
MONPRM volatile boolean VVSO_RoadSlopEstVld_flg = false;/* '<S488>/Logical Operator1' */
MONPRM volatile float32 VVSO_RoadSlopEst_pct = 0.0F;/* '<S488>/Switch2' */
MONPRM volatile float32 VVSO_RoadSlopTqEst_Nm = 0.0F;/* '<S504>/MinMax5' */
MONPRM volatile float32 VVSO_VehDrvResistTq_Nm = 0.0F;/* '<S490>/Switch5' */
MONPRM volatile boolean VVSO_VehMassConf_flg = false;/* '<S536>/Logical Operator4' */
MONPRM volatile uint8 VVSO_VehMassDistb_enum = ((uint8)0U);/* '<S536>/Signal Conversion' */
MONPRM volatile float32 VVSO_VehMassEst_kg = 0.0F;/* '<S539>/Switch' */
MONPRM volatile float32 VVSO_VehSpd_mps = 0.0F;/* '<S536>/Gain3' */
MONPRM volatile float32 VVSO_WhlAcceltnFL_mps2 = 0.0F;/* '<S471>/Divide' */
MONPRM volatile float32 VVSO_WhlAcceltnFR_mps2 = 0.0F;/* '<S472>/Divide' */
MONPRM volatile float32 VVSO_WhlAcceltnRL_mps2 = 0.0F;/* '<S473>/Divide' */
MONPRM volatile float32 VVSO_WhlAcceltnRR_mps2 = 0.0F;/* '<S474>/Divide' */
MONPRM volatile boolean VVSO_WhlDistErrHld_flg = false;/* '<S524>/OR' */
MONPRM volatile float32 VVSO_WhlLgtFrc_N = 0.0F;/* '<S541>/Add' */
MONPRM volatile EnumXWhlDistErrRefSt VVSO_XWhlDistErrRefStat_enum =
  EnumXWhlDistErrRefSt_Init;           /* '<S520>/Signal Conversion2' */
MONPRM volatile float32 VVSO_XWhlDistErrRef_mpkm = 0.0F;/* '<S520>/Signal Conversion1' */
MONPRM volatile float32 VVSO_XWhlDistErr_m = 0.0F;/* '<S533>/Switch4' */
MONPRM volatile float32 VVSO_YawRateBas_degps = 0.0F;/* '<S465>/Switch' */
MONPRM volatile float32 VVSO_YawRateDer_radps2 = 0.0F;/* '<S460>/Add6' */
MONPRM volatile float32 VVSO_YawRateFilt_radps = 0.0F;/* '<S464>/Switch' */
MONPRM volatile boolean VVSO_iTPMSAvail_flg = false;/* '<S524>/Logical Operator' */
MONPRM volatile EnumiTPMSSt VVSO_iTPMSState_enum = EnumiTPMSSt_Init;/* '<S520>/Signal Conversion' */
MONPRM volatile boolean VVSO_iTPMSWrng_flg = false;/* '<S520>/Signal Conversion3' */
MONPRM volatile boolean VVTM_BrkPedReld_flg = false;/* '<S885>/Logical Operator3' */
MONPRM volatile uint8 VVTM_DrvMotorSta_enum = ((uint8)0U);/* '<S892>/DriveMotorState' */
MONPRM volatile boolean VVTM_ESPIntvActv_flg = false;/* '<S885>/Logical Operator4' */
MONPRM volatile float32 VVTM_MotorActPwr_kW = 0.0F;/* '<S899>/Switch2' */
MONPRM volatile float32 VVTM_MotorSpd_rpm = 0.0F;/* '<S887>/Switch' */
MONPRM volatile boolean VVTM_RegenReqBrkLampOn_flg = false;/* '<S897>/Switch1' */
MONPRM volatile float32 VVTM_RsrvPwr_kW = 0.0F;/* '<S894>/MinMax4' */
MONPRM volatile float32 VVTM_RsrvRecupPwr_kW = 0.0F;/* '<S894>/MinMax1' */
MONPRM volatile float32 VVTM_VehAcceltn_mps2 = 0.0F;/* '<S890>/Switch' */
MONPRM volatile uint8 VVTM_VehActGrPstn_enum = ((uint8)0U);/* '<S885>/Switch1' */
MONPRM volatile float32 VVTM_VehSpd_kph = 0.0F;/* '<S886>/Switch' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
