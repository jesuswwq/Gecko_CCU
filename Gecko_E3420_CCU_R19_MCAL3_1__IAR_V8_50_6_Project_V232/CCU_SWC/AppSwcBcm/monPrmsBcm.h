/*
 * File: monPrmsBcm.h
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

#ifndef RTW_HEADER_monPrmsBcm_h_
#define RTW_HEADER_monPrmsBcm_h_
#include "rtwtypes.h"
#include "AppSwcBcm_types.h"

/* Exported data declaration */

/* Volatile memory section */
#include "XcpTest_types.h"

/* Declaration for custom storage class: Volatile */
extern MONPRM volatile boolean AlmSysCtl_AlrmWarnTimOut;/* '<S598>/AlmSysLogic' */
extern MONPRM volatile uint8 AlmSysCtl_BodyWarnSts;/* '<S598>/AlmSysLogic' */
extern MONPRM volatile uint16 BSW_CN744DrvSeatResis;/* '<S1>/C Caller14' */
extern MONPRM volatile uint16 BSW_DrvWinMotorCur;/* '<S1>/C Caller25' */
extern MONPRM volatile uint8 BSW_EEIlluminatedEntrySys;/* '<S4>/C Caller37' */
extern MONPRM volatile uint8 BSW_EEKeyEntry;/* '<S4>/C Caller38' */
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
extern MONPRM volatile uint16 BSW_PsgWinMotorCur;/* '<S1>/C Caller29' */
extern MONPRM volatile uint8 BSW_RKEReq;/* '<S3>/C Caller32' */
extern MONPRM volatile uint8 BSW_WakeupReas;/* '<S605>/Signal Conversion' */
extern MONPRM volatile boolean BatSaveCtl_DoorChgSta;/* '<S626>/Logical Operator1' */
extern MONPRM volatile boolean BatSaveCtl_DoorLckPwrOff;/* '<S625>/LIB_NegPluse6' */
extern MONPRM volatile boolean BatSaveCtl_DoorUnlckPwrOn;/* '<S635>/Logical Operator' */
extern MONPRM volatile boolean BatSaveCtl_J64SavePwr;/* '<S624>/Switch1' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOff;/* '<S625>/LIB_PosPluse' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOn;/* '<S626>/Relational Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOff;/* '<S625>/Logical Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOn;/* '<S626>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLck;/* '<S698>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLckSta;/* '<S699>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_CrshUnlck;/* '<S672>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFLSw;/* '<S641>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFRSw;/* '<S641>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRLSw;/* '<S641>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRRSw;/* '<S641>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean DoorLckCtl_DoorProtUnlck;/* '<S644>/LIB_Tim' */
extern MONPRM volatile boolean DoorLckCtl_DriverDoorLckSw;/* '<S641>/LIB_TPD_10ms' */
extern MONPRM volatile boolean DoorLckCtl_DrvPESw;/* '<S641>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean DoorLckCtl_DrvSeatSw;/* '<S641>/LIB_TPD_10ms11' */
extern MONPRM volatile uint8 DoorLckCtl_EEIlluminatedEntrySys;/* '<S641>/Switch14' */
extern MONPRM volatile uint8 DoorLckCtl_EEKeyEntry;/* '<S641>/Switch13' */
extern MONPRM volatile boolean DoorLckCtl_HULck;/* '<S659>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_HUUnLck;/* '<S673>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_HoodAjarSw;/* '<S641>/Constant69' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckSts;/* '<S646>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckStsFb;/* '<S646>/Multiport Switch1' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndSts;/* '<S641>/Switch15' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockSts;/* '<S647>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockStsFb;/* '<S647>/Multiport Switch1' */
extern MONPRM volatile boolean DoorLckCtl_InsLck;/* '<S648>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_InsLckSta;/* '<S601>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_InsUnlck;/* '<S649>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_J511TrunkUnlck;/* '<S639>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J54DoorLck;/* '<S638>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J56DoorUnlck;/* '<S640>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_MechAntiLck;/* '<S644>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechLck;/* '<S691>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechUnlck;/* '<S713>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_MotorProt;/* '<S650>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_OsLck;/* '<S651>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_OsLckSta;/* '<S601>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_OsUnlck;/* '<S652>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PELck;/* '<S692>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_PEUnlck;/* '<S714>/Logical Operator1' */
extern MONPRM volatile uint8 DoorLckCtl_ParkAutoUnlockSetFb;/* '<S654>/Multiport Switch' */
extern MONPRM volatile boolean DoorLckCtl_ParkUnlck;/* '<S674>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PsgPESw;/* '<S641>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean DoorLckCtl_RKEAntiLck;/* '<S644>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_RKELck;/* '<S705>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_RKEUnlck;/* '<S721>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSet;/* '<S655>/Constant8' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSetFb;/* '<S655>/Constant9' */
extern MONPRM volatile boolean DoorLckCtl_SpdLck;/* '<S665>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_ThermRunawayUnlck;/* '<S675>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAjarSw;/* '<S641>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAutoLck;/* '<S709>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_TrunkLckSta;/* '<S601>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkLckSw;/* '<S601>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkRKEUnlck;/* '<S725>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TrunkSw;/* '<S641>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean DoorLckCtl_TrunkUnlck;/* '<S716>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_VehRun;/* '<S641>/Logical Operator4' */
extern MONPRM volatile float32 DoorLckCtl_VehSpd;/* '<S641>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_VehStop;/* '<S641>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeLck;/* '<S695>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeUnlck;/* '<S717>/Logical Operator1' */
extern MONPRM volatile uint8 EEReadCtl_BackLadjvalFb;/* '<S218>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_BodyWarnSts;/* '<S218>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_CrashSta;/* '<S218>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_FlwrMeHomeCtlFb;/* '<S218>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_HazardLightSta;/* '<S218>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_IllmndLckSts;/* '<S218>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_IllmndUnlckSts;/* '<S218>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_InrTim;/* '<S218>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_LockHoornOnSts;/* '<S218>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_ParkAutoUnlockSetFb;/* '<S218>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_SpdCtlLckSet;/* '<S218>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_WiprIntlTimeSetFb;/* '<S218>/EEReadCtl' */
extern MONPRM volatile boolean ESCLCtl_J436Lck;/* '<S768>/ESCLLck' */
extern MONPRM volatile boolean ESCLCtl_J436PwrSup;/* '<S773>/Switch' */
extern MONPRM volatile boolean ESCLCtl_J436Unlck;/* '<S768>/ESCLUnlck' */
extern MONPRM volatile uint8 ESCLCtl_Lck;/* '<S768>/ESCLLck' */
extern MONPRM volatile uint8 ESCLCtl_UnOrLockCrtl;/* '<S768>/Truth Table' */
extern MONPRM volatile uint8 ESCLCtl_Unlck;/* '<S768>/ESCLUnlck' */
extern MONPRM volatile uint8 HornCtl_AlarmSta;/* '<S262>/Alarm' */
extern MONPRM volatile uint8 HornCtl_AntiLckSta;/* '<S263>/AntiLck' */
extern MONPRM volatile uint8 HornCtl_ArmedSta;/* '<S264>/Armed' */
extern MONPRM volatile boolean HornCtl_HornSwCtl;/* '<S266>/LIB_TPD_10ms' */
extern MONPRM volatile boolean HornCtl_J430HornDrv;/* '<S268>/Switch1' */
extern MONPRM volatile uint8 HornCtl_LockHoornOnSt;/* '<S265>/Multiport Switch' */
extern MONPRM volatile uint8 HornCtl_LockHoornOnStFb;/* '<S265>/Multiport Switch1' */
extern MONPRM volatile uint8 HornCtl_PartArmedSta;/* '<S269>/PartArmed' */
extern MONPRM volatile uint8 HornCtl_SeekSta;/* '<S270>/Seek' */
extern MONPRM volatile uint8 HornCtl_TrunkWarnSta;/* '<S271>/Chart' */
extern MONPRM volatile uint8 IMMOCtl_AuthResp[8];/* '<S603>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_INVRandom[8];/* '<S603>/Signal Conversion' */
extern MONPRM volatile uint8 IMMOCtl_SKRead[16];/* '<S603>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_SKSta;/* '<S603>/IMMOCtl' */
extern MONPRM volatile uint8 IODID_BSDLeftCtlFlg;/* '<S5>/Bitwise AND44' */
extern MONPRM volatile uint8 IODID_BSDRightCtlFlg;/* '<S5>/Bitwise AND43' */
extern MONPRM volatile uint8 IODID_BackLampCtlFlg;/* '<S5>/Bitwise AND2' */
extern MONPRM volatile uint8 IODID_BatSaveCtlFlg;/* '<S5>/Bitwise AND42' */
extern MONPRM volatile uint8 IODID_BrakeLightCtlFlg;/* '<S5>/Bitwise AND3' */
extern MONPRM volatile uint8 IODID_DayRunLightCtlFlg;/* '<S5>/Bitwise AND6' */
extern MONPRM volatile uint8 IODID_DomeLampCtlFlg;/* '<S5>/Bitwise AND9' */
extern MONPRM volatile uint8 IODID_DoorLckCtlFlg;/* '<S5>/Bitwise AND17' */
extern MONPRM volatile uint8 IODID_DoorUnlckCtlFlg;/* '<S5>/Bitwise AND16' */
extern MONPRM volatile uint8 IODID_FogLampFCtlFlg;/* '<S5>/Bitwise AND14' */
extern MONPRM volatile uint8 IODID_FogLampRCtlFlg;/* '<S5>/Bitwise AND15' */
extern MONPRM volatile uint8 IODID_HiBeamCtlFlg;/* '<S5>/Bitwise AND13' */
extern MONPRM volatile uint8 IODID_HornCtlFlg;/* '<S5>/Bitwise AND40' */
extern MONPRM volatile uint8 IODID_IG1RlyCtlFlg;/* '<S5>/Bitwise AND46' */
extern MONPRM volatile uint8 IODID_IG2RlyCtlFlg;/* '<S5>/Bitwise AND47' */
extern MONPRM volatile uint8 IODID_LowBeamCtlFlg;/* '<S5>/Bitwise AND12' */
extern MONPRM volatile uint8 IODID_PosLampCtlFlg;/* '<S5>/Bitwise AND7' */
extern MONPRM volatile uint8 IODID_ReverseLampCtlFlg;/* '<S5>/Bitwise AND5' */
extern MONPRM volatile uint8 IODID_TrunkUnlckCtlFlg;/* '<S5>/Bitwise AND22' */
extern MONPRM volatile uint8 IODID_TurnIndcrLCtlFlg;/* '<S5>/Bitwise AND' */
extern MONPRM volatile uint8 IODID_TurnIndcrRCtlFlg;/* '<S5>/Bitwise AND1' */
extern MONPRM volatile uint8 IODID_WinFLCtlFlg;/* '<S5>/Bitwise AND32' */
extern MONPRM volatile uint8 IODID_WinFRCtlFlg;/* '<S5>/Bitwise AND33' */
extern MONPRM volatile uint8 IODID_WiperHiSpdCtlFlg;/* '<S5>/Bitwise AND30' */
extern MONPRM volatile uint8 IODID_WiperLowSpdCtlFlg;/* '<S5>/Bitwise AND31' */
extern MONPRM volatile boolean LampCtl_AlrmSta;/* '<S419>/Chart' */
extern MONPRM volatile boolean LampCtl_AntiLckSta;/* '<S420>/Chart' */
extern MONPRM volatile boolean LampCtl_ArmedSta;/* '<S421>/Chart' */
extern MONPRM volatile boolean LampCtl_AutoLampSta;/* '<S341>/Switch' */
extern MONPRM volatile boolean LampCtl_AutoLampSw;/* '<S327>/LIB_TPD_10ms8' */
extern MONPRM volatile uint8 LampCtl_BackLadjvalFb;/* '<S298>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_BrakeLightSta;/* '<S316>/Switch1' */
extern MONPRM volatile boolean LampCtl_BrakeLightSw;/* '<S327>/Logical Operator13' */
extern MONPRM volatile boolean LampCtl_CrashSta;/* '<S422>/Chart' */
extern MONPRM volatile boolean LampCtl_DayRunLightSta;/* '<S310>/Switch1' */
extern MONPRM volatile boolean LampCtl_DisarmedSta;/* '<S423>/Chart' */
extern MONPRM volatile boolean LampCtl_DomeLampCloseDoor;/* '<S353>/Logical Operator6' */
extern MONPRM volatile boolean LampCtl_DomeLampCtl;/* '<S354>/Switch' */
extern MONPRM volatile boolean LampCtl_DomeLampFLOpen;/* '<S356>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampFROpen;/* '<S357>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampLockDoor;/* '<S353>/Relational Operator4' */
extern MONPRM volatile boolean LampCtl_DomeLampOff;/* '<S302>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOffGrad;/* '<S302>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOn;/* '<S302>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOnGrad;/* '<S302>/Truth Table' */
extern MONPRM volatile uint8 LampCtl_DomeLampPwmDuty;/* '<S311>/Switch1' */
extern MONPRM volatile boolean LampCtl_DomeLampPwrOff;/* '<S360>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampUnlock;/* '<S361>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_EmerHazardLightSta;/* '<S328>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_EmerSta;/* '<S424>/Logical Operator' */
extern MONPRM volatile uint8 LampCtl_FlwrMeHomeCtlFb;/* '<S526>/Multiport Switch1' */
extern MONPRM volatile boolean LampCtl_FlwrMeHomeSta;/* '<S528>/Switch' */
extern MONPRM volatile uint16 LampCtl_FlwrMeHomeTim;/* '<S526>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_FogLampFSta;/* '<S321>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampFSw;/* '<S327>/LIB_TPD_10ms12' */
extern MONPRM volatile boolean LampCtl_FogLampRSta;/* '<S320>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampRSw;/* '<S327>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean LampCtl_HazardLightSta;/* '<S328>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_HazardLightSw;/* '<S327>/LIB_TPD_10ms10' */
extern MONPRM volatile boolean LampCtl_HiBeamSta;/* '<S323>/Switch1' */
extern MONPRM volatile boolean LampCtl_HiBeamSw;/* '<S327>/LIB_TPD_10ms2' */
extern MONPRM volatile uint8 LampCtl_J408BackLampPWM;/* '<S315>/Switch1' */
extern MONPRM volatile boolean LampCtl_J420BSDRightCtl;/* '<S317>/Switch1' */
extern MONPRM volatile boolean LampCtl_J422BSDLeftCtl;/* '<S318>/Switch1' */
extern MONPRM volatile boolean LampCtl_J449BoxLamp;/* '<S314>/Switch1' */
extern MONPRM volatile boolean LampCtl_KnobBeamFaultSta;/* '<S305>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_LampDelay;/* '<S376>/Switch' */
extern MONPRM volatile uint8 LampCtl_LightIntstSta;/* '<S307>/Chart' */
extern MONPRM volatile uint16 LampCtl_LightIntstVal;/* '<S327>/Data Type Conversion12' */
extern MONPRM volatile boolean LampCtl_LowBeamSta;/* '<S319>/Switch1' */
extern MONPRM volatile boolean LampCtl_LowBeamSw;/* '<S327>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean LampCtl_PartArmedSta;/* '<S426>/Chart' */
extern MONPRM volatile boolean LampCtl_PassLightSta;/* '<S324>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_PassLightSw;/* '<S327>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_PosLampSta;/* '<S309>/Switch1' */
extern MONPRM volatile boolean LampCtl_PosLampSw;/* '<S327>/LIB_TPD_10ms' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntL;/* '<S433>/LIB_Pulse' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntR;/* '<S435>/LIB_Pulse' */
extern MONPRM volatile uint8 LampCtl_RKEReq;/* '<S327>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_ReverseLampSta;/* '<S322>/Switch1' */
extern MONPRM volatile boolean LampCtl_RodBeamFaultSta;/* '<S428>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_ThermalrunawaySta;/* '<S429>/Chart' */
extern MONPRM volatile boolean LampCtl_TrunkWarnSta;/* '<S430>/Chart' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLFlashCnt;/* '<S328>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLOpen;/* '<S432>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLShort;/* '<S432>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSta;/* '<S313>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSw;/* '<S327>/LIB_TPD_10ms4' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLVol;/* '<S432>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneLSw;/* '<S327>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneRSw;/* '<S327>/LIB_TPD_10ms7' */
extern MONPRM volatile uint8 LampCtl_TurnIndcrMod;/* '<S328>/TurnIndcrLogic' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrPrd;/* '<S328>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRFlashCnt;/* '<S328>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrROpen;/* '<S432>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRShort;/* '<S432>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSta;/* '<S312>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSw;/* '<S327>/LIB_TPD_10ms6' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRVol;/* '<S432>/C Caller1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRst;/* '<S328>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrWdt;/* '<S328>/TurnIndcrArb2' */
extern MONPRM volatile uint8 LampCtl_VehModeSta;/* '<S437>/Chart' */
extern MONPRM volatile boolean LampCtl_VehSeekSta;/* '<S438>/Chart' */
extern MONPRM volatile boolean LampCtl_WelcomeLampSta;/* '<S527>/Switch' */
extern MONPRM volatile boolean PDUCtl_IG1RelayFault;/* '<S789>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean PDUCtl_IG2RelayFault;/* '<S789>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean PDUCtl_IGRlyIlgCls;/* '<S789>/LIB_TPD_10ms3' */
extern MONPRM volatile uint8 PDUCtl_J421IG1RlyCtl;/* '<S785>/Switch1' */
extern MONPRM volatile uint8 PDUCtl_J437IG2RlyCtl;/* '<S786>/Switch1' */
extern MONPRM volatile boolean PDUCtl_PwrOff;/* '<S787>/Logical Operator6' */
extern MONPRM volatile boolean PDUCtl_PwrOn;/* '<S788>/Logical Operator2' */
extern MONPRM volatile boolean PDUCtl_StartReq;/* '<S815>/Switch' */
extern MONPRM volatile uint8 PDUCtl_SysPowerSts;/* '<S604>/Chart' */
extern MONPRM volatile uint8 PDUCtl_SysPwrMode;/* '<S604>/Truth Table' */
extern MONPRM volatile uint8 PDUCtl_SysPwrModeAct;/* '<S791>/Switch' */
extern MONPRM volatile boolean PDUCtl_SysPwrModeV;/* '<S789>/Switch' */
extern MONPRM volatile uint8 PEPSCtl_AvaluebleKeyInCar;/* '<S195>/Chart3' */
extern MONPRM volatile uint8 PEPSCtl_DrvPEAuthentAcsd;/* '<S195>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_FRPEAuthentAcsd;/* '<S195>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_FrbdnKeyNr;/* '<S193>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_IMMOKey;/* '<S196>/Chart5' */
extern MONPRM volatile uint8 PEPSCtl_IndicationKeyCloser;/* '<S196>/Chart3' */
extern MONPRM volatile uint8 PEPSCtl_KeyInCarSta;/* '<S195>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_KeyLoBattLvlWarn;/* '<S194>/Chart3' */
extern MONPRM volatile uint8 PEPSCtl_KeySta;/* '<S196>/Chart1' */
extern MONPRM volatile uint8 PEPSCtl_LckWlcmReq;/* '<S197>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_PSAuthentRes;/* '<S196>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_PSReq;/* '<S196>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_UnlckWlcmReq;/* '<S197>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_WarnKeyOutReminder;/* '<S194>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_WarnNoKeyFound;/* '<S196>/Chart2' */
extern MONPRM volatile boolean RVMCtl_J42Heat;/* '<S122>/Switch' */
extern MONPRM volatile uint8 SCS_FrntWiprSwtSt;/* '<S222>/Signal Conversion' */
extern MONPRM volatile boolean SCS_FrntWshrSwtSt;/* '<S222>/Signal Conversion1' */
extern MONPRM volatile boolean SCS_FrntWshrSwtStVD;/* '<S222>/Signal Conversion2' */
extern MONPRM volatile boolean SCS_WiprSwtStVD;/* '<S222>/Signal Conversion3' */
extern MONPRM volatile uint8 SeatCtl_CN167DrvSeatHtPWM;/* '<S129>/Switch' */
extern MONPRM volatile sint8 SeatCtl_DrvSeatTemp;/* '<S127>/Data Type Conversion' */
extern MONPRM volatile uint8 SeatCtl_MaiDrvSeatStFb;/* '<S127>/Multiport Switch' */
extern MONPRM volatile boolean SteerWhlCtl_J447SteerWhlHt;/* '<S132>/Switch' */
extern MONPRM volatile uint8 SteerWhlCtl_SteerWhlHeatSts;/* '<S130>/Multiport Switch' */
extern MONPRM volatile sint8 SteerWhlCtl_SteerWhlTemp;/* '<S130>/Data Type Conversion' */
extern MONPRM volatile boolean WakeUpCtl_NMReq;/* '<S829>/Switch' */
extern MONPRM volatile boolean WakeUpCtl_SleepAllwd;/* '<S818>/Logical Operator5' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnSw;/* '<S139>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinDnSw;/* '<S139>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinUpSw;/* '<S139>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean WinCtl_DrvWinAutoDnReq;/* '<S141>/Chart' */
extern MONPRM volatile boolean WinCtl_DrvWinAutoDnSw;/* '<S139>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WinCtl_DrvWinDnProt;/* '<S140>/LIB_CntLimit1' */
extern MONPRM volatile boolean WinCtl_DrvWinDnReq;/* '<S141>/Chart2' */
extern MONPRM volatile boolean WinCtl_DrvWinDnSw;/* '<S139>/LIB_TPD_10ms1' */
extern MONPRM volatile uint8 WinCtl_DrvWinReq;/* '<S141>/Switch11' */
extern MONPRM volatile uint8 WinCtl_DrvWinSta;/* '<S9>/DrvWinCtl' */
extern MONPRM volatile boolean WinCtl_DrvWinUpProt;/* '<S140>/LIB_CntLimit' */
extern MONPRM volatile boolean WinCtl_DrvWinUpReq;/* '<S141>/Chart3' */
extern MONPRM volatile boolean WinCtl_DrvWinUpSw;/* '<S139>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean WinCtl_J51DrvWinUp;/* '<S134>/Switch1' */
extern MONPRM volatile boolean WinCtl_J53DrvWinDn;/* '<S137>/Switch1' */
extern MONPRM volatile boolean WinCtl_J55PsgWinUp;/* '<S135>/Switch' */
extern MONPRM volatile boolean WinCtl_J57PsgWinDn;/* '<S136>/Switch' */
extern MONPRM volatile boolean WinCtl_PsgWinAutoDnReq;/* '<S141>/Chart1' */
extern MONPRM volatile boolean WinCtl_PsgWinAutoDnSw;/* '<S139>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean WinCtl_PsgWinDnProt;/* '<S140>/LIB_CntLimit3' */
extern MONPRM volatile boolean WinCtl_PsgWinDnReq;/* '<S141>/Chart4' */
extern MONPRM volatile boolean WinCtl_PsgWinDnSw;/* '<S139>/LIB_TPD_10ms5' */
extern MONPRM volatile uint8 WinCtl_PsgWinReq;/* '<S141>/Switch10' */
extern MONPRM volatile uint8 WinCtl_PsgWinSta;/* '<S9>/PsgWinCtl' */
extern MONPRM volatile boolean WinCtl_PsgWinUpProt;/* '<S140>/LIB_CntLimit2' */
extern MONPRM volatile boolean WinCtl_PsgWinUpReq;/* '<S141>/Chart5' */
extern MONPRM volatile boolean WinCtl_PsgWinUpSw;/* '<S139>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WinCtl_WinDnRKEReq;/* '<S141>/Logical Operator9' */
extern MONPRM volatile boolean WinCtl_WinUpRKEReq;/* '<S141>/Logical Operator3' */
extern MONPRM volatile boolean WiperCtl_HiSpdDrv;/* '<S547>/Switch1' */
extern MONPRM volatile uint16 WiperCtl_InrTim;/* '<S553>/Multiport Switch' */
extern MONPRM volatile boolean WiperCtl_InrTimChg;/* '<S553>/Relational Operator1' */
extern MONPRM volatile boolean WiperCtl_LockedRotorProtSta;/* '<S545>/Logical Operator2' */
extern MONPRM volatile boolean WiperCtl_LowSpdDrv;/* '<S546>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashMotorDrv;/* '<S548>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashSw;/* '<S549>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean WiperCtl_WashWiperSta;/* '<S550>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSta;/* '<S552>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSw;/* '<S549>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WiperCtl_WiperInrSta;/* '<S553>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperInrSw;/* '<S549>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSta;/* '<S554>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSw;/* '<S549>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean WiperCtl_WiperMaintSta;/* '<S592>/Switch' */
extern MONPRM volatile boolean WiperCtl_WiperMistSta;/* '<S556>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperMistSw;/* '<S549>/LIB_TPD_10ms' */
extern MONPRM volatile boolean WiperCtl_WiperOffSta;/* '<S557>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperOffSw;/* '<S549>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WiperCtl_WiperParkPosSw;/* '<S549>/LIB_TPD_10ms6' */
extern MONPRM volatile uint8 WiperCtl_WiperSta;/* '<S551>/Chart' */
extern MONPRM volatile uint8 WiperCtl_WiprIntlTimeSetFb;/* '<S553>/Multiport Switch1' */

#endif                                 /* RTW_HEADER_monPrmsBcm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
