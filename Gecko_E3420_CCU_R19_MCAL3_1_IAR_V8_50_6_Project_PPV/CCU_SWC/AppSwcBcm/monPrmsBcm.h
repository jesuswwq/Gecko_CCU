/*
 * File: monPrmsBcm.h
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1421
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Oct  9 16:23:34 2024
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
extern MONPRM volatile boolean AlmSysCtl_AlrmWarnTimOut;/* '<S620>/AlmSysLogic' */
extern MONPRM volatile uint8 AlmSysCtl_BodyWarnSts;/* '<S620>/AlmSysLogic' */
extern MONPRM volatile uint16 BSW_CN744DrvSeatResis;/* '<S1>/C Caller14' */
extern MONPRM volatile uint16 BSW_DrvWinMotorCur;/* '<S1>/C Caller25' */
extern MONPRM volatile uint8 BSW_EEIlluminatedEntrySys;/* '<S4>/C Caller37' */
extern MONPRM volatile uint8 BSW_EEKeyEntry;/* '<S4>/C Caller38' */
extern MONPRM volatile uint8 BSW_FogLampFCfg;/* '<S3>/C Caller1' */
extern MONPRM volatile uint8 BSW_HiBeamDigSts;/* '<S315>/C Caller1' */
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
extern MONPRM volatile uint8 BSW_LowBeamDigSts;/* '<S319>/C Caller' */
extern MONPRM volatile uint16 BSW_PsgWinMotorCur;/* '<S1>/C Caller29' */
extern MONPRM volatile uint8 BSW_RKEReq;/* '<S3>/C Caller32' */
extern MONPRM volatile uint8 BSW_WakeupReas;/* '<S628>/Signal Conversion' */
extern MONPRM volatile boolean BatSaveCtl_DoorChgSta;/* '<S649>/Logical Operator1' */
extern MONPRM volatile boolean BatSaveCtl_DoorLckPwrOff;/* '<S648>/LIB_PosPluse1' */
extern MONPRM volatile boolean BatSaveCtl_DoorUnlckPwrOn;/* '<S649>/Relational Operator1' */
extern MONPRM volatile boolean BatSaveCtl_J64SavePwr;/* '<S647>/Switch1' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOff;/* '<S648>/LIB_PosPluse' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOn;/* '<S649>/Relational Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOff;/* '<S648>/Logical Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOn;/* '<S649>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLck;/* '<S718>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLckSta;/* '<S719>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_CrshUnlck;/* '<S692>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFLSw;/* '<S661>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFRSw;/* '<S661>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRLSw;/* '<S661>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRRSw;/* '<S661>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean DoorLckCtl_DoorProtUnlck;/* '<S664>/LIB_Tim' */
extern MONPRM volatile boolean DoorLckCtl_DriverDoorLckSw;/* '<S661>/LIB_TPD_10ms' */
extern MONPRM volatile boolean DoorLckCtl_DrvPESw;/* '<S661>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean DoorLckCtl_DrvSeatSw;/* '<S661>/LIB_TPD_10ms11' */
extern MONPRM volatile uint8 DoorLckCtl_EEIlluminatedEntrySys;/* '<S661>/Switch14' */
extern MONPRM volatile uint8 DoorLckCtl_EEKeyEntry;/* '<S661>/Switch13' */
extern MONPRM volatile boolean DoorLckCtl_HULck;/* '<S679>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_HUUnLck;/* '<S693>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_HoodAjarSw;/* '<S661>/Constant69' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckSts;/* '<S666>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckStsFb;/* '<S666>/Multiport Switch1' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndSts;/* '<S661>/Switch15' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockSts;/* '<S667>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockStsFb;/* '<S667>/Multiport Switch1' */
extern MONPRM volatile boolean DoorLckCtl_InsLck;/* '<S668>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_InsLckSta;/* '<S623>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_InsUnlck;/* '<S669>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_J511TrunkUnlck;/* '<S659>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J54DoorLck;/* '<S658>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J56DoorUnlck;/* '<S660>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_MechAntiLck;/* '<S664>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechLck;/* '<S711>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechUnlck;/* '<S733>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_MotorProt;/* '<S670>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_OsLck;/* '<S671>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_OsLckSta;/* '<S623>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_OsUnlck;/* '<S672>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PELck;/* '<S712>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_PEUnlck;/* '<S734>/Logical Operator1' */
extern MONPRM volatile uint8 DoorLckCtl_ParkAutoUnlockSetFb;/* '<S674>/Multiport Switch' */
extern MONPRM volatile boolean DoorLckCtl_ParkUnlck;/* '<S694>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PsgPESw;/* '<S661>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean DoorLckCtl_RKEAntiLck;/* '<S664>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_RKELck;/* '<S725>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_RKEUnlck;/* '<S741>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSet;/* '<S675>/Constant8' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSetFb;/* '<S675>/Constant9' */
extern MONPRM volatile boolean DoorLckCtl_SpdLck;/* '<S685>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_ThermRunawayUnlck;/* '<S695>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAjarSw;/* '<S661>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAutoLck;/* '<S729>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TrunkHUUnlck;/* '<S746>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_TrunkLckSta;/* '<S623>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkLckSw;/* '<S623>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkRKEUnlck;/* '<S745>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TrunkSw;/* '<S661>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean DoorLckCtl_TrunkUnlck;/* '<S736>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_VehRun;/* '<S661>/Logical Operator4' */
extern MONPRM volatile float32 DoorLckCtl_VehSpd;/* '<S661>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_VehStop;/* '<S661>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeLck;/* '<S715>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeUnlck;/* '<S737>/Logical Operator1' */
extern MONPRM volatile uint8 DynDID_0xF22CAntitheftSta;/* '<S624>/Signal Conversion' */
extern MONPRM volatile uint8 DynDID_0xF230DoorOpRecord[10];/* '<S790>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF231TrunkOpRecord[10];/* '<S791>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF232LocalStartUpFailRecord[10];/* '<S792>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF233RemoteStartUpFailRecord[10];/* '<S793>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF234ADSampleValue[23];/* '<S794>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF235DigtInSampleValue[5];/* '<S795>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF236DigtOutSampleValue[5];/* '<S796>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF237PwrModeSta;/* '<S624>/Signal Conversion1' */
extern MONPRM volatile uint8 EEReadCtl_BackLadjvalFb;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_BodyWarnSts;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_CrashSta;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorOpRecord[10];/* '<S231>/EEReadCtl' */
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
extern MONPRM volatile uint8 EEReadCtl_TrunkLckSw;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkOpRecord[10];/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_WiprIntlTimeSetFb;/* '<S231>/EEReadCtl' */
extern MONPRM volatile uint64 ESCCtl_UnOrLockfeedback;/* '<S820>/Signal Copy' */
extern MONPRM volatile boolean ESCLCtl_J436Lck;/* '<S820>/ESCLLck' */
extern MONPRM volatile boolean ESCLCtl_J436PwrSup;/* '<S825>/Switch' */
extern MONPRM volatile boolean ESCLCtl_J436Unlck;/* '<S820>/ESCLUnlck' */
extern MONPRM volatile uint8 ESCLCtl_Lck;/* '<S820>/ESCLLck' */
extern MONPRM volatile uint8 ESCLCtl_UnOrLockCrtl;/* '<S820>/Truth Table' */
extern MONPRM volatile uint8 ESCLCtl_Unlck;/* '<S820>/ESCLUnlck' */
extern MONPRM volatile uint8 HornCtl_AlarmSta;/* '<S273>/Alarm' */
extern MONPRM volatile uint8 HornCtl_AntiLckSta;/* '<S274>/AntiLck' */
extern MONPRM volatile uint8 HornCtl_ArmedSta;/* '<S275>/Armed' */
extern MONPRM volatile boolean HornCtl_HornSwCtl;/* '<S277>/LIB_TPD_10ms' */
extern MONPRM volatile boolean HornCtl_J430HornDrv;/* '<S279>/Switch1' */
extern MONPRM volatile uint8 HornCtl_LockHoornOnSt;/* '<S276>/Multiport Switch' */
extern MONPRM volatile uint8 HornCtl_LockHoornOnStFb;/* '<S276>/Multiport Switch1' */
extern MONPRM volatile uint8 HornCtl_PartArmedSta;/* '<S280>/PartArmed' */
extern MONPRM volatile uint8 HornCtl_SeekSta;/* '<S281>/Seek' */
extern MONPRM volatile uint8 HornCtl_TrunkWarnSta;/* '<S282>/Chart' */
extern MONPRM volatile uint8 IMMOCtl_AuthResp[8];/* '<S626>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_INVRandom[8];/* '<S626>/Signal Conversion' */
extern MONPRM volatile uint8 IMMOCtl_SKRead[16];/* '<S626>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_SKSta;/* '<S626>/IMMOCtl' */
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
extern MONPRM volatile boolean LampCtl_AlrmSta;/* '<S435>/Chart' */
extern MONPRM volatile boolean LampCtl_AntiLckSta;/* '<S436>/Chart' */
extern MONPRM volatile boolean LampCtl_ArmedSta;/* '<S437>/Chart' */
extern MONPRM volatile boolean LampCtl_AutoLampSta;/* '<S352>/Switch' */
extern MONPRM volatile boolean LampCtl_AutoLampSw;/* '<S338>/LIB_TPD_10ms8' */
extern MONPRM volatile uint8 LampCtl_BackLadjvalFb;/* '<S309>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_BrakeLightSta;/* '<S327>/Switch1' */
extern MONPRM volatile boolean LampCtl_BrakeLightSw;/* '<S338>/Logical Operator13' */
extern MONPRM volatile boolean LampCtl_CrashSta;/* '<S438>/Chart' */
extern MONPRM volatile boolean LampCtl_DayRunLightSta;/* '<S321>/Switch1' */
extern MONPRM volatile boolean LampCtl_DisarmedSta;/* '<S439>/Chart' */
extern MONPRM volatile boolean LampCtl_DomeLampCloseDoor;/* '<S364>/Logical Operator6' */
extern MONPRM volatile boolean LampCtl_DomeLampCtl;/* '<S365>/Switch' */
extern MONPRM volatile boolean LampCtl_DomeLampFLOpen;/* '<S367>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampFROpen;/* '<S368>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampLockDoor;/* '<S378>/Logical Operator' */
extern MONPRM volatile boolean LampCtl_DomeLampOff;/* '<S313>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOffGrad;/* '<S313>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOn;/* '<S313>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOnGrad;/* '<S313>/Truth Table' */
extern MONPRM volatile uint8 LampCtl_DomeLampPwmDuty;/* '<S322>/Switch1' */
extern MONPRM volatile boolean LampCtl_DomeLampPwrOff;/* '<S371>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampUnlock;/* '<S372>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_EmerHazardLightSta;/* '<S339>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_EmerSta;/* '<S440>/Logical Operator' */
extern MONPRM volatile uint8 LampCtl_FlwrMeHomeCtlFb;/* '<S548>/Multiport Switch1' */
extern MONPRM volatile boolean LampCtl_FlwrMeHomeSta;/* '<S550>/Switch' */
extern MONPRM volatile uint16 LampCtl_FlwrMeHomeTim;/* '<S548>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_FogLampFSta;/* '<S332>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampFSw;/* '<S338>/LIB_TPD_10ms12' */
extern MONPRM volatile boolean LampCtl_FogLampRSta;/* '<S331>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampRSw;/* '<S338>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean LampCtl_HazardLightSta;/* '<S339>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_HazardLightSw;/* '<S338>/LIB_TPD_10ms10' */
extern MONPRM volatile boolean LampCtl_HiBeamShortToBat;/* '<S315>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_HiBeamSta;/* '<S334>/Switch1' */
extern MONPRM volatile boolean LampCtl_HiBeamSw;/* '<S338>/LIB_TPD_10ms2' */
extern MONPRM volatile uint8 LampCtl_J408BackLampPWM;/* '<S326>/Switch1' */
extern MONPRM volatile boolean LampCtl_J420BSDRightCtl;/* '<S328>/Switch1' */
extern MONPRM volatile boolean LampCtl_J422BSDLeftCtl;/* '<S329>/Switch1' */
extern MONPRM volatile boolean LampCtl_J449BoxLamp;/* '<S325>/Switch1' */
extern MONPRM volatile boolean LampCtl_KnobBeamFaultSta;/* '<S316>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_LampDelay;/* '<S391>/Switch' */
extern MONPRM volatile uint8 LampCtl_LightIntstSta;/* '<S318>/Chart' */
extern MONPRM volatile uint16 LampCtl_LightIntstVal;/* '<S338>/Data Type Conversion12' */
extern MONPRM volatile boolean LampCtl_LowBeamShortToBat;/* '<S319>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_LowBeamSta;/* '<S330>/Switch1' */
extern MONPRM volatile boolean LampCtl_LowBeamSw;/* '<S338>/LIB_TPD_10ms1' */
extern MONPRM volatile uint8 LampCtl_PartArmedSta;/* '<S442>/Chart' */
extern MONPRM volatile boolean LampCtl_PassLightSta;/* '<S335>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_PassLightSw;/* '<S338>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_PosLampSta;/* '<S320>/Switch1' */
extern MONPRM volatile boolean LampCtl_PosLampSw;/* '<S338>/LIB_TPD_10ms' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntL;/* '<S449>/LIB_Pulse' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntR;/* '<S451>/LIB_Pulse' */
extern MONPRM volatile uint8 LampCtl_RKEReq;/* '<S338>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_ReverseLampSta;/* '<S333>/Switch1' */
extern MONPRM volatile boolean LampCtl_RodBeamFaultSta;/* '<S444>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_ThermalrunawaySta;/* '<S445>/Chart' */
extern MONPRM volatile boolean LampCtl_TrunkWarnSta;/* '<S446>/Chart' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLFlashCnt;/* '<S339>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLOpen;/* '<S448>/Logical Operator' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLShort;/* '<S448>/Logical Operator2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSta;/* '<S324>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSw;/* '<S338>/LIB_TPD_10ms4' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLVol;/* '<S521>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneLSw;/* '<S338>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneRSw;/* '<S338>/LIB_TPD_10ms7' */
extern MONPRM volatile uint8 LampCtl_TurnIndcrMod;/* '<S339>/TurnIndcrLogic' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrPrd;/* '<S339>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRFlashCnt;/* '<S339>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrROpen;/* '<S448>/Logical Operator1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRShort;/* '<S448>/Logical Operator3' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSta;/* '<S323>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSw;/* '<S338>/LIB_TPD_10ms6' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRVol;/* '<S520>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRst;/* '<S339>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrWdt;/* '<S339>/TurnIndcrArb2' */
extern MONPRM volatile uint8 LampCtl_VehModeSta;/* '<S453>/Chart' */
extern MONPRM volatile boolean LampCtl_VehSeekSta;/* '<S454>/Chart' */
extern MONPRM volatile boolean LampCtl_WelcomeLampSta;/* '<S549>/Switch' */
extern MONPRM volatile boolean PDUCtl_IG1RelayFault;/* '<S841>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean PDUCtl_IG2RelayFault;/* '<S841>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean PDUCtl_IGRlyIlgCls;/* '<S841>/LIB_TPD_10ms3' */
extern MONPRM volatile uint8 PDUCtl_J421IG1RlyCtl;/* '<S837>/Switch1' */
extern MONPRM volatile uint8 PDUCtl_J437IG2RlyCtl;/* '<S838>/Switch1' */
extern MONPRM volatile boolean PDUCtl_PwrOff;/* '<S839>/Logical Operator6' */
extern MONPRM volatile boolean PDUCtl_PwrOn;/* '<S840>/Logical Operator2' */
extern MONPRM volatile boolean PDUCtl_StartReq;/* '<S869>/Switch' */
extern MONPRM volatile uint8 PDUCtl_SysPowerSts;/* '<S627>/Chart' */
extern MONPRM volatile uint8 PDUCtl_SysPwrMode;/* '<S627>/Truth Table' */
extern MONPRM volatile uint8 PDUCtl_SysPwrModeAct;/* '<S843>/Switch' */
extern MONPRM volatile boolean PDUCtl_SysPwrModeV;/* '<S841>/Switch' */
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
extern MONPRM volatile boolean WakeUpCtl_NMReq;/* '<S883>/Switch' */
extern MONPRM volatile boolean WakeUpCtl_SleepAllwd;/* '<S872>/Logical Operator5' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnSw;/* '<S141>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinDnSw;/* '<S141>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinUpSw;/* '<S141>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean WinCtl_DrvWinAutoDnReq;/* '<S143>/Chart' */
extern MONPRM volatile boolean WinCtl_DrvWinAutoDnSw;/* '<S141>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WinCtl_DrvWinDnProt;/* '<S142>/LIB_CntLimit1' */
extern MONPRM volatile boolean WinCtl_DrvWinDnReq;/* '<S143>/Chart2' */
extern MONPRM volatile boolean WinCtl_DrvWinDnSw;/* '<S141>/LIB_TPD_10ms1' */
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
extern MONPRM volatile uint8 WinCtl_PsgWinReq;/* '<S143>/Switch10' */
extern MONPRM volatile uint8 WinCtl_PsgWinSta;/* '<S10>/PsgWinCtl' */
extern MONPRM volatile boolean WinCtl_PsgWinUpProt;/* '<S142>/LIB_CntLimit2' */
extern MONPRM volatile boolean WinCtl_PsgWinUpReq;/* '<S143>/Chart5' */
extern MONPRM volatile boolean WinCtl_PsgWinUpSw;/* '<S141>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WiperCtl_HiSpdDrv;/* '<S569>/Switch1' */
extern MONPRM volatile uint16 WiperCtl_InrTim;/* '<S575>/Multiport Switch' */
extern MONPRM volatile boolean WiperCtl_InrTimChg;/* '<S575>/Relational Operator1' */
extern MONPRM volatile boolean WiperCtl_LockedRotorProtSta;/* '<S567>/Logical Operator2' */
extern MONPRM volatile boolean WiperCtl_LowSpdDrv;/* '<S568>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashMotorDrv;/* '<S570>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashSw;/* '<S571>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean WiperCtl_WashWiperSta;/* '<S572>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSta;/* '<S574>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSw;/* '<S571>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WiperCtl_WiperInrSta;/* '<S575>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperInrSw;/* '<S571>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSta;/* '<S576>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSw;/* '<S571>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean WiperCtl_WiperMaintSta;/* '<S614>/Switch' */
extern MONPRM volatile boolean WiperCtl_WiperMistSta;/* '<S578>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperMistSw;/* '<S571>/LIB_TPD_10ms' */
extern MONPRM volatile boolean WiperCtl_WiperOffSta;/* '<S579>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperOffSw;/* '<S571>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WiperCtl_WiperParkPosSw;/* '<S571>/LIB_TPD_10ms6' */
extern MONPRM volatile uint8 WiperCtl_WiperSta;/* '<S573>/Chart' */
extern MONPRM volatile uint8 WiperCtl_WiprIntlTimeSetFb;/* '<S575>/Multiport Switch1' */

#endif                                 /* RTW_HEADER_monPrmsBcm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
