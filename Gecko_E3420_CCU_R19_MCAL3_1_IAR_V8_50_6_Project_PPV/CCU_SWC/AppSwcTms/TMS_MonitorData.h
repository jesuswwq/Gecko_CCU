/*
 * File: TMS_MonitorData.h
 *
 * Code generated for Simulink model 'ME11'.
 *
 * Model version                  : 1.2248
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Oct 22 11:28:48 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TMS_MonitorData_h_
#define RTW_HEADER_TMS_MonitorData_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "ME11_types.h"

/* Exported data declaration */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Declaration for custom storage class: TMS_MonitorData */
extern MONPRM volatile float32 ACCCtl_sACCabinPreSetByEnv;/* '<S186>/cal_ACCabinPreSetByEnv_MAP' */
extern MONPRM volatile float32 ACCCtl_sACCabinPreSetByEnvECO;
                                    /* '<S186>/cal_ACCabinPreSetByEnvECO_MAP' */
extern MONPRM volatile float32 ACCCtl_sBlowerFanSpd;/* '<S57>/MinMax' */
extern MONPRM volatile float32 ACCCtl_sSetPtcDesTempMax;/* '<S180>/cal_SetPtcDesTempMax_MAP' */
extern MONPRM volatile uint8 ACCtl_BloweFanSpeed;/* '<S43>/Merge' */
extern MONPRM volatile BlowerModes ACCtl_BlowerMode;/* '<S44>/Merge' */
extern MONPRM volatile float32 ACCtl_DVTIDeadBand;/* '<S188>/Constant7' */
extern MONPRM volatile float32 ACCtl_DrfacPtc2NominalTemp;/* '<S392>/Switch4' */
extern MONPRM volatile uint8 ACCtl_IntakeRatio;/* '<S48>/Merge' */
extern MONPRM volatile float32 ACCtl_PsfacPtc2NominalTemp;/* '<S418>/Switch4' */
extern MONPRM volatile float32 ACCtl_RFace2FaceFloor;
                                      /* '<S81>/cal_RFace2FaceFloorByEnv_CUR' */
extern MONPRM volatile float32 ACCtl_RFaceFloor2Face;
                                      /* '<S81>/cal_RFaceFloor2FaceByEnv_CUR' */
extern MONPRM volatile float32 ACCtl_RFaceFloor2Floor;
                                     /* '<S81>/cal_RFaceFloor2FloorByEnv_CUR' */
extern MONPRM volatile float32 ACCtl_RFloor2FaceFloor;
                                     /* '<S81>/cal_RFloor2FaceFloorByEnv_CUR' */
extern MONPRM volatile boolean ACCtl_bExhFlg;/* '<S1086>/Switch' */
extern MONPRM volatile boolean ACCtl_bExhaustFlg;/* '<S11>/AND2' */
extern MONPRM volatile uint16 ACCtl_pwrHeatingFeed;/* '<S95>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern MONPRM volatile float32 ACCtl_pwrHeatingICor;/* '<S106>/Merge1' */
extern MONPRM volatile float32 ACCtl_pwrHeatingISum;/* '<S102>/Switch1' */
extern MONPRM volatile float32 ACCtl_pwrHeatingPCor;/* '<S105>/Merge' */
extern MONPRM volatile uint16 ACCtl_pwrHeatingReq;/* '<S39>/Signal Copy' */
extern MONPRM volatile uint8 ACCtl_rDrBasicMixDoor;/* '<S390>/Switch6' */
extern MONPRM volatile uint8 ACCtl_rDrMixDoorDes;/* '<S391>/Data Type Conversion' */
extern MONPRM volatile float32 ACCtl_rDrSetMixDoorICor;/* '<S401>/Merge1' */
extern MONPRM volatile float32 ACCtl_rDrSetMixDoorISum;/* '<S397>/Switch1' */
extern MONPRM volatile float32 ACCtl_rDrSetMixDoorPCor;/* '<S400>/Merge' */
extern MONPRM volatile uint8 ACCtl_rPsBasicMixDoor;/* '<S416>/Switch6' */
extern MONPRM volatile float32 ACCtl_rPsBlowerModeSet;/* '<S416>/Multiport Switch2' */
extern MONPRM volatile uint8 ACCtl_rPsMixDoorDes;/* '<S417>/Data Type Conversion' */
extern MONPRM volatile float32 ACCtl_rPsSetMixDoorICor;/* '<S425>/Merge1' */
extern MONPRM volatile float32 ACCtl_rPsSetMixDoorISum;/* '<S421>/Switch1' */
extern MONPRM volatile float32 ACCtl_rPsSetMixDoorPCor;/* '<S424>/Merge' */
extern MONPRM volatile float32 ACCtl_sECOEvaDesValLL;/* '<S179>/cal_ECOEvaDesValLL_MAP' */
extern MONPRM volatile float32 ACCtl_sMixDoorClsFF;/* '<S391>/Switch' */
extern MONPRM volatile boolean ACCtl_stACPTCHeated;/* '<S180>/PTCHeatedCheck' */
extern MONPRM volatile boolean ACCtl_stCabinCoolingEn;/* '<S45>/Merge' */
extern MONPRM volatile boolean ACCtl_stCabinHeatingEn;/* '<S94>/Logical Operator' */
extern MONPRM volatile uint8 ACCtl_stDvtPIDFreez;/* '<S191>/Merge' */
extern MONPRM volatile boolean ACCtl_stEvaCooledFlag;/* '<S179>/EvaCooledCheck' */
extern MONPRM volatile boolean ACCtl_stRecACHotStartEna;/* '<S127>/Relational Operator5' */
extern MONPRM volatile boolean ACCtl_stRecAQSEna;/* '<S128>/Recirc_AQS' */
extern MONPRM volatile boolean ACCtl_stRecForceChangeEna;/* '<S129>/Switch3' */
extern MONPRM volatile boolean ACCtl_stRecForceDefogEna;/* '<S130>/Relational Operator' */
extern MONPRM volatile uint8 ACCtl_stRecLevelFinal;/* '<S39>/Max' */
extern MONPRM volatile boolean ACCtl_stRecManualEna;/* '<S126>/Logical Operator' */
extern MONPRM volatile boolean ACCtl_stRecNormalDefogEna;/* '<S131>/Logical Operator' */
extern MONPRM volatile boolean ACCtl_stRecOut;/* '<S48>/Merge' */
extern MONPRM volatile boolean ACCtl_stRecPCUTempEna;/* '<S132>/Switch' */
extern MONPRM volatile boolean ACCtl_stRecPTCDvtEna;/* '<S133>/Switch1' */
extern MONPRM volatile boolean ACCtl_stRecQkChargeCoolingEna;/* '<S134>/Logical Operator' */
extern MONPRM volatile boolean ACCtl_stRecRemoteACEna;/* '<S135>/Relational Operator3' */
extern MONPRM volatile boolean ACCtl_stRecSummerCondEna;/* '<S136>/Relational Operator4' */
extern MONPRM volatile boolean ACCtl_stRecTargetOutTempEna;/* '<S137>/Switch1' */
extern MONPRM volatile boolean ACCtl_stRecTempLowEna;/* '<S36>/OR' */
extern MONPRM volatile boolean ACCtl_stRecVentEna;/* '<S139>/Logical Operator2' */
extern MONPRM volatile boolean ACCtl_stRecWinterCondEna;/* '<S140>/Relational Operator4' */
extern MONPRM volatile uint8 ACCtl_stStartState;/* '<S40>/AirConditionStartState' */
extern MONPRM volatile float32 ACCtl_tDVTFeedfoward;/* '<S209>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDVTFlt;/* '<S59>/Add' */
extern MONPRM volatile float32 ACCtl_tDVTPIBas;/* '<S191>/Merge' */
extern MONPRM volatile float32 ACCtl_tDesFrontCabin;/* '<S186>/Switch3' */
extern MONPRM volatile float32 ACCtl_tDrDVT;/* '<S182>/Switch3' */
extern MONPRM volatile float32 ACCtl_tDrDVTSolarCor;/* '<S182>/cal_ACDrDVTSolarCor_MAP' */
extern MONPRM volatile float32 ACCtl_tDrEvapDes;/* '<S284>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDrEvapDesPI;/* '<S287>/Merge' */
extern MONPRM volatile float32 ACCtl_tDrEvapICor;/* '<S290>/Merge1' */
extern MONPRM volatile float32 ACCtl_tDrEvapISum;/* '<S285>/Switch1' */
extern MONPRM volatile float32 ACCtl_tDrEvapPCor;/* '<S289>/Merge' */
extern MONPRM volatile float32 ACCtl_tDrPTCICor;/* '<S349>/Merge1' */
extern MONPRM volatile float32 ACCtl_tDrPTCISum;/* '<S345>/Switch1' */
extern MONPRM volatile float32 ACCtl_tDrPTCPCor;/* '<S348>/Merge' */
extern MONPRM volatile float32 ACCtl_tDrSetBasicEvap;/* '<S306>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDrSetBasicPTC;/* '<S344>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDvtICor;/* '<S193>/Merge1' */
extern MONPRM volatile float32 ACCtl_tDvtISum;/* '<S189>/Switch1' */
extern MONPRM volatile float32 ACCtl_tDvtPCor;/* '<S192>/Merge' */
extern MONPRM volatile float32 ACCtl_tErrACPTC;/* '<S103>/Switch1' */
extern MONPRM volatile boolean ACCtl_tErrACPTCPosFlag;/* '<S103>/Relational Operator' */
extern MONPRM volatile float32 ACCtl_tErrDVT;/* '<S190>/Switch1' */
extern MONPRM volatile boolean ACCtl_tErrDVTFlag;/* '<S190>/Relational Operator' */
extern MONPRM volatile float32 ACCtl_tErrDrDVT2Duct;/* '<S286>/Switch1' */
extern MONPRM volatile float32 ACCtl_tErrPsDVT2Duct;/* '<S312>/Switch1' */
extern MONPRM volatile float32 ACCtl_tLeftDuct;/* '<S176>/Switch' */
extern MONPRM volatile float32 ACCtl_tPsDVT;/* '<S183>/Switch1' */
extern MONPRM volatile float32 ACCtl_tPsDVTCabinCor;/* '<S183>/cal_ACPsDVTSetCorByEnv_MAP' */
extern MONPRM volatile float32 ACCtl_tPsDVTSolarCor;/* '<S183>/cal_ACPsDVTSolarCor_MAP' */
extern MONPRM volatile float32 ACCtl_tPsEvapDes;/* '<S309>/Switch2' */
extern MONPRM volatile float32 ACCtl_tPsEvapDesPI;/* '<S313>/Merge' */
extern MONPRM volatile float32 ACCtl_tPsEvapICor;/* '<S316>/Merge1' */
extern MONPRM volatile float32 ACCtl_tPsEvapISum;/* '<S311>/Switch1' */
extern MONPRM volatile float32 ACCtl_tPsEvapPCor;/* '<S314>/Merge' */
extern MONPRM volatile float32 ACCtl_tPsPTCICor;/* '<S371>/Merge1' */
extern MONPRM volatile float32 ACCtl_tPsPTCISum;/* '<S367>/Switch1' */
extern MONPRM volatile float32 ACCtl_tPsPTCPCor;/* '<S370>/Merge' */
extern MONPRM volatile float32 ACCtl_tPsSetBasicEvap;/* '<S331>/Switch2' */
extern MONPRM volatile float32 ACCtl_tPsSetBasicPTC;/* '<S366>/Switch2' */
extern MONPRM volatile float32 ACCtl_tRightDuct;/* '<S176>/Switch1' */
extern MONPRM volatile float32 ACCtl_tRightSetPointModeCor;/* '<S186>/Sum3' */
extern MONPRM volatile float32 ACCtl_tSetPointEvap;/* '<S179>/Switch1' */
extern MONPRM volatile float32 ACCtl_tSetPointPTC;/* '<S339>/Switch2' */
extern MONPRM volatile float32 ACDVTPreSetSolarCor;
                                      /* '<S186>/cal_ACDVTPreSetSolarCor_MAP' */
extern MONPRM volatile float32 ACDVTPreSetSolarCorByVx;
                                  /* '<S186>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern MONPRM volatile float32 ACFanSpdSolarCor;/* '<S57>/cal_ACFanSpdSolarCor_MAP' */
extern MONPRM volatile float32 ACFanSpdSolarCorByEnv;
                                     /* '<S57>/cal_ACFanSpdSolarCorByEnv_MAP' */
extern MONPRM volatile boolean ACNvm_bACAutoSts;/* '<S3>/Data Type Conversion1' */
extern MONPRM volatile boolean ACNvm_bACOnOff;/* '<S3>/Data Type Conversion' */
extern MONPRM volatile uint8 ACNvm_eACCabinMode;/* '<S3>/Index Vector4' */
extern MONPRM volatile uint8 ACNvm_eCabinBlower;/* '<S3>/Index Vector5' */
extern MONPRM volatile uint8 ACNvm_eCabinSetTemp;/* '<S3>/Index Vector2' */
extern MONPRM volatile uint8 ACNvm_eCainModeDoor;/* '<S3>/Index Vector11' */
extern MONPRM volatile uint8 ACNvm_eCainRecDoor;/* '<S3>/Index Vector10' */
extern MONPRM volatile uint8 ACNvm_eUnlockVentSts;/* '<S3>/Index Vector12' */
extern MONPRM volatile float32 ACNvm_sACEnvTemp;/* '<S3>/Add' */
extern MONPRM volatile float32 ACNvm_sPCUInletTemp;/* '<S3>/Add1' */
extern MONPRM volatile float32 ACPTCDrDesCabinCor;/* '<S342>/cal_ACPTCDesCabinCor_CUR' */
extern MONPRM volatile float32 ACPTCDrDesEnvCor;/* '<S342>/cal_ACPTCDesEnvCor_MAP' */
extern MONPRM volatile float32 ACPTCDrDesFanCor;/* '<S342>/cal_ACPTCDesFanCor_CUR' */
extern MONPRM volatile float32 ACPTCPsDesCabinCor;/* '<S364>/cal_ACPTCPsDesCabinCor_CUR' */
extern MONPRM volatile float32 ACPTCPsDesEnvCor;/* '<S364>/cal_ACPTCPsDesEnvCor_MAP' */
extern MONPRM volatile float32 ACPTCPsDesFanCor;/* '<S364>/cal_ACPTCPsDesFanCor_CUR' */
extern MONPRM volatile float32 ACPTC_HeatedCond1;/* '<S180>/Add3' */
extern MONPRM volatile float32 ACPTC_HeatingCond1;/* '<S180>/Add' */
extern MONPRM volatile float32 ACPTC_HeatingCond2;/* '<S180>/Add1' */
extern MONPRM volatile float32 ACPtc_CloseCond1;/* '<S180>/Add2' */
extern MONPRM volatile float32 ACPwr_sPTCLmtPwrVal;/* '<S31>/Switch3' */
extern MONPRM volatile FaultStatus ACSen_eACCMHTSenSts;/* '<S1850>/Data Type Conversion' */
extern MONPRM volatile uint8 ACSen_eAirInletPer;/* '<S1224>/Switch' */
extern MONPRM volatile FaultStatus ACSen_eCabinSenSts;/* '<S1725>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eChillerTSenSts;/* '<S1779>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eEVAPSurfTSenSts;/* '<S1809>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eEVAPTSenSts;/* '<S1799>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eEnvSenSts;/* '<S1790>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eFaceDuctSenSts;/* '<S1748>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eFootDuctSenSts;/* '<S1758>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eLPSenSts;/* '<S1714>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eMOTORTSenSts;/* '<S1818>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eMixDoorSenSts;/* '<S1205>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eModeSenSts;/* '<S1206>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eOHXTSenSts;/* '<S1825>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eRecircSenSts;/* '<S1207>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eSOLARSenSts;/* '<S1715>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eWCCHPSenSts;/* '<S1723>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eWCCHTSenSts;/* '<S1834>/Data Type Conversion' */
extern MONPRM volatile float32 ACSen_sACCMHiTempFilter;/* '<S1851>/Switch' */
extern MONPRM volatile float32 ACSen_sCabinTempFilter;/* '<S1726>/Switch' */
extern MONPRM volatile float32 ACSen_sChiTempFilter;/* '<S1778>/Switch' */
extern MONPRM volatile float32 ACSen_sEnvTAme;/* '<S1711>/cal_EnvTAme_CUR' */
extern MONPRM volatile float32 ACSen_sEnvTempCor;/* '<S1744>/Switch' */
extern MONPRM volatile float32 ACSen_sEnvTempFilter;/* '<S1796>/Switch' */
extern MONPRM volatile float32 ACSen_sEvapSurTemp;/* '<S1810>/Switch' */
extern MONPRM volatile float32 ACSen_sEvapTempFilter;/* '<S1800>/Switch' */
extern MONPRM volatile float32 ACSen_sFaceDuctTempFilter;/* '<S1749>/Switch' */
extern MONPRM volatile float32 ACSen_sFootDuctTempFilter;/* '<S1759>/Switch' */
extern MONPRM volatile float32 ACSen_sHiPressFilter;/* '<S1844>/Switch' */
extern MONPRM volatile float32 ACSen_sLoPressFilter;/* '<S1768>/Switch' */
extern MONPRM volatile float32 ACSen_sMixDoorPerc;/* '<S1210>/Switch' */
extern MONPRM volatile float32 ACSen_sModeMotorVol;/* '<S1217>/Switch' */
extern MONPRM volatile float32 ACSen_sMotTempFilter;/* '<S1816>/Switch' */
extern MONPRM volatile float32 ACSen_sOHXTempFilter;/* '<S1826>/Switch' */
extern MONPRM volatile float32 ACSen_sPressRateVal;/* '<S505>/Switch' */
extern MONPRM volatile float32 ACSen_sWCCHiTempFilter;/* '<S1836>/Switch' */
extern MONPRM volatile boolean ACTCrl_bEnvCOMPLmt;/* '<S501>/Switch1' */
extern MONPRM volatile boolean ACTCtl_bACCMCtlEnb;/* '<S461>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAEXVDvtFlg;/* '<S683>/NOT' */
extern MONPRM volatile boolean ACTCtl_bAEXVEnb;/* '<S687>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAEXVFaultFlg;/* '<S679>/OR' */
extern MONPRM volatile boolean ACTCtl_bAEXVInitFinishFlg;/* '<S696>/Compare' */
extern MONPRM volatile uint8 ACTCtl_bAEXVInitReq;/* '<S697>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAEXVPIEnble;/* '<S674>/AND' */
extern MONPRM volatile boolean ACTCtl_bAcPMPFaultFlg;/* '<S1037>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAcPMPSpdFlt;/* '<S1023>/Switch1' */
extern MONPRM volatile boolean ACTCtl_bBCVlearnFlg;/* '<S665>/AND2' */
extern MONPRM volatile boolean ACTCtl_bBEXVDvtFlg;/* '<S754>/NOT' */
extern MONPRM volatile boolean ACTCtl_bBEXVEnb;/* '<S806>/Switch' */
extern MONPRM volatile boolean ACTCtl_bBEXVFaultFlg;/* '<S749>/OR' */
extern MONPRM volatile boolean ACTCtl_bBEXVInitFinishFlg;/* '<S764>/Compare' */
extern MONPRM volatile uint8 ACTCtl_bBEXVInitReq;/* '<S765>/Switch' */
extern MONPRM volatile boolean ACTCtl_bBEXVPIEnble;/* '<S675>/AND' */
extern MONPRM volatile boolean ACTCtl_bBatPMPFaultFlg;/* '<S1053>/Switch' */
extern MONPRM volatile boolean ACTCtl_bBatPMPSpdFlt;/* '<S1024>/Switch1' */
extern MONPRM volatile uint8 ACTCtl_bBatTempDiff;/* '<S652>/Switch' */
extern MONPRM volatile boolean ACTCtl_bCOMPDvtFlg;/* '<S454>/Relational Operator' */
extern MONPRM volatile boolean ACTCtl_bCOMPEnbDelay;/* '<S504>/Chart' */
extern MONPRM volatile boolean ACTCtl_bCOMPEnvpTPrtFlg;/* '<S458>/AND' */
extern MONPRM volatile boolean ACTCtl_bCOMPFaultClc;/* '<S498>/OR2' */
extern MONPRM volatile boolean ACTCtl_bCOMPForbidFlg;/* '<S450>/OR' */
extern MONPRM volatile boolean ACTCtl_bCOMPHPFrbFlg;/* '<S456>/Signal Copy3' */
extern MONPRM volatile boolean ACTCtl_bCOMPHPLmtFlg;/* '<S456>/Signal Copy2' */
extern MONPRM volatile uint8 ACTCtl_bCOMPIFreeFlag;/* '<S482>/Merge' */
extern MONPRM volatile boolean ACTCtl_bCOMPLPFrbFlg;/* '<S456>/Signal Copy1' */
extern MONPRM volatile boolean ACTCtl_bCOMPLPLmtFlg;/* '<S456>/Signal Copy' */
extern MONPRM volatile boolean ACTCtl_bCOMPPIEnble;/* '<S457>/FFCal' */
extern MONPRM volatile boolean ACTCtl_bCOMPRealFault;/* '<S498>/OR1' */
extern MONPRM volatile boolean ACTCtl_bCOMPSpdDiffFlt;/* '<S452>/Chart' */
extern MONPRM volatile boolean ACTCtl_bCOMPStopFlg;/* '<S452>/OR' */
extern MONPRM volatile boolean ACTCtl_bCabinFltFlg;/* '<S1708>/Signal Copy1' */
extern MONPRM volatile boolean ACTCtl_bCtrlFPTCOnOrOffPwrDiff;/* '<S610>/Switch' */
extern MONPRM volatile boolean ACTCtl_bHPEXVDvtFlg;/* '<S825>/NOT' */
extern MONPRM volatile boolean ACTCtl_bHPEXVEnb;/* '<S837>/Switch' */
extern MONPRM volatile boolean ACTCtl_bHPEXVFaultFlg;/* '<S821>/OR' */
extern MONPRM volatile boolean ACTCtl_bHPEXVInitFinishFlg;/* '<S893>/Compare' */
extern MONPRM volatile uint8 ACTCtl_bHPEXVInitReq;/* '<S894>/Switch' */
extern MONPRM volatile boolean ACTCtl_bHPEXVPIEnble;/* '<S676>/AND' */
extern MONPRM volatile boolean ACTCtl_bHiPressProFlg;/* '<S826>/Switch4' */
extern MONPRM volatile boolean ACTCtl_bLowPressProFlg;/* '<S826>/Switch5' */
extern MONPRM volatile boolean ACTCtl_bMCVlearnFlg;/* '<S643>/AND2' */
extern MONPRM volatile boolean ACTCtl_bMotPMPFaultFlg;/* '<S1067>/Switch' */
extern MONPRM volatile boolean ACTCtl_bMotPMPSpdFlt;/* '<S1025>/Chart' */
extern MONPRM volatile boolean ACTCtl_bOCOLmtFlg;/* '<S504>/AND1' */
extern MONPRM volatile boolean ACTCtl_bPTCOnOrOffPwrDiff;/* '<S593>/Switch' */
extern MONPRM volatile boolean ACTCtl_bPressProtectFlg;/* '<S505>/Multiport Switch' */
extern MONPRM volatile boolean ACTCtl_bPressRateFlg;/* '<S505>/Multiport Switch1' */
extern MONPRM volatile boolean ACTCtl_bSOVCmd;/* '<S447>/Multiport Switch' */
extern MONPRM volatile uint8 ACTCtl_eACPumpRefSpd;/* '<S1023>/Multiport Switch' */
extern MONPRM volatile uint8 ACTCtl_eAcPMPSpdPerc;/* '<S1036>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eAcPMPSpdSet;/* '<S1023>/Divide' */
extern MONPRM volatile uint8 ACTCtl_eBatPMPSpdSet;/* '<S1024>/Divide' */
extern MONPRM volatile uint8 ACTCtl_eC3WVSLSts;/* '<S661>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eC3WVValue;/* '<S640>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eC5WVSLSts;/* '<S671>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eC5WVValue;/* '<S641>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eCOMPExhTPrtSts;/* '<S458>/Chart' */
extern MONPRM volatile uint8 ACTCtl_eCOMPJudgeFlg;/* '<S463>/Add' */
extern MONPRM volatile uint8 ACTCtl_eCOMPPrsPrtSts;/* '<S456>/Add' */
extern MONPRM volatile uint8 ACTCtl_eCOMPSpdSecSts;/* '<S534>/SecCal' */
extern MONPRM volatile uint8 ACTCtl_eCoolFanCtrl;/* '<S916>/cal_CoolFanCtrl_MAP' */
extern MONPRM volatile uint8 ACTCtl_eEvapProSts;/* '<S684>/EvapTemperature' */
extern MONPRM volatile uint8 ACTCtl_eFanPerc;/* '<S922>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eHeatFanCtrl;/* '<S919>/cal_HeatFanCtrl_MAP' */
extern MONPRM volatile uint8 ACTCtl_eLessThanT1Sts;/* '<S657>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eMotPMPSpdSet;/* '<S1025>/Divide' */
extern MONPRM volatile float32 ACTCtl_sACCMCtlFF;/* '<S457>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sACCMCtlSpd;/* '<S452>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sACCMI_Cor;/* '<S484>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sACCMI_Sum;/* '<S481>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sACCMPIVal;/* '<S482>/Merge' */
extern MONPRM volatile float32 ACTCtl_sACCMP_Cor;/* '<S483>/Merge' */
extern MONPRM volatile float32 ACTCtl_sAEXVActure;/* '<S674>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlBFF;/* '<S716>/cal_AEXVCtrlBFF_CUR' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlFF;/* '<S678>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlKi;/* '<S674>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlKp;/* '<S674>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sAEXVDvt;/* '<S683>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sAEXVI_Cor;/* '<S701>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sAEXVI_Sum;/* '<S698>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sAEXVPI_Cor;/* '<S699>/Merge' */
extern MONPRM volatile float32 ACTCtl_sAEXVP_Cor;/* '<S700>/Merge' */
extern MONPRM volatile float32 ACTCtl_sAEXVPos;/* '<S742>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sAEXVSetPoint;/* '<S674>/Signal Copy' */
extern MONPRM volatile float32 ACTCtl_sBEXVActure;/* '<S675>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlBFF;/* '<S784>/cal_BEXVCtrlBFF_CUR' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlFF;/* '<S753>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlKi;/* '<S675>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlKp;/* '<S675>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sBEXVDvt;/* '<S754>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sBEXVI_Cor;/* '<S769>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sBEXVI_Sum;/* '<S766>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sBEXVPI_Cor;/* '<S767>/Merge' */
extern MONPRM volatile float32 ACTCtl_sBEXVP_Cor;/* '<S768>/Merge' */
extern MONPRM volatile float32 ACTCtl_sBEXVPos;/* '<S812>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sBEXVSetPoint;/* '<S675>/Signal Copy' */
extern MONPRM volatile float32 ACTCtl_sBatHeatInletTrgT;/* '<S649>/Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPATNoiseBlwAndAccmSpd;/* '<S546>/cal_COMPATNoiseSpdLmt_MAP' */
extern MONPRM volatile float32 ACTCtl_sCOMPATNoiseLmtHVSSpd;
                                     /* '<S546>/cal_COMPATNoiseSpdLmtHVS_CUR' */
extern MONPRM volatile float32 ACTCtl_sCOMPATNoiseLmtSpd;/* '<S546>/Min' */
extern MONPRM volatile float32 ACTCtl_sCOMPActure;/* '<S441>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sCOMPCoolLmtSpd;/* '<S546>/Switch4' */
extern MONPRM volatile float32 ACTCtl_sCOMPCtrlAClsFF;/* '<S583>/cal_ACCMCtrlA2FF_MAP ' */
extern MONPRM volatile float32 ACTCtl_sCOMPCtrlKi;/* '<S441>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sCOMPCtrlKp;/* '<S441>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sCOMPDownSpd;/* '<S571>/Max1' */
extern MONPRM volatile float32 ACTCtl_sCOMPEnvLmtSpd;/* '<S547>/Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPFanlevelLmtSpd;/* '<S547>/cal_COMPFanLevelLmt_CUR' */
extern MONPRM volatile float32 ACTCtl_sCOMPHPLmtSpd;/* '<S546>/Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPLPLmtSpd;/* '<S546>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sCOMPLmtMaxSpd;/* '<S451>/Min' */
extern MONPRM volatile float32 ACTCtl_sCOMPPCULimSpd;/* '<S546>/Multiport Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPSetPoint;/* '<S441>/Signal Copy' */
extern MONPRM volatile float32 ACTCtl_sChiSuperHeat;/* '<S677>/Add5' */
extern MONPRM volatile float32 ACTCtl_sChiSuperHeatAvg;/* '<S899>/Divide' */
extern MONPRM volatile float32 ACTCtl_sChiSuperHeatAvg1;/* '<S908>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sCondDep;/* '<S677>/Add' */
extern MONPRM volatile float32 ACTCtl_sCondDepAvg;/* '<S896>/Divide' */
extern MONPRM volatile float32 ACTCtl_sCondDepAvg1;/* '<S902>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sCondDepDiff;/* '<S716>/Add' */
extern MONPRM volatile float32 ACTCtl_sCoolCondDep;/* '<S677>/Add3' */
extern MONPRM volatile float32 ACTCtl_sCoolCondDepAvg;/* '<S897>/Divide' */
extern MONPRM volatile float32 ACTCtl_sCoolCondDepAvg1;/* '<S904>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sCtrlFPTCAuxHeatPwr;
                                    /* '<S588>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern MONPRM volatile float32 ACTCtl_sDCoolBatTempDiff;/* '<S590>/Add2' */
extern MONPRM volatile float32 ACTCtl_sDCoolCabinTempDiff;/* '<S590>/Add3' */
extern MONPRM volatile float32 ACTCtl_sDvtCOMPCtrl;/* '<S454>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sEvapSuperHeat;/* '<S677>/Add4' */
extern MONPRM volatile float32 ACTCtl_sEvapSuperHeatAvg;/* '<S898>/Divide' */
extern MONPRM volatile float32 ACTCtl_sEvapSuperHeatAvg1;/* '<S906>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sExhSuperHeat;/* '<S677>/Add2' */
extern MONPRM volatile float32 ACTCtl_sExhSuperHeatAvg;/* '<S900>/Divide' */
extern MONPRM volatile float32 ACTCtl_sExhSuperHeatAvg1;/* '<S910>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVActure;/* '<S676>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlADiff;/* '<S859>/Add' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlFF;/* '<S820>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlKi;/* '<S676>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlKp;/* '<S676>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sHPEXVDvt;/* '<S825>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVI_Cor;/* '<S845>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVI_Sum;/* '<S842>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVPI_Cor;/* '<S843>/Merge' */
extern MONPRM volatile float32 ACTCtl_sHPEXVP_Cor;/* '<S844>/Merge' */
extern MONPRM volatile float32 ACTCtl_sHPEXVPos;/* '<S828>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sHPEXVSetPoint;/* '<S823>/Switch' */
extern MONPRM volatile float32 ACTCtl_sHPEXVStepLmt;/* '<S829>/Switch' */
extern MONPRM volatile float32 ACTCtl_sPTCAuxHeatPwr;/* '<S583>/cal_PTCAuxHeatPwrLmt_MAP' */
extern MONPRM volatile float32 ACTCtl_sPTCBatHeatPwrLmt;/* '<S948>/cal_PTCBatHeatPwrLmt_CUR' */
extern MONPRM volatile uint8 ACTCtl_sPTCEnable;/* '<S1014>/Switch' */
extern MONPRM volatile float32 ACTCtl_sPTCReqPower;/* '<S1021>/Switch' */
extern MONPRM volatile float32 ACTCtl_sPTCRequestTemp;/* '<S945>/Switch' */
extern MONPRM volatile float32 ACTCtl_sSOCHighPTCPwrLmt;/* '<S948>/cal_SOCHighPTCPwrLmt_CUR' */
extern MONPRM volatile float32 ACTCtl_sSuperHeat;/* '<S677>/Add1' */
extern MONPRM volatile float32 ACTCtl_sSuperHeatAvg;/* '<S901>/Divide' */
extern MONPRM volatile float32 ACTCtl_sSuperHeatAvg1;/* '<S912>/Sum1' */
extern MONPRM volatile float32 ACTCtl_tCtrlADiff;/* '<S583>/Add1' */
extern MONPRM volatile float32 ACTCtl_tCtrlBDiff;/* '<S584>/Add' */
extern MONPRM volatile float32 ACTCtl_tCtrlCDiff;/* '<S585>/Add1' */
extern MONPRM volatile uint8 AC_BlowerFanSpeedMax;/* '<S51>/MinMax' */
extern MONPRM volatile uint8 AC_BlowerFanSpeedMin;/* '<S52>/Switch4' */
extern MONPRM volatile float32 AC_DVT2PTCErr;/* '<S51>/Add' */
extern MONPRM volatile float32 AC_DVTPreSetByEnv;/* '<S186>/cal_ACDVTPreSetByEnv_MAP' */
extern MONPRM volatile float32 AC_DrEvapDesFilter;
                                     /* '<S282>/cal_DrEvapDesFilterByDvt_CUR' */
extern MONPRM volatile uint8 AC_FanLeVel;/* '<S43>/Merge' */
extern MONPRM volatile uint8 AC_FanLevelAct;/* '<S43>/Merge' */
extern MONPRM volatile float32 AC_PidCabinT_UL;
                                    /* '<S188>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern MONPRM volatile float32 AC_Ps2DrSetTempDvt;/* '<S183>/Sum2' */
extern MONPRM volatile float32 AC_PsEvapDesFilter;
                                     /* '<S307>/cal_PsEvapDesFilterByDvt_CUR' */
extern MONPRM volatile uint8 AC_rRecircInc;/* '<S57>/Data Type Conversion' */
extern MONPRM volatile uint16 AC_rSolarRight;/* '<S1773>/Switch' */
extern MONPRM volatile uint16 AC_rSunloadFlt;/* '<S211>/Saturation' */
extern MONPRM volatile boolean AC_stExhaust;/* '<S4>/stExhaustFunCheck' */
extern MONPRM volatile boolean AC_stIGNON;/* '<S1271>/Switch1' */
extern MONPRM volatile float32 AC_tEnvInvent;/* '<S187>/TempRampBaseTimeAndStep' */
extern MONPRM volatile uint16 AC_tiAfterRun;/* '<S1287>/Switch' */
extern MONPRM volatile uint8 AcPMP_HWVersion;/* '<S16>/Signal Copy114' */
extern MONPRM volatile uint8 AcPMP_PartNumber;/* '<S16>/Signal Copy113' */
extern MONPRM volatile uint8 AcPMP_ProjectCode1;/* '<S16>/Signal Copy110' */
extern MONPRM volatile uint8 AcPMP_ProjectCode2;/* '<S16>/Signal Copy111' */
extern MONPRM volatile boolean AcPMP_PumpDryRunningSta;/* '<S16>/Signal Copy105' */
extern MONPRM volatile uint8 AcPMP_PumpInputVolt;/* '<S16>/Signal Copy108' */
extern MONPRM volatile uint8 AcPMP_PumpMotorSta;/* '<S16>/Signal Copy104' */
extern MONPRM volatile uint8 AcPMP_PumpPowerSta;/* '<S16>/Signal Copy106' */
extern MONPRM volatile uint8 AcPMP_PumpTempSta;/* '<S16>/Signal Copy107' */
extern MONPRM volatile boolean AcPMP_RESP_ERROR;/* '<S16>/Signal Copy103' */
extern MONPRM volatile float32 AcPMP_RealRPM;/* '<S1261>/Gain' */
extern MONPRM volatile uint8 AcPMP_SWVersion_Main;/* '<S16>/Signal Copy115' */
extern MONPRM volatile uint8 AcPMP_SWVersion_Patch;/* '<S16>/Signal Copy117' */
extern MONPRM volatile uint8 AcPMP_SWVersion_Sub;/* '<S16>/Signal Copy116' */
extern MONPRM volatile uint8 AcPMP_SupplierNumber;/* '<S16>/Signal Copy112' */
extern MONPRM volatile uint8 BAT_EXV_CurrentInitState_B;/* '<S18>/Signal Copy35' */
extern MONPRM volatile float32 BAT_EXV_CurrentPosition_B;/* '<S1263>/Gain' */
extern MONPRM volatile uint8 BAT_EXV_FaultState_B;/* '<S18>/Signal Copy37' */
extern MONPRM volatile boolean BAT_EXV_ResponseError_B;/* '<S18>/Signal Copy34' */
extern MONPRM volatile boolean BAT_EXV_RunState_B;/* '<S18>/Signal Copy36' */
extern MONPRM volatile boolean BAT_EXV_SupplierLabel;/* '<S18>/Signal Copy40' */
extern MONPRM volatile uint8 BAT_EXV_TemperatureWarn_B;/* '<S1263>/Data Type Conversion' */
extern MONPRM volatile uint8 BAT_EXV_VoltageState_B;/* '<S18>/Signal Copy38' */
extern MONPRM volatile boolean BCV_ErrResp;/* '<S17>/Signal Copy73' */
extern MONPRM volatile uint8 BCV_FltSts;/* '<S17>/Signal Copy66' */
extern MONPRM volatile uint8 BCV_Mode; /* '<S17>/Signal Copy67' */
extern MONPRM volatile uint16 BCV_PosRec;/* '<S17>/Signal Copy68' */
extern MONPRM volatile boolean BCV_RunSts;/* '<S17>/Signal Copy69' */
extern MONPRM volatile uint8 BCV_SpdLvl;/* '<S17>/Signal Copy70' */
extern MONPRM volatile uint8 BCV_TempSts;/* '<S17>/Signal Copy71' */
extern MONPRM volatile uint8 BCV_VoltSts;/* '<S17>/Signal Copy72' */
extern MONPRM volatile float32 BMS_BatSOCAct_pct;/* '<S2>/Signal Copy1' */
extern MONPRM volatile float32 BMS_HVBatCellTempAve;/* '<S2>/Signal Copy159' */
extern MONPRM volatile float32 BMS_HVBatCellTempMax;/* '<S2>/Signal Copy160' */
extern MONPRM volatile float32 BMS_HVBatCellTempMin;/* '<S2>/Signal Copy161' */
extern MONPRM volatile float32 BMS_InletCooltActlTemp;/* '<S2>/Signal Copy147' */
extern MONPRM volatile boolean BatPMP_PumpDryRunningSta;/* '<S20>/Signal Copy91' */
extern MONPRM volatile uint8 BatPMP_PumpInputVolt;/* '<S20>/Signal Copy94' */
extern MONPRM volatile uint8 BatPMP_PumpMotorSta;/* '<S20>/Signal Copy90' */
extern MONPRM volatile uint8 BatPMP_PumpPowerSta;/* '<S20>/Signal Copy92' */
extern MONPRM volatile uint8 BatPMP_PumpTempSta;/* '<S20>/Signal Copy93' */
extern MONPRM volatile boolean BatPMP_RESP_ERROR;/* '<S20>/Signal Copy89' */
extern MONPRM volatile float32 BatPMP_RealRPM;/* '<S1264>/Gain' */
extern MONPRM volatile uint8 Bat_EXV_HWVersion;/* '<S18>/Signal Copy46' */
extern MONPRM volatile uint8 Bat_EXV_PartNumber;/* '<S18>/Signal Copy45' */
extern MONPRM volatile uint8 Bat_EXV_ProjectCode1;/* '<S18>/Signal Copy42' */
extern MONPRM volatile uint8 Bat_EXV_ProjectCode2;/* '<S18>/Signal Copy43' */
extern MONPRM volatile uint8 Bat_EXV_SWVersion_Main;/* '<S18>/Signal Copy47' */
extern MONPRM volatile uint8 Bat_EXV_SWVersion_Patch;/* '<S18>/Signal Copy49' */
extern MONPRM volatile uint8 Bat_EXV_SWVersion_Sub;/* '<S18>/Signal Copy48' */
extern MONPRM volatile uint8 Bat_EXV_SupplierNumber;/* '<S18>/Signal Copy44' */
extern MONPRM volatile boolean COMP_CANBusOff;/* '<S2>/Signal Copy118' */
extern MONPRM volatile boolean COMP_Commu_Error;/* '<S2>/Signal Copy120' */
extern MONPRM volatile boolean COMP_CurrentOffset;/* '<S2>/Signal Copy121' */
extern MONPRM volatile float32 COMP_EcompActSpd;/* '<S2>/Signal Copy122' */
extern MONPRM volatile uint8 COMP_EcompST;/* '<S2>/Signal Copy123' */
extern MONPRM volatile float32 COMP_High_Voltage;/* '<S2>/Signal Copy124' */
extern MONPRM volatile uint8 COMP_HvError;/* '<S2>/Signal Copy125' */
extern MONPRM volatile boolean COMP_IPM_Error;/* '<S2>/Signal Copy126' */
extern MONPRM volatile float32 COMP_InputCurrent;/* '<S2>/Signal Copy127' */
extern MONPRM volatile boolean COMP_LoseStep;/* '<S2>/Signal Copy128' */
extern MONPRM volatile uint8 COMP_LvError;/* '<S2>/Signal Copy129' */
extern MONPRM volatile uint8 COMP_OverCurrent;/* '<S2>/Signal Copy130' */
extern MONPRM volatile boolean COMP_OverDuty;/* '<S2>/Signal Copy131' */
extern MONPRM volatile boolean COMP_PI_Saturation;/* '<S2>/Signal Copy132' */
extern MONPRM volatile uint8 COMP_SelfCheckError;/* '<S2>/Signal Copy134' */
extern MONPRM volatile boolean COMP_TempError;/* '<S2>/Signal Copy135' */
extern MONPRM volatile float32 COMP_Temperature;/* '<S2>/Signal Copy136' */
extern MONPRM volatile float32 CabinDesTempSolarCor;
                                     /* '<S186>/cal_CabinDesTempSolarCor_MAP' */
extern MONPRM volatile float32 CabinDesTempSolarCorECO;
                                  /* '<S186>/cal_CabinDesTempSolarCorECO_MAP' */
extern MONPRM volatile boolean CoAC_stColdStart;/* '<S1272>/Switch3' */
extern MONPRM volatile uint8 CoAC_stwork;/* '<S30>/Switch1' */
extern MONPRM volatile float32 ColdPCUTempMinByEnv;
                                     /* '<S1710>/cal_ColdPCUTempMinByEnv_CUR' */
extern MONPRM volatile float32 ColdStartPCUTempMinByEnv;
                                /* '<S1283>/cal_ColdStartPCUTempMinByEnv_CUR' */
extern MONPRM volatile boolean ECUHighVoltInterlockSignal;/* '<S2>/Signal Copy137' */
extern MONPRM volatile float32 EE_PCUInletTemp;/* '<S1283>/Data Store Read1' */
extern MONPRM volatile uint8 EE_TimeDay;/* '<S1284>/Data Store Read3' */
extern MONPRM volatile uint8 EE_TimeHour;/* '<S1284>/Data Store Read' */
extern MONPRM volatile uint8 EE_TimeMin;/* '<S1284>/Data Store Read2' */
extern MONPRM volatile float32 EE_tEnv;/* '<S1283>/Data Store Read' */
extern MONPRM volatile uint8 EXV_CurrentInitState;/* '<S15>/Signal Copy97' */
extern MONPRM volatile float32 EXV_CurrentPosition;/* '<S1260>/Gain' */
extern MONPRM volatile uint8 EXV_FaultState;/* '<S15>/Signal Copy99' */
extern MONPRM volatile boolean EXV_ResponseError;/* '<S15>/Signal Copy96' */
extern MONPRM volatile boolean EXV_RunState;/* '<S15>/Signal Copy98' */
extern MONPRM volatile uint8 EXV_TemperatureWarn;/* '<S15>/Signal Copy101' */
extern MONPRM volatile uint8 EXV_VoltageState;/* '<S15>/Signal Copy100' */
extern MONPRM volatile float32 Eva_CloseCond1;/* '<S179>/Add2' */
extern MONPRM volatile float32 Eva_CooledCond1;/* '<S179>/Add3' */
extern MONPRM volatile float32 Eva_CoolingCond1;/* '<S179>/Add' */
extern MONPRM volatile float32 Eva_CoolingCond2;/* '<S179>/Add1' */
extern MONPRM volatile float32 EvapDesTempDrCabinCor;
                                      /* '<S283>/cal_EvapDesTempCabinCor_CUR' */
extern MONPRM volatile float32 EvapDesTempDrEnvCor;/* '<S283>/cal_EvapDesTempEnvCor_MAP' */
extern MONPRM volatile float32 EvapDesTempDrFanCor;/* '<S283>/cal_EvapDesTempFanCor_CUR' */
extern MONPRM volatile float32 EvapDesTempPsCabinCor;
                                    /* '<S308>/cal_EvapDesTempPsCabinCor_CUR' */
extern MONPRM volatile float32 EvapDesTempPsEnvCor;
                                      /* '<S308>/cal_EvapDesTempPsEnvCor_MAP' */
extern MONPRM volatile float32 EvapDesTempPsFanCor;
                                      /* '<S308>/cal_EvapDesTempPsFanCor_CUR' */
extern MONPRM volatile uint16 GlbDa_LeftSolar;/* '<S182>/Data Type Conversion1' */
extern MONPRM volatile uint16 GlbDa_LeftSolarAvr;/* '<S57>/Add1' */
extern MONPRM volatile uint16 GlbDa_RightSolar;/* '<S183>/Data Type Conversion' */
extern MONPRM volatile uint16 GlbDa_Solar;/* '<S280>/Max1' */
extern MONPRM volatile float32 GlbDa_tCabinInvent;/* '<S177>/Switch2' */
extern MONPRM volatile uint16 GlbDa_uBat;/* '<S2>/Constant2' */
extern MONPRM volatile boolean HMICtl_bACAuto;/* '<S1161>/Switch' */
extern MONPRM volatile boolean HMICtl_bACDefrost;/* '<S1175>/Switch' */
extern MONPRM volatile boolean HMICtl_bACOnOff;/* '<S1187>/Switch' */
extern MONPRM volatile boolean HMICtl_bLeftSetHigh;/* '<S1140>/Switch' */
extern MONPRM volatile boolean HMICtl_bLeftSetLow;/* '<S1141>/Switch' */
extern MONPRM volatile uint8 HMICtl_eACSts;/* '<S1199>/Switch' */
extern MONPRM volatile uint8 HMICtl_eBlwSts;/* '<S1099>/Switch' */
extern MONPRM volatile uint8 HMICtl_eInner;/* '<S1115>/Switch' */
extern MONPRM volatile uint8 HMICtl_eModeMotor;/* '<S1122>/Switch' */
extern MONPRM volatile uint8 HMICtl_eUnlckVentSts;/* '<S1204>/Switch' */
extern MONPRM volatile float32 HMICtl_sLeftSetPoint;/* '<S1142>/Switch' */
extern MONPRM volatile float32 HMICtl_sMixDoor;/* '<S1117>/Switch' */
extern MONPRM volatile float32 HP_EXV_CurrentPosition_B;/* '<S1265>/Gain' */
extern MONPRM volatile uint8 HP_EXV_FaultState_B;/* '<S22>/Signal Copy23' */
extern MONPRM volatile uint8 HP_EXV_HWVersion;/* '<S22>/Signal Copy30' */
extern MONPRM volatile uint8 HP_EXV_PartNumber;/* '<S22>/Signal Copy29' */
extern MONPRM volatile uint8 HP_EXV_ProjectCode1;/* '<S22>/Signal Copy26' */
extern MONPRM volatile uint8 HP_EXV_ProjectCode2;/* '<S22>/Signal Copy27' */
extern MONPRM volatile boolean HP_EXV_ResponseError_B;/* '<S22>/Signal Copy21' */
extern MONPRM volatile boolean HP_EXV_RunState_B;/* '<S22>/Signal Copy22' */
extern MONPRM volatile uint8 HP_EXV_SWVersion_Main;/* '<S22>/Signal Copy31' */
extern MONPRM volatile uint8 HP_EXV_SWVersion_Patch;/* '<S22>/Signal Copy33' */
extern MONPRM volatile uint8 HP_EXV_SWVersion_Sub;/* '<S22>/Signal Copy32' */
extern MONPRM volatile boolean HP_EXV_SupplierLabel;/* '<S22>/Signal Copy19' */
extern MONPRM volatile uint8 HP_EXV_SupplierNumber;/* '<S22>/Signal Copy28' */
extern MONPRM volatile uint8 HP_EXV_VoltageState_B;/* '<S22>/Signal Copy24' */
extern MONPRM volatile boolean HP_EXV_Warning_OverTemp;/* '<S22>/Signal Copy20' */
extern MONPRM volatile uint8 HP_EXV_initialize_status;/* '<S22>/Signal Copy18' */
extern MONPRM volatile uint8 HU_LeftTempSet;/* '<S2>/Signal Copy200' */
extern MONPRM volatile uint8 IOCtl_BloweFanSpeed;/* '<S1243>/Switch' */
extern MONPRM volatile boolean IOCtl_PwrNmReqFlg;/* '<S1232>/Relational Operator' */
extern MONPRM volatile uint8 IOCtl_RecircTrgPos;/* '<S1868>/Switch' */
extern MONPRM volatile boolean IOCtl_bModeMoveSts;/* '<S1861>/Signal Copy' */
extern MONPRM volatile float32 IOCtl_sMixDoorTrgPos;/* '<S1875>/Switch' */
extern MONPRM volatile float32 IOCtl_sModeMotorTrgPos;/* '<S1880>/Switch' */
extern MONPRM volatile boolean MCV_ErrResp;/* '<S24>/Signal Copy57' */
extern MONPRM volatile uint8 MCV_FltSts;/* '<S24>/Signal Copy50' */
extern MONPRM volatile uint8 MCV_Mode; /* '<S24>/Signal Copy51' */
extern MONPRM volatile uint16 MCV_PosRec;/* '<S24>/Signal Copy52' */
extern MONPRM volatile boolean MCV_RunSts;/* '<S24>/Signal Copy53' */
extern MONPRM volatile uint8 MCV_SpdLvl;/* '<S24>/Signal Copy54' */
extern MONPRM volatile uint8 MCV_TempSts;/* '<S24>/Signal Copy55' */
extern MONPRM volatile uint8 MCV_VoltSts;/* '<S24>/Signal Copy56' */
extern MONPRM volatile boolean MotPMP_PumpDryRunningSta;/* '<S25>/Signal Copy84' */
extern MONPRM volatile uint8 MotPMP_PumpInputVolt;/* '<S25>/Signal Copy87' */
extern MONPRM volatile uint8 MotPMP_PumpMotorSta;/* '<S25>/Signal Copy83' */
extern MONPRM volatile uint8 MotPMP_PumpPowerSta;/* '<S25>/Signal Copy85' */
extern MONPRM volatile uint8 MotPMP_PumpTempSta;/* '<S25>/Signal Copy86' */
extern MONPRM volatile boolean MotPMP_RESP_ERROR;/* '<S25>/Signal Copy82' */
extern MONPRM volatile float32 MotPMP_RealRPM;/* '<S1267>/Gain' */
extern MONPRM volatile float32 PCU_StartClntTemp;/* '<S1283>/Data Type Conversion' */
extern MONPRM volatile float32 PCUtempOffset2ShutByEnv;
                                 /* '<S1283>/cal_PCUtempOffset2ShutByEnv_CUR' */
extern MONPRM volatile boolean PWRCtl_bKL15swtSt;/* '<S2>/OR' */
extern MONPRM volatile boolean PWRCtl_bUnlockVentTimeFlg;/* '<S1281>/Switch' */
extern MONPRM volatile uint8 PWRCtl_eBatChargSts;/* '<S30>/CoBatCharg' */
extern MONPRM volatile PwrModes PWRCtl_eTMSStatus;/* '<S1276>/Switch' */
extern MONPRM volatile uint8 PWRCtl_eVCUPTSts;/* '<S2>/Signal Copy183' */
extern MONPRM volatile float32 PWRCtl_sCOMPActlPwr;/* '<S31>/Divide1' */
extern MONPRM volatile float32 PWRCtl_sLmtPwrCOMP;/* '<S31>/Min' */
extern MONPRM volatile uint32 PWRCtl_uTMSRunTimer;/* '<S30>/Cal_RunTime' */
extern MONPRM volatile uint32 PWRCtl_uTMSRunTimer20ms;/* '<S33>/Cal_RunTime_20ms' */
extern MONPRM volatile float32 PidCabinX_IsumMax;
                                   /* '<S188>/cal_PidCabinX_IsumMaxByDVT_CUR' */
extern MONPRM volatile float32 PidCabinX_IsumMin;
                                   /* '<S188>/cal_PidCabinX_IsumMinByDVT_CUR' */
extern MONPRM volatile boolean RMTCtl_bRemtACDefFlg;/* '<S1129>/Switch' */
extern MONPRM volatile boolean RMTCtl_bRemtACFlg;/* '<S1128>/Switch' */
extern MONPRM volatile uint16 SENCtl_uACCMHighTempVol;/* '<S1724>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uCabinVoltage;/* '<S1708>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uChillTempVol;/* '<S1716>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uEVAPSurfTempVol;/* '<S1719>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uEVAPXTempVol;/* '<S1718>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uEnvVoltage;/* '<S1717>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uFaceDuctVal;/* '<S1712>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uFootDuctVal;/* '<S1713>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uMixDoorVol;/* '<S1205>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uModeDoorVol;/* '<S1206>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uMotInletTempVol;/* '<S1720>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uOHXTempVol;/* '<S1721>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uRecircDoorVol;/* '<S1207>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uSolorVol;/* '<S1715>/C_Caller' */
extern MONPRM volatile uint16 SENCtl_uWCCHPVol;/* '<S1723>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uWCCHighTempVol;/* '<S1722>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uWCCLPVol;/* '<S1714>/C Caller' */
extern MONPRM volatile float32 SEN_ACCMTHiRaw;/* '<S1724>/cal_ACCMTHi_CUR' */
extern MONPRM volatile float32 SEN_ChiTRaw;/* '<S1716>/cal_TChillOutRaw_CUR' */
extern MONPRM volatile float32 SEN_EvapTRaw;/* '<S1718>/cal_TEvapOutRaw_CUR' */
extern MONPRM volatile float32 SEN_LoPressRaw;/* '<S1714>/cal_LoPress_CUR' */
extern MONPRM volatile float32 SEN_MixDoorRaw;/* '<S1205>/cal_MixDoorPerc_CUR' */
extern MONPRM volatile float32 SEN_OHXTRaw;/* '<S1721>/cal_OHXTRaw_CUR' */
extern MONPRM volatile uint16 SEN_SolarRaw;/* '<S1715>/cal_SolarValRaw_CUR' */
extern MONPRM volatile float32 SEN_TCabinRaw;/* '<S1708>/cal_TCabinRaw_CUR' */
extern MONPRM volatile float32 SEN_TDuctRaw;/* '<S1712>/cal_TDuctRaw_CUR' */
extern MONPRM volatile float32 SEN_TEnvRaw;/* '<S1717>/cal_TEnvRaw_CUR' */
extern MONPRM volatile float32 SEN_TEvapSurRaw;/* '<S1719>/cal_TEvapSur_CUR' */
extern MONPRM volatile float32 SEN_TFootDuctRaw;/* '<S1713>/cal_TDuctRaw_CUR' */
extern MONPRM volatile float32 SEN_TMotRaw;/* '<S1720>/cal_TMot_CUR' */
extern MONPRM volatile float32 SEN_WCCHiPressRaw;/* '<S1723>/cal_LCCOutHiPressRaw_CUR' */
extern MONPRM volatile float32 SEN_WCCTHiRaw;/* '<S1722>/cal_WCCTHiRaw_CUR' */
extern MONPRM volatile boolean SOMCtl_bB1toB31;/* '<S1309>/Switch1' */
extern MONPRM volatile boolean SOMCtl_bBatB1TB41Flg;/* '<S1460>/OR2' */
extern MONPRM volatile boolean SOMCtl_bBatB1TB42Flg;/* '<S1473>/OR2' */
extern MONPRM volatile boolean SOMCtl_bBatBalEntBFlg;/* '<S1608>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatBalFlg;/* '<S1302>/Judge' */
extern MONPRM volatile boolean SOMCtl_bBatCoolFlg;/* '<S1371>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatHStrFlg;/* '<S1549>/Chart' */
extern MONPRM volatile boolean SOMCtl_bBatHeatB31tB1Flg;/* '<S1552>/AND3' */
extern MONPRM volatile boolean SOMCtl_bBatHeatB3tB1Flg;/* '<S1309>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatHeatChrgFlgAB;/* '<S1456>/AND2' */
extern MONPRM volatile boolean SOMCtl_bBatHeatChrgFlgCD;/* '<S1457>/NOT' */
extern MONPRM volatile boolean SOMCtl_bBatHeatFlg;/* '<S1454>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatHeatOffFlg;/* '<S1484>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bBatHeatPwrLmtF;/* '<S1459>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bBatHeatTempDiffE;/* '<S1466>/Compare' */
extern MONPRM volatile boolean SOMCtl_bBatLTRFlg;/* '<S1304>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatLTROffFlg;/* '<S1414>/AND7' */
extern MONPRM volatile boolean SOMCtl_bBatTSEntAFlg;/* '<S1343>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatTSEntBFlg;/* '<S1344>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatTSExitFlg;/* '<S1323>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatTSFlg;/* '<S1302>/Switch' */
extern MONPRM volatile boolean SOMCtl_bCalTempBatHeatFlg;/* '<S1455>/Merge' */
extern MONPRM volatile boolean SOMCtl_bDBatLTROffFlg;/* '<S1516>/AND7' */
extern MONPRM volatile boolean SOMCtl_bDCBatLTROnFlg;/* '<S1413>/AND1' */
extern MONPRM volatile boolean SOMCtl_bEntExtDefFlg;/* '<S1697>/AND' */
extern MONPRM volatile boolean SOMCtl_bExitExtDefTempFlg;/* '<S1702>/Compare' */
extern MONPRM volatile boolean SOMCtl_bExtDefFlg;/* '<S1700>/Switch' */
extern MONPRM volatile boolean SOMCtl_bMD1CLMSts;/* '<S1646>/Chart' */
extern MONPRM volatile boolean SOMCtl_bMD1ToMD2Flg;/* '<S1645>/C' */
extern MONPRM volatile boolean SOMCtl_bMD2DHMD1Flg;/* '<S1647>/MD2_DHMD1' */
extern MONPRM volatile boolean SOMCtl_bMD2ToMD1Flg;/* '<S1645>/OR7' */
extern MONPRM volatile boolean SOMCtl_bMD2ToMD3Flg;/* '<S1648>/B' */
extern MONPRM volatile boolean SOMCtl_bMD3DHMD2Flg;/* '<S1649>/MD3_DHMD2' */
extern MONPRM volatile boolean SOMCtl_bMD3ToMD2Flg;/* '<S1648>/A' */
extern MONPRM volatile boolean SOMCtl_bMD3ToMD4Flg;/* '<S1650>/B' */
extern MONPRM volatile boolean SOMCtl_bMD4ToMD3Flg;/* '<S1650>/A' */
extern MONPRM volatile boolean SOMCtl_bMotAndBatLTRFlg;/* '<S1308>/Switch' */
extern MONPRM volatile boolean SOMCtl_bMotHeatBatFlg;/* '<S1310>/Switch' */
extern MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOffFlg;/* '<S1607>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOn1Flg;/* '<S1515>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOn2Flg;/* '<S1515>/Relational Operator1' */
extern MONPRM volatile boolean SOMCtl_bMotorHeatBatOffFlg;/* '<S1587>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bMotorHeatBatOnFlg;/* '<S1310>/Switch2' */
extern MONPRM volatile boolean SOMCtl_bMotorLTRAndBatBalFlg;/* '<S1311>/Switch' */
extern MONPRM volatile boolean SOMCtl_bNmlBatLTROnFlg;/* '<S1413>/Relational Operator' */
extern MONPRM volatile uint8 SOMCtl_eBatBalEntBFlg;/* '<S1608>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatCoolB1tB21;/* '<S1376>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatCoolB1tB22;/* '<S1387>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatCoolB2tB1;/* '<S1397>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatHeatOffVal;/* '<S1484>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatLTROnFlg;/* '<S1611>/Add' */
extern MONPRM volatile BatModes SOMCtl_eBatMode;/* '<S1449>/Switch' */
extern MONPRM volatile CabinMode SOMCtl_eCabinMode;/* '<S1695>/Switch' */
extern MONPRM volatile CabinMode SOMCtl_eCabinModePre;/* '<S1652>/Data Type Conversion2' */
extern MONPRM volatile uint8 SOMCtl_eHVPartMode;/* '<S1703>/Switch' */
extern MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOffFlg;/* '<S1607>/Add' */
extern MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOn1Flg;/* '<S1515>/Add' */
extern MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOn2Flg;/* '<S1515>/Add1' */
extern MONPRM volatile uint8 SOMCtl_eMotorHeatBat2Flg;/* '<S1585>/Add' */
extern MONPRM volatile uint8 SOMCtl_eMotorHeatBatFlg;/* '<S1586>/Add' */
extern MONPRM volatile uint16 SOMCtl_eMotorHeatBatOffFlg;/* '<S1587>/Add' */
extern MONPRM volatile uint8 SOMCtl_eNmlBatLTROnFlg;/* '<S1413>/Add' */
extern MONPRM volatile RefModes SOMCtl_eRefModes;/* '<S1704>/Switch' */
extern MONPRM volatile WaterModes SOMCtl_eWaterMode;/* '<S1696>/Switch' */
extern MONPRM volatile float32 SOMCtl_sBatHeatPTCTrgT;/* '<S1507>/Switch' */
extern MONPRM volatile float32 SOMCtl_sBatHeatT1;/* '<S1455>/Merge' */
extern MONPRM volatile float32 SOMCtl_sBatHeatT2;/* '<S1455>/Merge' */
extern MONPRM volatile float32 SOMCtl_sBatHeatTrgTempComp;
                                      /* '<S1507>/cal_BatHeatTrgTempComp_CUR' */
extern MONPRM volatile float32 SOMCtl_sBatTrgTemp;/* '<S1314>/Switch' */
extern MONPRM volatile float32 SOMCtl_sF1Value;/* '<S1644>/Add' */
extern MONPRM volatile float32 SOMCtl_sF2Value;/* '<S1644>/Add1' */
extern MONPRM volatile boolean SOMCtrl_bBatLTRDelayFlg;/* '<S1414>/Delay' */
extern MONPRM volatile uint8 TMS_VersionNumber;/* '<S8>/Constant1' */
extern MONPRM volatile float32 ThCo_rSetLeftMixDoor;/* '<S389>/Switch3' */
extern MONPRM volatile float32 ThCo_rSetRightMixDoor;/* '<S389>/Switch2' */
extern MONPRM volatile uint16 adc2_group0_0;/* '<S1707>/Signal Copy' */
extern MONPRM volatile uint16 adc2_group0_1;/* '<S1707>/Signal Copy1' */
extern MONPRM volatile uint16 adc2_group0_2;/* '<S1707>/Signal Copy2' */
extern MONPRM volatile uint16 adc2_group1_0;/* '<S1707>/Signal Copy3' */
extern MONPRM volatile uint16 adc2_group1_1;/* '<S1707>/Signal Copy4' */
extern MONPRM volatile uint16 adc2_group1_2;/* '<S1707>/Signal Copy5' */
extern MONPRM volatile uint16 adc2_group1_3;/* '<S1707>/Signal Copy6' */
extern MONPRM volatile uint16 adc2_group1_4;/* '<S1707>/Signal Copy7' */
extern MONPRM volatile uint16 adc2_group1_5;/* '<S1707>/Signal Copy8' */
extern MONPRM volatile uint16 adc2_group1_6;/* '<S1707>/Signal Copy9' */
extern MONPRM volatile uint16 adc2_group1_7;/* '<S1707>/Signal Copy10' */
extern MONPRM volatile uint16 adc2_group1_8;/* '<S1707>/Signal Copy11' */
extern MONPRM volatile uint16 adc2_group1_9;/* '<S1707>/Signal Copy12' */
extern MONPRM volatile uint16 adc2_group2_0;/* '<S1707>/Signal Copy17' */
extern MONPRM volatile uint16 adc2_group2_1;/* '<S1707>/Signal Copy18' */
extern MONPRM volatile uint16 adc2_group2_2;/* '<S1707>/Signal Copy19' */
extern MONPRM volatile uint16 adc2_group2_3;/* '<S1707>/Signal Copy13' */
extern MONPRM volatile uint16 adc2_group2_4;/* '<S1707>/Signal Copy14' */

#endif                                 /* RTW_HEADER_TMS_MonitorData_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
