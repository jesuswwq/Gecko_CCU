/*
 * File: monPrmsIpm.h
 *
 * Code generated for Simulink model 'AppSwcIpm'.
 *
 * Model version                  : 9.219
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov 13 16:55:17 2024
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
extern MONPRM volatile boolean VIPM_ACCMLostComm_flg;/* '<S384>/Switch14' */
extern MONPRM volatile boolean VIPM_APPVerMaxVld_flg;/* '<S15>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_APPVerMax_enum;/* '<S15>/Switch4' */
extern MONPRM volatile boolean VIPM_APPVerMinVld_flg;/* '<S16>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_APPVerMin_enum;/* '<S16>/Switch4' */
extern MONPRM volatile boolean VIPM_BACCANBusOff_flg;/* '<S384>/Switch2' */
extern MONPRM volatile boolean VIPM_BMSACChrgAtclStaVld_flg;/* '<S324>/Logical Operator3' */
extern MONPRM volatile EnumBMSACChrgSt VIPM_BMSACChrgAtclSta_enum;/* '<S324>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSActExchgCurntVld_flg;/* '<S306>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSActExchgCurnt_A;/* '<S306>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSBatCapctyVld_flg;/* '<S169>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSBatCapcty_Ah;/* '<S169>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSBatSOCActVld_flg;/* '<S315>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSBatSOCAct_pct;/* '<S315>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSBatSOCRptVld_flg;/* '<S316>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSBatSOCRpt_pct;/* '<S316>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSBatSOHVld_flg;/* '<S317>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSBatSOH_pct;/* '<S317>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSCellVoltMaxVld_flg;/* '<S343>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSCellVoltMax_mV;/* '<S343>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSCellVoltMinVld_flg;/* '<S344>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSCellVoltMin_mV;/* '<S344>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSChrgInterlockStaVld_flg;/* '<S307>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSChrgInterlockSta_enum;/* '<S307>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSDCSActOprtModeVld_flg;/* '<S304>/Logical Operator3' */
extern MONPRM volatile EnumBMSDCSMd VIPM_BMSDCSActOprtMode_enum;/* '<S304>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSDCSChrgReqVld_flg;/* '<S323>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_BMSDCSChrgReq_flg;/* '<S323>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSDCSInletConnectStaVld_flg;/* '<S305>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_BMSDCSInletConnectSta_flg;/* '<S305>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSDchrgInterlockStaVld_flg;/* '<S308>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSDchrgInterlockSta_enum;/* '<S308>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSEmgcySdnReqVld_flg;/* '<S309>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_BMSEmgcySdnReq_flg;/* '<S309>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSHVBatActVoltVld_flg;/* '<S318>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSHVBatActVolt_V;/* '<S318>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSHVBatCellTempAveVld_flg;/* '<S124>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSHVBatCellTempAve_C;/* '<S124>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSHVBatCellTempMaxVld_flg;/* '<S125>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSHVBatCellTempMax_C;/* '<S125>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSHVBatCellTempMinVld_flg;/* '<S126>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSHVBatCellTempMin_C;/* '<S126>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSInletCooltActlTempVld_flg;/* '<S325>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSInletCooltActlTemp_C;/* '<S325>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSIsoResistVld_flg;/* '<S326>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSIsoResist_MOhm;/* '<S326>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSLostComm_flg;/* '<S384>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSMaxChrgCurntACVld_flg;/* '<S327>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSMaxChrgCurntAC_A;/* '<S327>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSMaxChrgVoltACVld_flg;/* '<S328>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSMaxChrgVoltAC_V;/* '<S328>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSMaxConChrgCurntVld_flg;/* '<S335>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSMaxConChrgCurnt_A;/* '<S335>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSMaxConDisCurntVld_flg;/* '<S336>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSMaxConDisCurnt_A;/* '<S336>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSMaxInsChrgCurntVld_flg;/* '<S337>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSMaxInsChrgCurnt_A;/* '<S337>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSMaxInsDisCurntVld_flg;/* '<S338>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSMaxInsDisCurnt_A;/* '<S338>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSOutlCooltActlTempVld_flg;/* '<S329>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_BMSOutlCooltActlTemp_C;/* '<S329>/MinMax1' */
extern MONPRM volatile boolean VIPM_BMSPackIDVld_flg;/* '<S170>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSPackID_enum;/* '<S170>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSPwrTrainConnectStaVld_flg;/* '<S310>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSPwrTrainConnectSta_enum;/* '<S310>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSRunStaVld_flg;/* '<S311>/Logical Operator3' */
extern MONPRM volatile EnumBMSRunSt VIPM_BMSRunSta_enum;/* '<S311>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSSysFailStaVld_flg;/* '<S312>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSSysFailSta_enum;/* '<S312>/Switch4' */
extern MONPRM volatile boolean VIPM_BMSThermrunawayWrnVld_flg;/* '<S313>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BMSThermrunawayWrn_enum;/* '<S313>/Switch4' */
extern MONPRM volatile boolean VIPM_BMS_2_BatState_CRCFlt_flg;/* '<S383>/Logical Operator14' */
extern MONPRM volatile boolean VIPM_BODCANBusOff_flg;/* '<S384>/Switch1' */
extern MONPRM volatile boolean VIPM_BootVerVld_flg;/* '<S17>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_BootVer_enum;/* '<S17>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPACAutoKeyVld_flg;/* '<S350>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPACAutoKey_flg;/* '<S350>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPACSwKeyVld_flg;/* '<S351>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPACSwKey_flg;/* '<S351>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPAVASOffKeyVld_flg;/* '<S352>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPAVASOffKey_flg;/* '<S352>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPAVHKeyVld_flg;/* '<S353>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPAVHKey_flg;/* '<S353>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPAirInletModeKeyVld_flg;/* '<S354>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPAirInletModeKey_flg;/* '<S354>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPBlwngModeNextKeyVld_flg;/* '<S355>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPBlwngModeNextKey_flg;/* '<S355>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPBlwngModePrevKeyVld_flg;/* '<S356>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPBlwngModePrevKey_flg;/* '<S356>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPBlwrLvlAddKeyVld_flg;/* '<S357>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPBlwrLvlAddKey_flg;/* '<S357>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPBlwrLvlDecKeyVld_flg;/* '<S358>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPBlwrLvlDecKey_flg;/* '<S358>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPCenLckKeyVld_flg;/* '<S359>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPCenLckKey_flg;/* '<S359>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPESCOffKeyVld_flg;/* '<S360>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPESCOffKey_flg;/* '<S360>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPFrntWindDefrstKeyVld_flg;/* '<S361>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPFrntWindDefrstKey_flg;/* '<S361>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPHDCKeyVld_flg;/* '<S362>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPHDCKey_flg;/* '<S362>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPHzrdKeyVld_flg;/* '<S363>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPHzrdKey_flg;/* '<S363>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPLostComm_flg;/* '<S384>/Switch20' */
extern MONPRM volatile boolean VIPM_CCPModeKeyVld_flg;/* '<S364>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPModeKey_flg;/* '<S364>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPPwrRecupLvlKeyVld_flg;/* '<S365>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPPwrRecupLvlKey_flg;/* '<S365>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPRrViewMirrHeatgKeyVld_flg;/* '<S366>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPRrViewMirrHeatgKey_flg;/* '<S366>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPTPMSKeyVld_flg;/* '<S367>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPTPMSKey_flg;/* '<S367>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPTempAddKeyVld_flg;/* '<S368>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPTempAddKey_flg;/* '<S368>/Switch4' */
extern MONPRM volatile boolean VIPM_CCPTempDecKeyVld_flg;/* '<S369>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CCPTempDecKey_flg;/* '<S369>/Switch4' */
extern MONPRM volatile boolean VIPM_CCP_PanelStatus_CRCFlt_flg;/* '<S383>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_CDCBackLadjvalVld_flg;/* '<S75>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CDCBackLadjval_enum;/* '<S75>/Switch4' */
extern MONPRM volatile boolean VIPM_CDCLostComm_flg;/* '<S384>/Switch16' */
extern MONPRM volatile boolean VIPM_CHACANBusOff_flg;/* '<S384>/Switch3' */
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
extern MONPRM volatile boolean VIPM_COMP_AC_CRCFlt_flg;/* '<S383>/Logical Operator4' */
extern MONPRM volatile boolean VIPM_CRRRBSDWarnLtVld_flg;/* '<S267>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CRRRBSDWarnLt_enum;/* '<S267>/Switch4' */
extern MONPRM volatile boolean VIPM_CRRRBSDWarnRtVld_flg;/* '<S268>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CRRRBSDWarnRt_enum;/* '<S268>/Switch4' */
extern MONPRM volatile boolean VIPM_CRRRDOWWarnLtVld_flg;/* '<S269>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CRRRDOWWarnLt_enum;/* '<S269>/Switch4' */
extern MONPRM volatile boolean VIPM_CRRRDOWWarnRtVld_flg;/* '<S270>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CRRRDOWWarnRt_enum;/* '<S270>/Switch4' */
extern MONPRM volatile boolean VIPM_CRRRLostComm_flg;/* '<S384>/Switch7' */
extern MONPRM volatile boolean VIPM_CRRRRCTAWarnLtVld_flg;/* '<S271>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CRRRRCTAWarnLt_enum;/* '<S271>/Switch4' */
extern MONPRM volatile boolean VIPM_CRRRRCTAWarnRtVld_flg;/* '<S272>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_CRRRRCTAWarnRt_enum;/* '<S272>/Switch4' */
extern MONPRM volatile boolean VIPM_CRRR_A_CRCFlt_flg;/* '<S383>/Logical Operator7' */
extern MONPRM volatile boolean VIPM_ClientNumVld_flg;/* '<S18>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ClientNum_enum;/* '<S18>/Switch4' */
extern MONPRM volatile boolean VIPM_ECUHiVoltInterlockSigVld_flg;/* '<S41>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ECUHiVoltInterlockSig_flg;/* '<S41>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBAVHAppldStVld_flg;/* '<S273>/Logical Operator3' */
extern MONPRM volatile EnumAVHSt VIPM_EHBAVHAppldSt_enum;/* '<S273>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBBLAVld_flg;/* '<S274>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_EHBBLA_flg;/* '<S274>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBBrkPedlValPercVld_flg;/* '<S177>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_EHBBrkPedlValPerc_pct;/* '<S177>/MinMax1' */
extern MONPRM volatile boolean VIPM_EHBBrkPwrRecupTarWhlTqStsVld_flg;/* '<S178>/Logical Operator3' */
extern MONPRM volatile EnumRegenTgtTqStat VIPM_EHBBrkPwrRecupTarWhlTqSts_enum;/* '<S178>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBBrkPwrRecupTarWhlTqVld_flg;/* '<S179>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_EHBBrkPwrRecupTarWhlTq_Nm;/* '<S179>/MinMax1' */
extern MONPRM volatile boolean VIPM_EHBCDDActvVld_flg;/* '<S180>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_EHBCDDActv_flg;/* '<S180>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBEPBActuatorStLVld_flg;/* '<S275>/Logical Operator3' */
extern MONPRM volatile EnumEPBState VIPM_EHBEPBActuatorStL_enum;/* '<S275>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBEPBActuatorStRVld_flg;/* '<S181>/Logical Operator3' */
extern MONPRM volatile EnumEPBState VIPM_EHBEPBActuatorStR_enum;/* '<S181>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBEPBDynAppStVld_flg;/* '<S182>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_EHBEPBDynAppSt_enum;/* '<S182>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBEPBSwitchStsVld_flg;/* '<S276>/Logical Operator3' */
extern MONPRM volatile EnumEPBSwSt VIPM_EHBEPBSwitchSts_enum;/* '<S276>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBEPBSysStVld_flg;/* '<S277>/Logical Operator3' */
extern MONPRM volatile EnumEPBSysSt VIPM_EHBEPBSysSt_enum;/* '<S277>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBFltLvlVld_flg;/* '<S183>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_EHBFltLvl_enum;/* '<S183>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBHDCFucFaultVld_flg;/* '<S278>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_EHBHDCFucFault_flg;/* '<S278>/Switch4' */
extern MONPRM volatile boolean VIPM_EHBLostComm_flg;/* '<S384>/Switch18' */
extern MONPRM volatile boolean VIPM_EHBReqBrkLiOnVld_flg;/* '<S184>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_EHBReqBrkLiOn_flg;/* '<S184>/Switch4' */
extern MONPRM volatile boolean VIPM_EHB_B_CRCFlt_flg;/* '<S383>/Logical Operator8' */
extern MONPRM volatile boolean VIPM_EPSLostComm_flg;/* '<S384>/Switch9' */
extern MONPRM volatile boolean VIPM_EPSRotSpdVld_flg;/* '<S186>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_EPSRotSpd_degps;/* '<S186>/MinMax1' */
extern MONPRM volatile boolean VIPM_EPSSteerWhlAngCaldVld_flg;/* '<S187>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_EPSSteerWhlAngCald_flg;/* '<S187>/Switch4' */
extern MONPRM volatile boolean VIPM_EPSSteerWhlAngFailrVld_flg;/* '<S188>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_EPSSteerWhlAngFailr_flg;/* '<S188>/Switch4' */
extern MONPRM volatile boolean VIPM_EPSSteerWhlAngVld_flg;/* '<S189>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_EPSSteerWhlAng_deg;/* '<S189>/MinMax1' */
extern MONPRM volatile boolean VIPM_EPS_2_StrWhlAng_CRCFlt_flg;/* '<S383>/Logical Operator9' */
extern MONPRM volatile boolean VIPM_EPTCANBusOff_flg;/* '<S384>/Switch' */
extern MONPRM volatile boolean VIPM_ESCABSActvStaVld_flg;/* '<S192>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCABSActvSta_flg;/* '<S192>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCCDPActvVld_flg;/* '<S193>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCCDPActv_flg;/* '<S193>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCEBDActvVld_flg;/* '<S194>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCEBDActv_flg;/* '<S194>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCESPActvStaVld_flg;/* '<S195>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCESPActvSta_flg;/* '<S195>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCESSActvVld_flg;/* '<S196>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCESSActv_flg;/* '<S196>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCFltLvlVld_flg;/* '<S197>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ESCFltLvl_enum;/* '<S197>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCLUnOrLockfeedbackVld_flg;/* '<S370>/Logical Operator3' */
extern MONPRM volatile uint64 VIPM_ESCLUnOrLockfeedback_nu;/* '<S370>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCLatAccSnsrValVld_flg;/* '<S204>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCLatAccSnsrVal_g;/* '<S204>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCLongAccSnsrValVld_flg;/* '<S205>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCLongAccSnsrVal_g;/* '<S205>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCLostComm_flg;/* '<S384>/Switch5' */
extern MONPRM volatile boolean VIPM_ESCMstrCylPresrVld_flg;/* '<S206>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCMstrCylPresr_bar;/* '<S206>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCReqBrkLghtOnVld_flg;/* '<S198>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCReqBrkLghtOn_flg;/* '<S198>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCSlopPctVld_flg;/* '<S199>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCSlopPct_pct;/* '<S199>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCTCSActvStaVld_flg;/* '<S200>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCTCSActvSta_flg;/* '<S200>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCVehSpdVld_flg;/* '<S201>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCVehSpd_kph;/* '<S201>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCVehStandStillStaVld_flg;/* '<S207>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ESCVehStandStillSta_enum;/* '<S207>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlDirctnFLVld_flg;/* '<S208>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ESCWhlDirctnFL_enum;/* '<S208>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlDirctnFRVld_flg;/* '<S209>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ESCWhlDirctnFR_enum;/* '<S209>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlDirctnRLVld_flg;/* '<S210>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ESCWhlDirctnRL_enum;/* '<S210>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlDirctnRRVld_flg;/* '<S211>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_ESCWhlDirctnRR_enum;/* '<S211>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlSpdKphFLVld_flg;/* '<S212>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCWhlSpdKphFL_kph;/* '<S212>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCWhlSpdKphFRVld_flg;/* '<S213>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCWhlSpdKphFR_kph;/* '<S213>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCWhlSpdKphRLVld_flg;/* '<S214>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCWhlSpdKphRL_kph;/* '<S214>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCWhlSpdKphRRVld_flg;/* '<S215>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCWhlSpdKphRR_kph;/* '<S215>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCWhlTqDecReqActvVld_flg;/* '<S216>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCWhlTqDecReqActv_flg;/* '<S216>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlTqDecReqValVld_flg;/* '<S217>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCWhlTqDecReqVal_Nm;/* '<S217>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCWhlTqIncReqActvVld_flg;/* '<S218>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_ESCWhlTqIncReqActv_flg;/* '<S218>/Switch4' */
extern MONPRM volatile boolean VIPM_ESCWhlTqIncReqValVld_flg;/* '<S219>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCWhlTqIncReqVal_Nm;/* '<S219>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESCYawRateVld_flg;/* '<S220>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ESCYawRate_degps;/* '<S220>/MinMax1' */
extern MONPRM volatile boolean VIPM_ESC_7_FuncStatus_CRCFlt_flg;/* '<S383>/Logical Operator10' */
extern MONPRM volatile boolean VIPM_FCMACCSdnModeVld_flg;/* '<S279>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_FCMACCSdnMode_enum;/* '<S279>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMACCWhlDeceVld_flg;/* '<S280>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_FCMACCWhlDece_mps2;/* '<S280>/MinMax1' */
extern MONPRM volatile boolean VIPM_FCMACCWhlTqReqActvVld_flg;/* '<S281>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_FCMACCWhlTqReqActv_flg;/* '<S281>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMACCWhlTqReqValVld_flg;/* '<S282>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_FCMACCWhlTqReqVal_Nm;/* '<S282>/MinMax1' */
extern MONPRM volatile boolean VIPM_FCMAEBReqVld_flg;/* '<S283>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_FCMAEBReq_flg;/* '<S283>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMAccModeVld_flg;/* '<S284>/Logical Operator3' */
extern MONPRM volatile EnumACCMode VIPM_FCMAccMode_enum;/* '<S284>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMAccReqDriveOffVld_flg;/* '<S285>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_FCMAccReqDriveOff_flg;/* '<S285>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMAccReqStandstillVld_flg;/* '<S286>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_FCMAccReqStandstill_flg;/* '<S286>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMAccTarAccrnReqActvVld_flg;/* '<S287>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_FCMAccTarAccrnReqActv_flg;/* '<S287>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMAccTarAccrnVld_flg;/* '<S288>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_FCMAccTarAccrn_mps2;/* '<S288>/MinMax1' */
extern MONPRM volatile boolean VIPM_FCMAccTgtAxReqVld_flg;/* '<S289>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_FCMAccTgtAxReq_flg;/* '<S289>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMAccTgtAxVld_flg;/* '<S290>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_FCMAccTgtAx_mps2;/* '<S290>/MinMax1' */
extern MONPRM volatile boolean VIPM_FCMEPBReqVld_flg;/* '<S291>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_FCMEPBReq_enum;/* '<S291>/Switch4' */
extern MONPRM volatile boolean VIPM_FCMLostComm_flg;/* '<S384>/Switch6' */
extern MONPRM volatile boolean VIPM_FCMTrnLampReqVld_flg;/* '<S292>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_FCMTrnLampReq_enum;/* '<S292>/Switch4' */
extern MONPRM volatile boolean VIPM_FCM_B_CRCFlt_flg;/* '<S383>/Logical Operator11' */
extern MONPRM volatile boolean VIPM_HUACAutoCtlVld_flg;/* '<S76>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUACAutoCtl_enum;/* '<S76>/Switch4' */
extern MONPRM volatile boolean VIPM_HUACPwrCtlVld_flg;/* '<S77>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUACPwrCtl_enum;/* '<S77>/Switch4' */
extern MONPRM volatile boolean VIPM_HUACUnlckVentSetVld_flg;/* '<S78>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUACUnlckVentSet_enum;/* '<S78>/Switch4' */
extern MONPRM volatile boolean VIPM_HUAirInletModeSetVld_flg;/* '<S79>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUAirInletModeSet_enum;/* '<S79>/Switch4' */
extern MONPRM volatile boolean VIPM_HUBlwrModeSetVld_flg;/* '<S80>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUBlwrModeSet_enum;/* '<S80>/Switch4' */
extern MONPRM volatile boolean VIPM_HUChgWiprMtMdSwSetVld_flg;/* '<S81>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUChgWiprMtMdSwSet_enum;/* '<S81>/Switch4' */
extern MONPRM volatile boolean VIPM_HUChrgngReqVld_flg;/* '<S82>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUChrgngReq_enum;/* '<S82>/Switch4' */
extern MONPRM volatile boolean VIPM_HUChrgngmodeVld_flg;/* '<S83>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUChrgngmode_enum;/* '<S83>/Switch4' */
extern MONPRM volatile boolean VIPM_HUCstRecupModeSelVld_flg;/* '<S84>/Logical Operator3' */
extern MONPRM volatile EnumRegenModeSelct VIPM_HUCstRecupModeSel_enum;/* '<S84>/Switch4' */
extern MONPRM volatile boolean VIPM_HUDrvModeSelVld_flg;/* '<S85>/Logical Operator3' */
extern MONPRM volatile EnumDrvModeSelct VIPM_HUDrvModeSel_enum;/* '<S85>/Switch4' */
extern MONPRM volatile boolean VIPM_HUDrvPwrSetVld_flg;/* '<S86>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUDrvPwrSet_cnt;/* '<S86>/Switch4' */
extern MONPRM volatile boolean VIPM_HUFlwrMeHmCtrlVld_flg;/* '<S87>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUFlwrMeHmCtrl_enum;/* '<S87>/Switch4' */
extern MONPRM volatile boolean VIPM_HUFrntFanSpdSetVld_flg;/* '<S88>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUFrntFanSpdSet_enum;/* '<S88>/Switch4' */
extern MONPRM volatile boolean VIPM_HUHybEcoModeSetVld_flg;/* '<S89>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUHybEcoModeSet_enum;/* '<S89>/Switch4' */
extern MONPRM volatile boolean VIPM_HUIllmndEntryStsVld_flg;/* '<S90>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUIllmndEntrySts_enum;/* '<S90>/Switch4' */
extern MONPRM volatile boolean VIPM_HUIllmndLckStsVld_flg;/* '<S91>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUIllmndLckSts_enum;/* '<S91>/Switch4' */
extern MONPRM volatile boolean VIPM_HUIllmndUnlckStsVld_flg;/* '<S92>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUIllmndUnlckSts_enum;/* '<S92>/Switch4' */
extern MONPRM volatile boolean VIPM_HULckHornOnStVld_flg;/* '<S93>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HULckHornOnSt_enum;/* '<S93>/Switch4' */
extern MONPRM volatile boolean VIPM_HULeftTempSetVld_flg;/* '<S94>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HULeftTempSet_enum;/* '<S94>/Switch4' */
extern MONPRM volatile boolean VIPM_HUMaiDrvrSeatHeatVld_flg;/* '<S95>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUMaiDrvrSeatHeat_enum;/* '<S95>/Switch4' */
extern MONPRM volatile boolean VIPM_HUManlDefrstCtlVld_flg;/* '<S96>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUManlDefrstCtl_enum;/* '<S96>/Switch4' */
extern MONPRM volatile boolean VIPM_HUOvrspdCntrlLckSetVld_flg;/* '<S97>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUOvrspdCntrlLckSet_enum;/* '<S97>/Switch4' */
extern MONPRM volatile boolean VIPM_HUParkAutoUnlckSetVld_flg;/* '<S98>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUParkAutoUnlckSet_enum;/* '<S98>/Switch4' */
extern MONPRM volatile boolean VIPM_HUPeristalsisModeEnblVld_flg;/* '<S99>/Logical Operator3' */
extern MONPRM volatile EnumCrpModeEnbl VIPM_HUPeristalsisModeEnbl_enum;/* '<S99>/Switch4' */
extern MONPRM volatile boolean VIPM_HUPwrOffReqVld_flg;/* '<S100>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_HUPwrOffReq_flg;/* '<S100>/Switch4' */
extern MONPRM volatile boolean VIPM_HURecupPwrSetVld_flg;/* '<S101>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HURecupPwrSet_pct;/* '<S101>/Switch4' */
extern MONPRM volatile boolean VIPM_HURrMirrHeatVld_flg;/* '<S102>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HURrMirrHeat_enum;/* '<S102>/Switch4' */
extern MONPRM volatile boolean VIPM_HUSteerWhlHeatVld_flg;/* '<S103>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUSteerWhlHeat_enum;/* '<S103>/Switch4' */
extern MONPRM volatile boolean VIPM_HUTPMSRstReqVld_flg;/* '<S104>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_HUTPMSRstReq_flg;/* '<S104>/Switch4' */
extern MONPRM volatile boolean VIPM_HUTrnkLckSwCtrlVld_flg;/* '<S105>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUTrnkLckSwCtrl_enum;/* '<S105>/Switch4' */
extern MONPRM volatile boolean VIPM_HUVehMaxCurrVld_flg;/* '<S106>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUVehMaxCurr_A;/* '<S106>/Switch4' */
extern MONPRM volatile boolean VIPM_HUWiprIntlTmSetVld_flg;/* '<S107>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HUWiprIntlTmSet_enum;/* '<S107>/Switch4' */
extern MONPRM volatile boolean VIPM_HU_B_CRCFlt_flg;/* '<S383>/Logical Operator' */
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
extern MONPRM volatile boolean VIPM_HVCH_Status1_CRCFlt_flg;/* '<S383>/Logical Operator5' */
extern MONPRM volatile boolean VIPM_HwVerMaxVld_flg;/* '<S19>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HwVerMax_enum;/* '<S19>/Switch4' */
extern MONPRM volatile boolean VIPM_HwVerMinVld_flg;/* '<S20>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_HwVerMin_enum;/* '<S20>/Switch4' */
extern MONPRM volatile boolean VIPM_ICULostComm_flg;/* '<S384>/Switch11' */
extern MONPRM volatile boolean VIPM_ICUTotOdoVld_flg;/* '<S73>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_ICUTotOdo_km;/* '<S73>/MinMax1' */
extern MONPRM volatile boolean VIPM_ICU_Info_CRCFlt_flg;/* '<S383>/Logical Operator1' */
extern MONPRM volatile boolean VIPM_INV1ActModeVld_flg;/* '<S234>/Logical Operator3' */
extern MONPRM volatile EnumINVActMd VIPM_INV1ActMode_enum;/* '<S234>/Switch4' */
extern MONPRM volatile boolean VIPM_INV1ActTorqVld_flg;/* '<S235>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV1ActTorq_Nm;/* '<S235>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV1AntithftAuthRsltVld_flg;/* '<S236>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INV1AntithftAuthRslt_enum;/* '<S236>/Switch4' */
extern MONPRM volatile boolean VIPM_INV1MotSpdVld_flg;/* '<S237>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV1MotSpd_rpm;/* '<S237>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV1PreChrgAllwdVld_flg;/* '<S238>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INV1PreChrgAllwd_enum;/* '<S238>/Switch4' */
extern MONPRM volatile boolean VIPM_INV1PreprogmFlgVld_flg;/* '<S239>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_INV1PreprogmFlg_flg;/* '<S239>/Switch4' */
extern MONPRM volatile boolean VIPM_INV1ShutdownAllwdVld_flg;/* '<S240>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INV1ShutdownAllwd_enum;/* '<S240>/Switch4' */
extern MONPRM volatile boolean VIPM_INV2IgbtMaxTempVld_flg;/* '<S243>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV2IgbtMaxTemp_C;/* '<S243>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV2InpCurntVld_flg;/* '<S244>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV2InpCurnt_A;/* '<S244>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV2InpVoltVld_flg;/* '<S245>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV2InpVolt_V;/* '<S245>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV2MotorMaxTempVld_flg;/* '<S246>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV2MotorMaxTemp_C;/* '<S246>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV3DrvTqAllwdMaxVld_flg;/* '<S250>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV3DrvTqAllwdMax_Nm;/* '<S250>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV3RecupTqAllwdMaxVld_flg;/* '<S251>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_INV3RecupTqAllwdMax_Nm;/* '<S251>/MinMax1' */
extern MONPRM volatile boolean VIPM_INV4FltLvlVld_flg;/* '<S254>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INV4FltLvl_enum;/* '<S254>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngData02Vld_flg;/* '<S130>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngData02_nu;/* '<S130>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngData03Vld_flg;/* '<S131>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngData03_nu;/* '<S131>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngData04Vld_flg;/* '<S132>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngData04_nu;/* '<S132>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngData05Vld_flg;/* '<S133>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngData05_nu;/* '<S133>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngData06Vld_flg;/* '<S134>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngData06_nu;/* '<S134>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngData07Vld_flg;/* '<S135>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngData07_nu;/* '<S135>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngStsVld_flg;/* '<S136>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngSts_enum;/* '<S136>/Switch4' */
extern MONPRM volatile boolean VIPM_INVLrngSubIDVld_flg;/* '<S137>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_INVLrngSubID_cnt;/* '<S137>/Switch4' */
extern MONPRM volatile boolean VIPM_INV_1_Value_CRCFlt_flg;/* '<S383>/Logical Operator15' */
extern MONPRM volatile boolean VIPM_IPUDCCActOprtModeVld_flg;/* '<S138>/Logical Operator3' */
extern MONPRM volatile EnumDCCActMd VIPM_IPUDCCActOprtMode_enum;/* '<S138>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUDCCHiVoltActCurntVld_flg;/* '<S145>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUDCCHiVoltActCurnt_A;/* '<S145>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUDCCHiVoltActVoltVld_flg;/* '<S146>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUDCCHiVoltActVolt_V;/* '<S146>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUDCCLoVoltActCurntVld_flg;/* '<S139>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUDCCLoVoltActCurnt_A;/* '<S139>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUDCCLoVoltActVoltVld_flg;/* '<S140>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUDCCLoVoltActVolt_V;/* '<S140>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUDCCSysFailStaVld_flg;/* '<S141>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_IPUDCCSysFailSta_enum;/* '<S141>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUDeviceIntTempVld_flg;/* '<S160>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUDeviceIntTemp_C;/* '<S160>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUHVILFailStVld_flg;/* '<S142>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_IPUHVILFailSt_flg;/* '<S142>/Switch4' */
extern MONPRM volatile boolean VIPM_IPULostComm_flg;/* '<S384>/Switch17' */
extern MONPRM volatile boolean VIPM_IPUOBCACMaxPwrAllowVld_flg;/* '<S161>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUOBCACMaxPwrAllow_kW;/* '<S161>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUOBCActOprtModeVld_flg;/* '<S149>/Logical Operator3' */
extern MONPRM volatile EnumOBCActMd VIPM_IPUOBCActOprtMode_enum;/* '<S149>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUOBCConnectMainStaVld_flg;/* '<S150>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_IPUOBCConnectMainSta_flg;/* '<S150>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUOBCHVDCActCurVld_flg;/* '<S151>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUOBCHVDCActCur_A;/* '<S151>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUOBCHVDCActVolVld_flg;/* '<S152>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUOBCHVDCActVol_V;/* '<S152>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUOBCInletActPwrVld_flg;/* '<S153>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUOBCInletActPwr_kW;/* '<S153>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUOBCInletConnectStaVld_flg;/* '<S154>/Logical Operator3' */
extern MONPRM volatile EnumOBCPlugSt VIPM_IPUOBCInletConnectSta_enum;/* '<S154>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUOBCReqVld_flg;/* '<S155>/Logical Operator3' */
extern MONPRM volatile EnumOBCReq VIPM_IPUOBCReq_enum;/* '<S155>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUOBCS2StateVld_flg;/* '<S162>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_IPUOBCS2State_flg;/* '<S162>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUOBCSysFailStaVld_flg;/* '<S156>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_IPUOBCSysFailSta_enum;/* '<S156>/Switch4' */
extern MONPRM volatile boolean VIPM_IPUOBCTempIntVld_flg;/* '<S163>/Logical Operator3' */
extern MONPRM volatile float32 VIPM_IPUOBCTempInt_C;/* '<S163>/MinMax1' */
extern MONPRM volatile boolean VIPM_IPUOBCWakeUpModeVld_flg;/* '<S164>/Logical Operator3' */
extern MONPRM volatile EnumOBCWakeUpMd VIPM_IPUOBCWakeUpMode_enum;/* '<S164>/Switch4' */
extern MONPRM volatile boolean VIPM_IPU_DCC_1_State_CRCFlt_flg;/* '<S383>/Logical Operator16' */
extern MONPRM volatile boolean VIPM_MCULostComm_flg;/* '<S384>/Switch13' */
extern MONPRM volatile boolean VIPM_PPLostComm_flg;/* '<S384>/Switch8' */
extern MONPRM volatile boolean VIPM_PP_InformAndStatus_CRCFlt_flg;/* '<S383>/Logical Operator12' */
extern MONPRM volatile boolean VIPM_PTCLostComm_flg;/* '<S384>/Switch15' */
extern MONPRM volatile boolean VIPM_SCSFrntWiprSwtStVld_flg;/* '<S371>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_SCSFrntWiprSwtSt_enum;/* '<S371>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSFrntWshrSwtStVld_flg;/* '<S372>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSFrntWshrSwtSt_flg;/* '<S372>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSGrShftLvrPstnReqVld_flg;/* '<S259>/Logical Operator3' */
extern MONPRM volatile EnumGrShftLvrPstnReq VIPM_SCSGrShftLvrPstnReq_enum;/* '<S259>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSHiBeamSwStVld_flg;/* '<S373>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSHiBeamSwSt_flg;/* '<S373>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSLampAutoStVld_flg;/* '<S374>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSLampAutoSt_flg;/* '<S374>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSLeTrnLmpSwStVld_flg;/* '<S375>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSLeTrnLmpSwSt_flg;/* '<S375>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSLoBeamSwStVld_flg;/* '<S376>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSLoBeamSwSt_flg;/* '<S376>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSLostComm_flg;/* '<S384>/Switch19' */
extern MONPRM volatile boolean VIPM_SCSOvrVehBeamSwStVld_flg;/* '<S377>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSOvrVehBeamSwSt_flg;/* '<S377>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSPstnLghtSwStVld_flg;/* '<S378>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSPstnLghtSwSt_flg;/* '<S378>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSRght11SwVld_flg;/* '<S260>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSRght11Sw_flg;/* '<S260>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSRght12SwVld_flg;/* '<S261>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSRght12Sw_flg;/* '<S261>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSRght13SwVld_flg;/* '<S262>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSRght13Sw_flg;/* '<S262>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSRghtSwVldtyVld_flg;/* '<S263>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSRghtSwVldty_flg;/* '<S263>/Switch4' */
extern MONPRM volatile boolean VIPM_SCSRiTrnLmpSwStVld_flg;/* '<S379>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SCSRiTrnLmpSwSt_flg;/* '<S379>/Switch4' */
extern MONPRM volatile boolean VIPM_SCS_RiSwitchSts_CRCFlt_flg;/* '<S383>/Logical Operator6' */
extern MONPRM volatile boolean VIPM_SRSCrashOutputStsVld_flg;/* '<S381>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_SRSCrashOutputSts_enum;/* '<S381>/Switch4' */
extern MONPRM volatile boolean VIPM_SRSDrvSeatbeltBkldVld_flg;/* '<S382>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_SRSDrvSeatbeltBkld_flg;/* '<S382>/Switch4' */
extern MONPRM volatile boolean VIPM_SRSLostComm_flg;/* '<S384>/Switch10' */
extern MONPRM volatile boolean VIPM_SRS_1_Status_CRCFlt_flg;/* '<S383>/Logical Operator13' */
extern MONPRM volatile boolean VIPM_TBOXACRemtCtrlFlgVld_flg;/* '<S108>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXACRemtCtrlFlg_enum;/* '<S108>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXACTempSetVld_flg;/* '<S109>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXACTempSet_enum;/* '<S109>/Switch4' */
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
extern MONPRM volatile boolean VIPM_TBOXLostComm_flg;/* '<S384>/Switch12' */
extern MONPRM volatile boolean VIPM_TBOXRmtPwrLckVld_flg;/* '<S110>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXRmtPwrLck_enum;/* '<S110>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXVCUCCMSpdLimLvlVld_flg;/* '<S111>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBOXVCUCCMSpdLimLvl_enum;/* '<S111>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXVCUChrgngCondsVld_flg;/* '<S112>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_TBOXVCUChrgngConds_flg;/* '<S112>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXVCUOprtLicVld_flg;/* '<S113>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_TBOXVCUOprtLic_flg;/* '<S113>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOXVCUVerVld_flg;/* '<S114>/Logical Operator3' */
extern MONPRM volatile boolean VIPM_TBOXVCUVer_flg;/* '<S114>/Switch4' */
extern MONPRM volatile boolean VIPM_TBOX_BJS_Time_CRCFlt_flg;/* '<S383>/Logical Operator2' */
extern MONPRM volatile boolean VIPM_TBoxOpenVentnVld_flg;/* '<S115>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBoxOpenVentn_enum;/* '<S115>/Switch4' */
extern MONPRM volatile boolean VIPM_TBoxRmtCarSearchVld_flg;/* '<S116>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBoxRmtCarSearch_enum;/* '<S116>/Switch4' */
extern MONPRM volatile boolean VIPM_TBoxRmtLckVld_flg;/* '<S117>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TBoxRmtLck_enum;/* '<S117>/Switch4' */
extern MONPRM volatile boolean VIPM_TboxRmtDefrstCtlVld_flg;/* '<S118>/Logical Operator3' */
extern MONPRM volatile uint8 VIPM_TboxRmtDefrstCtl_enum;/* '<S118>/Switch4' */

#endif                                 /* RTW_HEADER_monPrmsVcu_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
