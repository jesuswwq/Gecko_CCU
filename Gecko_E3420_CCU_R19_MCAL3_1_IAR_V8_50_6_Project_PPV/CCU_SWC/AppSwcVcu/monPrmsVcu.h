/*
 * File: monPrmsVcu.h
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

#ifndef RTW_HEADER_monPrmsVcu_h_
#define RTW_HEADER_monPrmsVcu_h_
#include "rtwtypes.h"
#include "AppSwcVcu_types.h"

/* Exported data declaration */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Declaration for custom storage class: Volatile */
extern MONPRM volatile boolean BSW_RTCWakeup_flg;/* '<S974>/Switch4' */

/* RTC���ѱ�־λ_versteckt */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Day;/* '<S98>/Data Type Conversion45' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Hour;/* '<S98>/Data Type Conversion1' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Min;/* '<S98>/Data Type Conversion2' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Month;/* '<S98>/Data Type Conversion34' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Sec;/* '<S98>/Switch2' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Year;/* '<S98>/Data Type Conversion33' */
extern MONPRM volatile uint8 VBSW_WakeupReasn_enum;/* '<S1449>/EcuWakeupReasn' */

/* _versteckt */
extern MONPRM volatile float32 VCPT_MotorDrgMaxTq_Nm;/* '<S1033>/MinMax6' */
extern MONPRM volatile float32 VCPT_MotorDrvMaxTq_Nm;/* '<S1033>/MinMax7' */
extern MONPRM volatile float32 VCPT_MotorGenMaxTq_Nm;/* '<S1045>/Switch1' */
extern MONPRM volatile float32 VCPT_MotorMotMaxTq_Nm;/* '<S1044>/Switch1' */
extern MONPRM volatile boolean VCPT_MotorSpdRvrs_flg;/* '<S1033>/Switch3' */
extern MONPRM volatile float32 VCPT_MotorSpd_rpm;/* '<S1039>/Switch' */
extern MONPRM volatile float32 VCPT_WhlDrgMaxTq_Nm;/* '<S1033>/MinMax1' */
extern MONPRM volatile float32 VCPT_WhlDrvMaxTq_Nm;/* '<S1033>/MinMax8' */
extern MONPRM volatile boolean VDAC_ACCAvail_flg;/* '<S1054>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_ACCDeltaAcceltn_mps2;/* '<S1060>/Add5' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqFF_Nm;/* '<S1060>/Add3' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqI_N;/* '<S1060>/Saturation1' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqPID_Nm;/* '<S1060>/Product6' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqP_N;/* '<S1060>/Product3' */
extern MONPRM volatile boolean VDAC_ACCEnbl_flg;/* '<S1054>/Logical Operator3' */
extern MONPRM volatile boolean VDAC_ACCOvrd_flg;/* '<S1055>/Logical Operator22' */
extern MONPRM volatile float32 VDAC_ACCTqReqWhl_Nm;/* '<S1056>/Merge3' */
extern MONPRM volatile uint8 VDAC_AutoBrkReq_enum;/* '<S1161>/Switch' */
extern MONPRM volatile boolean VDAC_CCActv2Stby_flg;/* '<S1095>/Logical Operator15' */
extern MONPRM volatile boolean VDAC_CCActvBascCond_flg;/* '<S1095>/Logical Operator1' */
extern MONPRM volatile float32 VDAC_CCDeltaAcceltn_mps2;/* '<S1082>/Add3' */
extern MONPRM volatile float32 VDAC_CCDsrdAcceltnRaw_mps2;/* '<S1075>/Saturation1' */
extern MONPRM volatile float32 VDAC_CCDsrdAcceltn_mps2;/* '<S1073>/Merge1' */
extern MONPRM volatile float32 VDAC_CCDsrdTqFF_N;/* '<S1081>/Add3' */
extern MONPRM volatile float32 VDAC_CCDsrdTqI_N;/* '<S1082>/Saturation1' */
extern MONPRM volatile float32 VDAC_CCDsrdTqPID_N;/* '<S1082>/Add2' */
extern MONPRM volatile float32 VDAC_CCDsrdTqP_N;/* '<S1082>/Product2' */
extern MONPRM volatile boolean VDAC_CCEnbl_flg;/* '<S1096>/Logical Operator2' */
extern MONPRM volatile uint16 VDAC_CCNoActvCond_enum;/* '<S1098>/Add' */
extern MONPRM volatile boolean VDAC_CCOvrd_flg;/* '<S1069>/Logical Operator22' */
extern MONPRM volatile uint16 VDAC_CCQuitCond_enum;/* '<S1099>/Add' */
extern MONPRM volatile float32 VDAC_CCSpdUnstabTm_s;/* '<S1111>/Saturation' */
extern MONPRM volatile boolean VDAC_CCSpdUnstab_flg;/* '<S1111>/Relational Operator8' */
extern MONPRM volatile EnumCCState VDAC_CCSt_enum;/* '<S1070>/CC_State_Chart' */
extern MONPRM volatile boolean VDAC_CCStby2Actv_flg;/* '<S1095>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_CCTgtSpdCtrl_kph;/* '<S1120>/Switch1' */
extern MONPRM volatile uint8 VDAC_CCTgtSpdHU_kph;/* '<S1071>/TgtSpdCalc' */
extern MONPRM volatile EnumCCTgtSpdSt VDAC_CCTgtSpdSt_enum;/* '<S1071>/TgtSpdCalc' */
extern MONPRM volatile float32 VDAC_CCTgtSpd_kph;/* '<S1071>/MinMax7' */
extern MONPRM volatile float32 VDAC_CCTqReqWhl_Nm;/* '<S1074>/Merge2' */
extern MONPRM volatile float32 VDAC_CCVehSpdNonDrvn_kph;/* '<S1077>/Switch' */
extern MONPRM volatile boolean VDAC_CruzCncl_flg;/* '<S1136>/Chart' */
extern MONPRM volatile EnumCruiseStatus VDAC_CruzCtrlStat_enum;/* '<S1069>/Switch2' */
extern MONPRM volatile boolean VDAC_CruzCtrlSwVld_flg;/* '<S1072>/Signal Conversion1' */
extern MONPRM volatile boolean VDAC_CruzOn_flg;/* '<S1072>/Signal Conversion2' */
extern MONPRM volatile boolean VDAC_CruzRsmActv_flg;/* '<S1133>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSetActv_flg;/* '<S1131>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSpdDecActv_flg;/* '<S1132>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSpdIncActv_flg;/* '<S1134>/Switch4' */
extern MONPRM volatile float32 VDAC_DrvAsstTqSplitEHB_Nm;/* '<S1050>/MinMax2' */
extern MONPRM volatile float32 VDAC_DrvAsstTqSplitINV_Nm;/* '<S1050>/Add1' */
extern MONPRM volatile uint8 VDAC_DrvAsstTqSts_enum;/* '<S1050>/Switch1' */
extern MONPRM volatile float32 VDAC_DrvAsstTqTgt_Nm;/* '<S1050>/Switch2' */
extern MONPRM volatile boolean VDAC_EnblEHBBrkRun_flg;/* '<S1243>/Switch4' */
extern MONPRM volatile boolean VDAC_HDCActv2Idle_flg;/* '<S1143>/Logical Operator11' */
extern MONPRM volatile boolean VDAC_HDCActv2Stdby_flg;/* '<S1143>/Logical Operator8' */
extern MONPRM volatile float32 VDAC_HDCDeltaAcceltn_mps2;/* '<S1148>/Add5' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqFF_Nm;/* '<S1148>/Add3' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqI_N;/* '<S1148>/Saturation1' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqPID_Nm;/* '<S1148>/Product6' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqP_N;/* '<S1148>/Product3' */
extern MONPRM volatile boolean VDAC_HDCIdle2Stdby_flg;/* '<S1143>/Logical Operator2' */
extern MONPRM volatile EnumHDCState VDAC_HDCSt_enum;/* '<S1048>/HDC_State_Chart' */
extern MONPRM volatile boolean VDAC_HDCStdby2Actv_flg;/* '<S1143>/Logical Operator13' */
extern MONPRM volatile boolean VDAC_HDCStdby2Idle_flg;/* '<S1143>/Logical Operator3' */
extern MONPRM volatile float32 VDAC_HDCTgtAcceltn_mps2;/* '<S1140>/Merge1' */
extern MONPRM volatile float32 VDAC_HDCTgtSpd_kph;/* '<S1048>/HDC_State_Chart' */
extern MONPRM volatile float32 VDAC_HDCTqReqWhl_Nm;/* '<S1140>/Merge2' */
extern MONPRM volatile uint8 VDAC_HDCVehSpdHU_kph;/* '<S1141>/Switch1' */
extern MONPRM volatile boolean VDAC_MstrCylPresDec_flg;/* '<S1169>/Relational Operator' */
extern MONPRM volatile float32 VDAC_MstrCylPresrReq_bar;/* '<S1050>/Switch13' */
extern MONPRM volatile boolean VDAC_OPDActv_flg;/* '<S1184>/Switch4' */
extern MONPRM volatile boolean VDAC_OPDAvail_flg;/* '<S1162>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_OPDDeltaAcceltn_mps2;/* '<S1201>/Add3' */
extern MONPRM volatile float32 VDAC_OPDDeltaSpd_kph;/* '<S1201>/Add4' */
extern MONPRM volatile float32 VDAC_OPDDsrdTqD_N;/* '<S1215>/Switch' */
extern MONPRM volatile float32 VDAC_OPDDsrdTqFF_Nm;/* '<S1200>/Add3' */
extern MONPRM volatile boolean VDAC_OPDDsrdTqFstI_flg;/* '<S1212>/Logical Operator9' */
extern MONPRM volatile boolean VDAC_OPDDsrdTqHldI_flg;/* '<S1212>/Logical Operator3' */
extern MONPRM volatile float32 VDAC_OPDDsrdTqI_N;/* '<S1201>/Saturation1' */
extern MONPRM volatile float32 VDAC_OPDDsrdTqPID_Nm;/* '<S1201>/Product4' */
extern MONPRM volatile float32 VDAC_OPDDsrdTqP_N;/* '<S1207>/Switch2' */
extern MONPRM volatile float32 VDAC_OPDMaxDrgTqWhl_Nm;/* '<S1212>/MinMax1' */
extern MONPRM volatile float32 VDAC_OPDMaxDrvTqWhl_Nm;/* '<S1212>/MinMax3' */
extern MONPRM volatile boolean VDAC_OPDOvrd_flg;/* '<S1161>/Logical Operator22' */
extern MONPRM volatile float32 VDAC_OPDRtdTq_Nm;/* '<S1200>/Add1' */
extern MONPRM volatile boolean VDAC_OPDSpdClsLoop_flg;/* '<S1201>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_OPDTgtAcceltn_mps2;/* '<S1163>/Merge3' */
extern MONPRM volatile float32 VDAC_OPDTgtSpd_kph;/* '<S1163>/Merge1' */
extern MONPRM volatile boolean VDAC_OPDTqReqUnload_flg;/* '<S1161>/Logical Operator1' */
extern MONPRM volatile float32 VDAC_OPDTqReqWhlFilt_Nm;/* '<S1235>/Switch3' */
extern MONPRM volatile float32 VDAC_OPDTqReqWhlLmt_Nm;/* '<S1164>/Merge3' */
extern MONPRM volatile float32 VDAC_OPDTqReqWhl_Nm;/* '<S1172>/Switch3' */
extern MONPRM volatile float32 VDAC_OPDVehAcceltn2_mps2;/* '<S1191>/Switch' */
extern MONPRM volatile float32 VDAC_OPDVehAcceltn_mps2;/* '<S1163>/Switch2' */
extern MONPRM volatile float32 VDAC_OPDVehSpdMotorFac_rat;/* '<S1190>/Switch' */
extern MONPRM volatile float32 VDAC_OPDVehSpdMotor_kph;/* '<S1163>/Product1' */
extern MONPRM volatile float32 VDAC_OPDVehSpd_kph;/* '<S1163>/Switch1' */
extern MONPRM volatile uint8 VDAC_VehSpdHU_kph;/* '<S1122>/Switch1' */
extern MONPRM volatile uint8 VDAC_VirtAccPedPstnSta_enum;/* '<S1050>/Switch11' */
extern MONPRM volatile float32 VDAC_VirtAccPedPstn_pct;/* '<S1050>/Switch8' */
extern MONPRM volatile float32 VDAC_VirtAccelPedPstnRaw_pct;/* '<S1050>/Switch9' */
extern MONPRM volatile float32 VDAC_VirtPedPstn_pct;/* '<S1050>/Switch4' */
extern MONPRM volatile uint8 VDAG_ACChrgStFailFltSt_enum;/* '<S378>/FltStDeb' */

/* ACChargeStateFail����״̬ */
extern MONPRM volatile uint8 VDAG_ACDchaBMSPwrLoFltSt_enum;/* '<S384>/FltStDeb' */

/* AC�ŵ�BMS���ʵ͹���״̬ */
extern MONPRM volatile uint8 VDAG_ACDchaBMSSOCLoFltSt_enum;/* '<S383>/FltStDeb' */

/* AC�ŵ�BMSSOC�͹���״̬ */
extern MONPRM volatile uint8 VDAG_ACDchaOverPwrFltSt_enum;/* '<S377>/FltStDeb' */

/* AC�ŵ繦�ʳ��޹��� */
extern MONPRM volatile uint8 VDAG_ACSCmdTmOutFltSt_enum;/* '<S131>/FltStDeb' */

/* ACSCmd��ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_AccPed1ShtBattFltSt_enum;/* '<S495>/FltStDeb' */

/* ����̤��1·�̵�Դ����״̬ */
extern MONPRM volatile uint8 VDAG_AccPed1ShtGndFltSt_enum;/* '<S492>/FltStDeb' */

/* ����̤��1·�̵ع���״̬ */
extern MONPRM volatile uint8 VDAG_AccPed1SuplyShtCircFltSt_enum;/* '<S493>/FltStDeb' */

/* ����̤��1·�����·����״̬ */
extern MONPRM volatile uint8 VDAG_AccPed2ShtBattFltSt_enum;/* '<S488>/FltStDeb' */

/* ����̤��2·�̵�Դ����״̬ */
extern MONPRM volatile uint8 VDAG_AccPed2ShtGndFltSt_enum;/* '<S496>/FltStDeb' */

/* ����̤��2·�̵ع���״̬ */
extern MONPRM volatile uint8 VDAG_AccPed2SuplyShtCircFltSt_enum;/* '<S494>/FltStDeb' */

/* ����̤��2·�����·����״̬ */
extern MONPRM volatile uint8 VDAG_AccPedBothFailFltSt_enum;/* '<S490>/FltStDeb' */

/* ����̤��˫·ʧЧ����״̬ */
extern MONPRM volatile uint8 VDAG_AccPedCrsChkFltSt_enum;/* '<S489>/FltStDeb' */

/* ����̤���໥У�����״̬ */
extern MONPRM volatile uint8 VDAG_BMSCmdTmOutFltSt_enum;/* '<S125>/FltStDeb' */

/* BMS�̵���ָ����Ӧ��ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_BMSEmgcySdnFltSt_enum;/* '<S136>/FltStDeb' */

/* BMS�����µ����״̬ */
extern MONPRM volatile uint8 VDAG_BMSSOCLoFltSt_enum;/* '<S135>/FltStDeb' */

/* BMSSOC�͹���״̬ */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl1FltSt_enum;/* '<S132>/FltStDeb' */

/* BMSFailLevel1����״̬ */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl2FltSt_enum;/* '<S133>/FltStDeb' */

/* BMSFailLevel2����״̬ */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl3FltSt_enum;/* '<S134>/FltStDeb' */

/* BMSFailLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_BMSUndrVoltFltSt_enum;/* '<S137>/FltStDeb' */

/* BMSPackǷѹ����״̬ */
extern MONPRM volatile uint8 VDAG_BrkPedShtBattFltSt_enum;/* '<S515>/FltStDeb' */

/* �ƶ�̤��̵�Դ����״̬ */
extern MONPRM volatile uint8 VDAG_BrkPedShtGndFltSt_enum;/* '<S513>/FltStDeb' */

/* �ƶ�̤��̵ع���״̬ */
extern MONPRM volatile uint8 VDAG_BrkSwCrsChkCnt_cnt;/* '<S508>/Data Type Conversion' */

/* �ƶ������໥У�������� */
extern MONPRM volatile uint8 VDAG_BrkSwCrsChkFltSt_enum;/* '<S514>/FltStDeb' */

/* �ƶ������໥У�����״̬ */
extern MONPRM volatile uint8 VDAG_CellUndrVoltFltSt_enum;/* '<S138>/FltStDeb' */

/* BMSCellǷѹ����״̬ */
extern MONPRM volatile uint8 VDAG_DCCCmdTmOutFltSt_enum;/* '<S280>/FltStDeb' */

/* DCDCģʽָ����Ӧ��ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_DCCInVoltLoFltSt_enum;/* '<S281>/FltStDeb' */

/* DCDC�����ѹ�͹���״̬ */
extern MONPRM volatile uint8 VDAG_DCCModeFltFltSt_enum;/* '<S279>/FltStDeb' */

/* DCDCModeFault����״̬ */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl1FltSt_enum;/* '<S275>/FltStDeb' */

/* DCDCFailLevel1����״̬ */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl2FltSt_enum;/* '<S276>/FltStDeb' */

/* DCDCFailLevel2����״̬ */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl3FltSt_enum;/* '<S277>/FltStDeb' */

/* DCDCFailLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl4FltSt_enum;/* '<S278>/FltStDeb' */

/* DCDCFailLevel4����״̬ */
extern MONPRM volatile uint8 VDAG_DCSChrgReqFltSt_enum;/* '<S129>/FltStDeb' */

/* DCSChargeRequest����״̬ */
extern MONPRM volatile uint8 VDAG_DCSCmdTmOutFltSt_enum;/* '<S139>/FltStDeb' */

/* DCSCmd��ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_DCSFailStaFltSt_enum;/* '<S127>/FltStDeb' */

/* DCSFailState����״̬ */
extern MONPRM volatile uint8 VDAG_DCSInletConnectFltSt_enum;/* '<S128>/FltStDeb' */

/* DCS��ǹ����״̬ */
extern MONPRM volatile uint8 VDAG_DCSModeFailFltSt_enum;/* '<S130>/FltStDeb' */

/* DCSModeFail����״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl1FltSt_enum;/* '<S440>/FltStDeb' */

/* EHB1������״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl2FltSt_enum;/* '<S441>/FltStDeb' */

/* EHB2������״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl3FltSt_enum;/* '<S442>/FltStDeb' */

/* EHB3������״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl4FltSt_enum;/* '<S434>/FltStDeb' */

/* EHB4������״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl5FltSt_enum;/* '<S443>/FltStDeb' */

/* EHB5������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl1FltSt_enum;/* '<S445>/FltStDeb' */

/* ESC1������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl2FltSt_enum;/* '<S435>/FltStDeb' */

/* ESC2������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl3FltSt_enum;/* '<S436>/FltStDeb' */

/* ESC3������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl4FltSt_enum;/* '<S444>/FltStDeb' */

/* ESC4������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl5FltSt_enum;/* '<S437>/FltStDeb' */

/* ESC5������״̬ */
extern MONPRM volatile uint8 VDAG_ESCVehSpdInvldFltSt_enum;/* '<S439>/FltStDeb' */

/* ����ʧЧ����״̬ */
extern MONPRM volatile boolean VDAG_EmgcyShtdwn_flg;/* '<S89>/Switch30' */
extern MONPRM volatile uint16 VDAG_ErrCode_enum;/* '<S87>/Err_State' */
extern MONPRM volatile boolean VDAG_FanFullSpdOn_flg;/* '<S89>/Switch3' */
extern MONPRM volatile boolean VDAG_FbdACC_flg;/* '<S89>/Switch28' */
extern MONPRM volatile boolean VDAG_FbdACChrg_flg;/* '<S89>/Switch32' */
extern MONPRM volatile boolean VDAG_FbdACDcha_flg;/* '<S89>/Switch34' */
extern MONPRM volatile boolean VDAG_FbdAC_flg;/* '<S89>/Switch35' */
extern MONPRM volatile boolean VDAG_FbdCC_flg;/* '<S89>/Switch26' */
extern MONPRM volatile boolean VDAG_FbdDCChrg_flg;/* '<S89>/Switch33' */
extern MONPRM volatile boolean VDAG_FbdDCDC_flg;/* '<S89>/Switch31' */
extern MONPRM volatile boolean VDAG_FbdDRGr_flg;/* '<S89>/Switch25' */
extern MONPRM volatile boolean VDAG_FbdDrvTq_flg;/* '<S89>/Switch23' */
extern MONPRM volatile boolean VDAG_FbdHV_flg;/* '<S89>/Switch29' */
extern MONPRM volatile boolean VDAG_FbdLSP_flg;/* '<S89>/Switch27' */
extern MONPRM volatile boolean VDAG_FltLampOn_flg;/* '<S89>/Switch36' */
extern MONPRM volatile uint8 VDAG_FltLvl_enum;/* '<S89>/MinMax' */
extern MONPRM volatile uint8 VDAG_GearShftInvldFltSt_enum;/* '<S438>/FltStDeb' */

/* ��������ʧЧ����״̬ */
extern MONPRM volatile uint8 VDAG_HVILVoltHiFltSt_enum;/* '<S517>/FltStDeb' */

/* ��ѹ������ѹ�߹���״̬ */
extern MONPRM volatile uint8 VDAG_HVILVoltLoFltSt_enum;/* '<S516>/FltStDeb' */

/* ��ѹ������ѹ�͹���״̬ */
extern MONPRM volatile uint8 VDAG_HVIsoResistLoFltSt_enum;/* '<S126>/FltStDeb' */

/* ��ѹ��ؾ�Ե����״̬ */
extern MONPRM volatile uint8 VDAG_INVFltLvl1FltSt_enum;/* '<S344>/FltStDeb' */

/* INVFaultLevel1����״̬ */
extern MONPRM volatile uint8 VDAG_INVFltLvl2FltSt_enum;/* '<S345>/FltStDeb' */

/* INVFaultLevel2����״̬ */
extern MONPRM volatile uint8 VDAG_INVFltLvl3FltSt_enum;/* '<S346>/FltStDeb' */

/* INVFaultLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_INVFltLvl4FltSt_enum;/* '<S347>/FltStDeb' */

/* INVFaultLevel4����״̬ */
extern MONPRM volatile uint8 VDAG_INVInVoltLoFltSt_enum;/* '<S282>/FltStDeb' */

/* INV�����ѹ�͹���״̬ */
extern MONPRM volatile uint8 VDAG_INVRunCmdRespFltSt_enum;/* '<S348>/FltStDeb' */

/* INVRunָ����Ӧ��ʱ����״̬ */
extern MONPRM volatile boolean VDAG_LVBatLampOn_flg;/* '<S89>/Switch1' */
extern MONPRM volatile uint8 VDAG_LVBattSOCLoFltSt_enum;/* '<S468>/FltStDeb' */

/* ����SOC�͵Ĺ���״̬ */
extern MONPRM volatile uint8 VDAG_LVBattSOHLoFltSt_enum;/* '<S464>/FltStDeb' */

/* ����SOH�͵Ĺ���״̬ */
extern MONPRM volatile uint8 VDAG_LVBattTempHiFltSt_enum;/* '<S465>/FltStDeb' */

/* ���ع��¹���״̬ */
extern MONPRM volatile uint8 VDAG_LVBattVoltHiFltSt_enum;/* '<S467>/FltStDeb' */

/* ���ص�ѹ�߹���״̬ */
extern MONPRM volatile uint8 VDAG_LVBattVoltLoFltSt_enum;/* '<S466>/FltStDeb' */

/* ���ص�ѹ�͹���״̬ */
extern MONPRM volatile boolean VDAG_LimpHome_flg;/* '<S89>/Switch2' */
extern MONPRM volatile boolean VDAG_LmtDrvTq_flg;/* '<S89>/Switch24' */
extern MONPRM volatile uint8 VDAG_OBCChrgReqFltSt_enum;/* '<S382>/FltStDeb' */

/* OBCChargeRequest����״̬ */
extern MONPRM volatile uint8 VDAG_OBCConnectTmOutFltSt_enum;/* '<S380>/FltStDeb' */

/* OBC���ӳ�ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_OBCInletConnectFltSt_enum;/* '<S385>/FltStDeb' */

/* OBC��ǹ����״̬ */
extern MONPRM volatile uint8 VDAG_OBCModeMsmtchFltSt_enum;/* '<S379>/FltStDeb' */

/* OBCģʽ��ƥ�����״̬ */
extern MONPRM volatile uint8 VDAG_OBCS2StatFltSt_enum;/* '<S381>/FltStDeb' */

/* OBCS2���ӳ�ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl1FltSt_enum;/* '<S386>/FltStDeb' */

/* OBCFailLevel1����״̬ */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl2FltSt_enum;/* '<S387>/FltStDeb' */

/* OBCFailLevel2����״̬ */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl3FltSt_enum;/* '<S388>/FltStDeb' */

/* OBCFailLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl4FltSt_enum;/* '<S376>/FltStDeb' */

/* OBCFailLevel4����״̬ */
extern MONPRM volatile uint8 VDAG_SysPwrModeInvldFltSt_enum;/* '<S432>/FltStDeb' */

/* PowerModeʧЧ����״̬ */
extern MONPRM volatile uint8 VDAG_TMSFailLvl3FltSt_enum;/* '<S433>/FltStDeb' */

/* TMSRFailLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_VehCrashFltSt_enum;/* '<S487>/FltStDeb' */

/* ��ײ����״̬ */
extern MONPRM volatile boolean VDAG_WakeUp_flg;/* '<S306>/Chart' */

/* Ӳ�߻��ѻ���IBSLIN���ѱ�־ */
extern MONPRM volatile uint8 VDAG_WaterTempAbvThrFltSt_enum;/* '<S532>/FltStDeb' */

/* ��ȴˮ�¹��߹���״̬ */
extern MONPRM volatile uint8 VDAG_WaterTempBlwThrFltSt_enum;/* '<S531>/FltStDeb' */

/* ��ȴˮ�¹��͹���״̬ */
extern MONPRM volatile float32 VDSA_AcceltnIdxAvg_pct;/* '<S17>/AvgAcceltnIdx' */
extern MONPRM volatile float32 VDSA_AcceltnIdxRaw_pct;/* '<S17>/Saturation1' */
extern MONPRM volatile float32 VDSA_BrkPedPstnAvg_pct;/* '<S17>/AvgBrkPedPstn' */
extern MONPRM volatile float32 VDSA_DrvSprtIdx_pct;/* '<S17>/Saturation2' */
extern MONPRM volatile boolean VDSA_SprtIdxHldAcc_flg;/* '<S17>/Logical Operator3' */
extern MONPRM volatile boolean VDSA_SprtIdxHldBrk_flg;/* '<S17>/Logical Operator6' */
extern MONPRM volatile float32 VDSA_TqCalcAcceltn_mps2;/* '<S17>/Divide1' */
extern MONPRM volatile boolean VEMS_ACCMOprtCmd_flg;/* '<S30>/ACCMEnble' */

/* ʹ��ACCM */
extern MONPRM volatile float32 VEMS_AccPwrRaw_kW;/* '<S31>/MinMax4' */
extern MONPRM volatile float32 VEMS_CellTempSyn_C;/* '<S83>/Switch1' */
extern MONPRM volatile float32 VEMS_CellUndrVoltDrtFac_c;/* '<S28>/Saturation3' */
extern MONPRM volatile float32 VEMS_ChrgCurFbKi_A;/* '<S80>/Saturation' */
extern MONPRM volatile float32 VEMS_ChrgCurFbKp_A;/* '<S80>/Product2' */
extern MONPRM volatile float32 VEMS_ChrgCurFb_A;/* '<S80>/Saturation2' */
extern MONPRM volatile float32 VEMS_ChrgOvrshtPwr_kW;/* '<S27>/Add1' */
extern MONPRM volatile float32 VEMS_ChrgPwrFbKi_kW;/* '<S46>/Saturation' */
extern MONPRM volatile float32 VEMS_ChrgPwrFbKp_kW;/* '<S46>/Product2' */
extern MONPRM volatile float32 VEMS_ChrgPwrFb_kW;/* '<S27>/Merge' */
extern MONPRM volatile float32 VEMS_DchaCurFbKi_A;/* '<S81>/Saturation' */
extern MONPRM volatile float32 VEMS_DchaCurFbKp_A;/* '<S81>/Product2' */
extern MONPRM volatile float32 VEMS_DchaCurFb_A;/* '<S81>/Saturation2' */
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
extern MONPRM volatile boolean VEMS_TMSActSOCEnbl_flg;/* '<S77>/Switch1' */

/* SOC�Ƿ�����TMS */
extern MONPRM volatile boolean VEMS_TMSPwrEnbl_flg;/* '<S30>/Switch3' */

/* �����Ƿ�����TMS */
extern MONPRM volatile float32 VEMS_TMSUsePwr_kW;/* '<S30>/Subtract' */

/* TMS���ù��� */
extern MONPRM volatile boolean VEMS_UseConChrgCur_flg;/* '<S37>/Switch4' */
extern MONPRM volatile boolean VEMS_UseConDchaCur_flg;/* '<S55>/Switch4' */
extern MONPRM volatile boolean VGSM_AsstDrvFbShft_flg;/* '<S1501>/Logical Operator2' */

/* �淶��ACC/CC��ֹ��λ���� */
extern MONPRM volatile boolean VGSM_DRFlt2N_flg;/* '<S1500>/Switch1' */

/* �淶����������������־λ */
extern MONPRM volatile boolean VGSM_EPBAplyFlt_flg;/* '<S1493>/EPBLogical' */

/* ����P-EPB������� */
extern MONPRM volatile boolean VGSM_EPBRelsFlt_flg;/* '<S1493>/EPBLogical' */

/* ����P-EPB�ͷŹ��� */
extern MONPRM volatile boolean VGSM_GrD2PExcdTm_flg;/* '<S1655>/Chart' */

/* D����P����ʱ��N */
extern MONPRM volatile boolean VGSM_GrNReq2P_flg;/* '<S1500>/Switch2' */

/* N���ǻ��������P������ */
extern MONPRM volatile boolean VGSM_GrR2PExcdTm_flg;/* '<S1652>/Chart' */

/* R����P����ʱ��N */
extern MONPRM volatile boolean VGSM_HldGearP_flg;/* '<S1500>/Switch' */

/* �淶������P����־λ */
extern MONPRM volatile boolean VGSM_INVRunEnbl_flg;/* '<S1503>/Chart' */

/* �淶��INVʹ�ܿ��ƣ�����Ť�ؿ��ƣ�-VCU_1_EnaInvRun */
extern MONPRM volatile uint8 VGSM_PGrSwSts_enum;/* '<S1501>/Switch2' */

/* �淶��P����������־λ-VCU_PGearSwcst */
extern MONPRM volatile boolean VGSM_ReqEPBAply_flg;/* '<S1502>/Logical Operator6' */

/* �淶��EPB���������־λ */
extern MONPRM volatile boolean VGSM_ReqEPBRels_flg;/* '<S1502>/Logical Operator4' */

/* �淶��EPB�ͷ������־λ */
extern MONPRM volatile EnumEPBReq VGSM_ReqEPB_enum;/* '<S1493>/Switch' */

/* �淶��EPB�����ź�-VCUF_ReqEPB */
extern MONPRM volatile EnumTgtGearPstn VGSM_ShftTgtGrReq_enum;/* '<S1501>/Data Type Conversion1' */

/* ������Ŀ�굵λ 0-NoCmd 1-P 2-N 3-D 4-R  */
extern MONPRM volatile EnumGearPstn VGSM_VehActGearPstn_enum;/* '<S1494>/Switch1' */

/* �淶��ʵ�ʵ�λ-VCU_VhclActlGearPos */
extern MONPRM volatile boolean VGSM_VehEPBStErr_flg;/* '<S1493>/Logical Operator' */

/* �淶��P������PGear error-VCU_VhclPGearError */
extern MONPRM volatile EnumTgtGearPstn VGSM_VehTgtGrReq_enum;/* '<S1502>/Data Type Conversion1' */

/* �淶:Ŀ�굵λ */
extern MONPRM volatile uint8 VGSM_VehTgtGrTrnsfr_enum;/* '<S1541>/Switch' */

/* �淶�����������ź� */
extern MONPRM volatile uint8 VHMI_12VBatLowVolSta_enum;/* '<S576>/Switch' */
extern MONPRM volatile float32 VHMI_GrDSldDist_m;/* '<S590>/Saturation' */

/* D��������� */
extern MONPRM volatile boolean VHMI_GrDSldSw_flg;/* '<S590>/Logical Operator' */

/* D�����¼���/�����־ */
extern MONPRM volatile float32 VHMI_GrRSldDist_m;/* '<S590>/Saturation1' */

/* R��ǰ����� */
extern MONPRM volatile boolean VHMI_GrRSldSw_flg;/* '<S590>/Logical Operator4' */

/* R�����¼���/�����־ */
extern MONPRM volatile uint8 VHMI_InfoDisp_enum;/* '<S579>/Arbitration' */

/* �Ǳ���ֵ */
extern MONPRM volatile boolean VHVM_ACChrgEnbl_flg;/* '<S728>/Logical Operator8' */

/* ������������������ */
extern MONPRM volatile boolean VHVM_ACChrging2Stop_flg;/* '<S722>/AND' */

/* ���������ת�Ƶ����ֹͣ��־λ */
extern MONPRM volatile boolean VHVM_ACDchaEnbl_flg;/* '<S728>/Logical Operator10' */

/* �����ŵ������������ */
extern MONPRM volatile boolean VHVM_ACDschrging2Stop_flg;/* '<S722>/AND7' */

/* �����ŵ���ת�Ƶ��ŵ�ֹͣ��־λ */
extern MONPRM volatile EnumBMSSdnCmd VHVM_BMSShutdown_enum;/* '<S701>/Data Type Conversion10' */

/* VCU�ر�BMSָ���ӦCAN�źţ�VCU_BMS_Shutdown */
extern MONPRM volatile EnumBMSWakeUpMd VHVM_BMSWakeUpMode_enum;/* '<S701>/Data Type Conversion8' */

/* VCU����BMS�ķ�ʽ��ӦCAN�źţ�VCU_BMS_WakeupMode */
extern MONPRM volatile boolean VHVM_Bat2DrvTrainEnbl_flg;/* '<S701>/MainState' */

/* VCU�������̵���ָ���ӦCAN�źţ�VCU_Bat2DrvTrainEnb */
extern MONPRM volatile EnumChrgAllwCmd VHVM_ChrgAllowCmd_enum;/* '<S701>/Data Type Conversion12' */

/* VCU����������ָ���ӦCAN�źţ�VCU_ChrgAllowCmd */
extern MONPRM volatile uint8 VHVM_ChrgEnaAC_enum;/* '<S701>/MainState' */

/* VCU����OBC�������ʹ��ָ���ӦCAN�źţ�VCU_ChrgEna_AC */
extern MONPRM volatile boolean VHVM_ChrgEnaDC_flg;/* '<S701>/MainState' */

/* VCU����BMSֱ�����ʹ��ָ���ӦCAN�źţ�VCU_ChrgEna_DC */
extern MONPRM volatile float32 VHVM_DCCBuckLVVolt_V;/* '<S701>/MainState' */

/* VCU����DCDC BUCK��ѹֵ��ӦCAN�źţ�VCU_DCCBuckLV_Vol */
extern MONPRM volatile EnumDCCOprtCmd VHVM_DCCOprtCmd_enum;/* '<S701>/Data Type Conversion6' */

/* VCU����DCDC����ģʽָ���ӦCAN�źţ�VCU_DCCOprtCmd */
extern MONPRM volatile boolean VHVM_DCChrgEnbl_flg;/* '<S728>/Logical Operator2' */

/* ֱ���������������� */
extern MONPRM volatile boolean VHVM_DCChrging2Over_flg;/* '<S722>/AND1' */

/* ֱ�������ת�Ƶ���������־λ */
extern MONPRM volatile boolean VHVM_ECUSleepAllwd_flg;/* '<S701>/MainState' */

/* ����ײ����߱�־λ */
extern MONPRM volatile boolean VHVM_EmgcySdn_flg;/* '<S701>/MainState' */

/* VCU��INV���ͽ����µ�ָ��(INVǿ��ͣ��)��ӦCAN�źţ�VCU_1_EmShutDown */
extern MONPRM volatile boolean VHVM_EnaDisChg_flg;/* '<S701>/MainState' */

/* VCU����INVй��ָ���ӦCAN�źţ�VCU_1_EnaDisChg */
extern MONPRM volatile boolean VHVM_EngyExtrmLo_flg;/* '<S704>/Logical Operator17' */

/* ����������ͱ�־λ */
extern MONPRM volatile boolean VHVM_INVEnbl_flg;/* '<S701>/MainState' */

/* VCUӲ�߻���INV */
extern MONPRM volatile boolean VHVM_INVPreprogmFlg_flg;/* '<S723>/Switch1' */

/* INVԤ����������� */
extern MONPRM volatile float32 VHVM_MaxChrgCurntDC_A;/* '<S701>/MainState' */

/* VCU����BMSֱ�������������ӦCAN�źţ�VCU_MaxChrgCrnt_DC */
extern MONPRM volatile float32 VHVM_MaxChrgVoltDC_V;/* '<S701>/MainState' */

/* VCU����BMSֱ���������ѹ��ӦCAN�źţ�VCU_MaxChrgVol_DC */
extern MONPRM volatile float32 VHVM_MaxHVDCCurntAC_A;/* '<S701>/MainState' */

/* VCU����OBC���������������ӦCAN�źţ�VCU_MaxHVDC_Cur_AC */
extern MONPRM volatile float32 VHVM_MaxHVDCVoltAC_V;/* '<S701>/MainState' */

/* VCU����OBC�����������ѹ��ӦCAN�źţ�VCU_MaxHVDC_Vol_AC */
extern MONPRM volatile EnumOBCOprtCmd VHVM_OBCOprtCmd_enum;/* '<S702>/Data Type Conversion4' */

/* VCU����OBC����ģʽָ���ӦCAN�źţ�VCU_OBCOprtCmd */
extern MONPRM volatile EnumPTActMd VHVM_PTActOprtMode_enum;/* '<S701>/Data Type Conversion4' */

/* ��ѹPT״̬ */
extern MONPRM volatile boolean VHVM_PTRdy2PTStdby_flg;/* '<S725>/Switch1' */

/* PTRdy��PTStdby��־λ */
extern MONPRM volatile boolean VHVM_PTStdby2PTRdy_flg;/* '<S725>/Switch' */

/* PTStdby��PTRdy��־λ */
extern MONPRM volatile boolean VHVM_PowUpSelfChek_flg;/* '<S726>/Switch' */

/* ��ѹ�Լ��־λ */
extern MONPRM volatile boolean VHVM_PwrOn2PwrDwn_flg;/* '<S727>/Switch' */

/* ��ѹ�µ����������־λ������/����/������ */
extern MONPRM volatile boolean VHVM_SOPExtrmLo_flg;/* '<S704>/Relational Operator4' */

/* ���SOP���ͣ����ڹر�DCDC */
extern MONPRM volatile EnumSysSta VHVM_SysSta_enum;/* '<S701>/Data Type Conversion2' */

/* ��ѹ��״̬ */
extern MONPRM volatile uint8 VHVM_TBOX2OBC_emun;/* '<S702>/Switch1' */

/* TBOXԶ�̳�ŵ�ָ�� */
extern MONPRM volatile EnumVCUMode VHVM_VCUMode_enum;/* '<S701>/Data Type Conversion' */

/* ��ѹ��ת̬ */
extern MONPRM volatile boolean VHVM_VehHalt_flg;/* '<S717>/Switch4' */

/* ����ֹͣ��־λ�����ټ��䣩 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpACChrg_flg;/* '<S728>/Logical Operator16' */

/* ������绽���ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpACDcha_flg;/* '<S728>/Logical Operator26' */

/* �����ŵ绽���ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpDCChrg_flg;/* '<S728>/Logical Operator4' */

/* ֱ����绽���ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpIBS_flg;/* '<S728>/Logical Operator6' */

/* IBS�����ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpKL15_flg;/* '<S728>/Logical Operator' */

/* K15�����ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUp_flg;/* '<S728>/Switch' */

/* ���ѵ��ϸ�ѹ�������㣨����Դ������+��ѹ�Լ�ͨ���� */
extern MONPRM volatile boolean VHVM_WakeUpBMS_flg;/* '<S701>/MainState' */

/* VCUӲ�߻���BMS */
extern MONPRM volatile boolean VHVM_WakeUpVCU_flg;/* '<S729>/Switch' */

/* ���ߵ������������� */
extern MONPRM volatile boolean VIBS_BMSBatSOCAllow_flg;/* '<S952>/Switch3' */

/* �������SOC�������־λ_versteckt */
extern MONPRM volatile boolean VIBS_ChgNumAllow_flg;/* '<S952>/AND' */

/* ������������־λ_versteckt */
extern MONPRM volatile uint8 VIBS_ChgNum_cnt;/* '<S952>/Switch2' */

/* IBS�������_versteckt */
extern MONPRM volatile boolean VIBS_ChrgBascCond_flg;/* '<S952>/Logical Operator2' */

/* ��������������㣨�����������ѹ��_versteckt */
extern MONPRM volatile boolean VIBS_ChrgEnbl_flg;/* '<S952>/Logical Operator7' */

/* IBS���ʹ�ܱ�־λ_versteckt */
extern MONPRM volatile boolean VIBS_ChrgOver_flg;/* '<S950>/ChrgSt' */

/* IBS���������־λ_versteckt */
extern MONPRM volatile float32 VIBS_ChrgVoltThr_V;/* '<S953>/VoltState' */

/* �����ѹ��ֵ_versteckt */
extern MONPRM volatile float32 VIBS_EnvirTemp_C;/* '<S972>/Switch' */

/* IBS�����¶�_versteckt */
extern MONPRM volatile uint8 VIBS_FailChgNum_cnt;/* '<S952>/Switch5' */

/* IBS����ʧ�ܴ���_versteckt */
extern MONPRM volatile boolean VIBS_FbRctWup_flg;/* '<S952>/Logical Operator6' */

/* IBS��ֹRTC���ѱ�־λ_versteckt */
extern MONPRM volatile boolean VIBS_HVReq_flg;/* '<S952>/Switch' */

/* IBS�����ϸ�ѹ��־λ_versteckt */
extern MONPRM volatile float32 VIBS_HwKL30_V;/* '<S971>/Switch' */

/* �˲����KL30��ѹ_versteckt */
extern MONPRM volatile boolean VIBS_NMReq_flg;/* '<S959>/Switch4' */

/* IBS���������־λ_versteckt */
extern MONPRM volatile uint16 VIBS_NextRtcWupThr_min;/* '<S953>/Switch1' */

/* �´β��绽��RTC��ʱ��_versteckt */
extern MONPRM volatile EnumIBSChrgSt VIBS_RTCChrgSt_enum;/* '<S950>/Data Type Conversion' */

/* IBS����״̬_versteckt */
extern MONPRM volatile boolean VIBS_RTCWakeup_flg;/* '<S977>/Chart' */

/* RTC���ѱ�־λ�����ӳ�ʱ�䣩_versteckt */
extern MONPRM volatile boolean VIBS_SleepAllwd_flg;/* '<S952>/SleepAllwd' */

/* IBS����ײ����߱�־λ_versteckt */
extern MONPRM volatile uint16 VIBS_WupChgTmThr_min;/* '<S953>/Switch2' */

/* IBS����ʱ����ֵ_versteckt */
extern MONPRM volatile boolean VIBS_WupVoltAllow_flg;/* '<S973>/Switch4' */

/* KL30��ѹ�����־λ_versteckt */
extern MONPRM volatile boolean VIPC_ACCCfgd_flg;/* '<S828>/Switch8' */
extern MONPRM volatile boolean VIPC_AccPed1Flt_flg;/* '<S832>/Logical Operator1' */
extern MONPRM volatile boolean VIPC_AccPed1LrnDwnActv_flg;/* '<S842>/Relational Operator' */
extern MONPRM volatile boolean VIPC_AccPed1LrnUpActv_flg;/* '<S835>/Logical Operator5' */
extern MONPRM volatile float32 VIPC_AccPed1MinPstnLrnd_pct;/* '<S835>/Switch2' */
extern MONPRM volatile float32 VIPC_AccPed1NormzAvg_pct;/* '<S841>/Switch' */
extern MONPRM volatile float32 VIPC_AccPed1NormzPstn_pct;/* '<S832>/Switch5' */
extern MONPRM volatile float32 VIPC_AccPed1SclPstn_pct;/* '<S836>/Divide1' */
extern MONPRM volatile boolean VIPC_AccPed2Flt_flg;/* '<S832>/Logical Operator2' */
extern MONPRM volatile boolean VIPC_AccPed2LrnDwnActv_flg;/* '<S846>/Relational Operator' */
extern MONPRM volatile boolean VIPC_AccPed2LrnUpActv_flg;/* '<S837>/Logical Operator5' */
extern MONPRM volatile float32 VIPC_AccPed2MinPstnLrnd_pct;/* '<S837>/Switch2' */
extern MONPRM volatile float32 VIPC_AccPed2NormzAvg_pct;/* '<S845>/Switch' */
extern MONPRM volatile float32 VIPC_AccPed2NormzPstn_pct;/* '<S832>/Switch7' */
extern MONPRM volatile float32 VIPC_AccPed2SclPstn_pct;/* '<S838>/Divide5' */
extern MONPRM volatile boolean VIPC_AccPedPstnVld_flg;/* '<S834>/Switch3' */
extern MONPRM volatile float32 VIPC_AccPedPstn_pct;/* '<S830>/MinMax3' */
extern MONPRM volatile uint8 VIPC_AccPedSnsrSta_enum;/* '<S834>/Switch3' */
extern MONPRM volatile boolean VIPC_AccPedStkActv_flg;/* '<S833>/Logical Operator6' */
extern MONPRM volatile boolean VIPC_AccPedStkBrkPrsd_flg;/* '<S860>/Switch4' */
extern MONPRM volatile float32 VIPC_AccPedStkPstn_pct;/* '<S833>/MinMax' */
extern MONPRM volatile boolean VIPC_AccPedStkStab_flg;/* '<S862>/Relational Operator' */
extern MONPRM volatile float32 VIPC_AccPedWghtAvg_pct;/* '<S859>/Switch' */
extern MONPRM volatile float32 VIPC_AccPedWghtPstn_pct;/* '<S834>/Switch3' */
extern MONPRM volatile float32 VIPC_AccPedZeroPstn_pct;/* '<S833>/Switch' */
extern MONPRM volatile boolean VIPC_BrkPedPstnVld_flg;/* '<S825>/Logical Operator8' */
extern MONPRM volatile float32 VIPC_BrkPedPstn_pct;/* '<S825>/Saturation1' */
extern MONPRM volatile boolean VIPC_BrkSwActv_flg;/* '<S825>/Logical Operator' */
extern MONPRM volatile boolean VIPC_CCSCfgd_flg;/* '<S828>/Switch1' */
extern MONPRM volatile boolean VIPC_CrpCtrlCfgd_flg;/* '<S828>/Switch2' */
extern MONPRM volatile EnumCrpModeAct VIPC_CrpModeAct_enum;/* '<S827>/Switch12' */
extern MONPRM volatile EnumDrvModeAct VIPC_DrvModeAct_enum;/* '<S827>/Switch13' */
extern MONPRM volatile uint8 VIPC_DrvPwrIntnsty_pct;/* '<S827>/Switch25' */
extern MONPRM volatile boolean VIPC_DrvSw_flg;/* '<S830>/Relational Operator3' */
extern MONPRM volatile boolean VIPC_EPBAppld_flg;/* '<S826>/Logical Operator2' */
extern MONPRM volatile boolean VIPC_EPBReld_flg;/* '<S826>/Logical Operator1' */
extern MONPRM volatile boolean VIPC_HDCCfgd_flg;/* '<S828>/Switch3' */
extern MONPRM volatile EnumRegenModeAct VIPC_RegenModeAct_enum;/* '<S827>/Switch15' */
extern MONPRM volatile uint8 VIPC_RegenPwrIntnsty_pct;/* '<S827>/Switch28' */
extern MONPRM volatile boolean VIPC_SnowMode_flg;/* '<S827>/Switch14' */
extern MONPRM volatile float32 VIPC_TireRadius_m;/* '<S828>/TireSizeTable' */
extern MONPRM volatile uint8 VIPC_VehHiddenMode_enum;/* '<S827>/VehHiddenMode' */
extern MONPRM volatile float32 VIPC_VehSpdDrvnMotor_kph;/* '<S829>/Product1' */
extern MONPRM volatile boolean VIPC_VehSpdDrvnVld_flg;/* '<S896>/Logical Operator2' */
extern MONPRM volatile float32 VIPC_VehSpdDrvn_kph;/* '<S896>/Switch7' */
extern MONPRM volatile boolean VIPC_VehSpdNonDrvnVld_flg;/* '<S897>/Logical Operator2' */
extern MONPRM volatile float32 VIPC_VehSpdNonDrvn_kph;/* '<S897>/Switch7' */
extern MONPRM volatile boolean VIPC_VehSpdVld_flg;/* '<S896>/SignalConversion' */
extern MONPRM volatile float32 VIPC_VehSpd_kph;/* '<S896>/Switch4' */
extern MONPRM volatile boolean VIPC_VpedAutoCrp_flg;/* '<S884>/Switch4' */
extern MONPRM volatile boolean VIPC_ZeroPstnRst_flg;/* '<S833>/Logical Operator3' */
extern MONPRM volatile boolean VIPC_iTPMSCfgd_flg;/* '<S828>/Switch4' */
extern MONPRM volatile float32 VIPM_HwAccPedCh1SuplyVolt_mV;/* '<S1451>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh1Volt_mV;/* '<S1452>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh2SuplyVolt_mV;/* '<S1453>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh2Volt_mV;/* '<S1454>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwBMSWakeup_flg;/* '<S1455>/Switch4' */
extern MONPRM volatile boolean VIPM_HwBrkSwHi_flg;/* '<S1456>/Switch4' */
extern MONPRM volatile boolean VIPM_HwBrkSwLo_flg;/* '<S1457>/Switch4' */
extern MONPRM volatile boolean VIPM_HwCrpModeSw_flg;/* '<S1458>/Switch4' */
extern MONPRM volatile boolean VIPM_HwDrvModeSw_flg;/* '<S1459>/Switch4' */
extern MONPRM volatile boolean VIPM_HwEmgcyShutOff_flg;/* '<S1460>/Switch4' */
extern MONPRM volatile boolean VIPM_HwKL15A_flg;/* '<S1461>/Switch4' */
extern MONPRM volatile boolean VIPM_HwKL15B_flg;/* '<S1462>/Switch4' */
extern MONPRM volatile uint16 VIPM_HwKL30_mV;/* '<S1463>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwOBCWakeup_flg;/* '<S1464>/Switch4' */
extern MONPRM volatile boolean VIPM_HwRearFogLampSwt_flg;/* '<S1465>/Switch4' */
extern MONPRM volatile EnumPGearSwSts VIPM_HwShftPstnSwSts_enum;/* '<S1466>/Switch4' */
extern MONPRM volatile uint16 VIPM_HwShftPstnSw_Ohm;/* '<S1448>/HwShftPstnSw' */
extern MONPRM volatile boolean VIPM_HwVehCrash_flg;/* '<S1467>/Switch4' */
extern MONPRM volatile float32 VNVM_AvgPwrCnsm_kWh100km;/* '<S1449>/Add2' */

/* _versteckt */
extern MONPRM volatile float32 VNVM_AvgSOCCnsmWght_pctp100km;/* '<S1449>/Add6' */

/* _versteckt */
extern MONPRM volatile EnumCrpModeAct VNVM_CrpModeAct_enum;/* '<S1449>/Data Type Conversion1' */

/* _versteckt */
extern MONPRM volatile EnumDrvModeAct VNVM_DrvModeAct_enum;/* '<S1449>/Data Type Conversion23' */

/* _versteckt */
extern MONPRM volatile uint8 VNVM_DrvPwrIntnsty_pct;/* '<S1449>/Selector6' */

/* _versteckt */
extern MONPRM volatile float32 VNVM_DynRmnMilEst_km;/* '<S1449>/Gain2' */

/* _versteckt */
extern MONPRM volatile uint8 VNVM_EEWritten_nu;/* '<S1449>/Selector13' */

/* _versteckt */
extern MONPRM volatile uint8 VNVM_IBSChrgFailNum_cnt;/* '<S1449>/Selector1' */

/* _versteckt */
extern MONPRM volatile uint8 VNVM_IBSChrgNum_cnt;/* '<S1449>/Selector' */

/* _versteckt */
extern MONPRM volatile EnumRegenModeAct VNVM_RegenModeAct_enum;/* '<S1449>/Data Type Conversion24' */

/* _versteckt */
extern MONPRM volatile uint8 VNVM_RegenPwrIntnsty_pct;/* '<S1449>/Selector7' */

/* _versteckt */
extern MONPRM volatile EnumXWhlDistErrRefSt VNVM_XWhlDistErrRefStat_enum;/* '<S1449>/Data Type Conversion22' */

/* _versteckt */
extern MONPRM volatile float32 VNVM_XWhlDistErrRef_mpkm;/* '<S1449>/Add1' */

/* _versteckt */
extern MONPRM volatile boolean VNVM_iTPMSWrng_flg;/* '<S1449>/Data Type Conversion21' */

/* _versteckt */
extern MONPRM volatile boolean VOPM_HwWakeupBMS_flg;/* '<S1480>/Switch4' */
extern MONPRM volatile float32 VRMEAvgPwrCnsm15km_kWhpkm;/* '<S910>/Signal Copy2' */

/* 15kmƽ��Pwr�ܺ� */
extern MONPRM volatile float32 VRME_AvgPwrCnsm100km_kWhpkm;/* '<S910>/Signal Copy5' */

/* 100kmƽ��Pwr�ܺ� */
extern MONPRM volatile float32 VRME_AvgPwrCnsm10km_kWhpkm;/* '<S910>/Signal Copy1' */

/* 10kmƽ��Pwr�ܺ� */
extern MONPRM volatile float32 VRME_AvgPwrCnsm25km_kWhpkm;/* '<S910>/Signal Copy3' */

/* 25kmƽ��Pwr�ܺ� */
extern MONPRM volatile float32 VRME_AvgPwrCnsm50km_kWhpkm;/* '<S910>/Signal Copy4' */

/* 50kmƽ��Pwr�ܺ� */
extern MONPRM volatile float32 VRME_AvgPwrCnsm5km_kWhpkm;/* '<S910>/Signal Copy' */

/* 5kmƽ��Pwr�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm100Num_pctpkm;/* '<S923>/Signal Copy5' */

/* ǰ100������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm10Num_pctpkm;/* '<S923>/Signal Copy1' */

/* ǰ10������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm15Num_pctpkm;/* '<S923>/Signal Copy2' */

/* ǰ15������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm25Num_pctpkm;/* '<S923>/Signal Copy3' */

/* ǰ25������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm50Num_pctpkm;/* '<S923>/Signal Copy4' */

/* ǰ50������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm5Num_pctpkm;/* '<S923>/Signal Copy' */

/* ǰ5������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsmWght_pctpkm;/* '<S923>/Switch1' */

/* ��Ȩƽ��SOC�ܺ�/km */
extern MONPRM volatile boolean VRME_CHTCRmnMilEstV_flg;/* '<S905>/Logical Operator' */

/* CHTC��׼���������Ч�� */
extern MONPRM volatile float32 VRME_CHTCRmnMilEst_km;/* '<S905>/MRME_CHTCStdRmnMil_km' */

/* CHTC��׼�������ֵ */
extern MONPRM volatile float32 VRME_CalPwrCnsmPerTrig_kWhpkm;/* '<S909>/Switch4' */

/* Pwr����/��λ��̣�1km�� */
extern MONPRM volatile boolean VRME_CalPwrCnsmTrig_flg;/* '<S909>/Relational Operator1' */

/* �ۼ���̴��ڵ�λ��̣�Ĭ��1km�� */
extern MONPRM volatile float32 VRME_CalSOCCnsmPerTrig_pctptrig;/* '<S922>/Switch4' */

/* SOC����/Ŀ����� */
extern MONPRM volatile float32 VRME_CalSOCCnsmPerkm_pctpkm;/* '<S922>/Divide' */

/* Ŀ�������������Ϊ��λ��� */
extern MONPRM volatile float32 VRME_CalSOCCnsmTgtDist_m;/* '<S922>/Switch1' */

/* ��λĿ����ʻ��� */
extern MONPRM volatile boolean VRME_CalSOCCnsmTrig_flg;/* '<S922>/Relational Operator1' */

/* �ۼ���̴���Ŀ����� */
extern MONPRM volatile float32 VRME_DynRmnMilEstChgFac_c;/* '<S924>/MRME_DynEstRmnChgStp_c' */

/* ��̬�����仯ϵ�� */
extern MONPRM volatile float32 VRME_DynRmnMilEstTgt_km;/* '<S945>/Switch2' */

/* ��̬����Ŀ��ֵ */
extern MONPRM volatile boolean VRME_DynRmnMilEstUpdTrig_flg;/* '<S924>/Relational Operator2' */

/* ��������ֵ */
extern MONPRM volatile boolean VRME_DynRmnMilEstV_flg;/* '<S924>/Logical Operator1' */

/* ��̬������Ч�� */
extern MONPRM volatile float32 VRME_DynRmnMilEst_km;/* '<S944>/Switch2' */

/* ��̬�����޷�ֵ */
extern MONPRM volatile boolean VRME_VehStacEnbl_flg;/* '<S924>/Logical Operator4' */

/* ������ֹ״̬ */
extern MONPRM volatile float32 VRME_VehTotDistCurrCyc_km;/* '<S922>/Gain2' */

/* ��ǰ��ʻѭ���ۼ������ */
extern MONPRM volatile float32 VRME_VehTotPwrCurrCyc_kWh;/* '<S909>/Plus2' */

/* ��ǰ��ʻѭ������ʹ�ù��� */
extern MONPRM volatile float32 VRME_WLTPRmnMilEstDwLim_km;/* '<S922>/Product3' */

/* ��̬��������ֵ */
extern MONPRM volatile float32 VRME_WLTPRmnMilEstUpLim_km;/* '<S922>/Product2' */

/* ��̬��������ֵ */
extern MONPRM volatile float32 VRME_WLTPRmnMilEst_km;/* '<S922>/MRME_WLTPStdRmnMil_km' */

/* WLTP��׼�������ֵ */
extern MONPRM volatile float32 VRME_WLTPStdPwrCnsm_kWhpkm;/* '<S909>/Gain5' */

/* ��׼�����µ�� */
extern MONPRM volatile float32 VRME_WLTPStdSOCCnsm_pctpkm;/* '<S922>/Gain3' */

/* ��׼������SOC����/km */
extern MONPRM volatile boolean VTBX_VCUChrgngCondsFb_flg;/* '<S983>/Compare' */
extern MONPRM volatile uint8 VTBX_VCULckVehWrn_enum;/* '<S982>/Switch3' */
extern MONPRM volatile boolean VTBX_VCUOprtLicFb_flg;/* '<S984>/Compare' */
extern MONPRM volatile uint8 VTBX_VCUSpdLimLvlFb_enum;/* '<S982>/Switch2' */
extern MONPRM volatile uint8 VTBX_VCUSpdLimLvlSetFb_enum;/* '<S982>/Switch1' */
extern MONPRM volatile boolean VTBX_VCUVerFb_flg;/* '<S985>/Chart' */
extern MONPRM volatile uint8 VTBX_VCUVerSetFb_enum;/* '<S982>/Switch6' */
extern MONPRM volatile float32 VTQC_ABSorESPActvTm_s;/* '<S1256>/MinMax' */
extern MONPRM volatile float32 VTQC_BrkRegenMaxTqWhl_Nm;/* '<S1251>/Switch17' */
extern MONPRM volatile float32 VTQC_BrkRegenTgtTqWhl_Nm;/* '<S1251>/Switch2' */
extern MONPRM volatile float32 VTQC_CstRegenLmtTq_Nm;/* '<S1249>/CstRegenLmtTq' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhlABS_Nm;/* '<S1249>/MinMax1' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhlRBS_Nm;/* '<S1258>/MinMax5' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhl_Nm;/* '<S1250>/Switch5' */
extern MONPRM volatile float32 VTQC_MotorTqReq_Nm;/* '<S1250>/Divide' */
extern MONPRM volatile boolean VTQC_RBSActv_flg;/* '<S1259>/Switch4' */
extern MONPRM volatile float32 VTQD_AccelPedPstnRescl_pct;/* '<S1270>/Product' */
extern MONPRM volatile float32 VTQD_AdaptCstDeltaAcceltn_mps2;/* '<S1286>/Add5' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqFF_Nm;/* '<S1286>/Add2' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqI_N;/* '<S1286>/Saturation2' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqPID_Nm;/* '<S1286>/Product6' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqP_N;/* '<S1286>/Product3' */
extern MONPRM volatile float32 VTQD_AdaptCstMaxTqWhl_Nm;/* '<S1282>/MinMax4' */
extern MONPRM volatile float32 VTQD_AdaptCstMinTqWhl_Nm;/* '<S1282>/MinMax5' */
extern MONPRM volatile boolean VTQD_AdaptCstRegenEnbl_flg;/* '<S1282>/Logical Operator9' */
extern MONPRM volatile float32 VTQD_AdaptCstTgtAcceltn_mps2;/* '<S1288>/Switch' */
extern MONPRM volatile float32 VTQD_AdaptCstTqReqWhl_Nm;/* '<S1286>/MinMax6' */
extern MONPRM volatile boolean VTQD_BkwdDrv_flg;/* '<S1309>/Switch4' */
extern MONPRM volatile boolean VTQD_BrkRegenEnbl_flg;/* '<S1281>/Logical Operator1' */
extern MONPRM volatile float32 VTQD_CrpTqReqWhl_Nm;/* '<S1272>/Switch2' */
extern MONPRM volatile boolean VTQD_CstRegenEnbl_flg;/* '<S1281>/Logical Operator13' */
extern MONPRM volatile float32 VTQD_CstRegenEndPstn_pct;/* '<S1281>/Switch2' */
extern MONPRM volatile float32 VTQD_CstRegenTqReqWhl_Nm;/* '<S1283>/Switch4' */
extern MONPRM volatile float32 VTQD_DrvTqDrtFac_c;/* '<S1310>/Saturation' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhlMrg_Nm;/* '<S1311>/Switch4' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhlRaw_Nm;/* '<S1270>/Merge' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhl_Nm;/* '<S1268>/Switch3' */
extern MONPRM volatile boolean VTQD_DsblCrp_flg;/* '<S1272>/Logical Operator12' */
extern MONPRM volatile float32 VTQD_FullPedDrvTqWhl_Nm;/* '<S1270>/Signal Conversion1' */
extern MONPRM volatile float32 VTQD_FwdPedMap_pct;/* '<S1273>/Switch9' */
extern MONPRM volatile float32 VTQD_PedalTqReqWhlRaw_Nm;/* '<S1267>/Add' */
extern MONPRM volatile uint16 VTQD_TaskRunCounter_cnt;/* '<S1030>/Max1' */

/* test signal, to be deleted */
extern MONPRM volatile boolean VTQD_TqZeroFast_flg;/* '<S1302>/Logical Operator4' */
extern MONPRM volatile boolean VTQD_TqZeroSlow_flg;/* '<S1302>/Logical Operator2' */
extern MONPRM volatile boolean VTQD_TqZero_flg;/* '<S1302>/Logical Operator1' */
extern MONPRM volatile float32 VTQF_DrvTqReqWhl_Nm;/* '<S1326>/Switch2' */
extern MONPRM volatile float32 VTQF_TipOutTqDecRateCoeff_rat;/* '<S1328>/1-D Lookup Table1' */
extern MONPRM volatile boolean VTQF_TqInc_flg;/* '<S1338>/Switch4' */
extern MONPRM volatile float32 VTQF_TqOutChgRate_Nmps;/* '<S1348>/Switch' */
extern MONPRM volatile float32 VTQF_TqRateDecTgtMax_Nmps;/* '<S1328>/Switch3' */
extern MONPRM volatile float32 VTQF_TqRateDecTgtMin_Nmps;/* '<S1328>/MinMax4' */
extern MONPRM volatile float32 VTQF_TqRateIncTgtMax_Nmps;/* '<S1329>/Switch5' */
extern MONPRM volatile float32 VTQF_TqRateIncTgtMin_Nmps;/* '<S1329>/MinMax4' */
extern MONPRM volatile float32 VTQF_TqRateLimDec_Nmps;/* '<S1328>/MinMax3' */
extern MONPRM volatile boolean VTQF_TqRateLimEndg_flg;/* '<S1327>/Logical Operator9' */
extern MONPRM volatile float32 VTQF_TqRateLimInc_Nmps;/* '<S1329>/MinMax2' */
extern MONPRM volatile float32 VTQF_TqRawChgRate_Nmps;/* '<S1347>/Switch' */
extern MONPRM volatile float32 VTQF_WhlDrgMaxTqZX_Nm;/* '<S1346>/Switch1' */
extern MONPRM volatile float32 VTQF_WhlDrvMaxTqZX_Nm;/* '<S1346>/Switch7' */
extern MONPRM volatile boolean VTQR_ASDEnbl_flg;/* '<S1351>/Logical Operator14' */
extern MONPRM volatile float32 VTQR_ASDSpdFltHi_rpm;/* '<S1359>/Switch' */
extern MONPRM volatile float32 VTQR_ASDSpdOscRaw_rpm;/* '<S1355>/Add1' */
extern MONPRM volatile float32 VTQR_ASDSpdOsc_rpm;/* '<S1357>/Multiport Switch' */
extern MONPRM volatile float32 VTQR_ASDTqReqRaw_Nm;/* '<S1363>/MinMax5' */
extern MONPRM volatile float32 VTQR_ASDTqReq_Nm;/* '<S1356>/Switch3' */
extern MONPRM volatile boolean VTQR_MotDampngEnbl_flg;/* '<S1351>/Logical Operator1' */
extern MONPRM volatile float32 VTQR_MotDampngLmt_Nm;/* '<S1371>/MinMax5' */
extern MONPRM volatile EnumMotorDirReq VTQR_MotorDirReq_enum;/* '<S1352>/Switch4' */
extern MONPRM volatile EnumMotorModeReq VTQR_MotorModeReq_enum;/* '<S1349>/Signal Conversion15' */
extern MONPRM volatile float32 VTQR_MotorSpdReq_rpm;/* '<S1349>/Signal Conversion1' */
extern MONPRM volatile boolean VTQR_MotorStdby_flg;/* '<S1353>/Logical Operator1' */
extern MONPRM volatile float32 VTQR_MotorTqReq_Nm;/* '<S1349>/Signal Conversion2' */
extern MONPRM volatile float32 VTZX_AZDecRate_Nmps;/* '<S1387>/1-D Lookup Table4' */
extern MONPRM volatile float32 VTZX_AZIncRate_Nmps;/* '<S1387>/1-D Lookup Table3' */
extern MONPRM volatile float32 VTZX_BZDecRate_Nmps;/* '<S1387>/1-D Lookup Table2' */
extern MONPRM volatile float32 VTZX_BZIncRate_Nmps;/* '<S1387>/1-D Lookup Table1' */
extern MONPRM volatile boolean VTZX_BypZX_flg;/* '<S1391>/Logical Operator1' */
extern MONPRM volatile boolean VTZX_ClkActv_flg;/* '<S1390>/Switch4' */
extern MONPRM volatile float32 VTZX_ClkZXTm_s;/* '<S1383>/Switch1' */
extern MONPRM volatile float32 VTZX_MotorTqReqPrdt_Nm;/* '<S1403>/MinMax5' */
extern MONPRM volatile float32 VTZX_MotorTqReqZX_Nm;/* '<S1388>/TqZXSt' */
extern MONPRM volatile float32 VTZX_MotorTqReq_Nm;/* '<S1383>/Switch6' */
extern MONPRM volatile boolean VTZX_TqInc_flg;/* '<S1397>/Switch4' */
extern MONPRM volatile boolean VTZX_TqRateLimRamp_flg;/* '<S1404>/Switch4' */
extern MONPRM volatile EnumTZXStat VTZX_TqZXSt_enum;/* '<S1388>/Data Type Conversion1' */
extern MONPRM volatile float32 VTZX_ZeroTqHldDec_Nm;/* '<S1388>/TqZXSt' */
extern MONPRM volatile float32 VTZX_ZeroTqHldInc_Nm;/* '<S1388>/TqZXSt' */
extern MONPRM volatile float32 VTZX_ZeroTqOfstDec_Nm;/* '<S1387>/Switch3' */
extern MONPRM volatile float32 VTZX_ZeroTqOfstInc_Nm;/* '<S1387>/Switch2' */
extern MONPRM volatile float32 VTZX_ZeroTqOfst_Nm;/* '<S1387>/Switch4' */
extern MONPRM volatile float32 VTZX_ZeroXTm_s;/* '<S1387>/Switch8' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr1_mpkm;/* '<S998>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr2_mpkm;/* '<S998>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr3_mpkm;/* '<S998>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr4_mpkm;/* '<S998>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr5_mpkm;/* '<S998>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr_mpkm;/* '<S998>/Add3' */
extern MONPRM volatile float32 VVSO_DrvDist_m;/* '<S1011>/Switch1' */
extern MONPRM volatile float32 VVSO_RoadSlopEst_pct;/* '<S992>/Product19' */
extern MONPRM volatile float32 VVSO_RoadSlopTqEst_Nm;/* '<S996>/MinMax5' */
extern MONPRM volatile float32 VVSO_SlopEst_rat;/* '<S1020>/Switch' */
extern MONPRM volatile float32 VVSO_VehDrvResistTq_Nm;/* '<S992>/Switch4' */
extern MONPRM volatile float32 VVSO_VehMassEst_kg;/* '<S1019>/Switch' */
extern MONPRM volatile float32 VVSO_VehSpd_kph;/* '<S1002>/Gain1' */
extern MONPRM volatile boolean VVSO_WhlDistErrHld_flg;/* '<S1002>/OR' */
extern MONPRM volatile EnumXWhlDistErrRefSt VVSO_XWhlDistErrRefStat_enum;/* '<S998>/Signal Conversion2' */
extern MONPRM volatile float32 VVSO_XWhlDistErrRef_mpkm;/* '<S998>/Signal Conversion1' */
extern MONPRM volatile float32 VVSO_XWhlDistErr_m;/* '<S1011>/Switch4' */
extern MONPRM volatile boolean VVSO_iTPMSAvail_flg;/* '<S1002>/Logical Operator' */
extern MONPRM volatile EnumiTPMSSt VVSO_iTPMSState_enum;/* '<S998>/Signal Conversion' */
extern MONPRM volatile boolean VVSO_iTPMSWrng_flg;/* '<S998>/Signal Conversion3' */
extern MONPRM volatile boolean VVTM_BrkPedReld_flg;/* '<S1429>/Logical Operator3' */
extern MONPRM volatile uint8 VVTM_DrvMotorSta_enum;/* '<S1436>/DriveMotorState' */
extern MONPRM volatile boolean VVTM_ESPIntvActv_flg;/* '<S1429>/Logical Operator4' */
extern MONPRM volatile float32 VVTM_MotorActPwr_kW;/* '<S1443>/Switch2' */
extern MONPRM volatile float32 VVTM_MotorSpd_rpm;/* '<S1431>/Switch' */
extern MONPRM volatile boolean VVTM_PCUFailSta_flg;/* '<S1436>/Logical Operator2' */
extern MONPRM volatile boolean VVTM_RegenReqBrkLampOn_flg;/* '<S1441>/Switch1' */
extern MONPRM volatile float32 VVTM_RsrvPwr_kW;/* '<S1438>/MinMax4' */
extern MONPRM volatile float32 VVTM_RsrvRecupPwr_kW;/* '<S1438>/MinMax1' */
extern MONPRM volatile float32 VVTM_VehAcceltn_mps2;/* '<S1434>/Switch' */
extern MONPRM volatile uint8 VVTM_VehActGrPstn_enum;/* '<S1429>/Switch1' */
extern MONPRM volatile float32 VVTM_VehSpd_kph;/* '<S1430>/Switch' */

#endif                                 /* RTW_HEADER_monPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
