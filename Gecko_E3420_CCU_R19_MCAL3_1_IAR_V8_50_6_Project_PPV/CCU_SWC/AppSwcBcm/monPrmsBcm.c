/*
 * File: monPrmsBcm.c
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1537
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Dec 30 17:33:19 2024
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: NXP->Cortex-M4
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "monPrmsBcm.h"
#include "AppSwcBcm.h"

/* Exported data definition */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Definition for custom storage class: Volatile */
MONPRM volatile boolean AlmSysCtl_AlrmWarnTimOut = false;/* '<S405>/AlmSysLogic' */
MONPRM volatile uint8 AlmSysCtl_BodyWarnSts = ((uint8)0U);/* '<S405>/AlmSysLogic' */
MONPRM volatile uint16 BSW_CN744DrvSeatResis = ((uint16)0U);/* '<S1>/C Caller14' */
MONPRM volatile uint8 BSW_CrashPWMSta = ((uint8)0U);/* '<S4>/C Caller15' */
MONPRM volatile uint16 BSW_DrvWinMotorCur = ((uint16)0U);/* '<S1>/C Caller25' */
MONPRM volatile uint8 BSW_EEIlluminatedEntrySys = ((uint8)0U);/* '<S4>/C Caller37' */
MONPRM volatile uint8 BSW_EEKeyEntry = ((uint8)0U);/* '<S4>/C Caller38' */
MONPRM volatile uint8 BSW_FogLampFCfg = ((uint8)0U);/* '<S4>/C Caller3' */
MONPRM volatile uint8 BSW_HiBeamDigSts = ((uint8)0U);/* '<S629>/C Caller1' */
MONPRM volatile uint8 BSW_IllmndSts = ((uint8)0U);/* '<S4>/Constant3' */
MONPRM volatile uint16 BSW_J112DrvSeatResis = ((uint16)0U);/* '<S4>/C Caller16' */
MONPRM volatile uint16 BSW_J113DrvWinSwResis = ((uint16)0U);/* '<S1>/C Caller26' */
MONPRM volatile uint16 BSW_J125LightIntst = ((uint16)0U);/* '<S4>/C Caller30' */
MONPRM volatile uint16 BSW_J126DrvPsgWinSwResis = ((uint16)0U);/* '<S1>/C Caller27' */
MONPRM volatile uint16 BSW_J134SteerWhlResis = ((uint16)0U);/* '<S1>/C Caller34' */
MONPRM volatile uint16 BSW_J26PsgWinSwResis = ((uint16)0U);/* '<S1>/C Caller28' */
MONPRM volatile uint8 BSW_J310DoorAjarFR = ((uint8)0U);/* '<S4>/C Caller2' */
MONPRM volatile uint8 BSW_J313BrakeLoSw = ((uint8)0U);/* '<S4>/C Caller7' */
MONPRM volatile uint8 BSW_J319HornSw = ((uint8)0U);/* '<S3>/C Caller31' */
MONPRM volatile uint8 BSW_J320DoorAjarRL = ((uint8)0U);/* '<S4>/C Caller17' */
MONPRM volatile uint8 BSW_J321DoorAjarFL = ((uint8)0U);/* '<S4>/C Caller1' */
MONPRM volatile uint8 BSW_J322FogLampF = ((uint8)0U);/* '<S4>/C Caller4' */
MONPRM volatile uint8 BSW_J334WiperParkPos = ((uint8)0U);/* '<S3>/C Caller8' */
MONPRM volatile uint8 BSW_J335DriverDoorLck = ((uint8)0U);/* '<S4>/C Caller' */
MONPRM volatile uint8 BSW_J336Trunk = ((uint8)0U);/* '<S4>/C Caller18' */
MONPRM volatile uint8 BSW_J337PsgPE = ((uint8)0U);/* '<S4>/C Caller6' */
MONPRM volatile uint8 BSW_J338DrvPE = ((uint8)0U);/* '<S4>/C Caller5' */
MONPRM volatile uint8 BSW_J339BrakeHiSw = ((uint8)0U);/* '<S4>/C Caller33' */
MONPRM volatile uint8 BSW_J346FogLampR = ((uint8)0U);/* '<S4>/C Caller13' */
MONPRM volatile uint8 BSW_J349TrunkLck = ((uint8)0U);/* '<S4>/C Caller19' */
MONPRM volatile uint8 BSW_J36DoorAjarRR = ((uint8)0U);/* '<S4>/C Caller20' */
MONPRM volatile uint8 BSW_J37TrunkAjar = ((uint8)0U);/* '<S4>/C Caller21' */
MONPRM volatile uint8 BSW_J38HoodAjar = ((uint8)0U);/* '<S4>/C Caller22' */
MONPRM volatile uint8 BSW_LowBeamDigSts = ((uint8)0U);/* '<S633>/C Caller' */
MONPRM volatile uint16 BSW_PsgWinMotorCur = ((uint16)0U);/* '<S1>/C Caller29' */
MONPRM volatile uint8 BSW_RKEReq = ((uint8)0U);/* '<S4>/C Caller32' */
MONPRM volatile uint8 BSW_WakeupReas = ((uint8)0U);/* '<S413>/Signal Conversion' */
MONPRM volatile boolean BatSaveCtl_DoorChgSta = false;/* '<S434>/Logical Operator1' */
MONPRM volatile boolean BatSaveCtl_DoorLckPwrOff = false;/* '<S433>/LIB_PosPluse1' */
MONPRM volatile boolean BatSaveCtl_DoorUnlckPwrOn = false;/* '<S434>/Relational Operator1' */
MONPRM volatile boolean BatSaveCtl_J64SavePwr = false;/* '<S432>/Switch1' */
MONPRM volatile boolean BatSaveCtl_PwrModeOff = false;/* '<S433>/LIB_PosPluse' */
MONPRM volatile boolean BatSaveCtl_PwrModeOn = false;/* '<S434>/Relational Operator' */
MONPRM volatile boolean BatSaveCtl_PwrOff = false;/* '<S433>/Logical Operator' */
MONPRM volatile boolean BatSaveCtl_PwrOn = false;/* '<S434>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_AutoLck = false;/* '<S498>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_AutoLckSta = false;/* '<S499>/Switch' */
MONPRM volatile boolean DoorLckCtl_CrshUnlck = false;/* '<S472>/Chart' */
MONPRM volatile boolean DoorLckCtl_DoorAjarFLSw = false;/* '<S446>/LIB_TPD_10ms1' */
MONPRM volatile boolean DoorLckCtl_DoorAjarFRSw = false;/* '<S446>/LIB_TPD_10ms2' */
MONPRM volatile boolean DoorLckCtl_DoorAjarRLSw = false;/* '<S446>/LIB_TPD_10ms6' */
MONPRM volatile boolean DoorLckCtl_DoorAjarRRSw = false;/* '<S446>/LIB_TPD_10ms7' */
MONPRM volatile boolean DoorLckCtl_DoorProtUnlck = false;/* '<S449>/LIB_Tim' */
MONPRM volatile boolean DoorLckCtl_DriverDoorLckSw = false;/* '<S446>/LIB_TPD_10ms' */
MONPRM volatile boolean DoorLckCtl_DrvPESw = false;/* '<S446>/LIB_TPD_10ms3' */
MONPRM volatile boolean DoorLckCtl_DrvSeatSw = false;/* '<S446>/LIB_TPD_10ms11' */
MONPRM volatile uint8 DoorLckCtl_EEIlluminatedEntrySys = ((uint8)0U);/* '<S446>/Switch14' */
MONPRM volatile uint8 DoorLckCtl_EEKeyEntry = ((uint8)0U);/* '<S446>/Switch13' */
MONPRM volatile boolean DoorLckCtl_HULck = false;/* '<S465>/Logical Operator2' */
MONPRM volatile boolean DoorLckCtl_HUUnLck = false;/* '<S473>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_HoodAjarSw = true;/* '<S446>/Constant69' */
MONPRM volatile uint8 DoorLckCtl_IllmndLckSts = ((uint8)0U);/* '<S451>/Multiport Switch' */
MONPRM volatile uint8 DoorLckCtl_IllmndLckStsFb = ((uint8)0U);/* '<S451>/Multiport Switch1' */
MONPRM volatile uint8 DoorLckCtl_IllmndSts = ((uint8)0U);/* '<S446>/Switch15' */
MONPRM volatile uint8 DoorLckCtl_IllmndUnlockSts = ((uint8)0U);/* '<S452>/Multiport Switch' */
MONPRM volatile uint8 DoorLckCtl_IllmndUnlockStsFb = ((uint8)0U);/* '<S452>/Multiport Switch1' */
MONPRM volatile boolean DoorLckCtl_InsLck = false;/* '<S453>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_InsLckSta = ((uint8)0U);/* '<S407>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_InsUnlck = false;/* '<S454>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_J511TrunkUnlck = false;/* '<S444>/Switch1' */
MONPRM volatile boolean DoorLckCtl_J54DoorLck = false;/* '<S443>/Switch1' */
MONPRM volatile boolean DoorLckCtl_J56DoorUnlck = false;/* '<S445>/Switch1' */
MONPRM volatile boolean DoorLckCtl_MechAntiLck = false;/* '<S449>/Logical Operator3' */
MONPRM volatile boolean DoorLckCtl_MechLck = false;/* '<S490>/Logical Operator3' */
MONPRM volatile boolean DoorLckCtl_MechUnlck = false;/* '<S512>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_MotorProt = false;/* '<S455>/Switch' */
MONPRM volatile boolean DoorLckCtl_OsLck = false;/* '<S456>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_OsLckSta = ((uint8)0U);/* '<S407>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_OsUnlck = false;/* '<S457>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_PELck = false;/* '<S491>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_PEUnlck = false;/* '<S513>/Logical Operator1' */
MONPRM volatile uint8 DoorLckCtl_ParkAutoUnlockSetFb = ((uint8)0U);/* '<S459>/Multiport Switch' */
MONPRM volatile boolean DoorLckCtl_ParkUnlck = false;/* '<S474>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_PsgPESw = false;/* '<S446>/LIB_TPD_10ms4' */
MONPRM volatile boolean DoorLckCtl_RKEAntiLck = false;/* '<S449>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_RKELck = false;/* '<S505>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_RKEUnlck = false;/* '<S522>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_RemoteLockFb = ((uint8)0U);/* '<S461>/Chart' */
MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSet = ((uint8)1U);/* '<S460>/Constant8' */
MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSetFb = ((uint8)0U);/* '<S460>/Constant9' */
MONPRM volatile boolean DoorLckCtl_SpdLck = false;/* '<S471>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TboxLck = false;/* '<S508>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TboxUnlck = false;/* '<S525>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_ThermRunawayUnlck = false;/* '<S475>/Chart' */
MONPRM volatile boolean DoorLckCtl_TrunkAjarSw = false;/* '<S446>/LIB_TPD_10ms8' */
MONPRM volatile boolean DoorLckCtl_TrunkAutoLck = false;/* '<S510>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_TrunkLckSta = ((uint8)0U);/* '<S407>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_TrunkLckSw = true;/* '<S407>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_TrunkRKEUnlck = false;/* '<S527>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TrunkSw = false;/* '<S446>/LIB_TPD_10ms5' */
MONPRM volatile boolean DoorLckCtl_TrunkTboxUnlck = false;/* '<S529>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TrunkUnlck = false;/* '<S516>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_VehRun = false;/* '<S446>/Logical Operator4' */
MONPRM volatile float32 DoorLckCtl_VehSpd = 0.0F;/* '<S446>/Switch' */
MONPRM volatile boolean DoorLckCtl_VehStop = false;/* '<S446>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_WelcomeLck = false;/* '<S495>/Logical Operator2' */
MONPRM volatile boolean DoorLckCtl_WelcomeUnlck = false;/* '<S517>/Logical Operator1' */
MONPRM volatile uint8 DynDID_0xF22BFobInformation[16] = { ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U) };     /* '<S408>/Constant27' */

MONPRM volatile uint8 DynDID_0xF22CAntitheftSta = ((uint8)0U);/* '<S408>/Signal Conversion' */
MONPRM volatile uint8 DynDID_0xF230DoorOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S576>/Chart' */

MONPRM volatile uint8 DynDID_0xF231TrunkOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S577>/Chart' */

MONPRM volatile uint8 DynDID_0xF232LocalStartUpFailRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S578>/Chart' */

MONPRM volatile uint8 DynDID_0xF233RemoteStartUpFailRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S579>/Chart' */

MONPRM volatile uint8 DynDID_0xF234ADSampleValue[23] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S580>/Chart' */

MONPRM volatile uint8 DynDID_0xF235DigtInSampleValue[5] = { ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S581>/Chart' */

MONPRM volatile uint8 DynDID_0xF236DigtOutSampleValue[5] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S582>/Chart' */

MONPRM volatile uint8 DynDID_0xF237PwrModeSta = ((uint8)0U);/* '<S408>/Signal Conversion1' */
MONPRM volatile uint8 EEReadCtl_BackLadjvalFb = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_BodyWarnSts = ((uint8)1U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_CrashSta = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarFLSw = ((uint8)1U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarFRSw = ((uint8)1U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarRLSw = ((uint8)1U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarRRSw = ((uint8)1U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S268>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_DriverDoorLckSw = ((uint8)1U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DrvSeatSw = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_FlwrMeHomeCtlFb = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_HazardLightSta = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_IllmndLckSts = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_IllmndUnlckSts = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_InrTim = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_LocalStartFailOpRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S268>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_LockHoornOnSts = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_ParkAutoUnlockSetFb = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_RemotePwrLckSta = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_RemoteStartFailRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S268>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_SpdCtlLckSet = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_StartReq = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_SysPwrMode = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_TrunkAjarSw = ((uint8)1U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_TrunkLckSw = ((uint8)1U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_TrunkOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S268>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_TrunkSw = ((uint8)1U);/* '<S268>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_WiprIntlTimeSetFb = ((uint8)0U);/* '<S268>/EEReadCtl' */
MONPRM volatile boolean ESCLCtl_J436Lck = false;/* '<S606>/ESCLLck' */
MONPRM volatile boolean ESCLCtl_J436PwrSup = false;/* '<S611>/Switch' */
MONPRM volatile boolean ESCLCtl_J436Unlck = false;/* '<S606>/ESCLUnlck' */
MONPRM volatile uint8 ESCLCtl_Lck = ((uint8)0U);/* '<S606>/ESCLLck' */
MONPRM volatile uint8 ESCLCtl_UnOrLockCrtl = ((uint8)0U);/* '<S606>/Truth Table' */
MONPRM volatile uint8 ESCLCtl_Unlck = ((uint8)0U);/* '<S606>/ESCLUnlck' */
MONPRM volatile uint8 HornCtl_AlarmSta = ((uint8)0U);/* '<S314>/Alarm' */
MONPRM volatile uint8 HornCtl_AntiLckSta = ((uint8)0U);/* '<S315>/AntiLck' */
MONPRM volatile uint8 HornCtl_ArmedSta = ((uint8)0U);/* '<S316>/Armed' */
MONPRM volatile boolean HornCtl_HornSwCtl = false;/* '<S318>/LIB_TPD_10ms' */
MONPRM volatile boolean HornCtl_J430HornDrv = false;/* '<S320>/Switch1' */
MONPRM volatile uint8 HornCtl_LockHoornOnSt = ((uint8)0U);/* '<S317>/Multiport Switch' */
MONPRM volatile uint8 HornCtl_LockHoornOnStFb = ((uint8)0U);/* '<S317>/Multiport Switch1' */
MONPRM volatile uint8 HornCtl_PartArmedSta = ((uint8)0U);/* '<S321>/PartArmed' */
MONPRM volatile uint8 HornCtl_SeekSta = ((uint8)0U);/* '<S322>/Seek' */
MONPRM volatile uint8 HornCtl_TrunkWarnSta = ((uint8)0U);/* '<S323>/Chart1' */
MONPRM volatile uint8 IMMOCtl_AuthResp[8] = { ((uint8)255U), ((uint8)255U),
  ((uint8)255U), ((uint8)255U), ((uint8)255U), ((uint8)255U), ((uint8)255U),
  ((uint8)255U) };                     /* '<S410>/IMMOCtl' */

MONPRM volatile uint8 IMMOCtl_INVRandom[8] = { ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S410>/Signal Conversion' */

MONPRM volatile uint8 IMMOCtl_SKRead[16] = { ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U) };                  /* '<S410>/IMMOCtl' */

MONPRM volatile uint8 IMMOCtl_SKSta = ((uint8)0U);/* '<S410>/IMMOCtl' */
MONPRM volatile uint8 IODID_BSDLeftCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND44' */
MONPRM volatile uint8 IODID_BSDRightCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND43' */
MONPRM volatile uint8 IODID_BackLampCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND2' */
MONPRM volatile uint8 IODID_BatSaveCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND42' */
MONPRM volatile uint8 IODID_BrakeLightCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND3' */
MONPRM volatile uint8 IODID_DayRunLightCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND6' */
MONPRM volatile uint8 IODID_DomeLampCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND9' */
MONPRM volatile uint8 IODID_DoorLckCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND17' */
MONPRM volatile uint8 IODID_DoorUnlckCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND16' */
MONPRM volatile uint8 IODID_FogLampFCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND14' */
MONPRM volatile uint8 IODID_FogLampRCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND15' */
MONPRM volatile uint8 IODID_HiBeamCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND13' */
MONPRM volatile uint8 IODID_HornCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND40' */
MONPRM volatile uint8 IODID_IG1RlyCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND46' */
MONPRM volatile uint8 IODID_IG2RlyCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND47' */
MONPRM volatile uint8 IODID_LowBeamCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND12' */
MONPRM volatile uint8 IODID_PosLampCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND7' */
MONPRM volatile uint8 IODID_ReverseLampCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND5' */
MONPRM volatile uint8 IODID_TrunkUnlckCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND22' */
MONPRM volatile uint8 IODID_TurnIndcrLCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND' */
MONPRM volatile uint8 IODID_TurnIndcrRCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND1' */
MONPRM volatile uint8 IODID_WinFLCloseFlg = ((uint8)0U);/* '<S7>/Bitwise AND38' */
MONPRM volatile uint8 IODID_WinFLOpenFlg = ((uint8)0U);/* '<S7>/Bitwise AND39' */
MONPRM volatile uint8 IODID_WinFRCloseFlg = ((uint8)0U);/* '<S7>/Bitwise AND32' */
MONPRM volatile uint8 IODID_WinFROpenFlg = ((uint8)0U);/* '<S7>/Bitwise AND33' */
MONPRM volatile uint8 IODID_WiperHiSpdCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND30' */
MONPRM volatile uint8 IODID_WiperLowSpdCtlFlg = ((uint8)0U);/* '<S7>/Bitwise AND31' */
MONPRM volatile boolean LampCtl_AlrmSta = false;/* '<S752>/Chart' */
MONPRM volatile boolean LampCtl_AntiLckSta = false;/* '<S753>/Chart' */
MONPRM volatile boolean LampCtl_ArmedSta = false;/* '<S754>/Chart' */
MONPRM volatile boolean LampCtl_AutoLampSta = false;/* '<S667>/Switch' */
MONPRM volatile boolean LampCtl_AutoLampSw = false;/* '<S653>/LIB_TPD_10ms8' */
MONPRM volatile uint8 LampCtl_BackLadjvalFb = ((uint8)0U);/* '<S623>/Multiport Switch' */
MONPRM volatile boolean LampCtl_BrakeLightSta = false;/* '<S642>/Switch1' */
MONPRM volatile boolean LampCtl_BrakeLightSw = false;/* '<S653>/Logical Operator13' */
MONPRM volatile boolean LampCtl_CrashSta = false;/* '<S755>/Chart1' */
MONPRM volatile boolean LampCtl_DayRunLightSta = false;/* '<S636>/Switch1' */
MONPRM volatile boolean LampCtl_DisarmedSta = false;/* '<S756>/Chart' */
MONPRM volatile boolean LampCtl_DomeLampCloseDoor = false;/* '<S679>/Logical Operator6' */
MONPRM volatile boolean LampCtl_DomeLampCtl = false;/* '<S680>/Switch' */
MONPRM volatile boolean LampCtl_DomeLampFLOpen = false;/* '<S682>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampFROpen = false;/* '<S683>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampLockDoor = false;/* '<S695>/Logical Operator' */
MONPRM volatile boolean LampCtl_DomeLampOff = true;/* '<S627>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOffGrad = false;/* '<S627>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOn = false;/* '<S627>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOnGrad = false;/* '<S627>/Truth Table' */
MONPRM volatile uint8 LampCtl_DomeLampPwmDuty = ((uint8)0U);/* '<S637>/Switch1' */
MONPRM volatile boolean LampCtl_DomeLampPwrOff = false;/* '<S688>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampUnlock = false;/* '<S689>/LIB_Tim' */
MONPRM volatile boolean LampCtl_EmerHazardLightSta = false;/* '<S654>/HazardLightLogic' */
MONPRM volatile boolean LampCtl_EmerSta = false;/* '<S757>/Logical Operator' */
MONPRM volatile uint8 LampCtl_FlwrMeHomeCtlFb = ((uint8)0U);/* '<S870>/Multiport Switch1' */
MONPRM volatile boolean LampCtl_FlwrMeHomeSta = false;/* '<S872>/Switch' */
MONPRM volatile uint16 LampCtl_FlwrMeHomeTim = ((uint16)0U);/* '<S870>/Multiport Switch' */
MONPRM volatile boolean LampCtl_FogLampFSta = false;/* '<S647>/Switch1' */
MONPRM volatile boolean LampCtl_FogLampFSw = false;/* '<S653>/LIB_TPD_10ms12' */
MONPRM volatile boolean LampCtl_FogLampRSta = false;/* '<S646>/Switch1' */
MONPRM volatile boolean LampCtl_FogLampRSw = false;/* '<S653>/LIB_TPD_10ms9' */
MONPRM volatile boolean LampCtl_HazardLightSta = false;/* '<S654>/HazardLightLogic' */
MONPRM volatile boolean LampCtl_HazardLightSw = false;/* '<S653>/LIB_TPD_10ms10' */
MONPRM volatile boolean LampCtl_HiBeamShortToBat = false;/* '<S629>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_HiBeamSta = false;/* '<S649>/Switch1' */
MONPRM volatile boolean LampCtl_HiBeamSw = false;/* '<S653>/LIB_TPD_10ms2' */
MONPRM volatile uint8 LampCtl_J408BackLampPWM = ((uint8)0U);/* '<S641>/Switch1' */
MONPRM volatile boolean LampCtl_J420BSDRightCtl = false;/* '<S643>/Switch1' */
MONPRM volatile boolean LampCtl_J422BSDLeftCtl = false;/* '<S644>/Switch1' */
MONPRM volatile boolean LampCtl_J449BoxLamp = false;/* '<S640>/Switch1' */
MONPRM volatile boolean LampCtl_KnobBeamFaultSta = false;/* '<S630>/LIB_TPD_10ms' */
MONPRM volatile boolean LampCtl_LampDelay = false;/* '<S708>/Switch' */
MONPRM volatile uint8 LampCtl_LightIntstSta = ((uint8)0U);/* '<S632>/Chart' */
MONPRM volatile uint16 LampCtl_LightIntstVal = ((uint16)0U);/* '<S653>/Data Type Conversion12' */
MONPRM volatile boolean LampCtl_LowBeamShortToBat = false;/* '<S633>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_LowBeamSta = false;/* '<S645>/Switch1' */
MONPRM volatile boolean LampCtl_LowBeamSw = false;/* '<S653>/LIB_TPD_10ms1' */
MONPRM volatile uint8 LampCtl_PartArmedSta = ((uint8)0U);/* '<S759>/Chart' */
MONPRM volatile boolean LampCtl_PassLightSta = false;/* '<S650>/LIB_Tim' */
MONPRM volatile boolean LampCtl_PassLightSw = false;/* '<S653>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_PosLampSta = false;/* '<S635>/Switch1' */
MONPRM volatile boolean LampCtl_PosLampSw = false;/* '<S653>/LIB_TPD_10ms' */
MONPRM volatile uint16 LampCtl_PrdSucCntL = ((uint16)0U);/* '<S766>/LIB_Pulse' */
MONPRM volatile uint16 LampCtl_PrdSucCntR = ((uint16)0U);/* '<S768>/LIB_Pulse' */
MONPRM volatile uint8 LampCtl_RKEReq = ((uint8)0U);/* '<S653>/Multiport Switch' */
MONPRM volatile boolean LampCtl_ReverseLampSta = false;/* '<S648>/Switch1' */
MONPRM volatile boolean LampCtl_RodBeamFaultSta = false;/* '<S761>/LIB_TPD_10ms' */
MONPRM volatile boolean LampCtl_ThermalrunawaySta = false;/* '<S762>/Chart' */
MONPRM volatile boolean LampCtl_TrunkWarnSta = false;/* '<S763>/Chart' */
MONPRM volatile uint16 LampCtl_TurnIndcrLFlashCnt = ((uint16)0U);/* '<S654>/TurnIndcrArb2' */
MONPRM volatile boolean LampCtl_TurnIndcrLOpen = false;/* '<S765>/Logical Operator' */
MONPRM volatile boolean LampCtl_TurnIndcrLShort = false;/* '<S765>/Logical Operator2' */
MONPRM volatile boolean LampCtl_TurnIndcrLSta = false;/* '<S639>/Switch1' */
MONPRM volatile boolean LampCtl_TurnIndcrLSw = false;/* '<S653>/LIB_TPD_10ms4' */
MONPRM volatile uint16 LampCtl_TurnIndcrLVol = ((uint16)0U);/* '<S838>/C Caller' */
MONPRM volatile boolean LampCtl_TurnIndcrLaneLSw = false;/* '<S653>/LIB_TPD_10ms5' */
MONPRM volatile boolean LampCtl_TurnIndcrLaneRSw = false;/* '<S653>/LIB_TPD_10ms7' */
MONPRM volatile uint8 LampCtl_TurnIndcrMod = ((uint8)0U);/* '<S654>/TurnIndcrLogic' */
MONPRM volatile uint16 LampCtl_TurnIndcrPrd = ((uint16)0U);/* '<S654>/TurnIndcrArb2' */
MONPRM volatile uint16 LampCtl_TurnIndcrRFlashCnt = ((uint16)0U);/* '<S654>/TurnIndcrArb2' */
MONPRM volatile boolean LampCtl_TurnIndcrROpen = false;/* '<S765>/Logical Operator1' */
MONPRM volatile boolean LampCtl_TurnIndcrRShort = false;/* '<S765>/Logical Operator3' */
MONPRM volatile boolean LampCtl_TurnIndcrRSta = false;/* '<S638>/Switch1' */
MONPRM volatile boolean LampCtl_TurnIndcrRSw = false;/* '<S653>/LIB_TPD_10ms6' */
MONPRM volatile uint16 LampCtl_TurnIndcrRVol = ((uint16)0U);/* '<S837>/C Caller' */
MONPRM volatile boolean LampCtl_TurnIndcrRst = false;/* '<S654>/TurnIndcrArb2' */
MONPRM volatile uint16 LampCtl_TurnIndcrWdt = ((uint16)0U);/* '<S654>/TurnIndcrArb2' */
MONPRM volatile uint8 LampCtl_VehModeSta = ((uint8)0U);/* '<S770>/Chart' */
MONPRM volatile uint8 LampCtl_VehSeekSta = ((uint8)0U);/* '<S771>/Chart' */
MONPRM volatile uint8 LampCtl_VehSeekStaFb = ((uint8)0U);/* '<S771>/SeekFb' */
MONPRM volatile boolean LampCtl_WelcomeLampSta = false;/* '<S871>/Switch' */
MONPRM volatile boolean PDUCtl_BrkPwrOn = false;/* '<S891>/Logical Operator1' */
MONPRM volatile boolean PDUCtl_DelayTimPwrOff = false;/* '<S890>/LIB_Tim' */
MONPRM volatile boolean PDUCtl_EmerPwrOff = false;/* '<S890>/Logical Operator13' */
MONPRM volatile boolean PDUCtl_HUPwrOff = false;/* '<S890>/Logical Operator8' */
MONPRM volatile boolean PDUCtl_IG1RelayFault = false;/* '<S892>/LIB_TPD_10ms2' */
MONPRM volatile boolean PDUCtl_IG2RelayFault = false;/* '<S892>/LIB_TPD_10ms1' */
MONPRM volatile boolean PDUCtl_IGRlyIlgCls = false;/* '<S892>/LIB_TPD_10ms3' */
MONPRM volatile uint8 PDUCtl_J421IG1RlyCtl = ((uint8)0U);/* '<S888>/Switch1' */
MONPRM volatile uint8 PDUCtl_J437IG2RlyCtl = ((uint8)0U);/* '<S889>/Switch1' */
MONPRM volatile boolean PDUCtl_KeyChk = false;/* '<S891>/Logical Operator5' */
MONPRM volatile boolean PDUCtl_OTAOverTimPwrOff = false;/* '<S890>/LIB_PosPluse1' */
MONPRM volatile boolean PDUCtl_OTAPwrOff = false;/* '<S890>/Logical Operator20' */
MONPRM volatile boolean PDUCtl_OTAPwrOn = false;/* '<S917>/Logical Operator' */
MONPRM volatile boolean PDUCtl_OpenDoorPwrOn = false;/* '<S891>/Logical Operator' */
MONPRM volatile boolean PDUCtl_OsLckPwrOff = false;/* '<S890>/Logical Operator5' */
MONPRM volatile boolean PDUCtl_PwrOff = false;/* '<S890>/Logical Operator6' */
MONPRM volatile boolean PDUCtl_PwrOn = false;/* '<S891>/Logical Operator11' */
MONPRM volatile boolean PDUCtl_RemotePwrLckFb = false;/* '<S921>/Switch' */
MONPRM volatile uint8 PDUCtl_RemotePwrLckSta = ((uint8)0U);/* '<S891>/RemoteLck' */
MONPRM volatile boolean PDUCtl_RemtOverTimPwrOff = false;/* '<S890>/LIB_Tim1' */
MONPRM volatile boolean PDUCtl_RemtPasvPwrOff = false;/* '<S890>/Logical Operator16' */
MONPRM volatile uint8 PDUCtl_RemtPwrCtlFb = ((uint8)0U);/* '<S412>/RemtPwrCtlFb' */
MONPRM volatile boolean PDUCtl_RemtPwrOff = false;/* '<S890>/Logical Operator12' */
MONPRM volatile boolean PDUCtl_RemtPwrOn = false;/* '<S891>/Logical Operator9' */
MONPRM volatile boolean PDUCtl_StartReq = false;/* '<S939>/Switch' */
MONPRM volatile uint8 PDUCtl_SysPowerSts = ((uint8)0U);/* '<S412>/Chart' */
MONPRM volatile uint8 PDUCtl_SysPwrMode = ((uint8)0U);/* '<S412>/Truth Table' */
MONPRM volatile uint8 PDUCtl_SysPwrModeAct = ((uint8)0U);/* '<S895>/Switch' */
MONPRM volatile boolean PDUCtl_SysPwrModeV = false;/* '<S892>/Switch' */
MONPRM volatile uint8 PEPSCtl_AvaluebleKeyInCar = ((uint8)0U);/* '<S247>/Chart3' */
MONPRM volatile uint8 PEPSCtl_DrvPEAuthentAcsd = ((uint8)0U);/* '<S247>/Chart' */
MONPRM volatile uint8 PEPSCtl_FRPEAuthentAcsd = ((uint8)0U);/* '<S247>/Chart' */
MONPRM volatile uint8 PEPSCtl_FrbdnKeyNr = ((uint8)0U);/* '<S245>/Chart' */
MONPRM volatile uint8 PEPSCtl_IMMOKey = ((uint8)0U);/* '<S248>/Chart5' */
MONPRM volatile uint8 PEPSCtl_IndicationKeyCloser = ((uint8)0U);/* '<S248>/Chart2' */
MONPRM volatile uint8 PEPSCtl_KeyInCarSta = ((uint8)0U);/* '<S247>/Chart' */
MONPRM volatile uint8 PEPSCtl_KeyLoBattLvlWarn = ((uint8)0U);/* '<S246>/Chart3' */
MONPRM volatile uint8 PEPSCtl_KeySta = ((uint8)0U);/* '<S248>/Chart1' */
MONPRM volatile uint8 PEPSCtl_LckWlcmReq = ((uint8)0U);/* '<S249>/Chart' */
MONPRM volatile uint8 PEPSCtl_PSAuthentRes = ((uint8)0U);/* '<S248>/Chart' */
MONPRM volatile uint8 PEPSCtl_PSReq = ((uint8)0U);/* '<S248>/Chart' */
MONPRM volatile uint8 PEPSCtl_UnlckWlcmReq = ((uint8)0U);/* '<S249>/Chart' */
MONPRM volatile uint8 PEPSCtl_WarnKeyOutReminder = ((uint8)0U);/* '<S246>/Chart' */
MONPRM volatile uint8 PEPSCtl_WarnNoKeyFound = ((uint8)0U);/* '<S248>/Chart2' */
MONPRM volatile boolean RVMCtl_J42Heat = false;/* '<S131>/Switch' */
MONPRM volatile uint8 SCS_FrntWiprSwtSt = ((uint8)0U);/* '<S270>/Signal Conversion' */
MONPRM volatile boolean SCS_FrntWshrSwtSt = false;/* '<S270>/Signal Conversion1' */
MONPRM volatile boolean SCS_FrntWshrSwtStVD = false;/* '<S270>/Signal Conversion2' */
MONPRM volatile boolean SCS_WiprSwtStVD = false;/* '<S270>/Signal Conversion3' */
MONPRM volatile uint8 SeatCtl_CN167DrvSeatHtPWM = ((uint8)0U);/* '<S141>/Switch' */
MONPRM volatile boolean SeatCtl_DrvNTCOpen = false;/* '<S136>/LIB_TPD_Ts1' */
MONPRM volatile boolean SeatCtl_DrvNTCShort = false;/* '<S136>/LIB_TPD_Ts' */
MONPRM volatile sint8 SeatCtl_DrvSeatTemp = 0;/* '<S136>/Data Type Conversion' */
MONPRM volatile uint8 SeatCtl_MaiDrvSeatStFb = ((uint8)0U);/* '<S136>/Multiport Switch' */
MONPRM volatile uint8 SeatCtl_RemtHeatFb = ((uint8)0U);/* '<S136>/HeatFb' */
MONPRM volatile boolean SteerWhlCtl_J447SteerWhlHt = false;/* '<S148>/Switch' */
MONPRM volatile uint8 SteerWhlCtl_RemtHeatFb = ((uint8)0U);/* '<S144>/HeatFb' */
MONPRM volatile uint8 SteerWhlCtl_SteerWhlHeatSts = ((uint8)0U);/* '<S144>/HeatSet' */
MONPRM volatile sint8 SteerWhlCtl_SteerWhlTemp = 0;/* '<S144>/Data Type Conversion' */
MONPRM volatile boolean WakeUpCtl_NMReq = false;/* '<S954>/Switch' */
MONPRM volatile boolean WakeUpCtl_SleepAllwd = false;/* '<S942>/Logical Operator5' */
MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnReq = false;/* '<S159>/Chart13' */
MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnSw = false;/* '<S157>/LIB_TPD_10ms9' */
MONPRM volatile boolean WinCtl_DrvPsgWinDnReq = false;/* '<S159>/Chart11' */
MONPRM volatile boolean WinCtl_DrvPsgWinDnSw = false;/* '<S157>/LIB_TPD_10ms8' */
MONPRM volatile boolean WinCtl_DrvPsgWinOvTimProt = false;/* '<S159>/LIB_PosPluse2' */
MONPRM volatile boolean WinCtl_DrvPsgWinUpReq = false;/* '<S159>/Chart12' */
MONPRM volatile boolean WinCtl_DrvPsgWinUpSw = false;/* '<S157>/LIB_TPD_10ms7' */
MONPRM volatile boolean WinCtl_DrvWinAutoDnReq = false;/* '<S159>/Chart10' */
MONPRM volatile boolean WinCtl_DrvWinAutoDnSw = false;/* '<S157>/LIB_TPD_10ms2' */
MONPRM volatile boolean WinCtl_DrvWinDnProt = false;/* '<S158>/LIB_CntLimit1' */
MONPRM volatile boolean WinCtl_DrvWinDnReq = false;/* '<S159>/Chart2' */
MONPRM volatile boolean WinCtl_DrvWinDnSw = false;/* '<S157>/LIB_TPD_10ms1' */
MONPRM volatile boolean WinCtl_DrvWinMotorLocked = false;/* '<S159>/LIB_TPD_10ms3' */
MONPRM volatile uint8 WinCtl_DrvWinReq = ((uint8)0U);/* '<S159>/Switch11' */
MONPRM volatile uint8 WinCtl_DrvWinSta = ((uint8)0U);/* '<S11>/DrvWinCtl' */
MONPRM volatile boolean WinCtl_DrvWinUpProt = false;/* '<S158>/LIB_CntLimit' */
MONPRM volatile boolean WinCtl_DrvWinUpReq = false;/* '<S159>/Chart3' */
MONPRM volatile boolean WinCtl_DrvWinUpSw = false;/* '<S157>/LIB_TPD_10ms3' */
MONPRM volatile boolean WinCtl_J51DrvWinUp = false;/* '<S152>/Switch1' */
MONPRM volatile boolean WinCtl_J53DrvWinDn = false;/* '<S154>/Switch1' */
MONPRM volatile boolean WinCtl_J55PsgWinUp = false;/* '<S155>/Switch1' */
MONPRM volatile boolean WinCtl_J57PsgWinDn = false;/* '<S153>/Switch1' */
MONPRM volatile boolean WinCtl_PsgWinAutoDnReq = false;/* '<S159>/Chart1' */
MONPRM volatile boolean WinCtl_PsgWinAutoDnSw = false;/* '<S157>/LIB_TPD_10ms6' */
MONPRM volatile boolean WinCtl_PsgWinDnProt = false;/* '<S158>/LIB_CntLimit3' */
MONPRM volatile boolean WinCtl_PsgWinDnReq = false;/* '<S159>/Chart4' */
MONPRM volatile boolean WinCtl_PsgWinDnSw = false;/* '<S157>/LIB_TPD_10ms5' */
MONPRM volatile boolean WinCtl_PsgWinMotorLocked = false;/* '<S159>/LIB_TPD_10ms1' */
MONPRM volatile boolean WinCtl_PsgWinOvTimProt = false;/* '<S159>/LIB_PosPluse1' */
MONPRM volatile uint8 WinCtl_PsgWinReq = ((uint8)0U);/* '<S159>/Switch10' */
MONPRM volatile uint8 WinCtl_PsgWinSta = ((uint8)0U);/* '<S11>/PsgWinCtl' */
MONPRM volatile boolean WinCtl_PsgWinUpProt = false;/* '<S158>/LIB_CntLimit2' */
MONPRM volatile boolean WinCtl_PsgWinUpReq = false;/* '<S159>/Chart5' */
MONPRM volatile boolean WinCtl_PsgWinUpSw = false;/* '<S157>/LIB_TPD_10ms4' */
MONPRM volatile boolean WiperCtl_HiSpdDrv = false;/* '<S352>/Switch1' */
MONPRM volatile uint16 WiperCtl_InrTim = ((uint16)0U);/* '<S358>/Multiport Switch' */
MONPRM volatile boolean WiperCtl_InrTimChg = false;/* '<S358>/Relational Operator1' */
MONPRM volatile boolean WiperCtl_LockedRotorProtSta = false;/* '<S350>/Logical Operator2' */
MONPRM volatile boolean WiperCtl_LowSpdDrv = false;/* '<S351>/Switch1' */
MONPRM volatile boolean WiperCtl_WashMotorDrv = false;/* '<S353>/Switch1' */
MONPRM volatile boolean WiperCtl_WashSw = false;/* '<S354>/LIB_TPD_10ms5' */
MONPRM volatile boolean WiperCtl_WashWiperSta = false;/* '<S355>/LIB_TPD_10ms6' */
MONPRM volatile boolean WiperCtl_WiperHiSpdSta = false;/* '<S357>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperHiSpdSw = false;/* '<S354>/LIB_TPD_10ms4' */
MONPRM volatile boolean WiperCtl_WiperInrSta = false;/* '<S358>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperInrSw = false;/* '<S354>/LIB_TPD_10ms2' */
MONPRM volatile boolean WiperCtl_WiperLowSpdSta = false;/* '<S359>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperLowSpdSw = false;/* '<S354>/LIB_TPD_10ms3' */
MONPRM volatile boolean WiperCtl_WiperMaintSta = false;/* '<S399>/Switch' */
MONPRM volatile boolean WiperCtl_WiperMistSta = false;/* '<S361>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperMistSw = false;/* '<S354>/LIB_TPD_10ms' */
MONPRM volatile boolean WiperCtl_WiperOffSta = false;/* '<S362>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperOffSw = false;/* '<S354>/LIB_TPD_10ms1' */
MONPRM volatile boolean WiperCtl_WiperParkPosSw = false;/* '<S354>/LIB_TPD_10ms6' */
MONPRM volatile uint8 WiperCtl_WiperSta = ((uint8)0U);/* '<S356>/Chart' */
MONPRM volatile uint8 WiperCtl_WiprIntlTimeSetFb = ((uint8)0U);/* '<S358>/Multiport Switch1' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
