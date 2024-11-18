/*
 * File: monPrmsBcm.h
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1500
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Wed Nov 13 14:02:59 2024
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
extern MONPRM volatile boolean AlmSysCtl_AlrmWarnTimOut;/* '<S636>/AlmSysLogic' */
extern MONPRM volatile uint8 AlmSysCtl_BodyWarnSts;/* '<S636>/AlmSysLogic' */
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
extern MONPRM volatile uint8 BSW_WakeupReas;/* '<S644>/Signal Conversion' */
extern MONPRM volatile boolean BatSaveCtl_DoorChgSta;/* '<S665>/Logical Operator1' */
extern MONPRM volatile boolean BatSaveCtl_DoorLckPwrOff;/* '<S664>/LIB_PosPluse1' */
extern MONPRM volatile boolean BatSaveCtl_DoorUnlckPwrOn;/* '<S665>/Relational Operator1' */
extern MONPRM volatile boolean BatSaveCtl_J64SavePwr;/* '<S663>/Switch1' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOff;/* '<S664>/LIB_PosPluse' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOn;/* '<S665>/Relational Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOff;/* '<S664>/Logical Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOn;/* '<S665>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLck;/* '<S736>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLckSta;/* '<S737>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_CrshUnlck;/* '<S709>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFLSw;/* '<S677>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFRSw;/* '<S677>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRLSw;/* '<S677>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRRSw;/* '<S677>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean DoorLckCtl_DoorProtUnlck;/* '<S680>/LIB_Tim' */
extern MONPRM volatile boolean DoorLckCtl_DriverDoorLckSw;/* '<S677>/LIB_TPD_10ms' */
extern MONPRM volatile boolean DoorLckCtl_DrvPESw;/* '<S677>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean DoorLckCtl_DrvSeatSw;/* '<S677>/LIB_TPD_10ms11' */
extern MONPRM volatile uint8 DoorLckCtl_EEIlluminatedEntrySys;/* '<S677>/Switch14' */
extern MONPRM volatile uint8 DoorLckCtl_EEKeyEntry;/* '<S677>/Switch13' */
extern MONPRM volatile boolean DoorLckCtl_HULck;/* '<S696>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_HUUnLck;/* '<S710>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_HoodAjarSw;/* '<S677>/Constant69' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckSts;/* '<S682>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckStsFb;/* '<S682>/Multiport Switch1' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndSts;/* '<S677>/Switch15' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockSts;/* '<S683>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockStsFb;/* '<S683>/Multiport Switch1' */
extern MONPRM volatile boolean DoorLckCtl_InsLck;/* '<S684>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_InsLckSta;/* '<S639>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_InsUnlck;/* '<S685>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_J511TrunkUnlck;/* '<S675>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J54DoorLck;/* '<S674>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J56DoorUnlck;/* '<S676>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_MechAntiLck;/* '<S680>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechLck;/* '<S728>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechUnlck;/* '<S754>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_MotorProt;/* '<S686>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_OsLck;/* '<S687>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_OsLckSta;/* '<S639>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_OsUnlck;/* '<S688>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PELck;/* '<S729>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_PEUnlck;/* '<S755>/Logical Operator1' */
extern MONPRM volatile uint8 DoorLckCtl_ParkAutoUnlockSetFb;/* '<S690>/Multiport Switch' */
extern MONPRM volatile boolean DoorLckCtl_ParkUnlck;/* '<S711>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PsgPESw;/* '<S677>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean DoorLckCtl_RKEAntiLck;/* '<S680>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_RKELck;/* '<S743>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_RKEUnlck;/* '<S763>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_RemoteLockFb;/* '<S692>/Chart' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSet;/* '<S691>/Constant8' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSetFb;/* '<S691>/Constant9' */
extern MONPRM volatile boolean DoorLckCtl_SpdLck;/* '<S702>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TboxLck;/* '<S746>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TboxUnlck;/* '<S766>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_ThermRunawayUnlck;/* '<S712>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAjarSw;/* '<S677>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAutoLck;/* '<S749>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_TrunkLckSta;/* '<S639>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkLckSw;/* '<S639>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkRKEUnlck;/* '<S768>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TrunkSw;/* '<S677>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean DoorLckCtl_TrunkTboxUnlck;/* '<S770>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TrunkUnlck;/* '<S758>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_VehRun;/* '<S677>/Logical Operator4' */
extern MONPRM volatile float32 DoorLckCtl_VehSpd;/* '<S677>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_VehStop;/* '<S677>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeLck;/* '<S733>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeUnlck;/* '<S759>/Logical Operator1' */
extern MONPRM volatile uint8 DynDID_0xF22CAntitheftSta;/* '<S640>/Signal Conversion' */
extern MONPRM volatile uint8 DynDID_0xF230DoorOpRecord[10];/* '<S817>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF231TrunkOpRecord[10];/* '<S818>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF232LocalStartUpFailRecord[10];/* '<S819>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF233RemoteStartUpFailRecord[10];/* '<S820>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF234ADSampleValue[23];/* '<S821>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF235DigtInSampleValue[5];/* '<S822>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF236DigtOutSampleValue[5];/* '<S823>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF237PwrModeSta;/* '<S640>/Signal Conversion1' */
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
extern MONPRM volatile uint64 ESCCtl_UnOrLockfeedback;/* '<S847>/Signal Copy' */
extern MONPRM volatile boolean ESCLCtl_J436Lck;/* '<S847>/ESCLLck' */
extern MONPRM volatile boolean ESCLCtl_J436PwrSup;/* '<S852>/Switch' */
extern MONPRM volatile boolean ESCLCtl_J436Unlck;/* '<S847>/ESCLUnlck' */
extern MONPRM volatile uint8 ESCLCtl_Lck;/* '<S847>/ESCLLck' */
extern MONPRM volatile uint8 ESCLCtl_UnOrLockCrtl;/* '<S847>/Truth Table' */
extern MONPRM volatile uint8 ESCLCtl_Unlck;/* '<S847>/ESCLUnlck' */
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
extern MONPRM volatile uint8 IMMOCtl_AuthResp[8];/* '<S642>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_INVRandom[8];/* '<S642>/Signal Conversion' */
extern MONPRM volatile uint8 IMMOCtl_SKRead[16];/* '<S642>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_SKSta;/* '<S642>/IMMOCtl' */
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
extern MONPRM volatile boolean LampCtl_AlrmSta;/* '<S449>/Chart' */
extern MONPRM volatile boolean LampCtl_AntiLckSta;/* '<S450>/Chart' */
extern MONPRM volatile boolean LampCtl_ArmedSta;/* '<S451>/Chart' */
extern MONPRM volatile boolean LampCtl_AutoLampSta;/* '<S364>/Switch' */
extern MONPRM volatile boolean LampCtl_AutoLampSw;/* '<S350>/LIB_TPD_10ms8' */
extern MONPRM volatile uint8 LampCtl_BackLadjvalFb;/* '<S321>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_BrakeLightSta;/* '<S339>/Switch1' */
extern MONPRM volatile boolean LampCtl_BrakeLightSw;/* '<S350>/Logical Operator13' */
extern MONPRM volatile boolean LampCtl_CrashSta;/* '<S452>/Chart' */
extern MONPRM volatile boolean LampCtl_DayRunLightSta;/* '<S333>/Switch1' */
extern MONPRM volatile boolean LampCtl_DisarmedSta;/* '<S453>/Chart' */
extern MONPRM volatile boolean LampCtl_DomeLampCloseDoor;/* '<S376>/Logical Operator6' */
extern MONPRM volatile boolean LampCtl_DomeLampCtl;/* '<S377>/Switch' */
extern MONPRM volatile boolean LampCtl_DomeLampFLOpen;/* '<S379>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampFROpen;/* '<S380>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampLockDoor;/* '<S392>/Logical Operator' */
extern MONPRM volatile boolean LampCtl_DomeLampOff;/* '<S325>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOffGrad;/* '<S325>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOn;/* '<S325>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOnGrad;/* '<S325>/Truth Table' */
extern MONPRM volatile uint8 LampCtl_DomeLampPwmDuty;/* '<S334>/Switch1' */
extern MONPRM volatile boolean LampCtl_DomeLampPwrOff;/* '<S385>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampUnlock;/* '<S386>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_EmerHazardLightSta;/* '<S351>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_EmerSta;/* '<S454>/Logical Operator' */
extern MONPRM volatile uint8 LampCtl_FlwrMeHomeCtlFb;/* '<S567>/Multiport Switch1' */
extern MONPRM volatile boolean LampCtl_FlwrMeHomeSta;/* '<S569>/Switch' */
extern MONPRM volatile uint16 LampCtl_FlwrMeHomeTim;/* '<S567>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_FogLampFSta;/* '<S344>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampFSw;/* '<S350>/LIB_TPD_10ms12' */
extern MONPRM volatile boolean LampCtl_FogLampRSta;/* '<S343>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampRSw;/* '<S350>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean LampCtl_HazardLightSta;/* '<S351>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_HazardLightSw;/* '<S350>/LIB_TPD_10ms10' */
extern MONPRM volatile boolean LampCtl_HiBeamShortToBat;/* '<S327>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_HiBeamSta;/* '<S346>/Switch1' */
extern MONPRM volatile boolean LampCtl_HiBeamSw;/* '<S350>/LIB_TPD_10ms2' */
extern MONPRM volatile uint8 LampCtl_J408BackLampPWM;/* '<S338>/Switch1' */
extern MONPRM volatile boolean LampCtl_J420BSDRightCtl;/* '<S340>/Switch1' */
extern MONPRM volatile boolean LampCtl_J422BSDLeftCtl;/* '<S341>/Switch1' */
extern MONPRM volatile boolean LampCtl_J449BoxLamp;/* '<S337>/Switch1' */
extern MONPRM volatile boolean LampCtl_KnobBeamFaultSta;/* '<S328>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_LampDelay;/* '<S405>/Switch' */
extern MONPRM volatile uint8 LampCtl_LightIntstSta;/* '<S330>/Chart' */
extern MONPRM volatile uint16 LampCtl_LightIntstVal;/* '<S350>/Data Type Conversion12' */
extern MONPRM volatile boolean LampCtl_LowBeamShortToBat;/* '<S331>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_LowBeamSta;/* '<S342>/Switch1' */
extern MONPRM volatile boolean LampCtl_LowBeamSw;/* '<S350>/LIB_TPD_10ms1' */
extern MONPRM volatile uint8 LampCtl_PartArmedSta;/* '<S456>/Chart' */
extern MONPRM volatile boolean LampCtl_PassLightSta;/* '<S347>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_PassLightSw;/* '<S350>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_PosLampSta;/* '<S332>/Switch1' */
extern MONPRM volatile boolean LampCtl_PosLampSw;/* '<S350>/LIB_TPD_10ms' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntL;/* '<S463>/LIB_Pulse' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntR;/* '<S465>/LIB_Pulse' */
extern MONPRM volatile uint8 LampCtl_RKEReq;/* '<S350>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_ReverseLampSta;/* '<S345>/Switch1' */
extern MONPRM volatile boolean LampCtl_RodBeamFaultSta;/* '<S458>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_ThermalrunawaySta;/* '<S459>/Chart' */
extern MONPRM volatile boolean LampCtl_TrunkWarnSta;/* '<S460>/Chart' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLFlashCnt;/* '<S351>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLOpen;/* '<S462>/Logical Operator' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLShort;/* '<S462>/Logical Operator2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSta;/* '<S336>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSw;/* '<S350>/LIB_TPD_10ms4' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLVol;/* '<S535>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneLSw;/* '<S350>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneRSw;/* '<S350>/LIB_TPD_10ms7' */
extern MONPRM volatile uint8 LampCtl_TurnIndcrMod;/* '<S351>/TurnIndcrLogic' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrPrd;/* '<S351>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRFlashCnt;/* '<S351>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrROpen;/* '<S462>/Logical Operator1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRShort;/* '<S462>/Logical Operator3' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSta;/* '<S335>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSw;/* '<S350>/LIB_TPD_10ms6' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRVol;/* '<S534>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRst;/* '<S351>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrWdt;/* '<S351>/TurnIndcrArb2' */
extern MONPRM volatile uint8 LampCtl_VehModeSta;/* '<S467>/Chart' */
extern MONPRM volatile uint8 LampCtl_VehSeekSta;/* '<S468>/Chart' */
extern MONPRM volatile uint8 LampCtl_VehSeekStaFb;/* '<S468>/SeekFb' */
extern MONPRM volatile boolean LampCtl_WelcomeLampSta;/* '<S568>/Switch' */
extern MONPRM volatile boolean PDUCtl_BrkPwrOn;/* '<S867>/Logical Operator1' */
extern MONPRM volatile boolean PDUCtl_DelayTimPwrOff;/* '<S866>/LIB_Tim' */
extern MONPRM volatile boolean PDUCtl_EmerPwrOff;/* '<S866>/Logical Operator13' */
extern MONPRM volatile boolean PDUCtl_HUPwrOff;/* '<S866>/Logical Operator8' */
extern MONPRM volatile boolean PDUCtl_IG1RelayFault;/* '<S868>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean PDUCtl_IG2RelayFault;/* '<S868>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean PDUCtl_IGRlyIlgCls;/* '<S868>/LIB_TPD_10ms3' */
extern MONPRM volatile uint8 PDUCtl_J421IG1RlyCtl;/* '<S864>/Switch1' */
extern MONPRM volatile uint8 PDUCtl_J437IG2RlyCtl;/* '<S865>/Switch1' */
extern MONPRM volatile boolean PDUCtl_KeyChk;/* '<S867>/Logical Operator5' */
extern MONPRM volatile boolean PDUCtl_OpenDoorPwrOn;/* '<S867>/Logical Operator' */
extern MONPRM volatile boolean PDUCtl_OsLckPwrOff;/* '<S866>/Logical Operator5' */
extern MONPRM volatile boolean PDUCtl_PwrOff;/* '<S866>/Logical Operator6' */
extern MONPRM volatile boolean PDUCtl_PwrOn;/* '<S867>/Logical Operator10' */
extern MONPRM volatile boolean PDUCtl_RemotePwrLckFb;/* '<S891>/Switch' */
extern MONPRM volatile uint8 PDUCtl_RemotePwrLckSta;/* '<S867>/RemoteLck' */
extern MONPRM volatile boolean PDUCtl_RemtOverTimPwrOff;/* '<S866>/LIB_Tim1' */
extern MONPRM volatile boolean PDUCtl_RemtPasvPwrOff;/* '<S866>/Logical Operator16' */
extern MONPRM volatile uint8 PDUCtl_RemtPwrCtlFb;/* '<S643>/RemtPwrCtlFb' */
extern MONPRM volatile boolean PDUCtl_RemtPwrOff;/* '<S866>/Logical Operator12' */
extern MONPRM volatile boolean PDUCtl_RemtPwrOn;/* '<S867>/Logical Operator9' */
extern MONPRM volatile boolean PDUCtl_StartReq;/* '<S907>/Switch' */
extern MONPRM volatile uint8 PDUCtl_SysPowerSts;/* '<S643>/Chart' */
extern MONPRM volatile uint8 PDUCtl_SysPwrMode;/* '<S643>/Truth Table' */
extern MONPRM volatile uint8 PDUCtl_SysPwrModeAct;/* '<S871>/Switch' */
extern MONPRM volatile boolean PDUCtl_SysPwrModeV;/* '<S868>/Switch' */
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
extern MONPRM volatile boolean WakeUpCtl_NMReq;/* '<S922>/Switch' */
extern MONPRM volatile boolean WakeUpCtl_SleepAllwd;/* '<S910>/Logical Operator5' */
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
extern MONPRM volatile boolean WiperCtl_HiSpdDrv;/* '<S585>/Switch1' */
extern MONPRM volatile uint16 WiperCtl_InrTim;/* '<S591>/Multiport Switch' */
extern MONPRM volatile boolean WiperCtl_InrTimChg;/* '<S591>/Relational Operator1' */
extern MONPRM volatile boolean WiperCtl_LockedRotorProtSta;/* '<S583>/Logical Operator2' */
extern MONPRM volatile boolean WiperCtl_LowSpdDrv;/* '<S584>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashMotorDrv;/* '<S586>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashSw;/* '<S587>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean WiperCtl_WashWiperSta;/* '<S588>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSta;/* '<S590>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSw;/* '<S587>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WiperCtl_WiperInrSta;/* '<S591>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperInrSw;/* '<S587>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSta;/* '<S592>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSw;/* '<S587>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean WiperCtl_WiperMaintSta;/* '<S630>/Switch' */
extern MONPRM volatile boolean WiperCtl_WiperMistSta;/* '<S594>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperMistSw;/* '<S587>/LIB_TPD_10ms' */
extern MONPRM volatile boolean WiperCtl_WiperOffSta;/* '<S595>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperOffSw;/* '<S587>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WiperCtl_WiperParkPosSw;/* '<S587>/LIB_TPD_10ms6' */
extern MONPRM volatile uint8 WiperCtl_WiperSta;/* '<S589>/Chart' */
extern MONPRM volatile uint8 WiperCtl_WiprIntlTimeSetFb;/* '<S591>/Multiport Switch1' */

#endif                                 /* RTW_HEADER_monPrmsBcm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
