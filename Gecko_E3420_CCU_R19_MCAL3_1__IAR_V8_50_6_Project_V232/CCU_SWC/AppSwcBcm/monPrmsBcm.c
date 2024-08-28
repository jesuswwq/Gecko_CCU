/*
 * File: monPrmsBcm.c
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1254
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Aug 23 17:11:12 2024
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
MONPRM volatile boolean AlmSysCtl_AlrmWarnTimOut = false;/* '<S598>/AlmSysLogic' */
MONPRM volatile uint8 AlmSysCtl_BodyWarnSts = ((uint8)0U);/* '<S598>/AlmSysLogic' */
MONPRM volatile uint16 BSW_CN744DrvSeatResis = ((uint16)0U);/* '<S1>/C Caller14' */
MONPRM volatile uint16 BSW_DrvWinMotorCur = ((uint16)0U);/* '<S1>/C Caller25' */
MONPRM volatile uint8 BSW_EEIlluminatedEntrySys = ((uint8)0U);/* '<S4>/C Caller37' */
MONPRM volatile uint8 BSW_EEKeyEntry = ((uint8)0U);/* '<S4>/C Caller38' */
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
MONPRM volatile uint16 BSW_PsgWinMotorCur = ((uint16)0U);/* '<S1>/C Caller29' */
MONPRM volatile uint8 BSW_RKEReq = ((uint8)0U);/* '<S3>/C Caller32' */
MONPRM volatile uint8 BSW_WakeupReas = ((uint8)0U);/* '<S605>/Signal Conversion' */
MONPRM volatile boolean BatSaveCtl_DoorChgSta = false;/* '<S626>/Logical Operator1' */
MONPRM volatile boolean BatSaveCtl_DoorLckPwrOff = false;/* '<S625>/LIB_NegPluse6' */
MONPRM volatile boolean BatSaveCtl_DoorUnlckPwrOn = false;/* '<S635>/Logical Operator' */
MONPRM volatile boolean BatSaveCtl_J64SavePwr = false;/* '<S624>/Switch1' */
MONPRM volatile boolean BatSaveCtl_PwrModeOff = false;/* '<S625>/LIB_PosPluse' */
MONPRM volatile boolean BatSaveCtl_PwrModeOn = false;/* '<S626>/Relational Operator' */
MONPRM volatile boolean BatSaveCtl_PwrOff = false;/* '<S625>/Logical Operator' */
MONPRM volatile boolean BatSaveCtl_PwrOn = false;/* '<S626>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_AutoLck = false;/* '<S698>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_AutoLckSta = false;/* '<S699>/Switch' */
MONPRM volatile boolean DoorLckCtl_CrshUnlck = false;/* '<S672>/Chart' */
MONPRM volatile boolean DoorLckCtl_DoorAjarFLSw = true;/* '<S641>/LIB_TPD_10ms1' */
MONPRM volatile boolean DoorLckCtl_DoorAjarFRSw = true;/* '<S641>/LIB_TPD_10ms2' */
MONPRM volatile boolean DoorLckCtl_DoorAjarRLSw = true;/* '<S641>/LIB_TPD_10ms6' */
MONPRM volatile boolean DoorLckCtl_DoorAjarRRSw = true;/* '<S641>/LIB_TPD_10ms7' */
MONPRM volatile boolean DoorLckCtl_DoorProtUnlck = false;/* '<S644>/LIB_Tim' */
MONPRM volatile boolean DoorLckCtl_DriverDoorLckSw = true;/* '<S641>/LIB_TPD_10ms' */
MONPRM volatile boolean DoorLckCtl_DrvPESw = false;/* '<S641>/LIB_TPD_10ms3' */
MONPRM volatile boolean DoorLckCtl_DrvSeatSw = false;/* '<S641>/LIB_TPD_10ms11' */
MONPRM volatile uint8 DoorLckCtl_EEIlluminatedEntrySys = ((uint8)0U);/* '<S641>/Switch14' */
MONPRM volatile uint8 DoorLckCtl_EEKeyEntry = ((uint8)0U);/* '<S641>/Switch13' */
MONPRM volatile boolean DoorLckCtl_HULck = false;/* '<S659>/Logical Operator2' */
MONPRM volatile boolean DoorLckCtl_HUUnLck = false;/* '<S673>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_HoodAjarSw = true;/* '<S641>/Constant69' */
MONPRM volatile uint8 DoorLckCtl_IllmndLckSts = ((uint8)0U);/* '<S646>/Multiport Switch' */
MONPRM volatile uint8 DoorLckCtl_IllmndLckStsFb = ((uint8)0U);/* '<S646>/Multiport Switch1' */
MONPRM volatile uint8 DoorLckCtl_IllmndSts = ((uint8)0U);/* '<S641>/Switch15' */
MONPRM volatile uint8 DoorLckCtl_IllmndUnlockSts = ((uint8)0U);/* '<S647>/Multiport Switch' */
MONPRM volatile uint8 DoorLckCtl_IllmndUnlockStsFb = ((uint8)0U);/* '<S647>/Multiport Switch1' */
MONPRM volatile boolean DoorLckCtl_InsLck = false;/* '<S648>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_InsLckSta = ((uint8)0U);/* '<S601>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_InsUnlck = false;/* '<S649>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_J511TrunkUnlck = false;/* '<S639>/Switch1' */
MONPRM volatile boolean DoorLckCtl_J54DoorLck = false;/* '<S638>/Switch1' */
MONPRM volatile boolean DoorLckCtl_J56DoorUnlck = false;/* '<S640>/Switch1' */
MONPRM volatile boolean DoorLckCtl_MechAntiLck = false;/* '<S644>/Logical Operator3' */
MONPRM volatile boolean DoorLckCtl_MechLck = false;/* '<S691>/Logical Operator3' */
MONPRM volatile boolean DoorLckCtl_MechUnlck = false;/* '<S713>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_MotorProt = false;/* '<S650>/Switch' */
MONPRM volatile boolean DoorLckCtl_OsLck = false;/* '<S651>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_OsLckSta = ((uint8)0U);/* '<S601>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_OsUnlck = false;/* '<S652>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_PELck = false;/* '<S692>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_PEUnlck = false;/* '<S714>/Logical Operator1' */
MONPRM volatile uint8 DoorLckCtl_ParkAutoUnlockSetFb = ((uint8)0U);/* '<S654>/Multiport Switch' */
MONPRM volatile boolean DoorLckCtl_ParkUnlck = false;/* '<S674>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_PsgPESw = false;/* '<S641>/LIB_TPD_10ms4' */
MONPRM volatile boolean DoorLckCtl_RKEAntiLck = false;/* '<S644>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_RKELck = false;/* '<S705>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_RKEUnlck = false;/* '<S721>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSet = ((uint8)1U);/* '<S655>/Constant8' */
MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSetFb = ((uint8)0U);/* '<S655>/Constant9' */
MONPRM volatile boolean DoorLckCtl_SpdLck = false;/* '<S665>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_ThermRunawayUnlck = false;/* '<S675>/Chart' */
MONPRM volatile boolean DoorLckCtl_TrunkAjarSw = true;/* '<S641>/LIB_TPD_10ms8' */
MONPRM volatile boolean DoorLckCtl_TrunkAutoLck = false;/* '<S709>/Logical Operator' */
MONPRM volatile uint8 DoorLckCtl_TrunkLckSta = ((uint8)0U);/* '<S601>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_TrunkLckSw = true;/* '<S601>/DoorDrv' */
MONPRM volatile boolean DoorLckCtl_TrunkRKEUnlck = false;/* '<S725>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_TrunkSw = false;/* '<S641>/LIB_TPD_10ms5' */
MONPRM volatile boolean DoorLckCtl_TrunkUnlck = false;/* '<S716>/Logical Operator' */
MONPRM volatile boolean DoorLckCtl_VehRun = false;/* '<S641>/Logical Operator4' */
MONPRM volatile float32 DoorLckCtl_VehSpd = 0.0F;/* '<S641>/Switch' */
MONPRM volatile boolean DoorLckCtl_VehStop = false;/* '<S641>/Logical Operator1' */
MONPRM volatile boolean DoorLckCtl_WelcomeLck = false;/* '<S695>/Logical Operator2' */
MONPRM volatile boolean DoorLckCtl_WelcomeUnlck = false;/* '<S717>/Logical Operator1' */
MONPRM volatile uint8 EEReadCtl_BackLadjvalFb = ((uint8)0U);/* '<S218>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_BodyWarnSts = ((uint8)0U);/* '<S218>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_CrashSta = ((uint8)0U);/* '<S218>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_FlwrMeHomeCtlFb = ((uint8)0U);/* '<S218>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_HazardLightSta = ((uint8)0U);/* '<S218>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_IllmndLckSts = ((uint8)0U);/* '<S218>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_IllmndUnlckSts = ((uint8)0U);/* '<S218>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_InrTim = ((uint8)0U);/* '<S218>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_LockHoornOnSts = ((uint8)0U);/* '<S218>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_ParkAutoUnlockSetFb = ((uint8)0U);/* '<S218>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_SpdCtlLckSet = ((uint8)0U);/* '<S218>/EEReadCtl' */
MONPRM volatile uint8 EEReadCtl_WiprIntlTimeSetFb = ((uint8)0U);/* '<S218>/EEReadCtl' */
MONPRM volatile boolean ESCLCtl_J436Lck = false;/* '<S768>/ESCLLck' */
MONPRM volatile boolean ESCLCtl_J436PwrSup = false;/* '<S773>/Switch' */
MONPRM volatile boolean ESCLCtl_J436Unlck = false;/* '<S768>/ESCLUnlck' */
MONPRM volatile uint8 ESCLCtl_Lck = ((uint8)0U);/* '<S768>/ESCLLck' */
MONPRM volatile uint8 ESCLCtl_UnOrLockCrtl = ((uint8)0U);/* '<S768>/Truth Table' */
MONPRM volatile uint8 ESCLCtl_Unlck = ((uint8)0U);/* '<S768>/ESCLUnlck' */
MONPRM volatile uint8 HornCtl_AlarmSta = ((uint8)0U);/* '<S262>/Alarm' */
MONPRM volatile uint8 HornCtl_AntiLckSta = ((uint8)0U);/* '<S263>/AntiLck' */
MONPRM volatile uint8 HornCtl_ArmedSta = ((uint8)0U);/* '<S264>/Armed' */
MONPRM volatile boolean HornCtl_HornSwCtl = false;/* '<S266>/LIB_TPD_10ms' */
MONPRM volatile boolean HornCtl_J430HornDrv = false;/* '<S268>/Switch1' */
MONPRM volatile uint8 HornCtl_LockHoornOnSt = ((uint8)0U);/* '<S265>/Multiport Switch' */
MONPRM volatile uint8 HornCtl_LockHoornOnStFb = ((uint8)0U);/* '<S265>/Multiport Switch1' */
MONPRM volatile uint8 HornCtl_PartArmedSta = ((uint8)0U);/* '<S269>/PartArmed' */
MONPRM volatile uint8 HornCtl_SeekSta = ((uint8)0U);/* '<S270>/Seek' */
MONPRM volatile uint8 HornCtl_TrunkWarnSta = ((uint8)0U);/* '<S271>/Chart' */
MONPRM volatile uint8 IMMOCtl_AuthResp[8] = { ((uint8)255U), ((uint8)255U),
  ((uint8)255U), ((uint8)255U), ((uint8)255U), ((uint8)255U), ((uint8)255U),
  ((uint8)255U) };                     /* '<S603>/IMMOCtl' */

MONPRM volatile uint8 IMMOCtl_INVRandom[8] = { ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U) };/* '<S603>/Signal Conversion' */

MONPRM volatile uint8 IMMOCtl_SKRead[16] = { ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)0U), ((uint8)
  0U), ((uint8)0U) };                  /* '<S603>/IMMOCtl' */

MONPRM volatile uint8 IMMOCtl_SKSta = ((uint8)0U);/* '<S603>/IMMOCtl' */
MONPRM volatile uint8 IODID_BSDLeftCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND44' */
MONPRM volatile uint8 IODID_BSDRightCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND43' */
MONPRM volatile uint8 IODID_BackLampCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND2' */
MONPRM volatile uint8 IODID_BatSaveCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND42' */
MONPRM volatile uint8 IODID_BrakeLightCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND3' */
MONPRM volatile uint8 IODID_DayRunLightCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND6' */
MONPRM volatile uint8 IODID_DomeLampCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND9' */
MONPRM volatile uint8 IODID_DoorLckCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND17' */
MONPRM volatile uint8 IODID_DoorUnlckCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND16' */
MONPRM volatile uint8 IODID_FogLampFCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND14' */
MONPRM volatile uint8 IODID_FogLampRCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND15' */
MONPRM volatile uint8 IODID_HiBeamCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND13' */
MONPRM volatile uint8 IODID_HornCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND40' */
MONPRM volatile uint8 IODID_IG1RlyCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND46' */
MONPRM volatile uint8 IODID_IG2RlyCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND47' */
MONPRM volatile uint8 IODID_LowBeamCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND12' */
MONPRM volatile uint8 IODID_PosLampCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND7' */
MONPRM volatile uint8 IODID_ReverseLampCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND5' */
MONPRM volatile uint8 IODID_TrunkUnlckCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND22' */
MONPRM volatile uint8 IODID_TurnIndcrLCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND' */
MONPRM volatile uint8 IODID_TurnIndcrRCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND1' */
MONPRM volatile uint8 IODID_WinFLCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND32' */
MONPRM volatile uint8 IODID_WinFRCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND33' */
MONPRM volatile uint8 IODID_WiperHiSpdCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND30' */
MONPRM volatile uint8 IODID_WiperLowSpdCtlFlg = ((uint8)0U);/* '<S5>/Bitwise AND31' */
MONPRM volatile boolean LampCtl_AlrmSta = false;/* '<S419>/Chart' */
MONPRM volatile boolean LampCtl_AntiLckSta = false;/* '<S420>/Chart' */
MONPRM volatile boolean LampCtl_ArmedSta = false;/* '<S421>/Chart' */
MONPRM volatile boolean LampCtl_AutoLampSta = false;/* '<S341>/Switch' */
MONPRM volatile boolean LampCtl_AutoLampSw = false;/* '<S327>/LIB_TPD_10ms8' */
MONPRM volatile uint8 LampCtl_BackLadjvalFb = ((uint8)0U);/* '<S298>/Multiport Switch' */
MONPRM volatile boolean LampCtl_BrakeLightSta = false;/* '<S316>/Switch1' */
MONPRM volatile boolean LampCtl_BrakeLightSw = false;/* '<S327>/Logical Operator13' */
MONPRM volatile boolean LampCtl_CrashSta = false;/* '<S422>/Chart' */
MONPRM volatile boolean LampCtl_DayRunLightSta = false;/* '<S310>/Switch1' */
MONPRM volatile boolean LampCtl_DisarmedSta = false;/* '<S423>/Chart' */
MONPRM volatile boolean LampCtl_DomeLampCloseDoor = false;/* '<S353>/Logical Operator6' */
MONPRM volatile boolean LampCtl_DomeLampCtl = false;/* '<S354>/Switch' */
MONPRM volatile boolean LampCtl_DomeLampFLOpen = false;/* '<S356>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampFROpen = false;/* '<S357>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampLockDoor = false;/* '<S353>/Relational Operator4' */
MONPRM volatile boolean LampCtl_DomeLampOff = true;/* '<S302>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOffGrad = false;/* '<S302>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOn = false;/* '<S302>/Truth Table' */
MONPRM volatile boolean LampCtl_DomeLampOnGrad = false;/* '<S302>/Truth Table' */
MONPRM volatile uint8 LampCtl_DomeLampPwmDuty = ((uint8)0U);/* '<S311>/Switch1' */
MONPRM volatile boolean LampCtl_DomeLampPwrOff = false;/* '<S360>/LIB_Tim' */
MONPRM volatile boolean LampCtl_DomeLampUnlock = false;/* '<S361>/LIB_Tim' */
MONPRM volatile boolean LampCtl_EmerHazardLightSta = false;/* '<S328>/HazardLightLogic' */
MONPRM volatile boolean LampCtl_EmerSta = false;/* '<S424>/Logical Operator' */
MONPRM volatile uint8 LampCtl_FlwrMeHomeCtlFb = ((uint8)0U);/* '<S526>/Multiport Switch1' */
MONPRM volatile boolean LampCtl_FlwrMeHomeSta = false;/* '<S528>/Switch' */
MONPRM volatile uint16 LampCtl_FlwrMeHomeTim = ((uint16)0U);/* '<S526>/Multiport Switch' */
MONPRM volatile boolean LampCtl_FogLampFSta = false;/* '<S321>/Switch1' */
MONPRM volatile boolean LampCtl_FogLampFSw = false;/* '<S327>/LIB_TPD_10ms12' */
MONPRM volatile boolean LampCtl_FogLampRSta = false;/* '<S320>/Switch1' */
MONPRM volatile boolean LampCtl_FogLampRSw = false;/* '<S327>/LIB_TPD_10ms9' */
MONPRM volatile boolean LampCtl_HazardLightSta = false;/* '<S328>/HazardLightLogic' */
MONPRM volatile boolean LampCtl_HazardLightSw = false;/* '<S327>/LIB_TPD_10ms10' */
MONPRM volatile boolean LampCtl_HiBeamSta = false;/* '<S323>/Switch1' */
MONPRM volatile boolean LampCtl_HiBeamSw = false;/* '<S327>/LIB_TPD_10ms2' */
MONPRM volatile uint8 LampCtl_J408BackLampPWM = ((uint8)0U);/* '<S315>/Switch1' */
MONPRM volatile boolean LampCtl_J420BSDRightCtl = false;/* '<S317>/Switch1' */
MONPRM volatile boolean LampCtl_J422BSDLeftCtl = false;/* '<S318>/Switch1' */
MONPRM volatile boolean LampCtl_J449BoxLamp = false;/* '<S314>/Switch1' */
MONPRM volatile boolean LampCtl_KnobBeamFaultSta = false;/* '<S305>/LIB_TPD_10ms' */
MONPRM volatile boolean LampCtl_LampDelay = false;/* '<S376>/Switch' */
MONPRM volatile uint8 LampCtl_LightIntstSta = ((uint8)0U);/* '<S307>/Chart' */
MONPRM volatile uint16 LampCtl_LightIntstVal = ((uint16)0U);/* '<S327>/Data Type Conversion12' */
MONPRM volatile boolean LampCtl_LowBeamSta = false;/* '<S319>/Switch1' */
MONPRM volatile boolean LampCtl_LowBeamSw = false;/* '<S327>/LIB_TPD_10ms1' */
MONPRM volatile boolean LampCtl_PartArmedSta = false;/* '<S426>/Chart' */
MONPRM volatile boolean LampCtl_PassLightSta = false;/* '<S324>/LIB_Tim' */
MONPRM volatile boolean LampCtl_PassLightSw = false;/* '<S327>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_PosLampSta = false;/* '<S309>/Switch1' */
MONPRM volatile boolean LampCtl_PosLampSw = false;/* '<S327>/LIB_TPD_10ms' */
MONPRM volatile uint16 LampCtl_PrdSucCntL = ((uint16)0U);/* '<S433>/LIB_Pulse' */
MONPRM volatile uint16 LampCtl_PrdSucCntR = ((uint16)0U);/* '<S435>/LIB_Pulse' */
MONPRM volatile uint8 LampCtl_RKEReq = ((uint8)0U);/* '<S327>/Multiport Switch' */
MONPRM volatile boolean LampCtl_ReverseLampSta = false;/* '<S322>/Switch1' */
MONPRM volatile boolean LampCtl_RodBeamFaultSta = false;/* '<S428>/LIB_TPD_10ms' */
MONPRM volatile boolean LampCtl_ThermalrunawaySta = false;/* '<S429>/Chart' */
MONPRM volatile boolean LampCtl_TrunkWarnSta = false;/* '<S430>/Chart' */
MONPRM volatile uint16 LampCtl_TurnIndcrLFlashCnt = ((uint16)0U);/* '<S328>/TurnIndcrArb2' */
MONPRM volatile boolean LampCtl_TurnIndcrLOpen = false;/* '<S432>/LIB_TPD_10ms' */
MONPRM volatile boolean LampCtl_TurnIndcrLShort = false;/* '<S432>/LIB_TPD_10ms2' */
MONPRM volatile boolean LampCtl_TurnIndcrLSta = false;/* '<S313>/Switch1' */
MONPRM volatile boolean LampCtl_TurnIndcrLSw = false;/* '<S327>/LIB_TPD_10ms4' */
MONPRM volatile uint16 LampCtl_TurnIndcrLVol = ((uint16)0U);/* '<S432>/C Caller' */
MONPRM volatile boolean LampCtl_TurnIndcrLaneLSw = false;/* '<S327>/LIB_TPD_10ms5' */
MONPRM volatile boolean LampCtl_TurnIndcrLaneRSw = false;/* '<S327>/LIB_TPD_10ms7' */
MONPRM volatile uint8 LampCtl_TurnIndcrMod = ((uint8)0U);/* '<S328>/TurnIndcrLogic' */
MONPRM volatile uint16 LampCtl_TurnIndcrPrd = ((uint16)0U);/* '<S328>/TurnIndcrArb2' */
MONPRM volatile uint16 LampCtl_TurnIndcrRFlashCnt = ((uint16)0U);/* '<S328>/TurnIndcrArb2' */
MONPRM volatile boolean LampCtl_TurnIndcrROpen = false;/* '<S432>/LIB_TPD_10ms1' */
MONPRM volatile boolean LampCtl_TurnIndcrRShort = false;/* '<S432>/LIB_TPD_10ms3' */
MONPRM volatile boolean LampCtl_TurnIndcrRSta = false;/* '<S312>/Switch1' */
MONPRM volatile boolean LampCtl_TurnIndcrRSw = false;/* '<S327>/LIB_TPD_10ms6' */
MONPRM volatile uint16 LampCtl_TurnIndcrRVol = ((uint16)0U);/* '<S432>/C Caller1' */
MONPRM volatile boolean LampCtl_TurnIndcrRst = false;/* '<S328>/TurnIndcrArb2' */
MONPRM volatile uint16 LampCtl_TurnIndcrWdt = ((uint16)0U);/* '<S328>/TurnIndcrArb2' */
MONPRM volatile uint8 LampCtl_VehModeSta = ((uint8)0U);/* '<S437>/Chart' */
MONPRM volatile boolean LampCtl_VehSeekSta = false;/* '<S438>/Chart' */
MONPRM volatile boolean LampCtl_WelcomeLampSta = false;/* '<S527>/Switch' */
MONPRM volatile boolean PDUCtl_IG1RelayFault = false;/* '<S789>/LIB_TPD_10ms2' */
MONPRM volatile boolean PDUCtl_IG2RelayFault = false;/* '<S789>/LIB_TPD_10ms1' */
MONPRM volatile boolean PDUCtl_IGRlyIlgCls = false;/* '<S789>/LIB_TPD_10ms3' */
MONPRM volatile uint8 PDUCtl_J421IG1RlyCtl = ((uint8)0U);/* '<S785>/Switch1' */
MONPRM volatile uint8 PDUCtl_J437IG2RlyCtl = ((uint8)0U);/* '<S786>/Switch1' */
MONPRM volatile boolean PDUCtl_PwrOff = false;/* '<S787>/Logical Operator6' */
MONPRM volatile boolean PDUCtl_PwrOn = false;/* '<S788>/Logical Operator2' */
MONPRM volatile boolean PDUCtl_StartReq = false;/* '<S815>/Switch' */
MONPRM volatile uint8 PDUCtl_SysPowerSts = ((uint8)0U);/* '<S604>/Chart' */
MONPRM volatile uint8 PDUCtl_SysPwrMode = ((uint8)0U);/* '<S604>/Truth Table' */
MONPRM volatile uint8 PDUCtl_SysPwrModeAct = ((uint8)0U);/* '<S791>/Switch' */
MONPRM volatile boolean PDUCtl_SysPwrModeV = false;/* '<S789>/Switch' */
MONPRM volatile uint8 PEPSCtl_AvaluebleKeyInCar = ((uint8)0U);/* '<S195>/Chart3' */
MONPRM volatile uint8 PEPSCtl_DrvPEAuthentAcsd = ((uint8)0U);/* '<S195>/Chart' */
MONPRM volatile uint8 PEPSCtl_FRPEAuthentAcsd = ((uint8)0U);/* '<S195>/Chart' */
MONPRM volatile uint8 PEPSCtl_FrbdnKeyNr = ((uint8)0U);/* '<S193>/Chart' */
MONPRM volatile uint8 PEPSCtl_IMMOKey = ((uint8)0U);/* '<S196>/Chart5' */
MONPRM volatile uint8 PEPSCtl_IndicationKeyCloser = ((uint8)0U);/* '<S196>/Chart3' */
MONPRM volatile uint8 PEPSCtl_KeyInCarSta = ((uint8)0U);/* '<S195>/Chart' */
MONPRM volatile uint8 PEPSCtl_KeyLoBattLvlWarn = ((uint8)0U);/* '<S194>/Chart3' */
MONPRM volatile uint8 PEPSCtl_KeySta = ((uint8)0U);/* '<S196>/Chart1' */
MONPRM volatile uint8 PEPSCtl_LckWlcmReq = ((uint8)0U);/* '<S197>/Chart' */
MONPRM volatile uint8 PEPSCtl_PSAuthentRes = ((uint8)0U);/* '<S196>/Chart' */
MONPRM volatile uint8 PEPSCtl_PSReq = ((uint8)0U);/* '<S196>/Chart' */
MONPRM volatile uint8 PEPSCtl_UnlckWlcmReq = ((uint8)0U);/* '<S197>/Chart' */
MONPRM volatile uint8 PEPSCtl_WarnKeyOutReminder = ((uint8)0U);/* '<S194>/Chart' */
MONPRM volatile uint8 PEPSCtl_WarnNoKeyFound = ((uint8)0U);/* '<S196>/Chart2' */
MONPRM volatile boolean RVMCtl_J42Heat = false;/* '<S122>/Switch' */
MONPRM volatile uint8 SCS_FrntWiprSwtSt = ((uint8)0U);/* '<S222>/Signal Conversion' */
MONPRM volatile boolean SCS_FrntWshrSwtSt = false;/* '<S222>/Signal Conversion1' */
MONPRM volatile boolean SCS_FrntWshrSwtStVD = false;/* '<S222>/Signal Conversion2' */
MONPRM volatile boolean SCS_WiprSwtStVD = false;/* '<S222>/Signal Conversion3' */
MONPRM volatile uint8 SeatCtl_CN167DrvSeatHtPWM = ((uint8)0U);/* '<S129>/Switch' */
MONPRM volatile sint8 SeatCtl_DrvSeatTemp = 0;/* '<S127>/Data Type Conversion' */
MONPRM volatile uint8 SeatCtl_MaiDrvSeatStFb = ((uint8)0U);/* '<S127>/Multiport Switch' */
MONPRM volatile boolean SteerWhlCtl_J447SteerWhlHt = false;/* '<S132>/Switch' */
MONPRM volatile uint8 SteerWhlCtl_SteerWhlHeatSts = ((uint8)0U);/* '<S130>/Multiport Switch' */
MONPRM volatile sint8 SteerWhlCtl_SteerWhlTemp = 0;/* '<S130>/Data Type Conversion' */
MONPRM volatile boolean WakeUpCtl_NMReq = false;/* '<S829>/Switch' */
MONPRM volatile boolean WakeUpCtl_SleepAllwd = false;/* '<S818>/Logical Operator5' */
MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnSw = false;/* '<S139>/LIB_TPD_10ms9' */
MONPRM volatile boolean WinCtl_DrvPsgWinDnSw = false;/* '<S139>/LIB_TPD_10ms8' */
MONPRM volatile boolean WinCtl_DrvPsgWinUpSw = false;/* '<S139>/LIB_TPD_10ms7' */
MONPRM volatile boolean WinCtl_DrvWinAutoDnReq = false;/* '<S141>/Chart' */
MONPRM volatile boolean WinCtl_DrvWinAutoDnSw = false;/* '<S139>/LIB_TPD_10ms2' */
MONPRM volatile boolean WinCtl_DrvWinDnProt = false;/* '<S140>/LIB_CntLimit1' */
MONPRM volatile boolean WinCtl_DrvWinDnReq = false;/* '<S141>/Chart2' */
MONPRM volatile boolean WinCtl_DrvWinDnSw = false;/* '<S139>/LIB_TPD_10ms1' */
MONPRM volatile uint8 WinCtl_DrvWinReq = ((uint8)0U);/* '<S141>/Switch11' */
MONPRM volatile uint8 WinCtl_DrvWinSta = ((uint8)0U);/* '<S9>/DrvWinCtl' */
MONPRM volatile boolean WinCtl_DrvWinUpProt = false;/* '<S140>/LIB_CntLimit' */
MONPRM volatile boolean WinCtl_DrvWinUpReq = false;/* '<S141>/Chart3' */
MONPRM volatile boolean WinCtl_DrvWinUpSw = false;/* '<S139>/LIB_TPD_10ms3' */
MONPRM volatile boolean WinCtl_J51DrvWinUp = false;/* '<S134>/Switch1' */
MONPRM volatile boolean WinCtl_J53DrvWinDn = false;/* '<S137>/Switch1' */
MONPRM volatile boolean WinCtl_J55PsgWinUp = false;/* '<S135>/Switch' */
MONPRM volatile boolean WinCtl_J57PsgWinDn = false;/* '<S136>/Switch' */
MONPRM volatile boolean WinCtl_PsgWinAutoDnReq = false;/* '<S141>/Chart1' */
MONPRM volatile boolean WinCtl_PsgWinAutoDnSw = false;/* '<S139>/LIB_TPD_10ms6' */
MONPRM volatile boolean WinCtl_PsgWinDnProt = false;/* '<S140>/LIB_CntLimit3' */
MONPRM volatile boolean WinCtl_PsgWinDnReq = false;/* '<S141>/Chart4' */
MONPRM volatile boolean WinCtl_PsgWinDnSw = false;/* '<S139>/LIB_TPD_10ms5' */
MONPRM volatile uint8 WinCtl_PsgWinReq = ((uint8)0U);/* '<S141>/Switch10' */
MONPRM volatile uint8 WinCtl_PsgWinSta = ((uint8)0U);/* '<S9>/PsgWinCtl' */
MONPRM volatile boolean WinCtl_PsgWinUpProt = false;/* '<S140>/LIB_CntLimit2' */
MONPRM volatile boolean WinCtl_PsgWinUpReq = false;/* '<S141>/Chart5' */
MONPRM volatile boolean WinCtl_PsgWinUpSw = false;/* '<S139>/LIB_TPD_10ms4' */
MONPRM volatile boolean WinCtl_WinDnRKEReq = false;/* '<S141>/Logical Operator9' */
MONPRM volatile boolean WinCtl_WinUpRKEReq = false;/* '<S141>/Logical Operator3' */
MONPRM volatile boolean WiperCtl_HiSpdDrv = false;/* '<S547>/Switch1' */
MONPRM volatile uint16 WiperCtl_InrTim = ((uint16)0U);/* '<S553>/Multiport Switch' */
MONPRM volatile boolean WiperCtl_InrTimChg = false;/* '<S553>/Relational Operator1' */
MONPRM volatile boolean WiperCtl_LockedRotorProtSta = false;/* '<S545>/Logical Operator2' */
MONPRM volatile boolean WiperCtl_LowSpdDrv = false;/* '<S546>/Switch1' */
MONPRM volatile boolean WiperCtl_WashMotorDrv = false;/* '<S548>/Switch1' */
MONPRM volatile boolean WiperCtl_WashSw = false;/* '<S549>/LIB_TPD_10ms5' */
MONPRM volatile boolean WiperCtl_WashWiperSta = false;/* '<S550>/LIB_TPD_10ms6' */
MONPRM volatile boolean WiperCtl_WiperHiSpdSta = false;/* '<S552>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperHiSpdSw = false;/* '<S549>/LIB_TPD_10ms4' */
MONPRM volatile boolean WiperCtl_WiperInrSta = false;/* '<S553>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperInrSw = false;/* '<S549>/LIB_TPD_10ms2' */
MONPRM volatile boolean WiperCtl_WiperLowSpdSta = false;/* '<S554>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperLowSpdSw = false;/* '<S549>/LIB_TPD_10ms3' */
MONPRM volatile boolean WiperCtl_WiperMaintSta = false;/* '<S592>/Switch' */
MONPRM volatile boolean WiperCtl_WiperMistSta = false;/* '<S556>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperMistSw = false;/* '<S549>/LIB_TPD_10ms' */
MONPRM volatile boolean WiperCtl_WiperOffSta = false;/* '<S557>/Logical Operator' */
MONPRM volatile boolean WiperCtl_WiperOffSw = false;/* '<S549>/LIB_TPD_10ms1' */
MONPRM volatile boolean WiperCtl_WiperParkPosSw = false;/* '<S549>/LIB_TPD_10ms6' */
MONPRM volatile uint8 WiperCtl_WiperSta = ((uint8)0U);/* '<S551>/Chart' */
MONPRM volatile uint8 WiperCtl_WiprIntlTimeSetFb = ((uint8)0U);/* '<S553>/Multiport Switch1' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
