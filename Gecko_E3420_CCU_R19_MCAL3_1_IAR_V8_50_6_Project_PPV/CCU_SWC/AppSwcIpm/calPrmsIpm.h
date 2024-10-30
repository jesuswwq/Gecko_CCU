/*
 * File: calPrmsIpm.h
 *
 * Code generated for Simulink model 'AppSwcIpm'.
 *
 * Model version                  : 9.212
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Oct 28 18:01:57 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_calPrmsIpm_h_
#define RTW_HEADER_calPrmsIpm_h_
#include "rtwtypes.h"
#include "AppSwcIpm_types.h"

/* Exported data declaration */

/*Group of variables*/
#include "XcpTest_types.h"

/* Declaration for custom storage class: CalParam */
extern CALDATA const volatile boolean KIPM_ACCMCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst4' */
extern CALDATA const volatile boolean KIPM_ACCMLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg29' */
extern CALDATA const volatile boolean KIPM_ACCMLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg30' */
extern CALDATA const volatile uint8 KIPM_APPVerMaxDflt_enum;/* Referenced by: '<S15>/sat5' */
extern CALDATA const volatile boolean KIPM_APPVerMax_enum_ovrdflg;/* Referenced by: '<S15>/sat3' */
extern CALDATA const volatile uint8 KIPM_APPVerMax_enum_ovrdval;/* Referenced by: '<S15>/sat4' */
extern CALDATA const volatile uint8 KIPM_APPVerMinDflt_enum;/* Referenced by: '<S16>/sat5' */
extern CALDATA const volatile boolean KIPM_APPVerMin_enum_ovrdflg;/* Referenced by: '<S16>/sat3' */
extern CALDATA const volatile uint8 KIPM_APPVerMin_enum_ovrdval;/* Referenced by: '<S16>/sat4' */
extern CALDATA const volatile boolean KIPM_BACCANBusOffOvrdSw_flg;
                          /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg3' */
extern CALDATA const volatile boolean KIPM_BACCANBusOffOvrdVal_flg;
                          /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg5' */
extern CALDATA const volatile EnumBMSACChrgSt KIPM_BMSACChrgAtclStaDflt_enum;/* Referenced by: '<S321>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSACChrgAtclSta_enum_ovrdflg;/* Referenced by: '<S321>/sat3' */
extern CALDATA const volatile EnumBMSACChrgSt KIPM_BMSACChrgAtclSta_enum_ovrdval;/* Referenced by: '<S321>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSActExchgCurntDflt_A;/* Referenced by: '<S303>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSActExchgCurntHi_A;/* Referenced by: '<S303>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSActExchgCurntLo_A;/* Referenced by: '<S303>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSActExchgCurnt_A_ovrdflg;/* Referenced by: '<S303>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSActExchgCurnt_A_ovrdval;/* Referenced by: '<S303>/sat4' */
extern CALDATA const volatile uint8 KIPM_BMSBatCapctyDflt_Ah;/* Referenced by: '<S166>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSBatCapcty_Ah_ovrdflg;/* Referenced by: '<S166>/sat3' */
extern CALDATA const volatile uint8 KIPM_BMSBatCapcty_Ah_ovrdval;/* Referenced by: '<S166>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSBatSOCActDflt_pct;/* Referenced by: '<S312>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSBatSOCActHi_pct;/* Referenced by: '<S312>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSBatSOCActLo_pct;/* Referenced by: '<S312>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSBatSOCAct_pct_ovrdflg;/* Referenced by: '<S312>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSBatSOCAct_pct_ovrdval;/* Referenced by: '<S312>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSBatSOCRptDflt_pct;/* Referenced by: '<S313>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSBatSOCRptHi_pct;/* Referenced by: '<S313>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSBatSOCRptLo_pct;/* Referenced by: '<S313>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSBatSOCRpt_pct_ovrdflg;/* Referenced by: '<S313>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSBatSOCRpt_pct_ovrdval;/* Referenced by: '<S313>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSBatSOHDflt_pct;/* Referenced by: '<S314>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSBatSOHHi_pct;/* Referenced by: '<S314>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSBatSOHLo_pct;/* Referenced by: '<S314>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSBatSOH_pct_ovrdflg;/* Referenced by: '<S314>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSBatSOH_pct_ovrdval;/* Referenced by: '<S314>/sat4' */
extern CALDATA const volatile boolean KIPM_BMSCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst14' */
extern CALDATA const volatile float32 KIPM_BMSCellVoltMaxDflt_mV;/* Referenced by: '<S340>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSCellVoltMaxHi_mV;/* Referenced by: '<S340>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSCellVoltMaxLo_mV;/* Referenced by: '<S340>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSCellVoltMax_mV_ovrdflg;/* Referenced by: '<S340>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSCellVoltMax_mV_ovrdval;/* Referenced by: '<S340>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSCellVoltMinDflt_mV;/* Referenced by: '<S341>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSCellVoltMinHi_mV;/* Referenced by: '<S341>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSCellVoltMinLo_mV;/* Referenced by: '<S341>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSCellVoltMin_mV_ovrdflg;/* Referenced by: '<S341>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSCellVoltMin_mV_ovrdval;/* Referenced by: '<S341>/sat4' */
extern CALDATA const volatile uint8 KIPM_BMSChrgInterlockStaDflt_enum;/* Referenced by: '<S304>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSChrgInterlockSta_enum_ovrdflg;/* Referenced by: '<S304>/sat3' */
extern CALDATA const volatile uint8 KIPM_BMSChrgInterlockSta_enum_ovrdval;/* Referenced by: '<S304>/sat4' */
extern CALDATA const volatile EnumBMSDCSMd KIPM_BMSDCSActOprtModeDflt_enum;/* Referenced by: '<S301>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSDCSActOprtMode_enum_ovrdflg;/* Referenced by: '<S301>/sat3' */
extern CALDATA const volatile EnumBMSDCSMd KIPM_BMSDCSActOprtMode_enum_ovrdval;/* Referenced by: '<S301>/sat4' */
extern CALDATA const volatile boolean KIPM_BMSDCSChrgReqDflt_flg;/* Referenced by: '<S320>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSDCSChrgReq_flg_ovrdflg;/* Referenced by: '<S320>/sat3' */
extern CALDATA const volatile boolean KIPM_BMSDCSChrgReq_flg_ovrdval;/* Referenced by: '<S320>/sat4' */
extern CALDATA const volatile boolean KIPM_BMSDCSInletConnectStaDflt_flg;/* Referenced by: '<S302>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSDCSInletConnectSta_flg_ovrdflg;/* Referenced by: '<S302>/sat3' */
extern CALDATA const volatile boolean KIPM_BMSDCSInletConnectSta_flg_ovrdval;/* Referenced by: '<S302>/sat4' */
extern CALDATA const volatile uint8 KIPM_BMSDchrgInterlockStaDflt_enum;/* Referenced by: '<S305>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSDchrgInterlockSta_enum_ovrdflg;/* Referenced by: '<S305>/sat3' */
extern CALDATA const volatile uint8 KIPM_BMSDchrgInterlockSta_enum_ovrdval;/* Referenced by: '<S305>/sat4' */
extern CALDATA const volatile boolean KIPM_BMSEmgcySdnReqDflt_flg;/* Referenced by: '<S306>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSEmgcySdnReq_flg_ovrdflg;/* Referenced by: '<S306>/sat3' */
extern CALDATA const volatile boolean KIPM_BMSEmgcySdnReq_flg_ovrdval;/* Referenced by: '<S306>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSHVBatActVoltDflt_V;/* Referenced by: '<S315>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSHVBatActVoltHi_V;/* Referenced by: '<S315>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSHVBatActVoltLo_V;/* Referenced by: '<S315>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSHVBatActVolt_V_ovrdflg;/* Referenced by: '<S315>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSHVBatActVolt_V_ovrdval;/* Referenced by: '<S315>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSHVBatCellTempAveDflt_C;/* Referenced by: '<S121>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSHVBatCellTempAveHi_C;/* Referenced by: '<S121>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSHVBatCellTempAveLo_C;/* Referenced by: '<S121>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSHVBatCellTempAve_C_ovrdflg;/* Referenced by: '<S121>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSHVBatCellTempAve_C_ovrdval;/* Referenced by: '<S121>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSHVBatCellTempMaxDflt_C;/* Referenced by: '<S122>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSHVBatCellTempMaxHi_C;/* Referenced by: '<S122>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSHVBatCellTempMaxLo_C;/* Referenced by: '<S122>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSHVBatCellTempMax_C_ovrdflg;/* Referenced by: '<S122>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSHVBatCellTempMax_C_ovrdval;/* Referenced by: '<S122>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSHVBatCellTempMinDflt_C;/* Referenced by: '<S123>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSHVBatCellTempMinHi_C;/* Referenced by: '<S123>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSHVBatCellTempMinLo_C;/* Referenced by: '<S123>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSHVBatCellTempMin_C_ovrdflg;/* Referenced by: '<S123>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSHVBatCellTempMin_C_ovrdval;/* Referenced by: '<S123>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSInletCooltActlTempDflt_C;/* Referenced by: '<S322>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSInletCooltActlTempHi_C;/* Referenced by: '<S322>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSInletCooltActlTempLo_C;/* Referenced by: '<S322>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSInletCooltActlTemp_C_ovrdflg;/* Referenced by: '<S322>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSInletCooltActlTemp_C_ovrdval;/* Referenced by: '<S322>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSIsoResistDflt_MOhm;/* Referenced by: '<S323>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSIsoResistHi_MOhm;/* Referenced by: '<S323>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSIsoResistLo_MOhm;/* Referenced by: '<S323>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSIsoResist_MOhm_ovrdflg;/* Referenced by: '<S323>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSIsoResist_MOhm_ovrdval;/* Referenced by: '<S323>/sat4' */
extern CALDATA const volatile boolean KIPM_BMSLostCommOvrdSw_flg;
                          /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg8' */
extern CALDATA const volatile boolean KIPM_BMSLostCommOvrdVal_flg;
                          /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg9' */
extern CALDATA const volatile float32 KIPM_BMSMaxChrgCurntACDflt_A;/* Referenced by: '<S324>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSMaxChrgCurntACHi_A;/* Referenced by: '<S324>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSMaxChrgCurntACLo_A;/* Referenced by: '<S324>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSMaxChrgCurntAC_A_ovrdflg;/* Referenced by: '<S324>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSMaxChrgCurntAC_A_ovrdval;/* Referenced by: '<S324>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSMaxChrgVoltACDflt_V;/* Referenced by: '<S325>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSMaxChrgVoltACHi_V;/* Referenced by: '<S325>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSMaxChrgVoltACLo_V;/* Referenced by: '<S325>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSMaxChrgVoltAC_V_ovrdflg;/* Referenced by: '<S325>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSMaxChrgVoltAC_V_ovrdval;/* Referenced by: '<S325>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSMaxConChrgCurntDflt_A;/* Referenced by: '<S332>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSMaxConChrgCurntHi_A;/* Referenced by: '<S332>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSMaxConChrgCurntLo_A;/* Referenced by: '<S332>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSMaxConChrgCurnt_A_ovrdflg;/* Referenced by: '<S332>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSMaxConChrgCurnt_A_ovrdval;/* Referenced by: '<S332>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSMaxConDisCurntDflt_A;/* Referenced by: '<S333>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSMaxConDisCurntHi_A;/* Referenced by: '<S333>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSMaxConDisCurntLo_A;/* Referenced by: '<S333>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSMaxConDisCurnt_A_ovrdflg;/* Referenced by: '<S333>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSMaxConDisCurnt_A_ovrdval;/* Referenced by: '<S333>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSMaxInsChrgCurntDflt_A;/* Referenced by: '<S334>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSMaxInsChrgCurntHi_A;/* Referenced by: '<S334>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSMaxInsChrgCurntLo_A;/* Referenced by: '<S334>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSMaxInsChrgCurnt_A_ovrdflg;/* Referenced by: '<S334>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSMaxInsChrgCurnt_A_ovrdval;/* Referenced by: '<S334>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSMaxInsDisCurntDflt_A;/* Referenced by: '<S335>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSMaxInsDisCurntHi_A;/* Referenced by: '<S335>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSMaxInsDisCurntLo_A;/* Referenced by: '<S335>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSMaxInsDisCurnt_A_ovrdflg;/* Referenced by: '<S335>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSMaxInsDisCurnt_A_ovrdval;/* Referenced by: '<S335>/sat4' */
extern CALDATA const volatile float32 KIPM_BMSOutlCooltActlTempDflt_C;/* Referenced by: '<S326>/sat5' */
extern CALDATA const volatile float32 KIPM_BMSOutlCooltActlTempHi_C;/* Referenced by: '<S326>/sat6' */
extern CALDATA const volatile float32 KIPM_BMSOutlCooltActlTempLo_C;/* Referenced by: '<S326>/sat7' */
extern CALDATA const volatile boolean KIPM_BMSOutlCooltActlTemp_C_ovrdflg;/* Referenced by: '<S326>/sat3' */
extern CALDATA const volatile float32 KIPM_BMSOutlCooltActlTemp_C_ovrdval;/* Referenced by: '<S326>/sat4' */
extern CALDATA const volatile uint8 KIPM_BMSPackIDDflt_enum;/* Referenced by: '<S167>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSPackID_enum_ovrdflg;/* Referenced by: '<S167>/sat3' */
extern CALDATA const volatile uint8 KIPM_BMSPackID_enum_ovrdval;/* Referenced by: '<S167>/sat4' */
extern CALDATA const volatile uint8 KIPM_BMSPwrTrainConnectStaDflt_enum;/* Referenced by: '<S307>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSPwrTrainConnectSta_enum_ovrdflg;/* Referenced by: '<S307>/sat3' */
extern CALDATA const volatile uint8 KIPM_BMSPwrTrainConnectSta_enum_ovrdval;/* Referenced by: '<S307>/sat4' */
extern CALDATA const volatile EnumBMSRunSt KIPM_BMSRunStaDflt_enum;/* Referenced by: '<S308>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSRunSta_enum_ovrdflg;/* Referenced by: '<S308>/sat3' */
extern CALDATA const volatile EnumBMSRunSt KIPM_BMSRunSta_enum_ovrdval;/* Referenced by: '<S308>/sat4' */
extern CALDATA const volatile uint8 KIPM_BMSSysFailStaDflt_enum;/* Referenced by: '<S309>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSSysFailSta_enum_ovrdflg;/* Referenced by: '<S309>/sat3' */
extern CALDATA const volatile uint8 KIPM_BMSSysFailSta_enum_ovrdval;/* Referenced by: '<S309>/sat4' */
extern CALDATA const volatile uint8 KIPM_BMSThermrunawayWrnDflt_enum;/* Referenced by: '<S310>/sat5' */
extern CALDATA const volatile boolean KIPM_BMSThermrunawayWrn_enum_ovrdflg;/* Referenced by: '<S310>/sat3' */
extern CALDATA const volatile uint8 KIPM_BMSThermrunawayWrn_enum_ovrdval;/* Referenced by: '<S310>/sat4' */
extern CALDATA const volatile boolean KIPM_BODCANBusOffOvrdSw_flg;
                          /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg1' */
extern CALDATA const volatile boolean KIPM_BODCANBusOffOvrdVal_flg;
                          /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg2' */
extern CALDATA const volatile uint8 KIPM_BootVerDflt_enum;/* Referenced by: '<S17>/sat5' */
extern CALDATA const volatile boolean KIPM_BootVer_enum_ovrdflg;/* Referenced by: '<S17>/sat3' */
extern CALDATA const volatile uint8 KIPM_BootVer_enum_ovrdval;/* Referenced by: '<S17>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPACAutoKeyDflt_flg;/* Referenced by: '<S347>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPACAutoKey_flg_ovrdflg;/* Referenced by: '<S347>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPACAutoKey_flg_ovrdval;/* Referenced by: '<S347>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPACSwKeyDflt_flg;/* Referenced by: '<S348>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPACSwKey_flg_ovrdflg;/* Referenced by: '<S348>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPACSwKey_flg_ovrdval;/* Referenced by: '<S348>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPAVASOffKeyDflt_flg;/* Referenced by: '<S349>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPAVASOffKey_flg_ovrdflg;/* Referenced by: '<S349>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPAVASOffKey_flg_ovrdval;/* Referenced by: '<S349>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPAVHKeyDflt_flg;/* Referenced by: '<S350>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPAVHKey_flg_ovrdflg;/* Referenced by: '<S350>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPAVHKey_flg_ovrdval;/* Referenced by: '<S350>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPAirInletModeKeyDflt_flg;/* Referenced by: '<S351>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPAirInletModeKey_flg_ovrdflg;/* Referenced by: '<S351>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPAirInletModeKey_flg_ovrdval;/* Referenced by: '<S351>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPBlwngModeNextKeyDflt_flg;/* Referenced by: '<S352>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPBlwngModeNextKey_flg_ovrdflg;/* Referenced by: '<S352>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPBlwngModeNextKey_flg_ovrdval;/* Referenced by: '<S352>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPBlwngModePrevKeyDflt_flg;/* Referenced by: '<S353>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPBlwngModePrevKey_flg_ovrdflg;/* Referenced by: '<S353>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPBlwngModePrevKey_flg_ovrdval;/* Referenced by: '<S353>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPBlwrLvlAddKeyDflt_flg;/* Referenced by: '<S354>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPBlwrLvlAddKey_flg_ovrdflg;/* Referenced by: '<S354>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPBlwrLvlAddKey_flg_ovrdval;/* Referenced by: '<S354>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPBlwrLvlDecKeyDflt_flg;/* Referenced by: '<S355>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPBlwrLvlDecKey_flg_ovrdflg;/* Referenced by: '<S355>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPBlwrLvlDecKey_flg_ovrdval;/* Referenced by: '<S355>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst3' */
extern CALDATA const volatile boolean KIPM_CCPCenLckKeyDflt_flg;/* Referenced by: '<S356>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPCenLckKey_flg_ovrdflg;/* Referenced by: '<S356>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPCenLckKey_flg_ovrdval;/* Referenced by: '<S356>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPESCOffKeyDflt_flg;/* Referenced by: '<S357>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPESCOffKey_flg_ovrdflg;/* Referenced by: '<S357>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPESCOffKey_flg_ovrdval;/* Referenced by: '<S357>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPFrntWindDefrstKeyDflt_flg;/* Referenced by: '<S358>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPFrntWindDefrstKey_flg_ovrdflg;/* Referenced by: '<S358>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPFrntWindDefrstKey_flg_ovrdval;/* Referenced by: '<S358>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPHDCKeyDflt_flg;/* Referenced by: '<S359>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPHDCKey_flg_ovrdflg;/* Referenced by: '<S359>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPHDCKey_flg_ovrdval;/* Referenced by: '<S359>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPHzrdKeyDflt_flg;/* Referenced by: '<S360>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPHzrdKey_flg_ovrdflg;/* Referenced by: '<S360>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPHzrdKey_flg_ovrdval;/* Referenced by: '<S360>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg41' */
extern CALDATA const volatile boolean KIPM_CCPLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg42' */
extern CALDATA const volatile boolean KIPM_CCPModeKeyDflt_flg;/* Referenced by: '<S361>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPModeKey_flg_ovrdflg;/* Referenced by: '<S361>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPModeKey_flg_ovrdval;/* Referenced by: '<S361>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPPwrRecupLvlKeyDflt_flg;/* Referenced by: '<S362>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPPwrRecupLvlKey_flg_ovrdflg;/* Referenced by: '<S362>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPPwrRecupLvlKey_flg_ovrdval;/* Referenced by: '<S362>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPRrViewMirrHeatgKeyDflt_flg;/* Referenced by: '<S363>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPRrViewMirrHeatgKey_flg_ovrdflg;/* Referenced by: '<S363>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPRrViewMirrHeatgKey_flg_ovrdval;/* Referenced by: '<S363>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPTPMSKeyDflt_flg;/* Referenced by: '<S364>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPTPMSKey_flg_ovrdflg;/* Referenced by: '<S364>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPTPMSKey_flg_ovrdval;/* Referenced by: '<S364>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPTempAddKeyDflt_flg;/* Referenced by: '<S365>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPTempAddKey_flg_ovrdflg;/* Referenced by: '<S365>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPTempAddKey_flg_ovrdval;/* Referenced by: '<S365>/sat4' */
extern CALDATA const volatile boolean KIPM_CCPTempDecKeyDflt_flg;/* Referenced by: '<S366>/sat5' */
extern CALDATA const volatile boolean KIPM_CCPTempDecKey_flg_ovrdflg;/* Referenced by: '<S366>/sat3' */
extern CALDATA const volatile boolean KIPM_CCPTempDecKey_flg_ovrdval;/* Referenced by: '<S366>/sat4' */
extern CALDATA const volatile uint8 KIPM_CDCBackLadjvalDflt_enum;/* Referenced by: '<S72>/sat5' */
extern CALDATA const volatile boolean KIPM_CDCBackLadjval_enum_ovrdflg;/* Referenced by: '<S72>/sat3' */
extern CALDATA const volatile uint8 KIPM_CDCBackLadjval_enum_ovrdval;/* Referenced by: '<S72>/sat4' */
extern CALDATA const volatile boolean KIPM_CDCLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg33' */
extern CALDATA const volatile boolean KIPM_CDCLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg34' */
extern CALDATA const volatile boolean KIPM_CHACANBusOffOvrdSw_flg;
                          /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg6' */
extern CALDATA const volatile boolean KIPM_CHACANBusOffOvrdVal_flg;
                          /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg7' */
extern CALDATA const volatile boolean KIPM_COMPCANBusOffDflt_flg;/* Referenced by: '<S24>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPCANBusOff_flg_ovrdflg;/* Referenced by: '<S24>/sat3' */
extern CALDATA const volatile boolean KIPM_COMPCANBusOff_flg_ovrdval;/* Referenced by: '<S24>/sat4' */
extern CALDATA const volatile boolean KIPM_COMPCommuErrorDflt_flg;/* Referenced by: '<S25>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPCommuError_flg_ovrdflg;/* Referenced by: '<S25>/sat3' */
extern CALDATA const volatile boolean KIPM_COMPCommuError_flg_ovrdval;/* Referenced by: '<S25>/sat4' */
extern CALDATA const volatile boolean KIPM_COMPCurrOfstDflt_flg;/* Referenced by: '<S26>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPCurrOfst_flg_ovrdflg;/* Referenced by: '<S26>/sat3' */
extern CALDATA const volatile boolean KIPM_COMPCurrOfst_flg_ovrdval;/* Referenced by: '<S26>/sat4' */
extern CALDATA const volatile float32 KIPM_COMPEcompActSpdDflt_rpm;/* Referenced by: '<S27>/sat5' */
extern CALDATA const volatile float32 KIPM_COMPEcompActSpdHi_rpm;/* Referenced by: '<S27>/sat6' */
extern CALDATA const volatile float32 KIPM_COMPEcompActSpdLo_rpm;/* Referenced by: '<S27>/sat7' */
extern CALDATA const volatile boolean KIPM_COMPEcompActSpd_rpm_ovrdflg;/* Referenced by: '<S27>/sat3' */
extern CALDATA const volatile float32 KIPM_COMPEcompActSpd_rpm_ovrdval;/* Referenced by: '<S27>/sat4' */
extern CALDATA const volatile uint8 KIPM_COMPEcompSTDflt_enum;/* Referenced by: '<S28>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPEcompST_enum_ovrdflg;/* Referenced by: '<S28>/sat3' */
extern CALDATA const volatile uint8 KIPM_COMPEcompST_enum_ovrdval;/* Referenced by: '<S28>/sat4' */
extern CALDATA const volatile float32 KIPM_COMPHiVoltDflt_V;/* Referenced by: '<S29>/sat5' */
extern CALDATA const volatile float32 KIPM_COMPHiVoltHi_V;/* Referenced by: '<S29>/sat6' */
extern CALDATA const volatile float32 KIPM_COMPHiVoltLo_V;/* Referenced by: '<S29>/sat7' */
extern CALDATA const volatile boolean KIPM_COMPHiVolt_V_ovrdflg;/* Referenced by: '<S29>/sat3' */
extern CALDATA const volatile float32 KIPM_COMPHiVolt_V_ovrdval;/* Referenced by: '<S29>/sat4' */
extern CALDATA const volatile uint8 KIPM_COMPHvErrDflt_enum;/* Referenced by: '<S30>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPHvErr_enum_ovrdflg;/* Referenced by: '<S30>/sat3' */
extern CALDATA const volatile uint8 KIPM_COMPHvErr_enum_ovrdval;/* Referenced by: '<S30>/sat4' */
extern CALDATA const volatile boolean KIPM_COMPIPMErrDflt_flg;/* Referenced by: '<S31>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPIPMErr_flg_ovrdflg;/* Referenced by: '<S31>/sat3' */
extern CALDATA const volatile boolean KIPM_COMPIPMErr_flg_ovrdval;/* Referenced by: '<S31>/sat4' */
extern CALDATA const volatile float32 KIPM_COMPInCurrDflt_A;/* Referenced by: '<S32>/sat5' */
extern CALDATA const volatile float32 KIPM_COMPInCurrHi_A;/* Referenced by: '<S32>/sat6' */
extern CALDATA const volatile float32 KIPM_COMPInCurrLo_A;/* Referenced by: '<S32>/sat7' */
extern CALDATA const volatile boolean KIPM_COMPInCurr_A_ovrdflg;/* Referenced by: '<S32>/sat3' */
extern CALDATA const volatile float32 KIPM_COMPInCurr_A_ovrdval;/* Referenced by: '<S32>/sat4' */
extern CALDATA const volatile boolean KIPM_COMPLoseStepDflt_flg;/* Referenced by: '<S33>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPLoseStep_flg_ovrdflg;/* Referenced by: '<S33>/sat3' */
extern CALDATA const volatile boolean KIPM_COMPLoseStep_flg_ovrdval;/* Referenced by: '<S33>/sat4' */
extern CALDATA const volatile uint8 KIPM_COMPLvErrDflt_enum;/* Referenced by: '<S34>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPLvErr_enum_ovrdflg;/* Referenced by: '<S34>/sat3' */
extern CALDATA const volatile uint8 KIPM_COMPLvErr_enum_ovrdval;/* Referenced by: '<S34>/sat4' */
extern CALDATA const volatile boolean KIPM_COMPOverDutyDflt_flg;/* Referenced by: '<S35>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPOverDuty_flg_ovrdflg;/* Referenced by: '<S35>/sat3' */
extern CALDATA const volatile boolean KIPM_COMPOverDuty_flg_ovrdval;/* Referenced by: '<S35>/sat4' */
extern CALDATA const volatile uint8 KIPM_COMPOvrCurrDflt_enum;/* Referenced by: '<S36>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPOvrCurr_enum_ovrdflg;/* Referenced by: '<S36>/sat3' */
extern CALDATA const volatile uint8 KIPM_COMPOvrCurr_enum_ovrdval;/* Referenced by: '<S36>/sat4' */
extern CALDATA const volatile boolean KIPM_COMPPISaturationDflt_flg;/* Referenced by: '<S37>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPPISaturation_flg_ovrdflg;/* Referenced by: '<S37>/sat3' */
extern CALDATA const volatile boolean KIPM_COMPPISaturation_flg_ovrdval;/* Referenced by: '<S37>/sat4' */
extern CALDATA const volatile uint8 KIPM_COMPSelfChkErrDflt_enum;/* Referenced by: '<S38>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPSelfChkErr_enum_ovrdflg;/* Referenced by: '<S38>/sat3' */
extern CALDATA const volatile uint8 KIPM_COMPSelfChkErr_enum_ovrdval;/* Referenced by: '<S38>/sat4' */
extern CALDATA const volatile float32 KIPM_COMPTempDflt_C;/* Referenced by: '<S40>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPTempErrDflt_flg;/* Referenced by: '<S39>/sat5' */
extern CALDATA const volatile boolean KIPM_COMPTempErr_flg_ovrdflg;/* Referenced by: '<S39>/sat3' */
extern CALDATA const volatile boolean KIPM_COMPTempErr_flg_ovrdval;/* Referenced by: '<S39>/sat4' */
extern CALDATA const volatile float32 KIPM_COMPTempHi_C;/* Referenced by: '<S40>/sat6' */
extern CALDATA const volatile float32 KIPM_COMPTempLo_C;/* Referenced by: '<S40>/sat7' */
extern CALDATA const volatile boolean KIPM_COMPTemp_C_ovrdflg;/* Referenced by: '<S40>/sat3' */
extern CALDATA const volatile float32 KIPM_COMPTemp_C_ovrdval;/* Referenced by: '<S40>/sat4' */
extern CALDATA const volatile uint8 KIPM_CRRRBSDWarnLtDflt_enum;/* Referenced by: '<S264>/sat5' */
extern CALDATA const volatile boolean KIPM_CRRRBSDWarnLt_enum_ovrdflg;/* Referenced by: '<S264>/sat3' */
extern CALDATA const volatile uint8 KIPM_CRRRBSDWarnLt_enum_ovrdval;/* Referenced by: '<S264>/sat4' */
extern CALDATA const volatile uint8 KIPM_CRRRBSDWarnRtDflt_enum;/* Referenced by: '<S265>/sat5' */
extern CALDATA const volatile boolean KIPM_CRRRBSDWarnRt_enum_ovrdflg;/* Referenced by: '<S265>/sat3' */
extern CALDATA const volatile uint8 KIPM_CRRRBSDWarnRt_enum_ovrdval;/* Referenced by: '<S265>/sat4' */
extern CALDATA const volatile boolean KIPM_CRRRCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst7' */
extern CALDATA const volatile uint8 KIPM_CRRRDOWWarnLtDflt_enum;/* Referenced by: '<S266>/sat5' */
extern CALDATA const volatile boolean KIPM_CRRRDOWWarnLt_enum_ovrdflg;/* Referenced by: '<S266>/sat3' */
extern CALDATA const volatile uint8 KIPM_CRRRDOWWarnLt_enum_ovrdval;/* Referenced by: '<S266>/sat4' */
extern CALDATA const volatile uint8 KIPM_CRRRDOWWarnRtDflt_enum;/* Referenced by: '<S267>/sat5' */
extern CALDATA const volatile boolean KIPM_CRRRDOWWarnRt_enum_ovrdflg;/* Referenced by: '<S267>/sat3' */
extern CALDATA const volatile uint8 KIPM_CRRRDOWWarnRt_enum_ovrdval;/* Referenced by: '<S267>/sat4' */
extern CALDATA const volatile boolean KIPM_CRRRLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg15' */
extern CALDATA const volatile boolean KIPM_CRRRLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg16' */
extern CALDATA const volatile uint8 KIPM_CRRRRCTAWarnLtDflt_enum;/* Referenced by: '<S268>/sat5' */
extern CALDATA const volatile boolean KIPM_CRRRRCTAWarnLt_enum_ovrdflg;/* Referenced by: '<S268>/sat3' */
extern CALDATA const volatile uint8 KIPM_CRRRRCTAWarnLt_enum_ovrdval;/* Referenced by: '<S268>/sat4' */
extern CALDATA const volatile uint8 KIPM_CRRRRCTAWarnRtDflt_enum;/* Referenced by: '<S269>/sat5' */
extern CALDATA const volatile boolean KIPM_CRRRRCTAWarnRt_enum_ovrdflg;/* Referenced by: '<S269>/sat3' */
extern CALDATA const volatile uint8 KIPM_CRRRRCTAWarnRt_enum_ovrdval;/* Referenced by: '<S269>/sat4' */
extern CALDATA const volatile uint8 KIPM_ClientNumDflt_enum;/* Referenced by: '<S18>/sat5' */
extern CALDATA const volatile boolean KIPM_ClientNum_enum_ovrdflg;/* Referenced by: '<S18>/sat3' */
extern CALDATA const volatile uint8 KIPM_ClientNum_enum_ovrdval;/* Referenced by: '<S18>/sat4' */
extern CALDATA const volatile boolean KIPM_ECUHiVoltInterlockSigDflt_flg;/* Referenced by: '<S41>/sat5' */
extern CALDATA const volatile boolean KIPM_ECUHiVoltInterlockSig_flg_ovrdflg;/* Referenced by: '<S41>/sat3' */
extern CALDATA const volatile boolean KIPM_ECUHiVoltInterlockSig_flg_ovrdval;/* Referenced by: '<S41>/sat4' */
extern CALDATA const volatile EnumAVHSt KIPM_EHBAVHAppldStDflt_enum;/* Referenced by: '<S270>/sat5' */
extern CALDATA const volatile boolean KIPM_EHBAVHAppldSt_enum_ovrdflg;/* Referenced by: '<S270>/sat3' */
extern CALDATA const volatile EnumAVHSt KIPM_EHBAVHAppldSt_enum_ovrdval;/* Referenced by: '<S270>/sat4' */
extern CALDATA const volatile boolean KIPM_EHBBLADflt_flg;/* Referenced by: '<S271>/sat5' */
extern CALDATA const volatile boolean KIPM_EHBBLA_flg_ovrdflg;/* Referenced by: '<S271>/sat3' */
extern CALDATA const volatile boolean KIPM_EHBBLA_flg_ovrdval;/* Referenced by: '<S271>/sat4' */
extern CALDATA const volatile float32 KIPM_EHBBrkPedlValPercDflt_pct;/* Referenced by: '<S174>/sat5' */
extern CALDATA const volatile float32 KIPM_EHBBrkPedlValPercHi_pct;/* Referenced by: '<S174>/sat6' */
extern CALDATA const volatile float32 KIPM_EHBBrkPedlValPercLo_pct;/* Referenced by: '<S174>/sat7' */
extern CALDATA const volatile boolean KIPM_EHBBrkPedlValPerc_pct_ovrdflg;/* Referenced by: '<S174>/sat3' */
extern CALDATA const volatile float32 KIPM_EHBBrkPedlValPerc_pct_ovrdval;/* Referenced by: '<S174>/sat4' */
extern CALDATA const volatile float32 KIPM_EHBBrkPwrRecupTarWhlTqDflt_Nm;/* Referenced by: '<S176>/sat5' */
extern CALDATA const volatile float32 KIPM_EHBBrkPwrRecupTarWhlTqHi_Nm;/* Referenced by: '<S176>/sat6' */
extern CALDATA const volatile float32 KIPM_EHBBrkPwrRecupTarWhlTqLo_Nm;/* Referenced by: '<S176>/sat7' */
extern CALDATA const volatile EnumRegenTgtTqStat
  KIPM_EHBBrkPwrRecupTarWhlTqStsDflt_enum;/* Referenced by: '<S175>/sat5' */
extern CALDATA const volatile boolean
  KIPM_EHBBrkPwrRecupTarWhlTqSts_enum_ovrdflg;/* Referenced by: '<S175>/sat3' */
extern CALDATA const volatile EnumRegenTgtTqStat
  KIPM_EHBBrkPwrRecupTarWhlTqSts_enum_ovrdval;/* Referenced by: '<S175>/sat4' */
extern CALDATA const volatile boolean KIPM_EHBBrkPwrRecupTarWhlTq_Nm_ovrdflg;/* Referenced by: '<S176>/sat3' */
extern CALDATA const volatile float32 KIPM_EHBBrkPwrRecupTarWhlTq_Nm_ovrdval;/* Referenced by: '<S176>/sat4' */
extern CALDATA const volatile boolean KIPM_EHBCDDActvDflt_flg;/* Referenced by: '<S177>/sat5' */
extern CALDATA const volatile boolean KIPM_EHBCDDActv_flg_ovrdflg;/* Referenced by: '<S177>/sat3' */
extern CALDATA const volatile boolean KIPM_EHBCDDActv_flg_ovrdval;/* Referenced by: '<S177>/sat4' */
extern CALDATA const volatile boolean KIPM_EHBCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst8' */
extern CALDATA const volatile EnumEPBState KIPM_EHBEPBActuatorStLDflt_enum;/* Referenced by: '<S272>/sat5' */
extern CALDATA const volatile boolean KIPM_EHBEPBActuatorStL_enum_ovrdflg;/* Referenced by: '<S272>/sat3' */
extern CALDATA const volatile EnumEPBState KIPM_EHBEPBActuatorStL_enum_ovrdval;/* Referenced by: '<S272>/sat4' */
extern CALDATA const volatile EnumEPBState KIPM_EHBEPBActuatorStRDflt_enum;/* Referenced by: '<S178>/sat5' */
extern CALDATA const volatile boolean KIPM_EHBEPBActuatorStR_enum_ovrdflg;/* Referenced by: '<S178>/sat3' */
extern CALDATA const volatile EnumEPBState KIPM_EHBEPBActuatorStR_enum_ovrdval;/* Referenced by: '<S178>/sat4' */
extern CALDATA const volatile uint8 KIPM_EHBEPBDynAppStDflt_enum;/* Referenced by: '<S179>/sat5' */
extern CALDATA const volatile boolean KIPM_EHBEPBDynAppSt_enum_ovrdflg;/* Referenced by: '<S179>/sat3' */
extern CALDATA const volatile uint8 KIPM_EHBEPBDynAppSt_enum_ovrdval;/* Referenced by: '<S179>/sat4' */
extern CALDATA const volatile EnumEPBSwSt KIPM_EHBEPBSwitchStsDflt_enum;/* Referenced by: '<S273>/sat5' */
extern CALDATA const volatile boolean KIPM_EHBEPBSwitchSts_enum_ovrdflg;/* Referenced by: '<S273>/sat3' */
extern CALDATA const volatile EnumEPBSwSt KIPM_EHBEPBSwitchSts_enum_ovrdval;/* Referenced by: '<S273>/sat4' */
extern CALDATA const volatile EnumEPBSysSt KIPM_EHBEPBSysStDflt_enum;/* Referenced by: '<S274>/sat5' */
extern CALDATA const volatile boolean KIPM_EHBEPBSysSt_enum_ovrdflg;/* Referenced by: '<S274>/sat3' */
extern CALDATA const volatile EnumEPBSysSt KIPM_EHBEPBSysSt_enum_ovrdval;/* Referenced by: '<S274>/sat4' */
extern CALDATA const volatile uint8 KIPM_EHBFltLvlDflt_enum;/* Referenced by: '<S180>/sat5' */
extern CALDATA const volatile boolean KIPM_EHBFltLvl_enum_ovrdflg;/* Referenced by: '<S180>/sat3' */
extern CALDATA const volatile uint8 KIPM_EHBFltLvl_enum_ovrdval;/* Referenced by: '<S180>/sat4' */
extern CALDATA const volatile boolean KIPM_EHBHDCFucFaultDflt_flg;/* Referenced by: '<S275>/sat5' */
extern CALDATA const volatile boolean KIPM_EHBHDCFucFault_flg_ovrdflg;/* Referenced by: '<S275>/sat3' */
extern CALDATA const volatile boolean KIPM_EHBHDCFucFault_flg_ovrdval;/* Referenced by: '<S275>/sat4' */
extern CALDATA const volatile boolean KIPM_EHBLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg37' */
extern CALDATA const volatile boolean KIPM_EHBLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg38' */
extern CALDATA const volatile boolean KIPM_EHBReqBrkLiOnDflt_flg;/* Referenced by: '<S181>/sat5' */
extern CALDATA const volatile boolean KIPM_EHBReqBrkLiOn_flg_ovrdflg;/* Referenced by: '<S181>/sat3' */
extern CALDATA const volatile boolean KIPM_EHBReqBrkLiOn_flg_ovrdval;/* Referenced by: '<S181>/sat4' */
extern CALDATA const volatile boolean KIPM_EPSCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst9' */
extern CALDATA const volatile boolean KIPM_EPSLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg19' */
extern CALDATA const volatile boolean KIPM_EPSLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg20' */
extern CALDATA const volatile float32 KIPM_EPSRotSpdDflt_degps;/* Referenced by: '<S183>/sat5' */
extern CALDATA const volatile float32 KIPM_EPSRotSpdHi_degps;/* Referenced by: '<S183>/sat6' */
extern CALDATA const volatile float32 KIPM_EPSRotSpdLo_degps;/* Referenced by: '<S183>/sat7' */
extern CALDATA const volatile boolean KIPM_EPSRotSpd_degps_ovrdflg;/* Referenced by: '<S183>/sat3' */
extern CALDATA const volatile float32 KIPM_EPSRotSpd_degps_ovrdval;/* Referenced by: '<S183>/sat4' */
extern CALDATA const volatile boolean KIPM_EPSSteerWhlAngCaldDflt_flg;/* Referenced by: '<S184>/sat5' */
extern CALDATA const volatile boolean KIPM_EPSSteerWhlAngCald_flg_ovrdflg;/* Referenced by: '<S184>/sat3' */
extern CALDATA const volatile boolean KIPM_EPSSteerWhlAngCald_flg_ovrdval;/* Referenced by: '<S184>/sat4' */
extern CALDATA const volatile float32 KIPM_EPSSteerWhlAngDflt_deg;/* Referenced by: '<S186>/sat5' */
extern CALDATA const volatile boolean KIPM_EPSSteerWhlAngFailrDflt_flg;/* Referenced by: '<S185>/sat5' */
extern CALDATA const volatile boolean KIPM_EPSSteerWhlAngFailr_flg_ovrdflg;/* Referenced by: '<S185>/sat3' */
extern CALDATA const volatile boolean KIPM_EPSSteerWhlAngFailr_flg_ovrdval;/* Referenced by: '<S185>/sat4' */
extern CALDATA const volatile float32 KIPM_EPSSteerWhlAngHi_deg;/* Referenced by: '<S186>/sat6' */
extern CALDATA const volatile float32 KIPM_EPSSteerWhlAngLo_deg;/* Referenced by: '<S186>/sat7' */
extern CALDATA const volatile boolean KIPM_EPSSteerWhlAng_deg_ovrdflg;/* Referenced by: '<S186>/sat3' */
extern CALDATA const volatile float32 KIPM_EPSSteerWhlAng_deg_ovrdval;/* Referenced by: '<S186>/sat4' */
extern CALDATA const volatile boolean KIPM_EPTCANBusOffOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg11' */
extern CALDATA const volatile boolean KIPM_EPTCANBusOffOvrdVal_flg;
                          /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg4' */
extern CALDATA const volatile boolean KIPM_ESCABSActvStaDflt_flg;/* Referenced by: '<S189>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCABSActvSta_flg_ovrdflg;/* Referenced by: '<S189>/sat3' */
extern CALDATA const volatile boolean KIPM_ESCABSActvSta_flg_ovrdval;/* Referenced by: '<S189>/sat4' */
extern CALDATA const volatile boolean KIPM_ESCCDPActvDflt_flg;/* Referenced by: '<S190>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCCDPActv_flg_ovrdflg;/* Referenced by: '<S190>/sat3' */
extern CALDATA const volatile boolean KIPM_ESCCDPActv_flg_ovrdval;/* Referenced by: '<S190>/sat4' */
extern CALDATA const volatile boolean KIPM_ESCCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst10' */
extern CALDATA const volatile boolean KIPM_ESCEBDActvDflt_flg;/* Referenced by: '<S191>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCEBDActv_flg_ovrdflg;/* Referenced by: '<S191>/sat3' */
extern CALDATA const volatile boolean KIPM_ESCEBDActv_flg_ovrdval;/* Referenced by: '<S191>/sat4' */
extern CALDATA const volatile boolean KIPM_ESCESPActvStaDflt_flg;/* Referenced by: '<S192>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCESPActvSta_flg_ovrdflg;/* Referenced by: '<S192>/sat3' */
extern CALDATA const volatile boolean KIPM_ESCESPActvSta_flg_ovrdval;/* Referenced by: '<S192>/sat4' */
extern CALDATA const volatile boolean KIPM_ESCESSActvDflt_flg;/* Referenced by: '<S193>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCESSActv_flg_ovrdflg;/* Referenced by: '<S193>/sat3' */
extern CALDATA const volatile boolean KIPM_ESCESSActv_flg_ovrdval;/* Referenced by: '<S193>/sat4' */
extern CALDATA const volatile uint8 KIPM_ESCFltLvlDflt_enum;/* Referenced by: '<S194>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCFltLvl_enum_ovrdflg;/* Referenced by: '<S194>/sat3' */
extern CALDATA const volatile uint8 KIPM_ESCFltLvl_enum_ovrdval;/* Referenced by: '<S194>/sat4' */
extern CALDATA const volatile uint64 KIPM_ESCLUnOrLockfeedbackDflt_nu;/* Referenced by: '<S367>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCLUnOrLockfeedback_nu_ovrdflg;/* Referenced by: '<S367>/sat3' */
extern CALDATA const volatile uint64 KIPM_ESCLUnOrLockfeedback_nu_ovrdval;/* Referenced by: '<S367>/sat4' */
extern CALDATA const volatile float32 KIPM_ESCLatAccSnsrValDflt_g;/* Referenced by: '<S201>/sat5' */
extern CALDATA const volatile float32 KIPM_ESCLatAccSnsrValHi_g;/* Referenced by: '<S201>/sat6' */
extern CALDATA const volatile float32 KIPM_ESCLatAccSnsrValLo_g;/* Referenced by: '<S201>/sat7' */
extern CALDATA const volatile boolean KIPM_ESCLatAccSnsrVal_g_ovrdflg;/* Referenced by: '<S201>/sat3' */
extern CALDATA const volatile float32 KIPM_ESCLatAccSnsrVal_g_ovrdval;/* Referenced by: '<S201>/sat4' */
extern CALDATA const volatile float32 KIPM_ESCLongAccSnsrValDflt_g;/* Referenced by: '<S202>/sat5' */
extern CALDATA const volatile float32 KIPM_ESCLongAccSnsrValHi_g;/* Referenced by: '<S202>/sat6' */
extern CALDATA const volatile float32 KIPM_ESCLongAccSnsrValLo_g;/* Referenced by: '<S202>/sat7' */
extern CALDATA const volatile boolean KIPM_ESCLongAccSnsrVal_g_ovrdflg;/* Referenced by: '<S202>/sat3' */
extern CALDATA const volatile float32 KIPM_ESCLongAccSnsrVal_g_ovrdval;/* Referenced by: '<S202>/sat4' */
extern CALDATA const volatile boolean KIPM_ESCLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg10' */
extern CALDATA const volatile boolean KIPM_ESCLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg12' */
extern CALDATA const volatile float32 KIPM_ESCMstrCylPresrDflt_bar;/* Referenced by: '<S203>/sat5' */
extern CALDATA const volatile float32 KIPM_ESCMstrCylPresrHi_bar;/* Referenced by: '<S203>/sat6' */
extern CALDATA const volatile float32 KIPM_ESCMstrCylPresrLo_bar;/* Referenced by: '<S203>/sat7' */
extern CALDATA const volatile boolean KIPM_ESCMstrCylPresr_bar_ovrdflg;/* Referenced by: '<S203>/sat3' */
extern CALDATA const volatile float32 KIPM_ESCMstrCylPresr_bar_ovrdval;/* Referenced by: '<S203>/sat4' */
extern CALDATA const volatile boolean KIPM_ESCReqBrkLghtOnDflt_flg;/* Referenced by: '<S195>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCReqBrkLghtOn_flg_ovrdflg;/* Referenced by: '<S195>/sat3' */
extern CALDATA const volatile boolean KIPM_ESCReqBrkLghtOn_flg_ovrdval;/* Referenced by: '<S195>/sat4' */
extern CALDATA const volatile float32 KIPM_ESCSlopPctDflt_pct;/* Referenced by: '<S196>/sat5' */
extern CALDATA const volatile float32 KIPM_ESCSlopPctHi_pct;/* Referenced by: '<S196>/sat6' */
extern CALDATA const volatile float32 KIPM_ESCSlopPctLo_pct;/* Referenced by: '<S196>/sat7' */
extern CALDATA const volatile boolean KIPM_ESCSlopPct_pct_ovrdflg;/* Referenced by: '<S196>/sat3' */
extern CALDATA const volatile float32 KIPM_ESCSlopPct_pct_ovrdval;/* Referenced by: '<S196>/sat4' */
extern CALDATA const volatile boolean KIPM_ESCTCSActvStaDflt_flg;/* Referenced by: '<S197>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCTCSActvSta_flg_ovrdflg;/* Referenced by: '<S197>/sat3' */
extern CALDATA const volatile boolean KIPM_ESCTCSActvSta_flg_ovrdval;/* Referenced by: '<S197>/sat4' */
extern CALDATA const volatile float32 KIPM_ESCVehSpdDflt_kph;/* Referenced by: '<S198>/sat5' */
extern CALDATA const volatile float32 KIPM_ESCVehSpdHi_kph;/* Referenced by: '<S198>/sat6' */
extern CALDATA const volatile float32 KIPM_ESCVehSpdLo_kph;/* Referenced by: '<S198>/sat7' */
extern CALDATA const volatile boolean KIPM_ESCVehSpd_kph_ovrdflg;/* Referenced by: '<S198>/sat3' */
extern CALDATA const volatile float32 KIPM_ESCVehSpd_kph_ovrdval;/* Referenced by: '<S198>/sat4' */
extern CALDATA const volatile uint8 KIPM_ESCVehStandStillStaDflt_enum;/* Referenced by: '<S204>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCVehStandStillSta_enum_ovrdflg;/* Referenced by: '<S204>/sat3' */
extern CALDATA const volatile uint8 KIPM_ESCVehStandStillSta_enum_ovrdval;/* Referenced by: '<S204>/sat4' */
extern CALDATA const volatile uint8 KIPM_ESCWhlDirctnFLDflt_enum;/* Referenced by: '<S205>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCWhlDirctnFL_enum_ovrdflg;/* Referenced by: '<S205>/sat3' */
extern CALDATA const volatile uint8 KIPM_ESCWhlDirctnFL_enum_ovrdval;/* Referenced by: '<S205>/sat4' */
extern CALDATA const volatile uint8 KIPM_ESCWhlDirctnFRDflt_enum;/* Referenced by: '<S206>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCWhlDirctnFR_enum_ovrdflg;/* Referenced by: '<S206>/sat3' */
extern CALDATA const volatile uint8 KIPM_ESCWhlDirctnFR_enum_ovrdval;/* Referenced by: '<S206>/sat4' */
extern CALDATA const volatile uint8 KIPM_ESCWhlDirctnRLDflt_enum;/* Referenced by: '<S207>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCWhlDirctnRL_enum_ovrdflg;/* Referenced by: '<S207>/sat3' */
extern CALDATA const volatile uint8 KIPM_ESCWhlDirctnRL_enum_ovrdval;/* Referenced by: '<S207>/sat4' */
extern CALDATA const volatile uint8 KIPM_ESCWhlDirctnRRDflt_enum;/* Referenced by: '<S208>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCWhlDirctnRR_enum_ovrdflg;/* Referenced by: '<S208>/sat3' */
extern CALDATA const volatile uint8 KIPM_ESCWhlDirctnRR_enum_ovrdval;/* Referenced by: '<S208>/sat4' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphFLDflt_kph;/* Referenced by: '<S209>/sat5' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphFLHi_kph;/* Referenced by: '<S209>/sat6' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphFLLo_kph;/* Referenced by: '<S209>/sat7' */
extern CALDATA const volatile boolean KIPM_ESCWhlSpdKphFL_kph_ovrdflg;/* Referenced by: '<S209>/sat3' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphFL_kph_ovrdval;/* Referenced by: '<S209>/sat4' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphFRDflt_kph;/* Referenced by: '<S210>/sat5' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphFRHi_kph;/* Referenced by: '<S210>/sat6' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphFRLo_kph;/* Referenced by: '<S210>/sat7' */
extern CALDATA const volatile boolean KIPM_ESCWhlSpdKphFR_kph_ovrdflg;/* Referenced by: '<S210>/sat3' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphFR_kph_ovrdval;/* Referenced by: '<S210>/sat4' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphRLDflt_kph;/* Referenced by: '<S211>/sat5' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphRLHi_kph;/* Referenced by: '<S211>/sat6' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphRLLo_kph;/* Referenced by: '<S211>/sat7' */
extern CALDATA const volatile boolean KIPM_ESCWhlSpdKphRL_kph_ovrdflg;/* Referenced by: '<S211>/sat3' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphRL_kph_ovrdval;/* Referenced by: '<S211>/sat4' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphRRDflt_kph;/* Referenced by: '<S212>/sat5' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphRRHi_kph;/* Referenced by: '<S212>/sat6' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphRRLo_kph;/* Referenced by: '<S212>/sat7' */
extern CALDATA const volatile boolean KIPM_ESCWhlSpdKphRR_kph_ovrdflg;/* Referenced by: '<S212>/sat3' */
extern CALDATA const volatile float32 KIPM_ESCWhlSpdKphRR_kph_ovrdval;/* Referenced by: '<S212>/sat4' */
extern CALDATA const volatile boolean KIPM_ESCWhlTqDecReqActvDflt_flg;/* Referenced by: '<S213>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCWhlTqDecReqActv_flg_ovrdflg;/* Referenced by: '<S213>/sat3' */
extern CALDATA const volatile boolean KIPM_ESCWhlTqDecReqActv_flg_ovrdval;/* Referenced by: '<S213>/sat4' */
extern CALDATA const volatile float32 KIPM_ESCWhlTqDecReqValDflt_Nm;/* Referenced by: '<S214>/sat5' */
extern CALDATA const volatile float32 KIPM_ESCWhlTqDecReqValHi_Nm;/* Referenced by: '<S214>/sat6' */
extern CALDATA const volatile float32 KIPM_ESCWhlTqDecReqValLo_Nm;/* Referenced by: '<S214>/sat7' */
extern CALDATA const volatile boolean KIPM_ESCWhlTqDecReqVal_Nm_ovrdflg;/* Referenced by: '<S214>/sat3' */
extern CALDATA const volatile float32 KIPM_ESCWhlTqDecReqVal_Nm_ovrdval;/* Referenced by: '<S214>/sat4' */
extern CALDATA const volatile boolean KIPM_ESCWhlTqIncReqActvDflt_flg;/* Referenced by: '<S215>/sat5' */
extern CALDATA const volatile boolean KIPM_ESCWhlTqIncReqActv_flg_ovrdflg;/* Referenced by: '<S215>/sat3' */
extern CALDATA const volatile boolean KIPM_ESCWhlTqIncReqActv_flg_ovrdval;/* Referenced by: '<S215>/sat4' */
extern CALDATA const volatile float32 KIPM_ESCWhlTqIncReqValDflt_Nm;/* Referenced by: '<S216>/sat5' */
extern CALDATA const volatile float32 KIPM_ESCWhlTqIncReqValHi_Nm;/* Referenced by: '<S216>/sat6' */
extern CALDATA const volatile float32 KIPM_ESCWhlTqIncReqValLo_Nm;/* Referenced by: '<S216>/sat7' */
extern CALDATA const volatile boolean KIPM_ESCWhlTqIncReqVal_Nm_ovrdflg;/* Referenced by: '<S216>/sat3' */
extern CALDATA const volatile float32 KIPM_ESCWhlTqIncReqVal_Nm_ovrdval;/* Referenced by: '<S216>/sat4' */
extern CALDATA const volatile float32 KIPM_ESCYawRateDflt_degps;/* Referenced by: '<S217>/sat5' */
extern CALDATA const volatile float32 KIPM_ESCYawRateHi_degps;/* Referenced by: '<S217>/sat6' */
extern CALDATA const volatile float32 KIPM_ESCYawRateLo_degps;/* Referenced by: '<S217>/sat7' */
extern CALDATA const volatile boolean KIPM_ESCYawRate_degps_ovrdflg;/* Referenced by: '<S217>/sat3' */
extern CALDATA const volatile float32 KIPM_ESCYawRate_degps_ovrdval;/* Referenced by: '<S217>/sat4' */
extern CALDATA const volatile uint8 KIPM_FCMACCSdnModeDflt_enum;/* Referenced by: '<S276>/sat5' */
extern CALDATA const volatile boolean KIPM_FCMACCSdnMode_enum_ovrdflg;/* Referenced by: '<S276>/sat3' */
extern CALDATA const volatile uint8 KIPM_FCMACCSdnMode_enum_ovrdval;/* Referenced by: '<S276>/sat4' */
extern CALDATA const volatile float32 KIPM_FCMACCWhlDeceDflt_mps2;/* Referenced by: '<S277>/sat5' */
extern CALDATA const volatile float32 KIPM_FCMACCWhlDeceHi_mps2;/* Referenced by: '<S277>/sat6' */
extern CALDATA const volatile float32 KIPM_FCMACCWhlDeceLo_mps2;/* Referenced by: '<S277>/sat7' */
extern CALDATA const volatile boolean KIPM_FCMACCWhlDece_mps2_ovrdflg;/* Referenced by: '<S277>/sat3' */
extern CALDATA const volatile float32 KIPM_FCMACCWhlDece_mps2_ovrdval;/* Referenced by: '<S277>/sat4' */
extern CALDATA const volatile boolean KIPM_FCMACCWhlTqReqActvDflt_flg;/* Referenced by: '<S278>/sat5' */
extern CALDATA const volatile boolean KIPM_FCMACCWhlTqReqActv_flg_ovrdflg;/* Referenced by: '<S278>/sat3' */
extern CALDATA const volatile boolean KIPM_FCMACCWhlTqReqActv_flg_ovrdval;/* Referenced by: '<S278>/sat4' */
extern CALDATA const volatile float32 KIPM_FCMACCWhlTqReqValDflt_Nm;/* Referenced by: '<S279>/sat5' */
extern CALDATA const volatile float32 KIPM_FCMACCWhlTqReqValHi_Nm;/* Referenced by: '<S279>/sat6' */
extern CALDATA const volatile float32 KIPM_FCMACCWhlTqReqValLo_Nm;/* Referenced by: '<S279>/sat7' */
extern CALDATA const volatile boolean KIPM_FCMACCWhlTqReqVal_Nm_ovrdflg;/* Referenced by: '<S279>/sat3' */
extern CALDATA const volatile float32 KIPM_FCMACCWhlTqReqVal_Nm_ovrdval;/* Referenced by: '<S279>/sat4' */
extern CALDATA const volatile boolean KIPM_FCMAEBReqDflt_flg;/* Referenced by: '<S280>/sat5' */
extern CALDATA const volatile boolean KIPM_FCMAEBReq_flg_ovrdflg;/* Referenced by: '<S280>/sat3' */
extern CALDATA const volatile boolean KIPM_FCMAEBReq_flg_ovrdval;/* Referenced by: '<S280>/sat4' */
extern CALDATA const volatile EnumACCMode KIPM_FCMAccModeDflt_enum;/* Referenced by: '<S281>/sat5' */
extern CALDATA const volatile boolean KIPM_FCMAccMode_enum_ovrdflg;/* Referenced by: '<S281>/sat3' */
extern CALDATA const volatile EnumACCMode KIPM_FCMAccMode_enum_ovrdval;/* Referenced by: '<S281>/sat4' */
extern CALDATA const volatile boolean KIPM_FCMAccReqDriveOffDflt_flg;/* Referenced by: '<S282>/sat5' */
extern CALDATA const volatile boolean KIPM_FCMAccReqDriveOff_flg_ovrdflg;/* Referenced by: '<S282>/sat3' */
extern CALDATA const volatile boolean KIPM_FCMAccReqDriveOff_flg_ovrdval;/* Referenced by: '<S282>/sat4' */
extern CALDATA const volatile boolean KIPM_FCMAccReqStandstillDflt_flg;/* Referenced by: '<S283>/sat5' */
extern CALDATA const volatile boolean KIPM_FCMAccReqStandstill_flg_ovrdflg;/* Referenced by: '<S283>/sat3' */
extern CALDATA const volatile boolean KIPM_FCMAccReqStandstill_flg_ovrdval;/* Referenced by: '<S283>/sat4' */
extern CALDATA const volatile float32 KIPM_FCMAccTarAccrnDflt_mps2;/* Referenced by: '<S285>/sat5' */
extern CALDATA const volatile float32 KIPM_FCMAccTarAccrnHi_mps2;/* Referenced by: '<S285>/sat6' */
extern CALDATA const volatile float32 KIPM_FCMAccTarAccrnLo_mps2;/* Referenced by: '<S285>/sat7' */
extern CALDATA const volatile boolean KIPM_FCMAccTarAccrnReqActvDflt_flg;/* Referenced by: '<S284>/sat5' */
extern CALDATA const volatile boolean KIPM_FCMAccTarAccrnReqActv_flg_ovrdflg;/* Referenced by: '<S284>/sat3' */
extern CALDATA const volatile boolean KIPM_FCMAccTarAccrnReqActv_flg_ovrdval;/* Referenced by: '<S284>/sat4' */
extern CALDATA const volatile boolean KIPM_FCMAccTarAccrn_mps2_ovrdflg;/* Referenced by: '<S285>/sat3' */
extern CALDATA const volatile float32 KIPM_FCMAccTarAccrn_mps2_ovrdval;/* Referenced by: '<S285>/sat4' */
extern CALDATA const volatile float32 KIPM_FCMAccTgtAxDflt_mps2;/* Referenced by: '<S287>/sat5' */
extern CALDATA const volatile float32 KIPM_FCMAccTgtAxHi_mps2;/* Referenced by: '<S287>/sat6' */
extern CALDATA const volatile float32 KIPM_FCMAccTgtAxLo_mps2;/* Referenced by: '<S287>/sat7' */
extern CALDATA const volatile boolean KIPM_FCMAccTgtAxReqDflt_flg;/* Referenced by: '<S286>/sat5' */
extern CALDATA const volatile boolean KIPM_FCMAccTgtAxReq_flg_ovrdflg;/* Referenced by: '<S286>/sat3' */
extern CALDATA const volatile boolean KIPM_FCMAccTgtAxReq_flg_ovrdval;/* Referenced by: '<S286>/sat4' */
extern CALDATA const volatile boolean KIPM_FCMAccTgtAx_mps2_ovrdflg;/* Referenced by: '<S287>/sat3' */
extern CALDATA const volatile float32 KIPM_FCMAccTgtAx_mps2_ovrdval;/* Referenced by: '<S287>/sat4' */
extern CALDATA const volatile boolean KIPM_FCMCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst11' */
extern CALDATA const volatile uint8 KIPM_FCMEPBReqDflt_enum;/* Referenced by: '<S288>/sat5' */
extern CALDATA const volatile boolean KIPM_FCMEPBReq_enum_ovrdflg;/* Referenced by: '<S288>/sat3' */
extern CALDATA const volatile uint8 KIPM_FCMEPBReq_enum_ovrdval;/* Referenced by: '<S288>/sat4' */
extern CALDATA const volatile boolean KIPM_FCMLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg13' */
extern CALDATA const volatile boolean KIPM_FCMLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg14' */
extern CALDATA const volatile uint8 KIPM_FCMTrnLampReqDflt_enum;/* Referenced by: '<S289>/sat5' */
extern CALDATA const volatile boolean KIPM_FCMTrnLampReq_enum_ovrdflg;/* Referenced by: '<S289>/sat3' */
extern CALDATA const volatile uint8 KIPM_FCMTrnLampReq_enum_ovrdval;/* Referenced by: '<S289>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUACAutoCtlDflt_enum;/* Referenced by: '<S73>/sat5' */
extern CALDATA const volatile boolean KIPM_HUACAutoCtl_enum_ovrdflg;/* Referenced by: '<S73>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUACAutoCtl_enum_ovrdval;/* Referenced by: '<S73>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUACPwrCtlDflt_enum;/* Referenced by: '<S74>/sat5' */
extern CALDATA const volatile boolean KIPM_HUACPwrCtl_enum_ovrdflg;/* Referenced by: '<S74>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUACPwrCtl_enum_ovrdval;/* Referenced by: '<S74>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUACUnlckVentSetDflt_enum;/* Referenced by: '<S75>/sat5' */
extern CALDATA const volatile boolean KIPM_HUACUnlckVentSet_enum_ovrdflg;/* Referenced by: '<S75>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUACUnlckVentSet_enum_ovrdval;/* Referenced by: '<S75>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUAirInletModeSetDflt_enum;/* Referenced by: '<S76>/sat5' */
extern CALDATA const volatile boolean KIPM_HUAirInletModeSet_enum_ovrdflg;/* Referenced by: '<S76>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUAirInletModeSet_enum_ovrdval;/* Referenced by: '<S76>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUBlwrModeSetDflt_enum;/* Referenced by: '<S77>/sat5' */
extern CALDATA const volatile boolean KIPM_HUBlwrModeSet_enum_ovrdflg;/* Referenced by: '<S77>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUBlwrModeSet_enum_ovrdval;/* Referenced by: '<S77>/sat4' */
extern CALDATA const volatile boolean KIPM_HUCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst' */
extern CALDATA const volatile uint8 KIPM_HUChgWiprMtMdSwSetDflt_enum;/* Referenced by: '<S78>/sat5' */
extern CALDATA const volatile boolean KIPM_HUChgWiprMtMdSwSet_enum_ovrdflg;/* Referenced by: '<S78>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUChgWiprMtMdSwSet_enum_ovrdval;/* Referenced by: '<S78>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUChrgngReqDflt_enum;/* Referenced by: '<S79>/sat5' */
extern CALDATA const volatile boolean KIPM_HUChrgngReq_enum_ovrdflg;/* Referenced by: '<S79>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUChrgngReq_enum_ovrdval;/* Referenced by: '<S79>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUChrgngmodeDflt_enum;/* Referenced by: '<S80>/sat5' */
extern CALDATA const volatile boolean KIPM_HUChrgngmode_enum_ovrdflg;/* Referenced by: '<S80>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUChrgngmode_enum_ovrdval;/* Referenced by: '<S80>/sat4' */
extern CALDATA const volatile EnumRegenModeSelct KIPM_HUCstRecupModeSelDflt_enum;/* Referenced by: '<S81>/sat5' */
extern CALDATA const volatile boolean KIPM_HUCstRecupModeSel_enum_ovrdflg;/* Referenced by: '<S81>/sat3' */
extern CALDATA const volatile EnumRegenModeSelct
  KIPM_HUCstRecupModeSel_enum_ovrdval; /* Referenced by: '<S81>/sat4' */
extern CALDATA const volatile EnumDrvModeSelct KIPM_HUDrvModeSelDflt_enum;/* Referenced by: '<S82>/sat5' */
extern CALDATA const volatile boolean KIPM_HUDrvModeSel_enum_ovrdflg;/* Referenced by: '<S82>/sat3' */
extern CALDATA const volatile EnumDrvModeSelct KIPM_HUDrvModeSel_enum_ovrdval;/* Referenced by: '<S82>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUDrvPwrSetDflt_cnt;/* Referenced by: '<S83>/sat5' */
extern CALDATA const volatile boolean KIPM_HUDrvPwrSet_cnt_ovrdflg;/* Referenced by: '<S83>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUDrvPwrSet_cnt_ovrdval;/* Referenced by: '<S83>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUFlwrMeHmCtrlDflt_enum;/* Referenced by: '<S84>/sat5' */
extern CALDATA const volatile boolean KIPM_HUFlwrMeHmCtrl_enum_ovrdflg;/* Referenced by: '<S84>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUFlwrMeHmCtrl_enum_ovrdval;/* Referenced by: '<S84>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUFrntFanSpdSetDflt_enum;/* Referenced by: '<S85>/sat5' */
extern CALDATA const volatile boolean KIPM_HUFrntFanSpdSet_enum_ovrdflg;/* Referenced by: '<S85>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUFrntFanSpdSet_enum_ovrdval;/* Referenced by: '<S85>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUHybEcoModeSetDflt_enum;/* Referenced by: '<S86>/sat5' */
extern CALDATA const volatile boolean KIPM_HUHybEcoModeSet_enum_ovrdflg;/* Referenced by: '<S86>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUHybEcoModeSet_enum_ovrdval;/* Referenced by: '<S86>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUIllmndEntryStsDflt_enum;/* Referenced by: '<S87>/sat5' */
extern CALDATA const volatile boolean KIPM_HUIllmndEntrySts_enum_ovrdflg;/* Referenced by: '<S87>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUIllmndEntrySts_enum_ovrdval;/* Referenced by: '<S87>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUIllmndLckStsDflt_enum;/* Referenced by: '<S88>/sat5' */
extern CALDATA const volatile boolean KIPM_HUIllmndLckSts_enum_ovrdflg;/* Referenced by: '<S88>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUIllmndLckSts_enum_ovrdval;/* Referenced by: '<S88>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUIllmndUnlckStsDflt_enum;/* Referenced by: '<S89>/sat5' */
extern CALDATA const volatile boolean KIPM_HUIllmndUnlckSts_enum_ovrdflg;/* Referenced by: '<S89>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUIllmndUnlckSts_enum_ovrdval;/* Referenced by: '<S89>/sat4' */
extern CALDATA const volatile uint8 KIPM_HULckHornOnStDflt_enum;/* Referenced by: '<S90>/sat5' */
extern CALDATA const volatile boolean KIPM_HULckHornOnSt_enum_ovrdflg;/* Referenced by: '<S90>/sat3' */
extern CALDATA const volatile uint8 KIPM_HULckHornOnSt_enum_ovrdval;/* Referenced by: '<S90>/sat4' */
extern CALDATA const volatile uint8 KIPM_HULeftTempSetDflt_enum;/* Referenced by: '<S91>/sat5' */
extern CALDATA const volatile boolean KIPM_HULeftTempSet_enum_ovrdflg;/* Referenced by: '<S91>/sat3' */
extern CALDATA const volatile uint8 KIPM_HULeftTempSet_enum_ovrdval;/* Referenced by: '<S91>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUMaiDrvrSeatHeatDflt_enum;/* Referenced by: '<S92>/sat5' */
extern CALDATA const volatile boolean KIPM_HUMaiDrvrSeatHeat_enum_ovrdflg;/* Referenced by: '<S92>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUMaiDrvrSeatHeat_enum_ovrdval;/* Referenced by: '<S92>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUManlDefrstCtlDflt_enum;/* Referenced by: '<S93>/sat5' */
extern CALDATA const volatile boolean KIPM_HUManlDefrstCtl_enum_ovrdflg;/* Referenced by: '<S93>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUManlDefrstCtl_enum_ovrdval;/* Referenced by: '<S93>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUOvrspdCntrlLckSetDflt_enum;/* Referenced by: '<S94>/sat5' */
extern CALDATA const volatile boolean KIPM_HUOvrspdCntrlLckSet_enum_ovrdflg;/* Referenced by: '<S94>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUOvrspdCntrlLckSet_enum_ovrdval;/* Referenced by: '<S94>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUParkAutoUnlckSetDflt_enum;/* Referenced by: '<S95>/sat5' */
extern CALDATA const volatile boolean KIPM_HUParkAutoUnlckSet_enum_ovrdflg;/* Referenced by: '<S95>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUParkAutoUnlckSet_enum_ovrdval;/* Referenced by: '<S95>/sat4' */
extern CALDATA const volatile EnumCrpModeEnbl
  KIPM_HUPeristalsisModeEnblDflt_enum; /* Referenced by: '<S96>/sat5' */
extern CALDATA const volatile boolean KIPM_HUPeristalsisModeEnbl_enum_ovrdflg;/* Referenced by: '<S96>/sat3' */
extern CALDATA const volatile EnumCrpModeEnbl
  KIPM_HUPeristalsisModeEnbl_enum_ovrdval;/* Referenced by: '<S96>/sat4' */
extern CALDATA const volatile boolean KIPM_HUPwrOffReqDflt_flg;/* Referenced by: '<S97>/sat5' */
extern CALDATA const volatile boolean KIPM_HUPwrOffReq_flg_ovrdflg;/* Referenced by: '<S97>/sat3' */
extern CALDATA const volatile boolean KIPM_HUPwrOffReq_flg_ovrdval;/* Referenced by: '<S97>/sat4' */
extern CALDATA const volatile uint8 KIPM_HURecupPwrSetDflt_pct;/* Referenced by: '<S98>/sat5' */
extern CALDATA const volatile boolean KIPM_HURecupPwrSet_pct_ovrdflg;/* Referenced by: '<S98>/sat3' */
extern CALDATA const volatile uint8 KIPM_HURecupPwrSet_pct_ovrdval;/* Referenced by: '<S98>/sat4' */
extern CALDATA const volatile uint8 KIPM_HURrMirrHeatDflt_enum;/* Referenced by: '<S99>/sat5' */
extern CALDATA const volatile boolean KIPM_HURrMirrHeat_enum_ovrdflg;/* Referenced by: '<S99>/sat3' */
extern CALDATA const volatile uint8 KIPM_HURrMirrHeat_enum_ovrdval;/* Referenced by: '<S99>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUSteerWhlHeatDflt_enum;/* Referenced by: '<S100>/sat5' */
extern CALDATA const volatile boolean KIPM_HUSteerWhlHeat_enum_ovrdflg;/* Referenced by: '<S100>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUSteerWhlHeat_enum_ovrdval;/* Referenced by: '<S100>/sat4' */
extern CALDATA const volatile boolean KIPM_HUTPMSRstReqDflt_flg;/* Referenced by: '<S101>/sat5' */
extern CALDATA const volatile boolean KIPM_HUTPMSRstReq_flg_ovrdflg;/* Referenced by: '<S101>/sat3' */
extern CALDATA const volatile boolean KIPM_HUTPMSRstReq_flg_ovrdval;/* Referenced by: '<S101>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUTrnkLckSwCtrlDflt_enum;/* Referenced by: '<S102>/sat5' */
extern CALDATA const volatile boolean KIPM_HUTrnkLckSwCtrl_enum_ovrdflg;/* Referenced by: '<S102>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUTrnkLckSwCtrl_enum_ovrdval;/* Referenced by: '<S102>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUVehMaxCurrDflt_A;/* Referenced by: '<S103>/sat5' */
extern CALDATA const volatile boolean KIPM_HUVehMaxCurr_A_ovrdflg;/* Referenced by: '<S103>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUVehMaxCurr_A_ovrdval;/* Referenced by: '<S103>/sat4' */
extern CALDATA const volatile uint8 KIPM_HUWiprIntlTmSetDflt_enum;/* Referenced by: '<S104>/sat5' */
extern CALDATA const volatile boolean KIPM_HUWiprIntlTmSet_enum_ovrdflg;/* Referenced by: '<S104>/sat3' */
extern CALDATA const volatile uint8 KIPM_HUWiprIntlTmSet_enum_ovrdval;/* Referenced by: '<S104>/sat4' */
extern CALDATA const volatile float32 KIPM_HVCHCurrDflt_A;/* Referenced by: '<S55>/sat5' */
extern CALDATA const volatile float32 KIPM_HVCHCurrHi_A;/* Referenced by: '<S55>/sat6' */
extern CALDATA const volatile float32 KIPM_HVCHCurrLo_A;/* Referenced by: '<S55>/sat7' */
extern CALDATA const volatile boolean KIPM_HVCHCurr_A_ovrdflg;/* Referenced by: '<S55>/sat3' */
extern CALDATA const volatile float32 KIPM_HVCHCurr_A_ovrdval;/* Referenced by: '<S55>/sat4' */
extern CALDATA const volatile uint16 KIPM_HVCHFltCodDflt_enum;/* Referenced by: '<S56>/sat5' */
extern CALDATA const volatile boolean KIPM_HVCHFltCod_enum_ovrdflg;/* Referenced by: '<S56>/sat3' */
extern CALDATA const volatile uint16 KIPM_HVCHFltCod_enum_ovrdval;/* Referenced by: '<S56>/sat4' */
extern CALDATA const volatile boolean KIPM_HVCHHVStDflt_flg;/* Referenced by: '<S46>/sat5' */
extern CALDATA const volatile boolean KIPM_HVCHHVSt_flg_ovrdflg;/* Referenced by: '<S46>/sat3' */
extern CALDATA const volatile boolean KIPM_HVCHHVSt_flg_ovrdval;/* Referenced by: '<S46>/sat4' */
extern CALDATA const volatile float32 KIPM_HVCHHVVoltsDflt_V;/* Referenced by: '<S57>/sat5' */
extern CALDATA const volatile float32 KIPM_HVCHHVVoltsHi_V;/* Referenced by: '<S57>/sat6' */
extern CALDATA const volatile float32 KIPM_HVCHHVVoltsLo_V;/* Referenced by: '<S57>/sat7' */
extern CALDATA const volatile boolean KIPM_HVCHHVVolts_V_ovrdflg;/* Referenced by: '<S57>/sat3' */
extern CALDATA const volatile float32 KIPM_HVCHHVVolts_V_ovrdval;/* Referenced by: '<S57>/sat4' */
extern CALDATA const volatile float32 KIPM_HVCHInletTempDflt_C;/* Referenced by: '<S47>/sat5' */
extern CALDATA const volatile float32 KIPM_HVCHInletTempHi_C;/* Referenced by: '<S47>/sat6' */
extern CALDATA const volatile float32 KIPM_HVCHInletTempLo_C;/* Referenced by: '<S47>/sat7' */
extern CALDATA const volatile boolean KIPM_HVCHInletTemp_C_ovrdflg;/* Referenced by: '<S47>/sat3' */
extern CALDATA const volatile float32 KIPM_HVCHInletTemp_C_ovrdval;/* Referenced by: '<S47>/sat4' */
extern CALDATA const volatile float32 KIPM_HVCHOutlTempDflt_C;/* Referenced by: '<S48>/sat5' */
extern CALDATA const volatile float32 KIPM_HVCHOutlTempHi_C;/* Referenced by: '<S48>/sat6' */
extern CALDATA const volatile float32 KIPM_HVCHOutlTempLo_C;/* Referenced by: '<S48>/sat7' */
extern CALDATA const volatile boolean KIPM_HVCHOutlTemp_C_ovrdflg;/* Referenced by: '<S48>/sat3' */
extern CALDATA const volatile float32 KIPM_HVCHOutlTemp_C_ovrdval;/* Referenced by: '<S48>/sat4' */
extern CALDATA const volatile float32 KIPM_HVCHPCBTempDflt_C;/* Referenced by: '<S49>/sat5' */
extern CALDATA const volatile float32 KIPM_HVCHPCBTempHi_C;/* Referenced by: '<S49>/sat6' */
extern CALDATA const volatile float32 KIPM_HVCHPCBTempLo_C;/* Referenced by: '<S49>/sat7' */
extern CALDATA const volatile boolean KIPM_HVCHPCBTemp_C_ovrdflg;/* Referenced by: '<S49>/sat3' */
extern CALDATA const volatile float32 KIPM_HVCHPCBTemp_C_ovrdval;/* Referenced by: '<S49>/sat4' */
extern CALDATA const volatile float32 KIPM_HVCHPwrDflt_kW;/* Referenced by: '<S58>/sat5' */
extern CALDATA const volatile float32 KIPM_HVCHPwrHi_kW;/* Referenced by: '<S58>/sat6' */
extern CALDATA const volatile float32 KIPM_HVCHPwrLo_kW;/* Referenced by: '<S58>/sat7' */
extern CALDATA const volatile boolean KIPM_HVCHPwr_kW_ovrdflg;/* Referenced by: '<S58>/sat3' */
extern CALDATA const volatile float32 KIPM_HVCHPwr_kW_ovrdval;/* Referenced by: '<S58>/sat4' */
extern CALDATA const volatile uint8 KIPM_HVCHStDflt_enum;/* Referenced by: '<S50>/sat5' */
extern CALDATA const volatile boolean KIPM_HVCHSt_enum_ovrdflg;/* Referenced by: '<S50>/sat3' */
extern CALDATA const volatile uint8 KIPM_HVCHSt_enum_ovrdval;/* Referenced by: '<S50>/sat4' */
extern CALDATA const volatile uint8 KIPM_HVCHWorkModeDflt_enum;/* Referenced by: '<S51>/sat5' */
extern CALDATA const volatile boolean KIPM_HVCHWorkMode_enum_ovrdflg;/* Referenced by: '<S51>/sat3' */
extern CALDATA const volatile uint8 KIPM_HVCHWorkMode_enum_ovrdval;/* Referenced by: '<S51>/sat4' */
extern CALDATA const volatile uint8 KIPM_HVCHWorkStDflt_enum;/* Referenced by: '<S59>/sat5' */
extern CALDATA const volatile boolean KIPM_HVCHWorkSt_enum_ovrdflg;/* Referenced by: '<S59>/sat3' */
extern CALDATA const volatile uint8 KIPM_HVCHWorkSt_enum_ovrdval;/* Referenced by: '<S59>/sat4' */
extern CALDATA const volatile uint8 KIPM_HwVerMaxDflt_enum;/* Referenced by: '<S19>/sat5' */
extern CALDATA const volatile boolean KIPM_HwVerMax_enum_ovrdflg;/* Referenced by: '<S19>/sat3' */
extern CALDATA const volatile uint8 KIPM_HwVerMax_enum_ovrdval;/* Referenced by: '<S19>/sat4' */
extern CALDATA const volatile uint8 KIPM_HwVerMinDflt_enum;/* Referenced by: '<S20>/sat5' */
extern CALDATA const volatile boolean KIPM_HwVerMin_enum_ovrdflg;/* Referenced by: '<S20>/sat3' */
extern CALDATA const volatile uint8 KIPM_HwVerMin_enum_ovrdval;/* Referenced by: '<S20>/sat4' */
extern CALDATA const volatile boolean KIPM_ICUCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst1' */
extern CALDATA const volatile boolean KIPM_ICULostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg23' */
extern CALDATA const volatile boolean KIPM_ICULostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg24' */
extern CALDATA const volatile EnumINVActMd KIPM_INV1ActModeDflt_enum;/* Referenced by: '<S231>/sat5' */
extern CALDATA const volatile boolean KIPM_INV1ActMode_enum_ovrdflg;/* Referenced by: '<S231>/sat3' */
extern CALDATA const volatile EnumINVActMd KIPM_INV1ActMode_enum_ovrdval;/* Referenced by: '<S231>/sat4' */
extern CALDATA const volatile float32 KIPM_INV1ActTorqDflt_Nm;/* Referenced by: '<S232>/sat5' */
extern CALDATA const volatile float32 KIPM_INV1ActTorqHi_Nm;/* Referenced by: '<S232>/sat6' */
extern CALDATA const volatile float32 KIPM_INV1ActTorqLo_Nm;/* Referenced by: '<S232>/sat7' */
extern CALDATA const volatile boolean KIPM_INV1ActTorq_Nm_ovrdflg;/* Referenced by: '<S232>/sat3' */
extern CALDATA const volatile float32 KIPM_INV1ActTorq_Nm_ovrdval;/* Referenced by: '<S232>/sat4' */
extern CALDATA const volatile uint8 KIPM_INV1AntithftAuthRsltDflt_enum;/* Referenced by: '<S233>/sat5' */
extern CALDATA const volatile boolean KIPM_INV1AntithftAuthRslt_enum_ovrdflg;/* Referenced by: '<S233>/sat3' */
extern CALDATA const volatile uint8 KIPM_INV1AntithftAuthRslt_enum_ovrdval;/* Referenced by: '<S233>/sat4' */
extern CALDATA const volatile float32 KIPM_INV1MotSpdDflt_rpm;/* Referenced by: '<S234>/sat5' */
extern CALDATA const volatile float32 KIPM_INV1MotSpdHi_rpm;/* Referenced by: '<S234>/sat6' */
extern CALDATA const volatile float32 KIPM_INV1MotSpdLo_rpm;/* Referenced by: '<S234>/sat7' */
extern CALDATA const volatile boolean KIPM_INV1MotSpd_rpm_ovrdflg;/* Referenced by: '<S234>/sat3' */
extern CALDATA const volatile float32 KIPM_INV1MotSpd_rpm_ovrdval;/* Referenced by: '<S234>/sat4' */
extern CALDATA const volatile uint8 KIPM_INV1PreChrgAllwdDflt_enum;/* Referenced by: '<S235>/sat5' */
extern CALDATA const volatile boolean KIPM_INV1PreChrgAllwd_enum_ovrdflg;/* Referenced by: '<S235>/sat3' */
extern CALDATA const volatile uint8 KIPM_INV1PreChrgAllwd_enum_ovrdval;/* Referenced by: '<S235>/sat4' */
extern CALDATA const volatile boolean KIPM_INV1PreprogmFlgDflt_flg;/* Referenced by: '<S236>/sat5' */
extern CALDATA const volatile boolean KIPM_INV1PreprogmFlg_flg_ovrdflg;/* Referenced by: '<S236>/sat3' */
extern CALDATA const volatile boolean KIPM_INV1PreprogmFlg_flg_ovrdval;/* Referenced by: '<S236>/sat4' */
extern CALDATA const volatile uint8 KIPM_INV1ShutdownAllwdDflt_enum;/* Referenced by: '<S237>/sat5' */
extern CALDATA const volatile boolean KIPM_INV1ShutdownAllwd_enum_ovrdflg;/* Referenced by: '<S237>/sat3' */
extern CALDATA const volatile uint8 KIPM_INV1ShutdownAllwd_enum_ovrdval;/* Referenced by: '<S237>/sat4' */
extern CALDATA const volatile float32 KIPM_INV2IgbtMaxTempDflt_C;/* Referenced by: '<S240>/sat5' */
extern CALDATA const volatile float32 KIPM_INV2IgbtMaxTempHi_C;/* Referenced by: '<S240>/sat6' */
extern CALDATA const volatile float32 KIPM_INV2IgbtMaxTempLo_C;/* Referenced by: '<S240>/sat7' */
extern CALDATA const volatile boolean KIPM_INV2IgbtMaxTemp_C_ovrdflg;/* Referenced by: '<S240>/sat3' */
extern CALDATA const volatile float32 KIPM_INV2IgbtMaxTemp_C_ovrdval;/* Referenced by: '<S240>/sat4' */
extern CALDATA const volatile float32 KIPM_INV2InpCurntDflt_A;/* Referenced by: '<S241>/sat5' */
extern CALDATA const volatile float32 KIPM_INV2InpCurntHi_A;/* Referenced by: '<S241>/sat6' */
extern CALDATA const volatile float32 KIPM_INV2InpCurntLo_A;/* Referenced by: '<S241>/sat7' */
extern CALDATA const volatile boolean KIPM_INV2InpCurnt_A_ovrdflg;/* Referenced by: '<S241>/sat3' */
extern CALDATA const volatile float32 KIPM_INV2InpCurnt_A_ovrdval;/* Referenced by: '<S241>/sat4' */
extern CALDATA const volatile float32 KIPM_INV2InpVoltDflt_V;/* Referenced by: '<S242>/sat5' */
extern CALDATA const volatile float32 KIPM_INV2InpVoltHi_V;/* Referenced by: '<S242>/sat6' */
extern CALDATA const volatile float32 KIPM_INV2InpVoltLo_V;/* Referenced by: '<S242>/sat7' */
extern CALDATA const volatile boolean KIPM_INV2InpVolt_V_ovrdflg;/* Referenced by: '<S242>/sat3' */
extern CALDATA const volatile float32 KIPM_INV2InpVolt_V_ovrdval;/* Referenced by: '<S242>/sat4' */
extern CALDATA const volatile float32 KIPM_INV2MotorMaxTempDflt_C;/* Referenced by: '<S243>/sat5' */
extern CALDATA const volatile float32 KIPM_INV2MotorMaxTempHi_C;/* Referenced by: '<S243>/sat6' */
extern CALDATA const volatile float32 KIPM_INV2MotorMaxTempLo_C;/* Referenced by: '<S243>/sat7' */
extern CALDATA const volatile boolean KIPM_INV2MotorMaxTemp_C_ovrdflg;/* Referenced by: '<S243>/sat3' */
extern CALDATA const volatile float32 KIPM_INV2MotorMaxTemp_C_ovrdval;/* Referenced by: '<S243>/sat4' */
extern CALDATA const volatile float32 KIPM_INV3DrvTqAllwdMaxDflt_Nm;/* Referenced by: '<S247>/sat5' */
extern CALDATA const volatile float32 KIPM_INV3DrvTqAllwdMaxHi_Nm;/* Referenced by: '<S247>/sat6' */
extern CALDATA const volatile float32 KIPM_INV3DrvTqAllwdMaxLo_Nm;/* Referenced by: '<S247>/sat7' */
extern CALDATA const volatile boolean KIPM_INV3DrvTqAllwdMax_Nm_ovrdflg;/* Referenced by: '<S247>/sat3' */
extern CALDATA const volatile float32 KIPM_INV3DrvTqAllwdMax_Nm_ovrdval;/* Referenced by: '<S247>/sat4' */
extern CALDATA const volatile float32 KIPM_INV3RecupTqAllwdMaxDflt_Nm;/* Referenced by: '<S248>/sat5' */
extern CALDATA const volatile float32 KIPM_INV3RecupTqAllwdMaxHi_Nm;/* Referenced by: '<S248>/sat6' */
extern CALDATA const volatile float32 KIPM_INV3RecupTqAllwdMaxLo_Nm;/* Referenced by: '<S248>/sat7' */
extern CALDATA const volatile boolean KIPM_INV3RecupTqAllwdMax_Nm_ovrdflg;/* Referenced by: '<S248>/sat3' */
extern CALDATA const volatile float32 KIPM_INV3RecupTqAllwdMax_Nm_ovrdval;/* Referenced by: '<S248>/sat4' */
extern CALDATA const volatile uint8 KIPM_INV4FltLvlDflt_enum;/* Referenced by: '<S251>/sat5' */
extern CALDATA const volatile boolean KIPM_INV4FltLvl_enum_ovrdflg;/* Referenced by: '<S251>/sat3' */
extern CALDATA const volatile uint8 KIPM_INV4FltLvl_enum_ovrdval;/* Referenced by: '<S251>/sat4' */
extern CALDATA const volatile boolean KIPM_INVCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst15' */
extern CALDATA const volatile uint8 KIPM_INVLrngData02Dflt_nu;/* Referenced by: '<S127>/sat5' */
extern CALDATA const volatile boolean KIPM_INVLrngData02_nu_ovrdflg;/* Referenced by: '<S127>/sat3' */
extern CALDATA const volatile uint8 KIPM_INVLrngData02_nu_ovrdval;/* Referenced by: '<S127>/sat4' */
extern CALDATA const volatile uint8 KIPM_INVLrngData03Dflt_nu;/* Referenced by: '<S128>/sat5' */
extern CALDATA const volatile boolean KIPM_INVLrngData03_nu_ovrdflg;/* Referenced by: '<S128>/sat3' */
extern CALDATA const volatile uint8 KIPM_INVLrngData03_nu_ovrdval;/* Referenced by: '<S128>/sat4' */
extern CALDATA const volatile uint8 KIPM_INVLrngData04Dflt_nu;/* Referenced by: '<S129>/sat5' */
extern CALDATA const volatile boolean KIPM_INVLrngData04_nu_ovrdflg;/* Referenced by: '<S129>/sat3' */
extern CALDATA const volatile uint8 KIPM_INVLrngData04_nu_ovrdval;/* Referenced by: '<S129>/sat4' */
extern CALDATA const volatile uint8 KIPM_INVLrngData05Dflt_nu;/* Referenced by: '<S130>/sat5' */
extern CALDATA const volatile boolean KIPM_INVLrngData05_nu_ovrdflg;/* Referenced by: '<S130>/sat3' */
extern CALDATA const volatile uint8 KIPM_INVLrngData05_nu_ovrdval;/* Referenced by: '<S130>/sat4' */
extern CALDATA const volatile uint8 KIPM_INVLrngData06Dflt_nu;/* Referenced by: '<S131>/sat5' */
extern CALDATA const volatile boolean KIPM_INVLrngData06_nu_ovrdflg;/* Referenced by: '<S131>/sat3' */
extern CALDATA const volatile uint8 KIPM_INVLrngData06_nu_ovrdval;/* Referenced by: '<S131>/sat4' */
extern CALDATA const volatile uint8 KIPM_INVLrngData07Dflt_nu;/* Referenced by: '<S132>/sat5' */
extern CALDATA const volatile boolean KIPM_INVLrngData07_nu_ovrdflg;/* Referenced by: '<S132>/sat3' */
extern CALDATA const volatile uint8 KIPM_INVLrngData07_nu_ovrdval;/* Referenced by: '<S132>/sat4' */
extern CALDATA const volatile uint8 KIPM_INVLrngStsDflt_enum;/* Referenced by: '<S133>/sat5' */
extern CALDATA const volatile boolean KIPM_INVLrngSts_enum_ovrdflg;/* Referenced by: '<S133>/sat3' */
extern CALDATA const volatile uint8 KIPM_INVLrngSts_enum_ovrdval;/* Referenced by: '<S133>/sat4' */
extern CALDATA const volatile uint8 KIPM_INVLrngSubIDDflt_cnt;/* Referenced by: '<S134>/sat5' */
extern CALDATA const volatile boolean KIPM_INVLrngSubID_cnt_ovrdflg;/* Referenced by: '<S134>/sat3' */
extern CALDATA const volatile uint8 KIPM_INVLrngSubID_cnt_ovrdval;/* Referenced by: '<S134>/sat4' */
extern CALDATA const volatile boolean KIPM_IPUCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst16' */
extern CALDATA const volatile EnumDCCActMd KIPM_IPUDCCActOprtModeDflt_enum;/* Referenced by: '<S135>/sat5' */
extern CALDATA const volatile boolean KIPM_IPUDCCActOprtMode_enum_ovrdflg;/* Referenced by: '<S135>/sat3' */
extern CALDATA const volatile EnumDCCActMd KIPM_IPUDCCActOprtMode_enum_ovrdval;/* Referenced by: '<S135>/sat4' */
extern CALDATA const volatile float32 KIPM_IPUDCCHiVoltActCurntDflt_A;/* Referenced by: '<S142>/sat5' */
extern CALDATA const volatile float32 KIPM_IPUDCCHiVoltActCurntHi_A;/* Referenced by: '<S142>/sat6' */
extern CALDATA const volatile float32 KIPM_IPUDCCHiVoltActCurntLo_A;/* Referenced by: '<S142>/sat7' */
extern CALDATA const volatile boolean KIPM_IPUDCCHiVoltActCurnt_A_ovrdflg;/* Referenced by: '<S142>/sat3' */
extern CALDATA const volatile float32 KIPM_IPUDCCHiVoltActCurnt_A_ovrdval;/* Referenced by: '<S142>/sat4' */
extern CALDATA const volatile float32 KIPM_IPUDCCHiVoltActVoltDflt_V;/* Referenced by: '<S143>/sat5' */
extern CALDATA const volatile float32 KIPM_IPUDCCHiVoltActVoltHi_V;/* Referenced by: '<S143>/sat6' */
extern CALDATA const volatile float32 KIPM_IPUDCCHiVoltActVoltLo_V;/* Referenced by: '<S143>/sat7' */
extern CALDATA const volatile boolean KIPM_IPUDCCHiVoltActVolt_V_ovrdflg;/* Referenced by: '<S143>/sat3' */
extern CALDATA const volatile float32 KIPM_IPUDCCHiVoltActVolt_V_ovrdval;/* Referenced by: '<S143>/sat4' */
extern CALDATA const volatile float32 KIPM_IPUDCCLoVoltActCurntDflt_A;/* Referenced by: '<S136>/sat5' */
extern CALDATA const volatile float32 KIPM_IPUDCCLoVoltActCurntHi_A;/* Referenced by: '<S136>/sat6' */
extern CALDATA const volatile float32 KIPM_IPUDCCLoVoltActCurntLo_A;/* Referenced by: '<S136>/sat7' */
extern CALDATA const volatile boolean KIPM_IPUDCCLoVoltActCurnt_A_ovrdflg;/* Referenced by: '<S136>/sat3' */
extern CALDATA const volatile float32 KIPM_IPUDCCLoVoltActCurnt_A_ovrdval;/* Referenced by: '<S136>/sat4' */
extern CALDATA const volatile float32 KIPM_IPUDCCLoVoltActVoltDflt_V;/* Referenced by: '<S137>/sat5' */
extern CALDATA const volatile float32 KIPM_IPUDCCLoVoltActVoltHi_V;/* Referenced by: '<S137>/sat6' */
extern CALDATA const volatile float32 KIPM_IPUDCCLoVoltActVoltLo_V;/* Referenced by: '<S137>/sat7' */
extern CALDATA const volatile boolean KIPM_IPUDCCLoVoltActVolt_V_ovrdflg;/* Referenced by: '<S137>/sat3' */
extern CALDATA const volatile float32 KIPM_IPUDCCLoVoltActVolt_V_ovrdval;/* Referenced by: '<S137>/sat4' */
extern CALDATA const volatile uint8 KIPM_IPUDCCSysFailStaDflt_enum;/* Referenced by: '<S138>/sat5' */
extern CALDATA const volatile boolean KIPM_IPUDCCSysFailSta_enum_ovrdflg;/* Referenced by: '<S138>/sat3' */
extern CALDATA const volatile uint8 KIPM_IPUDCCSysFailSta_enum_ovrdval;/* Referenced by: '<S138>/sat4' */
extern CALDATA const volatile float32 KIPM_IPUDeviceIntTempDflt_C;/* Referenced by: '<S157>/sat5' */
extern CALDATA const volatile float32 KIPM_IPUDeviceIntTempHi_C;/* Referenced by: '<S157>/sat6' */
extern CALDATA const volatile float32 KIPM_IPUDeviceIntTempLo_C;/* Referenced by: '<S157>/sat7' */
extern CALDATA const volatile boolean KIPM_IPUDeviceIntTemp_C_ovrdflg;/* Referenced by: '<S157>/sat3' */
extern CALDATA const volatile float32 KIPM_IPUDeviceIntTemp_C_ovrdval;/* Referenced by: '<S157>/sat4' */
extern CALDATA const volatile boolean KIPM_IPUHVILFailStDflt_flg;/* Referenced by: '<S139>/sat5' */
extern CALDATA const volatile boolean KIPM_IPUHVILFailSt_flg_ovrdflg;/* Referenced by: '<S139>/sat3' */
extern CALDATA const volatile boolean KIPM_IPUHVILFailSt_flg_ovrdval;/* Referenced by: '<S139>/sat4' */
extern CALDATA const volatile boolean KIPM_IPULostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg35' */
extern CALDATA const volatile boolean KIPM_IPULostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg36' */
extern CALDATA const volatile float32 KIPM_IPUOBCACMaxPwrAllowDflt_kW;/* Referenced by: '<S158>/sat5' */
extern CALDATA const volatile float32 KIPM_IPUOBCACMaxPwrAllowHi_kW;/* Referenced by: '<S158>/sat6' */
extern CALDATA const volatile float32 KIPM_IPUOBCACMaxPwrAllowLo_kW;/* Referenced by: '<S158>/sat7' */
extern CALDATA const volatile boolean KIPM_IPUOBCACMaxPwrAllow_kW_ovrdflg;/* Referenced by: '<S158>/sat3' */
extern CALDATA const volatile float32 KIPM_IPUOBCACMaxPwrAllow_kW_ovrdval;/* Referenced by: '<S158>/sat4' */
extern CALDATA const volatile EnumOBCActMd KIPM_IPUOBCActOprtModeDflt_enum;/* Referenced by: '<S146>/sat5' */
extern CALDATA const volatile boolean KIPM_IPUOBCActOprtMode_enum_ovrdflg;/* Referenced by: '<S146>/sat3' */
extern CALDATA const volatile EnumOBCActMd KIPM_IPUOBCActOprtMode_enum_ovrdval;/* Referenced by: '<S146>/sat4' */
extern CALDATA const volatile boolean KIPM_IPUOBCConnectMainStaDflt_flg;/* Referenced by: '<S147>/sat5' */
extern CALDATA const volatile boolean KIPM_IPUOBCConnectMainSta_flg_ovrdflg;/* Referenced by: '<S147>/sat3' */
extern CALDATA const volatile boolean KIPM_IPUOBCConnectMainSta_flg_ovrdval;/* Referenced by: '<S147>/sat4' */
extern CALDATA const volatile float32 KIPM_IPUOBCHVDCActCurDflt_A;/* Referenced by: '<S148>/sat5' */
extern CALDATA const volatile float32 KIPM_IPUOBCHVDCActCurHi_A;/* Referenced by: '<S148>/sat6' */
extern CALDATA const volatile float32 KIPM_IPUOBCHVDCActCurLo_A;/* Referenced by: '<S148>/sat7' */
extern CALDATA const volatile boolean KIPM_IPUOBCHVDCActCur_A_ovrdflg;/* Referenced by: '<S148>/sat3' */
extern CALDATA const volatile float32 KIPM_IPUOBCHVDCActCur_A_ovrdval;/* Referenced by: '<S148>/sat4' */
extern CALDATA const volatile float32 KIPM_IPUOBCHVDCActVolDflt_V;/* Referenced by: '<S149>/sat5' */
extern CALDATA const volatile float32 KIPM_IPUOBCHVDCActVolHi_V;/* Referenced by: '<S149>/sat6' */
extern CALDATA const volatile float32 KIPM_IPUOBCHVDCActVolLo_V;/* Referenced by: '<S149>/sat7' */
extern CALDATA const volatile boolean KIPM_IPUOBCHVDCActVol_V_ovrdflg;/* Referenced by: '<S149>/sat3' */
extern CALDATA const volatile float32 KIPM_IPUOBCHVDCActVol_V_ovrdval;/* Referenced by: '<S149>/sat4' */
extern CALDATA const volatile float32 KIPM_IPUOBCInletActPwrDflt_kW;/* Referenced by: '<S150>/sat5' */
extern CALDATA const volatile float32 KIPM_IPUOBCInletActPwrHi_kW;/* Referenced by: '<S150>/sat6' */
extern CALDATA const volatile float32 KIPM_IPUOBCInletActPwrLo_kW;/* Referenced by: '<S150>/sat7' */
extern CALDATA const volatile boolean KIPM_IPUOBCInletActPwr_kW_ovrdflg;/* Referenced by: '<S150>/sat3' */
extern CALDATA const volatile float32 KIPM_IPUOBCInletActPwr_kW_ovrdval;/* Referenced by: '<S150>/sat4' */
extern CALDATA const volatile EnumOBCPlugSt KIPM_IPUOBCInletConnectStaDflt_enum;/* Referenced by: '<S151>/sat5' */
extern CALDATA const volatile boolean KIPM_IPUOBCInletConnectSta_enum_ovrdflg;/* Referenced by: '<S151>/sat3' */
extern CALDATA const volatile EnumOBCPlugSt
  KIPM_IPUOBCInletConnectSta_enum_ovrdval;/* Referenced by: '<S151>/sat4' */
extern CALDATA const volatile EnumOBCReq KIPM_IPUOBCReqDflt_enum;/* Referenced by: '<S152>/sat5' */
extern CALDATA const volatile boolean KIPM_IPUOBCReq_enum_ovrdflg;/* Referenced by: '<S152>/sat3' */
extern CALDATA const volatile EnumOBCReq KIPM_IPUOBCReq_enum_ovrdval;/* Referenced by: '<S152>/sat4' */
extern CALDATA const volatile boolean KIPM_IPUOBCS2StateDflt_flg;/* Referenced by: '<S159>/sat5' */
extern CALDATA const volatile boolean KIPM_IPUOBCS2State_flg_ovrdflg;/* Referenced by: '<S159>/sat3' */
extern CALDATA const volatile boolean KIPM_IPUOBCS2State_flg_ovrdval;/* Referenced by: '<S159>/sat4' */
extern CALDATA const volatile uint8 KIPM_IPUOBCSysFailStaDflt_enum;/* Referenced by: '<S153>/sat5' */
extern CALDATA const volatile boolean KIPM_IPUOBCSysFailSta_enum_ovrdflg;/* Referenced by: '<S153>/sat3' */
extern CALDATA const volatile uint8 KIPM_IPUOBCSysFailSta_enum_ovrdval;/* Referenced by: '<S153>/sat4' */
extern CALDATA const volatile float32 KIPM_IPUOBCTempIntDflt_C;/* Referenced by: '<S160>/sat5' */
extern CALDATA const volatile float32 KIPM_IPUOBCTempIntHi_C;/* Referenced by: '<S160>/sat6' */
extern CALDATA const volatile float32 KIPM_IPUOBCTempIntLo_C;/* Referenced by: '<S160>/sat7' */
extern CALDATA const volatile boolean KIPM_IPUOBCTempInt_C_ovrdflg;/* Referenced by: '<S160>/sat3' */
extern CALDATA const volatile float32 KIPM_IPUOBCTempInt_C_ovrdval;/* Referenced by: '<S160>/sat4' */
extern CALDATA const volatile EnumOBCWakeUpMd KIPM_IPUOBCWakeUpModeDflt_enum;/* Referenced by: '<S161>/sat5' */
extern CALDATA const volatile boolean KIPM_IPUOBCWakeUpMode_enum_ovrdflg;/* Referenced by: '<S161>/sat3' */
extern CALDATA const volatile EnumOBCWakeUpMd KIPM_IPUOBCWakeUpMode_enum_ovrdval;/* Referenced by: '<S161>/sat4' */
extern CALDATA const volatile boolean KIPM_MCULostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg27' */
extern CALDATA const volatile boolean KIPM_MCULostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg28' */
extern CALDATA const volatile boolean KIPM_PPCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst12' */
extern CALDATA const volatile boolean KIPM_PPLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg17' */
extern CALDATA const volatile boolean KIPM_PPLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg18' */
extern CALDATA const volatile boolean KIPM_PTCCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst5' */
extern CALDATA const volatile boolean KIPM_PTCLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg31' */
extern CALDATA const volatile boolean KIPM_PTCLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg32' */
extern CALDATA const volatile boolean KIPM_SCSCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst6' */
extern CALDATA const volatile uint8 KIPM_SCSFrntWiprSwtStDflt_enum;/* Referenced by: '<S368>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSFrntWiprSwtSt_enum_ovrdflg;/* Referenced by: '<S368>/sat3' */
extern CALDATA const volatile uint8 KIPM_SCSFrntWiprSwtSt_enum_ovrdval;/* Referenced by: '<S368>/sat4' */
extern CALDATA const volatile boolean KIPM_SCSFrntWshrSwtStDflt_flg;/* Referenced by: '<S369>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSFrntWshrSwtSt_flg_ovrdflg;/* Referenced by: '<S369>/sat3' */
extern CALDATA const volatile boolean KIPM_SCSFrntWshrSwtSt_flg_ovrdval;/* Referenced by: '<S369>/sat4' */
extern CALDATA const volatile EnumGrShftLvrPstnReq
  KIPM_SCSGrShftLvrPstnReqDflt_enum;   /* Referenced by: '<S256>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSGrShftLvrPstnReq_enum_ovrdflg;/* Referenced by: '<S256>/sat3' */
extern CALDATA const volatile EnumGrShftLvrPstnReq
  KIPM_SCSGrShftLvrPstnReq_enum_ovrdval;/* Referenced by: '<S256>/sat4' */
extern CALDATA const volatile boolean KIPM_SCSHiBeamSwStDflt_flg;/* Referenced by: '<S370>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSHiBeamSwSt_flg_ovrdflg;/* Referenced by: '<S370>/sat3' */
extern CALDATA const volatile boolean KIPM_SCSHiBeamSwSt_flg_ovrdval;/* Referenced by: '<S370>/sat4' */
extern CALDATA const volatile boolean KIPM_SCSLampAutoStDflt_flg;/* Referenced by: '<S371>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSLampAutoSt_flg_ovrdflg;/* Referenced by: '<S371>/sat3' */
extern CALDATA const volatile boolean KIPM_SCSLampAutoSt_flg_ovrdval;/* Referenced by: '<S371>/sat4' */
extern CALDATA const volatile boolean KIPM_SCSLeTrnLmpSwStDflt_flg;/* Referenced by: '<S372>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSLeTrnLmpSwSt_flg_ovrdflg;/* Referenced by: '<S372>/sat3' */
extern CALDATA const volatile boolean KIPM_SCSLeTrnLmpSwSt_flg_ovrdval;/* Referenced by: '<S372>/sat4' */
extern CALDATA const volatile boolean KIPM_SCSLoBeamSwStDflt_flg;/* Referenced by: '<S373>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSLoBeamSwSt_flg_ovrdflg;/* Referenced by: '<S373>/sat3' */
extern CALDATA const volatile boolean KIPM_SCSLoBeamSwSt_flg_ovrdval;/* Referenced by: '<S373>/sat4' */
extern CALDATA const volatile boolean KIPM_SCSLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg39' */
extern CALDATA const volatile boolean KIPM_SCSLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg40' */
extern CALDATA const volatile boolean KIPM_SCSOvrVehBeamSwStDflt_flg;/* Referenced by: '<S374>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSOvrVehBeamSwSt_flg_ovrdflg;/* Referenced by: '<S374>/sat3' */
extern CALDATA const volatile boolean KIPM_SCSOvrVehBeamSwSt_flg_ovrdval;/* Referenced by: '<S374>/sat4' */
extern CALDATA const volatile boolean KIPM_SCSPstnLghtSwStDflt_flg;/* Referenced by: '<S375>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSPstnLghtSwSt_flg_ovrdflg;/* Referenced by: '<S375>/sat3' */
extern CALDATA const volatile boolean KIPM_SCSPstnLghtSwSt_flg_ovrdval;/* Referenced by: '<S375>/sat4' */
extern CALDATA const volatile boolean KIPM_SCSRght11SwDflt_flg;/* Referenced by: '<S257>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSRght11Sw_flg_ovrdflg;/* Referenced by: '<S257>/sat3' */
extern CALDATA const volatile boolean KIPM_SCSRght11Sw_flg_ovrdval;/* Referenced by: '<S257>/sat4' */
extern CALDATA const volatile boolean KIPM_SCSRght12SwDflt_flg;/* Referenced by: '<S258>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSRght12Sw_flg_ovrdflg;/* Referenced by: '<S258>/sat3' */
extern CALDATA const volatile boolean KIPM_SCSRght12Sw_flg_ovrdval;/* Referenced by: '<S258>/sat4' */
extern CALDATA const volatile boolean KIPM_SCSRght13SwDflt_flg;/* Referenced by: '<S259>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSRght13Sw_flg_ovrdflg;/* Referenced by: '<S259>/sat3' */
extern CALDATA const volatile boolean KIPM_SCSRght13Sw_flg_ovrdval;/* Referenced by: '<S259>/sat4' */
extern CALDATA const volatile boolean KIPM_SCSRghtSwVldtyDflt_flg;/* Referenced by: '<S260>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSRghtSwVldty_flg_ovrdflg;/* Referenced by: '<S260>/sat3' */
extern CALDATA const volatile boolean KIPM_SCSRghtSwVldty_flg_ovrdval;/* Referenced by: '<S260>/sat4' */
extern CALDATA const volatile boolean KIPM_SCSRiTrnLmpSwStDflt_flg;/* Referenced by: '<S376>/sat5' */
extern CALDATA const volatile boolean KIPM_SCSRiTrnLmpSwSt_flg_ovrdflg;/* Referenced by: '<S376>/sat3' */
extern CALDATA const volatile boolean KIPM_SCSRiTrnLmpSwSt_flg_ovrdval;/* Referenced by: '<S376>/sat4' */
extern CALDATA const volatile boolean KIPM_SRSCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst13' */
extern CALDATA const volatile uint8 KIPM_SRSCrashOutputStsDflt_enum;/* Referenced by: '<S378>/sat5' */
extern CALDATA const volatile boolean KIPM_SRSCrashOutputSts_enum_ovrdflg;/* Referenced by: '<S378>/sat3' */
extern CALDATA const volatile uint8 KIPM_SRSCrashOutputSts_enum_ovrdval;/* Referenced by: '<S378>/sat4' */
extern CALDATA const volatile boolean KIPM_SRSDrvSeatbeltBkldDflt_flg;/* Referenced by: '<S379>/sat5' */
extern CALDATA const volatile boolean KIPM_SRSDrvSeatbeltBkld_flg_ovrdflg;/* Referenced by: '<S379>/sat3' */
extern CALDATA const volatile boolean KIPM_SRSDrvSeatbeltBkld_flg_ovrdval;/* Referenced by: '<S379>/sat4' */
extern CALDATA const volatile boolean KIPM_SRSLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg21' */
extern CALDATA const volatile boolean KIPM_SRSLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg22' */
extern CALDATA const volatile uint8 KIPM_TBOXACRemtCtrlFlgDflt_enum;/* Referenced by: '<S105>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXACRemtCtrlFlg_enum_ovrdflg;/* Referenced by: '<S105>/sat3' */
extern CALDATA const volatile uint8 KIPM_TBOXACRemtCtrlFlg_enum_ovrdval;/* Referenced by: '<S105>/sat4' */
extern CALDATA const volatile uint8 KIPM_TBOXACTempSetDflt_enum;/* Referenced by: '<S106>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXACTempSet_enum_ovrdflg;/* Referenced by: '<S106>/sat3' */
extern CALDATA const volatile uint8 KIPM_TBOXACTempSet_enum_ovrdval;/* Referenced by: '<S106>/sat4' */
extern CALDATA const volatile uint8 KIPM_TBOXBJSTimeDayDflt_nu;/* Referenced by: '<S64>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXBJSTimeDay_nu_ovrdflg;/* Referenced by: '<S64>/sat3' */
extern CALDATA const volatile uint8 KIPM_TBOXBJSTimeDay_nu_ovrdval;/* Referenced by: '<S64>/sat4' */
extern CALDATA const volatile uint8 KIPM_TBOXBJSTimeHourDflt_nu;/* Referenced by: '<S65>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXBJSTimeHour_nu_ovrdflg;/* Referenced by: '<S65>/sat3' */
extern CALDATA const volatile uint8 KIPM_TBOXBJSTimeHour_nu_ovrdval;/* Referenced by: '<S65>/sat4' */
extern CALDATA const volatile uint8 KIPM_TBOXBJSTimeMinDflt_nu;/* Referenced by: '<S66>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXBJSTimeMin_nu_ovrdflg;/* Referenced by: '<S66>/sat3' */
extern CALDATA const volatile uint8 KIPM_TBOXBJSTimeMin_nu_ovrdval;/* Referenced by: '<S66>/sat4' */
extern CALDATA const volatile uint8 KIPM_TBOXBJSTimeMonthDflt_nu;/* Referenced by: '<S67>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXBJSTimeMonth_nu_ovrdflg;/* Referenced by: '<S67>/sat3' */
extern CALDATA const volatile uint8 KIPM_TBOXBJSTimeMonth_nu_ovrdval;/* Referenced by: '<S67>/sat4' */
extern CALDATA const volatile uint8 KIPM_TBOXBJSTimeSecDflt_nu;/* Referenced by: '<S68>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXBJSTimeSec_nu_ovrdflg;/* Referenced by: '<S68>/sat3' */
extern CALDATA const volatile uint8 KIPM_TBOXBJSTimeSec_nu_ovrdval;/* Referenced by: '<S68>/sat4' */
extern CALDATA const volatile uint16 KIPM_TBOXBJSTimeYearDflt_nu;/* Referenced by: '<S69>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXBJSTimeYear_nu_ovrdflg;/* Referenced by: '<S69>/sat3' */
extern CALDATA const volatile uint16 KIPM_TBOXBJSTimeYear_nu_ovrdval;/* Referenced by: '<S69>/sat4' */
extern CALDATA const volatile boolean KIPM_TBOXCRCChkEnbl_flg;/* Referenced by: '<S380>/Cnst2' */
extern CALDATA const volatile boolean KIPM_TBOXLostCommOvrdSw_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg25' */
extern CALDATA const volatile boolean KIPM_TBOXLostCommOvrdVal_flg;
                         /* Referenced by: '<S381>/KIPC_LimpHomeOvrdSw_flg26' */
extern CALDATA const volatile uint8 KIPM_TBOXRmtPwrLckDflt_enum;/* Referenced by: '<S107>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXRmtPwrLck_enum_ovrdflg;/* Referenced by: '<S107>/sat3' */
extern CALDATA const volatile uint8 KIPM_TBOXRmtPwrLck_enum_ovrdval;/* Referenced by: '<S107>/sat4' */
extern CALDATA const volatile uint8 KIPM_TBOXVCUCCMSpdLimLvlDflt_enum;/* Referenced by: '<S108>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXVCUCCMSpdLimLvl_enum_ovrdflg;/* Referenced by: '<S108>/sat3' */
extern CALDATA const volatile uint8 KIPM_TBOXVCUCCMSpdLimLvl_enum_ovrdval;/* Referenced by: '<S108>/sat4' */
extern CALDATA const volatile boolean KIPM_TBOXVCUChrgngCondsDflt_flg;/* Referenced by: '<S109>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXVCUChrgngConds_flg_ovrdflg;/* Referenced by: '<S109>/sat3' */
extern CALDATA const volatile boolean KIPM_TBOXVCUChrgngConds_flg_ovrdval;/* Referenced by: '<S109>/sat4' */
extern CALDATA const volatile boolean KIPM_TBOXVCUOprtLicDflt_flg;/* Referenced by: '<S110>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXVCUOprtLic_flg_ovrdflg;/* Referenced by: '<S110>/sat3' */
extern CALDATA const volatile boolean KIPM_TBOXVCUOprtLic_flg_ovrdval;/* Referenced by: '<S110>/sat4' */
extern CALDATA const volatile boolean KIPM_TBOXVCUVerDflt_flg;/* Referenced by: '<S111>/sat5' */
extern CALDATA const volatile boolean KIPM_TBOXVCUVer_flg_ovrdflg;/* Referenced by: '<S111>/sat3' */
extern CALDATA const volatile boolean KIPM_TBOXVCUVer_flg_ovrdval;/* Referenced by: '<S111>/sat4' */
extern CALDATA const volatile uint8 KIPM_TBoxOpenVentnDflt_enum;/* Referenced by: '<S112>/sat5' */
extern CALDATA const volatile boolean KIPM_TBoxOpenVentn_enum_ovrdflg;/* Referenced by: '<S112>/sat3' */
extern CALDATA const volatile uint8 KIPM_TBoxOpenVentn_enum_ovrdval;/* Referenced by: '<S112>/sat4' */
extern CALDATA const volatile uint8 KIPM_TBoxRmtCarSearchDflt_enum;/* Referenced by: '<S113>/sat5' */
extern CALDATA const volatile boolean KIPM_TBoxRmtCarSearch_enum_ovrdflg;/* Referenced by: '<S113>/sat3' */
extern CALDATA const volatile uint8 KIPM_TBoxRmtCarSearch_enum_ovrdval;/* Referenced by: '<S113>/sat4' */
extern CALDATA const volatile uint8 KIPM_TBoxRmtLckDflt_enum;/* Referenced by: '<S114>/sat5' */
extern CALDATA const volatile boolean KIPM_TBoxRmtLck_enum_ovrdflg;/* Referenced by: '<S114>/sat3' */
extern CALDATA const volatile uint8 KIPM_TBoxRmtLck_enum_ovrdval;/* Referenced by: '<S114>/sat4' */
extern CALDATA const volatile uint8 KIPM_TboxRmtDefrstCtlDflt_enum;/* Referenced by: '<S115>/sat5' */
extern CALDATA const volatile boolean KIPM_TboxRmtDefrstCtl_enum_ovrdflg;/* Referenced by: '<S115>/sat3' */
extern CALDATA const volatile uint8 KIPM_TboxRmtDefrstCtl_enum_ovrdval;/* Referenced by: '<S115>/sat4' */

#endif                                 /* RTW_HEADER_calPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
