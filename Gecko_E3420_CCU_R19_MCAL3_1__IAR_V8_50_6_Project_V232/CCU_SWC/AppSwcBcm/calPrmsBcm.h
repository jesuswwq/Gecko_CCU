/*
 * File: calPrmsBcm.h
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

#ifndef RTW_HEADER_calPrmsBcm_h_
#define RTW_HEADER_calPrmsBcm_h_
#include "rtwtypes.h"
#include "AppSwcBcm_types.h"

/* Exported data declaration */

/*Group of variables*/
#include "XcpTest_types.h"

/* Declaration for custom storage class: CalParam */
extern CALDATA const volatile uint16 AlmSysCtl_AlrmTimLimit_C;/* Referenced by: '<S598>/AlmSysLogic' */
extern CALDATA const volatile uint16 BatSaveCtl_DlyTim_C;/* Referenced by: '<S625>/Constant2' */
extern CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdFlg_C;/* Referenced by: '<S599>/Constant18' */
extern CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdVal_C;/* Referenced by: '<S599>/Constant19' */
extern CALDATA const volatile uint16 BatSaveCtl_LckDlyTim_C;/* Referenced by: '<S625>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_AntiLckProtTim_C;/* Referenced by: '<S644>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_AutoLckDelayTim_C;/* Referenced by: '<S690>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_CntSubTim_C;/* Referenced by: '<S650>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_CrshPwrOnTimInValid_C;/* Referenced by: '<S672>/Constant4' */
extern CALDATA const volatile uint16 DoorLckCtl_CrshPwrOnTimValid_C;/* Referenced by: '<S672>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimInValid_C;/* Referenced by: '<S641>/Constant2' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimValid_C;/* Referenced by: '<S641>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarFLVal_C;/* Referenced by: '<S641>/Constant4' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimInValid_C;/* Referenced by: '<S641>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimValid_C;/* Referenced by: '<S641>/Constant6' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarFRVal_C;/* Referenced by: '<S641>/Constant9' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimInvalid_C;/* Referenced by: '<S641>/Constant35' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimValid_C;/* Referenced by: '<S641>/Constant34' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarRLVal_C;/* Referenced by: '<S641>/Constant18' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimInvalid_C;/* Referenced by: '<S641>/Constant38' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimValid_C;/* Referenced by: '<S641>/Constant37' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarRRVal_C;/* Referenced by: '<S641>/Constant20' */
extern CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimInValid_C;/* Referenced by: '<S641>/Constant47' */
extern CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimValid_C;/* Referenced by: '<S641>/Constant46' */
extern CALDATA const volatile boolean DoorLckCtl_DriverDoorLckVal_C;/* Referenced by: '<S641>/Constant60' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvPETimInvalid_C;/* Referenced by: '<S641>/Constant26' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvPETimValid_C;/* Referenced by: '<S641>/Constant25' */
extern CALDATA const volatile boolean DoorLckCtl_DrvPEVal_C;/* Referenced by: '<S641>/Constant12' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisMin_C;/* Referenced by: '<S641>/Constant67' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisVal_C;/* Referenced by: '<S641>/Constant63' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimInValid_C;/* Referenced by: '<S641>/Constant65' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimValid_C;/* Referenced by: '<S641>/Constant64' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvTim_C;/* Referenced by: '<S601>/DoorDrv' */
extern CALDATA const volatile uint8 DoorLckCtl_EEIlluminatedEntrySys_C;/* Referenced by: '<S641>/Constant74' */
extern CALDATA const volatile uint8 DoorLckCtl_EEKeyEntry_C;/* Referenced by: '<S641>/Constant72' */
extern CALDATA const volatile uint8 DoorLckCtl_IllmndSts_C;/* Referenced by: '<S641>/Constant76' */
extern CALDATA const volatile uint16 DoorLckCtl_InportCalSwBit_C;/* Referenced by:
                                                                  * '<S641>/Constant10'
                                                                  * '<S641>/Constant11'
                                                                  * '<S641>/Constant13'
                                                                  * '<S641>/Constant15'
                                                                  * '<S641>/Constant17'
                                                                  * '<S641>/Constant19'
                                                                  * '<S641>/Constant21'
                                                                  * '<S641>/Constant5'
                                                                  * '<S641>/Constant59'
                                                                  * '<S641>/Constant62'
                                                                  * '<S641>/Constant71'
                                                                  * '<S641>/Constant73'
                                                                  * '<S641>/Constant75'
                                                                  */
extern CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdFlg_C;/* Referenced by: '<S601>/Constant3' */
extern CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdVal_C;/* Referenced by: '<S601>/Constant4' */
extern CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdFlg_C;/* Referenced by: '<S601>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdVal_C;/* Referenced by: '<S601>/Constant2' */
extern CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdFlg_C;/* Referenced by: '<S601>/Constant18' */
extern CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdVal_C;/* Referenced by: '<S601>/Constant19' */
extern CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMaxTim_C;/* Referenced by: '<S601>/DoorDrv' */
extern CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMinTim_C;/* Referenced by: '<S601>/DoorDrv' */
extern CALDATA const volatile uint16 DoorLckCtl_MotorProtTimMax_C;/* Referenced by: '<S650>/Constant2' */
extern CALDATA const volatile uint8 DoorLckCtl_MotorWorkMax_C;/* Referenced by: '<S650>/Constant1' */
extern CALDATA const volatile uint16 DoorLckCtl_PEProtCnt_C;/* Referenced by: '<S653>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_PEProtIntvlTim_C;/* Referenced by: '<S653>/Constant2' */
extern CALDATA const volatile uint16 DoorLckCtl_PsgPETimInvalid_C;/* Referenced by:
                                                                   * '<S641>/Constant29'
                                                                   * '<S641>/Constant32'
                                                                   */
extern CALDATA const volatile uint16 DoorLckCtl_PsgPETimValid_C;/* Referenced by:
                                                                 * '<S641>/Constant28'
                                                                 * '<S641>/Constant31'
                                                                 */
extern CALDATA const volatile boolean DoorLckCtl_PsgPEVal_C;/* Referenced by: '<S641>/Constant14' */
extern CALDATA const volatile uint16 DoorLckCtl_SpdLckTimInValid_C;/* Referenced by:
                                                                    * '<S660>/Constant10'
                                                                    * '<S660>/Constant3'
                                                                    */
extern CALDATA const volatile uint16 DoorLckCtl_SpdLckTimValid_C;/* Referenced by:
                                                                  * '<S660>/Constant2'
                                                                  * '<S660>/Constant9'
                                                                  */
extern CALDATA const volatile uint8 DoorLckCtl_SpdLck_C;/* Referenced by: '<S660>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimInvalid_C;/* Referenced by: '<S641>/Constant41' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimValid_C;/* Referenced by: '<S641>/Constant40' */
extern CALDATA const volatile boolean DoorLckCtl_TrunkAjarVal_C;/* Referenced by: '<S641>/Constant22' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAutoLckTim_C;/* Referenced by: '<S694>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_TrunkSwVal_C;/* Referenced by: '<S641>/Constant16' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimInvalid_C;/* Referenced by: '<S716>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimValid_C;/* Referenced by: '<S716>/Constant2' */
extern CALDATA const volatile float32 DoorLckCtl_Ts_C;/* Referenced by:
                                                       * '<S641>/Constant27'
                                                       * '<S641>/Constant3'
                                                       * '<S641>/Constant30'
                                                       * '<S641>/Constant33'
                                                       * '<S641>/Constant36'
                                                       * '<S641>/Constant39'
                                                       * '<S641>/Constant42'
                                                       * '<S641>/Constant49'
                                                       * '<S641>/Constant66'
                                                       * '<S641>/Constant8'
                                                       * '<S660>/Constant11'
                                                       * '<S660>/Constant49'
                                                       * '<S672>/Constant6'
                                                       * '<S691>/Constant42'
                                                       * '<S713>/Constant42'
                                                       * '<S716>/Constant4'
                                                       */
extern CALDATA const volatile boolean EEWriteCtl_ImmOvrdFlg_C;/* Referenced by: '<S219>/EEWriteCtl' */
extern CALDATA const volatile uint8 EEWriteCtl_ImmOvrdVal_C[20];/* Referenced by: '<S219>/EEWriteCtl' */
extern CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdFlg_C;/* Referenced by: '<S768>/Constant18' */
extern CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdVal_C;/* Referenced by: '<S768>/Constant19' */
extern CALDATA const volatile uint16 ESCLCtl_LckDelay_C;/* Referenced by: '<S768>/ESCLLck' */
extern CALDATA const volatile uint16 ESCLCtl_LckTimMax_C;/* Referenced by: '<S768>/ESCLLck' */
extern CALDATA const volatile uint16 ESCLCtl_UnlckDelay_C;/* Referenced by: '<S768>/ESCLUnlck' */
extern CALDATA const volatile uint16 ESCLCtl_UnlckTimMax_C;/* Referenced by: '<S768>/ESCLUnlck' */
extern CALDATA const volatile uint16 HornCtl_HornSwTimInvalid_C;/* Referenced by: '<S266>/Constant38' */
extern CALDATA const volatile uint16 HornCtl_HornSwTimValid_C;/* Referenced by: '<S266>/Constant37' */
extern CALDATA const volatile boolean HornCtl_J430HornDrvOvrdFlg_C;/* Referenced by: '<S220>/Constant18' */
extern CALDATA const volatile boolean HornCtl_J430HornDrvOvrdVal_C;/* Referenced by: '<S220>/Constant19' */
extern CALDATA const volatile uint16 HornCtl_TrunkWarnTim_C;/* Referenced by: '<S271>/Chart' */
extern CALDATA const volatile float32 HornCtl_Ts_C;/* Referenced by: '<S266>/Constant39' */
extern CALDATA const volatile uint16 LampCtl_AutoLampDayDelayTim_C;/* Referenced by: '<S297>/Constant6' */
extern CALDATA const volatile uint16 LampCtl_AutoLampNightDelayTim_C;/* Referenced by: '<S297>/Constant43' */
extern CALDATA const volatile uint16 LampCtl_AutoLampTimInValid_C;/* Referenced by: '<S327>/Constant63' */
extern CALDATA const volatile uint16 LampCtl_AutoLampTimValid_C;/* Referenced by: '<S327>/Constant9' */
extern CALDATA const volatile boolean LampCtl_AutoLampVal_C;/* Referenced by: '<S327>/Constant8' */
extern CALDATA const volatile uint16 LampCtl_BoxLampOpenTimMax_C;/* Referenced by: '<S299>/Constant4' */
extern CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdFlg_C;/* Referenced by: '<S221>/Constant3' */
extern CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdVal_C;/* Referenced by: '<S221>/Constant4' */
extern CALDATA const volatile boolean LampCtl_BrakeLightVal_C;/* Referenced by:
                                                               * '<S327>/Constant62'
                                                               * '<S327>/Constant74'
                                                               */
extern CALDATA const volatile uint16 LampCtl_BrakeSwInValid_C;/* Referenced by:
                                                               * '<S327>/Constant15'
                                                               * '<S327>/Constant71'
                                                               */
extern CALDATA const volatile uint16 LampCtl_BrakeSwTimValid_C;/* Referenced by:
                                                                * '<S327>/Constant14'
                                                                * '<S327>/Constant70'
                                                                */
extern CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdFlg_C;/* Referenced by: '<S221>/Constant1' */
extern CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdVal_C;/* Referenced by: '<S221>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_DayTimeVal_C;/* Referenced by: '<S307>/Chart' */
extern CALDATA const volatile boolean LampCtl_DomeLampPwmDutyOvrdFlg_C;/* Referenced by: '<S221>/Constant22' */
extern CALDATA const volatile uint8 LampCtl_DomeLampPwmDutyOvrdVal_C;/* Referenced by: '<S221>/Constant21' */
extern CALDATA const volatile uint16 LampCtl_FlwrMeHomeTimValid_C;/* Referenced by: '<S525>/Constant43' */
extern CALDATA const volatile boolean LampCtl_FogLampFStaOvrdFlg_C;/* Referenced by: '<S221>/Constant14' */
extern CALDATA const volatile boolean LampCtl_FogLampFStaOvrdVal_C;/* Referenced by: '<S221>/Constant13' */
extern CALDATA const volatile uint16 LampCtl_FogLampFTimInValid_C;/* Referenced by: '<S327>/Constant66' */
extern CALDATA const volatile uint16 LampCtl_FogLampFTimValid_C;/* Referenced by: '<S327>/Constant64' */
extern CALDATA const volatile boolean LampCtl_FogLampFVal_C;/* Referenced by: '<S327>/Constant69' */
extern CALDATA const volatile boolean LampCtl_FogLampRStaOvrdFlg_C;/* Referenced by: '<S221>/Constant12' */
extern CALDATA const volatile boolean LampCtl_FogLampRStaOvrdVal_C;/* Referenced by: '<S221>/Constant11' */
extern CALDATA const volatile uint16 LampCtl_FogLampRTimInValid_C;/* Referenced by: '<S327>/Constant44' */
extern CALDATA const volatile uint16 LampCtl_FogLampRTimValid_C;/* Referenced by: '<S327>/Constant43' */
extern CALDATA const volatile boolean LampCtl_FogLampRVal_C;/* Referenced by: '<S327>/Constant56' */
extern CALDATA const volatile uint16 LampCtl_HazardLightTimInValid_C;/* Referenced by: '<S327>/Constant47' */
extern CALDATA const volatile uint16 LampCtl_HazardLightTimValid_C;/* Referenced by: '<S327>/Constant46' */
extern CALDATA const volatile boolean LampCtl_HazardLightVal_C;/* Referenced by: '<S327>/Constant60' */
extern CALDATA const volatile boolean LampCtl_HiBeamStaOvrdFlg_C;/* Referenced by: '<S221>/Constant20' */
extern CALDATA const volatile boolean LampCtl_HiBeamStaOvrdVal_C;/* Referenced by: '<S221>/Constant17' */
extern CALDATA const volatile uint16 LampCtl_HiBeamTimInValid_C;/* Referenced by: '<S327>/Constant26' */
extern CALDATA const volatile uint16 LampCtl_HiBeamTimValid_C;/* Referenced by: '<S327>/Constant25' */
extern CALDATA const volatile boolean LampCtl_HiBeamVal_C;/* Referenced by: '<S327>/Constant11' */
extern CALDATA const volatile uint16 LampCtl_InportCalSwBit_C;/* Referenced by:
                                                               * '<S327>/Constant1'
                                                               * '<S327>/Constant12'
                                                               * '<S327>/Constant3'
                                                               * '<S327>/Constant4'
                                                               * '<S327>/Constant48'
                                                               * '<S327>/Constant53'
                                                               * '<S327>/Constant55'
                                                               * '<S327>/Constant59'
                                                               * '<S327>/Constant6'
                                                               * '<S327>/Constant61'
                                                               * '<S327>/Constant68'
                                                               * '<S327>/Constant73'
                                                               */
extern CALDATA const volatile boolean LampCtl_J408BackLampPWMOvrdFlg_C;/* Referenced by: '<S221>/Constant30' */
extern CALDATA const volatile uint8 LampCtl_J408BackLampPWMOvrdVal_C;/* Referenced by: '<S221>/Constant29' */
extern CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdFlg_C;/* Referenced by: '<S221>/Constant5' */
extern CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdVal_C;/* Referenced by: '<S221>/Constant6' */
extern CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdFlg_C;/* Referenced by: '<S221>/Constant7' */
extern CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdVal_C;/* Referenced by: '<S221>/Constant8' */
extern CALDATA const volatile boolean LampCtl_J449BoxLampOvrdFlg_C;/* Referenced by: '<S221>/Constant28' */
extern CALDATA const volatile boolean LampCtl_J449BoxLampOvrdVal_C;/* Referenced by: '<S221>/Constant27' */
extern CALDATA const volatile uint16 LampCtl_LampDelayTim_C;/* Referenced by: '<S306>/Constant6' */
extern CALDATA const volatile boolean LampCtl_LowBeamStaOvrdFlg_C;/* Referenced by: '<S221>/Constant9' */
extern CALDATA const volatile boolean LampCtl_LowBeamStaOvrdVal_C;/* Referenced by: '<S221>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_LowBeamStaTimInValid_C;/* Referenced by: '<S308>/Constant5' */
extern CALDATA const volatile uint16 LampCtl_LowBeamStaTimValid_C;/* Referenced by: '<S308>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_LowBeamTimInValid_C;/* Referenced by: '<S327>/Constant24' */
extern CALDATA const volatile uint16 LampCtl_LowBeamTimValid_C;/* Referenced by: '<S327>/Constant23' */
extern CALDATA const volatile boolean LampCtl_LowBeamVal_C;/* Referenced by: '<S327>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_NightVal_C;/* Referenced by: '<S307>/Chart' */
extern CALDATA const volatile uint16 LampCtl_OsUnlckDelayTim_C;/* Referenced by: '<S530>/Constant3' */
extern CALDATA const volatile uint16 LampCtl_PassLightTimInValid_C;/* Referenced by: '<S327>/Constant29' */
extern CALDATA const volatile uint16 LampCtl_PassLightTimValid_C;/* Referenced by: '<S327>/Constant28' */
extern CALDATA const volatile boolean LampCtl_PassLightVal_C;/* Referenced by: '<S327>/Constant2' */
extern CALDATA const volatile boolean LampCtl_PosLampStaOvrdFlg_C;/* Referenced by: '<S221>/Constant18' */
extern CALDATA const volatile boolean LampCtl_PosLampStaOvrdVal_C;/* Referenced by: '<S221>/Constant19' */
extern CALDATA const volatile uint16 LampCtl_PosLampStaTimInValid_C;/* Referenced by: '<S325>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_PosLampStaTimValid_C;/* Referenced by: '<S325>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_PosLampTimInValid_C;/* Referenced by: '<S327>/Constant20' */
extern CALDATA const volatile uint16 LampCtl_PosLampTimValid_C;/* Referenced by: '<S327>/Constant19' */
extern CALDATA const volatile boolean LampCtl_PosLampVal_C;/* Referenced by: '<S327>/Constant50' */
extern CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdFlg_C;/* Referenced by: '<S221>/Constant16' */
extern CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdVal_C;/* Referenced by: '<S221>/Constant15' */
extern CALDATA const volatile uint16 LampCtl_TrunkWarnTim_C;/* Referenced by: '<S430>/Chart' */
extern CALDATA const volatile float32 LampCtl_Ts_C;/* Referenced by:
                                                    * '<S297>/Constant45'
                                                    * '<S297>/Constant7'
                                                    * '<S305>/Constant21'
                                                    * '<S308>/Constant13'
                                                    * '<S325>/Constant13'
                                                    * '<S327>/Constant13'
                                                    * '<S327>/Constant16'
                                                    * '<S327>/Constant21'
                                                    * '<S327>/Constant22'
                                                    * '<S327>/Constant27'
                                                    * '<S327>/Constant30'
                                                    * '<S327>/Constant33'
                                                    * '<S327>/Constant36'
                                                    * '<S327>/Constant39'
                                                    * '<S327>/Constant42'
                                                    * '<S327>/Constant45'
                                                    * '<S327>/Constant49'
                                                    * '<S327>/Constant67'
                                                    * '<S327>/Constant72'
                                                    * '<S428>/Constant21'
                                                    * '<S432>/Constant11'
                                                    * '<S432>/Constant13'
                                                    * '<S432>/Constant3'
                                                    * '<S432>/Constant45'
                                                    */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrFLOpenTimValid_C;/* Referenced by:
                                                                      * '<S432>/Constant14'
                                                                      * '<S432>/Constant43'
                                                                      * '<S432>/Constant9'
                                                                      */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrFROpenTimValid_C;/* Referenced by: '<S432>/Constant1' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdFlg_C;/* Referenced by: '<S221>/Constant25' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdVal_C;/* Referenced by: '<S221>/Constant26' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLTimInValid_C;/* Referenced by: '<S327>/Constant32' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLTimValid_C;/* Referenced by: '<S327>/Constant31' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLVal_C;/* Referenced by: '<S327>/Constant54' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimInValid_C;/* Referenced by: '<S327>/Constant35' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimValid_C;/* Referenced by: '<S327>/Constant34' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimInValid_C;/* Referenced by: '<S327>/Constant41' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimValid_C;/* Referenced by: '<S327>/Constant40' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrOpenCur_C;/* Referenced by:
                                                                 * '<S432>/Constant21'
                                                                 * '<S432>/Constant6'
                                                                 */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRLOpenTimInValid_C;/* Referenced by:
                                                                      * '<S432>/Constant10'
                                                                      * '<S432>/Constant12'
                                                                      * '<S432>/Constant44'
                                                                      */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRROpenTimInValid_C;/* Referenced by: '<S432>/Constant2' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdFlg_C;/* Referenced by: '<S221>/Constant23' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdVal_C;/* Referenced by: '<S221>/Constant24' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRTimInValid_C;/* Referenced by: '<S327>/Constant38' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRTimValid_C;/* Referenced by: '<S327>/Constant37' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRVal_C;/* Referenced by: '<S327>/Constant5' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrShortCur_C;/* Referenced by:
                                                                  * '<S432>/Constant16'
                                                                  * '<S432>/Constant4'
                                                                  */
extern CALDATA const volatile uint16 LampCtl_WelcomeLampTimMax_C;/* Referenced by: '<S529>/Constant6' */
extern CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdFlg_C;/* Referenced by: '<S604>/Constant18' */
extern CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdVal_C;/* Referenced by: '<S604>/Constant19' */
extern CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdFlg_C;/* Referenced by: '<S604>/Constant1' */
extern CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdVal_C;/* Referenced by: '<S604>/Constant2' */
extern CALDATA const volatile boolean PDUCtl_KeyValidOvrdFlg_C;/* Referenced by:
                                                                * '<S788>/Constant12'
                                                                * '<S788>/Constant9'
                                                                */
extern CALDATA const volatile boolean PDUCtl_KeyValidOvrdVal_C;/* Referenced by:
                                                                * '<S788>/Constant10'
                                                                * '<S788>/Constant11'
                                                                */
extern CALDATA const volatile uint16 PDUCtl_OpenDoorPwrOnTimValid;/* Referenced by: '<S788>/Constant6' */
extern CALDATA const volatile uint16 PDUCtl_PwrOnPSTimValid_C;/* Referenced by: '<S788>/Constant3' */
extern CALDATA const volatile uint16 PDUCtl_StartReqOverTimValid_C;/* Referenced by: '<S790>/Constant5' */
extern CALDATA const volatile uint16 PDUCtl_StartReqTimValid_C;/* Referenced by: '<S790>/Constant4' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffH_C;/* Referenced by: '<S787>/Constant4' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffM_C;/* Referenced by: '<S787>/Constant5' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffS_C;/* Referenced by: '<S787>/Constant6' */
extern CALDATA const volatile float32 PDUCtl_Ts_C;/* Referenced by:
                                                   * '<S787>/Constant7'
                                                   * '<S789>/Constant13'
                                                   * '<S789>/Constant6'
                                                   * '<S789>/Constant8'
                                                   */
extern CALDATA const volatile boolean RVMCtl_J42HeatOvrdFlg_C;/* Referenced by: '<S6>/Constant18' */
extern CALDATA const volatile boolean RVMCtl_J42HeatOvrdVal_C;/* Referenced by: '<S6>/Constant19' */
extern CALDATA const volatile uint8 RVMCtl_MaxHeatTimM_C;/* Referenced by: '<S123>/Constant2' */
extern CALDATA const volatile float32 RVMCtl_Ts_C;/* Referenced by: '<S123>/Constant7' */
extern CALDATA const volatile boolean SeatCtl_CN167DrvSeatHtPWMOvrdFlg_C;/* Referenced by: '<S127>/Constant18' */
extern CALDATA const volatile uint8 SeatCtl_CN167DrvSeatHtPWMOvrdVal_C;/* Referenced by: '<S127>/Constant19' */
extern CALDATA const volatile float32 SeatCtl_DrvSeatTempLookUp_X[12];
                                 /* Referenced by: '<S127>/1-D Lookup Table3' */
extern CALDATA const volatile float32 SeatCtl_DrvSeatTempLookUp_Y[12];
                                 /* Referenced by: '<S127>/1-D Lookup Table3' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl0_C;/* Referenced by: '<S127>/Constant8' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl1_C;/* Referenced by: '<S127>/Constant5' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl2_C;/* Referenced by: '<S127>/Constant6' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl3_C;/* Referenced by: '<S127>/Constant7' */
extern CALDATA const volatile uint8 SeatCtl_HtDiffTemp_C;/* Referenced by: '<S127>/Chart' */
extern CALDATA const volatile uint8 SteerWhlCtl_DiffTemp_C;/* Referenced by: '<S130>/HeatCtl' */
extern CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdFlg_C;/* Referenced by: '<S130>/Constant18' */
extern CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdVal_C;/* Referenced by: '<S130>/Constant19' */
extern CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_X[3];
                                 /* Referenced by: '<S130>/1-D Lookup Table1' */
extern CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_Y[3];
                                 /* Referenced by: '<S130>/1-D Lookup Table1' */
extern CALDATA const volatile uint8 SteerWhlCtl_TrgtTemp_C;/* Referenced by: '<S130>/HeatCtl' */
extern CALDATA const volatile uint16 WakeUpCtl_CANSleepDelayTim_C;/* Referenced by: '<S817>/Constant22' */
extern CALDATA const volatile uint16 WakeUpCtl_LocalSleepDelayTim_C;/* Referenced by: '<S818>/Constant27' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMaxResis_C;/* Referenced by: '<S139>/Constant51' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMinResis_C;/* Referenced by: '<S139>/Constant50' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimInValid_C;/* Referenced by: '<S139>/Constant10' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimValid_C;/* Referenced by: '<S139>/Constant9' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMaxResis_C;/* Referenced by: '<S139>/Constant49' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMinResis_C;/* Referenced by: '<S139>/Constant48' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimInValid_C;/* Referenced by: '<S139>/Constant7' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimValid_C;/* Referenced by: '<S139>/Constant6' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinSwResis_C;/* Referenced by: '<S139>/Constant5' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMaxResis_C;/* Referenced by: '<S139>/Constant47' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMinResis_C;/* Referenced by: '<S139>/Constant46' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimInValid_C;/* Referenced by: '<S139>/Constant3' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimValid_C;/* Referenced by: '<S139>/Constant2' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMaxResis_C;/* Referenced by: '<S139>/Constant36' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMinResis_C;/* Referenced by: '<S139>/Constant35' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimInValid_C;/* Referenced by: '<S139>/Constant24' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimValid_C;/* Referenced by: '<S139>/Constant23' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnMaxResis_C;/* Referenced by: '<S139>/Constant31' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnMinResis_C;/* Referenced by: '<S139>/Constant26' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnTimInValid_C;/* Referenced by: '<S139>/Constant18' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnTimValid_C;/* Referenced by: '<S139>/Constant17' */
extern CALDATA const volatile uint16 WinCtl_DrvWinSwResis_C;/* Referenced by: '<S139>/Constant15' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpMaxResis_C;/* Referenced by: '<S139>/Constant22' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpMinResis_C;/* Referenced by: '<S139>/Constant20' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpTimInValid_C;/* Referenced by: '<S139>/Constant13' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpTimValid_C;/* Referenced by: '<S139>/Constant12' */
extern CALDATA const volatile uint16 WinCtl_InportCalSwBit_C;/* Referenced by:
                                                              * '<S139>/Constant1'
                                                              * '<S139>/Constant11'
                                                              * '<S139>/Constant21'
                                                              */
extern CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdFlg_C;/* Referenced by: '<S9>/Constant18' */
extern CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdVal_C;/* Referenced by: '<S9>/Constant19' */
extern CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdFlg_C;/* Referenced by: '<S9>/Constant1' */
extern CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdVal_C;/* Referenced by: '<S9>/Constant2' */
extern CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdFlg_C;/* Referenced by: '<S9>/Constant3' */
extern CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdVal_C;/* Referenced by: '<S9>/Constant4' */
extern CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdFlg_C;/* Referenced by: '<S9>/Constant5' */
extern CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdVal_C;/* Referenced by: '<S9>/Constant6' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMaxResis_C;/* Referenced by: '<S139>/Constant45' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMinResis_C;/* Referenced by: '<S139>/Constant44' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimInValid_C;/* Referenced by: '<S139>/Constant38' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimValid_C;/* Referenced by: '<S139>/Constant37' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnMaxResis_C;/* Referenced by: '<S139>/Constant43' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnMinResis_C;/* Referenced by: '<S139>/Constant42' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnTimInValid_C;/* Referenced by: '<S139>/Constant33' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnTimValid_C;/* Referenced by: '<S139>/Constant32' */
extern CALDATA const volatile uint16 WinCtl_PsgWinSwResis_C;/* Referenced by: '<S139>/Constant30' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpMaxResis_C;/* Referenced by: '<S139>/Constant41' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpMinResis_C;/* Referenced by: '<S139>/Constant40' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpTimInValid_C;/* Referenced by: '<S139>/Constant28' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpTimValid_C;/* Referenced by: '<S139>/Constant27' */
extern CALDATA const volatile uint16 WinCtl_PwrOffWinValidTimMax_C;/* Referenced by: '<S141>/Constant20' */
extern CALDATA const volatile float32 WinCtl_Ts_C;/* Referenced by:
                                                   * '<S139>/Constant14'
                                                   * '<S139>/Constant16'
                                                   * '<S139>/Constant19'
                                                   * '<S139>/Constant25'
                                                   * '<S139>/Constant29'
                                                   * '<S139>/Constant34'
                                                   * '<S139>/Constant39'
                                                   * '<S139>/Constant4'
                                                   * '<S139>/Constant8'
                                                   * '<S141>/Constant10'
                                                   * '<S141>/Constant36'
                                                   */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurMax_C;/* Referenced by:
                                                              * '<S141>/Constant37'
                                                              * '<S141>/Constant48'
                                                              */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurTimInValid_C;/* Referenced by:
                                                                     * '<S141>/Constant35'
                                                                     * '<S141>/Constant44'
                                                                     */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurTimValid_C;/* Referenced by:
                                                                   * '<S141>/Constant11'
                                                                   * '<S141>/Constant34'
                                                                   */
extern CALDATA const volatile uint16 WinCtl_WinProtNum_C;/* Referenced by:
                                                          * '<S140>/Constant15'
                                                          * '<S140>/Constant2'
                                                          * '<S140>/Constant6'
                                                          * '<S140>/Constant9'
                                                          */
extern CALDATA const volatile uint16 WinCtl_WinProtTim_C;/* Referenced by:
                                                          * '<S140>/Constant1'
                                                          * '<S140>/Constant14'
                                                          * '<S140>/Constant5'
                                                          * '<S140>/Constant8'
                                                          */
extern CALDATA const volatile uint16 WinCtl_WinRunTimMax_C;/* Referenced by:
                                                            * '<S141>/Constant40'
                                                            * '<S141>/Constant8'
                                                            */
extern CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdFlg_C;/* Referenced by: '<S222>/Constant3' */
extern CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdVal_C;/* Referenced by: '<S222>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_HiSpdTimInValid_C;/* Referenced by: '<S549>/Constant22' */
extern CALDATA const volatile uint16 WiperCtl_HiSpdTimValid_C;/* Referenced by: '<S549>/Constant21' */
extern CALDATA const volatile uint16 WiperCtl_InportCalSwBit_C;/* Referenced by:
                                                                * '<S549>/Constant28'
                                                                * '<S549>/Constant35'
                                                                * '<S549>/Constant59'
                                                                */
extern CALDATA const volatile uint16 WiperCtl_InrLvl1Tim_C;/* Referenced by: '<S553>/Constant1' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl2Tim_C;/* Referenced by: '<S553>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl3Tim_C;/* Referenced by:
                                                            * '<S553>/Constant3'
                                                            * '<S553>/Constant8'
                                                            */
extern CALDATA const volatile uint16 WiperCtl_InrLvl4Tim_C;/* Referenced by: '<S553>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl5Tim_C;/* Referenced by: '<S553>/Constant5' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl6Tim_C;/* Referenced by: '<S553>/Constant6' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl7Tim_C;/* Referenced by: '<S553>/Constant7' */
extern CALDATA const volatile uint16 WiperCtl_InrTimInValid_C;/* Referenced by: '<S549>/Constant9' */
extern CALDATA const volatile uint16 WiperCtl_InrTimValid_C;/* Referenced by: '<S549>/Constant8' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimDef_C;/* Referenced by: '<S545>/Constant1' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimOk_C;/* Referenced by: '<S545>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkDef_C;/* Referenced by: '<S545>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkOk_C;/* Referenced by: '<S545>/Constant5' */
extern CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdFlg_C;/* Referenced by: '<S222>/Constant1' */
extern CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdVal_C;/* Referenced by: '<S222>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_LowSpdTimInValid_C;/* Referenced by: '<S549>/Constant17' */
extern CALDATA const volatile uint16 WiperCtl_LowSpdTimValid_C;/* Referenced by: '<S549>/Constant16' */
extern CALDATA const volatile uint16 WiperCtl_MaintWiperRunTim_C;/* Referenced by: '<S551>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_MistTimInValid_C;/* Referenced by: '<S549>/Constant47' */
extern CALDATA const volatile uint16 WiperCtl_MistTimValid_C;/* Referenced by: '<S549>/Constant46' */
extern CALDATA const volatile uint16 WiperCtl_OffTimInValid_C;/* Referenced by: '<S549>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_OffTimValid_C;/* Referenced by: '<S549>/Constant3' */
extern CALDATA const volatile float32 WiperCtl_Ts_C;/* Referenced by:
                                                     * '<S549>/Constant10'
                                                     * '<S549>/Constant11'
                                                     * '<S549>/Constant18'
                                                     * '<S549>/Constant27'
                                                     * '<S549>/Constant34'
                                                     * '<S549>/Constant49'
                                                     * '<S549>/Constant5'
                                                     * '<S550>/Constant34'
                                                     */
extern CALDATA const volatile uint8 WiperCtl_WashAfterNum_C;/* Referenced by: '<S551>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_WashAfterTim_C;/* Referenced by: '<S551>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_WashMaxTim_C;/* Referenced by: '<S550>/Constant' */
extern CALDATA const volatile uint16 WiperCtl_WashMinTim_C;/* Referenced by: '<S550>/Constant3' */
extern CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdFlg_C;/* Referenced by: '<S222>/Constant18' */
extern CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdVal_C;/* Referenced by: '<S222>/Constant19' */
extern CALDATA const volatile uint16 WiperCtl_WashTimInValid_C;/* Referenced by: '<S549>/Constant26' */
extern CALDATA const volatile uint16 WiperCtl_WashTimValid_C;/* Referenced by: '<S549>/Constant25' */
extern CALDATA const volatile boolean WiperCtl_WashVal_C;/* Referenced by: '<S549>/Constant29' */

/* 低有效 */
extern CALDATA const volatile uint16 WiperCtl_WiperParkPosTimValid_C;/* Referenced by: '<S549>/Constant32' */
extern CALDATA const volatile boolean WiperCtl_WiperParkPosVal_C;/* Referenced by: '<S549>/Constant36' */

/* 低有效 */
extern CALDATA const volatile uint16 WiperCtl_WiperPosTimInValid_C;/* Referenced by: '<S549>/Constant33' */
extern CALDATA const volatile uint8 WiperCtl_WiperSwVal_C;/* Referenced by: '<S549>/Constant60' */

#endif                                 /* RTW_HEADER_calPrmsBcm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
