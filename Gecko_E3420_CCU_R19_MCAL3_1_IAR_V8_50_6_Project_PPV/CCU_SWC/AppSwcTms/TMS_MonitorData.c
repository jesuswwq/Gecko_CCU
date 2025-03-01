#include "TMS_MonitorData.h"
#include "ME11.h"

#include "XcpTest_types.h"

MONPRM volatile uint8 ACCAN_TBOX_BJS_Time_Day = ((uint8)0U);
MONPRM volatile uint8 ACCAN_TBOX_BJS_Time_Hour = ((uint8)0U);
MONPRM volatile uint8 ACCAN_TBOX_BJS_Time_Min = ((uint8)0U);
MONPRM volatile float32 ACCCtl_sACCabinPreSetByEnv = 0.0F;
MONPRM volatile float32 ACCCtl_sACCabinPreSetByEnvECO = 0.0F;
MONPRM volatile float32 ACCCtl_sBlowerFanSpd = 0.0F;
MONPRM volatile float32 ACCCtl_sSetPtcDesTempMax = 0.0F;
MONPRM volatile uint8 ACCtl_BloweFanSpeed = ((uint8)0U);
MONPRM volatile BlowerModes ACCtl_BlowerMode = BlowerModes_FaceMode;
MONPRM volatile float32 ACCtl_DVTIDeadBand = 0.0F;
MONPRM volatile float32 ACCtl_DrfacPtc2NominalTemp = 0.0F;
MONPRM volatile uint8 ACCtl_IntakeRatio = ((uint8)0U);
MONPRM volatile float32 ACCtl_PsfacPtc2NominalTemp = 0.0F;
MONPRM volatile float32 ACCtl_RFace2FaceFloor = 0.0F;
MONPRM volatile float32 ACCtl_RFaceFloor2Face = 0.0F;
MONPRM volatile float32 ACCtl_RFaceFloor2Floor = 0.0F;
MONPRM volatile float32 ACCtl_RFloor2FaceFloor = 0.0F;
MONPRM volatile boolean ACCtl_bExhFlg = false;
MONPRM volatile boolean ACCtl_bExhaustFlg = false;
MONPRM volatile uint8 ACCtl_rDrBasicMixDoor = ((uint8)0U);
MONPRM volatile uint8 ACCtl_rDrMixDoorDes = ((uint8)0U);
MONPRM volatile float32 ACCtl_rDrSetMixDoorICor = 0.0F;
MONPRM volatile float32 ACCtl_rDrSetMixDoorISum = 0.0F;
MONPRM volatile float32 ACCtl_rDrSetMixDoorPCor = 0.0F;
MONPRM volatile uint8 ACCtl_rPsBasicMixDoor = ((uint8)0U);
MONPRM volatile float32 ACCtl_rPsBlowerModeSet = 0.0F;
MONPRM volatile uint8 ACCtl_rPsMixDoorDes = ((uint8)0U);
MONPRM volatile float32 ACCtl_rPsSetMixDoorICor = 0.0F;
MONPRM volatile float32 ACCtl_rPsSetMixDoorISum = 0.0F;
MONPRM volatile float32 ACCtl_rPsSetMixDoorPCor = 0.0F;
MONPRM volatile float32 ACCtl_sECOEvaDesValLL = 0.0F;
MONPRM volatile float32 ACCtl_sMixDoorClsFF = 0.0F;
MONPRM volatile boolean ACCtl_stACPTCHeated = false;
MONPRM volatile uint8 ACCtl_stDvtPIDFreez = ((uint8)0U);
MONPRM volatile boolean ACCtl_stEvaCooledFlag = false;
MONPRM volatile boolean ACCtl_stRecACHotStartEna = false;
MONPRM volatile boolean ACCtl_stRecAQSEna = false;
MONPRM volatile boolean ACCtl_stRecForceChangeEna = false;
MONPRM volatile boolean ACCtl_stRecForceDefogEna = false;
MONPRM volatile uint8 ACCtl_stRecLevelFinal = ((uint8)0U);
MONPRM volatile boolean ACCtl_stRecManualEna = false;
MONPRM volatile boolean ACCtl_stRecNormalDefogEna = false;
MONPRM volatile boolean ACCtl_stRecOut = false;
MONPRM volatile boolean ACCtl_stRecPCUTempEna = false;
MONPRM volatile boolean ACCtl_stRecPTCDvtEna = false;
MONPRM volatile boolean ACCtl_stRecQkChargeCoolingEna = false;
MONPRM volatile boolean ACCtl_stRecRemoteACEna = false;
MONPRM volatile boolean ACCtl_stRecSummerCondEna = false;
MONPRM volatile boolean ACCtl_stRecTargetOutTempEna = false;
MONPRM volatile boolean ACCtl_stRecTempLowEna = false;
MONPRM volatile boolean ACCtl_stRecVentEna = false;
MONPRM volatile boolean ACCtl_stRecWinterCondEna = false;
MONPRM volatile uint8 ACCtl_stStartState = ((uint8)0U);
MONPRM volatile float32 ACCtl_tDVTFeedfoward = 0.0F;
MONPRM volatile float32 ACCtl_tDVTFlt = 0.0F;
MONPRM volatile float32 ACCtl_tDVTPIBas = 0.0F;
MONPRM volatile float32 ACCtl_tDesFrontCabin = 0.0F;
MONPRM volatile float32 ACCtl_tDrDVT = 0.0F;
MONPRM volatile float32 ACCtl_tDrDVTSolarCor = 0.0F;
MONPRM volatile float32 ACCtl_tDrEvapDes = 0.0F;
MONPRM volatile float32 ACCtl_tDrEvapDesPI = 0.0F;
MONPRM volatile float32 ACCtl_tDrEvapICor = 0.0F;
MONPRM volatile float32 ACCtl_tDrEvapISum = 0.0F;
MONPRM volatile float32 ACCtl_tDrEvapPCor = 0.0F;
MONPRM volatile float32 ACCtl_tDrPTCICor = 0.0F;
MONPRM volatile float32 ACCtl_tDrPTCISum = 0.0F;
MONPRM volatile float32 ACCtl_tDrPTCPCor = 0.0F;
MONPRM volatile float32 ACCtl_tDrSetBasicEvap = 0.0F;
MONPRM volatile float32 ACCtl_tDrSetBasicPTC = 0.0F;
MONPRM volatile float32 ACCtl_tDvtICor = 0.0F;
MONPRM volatile float32 ACCtl_tDvtISum = 0.0F;
MONPRM volatile float32 ACCtl_tDvtPCor = 0.0F;
MONPRM volatile float32 ACCtl_tErrDVT = 0.0F;
MONPRM volatile boolean ACCtl_tErrDVTFlag = false;
MONPRM volatile float32 ACCtl_tErrDrDVT2Duct = 0.0F;
MONPRM volatile float32 ACCtl_tErrPsDVT2Duct = 0.0F;
MONPRM volatile float32 ACCtl_tLeftDuct = 0.0F;
MONPRM volatile float32 ACCtl_tPsDVT = 0.0F;
MONPRM volatile float32 ACCtl_tPsDVTCabinCor = 0.0F;
MONPRM volatile float32 ACCtl_tPsDVTSolarCor = 0.0F;
MONPRM volatile float32 ACCtl_tPsEvapDes = 0.0F;
MONPRM volatile float32 ACCtl_tPsEvapDesPI = 0.0F;
MONPRM volatile float32 ACCtl_tPsEvapICor = 0.0F;
MONPRM volatile float32 ACCtl_tPsEvapISum = 0.0F;
MONPRM volatile float32 ACCtl_tPsEvapPCor = 0.0F;
MONPRM volatile float32 ACCtl_tPsPTCICor = 0.0F;
MONPRM volatile float32 ACCtl_tPsPTCISum = 0.0F;
MONPRM volatile float32 ACCtl_tPsPTCPCor = 0.0F;
MONPRM volatile float32 ACCtl_tPsSetBasicEvap = 0.0F;
MONPRM volatile float32 ACCtl_tPsSetBasicPTC = 0.0F;
MONPRM volatile float32 ACCtl_tRightDuct = 0.0F;
MONPRM volatile float32 ACCtl_tRightSetPointModeCor = 0.0F;
MONPRM volatile float32 ACCtl_tSetPointEvap = 0.0F;
MONPRM volatile float32 ACCtl_tSetPointPTC = 0.0F;
MONPRM volatile boolean ACDIA_bFltVal = false;
MONPRM volatile uint8 ACDIA_eFltNum = ((uint8)0U);
MONPRM volatile uint8 ACDIA_eFltSortVal = ((uint8)0U);
MONPRM volatile float32 ACDVTPreSetSolarCor = 0.0F;
MONPRM volatile float32 ACDVTPreSetSolarCorByVx = 0.0F;
MONPRM volatile float32 ACFanSpdSolarCor = 0.0F;
MONPRM volatile float32 ACFanSpdSolarCorByEnv = 0.0F;
MONPRM volatile boolean ACNvm_bACAutoSts = false;
MONPRM volatile boolean ACNvm_bACOnOff = false;
MONPRM volatile uint8 ACNvm_eACCabinMode = ((uint8)0U);
MONPRM volatile uint8 ACNvm_eCabinBlower = ((uint8)0U);
MONPRM volatile uint8 ACNvm_eCabinSetTemp = ((uint8)0U);
MONPRM volatile uint8 ACNvm_eCainModeDoor = ((uint8)0U);
MONPRM volatile uint8 ACNvm_eCainRecDoor = ((uint8)0U);
MONPRM volatile uint8 ACNvm_eUnlockVentSts = ((uint8)0U);
MONPRM volatile float32 ACNvm_sACEnvTemp = -40.0F;
MONPRM volatile float32 ACNvm_sPCUInletTemp = -40.0F;
MONPRM volatile float32 ACPTCDrDesCabinCor = 0.0F;
MONPRM volatile float32 ACPTCDrDesEnvCor = 0.0F;
MONPRM volatile float32 ACPTCDrDesFanCor = 0.0F;
MONPRM volatile float32 ACPTCPsDesCabinCor = 0.0F;
MONPRM volatile float32 ACPTCPsDesEnvCor = 0.0F;
MONPRM volatile float32 ACPTCPsDesFanCor = 0.0F;
MONPRM volatile float32 ACPTC_HeatedCond1 = 0.0F;
MONPRM volatile float32 ACPTC_HeatingCond1 = 0.0F;
MONPRM volatile float32 ACPTC_HeatingCond2 = 0.0F;
MONPRM volatile float32 ACPtc_CloseCond1 = 0.0F;
MONPRM volatile float32 ACPwr_sPTCLmtPwrVal = 0.0F;
MONPRM volatile FaultStatus ACSen_eACCMHTSenSts = Normal;
MONPRM volatile uint8 ACSen_eAirInletPer = ((uint8)0U);
MONPRM volatile FaultStatus ACSen_eCabinSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eChillerTSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eEVAPSurfTSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eEVAPTSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eEnvSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eFaceDuctSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eFootDuctSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eLPSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eMOTORTSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eMixDoorSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eModeSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eOHXTSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eRecircSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eSOLARSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eWCCHPSenSts = Normal;
MONPRM volatile FaultStatus ACSen_eWCCHTSenSts = Normal;
MONPRM volatile float32 ACSen_sACCMHiTempFilter = 0.0F;
MONPRM volatile float32 ACSen_sCabinTempFilter = 0.0F;
MONPRM volatile float32 ACSen_sChiTempFilter = 0.0F;
MONPRM volatile float32 ACSen_sEnvTAme = 0.0F;
MONPRM volatile float32 ACSen_sEnvTempCor = 0.0F;
MONPRM volatile float32 ACSen_sEnvTempFilter = 0.0F;
MONPRM volatile float32 ACSen_sEvapSurTemp = 0.0F;
MONPRM volatile float32 ACSen_sEvapTempFilter = 0.0F;
MONPRM volatile float32 ACSen_sFaceDuctTempFilter = 0.0F;
MONPRM volatile float32 ACSen_sFootDuctTempFilter = 0.0F;
MONPRM volatile float32 ACSen_sHiPressFilter = 0.0F;
MONPRM volatile float32 ACSen_sLoPressFilter = 0.0F;
MONPRM volatile float32 ACSen_sMixDoorPerc = 0.0F;
MONPRM volatile float32 ACSen_sModeMotorVol = 0.0F;
MONPRM volatile float32 ACSen_sMotTempFilter = 0.0F;
MONPRM volatile float32 ACSen_sOHXTempFilter = 0.0F;
MONPRM volatile float32 ACSen_sPressRateVal = 0.0F;
MONPRM volatile float32 ACSen_sWCCHiTempFilter = 0.0F;
MONPRM volatile boolean ACTCrl_bEnvCOMPLmt = false;
MONPRM volatile boolean ACTCtl_bACCMCtlEnb = false;
MONPRM volatile boolean ACTCtl_bAEXVDvtFlg = false;
MONPRM volatile boolean ACTCtl_bAEXVEnb = false;
MONPRM volatile boolean ACTCtl_bAEXVFaultFlg = false;
MONPRM volatile boolean ACTCtl_bAEXVInitFinishFlg = false;
MONPRM volatile uint8 ACTCtl_bAEXVInitReq = ((uint8)0U);
MONPRM volatile boolean ACTCtl_bAEXVPIEnble = false;
MONPRM volatile boolean ACTCtl_bAcPMPFaultFlg = false;
MONPRM volatile boolean ACTCtl_bAcPMPSpdFlt = false;
MONPRM volatile boolean ACTCtl_bBCVlearnFlg = false;
MONPRM volatile boolean ACTCtl_bBEXVDvtFlg = false;
MONPRM volatile boolean ACTCtl_bBEXVEnb = false;
MONPRM volatile boolean ACTCtl_bBEXVFaultFlg = false;
MONPRM volatile boolean ACTCtl_bBEXVInitFinishFlg = false;
MONPRM volatile uint8 ACTCtl_bBEXVInitReq = ((uint8)0U);
MONPRM volatile boolean ACTCtl_bBEXVPIEnble = false;
MONPRM volatile boolean ACTCtl_bBatPMPFaultFlg = false;
MONPRM volatile boolean ACTCtl_bBatPMPSpdFlt = false;
MONPRM volatile uint8 ACTCtl_bBatTempDiff = ((uint8)0U);
MONPRM volatile boolean ACTCtl_bCOMPCoolEnvPrtFlg = false;
MONPRM volatile boolean ACTCtl_bCOMPDvtFlg = false;
MONPRM volatile boolean ACTCtl_bCOMPEnbDelay = false;
MONPRM volatile boolean ACTCtl_bCOMPEnvpTPrtFlg = false;
MONPRM volatile boolean ACTCtl_bCOMPFaultClc = false;
MONPRM volatile boolean ACTCtl_bCOMPForbidFlg = false;
MONPRM volatile boolean ACTCtl_bCOMPHPFrbFlg = false;
MONPRM volatile boolean ACTCtl_bCOMPHPLmtFlg = false;
MONPRM volatile uint8 ACTCtl_bCOMPIFreeFlag = ((uint8)0U);
MONPRM volatile boolean ACTCtl_bCOMPLPFrbFlg = false;
MONPRM volatile boolean ACTCtl_bCOMPLPLmtFlg = false;
MONPRM volatile boolean ACTCtl_bCOMPPIEnble = false;
MONPRM volatile boolean ACTCtl_bCOMPRealFault = false;
MONPRM volatile boolean ACTCtl_bCOMPSpdDiffFlt = false;
MONPRM volatile boolean ACTCtl_bCOMPStopFlg = false;
MONPRM volatile boolean ACTCtl_bCabinFltFlg = false;
MONPRM volatile boolean ACTCtl_bCtrlFPTCOnOrOffPwrDiff = false;
MONPRM volatile boolean ACTCtl_bHPEXVDvtFlg = false;
MONPRM volatile boolean ACTCtl_bHPEXVEnb = false;
MONPRM volatile boolean ACTCtl_bHPEXVFaultFlg = false;
MONPRM volatile boolean ACTCtl_bHPEXVInitFinishFlg = false;
MONPRM volatile uint8 ACTCtl_bHPEXVInitReq = ((uint8)0U);
MONPRM volatile boolean ACTCtl_bHPEXVPIEnble = false;
MONPRM volatile boolean ACTCtl_bHVCHFaultFlg = false;
MONPRM volatile boolean ACTCtl_bHiPressProFlg = false;
MONPRM volatile boolean ACTCtl_bLowPressProFlg = false;
MONPRM volatile boolean ACTCtl_bMCVlearnFlg = false;
MONPRM volatile boolean ACTCtl_bMotPMPFaultFlg = false;
MONPRM volatile boolean ACTCtl_bMotPMPSpdFlt = false;
MONPRM volatile boolean ACTCtl_bOCOLmtFlg = false;
MONPRM volatile boolean ACTCtl_bOilBackFlg = false;
MONPRM volatile boolean ACTCtl_bPTCOnOrOffPwrDiff = false;
MONPRM volatile boolean ACTCtl_bPressProtectFlg = false;
MONPRM volatile boolean ACTCtl_bPressRateFlg = false;
MONPRM volatile boolean ACTCtl_bSOVCmd = false;
MONPRM volatile uint8 ACTCtl_eACPumpRefSpd = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eAcPMPSpdPerc = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eAcPMPSpdSet = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eBatPMPSpdSet = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eC3WVSLSts = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eC3WVValue = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eC5WVSLSts = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eC5WVValue = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eCOMPExhTPrtSts = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eCOMPJudgeFlg = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eCOMPPrsPrtSts = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eCOMPSpdSecSts = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eCoolFanCtrl = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eEvapProSts = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eFanPerc = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eHeatFanCtrl = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eLessThanT1Sts = ((uint8)0U);
MONPRM volatile uint8 ACTCtl_eMotPMPSpdSet = ((uint8)0U);
MONPRM volatile float32 ACTCtl_sACCMCtlFF = 0.0F;
MONPRM volatile float32 ACTCtl_sACCMCtlSpd = 0.0F;
MONPRM volatile float32 ACTCtl_sACCMI_Cor = 0.0F;
MONPRM volatile float32 ACTCtl_sACCMI_Sum = 0.0F;
MONPRM volatile float32 ACTCtl_sACCMPIVal = 0.0F;
MONPRM volatile float32 ACTCtl_sACCMP_Cor = 0.0F;
MONPRM volatile float32 ACTCtl_sAEXVActure = 0.0F;
MONPRM volatile float32 ACTCtl_sAEXVCtrlBFF = 0.0F;
MONPRM volatile float32 ACTCtl_sAEXVCtrlFF = 0.0F;
MONPRM volatile float32 ACTCtl_sAEXVCtrlKi = 0.0F;
MONPRM volatile float32 ACTCtl_sAEXVCtrlKp = 0.0F;
MONPRM volatile float32 ACTCtl_sAEXVDvt = 0.0F;
MONPRM volatile float32 ACTCtl_sAEXVI_Cor = 0.0F;
MONPRM volatile float32 ACTCtl_sAEXVI_Sum = 0.0F;
MONPRM volatile float32 ACTCtl_sAEXVPI_Cor = 0.0F;
MONPRM volatile float32 ACTCtl_sAEXVP_Cor = 0.0F;
MONPRM volatile float32 ACTCtl_sAEXVPos = 0.0F;
MONPRM volatile float32 ACTCtl_sAEXVSetPoint = 0.0F;
MONPRM volatile float32 ACTCtl_sBEXVActure = 0.0F;
MONPRM volatile float32 ACTCtl_sBEXVCtrlBFF = 0.0F;
MONPRM volatile float32 ACTCtl_sBEXVCtrlFF = 0.0F;
MONPRM volatile float32 ACTCtl_sBEXVCtrlKi = 0.0F;
MONPRM volatile float32 ACTCtl_sBEXVCtrlKp = 0.0F;
MONPRM volatile float32 ACTCtl_sBEXVDvt = 0.0F;
MONPRM volatile float32 ACTCtl_sBEXVI_Cor = 0.0F;
MONPRM volatile float32 ACTCtl_sBEXVI_Sum = 0.0F;
MONPRM volatile float32 ACTCtl_sBEXVPI_Cor = 0.0F;
MONPRM volatile float32 ACTCtl_sBEXVP_Cor = 0.0F;
MONPRM volatile float32 ACTCtl_sBEXVPos = 0.0F;
MONPRM volatile float32 ACTCtl_sBEXVSetPoint = 0.0F;
MONPRM volatile float32 ACTCtl_sBatHeatInletTrgT = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPATNoiseBlwAndAccmSpd = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPATNoiseLmtHVSSpd = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPATNoiseLmtSpd = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPActure = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPCoolLmtSpd = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPCtrlAClsFF = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPCtrlKi = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPCtrlKp = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPDownSpd = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPEnvLmtSpd = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPFanlevelLmtSpd = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPHPLmtSpd = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPLPLmtSpd = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPLmtMaxSpd = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPPCULimSpd = 0.0F;
MONPRM volatile float32 ACTCtl_sCOMPSetPoint = 0.0F;
MONPRM volatile float32 ACTCtl_sChiSuperHeat = 0.0F;
MONPRM volatile float32 ACTCtl_sChiSuperHeatAvg = 0.0F;
MONPRM volatile float32 ACTCtl_sChiSuperHeatAvg1 = 0.0F;
MONPRM volatile float32 ACTCtl_sCondDep = 0.0F;
MONPRM volatile float32 ACTCtl_sCondDepAvg = 0.0F;
MONPRM volatile float32 ACTCtl_sCondDepAvg1 = 0.0F;
MONPRM volatile float32 ACTCtl_sCondDepDiff = 0.0F;
MONPRM volatile float32 ACTCtl_sCoolCondDep = 0.0F;
MONPRM volatile float32 ACTCtl_sCoolCondDepAvg = 0.0F;
MONPRM volatile float32 ACTCtl_sCoolCondDepAvg1 = 0.0F;
MONPRM volatile float32 ACTCtl_sCtrlFPTCAuxHeatPwr = 0.0F;
MONPRM volatile float32 ACTCtl_sDCoolBatTempDiff = 0.0F;
MONPRM volatile float32 ACTCtl_sDCoolCabinTempDiff = 0.0F;
MONPRM volatile float32 ACTCtl_sDvtCOMPCtrl = 0.0F;
MONPRM volatile float32 ACTCtl_sEvapSuperHeat = 0.0F;
MONPRM volatile float32 ACTCtl_sEvapSuperHeatAvg = 0.0F;
MONPRM volatile float32 ACTCtl_sEvapSuperHeatAvg1 = 0.0F;
MONPRM volatile float32 ACTCtl_sExhSuperHeat = 0.0F;
MONPRM volatile float32 ACTCtl_sExhSuperHeatAvg = 0.0F;
MONPRM volatile float32 ACTCtl_sExhSuperHeatAvg1 = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVActure = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVCtrlADiff = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVCtrlFF = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVCtrlKi = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVCtrlKp = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVDvt = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVI_Cor = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVI_Sum = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVPI_Cor = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVP_Cor = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVPos = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVSetPoint = 0.0F;
MONPRM volatile float32 ACTCtl_sHPEXVStepLmt = 0.0F;
MONPRM volatile float32 ACTCtl_sPTCAuxHeatPwr = 0.0F;
MONPRM volatile float32 ACTCtl_sPTCBatHeatPwrLmt = 0.0F;
MONPRM volatile uint8 ACTCtl_sPTCEnable = ((uint8)0U);
MONPRM volatile float32 ACTCtl_sPTCReqPower = 0.0F;
MONPRM volatile float32 ACTCtl_sPTCRequestTemp = 0.0F;
MONPRM volatile float32 ACTCtl_sSOCHighPTCPwrLmt = 0.0F;
MONPRM volatile float32 ACTCtl_sSuperHeat = 0.0F;
MONPRM volatile float32 ACTCtl_sSuperHeatAvg = 0.0F;
MONPRM volatile float32 ACTCtl_sSuperHeatAvg1 = 0.0F;
MONPRM volatile float32 ACTCtl_tCtrlADiff = 0.0F;
MONPRM volatile float32 ACTCtl_tCtrlBDiff = 0.0F;
MONPRM volatile float32 ACTCtl_tCtrlCDiff = 0.0F;
MONPRM volatile uint8 AC_BlowerFanSpeedMax = ((uint8)0U);
MONPRM volatile uint8 AC_BlowerFanSpeedMin = ((uint8)0U);
MONPRM volatile float32 AC_DVT2PTCErr = 0.0F;
MONPRM volatile float32 AC_DVTPreSetByEnv = 0.0F;
MONPRM volatile float32 AC_DrEvapDesFilter = 0.0F;
MONPRM volatile uint8 AC_FanLeVel = ((uint8)0U);
MONPRM volatile uint8 AC_FanLevelAct = ((uint8)0U);
MONPRM volatile float32 AC_PidCabinT_UL = 0.0F;
MONPRM volatile float32 AC_Ps2DrSetTempDvt = 0.0F;
MONPRM volatile float32 AC_PsEvapDesFilter = 0.0F;
MONPRM volatile uint8 AC_rRecircInc = ((uint8)0U);
MONPRM volatile uint16 AC_rSolarRight = ((uint16)0U);
MONPRM volatile uint16 AC_rSunloadFlt = ((uint16)0U);
MONPRM volatile boolean AC_stExhaust = false;
MONPRM volatile boolean AC_stIGNON = false;
MONPRM volatile float32 AC_tEnvInvent = 0.0F;
MONPRM volatile uint16 AC_tiAfterRun = ((uint16)0U);
MONPRM volatile uint8 AcPMP_HWVersion = ((uint8)0U);
MONPRM volatile uint8 AcPMP_PartNumber = ((uint8)0U);
MONPRM volatile uint8 AcPMP_ProjectCode1 = ((uint8)0U);
MONPRM volatile uint8 AcPMP_ProjectCode2 = ((uint8)0U);
MONPRM volatile boolean AcPMP_PumpDryRunningSta = false;
MONPRM volatile uint8 AcPMP_PumpInputVolt = ((uint8)0U);
MONPRM volatile uint8 AcPMP_PumpMotorSta = ((uint8)0U);
MONPRM volatile uint8 AcPMP_PumpPowerSta = ((uint8)0U);
MONPRM volatile uint8 AcPMP_PumpTempSta = ((uint8)0U);
MONPRM volatile boolean AcPMP_RESP_ERROR = false;
MONPRM volatile float32 AcPMP_RealRPM = 0.0F;
MONPRM volatile uint8 AcPMP_SWVersion_Main = ((uint8)0U);
MONPRM volatile uint8 AcPMP_SWVersion_Patch = ((uint8)0U);
MONPRM volatile uint8 AcPMP_SWVersion_Sub = ((uint8)0U);
MONPRM volatile uint8 AcPMP_SupplierNumber = ((uint8)0U);
MONPRM volatile uint8 BAT_EXV_CurrentInitState_B = ((uint8)0U);
MONPRM volatile float32 BAT_EXV_CurrentPosition_B = 0.0F;
MONPRM volatile uint8 BAT_EXV_FaultState_B = ((uint8)0U);
MONPRM volatile boolean BAT_EXV_ResponseError_B = false;
MONPRM volatile boolean BAT_EXV_RunState_B = false;
MONPRM volatile boolean BAT_EXV_SupplierLabel = false;
MONPRM volatile uint8 BAT_EXV_TemperatureWarn_B = ((uint8)0U);
MONPRM volatile uint8 BAT_EXV_VoltageState_B = ((uint8)0U);
MONPRM volatile boolean BCV_ErrResp = false;
MONPRM volatile uint8 BCV_FltSts = ((uint8)0U);
MONPRM volatile uint8 BCV_Mode = ((uint8)0U);
MONPRM volatile uint16 BCV_PosRec = ((uint16)0U);
MONPRM volatile boolean BCV_RunSts = false;
MONPRM volatile uint8 BCV_SpdLvl = ((uint8)0U);
MONPRM volatile uint8 BCV_TempSts = ((uint8)0U);
MONPRM volatile uint8 BCV_VoltSts = ((uint8)0U);
MONPRM volatile float32 BMS_BatSOCAct_pct = 0.0F;
MONPRM volatile float32 BMS_HVBatCellTempAve = 0.0F;
MONPRM volatile float32 BMS_HVBatCellTempMax = 0.0F;
MONPRM volatile float32 BMS_HVBatCellTempMin = 0.0F;
MONPRM volatile float32 BMS_InletCooltActlTemp = 0.0F;
MONPRM volatile boolean BatPMP_PumpDryRunningSta = false;
MONPRM volatile uint8 BatPMP_PumpInputVolt = ((uint8)0U);
MONPRM volatile uint8 BatPMP_PumpMotorSta = ((uint8)0U);
MONPRM volatile uint8 BatPMP_PumpPowerSta = ((uint8)0U);
MONPRM volatile uint8 BatPMP_PumpTempSta = ((uint8)0U);
MONPRM volatile boolean BatPMP_RESP_ERROR = false;
MONPRM volatile float32 BatPMP_RealRPM = 0.0F;
MONPRM volatile uint8 Bat_EXV_HWVersion = ((uint8)0U);
MONPRM volatile uint8 Bat_EXV_PartNumber = ((uint8)0U);
MONPRM volatile uint8 Bat_EXV_ProjectCode1 = ((uint8)0U);
MONPRM volatile uint8 Bat_EXV_ProjectCode2 = ((uint8)0U);
MONPRM volatile uint8 Bat_EXV_SWVersion_Main = ((uint8)0U);
MONPRM volatile uint8 Bat_EXV_SWVersion_Patch = ((uint8)0U);
MONPRM volatile uint8 Bat_EXV_SWVersion_Sub = ((uint8)0U);
MONPRM volatile uint8 Bat_EXV_SupplierNumber = ((uint8)0U);
MONPRM volatile boolean COMP_CANBusOff = false;
MONPRM volatile boolean COMP_Commu_Error = false;
MONPRM volatile boolean COMP_CurrentOffset = false;
MONPRM volatile float32 COMP_EcompActSpd = 0.0F;
MONPRM volatile uint8 COMP_EcompST = ((uint8)0U);
MONPRM volatile float32 COMP_High_Voltage = 0.0F;
MONPRM volatile uint8 COMP_HvError = ((uint8)0U);
MONPRM volatile boolean COMP_IPM_Error = false;
MONPRM volatile float32 COMP_InputCurrent = 0.0F;
MONPRM volatile boolean COMP_LoseStep = false;
MONPRM volatile uint8 COMP_LvError = ((uint8)0U);
MONPRM volatile uint8 COMP_OverCurrent = ((uint8)0U);
MONPRM volatile boolean COMP_OverDuty = false;
MONPRM volatile boolean COMP_PI_Saturation = false;
MONPRM volatile uint8 COMP_SelfCheckError = ((uint8)0U);
MONPRM volatile boolean COMP_TempError = false;
MONPRM volatile float32 COMP_Temperature = 0.0F;
MONPRM volatile float32 CabinDesTempSolarCor = 0.0F;
MONPRM volatile float32 CabinDesTempSolarCorECO = 0.0F;
MONPRM volatile boolean CoAC_stColdStart = false;
MONPRM volatile uint8 CoAC_stwork = ((uint8)0U);
MONPRM volatile float32 ColdPCUTempMinByEnv = 0.0F;
MONPRM volatile float32 ColdStartPCUTempMinByEnv = 0.0F;
MONPRM volatile boolean ECUHighVoltInterlockSignal = false;
MONPRM volatile float32 EE_PCUInletTemp = 0.0F;
MONPRM volatile uint8 EE_TimeDay = ((uint8)0U);
MONPRM volatile uint8 EE_TimeHour = ((uint8)0U);
MONPRM volatile uint8 EE_TimeMin = ((uint8)0U);
MONPRM volatile float32 EE_tEnv = 0.0F;
MONPRM volatile uint8 EXV_CurrentInitState = ((uint8)0U);
MONPRM volatile float32 EXV_CurrentPosition = 0.0F;
MONPRM volatile uint8 EXV_FaultState = ((uint8)0U);
MONPRM volatile boolean EXV_ResponseError = false;
MONPRM volatile boolean EXV_RunState = false;
MONPRM volatile uint8 EXV_TemperatureWarn = ((uint8)0U);
MONPRM volatile uint8 EXV_VoltageState = ((uint8)0U);
MONPRM volatile float32 Eva_CloseCond1 = 0.0F;
MONPRM volatile float32 Eva_CooledCond1 = 0.0F;
MONPRM volatile float32 Eva_CoolingCond1 = 0.0F;
MONPRM volatile float32 Eva_CoolingCond2 = 0.0F;
MONPRM volatile float32 EvapDesTempDrCabinCor = 0.0F;
MONPRM volatile float32 EvapDesTempDrEnvCor = 0.0F;
MONPRM volatile float32 EvapDesTempDrFanCor = 0.0F;
MONPRM volatile float32 EvapDesTempPsCabinCor = 0.0F;
MONPRM volatile float32 EvapDesTempPsEnvCor = 0.0F;
MONPRM volatile float32 EvapDesTempPsFanCor = 0.0F;
MONPRM volatile uint16 GlbDa_LeftSolar = ((uint16)0U);
MONPRM volatile uint16 GlbDa_LeftSolarAvr = ((uint16)0U);
MONPRM volatile uint16 GlbDa_RightSolar = ((uint16)0U);
MONPRM volatile uint16 GlbDa_Solar = ((uint16)0U);
MONPRM volatile float32 GlbDa_tCabinInvent = 0.0F;
MONPRM volatile uint16 GlbDa_uBat = ((uint16)1200U);
MONPRM volatile boolean HMICtl_bACAuto = false;
MONPRM volatile boolean HMICtl_bACDefrost = false;
MONPRM volatile boolean HMICtl_bACOnOff = false;
MONPRM volatile boolean HMICtl_bLeftSetHigh = false;
MONPRM volatile boolean HMICtl_bLeftSetLow = false;
MONPRM volatile uint8 HMICtl_eACSts = ((uint8)0U);
MONPRM volatile uint8 HMICtl_eBlwSts = ((uint8)0U);
MONPRM volatile uint8 HMICtl_eInner = ((uint8)0U);
MONPRM volatile uint8 HMICtl_eModeMotor = ((uint8)0U);
MONPRM volatile uint8 HMICtl_eUnlckVentSts = ((uint8)0U);
MONPRM volatile float32 HMICtl_sLeftSetPoint = 0.0F;
MONPRM volatile float32 HMICtl_sMixDoor = 0.0F;
MONPRM volatile float32 HP_EXV_CurrentPosition_B = 0.0F;
MONPRM volatile uint8 HP_EXV_FaultState_B = ((uint8)0U);
MONPRM volatile uint8 HP_EXV_HWVersion = ((uint8)0U);
MONPRM volatile uint8 HP_EXV_PartNumber = ((uint8)0U);
MONPRM volatile uint8 HP_EXV_ProjectCode1 = ((uint8)0U);
MONPRM volatile uint8 HP_EXV_ProjectCode2 = ((uint8)0U);
MONPRM volatile boolean HP_EXV_ResponseError_B = false;
MONPRM volatile boolean HP_EXV_RunState_B = false;
MONPRM volatile uint8 HP_EXV_SWVersion_Main = ((uint8)0U);
MONPRM volatile uint8 HP_EXV_SWVersion_Patch = ((uint8)0U);
MONPRM volatile uint8 HP_EXV_SWVersion_Sub = ((uint8)0U);
MONPRM volatile boolean HP_EXV_SupplierLabel = false;
MONPRM volatile uint8 HP_EXV_SupplierNumber = ((uint8)0U);
MONPRM volatile uint8 HP_EXV_VoltageState_B = ((uint8)0U);
MONPRM volatile boolean HP_EXV_Warning_OverTemp = false;
MONPRM volatile uint8 HP_EXV_initialize_status = ((uint8)0U);
MONPRM volatile uint8 HU_LeftTempSet = ((uint8)0U);
MONPRM volatile uint8 IOCtl_BloweFanSpeed = ((uint8)0U);
MONPRM volatile boolean IOCtl_PwrNmReqFlg = false;
MONPRM volatile uint8 IOCtl_RecircTrgPos = ((uint8)0U);
MONPRM volatile boolean IOCtl_bMixStall = false;
MONPRM volatile boolean IOCtl_bModeMoveSts = false;
MONPRM volatile boolean IOCtl_bModeStall = false;
MONPRM volatile boolean IOCtl_bRecStall = false;
MONPRM volatile float32 IOCtl_sMixDoorTrgPos = 0.0F;
MONPRM volatile float32 IOCtl_sModeMotorTrgPos = 0.0F;
MONPRM volatile boolean MCV_ErrResp = false;
MONPRM volatile uint8 MCV_FltSts = ((uint8)0U);
MONPRM volatile uint8 MCV_Mode = ((uint8)0U);
MONPRM volatile uint16 MCV_PosRec = ((uint16)0U);
MONPRM volatile boolean MCV_RunSts = false;
MONPRM volatile uint8 MCV_SpdLvl = ((uint8)0U);
MONPRM volatile uint8 MCV_TempSts = ((uint8)0U);
MONPRM volatile uint8 MCV_VoltSts = ((uint8)0U);
MONPRM volatile boolean MotPMP_PumpDryRunningSta = false;
MONPRM volatile uint8 MotPMP_PumpInputVolt = ((uint8)0U);
MONPRM volatile uint8 MotPMP_PumpMotorSta = ((uint8)0U);
MONPRM volatile uint8 MotPMP_PumpPowerSta = ((uint8)0U);
MONPRM volatile uint8 MotPMP_PumpTempSta = ((uint8)0U);
MONPRM volatile boolean MotPMP_RESP_ERROR = false;
MONPRM volatile float32 MotPMP_RealRPM = 0.0F;
MONPRM volatile float32 PCU_StartClntTemp = 0.0F;
MONPRM volatile float32 PCUtempOffset2ShutByEnv = 0.0F;
MONPRM volatile float32 PWRCtl_VCUACCMLimitPwr = 0.0F;
MONPRM volatile boolean PWRCtl_bKL15swtSt = false;
MONPRM volatile boolean PWRCtl_bUnlockVentTimeFlg = false;
MONPRM volatile uint8 PWRCtl_eBatChargSts = ((uint8)0U);
MONPRM volatile PwrModes PWRCtl_eTMSStatus = PwrOff;
MONPRM volatile uint8 PWRCtl_eUnlockActFlg = ((uint8)0U);
MONPRM volatile uint8 PWRCtl_eVCUPTSts = ((uint8)0U);
MONPRM volatile float32 PWRCtl_sCOMPActlPwr = 0.0F;
MONPRM volatile float32 PWRCtl_sLmtPwrCOMP = 0.0F;
MONPRM volatile uint32 PWRCtl_uTMSRunTimer = 0U;
MONPRM volatile uint32 PWRCtl_uTMSRunTimer20ms = 0U;
MONPRM volatile float32 PidCabinX_IsumMax = 0.0F;
MONPRM volatile float32 PidCabinX_IsumMin = 0.0F;
MONPRM volatile boolean RMTCtl_bRemtACDefFlg = false;
MONPRM volatile boolean RMTCtl_bRemtACFlg = false;
MONPRM volatile uint16 SENCtl_uACCMHighTempVol = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uCabinVoltage = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uChillTempVol = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uEVAPSurfTempVol = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uEVAPXTempVol = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uEnvVoltage = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uFaceDuctVal = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uFootDuctVal = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uMixDoorVol = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uModeDoorVol = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uMotInletTempVol = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uOHXTempVol = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uRecircDoorVol = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uSolorVol = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uWCCHPVol = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uWCCHighTempVol = ((uint16)0U);
MONPRM volatile uint16 SENCtl_uWCCLPVol = ((uint16)0U);
MONPRM volatile float32 SEN_ACCMTHiRaw = 0.0F;
MONPRM volatile float32 SEN_ChiTRaw = 0.0F;
MONPRM volatile float32 SEN_EvapTRaw = 0.0F;
MONPRM volatile float32 SEN_LoPressRaw = 0.0F;
MONPRM volatile float32 SEN_MixDoorRaw = 0.0F;
MONPRM volatile float32 SEN_OHXTRaw = 0.0F;
MONPRM volatile uint16 SEN_SolarRaw = ((uint16)0U);
MONPRM volatile float32 SEN_TCabinRaw = 0.0F;
MONPRM volatile float32 SEN_TDuctRaw = 0.0F;
MONPRM volatile float32 SEN_TEnvRaw = 0.0F;
MONPRM volatile float32 SEN_TEvapSurRaw = 0.0F;
MONPRM volatile float32 SEN_TFootDuctRaw = 0.0F;
MONPRM volatile float32 SEN_TMotRaw = 0.0F;
MONPRM volatile float32 SEN_WCCHiPressRaw = 0.0F;
MONPRM volatile float32 SEN_WCCTHiRaw = 0.0F;
MONPRM volatile boolean SOMCtl_bBatB1TB41Flg = false;
MONPRM volatile boolean SOMCtl_bBatB1TB42Flg = false;
MONPRM volatile boolean SOMCtl_bBatBalEntBFlg = false;
MONPRM volatile boolean SOMCtl_bBatCoolFlg = false;
MONPRM volatile boolean SOMCtl_bBatHeatChrgFlgAB = false;
MONPRM volatile boolean SOMCtl_bBatHeatFlg = false;
MONPRM volatile boolean SOMCtl_bBatHeatOffFlg = false;
MONPRM volatile boolean SOMCtl_bBatHeatPwrLmtF = false;
MONPRM volatile boolean SOMCtl_bBatHeatTempDiffE = false;
MONPRM volatile boolean SOMCtl_bBatTSEntAFlg = false;
MONPRM volatile boolean SOMCtl_bBatTSEntBFlg = false;
MONPRM volatile boolean SOMCtl_bBatTSExitFlg = false;
MONPRM volatile boolean SOMCtl_bBatTSFlg = false;
MONPRM volatile boolean SOMCtl_bCalTempBatHeatFlg = false;
MONPRM volatile boolean SOMCtl_bDBatLTROffFlg = false;
MONPRM volatile boolean SOMCtl_bEntExtDefFlg = false;
MONPRM volatile boolean SOMCtl_bExitExtDefTempFlg = false;
MONPRM volatile boolean SOMCtl_bExtDefFlg = false;
MONPRM volatile boolean SOMCtl_bMD1CLMSts = false;
MONPRM volatile boolean SOMCtl_bMD1ToMD2Flg = false;
MONPRM volatile boolean SOMCtl_bMD2DHMD1Flg = false;
MONPRM volatile boolean SOMCtl_bMD2ToMD1Flg = false;
MONPRM volatile boolean SOMCtl_bMD2ToMD3Flg = false;
MONPRM volatile boolean SOMCtl_bMD3DHMD2Flg = false;
MONPRM volatile boolean SOMCtl_bMD3ToMD2Flg = false;
MONPRM volatile boolean SOMCtl_bMD3ToMD4Flg = false;
MONPRM volatile boolean SOMCtl_bMD4ToMD3Flg = false;
MONPRM volatile boolean SOMCtl_bMotAndBatLTRFlg = false;
MONPRM volatile boolean SOMCtl_bMotHeatBatFlg = false;
MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOffFlg = false;
MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOn1Flg = false;
MONPRM volatile boolean SOMCtl_bMotLTRAndBatBalOn2Flg = false;
MONPRM volatile boolean SOMCtl_bMotorHeatBatOffFlg = false;
MONPRM volatile boolean SOMCtl_bMotorHeatBatOnFlg = false;
MONPRM volatile boolean SOMCtl_bMotorLTRAndBatBalFlg = false;
MONPRM volatile uint8 SOMCtl_eBatBalEntBFlg = ((uint8)0U);
MONPRM volatile uint8 SOMCtl_eBatCoolB1tB21 = ((uint8)0U);
MONPRM volatile uint8 SOMCtl_eBatCoolB1tB22 = ((uint8)0U);
MONPRM volatile uint8 SOMCtl_eBatCoolB2tB1 = ((uint8)0U);
MONPRM volatile uint8 SOMCtl_eBatHeatOffVal = ((uint8)0U);
MONPRM volatile uint8 SOMCtl_eBatLTROnFlg = ((uint8)0U);
MONPRM volatile BatModes SOMCtl_eBatMode = Off;
MONPRM volatile CabinMode SOMCtl_eCabinMode = CabinMode_MD_Off;
MONPRM volatile CabinMode SOMCtl_eCabinModePre = CabinMode_MD_Off;
MONPRM volatile uint8 SOMCtl_eHVPartMode = ((uint8)0U);
MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOffFlg = ((uint8)0U);
MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOn1Flg = ((uint8)0U);
MONPRM volatile uint8 SOMCtl_eMotLTRAndBatBalOn2Flg = ((uint8)0U);
MONPRM volatile uint8 SOMCtl_eMotorHeatBat2Flg = ((uint8)0U);
MONPRM volatile uint8 SOMCtl_eMotorHeatBatFlg = ((uint8)0U);
MONPRM volatile uint16 SOMCtl_eMotorHeatBatOffFlg = ((uint16)0U);
MONPRM volatile RefModes SOMCtl_eRefModes = RefModes_Ref_Off;
MONPRM volatile WaterModes SOMCtl_eWaterMode = WaterOff;
MONPRM volatile float32 SOMCtl_sBatHeatPTCTrgT = 0.0F;
MONPRM volatile float32 SOMCtl_sBatHeatT1 = 0.0F;
MONPRM volatile float32 SOMCtl_sBatHeatT2 = 0.0F;
MONPRM volatile float32 SOMCtl_sBatHeatTrgTempComp = 0.0F;
MONPRM volatile float32 SOMCtl_sBatTrgTemp = 0.0F;
MONPRM volatile float32 SOMCtl_sF1Value = 0.0F;
MONPRM volatile float32 SOMCtl_sF2Value = 0.0F;
MONPRM volatile uint8 TMS_VersionNumber = ((uint8)7U);
MONPRM volatile float32 ThCo_rSetLeftMixDoor = 0.0F;
MONPRM volatile float32 ThCo_rSetRightMixDoor = 0.0F;
