/*
 * File: monPrmsOpm.h
 *
 * Code generated for Simulink model 'AppSwcOpm'.
 *
 * Model version                  : 9.73
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Jul 16 10:40:51 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_monPrmsOpm_h_
#define RTW_HEADER_monPrmsOpm_h_
#include "rtwtypes.h"
#include "AppSwcOpm_types.h"

/* Exported data declaration */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Declaration for custom storage class: Volatile */
extern MONPRM volatile uint8 VOPM_12VBatLowVolSta_enum;/* '<S329>/MinMax1' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile float32 VOPM_ACActTotPwr_kW;/* '<S49>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_ACActlOprtMode_enum;/* '<S50>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_ACAirInletModeSta_enum;/* '<S92>/MinMax1' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile uint8 VOPM_ACAutoBlwrModeSta_enum;/* '<S93>/MinMax1' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile boolean VOPM_ACAutoFb_flg;/* '<S94>/Switch4' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile uint8 VOPM_ACAutoFrntFanSpd_enum;/* '<S79>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile boolean VOPM_ACBatPmpFailSta_flg;/* '<S51>/Switch4' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_ACBlwrModeSta_enum;/* '<S95>/MinMax1' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile boolean VOPM_ACCMOprtCmd_flg;/* '<S146>/Switch4' */

/* VCU_7_DrvRange_BOD */
extern MONPRM volatile boolean VOPM_ACCTrqCtrlAvl_flg;/* '<S260>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_ACCompFailModeOprtSta_flg;/* '<S39>/Switch4' */

/* AC_1_Command_BOD */
extern MONPRM volatile float32 VOPM_ACCompMaxAllowPwrCmsp_kW;/* '<S40>/MinMax1' */

/* AC_1_Command_BOD */
extern MONPRM volatile boolean VOPM_ACCompOprtEnaCmd_flg;/* '<S41>/Switch4' */

/* AC_1_Command_BOD */
extern MONPRM volatile boolean VOPM_ACCompOprtReq_flg;/* '<S42>/Switch4' */

/* AC_1_Command_BOD */
extern MONPRM volatile float32 VOPM_ACCompTgtSpd_rpm;/* '<S43>/MinMax1' */

/* AC_1_Command_BOD */
extern MONPRM volatile boolean VOPM_ACEnvirTempVld_flg;/* '<S65>/Switch4' */

/* AC_3_State_BOD */
extern MONPRM volatile float32 VOPM_ACEnvirTemp_C;/* '<S66>/MinMax1' */

/* AC_3_State_BOD */
extern MONPRM volatile float32 VOPM_ACEvapTgtTemp_C;/* '<S80>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile boolean VOPM_ACExtdDefrstActvReq_flg;/* '<S67>/Switch4' */

/* AC_3_State_BOD */
extern MONPRM volatile boolean VOPM_ACFailSta_flg;/* '<S52>/Switch4' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_ACFrntFanSpdVal_enum;/* '<S96>/MinMax1' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile uint8 VOPM_ACHVHActlOprtMode_enum;/* '<S53>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile float32 VOPM_ACHVHActlPwr_KW;/* '<S54>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile float32 VOPM_ACHVHDevInternTemp_C;/* '<S55>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile boolean VOPM_ACHVHFailSta_flg;/* '<S56>/Switch4' */

/* AC_2_State_BOD */
extern MONPRM volatile float32 VOPM_ACHVPTCIntPCBTemp_C;/* '<S81>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile float32 VOPM_ACHVPTCMedTemp_C;/* '<S82>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile uint8 VOPM_ACHVPTCOnRq_enum;/* '<S83>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile uint8 VOPM_ACHVPTCheatingrq_pct;/* '<S84>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile float32 VOPM_ACHighVolDCTotalPwr_kW;/* '<S44>/MinMax1' */

/* AC_1_Command_BOD */
extern MONPRM volatile uint8 VOPM_ACHybEcoModeSta_enum;/* '<S97>/MinMax1' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile float32 VOPM_ACIndoorTemp_C;/* '<S68>/MinMax1' */

/* AC_3_State_BOD */
extern MONPRM volatile boolean VOPM_ACLCurrtSlctFrgDirct_flg;/* '<S85>/Switch4' */

/* AC_8_status_BOD */
extern MONPRM volatile uint8 VOPM_ACLeftTempVal_enum;/* '<S98>/MinMax1' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile boolean VOPM_ACManlDefrstFb_flg;/* '<S99>/Switch4' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile boolean VOPM_ACPumpActlSpdDutyVld_flg;/* '<S45>/Switch4' */

/* AC_1_Command_BOD */
extern MONPRM volatile uint8 VOPM_ACPumpActlSpdDuty_pct;/* '<S46>/MinMax1' */

/* AC_1_Command_BOD */
extern MONPRM volatile boolean VOPM_ACPwrFb_flg;/* '<S100>/Switch4' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile boolean VOPM_ACRefrgLoPresVld_flg;/* '<S86>/Switch4' */

/* AC_8_status_BOD */
extern MONPRM volatile float32 VOPM_ACRefrgLoPres_kPa;/* '<S87>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile EnumAccPedSnsrSt VOPM_AccPedPosSnsrSta_enum;/* '<S261>/Data Type Conversion2' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_AccPedPosToESCSta_enum;/* '<S262>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_AccPedPosToESC_pct;/* '<S263>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_AcclPedalPos_pct;/* '<S264>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_ActWhlTqVld_flg;/* '<S166>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_ActWhlTq_Nm;/* '<S167>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_ActlMotorRotateSpdVld_flg;/* '<S168>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_ActlMotorRotateSpd_rpm;/* '<S169>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_ActlMotorTorqVld_flg;/* '<S170>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_ActlMotorTorq_Nm;/* '<S171>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_AllowHeatCoolMaxPwrCmsp_kW;/* '<S298>/MinMax1' */

/* VCU_3_OprtCmd_EPT */
extern MONPRM volatile uint8 VOPM_AppSoftNumb_nu;/* '<S201>/MinMax1' */

/* VCU_0_Value_EPT */
extern MONPRM volatile boolean VOPM_BCMAjarStaHood_flg;/* '<S346>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMAjarStaTrunk_flg;/* '<S347>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMAjarStaVHoodVld_flg;/* '<S348>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMAlrmHornReq_flg;/* '<S349>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMAuthentKeyNr_enum;/* '<S350>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMAutoLampStatus_flg;/* '<S351>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMAvaluebleKeyInCar_flg;/* '<S352>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMBackLadjvalFb_enum;/* '<S353>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMBassHornReq_enum;/* '<S354>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMBodyWarnSts_enum;/* '<S355>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMBrakeLampSta_flg;/* '<S356>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMBrkPedSta_flg;/* '<S330>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMCenLckSts_enum;/* '<S331>/MinMax1' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMCenLckSwCtrlFb_enum;/* '<S332>/MinMax1' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMChgWiprMtMdSwSetFb_enum;/* '<S357>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMChrgLidLockReq_enum;/* '<S358>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDayRunLiSwSig_flg;/* '<S359>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDayRunLightSta_flg;/* '<S360>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDoorAjarStaFL_flg;/* '<S361>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDoorAjarStaFR_flg;/* '<S362>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDoorAjarStaRL_flg;/* '<S363>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDoorAjarStaRR_flg;/* '<S364>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDoorLckStaFL_flg;/* '<S333>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMDrvPEAuthentAcsd_enum;/* '<S365>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMDrvSeatOccptSnsrSts_enum;/* '<S366>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMDrvrWinSwSig_enum;/* '<S367>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFLWinSts_flg;/* '<S368>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFLWinmotorSts_enum;/* '<S369>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFRPEAuthentAcsd_enum;/* '<S370>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFRWinSts_flg;/* '<S371>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFRWinmotorSts_enum;/* '<S372>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFlwrMeHmCtrlFb_enum;/* '<S373>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFogLampStaFront_flg;/* '<S374>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFogLampStaRear_flg;/* '<S375>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFrbdnKeyNr_enum;/* '<S376>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFrntFogLiSwSig_flg;/* '<S377>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFrntLeDoorHndlSwt_enum;/* '<S378>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFrntRiDoorHndlSwt_enum;/* '<S379>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFrntWiprMotSts_enum;/* '<S380>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFrntWshrSwSig_flg;/* '<S381>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFrontWashSts_flg;/* '<S382>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMHazardLampSts_flg;/* '<S383>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiBeamSwSig_enum;/* '<S384>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte0_nu;/* '<S11>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte10_nu;/* '<S12>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte11_nu;/* '<S13>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte12_nu;/* '<S14>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte13_nu;/* '<S15>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte14_nu;/* '<S16>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte15_nu;/* '<S17>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte1_nu;/* '<S18>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte2_nu;/* '<S19>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte3_nu;/* '<S20>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte4_nu;/* '<S21>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte5_nu;/* '<S22>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte6_nu;/* '<S23>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte7_nu;/* '<S24>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte8_nu;/* '<S25>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte9_nu;/* '<S26>/MinMax1' */

/* BCM_HFSData_BAC */
extern MONPRM volatile boolean VOPM_BCMHighBeamSta_flg;/* '<S385>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMHvyRainInd_flg;/* '<S386>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMHzrdWrngLghtSwSig_flg;/* '<S387>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMIllmndEntryStsFb_flg;/* '<S388>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMIllmndLampReq_flg;/* '<S389>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMIllmndLckStsFb_flg;/* '<S223>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMIllmndLockReq_enum;/* '<S390>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMIllmndSts_enum;/* '<S391>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMIllmndUnlckStsFb_flg;/* '<S224>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_BCMIndcnKeyClsr_flg;/* '<S392>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMIndcnShfttoNeut_flg;/* '<S393>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMKeyBattLvlSts_flg;/* '<S394>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile float32 VOPM_BCMKeyBattLvl_pct;/* '<S395>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMKeyFrbdn_flg;/* '<S396>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMKeyIDFb_enum;/* '<S397>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMKeyInCarSta_flg;/* '<S398>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMKeyLoBattLvlWarn_flg;/* '<S399>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint16 VOPM_BCMKeyLocn_mm;/* '<S400>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMKeySta_enum;/* '<S401>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMLckHornOnStFb_flg;/* '<S402>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMLeTrnLiFltFb_enum;/* '<S403>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMLghtSwSig_enum;/* '<S404>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMLightIntensity_enum;/* '<S405>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMLogoActvFlg_enum;/* '<S406>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMLowBeamSta_flg;/* '<S407>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMLrngData02_nu;/* '<S155>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngData03_nu;/* '<S156>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngData04_nu;/* '<S157>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngData05_nu;/* '<S158>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngData06_nu;/* '<S159>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngData07_nu;/* '<S160>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngSts_enum;/* '<S161>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngsubID_cnt;/* '<S162>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMMaiDrvrSeatSts_enum;/* '<S408>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile float32 VOPM_BCMMaiDrvrSeatTemp_C;/* '<S409>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMOvrspdCntrlLckSetFb_flg;/* '<S410>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMPSAuthentRes_enum;/* '<S411>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMPSReq_flg;/* '<S412>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMParkAutoUnlckSetFb_flg;/* '<S413>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMPassWinSwSig_enum;/* '<S414>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMPaswdwInit_flg;/* '<S415>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMPosLampSta_flg;/* '<S416>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMRFInitSta_flg;/* '<S417>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMRKEReq_enum;/* '<S418>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMReverseLampSta_flg;/* '<S419>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMRiTrnLiFltFb_enum;/* '<S420>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMRrFogLiSwSig_flg;/* '<S421>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMRrMirrHeatSts_flg;/* '<S422>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMRrViewMirrHeatgSts_flg;/* '<S101>/Switch4' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile uint8 VOPM_BCMStartReq_enum;/* '<S423>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMSteerWhlHeatSts_flg;/* '<S424>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile float32 VOPM_BCMSteerWhlTemp_C;/* '<S425>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMSysPowerSts_enum;/* '<S334>/MinMax1' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile boolean VOPM_BCMSysPwrModeVld_flg;/* '<S335>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMSysPwrMode_enum;/* '<S336>/MinMax1' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMTPMSRstSts_enum;/* '<S426>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMTrnkLckSta_flg;/* '<S427>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMTrnkLckSwCtrlFb_flg;/* '<S428>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMTrnngLiSwSig_enum;/* '<S429>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMTrunkSwtSig_flg;/* '<S430>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMTurnLampStaLeft_flg;/* '<S431>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMTurnLampStaRight_flg;/* '<S432>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMTurnLiSts_enum;/* '<S433>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMVehSeek_flg;/* '<S434>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMWarnKeyOutRmndr_flg;/* '<S435>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMWarnNoKeyFound_flg;/* '<S436>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMWashLiquidLvlWarn_flg;/* '<S437>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMWinLockSig_flg;/* '<S438>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMWinLockSts_flg;/* '<S439>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMWiperCtrlFront_enum;/* '<S440>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMWiperSwSig_enum;/* '<S441>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMWiprIntlGrSwtSig_enum;/* '<S442>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMWiprIntlTimeSetFb_enum;/* '<S443>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile EnumBMSSdnCmd VOPM_BMSShutdown_enum;/* '<S305>/Data Type Conversion2' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile EnumBMSWakeUpMd VOPM_BMSWakeupMode_enum;/* '<S299>/Data Type Conversion2' */

/* VCU_3_OprtCmd_EPT */
extern MONPRM volatile boolean VOPM_Bat2DrvTrainEnb_flg;/* '<S300>/Switch4' */

/* VCU_3_OprtCmd_EPT */
extern MONPRM volatile boolean VOPM_BraSwi_flg;/* '<S202>/Switch4' */

/* VCU_0_Value_EPT */
extern MONPRM volatile uint8 VOPM_BrkPedSnsrPosVRsrvd_enum;/* '<S265>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_BrkPedalPos_pct;/* '<S266>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_BrkPwrRecupActWhlTq_Nm;/* '<S172>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile uint8 VOPM_BrkPwrRecupActlWhlTqSts_enum;/* '<S173>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_BrkPwrRecupMaxAvlbWhlTq_Nm;/* '<S174>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile uint8 VOPM_CCKeyStgntn_enum;/* '<S225>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_COMPCompInPwrLim_W;/* '<S102>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile uint8 VOPM_COMPEcompEnbl_enum;/* '<S103>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile uint8 VOPM_COMPEcompErrClean_enum;/* '<S104>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile uint8 VOPM_COMPEcompHVSt_enum;/* '<S105>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile float32 VOPM_COMPEcompSpdCtrl_rpm;/* '<S106>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile EnumChrgAllwCmd VOPM_ChrgAllowCmd_enum;/* '<S306>/Data Type Conversion2' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile EnumChrgEnaAC VOPM_ChrgEnaAC_enum;/* '<S301>/Data Type Conversion2' */

/* VCU_3_OprtCmd_EPT */
extern MONPRM volatile boolean VOPM_ChrgEnaDC_flg;/* '<S307>/Switch4' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile float32 VOPM_DCCBoostHvVolt_V;/* '<S317>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
extern MONPRM volatile float32 VOPM_DCCBuckLVVolt_V;/* '<S318>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
extern MONPRM volatile EnumDCCOprtCmd VOPM_DCCOprtCmd_enum;/* '<S313>/Data Type Conversion2' */

/* VCU_B_AcclPedal_EPT */
extern MONPRM volatile uint8 VOPM_DrvModeKeyStgntn_enum;/* '<S226>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_DrvMotorSta_enum;/* '<S227>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_DrvPed_pct;/* '<S203>/MinMax1' */

/* VCU_0_Value_EPT */
extern MONPRM volatile boolean VOPM_DrvRangeDistEstVld_flg;/* '<S228>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_DrvRangeDistEst_km;/* '<S229>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_DrvReqMotorTorqVld_flg;/* '<S175>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_DrvReqMotorTorq_Nm;/* '<S176>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_DrvReqTorqOverrideFCM_flg;/* '<S267>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_DrvReqTorqOvrdESC_flg;/* '<S268>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_DrvReqWhlTqVld_flg;/* '<S177>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_DrvReqWhlTq_Nm;/* '<S178>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_DrvSwi_flg;/* '<S204>/Switch4' */

/* VCU_0_Value_EPT */
extern MONPRM volatile float32 VOPM_DrvWhlTqAllwdMax_Nm;/* '<S179>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile uint64 VOPM_ESCLUnOrLockCrtl_nu;/* '<S113>/MinMax1' */

/* BCM_ESCLCommand_BOD */
extern MONPRM volatile boolean VOPM_EmgcySdn_flg;/* '<S209>/Switch4' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile boolean VOPM_EnaDisChg_flg;/* '<S210>/Switch4' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile boolean VOPM_EnaInvRun_flg;/* '<S211>/Switch4' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile uint8 VOPM_ErrAmount_cnt;/* '<S314>/MinMax1' */

/* VCU_B_AcclPedal_EPT */
extern MONPRM volatile uint16 VOPM_ErrBit_nu;/* '<S315>/MinMax1' */

/* VCU_B_AcclPedal_EPT */
extern MONPRM volatile boolean VOPM_GearShiftInhibited_flg;/* '<S269>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_HDCStat_enum;/* '<S337>/MinMax1' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_HVCHEnbld_enum;/* '<S114>/MinMax1' */

/* HVCH_Command_BOD */
extern MONPRM volatile float32 VOPM_HVCHReqPwr_kW;/* '<S115>/MinMax1' */

/* HVCH_Command_BOD */
extern MONPRM volatile float32 VOPM_HVCHReqTemp_C;/* '<S116>/MinMax1' */

/* HVCH_Command_BOD */
extern MONPRM volatile boolean VOPM_IBSWakeup_flg;/* '<S147>/Switch4' */

/* VCU_7_DrvRange_BOD */
extern MONPRM volatile uint8 VOPM_InfoDisp_enum;/* '<S230>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_LimpHomeSta_flg;/* '<S338>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile boolean VOPM_MCUHiTempWrning_flg;/* '<S231>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_MaxChrgCurntDC_A;/* '<S308>/MinMax1' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile float32 VOPM_MaxChrgVoltDC_V;/* '<S309>/MinMax1' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile float32 VOPM_MaxHVDCCurntAC_A;/* '<S319>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
extern MONPRM volatile float32 VOPM_MaxHVDCVoltAC_V;/* '<S320>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
extern MONPRM volatile uint8 VOPM_MotActPwrTyp_enum;/* '<S232>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_MotActPwr_Kw;/* '<S233>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile EnumMotorDirReq VOPM_MotDirReq_enum;/* '<S212>/Data Type Conversion2' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile float32 VOPM_MotDmpgLmt_Nm;/* '<S205>/MinMax1' */

/* VCU_0_Value_EPT */
extern MONPRM volatile EnumMotorModeReq VOPM_MotModeReq_enum;/* '<S213>/Data Type Conversion2' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile float32 VOPM_MotSpdReq_rpm;/* '<S214>/MinMax1' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile float32 VOPM_MotTorqReq_Nm;/* '<S215>/MinMax1' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile boolean VOPM_MotorHiTempWrning_flg;/* '<S234>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_MotorOutputCooltTemp_C;/* '<S302>/MinMax1' */

/* VCU_3_OprtCmd_EPT */
extern MONPRM volatile boolean VOPM_OBCIntDchrgEna_flg;/* '<S321>/Switch4' */

/* VCU_C_OprtCmd_EPT */
extern MONPRM volatile EnumOBCOprtCmd VOPM_OBCOprtCmdToICU_enum;/* '<S235>/Data Type Conversion2' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile EnumOBCOprtCmd VOPM_OBCOprtCmd_enum;/* '<S310>/Data Type Conversion2' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile boolean VOPM_OTAModeSts_flg;/* '<S270>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_PCUFailSta_flg;/* '<S339>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_PGrSwcSt_enum;/* '<S271>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile EnumPTActMd VOPM_PTActlOprtMode_enum;/* '<S340>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile EnumCrpModeAct VOPM_PrstlsStaFb_enum;/* '<S341>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_PtReadyEna_enum;/* '<S148>/MinMax1' */

/* VCU_7_DrvRange_BOD */
extern MONPRM volatile float32 VOPM_PwrRecupActWhlTq_Nm;/* '<S180>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile uint8 VOPM_PwrRecupActlWhlTqSts_enum;/* '<S181>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile EnumRegenModeAct VOPM_PwrRecupIntnsty_enum;/* '<S342>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_PwrRecupMaxAvlbMotorTorqSta_enum;/* '<S272>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_PwrRecupMaxAvlbWhlTqSts_enum;/* '<S182>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_RsrvdPwr_kW;/* '<S236>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_SIBSBMSBatSOCAllow_flg;/* '<S237>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_SIBSChgNumAllow_flg;/* '<S238>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_SIBSFbRTCWupFlg_flg;/* '<S239>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_SIBSKL30Volt_V;/* '<S240>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile EnumIBSChrgSt VOPM_SIBSRTCChrgSt_enum;/* '<S241>/Data Type Conversion2' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_SIBSRTCWUChgFailNum_cnt;/* '<S242>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_SIBSRTCWUChgNum_cnt;/* '<S243>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_SIBSWupVoltAllow_flg;/* '<S244>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_ShftKeyStgntn_enum;/* '<S245>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_StrgRecupReqBrkLampOn_flg;/* '<S273>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_SysFailSta_enum;/* '<S316>/MinMax1' */

/* VCU_B_AcclPedal_EPT */
extern MONPRM volatile boolean VOPM_TMPSAbnmPrsrWarn_flg;/* '<S444>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile float32 VOPM_TMSACPExhtTmp_C;/* '<S107>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile float32 VOPM_TMSACPInletPres_kPa;/* '<S108>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile uint16 VOPM_TMSAEXVCurrentPstn_cnt;/* '<S132>/MinMax1' */

/* TMS_LINTestData2_BOD */
extern MONPRM volatile boolean VOPM_TMSAEXVEnblReq_flg;/* '<S136>/Switch4' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint16 VOPM_TMSAEXVPstnReq_cnt;/* '<S133>/MinMax1' */

/* TMS_LINTestData2_BOD */
extern MONPRM volatile float32 VOPM_TMSAcPMPRealRPM_rpm;/* '<S119>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile float32 VOPM_TMSAcPMPSpdSet_rpm;/* '<S120>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile uint16 VOPM_TMSBEXVCurrentPstn_cnt;/* '<S134>/MinMax1' */

/* TMS_LINTestData2_BOD */
extern MONPRM volatile boolean VOPM_TMSBEXVEnblCmd_flg;/* '<S137>/Switch4' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint16 VOPM_TMSBEXVPstnCmd_cnt;/* '<S135>/MinMax1' */

/* TMS_LINTestData2_BOD */
extern MONPRM volatile float32 VOPM_TMSBatPMPRealRPM_rpm;/* '<S121>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile float32 VOPM_TMSBatPMPSpdSet_rpm;/* '<S122>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile boolean VOPM_TMSBattTempCtrlRmnSwFb_flg;/* '<S57>/Switch4' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_TMSC3WVBPosSetReq_enum;/* '<S138>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint8 VOPM_TMSC3WVMode_enum;/* '<S139>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint16 VOPM_TMSC3WVPosRec_enum;/* '<S140>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint8 VOPM_TMSC5WVBPosSetReq_enum;/* '<S141>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint8 VOPM_TMSC5WVMode_enum;/* '<S142>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint16 VOPM_TMSC5WVPosRec_enum;/* '<S143>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile float32 VOPM_TMSChillerOutTmp_C;/* '<S69>/MinMax1' */

/* AC_3_State_BOD */
extern MONPRM volatile float32 VOPM_TMSEvapOutTmp_C;/* '<S70>/MinMax1' */

/* AC_3_State_BOD */
extern MONPRM volatile float32 VOPM_TMSEvapTmp_C;/* '<S71>/MinMax1' */

/* AC_3_State_BOD */
extern MONPRM volatile uint16 VOPM_TMSHPEXVCurrentPstn_cnt;/* '<S144>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile boolean VOPM_TMSHPEXVEnblCmd_flg;/* '<S145>/Switch4' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint16 VOPM_TMSHPEXVPstnCmd_cnt;/* '<S123>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile float32 VOPM_TMSMotPMPRealRPM_rpm;/* '<S124>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile float32 VOPM_TMSMotPMPSpdSet_rpm;/* '<S125>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile float32 VOPM_TMSOHXOutTmp_C;/* '<S72>/MinMax1' */

/* AC_3_State_BOD */
extern MONPRM volatile boolean VOPM_TMSPCUInletCooltTempVld_flg;/* '<S149>/Switch4' */

/* VCU_7_DrvRange_BOD */
extern MONPRM volatile float32 VOPM_TMSPCUInletCooltTemp_C;/* '<S150>/MinMax1' */

/* VCU_7_DrvRange_BOD */
extern MONPRM volatile float32 VOPM_TMSPTPres_kPa;/* '<S58>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile float32 VOPM_TMSPTTemp_C;/* '<S59>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_TMSPwrCoolFanSpdDuty_pct;/* '<S151>/MinMax1' */

/* VCU_7_DrvRange_BOD */
extern MONPRM volatile uint8 VOPM_TPMSPressureStaFL_enum;/* '<S445>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_TPMSPressureStaFR_enum;/* '<S446>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_TPMSPressureStaRL_enum;/* '<S447>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_TPMSPressureStaRR_enum;/* '<S448>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_VCUACCStandstillReq_flg;/* '<S274>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_VCUAccReqDrvOff_flg;/* '<S183>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_VCUAccReqStandstill_flg;/* '<S184>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_VCUAccTgtAxReq_flg;/* '<S275>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_VCUAccTgtAx_mps2;/* '<S276>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_VCUBraTorReq_Nm;/* '<S277>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_VCUCruiseCtrTgtSpd_kph;/* '<S278>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile EnumCruiseStatus VOPM_VCUCruiseCtrlSta_enum;/* '<S279>/Data Type Conversion2' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_VCUEPBApplyForbid_enum;/* '<S280>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_VCUEnaEHBBrkRun_flg;/* '<S185>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_VCUMasterCylinderPreReq_Bar;/* '<S186>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_VCUMotTorqueReqToEHB_Nm;/* '<S187>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_VCUParkSwStaVld_flg;/* '<S281>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_VCUParkSwSta_flg;/* '<S282>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_VCUPreKeReq_flg;/* '<S283>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_VCUReqAutoBrk_enum;/* '<S284>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_VCUReqEPBVld_flg;/* '<S285>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile EnumEPBReq VOPM_VCUReqEPB_enum;/* '<S286>/Data Type Conversion2' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_VCUVehSpdFastWarn_flg;/* '<S188>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile EnumDrvModeAct VOPM_VehActDrvMod1_enum;/* '<S343>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_VehActDrvPwr_pct;/* '<S246>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_VehActRecupPwr_pct;/* '<S247>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_VehActlGearPosVld_flg;/* '<S344>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile EnumGearPstn VOPM_VehActlGearPos_enum;/* '<S345>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile boolean VOPM_VehPGearError_flg;/* '<S248>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_VehPwrCnsmpAvrg_kWh;/* '<S249>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile EnumTgtGearPstn VOPM_VehTrgtGearPos_enum;/* '<S216>/Data Type Conversion2' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile float32 VOPM_VhclActlCnsmPwr_kWh;/* '<S250>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_VhclSpdFstWarn_flg;/* '<S251>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_WLTPDrvgRngDstVld_flg;/* '<S252>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_WLTPDrvgRngDst_km;/* '<S253>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_Zdznswi_flg;/* '<S206>/Switch4' */

/* VCU_0_Value_EPT */
#endif                                 /* RTW_HEADER_monPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
