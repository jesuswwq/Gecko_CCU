/*
 * File: calPrmsOpm.c
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

#include "calPrmsOpm.h"
#include "AppSwcOpm.h"

/* Exported data definition */

/*Group of variables*/
#include "XcpTest_types.h"

/* Definition for custom storage class: CalParam */
CALDATA const volatile uint8 KOPM_12VBatLowVolStaHi_enum = 3U;/* Referenced by: '<S350>/sat6' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_12VBatLowVolStaLo_enum = 0U;/* Referenced by: '<S350>/sat7' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_12VBatLowVolSta_enum_ovrdflg = false;/* Referenced by: '<S350>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_12VBatLowVolSta_enum_ovrdval = 0U;/* Referenced by: '<S350>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile float32 KOPM_ACActTotPwrHi_kW = 20.44F;/* Referenced by: '<S48>/sat6' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_ACActTotPwrLo_kW = 0.0F;/* Referenced by: '<S48>/sat7' */

/* AC_2_State_BOD */
CALDATA const volatile boolean KOPM_ACActTotPwr_kW_ovrdflg = false;/* Referenced by: '<S48>/sat3' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_ACActTotPwr_kW_ovrdval = 0.0F;/* Referenced by: '<S48>/sat4' */

/* AC_2_State_BOD */
CALDATA const volatile uint8 KOPM_ACActlOprtModeHi_enum = 3U;/* Referenced by: '<S49>/sat6' */

/* AC_2_State_BOD */
CALDATA const volatile uint8 KOPM_ACActlOprtModeLo_enum = 0U;/* Referenced by: '<S49>/sat7' */

/* AC_2_State_BOD */
CALDATA const volatile boolean KOPM_ACActlOprtMode_enum_ovrdflg = false;/* Referenced by: '<S49>/sat3' */

/* AC_2_State_BOD */
CALDATA const volatile uint8 KOPM_ACActlOprtMode_enum_ovrdval = 0U;/* Referenced by: '<S49>/sat4' */

/* AC_2_State_BOD */
CALDATA const volatile uint8 KOPM_ACAirInletModeStaHi_enum = 3U;/* Referenced by: '<S91>/sat6' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACAirInletModeStaLo_enum = 0U;/* Referenced by: '<S91>/sat7' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_ACAirInletModeSta_enum_ovrdflg = false;/* Referenced by: '<S91>/sat3' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACAirInletModeSta_enum_ovrdval = 0U;/* Referenced by: '<S91>/sat4' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACAutoBlwrModeStaHi_enum = 7U;/* Referenced by: '<S92>/sat6' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACAutoBlwrModeStaLo_enum = 0U;/* Referenced by: '<S92>/sat7' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_ACAutoBlwrModeSta_enum_ovrdflg = false;/* Referenced by: '<S92>/sat3' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACAutoBlwrModeSta_enum_ovrdval = 0U;/* Referenced by: '<S92>/sat4' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_ACAutoFb_flg_ovrdflg = false;/* Referenced by: '<S93>/sat3' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_ACAutoFb_flg_ovrdval = false;/* Referenced by: '<S93>/sat4' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACAutoFrntFanSpdHi_enum = 8U;/* Referenced by: '<S78>/sat6' */

/* AC_8_status_BOD */
CALDATA const volatile uint8 KOPM_ACAutoFrntFanSpdLo_enum = 0U;/* Referenced by: '<S78>/sat7' */

/* AC_8_status_BOD */
CALDATA const volatile boolean KOPM_ACAutoFrntFanSpd_enum_ovrdflg = false;/* Referenced by: '<S78>/sat3' */

/* AC_8_status_BOD */
CALDATA const volatile uint8 KOPM_ACAutoFrntFanSpd_enum_ovrdval = 0U;/* Referenced by: '<S78>/sat4' */

/* AC_8_status_BOD */
CALDATA const volatile boolean KOPM_ACBatPmpFailSta_flg_ovrdflg = false;/* Referenced by: '<S50>/sat3' */

/* AC_2_State_BOD */
CALDATA const volatile boolean KOPM_ACBatPmpFailSta_flg_ovrdval = false;/* Referenced by: '<S50>/sat4' */

/* AC_2_State_BOD */
CALDATA const volatile uint8 KOPM_ACBlwrModeStaHi_enum = 15U;/* Referenced by: '<S94>/sat6' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACBlwrModeStaLo_enum = 0U;/* Referenced by: '<S94>/sat7' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_ACBlwrModeSta_enum_ovrdflg = false;/* Referenced by: '<S94>/sat3' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACBlwrModeSta_enum_ovrdval = 0U;/* Referenced by: '<S94>/sat4' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_ACCTrqCtrlAvl_flg_ovrdflg = false;/* Referenced by: '<S279>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_ACCTrqCtrlAvl_flg_ovrdval = false;/* Referenced by: '<S279>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_ACChrgMaxCurrHi_A = 32U;/* Referenced by: '<S213>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACChrgMaxCurrLo_A = 0U;/* Referenced by: '<S213>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_ACChrgMaxCurr_A_ovrdflg = false;/* Referenced by: '<S213>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACChrgMaxCurr_A_ovrdval = 0U;/* Referenced by: '<S213>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACChrgModeHi_enum = 3U;/* Referenced by: '<S214>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACChrgModeLo_enum = 0U;/* Referenced by: '<S214>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_ACChrgMode_enum_ovrdflg = false;/* Referenced by: '<S214>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACChrgMode_enum_ovrdval = 0U;/* Referenced by: '<S214>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_ACCompFailModeOprtSta_flg_ovrdflg = false;/* Referenced by: '<S38>/sat3' */

/* AC_1_Command_BOD */
CALDATA const volatile boolean KOPM_ACCompFailModeOprtSta_flg_ovrdval = false;/* Referenced by: '<S38>/sat4' */

/* AC_1_Command_BOD */
CALDATA const volatile float32 KOPM_ACCompMaxAllowPwrCmspHi_kW = 10.16F;/* Referenced by: '<S39>/sat6' */

/* AC_1_Command_BOD */
CALDATA const volatile float32 KOPM_ACCompMaxAllowPwrCmspLo_kW = 0.0F;/* Referenced by: '<S39>/sat7' */

/* AC_1_Command_BOD */
CALDATA const volatile boolean KOPM_ACCompMaxAllowPwrCmsp_kW_ovrdflg = false;/* Referenced by: '<S39>/sat3' */

/* AC_1_Command_BOD */
CALDATA const volatile float32 KOPM_ACCompMaxAllowPwrCmsp_kW_ovrdval = 0.0F;/* Referenced by: '<S39>/sat4' */

/* AC_1_Command_BOD */
CALDATA const volatile boolean KOPM_ACCompOprtEnaCmd_flg_ovrdflg = false;/* Referenced by: '<S40>/sat3' */

/* AC_1_Command_BOD */
CALDATA const volatile boolean KOPM_ACCompOprtEnaCmd_flg_ovrdval = false;/* Referenced by: '<S40>/sat4' */

/* AC_1_Command_BOD */
CALDATA const volatile boolean KOPM_ACCompOprtReq_flg_ovrdflg = false;/* Referenced by: '<S41>/sat3' */

/* AC_1_Command_BOD */
CALDATA const volatile boolean KOPM_ACCompOprtReq_flg_ovrdval = false;/* Referenced by: '<S41>/sat4' */

/* AC_1_Command_BOD */
CALDATA const volatile float32 KOPM_ACCompTgtSpdHi_rpm = 8191.0F;/* Referenced by: '<S42>/sat6' */

/* AC_1_Command_BOD */
CALDATA const volatile float32 KOPM_ACCompTgtSpdLo_rpm = 0.0F;/* Referenced by: '<S42>/sat7' */

/* AC_1_Command_BOD */
CALDATA const volatile boolean KOPM_ACCompTgtSpd_rpm_ovrdflg = false;/* Referenced by: '<S42>/sat3' */

/* AC_1_Command_BOD */
CALDATA const volatile float32 KOPM_ACCompTgtSpd_rpm_ovrdval = 0.0F;/* Referenced by: '<S42>/sat4' */

/* AC_1_Command_BOD */
CALDATA const volatile float32 KOPM_ACEnvirTempHi_C = 87.5F;/* Referenced by: '<S65>/sat6' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_ACEnvirTempLo_C = -40.0F;/* Referenced by: '<S65>/sat7' */

/* AC_3_State_BOD */
CALDATA const volatile boolean KOPM_ACEnvirTempVld_flg_ovrdflg = false;/* Referenced by: '<S64>/sat3' */

/* AC_3_State_BOD */
CALDATA const volatile boolean KOPM_ACEnvirTempVld_flg_ovrdval = false;/* Referenced by: '<S64>/sat4' */

/* AC_3_State_BOD */
CALDATA const volatile boolean KOPM_ACEnvirTemp_C_ovrdflg = false;/* Referenced by: '<S65>/sat3' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_ACEnvirTemp_C_ovrdval = 0.0F;/* Referenced by: '<S65>/sat4' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_ACEvapTgtTempHi_C = 87.5F;/* Referenced by: '<S79>/sat6' */

/* AC_8_status_BOD */
CALDATA const volatile float32 KOPM_ACEvapTgtTempLo_C = -40.0F;/* Referenced by: '<S79>/sat7' */

/* AC_8_status_BOD */
CALDATA const volatile boolean KOPM_ACEvapTgtTemp_C_ovrdflg = false;/* Referenced by: '<S79>/sat3' */

/* AC_8_status_BOD */
CALDATA const volatile float32 KOPM_ACEvapTgtTemp_C_ovrdval = 0.0F;/* Referenced by: '<S79>/sat4' */

/* AC_8_status_BOD */
CALDATA const volatile boolean KOPM_ACExtdDefrstActvReq_flg_ovrdflg = false;/* Referenced by: '<S66>/sat3' */

/* AC_3_State_BOD */
CALDATA const volatile boolean KOPM_ACExtdDefrstActvReq_flg_ovrdval = false;/* Referenced by: '<S66>/sat4' */

/* AC_3_State_BOD */
CALDATA const volatile boolean KOPM_ACFailSta_flg_ovrdflg = false;/* Referenced by: '<S51>/sat3' */

/* AC_2_State_BOD */
CALDATA const volatile boolean KOPM_ACFailSta_flg_ovrdval = false;/* Referenced by: '<S51>/sat4' */

/* AC_2_State_BOD */
CALDATA const volatile uint8 KOPM_ACFrntFanSpdValHi_enum = 15U;/* Referenced by: '<S95>/sat6' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACFrntFanSpdValLo_enum = 0U;/* Referenced by: '<S95>/sat7' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_ACFrntFanSpdVal_enum_ovrdflg = false;/* Referenced by: '<S95>/sat3' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACFrntFanSpdVal_enum_ovrdval = 0U;/* Referenced by: '<S95>/sat4' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACHVHActlOprtModeHi_enum = 3U;/* Referenced by: '<S52>/sat6' */

/* AC_2_State_BOD */
CALDATA const volatile uint8 KOPM_ACHVHActlOprtModeLo_enum = 0U;/* Referenced by: '<S52>/sat7' */

/* AC_2_State_BOD */
CALDATA const volatile boolean KOPM_ACHVHActlOprtMode_enum_ovrdflg = false;/* Referenced by: '<S52>/sat3' */

/* AC_2_State_BOD */
CALDATA const volatile uint8 KOPM_ACHVHActlOprtMode_enum_ovrdval = 0U;/* Referenced by: '<S52>/sat4' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_ACHVHActlPwrHi_KW = 10.2F;/* Referenced by: '<S53>/sat6' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_ACHVHActlPwrLo_KW = 0.0F;/* Referenced by: '<S53>/sat7' */

/* AC_2_State_BOD */
CALDATA const volatile boolean KOPM_ACHVHActlPwr_KW_ovrdflg = false;/* Referenced by: '<S53>/sat3' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_ACHVHActlPwr_KW_ovrdval = 0.0F;/* Referenced by: '<S53>/sat4' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_ACHVHDevInternTempHi_C = 215.0F;/* Referenced by: '<S54>/sat6' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_ACHVHDevInternTempLo_C = -40.0F;/* Referenced by: '<S54>/sat7' */

/* AC_2_State_BOD */
CALDATA const volatile boolean KOPM_ACHVHDevInternTemp_C_ovrdflg = false;/* Referenced by: '<S54>/sat3' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_ACHVHDevInternTemp_C_ovrdval = 0.0F;/* Referenced by: '<S54>/sat4' */

/* AC_2_State_BOD */
CALDATA const volatile boolean KOPM_ACHVHFailSta_flg_ovrdflg = false;/* Referenced by: '<S55>/sat3' */

/* AC_2_State_BOD */
CALDATA const volatile boolean KOPM_ACHVHFailSta_flg_ovrdval = false;/* Referenced by: '<S55>/sat4' */

/* AC_2_State_BOD */
CALDATA const volatile uint8 KOPM_ACHVPTCOnRqHi_enum = 3U;/* Referenced by: '<S80>/sat6' */

/* AC_8_status_BOD */
CALDATA const volatile uint8 KOPM_ACHVPTCOnRqLo_enum = 0U;/* Referenced by: '<S80>/sat7' */

/* AC_8_status_BOD */
CALDATA const volatile boolean KOPM_ACHVPTCOnRq_enum_ovrdflg = false;/* Referenced by: '<S80>/sat3' */

/* AC_8_status_BOD */
CALDATA const volatile uint8 KOPM_ACHVPTCOnRq_enum_ovrdval = 0U;/* Referenced by: '<S80>/sat4' */

/* AC_8_status_BOD */
CALDATA const volatile float32 KOPM_ACHighVolDCTotalPwrHi_kW = 20.44F;/* Referenced by: '<S43>/sat6' */

/* AC_1_Command_BOD */
CALDATA const volatile float32 KOPM_ACHighVolDCTotalPwrLo_kW = 0.0F;/* Referenced by: '<S43>/sat7' */

/* AC_1_Command_BOD */
CALDATA const volatile boolean KOPM_ACHighVolDCTotalPwr_kW_ovrdflg = false;/* Referenced by: '<S43>/sat3' */

/* AC_1_Command_BOD */
CALDATA const volatile float32 KOPM_ACHighVolDCTotalPwr_kW_ovrdval = 0.0F;/* Referenced by: '<S43>/sat4' */

/* AC_1_Command_BOD */
CALDATA const volatile uint8 KOPM_ACHybEcoModeStaHi_enum = 3U;/* Referenced by: '<S96>/sat6' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACHybEcoModeStaLo_enum = 0U;/* Referenced by: '<S96>/sat7' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_ACHybEcoModeSta_enum_ovrdflg = false;/* Referenced by: '<S96>/sat3' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACHybEcoModeSta_enum_ovrdval = 0U;/* Referenced by: '<S96>/sat4' */

/* AC_ACStatuts_BOD */
CALDATA const volatile float32 KOPM_ACIndoorTempHi_C = 87.5F;/* Referenced by: '<S67>/sat6' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_ACIndoorTempLo_C = -40.0F;/* Referenced by: '<S67>/sat7' */

/* AC_3_State_BOD */
CALDATA const volatile boolean KOPM_ACIndoorTemp_C_ovrdflg = false;/* Referenced by: '<S67>/sat3' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_ACIndoorTemp_C_ovrdval = 0.0F;/* Referenced by: '<S67>/sat4' */

/* AC_3_State_BOD */
CALDATA const volatile uint8 KOPM_ACLeftTempValHi_enum = 63U;/* Referenced by: '<S97>/sat6' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACLeftTempValLo_enum = 0U;/* Referenced by: '<S97>/sat7' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_ACLeftTempVal_enum_ovrdflg = false;/* Referenced by: '<S97>/sat3' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACLeftTempVal_enum_ovrdval = 0U;/* Referenced by: '<S97>/sat4' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_ACManlDefrstFb_flg_ovrdflg = false;/* Referenced by: '<S98>/sat3' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_ACManlDefrstFb_flg_ovrdval = false;/* Referenced by: '<S98>/sat4' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_ACPumpActlSpdDutyHi_pct = 100U;/* Referenced by: '<S45>/sat6' */

/* AC_1_Command_BOD */
CALDATA const volatile uint8 KOPM_ACPumpActlSpdDutyLo_pct = 0U;/* Referenced by: '<S45>/sat7' */

/* AC_1_Command_BOD */
CALDATA const volatile boolean KOPM_ACPumpActlSpdDutyVld_flg_ovrdflg = false;/* Referenced by: '<S44>/sat3' */

/* AC_1_Command_BOD */
CALDATA const volatile boolean KOPM_ACPumpActlSpdDutyVld_flg_ovrdval = false;/* Referenced by: '<S44>/sat4' */

/* AC_1_Command_BOD */
CALDATA const volatile boolean KOPM_ACPumpActlSpdDuty_pct_ovrdflg = false;/* Referenced by: '<S45>/sat3' */

/* AC_1_Command_BOD */
CALDATA const volatile uint8 KOPM_ACPumpActlSpdDuty_pct_ovrdval = 0U;/* Referenced by: '<S45>/sat4' */

/* AC_1_Command_BOD */
CALDATA const volatile boolean KOPM_ACPwrFb_flg_ovrdflg = false;/* Referenced by: '<S99>/sat3' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_ACPwrFb_flg_ovrdval = false;/* Referenced by: '<S99>/sat4' */

/* AC_ACStatuts_BOD */
CALDATA const volatile float32 KOPM_ACRefrgLoPresHi_kPa = 1000.0F;/* Referenced by: '<S82>/sat6' */

/* AC_8_status_BOD */
CALDATA const volatile float32 KOPM_ACRefrgLoPresLo_kPa = 0.0F;/* Referenced by: '<S82>/sat7' */

/* AC_8_status_BOD */
CALDATA const volatile boolean KOPM_ACRefrgLoPresVld_flg_ovrdflg = false;/* Referenced by: '<S81>/sat3' */

/* AC_8_status_BOD */
CALDATA const volatile boolean KOPM_ACRefrgLoPresVld_flg_ovrdval = false;/* Referenced by: '<S81>/sat4' */

/* AC_8_status_BOD */
CALDATA const volatile boolean KOPM_ACRefrgLoPres_kPa_ovrdflg = false;/* Referenced by: '<S82>/sat3' */

/* AC_8_status_BOD */
CALDATA const volatile float32 KOPM_ACRefrgLoPres_kPa_ovrdval = 0.0F;/* Referenced by: '<S82>/sat4' */

/* AC_8_status_BOD */
CALDATA const volatile uint8 KOPM_ACRemtCtrlFbHi_enum = 3U;/* Referenced by: '<S215>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACRemtCtrlFbLo_enum = 0U;/* Referenced by: '<S215>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_ACRemtCtrlFb_enum_ovrdflg = false;/* Referenced by: '<S215>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACRemtCtrlFb_enum_ovrdval = 0U;/* Referenced by: '<S215>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACRmtDefrstCtlFbHi_enum = 3U;/* Referenced by: '<S216>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACRmtDefrstCtlFbLo_enum = 0U;/* Referenced by: '<S216>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_ACRmtDefrstCtlFb_enum_ovrdflg = false;/* Referenced by: '<S216>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACRmtDefrstCtlFb_enum_ovrdval = 0U;/* Referenced by: '<S216>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACTempSetFbHi_enum = 3U;/* Referenced by: '<S217>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACTempSetFbLo_enum = 0U;/* Referenced by: '<S217>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_ACTempSetFb_enum_ovrdflg = false;/* Referenced by: '<S217>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACTempSetFb_enum_ovrdval = 0U;/* Referenced by: '<S217>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACUnlckVentSetFBHi_enum = 3U;/* Referenced by: '<S218>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACUnlckVentSetFBLo_enum = 0U;/* Referenced by: '<S218>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_ACUnlckVentSetFB_enum_ovrdflg = false;/* Referenced by: '<S218>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ACUnlckVentSetFB_enum_ovrdval = 0U;/* Referenced by: '<S218>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_AccPedPosSnsrStaHi_enum = 3U;/* Referenced by: '<S280>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_AccPedPosSnsrStaLo_enum = 0U;/* Referenced by: '<S280>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_AccPedPosSnsrSta_enum_ovrdflg = false;/* Referenced by: '<S280>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile EnumAccPedSnsrSt KOPM_AccPedPosSnsrSta_enum_ovrdval =
  EnumAccPedSnsrSt_Invalid;            /* Referenced by: '<S280>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_AccPedPosToESCHi_pct = 100.0F;/* Referenced by: '<S282>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_AccPedPosToESCLo_pct = 0.0F;/* Referenced by: '<S282>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_AccPedPosToESCStaHi_enum = 4U;/* Referenced by: '<S281>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_AccPedPosToESCStaLo_enum = 0U;/* Referenced by: '<S281>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_AccPedPosToESCSta_enum_ovrdflg = false;/* Referenced by: '<S281>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_AccPedPosToESCSta_enum_ovrdval = 0U;/* Referenced by: '<S281>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_AccPedPosToESC_pct_ovrdflg = false;/* Referenced by: '<S282>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_AccPedPosToESC_pct_ovrdval = 0.0F;/* Referenced by: '<S282>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_AcclPedalPosHi_pct = 100.0F;/* Referenced by: '<S283>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_AcclPedalPosLo_pct = 0.0F;/* Referenced by: '<S283>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_AcclPedalPos_pct_ovrdflg = false;/* Referenced by: '<S283>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_AcclPedalPos_pct_ovrdval = 0.0F;/* Referenced by: '<S283>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_ActWhlTqHi_Nm = 6200.0F;/* Referenced by: '<S158>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_ActWhlTqLo_Nm = -6200.0F;/* Referenced by: '<S158>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_ActWhlTqVld_flg_ovrdflg = false;/* Referenced by: '<S157>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_ActWhlTqVld_flg_ovrdval = false;/* Referenced by: '<S157>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_ActWhlTq_Nm_ovrdflg = false;/* Referenced by: '<S158>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_ActWhlTq_Nm_ovrdval = 0.0F;/* Referenced by: '<S158>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_ActlMotorRotateSpdHi_rpm = 16000.0F;/* Referenced by: '<S160>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_ActlMotorRotateSpdLo_rpm = -10000.0F;/* Referenced by: '<S160>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_ActlMotorRotateSpdVld_flg_ovrdflg = false;/* Referenced by: '<S159>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_ActlMotorRotateSpdVld_flg_ovrdval = false;/* Referenced by: '<S159>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_ActlMotorRotateSpd_rpm_ovrdflg = false;/* Referenced by: '<S160>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_ActlMotorRotateSpd_rpm_ovrdval = 0.0F;/* Referenced by: '<S160>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_ActlMotorTorqHi_Nm = 1000.0F;/* Referenced by: '<S162>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_ActlMotorTorqLo_Nm = -1000.0F;/* Referenced by: '<S162>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_ActlMotorTorqVld_flg_ovrdflg = false;/* Referenced by: '<S161>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_ActlMotorTorqVld_flg_ovrdval = false;/* Referenced by: '<S161>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_ActlMotorTorq_Nm_ovrdflg = false;/* Referenced by: '<S162>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_ActlMotorTorq_Nm_ovrdval = 0.0F;/* Referenced by: '<S162>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_AllowHeatCoolMaxPwrCmspHi_kW = 20.44F;/* Referenced by: '<S318>/sat6' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_AllowHeatCoolMaxPwrCmspLo_kW = 0.0F;/* Referenced by: '<S318>/sat7' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_AllowHeatCoolMaxPwrCmsp_kW_ovrdflg = false;/* Referenced by: '<S318>/sat3' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_AllowHeatCoolMaxPwrCmsp_kW_ovrdval = 0.0F;/* Referenced by: '<S318>/sat4' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile uint8 KOPM_AppSoftNumbHi_nu = 255U;/* Referenced by: '<S191>/sat6' */

/* VCU_0_Value_EPT */
CALDATA const volatile uint8 KOPM_AppSoftNumbLo_nu = 0U;/* Referenced by: '<S191>/sat7' */

/* VCU_0_Value_EPT */
CALDATA const volatile boolean KOPM_AppSoftNumb_nu_ovrdflg = false;/* Referenced by: '<S191>/sat3' */

/* VCU_0_Value_EPT */
CALDATA const volatile uint8 KOPM_AppSoftNumb_nu_ovrdval = 0U;/* Referenced by: '<S191>/sat4' */

/* VCU_0_Value_EPT */
CALDATA const volatile boolean KOPM_BCMAjarStaHood_flg_ovrdflg = false;/* Referenced by: '<S369>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMAjarStaHood_flg_ovrdval = false;/* Referenced by: '<S369>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMAjarStaTrunk_flg_ovrdflg = false;/* Referenced by: '<S370>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMAjarStaTrunk_flg_ovrdval = false;/* Referenced by: '<S370>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMAjarStaVHoodVld_flg_ovrdflg = false;/* Referenced by: '<S371>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMAjarStaVHoodVld_flg_ovrdval = false;/* Referenced by: '<S371>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMAlrmHornReq_flg_ovrdflg = false;/* Referenced by: '<S372>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMAlrmHornReq_flg_ovrdval = false;/* Referenced by: '<S372>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMAuthentKeyNrHi_enum = 7U;/* Referenced by: '<S373>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMAuthentKeyNrLo_enum = 0U;/* Referenced by: '<S373>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMAuthentKeyNr_enum_ovrdflg = false;/* Referenced by: '<S373>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMAuthentKeyNr_enum_ovrdval = 0U;/* Referenced by: '<S373>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMAutoLampStatus_flg_ovrdflg = false;/* Referenced by: '<S374>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMAutoLampStatus_flg_ovrdval = false;/* Referenced by: '<S374>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMAvaluebleKeyInCar_flg_ovrdflg = false;/* Referenced by: '<S375>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMAvaluebleKeyInCar_flg_ovrdval = false;/* Referenced by: '<S375>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBackLadjvalFbHi_enum = 7U;/* Referenced by: '<S351>/sat6' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMBackLadjvalFbLo_enum = 0U;/* Referenced by: '<S351>/sat7' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_BCMBackLadjvalFb_enum_ovrdflg = false;/* Referenced by: '<S351>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMBackLadjvalFb_enum_ovrdval = 0U;/* Referenced by: '<S351>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_BCMBackLampSt_flg_ovrdflg = false;/* Referenced by: '<S376>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMBackLampSt_flg_ovrdval = false;/* Referenced by: '<S376>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBackLiFltFbHi_enum = 3U;/* Referenced by: '<S377>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBackLiFltFbLo_enum = 0U;/* Referenced by: '<S377>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMBackLiFltFb_enum_ovrdflg = false;/* Referenced by: '<S377>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBackLiFltFb_enum_ovrdval = 0U;/* Referenced by: '<S377>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBassHornReqHi_enum = 7U;/* Referenced by: '<S378>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBassHornReqLo_enum = 0U;/* Referenced by: '<S378>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMBassHornReq_enum_ovrdflg = false;/* Referenced by: '<S378>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBassHornReq_enum_ovrdval = 0U;/* Referenced by: '<S378>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBodyWarnStsHi_enum = 3U;/* Referenced by: '<S379>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBodyWarnStsLo_enum = 0U;/* Referenced by: '<S379>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMBodyWarnSts_enum_ovrdflg = false;/* Referenced by: '<S379>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBodyWarnSts_enum_ovrdval = 0U;/* Referenced by: '<S379>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMBrakeLampSta_flg_ovrdflg = false;/* Referenced by: '<S380>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMBrakeLampSta_flg_ovrdval = false;/* Referenced by: '<S380>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBrkLiFltFbHi_enum = 3U;/* Referenced by: '<S381>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBrkLiFltFbLo_enum = 0U;/* Referenced by: '<S381>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMBrkLiFltFb_enum_ovrdflg = false;/* Referenced by: '<S381>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMBrkLiFltFb_enum_ovrdval = 0U;/* Referenced by: '<S381>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMBrkPedSta_flg_ovrdflg = false;/* Referenced by: '<S352>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_BCMBrkPedSta_flg_ovrdval = false;/* Referenced by: '<S352>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_BCMCarrgLghtSt_flg_ovrdflg = false;/* Referenced by: '<S382>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMCarrgLghtSt_flg_ovrdval = false;/* Referenced by: '<S382>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMCenLckStsHi_enum = 3U;/* Referenced by: '<S353>/sat6' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMCenLckStsLo_enum = 0U;/* Referenced by: '<S353>/sat7' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_BCMCenLckSts_enum_ovrdflg = false;/* Referenced by: '<S353>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMCenLckSts_enum_ovrdval = 0U;/* Referenced by: '<S353>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMChgWiprMtMdSwSetFbHi_enum = 3U;/* Referenced by: '<S383>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMChgWiprMtMdSwSetFbLo_enum = 0U;/* Referenced by: '<S383>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMChgWiprMtMdSwSetFb_enum_ovrdflg = false;/* Referenced by: '<S383>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMChgWiprMtMdSwSetFb_enum_ovrdval = 0U;/* Referenced by: '<S383>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMChrgLidLockReqHi_enum = 3U;/* Referenced by: '<S384>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMChrgLidLockReqLo_enum = 0U;/* Referenced by: '<S384>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMChrgLidLockReq_enum_ovrdflg = false;/* Referenced by: '<S384>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMChrgLidLockReq_enum_ovrdval = 0U;/* Referenced by: '<S384>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDayRunLiFltFbHi_enum = 3U;/* Referenced by: '<S385>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDayRunLiFltFbLo_enum = 0U;/* Referenced by: '<S385>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDayRunLiFltFb_enum_ovrdflg = false;/* Referenced by: '<S385>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDayRunLiFltFb_enum_ovrdval = 0U;/* Referenced by: '<S385>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDayRunLiSwSig_flg_ovrdflg = false;/* Referenced by: '<S386>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDayRunLiSwSig_flg_ovrdval = false;/* Referenced by: '<S386>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDayRunLightSta_flg_ovrdflg = false;/* Referenced by: '<S387>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDayRunLightSta_flg_ovrdval = false;/* Referenced by: '<S387>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDomeLghtSt_flg_ovrdflg = false;/* Referenced by: '<S388>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDomeLghtSt_flg_ovrdval = false;/* Referenced by: '<S388>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDoorAjarStaFL_flg_ovrdflg = false;/* Referenced by: '<S389>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDoorAjarStaFL_flg_ovrdval = false;/* Referenced by: '<S389>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDoorAjarStaFR_flg_ovrdflg = false;/* Referenced by: '<S390>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDoorAjarStaFR_flg_ovrdval = false;/* Referenced by: '<S390>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDoorAjarStaRL_flg_ovrdflg = false;/* Referenced by: '<S391>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDoorAjarStaRL_flg_ovrdval = false;/* Referenced by: '<S391>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDoorAjarStaRR_flg_ovrdflg = false;/* Referenced by: '<S392>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDoorAjarStaRR_flg_ovrdval = false;/* Referenced by: '<S392>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDoorLckOpRecHi_enum = 31U;/* Referenced by: '<S393>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDoorLckOpRecLo_enum = 0U;/* Referenced by: '<S393>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDoorLckOpRec_enum_ovrdflg = false;/* Referenced by: '<S393>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDoorLckOpRec_enum_ovrdval = 0U;/* Referenced by: '<S393>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDoorLckStaFL_flg_ovrdflg = false;/* Referenced by: '<S354>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_BCMDoorLckStaFL_flg_ovrdval = false;/* Referenced by: '<S354>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMDrvPEAuthentAcsdHi_enum = 3U;/* Referenced by: '<S394>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDrvPEAuthentAcsdLo_enum = 0U;/* Referenced by: '<S394>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDrvPEAuthentAcsd_enum_ovrdflg = false;/* Referenced by: '<S394>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDrvPEAuthentAcsd_enum_ovrdval = 0U;/* Referenced by: '<S394>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDrvPassWinSwSigHi_enum = 7U;/* Referenced by: '<S395>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDrvPassWinSwSigLo_enum = 0U;/* Referenced by: '<S395>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDrvPassWinSwSig_enum_ovrdflg = false;/* Referenced by: '<S395>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDrvPassWinSwSig_enum_ovrdval = 0U;/* Referenced by: '<S395>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDrvSeatOccptSnsrStsHi_enum = 3U;/* Referenced by: '<S396>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDrvSeatOccptSnsrStsLo_enum = 0U;/* Referenced by: '<S396>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDrvSeatOccptSnsrSts_enum_ovrdflg = false;/* Referenced by: '<S396>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDrvSeatOccptSnsrSts_enum_ovrdval = 0U;/* Referenced by: '<S396>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDrvrWinSwSigHi_enum = 7U;/* Referenced by: '<S397>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDrvrWinSwSigLo_enum = 0U;/* Referenced by: '<S397>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMDrvrWinSwSig_enum_ovrdflg = false;/* Referenced by: '<S397>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMDrvrWinSwSig_enum_ovrdval = 0U;/* Referenced by: '<S397>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFLWinSts_flg_ovrdflg = false;/* Referenced by: '<S398>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFLWinSts_flg_ovrdval = false;/* Referenced by: '<S398>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFLWinmotorStsHi_enum = 7U;/* Referenced by: '<S399>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFLWinmotorStsLo_enum = 0U;/* Referenced by: '<S399>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFLWinmotorSts_enum_ovrdflg = false;/* Referenced by: '<S399>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFLWinmotorSts_enum_ovrdval = 0U;/* Referenced by: '<S399>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFLWinmotor_flg_ovrdflg = false;/* Referenced by: '<S400>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFLWinmotor_flg_ovrdval = false;/* Referenced by: '<S400>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFRPEAuthentAcsdHi_enum = 3U;/* Referenced by: '<S401>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFRPEAuthentAcsdLo_enum = 0U;/* Referenced by: '<S401>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFRPEAuthentAcsd_enum_ovrdflg = false;/* Referenced by: '<S401>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFRPEAuthentAcsd_enum_ovrdval = 0U;/* Referenced by: '<S401>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFRWinSts_flg_ovrdflg = false;/* Referenced by: '<S402>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFRWinSts_flg_ovrdval = false;/* Referenced by: '<S402>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFRWinmotorStsHi_enum = 7U;/* Referenced by: '<S403>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFRWinmotorStsLo_enum = 0U;/* Referenced by: '<S403>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFRWinmotorSts_enum_ovrdflg = false;/* Referenced by: '<S403>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFRWinmotorSts_enum_ovrdval = 0U;/* Referenced by: '<S403>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFRWinmotor_flg_ovrdflg = false;/* Referenced by: '<S404>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFRWinmotor_flg_ovrdval = false;/* Referenced by: '<S404>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFlwrMeHmCtrlFbHi_enum = 7U;/* Referenced by: '<S405>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFlwrMeHmCtrlFbLo_enum = 0U;/* Referenced by: '<S405>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFlwrMeHmCtrlFb_enum_ovrdflg = false;/* Referenced by: '<S405>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFlwrMeHmCtrlFb_enum_ovrdval = 0U;/* Referenced by: '<S405>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFogLampStaFront_flg_ovrdflg = false;/* Referenced by: '<S406>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFogLampStaFront_flg_ovrdval = false;/* Referenced by: '<S406>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFogLampStaRear_flg_ovrdflg = false;/* Referenced by: '<S407>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFogLampStaRear_flg_ovrdval = false;/* Referenced by: '<S407>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrbdnKeyNrHi_enum = 3U;/* Referenced by: '<S408>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrbdnKeyNrLo_enum = 0U;/* Referenced by: '<S408>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFrbdnKeyNr_enum_ovrdflg = false;/* Referenced by: '<S408>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrbdnKeyNr_enum_ovrdval = 0U;/* Referenced by: '<S408>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrntFogLiFltFbHi_enum = 3U;/* Referenced by: '<S409>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrntFogLiFltFbLo_enum = 0U;/* Referenced by: '<S409>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFrntFogLiFltFb_enum_ovrdflg = false;/* Referenced by: '<S409>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrntFogLiFltFb_enum_ovrdval = 0U;/* Referenced by: '<S409>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFrntFogLiSwSig_flg_ovrdflg = false;/* Referenced by: '<S410>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFrntFogLiSwSig_flg_ovrdval = false;/* Referenced by: '<S410>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrntLeDoorHndlSwtHi_enum = 3U;/* Referenced by: '<S411>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrntLeDoorHndlSwtLo_enum = 0U;/* Referenced by: '<S411>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFrntLeDoorHndlSwt_enum_ovrdflg = false;/* Referenced by: '<S411>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrntLeDoorHndlSwt_enum_ovrdval = 0U;/* Referenced by: '<S411>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrntRiDoorHndlSwtHi_enum = 3U;/* Referenced by: '<S412>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrntRiDoorHndlSwtLo_enum = 0U;/* Referenced by: '<S412>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFrntRiDoorHndlSwt_enum_ovrdflg = false;/* Referenced by: '<S412>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrntRiDoorHndlSwt_enum_ovrdval = 0U;/* Referenced by: '<S412>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrntWiprMotStsHi_enum = 3U;/* Referenced by: '<S413>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrntWiprMotStsLo_enum = 0U;/* Referenced by: '<S413>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFrntWiprMotSts_enum_ovrdflg = false;/* Referenced by: '<S413>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMFrntWiprMotSts_enum_ovrdval = 0U;/* Referenced by: '<S413>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFrntWshrSwSig_flg_ovrdflg = false;/* Referenced by: '<S414>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFrntWshrSwSig_flg_ovrdval = false;/* Referenced by: '<S414>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFrontWashSts_flg_ovrdflg = false;/* Referenced by: '<S415>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMFrontWashSts_flg_ovrdval = false;/* Referenced by: '<S415>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMHazardLampSts_flg_ovrdflg = false;/* Referenced by: '<S355>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_BCMHazardLampSts_flg_ovrdval = false;/* Referenced by: '<S355>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMHiBeamLiFltFbHi_enum = 3U;/* Referenced by: '<S416>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMHiBeamLiFltFbLo_enum = 0U;/* Referenced by: '<S416>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMHiBeamLiFltFb_enum_ovrdflg = false;/* Referenced by: '<S416>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMHiBeamLiFltFb_enum_ovrdval = 0U;/* Referenced by: '<S416>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMHiBeamSwSigHi_enum = 3U;/* Referenced by: '<S417>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMHiBeamSwSigLo_enum = 0U;/* Referenced by: '<S417>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMHiBeamSwSig_enum_ovrdflg = false;/* Referenced by: '<S417>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMHiBeamSwSig_enum_ovrdval = 0U;/* Referenced by: '<S417>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte0Hi_nu = 255U;/* Referenced by: '<S11>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte0Lo_nu = 0U;/* Referenced by: '<S11>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte0_nu_ovrdflg = false;/* Referenced by: '<S11>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte0_nu_ovrdval = 0U;/* Referenced by: '<S11>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte10Hi_nu = 255U;/* Referenced by: '<S12>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte10Lo_nu = 0U;/* Referenced by: '<S12>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte10_nu_ovrdflg = false;/* Referenced by: '<S12>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte10_nu_ovrdval = 0U;/* Referenced by: '<S12>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte11Hi_nu = 255U;/* Referenced by: '<S13>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte11Lo_nu = 0U;/* Referenced by: '<S13>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte11_nu_ovrdflg = false;/* Referenced by: '<S13>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte11_nu_ovrdval = 0U;/* Referenced by: '<S13>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte12Hi_nu = 255U;/* Referenced by: '<S14>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte12Lo_nu = 0U;/* Referenced by: '<S14>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte12_nu_ovrdflg = false;/* Referenced by: '<S14>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte12_nu_ovrdval = 0U;/* Referenced by: '<S14>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte13Hi_nu = 255U;/* Referenced by: '<S15>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte13Lo_nu = 0U;/* Referenced by: '<S15>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte13_nu_ovrdflg = false;/* Referenced by: '<S15>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte13_nu_ovrdval = 0U;/* Referenced by: '<S15>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte14Hi_nu = 255U;/* Referenced by: '<S16>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte14Lo_nu = 0U;/* Referenced by: '<S16>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte14_nu_ovrdflg = false;/* Referenced by: '<S16>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte14_nu_ovrdval = 0U;/* Referenced by: '<S16>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte15Hi_nu = 255U;/* Referenced by: '<S17>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte15Lo_nu = 0U;/* Referenced by: '<S17>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte15_nu_ovrdflg = false;/* Referenced by: '<S17>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte15_nu_ovrdval = 0U;/* Referenced by: '<S17>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte1Hi_nu = 255U;/* Referenced by: '<S18>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte1Lo_nu = 0U;/* Referenced by: '<S18>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte1_nu_ovrdflg = false;/* Referenced by: '<S18>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte1_nu_ovrdval = 0U;/* Referenced by: '<S18>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte2Hi_nu = 255U;/* Referenced by: '<S19>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte2Lo_nu = 0U;/* Referenced by: '<S19>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte2_nu_ovrdflg = false;/* Referenced by: '<S19>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte2_nu_ovrdval = 0U;/* Referenced by: '<S19>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte3Hi_nu = 255U;/* Referenced by: '<S20>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte3Lo_nu = 0U;/* Referenced by: '<S20>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte3_nu_ovrdflg = false;/* Referenced by: '<S20>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte3_nu_ovrdval = 0U;/* Referenced by: '<S20>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte4Hi_nu = 255U;/* Referenced by: '<S21>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte4Lo_nu = 0U;/* Referenced by: '<S21>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte4_nu_ovrdflg = false;/* Referenced by: '<S21>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte4_nu_ovrdval = 0U;/* Referenced by: '<S21>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte5Hi_nu = 255U;/* Referenced by: '<S22>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte5Lo_nu = 0U;/* Referenced by: '<S22>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte5_nu_ovrdflg = false;/* Referenced by: '<S22>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte5_nu_ovrdval = 0U;/* Referenced by: '<S22>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte6Hi_nu = 255U;/* Referenced by: '<S23>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte6Lo_nu = 0U;/* Referenced by: '<S23>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte6_nu_ovrdflg = false;/* Referenced by: '<S23>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte6_nu_ovrdval = 0U;/* Referenced by: '<S23>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte7Hi_nu = 255U;/* Referenced by: '<S24>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte7Lo_nu = 0U;/* Referenced by: '<S24>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte7_nu_ovrdflg = false;/* Referenced by: '<S24>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte7_nu_ovrdval = 0U;/* Referenced by: '<S24>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte8Hi_nu = 255U;/* Referenced by: '<S25>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte8Lo_nu = 0U;/* Referenced by: '<S25>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte8_nu_ovrdflg = false;/* Referenced by: '<S25>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte8_nu_ovrdval = 0U;/* Referenced by: '<S25>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte9Hi_nu = 255U;/* Referenced by: '<S26>/sat6' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte9Lo_nu = 0U;/* Referenced by: '<S26>/sat7' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte9_nu_ovrdflg = false;/* Referenced by: '<S26>/sat3' */

/* BCM_HFSData_BAC */
CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte9_nu_ovrdval = 0U;/* Referenced by: '<S26>/sat4' */

/* BCM_HFSData_BAC */
CALDATA const volatile boolean KOPM_BCMHighBeamSta_flg_ovrdflg = false;/* Referenced by: '<S418>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMHighBeamSta_flg_ovrdval = false;/* Referenced by: '<S418>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMHvyRainInd_flg_ovrdflg = false;/* Referenced by: '<S419>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMHvyRainInd_flg_ovrdval = false;/* Referenced by: '<S419>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMHzrdWrngLghtSwSig_flg_ovrdflg = false;/* Referenced by: '<S420>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMHzrdWrngLghtSwSig_flg_ovrdval = false;/* Referenced by: '<S420>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMIllmndEntryStsFb_flg_ovrdflg = false;/* Referenced by: '<S421>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMIllmndEntryStsFb_flg_ovrdval = false;/* Referenced by: '<S421>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMIllmndLampReq_flg_ovrdflg = false;/* Referenced by: '<S422>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMIllmndLampReq_flg_ovrdval = false;/* Referenced by: '<S422>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMIllmndLckStsFb_flg_ovrdflg = false;/* Referenced by: '<S219>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_BCMIllmndLckStsFb_flg_ovrdval = false;/* Referenced by: '<S219>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMIllmndLockReqHi_enum = 3U;/* Referenced by: '<S423>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMIllmndLockReqLo_enum = 0U;/* Referenced by: '<S423>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMIllmndLockReq_enum_ovrdflg = false;/* Referenced by: '<S423>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMIllmndLockReq_enum_ovrdval = 0U;/* Referenced by: '<S423>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMIllmndStsHi_enum = 3U;/* Referenced by: '<S424>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMIllmndStsLo_enum = 0U;/* Referenced by: '<S424>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMIllmndSts_enum_ovrdflg = false;/* Referenced by: '<S424>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMIllmndSts_enum_ovrdval = 0U;/* Referenced by: '<S424>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMIllmndUnlckStsFb_flg_ovrdflg = false;/* Referenced by: '<S220>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_BCMIllmndUnlckStsFb_flg_ovrdval = false;/* Referenced by: '<S220>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_BCMIndcnKeyClsr_flg_ovrdflg = false;/* Referenced by: '<S425>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMIndcnKeyClsr_flg_ovrdval = false;/* Referenced by: '<S425>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMIndcnShfttoNeut_flg_ovrdflg = false;/* Referenced by: '<S426>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMIndcnShfttoNeut_flg_ovrdval = false;/* Referenced by: '<S426>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile float32 KOPM_BCMKeyBattLvlHi_pct = 100.0F;/* Referenced by: '<S428>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile float32 KOPM_BCMKeyBattLvlLo_pct = 0.0F;/* Referenced by: '<S428>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMKeyBattLvlSts_flg_ovrdflg = false;/* Referenced by: '<S427>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMKeyBattLvlSts_flg_ovrdval = false;/* Referenced by: '<S427>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMKeyBattLvl_pct_ovrdflg = false;/* Referenced by: '<S428>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile float32 KOPM_BCMKeyBattLvl_pct_ovrdval = 0.0F;/* Referenced by: '<S428>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMKeyFrbdn_flg_ovrdflg = false;/* Referenced by: '<S429>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMKeyFrbdn_flg_ovrdval = false;/* Referenced by: '<S429>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMKeyIDFbHi_enum = 3U;/* Referenced by: '<S430>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMKeyIDFbLo_enum = 0U;/* Referenced by: '<S430>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMKeyIDFb_enum_ovrdflg = false;/* Referenced by: '<S430>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMKeyIDFb_enum_ovrdval = 0U;/* Referenced by: '<S430>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMKeyInCarSta_flg_ovrdflg = false;/* Referenced by: '<S431>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMKeyInCarSta_flg_ovrdval = false;/* Referenced by: '<S431>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMKeyLoBattLvlWarn_flg_ovrdflg = false;/* Referenced by: '<S432>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMKeyLoBattLvlWarn_flg_ovrdval = false;/* Referenced by: '<S432>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint16 KOPM_BCMKeyLocnHi_mm = 65535U;/* Referenced by: '<S433>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint16 KOPM_BCMKeyLocnLo_mm = 0U;/* Referenced by: '<S433>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMKeyLocn_mm_ovrdflg = false;/* Referenced by: '<S433>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint16 KOPM_BCMKeyLocn_mm_ovrdval = 0U;/* Referenced by: '<S433>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMKeyStaHi_enum = 3U;/* Referenced by: '<S434>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMKeyStaLo_enum = 0U;/* Referenced by: '<S434>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMKeySta_enum_ovrdflg = false;/* Referenced by: '<S434>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMKeySta_enum_ovrdval = 0U;/* Referenced by: '<S434>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMLFInitSta_flg_ovrdflg = false;/* Referenced by: '<S435>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMLFInitSta_flg_ovrdval = false;/* Referenced by: '<S435>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMLckHornOnStFb_flg_ovrdflg = false;/* Referenced by: '<S436>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMLckHornOnStFb_flg_ovrdval = false;/* Referenced by: '<S436>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLeTrnLiFltFbHi_enum = 3U;/* Referenced by: '<S437>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLeTrnLiFltFbLo_enum = 0U;/* Referenced by: '<S437>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMLeTrnLiFltFb_enum_ovrdflg = false;/* Referenced by: '<S437>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLeTrnLiFltFb_enum_ovrdval = 0U;/* Referenced by: '<S437>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLghtSwSigHi_enum = 3U;/* Referenced by: '<S438>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLghtSwSigLo_enum = 0U;/* Referenced by: '<S438>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMLghtSwSig_enum_ovrdflg = false;/* Referenced by: '<S438>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLghtSwSig_enum_ovrdval = 0U;/* Referenced by: '<S438>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLightIntensityHi_enum = 3U;/* Referenced by: '<S439>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLightIntensityLo_enum = 0U;/* Referenced by: '<S439>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMLightIntensity_enum_ovrdflg = false;/* Referenced by: '<S439>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLightIntensity_enum_ovrdval = 0U;/* Referenced by: '<S439>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLoBeamLiFltFbHi_enum = 3U;/* Referenced by: '<S440>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLoBeamLiFltFbLo_enum = 0U;/* Referenced by: '<S440>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMLoBeamLiFltFb_enum_ovrdflg = false;/* Referenced by: '<S440>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLoBeamLiFltFb_enum_ovrdval = 0U;/* Referenced by: '<S440>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLogoActvFlgHi_enum = 3U;/* Referenced by: '<S441>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLogoActvFlgLo_enum = 0U;/* Referenced by: '<S441>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMLogoActvFlg_enum_ovrdflg = false;/* Referenced by: '<S441>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLogoActvFlg_enum_ovrdval = 0U;/* Referenced by: '<S441>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMLowBeamSta_flg_ovrdflg = false;/* Referenced by: '<S442>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMLowBeamSta_flg_ovrdval = false;/* Referenced by: '<S442>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMLrngData02Hi_nu = 255U;/* Referenced by: '<S146>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData02Lo_nu = 0U;/* Referenced by: '<S146>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile boolean KOPM_BCMLrngData02_nu_ovrdflg = false;/* Referenced by: '<S146>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData02_nu_ovrdval = 0U;/* Referenced by: '<S146>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData03Hi_nu = 255U;/* Referenced by: '<S147>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData03Lo_nu = 0U;/* Referenced by: '<S147>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile boolean KOPM_BCMLrngData03_nu_ovrdflg = false;/* Referenced by: '<S147>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData03_nu_ovrdval = 0U;/* Referenced by: '<S147>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData04Hi_nu = 255U;/* Referenced by: '<S148>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData04Lo_nu = 0U;/* Referenced by: '<S148>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile boolean KOPM_BCMLrngData04_nu_ovrdflg = false;/* Referenced by: '<S148>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData04_nu_ovrdval = 0U;/* Referenced by: '<S148>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData05Hi_nu = 255U;/* Referenced by: '<S149>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData05Lo_nu = 0U;/* Referenced by: '<S149>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile boolean KOPM_BCMLrngData05_nu_ovrdflg = false;/* Referenced by: '<S149>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData05_nu_ovrdval = 0U;/* Referenced by: '<S149>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData06Hi_nu = 255U;/* Referenced by: '<S150>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData06Lo_nu = 0U;/* Referenced by: '<S150>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile boolean KOPM_BCMLrngData06_nu_ovrdflg = false;/* Referenced by: '<S150>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData06_nu_ovrdval = 0U;/* Referenced by: '<S150>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData07Hi_nu = 255U;/* Referenced by: '<S151>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData07Lo_nu = 0U;/* Referenced by: '<S151>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile boolean KOPM_BCMLrngData07_nu_ovrdflg = false;/* Referenced by: '<S151>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngData07_nu_ovrdval = 0U;/* Referenced by: '<S151>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngStsHi_enum = 255U;/* Referenced by: '<S152>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngStsLo_enum = 0U;/* Referenced by: '<S152>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile boolean KOPM_BCMLrngSts_enum_ovrdflg = false;/* Referenced by: '<S152>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngSts_enum_ovrdval = 0U;/* Referenced by: '<S152>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngsubIDHi_cnt = 255U;/* Referenced by: '<S153>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngsubIDLo_cnt = 0U;/* Referenced by: '<S153>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile boolean KOPM_BCMLrngsubID_cnt_ovrdflg = false;/* Referenced by: '<S153>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMLrngsubID_cnt_ovrdval = 0U;/* Referenced by: '<S153>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
CALDATA const volatile uint8 KOPM_BCMMaiDrvrSeatStsHi_enum = 3U;/* Referenced by: '<S443>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMMaiDrvrSeatStsLo_enum = 0U;/* Referenced by: '<S443>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMMaiDrvrSeatSts_enum_ovrdflg = false;/* Referenced by: '<S443>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMMaiDrvrSeatSts_enum_ovrdval = 0U;/* Referenced by: '<S443>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile float32 KOPM_BCMMaiDrvrSeatTempHi_C = 87.0F;/* Referenced by: '<S444>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile float32 KOPM_BCMMaiDrvrSeatTempLo_C = -40.0F;/* Referenced by: '<S444>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMMaiDrvrSeatTemp_C_ovrdflg = false;/* Referenced by: '<S444>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile float32 KOPM_BCMMaiDrvrSeatTemp_C_ovrdval = 0.0F;/* Referenced by: '<S444>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMOvrspdCntrlLckSetFb_flg_ovrdflg = false;/* Referenced by: '<S445>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMOvrspdCntrlLckSetFb_flg_ovrdval = false;/* Referenced by: '<S445>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMPSAuthentResHi_enum = 3U;/* Referenced by: '<S446>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMPSAuthentResLo_enum = 0U;/* Referenced by: '<S446>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMPSAuthentRes_enum_ovrdflg = false;/* Referenced by: '<S446>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMPSAuthentRes_enum_ovrdval = 0U;/* Referenced by: '<S446>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMPSReq_flg_ovrdflg = false;/* Referenced by: '<S447>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMPSReq_flg_ovrdval = false;/* Referenced by: '<S447>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMParkAutoUnlckSetFb_flg_ovrdflg = false;/* Referenced by: '<S448>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMParkAutoUnlckSetFb_flg_ovrdval = false;/* Referenced by: '<S448>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMPassWinSwSigHi_enum = 7U;/* Referenced by: '<S449>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMPassWinSwSigLo_enum = 0U;/* Referenced by: '<S449>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMPassWinSwSig_enum_ovrdflg = false;/* Referenced by: '<S449>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMPassWinSwSig_enum_ovrdval = 0U;/* Referenced by: '<S449>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMPaswdwInit_flg_ovrdflg = false;/* Referenced by: '<S450>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMPaswdwInit_flg_ovrdval = false;/* Referenced by: '<S450>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMPosLampSta_flg_ovrdflg = false;/* Referenced by: '<S356>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_BCMPosLampSta_flg_ovrdval = false;/* Referenced by: '<S356>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMPosLiFltFbHi_enum = 3U;/* Referenced by: '<S451>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMPosLiFltFbLo_enum = 0U;/* Referenced by: '<S451>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMPosLiFltFb_enum_ovrdflg = false;/* Referenced by: '<S451>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMPosLiFltFb_enum_ovrdval = 0U;/* Referenced by: '<S451>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMRFInitSta_flg_ovrdflg = false;/* Referenced by: '<S452>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMRFInitSta_flg_ovrdval = false;/* Referenced by: '<S452>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMRKEReqHi_enum = 7U;/* Referenced by: '<S453>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMRKEReqLo_enum = 0U;/* Referenced by: '<S453>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMRKEReq_enum_ovrdflg = false;/* Referenced by: '<S453>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMRKEReq_enum_ovrdval = 0U;/* Referenced by: '<S453>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMReverseLampSta_flg_ovrdflg = false;/* Referenced by: '<S454>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMReverseLampSta_flg_ovrdval = false;/* Referenced by: '<S454>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMRiTrnLiFltFbHi_enum = 3U;/* Referenced by: '<S455>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMRiTrnLiFltFbLo_enum = 0U;/* Referenced by: '<S455>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMRiTrnLiFltFb_enum_ovrdflg = false;/* Referenced by: '<S455>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMRiTrnLiFltFb_enum_ovrdval = 0U;/* Referenced by: '<S455>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMRrFogLiFltFbHi_enum = 3U;/* Referenced by: '<S456>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMRrFogLiFltFbLo_enum = 0U;/* Referenced by: '<S456>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMRrFogLiFltFb_enum_ovrdflg = false;/* Referenced by: '<S456>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMRrFogLiFltFb_enum_ovrdval = 0U;/* Referenced by: '<S456>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMRrFogLiSwSig_flg_ovrdflg = false;/* Referenced by: '<S457>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMRrFogLiSwSig_flg_ovrdval = false;/* Referenced by: '<S457>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMRrMirrHeatSts_flg_ovrdflg = false;/* Referenced by: '<S458>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMRrMirrHeatSts_flg_ovrdval = false;/* Referenced by: '<S458>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMRrViewMirrHeatgSts_flg_ovrdflg = false;/* Referenced by: '<S100>/sat3' */

/* AC_ACStatuts_BOD */
CALDATA const volatile boolean KOPM_BCMRrViewMirrHeatgSts_flg_ovrdval = false;/* Referenced by: '<S100>/sat4' */

/* AC_ACStatuts_BOD */
CALDATA const volatile uint8 KOPM_BCMRvrsLiFltFbHi_enum = 3U;/* Referenced by: '<S459>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMRvrsLiFltFbLo_enum = 0U;/* Referenced by: '<S459>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMRvrsLiFltFb_enum_ovrdflg = false;/* Referenced by: '<S459>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMRvrsLiFltFb_enum_ovrdval = 0U;/* Referenced by: '<S459>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMSavePwrSt_flg_ovrdflg = false;/* Referenced by: '<S460>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMSavePwrSt_flg_ovrdval = false;/* Referenced by: '<S460>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMStartReqHi_enum = 3U;/* Referenced by: '<S461>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMStartReqLo_enum = 0U;/* Referenced by: '<S461>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMStartReq_enum_ovrdflg = false;/* Referenced by: '<S461>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMStartReq_enum_ovrdval = 0U;/* Referenced by: '<S461>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMSteerWhlHeatStsHi_flg = true;/* Referenced by: '<S462>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMSteerWhlHeatStsLo_flg = false;/* Referenced by: '<S462>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMSteerWhlHeatSts_flg_ovrdflg = false;/* Referenced by: '<S462>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMSteerWhlHeatSts_flg_ovrdval = false;/* Referenced by: '<S462>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile float32 KOPM_BCMSteerWhlTempHi_C = 87.0F;/* Referenced by: '<S463>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile float32 KOPM_BCMSteerWhlTempLo_C = -40.0F;/* Referenced by: '<S463>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMSteerWhlTemp_C_ovrdflg = false;/* Referenced by: '<S463>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile float32 KOPM_BCMSteerWhlTemp_C_ovrdval = 0.0F;/* Referenced by: '<S463>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMSysPowerStsHi_enum = 7U;/* Referenced by: '<S357>/sat6' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMSysPowerStsLo_enum = 0U;/* Referenced by: '<S357>/sat7' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_BCMSysPowerSts_enum_ovrdflg = false;/* Referenced by: '<S357>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMSysPowerSts_enum_ovrdval = 0U;/* Referenced by: '<S357>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMSysPwrModeHi_enum = 3U;/* Referenced by: '<S359>/sat6' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMSysPwrModeLo_enum = 0U;/* Referenced by: '<S359>/sat7' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_BCMSysPwrModeVld_flg_ovrdflg = false;/* Referenced by: '<S358>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_BCMSysPwrModeVld_flg_ovrdval = false;/* Referenced by: '<S358>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_BCMSysPwrMode_enum_ovrdflg = false;/* Referenced by: '<S359>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMSysPwrMode_enum_ovrdval = 0U;/* Referenced by: '<S359>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_BCMTPMSRstStsHi_enum = 3U;/* Referenced by: '<S464>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMTPMSRstStsLo_enum = 0U;/* Referenced by: '<S464>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTPMSRstSts_enum_ovrdflg = false;/* Referenced by: '<S464>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMTPMSRstSts_enum_ovrdval = 0U;/* Referenced by: '<S464>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTrnkLckSta_flg_ovrdflg = false;/* Referenced by: '<S465>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTrnkLckSta_flg_ovrdval = false;/* Referenced by: '<S465>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTrnkLckSwCtrlFb_flg_ovrdflg = false;/* Referenced by: '<S466>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTrnkLckSwCtrlFb_flg_ovrdval = false;/* Referenced by: '<S466>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMTrnngLiSwSigHi_enum = 3U;/* Referenced by: '<S467>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMTrnngLiSwSigLo_enum = 0U;/* Referenced by: '<S467>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTrnngLiSwSig_enum_ovrdflg = false;/* Referenced by: '<S467>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMTrnngLiSwSig_enum_ovrdval = 0U;/* Referenced by: '<S467>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTrunkSwtSig_flg_ovrdflg = false;/* Referenced by: '<S468>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTrunkSwtSig_flg_ovrdval = false;/* Referenced by: '<S468>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTurnLampStaLeft_flg_ovrdflg = false;/* Referenced by: '<S469>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTurnLampStaLeft_flg_ovrdval = false;/* Referenced by: '<S469>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTurnLampStaRight_flg_ovrdflg = false;/* Referenced by: '<S470>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTurnLampStaRight_flg_ovrdval = false;/* Referenced by: '<S470>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMTurnLiStsHi_enum = 7U;/* Referenced by: '<S471>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMTurnLiStsLo_enum = 0U;/* Referenced by: '<S471>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMTurnLiSts_enum_ovrdflg = false;/* Referenced by: '<S471>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMTurnLiSts_enum_ovrdval = 0U;/* Referenced by: '<S471>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMVehSeek_flg_ovrdflg = false;/* Referenced by: '<S472>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMVehSeek_flg_ovrdval = false;/* Referenced by: '<S472>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWarnKeyOutRmndr_flg_ovrdflg = false;/* Referenced by: '<S473>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWarnKeyOutRmndr_flg_ovrdval = false;/* Referenced by: '<S473>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWarnNoKeyFound_flg_ovrdflg = false;/* Referenced by: '<S474>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWarnNoKeyFound_flg_ovrdval = false;/* Referenced by: '<S474>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWashLiquidLvlWarn_flg_ovrdflg = false;/* Referenced by: '<S475>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWashLiquidLvlWarn_flg_ovrdval = false;/* Referenced by: '<S475>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWinLockSig_flg_ovrdflg = false;/* Referenced by: '<S476>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWinLockSig_flg_ovrdval = false;/* Referenced by: '<S476>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWinLockSts_flg_ovrdflg = false;/* Referenced by: '<S477>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWinLockSts_flg_ovrdval = false;/* Referenced by: '<S477>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMWiperCtrlFrontHi_enum = 7U;/* Referenced by: '<S478>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMWiperCtrlFrontLo_enum = 0U;/* Referenced by: '<S478>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWiperCtrlFront_enum_ovrdflg = false;/* Referenced by: '<S478>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMWiperCtrlFront_enum_ovrdval = 0U;/* Referenced by: '<S478>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMWiperSwSigHi_enum = 7U;/* Referenced by: '<S479>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMWiperSwSigLo_enum = 0U;/* Referenced by: '<S479>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWiperSwSig_enum_ovrdflg = false;/* Referenced by: '<S479>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMWiperSwSig_enum_ovrdval = 0U;/* Referenced by: '<S479>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMWiprIntlGrSwtSigHi_enum = 7U;/* Referenced by: '<S480>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMWiprIntlGrSwtSigLo_enum = 0U;/* Referenced by: '<S480>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWiprIntlGrSwtSig_enum_ovrdflg = false;/* Referenced by: '<S480>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMWiprIntlGrSwtSig_enum_ovrdval = 0U;/* Referenced by: '<S480>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMWiprIntlTimeSetFbHi_enum = 7U;/* Referenced by: '<S481>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMWiprIntlTimeSetFbLo_enum = 0U;/* Referenced by: '<S481>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWiprIntlTimeSetFb_enum_ovrdflg = false;/* Referenced by: '<S481>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BCMWiprIntlTimeSetFb_enum_ovrdval = 0U;/* Referenced by: '<S481>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWiprStopPstnSt_flg_ovrdflg = false;/* Referenced by: '<S482>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_BCMWiprStopPstnSt_flg_ovrdval = false;/* Referenced by: '<S482>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_BMSShutdownHi_enum = 3U;/* Referenced by: '<S325>/sat6' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile uint8 KOPM_BMSShutdownLo_enum = 0U;/* Referenced by: '<S325>/sat7' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile boolean KOPM_BMSShutdown_enum_ovrdflg = false;/* Referenced by: '<S325>/sat3' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile EnumBMSSdnCmd KOPM_BMSShutdown_enum_ovrdval =
  EnumBMSSdnCmd_Normal;                /* Referenced by: '<S325>/sat4' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile uint8 KOPM_BMSWakeupModeHi_enum = 3U;/* Referenced by: '<S319>/sat6' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile uint8 KOPM_BMSWakeupModeLo_enum = 0U;/* Referenced by: '<S319>/sat7' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_BMSWakeupMode_enum_ovrdflg = false;/* Referenced by: '<S319>/sat3' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile EnumBMSWakeUpMd KOPM_BMSWakeupMode_enum_ovrdval =
  EnumBMSWakeUpMd_Invld;               /* Referenced by: '<S319>/sat4' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_Bat2DrvTrainEnb_flg_ovrdflg = false;/* Referenced by: '<S320>/sat3' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_Bat2DrvTrainEnb_flg_ovrdval = false;/* Referenced by: '<S320>/sat4' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_BraSwi_flg_ovrdflg = false;/* Referenced by: '<S192>/sat3' */

/* VCU_0_Value_EPT */
CALDATA const volatile boolean KOPM_BraSwi_flg_ovrdval = false;/* Referenced by: '<S192>/sat4' */

/* VCU_0_Value_EPT */
CALDATA const volatile uint8 KOPM_BrkPedSnsrPosVRsrvdHi_enum = 3U;/* Referenced by: '<S284>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_BrkPedSnsrPosVRsrvdLo_enum = 0U;/* Referenced by: '<S284>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_BrkPedSnsrPosVRsrvd_enum_ovrdflg = false;/* Referenced by: '<S284>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_BrkPedSnsrPosVRsrvd_enum_ovrdval = 0U;/* Referenced by: '<S284>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_BrkPedalPosHi_pct = 100.0F;/* Referenced by: '<S285>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_BrkPedalPosLo_pct = 0.0F;/* Referenced by: '<S285>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_BrkPedalPos_pct_ovrdflg = false;/* Referenced by: '<S285>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_BrkPedalPos_pct_ovrdval = 0.0F;/* Referenced by: '<S285>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_BrkPwrRecupActWhlTqHi_Nm = 0.0F;/* Referenced by: '<S163>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_BrkPwrRecupActWhlTqLo_Nm = -6200.0F;/* Referenced by: '<S163>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_BrkPwrRecupActWhlTq_Nm_ovrdflg = false;/* Referenced by: '<S163>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_BrkPwrRecupActWhlTq_Nm_ovrdval = 0.0F;/* Referenced by: '<S163>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile uint8 KOPM_BrkPwrRecupActlWhlTqStsHi_enum = 3U;/* Referenced by: '<S164>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile uint8 KOPM_BrkPwrRecupActlWhlTqStsLo_enum = 0U;/* Referenced by: '<S164>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_BrkPwrRecupActlWhlTqSts_enum_ovrdflg = false;/* Referenced by: '<S164>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile uint8 KOPM_BrkPwrRecupActlWhlTqSts_enum_ovrdval = 0U;/* Referenced by: '<S164>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_BrkPwrRecupMaxAvlbWhlTqHi_Nm = 0.0F;/* Referenced by: '<S165>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_BrkPwrRecupMaxAvlbWhlTqLo_Nm = -32768.0F;/* Referenced by: '<S165>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_BrkPwrRecupMaxAvlbWhlTq_Nm_ovrdflg = false;/* Referenced by: '<S165>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_BrkPwrRecupMaxAvlbWhlTq_Nm_ovrdval = 0.0F;/* Referenced by: '<S165>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile uint8 KOPM_CCKeyStgntnHi_enum = 3U;/* Referenced by: '<S221>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_CCKeyStgntnLo_enum = 0U;/* Referenced by: '<S221>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_CCKeyStgntn_enum_ovrdflg = false;/* Referenced by: '<S221>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCKeyStgntn_enum_ovrdval = 0U;/* Referenced by: '<S221>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCUOpenVentnFbHi_enum = 3U;/* Referenced by: '<S222>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCUOpenVentnFbLo_enum = 0U;/* Referenced by: '<S222>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_CCUOpenVentnFb_enum_ovrdflg = false;/* Referenced by: '<S222>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCUOpenVentnFb_enum_ovrdval = 0U;/* Referenced by: '<S222>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCURmtCarSearchFbHi_enum = 3U;/* Referenced by: '<S223>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCURmtCarSearchFbLo_enum = 0U;/* Referenced by: '<S223>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_CCURmtCarSearchFb_enum_ovrdflg = false;/* Referenced by: '<S223>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCURmtCarSearchFb_enum_ovrdval = 0U;/* Referenced by: '<S223>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCURmtLckFbHi_enum = 3U;/* Referenced by: '<S224>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCURmtLckFbLo_enum = 0U;/* Referenced by: '<S224>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_CCURmtLckFb_enum_ovrdflg = false;/* Referenced by: '<S224>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCURmtLckFb_enum_ovrdval = 0U;/* Referenced by: '<S224>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCURmtPwrLckFbHi_enum = 3U;/* Referenced by: '<S225>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCURmtPwrLckFbLo_enum = 0U;/* Referenced by: '<S225>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_CCURmtPwrLckFb_enum_ovrdflg = false;/* Referenced by: '<S225>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CCURmtPwrLckFb_enum_ovrdval = 0U;/* Referenced by: '<S225>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_COMPCompInPwrLimHi_W = 25500.0F;/* Referenced by: '<S101>/sat6' */

/* AC_COMP_BOD */
CALDATA const volatile float32 KOPM_COMPCompInPwrLimLo_W = 0.0F;/* Referenced by: '<S101>/sat7' */

/* AC_COMP_BOD */
CALDATA const volatile boolean KOPM_COMPCompInPwrLim_W_ovrdflg = false;/* Referenced by: '<S101>/sat3' */

/* AC_COMP_BOD */
CALDATA const volatile float32 KOPM_COMPCompInPwrLim_W_ovrdval = 0.0F;/* Referenced by: '<S101>/sat4' */

/* AC_COMP_BOD */
CALDATA const volatile uint8 KOPM_COMPEcompEnblHi_enum = 3U;/* Referenced by: '<S102>/sat6' */

/* AC_COMP_BOD */
CALDATA const volatile uint8 KOPM_COMPEcompEnblLo_enum = 0U;/* Referenced by: '<S102>/sat7' */

/* AC_COMP_BOD */
CALDATA const volatile boolean KOPM_COMPEcompEnbl_enum_ovrdflg = false;/* Referenced by: '<S102>/sat3' */

/* AC_COMP_BOD */
CALDATA const volatile uint8 KOPM_COMPEcompEnbl_enum_ovrdval = 0U;/* Referenced by: '<S102>/sat4' */

/* AC_COMP_BOD */
CALDATA const volatile uint8 KOPM_COMPEcompErrCleanHi_enum = 3U;/* Referenced by: '<S103>/sat6' */

/* AC_COMP_BOD */
CALDATA const volatile uint8 KOPM_COMPEcompErrCleanLo_enum = 0U;/* Referenced by: '<S103>/sat7' */

/* AC_COMP_BOD */
CALDATA const volatile boolean KOPM_COMPEcompErrClean_enum_ovrdflg = false;/* Referenced by: '<S103>/sat3' */

/* AC_COMP_BOD */
CALDATA const volatile uint8 KOPM_COMPEcompErrClean_enum_ovrdval = 0U;/* Referenced by: '<S103>/sat4' */

/* AC_COMP_BOD */
CALDATA const volatile uint8 KOPM_COMPEcompHVStHi_enum = 3U;/* Referenced by: '<S104>/sat6' */

/* AC_COMP_BOD */
CALDATA const volatile uint8 KOPM_COMPEcompHVStLo_enum = 0U;/* Referenced by: '<S104>/sat7' */

/* AC_COMP_BOD */
CALDATA const volatile boolean KOPM_COMPEcompHVSt_enum_ovrdflg = false;/* Referenced by: '<S104>/sat3' */

/* AC_COMP_BOD */
CALDATA const volatile uint8 KOPM_COMPEcompHVSt_enum_ovrdval = 0U;/* Referenced by: '<S104>/sat4' */

/* AC_COMP_BOD */
CALDATA const volatile float32 KOPM_COMPEcompSpdCtrlHi_rpm = 12750.0F;/* Referenced by: '<S105>/sat6' */

/* AC_COMP_BOD */
CALDATA const volatile float32 KOPM_COMPEcompSpdCtrlLo_rpm = 0.0F;/* Referenced by: '<S105>/sat7' */

/* AC_COMP_BOD */
CALDATA const volatile boolean KOPM_COMPEcompSpdCtrl_rpm_ovrdflg = false;/* Referenced by: '<S105>/sat3' */

/* AC_COMP_BOD */
CALDATA const volatile float32 KOPM_COMPEcompSpdCtrl_rpm_ovrdval = 0.0F;/* Referenced by: '<S105>/sat4' */

/* AC_COMP_BOD */
CALDATA const volatile uint8 KOPM_ChrgAllowCmdHi_enum = 3U;/* Referenced by: '<S326>/sat6' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile uint8 KOPM_ChrgAllowCmdLo_enum = 0U;/* Referenced by: '<S326>/sat7' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile boolean KOPM_ChrgAllowCmd_enum_ovrdflg = false;/* Referenced by: '<S326>/sat3' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile EnumChrgAllwCmd KOPM_ChrgAllowCmd_enum_ovrdval =
  EnumChrgAllwCmd_NotAllwd;            /* Referenced by: '<S326>/sat4' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile uint8 KOPM_ChrgEnaACHi_enum = 3U;/* Referenced by: '<S321>/sat6' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile uint8 KOPM_ChrgEnaACLo_enum = 0U;/* Referenced by: '<S321>/sat7' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_ChrgEnaAC_enum_ovrdflg = false;/* Referenced by: '<S321>/sat3' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile EnumChrgEnaAC KOPM_ChrgEnaAC_enum_ovrdval =
  EnumChrgEnaAC_Disable;               /* Referenced by: '<S321>/sat4' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_ChrgEnaDC_flg_ovrdflg = false;/* Referenced by: '<S327>/sat3' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile boolean KOPM_ChrgEnaDC_flg_ovrdval = false;/* Referenced by: '<S327>/sat4' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile boolean KOPM_ChrgngCondsFb_flg_ovrdflg = false;/* Referenced by: '<S226>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_ChrgngCondsFb_flg_ovrdval = false;/* Referenced by: '<S226>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_CruiseCtrTgtSpdHi_kph = 461.0F;/* Referenced by: '<S227>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_CruiseCtrTgtSpdLo_kph = 0.0F;/* Referenced by: '<S227>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_CruiseCtrTgtSpd_kph_ovrdflg = false;/* Referenced by: '<S227>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_CruiseCtrTgtSpd_kph_ovrdval = 0.0F;/* Referenced by: '<S227>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CruiseCtrlStaHi_enum = 7U;/* Referenced by: '<S228>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CruiseCtrlStaLo_enum = 0U;/* Referenced by: '<S228>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_CruiseCtrlSta_enum_ovrdflg = false;/* Referenced by: '<S228>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_CruiseCtrlSta_enum_ovrdval = 0U;/* Referenced by: '<S228>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_DCCBoostHvVoltHi_V = 1023.0F;/* Referenced by: '<S338>/sat6' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_DCCBoostHvVoltLo_V = 0.0F;/* Referenced by: '<S338>/sat7' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_DCCBoostHvVolt_V_ovrdflg = false;/* Referenced by: '<S338>/sat3' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_DCCBoostHvVolt_V_ovrdval = 0.0F;/* Referenced by: '<S338>/sat4' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_DCCBuckLVVoltHi_V = 25.5F;/* Referenced by: '<S339>/sat6' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_DCCBuckLVVoltLo_V = 0.0F;/* Referenced by: '<S339>/sat7' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_DCCBuckLVVolt_V_ovrdflg = false;/* Referenced by: '<S339>/sat3' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_DCCBuckLVVolt_V_ovrdval = 0.0F;/* Referenced by: '<S339>/sat4' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile uint8 KOPM_DCCOprtCmdHi_enum = 7U;/* Referenced by: '<S334>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_DCCOprtCmdLo_enum = 0U;/* Referenced by: '<S334>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_DCCOprtCmd_enum_ovrdflg = false;/* Referenced by: '<S334>/sat3' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile EnumDCCOprtCmd KOPM_DCCOprtCmd_enum_ovrdval =
  EnumDCCOprtCmd_Off;                  /* Referenced by: '<S334>/sat4' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_DrvLfAntDiagStatHi_enum = 3U;/* Referenced by: '<S483>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_DrvLfAntDiagStatLo_enum = 0U;/* Referenced by: '<S483>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_DrvLfAntDiagStat_enum_ovrdflg = false;/* Referenced by: '<S483>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_DrvLfAntDiagStat_enum_ovrdval = 0U;/* Referenced by: '<S483>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_DrvModeKeyStgntnHi_enum = 3U;/* Referenced by: '<S229>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_DrvModeKeyStgntnLo_enum = 0U;/* Referenced by: '<S229>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_DrvModeKeyStgntn_enum_ovrdflg = false;/* Referenced by: '<S229>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_DrvModeKeyStgntn_enum_ovrdval = 0U;/* Referenced by: '<S229>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_DrvMotorStaHi_enum = 255U;/* Referenced by: '<S230>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_DrvMotorStaLo_enum = 0U;/* Referenced by: '<S230>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_DrvMotorSta_enum_ovrdflg = false;/* Referenced by: '<S230>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_DrvMotorSta_enum_ovrdval = 0U;/* Referenced by: '<S230>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_DrvPedHi_pct = 102.3F;/* Referenced by: '<S193>/sat6' */

/* VCU_0_Value_EPT */
CALDATA const volatile float32 KOPM_DrvPedLo_pct = 0.0F;/* Referenced by: '<S193>/sat7' */

/* VCU_0_Value_EPT */
CALDATA const volatile boolean KOPM_DrvPed_pct_ovrdflg = false;/* Referenced by: '<S193>/sat3' */

/* VCU_0_Value_EPT */
CALDATA const volatile float32 KOPM_DrvPed_pct_ovrdval = 0.0F;/* Referenced by: '<S193>/sat4' */

/* VCU_0_Value_EPT */
CALDATA const volatile float32 KOPM_DrvRangeDistEstHi_km = 1023.0F;/* Referenced by: '<S232>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile float32 KOPM_DrvRangeDistEstLo_km = 0.0F;/* Referenced by: '<S232>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_DrvRangeDistEstVld_flg_ovrdflg = false;/* Referenced by: '<S231>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_DrvRangeDistEstVld_flg_ovrdval = false;/* Referenced by: '<S231>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_DrvRangeDistEst_km_ovrdflg = false;/* Referenced by: '<S232>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_DrvRangeDistEst_km_ovrdval = 0.0F;/* Referenced by: '<S232>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_DrvReqMotorTorqHi_Nm = 1000.0F;/* Referenced by: '<S167>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_DrvReqMotorTorqLo_Nm = -1000.0F;/* Referenced by: '<S167>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_DrvReqMotorTorqVld_flg_ovrdflg = false;/* Referenced by: '<S166>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_DrvReqMotorTorqVld_flg_ovrdval = false;/* Referenced by: '<S166>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_DrvReqMotorTorq_Nm_ovrdflg = false;/* Referenced by: '<S167>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_DrvReqMotorTorq_Nm_ovrdval = 0.0F;/* Referenced by: '<S167>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_DrvReqTorqOverrideFCM_flg_ovrdflg = false;/* Referenced by: '<S286>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_DrvReqTorqOverrideFCM_flg_ovrdval = false;/* Referenced by: '<S286>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_DrvReqTorqOvrdESC_flg_ovrdflg = false;/* Referenced by: '<S287>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_DrvReqTorqOvrdESC_flg_ovrdval = false;/* Referenced by: '<S287>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_DrvReqWhlTqHi_Nm = 6200.0F;/* Referenced by: '<S169>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_DrvReqWhlTqLo_Nm = -6200.0F;/* Referenced by: '<S169>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_DrvReqWhlTqVld_flg_ovrdflg = false;/* Referenced by: '<S168>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_DrvReqWhlTqVld_flg_ovrdval = false;/* Referenced by: '<S168>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_DrvReqWhlTq_Nm_ovrdflg = false;/* Referenced by: '<S169>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_DrvReqWhlTq_Nm_ovrdval = 0.0F;/* Referenced by: '<S169>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_DrvSwi_flg_ovrdflg = false;/* Referenced by: '<S194>/sat3' */

/* VCU_0_Value_EPT */
CALDATA const volatile boolean KOPM_DrvSwi_flg_ovrdval = false;/* Referenced by: '<S194>/sat4' */

/* VCU_0_Value_EPT */
CALDATA const volatile float32 KOPM_DrvWhlTqAllwdMaxHi_Nm = 6200.0F;/* Referenced by: '<S170>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_DrvWhlTqAllwdMaxLo_Nm = 0.0F;/* Referenced by: '<S170>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_DrvWhlTqAllwdMax_Nm_ovrdflg = false;/* Referenced by: '<S170>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_DrvWhlTqAllwdMax_Nm_ovrdval = 0.0F;/* Referenced by: '<S170>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile uint64 KOPM_ESCLUnOrLockCrtlHi_nu =
  (18446744073709500416ULL);           /* Referenced by: '<S112>/sat6' */

/* BCM_ESCLCommand_BOD */
CALDATA const volatile uint64 KOPM_ESCLUnOrLockCrtlLo_nu = (0ULL);/* Referenced by: '<S112>/sat7' */

/* BCM_ESCLCommand_BOD */
CALDATA const volatile boolean KOPM_ESCLUnOrLockCrtl_nu_ovrdflg = false;/* Referenced by: '<S112>/sat3' */

/* BCM_ESCLCommand_BOD */
CALDATA const volatile uint64 KOPM_ESCLUnOrLockCrtl_nu_ovrdval = (0ULL);/* Referenced by: '<S112>/sat4' */

/* BCM_ESCLCommand_BOD */
CALDATA const volatile boolean KOPM_EmgcySdn_flg_ovrdflg = false;/* Referenced by: '<S199>/sat3' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile boolean KOPM_EmgcySdn_flg_ovrdval = false;/* Referenced by: '<S199>/sat4' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile boolean KOPM_EnaDisChg_flg_ovrdflg = false;/* Referenced by: '<S200>/sat3' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile boolean KOPM_EnaDisChg_flg_ovrdval = false;/* Referenced by: '<S200>/sat4' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile boolean KOPM_EnaInvRun_flg_ovrdflg = false;/* Referenced by: '<S201>/sat3' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile boolean KOPM_EnaInvRun_flg_ovrdval = false;/* Referenced by: '<S201>/sat4' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile uint8 KOPM_ErrAmountHi_cnt = 127U;/* Referenced by: '<S335>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_ErrAmountLo_cnt = 0U;/* Referenced by: '<S335>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_ErrAmount_cnt_ovrdflg = false;/* Referenced by: '<S335>/sat3' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_ErrAmount_cnt_ovrdval = 0U;/* Referenced by: '<S335>/sat4' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint16 KOPM_ErrBitHi_nu = 1023U;/* Referenced by: '<S336>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint16 KOPM_ErrBitLo_nu = 0U;/* Referenced by: '<S336>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_ErrBit_nu_ovrdflg = false;/* Referenced by: '<S336>/sat3' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint16 KOPM_ErrBit_nu_ovrdval = 0U;/* Referenced by: '<S336>/sat4' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_GearShiftInhibited_flg_ovrdflg = false;/* Referenced by: '<S288>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_GearShiftInhibited_flg_ovrdval = false;/* Referenced by: '<S288>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_HDCStatHi_enum = 3U;/* Referenced by: '<S360>/sat6' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_HDCStatLo_enum = 0U;/* Referenced by: '<S360>/sat7' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_HDCStat_enum_ovrdflg = false;/* Referenced by: '<S360>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_HDCStat_enum_ovrdval = 0U;/* Referenced by: '<S360>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_HVCHEnbldHi_enum = 3U;/* Referenced by: '<S113>/sat6' */

/* HVCH_Command_BOD */
CALDATA const volatile uint8 KOPM_HVCHEnbldLo_enum = 0U;/* Referenced by: '<S113>/sat7' */

/* HVCH_Command_BOD */
CALDATA const volatile boolean KOPM_HVCHEnbld_enum_ovrdflg = false;/* Referenced by: '<S113>/sat3' */

/* HVCH_Command_BOD */
CALDATA const volatile uint8 KOPM_HVCHEnbld_enum_ovrdval = 0U;/* Referenced by: '<S113>/sat4' */

/* HVCH_Command_BOD */
CALDATA const volatile float32 KOPM_HVCHReqPwrHi_kW = 15.0F;/* Referenced by: '<S114>/sat6' */

/* HVCH_Command_BOD */
CALDATA const volatile float32 KOPM_HVCHReqPwrLo_kW = 0.0F;/* Referenced by: '<S114>/sat7' */

/* HVCH_Command_BOD */
CALDATA const volatile boolean KOPM_HVCHReqPwr_kW_ovrdflg = false;/* Referenced by: '<S114>/sat3' */

/* HVCH_Command_BOD */
CALDATA const volatile float32 KOPM_HVCHReqPwr_kW_ovrdval = 0.0F;/* Referenced by: '<S114>/sat4' */

/* HVCH_Command_BOD */
CALDATA const volatile float32 KOPM_HVCHReqTempHi_C = 215.0F;/* Referenced by: '<S115>/sat6' */

/* HVCH_Command_BOD */
CALDATA const volatile float32 KOPM_HVCHReqTempLo_C = -40.0F;/* Referenced by: '<S115>/sat7' */

/* HVCH_Command_BOD */
CALDATA const volatile boolean KOPM_HVCHReqTemp_C_ovrdflg = false;/* Referenced by: '<S115>/sat3' */

/* HVCH_Command_BOD */
CALDATA const volatile float32 KOPM_HVCHReqTemp_C_ovrdval = 0.0F;/* Referenced by: '<S115>/sat4' */

/* HVCH_Command_BOD */
CALDATA const volatile uint8 KOPM_InfoDispHi_enum = 31U;/* Referenced by: '<S233>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_InfoDispLo_enum = 0U;/* Referenced by: '<S233>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_InfoDisp_enum_ovrdflg = false;/* Referenced by: '<S233>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_InfoDisp_enum_ovrdval = 0U;/* Referenced by: '<S233>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_IntLfAntDiagStatHi_enum = 3U;/* Referenced by: '<S484>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_IntLfAntDiagStatLo_enum = 0U;/* Referenced by: '<S484>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_IntLfAntDiagStat_enum_ovrdflg = false;/* Referenced by: '<S484>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_IntLfAntDiagStat_enum_ovrdval = 0U;/* Referenced by: '<S484>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_LckVehWrmHi_enum = 2U;/* Referenced by: '<S234>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_LckVehWrmLo_enum = 0U;/* Referenced by: '<S234>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_LckVehWrm_enum_ovrdflg = false;/* Referenced by: '<S234>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_LckVehWrm_enum_ovrdval = 0U;/* Referenced by: '<S234>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_LimpHomeSta_flg_ovrdflg = false;/* Referenced by: '<S361>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_LimpHomeSta_flg_ovrdval = false;/* Referenced by: '<S361>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_MCUHiTempWrning_flg_ovrdflg = false;/* Referenced by: '<S235>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_MCUHiTempWrning_flg_ovrdval = false;/* Referenced by: '<S235>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_MaxChrgCurntACHi_A = 32U;/* Referenced by: '<S328>/sat6' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile uint8 KOPM_MaxChrgCurntACLo_A = 0U;/* Referenced by: '<S328>/sat7' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile boolean KOPM_MaxChrgCurntAC_A_ovrdflg = false;/* Referenced by: '<S328>/sat3' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile uint8 KOPM_MaxChrgCurntAC_A_ovrdval = 0U;/* Referenced by: '<S328>/sat4' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile float32 KOPM_MaxChrgCurntDCHi_A = 409.0F;/* Referenced by: '<S329>/sat6' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile float32 KOPM_MaxChrgCurntDCLo_A = 0.0F;/* Referenced by: '<S329>/sat7' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile boolean KOPM_MaxChrgCurntDC_A_ovrdflg = false;/* Referenced by: '<S329>/sat3' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile float32 KOPM_MaxChrgCurntDC_A_ovrdval = 0.0F;/* Referenced by: '<S329>/sat4' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile float32 KOPM_MaxChrgVoltDCHi_V = 1023.0F;/* Referenced by: '<S330>/sat6' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile float32 KOPM_MaxChrgVoltDCLo_V = 0.0F;/* Referenced by: '<S330>/sat7' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile boolean KOPM_MaxChrgVoltDC_V_ovrdflg = false;/* Referenced by: '<S330>/sat3' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile float32 KOPM_MaxChrgVoltDC_V_ovrdval = 0.0F;/* Referenced by: '<S330>/sat4' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile float32 KOPM_MaxHVDCCurntACHi_A = 102.3F;/* Referenced by: '<S340>/sat6' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_MaxHVDCCurntACLo_A = 0.0F;/* Referenced by: '<S340>/sat7' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_MaxHVDCCurntAC_A_ovrdflg = false;/* Referenced by: '<S340>/sat3' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_MaxHVDCCurntAC_A_ovrdval = 0.0F;/* Referenced by: '<S340>/sat4' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_MaxHVDCVoltACHi_V = 511.0F;/* Referenced by: '<S341>/sat6' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_MaxHVDCVoltACLo_V = 0.0F;/* Referenced by: '<S341>/sat7' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_MaxHVDCVoltAC_V_ovrdflg = false;/* Referenced by: '<S341>/sat3' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_MaxHVDCVoltAC_V_ovrdval = 0.0F;/* Referenced by: '<S341>/sat4' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_MotActPwrHi_Kw = 204.0F;/* Referenced by: '<S237>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile float32 KOPM_MotActPwrLo_Kw = 0.0F;/* Referenced by: '<S237>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_MotActPwrTypHi_enum = 1U;/* Referenced by: '<S236>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_MotActPwrTypLo_enum = 0U;/* Referenced by: '<S236>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_MotActPwrTyp_enum_ovrdflg = false;/* Referenced by: '<S236>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_MotActPwrTyp_enum_ovrdval = 0U;/* Referenced by: '<S236>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_MotActPwr_Kw_ovrdflg = false;/* Referenced by: '<S237>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_MotActPwr_Kw_ovrdval = 0.0F;/* Referenced by: '<S237>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_MotDirReqHi_enum = 3U;/* Referenced by: '<S202>/sat6' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile uint8 KOPM_MotDirReqLo_enum = 0U;/* Referenced by: '<S202>/sat7' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile boolean KOPM_MotDirReq_enum_ovrdflg = false;/* Referenced by: '<S202>/sat3' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile EnumMotorDirReq KOPM_MotDirReq_enum_ovrdval =
  EnumMotorDirReq_Stdby;               /* Referenced by: '<S202>/sat4' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile float32 KOPM_MotDmpgLmtHi_Nm = 25.5F;/* Referenced by: '<S195>/sat6' */

/* VCU_0_Value_EPT */
CALDATA const volatile float32 KOPM_MotDmpgLmtLo_Nm = 0.0F;/* Referenced by: '<S195>/sat7' */

/* VCU_0_Value_EPT */
CALDATA const volatile boolean KOPM_MotDmpgLmt_Nm_ovrdflg = false;/* Referenced by: '<S195>/sat3' */

/* VCU_0_Value_EPT */
CALDATA const volatile float32 KOPM_MotDmpgLmt_Nm_ovrdval = 0.0F;/* Referenced by: '<S195>/sat4' */

/* VCU_0_Value_EPT */
CALDATA const volatile uint8 KOPM_MotModeReqHi_enum = 3U;/* Referenced by: '<S203>/sat6' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile uint8 KOPM_MotModeReqLo_enum = 0U;/* Referenced by: '<S203>/sat7' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile boolean KOPM_MotModeReq_enum_ovrdflg = false;/* Referenced by: '<S203>/sat3' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile EnumMotorModeReq KOPM_MotModeReq_enum_ovrdval =
  EnumMotorModeReq_Stdby;              /* Referenced by: '<S203>/sat4' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile float32 KOPM_MotSpdReqHi_rpm = 16382.0F;/* Referenced by: '<S204>/sat6' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile float32 KOPM_MotSpdReqLo_rpm = -16384.0F;/* Referenced by: '<S204>/sat7' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile boolean KOPM_MotSpdReq_rpm_ovrdflg = false;/* Referenced by: '<S204>/sat3' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile float32 KOPM_MotSpdReq_rpm_ovrdval = 0.0F;/* Referenced by: '<S204>/sat4' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile float32 KOPM_MotTorqReqHi_Nm = 819.0F;/* Referenced by: '<S205>/sat6' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile float32 KOPM_MotTorqReqLo_Nm = -819.0F;/* Referenced by: '<S205>/sat7' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile boolean KOPM_MotTorqReq_Nm_ovrdflg = false;/* Referenced by: '<S205>/sat3' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile float32 KOPM_MotTorqReq_Nm_ovrdval = 0.0F;/* Referenced by: '<S205>/sat4' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile boolean KOPM_MotorHiTempWrning_flg_ovrdflg = false;/* Referenced by: '<S238>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_MotorHiTempWrning_flg_ovrdval = false;/* Referenced by: '<S238>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_MotorOutputCooltTempHi_C = 215.0F;/* Referenced by: '<S322>/sat6' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_MotorOutputCooltTempLo_C = -40.0F;/* Referenced by: '<S322>/sat7' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_MotorOutputCooltTemp_C_ovrdflg = false;/* Referenced by: '<S322>/sat3' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile float32 KOPM_MotorOutputCooltTemp_C_ovrdval = 0.0F;/* Referenced by: '<S322>/sat4' */

/* VCU_3_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_OBCIntDchrgEna_flg_ovrdflg = false;/* Referenced by: '<S342>/sat3' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile boolean KOPM_OBCIntDchrgEna_flg_ovrdval = false;/* Referenced by: '<S342>/sat4' */

/* VCU_C_OprtCmd_EPT */
CALDATA const volatile uint8 KOPM_OBCOprtCmdHi_enum = 7U;/* Referenced by: '<S331>/sat6' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile uint8 KOPM_OBCOprtCmdLo_enum = 0U;/* Referenced by: '<S331>/sat7' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile uint8 KOPM_OBCOprtCmdToICUHi_enum = 7U;/* Referenced by: '<S239>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_OBCOprtCmdToICULo_enum = 0U;/* Referenced by: '<S239>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_OBCOprtCmdToICU_enum_ovrdflg = false;/* Referenced by: '<S239>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile EnumOBCOprtCmd KOPM_OBCOprtCmdToICU_enum_ovrdval =
  EnumOBCOprtCmd_Standby;              /* Referenced by: '<S239>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_OBCOprtCmd_enum_ovrdflg = false;/* Referenced by: '<S331>/sat3' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile EnumOBCOprtCmd KOPM_OBCOprtCmd_enum_ovrdval =
  EnumOBCOprtCmd_Standby;              /* Referenced by: '<S331>/sat4' */

/* VCU_4_ChrgCmd_EPT */
CALDATA const volatile boolean KOPM_OTAModeSts_flg_ovrdflg = false;/* Referenced by: '<S289>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_OTAModeSts_flg_ovrdval = false;/* Referenced by: '<S289>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_PCUFailSta_flg_ovrdflg = false;/* Referenced by: '<S362>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_PCUFailSta_flg_ovrdval = false;/* Referenced by: '<S362>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_PGrSwcStHi_enum = 3U;/* Referenced by: '<S290>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_PGrSwcStLo_enum = 0U;/* Referenced by: '<S290>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_PGrSwcSt_enum_ovrdflg = false;/* Referenced by: '<S290>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_PGrSwcSt_enum_ovrdval = 0U;/* Referenced by: '<S290>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_PTActlOprtModeHi_enum = 7U;/* Referenced by: '<S363>/sat6' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_PTActlOprtModeLo_enum = 0U;/* Referenced by: '<S363>/sat7' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_PTActlOprtMode_enum_ovrdflg = false;/* Referenced by: '<S363>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile EnumPTActMd KOPM_PTActlOprtMode_enum_ovrdval =
  EnumPTActMd_OFF;                     /* Referenced by: '<S363>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_PassLfAntDiagStatHi_enum = 3U;/* Referenced by: '<S485>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_PassLfAntDiagStatLo_enum = 0U;/* Referenced by: '<S485>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_PassLfAntDiagStat_enum_ovrdflg = false;/* Referenced by: '<S485>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_PassLfAntDiagStat_enum_ovrdval = 0U;/* Referenced by: '<S485>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_PrstlsStaFbHi_enum = 3U;/* Referenced by: '<S364>/sat6' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_PrstlsStaFbLo_enum = 0U;/* Referenced by: '<S364>/sat7' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_PrstlsStaFb_enum_ovrdflg = false;/* Referenced by: '<S364>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile EnumCrpModeAct KOPM_PrstlsStaFb_enum_ovrdval =
  EnumCrpModeAct_Open;                 /* Referenced by: '<S364>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile float32 KOPM_PwrRecupActWhlTqHi_Nm = 32767.0F;/* Referenced by: '<S171>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_PwrRecupActWhlTqLo_Nm = -32768.0F;/* Referenced by: '<S171>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_PwrRecupActWhlTq_Nm_ovrdflg = false;/* Referenced by: '<S171>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_PwrRecupActWhlTq_Nm_ovrdval = 0.0F;/* Referenced by: '<S171>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile uint8 KOPM_PwrRecupActlWhlTqStsHi_enum = 3U;/* Referenced by: '<S172>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile uint8 KOPM_PwrRecupActlWhlTqStsLo_enum = 0U;/* Referenced by: '<S172>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_PwrRecupActlWhlTqSts_enum_ovrdflg = false;/* Referenced by: '<S172>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile uint8 KOPM_PwrRecupActlWhlTqSts_enum_ovrdval = 0U;/* Referenced by: '<S172>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile uint8 KOPM_PwrRecupIntnstyHi_enum = 3U;/* Referenced by: '<S365>/sat6' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_PwrRecupIntnstyLo_enum = 0U;/* Referenced by: '<S365>/sat7' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_PwrRecupIntnsty_enum_ovrdflg = false;/* Referenced by: '<S365>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile EnumRegenModeAct KOPM_PwrRecupIntnsty_enum_ovrdval =
  EnumRegenModeAct_Off;                /* Referenced by: '<S365>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_PwrRecupMaxAvlbMotorTorqStaHi_enum = 3U;/* Referenced by: '<S291>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_PwrRecupMaxAvlbMotorTorqStaLo_enum = 0U;/* Referenced by: '<S291>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_PwrRecupMaxAvlbMotorTorqSta_enum_ovrdflg =
  false;                               /* Referenced by: '<S291>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_PwrRecupMaxAvlbMotorTorqSta_enum_ovrdval = 0U;/* Referenced by: '<S291>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_PwrRecupMaxAvlbWhlTqStsHi_enum = 3U;/* Referenced by: '<S173>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile uint8 KOPM_PwrRecupMaxAvlbWhlTqStsLo_enum = 0U;/* Referenced by: '<S173>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_PwrRecupMaxAvlbWhlTqSts_enum_ovrdflg = false;/* Referenced by: '<S173>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile uint8 KOPM_PwrRecupMaxAvlbWhlTqSts_enum_ovrdval = 0U;/* Referenced by: '<S173>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_RmtACCtrlReq_flg_ovrdflg = false;/* Referenced by: '<S240>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_RmtACCtrlReq_flg_ovrdval = false;/* Referenced by: '<S240>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_RmtACCtrlStHi_enum = 3U;/* Referenced by: '<S241>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_RmtACCtrlStLo_enum = 0U;/* Referenced by: '<S241>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_RmtACCtrlSt_enum_ovrdflg = false;/* Referenced by: '<S241>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_RmtACCtrlSt_enum_ovrdval = 0U;/* Referenced by: '<S241>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_RmtACDefrstReq_flg_ovrdflg = false;/* Referenced by: '<S242>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_RmtACDefrstReq_flg_ovrdval = false;/* Referenced by: '<S242>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_RmtMainDrvrSeatHeatFbHi_enum = 3U;/* Referenced by: '<S243>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_RmtMainDrvrSeatHeatFbLo_enum = 0U;/* Referenced by: '<S243>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_RmtMainDrvrSeatHeatFb_enum_ovrdflg = false;/* Referenced by: '<S243>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_RmtMainDrvrSeatHeatFb_enum_ovrdval = 0U;/* Referenced by: '<S243>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_RmtPwrCtrlFbHi_enum = 3U;/* Referenced by: '<S244>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_RmtPwrCtrlFbLo_enum = 0U;/* Referenced by: '<S244>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_RmtPwrCtrlFb_enum_ovrdflg = false;/* Referenced by: '<S244>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_RmtPwrCtrlFb_enum_ovrdval = 0U;/* Referenced by: '<S244>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_RmtSteerWhlHeatFbHi_enum = 3U;/* Referenced by: '<S245>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_RmtSteerWhlHeatFbLo_enum = 0U;/* Referenced by: '<S245>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_RmtSteerWhlHeatFb_enum_ovrdflg = false;/* Referenced by: '<S245>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_RmtSteerWhlHeatFb_enum_ovrdval = 0U;/* Referenced by: '<S245>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_RsrvdPwrHi_kW = 409.0F;/* Referenced by: '<S246>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile float32 KOPM_RsrvdPwrLo_kW = 0.0F;/* Referenced by: '<S246>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_RsrvdPwr_kW_ovrdflg = false;/* Referenced by: '<S246>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_RsrvdPwr_kW_ovrdval = 0.0F;/* Referenced by: '<S246>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_SIBSBMSBatSOCAllow_flg_ovrdflg = false;/* Referenced by: '<S247>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_SIBSBMSBatSOCAllow_flg_ovrdval = false;/* Referenced by: '<S247>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_SIBSChgNumAllow_flg_ovrdflg = false;/* Referenced by: '<S248>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_SIBSChgNumAllow_flg_ovrdval = false;/* Referenced by: '<S248>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_SIBSFbRTCWupFlg_flg_ovrdflg = false;/* Referenced by: '<S249>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_SIBSFbRTCWupFlg_flg_ovrdval = false;/* Referenced by: '<S249>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_SIBSKL30VoltHi_V = 25.5F;/* Referenced by: '<S250>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_SIBSKL30VoltLo_V = 0.0F;/* Referenced by: '<S250>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_SIBSKL30Volt_V_ovrdflg = false;/* Referenced by: '<S250>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_SIBSKL30Volt_V_ovrdval = 0.0F;/* Referenced by: '<S250>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_SIBSRTCChrgStHi_enum = 7U;/* Referenced by: '<S251>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_SIBSRTCChrgStLo_enum = 0U;/* Referenced by: '<S251>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_SIBSRTCChrgSt_enum_ovrdflg = false;/* Referenced by: '<S251>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile EnumIBSChrgSt KOPM_SIBSRTCChrgSt_enum_ovrdval =
  EnumIBSChrgSt_Idle;                  /* Referenced by: '<S251>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_SIBSRTCWUChgFailNumHi_cnt = 31U;/* Referenced by: '<S252>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_SIBSRTCWUChgFailNumLo_cnt = 0U;/* Referenced by: '<S252>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_SIBSRTCWUChgFailNum_cnt_ovrdflg = false;/* Referenced by: '<S252>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_SIBSRTCWUChgFailNum_cnt_ovrdval = 0U;/* Referenced by: '<S252>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_SIBSRTCWUChgNumHi_cnt = 127U;/* Referenced by: '<S253>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_SIBSRTCWUChgNumLo_cnt = 0U;/* Referenced by: '<S253>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_SIBSRTCWUChgNum_cnt_ovrdflg = false;/* Referenced by: '<S253>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_SIBSRTCWUChgNum_cnt_ovrdval = 0U;/* Referenced by: '<S253>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_SIBSWupVoltAllow_flg_ovrdflg = false;/* Referenced by: '<S254>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_SIBSWupVoltAllow_flg_ovrdval = false;/* Referenced by: '<S254>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ShftKeyStgntnHi_enum = 3U;/* Referenced by: '<S255>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_ShftKeyStgntnLo_enum = 0U;/* Referenced by: '<S255>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_ShftKeyStgntn_enum_ovrdflg = false;/* Referenced by: '<S255>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_ShftKeyStgntn_enum_ovrdval = 0U;/* Referenced by: '<S255>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_StrgRecupReqBrkLampOn_flg_ovrdflg = false;/* Referenced by: '<S292>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_StrgRecupReqBrkLampOn_flg_ovrdval = false;/* Referenced by: '<S292>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_SysFailStaHi_enum = 15U;/* Referenced by: '<S337>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_SysFailStaLo_enum = 0U;/* Referenced by: '<S337>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_SysFailSta_enum_ovrdflg = false;/* Referenced by: '<S337>/sat3' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile uint8 KOPM_SysFailSta_enum_ovrdval = 0U;/* Referenced by: '<S337>/sat4' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_TMPSAbnmPrsrWarn_flg_ovrdflg = false;/* Referenced by: '<S486>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_TMPSAbnmPrsrWarn_flg_ovrdval = false;/* Referenced by: '<S486>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile float32 KOPM_TMSACPExhtTmpHi_C = 140.0F;/* Referenced by: '<S106>/sat6' */

/* AC_COMP_BOD */
CALDATA const volatile float32 KOPM_TMSACPExhtTmpLo_C = -40.0F;/* Referenced by: '<S106>/sat7' */

/* AC_COMP_BOD */
CALDATA const volatile boolean KOPM_TMSACPExhtTmp_C_ovrdflg = false;/* Referenced by: '<S106>/sat3' */

/* AC_COMP_BOD */
CALDATA const volatile float32 KOPM_TMSACPExhtTmp_C_ovrdval = 0.0F;/* Referenced by: '<S106>/sat4' */

/* AC_COMP_BOD */
CALDATA const volatile float32 KOPM_TMSACPInletPresHi_kPa = 1000.0F;/* Referenced by: '<S107>/sat6' */

/* AC_COMP_BOD */
CALDATA const volatile float32 KOPM_TMSACPInletPresLo_kPa = 0.0F;/* Referenced by: '<S107>/sat7' */

/* AC_COMP_BOD */
CALDATA const volatile boolean KOPM_TMSACPInletPres_kPa_ovrdflg = false;/* Referenced by: '<S107>/sat3' */

/* AC_COMP_BOD */
CALDATA const volatile float32 KOPM_TMSACPInletPres_kPa_ovrdval = 0.0F;/* Referenced by: '<S107>/sat4' */

/* AC_COMP_BOD */
CALDATA const volatile uint16 KOPM_TMSAEXVCurrentPstnHi_cnt = 65535U;/* Referenced by: '<S131>/sat6' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile uint16 KOPM_TMSAEXVCurrentPstnLo_cnt = 0U;/* Referenced by: '<S131>/sat7' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile boolean KOPM_TMSAEXVCurrentPstn_cnt_ovrdflg = false;/* Referenced by: '<S131>/sat3' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile uint16 KOPM_TMSAEXVCurrentPstn_cnt_ovrdval = 0U;/* Referenced by: '<S131>/sat4' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile boolean KOPM_TMSAEXVEnblReq_flg_ovrdflg = false;/* Referenced by: '<S135>/sat3' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile boolean KOPM_TMSAEXVEnblReq_flg_ovrdval = false;/* Referenced by: '<S135>/sat4' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint16 KOPM_TMSAEXVPstnReqHi_cnt = 65535U;/* Referenced by: '<S132>/sat6' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile uint16 KOPM_TMSAEXVPstnReqLo_cnt = 0U;/* Referenced by: '<S132>/sat7' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile boolean KOPM_TMSAEXVPstnReq_cnt_ovrdflg = false;/* Referenced by: '<S132>/sat3' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile uint16 KOPM_TMSAEXVPstnReq_cnt_ovrdval = 0U;/* Referenced by: '<S132>/sat4' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile float32 KOPM_TMSAcPMPRealRPMHi_rpm = 102.0F;/* Referenced by: '<S118>/sat6' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSAcPMPRealRPMLo_rpm = 0.0F;/* Referenced by: '<S118>/sat7' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile boolean KOPM_TMSAcPMPRealRPM_rpm_ovrdflg = false;/* Referenced by: '<S118>/sat3' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSAcPMPRealRPM_rpm_ovrdval = 0.0F;/* Referenced by: '<S118>/sat4' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSAcPMPSpdSetHi_rpm = 102.0F;/* Referenced by: '<S119>/sat6' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSAcPMPSpdSetLo_rpm = 0.0F;/* Referenced by: '<S119>/sat7' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile boolean KOPM_TMSAcPMPSpdSet_rpm_ovrdflg = false;/* Referenced by: '<S119>/sat3' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSAcPMPSpdSet_rpm_ovrdval = 0.0F;/* Referenced by: '<S119>/sat4' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile uint8 KOPM_TMSBATThermModHi_enum = 15U;/* Referenced by: '<S83>/sat6' */

/* AC_8_status_BOD */
CALDATA const volatile uint8 KOPM_TMSBATThermModLo_enum = 0U;/* Referenced by: '<S83>/sat7' */

/* AC_8_status_BOD */
CALDATA const volatile boolean KOPM_TMSBATThermMod_enum_ovrdflg = false;/* Referenced by: '<S83>/sat3' */

/* AC_8_status_BOD */
CALDATA const volatile uint8 KOPM_TMSBATThermMod_enum_ovrdval = 0U;/* Referenced by: '<S83>/sat4' */

/* AC_8_status_BOD */
CALDATA const volatile uint16 KOPM_TMSBEXVCurrentPstnHi_cnt = 65535U;/* Referenced by: '<S133>/sat6' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile uint16 KOPM_TMSBEXVCurrentPstnLo_cnt = 0U;/* Referenced by: '<S133>/sat7' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile boolean KOPM_TMSBEXVCurrentPstn_cnt_ovrdflg = false;/* Referenced by: '<S133>/sat3' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile uint16 KOPM_TMSBEXVCurrentPstn_cnt_ovrdval = 0U;/* Referenced by: '<S133>/sat4' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile boolean KOPM_TMSBEXVEnblCmd_flg_ovrdflg = false;/* Referenced by: '<S136>/sat3' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile boolean KOPM_TMSBEXVEnblCmd_flg_ovrdval = false;/* Referenced by: '<S136>/sat4' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint16 KOPM_TMSBEXVPstnCmdHi_cnt = 65535U;/* Referenced by: '<S134>/sat6' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile uint16 KOPM_TMSBEXVPstnCmdLo_cnt = 0U;/* Referenced by: '<S134>/sat7' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile boolean KOPM_TMSBEXVPstnCmd_cnt_ovrdflg = false;/* Referenced by: '<S134>/sat3' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile uint16 KOPM_TMSBEXVPstnCmd_cnt_ovrdval = 0U;/* Referenced by: '<S134>/sat4' */

/* TMS_LINTestData2_BOD */
CALDATA const volatile float32 KOPM_TMSBatPMPRealRPMHi_rpm = 102.0F;/* Referenced by: '<S120>/sat6' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSBatPMPRealRPMLo_rpm = 0.0F;/* Referenced by: '<S120>/sat7' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile boolean KOPM_TMSBatPMPRealRPM_rpm_ovrdflg = false;/* Referenced by: '<S120>/sat3' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSBatPMPRealRPM_rpm_ovrdval = 0.0F;/* Referenced by: '<S120>/sat4' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSBatPMPSpdSetHi_rpm = 102.0F;/* Referenced by: '<S121>/sat6' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSBatPMPSpdSetLo_rpm = 0.0F;/* Referenced by: '<S121>/sat7' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile boolean KOPM_TMSBatPMPSpdSet_rpm_ovrdflg = false;/* Referenced by: '<S121>/sat3' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSBatPMPSpdSet_rpm_ovrdval = 0.0F;/* Referenced by: '<S121>/sat4' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile boolean KOPM_TMSBattTempCtrlRmnSwFb_flg_ovrdflg = false;/* Referenced by: '<S56>/sat3' */

/* AC_2_State_BOD */
CALDATA const volatile boolean KOPM_TMSBattTempCtrlRmnSwFb_flg_ovrdval = false;/* Referenced by: '<S56>/sat4' */

/* AC_2_State_BOD */
CALDATA const volatile uint8 KOPM_TMSC3WVBPosSetReqHi_enum = 255U;/* Referenced by: '<S137>/sat6' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint8 KOPM_TMSC3WVBPosSetReqLo_enum = 0U;/* Referenced by: '<S137>/sat7' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile boolean KOPM_TMSC3WVBPosSetReq_enum_ovrdflg = false;/* Referenced by: '<S137>/sat3' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint8 KOPM_TMSC3WVBPosSetReq_enum_ovrdval = 0U;/* Referenced by: '<S137>/sat4' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint8 KOPM_TMSC3WVModeHi_enum = 15U;/* Referenced by: '<S138>/sat6' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint8 KOPM_TMSC3WVModeLo_enum = 0U;/* Referenced by: '<S138>/sat7' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile boolean KOPM_TMSC3WVMode_enum_ovrdflg = false;/* Referenced by: '<S138>/sat3' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint8 KOPM_TMSC3WVMode_enum_ovrdval = 0U;/* Referenced by: '<S138>/sat4' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint16 KOPM_TMSC3WVPosRecHi_enum = 1023U;/* Referenced by: '<S139>/sat6' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint16 KOPM_TMSC3WVPosRecLo_enum = 0U;/* Referenced by: '<S139>/sat7' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile boolean KOPM_TMSC3WVPosRec_enum_ovrdflg = false;/* Referenced by: '<S139>/sat3' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint16 KOPM_TMSC3WVPosRec_enum_ovrdval = 0U;/* Referenced by: '<S139>/sat4' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint8 KOPM_TMSC5WVBPosSetReqHi_enum = 255U;/* Referenced by: '<S140>/sat6' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint8 KOPM_TMSC5WVBPosSetReqLo_enum = 0U;/* Referenced by: '<S140>/sat7' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile boolean KOPM_TMSC5WVBPosSetReq_enum_ovrdflg = false;/* Referenced by: '<S140>/sat3' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint8 KOPM_TMSC5WVBPosSetReq_enum_ovrdval = 0U;/* Referenced by: '<S140>/sat4' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint8 KOPM_TMSC5WVModeHi_enum = 15U;/* Referenced by: '<S141>/sat6' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint8 KOPM_TMSC5WVModeLo_enum = 0U;/* Referenced by: '<S141>/sat7' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile boolean KOPM_TMSC5WVMode_enum_ovrdflg = false;/* Referenced by: '<S141>/sat3' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint8 KOPM_TMSC5WVMode_enum_ovrdval = 0U;/* Referenced by: '<S141>/sat4' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint16 KOPM_TMSC5WVPosRecHi_enum = 1023U;/* Referenced by: '<S142>/sat6' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint16 KOPM_TMSC5WVPosRecLo_enum = 0U;/* Referenced by: '<S142>/sat7' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile boolean KOPM_TMSC5WVPosRec_enum_ovrdflg = false;/* Referenced by: '<S142>/sat3' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint16 KOPM_TMSC5WVPosRec_enum_ovrdval = 0U;/* Referenced by: '<S142>/sat4' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint8 KOPM_TMSCabThermModHi_enum = 15U;/* Referenced by: '<S84>/sat6' */

/* AC_8_status_BOD */
CALDATA const volatile uint8 KOPM_TMSCabThermModLo_enum = 0U;/* Referenced by: '<S84>/sat7' */

/* AC_8_status_BOD */
CALDATA const volatile boolean KOPM_TMSCabThermMod_enum_ovrdflg = false;/* Referenced by: '<S84>/sat3' */

/* AC_8_status_BOD */
CALDATA const volatile uint8 KOPM_TMSCabThermMod_enum_ovrdval = 0U;/* Referenced by: '<S84>/sat4' */

/* AC_8_status_BOD */
CALDATA const volatile float32 KOPM_TMSChillerOutTmpHi_C = 125.0F;/* Referenced by: '<S68>/sat6' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_TMSChillerOutTmpLo_C = -10.0F;/* Referenced by: '<S68>/sat7' */

/* AC_3_State_BOD */
CALDATA const volatile boolean KOPM_TMSChillerOutTmp_C_ovrdflg = false;/* Referenced by: '<S68>/sat3' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_TMSChillerOutTmp_C_ovrdval = 0.0F;/* Referenced by: '<S68>/sat4' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_TMSEvapOutTmpHi_C = 140.0F;/* Referenced by: '<S69>/sat6' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_TMSEvapOutTmpLo_C = -40.0F;/* Referenced by: '<S69>/sat7' */

/* AC_3_State_BOD */
CALDATA const volatile boolean KOPM_TMSEvapOutTmp_C_ovrdflg = false;/* Referenced by: '<S69>/sat3' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_TMSEvapOutTmp_C_ovrdval = 0.0F;/* Referenced by: '<S69>/sat4' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_TMSEvapTmpHi_C = 100.0F;/* Referenced by: '<S70>/sat6' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_TMSEvapTmpLo_C = -50.0F;/* Referenced by: '<S70>/sat7' */

/* AC_3_State_BOD */
CALDATA const volatile boolean KOPM_TMSEvapTmp_C_ovrdflg = false;/* Referenced by: '<S70>/sat3' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_TMSEvapTmp_C_ovrdval = 0.0F;/* Referenced by: '<S70>/sat4' */

/* AC_3_State_BOD */
CALDATA const volatile uint16 KOPM_TMSHPEXVCurrentPstnHi_cnt = 65535U;/* Referenced by: '<S143>/sat6' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint16 KOPM_TMSHPEXVCurrentPstnLo_cnt = 0U;/* Referenced by: '<S143>/sat7' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile boolean KOPM_TMSHPEXVCurrentPstn_cnt_ovrdflg = false;/* Referenced by: '<S143>/sat3' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint16 KOPM_TMSHPEXVCurrentPstn_cnt_ovrdval = 0U;/* Referenced by: '<S143>/sat4' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile boolean KOPM_TMSHPEXVEnblCmd_flg_ovrdflg = false;/* Referenced by: '<S144>/sat3' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile boolean KOPM_TMSHPEXVEnblCmd_flg_ovrdval = false;/* Referenced by: '<S144>/sat4' */

/* TMS_LINTestData3_BOD */
CALDATA const volatile uint16 KOPM_TMSHPEXVPstnCmdHi_cnt = 65535U;/* Referenced by: '<S122>/sat6' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile uint16 KOPM_TMSHPEXVPstnCmdLo_cnt = 0U;/* Referenced by: '<S122>/sat7' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile boolean KOPM_TMSHPEXVPstnCmd_cnt_ovrdflg = false;/* Referenced by: '<S122>/sat3' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile uint16 KOPM_TMSHPEXVPstnCmd_cnt_ovrdval = 0U;/* Referenced by: '<S122>/sat4' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSMotInletCooltTempHi_C = 120.0F;/* Referenced by: '<S85>/sat6' */

/* AC_8_status_BOD */
CALDATA const volatile float32 KOPM_TMSMotInletCooltTempLo_C = -40.0F;/* Referenced by: '<S85>/sat7' */

/* AC_8_status_BOD */
CALDATA const volatile boolean KOPM_TMSMotInletCooltTemp_C_ovrdflg = false;/* Referenced by: '<S85>/sat3' */

/* AC_8_status_BOD */
CALDATA const volatile float32 KOPM_TMSMotInletCooltTemp_C_ovrdval = 0.0F;/* Referenced by: '<S85>/sat4' */

/* AC_8_status_BOD */
CALDATA const volatile float32 KOPM_TMSMotPMPRealRPMHi_rpm = 102.0F;/* Referenced by: '<S123>/sat6' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSMotPMPRealRPMLo_rpm = 0.0F;/* Referenced by: '<S123>/sat7' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile boolean KOPM_TMSMotPMPRealRPM_rpm_ovrdflg = false;/* Referenced by: '<S123>/sat3' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSMotPMPRealRPM_rpm_ovrdval = 0.0F;/* Referenced by: '<S123>/sat4' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSMotPMPSpdSetHi_rpm = 102.0F;/* Referenced by: '<S124>/sat6' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSMotPMPSpdSetLo_rpm = 0.0F;/* Referenced by: '<S124>/sat7' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile boolean KOPM_TMSMotPMPSpdSet_rpm_ovrdflg = false;/* Referenced by: '<S124>/sat3' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSMotPMPSpdSet_rpm_ovrdval = 0.0F;/* Referenced by: '<S124>/sat4' */

/* TMS_LINTestData1_BOD */
CALDATA const volatile float32 KOPM_TMSOHXOutTmpHi_C = 140.0F;/* Referenced by: '<S71>/sat6' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_TMSOHXOutTmpLo_C = -40.0F;/* Referenced by: '<S71>/sat7' */

/* AC_3_State_BOD */
CALDATA const volatile boolean KOPM_TMSOHXOutTmp_C_ovrdflg = false;/* Referenced by: '<S71>/sat3' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_TMSOHXOutTmp_C_ovrdval = 0.0F;/* Referenced by: '<S71>/sat4' */

/* AC_3_State_BOD */
CALDATA const volatile float32 KOPM_TMSPTPresHi_kPa = 3600.0F;/* Referenced by: '<S57>/sat6' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_TMSPTPresLo_kPa = 0.0F;/* Referenced by: '<S57>/sat7' */

/* AC_2_State_BOD */
CALDATA const volatile boolean KOPM_TMSPTPres_kPa_ovrdflg = false;/* Referenced by: '<S57>/sat3' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_TMSPTPres_kPa_ovrdval = 0.0F;/* Referenced by: '<S57>/sat4' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_TMSPTTempHi_C = 150.0F;/* Referenced by: '<S58>/sat6' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_TMSPTTempLo_C = -40.0F;/* Referenced by: '<S58>/sat7' */

/* AC_2_State_BOD */
CALDATA const volatile boolean KOPM_TMSPTTemp_C_ovrdflg = false;/* Referenced by: '<S58>/sat3' */

/* AC_2_State_BOD */
CALDATA const volatile float32 KOPM_TMSPTTemp_C_ovrdval = 0.0F;/* Referenced by: '<S58>/sat4' */

/* AC_2_State_BOD */
CALDATA const volatile uint8 KOPM_TMSPwrCoolFanSpdDutyHi_pct = 100U;/* Referenced by: '<S86>/sat6' */

/* AC_8_status_BOD */
CALDATA const volatile uint8 KOPM_TMSPwrCoolFanSpdDutyLo_pct = 0U;/* Referenced by: '<S86>/sat7' */

/* AC_8_status_BOD */
CALDATA const volatile boolean KOPM_TMSPwrCoolFanSpdDuty_pct_ovrdflg = false;/* Referenced by: '<S86>/sat3' */

/* AC_8_status_BOD */
CALDATA const volatile uint8 KOPM_TMSPwrCoolFanSpdDuty_pct_ovrdval = 0U;/* Referenced by: '<S86>/sat4' */

/* AC_8_status_BOD */
CALDATA const volatile uint8 KOPM_TPMSPressureStaFLHi_enum = 7U;/* Referenced by: '<S487>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_TPMSPressureStaFLLo_enum = 0U;/* Referenced by: '<S487>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_TPMSPressureStaFL_enum_ovrdflg = false;/* Referenced by: '<S487>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_TPMSPressureStaFL_enum_ovrdval = 0U;/* Referenced by: '<S487>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_TPMSPressureStaFRHi_enum = 7U;/* Referenced by: '<S488>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_TPMSPressureStaFRLo_enum = 0U;/* Referenced by: '<S488>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_TPMSPressureStaFR_enum_ovrdflg = false;/* Referenced by: '<S488>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_TPMSPressureStaFR_enum_ovrdval = 0U;/* Referenced by: '<S488>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_TPMSPressureStaRLHi_enum = 7U;/* Referenced by: '<S489>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_TPMSPressureStaRLLo_enum = 0U;/* Referenced by: '<S489>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_TPMSPressureStaRL_enum_ovrdflg = false;/* Referenced by: '<S489>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_TPMSPressureStaRL_enum_ovrdval = 0U;/* Referenced by: '<S489>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_TPMSPressureStaRRHi_enum = 7U;/* Referenced by: '<S490>/sat6' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_TPMSPressureStaRRLo_enum = 0U;/* Referenced by: '<S490>/sat7' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_TPMSPressureStaRR_enum_ovrdflg = false;/* Referenced by: '<S490>/sat3' */

/* BCM_B_Package_BAC */
CALDATA const volatile uint8 KOPM_TPMSPressureStaRR_enum_ovrdval = 0U;/* Referenced by: '<S490>/sat4' */

/* BCM_B_Package_BAC */
CALDATA const volatile boolean KOPM_VCUACCStandstillReq_flg_ovrdflg = false;/* Referenced by: '<S293>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUACCStandstillReq_flg_ovrdval = false;/* Referenced by: '<S293>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUACCStatHi_enum = 7U;/* Referenced by: '<S294>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUACCStatLo_enum = 0U;/* Referenced by: '<S294>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUACCStat_enum_ovrdflg = false;/* Referenced by: '<S294>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUACCStat_enum_ovrdval = 0U;/* Referenced by: '<S294>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUAccReqDrvOff_flg_ovrdflg = false;/* Referenced by: '<S174>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_VCUAccReqDrvOff_flg_ovrdval = false;/* Referenced by: '<S174>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_VCUAccReqStandstill_flg_ovrdflg = false;/* Referenced by: '<S175>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_VCUAccReqStandstill_flg_ovrdval = false;/* Referenced by: '<S175>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_VCUAccTgtAxHi_mps2 = 3.25F;/* Referenced by: '<S296>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_VCUAccTgtAxLo_mps2 = -9.5F;/* Referenced by: '<S296>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUAccTgtAxReq_flg_ovrdflg = false;/* Referenced by: '<S295>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUAccTgtAxReq_flg_ovrdval = false;/* Referenced by: '<S295>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUAccTgtAx_mps2_ovrdflg = false;/* Referenced by: '<S296>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_VCUAccTgtAx_mps2_ovrdval = 0.0F;/* Referenced by: '<S296>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_VCUBraTorReqHi_Nm = 6200.0F;/* Referenced by: '<S297>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_VCUBraTorReqLo_Nm = -6200.0F;/* Referenced by: '<S297>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUBraTorReq_Nm_ovrdflg = false;/* Referenced by: '<S297>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_VCUBraTorReq_Nm_ovrdval = 0.0F;/* Referenced by: '<S297>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_VCUCruiseCtrTgtSpdHi_kph = 460.0F;/* Referenced by: '<S298>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_VCUCruiseCtrTgtSpdLo_kph = 0.0F;/* Referenced by: '<S298>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUCruiseCtrTgtSpd_kph_ovrdflg = false;/* Referenced by: '<S298>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile float32 KOPM_VCUCruiseCtrTgtSpd_kph_ovrdval = 0.0F;/* Referenced by: '<S298>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUCruiseCtrlStaHi_enum = 7U;/* Referenced by: '<S299>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUCruiseCtrlStaLo_enum = 0U;/* Referenced by: '<S299>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUCruiseCtrlSta_enum_ovrdflg = false;/* Referenced by: '<S299>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile EnumCruiseStatus KOPM_VCUCruiseCtrlSta_enum_ovrdval =
  EnumCruiseStatus_NormOff;            /* Referenced by: '<S299>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUEPBApplyForbidHi_enum = 3U;/* Referenced by: '<S300>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUEPBApplyForbidLo_enum = 0U;/* Referenced by: '<S300>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUEPBApplyForbid_enum_ovrdflg = false;/* Referenced by: '<S300>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUEPBApplyForbid_enum_ovrdval = 0U;/* Referenced by: '<S300>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUEnaEHBBrkRun_flg_ovrdflg = false;/* Referenced by: '<S176>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_VCUEnaEHBBrkRun_flg_ovrdval = false;/* Referenced by: '<S176>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_VCUMasterCylinderPreReqHi_Bar = 276.0F;/* Referenced by: '<S177>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_VCUMasterCylinderPreReqLo_Bar = 0.0F;/* Referenced by: '<S177>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_VCUMasterCylinderPreReq_Bar_ovrdflg = false;/* Referenced by: '<S177>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_VCUMasterCylinderPreReq_Bar_ovrdval = 0.0F;/* Referenced by: '<S177>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_VCUMotTorqueReqToEHBHi_Nm = 819.0F;/* Referenced by: '<S178>/sat6' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_VCUMotTorqueReqToEHBLo_Nm = -819.0F;/* Referenced by: '<S178>/sat7' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_VCUMotTorqueReqToEHB_Nm_ovrdflg = false;/* Referenced by: '<S178>/sat3' */

/* VCU_10_Torque_CHA */
CALDATA const volatile float32 KOPM_VCUMotTorqueReqToEHB_Nm_ovrdval = 0.0F;/* Referenced by: '<S178>/sat4' */

/* VCU_10_Torque_CHA */
CALDATA const volatile boolean KOPM_VCUOprtLicFb_flg_ovrdflg = false;/* Referenced by: '<S256>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_VCUOprtLicFb_flg_ovrdval = false;/* Referenced by: '<S256>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_VCUParkSwStaVld_flg_ovrdflg = false;/* Referenced by: '<S301>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUParkSwStaVld_flg_ovrdval = false;/* Referenced by: '<S301>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUParkSwSta_flg_ovrdflg = false;/* Referenced by: '<S302>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUParkSwSta_flg_ovrdval = false;/* Referenced by: '<S302>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUPreKeReq_flg_ovrdflg = false;/* Referenced by: '<S303>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUPreKeReq_flg_ovrdval = false;/* Referenced by: '<S303>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUReqAutoBrkHi_enum = 3U;/* Referenced by: '<S304>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUReqAutoBrkLo_enum = 0U;/* Referenced by: '<S304>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUReqAutoBrk_enum_ovrdflg = false;/* Referenced by: '<S304>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUReqAutoBrk_enum_ovrdval = 0U;/* Referenced by: '<S304>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUReqEPBHi_enum = 3U;/* Referenced by: '<S306>/sat6' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUReqEPBLo_enum = 0U;/* Referenced by: '<S306>/sat7' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUReqEPBVld_flg_ovrdflg = false;/* Referenced by: '<S305>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUReqEPBVld_flg_ovrdval = false;/* Referenced by: '<S305>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile boolean KOPM_VCUReqEPB_enum_ovrdflg = false;/* Referenced by: '<S306>/sat3' */

/* VCU_D_Status_CHA */
CALDATA const volatile EnumEPBReq KOPM_VCUReqEPB_enum_ovrdval = EnumEPBReq_NoCmd;/* Referenced by: '<S306>/sat4' */

/* VCU_D_Status_CHA */
CALDATA const volatile uint8 KOPM_VCUSpdLimLvlFbHi_enum = 3U;/* Referenced by: '<S257>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VCUSpdLimLvlFbLo_enum = 0U;/* Referenced by: '<S257>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_VCUSpdLimLvlFb_enum_ovrdflg = false;/* Referenced by: '<S257>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VCUSpdLimLvlFb_enum_ovrdval = 0U;/* Referenced by: '<S257>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VCUSpdLimLvlSetFbHi_enum = 3U;/* Referenced by: '<S258>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VCUSpdLimLvlSetFbLo_enum = 0U;/* Referenced by: '<S258>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_VCUSpdLimLvlSetFb_enum_ovrdflg = false;/* Referenced by: '<S258>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VCUSpdLimLvlSetFb_enum_ovrdval = 0U;/* Referenced by: '<S258>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_VCUVerFb_flg_ovrdflg = false;/* Referenced by: '<S259>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_VCUVerFb_flg_ovrdval = false;/* Referenced by: '<S259>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VCUVerSetFbHi_enum = 3U;/* Referenced by: '<S260>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VCUVerSetFbLo_enum = 0U;/* Referenced by: '<S260>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_VCUVerSetFb_enum_ovrdflg = false;/* Referenced by: '<S260>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VCUVerSetFb_enum_ovrdval = 0U;/* Referenced by: '<S260>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VehActDrvMod1Hi_enum = 7U;/* Referenced by: '<S366>/sat6' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_VehActDrvMod1Lo_enum = 0U;/* Referenced by: '<S366>/sat7' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_VehActDrvMod1_enum_ovrdflg = false;/* Referenced by: '<S366>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile EnumDrvModeAct KOPM_VehActDrvMod1_enum_ovrdval =
  EnumDrvModeAct_Invalid;              /* Referenced by: '<S366>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_VehActDrvPwrHi_pct = 127U;/* Referenced by: '<S261>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VehActDrvPwrLo_pct = 0U;/* Referenced by: '<S261>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_VehActDrvPwr_pct_ovrdflg = false;/* Referenced by: '<S261>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VehActDrvPwr_pct_ovrdval = 0U;/* Referenced by: '<S261>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VehActRecupPwrHi_pct = 100U;/* Referenced by: '<S262>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VehActRecupPwrLo_pct = 0U;/* Referenced by: '<S262>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_VehActRecupPwr_pct_ovrdflg = false;/* Referenced by: '<S262>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VehActRecupPwr_pct_ovrdval = 0U;/* Referenced by: '<S262>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VehActlGearPosHi_enum = 15U;/* Referenced by: '<S368>/sat6' */

/* CCU_VehInfo_BAC */
CALDATA const volatile uint8 KOPM_VehActlGearPosLo_enum = 0U;/* Referenced by: '<S368>/sat7' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_VehActlGearPosVld_flg_ovrdflg = false;/* Referenced by: '<S367>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_VehActlGearPosVld_flg_ovrdval = false;/* Referenced by: '<S367>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_VehActlGearPos_enum_ovrdflg = false;/* Referenced by: '<S368>/sat3' */

/* CCU_VehInfo_BAC */
CALDATA const volatile EnumGearPstn KOPM_VehActlGearPos_enum_ovrdval =
  EnumGearPstn_P;                      /* Referenced by: '<S368>/sat4' */

/* CCU_VehInfo_BAC */
CALDATA const volatile boolean KOPM_VehPGearError_flg_ovrdflg = false;/* Referenced by: '<S263>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_VehPGearError_flg_ovrdval = false;/* Referenced by: '<S263>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_VehPwrCnsmpAvrgHi_kWh = 51.0F;/* Referenced by: '<S264>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile float32 KOPM_VehPwrCnsmpAvrgLo_kWh = 0.0F;/* Referenced by: '<S264>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_VehPwrCnsmpAvrg_kWh_ovrdflg = false;/* Referenced by: '<S264>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_VehPwrCnsmpAvrg_kWh_ovrdval = 0.0F;/* Referenced by: '<S264>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_VehTrgtGearPosHi_enum = 7U;/* Referenced by: '<S206>/sat6' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile uint8 KOPM_VehTrgtGearPosLo_enum = 0U;/* Referenced by: '<S206>/sat7' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile boolean KOPM_VehTrgtGearPos_enum_ovrdflg = false;/* Referenced by: '<S206>/sat3' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile EnumTgtGearPstn KOPM_VehTrgtGearPos_enum_ovrdval =
  EnumTgtGearPstn_NoReq;               /* Referenced by: '<S206>/sat4' */

/* VCU_1_InvCmd_EPT */
CALDATA const volatile float32 KOPM_VhclActlCnsmPwrHi_kWh = 51.0F;/* Referenced by: '<S265>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile float32 KOPM_VhclActlCnsmPwrLo_kWh = -51.0F;/* Referenced by: '<S265>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_VhclActlCnsmPwr_kWh_ovrdflg = false;/* Referenced by: '<S265>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_VhclActlCnsmPwr_kWh_ovrdval = 0.0F;/* Referenced by: '<S265>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_VhclSpdFstWarn_flg_ovrdflg = false;/* Referenced by: '<S266>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_VhclSpdFstWarn_flg_ovrdval = false;/* Referenced by: '<S266>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_WLTPDrvgRngDstHi_km = 1023.0F;/* Referenced by: '<S268>/sat6' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile float32 KOPM_WLTPDrvgRngDstLo_km = 0.0F;/* Referenced by: '<S268>/sat7' */

/* VCU_B_AcclPedal_EPT */
CALDATA const volatile boolean KOPM_WLTPDrvgRngDstVld_flg_ovrdflg = false;/* Referenced by: '<S267>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_WLTPDrvgRngDstVld_flg_ovrdval = false;/* Referenced by: '<S267>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_WLTPDrvgRngDst_km_ovrdflg = false;/* Referenced by: '<S268>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_WLTPDrvgRngDst_km_ovrdval = 0.0F;/* Referenced by: '<S268>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_WghConfdence_flg_ovrdflg = false;/* Referenced by: '<S269>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_WghConfdence_flg_ovrdval = false;/* Referenced by: '<S269>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_WghDistbHi_enum = 15U;/* Referenced by: '<S270>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_WghDistbLo_enum = 0U;/* Referenced by: '<S270>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_WghDistb_enum_ovrdflg = false;/* Referenced by: '<S270>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile uint8 KOPM_WghDistb_enum_ovrdval = 0U;/* Referenced by: '<S270>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_WghEstHi_kg = 8000.0F;/* Referenced by: '<S271>/sat6' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_WghEstLo_kg = 0.0F;/* Referenced by: '<S271>/sat7' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_WghEst_kg_ovrdflg = false;/* Referenced by: '<S271>/sat3' */

/* VCU_DispInfo_BAC */
CALDATA const volatile float32 KOPM_WghEst_kg_ovrdval = 0.0F;/* Referenced by: '<S271>/sat4' */

/* VCU_DispInfo_BAC */
CALDATA const volatile boolean KOPM_Zdznswi_flg_ovrdflg = false;/* Referenced by: '<S196>/sat3' */

/* VCU_0_Value_EPT */
CALDATA const volatile boolean KOPM_Zdznswi_flg_ovrdval = false;/* Referenced by: '<S196>/sat4' */

/* VCU_0_Value_EPT */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
