/*
 * File: calPrmsOpm.h
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

#ifndef RTW_HEADER_calPrmsOpm_h_
#define RTW_HEADER_calPrmsOpm_h_
#include "rtwtypes.h"
#include "AppSwcOpm_types.h"

/* Exported data declaration */

/*Group of variables*/
#include "XcpTest_types.h"

/* Declaration for custom storage class: CalParam */
extern CALDATA const volatile uint8 KOPM_12VBatLowVolStaHi_enum;/* Referenced by: '<S329>/sat6' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_12VBatLowVolStaLo_enum;/* Referenced by: '<S329>/sat7' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_12VBatLowVolSta_enum_ovrdflg;/* Referenced by: '<S329>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_12VBatLowVolSta_enum_ovrdval;/* Referenced by: '<S329>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile float32 KOPM_ACActTotPwrHi_kW;/* Referenced by: '<S49>/sat6' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_ACActTotPwrLo_kW;/* Referenced by: '<S49>/sat7' */

/* AC_2_State_BOD */
extern CALDATA const volatile boolean KOPM_ACActTotPwr_kW_ovrdflg;/* Referenced by: '<S49>/sat3' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_ACActTotPwr_kW_ovrdval;/* Referenced by: '<S49>/sat4' */

/* AC_2_State_BOD */
extern CALDATA const volatile uint8 KOPM_ACActlOprtModeHi_enum;/* Referenced by: '<S50>/sat6' */

/* AC_2_State_BOD */
extern CALDATA const volatile uint8 KOPM_ACActlOprtModeLo_enum;/* Referenced by: '<S50>/sat7' */

/* AC_2_State_BOD */
extern CALDATA const volatile boolean KOPM_ACActlOprtMode_enum_ovrdflg;/* Referenced by: '<S50>/sat3' */

/* AC_2_State_BOD */
extern CALDATA const volatile uint8 KOPM_ACActlOprtMode_enum_ovrdval;/* Referenced by: '<S50>/sat4' */

/* AC_2_State_BOD */
extern CALDATA const volatile uint8 KOPM_ACAirInletModeStaHi_enum;/* Referenced by: '<S92>/sat6' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACAirInletModeStaLo_enum;/* Referenced by: '<S92>/sat7' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_ACAirInletModeSta_enum_ovrdflg;/* Referenced by: '<S92>/sat3' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACAirInletModeSta_enum_ovrdval;/* Referenced by: '<S92>/sat4' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACAutoBlwrModeStaHi_enum;/* Referenced by: '<S93>/sat6' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACAutoBlwrModeStaLo_enum;/* Referenced by: '<S93>/sat7' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_ACAutoBlwrModeSta_enum_ovrdflg;/* Referenced by: '<S93>/sat3' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACAutoBlwrModeSta_enum_ovrdval;/* Referenced by: '<S93>/sat4' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_ACAutoFb_flg_ovrdflg;/* Referenced by: '<S94>/sat3' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_ACAutoFb_flg_ovrdval;/* Referenced by: '<S94>/sat4' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACAutoFrntFanSpdHi_enum;/* Referenced by: '<S79>/sat6' */

/* AC_8_status_BOD */
extern CALDATA const volatile uint8 KOPM_ACAutoFrntFanSpdLo_enum;/* Referenced by: '<S79>/sat7' */

/* AC_8_status_BOD */
extern CALDATA const volatile boolean KOPM_ACAutoFrntFanSpd_enum_ovrdflg;/* Referenced by: '<S79>/sat3' */

/* AC_8_status_BOD */
extern CALDATA const volatile uint8 KOPM_ACAutoFrntFanSpd_enum_ovrdval;/* Referenced by: '<S79>/sat4' */

/* AC_8_status_BOD */
extern CALDATA const volatile boolean KOPM_ACBatPmpFailSta_flg_ovrdflg;/* Referenced by: '<S51>/sat3' */

/* AC_2_State_BOD */
extern CALDATA const volatile boolean KOPM_ACBatPmpFailSta_flg_ovrdval;/* Referenced by: '<S51>/sat4' */

/* AC_2_State_BOD */
extern CALDATA const volatile uint8 KOPM_ACBlwrModeStaHi_enum;/* Referenced by: '<S95>/sat6' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACBlwrModeStaLo_enum;/* Referenced by: '<S95>/sat7' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_ACBlwrModeSta_enum_ovrdflg;/* Referenced by: '<S95>/sat3' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACBlwrModeSta_enum_ovrdval;/* Referenced by: '<S95>/sat4' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_ACCMOprtCmd_flg_ovrdflg;/* Referenced by: '<S146>/sat3' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile boolean KOPM_ACCMOprtCmd_flg_ovrdval;/* Referenced by: '<S146>/sat4' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile boolean KOPM_ACCTrqCtrlAvl_flg_ovrdflg;/* Referenced by: '<S260>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_ACCTrqCtrlAvl_flg_ovrdval;/* Referenced by: '<S260>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_ACCompFailModeOprtSta_flg_ovrdflg;/* Referenced by: '<S39>/sat3' */

/* AC_1_Command_BOD */
extern CALDATA const volatile boolean KOPM_ACCompFailModeOprtSta_flg_ovrdval;/* Referenced by: '<S39>/sat4' */

/* AC_1_Command_BOD */
extern CALDATA const volatile float32 KOPM_ACCompMaxAllowPwrCmspHi_kW;/* Referenced by: '<S40>/sat6' */

/* AC_1_Command_BOD */
extern CALDATA const volatile float32 KOPM_ACCompMaxAllowPwrCmspLo_kW;/* Referenced by: '<S40>/sat7' */

/* AC_1_Command_BOD */
extern CALDATA const volatile boolean KOPM_ACCompMaxAllowPwrCmsp_kW_ovrdflg;/* Referenced by: '<S40>/sat3' */

/* AC_1_Command_BOD */
extern CALDATA const volatile float32 KOPM_ACCompMaxAllowPwrCmsp_kW_ovrdval;/* Referenced by: '<S40>/sat4' */

/* AC_1_Command_BOD */
extern CALDATA const volatile boolean KOPM_ACCompOprtEnaCmd_flg_ovrdflg;/* Referenced by: '<S41>/sat3' */

/* AC_1_Command_BOD */
extern CALDATA const volatile boolean KOPM_ACCompOprtEnaCmd_flg_ovrdval;/* Referenced by: '<S41>/sat4' */

/* AC_1_Command_BOD */
extern CALDATA const volatile boolean KOPM_ACCompOprtReq_flg_ovrdflg;/* Referenced by: '<S42>/sat3' */

/* AC_1_Command_BOD */
extern CALDATA const volatile boolean KOPM_ACCompOprtReq_flg_ovrdval;/* Referenced by: '<S42>/sat4' */

/* AC_1_Command_BOD */
extern CALDATA const volatile float32 KOPM_ACCompTgtSpdHi_rpm;/* Referenced by: '<S43>/sat6' */

/* AC_1_Command_BOD */
extern CALDATA const volatile float32 KOPM_ACCompTgtSpdLo_rpm;/* Referenced by: '<S43>/sat7' */

/* AC_1_Command_BOD */
extern CALDATA const volatile boolean KOPM_ACCompTgtSpd_rpm_ovrdflg;/* Referenced by: '<S43>/sat3' */

/* AC_1_Command_BOD */
extern CALDATA const volatile float32 KOPM_ACCompTgtSpd_rpm_ovrdval;/* Referenced by: '<S43>/sat4' */

/* AC_1_Command_BOD */
extern CALDATA const volatile float32 KOPM_ACEnvirTempHi_C;/* Referenced by: '<S66>/sat6' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_ACEnvirTempLo_C;/* Referenced by: '<S66>/sat7' */

/* AC_3_State_BOD */
extern CALDATA const volatile boolean KOPM_ACEnvirTempVld_flg_ovrdflg;/* Referenced by: '<S65>/sat3' */

/* AC_3_State_BOD */
extern CALDATA const volatile boolean KOPM_ACEnvirTempVld_flg_ovrdval;/* Referenced by: '<S65>/sat4' */

/* AC_3_State_BOD */
extern CALDATA const volatile boolean KOPM_ACEnvirTemp_C_ovrdflg;/* Referenced by: '<S66>/sat3' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_ACEnvirTemp_C_ovrdval;/* Referenced by: '<S66>/sat4' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_ACEvapTgtTempHi_C;/* Referenced by: '<S80>/sat6' */

/* AC_8_status_BOD */
extern CALDATA const volatile float32 KOPM_ACEvapTgtTempLo_C;/* Referenced by: '<S80>/sat7' */

/* AC_8_status_BOD */
extern CALDATA const volatile boolean KOPM_ACEvapTgtTemp_C_ovrdflg;/* Referenced by: '<S80>/sat3' */

/* AC_8_status_BOD */
extern CALDATA const volatile float32 KOPM_ACEvapTgtTemp_C_ovrdval;/* Referenced by: '<S80>/sat4' */

/* AC_8_status_BOD */
extern CALDATA const volatile boolean KOPM_ACExtdDefrstActvReq_flg_ovrdflg;/* Referenced by: '<S67>/sat3' */

/* AC_3_State_BOD */
extern CALDATA const volatile boolean KOPM_ACExtdDefrstActvReq_flg_ovrdval;/* Referenced by: '<S67>/sat4' */

/* AC_3_State_BOD */
extern CALDATA const volatile boolean KOPM_ACFailSta_flg_ovrdflg;/* Referenced by: '<S52>/sat3' */

/* AC_2_State_BOD */
extern CALDATA const volatile boolean KOPM_ACFailSta_flg_ovrdval;/* Referenced by: '<S52>/sat4' */

/* AC_2_State_BOD */
extern CALDATA const volatile uint8 KOPM_ACFrntFanSpdValHi_enum;/* Referenced by: '<S96>/sat6' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACFrntFanSpdValLo_enum;/* Referenced by: '<S96>/sat7' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_ACFrntFanSpdVal_enum_ovrdflg;/* Referenced by: '<S96>/sat3' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACFrntFanSpdVal_enum_ovrdval;/* Referenced by: '<S96>/sat4' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACHVHActlOprtModeHi_enum;/* Referenced by: '<S53>/sat6' */

/* AC_2_State_BOD */
extern CALDATA const volatile uint8 KOPM_ACHVHActlOprtModeLo_enum;/* Referenced by: '<S53>/sat7' */

/* AC_2_State_BOD */
extern CALDATA const volatile boolean KOPM_ACHVHActlOprtMode_enum_ovrdflg;/* Referenced by: '<S53>/sat3' */

/* AC_2_State_BOD */
extern CALDATA const volatile uint8 KOPM_ACHVHActlOprtMode_enum_ovrdval;/* Referenced by: '<S53>/sat4' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_ACHVHActlPwrHi_KW;/* Referenced by: '<S54>/sat6' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_ACHVHActlPwrLo_KW;/* Referenced by: '<S54>/sat7' */

/* AC_2_State_BOD */
extern CALDATA const volatile boolean KOPM_ACHVHActlPwr_KW_ovrdflg;/* Referenced by: '<S54>/sat3' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_ACHVHActlPwr_KW_ovrdval;/* Referenced by: '<S54>/sat4' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_ACHVHDevInternTempHi_C;/* Referenced by: '<S55>/sat6' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_ACHVHDevInternTempLo_C;/* Referenced by: '<S55>/sat7' */

/* AC_2_State_BOD */
extern CALDATA const volatile boolean KOPM_ACHVHDevInternTemp_C_ovrdflg;/* Referenced by: '<S55>/sat3' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_ACHVHDevInternTemp_C_ovrdval;/* Referenced by: '<S55>/sat4' */

/* AC_2_State_BOD */
extern CALDATA const volatile boolean KOPM_ACHVHFailSta_flg_ovrdflg;/* Referenced by: '<S56>/sat3' */

/* AC_2_State_BOD */
extern CALDATA const volatile boolean KOPM_ACHVHFailSta_flg_ovrdval;/* Referenced by: '<S56>/sat4' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_ACHVPTCIntPCBTempHi_C;/* Referenced by: '<S81>/sat6' */

/* AC_8_status_BOD */
extern CALDATA const volatile float32 KOPM_ACHVPTCIntPCBTempLo_C;/* Referenced by: '<S81>/sat7' */

/* AC_8_status_BOD */
extern CALDATA const volatile boolean KOPM_ACHVPTCIntPCBTemp_C_ovrdflg;/* Referenced by: '<S81>/sat3' */

/* AC_8_status_BOD */
extern CALDATA const volatile float32 KOPM_ACHVPTCIntPCBTemp_C_ovrdval;/* Referenced by: '<S81>/sat4' */

/* AC_8_status_BOD */
extern CALDATA const volatile float32 KOPM_ACHVPTCMedTempHi_C;/* Referenced by: '<S82>/sat6' */

/* AC_8_status_BOD */
extern CALDATA const volatile float32 KOPM_ACHVPTCMedTempLo_C;/* Referenced by: '<S82>/sat7' */

/* AC_8_status_BOD */
extern CALDATA const volatile boolean KOPM_ACHVPTCMedTemp_C_ovrdflg;/* Referenced by: '<S82>/sat3' */

/* AC_8_status_BOD */
extern CALDATA const volatile float32 KOPM_ACHVPTCMedTemp_C_ovrdval;/* Referenced by: '<S82>/sat4' */

/* AC_8_status_BOD */
extern CALDATA const volatile uint8 KOPM_ACHVPTCOnRqHi_enum;/* Referenced by: '<S83>/sat6' */

/* AC_8_status_BOD */
extern CALDATA const volatile uint8 KOPM_ACHVPTCOnRqLo_enum;/* Referenced by: '<S83>/sat7' */

/* AC_8_status_BOD */
extern CALDATA const volatile boolean KOPM_ACHVPTCOnRq_enum_ovrdflg;/* Referenced by: '<S83>/sat3' */

/* AC_8_status_BOD */
extern CALDATA const volatile uint8 KOPM_ACHVPTCOnRq_enum_ovrdval;/* Referenced by: '<S83>/sat4' */

/* AC_8_status_BOD */
extern CALDATA const volatile uint8 KOPM_ACHVPTCheatingrqHi_pct;/* Referenced by: '<S84>/sat6' */

/* AC_8_status_BOD */
extern CALDATA const volatile uint8 KOPM_ACHVPTCheatingrqLo_pct;/* Referenced by: '<S84>/sat7' */

/* AC_8_status_BOD */
extern CALDATA const volatile boolean KOPM_ACHVPTCheatingrq_pct_ovrdflg;/* Referenced by: '<S84>/sat3' */

/* AC_8_status_BOD */
extern CALDATA const volatile uint8 KOPM_ACHVPTCheatingrq_pct_ovrdval;/* Referenced by: '<S84>/sat4' */

/* AC_8_status_BOD */
extern CALDATA const volatile float32 KOPM_ACHighVolDCTotalPwrHi_kW;/* Referenced by: '<S44>/sat6' */

/* AC_1_Command_BOD */
extern CALDATA const volatile float32 KOPM_ACHighVolDCTotalPwrLo_kW;/* Referenced by: '<S44>/sat7' */

/* AC_1_Command_BOD */
extern CALDATA const volatile boolean KOPM_ACHighVolDCTotalPwr_kW_ovrdflg;/* Referenced by: '<S44>/sat3' */

/* AC_1_Command_BOD */
extern CALDATA const volatile float32 KOPM_ACHighVolDCTotalPwr_kW_ovrdval;/* Referenced by: '<S44>/sat4' */

/* AC_1_Command_BOD */
extern CALDATA const volatile uint8 KOPM_ACHybEcoModeStaHi_enum;/* Referenced by: '<S97>/sat6' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACHybEcoModeStaLo_enum;/* Referenced by: '<S97>/sat7' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_ACHybEcoModeSta_enum_ovrdflg;/* Referenced by: '<S97>/sat3' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACHybEcoModeSta_enum_ovrdval;/* Referenced by: '<S97>/sat4' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile float32 KOPM_ACIndoorTempHi_C;/* Referenced by: '<S68>/sat6' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_ACIndoorTempLo_C;/* Referenced by: '<S68>/sat7' */

/* AC_3_State_BOD */
extern CALDATA const volatile boolean KOPM_ACIndoorTemp_C_ovrdflg;/* Referenced by: '<S68>/sat3' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_ACIndoorTemp_C_ovrdval;/* Referenced by: '<S68>/sat4' */

/* AC_3_State_BOD */
extern CALDATA const volatile boolean KOPM_ACLCurrtSlctFrgDirct_flg_ovrdflg;/* Referenced by: '<S85>/sat3' */

/* AC_8_status_BOD */
extern CALDATA const volatile boolean KOPM_ACLCurrtSlctFrgDirct_flg_ovrdval;/* Referenced by: '<S85>/sat4' */

/* AC_8_status_BOD */
extern CALDATA const volatile uint8 KOPM_ACLeftTempValHi_enum;/* Referenced by: '<S98>/sat6' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACLeftTempValLo_enum;/* Referenced by: '<S98>/sat7' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_ACLeftTempVal_enum_ovrdflg;/* Referenced by: '<S98>/sat3' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACLeftTempVal_enum_ovrdval;/* Referenced by: '<S98>/sat4' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_ACManlDefrstFb_flg_ovrdflg;/* Referenced by: '<S99>/sat3' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_ACManlDefrstFb_flg_ovrdval;/* Referenced by: '<S99>/sat4' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_ACPumpActlSpdDutyHi_pct;/* Referenced by: '<S46>/sat6' */

/* AC_1_Command_BOD */
extern CALDATA const volatile uint8 KOPM_ACPumpActlSpdDutyLo_pct;/* Referenced by: '<S46>/sat7' */

/* AC_1_Command_BOD */
extern CALDATA const volatile boolean KOPM_ACPumpActlSpdDutyVld_flg_ovrdflg;/* Referenced by: '<S45>/sat3' */

/* AC_1_Command_BOD */
extern CALDATA const volatile boolean KOPM_ACPumpActlSpdDutyVld_flg_ovrdval;/* Referenced by: '<S45>/sat4' */

/* AC_1_Command_BOD */
extern CALDATA const volatile boolean KOPM_ACPumpActlSpdDuty_pct_ovrdflg;/* Referenced by: '<S46>/sat3' */

/* AC_1_Command_BOD */
extern CALDATA const volatile uint8 KOPM_ACPumpActlSpdDuty_pct_ovrdval;/* Referenced by: '<S46>/sat4' */

/* AC_1_Command_BOD */
extern CALDATA const volatile boolean KOPM_ACPwrFb_flg_ovrdflg;/* Referenced by: '<S100>/sat3' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_ACPwrFb_flg_ovrdval;/* Referenced by: '<S100>/sat4' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile float32 KOPM_ACRefrgLoPresHi_kPa;/* Referenced by: '<S87>/sat6' */

/* AC_8_status_BOD */
extern CALDATA const volatile float32 KOPM_ACRefrgLoPresLo_kPa;/* Referenced by: '<S87>/sat7' */

/* AC_8_status_BOD */
extern CALDATA const volatile boolean KOPM_ACRefrgLoPresVld_flg_ovrdflg;/* Referenced by: '<S86>/sat3' */

/* AC_8_status_BOD */
extern CALDATA const volatile boolean KOPM_ACRefrgLoPresVld_flg_ovrdval;/* Referenced by: '<S86>/sat4' */

/* AC_8_status_BOD */
extern CALDATA const volatile boolean KOPM_ACRefrgLoPres_kPa_ovrdflg;/* Referenced by: '<S87>/sat3' */

/* AC_8_status_BOD */
extern CALDATA const volatile float32 KOPM_ACRefrgLoPres_kPa_ovrdval;/* Referenced by: '<S87>/sat4' */

/* AC_8_status_BOD */
extern CALDATA const volatile uint8 KOPM_AccPedPosSnsrStaHi_enum;/* Referenced by: '<S261>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_AccPedPosSnsrStaLo_enum;/* Referenced by: '<S261>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_AccPedPosSnsrSta_enum_ovrdflg;/* Referenced by: '<S261>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile EnumAccPedSnsrSt
  KOPM_AccPedPosSnsrSta_enum_ovrdval;  /* Referenced by: '<S261>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_AccPedPosToESCHi_pct;/* Referenced by: '<S263>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_AccPedPosToESCLo_pct;/* Referenced by: '<S263>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_AccPedPosToESCStaHi_enum;/* Referenced by: '<S262>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_AccPedPosToESCStaLo_enum;/* Referenced by: '<S262>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_AccPedPosToESCSta_enum_ovrdflg;/* Referenced by: '<S262>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_AccPedPosToESCSta_enum_ovrdval;/* Referenced by: '<S262>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_AccPedPosToESC_pct_ovrdflg;/* Referenced by: '<S263>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_AccPedPosToESC_pct_ovrdval;/* Referenced by: '<S263>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_AcclPedalPosHi_pct;/* Referenced by: '<S264>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_AcclPedalPosLo_pct;/* Referenced by: '<S264>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_AcclPedalPos_pct_ovrdflg;/* Referenced by: '<S264>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_AcclPedalPos_pct_ovrdval;/* Referenced by: '<S264>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_ActWhlTqHi_Nm;/* Referenced by: '<S167>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_ActWhlTqLo_Nm;/* Referenced by: '<S167>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_ActWhlTqVld_flg_ovrdflg;/* Referenced by: '<S166>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_ActWhlTqVld_flg_ovrdval;/* Referenced by: '<S166>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_ActWhlTq_Nm_ovrdflg;/* Referenced by: '<S167>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_ActWhlTq_Nm_ovrdval;/* Referenced by: '<S167>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_ActlMotorRotateSpdHi_rpm;/* Referenced by: '<S169>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_ActlMotorRotateSpdLo_rpm;/* Referenced by: '<S169>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_ActlMotorRotateSpdVld_flg_ovrdflg;/* Referenced by: '<S168>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_ActlMotorRotateSpdVld_flg_ovrdval;/* Referenced by: '<S168>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_ActlMotorRotateSpd_rpm_ovrdflg;/* Referenced by: '<S169>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_ActlMotorRotateSpd_rpm_ovrdval;/* Referenced by: '<S169>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_ActlMotorTorqHi_Nm;/* Referenced by: '<S171>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_ActlMotorTorqLo_Nm;/* Referenced by: '<S171>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_ActlMotorTorqVld_flg_ovrdflg;/* Referenced by: '<S170>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_ActlMotorTorqVld_flg_ovrdval;/* Referenced by: '<S170>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_ActlMotorTorq_Nm_ovrdflg;/* Referenced by: '<S171>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_ActlMotorTorq_Nm_ovrdval;/* Referenced by: '<S171>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_AllowHeatCoolMaxPwrCmspHi_kW;/* Referenced by: '<S298>/sat6' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_AllowHeatCoolMaxPwrCmspLo_kW;/* Referenced by: '<S298>/sat7' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_AllowHeatCoolMaxPwrCmsp_kW_ovrdflg;/* Referenced by: '<S298>/sat3' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_AllowHeatCoolMaxPwrCmsp_kW_ovrdval;/* Referenced by: '<S298>/sat4' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile uint8 KOPM_AppSoftNumbHi_nu;/* Referenced by: '<S201>/sat6' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile uint8 KOPM_AppSoftNumbLo_nu;/* Referenced by: '<S201>/sat7' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile boolean KOPM_AppSoftNumb_nu_ovrdflg;/* Referenced by: '<S201>/sat3' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile uint8 KOPM_AppSoftNumb_nu_ovrdval;/* Referenced by: '<S201>/sat4' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile boolean KOPM_BCMAjarStaHood_flg_ovrdflg;/* Referenced by: '<S346>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMAjarStaHood_flg_ovrdval;/* Referenced by: '<S346>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMAjarStaTrunk_flg_ovrdflg;/* Referenced by: '<S347>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMAjarStaTrunk_flg_ovrdval;/* Referenced by: '<S347>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMAjarStaVHoodVld_flg_ovrdflg;/* Referenced by: '<S348>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMAjarStaVHoodVld_flg_ovrdval;/* Referenced by: '<S348>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMAlrmHornReq_flg_ovrdflg;/* Referenced by: '<S349>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMAlrmHornReq_flg_ovrdval;/* Referenced by: '<S349>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMAuthentKeyNrHi_enum;/* Referenced by: '<S350>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMAuthentKeyNrLo_enum;/* Referenced by: '<S350>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMAuthentKeyNr_enum_ovrdflg;/* Referenced by: '<S350>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMAuthentKeyNr_enum_ovrdval;/* Referenced by: '<S350>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMAutoLampStatus_flg_ovrdflg;/* Referenced by: '<S351>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMAutoLampStatus_flg_ovrdval;/* Referenced by: '<S351>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMAvaluebleKeyInCar_flg_ovrdflg;/* Referenced by: '<S352>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMAvaluebleKeyInCar_flg_ovrdval;/* Referenced by: '<S352>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMBackLadjvalFbHi_enum;/* Referenced by: '<S353>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMBackLadjvalFbLo_enum;/* Referenced by: '<S353>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMBackLadjvalFb_enum_ovrdflg;/* Referenced by: '<S353>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMBackLadjvalFb_enum_ovrdval;/* Referenced by: '<S353>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMBassHornReqHi_enum;/* Referenced by: '<S354>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMBassHornReqLo_enum;/* Referenced by: '<S354>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMBassHornReq_enum_ovrdflg;/* Referenced by: '<S354>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMBassHornReq_enum_ovrdval;/* Referenced by: '<S354>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMBodyWarnStsHi_enum;/* Referenced by: '<S355>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMBodyWarnStsLo_enum;/* Referenced by: '<S355>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMBodyWarnSts_enum_ovrdflg;/* Referenced by: '<S355>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMBodyWarnSts_enum_ovrdval;/* Referenced by: '<S355>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMBrakeLampSta_flg_ovrdflg;/* Referenced by: '<S356>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMBrakeLampSta_flg_ovrdval;/* Referenced by: '<S356>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMBrkPedSta_flg_ovrdflg;/* Referenced by: '<S330>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_BCMBrkPedSta_flg_ovrdval;/* Referenced by: '<S330>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMCenLckStsHi_enum;/* Referenced by: '<S331>/sat6' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMCenLckStsLo_enum;/* Referenced by: '<S331>/sat7' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_BCMCenLckSts_enum_ovrdflg;/* Referenced by: '<S331>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMCenLckSts_enum_ovrdval;/* Referenced by: '<S331>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMCenLckSwCtrlFbHi_enum;/* Referenced by: '<S332>/sat6' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMCenLckSwCtrlFbLo_enum;/* Referenced by: '<S332>/sat7' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_BCMCenLckSwCtrlFb_enum_ovrdflg;/* Referenced by: '<S332>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMCenLckSwCtrlFb_enum_ovrdval;/* Referenced by: '<S332>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMChgWiprMtMdSwSetFbHi_enum;/* Referenced by: '<S357>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMChgWiprMtMdSwSetFbLo_enum;/* Referenced by: '<S357>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMChgWiprMtMdSwSetFb_enum_ovrdflg;/* Referenced by: '<S357>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMChgWiprMtMdSwSetFb_enum_ovrdval;/* Referenced by: '<S357>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMChrgLidLockReqHi_enum;/* Referenced by: '<S358>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMChrgLidLockReqLo_enum;/* Referenced by: '<S358>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMChrgLidLockReq_enum_ovrdflg;/* Referenced by: '<S358>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMChrgLidLockReq_enum_ovrdval;/* Referenced by: '<S358>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDayRunLiSwSig_flg_ovrdflg;/* Referenced by: '<S359>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDayRunLiSwSig_flg_ovrdval;/* Referenced by: '<S359>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDayRunLightSta_flg_ovrdflg;/* Referenced by: '<S360>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDayRunLightSta_flg_ovrdval;/* Referenced by: '<S360>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDoorAjarStaFL_flg_ovrdflg;/* Referenced by: '<S361>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDoorAjarStaFL_flg_ovrdval;/* Referenced by: '<S361>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDoorAjarStaFR_flg_ovrdflg;/* Referenced by: '<S362>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDoorAjarStaFR_flg_ovrdval;/* Referenced by: '<S362>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDoorAjarStaRL_flg_ovrdflg;/* Referenced by: '<S363>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDoorAjarStaRL_flg_ovrdval;/* Referenced by: '<S363>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDoorAjarStaRR_flg_ovrdflg;/* Referenced by: '<S364>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDoorAjarStaRR_flg_ovrdval;/* Referenced by: '<S364>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDoorLckStaFL_flg_ovrdflg;/* Referenced by: '<S333>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_BCMDoorLckStaFL_flg_ovrdval;/* Referenced by: '<S333>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMDrvPEAuthentAcsdHi_enum;/* Referenced by: '<S365>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMDrvPEAuthentAcsdLo_enum;/* Referenced by: '<S365>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDrvPEAuthentAcsd_enum_ovrdflg;/* Referenced by: '<S365>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMDrvPEAuthentAcsd_enum_ovrdval;/* Referenced by: '<S365>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMDrvSeatOccptSnsrStsHi_enum;/* Referenced by: '<S366>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMDrvSeatOccptSnsrStsLo_enum;/* Referenced by: '<S366>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDrvSeatOccptSnsrSts_enum_ovrdflg;/* Referenced by: '<S366>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMDrvSeatOccptSnsrSts_enum_ovrdval;/* Referenced by: '<S366>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMDrvrWinSwSigHi_enum;/* Referenced by: '<S367>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMDrvrWinSwSigLo_enum;/* Referenced by: '<S367>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMDrvrWinSwSig_enum_ovrdflg;/* Referenced by: '<S367>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMDrvrWinSwSig_enum_ovrdval;/* Referenced by: '<S367>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFLWinSts_flg_ovrdflg;/* Referenced by: '<S368>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFLWinSts_flg_ovrdval;/* Referenced by: '<S368>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFLWinmotorStsHi_enum;/* Referenced by: '<S369>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFLWinmotorStsLo_enum;/* Referenced by: '<S369>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFLWinmotorSts_enum_ovrdflg;/* Referenced by: '<S369>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFLWinmotorSts_enum_ovrdval;/* Referenced by: '<S369>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFRPEAuthentAcsdHi_enum;/* Referenced by: '<S370>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFRPEAuthentAcsdLo_enum;/* Referenced by: '<S370>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFRPEAuthentAcsd_enum_ovrdflg;/* Referenced by: '<S370>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFRPEAuthentAcsd_enum_ovrdval;/* Referenced by: '<S370>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFRWinSts_flg_ovrdflg;/* Referenced by: '<S371>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFRWinSts_flg_ovrdval;/* Referenced by: '<S371>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFRWinmotorStsHi_enum;/* Referenced by: '<S372>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFRWinmotorStsLo_enum;/* Referenced by: '<S372>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFRWinmotorSts_enum_ovrdflg;/* Referenced by: '<S372>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFRWinmotorSts_enum_ovrdval;/* Referenced by: '<S372>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFlwrMeHmCtrlFbHi_enum;/* Referenced by: '<S373>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFlwrMeHmCtrlFbLo_enum;/* Referenced by: '<S373>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFlwrMeHmCtrlFb_enum_ovrdflg;/* Referenced by: '<S373>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFlwrMeHmCtrlFb_enum_ovrdval;/* Referenced by: '<S373>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFogLampStaFront_flg_ovrdflg;/* Referenced by: '<S374>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFogLampStaFront_flg_ovrdval;/* Referenced by: '<S374>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFogLampStaRear_flg_ovrdflg;/* Referenced by: '<S375>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFogLampStaRear_flg_ovrdval;/* Referenced by: '<S375>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFrbdnKeyNrHi_enum;/* Referenced by: '<S376>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFrbdnKeyNrLo_enum;/* Referenced by: '<S376>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFrbdnKeyNr_enum_ovrdflg;/* Referenced by: '<S376>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFrbdnKeyNr_enum_ovrdval;/* Referenced by: '<S376>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFrntFogLiSwSig_flg_ovrdflg;/* Referenced by: '<S377>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFrntFogLiSwSig_flg_ovrdval;/* Referenced by: '<S377>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFrntLeDoorHndlSwtHi_enum;/* Referenced by: '<S378>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFrntLeDoorHndlSwtLo_enum;/* Referenced by: '<S378>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFrntLeDoorHndlSwt_enum_ovrdflg;/* Referenced by: '<S378>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFrntLeDoorHndlSwt_enum_ovrdval;/* Referenced by: '<S378>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFrntRiDoorHndlSwtHi_enum;/* Referenced by: '<S379>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFrntRiDoorHndlSwtLo_enum;/* Referenced by: '<S379>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFrntRiDoorHndlSwt_enum_ovrdflg;/* Referenced by: '<S379>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFrntRiDoorHndlSwt_enum_ovrdval;/* Referenced by: '<S379>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFrntWiprMotStsHi_enum;/* Referenced by: '<S380>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFrntWiprMotStsLo_enum;/* Referenced by: '<S380>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFrntWiprMotSts_enum_ovrdflg;/* Referenced by: '<S380>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMFrntWiprMotSts_enum_ovrdval;/* Referenced by: '<S380>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFrntWshrSwSig_flg_ovrdflg;/* Referenced by: '<S381>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFrntWshrSwSig_flg_ovrdval;/* Referenced by: '<S381>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFrontWashSts_flg_ovrdflg;/* Referenced by: '<S382>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMFrontWashSts_flg_ovrdval;/* Referenced by: '<S382>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMHazardLampSts_flg_ovrdflg;/* Referenced by: '<S383>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMHazardLampSts_flg_ovrdval;/* Referenced by: '<S383>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiBeamSwSigHi_enum;/* Referenced by: '<S384>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiBeamSwSigLo_enum;/* Referenced by: '<S384>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiBeamSwSig_enum_ovrdflg;/* Referenced by: '<S384>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiBeamSwSig_enum_ovrdval;/* Referenced by: '<S384>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte0Hi_nu;/* Referenced by: '<S11>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte0Lo_nu;/* Referenced by: '<S11>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte0_nu_ovrdflg;/* Referenced by: '<S11>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte0_nu_ovrdval;/* Referenced by: '<S11>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte10Hi_nu;/* Referenced by: '<S12>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte10Lo_nu;/* Referenced by: '<S12>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte10_nu_ovrdflg;/* Referenced by: '<S12>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte10_nu_ovrdval;/* Referenced by: '<S12>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte11Hi_nu;/* Referenced by: '<S13>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte11Lo_nu;/* Referenced by: '<S13>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte11_nu_ovrdflg;/* Referenced by: '<S13>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte11_nu_ovrdval;/* Referenced by: '<S13>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte12Hi_nu;/* Referenced by: '<S14>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte12Lo_nu;/* Referenced by: '<S14>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte12_nu_ovrdflg;/* Referenced by: '<S14>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte12_nu_ovrdval;/* Referenced by: '<S14>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte13Hi_nu;/* Referenced by: '<S15>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte13Lo_nu;/* Referenced by: '<S15>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte13_nu_ovrdflg;/* Referenced by: '<S15>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte13_nu_ovrdval;/* Referenced by: '<S15>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte14Hi_nu;/* Referenced by: '<S16>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte14Lo_nu;/* Referenced by: '<S16>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte14_nu_ovrdflg;/* Referenced by: '<S16>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte14_nu_ovrdval;/* Referenced by: '<S16>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte15Hi_nu;/* Referenced by: '<S17>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte15Lo_nu;/* Referenced by: '<S17>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte15_nu_ovrdflg;/* Referenced by: '<S17>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte15_nu_ovrdval;/* Referenced by: '<S17>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte1Hi_nu;/* Referenced by: '<S18>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte1Lo_nu;/* Referenced by: '<S18>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte1_nu_ovrdflg;/* Referenced by: '<S18>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte1_nu_ovrdval;/* Referenced by: '<S18>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte2Hi_nu;/* Referenced by: '<S19>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte2Lo_nu;/* Referenced by: '<S19>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte2_nu_ovrdflg;/* Referenced by: '<S19>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte2_nu_ovrdval;/* Referenced by: '<S19>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte3Hi_nu;/* Referenced by: '<S20>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte3Lo_nu;/* Referenced by: '<S20>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte3_nu_ovrdflg;/* Referenced by: '<S20>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte3_nu_ovrdval;/* Referenced by: '<S20>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte4Hi_nu;/* Referenced by: '<S21>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte4Lo_nu;/* Referenced by: '<S21>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte4_nu_ovrdflg;/* Referenced by: '<S21>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte4_nu_ovrdval;/* Referenced by: '<S21>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte5Hi_nu;/* Referenced by: '<S22>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte5Lo_nu;/* Referenced by: '<S22>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte5_nu_ovrdflg;/* Referenced by: '<S22>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte5_nu_ovrdval;/* Referenced by: '<S22>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte6Hi_nu;/* Referenced by: '<S23>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte6Lo_nu;/* Referenced by: '<S23>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte6_nu_ovrdflg;/* Referenced by: '<S23>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte6_nu_ovrdval;/* Referenced by: '<S23>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte7Hi_nu;/* Referenced by: '<S24>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte7Lo_nu;/* Referenced by: '<S24>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte7_nu_ovrdflg;/* Referenced by: '<S24>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte7_nu_ovrdval;/* Referenced by: '<S24>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte8Hi_nu;/* Referenced by: '<S25>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte8Lo_nu;/* Referenced by: '<S25>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte8_nu_ovrdflg;/* Referenced by: '<S25>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte8_nu_ovrdval;/* Referenced by: '<S25>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte9Hi_nu;/* Referenced by: '<S26>/sat6' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte9Lo_nu;/* Referenced by: '<S26>/sat7' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHiFreqSigDataByte9_nu_ovrdflg;/* Referenced by: '<S26>/sat3' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile uint8 KOPM_BCMHiFreqSigDataByte9_nu_ovrdval;/* Referenced by: '<S26>/sat4' */

/* BCM_HFSData_BAC */
extern CALDATA const volatile boolean KOPM_BCMHighBeamSta_flg_ovrdflg;/* Referenced by: '<S385>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMHighBeamSta_flg_ovrdval;/* Referenced by: '<S385>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMHvyRainInd_flg_ovrdflg;/* Referenced by: '<S386>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMHvyRainInd_flg_ovrdval;/* Referenced by: '<S386>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMHzrdWrngLghtSwSig_flg_ovrdflg;/* Referenced by: '<S387>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMHzrdWrngLghtSwSig_flg_ovrdval;/* Referenced by: '<S387>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMIllmndEntryStsFb_flg_ovrdflg;/* Referenced by: '<S388>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMIllmndEntryStsFb_flg_ovrdval;/* Referenced by: '<S388>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMIllmndLampReq_flg_ovrdflg;/* Referenced by: '<S389>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMIllmndLampReq_flg_ovrdval;/* Referenced by: '<S389>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMIllmndLckStsFb_flg_ovrdflg;/* Referenced by: '<S223>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_BCMIllmndLckStsFb_flg_ovrdval;/* Referenced by: '<S223>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMIllmndLockReqHi_enum;/* Referenced by: '<S390>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMIllmndLockReqLo_enum;/* Referenced by: '<S390>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMIllmndLockReq_enum_ovrdflg;/* Referenced by: '<S390>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMIllmndLockReq_enum_ovrdval;/* Referenced by: '<S390>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMIllmndStsHi_enum;/* Referenced by: '<S391>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMIllmndStsLo_enum;/* Referenced by: '<S391>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMIllmndSts_enum_ovrdflg;/* Referenced by: '<S391>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMIllmndSts_enum_ovrdval;/* Referenced by: '<S391>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMIllmndUnlckStsFb_flg_ovrdflg;/* Referenced by: '<S224>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_BCMIllmndUnlckStsFb_flg_ovrdval;/* Referenced by: '<S224>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_BCMIndcnKeyClsr_flg_ovrdflg;/* Referenced by: '<S392>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMIndcnKeyClsr_flg_ovrdval;/* Referenced by: '<S392>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMIndcnShfttoNeut_flg_ovrdflg;/* Referenced by: '<S393>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMIndcnShfttoNeut_flg_ovrdval;/* Referenced by: '<S393>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile float32 KOPM_BCMKeyBattLvlHi_pct;/* Referenced by: '<S395>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile float32 KOPM_BCMKeyBattLvlLo_pct;/* Referenced by: '<S395>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMKeyBattLvlSts_flg_ovrdflg;/* Referenced by: '<S394>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMKeyBattLvlSts_flg_ovrdval;/* Referenced by: '<S394>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMKeyBattLvl_pct_ovrdflg;/* Referenced by: '<S395>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile float32 KOPM_BCMKeyBattLvl_pct_ovrdval;/* Referenced by: '<S395>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMKeyFrbdn_flg_ovrdflg;/* Referenced by: '<S396>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMKeyFrbdn_flg_ovrdval;/* Referenced by: '<S396>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMKeyIDFbHi_enum;/* Referenced by: '<S397>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMKeyIDFbLo_enum;/* Referenced by: '<S397>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMKeyIDFb_enum_ovrdflg;/* Referenced by: '<S397>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMKeyIDFb_enum_ovrdval;/* Referenced by: '<S397>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMKeyInCarSta_flg_ovrdflg;/* Referenced by: '<S398>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMKeyInCarSta_flg_ovrdval;/* Referenced by: '<S398>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMKeyLoBattLvlWarn_flg_ovrdflg;/* Referenced by: '<S399>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMKeyLoBattLvlWarn_flg_ovrdval;/* Referenced by: '<S399>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint16 KOPM_BCMKeyLocnHi_mm;/* Referenced by: '<S400>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint16 KOPM_BCMKeyLocnLo_mm;/* Referenced by: '<S400>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMKeyLocn_mm_ovrdflg;/* Referenced by: '<S400>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint16 KOPM_BCMKeyLocn_mm_ovrdval;/* Referenced by: '<S400>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMKeyStaHi_enum;/* Referenced by: '<S401>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMKeyStaLo_enum;/* Referenced by: '<S401>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMKeySta_enum_ovrdflg;/* Referenced by: '<S401>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMKeySta_enum_ovrdval;/* Referenced by: '<S401>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMLckHornOnStFb_flg_ovrdflg;/* Referenced by: '<S402>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMLckHornOnStFb_flg_ovrdval;/* Referenced by: '<S402>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLeTrnLiFltFbHi_enum;/* Referenced by: '<S403>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLeTrnLiFltFbLo_enum;/* Referenced by: '<S403>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMLeTrnLiFltFb_enum_ovrdflg;/* Referenced by: '<S403>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLeTrnLiFltFb_enum_ovrdval;/* Referenced by: '<S403>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLghtSwSigHi_enum;/* Referenced by: '<S404>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLghtSwSigLo_enum;/* Referenced by: '<S404>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMLghtSwSig_enum_ovrdflg;/* Referenced by: '<S404>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLghtSwSig_enum_ovrdval;/* Referenced by: '<S404>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLightIntensityHi_enum;/* Referenced by: '<S405>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLightIntensityLo_enum;/* Referenced by: '<S405>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMLightIntensity_enum_ovrdflg;/* Referenced by: '<S405>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLightIntensity_enum_ovrdval;/* Referenced by: '<S405>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLogoActvFlgHi_enum;/* Referenced by: '<S406>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLogoActvFlgLo_enum;/* Referenced by: '<S406>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMLogoActvFlg_enum_ovrdflg;/* Referenced by: '<S406>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLogoActvFlg_enum_ovrdval;/* Referenced by: '<S406>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMLowBeamSta_flg_ovrdflg;/* Referenced by: '<S407>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMLowBeamSta_flg_ovrdval;/* Referenced by: '<S407>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMLrngData02Hi_nu;/* Referenced by: '<S155>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData02Lo_nu;/* Referenced by: '<S155>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile boolean KOPM_BCMLrngData02_nu_ovrdflg;/* Referenced by: '<S155>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData02_nu_ovrdval;/* Referenced by: '<S155>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData03Hi_nu;/* Referenced by: '<S156>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData03Lo_nu;/* Referenced by: '<S156>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile boolean KOPM_BCMLrngData03_nu_ovrdflg;/* Referenced by: '<S156>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData03_nu_ovrdval;/* Referenced by: '<S156>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData04Hi_nu;/* Referenced by: '<S157>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData04Lo_nu;/* Referenced by: '<S157>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile boolean KOPM_BCMLrngData04_nu_ovrdflg;/* Referenced by: '<S157>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData04_nu_ovrdval;/* Referenced by: '<S157>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData05Hi_nu;/* Referenced by: '<S158>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData05Lo_nu;/* Referenced by: '<S158>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile boolean KOPM_BCMLrngData05_nu_ovrdflg;/* Referenced by: '<S158>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData05_nu_ovrdval;/* Referenced by: '<S158>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData06Hi_nu;/* Referenced by: '<S159>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData06Lo_nu;/* Referenced by: '<S159>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile boolean KOPM_BCMLrngData06_nu_ovrdflg;/* Referenced by: '<S159>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData06_nu_ovrdval;/* Referenced by: '<S159>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData07Hi_nu;/* Referenced by: '<S160>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData07Lo_nu;/* Referenced by: '<S160>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile boolean KOPM_BCMLrngData07_nu_ovrdflg;/* Referenced by: '<S160>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngData07_nu_ovrdval;/* Referenced by: '<S160>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngStsHi_enum;/* Referenced by: '<S161>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngStsLo_enum;/* Referenced by: '<S161>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile boolean KOPM_BCMLrngSts_enum_ovrdflg;/* Referenced by: '<S161>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngSts_enum_ovrdval;/* Referenced by: '<S161>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngsubIDHi_cnt;/* Referenced by: '<S162>/sat6' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngsubIDLo_cnt;/* Referenced by: '<S162>/sat7' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile boolean KOPM_BCMLrngsubID_cnt_ovrdflg;/* Referenced by: '<S162>/sat3' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMLrngsubID_cnt_ovrdval;/* Referenced by: '<S162>/sat4' */

/* BCM_IMMOAuthResp1_EPT */
extern CALDATA const volatile uint8 KOPM_BCMMaiDrvrSeatStsHi_enum;/* Referenced by: '<S408>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMMaiDrvrSeatStsLo_enum;/* Referenced by: '<S408>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMMaiDrvrSeatSts_enum_ovrdflg;/* Referenced by: '<S408>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMMaiDrvrSeatSts_enum_ovrdval;/* Referenced by: '<S408>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile float32 KOPM_BCMMaiDrvrSeatTempHi_C;/* Referenced by: '<S409>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile float32 KOPM_BCMMaiDrvrSeatTempLo_C;/* Referenced by: '<S409>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMMaiDrvrSeatTemp_C_ovrdflg;/* Referenced by: '<S409>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile float32 KOPM_BCMMaiDrvrSeatTemp_C_ovrdval;/* Referenced by: '<S409>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMOvrspdCntrlLckSetFb_flg_ovrdflg;/* Referenced by: '<S410>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMOvrspdCntrlLckSetFb_flg_ovrdval;/* Referenced by: '<S410>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMPSAuthentResHi_enum;/* Referenced by: '<S411>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMPSAuthentResLo_enum;/* Referenced by: '<S411>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMPSAuthentRes_enum_ovrdflg;/* Referenced by: '<S411>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMPSAuthentRes_enum_ovrdval;/* Referenced by: '<S411>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMPSReq_flg_ovrdflg;/* Referenced by: '<S412>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMPSReq_flg_ovrdval;/* Referenced by: '<S412>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMParkAutoUnlckSetFb_flg_ovrdflg;/* Referenced by: '<S413>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMParkAutoUnlckSetFb_flg_ovrdval;/* Referenced by: '<S413>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMPassWinSwSigHi_enum;/* Referenced by: '<S414>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMPassWinSwSigLo_enum;/* Referenced by: '<S414>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMPassWinSwSig_enum_ovrdflg;/* Referenced by: '<S414>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMPassWinSwSig_enum_ovrdval;/* Referenced by: '<S414>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMPaswdwInit_flg_ovrdflg;/* Referenced by: '<S415>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMPaswdwInit_flg_ovrdval;/* Referenced by: '<S415>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMPosLampSta_flg_ovrdflg;/* Referenced by: '<S416>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMPosLampSta_flg_ovrdval;/* Referenced by: '<S416>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMRFInitSta_flg_ovrdflg;/* Referenced by: '<S417>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMRFInitSta_flg_ovrdval;/* Referenced by: '<S417>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMRKEReqHi_enum;/* Referenced by: '<S418>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMRKEReqLo_enum;/* Referenced by: '<S418>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMRKEReq_enum_ovrdflg;/* Referenced by: '<S418>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMRKEReq_enum_ovrdval;/* Referenced by: '<S418>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMReverseLampSta_flg_ovrdflg;/* Referenced by: '<S419>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMReverseLampSta_flg_ovrdval;/* Referenced by: '<S419>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMRiTrnLiFltFbHi_enum;/* Referenced by: '<S420>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMRiTrnLiFltFbLo_enum;/* Referenced by: '<S420>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMRiTrnLiFltFb_enum_ovrdflg;/* Referenced by: '<S420>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMRiTrnLiFltFb_enum_ovrdval;/* Referenced by: '<S420>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMRrFogLiSwSig_flg_ovrdflg;/* Referenced by: '<S421>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMRrFogLiSwSig_flg_ovrdval;/* Referenced by: '<S421>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMRrMirrHeatSts_flg_ovrdflg;/* Referenced by: '<S422>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMRrMirrHeatSts_flg_ovrdval;/* Referenced by: '<S422>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMRrViewMirrHeatgSts_flg_ovrdflg;/* Referenced by: '<S101>/sat3' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile boolean KOPM_BCMRrViewMirrHeatgSts_flg_ovrdval;/* Referenced by: '<S101>/sat4' */

/* AC_ACStatuts_BOD */
extern CALDATA const volatile uint8 KOPM_BCMStartReqHi_enum;/* Referenced by: '<S423>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMStartReqLo_enum;/* Referenced by: '<S423>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMStartReq_enum_ovrdflg;/* Referenced by: '<S423>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMStartReq_enum_ovrdval;/* Referenced by: '<S423>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMSteerWhlHeatStsHi_flg;/* Referenced by: '<S424>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMSteerWhlHeatStsLo_flg;/* Referenced by: '<S424>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMSteerWhlHeatSts_flg_ovrdflg;/* Referenced by: '<S424>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMSteerWhlHeatSts_flg_ovrdval;/* Referenced by: '<S424>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile float32 KOPM_BCMSteerWhlTempHi_C;/* Referenced by: '<S425>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile float32 KOPM_BCMSteerWhlTempLo_C;/* Referenced by: '<S425>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMSteerWhlTemp_C_ovrdflg;/* Referenced by: '<S425>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile float32 KOPM_BCMSteerWhlTemp_C_ovrdval;/* Referenced by: '<S425>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMSysPowerStsHi_enum;/* Referenced by: '<S334>/sat6' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMSysPowerStsLo_enum;/* Referenced by: '<S334>/sat7' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_BCMSysPowerSts_enum_ovrdflg;/* Referenced by: '<S334>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMSysPowerSts_enum_ovrdval;/* Referenced by: '<S334>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMSysPwrModeHi_enum;/* Referenced by: '<S336>/sat6' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMSysPwrModeLo_enum;/* Referenced by: '<S336>/sat7' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_BCMSysPwrModeVld_flg_ovrdflg;/* Referenced by: '<S335>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_BCMSysPwrModeVld_flg_ovrdval;/* Referenced by: '<S335>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_BCMSysPwrMode_enum_ovrdflg;/* Referenced by: '<S336>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMSysPwrMode_enum_ovrdval;/* Referenced by: '<S336>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_BCMTPMSRstStsHi_enum;/* Referenced by: '<S426>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMTPMSRstStsLo_enum;/* Referenced by: '<S426>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTPMSRstSts_enum_ovrdflg;/* Referenced by: '<S426>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMTPMSRstSts_enum_ovrdval;/* Referenced by: '<S426>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTrnkLckSta_flg_ovrdflg;/* Referenced by: '<S427>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTrnkLckSta_flg_ovrdval;/* Referenced by: '<S427>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTrnkLckSwCtrlFb_flg_ovrdflg;/* Referenced by: '<S428>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTrnkLckSwCtrlFb_flg_ovrdval;/* Referenced by: '<S428>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMTrnngLiSwSigHi_enum;/* Referenced by: '<S429>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMTrnngLiSwSigLo_enum;/* Referenced by: '<S429>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTrnngLiSwSig_enum_ovrdflg;/* Referenced by: '<S429>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMTrnngLiSwSig_enum_ovrdval;/* Referenced by: '<S429>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTrunkSwtSig_flg_ovrdflg;/* Referenced by: '<S430>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTrunkSwtSig_flg_ovrdval;/* Referenced by: '<S430>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTurnLampStaLeft_flg_ovrdflg;/* Referenced by: '<S431>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTurnLampStaLeft_flg_ovrdval;/* Referenced by: '<S431>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTurnLampStaRight_flg_ovrdflg;/* Referenced by: '<S432>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTurnLampStaRight_flg_ovrdval;/* Referenced by: '<S432>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMTurnLiStsHi_enum;/* Referenced by: '<S433>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMTurnLiStsLo_enum;/* Referenced by: '<S433>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMTurnLiSts_enum_ovrdflg;/* Referenced by: '<S433>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMTurnLiSts_enum_ovrdval;/* Referenced by: '<S433>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMVehSeek_flg_ovrdflg;/* Referenced by: '<S434>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMVehSeek_flg_ovrdval;/* Referenced by: '<S434>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWarnKeyOutRmndr_flg_ovrdflg;/* Referenced by: '<S435>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWarnKeyOutRmndr_flg_ovrdval;/* Referenced by: '<S435>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWarnNoKeyFound_flg_ovrdflg;/* Referenced by: '<S436>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWarnNoKeyFound_flg_ovrdval;/* Referenced by: '<S436>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWashLiquidLvlWarn_flg_ovrdflg;/* Referenced by: '<S437>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWashLiquidLvlWarn_flg_ovrdval;/* Referenced by: '<S437>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWinLockSig_flg_ovrdflg;/* Referenced by: '<S438>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWinLockSig_flg_ovrdval;/* Referenced by: '<S438>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWinLockSts_flg_ovrdflg;/* Referenced by: '<S439>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWinLockSts_flg_ovrdval;/* Referenced by: '<S439>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMWiperCtrlFrontHi_enum;/* Referenced by: '<S440>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMWiperCtrlFrontLo_enum;/* Referenced by: '<S440>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWiperCtrlFront_enum_ovrdflg;/* Referenced by: '<S440>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMWiperCtrlFront_enum_ovrdval;/* Referenced by: '<S440>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMWiperSwSigHi_enum;/* Referenced by: '<S441>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMWiperSwSigLo_enum;/* Referenced by: '<S441>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWiperSwSig_enum_ovrdflg;/* Referenced by: '<S441>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMWiperSwSig_enum_ovrdval;/* Referenced by: '<S441>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMWiprIntlGrSwtSigHi_enum;/* Referenced by: '<S442>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMWiprIntlGrSwtSigLo_enum;/* Referenced by: '<S442>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWiprIntlGrSwtSig_enum_ovrdflg;/* Referenced by: '<S442>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMWiprIntlGrSwtSig_enum_ovrdval;/* Referenced by: '<S442>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMWiprIntlTimeSetFbHi_enum;/* Referenced by: '<S443>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMWiprIntlTimeSetFbLo_enum;/* Referenced by: '<S443>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_BCMWiprIntlTimeSetFb_enum_ovrdflg;/* Referenced by: '<S443>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BCMWiprIntlTimeSetFb_enum_ovrdval;/* Referenced by: '<S443>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_BMSShutdownHi_enum;/* Referenced by: '<S305>/sat6' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile uint8 KOPM_BMSShutdownLo_enum;/* Referenced by: '<S305>/sat7' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile boolean KOPM_BMSShutdown_enum_ovrdflg;/* Referenced by: '<S305>/sat3' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile EnumBMSSdnCmd KOPM_BMSShutdown_enum_ovrdval;/* Referenced by: '<S305>/sat4' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile uint8 KOPM_BMSWakeupModeHi_enum;/* Referenced by: '<S299>/sat6' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile uint8 KOPM_BMSWakeupModeLo_enum;/* Referenced by: '<S299>/sat7' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_BMSWakeupMode_enum_ovrdflg;/* Referenced by: '<S299>/sat3' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile EnumBMSWakeUpMd KOPM_BMSWakeupMode_enum_ovrdval;/* Referenced by: '<S299>/sat4' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_Bat2DrvTrainEnb_flg_ovrdflg;/* Referenced by: '<S300>/sat3' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_Bat2DrvTrainEnb_flg_ovrdval;/* Referenced by: '<S300>/sat4' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_BraSwi_flg_ovrdflg;/* Referenced by: '<S202>/sat3' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile boolean KOPM_BraSwi_flg_ovrdval;/* Referenced by: '<S202>/sat4' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile uint8 KOPM_BrkPedSnsrPosVRsrvdHi_enum;/* Referenced by: '<S265>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_BrkPedSnsrPosVRsrvdLo_enum;/* Referenced by: '<S265>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_BrkPedSnsrPosVRsrvd_enum_ovrdflg;/* Referenced by: '<S265>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_BrkPedSnsrPosVRsrvd_enum_ovrdval;/* Referenced by: '<S265>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_BrkPedalPosHi_pct;/* Referenced by: '<S266>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_BrkPedalPosLo_pct;/* Referenced by: '<S266>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_BrkPedalPos_pct_ovrdflg;/* Referenced by: '<S266>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_BrkPedalPos_pct_ovrdval;/* Referenced by: '<S266>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_BrkPwrRecupActWhlTqHi_Nm;/* Referenced by: '<S172>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_BrkPwrRecupActWhlTqLo_Nm;/* Referenced by: '<S172>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_BrkPwrRecupActWhlTq_Nm_ovrdflg;/* Referenced by: '<S172>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_BrkPwrRecupActWhlTq_Nm_ovrdval;/* Referenced by: '<S172>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile uint8 KOPM_BrkPwrRecupActlWhlTqStsHi_enum;/* Referenced by: '<S173>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile uint8 KOPM_BrkPwrRecupActlWhlTqStsLo_enum;/* Referenced by: '<S173>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_BrkPwrRecupActlWhlTqSts_enum_ovrdflg;/* Referenced by: '<S173>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile uint8 KOPM_BrkPwrRecupActlWhlTqSts_enum_ovrdval;/* Referenced by: '<S173>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_BrkPwrRecupMaxAvlbWhlTqHi_Nm;/* Referenced by: '<S174>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_BrkPwrRecupMaxAvlbWhlTqLo_Nm;/* Referenced by: '<S174>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_BrkPwrRecupMaxAvlbWhlTq_Nm_ovrdflg;/* Referenced by: '<S174>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_BrkPwrRecupMaxAvlbWhlTq_Nm_ovrdval;/* Referenced by: '<S174>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile uint8 KOPM_CCKeyStgntnHi_enum;/* Referenced by: '<S225>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_CCKeyStgntnLo_enum;/* Referenced by: '<S225>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_CCKeyStgntn_enum_ovrdflg;/* Referenced by: '<S225>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_CCKeyStgntn_enum_ovrdval;/* Referenced by: '<S225>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_COMPCompInPwrLimHi_W;/* Referenced by: '<S102>/sat6' */

/* AC_COMP_BOD */
extern CALDATA const volatile float32 KOPM_COMPCompInPwrLimLo_W;/* Referenced by: '<S102>/sat7' */

/* AC_COMP_BOD */
extern CALDATA const volatile boolean KOPM_COMPCompInPwrLim_W_ovrdflg;/* Referenced by: '<S102>/sat3' */

/* AC_COMP_BOD */
extern CALDATA const volatile float32 KOPM_COMPCompInPwrLim_W_ovrdval;/* Referenced by: '<S102>/sat4' */

/* AC_COMP_BOD */
extern CALDATA const volatile uint8 KOPM_COMPEcompEnblHi_enum;/* Referenced by: '<S103>/sat6' */

/* AC_COMP_BOD */
extern CALDATA const volatile uint8 KOPM_COMPEcompEnblLo_enum;/* Referenced by: '<S103>/sat7' */

/* AC_COMP_BOD */
extern CALDATA const volatile boolean KOPM_COMPEcompEnbl_enum_ovrdflg;/* Referenced by: '<S103>/sat3' */

/* AC_COMP_BOD */
extern CALDATA const volatile uint8 KOPM_COMPEcompEnbl_enum_ovrdval;/* Referenced by: '<S103>/sat4' */

/* AC_COMP_BOD */
extern CALDATA const volatile uint8 KOPM_COMPEcompErrCleanHi_enum;/* Referenced by: '<S104>/sat6' */

/* AC_COMP_BOD */
extern CALDATA const volatile uint8 KOPM_COMPEcompErrCleanLo_enum;/* Referenced by: '<S104>/sat7' */

/* AC_COMP_BOD */
extern CALDATA const volatile boolean KOPM_COMPEcompErrClean_enum_ovrdflg;/* Referenced by: '<S104>/sat3' */

/* AC_COMP_BOD */
extern CALDATA const volatile uint8 KOPM_COMPEcompErrClean_enum_ovrdval;/* Referenced by: '<S104>/sat4' */

/* AC_COMP_BOD */
extern CALDATA const volatile uint8 KOPM_COMPEcompHVStHi_enum;/* Referenced by: '<S105>/sat6' */

/* AC_COMP_BOD */
extern CALDATA const volatile uint8 KOPM_COMPEcompHVStLo_enum;/* Referenced by: '<S105>/sat7' */

/* AC_COMP_BOD */
extern CALDATA const volatile boolean KOPM_COMPEcompHVSt_enum_ovrdflg;/* Referenced by: '<S105>/sat3' */

/* AC_COMP_BOD */
extern CALDATA const volatile uint8 KOPM_COMPEcompHVSt_enum_ovrdval;/* Referenced by: '<S105>/sat4' */

/* AC_COMP_BOD */
extern CALDATA const volatile float32 KOPM_COMPEcompSpdCtrlHi_rpm;/* Referenced by: '<S106>/sat6' */

/* AC_COMP_BOD */
extern CALDATA const volatile float32 KOPM_COMPEcompSpdCtrlLo_rpm;/* Referenced by: '<S106>/sat7' */

/* AC_COMP_BOD */
extern CALDATA const volatile boolean KOPM_COMPEcompSpdCtrl_rpm_ovrdflg;/* Referenced by: '<S106>/sat3' */

/* AC_COMP_BOD */
extern CALDATA const volatile float32 KOPM_COMPEcompSpdCtrl_rpm_ovrdval;/* Referenced by: '<S106>/sat4' */

/* AC_COMP_BOD */
extern CALDATA const volatile uint8 KOPM_ChrgAllowCmdHi_enum;/* Referenced by: '<S306>/sat6' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile uint8 KOPM_ChrgAllowCmdLo_enum;/* Referenced by: '<S306>/sat7' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile boolean KOPM_ChrgAllowCmd_enum_ovrdflg;/* Referenced by: '<S306>/sat3' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile EnumChrgAllwCmd KOPM_ChrgAllowCmd_enum_ovrdval;/* Referenced by: '<S306>/sat4' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile uint8 KOPM_ChrgEnaACHi_enum;/* Referenced by: '<S301>/sat6' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile uint8 KOPM_ChrgEnaACLo_enum;/* Referenced by: '<S301>/sat7' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_ChrgEnaAC_enum_ovrdflg;/* Referenced by: '<S301>/sat3' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile EnumChrgEnaAC KOPM_ChrgEnaAC_enum_ovrdval;/* Referenced by: '<S301>/sat4' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_ChrgEnaDC_flg_ovrdflg;/* Referenced by: '<S307>/sat3' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile boolean KOPM_ChrgEnaDC_flg_ovrdval;/* Referenced by: '<S307>/sat4' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile float32 KOPM_DCCBoostHvVoltHi_V;/* Referenced by: '<S317>/sat6' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_DCCBoostHvVoltLo_V;/* Referenced by: '<S317>/sat7' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_DCCBoostHvVolt_V_ovrdflg;/* Referenced by: '<S317>/sat3' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_DCCBoostHvVolt_V_ovrdval;/* Referenced by: '<S317>/sat4' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_DCCBuckLVVoltHi_V;/* Referenced by: '<S318>/sat6' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_DCCBuckLVVoltLo_V;/* Referenced by: '<S318>/sat7' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_DCCBuckLVVolt_V_ovrdflg;/* Referenced by: '<S318>/sat3' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_DCCBuckLVVolt_V_ovrdval;/* Referenced by: '<S318>/sat4' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile uint8 KOPM_DCCOprtCmdHi_enum;/* Referenced by: '<S313>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_DCCOprtCmdLo_enum;/* Referenced by: '<S313>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_DCCOprtCmd_enum_ovrdflg;/* Referenced by: '<S313>/sat3' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile EnumDCCOprtCmd KOPM_DCCOprtCmd_enum_ovrdval;/* Referenced by: '<S313>/sat4' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_DrvModeKeyStgntnHi_enum;/* Referenced by: '<S226>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_DrvModeKeyStgntnLo_enum;/* Referenced by: '<S226>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_DrvModeKeyStgntn_enum_ovrdflg;/* Referenced by: '<S226>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_DrvModeKeyStgntn_enum_ovrdval;/* Referenced by: '<S226>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_DrvMotorStaHi_enum;/* Referenced by: '<S227>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_DrvMotorStaLo_enum;/* Referenced by: '<S227>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_DrvMotorSta_enum_ovrdflg;/* Referenced by: '<S227>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_DrvMotorSta_enum_ovrdval;/* Referenced by: '<S227>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_DrvPedHi_pct;/* Referenced by: '<S203>/sat6' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile float32 KOPM_DrvPedLo_pct;/* Referenced by: '<S203>/sat7' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile boolean KOPM_DrvPed_pct_ovrdflg;/* Referenced by: '<S203>/sat3' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile float32 KOPM_DrvPed_pct_ovrdval;/* Referenced by: '<S203>/sat4' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile float32 KOPM_DrvRangeDistEstHi_km;/* Referenced by: '<S229>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile float32 KOPM_DrvRangeDistEstLo_km;/* Referenced by: '<S229>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_DrvRangeDistEstVld_flg_ovrdflg;/* Referenced by: '<S228>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_DrvRangeDistEstVld_flg_ovrdval;/* Referenced by: '<S228>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_DrvRangeDistEst_km_ovrdflg;/* Referenced by: '<S229>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_DrvRangeDistEst_km_ovrdval;/* Referenced by: '<S229>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_DrvReqMotorTorqHi_Nm;/* Referenced by: '<S176>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_DrvReqMotorTorqLo_Nm;/* Referenced by: '<S176>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_DrvReqMotorTorqVld_flg_ovrdflg;/* Referenced by: '<S175>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_DrvReqMotorTorqVld_flg_ovrdval;/* Referenced by: '<S175>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_DrvReqMotorTorq_Nm_ovrdflg;/* Referenced by: '<S176>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_DrvReqMotorTorq_Nm_ovrdval;/* Referenced by: '<S176>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_DrvReqTorqOverrideFCM_flg_ovrdflg;/* Referenced by: '<S267>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_DrvReqTorqOverrideFCM_flg_ovrdval;/* Referenced by: '<S267>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_DrvReqTorqOvrdESC_flg_ovrdflg;/* Referenced by: '<S268>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_DrvReqTorqOvrdESC_flg_ovrdval;/* Referenced by: '<S268>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_DrvReqWhlTqHi_Nm;/* Referenced by: '<S178>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_DrvReqWhlTqLo_Nm;/* Referenced by: '<S178>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_DrvReqWhlTqVld_flg_ovrdflg;/* Referenced by: '<S177>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_DrvReqWhlTqVld_flg_ovrdval;/* Referenced by: '<S177>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_DrvReqWhlTq_Nm_ovrdflg;/* Referenced by: '<S178>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_DrvReqWhlTq_Nm_ovrdval;/* Referenced by: '<S178>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_DrvSwi_flg_ovrdflg;/* Referenced by: '<S204>/sat3' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile boolean KOPM_DrvSwi_flg_ovrdval;/* Referenced by: '<S204>/sat4' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile float32 KOPM_DrvWhlTqAllwdMaxHi_Nm;/* Referenced by: '<S179>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_DrvWhlTqAllwdMaxLo_Nm;/* Referenced by: '<S179>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_DrvWhlTqAllwdMax_Nm_ovrdflg;/* Referenced by: '<S179>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_DrvWhlTqAllwdMax_Nm_ovrdval;/* Referenced by: '<S179>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile uint64 KOPM_ESCLUnOrLockCrtlHi_nu;/* Referenced by: '<S113>/sat6' */

/* BCM_ESCLCommand_BOD */
extern CALDATA const volatile uint64 KOPM_ESCLUnOrLockCrtlLo_nu;/* Referenced by: '<S113>/sat7' */

/* BCM_ESCLCommand_BOD */
extern CALDATA const volatile boolean KOPM_ESCLUnOrLockCrtl_nu_ovrdflg;/* Referenced by: '<S113>/sat3' */

/* BCM_ESCLCommand_BOD */
extern CALDATA const volatile uint64 KOPM_ESCLUnOrLockCrtl_nu_ovrdval;/* Referenced by: '<S113>/sat4' */

/* BCM_ESCLCommand_BOD */
extern CALDATA const volatile boolean KOPM_EmgcySdn_flg_ovrdflg;/* Referenced by: '<S209>/sat3' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile boolean KOPM_EmgcySdn_flg_ovrdval;/* Referenced by: '<S209>/sat4' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile boolean KOPM_EnaDisChg_flg_ovrdflg;/* Referenced by: '<S210>/sat3' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile boolean KOPM_EnaDisChg_flg_ovrdval;/* Referenced by: '<S210>/sat4' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile boolean KOPM_EnaInvRun_flg_ovrdflg;/* Referenced by: '<S211>/sat3' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile boolean KOPM_EnaInvRun_flg_ovrdval;/* Referenced by: '<S211>/sat4' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile uint8 KOPM_ErrAmountHi_cnt;/* Referenced by: '<S314>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_ErrAmountLo_cnt;/* Referenced by: '<S314>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_ErrAmount_cnt_ovrdflg;/* Referenced by: '<S314>/sat3' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_ErrAmount_cnt_ovrdval;/* Referenced by: '<S314>/sat4' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint16 KOPM_ErrBitHi_nu;/* Referenced by: '<S315>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint16 KOPM_ErrBitLo_nu;/* Referenced by: '<S315>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_ErrBit_nu_ovrdflg;/* Referenced by: '<S315>/sat3' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint16 KOPM_ErrBit_nu_ovrdval;/* Referenced by: '<S315>/sat4' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_GearShiftInhibited_flg_ovrdflg;/* Referenced by: '<S269>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_GearShiftInhibited_flg_ovrdval;/* Referenced by: '<S269>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_HDCStatHi_enum;/* Referenced by: '<S337>/sat6' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_HDCStatLo_enum;/* Referenced by: '<S337>/sat7' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_HDCStat_enum_ovrdflg;/* Referenced by: '<S337>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_HDCStat_enum_ovrdval;/* Referenced by: '<S337>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_HVCHEnbldHi_enum;/* Referenced by: '<S114>/sat6' */

/* HVCH_Command_BOD */
extern CALDATA const volatile uint8 KOPM_HVCHEnbldLo_enum;/* Referenced by: '<S114>/sat7' */

/* HVCH_Command_BOD */
extern CALDATA const volatile boolean KOPM_HVCHEnbld_enum_ovrdflg;/* Referenced by: '<S114>/sat3' */

/* HVCH_Command_BOD */
extern CALDATA const volatile uint8 KOPM_HVCHEnbld_enum_ovrdval;/* Referenced by: '<S114>/sat4' */

/* HVCH_Command_BOD */
extern CALDATA const volatile float32 KOPM_HVCHReqPwrHi_kW;/* Referenced by: '<S115>/sat6' */

/* HVCH_Command_BOD */
extern CALDATA const volatile float32 KOPM_HVCHReqPwrLo_kW;/* Referenced by: '<S115>/sat7' */

/* HVCH_Command_BOD */
extern CALDATA const volatile boolean KOPM_HVCHReqPwr_kW_ovrdflg;/* Referenced by: '<S115>/sat3' */

/* HVCH_Command_BOD */
extern CALDATA const volatile float32 KOPM_HVCHReqPwr_kW_ovrdval;/* Referenced by: '<S115>/sat4' */

/* HVCH_Command_BOD */
extern CALDATA const volatile float32 KOPM_HVCHReqTempHi_C;/* Referenced by: '<S116>/sat6' */

/* HVCH_Command_BOD */
extern CALDATA const volatile float32 KOPM_HVCHReqTempLo_C;/* Referenced by: '<S116>/sat7' */

/* HVCH_Command_BOD */
extern CALDATA const volatile boolean KOPM_HVCHReqTemp_C_ovrdflg;/* Referenced by: '<S116>/sat3' */

/* HVCH_Command_BOD */
extern CALDATA const volatile float32 KOPM_HVCHReqTemp_C_ovrdval;/* Referenced by: '<S116>/sat4' */

/* HVCH_Command_BOD */
extern CALDATA const volatile boolean KOPM_IBSWakeup_flg_ovrdflg;/* Referenced by: '<S147>/sat3' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile boolean KOPM_IBSWakeup_flg_ovrdval;/* Referenced by: '<S147>/sat4' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile uint8 KOPM_InfoDispHi_enum;/* Referenced by: '<S230>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_InfoDispLo_enum;/* Referenced by: '<S230>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_InfoDisp_enum_ovrdflg;/* Referenced by: '<S230>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_InfoDisp_enum_ovrdval;/* Referenced by: '<S230>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_LimpHomeSta_flg_ovrdflg;/* Referenced by: '<S338>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_LimpHomeSta_flg_ovrdval;/* Referenced by: '<S338>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_MCUHiTempWrning_flg_ovrdflg;/* Referenced by: '<S231>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_MCUHiTempWrning_flg_ovrdval;/* Referenced by: '<S231>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_MaxChrgCurntDCHi_A;/* Referenced by: '<S308>/sat6' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile float32 KOPM_MaxChrgCurntDCLo_A;/* Referenced by: '<S308>/sat7' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile boolean KOPM_MaxChrgCurntDC_A_ovrdflg;/* Referenced by: '<S308>/sat3' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile float32 KOPM_MaxChrgCurntDC_A_ovrdval;/* Referenced by: '<S308>/sat4' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile float32 KOPM_MaxChrgVoltDCHi_V;/* Referenced by: '<S309>/sat6' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile float32 KOPM_MaxChrgVoltDCLo_V;/* Referenced by: '<S309>/sat7' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile boolean KOPM_MaxChrgVoltDC_V_ovrdflg;/* Referenced by: '<S309>/sat3' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile float32 KOPM_MaxChrgVoltDC_V_ovrdval;/* Referenced by: '<S309>/sat4' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile float32 KOPM_MaxHVDCCurntACHi_A;/* Referenced by: '<S319>/sat6' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_MaxHVDCCurntACLo_A;/* Referenced by: '<S319>/sat7' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_MaxHVDCCurntAC_A_ovrdflg;/* Referenced by: '<S319>/sat3' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_MaxHVDCCurntAC_A_ovrdval;/* Referenced by: '<S319>/sat4' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_MaxHVDCVoltACHi_V;/* Referenced by: '<S320>/sat6' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_MaxHVDCVoltACLo_V;/* Referenced by: '<S320>/sat7' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_MaxHVDCVoltAC_V_ovrdflg;/* Referenced by: '<S320>/sat3' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_MaxHVDCVoltAC_V_ovrdval;/* Referenced by: '<S320>/sat4' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_MotActPwrHi_Kw;/* Referenced by: '<S233>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile float32 KOPM_MotActPwrLo_Kw;/* Referenced by: '<S233>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_MotActPwrTypHi_enum;/* Referenced by: '<S232>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_MotActPwrTypLo_enum;/* Referenced by: '<S232>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_MotActPwrTyp_enum_ovrdflg;/* Referenced by: '<S232>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_MotActPwrTyp_enum_ovrdval;/* Referenced by: '<S232>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_MotActPwr_Kw_ovrdflg;/* Referenced by: '<S233>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_MotActPwr_Kw_ovrdval;/* Referenced by: '<S233>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_MotDirReqHi_enum;/* Referenced by: '<S212>/sat6' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile uint8 KOPM_MotDirReqLo_enum;/* Referenced by: '<S212>/sat7' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile boolean KOPM_MotDirReq_enum_ovrdflg;/* Referenced by: '<S212>/sat3' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile EnumMotorDirReq KOPM_MotDirReq_enum_ovrdval;/* Referenced by: '<S212>/sat4' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile float32 KOPM_MotDmpgLmtHi_Nm;/* Referenced by: '<S205>/sat6' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile float32 KOPM_MotDmpgLmtLo_Nm;/* Referenced by: '<S205>/sat7' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile boolean KOPM_MotDmpgLmt_Nm_ovrdflg;/* Referenced by: '<S205>/sat3' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile float32 KOPM_MotDmpgLmt_Nm_ovrdval;/* Referenced by: '<S205>/sat4' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile uint8 KOPM_MotModeReqHi_enum;/* Referenced by: '<S213>/sat6' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile uint8 KOPM_MotModeReqLo_enum;/* Referenced by: '<S213>/sat7' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile boolean KOPM_MotModeReq_enum_ovrdflg;/* Referenced by: '<S213>/sat3' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile EnumMotorModeReq KOPM_MotModeReq_enum_ovrdval;/* Referenced by: '<S213>/sat4' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile float32 KOPM_MotSpdReqHi_rpm;/* Referenced by: '<S214>/sat6' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile float32 KOPM_MotSpdReqLo_rpm;/* Referenced by: '<S214>/sat7' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile boolean KOPM_MotSpdReq_rpm_ovrdflg;/* Referenced by: '<S214>/sat3' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile float32 KOPM_MotSpdReq_rpm_ovrdval;/* Referenced by: '<S214>/sat4' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile float32 KOPM_MotTorqReqHi_Nm;/* Referenced by: '<S215>/sat6' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile float32 KOPM_MotTorqReqLo_Nm;/* Referenced by: '<S215>/sat7' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile boolean KOPM_MotTorqReq_Nm_ovrdflg;/* Referenced by: '<S215>/sat3' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile float32 KOPM_MotTorqReq_Nm_ovrdval;/* Referenced by: '<S215>/sat4' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile boolean KOPM_MotorHiTempWrning_flg_ovrdflg;/* Referenced by: '<S234>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_MotorHiTempWrning_flg_ovrdval;/* Referenced by: '<S234>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_MotorOutputCooltTempHi_C;/* Referenced by: '<S302>/sat6' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_MotorOutputCooltTempLo_C;/* Referenced by: '<S302>/sat7' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_MotorOutputCooltTemp_C_ovrdflg;/* Referenced by: '<S302>/sat3' */

/* VCU_4_OprtCmd_EPT */
extern CALDATA const volatile float32 KOPM_MotorOutputCooltTemp_C_ovrdval;/* Referenced by: '<S302>/sat4' */

/* VCU_3_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_OBCIntDchrgEna_flg_ovrdflg;/* Referenced by: '<S321>/sat3' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile boolean KOPM_OBCIntDchrgEna_flg_ovrdval;/* Referenced by: '<S321>/sat4' */

/* VCU_C_OprtCmd_EPT */
extern CALDATA const volatile uint8 KOPM_OBCOprtCmdHi_enum;/* Referenced by: '<S310>/sat6' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile uint8 KOPM_OBCOprtCmdLo_enum;/* Referenced by: '<S310>/sat7' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile uint8 KOPM_OBCOprtCmdToICUHi_enum;/* Referenced by: '<S235>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_OBCOprtCmdToICULo_enum;/* Referenced by: '<S235>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_OBCOprtCmdToICU_enum_ovrdflg;/* Referenced by: '<S235>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile EnumOBCOprtCmd KOPM_OBCOprtCmdToICU_enum_ovrdval;/* Referenced by: '<S235>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_OBCOprtCmd_enum_ovrdflg;/* Referenced by: '<S310>/sat3' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile EnumOBCOprtCmd KOPM_OBCOprtCmd_enum_ovrdval;/* Referenced by: '<S310>/sat4' */

/* VCU_4_ChrgCmd_EPT */
extern CALDATA const volatile boolean KOPM_OTAModeSts_flg_ovrdflg;/* Referenced by: '<S270>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_OTAModeSts_flg_ovrdval;/* Referenced by: '<S270>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_PCUFailSta_flg_ovrdflg;/* Referenced by: '<S339>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_PCUFailSta_flg_ovrdval;/* Referenced by: '<S339>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_PGrSwcStHi_enum;/* Referenced by: '<S271>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_PGrSwcStLo_enum;/* Referenced by: '<S271>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_PGrSwcSt_enum_ovrdflg;/* Referenced by: '<S271>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_PGrSwcSt_enum_ovrdval;/* Referenced by: '<S271>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_PTActlOprtModeHi_enum;/* Referenced by: '<S340>/sat6' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_PTActlOprtModeLo_enum;/* Referenced by: '<S340>/sat7' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_PTActlOprtMode_enum_ovrdflg;/* Referenced by: '<S340>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile EnumPTActMd KOPM_PTActlOprtMode_enum_ovrdval;/* Referenced by: '<S340>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_PrstlsStaFbHi_enum;/* Referenced by: '<S341>/sat6' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_PrstlsStaFbLo_enum;/* Referenced by: '<S341>/sat7' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_PrstlsStaFb_enum_ovrdflg;/* Referenced by: '<S341>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile EnumCrpModeAct KOPM_PrstlsStaFb_enum_ovrdval;/* Referenced by: '<S341>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_PtReadyEnaHi_enum;/* Referenced by: '<S148>/sat6' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile uint8 KOPM_PtReadyEnaLo_enum;/* Referenced by: '<S148>/sat7' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile boolean KOPM_PtReadyEna_enum_ovrdflg;/* Referenced by: '<S148>/sat3' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile uint8 KOPM_PtReadyEna_enum_ovrdval;/* Referenced by: '<S148>/sat4' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile float32 KOPM_PwrRecupActWhlTqHi_Nm;/* Referenced by: '<S180>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_PwrRecupActWhlTqLo_Nm;/* Referenced by: '<S180>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_PwrRecupActWhlTq_Nm_ovrdflg;/* Referenced by: '<S180>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_PwrRecupActWhlTq_Nm_ovrdval;/* Referenced by: '<S180>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile uint8 KOPM_PwrRecupActlWhlTqStsHi_enum;/* Referenced by: '<S181>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile uint8 KOPM_PwrRecupActlWhlTqStsLo_enum;/* Referenced by: '<S181>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_PwrRecupActlWhlTqSts_enum_ovrdflg;/* Referenced by: '<S181>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile uint8 KOPM_PwrRecupActlWhlTqSts_enum_ovrdval;/* Referenced by: '<S181>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile uint8 KOPM_PwrRecupIntnstyHi_enum;/* Referenced by: '<S342>/sat6' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_PwrRecupIntnstyLo_enum;/* Referenced by: '<S342>/sat7' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_PwrRecupIntnsty_enum_ovrdflg;/* Referenced by: '<S342>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile EnumRegenModeAct KOPM_PwrRecupIntnsty_enum_ovrdval;/* Referenced by: '<S342>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_PwrRecupMaxAvlbMotorTorqStaHi_enum;/* Referenced by: '<S272>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_PwrRecupMaxAvlbMotorTorqStaLo_enum;/* Referenced by: '<S272>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean
  KOPM_PwrRecupMaxAvlbMotorTorqSta_enum_ovrdflg;/* Referenced by: '<S272>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8
  KOPM_PwrRecupMaxAvlbMotorTorqSta_enum_ovrdval;/* Referenced by: '<S272>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_PwrRecupMaxAvlbWhlTqStsHi_enum;/* Referenced by: '<S182>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile uint8 KOPM_PwrRecupMaxAvlbWhlTqStsLo_enum;/* Referenced by: '<S182>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_PwrRecupMaxAvlbWhlTqSts_enum_ovrdflg;/* Referenced by: '<S182>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile uint8 KOPM_PwrRecupMaxAvlbWhlTqSts_enum_ovrdval;/* Referenced by: '<S182>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_RsrvdPwrHi_kW;/* Referenced by: '<S236>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile float32 KOPM_RsrvdPwrLo_kW;/* Referenced by: '<S236>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_RsrvdPwr_kW_ovrdflg;/* Referenced by: '<S236>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_RsrvdPwr_kW_ovrdval;/* Referenced by: '<S236>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_SIBSBMSBatSOCAllow_flg_ovrdflg;/* Referenced by: '<S237>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_SIBSBMSBatSOCAllow_flg_ovrdval;/* Referenced by: '<S237>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_SIBSChgNumAllow_flg_ovrdflg;/* Referenced by: '<S238>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_SIBSChgNumAllow_flg_ovrdval;/* Referenced by: '<S238>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_SIBSFbRTCWupFlg_flg_ovrdflg;/* Referenced by: '<S239>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_SIBSFbRTCWupFlg_flg_ovrdval;/* Referenced by: '<S239>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_SIBSKL30VoltHi_V;/* Referenced by: '<S240>/sat6' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_SIBSKL30VoltLo_V;/* Referenced by: '<S240>/sat7' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_SIBSKL30Volt_V_ovrdflg;/* Referenced by: '<S240>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_SIBSKL30Volt_V_ovrdval;/* Referenced by: '<S240>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_SIBSRTCChrgStHi_enum;/* Referenced by: '<S241>/sat6' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_SIBSRTCChrgStLo_enum;/* Referenced by: '<S241>/sat7' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_SIBSRTCChrgSt_enum_ovrdflg;/* Referenced by: '<S241>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile EnumIBSChrgSt KOPM_SIBSRTCChrgSt_enum_ovrdval;/* Referenced by: '<S241>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_SIBSRTCWUChgFailNumHi_cnt;/* Referenced by: '<S242>/sat6' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_SIBSRTCWUChgFailNumLo_cnt;/* Referenced by: '<S242>/sat7' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_SIBSRTCWUChgFailNum_cnt_ovrdflg;/* Referenced by: '<S242>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_SIBSRTCWUChgFailNum_cnt_ovrdval;/* Referenced by: '<S242>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_SIBSRTCWUChgNumHi_cnt;/* Referenced by: '<S243>/sat6' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_SIBSRTCWUChgNumLo_cnt;/* Referenced by: '<S243>/sat7' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_SIBSRTCWUChgNum_cnt_ovrdflg;/* Referenced by: '<S243>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_SIBSRTCWUChgNum_cnt_ovrdval;/* Referenced by: '<S243>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_SIBSWupVoltAllow_flg_ovrdflg;/* Referenced by: '<S244>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_SIBSWupVoltAllow_flg_ovrdval;/* Referenced by: '<S244>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_ShftKeyStgntnHi_enum;/* Referenced by: '<S245>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_ShftKeyStgntnLo_enum;/* Referenced by: '<S245>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_ShftKeyStgntn_enum_ovrdflg;/* Referenced by: '<S245>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_ShftKeyStgntn_enum_ovrdval;/* Referenced by: '<S245>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_StrgRecupReqBrkLampOn_flg_ovrdflg;/* Referenced by: '<S273>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_StrgRecupReqBrkLampOn_flg_ovrdval;/* Referenced by: '<S273>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_SysFailStaHi_enum;/* Referenced by: '<S316>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_SysFailStaLo_enum;/* Referenced by: '<S316>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_SysFailSta_enum_ovrdflg;/* Referenced by: '<S316>/sat3' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile uint8 KOPM_SysFailSta_enum_ovrdval;/* Referenced by: '<S316>/sat4' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_TMPSAbnmPrsrWarn_flg_ovrdflg;/* Referenced by: '<S444>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_TMPSAbnmPrsrWarn_flg_ovrdval;/* Referenced by: '<S444>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile float32 KOPM_TMSACPExhtTmpHi_C;/* Referenced by: '<S107>/sat6' */

/* AC_COMP_BOD */
extern CALDATA const volatile float32 KOPM_TMSACPExhtTmpLo_C;/* Referenced by: '<S107>/sat7' */

/* AC_COMP_BOD */
extern CALDATA const volatile boolean KOPM_TMSACPExhtTmp_C_ovrdflg;/* Referenced by: '<S107>/sat3' */

/* AC_COMP_BOD */
extern CALDATA const volatile float32 KOPM_TMSACPExhtTmp_C_ovrdval;/* Referenced by: '<S107>/sat4' */

/* AC_COMP_BOD */
extern CALDATA const volatile float32 KOPM_TMSACPInletPresHi_kPa;/* Referenced by: '<S108>/sat6' */

/* AC_COMP_BOD */
extern CALDATA const volatile float32 KOPM_TMSACPInletPresLo_kPa;/* Referenced by: '<S108>/sat7' */

/* AC_COMP_BOD */
extern CALDATA const volatile boolean KOPM_TMSACPInletPres_kPa_ovrdflg;/* Referenced by: '<S108>/sat3' */

/* AC_COMP_BOD */
extern CALDATA const volatile float32 KOPM_TMSACPInletPres_kPa_ovrdval;/* Referenced by: '<S108>/sat4' */

/* AC_COMP_BOD */
extern CALDATA const volatile uint16 KOPM_TMSAEXVCurrentPstnHi_cnt;/* Referenced by: '<S132>/sat6' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile uint16 KOPM_TMSAEXVCurrentPstnLo_cnt;/* Referenced by: '<S132>/sat7' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile boolean KOPM_TMSAEXVCurrentPstn_cnt_ovrdflg;/* Referenced by: '<S132>/sat3' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile uint16 KOPM_TMSAEXVCurrentPstn_cnt_ovrdval;/* Referenced by: '<S132>/sat4' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile boolean KOPM_TMSAEXVEnblReq_flg_ovrdflg;/* Referenced by: '<S136>/sat3' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile boolean KOPM_TMSAEXVEnblReq_flg_ovrdval;/* Referenced by: '<S136>/sat4' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint16 KOPM_TMSAEXVPstnReqHi_cnt;/* Referenced by: '<S133>/sat6' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile uint16 KOPM_TMSAEXVPstnReqLo_cnt;/* Referenced by: '<S133>/sat7' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile boolean KOPM_TMSAEXVPstnReq_cnt_ovrdflg;/* Referenced by: '<S133>/sat3' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile uint16 KOPM_TMSAEXVPstnReq_cnt_ovrdval;/* Referenced by: '<S133>/sat4' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile float32 KOPM_TMSAcPMPRealRPMHi_rpm;/* Referenced by: '<S119>/sat6' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSAcPMPRealRPMLo_rpm;/* Referenced by: '<S119>/sat7' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile boolean KOPM_TMSAcPMPRealRPM_rpm_ovrdflg;/* Referenced by: '<S119>/sat3' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSAcPMPRealRPM_rpm_ovrdval;/* Referenced by: '<S119>/sat4' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSAcPMPSpdSetHi_rpm;/* Referenced by: '<S120>/sat6' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSAcPMPSpdSetLo_rpm;/* Referenced by: '<S120>/sat7' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile boolean KOPM_TMSAcPMPSpdSet_rpm_ovrdflg;/* Referenced by: '<S120>/sat3' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSAcPMPSpdSet_rpm_ovrdval;/* Referenced by: '<S120>/sat4' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile uint16 KOPM_TMSBEXVCurrentPstnHi_cnt;/* Referenced by: '<S134>/sat6' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile uint16 KOPM_TMSBEXVCurrentPstnLo_cnt;/* Referenced by: '<S134>/sat7' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile boolean KOPM_TMSBEXVCurrentPstn_cnt_ovrdflg;/* Referenced by: '<S134>/sat3' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile uint16 KOPM_TMSBEXVCurrentPstn_cnt_ovrdval;/* Referenced by: '<S134>/sat4' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile boolean KOPM_TMSBEXVEnblCmd_flg_ovrdflg;/* Referenced by: '<S137>/sat3' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile boolean KOPM_TMSBEXVEnblCmd_flg_ovrdval;/* Referenced by: '<S137>/sat4' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint16 KOPM_TMSBEXVPstnCmdHi_cnt;/* Referenced by: '<S135>/sat6' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile uint16 KOPM_TMSBEXVPstnCmdLo_cnt;/* Referenced by: '<S135>/sat7' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile boolean KOPM_TMSBEXVPstnCmd_cnt_ovrdflg;/* Referenced by: '<S135>/sat3' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile uint16 KOPM_TMSBEXVPstnCmd_cnt_ovrdval;/* Referenced by: '<S135>/sat4' */

/* TMS_LINTestData2_BOD */
extern CALDATA const volatile float32 KOPM_TMSBatPMPRealRPMHi_rpm;/* Referenced by: '<S121>/sat6' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSBatPMPRealRPMLo_rpm;/* Referenced by: '<S121>/sat7' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile boolean KOPM_TMSBatPMPRealRPM_rpm_ovrdflg;/* Referenced by: '<S121>/sat3' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSBatPMPRealRPM_rpm_ovrdval;/* Referenced by: '<S121>/sat4' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSBatPMPSpdSetHi_rpm;/* Referenced by: '<S122>/sat6' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSBatPMPSpdSetLo_rpm;/* Referenced by: '<S122>/sat7' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile boolean KOPM_TMSBatPMPSpdSet_rpm_ovrdflg;/* Referenced by: '<S122>/sat3' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSBatPMPSpdSet_rpm_ovrdval;/* Referenced by: '<S122>/sat4' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile boolean KOPM_TMSBattTempCtrlRmnSwFb_flg_ovrdflg;/* Referenced by: '<S57>/sat3' */

/* AC_2_State_BOD */
extern CALDATA const volatile boolean KOPM_TMSBattTempCtrlRmnSwFb_flg_ovrdval;/* Referenced by: '<S57>/sat4' */

/* AC_2_State_BOD */
extern CALDATA const volatile uint8 KOPM_TMSC3WVBPosSetReqHi_enum;/* Referenced by: '<S138>/sat6' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint8 KOPM_TMSC3WVBPosSetReqLo_enum;/* Referenced by: '<S138>/sat7' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile boolean KOPM_TMSC3WVBPosSetReq_enum_ovrdflg;/* Referenced by: '<S138>/sat3' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint8 KOPM_TMSC3WVBPosSetReq_enum_ovrdval;/* Referenced by: '<S138>/sat4' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint8 KOPM_TMSC3WVModeHi_enum;/* Referenced by: '<S139>/sat6' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint8 KOPM_TMSC3WVModeLo_enum;/* Referenced by: '<S139>/sat7' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile boolean KOPM_TMSC3WVMode_enum_ovrdflg;/* Referenced by: '<S139>/sat3' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint8 KOPM_TMSC3WVMode_enum_ovrdval;/* Referenced by: '<S139>/sat4' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint16 KOPM_TMSC3WVPosRecHi_enum;/* Referenced by: '<S140>/sat6' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint16 KOPM_TMSC3WVPosRecLo_enum;/* Referenced by: '<S140>/sat7' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile boolean KOPM_TMSC3WVPosRec_enum_ovrdflg;/* Referenced by: '<S140>/sat3' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint16 KOPM_TMSC3WVPosRec_enum_ovrdval;/* Referenced by: '<S140>/sat4' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint8 KOPM_TMSC5WVBPosSetReqHi_enum;/* Referenced by: '<S141>/sat6' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint8 KOPM_TMSC5WVBPosSetReqLo_enum;/* Referenced by: '<S141>/sat7' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile boolean KOPM_TMSC5WVBPosSetReq_enum_ovrdflg;/* Referenced by: '<S141>/sat3' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint8 KOPM_TMSC5WVBPosSetReq_enum_ovrdval;/* Referenced by: '<S141>/sat4' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint8 KOPM_TMSC5WVModeHi_enum;/* Referenced by: '<S142>/sat6' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint8 KOPM_TMSC5WVModeLo_enum;/* Referenced by: '<S142>/sat7' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile boolean KOPM_TMSC5WVMode_enum_ovrdflg;/* Referenced by: '<S142>/sat3' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint8 KOPM_TMSC5WVMode_enum_ovrdval;/* Referenced by: '<S142>/sat4' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint16 KOPM_TMSC5WVPosRecHi_enum;/* Referenced by: '<S143>/sat6' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint16 KOPM_TMSC5WVPosRecLo_enum;/* Referenced by: '<S143>/sat7' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile boolean KOPM_TMSC5WVPosRec_enum_ovrdflg;/* Referenced by: '<S143>/sat3' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint16 KOPM_TMSC5WVPosRec_enum_ovrdval;/* Referenced by: '<S143>/sat4' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile float32 KOPM_TMSChillerOutTmpHi_C;/* Referenced by: '<S69>/sat6' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSChillerOutTmpLo_C;/* Referenced by: '<S69>/sat7' */

/* AC_3_State_BOD */
extern CALDATA const volatile boolean KOPM_TMSChillerOutTmp_C_ovrdflg;/* Referenced by: '<S69>/sat3' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSChillerOutTmp_C_ovrdval;/* Referenced by: '<S69>/sat4' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSEvapOutTmpHi_C;/* Referenced by: '<S70>/sat6' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSEvapOutTmpLo_C;/* Referenced by: '<S70>/sat7' */

/* AC_3_State_BOD */
extern CALDATA const volatile boolean KOPM_TMSEvapOutTmp_C_ovrdflg;/* Referenced by: '<S70>/sat3' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSEvapOutTmp_C_ovrdval;/* Referenced by: '<S70>/sat4' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSEvapTmpHi_C;/* Referenced by: '<S71>/sat6' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSEvapTmpLo_C;/* Referenced by: '<S71>/sat7' */

/* AC_3_State_BOD */
extern CALDATA const volatile boolean KOPM_TMSEvapTmp_C_ovrdflg;/* Referenced by: '<S71>/sat3' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSEvapTmp_C_ovrdval;/* Referenced by: '<S71>/sat4' */

/* AC_3_State_BOD */
extern CALDATA const volatile uint16 KOPM_TMSHPEXVCurrentPstnHi_cnt;/* Referenced by: '<S144>/sat6' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint16 KOPM_TMSHPEXVCurrentPstnLo_cnt;/* Referenced by: '<S144>/sat7' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile boolean KOPM_TMSHPEXVCurrentPstn_cnt_ovrdflg;/* Referenced by: '<S144>/sat3' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint16 KOPM_TMSHPEXVCurrentPstn_cnt_ovrdval;/* Referenced by: '<S144>/sat4' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile boolean KOPM_TMSHPEXVEnblCmd_flg_ovrdflg;/* Referenced by: '<S145>/sat3' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile boolean KOPM_TMSHPEXVEnblCmd_flg_ovrdval;/* Referenced by: '<S145>/sat4' */

/* TMS_LINTestData3_BOD */
extern CALDATA const volatile uint16 KOPM_TMSHPEXVPstnCmdHi_cnt;/* Referenced by: '<S123>/sat6' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile uint16 KOPM_TMSHPEXVPstnCmdLo_cnt;/* Referenced by: '<S123>/sat7' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile boolean KOPM_TMSHPEXVPstnCmd_cnt_ovrdflg;/* Referenced by: '<S123>/sat3' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile uint16 KOPM_TMSHPEXVPstnCmd_cnt_ovrdval;/* Referenced by: '<S123>/sat4' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSMotPMPRealRPMHi_rpm;/* Referenced by: '<S124>/sat6' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSMotPMPRealRPMLo_rpm;/* Referenced by: '<S124>/sat7' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile boolean KOPM_TMSMotPMPRealRPM_rpm_ovrdflg;/* Referenced by: '<S124>/sat3' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSMotPMPRealRPM_rpm_ovrdval;/* Referenced by: '<S124>/sat4' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSMotPMPSpdSetHi_rpm;/* Referenced by: '<S125>/sat6' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSMotPMPSpdSetLo_rpm;/* Referenced by: '<S125>/sat7' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile boolean KOPM_TMSMotPMPSpdSet_rpm_ovrdflg;/* Referenced by: '<S125>/sat3' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSMotPMPSpdSet_rpm_ovrdval;/* Referenced by: '<S125>/sat4' */

/* TMS_LINTestData1_BOD */
extern CALDATA const volatile float32 KOPM_TMSOHXOutTmpHi_C;/* Referenced by: '<S72>/sat6' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSOHXOutTmpLo_C;/* Referenced by: '<S72>/sat7' */

/* AC_3_State_BOD */
extern CALDATA const volatile boolean KOPM_TMSOHXOutTmp_C_ovrdflg;/* Referenced by: '<S72>/sat3' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSOHXOutTmp_C_ovrdval;/* Referenced by: '<S72>/sat4' */

/* AC_3_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSPCUInletCooltTempHi_C;/* Referenced by: '<S150>/sat6' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile float32 KOPM_TMSPCUInletCooltTempLo_C;/* Referenced by: '<S150>/sat7' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile boolean KOPM_TMSPCUInletCooltTempVld_flg_ovrdflg;/* Referenced by: '<S149>/sat3' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile boolean KOPM_TMSPCUInletCooltTempVld_flg_ovrdval;/* Referenced by: '<S149>/sat4' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile boolean KOPM_TMSPCUInletCooltTemp_C_ovrdflg;/* Referenced by: '<S150>/sat3' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile float32 KOPM_TMSPCUInletCooltTemp_C_ovrdval;/* Referenced by: '<S150>/sat4' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile float32 KOPM_TMSPTPresHi_kPa;/* Referenced by: '<S58>/sat6' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSPTPresLo_kPa;/* Referenced by: '<S58>/sat7' */

/* AC_2_State_BOD */
extern CALDATA const volatile boolean KOPM_TMSPTPres_kPa_ovrdflg;/* Referenced by: '<S58>/sat3' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSPTPres_kPa_ovrdval;/* Referenced by: '<S58>/sat4' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSPTTempHi_C;/* Referenced by: '<S59>/sat6' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSPTTempLo_C;/* Referenced by: '<S59>/sat7' */

/* AC_2_State_BOD */
extern CALDATA const volatile boolean KOPM_TMSPTTemp_C_ovrdflg;/* Referenced by: '<S59>/sat3' */

/* AC_2_State_BOD */
extern CALDATA const volatile float32 KOPM_TMSPTTemp_C_ovrdval;/* Referenced by: '<S59>/sat4' */

/* AC_2_State_BOD */
extern CALDATA const volatile uint8 KOPM_TMSPwrCoolFanSpdDutyHi_pct;/* Referenced by: '<S151>/sat6' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile uint8 KOPM_TMSPwrCoolFanSpdDutyLo_pct;/* Referenced by: '<S151>/sat7' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile boolean KOPM_TMSPwrCoolFanSpdDuty_pct_ovrdflg;/* Referenced by: '<S151>/sat3' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile uint8 KOPM_TMSPwrCoolFanSpdDuty_pct_ovrdval;/* Referenced by: '<S151>/sat4' */

/* VCU_7_DrvRange_BOD */
extern CALDATA const volatile uint8 KOPM_TPMSPressureStaFLHi_enum;/* Referenced by: '<S445>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_TPMSPressureStaFLLo_enum;/* Referenced by: '<S445>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_TPMSPressureStaFL_enum_ovrdflg;/* Referenced by: '<S445>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_TPMSPressureStaFL_enum_ovrdval;/* Referenced by: '<S445>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_TPMSPressureStaFRHi_enum;/* Referenced by: '<S446>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_TPMSPressureStaFRLo_enum;/* Referenced by: '<S446>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_TPMSPressureStaFR_enum_ovrdflg;/* Referenced by: '<S446>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_TPMSPressureStaFR_enum_ovrdval;/* Referenced by: '<S446>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_TPMSPressureStaRLHi_enum;/* Referenced by: '<S447>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_TPMSPressureStaRLLo_enum;/* Referenced by: '<S447>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_TPMSPressureStaRL_enum_ovrdflg;/* Referenced by: '<S447>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_TPMSPressureStaRL_enum_ovrdval;/* Referenced by: '<S447>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_TPMSPressureStaRRHi_enum;/* Referenced by: '<S448>/sat6' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_TPMSPressureStaRRLo_enum;/* Referenced by: '<S448>/sat7' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_TPMSPressureStaRR_enum_ovrdflg;/* Referenced by: '<S448>/sat3' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile uint8 KOPM_TPMSPressureStaRR_enum_ovrdval;/* Referenced by: '<S448>/sat4' */

/* BCM_B_Package_BAC */
extern CALDATA const volatile boolean KOPM_VCUACCStandstillReq_flg_ovrdflg;/* Referenced by: '<S274>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUACCStandstillReq_flg_ovrdval;/* Referenced by: '<S274>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUAccReqDrvOff_flg_ovrdflg;/* Referenced by: '<S183>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_VCUAccReqDrvOff_flg_ovrdval;/* Referenced by: '<S183>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_VCUAccReqStandstill_flg_ovrdflg;/* Referenced by: '<S184>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_VCUAccReqStandstill_flg_ovrdval;/* Referenced by: '<S184>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_VCUAccTgtAxHi_mps2;/* Referenced by: '<S276>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_VCUAccTgtAxLo_mps2;/* Referenced by: '<S276>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUAccTgtAxReq_flg_ovrdflg;/* Referenced by: '<S275>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUAccTgtAxReq_flg_ovrdval;/* Referenced by: '<S275>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUAccTgtAx_mps2_ovrdflg;/* Referenced by: '<S276>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_VCUAccTgtAx_mps2_ovrdval;/* Referenced by: '<S276>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_VCUBraTorReqHi_Nm;/* Referenced by: '<S277>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_VCUBraTorReqLo_Nm;/* Referenced by: '<S277>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUBraTorReq_Nm_ovrdflg;/* Referenced by: '<S277>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_VCUBraTorReq_Nm_ovrdval;/* Referenced by: '<S277>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_VCUCruiseCtrTgtSpdHi_kph;/* Referenced by: '<S278>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_VCUCruiseCtrTgtSpdLo_kph;/* Referenced by: '<S278>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUCruiseCtrTgtSpd_kph_ovrdflg;/* Referenced by: '<S278>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile float32 KOPM_VCUCruiseCtrTgtSpd_kph_ovrdval;/* Referenced by: '<S278>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_VCUCruiseCtrlStaHi_enum;/* Referenced by: '<S279>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_VCUCruiseCtrlStaLo_enum;/* Referenced by: '<S279>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUCruiseCtrlSta_enum_ovrdflg;/* Referenced by: '<S279>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile EnumCruiseStatus
  KOPM_VCUCruiseCtrlSta_enum_ovrdval;  /* Referenced by: '<S279>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_VCUEPBApplyForbidHi_enum;/* Referenced by: '<S280>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_VCUEPBApplyForbidLo_enum;/* Referenced by: '<S280>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUEPBApplyForbid_enum_ovrdflg;/* Referenced by: '<S280>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_VCUEPBApplyForbid_enum_ovrdval;/* Referenced by: '<S280>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUEnaEHBBrkRun_flg_ovrdflg;/* Referenced by: '<S185>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_VCUEnaEHBBrkRun_flg_ovrdval;/* Referenced by: '<S185>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_VCUMasterCylinderPreReqHi_Bar;/* Referenced by: '<S186>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_VCUMasterCylinderPreReqLo_Bar;/* Referenced by: '<S186>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_VCUMasterCylinderPreReq_Bar_ovrdflg;/* Referenced by: '<S186>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_VCUMasterCylinderPreReq_Bar_ovrdval;/* Referenced by: '<S186>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_VCUMotTorqueReqToEHBHi_Nm;/* Referenced by: '<S187>/sat6' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_VCUMotTorqueReqToEHBLo_Nm;/* Referenced by: '<S187>/sat7' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_VCUMotTorqueReqToEHB_Nm_ovrdflg;/* Referenced by: '<S187>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile float32 KOPM_VCUMotTorqueReqToEHB_Nm_ovrdval;/* Referenced by: '<S187>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_VCUParkSwStaVld_flg_ovrdflg;/* Referenced by: '<S281>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUParkSwStaVld_flg_ovrdval;/* Referenced by: '<S281>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUParkSwSta_flg_ovrdflg;/* Referenced by: '<S282>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUParkSwSta_flg_ovrdval;/* Referenced by: '<S282>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUPreKeReq_flg_ovrdflg;/* Referenced by: '<S283>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUPreKeReq_flg_ovrdval;/* Referenced by: '<S283>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_VCUReqAutoBrkHi_enum;/* Referenced by: '<S284>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_VCUReqAutoBrkLo_enum;/* Referenced by: '<S284>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUReqAutoBrk_enum_ovrdflg;/* Referenced by: '<S284>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_VCUReqAutoBrk_enum_ovrdval;/* Referenced by: '<S284>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_VCUReqEPBHi_enum;/* Referenced by: '<S286>/sat6' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile uint8 KOPM_VCUReqEPBLo_enum;/* Referenced by: '<S286>/sat7' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUReqEPBVld_flg_ovrdflg;/* Referenced by: '<S285>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUReqEPBVld_flg_ovrdval;/* Referenced by: '<S285>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUReqEPB_enum_ovrdflg;/* Referenced by: '<S286>/sat3' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile EnumEPBReq KOPM_VCUReqEPB_enum_ovrdval;/* Referenced by: '<S286>/sat4' */

/* VCU_D_Status_CHA */
extern CALDATA const volatile boolean KOPM_VCUVehSpdFastWarn_flg_ovrdflg;/* Referenced by: '<S188>/sat3' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile boolean KOPM_VCUVehSpdFastWarn_flg_ovrdval;/* Referenced by: '<S188>/sat4' */

/* VCU_10_Torque_CHA */
extern CALDATA const volatile uint8 KOPM_VehActDrvMod1Hi_enum;/* Referenced by: '<S343>/sat6' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_VehActDrvMod1Lo_enum;/* Referenced by: '<S343>/sat7' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_VehActDrvMod1_enum_ovrdflg;/* Referenced by: '<S343>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile EnumDrvModeAct KOPM_VehActDrvMod1_enum_ovrdval;/* Referenced by: '<S343>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_VehActDrvPwrHi_pct;/* Referenced by: '<S246>/sat6' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_VehActDrvPwrLo_pct;/* Referenced by: '<S246>/sat7' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_VehActDrvPwr_pct_ovrdflg;/* Referenced by: '<S246>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_VehActDrvPwr_pct_ovrdval;/* Referenced by: '<S246>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_VehActRecupPwrHi_pct;/* Referenced by: '<S247>/sat6' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_VehActRecupPwrLo_pct;/* Referenced by: '<S247>/sat7' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_VehActRecupPwr_pct_ovrdflg;/* Referenced by: '<S247>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_VehActRecupPwr_pct_ovrdval;/* Referenced by: '<S247>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_VehActlGearPosHi_enum;/* Referenced by: '<S345>/sat6' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile uint8 KOPM_VehActlGearPosLo_enum;/* Referenced by: '<S345>/sat7' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_VehActlGearPosVld_flg_ovrdflg;/* Referenced by: '<S344>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_VehActlGearPosVld_flg_ovrdval;/* Referenced by: '<S344>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_VehActlGearPos_enum_ovrdflg;/* Referenced by: '<S345>/sat3' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile EnumGearPstn KOPM_VehActlGearPos_enum_ovrdval;/* Referenced by: '<S345>/sat4' */

/* CCU_VehInfo_BAC */
extern CALDATA const volatile boolean KOPM_VehPGearError_flg_ovrdflg;/* Referenced by: '<S248>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_VehPGearError_flg_ovrdval;/* Referenced by: '<S248>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_VehPwrCnsmpAvrgHi_kWh;/* Referenced by: '<S249>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile float32 KOPM_VehPwrCnsmpAvrgLo_kWh;/* Referenced by: '<S249>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_VehPwrCnsmpAvrg_kWh_ovrdflg;/* Referenced by: '<S249>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_VehPwrCnsmpAvrg_kWh_ovrdval;/* Referenced by: '<S249>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile uint8 KOPM_VehTrgtGearPosHi_enum;/* Referenced by: '<S216>/sat6' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile uint8 KOPM_VehTrgtGearPosLo_enum;/* Referenced by: '<S216>/sat7' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile boolean KOPM_VehTrgtGearPos_enum_ovrdflg;/* Referenced by: '<S216>/sat3' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile EnumTgtGearPstn KOPM_VehTrgtGearPos_enum_ovrdval;/* Referenced by: '<S216>/sat4' */

/* VCU_1_InvCmd_EPT */
extern CALDATA const volatile float32 KOPM_VhclActlCnsmPwrHi_kWh;/* Referenced by: '<S250>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile float32 KOPM_VhclActlCnsmPwrLo_kWh;/* Referenced by: '<S250>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_VhclActlCnsmPwr_kWh_ovrdflg;/* Referenced by: '<S250>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_VhclActlCnsmPwr_kWh_ovrdval;/* Referenced by: '<S250>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_VhclSpdFstWarn_flg_ovrdflg;/* Referenced by: '<S251>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_VhclSpdFstWarn_flg_ovrdval;/* Referenced by: '<S251>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_WLTPDrvgRngDstHi_km;/* Referenced by: '<S253>/sat6' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile float32 KOPM_WLTPDrvgRngDstLo_km;/* Referenced by: '<S253>/sat7' */

/* VCU_B_AcclPedal_EPT */
extern CALDATA const volatile boolean KOPM_WLTPDrvgRngDstVld_flg_ovrdflg;/* Referenced by: '<S252>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_WLTPDrvgRngDstVld_flg_ovrdval;/* Referenced by: '<S252>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_WLTPDrvgRngDst_km_ovrdflg;/* Referenced by: '<S253>/sat3' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile float32 KOPM_WLTPDrvgRngDst_km_ovrdval;/* Referenced by: '<S253>/sat4' */

/* VCU_DispInfo_BAC */
extern CALDATA const volatile boolean KOPM_Zdznswi_flg_ovrdflg;/* Referenced by: '<S206>/sat3' */

/* VCU_0_Value_EPT */
extern CALDATA const volatile boolean KOPM_Zdznswi_flg_ovrdval;/* Referenced by: '<S206>/sat4' */

/* VCU_0_Value_EPT */
#endif                                 /* RTW_HEADER_calPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
