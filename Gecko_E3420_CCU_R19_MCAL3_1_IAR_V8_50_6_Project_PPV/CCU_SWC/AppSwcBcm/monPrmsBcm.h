/*
 * File: monPrmsBcm.h
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

#ifndef RTW_HEADER_monPrmsBcm_h_
#define RTW_HEADER_monPrmsBcm_h_
#include "rtwtypes.h"
#include "AppSwcBcm_types.h"

/* Exported data declaration */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Declaration for custom storage class: Volatile */
extern MONPRM volatile boolean AlmSysCtl_AlrmWarnTimOut;/* '<S637>/AlmSysLogic' */
extern MONPRM volatile uint8 AlmSysCtl_BodyWarnSts;/* '<S637>/AlmSysLogic' */
extern MONPRM volatile uint16 BSW_CN744DrvSeatResis;/* '<S1>/C Caller14' */
extern MONPRM volatile uint8 BSW_CrashPWMSta;/* '<S3>/C Caller15' */
extern MONPRM volatile uint16 BSW_DrvWinMotorCur;/* '<S1>/C Caller25' */
extern MONPRM volatile uint8 BSW_EEIlluminatedEntrySys;/* '<S4>/C Caller37' */
extern MONPRM volatile uint8 BSW_EEKeyEntry;/* '<S4>/C Caller38' */
extern MONPRM volatile uint8 BSW_FogLampFCfg;/* '<S3>/C Caller1' */
extern MONPRM volatile uint8 BSW_HiBeamDigSts;/* '<S327>/C Caller1' */
extern MONPRM volatile uint8 BSW_IllmndSts;/* '<S4>/Constant3' */
extern MONPRM volatile uint16 BSW_J112DrvSeatResis;/* '<S4>/C Caller16' */
extern MONPRM volatile uint16 BSW_J113DrvWinSwResis;/* '<S1>/C Caller26' */
extern MONPRM volatile uint16 BSW_J125LightIntst;/* '<S3>/C Caller30' */
extern MONPRM volatile uint16 BSW_J126DrvPsgWinSwResis;/* '<S1>/C Caller27' */
extern MONPRM volatile uint16 BSW_J134SteerWhlResis;/* '<S1>/C Caller34' */
extern MONPRM volatile uint16 BSW_J26PsgWinSwResis;/* '<S1>/C Caller28' */
extern MONPRM volatile uint8 BSW_J310DoorAjarFR;/* '<S4>/C Caller2' */
extern MONPRM volatile uint8 BSW_J313BrakeLoSw;/* '<S3>/C Caller4' */
extern MONPRM volatile uint8 BSW_J319HornSw;/* '<S3>/C Caller31' */
extern MONPRM volatile uint8 BSW_J320DoorAjarRL;/* '<S4>/C Caller17' */
extern MONPRM volatile uint8 BSW_J321DoorAjarFL;/* '<S4>/C Caller1' */
extern MONPRM volatile uint8 BSW_J322FogLampF;/* '<S3>/C Caller3' */
extern MONPRM volatile uint8 BSW_J334WiperParkPos;/* '<S3>/C Caller8' */
extern MONPRM volatile uint8 BSW_J335DriverDoorLck;/* '<S4>/C Caller' */
extern MONPRM volatile uint8 BSW_J336Trunk;/* '<S4>/C Caller18' */
extern MONPRM volatile uint8 BSW_J337PsgPE;/* '<S4>/C Caller6' */
extern MONPRM volatile uint8 BSW_J338DrvPE;/* '<S4>/C Caller5' */
extern MONPRM volatile uint8 BSW_J339BrakeHiSw;/* '<S3>/C Caller33' */
extern MONPRM volatile uint8 BSW_J346FogLampR;/* '<S3>/C Caller13' */
extern MONPRM volatile uint8 BSW_J349TrunkLck;/* '<S4>/C Caller19' */
extern MONPRM volatile uint8 BSW_J36DoorAjarRR;/* '<S4>/C Caller20' */
extern MONPRM volatile uint8 BSW_J37TrunkAjar;/* '<S4>/C Caller21' */
extern MONPRM volatile uint8 BSW_J38HoodAjar;/* '<S4>/C Caller22' */
extern MONPRM volatile uint8 BSW_LowBeamDigSts;/* '<S331>/C Caller' */
extern MONPRM volatile uint16 BSW_PsgWinMotorCur;/* '<S1>/C Caller29' */
extern MONPRM volatile uint8 BSW_RKEReq;/* '<S3>/C Caller32' */
extern MONPRM volatile uint8 BSW_WakeupReas;/* '<S645>/Signal Conversion' */
extern MONPRM volatile boolean BatSaveCtl_DoorChgSta;/* '<S666>/Logical Operator1' */
extern MONPRM volatile boolean BatSaveCtl_DoorLckPwrOff;/* '<S665>/LIB_PosPluse1' */
extern MONPRM volatile boolean BatSaveCtl_DoorUnlckPwrOn;/* '<S666>/Relational Operator1' */
extern MONPRM volatile boolean BatSaveCtl_J64SavePwr;/* '<S664>/Switch1' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOff;/* '<S665>/LIB_PosPluse' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOn;/* '<S666>/Relational Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOff;/* '<S665>/Logical Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOn;/* '<S666>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLck;/* '<S737>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLckSta;/* '<S738>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_CrshUnlck;/* '<S710>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFLSw;/* '<S678>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFRSw;/* '<S678>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRLSw;/* '<S678>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRRSw;/* '<S678>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean DoorLckCtl_DoorProtUnlck;/* '<S681>/LIB_Tim' */
extern MONPRM volatile boolean DoorLckCtl_DriverDoorLckSw;/* '<S678>/LIB_TPD_10ms' */
extern MONPRM volatile boolean DoorLckCtl_DrvPESw;/* '<S678>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean DoorLckCtl_DrvSeatSw;/* '<S678>/LIB_TPD_10ms11' */
extern MONPRM volatile uint8 DoorLckCtl_EEIlluminatedEntrySys;/* '<S678>/Switch14' */
extern MONPRM volatile uint8 DoorLckCtl_EEKeyEntry;/* '<S678>/Switch13' */
extern MONPRM volatile boolean DoorLckCtl_HULck;/* '<S697>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_HUUnLck;/* '<S711>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_HoodAjarSw;/* '<S678>/Constant69' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckSts;/* '<S683>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckStsFb;/* '<S683>/Multiport Switch1' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndSts;/* '<S678>/Switch15' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockSts;/* '<S684>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockStsFb;/* '<S684>/Multiport Switch1' */
extern MONPRM volatile boolean DoorLckCtl_InsLck;/* '<S685>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_InsLckSta;/* '<S640>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_InsUnlck;/* '<S686>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_J511TrunkUnlck;/* '<S676>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J54DoorLck;/* '<S675>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J56DoorUnlck;/* '<S677>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_MechAntiLck;/* '<S681>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechLck;/* '<S729>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechUnlck;/* '<S755>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_MotorProt;/* '<S687>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_OsLck;/* '<S688>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_OsLckSta;/* '<S640>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_OsUnlck;/* '<S689>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PELck;/* '<S730>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_PEUnlck;/* '<S756>/Logical Operator1' */
extern MONPRM volatile uint8 DoorLckCtl_ParkAutoUnlockSetFb;/* '<S691>/Multiport Switch' */
extern MONPRM volatile boolean DoorLckCtl_ParkUnlck;/* '<S712>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PsgPESw;/* '<S678>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean DoorLckCtl_RKEAntiLck;/* '<S681>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_RKELck;/* '<S744>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_RKEUnlck;/* '<S764>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_RemoteLockFb;/* '<S693>/Chart' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSet;/* '<S692>/Constant8' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSetFb;/* '<S692>/Constant9' */
extern MONPRM volatile boolean DoorLckCtl_SpdLck;/* '<S703>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TboxLck;/* '<S747>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TboxUnlck;/* '<S767>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_ThermRunawayUnlck;/* '<S713>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAjarSw;/* '<S678>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAutoLck;/* '<S750>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_TrunkLckSta;/* '<S640>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkLckSw;/* '<S640>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkRKEUnlck;/* '<S769>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TrunkSw;/* '<S678>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean DoorLckCtl_TrunkTboxUnlck;/* '<S771>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TrunkUnlck;/* '<S759>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_VehRun;/* '<S678>/Logical Operator4' */
extern MONPRM volatile float32 DoorLckCtl_VehSpd;/* '<S678>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_VehStop;/* '<S678>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeLck;/* '<S734>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeUnlck;/* '<S760>/Logical Operator1' */
extern MONPRM volatile uint8 DynDID_0xF22CAntitheftSta;/* '<S641>/Signal Conversion' */
extern MONPRM volatile uint8 DynDID_0xF230DoorOpRecord[10];/* '<S818>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF231TrunkOpRecord[10];/* '<S819>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF232LocalStartUpFailRecord[10];/* '<S820>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF233RemoteStartUpFailRecord[10];/* '<S821>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF234ADSampleValue[23];/* '<S822>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF235DigtInSampleValue[5];/* '<S823>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF236DigtOutSampleValue[5];/* '<S824>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF237PwrModeSta;/* '<S641>/Signal Conversion1' */
extern MONPRM volatile uint8 EEReadCtl_BackLadjvalFb;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_BodyWarnSts;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_CrashSta;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarFLSw;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarFRSw;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarRLSw;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarRRSw;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorOpRecord[10];/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DriverDoorLckSw;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DrvSeatSw;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_FlwrMeHomeCtlFb;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_HazardLightSta;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_IllmndLckSts;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_IllmndUnlckSts;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_InrTim;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_LocalStartFailOpRecord[10];/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_LockHoornOnSts;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_ParkAutoUnlockSetFb;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_RemotePwrLckSta;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_RemoteStartFailRecord[10];/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_SpdCtlLckSet;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkAjarSw;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkLckSw;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkOpRecord[10];/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkSw;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_WiprIntlTimeSetFb;/* '<S239>/EEReadCtl' */
extern MONPRM volatile uint64 ESCCtl_UnOrLockfeedback;/* '<S848>/Signal Copy' */
extern MONPRM volatile boolean ESCLCtl_J436Lck;/* '<S848>/ESCLLck' */
extern MONPRM volatile boolean ESCLCtl_J436PwrSup;/* '<S853>/Switch' */
extern MONPRM volatile boolean ESCLCtl_J436Unlck;/* '<S848>/ESCLUnlck' */
extern MONPRM volatile uint8 ESCLCtl_Lck;/* '<S848>/ESCLLck' */
extern MONPRM volatile uint8 ESCLCtl_UnOrLockCrtl;/* '<S848>/Truth Table' */
extern MONPRM volatile uint8 ESCLCtl_Unlck;/* '<S848>/ESCLUnlck' */
extern MONPRM volatile uint8 HornCtl_AlarmSta;/* '<S283>/Alarm' */
extern MONPRM volatile uint8 HornCtl_AntiLckSta;/* '<S284>/AntiLck' */
extern MONPRM volatile uint8 HornCtl_ArmedSta;/* '<S285>/Armed' */
extern MONPRM volatile boolean HornCtl_HornSwCtl;/* '<S287>/LIB_TPD_10ms' */
extern MONPRM volatile boolean HornCtl_J430HornDrv;/* '<S289>/Switch1' */
extern MONPRM volatile uint8 HornCtl_LockHoornOnSt;/* '<S286>/Multiport Switch' */
extern MONPRM volatile uint8 HornCtl_LockHoornOnStFb;/* '<S286>/Multiport Switch1' */
extern MONPRM volatile uint8 HornCtl_PartArmedSta;/* '<S290>/PartArmed' */
extern MONPRM volatile uint8 HornCtl_SeekSta;/* '<S291>/Seek' */
extern MONPRM volatile uint8 HornCtl_TrunkWarnSta;/* '<S292>/Chart' */
extern MONPRM volatile uint8 IMMOCtl_AuthResp[8];/* '<S643>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_INVRandom[8];/* '<S643>/Signal Conversion' */
extern MONPRM volatile uint8 IMMOCtl_SKRead[16];/* '<S643>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_SKSta;/* '<S643>/IMMOCtl' */
extern MONPRM volatile uint8 IODID_BSDLeftCtlFlg;/* '<S6>/Bitwise AND44' */
extern MONPRM volatile uint8 IODID_BSDRightCtlFlg;/* '<S6>/Bitwise AND43' */
extern MONPRM volatile uint8 IODID_BackLampCtlFlg;/* '<S6>/Bitwise AND2' */
extern MONPRM volatile uint8 IODID_BatSaveCtlFlg;/* '<S6>/Bitwise AND42' */
extern MONPRM volatile uint8 IODID_BrakeLightCtlFlg;/* '<S6>/Bitwise AND3' */
extern MONPRM volatile uint8 IODID_DayRunLightCtlFlg;/* '<S6>/Bitwise AND6' */
extern MONPRM volatile uint8 IODID_DomeLampCtlFlg;/* '<S6>/Bitwise AND9' */
extern MONPRM volatile uint8 IODID_DoorLckCtlFlg;/* '<S6>/Bitwise AND17' */
extern MONPRM volatile uint8 IODID_DoorUnlckCtlFlg;/* '<S6>/Bitwise AND16' */
extern MONPRM volatile uint8 IODID_FogLampFCtlFlg;/* '<S6>/Bitwise AND14' */
extern MONPRM volatile uint8 IODID_FogLampRCtlFlg;/* '<S6>/Bitwise AND15' */
extern MONPRM volatile uint8 IODID_HiBeamCtlFlg;/* '<S6>/Bitwise AND13' */
extern MONPRM volatile uint8 IODID_HornCtlFlg;/* '<S6>/Bitwise AND40' */
extern MONPRM volatile uint8 IODID_IG1RlyCtlFlg;/* '<S6>/Bitwise AND46' */
extern MONPRM volatile uint8 IODID_IG2RlyCtlFlg;/* '<S6>/Bitwise AND47' */
extern MONPRM volatile uint8 IODID_LowBeamCtlFlg;/* '<S6>/Bitwise AND12' */
extern MONPRM volatile uint8 IODID_PosLampCtlFlg;/* '<S6>/Bitwise AND7' */
extern MONPRM volatile uint8 IODID_ReverseLampCtlFlg;/* '<S6>/Bitwise AND5' */
extern MONPRM volatile uint8 IODID_TrunkUnlckCtlFlg;/* '<S6>/Bitwise AND22' */
extern MONPRM volatile uint8 IODID_TurnIndcrLCtlFlg;/* '<S6>/Bitwise AND' */
extern MONPRM volatile uint8 IODID_TurnIndcrRCtlFlg;/* '<S6>/Bitwise AND1' */
extern MONPRM volatile uint8 IODID_WinFLCtlFlg;/* '<S6>/Bitwise AND32' */
extern MONPRM volatile uint8 IODID_WinFRCtlFlg;/* '<S6>/Bitwise AND33' */
extern MONPRM volatile uint8 IODID_WiperHiSpdCtlFlg;/* '<S6>/Bitwise AND30' */
extern MONPRM volatile uint8 IODID_WiperLowSpdCtlFlg;/* '<S6>/Bitwise AND31' */
extern MONPRM volatile boolean LampCtl_AlrmSta;/* '<S450>/Chart' */
extern MONPRM volatile boolean LampCtl_AntiLckSta;/* '<S451>/Chart' */
extern MONPRM volatile boolean LampCtl_ArmedSta;/* '<S452>/Chart' */
extern MONPRM volatile boolean LampCtl_AutoLampSta;/* '<S365>/Switch' */
extern MONPRM volatile boolean LampCtl_AutoLampSw;/* '<S351>/LIB_TPD_10ms8' */
extern MONPRM volatile uint8 LampCtl_BackLadjvalFb;/* '<S321>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_BrakeLightSta;/* '<S340>/Switch1' */
extern MONPRM volatile boolean LampCtl_BrakeLightSw;/* '<S351>/Logical Operator13' */
extern MONPRM volatile boolean LampCtl_CrashSta;/* '<S453>/Chart' */
extern MONPRM volatile boolean LampCtl_DayRunLightSta;/* '<S334>/Switch1' */
extern MONPRM volatile boolean LampCtl_DisarmedSta;/* '<S454>/Chart' */
extern MONPRM volatile boolean LampCtl_DomeLampCloseDoor;/* '<S377>/Logical Operator6' */
extern MONPRM volatile boolean LampCtl_DomeLampCtl;/* '<S378>/Switch' */
extern MONPRM volatile boolean LampCtl_DomeLampFLOpen;/* '<S380>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampFROpen;/* '<S381>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampLockDoor;/* '<S393>/Logical Operator' */
extern MONPRM volatile boolean LampCtl_DomeLampOff;/* '<S325>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOffGrad;/* '<S325>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOn;/* '<S325>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOnGrad;/* '<S325>/Truth Table' */
extern MONPRM volatile uint8 LampCtl_DomeLampPwmDuty;/* '<S335>/Switch1' */
extern MONPRM volatile boolean LampCtl_DomeLampPwrOff;/* '<S386>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampUnlock;/* '<S387>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_EmerHazardLightSta;/* '<S352>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_EmerSta;/* '<S455>/Logical Operator' */
extern MONPRM volatile uint8 LampCtl_FlwrMeHomeCtlFb;/* '<S568>/Multiport Switch1' */
extern MONPRM volatile boolean LampCtl_FlwrMeHomeSta;/* '<S570>/Switch' */
extern MONPRM volatile uint16 LampCtl_FlwrMeHomeTim;/* '<S568>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_FogLampFSta;/* '<S345>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampFSw;/* '<S351>/LIB_TPD_10ms12' */
extern MONPRM volatile boolean LampCtl_FogLampRSta;/* '<S344>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampRSw;/* '<S351>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean LampCtl_HazardLightSta;/* '<S352>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_HazardLightSw;/* '<S351>/LIB_TPD_10ms10' */
extern MONPRM volatile boolean LampCtl_HiBeamShortToBat;/* '<S327>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_HiBeamSta;/* '<S347>/Switch1' */
extern MONPRM volatile boolean LampCtl_HiBeamSw;/* '<S351>/LIB_TPD_10ms2' */
extern MONPRM volatile uint8 LampCtl_J408BackLampPWM;/* '<S339>/Switch1' */
extern MONPRM volatile boolean LampCtl_J420BSDRightCtl;/* '<S341>/Switch1' */
extern MONPRM volatile boolean LampCtl_J422BSDLeftCtl;/* '<S342>/Switch1' */
extern MONPRM volatile boolean LampCtl_J449BoxLamp;/* '<S338>/Switch1' */
extern MONPRM volatile boolean LampCtl_KnobBeamFaultSta;/* '<S328>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_LampDelay;/* '<S406>/Switch' */
extern MONPRM volatile uint8 LampCtl_LightIntstSta;/* '<S330>/Chart' */
extern MONPRM volatile uint16 LampCtl_LightIntstVal;/* '<S351>/Data Type Conversion12' */
extern MONPRM volatile boolean LampCtl_LowBeamShortToBat;/* '<S331>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_LowBeamSta;/* '<S343>/Switch1' */
extern MONPRM volatile boolean LampCtl_LowBeamSw;/* '<S351>/LIB_TPD_10ms1' */
extern MONPRM volatile uint8 LampCtl_PartArmedSta;/* '<S457>/Chart' */
extern MONPRM volatile boolean LampCtl_PassLightSta;/* '<S348>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_PassLightSw;/* '<S351>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_PosLampSta;/* '<S333>/Switch1' */
extern MONPRM volatile boolean LampCtl_PosLampSw;/* '<S351>/LIB_TPD_10ms' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntL;/* '<S464>/LIB_Pulse' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntR;/* '<S466>/LIB_Pulse' */
extern MONPRM volatile uint8 LampCtl_RKEReq;/* '<S351>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_ReverseLampSta;/* '<S346>/Switch1' */
extern MONPRM volatile boolean LampCtl_RodBeamFaultSta;/* '<S459>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_ThermalrunawaySta;/* '<S460>/Chart' */
extern MONPRM volatile boolean LampCtl_TrunkWarnSta;/* '<S461>/Chart' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLFlashCnt;/* '<S352>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLOpen;/* '<S463>/Logical Operator' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLShort;/* '<S463>/Logical Operator2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSta;/* '<S337>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSw;/* '<S351>/LIB_TPD_10ms4' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLVol;/* '<S536>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneLSw;/* '<S351>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneRSw;/* '<S351>/LIB_TPD_10ms7' */
extern MONPRM volatile uint8 LampCtl_TurnIndcrMod;/* '<S352>/TurnIndcrLogic' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrPrd;/* '<S352>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRFlashCnt;/* '<S352>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrROpen;/* '<S463>/Logical Operator1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRShort;/* '<S463>/Logical Operator3' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSta;/* '<S336>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSw;/* '<S351>/LIB_TPD_10ms6' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRVol;/* '<S535>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRst;/* '<S352>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrWdt;/* '<S352>/TurnIndcrArb2' */
extern MONPRM volatile uint8 LampCtl_VehModeSta;/* '<S468>/Chart' */
extern MONPRM volatile uint8 LampCtl_VehSeekSta;/* '<S469>/Chart' */
extern MONPRM volatile uint8 LampCtl_VehSeekStaFb;/* '<S469>/SeekFb' */
extern MONPRM volatile boolean LampCtl_WelcomeLampSta;/* '<S569>/Switch' */
extern MONPRM volatile boolean PDUCtl_BrkPwrOn;/* '<S868>/Logical Operator1' */
extern MONPRM volatile boolean PDUCtl_DelayTimPwrOff;/* '<S867>/LIB_Tim' */
extern MONPRM volatile boolean PDUCtl_EmerPwrOff;/* '<S867>/Logical Operator13' */
extern MONPRM volatile boolean PDUCtl_HUPwrOff;/* '<S867>/Logical Operator8' */
extern MONPRM volatile boolean PDUCtl_IG1RelayFault;/* '<S869>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean PDUCtl_IG2RelayFault;/* '<S869>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean PDUCtl_IGRlyIlgCls;/* '<S869>/LIB_TPD_10ms3' */
extern MONPRM volatile uint8 PDUCtl_J421IG1RlyCtl;/* '<S865>/Switch1' */
extern MONPRM volatile uint8 PDUCtl_J437IG2RlyCtl;/* '<S866>/Switch1' */
extern MONPRM volatile boolean PDUCtl_KeyChk;/* '<S868>/Logical Operator5' */
extern MONPRM volatile boolean PDUCtl_OpenDoorPwrOn;/* '<S868>/Logical Operator' */
extern MONPRM volatile boolean PDUCtl_OsLckPwrOff;/* '<S867>/Logical Operator5' */
extern MONPRM volatile boolean PDUCtl_PwrOff;/* '<S867>/Logical Operator6' */
extern MONPRM volatile boolean PDUCtl_PwrOn;/* '<S868>/Logical Operator10' */
extern MONPRM volatile boolean PDUCtl_RemotePwrLckFb;/* '<S892>/Switch' */
extern MONPRM volatile uint8 PDUCtl_RemotePwrLckSta;/* '<S868>/RemoteLck' */
extern MONPRM volatile boolean PDUCtl_RemtOverTimPwrOff;/* '<S867>/LIB_Tim1' */
extern MONPRM volatile boolean PDUCtl_RemtPasvPwrOff;/* '<S867>/Logical Operator16' */
extern MONPRM volatile uint8 PDUCtl_RemtPwrCtlFb;/* '<S644>/RemtPwrCtlFb' */
extern MONPRM volatile boolean PDUCtl_RemtPwrOff;/* '<S867>/Logical Operator12' */
extern MONPRM volatile boolean PDUCtl_RemtPwrOn;/* '<S868>/Logical Operator9' */
extern MONPRM volatile boolean PDUCtl_StartReq;/* '<S908>/Switch' */
extern MONPRM volatile uint8 PDUCtl_SysPowerSts;/* '<S644>/Chart' */
extern MONPRM volatile uint8 PDUCtl_SysPwrMode;/* '<S644>/Truth Table' */
extern MONPRM volatile uint8 PDUCtl_SysPwrModeAct;/* '<S872>/Switch' */
extern MONPRM volatile boolean PDUCtl_SysPwrModeV;/* '<S869>/Switch' */
extern MONPRM volatile uint8 PEPSCtl_AvaluebleKeyInCar;/* '<S218>/Chart3' */
extern MONPRM volatile uint8 PEPSCtl_DrvPEAuthentAcsd;/* '<S218>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_FRPEAuthentAcsd;/* '<S218>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_FrbdnKeyNr;/* '<S216>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_IMMOKey;/* '<S219>/Chart5' */
extern MONPRM volatile uint8 PEPSCtl_IndicationKeyCloser;/* '<S219>/Chart2' */
extern MONPRM volatile uint8 PEPSCtl_KeyInCarSta;/* '<S218>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_KeyLoBattLvlWarn;/* '<S217>/Chart3' */
extern MONPRM volatile uint8 PEPSCtl_KeySta;/* '<S219>/Chart1' */
extern MONPRM volatile uint8 PEPSCtl_LckWlcmReq;/* '<S220>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_PSAuthentRes;/* '<S219>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_PSReq;/* '<S219>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_UnlckWlcmReq;/* '<S220>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_WarnKeyOutReminder;/* '<S217>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_WarnNoKeyFound;/* '<S219>/Chart2' */
extern MONPRM volatile boolean RVMCtl_J42Heat;/* '<S124>/Switch' */
extern MONPRM volatile uint8 SCS_FrntWiprSwtSt;/* '<S242>/Signal Conversion' */
extern MONPRM volatile boolean SCS_FrntWshrSwtSt;/* '<S242>/Signal Conversion1' */
extern MONPRM volatile boolean SCS_FrntWshrSwtStVD;/* '<S242>/Signal Conversion2' */
extern MONPRM volatile boolean SCS_WiprSwtStVD;/* '<S242>/Signal Conversion3' */
extern MONPRM volatile uint8 SeatCtl_CN167DrvSeatHtPWM;/* '<S134>/Switch' */
extern MONPRM volatile boolean SeatCtl_DrvNTCOpen;/* '<S129>/LIB_TPD_Ts1' */
extern MONPRM volatile boolean SeatCtl_DrvNTCShort;/* '<S129>/LIB_TPD_Ts' */
extern MONPRM volatile sint8 SeatCtl_DrvSeatTemp;/* '<S129>/Data Type Conversion' */
extern MONPRM volatile uint8 SeatCtl_MaiDrvSeatStFb;/* '<S129>/Multiport Switch' */
extern MONPRM volatile uint8 SeatCtl_RemtHeatFb;/* '<S129>/HeatFb' */
extern MONPRM volatile boolean SteerWhlCtl_J447SteerWhlHt;/* '<S141>/Switch' */
extern MONPRM volatile uint8 SteerWhlCtl_RemtHeatFb;/* '<S137>/HeatFb' */
extern MONPRM volatile uint8 SteerWhlCtl_SteerWhlHeatSts;/* '<S137>/HeatSet' */
extern MONPRM volatile sint8 SteerWhlCtl_SteerWhlTemp;/* '<S137>/Data Type Conversion' */
extern MONPRM volatile boolean WakeUpCtl_NMReq;/* '<S923>/Switch' */
extern MONPRM volatile boolean WakeUpCtl_SleepAllwd;/* '<S911>/Logical Operator5' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnSw;/* '<S150>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinDnSw;/* '<S150>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinUpSw;/* '<S150>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean WinCtl_DrvWinAutoDnReq;/* '<S152>/Chart10' */
extern MONPRM volatile boolean WinCtl_DrvWinAutoDnSw;/* '<S150>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WinCtl_DrvWinDnProt;/* '<S151>/LIB_CntLimit1' */
extern MONPRM volatile boolean WinCtl_DrvWinDnReq;/* '<S152>/Chart2' */
extern MONPRM volatile boolean WinCtl_DrvWinDnSw;/* '<S150>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WinCtl_DrvWinMotorLocked;/* '<S152>/LIB_TPD_10ms3' */
extern MONPRM volatile uint8 WinCtl_DrvWinReq;/* '<S152>/Switch11' */
extern MONPRM volatile uint8 WinCtl_DrvWinSta;/* '<S10>/DrvWinCtl' */
extern MONPRM volatile boolean WinCtl_DrvWinUpProt;/* '<S151>/LIB_CntLimit' */
extern MONPRM volatile boolean WinCtl_DrvWinUpReq;/* '<S152>/Chart3' */
extern MONPRM volatile boolean WinCtl_DrvWinUpSw;/* '<S150>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean WinCtl_J51DrvWinUp;/* '<S145>/Switch1' */
extern MONPRM volatile boolean WinCtl_J53DrvWinDn;/* '<S148>/Switch1' */
extern MONPRM volatile boolean WinCtl_J55PsgWinUp;/* '<S146>/Switch' */
extern MONPRM volatile boolean WinCtl_J57PsgWinDn;/* '<S147>/Switch' */
extern MONPRM volatile boolean WinCtl_PsgWinAutoDnReq;/* '<S152>/Chart1' */
extern MONPRM volatile boolean WinCtl_PsgWinAutoDnSw;/* '<S150>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean WinCtl_PsgWinDnProt;/* '<S151>/LIB_CntLimit3' */
extern MONPRM volatile boolean WinCtl_PsgWinDnReq;/* '<S152>/Chart4' */
extern MONPRM volatile boolean WinCtl_PsgWinDnSw;/* '<S150>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean WinCtl_PsgWinMotorLocked;/* '<S152>/LIB_TPD_10ms1' */
extern MONPRM volatile uint8 WinCtl_PsgWinReq;/* '<S152>/Switch10' */
extern MONPRM volatile uint8 WinCtl_PsgWinSta;/* '<S10>/PsgWinCtl' */
extern MONPRM volatile boolean WinCtl_PsgWinUpProt;/* '<S151>/LIB_CntLimit2' */
extern MONPRM volatile boolean WinCtl_PsgWinUpReq;/* '<S152>/Chart5' */
extern MONPRM volatile boolean WinCtl_PsgWinUpSw;/* '<S150>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WiperCtl_HiSpdDrv;/* '<S586>/Switch1' */
extern MONPRM volatile uint16 WiperCtl_InrTim;/* '<S592>/Multiport Switch' */
extern MONPRM volatile boolean WiperCtl_InrTimChg;/* '<S592>/Relational Operator1' */
extern MONPRM volatile boolean WiperCtl_LockedRotorProtSta;/* '<S584>/Logical Operator2' */
extern MONPRM volatile boolean WiperCtl_LowSpdDrv;/* '<S585>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashMotorDrv;/* '<S587>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashSw;/* '<S588>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean WiperCtl_WashWiperSta;/* '<S589>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSta;/* '<S591>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSw;/* '<S588>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WiperCtl_WiperInrSta;/* '<S592>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperInrSw;/* '<S588>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSta;/* '<S593>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSw;/* '<S588>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean WiperCtl_WiperMaintSta;/* '<S631>/Switch' */
extern MONPRM volatile boolean WiperCtl_WiperMistSta;/* '<S595>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperMistSw;/* '<S588>/LIB_TPD_10ms' */
extern MONPRM volatile boolean WiperCtl_WiperOffSta;/* '<S596>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperOffSw;/* '<S588>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WiperCtl_WiperParkPosSw;/* '<S588>/LIB_TPD_10ms6' */
extern MONPRM volatile uint8 WiperCtl_WiperSta;/* '<S590>/Chart' */
extern MONPRM volatile uint8 WiperCtl_WiprIntlTimeSetFb;/* '<S592>/Multiport Switch1' */

#endif                                 /* RTW_HEADER_monPrmsBcm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
