/*
 * File: calPrmsBcm.h
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

#ifndef RTW_HEADER_calPrmsBcm_h_
#define RTW_HEADER_calPrmsBcm_h_
#include "rtwtypes.h"
#include "AppSwcBcm_types.h"

/* Exported data declaration */

/*Group of variables*/
#include "XcpTest_types.h"

/* Declaration for custom storage class: CalParam */
extern CALDATA const volatile uint16 AlmSysCtl_AlrmTimLimit_C;/* Referenced by: '<S430>/AlmSysLogic' */
extern CALDATA const volatile boolean BCMTx_TRMode_C;/* Referenced by:
                                                      * '<S292>/HwDrvSeatHeatCtl'
                                                      * '<S292>/HwSavePwrEnbl'
                                                      * '<S292>/HwTurnLampOnLeft'
                                                      * '<S292>/HwTurnLampOnRight'
                                                      */
extern CALDATA const volatile uint16 BatSaveCtl_DlyTim_C;/* Referenced by: '<S458>/Constant2' */
extern CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdFlg_C;/* Referenced by: '<S431>/Constant18' */
extern CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdVal_C;/* Referenced by: '<S431>/Constant19' */
extern CALDATA const volatile uint16 BatSaveCtl_LckDlyTim_C;/* Referenced by: '<S458>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_AntiLckProtTim_C;/* Referenced by: '<S474>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_AutoLckDelayTim_C;/* Referenced by: '<S513>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_CntSubTim_C;/* Referenced by: '<S479>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimInValid_C;/* Referenced by: '<S471>/Constant2' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimValid_C;/* Referenced by: '<S471>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarFLVal_C;/* Referenced by: '<S471>/Constant4' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimInValid_C;/* Referenced by: '<S471>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimValid_C;/* Referenced by: '<S471>/Constant6' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarFRVal_C;/* Referenced by: '<S471>/Constant9' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimInvalid_C;/* Referenced by: '<S471>/Constant35' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimValid_C;/* Referenced by: '<S471>/Constant34' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarRLVal_C;/* Referenced by: '<S471>/Constant18' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimInvalid_C;/* Referenced by: '<S471>/Constant38' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimValid_C;/* Referenced by: '<S471>/Constant37' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarRRVal_C;/* Referenced by: '<S471>/Constant20' */
extern CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimInValid_C;/* Referenced by: '<S471>/Constant47' */
extern CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimValid_C;/* Referenced by: '<S471>/Constant46' */
extern CALDATA const volatile boolean DoorLckCtl_DriverDoorLckVal_C;/* Referenced by: '<S471>/Constant60' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvPETimInvalid_C;/* Referenced by: '<S471>/Constant26' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvPETimValid_C;/* Referenced by: '<S471>/Constant25' */
extern CALDATA const volatile boolean DoorLckCtl_DrvPEVal_C;/* Referenced by: '<S471>/Constant12' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisMin_C;/* Referenced by: '<S471>/Constant67' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisVal_C;/* Referenced by: '<S471>/Constant63' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimInValid_C;/* Referenced by: '<S471>/Constant65' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimValid_C;/* Referenced by: '<S471>/Constant64' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvTim_C;/* Referenced by: '<S432>/DoorDrv' */
extern CALDATA const volatile uint8 DoorLckCtl_EEIlluminatedEntrySys_C;/* Referenced by: '<S471>/Constant74' */
extern CALDATA const volatile uint8 DoorLckCtl_EEKeyEntry_C;/* Referenced by: '<S471>/Constant72' */
extern CALDATA const volatile uint8 DoorLckCtl_IllmndSts_C;/* Referenced by: '<S471>/Constant76' */
extern CALDATA const volatile uint16 DoorLckCtl_InportCalSwBit_C;/* Referenced by:
                                                                  * '<S471>/Constant10'
                                                                  * '<S471>/Constant11'
                                                                  * '<S471>/Constant13'
                                                                  * '<S471>/Constant15'
                                                                  * '<S471>/Constant17'
                                                                  * '<S471>/Constant19'
                                                                  * '<S471>/Constant21'
                                                                  * '<S471>/Constant5'
                                                                  * '<S471>/Constant59'
                                                                  * '<S471>/Constant62'
                                                                  * '<S471>/Constant71'
                                                                  * '<S471>/Constant73'
                                                                  * '<S471>/Constant75'
                                                                  */
extern CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdFlg_C;/* Referenced by: '<S432>/Constant3' */
extern CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdVal_C;/* Referenced by: '<S432>/Constant4' */
extern CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdFlg_C;/* Referenced by: '<S432>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdVal_C;/* Referenced by: '<S432>/Constant2' */
extern CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdFlg_C;/* Referenced by: '<S432>/Constant18' */
extern CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdVal_C;/* Referenced by: '<S432>/Constant19' */
extern CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMaxTim_C;/* Referenced by: '<S432>/DoorDrv' */
extern CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMinTim_C;/* Referenced by: '<S432>/DoorDrv' */
extern CALDATA const volatile uint16 DoorLckCtl_MotorProtTimMax_C;/* Referenced by: '<S479>/Constant2' */
extern CALDATA const volatile uint8 DoorLckCtl_MotorWorkMax_C;/* Referenced by: '<S479>/Constant1' */
extern CALDATA const volatile uint16 DoorLckCtl_PEProtCnt_C;/* Referenced by: '<S482>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_PEProtIntvlTim_C;/* Referenced by: '<S482>/Constant2' */
extern CALDATA const volatile uint16 DoorLckCtl_PsgPETimInvalid_C;/* Referenced by:
                                                                   * '<S471>/Constant29'
                                                                   * '<S471>/Constant32'
                                                                   */
extern CALDATA const volatile uint16 DoorLckCtl_PsgPETimValid_C;/* Referenced by:
                                                                 * '<S471>/Constant28'
                                                                 * '<S471>/Constant31'
                                                                 */
extern CALDATA const volatile boolean DoorLckCtl_PsgPEVal_C;/* Referenced by: '<S471>/Constant14' */
extern CALDATA const volatile uint8 DoorLckCtl_RemtCmdFbCnt_C;/* Referenced by: '<S485>/Chart2' */
extern CALDATA const volatile uint16 DoorLckCtl_SpdLckTimInValid_C;/* Referenced by:
                                                                    * '<S490>/Constant10'
                                                                    * '<S490>/Constant3'
                                                                    */
extern CALDATA const volatile uint16 DoorLckCtl_SpdLckTimValid_C;/* Referenced by:
                                                                  * '<S490>/Constant2'
                                                                  * '<S490>/Constant9'
                                                                  */
extern CALDATA const volatile uint8 DoorLckCtl_SpdLck_C;/* Referenced by:
                                                         * '<S490>/Chart'
                                                         * '<S490>/Constant'
                                                         */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimInvalid_C;/* Referenced by: '<S471>/Constant41' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimValid_C;/* Referenced by: '<S471>/Constant40' */
extern CALDATA const volatile boolean DoorLckCtl_TrunkAjarVal_C;/* Referenced by: '<S471>/Constant22' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAutoLckTim_C;/* Referenced by: '<S518>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_TrunkSwVal_C;/* Referenced by: '<S471>/Constant16' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimInvalid_C;/* Referenced by: '<S537>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimValid_C;/* Referenced by: '<S537>/Constant2' */
extern CALDATA const volatile float32 DoorLckCtl_Ts_C;/* Referenced by:
                                                       * '<S471>/Constant27'
                                                       * '<S471>/Constant3'
                                                       * '<S471>/Constant30'
                                                       * '<S471>/Constant33'
                                                       * '<S471>/Constant36'
                                                       * '<S471>/Constant39'
                                                       * '<S471>/Constant42'
                                                       * '<S471>/Constant49'
                                                       * '<S471>/Constant66'
                                                       * '<S471>/Constant8'
                                                       * '<S490>/Constant11'
                                                       * '<S490>/Constant49'
                                                       * '<S514>/Constant42'
                                                       * '<S533>/Constant42'
                                                       * '<S533>/Constant7'
                                                       * '<S537>/Constant4'
                                                       */
extern CALDATA const volatile boolean EEWriteCtl_ImmOvrdFlg_C;/* Referenced by: '<S6>/EEWriteCtl' */
extern CALDATA const volatile uint8 EEWriteCtl_ImmOvrdVal_C[128];/* Referenced by: '<S6>/EEWriteCtl' */
extern CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdFlg_C;/* Referenced by: '<S625>/Constant18' */
extern CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdVal_C;/* Referenced by: '<S625>/Constant19' */
extern CALDATA const volatile uint16 ESCLCtl_LckDelay_C;/* Referenced by: '<S625>/ESCLLck' */
extern CALDATA const volatile uint16 ESCLCtl_LckTimMax_C;/* Referenced by: '<S625>/ESCLLck' */
extern CALDATA const volatile uint16 ESCLCtl_PwrOffDelay_C;/* Referenced by:
                                                            * '<S625>/ESCLLck'
                                                            * '<S625>/ESCLUnlck'
                                                            */
extern CALDATA const volatile uint16 ESCLCtl_UnlckDelay_C;/* Referenced by: '<S625>/ESCLUnlck' */
extern CALDATA const volatile uint16 ESCLCtl_UnlckTimMax_C;/* Referenced by: '<S625>/ESCLUnlck' */
extern CALDATA const volatile uint16 HornCtl_HornSwTimInvalid_C;/* Referenced by: '<S343>/Constant38' */
extern CALDATA const volatile uint16 HornCtl_HornSwTimValid_C;/* Referenced by: '<S343>/Constant37' */
extern CALDATA const volatile boolean HornCtl_J430HornDrvOvrdFlg_C;/* Referenced by: '<S290>/Constant18' */
extern CALDATA const volatile boolean HornCtl_J430HornDrvOvrdVal_C;/* Referenced by: '<S290>/Constant19' */
extern CALDATA const volatile float32 HornCtl_Ts_C;/* Referenced by: '<S343>/Constant39' */
extern CALDATA const volatile uint16 LampCtl_AutoHiBeamInhbTim_C;
                                     /* Referenced by: '<S641>/AutoHiBeamCtl' */
extern CALDATA const volatile uint16 LampCtl_AutoLampDayDelayTim_C;/* Referenced by: '<S642>/Constant6' */
extern CALDATA const volatile uint16 LampCtl_AutoLampNightDelayTim_C;/* Referenced by: '<S642>/Constant43' */
extern CALDATA const volatile uint16 LampCtl_AutoLampTimInValid_C;/* Referenced by: '<S673>/Constant63' */
extern CALDATA const volatile uint16 LampCtl_AutoLampTimValid_C;/* Referenced by: '<S673>/Constant9' */
extern CALDATA const volatile boolean LampCtl_AutoLampVal_C;/* Referenced by: '<S673>/Constant8' */
extern CALDATA const volatile uint16 LampCtl_BoxLampOpenTimMax_C;/* Referenced by: '<S644>/Constant4' */
extern CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdFlg_C;/* Referenced by: '<S436>/Constant3' */
extern CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdVal_C;/* Referenced by: '<S436>/Constant4' */
extern CALDATA const volatile boolean LampCtl_BrakeLightVal_C;/* Referenced by:
                                                               * '<S673>/Constant62'
                                                               * '<S673>/Constant74'
                                                               */
extern CALDATA const volatile uint16 LampCtl_BrakeSwInValid_C;/* Referenced by:
                                                               * '<S673>/Constant15'
                                                               * '<S673>/Constant71'
                                                               */
extern CALDATA const volatile uint16 LampCtl_BrakeSwTimValid_C;/* Referenced by:
                                                                * '<S673>/Constant14'
                                                                * '<S673>/Constant70'
                                                                */
extern CALDATA const volatile uint16 LampCtl_BrkLampShortToBatOrOpenTimInValid_C;/* Referenced by: '<S645>/Constant29' */
extern CALDATA const volatile uint16 LampCtl_BrkLampShortToBatOrOpenTimValid_C;/* Referenced by: '<S645>/Constant28' */
extern CALDATA const volatile uint16 LampCtl_BrkLampShortToGndTimInValid_C;/* Referenced by: '<S645>/Constant17' */
extern CALDATA const volatile uint16 LampCtl_BrkLampShortToGndTimValid_C;/* Referenced by: '<S645>/Constant16' */
extern CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdFlg_C;/* Referenced by: '<S436>/Constant1' */
extern CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdVal_C;/* Referenced by: '<S436>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_DayTimeVal_C;/* Referenced by: '<S652>/Chart' */
extern CALDATA const volatile boolean LampCtl_DomeLampPwmDutyOvrdFlg_C;/* Referenced by: '<S436>/Constant22' */
extern CALDATA const volatile uint8 LampCtl_DomeLampPwmDutyOvrdVal_C;/* Referenced by: '<S436>/Constant21' */
extern CALDATA const volatile uint16 LampCtl_DoorOpenFLInValidTim_C;/* Referenced by: '<S699>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_DoorOpenFLValidTim_C;/* Referenced by: '<S699>/Constant3' */
extern CALDATA const volatile uint16 LampCtl_DoorOpenFRInValidTim_C;/* Referenced by: '<S699>/Constant7' */
extern CALDATA const volatile uint16 LampCtl_DoorOpenFRValidTim_C;/* Referenced by: '<S699>/Constant6' */
extern CALDATA const volatile uint16 LampCtl_FlwrMeHomeTimValid_C;/* Referenced by: '<S895>/Constant43' */
extern CALDATA const volatile boolean LampCtl_FogLampFStaOvrdFlg_C;/* Referenced by: '<S436>/Constant14' */
extern CALDATA const volatile boolean LampCtl_FogLampFStaOvrdVal_C;/* Referenced by: '<S436>/Constant13' */
extern CALDATA const volatile uint16 LampCtl_FogLampFTimInValid_C;/* Referenced by: '<S673>/Constant66' */
extern CALDATA const volatile uint16 LampCtl_FogLampFTimValid_C;/* Referenced by: '<S673>/Constant64' */
extern CALDATA const volatile boolean LampCtl_FogLampFVal_C;/* Referenced by: '<S673>/Constant69' */
extern CALDATA const volatile boolean LampCtl_FogLampRStaOvrdFlg_C;/* Referenced by: '<S436>/Constant12' */
extern CALDATA const volatile boolean LampCtl_FogLampRStaOvrdVal_C;/* Referenced by: '<S436>/Constant11' */
extern CALDATA const volatile uint16 LampCtl_FogLampRTimInValid_C;/* Referenced by: '<S673>/Constant44' */
extern CALDATA const volatile uint16 LampCtl_FogLampRTimValid_C;/* Referenced by: '<S673>/Constant43' */
extern CALDATA const volatile boolean LampCtl_FogLampRVal_C;/* Referenced by: '<S673>/Constant56' */
extern CALDATA const volatile uint16 LampCtl_HazardLightTimInValid_C;/* Referenced by: '<S673>/Constant47' */
extern CALDATA const volatile uint16 LampCtl_HazardLightTimValid_C;/* Referenced by: '<S673>/Constant46' */
extern CALDATA const volatile boolean LampCtl_HazardLightVal_C;/* Referenced by: '<S673>/Constant60' */
extern CALDATA const volatile uint16 LampCtl_HiBeamShortToBatTimInValid_C;/* Referenced by: '<S649>/Constant29' */
extern CALDATA const volatile boolean LampCtl_HiBeamStaOvrdFlg_C;/* Referenced by: '<S436>/Constant20' */
extern CALDATA const volatile boolean LampCtl_HiBeamStaOvrdVal_C;/* Referenced by: '<S436>/Constant17' */
extern CALDATA const volatile uint16 LampCtl_HiBeamTimInValid_C;/* Referenced by: '<S673>/Constant26' */
extern CALDATA const volatile uint16 LampCtl_HiBeamTimValid_C;/* Referenced by: '<S673>/Constant25' */
extern CALDATA const volatile boolean LampCtl_HiBeamVal_C;/* Referenced by: '<S673>/Constant11' */
extern CALDATA const volatile uint16 LampCtl_InportCalSwBit_C;/* Referenced by:
                                                               * '<S673>/Constant1'
                                                               * '<S673>/Constant12'
                                                               * '<S673>/Constant3'
                                                               * '<S673>/Constant4'
                                                               * '<S673>/Constant48'
                                                               * '<S673>/Constant53'
                                                               * '<S673>/Constant55'
                                                               * '<S673>/Constant59'
                                                               * '<S673>/Constant6'
                                                               * '<S673>/Constant61'
                                                               * '<S673>/Constant68'
                                                               * '<S673>/Constant73'
                                                               */
extern CALDATA const volatile boolean LampCtl_J408BackLampPWMOvrdFlg_C;/* Referenced by: '<S436>/Constant30' */
extern CALDATA const volatile uint8 LampCtl_J408BackLampPWMOvrdVal_C;/* Referenced by: '<S436>/Constant29' */
extern CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdFlg_C;/* Referenced by: '<S436>/Constant5' */
extern CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdVal_C;/* Referenced by: '<S436>/Constant6' */
extern CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdFlg_C;/* Referenced by: '<S436>/Constant7' */
extern CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdVal_C;/* Referenced by: '<S436>/Constant8' */
extern CALDATA const volatile boolean LampCtl_J449BoxLampOvrdFlg_C;/* Referenced by: '<S436>/Constant28' */
extern CALDATA const volatile boolean LampCtl_J449BoxLampOvrdVal_C;/* Referenced by: '<S436>/Constant27' */
extern CALDATA const volatile uint8 LampCtl_LOpenCnt_C;/* Referenced by: '<S791>/Constant17' */
extern CALDATA const volatile uint8 LampCtl_LShortCnt_C;/* Referenced by: '<S791>/Constant19' */
extern CALDATA const volatile uint16 LampCtl_LampDelayTim_C;/* Referenced by: '<S651>/Constant6' */
extern CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimInValid_C;/* Referenced by: '<S653>/Constant29' */
extern CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimValid_C;/* Referenced by: '<S653>/Constant28' */
extern CALDATA const volatile boolean LampCtl_LowBeamStaOvrdFlg_C;/* Referenced by: '<S436>/Constant9' */
extern CALDATA const volatile boolean LampCtl_LowBeamStaOvrdVal_C;/* Referenced by: '<S436>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_LowBeamStaTimInValid_C;/* Referenced by: '<S653>/Constant5' */
extern CALDATA const volatile uint16 LampCtl_LowBeamStaTimValid_C;/* Referenced by: '<S653>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_LowBeamTimInValid_C;/* Referenced by: '<S673>/Constant24' */
extern CALDATA const volatile uint16 LampCtl_LowBeamTimValid_C;/* Referenced by: '<S673>/Constant23' */
extern CALDATA const volatile boolean LampCtl_LowBeamVal_C;/* Referenced by: '<S673>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_NightVal_C;/* Referenced by: '<S652>/Chart' */
extern CALDATA const volatile uint16 LampCtl_OsUnlckDelayTim_C;/* Referenced by: '<S900>/Constant3' */
extern CALDATA const volatile uint16 LampCtl_PassLightMaxTim_C;/* Referenced by: '<S670>/Constant1' */
extern CALDATA const volatile uint16 LampCtl_PassLightTimInValid_C;/* Referenced by: '<S673>/Constant29' */
extern CALDATA const volatile uint16 LampCtl_PassLightTimValid_C;/* Referenced by: '<S673>/Constant28' */
extern CALDATA const volatile boolean LampCtl_PassLightVal_C;/* Referenced by: '<S673>/Constant2' */
extern CALDATA const volatile boolean LampCtl_PosLampStaOvrdFlg_C;/* Referenced by: '<S436>/Constant18' */
extern CALDATA const volatile boolean LampCtl_PosLampStaOvrdVal_C;/* Referenced by: '<S436>/Constant19' */
extern CALDATA const volatile uint16 LampCtl_PosLampStaTimInValid_C;/* Referenced by: '<S671>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_PosLampStaTimValid_C;/* Referenced by: '<S671>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_PosLampTimInValid_C;/* Referenced by: '<S673>/Constant20' */
extern CALDATA const volatile uint16 LampCtl_PosLampTimValid_C;/* Referenced by: '<S673>/Constant19' */
extern CALDATA const volatile boolean LampCtl_PosLampVal_C;/* Referenced by: '<S673>/Constant50' */
extern CALDATA const volatile uint16 LampCtl_RKECmdClearCnt_C;
                                     /* Referenced by: '<S673>/ClearRKECommd' */
extern CALDATA const volatile uint8 LampCtl_ROpenCnt_C;/* Referenced by: '<S791>/Constant8' */
extern CALDATA const volatile uint8 LampCtl_RShortCnt_C;/* Referenced by: '<S791>/Constant16' */
extern CALDATA const volatile uint8 LampCtl_RemtCmdFbCnt_C;/* Referenced by: '<S797>/SeekFb' */
extern CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdFlg_C;/* Referenced by: '<S436>/Constant16' */
extern CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdVal_C;/* Referenced by: '<S436>/Constant15' */
extern CALDATA const volatile uint16 LampCtl_TrunkWarnTim_C;/* Referenced by: '<S789>/Chart' */
extern CALDATA const volatile float32 LampCtl_Ts_C;/* Referenced by:
                                                    * '<S642>/Constant45'
                                                    * '<S642>/Constant7'
                                                    * '<S645>/Constant18'
                                                    * '<S645>/Constant30'
                                                    * '<S649>/Constant30'
                                                    * '<S650>/Constant21'
                                                    * '<S653>/Constant13'
                                                    * '<S653>/Constant30'
                                                    * '<S671>/Constant13'
                                                    * '<S673>/Constant13'
                                                    * '<S673>/Constant16'
                                                    * '<S673>/Constant21'
                                                    * '<S673>/Constant22'
                                                    * '<S673>/Constant27'
                                                    * '<S673>/Constant30'
                                                    * '<S673>/Constant33'
                                                    * '<S673>/Constant36'
                                                    * '<S673>/Constant39'
                                                    * '<S673>/Constant42'
                                                    * '<S673>/Constant45'
                                                    * '<S673>/Constant49'
                                                    * '<S673>/Constant67'
                                                    * '<S673>/Constant72'
                                                    * '<S699>/Constant5'
                                                    * '<S699>/Constant8'
                                                    * '<S701>/Constant21'
                                                    * '<S787>/Constant21'
                                                    * '<S791>/Constant13'
                                                    * '<S791>/Constant18'
                                                    * '<S791>/Constant45'
                                                    * '<S791>/Constant6'
                                                    */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimInValid_C;/* Referenced by: '<S791>/Constant44' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimValid_C;/* Referenced by: '<S791>/Constant43' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimInValid_C;/* Referenced by: '<S791>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimValid_C;/* Referenced by: '<S791>/Constant9' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdFlg_C;/* Referenced by: '<S436>/Constant25' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdVal_C;/* Referenced by: '<S436>/Constant26' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLTimInValid_C;/* Referenced by: '<S673>/Constant32' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLTimValid_C;/* Referenced by: '<S673>/Constant31' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLVal_C;/* Referenced by: '<S673>/Constant54' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimInValid_C;/* Referenced by: '<S673>/Constant35' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimValid_C;/* Referenced by: '<S673>/Constant34' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimInValid_C;/* Referenced by: '<S673>/Constant41' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimValid_C;/* Referenced by: '<S673>/Constant40' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrOpenCur_C;/* Referenced by:
                                                                 * '<S791>/Constant11'
                                                                 * '<S791>/Constant21'
                                                                 */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimInValid_C;/* Referenced by: '<S791>/Constant3' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimValid_C;/* Referenced by: '<S791>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimInValid_C;/* Referenced by: '<S791>/Constant12' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimValid_C;/* Referenced by: '<S791>/Constant14' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdFlg_C;/* Referenced by: '<S436>/Constant23' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdVal_C;/* Referenced by: '<S436>/Constant24' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRTimInValid_C;/* Referenced by: '<S673>/Constant38' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRTimValid_C;/* Referenced by: '<S673>/Constant37' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRVal_C;/* Referenced by: '<S673>/Constant5' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrShortCur_C;/* Referenced by:
                                                                  * '<S791>/Constant20'
                                                                  * '<S791>/Constant4'
                                                                  */
extern CALDATA const volatile uint16 LampCtl_WelcomeLampTimMax_C;/* Referenced by: '<S899>/Constant6' */
extern CALDATA const volatile uint16 PDUCtl_EmerPwrOffTimInValid_C;/* Referenced by: '<S916>/Constant20' */
extern CALDATA const volatile uint16 PDUCtl_EmerPwrOffTimValid_C;/* Referenced by: '<S916>/Constant19' */
extern CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdFlg_C;/* Referenced by: '<S437>/Constant18' */
extern CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdVal_C;/* Referenced by: '<S437>/Constant19' */
extern CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdFlg_C;/* Referenced by: '<S437>/Constant1' */
extern CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdVal_C;/* Referenced by: '<S437>/Constant2' */
extern CALDATA const volatile boolean PDUCtl_KeyValidOvrdFlg_C;/* Referenced by:
                                                                * '<S917>/Constant12'
                                                                * '<S917>/Constant9'
                                                                */
extern CALDATA const volatile boolean PDUCtl_KeyValidOvrdVal_C;/* Referenced by:
                                                                * '<S917>/Constant10'
                                                                * '<S917>/Constant11'
                                                                */
extern CALDATA const volatile uint16 PDUCtl_OTAOverTimPwrOff_C;/* Referenced by: '<S916>/Constant37' */
extern CALDATA const volatile uint16 PDUCtl_OTAPwrOnDelayTim_C;/* Referenced by: '<S917>/Constant16' */
extern CALDATA const volatile uint16 PDUCtl_OpenDoorPwrOnTimValid;/* Referenced by: '<S917>/Constant6' */
extern CALDATA const volatile uint16 PDUCtl_PwrOnPSTimValid_C;/* Referenced by: '<S917>/Constant3' */
extern CALDATA const volatile uint8 PDUCtl_RemtCmdFbCnt_C;
                                      /* Referenced by: '<S437>/RemtPwrCtlFb' */
extern CALDATA const volatile uint16 PDUCtl_RemtPasvBrkSwTimValid_C;/* Referenced by: '<S916>/Constant33' */
extern CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffH_C;/* Referenced by: '<S916>/Constant25' */
extern CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffM_C;/* Referenced by: '<S916>/Constant26' */
extern CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffS_C;/* Referenced by: '<S916>/Constant27' */
extern CALDATA const volatile uint16 PDUCtl_StartReqOverTimValid_C;/* Referenced by: '<S920>/Constant5' */
extern CALDATA const volatile uint16 PDUCtl_StartReqTimValid_C;/* Referenced by: '<S920>/Constant4' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffH_C;/* Referenced by: '<S916>/Constant4' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffM_C;/* Referenced by: '<S916>/Constant5' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffS_C;/* Referenced by: '<S916>/Constant6' */
extern CALDATA const volatile float32 PDUCtl_Ts_C;/* Referenced by:
                                                   * '<S916>/Constant21'
                                                   * '<S916>/Constant28'
                                                   * '<S916>/Constant7'
                                                   * '<S917>/Constant17'
                                                   * '<S918>/Constant13'
                                                   * '<S918>/Constant6'
                                                   * '<S918>/Constant8'
                                                   */
extern CALDATA const volatile boolean RVMCtl_J42HeatOvrdFlg_C;/* Referenced by: '<S8>/Constant18' */
extern CALDATA const volatile boolean RVMCtl_J42HeatOvrdVal_C;/* Referenced by: '<S8>/Constant19' */
extern CALDATA const volatile uint8 RVMCtl_MaxHeatTimM_C;/* Referenced by: '<S141>/Constant2' */
extern CALDATA const volatile float32 RVMCtl_Ts_C;/* Referenced by: '<S141>/Constant7' */
extern CALDATA const volatile boolean SeatCtl_CN167DrvSeatHtPWMOvrdFlg_C;/* Referenced by: '<S145>/Constant18' */
extern CALDATA const volatile uint8 SeatCtl_CN167DrvSeatHtPWMOvrdVal_C;/* Referenced by: '<S145>/Constant19' */
extern CALDATA const volatile float32 SeatCtl_DrvSeatTempLookUp_X[23];
                                 /* Referenced by: '<S145>/1-D Lookup Table2' */
extern CALDATA const volatile float32 SeatCtl_DrvSeatTempLookUp_Y[23];
                                 /* Referenced by: '<S145>/1-D Lookup Table2' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl0_C;/* Referenced by: '<S145>/Constant8' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl1_C;/* Referenced by: '<S145>/Constant5' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl2_C;/* Referenced by: '<S145>/Constant6' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl3_C;/* Referenced by: '<S145>/Constant7' */
extern CALDATA const volatile uint8 SeatCtl_HtDiffTemp_C;/* Referenced by: '<S145>/Chart' */
extern CALDATA const volatile uint16 SeatCtl_NTCOpenInValidTim_C;/* Referenced by: '<S145>/Constant16' */
extern CALDATA const volatile float32 SeatCtl_NTCOpenResis_C;/* Referenced by: '<S145>/Constant11' */
extern CALDATA const volatile uint16 SeatCtl_NTCOpenValidTim_C;/* Referenced by: '<S145>/Constant15' */
extern CALDATA const volatile uint16 SeatCtl_NTCShortInValidTim_C;/* Referenced by: '<S145>/Constant13' */
extern CALDATA const volatile float32 SeatCtl_NTCShortResis_C;/* Referenced by: '<S145>/Constant' */
extern CALDATA const volatile uint16 SeatCtl_NTCShortValidTim_C;/* Referenced by: '<S145>/Constant12' */
extern CALDATA const volatile uint8 SeatCtl_RemtCmdFdCnt_C;/* Referenced by: '<S145>/HeatFb' */
extern CALDATA const volatile float32 SeatCtl_Ts_C;/* Referenced by:
                                                    * '<S145>/Constant14'
                                                    * '<S145>/Constant17'
                                                    */
extern CALDATA const volatile uint8 SteerWhlCtl_DiffTemp_C;/* Referenced by: '<S153>/HeatCtl' */
extern CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdFlg_C;/* Referenced by: '<S153>/Constant18' */
extern CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdVal_C;/* Referenced by: '<S153>/Constant19' */
extern CALDATA const volatile uint8 SteerWhlCtl_RemtCmdFbCnt_C;/* Referenced by: '<S153>/HeatFb' */
extern CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_X[18];
                                 /* Referenced by: '<S153>/1-D Lookup Table1' */
extern CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_Y[18];
                                 /* Referenced by: '<S153>/1-D Lookup Table1' */
extern CALDATA const volatile uint8 SteerWhlCtl_TrgtTemp_C;/* Referenced by: '<S153>/HeatCtl' */
extern CALDATA const volatile uint16 WakeUpCtl_CANSleepDelayTim_C;/* Referenced by: '<S967>/Constant22' */
extern CALDATA const volatile uint16 WakeUpCtl_LocalSleepDelayTim_C;/* Referenced by: '<S968>/Constant27' */
extern CALDATA const volatile uint16 WakeUpCtl_WinCtlDelayTim_C;/* Referenced by: '<S967>/Constant3' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMaxResis_C;/* Referenced by: '<S169>/Constant51' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMinResis_C;/* Referenced by: '<S169>/Constant50' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimInValid_C;/* Referenced by: '<S169>/Constant10' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimValid_C;/* Referenced by: '<S169>/Constant9' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMaxResis_C;/* Referenced by: '<S169>/Constant49' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMinResis_C;/* Referenced by: '<S169>/Constant48' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimInValid_C;/* Referenced by: '<S169>/Constant7' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimValid_C;/* Referenced by: '<S169>/Constant6' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinSwResis_C;/* Referenced by: '<S169>/Constant5' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMaxResis_C;/* Referenced by: '<S169>/Constant47' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMinResis_C;/* Referenced by: '<S169>/Constant46' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimInValid_C;/* Referenced by: '<S169>/Constant3' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimValid_C;/* Referenced by: '<S169>/Constant2' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMaxResis_C;/* Referenced by: '<S169>/Constant36' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMinResis_C;/* Referenced by: '<S169>/Constant35' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimInValid_C;/* Referenced by: '<S169>/Constant24' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimValid_C;/* Referenced by: '<S169>/Constant23' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnMaxResis_C;/* Referenced by: '<S169>/Constant31' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnMinResis_C;/* Referenced by: '<S169>/Constant26' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnTimInValid_C;/* Referenced by: '<S169>/Constant18' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnTimValid_C;/* Referenced by: '<S169>/Constant17' */
extern CALDATA const volatile uint16 WinCtl_DrvWinSwResis_C;/* Referenced by: '<S169>/Constant15' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpMaxResis_C;/* Referenced by: '<S169>/Constant22' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpMinResis_C;/* Referenced by: '<S169>/Constant20' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpTimInValid_C;/* Referenced by: '<S169>/Constant13' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpTimValid_C;/* Referenced by: '<S169>/Constant12' */
extern CALDATA const volatile uint16 WinCtl_InportCalSwBit_C;/* Referenced by:
                                                              * '<S169>/Constant1'
                                                              * '<S169>/Constant11'
                                                              * '<S169>/Constant21'
                                                              */
extern CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdFlg_C;/* Referenced by: '<S12>/Constant18' */
extern CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdVal_C;/* Referenced by: '<S12>/Constant19' */
extern CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdFlg_C;/* Referenced by: '<S12>/Constant1' */
extern CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdVal_C;/* Referenced by: '<S12>/Constant2' */
extern CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdFlg_C;/* Referenced by: '<S12>/Constant3' */
extern CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdVal_C;/* Referenced by: '<S12>/Constant4' */
extern CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdFlg_C;/* Referenced by: '<S12>/Constant5' */
extern CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdVal_C;/* Referenced by: '<S12>/Constant6' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMaxResis_C;/* Referenced by: '<S169>/Constant45' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMinResis_C;/* Referenced by: '<S169>/Constant44' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimInValid_C;/* Referenced by: '<S169>/Constant38' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimValid_C;/* Referenced by: '<S169>/Constant37' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnMaxResis_C;/* Referenced by: '<S169>/Constant43' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnMinResis_C;/* Referenced by: '<S169>/Constant42' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnTimInValid_C;/* Referenced by: '<S169>/Constant33' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnTimValid_C;/* Referenced by: '<S169>/Constant32' */
extern CALDATA const volatile uint16 WinCtl_PsgWinSwResis_C;/* Referenced by: '<S169>/Constant30' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpMaxResis_C;/* Referenced by: '<S169>/Constant41' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpMinResis_C;/* Referenced by: '<S169>/Constant40' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpTimInValid_C;/* Referenced by: '<S169>/Constant28' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpTimValid_C;/* Referenced by: '<S169>/Constant27' */
extern CALDATA const volatile uint16 WinCtl_PwrOffWinValidTimMax_C;/* Referenced by: '<S171>/Constant20' */
extern CALDATA const volatile float32 WinCtl_Ts_C;/* Referenced by:
                                                   * '<S169>/Constant14'
                                                   * '<S169>/Constant16'
                                                   * '<S169>/Constant19'
                                                   * '<S169>/Constant25'
                                                   * '<S169>/Constant29'
                                                   * '<S169>/Constant34'
                                                   * '<S169>/Constant39'
                                                   * '<S169>/Constant4'
                                                   * '<S169>/Constant8'
                                                   * '<S171>/Constant10'
                                                   * '<S171>/Constant36'
                                                   */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurMax_C;/* Referenced by:
                                                              * '<S171>/Constant37'
                                                              * '<S171>/Constant48'
                                                              */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurTimInValid_C;/* Referenced by:
                                                                     * '<S171>/Constant35'
                                                                     * '<S171>/Constant44'
                                                                     */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurTimValid_C;/* Referenced by:
                                                                   * '<S171>/Constant11'
                                                                   * '<S171>/Constant34'
                                                                   */
extern CALDATA const volatile uint16 WinCtl_WinProtNum_C;/* Referenced by:
                                                          * '<S170>/Constant15'
                                                          * '<S170>/Constant2'
                                                          * '<S170>/Constant6'
                                                          * '<S170>/Constant9'
                                                          */
extern CALDATA const volatile uint16 WinCtl_WinProtTim_C;/* Referenced by:
                                                          * '<S170>/Constant1'
                                                          * '<S170>/Constant14'
                                                          * '<S170>/Constant5'
                                                          * '<S170>/Constant8'
                                                          */
extern CALDATA const volatile uint16 WinCtl_WinRunTimMax_C;/* Referenced by:
                                                            * '<S171>/Constant40'
                                                            * '<S171>/Constant47'
                                                            * '<S171>/Constant8'
                                                            */
extern CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdFlg_C;/* Referenced by: '<S291>/Constant3' */
extern CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdVal_C;/* Referenced by: '<S291>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_HiSpdTimInValid_C;/* Referenced by: '<S379>/Constant22' */
extern CALDATA const volatile uint16 WiperCtl_HiSpdTimValid_C;/* Referenced by: '<S379>/Constant21' */
extern CALDATA const volatile uint16 WiperCtl_InportCalSwBit_C;/* Referenced by:
                                                                * '<S379>/Constant28'
                                                                * '<S379>/Constant35'
                                                                * '<S379>/Constant59'
                                                                */
extern CALDATA const volatile uint16 WiperCtl_InrLvl1Tim_C;/* Referenced by: '<S383>/Constant1' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl2Tim_C;/* Referenced by: '<S383>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl3Tim_C;/* Referenced by:
                                                            * '<S383>/Constant3'
                                                            * '<S383>/Constant8'
                                                            */
extern CALDATA const volatile uint16 WiperCtl_InrLvl4Tim_C;/* Referenced by: '<S383>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl5Tim_C;/* Referenced by: '<S383>/Constant5' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl6Tim_C;/* Referenced by: '<S383>/Constant6' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl7Tim_C;/* Referenced by: '<S383>/Constant7' */
extern CALDATA const volatile uint16 WiperCtl_InrTimInValid_C;/* Referenced by: '<S379>/Constant9' */
extern CALDATA const volatile uint16 WiperCtl_InrTimValid_C;/* Referenced by: '<S379>/Constant8' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimDef_C;/* Referenced by: '<S375>/Constant1' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimOk_C;/* Referenced by: '<S375>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkDef_C;/* Referenced by: '<S375>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkOk_C;/* Referenced by: '<S375>/Constant5' */
extern CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdFlg_C;/* Referenced by: '<S291>/Constant1' */
extern CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdVal_C;/* Referenced by: '<S291>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_LowSpdTimInValid_C;/* Referenced by: '<S379>/Constant17' */
extern CALDATA const volatile uint16 WiperCtl_LowSpdTimValid_C;/* Referenced by: '<S379>/Constant16' */
extern CALDATA const volatile uint16 WiperCtl_MaintWiperRunTim_C;/* Referenced by: '<S381>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_MistTimInValid_C;/* Referenced by: '<S379>/Constant47' */
extern CALDATA const volatile uint16 WiperCtl_MistTimValid_C;/* Referenced by: '<S379>/Constant46' */
extern CALDATA const volatile uint16 WiperCtl_OffTimInValid_C;/* Referenced by: '<S379>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_OffTimValid_C;/* Referenced by: '<S379>/Constant3' */
extern CALDATA const volatile float32 WiperCtl_Ts_C;/* Referenced by:
                                                     * '<S379>/Constant10'
                                                     * '<S379>/Constant11'
                                                     * '<S379>/Constant18'
                                                     * '<S379>/Constant27'
                                                     * '<S379>/Constant34'
                                                     * '<S379>/Constant49'
                                                     * '<S379>/Constant5'
                                                     * '<S380>/Constant34'
                                                     */
extern CALDATA const volatile uint8 WiperCtl_WashAfterNum_C;/* Referenced by: '<S381>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_WashAfterTim_C;/* Referenced by: '<S381>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_WashMaxTim_C;/* Referenced by: '<S380>/Constant' */
extern CALDATA const volatile uint16 WiperCtl_WashMinTim_C;/* Referenced by: '<S380>/Constant3' */
extern CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdFlg_C;/* Referenced by: '<S291>/Constant18' */
extern CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdVal_C;/* Referenced by: '<S291>/Constant19' */
extern CALDATA const volatile uint16 WiperCtl_WashTimInValid_C;/* Referenced by: '<S379>/Constant26' */
extern CALDATA const volatile uint16 WiperCtl_WashTimValid_C;/* Referenced by: '<S379>/Constant25' */
extern CALDATA const volatile boolean WiperCtl_WashVal_C;/* Referenced by: '<S379>/Constant29' */

/* 低有效 */
extern CALDATA const volatile uint16 WiperCtl_WiperParkPosTimValid_C;/* Referenced by: '<S379>/Constant32' */
extern CALDATA const volatile boolean WiperCtl_WiperParkPosVal_C;/* Referenced by: '<S379>/Constant36' */

/* 低有效 */
extern CALDATA const volatile uint16 WiperCtl_WiperPosTimInValid_C;/* Referenced by: '<S379>/Constant33' */
extern CALDATA const volatile uint16 WiperCtl_WiperReturnDelayTim_C;/* Referenced by: '<S381>/Chart' */
extern CALDATA const volatile uint8 WiperCtl_WiperSwVal_C;/* Referenced by: '<S379>/Constant60' */

#endif                                 /* RTW_HEADER_calPrmsBcm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
