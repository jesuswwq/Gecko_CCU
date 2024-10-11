/*
 * File: TMS_MonitorData.h
 *
 * Code generated for Simulink model 'ME11'.
 *
 * Model version                  : 1.2188
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Oct  8 16:29:54 2024
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
extern MONPRM volatile float32 ACCCtl_sACCabinPreSetByEnv;/* '<S185>/cal_ACCabinPreSetByEnv_MAP' */
extern MONPRM volatile float32 ACCCtl_sACCabinPreSetByEnvECO;
                                    /* '<S185>/cal_ACCabinPreSetByEnvECO_MAP' */
extern MONPRM volatile float32 ACCCtl_sBlowerFanSpd;/* '<S56>/MinMax' */
extern MONPRM volatile float32 ACCCtl_sSetPtcDesTempMax;/* '<S179>/cal_SetPtcDesTempMax_MAP' */
extern MONPRM volatile uint8 ACCtl_BloweFanSpeed;/* '<S42>/Merge' */
extern MONPRM volatile BlowerModes ACCtl_BlowerMode;/* '<S43>/Merge' */
extern MONPRM volatile float32 ACCtl_DVTIDeadBand;/* '<S187>/Constant7' */
extern MONPRM volatile float32 ACCtl_DrfacPtc2NominalTemp;/* '<S391>/Switch4' */
extern MONPRM volatile uint8 ACCtl_IntakeRatio;/* '<S47>/Merge' */
extern MONPRM volatile float32 ACCtl_PsfacPtc2NominalTemp;/* '<S417>/Switch4' */
extern MONPRM volatile float32 ACCtl_RFace2FaceFloor;
                                      /* '<S80>/cal_RFace2FaceFloorByEnv_CUR' */
extern MONPRM volatile float32 ACCtl_RFaceFloor2Face;
                                      /* '<S80>/cal_RFaceFloor2FaceByEnv_CUR' */
extern MONPRM volatile float32 ACCtl_RFaceFloor2Floor;
                                     /* '<S80>/cal_RFaceFloor2FloorByEnv_CUR' */
extern MONPRM volatile float32 ACCtl_RFloor2FaceFloor;
                                     /* '<S80>/cal_RFloor2FaceFloorByEnv_CUR' */
extern MONPRM volatile boolean ACCtl_bExhFlg;/* '<S1118>/Switch' */
extern MONPRM volatile boolean ACCtl_bExhaustFlg;/* '<S12>/AND2' */
extern MONPRM volatile uint16 ACCtl_pwrHeatingFeed;/* '<S94>/cal_ACPTCPwrPreSetByEnv_MAP' */
extern MONPRM volatile float32 ACCtl_pwrHeatingICor;/* '<S105>/Merge1' */
extern MONPRM volatile float32 ACCtl_pwrHeatingISum;/* '<S101>/Switch1' */
extern MONPRM volatile float32 ACCtl_pwrHeatingPCor;/* '<S104>/Merge' */
extern MONPRM volatile uint16 ACCtl_pwrHeatingReq;/* '<S38>/Signal Copy' */
extern MONPRM volatile uint8 ACCtl_rDrBasicMixDoor;/* '<S389>/Switch6' */
extern MONPRM volatile uint8 ACCtl_rDrMixDoorDes;/* '<S390>/Data Type Conversion' */
extern MONPRM volatile float32 ACCtl_rDrSetMixDoorICor;/* '<S400>/Merge1' */
extern MONPRM volatile float32 ACCtl_rDrSetMixDoorISum;/* '<S396>/Switch1' */
extern MONPRM volatile float32 ACCtl_rDrSetMixDoorPCor;/* '<S399>/Merge' */
extern MONPRM volatile uint8 ACCtl_rPsBasicMixDoor;/* '<S415>/Switch6' */
extern MONPRM volatile float32 ACCtl_rPsBlowerModeSet;/* '<S415>/Multiport Switch2' */
extern MONPRM volatile uint8 ACCtl_rPsMixDoorDes;/* '<S416>/Data Type Conversion' */
extern MONPRM volatile float32 ACCtl_rPsSetMixDoorICor;/* '<S424>/Merge1' */
extern MONPRM volatile float32 ACCtl_rPsSetMixDoorISum;/* '<S420>/Switch1' */
extern MONPRM volatile float32 ACCtl_rPsSetMixDoorPCor;/* '<S423>/Merge' */
extern MONPRM volatile float32 ACCtl_sECOEvaDesValLL;/* '<S178>/cal_ECOEvaDesValLL_MAP' */
extern MONPRM volatile float32 ACCtl_sMixDoorClsFF;/* '<S390>/Switch' */
extern MONPRM volatile boolean ACCtl_stACPTCHeated;/* '<S179>/PTCHeatedCheck' */
extern MONPRM volatile boolean ACCtl_stCabinCoolingEn;/* '<S44>/Merge' */
extern MONPRM volatile boolean ACCtl_stCabinHeatingEn;/* '<S93>/Logical Operator' */
extern MONPRM volatile uint8 ACCtl_stDvtPIDFreez;/* '<S190>/Merge' */
extern MONPRM volatile boolean ACCtl_stEvaCooledFlag;/* '<S178>/EvaCooledCheck' */
extern MONPRM volatile boolean ACCtl_stRecACHotStartEna;/* '<S126>/Relational Operator5' */
extern MONPRM volatile boolean ACCtl_stRecAQSEna;/* '<S127>/Recirc_AQS' */
extern MONPRM volatile boolean ACCtl_stRecForceChangeEna;/* '<S128>/Switch3' */
extern MONPRM volatile boolean ACCtl_stRecForceDefogEna;/* '<S129>/Relational Operator' */
extern MONPRM volatile uint8 ACCtl_stRecLevelFinal;/* '<S38>/Max' */
extern MONPRM volatile boolean ACCtl_stRecManualEna;/* '<S125>/Logical Operator' */
extern MONPRM volatile boolean ACCtl_stRecNormalDefogEna;/* '<S130>/Logical Operator' */
extern MONPRM volatile boolean ACCtl_stRecOut;/* '<S47>/Merge' */
extern MONPRM volatile boolean ACCtl_stRecPCUTempEna;/* '<S131>/Switch' */
extern MONPRM volatile boolean ACCtl_stRecPTCDvtEna;/* '<S132>/Switch1' */
extern MONPRM volatile boolean ACCtl_stRecQkChargeCoolingEna;/* '<S133>/Logical Operator' */
extern MONPRM volatile boolean ACCtl_stRecRemoteACEna;/* '<S134>/Relational Operator3' */
extern MONPRM volatile boolean ACCtl_stRecSummerCondEna;/* '<S135>/Relational Operator4' */
extern MONPRM volatile boolean ACCtl_stRecTargetOutTempEna;/* '<S136>/Switch1' */
extern MONPRM volatile boolean ACCtl_stRecTempLowEna;/* '<S35>/OR' */
extern MONPRM volatile boolean ACCtl_stRecVentEna;/* '<S138>/Logical Operator2' */
extern MONPRM volatile boolean ACCtl_stRecWinterCondEna;/* '<S139>/Relational Operator4' */
extern MONPRM volatile uint8 ACCtl_stStartState;/* '<S39>/AirConditionStartState' */
extern MONPRM volatile float32 ACCtl_tDVTFeedfoward;/* '<S208>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDVTFlt;/* '<S58>/Add' */
extern MONPRM volatile float32 ACCtl_tDVTPIBas;/* '<S190>/Merge' */
extern MONPRM volatile float32 ACCtl_tDesFrontCabin;/* '<S185>/Switch3' */
extern MONPRM volatile float32 ACCtl_tDrDVT;/* '<S181>/Switch3' */
extern MONPRM volatile float32 ACCtl_tDrDVTSolarCor;/* '<S181>/cal_ACDrDVTSolarCor_MAP' */
extern MONPRM volatile float32 ACCtl_tDrEvapDes;/* '<S283>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDrEvapDesPI;/* '<S286>/Merge' */
extern MONPRM volatile float32 ACCtl_tDrEvapICor;/* '<S289>/Merge1' */
extern MONPRM volatile float32 ACCtl_tDrEvapISum;/* '<S284>/Switch1' */
extern MONPRM volatile float32 ACCtl_tDrEvapPCor;/* '<S288>/Merge' */
extern MONPRM volatile float32 ACCtl_tDrPTCICor;/* '<S348>/Merge1' */
extern MONPRM volatile float32 ACCtl_tDrPTCISum;/* '<S344>/Switch1' */
extern MONPRM volatile float32 ACCtl_tDrPTCPCor;/* '<S347>/Merge' */
extern MONPRM volatile float32 ACCtl_tDrSetBasicEvap;/* '<S305>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDrSetBasicPTC;/* '<S343>/Switch2' */
extern MONPRM volatile float32 ACCtl_tDvtICor;/* '<S192>/Merge1' */
extern MONPRM volatile float32 ACCtl_tDvtISum;/* '<S188>/Switch1' */
extern MONPRM volatile float32 ACCtl_tDvtPCor;/* '<S191>/Merge' */
extern MONPRM volatile float32 ACCtl_tErrACPTC;/* '<S102>/Switch1' */
extern MONPRM volatile boolean ACCtl_tErrACPTCPosFlag;/* '<S102>/Relational Operator' */
extern MONPRM volatile float32 ACCtl_tErrDVT;/* '<S189>/Switch1' */
extern MONPRM volatile boolean ACCtl_tErrDVTFlag;/* '<S189>/Relational Operator' */
extern MONPRM volatile float32 ACCtl_tErrDrDVT2Duct;/* '<S285>/Switch1' */
extern MONPRM volatile float32 ACCtl_tErrPsDVT2Duct;/* '<S311>/Switch1' */
extern MONPRM volatile float32 ACCtl_tLeftDuct;/* '<S175>/Switch' */
extern MONPRM volatile float32 ACCtl_tPsDVT;/* '<S182>/Switch1' */
extern MONPRM volatile float32 ACCtl_tPsDVTCabinCor;/* '<S182>/cal_ACPsDVTSetCorByEnv_MAP' */
extern MONPRM volatile float32 ACCtl_tPsDVTSolarCor;/* '<S182>/cal_ACPsDVTSolarCor_MAP' */
extern MONPRM volatile float32 ACCtl_tPsEvapDes;/* '<S308>/Switch2' */
extern MONPRM volatile float32 ACCtl_tPsEvapDesPI;/* '<S312>/Merge' */
extern MONPRM volatile float32 ACCtl_tPsEvapICor;/* '<S315>/Merge1' */
extern MONPRM volatile float32 ACCtl_tPsEvapISum;/* '<S310>/Switch1' */
extern MONPRM volatile float32 ACCtl_tPsEvapPCor;/* '<S313>/Merge' */
extern MONPRM volatile float32 ACCtl_tPsPTCICor;/* '<S370>/Merge1' */
extern MONPRM volatile float32 ACCtl_tPsPTCISum;/* '<S366>/Switch1' */
extern MONPRM volatile float32 ACCtl_tPsPTCPCor;/* '<S369>/Merge' */
extern MONPRM volatile float32 ACCtl_tPsSetBasicEvap;/* '<S330>/Switch2' */
extern MONPRM volatile float32 ACCtl_tPsSetBasicPTC;/* '<S365>/Switch2' */
extern MONPRM volatile float32 ACCtl_tRightDuct;/* '<S175>/Switch1' */
extern MONPRM volatile float32 ACCtl_tRightSetPointModeCor;/* '<S185>/Sum3' */
extern MONPRM volatile float32 ACCtl_tSetPointEvap;/* '<S178>/Switch1' */
extern MONPRM volatile float32 ACCtl_tSetPointPTC;/* '<S338>/Switch2' */
extern MONPRM volatile float32 ACDVTPreSetSolarCor;
                                      /* '<S185>/cal_ACDVTPreSetSolarCor_MAP' */
extern MONPRM volatile float32 ACDVTPreSetSolarCorByVx;
                                  /* '<S185>/cal_ACDVTPreSetSolarCorByVx_MAP' */
extern MONPRM volatile float32 ACFanSpdSolarCor;/* '<S56>/cal_ACFanSpdSolarCor_MAP' */
extern MONPRM volatile float32 ACFanSpdSolarCorByEnv;
                                     /* '<S56>/cal_ACFanSpdSolarCorByEnv_MAP' */
extern MONPRM volatile boolean ACNvm_bACAutoSts;/* '<S3>/Data Type Conversion1' */
extern MONPRM volatile boolean ACNvm_bACOnOff;/* '<S3>/Data Type Conversion' */
extern MONPRM volatile uint8 ACNvm_eACCabinMode;/* '<S3>/Index Vector4' */
extern MONPRM volatile uint8 ACNvm_eCabinBlower;/* '<S3>/Index Vector5' */
extern MONPRM volatile uint8 ACNvm_eCabinSetTemp;/* '<S3>/Index Vector2' */
extern MONPRM volatile uint8 ACNvm_eCainModeDoor;/* '<S3>/Index Vector11' */
extern MONPRM volatile uint8 ACNvm_eCainRecDoor;/* '<S3>/Index Vector10' */
extern MONPRM volatile float32 ACNvm_sACEnvTemp;/* '<S3>/Add' */
extern MONPRM volatile float32 ACNvm_sPCUInletTemp;/* '<S3>/Add1' */
extern MONPRM volatile float32 ACPTCDrDesCabinCor;/* '<S341>/cal_ACPTCDesCabinCor_CUR' */
extern MONPRM volatile float32 ACPTCDrDesEnvCor;/* '<S341>/cal_ACPTCDesEnvCor_MAP' */
extern MONPRM volatile float32 ACPTCDrDesFanCor;/* '<S341>/cal_ACPTCDesFanCor_CUR' */
extern MONPRM volatile float32 ACPTCPsDesCabinCor;/* '<S363>/cal_ACPTCPsDesCabinCor_CUR' */
extern MONPRM volatile float32 ACPTCPsDesEnvCor;/* '<S363>/cal_ACPTCPsDesEnvCor_MAP' */
extern MONPRM volatile float32 ACPTCPsDesFanCor;/* '<S363>/cal_ACPTCPsDesFanCor_CUR' */
extern MONPRM volatile float32 ACPTC_HeatedCond1;/* '<S179>/Add3' */
extern MONPRM volatile float32 ACPTC_HeatingCond1;/* '<S179>/Add' */
extern MONPRM volatile float32 ACPTC_HeatingCond2;/* '<S179>/Add1' */
extern MONPRM volatile float32 ACPtc_CloseCond1;/* '<S179>/Add2' */
extern MONPRM volatile float32 ACPwr_sPTCLmtPwrVal;/* '<S31>/Switch3' */
extern MONPRM volatile FaultStatus ACSen_eACCMHTSenSts;/* '<S1870>/Data Type Conversion' */
extern MONPRM volatile uint8 ACSen_eAirInletPer;/* '<S1809>/Switch' */
extern MONPRM volatile FaultStatus ACSen_eCabinSenSts;/* '<S1755>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eChillerTSenSts;/* '<S1818>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eEVAPSurfTSenSts;/* '<S1836>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eEVAPTSenSts;/* '<S1826>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eEnvSenSts;/* '<S1089>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eFaceDuctSenSts;/* '<S1768>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eFootDuctSenSts;/* '<S1778>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eLPSenSts;/* '<S1743>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eMOTORTSenSts;/* '<S1100>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eMixDoorSenSts;/* '<S1744>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eModeSenSts;/* '<S1745>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eOHXTSenSts;/* '<S1845>/Data Type Conversion' */
extern MONPRM volatile FaultStatus ACSen_eRecircSenSts;/* '<S1746>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eSOLARSenSts;/* '<S1747>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eWCCHPSenSts;/* '<S1753>/Data Type Conversion3' */
extern MONPRM volatile FaultStatus ACSen_eWCCHTSenSts;/* '<S1854>/Data Type Conversion' */
extern MONPRM volatile float32 ACSen_sACCMHiTempFilter;/* '<S1871>/Switch' */
extern MONPRM volatile float32 ACSen_sCabinTempFilter;/* '<S1756>/Switch' */
extern MONPRM volatile float32 ACSen_sChiTempFilter;/* '<S1817>/Switch' */
extern MONPRM volatile float32 ACSen_sEnvTAme;/* '<S1073>/cal_EnvTAme_CUR' */
extern MONPRM volatile float32 ACSen_sEnvTempCor;/* '<S1085>/Switch' */
extern MONPRM volatile float32 ACSen_sEnvTempFilter;/* '<S1095>/Switch' */
extern MONPRM volatile float32 ACSen_sEvapSurTemp;/* '<S1837>/Switch' */
extern MONPRM volatile float32 ACSen_sEvapTempFilter;/* '<S1827>/Switch' */
extern MONPRM volatile float32 ACSen_sFaceDuctTempFilter;/* '<S1769>/Switch' */
extern MONPRM volatile float32 ACSen_sFootDuctTempFilter;/* '<S1779>/Switch' */
extern MONPRM volatile float32 ACSen_sHiPressFilter;/* '<S1864>/Switch' */
extern MONPRM volatile float32 ACSen_sLoPressFilter;/* '<S1788>/Switch' */
extern MONPRM volatile float32 ACSen_sMixDoorPerc;/* '<S1795>/Switch' */
extern MONPRM volatile float32 ACSen_sModeMotorVol;/* '<S1802>/Switch' */
extern MONPRM volatile float32 ACSen_sMotTempFilter;/* '<S1098>/Switch' */
extern MONPRM volatile float32 ACSen_sOHXTempFilter;/* '<S1846>/Switch' */
extern MONPRM volatile float32 ACSen_sPressRateVal;/* '<S504>/Switch' */
extern MONPRM volatile float32 ACSen_sWCCHiTempFilter;/* '<S1856>/Switch' */
extern MONPRM volatile boolean ACTCrl_bEnvCOMPLmt;/* '<S500>/Switch1' */
extern MONPRM volatile boolean ACTCtl_bACCMCtlEnb;/* '<S460>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAEXVDvtFlg;/* '<S682>/NOT' */
extern MONPRM volatile boolean ACTCtl_bAEXVEnb;/* '<S686>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAEXVFaultFlg;/* '<S678>/OR' */
extern MONPRM volatile boolean ACTCtl_bAEXVInitFinishFlg;/* '<S695>/Compare' */
extern MONPRM volatile uint8 ACTCtl_bAEXVInitReq;/* '<S696>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAEXVPIEnble;/* '<S673>/AND' */
extern MONPRM volatile boolean ACTCtl_bAcPMPFaultFlg;/* '<S1036>/Switch' */
extern MONPRM volatile boolean ACTCtl_bAcPMPSpdFlt;/* '<S1022>/Switch1' */
extern MONPRM volatile boolean ACTCtl_bBCVlearnFlg;/* '<S664>/AND2' */
extern MONPRM volatile boolean ACTCtl_bBEXVDvtFlg;/* '<S753>/NOT' */
extern MONPRM volatile boolean ACTCtl_bBEXVEnb;/* '<S805>/Switch' */
extern MONPRM volatile boolean ACTCtl_bBEXVFaultFlg;/* '<S748>/OR' */
extern MONPRM volatile boolean ACTCtl_bBEXVInitFinishFlg;/* '<S763>/Compare' */
extern MONPRM volatile uint8 ACTCtl_bBEXVInitReq;/* '<S764>/Switch' */
extern MONPRM volatile boolean ACTCtl_bBEXVPIEnble;/* '<S674>/AND' */
extern MONPRM volatile boolean ACTCtl_bBatPMPFaultFlg;/* '<S1052>/Switch' */
extern MONPRM volatile boolean ACTCtl_bBatPMPSpdFlt;/* '<S1023>/Switch1' */
extern MONPRM volatile uint8 ACTCtl_bBatTempDiff;/* '<S651>/Switch' */
extern MONPRM volatile boolean ACTCtl_bCOMPDvtFlg;/* '<S453>/Relational Operator' */
extern MONPRM volatile boolean ACTCtl_bCOMPEnbDelay;/* '<S503>/Chart' */
extern MONPRM volatile boolean ACTCtl_bCOMPEnvpTPrtFlg;/* '<S457>/AND' */
extern MONPRM volatile boolean ACTCtl_bCOMPFaultClc;/* '<S497>/OR2' */
extern MONPRM volatile boolean ACTCtl_bCOMPForbidFlg;/* '<S449>/OR' */
extern MONPRM volatile boolean ACTCtl_bCOMPHPFrbFlg;/* '<S455>/Signal Copy3' */
extern MONPRM volatile boolean ACTCtl_bCOMPHPLmtFlg;/* '<S455>/Signal Copy2' */
extern MONPRM volatile uint8 ACTCtl_bCOMPIFreeFlag;/* '<S481>/Merge' */
extern MONPRM volatile boolean ACTCtl_bCOMPLPFrbFlg;/* '<S455>/Signal Copy1' */
extern MONPRM volatile boolean ACTCtl_bCOMPLPLmtFlg;/* '<S455>/Signal Copy' */
extern MONPRM volatile boolean ACTCtl_bCOMPPIEnble;/* '<S456>/FFCal' */
extern MONPRM volatile boolean ACTCtl_bCOMPRealFault;/* '<S497>/OR1' */
extern MONPRM volatile boolean ACTCtl_bCOMPSpdDiffFlt;/* '<S451>/Chart' */
extern MONPRM volatile boolean ACTCtl_bCabinFltFlg;/* '<S1739>/Signal Copy1' */
extern MONPRM volatile boolean ACTCtl_bCtrlFPTCOnOrOffPwrDiff;/* '<S609>/Switch' */
extern MONPRM volatile boolean ACTCtl_bHPEXVDvtFlg;/* '<S824>/NOT' */
extern MONPRM volatile boolean ACTCtl_bHPEXVEnb;/* '<S836>/Switch' */
extern MONPRM volatile boolean ACTCtl_bHPEXVFaultFlg;/* '<S820>/OR' */
extern MONPRM volatile boolean ACTCtl_bHPEXVInitFinishFlg;/* '<S892>/Compare' */
extern MONPRM volatile uint8 ACTCtl_bHPEXVInitReq;/* '<S893>/Switch' */
extern MONPRM volatile boolean ACTCtl_bHPEXVPIEnble;/* '<S675>/AND' */
extern MONPRM volatile boolean ACTCtl_bHiPressProFlg;/* '<S825>/Switch4' */
extern MONPRM volatile boolean ACTCtl_bLowPressProFlg;/* '<S825>/Switch5' */
extern MONPRM volatile boolean ACTCtl_bMCVlearnFlg;/* '<S642>/AND2' */
extern MONPRM volatile boolean ACTCtl_bMotPMPFaultFlg;/* '<S1066>/Switch' */
extern MONPRM volatile boolean ACTCtl_bMotPMPSpdFlt;/* '<S1024>/Chart' */
extern MONPRM volatile boolean ACTCtl_bOCOLmtFlg;/* '<S503>/AND1' */
extern MONPRM volatile boolean ACTCtl_bPTCOnOrOffPwrDiff;/* '<S592>/Switch' */
extern MONPRM volatile boolean ACTCtl_bPressProtectFlg;/* '<S504>/Multiport Switch' */
extern MONPRM volatile boolean ACTCtl_bPressRateFlg;/* '<S504>/Multiport Switch1' */
extern MONPRM volatile boolean ACTCtl_bSOVCmd;/* '<S446>/Multiport Switch' */
extern MONPRM volatile uint8 ACTCtl_eACPumpRefSpd;/* '<S1022>/Multiport Switch' */
extern MONPRM volatile uint8 ACTCtl_eAcPMPSpdPerc;/* '<S1035>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eAcPMPSpdSet;/* '<S1022>/Divide' */
extern MONPRM volatile uint8 ACTCtl_eBatPMPSpdSet;/* '<S1023>/Divide' */
extern MONPRM volatile uint8 ACTCtl_eC3WVSLSts;/* '<S660>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eC3WVValue;/* '<S639>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eC5WVSLSts;/* '<S670>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eC5WVValue;/* '<S640>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eCOMPExhTPrtSts;/* '<S457>/Chart' */
extern MONPRM volatile uint8 ACTCtl_eCOMPJudgeFlg;/* '<S462>/Add' */
extern MONPRM volatile uint8 ACTCtl_eCOMPPrsPrtSts;/* '<S455>/Add' */
extern MONPRM volatile uint8 ACTCtl_eCOMPSpdSecSts;/* '<S533>/SecCal' */
extern MONPRM volatile uint8 ACTCtl_eCoolFanCtrl;/* '<S915>/cal_CoolFanCtrl_MAP' */
extern MONPRM volatile uint8 ACTCtl_eEvapProSts;/* '<S683>/EvapTemperature' */
extern MONPRM volatile uint8 ACTCtl_eFanPerc;/* '<S921>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eHeatFanCtrl;/* '<S918>/cal_HeatFanCtrl_MAP' */
extern MONPRM volatile uint8 ACTCtl_eLessThanT1Sts;/* '<S656>/Switch' */
extern MONPRM volatile uint8 ACTCtl_eMotPMPSpdSet;/* '<S1024>/Divide' */
extern MONPRM volatile float32 ACTCtl_sACCMCtlFF;/* '<S456>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sACCMCtlSpd;/* '<S451>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sACCMI_Cor;/* '<S483>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sACCMI_Sum;/* '<S480>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sACCMPIVal;/* '<S481>/Merge' */
extern MONPRM volatile float32 ACTCtl_sACCMP_Cor;/* '<S482>/Merge' */
extern MONPRM volatile float32 ACTCtl_sAEXVActure;/* '<S673>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlBFF;/* '<S715>/cal_AEXVCtrlBFF_CUR' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlFF;/* '<S677>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlKi;/* '<S673>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sAEXVCtrlKp;/* '<S673>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sAEXVDvt;/* '<S682>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sAEXVI_Cor;/* '<S700>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sAEXVI_Sum;/* '<S697>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sAEXVPI_Cor;/* '<S698>/Merge' */
extern MONPRM volatile float32 ACTCtl_sAEXVP_Cor;/* '<S699>/Merge' */
extern MONPRM volatile float32 ACTCtl_sAEXVPos;/* '<S741>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sAEXVSetPoint;/* '<S673>/Signal Copy' */
extern MONPRM volatile float32 ACTCtl_sBEXVActure;/* '<S674>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlBFF;/* '<S783>/cal_BEXVCtrlBFF_CUR' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlFF;/* '<S752>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlKi;/* '<S674>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sBEXVCtrlKp;/* '<S674>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sBEXVDvt;/* '<S753>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sBEXVI_Cor;/* '<S768>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sBEXVI_Sum;/* '<S765>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sBEXVPI_Cor;/* '<S766>/Merge' */
extern MONPRM volatile float32 ACTCtl_sBEXVP_Cor;/* '<S767>/Merge' */
extern MONPRM volatile float32 ACTCtl_sBEXVPos;/* '<S811>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sBEXVSetPoint;/* '<S674>/Signal Copy' */
extern MONPRM volatile float32 ACTCtl_sBatHeatInletTrgT;/* '<S648>/Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPATNoiseBlwAndAccmSpd;/* '<S545>/cal_COMPATNoiseSpdLmt_MAP' */
extern MONPRM volatile float32 ACTCtl_sCOMPATNoiseLmtHVSSpd;
                                     /* '<S545>/cal_COMPATNoiseSpdLmtHVS_CUR' */
extern MONPRM volatile float32 ACTCtl_sCOMPATNoiseLmtSpd;/* '<S545>/Min' */
extern MONPRM volatile float32 ACTCtl_sCOMPActure;/* '<S440>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sCOMPCoolLmtSpd;/* '<S545>/Switch4' */
extern MONPRM volatile float32 ACTCtl_sCOMPCtrlAClsFF;/* '<S582>/cal_ACCMCtrlA2FF_MAP ' */
extern MONPRM volatile float32 ACTCtl_sCOMPCtrlKi;/* '<S440>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sCOMPCtrlKp;/* '<S440>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sCOMPDownSpd;/* '<S570>/Max1' */
extern MONPRM volatile float32 ACTCtl_sCOMPEnvLmtSpd;/* '<S546>/Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPFanlevelLmtSpd;/* '<S546>/cal_COMPFanLevelLmt_CUR' */
extern MONPRM volatile float32 ACTCtl_sCOMPHPLmtSpd;/* '<S545>/Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPLPLmtSpd;/* '<S545>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sCOMPLmtMaxSpd;/* '<S450>/Min' */
extern MONPRM volatile float32 ACTCtl_sCOMPPCULimSpd;/* '<S545>/Multiport Switch' */
extern MONPRM volatile float32 ACTCtl_sCOMPSetPoint;/* '<S440>/Signal Copy' */
extern MONPRM volatile float32 ACTCtl_sChiSuperHeat;/* '<S676>/Add5' */
extern MONPRM volatile float32 ACTCtl_sChiSuperHeatAvg;/* '<S898>/Divide' */
extern MONPRM volatile float32 ACTCtl_sChiSuperHeatAvg1;/* '<S907>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sCondDep;/* '<S676>/Add' */
extern MONPRM volatile float32 ACTCtl_sCondDepAvg;/* '<S895>/Divide' */
extern MONPRM volatile float32 ACTCtl_sCondDepAvg1;/* '<S901>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sCondDepDiff;/* '<S715>/Add' */
extern MONPRM volatile float32 ACTCtl_sCoolCondDep;/* '<S676>/Add3' */
extern MONPRM volatile float32 ACTCtl_sCoolCondDepAvg;/* '<S896>/Divide' */
extern MONPRM volatile float32 ACTCtl_sCoolCondDepAvg1;/* '<S903>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sCtrlFPTCAuxHeatPwr;
                                    /* '<S587>/cal_CtrlFPTCAuxHeatPwrLmt_MAP' */
extern MONPRM volatile float32 ACTCtl_sDCoolBatTempDiff;/* '<S589>/Add2' */
extern MONPRM volatile float32 ACTCtl_sDCoolCabinTempDiff;/* '<S589>/Add3' */
extern MONPRM volatile float32 ACTCtl_sDvtCOMPCtrl;/* '<S453>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sEvapSuperHeat;/* '<S676>/Add4' */
extern MONPRM volatile float32 ACTCtl_sEvapSuperHeatAvg;/* '<S897>/Divide' */
extern MONPRM volatile float32 ACTCtl_sEvapSuperHeatAvg1;/* '<S905>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sExhSuperHeat;/* '<S676>/Add2' */
extern MONPRM volatile float32 ACTCtl_sExhSuperHeatAvg;/* '<S899>/Divide' */
extern MONPRM volatile float32 ACTCtl_sExhSuperHeatAvg1;/* '<S909>/Sum1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVActure;/* '<S675>/Signal Copy1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlADiff;/* '<S858>/Add' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlFF;/* '<S819>/FFCal' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlKi;/* '<S675>/Signal Copy3' */
extern MONPRM volatile float32 ACTCtl_sHPEXVCtrlKp;/* '<S675>/Signal Copy2' */
extern MONPRM volatile float32 ACTCtl_sHPEXVDvt;/* '<S824>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVI_Cor;/* '<S844>/Merge1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVI_Sum;/* '<S841>/Switch1' */
extern MONPRM volatile float32 ACTCtl_sHPEXVPI_Cor;/* '<S842>/Merge' */
extern MONPRM volatile float32 ACTCtl_sHPEXVP_Cor;/* '<S843>/Merge' */
extern MONPRM volatile float32 ACTCtl_sHPEXVPos;/* '<S827>/Switch2' */
extern MONPRM volatile float32 ACTCtl_sHPEXVSetPoint;/* '<S822>/Switch' */
extern MONPRM volatile float32 ACTCtl_sHPEXVStepLmt;/* '<S828>/Switch' */
extern MONPRM volatile float32 ACTCtl_sPTCAuxHeatPwr;/* '<S582>/cal_PTCAuxHeatPwrLmt_MAP' */
extern MONPRM volatile float32 ACTCtl_sPTCBatHeatPwrLmt;/* '<S947>/cal_PTCBatHeatPwrLmt_CUR' */
extern MONPRM volatile uint8 ACTCtl_sPTCEnable;/* '<S1013>/Switch' */
extern MONPRM volatile float32 ACTCtl_sPTCReqPower;/* '<S1020>/Switch' */
extern MONPRM volatile float32 ACTCtl_sPTCRequestTemp;/* '<S944>/Switch' */
extern MONPRM volatile float32 ACTCtl_sSOCHighPTCPwrLmt;/* '<S947>/cal_SOCHighPTCPwrLmt_CUR' */
extern MONPRM volatile float32 ACTCtl_sSuperHeat;/* '<S676>/Add1' */
extern MONPRM volatile float32 ACTCtl_sSuperHeatAvg;/* '<S900>/Divide' */
extern MONPRM volatile float32 ACTCtl_sSuperHeatAvg1;/* '<S911>/Sum1' */
extern MONPRM volatile float32 ACTCtl_tCtrlADiff;/* '<S582>/Add1' */
extern MONPRM volatile float32 ACTCtl_tCtrlBDiff;/* '<S583>/Add' */
extern MONPRM volatile float32 ACTCtl_tCtrlCDiff;/* '<S584>/Add1' */
extern MONPRM volatile uint8 AC_BlowerFanSpeedMax;/* '<S50>/MinMax' */
extern MONPRM volatile uint8 AC_BlowerFanSpeedMin;/* '<S51>/Switch4' */
extern MONPRM volatile float32 AC_DVT2PTCErr;/* '<S50>/Add' */
extern MONPRM volatile float32 AC_DVTPreSetByEnv;/* '<S185>/cal_ACDVTPreSetByEnv_MAP' */
extern MONPRM volatile float32 AC_DrEvapDesFilter;
                                     /* '<S281>/cal_DrEvapDesFilterByDvt_CUR' */
extern MONPRM volatile uint8 AC_FanLeVel;/* '<S42>/Merge' */
extern MONPRM volatile uint8 AC_FanLevelAct;/* '<S42>/Merge' */
extern MONPRM volatile float32 AC_PidCabinT_UL;
                                    /* '<S187>/cal_DvtDesLmtByCabinTDiff_MAP' */
extern MONPRM volatile float32 AC_Ps2DrSetTempDvt;/* '<S182>/Sum2' */
extern MONPRM volatile float32 AC_PsEvapDesFilter;
                                     /* '<S306>/cal_PsEvapDesFilterByDvt_CUR' */
extern MONPRM volatile uint8 AC_rRecircInc;/* '<S56>/Data Type Conversion' */
extern MONPRM volatile uint16 AC_rSolarRight;/* '<S1812>/Switch' */
extern MONPRM volatile uint16 AC_rSunloadFlt;/* '<S210>/Saturation' */
extern MONPRM volatile boolean AC_stExhaust;/* '<S4>/stExhaustFunCheck' */
extern MONPRM volatile boolean AC_stIGNON;/* '<S1291>/Switch1' */
extern MONPRM volatile float32 AC_tEnvInvent;/* '<S186>/TempRampBaseTimeAndStep' */
extern MONPRM volatile uint16 AC_tiAfterRun;/* '<S1303>/Switch' */
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
extern MONPRM volatile float32 AcPMP_RealRPM;/* '<S1281>/Gain' */
extern MONPRM volatile uint8 AcPMP_SWVersion_Main;/* '<S16>/Signal Copy115' */
extern MONPRM volatile uint8 AcPMP_SWVersion_Patch;/* '<S16>/Signal Copy117' */
extern MONPRM volatile uint8 AcPMP_SWVersion_Sub;/* '<S16>/Signal Copy116' */
extern MONPRM volatile uint8 AcPMP_SupplierNumber;/* '<S16>/Signal Copy112' */
extern MONPRM volatile uint8 BAT_EXV_CurrentInitState_B;/* '<S18>/Signal Copy35' */
extern MONPRM volatile float32 BAT_EXV_CurrentPosition_B;/* '<S1283>/Gain' */
extern MONPRM volatile uint8 BAT_EXV_FaultState_B;/* '<S18>/Signal Copy37' */
extern MONPRM volatile boolean BAT_EXV_ResponseError_B;/* '<S18>/Signal Copy34' */
extern MONPRM volatile boolean BAT_EXV_RunState_B;/* '<S18>/Signal Copy36' */
extern MONPRM volatile boolean BAT_EXV_SupplierLabel;/* '<S18>/Signal Copy40' */
extern MONPRM volatile uint8 BAT_EXV_TemperatureWarn_B;/* '<S1283>/Data Type Conversion' */
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
extern MONPRM volatile float32 BatPMP_RealRPM;/* '<S1284>/Gain' */
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
                                     /* '<S185>/cal_CabinDesTempSolarCor_MAP' */
extern MONPRM volatile float32 CabinDesTempSolarCorECO;
                                  /* '<S185>/cal_CabinDesTempSolarCorECO_MAP' */
extern MONPRM volatile boolean CoAC_stColdStart;/* '<S1292>/Switch3' */
extern MONPRM volatile uint8 CoAC_stwork;/* '<S30>/Switch1' */
extern MONPRM volatile float32 ColdPCUTempMinByEnv;
                                     /* '<S1072>/cal_ColdPCUTempMinByEnv_CUR' */
extern MONPRM volatile float32 ColdStartPCUTempMinByEnv;
                                /* '<S1299>/cal_ColdStartPCUTempMinByEnv_CUR' */
extern MONPRM volatile boolean ECUHighVoltInterlockSignal;/* '<S2>/Signal Copy137' */
extern MONPRM volatile float32 EE_PCUInletTemp;/* '<S1299>/Data Store Read1' */
extern MONPRM volatile uint8 EE_TimeDay;/* '<S1300>/Data Store Read3' */
extern MONPRM volatile uint8 EE_TimeHour;/* '<S1300>/Data Store Read' */
extern MONPRM volatile uint8 EE_TimeMin;/* '<S1300>/Data Store Read2' */
extern MONPRM volatile float32 EE_tEnv;/* '<S1299>/Data Store Read' */
extern MONPRM volatile uint8 EXV_CurrentInitState;/* '<S15>/Signal Copy97' */
extern MONPRM volatile float32 EXV_CurrentPosition;/* '<S1280>/Gain' */
extern MONPRM volatile uint8 EXV_FaultState;/* '<S15>/Signal Copy99' */
extern MONPRM volatile boolean EXV_ResponseError;/* '<S15>/Signal Copy96' */
extern MONPRM volatile boolean EXV_RunState;/* '<S15>/Signal Copy98' */
extern MONPRM volatile uint8 EXV_TemperatureWarn;/* '<S15>/Signal Copy101' */
extern MONPRM volatile uint8 EXV_VoltageState;/* '<S15>/Signal Copy100' */
extern MONPRM volatile float32 Eva_CloseCond1;/* '<S178>/Add2' */
extern MONPRM volatile float32 Eva_CooledCond1;/* '<S178>/Add3' */
extern MONPRM volatile float32 Eva_CoolingCond1;/* '<S178>/Add' */
extern MONPRM volatile float32 Eva_CoolingCond2;/* '<S178>/Add1' */
extern MONPRM volatile float32 EvapDesTempDrCabinCor;
                                      /* '<S282>/cal_EvapDesTempCabinCor_CUR' */
extern MONPRM volatile float32 EvapDesTempDrEnvCor;/* '<S282>/cal_EvapDesTempEnvCor_MAP' */
extern MONPRM volatile float32 EvapDesTempDrFanCor;/* '<S282>/cal_EvapDesTempFanCor_CUR' */
extern MONPRM volatile float32 EvapDesTempPsCabinCor;
                                    /* '<S307>/cal_EvapDesTempPsCabinCor_CUR' */
extern MONPRM volatile float32 EvapDesTempPsEnvCor;
                                      /* '<S307>/cal_EvapDesTempPsEnvCor_MAP' */
extern MONPRM volatile float32 EvapDesTempPsFanCor;
                                      /* '<S307>/cal_EvapDesTempPsFanCor_CUR' */
extern MONPRM volatile uint16 GlbDa_LeftSolar;/* '<S181>/Data Type Conversion1' */
extern MONPRM volatile uint16 GlbDa_LeftSolarAvr;/* '<S56>/Add1' */
extern MONPRM volatile uint16 GlbDa_RightSolar;/* '<S182>/Data Type Conversion' */
extern MONPRM volatile uint16 GlbDa_Solar;/* '<S279>/Max1' */
extern MONPRM volatile float32 GlbDa_tCabinInvent;/* '<S176>/Switch2' */
extern MONPRM volatile uint16 GlbDa_uBat;/* '<S2>/Constant2' */
extern MONPRM volatile boolean HMICtl_bACAuto;/* '<S1183>/Switch' */
extern MONPRM volatile boolean HMICtl_bACDefrost;/* '<S1197>/Switch' */
extern MONPRM volatile boolean HMICtl_bACOnOff;/* '<S1209>/Switch' */
extern MONPRM volatile boolean HMICtl_bLeftSetHigh;/* '<S1163>/Switch' */
extern MONPRM volatile boolean HMICtl_bLeftSetLow;/* '<S1164>/Switch' */
extern MONPRM volatile uint8 HMICtl_eACSts;/* '<S1221>/Switch' */
extern MONPRM volatile uint8 HMICtl_eBlwSts;/* '<S1129>/Switch' */
extern MONPRM volatile uint8 HMICtl_eInner;/* '<S1145>/Switch' */
extern MONPRM volatile uint8 HMICtl_eModeMotor;/* '<S1152>/Switch' */
extern MONPRM volatile float32 HMICtl_sLeftSetPoint;/* '<S1165>/Switch' */
extern MONPRM volatile float32 HMICtl_sMixDoor;/* '<S1147>/Switch' */
extern MONPRM volatile float32 HP_EXV_CurrentPosition_B;/* '<S1285>/Gain' */
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
extern MONPRM volatile uint8 IOCtl_BloweFanSpeed;/* '<S1242>/Switch' */
extern MONPRM volatile boolean IOCtl_PwrNmReqFlg;/* '<S1228>/Relational Operator' */
extern MONPRM volatile uint8 IOCtl_RecircTrgPos;/* '<S1261>/Switch' */
extern MONPRM volatile boolean IOCtl_bModeMoveSts;/* '<S1234>/Signal Copy' */
extern MONPRM volatile float32 IOCtl_sMixDoorTrgPos;/* '<S1268>/Switch' */
extern MONPRM volatile float32 IOCtl_sModeMotorTrgPos;/* '<S1273>/Switch' */
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
extern MONPRM volatile float32 MotPMP_RealRPM;/* '<S1287>/Gain' */
extern MONPRM volatile float32 PCU_StartClntTemp;/* '<S1299>/Data Type Conversion' */
extern MONPRM volatile float32 PCUtempOffset2ShutByEnv;
                                 /* '<S1299>/cal_PCUtempOffset2ShutByEnv_CUR' */
extern MONPRM volatile boolean PWRCtl_bKL15swtSt;/* '<S2>/OR' */
extern MONPRM volatile uint8 PWRCtl_eBatChargSts;/* '<S30>/CoBatCharg' */
extern MONPRM volatile PwrModes PWRCtl_eTMSStatus;/* '<S1296>/Switch' */
extern MONPRM volatile uint8 PWRCtl_eVCUPTSts;/* '<S2>/Signal Copy183' */
extern MONPRM volatile float32 PWRCtl_sCOMPActlPwr;/* '<S31>/Divide1' */
extern MONPRM volatile float32 PWRCtl_sLmtPwrCOMP;/* '<S31>/Min' */
extern MONPRM volatile uint32 PWRCtl_uTMSRunTimer;/* '<S30>/Cal_RunTime' */
extern MONPRM volatile uint32 PWRCtl_uTMSRunTimer20ms;/* '<S33>/Cal_RunTime_20ms' */
extern MONPRM volatile float32 PidCabinX_IsumMax;
                                   /* '<S187>/cal_PidCabinX_IsumMaxByDVT_CUR' */
extern MONPRM volatile float32 PidCabinX_IsumMin;
                                   /* '<S187>/cal_PidCabinX_IsumMinByDVT_CUR' */
extern MONPRM volatile uint16 SENCtl_uACCMHighTempVol;/* '<S1754>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uCabinVoltage;/* '<S1739>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uChillTempVol;/* '<S1748>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uEVAPSurfTempVol;/* '<S1750>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uEVAPXTempVol;/* '<S1749>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uEnvVoltage;/* '<S1074>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uFaceDuctVal;/* '<S1741>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uFootDuctVal;/* '<S1742>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uMixDoorVol;/* '<S1744>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uModeDoorVol;/* '<S1745>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uMotInletTempVol;/* '<S1075>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uOHXTempVol;/* '<S1751>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uRecircDoorVol;/* '<S1746>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uSolorVol;/* '<S1747>/C_Caller' */
extern MONPRM volatile uint16 SENCtl_uWCCHPVol;/* '<S1753>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uWCCHighTempVol;/* '<S1752>/C Caller' */
extern MONPRM volatile uint16 SENCtl_uWCCLPVol;/* '<S1743>/C Caller' */
extern MONPRM volatile float32 SEN_ACCMTHiRaw;/* '<S1754>/cal_ACCMTHi_CUR' */
extern MONPRM volatile float32 SEN_ChiTRaw;/* '<S1748>/cal_TChillOutRaw_CUR' */
extern MONPRM volatile float32 SEN_EvapTRaw;/* '<S1749>/cal_TEvapOutRaw_CUR' */
extern MONPRM volatile float32 SEN_LoPressRaw;/* '<S1743>/cal_LoPress_CUR' */
extern MONPRM volatile float32 SEN_MixDoorRaw;/* '<S1744>/cal_MixDoorPerc_CUR' */
extern MONPRM volatile float32 SEN_OHXTRaw;/* '<S1751>/cal_OHXTRaw_CUR' */
extern MONPRM volatile uint16 SEN_SolarRaw;/* '<S1747>/cal_SolarValRaw_CUR' */
extern MONPRM volatile float32 SEN_TCabinRaw;/* '<S1739>/cal_TCabinRaw_CUR' */
extern MONPRM volatile float32 SEN_TDuctRaw;/* '<S1741>/cal_TDuctRaw_CUR' */
extern MONPRM volatile float32 SEN_TEnvRaw;/* '<S1074>/cal_TEnvRaw_CUR' */
extern MONPRM volatile float32 SEN_TEvapSurRaw;/* '<S1750>/cal_TEvapSur_CUR' */
extern MONPRM volatile float32 SEN_TFootDuctRaw;/* '<S1742>/cal_TDuctRaw_CUR' */
extern MONPRM volatile float32 SEN_TMotRaw;/* '<S1075>/cal_TMot_CUR' */
extern MONPRM volatile float32 SEN_WCCHiPressRaw;/* '<S1753>/cal_LCCOutHiPressRaw_CUR' */
extern MONPRM volatile float32 SEN_WCCTHiRaw;/* '<S1752>/cal_WCCTHiRaw_CUR' */
extern MONPRM volatile boolean SOMCtl_bB1toB31;/* '<S1325>/Switch1' */
extern MONPRM volatile boolean SOMCtl_bBatB1TB41Flg;/* '<S1484>/OR2' */
extern MONPRM volatile boolean SOMCtl_bBatB1TB42Flg;/* '<S1497>/OR2' */
extern MONPRM volatile boolean SOMCtl_bBatBalEntBFlg;/* '<S1633>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatBalFlg;/* '<S1318>/Judge' */
extern MONPRM volatile boolean SOMCtl_bBatCoolFlg;/* '<S1395>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatHStrFlg;/* '<S1573>/Chart' */
extern MONPRM volatile boolean SOMCtl_bBatHeatB31tB1Flg;/* '<S1576>/AND3' */
extern MONPRM volatile boolean SOMCtl_bBatHeatB3tB1Flg;/* '<S1325>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatHeatChrgFlgAB;/* '<S1480>/AND2' */
extern MONPRM volatile boolean SOMCtl_bBatHeatChrgFlgCD;/* '<S1481>/NOT' */
extern MONPRM volatile boolean SOMCtl_bBatHeatFlg;/* '<S1478>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatHeatOffFlg;/* '<S1508>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bBatHeatPwrLmtF;/* '<S1483>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bBatHeatTempDiffE;/* '<S1490>/Compare' */
extern MONPRM volatile boolean SOMCtl_bBatLTRFlg;/* '<S1320>/Switch' */
extern MONPRM volatile boolean SOMCtl_bBatLTROffFlg;/* '<S1438>/AND7' */
extern MONPRM volatile boolean SOMCtl_bBatTSEntAFlg;/* '<S1358>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatTSEntBFlg;/* '<S1359>/AND1' */
extern MONPRM volatile boolean SOMCtl_bBatTSExitFlg;/* '<S1338>/AND1' */
extern MONPRM volatile boolean SOMCtl_bCalTempBatHeatFlg;/* '<S1479>/Merge' */
extern MONPRM volatile boolean SOMCtl_bDBatLTROffFlg;/* '<S1540>/AND7' */
extern MONPRM volatile boolean SOMCtl_bDCBatLTROnFlg;/* '<S1437>/AND1' */
extern MONPRM volatile boolean SOMCtl_bEntExtDefFlg;/* '<S1728>/AND' */
extern MONPRM volatile boolean SOMCtl_bExitExtDefTempFlg;/* '<S1733>/Compare' */
extern MONPRM volatile boolean SOMCtl_bExtDefFlg;/* '<S1731>/Switch' */
extern MONPRM volatile boolean SOMCtl_bMD1CLMSts;/* '<S1677>/Chart' */
extern MONPRM volatile boolean SOMCtl_bMD1ToMD2Flg;/* '<S1676>/C' */
extern MONPRM volatile boolean SOMCtl_bMD2DHMD1Flg;/* '<S1678>/MD2_DHMD1' */
extern MONPRM volatile boolean SOMCtl_bMD2ToMD1Flg;/* '<S1676>/OR7' */
extern MONPRM volatile boolean SOMCtl_bMD2ToMD3Flg;/* '<S1679>/B' */
extern MONPRM volatile boolean SOMCtl_bMD3DHMD2Flg;/* '<S1680>/MD3_DHMD2' */
extern MONPRM volatile boolean SOMCtl_bMD3ToMD2Flg;/* '<S1679>/A' */
extern MONPRM volatile boolean SOMCtl_bMD3ToMD4Flg;/* '<S1681>/B' */
extern MONPRM volatile boolean SOMCtl_bMD4ToMD3Flg;/* '<S1681>/A' */
extern MONPRM volatile boolean SOMCtl_bMotAndBatLTRFlg;/* '<S1324>/Switch' */
extern MONPRM volatile boolean SOMCtl_bMotHeatBatFlg;/* '<S1326>/Switch' */
extern MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOffFlg;/* '<S1632>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOn1Flg;/* '<S1539>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOn2Flg;/* '<S1539>/Relational Operator1' */
extern MONPRM volatile boolean SOMCtl_bMotorHeatBatOffFlg;/* '<S1612>/Relational Operator' */
extern MONPRM volatile boolean SOMCtl_bMotorHeatBatOnFlg;/* '<S1326>/Switch1' */
extern MONPRM volatile boolean SOMCtl_bMotorLTRAndBatBalFlg;/* '<S1327>/Switch' */
extern MONPRM volatile boolean SOMCtl_bNmlBatLTROnFlg;/* '<S1437>/Relational Operator' */
extern MONPRM volatile uint8 SOMCtl_eBatBalEntBFlg;/* '<S1633>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatCoolB1tB21;/* '<S1400>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatCoolB1tB22;/* '<S1411>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatCoolB2tB1;/* '<S1421>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatHeatOffVal;/* '<S1508>/Add' */
extern MONPRM volatile uint8 SOMCtl_eBatLTROnFlg;/* '<S1636>/Add' */
extern MONPRM volatile BatModes SOMCtl_eBatMode;/* '<S1473>/Switch' */
extern MONPRM volatile CabinMode SOMCtl_eCabinMode;/* '<S1726>/Switch' */
extern MONPRM volatile CabinMode SOMCtl_eCabinModePre;/* '<S1683>/Data Type Conversion2' */
extern MONPRM volatile uint8 SOMCtl_eHVPartMode;/* '<S1734>/Switch' */
extern MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOffFlg;/* '<S1632>/Add' */
extern MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOn1Flg;/* '<S1539>/Add' */
extern MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOn2Flg;/* '<S1539>/Add1' */
extern MONPRM volatile uint8 SOMCtl_eMotorHeatBat2Flg;/* '<S1610>/Add' */
extern MONPRM volatile uint8 SOMCtl_eMotorHeatBatFlg;/* '<S1611>/Add' */
extern MONPRM volatile uint16 SOMCtl_eMotorHeatBatOffFlg;/* '<S1612>/Add' */
extern MONPRM volatile uint8 SOMCtl_eNmlBatLTROnFlg;/* '<S1437>/Add' */
extern MONPRM volatile RefModes SOMCtl_eRefModes;/* '<S1735>/Switch' */
extern MONPRM volatile WaterModes SOMCtl_eWaterMode;/* '<S1727>/Switch' */
extern MONPRM volatile float32 SOMCtl_sBatHeatPTCTrgT;/* '<S1531>/Switch' */
extern MONPRM volatile float32 SOMCtl_sBatHeatT1;/* '<S1479>/Merge' */
extern MONPRM volatile float32 SOMCtl_sBatHeatT2;/* '<S1479>/Merge' */
extern MONPRM volatile float32 SOMCtl_sBatHeatTrgTempComp;
                                      /* '<S1531>/cal_BatHeatTrgTempComp_CUR' */
extern MONPRM volatile float32 SOMCtl_sBatTrgTemp;/* '<S1330>/Switch' */
extern MONPRM volatile float32 SOMCtl_sF1Value;/* '<S1675>/Add' */
extern MONPRM volatile float32 SOMCtl_sF2Value;/* '<S1675>/Add1' */
extern MONPRM volatile boolean SOMCtrl_bBatLTRDelayFlg;/* '<S1438>/Delay' */
extern MONPRM volatile uint8 TMS_VersionNumber;/* '<S8>/Constant1' */
extern MONPRM volatile float32 ThCo_rSetLeftMixDoor;/* '<S388>/Switch3' */
extern MONPRM volatile float32 ThCo_rSetRightMixDoor;/* '<S388>/Switch2' */
extern MONPRM volatile uint16 adc2_group0_0;/* '<S1738>/Signal Copy' */
extern MONPRM volatile uint16 adc2_group0_1;/* '<S1738>/Signal Copy1' */
extern MONPRM volatile uint16 adc2_group0_2;/* '<S1738>/Signal Copy2' */
extern MONPRM volatile uint16 adc2_group1_0;/* '<S1738>/Signal Copy3' */
extern MONPRM volatile uint16 adc2_group1_1;/* '<S1738>/Signal Copy4' */
extern MONPRM volatile uint16 adc2_group1_2;/* '<S1738>/Signal Copy5' */
extern MONPRM volatile uint16 adc2_group1_3;/* '<S1738>/Signal Copy6' */
extern MONPRM volatile uint16 adc2_group1_4;/* '<S1738>/Signal Copy7' */
extern MONPRM volatile uint16 adc2_group1_5;/* '<S1738>/Signal Copy8' */
extern MONPRM volatile uint16 adc2_group1_6;/* '<S1738>/Signal Copy9' */
extern MONPRM volatile uint16 adc2_group1_7;/* '<S1738>/Signal Copy10' */
extern MONPRM volatile uint16 adc2_group1_8;/* '<S1738>/Signal Copy11' */
extern MONPRM volatile uint16 adc2_group1_9;/* '<S1738>/Signal Copy12' */
extern MONPRM volatile uint16 adc2_group2_0;/* '<S1738>/Signal Copy17' */
extern MONPRM volatile uint16 adc2_group2_1;/* '<S1738>/Signal Copy18' */
extern MONPRM volatile uint16 adc2_group2_2;/* '<S1738>/Signal Copy19' */
extern MONPRM volatile uint16 adc2_group2_3;/* '<S1738>/Signal Copy13' */
extern MONPRM volatile uint16 adc2_group2_4;/* '<S1738>/Signal Copy14' */

#endif                                 /* RTW_HEADER_TMS_MonitorData_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
