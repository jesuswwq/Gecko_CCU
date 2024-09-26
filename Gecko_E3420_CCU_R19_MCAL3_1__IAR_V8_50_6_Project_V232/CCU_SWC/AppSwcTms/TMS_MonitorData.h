/*
 * File: TMS_MonitorData.h
 *
 * Code generated for Simulink model 'ME11'.
 *
 * Model version                  : 1.2111
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Sep 19 15:03:10 2024
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
extern MONPRM volatile float32 ACCCtl_sACCabinPreSetByEnv;/* '<S182>/cal_ACCabinPreSetByEnv_MAP' */
extern MONPRM volatile float32 ACCCtl_sACCabinPreSetByEnvECO;
                                    /* '<S182>/cal_ACCabinPreSetByEnvECO_MAP' */
extern MONPRM volatile float32 ACCCtl_sBlowerFanSpd;/* '<S53>/MinMax' */
extern MONPRM volatile float32 ACCCtl_sSetPtcDesTempMax;/* '<S176>/cal_SetPtcDesTempMax_MAP' */
extern MONPRM volatile uint8 ACCtl_BloweFanSpeed;/* '<S39>/Merge' */
extern MONPRM volatile BlowerModes ACCtl_BlowerMode;/* '<S40>/Merge' */
extern MONPRM volatile float32 ACCtl_DVTIDeadBand;/* '<S184>/Constant7' */
extern MONPRM volatile float32 ACCtl_DrfacPtc2NominalTemp;/* '<S388>/Switch4' */
extern MONPRM volatile uint8 ACCtl_IntakeRatio;/* '<S44>/Merge' */
extern MONPRM volatile float32 ACCtl_PsfacPtc2NominalTemp;/* '<S414>/Switch4' */
extern MONPRM volatile float32 ACCtl_RFace2FaceFloor;
                                      /* '<S77>/cal_RFace2FaceFloorByEnv_CUR' */
extern MONPRM volatile float32 ACCtl_RFaceFloor2Face;
                                      /* '<S77>/cal_RFaceFloor2FaceByEnv_CUR' */
extern MONPRM volatile float32 ACCtl_RFaceFloor2Floor;
                                     /* '<S77>/cal_RFaceFloor2FloorByEnv_CUR' */
extern MONPRM volatile float32 ACCtl_RFloor2FaceFloor;
                                     /* '<S77>/cal_RFloor2FaceFloorByEnv_CUR' */
extern MONPRM volatile boolean ACCtl_bExhFlg;/* '<S1081>/Switch' */
extern MONPRM volatile boolean ACCtl_bExhaustFlg;/* '<S10>/AND2' */
extern MONPRM volatile uint16 ACCtl_pwrHeatingFeed;/* '<S91>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern MONPRM volatile float32 ACCtl_pwrHeatingICor;/* '<S102>/Merge1' */
extern MONPRM volatile float32 ACCtl_pwrHeatingISum;/* '<S98>/Switch1' */
extern MONPRM volatile float32 ACCtl_pwrHeatingPCor;/* '<S101>/Merge' */
extern MONPRM volatile uint16 ACCtl_pwrHeatingReq;/* '<S35>/Signal Copy' */
extern MONPRM volatile uint8 ACCtl_rDrBasicMixDoor;/* '<S386>/Switch6' */
extern MONPRM volatile uint8 ACCtl_rDrMixDoorDes;/* '<S387>/Data Type Conversion' */
extern MONPRM volatile float32 ACCtl_rDrSetMixDoorICor;/* '<S397>/Merge1' */
extern MONPRM volatile float32 ACCtl_rDrSetMixDoorISum;/* '<S393>/Switch1' */
extern MONPRM volatile float32 ACCtl_rDrSetMixDoorPCor;/* '<S396>/Merge' */
extern MONPRM volatile uint8 ACCtl_rPsBasicMixDoor;/* '<S412>/Switch6' */
extern MONPRM volatile float32 ACCtl_rPsBlowerModeSet;/* '<S412>/Multiport Switch2' */
extern MONPRM volatile uint8 ACCtl_rPsMixDoorDes;/* '<S413>/Data Type Conversion' */
extern MONPRM volatile float32 ACCtl_rPsSetMixDoorICor;/* '<S421>/Merge1' */
extern MONPRM volatile float32 ACCtl_rPsSetMixDoorISum;/* '<S417>/Switch1' */
extern MONPRM volatile float32 ACCtl_rPsSetMixDoorPCor;/* '<S420>/Merge' */
extern MONPRM volatile float32 ACCtl_sECOEvaDesValLL;/* '<S175>/cal_ECOEvaDesValLL_MAP' */
extern MONPRM volatile float32 ACCtl_sMixDoorClsFF;/* '<S387>/Switch' */
extern MONPRM volatile boolean ACCtl_stACPTCHeated;/* '<S176>/PTCHeatedCheck' */
extern MONPRM volatile boolean ACCtl_stCabinCoolingEn;/* '<S41>/Merge' */
extern MONPRM volatile boolean ACCtl_stCabinHeatingEn;/* '<S90>/Logical Operator' */
extern MONPRM volatile uint8 ACCtl_stDvtPIDFreez;/* '<S187>/Merge' */
extern MONPRM volatile boolean ACCtl_stEvaCooledFlag;/* '<S175>/EvaCooledCheck' */
extern MONPRM volatile boolean ACCtl_stRecACHotStartEna;/* '<S123>/Relational Operator5' */
extern MONPRM volatile boolean ACCtl_stRecAQSEna;/* '<S124>/Recirc_AQS' */
extern MONPRM volatile boolean ACCtl_stRecForceChangeEna;/* '<S125>/Switch3' */
extern MONPRM volatile boolean ACCtl_stRecForceDefogEna;/* '<S126>/Relational Operator' */
extern MONPRM volatile uint8 ACCtl_stRecLevelFinal;/* '<S35>/Max' */
extern MONPRM volatile boolean ACCtl_stRecManualEna;/* '<S122>/Logical Operator' */
extern MONPRM volatile boolean ACCtl_stRecNormalDefogEna;/* '<S127>/Logical Operator' */
extern MONPRM volatile boolean ACCtl_stRecOut;/* '<S44>/Merge' */
extern MONPRM volatile boolean ACCtl_stRecPCUTempEna;/* '<S128>/Switch' */
extern MONPRM volatile boolean ACCtl_stRecPTCDvtEna;/* '<S129>/Switch1' */
extern MONPRM volatile boolean ACCtl_stRecQkChargeCoolingEna;/* '<S130>/Logical Operator' */
extern MONPRM volatile boolean ACCtl_stRecRemoteACEna;/* '<S131>/Relational Operator3' */
extern MONPRM volatile boolean ACCtl_stRecSummerCondEna;/* '<S132>/Relational Operator4' */
extern MONPRM volatile boolean ACCtl_stRecTargetOutTempEna;/* '<S133>/Switch1' */
extern MONPRM volatile boolean ACCtl_stRecTempLowEna;/* '<S32>/OR' */
extern MONPRM volatile boolean ACCtl_stRecVentEna;/* '<S135>/Logical Operator2' */
extern MONPRM volatile boolean ACCtl_stRecWinterCondEna;/* '<S136>/Relational Operator4' */
extern MONPRM volatile uint8 ACCtl_stStartState;/* '<S36>/AirConditionStartState' */
extern MONPRM volatile float32 ACCtl_tDVTFeedfoward;/* '<S205>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDVTFlt;/* '<S55>/Add' */
extern MONPRM volatile float32 ACCtl_tDVTPIBas;/* '<S187>/Merge' */
extern MONPRM volatile float32 ACCtl_tDesFrontCabin;/* '<S182>/Switch3' */
extern MONPRM volatile float32 ACCtl_tDrDVT;/* '<S178>/Switch3' */
extern MONPRM volatile float32 ACCtl_tDrDVTSolarCor;/* '<S178>/cal_ACDrDVTSolarCor_MAP' */
extern MONPRM volatile float32 ACCtl_tDrEvapDes;/* '<S280>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDrEvapDesPI;/* '<S283>/Merge' */
extern MONPRM volatile float32 ACCtl_tDrEvapICor;/* '<S286>/Merge1' */
extern MONPRM volatile float32 ACCtl_tDrEvapISum;/* '<S281>/Switch1' */
extern MONPRM volatile float32 ACCtl_tDrEvapPCor;/* '<S285>/Merge' */
extern MONPRM volatile float32 ACCtl_tDrPTCICor;/* '<S345>/Merge1' */
extern MONPRM volatile float32 ACCtl_tDrPTCISum;/* '<S341>/Switch1' */
extern MONPRM volatile float32 ACCtl_tDrPTCPCor;/* '<S344>/Merge' */
extern MONPRM volatile float32 ACCtl_tDrSetBasicEvap;/* '<S302>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDrSetBasicPTC;/* '<S340>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDvtICor;/* '<S189>/Merge1' */
extern MONPRM volatile float32 ACCtl_tDvtISum;/* '<S185>/Switch1' */
extern MONPRM volatile float32 ACCtl_tDvtPCor;/* '<S188>/Merge' */
extern MONPRM volatile float32 ACCtl_tErrACPTC;/* '<S99>/Switch1' */
extern MONPRM volatile boolean ACCtl_tErrACPTCPosFlag;/* '<S99>/Relational Operator' */
extern MONPRM volatile float32 ACCtl_tErrDVT;/* '<S186>/Switch1' */
extern MONPRM volatile boolean ACCtl_tErrDVTFlag;/* '<S186>/Relational Operator' */
extern MONPRM volatile float32 ACCtl_tErrDrDVT2Duct;/* '<S282>/Switch1' */
extern MONPRM volatile float32 ACCtl_tErrPsDVT2Duct;/* '<S308>/Switch1' */
extern MONPRM volatile float32 ACCtl_tLeftDuct;/* '<S172>/Switch' */
extern MONPRM volatile float32 ACCtl_tPsDVT;/* '<S179>/Switch1' */
extern MONPRM volatile float32 ACCtl_tPsDVTCabinCor;/* '<S179>/cal_ACPsDVTSetCorByEnv_MAP' */
extern MONPRM volatile float32 ACCtl_tPsDVTSolarCor;/* '<S179>/cal_ACPsDVTSolarCor_MAP' */
extern MONPRM volatile float32 ACCtl_tPsEvapDes;/* '<S305>/Switch2' */
extern MONPRM volatile float32 ACCtl_tPsEvapDesPI;/* '<S309>/Merge' */
extern MONPRM volatile float32 ACCtl_tPsEvapICor;/* '<S312>/Merge1' */
extern MONPRM volatile float32 ACCtl_tPsEvapISum;/* '<S307>/Switch1' */
extern MONPRM volatile float32 ACCtl_tPsEvapPCor;/* '<S310>/Merge' */
extern MONPRM volatile float32 ACCtl_tPsPTCICor;/* '<S367>/Merge1' */
extern MONPRM volatile float32 ACCtl_tPsPTCISum;/* '<S363>/Switch1' */
extern MONPRM volatile float32 ACCtl_tPsPTCPCor;/* '<S366>/Merge' */
extern MONPRM volatile float32 ACCtl_tPsSetBasicEvap;/* '<S327>/Switch2' */
extern MONPRM volatile float32 ACCtl_tPsSetBasicPTC;/* '<S362>/Switch2' */
extern MONPRM volatile float32 ACCtl_tRightDuct;/* '<S172>/Switch1' */
extern MONPRM volatile float32 ACCtl_tRightSetPointModeCor;/* '<S182>/Sum3' */
extern MONPRM volatile float32 ACCtl_tSetPointEvap;/* '<S175>/Switch1' */
extern MONPRM volatile float32 ACCtl_tSetPointPTC;/* '<S335>/Switch2' */
extern MONPRM volatile float32 ACDVTPreSetSolarCor;
                                      /* '<S182>/cal_ACDVTPreSetSolarCor_MAP' */
extern MONPRM volatile float32 ACDVTPreSetSolarCorByVx;
                                  /* '<S182>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern MONPRM volatile float32 ACFanSpdSolarCor;/* '<S53>/cal_ACFanSpdSolarCor_MAP' */
extern MONPRM volatile float32 ACFanSpdSolarCorByEnv;
                                     /* '<S53>/cal_ACFanSpdSolarCorByEnv_MAP' */
extern MONPRM volatile boolean ACNvm_bACAutoSts;/* '<S3>/Data Type Conversion1' */
extern MONPRM volatile boolean ACNvm_bACOnOff;/* '<S3>/Data Type Conversion' */
extern MONPRM volatile uint8 ACNvm_eACCabinMode;/* '<S3>/Index Vector4' */
extern MONPRM volatile uint8 ACNvm_eCabinBlower;/* '<S3>/Index Vector5' */
extern MONPRM volatile uint8 ACNvm_eCabinSetTemp;/* '<S3>/Index Vector2' */
extern MONPRM volatile uint8 ACNvm_eCainModeDoor;/* '<S3>/Index Vector11' */
extern MONPRM volatile uint8 ACNvm_eCainRecDoor;/* '<S3>/Index Vector10' */
extern MONPRM volatile float32 ACNvm_sACEnvTemp;/* '<S3>/Add' */
extern MONPRM volatile float32 ACNvm_sPCUInletTemp;/* '<S3>/Add1' */
extern MONPRM volatile float32 ACPTCDrDesCabinCor;/* '<S338>/cal_ACPTCDesCabinCor_CUR' */
extern MONPRM volatile float32 ACPTCDrDesEnvCor;/* '<S338>/cal_ACPTCDesEnvCor_MAP' */
extern MONPRM volatile float32 ACPTCDrDesFanCor;/* '<S338>/cal_ACPTCDesFanCor_CUR' */
extern MONPRM volatile float32 ACPTCPsDesCabinCor;/* '<S360>/cal_ACPTCPsDesCabinCor_CUR' */
extern MONPRM volatile float32 ACPTCPsDesEnvCor;/* '<S360>/cal_ACPTCPsDesEnvCor_MAP' */
extern MONPRM volatile float32 ACPTCPsDesFanCor;/* '<S360>/cal_ACPTCPsDesFanCor_CUR' */
extern MONPRM volatile float32 ACPTC_HeatedCond1;/* '<S176>/Add3' */
extern MONPRM volatile float32 ACPTC_HeatingCond1;/* '<S176>/Add' */
extern MONPRM volatile float32 ACPTC_HeatingCond2;/* '<S176>/Add1' */
extern MONPRM volatile float32 ACPtc_CloseCond1;/* '<S176>/Add2' */
extern MONPRM volatile FaultStatus ACSen_eACCMHTSenSts;/* '<S1865>/Data Type Conversion' */
extern MONPRM volatile uint8 ACSen_eAirInletPer;/* '<S1785>/Switch' */
extern MONPRM volatile FaultStatus ACSen_eCabinSenSts;/* '<S1721>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eChillerTSenSts;/* '<S1794>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eEVAPSurfTSenSts;/* '<S1824>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eEVAPTSenSts;/* '<S1814>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eEnvSenSts;/* '<S1805>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eFaceDuctSenSts;/* '<S1744>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eFootDuctSenSts;/* '<S1754>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eLPSenSts;/* '<S1707>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eMOTORTSenSts;/* '<S1833>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eMixDoorSenSts;/* '<S1708>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eModeSenSts;/* '<S1709>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eOHXTSenSts;/* '<S1840>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eRecircSenSts;/* '<S1710>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eSOLARSenSts;/* '<S1711>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eWCCHPSenSts;/* '<S1719>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eWCCHTSenSts;/* '<S1849>/Data Type Conversion' */
extern MONPRM volatile float32 ACSen_sACCMHiTempFilter;/* '<S1866>/Switch' */
extern MONPRM volatile float32 ACSen_sCabinTempFilter;/* '<S1722>/Switch' */
extern MONPRM volatile float32 ACSen_sChiTempFilter;/* '<S1793>/Switch' */
extern MONPRM volatile float32 ACSen_sEnvTAme;/* '<S1704>/cal_EnvTAme_CUR' */
extern MONPRM volatile float32 ACSen_sEnvTempCor;/* '<S1740>/Switch' */
extern MONPRM volatile float32 ACSen_sEnvTempFilter;/* '<S1811>/Switch' */
extern MONPRM volatile float32 ACSen_sEvapSurTemp;/* '<S1825>/Switch' */
extern MONPRM volatile float32 ACSen_sEvapTempFilter;/* '<S1815>/Switch' */
extern MONPRM volatile float32 ACSen_sFaceDuctTempFilter;/* '<S1745>/Switch' */
extern MONPRM volatile float32 ACSen_sFootDuctTempFilter;/* '<S1755>/Switch' */
extern MONPRM volatile float32 ACSen_sHiPressFilter;/* '<S1859>/Switch' */
extern MONPRM volatile float32 ACSen_sLoPressFilter;/* '<S1764>/Switch' */
extern MONPRM volatile float32 ACSen_sMixDoorPerc;/* '<S1771>/Switch' */
extern MONPRM volatile float32 ACSen_sModeMotorVol;/* '<S1778>/Switch' */
extern MONPRM volatile float32 ACSen_sMotTempFilter;/* '<S1831>/Switch' */
extern MONPRM volatile float32 ACSen_sOHXTempFilter;/* '<S1841>/Switch' */
extern MONPRM volatile float32 ACSen_sPressRateVal;/* '<S502>/Switch' */
extern MONPRM volatile float32 ACSen_sWCCHiTempFilter;/* '<S1851>/Switch' */
extern MONPRM volatile boolean ACTCrl_bEnvCOMPLmt;/* '<S498>/Switch1' */
extern MONPRM volatile boolean ACTCtl_bACCMCtlEnb;/* '<S457>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAEXVDvtFlg;/* '<S680>/NOT' */
extern MONPRM volatile boolean ACTCtl_bAEXVEnb;/* '<S684>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAEXVFaultFlg;/* '<S676>/OR' */
extern MONPRM volatile boolean ACTCtl_bAEXVInitFinishFlg;/* '<S693>/Compare' */
extern MONPRM volatile uint8 ACTCtl_bAEXVInitReq;/* '<S694>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAEXVPIEnble;/* '<S671>/AND' */
extern MONPRM volatile boolean ACTCtl_bAcPMPFaultFlg;/* '<S1034>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAcPMPSpdFlt;/* '<S1020>/Switch1' */
extern MONPRM volatile boolean ACTCtl_bBCVlearnFlg;/* '<S662>/AND2' */
extern MONPRM volatile boolean ACTCtl_bBEXVDvtFlg;/* '<S751>/NOT' */
extern MONPRM volatile boolean ACTCtl_bBEXVEnb;/* '<S803>/Switch' */
extern MONPRM volatile boolean ACTCtl_bBEXVFaultFlg;/* '<S746>/OR' */
extern MONPRM volatile boolean ACTCtl_bBEXVInitFinishFlg;/* '<S761>/Compare' */
extern MONPRM volatile uint8 ACTCtl_bBEXVInitReq;/* '<S762>/Switch' */
extern MONPRM volatile boolean ACTCtl_bBEXVPIEnble;/* '<S672>/AND' */
extern MONPRM volatile boolean ACTCtl_bBatPMPFaultFlg;/* '<S1050>/Switch' */
extern MONPRM volatile boolean ACTCtl_bBatPMPSpdFlt;/* '<S1021>/Switch1' */
extern MONPRM volatile uint8 ACTCtl_bBatTempDiff;/* '<S649>/Switch' */
extern MONPRM volatile boolean ACTCtl_bCOMPDvtFlg;/* '<S450>/Relational Operator' */
extern MONPRM volatile boolean ACTCtl_bCOMPEnbDelay;/* '<S501>/Chart' */
extern MONPRM volatile boolean ACTCtl_bCOMPEnvpTPrtFlg;/* '<S454>/AND' */
extern MONPRM volatile boolean ACTCtl_bCOMPFaultClc;/* '<S495>/OR2' */
extern MONPRM volatile boolean ACTCtl_bCOMPForbidFlg;/* '<S446>/OR' */
extern MONPRM volatile boolean ACTCtl_bCOMPHPFrbFlg;/* '<S452>/Signal Copy3' */
extern MONPRM volatile boolean ACTCtl_bCOMPHPLmtFlg;/* '<S452>/Signal Copy2' */
extern MONPRM volatile uint8 ACTCtl_bCOMPIFreeFlag;/* '<S479>/Merge' */
extern MONPRM volatile boolean ACTCtl_bCOMPLPFrbFlg;/* '<S452>/Signal Copy1' */
extern MONPRM volatile boolean ACTCtl_bCOMPLPLmtFlg;/* '<S452>/Signal Copy' */
extern MONPRM volatile boolean ACTCtl_bCOMPPIEnble;/* '<S453>/FFCal' */
extern MONPRM volatile boolean ACTCtl_bCOMPRealFault;/* '<S495>/OR1' */
extern MONPRM volatile boolean ACTCtl_bCOMPSpdDiffFlt;/* '<S448>/Chart' */
extern MONPRM volatile boolean ACTCtl_bCabinFltFlg;/* '<S1701>/Signal Copy1' */
extern MONPRM volatile boolean ACTCtl_bCtrlFPTCOnOrOffPwrDiff;/* '<S607>/Switch' */
extern MONPRM volatile boolean ACTCtl_bHPEXVDvtFlg;/* '<S822>/NOT' */
extern MONPRM volatile boolean ACTCtl_bHPEXVEnb;/* '<S834>/Switch' */
extern MONPRM volatile boolean ACTCtl_bHPEXVFaultFlg;/* '<S818>/OR' */
extern MONPRM volatile boolean ACTCtl_bHPEXVInitFinishFlg;/* '<S890>/Compare' */
extern MONPRM volatile uint8 ACTCtl_bHPEXVInitReq;/* '<S891>/Switch' */
extern MONPRM volatile boolean ACTCtl_bHPEXVPIEnble;/* '<S673>/AND' */
extern MONPRM volatile boolean ACTCtl_bHiPressProFlg;/* '<S823>/Switch4' */
extern MONPRM volatile boolean ACTCtl_bLowPressProFlg;/* '<S823>/Switch5' */
extern MONPRM volatile boolean ACTCtl_bMCVlearnFlg;/* '<S640>/AND2' */
extern MONPRM volatile boolean ACTCtl_bMotPMPFaultFlg;/* '<S1063>/Switch' */
extern MONPRM volatile boolean ACTCtl_bMotPMPSpdFlt;/* '<S1022>/Chart' */
extern MONPRM volatile boolean ACTCtl_bOCOLmtFlg;/* '<S501>/AND1' */
extern MONPRM volatile boolean ACTCtl_bPTCOnOrOffPwrDiff;/* '<S590>/Switch' */
extern MONPRM volatile boolean ACTCtl_bPressProtectFlg;/* '<S502>/Multiport Switch' */
extern MONPRM volatile boolean ACTCtl_bPressRateFlg;/* '<S502>/Multiport Switch1' */
extern MONPRM volatile boolean ACTCtl_bSOVCmd;/* '<S443>/Multiport Switch' */
extern MONPRM volatile uint8 ACTCtl_eACPumpRefSpd;/* '<S1020>/Multiport Switch' */
extern MONPRM volatile uint8 ACTCtl_eAcPMPSpdPerc;/* '<S1033>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eAcPMPSpdSet;/* '<S1020>/Divide' */
extern MONPRM volatile uint8 ACTCtl_eBatPMPSpdSet;/* '<S1021>/Divide' */
extern MONPRM volatile uint8 ACTCtl_eC3WVSLSts;/* '<S658>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eC3WVValue;/* '<S637>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eC5WVSLSts;/* '<S668>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eC5WVValue;/* '<S638>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eCOMPExhTPrtSts;/* '<S454>/Chart' */
extern MONPRM volatile uint8 ACTCtl_eCOMPJudgeFlg;/* '<S459>/Add' */
extern MONPRM volatile uint8 ACTCtl_eCOMPPrsPrtSts;/* '<S452>/Add' */
extern MONPRM volatile uint8 ACTCtl_eCOMPSpdSecSts;/* '<S531>/SecCal' */
extern MONPRM volatile uint8 ACTCtl_eCoolFanCtrl;/* '<S913>/cal_CoolFanCtrl_MAP' */
extern MONPRM volatile uint8 ACTCtl_eEvapProSts;/* '<S681>/EvapTemperature' */
extern MONPRM volatile uint8 ACTCtl_eFanPerc;/* '<S919>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eHeatFanCtrl;/* '<S916>/cal_HeatFanCtrl_MAP' */
extern MONPRM volatile uint8 ACTCtl_eLessThanT1Sts;/* '<S654>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eMotPMPSpdSet;/* '<S1022>/Divide' */
extern MONPRM volatile float32 ACTCtl_sACCMCtlFF;/* '<S453>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sACCMCtlSpd;/* '<S448>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sACCMI_Cor;/* '<S481>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sACCMI_Sum;/* '<S478>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sACCMPIVal;/* '<S479>/Merge' */
extern MONPRM volatile float32 ACTCtl_sACCMP_Cor;/* '<S480>/Merge' */
extern MONPRM volatile float32 ACTCtl_sAEXVActure;/* '<S671>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlBFF;/* '<S713>/cal_AEXVCtrlBFF_CUR' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlFF;/* '<S675>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlKi;/* '<S671>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlKp;/* '<S671>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sAEXVDvt;/* '<S680>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sAEXVI_Cor;/* '<S698>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sAEXVI_Sum;/* '<S695>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sAEXVPI_Cor;/* '<S696>/Merge' */
extern MONPRM volatile float32 ACTCtl_sAEXVP_Cor;/* '<S697>/Merge' */
extern MONPRM volatile float32 ACTCtl_sAEXVPos;/* '<S739>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sAEXVSetPoint;/* '<S671>/Signal Copy' */
extern MONPRM volatile float32 ACTCtl_sBEXVActure;/* '<S672>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlBFF;/* '<S781>/cal_BEXVCtrlBFF_CUR' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlFF;/* '<S750>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlKi;/* '<S672>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlKp;/* '<S672>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sBEXVDvt;/* '<S751>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sBEXVI_Cor;/* '<S766>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sBEXVI_Sum;/* '<S763>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sBEXVPI_Cor;/* '<S764>/Merge' */
extern MONPRM volatile float32 ACTCtl_sBEXVP_Cor;/* '<S765>/Merge' */
extern MONPRM volatile float32 ACTCtl_sBEXVPos;/* '<S809>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sBEXVSetPoint;/* '<S672>/Signal Copy' */
extern MONPRM volatile float32 ACTCtl_sBatHeatInletTrgT;/* '<S646>/Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPATNoiseBlwAndAccmSpd;/* '<S543>/cal_COMPATNoiseSpdLmt_MAP' */
extern MONPRM volatile float32 ACTCtl_sCOMPATNoiseLmtHVSSpd;
                                     /* '<S543>/cal_COMPATNoiseSpdLmtHVS_CUR' */
extern MONPRM volatile float32 ACTCtl_sCOMPATNoiseLmtSpd;/* '<S543>/Min' */
extern MONPRM volatile float32 ACTCtl_sCOMPActure;/* '<S437>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sCOMPCoolLmtSpd;/* '<S543>/Switch4' */
extern MONPRM volatile float32 ACTCtl_sCOMPCtrlAClsFF;/* '<S580>/cal_ACCMCtrlA2FF_MAP ' */
extern MONPRM volatile float32 ACTCtl_sCOMPCtrlKi;/* '<S437>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sCOMPCtrlKp;/* '<S437>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sCOMPDownSpd;/* '<S568>/Max1' */
extern MONPRM volatile float32 ACTCtl_sCOMPEnvLmtSpd;/* '<S544>/Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPFanlevelLmtSpd;/* '<S544>/cal_COMPFanLevelLmt_CUR' */
extern MONPRM volatile float32 ACTCtl_sCOMPHPLmtSpd;/* '<S543>/Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPLPLmtSpd;/* '<S543>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sCOMPLmtMaxSpd;/* '<S447>/Min' */
extern MONPRM volatile float32 ACTCtl_sCOMPPCULimSpd;/* '<S543>/Multiport Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPSetPoint;/* '<S437>/Signal Copy' */
extern MONPRM volatile float32 ACTCtl_sChiSuperHeat;/* '<S674>/Add5' */
extern MONPRM volatile float32 ACTCtl_sChiSuperHeatAvg;/* '<S896>/Divide' */
extern MONPRM volatile float32 ACTCtl_sChiSuperHeatAvg1;/* '<S905>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sCondDep;/* '<S674>/Add' */
extern MONPRM volatile float32 ACTCtl_sCondDepAvg;/* '<S893>/Divide' */
extern MONPRM volatile float32 ACTCtl_sCondDepAvg1;/* '<S899>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sCondDepDiff;/* '<S713>/Add' */
extern MONPRM volatile float32 ACTCtl_sCoolCondDep;/* '<S674>/Add3' */
extern MONPRM volatile float32 ACTCtl_sCoolCondDepAvg;/* '<S894>/Divide' */
extern MONPRM volatile float32 ACTCtl_sCoolCondDepAvg1;/* '<S901>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sCtrlFPTCAuxHeatPwr;
                                    /* '<S585>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern MONPRM volatile float32 ACTCtl_sDCoolBatTempDiff;/* '<S587>/Add2' */
extern MONPRM volatile float32 ACTCtl_sDCoolCabinTempDiff;/* '<S587>/Add3' */
extern MONPRM volatile float32 ACTCtl_sDvtCOMPCtrl;/* '<S450>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sEvapSuperHeat;/* '<S674>/Add4' */
extern MONPRM volatile float32 ACTCtl_sEvapSuperHeatAvg;/* '<S895>/Divide' */
extern MONPRM volatile float32 ACTCtl_sEvapSuperHeatAvg1;/* '<S903>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sExhSuperHeat;/* '<S674>/Add2' */
extern MONPRM volatile float32 ACTCtl_sExhSuperHeatAvg;/* '<S897>/Divide' */
extern MONPRM volatile float32 ACTCtl_sExhSuperHeatAvg1;/* '<S907>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVActure;/* '<S673>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlADiff;/* '<S856>/Add' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlFF;/* '<S817>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlKi;/* '<S673>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlKp;/* '<S673>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sHPEXVDvt;/* '<S822>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVI_Cor;/* '<S842>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVI_Sum;/* '<S839>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVPI_Cor;/* '<S840>/Merge' */
extern MONPRM volatile float32 ACTCtl_sHPEXVP_Cor;/* '<S841>/Merge' */
extern MONPRM volatile float32 ACTCtl_sHPEXVPos;/* '<S825>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sHPEXVSetPoint;/* '<S820>/Switch' */
extern MONPRM volatile float32 ACTCtl_sHPEXVStepLmt;/* '<S826>/Switch' */
extern MONPRM volatile float32 ACTCtl_sPTCAuxHeatPwr;/* '<S580>/cal_PTCAuxHeatPwrLmt_MAP' */
extern MONPRM volatile float32 ACTCtl_sPTCBatHeatPwrLmt;/* '<S945>/cal_PTCBatHeatPwrLmt_CUR' */
extern MONPRM volatile uint8 ACTCtl_sPTCEnable;/* '<S1011>/Switch' */
extern MONPRM volatile float32 ACTCtl_sPTCReqPower;/* '<S1018>/Switch' */
extern MONPRM volatile float32 ACTCtl_sPTCRequestTemp;/* '<S942>/Switch' */
extern MONPRM volatile float32 ACTCtl_sSOCHighPTCPwrLmt;/* '<S945>/cal_SOCHighPTCPwrLmt_CUR' */
extern MONPRM volatile float32 ACTCtl_sSuperHeat;/* '<S674>/Add1' */
extern MONPRM volatile float32 ACTCtl_sSuperHeatAvg;/* '<S898>/Divide' */
extern MONPRM volatile float32 ACTCtl_sSuperHeatAvg1;/* '<S909>/Sum1' */
extern MONPRM volatile float32 ACTCtl_tCtrlADiff;/* '<S580>/Add1' */
extern MONPRM volatile float32 ACTCtl_tCtrlBDiff;/* '<S581>/Add' */
extern MONPRM volatile float32 ACTCtl_tCtrlCDiff;/* '<S582>/Add1' */
extern MONPRM volatile uint8 AC_BlowerFanSpeedMax;/* '<S47>/MinMax' */
extern MONPRM volatile uint8 AC_BlowerFanSpeedMin;/* '<S48>/Switch4' */
extern MONPRM volatile float32 AC_DVT2PTCErr;/* '<S47>/Add' */
extern MONPRM volatile float32 AC_DVTPreSetByEnv;/* '<S182>/cal_ACDVTPreSetByEnv_MAP' */
extern MONPRM volatile float32 AC_DrEvapDesFilter;
                                     /* '<S278>/cal_DrEvapDesFilterByDvt_CUR' */
extern MONPRM volatile uint8 AC_FanLeVel;/* '<S39>/Merge' */
extern MONPRM volatile uint8 AC_FanLevelAct;/* '<S39>/Merge' */
extern MONPRM volatile float32 AC_PidCabinT_UL;
                                    /* '<S184>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern MONPRM volatile float32 AC_Ps2DrSetTempDvt;/* '<S179>/Sum2' */
extern MONPRM volatile float32 AC_PsEvapDesFilter;
                                     /* '<S303>/cal_PsEvapDesFilterByDvt_CUR' */
extern MONPRM volatile uint8 AC_rRecircInc;/* '<S53>/Data Type Conversion' */
extern MONPRM volatile uint16 AC_rSolarRight;/* '<S1788>/Switch' */
extern MONPRM volatile uint16 AC_rSunloadFlt;/* '<S207>/Saturation' */
extern MONPRM volatile boolean AC_stExhaust;/* '<S4>/stExhaustFunCheck' */
extern MONPRM volatile boolean AC_stIGNON;/* '<S1253>/Switch1' */
extern MONPRM volatile float32 AC_tEnvInvent;/* '<S183>/TempRampBaseTimeAndStep' */
extern MONPRM volatile uint16 AC_tiAfterRun;/* '<S1265>/Switch' */
extern MONPRM volatile uint8 AcPMP_HWVersion;/* '<S14>/Signal Copy114' */
extern MONPRM volatile uint8 AcPMP_PartNumber;/* '<S14>/Signal Copy113' */
extern MONPRM volatile uint8 AcPMP_ProjectCode1;/* '<S14>/Signal Copy110' */
extern MONPRM volatile uint8 AcPMP_ProjectCode2;/* '<S14>/Signal Copy111' */
extern MONPRM volatile boolean AcPMP_PumpDryRunningSta;/* '<S14>/Signal Copy105' */
extern MONPRM volatile uint8 AcPMP_PumpInputVolt;/* '<S14>/Signal Copy108' */
extern MONPRM volatile uint8 AcPMP_PumpMotorSta;/* '<S14>/Signal Copy104' */
extern MONPRM volatile uint8 AcPMP_PumpPowerSta;/* '<S14>/Signal Copy106' */
extern MONPRM volatile uint8 AcPMP_PumpTempSta;/* '<S14>/Signal Copy107' */
extern MONPRM volatile boolean AcPMP_RESP_ERROR;/* '<S14>/Signal Copy103' */
extern MONPRM volatile float32 AcPMP_RealRPM;/* '<S1243>/Gain' */
extern MONPRM volatile uint8 AcPMP_SWVersion_Main;/* '<S14>/Signal Copy115' */
extern MONPRM volatile uint8 AcPMP_SWVersion_Patch;/* '<S14>/Signal Copy117' */
extern MONPRM volatile uint8 AcPMP_SWVersion_Sub;/* '<S14>/Signal Copy116' */
extern MONPRM volatile uint8 AcPMP_SupplierNumber;/* '<S14>/Signal Copy112' */
extern MONPRM volatile uint8 BAT_EXV_CurrentInitState_B;/* '<S16>/Signal Copy35' */
extern MONPRM volatile float32 BAT_EXV_CurrentPosition_B;/* '<S1245>/Gain' */
extern MONPRM volatile uint8 BAT_EXV_FaultState_B;/* '<S16>/Signal Copy37' */
extern MONPRM volatile boolean BAT_EXV_ResponseError_B;/* '<S16>/Signal Copy34' */
extern MONPRM volatile boolean BAT_EXV_RunState_B;/* '<S16>/Signal Copy36' */
extern MONPRM volatile boolean BAT_EXV_SupplierLabel;/* '<S16>/Signal Copy40' */
extern MONPRM volatile uint8 BAT_EXV_TemperatureWarn_B;/* '<S1245>/Data Type Conversion' */
extern MONPRM volatile uint8 BAT_EXV_VoltageState_B;/* '<S16>/Signal Copy38' */
extern MONPRM volatile boolean BCV_ErrResp;/* '<S15>/Signal Copy73' */
extern MONPRM volatile uint8 BCV_FltSts;/* '<S15>/Signal Copy66' */
extern MONPRM volatile uint8 BCV_Mode; /* '<S15>/Signal Copy67' */
extern MONPRM volatile uint16 BCV_PosRec;/* '<S15>/Signal Copy68' */
extern MONPRM volatile boolean BCV_RunSts;/* '<S15>/Signal Copy69' */
extern MONPRM volatile uint8 BCV_SpdLvl;/* '<S15>/Signal Copy70' */
extern MONPRM volatile uint8 BCV_TempSts;/* '<S15>/Signal Copy71' */
extern MONPRM volatile uint8 BCV_VoltSts;/* '<S15>/Signal Copy72' */
extern MONPRM volatile float32 BMS_BatSOCAct_pct;/* '<S2>/Signal Copy1' */
extern MONPRM volatile float32 BMS_HVBatCellTempAve;/* '<S2>/Signal Copy159' */
extern MONPRM volatile float32 BMS_HVBatCellTempMax;/* '<S2>/Signal Copy160' */
extern MONPRM volatile float32 BMS_HVBatCellTempMin;/* '<S2>/Signal Copy161' */
extern MONPRM volatile float32 BMS_InletCooltActlTemp;/* '<S2>/Signal Copy147' */
extern MONPRM volatile boolean BatPMP_PumpDryRunningSta;/* '<S18>/Signal Copy91' */
extern MONPRM volatile uint8 BatPMP_PumpInputVolt;/* '<S18>/Signal Copy94' */
extern MONPRM volatile uint8 BatPMP_PumpMotorSta;/* '<S18>/Signal Copy90' */
extern MONPRM volatile uint8 BatPMP_PumpPowerSta;/* '<S18>/Signal Copy92' */
extern MONPRM volatile uint8 BatPMP_PumpTempSta;/* '<S18>/Signal Copy93' */
extern MONPRM volatile boolean BatPMP_RESP_ERROR;/* '<S18>/Signal Copy89' */
extern MONPRM volatile float32 BatPMP_RealRPM;/* '<S1246>/Gain' */
extern MONPRM volatile uint8 Bat_EXV_HWVersion;/* '<S16>/Signal Copy46' */
extern MONPRM volatile uint8 Bat_EXV_PartNumber;/* '<S16>/Signal Copy45' */
extern MONPRM volatile uint8 Bat_EXV_ProjectCode1;/* '<S16>/Signal Copy42' */
extern MONPRM volatile uint8 Bat_EXV_ProjectCode2;/* '<S16>/Signal Copy43' */
extern MONPRM volatile uint8 Bat_EXV_SWVersion_Main;/* '<S16>/Signal Copy47' */
extern MONPRM volatile uint8 Bat_EXV_SWVersion_Patch;/* '<S16>/Signal Copy49' */
extern MONPRM volatile uint8 Bat_EXV_SWVersion_Sub;/* '<S16>/Signal Copy48' */
extern MONPRM volatile uint8 Bat_EXV_SupplierNumber;/* '<S16>/Signal Copy44' */
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
                                     /* '<S182>/cal_CabinDesTempSolarCor_MAP' */
extern MONPRM volatile float32 CabinDesTempSolarCorECO;
                                  /* '<S182>/cal_CabinDesTempSolarCorECO_MAP' */
extern MONPRM volatile boolean CoAC_stColdStart;/* '<S1254>/Switch3' */
extern MONPRM volatile uint8 CoAC_stwork;/* '<S28>/Switch1' */
extern MONPRM volatile float32 ColdPCUTempMinByEnv;
                                     /* '<S1703>/cal_ColdPCUTempMinByEnv_CUR' */
extern MONPRM volatile float32 ColdStartPCUTempMinByEnv;
                                /* '<S1261>/cal_ColdStartPCUTempMinByEnv_CUR' */
extern MONPRM volatile boolean ECUHighVoltInterlockSignal;/* '<S2>/Signal Copy137' */
extern MONPRM volatile float32 EE_PCUInletTemp;/* '<S1261>/Data Store Read1' */
extern MONPRM volatile uint8 EE_TimeDay;/* '<S1262>/Data Store Read3' */
extern MONPRM volatile uint8 EE_TimeHour;/* '<S1262>/Data Store Read' */
extern MONPRM volatile uint8 EE_TimeMin;/* '<S1262>/Data Store Read2' */
extern MONPRM volatile float32 EE_tEnv;/* '<S1261>/Data Store Read' */
extern MONPRM volatile uint8 EXV_CurrentInitState;/* '<S13>/Signal Copy97' */
extern MONPRM volatile float32 EXV_CurrentPosition;/* '<S1242>/Gain' */
extern MONPRM volatile uint8 EXV_FaultState;/* '<S13>/Signal Copy99' */
extern MONPRM volatile boolean EXV_ResponseError;/* '<S13>/Signal Copy96' */
extern MONPRM volatile boolean EXV_RunState;/* '<S13>/Signal Copy98' */
extern MONPRM volatile uint8 EXV_TemperatureWarn;/* '<S13>/Signal Copy101' */
extern MONPRM volatile uint8 EXV_VoltageState;/* '<S13>/Signal Copy100' */
extern MONPRM volatile float32 Eva_CloseCond1;/* '<S175>/Add2' */
extern MONPRM volatile float32 Eva_CooledCond1;/* '<S175>/Add3' */
extern MONPRM volatile float32 Eva_CoolingCond1;/* '<S175>/Add' */
extern MONPRM volatile float32 Eva_CoolingCond2;/* '<S175>/Add1' */
extern MONPRM volatile float32 EvapDesTempDrCabinCor;
                                      /* '<S279>/cal_EvapDesTempCabinCor_CUR' */
extern MONPRM volatile float32 EvapDesTempDrEnvCor;/* '<S279>/cal_EvapDesTempEnvCor_MAP' */
extern MONPRM volatile float32 EvapDesTempDrFanCor;/* '<S279>/cal_EvapDesTempFanCor_CUR' */
extern MONPRM volatile float32 EvapDesTempPsCabinCor;
                                    /* '<S304>/cal_EvapDesTempPsCabinCor_CUR' */
extern MONPRM volatile float32 EvapDesTempPsEnvCor;
                                      /* '<S304>/cal_EvapDesTempPsEnvCor_MAP' */
extern MONPRM volatile float32 EvapDesTempPsFanCor;
                                      /* '<S304>/cal_EvapDesTempPsFanCor_CUR' */
extern MONPRM volatile uint16 GlbDa_LeftSolar;/* '<S178>/Data Type Conversion1' */
extern MONPRM volatile uint16 GlbDa_LeftSolarAvr;/* '<S53>/Add1' */
extern MONPRM volatile uint16 GlbDa_RightSolar;/* '<S179>/Data Type Conversion' */
extern MONPRM volatile uint16 GlbDa_Solar;/* '<S276>/Max1' */
extern MONPRM volatile float32 GlbDa_tCabinInvent;/* '<S173>/Switch2' */
extern MONPRM volatile uint16 GlbDa_uBat;/* '<S2>/Constant2' */
extern MONPRM volatile boolean HMICtl_bACAuto;/* '<S1145>/Switch' */
extern MONPRM volatile boolean HMICtl_bACDefrost;/* '<S1159>/Switch' */
extern MONPRM volatile boolean HMICtl_bACOnOff;/* '<S1171>/Switch' */
extern MONPRM volatile boolean HMICtl_bLeftSetHigh;/* '<S1126>/Switch' */
extern MONPRM volatile boolean HMICtl_bLeftSetLow;/* '<S1127>/Switch' */
extern MONPRM volatile uint8 HMICtl_eACSts;/* '<S1183>/Switch' */
extern MONPRM volatile uint8 HMICtl_eBlwSts;/* '<S1092>/Switch' */
extern MONPRM volatile uint8 HMICtl_eInner;/* '<S1108>/Switch' */
extern MONPRM volatile uint8 HMICtl_eModeMotor;/* '<S1115>/Switch' */
extern MONPRM volatile float32 HMICtl_sLeftSetPoint;/* '<S1128>/Switch' */
extern MONPRM volatile float32 HMICtl_sMixDoor;/* '<S1110>/Switch' */
extern MONPRM volatile float32 HP_EXV_CurrentPosition_B;/* '<S1247>/Gain' */
extern MONPRM volatile uint8 HP_EXV_FaultState_B;/* '<S20>/Signal Copy23' */
extern MONPRM volatile uint8 HP_EXV_HWVersion;/* '<S20>/Signal Copy30' */
extern MONPRM volatile uint8 HP_EXV_PartNumber;/* '<S20>/Signal Copy29' */
extern MONPRM volatile uint8 HP_EXV_ProjectCode1;/* '<S20>/Signal Copy26' */
extern MONPRM volatile uint8 HP_EXV_ProjectCode2;/* '<S20>/Signal Copy27' */
extern MONPRM volatile boolean HP_EXV_ResponseError_B;/* '<S20>/Signal Copy21' */
extern MONPRM volatile boolean HP_EXV_RunState_B;/* '<S20>/Signal Copy22' */
extern MONPRM volatile uint8 HP_EXV_SWVersion_Main;/* '<S20>/Signal Copy31' */
extern MONPRM volatile uint8 HP_EXV_SWVersion_Patch;/* '<S20>/Signal Copy33' */
extern MONPRM volatile uint8 HP_EXV_SWVersion_Sub;/* '<S20>/Signal Copy32' */
extern MONPRM volatile boolean HP_EXV_SupplierLabel;/* '<S20>/Signal Copy19' */
extern MONPRM volatile uint8 HP_EXV_SupplierNumber;/* '<S20>/Signal Copy28' */
extern MONPRM volatile uint8 HP_EXV_VoltageState_B;/* '<S20>/Signal Copy24' */
extern MONPRM volatile boolean HP_EXV_Warning_OverTemp;/* '<S20>/Signal Copy20' */
extern MONPRM volatile uint8 HP_EXV_initialize_status;/* '<S20>/Signal Copy18' */
extern MONPRM volatile uint8 HU_LeftTempSet;/* '<S2>/Signal Copy200' */
extern MONPRM volatile uint8 IOCtl_BloweFanSpeed;/* '<S1204>/Switch' */
extern MONPRM volatile boolean IOCtl_PwrNmReqFlg;/* '<S1190>/Relational Operator' */
extern MONPRM volatile uint8 IOCtl_RecircTrgPos;/* '<S1223>/Switch' */
extern MONPRM volatile boolean IOCtl_bModeMoveSts;/* '<S1196>/Signal Copy' */
extern MONPRM volatile float32 IOCtl_sMixDoorTrgPos;/* '<S1230>/Switch' */
extern MONPRM volatile float32 IOCtl_sModeMotorTrgPos;/* '<S1235>/Switch' */
extern MONPRM volatile boolean MCV_ErrResp;/* '<S22>/Signal Copy57' */
extern MONPRM volatile uint8 MCV_FltSts;/* '<S22>/Signal Copy50' */
extern MONPRM volatile uint8 MCV_Mode; /* '<S22>/Signal Copy51' */
extern MONPRM volatile uint16 MCV_PosRec;/* '<S22>/Signal Copy52' */
extern MONPRM volatile boolean MCV_RunSts;/* '<S22>/Signal Copy53' */
extern MONPRM volatile uint8 MCV_SpdLvl;/* '<S22>/Signal Copy54' */
extern MONPRM volatile uint8 MCV_TempSts;/* '<S22>/Signal Copy55' */
extern MONPRM volatile uint8 MCV_VoltSts;/* '<S22>/Signal Copy56' */
extern MONPRM volatile boolean MotPMP_PumpDryRunningSta;/* '<S23>/Signal Copy84' */
extern MONPRM volatile uint8 MotPMP_PumpInputVolt;/* '<S23>/Signal Copy87' */
extern MONPRM volatile uint8 MotPMP_PumpMotorSta;/* '<S23>/Signal Copy83' */
extern MONPRM volatile uint8 MotPMP_PumpPowerSta;/* '<S23>/Signal Copy85' */
extern MONPRM volatile uint8 MotPMP_PumpTempSta;/* '<S23>/Signal Copy86' */
extern MONPRM volatile boolean MotPMP_RESP_ERROR;/* '<S23>/Signal Copy82' */
extern MONPRM volatile float32 MotPMP_RealRPM;/* '<S1249>/Gain' */
extern MONPRM volatile float32 PCU_StartClntTemp;/* '<S1261>/Data Type Conversion' */
extern MONPRM volatile float32 PCUtempOffset2ShutByEnv;
                                 /* '<S1261>/cal_PCUtempOffset2ShutByEnv_CUR' */
extern MONPRM volatile boolean PWRCtl_bKL15swtSt;/* '<S2>/OR' */
extern MONPRM volatile uint8 PWRCtl_eBatChargSts;/* '<S28>/CoBatCharg' */
extern MONPRM volatile PwrModes PWRCtl_eTMSStatus;/* '<S1258>/Switch' */
extern MONPRM volatile uint8 PWRCtl_eVCUPTSts;/* '<S2>/Signal Copy183' */
extern MONPRM volatile float32 PWRCtl_sCOMPActlPwr;/* '<S29>/Divide1' */
extern MONPRM volatile uint32 PWRCtl_uTMSRunTimer;/* '<S28>/Cal_RunTime' */
extern MONPRM volatile uint32 PWRCtl_uTMSRunTimer20ms;/* '<S31>/Cal_RunTime_20ms' */
extern MONPRM volatile float32 PidCabinX_IsumMax;
                                   /* '<S184>/cal_PidCabinX_IsumMaxByDVT_CUR' */
extern MONPRM volatile float32 PidCabinX_IsumMin;
                                   /* '<S184>/cal_PidCabinX_IsumMinByDVT_CUR' */
extern MONPRM volatile uint16 SENCtl_uACCMHighTempVol;/* '<S1720>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uCabinVoltage;/* '<S1701>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uChillTempVol;/* '<S1712>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uEVAPSurfTempVol;/* '<S1715>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uEVAPXTempVol;/* '<S1714>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uEnvVoltage;/* '<S1713>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uFaceDuctVal;/* '<S1705>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uFootDuctVal;/* '<S1706>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uMixDoorVol;/* '<S1708>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uModeDoorVol;/* '<S1709>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uMotInletTempVol;/* '<S1716>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uOHXTempVol;/* '<S1717>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uRecircDoorVol;/* '<S1710>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uSolorVol;/* '<S1711>/C_Caller' */
extern MONPRM volatile uint16 SENCtl_uWCCHPVol;/* '<S1719>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uWCCHighTempVol;/* '<S1718>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uWCCLPVol;/* '<S1707>/C Caller' */
extern MONPRM volatile float32 SEN_ACCMTHiRaw;/* '<S1720>/cal_ACCMTHi_CUR' */
extern MONPRM volatile float32 SEN_ChiTRaw;/* '<S1712>/cal_TChillOutRaw_CUR' */
extern MONPRM volatile float32 SEN_EvapTRaw;/* '<S1714>/cal_TEvapOutRaw_CUR' */
extern MONPRM volatile float32 SEN_LoPressRaw;/* '<S1707>/cal_LoPress_CUR' */
extern MONPRM volatile float32 SEN_MixDoorRaw;/* '<S1708>/cal_MixDoorPerc_CUR' */
extern MONPRM volatile float32 SEN_OHXTRaw;/* '<S1717>/cal_OHXTRaw_CUR' */
extern MONPRM volatile uint16 SEN_SolarRaw;/* '<S1711>/cal_SolarValRaw_CUR' */
extern MONPRM volatile float32 SEN_TCabinRaw;/* '<S1701>/cal_TCabinRaw_CUR' */
extern MONPRM volatile float32 SEN_TDuctRaw;/* '<S1705>/cal_TDuctRaw_CUR' */
extern MONPRM volatile float32 SEN_TEnvRaw;/* '<S1713>/cal_TEnvRaw_CUR' */
extern MONPRM volatile float32 SEN_TEvapSurRaw;/* '<S1715>/cal_TEvapSur_CUR' */
extern MONPRM volatile float32 SEN_TFootDuctRaw;/* '<S1706>/cal_TDuctRaw_CUR' */
extern MONPRM volatile float32 SEN_TMotRaw;/* '<S1716>/cal_TMot_CUR' */
extern MONPRM volatile float32 SEN_WCCHiPressRaw;/* '<S1719>/cal_LCCOutHiPressRaw_CUR' */
extern MONPRM volatile float32 SEN_WCCTHiRaw;/* '<S1718>/cal_WCCTHiRaw_CUR' */
extern MONPRM volatile boolean SOMCtl_bB1toB31;/* '<S1287>/Switch1' */
extern MONPRM volatile boolean SOMCtl_bBatB1TB41Flg;/* '<S1446>/OR2' */
extern MONPRM volatile boolean SOMCtl_bBatB1TB42Flg;/* '<S1459>/OR2' */
extern MONPRM volatile boolean SOMCtl_bBatBalEntBFlg;/* '<S1595>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatBalFlg;/* '<S1280>/Judge' */
extern MONPRM volatile boolean SOMCtl_bBatCoolFlg;/* '<S1357>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatHStrFlg;/* '<S1535>/Chart' */
extern MONPRM volatile boolean SOMCtl_bBatHeatB31tB1Flg;/* '<S1538>/AND3' */
extern MONPRM volatile boolean SOMCtl_bBatHeatB3tB1Flg;/* '<S1287>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatHeatChrgFlgAB;/* '<S1442>/AND2' */
extern MONPRM volatile boolean SOMCtl_bBatHeatChrgFlgCD;/* '<S1443>/NOT' */
extern MONPRM volatile boolean SOMCtl_bBatHeatFlg;/* '<S1440>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatHeatOffFlg;/* '<S1470>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bBatHeatPwrLmtF;/* '<S1445>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bBatHeatTempDiffE;/* '<S1452>/Compare' */
extern MONPRM volatile boolean SOMCtl_bBatLTRFlg;/* '<S1282>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatLTROffFlg;/* '<S1400>/AND7' */
extern MONPRM volatile boolean SOMCtl_bBatTSEntAFlg;/* '<S1320>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatTSEntBFlg;/* '<S1321>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatTSExitFlg;/* '<S1300>/AND1' */
extern MONPRM volatile boolean SOMCtl_bCalTempBatHeatFlg;/* '<S1441>/Merge' */
extern MONPRM volatile boolean SOMCtl_bDBatLTROffFlg;/* '<S1502>/AND7' */
extern MONPRM volatile boolean SOMCtl_bDCBatLTROnFlg;/* '<S1399>/AND1' */
extern MONPRM volatile boolean SOMCtl_bEntExtDefFlg;/* '<S1690>/AND' */
extern MONPRM volatile boolean SOMCtl_bExitExtDefTempFlg;/* '<S1695>/Compare' */
extern MONPRM volatile boolean SOMCtl_bExtDefFlg;/* '<S1693>/Switch' */
extern MONPRM volatile boolean SOMCtl_bMD1CLMSts;/* '<S1639>/Chart' */
extern MONPRM volatile boolean SOMCtl_bMD1ToMD2Flg;/* '<S1638>/C' */
extern MONPRM volatile boolean SOMCtl_bMD2DHMD1Flg;/* '<S1640>/MD2_DHMD1' */
extern MONPRM volatile boolean SOMCtl_bMD2ToMD1Flg;/* '<S1638>/OR7' */
extern MONPRM volatile boolean SOMCtl_bMD2ToMD3Flg;/* '<S1641>/B' */
extern MONPRM volatile boolean SOMCtl_bMD3DHMD2Flg;/* '<S1642>/MD3_DHMD2' */
extern MONPRM volatile boolean SOMCtl_bMD3ToMD2Flg;/* '<S1641>/A' */
extern MONPRM volatile boolean SOMCtl_bMD3ToMD4Flg;/* '<S1643>/B' */
extern MONPRM volatile boolean SOMCtl_bMD4ToMD3Flg;/* '<S1643>/A' */
extern MONPRM volatile boolean SOMCtl_bMotAndBatLTRFlg;/* '<S1286>/Switch' */
extern MONPRM volatile boolean SOMCtl_bMotHeatBatFlg;/* '<S1288>/Switch' */
extern MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOffFlg;/* '<S1594>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOn1Flg;/* '<S1501>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOn2Flg;/* '<S1501>/Relational Operator1' */
extern MONPRM volatile boolean SOMCtl_bMotorHeatBatOffFlg;/* '<S1574>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bMotorHeatBatOnFlg;/* '<S1288>/Switch1' */
extern MONPRM volatile boolean SOMCtl_bMotorLTRAndBatBalFlg;/* '<S1289>/Switch' */
extern MONPRM volatile boolean SOMCtl_bNmlBatLTROnFlg;/* '<S1399>/Relational Operator' */
extern MONPRM volatile uint8 SOMCtl_eBatBalEntBFlg;/* '<S1595>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatCoolB1tB21;/* '<S1362>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatCoolB1tB22;/* '<S1373>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatCoolB2tB1;/* '<S1383>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatHeatOffVal;/* '<S1470>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatLTROnFlg;/* '<S1598>/Add' */
extern MONPRM volatile BatModes SOMCtl_eBatMode;/* '<S1435>/Switch' */
extern MONPRM volatile CabinMode SOMCtl_eCabinMode;/* '<S1688>/Switch' */
extern MONPRM volatile CabinMode SOMCtl_eCabinModePre;/* '<S1645>/Data Type Conversion2' */
extern MONPRM volatile uint8 SOMCtl_eHVPartMode;/* '<S1696>/Switch' */
extern MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOffFlg;/* '<S1594>/Add' */
extern MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOn1Flg;/* '<S1501>/Add' */
extern MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOn2Flg;/* '<S1501>/Add1' */
extern MONPRM volatile uint8 SOMCtl_eMotorHeatBat2Flg;/* '<S1572>/Add' */
extern MONPRM volatile uint8 SOMCtl_eMotorHeatBatFlg;/* '<S1573>/Add' */
extern MONPRM volatile uint16 SOMCtl_eMotorHeatBatOffFlg;/* '<S1574>/Add' */
extern MONPRM volatile uint8 SOMCtl_eNmlBatLTROnFlg;/* '<S1399>/Add' */
extern MONPRM volatile RefModes SOMCtl_eRefModes;/* '<S1697>/Switch' */
extern MONPRM volatile WaterModes SOMCtl_eWaterMode;/* '<S1689>/Switch' */
extern MONPRM volatile float32 SOMCtl_sBatHeatPTCTrgT;/* '<S1493>/Switch' */
extern MONPRM volatile float32 SOMCtl_sBatHeatT1;/* '<S1441>/Merge' */
extern MONPRM volatile float32 SOMCtl_sBatHeatT2;/* '<S1441>/Merge' */
extern MONPRM volatile float32 SOMCtl_sBatHeatTrgTempComp;
                                      /* '<S1493>/cal_BatHeatTrgTempComp_CUR' */
extern MONPRM volatile float32 SOMCtl_sBatTrgTemp;/* '<S1292>/Switch' */
extern MONPRM volatile float32 SOMCtl_sF1Value;/* '<S1637>/Add' */
extern MONPRM volatile float32 SOMCtl_sF2Value;/* '<S1637>/Add1' */
extern MONPRM volatile boolean SOMCtrl_bBatLTRDelayFlg;/* '<S1400>/Delay' */
extern MONPRM volatile uint8 TMS_VersionNumber;/* '<S7>/Constant1' */
extern MONPRM volatile float32 ThCo_rSetLeftMixDoor;/* '<S385>/Switch3' */
extern MONPRM volatile float32 ThCo_rSetRightMixDoor;/* '<S385>/Switch2' */
extern MONPRM volatile uint16 adc2_group0_0;/* '<S1700>/Signal Copy' */
extern MONPRM volatile uint16 adc2_group0_1;/* '<S1700>/Signal Copy1' */
extern MONPRM volatile uint16 adc2_group0_2;/* '<S1700>/Signal Copy2' */
extern MONPRM volatile uint16 adc2_group1_0;/* '<S1700>/Signal Copy3' */
extern MONPRM volatile uint16 adc2_group1_1;/* '<S1700>/Signal Copy4' */
extern MONPRM volatile uint16 adc2_group1_2;/* '<S1700>/Signal Copy5' */
extern MONPRM volatile uint16 adc2_group1_3;/* '<S1700>/Signal Copy6' */
extern MONPRM volatile uint16 adc2_group1_4;/* '<S1700>/Signal Copy7' */
extern MONPRM volatile uint16 adc2_group1_5;/* '<S1700>/Signal Copy8' */
extern MONPRM volatile uint16 adc2_group1_6;/* '<S1700>/Signal Copy9' */
extern MONPRM volatile uint16 adc2_group1_7;/* '<S1700>/Signal Copy10' */
extern MONPRM volatile uint16 adc2_group1_8;/* '<S1700>/Signal Copy11' */
extern MONPRM volatile uint16 adc2_group1_9;/* '<S1700>/Signal Copy12' */
extern MONPRM volatile uint16 adc2_group2_0;/* '<S1700>/Signal Copy17' */
extern MONPRM volatile uint16 adc2_group2_1;/* '<S1700>/Signal Copy18' */
extern MONPRM volatile uint16 adc2_group2_2;/* '<S1700>/Signal Copy19' */
extern MONPRM volatile uint16 adc2_group2_3;/* '<S1700>/Signal Copy13' */
extern MONPRM volatile uint16 adc2_group2_4;/* '<S1700>/Signal Copy14' */

#endif                                 /* RTW_HEADER_TMS_MonitorData_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
