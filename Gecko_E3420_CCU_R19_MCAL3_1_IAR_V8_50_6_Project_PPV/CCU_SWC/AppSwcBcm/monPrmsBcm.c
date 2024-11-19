/*
 * File: monPrmsBcm.c
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1501
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Tue Nov 19 10:56:39 2024
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
MONPRM volatile boolean AlmSysCtl_AlrmWarnTimOut = false;/* '<S637>/AlmSysLogic' */
MONPRM volatile uint8 AlmSysCtl_BodyWarnSts = ((uint8)0U);/* '<S637>/AlmSysLogic' */
MONPRM volatile uint16 BSW_CN744DrvSeatResis = ((uint16)0U);/* '<S1>/C Caller14' */
MONPRM volatile uint8 BSW_CrashPWMSta = ((uint8)0U);/* '<S3>/C Caller15' */
MONPRM volatile uint16 BSW_DrvWinMotorCur = ((uint16)0U);/* '<S1>/C Caller25' */
MONPRM volatile uint8 BSW_EEIlluminatedEntrySys = ((uint8)0U);/* '<S4>/C Caller37' */
MONPRM volatile uint8 BSW_EEKeyEntry = ((uint8)0U);/* '<S4>/C Caller38' */
MONPRM volatile uint8 BSW_FogLampFCfg = ((uint8)0U);/* '<S3>/C Caller1' */
MONPRM volatile uint8 BSW_HiBeamDigSts = ((uint8)0U);/* '<S327>/C Caller1' */
MONPRM volatile uint8 BSW_IllmndSts = ((uint8)0U);/* '<S4>/Constant3' */
MONPRM volatile uint16 BSW_J112DrvSeatResis = ((uint16)0U);/* '<S4>/C Caller16' */
MONPRM volatile uint16 BSW_J113DrvWinSwResis = ((uint16)0U);/* '<S1>/C Caller26' */
MONPRM volatile uint16 BSW_J125LightIntst = ((uint16)0U);/* '<S3>/C Caller30' */
MONPRM volatile uint16 BSW_J126DrvPsgWinSwResis = ((uint16)0U);/* '<S1>/C Caller27' */
MONPRM volatile uint16 BSW_J134SteerWhlResis = ((uint16)0U);/* '<S1>/C Caller34' */
MONPRM volatile uint16 BSW_J26PsgWinSwResis = ((uint16)0U);/* '<S1>/C Caller28' */
MONPRM volatile uint8 BSW_J310DoorAjarFR = ((uint8)0U);/* '<S4>/C Caller2' */
MONPRM volatile uint8 BSW_J313BrakeLoSw = ((uint8)0U);/* '<S3>/C Caller4' */
MONPRM volatile uint8 BSW_J319HornSw = ((uint8)0U);/* '<S3>/C Caller31' */
MONPRM volatile uint8 BSW_J320DoorAjarRL = ((uint8)0U);/* '<S4>/C Caller17' */
MONPRM volatile uint8 BSW_J321DoorAjarFL = ((uint8)0U);/* '<S4>/C Caller1' */
MONPRM volatile uint8 BSW_J322FogLampF = ((uint8)0U);/* '<S3>/C Caller3' */
MONPRM volatile uint8 BSW_J334WiperParkPos = ((uint8)0U);/* '<S3>/C Caller8' */
MONPRM volatile uint8 BSW_J335DriverDoorLck = ((uint8)0U);/* '<S4>/C Caller' */
MONPRM volatile uint8 BSW_J336Trunk = ((uint8)0U);/* '<S4>/C Caller18' */
MONPRM volatile uint8 BSW_J337PsgPE = ((uint8)0U);/* '<S4>/C Caller6' */
MONPRM volatile uint8 BSW_J338DrvPE = ((uint8)0U);/* '<S4>/C Caller5' */
MONPRM volatile uint8 BSW_J339BrakeHiSw = ((uint8)0U);/* '<S3>/C Caller33' */
MONPRM volatile uint8 BSW_J346FogLampR = ((uint8)0U);/* '<S3>/C Caller13' */
MONPRM volatile uint8 BSW_J349TrunkLck = ((uint8)0U);/* '<S4>/C Caller19' */
MONPRM volatile uint8 BSW_J36DoorAjarRR = ((uint8)0U);/* '<S4>/C Caller20' */
MONPRM volatile uint8 BSW_J37TrunkAjar = ((uint8)0U);/* '<S4>/C Caller21' */
MONPRM volatile uint8 BSW_J38HoodAjar = ((uint8)0U);/* '<S4>/C Caller22' */
MONPRM volatile uint8 BSW_LowBeamDigSts = ((uint8)0U);/* '<S331>/C Caller' */
MONPRM volatile uint16 BSW_PsgWinMotorCur = ((uint16)0U);/* '<S1>/C Caller29' */
MONPRM volatile uint8 BSW_RKEReq = ((uint8)0U);/* '<S3>/C Caller32' */
MONPRM volatile uint8 BSW_WakeupReas = ((uint8)0U);/* '<S645>/Signal Conversion' */
MONPRM volatile boolean BatSaveCtl_DoorChgSta = false;/* '<S666>/Logical Operator1' */
MONPRM volatile boolean BatSaveCtl_DoorLckPwrOff = false;/* '<S665>/LIB_PosPluse1' */
MONPRM volatile boolean BatSaveCtl_DoorUnlckPwrOn = false;/* '<S666>/Relational Operator1' */
MONPRM volatile boolean BatSaveCtl_J64SavePwr = false;/* '<S664>/Switch1' */
MONPRM volatile boolean BatSaveCtl_PwrModeOff = false;/* '<S665>/LIB_PosPluse' */
MONPRM volatile boolean BatSaveCtl_PwrModeOn = false;/* '<S666>/Relational Operator' */
MONPRM volatile boolean BatSaveCtl_PwrOff = false;/* '<S665>/Logical Operator' */
MONPRM volatile boolean BatSaveCtl_PwrOn = false;/* '<S666>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_AutoLck = false;/* '<S737>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_AutoLckSta = false;/* '<S738>/Switch' */
MONPRM volatile boolean DoorLckCtl_CrshUnlck = false;/* '<S710>/Chart' */
MONPRM volatile boolean DoorLckCtl_DoorAjarFLSw = false;/* '<S678>/LIB_TPD_10ms1' */
MONPRM volatile boolean DoorLckCtl_DoorAjarFRSw = false;/* '<S678>/LIB_TPD_10ms2' */
MONPRM volatile boolean DoorLckCtl_DoorAjarRLSw = false;/* '<S678>/LIB_TPD_10ms6' */
MONPRM volatile boolean DoorLckCtl_DoorAjarRRSw = false;/* '<S678>/LIB_TPD_10ms7' */
MONPRM volatile boolean DoorLckCtl_DoorProtUnlck = false;/* '<S681>/LIB_Tim' */
MONPRM volatile boolean DoorLckCtl_DriverDoorLckSw = false;/* '<S678>/LIB_TPD_10ms' */
MONPRM volatile boolean DoorLckCtl_DrvPESw = false;/* '<S678>/LIB_TPD_10ms3' */
MONPRM volatile boolean DoorLckCtl_DrvSeatSw = false;/* '<S678>/LIB_TPD_10ms11' */
MONPRM volatile uint8 DoorLckCtl_EEIlluminatedEntrySys = ((uint8)0U);/* '<S678>/Switch14' */
MONPRM volatile uint8 DoorLckCtl_EEKeyEntry = ((uint8)0U);/* '<S678>/Switch13' */
MONPRM volatile boolean DoorLckCtl_HULck = false;/* '<S697>/Logical Operator2' */
MONPRM volatile boolean DoorLckCtl_HUUnLck = false;/* '<S711>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_HoodAjarSw = true;/* '<S678>/Constant69' */
MONPRM volatile uint8 DoorLckCtl_IllmndLckSts = ((uint8)0U);/* '<S683>/Multiport Switch' */
MONPRM volatile uint8 DoorLckCtl_IllmndLckStsFb = ((uint8)0U);/* '<S683>/Multiport Switch1' */
MONPRM volatile uint8 DoorLckCtl_IllmndSts = ((uint8)0U);/* '<S678>/Switch15' */
MONPRM volatile uint8 DoorLckCtl_IllmndUnlockSts = ((uint8)0U);/* '<S684>/Multiport Switch' */
MONPRM volatile uint8 DoorLckCtl_IllmndUnlockStsFb = ((uint8)0U);/* '<S684>/Multiport Switch1' */
MONPRM volatile boolean DoorLckCtl_InsLck = false;/* '<S685>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_InsLckSta = ((uint8)0U);/* '<S640>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_InsUnlck = false;/* '<S686>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_J511TrunkUnlck = false;/* '<S676>/Switch1' */
MONPRM volatile boolean DoorLckCtl_J54DoorLck = false;/* '<S675>/Switch1' */
MONPRM volatile boolean DoorLckCtl_J56DoorUnlck = false;/* '<S677>/Switch1' */
MONPRM volatile boolean DoorLckCtl_MechAntiLck = false;/* '<S681>/Logical Operator3' */
MONPRM volatile boolean DoorLckCtl_MechLck = false;/* '<S729>/Logical Operator3' */
MONPRM volatile boolean DoorLckCtl_MechUnlck = false;/* '<S755>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_MotorProt = false;/* '<S687>/Switch' */
MONPRM volatile boolean DoorLckCtl_OsLck = false;/* '<S688>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_OsLckSta = ((uint8)0U);/* '<S640>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_OsUnlck = false;/* '<S689>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_PELck = false;/* '<S730>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_PEUnlck = false;/* '<S756>/Logical Operator1' */
MONPRM volatile uint8 DoorLckCtl_ParkAutoUnlockSetFb = ((uint8)0U);/* '<S691>/Multiport Switch' */
MONPRM volatile boolean DoorLckCtl_ParkUnlck = false;/* '<S712>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_PsgPESw = false;/* '<S678>/LIB_TPD_10ms4' */
MONPRM volatile boolean DoorLckCtl_RKEAntiLck = false;/* '<S681>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_RKELck = false;/* '<S744>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_RKEUnlck = false;/* '<S764>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_RemoteLockFb = ((uint8)0U);/* '<S693>/Chart' */
MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSet = ((uint8)1U);/* '<S692>/Constant8' */
MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSetFb = ((uint8)0U);/* '<S692>/Constant9' */
MONPRM volatile boolean DoorLckCtl_SpdLck = false;/* '<S703>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TboxLck = false;/* '<S747>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TboxUnlck = false;/* '<S767>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_ThermRunawayUnlck = false;/* '<S713>/Chart' */
MONPRM volatile boolean DoorLckCtl_TrunkAjarSw = false;/* '<S678>/LIB_TPD_10ms8' */
MONPRM volatile boolean DoorLckCtl_TrunkAutoLck = false;/* '<S750>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_TrunkLckSta = ((uint8)0U);/* '<S640>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_TrunkLckSw = true;/* '<S640>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_TrunkRKEUnlck = false;/* '<S769>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TrunkSw = false;/* '<S678>/LIB_TPD_10ms5' */
MONPRM volatile boolean DoorLckCtl_TrunkTboxUnlck = false;/* '<S771>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TrunkUnlck = false;/* '<S759>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_VehRun = false;/* '<S678>/Logical Operator4' */
MONPRM volatile float32 DoorLckCtl_VehSpd = 0.0F;/* '<S678>/Switch' */
MONPRM volatile boolean DoorLckCtl_VehStop = false;/* '<S678>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_WelcomeLck = false;/* '<S734>/Logical Operator2' */
MONPRM volatile boolean DoorLckCtl_WelcomeUnlck = false;/* '<S760>/Logical Operator1' */
MONPRM volatile uint8 DynDID_0xF22CAntitheftSta = ((uint8)0U);/* '<S641>/Signal Conversion' */
MONPRM volatile uint8 DynDID_0xF230DoorOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S818>/Chart' */

MONPRM volatile uint8 DynDID_0xF231TrunkOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S819>/Chart' */

MONPRM volatile uint8 DynDID_0xF232LocalStartUpFailRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S820>/Chart' */

MONPRM volatile uint8 DynDID_0xF233RemoteStartUpFailRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S821>/Chart' */

MONPRM volatile uint8 DynDID_0xF234ADSampleValue[23] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S822>/Chart' */

MONPRM volatile uint8 DynDID_0xF235DigtInSampleValue[5] = { ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S823>/Chart' */

MONPRM volatile uint8 DynDID_0xF236DigtOutSampleValue[5] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S824>/Chart' */

MONPRM volatile uint8 DynDID_0xF237PwrModeSta = ((uint8)0U);/* '<S641>/Signal Conversion1' */
MONPRM volatile uint8 EEReadCtl_BackLadjvalFb = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_BodyWarnSts = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_CrashSta = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarFLSw = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarFRSw = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarRLSw = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarRRSw = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S239>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_DriverDoorLckSw = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DrvSeatSw = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_FlwrMeHomeCtlFb = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_HazardLightSta = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_IllmndLckSts = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_IllmndUnlckSts = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_InrTim = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_LocalStartFailOpRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S239>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_LockHoornOnSts = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_ParkAutoUnlockSetFb = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_RemotePwrLckSta = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_RemoteStartFailRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S239>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_SpdCtlLckSet = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_TrunkAjarSw = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_TrunkLckSw = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_TrunkOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S239>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_TrunkSw = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_WiprIntlTimeSetFb = ((uint8)0U);/* '<S239>/EEReadCtl' */
MONPRM volatile uint64 ESCCtl_UnOrLockfeedback = (0ULL);/* '<S848>/Signal Copy' */
MONPRM volatile boolean ESCLCtl_J436Lck = false;/* '<S848>/ESCLLck' */
MONPRM volatile boolean ESCLCtl_J436PwrSup = false;/* '<S853>/Switch' */
MONPRM volatile boolean ESCLCtl_J436Unlck = false;/* '<S848>/ESCLUnlck' */
MONPRM volatile uint8 ESCLCtl_Lck = ((uint8)0U);/* '<S848>/ESCLLck' */
MONPRM volatile uint8 ESCLCtl_UnOrLockCrtl = ((uint8)0U);/* '<S848>/Truth Table' */
MONPRM volatile uint8 ESCLCtl_Unlck = ((uint8)0U);/* '<S848>/ESCLUnlck' */
MONPRM volatile uint8 HornCtl_AlarmSta = ((uint8)0U);/* '<S283>/Alarm' */
MONPRM volatile uint8 HornCtl_AntiLckSta = ((uint8)0U);/* '<S284>/AntiLck' */
MONPRM volatile uint8 HornCtl_ArmedSta = ((uint8)0U);/* '<S285>/Armed' */
MONPRM volatile boolean HornCtl_HornSwCtl = false;/* '<S287>/LIB_TPD_10ms' */
MONPRM volatile boolean HornCtl_J430HornDrv = false;/* '<S289>/Switch1' */
MONPRM volatile uint8 HornCtl_LockHoornOnSt = ((uint8)0U);/* '<S286>/Multiport Switch' */
MONPRM volatile uint8 HornCtl_LockHoornOnStFb = ((uint8)0U);/* '<S286>/Multiport Switch1' */
MONPRM volatile uint8 HornCtl_PartArmedSta = ((uint8)0U);/* '<S290>/PartArmed' */
MONPRM volatile uint8 HornCtl_SeekSta = ((uint8)0U);/* '<S291>/Seek' */
MONPRM volatile uint8 HornCtl_TrunkWarnSta = ((uint8)0U);/* '<S292>/Chart' */
MONPRM volatile uint8 IMMOCtl_AuthResp[8] = { ((uint8)255U), ((uint8)255U),
  ((uint8)255U), ((uint8)255U), ((uint8)255U), ((uint8)255U), ((uint8)255U),
  ((uint8)255U) };                     /* '<S643>/IMMOCtl' */

MONPRM volatile uint8 IMMOCtl_INVRandom[8] = { ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S643>/Signal Conversion' */

MONPRM volatile uint8 IMMOCtl_SKRead[16] = { ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U) };                  /* '<S643>/IMMOCtl' */

MONPRM volatile uint8 IMMOCtl_SKSta = ((uint8)0U);/* '<S643>/IMMOCtl' */
MONPRM volatile uint8 IODID_BSDLeftCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND44' */
MONPRM volatile uint8 IODID_BSDRightCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND43' */
MONPRM volatile uint8 IODID_BackLampCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND2' */
MONPRM volatile uint8 IODID_BatSaveCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND42' */
MONPRM volatile uint8 IODID_BrakeLightCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND3' */
MONPRM volatile uint8 IODID_DayRunLightCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND6' */
MONPRM volatile uint8 IODID_DomeLampCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND9' */
MONPRM volatile uint8 IODID_DoorLckCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND17' */
MONPRM volatile uint8 IODID_DoorUnlckCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND16' */
MONPRM volatile uint8 IODID_FogLampFCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND14' */
MONPRM volatile uint8 IODID_FogLampRCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND15' */
MONPRM volatile uint8 IODID_HiBeamCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND13' */
MONPRM volatile uint8 IODID_HornCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND40' */
MONPRM volatile uint8 IODID_IG1RlyCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND46' */
MONPRM volatile uint8 IODID_IG2RlyCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND47' */
MONPRM volatile uint8 IODID_LowBeamCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND12' */
MONPRM volatile uint8 IODID_PosLampCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND7' */
MONPRM volatile uint8 IODID_ReverseLampCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND5' */
MONPRM volatile uint8 IODID_TrunkUnlckCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND22' */
MONPRM volatile uint8 IODID_TurnIndcrLCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND' */
MONPRM volatile uint8 IODID_TurnIndcrRCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND1' */
MONPRM volatile uint8 IODID_WinFLCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND32' */
MONPRM volatile uint8 IODID_WinFRCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND33' */
MONPRM volatile uint8 IODID_WiperHiSpdCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND30' */
MONPRM volatile uint8 IODID_WiperLowSpdCtlFlg = ((uint8)0U);/* '<S6>/Bitwise AND31' */
MONPRM volatile boolean LampCtl_AlrmSta = false;/* '<S450>/Chart' */
MONPRM volatile boolean LampCtl_AntiLckSta = false;/* '<S451>/Chart' */
MONPRM volatile boolean LampCtl_ArmedSta = false;/* '<S452>/Chart' */
MONPRM volatile boolean LampCtl_AutoLampSta = false;/* '<S365>/Switch' */
MONPRM volatile boolean LampCtl_AutoLampSw = false;/* '<S351>/LIB_TPD_10ms8' */
MONPRM volatile uint8 LampCtl_BackLadjvalFb = ((uint8)0U);/* '<S321>/Multiport Switch' */
MONPRM volatile boolean LampCtl_BrakeLightSta = false;/* '<S340>/Switch1' */
MONPRM volatile boolean LampCtl_BrakeLightSw = false;/* '<S351>/Logical Operator13' */
MONPRM volatile boolean LampCtl_CrashSta = false;/* '<S453>/Chart' */
MONPRM volatile boolean LampCtl_DayRunLightSta = false;/* '<S334>/Switch1' */
MONPRM volatile boolean LampCtl_DisarmedSta = false;/* '<S454>/Chart' */
MONPRM volatile boolean LampCtl_DomeLampCloseDoor = false;/* '<S377>/Logical Operator6' */
MONPRM volatile boolean LampCtl_DomeLampCtl = false;/* '<S378>/Switch' */
MONPRM volatile boolean LampCtl_DomeLampFLOpen = false;/* '<S380>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampFROpen = false;/* '<S381>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampLockDoor = false;/* '<S393>/Logical Operator' */
MONPRM volatile boolean LampCtl_DomeLampOff = true;/* '<S325>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOffGrad = false;/* '<S325>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOn = false;/* '<S325>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOnGrad = false;/* '<S325>/Truth Table' */
MONPRM volatile uint8 LampCtl_DomeLampPwmDuty = ((uint8)0U);/* '<S335>/Switch1' */
MONPRM volatile boolean LampCtl_DomeLampPwrOff = false;/* '<S386>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampUnlock = false;/* '<S387>/LIB_Tim' */
MONPRM volatile boolean LampCtl_EmerHazardLightSta = false;/* '<S352>/HazardLightLogic' */
MONPRM volatile boolean LampCtl_EmerSta = false;/* '<S455>/Logical Operator' */
MONPRM volatile uint8 LampCtl_FlwrMeHomeCtlFb = ((uint8)0U);/* '<S568>/Multiport Switch1' */
MONPRM volatile boolean LampCtl_FlwrMeHomeSta = false;/* '<S570>/Switch' */
MONPRM volatile uint16 LampCtl_FlwrMeHomeTim = ((uint16)0U);/* '<S568>/Multiport Switch' */
MONPRM volatile boolean LampCtl_FogLampFSta = false;/* '<S345>/Switch1' */
MONPRM volatile boolean LampCtl_FogLampFSw = false;/* '<S351>/LIB_TPD_10ms12' */
MONPRM volatile boolean LampCtl_FogLampRSta = false;/* '<S344>/Switch1' */
MONPRM volatile boolean LampCtl_FogLampRSw = false;/* '<S351>/LIB_TPD_10ms9' */
MONPRM volatile boolean LampCtl_HazardLightSta = false;/* '<S352>/HazardLightLogic' */
MONPRM volatile boolean LampCtl_HazardLightSw = false;/* '<S351>/LIB_TPD_10ms10' */
MONPRM volatile boolean LampCtl_HiBeamShortToBat = false;/* '<S327>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_HiBeamSta = false;/* '<S347>/Switch1' */
MONPRM volatile boolean LampCtl_HiBeamSw = false;/* '<S351>/LIB_TPD_10ms2' */
MONPRM volatile uint8 LampCtl_J408BackLampPWM = ((uint8)0U);/* '<S339>/Switch1' */
MONPRM volatile boolean LampCtl_J420BSDRightCtl = false;/* '<S341>/Switch1' */
MONPRM volatile boolean LampCtl_J422BSDLeftCtl = false;/* '<S342>/Switch1' */
MONPRM volatile boolean LampCtl_J449BoxLamp = false;/* '<S338>/Switch1' */
MONPRM volatile boolean LampCtl_KnobBeamFaultSta = false;/* '<S328>/LIB_TPD_10ms' */
MONPRM volatile boolean LampCtl_LampDelay = false;/* '<S406>/Switch' */
MONPRM volatile uint8 LampCtl_LightIntstSta = ((uint8)0U);/* '<S330>/Chart' */
MONPRM volatile uint16 LampCtl_LightIntstVal = ((uint16)0U);/* '<S351>/Data Type Conversion12' */
MONPRM volatile boolean LampCtl_LowBeamShortToBat = false;/* '<S331>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_LowBeamSta = false;/* '<S343>/Switch1' */
MONPRM volatile boolean LampCtl_LowBeamSw = false;/* '<S351>/LIB_TPD_10ms1' */
MONPRM volatile uint8 LampCtl_PartArmedSta = ((uint8)0U);/* '<S457>/Chart' */
MONPRM volatile boolean LampCtl_PassLightSta = false;/* '<S348>/LIB_Tim' */
MONPRM volatile boolean LampCtl_PassLightSw = false;/* '<S351>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_PosLampSta = false;/* '<S333>/Switch1' */
MONPRM volatile boolean LampCtl_PosLampSw = false;/* '<S351>/LIB_TPD_10ms' */
MONPRM volatile uint16 LampCtl_PrdSucCntL = ((uint16)0U);/* '<S464>/LIB_Pulse' */
MONPRM volatile uint16 LampCtl_PrdSucCntR = ((uint16)0U);/* '<S466>/LIB_Pulse' */
MONPRM volatile uint8 LampCtl_RKEReq = ((uint8)0U);/* '<S351>/Multiport Switch' */
MONPRM volatile boolean LampCtl_ReverseLampSta = false;/* '<S346>/Switch1' */
MONPRM volatile boolean LampCtl_RodBeamFaultSta = false;/* '<S459>/LIB_TPD_10ms' */
MONPRM volatile boolean LampCtl_ThermalrunawaySta = false;/* '<S460>/Chart' */
MONPRM volatile boolean LampCtl_TrunkWarnSta = false;/* '<S461>/Chart' */
MONPRM volatile uint16 LampCtl_TurnIndcrLFlashCnt = ((uint16)0U);/* '<S352>/TurnIndcrArb2' */
MONPRM volatile boolean LampCtl_TurnIndcrLOpen = false;/* '<S463>/Logical Operator' */
MONPRM volatile boolean LampCtl_TurnIndcrLShort = false;/* '<S463>/Logical Operator2' */
MONPRM volatile boolean LampCtl_TurnIndcrLSta = false;/* '<S337>/Switch1' */
MONPRM volatile boolean LampCtl_TurnIndcrLSw = false;/* '<S351>/LIB_TPD_10ms4' */
MONPRM volatile uint16 LampCtl_TurnIndcrLVol = ((uint16)0U);/* '<S536>/C Caller' */
MONPRM volatile boolean LampCtl_TurnIndcrLaneLSw = false;/* '<S351>/LIB_TPD_10ms5' */
MONPRM volatile boolean LampCtl_TurnIndcrLaneRSw = false;/* '<S351>/LIB_TPD_10ms7' */
MONPRM volatile uint8 LampCtl_TurnIndcrMod = ((uint8)0U);/* '<S352>/TurnIndcrLogic' */
MONPRM volatile uint16 LampCtl_TurnIndcrPrd = ((uint16)0U);/* '<S352>/TurnIndcrArb2' */
MONPRM volatile uint16 LampCtl_TurnIndcrRFlashCnt = ((uint16)0U);/* '<S352>/TurnIndcrArb2' */
MONPRM volatile boolean LampCtl_TurnIndcrROpen = false;/* '<S463>/Logical Operator1' */
MONPRM volatile boolean LampCtl_TurnIndcrRShort = false;/* '<S463>/Logical Operator3' */
MONPRM volatile boolean LampCtl_TurnIndcrRSta = false;/* '<S336>/Switch1' */
MONPRM volatile boolean LampCtl_TurnIndcrRSw = false;/* '<S351>/LIB_TPD_10ms6' */
MONPRM volatile uint16 LampCtl_TurnIndcrRVol = ((uint16)0U);/* '<S535>/C Caller' */
MONPRM volatile boolean LampCtl_TurnIndcrRst = false;/* '<S352>/TurnIndcrArb2' */
MONPRM volatile uint16 LampCtl_TurnIndcrWdt = ((uint16)0U);/* '<S352>/TurnIndcrArb2' */
MONPRM volatile uint8 LampCtl_VehModeSta = ((uint8)0U);/* '<S468>/Chart' */
MONPRM volatile uint8 LampCtl_VehSeekSta = ((uint8)0U);/* '<S469>/Chart' */
MONPRM volatile uint8 LampCtl_VehSeekStaFb = ((uint8)0U);/* '<S469>/SeekFb' */
MONPRM volatile boolean LampCtl_WelcomeLampSta = false;/* '<S569>/Switch' */
MONPRM volatile boolean PDUCtl_BrkPwrOn = false;/* '<S868>/Logical Operator1' */
MONPRM volatile boolean PDUCtl_DelayTimPwrOff = false;/* '<S867>/LIB_Tim' */
MONPRM volatile boolean PDUCtl_EmerPwrOff = false;/* '<S867>/Logical Operator13' */
MONPRM volatile boolean PDUCtl_HUPwrOff = false;/* '<S867>/Logical Operator8' */
MONPRM volatile boolean PDUCtl_IG1RelayFault = false;/* '<S869>/LIB_TPD_10ms2' */
MONPRM volatile boolean PDUCtl_IG2RelayFault = false;/* '<S869>/LIB_TPD_10ms1' */
MONPRM volatile boolean PDUCtl_IGRlyIlgCls = false;/* '<S869>/LIB_TPD_10ms3' */
MONPRM volatile uint8 PDUCtl_J421IG1RlyCtl = ((uint8)0U);/* '<S865>/Switch1' */
MONPRM volatile uint8 PDUCtl_J437IG2RlyCtl = ((uint8)0U);/* '<S866>/Switch1' */
MONPRM volatile boolean PDUCtl_KeyChk = false;/* '<S868>/Logical Operator5' */
MONPRM volatile boolean PDUCtl_OpenDoorPwrOn = false;/* '<S868>/Logical Operator' */
MONPRM volatile boolean PDUCtl_OsLckPwrOff = false;/* '<S867>/Logical Operator5' */
MONPRM volatile boolean PDUCtl_PwrOff = false;/* '<S867>/Logical Operator6' */
MONPRM volatile boolean PDUCtl_PwrOn = false;/* '<S868>/Logical Operator10' */
MONPRM volatile boolean PDUCtl_RemotePwrLckFb = false;/* '<S892>/Switch' */
MONPRM volatile uint8 PDUCtl_RemotePwrLckSta = ((uint8)0U);/* '<S868>/RemoteLck' */
MONPRM volatile boolean PDUCtl_RemtOverTimPwrOff = false;/* '<S867>/LIB_Tim1' */
MONPRM volatile boolean PDUCtl_RemtPasvPwrOff = false;/* '<S867>/Logical Operator16' */
MONPRM volatile uint8 PDUCtl_RemtPwrCtlFb = ((uint8)0U);/* '<S644>/RemtPwrCtlFb' */
MONPRM volatile boolean PDUCtl_RemtPwrOff = false;/* '<S867>/Logical Operator12' */
MONPRM volatile boolean PDUCtl_RemtPwrOn = false;/* '<S868>/Logical Operator9' */
MONPRM volatile boolean PDUCtl_StartReq = false;/* '<S908>/Switch' */
MONPRM volatile uint8 PDUCtl_SysPowerSts = ((uint8)0U);/* '<S644>/Chart' */
MONPRM volatile uint8 PDUCtl_SysPwrMode = ((uint8)0U);/* '<S644>/Truth Table' */
MONPRM volatile uint8 PDUCtl_SysPwrModeAct = ((uint8)0U);/* '<S872>/Switch' */
MONPRM volatile boolean PDUCtl_SysPwrModeV = false;/* '<S869>/Switch' */
MONPRM volatile uint8 PEPSCtl_AvaluebleKeyInCar = ((uint8)0U);/* '<S218>/Chart3' */
MONPRM volatile uint8 PEPSCtl_DrvPEAuthentAcsd = ((uint8)0U);/* '<S218>/Chart' */
MONPRM volatile uint8 PEPSCtl_FRPEAuthentAcsd = ((uint8)0U);/* '<S218>/Chart' */
MONPRM volatile uint8 PEPSCtl_FrbdnKeyNr = ((uint8)0U);/* '<S216>/Chart' */
MONPRM volatile uint8 PEPSCtl_IMMOKey = ((uint8)0U);/* '<S219>/Chart5' */
MONPRM volatile uint8 PEPSCtl_IndicationKeyCloser = ((uint8)0U);/* '<S219>/Chart2' */
MONPRM volatile uint8 PEPSCtl_KeyInCarSta = ((uint8)0U);/* '<S218>/Chart' */
MONPRM volatile uint8 PEPSCtl_KeyLoBattLvlWarn = ((uint8)0U);/* '<S217>/Chart3' */
MONPRM volatile uint8 PEPSCtl_KeySta = ((uint8)0U);/* '<S219>/Chart1' */
MONPRM volatile uint8 PEPSCtl_LckWlcmReq = ((uint8)0U);/* '<S220>/Chart' */
MONPRM volatile uint8 PEPSCtl_PSAuthentRes = ((uint8)0U);/* '<S219>/Chart' */
MONPRM volatile uint8 PEPSCtl_PSReq = ((uint8)0U);/* '<S219>/Chart' */
MONPRM volatile uint8 PEPSCtl_UnlckWlcmReq = ((uint8)0U);/* '<S220>/Chart' */
MONPRM volatile uint8 PEPSCtl_WarnKeyOutReminder = ((uint8)0U);/* '<S217>/Chart' */
MONPRM volatile uint8 PEPSCtl_WarnNoKeyFound = ((uint8)0U);/* '<S219>/Chart2' */
MONPRM volatile boolean RVMCtl_J42Heat = false;/* '<S124>/Switch' */
MONPRM volatile uint8 SCS_FrntWiprSwtSt = ((uint8)0U);/* '<S242>/Signal Conversion' */
MONPRM volatile boolean SCS_FrntWshrSwtSt = false;/* '<S242>/Signal Conversion1' */
MONPRM volatile boolean SCS_FrntWshrSwtStVD = false;/* '<S242>/Signal Conversion2' */
MONPRM volatile boolean SCS_WiprSwtStVD = false;/* '<S242>/Signal Conversion3' */
MONPRM volatile uint8 SeatCtl_CN167DrvSeatHtPWM = ((uint8)0U);/* '<S134>/Switch' */
MONPRM volatile boolean SeatCtl_DrvNTCOpen = false;/* '<S129>/LIB_TPD_Ts1' */
MONPRM volatile boolean SeatCtl_DrvNTCShort = false;/* '<S129>/LIB_TPD_Ts' */
MONPRM volatile sint8 SeatCtl_DrvSeatTemp = 0;/* '<S129>/Data Type Conversion' */
MONPRM volatile uint8 SeatCtl_MaiDrvSeatStFb = ((uint8)0U);/* '<S129>/Multiport Switch' */
MONPRM volatile uint8 SeatCtl_RemtHeatFb = ((uint8)0U);/* '<S129>/HeatFb' */
MONPRM volatile boolean SteerWhlCtl_J447SteerWhlHt = false;/* '<S141>/Switch' */
MONPRM volatile uint8 SteerWhlCtl_RemtHeatFb = ((uint8)0U);/* '<S137>/HeatFb' */
MONPRM volatile uint8 SteerWhlCtl_SteerWhlHeatSts = ((uint8)0U);/* '<S137>/HeatSet' */
MONPRM volatile sint8 SteerWhlCtl_SteerWhlTemp = 0;/* '<S137>/Data Type Conversion' */
MONPRM volatile boolean WakeUpCtl_NMReq = false;/* '<S923>/Switch' */
MONPRM volatile boolean WakeUpCtl_SleepAllwd = false;/* '<S911>/Logical Operator5' */
MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnSw = false;/* '<S150>/LIB_TPD_10ms9' */
MONPRM volatile boolean WinCtl_DrvPsgWinDnSw = false;/* '<S150>/LIB_TPD_10ms8' */
MONPRM volatile boolean WinCtl_DrvPsgWinUpSw = false;/* '<S150>/LIB_TPD_10ms7' */
MONPRM volatile boolean WinCtl_DrvWinAutoDnReq = false;/* '<S152>/Chart10' */
MONPRM volatile boolean WinCtl_DrvWinAutoDnSw = false;/* '<S150>/LIB_TPD_10ms2' */
MONPRM volatile boolean WinCtl_DrvWinDnProt = false;/* '<S151>/LIB_CntLimit1' */
MONPRM volatile boolean WinCtl_DrvWinDnReq = false;/* '<S152>/Chart2' */
MONPRM volatile boolean WinCtl_DrvWinDnSw = false;/* '<S150>/LIB_TPD_10ms1' */
MONPRM volatile boolean WinCtl_DrvWinMotorLocked = false;/* '<S152>/LIB_TPD_10ms3' */
MONPRM volatile uint8 WinCtl_DrvWinReq = ((uint8)0U);/* '<S152>/Switch11' */
MONPRM volatile uint8 WinCtl_DrvWinSta = ((uint8)0U);/* '<S10>/DrvWinCtl' */
MONPRM volatile boolean WinCtl_DrvWinUpProt = false;/* '<S151>/LIB_CntLimit' */
MONPRM volatile boolean WinCtl_DrvWinUpReq = false;/* '<S152>/Chart3' */
MONPRM volatile boolean WinCtl_DrvWinUpSw = false;/* '<S150>/LIB_TPD_10ms3' */
MONPRM volatile boolean WinCtl_J51DrvWinUp = false;/* '<S145>/Switch1' */
MONPRM volatile boolean WinCtl_J53DrvWinDn = false;/* '<S148>/Switch1' */
MONPRM volatile boolean WinCtl_J55PsgWinUp = false;/* '<S146>/Switch' */
MONPRM volatile boolean WinCtl_J57PsgWinDn = false;/* '<S147>/Switch' */
MONPRM volatile boolean WinCtl_PsgWinAutoDnReq = false;/* '<S152>/Chart1' */
MONPRM volatile boolean WinCtl_PsgWinAutoDnSw = false;/* '<S150>/LIB_TPD_10ms6' */
MONPRM volatile boolean WinCtl_PsgWinDnProt = false;/* '<S151>/LIB_CntLimit3' */
MONPRM volatile boolean WinCtl_PsgWinDnReq = false;/* '<S152>/Chart4' */
MONPRM volatile boolean WinCtl_PsgWinDnSw = false;/* '<S150>/LIB_TPD_10ms5' */
MONPRM volatile boolean WinCtl_PsgWinMotorLocked = false;/* '<S152>/LIB_TPD_10ms1' */
MONPRM volatile uint8 WinCtl_PsgWinReq = ((uint8)0U);/* '<S152>/Switch10' */
MONPRM volatile uint8 WinCtl_PsgWinSta = ((uint8)0U);/* '<S10>/PsgWinCtl' */
MONPRM volatile boolean WinCtl_PsgWinUpProt = false;/* '<S151>/LIB_CntLimit2' */
MONPRM volatile boolean WinCtl_PsgWinUpReq = false;/* '<S152>/Chart5' */
MONPRM volatile boolean WinCtl_PsgWinUpSw = false;/* '<S150>/LIB_TPD_10ms4' */
MONPRM volatile boolean WiperCtl_HiSpdDrv = false;/* '<S586>/Switch1' */
MONPRM volatile uint16 WiperCtl_InrTim = ((uint16)0U);/* '<S592>/Multiport Switch' */
MONPRM volatile boolean WiperCtl_InrTimChg = false;/* '<S592>/Relational Operator1' */
MONPRM volatile boolean WiperCtl_LockedRotorProtSta = false;/* '<S584>/Logical Operator2' */
MONPRM volatile boolean WiperCtl_LowSpdDrv = false;/* '<S585>/Switch1' */
MONPRM volatile boolean WiperCtl_WashMotorDrv = false;/* '<S587>/Switch1' */
MONPRM volatile boolean WiperCtl_WashSw = false;/* '<S588>/LIB_TPD_10ms5' */
MONPRM volatile boolean WiperCtl_WashWiperSta = false;/* '<S589>/LIB_TPD_10ms6' */
MONPRM volatile boolean WiperCtl_WiperHiSpdSta = false;/* '<S591>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperHiSpdSw = false;/* '<S588>/LIB_TPD_10ms4' */
MONPRM volatile boolean WiperCtl_WiperInrSta = false;/* '<S592>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperInrSw = false;/* '<S588>/LIB_TPD_10ms2' */
MONPRM volatile boolean WiperCtl_WiperLowSpdSta = false;/* '<S593>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperLowSpdSw = false;/* '<S588>/LIB_TPD_10ms3' */
MONPRM volatile boolean WiperCtl_WiperMaintSta = false;/* '<S631>/Switch' */
MONPRM volatile boolean WiperCtl_WiperMistSta = false;/* '<S595>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperMistSw = false;/* '<S588>/LIB_TPD_10ms' */
MONPRM volatile boolean WiperCtl_WiperOffSta = false;/* '<S596>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperOffSw = false;/* '<S588>/LIB_TPD_10ms1' */
MONPRM volatile boolean WiperCtl_WiperParkPosSw = false;/* '<S588>/LIB_TPD_10ms6' */
MONPRM volatile uint8 WiperCtl_WiperSta = ((uint8)0U);/* '<S590>/Chart' */
MONPRM volatile uint8 WiperCtl_WiprIntlTimeSetFb = ((uint8)0U);/* '<S592>/Multiport Switch1' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
