/*
 * File: monPrmsBcm.h
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

#ifndef RTW_HEADER_monPrmsBcm_h_
#define RTW_HEADER_monPrmsBcm_h_
#include "rtwtypes.h"
#include "AppSwcBcm_types.h"

/* Exported data declaration */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Declaration for custom storage class: Volatile */
extern MONPRM volatile boolean AlmSysCtl_AlrmWarnTimOut;/* '<S619>/AlmSysLogic' */
extern MONPRM volatile uint8 AlmSysCtl_BodyWarnSts;/* '<S619>/AlmSysLogic' */
extern MONPRM volatile uint16 BSW_CN744DrvSeatResis;/* '<S1>/C Caller14' */
extern MONPRM volatile uint16 BSW_DrvWinMotorCur;/* '<S1>/C Caller25' */
extern MONPRM volatile uint8 BSW_EEIlluminatedEntrySys;/* '<S4>/C Caller37' */
extern MONPRM volatile uint8 BSW_EEKeyEntry;/* '<S4>/C Caller38' */
extern MONPRM volatile uint8 BSW_FogLampFCfg;/* '<S3>/C Caller1' */
extern MONPRM volatile uint8 BSW_HiBeamDigSts;/* '<S317>/C Caller1' */
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
extern MONPRM volatile uint8 BSW_LowBeamDigSts;/* '<S321>/C Caller' */
extern MONPRM volatile uint16 BSW_PsgWinMotorCur;/* '<S1>/C Caller29' */
extern MONPRM volatile uint8 BSW_RKEReq;/* '<S3>/C Caller32' */
extern MONPRM volatile uint8 BSW_WakeupReas;/* '<S627>/Signal Conversion' */
extern MONPRM volatile boolean BatSaveCtl_DoorChgSta;/* '<S648>/Logical Operator1' */
extern MONPRM volatile boolean BatSaveCtl_DoorLckPwrOff;/* '<S647>/LIB_PosPluse1' */
extern MONPRM volatile boolean BatSaveCtl_DoorUnlckPwrOn;/* '<S648>/Relational Operator1' */
extern MONPRM volatile boolean BatSaveCtl_J64SavePwr;/* '<S646>/Switch1' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOff;/* '<S647>/LIB_PosPluse' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOn;/* '<S648>/Relational Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOff;/* '<S647>/Logical Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOn;/* '<S648>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLck;/* '<S717>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLckSta;/* '<S718>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_CrshUnlck;/* '<S691>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFLSw;/* '<S660>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFRSw;/* '<S660>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRLSw;/* '<S660>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRRSw;/* '<S660>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean DoorLckCtl_DoorProtUnlck;/* '<S663>/LIB_Tim' */
extern MONPRM volatile boolean DoorLckCtl_DriverDoorLckSw;/* '<S660>/LIB_TPD_10ms' */
extern MONPRM volatile boolean DoorLckCtl_DrvPESw;/* '<S660>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean DoorLckCtl_DrvSeatSw;/* '<S660>/LIB_TPD_10ms11' */
extern MONPRM volatile uint8 DoorLckCtl_EEIlluminatedEntrySys;/* '<S660>/Switch14' */
extern MONPRM volatile uint8 DoorLckCtl_EEKeyEntry;/* '<S660>/Switch13' */
extern MONPRM volatile boolean DoorLckCtl_HULck;/* '<S678>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_HUUnLck;/* '<S692>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_HoodAjarSw;/* '<S660>/Constant69' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckSts;/* '<S665>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckStsFb;/* '<S665>/Multiport Switch1' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndSts;/* '<S660>/Switch15' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockSts;/* '<S666>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockStsFb;/* '<S666>/Multiport Switch1' */
extern MONPRM volatile boolean DoorLckCtl_InsLck;/* '<S667>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_InsLckSta;/* '<S622>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_InsUnlck;/* '<S668>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_J511TrunkUnlck;/* '<S658>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J54DoorLck;/* '<S657>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J56DoorUnlck;/* '<S659>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_MechAntiLck;/* '<S663>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechLck;/* '<S710>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechUnlck;/* '<S734>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_MotorProt;/* '<S669>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_OsLck;/* '<S670>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_OsLckSta;/* '<S622>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_OsUnlck;/* '<S671>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PELck;/* '<S711>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_PEUnlck;/* '<S735>/Logical Operator1' */
extern MONPRM volatile uint8 DoorLckCtl_ParkAutoUnlockSetFb;/* '<S673>/Multiport Switch' */
extern MONPRM volatile boolean DoorLckCtl_ParkUnlck;/* '<S693>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PsgPESw;/* '<S660>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean DoorLckCtl_RKEAntiLck;/* '<S663>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_RKELck;/* '<S724>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_RKEUnlck;/* '<S742>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSet;/* '<S674>/Constant8' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSetFb;/* '<S674>/Constant9' */
extern MONPRM volatile boolean DoorLckCtl_SpdLck;/* '<S684>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_ThermRunawayUnlck;/* '<S694>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAjarSw;/* '<S660>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAutoLck;/* '<S729>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_TrunkLckSta;/* '<S622>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkLckSw;/* '<S622>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkRKEUnlck;/* '<S746>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TrunkSw;/* '<S660>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean DoorLckCtl_TrunkUnlck;/* '<S737>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_VehRun;/* '<S660>/Logical Operator4' */
extern MONPRM volatile float32 DoorLckCtl_VehSpd;/* '<S660>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_VehStop;/* '<S660>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeLck;/* '<S714>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeUnlck;/* '<S738>/Logical Operator1' */
extern MONPRM volatile uint8 DynDID_0xF22CAntitheftSta;/* '<S623>/Signal Conversion' */
extern MONPRM volatile uint8 DynDID_0xF230DoorOpRecord[10];/* '<S791>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF231TrunkOpRecord[10];/* '<S792>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF232LocalStartUpFailRecord[10];/* '<S793>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF233RemoteStartUpFailRecord[10];/* '<S794>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF234ADSampleValue[23];/* '<S795>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF235DigtInSampleValue[5];/* '<S796>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF236DigtOutSampleValue[5];/* '<S797>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF237PwrModeSta;/* '<S623>/Signal Conversion1' */
extern MONPRM volatile uint8 EEReadCtl_BackLadjvalFb;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_BodyWarnSts;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_CrashSta;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarFLSw;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarFRSw;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarRLSw;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarRRSw;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorOpRecord[10];/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DriverDoorLckSw;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DrvSeatSw;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_FlwrMeHomeCtlFb;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_HazardLightSta;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_IllmndLckSts;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_IllmndUnlckSts;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_InrTim;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_LocalStartFailOpRecord[10];/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_LockHoornOnSts;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_ParkAutoUnlockSetFb;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_RemoteStartFailRecord[10];/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_SpdCtlLckSet;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkAjarSw;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkLckSw;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkOpRecord[10];/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkSw;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_WiprIntlTimeSetFb;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint64 ESCCtl_UnOrLockfeedback;/* '<S821>/Signal Copy' */
extern MONPRM volatile boolean ESCLCtl_J436Lck;/* '<S821>/ESCLLck' */
extern MONPRM volatile boolean ESCLCtl_J436PwrSup;/* '<S826>/Switch' */
extern MONPRM volatile boolean ESCLCtl_J436Unlck;/* '<S821>/ESCLUnlck' */
extern MONPRM volatile uint8 ESCLCtl_Lck;/* '<S821>/ESCLLck' */
extern MONPRM volatile uint8 ESCLCtl_UnOrLockCrtl;/* '<S821>/Truth Table' */
extern MONPRM volatile uint8 ESCLCtl_Unlck;/* '<S821>/ESCLUnlck' */
extern MONPRM volatile uint8 HornCtl_AlarmSta;/* '<S275>/Alarm' */
extern MONPRM volatile uint8 HornCtl_AntiLckSta;/* '<S276>/AntiLck' */
extern MONPRM volatile uint8 HornCtl_ArmedSta;/* '<S277>/Armed' */
extern MONPRM volatile boolean HornCtl_HornSwCtl;/* '<S279>/LIB_TPD_10ms' */
extern MONPRM volatile boolean HornCtl_J430HornDrv;/* '<S281>/Switch1' */
extern MONPRM volatile uint8 HornCtl_LockHoornOnSt;/* '<S278>/Multiport Switch' */
extern MONPRM volatile uint8 HornCtl_LockHoornOnStFb;/* '<S278>/Multiport Switch1' */
extern MONPRM volatile uint8 HornCtl_PartArmedSta;/* '<S282>/PartArmed' */
extern MONPRM volatile uint8 HornCtl_SeekSta;/* '<S283>/Seek' */
extern MONPRM volatile uint8 HornCtl_TrunkWarnSta;/* '<S284>/Chart' */
extern MONPRM volatile uint8 IMMOCtl_AuthResp[8];/* '<S625>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_INVRandom[8];/* '<S625>/Signal Conversion' */
extern MONPRM volatile uint8 IMMOCtl_SKRead[16];/* '<S625>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_SKSta;/* '<S625>/IMMOCtl' */
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
extern MONPRM volatile boolean LampCtl_AlrmSta;/* '<S437>/Chart' */
extern MONPRM volatile boolean LampCtl_AntiLckSta;/* '<S438>/Chart' */
extern MONPRM volatile boolean LampCtl_ArmedSta;/* '<S439>/Chart' */
extern MONPRM volatile boolean LampCtl_AutoLampSta;/* '<S354>/Switch' */
extern MONPRM volatile boolean LampCtl_AutoLampSw;/* '<S340>/LIB_TPD_10ms8' */
extern MONPRM volatile uint8 LampCtl_BackLadjvalFb;/* '<S311>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_BrakeLightSta;/* '<S329>/Switch1' */
extern MONPRM volatile boolean LampCtl_BrakeLightSw;/* '<S340>/Logical Operator13' */
extern MONPRM volatile boolean LampCtl_CrashSta;/* '<S440>/Chart' */
extern MONPRM volatile boolean LampCtl_DayRunLightSta;/* '<S323>/Switch1' */
extern MONPRM volatile boolean LampCtl_DisarmedSta;/* '<S441>/Chart' */
extern MONPRM volatile boolean LampCtl_DomeLampCloseDoor;/* '<S366>/Logical Operator6' */
extern MONPRM volatile boolean LampCtl_DomeLampCtl;/* '<S367>/Switch' */
extern MONPRM volatile boolean LampCtl_DomeLampFLOpen;/* '<S369>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampFROpen;/* '<S370>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampLockDoor;/* '<S380>/Logical Operator' */
extern MONPRM volatile boolean LampCtl_DomeLampOff;/* '<S315>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOffGrad;/* '<S315>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOn;/* '<S315>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOnGrad;/* '<S315>/Truth Table' */
extern MONPRM volatile uint8 LampCtl_DomeLampPwmDuty;/* '<S324>/Switch1' */
extern MONPRM volatile boolean LampCtl_DomeLampPwrOff;/* '<S373>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampUnlock;/* '<S374>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_EmerHazardLightSta;/* '<S341>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_EmerSta;/* '<S442>/Logical Operator' */
extern MONPRM volatile uint8 LampCtl_FlwrMeHomeCtlFb;/* '<S550>/Multiport Switch1' */
extern MONPRM volatile boolean LampCtl_FlwrMeHomeSta;/* '<S552>/Switch' */
extern MONPRM volatile uint16 LampCtl_FlwrMeHomeTim;/* '<S550>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_FogLampFSta;/* '<S334>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampFSw;/* '<S340>/LIB_TPD_10ms12' */
extern MONPRM volatile boolean LampCtl_FogLampRSta;/* '<S333>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampRSw;/* '<S340>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean LampCtl_HazardLightSta;/* '<S341>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_HazardLightSw;/* '<S340>/LIB_TPD_10ms10' */
extern MONPRM volatile boolean LampCtl_HiBeamShortToBat;/* '<S317>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_HiBeamSta;/* '<S336>/Switch1' */
extern MONPRM volatile boolean LampCtl_HiBeamSw;/* '<S340>/LIB_TPD_10ms2' */
extern MONPRM volatile uint8 LampCtl_J408BackLampPWM;/* '<S328>/Switch1' */
extern MONPRM volatile boolean LampCtl_J420BSDRightCtl;/* '<S330>/Switch1' */
extern MONPRM volatile boolean LampCtl_J422BSDLeftCtl;/* '<S331>/Switch1' */
extern MONPRM volatile boolean LampCtl_J449BoxLamp;/* '<S327>/Switch1' */
extern MONPRM volatile boolean LampCtl_KnobBeamFaultSta;/* '<S318>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_LampDelay;/* '<S393>/Switch' */
extern MONPRM volatile uint8 LampCtl_LightIntstSta;/* '<S320>/Chart' */
extern MONPRM volatile uint16 LampCtl_LightIntstVal;/* '<S340>/Data Type Conversion12' */
extern MONPRM volatile boolean LampCtl_LowBeamShortToBat;/* '<S321>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_LowBeamSta;/* '<S332>/Switch1' */
extern MONPRM volatile boolean LampCtl_LowBeamSw;/* '<S340>/LIB_TPD_10ms1' */
extern MONPRM volatile uint8 LampCtl_PartArmedSta;/* '<S444>/Chart' */
extern MONPRM volatile boolean LampCtl_PassLightSta;/* '<S337>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_PassLightSw;/* '<S340>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_PosLampSta;/* '<S322>/Switch1' */
extern MONPRM volatile boolean LampCtl_PosLampSw;/* '<S340>/LIB_TPD_10ms' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntL;/* '<S451>/LIB_Pulse' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntR;/* '<S453>/LIB_Pulse' */
extern MONPRM volatile uint8 LampCtl_RKEReq;/* '<S340>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_ReverseLampSta;/* '<S335>/Switch1' */
extern MONPRM volatile boolean LampCtl_RodBeamFaultSta;/* '<S446>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_ThermalrunawaySta;/* '<S447>/Chart' */
extern MONPRM volatile boolean LampCtl_TrunkWarnSta;/* '<S448>/Chart' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLFlashCnt;/* '<S341>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLOpen;/* '<S450>/Logical Operator' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLShort;/* '<S450>/Logical Operator2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSta;/* '<S326>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSw;/* '<S340>/LIB_TPD_10ms4' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLVol;/* '<S523>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneLSw;/* '<S340>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneRSw;/* '<S340>/LIB_TPD_10ms7' */
extern MONPRM volatile uint8 LampCtl_TurnIndcrMod;/* '<S341>/TurnIndcrLogic' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrPrd;/* '<S341>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRFlashCnt;/* '<S341>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrROpen;/* '<S450>/Logical Operator1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRShort;/* '<S450>/Logical Operator3' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSta;/* '<S325>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSw;/* '<S340>/LIB_TPD_10ms6' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRVol;/* '<S522>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRst;/* '<S341>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrWdt;/* '<S341>/TurnIndcrArb2' */
extern MONPRM volatile uint8 LampCtl_VehModeSta;/* '<S455>/Chart' */
extern MONPRM volatile boolean LampCtl_VehSeekSta;/* '<S456>/Chart' */
extern MONPRM volatile boolean LampCtl_WelcomeLampSta;/* '<S551>/Switch' */
extern MONPRM volatile boolean PDUCtl_BrkPwrOn;/* '<S841>/Logical Operator1' */
extern MONPRM volatile boolean PDUCtl_DelayTimPwrOff;/* '<S840>/LIB_Tim' */
extern MONPRM volatile boolean PDUCtl_HUPwrOff;/* '<S840>/Logical Operator8' */
extern MONPRM volatile boolean PDUCtl_IG1RelayFault;/* '<S842>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean PDUCtl_IG2RelayFault;/* '<S842>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean PDUCtl_IGRlyIlgCls;/* '<S842>/LIB_TPD_10ms3' */
extern MONPRM volatile uint8 PDUCtl_J421IG1RlyCtl;/* '<S838>/Switch1' */
extern MONPRM volatile uint8 PDUCtl_J437IG2RlyCtl;/* '<S839>/Switch1' */
extern MONPRM volatile boolean PDUCtl_KeyChk;/* '<S841>/Logical Operator5' */
extern MONPRM volatile boolean PDUCtl_OpenDoorPwrOn;/* '<S841>/Logical Operator' */
extern MONPRM volatile boolean PDUCtl_OsLckPwrOff;/* '<S840>/Logical Operator5' */
extern MONPRM volatile boolean PDUCtl_PwrOff;/* '<S840>/Logical Operator6' */
extern MONPRM volatile boolean PDUCtl_PwrOn;/* '<S841>/Logical Operator2' */
extern MONPRM volatile boolean PDUCtl_StartReq;/* '<S870>/Switch' */
extern MONPRM volatile uint8 PDUCtl_SysPowerSts;/* '<S626>/Chart' */
extern MONPRM volatile uint8 PDUCtl_SysPwrMode;/* '<S626>/Truth Table' */
extern MONPRM volatile uint8 PDUCtl_SysPwrModeAct;/* '<S844>/Switch' */
extern MONPRM volatile boolean PDUCtl_SysPwrModeV;/* '<S842>/Switch' */
extern MONPRM volatile uint8 PEPSCtl_AvaluebleKeyInCar;/* '<S209>/Chart3' */
extern MONPRM volatile uint8 PEPSCtl_DrvPEAuthentAcsd;/* '<S209>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_FRPEAuthentAcsd;/* '<S209>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_FrbdnKeyNr;/* '<S207>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_IMMOKey;/* '<S210>/Chart5' */
extern MONPRM volatile uint8 PEPSCtl_IndicationKeyCloser;/* '<S210>/Chart3' */
extern MONPRM volatile uint8 PEPSCtl_KeyInCarSta;/* '<S209>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_KeyLoBattLvlWarn;/* '<S208>/Chart3' */
extern MONPRM volatile uint8 PEPSCtl_KeySta;/* '<S210>/Chart1' */
extern MONPRM volatile uint8 PEPSCtl_LckWlcmReq;/* '<S211>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_PSAuthentRes;/* '<S210>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_PSReq;/* '<S210>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_UnlckWlcmReq;/* '<S211>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_WarnKeyOutReminder;/* '<S208>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_WarnNoKeyFound;/* '<S210>/Chart2' */
extern MONPRM volatile boolean RVMCtl_J42Heat;/* '<S124>/Switch' */
extern MONPRM volatile uint8 SCS_FrntWiprSwtSt;/* '<S234>/Signal Conversion' */
extern MONPRM volatile boolean SCS_FrntWshrSwtSt;/* '<S234>/Signal Conversion1' */
extern MONPRM volatile boolean SCS_FrntWshrSwtStVD;/* '<S234>/Signal Conversion2' */
extern MONPRM volatile boolean SCS_WiprSwtStVD;/* '<S234>/Signal Conversion3' */
extern MONPRM volatile uint8 SeatCtl_CN167DrvSeatHtPWM;/* '<S131>/Switch' */
extern MONPRM volatile sint8 SeatCtl_DrvSeatTemp;/* '<S129>/Data Type Conversion' */
extern MONPRM volatile uint8 SeatCtl_MaiDrvSeatStFb;/* '<S129>/Multiport Switch' */
extern MONPRM volatile boolean SteerWhlCtl_J447SteerWhlHt;/* '<S134>/Switch' */
extern MONPRM volatile uint8 SteerWhlCtl_SteerWhlHeatSts;/* '<S132>/Multiport Switch' */
extern MONPRM volatile sint8 SteerWhlCtl_SteerWhlTemp;/* '<S132>/Data Type Conversion' */
extern MONPRM volatile boolean WakeUpCtl_NMReq;/* '<S885>/Switch' */
extern MONPRM volatile boolean WakeUpCtl_SleepAllwd;/* '<S873>/Logical Operator5' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnSw;/* '<S141>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinDnSw;/* '<S141>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinUpSw;/* '<S141>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean WinCtl_DrvWinAutoDnReq;/* '<S143>/Chart10' */
extern MONPRM volatile boolean WinCtl_DrvWinAutoDnSw;/* '<S141>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WinCtl_DrvWinDnProt;/* '<S142>/LIB_CntLimit1' */
extern MONPRM volatile boolean WinCtl_DrvWinDnReq;/* '<S143>/Chart2' */
extern MONPRM volatile boolean WinCtl_DrvWinDnSw;/* '<S141>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WinCtl_DrvWinMotorLocked;/* '<S143>/LIB_TPD_10ms3' */
extern MONPRM volatile uint8 WinCtl_DrvWinReq;/* '<S143>/Switch11' */
extern MONPRM volatile uint8 WinCtl_DrvWinSta;/* '<S10>/DrvWinCtl' */
extern MONPRM volatile boolean WinCtl_DrvWinUpProt;/* '<S142>/LIB_CntLimit' */
extern MONPRM volatile boolean WinCtl_DrvWinUpReq;/* '<S143>/Chart3' */
extern MONPRM volatile boolean WinCtl_DrvWinUpSw;/* '<S141>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean WinCtl_J51DrvWinUp;/* '<S136>/Switch1' */
extern MONPRM volatile boolean WinCtl_J53DrvWinDn;/* '<S139>/Switch1' */
extern MONPRM volatile boolean WinCtl_J55PsgWinUp;/* '<S137>/Switch' */
extern MONPRM volatile boolean WinCtl_J57PsgWinDn;/* '<S138>/Switch' */
extern MONPRM volatile boolean WinCtl_PsgWinAutoDnReq;/* '<S143>/Chart1' */
extern MONPRM volatile boolean WinCtl_PsgWinAutoDnSw;/* '<S141>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean WinCtl_PsgWinDnProt;/* '<S142>/LIB_CntLimit3' */
extern MONPRM volatile boolean WinCtl_PsgWinDnReq;/* '<S143>/Chart4' */
extern MONPRM volatile boolean WinCtl_PsgWinDnSw;/* '<S141>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean WinCtl_PsgWinMotorLocked;/* '<S143>/LIB_TPD_10ms1' */
extern MONPRM volatile uint8 WinCtl_PsgWinReq;/* '<S143>/Switch10' */
extern MONPRM volatile uint8 WinCtl_PsgWinSta;/* '<S10>/PsgWinCtl' */
extern MONPRM volatile boolean WinCtl_PsgWinUpProt;/* '<S142>/LIB_CntLimit2' */
extern MONPRM volatile boolean WinCtl_PsgWinUpReq;/* '<S143>/Chart5' */
extern MONPRM volatile boolean WinCtl_PsgWinUpSw;/* '<S141>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WiperCtl_HiSpdDrv;/* '<S568>/Switch1' */
extern MONPRM volatile uint16 WiperCtl_InrTim;/* '<S574>/Multiport Switch' */
extern MONPRM volatile boolean WiperCtl_InrTimChg;/* '<S574>/Relational Operator1' */
extern MONPRM volatile boolean WiperCtl_LockedRotorProtSta;/* '<S566>/Logical Operator2' */
extern MONPRM volatile boolean WiperCtl_LowSpdDrv;/* '<S567>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashMotorDrv;/* '<S569>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashSw;/* '<S570>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean WiperCtl_WashWiperSta;/* '<S571>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSta;/* '<S573>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSw;/* '<S570>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WiperCtl_WiperInrSta;/* '<S574>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperInrSw;/* '<S570>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSta;/* '<S575>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSw;/* '<S570>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean WiperCtl_WiperMaintSta;/* '<S613>/Switch' */
extern MONPRM volatile boolean WiperCtl_WiperMistSta;/* '<S577>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperMistSw;/* '<S570>/LIB_TPD_10ms' */
extern MONPRM volatile boolean WiperCtl_WiperOffSta;/* '<S578>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperOffSw;/* '<S570>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WiperCtl_WiperParkPosSw;/* '<S570>/LIB_TPD_10ms6' */
extern MONPRM volatile uint8 WiperCtl_WiperSta;/* '<S572>/Chart' */
extern MONPRM volatile uint8 WiperCtl_WiprIntlTimeSetFb;/* '<S574>/Multiport Switch1' */

#endif                                 /* RTW_HEADER_monPrmsBcm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
