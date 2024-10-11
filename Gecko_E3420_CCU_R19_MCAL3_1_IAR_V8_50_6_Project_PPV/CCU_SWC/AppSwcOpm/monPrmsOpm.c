/*
 * File: monPrmsOpm.c
 *
 * Code generated for Simulink model 'AppSwcOpm'.
 *
 * Model version                  : 9.95
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Sep 25 10:30:11 2024
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
MONPRM volatile uint8 VOPM_12VBatLowVolSta_enum = ((uint8)0U);/* '<S344>/MinMax1' */

/* CCU_VehInfo_BAC */
MONPRM volatile float32 VOPM_ACActTotPwr_kW = 0.0F;/* '<S48>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_ACActlOprtMode_enum = ((uint8)0U);/* '<S49>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_ACAirInletModeSta_enum = ((uint8)0U);/* '<S91>/MinMax1' */

/* AC_ACStatuts_BOD */
MONPRM volatile uint8 VOPM_ACAutoBlwrModeSta_enum = ((uint8)0U);/* '<S92>/MinMax1' */

/* AC_ACStatuts_BOD */
MONPRM volatile boolean VOPM_ACAutoFb_flg = false;/* '<S93>/Switch4' */

/* AC_ACStatuts_BOD */
MONPRM volatile uint8 VOPM_ACAutoFrntFanSpd_enum = ((uint8)0U);/* '<S78>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile boolean VOPM_ACBatPmpFailSta_flg = false;/* '<S50>/Switch4' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_ACBlwrModeSta_enum = ((uint8)0U);/* '<S94>/MinMax1' */

/* AC_ACStatuts_BOD */
MONPRM volatile boolean VOPM_ACCTrqCtrlAvl_flg = false;/* '<S273>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_ACChrgMaxCurr_A = ((uint8)0U);/* '<S214>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_ACChrgMode_enum = ((uint8)0U);/* '<S215>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_ACCompFailModeOprtSta_flg = false;/* '<S38>/Switch4' */

/* AC_1_Command_BOD */
MONPRM volatile float32 VOPM_ACCompMaxAllowPwrCmsp_kW = 0.0F;/* '<S39>/MinMax1' */

/* AC_1_Command_BOD */
MONPRM volatile boolean VOPM_ACCompOprtEnaCmd_flg = false;/* '<S40>/Switch4' */

/* AC_1_Command_BOD */
MONPRM volatile boolean VOPM_ACCompOprtReq_flg = false;/* '<S41>/Switch4' */

/* AC_1_Command_BOD */
MONPRM volatile float32 VOPM_ACCompTgtSpd_rpm = 0.0F;/* '<S42>/MinMax1' */

/* AC_1_Command_BOD */
MONPRM volatile boolean VOPM_ACEnvirTempVld_flg = false;/* '<S64>/Switch4' */

/* AC_3_State_BOD */
MONPRM volatile float32 VOPM_ACEnvirTemp_C = 0.0F;/* '<S65>/MinMax1' */

/* AC_3_State_BOD */
MONPRM volatile float32 VOPM_ACEvapTgtTemp_C = 0.0F;/* '<S79>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile boolean VOPM_ACExtdDefrstActvReq_flg = false;/* '<S66>/Switch4' */

/* AC_3_State_BOD */
MONPRM volatile boolean VOPM_ACFailSta_flg = false;/* '<S51>/Switch4' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_ACFrntFanSpdVal_enum = ((uint8)0U);/* '<S95>/MinMax1' */

/* AC_ACStatuts_BOD */
MONPRM volatile uint8 VOPM_ACHVHActlOprtMode_enum = ((uint8)0U);/* '<S52>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile float32 VOPM_ACHVHActlPwr_KW = 0.0F;/* '<S53>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile float32 VOPM_ACHVHDevInternTemp_C = 0.0F;/* '<S54>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile boolean VOPM_ACHVHFailSta_flg = false;/* '<S55>/Switch4' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_ACHVPTCOnRq_enum = ((uint8)0U);/* '<S80>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile float32 VOPM_ACHighVolDCTotalPwr_kW = 0.0F;/* '<S43>/MinMax1' */

/* AC_1_Command_BOD */
MONPRM volatile uint8 VOPM_ACHybEcoModeSta_enum = ((uint8)0U);/* '<S96>/MinMax1' */

/* AC_ACStatuts_BOD */
MONPRM volatile float32 VOPM_ACIndoorTemp_C = 0.0F;/* '<S67>/MinMax1' */

/* AC_3_State_BOD */
MONPRM volatile uint8 VOPM_ACLeftTempVal_enum = ((uint8)0U);/* '<S97>/MinMax1' */

/* AC_ACStatuts_BOD */
MONPRM volatile boolean VOPM_ACManlDefrstFb_flg = false;/* '<S98>/Switch4' */

/* AC_ACStatuts_BOD */
MONPRM volatile boolean VOPM_ACPumpActlSpdDutyVld_flg = false;/* '<S44>/Switch4' */

/* AC_1_Command_BOD */
MONPRM volatile uint8 VOPM_ACPumpActlSpdDuty_pct = ((uint8)0U);/* '<S45>/MinMax1' */

/* AC_1_Command_BOD */
MONPRM volatile boolean VOPM_ACPwrFb_flg = false;/* '<S99>/Switch4' */

/* AC_ACStatuts_BOD */
MONPRM volatile boolean VOPM_ACRefrgLoPresVld_flg = false;/* '<S81>/Switch4' */

/* AC_8_status_BOD */
MONPRM volatile float32 VOPM_ACRefrgLoPres_kPa = 0.0F;/* '<S82>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile uint8 VOPM_ACRemtCtrlFb_enum = ((uint8)0U);/* '<S216>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_ACRmtDefrstCtlFb_enum = ((uint8)0U);/* '<S217>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_ACTempSetFb_enum = ((uint8)0U);/* '<S218>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_ACUnlckVentSetFB_enum = ((uint8)0U);/* '<S219>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile EnumAccPedSnsrSt VOPM_AccPedPosSnsrSta_enum =
  EnumAccPedSnsrSt_Invalid;            /* '<S274>/Data Type Conversion2' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_AccPedPosToESCSta_enum = ((uint8)0U);/* '<S275>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_AccPedPosToESC_pct = 0.0F;/* '<S276>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_AcclPedalPos_pct = 0.0F;/* '<S277>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_ActWhlTqVld_flg = false;/* '<S157>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_ActWhlTq_Nm = 0.0F;/* '<S158>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_ActlMotorRotateSpdVld_flg = false;/* '<S159>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_ActlMotorRotateSpd_rpm = 0.0F;/* '<S160>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_ActlMotorTorqVld_flg = false;/* '<S161>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_ActlMotorTorq_Nm = 0.0F;/* '<S162>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_AllowHeatCoolMaxPwrCmsp_kW = 0.0F;/* '<S312>/MinMax1' */

/* VCU_3_OprtCmd_EPT */
MONPRM volatile uint8 VOPM_AppSoftNumb_nu = ((uint8)0U);/* '<S192>/MinMax1' */

/* VCU_0_Value_EPT */
MONPRM volatile boolean VOPM_BCMAjarStaHood_flg = false;/* '<S363>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMAjarStaTrunk_flg = false;/* '<S364>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMAjarStaVHoodVld_flg = false;/* '<S365>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMAlrmHornReq_flg = false;/* '<S366>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMAuthentKeyNr_enum = ((uint8)0U);/* '<S367>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMAutoLampStatus_flg = false;/* '<S368>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMAvaluebleKeyInCar_flg = false;/* '<S369>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMBackLadjvalFb_enum = ((uint8)0U);/* '<S345>/MinMax1' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMBackLiFltFb_enum = ((uint8)0U);/* '<S370>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMBassHornReq_enum = ((uint8)0U);/* '<S371>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMBodyWarnSts_enum = ((uint8)0U);/* '<S372>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMBrakeLampSta_flg = false;/* '<S373>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMBrkLiFltFb_enum = ((uint8)0U);/* '<S374>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMBrkPedSta_flg = false;/* '<S346>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMCenLckSts_enum = ((uint8)0U);/* '<S347>/MinMax1' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMChgWiprMtMdSwSetFb_enum = ((uint8)0U);/* '<S375>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMChrgLidLockReq_enum = ((uint8)0U);/* '<S376>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMDayRunLiFltFb_enum = ((uint8)0U);/* '<S377>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDayRunLiSwSig_flg = false;/* '<S378>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDayRunLightSta_flg = false;/* '<S379>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDoorAjarStaFL_flg = false;/* '<S380>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDoorAjarStaFR_flg = false;/* '<S381>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDoorAjarStaRL_flg = false;/* '<S382>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDoorAjarStaRR_flg = false;/* '<S383>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMDoorLckOpRec_enum = ((uint8)0U);/* '<S384>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMDoorLckStaFL_flg = false;/* '<S348>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMDrvPEAuthentAcsd_enum = ((uint8)0U);/* '<S385>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMDrvPassWinSwSig_enum = ((uint8)0U);/* '<S386>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMDrvSeatOccptSnsrSts_enum = ((uint8)0U);/* '<S387>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMDrvrWinSwSig_enum = ((uint8)0U);/* '<S388>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFLWinSts_flg = false;/* '<S389>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFLWinmotorSts_enum = ((uint8)0U);/* '<S390>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFLWinmotor_flg = false;/* '<S391>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFRPEAuthentAcsd_enum = ((uint8)0U);/* '<S392>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFRWinSts_flg = false;/* '<S393>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFRWinmotorSts_enum = ((uint8)0U);/* '<S394>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFRWinmotor_flg = false;/* '<S395>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFlwrMeHmCtrlFb_enum = ((uint8)0U);/* '<S396>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFogLampStaFront_flg = false;/* '<S397>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFogLampStaRear_flg = false;/* '<S398>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFrbdnKeyNr_enum = ((uint8)0U);/* '<S399>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFrntFogLiFltFb_enum = ((uint8)0U);/* '<S400>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFrntFogLiSwSig_flg = false;/* '<S401>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFrntLeDoorHndlSwt_enum = ((uint8)0U);/* '<S402>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFrntRiDoorHndlSwt_enum = ((uint8)0U);/* '<S403>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMFrntWiprMotSts_enum = ((uint8)0U);/* '<S404>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFrntWshrSwSig_flg = false;/* '<S405>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMFrontWashSts_flg = false;/* '<S406>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMHazardLampSts_flg = false;/* '<S349>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMHiBeamLiFltFb_enum = ((uint8)0U);/* '<S407>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMHiBeamSwSig_enum = ((uint8)0U);/* '<S408>/MinMax1' */

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
MONPRM volatile boolean VOPM_BCMHighBeamSta_flg = false;/* '<S409>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMHvyRainInd_flg = false;/* '<S410>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMHzrdWrngLghtSwSig_flg = false;/* '<S411>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMIllmndEntryStsFb_flg = false;/* '<S412>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMIllmndLampReq_flg = false;/* '<S413>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMIllmndLckStsFb_flg = false;/* '<S220>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_BCMIllmndLockReq_enum = ((uint8)0U);/* '<S414>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMIllmndSts_enum = ((uint8)0U);/* '<S415>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMIllmndUnlckStsFb_flg = false;/* '<S221>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_BCMIndcnKeyClsr_flg = false;/* '<S416>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMIndcnShfttoNeut_flg = false;/* '<S417>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMKeyBattLvlSts_flg = false;/* '<S418>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile float32 VOPM_BCMKeyBattLvl_pct = 0.0F;/* '<S419>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMKeyFrbdn_flg = false;/* '<S420>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMKeyIDFb_enum = ((uint8)0U);/* '<S421>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMKeyInCarSta_flg = false;/* '<S422>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMKeyLoBattLvlWarn_flg = false;/* '<S423>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint16 VOPM_BCMKeyLocn_mm = ((uint16)0U);/* '<S424>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMKeySta_enum = ((uint8)0U);/* '<S425>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMLFInitSta_flg = false;/* '<S426>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMLckHornOnStFb_flg = false;/* '<S427>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMLeTrnLiFltFb_enum = ((uint8)0U);/* '<S428>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMLghtSwSig_enum = ((uint8)0U);/* '<S429>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMLightIntensity_enum = ((uint8)0U);/* '<S430>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMLoBeamLiFltFb_enum = ((uint8)0U);/* '<S431>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMLogoActvFlg_enum = ((uint8)0U);/* '<S432>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMLowBeamSta_flg = false;/* '<S433>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMLrngData02_nu = ((uint8)0U);/* '<S146>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngData03_nu = ((uint8)0U);/* '<S147>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngData04_nu = ((uint8)0U);/* '<S148>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngData05_nu = ((uint8)0U);/* '<S149>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngData06_nu = ((uint8)0U);/* '<S150>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngData07_nu = ((uint8)0U);/* '<S151>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngSts_enum = ((uint8)0U);/* '<S152>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMLrngsubID_cnt = ((uint8)0U);/* '<S153>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
MONPRM volatile uint8 VOPM_BCMMaiDrvrSeatSts_enum = ((uint8)0U);/* '<S434>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile float32 VOPM_BCMMaiDrvrSeatTemp_C = 0.0F;/* '<S435>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMOvrspdCntrlLckSetFb_flg = false;/* '<S436>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMPSAuthentRes_enum = ((uint8)0U);/* '<S437>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMPSReq_flg = false;/* '<S438>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMParkAutoUnlckSetFb_flg = false;/* '<S439>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMPassWinSwSig_enum = ((uint8)0U);/* '<S440>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMPaswdwInit_flg = false;/* '<S441>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMPosLampSta_flg = false;/* '<S350>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMPosLiFltFb_enum = ((uint8)0U);/* '<S442>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMRFInitSta_flg = false;/* '<S443>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMRKEReq_enum = ((uint8)0U);/* '<S444>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMReverseLampSta_flg = false;/* '<S445>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMRiTrnLiFltFb_enum = ((uint8)0U);/* '<S446>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMRrFogLiFltFb_enum = ((uint8)0U);/* '<S447>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMRrFogLiSwSig_flg = false;/* '<S448>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMRrMirrHeatSts_flg = false;/* '<S449>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMRrViewMirrHeatgSts_flg = false;/* '<S100>/Switch4' */

/* AC_ACStatuts_BOD */
MONPRM volatile uint8 VOPM_BCMRvrsLiFltFb_enum = ((uint8)0U);/* '<S450>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMStartReq_enum = ((uint8)0U);/* '<S451>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMSteerWhlHeatSts_flg = false;/* '<S452>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile float32 VOPM_BCMSteerWhlTemp_C = 0.0F;/* '<S453>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMSysPowerSts_enum = ((uint8)0U);/* '<S351>/MinMax1' */

/* CCU_VehInfo_BAC */
MONPRM volatile boolean VOPM_BCMSysPwrModeVld_flg = false;/* '<S352>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMSysPwrMode_enum = ((uint8)0U);/* '<S353>/MinMax1' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_BCMTPMSRstSts_enum = ((uint8)0U);/* '<S454>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMTrnkLckSta_flg = false;/* '<S455>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMTrnkLckSwCtrlFb_flg = false;/* '<S456>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMTrnngLiSwSig_enum = ((uint8)0U);/* '<S457>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMTrunkSwtSig_flg = false;/* '<S458>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMTurnLampStaLeft_flg = false;/* '<S459>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMTurnLampStaRight_flg = false;/* '<S460>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMTurnLiSts_enum = ((uint8)0U);/* '<S461>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMVehSeek_flg = false;/* '<S462>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMWarnKeyOutRmndr_flg = false;/* '<S463>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMWarnNoKeyFound_flg = false;/* '<S464>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMWashLiquidLvlWarn_flg = false;/* '<S465>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMWinLockSig_flg = false;/* '<S466>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_BCMWinLockSts_flg = false;/* '<S467>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMWiperCtrlFront_enum = ((uint8)0U);/* '<S468>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMWiperSwSig_enum = ((uint8)0U);/* '<S469>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMWiprIntlGrSwtSig_enum = ((uint8)0U);/* '<S470>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_BCMWiprIntlTimeSetFb_enum = ((uint8)0U);/* '<S471>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile EnumBMSSdnCmd VOPM_BMSShutdown_enum = EnumBMSSdnCmd_Normal;/* '<S319>/Data Type Conversion2' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile EnumBMSWakeUpMd VOPM_BMSWakeupMode_enum = EnumBMSWakeUpMd_Invld;/* '<S313>/Data Type Conversion2' */

/* VCU_3_OprtCmd_EPT */
MONPRM volatile boolean VOPM_Bat2DrvTrainEnb_flg = false;/* '<S314>/Switch4' */

/* VCU_3_OprtCmd_EPT */
MONPRM volatile boolean VOPM_BraSwi_flg = false;/* '<S193>/Switch4' */

/* VCU_0_Value_EPT */
MONPRM volatile uint8 VOPM_BrkPedSnsrPosVRsrvd_enum = ((uint8)0U);/* '<S278>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_BrkPedalPos_pct = 0.0F;/* '<S279>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_BrkPwrRecupActWhlTq_Nm = 0.0F;/* '<S163>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile uint8 VOPM_BrkPwrRecupActlWhlTqSts_enum = ((uint8)0U);/* '<S164>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_BrkPwrRecupMaxAvlbWhlTq_Nm = 0.0F;/* '<S165>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile uint8 VOPM_CCKeyStgntn_enum = ((uint8)0U);/* '<S222>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_CCUOpenVentnFb_enum = ((uint8)0U);/* '<S223>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_CCURmtCarSearchFb_enum = ((uint8)0U);/* '<S224>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_CCURmtLckFb_enum = ((uint8)0U);/* '<S225>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_CCURmtPwrLckFb_enum = ((uint8)0U);/* '<S226>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_COMPCompInPwrLim_W = 0.0F;/* '<S101>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile uint8 VOPM_COMPEcompEnbl_enum = ((uint8)0U);/* '<S102>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile uint8 VOPM_COMPEcompErrClean_enum = ((uint8)0U);/* '<S103>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile uint8 VOPM_COMPEcompHVSt_enum = ((uint8)0U);/* '<S104>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile float32 VOPM_COMPEcompSpdCtrl_rpm = 0.0F;/* '<S105>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile EnumChrgAllwCmd VOPM_ChrgAllowCmd_enum =
  EnumChrgAllwCmd_NotAllwd;            /* '<S320>/Data Type Conversion2' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile EnumChrgEnaAC VOPM_ChrgEnaAC_enum = EnumChrgEnaAC_Disable;/* '<S315>/Data Type Conversion2' */

/* VCU_3_OprtCmd_EPT */
MONPRM volatile boolean VOPM_ChrgEnaDC_flg = false;/* '<S321>/Switch4' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile float32 VOPM_CruiseCtrTgtSpd_kph = 0.0F;/* '<S227>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_CruiseCtrlSta_enum = ((uint8)0U);/* '<S228>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_DCCBoostHvVolt_V = 0.0F;/* '<S332>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
MONPRM volatile float32 VOPM_DCCBuckLVVolt_V = 0.0F;/* '<S333>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
MONPRM volatile EnumDCCOprtCmd VOPM_DCCOprtCmd_enum = EnumDCCOprtCmd_Off;/* '<S328>/Data Type Conversion2' */

/* VCU_B_AcclPedal_EPT */
MONPRM volatile uint8 VOPM_DrvLfAntDiagStat_enum = ((uint8)0U);/* '<S472>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_DrvModeKeyStgntn_enum = ((uint8)0U);/* '<S229>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_DrvMotorSta_enum = ((uint8)0U);/* '<S230>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_DrvPed_pct = 0.0F;/* '<S194>/MinMax1' */

/* VCU_0_Value_EPT */
MONPRM volatile boolean VOPM_DrvRangeDistEstVld_flg = false;/* '<S231>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_DrvRangeDistEst_km = 0.0F;/* '<S232>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_DrvReqMotorTorqVld_flg = false;/* '<S166>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_DrvReqMotorTorq_Nm = 0.0F;/* '<S167>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_DrvReqTorqOverrideFCM_flg = false;/* '<S280>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_DrvReqTorqOvrdESC_flg = false;/* '<S281>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_DrvReqWhlTqVld_flg = false;/* '<S168>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_DrvReqWhlTq_Nm = 0.0F;/* '<S169>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_DrvSwi_flg = false;/* '<S195>/Switch4' */

/* VCU_0_Value_EPT */
MONPRM volatile float32 VOPM_DrvWhlTqAllwdMax_Nm = 0.0F;/* '<S170>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile uint64 VOPM_ESCLUnOrLockCrtl_nu = (0ULL);/* '<S112>/MinMax1' */

/* BCM_ESCLCommand_BOD */
MONPRM volatile boolean VOPM_EmgcySdn_flg = false;/* '<S200>/Switch4' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile boolean VOPM_EnaDisChg_flg = false;/* '<S201>/Switch4' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile boolean VOPM_EnaInvRun_flg = false;/* '<S202>/Switch4' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile uint8 VOPM_ErrAmount_cnt = ((uint8)0U);/* '<S329>/MinMax1' */

/* VCU_B_AcclPedal_EPT */
MONPRM volatile uint16 VOPM_ErrBit_nu = ((uint16)0U);/* '<S330>/MinMax1' */

/* VCU_B_AcclPedal_EPT */
MONPRM volatile boolean VOPM_GearShiftInhibited_flg = false;/* '<S282>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_HDCStat_enum = ((uint8)0U);/* '<S354>/MinMax1' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_HVCHEnbld_enum = ((uint8)0U);/* '<S113>/MinMax1' */

/* HVCH_Command_BOD */
MONPRM volatile float32 VOPM_HVCHReqPwr_kW = 0.0F;/* '<S114>/MinMax1' */

/* HVCH_Command_BOD */
MONPRM volatile float32 VOPM_HVCHReqTemp_C = 0.0F;/* '<S115>/MinMax1' */

/* HVCH_Command_BOD */
MONPRM volatile uint8 VOPM_InfoDisp_enum = ((uint8)0U);/* '<S233>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_IntLfAntDiagStat_enum = ((uint8)0U);/* '<S473>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_LckVehWrm_enum = ((uint8)0U);/* '<S234>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_LimpHomeSta_flg = false;/* '<S355>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile boolean VOPM_MCUHiTempWrning_flg = false;/* '<S235>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_MaxChrgCurntAC_A = ((uint8)0U);/* '<S322>/MinMax1' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile float32 VOPM_MaxChrgCurntDC_A = 0.0F;/* '<S323>/MinMax1' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile float32 VOPM_MaxChrgVoltDC_V = 0.0F;/* '<S324>/MinMax1' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile float32 VOPM_MaxHVDCCurntAC_A = 0.0F;/* '<S334>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
MONPRM volatile float32 VOPM_MaxHVDCVoltAC_V = 0.0F;/* '<S335>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
MONPRM volatile uint8 VOPM_MotActPwrTyp_enum = ((uint8)0U);/* '<S236>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_MotActPwr_Kw = 0.0F;/* '<S237>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile EnumMotorDirReq VOPM_MotDirReq_enum = EnumMotorDirReq_Stdby;/* '<S203>/Data Type Conversion2' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile float32 VOPM_MotDmpgLmt_Nm = 0.0F;/* '<S196>/MinMax1' */

/* VCU_0_Value_EPT */
MONPRM volatile EnumMotorModeReq VOPM_MotModeReq_enum = EnumMotorModeReq_Stdby;/* '<S204>/Data Type Conversion2' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile float32 VOPM_MotSpdReq_rpm = 0.0F;/* '<S205>/MinMax1' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile float32 VOPM_MotTorqReq_Nm = 0.0F;/* '<S206>/MinMax1' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile boolean VOPM_MotorHiTempWrning_flg = false;/* '<S238>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_MotorOutputCooltTemp_C = 0.0F;/* '<S316>/MinMax1' */

/* VCU_3_OprtCmd_EPT */
MONPRM volatile boolean VOPM_OBCIntDchrgEna_flg = false;/* '<S336>/Switch4' */

/* VCU_C_OprtCmd_EPT */
MONPRM volatile EnumOBCOprtCmd VOPM_OBCOprtCmdToICU_enum =
  EnumOBCOprtCmd_Standby;              /* '<S239>/Data Type Conversion2' */

/* VCU_DispInfo_BAC */
MONPRM volatile EnumOBCOprtCmd VOPM_OBCOprtCmd_enum = EnumOBCOprtCmd_Standby;/* '<S325>/Data Type Conversion2' */

/* VCU_4_ChrgCmd_EPT */
MONPRM volatile boolean VOPM_OTAModeSts_flg = false;/* '<S283>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_PCUFailSta_flg = false;/* '<S356>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_PGrSwcSt_enum = ((uint8)0U);/* '<S284>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile EnumPTActMd VOPM_PTActlOprtMode_enum = EnumPTActMd_OFF;/* '<S357>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_PassLfAntDiagStat_enum = ((uint8)0U);/* '<S474>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile EnumCrpModeAct VOPM_PrstlsStaFb_enum = EnumCrpModeAct_Open;/* '<S358>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
MONPRM volatile float32 VOPM_PwrRecupActWhlTq_Nm = 0.0F;/* '<S171>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile uint8 VOPM_PwrRecupActlWhlTqSts_enum = ((uint8)0U);/* '<S172>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile EnumRegenModeAct VOPM_PwrRecupIntnsty_enum =
  EnumRegenModeAct_Off;                /* '<S359>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_PwrRecupMaxAvlbMotorTorqSta_enum = ((uint8)0U);/* '<S285>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_PwrRecupMaxAvlbWhlTqSts_enum = ((uint8)0U);/* '<S173>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_RsrvdPwr_kW = 0.0F;/* '<S240>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_SIBSBMSBatSOCAllow_flg = false;/* '<S241>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_SIBSChgNumAllow_flg = false;/* '<S242>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_SIBSFbRTCWupFlg_flg = false;/* '<S243>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_SIBSKL30Volt_V = 0.0F;/* '<S244>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile EnumIBSChrgSt VOPM_SIBSRTCChrgSt_enum = EnumIBSChrgSt_Idle;/* '<S245>/Data Type Conversion2' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_SIBSRTCWUChgFailNum_cnt = ((uint8)0U);/* '<S246>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_SIBSRTCWUChgNum_cnt = ((uint8)0U);/* '<S247>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_SIBSWupVoltAllow_flg = false;/* '<S248>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_ShftKeyStgntn_enum = ((uint8)0U);/* '<S249>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_StrgRecupReqBrkLampOn_flg = false;/* '<S286>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_SysFailSta_enum = ((uint8)0U);/* '<S331>/MinMax1' */

/* VCU_B_AcclPedal_EPT */
MONPRM volatile boolean VOPM_TMPSAbnmPrsrWarn_flg = false;/* '<S475>/Switch4' */

/* BCM_B_Package_BAC */
MONPRM volatile float32 VOPM_TMSACPExhtTmp_C = 0.0F;/* '<S106>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile float32 VOPM_TMSACPInletPres_kPa = 0.0F;/* '<S107>/MinMax1' */

/* AC_COMP_BOD */
MONPRM volatile uint16 VOPM_TMSAEXVCurrentPstn_cnt = ((uint16)0U);/* '<S131>/MinMax1' */

/* TMS_LINTestData2_BOD */
MONPRM volatile boolean VOPM_TMSAEXVEnblReq_flg = false;/* '<S135>/Switch4' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint16 VOPM_TMSAEXVPstnReq_cnt = ((uint16)0U);/* '<S132>/MinMax1' */

/* TMS_LINTestData2_BOD */
MONPRM volatile float32 VOPM_TMSAcPMPRealRPM_rpm = 0.0F;/* '<S118>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile float32 VOPM_TMSAcPMPSpdSet_rpm = 0.0F;/* '<S119>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile uint8 VOPM_TMSBATThermMod_enum = ((uint8)0U);/* '<S83>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile uint16 VOPM_TMSBEXVCurrentPstn_cnt = ((uint16)0U);/* '<S133>/MinMax1' */

/* TMS_LINTestData2_BOD */
MONPRM volatile boolean VOPM_TMSBEXVEnblCmd_flg = false;/* '<S136>/Switch4' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint16 VOPM_TMSBEXVPstnCmd_cnt = ((uint16)0U);/* '<S134>/MinMax1' */

/* TMS_LINTestData2_BOD */
MONPRM volatile float32 VOPM_TMSBatPMPRealRPM_rpm = 0.0F;/* '<S120>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile float32 VOPM_TMSBatPMPSpdSet_rpm = 0.0F;/* '<S121>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile boolean VOPM_TMSBattTempCtrlRmnSwFb_flg = false;/* '<S56>/Switch4' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_TMSC3WVBPosSetReq_enum = ((uint8)0U);/* '<S137>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint8 VOPM_TMSC3WVMode_enum = ((uint8)0U);/* '<S138>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint16 VOPM_TMSC3WVPosRec_enum = ((uint16)0U);/* '<S139>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint8 VOPM_TMSC5WVBPosSetReq_enum = ((uint8)0U);/* '<S140>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint8 VOPM_TMSC5WVMode_enum = ((uint8)0U);/* '<S141>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint16 VOPM_TMSC5WVPosRec_enum = ((uint16)0U);/* '<S142>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint8 VOPM_TMSCabThermMod_enum = ((uint8)0U);/* '<S84>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile float32 VOPM_TMSChillerOutTmp_C = 0.0F;/* '<S68>/MinMax1' */

/* AC_3_State_BOD */
MONPRM volatile float32 VOPM_TMSEvapOutTmp_C = 0.0F;/* '<S69>/MinMax1' */

/* AC_3_State_BOD */
MONPRM volatile float32 VOPM_TMSEvapTmp_C = 0.0F;/* '<S70>/MinMax1' */

/* AC_3_State_BOD */
MONPRM volatile uint16 VOPM_TMSHPEXVCurrentPstn_cnt = ((uint16)0U);/* '<S143>/MinMax1' */

/* TMS_LINTestData3_BOD */
MONPRM volatile boolean VOPM_TMSHPEXVEnblCmd_flg = false;/* '<S144>/Switch4' */

/* TMS_LINTestData3_BOD */
MONPRM volatile uint16 VOPM_TMSHPEXVPstnCmd_cnt = ((uint16)0U);/* '<S122>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile float32 VOPM_TMSMotInletCooltTemp_C = 0.0F;/* '<S85>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile float32 VOPM_TMSMotPMPRealRPM_rpm = 0.0F;/* '<S123>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile float32 VOPM_TMSMotPMPSpdSet_rpm = 0.0F;/* '<S124>/MinMax1' */

/* TMS_LINTestData1_BOD */
MONPRM volatile float32 VOPM_TMSOHXOutTmp_C = 0.0F;/* '<S71>/MinMax1' */

/* AC_3_State_BOD */
MONPRM volatile float32 VOPM_TMSPTPres_kPa = 0.0F;/* '<S57>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile float32 VOPM_TMSPTTemp_C = 0.0F;/* '<S58>/MinMax1' */

/* AC_2_State_BOD */
MONPRM volatile uint8 VOPM_TMSPwrCoolFanSpdDuty_pct = ((uint8)0U);/* '<S86>/MinMax1' */

/* AC_8_status_BOD */
MONPRM volatile uint8 VOPM_TPMSPressureStaFL_enum = ((uint8)0U);/* '<S476>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_TPMSPressureStaFR_enum = ((uint8)0U);/* '<S477>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_TPMSPressureStaRL_enum = ((uint8)0U);/* '<S478>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile uint8 VOPM_TPMSPressureStaRR_enum = ((uint8)0U);/* '<S479>/MinMax1' */

/* BCM_B_Package_BAC */
MONPRM volatile boolean VOPM_VCUACCStandstillReq_flg = false;/* '<S287>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_VCUACCStat_enum = ((uint8)0U);/* '<S288>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_VCUAccReqDrvOff_flg = false;/* '<S174>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_VCUAccReqStandstill_flg = false;/* '<S175>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_VCUAccTgtAxReq_flg = false;/* '<S289>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_VCUAccTgtAx_mps2 = 0.0F;/* '<S290>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_VCUBraTorReq_Nm = 0.0F;/* '<S291>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile float32 VOPM_VCUCruiseCtrTgtSpd_kph = 0.0F;/* '<S292>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile EnumCruiseStatus VOPM_VCUCruiseCtrlSta_enum =
  EnumCruiseStatus_NormOff;            /* '<S293>/Data Type Conversion2' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_VCUEPBApplyForbid_enum = ((uint8)0U);/* '<S294>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_VCUEnaEHBBrkRun_flg = false;/* '<S176>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_VCUMasterCylinderPreReq_Bar = 0.0F;/* '<S177>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile float32 VOPM_VCUMotTorqueReqToEHB_Nm = 0.0F;/* '<S178>/MinMax1' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_VCUOprtLicFb_flg = false;/* '<S250>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_VCUParkSwStaVld_flg = false;/* '<S295>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_VCUParkSwSta_flg = false;/* '<S296>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_VCUPreKeReq_flg = false;/* '<S297>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_VCUReqAutoBrk_enum = ((uint8)0U);/* '<S298>/MinMax1' */

/* VCU_D_Status_CHA */
MONPRM volatile boolean VOPM_VCUReqEPBVld_flg = false;/* '<S299>/Switch4' */

/* VCU_D_Status_CHA */
MONPRM volatile EnumEPBReq VOPM_VCUReqEPB_enum = EnumEPBReq_NoCmd;/* '<S300>/Data Type Conversion2' */

/* VCU_D_Status_CHA */
MONPRM volatile uint8 VOPM_VCUSpdLimLvlFb_enum = ((uint8)0U);/* '<S251>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_VCUSpdLimLvlSetFb_enum = ((uint8)0U);/* '<S252>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_VCUVehSpdFastWarn_flg = false;/* '<S179>/Switch4' */

/* VCU_10_Torque_CHA */
MONPRM volatile boolean VOPM_VCUVerFb_flg = false;/* '<S253>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_VCUVerSetFb_enum = ((uint8)0U);/* '<S254>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile EnumDrvModeAct VOPM_VehActDrvMod1_enum = EnumDrvModeAct_Invalid;/* '<S360>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
MONPRM volatile uint8 VOPM_VehActDrvPwr_pct = ((uint8)0U);/* '<S255>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_VehActRecupPwr_pct = ((uint8)0U);/* '<S256>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_VehActlGearPosVld_flg = false;/* '<S361>/Switch4' */

/* CCU_VehInfo_BAC */
MONPRM volatile EnumGearPstn VOPM_VehActlGearPos_enum = EnumGearPstn_P;/* '<S362>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
MONPRM volatile boolean VOPM_VehPGearError_flg = false;/* '<S257>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_VehPwrCnsmpAvrg_kWh = 0.0F;/* '<S258>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile EnumTgtGearPstn VOPM_VehTrgtGearPos_enum = EnumTgtGearPstn_NoReq;/* '<S207>/Data Type Conversion2' */

/* VCU_1_InvCmd_EPT */
MONPRM volatile float32 VOPM_VhclActlCnsmPwr_kWh = 0.0F;/* '<S259>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_VhclSpdFstWarn_flg = false;/* '<S260>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_WLTPDrvgRngDstVld_flg = false;/* '<S261>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_WLTPDrvgRngDst_km = 0.0F;/* '<S262>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_WghConfdence_flg = false;/* '<S263>/Switch4' */

/* VCU_DispInfo_BAC */
MONPRM volatile uint8 VOPM_WghDistb_enum = ((uint8)0U);/* '<S264>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile float32 VOPM_WghEst_kg = 0.0F;/* '<S265>/MinMax1' */

/* VCU_DispInfo_BAC */
MONPRM volatile boolean VOPM_Zdznswi_flg = false;/* '<S197>/Switch4' */

/* VCU_0_Value_EPT */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
