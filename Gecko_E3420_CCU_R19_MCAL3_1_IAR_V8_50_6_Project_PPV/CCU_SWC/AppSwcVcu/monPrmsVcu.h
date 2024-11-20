/*
 * File: monPrmsVcu.h
 *
 * Code generated for Simulink model 'AppSwcVcu'.
 *
 * Model version                  : 9.642
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov 20 11:28:45 2024
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
extern MONPRM volatile boolean BSW_RTCWakeup_flg;/* '<S275>/Switch4' */

/* RTC���ѱ�־λ_versteckt */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Day;/* '<S963>/Data Type Conversion45' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Hour;/* '<S963>/Data Type Conversion1' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Min;/* '<S963>/Data Type Conversion2' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Month;/* '<S963>/Data Type Conversion34' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Sec;/* '<S963>/Switch2' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Year;/* '<S963>/Data Type Conversion33' */
extern MONPRM volatile uint8 VBSW_WakeupReasn_enum;/* '<S8>/EcuWakeupReasn' */
extern MONPRM volatile float32 VCPT_MotorDrgMaxTq_Nm;/* '<S541>/MinMax6' */
extern MONPRM volatile float32 VCPT_MotorDrvMaxTq_Nm;/* '<S541>/MinMax7' */
extern MONPRM volatile float32 VCPT_MotorGenMaxTq_Nm;/* '<S553>/Switch1' */
extern MONPRM volatile float32 VCPT_MotorMotMaxTq_Nm;/* '<S552>/Switch1' */
extern MONPRM volatile boolean VCPT_MotorSpdRvrs_flg;/* '<S541>/Switch3' */
extern MONPRM volatile float32 VCPT_MotorSpd_rpm;/* '<S547>/Switch' */
extern MONPRM volatile float32 VCPT_WhlDrgMaxTq_Nm;/* '<S541>/MinMax1' */
extern MONPRM volatile float32 VCPT_WhlDrvMaxTq_Nm;/* '<S541>/MinMax8' */
extern MONPRM volatile boolean VDAC_ACCAvail_flg;/* '<S562>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_ACCDeltaAcceltn_mps2;/* '<S569>/Add5' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqFF_Nm;/* '<S569>/Add3' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqI_N;/* '<S569>/Saturation1' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqPID_Nm;/* '<S569>/Product6' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqP_N;/* '<S569>/Product3' */
extern MONPRM volatile boolean VDAC_ACCEnbl_flg;/* '<S562>/Logical Operator3' */
extern MONPRM volatile boolean VDAC_ACCOvrd_flg;/* '<S563>/Logical Operator22' */
extern MONPRM volatile uint8 VDAC_ACCStat_enum;/* '<S564>/Switch1' */
extern MONPRM volatile float32 VDAC_ACCTqReqWhl_Nm;/* '<S565>/Merge3' */
extern MONPRM volatile boolean VDAC_CCActv2Stby_flg;/* '<S605>/Logical Operator15' */
extern MONPRM volatile boolean VDAC_CCActvBascCond_flg;/* '<S605>/Logical Operator1' */
extern MONPRM volatile float32 VDAC_CCDeltaAcceltn_mps2;/* '<S592>/Add3' */
extern MONPRM volatile float32 VDAC_CCDsrdAcceltnRaw_mps2;/* '<S585>/Saturation1' */
extern MONPRM volatile float32 VDAC_CCDsrdAcceltn_mps2;/* '<S583>/Merge1' */
extern MONPRM volatile float32 VDAC_CCDsrdTqFF_N;/* '<S591>/Add3' */
extern MONPRM volatile float32 VDAC_CCDsrdTqI_N;/* '<S592>/Saturation1' */
extern MONPRM volatile float32 VDAC_CCDsrdTqPID_N;/* '<S592>/Add2' */
extern MONPRM volatile float32 VDAC_CCDsrdTqP_N;/* '<S592>/Product2' */
extern MONPRM volatile boolean VDAC_CCEnbl_flg;/* '<S606>/Logical Operator2' */
extern MONPRM volatile uint16 VDAC_CCNoActvCond_enum;/* '<S608>/Add' */
extern MONPRM volatile boolean VDAC_CCOvrd_flg;/* '<S579>/Logical Operator22' */
extern MONPRM volatile uint16 VDAC_CCQuitCond_enum;/* '<S609>/Add' */
extern MONPRM volatile float32 VDAC_CCSpdUnstabTm_s;/* '<S621>/Saturation' */
extern MONPRM volatile boolean VDAC_CCSpdUnstab_flg;/* '<S621>/Relational Operator8' */
extern MONPRM volatile EnumCCState VDAC_CCSt_enum;/* '<S580>/CC_State_Chart' */
extern MONPRM volatile boolean VDAC_CCStby2Actv_flg;/* '<S605>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_CCTgtSpdCtrl_kph;/* '<S630>/Switch1' */
extern MONPRM volatile uint8 VDAC_CCTgtSpdHU_kph;/* '<S581>/TgtSpdCalc' */
extern MONPRM volatile EnumCCTgtSpdSt VDAC_CCTgtSpdSt_enum;/* '<S581>/TgtSpdCalc' */
extern MONPRM volatile float32 VDAC_CCTgtSpd_kph;/* '<S581>/MinMax7' */
extern MONPRM volatile float32 VDAC_CCTqReqWhl_Nm;/* '<S584>/Merge2' */
extern MONPRM volatile float32 VDAC_CCVehSpdNonDrvn_kph;/* '<S587>/Switch' */
extern MONPRM volatile boolean VDAC_CruzCncl_flg;/* '<S646>/Chart' */
extern MONPRM volatile EnumCruiseStatus VDAC_CruzCtrlStat_enum;/* '<S579>/Switch2' */
extern MONPRM volatile boolean VDAC_CruzCtrlSwVld_flg;/* '<S582>/Signal Conversion1' */
extern MONPRM volatile boolean VDAC_CruzOn_flg;/* '<S582>/Signal Conversion2' */
extern MONPRM volatile boolean VDAC_CruzRsmActv_flg;/* '<S643>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSetActv_flg;/* '<S641>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSpdDecActv_flg;/* '<S642>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSpdIncActv_flg;/* '<S644>/Switch4' */
extern MONPRM volatile float32 VDAC_DrvAsstTqSplitEHB_Nm;/* '<S558>/MinMax2' */
extern MONPRM volatile float32 VDAC_DrvAsstTqSplitINV_Nm;/* '<S558>/Add1' */
extern MONPRM volatile uint8 VDAC_DrvAsstTqSts_enum;/* '<S558>/Switch1' */
extern MONPRM volatile float32 VDAC_DrvAsstTqTgt_Nm;/* '<S558>/Switch2' */
extern MONPRM volatile boolean VDAC_EnblEHBBrkRun_flg;/* '<S677>/Switch4' */
extern MONPRM volatile boolean VDAC_HDCActv2Idle_flg;/* '<S653>/Logical Operator11' */
extern MONPRM volatile boolean VDAC_HDCActv2Stdby_flg;/* '<S653>/Logical Operator8' */
extern MONPRM volatile float32 VDAC_HDCDeltaAcceltn_mps2;/* '<S658>/Add5' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqFF_Nm;/* '<S658>/Add3' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqI_N;/* '<S658>/Saturation1' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqPID_Nm;/* '<S658>/Product6' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqP_N;/* '<S658>/Product3' */
extern MONPRM volatile boolean VDAC_HDCIdle2Stdby_flg;/* '<S653>/Logical Operator2' */
extern MONPRM volatile EnumHDCState VDAC_HDCSt_enum;/* '<S556>/HDC_State_Chart' */
extern MONPRM volatile boolean VDAC_HDCStdby2Actv_flg;/* '<S653>/Logical Operator13' */
extern MONPRM volatile boolean VDAC_HDCStdby2Idle_flg;/* '<S653>/Logical Operator3' */
extern MONPRM volatile float32 VDAC_HDCTgtAcceltn_mps2;/* '<S650>/Merge1' */
extern MONPRM volatile float32 VDAC_HDCTgtSpd_kph;/* '<S556>/HDC_State_Chart' */
extern MONPRM volatile float32 VDAC_HDCTqReqWhl_Nm;/* '<S650>/Merge2' */
extern MONPRM volatile uint8 VDAC_HDCVehSpdHU_kph;/* '<S651>/Switch1' */
extern MONPRM volatile float32 VDAC_MstrCylPresrReq_bar;/* '<S558>/Switch13' */
extern MONPRM volatile uint8 VDAC_VehSpdHU_kph;/* '<S632>/Switch1' */
extern MONPRM volatile uint8 VDAC_VirtAccPedPstnSta_enum;/* '<S558>/Switch11' */
extern MONPRM volatile float32 VDAC_VirtAccPedPstn_pct;/* '<S558>/Switch8' */
extern MONPRM volatile float32 VDAC_VirtAccelPedPstnRaw_pct;/* '<S558>/Switch9' */
extern MONPRM volatile float32 VDAC_VirtPedPstn_pct;/* '<S558>/Switch4' */
extern MONPRM volatile uint8 VDAG_ACCMHVILFltSt_enum;/* '<S1431>/FltStDeb' */

/* ѹ������ѹ��������״̬ */
extern MONPRM volatile uint8 VDAG_ACChrgStFailFltSt_enum;/* '<S1264>/FltStDeb' */

/* ACChargeStateFail����״̬ */
extern MONPRM volatile uint8 VDAG_ACDchaBMSPwrLoFltSt_enum;/* '<S1270>/FltStDeb' */

/* AC�ŵ�BMS���ʵ͹���״̬ */
extern MONPRM volatile uint8 VDAG_ACDchaBMSSOCLoFltSt_enum;/* '<S1269>/FltStDeb' */

/* AC�ŵ�BMSSOC�͹���״̬ */
extern MONPRM volatile uint8 VDAG_ACDchaOverPwrFltSt_enum;/* '<S1263>/FltStDeb' */

/* AC�ŵ繦�ʳ��޹��� */
extern MONPRM volatile uint8 VDAG_ACSCmdTmOutFltSt_enum;/* '<S996>/FltStDeb' */

/* ACSCmd��ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_AccPed1ShtBattFltSt_enum;/* '<S1405>/FltStDeb' */

/* ����̤��1·�̵�Դ����״̬ */
extern MONPRM volatile uint8 VDAG_AccPed1ShtGndFltSt_enum;/* '<S1402>/FltStDeb' */

/* ����̤��1·�̵ع���״̬ */
extern MONPRM volatile uint8 VDAG_AccPed1SuplyShtCircFltSt_enum;/* '<S1403>/FltStDeb' */

/* ����̤��1·�����·����״̬ */
extern MONPRM volatile uint8 VDAG_AccPed2ShtBattFltSt_enum;/* '<S1398>/FltStDeb' */

/* ����̤��2·�̵�Դ����״̬ */
extern MONPRM volatile uint8 VDAG_AccPed2ShtGndFltSt_enum;/* '<S1406>/FltStDeb' */

/* ����̤��2·�̵ع���״̬ */
extern MONPRM volatile uint8 VDAG_AccPed2SuplyShtCircFltSt_enum;/* '<S1404>/FltStDeb' */

/* ����̤��2·�����·����״̬ */
extern MONPRM volatile uint8 VDAG_AccPedBothFailFltSt_enum;/* '<S1400>/FltStDeb' */

/* ����̤��˫·ʧЧ����״̬ */
extern MONPRM volatile uint8 VDAG_AccPedCrsChkFltSt_enum;/* '<S1399>/FltStDeb' */

/* ����̤���໥У�����״̬ */
extern MONPRM volatile uint8 VDAG_BMSCmdTmOutFltSt_enum;/* '<S990>/FltStDeb' */

/* BMS�̵���ָ����Ӧ��ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_BMSEmgcySdnFltSt_enum;/* '<S1001>/FltStDeb' */

/* BMS�����µ����״̬ */
extern MONPRM volatile uint8 VDAG_BMSSOCLoFltSt_enum;/* '<S1000>/FltStDeb' */

/* BMSSOC�͹���״̬ */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl1FltSt_enum;/* '<S997>/FltStDeb' */

/* BMSFailLevel1����״̬ */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl2FltSt_enum;/* '<S998>/FltStDeb' */

/* BMSFailLevel2����״̬ */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl3FltSt_enum;/* '<S999>/FltStDeb' */

/* BMSFailLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_BMSUndrVoltFltSt_enum;/* '<S1002>/FltStDeb' */

/* BMSPackǷѹ����״̬ */
extern MONPRM volatile uint8 VDAG_BrkPedShtBattFltSt_enum;/* '<S1428>/FltStDeb' */

/* �ƶ�̤��̵�Դ����״̬ */
extern MONPRM volatile uint8 VDAG_BrkPedShtGndFltSt_enum;/* '<S1426>/FltStDeb' */

/* �ƶ�̤��̵ع���״̬ */
extern MONPRM volatile uint8 VDAG_BrkSwCrsChkCnt_cnt;/* '<S1418>/Data Type Conversion' */

/* �ƶ������໥У�������� */
extern MONPRM volatile uint8 VDAG_BrkSwCrsChkFltSt_enum;/* '<S1427>/FltStDeb' */

/* �ƶ������໥У�����״̬ */
extern MONPRM volatile uint8 VDAG_CellUndrVoltFltSt_enum;/* '<S1003>/FltStDeb' */

/* BMSCellǷѹ����״̬ */
extern MONPRM volatile uint8 VDAG_DCCCmdTmOutFltSt_enum;/* '<S1164>/FltStDeb' */

/* DCDCģʽָ����Ӧ��ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_DCCInVoltLoFltSt_enum;/* '<S1165>/FltStDeb' */

/* DCDC�����ѹ�͹���״̬ */
extern MONPRM volatile uint8 VDAG_DCCModeFltFltSt_enum;/* '<S1163>/FltStDeb' */

/* DCDCModeFault����״̬ */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl1FltSt_enum;/* '<S1159>/FltStDeb' */

/* DCDCFailLevel1����״̬ */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl2FltSt_enum;/* '<S1160>/FltStDeb' */

/* DCDCFailLevel2����״̬ */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl3FltSt_enum;/* '<S1161>/FltStDeb' */

/* DCDCFailLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl4FltSt_enum;/* '<S1162>/FltStDeb' */

/* DCDCFailLevel4����״̬ */
extern MONPRM volatile uint8 VDAG_DCSChrgReqFltSt_enum;/* '<S994>/FltStDeb' */

/* DCSChargeRequest����״̬ */
extern MONPRM volatile uint8 VDAG_DCSCmdTmOutFltSt_enum;/* '<S1004>/FltStDeb' */

/* DCSCmd��ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_DCSFailStaFltSt_enum;/* '<S992>/FltStDeb' */

/* DCSFailState����״̬ */
extern MONPRM volatile uint8 VDAG_DCSInletConnectFltSt_enum;/* '<S993>/FltStDeb' */

/* DCS��ǹ����״̬ */
extern MONPRM volatile uint8 VDAG_DCSModeFailFltSt_enum;/* '<S995>/FltStDeb' */

/* DCSModeFail����״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl1FltSt_enum;/* '<S1336>/FltStDeb' */

/* EHB1������״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl2FltSt_enum;/* '<S1337>/FltStDeb' */

/* EHB2������״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl3FltSt_enum;/* '<S1338>/FltStDeb' */

/* EHB3������״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl4FltSt_enum;/* '<S1330>/FltStDeb' */

/* EHB4������״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl5FltSt_enum;/* '<S1339>/FltStDeb' */

/* EHB5������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl1FltSt_enum;/* '<S1341>/FltStDeb' */

/* ESC1������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl2FltSt_enum;/* '<S1331>/FltStDeb' */

/* ESC2������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl3FltSt_enum;/* '<S1332>/FltStDeb' */

/* ESC3������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl4FltSt_enum;/* '<S1340>/FltStDeb' */

/* ESC4������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl5FltSt_enum;/* '<S1333>/FltStDeb' */

/* ESC5������״̬ */
extern MONPRM volatile uint8 VDAG_ESCVehSpdInvldFltSt_enum;/* '<S1335>/FltStDeb' */

/* ����ʧЧ����״̬ */
extern MONPRM volatile boolean VDAG_EmgcyShtdwn_flg;/* '<S954>/Switch30' */
extern MONPRM volatile uint16 VDAG_ErrCode_enum;/* '<S952>/Err_State' */
extern MONPRM volatile boolean VDAG_FanFullSpdOn_flg;/* '<S954>/Switch3' */
extern MONPRM volatile boolean VDAG_FbdACC_flg;/* '<S954>/Switch28' */
extern MONPRM volatile boolean VDAG_FbdACChrg_flg;/* '<S954>/Switch32' */
extern MONPRM volatile boolean VDAG_FbdACDcha_flg;/* '<S954>/Switch34' */
extern MONPRM volatile boolean VDAG_FbdAC_flg;/* '<S954>/Switch35' */
extern MONPRM volatile boolean VDAG_FbdCC_flg;/* '<S954>/Switch26' */
extern MONPRM volatile boolean VDAG_FbdDCChrg_flg;/* '<S954>/Switch33' */
extern MONPRM volatile boolean VDAG_FbdDCDC_flg;/* '<S954>/Switch31' */
extern MONPRM volatile boolean VDAG_FbdDRGr_flg;/* '<S954>/Switch25' */
extern MONPRM volatile boolean VDAG_FbdDrvTq_flg;/* '<S954>/Switch23' */
extern MONPRM volatile boolean VDAG_FbdHV_flg;/* '<S954>/Switch29' */
extern MONPRM volatile boolean VDAG_FbdLSP_flg;/* '<S954>/Switch27' */
extern MONPRM volatile boolean VDAG_FltLampOn_flg;/* '<S954>/Switch36' */
extern MONPRM volatile uint8 VDAG_FltLvl_enum;/* '<S954>/MinMax' */
extern MONPRM volatile uint8 VDAG_FrstHVILVoltHiFltSt_enum;/* '<S1430>/FltStDeb' */

/* ��Ҫ��ѹ������ѹ�߹���״̬ */
extern MONPRM volatile uint8 VDAG_FrstHVILVoltLoFltSt_enum;/* '<S1429>/FltStDeb' */

/* ��Ҫ��ѹ������ѹ�͹���״̬ */
extern MONPRM volatile uint8 VDAG_GearShftInvldFltSt_enum;/* '<S1334>/FltStDeb' */

/* ��������ʧЧ����״̬ */
extern MONPRM volatile uint8 VDAG_HVIsoResistLoFltSt_enum;/* '<S991>/FltStDeb' */

/* ��ѹ��ؾ�Ե����״̬ */
extern MONPRM volatile uint8 VDAG_INVFltLvl1FltSt_enum;/* '<S1230>/FltStDeb' */

/* INVFaultLevel1����״̬ */
extern MONPRM volatile uint8 VDAG_INVFltLvl2FltSt_enum;/* '<S1231>/FltStDeb' */

/* INVFaultLevel2����״̬ */
extern MONPRM volatile uint8 VDAG_INVFltLvl3FltSt_enum;/* '<S1232>/FltStDeb' */

/* INVFaultLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_INVFltLvl4FltSt_enum;/* '<S1233>/FltStDeb' */

/* INVFaultLevel4����״̬ */
extern MONPRM volatile uint8 VDAG_INVInVoltLoFltSt_enum;/* '<S1166>/FltStDeb' */

/* INV�����ѹ�͹���״̬ */
extern MONPRM volatile uint8 VDAG_INVRunCmdRespFltSt_enum;/* '<S1234>/FltStDeb' */

/* INVRunָ����Ӧ��ʱ����״̬ */
extern MONPRM volatile boolean VDAG_LVBatLampOn_flg;/* '<S954>/Switch1' */
extern MONPRM volatile uint8 VDAG_LVBattSOCLoFltSt_enum;/* '<S1378>/FltStDeb' */

/* ����SOC�͵Ĺ���״̬ */
extern MONPRM volatile uint8 VDAG_LVBattSOHLoFltSt_enum;/* '<S1374>/FltStDeb' */

/* ����SOH�͵Ĺ���״̬ */
extern MONPRM volatile uint8 VDAG_LVBattTempHiFltSt_enum;/* '<S1375>/FltStDeb' */

/* ���ع��¹���״̬ */
extern MONPRM volatile uint8 VDAG_LVBattVoltHiFltSt_enum;/* '<S1377>/FltStDeb' */

/* ���ص�ѹ�߹���״̬ */
extern MONPRM volatile uint8 VDAG_LVBattVoltLoFltSt_enum;/* '<S1376>/FltStDeb' */

/* ���ص�ѹ�͹���״̬ */
extern MONPRM volatile boolean VDAG_LimpHome_flg;/* '<S954>/Switch2' */
extern MONPRM volatile boolean VDAG_LmtDrvTq_flg;/* '<S954>/Switch24' */
extern MONPRM volatile uint8 VDAG_OBCChrgReqFltSt_enum;/* '<S1268>/FltStDeb' */

/* OBCChargeRequest����״̬ */
extern MONPRM volatile uint8 VDAG_OBCConnectTmOutFltSt_enum;/* '<S1266>/FltStDeb' */

/* OBC���ӳ�ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_OBCInletConnectFltSt_enum;/* '<S1271>/FltStDeb' */

/* OBC��ǹ����״̬ */
extern MONPRM volatile uint8 VDAG_OBCModeMsmtchFltSt_enum;/* '<S1265>/FltStDeb' */

/* OBCģʽ��ƥ�����״̬ */
extern MONPRM volatile uint8 VDAG_OBCS2StatFltSt_enum;/* '<S1267>/FltStDeb' */

/* OBCS2���ӳ�ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl1FltSt_enum;/* '<S1272>/FltStDeb' */

/* OBCFailLevel1����״̬ */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl2FltSt_enum;/* '<S1273>/FltStDeb' */

/* OBCFailLevel2����״̬ */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl3FltSt_enum;/* '<S1274>/FltStDeb' */

/* OBCFailLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl4FltSt_enum;/* '<S1262>/FltStDeb' */

/* OBCFailLevel4����״̬ */
extern MONPRM volatile uint8 VDAG_SecdHVILVoltHiFltSt_enum;/* '<S1433>/FltStDeb' */

/* ��Ҫ��ѹ������ѹ�߹���״̬ */
extern MONPRM volatile uint8 VDAG_SecdHVILVoltLoFltSt_enum;/* '<S1432>/FltStDeb' */

/* ��Ҫ��ѹ������ѹ�͹���״̬ */
extern MONPRM volatile uint8 VDAG_SysPwrModeInvldFltSt_enum;/* '<S1328>/FltStDeb' */

/* PowerModeʧЧ����״̬ */
extern MONPRM volatile uint8 VDAG_TMSFailLvl3FltSt_enum;/* '<S1329>/FltStDeb' */

/* TMSRFailLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_VehCrashFltSt_enum;/* '<S1397>/FltStDeb' */

/* ��ײ����״̬ */
extern MONPRM volatile boolean VDAG_WakeUp_flg;/* '<S1190>/Chart' */

/* Ӳ�߻��ѻ���IBSLIN���ѱ�־ */
extern MONPRM volatile uint8 VDAG_WaterTempAbvThrFltSt_enum;/* '<S1453>/FltStDeb' */

/* ��ȴˮ�¹��߹���״̬ */
extern MONPRM volatile uint8 VDAG_WaterTempBlwThrFltSt_enum;/* '<S1452>/FltStDeb' */

/* ��ȴˮ�¹��͹���״̬ */
extern MONPRM volatile float32 VDSA_AcceltnIdxAvg_pct;/* '<S63>/AvgAcceltnIdx' */
extern MONPRM volatile float32 VDSA_AcceltnIdxRaw_pct;/* '<S63>/Saturation1' */
extern MONPRM volatile float32 VDSA_BrkPedPstnAvg_pct;/* '<S63>/AvgBrkPedPstn' */
extern MONPRM volatile float32 VDSA_DrvSprtIdx_pct;/* '<S63>/Saturation2' */
extern MONPRM volatile boolean VDSA_SprtIdxHldAcc_flg;/* '<S63>/Logical Operator3' */
extern MONPRM volatile boolean VDSA_SprtIdxHldBrk_flg;/* '<S63>/Logical Operator6' */
extern MONPRM volatile float32 VDSA_TqCalcAcceltn_mps2;/* '<S63>/Divide1' */
extern MONPRM volatile boolean VEMS_ACCMOprtCmd_flg;/* '<S893>/ACCMEnble' */

/* ʹ��ACCM */
extern MONPRM volatile float32 VEMS_AccPwrRaw_kW;/* '<S894>/MinMax4' */
extern MONPRM volatile float32 VEMS_CellTempSyn_C;/* '<S948>/Switch1' */
extern MONPRM volatile float32 VEMS_CellUndrVoltDrtFac_c;/* '<S891>/Saturation3' */
extern MONPRM volatile float32 VEMS_ChrgCurFbKi_A;/* '<S945>/Saturation' */
extern MONPRM volatile float32 VEMS_ChrgCurFbKp_A;/* '<S945>/Product2' */
extern MONPRM volatile float32 VEMS_ChrgCurFb_A;/* '<S945>/Saturation2' */
extern MONPRM volatile float32 VEMS_ChrgOvrshtPwr_kW;/* '<S890>/Add1' */
extern MONPRM volatile float32 VEMS_ChrgPwrFbKi_kW;/* '<S909>/Saturation' */
extern MONPRM volatile float32 VEMS_ChrgPwrFbKp_kW;/* '<S909>/Product2' */
extern MONPRM volatile float32 VEMS_ChrgPwrFb_kW;/* '<S890>/Merge' */
extern MONPRM volatile float32 VEMS_DchaCurFbKi_A;/* '<S946>/Saturation' */
extern MONPRM volatile float32 VEMS_DchaCurFbKp_A;/* '<S946>/Product2' */
extern MONPRM volatile float32 VEMS_DchaCurFb_A;/* '<S946>/Saturation2' */
extern MONPRM volatile float32 VEMS_DchaOvrshtPwr_kW;/* '<S892>/Add1' */
extern MONPRM volatile float32 VEMS_DchaPwrFbKi_kW;/* '<S927>/Saturation' */
extern MONPRM volatile float32 VEMS_DchaPwrFbKp_kW;/* '<S927>/Product2' */
extern MONPRM volatile float32 VEMS_DchaPwrFb_kW;/* '<S892>/Merge' */
extern MONPRM volatile float32 VEMS_HVBatPwrAct_kW;/* '<S894>/Gain1' */
extern MONPRM volatile float32 VEMS_MaxChrgCur_A;/* '<S889>/Saturation4' */
extern MONPRM volatile float32 VEMS_MaxChrgPwr2MotRaw_kW;/* '<S889>/Add7' */
extern MONPRM volatile float32 VEMS_MaxChrgPwr2Mot_kW;/* '<S890>/MinMax2' */
extern MONPRM volatile float32 VEMS_MaxChrgPwr_kW;/* '<S889>/Product2' */
extern MONPRM volatile float32 VEMS_MaxConChrgCur_A;/* '<S889>/MinMax1' */
extern MONPRM volatile float32 VEMS_MaxConDchaCur_A;/* '<S891>/MinMax1' */
extern MONPRM volatile float32 VEMS_MaxDchaCur_A;/* '<S891>/Saturation4' */
extern MONPRM volatile float32 VEMS_MaxDchaPwr2MotRaw_kW;/* '<S891>/Add7' */
extern MONPRM volatile float32 VEMS_MaxDchaPwr2Mot_kW;/* '<S892>/MinMax2' */
extern MONPRM volatile float32 VEMS_MaxDchaPwr_kW;/* '<S891>/Product2' */
extern MONPRM volatile float32 VEMS_MaxInsChrgCur_A;/* '<S889>/MinMax3' */
extern MONPRM volatile float32 VEMS_MaxInsDchaCur_A;/* '<S891>/MinMax3' */
extern MONPRM volatile boolean VEMS_TMSActSOCEnbl_flg;/* '<S942>/Switch1' */

/* SOC�Ƿ�����TMS */
extern MONPRM volatile boolean VEMS_TMSPwrEnbl_flg;/* '<S893>/Switch3' */

/* �����Ƿ�����TMS */
extern MONPRM volatile float32 VEMS_TMSUsePwr_kW;/* '<S893>/Subtract' */

/* TMS���ù��� */
extern MONPRM volatile boolean VEMS_UseConChrgCur_flg;/* '<S900>/Switch4' */
extern MONPRM volatile boolean VEMS_UseConDchaCur_flg;/* '<S918>/Switch4' */
extern MONPRM volatile boolean VGSM_AsstDrvFbShft_flg;/* '<S1660>/Logical Operator2' */

/* �淶��ACC/CC��ֹ��λ���� */
extern MONPRM volatile boolean VGSM_AsstDrvReqEPB_flg;/* '<S1646>/Switch4' */

/* ACCͨѶ��ʧ���������EPB */
extern MONPRM volatile boolean VGSM_DRFlt2N_flg;/* '<S1659>/Switch1' */

/* �淶����������������־λ */
extern MONPRM volatile boolean VGSM_EPBAplyFlt_flg;/* '<S1636>/EPBLogical' */

/* ����P-EPB������� */
extern MONPRM volatile boolean VGSM_EPBRelsFlt_flg;/* '<S1636>/EPBLogical' */

/* ����P-EPB�ͷŹ��� */
extern MONPRM volatile boolean VGSM_GrD2PExcdTm_flg;/* '<S1813>/Chart' */

/* D����P����ʱ��N */
extern MONPRM volatile boolean VGSM_GrNReq2P_flg;/* '<S1659>/Switch2' */

/* N���ǻ��������P������ */
extern MONPRM volatile boolean VGSM_GrR2PExcdTm_flg;/* '<S1810>/Chart' */

/* R����P����ʱ��N */
extern MONPRM volatile boolean VGSM_HldGearP_flg;/* '<S1659>/Switch' */

/* �淶������P����־λ */
extern MONPRM volatile boolean VGSM_INVRunEnbl_flg;/* '<S1662>/Chart' */

/* �淶��INVʹ�ܿ��ƣ�����Ť�ؿ��ƣ�-VCU_1_EnaInvRun */
extern MONPRM volatile uint8 VGSM_PGrSwSts_enum;/* '<S1660>/Switch2' */

/* �淶��P����������־λ-VCU_PGearSwcst */
extern MONPRM volatile boolean VGSM_ReqEPBAply_flg;/* '<S1661>/Logical Operator6' */

/* �淶��EPB���������־λ */
extern MONPRM volatile boolean VGSM_ReqEPBRels_flg;/* '<S1661>/Logical Operator4' */

/* �淶��EPB�ͷ������־λ */
extern MONPRM volatile EnumEPBReq VGSM_ReqEPB_enum;/* '<S1636>/Switch' */

/* �淶��EPB�����ź�-VCUF_ReqEPB */
extern MONPRM volatile EnumTgtGearPstn VGSM_ShftTgtGrReq_enum;/* '<S1660>/Data Type Conversion1' */

/* ������Ŀ�굵λ 0-NoCmd 1-P 2-N 3-D 4-R  */
extern MONPRM volatile EnumGearPstn VGSM_VehActGearPstn_enum;/* '<S1637>/Switch1' */

/* �淶��ʵ�ʵ�λ-VCU_VhclActlGearPos */
extern MONPRM volatile boolean VGSM_VehEPBStErr_flg;/* '<S1636>/Logical Operator' */

/* �淶��P������PGear error-VCU_VhclPGearError */
extern MONPRM volatile EnumTgtGearPstn VGSM_VehTgtGrReq_enum;/* '<S1661>/Data Type Conversion1' */

/* �淶:Ŀ�굵λ */
extern MONPRM volatile uint8 VGSM_VehTgtGrTrnsfr_enum;/* '<S1699>/Switch' */

/* �淶�����������ź� */
extern MONPRM volatile uint8 VHMI_12VBatLowVolSta_enum;/* '<S72>/Switch' */
extern MONPRM volatile float32 VHMI_GrDSldDist_m;/* '<S86>/Saturation' */

/* D��������� */
extern MONPRM volatile boolean VHMI_GrDSldSw_flg;/* '<S86>/Logical Operator' */

/* D�����¼���/�����־ */
extern MONPRM volatile float32 VHMI_GrRSldDist_m;/* '<S86>/Saturation1' */

/* R��ǰ����� */
extern MONPRM volatile boolean VHMI_GrRSldSw_flg;/* '<S86>/Logical Operator4' */

/* R�����¼���/�����־ */
extern MONPRM volatile uint8 VHMI_InfoDisp_enum;/* '<S75>/Arbitration' */

/* �Ǳ���ֵ */
extern MONPRM volatile boolean VHVM_ACChrgEnbl_flg;/* '<S1530>/Logical Operator8' */

/* ������������������ */
extern MONPRM volatile uint8 VHVM_ACChrgMaxCurrFb_A;/* '<S1501>/Switch4' */

/* HU���õ������� */
extern MONPRM volatile uint8 VHVM_ACChrgModeFb_enum;/* '<S1501>/Switch7' */

/* HU���ó��ģʽ���� */
extern MONPRM volatile boolean VHVM_ACChrging2Stop_flg;/* '<S1524>/AND' */

/* ���������ת�Ƶ����ֹͣ��־λ */
extern MONPRM volatile boolean VHVM_ACDchaEnbl_flg;/* '<S1530>/Logical Operator10' */

/* �����ŵ������������ */
extern MONPRM volatile boolean VHVM_ACDschrging2Stop_flg;/* '<S1524>/AND7' */

/* �����ŵ���ת�Ƶ��ŵ�ֹͣ��־λ */
extern MONPRM volatile EnumBMSSdnCmd VHVM_BMSShutdown_enum;/* '<S1500>/Data Type Conversion10' */

/* VCU�ر�BMSָ���ӦCAN�źţ�VCU_BMS_Shutdown */
extern MONPRM volatile EnumBMSWakeUpMd VHVM_BMSWakeUpMode_enum;/* '<S1500>/Data Type Conversion8' */

/* VCU����BMS�ķ�ʽ��ӦCAN�źţ�VCU_BMS_WakeupMode */
extern MONPRM volatile boolean VHVM_Bat2DrvTrainEnbl_flg;/* '<S1500>/MainState' */

/* VCU�������̵���ָ���ӦCAN�źţ�VCU_Bat2DrvTrainEnb */
extern MONPRM volatile EnumChrgAllwCmd VHVM_ChrgAllowCmd_enum;/* '<S1500>/Data Type Conversion12' */

/* VCU����������ָ���ӦCAN�źţ�VCU_ChrgAllowCmd */
extern MONPRM volatile uint8 VHVM_ChrgEnaAC_enum;/* '<S1500>/MainState' */

/* VCU����OBC�������ʹ��ָ���ӦCAN�źţ�VCU_ChrgEna_AC */
extern MONPRM volatile boolean VHVM_ChrgEnaDC_flg;/* '<S1500>/MainState' */

/* VCU����BMSֱ�����ʹ��ָ���ӦCAN�źţ�VCU_ChrgEna_DC */
extern MONPRM volatile float32 VHVM_DCCBuckLVVolt_V;/* '<S1500>/MainState' */

/* VCU����DCDC BUCK��ѹֵ��ӦCAN�źţ�VCU_DCCBuckLV_Vol */
extern MONPRM volatile EnumDCCOprtCmd VHVM_DCCOprtCmd_enum;/* '<S1500>/Data Type Conversion6' */

/* VCU����DCDC����ģʽָ���ӦCAN�źţ�VCU_DCCOprtCmd */
extern MONPRM volatile boolean VHVM_DCChrgEnbl_flg;/* '<S1530>/Logical Operator2' */

/* ֱ���������������� */
extern MONPRM volatile boolean VHVM_DCChrging2Over_flg;/* '<S1524>/AND1' */

/* ֱ�������ת�Ƶ���������־λ */
extern MONPRM volatile boolean VHVM_ECUSleepAllwd_flg;/* '<S1500>/MainState' */

/* ����ײ����߱�־λ */
extern MONPRM volatile boolean VHVM_EmgcySdn_flg;/* '<S1500>/MainState' */

/* VCU��INV���ͽ����µ�ָ��(INVǿ��ͣ��)��ӦCAN�źţ�VCU_1_EmShutDown */
extern MONPRM volatile boolean VHVM_EnaDisChg_flg;/* '<S1500>/MainState' */

/* VCU����INVй��ָ���ӦCAN�źţ�VCU_1_EnaDisChg */
extern MONPRM volatile boolean VHVM_EngyExtrmLo_flg;/* '<S1503>/Logical Operator17' */

/* ����������ͱ�־λ */
extern MONPRM volatile boolean VHVM_INVEnbl_flg;/* '<S1500>/MainState' */

/* VCUӲ�߻���INV */
extern MONPRM volatile boolean VHVM_INVPreprogmFlg_flg;/* '<S1525>/Switch1' */

/* INVԤ����������� */
extern MONPRM volatile float32 VHVM_MaxChrgCurntDC_A;/* '<S1500>/MainState' */

/* VCU����BMSֱ�������������ӦCAN�źţ�VCU_MaxChrgCrnt_DC */
extern MONPRM volatile float32 VHVM_MaxChrgVoltDC_V;/* '<S1500>/MainState' */

/* VCU����BMSֱ���������ѹ��ӦCAN�źţ�VCU_MaxChrgVol_DC */
extern MONPRM volatile float32 VHVM_MaxHVDCCurntAC_A;/* '<S1500>/MainState' */

/* VCU����OBC���������������ӦCAN�źţ�VCU_MaxHVDC_Cur_AC */
extern MONPRM volatile float32 VHVM_MaxHVDCVoltAC_V;/* '<S1500>/MainState' */

/* VCU����OBC�����������ѹ��ӦCAN�źţ�VCU_MaxHVDC_Vol_AC */
extern MONPRM volatile EnumOBCOprtCmd VHVM_OBCOprtCmd_enum;/* '<S1501>/Data Type Conversion4' */

/* VCU����OBC����ģʽָ���ӦCAN�źţ�VCU_OBCOprtCmd */
extern MONPRM volatile EnumPTActMd VHVM_PTActOprtMode_enum;/* '<S1500>/Data Type Conversion4' */

/* ��ѹPT״̬ */
extern MONPRM volatile boolean VHVM_PTRdy2PTStdby_flg;/* '<S1527>/Switch1' */

/* PTRdy��PTStdby��־λ */
extern MONPRM volatile boolean VHVM_PTStdby2PTRdy_flg;/* '<S1527>/Switch' */

/* PTStdby��PTRdy��־λ */
extern MONPRM volatile boolean VHVM_PowUpSelfChek_flg;/* '<S1528>/Switch' */

/* ��ѹ�Լ��־λ */
extern MONPRM volatile boolean VHVM_PwrOn2PwrDwn_flg;/* '<S1529>/Switch' */

/* ��ѹ�µ����������־λ������/����/������ */
extern MONPRM volatile boolean VHVM_SOPExtrmLo_flg;/* '<S1503>/Relational Operator4' */

/* ���SOP���ͣ����ڹر�DCDC */
extern MONPRM volatile EnumSysSta VHVM_SysSta_enum;/* '<S1500>/Data Type Conversion2' */

/* ��ѹ��״̬ */
extern MONPRM volatile uint8 VHVM_TBOX2OBC_emun;/* '<S1501>/Switch1' */

/* TBOXԶ�̳�ŵ�ָ�� */
extern MONPRM volatile EnumVCUMode VHVM_VCUMode_enum;/* '<S1500>/Data Type Conversion' */

/* ��ѹ��ת̬ */
extern MONPRM volatile boolean VHVM_VehHalt_flg;/* '<S1519>/Switch4' */

/* ����ֹͣ��־λ�����ټ��䣩 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpACChrg_flg;/* '<S1530>/Logical Operator16' */

/* ������绽���ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpACDcha_flg;/* '<S1530>/Logical Operator26' */

/* �����ŵ绽���ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpDCChrg_flg;/* '<S1530>/Logical Operator4' */

/* ֱ����绽���ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpIBS_flg;/* '<S1530>/Logical Operator6' */

/* IBS�����ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpKL15_flg;/* '<S1530>/Logical Operator' */

/* K15�����ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUp_flg;/* '<S1530>/Switch' */

/* ���ѵ��ϸ�ѹ�������㣨����Դ������+��ѹ�Լ�ͨ���� */
extern MONPRM volatile boolean VHVM_WakeUpBMS_flg;/* '<S1500>/MainState' */

/* VCUӲ�߻���BMS */
extern MONPRM volatile boolean VHVM_WakeUpVCU_flg;/* '<S1531>/Switch' */

/* ���ߵ������������� */
extern MONPRM volatile boolean VIBS_BMSBatSOCAllow_flg;/* '<S250>/Switch3' */

/* �������SOC�������־λ_versteckt */
extern MONPRM volatile boolean VIBS_ChgNumAllow_flg;/* '<S250>/AND' */

/* ������������־λ_versteckt */
extern MONPRM volatile uint8 VIBS_ChgNum_cnt;/* '<S250>/Switch2' */

/* IBS�������_versteckt */
extern MONPRM volatile boolean VIBS_ChrgBascCond_flg;/* '<S250>/Logical Operator2' */

/* ��������������㣨�����������ѹ��_versteckt */
extern MONPRM volatile boolean VIBS_ChrgEnbl_flg;/* '<S250>/Logical Operator7' */

/* IBS���ʹ�ܱ�־λ_versteckt */
extern MONPRM volatile boolean VIBS_ChrgOver_flg;/* '<S248>/ChrgSt' */

/* IBS���������־λ_versteckt */
extern MONPRM volatile float32 VIBS_ChrgVoltThr_V;/* '<S251>/VoltState' */

/* �����ѹ��ֵ_versteckt */
extern MONPRM volatile float32 VIBS_EnvirTemp_C;/* '<S273>/Switch' */

/* IBS�����¶�_versteckt */
extern MONPRM volatile uint8 VIBS_FailChgNum_cnt;/* '<S250>/Switch5' */

/* IBS����ʧ�ܴ���_versteckt */
extern MONPRM volatile boolean VIBS_FbRctWup_flg;/* '<S250>/Logical Operator6' */

/* IBS��ֹRTC���ѱ�־λ_versteckt */
extern MONPRM volatile boolean VIBS_HVReq_flg;/* '<S250>/Switch' */

/* IBS�����ϸ�ѹ��־λ_versteckt */
extern MONPRM volatile float32 VIBS_HwKL30_V;/* '<S272>/Switch' */

/* �˲����KL30��ѹ_versteckt */
extern MONPRM volatile float32 VIBS_MustChrgVolt_V;/* '<S251>/MIBS_MustChrgVolt_V' */

/* ���׵�ѹ_versteckt */
extern MONPRM volatile boolean VIBS_MustChrg_flg;/* '<S281>/Chart' */

/* ���׵�ѹ�����־λ_versteckt */
extern MONPRM volatile boolean VIBS_NMReq_flg;/* '<S257>/Switch4' */

/* IBS���������־λ_versteckt */
extern MONPRM volatile uint16 VIBS_NextRtcWupThr_min;/* '<S251>/Switch1' */

/* �´β��绽��RTC��ʱ��_versteckt */
extern MONPRM volatile EnumIBSChrgSt VIBS_RTCChrgSt_enum;/* '<S248>/Data Type Conversion' */

/* IBS����״̬_versteckt */
extern MONPRM volatile boolean VIBS_RTCWakeup_flg;/* '<S251>/Switch3' */

/* RTC���ѱ�־λ�����ӳ�ʱ�䣩_versteckt */
extern MONPRM volatile boolean VIBS_SleepAllwd_flg;/* '<S250>/SleepAllwd' */

/* IBS����ײ����߱�־λ_versteckt */
extern MONPRM volatile uint16 VIBS_WupChgTmThr_min;/* '<S251>/Switch2' */

/* IBS����ʱ����ֵ_versteckt */
extern MONPRM volatile boolean VIBS_WupVoltAllow_flg;/* '<S274>/Switch4' */

/* KL30��ѹ�����־λ_versteckt */
extern MONPRM volatile boolean VIPC_ACCCfgd_flg;/* '<S356>/Switch8' */
extern MONPRM volatile boolean VIPC_AccPed1Flt_flg;/* '<S360>/Logical Operator1' */
extern MONPRM volatile boolean VIPC_AccPed1LrnDwnActv_flg;/* '<S370>/Relational Operator' */
extern MONPRM volatile boolean VIPC_AccPed1LrnUpActv_flg;/* '<S363>/Logical Operator5' */
extern MONPRM volatile float32 VIPC_AccPed1MinPstnLrnd_pct;/* '<S363>/Switch2' */
extern MONPRM volatile float32 VIPC_AccPed1NormzAvg_pct;/* '<S369>/Switch' */
extern MONPRM volatile float32 VIPC_AccPed1NormzPstn_pct;/* '<S360>/Switch5' */
extern MONPRM volatile float32 VIPC_AccPed1SclPstn_pct;/* '<S364>/Divide1' */
extern MONPRM volatile boolean VIPC_AccPed2Flt_flg;/* '<S360>/Logical Operator2' */
extern MONPRM volatile boolean VIPC_AccPed2LrnDwnActv_flg;/* '<S374>/Relational Operator' */
extern MONPRM volatile boolean VIPC_AccPed2LrnUpActv_flg;/* '<S365>/Logical Operator5' */
extern MONPRM volatile float32 VIPC_AccPed2MinPstnLrnd_pct;/* '<S365>/Switch2' */
extern MONPRM volatile float32 VIPC_AccPed2NormzAvg_pct;/* '<S373>/Switch' */
extern MONPRM volatile float32 VIPC_AccPed2NormzPstn_pct;/* '<S360>/Switch7' */
extern MONPRM volatile float32 VIPC_AccPed2SclPstn_pct;/* '<S366>/Divide5' */
extern MONPRM volatile boolean VIPC_AccPedPstnVld_flg;/* '<S362>/Switch3' */
extern MONPRM volatile float32 VIPC_AccPedPstn_pct;/* '<S358>/MinMax3' */
extern MONPRM volatile uint8 VIPC_AccPedSnsrSta_enum;/* '<S362>/Switch3' */
extern MONPRM volatile boolean VIPC_AccPedStkActv_flg;/* '<S361>/Logical Operator6' */
extern MONPRM volatile boolean VIPC_AccPedStkBrkPrsd_flg;/* '<S388>/Switch4' */
extern MONPRM volatile float32 VIPC_AccPedStkPstn_pct;/* '<S361>/MinMax' */
extern MONPRM volatile boolean VIPC_AccPedStkStab_flg;/* '<S390>/Relational Operator' */
extern MONPRM volatile float32 VIPC_AccPedWghtAvg_pct;/* '<S387>/Switch' */
extern MONPRM volatile float32 VIPC_AccPedWghtPstn_pct;/* '<S362>/Switch3' */
extern MONPRM volatile float32 VIPC_AccPedZeroPstn_pct;/* '<S361>/Switch' */
extern MONPRM volatile boolean VIPC_BrkPedPstnVld_flg;/* '<S353>/Logical Operator8' */
extern MONPRM volatile float32 VIPC_BrkPedPstn_pct;/* '<S353>/Saturation1' */
extern MONPRM volatile boolean VIPC_BrkSwActv_flg;/* '<S353>/Logical Operator' */
extern MONPRM volatile boolean VIPC_CCSCfgd_flg;/* '<S356>/Switch1' */
extern MONPRM volatile boolean VIPC_CrpCtrlCfgd_flg;/* '<S356>/Switch2' */
extern MONPRM volatile EnumCrpModeAct VIPC_CrpModeAct_enum;/* '<S355>/Switch12' */
extern MONPRM volatile EnumDrvModeAct VIPC_DrvModeAct_enum;/* '<S355>/Switch13' */
extern MONPRM volatile uint8 VIPC_DrvPwrIntnsty_pct;/* '<S355>/Switch25' */
extern MONPRM volatile boolean VIPC_DrvSw_flg;/* '<S358>/Relational Operator3' */
extern MONPRM volatile boolean VIPC_EPBAppld_flg;/* '<S354>/Logical Operator2' */
extern MONPRM volatile boolean VIPC_EPBReld_flg;/* '<S354>/Logical Operator1' */
extern MONPRM volatile boolean VIPC_HDCCfgd_flg;/* '<S356>/Switch3' */
extern MONPRM volatile EnumRegenModeAct VIPC_RegenModeAct_enum;/* '<S355>/Switch15' */
extern MONPRM volatile uint8 VIPC_RegenPwrIntnsty_pct;/* '<S355>/Switch28' */
extern MONPRM volatile boolean VIPC_SnowMode_flg;/* '<S355>/Switch14' */
extern MONPRM volatile float32 VIPC_TireRadius_m;/* '<S356>/TireSizeTable' */
extern MONPRM volatile uint8 VIPC_VehHiddenMode_enum;/* '<S355>/VehHiddenMode' */
extern MONPRM volatile float32 VIPC_VehSpdDrvnMotor_kph;/* '<S357>/Product1' */
extern MONPRM volatile boolean VIPC_VehSpdDrvnVld_flg;/* '<S424>/Logical Operator2' */
extern MONPRM volatile float32 VIPC_VehSpdDrvn_kph;/* '<S424>/Switch7' */
extern MONPRM volatile boolean VIPC_VehSpdNonDrvnVld_flg;/* '<S425>/Logical Operator2' */
extern MONPRM volatile float32 VIPC_VehSpdNonDrvn_kph;/* '<S425>/Switch7' */
extern MONPRM volatile boolean VIPC_VehSpdVld_flg;/* '<S424>/SignalConversion' */
extern MONPRM volatile float32 VIPC_VehSpd_kph;/* '<S424>/Switch4' */
extern MONPRM volatile boolean VIPC_VpedAutoCrp_flg;/* '<S412>/Switch4' */
extern MONPRM volatile boolean VIPC_ZeroPstnRst_flg;/* '<S361>/Logical Operator3' */
extern MONPRM volatile boolean VIPC_iTPMSCfgd_flg;/* '<S356>/Switch4' */
extern MONPRM volatile float32 VIPM_HwAccPedCh1SuplyVolt_mV;/* '<S10>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh1Volt_mV;/* '<S11>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh2SuplyVolt_mV;/* '<S12>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh2Volt_mV;/* '<S13>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwBMSWakeup_flg;/* '<S14>/Switch4' */
extern MONPRM volatile boolean VIPM_HwBrkSwHi_flg;/* '<S15>/Switch4' */
extern MONPRM volatile boolean VIPM_HwBrkSwLo_flg;/* '<S16>/Switch4' */
extern MONPRM volatile boolean VIPM_HwCrpModeSw_flg;/* '<S17>/Switch4' */
extern MONPRM volatile boolean VIPM_HwDrvModeSw_flg;/* '<S18>/Switch4' */
extern MONPRM volatile boolean VIPM_HwEmgcyShutOff_flg;/* '<S19>/Switch4' */
extern MONPRM volatile float32 VIPM_HwHVIL1Volt_mV;/* '<S20>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwHVIL2Volt_mV;/* '<S21>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwKL15A_flg;/* '<S22>/Switch4' */
extern MONPRM volatile boolean VIPM_HwKL15B_flg;/* '<S23>/Switch4' */
extern MONPRM volatile uint16 VIPM_HwKL30_mV;/* '<S24>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwOBCWakeup_flg;/* '<S25>/Switch4' */
extern MONPRM volatile boolean VIPM_HwRearFogLampSwt_flg;/* '<S26>/Switch4' */
extern MONPRM volatile EnumPGearSwSts VIPM_HwShftPstnSwSts_enum;/* '<S27>/Switch4' */
extern MONPRM volatile uint16 VIPM_HwShftPstnSw_Ohm;/* '<S7>/HwShftPstnSw' */
extern MONPRM volatile boolean VIPM_HwVehCrash_flg;/* '<S28>/Switch4' */
extern MONPRM volatile uint8 VNVM_ACChrgMaxCurrFb_A;/* '<S8>/Selector18' */
extern MONPRM volatile uint8 VNVM_ACChrgModeFb_enum;/* '<S8>/Selector19' */
extern MONPRM volatile float32 VNVM_AvgPwrCnsm_kWh100km;/* '<S8>/Add2' */
extern MONPRM volatile float32 VNVM_AvgSOCCnsmWght_pctp100km;/* '<S8>/Add6' */
extern MONPRM volatile EnumCrpModeAct VNVM_CrpModeAct_enum;/* '<S8>/Data Type Conversion1' */
extern MONPRM volatile EnumDrvModeAct VNVM_DrvModeAct_enum;/* '<S8>/Data Type Conversion23' */
extern MONPRM volatile uint8 VNVM_DrvPwrIntnsty_pct;/* '<S8>/Selector6' */
extern MONPRM volatile float32 VNVM_DynRmnMilEst_km;/* '<S8>/Gain2' */
extern MONPRM volatile uint8 VNVM_EE01ReadOK_nu;/* '<S8>/Selector13' */
extern MONPRM volatile uint8 VNVM_EEImdtReadOK_nu;/* '<S8>/Selector14' */
extern MONPRM volatile uint8 VNVM_IBSChrgFailNum_cnt;/* '<S8>/Selector1' */
extern MONPRM volatile uint8 VNVM_IBSChrgNum_cnt;/* '<S8>/Selector' */
extern MONPRM volatile EnumRegenModeAct VNVM_RegenModeAct_enum;/* '<S8>/Data Type Conversion24' */
extern MONPRM volatile uint8 VNVM_RegenPwrIntnsty_pct;/* '<S8>/Selector7' */
extern MONPRM volatile boolean VNVM_TBOXOffline_flg;/* '<S8>/Data Type Conversion11' */
extern MONPRM volatile EnumTBOXLimSt VNVM_VCUSpdLimSt_enum;/* '<S8>/Data Type Conversion10' */
extern MONPRM volatile boolean VNVM_VCUVerFb_flg;/* '<S8>/Data Type Conversion12' */
extern MONPRM volatile EnumXWhlDistErrRefSt VNVM_XWhlDistErrRefStat_enum;/* '<S8>/Data Type Conversion22' */
extern MONPRM volatile float32 VNVM_XWhlDistErrRef_mpkm;/* '<S8>/Add1' */
extern MONPRM volatile boolean VNVM_iTPMSWrng_flg;/* '<S8>/Data Type Conversion21' */
extern MONPRM volatile boolean VOPM_HwWakeupBMS_flg;/* '<S42>/Switch4' */
extern MONPRM volatile float32 VRME_AvgSOCCnsm100Num_pctpkm;/* '<S231>/Signal Copy5' */

/* ǰ100������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm10Num_pctpkm;/* '<S231>/Signal Copy1' */

/* ǰ10������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm15Num_pctpkm;/* '<S231>/Signal Copy2' */

/* ǰ15������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm25Num_pctpkm;/* '<S231>/Signal Copy3' */

/* ǰ25������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm50Num_pctpkm;/* '<S231>/Signal Copy4' */

/* ǰ50������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm5Num_pctpkm;/* '<S231>/Signal Copy' */

/* ǰ5������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsmWght_pctpkm;/* '<S231>/Switch1' */

/* ��Ȩƽ��SOC�ܺ� */
extern MONPRM volatile boolean VRME_CHTCRmnMilEstV_flg;/* '<S198>/Logical Operator' */

/* CHTC��׼���������Ч�� */
extern MONPRM volatile float32 VRME_CHTCRmnMilEst_km;/* '<S198>/MRME_CHTCStdRmnMil_km' */

/* CHTC��׼�������ֵ */
extern MONPRM volatile float32 VRME_CalPwrCnsmPerTrig_kWhptrig;/* '<S202>/Switch4' */

/* Pwr����/��λ��̣�trig�� */
extern MONPRM volatile boolean VRME_CalPwrCnsmTrig_flg;/* '<S202>/Relational Operator1' */

/* �ۼ���̴��ڵ�λ��� */
extern MONPRM volatile float32 VRME_CalSOCCnsmDrvDist_m;/* '<S230>/Switch1' */

/* ��λĿ����ʻ��� */
extern MONPRM volatile float32 VRME_CalSOCCnsmPerTrig_pctptrig;/* '<S230>/Switch4' */

/* SOC����/��λ��̣�trig�� */
extern MONPRM volatile float32 VRME_CalSOCCnsmPerkm_pctpkm;/* '<S230>/Divide' */

/* SOC����/��λ��̣�1km�� */
extern MONPRM volatile boolean VRME_CalSOCCnsmTrig_flg;/* '<S230>/Relational Operator1' */

/* �ۼ���̴���Ŀ����� */
extern MONPRM volatile float32 VRME_ChrgRmnMilEstTgt_km;/* '<S211>/Saturation3' */

/* ���ģʽ��̬����Ŀ��ֵ */
extern MONPRM volatile float32 VRME_ChrgRmnMilEst_km;/* '<S211>/Different Slops' */

/* ��繤����̬����ֵ */
extern MONPRM volatile float32 VRME_ChrgTgtFstRate_kmpsoc;/* '<S211>/Divide2' */

/* ��繤��Ŀ������׷������ */
extern MONPRM volatile float32 VRME_ChrgTgtNormRate_kmpsoc;/* '<S211>/Divide1' */

/* ��繤��Ŀ�������仯���� */
extern MONPRM volatile float32 VRME_DchaRmnMilEstChgFac_c;/* '<S229>/MRME_DynEstRmnChgStp_c' */

/* �ǳ��ģʽ��̬�����仯ϵ�� */
extern MONPRM volatile float32 VRME_DchaRmnMilEstTgt_km;/* '<S238>/Switch2' */

/* �ǳ��ģʽ��̬����Ŀ��ֵ */
extern MONPRM volatile boolean VRME_DchaRmnMilEstUpdTrig_flg;/* '<S229>/Relational Operator2' */

/* ��������ֵ */
extern MONPRM volatile float32 VRME_DchaRmnMilEst_km;/* '<S229>/Signal Copy1' */

/* �ǳ��ģʽ��̬����ֵ */
extern MONPRM volatile boolean VRME_DchaVehStall_flg;/* '<S228>/Logical Operator4' */

/* �ǳ��ģʽ����פ��״̬ */
extern MONPRM volatile boolean VRME_DynRmnMilEstV_flg;/* '<S200>/Logical Operator1' */

/* ��̬������Ч�� */
extern MONPRM volatile float32 VRME_VehPwrCnsmAvg_kWhpkm;/* '<S202>/Switch7' */

/* ��ǰѭ��ƽ���ܺ� */
extern MONPRM volatile float32 VRME_VehPwrCnsmIns_kWhpkm;/* '<S202>/Divide' */

/* ��ǰѭ��˲���ܺ� */
extern MONPRM volatile float32 VRME_VehTotMilCyc_km;/* '<S202>/Gain8' */

/* ��ǰ��ʻѭ��������� */
extern MONPRM volatile float32 VRME_VehTotPwrCyc_kWh;/* '<S202>/Switch8' */

/* ��ǰ��ʻѭ���������� */
extern MONPRM volatile float32 VRME_WLTPRmnMilEstDwLim_km;/* '<S210>/Product3' */

/* ��̬��������ֵ */
extern MONPRM volatile float32 VRME_WLTPRmnMilEstUpLim_km;/* '<S210>/Product2' */

/* ��̬��������ֵ */
extern MONPRM volatile float32 VRME_WLTPRmnMilEst_km;/* '<S210>/MRME_WLTPStdRmnMil_km' */

/* WLTP��׼�������ֵ */
extern MONPRM volatile float32 VRME_WLTPStdPwrCnsm_kWhpkm;/* '<S202>/Gain5' */

/* ��׼������ģ�kWh/km�� */
extern MONPRM volatile float32 VRME_WLTPStdSOCCnsm_pctpkm;/* '<S230>/Gain3' */

/* ��׼������SOC����/km */
extern MONPRM volatile boolean VTBX_CnclSpdLim_flg;/* '<S308>/Logical Operator12' */

/* TBOX������� */
extern MONPRM volatile boolean VTBX_LckVer_flg;/* '<S328>/Chart' */

/* �����汾 */
extern MONPRM volatile boolean VTBX_RecryTBOXHw_flg;/* '<S308>/Logical Operator14' */

/* TBOXӲ��ͨѶ��ʧ�ָ� */
extern MONPRM volatile boolean VTBX_ReqLimpHome_flg;/* '<S307>/Data Type Conversion6' */

/* VCU�������ж��� */
extern MONPRM volatile boolean VTBX_RmvTBOXHw_flg;/* '<S308>/Logical Operator3' */

/* TBOXӲ��ͨѶ��ʧ */
extern MONPRM volatile boolean VTBX_SpdLimLvl1_flg;/* '<S308>/Logical Operator5' */

/* TBOXһ������ */
extern MONPRM volatile boolean VTBX_SpdLimLvl2_flg;/* '<S308>/Logical Operator7' */

/* TBOX�������� */
extern MONPRM volatile boolean VTBX_SpdLimLvl3_flg;/* '<S308>/Logical Operator9' */

/* TBOX�������� */
extern MONPRM volatile boolean VTBX_StorgSpdLim_flg;/* '<S308>/Logical Operator11' */

/* TBOX������� */
extern MONPRM volatile boolean VTBX_TBOXOffline_flg;/* '<S307>/Signal Copy3' */

/* TBOXӲ��״̬-ʵʱ�洢 */
extern MONPRM volatile boolean VTBX_UnlckVer_flg;/* '<S327>/Chart' */

/* �������汾 */
extern MONPRM volatile boolean VTBX_VCUChrgngCondsFb_flg;/* '<S307>/Data Type Conversion5' */

/* VCU�����жϳ������ */
extern MONPRM volatile uint8 VTBX_VCULckVehWrn_enum;/* '<S307>/Signal Copy5' */

/* VCU������������ */
extern MONPRM volatile boolean VTBX_VCUOprtLicFb_flg;/* '<S307>/Data Type Conversion4' */

/* VCU������Ӫ״̬ */
extern MONPRM volatile EnumTBOXLimGrd VTBX_VCUSpdLimLvlFb_enum;/* '<S307>/Data Type Conversion3' */

/* VCU�������ٵȼ�-��ǰ��ʻѭ�� */
extern MONPRM volatile uint8 VTBX_VCUSpdLimLvlSetFb_enum;/* '<S307>/Data Type Conversion7' */

/* VCU�������ٵȼ����óɹ� */
extern MONPRM volatile EnumTBOXLimSt VTBX_VCUSpdLimSt_enum;/* '<S307>/Data Type Conversion1' */

/* ��ǰѭ������״̬-ʵʱ�洢 */
extern MONPRM volatile boolean VTBX_VCUVerFb_flg;/* '<S307>/Signal Copy' */

/* VCU���������汾-ʵʱ�洢 */
extern MONPRM volatile uint8 VTBX_VCUVerSetFb_enum;/* '<S307>/Signal Copy1' */

/* VCU���������汾���óɹ� */
extern MONPRM volatile float32 VTQC_ABSorESPActvTm_s;/* '<S690>/MinMax' */
extern MONPRM volatile float32 VTQC_BrkRegenMaxTqWhl_Nm;/* '<S685>/Switch17' */
extern MONPRM volatile float32 VTQC_BrkRegenTgtTqWhl_Nm;/* '<S685>/Switch2' */
extern MONPRM volatile float32 VTQC_CstRegenLmtTq_Nm;/* '<S683>/CstRegenLmtTq' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhlABS_Nm;/* '<S683>/MinMax1' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhlRBS_Nm;/* '<S692>/MinMax5' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhl_Nm;/* '<S684>/Switch5' */
extern MONPRM volatile float32 VTQC_MotorTqReq_Nm;/* '<S684>/Divide' */
extern MONPRM volatile boolean VTQC_RBSActv_flg;/* '<S693>/Switch4' */
extern MONPRM volatile float32 VTQD_AccelPedPstnRescl_pct;/* '<S704>/Product' */
extern MONPRM volatile float32 VTQD_AdaptCstDeltaAcceltn_mps2;/* '<S720>/Add5' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqFF_Nm;/* '<S720>/Add2' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqI_N;/* '<S720>/Saturation2' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqPID_Nm;/* '<S720>/Product6' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqP_N;/* '<S720>/Product3' */
extern MONPRM volatile float32 VTQD_AdaptCstMaxTqWhl_Nm;/* '<S716>/MinMax4' */
extern MONPRM volatile float32 VTQD_AdaptCstMinTqWhl_Nm;/* '<S716>/MinMax5' */
extern MONPRM volatile boolean VTQD_AdaptCstRegenEnbl_flg;/* '<S716>/Logical Operator9' */
extern MONPRM volatile float32 VTQD_AdaptCstTgtAcceltn_mps2;/* '<S722>/Switch' */
extern MONPRM volatile float32 VTQD_AdaptCstTqReqWhl_Nm;/* '<S720>/MinMax6' */
extern MONPRM volatile boolean VTQD_BkwdDrv_flg;/* '<S743>/Switch4' */
extern MONPRM volatile boolean VTQD_BrkRegenEnbl_flg;/* '<S715>/Logical Operator1' */
extern MONPRM volatile float32 VTQD_CrpTqReqWhl_Nm;/* '<S706>/Switch2' */
extern MONPRM volatile boolean VTQD_CstRegenEnbl_flg;/* '<S715>/Logical Operator13' */
extern MONPRM volatile float32 VTQD_CstRegenEndPstn_pct;/* '<S715>/Switch2' */
extern MONPRM volatile float32 VTQD_CstRegenTqReqWhl_Nm;/* '<S717>/Switch4' */
extern MONPRM volatile float32 VTQD_DrvTqDrtFac_c;/* '<S744>/Saturation' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhlMrg_Nm;/* '<S745>/Switch4' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhlRaw_Nm;/* '<S704>/Merge' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhl_Nm;/* '<S702>/Switch3' */
extern MONPRM volatile boolean VTQD_DsblCrp_flg;/* '<S706>/Logical Operator12' */
extern MONPRM volatile float32 VTQD_FullPedDrvTqWhl_Nm;/* '<S704>/Signal Conversion1' */
extern MONPRM volatile float32 VTQD_FwdPedMap_pct;/* '<S707>/Switch9' */
extern MONPRM volatile float32 VTQD_PedalTqReqWhlRaw_Nm;/* '<S701>/Add' */
extern MONPRM volatile uint16 VTQD_TaskRunCounter_cnt;/* '<S538>/Max1' */

/* test signal, to be deleted */
extern MONPRM volatile boolean VTQD_TqZeroFast_flg;/* '<S736>/Logical Operator4' */
extern MONPRM volatile boolean VTQD_TqZeroSlow_flg;/* '<S736>/Logical Operator2' */
extern MONPRM volatile boolean VTQD_TqZero_flg;/* '<S736>/Logical Operator1' */
extern MONPRM volatile float32 VTQF_DrvTqReqWhl_Nm;/* '<S761>/Switch2' */
extern MONPRM volatile float32 VTQF_TipOutTqDecRateCoeff_rat;/* '<S763>/1-D Lookup Table1' */
extern MONPRM volatile boolean VTQF_TqInc_flg;/* '<S773>/Switch4' */
extern MONPRM volatile float32 VTQF_TqOutChgRate_Nmps;/* '<S783>/Switch' */
extern MONPRM volatile float32 VTQF_TqRateDecTgtMax_Nmps;/* '<S763>/Switch3' */
extern MONPRM volatile float32 VTQF_TqRateDecTgtMin_Nmps;/* '<S763>/MinMax4' */
extern MONPRM volatile float32 VTQF_TqRateIncTgtMax_Nmps;/* '<S764>/Switch5' */
extern MONPRM volatile float32 VTQF_TqRateIncTgtMin_Nmps;/* '<S764>/MinMax4' */
extern MONPRM volatile float32 VTQF_TqRateLimDec_Nmps;/* '<S763>/MinMax3' */
extern MONPRM volatile boolean VTQF_TqRateLimEndg_flg;/* '<S762>/Logical Operator9' */
extern MONPRM volatile float32 VTQF_TqRateLimInc_Nmps;/* '<S764>/MinMax2' */
extern MONPRM volatile float32 VTQF_TqRawChgRate_Nmps;/* '<S782>/Switch' */
extern MONPRM volatile float32 VTQF_WhlDrgMaxTqZX_Nm;/* '<S781>/Switch1' */
extern MONPRM volatile float32 VTQF_WhlDrvMaxTqZX_Nm;/* '<S781>/Switch7' */
extern MONPRM volatile boolean VTQR_ASDEnbl_flg;/* '<S786>/Logical Operator14' */
extern MONPRM volatile float32 VTQR_ASDSpdFltHi_rpm;/* '<S794>/Switch' */
extern MONPRM volatile float32 VTQR_ASDSpdOscRaw_rpm;/* '<S790>/Add1' */
extern MONPRM volatile float32 VTQR_ASDSpdOsc_rpm;/* '<S792>/Multiport Switch' */
extern MONPRM volatile float32 VTQR_ASDTqReqRaw_Nm;/* '<S798>/MinMax5' */
extern MONPRM volatile float32 VTQR_ASDTqReq_Nm;/* '<S791>/Switch3' */
extern MONPRM volatile boolean VTQR_MotDampngEnbl_flg;/* '<S786>/Logical Operator1' */
extern MONPRM volatile float32 VTQR_MotDampngLmt_Nm;/* '<S806>/MinMax5' */
extern MONPRM volatile EnumMotorDirReq VTQR_MotorDirReq_enum;/* '<S787>/Switch4' */
extern MONPRM volatile EnumMotorModeReq VTQR_MotorModeReq_enum;/* '<S784>/Signal Conversion15' */
extern MONPRM volatile float32 VTQR_MotorSpdReq_rpm;/* '<S784>/Signal Conversion1' */
extern MONPRM volatile boolean VTQR_MotorStdby_flg;/* '<S788>/Logical Operator1' */
extern MONPRM volatile float32 VTQR_MotorTqReq_Nm;/* '<S784>/Signal Conversion2' */
extern MONPRM volatile float32 VTZX_AZDecRate_Nmps;/* '<S822>/1-D Lookup Table4' */
extern MONPRM volatile float32 VTZX_AZIncRate_Nmps;/* '<S822>/1-D Lookup Table3' */
extern MONPRM volatile float32 VTZX_BZDecRate_Nmps;/* '<S822>/1-D Lookup Table2' */
extern MONPRM volatile float32 VTZX_BZIncRate_Nmps;/* '<S822>/1-D Lookup Table1' */
extern MONPRM volatile boolean VTZX_BypZX_flg;/* '<S826>/Logical Operator1' */
extern MONPRM volatile boolean VTZX_ClkActv_flg;/* '<S825>/Switch4' */
extern MONPRM volatile float32 VTZX_ClkZXTm_s;/* '<S818>/Switch1' */
extern MONPRM volatile float32 VTZX_MotorTqReqPrdt_Nm;/* '<S838>/MinMax5' */
extern MONPRM volatile float32 VTZX_MotorTqReqZX_Nm;/* '<S823>/TqZXSt' */
extern MONPRM volatile float32 VTZX_MotorTqReq_Nm;/* '<S818>/Switch6' */
extern MONPRM volatile boolean VTZX_TqInc_flg;/* '<S832>/Switch4' */
extern MONPRM volatile boolean VTZX_TqRateLimRamp_flg;/* '<S839>/Switch4' */
extern MONPRM volatile EnumTZXStat VTZX_TqZXSt_enum;/* '<S823>/Data Type Conversion1' */
extern MONPRM volatile float32 VTZX_ZeroTqHldDec_Nm;/* '<S823>/TqZXSt' */
extern MONPRM volatile float32 VTZX_ZeroTqHldInc_Nm;/* '<S823>/TqZXSt' */
extern MONPRM volatile float32 VTZX_ZeroTqOfstDec_Nm;/* '<S822>/Switch3' */
extern MONPRM volatile float32 VTZX_ZeroTqOfstInc_Nm;/* '<S822>/Switch2' */
extern MONPRM volatile float32 VTZX_ZeroTqOfst_Nm;/* '<S822>/Switch4' */
extern MONPRM volatile float32 VTZX_ZeroXTm_s;/* '<S822>/Switch8' */
extern MONPRM volatile float32 VVSO_ALatSnsr_mps2;/* '<S442>/Switch1' */
extern MONPRM volatile float32 VVSO_ALgtSnsr_mps2;/* '<S441>/Switch1' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr1_mpkm;/* '<S503>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr2_mpkm;/* '<S503>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr3_mpkm;/* '<S503>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr4_mpkm;/* '<S503>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr5_mpkm;/* '<S503>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr_mpkm;/* '<S503>/Add3' */
extern MONPRM volatile float32 VVSO_DrvDist_m;/* '<S516>/Switch1' */
extern MONPRM volatile boolean VVSO_RSEBrkPresrConf_flg;/* '<S488>/Relational Operator2' */
extern MONPRM volatile boolean VVSO_RSESigConf_flg;/* '<S474>/Logical Operator3' */
extern MONPRM volatile boolean VVSO_RSEVehSpdConf_flg;/* '<S490>/Logical Operator2' */
extern MONPRM volatile boolean VVSO_RSEWhlSlipConf_flg;/* '<S491>/Logical Operator2' */
extern MONPRM volatile boolean VVSO_RSEYawRateConf_flg;/* '<S492>/Logical Operator' */
extern MONPRM volatile float32 VVSO_RoadSlopCalcRaw_pct;/* '<S472>/Product19' */
extern MONPRM volatile boolean VVSO_RoadSlopEstVld_flg;/* '<S471>/Logical Operator1' */
extern MONPRM volatile float32 VVSO_RoadSlopEst_pct;/* '<S471>/Switch2' */
extern MONPRM volatile float32 VVSO_RoadSlopTqEst_Nm;/* '<S487>/MinMax5' */
extern MONPRM volatile float32 VVSO_VehDrvResistTq_Nm;/* '<S473>/Switch5' */
extern MONPRM volatile boolean VVSO_VehMassConf_flg;/* '<S519>/Logical Operator4' */
extern MONPRM volatile uint8 VVSO_VehMassDistb_enum;/* '<S519>/Signal Conversion' */
extern MONPRM volatile float32 VVSO_VehMassEst_kg;/* '<S522>/Switch' */
extern MONPRM volatile float32 VVSO_VehSpd_mps;/* '<S519>/Gain3' */
extern MONPRM volatile float32 VVSO_WhlAcceltnFL_mps2;/* '<S454>/Divide' */
extern MONPRM volatile float32 VVSO_WhlAcceltnFR_mps2;/* '<S455>/Divide' */
extern MONPRM volatile float32 VVSO_WhlAcceltnRL_mps2;/* '<S456>/Divide' */
extern MONPRM volatile float32 VVSO_WhlAcceltnRR_mps2;/* '<S457>/Divide' */
extern MONPRM volatile boolean VVSO_WhlDistErrHld_flg;/* '<S507>/OR' */
extern MONPRM volatile float32 VVSO_WhlLgtFrc_N;/* '<S524>/Add' */
extern MONPRM volatile EnumXWhlDistErrRefSt VVSO_XWhlDistErrRefStat_enum;/* '<S503>/Signal Conversion2' */
extern MONPRM volatile float32 VVSO_XWhlDistErrRef_mpkm;/* '<S503>/Signal Conversion1' */
extern MONPRM volatile float32 VVSO_XWhlDistErr_m;/* '<S516>/Switch4' */
extern MONPRM volatile float32 VVSO_YawRateBas_degps;/* '<S448>/Switch' */
extern MONPRM volatile float32 VVSO_YawRateDer_radps2;/* '<S443>/Add6' */
extern MONPRM volatile float32 VVSO_YawRateFilt_radps;/* '<S447>/Switch' */
extern MONPRM volatile boolean VVSO_iTPMSAvail_flg;/* '<S507>/Logical Operator' */
extern MONPRM volatile EnumiTPMSSt VVSO_iTPMSState_enum;/* '<S503>/Signal Conversion' */
extern MONPRM volatile boolean VVSO_iTPMSWrng_flg;/* '<S503>/Signal Conversion3' */
extern MONPRM volatile boolean VVTM_BrkPedReld_flg;/* '<S864>/Logical Operator3' */
extern MONPRM volatile uint8 VVTM_DrvMotorSta_enum;/* '<S871>/DriveMotorState' */
extern MONPRM volatile boolean VVTM_ESPIntvActv_flg;/* '<S864>/Logical Operator4' */
extern MONPRM volatile float32 VVTM_MotorActPwr_kW;/* '<S878>/Switch2' */
extern MONPRM volatile float32 VVTM_MotorSpd_rpm;/* '<S866>/Switch' */
extern MONPRM volatile boolean VVTM_PCUFailSta_flg;/* '<S871>/Logical Operator2' */
extern MONPRM volatile boolean VVTM_RegenReqBrkLampOn_flg;/* '<S876>/Switch1' */
extern MONPRM volatile float32 VVTM_RsrvPwr_kW;/* '<S873>/MinMax4' */
extern MONPRM volatile float32 VVTM_RsrvRecupPwr_kW;/* '<S873>/MinMax1' */
extern MONPRM volatile float32 VVTM_VehAcceltn_mps2;/* '<S869>/Switch' */
extern MONPRM volatile uint8 VVTM_VehActGrPstn_enum;/* '<S864>/Switch1' */
extern MONPRM volatile float32 VVTM_VehSpd_kph;/* '<S865>/Switch' */

#endif                                 /* RTW_HEADER_monPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
