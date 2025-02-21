/*
 * File: monPrmsBcm.c
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1584
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Feb 21 15:51:30 2025
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
MONPRM volatile boolean AlmSysCtl_AlrmWarnTimOut = false;/* '<S430>/AlmSysLogic' */
MONPRM volatile uint8 AlmSysCtl_BodyWarnSts = ((uint8)0U);/* '<S430>/AlmSysLogic' */
MONPRM volatile uint8 BCM_DriverWinSwSig = ((uint8)0U);/* '<S316>/Switch' */
MONPRM volatile uint8 BCM_DrvPassWinSwSig = ((uint8)0U);/* '<S309>/Switch' */
MONPRM volatile uint8 BCM_PassWinSwSig = ((uint8)0U);/* '<S317>/Switch' */
MONPRM volatile uint8 BSW_BrkLampDigSts = ((uint8)0U);/* '<S645>/C Caller' */
MONPRM volatile uint16 BSW_CN744DrvSeatResis = ((uint16)0U);/* '<S1>/C Caller14' */
MONPRM volatile uint8 BSW_CrashPWMSta = ((uint8)0U);/* '<S4>/C Caller15' */
MONPRM volatile uint16 BSW_DrvWinMotorCur = ((uint16)0U);/* '<S1>/C Caller25' */
MONPRM volatile uint8 BSW_EEIlluminatedEntrySys = ((uint8)0U);/* '<S4>/C Caller37' */
MONPRM volatile uint8 BSW_EEKeyEntry = ((uint8)0U);/* '<S4>/C Caller38' */
MONPRM volatile uint8 BSW_FogLampFCfg = ((uint8)0U);/* '<S4>/C Caller3' */
MONPRM volatile uint8 BSW_HMACfg = ((uint8)0U);/* '<S4>/C Caller12' */
MONPRM volatile uint8 BSW_HiBeamDigSts = ((uint8)0U);/* '<S649>/C Caller1' */
MONPRM volatile uint8 BSW_IllmndSts = ((uint8)1U);/* '<S4>/Constant3' */
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
MONPRM volatile uint8 BSW_LowBeamDigSts = ((uint8)0U);/* '<S653>/C Caller' */
MONPRM volatile uint16 BSW_PsgWinMotorCur = ((uint16)0U);/* '<S1>/C Caller29' */
MONPRM volatile uint8 BSW_RKEReq = ((uint8)0U);/* '<S4>/C Caller32' */
MONPRM volatile uint8 BSW_WakeupReas = ((uint8)0U);/* '<S438>/Signal Conversion' */
MONPRM volatile boolean BatSaveCtl_DoorChgSta = false;/* '<S459>/Logical Operator1' */
MONPRM volatile boolean BatSaveCtl_DoorLckPwrOff = false;/* '<S458>/LIB_PosPluse1' */
MONPRM volatile boolean BatSaveCtl_DoorUnlckPwrOn = false;/* '<S459>/Relational Operator1' */
MONPRM volatile boolean BatSaveCtl_J64SavePwr = false;/* '<S457>/Switch1' */
MONPRM volatile boolean BatSaveCtl_PwrModeOff = false;/* '<S458>/LIB_PosPluse' */
MONPRM volatile boolean BatSaveCtl_PwrModeOn = false;/* '<S459>/Relational Operator' */
MONPRM volatile boolean BatSaveCtl_PwrOff = false;/* '<S458>/Logical Operator' */
MONPRM volatile boolean BatSaveCtl_PwrOn = false;/* '<S459>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_AutoLck = false;/* '<S522>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_AutoLckSta = false;/* '<S523>/Switch' */
MONPRM volatile boolean DoorLckCtl_CrshUnlck = false;/* '<S496>/Chart' */
MONPRM volatile boolean DoorLckCtl_DoorAjarFLSw = false;/* '<S471>/LIB_TPD_10ms1' */
MONPRM volatile boolean DoorLckCtl_DoorAjarFRSw = false;/* '<S471>/LIB_TPD_10ms2' */
MONPRM volatile boolean DoorLckCtl_DoorAjarRLSw = false;/* '<S471>/LIB_TPD_10ms6' */
MONPRM volatile boolean DoorLckCtl_DoorAjarRRSw = false;/* '<S471>/LIB_TPD_10ms7' */
MONPRM volatile boolean DoorLckCtl_DoorProtUnlck = false;/* '<S474>/LIB_Tim' */
MONPRM volatile boolean DoorLckCtl_DriverDoorLckSw = false;/* '<S471>/LIB_TPD_10ms' */
MONPRM volatile boolean DoorLckCtl_DrvPESw = false;/* '<S471>/LIB_TPD_10ms3' */
MONPRM volatile boolean DoorLckCtl_DrvSeatSw = false;/* '<S471>/LIB_TPD_10ms11' */
MONPRM volatile uint8 DoorLckCtl_EEIlluminatedEntrySys = ((uint8)0U);/* '<S471>/Switch14' */
MONPRM volatile uint8 DoorLckCtl_EEKeyEntry = ((uint8)0U);/* '<S471>/Switch13' */
MONPRM volatile boolean DoorLckCtl_HULck = false;/* '<S489>/Logical Operator2' */
MONPRM volatile boolean DoorLckCtl_HUUnLck = false;/* '<S497>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_HoodAjarSw = true;/* '<S471>/Constant69' */
MONPRM volatile uint8 DoorLckCtl_IllmndLckSts = ((uint8)0U);/* '<S475>/Multiport Switch' */
MONPRM volatile uint8 DoorLckCtl_IllmndLckStsFb = ((uint8)0U);/* '<S475>/Multiport Switch1' */
MONPRM volatile uint8 DoorLckCtl_IllmndSts = ((uint8)0U);/* '<S471>/Switch15' */
MONPRM volatile uint8 DoorLckCtl_IllmndUnlockSts = ((uint8)0U);/* '<S476>/Multiport Switch' */
MONPRM volatile uint8 DoorLckCtl_IllmndUnlockStsFb = ((uint8)0U);/* '<S476>/Multiport Switch1' */
MONPRM volatile boolean DoorLckCtl_InsLck = false;/* '<S477>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_InsLckSta = ((uint8)0U);/* '<S432>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_InsUnlck = false;/* '<S478>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_J511TrunkUnlck = false;/* '<S469>/Switch1' */
MONPRM volatile boolean DoorLckCtl_J54DoorLck = false;/* '<S468>/Switch1' */
MONPRM volatile boolean DoorLckCtl_J56DoorUnlck = false;/* '<S470>/Switch1' */
MONPRM volatile boolean DoorLckCtl_MechAntiLck = false;/* '<S474>/Logical Operator3' */
MONPRM volatile boolean DoorLckCtl_MechLck = false;/* '<S514>/Logical Operator3' */
MONPRM volatile boolean DoorLckCtl_MechUnlck = false;/* '<S533>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_MotorProt = false;/* '<S479>/Switch' */
MONPRM volatile boolean DoorLckCtl_OsLck = false;/* '<S480>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_OsLckSta = ((uint8)0U);/* '<S432>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_OsUnlck = false;/* '<S481>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_PELck = false;/* '<S515>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_PEUnlck = false;/* '<S534>/Logical Operator1' */
MONPRM volatile uint8 DoorLckCtl_ParkAutoUnlockSetFb = ((uint8)0U);/* '<S483>/Multiport Switch' */
MONPRM volatile boolean DoorLckCtl_ParkUnlck = false;/* '<S498>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_PsgPESw = false;/* '<S471>/LIB_TPD_10ms4' */
MONPRM volatile boolean DoorLckCtl_RKEAntiLck = false;/* '<S474>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_RKELck = false;/* '<S528>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_RKEUnlck = false;/* '<S542>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_RemoteLockFb = ((uint8)0U);/* '<S485>/Chart2' */
MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSet = ((uint8)1U);/* '<S484>/Constant8' */
MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSetFb = ((uint8)0U);/* '<S484>/Constant9' */
MONPRM volatile boolean DoorLckCtl_SpdLck = false;/* '<S495>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TboxAntiLck = false;/* '<S474>/Logical Operator5' */
MONPRM volatile boolean DoorLckCtl_TboxLck = false;/* '<S529>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TboxUnlck = false;/* '<S543>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_ThermRunawayUnlck = false;/* '<S499>/Chart' */
MONPRM volatile boolean DoorLckCtl_TrunkAjarSw = false;/* '<S471>/LIB_TPD_10ms8' */
MONPRM volatile boolean DoorLckCtl_TrunkAutoLck = false;/* '<S531>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_TrunkLckSta = ((uint8)0U);/* '<S432>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_TrunkLckSw = false;/* '<S432>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_TrunkRKEUnlck = false;/* '<S545>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TrunkSw = false;/* '<S471>/LIB_TPD_10ms5' */
MONPRM volatile boolean DoorLckCtl_TrunkTboxUnlck = false;/* '<S547>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TrunkUnlck = false;/* '<S537>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_VehRun = false;/* '<S471>/Logical Operator4' */
MONPRM volatile float32 DoorLckCtl_VehSpd = 0.0F;/* '<S471>/Switch' */
MONPRM volatile boolean DoorLckCtl_VehStop = false;/* '<S471>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_WelcomeLck = false;/* '<S519>/Logical Operator2' */
MONPRM volatile boolean DoorLckCtl_WelcomeUnlck = false;/* '<S538>/Logical Operator1' */
MONPRM volatile uint8 DynDID_0xF200ECUPwrMode = ((uint8)0U);/* '<S433>/Signal Conversion2' */
MONPRM volatile uint8 DynDID_0xF22BFobInformation[16] = { ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U) };     /* '<S433>/Constant27' */

MONPRM volatile uint8 DynDID_0xF22CAntitheftSta = ((uint8)0U);/* '<S433>/Signal Conversion' */
MONPRM volatile uint8 DynDID_0xF230DoorOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S595>/Chart' */

MONPRM volatile uint8 DynDID_0xF231TrunkOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S596>/Chart' */

MONPRM volatile uint8 DynDID_0xF232LocalStartUpFailRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S597>/Chart' */

MONPRM volatile uint8 DynDID_0xF233RemoteStartUpFailRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S598>/Chart' */

MONPRM volatile uint8 DynDID_0xF234ADSampleValue[23] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S599>/Chart' */

MONPRM volatile uint8 DynDID_0xF235DigtInSampleValue[5] = { ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S600>/Chart' */

MONPRM volatile uint8 DynDID_0xF236DigtOutSampleValue[5] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S601>/Chart' */

MONPRM volatile uint8 DynDID_0xF237PwrModeSta = ((uint8)0U);/* '<S433>/Signal Conversion1' */
MONPRM volatile uint8 DynDID_DoorOpRecord = ((uint8)0U);/* '<S595>/Switch' */
MONPRM volatile uint8 EEReadCtl_BJSTimeDay = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_BJSTimeHour = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_BJSTimeMonth = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint16 EEReadCtl_BJSTimeYear = ((uint16)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_BackLadjvalFb = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_BodyWarnSts = ((uint8)1U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_CrashSta = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarFLSw = ((uint8)1U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarFRSw = ((uint8)1U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarRLSw = ((uint8)1U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarRRSw = ((uint8)1U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S289>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_DriverDoorLckSw = ((uint8)1U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DrvSeatSw = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_FlwrMeHomeCtlFb = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_HazardLightSta = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_IllmndLckSts = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_IllmndUnlckSts = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_InrTim = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_LocalStartFailOpRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S289>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_LockHoornOnSts = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_ParkAutoUnlockSetFb = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_RemotePwrLckSta = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_RemoteStartFailRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S289>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_SpdCtlLckSet = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_StartReq = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_SysPwrMode = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_TrunkAjarSw = ((uint8)1U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_TrunkLckSw = ((uint8)1U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_TrunkOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S289>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_TrunkSw = ((uint8)1U);/* '<S289>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_WiprIntlTimeSetFb = ((uint8)0U);/* '<S289>/EEReadCtl' */
MONPRM volatile boolean ESCLCtl_J436Lck = false;/* '<S625>/ESCLLck' */
MONPRM volatile boolean ESCLCtl_J436PwrSup = false;/* '<S630>/Switch' */
MONPRM volatile boolean ESCLCtl_J436Unlck = false;/* '<S625>/ESCLUnlck' */
MONPRM volatile uint8 ESCLCtl_Lck = ((uint8)0U);/* '<S625>/ESCLLck' */
MONPRM volatile uint8 ESCLCtl_UnOrLockCrtl = ((uint8)0U);/* '<S625>/Truth Table' */
MONPRM volatile uint8 ESCLCtl_Unlck = ((uint8)0U);/* '<S625>/ESCLUnlck' */
MONPRM volatile uint8 HornCtl_AlarmSta = ((uint8)0U);/* '<S339>/Alarm' */
MONPRM volatile uint8 HornCtl_AntiLckSta = ((uint8)0U);/* '<S340>/AntiLck' */
MONPRM volatile uint8 HornCtl_ArmedSta = ((uint8)0U);/* '<S341>/Armed' */
MONPRM volatile boolean HornCtl_HornSwCtl = false;/* '<S343>/LIB_TPD_10ms' */
MONPRM volatile boolean HornCtl_J430HornDrv = false;/* '<S345>/Switch1' */
MONPRM volatile uint8 HornCtl_LockHoornOnSt = ((uint8)0U);/* '<S342>/Multiport Switch' */
MONPRM volatile uint8 HornCtl_LockHoornOnStFb = ((uint8)0U);/* '<S342>/Multiport Switch1' */
MONPRM volatile uint8 HornCtl_PartArmedSta = ((uint8)0U);/* '<S346>/PartArmed' */
MONPRM volatile uint8 HornCtl_SeekSta = ((uint8)0U);/* '<S347>/Seek' */
MONPRM volatile uint8 HornCtl_TrunkWarnSta = ((uint8)0U);/* '<S348>/Chart1' */
MONPRM volatile uint8 IMMOCtl_AuthResp[8] = { ((uint8)255U), ((uint8)255U),
  ((uint8)255U), ((uint8)255U), ((uint8)255U), ((uint8)255U), ((uint8)255U),
  ((uint8)255U) };                     /* '<S435>/IMMOCtl' */

MONPRM volatile uint8 IMMOCtl_INVRandom[8] = { ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S435>/Signal Conversion' */

MONPRM volatile uint8 IMMOCtl_SKRead[16] = { ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U) };                  /* '<S435>/IMMOCtl' */

MONPRM volatile uint8 IMMOCtl_SKSta = ((uint8)0U);/* '<S435>/IMMOCtl' */
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
MONPRM volatile boolean LampCtl_AlrmSta = false;/* '<S778>/Chart' */
MONPRM volatile boolean LampCtl_AntiLckSta = false;/* '<S779>/Chart' */
MONPRM volatile boolean LampCtl_ArmedSta = false;/* '<S780>/Chart' */
MONPRM volatile boolean LampCtl_AutoHiBeam = false;/* '<S641>/AutoHiBeamCtl' */
MONPRM volatile boolean LampCtl_AutoLampSta = false;/* '<S688>/Switch' */
MONPRM volatile boolean LampCtl_AutoLampSw = false;/* '<S673>/LIB_TPD_10ms8' */
MONPRM volatile uint8 LampCtl_BackLadjvalFb = ((uint8)0U);/* '<S643>/Multiport Switch' */
MONPRM volatile boolean LampCtl_BrakeLightSta = false;/* '<S662>/Switch1' */
MONPRM volatile boolean LampCtl_BrakeLightSw = false;/* '<S673>/Logical Operator13' */
MONPRM volatile boolean LampCtl_BrkLampShortToBatOrOpen = false;/* '<S645>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_BrkLampShortToGnd = false;/* '<S645>/LIB_TPD_10ms1' */
MONPRM volatile boolean LampCtl_CrashSta = false;/* '<S781>/Chart1' */
MONPRM volatile boolean LampCtl_DayRunLightSta = false;/* '<S656>/Switch1' */
MONPRM volatile boolean LampCtl_DisarmedSta = false;/* '<S782>/Chart' */
MONPRM volatile boolean LampCtl_DomeLampCloseDoor = false;/* '<S702>/Logical Operator6' */
MONPRM volatile boolean LampCtl_DomeLampCtl = false;/* '<S703>/Switch' */
MONPRM volatile boolean LampCtl_DomeLampFLOpen = false;/* '<S705>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampFROpen = false;/* '<S706>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampLockDoor = false;/* '<S718>/Logical Operator' */
MONPRM volatile boolean LampCtl_DomeLampOff = true;/* '<S647>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOffGrad = false;/* '<S647>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOn = false;/* '<S647>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOnGrad = false;/* '<S647>/Truth Table' */
MONPRM volatile uint8 LampCtl_DomeLampPwmDuty = ((uint8)0U);/* '<S657>/Switch1' */
MONPRM volatile boolean LampCtl_DomeLampPwrOff = false;/* '<S711>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampUnlock = false;/* '<S712>/LIB_Tim' */
MONPRM volatile boolean LampCtl_EmerHazardLightSta = false;/* '<S674>/HazardLightLogic' */
MONPRM volatile boolean LampCtl_EmerSta = false;/* '<S783>/Logical Operator' */
MONPRM volatile uint8 LampCtl_FlwrMeHomeCtlFb = ((uint8)0U);/* '<S896>/Multiport Switch1' */
MONPRM volatile boolean LampCtl_FlwrMeHomeSta = false;/* '<S898>/Switch' */
MONPRM volatile uint16 LampCtl_FlwrMeHomeTim = ((uint16)0U);/* '<S896>/Multiport Switch' */
MONPRM volatile boolean LampCtl_FogLampFSta = false;/* '<S667>/Switch1' */
MONPRM volatile boolean LampCtl_FogLampFSw = false;/* '<S673>/LIB_TPD_10ms12' */
MONPRM volatile boolean LampCtl_FogLampRSta = false;/* '<S666>/Switch1' */
MONPRM volatile boolean LampCtl_FogLampRSw = false;/* '<S673>/LIB_TPD_10ms9' */
MONPRM volatile boolean LampCtl_HazardLightSta = false;/* '<S674>/HazardLightLogic' */
MONPRM volatile boolean LampCtl_HazardLightSw = false;/* '<S673>/LIB_TPD_10ms10' */
MONPRM volatile boolean LampCtl_HiBeamShortToBat = false;/* '<S649>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_HiBeamSta = false;/* '<S669>/Switch1' */
MONPRM volatile boolean LampCtl_HiBeamSw = false;/* '<S673>/LIB_TPD_10ms2' */
MONPRM volatile uint8 LampCtl_J408BackLampPWM = ((uint8)0U);/* '<S661>/Switch1' */
MONPRM volatile boolean LampCtl_J420BSDRightCtl = false;/* '<S663>/Switch1' */
MONPRM volatile boolean LampCtl_J422BSDLeftCtl = false;/* '<S664>/Switch1' */
MONPRM volatile boolean LampCtl_J449BoxLamp = false;/* '<S660>/Switch1' */
MONPRM volatile boolean LampCtl_KnobBeamFaultSta = false;/* '<S650>/LIB_TPD_10ms' */
MONPRM volatile boolean LampCtl_LampDelay = false;/* '<S731>/Switch' */
MONPRM volatile uint8 LampCtl_LightIntstSta = ((uint8)0U);/* '<S652>/Chart' */
MONPRM volatile uint16 LampCtl_LightIntstVal = ((uint16)0U);/* '<S673>/Data Type Conversion12' */
MONPRM volatile boolean LampCtl_LowBeamShortToBat = false;/* '<S653>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_LowBeamSta = false;/* '<S665>/Switch1' */
MONPRM volatile boolean LampCtl_LowBeamSw = false;/* '<S673>/LIB_TPD_10ms1' */
MONPRM volatile uint8 LampCtl_PartArmedSta = ((uint8)0U);/* '<S785>/Chart' */
MONPRM volatile boolean LampCtl_PassLightSta = false;/* '<S670>/LIB_Tim' */
MONPRM volatile boolean LampCtl_PassLightSw = false;/* '<S673>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_PosLampSta = false;/* '<S655>/Switch1' */
MONPRM volatile boolean LampCtl_PosLampSw = false;/* '<S673>/LIB_TPD_10ms' */
MONPRM volatile uint16 LampCtl_PrdSucCntL = ((uint16)0U);/* '<S792>/LIB_Pulse' */
MONPRM volatile uint16 LampCtl_PrdSucCntR = ((uint16)0U);/* '<S794>/LIB_Pulse' */
MONPRM volatile uint8 LampCtl_RKEReq = ((uint8)0U);/* '<S673>/Multiport Switch' */
MONPRM volatile boolean LampCtl_ReverseLampSta = false;/* '<S668>/Switch1' */
MONPRM volatile boolean LampCtl_RodBeamFaultSta = false;/* '<S787>/LIB_TPD_10ms' */
MONPRM volatile boolean LampCtl_ThermalrunawaySta = false;/* '<S788>/Chart' */
MONPRM volatile boolean LampCtl_TrunkWarnSta = false;/* '<S789>/Chart' */
MONPRM volatile uint16 LampCtl_TurnIndcrLFlashCnt = ((uint16)0U);/* '<S674>/TurnIndcrArb2' */
MONPRM volatile boolean LampCtl_TurnIndcrLOpen = false;/* '<S791>/Logical Operator' */
MONPRM volatile boolean LampCtl_TurnIndcrLShort = false;/* '<S791>/Logical Operator2' */
MONPRM volatile boolean LampCtl_TurnIndcrLSta = false;/* '<S659>/Switch1' */
MONPRM volatile boolean LampCtl_TurnIndcrLSw = false;/* '<S673>/LIB_TPD_10ms4' */
MONPRM volatile uint16 LampCtl_TurnIndcrLVol = ((uint16)0U);/* '<S864>/C Caller' */
MONPRM volatile boolean LampCtl_TurnIndcrLaneLSw = false;/* '<S673>/LIB_TPD_10ms5' */
MONPRM volatile boolean LampCtl_TurnIndcrLaneRSw = false;/* '<S673>/LIB_TPD_10ms7' */
MONPRM volatile uint8 LampCtl_TurnIndcrMod = ((uint8)0U);/* '<S674>/TurnIndcrLogic' */
MONPRM volatile uint16 LampCtl_TurnIndcrPrd = ((uint16)0U);/* '<S674>/TurnIndcrArb2' */
MONPRM volatile uint16 LampCtl_TurnIndcrRFlashCnt = ((uint16)0U);/* '<S674>/TurnIndcrArb2' */
MONPRM volatile boolean LampCtl_TurnIndcrROpen = false;/* '<S791>/Logical Operator1' */
MONPRM volatile boolean LampCtl_TurnIndcrRShort = false;/* '<S791>/Logical Operator3' */
MONPRM volatile boolean LampCtl_TurnIndcrRSta = false;/* '<S658>/Switch1' */
MONPRM volatile boolean LampCtl_TurnIndcrRSw = false;/* '<S673>/LIB_TPD_10ms6' */
MONPRM volatile uint16 LampCtl_TurnIndcrRVol = ((uint16)0U);/* '<S863>/C Caller' */
MONPRM volatile boolean LampCtl_TurnIndcrRst = false;/* '<S674>/TurnIndcrArb2' */
MONPRM volatile uint16 LampCtl_TurnIndcrWdt = ((uint16)0U);/* '<S674>/TurnIndcrArb2' */
MONPRM volatile uint8 LampCtl_VehModeSta = ((uint8)0U);/* '<S796>/Chart' */
MONPRM volatile uint8 LampCtl_VehSeekSta = ((uint8)0U);/* '<S797>/Chart' */
MONPRM volatile uint8 LampCtl_VehSeekStaFb = ((uint8)0U);/* '<S797>/SeekFb' */
MONPRM volatile boolean LampCtl_WelcomeLampSta = false;/* '<S897>/Switch' */
MONPRM volatile boolean PDUCtl_BrkPwrOn = false;/* '<S917>/Logical Operator1' */
MONPRM volatile boolean PDUCtl_DelayTimPwrOff = false;/* '<S916>/LIB_Tim' */
MONPRM volatile boolean PDUCtl_EmerPwrOff = false;/* '<S916>/Logical Operator13' */
MONPRM volatile boolean PDUCtl_HUPwrOff = false;/* '<S916>/Logical Operator8' */
MONPRM volatile boolean PDUCtl_IG1RelayFault = false;/* '<S918>/LIB_TPD_10ms2' */
MONPRM volatile boolean PDUCtl_IG2RelayFault = false;/* '<S918>/LIB_TPD_10ms1' */
MONPRM volatile boolean PDUCtl_IGRlyIlgCls = false;/* '<S918>/LIB_TPD_10ms3' */
MONPRM volatile uint8 PDUCtl_J421IG1RlyCtl = ((uint8)0U);/* '<S914>/Switch1' */
MONPRM volatile uint8 PDUCtl_J437IG2RlyCtl = ((uint8)0U);/* '<S915>/Switch1' */
MONPRM volatile boolean PDUCtl_KeyChk = false;/* '<S917>/Logical Operator5' */
MONPRM volatile boolean PDUCtl_OTAOverTimPwrOff = false;/* '<S916>/LIB_PosPluse1' */
MONPRM volatile boolean PDUCtl_OTAPwrOff = false;/* '<S916>/Logical Operator20' */
MONPRM volatile boolean PDUCtl_OTAPwrOn = false;/* '<S943>/Logical Operator' */
MONPRM volatile boolean PDUCtl_OpenDoorPwrOn = false;/* '<S917>/Logical Operator' */
MONPRM volatile boolean PDUCtl_OsLckPwrOff = false;/* '<S916>/Logical Operator5' */
MONPRM volatile boolean PDUCtl_PwrOff = false;/* '<S916>/Logical Operator6' */
MONPRM volatile boolean PDUCtl_PwrOn = false;/* '<S917>/Logical Operator11' */
MONPRM volatile boolean PDUCtl_RemotePwrLckFb = false;/* '<S947>/Switch' */
MONPRM volatile uint8 PDUCtl_RemotePwrLckSta = ((uint8)0U);/* '<S917>/RemoteLck' */
MONPRM volatile boolean PDUCtl_RemtOverTimPwrOff = false;/* '<S916>/LIB_Tim1' */
MONPRM volatile boolean PDUCtl_RemtPasvPwrOff = false;/* '<S916>/Logical Operator16' */
MONPRM volatile uint8 PDUCtl_RemtPwrCtlFb = ((uint8)0U);/* '<S437>/RemtPwrCtlFb' */
MONPRM volatile boolean PDUCtl_RemtPwrOff = false;/* '<S916>/Logical Operator12' */
MONPRM volatile boolean PDUCtl_RemtPwrOn = false;/* '<S917>/Logical Operator9' */
MONPRM volatile boolean PDUCtl_StartReq = false;/* '<S965>/Switch' */
MONPRM volatile uint8 PDUCtl_SysPowerSts = ((uint8)0U);/* '<S437>/Chart' */
MONPRM volatile uint8 PDUCtl_SysPwrMode = ((uint8)0U);/* '<S437>/Truth Table' */
MONPRM volatile uint8 PDUCtl_SysPwrModeAct = ((uint8)0U);/* '<S921>/Switch' */
MONPRM volatile boolean PDUCtl_SysPwrModeV = false;/* '<S918>/Switch' */
MONPRM volatile uint8 PEPSCtl_AvaluebleKeyInCar = ((uint8)0U);/* '<S259>/Chart3' */
MONPRM volatile uint8 PEPSCtl_DrvPEAuthentAcsd = ((uint8)0U);/* '<S259>/Chart' */
MONPRM volatile uint8 PEPSCtl_FRPEAuthentAcsd = ((uint8)0U);/* '<S259>/Chart' */
MONPRM volatile uint8 PEPSCtl_FrbdnKeyNr = ((uint8)0U);/* '<S257>/Chart' */
MONPRM volatile uint8 PEPSCtl_IMMOKey = ((uint8)0U);/* '<S260>/Chart5' */
MONPRM volatile uint8 PEPSCtl_IndicationKeyCloser = ((uint8)0U);/* '<S260>/Chart2' */
MONPRM volatile uint8 PEPSCtl_KeyInCarSta = ((uint8)0U);/* '<S259>/Chart' */
MONPRM volatile uint8 PEPSCtl_KeyLoBattLvlWarn = ((uint8)0U);/* '<S258>/Chart3' */
MONPRM volatile uint8 PEPSCtl_KeySta = ((uint8)0U);/* '<S260>/Chart1' */
MONPRM volatile uint8 PEPSCtl_LckWlcmReq = ((uint8)0U);/* '<S261>/Chart' */
MONPRM volatile uint8 PEPSCtl_PSAuthentRes = ((uint8)0U);/* '<S260>/Chart' */
MONPRM volatile uint8 PEPSCtl_PSReq = ((uint8)0U);/* '<S260>/Chart' */
MONPRM volatile uint8 PEPSCtl_UnlckWlcmReq = ((uint8)0U);/* '<S261>/Chart' */
MONPRM volatile uint8 PEPSCtl_WarnKeyOutReminder = ((uint8)0U);/* '<S258>/Chart' */
MONPRM volatile uint8 PEPSCtl_WarnNoKeyFound = ((uint8)0U);/* '<S260>/Chart2' */
MONPRM volatile boolean RVMCtl_J42Heat = false;/* '<S140>/Switch' */
MONPRM volatile uint8 SCS_FrntWiprSwtSt = ((uint8)0U);/* '<S291>/Signal Conversion' */
MONPRM volatile boolean SCS_FrntWshrSwtSt = false;/* '<S291>/Signal Conversion1' */
MONPRM volatile boolean SCS_FrntWshrSwtStVD = false;/* '<S291>/Signal Conversion2' */
MONPRM volatile boolean SCS_WiprSwtStVD = false;/* '<S291>/Signal Conversion3' */
MONPRM volatile uint8 SeatCtl_CN167DrvSeatHtPWM = ((uint8)0U);/* '<S150>/Switch' */
MONPRM volatile boolean SeatCtl_DrvNTCOpen = false;/* '<S145>/LIB_TPD_Ts1' */
MONPRM volatile boolean SeatCtl_DrvNTCShort = false;/* '<S145>/LIB_TPD_Ts' */
MONPRM volatile sint8 SeatCtl_DrvSeatTemp = 0;/* '<S145>/Data Type Conversion' */
MONPRM volatile uint8 SeatCtl_MaiDrvSeatStFb = ((uint8)0U);/* '<S145>/Multiport Switch' */
MONPRM volatile uint8 SeatCtl_RemtHeatFb = ((uint8)0U);/* '<S145>/HeatFb' */
MONPRM volatile boolean SteerWhlCtl_J447SteerWhlHt = false;/* '<S157>/Switch' */
MONPRM volatile uint8 SteerWhlCtl_RemtHeatFb = ((uint8)0U);/* '<S153>/HeatFb' */
MONPRM volatile uint8 SteerWhlCtl_SteerWhlHeatSts = ((uint8)0U);/* '<S153>/HeatSet' */
MONPRM volatile sint8 SteerWhlCtl_SteerWhlTemp = 0;/* '<S153>/Data Type Conversion' */
MONPRM volatile uint8 TboxTim_BJSTimeDay = ((uint8)0U);/* '<S11>/TboxTim' */
MONPRM volatile uint8 TboxTim_BJSTimeHour = ((uint8)0U);/* '<S11>/TboxTim' */
MONPRM volatile uint8 TboxTim_BJSTimeMonth = ((uint8)0U);/* '<S11>/TboxTim' */
MONPRM volatile uint16 TboxTim_BJSTimeYear = ((uint16)0U);/* '<S11>/TboxTim' */
MONPRM volatile uint8 TboxTim_HourDiff = ((uint8)0U);/* '<S11>/TboxTim' */
MONPRM volatile boolean WakeUpCtl_NMReq = false;/* '<S980>/Switch' */
MONPRM volatile boolean WakeUpCtl_SleepAllwd = false;/* '<S968>/Logical Operator5' */
MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnReq = false;/* '<S171>/Chart13' */
MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnSw = false;/* '<S169>/LIB_TPD_10ms9' */
MONPRM volatile boolean WinCtl_DrvPsgWinDnReq = false;/* '<S171>/Chart11' */
MONPRM volatile boolean WinCtl_DrvPsgWinDnSw = false;/* '<S169>/LIB_TPD_10ms8' */
MONPRM volatile boolean WinCtl_DrvPsgWinOvTimProt = false;/* '<S171>/LIB_PosPluse2' */
MONPRM volatile boolean WinCtl_DrvPsgWinUpReq = false;/* '<S171>/Chart12' */
MONPRM volatile boolean WinCtl_DrvPsgWinUpSw = false;/* '<S169>/LIB_TPD_10ms7' */
MONPRM volatile boolean WinCtl_DrvWinAutoDnReq = false;/* '<S171>/Chart10' */
MONPRM volatile boolean WinCtl_DrvWinAutoDnSw = false;/* '<S169>/LIB_TPD_10ms2' */
MONPRM volatile boolean WinCtl_DrvWinDnProt = false;/* '<S170>/LIB_CntLimit1' */
MONPRM volatile boolean WinCtl_DrvWinDnReq = false;/* '<S171>/Chart2' */
MONPRM volatile boolean WinCtl_DrvWinDnSw = false;/* '<S169>/LIB_TPD_10ms1' */
MONPRM volatile boolean WinCtl_DrvWinMotorLocked = false;/* '<S171>/LIB_TPD_10ms3' */
MONPRM volatile uint8 WinCtl_DrvWinReq = ((uint8)0U);/* '<S171>/Switch11' */
MONPRM volatile uint8 WinCtl_DrvWinSta = ((uint8)0U);/* '<S12>/DrvWinCtl' */
MONPRM volatile boolean WinCtl_DrvWinUpProt = false;/* '<S170>/LIB_CntLimit' */
MONPRM volatile boolean WinCtl_DrvWinUpReq = false;/* '<S171>/Chart3' */
MONPRM volatile boolean WinCtl_DrvWinUpSw = false;/* '<S169>/LIB_TPD_10ms3' */
MONPRM volatile boolean WinCtl_J51DrvWinUp = false;/* '<S164>/Switch1' */
MONPRM volatile boolean WinCtl_J53DrvWinDn = false;/* '<S166>/Switch1' */
MONPRM volatile boolean WinCtl_J55PsgWinUp = false;/* '<S167>/Switch1' */
MONPRM volatile boolean WinCtl_J57PsgWinDn = false;/* '<S165>/Switch1' */
MONPRM volatile boolean WinCtl_PsgWinAutoDnReq = false;/* '<S171>/Chart1' */
MONPRM volatile boolean WinCtl_PsgWinAutoDnSw = false;/* '<S169>/LIB_TPD_10ms6' */
MONPRM volatile boolean WinCtl_PsgWinDnProt = false;/* '<S170>/LIB_CntLimit3' */
MONPRM volatile boolean WinCtl_PsgWinDnReq = false;/* '<S171>/Chart4' */
MONPRM volatile boolean WinCtl_PsgWinDnSw = false;/* '<S169>/LIB_TPD_10ms5' */
MONPRM volatile boolean WinCtl_PsgWinMotorLocked = false;/* '<S171>/LIB_TPD_10ms1' */
MONPRM volatile boolean WinCtl_PsgWinOvTimProt = false;/* '<S171>/LIB_PosPluse1' */
MONPRM volatile uint8 WinCtl_PsgWinReq = ((uint8)0U);/* '<S171>/Switch10' */
MONPRM volatile uint8 WinCtl_PsgWinSta = ((uint8)0U);/* '<S12>/PsgWinCtl' */
MONPRM volatile boolean WinCtl_PsgWinUpProt = false;/* '<S170>/LIB_CntLimit2' */
MONPRM volatile boolean WinCtl_PsgWinUpReq = false;/* '<S171>/Chart5' */
MONPRM volatile boolean WinCtl_PsgWinUpSw = false;/* '<S169>/LIB_TPD_10ms4' */
MONPRM volatile boolean WiperCtl_HiSpdDrv = false;/* '<S377>/Switch1' */
MONPRM volatile uint16 WiperCtl_InrTim = ((uint16)0U);/* '<S383>/Multiport Switch' */
MONPRM volatile boolean WiperCtl_InrTimChg = false;/* '<S383>/Relational Operator1' */
MONPRM volatile boolean WiperCtl_LockedRotorProtSta = false;/* '<S375>/Logical Operator2' */
MONPRM volatile boolean WiperCtl_LowSpdDrv = false;/* '<S376>/Switch1' */
MONPRM volatile boolean WiperCtl_WashMotorDrv = false;/* '<S378>/Switch1' */
MONPRM volatile boolean WiperCtl_WashSw = false;/* '<S379>/LIB_TPD_10ms5' */
MONPRM volatile boolean WiperCtl_WashWiperSta = false;/* '<S380>/LIB_TPD_10ms6' */
MONPRM volatile boolean WiperCtl_WiperHiSpdSta = false;/* '<S382>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperHiSpdSw = false;/* '<S379>/LIB_TPD_10ms4' */
MONPRM volatile boolean WiperCtl_WiperInrSta = false;/* '<S383>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperInrSw = false;/* '<S379>/LIB_TPD_10ms2' */
MONPRM volatile boolean WiperCtl_WiperLowSpdSta = false;/* '<S384>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperLowSpdSw = false;/* '<S379>/LIB_TPD_10ms3' */
MONPRM volatile boolean WiperCtl_WiperMaintSta = false;/* '<S424>/Switch' */
MONPRM volatile boolean WiperCtl_WiperMistSta = false;/* '<S386>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperMistSw = false;/* '<S379>/LIB_TPD_10ms' */
MONPRM volatile boolean WiperCtl_WiperOffSta = false;/* '<S387>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperOffSw = false;/* '<S379>/LIB_TPD_10ms1' */
MONPRM volatile boolean WiperCtl_WiperParkPosSw = false;/* '<S379>/LIB_TPD_10ms6' */
MONPRM volatile uint8 WiperCtl_WiperSta = ((uint8)0U);/* '<S381>/Chart' */
MONPRM volatile uint8 WiperCtl_WiprIntlTimeSetFb = ((uint8)0U);/* '<S383>/Multiport Switch1' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
