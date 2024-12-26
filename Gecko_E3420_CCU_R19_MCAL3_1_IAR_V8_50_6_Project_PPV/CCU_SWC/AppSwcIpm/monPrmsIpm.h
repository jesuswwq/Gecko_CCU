/*
 * File: monPrmsIpm.h
 *
 * Code generated for Simulink model 'AppSwcIpm'.
 *
 * Model version                  : 9.226
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Dec 25 14:36:51 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_monPrmsIpm_h_
#define RTW_HEADER_monPrmsIpm_h_
#include "rtwtypes.h"
#include "AppSwcIpm_types.h"

/* Exported data declaration */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Declaration for custom storage class: Volatile */
extern MONPRM volatile boolean VIPM_ACCMLostComm_flg;/* '<S389>/Switch14' */
extern MONPRM volatile boolean VIPM_APPVerMaxVld_flg;/* '<S15>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_APPVerMax_enum;/* '<S15>/Switch4' */
extern MONPRM volatile boolean VIPM_APPVerMinVld_flg;/* '<S16>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_APPVerMin_enum;/* '<S16>/Switch4' */
extern MONPRM volatile boolean VIPM_BACCANBusOff_flg;/* '<S389>/Switch2' */
extern MONPRM volatile boolean VIPM_BMSACChrgAtclStaVld_flg;/* '<S329>/Logical Operator3' */
extern MONPRM volatile EnumBMSACChrgSt VIPM_BMSACChrgAtclSta_enum;/* '<S329>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSActExchgCurntVld_flg;/* '<S311>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSActExchgCurnt_A;/* '<S311>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSBatCapctyVld_flg;/* '<S174>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSBatCapcty_Ah;/* '<S174>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSBatSOCActVld_flg;/* '<S320>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSBatSOCAct_pct;/* '<S320>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSBatSOCRptVld_flg;/* '<S321>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSBatSOCRpt_pct;/* '<S321>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSBatSOHVld_flg;/* '<S322>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSBatSOH_pct;/* '<S322>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSCellVoltMaxVld_flg;/* '<S348>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSCellVoltMax_mV;/* '<S348>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSCellVoltMinVld_flg;/* '<S349>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSCellVoltMin_mV;/* '<S349>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSChrgInterlockStaVld_flg;/* '<S312>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSChrgInterlockSta_enum;/* '<S312>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSDCSActOprtModeVld_flg;/* '<S309>/Logical Operator3' */
extern MONPRM volatile EnumBMSDCSMd VIPM_BMSDCSActOprtMode_enum;/* '<S309>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSDCSChrgReqVld_flg;/* '<S328>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_BMSDCSChrgReq_flg;/* '<S328>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSDCSInletConnectStaVld_flg;/* '<S310>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_BMSDCSInletConnectSta_flg;/* '<S310>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSDchrgInterlockStaVld_flg;/* '<S313>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSDchrgInterlockSta_enum;/* '<S313>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSEmgcySdnReqVld_flg;/* '<S314>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_BMSEmgcySdnReq_flg;/* '<S314>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSHVBatActVoltVld_flg;/* '<S323>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSHVBatActVolt_V;/* '<S323>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSHVBatCellTempAveVld_flg;/* '<S129>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSHVBatCellTempAve_C;/* '<S129>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSHVBatCellTempMaxVld_flg;/* '<S130>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSHVBatCellTempMax_C;/* '<S130>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSHVBatCellTempMinVld_flg;/* '<S131>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSHVBatCellTempMin_C;/* '<S131>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSInletCooltActlTempVld_flg;/* '<S330>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSInletCooltActlTemp_C;/* '<S330>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSIsoResistVld_flg;/* '<S331>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSIsoResist_MOhm;/* '<S331>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSLostComm_flg;/* '<S389>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSMaxChrgCurntACVld_flg;/* '<S332>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSMaxChrgCurntAC_A;/* '<S332>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSMaxChrgVoltACVld_flg;/* '<S333>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSMaxChrgVoltAC_V;/* '<S333>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSMaxConChrgCurntVld_flg;/* '<S340>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSMaxConChrgCurnt_A;/* '<S340>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSMaxConDisCurntVld_flg;/* '<S341>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSMaxConDisCurnt_A;/* '<S341>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSMaxInsChrgCurntVld_flg;/* '<S342>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSMaxInsChrgCurnt_A;/* '<S342>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSMaxInsDisCurntVld_flg;/* '<S343>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSMaxInsDisCurnt_A;/* '<S343>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSOutlCooltActlTempVld_flg;/* '<S334>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSOutlCooltActlTemp_C;/* '<S334>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSPackIDVld_flg;/* '<S175>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSPackID_enum;/* '<S175>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSPwrTrainConnectStaVld_flg;/* '<S315>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSPwrTrainConnectSta_enum;/* '<S315>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSRunStaVld_flg;/* '<S316>/Logical Operator3' */
extern MONPRM volatile EnumBMSRunSt VIPM_BMSRunSta_enum;/* '<S316>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSSysFailStaVld_flg;/* '<S317>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSSysFailSta_enum;/* '<S317>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSThermrunawayWrnVld_flg;/* '<S318>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSThermrunawayWrn_enum;/* '<S318>/Switch4' */
extern MONPRM volatile boolean VIPM_BMS_2_BatState_CRCFlt_flg;/* '<S388>/Logical Operator14' */
extern MONPRM volatile boolean VIPM_BODCANBusOff_flg;/* '<S389>/Switch1' */
extern MONPRM volatile boolean VIPM_BootVerVld_flg;/* '<S17>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BootVer_enum;/* '<S17>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPACAutoKeyVld_flg;/* '<S355>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPACAutoKey_flg;/* '<S355>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPACSwKeyVld_flg;/* '<S356>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPACSwKey_flg;/* '<S356>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPAVASOffKeyVld_flg;/* '<S357>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPAVASOffKey_flg;/* '<S357>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPAVHKeyVld_flg;/* '<S358>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPAVHKey_flg;/* '<S358>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPAirInletModeKeyVld_flg;/* '<S359>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPAirInletModeKey_flg;/* '<S359>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPBlwngModeNextKeyVld_flg;/* '<S360>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPBlwngModeNextKey_flg;/* '<S360>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPBlwngModePrevKeyVld_flg;/* '<S361>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPBlwngModePrevKey_flg;/* '<S361>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPBlwrLvlAddKeyVld_flg;/* '<S362>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPBlwrLvlAddKey_flg;/* '<S362>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPBlwrLvlDecKeyVld_flg;/* '<S363>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPBlwrLvlDecKey_flg;/* '<S363>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPCenLckKeyVld_flg;/* '<S364>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPCenLckKey_flg;/* '<S364>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPESCOffKeyVld_flg;/* '<S365>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPESCOffKey_flg;/* '<S365>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPFrntWindDefrstKeyVld_flg;/* '<S366>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPFrntWindDefrstKey_flg;/* '<S366>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPHDCKeyVld_flg;/* '<S367>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPHDCKey_flg;/* '<S367>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPHzrdKeyVld_flg;/* '<S368>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPHzrdKey_flg;/* '<S368>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPLostComm_flg;/* '<S389>/Switch20' */
extern MONPRM volatile boolean VIPM_CCPModeKeyVld_flg;/* '<S369>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPModeKey_flg;/* '<S369>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPPwrRecupLvlKeyVld_flg;/* '<S370>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPPwrRecupLvlKey_flg;/* '<S370>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPRrViewMirrHeatgKeyVld_flg;/* '<S371>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPRrViewMirrHeatgKey_flg;/* '<S371>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPTPMSKeyVld_flg;/* '<S372>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPTPMSKey_flg;/* '<S372>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPTempAddKeyVld_flg;/* '<S373>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPTempAddKey_flg;/* '<S373>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPTempDecKeyVld_flg;/* '<S374>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPTempDecKey_flg;/* '<S374>/Switch4' */
extern MONPRM volatile boolean VIPM_CCP_PanelStatus_CRCFlt_flg;/* '<S388>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CDCBackLadjvalVld_flg;/* '<S75>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CDCBackLadjval_enum;/* '<S75>/Switch4' */
extern MONPRM volatile boolean VIPM_CDCLostComm_flg;/* '<S389>/Switch16' */
extern MONPRM volatile boolean VIPM_CHACANBusOff_flg;/* '<S389>/Switch3' */
extern MONPRM volatile boolean VIPM_COMPCANBusOffVld_flg;/* '<S24>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_COMPCANBusOff_flg;/* '<S24>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPCommuErrorVld_flg;/* '<S25>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_COMPCommuError_flg;/* '<S25>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPCurrOfstVld_flg;/* '<S26>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_COMPCurrOfst_flg;/* '<S26>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPEcompActSpdVld_flg;/* '<S27>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_COMPEcompActSpd_rpm;/* '<S27>/MinMax1' */
extern MONPRM volatile boolean VIPM_COMPEcompSTVld_flg;/* '<S28>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_COMPEcompST_enum;/* '<S28>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPHiVoltVld_flg;/* '<S29>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_COMPHiVolt_V;/* '<S29>/MinMax1' */
extern MONPRM volatile boolean VIPM_COMPHvErrVld_flg;/* '<S30>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_COMPHvErr_enum;/* '<S30>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPIPMErrVld_flg;/* '<S31>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_COMPIPMErr_flg;/* '<S31>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPInCurrVld_flg;/* '<S32>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_COMPInCurr_A;/* '<S32>/MinMax1' */
extern MONPRM volatile boolean VIPM_COMPLoseStepVld_flg;/* '<S33>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_COMPLoseStep_flg;/* '<S33>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPLvErrVld_flg;/* '<S34>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_COMPLvErr_enum;/* '<S34>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPOverDutyVld_flg;/* '<S35>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_COMPOverDuty_flg;/* '<S35>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPOvrCurrVld_flg;/* '<S36>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_COMPOvrCurr_enum;/* '<S36>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPPISaturationVld_flg;/* '<S37>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_COMPPISaturation_flg;/* '<S37>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPSelfChkErrVld_flg;/* '<S38>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_COMPSelfChkErr_enum;/* '<S38>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPTempErrVld_flg;/* '<S39>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_COMPTempErr_flg;/* '<S39>/Switch4' */
extern MONPRM volatile boolean VIPM_COMPTempVld_flg;/* '<S40>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_COMPTemp_C;/* '<S40>/MinMax1' */
extern MONPRM volatile boolean VIPM_COMP_AC_CRCFlt_flg;/* '<S388>/Logical Operator4' */
extern MONPRM volatile boolean VIPM_CRRRBSDWarnLtVld_flg;/* '<S272>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CRRRBSDWarnLt_enum;/* '<S272>/Switch4' */
extern MONPRM volatile boolean VIPM_CRRRBSDWarnRtVld_flg;/* '<S273>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CRRRBSDWarnRt_enum;/* '<S273>/Switch4' */
extern MONPRM volatile boolean VIPM_CRRRDOWWarnLtVld_flg;/* '<S274>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CRRRDOWWarnLt_enum;/* '<S274>/Switch4' */
extern MONPRM volatile boolean VIPM_CRRRDOWWarnRtVld_flg;/* '<S275>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CRRRDOWWarnRt_enum;/* '<S275>/Switch4' */
extern MONPRM volatile boolean VIPM_CRRRLostComm_flg;/* '<S389>/Switch7' */
extern MONPRM volatile boolean VIPM_CRRRRCTAWarnLtVld_flg;/* '<S276>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CRRRRCTAWarnLt_enum;/* '<S276>/Switch4' */
extern MONPRM volatile boolean VIPM_CRRRRCTAWarnRtVld_flg;/* '<S277>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CRRRRCTAWarnRt_enum;/* '<S277>/Switch4' */
extern MONPRM volatile boolean VIPM_CRRR_A_CRCFlt_flg;/* '<S388>/Logical Operator7' */
extern MONPRM volatile boolean VIPM_ClientNumVld_flg;/* '<S18>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ClientNum_enum;/* '<S18>/Switch4' */
extern MONPRM volatile boolean VIPM_ECUHiVoltInterlockSigVld_flg;/* '<S41>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ECUHiVoltInterlockSig_flg;/* '<S41>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBAVHAppldStVld_flg;/* '<S278>/Logical Operator3' */
extern MONPRM volatile EnumAVHSt VIPM_EHBAVHAppldSt_enum;/* '<S278>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBBLAVld_flg;/* '<S279>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_EHBBLA_flg;/* '<S279>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBBrkPedlValPercVld_flg;/* '<S182>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_EHBBrkPedlValPerc_pct;/* '<S182>/MinMax1' */
extern MONPRM volatile boolean VIPM_EHBBrkPwrRecupTarWhlTqStsVld_flg;/* '<S183>/Logical Operator3' */
extern MONPRM volatile EnumRegenTgtTqStat VIPM_EHBBrkPwrRecupTarWhlTqSts_enum;/* '<S183>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBBrkPwrRecupTarWhlTqVld_flg;/* '<S184>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_EHBBrkPwrRecupTarWhlTq_Nm;/* '<S184>/MinMax1' */
extern MONPRM volatile boolean VIPM_EHBCDDActvVld_flg;/* '<S185>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_EHBCDDActv_flg;/* '<S185>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBEPBActuatorStLVld_flg;/* '<S280>/Logical Operator3' */
extern MONPRM volatile EnumEPBState VIPM_EHBEPBActuatorStL_enum;/* '<S280>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBEPBActuatorStRVld_flg;/* '<S186>/Logical Operator3' */
extern MONPRM volatile EnumEPBState VIPM_EHBEPBActuatorStR_enum;/* '<S186>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBEPBDynAppStVld_flg;/* '<S187>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_EHBEPBDynAppSt_enum;/* '<S187>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBEPBSwitchStsVld_flg;/* '<S281>/Logical Operator3' */
extern MONPRM volatile EnumEPBSwSt VIPM_EHBEPBSwitchSts_enum;/* '<S281>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBEPBSysStVld_flg;/* '<S282>/Logical Operator3' */
extern MONPRM volatile EnumEPBSysSt VIPM_EHBEPBSysSt_enum;/* '<S282>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBFltLvlVld_flg;/* '<S188>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_EHBFltLvl_enum;/* '<S188>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBHDCFucFaultVld_flg;/* '<S283>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_EHBHDCFucFault_flg;/* '<S283>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBLostComm_flg;/* '<S389>/Switch18' */
extern MONPRM volatile boolean VIPM_EHBReqBrkLiOnVld_flg;/* '<S189>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_EHBReqBrkLiOn_flg;/* '<S189>/Switch4' */
extern MONPRM volatile boolean VIPM_EHB_B_CRCFlt_flg;/* '<S388>/Logical Operator8' */
extern MONPRM volatile boolean VIPM_EPSLostComm_flg;/* '<S389>/Switch9' */
extern MONPRM volatile boolean VIPM_EPSRotSpdVld_flg;/* '<S191>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_EPSRotSpd_degps;/* '<S191>/MinMax1' */
extern MONPRM volatile boolean VIPM_EPSSteerWhlAngCaldVld_flg;/* '<S192>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_EPSSteerWhlAngCald_flg;/* '<S192>/Switch4' */
extern MONPRM volatile boolean VIPM_EPSSteerWhlAngFailrVld_flg;/* '<S193>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_EPSSteerWhlAngFailr_flg;/* '<S193>/Switch4' */
extern MONPRM volatile boolean VIPM_EPSSteerWhlAngVld_flg;/* '<S194>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_EPSSteerWhlAng_deg;/* '<S194>/MinMax1' */
extern MONPRM volatile boolean VIPM_EPS_2_StrWhlAng_CRCFlt_flg;/* '<S388>/Logical Operator9' */
extern MONPRM volatile boolean VIPM_EPTCANBusOff_flg;/* '<S389>/Switch' */
extern MONPRM volatile boolean VIPM_ESCABSActvStaVld_flg;/* '<S197>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCABSActvSta_flg;/* '<S197>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCCDPActvVld_flg;/* '<S198>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCCDPActv_flg;/* '<S198>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCEBDActvVld_flg;/* '<S199>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCEBDActv_flg;/* '<S199>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCESPActvStaVld_flg;/* '<S200>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCESPActvSta_flg;/* '<S200>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCESSActvVld_flg;/* '<S201>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCESSActv_flg;/* '<S201>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCFltLvlVld_flg;/* '<S202>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ESCFltLvl_enum;/* '<S202>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCLUnOrLockfeedbackVld_flg;/* '<S375>/Logical Operator3' */
extern MONPRM volatile uint64 VIPM_ESCLUnOrLockfeedback_nu;/* '<S375>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCLatAccSnsrValVld_flg;/* '<S209>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCLatAccSnsrVal_g;/* '<S209>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCLongAccSnsrValVld_flg;/* '<S210>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCLongAccSnsrVal_g;/* '<S210>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCLostComm_flg;/* '<S389>/Switch5' */
extern MONPRM volatile boolean VIPM_ESCMstrCylPresrVld_flg;/* '<S211>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCMstrCylPresr_bar;/* '<S211>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCReqBrkLghtOnVld_flg;/* '<S203>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCReqBrkLghtOn_flg;/* '<S203>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCSlopPctVld_flg;/* '<S204>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCSlopPct_pct;/* '<S204>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCTCSActvStaVld_flg;/* '<S205>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCTCSActvSta_flg;/* '<S205>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCVehSpdVld_flg;/* '<S206>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCVehSpd_kph;/* '<S206>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCVehStandStillStaVld_flg;/* '<S212>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ESCVehStandStillSta_enum;/* '<S212>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlDirctnFLVld_flg;/* '<S213>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ESCWhlDirctnFL_enum;/* '<S213>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlDirctnFRVld_flg;/* '<S214>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ESCWhlDirctnFR_enum;/* '<S214>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlDirctnRLVld_flg;/* '<S215>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ESCWhlDirctnRL_enum;/* '<S215>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlDirctnRRVld_flg;/* '<S216>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ESCWhlDirctnRR_enum;/* '<S216>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlSpdKphFLVld_flg;/* '<S217>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCWhlSpdKphFL_kph;/* '<S217>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCWhlSpdKphFRVld_flg;/* '<S218>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCWhlSpdKphFR_kph;/* '<S218>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCWhlSpdKphRLVld_flg;/* '<S219>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCWhlSpdKphRL_kph;/* '<S219>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCWhlSpdKphRRVld_flg;/* '<S220>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCWhlSpdKphRR_kph;/* '<S220>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCWhlTqDecReqActvVld_flg;/* '<S221>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCWhlTqDecReqActv_flg;/* '<S221>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlTqDecReqValVld_flg;/* '<S222>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCWhlTqDecReqVal_Nm;/* '<S222>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCWhlTqIncReqActvVld_flg;/* '<S223>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCWhlTqIncReqActv_flg;/* '<S223>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlTqIncReqValVld_flg;/* '<S224>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCWhlTqIncReqVal_Nm;/* '<S224>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCYawRateVld_flg;/* '<S225>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCYawRate_degps;/* '<S225>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESC_7_FuncStatus_CRCFlt_flg;/* '<S388>/Logical Operator10' */
extern MONPRM volatile boolean VIPM_FCMACCSdnModeVld_flg;/* '<S284>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_FCMACCSdnMode_enum;/* '<S284>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMACCWhlDeceVld_flg;/* '<S285>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_FCMACCWhlDece_mps2;/* '<S285>/MinMax1' */
extern MONPRM volatile boolean VIPM_FCMACCWhlTqReqActvVld_flg;/* '<S286>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_FCMACCWhlTqReqActv_flg;/* '<S286>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMACCWhlTqReqValVld_flg;/* '<S287>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_FCMACCWhlTqReqVal_Nm;/* '<S287>/MinMax1' */
extern MONPRM volatile boolean VIPM_FCMAEBReqVld_flg;/* '<S288>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_FCMAEBReq_flg;/* '<S288>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMAccModeVld_flg;/* '<S289>/Logical Operator3' */
extern MONPRM volatile EnumACCMode VIPM_FCMAccMode_enum;/* '<S289>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMAccReqDriveOffVld_flg;/* '<S290>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_FCMAccReqDriveOff_flg;/* '<S290>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMAccReqStandstillVld_flg;/* '<S291>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_FCMAccReqStandstill_flg;/* '<S291>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMAccTarAccrnReqActvVld_flg;/* '<S292>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_FCMAccTarAccrnReqActv_flg;/* '<S292>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMAccTarAccrnVld_flg;/* '<S293>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_FCMAccTarAccrn_mps2;/* '<S293>/MinMax1' */
extern MONPRM volatile boolean VIPM_FCMAccTgtAxReqVld_flg;/* '<S294>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_FCMAccTgtAxReq_flg;/* '<S294>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMAccTgtAxVld_flg;/* '<S295>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_FCMAccTgtAx_mps2;/* '<S295>/MinMax1' */
extern MONPRM volatile boolean VIPM_FCMEPBReqVld_flg;/* '<S296>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_FCMEPBReq_enum;/* '<S296>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMLostComm_flg;/* '<S389>/Switch6' */
extern MONPRM volatile boolean VIPM_FCMTrnLampReqVld_flg;/* '<S297>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_FCMTrnLampReq_enum;/* '<S297>/Switch4' */
extern MONPRM volatile boolean VIPM_FCM_B_CRCFlt_flg;/* '<S388>/Logical Operator11' */
extern MONPRM volatile boolean VIPM_HUACAutoCtlVld_flg;/* '<S76>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUACAutoCtl_enum;/* '<S76>/Switch4' */
extern MONPRM volatile boolean VIPM_HUACPwrCtlVld_flg;/* '<S77>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUACPwrCtl_enum;/* '<S77>/Switch4' */
extern MONPRM volatile boolean VIPM_HUACUnlckVentSetVld_flg;/* '<S78>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUACUnlckVentSet_enum;/* '<S78>/Switch4' */
extern MONPRM volatile boolean VIPM_HUAirInletModeSetVld_flg;/* '<S79>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUAirInletModeSet_enum;/* '<S79>/Switch4' */
extern MONPRM volatile boolean VIPM_HUBCMCargoLghtSetVld_flg;/* '<S80>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUBCMCargoLghtSet_enum;/* '<S80>/Switch4' */
extern MONPRM volatile boolean VIPM_HUBCMOTAModeSetVld_flg;/* '<S81>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUBCMOTAModeSet_enum;/* '<S81>/Switch4' */
extern MONPRM volatile boolean VIPM_HUBlwrModeSetVld_flg;/* '<S82>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUBlwrModeSet_enum;/* '<S82>/Switch4' */
extern MONPRM volatile boolean VIPM_HUChgWiprMtMdSwSetVld_flg;/* '<S83>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUChgWiprMtMdSwSet_enum;/* '<S83>/Switch4' */
extern MONPRM volatile boolean VIPM_HUChrgngReqVld_flg;/* '<S84>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUChrgngReq_enum;/* '<S84>/Switch4' */
extern MONPRM volatile boolean VIPM_HUChrgngmodeVld_flg;/* '<S85>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUChrgngmode_enum;/* '<S85>/Switch4' */
extern MONPRM volatile boolean VIPM_HUCstRecupModeSelVld_flg;/* '<S86>/Logical Operator3' */
extern MONPRM volatile EnumRegenModeSelct VIPM_HUCstRecupModeSel_enum;/* '<S86>/Switch4' */
extern MONPRM volatile boolean VIPM_HUDrvModeSelVld_flg;/* '<S87>/Logical Operator3' */
extern MONPRM volatile EnumDrvModeSelct VIPM_HUDrvModeSel_enum;/* '<S87>/Switch4' */
extern MONPRM volatile boolean VIPM_HUDrvPwrSetVld_flg;/* '<S88>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUDrvPwrSet_cnt;/* '<S88>/Switch4' */
extern MONPRM volatile boolean VIPM_HUFlwrMeHmCtrlVld_flg;/* '<S89>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUFlwrMeHmCtrl_enum;/* '<S89>/Switch4' */
extern MONPRM volatile boolean VIPM_HUFrntFanSpdSetVld_flg;/* '<S90>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUFrntFanSpdSet_enum;/* '<S90>/Switch4' */
extern MONPRM volatile boolean VIPM_HUHybEcoModeSetVld_flg;/* '<S91>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUHybEcoModeSet_enum;/* '<S91>/Switch4' */
extern MONPRM volatile boolean VIPM_HUIllmndEntryStsVld_flg;/* '<S92>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUIllmndEntrySts_enum;/* '<S92>/Switch4' */
extern MONPRM volatile boolean VIPM_HUIllmndLckStsVld_flg;/* '<S93>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUIllmndLckSts_enum;/* '<S93>/Switch4' */
extern MONPRM volatile boolean VIPM_HUIllmndUnlckStsVld_flg;/* '<S94>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUIllmndUnlckSts_enum;/* '<S94>/Switch4' */
extern MONPRM volatile boolean VIPM_HULckHornOnStVld_flg;/* '<S95>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HULckHornOnSt_enum;/* '<S95>/Switch4' */
extern MONPRM volatile boolean VIPM_HULeftTempSetVld_flg;/* '<S96>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HULeftTempSet_enum;/* '<S96>/Switch4' */
extern MONPRM volatile boolean VIPM_HUMaiDrvrSeatHeatVld_flg;/* '<S97>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUMaiDrvrSeatHeat_enum;/* '<S97>/Switch4' */
extern MONPRM volatile boolean VIPM_HUManlDefrstCtlVld_flg;/* '<S98>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUManlDefrstCtl_enum;/* '<S98>/Switch4' */
extern MONPRM volatile boolean VIPM_HUOvrspdCntrlLckSetVld_flg;/* '<S99>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUOvrspdCntrlLckSet_enum;/* '<S99>/Switch4' */
extern MONPRM volatile boolean VIPM_HUParkAutoUnlckSetVld_flg;/* '<S100>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUParkAutoUnlckSet_enum;/* '<S100>/Switch4' */
extern MONPRM volatile boolean VIPM_HUPeristalsisModeEnblVld_flg;/* '<S101>/Logical Operator3' */
extern MONPRM volatile EnumCrpModeEnbl VIPM_HUPeristalsisModeEnbl_enum;/* '<S101>/Switch4' */
extern MONPRM volatile boolean VIPM_HUPwrOffReqVld_flg;/* '<S102>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_HUPwrOffReq_flg;/* '<S102>/Switch4' */
extern MONPRM volatile boolean VIPM_HURecupPwrSetVld_flg;/* '<S103>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HURecupPwrSet_pct;/* '<S103>/Switch4' */
extern MONPRM volatile boolean VIPM_HURrMirrHeatVld_flg;/* '<S104>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HURrMirrHeat_enum;/* '<S104>/Switch4' */
extern MONPRM volatile boolean VIPM_HUSteerWhlHeatVld_flg;/* '<S105>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUSteerWhlHeat_enum;/* '<S105>/Switch4' */
extern MONPRM volatile boolean VIPM_HUTPMSRstReqVld_flg;/* '<S106>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_HUTPMSRstReq_flg;/* '<S106>/Switch4' */
extern MONPRM volatile boolean VIPM_HUTrnkLckSwCtrlVld_flg;/* '<S107>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUTrnkLckSwCtrl_enum;/* '<S107>/Switch4' */
extern MONPRM volatile boolean VIPM_HUVehMaxCurrVld_flg;/* '<S108>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUVehMaxCurr_A;/* '<S108>/Switch4' */
extern MONPRM volatile boolean VIPM_HUWiprIntlTmSetVld_flg;/* '<S109>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUWiprIntlTmSet_enum;/* '<S109>/Switch4' */
extern MONPRM volatile boolean VIPM_HU_B_CRCFlt_flg;/* '<S388>/Logical Operator' */
extern MONPRM volatile boolean VIPM_HVCHCurrVld_flg;/* '<S55>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_HVCHCurr_A;/* '<S55>/MinMax1' */
extern MONPRM volatile boolean VIPM_HVCHFltCodVld_flg;/* '<S56>/Logical Operator3' */
extern MONPRM volatile uint16 VIPM_HVCHFltCod_enum;/* '<S56>/Switch4' */
extern MONPRM volatile boolean VIPM_HVCHHVStVld_flg;/* '<S46>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_HVCHHVSt_flg;/* '<S46>/Switch4' */
extern MONPRM volatile boolean VIPM_HVCHHVVoltsVld_flg;/* '<S57>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_HVCHHVVolts_V;/* '<S57>/MinMax1' */
extern MONPRM volatile boolean VIPM_HVCHInletTempVld_flg;/* '<S47>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_HVCHInletTemp_C;/* '<S47>/MinMax1' */
extern MONPRM volatile boolean VIPM_HVCHOutlTempVld_flg;/* '<S48>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_HVCHOutlTemp_C;/* '<S48>/MinMax1' */
extern MONPRM volatile boolean VIPM_HVCHPCBTempVld_flg;/* '<S49>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_HVCHPCBTemp_C;/* '<S49>/MinMax1' */
extern MONPRM volatile boolean VIPM_HVCHPwrVld_flg;/* '<S58>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_HVCHPwr_kW;/* '<S58>/MinMax1' */
extern MONPRM volatile boolean VIPM_HVCHStVld_flg;/* '<S50>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HVCHSt_enum;/* '<S50>/Switch4' */
extern MONPRM volatile boolean VIPM_HVCHWorkModeVld_flg;/* '<S51>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HVCHWorkMode_enum;/* '<S51>/Switch4' */
extern MONPRM volatile boolean VIPM_HVCHWorkStVld_flg;/* '<S59>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HVCHWorkSt_enum;/* '<S59>/Switch4' */
extern MONPRM volatile boolean VIPM_HVCH_Status1_CRCFlt_flg;/* '<S388>/Logical Operator5' */
extern MONPRM volatile boolean VIPM_HwVerMaxVld_flg;/* '<S19>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HwVerMax_enum;/* '<S19>/Switch4' */
extern MONPRM volatile boolean VIPM_HwVerMinVld_flg;/* '<S20>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HwVerMin_enum;/* '<S20>/Switch4' */
extern MONPRM volatile boolean VIPM_ICULostComm_flg;/* '<S389>/Switch11' */
extern MONPRM volatile boolean VIPM_ICUTotOdoVld_flg;/* '<S73>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ICUTotOdo_km;/* '<S73>/MinMax1' */
extern MONPRM volatile boolean VIPM_ICU_Info_CRCFlt_flg;/* '<S388>/Logical Operator1' */
extern MONPRM volatile boolean VIPM_INV1ActModeVld_flg;/* '<S239>/Logical Operator3' */
extern MONPRM volatile EnumINVActMd VIPM_INV1ActMode_enum;/* '<S239>/Switch4' */
extern MONPRM volatile boolean VIPM_INV1ActTorqVld_flg;/* '<S240>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV1ActTorq_Nm;/* '<S240>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV1AntithftAuthRsltVld_flg;/* '<S241>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INV1AntithftAuthRslt_enum;/* '<S241>/Switch4' */
extern MONPRM volatile boolean VIPM_INV1MotSpdVld_flg;/* '<S242>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV1MotSpd_rpm;/* '<S242>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV1PreChrgAllwdVld_flg;/* '<S243>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INV1PreChrgAllwd_enum;/* '<S243>/Switch4' */
extern MONPRM volatile boolean VIPM_INV1PreprogmFlgVld_flg;/* '<S244>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_INV1PreprogmFlg_flg;/* '<S244>/Switch4' */
extern MONPRM volatile boolean VIPM_INV1ShutdownAllwdVld_flg;/* '<S245>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INV1ShutdownAllwd_enum;/* '<S245>/Switch4' */
extern MONPRM volatile boolean VIPM_INV2IgbtMaxTempVld_flg;/* '<S248>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV2IgbtMaxTemp_C;/* '<S248>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV2InpCurntVld_flg;/* '<S249>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV2InpCurnt_A;/* '<S249>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV2InpVoltVld_flg;/* '<S250>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV2InpVolt_V;/* '<S250>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV2MotorMaxTempVld_flg;/* '<S251>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV2MotorMaxTemp_C;/* '<S251>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV3DrvTqAllwdMaxVld_flg;/* '<S255>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV3DrvTqAllwdMax_Nm;/* '<S255>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV3RecupTqAllwdMaxVld_flg;/* '<S256>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV3RecupTqAllwdMax_Nm;/* '<S256>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV4FltLvlVld_flg;/* '<S259>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INV4FltLvl_enum;/* '<S259>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngData02Vld_flg;/* '<S135>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngData02_nu;/* '<S135>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngData03Vld_flg;/* '<S136>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngData03_nu;/* '<S136>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngData04Vld_flg;/* '<S137>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngData04_nu;/* '<S137>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngData05Vld_flg;/* '<S138>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngData05_nu;/* '<S138>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngData06Vld_flg;/* '<S139>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngData06_nu;/* '<S139>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngData07Vld_flg;/* '<S140>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngData07_nu;/* '<S140>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngStsVld_flg;/* '<S141>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngSts_enum;/* '<S141>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngSubIDVld_flg;/* '<S142>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngSubID_cnt;/* '<S142>/Switch4' */
extern MONPRM volatile boolean VIPM_INV_1_Value_CRCFlt_flg;/* '<S388>/Logical Operator15' */
extern MONPRM volatile boolean VIPM_IPUDCCActOprtModeVld_flg;/* '<S143>/Logical Operator3' */
extern MONPRM volatile EnumDCCActMd VIPM_IPUDCCActOprtMode_enum;/* '<S143>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUDCCHiVoltActCurntVld_flg;/* '<S150>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUDCCHiVoltActCurnt_A;/* '<S150>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUDCCHiVoltActVoltVld_flg;/* '<S151>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUDCCHiVoltActVolt_V;/* '<S151>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUDCCLoVoltActCurntVld_flg;/* '<S144>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUDCCLoVoltActCurnt_A;/* '<S144>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUDCCLoVoltActVoltVld_flg;/* '<S145>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUDCCLoVoltActVolt_V;/* '<S145>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUDCCSysFailStaVld_flg;/* '<S146>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_IPUDCCSysFailSta_enum;/* '<S146>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUDeviceIntTempVld_flg;/* '<S165>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUDeviceIntTemp_C;/* '<S165>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUHVILFailStVld_flg;/* '<S147>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_IPUHVILFailSt_flg;/* '<S147>/Switch4' */
extern MONPRM volatile boolean VIPM_IPULostComm_flg;/* '<S389>/Switch17' */
extern MONPRM volatile boolean VIPM_IPUOBCACMaxPwrAllowVld_flg;/* '<S166>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUOBCACMaxPwrAllow_kW;/* '<S166>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUOBCActOprtModeVld_flg;/* '<S154>/Logical Operator3' */
extern MONPRM volatile EnumOBCActMd VIPM_IPUOBCActOprtMode_enum;/* '<S154>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUOBCConnectMainStaVld_flg;/* '<S155>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_IPUOBCConnectMainSta_flg;/* '<S155>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUOBCHVDCActCurVld_flg;/* '<S156>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUOBCHVDCActCur_A;/* '<S156>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUOBCHVDCActVolVld_flg;/* '<S157>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUOBCHVDCActVol_V;/* '<S157>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUOBCInletActPwrVld_flg;/* '<S158>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUOBCInletActPwr_kW;/* '<S158>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUOBCInletConnectStaVld_flg;/* '<S159>/Logical Operator3' */
extern MONPRM volatile EnumOBCPlugSt VIPM_IPUOBCInletConnectSta_enum;/* '<S159>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUOBCReqVld_flg;/* '<S160>/Logical Operator3' */
extern MONPRM volatile EnumOBCReq VIPM_IPUOBCReq_enum;/* '<S160>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUOBCS2StateVld_flg;/* '<S167>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_IPUOBCS2State_flg;/* '<S167>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUOBCSysFailStaVld_flg;/* '<S161>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_IPUOBCSysFailSta_enum;/* '<S161>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUOBCTempIntVld_flg;/* '<S168>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUOBCTempInt_C;/* '<S168>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUOBCWakeUpModeVld_flg;/* '<S169>/Logical Operator3' */
extern MONPRM volatile EnumOBCWakeUpMd VIPM_IPUOBCWakeUpMode_enum;/* '<S169>/Switch4' */
extern MONPRM volatile boolean VIPM_IPU_DCC_1_State_CRCFlt_flg;/* '<S388>/Logical Operator16' */
extern MONPRM volatile boolean VIPM_MCULostComm_flg;/* '<S389>/Switch13' */
extern MONPRM volatile boolean VIPM_PPLostComm_flg;/* '<S389>/Switch8' */
extern MONPRM volatile boolean VIPM_PP_InformAndStatus_CRCFlt_flg;/* '<S388>/Logical Operator12' */
extern MONPRM volatile boolean VIPM_PTCLostComm_flg;/* '<S389>/Switch15' */
extern MONPRM volatile boolean VIPM_SCSFrntWiprSwtStVld_flg;/* '<S376>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_SCSFrntWiprSwtSt_enum;/* '<S376>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSFrntWshrSwtStVld_flg;/* '<S377>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSFrntWshrSwtSt_flg;/* '<S377>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSGrShftLvrPstnReqVld_flg;/* '<S264>/Logical Operator3' */
extern MONPRM volatile EnumGrShftLvrPstnReq VIPM_SCSGrShftLvrPstnReq_enum;/* '<S264>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSHiBeamSwStVld_flg;/* '<S378>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSHiBeamSwSt_flg;/* '<S378>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSLampAutoStVld_flg;/* '<S379>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSLampAutoSt_flg;/* '<S379>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSLeTrnLmpSwStVld_flg;/* '<S380>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSLeTrnLmpSwSt_flg;/* '<S380>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSLoBeamSwStVld_flg;/* '<S381>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSLoBeamSwSt_flg;/* '<S381>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSLostComm_flg;/* '<S389>/Switch19' */
extern MONPRM volatile boolean VIPM_SCSOvrVehBeamSwStVld_flg;/* '<S382>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSOvrVehBeamSwSt_flg;/* '<S382>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSPstnLghtSwStVld_flg;/* '<S383>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSPstnLghtSwSt_flg;/* '<S383>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSRght11SwVld_flg;/* '<S265>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSRght11Sw_flg;/* '<S265>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSRght12SwVld_flg;/* '<S266>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSRght12Sw_flg;/* '<S266>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSRght13SwVld_flg;/* '<S267>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSRght13Sw_flg;/* '<S267>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSRghtSwVldtyVld_flg;/* '<S268>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSRghtSwVldty_flg;/* '<S268>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSRiTrnLmpSwStVld_flg;/* '<S384>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSRiTrnLmpSwSt_flg;/* '<S384>/Switch4' */
extern MONPRM volatile boolean VIPM_SCS_RiSwitchSts_CRCFlt_flg;/* '<S388>/Logical Operator6' */
extern MONPRM volatile boolean VIPM_SRSCrashOutputStsVld_flg;/* '<S386>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_SRSCrashOutputSts_enum;/* '<S386>/Switch4' */
extern MONPRM volatile boolean VIPM_SRSDrvSeatbeltBkldVld_flg;/* '<S387>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SRSDrvSeatbeltBkld_flg;/* '<S387>/Switch4' */
extern MONPRM volatile boolean VIPM_SRSLostComm_flg;/* '<S389>/Switch10' */
extern MONPRM volatile boolean VIPM_SRS_1_Status_CRCFlt_flg;/* '<S388>/Logical Operator13' */
extern MONPRM volatile boolean VIPM_TBOXACRemtCtrlFlgVld_flg;/* '<S110>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXACRemtCtrlFlg_enum;/* '<S110>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXACTempSetVld_flg;/* '<S111>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXACTempSet_enum;/* '<S111>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXBJSTimeDayVld_flg;/* '<S64>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXBJSTimeDay_nu;/* '<S64>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXBJSTimeHourVld_flg;/* '<S65>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXBJSTimeHour_nu;/* '<S65>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXBJSTimeMinVld_flg;/* '<S66>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXBJSTimeMin_nu;/* '<S66>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXBJSTimeMonthVld_flg;/* '<S67>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXBJSTimeMonth_nu;/* '<S67>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXBJSTimeSecVld_flg;/* '<S68>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXBJSTimeSec_nu;/* '<S68>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXBJSTimeYearVld_flg;/* '<S69>/Logical Operator3' */
extern MONPRM volatile uint16 VIPM_TBOXBJSTimeYear_nu;/* '<S69>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXLostComm_flg;/* '<S389>/Switch12' */
extern MONPRM volatile boolean VIPM_TBOXRemtMaiDrSeatHeatReqVld_flg;/* '<S112>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXRemtMaiDrSeatHeatReq_enum;/* '<S112>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXRemtPwrCtrlReqVld_flg;/* '<S113>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXRemtPwrCtrlReq_enum;/* '<S113>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXRemtStrWhlHeatReqVld_flg;/* '<S114>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXRemtStrWhlHeatReq_enum;/* '<S114>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXRmtPwrLckVld_flg;/* '<S115>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXRmtPwrLck_enum;/* '<S115>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXVCUCCMSpdLimLvlVld_flg;/* '<S116>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXVCUCCMSpdLimLvl_enum;/* '<S116>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXVCUChrgngCondsVld_flg;/* '<S117>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_TBOXVCUChrgngConds_flg;/* '<S117>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXVCUOprtLicVld_flg;/* '<S118>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_TBOXVCUOprtLic_flg;/* '<S118>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXVCUVerVld_flg;/* '<S119>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_TBOXVCUVer_flg;/* '<S119>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOX_BJS_Time_CRCFlt_flg;/* '<S388>/Logical Operator2' */
extern MONPRM volatile boolean VIPM_TBoxOpenVentnVld_flg;/* '<S120>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBoxOpenVentn_enum;/* '<S120>/Switch4' */
extern MONPRM volatile boolean VIPM_TBoxRmtCarSearchVld_flg;/* '<S121>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBoxRmtCarSearch_enum;/* '<S121>/Switch4' */
extern MONPRM volatile boolean VIPM_TBoxRmtLckVld_flg;/* '<S122>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBoxRmtLck_enum;/* '<S122>/Switch4' */
extern MONPRM volatile boolean VIPM_TboxRmtDefrstCtlVld_flg;/* '<S123>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TboxRmtDefrstCtl_enum;/* '<S123>/Switch4' */

#endif                                 /* RTW_HEADER_monPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
