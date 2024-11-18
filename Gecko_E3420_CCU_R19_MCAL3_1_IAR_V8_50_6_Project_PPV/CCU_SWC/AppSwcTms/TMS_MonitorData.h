/*
 * File: TMS_MonitorData.h
 *
 * Code generated for Simulink model 'ME11'.
 *
 * Model version                  : 1.2326
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Nov 14 16:10:51 2024
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
extern MONPRM volatile float32 ACCCtl_sACCabinPreSetByEnv;/* '<S187>/cal_ACCabinPreSetByEnv_MAP' */
extern MONPRM volatile float32 ACCCtl_sACCabinPreSetByEnvECO;
                                    /* '<S187>/cal_ACCabinPreSetByEnvECO_MAP' */
extern MONPRM volatile float32 ACCCtl_sBlowerFanSpd;/* '<S58>/MinMax' */
extern MONPRM volatile float32 ACCCtl_sSetPtcDesTempMax;/* '<S181>/cal_SetPtcDesTempMax_MAP' */
extern MONPRM volatile uint8 ACCtl_BloweFanSpeed;/* '<S44>/Merge' */
extern MONPRM volatile BlowerModes ACCtl_BlowerMode;/* '<S45>/Merge' */
extern MONPRM volatile float32 ACCtl_DVTIDeadBand;/* '<S189>/Constant7' */
extern MONPRM volatile float32 ACCtl_DrfacPtc2NominalTemp;/* '<S393>/Switch4' */
extern MONPRM volatile uint8 ACCtl_IntakeRatio;/* '<S49>/Merge' */
extern MONPRM volatile float32 ACCtl_PsfacPtc2NominalTemp;/* '<S419>/Switch4' */
extern MONPRM volatile float32 ACCtl_RFace2FaceFloor;
                                      /* '<S82>/cal_RFace2FaceFloorByEnv_CUR' */
extern MONPRM volatile float32 ACCtl_RFaceFloor2Face;
                                      /* '<S82>/cal_RFaceFloor2FaceByEnv_CUR' */
extern MONPRM volatile float32 ACCtl_RFaceFloor2Floor;
                                     /* '<S82>/cal_RFaceFloor2FloorByEnv_CUR' */
extern MONPRM volatile float32 ACCtl_RFloor2FaceFloor;
                                     /* '<S82>/cal_RFloor2FaceFloorByEnv_CUR' */
extern MONPRM volatile boolean ACCtl_bExhFlg;/* '<S1094>/Switch' */
extern MONPRM volatile boolean ACCtl_bExhaustFlg;/* '<S11>/AND2' */
extern MONPRM volatile uint16 ACCtl_pwrHeatingFeed;/* '<S96>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern MONPRM volatile float32 ACCtl_pwrHeatingICor;/* '<S107>/Merge1' */
extern MONPRM volatile float32 ACCtl_pwrHeatingISum;/* '<S103>/Switch1' */
extern MONPRM volatile float32 ACCtl_pwrHeatingPCor;/* '<S106>/Merge' */
extern MONPRM volatile uint16 ACCtl_pwrHeatingReq;/* '<S40>/Signal Copy' */
extern MONPRM volatile uint8 ACCtl_rDrBasicMixDoor;/* '<S391>/Switch6' */
extern MONPRM volatile uint8 ACCtl_rDrMixDoorDes;/* '<S392>/Data Type Conversion' */
extern MONPRM volatile float32 ACCtl_rDrSetMixDoorICor;/* '<S402>/Merge1' */
extern MONPRM volatile float32 ACCtl_rDrSetMixDoorISum;/* '<S398>/Switch1' */
extern MONPRM volatile float32 ACCtl_rDrSetMixDoorPCor;/* '<S401>/Merge' */
extern MONPRM volatile uint8 ACCtl_rPsBasicMixDoor;/* '<S417>/Switch6' */
extern MONPRM volatile float32 ACCtl_rPsBlowerModeSet;/* '<S417>/Multiport Switch2' */
extern MONPRM volatile uint8 ACCtl_rPsMixDoorDes;/* '<S418>/Data Type Conversion' */
extern MONPRM volatile float32 ACCtl_rPsSetMixDoorICor;/* '<S426>/Merge1' */
extern MONPRM volatile float32 ACCtl_rPsSetMixDoorISum;/* '<S422>/Switch1' */
extern MONPRM volatile float32 ACCtl_rPsSetMixDoorPCor;/* '<S425>/Merge' */
extern MONPRM volatile float32 ACCtl_sECOEvaDesValLL;/* '<S180>/cal_ECOEvaDesValLL_MAP' */
extern MONPRM volatile float32 ACCtl_sMixDoorClsFF;/* '<S392>/Switch' */
extern MONPRM volatile boolean ACCtl_stACPTCHeated;/* '<S181>/PTCHeatedCheck' */
extern MONPRM volatile boolean ACCtl_stCabinCoolingEn;/* '<S46>/Merge' */
extern MONPRM volatile boolean ACCtl_stCabinHeatingEn;/* '<S95>/Logical Operator' */
extern MONPRM volatile uint8 ACCtl_stDvtPIDFreez;/* '<S192>/Merge' */
extern MONPRM volatile boolean ACCtl_stEvaCooledFlag;/* '<S180>/EvaCooledCheck' */
extern MONPRM volatile boolean ACCtl_stRecACHotStartEna;/* '<S128>/Relational Operator5' */
extern MONPRM volatile boolean ACCtl_stRecAQSEna;/* '<S129>/Recirc_AQS' */
extern MONPRM volatile boolean ACCtl_stRecForceChangeEna;/* '<S130>/Switch3' */
extern MONPRM volatile boolean ACCtl_stRecForceDefogEna;/* '<S131>/Relational Operator' */
extern MONPRM volatile uint8 ACCtl_stRecLevelFinal;/* '<S40>/Max' */
extern MONPRM volatile boolean ACCtl_stRecManualEna;/* '<S127>/Logical Operator' */
extern MONPRM volatile boolean ACCtl_stRecNormalDefogEna;/* '<S132>/Logical Operator' */
extern MONPRM volatile boolean ACCtl_stRecOut;/* '<S49>/Merge' */
extern MONPRM volatile boolean ACCtl_stRecPCUTempEna;/* '<S133>/Switch' */
extern MONPRM volatile boolean ACCtl_stRecPTCDvtEna;/* '<S134>/Switch1' */
extern MONPRM volatile boolean ACCtl_stRecQkChargeCoolingEna;/* '<S135>/Logical Operator' */
extern MONPRM volatile boolean ACCtl_stRecRemoteACEna;/* '<S136>/Relational Operator3' */
extern MONPRM volatile boolean ACCtl_stRecSummerCondEna;/* '<S137>/Relational Operator4' */
extern MONPRM volatile boolean ACCtl_stRecTargetOutTempEna;/* '<S138>/Switch1' */
extern MONPRM volatile boolean ACCtl_stRecTempLowEna;/* '<S37>/OR' */
extern MONPRM volatile boolean ACCtl_stRecVentEna;/* '<S140>/Logical Operator2' */
extern MONPRM volatile boolean ACCtl_stRecWinterCondEna;/* '<S141>/Relational Operator4' */
extern MONPRM volatile uint8 ACCtl_stStartState;/* '<S41>/AirConditionStartState' */
extern MONPRM volatile float32 ACCtl_tDVTFeedfoward;/* '<S210>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDVTFlt;/* '<S60>/Add' */
extern MONPRM volatile float32 ACCtl_tDVTPIBas;/* '<S192>/Merge' */
extern MONPRM volatile float32 ACCtl_tDesFrontCabin;/* '<S187>/Switch3' */
extern MONPRM volatile float32 ACCtl_tDrDVT;/* '<S183>/Switch3' */
extern MONPRM volatile float32 ACCtl_tDrDVTSolarCor;/* '<S183>/cal_ACDrDVTSolarCor_MAP' */
extern MONPRM volatile float32 ACCtl_tDrEvapDes;/* '<S285>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDrEvapDesPI;/* '<S288>/Merge' */
extern MONPRM volatile float32 ACCtl_tDrEvapICor;/* '<S291>/Merge1' */
extern MONPRM volatile float32 ACCtl_tDrEvapISum;/* '<S286>/Switch1' */
extern MONPRM volatile float32 ACCtl_tDrEvapPCor;/* '<S290>/Merge' */
extern MONPRM volatile float32 ACCtl_tDrPTCICor;/* '<S350>/Merge1' */
extern MONPRM volatile float32 ACCtl_tDrPTCISum;/* '<S346>/Switch1' */
extern MONPRM volatile float32 ACCtl_tDrPTCPCor;/* '<S349>/Merge' */
extern MONPRM volatile float32 ACCtl_tDrSetBasicEvap;/* '<S307>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDrSetBasicPTC;/* '<S345>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDvtICor;/* '<S194>/Merge1' */
extern MONPRM volatile float32 ACCtl_tDvtISum;/* '<S190>/Switch1' */
extern MONPRM volatile float32 ACCtl_tDvtPCor;/* '<S193>/Merge' */
extern MONPRM volatile float32 ACCtl_tErrACPTC;/* '<S104>/Switch1' */
extern MONPRM volatile boolean ACCtl_tErrACPTCPosFlag;/* '<S104>/Relational Operator' */
extern MONPRM volatile float32 ACCtl_tErrDVT;/* '<S191>/Switch1' */
extern MONPRM volatile boolean ACCtl_tErrDVTFlag;/* '<S191>/Relational Operator' */
extern MONPRM volatile float32 ACCtl_tErrDrDVT2Duct;/* '<S287>/Switch1' */
extern MONPRM volatile float32 ACCtl_tErrPsDVT2Duct;/* '<S313>/Switch1' */
extern MONPRM volatile float32 ACCtl_tLeftDuct;/* '<S177>/Switch' */
extern MONPRM volatile float32 ACCtl_tPsDVT;/* '<S184>/Switch1' */
extern MONPRM volatile float32 ACCtl_tPsDVTCabinCor;/* '<S184>/cal_ACPsDVTSetCorByEnv_MAP' */
extern MONPRM volatile float32 ACCtl_tPsDVTSolarCor;/* '<S184>/cal_ACPsDVTSolarCor_MAP' */
extern MONPRM volatile float32 ACCtl_tPsEvapDes;/* '<S310>/Switch2' */
extern MONPRM volatile float32 ACCtl_tPsEvapDesPI;/* '<S314>/Merge' */
extern MONPRM volatile float32 ACCtl_tPsEvapICor;/* '<S317>/Merge1' */
extern MONPRM volatile float32 ACCtl_tPsEvapISum;/* '<S312>/Switch1' */
extern MONPRM volatile float32 ACCtl_tPsEvapPCor;/* '<S315>/Merge' */
extern MONPRM volatile float32 ACCtl_tPsPTCICor;/* '<S372>/Merge1' */
extern MONPRM volatile float32 ACCtl_tPsPTCISum;/* '<S368>/Switch1' */
extern MONPRM volatile float32 ACCtl_tPsPTCPCor;/* '<S371>/Merge' */
extern MONPRM volatile float32 ACCtl_tPsSetBasicEvap;/* '<S332>/Switch2' */
extern MONPRM volatile float32 ACCtl_tPsSetBasicPTC;/* '<S367>/Switch2' */
extern MONPRM volatile float32 ACCtl_tRightDuct;/* '<S177>/Switch1' */
extern MONPRM volatile float32 ACCtl_tRightSetPointModeCor;/* '<S187>/Sum3' */
extern MONPRM volatile float32 ACCtl_tSetPointEvap;/* '<S180>/Switch1' */
extern MONPRM volatile float32 ACCtl_tSetPointPTC;/* '<S340>/Switch2' */
extern MONPRM volatile float32 ACDVTPreSetSolarCor;
                                      /* '<S187>/cal_ACDVTPreSetSolarCor_MAP' */
extern MONPRM volatile float32 ACDVTPreSetSolarCorByVx;
                                  /* '<S187>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern MONPRM volatile float32 ACFanSpdSolarCor;/* '<S58>/cal_ACFanSpdSolarCor_MAP' */
extern MONPRM volatile float32 ACFanSpdSolarCorByEnv;
                                     /* '<S58>/cal_ACFanSpdSolarCorByEnv_MAP' */
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
extern MONPRM volatile float32 ACPTCDrDesCabinCor;/* '<S343>/cal_ACPTCDesCabinCor_CUR' */
extern MONPRM volatile float32 ACPTCDrDesEnvCor;/* '<S343>/cal_ACPTCDesEnvCor_MAP' */
extern MONPRM volatile float32 ACPTCDrDesFanCor;/* '<S343>/cal_ACPTCDesFanCor_CUR' */
extern MONPRM volatile float32 ACPTCPsDesCabinCor;/* '<S365>/cal_ACPTCPsDesCabinCor_CUR' */
extern MONPRM volatile float32 ACPTCPsDesEnvCor;/* '<S365>/cal_ACPTCPsDesEnvCor_MAP' */
extern MONPRM volatile float32 ACPTCPsDesFanCor;/* '<S365>/cal_ACPTCPsDesFanCor_CUR' */
extern MONPRM volatile float32 ACPTC_HeatedCond1;/* '<S181>/Add3' */
extern MONPRM volatile float32 ACPTC_HeatingCond1;/* '<S181>/Add' */
extern MONPRM volatile float32 ACPTC_HeatingCond2;/* '<S181>/Add1' */
extern MONPRM volatile float32 ACPtc_CloseCond1;/* '<S181>/Add2' */
extern MONPRM volatile float32 ACPwr_sPTCLmtPwrVal;/* '<S33>/Switch3' */
extern MONPRM volatile FaultStatus ACSen_eACCMHTSenSts;/* '<S1857>/Data Type Conversion' */
extern MONPRM volatile uint8 ACSen_eAirInletPer;/* '<S1233>/Switch' */
extern MONPRM volatile FaultStatus ACSen_eCabinSenSts;/* '<S1732>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eChillerTSenSts;/* '<S1786>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eEVAPSurfTSenSts;/* '<S1816>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eEVAPTSenSts;/* '<S1806>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eEnvSenSts;/* '<S1797>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eFaceDuctSenSts;/* '<S1755>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eFootDuctSenSts;/* '<S1765>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eLPSenSts;/* '<S1721>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eMOTORTSenSts;/* '<S1825>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eMixDoorSenSts;/* '<S1214>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eModeSenSts;/* '<S1215>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eOHXTSenSts;/* '<S1832>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eRecircSenSts;/* '<S1216>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eSOLARSenSts;/* '<S1722>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eWCCHPSenSts;/* '<S1730>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eWCCHTSenSts;/* '<S1841>/Data Type Conversion' */
extern MONPRM volatile float32 ACSen_sACCMHiTempFilter;/* '<S1858>/Switch' */
extern MONPRM volatile float32 ACSen_sCabinTempFilter;/* '<S1733>/Switch' */
extern MONPRM volatile float32 ACSen_sChiTempFilter;/* '<S1785>/Switch' */
extern MONPRM volatile float32 ACSen_sEnvTAme;/* '<S1718>/cal_EnvTAme_CUR' */
extern MONPRM volatile float32 ACSen_sEnvTempCor;/* '<S1751>/Switch' */
extern MONPRM volatile float32 ACSen_sEnvTempFilter;/* '<S1803>/Switch' */
extern MONPRM volatile float32 ACSen_sEvapSurTemp;/* '<S1817>/Switch' */
extern MONPRM volatile float32 ACSen_sEvapTempFilter;/* '<S1807>/Switch' */
extern MONPRM volatile float32 ACSen_sFaceDuctTempFilter;/* '<S1756>/Switch' */
extern MONPRM volatile float32 ACSen_sFootDuctTempFilter;/* '<S1766>/Switch' */
extern MONPRM volatile float32 ACSen_sHiPressFilter;/* '<S1851>/Switch' */
extern MONPRM volatile float32 ACSen_sLoPressFilter;/* '<S1775>/Switch' */
extern MONPRM volatile float32 ACSen_sMixDoorPerc;/* '<S1219>/Switch' */
extern MONPRM volatile float32 ACSen_sModeMotorVol;/* '<S1226>/Switch' */
extern MONPRM volatile float32 ACSen_sMotTempFilter;/* '<S1823>/Switch' */
extern MONPRM volatile float32 ACSen_sOHXTempFilter;/* '<S1833>/Switch' */
extern MONPRM volatile float32 ACSen_sPressRateVal;/* '<S506>/Switch' */
extern MONPRM volatile float32 ACSen_sWCCHiTempFilter;/* '<S1843>/Switch' */
extern MONPRM volatile boolean ACTCrl_bEnvCOMPLmt;/* '<S502>/Switch1' */
extern MONPRM volatile boolean ACTCtl_bACCMCtlEnb;/* '<S462>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAEXVDvtFlg;/* '<S691>/NOT' */
extern MONPRM volatile boolean ACTCtl_bAEXVEnb;/* '<S695>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAEXVFaultFlg;/* '<S687>/OR' */
extern MONPRM volatile boolean ACTCtl_bAEXVInitFinishFlg;/* '<S704>/Compare' */
extern MONPRM volatile uint8 ACTCtl_bAEXVInitReq;/* '<S705>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAEXVPIEnble;/* '<S682>/AND' */
extern MONPRM volatile boolean ACTCtl_bAcPMPFaultFlg;/* '<S1045>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAcPMPSpdFlt;/* '<S1031>/Switch1' */
extern MONPRM volatile boolean ACTCtl_bBCVlearnFlg;/* '<S673>/AND2' */
extern MONPRM volatile boolean ACTCtl_bBEXVDvtFlg;/* '<S762>/NOT' */
extern MONPRM volatile boolean ACTCtl_bBEXVEnb;/* '<S814>/Switch' */
extern MONPRM volatile boolean ACTCtl_bBEXVFaultFlg;/* '<S757>/OR' */
extern MONPRM volatile boolean ACTCtl_bBEXVInitFinishFlg;/* '<S772>/Compare' */
extern MONPRM volatile uint8 ACTCtl_bBEXVInitReq;/* '<S773>/Switch' */
extern MONPRM volatile boolean ACTCtl_bBEXVPIEnble;/* '<S683>/AND' */
extern MONPRM volatile boolean ACTCtl_bBatPMPFaultFlg;/* '<S1061>/Switch' */
extern MONPRM volatile boolean ACTCtl_bBatPMPSpdFlt;/* '<S1032>/Switch1' */
extern MONPRM volatile uint8 ACTCtl_bBatTempDiff;/* '<S653>/Switch' */
extern MONPRM volatile boolean ACTCtl_bCOMPDvtFlg;/* '<S455>/Relational Operator' */
extern MONPRM volatile boolean ACTCtl_bCOMPEnbDelay;/* '<S505>/Chart' */
extern MONPRM volatile boolean ACTCtl_bCOMPEnvpTPrtFlg;/* '<S459>/AND' */
extern MONPRM volatile boolean ACTCtl_bCOMPFaultClc;/* '<S499>/OR2' */
extern MONPRM volatile boolean ACTCtl_bCOMPForbidFlg;/* '<S451>/OR' */
extern MONPRM volatile boolean ACTCtl_bCOMPHPFrbFlg;/* '<S457>/Signal Copy3' */
extern MONPRM volatile boolean ACTCtl_bCOMPHPLmtFlg;/* '<S457>/Signal Copy2' */
extern MONPRM volatile uint8 ACTCtl_bCOMPIFreeFlag;/* '<S483>/Merge' */
extern MONPRM volatile boolean ACTCtl_bCOMPLPFrbFlg;/* '<S457>/Signal Copy1' */
extern MONPRM volatile boolean ACTCtl_bCOMPLPLmtFlg;/* '<S457>/Signal Copy' */
extern MONPRM volatile boolean ACTCtl_bCOMPPIEnble;/* '<S458>/FFCal' */
extern MONPRM volatile boolean ACTCtl_bCOMPRealFault;/* '<S499>/OR1' */
extern MONPRM volatile boolean ACTCtl_bCOMPSpdDiffFlt;/* '<S453>/Chart' */
extern MONPRM volatile boolean ACTCtl_bCOMPStopFlg;/* '<S453>/OR' */
extern MONPRM volatile boolean ACTCtl_bCabinFltFlg;/* '<S1715>/Signal Copy1' */
extern MONPRM volatile boolean ACTCtl_bCtrlFPTCOnOrOffPwrDiff;/* '<S611>/Switch' */
extern MONPRM volatile boolean ACTCtl_bHPEXVDvtFlg;/* '<S833>/NOT' */
extern MONPRM volatile boolean ACTCtl_bHPEXVEnb;/* '<S845>/Switch' */
extern MONPRM volatile boolean ACTCtl_bHPEXVFaultFlg;/* '<S829>/OR' */
extern MONPRM volatile boolean ACTCtl_bHPEXVInitFinishFlg;/* '<S901>/Compare' */
extern MONPRM volatile uint8 ACTCtl_bHPEXVInitReq;/* '<S902>/Switch' */
extern MONPRM volatile boolean ACTCtl_bHPEXVPIEnble;/* '<S684>/AND' */
extern MONPRM volatile boolean ACTCtl_bHiPressProFlg;/* '<S834>/Switch4' */
extern MONPRM volatile boolean ACTCtl_bLowPressProFlg;/* '<S834>/Switch5' */
extern MONPRM volatile boolean ACTCtl_bMCVlearnFlg;/* '<S644>/AND2' */
extern MONPRM volatile boolean ACTCtl_bMotPMPFaultFlg;/* '<S1075>/Switch' */
extern MONPRM volatile boolean ACTCtl_bMotPMPSpdFlt;/* '<S1033>/Chart' */
extern MONPRM volatile boolean ACTCtl_bOCOLmtFlg;/* '<S505>/AND1' */
extern MONPRM volatile boolean ACTCtl_bPTCOnOrOffPwrDiff;/* '<S594>/Switch' */
extern MONPRM volatile boolean ACTCtl_bPressProtectFlg;/* '<S506>/Multiport Switch' */
extern MONPRM volatile boolean ACTCtl_bPressRateFlg;/* '<S506>/Multiport Switch1' */
extern MONPRM volatile boolean ACTCtl_bSOVCmd;/* '<S448>/Multiport Switch' */
extern MONPRM volatile uint8 ACTCtl_eACPumpRefSpd;/* '<S1031>/Multiport Switch' */
extern MONPRM volatile uint8 ACTCtl_eAcPMPSpdPerc;/* '<S1044>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eAcPMPSpdSet;/* '<S1031>/Divide' */
extern MONPRM volatile uint8 ACTCtl_eBatPMPSpdSet;/* '<S1032>/Divide' */
extern MONPRM volatile uint8 ACTCtl_eC3WVSLSts;/* '<S669>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eC3WVValue;/* '<S641>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eC5WVSLSts;/* '<S679>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eC5WVValue;/* '<S642>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eCOMPExhTPrtSts;/* '<S459>/Chart' */
extern MONPRM volatile uint8 ACTCtl_eCOMPJudgeFlg;/* '<S464>/Add' */
extern MONPRM volatile uint8 ACTCtl_eCOMPPrsPrtSts;/* '<S457>/Add' */
extern MONPRM volatile uint8 ACTCtl_eCOMPSpdSecSts;/* '<S535>/SecCal' */
extern MONPRM volatile uint8 ACTCtl_eCoolFanCtrl;/* '<S924>/cal_CoolFanCtrl_MAP' */
extern MONPRM volatile uint8 ACTCtl_eEvapProSts;/* '<S692>/EvapTemperature' */
extern MONPRM volatile uint8 ACTCtl_eFanPerc;/* '<S930>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eHeatFanCtrl;/* '<S927>/cal_HeatFanCtrl_MAP' */
extern MONPRM volatile uint8 ACTCtl_eLessThanT1Sts;/* '<S658>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eMotPMPSpdSet;/* '<S1033>/Divide' */
extern MONPRM volatile float32 ACTCtl_sACCMCtlFF;/* '<S458>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sACCMCtlSpd;/* '<S453>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sACCMI_Cor;/* '<S485>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sACCMI_Sum;/* '<S482>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sACCMPIVal;/* '<S483>/Merge' */
extern MONPRM volatile float32 ACTCtl_sACCMP_Cor;/* '<S484>/Merge' */
extern MONPRM volatile float32 ACTCtl_sAEXVActure;/* '<S682>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlBFF;/* '<S724>/cal_AEXVCtrlBFF_CUR' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlFF;/* '<S686>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlKi;/* '<S682>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlKp;/* '<S682>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sAEXVDvt;/* '<S691>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sAEXVI_Cor;/* '<S709>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sAEXVI_Sum;/* '<S706>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sAEXVPI_Cor;/* '<S707>/Merge' */
extern MONPRM volatile float32 ACTCtl_sAEXVP_Cor;/* '<S708>/Merge' */
extern MONPRM volatile float32 ACTCtl_sAEXVPos;/* '<S750>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sAEXVSetPoint;/* '<S682>/Signal Copy' */
extern MONPRM volatile float32 ACTCtl_sBEXVActure;/* '<S683>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlBFF;/* '<S792>/cal_BEXVCtrlBFF_CUR' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlFF;/* '<S761>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlKi;/* '<S683>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlKp;/* '<S683>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sBEXVDvt;/* '<S762>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sBEXVI_Cor;/* '<S777>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sBEXVI_Sum;/* '<S774>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sBEXVPI_Cor;/* '<S775>/Merge' */
extern MONPRM volatile float32 ACTCtl_sBEXVP_Cor;/* '<S776>/Merge' */
extern MONPRM volatile float32 ACTCtl_sBEXVPos;/* '<S820>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sBEXVSetPoint;/* '<S683>/Signal Copy' */
extern MONPRM volatile float32 ACTCtl_sBatHeatInletTrgT;/* '<S650>/Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPATNoiseBlwAndAccmSpd;/* '<S547>/cal_COMPATNoiseSpdLmt_MAP' */
extern MONPRM volatile float32 ACTCtl_sCOMPATNoiseLmtHVSSpd;
                                     /* '<S547>/cal_COMPATNoiseSpdLmtHVS_CUR' */
extern MONPRM volatile float32 ACTCtl_sCOMPATNoiseLmtSpd;/* '<S547>/Min' */
extern MONPRM volatile float32 ACTCtl_sCOMPActure;/* '<S442>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sCOMPCoolLmtSpd;/* '<S547>/Switch4' */
extern MONPRM volatile float32 ACTCtl_sCOMPCtrlAClsFF;/* '<S584>/cal_ACCMCtrlA2FF_MAP ' */
extern MONPRM volatile float32 ACTCtl_sCOMPCtrlKi;/* '<S442>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sCOMPCtrlKp;/* '<S442>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sCOMPDownSpd;/* '<S572>/Max1' */
extern MONPRM volatile float32 ACTCtl_sCOMPEnvLmtSpd;/* '<S548>/Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPFanlevelLmtSpd;/* '<S548>/cal_COMPFanLevelLmt_CUR' */
extern MONPRM volatile float32 ACTCtl_sCOMPHPLmtSpd;/* '<S547>/Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPLPLmtSpd;/* '<S547>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sCOMPLmtMaxSpd;/* '<S452>/Min' */
extern MONPRM volatile float32 ACTCtl_sCOMPPCULimSpd;/* '<S547>/Multiport Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPSetPoint;/* '<S442>/Signal Copy' */
extern MONPRM volatile float32 ACTCtl_sChiSuperHeat;/* '<S685>/Add5' */
extern MONPRM volatile float32 ACTCtl_sChiSuperHeatAvg;/* '<S907>/Divide' */
extern MONPRM volatile float32 ACTCtl_sChiSuperHeatAvg1;/* '<S916>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sCondDep;/* '<S685>/Add' */
extern MONPRM volatile float32 ACTCtl_sCondDepAvg;/* '<S904>/Divide' */
extern MONPRM volatile float32 ACTCtl_sCondDepAvg1;/* '<S910>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sCondDepDiff;/* '<S724>/Add' */
extern MONPRM volatile float32 ACTCtl_sCoolCondDep;/* '<S685>/Add3' */
extern MONPRM volatile float32 ACTCtl_sCoolCondDepAvg;/* '<S905>/Divide' */
extern MONPRM volatile float32 ACTCtl_sCoolCondDepAvg1;/* '<S912>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sCtrlFPTCAuxHeatPwr;
                                    /* '<S589>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern MONPRM volatile float32 ACTCtl_sDCoolBatTempDiff;/* '<S591>/Add2' */
extern MONPRM volatile float32 ACTCtl_sDCoolCabinTempDiff;/* '<S591>/Add3' */
extern MONPRM volatile float32 ACTCtl_sDvtCOMPCtrl;/* '<S455>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sEvapSuperHeat;/* '<S685>/Add4' */
extern MONPRM volatile float32 ACTCtl_sEvapSuperHeatAvg;/* '<S906>/Divide' */
extern MONPRM volatile float32 ACTCtl_sEvapSuperHeatAvg1;/* '<S914>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sExhSuperHeat;/* '<S685>/Add2' */
extern MONPRM volatile float32 ACTCtl_sExhSuperHeatAvg;/* '<S908>/Divide' */
extern MONPRM volatile float32 ACTCtl_sExhSuperHeatAvg1;/* '<S918>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVActure;/* '<S684>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlADiff;/* '<S867>/Add' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlFF;/* '<S828>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlKi;/* '<S684>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlKp;/* '<S684>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sHPEXVDvt;/* '<S833>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVI_Cor;/* '<S853>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVI_Sum;/* '<S850>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVPI_Cor;/* '<S851>/Merge' */
extern MONPRM volatile float32 ACTCtl_sHPEXVP_Cor;/* '<S852>/Merge' */
extern MONPRM volatile float32 ACTCtl_sHPEXVPos;/* '<S836>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sHPEXVSetPoint;/* '<S831>/Switch' */
extern MONPRM volatile float32 ACTCtl_sHPEXVStepLmt;/* '<S837>/Switch' */
extern MONPRM volatile float32 ACTCtl_sPTCAuxHeatPwr;/* '<S584>/cal_PTCAuxHeatPwrLmt_MAP' */
extern MONPRM volatile float32 ACTCtl_sPTCBatHeatPwrLmt;/* '<S956>/cal_PTCBatHeatPwrLmt_CUR' */
extern MONPRM volatile uint8 ACTCtl_sPTCEnable;/* '<S1022>/Switch' */
extern MONPRM volatile float32 ACTCtl_sPTCReqPower;/* '<S1029>/Switch' */
extern MONPRM volatile float32 ACTCtl_sPTCRequestTemp;/* '<S953>/Switch' */
extern MONPRM volatile float32 ACTCtl_sSOCHighPTCPwrLmt;/* '<S956>/cal_SOCHighPTCPwrLmt_CUR' */
extern MONPRM volatile float32 ACTCtl_sSuperHeat;/* '<S685>/Add1' */
extern MONPRM volatile float32 ACTCtl_sSuperHeatAvg;/* '<S909>/Divide' */
extern MONPRM volatile float32 ACTCtl_sSuperHeatAvg1;/* '<S920>/Sum1' */
extern MONPRM volatile float32 ACTCtl_tCtrlADiff;/* '<S584>/Add1' */
extern MONPRM volatile float32 ACTCtl_tCtrlBDiff;/* '<S585>/Add' */
extern MONPRM volatile float32 ACTCtl_tCtrlCDiff;/* '<S586>/Add1' */
extern MONPRM volatile uint8 AC_BlowerFanSpeedMax;/* '<S52>/MinMax' */
extern MONPRM volatile uint8 AC_BlowerFanSpeedMin;/* '<S53>/Switch4' */
extern MONPRM volatile float32 AC_DVT2PTCErr;/* '<S52>/Add' */
extern MONPRM volatile float32 AC_DVTPreSetByEnv;/* '<S187>/cal_ACDVTPreSetByEnv_MAP' */
extern MONPRM volatile float32 AC_DrEvapDesFilter;
                                     /* '<S283>/cal_DrEvapDesFilterByDvt_CUR' */
extern MONPRM volatile uint8 AC_FanLeVel;/* '<S44>/Merge' */
extern MONPRM volatile uint8 AC_FanLevelAct;/* '<S44>/Merge' */
extern MONPRM volatile float32 AC_PidCabinT_UL;
                                    /* '<S189>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern MONPRM volatile float32 AC_Ps2DrSetTempDvt;/* '<S184>/Sum2' */
extern MONPRM volatile float32 AC_PsEvapDesFilter;
                                     /* '<S308>/cal_PsEvapDesFilterByDvt_CUR' */
extern MONPRM volatile uint8 AC_rRecircInc;/* '<S58>/Data Type Conversion' */
extern MONPRM volatile uint16 AC_rSolarRight;/* '<S1780>/Switch' */
extern MONPRM volatile uint16 AC_rSunloadFlt;/* '<S212>/Saturation' */
extern MONPRM volatile boolean AC_stExhaust;/* '<S4>/stExhaustFunCheck' */
extern MONPRM volatile boolean AC_stIGNON;/* '<S1280>/Switch1' */
extern MONPRM volatile float32 AC_tEnvInvent;/* '<S188>/TempRampBaseTimeAndStep' */
extern MONPRM volatile uint16 AC_tiAfterRun;/* '<S1296>/Switch' */
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
extern MONPRM volatile float32 AcPMP_RealRPM;/* '<S1270>/Gain' */
extern MONPRM volatile uint8 AcPMP_SWVersion_Main;/* '<S16>/Signal Copy115' */
extern MONPRM volatile uint8 AcPMP_SWVersion_Patch;/* '<S16>/Signal Copy117' */
extern MONPRM volatile uint8 AcPMP_SWVersion_Sub;/* '<S16>/Signal Copy116' */
extern MONPRM volatile uint8 AcPMP_SupplierNumber;/* '<S16>/Signal Copy112' */
extern MONPRM volatile uint8 BAT_EXV_CurrentInitState_B;/* '<S18>/Signal Copy35' */
extern MONPRM volatile float32 BAT_EXV_CurrentPosition_B;/* '<S1272>/Gain' */
extern MONPRM volatile uint8 BAT_EXV_FaultState_B;/* '<S18>/Signal Copy37' */
extern MONPRM volatile boolean BAT_EXV_ResponseError_B;/* '<S18>/Signal Copy34' */
extern MONPRM volatile boolean BAT_EXV_RunState_B;/* '<S18>/Signal Copy36' */
extern MONPRM volatile boolean BAT_EXV_SupplierLabel;/* '<S18>/Signal Copy40' */
extern MONPRM volatile uint8 BAT_EXV_TemperatureWarn_B;/* '<S1272>/Data Type Conversion' */
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
extern MONPRM volatile float32 BatPMP_RealRPM;/* '<S1273>/Gain' */
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
                                     /* '<S187>/cal_CabinDesTempSolarCor_MAP' */
extern MONPRM volatile float32 CabinDesTempSolarCorECO;
                                  /* '<S187>/cal_CabinDesTempSolarCorECO_MAP' */
extern MONPRM volatile boolean CoAC_stColdStart;/* '<S1281>/Switch3' */
extern MONPRM volatile uint8 CoAC_stwork;/* '<S32>/Switch1' */
extern MONPRM volatile float32 ColdPCUTempMinByEnv;
                                     /* '<S1717>/cal_ColdPCUTempMinByEnv_CUR' */
extern MONPRM volatile float32 ColdStartPCUTempMinByEnv;
                                /* '<S1292>/cal_ColdStartPCUTempMinByEnv_CUR' */
extern MONPRM volatile boolean ECUHighVoltInterlockSignal;/* '<S2>/Signal Copy137' */
extern MONPRM volatile float32 EE_PCUInletTemp;/* '<S1292>/Data Store Read1' */
extern MONPRM volatile uint8 EE_TimeDay;/* '<S1293>/Data Store Read3' */
extern MONPRM volatile uint8 EE_TimeHour;/* '<S1293>/Data Store Read' */
extern MONPRM volatile uint8 EE_TimeMin;/* '<S1293>/Data Store Read2' */
extern MONPRM volatile float32 EE_tEnv;/* '<S1292>/Data Store Read' */
extern MONPRM volatile uint8 EXV_CurrentInitState;/* '<S15>/Signal Copy97' */
extern MONPRM volatile float32 EXV_CurrentPosition;/* '<S1269>/Gain' */
extern MONPRM volatile uint8 EXV_FaultState;/* '<S15>/Signal Copy99' */
extern MONPRM volatile boolean EXV_ResponseError;/* '<S15>/Signal Copy96' */
extern MONPRM volatile boolean EXV_RunState;/* '<S15>/Signal Copy98' */
extern MONPRM volatile uint8 EXV_TemperatureWarn;/* '<S15>/Signal Copy101' */
extern MONPRM volatile uint8 EXV_VoltageState;/* '<S15>/Signal Copy100' */
extern MONPRM volatile float32 Eva_CloseCond1;/* '<S180>/Add2' */
extern MONPRM volatile float32 Eva_CooledCond1;/* '<S180>/Add3' */
extern MONPRM volatile float32 Eva_CoolingCond1;/* '<S180>/Add' */
extern MONPRM volatile float32 Eva_CoolingCond2;/* '<S180>/Add1' */
extern MONPRM volatile float32 EvapDesTempDrCabinCor;
                                      /* '<S284>/cal_EvapDesTempCabinCor_CUR' */
extern MONPRM volatile float32 EvapDesTempDrEnvCor;/* '<S284>/cal_EvapDesTempEnvCor_MAP' */
extern MONPRM volatile float32 EvapDesTempDrFanCor;/* '<S284>/cal_EvapDesTempFanCor_CUR' */
extern MONPRM volatile float32 EvapDesTempPsCabinCor;
                                    /* '<S309>/cal_EvapDesTempPsCabinCor_CUR' */
extern MONPRM volatile float32 EvapDesTempPsEnvCor;
                                      /* '<S309>/cal_EvapDesTempPsEnvCor_MAP' */
extern MONPRM volatile float32 EvapDesTempPsFanCor;
                                      /* '<S309>/cal_EvapDesTempPsFanCor_CUR' */
extern MONPRM volatile uint16 GlbDa_LeftSolar;/* '<S183>/Data Type Conversion1' */
extern MONPRM volatile uint16 GlbDa_LeftSolarAvr;/* '<S58>/Add1' */
extern MONPRM volatile uint16 GlbDa_RightSolar;/* '<S184>/Data Type Conversion' */
extern MONPRM volatile uint16 GlbDa_Solar;/* '<S281>/Max1' */
extern MONPRM volatile float32 GlbDa_tCabinInvent;/* '<S178>/Switch2' */
extern MONPRM volatile uint16 GlbDa_uBat;/* '<S2>/Constant2' */
extern MONPRM volatile boolean HMICtl_bACAuto;/* '<S1169>/Switch' */
extern MONPRM volatile boolean HMICtl_bACDefrost;/* '<S1183>/Switch' */
extern MONPRM volatile boolean HMICtl_bACOnOff;/* '<S1196>/Switch' */
extern MONPRM volatile boolean HMICtl_bLeftSetHigh;/* '<S1148>/Switch' */
extern MONPRM volatile boolean HMICtl_bLeftSetLow;/* '<S1149>/Switch' */
extern MONPRM volatile uint8 HMICtl_eACSts;/* '<S1208>/Switch' */
extern MONPRM volatile uint8 HMICtl_eBlwSts;/* '<S1107>/Switch' */
extern MONPRM volatile uint8 HMICtl_eInner;/* '<S1123>/Switch' */
extern MONPRM volatile uint8 HMICtl_eModeMotor;/* '<S1130>/Switch' */
extern MONPRM volatile uint8 HMICtl_eUnlckVentSts;/* '<S1213>/Switch' */
extern MONPRM volatile float32 HMICtl_sLeftSetPoint;/* '<S1150>/Switch' */
extern MONPRM volatile float32 HMICtl_sMixDoor;/* '<S1125>/Switch' */
extern MONPRM volatile float32 HP_EXV_CurrentPosition_B;/* '<S1274>/Gain' */
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
extern MONPRM volatile uint8 IOCtl_BloweFanSpeed;/* '<S1252>/Switch' */
extern MONPRM volatile boolean IOCtl_PwrNmReqFlg;/* '<S1241>/Relational Operator' */
extern MONPRM volatile uint8 IOCtl_RecircTrgPos;/* '<S1875>/Switch' */
extern MONPRM volatile boolean IOCtl_bModeMoveSts;/* '<S1868>/Signal Copy' */
extern MONPRM volatile float32 IOCtl_sMixDoorTrgPos;/* '<S1882>/Switch' */
extern MONPRM volatile float32 IOCtl_sModeMotorTrgPos;/* '<S1887>/Switch' */
extern MONPRM volatile boolean MCV_ErrResp;/* '<S25>/Signal Copy57' */
extern MONPRM volatile uint8 MCV_FltSts;/* '<S25>/Signal Copy50' */
extern MONPRM volatile uint8 MCV_Mode; /* '<S25>/Signal Copy51' */
extern MONPRM volatile uint16 MCV_PosRec;/* '<S25>/Signal Copy52' */
extern MONPRM volatile boolean MCV_RunSts;/* '<S25>/Signal Copy53' */
extern MONPRM volatile uint8 MCV_SpdLvl;/* '<S25>/Signal Copy54' */
extern MONPRM volatile uint8 MCV_TempSts;/* '<S25>/Signal Copy55' */
extern MONPRM volatile uint8 MCV_VoltSts;/* '<S25>/Signal Copy56' */
extern MONPRM volatile boolean MotPMP_PumpDryRunningSta;/* '<S26>/Signal Copy84' */
extern MONPRM volatile uint8 MotPMP_PumpInputVolt;/* '<S26>/Signal Copy87' */
extern MONPRM volatile uint8 MotPMP_PumpMotorSta;/* '<S26>/Signal Copy83' */
extern MONPRM volatile uint8 MotPMP_PumpPowerSta;/* '<S26>/Signal Copy85' */
extern MONPRM volatile uint8 MotPMP_PumpTempSta;/* '<S26>/Signal Copy86' */
extern MONPRM volatile boolean MotPMP_RESP_ERROR;/* '<S26>/Signal Copy82' */
extern MONPRM volatile float32 MotPMP_RealRPM;/* '<S1276>/Gain' */
extern MONPRM volatile float32 PCU_StartClntTemp;/* '<S1292>/Data Type Conversion' */
extern MONPRM volatile float32 PCUtempOffset2ShutByEnv;
                                 /* '<S1292>/cal_PCUtempOffset2ShutByEnv_CUR' */
extern MONPRM volatile boolean PWRCtl_bKL15swtSt;/* '<S2>/OR' */
extern MONPRM volatile boolean PWRCtl_bUnlockVentTimeFlg;/* '<S1290>/Switch' */
extern MONPRM volatile uint8 PWRCtl_eBatChargSts;/* '<S32>/CoBatCharg' */
extern MONPRM volatile PwrModes PWRCtl_eTMSStatus;/* '<S1285>/Switch' */
extern MONPRM volatile uint8 PWRCtl_eVCUPTSts;/* '<S2>/Signal Copy183' */
extern MONPRM volatile float32 PWRCtl_sCOMPActlPwr;/* '<S33>/Divide1' */
extern MONPRM volatile float32 PWRCtl_sLmtPwrCOMP;/* '<S33>/Min' */
extern MONPRM volatile uint32 PWRCtl_uTMSRunTimer;/* '<S32>/Cal_RunTime' */
extern MONPRM volatile uint32 PWRCtl_uTMSRunTimer20ms;/* '<S35>/Cal_RunTime_20ms' */
extern MONPRM volatile float32 PidCabinX_IsumMax;
                                   /* '<S189>/cal_PidCabinX_IsumMaxByDVT_CUR' */
extern MONPRM volatile float32 PidCabinX_IsumMin;
                                   /* '<S189>/cal_PidCabinX_IsumMinByDVT_CUR' */
extern MONPRM volatile boolean RMTCtl_bRemtACDefFlg;/* '<S1137>/Switch' */
extern MONPRM volatile boolean RMTCtl_bRemtACFlg;/* '<S1136>/Switch' */
extern MONPRM volatile uint16 SENCtl_uACCMHighTempVol;/* '<S1731>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uCabinVoltage;/* '<S1715>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uChillTempVol;/* '<S1723>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uEVAPSurfTempVol;/* '<S1726>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uEVAPXTempVol;/* '<S1725>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uEnvVoltage;/* '<S1724>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uFaceDuctVal;/* '<S1719>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uFootDuctVal;/* '<S1720>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uMixDoorVol;/* '<S1214>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uModeDoorVol;/* '<S1215>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uMotInletTempVol;/* '<S1727>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uOHXTempVol;/* '<S1728>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uRecircDoorVol;/* '<S1216>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uSolorVol;/* '<S1722>/C_Caller' */
extern MONPRM volatile uint16 SENCtl_uWCCHPVol;/* '<S1730>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uWCCHighTempVol;/* '<S1729>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uWCCLPVol;/* '<S1721>/C Caller' */
extern MONPRM volatile float32 SEN_ACCMTHiRaw;/* '<S1731>/cal_ACCMTHi_CUR' */
extern MONPRM volatile float32 SEN_ChiTRaw;/* '<S1723>/cal_TChillOutRaw_CUR' */
extern MONPRM volatile float32 SEN_EvapTRaw;/* '<S1725>/cal_TEvapOutRaw_CUR' */
extern MONPRM volatile float32 SEN_LoPressRaw;/* '<S1721>/cal_LoPress_CUR' */
extern MONPRM volatile float32 SEN_MixDoorRaw;/* '<S1214>/cal_MixDoorPerc_CUR' */
extern MONPRM volatile float32 SEN_OHXTRaw;/* '<S1728>/cal_OHXTRaw_CUR' */
extern MONPRM volatile uint16 SEN_SolarRaw;/* '<S1722>/cal_SolarValRaw_CUR' */
extern MONPRM volatile float32 SEN_TCabinRaw;/* '<S1715>/cal_TCabinRaw_CUR' */
extern MONPRM volatile float32 SEN_TDuctRaw;/* '<S1719>/cal_TDuctRaw_CUR' */
extern MONPRM volatile float32 SEN_TEnvRaw;/* '<S1724>/cal_TEnvRaw_CUR' */
extern MONPRM volatile float32 SEN_TEvapSurRaw;/* '<S1726>/cal_TEvapSur_CUR' */
extern MONPRM volatile float32 SEN_TFootDuctRaw;/* '<S1720>/cal_TDuctRaw_CUR' */
extern MONPRM volatile float32 SEN_TMotRaw;/* '<S1727>/cal_TMot_CUR' */
extern MONPRM volatile float32 SEN_WCCHiPressRaw;/* '<S1730>/cal_LCCOutHiPressRaw_CUR' */
extern MONPRM volatile float32 SEN_WCCTHiRaw;/* '<S1729>/cal_WCCTHiRaw_CUR' */
extern MONPRM volatile boolean SOMCtl_bB1toB31;/* '<S1318>/Switch1' */
extern MONPRM volatile boolean SOMCtl_bBatB1TB41Flg;/* '<S1467>/OR2' */
extern MONPRM volatile boolean SOMCtl_bBatB1TB42Flg;/* '<S1480>/OR2' */
extern MONPRM volatile boolean SOMCtl_bBatBalEntBFlg;/* '<S1615>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatBalFlg;/* '<S1311>/Judge' */
extern MONPRM volatile boolean SOMCtl_bBatCoolFlg;/* '<S1380>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatHStrFlg;/* '<S1556>/Chart' */
extern MONPRM volatile boolean SOMCtl_bBatHeatB31tB1Flg;/* '<S1559>/AND3' */
extern MONPRM volatile boolean SOMCtl_bBatHeatB3tB1Flg;/* '<S1318>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatHeatChrgFlgAB;/* '<S1463>/AND2' */
extern MONPRM volatile boolean SOMCtl_bBatHeatChrgFlgCD;/* '<S1464>/NOT' */
extern MONPRM volatile boolean SOMCtl_bBatHeatFlg;/* '<S1461>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatHeatOffFlg;/* '<S1491>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bBatHeatPwrLmtF;/* '<S1466>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bBatHeatTempDiffE;/* '<S1473>/Compare' */
extern MONPRM volatile boolean SOMCtl_bBatLTRFlg;/* '<S1313>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatLTROffFlg;/* '<S1421>/AND7' */
extern MONPRM volatile boolean SOMCtl_bBatTSEntAFlg;/* '<S1352>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatTSEntBFlg;/* '<S1353>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatTSExitFlg;/* '<S1332>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatTSFlg;/* '<S1311>/Switch' */
extern MONPRM volatile boolean SOMCtl_bCalTempBatHeatFlg;/* '<S1462>/Merge' */
extern MONPRM volatile boolean SOMCtl_bDBatLTROffFlg;/* '<S1523>/AND7' */
extern MONPRM volatile boolean SOMCtl_bDCBatLTROnFlg;/* '<S1420>/AND1' */
extern MONPRM volatile boolean SOMCtl_bEntExtDefFlg;/* '<S1704>/AND' */
extern MONPRM volatile boolean SOMCtl_bExitExtDefTempFlg;/* '<S1709>/Compare' */
extern MONPRM volatile boolean SOMCtl_bExtDefFlg;/* '<S1707>/Switch' */
extern MONPRM volatile boolean SOMCtl_bMD1CLMSts;/* '<S1653>/Chart' */
extern MONPRM volatile boolean SOMCtl_bMD1ToMD2Flg;/* '<S1652>/C' */
extern MONPRM volatile boolean SOMCtl_bMD2DHMD1Flg;/* '<S1654>/MD2_DHMD1' */
extern MONPRM volatile boolean SOMCtl_bMD2ToMD1Flg;/* '<S1652>/OR7' */
extern MONPRM volatile boolean SOMCtl_bMD2ToMD3Flg;/* '<S1655>/B' */
extern MONPRM volatile boolean SOMCtl_bMD3DHMD2Flg;/* '<S1656>/MD3_DHMD2' */
extern MONPRM volatile boolean SOMCtl_bMD3ToMD2Flg;/* '<S1655>/A' */
extern MONPRM volatile boolean SOMCtl_bMD3ToMD4Flg;/* '<S1657>/B' */
extern MONPRM volatile boolean SOMCtl_bMD4ToMD3Flg;/* '<S1657>/A' */
extern MONPRM volatile boolean SOMCtl_bMotAndBatLTRFlg;/* '<S1317>/Switch' */
extern MONPRM volatile boolean SOMCtl_bMotHeatBatFlg;/* '<S1319>/Switch' */
extern MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOffFlg;/* '<S1614>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOn1Flg;/* '<S1522>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOn2Flg;/* '<S1522>/Relational Operator1' */
extern MONPRM volatile boolean SOMCtl_bMotorHeatBatOffFlg;/* '<S1594>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bMotorHeatBatOnFlg;/* '<S1319>/Switch2' */
extern MONPRM volatile boolean SOMCtl_bMotorLTRAndBatBalFlg;/* '<S1320>/Switch' */
extern MONPRM volatile boolean SOMCtl_bNmlBatLTROnFlg;/* '<S1420>/Relational Operator' */
extern MONPRM volatile uint8 SOMCtl_eBatBalEntBFlg;/* '<S1615>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatCoolB1tB21;/* '<S1385>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatCoolB1tB22;/* '<S1396>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatCoolB2tB1;/* '<S1406>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatHeatOffVal;/* '<S1491>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatLTROnFlg;/* '<S1618>/Add' */
extern MONPRM volatile BatModes SOMCtl_eBatMode;/* '<S1456>/Switch' */
extern MONPRM volatile CabinMode SOMCtl_eCabinMode;/* '<S1702>/Switch' */
extern MONPRM volatile CabinMode SOMCtl_eCabinModePre;/* '<S1659>/Data Type Conversion2' */
extern MONPRM volatile uint8 SOMCtl_eHVPartMode;/* '<S1710>/Switch' */
extern MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOffFlg;/* '<S1614>/Add' */
extern MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOn1Flg;/* '<S1522>/Add' */
extern MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOn2Flg;/* '<S1522>/Add1' */
extern MONPRM volatile uint8 SOMCtl_eMotorHeatBat2Flg;/* '<S1592>/Add' */
extern MONPRM volatile uint8 SOMCtl_eMotorHeatBatFlg;/* '<S1593>/Add' */
extern MONPRM volatile uint16 SOMCtl_eMotorHeatBatOffFlg;/* '<S1594>/Add' */
extern MONPRM volatile uint8 SOMCtl_eNmlBatLTROnFlg;/* '<S1420>/Add' */
extern MONPRM volatile RefModes SOMCtl_eRefModes;/* '<S1711>/Switch' */
extern MONPRM volatile WaterModes SOMCtl_eWaterMode;/* '<S1703>/Switch' */
extern MONPRM volatile float32 SOMCtl_sBatHeatPTCTrgT;/* '<S1514>/Switch' */
extern MONPRM volatile float32 SOMCtl_sBatHeatT1;/* '<S1462>/Merge' */
extern MONPRM volatile float32 SOMCtl_sBatHeatT2;/* '<S1462>/Merge' */
extern MONPRM volatile float32 SOMCtl_sBatHeatTrgTempComp;
                                      /* '<S1514>/cal_BatHeatTrgTempComp_CUR' */
extern MONPRM volatile float32 SOMCtl_sBatTrgTemp;/* '<S1323>/Switch' */
extern MONPRM volatile float32 SOMCtl_sF1Value;/* '<S1651>/Add' */
extern MONPRM volatile float32 SOMCtl_sF2Value;/* '<S1651>/Add1' */
extern MONPRM volatile boolean SOMCtrl_bBatLTRDelayFlg;/* '<S1421>/Delay' */
extern MONPRM volatile uint8 TMS_VersionNumber;/* '<S8>/Constant1' */
extern MONPRM volatile float32 ThCo_rSetLeftMixDoor;/* '<S390>/Switch3' */
extern MONPRM volatile float32 ThCo_rSetRightMixDoor;/* '<S390>/Switch2' */
extern MONPRM volatile uint16 adc2_group0_0;/* '<S1714>/Signal Copy' */
extern MONPRM volatile uint16 adc2_group0_1;/* '<S1714>/Signal Copy1' */
extern MONPRM volatile uint16 adc2_group0_2;/* '<S1714>/Signal Copy2' */
extern MONPRM volatile uint16 adc2_group1_0;/* '<S1714>/Signal Copy3' */
extern MONPRM volatile uint16 adc2_group1_1;/* '<S1714>/Signal Copy4' */
extern MONPRM volatile uint16 adc2_group1_2;/* '<S1714>/Signal Copy5' */
extern MONPRM volatile uint16 adc2_group1_3;/* '<S1714>/Signal Copy6' */
extern MONPRM volatile uint16 adc2_group1_4;/* '<S1714>/Signal Copy7' */
extern MONPRM volatile uint16 adc2_group1_5;/* '<S1714>/Signal Copy8' */
extern MONPRM volatile uint16 adc2_group1_6;/* '<S1714>/Signal Copy9' */
extern MONPRM volatile uint16 adc2_group1_7;/* '<S1714>/Signal Copy10' */
extern MONPRM volatile uint16 adc2_group1_8;/* '<S1714>/Signal Copy11' */
extern MONPRM volatile uint16 adc2_group1_9;/* '<S1714>/Signal Copy12' */
extern MONPRM volatile uint16 adc2_group2_0;/* '<S1714>/Signal Copy17' */
extern MONPRM volatile uint16 adc2_group2_1;/* '<S1714>/Signal Copy18' */
extern MONPRM volatile uint16 adc2_group2_2;/* '<S1714>/Signal Copy19' */
extern MONPRM volatile uint16 adc2_group2_3;/* '<S1714>/Signal Copy13' */
extern MONPRM volatile uint16 adc2_group2_4;/* '<S1714>/Signal Copy14' */

#endif                                 /* RTW_HEADER_TMS_MonitorData_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
