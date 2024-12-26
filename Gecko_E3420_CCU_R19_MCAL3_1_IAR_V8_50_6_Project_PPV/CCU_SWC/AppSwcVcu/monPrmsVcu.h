/*
 * File: monPrmsVcu.h
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

#ifndef RTW_HEADER_monPrmsVcu_h_
#define RTW_HEADER_monPrmsVcu_h_
#include "rtwtypes.h"
#include "AppSwcVcu_types.h"

/* Exported data declaration */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Declaration for custom storage class: Volatile */
extern MONPRM volatile boolean BSW_RTCWakeup_flg;/* '<S284>/Switch4' */

/* RTC唤醒标志位_versteckt */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Day;/* '<S978>/Data Type Conversion45' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Hour;/* '<S978>/Data Type Conversion1' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Min;/* '<S978>/Data Type Conversion2' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Month;/* '<S978>/Data Type Conversion34' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Sec;/* '<S978>/Switch2' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Year;/* '<S978>/Data Type Conversion33' */
extern MONPRM volatile boolean VBSW_ECURst_flg;/* '<S7>/Relational Operator3' */
extern MONPRM volatile boolean VBSW_F1B1PwrOffReq_flg;/* '<S12>/Chart' */

/* F1B1请求下高压 */
extern MONPRM volatile boolean VBSW_F1B1PwrOnReq_flg;/* '<S11>/Chart' */

/* F1B1请求上高压 */
extern MONPRM volatile uint16 VBSW_RTCWupRmningT_min;/* '<S7>/Data Type Conversion1' */

/* RTC唤醒剩余时间 */
extern MONPRM volatile uint8 VBSW_RoutineF1B1_enum;/* '<S7>/Selector' */

/* F1B1例程控制 */
extern MONPRM volatile uint8 VBSW_WakeupReasn_enum;/* '<S7>/EcuWakeupReasn' */
extern MONPRM volatile float32 VCPT_MotorDrgMaxTq_Nm;/* '<S550>/MinMax6' */
extern MONPRM volatile float32 VCPT_MotorDrvMaxTq_Nm;/* '<S550>/MinMax7' */
extern MONPRM volatile float32 VCPT_MotorGenMaxTq_Nm;/* '<S562>/Switch1' */
extern MONPRM volatile float32 VCPT_MotorMotMaxTq_Nm;/* '<S561>/Switch1' */
extern MONPRM volatile boolean VCPT_MotorSpdRvrs_flg;/* '<S550>/Switch3' */
extern MONPRM volatile float32 VCPT_MotorSpd_rpm;/* '<S556>/Switch' */
extern MONPRM volatile float32 VCPT_WhlDrgMaxTq_Nm;/* '<S550>/MinMax1' */
extern MONPRM volatile float32 VCPT_WhlDrvMaxTq_Nm;/* '<S550>/MinMax8' */
extern MONPRM volatile boolean VDAC_ACCAvail_flg;/* '<S571>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_ACCDeltaAcceltn_mps2;/* '<S578>/Add5' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqFF_Nm;/* '<S578>/Add3' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqI_N;/* '<S578>/Saturation1' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqPID_Nm;/* '<S578>/Product6' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqP_N;/* '<S578>/Product3' */
extern MONPRM volatile boolean VDAC_ACCEnbl_flg;/* '<S571>/Logical Operator3' */
extern MONPRM volatile boolean VDAC_ACCOvrd_flg;/* '<S572>/Logical Operator22' */
extern MONPRM volatile uint8 VDAC_ACCStat_enum;/* '<S573>/Switch1' */
extern MONPRM volatile float32 VDAC_ACCTqReqWhl_Nm;/* '<S574>/Merge3' */
extern MONPRM volatile boolean VDAC_CCActv2Stby_flg;/* '<S618>/Logical Operator15' */
extern MONPRM volatile boolean VDAC_CCActvBascCond_flg;/* '<S618>/Logical Operator1' */
extern MONPRM volatile float32 VDAC_CCDeltaAcceltn_mps2;/* '<S605>/Add3' */
extern MONPRM volatile float32 VDAC_CCDsrdAcceltnRaw_mps2;/* '<S598>/Saturation1' */
extern MONPRM volatile float32 VDAC_CCDsrdAcceltn_mps2;/* '<S596>/Merge1' */
extern MONPRM volatile float32 VDAC_CCDsrdTqFF_N;/* '<S604>/Add3' */
extern MONPRM volatile float32 VDAC_CCDsrdTqI_N;/* '<S605>/Saturation1' */
extern MONPRM volatile float32 VDAC_CCDsrdTqPID_N;/* '<S605>/Add2' */
extern MONPRM volatile float32 VDAC_CCDsrdTqP_N;/* '<S605>/Product2' */
extern MONPRM volatile boolean VDAC_CCEnbl_flg;/* '<S619>/Logical Operator2' */
extern MONPRM volatile uint16 VDAC_CCNoActvCond_enum;/* '<S621>/Add' */
extern MONPRM volatile boolean VDAC_CCOvrd_flg;/* '<S592>/Logical Operator22' */
extern MONPRM volatile uint16 VDAC_CCQuitCond_enum;/* '<S622>/Add' */
extern MONPRM volatile float32 VDAC_CCSpdUnstabTm_s;/* '<S634>/Saturation' */
extern MONPRM volatile boolean VDAC_CCSpdUnstab_flg;/* '<S634>/Relational Operator8' */
extern MONPRM volatile EnumCCState VDAC_CCSt_enum;/* '<S593>/CC_State_Chart' */
extern MONPRM volatile boolean VDAC_CCStby2Actv_flg;/* '<S618>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_CCTgtSpdCtrl_kph;/* '<S643>/Switch1' */
extern MONPRM volatile uint8 VDAC_CCTgtSpdHU_kph;/* '<S594>/TgtSpdCalc' */
extern MONPRM volatile EnumCCTgtSpdSt VDAC_CCTgtSpdSt_enum;/* '<S594>/TgtSpdCalc' */
extern MONPRM volatile float32 VDAC_CCTgtSpd_kph;/* '<S594>/MinMax7' */
extern MONPRM volatile float32 VDAC_CCTqReqWhl_Nm;/* '<S597>/Merge2' */
extern MONPRM volatile float32 VDAC_CCVehSpdNonDrvn_kph;/* '<S600>/Switch' */
extern MONPRM volatile boolean VDAC_CruzCncl_flg;/* '<S659>/Chart' */
extern MONPRM volatile EnumCruiseStatus VDAC_CruzCtrlStat_enum;/* '<S592>/Switch2' */
extern MONPRM volatile boolean VDAC_CruzCtrlSwVld_flg;/* '<S595>/Signal Conversion1' */
extern MONPRM volatile boolean VDAC_CruzOn_flg;/* '<S595>/Signal Conversion2' */
extern MONPRM volatile boolean VDAC_CruzRsmActv_flg;/* '<S656>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSetActv_flg;/* '<S654>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSpdDecActv_flg;/* '<S655>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSpdIncActv_flg;/* '<S657>/Switch4' */
extern MONPRM volatile float32 VDAC_DrvAsstTqSplitEHB_Nm;/* '<S567>/MinMax2' */
extern MONPRM volatile float32 VDAC_DrvAsstTqSplitINV_Nm;/* '<S567>/Add1' */
extern MONPRM volatile uint8 VDAC_DrvAsstTqSts_enum;/* '<S567>/Switch1' */
extern MONPRM volatile float32 VDAC_DrvAsstTqTgt_Nm;/* '<S567>/Switch2' */
extern MONPRM volatile boolean VDAC_EnblEHBBrkRun_flg;/* '<S690>/Switch4' */
extern MONPRM volatile boolean VDAC_HDCActv2Idle_flg;/* '<S666>/Logical Operator11' */
extern MONPRM volatile boolean VDAC_HDCActv2Stdby_flg;/* '<S666>/Logical Operator8' */
extern MONPRM volatile float32 VDAC_HDCDeltaAcceltn_mps2;/* '<S671>/Add5' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqFF_Nm;/* '<S671>/Add3' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqI_N;/* '<S671>/Saturation1' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqPID_Nm;/* '<S671>/Product6' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqP_N;/* '<S671>/Product3' */
extern MONPRM volatile boolean VDAC_HDCIdle2Stdby_flg;/* '<S666>/Logical Operator2' */
extern MONPRM volatile EnumHDCState VDAC_HDCSt_enum;/* '<S565>/HDC_State_Chart' */
extern MONPRM volatile boolean VDAC_HDCStdby2Actv_flg;/* '<S666>/Logical Operator13' */
extern MONPRM volatile boolean VDAC_HDCStdby2Idle_flg;/* '<S666>/Logical Operator3' */
extern MONPRM volatile float32 VDAC_HDCTgtAcceltn_mps2;/* '<S663>/Merge1' */
extern MONPRM volatile float32 VDAC_HDCTgtSpd_kph;/* '<S565>/HDC_State_Chart' */
extern MONPRM volatile float32 VDAC_HDCTqReqWhl_Nm;/* '<S663>/Merge2' */
extern MONPRM volatile uint8 VDAC_HDCVehSpdHU_kph;/* '<S664>/Switch1' */
extern MONPRM volatile float32 VDAC_MstrCylPresrReq_bar;/* '<S567>/Switch13' */
extern MONPRM volatile uint8 VDAC_VehSpdHU_kph;/* '<S645>/Switch1' */
extern MONPRM volatile uint8 VDAC_VirtAccPedPstnSta_enum;/* '<S567>/Switch11' */
extern MONPRM volatile float32 VDAC_VirtAccPedPstn_pct;/* '<S567>/Switch8' */
extern MONPRM volatile float32 VDAC_VirtAccelPedPstnRaw_pct;/* '<S567>/Switch9' */
extern MONPRM volatile float32 VDAC_VirtPedPstn_pct;/* '<S567>/Switch4' */
extern MONPRM volatile uint8 VDAG_ACCMHVILFltSt_enum;/* '<S1448>/FltStDeb' */

/* 压缩机高压互锁故障状态 */
extern MONPRM volatile uint8 VDAG_ACChrgStFailFltSt_enum;/* '<S1281>/FltStDeb' */

/* ACChargeStateFail故障状态 */
extern MONPRM volatile uint8 VDAG_ACDchaBMSPwrLoFltSt_enum;/* '<S1287>/FltStDeb' */

/* AC放电BMS功率低故障状态 */
extern MONPRM volatile uint8 VDAG_ACDchaBMSSOCLoFltSt_enum;/* '<S1286>/FltStDeb' */

/* AC放电BMSSOC低故障状态 */
extern MONPRM volatile uint8 VDAG_ACDchaOverPwrFltSt_enum;/* '<S1280>/FltStDeb' */

/* AC放电功率超限故障 */
extern MONPRM volatile uint8 VDAG_ACSCmdTmOutFltSt_enum;/* '<S1011>/FltStDeb' */

/* ACSCmd超时故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed1ShtBattFltSt_enum;/* '<S1422>/FltStDeb' */

/* 加速踏板1路短电源故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed1ShtGndFltSt_enum;/* '<S1419>/FltStDeb' */

/* 加速踏板1路短地故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed1SuplyShtCircFltSt_enum;/* '<S1420>/FltStDeb' */

/* 加速踏板1路供电短路故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed2ShtBattFltSt_enum;/* '<S1415>/FltStDeb' */

/* 加速踏板2路短电源故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed2ShtGndFltSt_enum;/* '<S1423>/FltStDeb' */

/* 加速踏板2路短地故障状态 */
extern MONPRM volatile uint8 VDAG_AccPed2SuplyShtCircFltSt_enum;/* '<S1421>/FltStDeb' */

/* 加速踏板2路供电短路故障状态 */
extern MONPRM volatile uint8 VDAG_AccPedBothFailFltSt_enum;/* '<S1417>/FltStDeb' */

/* 加速踏板双路失效故障状态 */
extern MONPRM volatile uint8 VDAG_AccPedCrsChkFltSt_enum;/* '<S1416>/FltStDeb' */

/* 加速踏板相互校验故障状态 */
extern MONPRM volatile uint8 VDAG_BMSCmdTmOutFltSt_enum;/* '<S1005>/FltStDeb' */

/* BMS继电器指令响应超时故障状态 */
extern MONPRM volatile uint8 VDAG_BMSEmgcySdnFltSt_enum;/* '<S1016>/FltStDeb' */

/* BMS紧急下电故障状态 */
extern MONPRM volatile uint8 VDAG_BMSSOCLoFltSt_enum;/* '<S1015>/FltStDeb' */

/* BMSSOC低故障状态 */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl1FltSt_enum;/* '<S1012>/FltStDeb' */

/* BMSFailLevel1故障状态 */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl2FltSt_enum;/* '<S1013>/FltStDeb' */

/* BMSFailLevel2故障状态 */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl3FltSt_enum;/* '<S1014>/FltStDeb' */

/* BMSFailLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_BMSUndrVoltFltSt_enum;/* '<S1017>/FltStDeb' */

/* BMSPack欠压故障状态 */
extern MONPRM volatile uint8 VDAG_BrkPedShtBattFltSt_enum;/* '<S1445>/FltStDeb' */

/* 制动踏板短电源故障状态 */
extern MONPRM volatile uint8 VDAG_BrkPedShtGndFltSt_enum;/* '<S1443>/FltStDeb' */

/* 制动踏板短地故障状态 */
extern MONPRM volatile uint8 VDAG_BrkSwCrsChkCnt_cnt;/* '<S1435>/Data Type Conversion' */

/* 制动开关相互校验错误计数 */
extern MONPRM volatile uint8 VDAG_BrkSwCrsChkFltSt_enum;/* '<S1444>/FltStDeb' */

/* 制动开关相互校验故障状态 */
extern MONPRM volatile uint8 VDAG_CellUndrVoltFltSt_enum;/* '<S1018>/FltStDeb' */

/* BMSCell欠压故障状态 */
extern MONPRM volatile uint8 VDAG_DCCCmdTmOutFltSt_enum;/* '<S1179>/FltStDeb' */

/* DCDC模式指令响应超时故障状态 */
extern MONPRM volatile uint8 VDAG_DCCInVoltLoFltSt_enum;/* '<S1180>/FltStDeb' */

/* DCDC输入电压低故障状态 */
extern MONPRM volatile uint8 VDAG_DCCModeFltFltSt_enum;/* '<S1178>/FltStDeb' */

/* DCDCModeFault故障状态 */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl1FltSt_enum;/* '<S1174>/FltStDeb' */

/* DCDCFailLevel1故障状态 */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl2FltSt_enum;/* '<S1175>/FltStDeb' */

/* DCDCFailLevel2故障状态 */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl3FltSt_enum;/* '<S1176>/FltStDeb' */

/* DCDCFailLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl4FltSt_enum;/* '<S1177>/FltStDeb' */

/* DCDCFailLevel4故障状态 */
extern MONPRM volatile uint8 VDAG_DCSChrgReqFltSt_enum;/* '<S1009>/FltStDeb' */

/* DCSChargeRequest故障状态 */
extern MONPRM volatile uint8 VDAG_DCSCmdTmOutFltSt_enum;/* '<S1019>/FltStDeb' */

/* DCSCmd超时故障状态 */
extern MONPRM volatile uint8 VDAG_DCSFailStaFltSt_enum;/* '<S1007>/FltStDeb' */

/* DCSFailState故障状态 */
extern MONPRM volatile uint8 VDAG_DCSInletConnectFltSt_enum;/* '<S1008>/FltStDeb' */

/* DCS插枪故障状态 */
extern MONPRM volatile uint8 VDAG_DCSModeFailFltSt_enum;/* '<S1010>/FltStDeb' */

/* DCSModeFail故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl1FltSt_enum;/* '<S1353>/FltStDeb' */

/* EHB1级故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl2FltSt_enum;/* '<S1354>/FltStDeb' */

/* EHB2级故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl3FltSt_enum;/* '<S1355>/FltStDeb' */

/* EHB3级故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl4FltSt_enum;/* '<S1347>/FltStDeb' */

/* EHB4级故障状态 */
extern MONPRM volatile uint8 VDAG_EHBFltLvl5FltSt_enum;/* '<S1356>/FltStDeb' */

/* EHB5级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl1FltSt_enum;/* '<S1358>/FltStDeb' */

/* ESC1级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl2FltSt_enum;/* '<S1348>/FltStDeb' */

/* ESC2级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl3FltSt_enum;/* '<S1349>/FltStDeb' */

/* ESC3级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl4FltSt_enum;/* '<S1357>/FltStDeb' */

/* ESC4级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCFltLvl5FltSt_enum;/* '<S1350>/FltStDeb' */

/* ESC5级故障状态 */
extern MONPRM volatile uint8 VDAG_ESCVehSpdInvldFltSt_enum;/* '<S1352>/FltStDeb' */

/* 车速失效故障状态 */
extern MONPRM volatile boolean VDAG_EmgcyShtdwn_flg;/* '<S969>/Switch30' */
extern MONPRM volatile uint16 VDAG_ErrCode_enum;/* '<S967>/Err_State' */
extern MONPRM volatile boolean VDAG_FanFullSpdOn_flg;/* '<S969>/Switch3' */
extern MONPRM volatile boolean VDAG_FbdACC_flg;/* '<S969>/Switch28' */
extern MONPRM volatile boolean VDAG_FbdACChrg_flg;/* '<S969>/Switch32' */
extern MONPRM volatile boolean VDAG_FbdACDcha_flg;/* '<S969>/Switch34' */
extern MONPRM volatile boolean VDAG_FbdAC_flg;/* '<S969>/Switch35' */
extern MONPRM volatile boolean VDAG_FbdCC_flg;/* '<S969>/Switch26' */
extern MONPRM volatile boolean VDAG_FbdDCChrg_flg;/* '<S969>/Switch33' */
extern MONPRM volatile boolean VDAG_FbdDCDC_flg;/* '<S969>/Switch31' */
extern MONPRM volatile boolean VDAG_FbdDRGr_flg;/* '<S969>/Switch25' */
extern MONPRM volatile boolean VDAG_FbdDrvTq_flg;/* '<S969>/Switch23' */
extern MONPRM volatile boolean VDAG_FbdHV_flg;/* '<S969>/Switch29' */
extern MONPRM volatile boolean VDAG_FbdLSP_flg;/* '<S969>/Switch27' */
extern MONPRM volatile boolean VDAG_FltLampOn_flg;/* '<S969>/Switch36' */
extern MONPRM volatile uint8 VDAG_FltLvl_enum;/* '<S969>/MinMax' */
extern MONPRM volatile uint8 VDAG_FrstHVILVoltHiFltSt_enum;/* '<S1447>/FltStDeb' */

/* 主要高压互锁电压高故障状态 */
extern MONPRM volatile uint8 VDAG_FrstHVILVoltLoFltSt_enum;/* '<S1446>/FltStDeb' */

/* 主要高压互锁电压低故障状态 */
extern MONPRM volatile uint8 VDAG_GearShftInvldFltSt_enum;/* '<S1351>/FltStDeb' */

/* 换挡输入失效故障状态 */
extern MONPRM volatile uint8 VDAG_HVIsoResistLoFltSt_enum;/* '<S1006>/FltStDeb' */

/* 高压电池绝缘故障状态 */
extern MONPRM volatile uint8 VDAG_INVFltLvl1FltSt_enum;/* '<S1247>/FltStDeb' */

/* INVFaultLevel1故障状态 */
extern MONPRM volatile uint8 VDAG_INVFltLvl2FltSt_enum;/* '<S1248>/FltStDeb' */

/* INVFaultLevel2故障状态 */
extern MONPRM volatile uint8 VDAG_INVFltLvl3FltSt_enum;/* '<S1249>/FltStDeb' */

/* INVFaultLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_INVFltLvl4FltSt_enum;/* '<S1250>/FltStDeb' */

/* INVFaultLevel4故障状态 */
extern MONPRM volatile uint8 VDAG_INVInVoltLoFltSt_enum;/* '<S1181>/FltStDeb' */

/* INV输入电压低故障状态 */
extern MONPRM volatile uint8 VDAG_INVRunCmdRespFltSt_enum;/* '<S1251>/FltStDeb' */

/* INVRun指令响应超时故障状态 */
extern MONPRM volatile boolean VDAG_LVBatLampOn_flg;/* '<S969>/Switch1' */
extern MONPRM volatile uint8 VDAG_LVBattSOCLoFltSt_enum;/* '<S1395>/FltStDeb' */

/* 蓄电池SOC低的故障状态 */
extern MONPRM volatile uint8 VDAG_LVBattSOHLoFltSt_enum;/* '<S1391>/FltStDeb' */

/* 蓄电池SOH低的故障状态 */
extern MONPRM volatile uint8 VDAG_LVBattTempHiFltSt_enum;/* '<S1392>/FltStDeb' */

/* 蓄电池过温故障状态 */
extern MONPRM volatile uint8 VDAG_LVBattVoltHiFltSt_enum;/* '<S1394>/FltStDeb' */

/* 蓄电池电压高故障状态 */
extern MONPRM volatile uint8 VDAG_LVBattVoltLoFltSt_enum;/* '<S1393>/FltStDeb' */

/* 蓄电池电压低故障状态 */
extern MONPRM volatile boolean VDAG_LimpHome_flg;/* '<S969>/Switch2' */
extern MONPRM volatile boolean VDAG_LmtDrvTq_flg;/* '<S969>/Switch24' */
extern MONPRM volatile uint8 VDAG_OBCChrgReqFltSt_enum;/* '<S1285>/FltStDeb' */

/* OBCChargeRequest故障状态 */
extern MONPRM volatile uint8 VDAG_OBCConnectTmOutFltSt_enum;/* '<S1283>/FltStDeb' */

/* OBC连接超时故障状态 */
extern MONPRM volatile uint8 VDAG_OBCInletConnectFltSt_enum;/* '<S1288>/FltStDeb' */

/* OBC插枪故障状态 */
extern MONPRM volatile uint8 VDAG_OBCModeMsmtchFltSt_enum;/* '<S1282>/FltStDeb' */

/* OBC模式不匹配故障状态 */
extern MONPRM volatile uint8 VDAG_OBCS2StatFltSt_enum;/* '<S1284>/FltStDeb' */

/* OBCS2连接超时故障状态 */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl1FltSt_enum;/* '<S1289>/FltStDeb' */

/* OBCFailLevel1故障状态 */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl2FltSt_enum;/* '<S1290>/FltStDeb' */

/* OBCFailLevel2故障状态 */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl3FltSt_enum;/* '<S1291>/FltStDeb' */

/* OBCFailLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl4FltSt_enum;/* '<S1279>/FltStDeb' */

/* OBCFailLevel4故障状态 */
extern MONPRM volatile uint8 VDAG_SecdHVILVoltHiFltSt_enum;/* '<S1450>/FltStDeb' */

/* 次要高压互锁电压高故障状态 */
extern MONPRM volatile uint8 VDAG_SecdHVILVoltLoFltSt_enum;/* '<S1449>/FltStDeb' */

/* 次要高压互锁电压低故障状态 */
extern MONPRM volatile uint8 VDAG_SysPwrModeInvldFltSt_enum;/* '<S1345>/FltStDeb' */

/* PowerMode失效故障状态 */
extern MONPRM volatile uint8 VDAG_TMSFailLvl3FltSt_enum;/* '<S1346>/FltStDeb' */

/* TMSRFailLevel3故障状态 */
extern MONPRM volatile uint8 VDAG_VehCrashFltSt_enum;/* '<S1414>/FltStDeb' */

/* 碰撞故障状态 */
extern MONPRM volatile boolean VDAG_WakeUp_flg;/* '<S968>/Logical Operator9' */

/* 硬线唤醒或者IBSLIN唤醒标志 */
extern MONPRM volatile uint8 VDAG_WaterTempAbvThrFltSt_enum;/* '<S1470>/FltStDeb' */

/* 冷却水温过高故障状态 */
extern MONPRM volatile uint8 VDAG_WaterTempBlwThrFltSt_enum;/* '<S1469>/FltStDeb' */

/* 冷却水温过低故障状态 */
extern MONPRM volatile float32 VDSA_AcceltnIdxAvg_pct;/* '<S71>/AvgAcceltnIdx' */
extern MONPRM volatile float32 VDSA_AcceltnIdxRaw_pct;/* '<S71>/Saturation1' */
extern MONPRM volatile float32 VDSA_BrkPedPstnAvg_pct;/* '<S71>/AvgBrkPedPstn' */
extern MONPRM volatile float32 VDSA_DrvSprtIdx_pct;/* '<S71>/Saturation2' */
extern MONPRM volatile boolean VDSA_SprtIdxHldAcc_flg;/* '<S71>/Logical Operator3' */
extern MONPRM volatile boolean VDSA_SprtIdxHldBrk_flg;/* '<S71>/Logical Operator6' */
extern MONPRM volatile float32 VDSA_TqCalcAcceltn_mps2;/* '<S71>/Divide1' */
extern MONPRM volatile boolean VEMS_ACCMOprtCmd_flg;/* '<S906>/ACCMEnble' */

/* 使能ACCM */
extern MONPRM volatile float32 VEMS_AccPwrRaw_kW;/* '<S907>/MinMax4' */
extern MONPRM volatile float32 VEMS_CellTempSyn_C;/* '<S963>/Switch1' */
extern MONPRM volatile float32 VEMS_CellUndrVoltDrtFac_c;/* '<S904>/Saturation3' */
extern MONPRM volatile float32 VEMS_ChrgCurFbKi_A;/* '<S960>/Saturation' */
extern MONPRM volatile float32 VEMS_ChrgCurFbKp_A;/* '<S960>/Product2' */
extern MONPRM volatile float32 VEMS_ChrgCurFb_A;/* '<S960>/Saturation2' */
extern MONPRM volatile float32 VEMS_ChrgOvrshtPwr_kW;/* '<S903>/Add1' */
extern MONPRM volatile float32 VEMS_ChrgPwrFbKi_kW;/* '<S922>/Saturation' */
extern MONPRM volatile float32 VEMS_ChrgPwrFbKp_kW;/* '<S922>/Product2' */
extern MONPRM volatile float32 VEMS_ChrgPwrFb_kW;/* '<S903>/Merge' */
extern MONPRM volatile float32 VEMS_DchaCurFbKi_A;/* '<S961>/Saturation' */
extern MONPRM volatile float32 VEMS_DchaCurFbKp_A;/* '<S961>/Product2' */
extern MONPRM volatile float32 VEMS_DchaCurFb_A;/* '<S961>/Saturation2' */
extern MONPRM volatile float32 VEMS_DchaOvrshtPwr_kW;/* '<S905>/Add1' */
extern MONPRM volatile float32 VEMS_DchaPwrFbKi_kW;/* '<S940>/Saturation' */
extern MONPRM volatile float32 VEMS_DchaPwrFbKp_kW;/* '<S940>/Product2' */
extern MONPRM volatile float32 VEMS_DchaPwrFb_kW;/* '<S905>/Merge' */
extern MONPRM volatile float32 VEMS_HVBatPwrAct_kW;/* '<S907>/Gain1' */
extern MONPRM volatile float32 VEMS_MaxChrgCur_A;/* '<S902>/Saturation4' */
extern MONPRM volatile float32 VEMS_MaxChrgPwr2MotRaw_kW;/* '<S902>/Add7' */
extern MONPRM volatile float32 VEMS_MaxChrgPwr2Mot_kW;/* '<S903>/MinMax2' */
extern MONPRM volatile float32 VEMS_MaxChrgPwr_kW;/* '<S902>/Product2' */
extern MONPRM volatile float32 VEMS_MaxConChrgCur_A;/* '<S902>/MinMax1' */
extern MONPRM volatile float32 VEMS_MaxConDchaCur_A;/* '<S904>/MinMax1' */
extern MONPRM volatile float32 VEMS_MaxDchaCur_A;/* '<S904>/Saturation4' */
extern MONPRM volatile float32 VEMS_MaxDchaPwr2MotRaw_kW;/* '<S904>/Add7' */
extern MONPRM volatile float32 VEMS_MaxDchaPwr2Mot_kW;/* '<S905>/MinMax2' */
extern MONPRM volatile float32 VEMS_MaxDchaPwr_kW;/* '<S904>/Product2' */
extern MONPRM volatile float32 VEMS_MaxInsChrgCur_A;/* '<S902>/MinMax3' */
extern MONPRM volatile float32 VEMS_MaxInsDchaCur_A;/* '<S904>/MinMax3' */
extern MONPRM volatile boolean VEMS_TMSActSOCEnbl_flg;/* '<S957>/Switch1' */

/* SOC是否限制TMS */
extern MONPRM volatile boolean VEMS_TMSPwrEnbl_flg;/* '<S906>/Switch3' */

/* 功率是否限制TMS */
extern MONPRM volatile float32 VEMS_TMSUsePwrRaw_kW;/* '<S906>/Subtract' */

/* TMS原始可用功率（BMS持续功率-DCDC实际功率） */
extern MONPRM volatile float32 VEMS_TMSUsePwr_kW;/* '<S906>/Switch2' */

/* TMS限制后可用功率(故障条件、TBOX远程、纯加热模式、SOC限制) */
extern MONPRM volatile boolean VEMS_UseConChrgCur_flg;/* '<S913>/Switch4' */
extern MONPRM volatile boolean VEMS_UseConDchaCur_flg;/* '<S931>/Switch4' */
extern MONPRM volatile boolean VGSM_AsstDrvFbShft_flg;/* '<S1677>/Logical Operator2' */

/* 规范：ACC/CC禁止档位解析 */
extern MONPRM volatile boolean VGSM_AsstDrvReqEPB_flg;/* '<S1663>/Switch4' */

/* ACC通讯丢失或故障拉起EPB */
extern MONPRM volatile boolean VGSM_DRFlt2N_flg;/* '<S1676>/Switch1' */

/* 规范：退至非驱动档标志位 */
extern MONPRM volatile boolean VGSM_EPBAplyFlt_flg;/* '<S1653>/EPBLogical' */

/* 故障P-EPB拉起故障 */
extern MONPRM volatile boolean VGSM_EPBRelsFlt_flg;/* '<S1653>/EPBLogical' */

/* 故障P-EPB释放故障 */
extern MONPRM volatile boolean VGSM_GrD2PExcdTm_flg;/* '<S1831>/Chart' */

/* D档入P请求超时入N */
extern MONPRM volatile boolean VGSM_GrNReq2P_flg;/* '<S1676>/Switch2' */

/* N档非换挡请求进P档请求 */
extern MONPRM volatile boolean VGSM_GrR2PExcdTm_flg;/* '<S1828>/Chart' */

/* R档入P请求超时入N */
extern MONPRM volatile boolean VGSM_HldGearP_flg;/* '<S1676>/Switch' */

/* 规范：保持P档标志位 */
extern MONPRM volatile boolean VGSM_INVRunEnbl_flg;/* '<S1679>/Chart' */

/* 规范：INV使能控制（允许扭矩控制）-VCU_1_EnaInvRun */
extern MONPRM volatile uint8 VGSM_PGrSwSts_enum;/* '<S1677>/Switch2' */

/* 规范：P按键触发标志位-VCU_PGearSwcst */
extern MONPRM volatile boolean VGSM_ReqEPBAply_flg;/* '<S1678>/Logical Operator6' */

/* 规范：EPB拉起请求标志位 */
extern MONPRM volatile boolean VGSM_ReqEPBRels_flg;/* '<S1678>/Logical Operator4' */

/* 规范：EPB释放请求标志位 */
extern MONPRM volatile EnumEPBReq VGSM_ReqEPB_enum;/* '<S1653>/Switch' */

/* 规范：EPB操作信号-VCUF_ReqEPB */
extern MONPRM volatile EnumTgtGearPstn VGSM_ShftTgtGrReq_enum;/* '<S1677>/Data Type Conversion1' */

/* 换挡杆目标档位 0-NoCmd 1-P 2-N 3-D 4-R  */
extern MONPRM volatile EnumGearPstn VGSM_VehActGearPstn_enum;/* '<S1654>/Switch1' */

/* 规范：实际档位-VCU_VhclActlGearPos */
extern MONPRM volatile boolean VGSM_VehEPBStErr_flg;/* '<S1653>/Logical Operator' */

/* 规范：P档故障PGear error-VCU_VhclPGearError */
extern MONPRM volatile EnumTgtGearPstn VGSM_VehTgtGrReq_enum;/* '<S1678>/Data Type Conversion1' */

/* 规范:目标档位 */
extern MONPRM volatile uint8 VGSM_VehTgtGrTrnsfr_enum;/* '<S1716>/Switch' */

/* 规范：换档请求信号 */
extern MONPRM volatile uint8 VHMI_12VBatLowVolSta_enum;/* '<S80>/Switch' */
extern MONPRM volatile float32 VHMI_GrDSldDist_m;/* '<S94>/Saturation' */

/* D档后溜距离 */
extern MONPRM volatile boolean VHMI_GrDSldSw_flg;/* '<S94>/Logical Operator' */

/* D档溜坡计速/距离标志 */
extern MONPRM volatile float32 VHMI_GrRSldDist_m;/* '<S94>/Saturation1' */

/* R档前溜距离 */
extern MONPRM volatile boolean VHMI_GrRSldSw_flg;/* '<S94>/Logical Operator4' */

/* R档溜坡计速/距离标志 */
extern MONPRM volatile uint8 VHMI_InfoDisp_enum;/* '<S83>/Arbitration' */

/* 仪表弹窗值 */
extern MONPRM volatile boolean VHVM_ACChrgEnbl_flg;/* '<S1547>/Logical Operator8' */

/* 交流充电基本条件满足 */
extern MONPRM volatile uint8 VHVM_ACChrgMaxCurrFb_A;/* '<S1518>/Switch5' */

/* HU设置电流反馈 */
extern MONPRM volatile uint8 VHVM_ACChrgModeFb_enum;/* '<S1518>/Switch7' */

/* HU设置充电模式反馈 */
extern MONPRM volatile boolean VHVM_ACChrging2Stop_flg;/* '<S1541>/AND' */

/* 交流充电中转移到充电停止标志位 */
extern MONPRM volatile boolean VHVM_ACDchaEnbl_flg;/* '<S1547>/Logical Operator10' */

/* 交流放电基本条件满足 */
extern MONPRM volatile boolean VHVM_ACDschrging2Stop_flg;/* '<S1541>/AND7' */

/* 交流放电中转移到放电停止标志位 */
extern MONPRM volatile EnumBMSSdnCmd VHVM_BMSShutdown_enum;/* '<S1517>/Data Type Conversion10' */

/* VCU关闭BMS指令对应CAN信号：VCU_BMS_Shutdown */
extern MONPRM volatile EnumBMSWakeUpMd VHVM_BMSWakeUpMode_enum;/* '<S1517>/Data Type Conversion8' */

/* VCU唤醒BMS的方式对应CAN信号：VCU_BMS_WakeupMode */
extern MONPRM volatile boolean VHVM_Bat2DrvTrainEnbl_flg;/* '<S1517>/MainState' */

/* VCU控制主继电器指令对应CAN信号：VCU_Bat2DrvTrainEnb */
extern MONPRM volatile EnumChrgAllwCmd VHVM_ChrgAllowCmd_enum;/* '<S1517>/Data Type Conversion12' */

/* VCU发送允许充电指令对应CAN信号：VCU_ChrgAllowCmd */
extern MONPRM volatile uint8 VHVM_ChrgEnaAC_enum;/* '<S1517>/MainState' */

/* VCU控制OBC交流充电使能指令对应CAN信号：VCU_ChrgEna_AC */
extern MONPRM volatile boolean VHVM_ChrgEnaDC_flg;/* '<S1517>/MainState' */

/* VCU控制BMS直流充电使能指令对应CAN信号：VCU_ChrgEna_DC */
extern MONPRM volatile float32 VHVM_DCCBuckLVVolt_V;/* '<S1517>/MainState' */

/* VCU控制DCDC BUCK电压值对应CAN信号：VCU_DCCBuckLV_Vol */
extern MONPRM volatile EnumDCCOprtCmd VHVM_DCCOprtCmd_enum;/* '<S1517>/Data Type Conversion6' */

/* VCU控制DCDC工作模式指令对应CAN信号：VCU_DCCOprtCmd */
extern MONPRM volatile boolean VHVM_DCChrgEnbl_flg;/* '<S1547>/Logical Operator2' */

/* 直流充电基本条件满足 */
extern MONPRM volatile boolean VHVM_DCChrging2Over_flg;/* '<S1541>/AND1' */

/* 直流充电中转移到充电结束标志位 */
extern MONPRM volatile boolean VHVM_ECUSleepAllwd_flg;/* '<S1517>/MainState' */

/* 允许底层休眠标志位 */
extern MONPRM volatile boolean VHVM_EmgcySdn_flg;/* '<S1517>/MainState' */

/* VCU给INV发送紧急下电指令(INV强制停机)对应CAN信号：VCU_1_EmShutDown */
extern MONPRM volatile boolean VHVM_EnaDisChg_flg;/* '<S1517>/MainState' */

/* VCU控制INV泄放指令对应CAN信号：VCU_1_EnaDisChg */
extern MONPRM volatile boolean VHVM_EngyExtrmLo_flg;/* '<S1520>/Logical Operator17' */

/* 电池能量极低标志位 */
extern MONPRM volatile boolean VHVM_F1B1HVOffReq_flg;/* '<S1546>/Logical Operator45' */

/* F1B1下电请求 */
extern MONPRM volatile boolean VHVM_F1B1HVOnReq_flg;/* '<S1547>/Logical Operator45' */

/* F1B1上电请求 */
extern MONPRM volatile boolean VHVM_HVRdy_flg;/* '<S1517>/MainState' */

/* DCDC&INV预充完成 */
extern MONPRM volatile boolean VHVM_INVEnbl_flg;/* '<S1517>/MainState' */

/* VCU硬线唤醒INV */
extern MONPRM volatile boolean VHVM_INVPreprogmFlg_flg;/* '<S1542>/Switch1' */

/* INV预编程条件满足 */
extern MONPRM volatile float32 VHVM_MaxChrgCurntDC_A;/* '<S1517>/MainState' */

/* VCU允许BMS直流充电最大电流对应CAN信号：VCU_MaxChrgCrnt_DC */
extern MONPRM volatile float32 VHVM_MaxChrgVoltDC_V;/* '<S1517>/MainState' */

/* VCU允许BMS直流充电最大电压对应CAN信号：VCU_MaxChrgVol_DC */
extern MONPRM volatile float32 VHVM_MaxHVDCCurntAC_A;/* '<S1517>/MainState' */

/* VCU允许OBC交流充电最大电流对应CAN信号：VCU_MaxHVDC_Cur_AC */
extern MONPRM volatile float32 VHVM_MaxHVDCVoltAC_V;/* '<S1517>/MainState' */

/* VCU允许OBC交流充电最大电压对应CAN信号：VCU_MaxHVDC_Vol_AC */
extern MONPRM volatile EnumOBCOprtCmd VHVM_OBCOprtCmd_enum;/* '<S1518>/Data Type Conversion4' */

/* VCU控制OBC工作模式指令对应CAN信号：VCU_OBCOprtCmd */
extern MONPRM volatile EnumPTActMd VHVM_PTActOprtMode_enum;/* '<S1517>/Data Type Conversion4' */

/* 高压PT状态 */
extern MONPRM volatile boolean VHVM_PTRdy2PTStdby_flg;/* '<S1544>/Switch1' */

/* PTRdy到PTStdby标志位 */
extern MONPRM volatile boolean VHVM_PTStdby2PTRdy_flg;/* '<S1544>/Switch' */

/* PTStdby到PTRdy标志位 */
extern MONPRM volatile boolean VHVM_PowUpSelfChek_flg;/* '<S1545>/Switch' */

/* 高压自检标志位 */
extern MONPRM volatile boolean VHVM_PwrOn2PwrDwn_flg;/* '<S1546>/Switch' */

/* 高压下电条件满足标志位（正常/故障/紧急） */
extern MONPRM volatile boolean VHVM_SOPExtrmLo_flg;/* '<S1520>/Relational Operator4' */

/* 电池SOP极低，用于关闭DCDC */
extern MONPRM volatile EnumSysSta VHVM_SysSta_enum;/* '<S1517>/Data Type Conversion2' */

/* 高压子状态 */
extern MONPRM volatile uint8 VHVM_TBOX2OBC_emun;/* '<S1518>/Switch1' */

/* TBOX远程充放电指令 */
extern MONPRM volatile EnumVCUMode VHVM_VCUMode_enum;/* '<S1517>/Data Type Conversion' */

/* 高压主转态 */
extern MONPRM volatile boolean VHVM_VehHalt_flg;/* '<S1536>/Switch4' */

/* 车辆停止标志位（车速极其） */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpACChrg_flg;/* '<S1547>/Logical Operator16' */

/* 交流充电唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpACDcha_flg;/* '<S1547>/Logical Operator26' */

/* 交流放电唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpDCChrg_flg;/* '<S1547>/Logical Operator4' */

/* 直流充电唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpIBS_flg;/* '<S1547>/Logical Operator6' */

/* IBS唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpKL15_flg;/* '<S1547>/Logical Operator' */

/* K15唤醒上电 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUp_flg;/* '<S1547>/Switch' */

/* 唤醒到上高压条件满足（唤醒源上升沿+高压自检通过） */
extern MONPRM volatile boolean VHVM_WakeUpBMS_flg;/* '<S1517>/MainState' */

/* VCU硬线唤醒BMS */
extern MONPRM volatile boolean VHVM_WakeUpVCU_flg;/* '<S1548>/Switch' */

/* 休眠到唤醒条件满足 */
extern MONPRM volatile boolean VIBS_BMSBatSOCAllow_flg;/* '<S259>/Switch3' */

/* 动力电池SOC允许补电标志位_versteckt */
extern MONPRM volatile boolean VIBS_ChgNumAllow_flg;/* '<S259>/AND' */

/* 补电次数允许标志位_versteckt */
extern MONPRM volatile uint8 VIBS_ChgNum_cnt;/* '<S259>/Switch2' */

/* IBS补电次数_versteckt */
extern MONPRM volatile boolean VIBS_ChrgBascCond_flg;/* '<S259>/Logical Operator2' */

/* 补电基本条件满足（补电次数及电压）_versteckt */
extern MONPRM volatile boolean VIBS_ChrgEnbl_flg;/* '<S259>/Logical Operator7' */

/* IBS充电使能标志位_versteckt */
extern MONPRM volatile boolean VIBS_ChrgOver_flg;/* '<S257>/ChrgSt' */

/* IBS补电结束标志位_versteckt */
extern MONPRM volatile float32 VIBS_ChrgVoltThr_V;/* '<S260>/VoltState' */

/* 补电电压阈值_versteckt */
extern MONPRM volatile float32 VIBS_EnvirTemp_C;/* '<S282>/Switch' */

/* IBS环境温度_versteckt */
extern MONPRM volatile uint8 VIBS_FailChgNum_cnt;/* '<S259>/Switch5' */

/* IBS补电失败次数_versteckt */
extern MONPRM volatile boolean VIBS_FbRctWup_flg;/* '<S259>/Logical Operator6' */

/* IBS禁止RTC唤醒标志位_versteckt */
extern MONPRM volatile boolean VIBS_HVReq_flg;/* '<S259>/Switch' */

/* IBS请求上高压标志位_versteckt */
extern MONPRM volatile float32 VIBS_HwKL30_V;/* '<S281>/Switch' */

/* 滤波后的KL30电压_versteckt */
extern MONPRM volatile float32 VIBS_MustChrgVolt_V;/* '<S260>/MIBS_MustChrgVolt_V' */

/* 兜底电压_versteckt */
extern MONPRM volatile boolean VIBS_MustChrg_flg;/* '<S290>/Chart' */

/* 兜底电压激活标志位_versteckt */
extern MONPRM volatile boolean VIBS_NMReq_flg;/* '<S266>/Switch4' */

/* IBS请求网络标志位_versteckt */
extern MONPRM volatile uint16 VIBS_NextRtcWupThr_min;/* '<S260>/Switch1' */

/* 下次补电唤醒RTC的时间_versteckt */
extern MONPRM volatile EnumIBSChrgSt VIBS_RTCChrgSt_enum;/* '<S257>/Data Type Conversion' */

/* IBS补电状态_versteckt */
extern MONPRM volatile boolean VIBS_RTCWakeup_flg;/* '<S260>/Switch3' */

/* RTC唤醒标志位（含延迟时间）_versteckt */
extern MONPRM volatile boolean VIBS_SleepAllwd_flg;/* '<S259>/SleepAllwd' */

/* IBS允许底层休眠标志位_versteckt */
extern MONPRM volatile uint16 VIBS_WupChgTmThr_min;/* '<S260>/Switch2' */

/* IBS补电时间阈值_versteckt */
extern MONPRM volatile boolean VIBS_WupVoltAllow_flg;/* '<S283>/Switch4' */

/* KL30电压允许标志位_versteckt */
extern MONPRM volatile boolean VIPC_ACCCfgd_flg;/* '<S365>/Switch8' */
extern MONPRM volatile boolean VIPC_AccPed1Flt_flg;/* '<S369>/Logical Operator1' */
extern MONPRM volatile boolean VIPC_AccPed1LrnDwnActv_flg;/* '<S379>/Relational Operator' */
extern MONPRM volatile boolean VIPC_AccPed1LrnUpActv_flg;/* '<S372>/Logical Operator5' */
extern MONPRM volatile float32 VIPC_AccPed1MinPstnLrnd_pct;/* '<S372>/Switch2' */
extern MONPRM volatile float32 VIPC_AccPed1NormzAvg_pct;/* '<S378>/Switch' */
extern MONPRM volatile float32 VIPC_AccPed1NormzPstn_pct;/* '<S369>/Switch5' */
extern MONPRM volatile float32 VIPC_AccPed1SclPstn_pct;/* '<S373>/Divide1' */
extern MONPRM volatile boolean VIPC_AccPed2Flt_flg;/* '<S369>/Logical Operator2' */
extern MONPRM volatile boolean VIPC_AccPed2LrnDwnActv_flg;/* '<S383>/Relational Operator' */
extern MONPRM volatile boolean VIPC_AccPed2LrnUpActv_flg;/* '<S374>/Logical Operator5' */
extern MONPRM volatile float32 VIPC_AccPed2MinPstnLrnd_pct;/* '<S374>/Switch2' */
extern MONPRM volatile float32 VIPC_AccPed2NormzAvg_pct;/* '<S382>/Switch' */
extern MONPRM volatile float32 VIPC_AccPed2NormzPstn_pct;/* '<S369>/Switch7' */
extern MONPRM volatile float32 VIPC_AccPed2SclPstn_pct;/* '<S375>/Divide5' */
extern MONPRM volatile boolean VIPC_AccPedPstnVld_flg;/* '<S371>/Switch3' */
extern MONPRM volatile float32 VIPC_AccPedPstn_pct;/* '<S367>/MinMax3' */
extern MONPRM volatile uint8 VIPC_AccPedSnsrSta_enum;/* '<S371>/Switch3' */
extern MONPRM volatile boolean VIPC_AccPedStkActv_flg;/* '<S370>/Logical Operator6' */
extern MONPRM volatile boolean VIPC_AccPedStkBrkPrsd_flg;/* '<S397>/Switch4' */
extern MONPRM volatile float32 VIPC_AccPedStkPstn_pct;/* '<S370>/MinMax' */
extern MONPRM volatile boolean VIPC_AccPedStkStab_flg;/* '<S399>/Relational Operator' */
extern MONPRM volatile float32 VIPC_AccPedWghtAvg_pct;/* '<S396>/Switch' */
extern MONPRM volatile float32 VIPC_AccPedWghtPstn_pct;/* '<S371>/Switch3' */
extern MONPRM volatile float32 VIPC_AccPedZeroPstn_pct;/* '<S370>/Switch' */
extern MONPRM volatile boolean VIPC_BrkPedPstnVld_flg;/* '<S362>/Logical Operator8' */
extern MONPRM volatile float32 VIPC_BrkPedPstn_pct;/* '<S362>/Saturation1' */
extern MONPRM volatile boolean VIPC_BrkSwActv_flg;/* '<S362>/Logical Operator' */
extern MONPRM volatile boolean VIPC_CCSCfgd_flg;/* '<S365>/Switch1' */
extern MONPRM volatile boolean VIPC_CrpCtrlCfgd_flg;/* '<S365>/Switch2' */
extern MONPRM volatile EnumCrpModeAct VIPC_CrpModeAct_enum;/* '<S364>/Switch12' */
extern MONPRM volatile EnumDrvModeAct VIPC_DrvModeAct_enum;/* '<S364>/Switch13' */
extern MONPRM volatile uint8 VIPC_DrvPwrIntnsty_pct;/* '<S364>/Switch25' */
extern MONPRM volatile boolean VIPC_DrvSw_flg;/* '<S367>/Relational Operator3' */
extern MONPRM volatile boolean VIPC_EPBAppld_flg;/* '<S363>/Logical Operator2' */
extern MONPRM volatile boolean VIPC_EPBReld_flg;/* '<S363>/Logical Operator1' */
extern MONPRM volatile boolean VIPC_HDCCfgd_flg;/* '<S365>/Switch3' */
extern MONPRM volatile EnumRegenModeAct VIPC_RegenModeAct_enum;/* '<S364>/Switch15' */
extern MONPRM volatile uint8 VIPC_RegenPwrIntnsty_pct;/* '<S364>/Switch28' */
extern MONPRM volatile boolean VIPC_SnowMode_flg;/* '<S364>/Switch14' */
extern MONPRM volatile float32 VIPC_TireRadius_m;/* '<S365>/TireSizeTable' */
extern MONPRM volatile uint8 VIPC_VehHiddenMode_enum;/* '<S364>/VehHiddenMode' */
extern MONPRM volatile float32 VIPC_VehSpdDrvnMotor_kph;/* '<S366>/Product1' */
extern MONPRM volatile boolean VIPC_VehSpdDrvnVld_flg;/* '<S433>/Logical Operator2' */
extern MONPRM volatile float32 VIPC_VehSpdDrvn_kph;/* '<S433>/Switch7' */
extern MONPRM volatile boolean VIPC_VehSpdNonDrvnVld_flg;/* '<S434>/Logical Operator2' */
extern MONPRM volatile float32 VIPC_VehSpdNonDrvn_kph;/* '<S434>/Switch7' */
extern MONPRM volatile boolean VIPC_VehSpdVld_flg;/* '<S433>/SignalConversion' */
extern MONPRM volatile float32 VIPC_VehSpd_kph;/* '<S433>/Switch4' */
extern MONPRM volatile boolean VIPC_VpedAutoCrp_flg;/* '<S421>/Switch4' */
extern MONPRM volatile boolean VIPC_ZeroPstnRst_flg;/* '<S370>/Logical Operator3' */
extern MONPRM volatile boolean VIPC_iTPMSCfgd_flg;/* '<S365>/Switch4' */
extern MONPRM volatile float32 VIPM_HwAccPedCh1SuplyVolt_mV;/* '<S15>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh1Volt_mV;/* '<S16>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh2SuplyVolt_mV;/* '<S17>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh2Volt_mV;/* '<S18>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwBMSWakeup_flg;/* '<S19>/Switch4' */
extern MONPRM volatile boolean VIPM_HwBrkSwHi_flg;/* '<S20>/Switch4' */
extern MONPRM volatile boolean VIPM_HwBrkSwLo_flg;/* '<S21>/Switch4' */
extern MONPRM volatile boolean VIPM_HwCrpModeSw_flg;/* '<S22>/Switch4' */
extern MONPRM volatile boolean VIPM_HwDrvModeSw_flg;/* '<S23>/Switch4' */
extern MONPRM volatile boolean VIPM_HwEmgcyShutOff_flg;/* '<S24>/Switch4' */
extern MONPRM volatile float32 VIPM_HwHVIL1Volt_mV;/* '<S25>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwHVIL2Volt_mV;/* '<S26>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwKL15A_flg;/* '<S27>/Switch4' */
extern MONPRM volatile boolean VIPM_HwKL15B_flg;/* '<S28>/Switch4' */
extern MONPRM volatile uint16 VIPM_HwKL30_mV;/* '<S29>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwOBCWakeup_flg;/* '<S30>/Switch4' */
extern MONPRM volatile boolean VIPM_HwRearFogLampSwt_flg;/* '<S31>/Switch4' */
extern MONPRM volatile EnumPGearSwSts VIPM_HwShftPstnSwSts_enum;/* '<S32>/Switch4' */
extern MONPRM volatile uint16 VIPM_HwShftPstnSw_Ohm;/* '<S8>/HwShftPstnSw' */
extern MONPRM volatile boolean VIPM_HwVehCrash_flg;/* '<S33>/Switch4' */
extern MONPRM volatile uint8 VNVM_ACChrgMaxCurrFb_A;/* '<S9>/Selector18' */
extern MONPRM volatile uint8 VNVM_ACChrgModeFb_enum;/* '<S9>/Selector19' */
extern MONPRM volatile float32 VNVM_AvgPwrCnsm_kWh100km;/* '<S9>/Add2' */
extern MONPRM volatile float32 VNVM_AvgSOCCnsmWght_pctp100km;/* '<S9>/Add6' */
extern MONPRM volatile EnumCrpModeAct VNVM_CrpModeAct_enum;/* '<S9>/Data Type Conversion1' */
extern MONPRM volatile EnumDrvModeAct VNVM_DrvModeAct_enum;/* '<S9>/Data Type Conversion23' */
extern MONPRM volatile uint8 VNVM_DrvPwrIntnsty_pct;/* '<S9>/Selector6' */
extern MONPRM volatile float32 VNVM_DynRmnMilEst_km;/* '<S9>/Gain2' */
extern MONPRM volatile uint8 VNVM_EE01ReadOK_nu;/* '<S9>/Selector13' */
extern MONPRM volatile uint8 VNVM_EEImdtReadOK_nu;/* '<S9>/Selector14' */
extern MONPRM volatile boolean VNVM_HVRdy_flg;/* '<S9>/Data Type Conversion27' */
extern MONPRM volatile uint8 VNVM_IBSChrgFailNum_cnt;/* '<S9>/Selector1' */
extern MONPRM volatile uint8 VNVM_IBSChrgNum_cnt;/* '<S9>/Selector' */
extern MONPRM volatile EnumPTActMd VNVM_PTActOprtMode_enum;/* '<S9>/Data Type Conversion30' */
extern MONPRM volatile EnumRegenModeAct VNVM_RegenModeAct_enum;/* '<S9>/Data Type Conversion24' */
extern MONPRM volatile uint8 VNVM_RegenPwrIntnsty_pct;/* '<S9>/Selector7' */
extern MONPRM volatile boolean VNVM_TBOXOffline_flg;/* '<S9>/Data Type Conversion11' */
extern MONPRM volatile EnumTBOXLimSt VNVM_VCUSpdLimSt_enum;/* '<S9>/Data Type Conversion10' */
extern MONPRM volatile boolean VNVM_VCUVerFb_flg;/* '<S9>/Data Type Conversion12' */
extern MONPRM volatile EnumGearPstn VNVM_VehActGearPstn_enum;/* '<S9>/Data Type Conversion31' */
extern MONPRM volatile EnumXWhlDistErrRefSt VNVM_XWhlDistErrRefStat_enum;/* '<S9>/Data Type Conversion22' */
extern MONPRM volatile float32 VNVM_XWhlDistErrRef_mpkm;/* '<S9>/Add1' */
extern MONPRM volatile boolean VNVM_iTPMSWrng_flg;/* '<S9>/Data Type Conversion21' */
extern MONPRM volatile boolean VOPM_HwWakeupBMS_flg;/* '<S47>/Switch4' */
extern MONPRM volatile float32 VRME_AvgSOCCnsm100Num_pctpkm;/* '<S240>/Signal Copy5' */

/* 前100个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm10Num_pctpkm;/* '<S240>/Signal Copy1' */

/* 前10个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm15Num_pctpkm;/* '<S240>/Signal Copy2' */

/* 前15个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm25Num_pctpkm;/* '<S240>/Signal Copy3' */

/* 前25个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm50Num_pctpkm;/* '<S240>/Signal Copy4' */

/* 前50个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsm5Num_pctpkm;/* '<S240>/Signal Copy' */

/* 前5个数组平均SOC能耗 */
extern MONPRM volatile float32 VRME_AvgSOCCnsmWght_pctpkm;/* '<S240>/Switch1' */

/* 加权平均SOC能耗 */
extern MONPRM volatile boolean VRME_CHTCRmnMilEstV_flg;/* '<S206>/Logical Operator' */

/* CHTC标准续航里程有效性 */
extern MONPRM volatile float32 VRME_CHTCRmnMilEst_km;/* '<S206>/MRME_CHTCStdRmnMil_km' */

/* CHTC标准续航查表值 */
extern MONPRM volatile float32 VRME_CalPwrCnsmPerTrig_kWhptrig;/* '<S210>/Switch4' */

/* Pwr消耗/单位里程（trig） */
extern MONPRM volatile boolean VRME_CalPwrCnsmTrig_flg;/* '<S210>/Relational Operator1' */

/* 累计里程大于单位里程 */
extern MONPRM volatile float32 VRME_CalSOCCnsmDrvDist_m;/* '<S239>/Switch1' */

/* 单位目标行驶里程 */
extern MONPRM volatile float32 VRME_CalSOCCnsmPerTrig_pctptrig;/* '<S239>/Switch4' */

/* SOC消耗/单位里程（trig） */
extern MONPRM volatile float32 VRME_CalSOCCnsmPerkm_pctpkm;/* '<S239>/Divide' */

/* SOC消耗/单位里程（1km） */
extern MONPRM volatile boolean VRME_CalSOCCnsmTrig_flg;/* '<S239>/Relational Operator1' */

/* 累计里程大于目标里程 */
extern MONPRM volatile float32 VRME_ChrgRmnMilEstTgt_km;/* '<S235>/Switch2' */

/* 充电模式动态续航目标值 */
extern MONPRM volatile float32 VRME_ChrgRmnMilEst_km;/* '<S219>/Different Slops' */

/* 充电工况动态续航值 */
extern MONPRM volatile float32 VRME_ChrgTgtFstRate_kmpsoc;/* '<S219>/Divide2' */

/* 充电工况目标续航追击速率 */
extern MONPRM volatile float32 VRME_ChrgTgtNormRate_kmpsoc;/* '<S219>/Divide1' */

/* 充电工况目标续航变化速率 */
extern MONPRM volatile float32 VRME_DchaRmnMilEstChgFac_c;/* '<S238>/MRME_DynEstRmnChgStp_c' */

/* 非充电模式动态续航变化系数 */
extern MONPRM volatile float32 VRME_DchaRmnMilEstTgt_km;/* '<S247>/Switch2' */

/* 非充电模式动态续航目标值 */
extern MONPRM volatile boolean VRME_DchaRmnMilEstUpdTrig_flg;/* '<S238>/Relational Operator2' */

/* 更新续航值 */
extern MONPRM volatile float32 VRME_DchaRmnMilEst_km;/* '<S238>/Signal Copy1' */

/* 非充电模式动态续航值 */
extern MONPRM volatile boolean VRME_DchaVehStall_flg;/* '<S237>/Logical Operator4' */

/* 非充电模式车辆驻车状态 */
extern MONPRM volatile boolean VRME_DynRmnMilEstV_flg;/* '<S208>/Logical Operator1' */

/* 动态续航有效性 */
extern MONPRM volatile float32 VRME_VehPwrCnsmAvg_kWhpkm;/* '<S210>/Switch7' */

/* 当前循环平均能耗 */
extern MONPRM volatile float32 VRME_VehPwrCnsmIns_kWhpkm;/* '<S210>/Divide' */

/* 当前循环瞬间能耗 */
extern MONPRM volatile float32 VRME_VehTotMilCyc_km;/* '<S210>/Gain8' */

/* 当前驾驶循环车辆里程 */
extern MONPRM volatile float32 VRME_VehTotPwrCyc_kWh;/* '<S210>/Switch8' */

/* 当前驾驶循环车辆功率 */
extern MONPRM volatile float32 VRME_WLTPRmnMilEstDwLim_km;/* '<S215>/Product3' */

/* 动态续航下限值 */
extern MONPRM volatile float32 VRME_WLTPRmnMilEstUpLim_km;/* '<S215>/Product2' */

/* 动态续航上限值 */
extern MONPRM volatile float32 VRME_WLTPRmnMilEst_km;/* '<S215>/MRME_WLTPStdRmnMil_km' */

/* WLTP标准续航查表值 */
extern MONPRM volatile float32 VRME_WLTPStdPwrCnsm_kWhpkm;/* '<S210>/Gain5' */

/* 标准工况电耗（kWh/km） */
extern MONPRM volatile float32 VRME_WLTPStdSOCCnsm_pctpkm;/* '<S239>/Gain3' */

/* 标准工况下SOC消耗/km */
extern MONPRM volatile boolean VTBX_CnclSpdLim_flg;/* '<S317>/Logical Operator12' */

/* TBOX解除限速 */
extern MONPRM volatile boolean VTBX_LckVer_flg;/* '<S337>/Chart' */

/* 锁车版本 */
extern MONPRM volatile boolean VTBX_RecryTBOXHw_flg;/* '<S317>/Logical Operator14' */

/* TBOX硬件通讯丢失恢复 */
extern MONPRM volatile boolean VTBX_ReqLimpHome_flg;/* '<S316>/Data Type Conversion6' */

/* VCU请求跛行动作 */
extern MONPRM volatile boolean VTBX_RmvTBOXHw_flg;/* '<S317>/Logical Operator3' */

/* TBOX硬件通讯丢失 */
extern MONPRM volatile boolean VTBX_SpdLimLvl1_flg;/* '<S317>/Logical Operator5' */

/* TBOX一级限速 */
extern MONPRM volatile boolean VTBX_SpdLimLvl2_flg;/* '<S317>/Logical Operator7' */

/* TBOX二级限速 */
extern MONPRM volatile boolean VTBX_SpdLimLvl3_flg;/* '<S317>/Logical Operator9' */

/* TBOX三级限速 */
extern MONPRM volatile boolean VTBX_StorgSpdLim_flg;/* '<S317>/Logical Operator11' */

/* TBOX库存限速 */
extern MONPRM volatile boolean VTBX_TBOXOffline_flg;/* '<S316>/Signal Copy3' */

/* TBOX硬件状态-实时存储 */
extern MONPRM volatile boolean VTBX_UnlckVer_flg;/* '<S336>/Chart' */

/* 非锁车版本 */
extern MONPRM volatile boolean VTBX_VCUChrgngCondsFb_flg;/* '<S316>/Data Type Conversion5' */

/* VCU反馈判断充电条件 */
extern MONPRM volatile uint8 VTBX_VCULckVehWrn_enum;/* '<S316>/Signal Copy5' */

/* VCU反馈锁存提醒 */
extern MONPRM volatile boolean VTBX_VCUOprtLicFb_flg;/* '<S316>/Data Type Conversion4' */

/* VCU反馈运营状态 */
extern MONPRM volatile EnumTBOXLimGrd VTBX_VCUSpdLimLvlFb_enum;/* '<S316>/Data Type Conversion3' */

/* VCU反馈限速等级-当前驾驶循环 */
extern MONPRM volatile uint8 VTBX_VCUSpdLimLvlSetFb_enum;/* '<S316>/Data Type Conversion7' */

/* VCU反馈限速等级设置成功 */
extern MONPRM volatile EnumTBOXLimSt VTBX_VCUSpdLimSt_enum;/* '<S316>/Data Type Conversion1' */

/* 当前循环限速状态-实时存储 */
extern MONPRM volatile boolean VTBX_VCUVerFb_flg;/* '<S316>/Signal Copy' */

/* VCU反馈锁车版本-实时存储 */
extern MONPRM volatile uint8 VTBX_VCUVerSetFb_enum;/* '<S316>/Signal Copy1' */

/* VCU反馈锁车版本设置成功 */
extern MONPRM volatile float32 VTQC_ABSorESPActvTm_s;/* '<S703>/MinMax' */
extern MONPRM volatile float32 VTQC_BrkRegenMaxTqWhl_Nm;/* '<S698>/Switch17' */
extern MONPRM volatile float32 VTQC_BrkRegenTgtTqWhl_Nm;/* '<S698>/Switch2' */
extern MONPRM volatile float32 VTQC_CstRegenLmtTq_Nm;/* '<S696>/CstRegenLmtTq' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhlABS_Nm;/* '<S696>/MinMax1' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhlRBS_Nm;/* '<S705>/MinMax5' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhl_Nm;/* '<S697>/Switch5' */
extern MONPRM volatile float32 VTQC_MotorTqReq_Nm;/* '<S697>/Divide' */
extern MONPRM volatile boolean VTQC_RBSActv_flg;/* '<S706>/Switch4' */
extern MONPRM volatile float32 VTQD_AccelPedPstnRescl_pct;/* '<S717>/Product' */
extern MONPRM volatile float32 VTQD_AdaptCstDeltaAcceltn_mps2;/* '<S733>/Add5' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqFF_Nm;/* '<S733>/Add2' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqI_N;/* '<S733>/Saturation2' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqPID_Nm;/* '<S733>/Product6' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqP_N;/* '<S733>/Product3' */
extern MONPRM volatile float32 VTQD_AdaptCstMaxTqWhl_Nm;/* '<S729>/MinMax4' */
extern MONPRM volatile float32 VTQD_AdaptCstMinTqWhl_Nm;/* '<S729>/MinMax5' */
extern MONPRM volatile boolean VTQD_AdaptCstRegenEnbl_flg;/* '<S729>/Logical Operator9' */
extern MONPRM volatile float32 VTQD_AdaptCstTgtAcceltn_mps2;/* '<S735>/Switch' */
extern MONPRM volatile float32 VTQD_AdaptCstTqReqWhl_Nm;/* '<S733>/MinMax6' */
extern MONPRM volatile boolean VTQD_BkwdDrv_flg;/* '<S756>/Switch4' */
extern MONPRM volatile boolean VTQD_BrkRegenEnbl_flg;/* '<S728>/Logical Operator1' */
extern MONPRM volatile float32 VTQD_CrpTqReqWhl_Nm;/* '<S719>/Switch2' */
extern MONPRM volatile boolean VTQD_CstRegenEnbl_flg;/* '<S728>/Logical Operator13' */
extern MONPRM volatile float32 VTQD_CstRegenEndPstn_pct;/* '<S728>/Switch2' */
extern MONPRM volatile float32 VTQD_CstRegenTqReqWhl_Nm;/* '<S730>/Switch4' */
extern MONPRM volatile float32 VTQD_DrvTqDrtFac_c;/* '<S757>/Saturation' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhlMrg_Nm;/* '<S758>/Switch4' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhlRaw_Nm;/* '<S717>/Merge' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhl_Nm;/* '<S715>/Switch3' */
extern MONPRM volatile boolean VTQD_DsblCrp_flg;/* '<S719>/Logical Operator12' */
extern MONPRM volatile float32 VTQD_FullPedDrvTqWhl_Nm;/* '<S717>/Signal Conversion1' */
extern MONPRM volatile float32 VTQD_FwdPedMap_pct;/* '<S720>/Switch9' */
extern MONPRM volatile float32 VTQD_PedalTqReqWhlRaw_Nm;/* '<S714>/Add' */
extern MONPRM volatile uint16 VTQD_TaskRunCounter_cnt;/* '<S547>/Max1' */

/* test signal, to be deleted */
extern MONPRM volatile boolean VTQD_TqZeroFast_flg;/* '<S749>/Logical Operator4' */
extern MONPRM volatile boolean VTQD_TqZeroSlow_flg;/* '<S749>/Logical Operator2' */
extern MONPRM volatile boolean VTQD_TqZero_flg;/* '<S749>/Logical Operator1' */
extern MONPRM volatile float32 VTQF_DrvTqReqWhl_Nm;/* '<S774>/Switch2' */
extern MONPRM volatile float32 VTQF_TipOutTqDecRateCoeff_rat;/* '<S776>/1-D Lookup Table1' */
extern MONPRM volatile boolean VTQF_TqInc_flg;/* '<S786>/Switch4' */
extern MONPRM volatile float32 VTQF_TqOutChgRate_Nmps;/* '<S796>/Switch' */
extern MONPRM volatile float32 VTQF_TqRateDecTgtMax_Nmps;/* '<S776>/Switch3' */
extern MONPRM volatile float32 VTQF_TqRateDecTgtMin_Nmps;/* '<S776>/MinMax4' */
extern MONPRM volatile float32 VTQF_TqRateIncTgtMax_Nmps;/* '<S777>/Switch5' */
extern MONPRM volatile float32 VTQF_TqRateIncTgtMin_Nmps;/* '<S777>/MinMax4' */
extern MONPRM volatile float32 VTQF_TqRateLimDec_Nmps;/* '<S776>/MinMax3' */
extern MONPRM volatile boolean VTQF_TqRateLimEndg_flg;/* '<S775>/Logical Operator9' */
extern MONPRM volatile float32 VTQF_TqRateLimInc_Nmps;/* '<S777>/MinMax2' */
extern MONPRM volatile float32 VTQF_TqRawChgRate_Nmps;/* '<S795>/Switch' */
extern MONPRM volatile float32 VTQF_WhlDrgMaxTqZX_Nm;/* '<S794>/Switch1' */
extern MONPRM volatile float32 VTQF_WhlDrvMaxTqZX_Nm;/* '<S794>/Switch7' */
extern MONPRM volatile boolean VTQR_ASDEnbl_flg;/* '<S799>/Logical Operator14' */
extern MONPRM volatile float32 VTQR_ASDSpdFltHi_rpm;/* '<S807>/Switch' */
extern MONPRM volatile float32 VTQR_ASDSpdOscRaw_rpm;/* '<S803>/Add1' */
extern MONPRM volatile float32 VTQR_ASDSpdOsc_rpm;/* '<S805>/Multiport Switch' */
extern MONPRM volatile float32 VTQR_ASDTqReqRaw_Nm;/* '<S811>/MinMax5' */
extern MONPRM volatile float32 VTQR_ASDTqReq_Nm;/* '<S804>/Switch3' */
extern MONPRM volatile boolean VTQR_MotDampngEnbl_flg;/* '<S799>/Logical Operator1' */
extern MONPRM volatile float32 VTQR_MotDampngLmt_Nm;/* '<S819>/MinMax5' */
extern MONPRM volatile EnumMotorDirReq VTQR_MotorDirReq_enum;/* '<S800>/Switch4' */
extern MONPRM volatile EnumMotorModeReq VTQR_MotorModeReq_enum;/* '<S797>/Signal Conversion15' */
extern MONPRM volatile float32 VTQR_MotorSpdReq_rpm;/* '<S797>/Signal Conversion1' */
extern MONPRM volatile boolean VTQR_MotorStdby_flg;/* '<S801>/Logical Operator1' */
extern MONPRM volatile float32 VTQR_MotorTqReq_Nm;/* '<S797>/Signal Conversion2' */
extern MONPRM volatile float32 VTZX_AZDecRate_Nmps;/* '<S835>/1-D Lookup Table4' */
extern MONPRM volatile float32 VTZX_AZIncRate_Nmps;/* '<S835>/1-D Lookup Table3' */
extern MONPRM volatile float32 VTZX_BZDecRate_Nmps;/* '<S835>/1-D Lookup Table2' */
extern MONPRM volatile float32 VTZX_BZIncRate_Nmps;/* '<S835>/1-D Lookup Table1' */
extern MONPRM volatile boolean VTZX_BypZX_flg;/* '<S839>/Logical Operator1' */
extern MONPRM volatile boolean VTZX_ClkActv_flg;/* '<S838>/Switch4' */
extern MONPRM volatile float32 VTZX_ClkZXTm_s;/* '<S831>/Switch1' */
extern MONPRM volatile float32 VTZX_MotorTqReqPrdt_Nm;/* '<S851>/MinMax5' */
extern MONPRM volatile float32 VTZX_MotorTqReqZX_Nm;/* '<S836>/TqZXSt' */
extern MONPRM volatile float32 VTZX_MotorTqReq_Nm;/* '<S831>/Switch6' */
extern MONPRM volatile boolean VTZX_TqInc_flg;/* '<S845>/Switch4' */
extern MONPRM volatile boolean VTZX_TqRateLimRamp_flg;/* '<S852>/Switch4' */
extern MONPRM volatile EnumTZXStat VTZX_TqZXSt_enum;/* '<S836>/Data Type Conversion1' */
extern MONPRM volatile float32 VTZX_ZeroTqHldDec_Nm;/* '<S836>/TqZXSt' */
extern MONPRM volatile float32 VTZX_ZeroTqHldInc_Nm;/* '<S836>/TqZXSt' */
extern MONPRM volatile float32 VTZX_ZeroTqOfstDec_Nm;/* '<S835>/Switch3' */
extern MONPRM volatile float32 VTZX_ZeroTqOfstInc_Nm;/* '<S835>/Switch2' */
extern MONPRM volatile float32 VTZX_ZeroTqOfst_Nm;/* '<S835>/Switch4' */
extern MONPRM volatile float32 VTZX_ZeroXTm_s;/* '<S835>/Switch8' */
extern MONPRM volatile uint8 VVCU_ECURstCntr_cnt;/* '<S44>/Switch2' */

/* 控制器Reset计数器 */
extern MONPRM volatile float32 VVSO_ALatSnsr_mps2;/* '<S451>/Switch1' */
extern MONPRM volatile float32 VVSO_ALgtSnsr_mps2;/* '<S450>/Switch1' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr1_mpkm;/* '<S512>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr2_mpkm;/* '<S512>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr3_mpkm;/* '<S512>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr4_mpkm;/* '<S512>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr5_mpkm;/* '<S512>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr_mpkm;/* '<S512>/Add3' */
extern MONPRM volatile float32 VVSO_DrvDist_m;/* '<S525>/Switch1' */
extern MONPRM volatile boolean VVSO_RSEBrkPresrConf_flg;/* '<S497>/Relational Operator2' */
extern MONPRM volatile boolean VVSO_RSESigConf_flg;/* '<S483>/Logical Operator3' */
extern MONPRM volatile boolean VVSO_RSEVehSpdConf_flg;/* '<S499>/Logical Operator2' */
extern MONPRM volatile boolean VVSO_RSEWhlSlipConf_flg;/* '<S500>/Logical Operator2' */
extern MONPRM volatile boolean VVSO_RSEYawRateConf_flg;/* '<S501>/Logical Operator' */
extern MONPRM volatile float32 VVSO_RoadSlopCalcRaw_pct;/* '<S481>/Product19' */
extern MONPRM volatile boolean VVSO_RoadSlopEstVld_flg;/* '<S480>/Logical Operator1' */
extern MONPRM volatile float32 VVSO_RoadSlopEst_pct;/* '<S480>/Switch2' */
extern MONPRM volatile float32 VVSO_RoadSlopTqEst_Nm;/* '<S496>/MinMax5' */
extern MONPRM volatile float32 VVSO_VehDrvResistTq_Nm;/* '<S482>/Switch5' */
extern MONPRM volatile boolean VVSO_VehMassConf_flg;/* '<S528>/Logical Operator4' */
extern MONPRM volatile uint8 VVSO_VehMassDistb_enum;/* '<S528>/Signal Conversion' */
extern MONPRM volatile float32 VVSO_VehMassEst_kg;/* '<S531>/Switch' */
extern MONPRM volatile float32 VVSO_VehSpd_mps;/* '<S528>/Gain3' */
extern MONPRM volatile float32 VVSO_WhlAcceltnFL_mps2;/* '<S463>/Divide' */
extern MONPRM volatile float32 VVSO_WhlAcceltnFR_mps2;/* '<S464>/Divide' */
extern MONPRM volatile float32 VVSO_WhlAcceltnRL_mps2;/* '<S465>/Divide' */
extern MONPRM volatile float32 VVSO_WhlAcceltnRR_mps2;/* '<S466>/Divide' */
extern MONPRM volatile boolean VVSO_WhlDistErrHld_flg;/* '<S516>/OR' */
extern MONPRM volatile float32 VVSO_WhlLgtFrc_N;/* '<S533>/Add' */
extern MONPRM volatile EnumXWhlDistErrRefSt VVSO_XWhlDistErrRefStat_enum;/* '<S512>/Signal Conversion2' */
extern MONPRM volatile float32 VVSO_XWhlDistErrRef_mpkm;/* '<S512>/Signal Conversion1' */
extern MONPRM volatile float32 VVSO_XWhlDistErr_m;/* '<S525>/Switch4' */
extern MONPRM volatile float32 VVSO_YawRateBas_degps;/* '<S457>/Switch' */
extern MONPRM volatile float32 VVSO_YawRateDer_radps2;/* '<S452>/Add6' */
extern MONPRM volatile float32 VVSO_YawRateFilt_radps;/* '<S456>/Switch' */
extern MONPRM volatile boolean VVSO_iTPMSAvail_flg;/* '<S516>/Logical Operator' */
extern MONPRM volatile EnumiTPMSSt VVSO_iTPMSState_enum;/* '<S512>/Signal Conversion' */
extern MONPRM volatile boolean VVSO_iTPMSWrng_flg;/* '<S512>/Signal Conversion3' */
extern MONPRM volatile boolean VVTM_BrkPedReld_flg;/* '<S877>/Logical Operator3' */
extern MONPRM volatile uint8 VVTM_DrvMotorSta_enum;/* '<S884>/DriveMotorState' */
extern MONPRM volatile boolean VVTM_ESPIntvActv_flg;/* '<S877>/Logical Operator4' */
extern MONPRM volatile float32 VVTM_MotorActPwr_kW;/* '<S891>/Switch2' */
extern MONPRM volatile float32 VVTM_MotorSpd_rpm;/* '<S879>/Switch' */
extern MONPRM volatile boolean VVTM_PCUFailSta_flg;/* '<S884>/Logical Operator2' */
extern MONPRM volatile boolean VVTM_RegenReqBrkLampOn_flg;/* '<S889>/Switch1' */
extern MONPRM volatile float32 VVTM_RsrvPwr_kW;/* '<S886>/MinMax4' */
extern MONPRM volatile float32 VVTM_RsrvRecupPwr_kW;/* '<S886>/MinMax1' */
extern MONPRM volatile float32 VVTM_VehAcceltn_mps2;/* '<S882>/Switch' */
extern MONPRM volatile uint8 VVTM_VehActGrPstn_enum;/* '<S877>/Switch1' */
extern MONPRM volatile float32 VVTM_VehSpd_kph;/* '<S878>/Switch' */

#endif                                 /* RTW_HEADER_monPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
