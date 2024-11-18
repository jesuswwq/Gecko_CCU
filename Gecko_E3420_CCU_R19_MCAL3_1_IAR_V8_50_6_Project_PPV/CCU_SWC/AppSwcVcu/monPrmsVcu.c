/*
 * File: monPrmsVcu.c
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

#include "monPrmsVcu.h"
#include "AppSwcVcu.h"

/* Exported data definition */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Definition for custom storage class: Volatile */
MONPRM volatile boolean BSW_RTCWakeup_flg = false;/* '<S1053>/Switch4' */

/* RTC���ѱ�־λ_versteckt */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Day = ((uint8)0U);/* '<S100>/Data Type Conversion45' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Hour = ((uint8)0U);/* '<S100>/Data Type Conversion1' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Min = ((uint8)0U);/* '<S100>/Data Type Conversion2' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Month = ((uint8)0U);/* '<S100>/Data Type Conversion34' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Sec = ((uint8)0U);/* '<S100>/Switch2' */
MONPRM volatile uint8 UDS_TBOX_BJS_Time_Year = ((uint8)0U);/* '<S100>/Data Type Conversion33' */
MONPRM volatile uint8 VBSW_WakeupReasn_enum = ((uint8)0U);/* '<S1573>/EcuWakeupReasn' */
MONPRM volatile float32 VCPT_MotorDrgMaxTq_Nm = 0.0F;/* '<S1230>/MinMax6' */
MONPRM volatile float32 VCPT_MotorDrvMaxTq_Nm = 0.0F;/* '<S1230>/MinMax7' */
MONPRM volatile float32 VCPT_MotorGenMaxTq_Nm = 0.0F;/* '<S1242>/Switch1' */
MONPRM volatile float32 VCPT_MotorMotMaxTq_Nm = 0.0F;/* '<S1241>/Switch1' */
MONPRM volatile boolean VCPT_MotorSpdRvrs_flg = false;/* '<S1230>/Switch3' */
MONPRM volatile float32 VCPT_MotorSpd_rpm = 0.0F;/* '<S1236>/Switch' */
MONPRM volatile float32 VCPT_WhlDrgMaxTq_Nm = 0.0F;/* '<S1230>/MinMax1' */
MONPRM volatile float32 VCPT_WhlDrvMaxTq_Nm = 0.0F;/* '<S1230>/MinMax8' */
MONPRM volatile boolean VDAC_ACCAvail_flg = false;/* '<S1251>/Logical Operator9' */
MONPRM volatile float32 VDAC_ACCDeltaAcceltn_mps2 = 0.0F;/* '<S1258>/Add5' */
MONPRM volatile float32 VDAC_ACCDsrdTqFF_Nm = 0.0F;/* '<S1258>/Add3' */
MONPRM volatile float32 VDAC_ACCDsrdTqI_N = 0.0F;/* '<S1258>/Saturation1' */
MONPRM volatile float32 VDAC_ACCDsrdTqPID_Nm = 0.0F;/* '<S1258>/Product6' */
MONPRM volatile float32 VDAC_ACCDsrdTqP_N = 0.0F;/* '<S1258>/Product3' */
MONPRM volatile boolean VDAC_ACCEnbl_flg = false;/* '<S1251>/Logical Operator3' */
MONPRM volatile boolean VDAC_ACCOvrd_flg = false;/* '<S1252>/Logical Operator22' */
MONPRM volatile uint8 VDAC_ACCStat_enum = ((uint8)0U);/* '<S1253>/Switch1' */
MONPRM volatile float32 VDAC_ACCTqReqWhl_Nm = 0.0F;/* '<S1254>/Merge3' */
MONPRM volatile boolean VDAC_CCActv2Stby_flg = false;/* '<S1294>/Logical Operator15' */
MONPRM volatile boolean VDAC_CCActvBascCond_flg = false;/* '<S1294>/Logical Operator1' */
MONPRM volatile float32 VDAC_CCDeltaAcceltn_mps2 = 0.0F;/* '<S1281>/Add3' */
MONPRM volatile float32 VDAC_CCDsrdAcceltnRaw_mps2 = 0.0F;/* '<S1274>/Saturation1' */
MONPRM volatile float32 VDAC_CCDsrdAcceltn_mps2 = 0.0F;/* '<S1272>/Merge1' */
MONPRM volatile float32 VDAC_CCDsrdTqFF_N = 0.0F;/* '<S1280>/Add3' */
MONPRM volatile float32 VDAC_CCDsrdTqI_N = 0.0F;/* '<S1281>/Saturation1' */
MONPRM volatile float32 VDAC_CCDsrdTqPID_N = 0.0F;/* '<S1281>/Add2' */
MONPRM volatile float32 VDAC_CCDsrdTqP_N = 0.0F;/* '<S1281>/Product2' */
MONPRM volatile boolean VDAC_CCEnbl_flg = false;/* '<S1295>/Logical Operator2' */
MONPRM volatile uint16 VDAC_CCNoActvCond_enum = ((uint16)0U);/* '<S1297>/Add' */
MONPRM volatile boolean VDAC_CCOvrd_flg = false;/* '<S1268>/Logical Operator22' */
MONPRM volatile uint16 VDAC_CCQuitCond_enum = ((uint16)0U);/* '<S1298>/Add' */
MONPRM volatile float32 VDAC_CCSpdUnstabTm_s = 0.0F;/* '<S1310>/Saturation' */
MONPRM volatile boolean VDAC_CCSpdUnstab_flg = false;/* '<S1310>/Relational Operator8' */
MONPRM volatile EnumCCState VDAC_CCSt_enum = EnumCCState_Off;/* '<S1269>/CC_State_Chart' */
MONPRM volatile boolean VDAC_CCStby2Actv_flg = false;/* '<S1294>/Logical Operator9' */
MONPRM volatile float32 VDAC_CCTgtSpdCtrl_kph = 0.0F;/* '<S1319>/Switch1' */
MONPRM volatile uint8 VDAC_CCTgtSpdHU_kph = ((uint8)0U);/* '<S1270>/TgtSpdCalc' */
MONPRM volatile EnumCCTgtSpdSt VDAC_CCTgtSpdSt_enum = EnumCCTgtSpdSt_Reset;/* '<S1270>/TgtSpdCalc' */
MONPRM volatile float32 VDAC_CCTgtSpd_kph = 0.0F;/* '<S1270>/MinMax7' */
MONPRM volatile float32 VDAC_CCTqReqWhl_Nm = 0.0F;/* '<S1273>/Merge2' */
MONPRM volatile float32 VDAC_CCVehSpdNonDrvn_kph = 0.0F;/* '<S1276>/Switch' */
MONPRM volatile boolean VDAC_CruzCncl_flg = false;/* '<S1335>/Chart' */
MONPRM volatile EnumCruiseStatus VDAC_CruzCtrlStat_enum =
  EnumCruiseStatus_NormOff;            /* '<S1268>/Switch2' */
MONPRM volatile boolean VDAC_CruzCtrlSwVld_flg = false;/* '<S1271>/Signal Conversion1' */
MONPRM volatile boolean VDAC_CruzOn_flg = true;/* '<S1271>/Signal Conversion2' */
MONPRM volatile boolean VDAC_CruzRsmActv_flg = false;/* '<S1332>/Switch4' */
MONPRM volatile boolean VDAC_CruzSetActv_flg = false;/* '<S1330>/Switch4' */
MONPRM volatile boolean VDAC_CruzSpdDecActv_flg = false;/* '<S1331>/Switch4' */
MONPRM volatile boolean VDAC_CruzSpdIncActv_flg = false;/* '<S1333>/Switch4' */
MONPRM volatile float32 VDAC_DrvAsstTqSplitEHB_Nm = 0.0F;/* '<S1247>/MinMax2' */
MONPRM volatile float32 VDAC_DrvAsstTqSplitINV_Nm = 0.0F;/* '<S1247>/Add1' */
MONPRM volatile uint8 VDAC_DrvAsstTqSts_enum = ((uint8)0U);/* '<S1247>/Switch1' */
MONPRM volatile float32 VDAC_DrvAsstTqTgt_Nm = 0.0F;/* '<S1247>/Switch2' */
MONPRM volatile boolean VDAC_EnblEHBBrkRun_flg = false;/* '<S1366>/Switch4' */
MONPRM volatile boolean VDAC_HDCActv2Idle_flg = false;/* '<S1342>/Logical Operator11' */
MONPRM volatile boolean VDAC_HDCActv2Stdby_flg = false;/* '<S1342>/Logical Operator8' */
MONPRM volatile float32 VDAC_HDCDeltaAcceltn_mps2 = 0.0F;/* '<S1347>/Add5' */
MONPRM volatile float32 VDAC_HDCDsrdTqFF_Nm = 0.0F;/* '<S1347>/Add3' */
MONPRM volatile float32 VDAC_HDCDsrdTqI_N = 0.0F;/* '<S1347>/Saturation1' */
MONPRM volatile float32 VDAC_HDCDsrdTqPID_Nm = 0.0F;/* '<S1347>/Product6' */
MONPRM volatile float32 VDAC_HDCDsrdTqP_N = 0.0F;/* '<S1347>/Product3' */
MONPRM volatile boolean VDAC_HDCIdle2Stdby_flg = false;/* '<S1342>/Logical Operator2' */
MONPRM volatile EnumHDCState VDAC_HDCSt_enum = EnumHDCState_Idle;/* '<S1245>/HDC_State_Chart' */
MONPRM volatile boolean VDAC_HDCStdby2Actv_flg = false;/* '<S1342>/Logical Operator13' */
MONPRM volatile boolean VDAC_HDCStdby2Idle_flg = false;/* '<S1342>/Logical Operator3' */
MONPRM volatile float32 VDAC_HDCTgtAcceltn_mps2 = 0.0F;/* '<S1339>/Merge1' */
MONPRM volatile float32 VDAC_HDCTgtSpd_kph = 0.0F;/* '<S1245>/HDC_State_Chart' */
MONPRM volatile float32 VDAC_HDCTqReqWhl_Nm = 0.0F;/* '<S1339>/Merge2' */
MONPRM volatile uint8 VDAC_HDCVehSpdHU_kph = ((uint8)0U);/* '<S1340>/Switch1' */
MONPRM volatile float32 VDAC_MstrCylPresrReq_bar = 0.0F;/* '<S1247>/Switch13' */
MONPRM volatile uint8 VDAC_VehSpdHU_kph = ((uint8)0U);/* '<S1321>/Switch1' */
MONPRM volatile uint8 VDAC_VirtAccPedPstnSta_enum = ((uint8)0U);/* '<S1247>/Switch11' */
MONPRM volatile float32 VDAC_VirtAccPedPstn_pct = 0.0F;/* '<S1247>/Switch8' */
MONPRM volatile float32 VDAC_VirtAccelPedPstnRaw_pct = 0.0F;/* '<S1247>/Switch9' */
MONPRM volatile float32 VDAC_VirtPedPstn_pct = 0.0F;/* '<S1247>/Switch4' */
MONPRM volatile uint8 VDAG_ACCMHVILFltSt_enum = ((uint8)0U);/* '<S568>/FltStDeb' */

/* ѹ������ѹ��������״̬ */
MONPRM volatile uint8 VDAG_ACChrgStFailFltSt_enum = ((uint8)0U);/* '<S401>/FltStDeb' */

/* ACChargeStateFail����״̬ */
MONPRM volatile uint8 VDAG_ACDchaBMSPwrLoFltSt_enum = ((uint8)0U);/* '<S407>/FltStDeb' */

/* AC�ŵ�BMS���ʵ͹���״̬ */
MONPRM volatile uint8 VDAG_ACDchaBMSSOCLoFltSt_enum = ((uint8)0U);/* '<S406>/FltStDeb' */

/* AC�ŵ�BMSSOC�͹���״̬ */
MONPRM volatile uint8 VDAG_ACDchaOverPwrFltSt_enum = ((uint8)0U);/* '<S400>/FltStDeb' */

/* AC�ŵ繦�ʳ��޹��� */
MONPRM volatile uint8 VDAG_ACSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S133>/FltStDeb' */

/* ACSCmd��ʱ����״̬ */
MONPRM volatile uint8 VDAG_AccPed1ShtBattFltSt_enum = ((uint8)0U);/* '<S542>/FltStDeb' */

/* ����̤��1·�̵�Դ����״̬ */
MONPRM volatile uint8 VDAG_AccPed1ShtGndFltSt_enum = ((uint8)0U);/* '<S539>/FltStDeb' */

/* ����̤��1·�̵ع���״̬ */
MONPRM volatile uint8 VDAG_AccPed1SuplyShtCircFltSt_enum = ((uint8)0U);/* '<S540>/FltStDeb' */

/* ����̤��1·�����·����״̬ */
MONPRM volatile uint8 VDAG_AccPed2ShtBattFltSt_enum = ((uint8)0U);/* '<S535>/FltStDeb' */

/* ����̤��2·�̵�Դ����״̬ */
MONPRM volatile uint8 VDAG_AccPed2ShtGndFltSt_enum = ((uint8)0U);/* '<S543>/FltStDeb' */

/* ����̤��2·�̵ع���״̬ */
MONPRM volatile uint8 VDAG_AccPed2SuplyShtCircFltSt_enum = ((uint8)0U);/* '<S541>/FltStDeb' */

/* ����̤��2·�����·����״̬ */
MONPRM volatile uint8 VDAG_AccPedBothFailFltSt_enum = ((uint8)0U);/* '<S537>/FltStDeb' */

/* ����̤��˫·ʧЧ����״̬ */
MONPRM volatile uint8 VDAG_AccPedCrsChkFltSt_enum = ((uint8)0U);/* '<S536>/FltStDeb' */

/* ����̤���໥У�����״̬ */
MONPRM volatile uint8 VDAG_BMSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S127>/FltStDeb' */

/* BMS�̵���ָ����Ӧ��ʱ����״̬ */
MONPRM volatile uint8 VDAG_BMSEmgcySdnFltSt_enum = ((uint8)0U);/* '<S138>/FltStDeb' */

/* BMS�����µ����״̬ */
MONPRM volatile uint8 VDAG_BMSSOCLoFltSt_enum = ((uint8)0U);/* '<S137>/FltStDeb' */

/* BMSSOC�͹���״̬ */
MONPRM volatile uint8 VDAG_BMSSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S134>/FltStDeb' */

/* BMSFailLevel1����״̬ */
MONPRM volatile uint8 VDAG_BMSSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S135>/FltStDeb' */

/* BMSFailLevel2����״̬ */
MONPRM volatile uint8 VDAG_BMSSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S136>/FltStDeb' */

/* BMSFailLevel3����״̬ */
MONPRM volatile uint8 VDAG_BMSUndrVoltFltSt_enum = ((uint8)0U);/* '<S139>/FltStDeb' */

/* BMSPackǷѹ����״̬ */
MONPRM volatile uint8 VDAG_BrkPedShtBattFltSt_enum = ((uint8)0U);/* '<S565>/FltStDeb' */

/* �ƶ�̤��̵�Դ����״̬ */
MONPRM volatile uint8 VDAG_BrkPedShtGndFltSt_enum = ((uint8)0U);/* '<S563>/FltStDeb' */

/* �ƶ�̤��̵ع���״̬ */
MONPRM volatile uint8 VDAG_BrkSwCrsChkCnt_cnt = ((uint8)0U);/* '<S555>/Data Type Conversion' */

/* �ƶ������໥У�������� */
MONPRM volatile uint8 VDAG_BrkSwCrsChkFltSt_enum = ((uint8)0U);/* '<S564>/FltStDeb' */

/* �ƶ������໥У�����״̬ */
MONPRM volatile uint8 VDAG_CellUndrVoltFltSt_enum = ((uint8)0U);/* '<S140>/FltStDeb' */

/* BMSCellǷѹ����״̬ */
MONPRM volatile uint8 VDAG_DCCCmdTmOutFltSt_enum = ((uint8)0U);/* '<S301>/FltStDeb' */

/* DCDCģʽָ����Ӧ��ʱ����״̬ */
MONPRM volatile uint8 VDAG_DCCInVoltLoFltSt_enum = ((uint8)0U);/* '<S302>/FltStDeb' */

/* DCDC�����ѹ�͹���״̬ */
MONPRM volatile uint8 VDAG_DCCModeFltFltSt_enum = ((uint8)0U);/* '<S300>/FltStDeb' */

/* DCDCModeFault����״̬ */
MONPRM volatile uint8 VDAG_DCCSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S296>/FltStDeb' */

/* DCDCFailLevel1����״̬ */
MONPRM volatile uint8 VDAG_DCCSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S297>/FltStDeb' */

/* DCDCFailLevel2����״̬ */
MONPRM volatile uint8 VDAG_DCCSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S298>/FltStDeb' */

/* DCDCFailLevel3����״̬ */
MONPRM volatile uint8 VDAG_DCCSysFailLvl4FltSt_enum = ((uint8)0U);/* '<S299>/FltStDeb' */

/* DCDCFailLevel4����״̬ */
MONPRM volatile uint8 VDAG_DCSChrgReqFltSt_enum = ((uint8)0U);/* '<S131>/FltStDeb' */

/* DCSChargeRequest����״̬ */
MONPRM volatile uint8 VDAG_DCSCmdTmOutFltSt_enum = ((uint8)0U);/* '<S141>/FltStDeb' */

/* DCSCmd��ʱ����״̬ */
MONPRM volatile uint8 VDAG_DCSFailStaFltSt_enum = ((uint8)0U);/* '<S129>/FltStDeb' */

/* DCSFailState����״̬ */
MONPRM volatile uint8 VDAG_DCSInletConnectFltSt_enum = ((uint8)0U);/* '<S130>/FltStDeb' */

/* DCS��ǹ����״̬ */
MONPRM volatile uint8 VDAG_DCSModeFailFltSt_enum = ((uint8)0U);/* '<S132>/FltStDeb' */

/* DCSModeFail����״̬ */
MONPRM volatile uint8 VDAG_EHBFltLvl1FltSt_enum = ((uint8)0U);/* '<S473>/FltStDeb' */

/* EHB1������״̬ */
MONPRM volatile uint8 VDAG_EHBFltLvl2FltSt_enum = ((uint8)0U);/* '<S474>/FltStDeb' */

/* EHB2������״̬ */
MONPRM volatile uint8 VDAG_EHBFltLvl3FltSt_enum = ((uint8)0U);/* '<S475>/FltStDeb' */

/* EHB3������״̬ */
MONPRM volatile uint8 VDAG_EHBFltLvl4FltSt_enum = ((uint8)0U);/* '<S467>/FltStDeb' */

/* EHB4������״̬ */
MONPRM volatile uint8 VDAG_EHBFltLvl5FltSt_enum = ((uint8)0U);/* '<S476>/FltStDeb' */

/* EHB5������״̬ */
MONPRM volatile uint8 VDAG_ESCFltLvl1FltSt_enum = ((uint8)0U);/* '<S478>/FltStDeb' */

/* ESC1������״̬ */
MONPRM volatile uint8 VDAG_ESCFltLvl2FltSt_enum = ((uint8)0U);/* '<S468>/FltStDeb' */

/* ESC2������״̬ */
MONPRM volatile uint8 VDAG_ESCFltLvl3FltSt_enum = ((uint8)0U);/* '<S469>/FltStDeb' */

/* ESC3������״̬ */
MONPRM volatile uint8 VDAG_ESCFltLvl4FltSt_enum = ((uint8)0U);/* '<S477>/FltStDeb' */

/* ESC4������״̬ */
MONPRM volatile uint8 VDAG_ESCFltLvl5FltSt_enum = ((uint8)0U);/* '<S470>/FltStDeb' */

/* ESC5������״̬ */
MONPRM volatile uint8 VDAG_ESCVehSpdInvldFltSt_enum = ((uint8)0U);/* '<S472>/FltStDeb' */

/* ����ʧЧ����״̬ */
MONPRM volatile boolean VDAG_EmgcyShtdwn_flg = false;/* '<S91>/Switch30' */
MONPRM volatile uint16 VDAG_ErrCode_enum = ((uint16)0U);/* '<S89>/Err_State' */
MONPRM volatile boolean VDAG_FanFullSpdOn_flg = false;/* '<S91>/Switch3' */
MONPRM volatile boolean VDAG_FbdACC_flg = false;/* '<S91>/Switch28' */
MONPRM volatile boolean VDAG_FbdACChrg_flg = false;/* '<S91>/Switch32' */
MONPRM volatile boolean VDAG_FbdACDcha_flg = false;/* '<S91>/Switch34' */
MONPRM volatile boolean VDAG_FbdAC_flg = false;/* '<S91>/Switch35' */
MONPRM volatile boolean VDAG_FbdCC_flg = false;/* '<S91>/Switch26' */
MONPRM volatile boolean VDAG_FbdDCChrg_flg = false;/* '<S91>/Switch33' */
MONPRM volatile boolean VDAG_FbdDCDC_flg = false;/* '<S91>/Switch31' */
MONPRM volatile boolean VDAG_FbdDRGr_flg = false;/* '<S91>/Switch25' */
MONPRM volatile boolean VDAG_FbdDrvTq_flg = false;/* '<S91>/Switch23' */
MONPRM volatile boolean VDAG_FbdHV_flg = false;/* '<S91>/Switch29' */
MONPRM volatile boolean VDAG_FbdLSP_flg = false;/* '<S91>/Switch27' */
MONPRM volatile boolean VDAG_FltLampOn_flg = false;/* '<S91>/Switch36' */
MONPRM volatile uint8 VDAG_FltLvl_enum = ((uint8)0U);/* '<S91>/MinMax' */
MONPRM volatile uint8 VDAG_FrstHVILVoltHiFltSt_enum = ((uint8)0U);/* '<S567>/FltStDeb' */

/* ��Ҫ��ѹ������ѹ�߹���״̬ */
MONPRM volatile uint8 VDAG_FrstHVILVoltLoFltSt_enum = ((uint8)0U);/* '<S566>/FltStDeb' */

/* ��Ҫ��ѹ������ѹ�͹���״̬ */
MONPRM volatile uint8 VDAG_GearShftInvldFltSt_enum = ((uint8)0U);/* '<S471>/FltStDeb' */

/* ��������ʧЧ����״̬ */
MONPRM volatile uint8 VDAG_HVIsoResistLoFltSt_enum = ((uint8)0U);/* '<S128>/FltStDeb' */

/* ��ѹ��ؾ�Ե����״̬ */
MONPRM volatile uint8 VDAG_INVFltLvl1FltSt_enum = ((uint8)0U);/* '<S367>/FltStDeb' */

/* INVFaultLevel1����״̬ */
MONPRM volatile uint8 VDAG_INVFltLvl2FltSt_enum = ((uint8)0U);/* '<S368>/FltStDeb' */

/* INVFaultLevel2����״̬ */
MONPRM volatile uint8 VDAG_INVFltLvl3FltSt_enum = ((uint8)0U);/* '<S369>/FltStDeb' */

/* INVFaultLevel3����״̬ */
MONPRM volatile uint8 VDAG_INVFltLvl4FltSt_enum = ((uint8)0U);/* '<S370>/FltStDeb' */

/* INVFaultLevel4����״̬ */
MONPRM volatile uint8 VDAG_INVInVoltLoFltSt_enum = ((uint8)0U);/* '<S303>/FltStDeb' */

/* INV�����ѹ�͹���״̬ */
MONPRM volatile uint8 VDAG_INVRunCmdRespFltSt_enum = ((uint8)0U);/* '<S371>/FltStDeb' */

/* INVRunָ����Ӧ��ʱ����״̬ */
MONPRM volatile boolean VDAG_LVBatLampOn_flg = false;/* '<S91>/Switch1' */
MONPRM volatile uint8 VDAG_LVBattSOCLoFltSt_enum = ((uint8)0U);/* '<S515>/FltStDeb' */

/* ����SOC�͵Ĺ���״̬ */
MONPRM volatile uint8 VDAG_LVBattSOHLoFltSt_enum = ((uint8)0U);/* '<S511>/FltStDeb' */

/* ����SOH�͵Ĺ���״̬ */
MONPRM volatile uint8 VDAG_LVBattTempHiFltSt_enum = ((uint8)0U);/* '<S512>/FltStDeb' */

/* ���ع��¹���״̬ */
MONPRM volatile uint8 VDAG_LVBattVoltHiFltSt_enum = ((uint8)0U);/* '<S514>/FltStDeb' */

/* ���ص�ѹ�߹���״̬ */
MONPRM volatile uint8 VDAG_LVBattVoltLoFltSt_enum = ((uint8)0U);/* '<S513>/FltStDeb' */

/* ���ص�ѹ�͹���״̬ */
MONPRM volatile boolean VDAG_LimpHome_flg = false;/* '<S91>/Switch2' */
MONPRM volatile boolean VDAG_LmtDrvTq_flg = false;/* '<S91>/Switch24' */
MONPRM volatile uint8 VDAG_OBCChrgReqFltSt_enum = ((uint8)0U);/* '<S405>/FltStDeb' */

/* OBCChargeRequest����״̬ */
MONPRM volatile uint8 VDAG_OBCConnectTmOutFltSt_enum = ((uint8)0U);/* '<S403>/FltStDeb' */

/* OBC���ӳ�ʱ����״̬ */
MONPRM volatile uint8 VDAG_OBCInletConnectFltSt_enum = ((uint8)0U);/* '<S408>/FltStDeb' */

/* OBC��ǹ����״̬ */
MONPRM volatile uint8 VDAG_OBCModeMsmtchFltSt_enum = ((uint8)0U);/* '<S402>/FltStDeb' */

/* OBCģʽ��ƥ�����״̬ */
MONPRM volatile uint8 VDAG_OBCS2StatFltSt_enum = ((uint8)0U);/* '<S404>/FltStDeb' */

/* OBCS2���ӳ�ʱ����״̬ */
MONPRM volatile uint8 VDAG_OBCSysFailLvl1FltSt_enum = ((uint8)0U);/* '<S409>/FltStDeb' */

/* OBCFailLevel1����״̬ */
MONPRM volatile uint8 VDAG_OBCSysFailLvl2FltSt_enum = ((uint8)0U);/* '<S410>/FltStDeb' */

/* OBCFailLevel2����״̬ */
MONPRM volatile uint8 VDAG_OBCSysFailLvl3FltSt_enum = ((uint8)0U);/* '<S411>/FltStDeb' */

/* OBCFailLevel3����״̬ */
MONPRM volatile uint8 VDAG_OBCSysFailLvl4FltSt_enum = ((uint8)0U);/* '<S399>/FltStDeb' */

/* OBCFailLevel4����״̬ */
MONPRM volatile uint8 VDAG_SecdHVILVoltHiFltSt_enum = ((uint8)0U);/* '<S570>/FltStDeb' */

/* ��Ҫ��ѹ������ѹ�߹���״̬ */
MONPRM volatile uint8 VDAG_SecdHVILVoltLoFltSt_enum = ((uint8)0U);/* '<S569>/FltStDeb' */

/* ��Ҫ��ѹ������ѹ�͹���״̬ */
MONPRM volatile uint8 VDAG_SysPwrModeInvldFltSt_enum = ((uint8)0U);/* '<S465>/FltStDeb' */

/* PowerModeʧЧ����״̬ */
MONPRM volatile uint8 VDAG_TMSFailLvl3FltSt_enum = ((uint8)0U);/* '<S466>/FltStDeb' */

/* TMSRFailLevel3����״̬ */
MONPRM volatile uint8 VDAG_VehCrashFltSt_enum = ((uint8)0U);/* '<S534>/FltStDeb' */

/* ��ײ����״̬ */
MONPRM volatile boolean VDAG_WakeUp_flg = false;/* '<S327>/Chart' */

/* Ӳ�߻��ѻ���IBSLIN���ѱ�־ */
MONPRM volatile uint8 VDAG_WaterTempAbvThrFltSt_enum = ((uint8)0U);/* '<S590>/FltStDeb' */

/* ��ȴˮ�¹��߹���״̬ */
MONPRM volatile uint8 VDAG_WaterTempBlwThrFltSt_enum = ((uint8)0U);/* '<S589>/FltStDeb' */

/* ��ȴˮ�¹��͹���״̬ */
MONPRM volatile float32 VDSA_AcceltnIdxAvg_pct = 0.0F;/* '<S17>/AvgAcceltnIdx' */
MONPRM volatile float32 VDSA_AcceltnIdxRaw_pct = 0.0F;/* '<S17>/Saturation1' */
MONPRM volatile float32 VDSA_BrkPedPstnAvg_pct = 0.0F;/* '<S17>/AvgBrkPedPstn' */
MONPRM volatile float32 VDSA_DrvSprtIdx_pct = 0.0F;/* '<S17>/Saturation2' */
MONPRM volatile boolean VDSA_SprtIdxHldAcc_flg = false;/* '<S17>/Logical Operator3' */
MONPRM volatile boolean VDSA_SprtIdxHldBrk_flg = false;/* '<S17>/Logical Operator6' */
MONPRM volatile float32 VDSA_TqCalcAcceltn_mps2 = 0.0F;/* '<S17>/Divide1' */
MONPRM volatile boolean VEMS_ACCMOprtCmd_flg = false;/* '<S30>/ACCMEnble' */

/* ʹ��ACCM */
MONPRM volatile float32 VEMS_AccPwrRaw_kW = 0.0F;/* '<S31>/MinMax4' */
MONPRM volatile float32 VEMS_CellTempSyn_C = 0.0F;/* '<S85>/Switch1' */
MONPRM volatile float32 VEMS_CellUndrVoltDrtFac_c = 0.0F;/* '<S28>/Saturation3' */
MONPRM volatile float32 VEMS_ChrgCurFbKi_A = 0.0F;/* '<S82>/Saturation' */
MONPRM volatile float32 VEMS_ChrgCurFbKp_A = 0.0F;/* '<S82>/Product2' */
MONPRM volatile float32 VEMS_ChrgCurFb_A = 0.0F;/* '<S82>/Saturation2' */
MONPRM volatile float32 VEMS_ChrgOvrshtPwr_kW = 0.0F;/* '<S27>/Add1' */
MONPRM volatile float32 VEMS_ChrgPwrFbKi_kW = 0.0F;/* '<S46>/Saturation' */
MONPRM volatile float32 VEMS_ChrgPwrFbKp_kW = 0.0F;/* '<S46>/Product2' */
MONPRM volatile float32 VEMS_ChrgPwrFb_kW = 0.0F;/* '<S27>/Merge' */
MONPRM volatile float32 VEMS_DchaCurFbKi_A = 0.0F;/* '<S83>/Saturation' */
MONPRM volatile float32 VEMS_DchaCurFbKp_A = 0.0F;/* '<S83>/Product2' */
MONPRM volatile float32 VEMS_DchaCurFb_A = 0.0F;/* '<S83>/Saturation2' */
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
MONPRM volatile boolean VEMS_TMSActSOCEnbl_flg = false;/* '<S79>/Switch1' */

/* SOC�Ƿ�����TMS */
MONPRM volatile boolean VEMS_TMSPwrEnbl_flg = false;/* '<S30>/Switch3' */

/* �����Ƿ�����TMS */
MONPRM volatile float32 VEMS_TMSUsePwr_kW = 0.0F;/* '<S30>/Subtract' */

/* TMS���ù��� */
MONPRM volatile boolean VEMS_UseConChrgCur_flg = false;/* '<S37>/Switch4' */
MONPRM volatile boolean VEMS_UseConDchaCur_flg = false;/* '<S55>/Switch4' */
MONPRM volatile boolean VGSM_AsstDrvFbShft_flg = false;/* '<S1646>/Logical Operator2' */

/* �淶��ACC/CC��ֹ��λ���� */
MONPRM volatile boolean VGSM_AsstDrvReqEPB_flg = false;/* '<S1632>/Switch4' */

/* ACCͨѶ��ʧ���������EPB */
MONPRM volatile boolean VGSM_DRFlt2N_flg = false;/* '<S1645>/Switch1' */

/* �淶����������������־λ */
MONPRM volatile boolean VGSM_EPBAplyFlt_flg = false;/* '<S1622>/EPBLogical' */

/* ����P-EPB������� */
MONPRM volatile boolean VGSM_EPBRelsFlt_flg = false;/* '<S1622>/EPBLogical' */

/* ����P-EPB�ͷŹ��� */
MONPRM volatile boolean VGSM_GrD2PExcdTm_flg = false;/* '<S1799>/Chart' */

/* D����P����ʱ��N */
MONPRM volatile boolean VGSM_GrNReq2P_flg = false;/* '<S1645>/Switch2' */

/* N���ǻ��������P������ */
MONPRM volatile boolean VGSM_GrR2PExcdTm_flg = false;/* '<S1796>/Chart' */

/* R����P����ʱ��N */
MONPRM volatile boolean VGSM_HldGearP_flg = false;/* '<S1645>/Switch' */

/* �淶������P����־λ */
MONPRM volatile boolean VGSM_INVRunEnbl_flg = false;/* '<S1648>/Chart' */

/* �淶��INVʹ�ܿ��ƣ�����Ť�ؿ��ƣ�-VCU_1_EnaInvRun */
MONPRM volatile uint8 VGSM_PGrSwSts_enum = ((uint8)0U);/* '<S1646>/Switch2' */

/* �淶��P����������־λ-VCU_PGearSwcst */
MONPRM volatile boolean VGSM_ReqEPBAply_flg = false;/* '<S1647>/Logical Operator6' */

/* �淶��EPB���������־λ */
MONPRM volatile boolean VGSM_ReqEPBRels_flg = false;/* '<S1647>/Logical Operator4' */

/* �淶��EPB�ͷ������־λ */
MONPRM volatile EnumEPBReq VGSM_ReqEPB_enum = EnumEPBReq_NoCmd;/* '<S1622>/Switch' */

/* �淶��EPB�����ź�-VCUF_ReqEPB */
MONPRM volatile EnumTgtGearPstn VGSM_ShftTgtGrReq_enum = EnumTgtGearPstn_NoReq;/* '<S1646>/Data Type Conversion1' */

/* ������Ŀ�굵λ 0-NoCmd 1-P 2-N 3-D 4-R  */
MONPRM volatile EnumGearPstn VGSM_VehActGearPstn_enum = EnumGearPstn_P;/* '<S1623>/Switch1' */

/* �淶��ʵ�ʵ�λ-VCU_VhclActlGearPos */
MONPRM volatile boolean VGSM_VehEPBStErr_flg = false;/* '<S1622>/Logical Operator' */

/* �淶��P������PGear error-VCU_VhclPGearError */
MONPRM volatile EnumTgtGearPstn VGSM_VehTgtGrReq_enum = EnumTgtGearPstn_NoReq;/* '<S1647>/Data Type Conversion1' */

/* �淶:Ŀ�굵λ */
MONPRM volatile uint8 VGSM_VehTgtGrTrnsfr_enum = ((uint8)0U);/* '<S1685>/Switch' */

/* �淶�����������ź� */
MONPRM volatile uint8 VHMI_12VBatLowVolSta_enum = ((uint8)0U);/* '<S638>/Switch' */
MONPRM volatile float32 VHMI_GrDSldDist_m = 0.0F;/* '<S652>/Saturation' */

/* D��������� */
MONPRM volatile boolean VHMI_GrDSldSw_flg = false;/* '<S652>/Logical Operator' */

/* D�����¼���/�����־ */
MONPRM volatile float32 VHMI_GrRSldDist_m = 0.0F;/* '<S652>/Saturation1' */

/* R��ǰ����� */
MONPRM volatile boolean VHMI_GrRSldSw_flg = false;/* '<S652>/Logical Operator4' */

/* R�����¼���/�����־ */
MONPRM volatile uint8 VHMI_InfoDisp_enum = ((uint8)0U);/* '<S641>/Arbitration' */

/* �Ǳ���ֵ */
MONPRM volatile boolean VHVM_ACChrgEnbl_flg = false;/* '<S793>/Logical Operator8' */

/* ������������������ */
MONPRM volatile uint8 VHVM_ACChrgMaxCurrFb_A = ((uint8)0U);/* '<S764>/Switch4' */

/* HU���õ������� */
MONPRM volatile uint8 VHVM_ACChrgModeFb_enum = ((uint8)0U);/* '<S764>/Switch7' */

/* HU���ó��ģʽ���� */
MONPRM volatile boolean VHVM_ACChrging2Stop_flg = false;/* '<S787>/AND' */

/* ���������ת�Ƶ����ֹͣ��־λ */
MONPRM volatile boolean VHVM_ACDchaEnbl_flg = false;/* '<S793>/Logical Operator10' */

/* �����ŵ������������ */
MONPRM volatile boolean VHVM_ACDschrging2Stop_flg = false;/* '<S787>/AND7' */

/* �����ŵ���ת�Ƶ��ŵ�ֹͣ��־λ */
MONPRM volatile EnumBMSSdnCmd VHVM_BMSShutdown_enum = EnumBMSSdnCmd_Normal;/* '<S763>/Data Type Conversion10' */

/* VCU�ر�BMSָ���ӦCAN�źţ�VCU_BMS_Shutdown */
MONPRM volatile EnumBMSWakeUpMd VHVM_BMSWakeUpMode_enum = EnumBMSWakeUpMd_Invld;/* '<S763>/Data Type Conversion8' */

/* VCU����BMS�ķ�ʽ��ӦCAN�źţ�VCU_BMS_WakeupMode */
MONPRM volatile boolean VHVM_Bat2DrvTrainEnbl_flg = false;/* '<S763>/MainState' */

/* VCU�������̵���ָ���ӦCAN�źţ�VCU_Bat2DrvTrainEnb */
MONPRM volatile EnumChrgAllwCmd VHVM_ChrgAllowCmd_enum =
  EnumChrgAllwCmd_NotAllwd;            /* '<S763>/Data Type Conversion12' */

/* VCU����������ָ���ӦCAN�źţ�VCU_ChrgAllowCmd */
MONPRM volatile uint8 VHVM_ChrgEnaAC_enum = ((uint8)0U);/* '<S763>/MainState' */

/* VCU����OBC�������ʹ��ָ���ӦCAN�źţ�VCU_ChrgEna_AC */
MONPRM volatile boolean VHVM_ChrgEnaDC_flg = false;/* '<S763>/MainState' */

/* VCU����BMSֱ�����ʹ��ָ���ӦCAN�źţ�VCU_ChrgEna_DC */
MONPRM volatile float32 VHVM_DCCBuckLVVolt_V = 0.0F;/* '<S763>/MainState' */

/* VCU����DCDC BUCK��ѹֵ��ӦCAN�źţ�VCU_DCCBuckLV_Vol */
MONPRM volatile EnumDCCOprtCmd VHVM_DCCOprtCmd_enum = EnumDCCOprtCmd_Off;/* '<S763>/Data Type Conversion6' */

/* VCU����DCDC����ģʽָ���ӦCAN�źţ�VCU_DCCOprtCmd */
MONPRM volatile boolean VHVM_DCChrgEnbl_flg = false;/* '<S793>/Logical Operator2' */

/* ֱ���������������� */
MONPRM volatile boolean VHVM_DCChrging2Over_flg = false;/* '<S787>/AND1' */

/* ֱ�������ת�Ƶ���������־λ */
MONPRM volatile boolean VHVM_ECUSleepAllwd_flg = false;/* '<S763>/MainState' */

/* ����ײ����߱�־λ */
MONPRM volatile boolean VHVM_EmgcySdn_flg = false;/* '<S763>/MainState' */

/* VCU��INV���ͽ����µ�ָ��(INVǿ��ͣ��)��ӦCAN�źţ�VCU_1_EmShutDown */
MONPRM volatile boolean VHVM_EnaDisChg_flg = false;/* '<S763>/MainState' */

/* VCU����INVй��ָ���ӦCAN�źţ�VCU_1_EnaDisChg */
MONPRM volatile boolean VHVM_EngyExtrmLo_flg = false;/* '<S766>/Logical Operator17' */

/* ����������ͱ�־λ */
MONPRM volatile boolean VHVM_INVEnbl_flg = false;/* '<S763>/MainState' */

/* VCUӲ�߻���INV */
MONPRM volatile boolean VHVM_INVPreprogmFlg_flg = false;/* '<S788>/Switch1' */

/* INVԤ����������� */
MONPRM volatile float32 VHVM_MaxChrgCurntDC_A = 0.0F;/* '<S763>/MainState' */

/* VCU����BMSֱ�������������ӦCAN�źţ�VCU_MaxChrgCrnt_DC */
MONPRM volatile float32 VHVM_MaxChrgVoltDC_V = 0.0F;/* '<S763>/MainState' */

/* VCU����BMSֱ���������ѹ��ӦCAN�źţ�VCU_MaxChrgVol_DC */
MONPRM volatile float32 VHVM_MaxHVDCCurntAC_A = 0.0F;/* '<S763>/MainState' */

/* VCU����OBC���������������ӦCAN�źţ�VCU_MaxHVDC_Cur_AC */
MONPRM volatile float32 VHVM_MaxHVDCVoltAC_V = 0.0F;/* '<S763>/MainState' */

/* VCU����OBC�����������ѹ��ӦCAN�źţ�VCU_MaxHVDC_Vol_AC */
MONPRM volatile EnumOBCOprtCmd VHVM_OBCOprtCmd_enum = EnumOBCOprtCmd_Standby;/* '<S764>/Data Type Conversion4' */

/* VCU����OBC����ģʽָ���ӦCAN�źţ�VCU_OBCOprtCmd */
MONPRM volatile EnumPTActMd VHVM_PTActOprtMode_enum = EnumPTActMd_OFF;/* '<S763>/Data Type Conversion4' */

/* ��ѹPT״̬ */
MONPRM volatile boolean VHVM_PTRdy2PTStdby_flg = false;/* '<S790>/Switch1' */

/* PTRdy��PTStdby��־λ */
MONPRM volatile boolean VHVM_PTStdby2PTRdy_flg = false;/* '<S790>/Switch' */

/* PTStdby��PTRdy��־λ */
MONPRM volatile boolean VHVM_PowUpSelfChek_flg = false;/* '<S791>/Switch' */

/* ��ѹ�Լ��־λ */
MONPRM volatile boolean VHVM_PwrOn2PwrDwn_flg = false;/* '<S792>/Switch' */

/* ��ѹ�µ����������־λ������/����/������ */
MONPRM volatile boolean VHVM_SOPExtrmLo_flg = false;/* '<S766>/Relational Operator4' */

/* ���SOP���ͣ����ڹر�DCDC */
MONPRM volatile EnumSysSta VHVM_SysSta_enum = EnumSysSta_Sleep;/* '<S763>/Data Type Conversion2' */

/* ��ѹ��״̬ */
MONPRM volatile uint8 VHVM_TBOX2OBC_emun = ((uint8)0U);/* '<S764>/Switch1' */

/* TBOXԶ�̳�ŵ�ָ�� */
MONPRM volatile EnumVCUMode VHVM_VCUMode_enum = EnumVCUMode_PwrOff;/* '<S763>/Data Type Conversion' */

/* ��ѹ��ת̬ */
MONPRM volatile boolean VHVM_VehHalt_flg = false;/* '<S782>/Switch4' */

/* ����ֹͣ��־λ�����ټ��䣩 */
MONPRM volatile boolean VHVM_WakeUp2PwrUpACChrg_flg = false;/* '<S793>/Logical Operator16' */

/* ������绽���ϵ� */
MONPRM volatile boolean VHVM_WakeUp2PwrUpACDcha_flg = false;/* '<S793>/Logical Operator26' */

/* �����ŵ绽���ϵ� */
MONPRM volatile boolean VHVM_WakeUp2PwrUpDCChrg_flg = false;/* '<S793>/Logical Operator4' */

/* ֱ����绽���ϵ� */
MONPRM volatile boolean VHVM_WakeUp2PwrUpIBS_flg = false;/* '<S793>/Logical Operator6' */

/* IBS�����ϵ� */
MONPRM volatile boolean VHVM_WakeUp2PwrUpKL15_flg = false;/* '<S793>/Logical Operator' */

/* K15�����ϵ� */
MONPRM volatile boolean VHVM_WakeUp2PwrUp_flg = false;/* '<S793>/Switch' */

/* ���ѵ��ϸ�ѹ�������㣨����Դ������+��ѹ�Լ�ͨ���� */
MONPRM volatile boolean VHVM_WakeUpBMS_flg = false;/* '<S763>/MainState' */

/* VCUӲ�߻���BMS */
MONPRM volatile boolean VHVM_WakeUpVCU_flg = false;/* '<S794>/Switch' */

/* ���ߵ������������� */
MONPRM volatile boolean VIBS_BMSBatSOCAllow_flg = false;/* '<S1031>/Switch3' */

/* �������SOC�������־λ_versteckt */
MONPRM volatile boolean VIBS_ChgNumAllow_flg = false;/* '<S1031>/AND' */

/* ������������־λ_versteckt */
MONPRM volatile uint8 VIBS_ChgNum_cnt = ((uint8)0U);/* '<S1031>/Switch2' */

/* IBS�������_versteckt */
MONPRM volatile boolean VIBS_ChrgBascCond_flg = false;/* '<S1031>/Logical Operator2' */

/* ��������������㣨�����������ѹ��_versteckt */
MONPRM volatile boolean VIBS_ChrgEnbl_flg = false;/* '<S1031>/Logical Operator7' */

/* IBS���ʹ�ܱ�־λ_versteckt */
MONPRM volatile boolean VIBS_ChrgOver_flg = false;/* '<S1029>/ChrgSt' */

/* IBS���������־λ_versteckt */
MONPRM volatile float32 VIBS_ChrgVoltThr_V = 0.0F;/* '<S1032>/VoltState' */

/* �����ѹ��ֵ_versteckt */
MONPRM volatile float32 VIBS_EnvirTemp_C = 0.0F;/* '<S1051>/Switch' */

/* IBS�����¶�_versteckt */
MONPRM volatile uint8 VIBS_FailChgNum_cnt = ((uint8)0U);/* '<S1031>/Switch5' */

/* IBS����ʧ�ܴ���_versteckt */
MONPRM volatile boolean VIBS_FbRctWup_flg = false;/* '<S1031>/Logical Operator6' */

/* IBS��ֹRTC���ѱ�־λ_versteckt */
MONPRM volatile boolean VIBS_HVReq_flg = false;/* '<S1031>/Switch' */

/* IBS�����ϸ�ѹ��־λ_versteckt */
MONPRM volatile float32 VIBS_HwKL30_V = 0.0F;/* '<S1050>/Switch' */

/* �˲����KL30��ѹ_versteckt */
MONPRM volatile boolean VIBS_NMReq_flg = false;/* '<S1038>/Switch4' */

/* IBS���������־λ_versteckt */
MONPRM volatile uint16 VIBS_NextRtcWupThr_min = ((uint16)0U);/* '<S1032>/Switch1' */

/* �´β��绽��RTC��ʱ��_versteckt */
MONPRM volatile EnumIBSChrgSt VIBS_RTCChrgSt_enum = EnumIBSChrgSt_Idle;/* '<S1029>/Data Type Conversion' */

/* IBS����״̬_versteckt */
MONPRM volatile boolean VIBS_RTCWakeup_flg = false;/* '<S1056>/Chart' */

/* RTC���ѱ�־λ�����ӳ�ʱ�䣩_versteckt */
MONPRM volatile boolean VIBS_SleepAllwd_flg = false;/* '<S1031>/SleepAllwd' */

/* IBS����ײ����߱�־λ_versteckt */
MONPRM volatile uint16 VIBS_WupChgTmThr_min = ((uint16)0U);/* '<S1032>/Switch2' */

/* IBS����ʱ����ֵ_versteckt */
MONPRM volatile boolean VIBS_WupVoltAllow_flg = false;/* '<S1052>/Switch4' */

/* KL30��ѹ�����־λ_versteckt */
MONPRM volatile boolean VIPC_ACCCfgd_flg = false;/* '<S903>/Switch8' */
MONPRM volatile boolean VIPC_AccPed1Flt_flg = false;/* '<S907>/Logical Operator1' */
MONPRM volatile boolean VIPC_AccPed1LrnDwnActv_flg = false;/* '<S917>/Relational Operator' */
MONPRM volatile boolean VIPC_AccPed1LrnUpActv_flg = false;/* '<S910>/Logical Operator5' */
MONPRM volatile float32 VIPC_AccPed1MinPstnLrnd_pct = 0.0F;/* '<S910>/Switch2' */
MONPRM volatile float32 VIPC_AccPed1NormzAvg_pct = 0.0F;/* '<S916>/Switch' */
MONPRM volatile float32 VIPC_AccPed1NormzPstn_pct = 0.0F;/* '<S907>/Switch5' */
MONPRM volatile float32 VIPC_AccPed1SclPstn_pct = 0.0F;/* '<S911>/Divide1' */
MONPRM volatile boolean VIPC_AccPed2Flt_flg = false;/* '<S907>/Logical Operator2' */
MONPRM volatile boolean VIPC_AccPed2LrnDwnActv_flg = false;/* '<S921>/Relational Operator' */
MONPRM volatile boolean VIPC_AccPed2LrnUpActv_flg = false;/* '<S912>/Logical Operator5' */
MONPRM volatile float32 VIPC_AccPed2MinPstnLrnd_pct = 0.0F;/* '<S912>/Switch2' */
MONPRM volatile float32 VIPC_AccPed2NormzAvg_pct = 0.0F;/* '<S920>/Switch' */
MONPRM volatile float32 VIPC_AccPed2NormzPstn_pct = 0.0F;/* '<S907>/Switch7' */
MONPRM volatile float32 VIPC_AccPed2SclPstn_pct = 0.0F;/* '<S913>/Divide5' */
MONPRM volatile boolean VIPC_AccPedPstnVld_flg = false;/* '<S909>/Switch3' */
MONPRM volatile float32 VIPC_AccPedPstn_pct = 0.0F;/* '<S905>/MinMax3' */
MONPRM volatile uint8 VIPC_AccPedSnsrSta_enum = ((uint8)0U);/* '<S909>/Switch3' */
MONPRM volatile boolean VIPC_AccPedStkActv_flg = false;/* '<S908>/Logical Operator6' */
MONPRM volatile boolean VIPC_AccPedStkBrkPrsd_flg = false;/* '<S935>/Switch4' */
MONPRM volatile float32 VIPC_AccPedStkPstn_pct = 0.0F;/* '<S908>/MinMax' */
MONPRM volatile boolean VIPC_AccPedStkStab_flg = false;/* '<S937>/Relational Operator' */
MONPRM volatile float32 VIPC_AccPedWghtAvg_pct = 0.0F;/* '<S934>/Switch' */
MONPRM volatile float32 VIPC_AccPedWghtPstn_pct = 0.0F;/* '<S909>/Switch3' */
MONPRM volatile float32 VIPC_AccPedZeroPstn_pct = 0.0F;/* '<S908>/Switch' */
MONPRM volatile boolean VIPC_BrkPedPstnVld_flg = false;/* '<S900>/Logical Operator8' */
MONPRM volatile float32 VIPC_BrkPedPstn_pct = 0.0F;/* '<S900>/Saturation1' */
MONPRM volatile boolean VIPC_BrkSwActv_flg = false;/* '<S900>/Logical Operator' */
MONPRM volatile boolean VIPC_CCSCfgd_flg = false;/* '<S903>/Switch1' */
MONPRM volatile boolean VIPC_CrpCtrlCfgd_flg = false;/* '<S903>/Switch2' */
MONPRM volatile EnumCrpModeAct VIPC_CrpModeAct_enum = EnumCrpModeAct_Open;/* '<S902>/Switch12' */
MONPRM volatile EnumDrvModeAct VIPC_DrvModeAct_enum = EnumDrvModeAct_Invalid;/* '<S902>/Switch13' */
MONPRM volatile uint8 VIPC_DrvPwrIntnsty_pct = ((uint8)0U);/* '<S902>/Switch25' */
MONPRM volatile boolean VIPC_DrvSw_flg = false;/* '<S905>/Relational Operator3' */
MONPRM volatile boolean VIPC_EPBAppld_flg = false;/* '<S901>/Logical Operator2' */
MONPRM volatile boolean VIPC_EPBReld_flg = false;/* '<S901>/Logical Operator1' */
MONPRM volatile boolean VIPC_HDCCfgd_flg = false;/* '<S903>/Switch3' */
MONPRM volatile EnumRegenModeAct VIPC_RegenModeAct_enum = EnumRegenModeAct_Off;/* '<S902>/Switch15' */
MONPRM volatile uint8 VIPC_RegenPwrIntnsty_pct = ((uint8)0U);/* '<S902>/Switch28' */
MONPRM volatile boolean VIPC_SnowMode_flg = false;/* '<S902>/Switch14' */
MONPRM volatile float32 VIPC_TireRadius_m = 0.0F;/* '<S903>/TireSizeTable' */
MONPRM volatile uint8 VIPC_VehHiddenMode_enum = ((uint8)0U);/* '<S902>/VehHiddenMode' */
MONPRM volatile float32 VIPC_VehSpdDrvnMotor_kph = 0.0F;/* '<S904>/Product1' */
MONPRM volatile boolean VIPC_VehSpdDrvnVld_flg = false;/* '<S971>/Logical Operator2' */
MONPRM volatile float32 VIPC_VehSpdDrvn_kph = 0.0F;/* '<S971>/Switch7' */
MONPRM volatile boolean VIPC_VehSpdNonDrvnVld_flg = false;/* '<S972>/Logical Operator2' */
MONPRM volatile float32 VIPC_VehSpdNonDrvn_kph = 0.0F;/* '<S972>/Switch7' */
MONPRM volatile boolean VIPC_VehSpdVld_flg = false;/* '<S971>/SignalConversion' */
MONPRM volatile float32 VIPC_VehSpd_kph = 0.0F;/* '<S971>/Switch4' */
MONPRM volatile boolean VIPC_VpedAutoCrp_flg = false;/* '<S959>/Switch4' */
MONPRM volatile boolean VIPC_ZeroPstnRst_flg = false;/* '<S908>/Logical Operator3' */
MONPRM volatile boolean VIPC_iTPMSCfgd_flg = false;/* '<S903>/Switch4' */
MONPRM volatile float32 VIPM_HwAccPedCh1SuplyVolt_mV = 0.0F;/* '<S1575>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh1Volt_mV = 0.0F;/* '<S1576>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh2SuplyVolt_mV = 0.0F;/* '<S1577>/MinMax1' */
MONPRM volatile float32 VIPM_HwAccPedCh2Volt_mV = 0.0F;/* '<S1578>/MinMax1' */
MONPRM volatile boolean VIPM_HwBMSWakeup_flg = false;/* '<S1579>/Switch4' */
MONPRM volatile boolean VIPM_HwBrkSwHi_flg = false;/* '<S1580>/Switch4' */
MONPRM volatile boolean VIPM_HwBrkSwLo_flg = false;/* '<S1581>/Switch4' */
MONPRM volatile boolean VIPM_HwCrpModeSw_flg = false;/* '<S1582>/Switch4' */
MONPRM volatile boolean VIPM_HwDrvModeSw_flg = false;/* '<S1583>/Switch4' */
MONPRM volatile boolean VIPM_HwEmgcyShutOff_flg = false;/* '<S1584>/Switch4' */
MONPRM volatile float32 VIPM_HwHVIL1Volt_mV = 0.0F;/* '<S1585>/MinMax1' */
MONPRM volatile float32 VIPM_HwHVIL2Volt_mV = 0.0F;/* '<S1586>/MinMax1' */
MONPRM volatile boolean VIPM_HwKL15A_flg = false;/* '<S1587>/Switch4' */
MONPRM volatile boolean VIPM_HwKL15B_flg = false;/* '<S1588>/Switch4' */
MONPRM volatile uint16 VIPM_HwKL30_mV = ((uint16)0U);/* '<S1589>/MinMax1' */
MONPRM volatile boolean VIPM_HwOBCWakeup_flg = false;/* '<S1590>/Switch4' */
MONPRM volatile boolean VIPM_HwRearFogLampSwt_flg = false;/* '<S1591>/Switch4' */
MONPRM volatile EnumPGearSwSts VIPM_HwShftPstnSwSts_enum = EnumPGearSwSts_Reld;/* '<S1592>/Switch4' */
MONPRM volatile uint16 VIPM_HwShftPstnSw_Ohm = ((uint16)0U);/* '<S1572>/HwShftPstnSw' */
MONPRM volatile boolean VIPM_HwVehCrash_flg = false;/* '<S1593>/Switch4' */
MONPRM volatile uint8 VNVM_ACChrgMaxCurrFb_A = ((uint8)0U);/* '<S1573>/Selector18' */
MONPRM volatile uint8 VNVM_ACChrgModeFb_enum = ((uint8)0U);/* '<S1573>/Selector19' */
MONPRM volatile float32 VNVM_AvgPwrCnsm_kWh100km = 0.0F;/* '<S1573>/Add2' */
MONPRM volatile float32 VNVM_AvgSOCCnsmWght_pctp100km = 0.0F;/* '<S1573>/Add6' */
MONPRM volatile EnumCrpModeAct VNVM_CrpModeAct_enum = EnumCrpModeAct_Open;/* '<S1573>/Data Type Conversion1' */
MONPRM volatile EnumDrvModeAct VNVM_DrvModeAct_enum = EnumDrvModeAct_Invalid;/* '<S1573>/Data Type Conversion23' */
MONPRM volatile uint8 VNVM_DrvPwrIntnsty_pct = ((uint8)0U);/* '<S1573>/Selector6' */
MONPRM volatile float32 VNVM_DynRmnMilEst_km = 0.0F;/* '<S1573>/Gain2' */
MONPRM volatile uint8 VNVM_EE01ReadOK_nu = ((uint8)0U);/* '<S1573>/Selector13' */
MONPRM volatile uint8 VNVM_EEImdtReadOK_nu = ((uint8)0U);/* '<S1573>/Selector14' */
MONPRM volatile uint8 VNVM_IBSChrgFailNum_cnt = ((uint8)0U);/* '<S1573>/Selector1' */
MONPRM volatile uint8 VNVM_IBSChrgNum_cnt = ((uint8)0U);/* '<S1573>/Selector' */
MONPRM volatile EnumRegenModeAct VNVM_RegenModeAct_enum = EnumRegenModeAct_Off;/* '<S1573>/Data Type Conversion24' */
MONPRM volatile uint8 VNVM_RegenPwrIntnsty_pct = ((uint8)0U);/* '<S1573>/Selector7' */
MONPRM volatile boolean VNVM_TBOXOffline_flg = false;/* '<S1573>/Data Type Conversion11' */
MONPRM volatile EnumTBOXLimSt VNVM_VCUSpdLimSt_enum = EnumTBOXLimSt_Normal;/* '<S1573>/Data Type Conversion10' */
MONPRM volatile boolean VNVM_VCUVerFb_flg = false;/* '<S1573>/Data Type Conversion12' */
MONPRM volatile EnumXWhlDistErrRefSt VNVM_XWhlDistErrRefStat_enum =
  EnumXWhlDistErrRefSt_Init;           /* '<S1573>/Data Type Conversion22' */
MONPRM volatile float32 VNVM_XWhlDistErrRef_mpkm = 0.0F;/* '<S1573>/Add1' */
MONPRM volatile boolean VNVM_iTPMSWrng_flg = false;/* '<S1573>/Data Type Conversion21' */
MONPRM volatile boolean VOPM_HwWakeupBMS_flg = false;/* '<S1607>/Switch4' */
MONPRM volatile float32 VRME_AvgSOCCnsm100Num_pctpkm = 0.0F;/* '<S1010>/Signal Copy5' */

/* ǰ100������ƽ��SOC�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsm10Num_pctpkm = 0.0F;/* '<S1010>/Signal Copy1' */

/* ǰ10������ƽ��SOC�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsm15Num_pctpkm = 0.0F;/* '<S1010>/Signal Copy2' */

/* ǰ15������ƽ��SOC�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsm25Num_pctpkm = 0.0F;/* '<S1010>/Signal Copy3' */

/* ǰ25������ƽ��SOC�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsm50Num_pctpkm = 0.0F;/* '<S1010>/Signal Copy4' */

/* ǰ50������ƽ��SOC�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsm5Num_pctpkm = 0.0F;/* '<S1010>/Signal Copy' */

/* ǰ5������ƽ��SOC�ܺ� */
MONPRM volatile float32 VRME_AvgSOCCnsmWght_pctpkm = 0.0F;/* '<S1010>/Switch1' */

/* ��Ȩƽ��SOC�ܺ�/km */
MONPRM volatile boolean VRME_CHTCRmnMilEstV_flg = false;/* '<S980>/Logical Operator' */

/* CHTC��׼���������Ч�� */
MONPRM volatile float32 VRME_CHTCRmnMilEst_km = 0.0F;/* '<S980>/MRME_CHTCStdRmnMil_km' */

/* CHTC��׼�������ֵ */
MONPRM volatile float32 VRME_CalPwrCnsmPerTrig_kWhptrig = 0.0F;/* '<S984>/Switch4' */

/* Pwr����/��λ��̣�trig�� */
MONPRM volatile float32 VRME_CalPwrCnsmPerkm_kWhpkm = 0.0F;/* '<S984>/Divide' */

/* Pwr����/��λ��̣�1km�� */
MONPRM volatile boolean VRME_CalPwrCnsmTrig_flg = false;/* '<S984>/Relational Operator1' */

/* �ۼ���̴��ڵ�λ��� */
MONPRM volatile float32 VRME_CalSOCCnsmPerTrig_pctptrig = 0.0F;/* '<S1009>/Switch4' */

/* SOC����/��λ��̣�trig�� */
MONPRM volatile float32 VRME_CalSOCCnsmPerkm_pctpkm = 0.0F;/* '<S1009>/Divide' */

/* SOC����/��λ��̣�1km�� */
MONPRM volatile float32 VRME_CalSOCCnsmTgtDist_m = 0.0F;/* '<S1009>/Switch1' */

/* ��λĿ����ʻ��� */
MONPRM volatile boolean VRME_CalSOCCnsmTrig_flg = false;/* '<S1009>/Relational Operator1' */

/* �ۼ���̴���Ŀ����� */
MONPRM volatile float32 VRME_ChrgRmnMilEstTgt_km = 0.0F;/* '<S1005>/Switch2' */

/* ���ģʽ��̬����Ŀ��ֵ */
MONPRM volatile float32 VRME_ChrgRmnMilEst_km = 0.0F;/* '<S1006>/Switch2' */

/* ��繤����̬����ֵ */
MONPRM volatile float32 VRME_ChrgTgtFstRate_kmpsoc = 0.0F;/* '<S995>/Divide2' */

/* ��繤��Ŀ������׷������ */
MONPRM volatile float32 VRME_ChrgTgtNormRate_kmpsoc = 0.0F;/* '<S995>/Divide1' */

/* ��繤��Ŀ�������仯���� */
MONPRM volatile float32 VRME_DchaRmnMilEstChgFac_c = 0.0F;/* '<S1008>/MRME_DynEstRmnChgStp_c' */

/* �ǳ��ģʽ��̬�����仯ϵ�� */
MONPRM volatile float32 VRME_DchaRmnMilEstTgt_km = 0.0F;/* '<S1020>/Switch2' */

/* �ǳ��ģʽ��̬����Ŀ��ֵ */
MONPRM volatile boolean VRME_DchaRmnMilEstUpdTrig_flg = false;/* '<S1008>/Relational Operator2' */

/* ��������ֵ */
MONPRM volatile float32 VRME_DchaRmnMilEst_km = 0.0F;/* '<S1019>/Switch2' */

/* �ǳ��ģʽ��̬����ֵ */
MONPRM volatile boolean VRME_DchaVehStac_flg = false;/* '<S1007>/Logical Operator4' */

/* �ǳ��ģʽ����פ��״̬ */
MONPRM volatile boolean VRME_DynRmnMilEstV_flg = false;/* '<S987>/Logical Operator1' */

/* ��̬������Ч�� */
MONPRM volatile float32 VRME_DynRmnMilEst_km = 0.0F;/* '<S992>/Switch2' */

/* �ۺϵĶ�̬����ֵ */
MONPRM volatile float32 VRME_VehPwrCnsmAvg_kWhpkm = 0.0F;/* '<S984>/Switch7' */

/* ��ǰѭ��ƽ���ܺ� */
MONPRM volatile float32 VRME_VehTotMilCyc_km = 0.0F;/* '<S984>/Gain8' */

/* ��ǰ��ʻѭ��������� */
MONPRM volatile float32 VRME_VehTotPwrCyc_kWh = 0.0F;/* '<S984>/Switch6' */

/* ��ǰ��ʻѭ���������� */
MONPRM volatile float32 VRME_WLTPRmnMilEstDwLim_km = 0.0F;/* '<S989>/Product3' */

/* ��̬��������ֵ */
MONPRM volatile float32 VRME_WLTPRmnMilEstUpLim_km = 0.0F;/* '<S989>/Product2' */

/* ��̬��������ֵ */
MONPRM volatile float32 VRME_WLTPRmnMilEst_km = 0.0F;/* '<S989>/MRME_WLTPStdRmnMil_km' */

/* WLTP��׼�������ֵ */
MONPRM volatile float32 VRME_WLTPStdPwrCnsm_kWhpkm = 0.0F;/* '<S984>/Gain5' */

/* ��׼������ģ�kWh/km�� */
MONPRM volatile float32 VRME_WLTPStdSOCCnsm_pctpkm = 0.0F;/* '<S989>/Gain3' */

/* ��׼������SOC����/km */
MONPRM volatile boolean VTBX_CnclSpdLim_flg = false;/* '<S1082>/Logical Operator12' */

/* TBOX������� */
MONPRM volatile boolean VTBX_LckVer_flg = false;/* '<S1102>/Chart' */

/* �����汾 */
MONPRM volatile boolean VTBX_RecryTBOXHw_flg = false;/* '<S1082>/Logical Operator14' */

/* TBOXӲ��ͨѶ��ʧ�ָ� */
MONPRM volatile boolean VTBX_ReqLimpHome_flg = false;/* '<S1081>/Data Type Conversion6' */

/* VCU�������ж��� */
MONPRM volatile boolean VTBX_RmvTBOXHw_flg = false;/* '<S1082>/Logical Operator3' */

/* TBOXӲ��ͨѶ��ʧ */
MONPRM volatile boolean VTBX_SpdLimLvl1_flg = false;/* '<S1082>/Logical Operator5' */

/* TBOXһ������ */
MONPRM volatile boolean VTBX_SpdLimLvl2_flg = false;/* '<S1082>/Logical Operator7' */

/* TBOX�������� */
MONPRM volatile boolean VTBX_SpdLimLvl3_flg = false;/* '<S1082>/Logical Operator9' */

/* TBOX�������� */
MONPRM volatile boolean VTBX_StorgSpdLim_flg = false;/* '<S1082>/Logical Operator11' */

/* TBOX������� */
MONPRM volatile boolean VTBX_TBOXOffline_flg = false;/* '<S1081>/Signal Copy3' */

/* TBOXӲ��״̬-ʵʱ�洢 */
MONPRM volatile boolean VTBX_UnlckVer_flg = false;/* '<S1101>/Chart' */

/* �������汾 */
MONPRM volatile boolean VTBX_VCUChrgngCondsFb_flg = false;/* '<S1081>/Data Type Conversion5' */

/* VCU�����жϳ������ */
MONPRM volatile uint8 VTBX_VCULckVehWrn_enum = ((uint8)0U);/* '<S1081>/Signal Copy5' */

/* VCU������������ */
MONPRM volatile boolean VTBX_VCUOprtLicFb_flg = false;/* '<S1081>/Data Type Conversion4' */

/* VCU������Ӫ״̬ */
MONPRM volatile EnumTBOXLimGrd VTBX_VCUSpdLimLvlFb_enum = EnumTBOXLimGrd_Normal;/* '<S1081>/Data Type Conversion3' */

/* VCU�������ٵȼ�-��ǰ��ʻѭ�� */
MONPRM volatile uint8 VTBX_VCUSpdLimLvlSetFb_enum = ((uint8)0U);/* '<S1081>/Data Type Conversion7' */

/* VCU�������ٵȼ����óɹ� */
MONPRM volatile EnumTBOXLimSt VTBX_VCUSpdLimSt_enum = EnumTBOXLimSt_Normal;/* '<S1081>/Data Type Conversion1' */

/* ��ǰѭ������״̬-ʵʱ�洢 */
MONPRM volatile boolean VTBX_VCUVerFb_flg = false;/* '<S1081>/Signal Copy' */

/* VCU���������汾-ʵʱ�洢 */
MONPRM volatile uint8 VTBX_VCUVerSetFb_enum = ((uint8)0U);/* '<S1081>/Signal Copy1' */

/* VCU���������汾���óɹ� */
MONPRM volatile float32 VTQC_ABSorESPActvTm_s = 0.0F;/* '<S1379>/MinMax' */
MONPRM volatile float32 VTQC_BrkRegenMaxTqWhl_Nm = 0.0F;/* '<S1374>/Switch17' */
MONPRM volatile float32 VTQC_BrkRegenTgtTqWhl_Nm = 0.0F;/* '<S1374>/Switch2' */
MONPRM volatile float32 VTQC_CstRegenLmtTq_Nm = 0.0F;/* '<S1372>/CstRegenLmtTq' */
MONPRM volatile float32 VTQC_DrvTqReqWhlABS_Nm = 0.0F;/* '<S1372>/MinMax1' */
MONPRM volatile float32 VTQC_DrvTqReqWhlRBS_Nm = 0.0F;/* '<S1381>/MinMax5' */
MONPRM volatile float32 VTQC_DrvTqReqWhl_Nm = 0.0F;/* '<S1373>/Switch5' */
MONPRM volatile float32 VTQC_MotorTqReq_Nm = 0.0F;/* '<S1373>/Divide' */
MONPRM volatile boolean VTQC_RBSActv_flg = false;/* '<S1382>/Switch4' */
MONPRM volatile float32 VTQD_AccelPedPstnRescl_pct = 0.0F;/* '<S1393>/Product' */
MONPRM volatile float32 VTQD_AdaptCstDeltaAcceltn_mps2 = 0.0F;/* '<S1409>/Add5' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqFF_Nm = 0.0F;/* '<S1409>/Add2' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqI_N = 0.0F;/* '<S1409>/Saturation2' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqPID_Nm = 0.0F;/* '<S1409>/Product6' */
MONPRM volatile float32 VTQD_AdaptCstDsrdTqP_N = 0.0F;/* '<S1409>/Product3' */
MONPRM volatile float32 VTQD_AdaptCstMaxTqWhl_Nm = 0.0F;/* '<S1405>/MinMax4' */
MONPRM volatile float32 VTQD_AdaptCstMinTqWhl_Nm = 0.0F;/* '<S1405>/MinMax5' */
MONPRM volatile boolean VTQD_AdaptCstRegenEnbl_flg = false;/* '<S1405>/Logical Operator9' */
MONPRM volatile float32 VTQD_AdaptCstTgtAcceltn_mps2 = 0.0F;/* '<S1411>/Switch' */
MONPRM volatile float32 VTQD_AdaptCstTqReqWhl_Nm = 0.0F;/* '<S1409>/MinMax6' */
MONPRM volatile boolean VTQD_BkwdDrv_flg = false;/* '<S1432>/Switch4' */
MONPRM volatile boolean VTQD_BrkRegenEnbl_flg = false;/* '<S1404>/Logical Operator1' */
MONPRM volatile float32 VTQD_CrpTqReqWhl_Nm = 0.0F;/* '<S1395>/Switch2' */
MONPRM volatile boolean VTQD_CstRegenEnbl_flg = false;/* '<S1404>/Logical Operator13' */
MONPRM volatile float32 VTQD_CstRegenEndPstn_pct = 0.0F;/* '<S1404>/Switch2' */
MONPRM volatile float32 VTQD_CstRegenTqReqWhl_Nm = 0.0F;/* '<S1406>/Switch4' */
MONPRM volatile float32 VTQD_DrvTqDrtFac_c = 0.0F;/* '<S1433>/Saturation' */
MONPRM volatile float32 VTQD_DrvTqReqWhlMrg_Nm = 0.0F;/* '<S1434>/Switch4' */
MONPRM volatile float32 VTQD_DrvTqReqWhlRaw_Nm = 0.0F;/* '<S1393>/Merge' */
MONPRM volatile float32 VTQD_DrvTqReqWhl_Nm = 0.0F;/* '<S1391>/Switch3' */
MONPRM volatile boolean VTQD_DsblCrp_flg = false;/* '<S1395>/Logical Operator12' */
MONPRM volatile float32 VTQD_FullPedDrvTqWhl_Nm = 0.0F;/* '<S1393>/Signal Conversion1' */
MONPRM volatile float32 VTQD_FwdPedMap_pct = 0.0F;/* '<S1396>/Switch9' */
MONPRM volatile float32 VTQD_PedalTqReqWhlRaw_Nm = 0.0F;/* '<S1390>/Add' */
MONPRM volatile uint16 VTQD_TaskRunCounter_cnt = ((uint16)0U);/* '<S1227>/Max1' */

/* test signal, to be deleted */
MONPRM volatile boolean VTQD_TqZeroFast_flg = false;/* '<S1425>/Logical Operator4' */
MONPRM volatile boolean VTQD_TqZeroSlow_flg = false;/* '<S1425>/Logical Operator2' */
MONPRM volatile boolean VTQD_TqZero_flg = false;/* '<S1425>/Logical Operator1' */
MONPRM volatile float32 VTQF_DrvTqReqWhl_Nm = 0.0F;/* '<S1450>/Switch2' */
MONPRM volatile float32 VTQF_TipOutTqDecRateCoeff_rat = 0.0F;/* '<S1452>/1-D Lookup Table1' */
MONPRM volatile boolean VTQF_TqInc_flg = false;/* '<S1462>/Switch4' */
MONPRM volatile float32 VTQF_TqOutChgRate_Nmps = 0.0F;/* '<S1472>/Switch' */
MONPRM volatile float32 VTQF_TqRateDecTgtMax_Nmps = 0.0F;/* '<S1452>/Switch3' */
MONPRM volatile float32 VTQF_TqRateDecTgtMin_Nmps = 0.0F;/* '<S1452>/MinMax4' */
MONPRM volatile float32 VTQF_TqRateIncTgtMax_Nmps = 0.0F;/* '<S1453>/Switch5' */
MONPRM volatile float32 VTQF_TqRateIncTgtMin_Nmps = 0.0F;/* '<S1453>/MinMax4' */
MONPRM volatile float32 VTQF_TqRateLimDec_Nmps = 0.0F;/* '<S1452>/MinMax3' */
MONPRM volatile boolean VTQF_TqRateLimEndg_flg = false;/* '<S1451>/Logical Operator9' */
MONPRM volatile float32 VTQF_TqRateLimInc_Nmps = 0.0F;/* '<S1453>/MinMax2' */
MONPRM volatile float32 VTQF_TqRawChgRate_Nmps = 0.0F;/* '<S1471>/Switch' */
MONPRM volatile float32 VTQF_WhlDrgMaxTqZX_Nm = 0.0F;/* '<S1470>/Switch1' */
MONPRM volatile float32 VTQF_WhlDrvMaxTqZX_Nm = 0.0F;/* '<S1470>/Switch7' */
MONPRM volatile boolean VTQR_ASDEnbl_flg = false;/* '<S1475>/Logical Operator14' */
MONPRM volatile float32 VTQR_ASDSpdFltHi_rpm = 0.0F;/* '<S1483>/Switch' */
MONPRM volatile float32 VTQR_ASDSpdOscRaw_rpm = 0.0F;/* '<S1479>/Add1' */
MONPRM volatile float32 VTQR_ASDSpdOsc_rpm = 0.0F;/* '<S1481>/Multiport Switch' */
MONPRM volatile float32 VTQR_ASDTqReqRaw_Nm = 0.0F;/* '<S1487>/MinMax5' */
MONPRM volatile float32 VTQR_ASDTqReq_Nm = 0.0F;/* '<S1480>/Switch3' */
MONPRM volatile boolean VTQR_MotDampngEnbl_flg = false;/* '<S1475>/Logical Operator1' */
MONPRM volatile float32 VTQR_MotDampngLmt_Nm = 0.0F;/* '<S1495>/MinMax5' */
MONPRM volatile EnumMotorDirReq VTQR_MotorDirReq_enum = EnumMotorDirReq_Stdby;/* '<S1476>/Switch4' */
MONPRM volatile EnumMotorModeReq VTQR_MotorModeReq_enum = EnumMotorModeReq_Stdby;/* '<S1473>/Signal Conversion15' */
MONPRM volatile float32 VTQR_MotorSpdReq_rpm = 0.0F;/* '<S1473>/Signal Conversion1' */
MONPRM volatile boolean VTQR_MotorStdby_flg = false;/* '<S1477>/Logical Operator1' */
MONPRM volatile float32 VTQR_MotorTqReq_Nm = 0.0F;/* '<S1473>/Signal Conversion2' */
MONPRM volatile float32 VTZX_AZDecRate_Nmps = 0.0F;/* '<S1511>/1-D Lookup Table4' */
MONPRM volatile float32 VTZX_AZIncRate_Nmps = 0.0F;/* '<S1511>/1-D Lookup Table3' */
MONPRM volatile float32 VTZX_BZDecRate_Nmps = 0.0F;/* '<S1511>/1-D Lookup Table2' */
MONPRM volatile float32 VTZX_BZIncRate_Nmps = 0.0F;/* '<S1511>/1-D Lookup Table1' */
MONPRM volatile boolean VTZX_BypZX_flg = false;/* '<S1515>/Logical Operator1' */
MONPRM volatile boolean VTZX_ClkActv_flg = false;/* '<S1514>/Switch4' */
MONPRM volatile float32 VTZX_ClkZXTm_s = 0.0F;/* '<S1507>/Switch1' */
MONPRM volatile float32 VTZX_MotorTqReqPrdt_Nm = 0.0F;/* '<S1527>/MinMax5' */
MONPRM volatile float32 VTZX_MotorTqReqZX_Nm = 0.0F;/* '<S1512>/TqZXSt' */
MONPRM volatile float32 VTZX_MotorTqReq_Nm = 0.0F;/* '<S1507>/Switch6' */
MONPRM volatile boolean VTZX_TqInc_flg = false;/* '<S1521>/Switch4' */
MONPRM volatile boolean VTZX_TqRateLimRamp_flg = false;/* '<S1528>/Switch4' */
MONPRM volatile EnumTZXStat VTZX_TqZXSt_enum = EnumTZXStat_NTRL;/* '<S1512>/Data Type Conversion1' */
MONPRM volatile float32 VTZX_ZeroTqHldDec_Nm = 0.0F;/* '<S1512>/TqZXSt' */
MONPRM volatile float32 VTZX_ZeroTqHldInc_Nm = 0.0F;/* '<S1512>/TqZXSt' */
MONPRM volatile float32 VTZX_ZeroTqOfstDec_Nm = 0.0F;/* '<S1511>/Switch3' */
MONPRM volatile float32 VTZX_ZeroTqOfstInc_Nm = 0.0F;/* '<S1511>/Switch2' */
MONPRM volatile float32 VTZX_ZeroTqOfst_Nm = 0.0F;/* '<S1511>/Switch4' */
MONPRM volatile float32 VTZX_ZeroXTm_s = 0.0F;/* '<S1511>/Switch8' */
MONPRM volatile float32 VVSO_ALatSnsr_mps2 = 0.0F;/* '<S1131>/Switch1' */
MONPRM volatile float32 VVSO_ALgtSnsr_mps2 = 0.0F;/* '<S1130>/Switch1' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr1_mpkm = 0.0F;/* '<S1192>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr2_mpkm = 0.0F;/* '<S1192>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr3_mpkm = 0.0F;/* '<S1192>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr4_mpkm = 0.0F;/* '<S1192>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr5_mpkm = 0.0F;/* '<S1192>/WhlDistErrRec' */
MONPRM volatile float32 VVSO_AvgXWhlDistErr_mpkm = 0.0F;/* '<S1192>/Add3' */
MONPRM volatile float32 VVSO_DrvDist_m = 0.0F;/* '<S1205>/Switch1' */
MONPRM volatile boolean VVSO_RSEBrkPresrConf_flg = false;/* '<S1177>/Relational Operator2' */
MONPRM volatile boolean VVSO_RSESigConf_flg = false;/* '<S1163>/Logical Operator3' */
MONPRM volatile boolean VVSO_RSEVehSpdConf_flg = false;/* '<S1179>/Logical Operator2' */
MONPRM volatile boolean VVSO_RSEWhlSlipConf_flg = false;/* '<S1180>/Logical Operator2' */
MONPRM volatile boolean VVSO_RSEYawRateConf_flg = false;/* '<S1181>/Logical Operator' */
MONPRM volatile float32 VVSO_RoadSlopCalcRaw_pct = 0.0F;/* '<S1161>/Product19' */
MONPRM volatile boolean VVSO_RoadSlopEstVld_flg = false;/* '<S1160>/Logical Operator1' */
MONPRM volatile float32 VVSO_RoadSlopEst_pct = 0.0F;/* '<S1160>/Switch2' */
MONPRM volatile float32 VVSO_RoadSlopTqEst_Nm = 0.0F;/* '<S1176>/MinMax5' */
MONPRM volatile float32 VVSO_VehDrvResistTq_Nm = 0.0F;/* '<S1162>/Switch5' */
MONPRM volatile boolean VVSO_VehMassConf_flg = false;/* '<S1208>/Logical Operator4' */
MONPRM volatile uint8 VVSO_VehMassDistb_enum = ((uint8)0U);/* '<S1208>/Signal Conversion' */
MONPRM volatile float32 VVSO_VehMassEst_kg = 0.0F;/* '<S1211>/Switch' */
MONPRM volatile float32 VVSO_VehSpd_mps = 0.0F;/* '<S1208>/Gain3' */
MONPRM volatile float32 VVSO_WhlAcceltnFL_mps2 = 0.0F;/* '<S1143>/Divide' */
MONPRM volatile float32 VVSO_WhlAcceltnFR_mps2 = 0.0F;/* '<S1144>/Divide' */
MONPRM volatile float32 VVSO_WhlAcceltnRL_mps2 = 0.0F;/* '<S1145>/Divide' */
MONPRM volatile float32 VVSO_WhlAcceltnRR_mps2 = 0.0F;/* '<S1146>/Divide' */
MONPRM volatile boolean VVSO_WhlDistErrHld_flg = false;/* '<S1196>/OR' */
MONPRM volatile float32 VVSO_WhlLgtFrc_N = 0.0F;/* '<S1213>/Add' */
MONPRM volatile EnumXWhlDistErrRefSt VVSO_XWhlDistErrRefStat_enum =
  EnumXWhlDistErrRefSt_Init;           /* '<S1192>/Signal Conversion2' */
MONPRM volatile float32 VVSO_XWhlDistErrRef_mpkm = 0.0F;/* '<S1192>/Signal Conversion1' */
MONPRM volatile float32 VVSO_XWhlDistErr_m = 0.0F;/* '<S1205>/Switch4' */
MONPRM volatile float32 VVSO_YawRateBas_degps = 0.0F;/* '<S1137>/Switch' */
MONPRM volatile float32 VVSO_YawRateDer_radps2 = 0.0F;/* '<S1132>/Add6' */
MONPRM volatile float32 VVSO_YawRateFilt_radps = 0.0F;/* '<S1136>/Switch' */
MONPRM volatile boolean VVSO_iTPMSAvail_flg = false;/* '<S1196>/Logical Operator' */
MONPRM volatile EnumiTPMSSt VVSO_iTPMSState_enum = EnumiTPMSSt_Init;/* '<S1192>/Signal Conversion' */
MONPRM volatile boolean VVSO_iTPMSWrng_flg = false;/* '<S1192>/Signal Conversion3' */
MONPRM volatile boolean VVTM_BrkPedReld_flg = false;/* '<S1553>/Logical Operator3' */
MONPRM volatile uint8 VVTM_DrvMotorSta_enum = ((uint8)0U);/* '<S1560>/DriveMotorState' */
MONPRM volatile boolean VVTM_ESPIntvActv_flg = false;/* '<S1553>/Logical Operator4' */
MONPRM volatile float32 VVTM_MotorActPwr_kW = 0.0F;/* '<S1567>/Switch2' */
MONPRM volatile float32 VVTM_MotorSpd_rpm = 0.0F;/* '<S1555>/Switch' */
MONPRM volatile boolean VVTM_PCUFailSta_flg = false;/* '<S1560>/Logical Operator2' */
MONPRM volatile boolean VVTM_RegenReqBrkLampOn_flg = false;/* '<S1565>/Switch1' */
MONPRM volatile float32 VVTM_RsrvPwr_kW = 0.0F;/* '<S1562>/MinMax4' */
MONPRM volatile float32 VVTM_RsrvRecupPwr_kW = 0.0F;/* '<S1562>/MinMax1' */
MONPRM volatile float32 VVTM_VehAcceltn_mps2 = 0.0F;/* '<S1558>/Switch' */
MONPRM volatile uint8 VVTM_VehActGrPstn_enum = ((uint8)0U);/* '<S1553>/Switch1' */
MONPRM volatile float32 VVTM_VehSpd_kph = 0.0F;/* '<S1554>/Switch' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
