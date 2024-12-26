/*
 * File: calPrmsBcm.h
 *
 * Code generated for Simulink model 'AppSwcBcm'.
 *
 * Model version                  : 1.1537
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Fri Dec 20 09:37:55 2024
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
extern CALDATA const volatile uint16 AlmSysCtl_AlrmTimLimit_C;/* Referenced by: '<S405>/AlmSysLogic' */
extern CALDATA const volatile uint16 BatSaveCtl_DlyTim_C;/* Referenced by: '<S433>/Constant2' */
extern CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdFlg_C;/* Referenced by: '<S406>/Constant18' */
extern CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdVal_C;/* Referenced by: '<S406>/Constant19' */
extern CALDATA const volatile uint16 BatSaveCtl_LckDlyTim_C;/* Referenced by: '<S433>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_AntiLckProtTim_C;/* Referenced by: '<S449>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_AutoLckDelayTim_C;/* Referenced by: '<S489>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_CntSubTim_C;/* Referenced by: '<S455>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimInValid_C;/* Referenced by: '<S446>/Constant2' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimValid_C;/* Referenced by: '<S446>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarFLVal_C;/* Referenced by: '<S446>/Constant4' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimInValid_C;/* Referenced by: '<S446>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimValid_C;/* Referenced by: '<S446>/Constant6' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarFRVal_C;/* Referenced by: '<S446>/Constant9' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimInvalid_C;/* Referenced by: '<S446>/Constant35' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimValid_C;/* Referenced by: '<S446>/Constant34' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarRLVal_C;/* Referenced by: '<S446>/Constant18' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimInvalid_C;/* Referenced by: '<S446>/Constant38' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimValid_C;/* Referenced by: '<S446>/Constant37' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarRRVal_C;/* Referenced by: '<S446>/Constant20' */
extern CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimInValid_C;/* Referenced by: '<S446>/Constant47' */
extern CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimValid_C;/* Referenced by: '<S446>/Constant46' */
extern CALDATA const volatile boolean DoorLckCtl_DriverDoorLckVal_C;/* Referenced by: '<S446>/Constant60' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvPETimInvalid_C;/* Referenced by: '<S446>/Constant26' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvPETimValid_C;/* Referenced by: '<S446>/Constant25' */
extern CALDATA const volatile boolean DoorLckCtl_DrvPEVal_C;/* Referenced by: '<S446>/Constant12' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisMin_C;/* Referenced by: '<S446>/Constant67' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisVal_C;/* Referenced by: '<S446>/Constant63' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimInValid_C;/* Referenced by: '<S446>/Constant65' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimValid_C;/* Referenced by: '<S446>/Constant64' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvTim_C;/* Referenced by: '<S407>/DoorDrv' */
extern CALDATA const volatile uint8 DoorLckCtl_EEIlluminatedEntrySys_C;/* Referenced by: '<S446>/Constant74' */
extern CALDATA const volatile uint8 DoorLckCtl_EEKeyEntry_C;/* Referenced by: '<S446>/Constant72' */
extern CALDATA const volatile uint8 DoorLckCtl_IllmndSts_C;/* Referenced by: '<S446>/Constant76' */
extern CALDATA const volatile uint16 DoorLckCtl_InportCalSwBit_C;/* Referenced by:
                                                                  * '<S446>/Constant10'
                                                                  * '<S446>/Constant11'
                                                                  * '<S446>/Constant13'
                                                                  * '<S446>/Constant15'
                                                                  * '<S446>/Constant17'
                                                                  * '<S446>/Constant19'
                                                                  * '<S446>/Constant21'
                                                                  * '<S446>/Constant5'
                                                                  * '<S446>/Constant59'
                                                                  * '<S446>/Constant62'
                                                                  * '<S446>/Constant71'
                                                                  * '<S446>/Constant73'
                                                                  * '<S446>/Constant75'
                                                                  */
extern CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdFlg_C;/* Referenced by: '<S407>/Constant3' */
extern CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdVal_C;/* Referenced by: '<S407>/Constant4' */
extern CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdFlg_C;/* Referenced by: '<S407>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdVal_C;/* Referenced by: '<S407>/Constant2' */
extern CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdFlg_C;/* Referenced by: '<S407>/Constant18' */
extern CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdVal_C;/* Referenced by: '<S407>/Constant19' */
extern CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMaxTim_C;/* Referenced by: '<S407>/DoorDrv' */
extern CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMinTim_C;/* Referenced by: '<S407>/DoorDrv' */
extern CALDATA const volatile uint16 DoorLckCtl_MotorProtTimMax_C;/* Referenced by: '<S455>/Constant2' */
extern CALDATA const volatile uint8 DoorLckCtl_MotorWorkMax_C;/* Referenced by: '<S455>/Constant1' */
extern CALDATA const volatile uint16 DoorLckCtl_PEProtCnt_C;/* Referenced by: '<S458>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_PEProtIntvlTim_C;/* Referenced by: '<S458>/Constant2' */
extern CALDATA const volatile uint16 DoorLckCtl_PsgPETimInvalid_C;/* Referenced by:
                                                                   * '<S446>/Constant29'
                                                                   * '<S446>/Constant32'
                                                                   */
extern CALDATA const volatile uint16 DoorLckCtl_PsgPETimValid_C;/* Referenced by:
                                                                 * '<S446>/Constant28'
                                                                 * '<S446>/Constant31'
                                                                 */
extern CALDATA const volatile boolean DoorLckCtl_PsgPEVal_C;/* Referenced by: '<S446>/Constant14' */
extern CALDATA const volatile uint16 DoorLckCtl_SpdLckTimInValid_C;/* Referenced by:
                                                                    * '<S466>/Constant10'
                                                                    * '<S466>/Constant3'
                                                                    */
extern CALDATA const volatile uint16 DoorLckCtl_SpdLckTimValid_C;/* Referenced by:
                                                                  * '<S466>/Constant2'
                                                                  * '<S466>/Constant9'
                                                                  */
extern CALDATA const volatile uint8 DoorLckCtl_SpdLck_C;/* Referenced by:
                                                         * '<S466>/Chart'
                                                         * '<S466>/Constant'
                                                         */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimInvalid_C;/* Referenced by: '<S446>/Constant41' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimValid_C;/* Referenced by: '<S446>/Constant40' */
extern CALDATA const volatile boolean DoorLckCtl_TrunkAjarVal_C;/* Referenced by: '<S446>/Constant22' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAutoLckTim_C;/* Referenced by: '<S494>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_TrunkSwVal_C;/* Referenced by: '<S446>/Constant16' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimInvalid_C;/* Referenced by: '<S516>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimValid_C;/* Referenced by: '<S516>/Constant2' */
extern CALDATA const volatile float32 DoorLckCtl_Ts_C;/* Referenced by:
                                                       * '<S446>/Constant27'
                                                       * '<S446>/Constant3'
                                                       * '<S446>/Constant30'
                                                       * '<S446>/Constant33'
                                                       * '<S446>/Constant36'
                                                       * '<S446>/Constant39'
                                                       * '<S446>/Constant42'
                                                       * '<S446>/Constant49'
                                                       * '<S446>/Constant66'
                                                       * '<S446>/Constant8'
                                                       * '<S466>/Constant11'
                                                       * '<S466>/Constant49'
                                                       * '<S490>/Constant42'
                                                       * '<S512>/Constant42'
                                                       * '<S512>/Constant7'
                                                       * '<S516>/Constant4'
                                                       */
extern CALDATA const volatile boolean EEWriteCtl_ImmOvrdFlg_C;/* Referenced by: '<S6>/EEWriteCtl' */
extern CALDATA const volatile uint8 EEWriteCtl_ImmOvrdVal_C[128];/* Referenced by: '<S6>/EEWriteCtl' */
extern CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdFlg_C;/* Referenced by: '<S606>/Constant18' */
extern CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdVal_C;/* Referenced by: '<S606>/Constant19' */
extern CALDATA const volatile uint16 ESCLCtl_LckDelay_C;/* Referenced by: '<S606>/ESCLLck' */
extern CALDATA const volatile uint16 ESCLCtl_LckTimMax_C;/* Referenced by: '<S606>/ESCLLck' */
extern CALDATA const volatile uint16 ESCLCtl_PwrOffDelay_C;/* Referenced by:
                                                            * '<S606>/ESCLLck'
                                                            * '<S606>/ESCLUnlck'
                                                            */
extern CALDATA const volatile uint16 ESCLCtl_UnlckDelay_C;/* Referenced by: '<S606>/ESCLUnlck' */
extern CALDATA const volatile uint16 ESCLCtl_UnlckTimMax_C;/* Referenced by: '<S606>/ESCLUnlck' */
extern CALDATA const volatile uint16 HornCtl_HornSwTimInvalid_C;/* Referenced by: '<S318>/Constant38' */
extern CALDATA const volatile uint16 HornCtl_HornSwTimValid_C;/* Referenced by: '<S318>/Constant37' */
extern CALDATA const volatile boolean HornCtl_J430HornDrvOvrdFlg_C;/* Referenced by: '<S269>/Constant18' */
extern CALDATA const volatile boolean HornCtl_J430HornDrvOvrdVal_C;/* Referenced by: '<S269>/Constant19' */
extern CALDATA const volatile float32 HornCtl_Ts_C;/* Referenced by: '<S318>/Constant39' */
extern CALDATA const volatile uint16 LampCtl_AutoLampDayDelayTim_C;/* Referenced by: '<S622>/Constant6' */
extern CALDATA const volatile uint16 LampCtl_AutoLampNightDelayTim_C;/* Referenced by: '<S622>/Constant43' */
extern CALDATA const volatile uint16 LampCtl_AutoLampTimInValid_C;/* Referenced by: '<S653>/Constant63' */
extern CALDATA const volatile uint16 LampCtl_AutoLampTimValid_C;/* Referenced by: '<S653>/Constant9' */
extern CALDATA const volatile boolean LampCtl_AutoLampVal_C;/* Referenced by: '<S653>/Constant8' */
extern CALDATA const volatile uint16 LampCtl_BoxLampOpenTimMax_C;/* Referenced by: '<S624>/Constant4' */
extern CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdFlg_C;/* Referenced by: '<S411>/Constant3' */
extern CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdVal_C;/* Referenced by: '<S411>/Constant4' */
extern CALDATA const volatile boolean LampCtl_BrakeLightVal_C;/* Referenced by:
                                                               * '<S653>/Constant62'
                                                               * '<S653>/Constant74'
                                                               */
extern CALDATA const volatile uint16 LampCtl_BrakeSwInValid_C;/* Referenced by:
                                                               * '<S653>/Constant15'
                                                               * '<S653>/Constant71'
                                                               */
extern CALDATA const volatile uint16 LampCtl_BrakeSwTimValid_C;/* Referenced by:
                                                                * '<S653>/Constant14'
                                                                * '<S653>/Constant70'
                                                                */
extern CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdFlg_C;/* Referenced by: '<S411>/Constant1' */
extern CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdVal_C;/* Referenced by: '<S411>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_DayTimeVal_C;/* Referenced by: '<S632>/Chart' */
extern CALDATA const volatile boolean LampCtl_DomeLampPwmDutyOvrdFlg_C;/* Referenced by: '<S411>/Constant22' */
extern CALDATA const volatile uint8 LampCtl_DomeLampPwmDutyOvrdVal_C;/* Referenced by: '<S411>/Constant21' */
extern CALDATA const volatile uint16 LampCtl_DoorOpenFLInValidTim_C;/* Referenced by: '<S676>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_DoorOpenFLValidTim_C;/* Referenced by: '<S676>/Constant3' */
extern CALDATA const volatile uint16 LampCtl_DoorOpenFRInValidTim_C;/* Referenced by: '<S676>/Constant7' */
extern CALDATA const volatile uint16 LampCtl_DoorOpenFRValidTim_C;/* Referenced by: '<S676>/Constant6' */
extern CALDATA const volatile uint16 LampCtl_FlwrMeHomeTimValid_C;/* Referenced by: '<S869>/Constant43' */
extern CALDATA const volatile boolean LampCtl_FogLampFStaOvrdFlg_C;/* Referenced by: '<S411>/Constant14' */
extern CALDATA const volatile boolean LampCtl_FogLampFStaOvrdVal_C;/* Referenced by: '<S411>/Constant13' */
extern CALDATA const volatile uint16 LampCtl_FogLampFTimInValid_C;/* Referenced by: '<S653>/Constant66' */
extern CALDATA const volatile uint16 LampCtl_FogLampFTimValid_C;/* Referenced by: '<S653>/Constant64' */
extern CALDATA const volatile boolean LampCtl_FogLampFVal_C;/* Referenced by: '<S653>/Constant69' */
extern CALDATA const volatile boolean LampCtl_FogLampRStaOvrdFlg_C;/* Referenced by: '<S411>/Constant12' */
extern CALDATA const volatile boolean LampCtl_FogLampRStaOvrdVal_C;/* Referenced by: '<S411>/Constant11' */
extern CALDATA const volatile uint16 LampCtl_FogLampRTimInValid_C;/* Referenced by: '<S653>/Constant44' */
extern CALDATA const volatile uint16 LampCtl_FogLampRTimValid_C;/* Referenced by: '<S653>/Constant43' */
extern CALDATA const volatile boolean LampCtl_FogLampRVal_C;/* Referenced by: '<S653>/Constant56' */
extern CALDATA const volatile uint16 LampCtl_HazardLightTimInValid_C;/* Referenced by: '<S653>/Constant47' */
extern CALDATA const volatile uint16 LampCtl_HazardLightTimValid_C;/* Referenced by: '<S653>/Constant46' */
extern CALDATA const volatile boolean LampCtl_HazardLightVal_C;/* Referenced by: '<S653>/Constant60' */
extern CALDATA const volatile uint16 LampCtl_HiBeamShortToBatTimInValid_C;/* Referenced by: '<S629>/Constant29' */
extern CALDATA const volatile boolean LampCtl_HiBeamStaOvrdFlg_C;/* Referenced by: '<S411>/Constant20' */
extern CALDATA const volatile boolean LampCtl_HiBeamStaOvrdVal_C;/* Referenced by: '<S411>/Constant17' */
extern CALDATA const volatile uint16 LampCtl_HiBeamTimInValid_C;/* Referenced by: '<S653>/Constant26' */
extern CALDATA const volatile uint16 LampCtl_HiBeamTimValid_C;/* Referenced by: '<S653>/Constant25' */
extern CALDATA const volatile boolean LampCtl_HiBeamVal_C;/* Referenced by: '<S653>/Constant11' */
extern CALDATA const volatile uint16 LampCtl_InportCalSwBit_C;/* Referenced by:
                                                               * '<S653>/Constant1'
                                                               * '<S653>/Constant12'
                                                               * '<S653>/Constant3'
                                                               * '<S653>/Constant4'
                                                               * '<S653>/Constant48'
                                                               * '<S653>/Constant53'
                                                               * '<S653>/Constant55'
                                                               * '<S653>/Constant59'
                                                               * '<S653>/Constant6'
                                                               * '<S653>/Constant61'
                                                               * '<S653>/Constant68'
                                                               * '<S653>/Constant73'
                                                               */
extern CALDATA const volatile boolean LampCtl_J408BackLampPWMOvrdFlg_C;/* Referenced by: '<S411>/Constant30' */
extern CALDATA const volatile uint8 LampCtl_J408BackLampPWMOvrdVal_C;/* Referenced by: '<S411>/Constant29' */
extern CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdFlg_C;/* Referenced by: '<S411>/Constant5' */
extern CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdVal_C;/* Referenced by: '<S411>/Constant6' */
extern CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdFlg_C;/* Referenced by: '<S411>/Constant7' */
extern CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdVal_C;/* Referenced by: '<S411>/Constant8' */
extern CALDATA const volatile boolean LampCtl_J449BoxLampOvrdFlg_C;/* Referenced by: '<S411>/Constant28' */
extern CALDATA const volatile boolean LampCtl_J449BoxLampOvrdVal_C;/* Referenced by: '<S411>/Constant27' */
extern CALDATA const volatile uint8 LampCtl_LOpenCnt_C;/* Referenced by: '<S765>/Constant17' */
extern CALDATA const volatile uint8 LampCtl_LShortCnt_C;/* Referenced by: '<S765>/Constant19' */
extern CALDATA const volatile uint16 LampCtl_LampDelayTim_C;/* Referenced by: '<S631>/Constant6' */
extern CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimInValid_C;/* Referenced by: '<S633>/Constant29' */
extern CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimValid_C;/* Referenced by: '<S633>/Constant28' */
extern CALDATA const volatile boolean LampCtl_LowBeamStaOvrdFlg_C;/* Referenced by: '<S411>/Constant9' */
extern CALDATA const volatile boolean LampCtl_LowBeamStaOvrdVal_C;/* Referenced by: '<S411>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_LowBeamStaTimInValid_C;/* Referenced by: '<S633>/Constant5' */
extern CALDATA const volatile uint16 LampCtl_LowBeamStaTimValid_C;/* Referenced by: '<S633>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_LowBeamTimInValid_C;/* Referenced by: '<S653>/Constant24' */
extern CALDATA const volatile uint16 LampCtl_LowBeamTimValid_C;/* Referenced by: '<S653>/Constant23' */
extern CALDATA const volatile boolean LampCtl_LowBeamVal_C;/* Referenced by: '<S653>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_NightVal_C;/* Referenced by: '<S632>/Chart' */
extern CALDATA const volatile uint16 LampCtl_OsUnlckDelayTim_C;/* Referenced by: '<S874>/Constant3' */
extern CALDATA const volatile uint16 LampCtl_PassLightTimInValid_C;/* Referenced by: '<S653>/Constant29' */
extern CALDATA const volatile uint16 LampCtl_PassLightTimValid_C;/* Referenced by: '<S653>/Constant28' */
extern CALDATA const volatile boolean LampCtl_PassLightVal_C;/* Referenced by: '<S653>/Constant2' */
extern CALDATA const volatile boolean LampCtl_PosLampStaOvrdFlg_C;/* Referenced by: '<S411>/Constant18' */
extern CALDATA const volatile boolean LampCtl_PosLampStaOvrdVal_C;/* Referenced by: '<S411>/Constant19' */
extern CALDATA const volatile uint16 LampCtl_PosLampStaTimInValid_C;/* Referenced by: '<S651>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_PosLampStaTimValid_C;/* Referenced by: '<S651>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_PosLampTimInValid_C;/* Referenced by: '<S653>/Constant20' */
extern CALDATA const volatile uint16 LampCtl_PosLampTimValid_C;/* Referenced by: '<S653>/Constant19' */
extern CALDATA const volatile boolean LampCtl_PosLampVal_C;/* Referenced by: '<S653>/Constant50' */
extern CALDATA const volatile uint8 LampCtl_ROpenCnt_C;/* Referenced by: '<S765>/Constant8' */
extern CALDATA const volatile uint8 LampCtl_RShortCnt_C;/* Referenced by: '<S765>/Constant16' */
extern CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdFlg_C;/* Referenced by: '<S411>/Constant16' */
extern CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdVal_C;/* Referenced by: '<S411>/Constant15' */
extern CALDATA const volatile uint16 LampCtl_TrunkWarnTim_C;/* Referenced by: '<S763>/Chart' */
extern CALDATA const volatile float32 LampCtl_Ts_C;/* Referenced by:
                                                    * '<S622>/Constant45'
                                                    * '<S622>/Constant7'
                                                    * '<S629>/Constant30'
                                                    * '<S630>/Constant21'
                                                    * '<S633>/Constant13'
                                                    * '<S633>/Constant30'
                                                    * '<S651>/Constant13'
                                                    * '<S653>/Constant13'
                                                    * '<S653>/Constant16'
                                                    * '<S653>/Constant21'
                                                    * '<S653>/Constant22'
                                                    * '<S653>/Constant27'
                                                    * '<S653>/Constant30'
                                                    * '<S653>/Constant33'
                                                    * '<S653>/Constant36'
                                                    * '<S653>/Constant39'
                                                    * '<S653>/Constant42'
                                                    * '<S653>/Constant45'
                                                    * '<S653>/Constant49'
                                                    * '<S653>/Constant67'
                                                    * '<S653>/Constant72'
                                                    * '<S676>/Constant5'
                                                    * '<S676>/Constant8'
                                                    * '<S678>/Constant21'
                                                    * '<S761>/Constant21'
                                                    * '<S765>/Constant13'
                                                    * '<S765>/Constant18'
                                                    * '<S765>/Constant45'
                                                    * '<S765>/Constant6'
                                                    */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimInValid_C;/* Referenced by: '<S765>/Constant44' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimValid_C;/* Referenced by: '<S765>/Constant43' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimInValid_C;/* Referenced by: '<S765>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimValid_C;/* Referenced by: '<S765>/Constant9' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdFlg_C;/* Referenced by: '<S411>/Constant25' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdVal_C;/* Referenced by: '<S411>/Constant26' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLTimInValid_C;/* Referenced by: '<S653>/Constant32' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLTimValid_C;/* Referenced by: '<S653>/Constant31' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLVal_C;/* Referenced by: '<S653>/Constant54' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimInValid_C;/* Referenced by: '<S653>/Constant35' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimValid_C;/* Referenced by: '<S653>/Constant34' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimInValid_C;/* Referenced by: '<S653>/Constant41' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimValid_C;/* Referenced by: '<S653>/Constant40' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrOpenCur_C;/* Referenced by:
                                                                 * '<S765>/Constant11'
                                                                 * '<S765>/Constant21'
                                                                 */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimInValid_C;/* Referenced by: '<S765>/Constant3' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimValid_C;/* Referenced by: '<S765>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimInValid_C;/* Referenced by: '<S765>/Constant12' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimValid_C;/* Referenced by: '<S765>/Constant14' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdFlg_C;/* Referenced by: '<S411>/Constant23' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdVal_C;/* Referenced by: '<S411>/Constant24' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRTimInValid_C;/* Referenced by: '<S653>/Constant38' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRTimValid_C;/* Referenced by: '<S653>/Constant37' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRVal_C;/* Referenced by: '<S653>/Constant5' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrShortCur_C;/* Referenced by:
                                                                  * '<S765>/Constant20'
                                                                  * '<S765>/Constant4'
                                                                  */
extern CALDATA const volatile uint16 LampCtl_WelcomeLampTimMax_C;/* Referenced by: '<S873>/Constant6' */
extern CALDATA const volatile uint16 PDUCtl_EmerPwrOffTimInValid_C;/* Referenced by: '<S890>/Constant20' */
extern CALDATA const volatile uint16 PDUCtl_EmerPwrOffTimValid_C;/* Referenced by: '<S890>/Constant19' */
extern CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdFlg_C;/* Referenced by: '<S412>/Constant18' */
extern CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdVal_C;/* Referenced by: '<S412>/Constant19' */
extern CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdFlg_C;/* Referenced by: '<S412>/Constant1' */
extern CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdVal_C;/* Referenced by: '<S412>/Constant2' */
extern CALDATA const volatile boolean PDUCtl_KeyValidOvrdFlg_C;/* Referenced by:
                                                                * '<S891>/Constant12'
                                                                * '<S891>/Constant9'
                                                                */
extern CALDATA const volatile boolean PDUCtl_KeyValidOvrdVal_C;/* Referenced by:
                                                                * '<S891>/Constant10'
                                                                * '<S891>/Constant11'
                                                                */
extern CALDATA const volatile uint16 PDUCtl_OTAOverTimPwrOff_C;/* Referenced by: '<S890>/Constant37' */
extern CALDATA const volatile uint16 PDUCtl_OTAPwrOnDelayTim_C;/* Referenced by: '<S891>/Constant16' */
extern CALDATA const volatile uint16 PDUCtl_OpenDoorPwrOnTimValid;/* Referenced by: '<S891>/Constant6' */
extern CALDATA const volatile uint16 PDUCtl_PwrOnPSTimValid_C;/* Referenced by: '<S891>/Constant3' */
extern CALDATA const volatile uint16 PDUCtl_RemtPasvBrkSwTimValid_C;/* Referenced by: '<S890>/Constant33' */
extern CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffH_C;/* Referenced by: '<S890>/Constant25' */
extern CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffM_C;/* Referenced by: '<S890>/Constant26' */
extern CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffS_C;/* Referenced by: '<S890>/Constant27' */
extern CALDATA const volatile uint16 PDUCtl_StartReqOverTimValid_C;/* Referenced by: '<S894>/Constant5' */
extern CALDATA const volatile uint16 PDUCtl_StartReqTimValid_C;/* Referenced by: '<S894>/Constant4' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffH_C;/* Referenced by: '<S890>/Constant4' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffM_C;/* Referenced by: '<S890>/Constant5' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffS_C;/* Referenced by: '<S890>/Constant6' */
extern CALDATA const volatile float32 PDUCtl_Ts_C;/* Referenced by:
                                                   * '<S890>/Constant21'
                                                   * '<S890>/Constant28'
                                                   * '<S890>/Constant7'
                                                   * '<S891>/Constant17'
                                                   * '<S892>/Constant13'
                                                   * '<S892>/Constant6'
                                                   * '<S892>/Constant8'
                                                   */
extern CALDATA const volatile boolean RVMCtl_J42HeatOvrdFlg_C;/* Referenced by: '<S8>/Constant18' */
extern CALDATA const volatile boolean RVMCtl_J42HeatOvrdVal_C;/* Referenced by: '<S8>/Constant19' */
extern CALDATA const volatile uint8 RVMCtl_MaxHeatTimM_C;/* Referenced by: '<S132>/Constant2' */
extern CALDATA const volatile float32 RVMCtl_Ts_C;/* Referenced by: '<S132>/Constant7' */
extern CALDATA const volatile boolean SeatCtl_CN167DrvSeatHtPWMOvrdFlg_C;/* Referenced by: '<S136>/Constant18' */
extern CALDATA const volatile uint8 SeatCtl_CN167DrvSeatHtPWMOvrdVal_C;/* Referenced by: '<S136>/Constant19' */
extern CALDATA const volatile float32 SeatCtl_DrvSeatTempLookUp_X[23];
                                 /* Referenced by: '<S136>/1-D Lookup Table2' */
extern CALDATA const volatile float32 SeatCtl_DrvSeatTempLookUp_Y[23];
                                 /* Referenced by: '<S136>/1-D Lookup Table2' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl0_C;/* Referenced by: '<S136>/Constant8' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl1_C;/* Referenced by: '<S136>/Constant5' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl2_C;/* Referenced by: '<S136>/Constant6' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl3_C;/* Referenced by: '<S136>/Constant7' */
extern CALDATA const volatile uint8 SeatCtl_HtDiffTemp_C;/* Referenced by: '<S136>/Chart' */
extern CALDATA const volatile uint16 SeatCtl_NTCOpenInValidTim_C;/* Referenced by: '<S136>/Constant16' */
extern CALDATA const volatile float32 SeatCtl_NTCOpenResis_C;/* Referenced by: '<S136>/Constant11' */
extern CALDATA const volatile uint16 SeatCtl_NTCOpenValidTim_C;/* Referenced by: '<S136>/Constant15' */
extern CALDATA const volatile uint16 SeatCtl_NTCShortInValidTim_C;/* Referenced by: '<S136>/Constant13' */
extern CALDATA const volatile float32 SeatCtl_NTCShortResis_C;/* Referenced by: '<S136>/Constant' */
extern CALDATA const volatile uint16 SeatCtl_NTCShortValidTim_C;/* Referenced by: '<S136>/Constant12' */
extern CALDATA const volatile float32 SeatCtl_Ts_C;/* Referenced by:
                                                    * '<S136>/Constant14'
                                                    * '<S136>/Constant17'
                                                    */
extern CALDATA const volatile uint8 SteerWhlCtl_DiffTemp_C;/* Referenced by: '<S144>/HeatCtl' */
extern CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdFlg_C;/* Referenced by: '<S144>/Constant18' */
extern CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdVal_C;/* Referenced by: '<S144>/Constant19' */
extern CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_X[18];
                                 /* Referenced by: '<S144>/1-D Lookup Table1' */
extern CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_Y[18];
                                 /* Referenced by: '<S144>/1-D Lookup Table1' */
extern CALDATA const volatile uint8 SteerWhlCtl_TrgtTemp_C;/* Referenced by: '<S144>/HeatCtl' */
extern CALDATA const volatile uint16 WakeUpCtl_CANSleepDelayTim_C;/* Referenced by: '<S941>/Constant22' */
extern CALDATA const volatile uint16 WakeUpCtl_LocalSleepDelayTim_C;/* Referenced by: '<S942>/Constant27' */
extern CALDATA const volatile uint16 WakeUpCtl_WinCtlDelayTim_C;/* Referenced by: '<S941>/Constant3' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMaxResis_C;/* Referenced by: '<S157>/Constant51' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMinResis_C;/* Referenced by: '<S157>/Constant50' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimInValid_C;/* Referenced by: '<S157>/Constant10' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimValid_C;/* Referenced by: '<S157>/Constant9' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMaxResis_C;/* Referenced by: '<S157>/Constant49' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMinResis_C;/* Referenced by: '<S157>/Constant48' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimInValid_C;/* Referenced by: '<S157>/Constant7' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimValid_C;/* Referenced by: '<S157>/Constant6' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinSwResis_C;/* Referenced by: '<S157>/Constant5' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMaxResis_C;/* Referenced by: '<S157>/Constant47' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMinResis_C;/* Referenced by: '<S157>/Constant46' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimInValid_C;/* Referenced by: '<S157>/Constant3' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimValid_C;/* Referenced by: '<S157>/Constant2' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMaxResis_C;/* Referenced by: '<S157>/Constant36' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMinResis_C;/* Referenced by: '<S157>/Constant35' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimInValid_C;/* Referenced by: '<S157>/Constant24' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimValid_C;/* Referenced by: '<S157>/Constant23' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnMaxResis_C;/* Referenced by: '<S157>/Constant31' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnMinResis_C;/* Referenced by: '<S157>/Constant26' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnTimInValid_C;/* Referenced by: '<S157>/Constant18' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnTimValid_C;/* Referenced by: '<S157>/Constant17' */
extern CALDATA const volatile uint16 WinCtl_DrvWinSwResis_C;/* Referenced by: '<S157>/Constant15' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpMaxResis_C;/* Referenced by: '<S157>/Constant22' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpMinResis_C;/* Referenced by: '<S157>/Constant20' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpTimInValid_C;/* Referenced by: '<S157>/Constant13' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpTimValid_C;/* Referenced by: '<S157>/Constant12' */
extern CALDATA const volatile uint16 WinCtl_InportCalSwBit_C;/* Referenced by:
                                                              * '<S157>/Constant1'
                                                              * '<S157>/Constant11'
                                                              * '<S157>/Constant21'
                                                              */
extern CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdFlg_C;/* Referenced by: '<S11>/Constant18' */
extern CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdVal_C;/* Referenced by: '<S11>/Constant19' */
extern CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdFlg_C;/* Referenced by: '<S11>/Constant1' */
extern CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdVal_C;/* Referenced by: '<S11>/Constant2' */
extern CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdFlg_C;/* Referenced by: '<S11>/Constant3' */
extern CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdVal_C;/* Referenced by: '<S11>/Constant4' */
extern CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdFlg_C;/* Referenced by: '<S11>/Constant5' */
extern CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdVal_C;/* Referenced by: '<S11>/Constant6' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMaxResis_C;/* Referenced by: '<S157>/Constant45' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMinResis_C;/* Referenced by: '<S157>/Constant44' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimInValid_C;/* Referenced by: '<S157>/Constant38' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimValid_C;/* Referenced by: '<S157>/Constant37' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnMaxResis_C;/* Referenced by: '<S157>/Constant43' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnMinResis_C;/* Referenced by: '<S157>/Constant42' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnTimInValid_C;/* Referenced by: '<S157>/Constant33' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnTimValid_C;/* Referenced by: '<S157>/Constant32' */
extern CALDATA const volatile uint16 WinCtl_PsgWinSwResis_C;/* Referenced by: '<S157>/Constant30' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpMaxResis_C;/* Referenced by: '<S157>/Constant41' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpMinResis_C;/* Referenced by: '<S157>/Constant40' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpTimInValid_C;/* Referenced by: '<S157>/Constant28' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpTimValid_C;/* Referenced by: '<S157>/Constant27' */
extern CALDATA const volatile uint16 WinCtl_PwrOffWinValidTimMax_C;/* Referenced by: '<S159>/Constant20' */
extern CALDATA const volatile float32 WinCtl_Ts_C;/* Referenced by:
                                                   * '<S157>/Constant14'
                                                   * '<S157>/Constant16'
                                                   * '<S157>/Constant19'
                                                   * '<S157>/Constant25'
                                                   * '<S157>/Constant29'
                                                   * '<S157>/Constant34'
                                                   * '<S157>/Constant39'
                                                   * '<S157>/Constant4'
                                                   * '<S157>/Constant8'
                                                   * '<S159>/Constant10'
                                                   * '<S159>/Constant36'
                                                   */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurMax_C;/* Referenced by:
                                                              * '<S159>/Constant37'
                                                              * '<S159>/Constant48'
                                                              */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurTimInValid_C;/* Referenced by:
                                                                     * '<S159>/Constant35'
                                                                     * '<S159>/Constant44'
                                                                     */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurTimValid_C;/* Referenced by:
                                                                   * '<S159>/Constant11'
                                                                   * '<S159>/Constant34'
                                                                   */
extern CALDATA const volatile uint16 WinCtl_WinProtNum_C;/* Referenced by:
                                                          * '<S158>/Constant15'
                                                          * '<S158>/Constant2'
                                                          * '<S158>/Constant6'
                                                          * '<S158>/Constant9'
                                                          */
extern CALDATA const volatile uint16 WinCtl_WinProtTim_C;/* Referenced by:
                                                          * '<S158>/Constant1'
                                                          * '<S158>/Constant14'
                                                          * '<S158>/Constant5'
                                                          * '<S158>/Constant8'
                                                          */
extern CALDATA const volatile uint16 WinCtl_WinRunTimMax_C;/* Referenced by:
                                                            * '<S159>/Constant40'
                                                            * '<S159>/Constant47'
                                                            * '<S159>/Constant8'
                                                            */
extern CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdFlg_C;/* Referenced by: '<S270>/Constant3' */
extern CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdVal_C;/* Referenced by: '<S270>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_HiSpdTimInValid_C;/* Referenced by: '<S354>/Constant22' */
extern CALDATA const volatile uint16 WiperCtl_HiSpdTimValid_C;/* Referenced by: '<S354>/Constant21' */
extern CALDATA const volatile uint16 WiperCtl_InportCalSwBit_C;/* Referenced by:
                                                                * '<S354>/Constant28'
                                                                * '<S354>/Constant35'
                                                                * '<S354>/Constant59'
                                                                */
extern CALDATA const volatile uint16 WiperCtl_InrLvl1Tim_C;/* Referenced by: '<S358>/Constant1' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl2Tim_C;/* Referenced by: '<S358>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl3Tim_C;/* Referenced by:
                                                            * '<S358>/Constant3'
                                                            * '<S358>/Constant8'
                                                            */
extern CALDATA const volatile uint16 WiperCtl_InrLvl4Tim_C;/* Referenced by: '<S358>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl5Tim_C;/* Referenced by: '<S358>/Constant5' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl6Tim_C;/* Referenced by: '<S358>/Constant6' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl7Tim_C;/* Referenced by: '<S358>/Constant7' */
extern CALDATA const volatile uint16 WiperCtl_InrTimInValid_C;/* Referenced by: '<S354>/Constant9' */
extern CALDATA const volatile uint16 WiperCtl_InrTimValid_C;/* Referenced by: '<S354>/Constant8' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimDef_C;/* Referenced by: '<S350>/Constant1' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimOk_C;/* Referenced by: '<S350>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkDef_C;/* Referenced by: '<S350>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkOk_C;/* Referenced by: '<S350>/Constant5' */
extern CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdFlg_C;/* Referenced by: '<S270>/Constant1' */
extern CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdVal_C;/* Referenced by: '<S270>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_LowSpdTimInValid_C;/* Referenced by: '<S354>/Constant17' */
extern CALDATA const volatile uint16 WiperCtl_LowSpdTimValid_C;/* Referenced by: '<S354>/Constant16' */
extern CALDATA const volatile uint16 WiperCtl_MaintWiperRunTim_C;/* Referenced by: '<S356>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_MistTimInValid_C;/* Referenced by: '<S354>/Constant47' */
extern CALDATA const volatile uint16 WiperCtl_MistTimValid_C;/* Referenced by: '<S354>/Constant46' */
extern CALDATA const volatile uint16 WiperCtl_OffTimInValid_C;/* Referenced by: '<S354>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_OffTimValid_C;/* Referenced by: '<S354>/Constant3' */
extern CALDATA const volatile float32 WiperCtl_Ts_C;/* Referenced by:
                                                     * '<S354>/Constant10'
                                                     * '<S354>/Constant11'
                                                     * '<S354>/Constant18'
                                                     * '<S354>/Constant27'
                                                     * '<S354>/Constant34'
                                                     * '<S354>/Constant49'
                                                     * '<S354>/Constant5'
                                                     * '<S355>/Constant34'
                                                     */
extern CALDATA const volatile uint8 WiperCtl_WashAfterNum_C;/* Referenced by: '<S356>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_WashAfterTim_C;/* Referenced by: '<S356>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_WashMaxTim_C;/* Referenced by: '<S355>/Constant' */
extern CALDATA const volatile uint16 WiperCtl_WashMinTim_C;/* Referenced by: '<S355>/Constant3' */
extern CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdFlg_C;/* Referenced by: '<S270>/Constant18' */
extern CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdVal_C;/* Referenced by: '<S270>/Constant19' */
extern CALDATA const volatile uint16 WiperCtl_WashTimInValid_C;/* Referenced by: '<S354>/Constant26' */
extern CALDATA const volatile uint16 WiperCtl_WashTimValid_C;/* Referenced by: '<S354>/Constant25' */
extern CALDATA const volatile boolean WiperCtl_WashVal_C;/* Referenced by: '<S354>/Constant29' */

/* 低有效 */
extern CALDATA const volatile uint16 WiperCtl_WiperParkPosTimValid_C;/* Referenced by: '<S354>/Constant32' */
extern CALDATA const volatile boolean WiperCtl_WiperParkPosVal_C;/* Referenced by: '<S354>/Constant36' */

/* 低有效 */
extern CALDATA const volatile uint16 WiperCtl_WiperPosTimInValid_C;/* Referenced by: '<S354>/Constant33' */
extern CALDATA const volatile uint16 WiperCtl_WiperReturnDelayTim_C;/* Referenced by: '<S356>/Chart' */
extern CALDATA const volatile uint8 WiperCtl_WiperSwVal_C;/* Referenced by: '<S354>/Constant60' */

#endif                                 /* RTW_HEADER_calPrmsBcm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
