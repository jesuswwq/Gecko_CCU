/*
 * File: monPrmsBcm.h
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

#ifndef RTW_HEADER_monPrmsBcm_h_
#define RTW_HEADER_monPrmsBcm_h_
#include "rtwtypes.h"
#include "AppSwcBcm_types.h"

/* Exported data declaration */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Declaration for custom storage class: Volatile */
extern MONPRM volatile boolean AlmSysCtl_AlrmWarnTimOut;/* '<S430>/AlmSysLogic' */
extern MONPRM volatile uint8 AlmSysCtl_BodyWarnSts;/* '<S430>/AlmSysLogic' */
extern MONPRM volatile uint8 BCM_DriverWinSwSig;/* '<S316>/Switch' */
extern MONPRM volatile uint8 BCM_DrvPassWinSwSig;/* '<S309>/Switch' */
extern MONPRM volatile uint8 BCM_PassWinSwSig;/* '<S317>/Switch' */
extern MONPRM volatile uint8 BSW_BrkLampDigSts;/* '<S645>/C Caller' */
extern MONPRM volatile uint16 BSW_CN744DrvSeatResis;/* '<S1>/C Caller14' */
extern MONPRM volatile uint8 BSW_CrashPWMSta;/* '<S4>/C Caller15' */
extern MONPRM volatile uint16 BSW_DrvWinMotorCur;/* '<S1>/C Caller25' */
extern MONPRM volatile uint8 BSW_EEIlluminatedEntrySys;/* '<S4>/C Caller37' */
extern MONPRM volatile uint8 BSW_EEKeyEntry;/* '<S4>/C Caller38' */
extern MONPRM volatile uint8 BSW_FogLampFCfg;/* '<S4>/C Caller3' */
extern MONPRM volatile uint8 BSW_HMACfg;/* '<S4>/C Caller12' */
extern MONPRM volatile uint8 BSW_HiBeamDigSts;/* '<S649>/C Caller1' */
extern MONPRM volatile uint8 BSW_IllmndSts;/* '<S4>/Constant3' */
extern MONPRM volatile uint16 BSW_J112DrvSeatResis;/* '<S4>/C Caller16' */
extern MONPRM volatile uint16 BSW_J113DrvWinSwResis;/* '<S1>/C Caller26' */
extern MONPRM volatile uint16 BSW_J125LightIntst;/* '<S4>/C Caller30' */
extern MONPRM volatile uint16 BSW_J126DrvPsgWinSwResis;/* '<S1>/C Caller27' */
extern MONPRM volatile uint16 BSW_J134SteerWhlResis;/* '<S1>/C Caller34' */
extern MONPRM volatile uint16 BSW_J26PsgWinSwResis;/* '<S1>/C Caller28' */
extern MONPRM volatile uint8 BSW_J310DoorAjarFR;/* '<S4>/C Caller2' */
extern MONPRM volatile uint8 BSW_J313BrakeLoSw;/* '<S4>/C Caller7' */
extern MONPRM volatile uint8 BSW_J319HornSw;/* '<S3>/C Caller31' */
extern MONPRM volatile uint8 BSW_J320DoorAjarRL;/* '<S4>/C Caller17' */
extern MONPRM volatile uint8 BSW_J321DoorAjarFL;/* '<S4>/C Caller1' */
extern MONPRM volatile uint8 BSW_J322FogLampF;/* '<S4>/C Caller4' */
extern MONPRM volatile uint8 BSW_J334WiperParkPos;/* '<S3>/C Caller8' */
extern MONPRM volatile uint8 BSW_J335DriverDoorLck;/* '<S4>/C Caller' */
extern MONPRM volatile uint8 BSW_J336Trunk;/* '<S4>/C Caller18' */
extern MONPRM volatile uint8 BSW_J337PsgPE;/* '<S4>/C Caller6' */
extern MONPRM volatile uint8 BSW_J338DrvPE;/* '<S4>/C Caller5' */
extern MONPRM volatile uint8 BSW_J339BrakeHiSw;/* '<S4>/C Caller33' */
extern MONPRM volatile uint8 BSW_J346FogLampR;/* '<S4>/C Caller13' */
extern MONPRM volatile uint8 BSW_J349TrunkLck;/* '<S4>/C Caller19' */
extern MONPRM volatile uint8 BSW_J36DoorAjarRR;/* '<S4>/C Caller20' */
extern MONPRM volatile uint8 BSW_J37TrunkAjar;/* '<S4>/C Caller21' */
extern MONPRM volatile uint8 BSW_J38HoodAjar;/* '<S4>/C Caller22' */
extern MONPRM volatile uint8 BSW_LowBeamDigSts;/* '<S653>/C Caller' */
extern MONPRM volatile uint16 BSW_PsgWinMotorCur;/* '<S1>/C Caller29' */
extern MONPRM volatile uint8 BSW_RKEReq;/* '<S4>/C Caller32' */
extern MONPRM volatile uint8 BSW_WakeupReas;/* '<S438>/Signal Conversion' */
extern MONPRM volatile boolean BatSaveCtl_DoorChgSta;/* '<S459>/Logical Operator1' */
extern MONPRM volatile boolean BatSaveCtl_DoorLckPwrOff;/* '<S458>/LIB_PosPluse1' */
extern MONPRM volatile boolean BatSaveCtl_DoorUnlckPwrOn;/* '<S459>/Relational Operator1' */
extern MONPRM volatile boolean BatSaveCtl_J64SavePwr;/* '<S457>/Switch1' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOff;/* '<S458>/LIB_PosPluse' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOn;/* '<S459>/Relational Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOff;/* '<S458>/Logical Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOn;/* '<S459>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLck;/* '<S522>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLckSta;/* '<S523>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_CrshUnlck;/* '<S496>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFLSw;/* '<S471>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFRSw;/* '<S471>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRLSw;/* '<S471>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRRSw;/* '<S471>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean DoorLckCtl_DoorProtUnlck;/* '<S474>/LIB_Tim' */
extern MONPRM volatile boolean DoorLckCtl_DriverDoorLckSw;/* '<S471>/LIB_TPD_10ms' */
extern MONPRM volatile boolean DoorLckCtl_DrvPESw;/* '<S471>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean DoorLckCtl_DrvSeatSw;/* '<S471>/LIB_TPD_10ms11' */
extern MONPRM volatile uint8 DoorLckCtl_EEIlluminatedEntrySys;/* '<S471>/Switch14' */
extern MONPRM volatile uint8 DoorLckCtl_EEKeyEntry;/* '<S471>/Switch13' */
extern MONPRM volatile boolean DoorLckCtl_HULck;/* '<S489>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_HUUnLck;/* '<S497>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_HoodAjarSw;/* '<S471>/Constant69' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckSts;/* '<S475>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckStsFb;/* '<S475>/Multiport Switch1' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndSts;/* '<S471>/Switch15' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockSts;/* '<S476>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockStsFb;/* '<S476>/Multiport Switch1' */
extern MONPRM volatile boolean DoorLckCtl_InsLck;/* '<S477>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_InsLckSta;/* '<S432>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_InsUnlck;/* '<S478>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_J511TrunkUnlck;/* '<S469>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J54DoorLck;/* '<S468>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J56DoorUnlck;/* '<S470>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_MechAntiLck;/* '<S474>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechLck;/* '<S514>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechUnlck;/* '<S533>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_MotorProt;/* '<S479>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_OsLck;/* '<S480>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_OsLckSta;/* '<S432>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_OsUnlck;/* '<S481>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PELck;/* '<S515>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_PEUnlck;/* '<S534>/Logical Operator1' */
extern MONPRM volatile uint8 DoorLckCtl_ParkAutoUnlockSetFb;/* '<S483>/Multiport Switch' */
extern MONPRM volatile boolean DoorLckCtl_ParkUnlck;/* '<S498>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PsgPESw;/* '<S471>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean DoorLckCtl_RKEAntiLck;/* '<S474>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_RKELck;/* '<S528>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_RKEUnlck;/* '<S542>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_RemoteLockFb;/* '<S485>/Chart2' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSet;/* '<S484>/Constant8' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSetFb;/* '<S484>/Constant9' */
extern MONPRM volatile boolean DoorLckCtl_SpdLck;/* '<S495>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TboxAntiLck;/* '<S474>/Logical Operator5' */
extern MONPRM volatile boolean DoorLckCtl_TboxLck;/* '<S529>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TboxUnlck;/* '<S543>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_ThermRunawayUnlck;/* '<S499>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAjarSw;/* '<S471>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAutoLck;/* '<S531>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_TrunkLckSta;/* '<S432>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkLckSw;/* '<S432>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkRKEUnlck;/* '<S545>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TrunkSw;/* '<S471>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean DoorLckCtl_TrunkTboxUnlck;/* '<S547>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TrunkUnlck;/* '<S537>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_VehRun;/* '<S471>/Logical Operator4' */
extern MONPRM volatile float32 DoorLckCtl_VehSpd;/* '<S471>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_VehStop;/* '<S471>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeLck;/* '<S519>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeUnlck;/* '<S538>/Logical Operator1' */
extern MONPRM volatile uint8 DynDID_0xF200ECUPwrMode;/* '<S433>/Signal Conversion2' */
extern MONPRM volatile uint8 DynDID_0xF22BFobInformation[16];/* '<S433>/Constant27' */
extern MONPRM volatile uint8 DynDID_0xF22CAntitheftSta;/* '<S433>/Signal Conversion' */
extern MONPRM volatile uint8 DynDID_0xF230DoorOpRecord[10];/* '<S595>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF231TrunkOpRecord[10];/* '<S596>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF232LocalStartUpFailRecord[10];/* '<S597>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF233RemoteStartUpFailRecord[10];/* '<S598>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF234ADSampleValue[23];/* '<S599>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF235DigtInSampleValue[5];/* '<S600>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF236DigtOutSampleValue[5];/* '<S601>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF237PwrModeSta;/* '<S433>/Signal Conversion1' */
extern MONPRM volatile uint8 DynDID_DoorOpRecord;/* '<S595>/Switch' */
extern MONPRM volatile uint8 EEReadCtl_BJSTimeDay;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_BJSTimeHour;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_BJSTimeMonth;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint16 EEReadCtl_BJSTimeYear;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_BackLadjvalFb;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_BodyWarnSts;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_CrashSta;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarFLSw;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarFRSw;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarRLSw;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarRRSw;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorOpRecord[10];/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DriverDoorLckSw;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DrvSeatSw;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_FlwrMeHomeCtlFb;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_HazardLightSta;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_IllmndLckSts;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_IllmndUnlckSts;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_InrTim;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_LocalStartFailOpRecord[10];/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_LockHoornOnSts;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_ParkAutoUnlockSetFb;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_RemotePwrLckSta;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_RemoteStartFailRecord[10];/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_SpdCtlLckSet;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_StartReq;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_SysPwrMode;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkAjarSw;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkLckSw;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkOpRecord[10];/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkSw;/* '<S289>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_WiprIntlTimeSetFb;/* '<S289>/EEReadCtl' */
extern MONPRM volatile boolean ESCLCtl_J436Lck;/* '<S625>/ESCLLck' */
extern MONPRM volatile boolean ESCLCtl_J436PwrSup;/* '<S630>/Switch' */
extern MONPRM volatile boolean ESCLCtl_J436Unlck;/* '<S625>/ESCLUnlck' */
extern MONPRM volatile uint8 ESCLCtl_Lck;/* '<S625>/ESCLLck' */
extern MONPRM volatile uint8 ESCLCtl_UnOrLockCrtl;/* '<S625>/Truth Table' */
extern MONPRM volatile uint8 ESCLCtl_Unlck;/* '<S625>/ESCLUnlck' */
extern MONPRM volatile uint8 HornCtl_AlarmSta;/* '<S339>/Alarm' */
extern MONPRM volatile uint8 HornCtl_AntiLckSta;/* '<S340>/AntiLck' */
extern MONPRM volatile uint8 HornCtl_ArmedSta;/* '<S341>/Armed' */
extern MONPRM volatile boolean HornCtl_HornSwCtl;/* '<S343>/LIB_TPD_10ms' */
extern MONPRM volatile boolean HornCtl_J430HornDrv;/* '<S345>/Switch1' */
extern MONPRM volatile uint8 HornCtl_LockHoornOnSt;/* '<S342>/Multiport Switch' */
extern MONPRM volatile uint8 HornCtl_LockHoornOnStFb;/* '<S342>/Multiport Switch1' */
extern MONPRM volatile uint8 HornCtl_PartArmedSta;/* '<S346>/PartArmed' */
extern MONPRM volatile uint8 HornCtl_SeekSta;/* '<S347>/Seek' */
extern MONPRM volatile uint8 HornCtl_TrunkWarnSta;/* '<S348>/Chart1' */
extern MONPRM volatile uint8 IMMOCtl_AuthResp[8];/* '<S435>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_INVRandom[8];/* '<S435>/Signal Conversion' */
extern MONPRM volatile uint8 IMMOCtl_SKRead[16];/* '<S435>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_SKSta;/* '<S435>/IMMOCtl' */
extern MONPRM volatile uint8 IODID_BSDLeftCtlFlg;/* '<S7>/Bitwise AND44' */
extern MONPRM volatile uint8 IODID_BSDRightCtlFlg;/* '<S7>/Bitwise AND43' */
extern MONPRM volatile uint8 IODID_BackLampCtlFlg;/* '<S7>/Bitwise AND2' */
extern MONPRM volatile uint8 IODID_BatSaveCtlFlg;/* '<S7>/Bitwise AND42' */
extern MONPRM volatile uint8 IODID_BrakeLightCtlFlg;/* '<S7>/Bitwise AND3' */
extern MONPRM volatile uint8 IODID_DayRunLightCtlFlg;/* '<S7>/Bitwise AND6' */
extern MONPRM volatile uint8 IODID_DomeLampCtlFlg;/* '<S7>/Bitwise AND9' */
extern MONPRM volatile uint8 IODID_DoorLckCtlFlg;/* '<S7>/Bitwise AND17' */
extern MONPRM volatile uint8 IODID_DoorUnlckCtlFlg;/* '<S7>/Bitwise AND16' */
extern MONPRM volatile uint8 IODID_FogLampFCtlFlg;/* '<S7>/Bitwise AND14' */
extern MONPRM volatile uint8 IODID_FogLampRCtlFlg;/* '<S7>/Bitwise AND15' */
extern MONPRM volatile uint8 IODID_HiBeamCtlFlg;/* '<S7>/Bitwise AND13' */
extern MONPRM volatile uint8 IODID_HornCtlFlg;/* '<S7>/Bitwise AND40' */
extern MONPRM volatile uint8 IODID_IG1RlyCtlFlg;/* '<S7>/Bitwise AND46' */
extern MONPRM volatile uint8 IODID_IG2RlyCtlFlg;/* '<S7>/Bitwise AND47' */
extern MONPRM volatile uint8 IODID_LowBeamCtlFlg;/* '<S7>/Bitwise AND12' */
extern MONPRM volatile uint8 IODID_PosLampCtlFlg;/* '<S7>/Bitwise AND7' */
extern MONPRM volatile uint8 IODID_ReverseLampCtlFlg;/* '<S7>/Bitwise AND5' */
extern MONPRM volatile uint8 IODID_TrunkUnlckCtlFlg;/* '<S7>/Bitwise AND22' */
extern MONPRM volatile uint8 IODID_TurnIndcrLCtlFlg;/* '<S7>/Bitwise AND' */
extern MONPRM volatile uint8 IODID_TurnIndcrRCtlFlg;/* '<S7>/Bitwise AND1' */
extern MONPRM volatile uint8 IODID_WinFLCloseFlg;/* '<S7>/Bitwise AND38' */
extern MONPRM volatile uint8 IODID_WinFLOpenFlg;/* '<S7>/Bitwise AND39' */
extern MONPRM volatile uint8 IODID_WinFRCloseFlg;/* '<S7>/Bitwise AND32' */
extern MONPRM volatile uint8 IODID_WinFROpenFlg;/* '<S7>/Bitwise AND33' */
extern MONPRM volatile uint8 IODID_WiperHiSpdCtlFlg;/* '<S7>/Bitwise AND30' */
extern MONPRM volatile uint8 IODID_WiperLowSpdCtlFlg;/* '<S7>/Bitwise AND31' */
extern MONPRM volatile boolean LampCtl_AlrmSta;/* '<S778>/Chart' */
extern MONPRM volatile boolean LampCtl_AntiLckSta;/* '<S779>/Chart' */
extern MONPRM volatile boolean LampCtl_ArmedSta;/* '<S780>/Chart' */
extern MONPRM volatile boolean LampCtl_AutoHiBeam;/* '<S641>/AutoHiBeamCtl' */
extern MONPRM volatile boolean LampCtl_AutoLampSta;/* '<S688>/Switch' */
extern MONPRM volatile boolean LampCtl_AutoLampSw;/* '<S673>/LIB_TPD_10ms8' */
extern MONPRM volatile uint8 LampCtl_BackLadjvalFb;/* '<S643>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_BrakeLightSta;/* '<S662>/Switch1' */
extern MONPRM volatile boolean LampCtl_BrakeLightSw;/* '<S673>/Logical Operator13' */
extern MONPRM volatile boolean LampCtl_BrkLampShortToBatOrOpen;/* '<S645>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_BrkLampShortToGnd;/* '<S645>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean LampCtl_CrashSta;/* '<S781>/Chart1' */
extern MONPRM volatile boolean LampCtl_DayRunLightSta;/* '<S656>/Switch1' */
extern MONPRM volatile boolean LampCtl_DisarmedSta;/* '<S782>/Chart' */
extern MONPRM volatile boolean LampCtl_DomeLampCloseDoor;/* '<S702>/Logical Operator6' */
extern MONPRM volatile boolean LampCtl_DomeLampCtl;/* '<S703>/Switch' */
extern MONPRM volatile boolean LampCtl_DomeLampFLOpen;/* '<S705>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampFROpen;/* '<S706>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampLockDoor;/* '<S718>/Logical Operator' */
extern MONPRM volatile boolean LampCtl_DomeLampOff;/* '<S647>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOffGrad;/* '<S647>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOn;/* '<S647>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOnGrad;/* '<S647>/Truth Table' */
extern MONPRM volatile uint8 LampCtl_DomeLampPwmDuty;/* '<S657>/Switch1' */
extern MONPRM volatile boolean LampCtl_DomeLampPwrOff;/* '<S711>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampUnlock;/* '<S712>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_EmerHazardLightSta;/* '<S674>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_EmerSta;/* '<S783>/Logical Operator' */
extern MONPRM volatile uint8 LampCtl_FlwrMeHomeCtlFb;/* '<S896>/Multiport Switch1' */
extern MONPRM volatile boolean LampCtl_FlwrMeHomeSta;/* '<S898>/Switch' */
extern MONPRM volatile uint16 LampCtl_FlwrMeHomeTim;/* '<S896>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_FogLampFSta;/* '<S667>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampFSw;/* '<S673>/LIB_TPD_10ms12' */
extern MONPRM volatile boolean LampCtl_FogLampRSta;/* '<S666>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampRSw;/* '<S673>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean LampCtl_HazardLightSta;/* '<S674>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_HazardLightSw;/* '<S673>/LIB_TPD_10ms10' */
extern MONPRM volatile boolean LampCtl_HiBeamShortToBat;/* '<S649>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_HiBeamSta;/* '<S669>/Switch1' */
extern MONPRM volatile boolean LampCtl_HiBeamSw;/* '<S673>/LIB_TPD_10ms2' */
extern MONPRM volatile uint8 LampCtl_J408BackLampPWM;/* '<S661>/Switch1' */
extern MONPRM volatile boolean LampCtl_J420BSDRightCtl;/* '<S663>/Switch1' */
extern MONPRM volatile boolean LampCtl_J422BSDLeftCtl;/* '<S664>/Switch1' */
extern MONPRM volatile boolean LampCtl_J449BoxLamp;/* '<S660>/Switch1' */
extern MONPRM volatile boolean LampCtl_KnobBeamFaultSta;/* '<S650>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_LampDelay;/* '<S731>/Switch' */
extern MONPRM volatile uint8 LampCtl_LightIntstSta;/* '<S652>/Chart' */
extern MONPRM volatile uint16 LampCtl_LightIntstVal;/* '<S673>/Data Type Conversion12' */
extern MONPRM volatile boolean LampCtl_LowBeamShortToBat;/* '<S653>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_LowBeamSta;/* '<S665>/Switch1' */
extern MONPRM volatile boolean LampCtl_LowBeamSw;/* '<S673>/LIB_TPD_10ms1' */
extern MONPRM volatile uint8 LampCtl_PartArmedSta;/* '<S785>/Chart' */
extern MONPRM volatile boolean LampCtl_PassLightSta;/* '<S670>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_PassLightSw;/* '<S673>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_PosLampSta;/* '<S655>/Switch1' */
extern MONPRM volatile boolean LampCtl_PosLampSw;/* '<S673>/LIB_TPD_10ms' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntL;/* '<S792>/LIB_Pulse' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntR;/* '<S794>/LIB_Pulse' */
extern MONPRM volatile uint8 LampCtl_RKEReq;/* '<S673>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_ReverseLampSta;/* '<S668>/Switch1' */
extern MONPRM volatile boolean LampCtl_RodBeamFaultSta;/* '<S787>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_ThermalrunawaySta;/* '<S788>/Chart' */
extern MONPRM volatile boolean LampCtl_TrunkWarnSta;/* '<S789>/Chart' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLFlashCnt;/* '<S674>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLOpen;/* '<S791>/Logical Operator' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLShort;/* '<S791>/Logical Operator2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSta;/* '<S659>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSw;/* '<S673>/LIB_TPD_10ms4' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLVol;/* '<S864>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneLSw;/* '<S673>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneRSw;/* '<S673>/LIB_TPD_10ms7' */
extern MONPRM volatile uint8 LampCtl_TurnIndcrMod;/* '<S674>/TurnIndcrLogic' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrPrd;/* '<S674>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRFlashCnt;/* '<S674>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrROpen;/* '<S791>/Logical Operator1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRShort;/* '<S791>/Logical Operator3' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSta;/* '<S658>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSw;/* '<S673>/LIB_TPD_10ms6' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRVol;/* '<S863>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRst;/* '<S674>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrWdt;/* '<S674>/TurnIndcrArb2' */
extern MONPRM volatile uint8 LampCtl_VehModeSta;/* '<S796>/Chart' */
extern MONPRM volatile uint8 LampCtl_VehSeekSta;/* '<S797>/Chart' */
extern MONPRM volatile uint8 LampCtl_VehSeekStaFb;/* '<S797>/SeekFb' */
extern MONPRM volatile boolean LampCtl_WelcomeLampSta;/* '<S897>/Switch' */
extern MONPRM volatile boolean PDUCtl_BrkPwrOn;/* '<S917>/Logical Operator1' */
extern MONPRM volatile boolean PDUCtl_DelayTimPwrOff;/* '<S916>/LIB_Tim' */
extern MONPRM volatile boolean PDUCtl_EmerPwrOff;/* '<S916>/Logical Operator13' */
extern MONPRM volatile boolean PDUCtl_HUPwrOff;/* '<S916>/Logical Operator8' */
extern MONPRM volatile boolean PDUCtl_IG1RelayFault;/* '<S918>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean PDUCtl_IG2RelayFault;/* '<S918>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean PDUCtl_IGRlyIlgCls;/* '<S918>/LIB_TPD_10ms3' */
extern MONPRM volatile uint8 PDUCtl_J421IG1RlyCtl;/* '<S914>/Switch1' */
extern MONPRM volatile uint8 PDUCtl_J437IG2RlyCtl;/* '<S915>/Switch1' */
extern MONPRM volatile boolean PDUCtl_KeyChk;/* '<S917>/Logical Operator5' */
extern MONPRM volatile boolean PDUCtl_OTAOverTimPwrOff;/* '<S916>/LIB_PosPluse1' */
extern MONPRM volatile boolean PDUCtl_OTAPwrOff;/* '<S916>/Logical Operator20' */
extern MONPRM volatile boolean PDUCtl_OTAPwrOn;/* '<S943>/Logical Operator' */
extern MONPRM volatile boolean PDUCtl_OpenDoorPwrOn;/* '<S917>/Logical Operator' */
extern MONPRM volatile boolean PDUCtl_OsLckPwrOff;/* '<S916>/Logical Operator5' */
extern MONPRM volatile boolean PDUCtl_PwrOff;/* '<S916>/Logical Operator6' */
extern MONPRM volatile boolean PDUCtl_PwrOn;/* '<S917>/Logical Operator11' */
extern MONPRM volatile boolean PDUCtl_RemotePwrLckFb;/* '<S947>/Switch' */
extern MONPRM volatile uint8 PDUCtl_RemotePwrLckSta;/* '<S917>/RemoteLck' */
extern MONPRM volatile boolean PDUCtl_RemtOverTimPwrOff;/* '<S916>/LIB_Tim1' */
extern MONPRM volatile boolean PDUCtl_RemtPasvPwrOff;/* '<S916>/Logical Operator16' */
extern MONPRM volatile uint8 PDUCtl_RemtPwrCtlFb;/* '<S437>/RemtPwrCtlFb' */
extern MONPRM volatile boolean PDUCtl_RemtPwrOff;/* '<S916>/Logical Operator12' */
extern MONPRM volatile boolean PDUCtl_RemtPwrOn;/* '<S917>/Logical Operator9' */
extern MONPRM volatile boolean PDUCtl_StartReq;/* '<S965>/Switch' */
extern MONPRM volatile uint8 PDUCtl_SysPowerSts;/* '<S437>/Chart' */
extern MONPRM volatile uint8 PDUCtl_SysPwrMode;/* '<S437>/Truth Table' */
extern MONPRM volatile uint8 PDUCtl_SysPwrModeAct;/* '<S921>/Switch' */
extern MONPRM volatile boolean PDUCtl_SysPwrModeV;/* '<S918>/Switch' */
extern MONPRM volatile uint8 PEPSCtl_AvaluebleKeyInCar;/* '<S259>/Chart3' */
extern MONPRM volatile uint8 PEPSCtl_DrvPEAuthentAcsd;/* '<S259>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_FRPEAuthentAcsd;/* '<S259>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_FrbdnKeyNr;/* '<S257>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_IMMOKey;/* '<S260>/Chart5' */
extern MONPRM volatile uint8 PEPSCtl_IndicationKeyCloser;/* '<S260>/Chart2' */
extern MONPRM volatile uint8 PEPSCtl_KeyInCarSta;/* '<S259>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_KeyLoBattLvlWarn;/* '<S258>/Chart3' */
extern MONPRM volatile uint8 PEPSCtl_KeySta;/* '<S260>/Chart1' */
extern MONPRM volatile uint8 PEPSCtl_LckWlcmReq;/* '<S261>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_PSAuthentRes;/* '<S260>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_PSReq;/* '<S260>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_UnlckWlcmReq;/* '<S261>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_WarnKeyOutReminder;/* '<S258>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_WarnNoKeyFound;/* '<S260>/Chart2' */
extern MONPRM volatile boolean RVMCtl_J42Heat;/* '<S140>/Switch' */
extern MONPRM volatile uint8 SCS_FrntWiprSwtSt;/* '<S291>/Signal Conversion' */
extern MONPRM volatile boolean SCS_FrntWshrSwtSt;/* '<S291>/Signal Conversion1' */
extern MONPRM volatile boolean SCS_FrntWshrSwtStVD;/* '<S291>/Signal Conversion2' */
extern MONPRM volatile boolean SCS_WiprSwtStVD;/* '<S291>/Signal Conversion3' */
extern MONPRM volatile uint8 SeatCtl_CN167DrvSeatHtPWM;/* '<S150>/Switch' */
extern MONPRM volatile boolean SeatCtl_DrvNTCOpen;/* '<S145>/LIB_TPD_Ts1' */
extern MONPRM volatile boolean SeatCtl_DrvNTCShort;/* '<S145>/LIB_TPD_Ts' */
extern MONPRM volatile sint8 SeatCtl_DrvSeatTemp;/* '<S145>/Data Type Conversion' */
extern MONPRM volatile uint8 SeatCtl_MaiDrvSeatStFb;/* '<S145>/Multiport Switch' */
extern MONPRM volatile uint8 SeatCtl_RemtHeatFb;/* '<S145>/HeatFb' */
extern MONPRM volatile boolean SteerWhlCtl_J447SteerWhlHt;/* '<S157>/Switch' */
extern MONPRM volatile uint8 SteerWhlCtl_RemtHeatFb;/* '<S153>/HeatFb' */
extern MONPRM volatile uint8 SteerWhlCtl_SteerWhlHeatSts;/* '<S153>/HeatSet' */
extern MONPRM volatile sint8 SteerWhlCtl_SteerWhlTemp;/* '<S153>/Data Type Conversion' */
extern MONPRM volatile uint8 TboxTim_BJSTimeDay;/* '<S11>/TboxTim' */
extern MONPRM volatile uint8 TboxTim_BJSTimeHour;/* '<S11>/TboxTim' */
extern MONPRM volatile uint8 TboxTim_BJSTimeMonth;/* '<S11>/TboxTim' */
extern MONPRM volatile uint16 TboxTim_BJSTimeYear;/* '<S11>/TboxTim' */
extern MONPRM volatile uint8 TboxTim_HourDiff;/* '<S11>/TboxTim' */
extern MONPRM volatile boolean WakeUpCtl_NMReq;/* '<S980>/Switch' */
extern MONPRM volatile boolean WakeUpCtl_SleepAllwd;/* '<S968>/Logical Operator5' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnReq;/* '<S171>/Chart13' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnSw;/* '<S169>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinDnReq;/* '<S171>/Chart11' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinDnSw;/* '<S169>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinOvTimProt;/* '<S171>/LIB_PosPluse2' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinUpReq;/* '<S171>/Chart12' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinUpSw;/* '<S169>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean WinCtl_DrvWinAutoDnReq;/* '<S171>/Chart10' */
extern MONPRM volatile boolean WinCtl_DrvWinAutoDnSw;/* '<S169>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WinCtl_DrvWinDnProt;/* '<S170>/LIB_CntLimit1' */
extern MONPRM volatile boolean WinCtl_DrvWinDnReq;/* '<S171>/Chart2' */
extern MONPRM volatile boolean WinCtl_DrvWinDnSw;/* '<S169>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WinCtl_DrvWinMotorLocked;/* '<S171>/LIB_TPD_10ms3' */
extern MONPRM volatile uint8 WinCtl_DrvWinReq;/* '<S171>/Switch11' */
extern MONPRM volatile uint8 WinCtl_DrvWinSta;/* '<S12>/DrvWinCtl' */
extern MONPRM volatile boolean WinCtl_DrvWinUpProt;/* '<S170>/LIB_CntLimit' */
extern MONPRM volatile boolean WinCtl_DrvWinUpReq;/* '<S171>/Chart3' */
extern MONPRM volatile boolean WinCtl_DrvWinUpSw;/* '<S169>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean WinCtl_J51DrvWinUp;/* '<S164>/Switch1' */
extern MONPRM volatile boolean WinCtl_J53DrvWinDn;/* '<S166>/Switch1' */
extern MONPRM volatile boolean WinCtl_J55PsgWinUp;/* '<S167>/Switch1' */
extern MONPRM volatile boolean WinCtl_J57PsgWinDn;/* '<S165>/Switch1' */
extern MONPRM volatile boolean WinCtl_PsgWinAutoDnReq;/* '<S171>/Chart1' */
extern MONPRM volatile boolean WinCtl_PsgWinAutoDnSw;/* '<S169>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean WinCtl_PsgWinDnProt;/* '<S170>/LIB_CntLimit3' */
extern MONPRM volatile boolean WinCtl_PsgWinDnReq;/* '<S171>/Chart4' */
extern MONPRM volatile boolean WinCtl_PsgWinDnSw;/* '<S169>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean WinCtl_PsgWinMotorLocked;/* '<S171>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WinCtl_PsgWinOvTimProt;/* '<S171>/LIB_PosPluse1' */
extern MONPRM volatile uint8 WinCtl_PsgWinReq;/* '<S171>/Switch10' */
extern MONPRM volatile uint8 WinCtl_PsgWinSta;/* '<S12>/PsgWinCtl' */
extern MONPRM volatile boolean WinCtl_PsgWinUpProt;/* '<S170>/LIB_CntLimit2' */
extern MONPRM volatile boolean WinCtl_PsgWinUpReq;/* '<S171>/Chart5' */
extern MONPRM volatile boolean WinCtl_PsgWinUpSw;/* '<S169>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WiperCtl_HiSpdDrv;/* '<S377>/Switch1' */
extern MONPRM volatile uint16 WiperCtl_InrTim;/* '<S383>/Multiport Switch' */
extern MONPRM volatile boolean WiperCtl_InrTimChg;/* '<S383>/Relational Operator1' */
extern MONPRM volatile boolean WiperCtl_LockedRotorProtSta;/* '<S375>/Logical Operator2' */
extern MONPRM volatile boolean WiperCtl_LowSpdDrv;/* '<S376>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashMotorDrv;/* '<S378>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashSw;/* '<S379>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean WiperCtl_WashWiperSta;/* '<S380>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSta;/* '<S382>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSw;/* '<S379>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WiperCtl_WiperInrSta;/* '<S383>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperInrSw;/* '<S379>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSta;/* '<S384>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSw;/* '<S379>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean WiperCtl_WiperMaintSta;/* '<S424>/Switch' */
extern MONPRM volatile boolean WiperCtl_WiperMistSta;/* '<S386>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperMistSw;/* '<S379>/LIB_TPD_10ms' */
extern MONPRM volatile boolean WiperCtl_WiperOffSta;/* '<S387>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperOffSw;/* '<S379>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WiperCtl_WiperParkPosSw;/* '<S379>/LIB_TPD_10ms6' */
extern MONPRM volatile uint8 WiperCtl_WiperSta;/* '<S381>/Chart' */
extern MONPRM volatile uint8 WiperCtl_WiprIntlTimeSetFb;/* '<S383>/Multiport Switch1' */

#endif                                 /* RTW_HEADER_monPrmsBcm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
