/*
 * File: monPrmsBcm.h
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1537
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Dec 30 17:33:19 2024
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
extern MONPRM volatile boolean AlmSysCtl_AlrmWarnTimOut;/* '<S405>/AlmSysLogic' */
extern MONPRM volatile uint8 AlmSysCtl_BodyWarnSts;/* '<S405>/AlmSysLogic' */
extern MONPRM volatile uint16 BSW_CN744DrvSeatResis;/* '<S1>/C Caller14' */
extern MONPRM volatile uint8 BSW_CrashPWMSta;/* '<S4>/C Caller15' */
extern MONPRM volatile uint16 BSW_DrvWinMotorCur;/* '<S1>/C Caller25' */
extern MONPRM volatile uint8 BSW_EEIlluminatedEntrySys;/* '<S4>/C Caller37' */
extern MONPRM volatile uint8 BSW_EEKeyEntry;/* '<S4>/C Caller38' */
extern MONPRM volatile uint8 BSW_FogLampFCfg;/* '<S4>/C Caller3' */
extern MONPRM volatile uint8 BSW_HiBeamDigSts;/* '<S629>/C Caller1' */
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
extern MONPRM volatile uint8 BSW_LowBeamDigSts;/* '<S633>/C Caller' */
extern MONPRM volatile uint16 BSW_PsgWinMotorCur;/* '<S1>/C Caller29' */
extern MONPRM volatile uint8 BSW_RKEReq;/* '<S4>/C Caller32' */
extern MONPRM volatile uint8 BSW_WakeupReas;/* '<S413>/Signal Conversion' */
extern MONPRM volatile boolean BatSaveCtl_DoorChgSta;/* '<S434>/Logical Operator1' */
extern MONPRM volatile boolean BatSaveCtl_DoorLckPwrOff;/* '<S433>/LIB_PosPluse1' */
extern MONPRM volatile boolean BatSaveCtl_DoorUnlckPwrOn;/* '<S434>/Relational Operator1' */
extern MONPRM volatile boolean BatSaveCtl_J64SavePwr;/* '<S432>/Switch1' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOff;/* '<S433>/LIB_PosPluse' */
extern MONPRM volatile boolean BatSaveCtl_PwrModeOn;/* '<S434>/Relational Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOff;/* '<S433>/Logical Operator' */
extern MONPRM volatile boolean BatSaveCtl_PwrOn;/* '<S434>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLck;/* '<S498>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_AutoLckSta;/* '<S499>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_CrshUnlck;/* '<S472>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFLSw;/* '<S446>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarFRSw;/* '<S446>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRLSw;/* '<S446>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean DoorLckCtl_DoorAjarRRSw;/* '<S446>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean DoorLckCtl_DoorProtUnlck;/* '<S449>/LIB_Tim' */
extern MONPRM volatile boolean DoorLckCtl_DriverDoorLckSw;/* '<S446>/LIB_TPD_10ms' */
extern MONPRM volatile boolean DoorLckCtl_DrvPESw;/* '<S446>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean DoorLckCtl_DrvSeatSw;/* '<S446>/LIB_TPD_10ms11' */
extern MONPRM volatile uint8 DoorLckCtl_EEIlluminatedEntrySys;/* '<S446>/Switch14' */
extern MONPRM volatile uint8 DoorLckCtl_EEKeyEntry;/* '<S446>/Switch13' */
extern MONPRM volatile boolean DoorLckCtl_HULck;/* '<S465>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_HUUnLck;/* '<S473>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_HoodAjarSw;/* '<S446>/Constant69' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckSts;/* '<S451>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndLckStsFb;/* '<S451>/Multiport Switch1' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndSts;/* '<S446>/Switch15' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockSts;/* '<S452>/Multiport Switch' */
extern MONPRM volatile uint8 DoorLckCtl_IllmndUnlockStsFb;/* '<S452>/Multiport Switch1' */
extern MONPRM volatile boolean DoorLckCtl_InsLck;/* '<S453>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_InsLckSta;/* '<S407>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_InsUnlck;/* '<S454>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_J511TrunkUnlck;/* '<S444>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J54DoorLck;/* '<S443>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_J56DoorUnlck;/* '<S445>/Switch1' */
extern MONPRM volatile boolean DoorLckCtl_MechAntiLck;/* '<S449>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechLck;/* '<S490>/Logical Operator3' */
extern MONPRM volatile boolean DoorLckCtl_MechUnlck;/* '<S512>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_MotorProt;/* '<S455>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_OsLck;/* '<S456>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_OsLckSta;/* '<S407>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_OsUnlck;/* '<S457>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PELck;/* '<S491>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_PEUnlck;/* '<S513>/Logical Operator1' */
extern MONPRM volatile uint8 DoorLckCtl_ParkAutoUnlockSetFb;/* '<S459>/Multiport Switch' */
extern MONPRM volatile boolean DoorLckCtl_ParkUnlck;/* '<S474>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_PsgPESw;/* '<S446>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean DoorLckCtl_RKEAntiLck;/* '<S449>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_RKELck;/* '<S505>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_RKEUnlck;/* '<S522>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_RemoteLockFb;/* '<S461>/Chart' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSet;/* '<S460>/Constant8' */
extern MONPRM volatile uint8 DoorLckCtl_SpdCtlLckSetFb;/* '<S460>/Constant9' */
extern MONPRM volatile boolean DoorLckCtl_SpdLck;/* '<S471>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TboxLck;/* '<S508>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TboxUnlck;/* '<S525>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_ThermRunawayUnlck;/* '<S475>/Chart' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAjarSw;/* '<S446>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean DoorLckCtl_TrunkAutoLck;/* '<S510>/Logical Operator' */
extern MONPRM volatile uint8 DoorLckCtl_TrunkLckSta;/* '<S407>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkLckSw;/* '<S407>/DoorDrv' */
extern MONPRM volatile boolean DoorLckCtl_TrunkRKEUnlck;/* '<S527>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TrunkSw;/* '<S446>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean DoorLckCtl_TrunkTboxUnlck;/* '<S529>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_TrunkUnlck;/* '<S516>/Logical Operator' */
extern MONPRM volatile boolean DoorLckCtl_VehRun;/* '<S446>/Logical Operator4' */
extern MONPRM volatile float32 DoorLckCtl_VehSpd;/* '<S446>/Switch' */
extern MONPRM volatile boolean DoorLckCtl_VehStop;/* '<S446>/Logical Operator1' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeLck;/* '<S495>/Logical Operator2' */
extern MONPRM volatile boolean DoorLckCtl_WelcomeUnlck;/* '<S517>/Logical Operator1' */
extern MONPRM volatile uint8 DynDID_0xF22BFobInformation[16];/* '<S408>/Constant27' */
extern MONPRM volatile uint8 DynDID_0xF22CAntitheftSta;/* '<S408>/Signal Conversion' */
extern MONPRM volatile uint8 DynDID_0xF230DoorOpRecord[10];/* '<S576>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF231TrunkOpRecord[10];/* '<S577>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF232LocalStartUpFailRecord[10];/* '<S578>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF233RemoteStartUpFailRecord[10];/* '<S579>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF234ADSampleValue[23];/* '<S580>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF235DigtInSampleValue[5];/* '<S581>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF236DigtOutSampleValue[5];/* '<S582>/Chart' */
extern MONPRM volatile uint8 DynDID_0xF237PwrModeSta;/* '<S408>/Signal Conversion1' */
extern MONPRM volatile uint8 EEReadCtl_BackLadjvalFb;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_BodyWarnSts;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_CrashSta;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarFLSw;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarFRSw;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarRLSw;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorAjarRRSw;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DoorOpRecord[10];/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DriverDoorLckSw;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_DrvSeatSw;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_FlwrMeHomeCtlFb;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_HazardLightSta;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_IllmndLckSts;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_IllmndUnlckSts;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_InrTim;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_LocalStartFailOpRecord[10];/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_LockHoornOnSts;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_ParkAutoUnlockSetFb;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_RemotePwrLckSta;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_RemoteStartFailRecord[10];/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_SpdCtlLckSet;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_StartReq;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_SysPwrMode;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkAjarSw;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkLckSw;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkOpRecord[10];/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_TrunkSw;/* '<S268>/EEReadCtl' */
extern MONPRM volatile uint8 EEReadCtl_WiprIntlTimeSetFb;/* '<S268>/EEReadCtl' */
extern MONPRM volatile boolean ESCLCtl_J436Lck;/* '<S606>/ESCLLck' */
extern MONPRM volatile boolean ESCLCtl_J436PwrSup;/* '<S611>/Switch' */
extern MONPRM volatile boolean ESCLCtl_J436Unlck;/* '<S606>/ESCLUnlck' */
extern MONPRM volatile uint8 ESCLCtl_Lck;/* '<S606>/ESCLLck' */
extern MONPRM volatile uint8 ESCLCtl_UnOrLockCrtl;/* '<S606>/Truth Table' */
extern MONPRM volatile uint8 ESCLCtl_Unlck;/* '<S606>/ESCLUnlck' */
extern MONPRM volatile uint8 HornCtl_AlarmSta;/* '<S314>/Alarm' */
extern MONPRM volatile uint8 HornCtl_AntiLckSta;/* '<S315>/AntiLck' */
extern MONPRM volatile uint8 HornCtl_ArmedSta;/* '<S316>/Armed' */
extern MONPRM volatile boolean HornCtl_HornSwCtl;/* '<S318>/LIB_TPD_10ms' */
extern MONPRM volatile boolean HornCtl_J430HornDrv;/* '<S320>/Switch1' */
extern MONPRM volatile uint8 HornCtl_LockHoornOnSt;/* '<S317>/Multiport Switch' */
extern MONPRM volatile uint8 HornCtl_LockHoornOnStFb;/* '<S317>/Multiport Switch1' */
extern MONPRM volatile uint8 HornCtl_PartArmedSta;/* '<S321>/PartArmed' */
extern MONPRM volatile uint8 HornCtl_SeekSta;/* '<S322>/Seek' */
extern MONPRM volatile uint8 HornCtl_TrunkWarnSta;/* '<S323>/Chart1' */
extern MONPRM volatile uint8 IMMOCtl_AuthResp[8];/* '<S410>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_INVRandom[8];/* '<S410>/Signal Conversion' */
extern MONPRM volatile uint8 IMMOCtl_SKRead[16];/* '<S410>/IMMOCtl' */
extern MONPRM volatile uint8 IMMOCtl_SKSta;/* '<S410>/IMMOCtl' */
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
extern MONPRM volatile boolean LampCtl_AlrmSta;/* '<S752>/Chart' */
extern MONPRM volatile boolean LampCtl_AntiLckSta;/* '<S753>/Chart' */
extern MONPRM volatile boolean LampCtl_ArmedSta;/* '<S754>/Chart' */
extern MONPRM volatile boolean LampCtl_AutoLampSta;/* '<S667>/Switch' */
extern MONPRM volatile boolean LampCtl_AutoLampSw;/* '<S653>/LIB_TPD_10ms8' */
extern MONPRM volatile uint8 LampCtl_BackLadjvalFb;/* '<S623>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_BrakeLightSta;/* '<S642>/Switch1' */
extern MONPRM volatile boolean LampCtl_BrakeLightSw;/* '<S653>/Logical Operator13' */
extern MONPRM volatile boolean LampCtl_CrashSta;/* '<S755>/Chart1' */
extern MONPRM volatile boolean LampCtl_DayRunLightSta;/* '<S636>/Switch1' */
extern MONPRM volatile boolean LampCtl_DisarmedSta;/* '<S756>/Chart' */
extern MONPRM volatile boolean LampCtl_DomeLampCloseDoor;/* '<S679>/Logical Operator6' */
extern MONPRM volatile boolean LampCtl_DomeLampCtl;/* '<S680>/Switch' */
extern MONPRM volatile boolean LampCtl_DomeLampFLOpen;/* '<S682>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampFROpen;/* '<S683>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampLockDoor;/* '<S695>/Logical Operator' */
extern MONPRM volatile boolean LampCtl_DomeLampOff;/* '<S627>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOffGrad;/* '<S627>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOn;/* '<S627>/Truth Table' */
extern MONPRM volatile boolean LampCtl_DomeLampOnGrad;/* '<S627>/Truth Table' */
extern MONPRM volatile uint8 LampCtl_DomeLampPwmDuty;/* '<S637>/Switch1' */
extern MONPRM volatile boolean LampCtl_DomeLampPwrOff;/* '<S688>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_DomeLampUnlock;/* '<S689>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_EmerHazardLightSta;/* '<S654>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_EmerSta;/* '<S757>/Logical Operator' */
extern MONPRM volatile uint8 LampCtl_FlwrMeHomeCtlFb;/* '<S870>/Multiport Switch1' */
extern MONPRM volatile boolean LampCtl_FlwrMeHomeSta;/* '<S872>/Switch' */
extern MONPRM volatile uint16 LampCtl_FlwrMeHomeTim;/* '<S870>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_FogLampFSta;/* '<S647>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampFSw;/* '<S653>/LIB_TPD_10ms12' */
extern MONPRM volatile boolean LampCtl_FogLampRSta;/* '<S646>/Switch1' */
extern MONPRM volatile boolean LampCtl_FogLampRSw;/* '<S653>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean LampCtl_HazardLightSta;/* '<S654>/HazardLightLogic' */
extern MONPRM volatile boolean LampCtl_HazardLightSw;/* '<S653>/LIB_TPD_10ms10' */
extern MONPRM volatile boolean LampCtl_HiBeamShortToBat;/* '<S629>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_HiBeamSta;/* '<S649>/Switch1' */
extern MONPRM volatile boolean LampCtl_HiBeamSw;/* '<S653>/LIB_TPD_10ms2' */
extern MONPRM volatile uint8 LampCtl_J408BackLampPWM;/* '<S641>/Switch1' */
extern MONPRM volatile boolean LampCtl_J420BSDRightCtl;/* '<S643>/Switch1' */
extern MONPRM volatile boolean LampCtl_J422BSDLeftCtl;/* '<S644>/Switch1' */
extern MONPRM volatile boolean LampCtl_J449BoxLamp;/* '<S640>/Switch1' */
extern MONPRM volatile boolean LampCtl_KnobBeamFaultSta;/* '<S630>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_LampDelay;/* '<S708>/Switch' */
extern MONPRM volatile uint8 LampCtl_LightIntstSta;/* '<S632>/Chart' */
extern MONPRM volatile uint16 LampCtl_LightIntstVal;/* '<S653>/Data Type Conversion12' */
extern MONPRM volatile boolean LampCtl_LowBeamShortToBat;/* '<S633>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_LowBeamSta;/* '<S645>/Switch1' */
extern MONPRM volatile boolean LampCtl_LowBeamSw;/* '<S653>/LIB_TPD_10ms1' */
extern MONPRM volatile uint8 LampCtl_PartArmedSta;/* '<S759>/Chart' */
extern MONPRM volatile boolean LampCtl_PassLightSta;/* '<S650>/LIB_Tim' */
extern MONPRM volatile boolean LampCtl_PassLightSw;/* '<S653>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean LampCtl_PosLampSta;/* '<S635>/Switch1' */
extern MONPRM volatile boolean LampCtl_PosLampSw;/* '<S653>/LIB_TPD_10ms' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntL;/* '<S766>/LIB_Pulse' */
extern MONPRM volatile uint16 LampCtl_PrdSucCntR;/* '<S768>/LIB_Pulse' */
extern MONPRM volatile uint8 LampCtl_RKEReq;/* '<S653>/Multiport Switch' */
extern MONPRM volatile boolean LampCtl_ReverseLampSta;/* '<S648>/Switch1' */
extern MONPRM volatile boolean LampCtl_RodBeamFaultSta;/* '<S761>/LIB_TPD_10ms' */
extern MONPRM volatile boolean LampCtl_ThermalrunawaySta;/* '<S762>/Chart' */
extern MONPRM volatile boolean LampCtl_TrunkWarnSta;/* '<S763>/Chart' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLFlashCnt;/* '<S654>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLOpen;/* '<S765>/Logical Operator' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLShort;/* '<S765>/Logical Operator2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSta;/* '<S639>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLSw;/* '<S653>/LIB_TPD_10ms4' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrLVol;/* '<S838>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneLSw;/* '<S653>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean LampCtl_TurnIndcrLaneRSw;/* '<S653>/LIB_TPD_10ms7' */
extern MONPRM volatile uint8 LampCtl_TurnIndcrMod;/* '<S654>/TurnIndcrLogic' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrPrd;/* '<S654>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRFlashCnt;/* '<S654>/TurnIndcrArb2' */
extern MONPRM volatile boolean LampCtl_TurnIndcrROpen;/* '<S765>/Logical Operator1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRShort;/* '<S765>/Logical Operator3' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSta;/* '<S638>/Switch1' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRSw;/* '<S653>/LIB_TPD_10ms6' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrRVol;/* '<S837>/C Caller' */
extern MONPRM volatile boolean LampCtl_TurnIndcrRst;/* '<S654>/TurnIndcrArb2' */
extern MONPRM volatile uint16 LampCtl_TurnIndcrWdt;/* '<S654>/TurnIndcrArb2' */
extern MONPRM volatile uint8 LampCtl_VehModeSta;/* '<S770>/Chart' */
extern MONPRM volatile uint8 LampCtl_VehSeekSta;/* '<S771>/Chart' */
extern MONPRM volatile uint8 LampCtl_VehSeekStaFb;/* '<S771>/SeekFb' */
extern MONPRM volatile boolean LampCtl_WelcomeLampSta;/* '<S871>/Switch' */
extern MONPRM volatile boolean PDUCtl_BrkPwrOn;/* '<S891>/Logical Operator1' */
extern MONPRM volatile boolean PDUCtl_DelayTimPwrOff;/* '<S890>/LIB_Tim' */
extern MONPRM volatile boolean PDUCtl_EmerPwrOff;/* '<S890>/Logical Operator13' */
extern MONPRM volatile boolean PDUCtl_HUPwrOff;/* '<S890>/Logical Operator8' */
extern MONPRM volatile boolean PDUCtl_IG1RelayFault;/* '<S892>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean PDUCtl_IG2RelayFault;/* '<S892>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean PDUCtl_IGRlyIlgCls;/* '<S892>/LIB_TPD_10ms3' */
extern MONPRM volatile uint8 PDUCtl_J421IG1RlyCtl;/* '<S888>/Switch1' */
extern MONPRM volatile uint8 PDUCtl_J437IG2RlyCtl;/* '<S889>/Switch1' */
extern MONPRM volatile boolean PDUCtl_KeyChk;/* '<S891>/Logical Operator5' */
extern MONPRM volatile boolean PDUCtl_OTAOverTimPwrOff;/* '<S890>/LIB_PosPluse1' */
extern MONPRM volatile boolean PDUCtl_OTAPwrOff;/* '<S890>/Logical Operator20' */
extern MONPRM volatile boolean PDUCtl_OTAPwrOn;/* '<S917>/Logical Operator' */
extern MONPRM volatile boolean PDUCtl_OpenDoorPwrOn;/* '<S891>/Logical Operator' */
extern MONPRM volatile boolean PDUCtl_OsLckPwrOff;/* '<S890>/Logical Operator5' */
extern MONPRM volatile boolean PDUCtl_PwrOff;/* '<S890>/Logical Operator6' */
extern MONPRM volatile boolean PDUCtl_PwrOn;/* '<S891>/Logical Operator11' */
extern MONPRM volatile boolean PDUCtl_RemotePwrLckFb;/* '<S921>/Switch' */
extern MONPRM volatile uint8 PDUCtl_RemotePwrLckSta;/* '<S891>/RemoteLck' */
extern MONPRM volatile boolean PDUCtl_RemtOverTimPwrOff;/* '<S890>/LIB_Tim1' */
extern MONPRM volatile boolean PDUCtl_RemtPasvPwrOff;/* '<S890>/Logical Operator16' */
extern MONPRM volatile uint8 PDUCtl_RemtPwrCtlFb;/* '<S412>/RemtPwrCtlFb' */
extern MONPRM volatile boolean PDUCtl_RemtPwrOff;/* '<S890>/Logical Operator12' */
extern MONPRM volatile boolean PDUCtl_RemtPwrOn;/* '<S891>/Logical Operator9' */
extern MONPRM volatile boolean PDUCtl_StartReq;/* '<S939>/Switch' */
extern MONPRM volatile uint8 PDUCtl_SysPowerSts;/* '<S412>/Chart' */
extern MONPRM volatile uint8 PDUCtl_SysPwrMode;/* '<S412>/Truth Table' */
extern MONPRM volatile uint8 PDUCtl_SysPwrModeAct;/* '<S895>/Switch' */
extern MONPRM volatile boolean PDUCtl_SysPwrModeV;/* '<S892>/Switch' */
extern MONPRM volatile uint8 PEPSCtl_AvaluebleKeyInCar;/* '<S247>/Chart3' */
extern MONPRM volatile uint8 PEPSCtl_DrvPEAuthentAcsd;/* '<S247>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_FRPEAuthentAcsd;/* '<S247>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_FrbdnKeyNr;/* '<S245>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_IMMOKey;/* '<S248>/Chart5' */
extern MONPRM volatile uint8 PEPSCtl_IndicationKeyCloser;/* '<S248>/Chart2' */
extern MONPRM volatile uint8 PEPSCtl_KeyInCarSta;/* '<S247>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_KeyLoBattLvlWarn;/* '<S246>/Chart3' */
extern MONPRM volatile uint8 PEPSCtl_KeySta;/* '<S248>/Chart1' */
extern MONPRM volatile uint8 PEPSCtl_LckWlcmReq;/* '<S249>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_PSAuthentRes;/* '<S248>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_PSReq;/* '<S248>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_UnlckWlcmReq;/* '<S249>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_WarnKeyOutReminder;/* '<S246>/Chart' */
extern MONPRM volatile uint8 PEPSCtl_WarnNoKeyFound;/* '<S248>/Chart2' */
extern MONPRM volatile boolean RVMCtl_J42Heat;/* '<S131>/Switch' */
extern MONPRM volatile uint8 SCS_FrntWiprSwtSt;/* '<S270>/Signal Conversion' */
extern MONPRM volatile boolean SCS_FrntWshrSwtSt;/* '<S270>/Signal Conversion1' */
extern MONPRM volatile boolean SCS_FrntWshrSwtStVD;/* '<S270>/Signal Conversion2' */
extern MONPRM volatile boolean SCS_WiprSwtStVD;/* '<S270>/Signal Conversion3' */
extern MONPRM volatile uint8 SeatCtl_CN167DrvSeatHtPWM;/* '<S141>/Switch' */
extern MONPRM volatile boolean SeatCtl_DrvNTCOpen;/* '<S136>/LIB_TPD_Ts1' */
extern MONPRM volatile boolean SeatCtl_DrvNTCShort;/* '<S136>/LIB_TPD_Ts' */
extern MONPRM volatile sint8 SeatCtl_DrvSeatTemp;/* '<S136>/Data Type Conversion' */
extern MONPRM volatile uint8 SeatCtl_MaiDrvSeatStFb;/* '<S136>/Multiport Switch' */
extern MONPRM volatile uint8 SeatCtl_RemtHeatFb;/* '<S136>/HeatFb' */
extern MONPRM volatile boolean SteerWhlCtl_J447SteerWhlHt;/* '<S148>/Switch' */
extern MONPRM volatile uint8 SteerWhlCtl_RemtHeatFb;/* '<S144>/HeatFb' */
extern MONPRM volatile uint8 SteerWhlCtl_SteerWhlHeatSts;/* '<S144>/HeatSet' */
extern MONPRM volatile sint8 SteerWhlCtl_SteerWhlTemp;/* '<S144>/Data Type Conversion' */
extern MONPRM volatile boolean WakeUpCtl_NMReq;/* '<S954>/Switch' */
extern MONPRM volatile boolean WakeUpCtl_SleepAllwd;/* '<S942>/Logical Operator5' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnReq;/* '<S159>/Chart13' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinAutoDnSw;/* '<S157>/LIB_TPD_10ms9' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinDnReq;/* '<S159>/Chart11' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinDnSw;/* '<S157>/LIB_TPD_10ms8' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinOvTimProt;/* '<S159>/LIB_PosPluse2' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinUpReq;/* '<S159>/Chart12' */
extern MONPRM volatile boolean WinCtl_DrvPsgWinUpSw;/* '<S157>/LIB_TPD_10ms7' */
extern MONPRM volatile boolean WinCtl_DrvWinAutoDnReq;/* '<S159>/Chart10' */
extern MONPRM volatile boolean WinCtl_DrvWinAutoDnSw;/* '<S157>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WinCtl_DrvWinDnProt;/* '<S158>/LIB_CntLimit1' */
extern MONPRM volatile boolean WinCtl_DrvWinDnReq;/* '<S159>/Chart2' */
extern MONPRM volatile boolean WinCtl_DrvWinDnSw;/* '<S157>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WinCtl_DrvWinMotorLocked;/* '<S159>/LIB_TPD_10ms3' */
extern MONPRM volatile uint8 WinCtl_DrvWinReq;/* '<S159>/Switch11' */
extern MONPRM volatile uint8 WinCtl_DrvWinSta;/* '<S11>/DrvWinCtl' */
extern MONPRM volatile boolean WinCtl_DrvWinUpProt;/* '<S158>/LIB_CntLimit' */
extern MONPRM volatile boolean WinCtl_DrvWinUpReq;/* '<S159>/Chart3' */
extern MONPRM volatile boolean WinCtl_DrvWinUpSw;/* '<S157>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean WinCtl_J51DrvWinUp;/* '<S152>/Switch1' */
extern MONPRM volatile boolean WinCtl_J53DrvWinDn;/* '<S154>/Switch1' */
extern MONPRM volatile boolean WinCtl_J55PsgWinUp;/* '<S155>/Switch1' */
extern MONPRM volatile boolean WinCtl_J57PsgWinDn;/* '<S153>/Switch1' */
extern MONPRM volatile boolean WinCtl_PsgWinAutoDnReq;/* '<S159>/Chart1' */
extern MONPRM volatile boolean WinCtl_PsgWinAutoDnSw;/* '<S157>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean WinCtl_PsgWinDnProt;/* '<S158>/LIB_CntLimit3' */
extern MONPRM volatile boolean WinCtl_PsgWinDnReq;/* '<S159>/Chart4' */
extern MONPRM volatile boolean WinCtl_PsgWinDnSw;/* '<S157>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean WinCtl_PsgWinMotorLocked;/* '<S159>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WinCtl_PsgWinOvTimProt;/* '<S159>/LIB_PosPluse1' */
extern MONPRM volatile uint8 WinCtl_PsgWinReq;/* '<S159>/Switch10' */
extern MONPRM volatile uint8 WinCtl_PsgWinSta;/* '<S11>/PsgWinCtl' */
extern MONPRM volatile boolean WinCtl_PsgWinUpProt;/* '<S158>/LIB_CntLimit2' */
extern MONPRM volatile boolean WinCtl_PsgWinUpReq;/* '<S159>/Chart5' */
extern MONPRM volatile boolean WinCtl_PsgWinUpSw;/* '<S157>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WiperCtl_HiSpdDrv;/* '<S352>/Switch1' */
extern MONPRM volatile uint16 WiperCtl_InrTim;/* '<S358>/Multiport Switch' */
extern MONPRM volatile boolean WiperCtl_InrTimChg;/* '<S358>/Relational Operator1' */
extern MONPRM volatile boolean WiperCtl_LockedRotorProtSta;/* '<S350>/Logical Operator2' */
extern MONPRM volatile boolean WiperCtl_LowSpdDrv;/* '<S351>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashMotorDrv;/* '<S353>/Switch1' */
extern MONPRM volatile boolean WiperCtl_WashSw;/* '<S354>/LIB_TPD_10ms5' */
extern MONPRM volatile boolean WiperCtl_WashWiperSta;/* '<S355>/LIB_TPD_10ms6' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSta;/* '<S357>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperHiSpdSw;/* '<S354>/LIB_TPD_10ms4' */
extern MONPRM volatile boolean WiperCtl_WiperInrSta;/* '<S358>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperInrSw;/* '<S354>/LIB_TPD_10ms2' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSta;/* '<S359>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperLowSpdSw;/* '<S354>/LIB_TPD_10ms3' */
extern MONPRM volatile boolean WiperCtl_WiperMaintSta;/* '<S399>/Switch' */
extern MONPRM volatile boolean WiperCtl_WiperMistSta;/* '<S361>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperMistSw;/* '<S354>/LIB_TPD_10ms' */
extern MONPRM volatile boolean WiperCtl_WiperOffSta;/* '<S362>/Logical Operator' */
extern MONPRM volatile boolean WiperCtl_WiperOffSw;/* '<S354>/LIB_TPD_10ms1' */
extern MONPRM volatile boolean WiperCtl_WiperParkPosSw;/* '<S354>/LIB_TPD_10ms6' */
extern MONPRM volatile uint8 WiperCtl_WiperSta;/* '<S356>/Chart' */
extern MONPRM volatile uint8 WiperCtl_WiprIntlTimeSetFb;/* '<S358>/Multiport Switch1' */

#endif                                 /* RTW_HEADER_monPrmsBcm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
