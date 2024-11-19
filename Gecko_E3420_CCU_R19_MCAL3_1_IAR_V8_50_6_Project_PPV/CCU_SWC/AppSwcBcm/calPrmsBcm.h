/*
 * File: calPrmsBcm.h
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

#ifndef RTW_HEADER_calPrmsBcm_h_
#define RTW_HEADER_calPrmsBcm_h_
#include "rtwtypes.h"
#include "AppSwcBcm_types.h"

/* Exported data declaration */

/*Group of variables*/
#include "XcpTest_types.h"

/* Declaration for custom storage class: CalParam */
extern CALDATA const volatile uint16 AlmSysCtl_AlrmTimLimit_C;/* Referenced by: '<S637>/AlmSysLogic' */
extern CALDATA const volatile uint16 BatSaveCtl_DlyTim_C;/* Referenced by: '<S665>/Constant2' */
extern CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdFlg_C;/* Referenced by: '<S638>/Constant18' */
extern CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdVal_C;/* Referenced by: '<S638>/Constant19' */
extern CALDATA const volatile uint16 BatSaveCtl_LckDlyTim_C;/* Referenced by: '<S665>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_AntiLckProtTim_C;/* Referenced by: '<S681>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_AutoLckDelayTim_C;/* Referenced by: '<S728>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_CntSubTim_C;/* Referenced by: '<S687>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_CrshPwrOnTimInValid_C;/* Referenced by: '<S710>/Constant4' */
extern CALDATA const volatile uint16 DoorLckCtl_CrshPwrOnTimValid_C;/* Referenced by: '<S710>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimInValid_C;/* Referenced by: '<S678>/Constant2' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimValid_C;/* Referenced by: '<S678>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarFLVal_C;/* Referenced by: '<S678>/Constant4' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimInValid_C;/* Referenced by: '<S678>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimValid_C;/* Referenced by: '<S678>/Constant6' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarFRVal_C;/* Referenced by: '<S678>/Constant9' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimInvalid_C;/* Referenced by: '<S678>/Constant35' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimValid_C;/* Referenced by: '<S678>/Constant34' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarRLVal_C;/* Referenced by: '<S678>/Constant18' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimInvalid_C;/* Referenced by: '<S678>/Constant38' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimValid_C;/* Referenced by: '<S678>/Constant37' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarRRVal_C;/* Referenced by: '<S678>/Constant20' */
extern CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimInValid_C;/* Referenced by: '<S678>/Constant47' */
extern CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimValid_C;/* Referenced by: '<S678>/Constant46' */
extern CALDATA const volatile boolean DoorLckCtl_DriverDoorLckVal_C;/* Referenced by: '<S678>/Constant60' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvPETimInvalid_C;/* Referenced by: '<S678>/Constant26' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvPETimValid_C;/* Referenced by: '<S678>/Constant25' */
extern CALDATA const volatile boolean DoorLckCtl_DrvPEVal_C;/* Referenced by: '<S678>/Constant12' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisMin_C;/* Referenced by: '<S678>/Constant67' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisVal_C;/* Referenced by: '<S678>/Constant63' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimInValid_C;/* Referenced by: '<S678>/Constant65' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimValid_C;/* Referenced by: '<S678>/Constant64' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvTim_C;/* Referenced by: '<S640>/DoorDrv' */
extern CALDATA const volatile uint8 DoorLckCtl_EEIlluminatedEntrySys_C;/* Referenced by: '<S678>/Constant74' */
extern CALDATA const volatile uint8 DoorLckCtl_EEKeyEntry_C;/* Referenced by: '<S678>/Constant72' */
extern CALDATA const volatile uint8 DoorLckCtl_IllmndSts_C;/* Referenced by: '<S678>/Constant76' */
extern CALDATA const volatile uint16 DoorLckCtl_InportCalSwBit_C;/* Referenced by:
                                                                  * '<S678>/Constant10'
                                                                  * '<S678>/Constant11'
                                                                  * '<S678>/Constant13'
                                                                  * '<S678>/Constant15'
                                                                  * '<S678>/Constant17'
                                                                  * '<S678>/Constant19'
                                                                  * '<S678>/Constant21'
                                                                  * '<S678>/Constant5'
                                                                  * '<S678>/Constant59'
                                                                  * '<S678>/Constant62'
                                                                  * '<S678>/Constant71'
                                                                  * '<S678>/Constant73'
                                                                  * '<S678>/Constant75'
                                                                  */
extern CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdFlg_C;/* Referenced by: '<S640>/Constant3' */
extern CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdVal_C;/* Referenced by: '<S640>/Constant4' */
extern CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdFlg_C;/* Referenced by: '<S640>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdVal_C;/* Referenced by: '<S640>/Constant2' */
extern CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdFlg_C;/* Referenced by: '<S640>/Constant18' */
extern CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdVal_C;/* Referenced by: '<S640>/Constant19' */
extern CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMaxTim_C;/* Referenced by: '<S640>/DoorDrv' */
extern CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMinTim_C;/* Referenced by: '<S640>/DoorDrv' */
extern CALDATA const volatile uint16 DoorLckCtl_MotorProtTimMax_C;/* Referenced by: '<S687>/Constant2' */
extern CALDATA const volatile uint8 DoorLckCtl_MotorWorkMax_C;/* Referenced by: '<S687>/Constant1' */
extern CALDATA const volatile uint16 DoorLckCtl_PEProtCnt_C;/* Referenced by: '<S690>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_PEProtIntvlTim_C;/* Referenced by: '<S690>/Constant2' */
extern CALDATA const volatile uint16 DoorLckCtl_PsgPETimInvalid_C;/* Referenced by:
                                                                   * '<S678>/Constant29'
                                                                   * '<S678>/Constant32'
                                                                   */
extern CALDATA const volatile uint16 DoorLckCtl_PsgPETimValid_C;/* Referenced by:
                                                                 * '<S678>/Constant28'
                                                                 * '<S678>/Constant31'
                                                                 */
extern CALDATA const volatile boolean DoorLckCtl_PsgPEVal_C;/* Referenced by: '<S678>/Constant14' */
extern CALDATA const volatile uint16 DoorLckCtl_SpdLckTimInValid_C;/* Referenced by:
                                                                    * '<S698>/Constant10'
                                                                    * '<S698>/Constant3'
                                                                    */
extern CALDATA const volatile uint16 DoorLckCtl_SpdLckTimValid_C;/* Referenced by:
                                                                  * '<S698>/Constant2'
                                                                  * '<S698>/Constant9'
                                                                  */
extern CALDATA const volatile uint8 DoorLckCtl_SpdLck_C;/* Referenced by: '<S698>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimInvalid_C;/* Referenced by: '<S678>/Constant41' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimValid_C;/* Referenced by: '<S678>/Constant40' */
extern CALDATA const volatile boolean DoorLckCtl_TrunkAjarVal_C;/* Referenced by: '<S678>/Constant22' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAutoLckTim_C;/* Referenced by: '<S733>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_TrunkSwVal_C;/* Referenced by: '<S678>/Constant16' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimInvalid_C;/* Referenced by: '<S759>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimValid_C;/* Referenced by: '<S759>/Constant2' */
extern CALDATA const volatile float32 DoorLckCtl_Ts_C;/* Referenced by:
                                                       * '<S678>/Constant27'
                                                       * '<S678>/Constant3'
                                                       * '<S678>/Constant30'
                                                       * '<S678>/Constant33'
                                                       * '<S678>/Constant36'
                                                       * '<S678>/Constant39'
                                                       * '<S678>/Constant42'
                                                       * '<S678>/Constant49'
                                                       * '<S678>/Constant66'
                                                       * '<S678>/Constant8'
                                                       * '<S698>/Constant11'
                                                       * '<S698>/Constant49'
                                                       * '<S710>/Constant6'
                                                       * '<S729>/Constant42'
                                                       * '<S755>/Constant42'
                                                       * '<S759>/Constant4'
                                                       */
extern CALDATA const volatile boolean EEWriteCtl_ImmOvrdFlg_C;/* Referenced by: '<S5>/EEWriteCtl' */
extern CALDATA const volatile uint8 EEWriteCtl_ImmOvrdVal_C[128];/* Referenced by: '<S5>/EEWriteCtl' */
extern CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdFlg_C;/* Referenced by: '<S848>/Constant18' */
extern CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdVal_C;/* Referenced by: '<S848>/Constant19' */
extern CALDATA const volatile uint16 ESCLCtl_LckDelay_C;/* Referenced by: '<S848>/ESCLLck' */
extern CALDATA const volatile uint16 ESCLCtl_LckTimMax_C;/* Referenced by: '<S848>/ESCLLck' */
extern CALDATA const volatile uint16 ESCLCtl_UnlckDelay_C;/* Referenced by: '<S848>/ESCLUnlck' */
extern CALDATA const volatile uint16 ESCLCtl_UnlckTimMax_C;/* Referenced by: '<S848>/ESCLUnlck' */
extern CALDATA const volatile uint16 HornCtl_HornSwTimInvalid_C;/* Referenced by: '<S287>/Constant38' */
extern CALDATA const volatile uint16 HornCtl_HornSwTimValid_C;/* Referenced by: '<S287>/Constant37' */
extern CALDATA const volatile boolean HornCtl_J430HornDrvOvrdFlg_C;/* Referenced by: '<S240>/Constant18' */
extern CALDATA const volatile boolean HornCtl_J430HornDrvOvrdVal_C;/* Referenced by: '<S240>/Constant19' */
extern CALDATA const volatile uint16 HornCtl_TrunkWarnTim_C;/* Referenced by: '<S292>/Chart' */
extern CALDATA const volatile float32 HornCtl_Ts_C;/* Referenced by: '<S287>/Constant39' */
extern CALDATA const volatile uint16 LampCtl_AutoLampDayDelayTim_C;/* Referenced by: '<S320>/Constant6' */
extern CALDATA const volatile uint16 LampCtl_AutoLampNightDelayTim_C;/* Referenced by: '<S320>/Constant43' */
extern CALDATA const volatile uint16 LampCtl_AutoLampTimInValid_C;/* Referenced by: '<S351>/Constant63' */
extern CALDATA const volatile uint16 LampCtl_AutoLampTimValid_C;/* Referenced by: '<S351>/Constant9' */
extern CALDATA const volatile boolean LampCtl_AutoLampVal_C;/* Referenced by: '<S351>/Constant8' */
extern CALDATA const volatile uint16 LampCtl_BoxLampOpenTimMax_C;/* Referenced by: '<S322>/Constant4' */
extern CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdFlg_C;/* Referenced by: '<S241>/Constant3' */
extern CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdVal_C;/* Referenced by: '<S241>/Constant4' */
extern CALDATA const volatile boolean LampCtl_BrakeLightVal_C;/* Referenced by:
                                                               * '<S351>/Constant62'
                                                               * '<S351>/Constant74'
                                                               */
extern CALDATA const volatile uint16 LampCtl_BrakeSwInValid_C;/* Referenced by:
                                                               * '<S351>/Constant15'
                                                               * '<S351>/Constant71'
                                                               */
extern CALDATA const volatile uint16 LampCtl_BrakeSwTimValid_C;/* Referenced by:
                                                                * '<S351>/Constant14'
                                                                * '<S351>/Constant70'
                                                                */
extern CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdFlg_C;/* Referenced by: '<S241>/Constant1' */
extern CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdVal_C;/* Referenced by: '<S241>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_DayTimeVal_C;/* Referenced by: '<S330>/Chart' */
extern CALDATA const volatile boolean LampCtl_DomeLampPwmDutyOvrdFlg_C;/* Referenced by: '<S241>/Constant22' */
extern CALDATA const volatile uint8 LampCtl_DomeLampPwmDutyOvrdVal_C;/* Referenced by: '<S241>/Constant21' */
extern CALDATA const volatile uint16 LampCtl_DoorOpenFLInValidTim_C;/* Referenced by: '<S374>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_DoorOpenFLValidTim_C;/* Referenced by: '<S374>/Constant3' */
extern CALDATA const volatile uint16 LampCtl_DoorOpenFRInValidTim_C;/* Referenced by: '<S374>/Constant7' */
extern CALDATA const volatile uint16 LampCtl_DoorOpenFRValidTim_C;/* Referenced by: '<S374>/Constant6' */
extern CALDATA const volatile uint16 LampCtl_FlwrMeHomeTimValid_C;/* Referenced by: '<S567>/Constant43' */
extern CALDATA const volatile boolean LampCtl_FogLampFStaOvrdFlg_C;/* Referenced by: '<S241>/Constant14' */
extern CALDATA const volatile boolean LampCtl_FogLampFStaOvrdVal_C;/* Referenced by: '<S241>/Constant13' */
extern CALDATA const volatile uint16 LampCtl_FogLampFTimInValid_C;/* Referenced by: '<S351>/Constant66' */
extern CALDATA const volatile uint16 LampCtl_FogLampFTimValid_C;/* Referenced by: '<S351>/Constant64' */
extern CALDATA const volatile boolean LampCtl_FogLampFVal_C;/* Referenced by: '<S351>/Constant69' */
extern CALDATA const volatile boolean LampCtl_FogLampRStaOvrdFlg_C;/* Referenced by: '<S241>/Constant12' */
extern CALDATA const volatile boolean LampCtl_FogLampRStaOvrdVal_C;/* Referenced by: '<S241>/Constant11' */
extern CALDATA const volatile uint16 LampCtl_FogLampRTimInValid_C;/* Referenced by: '<S351>/Constant44' */
extern CALDATA const volatile uint16 LampCtl_FogLampRTimValid_C;/* Referenced by: '<S351>/Constant43' */
extern CALDATA const volatile boolean LampCtl_FogLampRVal_C;/* Referenced by: '<S351>/Constant56' */
extern CALDATA const volatile uint16 LampCtl_HazardLightTimInValid_C;/* Referenced by: '<S351>/Constant47' */
extern CALDATA const volatile uint16 LampCtl_HazardLightTimValid_C;/* Referenced by: '<S351>/Constant46' */
extern CALDATA const volatile boolean LampCtl_HazardLightVal_C;/* Referenced by: '<S351>/Constant60' */
extern CALDATA const volatile uint16 LampCtl_HiBeamShortToBatTimInValid_C;/* Referenced by: '<S327>/Constant29' */
extern CALDATA const volatile boolean LampCtl_HiBeamStaOvrdFlg_C;/* Referenced by: '<S241>/Constant20' */
extern CALDATA const volatile boolean LampCtl_HiBeamStaOvrdVal_C;/* Referenced by: '<S241>/Constant17' */
extern CALDATA const volatile uint16 LampCtl_HiBeamTimInValid_C;/* Referenced by: '<S351>/Constant26' */
extern CALDATA const volatile uint16 LampCtl_HiBeamTimValid_C;/* Referenced by: '<S351>/Constant25' */
extern CALDATA const volatile boolean LampCtl_HiBeamVal_C;/* Referenced by: '<S351>/Constant11' */
extern CALDATA const volatile uint16 LampCtl_InportCalSwBit_C;/* Referenced by:
                                                               * '<S351>/Constant1'
                                                               * '<S351>/Constant12'
                                                               * '<S351>/Constant3'
                                                               * '<S351>/Constant4'
                                                               * '<S351>/Constant48'
                                                               * '<S351>/Constant53'
                                                               * '<S351>/Constant55'
                                                               * '<S351>/Constant59'
                                                               * '<S351>/Constant6'
                                                               * '<S351>/Constant61'
                                                               * '<S351>/Constant68'
                                                               * '<S351>/Constant73'
                                                               */
extern CALDATA const volatile boolean LampCtl_J408BackLampPWMOvrdFlg_C;/* Referenced by: '<S241>/Constant30' */
extern CALDATA const volatile uint8 LampCtl_J408BackLampPWMOvrdVal_C;/* Referenced by: '<S241>/Constant29' */
extern CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdFlg_C;/* Referenced by: '<S241>/Constant5' */
extern CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdVal_C;/* Referenced by: '<S241>/Constant6' */
extern CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdFlg_C;/* Referenced by: '<S241>/Constant7' */
extern CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdVal_C;/* Referenced by: '<S241>/Constant8' */
extern CALDATA const volatile boolean LampCtl_J449BoxLampOvrdFlg_C;/* Referenced by: '<S241>/Constant28' */
extern CALDATA const volatile boolean LampCtl_J449BoxLampOvrdVal_C;/* Referenced by: '<S241>/Constant27' */
extern CALDATA const volatile uint8 LampCtl_LOpenCnt_C;/* Referenced by: '<S463>/Constant17' */
extern CALDATA const volatile uint8 LampCtl_LShortCnt_C;/* Referenced by: '<S463>/Constant19' */
extern CALDATA const volatile uint16 LampCtl_LampDelayTim_C;/* Referenced by: '<S329>/Constant6' */
extern CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimInValid_C;/* Referenced by: '<S331>/Constant29' */
extern CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimValid_C;/* Referenced by: '<S331>/Constant28' */
extern CALDATA const volatile boolean LampCtl_LowBeamStaOvrdFlg_C;/* Referenced by: '<S241>/Constant9' */
extern CALDATA const volatile boolean LampCtl_LowBeamStaOvrdVal_C;/* Referenced by: '<S241>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_LowBeamStaTimInValid_C;/* Referenced by: '<S331>/Constant5' */
extern CALDATA const volatile uint16 LampCtl_LowBeamStaTimValid_C;/* Referenced by: '<S331>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_LowBeamTimInValid_C;/* Referenced by: '<S351>/Constant24' */
extern CALDATA const volatile uint16 LampCtl_LowBeamTimValid_C;/* Referenced by: '<S351>/Constant23' */
extern CALDATA const volatile boolean LampCtl_LowBeamVal_C;/* Referenced by: '<S351>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_NightVal_C;/* Referenced by: '<S330>/Chart' */
extern CALDATA const volatile uint16 LampCtl_OsUnlckDelayTim_C;/* Referenced by: '<S572>/Constant3' */
extern CALDATA const volatile uint16 LampCtl_PassLightTimInValid_C;/* Referenced by: '<S351>/Constant29' */
extern CALDATA const volatile uint16 LampCtl_PassLightTimValid_C;/* Referenced by: '<S351>/Constant28' */
extern CALDATA const volatile boolean LampCtl_PassLightVal_C;/* Referenced by: '<S351>/Constant2' */
extern CALDATA const volatile boolean LampCtl_PosLampStaOvrdFlg_C;/* Referenced by: '<S241>/Constant18' */
extern CALDATA const volatile boolean LampCtl_PosLampStaOvrdVal_C;/* Referenced by: '<S241>/Constant19' */
extern CALDATA const volatile uint16 LampCtl_PosLampStaTimInValid_C;/* Referenced by: '<S349>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_PosLampStaTimValid_C;/* Referenced by: '<S349>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_PosLampTimInValid_C;/* Referenced by: '<S351>/Constant20' */
extern CALDATA const volatile uint16 LampCtl_PosLampTimValid_C;/* Referenced by: '<S351>/Constant19' */
extern CALDATA const volatile boolean LampCtl_PosLampVal_C;/* Referenced by: '<S351>/Constant50' */
extern CALDATA const volatile uint8 LampCtl_ROpenCnt_C;/* Referenced by: '<S463>/Constant8' */
extern CALDATA const volatile uint8 LampCtl_RShortCnt_C;/* Referenced by: '<S463>/Constant16' */
extern CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdFlg_C;/* Referenced by: '<S241>/Constant16' */
extern CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdVal_C;/* Referenced by: '<S241>/Constant15' */
extern CALDATA const volatile uint16 LampCtl_TrunkWarnTim_C;/* Referenced by: '<S461>/Chart' */
extern CALDATA const volatile float32 LampCtl_Ts_C;/* Referenced by:
                                                    * '<S320>/Constant45'
                                                    * '<S320>/Constant7'
                                                    * '<S327>/Constant30'
                                                    * '<S328>/Constant21'
                                                    * '<S331>/Constant13'
                                                    * '<S331>/Constant30'
                                                    * '<S349>/Constant13'
                                                    * '<S351>/Constant13'
                                                    * '<S351>/Constant16'
                                                    * '<S351>/Constant21'
                                                    * '<S351>/Constant22'
                                                    * '<S351>/Constant27'
                                                    * '<S351>/Constant30'
                                                    * '<S351>/Constant33'
                                                    * '<S351>/Constant36'
                                                    * '<S351>/Constant39'
                                                    * '<S351>/Constant42'
                                                    * '<S351>/Constant45'
                                                    * '<S351>/Constant49'
                                                    * '<S351>/Constant67'
                                                    * '<S351>/Constant72'
                                                    * '<S374>/Constant5'
                                                    * '<S374>/Constant8'
                                                    * '<S459>/Constant21'
                                                    * '<S463>/Constant13'
                                                    * '<S463>/Constant18'
                                                    * '<S463>/Constant45'
                                                    * '<S463>/Constant6'
                                                    */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimInValid_C;/* Referenced by: '<S463>/Constant44' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimValid_C;/* Referenced by: '<S463>/Constant43' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimInValid_C;/* Referenced by: '<S463>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimValid_C;/* Referenced by: '<S463>/Constant9' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdFlg_C;/* Referenced by: '<S241>/Constant25' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdVal_C;/* Referenced by: '<S241>/Constant26' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLTimInValid_C;/* Referenced by: '<S351>/Constant32' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLTimValid_C;/* Referenced by: '<S351>/Constant31' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLVal_C;/* Referenced by: '<S351>/Constant54' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimInValid_C;/* Referenced by: '<S351>/Constant35' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimValid_C;/* Referenced by: '<S351>/Constant34' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimInValid_C;/* Referenced by: '<S351>/Constant41' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimValid_C;/* Referenced by: '<S351>/Constant40' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrOpenCur_C;/* Referenced by:
                                                                 * '<S463>/Constant11'
                                                                 * '<S463>/Constant21'
                                                                 */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimInValid_C;/* Referenced by: '<S463>/Constant3' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimValid_C;/* Referenced by: '<S463>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimInValid_C;/* Referenced by: '<S463>/Constant12' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimValid_C;/* Referenced by: '<S463>/Constant14' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdFlg_C;/* Referenced by: '<S241>/Constant23' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdVal_C;/* Referenced by: '<S241>/Constant24' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRTimInValid_C;/* Referenced by: '<S351>/Constant38' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRTimValid_C;/* Referenced by: '<S351>/Constant37' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRVal_C;/* Referenced by: '<S351>/Constant5' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrShortCur_C;/* Referenced by:
                                                                  * '<S463>/Constant20'
                                                                  * '<S463>/Constant4'
                                                                  */
extern CALDATA const volatile uint16 LampCtl_WelcomeLampTimMax_C;/* Referenced by: '<S571>/Constant6' */
extern CALDATA const volatile uint16 PDUCtl_EmerPwrOffTimInValid_C;/* Referenced by: '<S867>/Constant20' */
extern CALDATA const volatile uint16 PDUCtl_EmerPwrOffTimValid_C;/* Referenced by: '<S867>/Constant19' */
extern CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdFlg_C;/* Referenced by: '<S644>/Constant18' */
extern CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdVal_C;/* Referenced by: '<S644>/Constant19' */
extern CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdFlg_C;/* Referenced by: '<S644>/Constant1' */
extern CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdVal_C;/* Referenced by: '<S644>/Constant2' */
extern CALDATA const volatile boolean PDUCtl_KeyValidOvrdFlg_C;/* Referenced by:
                                                                * '<S868>/Constant12'
                                                                * '<S868>/Constant9'
                                                                */
extern CALDATA const volatile boolean PDUCtl_KeyValidOvrdVal_C;/* Referenced by:
                                                                * '<S868>/Constant10'
                                                                * '<S868>/Constant11'
                                                                */
extern CALDATA const volatile uint16 PDUCtl_OpenDoorPwrOnTimValid;/* Referenced by: '<S868>/Constant6' */
extern CALDATA const volatile uint16 PDUCtl_PwrOnPSTimValid_C;/* Referenced by: '<S868>/Constant3' */
extern CALDATA const volatile uint16 PDUCtl_RemtPasvBrkSwTimValid_C;/* Referenced by: '<S867>/Constant33' */
extern CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffH_C;/* Referenced by: '<S867>/Constant25' */
extern CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffM_C;/* Referenced by: '<S867>/Constant26' */
extern CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffS_C;/* Referenced by: '<S867>/Constant27' */
extern CALDATA const volatile uint16 PDUCtl_StartReqOverTimValid_C;/* Referenced by: '<S871>/Constant5' */
extern CALDATA const volatile uint16 PDUCtl_StartReqTimValid_C;/* Referenced by: '<S871>/Constant4' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffH_C;/* Referenced by: '<S867>/Constant4' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffM_C;/* Referenced by: '<S867>/Constant5' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffS_C;/* Referenced by: '<S867>/Constant6' */
extern CALDATA const volatile float32 PDUCtl_Ts_C;/* Referenced by:
                                                   * '<S867>/Constant21'
                                                   * '<S867>/Constant28'
                                                   * '<S867>/Constant7'
                                                   * '<S869>/Constant13'
                                                   * '<S869>/Constant6'
                                                   * '<S869>/Constant8'
                                                   */
extern CALDATA const volatile boolean RVMCtl_J42HeatOvrdFlg_C;/* Referenced by: '<S7>/Constant18' */
extern CALDATA const volatile boolean RVMCtl_J42HeatOvrdVal_C;/* Referenced by: '<S7>/Constant19' */
extern CALDATA const volatile uint8 RVMCtl_MaxHeatTimM_C;/* Referenced by: '<S125>/Constant2' */
extern CALDATA const volatile float32 RVMCtl_Ts_C;/* Referenced by: '<S125>/Constant7' */
extern CALDATA const volatile boolean SeatCtl_CN167DrvSeatHtPWMOvrdFlg_C;/* Referenced by: '<S129>/Constant18' */
extern CALDATA const volatile uint8 SeatCtl_CN167DrvSeatHtPWMOvrdVal_C;/* Referenced by: '<S129>/Constant19' */
extern CALDATA const volatile float32 SeatCtl_DrvSeatTempLookUp_X[24];
                                 /* Referenced by: '<S129>/1-D Lookup Table2' */
extern CALDATA const volatile float32 SeatCtl_DrvSeatTempLookUp_Y[24];
                                 /* Referenced by: '<S129>/1-D Lookup Table2' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl0_C;/* Referenced by: '<S129>/Constant8' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl1_C;/* Referenced by: '<S129>/Constant5' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl2_C;/* Referenced by: '<S129>/Constant6' */
extern CALDATA const volatile uint8 SeatCtl_DrvTempLvl3_C;/* Referenced by: '<S129>/Constant7' */
extern CALDATA const volatile uint8 SeatCtl_HtDiffTemp_C;/* Referenced by: '<S129>/Chart' */
extern CALDATA const volatile uint16 SeatCtl_NTCOpenInValidTim_C;/* Referenced by: '<S129>/Constant16' */
extern CALDATA const volatile float32 SeatCtl_NTCOpenResis_C;/* Referenced by: '<S129>/Constant11' */
extern CALDATA const volatile uint16 SeatCtl_NTCOpenValidTim_C;/* Referenced by: '<S129>/Constant15' */
extern CALDATA const volatile uint16 SeatCtl_NTCShortInValidTim_C;/* Referenced by: '<S129>/Constant13' */
extern CALDATA const volatile float32 SeatCtl_NTCShortResis_C;/* Referenced by: '<S129>/Constant' */
extern CALDATA const volatile uint16 SeatCtl_NTCShortValidTim_C;/* Referenced by: '<S129>/Constant12' */
extern CALDATA const volatile float32 SeatCtl_Ts_C;/* Referenced by:
                                                    * '<S129>/Constant14'
                                                    * '<S129>/Constant17'
                                                    */
extern CALDATA const volatile uint8 SteerWhlCtl_DiffTemp_C;/* Referenced by: '<S137>/HeatCtl' */
extern CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdFlg_C;/* Referenced by: '<S137>/Constant18' */
extern CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdVal_C;/* Referenced by: '<S137>/Constant19' */
extern CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_X[18];
                                 /* Referenced by: '<S137>/1-D Lookup Table1' */
extern CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_Y[18];
                                 /* Referenced by: '<S137>/1-D Lookup Table1' */
extern CALDATA const volatile uint8 SteerWhlCtl_TrgtTemp_C;/* Referenced by: '<S137>/HeatCtl' */
extern CALDATA const volatile uint16 WakeUpCtl_CANSleepDelayTim_C;/* Referenced by: '<S910>/Constant22' */
extern CALDATA const volatile uint16 WakeUpCtl_LocalSleepDelayTim_C;/* Referenced by: '<S911>/Constant27' */
extern CALDATA const volatile uint16 WakeUpCtl_WinCtlDelayTim_C;/* Referenced by: '<S910>/Constant3' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMaxResis_C;/* Referenced by: '<S150>/Constant51' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMinResis_C;/* Referenced by: '<S150>/Constant50' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimInValid_C;/* Referenced by: '<S150>/Constant10' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimValid_C;/* Referenced by: '<S150>/Constant9' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMaxResis_C;/* Referenced by: '<S150>/Constant49' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMinResis_C;/* Referenced by: '<S150>/Constant48' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimInValid_C;/* Referenced by: '<S150>/Constant7' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimValid_C;/* Referenced by: '<S150>/Constant6' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinSwResis_C;/* Referenced by: '<S150>/Constant5' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMaxResis_C;/* Referenced by: '<S150>/Constant47' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMinResis_C;/* Referenced by: '<S150>/Constant46' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimInValid_C;/* Referenced by: '<S150>/Constant3' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimValid_C;/* Referenced by: '<S150>/Constant2' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMaxResis_C;/* Referenced by: '<S150>/Constant36' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMinResis_C;/* Referenced by: '<S150>/Constant35' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimInValid_C;/* Referenced by: '<S150>/Constant24' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimValid_C;/* Referenced by: '<S150>/Constant23' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnMaxResis_C;/* Referenced by: '<S150>/Constant31' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnMinResis_C;/* Referenced by: '<S150>/Constant26' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnTimInValid_C;/* Referenced by: '<S150>/Constant18' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnTimValid_C;/* Referenced by: '<S150>/Constant17' */
extern CALDATA const volatile uint16 WinCtl_DrvWinSwResis_C;/* Referenced by: '<S150>/Constant15' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpMaxResis_C;/* Referenced by: '<S150>/Constant22' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpMinResis_C;/* Referenced by: '<S150>/Constant20' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpTimInValid_C;/* Referenced by: '<S150>/Constant13' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpTimValid_C;/* Referenced by: '<S150>/Constant12' */
extern CALDATA const volatile uint16 WinCtl_InportCalSwBit_C;/* Referenced by:
                                                              * '<S150>/Constant1'
                                                              * '<S150>/Constant11'
                                                              * '<S150>/Constant21'
                                                              */
extern CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdFlg_C;/* Referenced by: '<S10>/Constant18' */
extern CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdVal_C;/* Referenced by: '<S10>/Constant19' */
extern CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdFlg_C;/* Referenced by: '<S10>/Constant1' */
extern CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdVal_C;/* Referenced by: '<S10>/Constant2' */
extern CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdFlg_C;/* Referenced by: '<S10>/Constant3' */
extern CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdVal_C;/* Referenced by: '<S10>/Constant4' */
extern CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdFlg_C;/* Referenced by: '<S10>/Constant5' */
extern CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdVal_C;/* Referenced by: '<S10>/Constant6' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMaxResis_C;/* Referenced by: '<S150>/Constant45' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMinResis_C;/* Referenced by: '<S150>/Constant44' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimInValid_C;/* Referenced by: '<S150>/Constant38' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimValid_C;/* Referenced by: '<S150>/Constant37' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnMaxResis_C;/* Referenced by: '<S150>/Constant43' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnMinResis_C;/* Referenced by: '<S150>/Constant42' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnTimInValid_C;/* Referenced by: '<S150>/Constant33' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnTimValid_C;/* Referenced by: '<S150>/Constant32' */
extern CALDATA const volatile uint16 WinCtl_PsgWinSwResis_C;/* Referenced by: '<S150>/Constant30' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpMaxResis_C;/* Referenced by: '<S150>/Constant41' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpMinResis_C;/* Referenced by: '<S150>/Constant40' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpTimInValid_C;/* Referenced by: '<S150>/Constant28' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpTimValid_C;/* Referenced by: '<S150>/Constant27' */
extern CALDATA const volatile uint16 WinCtl_PwrOffWinValidTimMax_C;/* Referenced by: '<S152>/Constant20' */
extern CALDATA const volatile float32 WinCtl_Ts_C;/* Referenced by:
                                                   * '<S150>/Constant14'
                                                   * '<S150>/Constant16'
                                                   * '<S150>/Constant19'
                                                   * '<S150>/Constant25'
                                                   * '<S150>/Constant29'
                                                   * '<S150>/Constant34'
                                                   * '<S150>/Constant39'
                                                   * '<S150>/Constant4'
                                                   * '<S150>/Constant8'
                                                   * '<S152>/Constant10'
                                                   * '<S152>/Constant36'
                                                   */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurMax_C;/* Referenced by:
                                                              * '<S152>/Constant37'
                                                              * '<S152>/Constant48'
                                                              */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurTimInValid_C;/* Referenced by:
                                                                     * '<S152>/Constant35'
                                                                     * '<S152>/Constant44'
                                                                     */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurTimValid_C;/* Referenced by:
                                                                   * '<S152>/Constant11'
                                                                   * '<S152>/Constant34'
                                                                   */
extern CALDATA const volatile uint16 WinCtl_WinProtNum_C;/* Referenced by:
                                                          * '<S151>/Constant15'
                                                          * '<S151>/Constant2'
                                                          * '<S151>/Constant6'
                                                          * '<S151>/Constant9'
                                                          */
extern CALDATA const volatile uint16 WinCtl_WinProtTim_C;/* Referenced by:
                                                          * '<S151>/Constant1'
                                                          * '<S151>/Constant14'
                                                          * '<S151>/Constant5'
                                                          * '<S151>/Constant8'
                                                          */
extern CALDATA const volatile uint16 WinCtl_WinRunTimMax_C;/* Referenced by:
                                                            * '<S152>/Constant40'
                                                            * '<S152>/Constant8'
                                                            */
extern CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdFlg_C;/* Referenced by: '<S242>/Constant3' */
extern CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdVal_C;/* Referenced by: '<S242>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_HiSpdTimInValid_C;/* Referenced by: '<S588>/Constant22' */
extern CALDATA const volatile uint16 WiperCtl_HiSpdTimValid_C;/* Referenced by: '<S588>/Constant21' */
extern CALDATA const volatile uint16 WiperCtl_InportCalSwBit_C;/* Referenced by:
                                                                * '<S588>/Constant28'
                                                                * '<S588>/Constant35'
                                                                * '<S588>/Constant59'
                                                                */
extern CALDATA const volatile uint16 WiperCtl_InrLvl1Tim_C;/* Referenced by: '<S592>/Constant1' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl2Tim_C;/* Referenced by: '<S592>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl3Tim_C;/* Referenced by:
                                                            * '<S592>/Constant3'
                                                            * '<S592>/Constant8'
                                                            */
extern CALDATA const volatile uint16 WiperCtl_InrLvl4Tim_C;/* Referenced by: '<S592>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl5Tim_C;/* Referenced by: '<S592>/Constant5' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl6Tim_C;/* Referenced by: '<S592>/Constant6' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl7Tim_C;/* Referenced by: '<S592>/Constant7' */
extern CALDATA const volatile uint16 WiperCtl_InrTimInValid_C;/* Referenced by: '<S588>/Constant9' */
extern CALDATA const volatile uint16 WiperCtl_InrTimValid_C;/* Referenced by: '<S588>/Constant8' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimDef_C;/* Referenced by: '<S584>/Constant1' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimOk_C;/* Referenced by: '<S584>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkDef_C;/* Referenced by: '<S584>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkOk_C;/* Referenced by: '<S584>/Constant5' */
extern CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdFlg_C;/* Referenced by: '<S242>/Constant1' */
extern CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdVal_C;/* Referenced by: '<S242>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_LowSpdTimInValid_C;/* Referenced by: '<S588>/Constant17' */
extern CALDATA const volatile uint16 WiperCtl_LowSpdTimValid_C;/* Referenced by: '<S588>/Constant16' */
extern CALDATA const volatile uint16 WiperCtl_MaintWiperRunTim_C;/* Referenced by: '<S590>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_MistTimInValid_C;/* Referenced by: '<S588>/Constant47' */
extern CALDATA const volatile uint16 WiperCtl_MistTimValid_C;/* Referenced by: '<S588>/Constant46' */
extern CALDATA const volatile uint16 WiperCtl_OffTimInValid_C;/* Referenced by: '<S588>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_OffTimValid_C;/* Referenced by: '<S588>/Constant3' */
extern CALDATA const volatile float32 WiperCtl_Ts_C;/* Referenced by:
                                                     * '<S588>/Constant10'
                                                     * '<S588>/Constant11'
                                                     * '<S588>/Constant18'
                                                     * '<S588>/Constant27'
                                                     * '<S588>/Constant34'
                                                     * '<S588>/Constant49'
                                                     * '<S588>/Constant5'
                                                     * '<S589>/Constant34'
                                                     */
extern CALDATA const volatile uint8 WiperCtl_WashAfterNum_C;/* Referenced by: '<S590>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_WashAfterTim_C;/* Referenced by: '<S590>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_WashMaxTim_C;/* Referenced by: '<S589>/Constant' */
extern CALDATA const volatile uint16 WiperCtl_WashMinTim_C;/* Referenced by: '<S589>/Constant3' */
extern CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdFlg_C;/* Referenced by: '<S242>/Constant18' */
extern CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdVal_C;/* Referenced by: '<S242>/Constant19' */
extern CALDATA const volatile uint16 WiperCtl_WashTimInValid_C;/* Referenced by: '<S588>/Constant26' */
extern CALDATA const volatile uint16 WiperCtl_WashTimValid_C;/* Referenced by: '<S588>/Constant25' */
extern CALDATA const volatile boolean WiperCtl_WashVal_C;/* Referenced by: '<S588>/Constant29' */

/* 低有效 */
extern CALDATA const volatile uint16 WiperCtl_WiperParkPosTimValid_C;/* Referenced by: '<S588>/Constant32' */
extern CALDATA const volatile boolean WiperCtl_WiperParkPosVal_C;/* Referenced by: '<S588>/Constant36' */

/* 低有效 */
extern CALDATA const volatile uint16 WiperCtl_WiperPosTimInValid_C;/* Referenced by: '<S588>/Constant33' */
extern CALDATA const volatile uint8 WiperCtl_WiperSwVal_C;/* Referenced by: '<S588>/Constant60' */

#endif                                 /* RTW_HEADER_calPrmsBcm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
