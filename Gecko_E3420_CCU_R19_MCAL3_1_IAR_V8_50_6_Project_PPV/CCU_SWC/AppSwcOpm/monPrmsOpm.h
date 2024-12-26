/*
 * File: monPrmsOpm.h
 *
 * Code generated for Simulink model 'AppSwcOpm'.
 *
 * Model version                  : 9.103
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Dec 17 18:02:01 2024
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
extern MONPRM volatile uint8 VOPM_12VBatLowVolSta_enum;/* '<S350>/MinMax1' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile float32 VOPM_ACActTotPwr_kW;/* '<S48>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_ACActlOprtMode_enum;/* '<S49>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_ACAirInletModeSta_enum;/* '<S91>/MinMax1' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile uint8 VOPM_ACAutoBlwrModeSta_enum;/* '<S92>/MinMax1' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile boolean VOPM_ACAutoFb_flg;/* '<S93>/Switch4' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile uint8 VOPM_ACAutoFrntFanSpd_enum;/* '<S78>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile boolean VOPM_ACBatPmpFailSta_flg;/* '<S50>/Switch4' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_ACBlwrModeSta_enum;/* '<S94>/MinMax1' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile boolean VOPM_ACCTrqCtrlAvl_flg;/* '<S279>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_ACChrgMaxCurr_A;/* '<S213>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_ACChrgMode_enum;/* '<S214>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_ACCompFailModeOprtSta_flg;/* '<S38>/Switch4' */

/* AC_1_Command_BOD */
extern MONPRM volatile float32 VOPM_ACCompMaxAllowPwrCmsp_kW;/* '<S39>/MinMax1' */

/* AC_1_Command_BOD */
extern MONPRM volatile boolean VOPM_ACCompOprtEnaCmd_flg;/* '<S40>/Switch4' */

/* AC_1_Command_BOD */
extern MONPRM volatile boolean VOPM_ACCompOprtReq_flg;/* '<S41>/Switch4' */

/* AC_1_Command_BOD */
extern MONPRM volatile float32 VOPM_ACCompTgtSpd_rpm;/* '<S42>/MinMax1' */

/* AC_1_Command_BOD */
extern MONPRM volatile boolean VOPM_ACEnvirTempVld_flg;/* '<S64>/Switch4' */

/* AC_3_State_BOD */
extern MONPRM volatile float32 VOPM_ACEnvirTemp_C;/* '<S65>/MinMax1' */

/* AC_3_State_BOD */
extern MONPRM volatile float32 VOPM_ACEvapTgtTemp_C;/* '<S79>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile boolean VOPM_ACExtdDefrstActvReq_flg;/* '<S66>/Switch4' */

/* AC_3_State_BOD */
extern MONPRM volatile boolean VOPM_ACFailSta_flg;/* '<S51>/Switch4' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_ACFrntFanSpdVal_enum;/* '<S95>/MinMax1' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile uint8 VOPM_ACHVHActlOprtMode_enum;/* '<S52>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile float32 VOPM_ACHVHActlPwr_KW;/* '<S53>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile float32 VOPM_ACHVHDevInternTemp_C;/* '<S54>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile boolean VOPM_ACHVHFailSta_flg;/* '<S55>/Switch4' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_ACHVPTCOnRq_enum;/* '<S80>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile float32 VOPM_ACHighVolDCTotalPwr_kW;/* '<S43>/MinMax1' */

/* AC_1_Command_BOD */
extern MONPRM volatile uint8 VOPM_ACHybEcoModeSta_enum;/* '<S96>/MinMax1' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile float32 VOPM_ACIndoorTemp_C;/* '<S67>/MinMax1' */

/* AC_3_State_BOD */
extern MONPRM volatile uint8 VOPM_ACLeftTempVal_enum;/* '<S97>/MinMax1' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile boolean VOPM_ACManlDefrstFb_flg;/* '<S98>/Switch4' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile boolean VOPM_ACPumpActlSpdDutyVld_flg;/* '<S44>/Switch4' */

/* AC_1_Command_BOD */
extern MONPRM volatile uint8 VOPM_ACPumpActlSpdDuty_pct;/* '<S45>/MinMax1' */

/* AC_1_Command_BOD */
extern MONPRM volatile boolean VOPM_ACPwrFb_flg;/* '<S99>/Switch4' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile boolean VOPM_ACRefrgLoPresVld_flg;/* '<S81>/Switch4' */

/* AC_8_status_BOD */
extern MONPRM volatile float32 VOPM_ACRefrgLoPres_kPa;/* '<S82>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile uint8 VOPM_ACRemtCtrlFb_enum;/* '<S215>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_ACRmtDefrstCtlFb_enum;/* '<S216>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_ACTempSetFb_enum;/* '<S217>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_ACUnlckVentSetFB_enum;/* '<S218>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile EnumAccPedSnsrSt VOPM_AccPedPosSnsrSta_enum;/* '<S280>/Data Type Conversion2' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_AccPedPosToESCSta_enum;/* '<S281>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_AccPedPosToESC_pct;/* '<S282>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_AcclPedalPos_pct;/* '<S283>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_ActWhlTqVld_flg;/* '<S157>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_ActWhlTq_Nm;/* '<S158>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_ActlMotorRotateSpdVld_flg;/* '<S159>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_ActlMotorRotateSpd_rpm;/* '<S160>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_ActlMotorTorqVld_flg;/* '<S161>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_ActlMotorTorq_Nm;/* '<S162>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_AllowHeatCoolMaxPwrCmsp_kW;/* '<S318>/MinMax1' */

/* VCU_3_OprtCmd_EPT */
extern MONPRM volatile uint8 VOPM_AppSoftNumb_nu;/* '<S191>/MinMax1' */

/* VCU_0_Value_EPT */
extern MONPRM volatile boolean VOPM_BCMAjarStaHood_flg;/* '<S369>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMAjarStaTrunk_flg;/* '<S370>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMAjarStaVHoodVld_flg;/* '<S371>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMAlrmHornReq_flg;/* '<S372>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMAuthentKeyNr_enum;/* '<S373>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMAutoLampStatus_flg;/* '<S374>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMAvaluebleKeyInCar_flg;/* '<S375>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMBackLadjvalFb_enum;/* '<S351>/MinMax1' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile boolean VOPM_BCMBackLampSt_flg;/* '<S376>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMBackLiFltFb_enum;/* '<S377>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMBassHornReq_enum;/* '<S378>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMBodyWarnSts_enum;/* '<S379>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMBrakeLampSta_flg;/* '<S380>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMBrkLiFltFb_enum;/* '<S381>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMBrkPedSta_flg;/* '<S352>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile boolean VOPM_BCMCarrgLghtSt_flg;/* '<S382>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMCenLckSts_enum;/* '<S353>/MinMax1' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMChgWiprMtMdSwSetFb_enum;/* '<S383>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMChrgLidLockReq_enum;/* '<S384>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMDayRunLiFltFb_enum;/* '<S385>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDayRunLiSwSig_flg;/* '<S386>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDayRunLightSta_flg;/* '<S387>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDomeLghtSt_flg;/* '<S388>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDoorAjarStaFL_flg;/* '<S389>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDoorAjarStaFR_flg;/* '<S390>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDoorAjarStaRL_flg;/* '<S391>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDoorAjarStaRR_flg;/* '<S392>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMDoorLckOpRec_enum;/* '<S393>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMDoorLckStaFL_flg;/* '<S354>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMDrvPEAuthentAcsd_enum;/* '<S394>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMDrvPassWinSwSig_enum;/* '<S395>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMDrvSeatOccptSnsrSts_enum;/* '<S396>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMDrvrWinSwSig_enum;/* '<S397>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFLWinSts_flg;/* '<S398>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFLWinmotorSts_enum;/* '<S399>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFLWinmotor_flg;/* '<S400>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFRPEAuthentAcsd_enum;/* '<S401>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFRWinSts_flg;/* '<S402>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFRWinmotorSts_enum;/* '<S403>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFRWinmotor_flg;/* '<S404>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFlwrMeHmCtrlFb_enum;/* '<S405>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFogLampStaFront_flg;/* '<S406>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFogLampStaRear_flg;/* '<S407>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFrbdnKeyNr_enum;/* '<S408>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFrntFogLiFltFb_enum;/* '<S409>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFrntFogLiSwSig_flg;/* '<S410>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFrntLeDoorHndlSwt_enum;/* '<S411>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFrntRiDoorHndlSwt_enum;/* '<S412>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMFrntWiprMotSts_enum;/* '<S413>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFrntWshrSwSig_flg;/* '<S414>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMFrontWashSts_flg;/* '<S415>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMHazardLampSts_flg;/* '<S355>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiBeamLiFltFb_enum;/* '<S416>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMHiBeamSwSig_enum;/* '<S417>/MinMax1' */

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
extern MONPRM volatile boolean VOPM_BCMHighBeamSta_flg;/* '<S418>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMHvyRainInd_flg;/* '<S419>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMHzrdWrngLghtSwSig_flg;/* '<S420>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMIllmndEntryStsFb_flg;/* '<S421>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMIllmndLampReq_flg;/* '<S422>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMIllmndLckStsFb_flg;/* '<S219>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMIllmndLockReq_enum;/* '<S423>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMIllmndSts_enum;/* '<S424>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMIllmndUnlckStsFb_flg;/* '<S220>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_BCMIndcnKeyClsr_flg;/* '<S425>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMIndcnShfttoNeut_flg;/* '<S426>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMKeyBattLvlSts_flg;/* '<S427>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile float32 VOPM_BCMKeyBattLvl_pct;/* '<S428>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMKeyFrbdn_flg;/* '<S429>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMKeyIDFb_enum;/* '<S430>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMKeyInCarSta_flg;/* '<S431>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMKeyLoBattLvlWarn_flg;/* '<S432>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint16 VOPM_BCMKeyLocn_mm;/* '<S433>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMKeySta_enum;/* '<S434>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMLFInitSta_flg;/* '<S435>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMLckHornOnStFb_flg;/* '<S436>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMLeTrnLiFltFb_enum;/* '<S437>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMLghtSwSig_enum;/* '<S438>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMLightIntensity_enum;/* '<S439>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMLoBeamLiFltFb_enum;/* '<S440>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMLogoActvFlg_enum;/* '<S441>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMLowBeamSta_flg;/* '<S442>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMLrngData02_nu;/* '<S146>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngData03_nu;/* '<S147>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngData04_nu;/* '<S148>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngData05_nu;/* '<S149>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngData06_nu;/* '<S150>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngData07_nu;/* '<S151>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngSts_enum;/* '<S152>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMLrngsubID_cnt;/* '<S153>/MinMax1' */

/* BCM_IMMOAuthResp1_EPT */
extern MONPRM volatile uint8 VOPM_BCMMaiDrvrSeatSts_enum;/* '<S443>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile float32 VOPM_BCMMaiDrvrSeatTemp_C;/* '<S444>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMOvrspdCntrlLckSetFb_flg;/* '<S445>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMPSAuthentRes_enum;/* '<S446>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMPSReq_flg;/* '<S447>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMParkAutoUnlckSetFb_flg;/* '<S448>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMPassWinSwSig_enum;/* '<S449>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMPaswdwInit_flg;/* '<S450>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMPosLampSta_flg;/* '<S356>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMPosLiFltFb_enum;/* '<S451>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMRFInitSta_flg;/* '<S452>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMRKEReq_enum;/* '<S453>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMReverseLampSta_flg;/* '<S454>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMRiTrnLiFltFb_enum;/* '<S455>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMRrFogLiFltFb_enum;/* '<S456>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMRrFogLiSwSig_flg;/* '<S457>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMRrMirrHeatSts_flg;/* '<S458>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMRrViewMirrHeatgSts_flg;/* '<S100>/Switch4' */

/* AC_ACStatuts_BOD */
extern MONPRM volatile uint8 VOPM_BCMRvrsLiFltFb_enum;/* '<S459>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMSavePwrSt_flg;/* '<S460>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMStartReq_enum;/* '<S461>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMSteerWhlHeatSts_flg;/* '<S462>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile float32 VOPM_BCMSteerWhlTemp_C;/* '<S463>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMSysPowerSts_enum;/* '<S357>/MinMax1' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile boolean VOPM_BCMSysPwrModeVld_flg;/* '<S358>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMSysPwrMode_enum;/* '<S359>/MinMax1' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_BCMTPMSRstSts_enum;/* '<S464>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMTrnkLckSta_flg;/* '<S465>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMTrnkLckSwCtrlFb_flg;/* '<S466>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMTrnngLiSwSig_enum;/* '<S467>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMTrunkSwtSig_flg;/* '<S468>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMTurnLampStaLeft_flg;/* '<S469>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMTurnLampStaRight_flg;/* '<S470>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMTurnLiSts_enum;/* '<S471>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMVehSeek_flg;/* '<S472>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMWarnKeyOutRmndr_flg;/* '<S473>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMWarnNoKeyFound_flg;/* '<S474>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMWashLiquidLvlWarn_flg;/* '<S475>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMWinLockSig_flg;/* '<S476>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMWinLockSts_flg;/* '<S477>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMWiperCtrlFront_enum;/* '<S478>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMWiperSwSig_enum;/* '<S479>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMWiprIntlGrSwtSig_enum;/* '<S480>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_BCMWiprIntlTimeSetFb_enum;/* '<S481>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_BCMWiprStopPstnSt_flg;/* '<S482>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile EnumBMSSdnCmd VOPM_BMSShutdown_enum;/* '<S325>/Data Type Conversion2' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile EnumBMSWakeUpMd VOPM_BMSWakeupMode_enum;/* '<S319>/Data Type Conversion2' */

/* VCU_3_OprtCmd_EPT */
extern MONPRM volatile boolean VOPM_Bat2DrvTrainEnb_flg;/* '<S320>/Switch4' */

/* VCU_3_OprtCmd_EPT */
extern MONPRM volatile boolean VOPM_BraSwi_flg;/* '<S192>/Switch4' */

/* VCU_0_Value_EPT */
extern MONPRM volatile uint8 VOPM_BrkPedSnsrPosVRsrvd_enum;/* '<S284>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_BrkPedalPos_pct;/* '<S285>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_BrkPwrRecupActWhlTq_Nm;/* '<S163>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile uint8 VOPM_BrkPwrRecupActlWhlTqSts_enum;/* '<S164>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_BrkPwrRecupMaxAvlbWhlTq_Nm;/* '<S165>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile uint8 VOPM_CCKeyStgntn_enum;/* '<S221>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_CCUOpenVentnFb_enum;/* '<S222>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_CCURmtCarSearchFb_enum;/* '<S223>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_CCURmtLckFb_enum;/* '<S224>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_CCURmtPwrLckFb_enum;/* '<S225>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_COMPCompInPwrLim_W;/* '<S101>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile uint8 VOPM_COMPEcompEnbl_enum;/* '<S102>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile uint8 VOPM_COMPEcompErrClean_enum;/* '<S103>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile uint8 VOPM_COMPEcompHVSt_enum;/* '<S104>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile float32 VOPM_COMPEcompSpdCtrl_rpm;/* '<S105>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile EnumChrgAllwCmd VOPM_ChrgAllowCmd_enum;/* '<S326>/Data Type Conversion2' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile EnumChrgEnaAC VOPM_ChrgEnaAC_enum;/* '<S321>/Data Type Conversion2' */

/* VCU_3_OprtCmd_EPT */
extern MONPRM volatile boolean VOPM_ChrgEnaDC_flg;/* '<S327>/Switch4' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile boolean VOPM_ChrgngCondsFb_flg;/* '<S226>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_CruiseCtrTgtSpd_kph;/* '<S227>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_CruiseCtrlSta_enum;/* '<S228>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_DCCBoostHvVolt_V;/* '<S338>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
extern MONPRM volatile float32 VOPM_DCCBuckLVVolt_V;/* '<S339>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
extern MONPRM volatile EnumDCCOprtCmd VOPM_DCCOprtCmd_enum;/* '<S334>/Data Type Conversion2' */

/* VCU_B_AcclPedal_EPT */
extern MONPRM volatile uint8 VOPM_DrvLfAntDiagStat_enum;/* '<S483>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_DrvModeKeyStgntn_enum;/* '<S229>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_DrvMotorSta_enum;/* '<S230>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_DrvPed_pct;/* '<S193>/MinMax1' */

/* VCU_0_Value_EPT */
extern MONPRM volatile boolean VOPM_DrvRangeDistEstVld_flg;/* '<S231>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_DrvRangeDistEst_km;/* '<S232>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_DrvReqMotorTorqVld_flg;/* '<S166>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_DrvReqMotorTorq_Nm;/* '<S167>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_DrvReqTorqOverrideFCM_flg;/* '<S286>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_DrvReqTorqOvrdESC_flg;/* '<S287>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_DrvReqWhlTqVld_flg;/* '<S168>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_DrvReqWhlTq_Nm;/* '<S169>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_DrvSwi_flg;/* '<S194>/Switch4' */

/* VCU_0_Value_EPT */
extern MONPRM volatile float32 VOPM_DrvWhlTqAllwdMax_Nm;/* '<S170>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile uint64 VOPM_ESCLUnOrLockCrtl_nu;/* '<S112>/MinMax1' */

/* BCM_ESCLCommand_BOD */
extern MONPRM volatile boolean VOPM_EmgcySdn_flg;/* '<S199>/Switch4' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile boolean VOPM_EnaDisChg_flg;/* '<S200>/Switch4' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile boolean VOPM_EnaInvRun_flg;/* '<S201>/Switch4' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile uint8 VOPM_ErrAmount_cnt;/* '<S335>/MinMax1' */

/* VCU_B_AcclPedal_EPT */
extern MONPRM volatile uint16 VOPM_ErrBit_nu;/* '<S336>/MinMax1' */

/* VCU_B_AcclPedal_EPT */
extern MONPRM volatile boolean VOPM_GearShiftInhibited_flg;/* '<S288>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_HDCStat_enum;/* '<S360>/MinMax1' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_HVCHEnbld_enum;/* '<S113>/MinMax1' */

/* HVCH_Command_BOD */
extern MONPRM volatile float32 VOPM_HVCHReqPwr_kW;/* '<S114>/MinMax1' */

/* HVCH_Command_BOD */
extern MONPRM volatile float32 VOPM_HVCHReqTemp_C;/* '<S115>/MinMax1' */

/* HVCH_Command_BOD */
extern MONPRM volatile uint8 VOPM_InfoDisp_enum;/* '<S233>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_IntLfAntDiagStat_enum;/* '<S484>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_LckVehWrm_enum;/* '<S234>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_LimpHomeSta_flg;/* '<S361>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile boolean VOPM_MCUHiTempWrning_flg;/* '<S235>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_MaxChrgCurntAC_A;/* '<S328>/MinMax1' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile float32 VOPM_MaxChrgCurntDC_A;/* '<S329>/MinMax1' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile float32 VOPM_MaxChrgVoltDC_V;/* '<S330>/MinMax1' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile float32 VOPM_MaxHVDCCurntAC_A;/* '<S340>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
extern MONPRM volatile float32 VOPM_MaxHVDCVoltAC_V;/* '<S341>/MinMax1' */

/* VCU_C_OprtCmd_EPT */
extern MONPRM volatile uint8 VOPM_MotActPwrTyp_enum;/* '<S236>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_MotActPwr_Kw;/* '<S237>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile EnumMotorDirReq VOPM_MotDirReq_enum;/* '<S202>/Data Type Conversion2' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile float32 VOPM_MotDmpgLmt_Nm;/* '<S195>/MinMax1' */

/* VCU_0_Value_EPT */
extern MONPRM volatile EnumMotorModeReq VOPM_MotModeReq_enum;/* '<S203>/Data Type Conversion2' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile float32 VOPM_MotSpdReq_rpm;/* '<S204>/MinMax1' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile float32 VOPM_MotTorqReq_Nm;/* '<S205>/MinMax1' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile boolean VOPM_MotorHiTempWrning_flg;/* '<S238>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_MotorOutputCooltTemp_C;/* '<S322>/MinMax1' */

/* VCU_3_OprtCmd_EPT */
extern MONPRM volatile boolean VOPM_OBCIntDchrgEna_flg;/* '<S342>/Switch4' */

/* VCU_C_OprtCmd_EPT */
extern MONPRM volatile EnumOBCOprtCmd VOPM_OBCOprtCmdToICU_enum;/* '<S239>/Data Type Conversion2' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile EnumOBCOprtCmd VOPM_OBCOprtCmd_enum;/* '<S331>/Data Type Conversion2' */

/* VCU_4_ChrgCmd_EPT */
extern MONPRM volatile boolean VOPM_OTAModeSts_flg;/* '<S289>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_PCUFailSta_flg;/* '<S362>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_PGrSwcSt_enum;/* '<S290>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile EnumPTActMd VOPM_PTActlOprtMode_enum;/* '<S363>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_PassLfAntDiagStat_enum;/* '<S485>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile EnumCrpModeAct VOPM_PrstlsStaFb_enum;/* '<S364>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile float32 VOPM_PwrRecupActWhlTq_Nm;/* '<S171>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile uint8 VOPM_PwrRecupActlWhlTqSts_enum;/* '<S172>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile EnumRegenModeAct VOPM_PwrRecupIntnsty_enum;/* '<S365>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_PwrRecupMaxAvlbMotorTorqSta_enum;/* '<S291>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_PwrRecupMaxAvlbWhlTqSts_enum;/* '<S173>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_RmtACCtrlReq_flg;/* '<S240>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_RmtACCtrlSt_enum;/* '<S241>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_RmtACDefrstReq_flg;/* '<S242>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_RmtMainDrvrSeatHeatFb_enum;/* '<S243>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_RmtPwrCtrlFb_enum;/* '<S244>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_RmtSteerWhlHeatFb_enum;/* '<S245>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_RsrvdPwr_kW;/* '<S246>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_SIBSBMSBatSOCAllow_flg;/* '<S247>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_SIBSChgNumAllow_flg;/* '<S248>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_SIBSFbRTCWupFlg_flg;/* '<S249>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_SIBSKL30Volt_V;/* '<S250>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile EnumIBSChrgSt VOPM_SIBSRTCChrgSt_enum;/* '<S251>/Data Type Conversion2' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_SIBSRTCWUChgFailNum_cnt;/* '<S252>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_SIBSRTCWUChgNum_cnt;/* '<S253>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_SIBSWupVoltAllow_flg;/* '<S254>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_ShftKeyStgntn_enum;/* '<S255>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_StrgRecupReqBrkLampOn_flg;/* '<S292>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_SysFailSta_enum;/* '<S337>/MinMax1' */

/* VCU_B_AcclPedal_EPT */
extern MONPRM volatile boolean VOPM_TMPSAbnmPrsrWarn_flg;/* '<S486>/Switch4' */

/* BCM_B_Package_BAC */
extern MONPRM volatile float32 VOPM_TMSACPExhtTmp_C;/* '<S106>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile float32 VOPM_TMSACPInletPres_kPa;/* '<S107>/MinMax1' */

/* AC_COMP_BOD */
extern MONPRM volatile uint16 VOPM_TMSAEXVCurrentPstn_cnt;/* '<S131>/MinMax1' */

/* TMS_LINTestData2_BOD */
extern MONPRM volatile boolean VOPM_TMSAEXVEnblReq_flg;/* '<S135>/Switch4' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint16 VOPM_TMSAEXVPstnReq_cnt;/* '<S132>/MinMax1' */

/* TMS_LINTestData2_BOD */
extern MONPRM volatile float32 VOPM_TMSAcPMPRealRPM_rpm;/* '<S118>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile float32 VOPM_TMSAcPMPSpdSet_rpm;/* '<S119>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile uint8 VOPM_TMSBATThermMod_enum;/* '<S83>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile uint16 VOPM_TMSBEXVCurrentPstn_cnt;/* '<S133>/MinMax1' */

/* TMS_LINTestData2_BOD */
extern MONPRM volatile boolean VOPM_TMSBEXVEnblCmd_flg;/* '<S136>/Switch4' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint16 VOPM_TMSBEXVPstnCmd_cnt;/* '<S134>/MinMax1' */

/* TMS_LINTestData2_BOD */
extern MONPRM volatile float32 VOPM_TMSBatPMPRealRPM_rpm;/* '<S120>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile float32 VOPM_TMSBatPMPSpdSet_rpm;/* '<S121>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile boolean VOPM_TMSBattTempCtrlRmnSwFb_flg;/* '<S56>/Switch4' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_TMSC3WVBPosSetReq_enum;/* '<S137>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint8 VOPM_TMSC3WVMode_enum;/* '<S138>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint16 VOPM_TMSC3WVPosRec_enum;/* '<S139>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint8 VOPM_TMSC5WVBPosSetReq_enum;/* '<S140>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint8 VOPM_TMSC5WVMode_enum;/* '<S141>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint16 VOPM_TMSC5WVPosRec_enum;/* '<S142>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint8 VOPM_TMSCabThermMod_enum;/* '<S84>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile float32 VOPM_TMSChillerOutTmp_C;/* '<S68>/MinMax1' */

/* AC_3_State_BOD */
extern MONPRM volatile float32 VOPM_TMSEvapOutTmp_C;/* '<S69>/MinMax1' */

/* AC_3_State_BOD */
extern MONPRM volatile float32 VOPM_TMSEvapTmp_C;/* '<S70>/MinMax1' */

/* AC_3_State_BOD */
extern MONPRM volatile uint16 VOPM_TMSHPEXVCurrentPstn_cnt;/* '<S143>/MinMax1' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile boolean VOPM_TMSHPEXVEnblCmd_flg;/* '<S144>/Switch4' */

/* TMS_LINTestData3_BOD */
extern MONPRM volatile uint16 VOPM_TMSHPEXVPstnCmd_cnt;/* '<S122>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile float32 VOPM_TMSMotInletCooltTemp_C;/* '<S85>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile float32 VOPM_TMSMotPMPRealRPM_rpm;/* '<S123>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile float32 VOPM_TMSMotPMPSpdSet_rpm;/* '<S124>/MinMax1' */

/* TMS_LINTestData1_BOD */
extern MONPRM volatile float32 VOPM_TMSOHXOutTmp_C;/* '<S71>/MinMax1' */

/* AC_3_State_BOD */
extern MONPRM volatile float32 VOPM_TMSPTPres_kPa;/* '<S57>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile float32 VOPM_TMSPTTemp_C;/* '<S58>/MinMax1' */

/* AC_2_State_BOD */
extern MONPRM volatile uint8 VOPM_TMSPwrCoolFanSpdDuty_pct;/* '<S86>/MinMax1' */

/* AC_8_status_BOD */
extern MONPRM volatile uint8 VOPM_TPMSPressureStaFL_enum;/* '<S487>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_TPMSPressureStaFR_enum;/* '<S488>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_TPMSPressureStaRL_enum;/* '<S489>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile uint8 VOPM_TPMSPressureStaRR_enum;/* '<S490>/MinMax1' */

/* BCM_B_Package_BAC */
extern MONPRM volatile boolean VOPM_VCUACCStandstillReq_flg;/* '<S293>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_VCUACCStat_enum;/* '<S294>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_VCUAccReqDrvOff_flg;/* '<S174>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_VCUAccReqStandstill_flg;/* '<S175>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_VCUAccTgtAxReq_flg;/* '<S295>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_VCUAccTgtAx_mps2;/* '<S296>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_VCUBraTorReq_Nm;/* '<S297>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile float32 VOPM_VCUCruiseCtrTgtSpd_kph;/* '<S298>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile EnumCruiseStatus VOPM_VCUCruiseCtrlSta_enum;/* '<S299>/Data Type Conversion2' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_VCUEPBApplyForbid_enum;/* '<S300>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_VCUEnaEHBBrkRun_flg;/* '<S176>/Switch4' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_VCUMasterCylinderPreReq_Bar;/* '<S177>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile float32 VOPM_VCUMotTorqueReqToEHB_Nm;/* '<S178>/MinMax1' */

/* VCU_10_Torque_CHA */
extern MONPRM volatile boolean VOPM_VCUOprtLicFb_flg;/* '<S256>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_VCUParkSwStaVld_flg;/* '<S301>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_VCUParkSwSta_flg;/* '<S302>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_VCUPreKeReq_flg;/* '<S303>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_VCUReqAutoBrk_enum;/* '<S304>/MinMax1' */

/* VCU_D_Status_CHA */
extern MONPRM volatile boolean VOPM_VCUReqEPBVld_flg;/* '<S305>/Switch4' */

/* VCU_D_Status_CHA */
extern MONPRM volatile EnumEPBReq VOPM_VCUReqEPB_enum;/* '<S306>/Data Type Conversion2' */

/* VCU_D_Status_CHA */
extern MONPRM volatile uint8 VOPM_VCUSpdLimLvlFb_enum;/* '<S257>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_VCUSpdLimLvlSetFb_enum;/* '<S258>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_VCUVerFb_flg;/* '<S259>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_VCUVerSetFb_enum;/* '<S260>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile EnumDrvModeAct VOPM_VehActDrvMod1_enum;/* '<S366>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile uint8 VOPM_VehActDrvPwr_pct;/* '<S261>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_VehActRecupPwr_pct;/* '<S262>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_VehActlGearPosVld_flg;/* '<S367>/Switch4' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile EnumGearPstn VOPM_VehActlGearPos_enum;/* '<S368>/Data Type Conversion2' */

/* CCU_VehInfo_BAC */
extern MONPRM volatile boolean VOPM_VehPGearError_flg;/* '<S263>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_VehPwrCnsmpAvrg_kWh;/* '<S264>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile EnumTgtGearPstn VOPM_VehTrgtGearPos_enum;/* '<S206>/Data Type Conversion2' */

/* VCU_1_InvCmd_EPT */
extern MONPRM volatile float32 VOPM_VhclActlCnsmPwr_kWh;/* '<S265>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_VhclSpdFstWarn_flg;/* '<S266>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_WLTPDrvgRngDstVld_flg;/* '<S267>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_WLTPDrvgRngDst_km;/* '<S268>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_WghConfdence_flg;/* '<S269>/Switch4' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile uint8 VOPM_WghDistb_enum;/* '<S270>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile float32 VOPM_WghEst_kg;/* '<S271>/MinMax1' */

/* VCU_DispInfo_BAC */
extern MONPRM volatile boolean VOPM_Zdznswi_flg;/* '<S196>/Switch4' */

/* VCU_0_Value_EPT */
#endif                                 /* RTW_HEADER_monPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
