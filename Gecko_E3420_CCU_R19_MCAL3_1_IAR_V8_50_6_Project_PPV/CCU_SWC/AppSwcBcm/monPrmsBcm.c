/*
 * File: monPrmsBcm.c
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1462
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Thu Oct 24 15:51:05 2024
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
MONPRM volatile boolean AlmSysCtl_AlrmWarnTimOut = false;/* '<S619>/AlmSysLogic' */
MONPRM volatile uint8 AlmSysCtl_BodyWarnSts = ((uint8)0U);/* '<S619>/AlmSysLogic' */
MONPRM volatile uint16 BSW_CN744DrvSeatResis = ((uint16)0U);/* '<S1>/C Caller14' */
MONPRM volatile uint16 BSW_DrvWinMotorCur = ((uint16)0U);/* '<S1>/C Caller25' */
MONPRM volatile uint8 BSW_EEIlluminatedEntrySys = ((uint8)0U);/* '<S4>/C Caller37' */
MONPRM volatile uint8 BSW_EEKeyEntry = ((uint8)0U);/* '<S4>/C Caller38' */
MONPRM volatile uint8 BSW_FogLampFCfg = ((uint8)0U);/* '<S3>/C Caller1' */
MONPRM volatile uint8 BSW_HiBeamDigSts = ((uint8)0U);/* '<S317>/C Caller1' */
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
MONPRM volatile uint8 BSW_LowBeamDigSts = ((uint8)0U);/* '<S321>/C Caller' */
MONPRM volatile uint16 BSW_PsgWinMotorCur = ((uint16)0U);/* '<S1>/C Caller29' */
MONPRM volatile uint8 BSW_RKEReq = ((uint8)0U);/* '<S3>/C Caller32' */
MONPRM volatile uint8 BSW_WakeupReas = ((uint8)0U);/* '<S627>/Signal Conversion' */
MONPRM volatile boolean BatSaveCtl_DoorChgSta = false;/* '<S648>/Logical Operator1' */
MONPRM volatile boolean BatSaveCtl_DoorLckPwrOff = false;/* '<S647>/LIB_PosPluse1' */
MONPRM volatile boolean BatSaveCtl_DoorUnlckPwrOn = false;/* '<S648>/Relational Operator1' */
MONPRM volatile boolean BatSaveCtl_J64SavePwr = false;/* '<S646>/Switch1' */
MONPRM volatile boolean BatSaveCtl_PwrModeOff = false;/* '<S647>/LIB_PosPluse' */
MONPRM volatile boolean BatSaveCtl_PwrModeOn = false;/* '<S648>/Relational Operator' */
MONPRM volatile boolean BatSaveCtl_PwrOff = false;/* '<S647>/Logical Operator' */
MONPRM volatile boolean BatSaveCtl_PwrOn = false;/* '<S648>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_AutoLck = false;/* '<S717>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_AutoLckSta = false;/* '<S718>/Switch' */
MONPRM volatile boolean DoorLckCtl_CrshUnlck = false;/* '<S691>/Chart' */
MONPRM volatile boolean DoorLckCtl_DoorAjarFLSw = false;/* '<S660>/LIB_TPD_10ms1' */
MONPRM volatile boolean DoorLckCtl_DoorAjarFRSw = false;/* '<S660>/LIB_TPD_10ms2' */
MONPRM volatile boolean DoorLckCtl_DoorAjarRLSw = false;/* '<S660>/LIB_TPD_10ms6' */
MONPRM volatile boolean DoorLckCtl_DoorAjarRRSw = false;/* '<S660>/LIB_TPD_10ms7' */
MONPRM volatile boolean DoorLckCtl_DoorProtUnlck = false;/* '<S663>/LIB_Tim' */
MONPRM volatile boolean DoorLckCtl_DriverDoorLckSw = false;/* '<S660>/LIB_TPD_10ms' */
MONPRM volatile boolean DoorLckCtl_DrvPESw = false;/* '<S660>/LIB_TPD_10ms3' */
MONPRM volatile boolean DoorLckCtl_DrvSeatSw = false;/* '<S660>/LIB_TPD_10ms11' */
MONPRM volatile uint8 DoorLckCtl_EEIlluminatedEntrySys = ((uint8)0U);/* '<S660>/Switch14' */
MONPRM volatile uint8 DoorLckCtl_EEKeyEntry = ((uint8)0U);/* '<S660>/Switch13' */
MONPRM volatile boolean DoorLckCtl_HULck = false;/* '<S678>/Logical Operator2' */
MONPRM volatile boolean DoorLckCtl_HUUnLck = false;/* '<S692>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_HoodAjarSw = true;/* '<S660>/Constant69' */
MONPRM volatile uint8 DoorLckCtl_IllmndLckSts = ((uint8)0U);/* '<S665>/Multiport Switch' */
MONPRM volatile uint8 DoorLckCtl_IllmndLckStsFb = ((uint8)0U);/* '<S665>/Multiport Switch1' */
MONPRM volatile uint8 DoorLckCtl_IllmndSts = ((uint8)0U);/* '<S660>/Switch15' */
MONPRM volatile uint8 DoorLckCtl_IllmndUnlockSts = ((uint8)0U);/* '<S666>/Multiport Switch' */
MONPRM volatile uint8 DoorLckCtl_IllmndUnlockStsFb = ((uint8)0U);/* '<S666>/Multiport Switch1' */
MONPRM volatile boolean DoorLckCtl_InsLck = false;/* '<S667>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_InsLckSta = ((uint8)0U);/* '<S622>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_InsUnlck = false;/* '<S668>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_J511TrunkUnlck = false;/* '<S658>/Switch1' */
MONPRM volatile boolean DoorLckCtl_J54DoorLck = false;/* '<S657>/Switch1' */
MONPRM volatile boolean DoorLckCtl_J56DoorUnlck = false;/* '<S659>/Switch1' */
MONPRM volatile boolean DoorLckCtl_MechAntiLck = false;/* '<S663>/Logical Operator3' */
MONPRM volatile boolean DoorLckCtl_MechLck = false;/* '<S710>/Logical Operator3' */
MONPRM volatile boolean DoorLckCtl_MechUnlck = false;/* '<S734>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_MotorProt = false;/* '<S669>/Switch' */
MONPRM volatile boolean DoorLckCtl_OsLck = false;/* '<S670>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_OsLckSta = ((uint8)0U);/* '<S622>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_OsUnlck = false;/* '<S671>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_PELck = false;/* '<S711>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_PEUnlck = false;/* '<S735>/Logical Operator1' */
MONPRM volatile uint8 DoorLckCtl_ParkAutoUnlockSetFb = ((uint8)0U);/* '<S673>/Multiport Switch' */
MONPRM volatile boolean DoorLckCtl_ParkUnlck = false;/* '<S693>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_PsgPESw = false;/* '<S660>/LIB_TPD_10ms4' */
MONPRM volatile boolean DoorLckCtl_RKEAntiLck = false;/* '<S663>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_RKELck = false;/* '<S724>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_RKEUnlck = false;/* '<S742>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSet = ((uint8)1U);/* '<S674>/Constant8' */
MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSetFb = ((uint8)0U);/* '<S674>/Constant9' */
MONPRM volatile boolean DoorLckCtl_SpdLck = false;/* '<S684>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_ThermRunawayUnlck = false;/* '<S694>/Chart' */
MONPRM volatile boolean DoorLckCtl_TrunkAjarSw = false;/* '<S660>/LIB_TPD_10ms8' */
MONPRM volatile boolean DoorLckCtl_TrunkAutoLck = false;/* '<S729>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_TrunkLckSta = ((uint8)0U);/* '<S622>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_TrunkLckSw = true;/* '<S622>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_TrunkRKEUnlck = false;/* '<S746>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TrunkSw = false;/* '<S660>/LIB_TPD_10ms5' */
MONPRM volatile boolean DoorLckCtl_TrunkUnlck = false;/* '<S737>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_VehRun = false;/* '<S660>/Logical Operator4' */
MONPRM volatile float32 DoorLckCtl_VehSpd = 0.0F;/* '<S660>/Switch' */
MONPRM volatile boolean DoorLckCtl_VehStop = false;/* '<S660>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_WelcomeLck = false;/* '<S714>/Logical Operator2' */
MONPRM volatile boolean DoorLckCtl_WelcomeUnlck = false;/* '<S738>/Logical Operator1' */
MONPRM volatile uint8 DynDID_0xF22CAntitheftSta = ((uint8)0U);/* '<S623>/Signal Conversion' */
MONPRM volatile uint8 DynDID_0xF230DoorOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S791>/Chart' */

MONPRM volatile uint8 DynDID_0xF231TrunkOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S792>/Chart' */

MONPRM volatile uint8 DynDID_0xF232LocalStartUpFailRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S793>/Chart' */

MONPRM volatile uint8 DynDID_0xF233RemoteStartUpFailRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S794>/Chart' */

MONPRM volatile uint8 DynDID_0xF234ADSampleValue[23] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S795>/Chart' */

MONPRM volatile uint8 DynDID_0xF235DigtInSampleValue[5] = { ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S796>/Chart' */

MONPRM volatile uint8 DynDID_0xF236DigtOutSampleValue[5] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S797>/Chart' */

MONPRM volatile uint8 DynDID_0xF237PwrModeSta = ((uint8)0U);/* '<S623>/Signal Conversion1' */
MONPRM volatile uint8 EEReadCtl_BackLadjvalFb = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_BodyWarnSts = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_CrashSta = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarFLSw = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarFRSw = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarRLSw = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorAjarRRSw = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DoorOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S231>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_DriverDoorLckSw = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_DrvSeatSw = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_FlwrMeHomeCtlFb = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_HazardLightSta = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_IllmndLckSts = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_IllmndUnlckSts = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_InrTim = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_LocalStartFailOpRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S231>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_LockHoornOnSts = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_ParkAutoUnlockSetFb = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_RemoteStartFailRecord[10] = { ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S231>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_SpdCtlLckSet = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_TrunkAjarSw = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_TrunkLckSw = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_TrunkOpRecord[10] = { ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U),
  ((uint8)0U), ((uint8)0U) };          /* '<S231>/EEReadCtl' */

MONPRM volatile uint8 EEReadCtl_TrunkSw = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_WiprIntlTimeSetFb = ((uint8)0U);/* '<S231>/EEReadCtl' */
MONPRM volatile uint64 ESCCtl_UnOrLockfeedback = (0ULL);/* '<S821>/Signal Copy' */
MONPRM volatile boolean ESCLCtl_J436Lck = false;/* '<S821>/ESCLLck' */
MONPRM volatile boolean ESCLCtl_J436PwrSup = false;/* '<S826>/Switch' */
MONPRM volatile boolean ESCLCtl_J436Unlck = false;/* '<S821>/ESCLUnlck' */
MONPRM volatile uint8 ESCLCtl_Lck = ((uint8)0U);/* '<S821>/ESCLLck' */
MONPRM volatile uint8 ESCLCtl_UnOrLockCrtl = ((uint8)0U);/* '<S821>/Truth Table' */
MONPRM volatile uint8 ESCLCtl_Unlck = ((uint8)0U);/* '<S821>/ESCLUnlck' */
MONPRM volatile uint8 HornCtl_AlarmSta = ((uint8)0U);/* '<S275>/Alarm' */
MONPRM volatile uint8 HornCtl_AntiLckSta = ((uint8)0U);/* '<S276>/AntiLck' */
MONPRM volatile uint8 HornCtl_ArmedSta = ((uint8)0U);/* '<S277>/Armed' */
MONPRM volatile boolean HornCtl_HornSwCtl = false;/* '<S279>/LIB_TPD_10ms' */
MONPRM volatile boolean HornCtl_J430HornDrv = false;/* '<S281>/Switch1' */
MONPRM volatile uint8 HornCtl_LockHoornOnSt = ((uint8)0U);/* '<S278>/Multiport Switch' */
MONPRM volatile uint8 HornCtl_LockHoornOnStFb = ((uint8)0U);/* '<S278>/Multiport Switch1' */
MONPRM volatile uint8 HornCtl_PartArmedSta = ((uint8)0U);/* '<S282>/PartArmed' */
MONPRM volatile uint8 HornCtl_SeekSta = ((uint8)0U);/* '<S283>/Seek' */
MONPRM volatile uint8 HornCtl_TrunkWarnSta = ((uint8)0U);/* '<S284>/Chart' */
MONPRM volatile uint8 IMMOCtl_AuthResp[8] = { ((uint8)255U), ((uint8)255U),
  ((uint8)255U), ((uint8)255U), ((uint8)255U), ((uint8)255U), ((uint8)255U),
  ((uint8)255U) };                     /* '<S625>/IMMOCtl' */

MONPRM volatile uint8 IMMOCtl_INVRandom[8] = { ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S625>/Signal Conversion' */

MONPRM volatile uint8 IMMOCtl_SKRead[16] = { ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U) };                  /* '<S625>/IMMOCtl' */

MONPRM volatile uint8 IMMOCtl_SKSta = ((uint8)0U);/* '<S625>/IMMOCtl' */
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
MONPRM volatile boolean LampCtl_AlrmSta = false;/* '<S437>/Chart' */
MONPRM volatile boolean LampCtl_AntiLckSta = false;/* '<S438>/Chart' */
MONPRM volatile boolean LampCtl_ArmedSta = false;/* '<S439>/Chart' */
MONPRM volatile boolean LampCtl_AutoLampSta = false;/* '<S354>/Switch' */
MONPRM volatile boolean LampCtl_AutoLampSw = false;/* '<S340>/LIB_TPD_10ms8' */
MONPRM volatile uint8 LampCtl_BackLadjvalFb = ((uint8)0U);/* '<S311>/Multiport Switch' */
MONPRM volatile boolean LampCtl_BrakeLightSta = false;/* '<S329>/Switch1' */
MONPRM volatile boolean LampCtl_BrakeLightSw = false;/* '<S340>/Logical Operator13' */
MONPRM volatile boolean LampCtl_CrashSta = false;/* '<S440>/Chart' */
MONPRM volatile boolean LampCtl_DayRunLightSta = false;/* '<S323>/Switch1' */
MONPRM volatile boolean LampCtl_DisarmedSta = false;/* '<S441>/Chart' */
MONPRM volatile boolean LampCtl_DomeLampCloseDoor = false;/* '<S366>/Logical Operator6' */
MONPRM volatile boolean LampCtl_DomeLampCtl = false;/* '<S367>/Switch' */
MONPRM volatile boolean LampCtl_DomeLampFLOpen = false;/* '<S369>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampFROpen = false;/* '<S370>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampLockDoor = false;/* '<S380>/Logical Operator' */
MONPRM volatile boolean LampCtl_DomeLampOff = true;/* '<S315>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOffGrad = false;/* '<S315>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOn = false;/* '<S315>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOnGrad = false;/* '<S315>/Truth Table' */
MONPRM volatile uint8 LampCtl_DomeLampPwmDuty = ((uint8)0U);/* '<S324>/Switch1' */
MONPRM volatile boolean LampCtl_DomeLampPwrOff = false;/* '<S373>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampUnlock = false;/* '<S374>/LIB_Tim' */
MONPRM volatile boolean LampCtl_EmerHazardLightSta = false;/* '<S341>/HazardLightLogic' */
MONPRM volatile boolean LampCtl_EmerSta = false;/* '<S442>/Logical Operator' */
MONPRM volatile uint8 LampCtl_FlwrMeHomeCtlFb = ((uint8)0U);/* '<S550>/Multiport Switch1' */
MONPRM volatile boolean LampCtl_FlwrMeHomeSta = false;/* '<S552>/Switch' */
MONPRM volatile uint16 LampCtl_FlwrMeHomeTim = ((uint16)0U);/* '<S550>/Multiport Switch' */
MONPRM volatile boolean LampCtl_FogLampFSta = false;/* '<S334>/Switch1' */
MONPRM volatile boolean LampCtl_FogLampFSw = false;/* '<S340>/LIB_TPD_10ms12' */
MONPRM volatile boolean LampCtl_FogLampRSta = false;/* '<S333>/Switch1' */
MONPRM volatile boolean LampCtl_FogLampRSw = false;/* '<S340>/LIB_TPD_10ms9' */
MONPRM volatile boolean LampCtl_HazardLightSta = false;/* '<S341>/HazardLightLogic' */
MONPRM volatile boolean LampCtl_HazardLightSw = false;/* '<S340>/LIB_TPD_10ms10' */
MONPRM volatile boolean LampCtl_HiBeamShortToBat = false;/* '<S317>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_HiBeamSta = false;/* '<S336>/Switch1' */
MONPRM volatile boolean LampCtl_HiBeamSw = false;/* '<S340>/LIB_TPD_10ms2' */
MONPRM volatile uint8 LampCtl_J408BackLampPWM = ((uint8)0U);/* '<S328>/Switch1' */
MONPRM volatile boolean LampCtl_J420BSDRightCtl = false;/* '<S330>/Switch1' */
MONPRM volatile boolean LampCtl_J422BSDLeftCtl = false;/* '<S331>/Switch1' */
MONPRM volatile boolean LampCtl_J449BoxLamp = false;/* '<S327>/Switch1' */
MONPRM volatile boolean LampCtl_KnobBeamFaultSta = false;/* '<S318>/LIB_TPD_10ms' */
MONPRM volatile boolean LampCtl_LampDelay = false;/* '<S393>/Switch' */
MONPRM volatile uint8 LampCtl_LightIntstSta = ((uint8)0U);/* '<S320>/Chart' */
MONPRM volatile uint16 LampCtl_LightIntstVal = ((uint16)0U);/* '<S340>/Data Type Conversion12' */
MONPRM volatile boolean LampCtl_LowBeamShortToBat = false;/* '<S321>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_LowBeamSta = false;/* '<S332>/Switch1' */
MONPRM volatile boolean LampCtl_LowBeamSw = false;/* '<S340>/LIB_TPD_10ms1' */
MONPRM volatile uint8 LampCtl_PartArmedSta = ((uint8)0U);/* '<S444>/Chart' */
MONPRM volatile boolean LampCtl_PassLightSta = false;/* '<S337>/LIB_Tim' */
MONPRM volatile boolean LampCtl_PassLightSw = false;/* '<S340>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_PosLampSta = false;/* '<S322>/Switch1' */
MONPRM volatile boolean LampCtl_PosLampSw = false;/* '<S340>/LIB_TPD_10ms' */
MONPRM volatile uint16 LampCtl_PrdSucCntL = ((uint16)0U);/* '<S451>/LIB_Pulse' */
MONPRM volatile uint16 LampCtl_PrdSucCntR = ((uint16)0U);/* '<S453>/LIB_Pulse' */
MONPRM volatile uint8 LampCtl_RKEReq = ((uint8)0U);/* '<S340>/Multiport Switch' */
MONPRM volatile boolean LampCtl_ReverseLampSta = false;/* '<S335>/Switch1' */
MONPRM volatile boolean LampCtl_RodBeamFaultSta = false;/* '<S446>/LIB_TPD_10ms' */
MONPRM volatile boolean LampCtl_ThermalrunawaySta = false;/* '<S447>/Chart' */
MONPRM volatile boolean LampCtl_TrunkWarnSta = false;/* '<S448>/Chart' */
MONPRM volatile uint16 LampCtl_TurnIndcrLFlashCnt = ((uint16)0U);/* '<S341>/TurnIndcrArb2' */
MONPRM volatile boolean LampCtl_TurnIndcrLOpen = false;/* '<S450>/Logical Operator' */
MONPRM volatile boolean LampCtl_TurnIndcrLShort = false;/* '<S450>/Logical Operator2' */
MONPRM volatile boolean LampCtl_TurnIndcrLSta = false;/* '<S326>/Switch1' */
MONPRM volatile boolean LampCtl_TurnIndcrLSw = false;/* '<S340>/LIB_TPD_10ms4' */
MONPRM volatile uint16 LampCtl_TurnIndcrLVol = ((uint16)0U);/* '<S523>/C Caller' */
MONPRM volatile boolean LampCtl_TurnIndcrLaneLSw = false;/* '<S340>/LIB_TPD_10ms5' */
MONPRM volatile boolean LampCtl_TurnIndcrLaneRSw = false;/* '<S340>/LIB_TPD_10ms7' */
MONPRM volatile uint8 LampCtl_TurnIndcrMod = ((uint8)0U);/* '<S341>/TurnIndcrLogic' */
MONPRM volatile uint16 LampCtl_TurnIndcrPrd = ((uint16)0U);/* '<S341>/TurnIndcrArb2' */
MONPRM volatile uint16 LampCtl_TurnIndcrRFlashCnt = ((uint16)0U);/* '<S341>/TurnIndcrArb2' */
MONPRM volatile boolean LampCtl_TurnIndcrROpen = false;/* '<S450>/Logical Operator1' */
MONPRM volatile boolean LampCtl_TurnIndcrRShort = false;/* '<S450>/Logical Operator3' */
MONPRM volatile boolean LampCtl_TurnIndcrRSta = false;/* '<S325>/Switch1' */
MONPRM volatile boolean LampCtl_TurnIndcrRSw = false;/* '<S340>/LIB_TPD_10ms6' */
MONPRM volatile uint16 LampCtl_TurnIndcrRVol = ((uint16)0U);/* '<S522>/C Caller' */
MONPRM volatile boolean LampCtl_TurnIndcrRst = false;/* '<S341>/TurnIndcrArb2' */
MONPRM volatile uint16 LampCtl_TurnIndcrWdt = ((uint16)0U);/* '<S341>/TurnIndcrArb2' */
MONPRM volatile uint8 LampCtl_VehModeSta = ((uint8)0U);/* '<S455>/Chart' */
MONPRM volatile boolean LampCtl_VehSeekSta = false;/* '<S456>/Chart' */
MONPRM volatile boolean LampCtl_WelcomeLampSta = false;/* '<S551>/Switch' */
MONPRM volatile boolean PDUCtl_BrkPwrOn = false;/* '<S841>/Logical Operator1' */
MONPRM volatile boolean PDUCtl_DelayTimPwrOff = false;/* '<S840>/LIB_Tim' */
MONPRM volatile boolean PDUCtl_HUPwrOff = false;/* '<S840>/Logical Operator8' */
MONPRM volatile boolean PDUCtl_IG1RelayFault = false;/* '<S842>/LIB_TPD_10ms2' */
MONPRM volatile boolean PDUCtl_IG2RelayFault = false;/* '<S842>/LIB_TPD_10ms1' */
MONPRM volatile boolean PDUCtl_IGRlyIlgCls = false;/* '<S842>/LIB_TPD_10ms3' */
MONPRM volatile uint8 PDUCtl_J421IG1RlyCtl = ((uint8)0U);/* '<S838>/Switch1' */
MONPRM volatile uint8 PDUCtl_J437IG2RlyCtl = ((uint8)0U);/* '<S839>/Switch1' */
MONPRM volatile boolean PDUCtl_KeyChk = false;/* '<S841>/Logical Operator5' */
MONPRM volatile boolean PDUCtl_OpenDoorPwrOn = false;/* '<S841>/Logical Operator' */
MONPRM volatile boolean PDUCtl_OsLckPwrOff = false;/* '<S840>/Logical Operator5' */
MONPRM volatile boolean PDUCtl_PwrOff = false;/* '<S840>/Logical Operator6' */
MONPRM volatile boolean PDUCtl_PwrOn = false;/* '<S841>/Logical Operator2' */
MONPRM volatile boolean PDUCtl_StartReq = false;/* '<S870>/Switch' */
MONPRM volatile uint8 PDUCtl_SysPowerSts = ((uint8)0U);/* '<S626>/Chart' */
MONPRM volatile uint8 PDUCtl_SysPwrMode = ((uint8)0U);/* '<S626>/Truth Table' */
MONPRM volatile uint8 PDUCtl_SysPwrModeAct = ((uint8)0U);/* '<S844>/Switch' */
MONPRM volatile boolean PDUCtl_SysPwrModeV = false;/* '<S842>/Switch' */
MONPRM volatile uint8 PEPSCtl_AvaluebleKeyInCar = ((uint8)0U);/* '<S209>/Chart3' */
MONPRM volatile uint8 PEPSCtl_DrvPEAuthentAcsd = ((uint8)0U);/* '<S209>/Chart' */
MONPRM volatile uint8 PEPSCtl_FRPEAuthentAcsd = ((uint8)0U);/* '<S209>/Chart' */
MONPRM volatile uint8 PEPSCtl_FrbdnKeyNr = ((uint8)0U);/* '<S207>/Chart' */
MONPRM volatile uint8 PEPSCtl_IMMOKey = ((uint8)0U);/* '<S210>/Chart5' */
MONPRM volatile uint8 PEPSCtl_IndicationKeyCloser = ((uint8)0U);/* '<S210>/Chart3' */
MONPRM volatile uint8 PEPSCtl_KeyInCarSta = ((uint8)0U);/* '<S209>/Chart' */
MONPRM volatile uint8 PEPSCtl_KeyLoBattLvlWarn = ((uint8)0U);/* '<S208>/Chart3' */
MONPRM volatile uint8 PEPSCtl_KeySta = ((uint8)0U);/* '<S210>/Chart1' */
MONPRM volatile uint8 PEPSCtl_LckWlcmReq = ((uint8)0U);/* '<S211>/Chart' */
MONPRM volatile uint8 PEPSCtl_PSAuthentRes = ((uint8)0U);/* '<S210>/Chart' */
MONPRM volatile uint8 PEPSCtl_PSReq = ((uint8)0U);/* '<S210>/Chart' */
MONPRM volatile uint8 PEPSCtl_UnlckWlcmReq = ((uint8)0U);/* '<S211>/Chart' */
MONPRM volatile uint8 PEPSCtl_WarnKeyOutReminder = ((uint8)0U);/* '<S208>/Chart' */
MONPRM volatile uint8 PEPSCtl_WarnNoKeyFound = ((uint8)0U);/* '<S210>/Chart2' */
MONPRM volatile boolean RVMCtl_J42Heat = false;/* '<S124>/Switch' */
MONPRM volatile uint8 SCS_FrntWiprSwtSt = ((uint8)0U);/* '<S234>/Signal Conversion' */
MONPRM volatile boolean SCS_FrntWshrSwtSt = false;/* '<S234>/Signal Conversion1' */
MONPRM volatile boolean SCS_FrntWshrSwtStVD = false;/* '<S234>/Signal Conversion2' */
MONPRM volatile boolean SCS_WiprSwtStVD = false;/* '<S234>/Signal Conversion3' */
MONPRM volatile uint8 SeatCtl_CN167DrvSeatHtPWM = ((uint8)0U);/* '<S131>/Switch' */
MONPRM volatile sint8 SeatCtl_DrvSeatTemp = 0;/* '<S129>/Data Type Conversion' */
MONPRM volatile uint8 SeatCtl_MaiDrvSeatStFb = ((uint8)0U);/* '<S129>/Multiport Switch' */
MONPRM volatile boolean SteerWhlCtl_J447SteerWhlHt = false;/* '<S134>/Switch' */
MONPRM volatile uint8 SteerWhlCtl_SteerWhlHeatSts = ((uint8)0U);/* '<S132>/Multiport Switch' */
MONPRM volatile sint8 SteerWhlCtl_SteerWhlTemp = 0;/* '<S132>/Data Type Conversion' */
MONPRM volatile boolean WakeUpCtl_NMReq = false;/* '<S885>/Switch' */
MONPRM volatile boolean WakeUpCtl_SleepAllwd = false;/* '<S873>/Logical Operator5' */
MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnSw = false;/* '<S141>/LIB_TPD_10ms9' */
MONPRM volatile boolean WinCtl_DrvPsgWinDnSw = false;/* '<S141>/LIB_TPD_10ms8' */
MONPRM volatile boolean WinCtl_DrvPsgWinUpSw = false;/* '<S141>/LIB_TPD_10ms7' */
MONPRM volatile boolean WinCtl_DrvWinAutoDnReq = false;/* '<S143>/Chart10' */
MONPRM volatile boolean WinCtl_DrvWinAutoDnSw = false;/* '<S141>/LIB_TPD_10ms2' */
MONPRM volatile boolean WinCtl_DrvWinDnProt = false;/* '<S142>/LIB_CntLimit1' */
MONPRM volatile boolean WinCtl_DrvWinDnReq = false;/* '<S143>/Chart2' */
MONPRM volatile boolean WinCtl_DrvWinDnSw = false;/* '<S141>/LIB_TPD_10ms1' */
MONPRM volatile boolean WinCtl_DrvWinMotorLocked = false;/* '<S143>/LIB_TPD_10ms3' */
MONPRM volatile uint8 WinCtl_DrvWinReq = ((uint8)0U);/* '<S143>/Switch11' */
MONPRM volatile uint8 WinCtl_DrvWinSta = ((uint8)0U);/* '<S10>/DrvWinCtl' */
MONPRM volatile boolean WinCtl_DrvWinUpProt = false;/* '<S142>/LIB_CntLimit' */
MONPRM volatile boolean WinCtl_DrvWinUpReq = false;/* '<S143>/Chart3' */
MONPRM volatile boolean WinCtl_DrvWinUpSw = false;/* '<S141>/LIB_TPD_10ms3' */
MONPRM volatile boolean WinCtl_J51DrvWinUp = false;/* '<S136>/Switch1' */
MONPRM volatile boolean WinCtl_J53DrvWinDn = false;/* '<S139>/Switch1' */
MONPRM volatile boolean WinCtl_J55PsgWinUp = false;/* '<S137>/Switch' */
MONPRM volatile boolean WinCtl_J57PsgWinDn = false;/* '<S138>/Switch' */
MONPRM volatile boolean WinCtl_PsgWinAutoDnReq = false;/* '<S143>/Chart1' */
MONPRM volatile boolean WinCtl_PsgWinAutoDnSw = false;/* '<S141>/LIB_TPD_10ms6' */
MONPRM volatile boolean WinCtl_PsgWinDnProt = false;/* '<S142>/LIB_CntLimit3' */
MONPRM volatile boolean WinCtl_PsgWinDnReq = false;/* '<S143>/Chart4' */
MONPRM volatile boolean WinCtl_PsgWinDnSw = false;/* '<S141>/LIB_TPD_10ms5' */
MONPRM volatile boolean WinCtl_PsgWinMotorLocked = false;/* '<S143>/LIB_TPD_10ms1' */
MONPRM volatile uint8 WinCtl_PsgWinReq = ((uint8)0U);/* '<S143>/Switch10' */
MONPRM volatile uint8 WinCtl_PsgWinSta = ((uint8)0U);/* '<S10>/PsgWinCtl' */
MONPRM volatile boolean WinCtl_PsgWinUpProt = false;/* '<S142>/LIB_CntLimit2' */
MONPRM volatile boolean WinCtl_PsgWinUpReq = false;/* '<S143>/Chart5' */
MONPRM volatile boolean WinCtl_PsgWinUpSw = false;/* '<S141>/LIB_TPD_10ms4' */
MONPRM volatile boolean WiperCtl_HiSpdDrv = false;/* '<S568>/Switch1' */
MONPRM volatile uint16 WiperCtl_InrTim = ((uint16)0U);/* '<S574>/Multiport Switch' */
MONPRM volatile boolean WiperCtl_InrTimChg = false;/* '<S574>/Relational Operator1' */
MONPRM volatile boolean WiperCtl_LockedRotorProtSta = false;/* '<S566>/Logical Operator2' */
MONPRM volatile boolean WiperCtl_LowSpdDrv = false;/* '<S567>/Switch1' */
MONPRM volatile boolean WiperCtl_WashMotorDrv = false;/* '<S569>/Switch1' */
MONPRM volatile boolean WiperCtl_WashSw = false;/* '<S570>/LIB_TPD_10ms5' */
MONPRM volatile boolean WiperCtl_WashWiperSta = false;/* '<S571>/LIB_TPD_10ms6' */
MONPRM volatile boolean WiperCtl_WiperHiSpdSta = false;/* '<S573>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperHiSpdSw = false;/* '<S570>/LIB_TPD_10ms4' */
MONPRM volatile boolean WiperCtl_WiperInrSta = false;/* '<S574>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperInrSw = false;/* '<S570>/LIB_TPD_10ms2' */
MONPRM volatile boolean WiperCtl_WiperLowSpdSta = false;/* '<S575>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperLowSpdSw = false;/* '<S570>/LIB_TPD_10ms3' */
MONPRM volatile boolean WiperCtl_WiperMaintSta = false;/* '<S613>/Switch' */
MONPRM volatile boolean WiperCtl_WiperMistSta = false;/* '<S577>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperMistSw = false;/* '<S570>/LIB_TPD_10ms' */
MONPRM volatile boolean WiperCtl_WiperOffSta = false;/* '<S578>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperOffSw = false;/* '<S570>/LIB_TPD_10ms1' */
MONPRM volatile boolean WiperCtl_WiperParkPosSw = false;/* '<S570>/LIB_TPD_10ms6' */
MONPRM volatile uint8 WiperCtl_WiperSta = ((uint8)0U);/* '<S572>/Chart' */
MONPRM volatile uint8 WiperCtl_WiprIntlTimeSetFb = ((uint8)0U);/* '<S574>/Multiport Switch1' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
