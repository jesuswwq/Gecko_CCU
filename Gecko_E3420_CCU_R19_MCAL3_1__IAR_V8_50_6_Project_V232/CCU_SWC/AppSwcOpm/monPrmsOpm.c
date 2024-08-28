/*
 * File: monPrmsOpm.c
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

#include "monPrmsOpm.h"
#include "AppSwcOpm.h"

/* Exported data definition */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Definition for custom storage class: Volatile */
MONPRM volatile uint8 VOPM_12VBatLowVolSta_enum = ((uint8)0U);/* '<S329>/MinMax1' */

/* CCU_VehInfo_BAC */
MONPRM volatile float32 VOPM_ACActTotPwr_kW = 0.0F;/* '<S49>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_ACActlOprtMode_enum = ((uint8)0U);/* '<S50>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_ACAirInletModeSta_enum = ((uint8)0U);/* '<S92>/MinMax1' */

/* AC_ACStatuts_BOD */
MONPRM volatile uint8 VOPM_ACAutoBlwrModeSta_enum = ((uint8)0U);/* '<S93>/MinMax1' */

/* AC_ACStatuts_BOD */
MONPRM volatile boolean VOPM_ACAutoFb_flg = false;/* '<S94>/Switch4' */

/* AC_ACStatuts_BOD */
MONPRM volatile uint8 VOPM_ACAutoFrntFanSpd_enum = ((uint8)0U);/* '<S79>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile boolean VOPM_ACBatPmpFailSta_flg = false;/* '<S51>/Switch4' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_ACBlwrModeSta_enum = ((uint8)0U);/* '<S95>/MinMax1' */

/* AC_ACStatuts_BOD */
MONPRM volatile boolean VOPM_ACCMOprtCmd_flg = false;/* '<S146>/Switch4' */

/* VCU_7_DrvRange_BOD */
MONPRM volatile boolean VOPM_ACCTrqCtrlAvl_flg = false;/* '<S260>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_ACCompFailModeOprtSta_flg = false;/* '<S39>/Switch4' */

/* AC_1_Command_BOD */
MONPRM volatile float32 VOPM_ACCompMaxAllowPwrCmsp_kW = 0.0F;/* '<S40>/MinMax1' */

/* AC_1_Command_BOD */
MONPRM volatile boolean VOPM_ACCompOprtEnaCmd_flg = false;/* '<S41>/Switch4' */

/* AC_1_Command_BOD */
MONPRM volatile boolean VOPM_ACCompOprtReq_flg = false;/* '<S42>/Switch4' */

/* AC_1_Command_BOD */
MONPRM volatile float32 VOPM_ACCompTgtSpd_rpm = 0.0F;/* '<S43>/MinMax1' */

/* AC_1_Command_BOD */
MONPRM volatile boolean VOPM_ACEnvirTempVld_flg = false;/* '<S65>/Switch4' */

/* AC_3_State_BOD */
MONPRM volatile float32 VOPM_ACEnvirTemp_C = 0.0F;/* '<S66>/MinMax1' */

/* AC_3_State_BOD */
MONPRM volatile float32 VOPM_ACEvapTgtTemp_C = 0.0F;/* '<S80>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile boolean VOPM_ACExtdDefrstActvReq_flg = false;/* '<S67>/Switch4' */

/* AC_3_State_BOD */
MONPRM volatile boolean VOPM_ACFailSta_flg = false;/* '<S52>/Switch4' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_ACFrntFanSpdVal_enum = ((uint8)0U);/* '<S96>/MinMax1' */

/* AC_ACStatuts_BOD */
MONPRM volatile uint8 VOPM_ACHVHActlOprtMode_enum = ((uint8)0U);/* '<S53>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile float32 VOPM_ACHVHActlPwr_KW = 0.0F;/* '<S54>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile float32 VOPM_ACHVHDevInternTemp_C = 0.0F;/* '<S55>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile boolean VOPM_ACHVHFailSta_flg = false;/* '<S56>/Switch4' */

/* AC_2_State_BOD */
MONPRM volatile float32 VOPM_ACHVPTCIntPCBTemp_C = 0.0F;/* '<S81>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile float32 VOPM_ACHVPTCMedTemp_C = 0.0F;/* '<S82>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile uint8 VOPM_ACHVPTCOnRq_enum = ((uint8)0U);/* '<S83>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile uint8 VOPM_ACHVPTCheatingrq_pct = ((uint8)0U);/* '<S84>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile float32 VOPM_ACHighVolDCTotalPwr_kW = 0.0F;/* '<S44>/MinMax1' */

/* AC_1_Command_BOD */
MONPRM volatile uint8 VOPM_ACHybEcoModeSta_enum = ((uint8)0U);/* '<S97>/MinMax1' */

/* AC_ACStatuts_BOD */
MONPRM volatile float32 VOPM_ACIndoorTemp_C = 0.0F;/* '<S68>/MinMax1' */

/* AC_3_State_BOD */
MONPRM volatile boolean VOPM_ACLCurrtSlctFrgDirct_flg = false;/* '<S85>/Switch4' */

/* AC_8_status_BOD */
MONPRM volatile uint8 VOPM_ACLeftTempVal_enum = ((uint8)0U);/* '<S98>/MinMax1' */

/* AC_ACStatuts_BOD */
MONPRM volatile boolean VOPM_ACManlDefrstFb_flg = false;/* '<S99>/Switch4' */

/* AC_ACStatuts_BOD */
MONPRM volatile boolean VOPM_ACPumpActlSpdDutyVld_flg = false;/* '<S45>/Switch4' */

/* AC_1_Command_BOD */
MONPRM volatile uint8 VOPM_ACPumpActlSpdDuty_pct = ((uint8)0U);/* '<S46>/MinMax1' */

/* AC_1_Command_BOD */
MONPRM volatile boolean VOPM_ACPwrFb_flg = false;/* '<S100>/Switch4' */

/* AC_ACStatuts_BOD */
MONPRM volatile boolean VOPM_ACRefrgLoPresVld_flg = false;/* '<S86>/Switch4' */

/* AC_8_status_BOD */
MONPRM volatile float32 VOPM_ACRefrgLoPres_kPa = 0.0F;/* '<S87>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile EnumAccPedSnsrSt VOPM_AccPedPosSnsrSta_enum =
  EnumAccPedSnsrSt_Invalid;            /* '<S261>/Data Type Conversion2' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_AccPedPosToESCSta_enum = ((uint8)0U);/* '<S262>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_AccPedPosToESC_pct = 0.0F;/* '<S263>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_AcclPedalPos_pct = 0.0F;/* '<S264>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_ActWhlTqVld_flg = false;/* '<S166>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_ActWhlTq_Nm = 0.0F;/* '<S167>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_ActlMotorRotateSpdVld_flg = false;/* '<S168>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_ActlMotorRotateSpd_rpm = 0.0F;/* '<S169>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_ActlMotorTorqVld_flg = false;/* '<S170>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_ActlMotorTorq_Nm = 0.0F;/* '<S171>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_AllowHeatCoolMaxPwrCmsp_kW = 0.0F;/* '<S298>/MinMax1' */

/* VCU_3_OprtCmd_EPT */
MONPRM volatile uint8 VOPM_AppSoftNumb_nu = ((uint8)0U);/* '<S201>/MinMax1' */

/* VCU_0_Value_EPT */
MONPRM volatile boolean VOPM_BCMAjarStaHood_flg = false;/* '<S346>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMAjarStaTrunk_flg = false;/* '<S347>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMAjarStaVHoodVld_flg = false;/* '<S348>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMAlrmHornReq_flg = false;/* '<S349>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMAuthentKeyNr_enum = ((uint8)0U);/* '<S350>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMAutoLampStatus_flg = false;/* '<S351>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMAvaluebleKeyInCar_flg = false;/* '<S352>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMBackLadjvalFb_enum = ((uint8)0U);/* '<S353>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMBassHornReq_enum = ((uint8)0U);/* '<S354>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMBodyWarnSts_enum = ((uint8)0U);/* '<S355>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMBrakeLampSta_flg = false;/* '<S356>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMBrkPedSta_flg = false;/* '<S330>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMCenLckSts_enum = ((uint8)0U);/* '<S331>/MinMax1' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMCenLckSwCtrlFb_enum = ((uint8)0U);/* '<S332>/MinMax1' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMChgWiprMtMdSwSetFb_enum = ((uint8)0U);/* '<S357>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMChrgLidLockReq_enum = ((uint8)0U);/* '<S358>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDayRunLiSwSig_flg = false;/* '<S359>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDayRunLightSta_flg = false;/* '<S360>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDoorAjarStaFL_flg = false;/* '<S361>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDoorAjarStaFR_flg = false;/* '<S362>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDoorAjarStaRL_flg = false;/* '<S363>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDoorAjarStaRR_flg = false;/* '<S364>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDoorLckStaFL_flg = false;/* '<S333>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMDrvPEAuthentAcsd_enum = ((uint8)0U);/* '<S365>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMDrvSeatOccptSnsrSts_enum = ((uint8)0U);/* '<S366>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMDrvrWinSwSig_enum = ((uint8)0U);/* '<S367>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFLWinSts_flg = false;/* '<S368>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFLWinmotorSts_enum = ((uint8)0U);/* '<S369>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFRPEAuthentAcsd_enum = ((uint8)0U);/* '<S370>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFRWinSts_flg = false;/* '<S371>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFRWinmotorSts_enum = ((uint8)0U);/* '<S372>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFlwrMeHmCtrlFb_enum = ((uint8)0U);/* '<S373>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFogLampStaFront_flg = false;/* '<S374>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFogLampStaRear_flg = false;/* '<S375>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFrbdnKeyNr_enum = ((uint8)0U);/* '<S376>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFrntFogLiSwSig_flg = false;/* '<S377>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFrntLeDoorHndlSwt_enum = ((uint8)0U);/* '<S378>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFrntRiDoorHndlSwt_enum = ((uint8)0U);/* '<S379>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFrntWiprMotSts_enum = ((uint8)0U);/* '<S380>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFrntWshrSwSig_flg = false;/* '<S381>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFrontWashSts_flg = false;/* '<S382>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMHazardLampSts_flg = false;/* '<S383>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMHiBeamSwSig_enum = ((uint8)0U);/* '<S384>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte0_nu = ((uint8)0U);/* '<S11>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte10_nu = ((uint8)0U);/* '<S12>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte11_nu = ((uint8)0U);/* '<S13>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte12_nu = ((uint8)0U);/* '<S14>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte13_nu = ((uint8)0U);/* '<S15>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte14_nu = ((uint8)0U);/* '<S16>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte15_nu = ((uint8)0U);/* '<S17>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte1_nu = ((uint8)0U);/* '<S18>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte2_nu = ((uint8)0U);/* '<S19>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte3_nu = ((uint8)0U);/* '<S20>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte4_nu = ((uint8)0U);/* '<S21>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte5_nu = ((uint8)0U);/* '<S22>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte6_nu = ((uint8)0U);/* '<S23>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte7_nu = ((uint8)0U);/* '<S24>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte8_nu = ((uint8)0U);/* '<S25>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile uint8 VOPM_BCMHiFreqSigDataByte9_nu = ((uint8)0U);/* '<S26>/MinMax1' */

/* BCM_HFSData_BAC */
MONPRM volatile boolean VOPM_BCMHighBeamSta_flg = false;/* '<S385>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMHvyRainInd_flg = false;/* '<S386>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMHzrdWrngLghtSwSig_flg = false;/* '<S387>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMIllmndEntryStsFb_flg = false;/* '<S388>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMIllmndLampReq_flg = false;/* '<S389>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMIllmndLckStsFb_flg = false;/* '<S223>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_BCMIllmndLockReq_enum = ((uint8)0U);/* '<S390>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMIllmndSts_enum = ((uint8)0U);/* '<S391>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMIllmndUnlckStsFb_flg = false;/* '<S224>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_BCMIndcnKeyClsr_flg = false;/* '<S392>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMIndcnShfttoNeut_flg = false;/* '<S393>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMKeyBattLvlSts_flg = false;/* '<S394>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile float32 VOPM_BCMKeyBattLvl_pct = 0.0F;/* '<S395>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMKeyFrbdn_flg = false;/* '<S396>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMKeyIDFb_enum = ((uint8)0U);/* '<S397>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMKeyInCarSta_flg = false;/* '<S398>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMKeyLoBattLvlWarn_flg = false;/* '<S399>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint16 VOPM_BCMKeyLocn_mm = ((uint16)0U);/* '<S400>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMKeySta_enum = ((uint8)0U);/* '<S401>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMLckHornOnStFb_flg = false;/* '<S402>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMLeTrnLiFltFb_enum = ((uint8)0U);/* '<S403>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMLghtSwSig_enum = ((uint8)0U);/* '<S404>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMLightIntensity_enum = ((uint8)0U);/* '<S405>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMLogoActvFlg_enum = ((uint8)0U);/* '<S406>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMLowBeamSta_flg = false;/* '<S407>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMLrngData02_nu = ((uint8)0U);/* '<S155>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngData03_nu = ((uint8)0U);/* '<S156>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngData04_nu = ((uint8)0U);/* '<S157>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngData05_nu = ((uint8)0U);/* '<S158>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngData06_nu = ((uint8)0U);/* '<S159>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngData07_nu = ((uint8)0U);/* '<S160>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngSts_enum = ((uint8)0U);/* '<S161>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngsubID_cnt = ((uint8)0U);/* '<S162>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMMaiDrvrSeatSts_enum = ((uint8)0U);/* '<S408>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile float32 VOPM_BCMMaiDrvrSeatTemp_C = 0.0F;/* '<S409>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMOvrspdCntrlLckSetFb_flg = false;/* '<S410>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMPSAuthentRes_enum = ((uint8)0U);/* '<S411>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMPSReq_flg = false;/* '<S412>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMParkAutoUnlckSetFb_flg = false;/* '<S413>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMPassWinSwSig_enum = ((uint8)0U);/* '<S414>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMPaswdwInit_flg = false;/* '<S415>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMPosLampSta_flg = false;/* '<S416>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMRFInitSta_flg = false;/* '<S417>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMRKEReq_enum = ((uint8)0U);/* '<S418>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMReverseLampSta_flg = false;/* '<S419>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMRiTrnLiFltFb_enum = ((uint8)0U);/* '<S420>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMRrFogLiSwSig_flg = false;/* '<S421>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMRrMirrHeatSts_flg = false;/* '<S422>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMRrViewMirrHeatgSts_flg = false;/* '<S101>/Switch4' */

/* AC_ACStatuts_BOD */
MONPRM volatile uint8 VOPM_BCMStartReq_enum = ((uint8)0U);/* '<S423>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMSteerWhlHeatSts_flg = false;/* '<S424>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile float32 VOPM_BCMSteerWhlTemp_C = 0.0F;/* '<S425>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMSysPowerSts_enum = ((uint8)0U);/* '<S334>/MinMax1' */

/* CCU_VehInfo_BAC */
MONPRM volatile boolean VOPM_BCMSysPwrModeVld_flg = false;/* '<S335>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMSysPwrMode_enum = ((uint8)0U);/* '<S336>/MinMax1' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMTPMSRstSts_enum = ((uint8)0U);/* '<S426>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMTrnkLckSta_flg = false;/* '<S427>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMTrnkLckSwCtrlFb_flg = false;/* '<S428>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMTrnngLiSwSig_enum = ((uint8)0U);/* '<S429>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMTrunkSwtSig_flg = false;/* '<S430>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMTurnLampStaLeft_flg = false;/* '<S431>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMTurnLampStaRight_flg = false;/* '<S432>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMTurnLiSts_enum = ((uint8)0U);/* '<S433>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMVehSeek_flg = false;/* '<S434>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMWarnKeyOutRmndr_flg = false;/* '<S435>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMWarnNoKeyFound_flg = false;/* '<S436>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMWashLiquidLvlWarn_flg = false;/* '<S437>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMWinLockSig_flg = false;/* '<S438>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMWinLockSts_flg = false;/* '<S439>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMWiperCtrlFront_enum = ((uint8)0U);/* '<S440>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMWiperSwSig_enum = ((uint8)0U);/* '<S441>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMWiprIntlGrSwtSig_enum = ((uint8)0U);/* '<S442>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMWiprIntlTimeSetFb_enum = ((uint8)0U);/* '<S443>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile EnumBMSSdnCmd VOPM_BMSShutdown_enum = EnumBMSSdnCmd_Normal;/* '<S305>/Data Type Conversion2' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile EnumBMSWakeUpMd VOPM_BMSWakeupMode_enum = EnumBMSWakeUpMd_Invld;/* '<S299>/Data Type Conversion2' */

/* VCU_3_OprtCmd_EPT */
MONPRM volatile boolean VOPM_Bat2DrvTrainEnb_flg = false;/* '<S300>/Switch4' */

/* VCU_3_OprtCmd_EPT */
MONPRM volatile boolean VOPM_BraSwi_flg = false;/* '<S202>/Switch4' */

/* VCU_0_Value_EPT */
MONPRM volatile uint8 VOPM_BrkPedSnsrPosVRsrvd_enum = ((uint8)0U);/* '<S265>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_BrkPedalPos_pct = 0.0F;/* '<S266>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_BrkPwrRecupActWhlTq_Nm = 0.0F;/* '<S172>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile uint8 VOPM_BrkPwrRecupActlWhlTqSts_enum = ((uint8)0U);/* '<S173>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_BrkPwrRecupMaxAvlbWhlTq_Nm = 0.0F;/* '<S174>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile uint8 VOPM_CCKeyStgntn_enum = ((uint8)0U);/* '<S225>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_COMPCompInPwrLim_W = 0.0F;/* '<S102>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile uint8 VOPM_COMPEcompEnbl_enum = ((uint8)0U);/* '<S103>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile uint8 VOPM_COMPEcompErrClean_enum = ((uint8)0U);/* '<S104>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile uint8 VOPM_COMPEcompHVSt_enum = ((uint8)0U);/* '<S105>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile float32 VOPM_COMPEcompSpdCtrl_rpm = 0.0F;/* '<S106>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile EnumChrgAllwCmd VOPM_ChrgAllowCmd_enum =
  EnumChrgAllwCmd_NotAllwd;            /* '<S306>/Data Type Conversion2' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile EnumChrgEnaAC VOPM_ChrgEnaAC_enum = EnumChrgEnaAC_Disable;/* '<S301>/Data Type Conversion2' */

/* VCU_3_OprtCmd_EPT */
MONPRM volatile boolean VOPM_ChrgEnaDC_flg = false;/* '<S307>/Switch4' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile float32 VOPM_DCCBoostHvVolt_V = 0.0F;/* '<S317>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
MONPRM volatile float32 VOPM_DCCBuckLVVolt_V = 0.0F;/* '<S318>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
MONPRM volatile EnumDCCOprtCmd VOPM_DCCOprtCmd_enum = EnumDCCOprtCmd_Off;/* '<S313>/Data Type Conversion2' */

/* VCU_B_AcclPedal_EPT */
MONPRM volatile uint8 VOPM_DrvModeKeyStgntn_enum = ((uint8)0U);/* '<S226>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_DrvMotorSta_enum = ((uint8)0U);/* '<S227>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_DrvPed_pct = 0.0F;/* '<S203>/MinMax1' */

/* VCU_0_Value_EPT */
MONPRM volatile boolean VOPM_DrvRangeDistEstVld_flg = false;/* '<S228>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_DrvRangeDistEst_km = 0.0F;/* '<S229>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_DrvReqMotorTorqVld_flg = false;/* '<S175>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_DrvReqMotorTorq_Nm = 0.0F;/* '<S176>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_DrvReqTorqOverrideFCM_flg = false;/* '<S267>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_DrvReqTorqOvrdESC_flg = false;/* '<S268>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_DrvReqWhlTqVld_flg = false;/* '<S177>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_DrvReqWhlTq_Nm = 0.0F;/* '<S178>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_DrvSwi_flg = false;/* '<S204>/Switch4' */

/* VCU_0_Value_EPT */
MONPRM volatile float32 VOPM_DrvWhlTqAllwdMax_Nm = 0.0F;/* '<S179>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile uint64 VOPM_ESCLUnOrLockCrtl_nu = (0ULL);/* '<S113>/MinMax1' */

/* BCM_ESCLCommand_BOD */
MONPRM volatile boolean VOPM_EmgcySdn_flg = false;/* '<S209>/Switch4' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile boolean VOPM_EnaDisChg_flg = false;/* '<S210>/Switch4' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile boolean VOPM_EnaInvRun_flg = false;/* '<S211>/Switch4' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile uint8 VOPM_ErrAmount_cnt = ((uint8)0U);/* '<S314>/MinMax1' */

/* VCU_B_AcclPedal_EPT */
MONPRM volatile uint16 VOPM_ErrBit_nu = ((uint16)0U);/* '<S315>/MinMax1' */

/* VCU_B_AcclPedal_EPT */
MONPRM volatile boolean VOPM_GearShiftInhibited_flg = false;/* '<S269>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_HDCStat_enum = ((uint8)0U);/* '<S337>/MinMax1' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_HVCHEnbld_enum = ((uint8)0U);/* '<S114>/MinMax1' */

/* HVCH_Command_BOD */
MONPRM volatile float32 VOPM_HVCHReqPwr_kW = 0.0F;/* '<S115>/MinMax1' */

/* HVCH_Command_BOD */
MONPRM volatile float32 VOPM_HVCHReqTemp_C = 0.0F;/* '<S116>/MinMax1' */

/* HVCH_Command_BOD */
MONPRM volatile boolean VOPM_IBSWakeup_flg = false;/* '<S147>/Switch4' */

/* VCU_7_DrvRange_BOD */
MONPRM volatile uint8 VOPM_InfoDisp_enum = ((uint8)0U);/* '<S230>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_LimpHomeSta_flg = false;/* '<S338>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile boolean VOPM_MCUHiTempWrning_flg = false;/* '<S231>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_MaxChrgCurntDC_A = 0.0F;/* '<S308>/MinMax1' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile float32 VOPM_MaxChrgVoltDC_V = 0.0F;/* '<S309>/MinMax1' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile float32 VOPM_MaxHVDCCurntAC_A = 0.0F;/* '<S319>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
MONPRM volatile float32 VOPM_MaxHVDCVoltAC_V = 0.0F;/* '<S320>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
MONPRM volatile uint8 VOPM_MotActPwrTyp_enum = ((uint8)0U);/* '<S232>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_MotActPwr_Kw = 0.0F;/* '<S233>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile EnumMotorDirReq VOPM_MotDirReq_enum = EnumMotorDirReq_Stdby;/* '<S212>/Data Type Conversion2' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile float32 VOPM_MotDmpgLmt_Nm = 0.0F;/* '<S205>/MinMax1' */

/* VCU_0_Value_EPT */
MONPRM volatile EnumMotorModeReq VOPM_MotModeReq_enum = EnumMotorModeReq_Stdby;/* '<S213>/Data Type Conversion2' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile float32 VOPM_MotSpdReq_rpm = 0.0F;/* '<S214>/MinMax1' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile float32 VOPM_MotTorqReq_Nm = 0.0F;/* '<S215>/MinMax1' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile boolean VOPM_MotorHiTempWrning_flg = false;/* '<S234>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_MotorOutputCooltTemp_C = 0.0F;/* '<S302>/MinMax1' */

/* VCU_3_OprtCmd_EPT */
MONPRM volatile boolean VOPM_OBCIntDchrgEna_flg = false;/* '<S321>/Switch4' */

/* VCU_C_OprtCmd_EPT */
MONPRM volatile EnumOBCOprtCmd VOPM_OBCOprtCmdToICU_enum =
  EnumOBCOprtCmd_Standby;              /* '<S235>/Data Type Conversion2' */

/* VCU_DispInfo_BAC */
MONPRM volatile EnumOBCOprtCmd VOPM_OBCOprtCmd_enum = EnumOBCOprtCmd_Standby;/* '<S310>/Data Type Conversion2' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile boolean VOPM_OTAModeSts_flg = false;/* '<S270>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_PCUFailSta_flg = false;/* '<S339>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_PGrSwcSt_enum = ((uint8)0U);/* '<S271>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile EnumPTActMd VOPM_PTActlOprtMode_enum = EnumPTActMd_OFF;/* '<S340>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
MONPRM volatile EnumCrpModeAct VOPM_PrstlsStaFb_enum = EnumCrpModeAct_Open;/* '<S341>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_PtReadyEna_enum = ((uint8)0U);/* '<S148>/MinMax1' */

/* VCU_7_DrvRange_BOD */
MONPRM volatile float32 VOPM_PwrRecupActWhlTq_Nm = 0.0F;/* '<S180>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile uint8 VOPM_PwrRecupActlWhlTqSts_enum = ((uint8)0U);/* '<S181>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile EnumRegenModeAct VOPM_PwrRecupIntnsty_enum =
  EnumRegenModeAct_Off;                /* '<S342>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_PwrRecupMaxAvlbMotorTorqSta_enum = ((uint8)0U);/* '<S272>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_PwrRecupMaxAvlbWhlTqSts_enum = ((uint8)0U);/* '<S182>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_RsrvdPwr_kW = 0.0F;/* '<S236>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_SIBSBMSBatSOCAllow_flg = false;/* '<S237>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_SIBSChgNumAllow_flg = false;/* '<S238>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_SIBSFbRTCWupFlg_flg = false;/* '<S239>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_SIBSKL30Volt_V = 0.0F;/* '<S240>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile EnumIBSChrgSt VOPM_SIBSRTCChrgSt_enum = EnumIBSChrgSt_Idle;/* '<S241>/Data Type Conversion2' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_SIBSRTCWUChgFailNum_cnt = ((uint8)0U);/* '<S242>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_SIBSRTCWUChgNum_cnt = ((uint8)0U);/* '<S243>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_SIBSWupVoltAllow_flg = false;/* '<S244>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_ShftKeyStgntn_enum = ((uint8)0U);/* '<S245>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_StrgRecupReqBrkLampOn_flg = false;/* '<S273>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_SysFailSta_enum = ((uint8)0U);/* '<S316>/MinMax1' */

/* VCU_B_AcclPedal_EPT */
MONPRM volatile boolean VOPM_TMPSAbnmPrsrWarn_flg = false;/* '<S444>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile float32 VOPM_TMSACPExhtTmp_C = 0.0F;/* '<S107>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile float32 VOPM_TMSACPInletPres_kPa = 0.0F;/* '<S108>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile uint16 VOPM_TMSAEXVCurrentPstn_cnt = ((uint16)0U);/* '<S132>/MinMax1' */

/* TMS_LINTestData2_BOD */
MONPRM volatile boolean VOPM_TMSAEXVEnblReq_flg = false;/* '<S136>/Switch4' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint16 VOPM_TMSAEXVPstnReq_cnt = ((uint16)0U);/* '<S133>/MinMax1' */

/* TMS_LINTestData2_BOD */
MONPRM volatile float32 VOPM_TMSAcPMPRealRPM_rpm = 0.0F;/* '<S119>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile float32 VOPM_TMSAcPMPSpdSet_rpm = 0.0F;/* '<S120>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile uint16 VOPM_TMSBEXVCurrentPstn_cnt = ((uint16)0U);/* '<S134>/MinMax1' */

/* TMS_LINTestData2_BOD */
MONPRM volatile boolean VOPM_TMSBEXVEnblCmd_flg = false;/* '<S137>/Switch4' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint16 VOPM_TMSBEXVPstnCmd_cnt = ((uint16)0U);/* '<S135>/MinMax1' */

/* TMS_LINTestData2_BOD */
MONPRM volatile float32 VOPM_TMSBatPMPRealRPM_rpm = 0.0F;/* '<S121>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile float32 VOPM_TMSBatPMPSpdSet_rpm = 0.0F;/* '<S122>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile boolean VOPM_TMSBattTempCtrlRmnSwFb_flg = false;/* '<S57>/Switch4' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_TMSC3WVBPosSetReq_enum = ((uint8)0U);/* '<S138>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint8 VOPM_TMSC3WVMode_enum = ((uint8)0U);/* '<S139>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint16 VOPM_TMSC3WVPosRec_enum = ((uint16)0U);/* '<S140>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint8 VOPM_TMSC5WVBPosSetReq_enum = ((uint8)0U);/* '<S141>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint8 VOPM_TMSC5WVMode_enum = ((uint8)0U);/* '<S142>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint16 VOPM_TMSC5WVPosRec_enum = ((uint16)0U);/* '<S143>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile float32 VOPM_TMSChillerOutTmp_C = 0.0F;/* '<S69>/MinMax1' */

/* AC_3_State_BOD */
MONPRM volatile float32 VOPM_TMSEvapOutTmp_C = 0.0F;/* '<S70>/MinMax1' */

/* AC_3_State_BOD */
MONPRM volatile float32 VOPM_TMSEvapTmp_C = 0.0F;/* '<S71>/MinMax1' */

/* AC_3_State_BOD */
MONPRM volatile uint16 VOPM_TMSHPEXVCurrentPstn_cnt = ((uint16)0U);/* '<S144>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile boolean VOPM_TMSHPEXVEnblCmd_flg = false;/* '<S145>/Switch4' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint16 VOPM_TMSHPEXVPstnCmd_cnt = ((uint16)0U);/* '<S123>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile float32 VOPM_TMSMotPMPRealRPM_rpm = 0.0F;/* '<S124>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile float32 VOPM_TMSMotPMPSpdSet_rpm = 0.0F;/* '<S125>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile float32 VOPM_TMSOHXOutTmp_C = 0.0F;/* '<S72>/MinMax1' */

/* AC_3_State_BOD */
MONPRM volatile boolean VOPM_TMSPCUInletCooltTempVld_flg = false;/* '<S149>/Switch4' */

/* VCU_7_DrvRange_BOD */
MONPRM volatile float32 VOPM_TMSPCUInletCooltTemp_C = 0.0F;/* '<S150>/MinMax1' */

/* VCU_7_DrvRange_BOD */
MONPRM volatile float32 VOPM_TMSPTPres_kPa = 0.0F;/* '<S58>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile float32 VOPM_TMSPTTemp_C = 0.0F;/* '<S59>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_TMSPwrCoolFanSpdDuty_pct = ((uint8)0U);/* '<S151>/MinMax1' */

/* VCU_7_DrvRange_BOD */
MONPRM volatile uint8 VOPM_TPMSPressureStaFL_enum = ((uint8)0U);/* '<S445>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_TPMSPressureStaFR_enum = ((uint8)0U);/* '<S446>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_TPMSPressureStaRL_enum = ((uint8)0U);/* '<S447>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_TPMSPressureStaRR_enum = ((uint8)0U);/* '<S448>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_VCUACCStandstillReq_flg = false;/* '<S274>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_VCUAccReqDrvOff_flg = false;/* '<S183>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_VCUAccReqStandstill_flg = false;/* '<S184>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_VCUAccTgtAxReq_flg = false;/* '<S275>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_VCUAccTgtAx_mps2 = 0.0F;/* '<S276>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_VCUBraTorReq_Nm = 0.0F;/* '<S277>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_VCUCruiseCtrTgtSpd_kph = 0.0F;/* '<S278>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile EnumCruiseStatus VOPM_VCUCruiseCtrlSta_enum =
  EnumCruiseStatus_NormOff;            /* '<S279>/Data Type Conversion2' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_VCUEPBApplyForbid_enum = ((uint8)0U);/* '<S280>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_VCUEnaEHBBrkRun_flg = false;/* '<S185>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_VCUMasterCylinderPreReq_Bar = 0.0F;/* '<S186>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_VCUMotTorqueReqToEHB_Nm = 0.0F;/* '<S187>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_VCUParkSwStaVld_flg = false;/* '<S281>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_VCUParkSwSta_flg = false;/* '<S282>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_VCUPreKeReq_flg = false;/* '<S283>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_VCUReqAutoBrk_enum = ((uint8)0U);/* '<S284>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_VCUReqEPBVld_flg = false;/* '<S285>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile EnumEPBReq VOPM_VCUReqEPB_enum = EnumEPBReq_NoCmd;/* '<S286>/Data Type Conversion2' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_VCUVehSpdFastWarn_flg = false;/* '<S188>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile EnumDrvModeAct VOPM_VehActDrvMod1_enum = EnumDrvModeAct_Invalid;/* '<S343>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_VehActDrvPwr_pct = ((uint8)0U);/* '<S246>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_VehActRecupPwr_pct = ((uint8)0U);/* '<S247>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_VehActlGearPosVld_flg = false;/* '<S344>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile EnumGearPstn VOPM_VehActlGearPos_enum = EnumGearPstn_P;/* '<S345>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
MONPRM volatile boolean VOPM_VehPGearError_flg = false;/* '<S248>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_VehPwrCnsmpAvrg_kWh = 0.0F;/* '<S249>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile EnumTgtGearPstn VOPM_VehTrgtGearPos_enum = EnumTgtGearPstn_NoReq;/* '<S216>/Data Type Conversion2' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile float32 VOPM_VhclActlCnsmPwr_kWh = 0.0F;/* '<S250>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_VhclSpdFstWarn_flg = false;/* '<S251>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_WLTPDrvgRngDstVld_flg = false;/* '<S252>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_WLTPDrvgRngDst_km = 0.0F;/* '<S253>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_Zdznswi_flg = false;/* '<S206>/Switch4' */

/* VCU_0_Value_EPT */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
