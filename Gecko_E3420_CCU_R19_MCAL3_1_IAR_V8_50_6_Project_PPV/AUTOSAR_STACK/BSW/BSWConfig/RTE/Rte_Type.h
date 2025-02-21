/*============================================================================*/
/*  Copyright (C) iSOFT   (2022), iSOFT INFRASTRUCTURE SOFTWARE CO.,LTD.
 *  
 *  All rights reserved. This software is iSOFT property. Duplication 
 *  or disclosure without iSOFT written authorization is prohibited.
 *  
 *  @file       <Rte_Type.h>
 *  @brief      <>
 *  
 *  <MCU:E3420>
 *  
 *  @author     <>
 *  @date       <2025-02-19 14:23:38>
 */
/*============================================================================*/

/* Rte_Type.h */

#ifndef RTE_TYPE_H
#define RTE_TYPE_H

/*******************************************************************************
 **                        Revision Control History                           **
******************************************************************************/

/*******************************************************************************
 **                        Version Information                                **
******************************************************************************/

/*******************************************************************************
 **                        Include Section                                    **
******************************************************************************/
#include "Rte.h"

/*******************************************************************************
 **                        Global Variable Definitions                        **
******************************************************************************/

typedef boolean Boolean;
#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#define _DEFINED_TYPEDEF_FOR_Boolean_

typedef float32 Float;

#define _DEFINED_TYPEDEF_FOR_Float_

typedef sint16 SInt16;

#define _DEFINED_TYPEDEF_FOR_SInt16_

typedef sint8 SInt8;

#define _DEFINED_TYPEDEF_FOR_SInt8_

typedef uint64 UINT64;

#define _DEFINED_TYPEDEF_FOR_UINT64_

typedef uint16 UInt16;

#define _DEFINED_TYPEDEF_FOR_UInt16_

typedef uint32 UInt32;

#define _DEFINED_TYPEDEF_FOR_UInt32_

typedef uint8 UInt8;

#define _DEFINED_TYPEDEF_FOR_UInt8_

typedef struct
{
    UInt8 APP_Version_Max;
    UInt8 APP_Version_Min;
    UInt8 Boot_Version;
    UInt8 Client_Number;
    UInt8 Hardware_Version_Max;
    UInt8 Hardware_Version_Min;
} ACCM_Version_BOD;

#define _DEFINED_TYPEDEF_FOR_ACCM_Version_BOD_

typedef struct
{
    Boolean AC_CompFailModeOprtSta;
    Boolean AC_CompOprtReq;
    Boolean AC_CompOprtEnaCmd;
    UInt16 AC_CompTgtSpd;
    UInt8 AC_CompMaxAllowPwrCmsp;
    UInt8 AC_PumpActlSpdDuty;
    UInt16 AC_HighVolDCTolalPwr;
    Boolean AC_PumpActlSpdDutyV;
} AC_1_Command_BOD;

#define _DEFINED_TYPEDEF_FOR_AC_1_Command_BOD_

typedef struct
{
    UInt8 AC_HVHActlPwr_HVAC;
    UInt8 AC_HVHDeviceInternTemp_HVAC;
    UInt8 TMS_PTPressure;
    UInt16 AC_ActTotalPower;
    Boolean AC_HVHFailSta_HVAC;
    Boolean AC_FailSta;
    Boolean TMSR_BattTempCtrlRmnSwtFb;
    Boolean AC_BatPumpFailSta;
    UInt8 AC_HVHActlOprtMode_HVAC;
    UInt8 AC_ActlOprtMode;
    UInt8 TMS_PTTemp;
} AC_2_State_BOD;

#define _DEFINED_TYPEDEF_FOR_AC_2_State_BOD_

typedef struct
{
    Boolean AC_ExtdDefrostActvReq;
    UInt8 AC_EnvirTemp;
    Boolean AC_EnvirTempV;
    UInt8 AC_IndoorTemp;
    UInt8 TMS_OHXOutTmp;
    UInt8 TMS_EvapTmp;
    UInt8 TMS_EvapOutTmp;
    UInt8 TMS_ChillerOutTmp;
} AC_3_State_BOD;

#define _DEFINED_TYPEDEF_FOR_AC_3_State_BOD_

typedef struct
{
    UInt8 AC_RefrgLoPressure;
    Boolean AC_RefrgLoPressureV;
    UInt8 AC_EvapTgtTemp;
    UInt8 AC_HV_PTC_On_Rq;
    UInt8 AC_Auto_FrontFanSpd;
    UInt8 TMS_MotInletCooltTemp;
    UInt8 TMS_BATThermalMod;
    UInt8 TMS_CabThermalMod;
    UInt8 TMS_PwrCoolFanSpdDuty;
} AC_8_status_BOD;

#define _DEFINED_TYPEDEF_FOR_AC_8_status_BOD_

typedef struct
{
    UInt8 AC_leftTempValue;
    Boolean AC_ManualDefrostFb;
    Boolean AC_ACAutoFb;
    UInt8 AC_BlowerModeSta;
    UInt8 AC_FrontFanSpdValue;
    Boolean AC_ACPowerFb;
    UInt8 AC_AutoBlowerModeSta;
    UInt8 AC_HybridEcoModeSta;
    UInt8 AC_AirInletModeSta;
    Boolean BCM_RearViewMirrHeatingSts;
} AC_ACStatuts_BOD;

#define _DEFINED_TYPEDEF_FOR_AC_ACStatuts_BOD_

typedef struct
{
    UInt8 COMP_EcompSpeedCtrl;
    UInt8 COMP_EcompEnable;
    UInt8 COMP_EcompHVSt;
    UInt8 COMP_EcompErrorClean;
    UInt8 COMP_CompInputPowerLimit;
    UInt8 TMS_ACPExhaustTmp;
    UInt8 TMS_ACPInletPressure;
} AC_COMP_BOD;

#define _DEFINED_TYPEDEF_FOR_AC_COMP_BOD_

typedef struct
{
    UInt8 BodyWarnSts;
    Boolean AlrmWarnTimOut;
} AlmSysCtl;

#define _DEFINED_TYPEDEF_FOR_AlmSysCtl_

typedef struct
{
    Boolean BCM_TurnLampSta_Left;
    Boolean BCM_TurnLampSta_Right;
    Boolean BCM_FogLampSta_Rear;
    Boolean BCM_HighBeamSta;
    Boolean BCM_LowBeamSta;
    Boolean BCM_FogLampSta_Front;
    Boolean BCM_AutoLampStatus;
    Boolean BCM_DayRunLightSta;
    Boolean BCM_ReverseLampSta;
    Boolean BCM_BrakeLampSta;
    Boolean BCM_DayRunLiSwSig;
    UInt8 BCM_TurnLiSts;
    UInt8 BCM_TurnngLiSwSig;
    UInt8 BCM_LightIntensity;
    UInt8 BCM_LightSwSig;
    UInt8 BCM_HighBeamSwSig;
    Boolean BCM_AjarStaV_Hood;
    Boolean BCM_AjarSta_Hood;
    Boolean BCM_HazardWarningLightSwSig;
    Boolean BCM_FrntFogLiSwSig;
    Boolean BCM_RearFogLiSwSig;
    UInt8 BCM_FlwrMeHmCtrlFb;
    UInt8 BCM_BassHornReq;
    Boolean BCM_AjarSta_Trunk;
    Boolean BCM_DoorAjarSta_FL;
    Boolean BCM_DoorAjarSta_FR;
    Boolean BCM_DoorAjarSta_RL;
    Boolean BCM_DoorAjarSta_RR;
    Boolean BCM_LockHornOnStFb;
    Boolean BCM_AlrmHornReq;
    Boolean TPMS_TempSts_FL;
    UInt8 TPMS_PressureSta_FL;
    Boolean TPMS_TempSts_FR;
    UInt8 TPMS_PressureSta_FR;
    UInt8 TPMS_PressureValue_FL;
    UInt8 TPMS_PressureValue_FR;
    UInt8 TPMS_TireTempValue_FL;
    UInt8 TPMS_TireTempValue_FR;
    UInt8 BCM_TPMSResetSts;
    Boolean TMPS_AbnmPrsrWarn;
    Boolean TPMS_TempSts_RL;
    UInt8 TPMS_PressureSta_RL;
    Boolean TPMS_TempSts_RR;
    UInt8 TPMS_PressureSta_RR;
    UInt8 TPMS_PressureValue_RL;
    UInt8 TPMS_PressureValue_RR;
    UInt8 TPMS_TireTempValue_RL;
    UInt8 TPMS_TireTempValue_RR;
    UInt8 BCM_WiperCtrl_Front;
    Boolean BCM_WashLiquidLevelWarn;
    UInt8 BCM_DrvSeatOccupantSensorSts;
    Boolean BCM_HeavyRainInd;
    Boolean BCM_FrntWshrSwSig;
    Boolean BCM_Pas_wdw_Init;
    Boolean BCM_FrontWashSts;
    UInt8 BCM_WiprIntlGearSwtSig;
    UInt8 BCM_WiperSwSig;
    Boolean BCM_WinLockSts;
    Boolean BCM_WinLockSig;
    UInt8 BCM_DriverWinSwSig;
    UInt8 BCM_PassWinSwSig;
    Boolean BCM_FLWindowSts;
    Boolean BCM_FRWindowSts;
    UInt8 BCM_FLWindowmotorSts;
    UInt8 BCM_FRWindowmotorSts;
    UInt8 BCM_FrntLeDoorHndlSwt;
    UInt8 BCM_FrntRiDoorHndlSwt;
    Boolean BCM_TrunkSwtSig;
    Boolean BCM_WarnNoKeyFound;
    UInt8 BCM_BodyWarnSts;
    UInt8 BCM_PSAuthentRes;
    UInt8 BCM_ChrgLidLockReq;
    UInt8 BCM_RKEReq;
    Boolean BCM_KeyInCarSta;
    UInt8 BCM_DrvPEAuthentAcsd;
    UInt8 BCM_FRPEAuthentAcsd;
    Boolean BCM_PSReq;
    UInt8 BCM_WiprIntlTimeSetFb;
    UInt8 BCM_StartReq;
    UInt8 BCM_ChgWiperMtMdSwSetFb;
    Boolean BCM_ParkAutoUnlockSetFb;
    Boolean BCM_OverspdCntrlLockSetFb;
    Boolean BCM_TrunkLockSta;
    Boolean BCM_TrunkLockSwCtrlFb;
    UInt8 BCM_AuthentKeyNr;
    Boolean BCM_KeyFrbdn;
    UInt8 BCM_FrbdnKeyNr;
    UInt8 BCM_KeyIDFb;
    UInt16 BCM_KeyLocn;
    Boolean BCM_IllmndEntryStsFb;
    Boolean BCM_AvaluebleKeyInCar;
    Boolean BCM_KeyBattLvlSts;
    UInt16 BCM_KeyBattLvl;
    Boolean BCM_KeyLoBattLvlWarn;
    UInt8 BCM_KeySta;
    Boolean BCM_IllmndLampReq;
    UInt8 BCM_IllmndLockReq;
    Boolean BCM_IndicationShifttoNeutral;
    Boolean BCM_WarnKeyOutReminder;
    Boolean BCM_IndicationKeyCloser;
    UInt8 BCM_IllmndSts;
    Boolean BCM_SteerWhlHeatSts;
    UInt8 BCM_SteerWhlTemp;
    UInt8 BCM_MaiDrvrSeatTemp;
    Boolean BCM_RearMirrorHeatSts;
    UInt8 BCM_MaiDrvrSeatSts;
    UInt8 BCM_FrontWiperMotorSts;
    UInt8 BCM_LogoActiveFlag;
    Boolean BCM_VhclSeek;
    Boolean BCM_RFInitSta;
    UInt8 BCM_RiTurnLiFaultFb;
    UInt8 BCM_LeTurnLiFaultFb;
    Boolean BCM_FLWindowmotorFlags;
    Boolean BCM_FRWindowmotorFlags;
    UInt8 BCM_DrvPassWinSwSig;
    UInt8 BCM_DoorLockOperationRecord;
    Boolean BCM_LFInitSta;
    UInt8 DrvLfAnt_DiagStatus;
    UInt8 PassLfAnt_DiagStatus;
    UInt8 IntLfAnt_DiagStatus;
    UInt8 BCM_RearFogLiFaultFb;
    UInt8 BCM_PosLiFaultFb;
    UInt8 BCM_HighBeamLiFaultFb;
    UInt8 BCM_LowBeamLiFaultFb;
    UInt8 BCM_FrontFogLiFaultFb;
    UInt8 BCM_DayRunLiFaultFb;
    UInt8 BCM_ReverseLiFaultFb;
    UInt8 BCM_BrakeLiFaultFb;
    UInt8 BCM_BackLiFaultFb;
    Boolean BCM_DomeLightSta;
    Boolean BCM_CarriageLightSta;
    Boolean BCM_BackLampSta;
    Boolean BCM_WiperStopPosSta;
    Boolean BCM_SavePowerSta;
} BCM_B_Package_BAC;

#define _DEFINED_TYPEDEF_FOR_BCM_B_Package_BAC_

typedef struct
{
    UINT64 ESCL_UnOrLockCrtl;
} BCM_ESCLCommand_BOD;

#define _DEFINED_TYPEDEF_FOR_BCM_ESCLCommand_BOD_

typedef struct
{
    UInt8 BCM_HighFreqSigData_Byte0;
    UInt8 BCM_HighFreqSigData_Byte1;
    UInt8 BCM_HighFreqSigData_Byte2;
    UInt8 BCM_HighFreqSigData_Byte3;
    UInt8 BCM_HighFreqSigData_Byte4;
    UInt8 BCM_HighFreqSigData_Byte5;
    UInt8 BCM_HighFreqSigData_Byte6;
    UInt8 BCM_HighFreqSigData_Byte7;
    UInt8 BCM_HighFreqSigData_Byte8;
    UInt8 BCM_HighFreqSigData_Byte9;
    UInt8 BCM_HighFreqSigData_Byte10;
    UInt8 BCM_HighFreqSigData_Byte11;
    UInt8 BCM_HighFreqSigData_Byte12;
    UInt8 BCM_HighFreqSigData_Byte13;
    UInt8 BCM_HighFreqSigData_Byte14;
    UInt8 BCM_HighFreqSigData_Byte15;
} BCM_HFSData_BAC;

#define _DEFINED_TYPEDEF_FOR_BCM_HFSData_BAC_

typedef struct
{
    UInt8 BCM_Learning_subID;
    UInt8 BCM_Learning_Status;
    UInt8 BCM_Learning_Data_02;
    UInt8 BCM_Learning_Data_03;
    UInt8 BCM_Learning_Data_04;
    UInt8 BCM_Learning_Data_05;
    UInt8 BCM_Learning_Data_06;
    UInt8 BCM_Learning_Data_07;
} BCM_IMMOAuthResp1_EPT;

#define _DEFINED_TYPEDEF_FOR_BCM_IMMOAuthResp1_EPT_

typedef struct
{
    UInt8 BMS_10_AliveCnt;
    UInt8 BMS_10_Chksum;
    UInt8 BMS_DCS_ActOprtMode;
    UInt16 BMS_DCS_ActlChrgCurrent;
    UInt16 BMS_DCS_ActlChrgPower;
    UInt16 BMS_DCS_ActlChrgVoltage;
    Boolean BMS_DCS_InletConnectSta;
    UInt16 BMS_DC_AC_RemChrgTime;
} BMS_10_DC_ChargeStates_EPT;

#define _DEFINED_TYPEDEF_FOR_BMS_10_DC_ChargeStates_EPT_

typedef struct
{
    UInt8 BMS_1_AliveCnt;
    UInt8 BMS_1_Chksum;
    UInt16 BMS_ActlExchgCurnt;
    Boolean BMS_Batt_BalanceSta;
    UInt8 BMS_ChargeInterlockSta;
    Boolean BMS_Contactor_state_Negative;
    Boolean BMS_Contactor_state_Positive;
    Boolean BMS_Contactor_state_Precharge;
    UInt8 BMS_DisChargeInterlockSta;
    Boolean BMS_Emeshutdown_Req;
    UInt8 BMS_InsulationWrningDistgsh;
    UInt8 BMS_PwrTrainConnectSta;
    UInt8 BMS_RunState;
    UInt8 BMS_SupplyVoltageStatus;
    UInt8 BMS_SysFailSta;
    Boolean BMS_ThermRunawaySnsrFlt;
    Boolean BMS_ThermRunawayVlvSt;
    UInt8 BMS_ThermalrunawayWrn;
} BMS_1_MainState_EPT;

#define _DEFINED_TYPEDEF_FOR_BMS_1_MainState_EPT_

typedef struct
{
    UInt8 BMS_2_AliveCnt;
    UInt8 BMS_2_Chksum;
    UInt16 BMS_BatSOC_Actl;
    UInt16 BMS_BatSOC_Rpt;
    UInt16 BMS_BatSOH;
    UInt16 BMS_HVBatActlVoltage;
    Boolean BMS_HVBatActlVoltageV;
} BMS_2_BatState_EPT;

#define _DEFINED_TYPEDEF_FOR_BMS_2_BatState_EPT_

typedef struct
{
    UInt8 BMS_3_AliveCnt;
    UInt8 BMS_3_Chksum;
    Boolean BMS_Contactor_state_DCCharger;
    Boolean BMS_DCS_ChargeRequest;
    Boolean BMS_DCS_ChrgAPlus;
    Boolean BMS_Electronic_Lock_Ctrl;
    Boolean BMS_Electronic_Lock_State;
    UInt16 BMS_MaxAllowChrgCur_DC;
    UInt16 BMS_MaxAllowChrgVol_DC;
    UInt8 BMS_PCB_TempMax;
    UInt8 BMS_TempMax_DCChargeSocket;
} BMS_3_DC_ChargeState_EPT;

#define _DEFINED_TYPEDEF_FOR_BMS_3_DC_ChargeState_EPT_

typedef struct
{
    UInt8 BMS_4_AliveCnt;
    UInt8 BMS_4_Chksum;
    UInt8 BMS_ACChrgAtclSta;
    UInt8 BMS_InletCoolantActlTemp;
    Boolean BMS_InletCoolantActlTempValid;
    UInt16 BMS_IsoResistance;
    UInt16 BMS_MaxChrgCurrent_AC;
    UInt16 BMS_MaxChrgVoltage_AC;
    UInt8 BMS_OutletCoolantActlTemp;
    Boolean BMS_OutletCoolantActlTempValid;
} BMS_4_AC_ChargeState_EPT;

#define _DEFINED_TYPEDEF_FOR_BMS_4_AC_ChargeState_EPT_

typedef struct
{
    UInt8 BMS_5_AliveCnt;
    UInt8 BMS_5_Chksum;
    UInt8 BMS_HVBatCellTempAve;
    UInt8 BMS_HVBatCellTempMax;
    UInt8 BMS_HVBatCellTempMin;
    Boolean BMS_HVBatCellTempValid;
    UInt8 BMS_MaxTempProbeCod;
    UInt8 BMS_MinTempProbeCod;
} BMS_5_BatTemp_EPT;

#define _DEFINED_TYPEDEF_FOR_BMS_5_BatTemp_EPT_

typedef struct
{
    UInt16 BMS_MaxConDisCurnt;
    UInt16 BMS_MaxInstanDisCurnt;
    UInt16 BMS_PwrRecupMaxConChrgCurnt;
    UInt16 BMS_PwrRecupMaxInstanChrgCurnt;
} BMS_6_DischrgRecup_EPT;

#define _DEFINED_TYPEDEF_FOR_BMS_6_DischrgRecup_EPT_

typedef struct
{
    UInt16 BMS_CellVolAve;
    UInt16 BMS_CellVolMax;
    UInt16 BMS_CellVolMin;
    UInt8 BMS_MaxVolCellCod;
    UInt8 BMS_MinVolCellCod;
} BMS_7_CellVolt_EPT;

#define _DEFINED_TYPEDEF_FOR_BMS_7_CellVolt_EPT_

typedef struct
{
    UInt8 BMS_BatCapacity;
    UInt8 BMS_BatteryType;
    UInt8 BMS_HW_Version;
    UInt8 BMS_NomCellCap;
    UInt8 BMS_Pack_Identity;
    UInt8 BMS_SW_Version;
} BMS_9_BattInfo_EPT;

#define _DEFINED_TYPEDEF_FOR_BMS_9_BattInfo_EPT_

typedef struct
{
    UInt8 VBSW_WakeupReasn_enum;
    Boolean VBSW_ECURst_flg;
    UInt16 VBSW_RTCWupRmningT_min;
    Boolean VBSW_F1B1PwrOnReq_flg;
    Boolean VBSW_F1B1PwrOffReq_flg;
    Boolean VBSW_NetWorkWakeup_flg;
    Boolean VBSW_SrvClrDTCReq_flg;
    Boolean VBSW_DiagInitCmpl_flg;
} BSW2VCU_outputs;

#define _DEFINED_TYPEDEF_FOR_BSW2VCU_outputs_

typedef struct
{
    Boolean J64SavePwr;
} BatSaveCtl;

#define _DEFINED_TYPEDEF_FOR_BatSaveCtl_

typedef struct
{
    Boolean CCP_ACAutoKey;
    Boolean CCP_ACSwitchKey;
    Boolean CCP_AVASOffKey;
    Boolean CCP_AVHKey;
    Boolean CCP_AirInletModeKey;
    Boolean CCP_BlowerLevelAddKey;
    Boolean CCP_BlowerLvlDecreaseKey;
    Boolean CCP_BlowingModeNextKey;
    Boolean CCP_BlowingModePreviousKey;
    Boolean CCP_CentralLockKey;
    UInt8 CCP_Checksum;
    Boolean CCP_ESCOFFKey;
    Boolean CCP_FrontWindDefrostKey;
    Boolean CCP_HDCKey;
    Boolean CCP_HazardKey;
    Boolean CCP_ModeKey;
    Boolean CCP_PwrRecupLevelKey;
    Boolean CCP_RearViewMirrHeatingKey;
    UInt8 CCP_RollingCounter;
    Boolean CCP_TPMSKey;
    Boolean CCP_TempAddKey;
    Boolean CCP_TempDecreaseKey;
} CCP_PanelStatus_BOD;

#define _DEFINED_TYPEDEF_FOR_CCP_PanelStatus_BOD_

typedef struct
{
    UInt8 VCU_PTActlOprtMode;
    Boolean VCU_VhclActlGearPosV;
    UInt8 VCU_VhclActlGearPos;
    Boolean BCM_BrakePedalSta;
    Boolean BCM_SysPwrModeV;
    UInt8 BCM_SysPwrMode;
    UInt8 VCU_12VBatLowVolSta;
    Boolean VCU_LimpHomeSta;
    Boolean VCU_PCUFailSta;
    UInt8 BCM_CentralLockSts;
    UInt8 BCM_SysPowerSts;
    UInt8 VCU_PwrRecupIntensity;
    Boolean BCM_DoorLockSta_FL;
    UInt8 VCU_PrstlsStaFb;
    UInt8 VCU_VehActDrvMod1;
    Boolean CCU_DiagTesterOnline;
    UInt8 VCU_HDCStatus;
    UInt8 BCM_HazardLampSts;
    UInt8 BCM_BackLadjvalFb;
    Boolean BCM_PosLampSta;
} CCU_VehInfo_BAC;

#define _DEFINED_TYPEDEF_FOR_CCU_VehInfo_BAC_

typedef struct
{
    Boolean COMP_CANBusOff;
    UInt8 COMP_Checksum;
    Boolean COMP_Commu_Error;
    Boolean COMP_CurrentOffset;
    UInt8 COMP_EcompActSpd;
    UInt8 COMP_EcompST;
    UInt8 COMP_High_Voltage;
    UInt8 COMP_HvError;
    Boolean COMP_IPM_Error;
    UInt8 COMP_InputCurrent;
    Boolean COMP_LoseStep;
    UInt8 COMP_LvError;
    UInt8 COMP_OverCurrent;
    Boolean COMP_OverDuty;
    Boolean COMP_PI_Saturation;
    UInt8 COMP_RollingCounter;
    UInt8 COMP_SelfCheckError;
    Boolean COMP_TempError;
    UInt8 COMP_Temperature;
    Boolean ECUHighVoltInterlockSignal;
} COMP_AC_BOD;

#define _DEFINED_TYPEDEF_FOR_COMP_AC_BOD_

typedef struct
{
    UInt8 CRRR_A_AliveCnt1;
    UInt8 CRRR_A_Chksum1;
    Boolean CRRR_BSD_SetFb;
    UInt8 CRRR_BSD_Warn_Left;
    UInt8 CRRR_BSD_Warn_Right;
    Boolean CRRR_DOWSetFB;
    UInt8 CRRR_DOWWarnFL;
    UInt8 CRRR_DOWWarnFR;
    UInt8 CRRR_DOWWarnRL;
    UInt8 CRRR_DOWWarnRR;
    UInt8 CRRR_DOW_Warn_Left;
    UInt8 CRRR_DOW_Warn_Right;
    UInt8 CRRR_FOVChgSetFb;
    Boolean CRRR_RCTA_SetFb;
    UInt8 CRRR_RCTA_Warn_Left;
    UInt8 CRRR_RCTA_Warn_Right;
    UInt8 CRRR_RCTBDecelaration;
    Boolean CRRR_RCTBReq;
    Boolean CRRR_RCTB_BrkgVld;
    Boolean CRRR_RCW_SetFb;
    UInt8 CRRR_RCW_Warning;
    UInt8 CRRR_RearCornerBlindness;
    UInt8 CRRR_RearCornerFailure;
} CRRR_A_CHA;

#define _DEFINED_TYPEDEF_FOR_CRRR_A_CHA_

typedef struct
{
    Boolean VDAG_HUCRCChkFlt_flg;
    Boolean VDAG_ICUCRCChkFlt_flg;
    Boolean VDAG_TBOXCRCChkFlt_flg;
    Boolean VDAG_CCPCRCChkFlt_flg;
    Boolean VDAG_ACCMCRCChkFlt_flg;
    Boolean VDAG_PTCCRCChkFlt_flg;
    Boolean VDAG_SCSCRCChkFlt_flg;
    Boolean VDAG_CRRRCRCChkFlt_flg;
    Boolean VDAG_EHBCRCChkFlt_flg;
    Boolean VDAG_EPSCRCChkFlt_flg;
    Boolean VDAG_ESCCRCChkFlt_flg;
    Boolean VDAG_FCMCRCChkFlt_flg;
    Boolean VDAG_PPCRCChkFlt_flg;
    Boolean VDAG_SRSCRCChkFlt_flg;
    Boolean VDAG_BMSCRCChkFlt_flg;
    Boolean VDAG_INVCRCChkFlt_flg;
    Boolean VDAG_IPUCRCChkFlt_flg;
} DAG_Comm_outputs;

#define _DEFINED_TYPEDEF_FOR_DAG_Comm_outputs_

typedef struct
{
    Boolean VDAG_DCCCmdTmOutErrFlg_flg;
    Boolean VDAG_DCCSysFailLvl1ErrFlg_flg;
    Boolean VDAG_DCCSysFailLvl2ErrFlg_flg;
    Boolean VDAG_DCCSysFailLvl3ErrFlg_flg;
    Boolean VDAG_DCCSysFailLvl4ErrFlg_flg;
    Boolean VDAG_DCCModeFltErrFlg_flg;
    Boolean VDAG_DCCInVoltLoErrFlg_flg;
    Boolean VDAG_INVInVoltLoErrFlg_flg;
} DAG_DCC_outputs;

#define _DEFINED_TYPEDEF_FOR_DAG_DCC_outputs_

typedef struct
{
    Boolean VDAG_FbdDrvTq_flg;
    Boolean VDAG_LimpHome_flg;
    Boolean VDAG_LmtDrvTq_flg;
    Boolean VDAG_FbdDRGr_flg;
    Boolean VDAG_FbdCC_flg;
    Boolean VDAG_FbdLSP_flg;
    Boolean VDAG_FbdACC_flg;
    Boolean VDAG_FbdHV_flg;
    Boolean VDAG_EmgcyShtdwn_flg;
    Boolean VDAG_FbdDCDC_flg;
    Boolean VDAG_FbdACChrg_flg;
    Boolean VDAG_FbdDCChrg_flg;
    Boolean VDAG_FbdACDcha_flg;
    Boolean VDAG_FbdAC_flg;
    Boolean VDAG_FltLampOn_flg;
    Boolean VDAG_LVBatLampOn_flg;
    Boolean VDAG_FanFullSpdOn_flg;
    Boolean VDAG_FbdHDC_flg;
} DAG_FltActn_outputs;

#define _DEFINED_TYPEDEF_FOR_DAG_FltActn_outputs_

typedef struct
{
    Boolean VDAG_LVBattSOCLoErrFlg_flg;
    Boolean VDAG_LVBattSOHLoErrFlg_flg;
    Boolean VDAG_LVBattTempHiErrFlg_flg;
    Boolean VDAG_LVBattVoltLoErrFlg_flg;
    Boolean VDAG_LVBattVoltHiErrFlg_flg;
} DAG_Other_outputs;

#define _DEFINED_TYPEDEF_FOR_DAG_Other_outputs_

typedef struct
{
    Boolean VDAG_AccPed1SuplyShtCircErrFlg_flg;
    Boolean VDAG_AccPed2SuplyShtCircErrFlg_flg;
    Boolean VDAG_AccPed1ShtGndErrFlg_flg;
    Boolean VDAG_AccPed1ShtBattErrFlg_flg;
    Boolean VDAG_AccPed2ShtGndErrFlg_flg;
    Boolean VDAG_AccPed2ShtBattErrFlg_flg;
    Boolean VDAG_AccPedCrsChkErrFlg_flg;
    Boolean VDAG_AccPedBothFailErrFlg_flg;
    Boolean VDAG_VehCrashErrFlg_flg;
} DAG_Sensor10ms_outputs;

#define _DEFINED_TYPEDEF_FOR_DAG_Sensor10ms_outputs_

typedef struct
{
    Boolean VDAG_WaterTempBlwThrErrFlg_flg;
    Boolean VDAG_WaterTempAbvThrErrFlg_flg;
} DAG_Sensor50ms_outputs;

#define _DEFINED_TYPEDEF_FOR_DAG_Sensor50ms_outputs_

typedef struct
{
    Float VDSA_DrvSprtIdx_pct;
} DSA_outputs;

#define _DEFINED_TYPEDEF_FOR_DSA_outputs_

typedef struct
{
    UInt8 BCM_TurnLampSta_Left;
    UInt8 BCM_TurnLampSta_Right;
    UInt8 BCM_FogLampSta_Rear;
    UInt8 BCM_PosLampSta;
    UInt8 BCM_HazardLampSts;
    UInt8 BCM_HighBeamSta;
    UInt8 BCM_LowBeamSta;
    UInt8 BCM_FogLampSta_Front;
    UInt8 BCM_AutoLampStatus;
    UInt8 BCM_DayRunLightSta;
    UInt8 BCM_ReverseLampSta;
    UInt8 BCM_BrakeLampSta;
    UInt8 BCM_DayRunLiSwSig;
    UInt8 BCM_TurnLiSts;
    UInt8 BCM_TurnngLiSwSig;
    UInt8 BCM_LightIntensity;
    UInt8 BCM_LightSwSig;
    UInt8 BCM_HighBeamSwSig;
    UInt8 BCM_AjarStaV_Hood;
    UInt8 BCM_AjarSta_Hood;
    UInt8 BCM_HazardWarningLightSwSig;
    UInt8 BCM_FrntFogLiSwSig;
    UInt8 BCM_RearFogLiSwSig;
    UInt8 BCM_FlwrMeHmCtrlFb;
    UInt8 BCM_BassHornReq;
    UInt8 BCM_AjarSta_Trunk;
    UInt8 BCM_DoorAjarSta_FL;
    UInt8 BCM_DoorAjarSta_FR;
    UInt8 BCM_DoorAjarSta_RL;
    UInt8 BCM_DoorAjarSta_RR;
    UInt8 BCM_LockHornOnStFb;
    UInt8 BCM_AlrmHornReq;
    UInt8 BCM_WiperCtrl_Front;
    UInt8 BCM_WashLiquidLevelWarn;
    UInt8 BCM_DrvSeatOccupantSensorSts;
    UInt8 BCM_FrntWshrSwSig;
    UInt8 BCM_FrontWashSts;
    UInt8 BCM_WiprIntlGearSwtSig;
    UInt8 BCM_WiperSwSig;
    UInt8 BCM_WinLockSts;
    UInt8 BCM_WinLockSig;
    UInt8 BCM_DriverWinSwSig;
    UInt8 BCM_PassWinSwSig;
    UInt8 BCM_FLWindowSts;
    UInt8 BCM_FRWindowSts;
    UInt8 BCM_FLWindowmotorSts;
    UInt8 BCM_FRWindowmotorSts;
    UInt8 BCM_FrontWiperMotorSts;
    UInt8 BCM_FrntLeDoorHndlSwt;
    UInt8 BCM_FrntRiDoorHndlSwt;
    UInt8 BCM_TrunkSwtSig;
    UInt8 BCM_WarnNoKeyFound;
    UInt8 BCM_BodyWarnSts;
    UInt8 BCM_PSAuthentRes;
    UInt8 BCM_ChrgLidLockReq;
    UInt8 BCM_RKEReq;
    UInt8 BCM_KeyInCarSta;
    UInt8 BCM_DrvPEAuthentAcsd;
    UInt8 BCM_FRPEAuthentAcsd;
    UInt8 BCM_PSReq;
    UInt8 BCM_WiprIntlTimeSetFb;
    UInt8 BCM_StartReq;
    UInt8 BCM_ChgWiperMtMdSwSetFb;
    UInt8 BCM_ParkAutoUnlockSetFb;
    UInt8 BCM_OverspdCntrlLockSetFb;
    UInt8 BCM_TrunkLockSta;
    UInt8 BCM_TrunkLockSwCtrlFb;
    UInt8 BCM_AuthentKeyNr;
    UInt8 BCM_KeyFrbdn;
    UInt8 BCM_FrbdnKeyNr;
    UInt8 BCM_KeyIDFb;
    UInt8 BCM_KeyLocn;
    UInt8 BCM_IllmndEntryStsFb;
    UInt8 BCM_AvaluebleKeyInCar;
    UInt8 BCM_KeyBattLvlSts;
    UInt8 BCM_KeyBattLvl;
    UInt8 BCM_KeyLoBattLvlWarn;
    UInt8 BCM_KeySta;
    UInt8 BCM_IllmndLampReq;
    UInt8 BCM_IllmndLockReq;
    UInt8 BCM_IndicationShifttoNeutral;
    UInt8 BCM_WarnKeyOutReminder;
    UInt8 BCM_IndicationKeyCloser;
    UInt8 BCM_IllmndSts;
    UInt8 BCM_SteerWhlHeatSts;
    SInt8 BCM_SteerWhlTemp;
    SInt8 BCM_MaiDrvrSeatTemp;
    UInt8 BCM_RearMirrorHeatSts;
    UInt8 BCM_BackLadjvalFb;
    UInt8 BCM_MaiDrvrSeatSts;
    UInt8 BCM_BrakePedalSta;
    UInt8 BCM_SysPwrMode;
    UInt8 BCM_SysPwrModeV;
    UInt8 BCM_CentralLockSwCtrlFb;
    UInt8 BCM_CentralLockSts;
    UInt8 BCM_SysPowerSts;
    UInt8 BCM_DoorLockSta_FL;
    UInt8 BCM_HighFreqSigData_Byte0;
    UInt8 BCM_HighFreqSigData_Byte1;
    UInt8 BCM_HighFreqSigData_Byte2;
    UInt8 BCM_HighFreqSigData_Byte3;
    UInt8 BCM_HighFreqSigData_Byte4;
    UInt8 BCM_HighFreqSigData_Byte5;
    UInt8 BCM_HighFreqSigData_Byte6;
    UInt8 BCM_HighFreqSigData_Byte7;
    UInt8 BCM_HighFreqSigData_Byte8;
    UInt8 BCM_HighFreqSigData_Byte9;
    UInt8 BCM_HighFreqSigData_Byte10;
    UInt8 BCM_HighFreqSigData_Byte11;
    UInt8 BCM_HighFreqSigData_Byte12;
    UInt8 BCM_HighFreqSigData_Byte13;
    UInt8 BCM_HighFreqSigData_Byte14;
    UInt8 BCM_HighFreqSigData_Byte15;
    UInt8 BCM_IllmndLockStsFb;
    UInt8 BCM_IllmndUnlockStsFb;
    UInt8 BCM_LogoActiveFlag;
    UInt8 BCM_VhclSeek;
    UInt8 BCM_RFInitSta;
    UInt8 BCM_RiTurnLiFaultFb;
    UInt8 BCM_LeTurnLiFaultFb;
    UInt8 BCM_BackLiFaultFb;
    UInt8 BCM_BrakeLiFaultFb;
    UInt8 BCM_DayRunLiFaultFb;
    UInt8 BCM_DoorLockOperationRecord;
    UInt8 BCM_DrvPassWinSwSig;
    Boolean BCM_FLWindowmotorFlags;
    Boolean BCM_FRWindowmotorFlags;
    UInt8 BCM_FrontFogLiFaultFb;
    UInt8 BCM_HighBeamLiFaultFb;
    Boolean BCM_LFInitSta;
    UInt8 BCM_LowBeamLiFaultFb;
    UInt8 BCM_PosLiFaultFb;
    UInt8 BCM_RearFogLiFaultFb;
    UInt8 BCM_ReverseLiFaultFb;
    UInt8 DrvLfAnt_DiagStatus;
    UInt8 IntLfAnt_DiagStatus;
    UInt8 PassLfAnt_DiagStatus;
    UInt8 CCU_RemoteCarSearchFb;
    UInt8 CCU_RemoteLockFb;
    UInt8 CCU_RemotePowerLockFb;
    UInt8 CCU_RemtMaiDrSeatHeatFb;
    UInt8 CCU_RemtPowerCtrlFb;
    UInt8 CCU_RemtSteerWhlHeatFb;
    UInt8 BCM_WiperStopPosSta;
    UInt8 BCM_DomeLightSta;
    UInt8 BCM_CarriageLightSta;
    UInt8 BCM_BackLampSta;
    UInt8 BCM_SavePowerSta;
} DT_Bcm2OpmBAC_outputs;

#define _DEFINED_TYPEDEF_FOR_DT_Bcm2OpmBAC_outputs_

typedef struct
{
    UInt8 BCM_Learning_subID;
    UInt8 BCM_Learning_Status;
    UInt8 BCM_Learning_Data_02;
    UInt8 BCM_Learning_Data_03;
    UInt8 BCM_Learning_Data_04;
    UInt8 BCM_Learning_Data_05;
    UInt8 BCM_Learning_Data_06;
    UInt8 BCM_Learning_Data_07;
} DT_Bcm2OpmEPT_outputs;

#define _DEFINED_TYPEDEF_FOR_DT_Bcm2OpmEPT_outputs_

typedef struct
{
    UINT64 ESCL_UnOrLockCrtl;
} DT_Bcm2OpmOBD_outputs;

#define _DEFINED_TYPEDEF_FOR_DT_Bcm2OpmOBD_outputs_

typedef struct
{
    UInt8 BCM_SysPwrMode;
    UInt8 BCM_SysPwrModeV;
    UInt8 BCM_SysPowerSts;
    UInt8 BCM_StartReq;
    UInt8 BCM_DoorAjarSta_FL;
    UInt8 BCM_DoorAjarSta_FR;
    UInt8 BCM_DoorAjarSta_RL;
    UInt8 BCM_DoorAiarSta_RR;
    UInt8 AppSwcBcmVersion;
    UInt8 BCM_NMReq_flg;
    UInt8 BCM_SleepAllwd_flg;
    UInt8 BCM_RearMirrorHeatSts;
    UInt8 BCM_BodyWarnSts;
} DT_Bcm2VcuTms_outputs;

#define _DEFINED_TYPEDEF_FOR_DT_Bcm2VcuTms_outputs_

typedef struct
{
    Boolean VIPM_HU_B_CRCFlt_flg;
    Boolean VIPM_ICU_Info_CRCFlt_flg;
    Boolean VIPM_TBOX_BJS_Time_CRCFlt_flg;
    Boolean VIPM_CCP_PanelStatus_CRCFlt_flg;
    Boolean VIPM_COMP_AC_CRCFlt_flg;
    Boolean VIPM_HVCH_Status1_CRCFlt_flg;
    Boolean VIPM_SCS_RiSwitchSts_CRCFlt_flg;
    Boolean VIPM_CRRR_A_CRCFlt_flg;
    Boolean VIPM_EHB_B_CRCFlt_flg;
    Boolean VIPM_EPS_2_StrWhlAng_CRCFlt_flg;
    Boolean VIPM_ESC_7_FuncStatus_CRCFlt_flg;
    Boolean VIPM_FCM_B_CRCFlt_flg;
    Boolean VIPM_PP_InformAndStatus_CRCFlt_flg;
    Boolean VIPM_SRS_1_Status_CRCFlt_flg;
    Boolean VIPM_BMS_2_BatState_CRCFlt_flg;
    Boolean VIPM_INV_1_Value_CRCFlt_flg;
    Boolean VIPM_IPU_DCC_1_State_CRCFlt_flg;
} DT_CANCommCRCFlt;

#define _DEFINED_TYPEDEF_FOR_DT_CANCommCRCFlt_

typedef struct
{
    Boolean VIPM_BACCANBusOff_flg;
    Boolean VIPM_EPTCANBusOff_flg;
    Boolean VIPM_CHACANBusOff_flg;
    Boolean VIPM_BODCANBusOff_flg;
    Boolean VIPM_BMSLostComm_flg;
    Boolean VIPM_ESCLostComm_flg;
    Boolean VIPM_FCMLostComm_flg;
    Boolean VIPM_CRRRLostComm_flg;
    Boolean VIPM_PPLostComm_flg;
    Boolean VIPM_EPSLostComm_flg;
    Boolean VIPM_SRSLostComm_flg;
    Boolean VIPM_ICULostComm_flg;
    Boolean VIPM_TBOXLostComm_flg;
    Boolean VIPM_MCULostComm_flg;
    Boolean VIPM_ACCMLostComm_flg;
    Boolean VIPM_PTCLostComm_flg;
    Boolean VIPM_CDCLostComm_flg;
    Boolean VIPM_IPULostComm_flg;
    Boolean VIPM_EHBLostComm_flg;
    Boolean VIPM_SCSLostComm_flg;
    Boolean VIPM_CCPLostComm_flg;
} DT_CANCommErr;

#define _DEFINED_TYPEDEF_FOR_DT_CANCommErr_

typedef struct
{
    UInt16 VIPM_HwKL30_mV;
    Boolean VIPM_HwKL15A_flg;
    Boolean VIPM_HwKL15B_flg;
    Float VIPM_HwAccPedCh1Volt_mV;
    Float VIPM_HwAccPedCh2Volt_mV;
    Float VIPM_HwAccPedCh1SuplyVolt_mV;
    Float VIPM_HwAccPedCh2SuplyVolt_mV;
    Boolean VIPM_HwDrvModeSw_flg;
    UInt8 VIPM_HwShftPstnSwSts_enum;
    Boolean VIPM_HwRearFogLampSwt_flg;
    Boolean VIPM_HwBrkSwHi_flg;
    Boolean VIPM_HwBrkSwLo_flg;
    Boolean VIPM_HwOBCWakeup_flg;
    Boolean VIPM_HwBMSWakeup_flg;
    Boolean VIPM_HwEmgcyShutOff_flg;
    Boolean VIPM_HwVehCrash_flg;
    Boolean VIPM_HwCrpModeSw_flg;
    Float VIPM_HwHVIL1Volt_mV;
    Float VIPM_HwHVIL2Volt_mV;
} DT_HardWire_Input_VCU;

#define _DEFINED_TYPEDEF_FOR_DT_HardWire_Input_VCU_

typedef struct
{
    UInt8 VIPM_ClientNum_enum;
    Boolean VIPM_ClientNumVld_flg;
    UInt8 VIPM_APPVerMax_enum;
    Boolean VIPM_APPVerMaxVld_flg;
    UInt8 VIPM_APPVerMin_enum;
    Boolean VIPM_APPVerMinVld_flg;
    UInt8 VIPM_HwVerMax_enum;
    Boolean VIPM_HwVerMaxVld_flg;
    UInt8 VIPM_HwVerMin_enum;
    Boolean VIPM_HwVerMinVld_flg;
    UInt8 VIPM_BootVer_enum;
    Boolean VIPM_BootVerVld_flg;
} DT_IPM_ACCM_Version_BOD;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_ACCM_Version_BOD_

typedef struct
{
    Boolean VIPM_BMSDCSInletConnectSta_flg;
    Boolean VIPM_BMSDCSInletConnectStaVld_flg;
    UInt8 VIPM_BMSDCSActOprtMode_enum;
    Boolean VIPM_BMSDCSActOprtModeVld_flg;
} DT_IPM_BMS_10_DC_ChargeStates_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_BMS_10_DC_ChargeStates_EPT_

typedef struct
{
    UInt8 VIPM_BMSThermrunawayWrn_enum;
    Boolean VIPM_BMSThermrunawayWrnVld_flg;
    UInt8 VIPM_BMSDchrgInterlockSta_enum;
    Boolean VIPM_BMSDchrgInterlockStaVld_flg;
    UInt8 VIPM_BMSChrgInterlockSta_enum;
    Boolean VIPM_BMSChrgInterlockStaVld_flg;
    Float VIPM_BMSActExchgCurnt_A;
    Boolean VIPM_BMSActExchgCurntVld_flg;
    Boolean VIPM_BMSEmgcySdnReq_flg;
    Boolean VIPM_BMSEmgcySdnReqVld_flg;
    UInt8 VIPM_BMSSysFailSta_enum;
    Boolean VIPM_BMSSysFailStaVld_flg;
    UInt8 VIPM_BMSPwrTrainConnectSta_enum;
    Boolean VIPM_BMSPwrTrainConnectStaVld_flg;
    UInt8 VIPM_BMSRunSta_enum;
    Boolean VIPM_BMSRunStaVld_flg;
} DT_IPM_BMS_1_MainState_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_BMS_1_MainState_EPT_

typedef struct
{
    Float VIPM_BMSBatSOCRpt_pct;
    Boolean VIPM_BMSBatSOCRptVld_flg;
    Float VIPM_BMSBatSOH_pct;
    Boolean VIPM_BMSBatSOHVld_flg;
    Float VIPM_BMSHVBatActVolt_V;
    Boolean VIPM_BMSHVBatActVoltVld_flg;
    Float VIPM_BMSBatSOCAct_pct;
    Boolean VIPM_BMSBatSOCActVld_flg;
} DT_IPM_BMS_2_BatState_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_BMS_2_BatState_EPT_

typedef struct
{
    Boolean VIPM_BMSDCSChrgReq_flg;
    Boolean VIPM_BMSDCSChrgReqVld_flg;
} DT_IPM_BMS_3_DC_ChargeState_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_BMS_3_DC_ChargeState_EPT_

typedef struct
{
    UInt8 VIPM_BMSACChrgAtclSta_enum;
    Boolean VIPM_BMSACChrgAtclStaVld_flg;
    Float VIPM_BMSOutlCooltActlTemp_C;
    Boolean VIPM_BMSOutlCooltActlTempVld_flg;
    Float VIPM_BMSInletCooltActlTemp_C;
    Boolean VIPM_BMSInletCooltActlTempVld_flg;
    Float VIPM_BMSIsoResist_MOhm;
    Boolean VIPM_BMSIsoResistVld_flg;
    Float VIPM_BMSMaxChrgVoltAC_V;
    Boolean VIPM_BMSMaxChrgVoltACVld_flg;
    Float VIPM_BMSMaxChrgCurntAC_A;
    Boolean VIPM_BMSMaxChrgCurntACVld_flg;
} DT_IPM_BMS_4_AC_ChargeState_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_BMS_4_AC_ChargeState_EPT_

typedef struct
{
    Float VIPM_BMSHVBatCellTempAve_C;
    Boolean VIPM_BMSHVBatCellTempAveVld_flg;
    Float VIPM_BMSHVBatCellTempMax_C;
    Boolean VIPM_BMSHVBatCellTempMaxVld_flg;
    Float VIPM_BMSHVBatCellTempMin_C;
    Boolean VIPM_BMSHVBatCellTempMinVld_flg;
} DT_IPM_BMS_5_BatTemp_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_BMS_5_BatTemp_EPT_

typedef struct
{
    Float VIPM_BMSMaxConDisCurnt_A;
    Boolean VIPM_BMSMaxConDisCurntVld_flg;
    Float VIPM_BMSMaxInsDisCurnt_A;
    Boolean VIPM_BMSMaxInsDisCurntVld_flg;
    Float VIPM_BMSMaxConChrgCurnt_A;
    Boolean VIPM_BMSMaxConChrgCurntVld_flg;
    Float VIPM_BMSMaxInsChrgCurnt_A;
    Boolean VIPM_BMSMaxInsChrgCurntVld_flg;
} DT_IPM_BMS_6_DischrgRecup_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_BMS_6_DischrgRecup_EPT_

typedef struct
{
    Float VIPM_BMSCellVoltMax_mV;
    Boolean VIPM_BMSCellVoltMaxVld_flg;
    Float VIPM_BMSCellVoltMin_mV;
    Boolean VIPM_BMSCellVoltMinVld_flg;
} DT_IPM_BMS_7_CellVolt_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_BMS_7_CellVolt_EPT_

typedef struct
{
    UInt8 VIPM_BMSPackID_enum;
    Boolean VIPM_BMSPackIDVld_flg;
    UInt8 VIPM_BMSBatCapcty_Ah;
    Boolean VIPM_BMSBatCapctyVld_flg;
} DT_IPM_BMS_9_BattInfo_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_BMS_9_BattInfo_EPT_

typedef struct
{
    Boolean VIPM_CCPTempAddKey_flg;
    Boolean VIPM_CCPTempAddKeyVld_flg;
    Boolean VIPM_CCPTempDecKey_flg;
    Boolean VIPM_CCPTempDecKeyVld_flg;
    Boolean VIPM_CCPBlwrLvlAddKey_flg;
    Boolean VIPM_CCPBlwrLvlAddKeyVld_flg;
    Boolean VIPM_CCPBlwrLvlDecKey_flg;
    Boolean VIPM_CCPBlwrLvlDecKeyVld_flg;
    Boolean VIPM_CCPBlwngModeNextKey_flg;
    Boolean VIPM_CCPBlwngModeNextKeyVld_flg;
    Boolean VIPM_CCPBlwngModePrevKey_flg;
    Boolean VIPM_CCPBlwngModePrevKeyVld_flg;
    Boolean VIPM_CCPACSwKey_flg;
    Boolean VIPM_CCPACSwKeyVld_flg;
    Boolean VIPM_CCPACAutoKey_flg;
    Boolean VIPM_CCPACAutoKeyVld_flg;
    Boolean VIPM_CCPRrViewMirrHeatgKey_flg;
    Boolean VIPM_CCPRrViewMirrHeatgKeyVld_flg;
    Boolean VIPM_CCPAirInletModeKey_flg;
    Boolean VIPM_CCPAirInletModeKeyVld_flg;
    Boolean VIPM_CCPFrntWindDefrstKey_flg;
    Boolean VIPM_CCPFrntWindDefrstKeyVld_flg;
    Boolean VIPM_CCPModeKey_flg;
    Boolean VIPM_CCPModeKeyVld_flg;
    Boolean VIPM_CCPHzrdKey_flg;
    Boolean VIPM_CCPHzrdKeyVld_flg;
    Boolean VIPM_CCPCenLckKey_flg;
    Boolean VIPM_CCPCenLckKeyVld_flg;
    Boolean VIPM_CCPTPMSKey_flg;
    Boolean VIPM_CCPTPMSKeyVld_flg;
    Boolean VIPM_CCPESCOffKey_flg;
    Boolean VIPM_CCPESCOffKeyVld_flg;
    Boolean VIPM_CCPAVASOffKey_flg;
    Boolean VIPM_CCPAVASOffKeyVld_flg;
    Boolean VIPM_CCPHDCKey_flg;
    Boolean VIPM_CCPHDCKeyVld_flg;
    Boolean VIPM_CCPAVHKey_flg;
    Boolean VIPM_CCPAVHKeyVld_flg;
    Boolean VIPM_CCPPwrRecupLvlKey_flg;
    Boolean VIPM_CCPPwrRecupLvlKeyVld_flg;
} DT_IPM_CCP_PanelStatus_BOD;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_CCP_PanelStatus_BOD_

typedef struct
{
    Boolean VIPM_COMPOverDuty_flg;
    Boolean VIPM_COMPOverDutyVld_flg;
    Boolean VIPM_COMPCommuError_flg;
    Boolean VIPM_COMPCommuErrorVld_flg;
    Boolean VIPM_COMPPISaturation_flg;
    Boolean VIPM_COMPPISaturationVld_flg;
    Boolean VIPM_COMPLoseStep_flg;
    Boolean VIPM_COMPLoseStepVld_flg;
    UInt8 VIPM_COMPSelfChkErr_enum;
    Boolean VIPM_COMPSelfChkErrVld_flg;
    Boolean VIPM_COMPIPMErr_flg;
    Boolean VIPM_COMPIPMErrVld_flg;
    Boolean VIPM_COMPTempErr_flg;
    Boolean VIPM_COMPTempErrVld_flg;
    UInt8 VIPM_COMPLvErr_enum;
    Boolean VIPM_COMPLvErrVld_flg;
    UInt8 VIPM_COMPHvErr_enum;
    Boolean VIPM_COMPHvErrVld_flg;
    UInt8 VIPM_COMPOvrCurr_enum;
    Boolean VIPM_COMPOvrCurrVld_flg;
    UInt8 VIPM_COMPEcompST_enum;
    Boolean VIPM_COMPEcompSTVld_flg;
    Boolean VIPM_COMPCurrOfst_flg;
    Boolean VIPM_COMPCurrOfstVld_flg;
    Boolean VIPM_COMPCANBusOff_flg;
    Boolean VIPM_COMPCANBusOffVld_flg;
    Boolean VIPM_ECUHiVoltInterlockSig_flg;
    Boolean VIPM_ECUHiVoltInterlockSigVld_flg;
    Float VIPM_COMPTemp_C;
    Boolean VIPM_COMPTempVld_flg;
    Float VIPM_COMPInCurr_A;
    Boolean VIPM_COMPInCurrVld_flg;
    Float VIPM_COMPHiVolt_V;
    Boolean VIPM_COMPHiVoltVld_flg;
    Float VIPM_COMPEcompActSpd_rpm;
    Boolean VIPM_COMPEcompActSpdVld_flg;
} DT_IPM_COMP_AC_BOD;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_COMP_AC_BOD_

typedef struct
{
    UInt8 VIPM_CRRRBSDWarnLt_enum;
    Boolean VIPM_CRRRBSDWarnLtVld_flg;
    UInt8 VIPM_CRRRBSDWarnRt_enum;
    Boolean VIPM_CRRRBSDWarnRtVld_flg;
    UInt8 VIPM_CRRRDOWWarnLt_enum;
    Boolean VIPM_CRRRDOWWarnLtVld_flg;
    UInt8 VIPM_CRRRDOWWarnRt_enum;
    Boolean VIPM_CRRRDOWWarnRtVld_flg;
    UInt8 VIPM_CRRRRCTAWarnLt_enum;
    Boolean VIPM_CRRRRCTAWarnLtVld_flg;
    UInt8 VIPM_CRRRRCTAWarnRt_enum;
    Boolean VIPM_CRRRRCTAWarnRtVld_flg;
} DT_IPM_CRRR_A_CHA;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_CRRR_A_CHA_

typedef struct
{
    UInt8 VIPM_EHBEPBActuatorStL_enum;
    Boolean VIPM_EHBEPBActuatorStLVld_flg;
    UInt8 VIPM_EHBEPBSwitchSts_enum;
    Boolean VIPM_EHBEPBSwitchStsVld_flg;
    UInt8 VIPM_EHBEPBSysSt_enum;
    Boolean VIPM_EHBEPBSysStVld_flg;
    Boolean VIPM_EHBHDCFucFault_flg;
    Boolean VIPM_EHBHDCFucFaultVld_flg;
    UInt8 VIPM_EHBAVHAppldSt_enum;
    Boolean VIPM_EHBAVHAppldStVld_flg;
    Boolean VIPM_EHBBLA_flg;
    Boolean VIPM_EHBBLAVld_flg;
} DT_IPM_EHB_A_CHA;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_EHB_A_CHA_

typedef struct
{
    UInt8 VIPM_EHBEPBDynAppSt_enum;
    Boolean VIPM_EHBEPBDynAppStVld_flg;
    Float VIPM_EHBBrkPedlValPerc_pct;
    Boolean VIPM_EHBBrkPedlValPercVld_flg;
    UInt8 VIPM_EHBFltLvl_enum;
    Boolean VIPM_EHBFltLvlVld_flg;
    Boolean VIPM_EHBReqBrkLiOn_flg;
    Boolean VIPM_EHBReqBrkLiOnVld_flg;
    Float VIPM_EHBBrkPwrRecupTarWhlTq_Nm;
    Boolean VIPM_EHBBrkPwrRecupTarWhlTqVld_flg;
    UInt8 VIPM_EHBBrkPwrRecupTarWhlTqSts_enum;
    Boolean VIPM_EHBBrkPwrRecupTarWhlTqStsVld_flg;
    UInt8 VIPM_EHBEPBActuatorStR_enum;
    Boolean VIPM_EHBEPBActuatorStRVld_flg;
    Boolean VIPM_EHBCDDActv_flg;
    Boolean VIPM_EHBCDDActvVld_flg;
} DT_IPM_EHB_B_CHA;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_EHB_B_CHA_

typedef struct
{
    Float VIPM_EPSSteerWhlAng_deg;
    Boolean VIPM_EPSSteerWhlAngVld_flg;
    Float VIPM_EPSRotSpd_degps;
    Boolean VIPM_EPSRotSpdVld_flg;
    Boolean VIPM_EPSSteerWhlAngCald_flg;
    Boolean VIPM_EPSSteerWhlAngCaldVld_flg;
    Boolean VIPM_EPSSteerWhlAngFailr_flg;
    Boolean VIPM_EPSSteerWhlAngFailrVld_flg;
} DT_IPM_EPS_2_StrWhlAng_CHA;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_EPS_2_StrWhlAng_CHA_

typedef struct
{
    UINT64 VIPM_ESCLUnOrLockfeedback_nu;
    Boolean VIPM_ESCLUnOrLockfeedbackVld_flg;
} DT_IPM_ESCL_ESCLStatus_BOD;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_ESCL_ESCLStatus_BOD_

typedef struct
{
    Boolean VIPM_ESCABSActvSta_flg;
    Boolean VIPM_ESCABSActvStaVld_flg;
    Float VIPM_ESCVehSpd_kph;
    Boolean VIPM_ESCVehSpdVld_flg;
    Boolean VIPM_ESCTCSActvSta_flg;
    Boolean VIPM_ESCTCSActvStaVld_flg;
    Boolean VIPM_ESCESPActvSta_flg;
    Boolean VIPM_ESCESPActvStaVld_flg;
    Boolean VIPM_ESCReqBrkLghtOn_flg;
    Boolean VIPM_ESCReqBrkLghtOnVld_flg;
    Boolean VIPM_ESCCDPActv_flg;
    Boolean VIPM_ESCCDPActvVld_flg;
    Boolean VIPM_ESCESSActv_flg;
    Boolean VIPM_ESCESSActvVld_flg;
    Boolean VIPM_ESCEBDActv_flg;
    Boolean VIPM_ESCEBDActvVld_flg;
    UInt8 VIPM_ESCFltLvl_enum;
    Boolean VIPM_ESCFltLvlVld_flg;
    Float VIPM_ESCSlopPct_pct;
    Boolean VIPM_ESCSlopPctVld_flg;
} DT_IPM_ESC_7_FuncStatus_CHA;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_ESC_7_FuncStatus_CHA_

typedef struct
{
    UInt8 VIPM_ESCVehStandStillSta_enum;
    Boolean VIPM_ESCVehStandStillStaVld_flg;
    UInt8 VIPM_ESCWhlDirctnFL_enum;
    Boolean VIPM_ESCWhlDirctnFLVld_flg;
    Float VIPM_ESCWhlSpdKphFL_kph;
    Boolean VIPM_ESCWhlSpdKphFLVld_flg;
    UInt8 VIPM_ESCWhlDirctnFR_enum;
    Boolean VIPM_ESCWhlDirctnFRVld_flg;
    Float VIPM_ESCWhlSpdKphFR_kph;
    Boolean VIPM_ESCWhlSpdKphFRVld_flg;
    Float VIPM_ESCMstrCylPresr_bar;
    Boolean VIPM_ESCMstrCylPresrVld_flg;
    UInt8 VIPM_ESCWhlDirctnRL_enum;
    Boolean VIPM_ESCWhlDirctnRLVld_flg;
    Float VIPM_ESCWhlSpdKphRL_kph;
    Boolean VIPM_ESCWhlSpdKphRLVld_flg;
    UInt8 VIPM_ESCWhlDirctnRR_enum;
    Boolean VIPM_ESCWhlDirctnRRVld_flg;
    Float VIPM_ESCWhlSpdKphRR_kph;
    Boolean VIPM_ESCWhlSpdKphRRVld_flg;
    Float VIPM_ESCLongAccSnsrVal_g;
    Boolean VIPM_ESCLongAccSnsrValVld_flg;
    Float VIPM_ESCLatAccSnsrVal_g;
    Boolean VIPM_ESCLatAccSnsrValVld_flg;
    Float VIPM_ESCYawRate_degps;
    Boolean VIPM_ESCYawRateVld_flg;
    Boolean VIPM_ESCWhlTqDecReqActv_flg;
    Boolean VIPM_ESCWhlTqDecReqActvVld_flg;
    Float VIPM_ESCWhlTqDecReqVal_Nm;
    Boolean VIPM_ESCWhlTqDecReqValVld_flg;
    Boolean VIPM_ESCWhlTqIncReqActv_flg;
    Boolean VIPM_ESCWhlTqIncReqActvVld_flg;
    Float VIPM_ESCWhlTqIncReqVal_Nm;
    Boolean VIPM_ESCWhlTqIncReqValVld_flg;
} DT_IPM_ESC_A_CHA;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_ESC_A_CHA_

typedef struct
{
    Boolean VIPM_FCMHMAHiBeamReq_flg;
    Boolean VIPM_FCMHMAHiBeamReqVld_flg;
    Boolean VIPM_FCMHMASetFb_flg;
    Boolean VIPM_FCMHMASetFbVld_flg;
} DT_IPM_FCM_A_CHA;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_FCM_A_CHA_

typedef struct
{
    Boolean VIPM_FCMACCWhlTqReqActv_flg;
    Boolean VIPM_FCMACCWhlTqReqActvVld_flg;
    Float VIPM_FCMACCWhlTqReqVal_Nm;
    Boolean VIPM_FCMACCWhlTqReqValVld_flg;
    Float VIPM_FCMACCWhlDece_mps2;
    Boolean VIPM_FCMACCWhlDeceVld_flg;
    Boolean VIPM_FCMAccTarAccrnReqActv_flg;
    Boolean VIPM_FCMAccTarAccrnReqActvVld_flg;
    Float VIPM_FCMAccTarAccrn_mps2;
    Boolean VIPM_FCMAccTarAccrnVld_flg;
    UInt8 VIPM_FCMEPBReq_enum;
    Boolean VIPM_FCMEPBReqVld_flg;
    Boolean VIPM_FCMAccTgtAxReq_flg;
    Boolean VIPM_FCMAccTgtAxReqVld_flg;
    Float VIPM_FCMAccTgtAx_mps2;
    Boolean VIPM_FCMAccTgtAxVld_flg;
    Boolean VIPM_FCMAccReqStandstill_flg;
    Boolean VIPM_FCMAccReqStandstillVld_flg;
    Boolean VIPM_FCMAccReqDriveOff_flg;
    Boolean VIPM_FCMAccReqDriveOffVld_flg;
    UInt8 VIPM_FCMAccMode_enum;
    Boolean VIPM_FCMAccModeVld_flg;
    Boolean VIPM_FCMAEBReq_flg;
    Boolean VIPM_FCMAEBReqVld_flg;
    UInt8 VIPM_FCMTrnLampReq_enum;
    Boolean VIPM_FCMTrnLampReqVld_flg;
    UInt8 VIPM_FCMACCSdnMode_enum;
    Boolean VIPM_FCMACCSdnModeVld_flg;
} DT_IPM_FCM_B_CHA;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_FCM_B_CHA_

typedef struct
{
    UInt8 VIPM_HUHybEcoModeSet_enum;
    Boolean VIPM_HUHybEcoModeSetVld_flg;
    UInt8 VIPM_HULeftTempSet_enum;
    Boolean VIPM_HULeftTempSetVld_flg;
    UInt8 VIPM_HUACPwrCtl_enum;
    Boolean VIPM_HUACPwrCtlVld_flg;
    UInt8 VIPM_HUAirInletModeSet_enum;
    Boolean VIPM_HUAirInletModeSetVld_flg;
    UInt8 VIPM_HUFrntFanSpdSet_enum;
    Boolean VIPM_HUFrntFanSpdSetVld_flg;
    UInt8 VIPM_HUManlDefrstCtl_enum;
    Boolean VIPM_HUManlDefrstCtlVld_flg;
    UInt8 VIPM_HUBlwrModeSet_enum;
    Boolean VIPM_HUBlwrModeSetVld_flg;
    UInt8 VIPM_HUFlwrMeHmCtrl_enum;
    Boolean VIPM_HUFlwrMeHmCtrlVld_flg;
    UInt8 VIPM_HUIllmndEntrySts_enum;
    Boolean VIPM_HUIllmndEntryStsVld_flg;
    UInt8 VIPM_HULckHornOnSt_enum;
    Boolean VIPM_HULckHornOnStVld_flg;
    UInt8 VIPM_HUACAutoCtl_enum;
    Boolean VIPM_HUACAutoCtlVld_flg;
    UInt8 VIPM_HUParkAutoUnlckSet_enum;
    Boolean VIPM_HUParkAutoUnlckSetVld_flg;
    UInt8 VIPM_HUOvrspdCntrlLckSet_enum;
    Boolean VIPM_HUOvrspdCntrlLckSetVld_flg;
    UInt8 VIPM_HUTrnkLckSwCtrl_enum;
    Boolean VIPM_HUTrnkLckSwCtrlVld_flg;
    UInt8 VIPM_HUChgWiprMtMdSwSet_enum;
    Boolean VIPM_HUChgWiprMtMdSwSetVld_flg;
    Boolean VIPM_HUTPMSRstReq_flg;
    Boolean VIPM_HUTPMSRstReqVld_flg;
    UInt8 VIPM_HUMaiDrvrSeatHeat_enum;
    Boolean VIPM_HUMaiDrvrSeatHeatVld_flg;
    Boolean VIPM_HUPwrOffReq_flg;
    Boolean VIPM_HUPwrOffReqVld_flg;
    UInt8 VIPM_HUWiprIntlTmSet_enum;
    Boolean VIPM_HUWiprIntlTmSetVld_flg;
    UInt8 VIPM_CDCBackLadjval_enum;
    Boolean VIPM_CDCBackLadjvalVld_flg;
    UInt8 VIPM_HURrMirrHeat_enum;
    Boolean VIPM_HURrMirrHeatVld_flg;
    UInt8 VIPM_HUSteerWhlHeat_enum;
    Boolean VIPM_HUSteerWhlHeatVld_flg;
    UInt8 VIPM_HUCstRecupModeSel_enum;
    Boolean VIPM_HUCstRecupModeSelVld_flg;
    UInt8 VIPM_HUPeristalsisModeEnbl_enum;
    Boolean VIPM_HUPeristalsisModeEnblVld_flg;
    UInt8 VIPM_HUIllmndUnlckSts_enum;
    Boolean VIPM_HUIllmndUnlckStsVld_flg;
    UInt8 VIPM_HUIllmndLckSts_enum;
    Boolean VIPM_HUIllmndLckStsVld_flg;
    UInt8 VIPM_HUDrvModeSel_enum;
    Boolean VIPM_HUDrvModeSelVld_flg;
    UInt8 VIPM_HURecupPwrSet_pct;
    Boolean VIPM_HURecupPwrSetVld_flg;
    UInt8 VIPM_HUDrvPwrSet_cnt;
    Boolean VIPM_HUDrvPwrSetVld_flg;
    UInt8 VIPM_HUChrgngmode_enum;
    Boolean VIPM_HUChrgngmodeVld_flg;
    UInt8 VIPM_HUChrgngReq_enum;
    Boolean VIPM_HUChrgngReqVld_flg;
    UInt8 VIPM_HUVehMaxCurr_A;
    Boolean VIPM_HUVehMaxCurrVld_flg;
    UInt8 VIPM_HUACUnlckVentSet_enum;
    Boolean VIPM_HUACUnlckVentSetVld_flg;
    UInt8 VIPM_TBoxRmtCarSearch_enum;
    Boolean VIPM_TBoxRmtCarSearchVld_flg;
    UInt8 VIPM_TBoxOpenVentn_enum;
    Boolean VIPM_TBoxOpenVentnVld_flg;
    UInt8 VIPM_TBOXACRemtCtrlFlg_enum;
    Boolean VIPM_TBOXACRemtCtrlFlgVld_flg;
    UInt8 VIPM_TBOXACTempSet_enum;
    Boolean VIPM_TBOXACTempSetVld_flg;
    UInt8 VIPM_TboxRmtDefrstCtl_enum;
    Boolean VIPM_TboxRmtDefrstCtlVld_flg;
    Boolean VIPM_TBOXVCUVer_flg;
    Boolean VIPM_TBOXVCUVerVld_flg;
    Boolean VIPM_TBOXVCUOprtLic_flg;
    Boolean VIPM_TBOXVCUOprtLicVld_flg;
    Boolean VIPM_TBOXVCUChrgngConds_flg;
    Boolean VIPM_TBOXVCUChrgngCondsVld_flg;
    UInt8 VIPM_TBOXRmtPwrLck_enum;
    Boolean VIPM_TBOXRmtPwrLckVld_flg;
    UInt8 VIPM_TBOXVCUCCMSpdLimLvl_enum;
    Boolean VIPM_TBOXVCUCCMSpdLimLvlVld_flg;
    UInt8 VIPM_TBoxRmtLck_enum;
    Boolean VIPM_TBoxRmtLckVld_flg;
    UInt8 VIPM_TBOXRemtPwrCtrlReq_enum;
    Boolean VIPM_TBOXRemtPwrCtrlReqVld_flg;
    UInt8 VIPM_TBOXRemtStrWhlHeatReq_enum;
    Boolean VIPM_TBOXRemtStrWhlHeatReqVld_flg;
    UInt8 VIPM_TBOXRemtMaiDrSeatHeatReq_enum;
    Boolean VIPM_TBOXRemtMaiDrSeatHeatReqVld_flg;
    UInt8 VIPM_HUBCMCargoLghtSet_enum;
    Boolean VIPM_HUBCMCargoLghtSetVld_flg;
    UInt8 VIPM_HUBCMOTAModeSet_enum;
    Boolean VIPM_HUBCMOTAModeSetVld_flg;
} DT_IPM_HU_B_BAC;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_HU_B_BAC_

typedef struct
{
    Float VIPM_HVCHInletTemp_C;
    Boolean VIPM_HVCHInletTempVld_flg;
    Float VIPM_HVCHOutlTemp_C;
    Boolean VIPM_HVCHOutlTempVld_flg;
    Float VIPM_HVCHPCBTemp_C;
    Boolean VIPM_HVCHPCBTempVld_flg;
    UInt8 VIPM_HVCHWorkMode_enum;
    Boolean VIPM_HVCHWorkModeVld_flg;
    Boolean VIPM_HVCHHVSt_flg;
    Boolean VIPM_HVCHHVStVld_flg;
    UInt8 VIPM_HVCHSt_enum;
    Boolean VIPM_HVCHStVld_flg;
} DT_IPM_HVCH_Status1_BOD;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_HVCH_Status1_BOD_

typedef struct
{
    UInt16 VIPM_HVCHFltCod_enum;
    Boolean VIPM_HVCHFltCodVld_flg;
    Float VIPM_HVCHHVVolts_V;
    Boolean VIPM_HVCHHVVoltsVld_flg;
    Float VIPM_HVCHCurr_A;
    Boolean VIPM_HVCHCurrVld_flg;
    Float VIPM_HVCHPwr_kW;
    Boolean VIPM_HVCHPwrVld_flg;
    UInt8 VIPM_HVCHWorkSt_enum;
    Boolean VIPM_HVCHWorkStVld_flg;
} DT_IPM_HVCH_Status2_BOD;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_HVCH_Status2_BOD_

typedef struct
{
    Float VIPM_ICUTotOdo_km;
    Boolean VIPM_ICUTotOdoVld_flg;
} DT_IPM_ICU_2_Odo_BAC;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_ICU_2_Odo_BAC_

typedef struct
{
    Float VIPM_INV1MotSpd_rpm;
    Boolean VIPM_INV1MotSpdVld_flg;
    Float VIPM_INV1ActTorq_Nm;
    Boolean VIPM_INV1ActTorqVld_flg;
    UInt8 VIPM_INV1PreChrgAllwd_enum;
    Boolean VIPM_INV1PreChrgAllwdVld_flg;
    UInt8 VIPM_INV1ShutdownAllwd_enum;
    Boolean VIPM_INV1ShutdownAllwdVld_flg;
    UInt8 VIPM_INV1ActMode_enum;
    Boolean VIPM_INV1ActModeVld_flg;
    Boolean VIPM_INV1PreprogmFlg_flg;
    Boolean VIPM_INV1PreprogmFlgVld_flg;
    UInt8 VIPM_INV1AntithftAuthRslt_enum;
    Boolean VIPM_INV1AntithftAuthRsltVld_flg;
} DT_IPM_INV_1_Value_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_INV_1_Value_EPT_

typedef struct
{
    Float VIPM_INV2MotorMaxTemp_C;
    Boolean VIPM_INV2MotorMaxTempVld_flg;
    Float VIPM_INV2IgbtMaxTemp_C;
    Boolean VIPM_INV2IgbtMaxTempVld_flg;
    Float VIPM_INV2InpCurnt_A;
    Boolean VIPM_INV2InpCurntVld_flg;
    Float VIPM_INV2InpVolt_V;
    Boolean VIPM_INV2InpVoltVld_flg;
} DT_IPM_INV_2_Value_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_INV_2_Value_EPT_

typedef struct
{
    Float VIPM_INV3DrvTqAllwdMax_Nm;
    Boolean VIPM_INV3DrvTqAllwdMaxVld_flg;
    Float VIPM_INV3RecupTqAllwdMax_Nm;
    Boolean VIPM_INV3RecupTqAllwdMaxVld_flg;
} DT_IPM_INV_3_Value_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_INV_3_Value_EPT_

typedef struct
{
    UInt8 VIPM_INV4FltLvl_enum;
    Boolean VIPM_INV4FltLvlVld_flg;
} DT_IPM_INV_4_Value_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_INV_4_Value_EPT_

typedef struct
{
    UInt8 VIPM_INVLrngSubID_cnt;
    Boolean VIPM_INVLrngSubIDVld_flg;
    UInt8 VIPM_INVLrngSts_enum;
    Boolean VIPM_INVLrngStsVld_flg;
    UInt8 VIPM_INVLrngData02_nu;
    Boolean VIPM_INVLrngData02Vld_flg;
    UInt8 VIPM_INVLrngData03_nu;
    Boolean VIPM_INVLrngData03Vld_flg;
    UInt8 VIPM_INVLrngData04_nu;
    Boolean VIPM_INVLrngData04Vld_flg;
    UInt8 VIPM_INVLrngData05_nu;
    Boolean VIPM_INVLrngData05Vld_flg;
    UInt8 VIPM_INVLrngData06_nu;
    Boolean VIPM_INVLrngData06Vld_flg;
    UInt8 VIPM_INVLrngData07_nu;
    Boolean VIPM_INVLrngData07Vld_flg;
} DT_IPM_INV_IMMO_Req_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_INV_IMMO_Req_EPT_

typedef struct
{
    UInt8 VIPM_IPUDCCActOprtMode_enum;
    Boolean VIPM_IPUDCCActOprtModeVld_flg;
    Float VIPM_IPUDCCLoVoltActVolt_V;
    Boolean VIPM_IPUDCCLoVoltActVoltVld_flg;
    Float VIPM_IPUDCCLoVoltActCurnt_A;
    Boolean VIPM_IPUDCCLoVoltActCurntVld_flg;
    UInt8 VIPM_IPUDCCSysFailSta_enum;
    Boolean VIPM_IPUDCCSysFailStaVld_flg;
    Boolean VIPM_IPUHVILFailSt_flg;
    Boolean VIPM_IPUHVILFailStVld_flg;
} DT_IPM_IPU_DCC_1_State_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_IPU_DCC_1_State_EPT_

typedef struct
{
    Float VIPM_IPUDCCHiVoltActCurnt_A;
    Boolean VIPM_IPUDCCHiVoltActCurntVld_flg;
    Float VIPM_IPUDCCHiVoltActVolt_V;
    Boolean VIPM_IPUDCCHiVoltActVoltVld_flg;
} DT_IPM_IPU_DCC_2_ChrgInValue_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_IPU_DCC_2_ChrgInValue_EPT_

typedef struct
{
    UInt8 VIPM_IPUOBCReq_enum;
    Boolean VIPM_IPUOBCReqVld_flg;
    UInt8 VIPM_IPUOBCSysFailSta_enum;
    Boolean VIPM_IPUOBCSysFailStaVld_flg;
    Boolean VIPM_IPUOBCConnectMainSta_flg;
    Boolean VIPM_IPUOBCConnectMainStaVld_flg;
    UInt8 VIPM_IPUOBCActOprtMode_enum;
    Boolean VIPM_IPUOBCActOprtModeVld_flg;
    UInt8 VIPM_IPUOBCInletConnectSta_enum;
    Boolean VIPM_IPUOBCInletConnectStaVld_flg;
    Float VIPM_IPUOBCHVDCActCur_A;
    Boolean VIPM_IPUOBCHVDCActCurVld_flg;
    Float VIPM_IPUOBCHVDCActVol_V;
    Boolean VIPM_IPUOBCHVDCActVolVld_flg;
    Float VIPM_IPUOBCInletActPwr_kW;
    Boolean VIPM_IPUOBCInletActPwrVld_flg;
} DT_IPM_IPU_OBC_1_State_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_IPU_OBC_1_State_EPT_

typedef struct
{
    UInt8 VIPM_IPUOBCWakeUpMode_enum;
    Boolean VIPM_IPUOBCWakeUpModeVld_flg;
    Boolean VIPM_IPUOBCS2State_flg;
    Boolean VIPM_IPUOBCS2StateVld_flg;
    Float VIPM_IPUOBCACMaxPwrAllow_kW;
    Boolean VIPM_IPUOBCACMaxPwrAllowVld_flg;
    Float VIPM_IPUDeviceIntTemp_C;
    Boolean VIPM_IPUDeviceIntTempVld_flg;
    Float VIPM_IPUOBCTempInt_C;
    Boolean VIPM_IPUOBCTempIntVld_flg;
} DT_IPM_IPU_OBC_2_Inlet_EPT;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_IPU_OBC_2_Inlet_EPT_

typedef struct
{
    Boolean VIPM_SCSFrntWshrSwtSt_flg;
    Boolean VIPM_SCSFrntWshrSwtStVld_flg;
    UInt8 VIPM_SCSFrntWiprSwtSt_enum;
    Boolean VIPM_SCSFrntWiprSwtStVld_flg;
    Boolean VIPM_SCSPstnLghtSwSt_flg;
    Boolean VIPM_SCSPstnLghtSwStVld_flg;
    Boolean VIPM_SCSLoBeamSwSt_flg;
    Boolean VIPM_SCSLoBeamSwStVld_flg;
    Boolean VIPM_SCSHiBeamSwSt_flg;
    Boolean VIPM_SCSHiBeamSwStVld_flg;
    Boolean VIPM_SCSOvrVehBeamSwSt_flg;
    Boolean VIPM_SCSOvrVehBeamSwStVld_flg;
    Boolean VIPM_SCSLampAutoSt_flg;
    Boolean VIPM_SCSLampAutoStVld_flg;
    Boolean VIPM_SCSLeTrnLmpSwSt_flg;
    Boolean VIPM_SCSLeTrnLmpSwStVld_flg;
    Boolean VIPM_SCSRiTrnLmpSwSt_flg;
    Boolean VIPM_SCSRiTrnLmpSwStVld_flg;
} DT_IPM_SCS_LeSwitchSts_BOD;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_SCS_LeSwitchSts_BOD_

typedef struct
{
    UInt8 VIPM_SCSGrShftLvrPstnReq_enum;
    Boolean VIPM_SCSGrShftLvrPstnReqVld_flg;
    Boolean VIPM_SCSRghtSwVldty_flg;
    Boolean VIPM_SCSRghtSwVldtyVld_flg;
    Boolean VIPM_SCSRght11Sw_flg;
    Boolean VIPM_SCSRght11SwVld_flg;
    Boolean VIPM_SCSRght12Sw_flg;
    Boolean VIPM_SCSRght12SwVld_flg;
    Boolean VIPM_SCSRght13Sw_flg;
    Boolean VIPM_SCSRght13SwVld_flg;
} DT_IPM_SCS_RiSwitchSts_BOD;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_SCS_RiSwitchSts_BOD_

typedef struct
{
    Boolean VIPM_SRSDrvSeatbeltBkld_flg;
    Boolean VIPM_SRSDrvSeatbeltBkldVld_flg;
    UInt8 VIPM_SRSCrashOutputSts_enum;
    Boolean VIPM_SRSCrashOutputStsVld_flg;
} DT_IPM_SRS_1_Status_CHA;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_SRS_1_Status_CHA_

typedef struct
{
    UInt16 VIPM_TBOXBJSTimeYear_nu;
    Boolean VIPM_TBOXBJSTimeYearVld_flg;
    UInt8 VIPM_TBOXBJSTimeMonth_nu;
    Boolean VIPM_TBOXBJSTimeMonthVld_flg;
    UInt8 VIPM_TBOXBJSTimeDay_nu;
    Boolean VIPM_TBOXBJSTimeDayVld_flg;
    UInt8 VIPM_TBOXBJSTimeHour_nu;
    Boolean VIPM_TBOXBJSTimeHourVld_flg;
    UInt8 VIPM_TBOXBJSTimeMin_nu;
    Boolean VIPM_TBOXBJSTimeMinVld_flg;
    UInt8 VIPM_TBOXBJSTimeSec_nu;
    Boolean VIPM_TBOXBJSTimeSecVld_flg;
} DT_IPM_TBOX_BJS_Time_BAC;

#define _DEFINED_TYPEDEF_FOR_DT_IPM_TBOX_BJS_Time_BAC_

typedef struct
{
    Boolean VIPM_BMSMsgActv_flg;
    Boolean VIPM_INVMsgActv_flg;
    Boolean VIPM_OBCMsgActv_flg;
    Boolean VIPM_DCDCMsgActv_flg;
    Boolean VIPM_EPSMsgActv_flg;
    Boolean VIPM_SRSMsgActv_flg;
    Boolean VIPM_ESCMsgActv_flg;
    Boolean VIPM_FCMMsgActv_flg;
    Boolean VIPM_EHBMsgActv_flg;
    Boolean VIPM_CDCMsgActv_flg;
    Boolean VIPM_TBOXMsgActv_flg;
    Boolean VIPM_ACCMMsgActv_flg;
    Boolean VIPM_SCSMsgActv_flg;
    Boolean VIPM_CCPMsgActv_flg;
    Boolean VIPM_ESCLMsgActv_flg;
    Boolean VIPM_HUMsgActv_flg;
    Boolean VIPM_PTCMsgActv_flg;
    Boolean VIPM_CRRRMsgActv_flg;
} DT_MsgActv;

#define _DEFINED_TYPEDEF_FOR_DT_MsgActv_

typedef struct
{
    UInt8 VIBS_RTCChrgSt_enum;
    UInt8 VIBS_ChgNum_cnt;
    Boolean VIBS_FbRctWup_flg;
    UInt16 VIBS_NextRtcWupThr_min;
    Boolean VIBS_HVReq_flg;
    Boolean VIBS_NMReq_flg;
    UInt8 VIBS_FailChgNum_cnt;
    Boolean VIBS_SleepAllwd_flg;
    Boolean VIBS_WupVoltAllow_flg;
    Float VIBS_HwKL30_V;
    Boolean VIBS_ChgNumAllow_flg;
    Boolean VIBS_BMSBatSOCAllow_flg;
} DT_SIBS_Output;

#define _DEFINED_TYPEDEF_FOR_DT_SIBS_Output_

typedef struct
{
    Float VIPC_VehSpd_kph;
    Boolean VIPC_VehSpdVld_flg;
    UInt8 VIPC_DrvModeAct_enum;
    UInt8 VIPC_RegenModeAct_enum;
    UInt8 VGSM_VehActGearPstn_enum;
    Boolean VGSM_VehActGearPstnV_flg;
    UInt8 VHVM_PTActOprtMode_enum;
    Boolean VHVM_Bat2DrvTrainEnbl_flg;
    Boolean VHVM_OTAModeSts_flg;
    Boolean VVTM_RegenReqBrkLampOn_flg;
    Boolean VDAG_LimpHome_flg;
    UInt8 VHMI_12VBatLoVolSta_enum;
    Boolean VEMS_ACCMOprtCmd_flg;
    Float VEMS_HeatCoolMaxPwrCmsp_kW;
    UInt8 VBSW_WakeupReasn_enum;
    UInt8 VIPC_VehHiddenMode_enum;
    Boolean VTBX_VCURmtACCtrlReq_flg;
    Boolean VTBX_VCURmtACDefrstReq_flg;
    UInt8 VTBX_VCURmtACCtrlSt_enum;
} DT_Vcu2BcmTms_outputs;

#define _DEFINED_TYPEDEF_FOR_DT_Vcu2BcmTms_outputs_

typedef struct
{
    Boolean VVTM_MotorActlPwrType_flg;
    Float VVTM_RsrvPwr_kW;
    Float VVTM_MotorActlPwr_kW;
    UInt8 VVTM_DrvMotorSta_enum;
    Boolean VVTM_PCUFailSta_flg;
    Boolean VRME_CHTCRmnMilEstV_flg;
    Float VRME_CHTCRmnMilEst_km;
    Boolean VRME_DynRmnMilEstV_flg;
    Float VRME_DynRmnMilEst_km;
    Float VRME_VehPwrCnsmAvg_kWhp100km;
    Float VRME_VehPwrCnsmIns_kWhp100km;
    UInt8 VHMI_12VBatLoVolSta_enum;
    UInt8 VHMI_InfoDisp_enum;
    UInt8 VGSM_VehActGearPstn_enum;
    Boolean VGSM_VehActGearPstnV_flg;
    Boolean VGSM_VehPGearErr_flg;
    Boolean VGSM_VehSpdFstWrn_flg;
    UInt8 VHVM_OBCOprtCmd_enum;
    UInt8 VHVM_PTActOprtMode_enum;
    UInt8 VIPC_RegenModeAct_enum;
    UInt8 VIPC_CrpModeAct_enum;
    UInt8 VIPC_DrvModeAct_enum;
    UInt8 VIPC_DrvPwrIntnsty_pct;
    UInt8 VIPC_RegenPwrIntnsty_pct;
    Boolean VDAG_LimpHome_flg;
    Boolean VVcuTx_MotorHiTempWrning_flg;
    Boolean VVcuTx_MCUHiTempWrning_flg;
    Float VIBS_HwKL30_V;
    Boolean VIBS_ChgNumAllow_flg;
    UInt8 VIBS_ChgNum_cnt;
    UInt8 VIBS_RTCChrgSt_enum;
    UInt8 VIBS_FailChgNum_cnt;
    Boolean VIBS_FbRctWup_flg;
    Boolean VIBS_BMSBatSOCAllow_flg;
    Boolean VIBS_WupVoltAllow_flg;
    UInt8 VVcuTx_ShftKeyStgntn_enum;
    UInt8 VVcuTx_CCKeyStgntn_enum;
    UInt8 VVcuTx_DrvModeKeyStgntn_enum;
    UInt8 VVTM_HDCStat_enum;
    UInt8 VVSO_TPMSPrsrStaFL_enum;
    UInt8 VVSO_TPMSPrsrStaFR_enum;
    UInt8 VVSO_TPMSPrsrStaRL_enum;
    UInt8 VVSO_TPMSPrsrStaRR_enum;
    UInt8 VVSO_BCMTPMSRstSts_enum;
    Boolean VVSO_TMPSAbnmPrsrWarn_flg;
    UInt8 VHVM_ACChrgModeFb_enum;
    UInt8 VHVM_ACChrgMaxCurrFb_A;
    UInt8 VTBX_VCULckVehWrn_enum;
    UInt8 VTBX_VCUVerSetFb_enum;
    UInt8 VTBX_VCUSpdLimLvlSetFb_enum;
    Boolean VTBX_VCUVerFb_flg;
    Boolean VTBX_VCUOprtLicFb_flg;
    UInt8 VTBX_VCUSpdLimLvlFb_enum;
    Boolean VTBX_VCUChrgngCondsFb_flg;
    Boolean VTBX_VCURmtACCtrlReq_flg;
    Boolean VTBX_VCURmtACDefrstReq_flg;
    UInt8 VTBX_VCURmtACCtrlSt_enum;
    Boolean VVSO_WghConfdence_flg;
    Float VVSO_WghEst_kg;
    UInt8 VVSO_WghDistb_enum;
    UInt8 VVTM_CruzCtrlStat_enum;
    Float VVTM_CCTgtSpd_kph;
} DT_Vcu2OpmBAC_outputs;

#define _DEFINED_TYPEDEF_FOR_DT_Vcu2OpmBAC_outputs_

typedef struct
{
    Float VVTM_ActWhlTq_Nm;
    Boolean VVTM_DrvReqMotorTorqV_flg;
    Float VVTM_DrvReqWhlTq_Nm;
    Float VVTM_WhlDrvMaxTq_Nm;
    UInt8 VVTM_PwrRecActWhlTorqSta_enum;
    Float VVTM_PwrRecActWhlTorq_Nm;
    UInt8 VVTM_BrkPwrRecMaxWhlTorqSta_enum;
    Float VVTM_BrkPwrRecMaxWhlTorq_Nm;
    UInt8 VVTM_BrkPwrRecActWhlTorqSt_enum;
    Float VVTM_BrkPwrRecActWhlTorq_Nm;
    Float VVTM_DrvReqMotorTorq_Nm;
    Boolean VVTM_ACCOvrd_flg;
    Boolean VVTM_ACCAvail_flg;
    Float VVTM_VirtAccPedPstn_pct;
    UInt8 VVTM_VirtAccPedPstnSta_enum;
    Boolean VVTM_RegenReqBrkLampOn_flg;
    UInt8 VVTM_CruzCtrlStat_enum;
    Float VVTM_CCTgtSpd_kph;
    UInt8 VVTM_AutoBrkReq_enum;
    UInt8 VGSM_ReqEPB_enum;
    Boolean VGSM_ReqEPBV_flg;
    Boolean VGSM_GrShftInhbed_flg;
    UInt8 VGSM_PGrSwSts_enum;
    Float VIPC_AccPedPstn_pct;
    UInt8 VIPC_AccPedSnsrSta_enum;
    Boolean VIPC_BrkPedPstnVld_flg;
    Float VIPC_BrkPedPstn_pct;
    Boolean VHVM_OTAModeSts_flg;
    Boolean VVTM_EnblEHBBrkRun_flg;
    Float VVTM_MotorTqReqToEHB_Nm;
    Float VVTM_MstrCylPresrReq_Bar;
    Boolean VVcuTx_ParkSwStaVld_flg;
    Boolean VVcuTx_ParkSwSta_flg;
    UInt8 VGSM_EPBApplyFbd_enum;
    UInt8 VVTM_ACCStat_enum;
    Boolean VVTM_AccReqStandstill_flg;
} DT_Vcu2OpmCHA_outputs;

#define _DEFINED_TYPEDEF_FOR_DT_Vcu2OpmCHA_outputs_

typedef struct
{
    Float VIPC_AccPedPstn_pct;
    Boolean VIPC_DrvSw_flg;
    Boolean VIPC_BrkSwActv_flg;
    Boolean VVTM_MotDampngEnbl_flg;
    Float VVTM_MotDampngLmt_Nm;
    UInt8 VVTM_MotorModeReq_enum;
    UInt8 VVTM_MotorDirReq_enum;
    Float VVTM_MotorTqReq_Nm;
    SInt16 VVTM_MotorSpdReq_rpm;
    Boolean VHVM_EnaDisChg_flg;
    Boolean VHVM_EmgcySdn_flg;
    Boolean VHVM_Bat2DrvTrainEnbl_flg;
    UInt8 VHVM_ChrgEnaAC_enum;
    UInt8 VHVM_BMSWakeUpMode_enum;
    UInt8 VHVM_BMSShutdown_enum;
    UInt8 VHVM_ChrgAllowCmd_enum;
    Boolean VHVM_ChrgEnaDC_flg;
    Float VHVM_MaxChrgCurntDC_A;
    Float VHVM_MaxChrgVoltDC_V;
    UInt8 VHVM_OBCOprtCmd_enum;
    UInt8 VHVM_SysSta_enum;
    UInt8 VHVM_DCCOprtCmd_enum;
    Float VHVM_DCCBuckLVVolt_V;
    Float VHVM_MaxHVDCCurntAC_A;
    Float VHVM_MaxHVDCVoltAC_V;
    UInt8 VHVM_MaxChrgCurntAC_A;
    Boolean VGSM_INVRunEnbl_flg;
    UInt8 VGSM_VehTgtGrReq_enum;
    Float VEMS_HeatCoolMaxPwrCmsp_kW;
    UInt16 VDAG_VCUErrCode_enum;
    UInt8 VDAG_VCUFltLvl_enum;
    UInt8 VVCU_SoftWareVer_cnt;
} DT_Vcu2OpmEPT_outputs;

#define _DEFINED_TYPEDEF_FOR_DT_Vcu2OpmEPT_outputs_

typedef struct
{
    Boolean DoorAjarFLSw;
    Boolean DoorAjarFRSw;
    Boolean DriverDoorLckSw;
    Boolean DrvPESw;
    Boolean PsgPESw;
    Boolean TrunkSw;
    Boolean DoorAjarRLSw;
    Boolean DoorAjarRRSw;
    Boolean TrunkAjarSw;
    Boolean HoodAjarSw;
    Boolean TrunkLckSw;
    Boolean DrvSeatSw;
    Boolean InsLck;
    Boolean InsUnlck;
    Boolean OsLck;
    Boolean OsUnlck;
    Boolean TrunkUnlck;
    Boolean MotorProt;
    Boolean DoorProtUnlck;
    UInt8 ParkAutoUnlockSetFb;
    Boolean CrshUnlck;
    Boolean J56DoorUnlck;
    Boolean J54DoorLck;
    Boolean J511TrunkUnlck;
    UInt8 TrunkLckSta;
    UInt8 InsLckSta;
    UInt8 OsLckSta;
    Boolean RKEAntiLck;
    Boolean MechAntiLck;
    UInt8 SpdCtlLckSetFb;
    UInt8 SpdCtlLckSet;
    Boolean WelcomeLck;
    Boolean WelcomeUnlck;
    Boolean HULck;
    Boolean HUUnlck;
    Boolean VehStop;
    Boolean AutoLckSta;
    Boolean AutoLck;
    Boolean PELck;
    UInt8 IllmndUnlockStsFb;
    UInt8 IllmndUnlockSts;
    UInt8 IllmndLckSts;
    UInt8 IllmndLckStsFb;
    Boolean MechLck;
    Boolean RKELck;
    Boolean RKEUnlck;
    Boolean PEUnlck;
    Boolean MechUnlck;
    Boolean ParkUnlck;
    Boolean ThermRunawayUnlck;
    Boolean SpdLck;
    Boolean TrunkRkEUnlck;
    Boolean TrunkHUUnlck;
    Boolean TrunkAutoLck;
    Boolean TboxLck;
    Boolean TboxUnlck;
    Boolean TrunkTboxUnlck;
    UInt8 RemoteLockFb;
    Boolean TboxAntiLck;
} DoorLckCtl;

#define _DEFINED_TYPEDEF_FOR_DoorLckCtl_

typedef UInt8 rt_Array_UInt8_10[10];

#define _DEFINED_TYPEDEF_FOR_rt_Array_UInt8_10_

typedef struct
{
    UInt8 BodyWarnSts;
    UInt8 FlwrMeHomeCtlFb;
    UInt8 BackLadjvalFb;
    UInt8 HazardLightSta;
    UInt8 IllmndLckSts;
    UInt8 SpdCtlLckSet;
    UInt8 ParkAutoUnlockSetFb;
    UInt8 LockHoornOnSts;
    UInt8 CrashSta;
    UInt8 IllmndUnlckSts;
    UInt8 InrTim;
    UInt8 WiperIntlTimeSetFb;
    rt_Array_UInt8_10 DoorOpRecord;
    rt_Array_UInt8_10 LocalStartFailOpRecord;
    rt_Array_UInt8_10 RemoteStartFailRecord;
    rt_Array_UInt8_10 TrunkOpRecord;
    UInt8 TrunkLckSw;
    UInt8 DriverDoorLckSw;
    UInt8 DoorAjarFLSw;
    UInt8 DoorAjarFRSw;
    UInt8 TrunkSw;
    UInt8 DoorAjarRLSw;
    UInt8 DoorAjarRRSw;
    UInt8 TrunkAjarSw;
    UInt8 DrvSeatSw;
    UInt8 RemotePwrLckSta;
    UInt8 SysPwrMode;
    UInt8 StartReq;
    UInt8 BJSTimeDay;
    UInt8 BJSTimeHour;
    UInt8 BJSTimeMonth;
    UInt16 BJSTimeYear;
} EEReadCtl;

#define _DEFINED_TYPEDEF_FOR_EEReadCtl_

typedef struct
{
    UInt8 EHB_AVHAppldSt;
    UInt8 EHB_AVHDispMSG;
    UInt8 EHB_AVHLampReq;
    UInt8 EHB_A_AliveCnt;
    UInt8 EHB_A_Chksum;
    UInt8 EHB_BBSDfctv;
    Boolean EHB_BLA;
    Boolean EHB_BrakeLiquidLevelWarn;
    Boolean EHB_BrkDisWipAc;
    UInt8 EHB_EPB_ActuatorSt_L;
    UInt8 EHB_EPB_DisplayMsgID;
    UInt8 EHB_EPB_FltSts;
    UInt8 EHB_EPB_Left_FailStatus;
    UInt8 EHB_EPB_ParkLampSta;
    UInt8 EHB_EPB_RequestEcho;
    UInt8 EHB_EPB_Right_MotComd;
    UInt8 EHB_EPB_SwitchSts;
    UInt8 EHB_EPB_SystemState;
    UInt8 EHB_EPB_WarnLampSta;
    Boolean EHB_ExtReqPrio;
    UInt8 EHB_ExtReqStatus;
    Boolean EHB_FailureSts;
    Boolean EHB_HDCFucFault;
    UInt8 EHB_HHC_ActiveSta;
    Boolean EHB_HMI_WarningOn;
    UInt8 EHB_RgnBrkSt;
} EHB_A_CHA;

#define _DEFINED_TYPEDEF_FOR_EHB_A_CHA_

typedef struct
{
    Boolean EHB_ABA_ActiveSta;
    Boolean EHB_ABA_AvailableSta;
    Boolean EHB_ABP_ActiveSta;
    Boolean EHB_ABP_AvailableSta;
    Boolean EHB_AEB_ActiveSta;
    Boolean EHB_AEB_AvailableSta;
    Boolean EHB_AWB_ActiveSta;
    Boolean EHB_AWB_AvailableSta;
    UInt8 EHB_B_AliveCnt1;
    UInt8 EHB_B_AliveCnt2;
    UInt8 EHB_B_AliveCnt3;
    UInt8 EHB_B_Chksum1;
    UInt8 EHB_B_Chksum2;
    UInt8 EHB_B_Chksum3;
    Boolean EHB_BrakePedalApplied;
    UInt8 EHB_BrakePedalApplied_Q;
    UInt16 EHB_BrkPedlVal;
    UInt8 EHB_BrkPedlValPerc;
    Boolean EHB_BrkPedlValPercVld;
    Boolean EHB_BrkPedlValVld;
    UInt16 EHB_BrkPwrRecupTarWhlTq;
    UInt8 EHB_BrkPwrRecupTarWhlTqSts;
    Boolean EHB_CDDActive;
    Boolean EHB_CDDAvailable;
    Boolean EHB_CDDTempOff;
    Boolean EHB_DiagActiveSts;
    UInt8 EHB_EPB_ActuatorSt_R;
    UInt8 EHB_EPB_DynamicApplySta;
    UInt8 EHB_FaultLevel;
    Boolean EHB_HBCRequestActive;
    Boolean EHB_HbbRequest;
    UInt16 EHB_MotBrkRegnTqTar;
    Boolean EHB_MotBrkRegnTqTarVld;
    Boolean EHB_NoBrakeForce;
    UInt8 EHB_PBCInApplyRelsReq;
    Boolean EHB_PBCRollrBenchActv;
    Boolean EHB_PBCRollrBenchActvVldty;
    Boolean EHB_PedlTrvlSnsrFail_PDF;
    Boolean EHB_PedlTrvlSnsrFail_PDT;
    UInt8 EHB_PedlTrvlSnsrPlauSta;
    Boolean EHB_ReqBrkLiOn;
    UInt8 EHB_pRunoutPressure;
    Boolean EHB_pRunoutPressureVld;
    UInt16 EHB_pSetEbr;
    UInt8 EHB_pSetEbr_Q;
    UInt8 EHB_sOutputRodDriverPerc;
    Boolean EHB_sOutputRodDriverSnsrFail;
    UInt16 EHB_sOutputRodHydraulicTarget;
    Boolean EHB_sOutputRodHydraulicTarget_Q;
} EHB_B_CHA;

#define _DEFINED_TYPEDEF_FOR_EHB_B_CHA_

typedef struct
{
    Float VEMS_HVBatPwrAct_kW;
    Float VEMS_MaxDchaPwr2Mot_kW;
    Float VEMS_MaxChrgPwr2Mot_kW;
    Boolean VEMS_ACCMOprtCmd_flg;
    Float VEMS_HeatCoolMaxPwrCmsp_kW;
    Float VEMS_BatHeatMaxPwrCmsp_kw;
} EMS_outputs;

#define _DEFINED_TYPEDEF_FOR_EMS_outputs_

typedef struct
{
    UInt8 EPS_2_AliveCnt;
    UInt8 EPS_2_Chksum;
    UInt8 EPS_ElectricPowerSta;
    UInt16 EPS_RotSpeed;
    UInt16 EPS_SteerWheelAngle;
    Boolean EPS_SteerWheelAngleCalibrated;
    Boolean EPS_SteerWheelAngleFailure;
    Boolean EPS_SteerWheelAngleValid;
} EPS_2_StrWhlAng_CHA;

#define _DEFINED_TYPEDEF_FOR_EPS_2_StrWhlAng_CHA_

typedef struct
{
    UInt8 UnOrLockCrtl;
    Boolean J436PwrSup;
} ESCLCtl;

#define _DEFINED_TYPEDEF_FOR_ESCLCtl_

typedef struct
{
    UINT64 ESCL_UnOrLock_feedback;
} ESCL_ESCLStatus_BOD;

#define _DEFINED_TYPEDEF_FOR_ESCL_ESCLStatus_BOD_

typedef struct
{
    UInt8 ESC_7_AliveCnt;
    UInt8 ESC_7_Chksum;
    Boolean ESC_ABSActiveSta;
    Boolean ESC_ABSFailed;
    Boolean ESC_CDPActive;
    Boolean ESC_CDPAvailable;
    Boolean ESC_EBDActiveSta;
    Boolean ESC_EBDFailed;
    Boolean ESC_ESCDisable;
    Boolean ESC_ESCorTCSFailed;
    Boolean ESC_ESPActiveSta;
    Boolean ESC_ESSActive;
    Boolean ESC_ESSAvailable;
    UInt8 ESC_FaultLevel;
    UInt8 ESC_HMI_WarningOn;
    UInt8 ESC_PALAResponse;
    Boolean ESC_RMIActiveSta;
    Boolean ESC_ReqBrakeLightOn;
    UInt8 ESC_SlopePercent;
    UInt8 ESC_SlopePercentV;
    Boolean ESC_TCSActiveSta;
    UInt16 ESC_VehicleSpeed;
    Boolean ESC_VehicleSpeedV;
} ESC_7_FuncStatus_CHA;

#define _DEFINED_TYPEDEF_FOR_ESC_7_FuncStatus_CHA_

typedef struct
{
    UInt8 ESC_A_AliveCnt1;
    UInt8 ESC_A_AliveCnt2;
    UInt8 ESC_A_AliveCnt3;
    UInt8 ESC_A_AliveCnt4;
    UInt8 ESC_A_AliveCnt5;
    UInt8 ESC_A_AliveCnt6_RihgtEPB;
    UInt8 ESC_A_AliveCnt7;
    UInt8 ESC_A_Chksum1;
    UInt8 ESC_A_Chksum2;
    UInt8 ESC_A_Chksum3;
    UInt8 ESC_A_Chksum4;
    UInt8 ESC_A_Chksum5;
    UInt8 ESC_A_Chksum6_RihgtEPB;
    UInt8 ESC_A_Chksum7;
    Boolean ESC_BrakeTempOverHeat;
    Boolean ESC_DTCFailureSts;
    Boolean ESC_DTCRequestRBSSts;
    Boolean ESC_DTC_ActiveSts;
    UInt8 ESC_EPB_ActuatorSt_R;
    UInt8 ESC_EPB_RightFaultState;
    UInt16 ESC_EPB_Right_Current;
    UInt8 ESC_HbbHbcActive;
    UInt8 ESC_HbbHbcAvailable;
    UInt16 ESC_LatAccSensorValue;
    Boolean ESC_LatAccSensorValueVld;
    UInt16 ESC_LongAccSensorValue;
    Boolean ESC_LongAccSensorValueVld;
    UInt8 ESC_MasterCylinderPresr;
    Boolean ESC_MasterCylinderPresrV;
    UInt8 ESC_VhclStandstillSta;
    UInt8 ESC_WheelDirection_FL;
    UInt8 ESC_WheelDirection_FR;
    UInt8 ESC_WheelDirection_RL;
    UInt8 ESC_WheelDirection_RR;
    Boolean ESC_WheelSpeedKphV_FL;
    Boolean ESC_WheelSpeedKphV_FR;
    Boolean ESC_WheelSpeedKphV_RL;
    Boolean ESC_WheelSpeedKphV_RR;
    UInt16 ESC_WheelSpeedKph_FL;
    UInt16 ESC_WheelSpeedKph_FR;
    UInt16 ESC_WheelSpeedKph_RL;
    UInt16 ESC_WheelSpeedKph_RR;
    Boolean ESC_WheelSpeedRCSts_FL;
    Boolean ESC_WheelSpeedRCSts_FR;
    Boolean ESC_WheelSpeedRCSts_RL;
    Boolean ESC_WheelSpeedRCSts_RR;
    UInt16 ESC_WheelSpeedRC_FL;
    UInt16 ESC_WheelSpeedRC_FR;
    UInt16 ESC_WheelSpeedRC_RL;
    UInt16 ESC_WheelSpeedRC_RR;
    Boolean ESC_WhlTqDecReqActv;
    UInt16 ESC_WhlTqDecReqVal;
    Boolean ESC_WhlTqIncReqActv;
    UInt16 ESC_WhlTqIncReqVal;
    UInt16 ESC_YawRate;
    Boolean ESC_YawRateVld;
} ESC_A_CHA;

#define _DEFINED_TYPEDEF_FOR_ESC_A_CHA_

typedef struct
{
    Boolean FCM_ACCStart;
    Boolean FCM_ACCTakeOverReq;
    UInt8 FCM_ADASDrvrReq;
    UInt8 FCM_ADASNotAvlReas;
    UInt8 FCM_ADASQuitReas;
    UInt8 FCM_AEBObjID;
    Boolean FCM_AEBRecReq;
    Boolean FCM_AEBSetFb;
    UInt8 FCM_A_AliveCnt1;
    UInt8 FCM_A_AliveCnt2;
    UInt8 FCM_A_AliveCnt3;
    UInt8 FCM_A_AliveCnt4;
    UInt8 FCM_A_AliveCnt5;
    UInt8 FCM_A_AliveCnt6;
    UInt8 FCM_A_Chksum1;
    UInt8 FCM_A_Chksum2;
    UInt8 FCM_A_Chksum3;
    UInt8 FCM_A_Chksum4;
    UInt8 FCM_A_Chksum5;
    UInt8 FCM_A_Chksum6;
    UInt8 FCM_AccModeHMI;
    UInt8 FCM_ActDrvAsstStsHMI;
    Boolean FCM_AudioWarnHandsOff;
    UInt8 FCM_ELKLeftMode;
    UInt8 FCM_ELKRightMode;
    UInt8 FCM_ELKSetFb;
    UInt8 FCM_FCM_intialization;
    UInt8 FCM_FCWSetFb;
    UInt8 FCM_FaultTextInfo;
    Boolean FCM_HMASetFb;
    UInt8 FCM_HMASts;
    Boolean FCM_HMA_HighbeamReq;
    Boolean FCM_ICASetFb;
    Boolean FCM_ICATruckSetFb;
    UInt8 FCM_LDWAlertMethodSetFb;
    UInt8 FCM_LDWAudioWarn;
    Boolean FCM_LDWSetFb;
    UInt8 FCM_LDWSts;
    Boolean FCM_LKASetFb;
    UInt8 FCM_LKASts;
    Boolean FCM_LKA_AudioWarning;
    UInt8 FCM_Laterallimit;
    UInt8 FCM_LeLineColorFct;
    Boolean FCM_PCWLatentWarn;
    Boolean FCM_PCWPreWarn;
    UInt8 FCM_RAEB_WorkSts;
    UInt8 FCM_RiLineColorFct;
    UInt8 FCM_SLIFOperSts;
    UInt8 FCM_SLIFSetFb;
    UInt8 FCM_SLWFSetFb;
    UInt8 FCM_TJATakeoverReq;
    UInt8 FCM_TSRLatDst;
    UInt8 FCM_TSRLgtDst;
    UInt8 FCM_TSRSpdLim;
    UInt8 FCM_TSRSpdLimSts;
    Boolean FCM_TSRSpdLimWarn;
    Boolean FCM_TSRSpdLimWarnAu;
    Boolean FCM_TSR_SetFb;
    UInt8 FCM_TarObjACC;
    UInt8 FCM_TauGapSet;
    UInt8 FCM_TextInfoLKA1;
    UInt8 FCM_TrfcSign;
    UInt16 FCM_vSetDis;
} FCM_A_CHA;

#define _DEFINED_TYPEDEF_FOR_FCM_A_CHA_

typedef struct
{
    UInt8 FCM_ABALevel;
    Boolean FCM_ABAReq;
    Boolean FCM_ABPReq;
    UInt8 FCM_ACCSuppAbort;
    UInt8 FCM_ACCWhlDece;
    Boolean FCM_ACCWhlTqReqActv;
    UInt16 FCM_ACCWhlTqReqVal;
    UInt8 FCM_ACC_ShutdownMode;
    Boolean FCM_AEBReq;
    Boolean FCM_AEBStandstillSts;
    Boolean FCM_AEBStandstillStsV;
    UInt16 FCM_AEBTgtAx;
    UInt8 FCM_AEB_Status;
    UInt8 FCM_AWBLevel;
    Boolean FCM_AWBReq;
    UInt8 FCM_AccMode;
    Boolean FCM_AccReqDriveOff;
    Boolean FCM_AccReqStandstill;
    UInt8 FCM_AccTarAccrn;
    Boolean FCM_AccTarAccrnReqActv;
    UInt8 FCM_AccTgtAx;
    Boolean FCM_AccTgtAxReq;
    UInt8 FCM_ActDrvAsstSts;
    UInt8 FCM_AhdObjID;
    UInt8 FCM_B_AliveCnt1;
    UInt8 FCM_B_AliveCnt2;
    UInt8 FCM_B_AliveCnt3;
    UInt8 FCM_B_AliveCnt4;
    UInt8 FCM_B_AliveCnt5;
    UInt8 FCM_B_Chksum1;
    UInt8 FCM_B_Chksum2;
    UInt8 FCM_B_Chksum3;
    UInt8 FCM_B_Chksum4;
    UInt8 FCM_B_Chksum5;
    Boolean FCM_CrvDecelSta;
    Boolean FCM_DAEPSModeReq;
    Boolean FCM_DrvrWarnVibReq;
    Boolean FCM_EBAReq;
    UInt8 FCM_ELKSts;
    UInt8 FCM_ELKSuppsAbortn;
    UInt8 FCM_EPBReq;
    Boolean FCM_EPBReqV;
    UInt8 FCM_EPSCtrlReq;
    UInt16 FCM_EPSSetSteerWhlAgl;
    UInt8 FCM_FltSts;
    UInt8 FCM_HMASuppsAbortn;
    UInt8 FCM_LKALDWSuppsAbortn;
    UInt8 FCM_LKATorqFactReq;
    Boolean FCM_LgtFctActvFlg;
    Boolean FCM_OvertakeAssSysSts;
    UInt8 FCM_SteerTqReqActive;
    UInt8 FCM_TJAICASuppsAbortn;
    UInt8 FCM_TurnLampReq;
} FCM_B_CHA;

#define _DEFINED_TYPEDEF_FOR_FCM_B_CHA_

typedef struct
{
    Boolean VGSM_INVRunEnbl_flg;
    UInt8 VGSM_ReqEPB_enum;
    Boolean VGSM_ReqEPBV_flg;
    UInt8 VGSM_VehActGearPstn_enum;
    Boolean VGSM_VehActGearPstnV_flg;
    Boolean VGSM_VehPGearErr_flg;
    Boolean VGSM_VehSpdFstWrn_flg;
    Boolean VGSM_GrShftInhbed_flg;
    UInt8 VGSM_VehTgtGrReq_enum;
    UInt8 VGSM_PGrSwSts_enum;
} GSM_outputs;

#define _DEFINED_TYPEDEF_FOR_GSM_outputs_

typedef struct
{
    UInt8 VHMI_InfoDisp_enum;
    UInt8 VHMI_12VBatLoVolSta_enum;
} HMI_outputs;

#define _DEFINED_TYPEDEF_FOR_HMI_outputs_

typedef struct
{
    UInt8 CDC_BackLadjval;
    UInt8 HU_ACAutoCtl;
    UInt8 HU_ACPowerCtl;
    UInt8 HU_ACUnlockVentSet;
    UInt8 HU_AirInletModeSet;
    UInt8 HU_BCMCargoLightSet;
    UInt8 HU_BCMOTAModeSet;
    UInt8 HU_B_AliveCnt1;
    UInt8 HU_B_AliveCnt2;
    UInt8 HU_B_AliveCnt3;
    UInt8 HU_B_Chksum1;
    UInt8 HU_B_Chksum2;
    UInt8 HU_B_Chksum3;
    UInt8 HU_BlowerModeSet;
    UInt8 HU_ChargingRequest;
    UInt8 HU_Chargingmode;
    UInt8 HU_ChgWiperMtMdSwSet;
    UInt8 HU_CoastRecupModeSelect;
    UInt8 HU_DrivingModeSelect;
    UInt8 HU_DrivingPowerSet;
    UInt8 HU_FlwrMeHmCtrl;
    UInt8 HU_FrontFanSpdSet;
    UInt8 HU_HybridEcoModeSet;
    UInt8 HU_IllmndEntrySts;
    UInt8 HU_IllmndLockSts;
    UInt8 HU_IllmndUnlockSts;
    UInt8 HU_LeftTempSet;
    UInt8 HU_LockHornOnSt;
    UInt8 HU_MaiDrvrSeatHeat;
    UInt8 HU_ManualDefrostCtl;
    UInt8 HU_OverspdCntrlLockSet;
    UInt8 HU_ParkAutoUnlckSet;
    UInt8 HU_PeristalsisModeEnb;
    Boolean HU_PwrOFFReq;
    UInt8 HU_RearMirrorHeat;
    UInt8 HU_RecuperatePowerSet;
    UInt8 HU_SteerWhlHeat;
    Boolean HU_TPMSResetReq;
    UInt8 HU_TrunkLockSwCtrl;
    UInt8 HU_VehMaxCurrent;
    UInt8 HU_WiprIntlTimeSet;
    UInt8 TBOX_AC_RemtCtrlFlag;
    UInt8 TBOX_AC_TempSet;
    UInt8 TBOX_RemotePowerLock;
    Boolean TBOX_RemotePowerLockV;
    UInt8 TBOX_RemtMaiDrSeatHeatReq;
    UInt8 TBOX_RemtPowerCtrlReq;
    UInt8 TBOX_RemtSteerWhlHeatReq;
    UInt8 TBOX_VCU_CCM_SpeedLimitLevel;
    Boolean TBOX_VCU_ChargingConditions;
    Boolean TBOX_VCU_OperatLicence;
    Boolean TBOX_VCU_Version;
    UInt8 TBox_OpenVentilation;
    UInt8 TBox_RemoteCarSearch;
    UInt8 TBox_RemoteLock;
    UInt8 Tbox_RemoteDefrostCtl;
} HU_B_BAC;

#define _DEFINED_TYPEDEF_FOR_HU_B_BAC_

typedef struct
{
    UInt8 HVCH_RequestTemp;
    UInt8 HVCH_RequestPower;
    UInt8 HVCH_Enabled;
} HVCH_Command_BOD;

#define _DEFINED_TYPEDEF_FOR_HVCH_Command_BOD_

typedef struct
{
    UInt8 HVCHSts1_Checksum;
    UInt8 HVCHSts1_RollingCounter;
    Boolean HVCH_HVState;
    UInt8 HVCH_InletTemp;
    UInt8 HVCH_OutletTemp;
    UInt8 HVCH_PCBTemp;
    UInt8 HVCH_State;
    Boolean HVCH_WorkMode;
} HVCH_Status1_BOD;

#define _DEFINED_TYPEDEF_FOR_HVCH_Status1_BOD_

typedef struct
{
    UInt8 HVCHSts2_Checksum;
    UInt8 HVCHSts2_RollingCounter;
    UInt8 HVCH_Current;
    UInt8 HVCH_FaultCode;
    UInt8 HVCH_HV_Volts;
    UInt8 HVCH_Power;
    UInt8 HVCH_WorkState;
} HVCH_Status2_BOD;

#define _DEFINED_TYPEDEF_FOR_HVCH_Status2_BOD_

typedef struct
{
    UInt8 VHVM_VCUMode_enum;
    UInt8 VHVM_SysSta_enum;
    UInt8 VHVM_PTActOprtMode_enum;
    Boolean VHVM_EmgcySdn_flg;
    Boolean VHVM_WakeUpBMS_flg;
    UInt8 VHVM_BMSWakeUpMode_enum;
    Boolean VHVM_Bat2DrvTrainEnbl_flg;
    UInt8 VHVM_BMSShutdown_enum;
    UInt8 VHVM_DCCOprtCmd_enum;
    UInt8 VHVM_OBCOprtCmd_enum;
    Boolean VHVM_INVEnbl_flg;
    Boolean VHVM_EnaDisChg_flg;
    Boolean VHVM_ECUSleepAllwd_flg;
    UInt8 VHVM_ChrgAllowCmd_enum;
    Boolean VHVM_ChrgEnaDC_flg;
    Float VHVM_MaxChrgVoltDC_V;
    Float VHVM_MaxChrgCurntDC_A;
    UInt8 VHVM_ChrgEnaAC_enum;
    Float VHVM_MaxHVDCVoltAC_V;
    Float VHVM_MaxHVDCCurntAC_A;
    UInt8 VHVM_MaxChrgCurntAC_A;
    UInt8 VHVM_ACChrgMaxCurrFb_A;
    Float VHVM_DCCBuckLVVolt_V;
    Boolean VHVM_OTAModeSts_flg;
    UInt8 VHVM_ACChrgModeFb_enum;
    Boolean VHVM_HVRdy_flg;
} HVM_outputs;

#define _DEFINED_TYPEDEF_FOR_HVM_outputs_

typedef struct
{
    Boolean HornDrv;
    UInt8 LockHoornOnStFb;
    UInt8 LockHoornOnSt;
    Boolean HornSwCtl;
    UInt8 PartArmedSta;
    UInt8 ArmedSta;
    UInt8 AlarmSta;
    UInt8 SeekSta;
    UInt8 AntiLckSta;
    UInt8 TrunkWarnSta;
} HornCtl;

#define _DEFINED_TYPEDEF_FOR_HornCtl_

typedef struct
{
    UInt32 ICU_ICUTotalOdometer;
    UInt32 ICU_ICUTripAOdometer;
    UInt32 ICU_ICUTripBOdometer;
} ICU_2_Odo_BAC;

#define _DEFINED_TYPEDEF_FOR_ICU_2_Odo_BAC_

typedef UInt8 rt_Array_UInt8_8[8];

#define _DEFINED_TYPEDEF_FOR_rt_Array_UInt8_8_

typedef struct
{
    UInt8 INV_1_ActMode;
    UInt16 INV_1_ActTorque;
    UInt8 INV_1_ActiveDischarge_Status;
    UInt8 INV_1_CheckSum;
    Boolean INV_1_HasDerating;
    UInt8 INV_1_MotMode;
    UInt16 INV_1_MotSpeed;
    UInt8 INV_1_PreChargeAllowed;
    UInt8 INV_1_RollingCounter;
    UInt8 INV_1_ShutdownAllowed;
    UInt8 INV_AntithftAuthRslt;
    Boolean INV_PreprogmFlg;
    Boolean INV_SlipStatus;
} INV_1_Value_EPT;

#define _DEFINED_TYPEDEF_FOR_INV_1_Value_EPT_

typedef struct
{
    UInt8 INV_2_CheckSum;
    UInt8 INV_2_Derating;
    UInt8 INV_2_IgbtMaxTem;
    UInt16 INV_2_InpCurrent;
    UInt16 INV_2_InpVoltage;
    UInt8 INV_2_MotorMaxTem;
    UInt8 INV_2_RollingCounter;
} INV_2_Value_EPT;

#define _DEFINED_TYPEDEF_FOR_INV_2_Value_EPT_

typedef struct
{
    UInt8 INV_3_CheckSum;
    UInt16 INV_3_DriveTqAllowedMax;
    UInt16 INV_3_RecuperationTqAllowedMax;
    UInt8 INV_3_RollingCounter;
    Boolean INV_ActiveDampingMark;
    UInt16 INV_ActiveDampingValue;
} INV_3_Value_EPT;

#define _DEFINED_TYPEDEF_FOR_INV_3_Value_EPT_

typedef struct
{
    UInt8 INV_4_CheckSum;
    UInt16 INV_4_ErrBits;
    UInt8 INV_4_FaultLevl;
    UInt16 INV_4_PhaseU_AC_Current;
    UInt16 INV_4_PhaseV_AC_Current;
    UInt8 INV_4_RollingCounter;
} INV_4_Value_EPT;

#define _DEFINED_TYPEDEF_FOR_INV_4_Value_EPT_

typedef struct
{
    UInt8 INV_LrngData02;
    UInt8 INV_LrngData03;
    UInt8 INV_LrngData04;
    UInt8 INV_LrngData05;
    UInt8 INV_LrngData06;
    UInt8 INV_LrngData07;
    UInt8 INV_LrngSts;
    UInt8 INV_LrngSubID;
} INV_IMMO_Req_EPT;

#define _DEFINED_TYPEDEF_FOR_INV_IMMO_Req_EPT_

typedef struct
{
    UInt8 TurnIndcrLCtlFlg;
    UInt8 TurnIndcrRCtlFlg;
    UInt8 BackLampCtlFlg;
    UInt8 BrakeLightCtlFlg;
    UInt8 ReverseLampCtlFlg;
    UInt8 DayRunLightCtlFlg;
    UInt8 PosLampCtlFlg;
    UInt8 DomeLampCtlFlg;
    UInt8 LowBeamCtlFlg;
    UInt8 HiBeamCtlFlg;
    UInt8 FogLampFCtlFlg;
    UInt8 FogLampRCtlFlg;
    UInt8 TrunkUnlckCtlFlg;
    UInt8 DoorUnlckCtlFlg;
    UInt8 DoorLlckCtlFlg;
    UInt8 WiperHiSpdCtlFlg;
    UInt8 WiperLowSpdCtlFlg;
    UInt8 WinFRCloselFlg;
    UInt8 WinFROpenFlg;
    UInt8 IG1RlyCtlFlg;
    UInt8 IG2RlyCtlFlg;
    UInt8 HornCtlFlg;
    UInt8 BatSaveCtlFlg;
    UInt8 BSDRightCtlFlg;
    UInt8 BSDLeftCtlFlg;
    UInt8 WinFLCloselFlg;
    UInt8 WinFLOpenFlg;
} IODID;

#define _DEFINED_TYPEDEF_FOR_IODID_

typedef struct
{
    Float VIPC_AccPedPstn_pct;
    Boolean VIPC_AccPedPstnVld_flg;
    UInt8 VIPC_AccPedSnsrSta_enum;
    Boolean VIPC_DrvSw_flg;
    Float VIPC_AccPedZeroPstn_pct;
    Float VIPC_BrkPedPstn_pct;
    Boolean VIPC_BrkPedPstnVld_flg;
    Boolean VIPC_BrkSwActv_flg;
    Float VIPC_TireRadius_m;
    Boolean VIPC_CCSCfgd_flg;
    Boolean VIPC_ACCCfgd_flg;
    Boolean VIPC_HDCCfgd_flg;
    Boolean VIPC_iTPMSCfgd_flg;
    Boolean VIPC_EPBAppld_flg;
    Boolean VIPC_EPBReld_flg;
    UInt8 VIPC_CrpModeAct_enum;
    UInt8 VIPC_DrvModeAct_enum;
    Boolean VIPC_SnowMode_flg;
    UInt8 VIPC_RegenModeAct_enum;
    UInt8 VIPC_DrvPwrIntnsty_pct;
    UInt8 VIPC_RegenPwrIntnsty_pct;
    Boolean VIPC_VpedAutoCrp_flg;
    Float VIPC_VehSpd_kph;
    Boolean VIPC_VehSpdVld_flg;
    Float VIPC_VehSpdDrvn_kph;
    Boolean VIPC_VehSpdDrvnVld_flg;
    Float VIPC_VehSpdNonDrvn_kph;
    Boolean VIPC_VehSpdNonDrvnVld_flg;
    Float VIPC_WhlSpdFL_kph;
    Boolean VIPC_WhlSpdFLVld_flg;
    Float VIPC_WhlSpdFR_kph;
    Boolean VIPC_WhlSpdFRVld_flg;
    Float VIPC_WhlSpdRL_kph;
    Boolean VIPC_WhlSpdRLVld_flg;
    Float VIPC_WhlSpdRR_kph;
    Boolean VIPC_WhlSpdRRVld_flg;
    UInt8 VIPC_VehHiddenMode_enum;
} IPC_outputs;

#define _DEFINED_TYPEDEF_FOR_IPC_outputs_

typedef struct
{
    UInt8 IPU_DCC_1_AliveCnt;
    UInt8 IPU_DCC_1_Chksum;
    UInt8 IPU_DCC_ActlOprtMode;
    Boolean IPU_DCC_DeratingOprtSta;
    UInt8 IPU_DCC_Errbit;
    UInt16 IPU_DCC_LowVolActlCur;
    UInt8 IPU_DCC_LowVolActlVol;
    Boolean IPU_DCC_PrechargeComplete;
    UInt8 IPU_DCC_SysFailSta;
    Boolean IPU_HVILFailSta;
    Boolean IPU_OverTemperatureFail;
} IPU_DCC_1_State_EPT;

#define _DEFINED_TYPEDEF_FOR_IPU_DCC_1_State_EPT_

typedef struct
{
    UInt8 IPU_DCC_2_AliveCnt;
    UInt8 IPU_DCC_2_Chksum;
    UInt16 IPU_DCC_HighVoltActlCur;
    UInt16 IPU_DCC_HighVoltActlVol;
} IPU_DCC_2_ChrgInValue_EPT;

#define _DEFINED_TYPEDEF_FOR_IPU_DCC_2_ChrgInValue_EPT_

typedef struct
{
    UInt8 IPU_OBC_1_AliveCnt;
    UInt8 IPU_OBC_1_Chksum;
    UInt8 IPU_OBC_ActlOprtMode;
    Boolean IPU_OBC_ConnectMainSta;
    UInt8 IPU_OBC_Errbit;
    UInt8 IPU_OBC_HVDC_ActlCur;
    UInt16 IPU_OBC_HVDC_ActlVol;
    UInt16 IPU_OBC_InleltActlPower;
    UInt8 IPU_OBC_InletConnctSta;
    UInt8 IPU_OBC_Request;
    UInt8 IPU_OBC_SysFailSta;
} IPU_OBC_1_State_EPT;

#define _DEFINED_TYPEDEF_FOR_IPU_OBC_1_State_EPT_

typedef struct
{
    UInt8 IPU_DeviceIntTemp;
    UInt8 IPU_OBC_2_AliveCnt;
    UInt8 IPU_OBC_2_Chksum;
    UInt16 IPU_OBC_ACMaxPwAllow;
    UInt8 IPU_OBC_Inlet_Electronic_Lock;
    Boolean IPU_OBC_S2_State;
    UInt8 IPU_OBC_TempInlet;
    Boolean IPU_OBC_VoltageOkL1;
    Boolean IPU_OBC_VoltageOkL2;
    Boolean IPU_OBC_VoltageOkL3;
    UInt8 IPU_OBC_Wake_Up_Mode;
} IPU_OBC_2_Inlet_EPT;

#define _DEFINED_TYPEDEF_FOR_IPU_OBC_2_Inlet_EPT_

typedef struct
{
    Boolean PosLampSw;
    Boolean LowBeamSw;
    Boolean HiBeamSw;
    Boolean PassLightSw;
    Boolean TurnIndcrLSw;
    Boolean TurnIndcrLaneLSw;
    Boolean TurnIndcrRSw;
    Boolean TurnIndcrLaneRSw;
    Boolean FogLampRSw;
    Boolean HazardLightSw;
    Boolean BrakeLightSw;
    UInt16 LightIntstVal;
    Boolean AutoLampSw;
    Boolean PosLampSta;
    Boolean DayRunLightSta;
    Boolean BrakeLightSta;
    Boolean BSDRightCtl;
    Boolean BSDLeftCtl;
    Boolean LowBeamSta;
    Boolean FogLampRSta;
    Boolean ReverseLampSta;
    UInt8 LightIntstSta;
    Boolean HiBeamSta;
    UInt8 DomeLampPwmDuty;
    Boolean TurnIndcrRSta;
    Boolean TurnIndcrLSta;
    UInt8 VehSeekSta;
    Boolean ThermalrunawaySta;
    Boolean EmerSta;
    Boolean ArmedSta;
    Boolean CrashSta;
    Boolean DisarmedSta;
    UInt8 PartArmedSta;
    Boolean AlrmSta;
    Boolean EmerHazardLightSta;
    Boolean HazardLightSta;
    UInt8 TurnIndcrMod;
    Boolean PassLightSta;
    Boolean AutoLampSta;
    Boolean BoxLampSta;
    Boolean WelcomeLampSta;
    Boolean FlwrMeHomeSta;
    UInt8 FlwrMeHomeCtlFb;
    UInt16 FlwrMeHomeTim;
    Boolean TurnIndcrLOpen;
    Boolean TurnIndcrLShort;
    Boolean TurnIndcrROpen;
    Boolean TurnIndcrRShort;
    UInt8 RKEReq;
    Boolean KnobBeamFaultSta;
    Boolean RodBeamFaultSta;
    UInt8 BackLadjvalFb;
    UInt8 J408BackLampPWM;
    Boolean FogLampFSw;
    Boolean FogLampFSta;
    Boolean LampDelay;
    Boolean AntiLckSta;
    Boolean TrunkWarnSta;
    Boolean LowBeamShortToBat;
    Boolean HiBeamShortToBat;
    UInt8 VehSeekStaFb;
    Boolean AutoHiBeam;
    Boolean BrkLampShortToBatOrOpen;
    Boolean BrkLampShortToGnd;
} LampCtl;

#define _DEFINED_TYPEDEF_FOR_LampCtl_

typedef struct
{
    Boolean VNVM_EEImdtReadOK_flg;
    Boolean VNVM_VCUVerFb_flg;
    UInt8 VNVM_VCUSpdLimSt_enum;
    Boolean VNVM_TBOXOffline_flg;
    Boolean VNVM_HVRdy_flg;
    UInt8 VNVM_PTActOprtMode_enum;
    UInt8 VNVM_VehActGearPstn_enum;
    UInt8 VNVM_AccPedZeroPstn_pct;
    UInt8 VNVM_ECURstCntr_cnt;
} NVM_Imdt_outputs;

#define _DEFINED_TYPEDEF_FOR_NVM_Imdt_outputs_

typedef struct
{
    Boolean VNVM_EE01ReadOK_flg;
    UInt8 VNVM_IBSChrgNum_cnt;
    UInt8 VNVM_IBSChrgFailNum_cnt;
    Boolean VNVM_iTPMSWrng_flg;
    UInt8 VNVM_XWhlDistErrRefStat_enum;
    UInt8 VNVM_DrvModeAct_enum;
    UInt8 VNVM_RegenModeAct_enum;
    UInt8 VNVM_CrpModeAct_enum;
    UInt8 VNVM_DrvPwrIntnsty_pct;
    UInt8 VNVM_RegenPwrIntnsty_pct;
    Float VNVM_XWhlDistErrRef_mpkm;
    Float VNVM_DynRmnMilEst_km;
    Float VNVM_AvgPwrCnsm_kWh100km;
    Float VNVM_AvgSOCCnsmWght_pctp100km;
    UInt8 VNVM_ACChrgMaxCurrFb_A;
    UInt8 VNVM_ACChrgModeFb_enum;
} NVM_outputs;

#define _DEFINED_TYPEDEF_FOR_NVM_outputs_

typedef struct
{
    UInt8 SysPwrMode;
    UInt8 J421IG1RlyCtl;
    UInt8 J437IG2RlyCtl;
    Boolean IG1RelayFault;
    Boolean IG2RelayFault;
    Boolean SysPwrModeV;
    UInt8 SysPowerSts;
    Boolean PwrOn;
    UInt8 SysPwrModeAct;
    Boolean StartReq;
    Boolean IGRlyIIgCls;
    UInt8 RemotePwrLckSta;
    Boolean RemotePwrLckFb;
    UInt8 RemotePwrCtlFb;
} PDUCtl;

#define _DEFINED_TYPEDEF_FOR_PDUCtl_

typedef struct
{
    UInt8 KeyInCarSta;
    UInt8 FRPEAuthentAcsd;
    UInt8 DrvPEAuthentAcsd;
    UInt8 AvaluebleKeyInCar;
    UInt8 PSAuthentRes;
    UInt8 WarnNoKeyFound;
    UInt8 KeySta;
    UInt8 IndicationKeyCloser;
    UInt8 UnlckWlcmReq;
    UInt8 LckWlcmReq;
    UInt8 FrbdnKeyNr;
    UInt8 KeyLoBattLvlWarn;
    UInt8 WarnKeyOutReminder;
    UInt8 PSReq;
    UInt8 IMMOKey;
} PEPSCtl;

#define _DEFINED_TYPEDEF_FOR_PEPSCtl_

typedef struct
{
    Float VRME_CHTCRmnMilEst_km;
    Boolean VRME_CHTCRmnMilEstV_flg;
    Float VRME_DynRmnMilEst_km;
    Boolean VRME_DynRmnMilEstV_flg;
    Float VRME_VehSOCCnsmIns_pctp100km;
    Float VRME_VehSOCCnsmAvg_pctp100km;
    Float VRME_VehPwrCnsmIns_kWhp100km;
    Float VRME_VehPwrCnsmAvg_kWhp100km;
} RME_outputs;

#define _DEFINED_TYPEDEF_FOR_RME_outputs_

typedef struct
{
    Boolean J42Heat;
} RVMCtl;

#define _DEFINED_TYPEDEF_FOR_RVMCtl_

typedef struct
{
    UInt8 SCS_FrntWiprSwtSt;
    Boolean SCS_FrntWshrSwtSt;
    Boolean SCS_FrntWshrSwtStVD;
    Boolean SCS_HiBeamSwtSt;
    Boolean SCS_KnobBeamSwtStVD;
    Boolean SCS_LampAutoSt;
    UInt8 SCS_LeSwitchSts_AliveCnt;
    UInt8 SCS_LeSwitchSts_Chksum;
    Boolean SCS_LeTurnLmpSwtSt;
    Boolean SCS_LeftSwtVD;
    Boolean SCS_Left_1Swt;
    Boolean SCS_Left_2Swt;
    Boolean SCS_Left_3Swt;
    Boolean SCS_Left_4Swt;
    Boolean SCS_Left_5Swt;
    Boolean SCS_Left_6Swt;
    Boolean SCS_Left_7Swt;
    Boolean SCS_Left_8Swt;
    Boolean SCS_LowBeamSwtSt;
    Boolean SCS_OverVehBeamSwtSt;
    Boolean SCS_PositionLightswitchSt;
    UInt8 SCS_RearWiprSwtSt;
    Boolean SCS_RiTurnLmpSwtSt;
    Boolean SCS_RodBeamSwtStVD;
    Boolean SCS_WasrSwtStVD;
    Boolean SCS_WiprSwtStVD;
} SCS_LeSwitchSts_BOD;

#define _DEFINED_TYPEDEF_FOR_SCS_LeSwitchSts_BOD_

typedef struct
{
    UInt8 SCS_GearShiftLeverPstReq;
    Boolean SCS_GearShiftLeverPstReqVD;
    UInt8 SCS_RiSwitchSts_AliveCnt;
    UInt8 SCS_RiSwitchSts_Chksum;
    Boolean SCS_RightSwtVD;
    Boolean SCS_Right_10Swt;
    Boolean SCS_Right_11Swt;
    Boolean SCS_Right_12Swt;
    Boolean SCS_Right_13Swt;
    Boolean SCS_Right_14Swt;
    Boolean SCS_Right_15Swt;
    Boolean SCS_Right_16Swt;
    Boolean SCS_Right_9Swt;
} SCS_RiSwitchSts_BOD;

#define _DEFINED_TYPEDEF_FOR_SCS_RiSwitchSts_BOD_

typedef struct
{
    UInt8 SRS_1_AliveCnt;
    UInt8 SRS_1_Chksum;
    UInt8 SRS_AirbagWarningLampSts;
    UInt8 SRS_CrashOutputSts;
    UInt8 SRS_DrvSeatBeltRSt;
    Boolean SRS_DrvSeatbeltBuckleValid;
    Boolean SRS_DrvSeatbeltBucklestatus;
    Boolean SRS_MidSeatBeltBuckleValid;
    Boolean SRS_MidSeatBeltBucklestatus;
    UInt8 SRS_MidSeatOccupantSensorSts;
    UInt8 SRS_PassAirbSts;
    UInt8 SRS_PassSeatOccupantSensorSts;
    Boolean SRS_PassSeatbeltBuckleValid;
    Boolean SRS_PassSeatbeltBucklestatus;
    Boolean SRS_PassengerAirbagSta_Rsvr;
    UInt8 SRS_PsSeatBeltRSt;
} SRS_1_Status_CHA;

#define _DEFINED_TYPEDEF_FOR_SRS_1_Status_CHA_

typedef struct
{
    UInt8 MaiDrvSeatStFb;
    UInt8 CN167DrvSeatHtPWM;
    SInt8 DrvSeatTemp;
    Boolean DrvNTCShort;
    Boolean DrvNTCOpen;
    UInt8 RemtHeatFb;
} SeatCtl;

#define _DEFINED_TYPEDEF_FOR_SeatCtl_

typedef struct
{
    UInt8 SteerWhlHeatSts;
    Boolean J447SteerWhlHt;
    SInt8 SteerWhlTemp;
    UInt8 RemtHeatFb;
} SteerWhlCtl;

#define _DEFINED_TYPEDEF_FOR_SteerWhlCtl_

typedef struct
{
    UInt8 TBOX_BJS_AliveCnt;
    UInt8 TBOX_BJS_Chksum;
    UInt8 TBOX_BJS_Time_Day;
    UInt8 TBOX_BJS_Time_Hour;
    UInt8 TBOX_BJS_Time_Min;
    UInt8 TBOX_BJS_Time_Month;
    UInt8 TBOX_BJS_Time_Sec;
    UInt8 TBOX_BJS_Time_Year;
} TBOX_BJS_Time_BAC;

#define _DEFINED_TYPEDEF_FOR_TBOX_BJS_Time_BAC_

typedef struct
{
    UInt8 VTBX_VCUVerSetFb_enum;
    Boolean VTBX_VCUVerFb_flg;
    UInt8 VTBX_VCUSpdLimLvlSetFb_enum;
    UInt8 VTBX_VCUSpdLimLvlFb_enum;
    Boolean VTBX_VCUOprtLicFb_flg;
    Boolean VTBX_VCUChrgngCondsFb_flg;
    UInt8 VTBX_VCULckVehWrn_enum;
    Boolean VTBX_ReqLimpHome_flg;
    Boolean VTBX_TBOXOffline_flg;
    UInt8 VTBX_VCUSpdLimSt_enum;
    Boolean VTBX_VCURmtACCtrlReq_flg;
    Boolean VTBX_VCURmtACDefrstReq_flg;
    UInt8 VTBX_VCURmtACCtrlSt_enum;
    Boolean VTBX_RmtACPwrReq_flg;
} TBOX_outputs;

#define _DEFINED_TYPEDEF_FOR_TBOX_outputs_

typedef struct
{
    UInt8 AC_1_Chksum;
    UInt8 AC_1_AliveCnt;
    Boolean AC_CompFailModeOprtSta;
    Boolean AC_CompOprtReq;
    Boolean AC_CompOprtEnaCmd;
    UInt16 AC_CompTgtSpd;
    Float AC_CompMaxAllowPwrCmsp;
    UInt8 AC_PumpActlSpdDuty;
    Float AC_HighVolDCTolalPwr;
    Boolean AC_PumpActlSpdDutyV;
} TMS2VCU_AC_1_Command_Outputs;

#define _DEFINED_TYPEDEF_FOR_TMS2VCU_AC_1_Command_Outputs_

typedef struct
{
    UInt8 AC_2_Chksum;
    UInt8 AC_2_AliveCnt;
    Float AC_HVHActlPwr_HVAC;
    SInt8 AC_HVHDeviceInternTemp_HVAC;
    Float TMS_PTPressure;
    Float AC_ActTotalPower;
    Boolean AC_HVHFailSta_HVAC;
    Boolean AC_FailSta;
    Boolean TMSR_BattTempCtrlRmnSwtFb;
    Boolean AC_BatPumpFailSta;
    UInt8 AC_HVHActlOprtMode_HVAC;
    UInt8 AC_ActlOprtMode;
    SInt8 TMS_PTTemp;
} TMS2VCU_AC_2_State_Outputs;

#define _DEFINED_TYPEDEF_FOR_TMS2VCU_AC_2_State_Outputs_

typedef struct
{
    UInt8 AC_3_Chksum;
    UInt8 AC_3_AliveCnt;
    Boolean AC_ExtdDefrostActvReq;
    Boolean AC_EnvirTempV;
    Float AC_IndoorTemp;
    Float AC_EnvirTemp;
    SInt8 TMS_OHXOutTmp;
    SInt8 TMS_EvapTmp;
    SInt8 TMS_EvapOutTmp;
    SInt8 TMS_ChillerOutTmp;
} TMS2VCU_AC_3_State_Outputs;

#define _DEFINED_TYPEDEF_FOR_TMS2VCU_AC_3_State_Outputs_

typedef struct
{
    UInt8 AC_8_Checksum;
    UInt8 AC_8_RollingCounter;
    Boolean AC_RefrgLoPressureV;
    Float AC_RefrgLoPressure;
    Boolean AC_L_Currt_Slct_Frg_Dirct;
    UInt8 AC_HV_PTC_heating_rq;
    SInt8 AC_HV_PTC_MediumTemp;
    SInt8 AC_HV_PTC_InternalPCBTemp;
    Float AC_EvapTgtTemp;
    UInt8 AC_HV_PTC_On_Rq;
    UInt8 AC_Auto_FrontFanSpd;
} TMS2VCU_AC_8_status_Outputs;

#define _DEFINED_TYPEDEF_FOR_TMS2VCU_AC_8_status_Outputs_

typedef struct
{
    UInt8 AC_ACStatus_Chksum;
    UInt8 AC_ACStatus_AliveCnt;
    UInt8 AC_leftTempValue;
    Boolean AC_ManualDefrostFb;
    Boolean AC_ACAutoFb;
    UInt8 AC_BlowerModeSta;
    UInt8 AC_FrontFanSpdValue;
    Boolean AC_ACPowerFb;
    UInt8 AC_AutoBlowerModeSta;
    UInt8 AC_HybridEcoModeSta;
    UInt8 AC_AirInletModeSta;
    Boolean BCM_RearViewMirrHeatingSts;
} TMS2VCU_AC_ACStatuts_Outputs;

#define _DEFINED_TYPEDEF_FOR_TMS2VCU_AC_ACStatuts_Outputs_

typedef struct
{
    UInt8 AC_Checksum;
    UInt8 AC_RollingCounter;
    Float COMP_EcompSpeedCtrl;
    UInt8 COMP_EcompEnable;
    UInt8 COMP_EcompHVSt;
    UInt8 COMP_EcompErrorClean;
    Float COMP_CompInputPowerLimit;
    SInt8 TMS_ACPExhaustTmp;
    Float TMS_ACPInletPressure;
} TMS2VCU_AC_COMP_Outputs;

#define _DEFINED_TYPEDEF_FOR_TMS2VCU_AC_COMP_Outputs_

typedef struct
{
    UInt8 HVCHCmd_Checksum;
    UInt8 HVCHCmd_RollingCounter;
    SInt8 HVCH_RequestTemp;
    Float HVCH_RequestPower;
    UInt8 HVCH_Enabled;
} TMS2VCU_HVCH_Command_Outputs;

#define _DEFINED_TYPEDEF_FOR_TMS2VCU_HVCH_Command_Outputs_

typedef struct
{
    SInt8 TMS_MotInletCooltTemp;
    Float TMS_PwrCoolFanSpdDuty;
    UInt8 TMS_BATThermalMod;
    UInt8 TMS_CabThermalMod;
    UInt8 AC_ACUnlockVentSetFB;
    UInt8 CCU_RemoteLockFb;
    UInt8 CCU_RemoteCarSearchFb;
    UInt8 CCU_OpenVentilationFb;
    UInt8 AC_RemtCtrlFb;
    UInt8 AC_TempSetFb;
    UInt8 AC_RemoteDefrostCtlFb;
} TMS2VCU_PPVAddSignalGroup_Outputs;

#define _DEFINED_TYPEDEF_FOR_TMS2VCU_PPVAddSignalGroup_Outputs_

typedef struct
{
    Float TMS_AcPMPSpdSet;
    Float TMS_BatPMPSpdSet;
    Float TMS_MotPMPSpdSet;
    Float TMS_MotPMPRealRPM;
    Float TMS_BatPMPRealRPM;
    Float TMS_AcPMPRealRPM;
    UInt16 TMS_HPEXVPositionCmd;
} TMS2VCU_TMS_LINTestData1_Outputs;

#define _DEFINED_TYPEDEF_FOR_TMS2VCU_TMS_LINTestData1_Outputs_

typedef struct
{
    UInt16 TMS_BEXVPositionCmd;
    UInt16 TMS_BEXVCurrentPosition;
    UInt16 TMS_AEXVPositionReq;
    UInt16 TMS_AEXVCurrentPosition;
} TMS2VCU_TMS_LINTestData2_Outputs;

#define _DEFINED_TYPEDEF_FOR_TMS2VCU_TMS_LINTestData2_Outputs_

typedef struct
{
    UInt16 TMS_HPEXVCurrentPosition;
    UInt8 TMS_C5WVBPosSetReq;
    UInt8 TMS_C3WVBPosSetReq;
    Boolean TMS_HPEXVEnableCmd;
    Boolean TMS_BEXVEnableCmd;
    Boolean TMS_AEXVEnableReq;
    UInt16 TMS_C5WVPosRec;
    UInt16 TMS_C3WVPosRec;
    UInt8 TMS_C5WVMode;
    UInt8 TMS_C3WVMode;
} TMS2VCU_TMS_LINTestData3_Outputs;

#define _DEFINED_TYPEDEF_FOR_TMS2VCU_TMS_LINTestData3_Outputs_

typedef struct
{
    UInt8 TMS_AcPMPSpdSet;
    UInt8 TMS_BatPMPSpdSet;
    UInt8 TMS_MotPMPSpdSet;
    UInt8 TMS_MotPMPRealRPM;
    UInt8 TMS_BatPMPRealRPM;
    UInt8 TMS_AcPMPRealRPM;
    UInt16 TMS_HPEXVPositionCmd;
} TMS_LINTestData1_BOD;

#define _DEFINED_TYPEDEF_FOR_TMS_LINTestData1_BOD_

typedef struct
{
    UInt16 TMS_BEXVPositionCmd;
    UInt16 TMS_BEXVCurrentPosition;
    UInt16 TMS_AEXVPositionReq;
    UInt16 TMS_AEXVCurrentPosition;
} TMS_LINTestData2_BOD;

#define _DEFINED_TYPEDEF_FOR_TMS_LINTestData2_BOD_

typedef struct
{
    UInt16 TMS_HPEXVCurrentPosition;
    UInt8 TMS_C5WVBPosSetReq;
    UInt8 TMS_C3WVBPosSetReq;
    Boolean TMS_HPEXVEnableCmd;
    Boolean TMS_BEXVEnableCmd;
    Boolean TMS_AEXVEnableReq;
    UInt16 TMS_C5WVPosRec;
    UInt16 TMS_C3WVPosRec;
    UInt8 TMS_C5WVMode;
    UInt8 TMS_C3WVMode;
} TMS_LINTestData3_BOD;

#define _DEFINED_TYPEDEF_FOR_TMS_LINTestData3_BOD_

typedef struct
{
    UInt8 BJSTimeDay;
    UInt8 BJSTimeHour;
    UInt8 BJSTimeMonth;
    UInt16 BJSTimeYear;
    UInt8 HourDiff;
} TboxTim;

#define _DEFINED_TYPEDEF_FOR_TboxTim_

typedef struct
{
    UInt8 AppSwcTmsVersion;
    Boolean TMS_NMReq_flg;
    Boolean TMS_HVReq_flg;
    Boolean IOCtl_bPwrHVPart;
} Tms2Vcu_Info;

#define _DEFINED_TYPEDEF_FOR_Tms2Vcu_Info_

typedef struct
{
    Boolean VCU_0_BraSwi;
    Boolean VCU_0_DrvSwi;
    Boolean VCU_0_Zdznswi;
    UInt16 VCU_0_DrvPed;
    UInt8 VCU_MotDampngLmt;
    UInt8 VCU_AppSoftNumb;
} VCU_0_Value_EPT;

#define _DEFINED_TYPEDEF_FOR_VCU_0_Value_EPT_

typedef struct
{
    Boolean VCU_ActWhlTqVld;
    UInt16 VCU_ActWhlTq;
    Boolean VCU_DrvReqWhlTqVld;
    UInt16 VCU_DrvReqWhlTq;
    UInt16 VCU_DrvWhlTqAllwdMax;
    UInt8 VCU_PwrRecupActlWhlTqSts;
    UInt16 VCU_PwrRecupActWhlTq;
    UInt8 VCU_PwrRecupMaxAvlbWhlTqSts;
    UInt16 VCU_BrkPwrRecupMaxAvlbWhlTq;
    UInt8 VCU_BrkPwrRecupActlWhlTqSts;
    UInt16 VCU_BrkPwrRecupActWhlTq;
    Boolean VCU_AccReqDriveOff;
    UInt16 VCU_Actl_MotorRotateSpd;
    Boolean VCU_Actl_MotorRotateSpdV;
    UInt16 VCU_Actl_MotorTorque;
    Boolean VCU_Actl_MotorTorqueV;
    UInt16 VCU_DrvReq_MotorTorq;
    Boolean VCU_DrvReq_MotorTorqV;
    Boolean VCU_EparkSysSta;
    Boolean VCU_EnaEHBBrkRun;
    Boolean VCU_AccReqStandstill;
    UInt16 VCU_1_MotTorqueReqToEHB;
    UInt16 VCU_MasterCylinderPreReq;
} VCU_10_Torque_CHA;

#define _DEFINED_TYPEDEF_FOR_VCU_10_Torque_CHA_

typedef struct
{
    UInt8 VCU_1_MotModeReq;
    Boolean VCU_1_EnaDisChg;
    UInt8 VCU_1_MotDirReq;
    UInt16 VCU_1_MotTorqueReq;
    Boolean VCU_1_EnaInvRun;
    Boolean VCU_1_EmShutDown;
    UInt8 VCU_ShiftMotorParkReq;
    UInt16 VCU_1_MotSpdReq;
    Boolean VCU_INVSkid;
    UInt8 VCU_VhclTrgtGearPos;
} VCU_1_InvCmd_EPT;

#define _DEFINED_TYPEDEF_FOR_VCU_1_InvCmd_EPT_

typedef struct
{
    UInt8 VCU_MotoroutputCoolantTemp;
    UInt16 VCU_AllowHeatCoolMaxPwrCmsp;
    Boolean VCU_Bat2DrvTrainEnb;
    UInt8 VCU_ChrgEna_AC;
    UInt8 VCU_BMS_WakeupMode;
} VCU_3_OprtCmd_EPT;

#define _DEFINED_TYPEDEF_FOR_VCU_3_OprtCmd_EPT_

typedef struct
{
    UInt8 VCU_BMS_Shutdown;
    UInt8 VCU_ChrgAllowCmd;
    Boolean VCU_ChrgEna_DC;
    UInt16 VCU_MaxChrgCrnt_DC;
    UInt16 VCU_MaxChrgVol_DC;
    UInt8 VCU_OBCOprtCmd;
    UInt8 VCU_MaxChrgCurnt_AC;
} VCU_4_ChrgCmd_EPT;

#define _DEFINED_TYPEDEF_FOR_VCU_4_ChrgCmd_EPT_

typedef struct
{
    UInt8 VCU_ErrAmount;
    UInt8 VCU_EPK_ParkLock;
    UInt8 VCU_DCCOprtCmd;
    UInt8 VCU_SysFailSta;
    UInt16 VCU_ErrBit;
} VCU_B_AcclPedal_EPT;

#define _DEFINED_TYPEDEF_FOR_VCU_B_AcclPedal_EPT_

typedef struct
{
    UInt8 VCU_DCCBuckLV_Vol;
    Boolean VCU_OBCIntDischargeEnable;
    UInt16 VCU_DCCBoostHv_Vol;
    UInt16 VCU_MaxHVDC_Cur_AC;
    UInt16 VCU_MaxHVDC_Vol_AC;
} VCU_C_OprtCmd_EPT;

#define _DEFINED_TYPEDEF_FOR_VCU_C_OprtCmd_EPT_

typedef struct
{
    UInt8 VCU_AcclPedalPos;
    UInt8 VCU_BrkPedalPos;
    Boolean VCU_OTAModeSts;
    Boolean VCU_DrvReqTorqOverrideESC;
    UInt8 VCU_BrkPedalSnsrPosV_Reserved;
    Boolean VCU_ACCTrqCtrlAvl;
    Boolean VCU_StandStilDecelReq;
    UInt8 VCU_AcclPedalPosSnsrSta;
    UInt8 VCU_PGearSwcSt;
    Boolean VCU_DrvReqTorqOverrideFCM;
    UInt8 VCU_StandStilOverride;
    UInt16 VCU_StandStilTarDecelVal;
    UInt8 VCU_AcclPedalPosToESC;
    UInt8 VCU_PwrRecupMaxAvlbMotorTorqSta;
    UInt8 VCU_ReqEPB;
    Boolean VCU_ReqEPBV;
    UInt8 VCU_AcclPedalPosToESCSta;
    Boolean VCU_ParkSwStaV;
    Boolean VCU_ParkSwSta;
    Boolean VCU_StrgRecupReqBrkLampOn;
    Boolean VCU_GearShiftInhibited;
    UInt8 VCU_EPK_ParkLocktoCHA;
    UInt8 VCU_EPBApplyForbid;
    UInt8 VCU_AccTgtAx;
    Boolean VCU_AccTgtAxReq;
    UInt16 VCU_BraTorReq;
    Boolean VCU_ACCStandstillReq;
    Boolean VCU_PreKeReq;
    UInt8 VCU_CruiseCtrlSta;
    UInt16 VCU_CruiseCtrTgtSpd;
    UInt8 VCU_ReqAutoBrk;
    UInt8 VCU_ACCStatus;
} VCU_D_Status_CHA;

#define _DEFINED_TYPEDEF_FOR_VCU_D_Status_CHA_

typedef struct
{
    Boolean VCU_MotorActualPowerType;
    Boolean VCU_DrvRangeDistEstV;
    UInt16 VCU_DrvRangeDistEst;
    Boolean VCU_WLTPDrvgRngDstVldty;
    UInt16 VCU_WLTPDrvgRngDst;
    UInt16 VCU_ReservePower;
    UInt16 VCU_MotorActualPower;
    UInt8 VCU_DrvMotorSta;
    UInt8 VCU_InfoDisp;
    Boolean VCU_VhclPGearError;
    UInt16 VCU_VhclActlCnsmPwr;
    Boolean VCU_VhclSpeedFastWarn;
    UInt8 VCU_OBCOprtCmdToICU;
    Boolean VCU_MotorHighTempWrning;
    Boolean VCU_MCUHighTempWrning;
    UInt16 VCU_VhclPwrCnsmpAvrg;
    UInt8 VCU_ShiftKeyStagnation;
    UInt8 VCU_CCKeyStagnation;
    UInt8 VCU_DriveModeKeyStagnation;
    UInt8 VCU_SIBS_KL30Voltage;
    Boolean VCU_SIBS_ChgNumAllow;
    UInt8 VCU_SIBS_RTCWUChgNum;
    UInt8 VCU_SIBS_RTCChrgSt;
    UInt8 VCU_SIBS_RTCWUChgFailNum;
    Boolean BCM_IllmndLockStsFb;
    Boolean BCM_IllmndUnlockStsFb;
    Boolean VCU_SIBS_FbRTCWupFlg;
    Boolean VCU_SIBS_BMSBatSOCAllow;
    Boolean VCU_SIBS_WupVoltAllow;
    UInt8 VCU_VehActDrivingPwr;
    UInt8 VCU_VehActRecuperatePwr;
    UInt8 VCU_LockVehWarm;
    UInt8 VCU_ACChrgMode;
    UInt8 VCU_ACChrgMaxCurr;
    UInt8 AC_ACUnlockVentSetFB;
    UInt8 CCU_RemoteLockFb;
    UInt8 CCU_RemoteCarSearchFb;
    UInt8 CCU_OpenVentilationFb;
    UInt8 AC_RemtCtrlFb;
    UInt8 AC_TempSetFb;
    UInt8 AC_RemoteDefrostCtlFb;
    UInt8 VCU_VesionSetFb;
    UInt8 VCU_SpeedLimitLevelSetFb;
    Boolean VCU_VersionFb;
    Boolean VCU_OperatLicenceFb;
    UInt8 VCU_SpeedLimitLevelFb;
    UInt8 CCU_RemotePowerLockFb;
    Boolean VCU_WghConfdence;
    UInt16 VCU_WghEst;
    UInt8 VCU_WghDistb;
    UInt8 VCU_CruiseCtrlSta_forBAC;
    UInt16 VCU_CruiseCtrTgtSpd_forBAC;
    Boolean VCU_ChargingConditionsFb;
    Boolean VCU_RemtACCtrlReq;
    Boolean VCU_RemtACDefrostlReq;
    UInt8 VCU_RemtACCtrlSt;
    UInt8 CCU_RemtPowerCtrlFb;
    UInt8 CCU_RemtSteerWhlHeatFb;
    UInt8 CCU_RemtMaiDrSeatHeatFb;
} VCU_DispInfo_BAC;

#define _DEFINED_TYPEDEF_FOR_VCU_DispInfo_BAC_

typedef struct
{
    UInt8 VVSO_iTPMSState_enum;
    Float VVSO_XWhlDistErrRef_mpkm;
    UInt8 VVSO_XWhlDistErrRefStat_enum;
    Boolean VVSO_iTPMSWrng_flg;
    Float VVSO_VehMassEst_kg;
    Boolean VVSO_VehMassConf_flg;
    UInt8 VVSO_VehMassDistb_enum;
    Float VVSO_RoadSlopEst_pct;
    Float VVSO_RoadSlopTqEst_Nm;
    Float VVSO_VehDrvResistTq_Nm;
} VSO_outputs;

#define _DEFINED_TYPEDEF_FOR_VSO_outputs_

typedef struct
{
    Float VVTM_DrvReqMotorTorq_Nm;
    Boolean VVTM_DrvReqMotorTorqV_flg;
    Float VVTM_DrvReqWhlTq_Nm;
    Float VVTM_ActWhlTq_Nm;
    Float VVTM_BrkPwrRecActWhlTorq_Nm;
    UInt8 VVTM_BrkPwrRecActWhlTorqSt_enum;
    Float VVTM_BrkPwrRecMaxWhlTorq_Nm;
    UInt8 VVTM_BrkPwrRecMaxWhlTorqSta_enum;
    Float VVTM_PwrRecActWhlTorq_Nm;
    UInt8 VVTM_PwrRecActWhlTorqSta_enum;
    Boolean VVTM_PCUFailSta_flg;
    UInt8 VVTM_DrvMotorSta_enum;
    SInt16 VVTM_MotorSpdReq_rpm;
    Float VVTM_MotorTqReq_Nm;
    UInt8 VVTM_MotorDirReq_enum;
    UInt8 VVTM_MotorModeReq_enum;
    Boolean VVTM_MotDampngEnbl_flg;
    Float VVTM_MotDampngLmt_Nm;
    Float VVTM_WhlDrvMaxTq_Nm;
    Float VVTM_VirtAccPedPstn_pct;
    UInt8 VVTM_VirtAccPedPstnSta_enum;
    Boolean VVTM_ACCOvrd_flg;
    Boolean VVTM_QECACC_flg;
    UInt8 VVTM_MAAActvFb_enum;
    Boolean VVTM_MAAAvail_flg;
    Boolean VVTM_ACCAvail_flg;
    Boolean VVTM_CruzMainSwOn_flg;
    UInt8 VVTM_AutoBrkReq_enum;
    Boolean VVTM_OPDAvail_flg;
    Boolean VVTM_RegenReqBrkLampOn_flg;
    UInt8 VVTM_CruzCtrlStat_enum;
    Float VVTM_CCTgtSpd_kph;
    Float VVTM_MotorActlPwr_kW;
    Boolean VVTM_MotorActlPwrType_flg;
    Float VVTM_RsrvPwr_kW;
    Float VVTM_RsrvRecupPwr_kW;
    UInt8 VVTM_CreepEnFbRsvd_enum;
    UInt8 VVTM_HDCStat_enum;
    Boolean VVTM_EnblEHBBrkRun_flg;
    Float VVTM_MstrCylPresrReq_Bar;
    UInt8 VVTM_ACCStat_enum;
    Boolean VVTM_AccReqStandstill_flg;
} VTM_outputs;

#define _DEFINED_TYPEDEF_FOR_VTM_outputs_

typedef struct
{
    UInt8 VNVM_VehCfgTyreSize_enum;
    UInt8 VNVM_VehCfgCrpCtrl_enum;
    UInt8 VNVM_VehCfgCCS_enum;
    UInt8 VNVM_VehCfgACC_enum;
    UInt8 VNVM_VehCfgHDC_enum;
    UInt8 VNVM_VehCfgTPMSTyp_enum;
} VehCfg_outputs;

#define _DEFINED_TYPEDEF_FOR_VehCfg_outputs_

typedef struct
{
    Boolean NMReq;
    Boolean SleepAllwd;
} WakeUpCtl;

#define _DEFINED_TYPEDEF_FOR_WakeUpCtl_

typedef struct
{
    Boolean DrvWinUpSw;
    Boolean DrvWinDnSw;
    Boolean DrvWinAutoDnSw;
    Boolean PsgWinUpSw;
    Boolean PsgWinDnSw;
    Boolean PsgWinAutoDnSw;
    Boolean DrvPsgWinUpSw;
    Boolean DrvPsgWinDnSw;
    Boolean DrvPsgWinAutoDnSw;
    UInt8 DrvWinSta;
    Boolean J51DrvWinUp;
    Boolean J53DrvWinDn;
    UInt8 PsgWinSta;
    Boolean J55PsgWinUp;
    Boolean J57PsgWinDn;
    Boolean DrvWinUpProt;
    Boolean PsgWinUpProt;
    Boolean DrvWinDnProt;
    Boolean PsgWinDnProt;
    Boolean DrvWinMotorLocked;
    Boolean PsgWinMotorLocked;
} WinCtl;

#define _DEFINED_TYPEDEF_FOR_WinCtl_

typedef struct
{
    Boolean WiperMistSw;
    Boolean WashSw;
    Boolean WiperParkPosSw;
    Boolean WiperOffSw;
    Boolean WiperInrSw;
    Boolean WiperLowSpdSw;
    Boolean WiperHiSpdSw;
    Boolean WiperMistSta;
    Boolean WiperInrSta;
    UInt16 InrTim;
    UInt8 WiprIntlTimeSetFb;
    Boolean InrTimChg;
    Boolean WiperOffSta;
    Boolean WiperMaintSta;
    Boolean WiperHiSpdSta;
    Boolean WiperLowSpdSta;
    Boolean LockedRotorProtSta;
    Boolean WashSta;
    Boolean WashMotorDrv;
    Boolean LowSpdDrv;
    Boolean HiSpdDrv;
    UInt8 WiperSta;
} WiperCtl;

#define _DEFINED_TYPEDEF_FOR_WiperCtl_

typedef UInt8 rt_Array_UInt8_23[23];

#define _DEFINED_TYPEDEF_FOR_rt_Array_UInt8_23_

typedef UInt8 rt_Array_UInt8_16[16];

#define _DEFINED_TYPEDEF_FOR_rt_Array_UInt8_16_

typedef UInt8 rt_Array_UInt8_5[5];

#define _DEFINED_TYPEDEF_FOR_rt_Array_UInt8_5_

typedef struct
{
    UInt8 DynDID_0xF22CAntitheftSta;
    rt_Array_UInt8_10 DynDID_0xF230DoorOpRecord;
    rt_Array_UInt8_10 DynDID_0xF231TrunkOpRecord;
    rt_Array_UInt8_23 DynDID_0xF234ADSampleValue;
    rt_Array_UInt8_10 DynDID_0xF232LocalStartUpFailRecord;
    rt_Array_UInt8_10 DynDID_0xF233RemoteStartUpFailRecord;
    rt_Array_UInt8_5 DynDID_0xF236DigtOutSampleValue;
    UInt8 DynDID_0xF237PwrModeSta;
    rt_Array_UInt8_5 DynDID_0xF235DigtInSampleValue;
    UInt8 DynDID_DoorOpRecord;
    UInt8 DynDID_0xF200ECUPwrMode;
} DynDID;

#define _DEFINED_TYPEDEF_FOR_DynDID_

typedef struct
{
    rt_Array_UInt8_8 AuthResp;
    UInt8 SKSta;
    rt_Array_UInt8_16 SKRead;
} IMMOCtl;

#define _DEFINED_TYPEDEF_FOR_IMMOCtl_

#ifndef close
#define close ((UInt8)0)
#endif /*close*/
#ifndef open
#define open ((UInt8)1)
#endif /*open*/

#ifndef close
#define close ((UInt8)0)
#endif /*close*/
#ifndef open
#define open ((UInt8)1)
#endif /*open*/

#ifndef close
#define close ((UInt8)0)
#endif /*close*/
#ifndef open
#define open ((UInt8)1)
#endif /*open*/

#ifndef close
#define close ((UInt8)0)
#endif /*close*/
#ifndef open
#define open ((UInt8)1)
#endif /*open*/

#ifndef DryRun
#define DryRun ((Boolean)1)
#endif /*DryRun*/
#ifndef Normal
#define Normal ((Boolean)0)
#endif /*Normal*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef DryRun
#define DryRun ((Boolean)1)
#endif /*DryRun*/
#ifndef Normal
#define Normal ((Boolean)0)
#endif /*Normal*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef ShortCircuit
#define ShortCircuit ((UInt8)1)
#endif /*ShortCircuit*/
#ifndef OpenCircuit
#define OpenCircuit ((UInt8)2)
#endif /*OpenCircuit*/
#ifndef Stall
#define Stall ((UInt8)3)
#endif /*Stall*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/

#ifndef ShortCircuit
#define ShortCircuit ((UInt8)1)
#endif /*ShortCircuit*/
#ifndef OpenCircuit
#define OpenCircuit ((UInt8)2)
#endif /*OpenCircuit*/
#ifndef Stall
#define Stall ((UInt8)3)
#endif /*Stall*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/

#ifndef BelowVol
#define BelowVol ((UInt8)2)
#endif /*BelowVol*/
#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef OverVol
#define OverVol ((UInt8)1)
#endif /*OverVol*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/

#ifndef BelowVol
#define BelowVol ((UInt8)2)
#endif /*BelowVol*/
#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef OverVol
#define OverVol ((UInt8)1)
#endif /*OverVol*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef OverTempShutDown
#define OverTempShutDown ((UInt8)2)
#endif /*OverTempShutDown*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/
#ifndef OverTempReduction
#define OverTempReduction ((UInt8)1)
#endif /*OverTempReduction*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef OverTempShutDown
#define OverTempShutDown ((UInt8)2)
#endif /*OverTempShutDown*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/
#ifndef OverTempReduction
#define OverTempReduction ((UInt8)1)
#endif /*OverTempReduction*/

#ifndef Error
#define Error ((Boolean)1)
#endif /*Error*/
#ifndef Normal
#define Normal ((Boolean)0)
#endif /*Normal*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Error
#define Error ((Boolean)1)
#endif /*Error*/
#ifndef Normal
#define Normal ((Boolean)0)
#endif /*Normal*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Reserved
#define Reserved ((UInt8)4)
#endif /*Reserved*/
#ifndef COIL_SHRT
#define COIL_SHRT ((UInt8)1)
#endif /*COIL_SHRT*/
#ifndef COIL_OPN
#define COIL_OPN ((UInt8)2)
#endif /*COIL_OPN*/

#ifndef Reserved
#define Reserved ((UInt8)4)
#endif /*Reserved*/
#ifndef COIL_SHRT
#define COIL_SHRT ((UInt8)1)
#endif /*COIL_SHRT*/
#ifndef COIL_OPN
#define COIL_OPN ((UInt8)2)
#endif /*COIL_OPN*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Fault
#define Fault ((Boolean)1)
#endif /*Fault*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef Initialized
#define Initialized ((UInt8)2)
#endif /*Initialized*/

#ifndef DryRun
#define DryRun ((Boolean)1)
#endif /*DryRun*/
#ifndef Normal
#define Normal ((Boolean)0)
#endif /*Normal*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef DryRun
#define DryRun ((Boolean)1)
#endif /*DryRun*/
#ifndef Normal
#define Normal ((Boolean)0)
#endif /*Normal*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef ShortCircuit
#define ShortCircuit ((UInt8)1)
#endif /*ShortCircuit*/
#ifndef OpenCircuit
#define OpenCircuit ((UInt8)2)
#endif /*OpenCircuit*/
#ifndef Stall
#define Stall ((UInt8)3)
#endif /*Stall*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/

#ifndef ShortCircuit
#define ShortCircuit ((UInt8)1)
#endif /*ShortCircuit*/
#ifndef OpenCircuit
#define OpenCircuit ((UInt8)2)
#endif /*OpenCircuit*/
#ifndef Stall
#define Stall ((UInt8)3)
#endif /*Stall*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/

#ifndef BelowVol
#define BelowVol ((UInt8)2)
#endif /*BelowVol*/
#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef OverVol
#define OverVol ((UInt8)1)
#endif /*OverVol*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/

#ifndef BelowVol
#define BelowVol ((UInt8)2)
#endif /*BelowVol*/
#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef OverVol
#define OverVol ((UInt8)1)
#endif /*OverVol*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef OverTempShutDown
#define OverTempShutDown ((UInt8)2)
#endif /*OverTempShutDown*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/
#ifndef OverTempReduction
#define OverTempReduction ((UInt8)1)
#endif /*OverTempReduction*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef OverTempShutDown
#define OverTempShutDown ((UInt8)2)
#endif /*OverTempShutDown*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/
#ifndef OverTempReduction
#define OverTempReduction ((UInt8)1)
#endif /*OverTempReduction*/

#ifndef Error
#define Error ((Boolean)1)
#endif /*Error*/
#ifndef Normal
#define Normal ((Boolean)0)
#endif /*Normal*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Error
#define Error ((Boolean)1)
#endif /*Error*/
#ifndef Normal
#define Normal ((Boolean)0)
#endif /*Normal*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef False
#define False ((Boolean)0)
#endif /*False*/
#ifndef True
#define True ((Boolean)1)
#endif /*True*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Moving
#define Moving ((Boolean)1)
#endif /*Moving*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Moving
#define Moving ((Boolean)1)
#endif /*Moving*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef Invalid
#define Invalid ((UInt8)0)
#endif /*Invalid*/
#ifndef Level_2
#define Level_2 ((UInt8)2)
#endif /*Level_2*/
#ifndef Level_1
#define Level_1 ((UInt8)1)
#endif /*Level_1*/

#ifndef INIT_IN_PROCESS
#define INIT_IN_PROCESS ((UInt8)1)
#endif /*INIT_IN_PROCESS*/
#ifndef NO_INIT
#define NO_INIT ((UInt8)0)
#endif /*NO_INIT*/
#ifndef Initialized
#define Initialized ((UInt8)2)
#endif /*Initialized*/

#ifndef INIT_IN_PROCESS
#define INIT_IN_PROCESS ((UInt8)1)
#endif /*INIT_IN_PROCESS*/
#ifndef NO_INIT
#define NO_INIT ((UInt8)0)
#endif /*NO_INIT*/
#ifndef Initialized
#define Initialized ((UInt8)2)
#endif /*Initialized*/

#ifndef Reserved
#define Reserved ((UInt8)15)
#endif /*Reserved*/
#ifndef COIL_SHRT
#define COIL_SHRT ((UInt8)1)
#endif /*COIL_SHRT*/
#ifndef COIL_OPN
#define COIL_OPN ((UInt8)2)
#endif /*COIL_OPN*/

#ifndef Reserved
#define Reserved ((UInt8)15)
#endif /*Reserved*/
#ifndef COIL_SHRT
#define COIL_SHRT ((UInt8)1)
#endif /*COIL_SHRT*/
#ifndef COIL_OPN
#define COIL_OPN ((UInt8)2)
#endif /*COIL_OPN*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef ACT_MOVING
#define ACT_MOVING ((Boolean)1)
#endif /*ACT_MOVING*/
#ifndef NO_MOVEMENT
#define NO_MOVEMENT ((Boolean)0)
#endif /*NO_MOVEMENT*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef ACT_MOVING
#define ACT_MOVING ((Boolean)1)
#endif /*ACT_MOVING*/
#ifndef NO_MOVEMENT
#define NO_MOVEMENT ((Boolean)0)
#endif /*NO_MOVEMENT*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef WARNING
#define WARNING ((UInt8)1)
#endif /*WARNING*/
#ifndef OK
#define OK ((UInt8)0)
#endif /*OK*/

#ifndef WARNING
#define WARNING ((UInt8)1)
#endif /*WARNING*/
#ifndef OK
#define OK ((UInt8)0)
#endif /*OK*/

#ifndef False
#define False ((Boolean)0)
#endif /*False*/
#ifndef True
#define True ((Boolean)1)
#endif /*True*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Reserved
#define Reserved ((UInt8)4)
#endif /*Reserved*/
#ifndef COIL_SHRT
#define COIL_SHRT ((UInt8)1)
#endif /*COIL_SHRT*/
#ifndef COIL_OPN
#define COIL_OPN ((UInt8)2)
#endif /*COIL_OPN*/

#ifndef Reserved
#define Reserved ((UInt8)4)
#endif /*Reserved*/
#ifndef COIL_SHRT
#define COIL_SHRT ((UInt8)1)
#endif /*COIL_SHRT*/
#ifndef COIL_OPN
#define COIL_OPN ((UInt8)2)
#endif /*COIL_OPN*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Fault
#define Fault ((Boolean)1)
#endif /*Fault*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Fault
#define Fault ((Boolean)1)
#endif /*Fault*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef Initialized
#define Initialized ((UInt8)2)
#endif /*Initialized*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef Initialized
#define Initialized ((UInt8)2)
#endif /*Initialized*/

#ifndef DryRun
#define DryRun ((Boolean)1)
#endif /*DryRun*/
#ifndef Normal
#define Normal ((Boolean)0)
#endif /*Normal*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef DryRun
#define DryRun ((Boolean)1)
#endif /*DryRun*/
#ifndef Normal
#define Normal ((Boolean)0)
#endif /*Normal*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef ShortCircuit
#define ShortCircuit ((UInt8)1)
#endif /*ShortCircuit*/
#ifndef OpenCircuit
#define OpenCircuit ((UInt8)2)
#endif /*OpenCircuit*/
#ifndef Stall
#define Stall ((UInt8)3)
#endif /*Stall*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/

#ifndef ShortCircuit
#define ShortCircuit ((UInt8)1)
#endif /*ShortCircuit*/
#ifndef OpenCircuit
#define OpenCircuit ((UInt8)2)
#endif /*OpenCircuit*/
#ifndef Stall
#define Stall ((UInt8)3)
#endif /*Stall*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/

#ifndef BelowVol
#define BelowVol ((UInt8)2)
#endif /*BelowVol*/
#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef OverVol
#define OverVol ((UInt8)1)
#endif /*OverVol*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/

#ifndef BelowVol
#define BelowVol ((UInt8)2)
#endif /*BelowVol*/
#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef OverVol
#define OverVol ((UInt8)1)
#endif /*OverVol*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef OverTempShutDown
#define OverTempShutDown ((UInt8)2)
#endif /*OverTempShutDown*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/
#ifndef OverTempReduction
#define OverTempReduction ((UInt8)1)
#endif /*OverTempReduction*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef OverTempShutDown
#define OverTempShutDown ((UInt8)2)
#endif /*OverTempShutDown*/
#ifndef Normal
#define Normal ((UInt8)0)
#endif /*Normal*/
#ifndef OverTempReduction
#define OverTempReduction ((UInt8)1)
#endif /*OverTempReduction*/

#ifndef Error
#define Error ((Boolean)1)
#endif /*Error*/
#ifndef Normal
#define Normal ((Boolean)0)
#endif /*Normal*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef Error
#define Error ((Boolean)1)
#endif /*Error*/
#ifndef Normal
#define Normal ((Boolean)0)
#endif /*Normal*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef NO_RQ
#define NO_RQ ((UInt8)0)
#endif /*NO_RQ*/
#ifndef InitializationReq
#define InitializationReq ((UInt8)1)
#endif /*InitializationReq*/

#ifndef NO_RQ
#define NO_RQ ((UInt8)0)
#endif /*NO_RQ*/
#ifndef InitializationReq
#define InitializationReq ((UInt8)1)
#endif /*InitializationReq*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef reserved
#define reserved ((UInt8)31)
#endif /*reserved*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef Invalid
#define Invalid ((UInt8)0)
#endif /*Invalid*/
#ifndef Level_2
#define Level_2 ((UInt8)2)
#endif /*Level_2*/
#ifndef Level_1
#define Level_1 ((UInt8)1)
#endif /*Level_1*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef Invalid
#define Invalid ((UInt8)0)
#endif /*Invalid*/
#ifndef Level_2
#define Level_2 ((UInt8)2)
#endif /*Level_2*/
#ifndef Level_1
#define Level_1 ((UInt8)1)
#endif /*Level_1*/

#ifndef Reserved
#define Reserved ((UInt8)3)
#endif /*Reserved*/
#ifndef Invalid
#define Invalid ((UInt8)0)
#endif /*Invalid*/
#ifndef Level_2
#define Level_2 ((UInt8)2)
#endif /*Level_2*/
#ifndef Level_1
#define Level_1 ((UInt8)1)
#endif /*Level_1*/

#ifndef NO_RQ
#define NO_RQ ((UInt8)0)
#endif /*NO_RQ*/
#ifndef InitializationReq
#define InitializationReq ((UInt8)1)
#endif /*InitializationReq*/

#ifndef NO_RQ
#define NO_RQ ((UInt8)0)
#endif /*NO_RQ*/
#ifndef InitializationReq
#define InitializationReq ((UInt8)1)
#endif /*InitializationReq*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef FALSE
#define FALSE ((Boolean)0)
#endif /*FALSE*/
#ifndef TRUE
#define TRUE ((Boolean)1)
#endif /*TRUE*/

#ifndef NO_RQ
#define NO_RQ ((UInt8)0)
#endif /*NO_RQ*/
#ifndef InitializationReq
#define InitializationReq ((UInt8)1)
#endif /*InitializationReq*/

#ifndef NO_RQ
#define NO_RQ ((UInt8)0)
#endif /*NO_RQ*/
#ifndef InitializationReq
#define InitializationReq ((UInt8)1)
#endif /*InitializationReq*/

typedef enum
{
    RTE_UNINITED,
    RTE_INITED
} Rte_InitStatusType;

extern Rte_InitStatusType RteInitState;

#endif

