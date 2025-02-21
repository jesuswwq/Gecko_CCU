/*
 * File: monPrmsVcu.h
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

#ifndef RTW_HEADER_monPrmsVcu_h_
#define RTW_HEADER_monPrmsVcu_h_
#include "rtwtypes.h"
#include "AppSwcVcu_types.h"

/* Exported data declaration */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Declaration for custom storage class: Volatile */
extern MONPRM volatile boolean BSW_RTCWakeup_flg;/* '<S290>/Switch4' */

/* RTC���ѱ�־λ_versteckt */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Day;/* '<S988>/Data Type Conversion45' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Hour;/* '<S988>/Data Type Conversion1' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Min;/* '<S988>/Data Type Conversion2' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Month;/* '<S988>/Data Type Conversion34' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Sec;/* '<S988>/Switch2' */
extern MONPRM volatile uint8 UDS_TBOX_BJS_Time_Year;/* '<S988>/Data Type Conversion33' */
extern MONPRM volatile boolean VBSW_ECURst_flg;/* '<S11>/Relational Operator3' */
extern MONPRM volatile boolean VBSW_F1B1PwrOffReq_flg;/* '<S15>/Chart' */

/* F1B1�����¸�ѹ */
extern MONPRM volatile boolean VBSW_F1B1PwrOnReq_flg;/* '<S14>/Chart' */

/* F1B1�����ϸ�ѹ */
extern MONPRM volatile boolean VBSW_NetWorkWakeup_flg;/* '<S7>/Relational Operator17' */
extern MONPRM volatile uint16 VBSW_RTCWupRmningT_min;/* '<S11>/Data Type Conversion1' */

/* RTC����ʣ��ʱ�� */
extern MONPRM volatile uint8 VBSW_RoutineF1B1_enum;/* '<S7>/Selector' */

/* F1B1���̿��� */
extern MONPRM volatile boolean VBSW_SrvClrDTCReq_flg;/* '<S7>/Relational Operator4' */
extern MONPRM volatile uint8 VBSW_WakeupReasn_enum;/* '<S11>/Data Type Conversion2' */
extern MONPRM volatile float32 VCPT_MotorDrgMaxTq_Nm;/* '<S558>/MinMax6' */
extern MONPRM volatile float32 VCPT_MotorDrvMaxTq_Nm;/* '<S558>/MinMax7' */
extern MONPRM volatile float32 VCPT_MotorGenMaxTq_Nm;/* '<S570>/Switch1' */
extern MONPRM volatile float32 VCPT_MotorMotMaxTq_Nm;/* '<S569>/Switch1' */
extern MONPRM volatile boolean VCPT_MotorSpdRvrs_flg;/* '<S558>/Switch3' */
extern MONPRM volatile float32 VCPT_MotorSpd_rpm;/* '<S564>/Switch' */
extern MONPRM volatile float32 VCPT_WhlDrgMaxTq_Nm;/* '<S558>/MinMax1' */
extern MONPRM volatile float32 VCPT_WhlDrvMaxTq_Nm;/* '<S558>/MinMax8' */
extern MONPRM volatile boolean VDAC_ACCAvail_flg;/* '<S579>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_ACCDeltaAcceltn_mps2;/* '<S586>/Add5' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqFF_Nm;/* '<S586>/Add3' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqI_N;/* '<S586>/Saturation1' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqPID_Nm;/* '<S586>/Product6' */
extern MONPRM volatile float32 VDAC_ACCDsrdTqP_N;/* '<S586>/Product3' */
extern MONPRM volatile boolean VDAC_ACCEnbl_flg;/* '<S579>/Logical Operator3' */
extern MONPRM volatile boolean VDAC_ACCOvrd_flg;/* '<S580>/Logical Operator22' */
extern MONPRM volatile uint8 VDAC_ACCStat_enum;/* '<S581>/Switch1' */
extern MONPRM volatile float32 VDAC_ACCTqReqWhl_Nm;/* '<S582>/Merge3' */
extern MONPRM volatile boolean VDAC_CCActv2Stby_flg;/* '<S626>/Logical Operator15' */
extern MONPRM volatile boolean VDAC_CCActvBascCond_flg;/* '<S626>/Logical Operator1' */
extern MONPRM volatile float32 VDAC_CCDeltaAcceltn_mps2;/* '<S613>/Add3' */
extern MONPRM volatile float32 VDAC_CCDsrdAcceltnRaw_mps2;/* '<S606>/Saturation1' */
extern MONPRM volatile float32 VDAC_CCDsrdAcceltn_mps2;/* '<S604>/Merge1' */
extern MONPRM volatile float32 VDAC_CCDsrdTqFF_N;/* '<S612>/Add3' */
extern MONPRM volatile float32 VDAC_CCDsrdTqI_N;/* '<S613>/Saturation1' */
extern MONPRM volatile float32 VDAC_CCDsrdTqPID_N;/* '<S613>/Add2' */
extern MONPRM volatile float32 VDAC_CCDsrdTqP_N;/* '<S613>/Product2' */
extern MONPRM volatile boolean VDAC_CCEnbl_flg;/* '<S627>/Logical Operator2' */
extern MONPRM volatile uint16 VDAC_CCNoActvCond_enum;/* '<S629>/Add' */
extern MONPRM volatile boolean VDAC_CCOvrd_flg;/* '<S600>/Logical Operator22' */
extern MONPRM volatile uint16 VDAC_CCQuitCond_enum;/* '<S630>/Add' */
extern MONPRM volatile float32 VDAC_CCSpdUnstabTm_s;/* '<S642>/Saturation' */
extern MONPRM volatile boolean VDAC_CCSpdUnstab_flg;/* '<S642>/Relational Operator8' */
extern MONPRM volatile EnumCCState VDAC_CCSt_enum;/* '<S601>/CC_State_Chart' */
extern MONPRM volatile boolean VDAC_CCStby2Actv_flg;/* '<S626>/Logical Operator9' */
extern MONPRM volatile float32 VDAC_CCTgtSpdCtrl_kph;/* '<S651>/Switch1' */
extern MONPRM volatile uint8 VDAC_CCTgtSpdHU_kph;/* '<S602>/TgtSpdCalc' */
extern MONPRM volatile EnumCCTgtSpdSt VDAC_CCTgtSpdSt_enum;/* '<S602>/TgtSpdCalc' */
extern MONPRM volatile float32 VDAC_CCTgtSpd_kph;/* '<S602>/MinMax7' */
extern MONPRM volatile float32 VDAC_CCTqReqWhl_Nm;/* '<S605>/Merge2' */
extern MONPRM volatile float32 VDAC_CCVehSpdNonDrvn_kph;/* '<S608>/Switch' */
extern MONPRM volatile boolean VDAC_CruzCncl_flg;/* '<S667>/Chart' */
extern MONPRM volatile EnumCruiseStatus VDAC_CruzCtrlStat_enum;/* '<S600>/Switch2' */
extern MONPRM volatile boolean VDAC_CruzCtrlSwVld_flg;/* '<S603>/Signal Conversion1' */
extern MONPRM volatile boolean VDAC_CruzOn_flg;/* '<S603>/Signal Conversion2' */
extern MONPRM volatile boolean VDAC_CruzRsmActv_flg;/* '<S664>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSetActv_flg;/* '<S662>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSpdDecActv_flg;/* '<S663>/Switch4' */
extern MONPRM volatile boolean VDAC_CruzSpdIncActv_flg;/* '<S665>/Switch4' */
extern MONPRM volatile float32 VDAC_DrvAsstTqSplitEHB_Nm;/* '<S575>/MinMax2' */
extern MONPRM volatile float32 VDAC_DrvAsstTqSplitINV_Nm;/* '<S575>/Add1' */
extern MONPRM volatile uint8 VDAC_DrvAsstTqSts_enum;/* '<S575>/Switch1' */
extern MONPRM volatile float32 VDAC_DrvAsstTqTgt_Nm;/* '<S575>/Switch2' */
extern MONPRM volatile boolean VDAC_EnblEHBBrkRun_flg;/* '<S698>/Switch4' */
extern MONPRM volatile boolean VDAC_HDCActv2Idle_flg;/* '<S674>/Logical Operator11' */
extern MONPRM volatile boolean VDAC_HDCActv2Stdby_flg;/* '<S674>/Logical Operator8' */
extern MONPRM volatile float32 VDAC_HDCDeltaAcceltn_mps2;/* '<S679>/Add5' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqFF_Nm;/* '<S679>/Add3' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqI_N;/* '<S679>/Saturation1' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqPID_Nm;/* '<S679>/Product6' */
extern MONPRM volatile float32 VDAC_HDCDsrdTqP_N;/* '<S679>/Product3' */
extern MONPRM volatile boolean VDAC_HDCIdle2Stdby_flg;/* '<S674>/Logical Operator2' */
extern MONPRM volatile EnumHDCState VDAC_HDCSt_enum;/* '<S573>/HDC_State_Chart' */
extern MONPRM volatile boolean VDAC_HDCStdby2Actv_flg;/* '<S674>/Logical Operator13' */
extern MONPRM volatile boolean VDAC_HDCStdby2Idle_flg;/* '<S674>/Logical Operator3' */
extern MONPRM volatile float32 VDAC_HDCTgtAcceltn_mps2;/* '<S671>/Merge1' */
extern MONPRM volatile float32 VDAC_HDCTgtSpd_kph;/* '<S573>/HDC_State_Chart' */
extern MONPRM volatile float32 VDAC_HDCTqReqWhl_Nm;/* '<S671>/Merge2' */
extern MONPRM volatile uint8 VDAC_HDCVehSpdHU_kph;/* '<S672>/Switch1' */
extern MONPRM volatile float32 VDAC_MstrCylPresrReq_bar;/* '<S575>/Switch13' */
extern MONPRM volatile uint8 VDAC_VehSpdHU_kph;/* '<S653>/Switch1' */
extern MONPRM volatile uint8 VDAC_VirtAccPedPstnSta_enum;/* '<S575>/Switch11' */
extern MONPRM volatile float32 VDAC_VirtAccPedPstn_pct;/* '<S575>/Switch8' */
extern MONPRM volatile float32 VDAC_VirtAccelPedPstnRaw_pct;/* '<S575>/Switch9' */
extern MONPRM volatile float32 VDAC_VirtPedPstn_pct;/* '<S575>/Switch4' */
extern MONPRM volatile uint8 VDAG_ACCMHVILFltSt_enum;/* '<S1471>/FltStDeb' */

/* ѹ������ѹ��������״̬ */
extern MONPRM volatile uint8 VDAG_ACChrgStFailFltSt_enum;/* '<S1303>/FltStDeb' */

/* ACChargeStateFail����״̬ */
extern MONPRM volatile uint8 VDAG_ACDchaBMSPwrLoFltSt_enum;/* '<S1309>/FltStDeb' */

/* AC�ŵ�BMS���ʵ͹���״̬ */
extern MONPRM volatile uint8 VDAG_ACDchaBMSSOCLoFltSt_enum;/* '<S1308>/FltStDeb' */

/* AC�ŵ�BMSSOC�͹���״̬ */
extern MONPRM volatile uint8 VDAG_ACDchaOverPwrFltSt_enum;/* '<S1302>/FltStDeb' */

/* AC�ŵ繦�ʳ��޹��� */
extern MONPRM volatile uint8 VDAG_ACSCmdTmOutFltSt_enum;/* '<S1021>/FltStDeb' */

/* ACSCmd��ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_AccPed1ShtBattFltSt_enum;/* '<S1444>/FltStDeb' */

/* ����̤��1·�̵�Դ����״̬ */
extern MONPRM volatile uint8 VDAG_AccPed1ShtGndFltSt_enum;/* '<S1441>/FltStDeb' */

/* ����̤��1·�̵ع���״̬ */
extern MONPRM volatile uint8 VDAG_AccPed1SuplyShtCircFltSt_enum;/* '<S1442>/FltStDeb' */

/* ����̤��1·�����·����״̬ */
extern MONPRM volatile uint8 VDAG_AccPed2ShtBattFltSt_enum;/* '<S1437>/FltStDeb' */

/* ����̤��2·�̵�Դ����״̬ */
extern MONPRM volatile uint8 VDAG_AccPed2ShtGndFltSt_enum;/* '<S1445>/FltStDeb' */

/* ����̤��2·�̵ع���״̬ */
extern MONPRM volatile uint8 VDAG_AccPed2SuplyShtCircFltSt_enum;/* '<S1443>/FltStDeb' */

/* ����̤��2·�����·����״̬ */
extern MONPRM volatile uint8 VDAG_AccPedBothFailFltSt_enum;/* '<S1439>/FltStDeb' */

/* ����̤��˫·ʧЧ����״̬ */
extern MONPRM volatile uint8 VDAG_AccPedCrsChkFltSt_enum;/* '<S1438>/FltStDeb' */

/* ����̤���໥У�����״̬ */
extern MONPRM volatile uint8 VDAG_BMSCmdTmOutFltSt_enum;/* '<S1015>/FltStDeb' */

/* BMS�̵���ָ����Ӧ��ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_BMSEmgcySdnFltSt_enum;/* '<S1026>/FltStDeb' */

/* BMS�����µ����״̬ */
extern MONPRM volatile uint8 VDAG_BMSSOCLoFltSt_enum;/* '<S1025>/FltStDeb' */

/* BMSSOC�͹���״̬ */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl1FltSt_enum;/* '<S1022>/FltStDeb' */

/* BMSFailLevel1����״̬ */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl2FltSt_enum;/* '<S1023>/FltStDeb' */

/* BMSFailLevel2����״̬ */
extern MONPRM volatile uint8 VDAG_BMSSysFailLvl3FltSt_enum;/* '<S1024>/FltStDeb' */

/* BMSFailLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_BMSUndrVoltFltSt_enum;/* '<S1027>/FltStDeb' */

/* BMSPackǷѹ����״̬ */
extern MONPRM volatile uint8 VDAG_BrkPedShtBattFltSt_enum;/* '<S1468>/FltStDeb' */

/* �ƶ�̤��̵�Դ����״̬ */
extern MONPRM volatile uint8 VDAG_BrkPedShtGndFltSt_enum;/* '<S1466>/FltStDeb' */

/* �ƶ�̤��̵ع���״̬ */
extern MONPRM volatile uint8 VDAG_BrkSwCrsChkCnt_cnt;/* '<S1458>/Data Type Conversion' */

/* �ƶ������໥У�������� */
extern MONPRM volatile uint8 VDAG_BrkSwCrsChkFltSt_enum;/* '<S1467>/FltStDeb' */

/* �ƶ������໥У�����״̬ */
extern MONPRM volatile uint8 VDAG_CellUndrVoltFltSt_enum;/* '<S1028>/FltStDeb' */

/* BMSCellǷѹ����״̬ */
extern MONPRM volatile uint8 VDAG_DCCCmdTmOutFltSt_enum;/* '<S1197>/FltStDeb' */

/* DCDCģʽָ����Ӧ��ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_DCCInVoltLoFltSt_enum;/* '<S1198>/FltStDeb' */

/* DCDC�����ѹ�͹���״̬ */
extern MONPRM volatile uint8 VDAG_DCCModeFltFltSt_enum;/* '<S1196>/FltStDeb' */

/* DCDCModeFault����״̬ */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl1FltSt_enum;/* '<S1192>/FltStDeb' */

/* DCDCFailLevel1����״̬ */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl2FltSt_enum;/* '<S1193>/FltStDeb' */

/* DCDCFailLevel2����״̬ */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl3FltSt_enum;/* '<S1194>/FltStDeb' */

/* DCDCFailLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_DCCSysFailLvl4FltSt_enum;/* '<S1195>/FltStDeb' */

/* DCDCFailLevel4����״̬ */
extern MONPRM volatile uint8 VDAG_DCSChrgReqFltSt_enum;/* '<S1019>/FltStDeb' */

/* DCSChargeRequest����״̬ */
extern MONPRM volatile uint8 VDAG_DCSCmdTmOutFltSt_enum;/* '<S1029>/FltStDeb' */

/* DCSCmd��ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_DCSFailStaFltSt_enum;/* '<S1017>/FltStDeb' */

/* DCSFailState����״̬ */
extern MONPRM volatile uint8 VDAG_DCSInletConnectFltSt_enum;/* '<S1018>/FltStDeb' */

/* DCS��ǹ����״̬ */
extern MONPRM volatile uint8 VDAG_DCSModeFailFltSt_enum;/* '<S1020>/FltStDeb' */

/* DCSModeFail����״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl1FltSt_enum;/* '<S1375>/FltStDeb' */

/* EHB1������״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl2FltSt_enum;/* '<S1376>/FltStDeb' */

/* EHB2������״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl3FltSt_enum;/* '<S1377>/FltStDeb' */

/* EHB3������״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl4FltSt_enum;/* '<S1369>/FltStDeb' */

/* EHB4������״̬ */
extern MONPRM volatile uint8 VDAG_EHBFltLvl5FltSt_enum;/* '<S1378>/FltStDeb' */

/* EHB5������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl1FltSt_enum;/* '<S1380>/FltStDeb' */

/* ESC1������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl2FltSt_enum;/* '<S1370>/FltStDeb' */

/* ESC2������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl3FltSt_enum;/* '<S1371>/FltStDeb' */

/* ESC3������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl4FltSt_enum;/* '<S1379>/FltStDeb' */

/* ESC4������״̬ */
extern MONPRM volatile uint8 VDAG_ESCFltLvl5FltSt_enum;/* '<S1372>/FltStDeb' */

/* ESC5������״̬ */
extern MONPRM volatile uint8 VDAG_ESCVehSpdInvldFltSt_enum;/* '<S1374>/FltStDeb' */

/* ����ʧЧ����״̬ */
extern MONPRM volatile boolean VDAG_EmgcyShtdwn_flg;/* '<S979>/Switch30' */
extern MONPRM volatile uint16 VDAG_ErrCode_enum;/* '<S977>/Err_State' */
extern MONPRM volatile boolean VDAG_FanFullSpdOn_flg;/* '<S979>/Switch3' */
extern MONPRM volatile boolean VDAG_FbdACC_flg;/* '<S979>/Switch28' */
extern MONPRM volatile boolean VDAG_FbdACChrg_flg;/* '<S979>/Switch32' */
extern MONPRM volatile boolean VDAG_FbdACDcha_flg;/* '<S979>/Switch34' */
extern MONPRM volatile boolean VDAG_FbdAC_flg;/* '<S979>/Switch35' */
extern MONPRM volatile boolean VDAG_FbdCC_flg;/* '<S979>/Switch26' */
extern MONPRM volatile boolean VDAG_FbdDCChrg_flg;/* '<S979>/Switch33' */
extern MONPRM volatile boolean VDAG_FbdDCDC_flg;/* '<S979>/Switch31' */
extern MONPRM volatile boolean VDAG_FbdDRGr_flg;/* '<S979>/Switch25' */
extern MONPRM volatile boolean VDAG_FbdDrvTq_flg;/* '<S979>/Switch23' */
extern MONPRM volatile boolean VDAG_FbdHV_flg;/* '<S979>/Switch29' */
extern MONPRM volatile boolean VDAG_FbdLSP_flg;/* '<S979>/Switch27' */
extern MONPRM volatile boolean VDAG_FltLampOn_flg;/* '<S979>/Switch36' */
extern MONPRM volatile uint8 VDAG_FltLvl_enum;/* '<S979>/MinMax' */
extern MONPRM volatile uint8 VDAG_FrstHVILVoltHiFltSt_enum;/* '<S1470>/FltStDeb' */

/* ��Ҫ��ѹ������ѹ�߹���״̬ */
extern MONPRM volatile uint8 VDAG_FrstHVILVoltLoFltSt_enum;/* '<S1469>/FltStDeb' */

/* ��Ҫ��ѹ������ѹ�͹���״̬ */
extern MONPRM volatile uint8 VDAG_GearShftInvldFltSt_enum;/* '<S1373>/FltStDeb' */

/* ��������ʧЧ����״̬ */
extern MONPRM volatile uint8 VDAG_HVIsoResistLoFltSt_enum;/* '<S1016>/FltStDeb' */

/* ��ѹ��ؾ�Ե����״̬ */
extern MONPRM volatile uint8 VDAG_INVFltLvl1FltSt_enum;/* '<S1269>/FltStDeb' */

/* INVFaultLevel1����״̬ */
extern MONPRM volatile uint8 VDAG_INVFltLvl2FltSt_enum;/* '<S1270>/FltStDeb' */

/* INVFaultLevel2����״̬ */
extern MONPRM volatile uint8 VDAG_INVFltLvl3FltSt_enum;/* '<S1271>/FltStDeb' */

/* INVFaultLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_INVFltLvl4FltSt_enum;/* '<S1272>/FltStDeb' */

/* INVFaultLevel4����״̬ */
extern MONPRM volatile uint8 VDAG_INVInVoltLoFltSt_enum;/* '<S1199>/FltStDeb' */

/* INV�����ѹ�͹���״̬ */
extern MONPRM volatile uint8 VDAG_INVRunCmdRespFltSt_enum;/* '<S1273>/FltStDeb' */

/* INVRunָ����Ӧ��ʱ����״̬ */
extern MONPRM volatile boolean VDAG_LVBatLampOn_flg;/* '<S979>/Switch1' */
extern MONPRM volatile uint8 VDAG_LVBattSOCLoFltSt_enum;/* '<S1417>/FltStDeb' */

/* ����SOC�͵Ĺ���״̬ */
extern MONPRM volatile uint8 VDAG_LVBattSOHLoFltSt_enum;/* '<S1413>/FltStDeb' */

/* ����SOH�͵Ĺ���״̬ */
extern MONPRM volatile uint8 VDAG_LVBattTempHiFltSt_enum;/* '<S1414>/FltStDeb' */

/* ���ع��¹���״̬ */
extern MONPRM volatile uint8 VDAG_LVBattVoltHiFltSt_enum;/* '<S1416>/FltStDeb' */

/* ���ص�ѹ�߹���״̬ */
extern MONPRM volatile uint8 VDAG_LVBattVoltLoFltSt_enum;/* '<S1415>/FltStDeb' */

/* ���ص�ѹ�͹���״̬ */
extern MONPRM volatile boolean VDAG_LimpHome_flg;/* '<S979>/Switch2' */
extern MONPRM volatile boolean VDAG_LmtDrvTq_flg;/* '<S979>/Switch24' */
extern MONPRM volatile uint8 VDAG_OBCChrgReqFltSt_enum;/* '<S1307>/FltStDeb' */

/* OBCChargeRequest����״̬ */
extern MONPRM volatile uint8 VDAG_OBCConnectTmOutFltSt_enum;/* '<S1305>/FltStDeb' */

/* OBC���ӳ�ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_OBCInletConnectFltSt_enum;/* '<S1310>/FltStDeb' */

/* OBC��ǹ����״̬ */
extern MONPRM volatile uint8 VDAG_OBCModeMsmtchFltSt_enum;/* '<S1304>/FltStDeb' */

/* OBCģʽ��ƥ�����״̬ */
extern MONPRM volatile uint8 VDAG_OBCS2StatFltSt_enum;/* '<S1306>/FltStDeb' */

/* OBCS2���ӳ�ʱ����״̬ */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl1FltSt_enum;/* '<S1311>/FltStDeb' */

/* OBCFailLevel1����״̬ */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl2FltSt_enum;/* '<S1312>/FltStDeb' */

/* OBCFailLevel2����״̬ */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl3FltSt_enum;/* '<S1313>/FltStDeb' */

/* OBCFailLevel3����״̬ */
extern MONPRM volatile uint8 VDAG_OBCSysFailLvl4FltSt_enum;/* '<S1301>/FltStDeb' */

/* OBCFailLevel4����״̬ */
extern MONPRM volatile uint8 VDAG_SecdHVILVoltHiFltSt_enum;/* '<S1473>/FltStDeb' */

/* ��Ҫ��ѹ������ѹ�߹���״̬ */
extern MONPRM volatile uint8 VDAG_SecdHVILVoltLoFltSt_enum;/* '<S1472>/FltStDeb' */

/* ��Ҫ��ѹ������ѹ�͹���״̬ */
extern MONPRM volatile uint8 VDAG_SysPwrModeInvldFltSt_enum;/* '<S1367>/FltStDeb' */

/* PowerModeʧЧ����״̬ */
extern MONPRM volatile uint8 VDAG_TMSFailLvl3FltSt_enum;/* '<S1368>/FltStDeb' */

/* TMSRFailLevel3����״̬ */
extern MONPRM volatile boolean VDAG_TMSbPwrHVPart_flg;/* '<S978>/Signal Conversion1' */

/* TMS����PTC��ACCM */
extern MONPRM volatile uint8 VDAG_VehCrashFltSt_enum;/* '<S1436>/FltStDeb' */

/* ��ײ����״̬ */
extern MONPRM volatile uint8 VDAG_WaterTempAbvThrFltSt_enum;/* '<S1504>/FltStDeb' */

/* ��ȴˮ�¹��߹���״̬ */
extern MONPRM volatile uint8 VDAG_WaterTempBlwThrFltSt_enum;/* '<S1503>/FltStDeb' */

/* ��ȴˮ�¹��͹���״̬ */
extern MONPRM volatile float32 VDSA_AcceltnIdxAvg_pct;/* '<S75>/AvgAcceltnIdx' */
extern MONPRM volatile float32 VDSA_AcceltnIdxRaw_pct;/* '<S75>/Saturation1' */
extern MONPRM volatile float32 VDSA_BrkPedPstnAvg_pct;/* '<S75>/AvgBrkPedPstn' */
extern MONPRM volatile float32 VDSA_DrvSprtIdx_pct;/* '<S75>/Saturation2' */
extern MONPRM volatile boolean VDSA_SprtIdxHldAcc_flg;/* '<S75>/Logical Operator3' */
extern MONPRM volatile boolean VDSA_SprtIdxHldBrk_flg;/* '<S75>/Logical Operator6' */
extern MONPRM volatile float32 VDSA_TqCalcAcceltn_mps2;/* '<S75>/Divide1' */
extern MONPRM volatile boolean VEMS_ACCMOprtCmd_flg;/* '<S914>/ACCMEnble' */

/* ʹ��ACCM��Ŀǰδʹ�ã� */
extern MONPRM volatile float32 VEMS_AccPwrRaw_kW;/* '<S915>/MinMax4' */

/* ԭʼ�������ʣ�ACCM��PTC��DCC�� */
extern MONPRM volatile boolean VEMS_CellTempLo_flg;/* '<S915>/Relational Operator6' */

/* ��о���±�־λ */
extern MONPRM volatile float32 VEMS_CellTempSyn_C;/* '<S973>/Switch1' */

/* ��о�¶��޷� */
extern MONPRM volatile float32 VEMS_CellUndrVoltDrtFac_c;/* '<S912>/Saturation3' */

/* �ŵ絥�忪����ѹ����ϵ����Ƿѹ���׷�ֵ�� */
extern MONPRM volatile float32 VEMS_ChrgCurFbKi_A;/* '<S970>/Saturation' */

/* ���յ����ѹ�ջ�I�� */
extern MONPRM volatile float32 VEMS_ChrgCurFbKp_A;/* '<S970>/Product2' */

/* ���յ����ѹ�ջ�P�� */
extern MONPRM volatile float32 VEMS_ChrgCurFb_A;/* '<S970>/Saturation2' */

/* ���յ����ѹ�ջ�P��+I�� */
extern MONPRM volatile float32 VEMS_ChrgOvrshtPwr_kW;/* '<S911>/Add1' */

/* ���չ��ʱջ���ֵ  VEMS_MaxChrgPwr_kW-VEMS_HVBatPwrAct_kW */
extern MONPRM volatile float32 VEMS_ChrgPwrFbKi_kW;/* '<S931>/Saturation' */

/* ���չ��ʱջ�I�� */
extern MONPRM volatile float32 VEMS_ChrgPwrFbKp_kW;/* '<S931>/Product2' */

/* ���չ��ʱջ�P�� */
extern MONPRM volatile float32 VEMS_ChrgPwrFb_kW;/* '<S911>/Merge' */

/* ���չ��ʱջ�P��+I�� */
extern MONPRM volatile float32 VEMS_DchaCurFbKi_A;/* '<S971>/Saturation' */

/* �ŵ絥���ѹ�ջ�I�� */
extern MONPRM volatile float32 VEMS_DchaCurFbKp_A;/* '<S971>/Product2' */

/* �ŵ絥���ѹ�ջ�P�� */
extern MONPRM volatile float32 VEMS_DchaCurFb_A;/* '<S971>/Saturation2' */

/* �ŵ絥���ѹ�ջ�P��+I�� */
extern MONPRM volatile float32 VEMS_DchaOvrshtPwr_kW;/* '<S913>/Add1' */

/* �ŵ繦�ʱջ���ֵ  VEMS_MaxDchaPwr_kW-VEMS_HVBatPwrAct_kW */
extern MONPRM volatile float32 VEMS_DchaPwrFbKi_kW;/* '<S950>/Saturation' */

/* �ŵ繦�ʱջ�I�� */
extern MONPRM volatile float32 VEMS_DchaPwrFbKp_kW;/* '<S950>/Product2' */

/* �ŵ繦�ʱջ�P�� */
extern MONPRM volatile float32 VEMS_DchaPwrFb_kW;/* '<S913>/Merge' */

/* �ŵ繦�ʱջ�P��+I�� */
extern MONPRM volatile float32 VEMS_HVBatPwrAct_kW;/* '<S915>/Gain1' */

/* ʵ��ĸ�߹��� */
extern MONPRM volatile float32 VEMS_MaxChrgCur_A;/* '<S910>/Saturation4' */

/* �������������� ��˲ʱ/���������л���*VEMS_CellOverVoltDrtFac_c */
extern MONPRM volatile float32 VEMS_MaxChrgPwr2MotRaw_kW;/* '<S910>/Add7' */

/* ����������ԭʼ����  VEMS_MaxChrgPwr_kW���˲���-VEMS_AccPwrRaw_kW���˲��� */
extern MONPRM volatile float32 VEMS_MaxChrgPwr2Mot_kW;/* '<S911>/Switch' */

/* ������������ VEMS_MaxChrgPwr2MotRaw_kW+VEMS_ChrgPwrFb_kW */
extern MONPRM volatile float32 VEMS_MaxChrgPwr_kW;/* '<S910>/Product2' */

/* ������������� VEMS_MaxChrgCur_A*VIPM_BMSHVBatActVolt_V */
extern MONPRM volatile float32 VEMS_MaxConChrgCur_A;/* '<S910>/MinMax1' */

/* ���ճ����������� min{VEMS_MaxConChrgVoltCls_A-ƫ�Ƶ���,������} */
extern MONPRM volatile float32 VEMS_MaxConChrgVoltCls_A;/* '<S915>/Saturation4' */

/* ���յ����ѹ�ջ���������������VIPM_BMSMaxConChrgCurnt_A+VEMS_ChrgCurFb_A�� */
extern MONPRM volatile float32 VEMS_MaxConDchaCur_A;/* '<S912>/MinMax1' */

/* �ŵ������������ min{VEMS_MaxConDchaVoltCls_A-ƫ�Ƶ���,������} */
extern MONPRM volatile float32 VEMS_MaxConDchaVoltCls_A;/* '<S915>/Saturation2' */

/* �ŵ絥���ѹ�ջ���������������VIPM_BMSMaxConDisCurnt_A+VEMS_DchaCurFb_A�� */
extern MONPRM volatile float32 VEMS_MaxDchaCur_A;/* '<S912>/Saturation4' */

/* �ŵ����������� ��˲ʱ/���������л���*VEMS_CellUndrVoltDrtFac_c */
extern MONPRM volatile float32 VEMS_MaxDchaPwr2MotRaw_kW;/* '<S912>/Add7' */

/* ����ŵ����ԭʼ����  VEMS_MaxDchaPwr_kW���˲���-VEMS_AccPwrRaw_kW���˲��� */
extern MONPRM volatile float32 VEMS_MaxDchaPwr2Mot_kW;/* '<S913>/Switch' */

/* ����ŵ������ VEMS_MaxDchaPwr2MotRaw_kW+VEMS_DchaPwrFb_kW */
extern MONPRM volatile float32 VEMS_MaxDchaPwr_kW;/* '<S912>/Product2' */

/* �ŵ����������  VEMS_MaxDchaCur_A*VIPM_BMSHVBatActVolt_V */
extern MONPRM volatile float32 VEMS_MaxInsChrgCur_A;/* '<S910>/MinMax3' */

/* ����˲ʱ�������� min{VEMS_MaxInsChrgVoltCls_A-ƫ�Ƶ���,������} */
extern MONPRM volatile float32 VEMS_MaxInsChrgVoltCls_A;/* '<S915>/Saturation3' */

/* ���յ����ѹ�ջ�˲ʱ����������VIPM_BMSMaxInsChrgCurnt_A+VEMS_ChrgCurFb_A�� */
extern MONPRM volatile float32 VEMS_MaxInsDchaCur_A;/* '<S912>/MinMax3' */

/* �ŵ�˲ʱ�������� min{VEMS_MaxInsDchaVoltCls_A-ƫ�Ƶ���,������} */
extern MONPRM volatile float32 VEMS_MaxInsDchaVoltCls_A;/* '<S915>/Saturation1' */

/* �ŵ絥���ѹ�ջ�˲ʱ����������VIPM_BMSMaxInsDisCurnt_A+VEMS_DchaCurFb_A�� */
extern MONPRM volatile boolean VEMS_TMSActSOCEnbl_flg;/* '<S967>/Switch1' */

/* SOC����TMS���ŵ磩 */
extern MONPRM volatile boolean VEMS_TMSPwrEnbl_flg;/* '<S914>/Switch3' */

/* ��������TMS�����+�ŵ磩 */
extern MONPRM volatile float32 VEMS_TMSUsePwrRaw_kW;/* '<S914>/Subtract' */

/* TMSԭʼ���ù��ʣ�BMS�������ʣ�VEMS_MaxConDchaVoltCls_A*VIPM_BMSHVBatActVolt_V��-DCDCʵ�ʹ��ʣ� */
extern MONPRM volatile float32 VEMS_TMSUsePwr_kW;/* '<S914>/Switch2' */

/* TMS���ƺ���ù���(����������TBOXԶ�̡�������ģʽ��SOC����) */
extern MONPRM volatile boolean VEMS_UseConChrgCur_flg;/* '<S921>/Switch4' */

/* ʹ�ó������յ�����־λ */
extern MONPRM volatile boolean VEMS_UseConDchaCur_flg;/* '<S940>/Switch4' */

/* ʹ�ó����ŵ������־λ */
extern MONPRM volatile boolean VGSM_AsstDrvFbShft_flg;/* '<S1714>/Logical Operator2' */

/* �淶��ACC/CC��ֹ��λ���� */
extern MONPRM volatile boolean VGSM_AsstDrvReqEPB_flg;/* '<S1700>/Switch4' */

/* ACCͨѶ��ʧ���������EPB */
extern MONPRM volatile boolean VGSM_DRFlt2N_flg;/* '<S1713>/Switch1' */

/* �淶����������������־λ */
extern MONPRM volatile boolean VGSM_EPBAplyFlt_flg;/* '<S1690>/EPBLogical' */

/* ����P-EPB������� */
extern MONPRM volatile boolean VGSM_EPBRelsFlt_flg;/* '<S1690>/EPBLogical' */

/* ����P-EPB�ͷŹ��� */
extern MONPRM volatile boolean VGSM_GrD2PExcdTm_flg;/* '<S1868>/Chart' */

/* D����P����ʱ��N */
extern MONPRM volatile boolean VGSM_GrNReq2P_flg;/* '<S1713>/Switch2' */

/* N���ǻ��������P������ */
extern MONPRM volatile boolean VGSM_GrR2PExcdTm_flg;/* '<S1865>/Chart' */

/* R����P����ʱ��N */
extern MONPRM volatile boolean VGSM_HldGearP_flg;/* '<S1713>/Switch' */

/* �淶������P����־λ */
extern MONPRM volatile boolean VGSM_INVRunEnbl_flg;/* '<S1716>/Chart' */

/* �淶��INVʹ�ܿ��ƣ�����Ť�ؿ��ƣ�-VCU_1_EnaInvRun */
extern MONPRM volatile uint8 VGSM_PGrSwSts_enum;/* '<S1714>/Switch2' */

/* �淶��P����������־λ-VCU_PGearSwcst */
extern MONPRM volatile boolean VGSM_ReqEPBAply_flg;/* '<S1715>/Logical Operator6' */

/* �淶��EPB���������־λ */
extern MONPRM volatile boolean VGSM_ReqEPBRels_flg;/* '<S1715>/Logical Operator4' */

/* �淶��EPB�ͷ������־λ */
extern MONPRM volatile EnumEPBReq VGSM_ReqEPB_enum;/* '<S1690>/Switch' */

/* �淶��EPB�����ź�-VCUF_ReqEPB */
extern MONPRM volatile EnumTgtGearPstn VGSM_ShftTgtGrReq_enum;/* '<S1714>/Data Type Conversion1' */

/* ������Ŀ�굵λ 0-NoCmd 1-P 2-N 3-D 4-R  */
extern MONPRM volatile EnumGearPstn VGSM_VehActGearPstn_enum;/* '<S1691>/Switch1' */

/* �淶��ʵ�ʵ�λ-VCU_VhclActlGearPos */
extern MONPRM volatile boolean VGSM_VehEPBStErr_flg;/* '<S1690>/Logical Operator' */

/* �淶��P������PGear error-VCU_VhclPGearError */
extern MONPRM volatile EnumTgtGearPstn VGSM_VehTgtGrReq_enum;/* '<S1715>/Data Type Conversion1' */

/* �淶:Ŀ�굵λ */
extern MONPRM volatile uint8 VGSM_VehTgtGrTrnsfr_enum;/* '<S1753>/Switch' */

/* �淶�����������ź� */
extern MONPRM volatile uint8 VHMI_12VBatLowVolSta_enum;/* '<S84>/Switch' */
extern MONPRM volatile float32 VHMI_GrDSldDist_m;/* '<S98>/Saturation' */

/* D��������� */
extern MONPRM volatile boolean VHMI_GrDSldSw_flg;/* '<S98>/Logical Operator' */

/* D�����¼���/�����־ */
extern MONPRM volatile float32 VHMI_GrRSldDist_m;/* '<S98>/Saturation1' */

/* R��ǰ����� */
extern MONPRM volatile boolean VHMI_GrRSldSw_flg;/* '<S98>/Logical Operator4' */

/* R�����¼���/�����־ */
extern MONPRM volatile uint8 VHMI_InfoDisp_enum;/* '<S87>/Arbitration' */

/* �Ǳ���ֵ */
extern MONPRM volatile boolean VHVM_ACChrgEnbl_flg;/* '<S1582>/Logical Operator8' */

/* ������������������ */
extern MONPRM volatile uint8 VHVM_ACChrgMaxCurrFb_A;/* '<S1552>/Switch5' */

/* HU���õ������� */
extern MONPRM volatile uint8 VHVM_ACChrgModeFb_enum;/* '<S1552>/Switch7' */

/* HU���ó��ģʽ���� */
extern MONPRM volatile boolean VHVM_ACChrging2Stop_flg;/* '<S1576>/AND' */

/* ���������ת�Ƶ����ֹͣ��־λ */
extern MONPRM volatile boolean VHVM_ACDchaEnbl_flg;/* '<S1582>/Logical Operator10' */

/* �����ŵ������������ */
extern MONPRM volatile boolean VHVM_ACDschrging2Stop_flg;/* '<S1576>/AND7' */

/* �����ŵ���ת�Ƶ��ŵ�ֹͣ��־λ */
extern MONPRM volatile EnumBMSSdnCmd VHVM_BMSShutdown_enum;/* '<S1551>/Data Type Conversion10' */

/* VCU�ر�BMSָ���ӦCAN�źţ�VCU_BMS_Shutdown */
extern MONPRM volatile EnumBMSWakeUpMd VHVM_BMSWakeUpMode_enum;/* '<S1551>/Data Type Conversion8' */

/* VCU����BMS�ķ�ʽ��ӦCAN�źţ�VCU_BMS_WakeupMode */
extern MONPRM volatile boolean VHVM_Bat2DrvTrainEnbl_flg;/* '<S1551>/MainState' */

/* VCU�������̵���ָ���ӦCAN�źţ�VCU_Bat2DrvTrainEnb */
extern MONPRM volatile EnumChrgAllwCmd VHVM_ChrgAllowCmd_enum;/* '<S1551>/Data Type Conversion12' */

/* VCU����������ָ���ӦCAN�źţ�VCU_ChrgAllowCmd */
extern MONPRM volatile uint8 VHVM_ChrgEnaAC_enum;/* '<S1551>/MainState' */

/* VCU����OBC�������ʹ��ָ���ӦCAN�źţ�VCU_ChrgEna_AC */
extern MONPRM volatile boolean VHVM_ChrgEnaDC_flg;/* '<S1551>/MainState' */

/* VCU����BMSֱ�����ʹ��ָ���ӦCAN�źţ�VCU_ChrgEna_DC */
extern MONPRM volatile float32 VHVM_DCCBuckLVVolt_V;/* '<S1551>/MainState' */

/* VCU����DCDC BUCK��ѹֵ��ӦCAN�źţ�VCU_DCCBuckLV_Vol */
extern MONPRM volatile EnumDCCOprtCmd VHVM_DCCOprtCmd_enum;/* '<S1551>/Data Type Conversion6' */

/* VCU����DCDC����ģʽָ���ӦCAN�źţ�VCU_DCCOprtCmd */
extern MONPRM volatile boolean VHVM_DCChrgEnbl_flg;/* '<S1582>/Logical Operator2' */

/* ֱ���������������� */
extern MONPRM volatile boolean VHVM_DCChrging2Over_flg;/* '<S1576>/AND1' */

/* ֱ�������ת�Ƶ���������־λ */
extern MONPRM volatile boolean VHVM_ECUSleepAllwd_flg;/* '<S1551>/MainState' */

/* ����ײ����߱�־λ */
extern MONPRM volatile boolean VHVM_EmgcySdn_flg;/* '<S1551>/MainState' */

/* VCU��INV���ͽ����µ�ָ��(INVǿ��ͣ��)��ӦCAN�źţ�VCU_1_EmShutDown */
extern MONPRM volatile boolean VHVM_EnaDisChg_flg;/* '<S1551>/MainState' */

/* VCU����INVй��ָ���ӦCAN�źţ�VCU_1_EnaDisChg */
extern MONPRM volatile boolean VHVM_EngyExtrmLo_flg;/* '<S1554>/Logical Operator17' */

/* ����������ͱ�־λ */
extern MONPRM volatile boolean VHVM_F1B1HVOffReq_flg;/* '<S1581>/Logical Operator45' */

/* F1B1�µ����� */
extern MONPRM volatile boolean VHVM_F1B1HVOnReq_flg;/* '<S1582>/Logical Operator45' */

/* F1B1�ϵ����� */
extern MONPRM volatile boolean VHVM_HVRdy_flg;/* '<S1551>/MainState' */

/* DCDC&INVԤ����� */
extern MONPRM volatile boolean VHVM_INVEnbl_flg;/* '<S1551>/MainState' */

/* VCUӲ�߻���INV */
extern MONPRM volatile boolean VHVM_INVPreprogmFlg_flg;/* '<S1577>/Switch1' */

/* INVԤ����������� */
extern MONPRM volatile float32 VHVM_MaxChrgCurntDC_A;/* '<S1551>/MainState' */

/* VCU����BMSֱ�������������ӦCAN�źţ�VCU_MaxChrgCrnt_DC */
extern MONPRM volatile float32 VHVM_MaxChrgVoltDC_V;/* '<S1551>/MainState' */

/* VCU����BMSֱ���������ѹ��ӦCAN�źţ�VCU_MaxChrgVol_DC */
extern MONPRM volatile float32 VHVM_MaxHVDCCurntAC_A;/* '<S1551>/MainState' */

/* VCU����OBC���������������ӦCAN�źţ�VCU_MaxHVDC_Cur_AC */
extern MONPRM volatile float32 VHVM_MaxHVDCVoltAC_V;/* '<S1551>/MainState' */

/* VCU����OBC�����������ѹ��ӦCAN�źţ�VCU_MaxHVDC_Vol_AC */
extern MONPRM volatile EnumOBCOprtCmd VHVM_OBCOprtCmd_enum;/* '<S1552>/Data Type Conversion4' */

/* VCU����OBC����ģʽָ���ӦCAN�źţ�VCU_OBCOprtCmd */
extern MONPRM volatile EnumPTActMd VHVM_PTActOprtMode_enum;/* '<S1551>/Data Type Conversion4' */

/* ��ѹPT״̬ */
extern MONPRM volatile boolean VHVM_PTRdy2PTStdby_flg;/* '<S1579>/Switch1' */

/* PTRdy��PTStdby��־λ */
extern MONPRM volatile boolean VHVM_PTStdby2PTRdy_flg;/* '<S1579>/Switch' */

/* PTStdby��PTRdy��־λ */
extern MONPRM volatile boolean VHVM_PowUpSelfChek_flg;/* '<S1580>/Switch' */

/* ��ѹ�Լ��־λ */
extern MONPRM volatile boolean VHVM_PwrOn2PwrDwn_flg;/* '<S1581>/Switch' */

/* ��ѹ�µ����������־λ������/����/������ */
extern MONPRM volatile boolean VHVM_SOPExtrmLo_flg;/* '<S1554>/Relational Operator4' */

/* ���SOP���ͣ����ڹر�DCDC */
extern MONPRM volatile EnumSysSta VHVM_SysSta_enum;/* '<S1551>/Data Type Conversion2' */

/* ��ѹ��״̬ */
extern MONPRM volatile EnumVCUMode VHVM_VCUMode_enum;/* '<S1551>/Data Type Conversion' */

/* ��ѹ��ת̬ */
extern MONPRM volatile boolean VHVM_VehHalt_flg;/* '<S1571>/Switch4' */

/* ����ֹͣ��־λ�����ټ��䣩 */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpACChrg_flg;/* '<S1582>/Logical Operator16' */

/* ������绽���ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpACDcha_flg;/* '<S1582>/Logical Operator26' */

/* �����ŵ绽���ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpDCChrg_flg;/* '<S1582>/Logical Operator4' */

/* ֱ����绽���ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpIBS_flg;/* '<S1582>/Logical Operator6' */

/* IBS�����ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUpKL15_flg;/* '<S1582>/Logical Operator' */

/* K15�����ϵ� */
extern MONPRM volatile boolean VHVM_WakeUp2PwrUp_flg;/* '<S1582>/Switch' */

/* ���ѵ��ϸ�ѹ�������㣨����Դ������+��ѹ�Լ�ͨ���� */
extern MONPRM volatile boolean VHVM_WakeUpBMS_flg;/* '<S1551>/MainState' */

/* VCUӲ�߻���BMS */
extern MONPRM volatile boolean VHVM_WakeUpVCU_flg;/* '<S1583>/Switch' */

/* ���ߵ������������� */
extern MONPRM volatile boolean VIBS_BMSBatSOCAllow_flg;/* '<S263>/Switch3' */

/* �������SOC�������־λ_versteckt */
extern MONPRM volatile boolean VIBS_ChgNumAllow_flg;/* '<S263>/AND' */

/* ������������־λ_versteckt */
extern MONPRM volatile uint8 VIBS_ChgNum_cnt;/* '<S263>/Switch2' */

/* IBS�������_versteckt */
extern MONPRM volatile boolean VIBS_ChrgBascCond_flg;/* '<S263>/Logical Operator2' */

/* ��������������㣨�����������ѹ��_versteckt */
extern MONPRM volatile boolean VIBS_ChrgEnbl_flg;/* '<S263>/Logical Operator7' */

/* IBS���ʹ�ܱ�־λ_versteckt */
extern MONPRM volatile boolean VIBS_ChrgOver_flg;/* '<S261>/ChrgSt' */

/* IBS���������־λ_versteckt */
extern MONPRM volatile float32 VIBS_ChrgVoltThr_V;/* '<S264>/VoltState' */

/* �����ѹ��ֵ_versteckt */
extern MONPRM volatile float32 VIBS_EnvirTemp_C;/* '<S288>/Switch' */

/* IBS�����¶�_versteckt */
extern MONPRM volatile uint8 VIBS_FailChgNum_cnt;/* '<S263>/Switch5' */

/* IBS����ʧ�ܴ���_versteckt */
extern MONPRM volatile boolean VIBS_FbRctWup_flg;/* '<S263>/Logical Operator6' */

/* IBS��ֹRTC���ѱ�־λ_versteckt */
extern MONPRM volatile boolean VIBS_HVReq_flg;/* '<S263>/Switch' */

/* IBS�����ϸ�ѹ��־λ_versteckt */
extern MONPRM volatile float32 VIBS_HwKL30_V;/* '<S287>/Switch' */

/* �˲����KL30��ѹ_versteckt */
extern MONPRM volatile float32 VIBS_MustChrgVolt_V;/* '<S264>/MIBS_MustChrgVolt_V' */

/* ���׵�ѹ_versteckt */
extern MONPRM volatile boolean VIBS_MustChrg_flg;/* '<S295>/Chart' */

/* ���׵�ѹ�����־λ_versteckt */
extern MONPRM volatile boolean VIBS_NMReq_flg;/* '<S270>/Switch4' */

/* IBS���������־λ_versteckt */
extern MONPRM volatile uint16 VIBS_NextRtcWupThr_min;/* '<S264>/Switch1' */

/* �´β��绽��RTC��ʱ��_versteckt */
extern MONPRM volatile EnumIBSChrgSt VIBS_RTCChrgSt_enum;/* '<S261>/Data Type Conversion' */

/* IBS����״̬_versteckt */
extern MONPRM volatile boolean VIBS_RTCWakeup_flg;/* '<S296>/Chart' */

/* RTC���ѱ�־λ�����ӳ�ʱ�䣩_versteckt */
extern MONPRM volatile boolean VIBS_SleepAllwd_flg;/* '<S263>/SleepAllwd' */

/* IBS����ײ����߱�־λ_versteckt */
extern MONPRM volatile uint16 VIBS_WupChgTmThr_min;/* '<S264>/Switch2' */

/* IBS����ʱ����ֵ_versteckt */
extern MONPRM volatile boolean VIBS_WupVoltAllow_flg;/* '<S289>/Switch4' */

/* KL30��ѹ�����־λ_versteckt */
extern MONPRM volatile boolean VIPC_ACCCfgd_flg;/* '<S373>/Switch8' */
extern MONPRM volatile boolean VIPC_AccPed1Flt_flg;/* '<S377>/Logical Operator1' */
extern MONPRM volatile boolean VIPC_AccPed1LrnDwnActv_flg;/* '<S387>/Relational Operator' */
extern MONPRM volatile boolean VIPC_AccPed1LrnUpActv_flg;/* '<S380>/Logical Operator5' */
extern MONPRM volatile float32 VIPC_AccPed1MinPstnLrnd_pct;/* '<S380>/Switch2' */
extern MONPRM volatile float32 VIPC_AccPed1NormzAvg_pct;/* '<S386>/Switch' */
extern MONPRM volatile float32 VIPC_AccPed1NormzPstn_pct;/* '<S377>/Switch5' */
extern MONPRM volatile float32 VIPC_AccPed1SclPstn_pct;/* '<S381>/Divide1' */
extern MONPRM volatile boolean VIPC_AccPed2Flt_flg;/* '<S377>/Logical Operator2' */
extern MONPRM volatile boolean VIPC_AccPed2LrnDwnActv_flg;/* '<S391>/Relational Operator' */
extern MONPRM volatile boolean VIPC_AccPed2LrnUpActv_flg;/* '<S382>/Logical Operator5' */
extern MONPRM volatile float32 VIPC_AccPed2MinPstnLrnd_pct;/* '<S382>/Switch2' */
extern MONPRM volatile float32 VIPC_AccPed2NormzAvg_pct;/* '<S390>/Switch' */
extern MONPRM volatile float32 VIPC_AccPed2NormzPstn_pct;/* '<S377>/Switch7' */
extern MONPRM volatile float32 VIPC_AccPed2SclPstn_pct;/* '<S383>/Divide5' */
extern MONPRM volatile boolean VIPC_AccPedPstnVld_flg;/* '<S379>/Switch3' */
extern MONPRM volatile float32 VIPC_AccPedPstn_pct;/* '<S375>/MinMax3' */
extern MONPRM volatile uint8 VIPC_AccPedSnsrSta_enum;/* '<S379>/Switch3' */
extern MONPRM volatile boolean VIPC_AccPedStkActv_flg;/* '<S378>/Logical Operator6' */
extern MONPRM volatile boolean VIPC_AccPedStkBrkPrsd_flg;/* '<S405>/Switch4' */
extern MONPRM volatile float32 VIPC_AccPedStkPstn_pct;/* '<S378>/MinMax' */
extern MONPRM volatile boolean VIPC_AccPedStkStab_flg;/* '<S407>/Relational Operator' */
extern MONPRM volatile float32 VIPC_AccPedWghtAvg_pct;/* '<S404>/Switch' */
extern MONPRM volatile float32 VIPC_AccPedWghtPstn_pct;/* '<S379>/Switch3' */
extern MONPRM volatile float32 VIPC_AccPedZeroPstn_pct;/* '<S378>/Switch2' */
extern MONPRM volatile boolean VIPC_BrkPedPstnVld_flg;/* '<S370>/Logical Operator8' */
extern MONPRM volatile float32 VIPC_BrkPedPstn_pct;/* '<S370>/Saturation1' */
extern MONPRM volatile boolean VIPC_BrkSwActv_flg;/* '<S370>/Logical Operator' */
extern MONPRM volatile boolean VIPC_CCSCfgd_flg;/* '<S373>/Switch1' */
extern MONPRM volatile boolean VIPC_CrpCtrlCfgd_flg;/* '<S373>/Switch2' */
extern MONPRM volatile EnumCrpModeAct VIPC_CrpModeAct_enum;/* '<S372>/Switch12' */
extern MONPRM volatile EnumDrvModeAct VIPC_DrvModeAct_enum;/* '<S372>/Switch13' */
extern MONPRM volatile uint8 VIPC_DrvPwrIntnsty_pct;/* '<S372>/Switch25' */
extern MONPRM volatile boolean VIPC_DrvSw_flg;/* '<S375>/Relational Operator3' */
extern MONPRM volatile boolean VIPC_EPBAppld_flg;/* '<S371>/Logical Operator2' */
extern MONPRM volatile boolean VIPC_EPBReld_flg;/* '<S371>/Logical Operator1' */
extern MONPRM volatile boolean VIPC_HDCCfgd_flg;/* '<S373>/Switch3' */
extern MONPRM volatile EnumRegenModeAct VIPC_RegenModeAct_enum;/* '<S372>/Switch15' */
extern MONPRM volatile uint8 VIPC_RegenPwrIntnsty_pct;/* '<S372>/Switch28' */
extern MONPRM volatile boolean VIPC_SnowMode_flg;/* '<S372>/Switch14' */
extern MONPRM volatile float32 VIPC_TireRadius_m;/* '<S373>/TireSizeTable' */
extern MONPRM volatile uint8 VIPC_VehHiddenMode_enum;/* '<S372>/VehHiddenMode' */
extern MONPRM volatile float32 VIPC_VehSpdDrvnMotor_kph;/* '<S374>/Product1' */
extern MONPRM volatile boolean VIPC_VehSpdDrvnVld_flg;/* '<S441>/Logical Operator2' */
extern MONPRM volatile float32 VIPC_VehSpdDrvn_kph;/* '<S441>/Switch7' */
extern MONPRM volatile boolean VIPC_VehSpdNonDrvnVld_flg;/* '<S442>/Logical Operator2' */
extern MONPRM volatile float32 VIPC_VehSpdNonDrvn_kph;/* '<S442>/Switch7' */
extern MONPRM volatile boolean VIPC_VehSpdVld_flg;/* '<S441>/SignalConversion' */
extern MONPRM volatile float32 VIPC_VehSpd_kph;/* '<S441>/Switch4' */
extern MONPRM volatile boolean VIPC_VpedAutoCrp_flg;/* '<S429>/Switch4' */
extern MONPRM volatile boolean VIPC_ZeroPstnRst_flg;/* '<S378>/Logical Operator3' */
extern MONPRM volatile boolean VIPC_iTPMSCfgd_flg;/* '<S373>/Switch4' */
extern MONPRM volatile float32 VIPM_HwAccPedCh1SuplyVolt_mV;/* '<S18>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh1Volt_mV;/* '<S19>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh2SuplyVolt_mV;/* '<S20>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwAccPedCh2Volt_mV;/* '<S21>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwBMSWakeup_flg;/* '<S22>/Switch4' */
extern MONPRM volatile boolean VIPM_HwBrkSwHi_flg;/* '<S23>/Switch4' */
extern MONPRM volatile boolean VIPM_HwBrkSwLo_flg;/* '<S24>/Switch4' */
extern MONPRM volatile boolean VIPM_HwCrpModeSw_flg;/* '<S25>/Switch4' */
extern MONPRM volatile boolean VIPM_HwDrvModeSw_flg;/* '<S26>/Switch4' */
extern MONPRM volatile boolean VIPM_HwEmgcyShutOff_flg;/* '<S27>/Switch4' */
extern MONPRM volatile float32 VIPM_HwHVIL1Volt_mV;/* '<S28>/MinMax1' */
extern MONPRM volatile float32 VIPM_HwHVIL2Volt_mV;/* '<S29>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwKL15A_flg;/* '<S30>/Switch4' */
extern MONPRM volatile boolean VIPM_HwKL15B_flg;/* '<S31>/Switch4' */
extern MONPRM volatile uint16 VIPM_HwKL30_mV;/* '<S32>/MinMax1' */
extern MONPRM volatile boolean VIPM_HwOBCWakeup_flg;/* '<S33>/Switch4' */
extern MONPRM volatile boolean VIPM_HwRearFogLampSwt_flg;/* '<S34>/Switch4' */
extern MONPRM volatile EnumPGearSwSts VIPM_HwShftPstnSwSts_enum;/* '<S35>/Switch4' */
extern MONPRM volatile uint16 VIPM_HwShftPstnSw_Ohm;/* '<S8>/HwShftPstnSw' */
extern MONPRM volatile boolean VIPM_HwVehCrash_flg;/* '<S36>/Switch4' */
extern MONPRM volatile uint8 VNVM_ACChrgMaxCurrFb_A;/* '<S9>/Selector18' */
extern MONPRM volatile uint8 VNVM_ACChrgModeFb_enum;/* '<S9>/Selector19' */
extern MONPRM volatile uint8 VNVM_AccPedZeroPstn_pct;/* '<S9>/Selector24' */
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
extern MONPRM volatile boolean VOPM_HwWakeupBMS_flg;/* '<S50>/Switch4' */
extern MONPRM volatile float32 VRME_AvgSOCCnsm100Num_pctpkm;/* '<S244>/Signal Copy5' */

/* ǰ100������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm10Num_pctpkm;/* '<S244>/Signal Copy1' */

/* ǰ10������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm15Num_pctpkm;/* '<S244>/Signal Copy2' */

/* ǰ15������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm25Num_pctpkm;/* '<S244>/Signal Copy3' */

/* ǰ25������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm50Num_pctpkm;/* '<S244>/Signal Copy4' */

/* ǰ50������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsm5Num_pctpkm;/* '<S244>/Signal Copy' */

/* ǰ5������ƽ��SOC�ܺ� */
extern MONPRM volatile float32 VRME_AvgSOCCnsmWght_pctpkm;/* '<S244>/Switch1' */

/* ��Ȩƽ��SOC�ܺ� */
extern MONPRM volatile boolean VRME_CHTCRmnMilEstV_flg;/* '<S210>/Logical Operator' */

/* CHTC��׼���������Ч�� */
extern MONPRM volatile float32 VRME_CHTCRmnMilEst_km;/* '<S210>/MRME_CHTCStdRmnMil_km' */

/* CHTC��׼�������ֵ */
extern MONPRM volatile float32 VRME_CalPwrCnsmPerTrig_kWhptrig;/* '<S214>/Switch4' */

/* Pwr����/��λ��̣�trig�� */
extern MONPRM volatile boolean VRME_CalPwrCnsmTrig_flg;/* '<S214>/Relational Operator1' */

/* �ۼ���̴��ڵ�λ��� */
extern MONPRM volatile float32 VRME_CalSOCCnsmDrvDist_m;/* '<S243>/Switch1' */

/* ��λĿ����ʻ��� */
extern MONPRM volatile float32 VRME_CalSOCCnsmPerTrig_pctptrig;/* '<S243>/Switch4' */

/* SOC����/��λ��̣�trig�� */
extern MONPRM volatile float32 VRME_CalSOCCnsmPerkm_pctpkm;/* '<S243>/Divide' */

/* SOC����/��λ��̣�1km�� */
extern MONPRM volatile boolean VRME_CalSOCCnsmTrig_flg;/* '<S243>/Relational Operator1' */

/* �ۼ���̴���Ŀ����� */
extern MONPRM volatile float32 VRME_ChrgRmnMilEstTgt_km;/* '<S239>/Switch2' */

/* ���ģʽ��̬����Ŀ��ֵ */
extern MONPRM volatile float32 VRME_ChrgRmnMilEst_km;/* '<S223>/Different Slops' */

/* ��繤����̬����ֵ */
extern MONPRM volatile float32 VRME_ChrgTgtFstRate_kmpsoc;/* '<S223>/Divide2' */

/* ��繤��Ŀ������׷������ */
extern MONPRM volatile float32 VRME_ChrgTgtNormRate_kmpsoc;/* '<S223>/Divide1' */

/* ��繤��Ŀ�������仯���� */
extern MONPRM volatile float32 VRME_DchaRmnMilEstChgFac_c;/* '<S242>/MRME_DynEstRmnChgStp_c' */

/* �ǳ��ģʽ��̬�����仯ϵ�� */
extern MONPRM volatile float32 VRME_DchaRmnMilEstTgt_km;/* '<S251>/Switch2' */

/* �ǳ��ģʽ��̬����Ŀ��ֵ */
extern MONPRM volatile boolean VRME_DchaRmnMilEstUpdTrig_flg;/* '<S242>/Relational Operator2' */

/* ��������ֵ */
extern MONPRM volatile float32 VRME_DchaRmnMilEst_km;/* '<S242>/Signal Copy1' */

/* �ǳ��ģʽ��̬����ֵ */
extern MONPRM volatile boolean VRME_DchaVehStall_flg;/* '<S241>/Logical Operator4' */

/* �ǳ��ģʽ����פ��״̬ */
extern MONPRM volatile boolean VRME_DynRmnMilEstV_flg;/* '<S212>/Logical Operator1' */

/* ��̬������Ч�� */
extern MONPRM volatile float32 VRME_VehPwrCnsmAvg_kWhpkm;/* '<S214>/Switch7' */

/* ��ǰѭ��ƽ���ܺ� */
extern MONPRM volatile float32 VRME_VehPwrCnsmIns_kWhpkm;/* '<S214>/Divide' */

/* ��ǰѭ��˲���ܺ� */
extern MONPRM volatile float32 VRME_VehTotMilCyc_km;/* '<S214>/Gain8' */

/* ��ǰ��ʻѭ��������� */
extern MONPRM volatile float32 VRME_VehTotPwrCyc_kWh;/* '<S214>/Switch8' */

/* ��ǰ��ʻѭ���������� */
extern MONPRM volatile float32 VRME_WLTPRmnMilEstDwLim_km;/* '<S219>/Product3' */

/* ��̬��������ֵ */
extern MONPRM volatile float32 VRME_WLTPRmnMilEstUpLim_km;/* '<S219>/Product2' */

/* ��̬��������ֵ */
extern MONPRM volatile float32 VRME_WLTPRmnMilEst_km;/* '<S219>/MRME_WLTPStdRmnMil_km' */

/* WLTP��׼�������ֵ */
extern MONPRM volatile float32 VRME_WLTPStdPwrCnsm_kWhpkm;/* '<S214>/Gain5' */

/* ��׼������ģ�kWh/km�� */
extern MONPRM volatile float32 VRME_WLTPStdSOCCnsm_pctpkm;/* '<S243>/Gain3' */

/* ��׼������SOC����/km */
extern MONPRM volatile boolean VTBX_CnclSpdLim_flg;/* '<S323>/Logical Operator12' */

/* TBOX������� */
extern MONPRM volatile boolean VTBX_LckVer_flg;/* '<S345>/Chart' */

/* �����汾 */
extern MONPRM volatile boolean VTBX_RecryTBOXHw_flg;/* '<S323>/Logical Operator14' */

/* TBOXӲ��ͨѶ��ʧ�ָ� */
extern MONPRM volatile boolean VTBX_ReqLimpHome_flg;/* '<S322>/Data Type Conversion6' */

/* VCU�������ж��� */
extern MONPRM volatile boolean VTBX_RmvTBOXHw_flg;/* '<S323>/Logical Operator3' */

/* TBOXӲ��ͨѶ��ʧ */
extern MONPRM volatile boolean VTBX_SpdLimLvl1_flg;/* '<S323>/Logical Operator5' */

/* TBOXһ������ */
extern MONPRM volatile boolean VTBX_SpdLimLvl2_flg;/* '<S323>/Logical Operator7' */

/* TBOX�������� */
extern MONPRM volatile boolean VTBX_SpdLimLvl3_flg;/* '<S323>/Logical Operator9' */

/* TBOX�������� */
extern MONPRM volatile boolean VTBX_StorgSpdLim_flg;/* '<S323>/Logical Operator11' */

/* TBOX������� */
extern MONPRM volatile boolean VTBX_TBOXOffline_flg;/* '<S322>/Signal Copy3' */

/* TBOXӲ��״̬-ʵʱ�洢 */
extern MONPRM volatile boolean VTBX_UnlckVer_flg;/* '<S344>/Chart' */

/* �������汾 */
extern MONPRM volatile boolean VTBX_VCUChrgngCondsFb_flg;/* '<S322>/Data Type Conversion5' */

/* VCU�����жϳ������ */
extern MONPRM volatile uint8 VTBX_VCULckVehWrn_enum;/* '<S322>/Signal Copy5' */

/* VCU������������ */
extern MONPRM volatile boolean VTBX_VCUOprtLicFb_flg;/* '<S322>/Data Type Conversion4' */

/* VCU������Ӫ״̬ */
extern MONPRM volatile EnumTBOXLimGrd VTBX_VCUSpdLimLvlFb_enum;/* '<S322>/Data Type Conversion3' */

/* VCU�������ٵȼ�-��ǰ��ʻѭ�� */
extern MONPRM volatile uint8 VTBX_VCUSpdLimLvlSetFb_enum;/* '<S322>/Data Type Conversion7' */

/* VCU�������ٵȼ����óɹ� */
extern MONPRM volatile EnumTBOXLimSt VTBX_VCUSpdLimSt_enum;/* '<S322>/Data Type Conversion1' */

/* ��ǰѭ������״̬-ʵʱ�洢 */
extern MONPRM volatile boolean VTBX_VCUVerFb_flg;/* '<S322>/Signal Copy' */

/* VCU���������汾-ʵʱ�洢 */
extern MONPRM volatile uint8 VTBX_VCUVerSetFb_enum;/* '<S322>/Signal Copy1' */

/* VCU���������汾���óɹ� */
extern MONPRM volatile float32 VTQC_ABSorESPActvTm_s;/* '<S711>/MinMax' */
extern MONPRM volatile float32 VTQC_BrkRegenMaxTqWhl_Nm;/* '<S706>/Switch17' */
extern MONPRM volatile float32 VTQC_BrkRegenTgtTqWhl_Nm;/* '<S706>/Switch2' */
extern MONPRM volatile float32 VTQC_CstRegenLmtTq_Nm;/* '<S704>/CstRegenLmtTq' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhlABS_Nm;/* '<S704>/MinMax1' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhlRBS_Nm;/* '<S713>/MinMax5' */
extern MONPRM volatile float32 VTQC_DrvTqReqWhl_Nm;/* '<S705>/Switch5' */
extern MONPRM volatile float32 VTQC_MotorTqReq_Nm;/* '<S705>/Divide' */
extern MONPRM volatile boolean VTQC_RBSActv_flg;/* '<S714>/Switch4' */
extern MONPRM volatile float32 VTQD_AccelPedPstnRescl_pct;/* '<S725>/Product' */
extern MONPRM volatile float32 VTQD_AdaptCstDeltaAcceltn_mps2;/* '<S741>/Add5' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqFF_Nm;/* '<S741>/Add2' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqI_N;/* '<S741>/Saturation2' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqPID_Nm;/* '<S741>/Product6' */
extern MONPRM volatile float32 VTQD_AdaptCstDsrdTqP_N;/* '<S741>/Product3' */
extern MONPRM volatile float32 VTQD_AdaptCstMaxTqWhl_Nm;/* '<S737>/MinMax4' */
extern MONPRM volatile float32 VTQD_AdaptCstMinTqWhl_Nm;/* '<S737>/MinMax5' */
extern MONPRM volatile boolean VTQD_AdaptCstRegenEnbl_flg;/* '<S737>/Logical Operator9' */
extern MONPRM volatile float32 VTQD_AdaptCstTgtAcceltn_mps2;/* '<S743>/Switch' */
extern MONPRM volatile float32 VTQD_AdaptCstTqReqWhl_Nm;/* '<S741>/MinMax6' */
extern MONPRM volatile boolean VTQD_BkwdDrv_flg;/* '<S764>/Switch4' */
extern MONPRM volatile boolean VTQD_BrkRegenEnbl_flg;/* '<S736>/Logical Operator1' */
extern MONPRM volatile float32 VTQD_CrpTqReqWhl_Nm;/* '<S727>/Switch2' */
extern MONPRM volatile boolean VTQD_CstRegenEnbl_flg;/* '<S736>/Logical Operator13' */
extern MONPRM volatile float32 VTQD_CstRegenEndPstn_pct;/* '<S736>/Switch2' */
extern MONPRM volatile float32 VTQD_CstRegenTqReqWhl_Nm;/* '<S738>/Switch4' */
extern MONPRM volatile float32 VTQD_DrvTqDrtFac_c;/* '<S765>/Saturation' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhlMrg_Nm;/* '<S766>/Switch4' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhlRaw_Nm;/* '<S725>/Merge' */
extern MONPRM volatile float32 VTQD_DrvTqReqWhl_Nm;/* '<S723>/Switch3' */
extern MONPRM volatile boolean VTQD_DsblCrp_flg;/* '<S727>/Logical Operator12' */
extern MONPRM volatile float32 VTQD_FullPedDrvTqWhl_Nm;/* '<S725>/Signal Conversion1' */
extern MONPRM volatile float32 VTQD_FwdPedMap_pct;/* '<S728>/Switch9' */
extern MONPRM volatile float32 VTQD_PedalTqReqWhlRaw_Nm;/* '<S722>/Add' */
extern MONPRM volatile uint16 VTQD_TaskRunCounter_cnt;/* '<S555>/Max1' */

/* test signal, to be deleted */
extern MONPRM volatile boolean VTQD_TqZeroFast_flg;/* '<S757>/Logical Operator4' */
extern MONPRM volatile boolean VTQD_TqZeroSlow_flg;/* '<S757>/Logical Operator2' */
extern MONPRM volatile boolean VTQD_TqZero_flg;/* '<S757>/Logical Operator1' */
extern MONPRM volatile float32 VTQF_DrvTqReqWhl_Nm;/* '<S782>/Switch2' */
extern MONPRM volatile float32 VTQF_TipOutTqDecRateCoeff_rat;/* '<S784>/1-D Lookup Table1' */
extern MONPRM volatile boolean VTQF_TqInc_flg;/* '<S794>/Switch4' */
extern MONPRM volatile float32 VTQF_TqOutChgRate_Nmps;/* '<S804>/Switch' */
extern MONPRM volatile float32 VTQF_TqRateDecTgtMax_Nmps;/* '<S784>/Switch3' */
extern MONPRM volatile float32 VTQF_TqRateDecTgtMin_Nmps;/* '<S784>/MinMax4' */
extern MONPRM volatile float32 VTQF_TqRateIncTgtMax_Nmps;/* '<S785>/Switch5' */
extern MONPRM volatile float32 VTQF_TqRateIncTgtMin_Nmps;/* '<S785>/MinMax4' */
extern MONPRM volatile float32 VTQF_TqRateLimDec_Nmps;/* '<S784>/MinMax3' */
extern MONPRM volatile boolean VTQF_TqRateLimEndg_flg;/* '<S783>/Logical Operator9' */
extern MONPRM volatile float32 VTQF_TqRateLimInc_Nmps;/* '<S785>/MinMax2' */
extern MONPRM volatile float32 VTQF_TqRawChgRate_Nmps;/* '<S803>/Switch' */
extern MONPRM volatile float32 VTQF_WhlDrgMaxTqZX_Nm;/* '<S802>/Switch1' */
extern MONPRM volatile float32 VTQF_WhlDrvMaxTqZX_Nm;/* '<S802>/Switch7' */
extern MONPRM volatile boolean VTQR_ASDEnbl_flg;/* '<S807>/Logical Operator14' */
extern MONPRM volatile float32 VTQR_ASDSpdFltHi_rpm;/* '<S815>/Switch' */
extern MONPRM volatile float32 VTQR_ASDSpdOscRaw_rpm;/* '<S811>/Add1' */
extern MONPRM volatile float32 VTQR_ASDSpdOsc_rpm;/* '<S813>/Multiport Switch' */
extern MONPRM volatile float32 VTQR_ASDTqReqRaw_Nm;/* '<S819>/MinMax5' */
extern MONPRM volatile float32 VTQR_ASDTqReq_Nm;/* '<S812>/Switch3' */
extern MONPRM volatile boolean VTQR_MotDampngEnbl_flg;/* '<S807>/Logical Operator1' */
extern MONPRM volatile float32 VTQR_MotDampngLmt_Nm;/* '<S827>/MinMax5' */
extern MONPRM volatile EnumMotorDirReq VTQR_MotorDirReq_enum;/* '<S808>/Switch4' */
extern MONPRM volatile EnumMotorModeReq VTQR_MotorModeReq_enum;/* '<S805>/Signal Conversion15' */
extern MONPRM volatile float32 VTQR_MotorSpdReq_rpm;/* '<S805>/Signal Conversion1' */
extern MONPRM volatile boolean VTQR_MotorStdby_flg;/* '<S809>/Logical Operator1' */
extern MONPRM volatile float32 VTQR_MotorTqReq_Nm;/* '<S805>/Signal Conversion2' */
extern MONPRM volatile float32 VTZX_AZDecRate_Nmps;/* '<S843>/1-D Lookup Table4' */
extern MONPRM volatile float32 VTZX_AZIncRate_Nmps;/* '<S843>/1-D Lookup Table3' */
extern MONPRM volatile float32 VTZX_BZDecRate_Nmps;/* '<S843>/1-D Lookup Table2' */
extern MONPRM volatile float32 VTZX_BZIncRate_Nmps;/* '<S843>/1-D Lookup Table1' */
extern MONPRM volatile boolean VTZX_BypZX_flg;/* '<S847>/Logical Operator1' */
extern MONPRM volatile boolean VTZX_ClkActv_flg;/* '<S846>/Switch4' */
extern MONPRM volatile float32 VTZX_ClkZXTm_s;/* '<S839>/Switch1' */
extern MONPRM volatile float32 VTZX_MotorTqReqPrdt_Nm;/* '<S859>/MinMax5' */
extern MONPRM volatile float32 VTZX_MotorTqReqZX_Nm;/* '<S844>/TqZXSt' */
extern MONPRM volatile float32 VTZX_MotorTqReq_Nm;/* '<S839>/Switch6' */
extern MONPRM volatile boolean VTZX_TqInc_flg;/* '<S853>/Switch4' */
extern MONPRM volatile boolean VTZX_TqRateLimRamp_flg;/* '<S860>/Switch4' */
extern MONPRM volatile EnumTZXStat VTZX_TqZXSt_enum;/* '<S844>/Data Type Conversion1' */
extern MONPRM volatile float32 VTZX_ZeroTqHldDec_Nm;/* '<S844>/TqZXSt' */
extern MONPRM volatile float32 VTZX_ZeroTqHldInc_Nm;/* '<S844>/TqZXSt' */
extern MONPRM volatile float32 VTZX_ZeroTqOfstDec_Nm;/* '<S843>/Switch3' */
extern MONPRM volatile float32 VTZX_ZeroTqOfstInc_Nm;/* '<S843>/Switch2' */
extern MONPRM volatile float32 VTZX_ZeroTqOfst_Nm;/* '<S843>/Switch4' */
extern MONPRM volatile float32 VTZX_ZeroXTm_s;/* '<S843>/Switch8' */
extern MONPRM volatile uint8 VVCU_ECURstCntr_cnt;/* '<S47>/Switch2' */

/* ������Reset������ */
extern MONPRM volatile float32 VVSO_ALatSnsr_mps2;/* '<S459>/Switch1' */
extern MONPRM volatile float32 VVSO_ALgtSnsr_mps2;/* '<S458>/Switch1' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr1_mpkm;/* '<S520>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr2_mpkm;/* '<S520>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr3_mpkm;/* '<S520>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr4_mpkm;/* '<S520>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr5_mpkm;/* '<S520>/WhlDistErrRec' */
extern MONPRM volatile float32 VVSO_AvgXWhlDistErr_mpkm;/* '<S520>/Add3' */
extern MONPRM volatile float32 VVSO_DrvDist_m;/* '<S533>/Switch1' */
extern MONPRM volatile boolean VVSO_RSEBrkPresrConf_flg;/* '<S505>/Relational Operator2' */
extern MONPRM volatile boolean VVSO_RSESigConf_flg;/* '<S491>/Logical Operator3' */
extern MONPRM volatile boolean VVSO_RSEVehSpdConf_flg;/* '<S507>/Logical Operator2' */
extern MONPRM volatile boolean VVSO_RSEWhlSlipConf_flg;/* '<S508>/Logical Operator2' */
extern MONPRM volatile boolean VVSO_RSEYawRateConf_flg;/* '<S509>/Logical Operator' */
extern MONPRM volatile float32 VVSO_RoadSlopCalcRaw_pct;/* '<S489>/Product19' */
extern MONPRM volatile boolean VVSO_RoadSlopEstVld_flg;/* '<S488>/Logical Operator1' */
extern MONPRM volatile float32 VVSO_RoadSlopEst_pct;/* '<S488>/Switch2' */
extern MONPRM volatile float32 VVSO_RoadSlopTqEst_Nm;/* '<S504>/MinMax5' */
extern MONPRM volatile float32 VVSO_VehDrvResistTq_Nm;/* '<S490>/Switch5' */
extern MONPRM volatile boolean VVSO_VehMassConf_flg;/* '<S536>/Logical Operator4' */
extern MONPRM volatile uint8 VVSO_VehMassDistb_enum;/* '<S536>/Signal Conversion' */
extern MONPRM volatile float32 VVSO_VehMassEst_kg;/* '<S539>/Switch' */
extern MONPRM volatile float32 VVSO_VehSpd_mps;/* '<S536>/Gain3' */
extern MONPRM volatile float32 VVSO_WhlAcceltnFL_mps2;/* '<S471>/Divide' */
extern MONPRM volatile float32 VVSO_WhlAcceltnFR_mps2;/* '<S472>/Divide' */
extern MONPRM volatile float32 VVSO_WhlAcceltnRL_mps2;/* '<S473>/Divide' */
extern MONPRM volatile float32 VVSO_WhlAcceltnRR_mps2;/* '<S474>/Divide' */
extern MONPRM volatile boolean VVSO_WhlDistErrHld_flg;/* '<S524>/OR' */
extern MONPRM volatile float32 VVSO_WhlLgtFrc_N;/* '<S541>/Add' */
extern MONPRM volatile EnumXWhlDistErrRefSt VVSO_XWhlDistErrRefStat_enum;/* '<S520>/Signal Conversion2' */
extern MONPRM volatile float32 VVSO_XWhlDistErrRef_mpkm;/* '<S520>/Signal Conversion1' */
extern MONPRM volatile float32 VVSO_XWhlDistErr_m;/* '<S533>/Switch4' */
extern MONPRM volatile float32 VVSO_YawRateBas_degps;/* '<S465>/Switch' */
extern MONPRM volatile float32 VVSO_YawRateDer_radps2;/* '<S460>/Add6' */
extern MONPRM volatile float32 VVSO_YawRateFilt_radps;/* '<S464>/Switch' */
extern MONPRM volatile boolean VVSO_iTPMSAvail_flg;/* '<S524>/Logical Operator' */
extern MONPRM volatile EnumiTPMSSt VVSO_iTPMSState_enum;/* '<S520>/Signal Conversion' */
extern MONPRM volatile boolean VVSO_iTPMSWrng_flg;/* '<S520>/Signal Conversion3' */
extern MONPRM volatile boolean VVTM_BrkPedReld_flg;/* '<S885>/Logical Operator3' */
extern MONPRM volatile uint8 VVTM_DrvMotorSta_enum;/* '<S892>/DriveMotorState' */
extern MONPRM volatile boolean VVTM_ESPIntvActv_flg;/* '<S885>/Logical Operator4' */
extern MONPRM volatile float32 VVTM_MotorActPwr_kW;/* '<S899>/Switch2' */
extern MONPRM volatile float32 VVTM_MotorSpd_rpm;/* '<S887>/Switch' */
extern MONPRM volatile boolean VVTM_RegenReqBrkLampOn_flg;/* '<S897>/Switch1' */
extern MONPRM volatile float32 VVTM_RsrvPwr_kW;/* '<S894>/MinMax4' */
extern MONPRM volatile float32 VVTM_RsrvRecupPwr_kW;/* '<S894>/MinMax1' */
extern MONPRM volatile float32 VVTM_VehAcceltn_mps2;/* '<S890>/Switch' */
extern MONPRM volatile uint8 VVTM_VehActGrPstn_enum;/* '<S885>/Switch1' */
extern MONPRM volatile float32 VVTM_VehSpd_kph;/* '<S886>/Switch' */

#endif                                 /* RTW_HEADER_monPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
