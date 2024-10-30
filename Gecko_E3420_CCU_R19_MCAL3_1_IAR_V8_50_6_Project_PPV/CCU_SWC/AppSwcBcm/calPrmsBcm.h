/*
 * File: calPrmsBcm.h
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

#ifndef RTW_HEADER_calPrmsBcm_h_
#define RTW_HEADER_calPrmsBcm_h_
#include "rtwtypes.h"
#include "AppSwcBcm_types.h"

/* Exported data declaration */

/*Group of variables*/
#include "XcpTest_types.h"

/* Declaration for custom storage class: CalParam */
extern CALDATA const volatile uint16 AlmSysCtl_AlrmTimLimit_C;/* Referenced by: '<S619>/AlmSysLogic' */
extern CALDATA const volatile uint16 BatSaveCtl_DlyTim_C;/* Referenced by: '<S647>/Constant2' */
extern CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdFlg_C;/* Referenced by: '<S620>/Constant18' */
extern CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdVal_C;/* Referenced by: '<S620>/Constant19' */
extern CALDATA const volatile uint16 BatSaveCtl_LckDlyTim_C;/* Referenced by: '<S647>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_AntiLckProtTim_C;/* Referenced by: '<S663>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_AutoLckDelayTim_C;/* Referenced by: '<S709>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_CntSubTim_C;/* Referenced by: '<S669>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_CrshPwrOnTimInValid_C;/* Referenced by: '<S691>/Constant4' */
extern CALDATA const volatile uint16 DoorLckCtl_CrshPwrOnTimValid_C;/* Referenced by: '<S691>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimInValid_C;/* Referenced by: '<S660>/Constant2' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimValid_C;/* Referenced by: '<S660>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarFLVal_C;/* Referenced by: '<S660>/Constant4' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimInValid_C;/* Referenced by: '<S660>/Constant7' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimValid_C;/* Referenced by: '<S660>/Constant6' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarFRVal_C;/* Referenced by: '<S660>/Constant9' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimInvalid_C;/* Referenced by: '<S660>/Constant35' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimValid_C;/* Referenced by: '<S660>/Constant34' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarRLVal_C;/* Referenced by: '<S660>/Constant18' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimInvalid_C;/* Referenced by: '<S660>/Constant38' */
extern CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimValid_C;/* Referenced by: '<S660>/Constant37' */
extern CALDATA const volatile boolean DoorLckCtl_DoorAjarRRVal_C;/* Referenced by: '<S660>/Constant20' */
extern CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimInValid_C;/* Referenced by: '<S660>/Constant47' */
extern CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimValid_C;/* Referenced by: '<S660>/Constant46' */
extern CALDATA const volatile boolean DoorLckCtl_DriverDoorLckVal_C;/* Referenced by: '<S660>/Constant60' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvPETimInvalid_C;/* Referenced by: '<S660>/Constant26' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvPETimValid_C;/* Referenced by: '<S660>/Constant25' */
extern CALDATA const volatile boolean DoorLckCtl_DrvPEVal_C;/* Referenced by: '<S660>/Constant12' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisMin_C;/* Referenced by: '<S660>/Constant67' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisVal_C;/* Referenced by: '<S660>/Constant63' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimInValid_C;/* Referenced by: '<S660>/Constant65' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimValid_C;/* Referenced by: '<S660>/Constant64' */
extern CALDATA const volatile uint16 DoorLckCtl_DrvTim_C;/* Referenced by: '<S622>/DoorDrv' */
extern CALDATA const volatile uint8 DoorLckCtl_EEIlluminatedEntrySys_C;/* Referenced by: '<S660>/Constant74' */
extern CALDATA const volatile uint8 DoorLckCtl_EEKeyEntry_C;/* Referenced by: '<S660>/Constant72' */
extern CALDATA const volatile uint8 DoorLckCtl_IllmndSts_C;/* Referenced by: '<S660>/Constant76' */
extern CALDATA const volatile uint16 DoorLckCtl_InportCalSwBit_C;/* Referenced by:
                                                                  * '<S660>/Constant10'
                                                                  * '<S660>/Constant11'
                                                                  * '<S660>/Constant13'
                                                                  * '<S660>/Constant15'
                                                                  * '<S660>/Constant17'
                                                                  * '<S660>/Constant19'
                                                                  * '<S660>/Constant21'
                                                                  * '<S660>/Constant5'
                                                                  * '<S660>/Constant59'
                                                                  * '<S660>/Constant62'
                                                                  * '<S660>/Constant71'
                                                                  * '<S660>/Constant73'
                                                                  * '<S660>/Constant75'
                                                                  */
extern CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdFlg_C;/* Referenced by: '<S622>/Constant3' */
extern CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdVal_C;/* Referenced by: '<S622>/Constant4' */
extern CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdFlg_C;/* Referenced by: '<S622>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdVal_C;/* Referenced by: '<S622>/Constant2' */
extern CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdFlg_C;/* Referenced by: '<S622>/Constant18' */
extern CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdVal_C;/* Referenced by: '<S622>/Constant19' */
extern CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMaxTim_C;/* Referenced by: '<S622>/DoorDrv' */
extern CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMinTim_C;/* Referenced by: '<S622>/DoorDrv' */
extern CALDATA const volatile uint16 DoorLckCtl_MotorProtTimMax_C;/* Referenced by: '<S669>/Constant2' */
extern CALDATA const volatile uint8 DoorLckCtl_MotorWorkMax_C;/* Referenced by: '<S669>/Constant1' */
extern CALDATA const volatile uint16 DoorLckCtl_PEProtCnt_C;/* Referenced by: '<S672>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_PEProtIntvlTim_C;/* Referenced by: '<S672>/Constant2' */
extern CALDATA const volatile uint16 DoorLckCtl_PsgPETimInvalid_C;/* Referenced by:
                                                                   * '<S660>/Constant29'
                                                                   * '<S660>/Constant32'
                                                                   */
extern CALDATA const volatile uint16 DoorLckCtl_PsgPETimValid_C;/* Referenced by:
                                                                 * '<S660>/Constant28'
                                                                 * '<S660>/Constant31'
                                                                 */
extern CALDATA const volatile boolean DoorLckCtl_PsgPEVal_C;/* Referenced by: '<S660>/Constant14' */
extern CALDATA const volatile uint16 DoorLckCtl_SpdLckTimInValid_C;/* Referenced by:
                                                                    * '<S679>/Constant10'
                                                                    * '<S679>/Constant3'
                                                                    */
extern CALDATA const volatile uint16 DoorLckCtl_SpdLckTimValid_C;/* Referenced by:
                                                                  * '<S679>/Constant2'
                                                                  * '<S679>/Constant9'
                                                                  */
extern CALDATA const volatile uint8 DoorLckCtl_SpdLck_C;/* Referenced by: '<S679>/Constant' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimInvalid_C;/* Referenced by: '<S660>/Constant41' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimValid_C;/* Referenced by: '<S660>/Constant40' */
extern CALDATA const volatile boolean DoorLckCtl_TrunkAjarVal_C;/* Referenced by: '<S660>/Constant22' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkAutoLckTim_C;/* Referenced by: '<S713>/Constant1' */
extern CALDATA const volatile boolean DoorLckCtl_TrunkSwVal_C;/* Referenced by: '<S660>/Constant16' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimInvalid_C;/* Referenced by: '<S737>/Constant3' */
extern CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimValid_C;/* Referenced by: '<S737>/Constant2' */
extern CALDATA const volatile float32 DoorLckCtl_Ts_C;/* Referenced by:
                                                       * '<S660>/Constant27'
                                                       * '<S660>/Constant3'
                                                       * '<S660>/Constant30'
                                                       * '<S660>/Constant33'
                                                       * '<S660>/Constant36'
                                                       * '<S660>/Constant39'
                                                       * '<S660>/Constant42'
                                                       * '<S660>/Constant49'
                                                       * '<S660>/Constant66'
                                                       * '<S660>/Constant8'
                                                       * '<S679>/Constant11'
                                                       * '<S679>/Constant49'
                                                       * '<S691>/Constant6'
                                                       * '<S710>/Constant42'
                                                       * '<S734>/Constant42'
                                                       * '<S737>/Constant4'
                                                       */
extern CALDATA const volatile boolean EEWriteCtl_ImmOvrdFlg_C;/* Referenced by: '<S5>/EEWriteCtl' */
extern CALDATA const volatile uint8 EEWriteCtl_ImmOvrdVal_C[128];/* Referenced by: '<S5>/EEWriteCtl' */
extern CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdFlg_C;/* Referenced by: '<S821>/Constant18' */
extern CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdVal_C;/* Referenced by: '<S821>/Constant19' */
extern CALDATA const volatile uint16 ESCLCtl_LckDelay_C;/* Referenced by: '<S821>/ESCLLck' */
extern CALDATA const volatile uint16 ESCLCtl_LckTimMax_C;/* Referenced by: '<S821>/ESCLLck' */
extern CALDATA const volatile uint16 ESCLCtl_UnlckDelay_C;/* Referenced by: '<S821>/ESCLUnlck' */
extern CALDATA const volatile uint16 ESCLCtl_UnlckTimMax_C;/* Referenced by: '<S821>/ESCLUnlck' */
extern CALDATA const volatile uint16 HornCtl_HornSwTimInvalid_C;/* Referenced by: '<S279>/Constant38' */
extern CALDATA const volatile uint16 HornCtl_HornSwTimValid_C;/* Referenced by: '<S279>/Constant37' */
extern CALDATA const volatile boolean HornCtl_J430HornDrvOvrdFlg_C;/* Referenced by: '<S232>/Constant18' */
extern CALDATA const volatile boolean HornCtl_J430HornDrvOvrdVal_C;/* Referenced by: '<S232>/Constant19' */
extern CALDATA const volatile uint16 HornCtl_TrunkWarnTim_C;/* Referenced by: '<S284>/Chart' */
extern CALDATA const volatile float32 HornCtl_Ts_C;/* Referenced by: '<S279>/Constant39' */
extern CALDATA const volatile uint16 LampCtl_AutoLampDayDelayTim_C;/* Referenced by: '<S310>/Constant6' */
extern CALDATA const volatile uint16 LampCtl_AutoLampNightDelayTim_C;/* Referenced by: '<S310>/Constant43' */
extern CALDATA const volatile uint16 LampCtl_AutoLampTimInValid_C;/* Referenced by: '<S340>/Constant63' */
extern CALDATA const volatile uint16 LampCtl_AutoLampTimValid_C;/* Referenced by: '<S340>/Constant9' */
extern CALDATA const volatile boolean LampCtl_AutoLampVal_C;/* Referenced by: '<S340>/Constant8' */
extern CALDATA const volatile uint16 LampCtl_BoxLampOpenTimMax_C;/* Referenced by: '<S312>/Constant4' */
extern CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdFlg_C;/* Referenced by: '<S233>/Constant3' */
extern CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdVal_C;/* Referenced by: '<S233>/Constant4' */
extern CALDATA const volatile boolean LampCtl_BrakeLightVal_C;/* Referenced by:
                                                               * '<S340>/Constant62'
                                                               * '<S340>/Constant74'
                                                               */
extern CALDATA const volatile uint16 LampCtl_BrakeSwInValid_C;/* Referenced by:
                                                               * '<S340>/Constant15'
                                                               * '<S340>/Constant71'
                                                               */
extern CALDATA const volatile uint16 LampCtl_BrakeSwTimValid_C;/* Referenced by:
                                                                * '<S340>/Constant14'
                                                                * '<S340>/Constant70'
                                                                */
extern CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdFlg_C;/* Referenced by: '<S233>/Constant1' */
extern CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdVal_C;/* Referenced by: '<S233>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_DayTimeVal_C;/* Referenced by: '<S320>/Chart' */
extern CALDATA const volatile boolean LampCtl_DomeLampPwmDutyOvrdFlg_C;/* Referenced by: '<S233>/Constant22' */
extern CALDATA const volatile uint8 LampCtl_DomeLampPwmDutyOvrdVal_C;/* Referenced by: '<S233>/Constant21' */
extern CALDATA const volatile uint16 LampCtl_FlwrMeHomeTimValid_C;/* Referenced by: '<S549>/Constant43' */
extern CALDATA const volatile boolean LampCtl_FogLampFStaOvrdFlg_C;/* Referenced by: '<S233>/Constant14' */
extern CALDATA const volatile boolean LampCtl_FogLampFStaOvrdVal_C;/* Referenced by: '<S233>/Constant13' */
extern CALDATA const volatile uint16 LampCtl_FogLampFTimInValid_C;/* Referenced by: '<S340>/Constant66' */
extern CALDATA const volatile uint16 LampCtl_FogLampFTimValid_C;/* Referenced by: '<S340>/Constant64' */
extern CALDATA const volatile boolean LampCtl_FogLampFVal_C;/* Referenced by: '<S340>/Constant69' */
extern CALDATA const volatile boolean LampCtl_FogLampRStaOvrdFlg_C;/* Referenced by: '<S233>/Constant12' */
extern CALDATA const volatile boolean LampCtl_FogLampRStaOvrdVal_C;/* Referenced by: '<S233>/Constant11' */
extern CALDATA const volatile uint16 LampCtl_FogLampRTimInValid_C;/* Referenced by: '<S340>/Constant44' */
extern CALDATA const volatile uint16 LampCtl_FogLampRTimValid_C;/* Referenced by: '<S340>/Constant43' */
extern CALDATA const volatile boolean LampCtl_FogLampRVal_C;/* Referenced by: '<S340>/Constant56' */
extern CALDATA const volatile uint16 LampCtl_HazardLightTimInValid_C;/* Referenced by: '<S340>/Constant47' */
extern CALDATA const volatile uint16 LampCtl_HazardLightTimValid_C;/* Referenced by: '<S340>/Constant46' */
extern CALDATA const volatile boolean LampCtl_HazardLightVal_C;/* Referenced by: '<S340>/Constant60' */
extern CALDATA const volatile uint16 LampCtl_HiBeamShortToBatTimInValid_C;/* Referenced by: '<S317>/Constant29' */
extern CALDATA const volatile boolean LampCtl_HiBeamStaOvrdFlg_C;/* Referenced by: '<S233>/Constant20' */
extern CALDATA const volatile boolean LampCtl_HiBeamStaOvrdVal_C;/* Referenced by: '<S233>/Constant17' */
extern CALDATA const volatile uint16 LampCtl_HiBeamTimInValid_C;/* Referenced by: '<S340>/Constant26' */
extern CALDATA const volatile uint16 LampCtl_HiBeamTimValid_C;/* Referenced by: '<S340>/Constant25' */
extern CALDATA const volatile boolean LampCtl_HiBeamVal_C;/* Referenced by: '<S340>/Constant11' */
extern CALDATA const volatile uint16 LampCtl_InportCalSwBit_C;/* Referenced by:
                                                               * '<S340>/Constant1'
                                                               * '<S340>/Constant12'
                                                               * '<S340>/Constant3'
                                                               * '<S340>/Constant4'
                                                               * '<S340>/Constant48'
                                                               * '<S340>/Constant53'
                                                               * '<S340>/Constant55'
                                                               * '<S340>/Constant59'
                                                               * '<S340>/Constant6'
                                                               * '<S340>/Constant61'
                                                               * '<S340>/Constant68'
                                                               * '<S340>/Constant73'
                                                               */
extern CALDATA const volatile boolean LampCtl_J408BackLampPWMOvrdFlg_C;/* Referenced by: '<S233>/Constant30' */
extern CALDATA const volatile uint8 LampCtl_J408BackLampPWMOvrdVal_C;/* Referenced by: '<S233>/Constant29' */
extern CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdFlg_C;/* Referenced by: '<S233>/Constant5' */
extern CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdVal_C;/* Referenced by: '<S233>/Constant6' */
extern CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdFlg_C;/* Referenced by: '<S233>/Constant7' */
extern CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdVal_C;/* Referenced by: '<S233>/Constant8' */
extern CALDATA const volatile boolean LampCtl_J449BoxLampOvrdFlg_C;/* Referenced by: '<S233>/Constant28' */
extern CALDATA const volatile boolean LampCtl_J449BoxLampOvrdVal_C;/* Referenced by: '<S233>/Constant27' */
extern CALDATA const volatile uint8 LampCtl_LOpenCnt_C;/* Referenced by: '<S450>/Constant17' */
extern CALDATA const volatile uint8 LampCtl_LShortCnt_C;/* Referenced by: '<S450>/Constant19' */
extern CALDATA const volatile uint16 LampCtl_LampDelayTim_C;/* Referenced by: '<S319>/Constant6' */
extern CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimInValid_C;/* Referenced by: '<S321>/Constant29' */
extern CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimValid_C;/* Referenced by: '<S321>/Constant28' */
extern CALDATA const volatile boolean LampCtl_LowBeamStaOvrdFlg_C;/* Referenced by: '<S233>/Constant9' */
extern CALDATA const volatile boolean LampCtl_LowBeamStaOvrdVal_C;/* Referenced by: '<S233>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_LowBeamStaTimInValid_C;/* Referenced by: '<S321>/Constant5' */
extern CALDATA const volatile uint16 LampCtl_LowBeamStaTimValid_C;/* Referenced by: '<S321>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_LowBeamTimInValid_C;/* Referenced by: '<S340>/Constant24' */
extern CALDATA const volatile uint16 LampCtl_LowBeamTimValid_C;/* Referenced by: '<S340>/Constant23' */
extern CALDATA const volatile boolean LampCtl_LowBeamVal_C;/* Referenced by: '<S340>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_NightVal_C;/* Referenced by: '<S320>/Chart' */
extern CALDATA const volatile uint16 LampCtl_OsUnlckDelayTim_C;/* Referenced by: '<S554>/Constant3' */
extern CALDATA const volatile uint16 LampCtl_PassLightTimInValid_C;/* Referenced by: '<S340>/Constant29' */
extern CALDATA const volatile uint16 LampCtl_PassLightTimValid_C;/* Referenced by: '<S340>/Constant28' */
extern CALDATA const volatile boolean LampCtl_PassLightVal_C;/* Referenced by: '<S340>/Constant2' */
extern CALDATA const volatile boolean LampCtl_PosLampStaOvrdFlg_C;/* Referenced by: '<S233>/Constant18' */
extern CALDATA const volatile boolean LampCtl_PosLampStaOvrdVal_C;/* Referenced by: '<S233>/Constant19' */
extern CALDATA const volatile uint16 LampCtl_PosLampStaTimInValid_C;/* Referenced by: '<S338>/Constant4' */
extern CALDATA const volatile uint16 LampCtl_PosLampStaTimValid_C;/* Referenced by: '<S338>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_PosLampTimInValid_C;/* Referenced by: '<S340>/Constant20' */
extern CALDATA const volatile uint16 LampCtl_PosLampTimValid_C;/* Referenced by: '<S340>/Constant19' */
extern CALDATA const volatile boolean LampCtl_PosLampVal_C;/* Referenced by: '<S340>/Constant50' */
extern CALDATA const volatile uint8 LampCtl_ROpenCnt_C;/* Referenced by: '<S450>/Constant8' */
extern CALDATA const volatile uint8 LampCtl_RShortCnt_C;/* Referenced by: '<S450>/Constant16' */
extern CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdFlg_C;/* Referenced by: '<S233>/Constant16' */
extern CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdVal_C;/* Referenced by: '<S233>/Constant15' */
extern CALDATA const volatile uint16 LampCtl_TrunkWarnTim_C;/* Referenced by: '<S448>/Chart' */
extern CALDATA const volatile float32 LampCtl_Ts_C;/* Referenced by:
                                                    * '<S310>/Constant45'
                                                    * '<S310>/Constant7'
                                                    * '<S317>/Constant30'
                                                    * '<S318>/Constant21'
                                                    * '<S321>/Constant13'
                                                    * '<S321>/Constant30'
                                                    * '<S338>/Constant13'
                                                    * '<S340>/Constant13'
                                                    * '<S340>/Constant16'
                                                    * '<S340>/Constant21'
                                                    * '<S340>/Constant22'
                                                    * '<S340>/Constant27'
                                                    * '<S340>/Constant30'
                                                    * '<S340>/Constant33'
                                                    * '<S340>/Constant36'
                                                    * '<S340>/Constant39'
                                                    * '<S340>/Constant42'
                                                    * '<S340>/Constant45'
                                                    * '<S340>/Constant49'
                                                    * '<S340>/Constant67'
                                                    * '<S340>/Constant72'
                                                    * '<S446>/Constant21'
                                                    * '<S450>/Constant13'
                                                    * '<S450>/Constant18'
                                                    * '<S450>/Constant45'
                                                    * '<S450>/Constant6'
                                                    */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimInValid_C;/* Referenced by: '<S450>/Constant44' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimValid_C;/* Referenced by: '<S450>/Constant43' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimInValid_C;/* Referenced by: '<S450>/Constant10' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimValid_C;/* Referenced by: '<S450>/Constant9' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdFlg_C;/* Referenced by: '<S233>/Constant25' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdVal_C;/* Referenced by: '<S233>/Constant26' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLTimInValid_C;/* Referenced by: '<S340>/Constant32' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLTimValid_C;/* Referenced by: '<S340>/Constant31' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrLVal_C;/* Referenced by: '<S340>/Constant54' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimInValid_C;/* Referenced by: '<S340>/Constant35' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimValid_C;/* Referenced by: '<S340>/Constant34' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimInValid_C;/* Referenced by: '<S340>/Constant41' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimValid_C;/* Referenced by: '<S340>/Constant40' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrOpenCur_C;/* Referenced by:
                                                                 * '<S450>/Constant11'
                                                                 * '<S450>/Constant21'
                                                                 */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimInValid_C;/* Referenced by: '<S450>/Constant3' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimValid_C;/* Referenced by: '<S450>/Constant2' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimInValid_C;/* Referenced by: '<S450>/Constant12' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimValid_C;/* Referenced by: '<S450>/Constant14' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdFlg_C;/* Referenced by: '<S233>/Constant23' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdVal_C;/* Referenced by: '<S233>/Constant24' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRTimInValid_C;/* Referenced by: '<S340>/Constant38' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrRTimValid_C;/* Referenced by: '<S340>/Constant37' */
extern CALDATA const volatile boolean LampCtl_TurnIndcrRVal_C;/* Referenced by: '<S340>/Constant5' */
extern CALDATA const volatile uint16 LampCtl_TurnIndcrShortCur_C;/* Referenced by:
                                                                  * '<S450>/Constant20'
                                                                  * '<S450>/Constant4'
                                                                  */
extern CALDATA const volatile uint16 LampCtl_WelcomeLampTimMax_C;/* Referenced by: '<S553>/Constant6' */
extern CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdFlg_C;/* Referenced by: '<S626>/Constant18' */
extern CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdVal_C;/* Referenced by: '<S626>/Constant19' */
extern CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdFlg_C;/* Referenced by: '<S626>/Constant1' */
extern CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdVal_C;/* Referenced by: '<S626>/Constant2' */
extern CALDATA const volatile boolean PDUCtl_KeyValidOvrdFlg_C;/* Referenced by:
                                                                * '<S841>/Constant12'
                                                                * '<S841>/Constant9'
                                                                */
extern CALDATA const volatile boolean PDUCtl_KeyValidOvrdVal_C;/* Referenced by:
                                                                * '<S841>/Constant10'
                                                                * '<S841>/Constant11'
                                                                */
extern CALDATA const volatile uint16 PDUCtl_OpenDoorPwrOnTimValid;/* Referenced by: '<S841>/Constant6' */
extern CALDATA const volatile uint16 PDUCtl_PwrOnPSTimValid_C;/* Referenced by: '<S841>/Constant3' */
extern CALDATA const volatile uint16 PDUCtl_StartReqOverTimValid_C;/* Referenced by: '<S843>/Constant5' */
extern CALDATA const volatile uint16 PDUCtl_StartReqTimValid_C;/* Referenced by: '<S843>/Constant4' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffH_C;/* Referenced by: '<S840>/Constant4' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffM_C;/* Referenced by: '<S840>/Constant5' */
extern CALDATA const volatile uint8 PDUCtl_TimOutPwrOffS_C;/* Referenced by: '<S840>/Constant6' */
extern CALDATA const volatile float32 PDUCtl_Ts_C;/* Referenced by:
                                                   * '<S840>/Constant7'
                                                   * '<S842>/Constant13'
                                                   * '<S842>/Constant6'
                                                   * '<S842>/Constant8'
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
extern CALDATA const volatile uint8 SteerWhlCtl_DiffTemp_C;/* Referenced by: '<S132>/HeatCtl' */
extern CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdFlg_C;/* Referenced by: '<S132>/Constant18' */
extern CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdVal_C;/* Referenced by: '<S132>/Constant19' */
extern CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_X[3];
                                 /* Referenced by: '<S132>/1-D Lookup Table1' */
extern CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_Y[3];
                                 /* Referenced by: '<S132>/1-D Lookup Table1' */
extern CALDATA const volatile uint8 SteerWhlCtl_TrgtTemp_C;/* Referenced by: '<S132>/HeatCtl' */
extern CALDATA const volatile uint16 WakeUpCtl_CANSleepDelayTim_C;/* Referenced by: '<S872>/Constant22' */
extern CALDATA const volatile uint16 WakeUpCtl_LocalSleepDelayTim_C;/* Referenced by: '<S873>/Constant27' */
extern CALDATA const volatile uint16 WakeUpCtl_WinCtlDelayTim_C;/* Referenced by: '<S872>/Constant3' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMaxResis_C;/* Referenced by: '<S141>/Constant51' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMinResis_C;/* Referenced by: '<S141>/Constant50' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimInValid_C;/* Referenced by: '<S141>/Constant10' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimValid_C;/* Referenced by: '<S141>/Constant9' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMaxResis_C;/* Referenced by: '<S141>/Constant49' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMinResis_C;/* Referenced by: '<S141>/Constant48' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimInValid_C;/* Referenced by: '<S141>/Constant7' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimValid_C;/* Referenced by: '<S141>/Constant6' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinSwResis_C;/* Referenced by: '<S141>/Constant5' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMaxResis_C;/* Referenced by: '<S141>/Constant47' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMinResis_C;/* Referenced by: '<S141>/Constant46' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimInValid_C;/* Referenced by: '<S141>/Constant3' */
extern CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimValid_C;/* Referenced by: '<S141>/Constant2' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMaxResis_C;/* Referenced by: '<S141>/Constant36' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMinResis_C;/* Referenced by: '<S141>/Constant35' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimInValid_C;/* Referenced by: '<S141>/Constant24' */
extern CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimValid_C;/* Referenced by: '<S141>/Constant23' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnMaxResis_C;/* Referenced by: '<S141>/Constant31' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnMinResis_C;/* Referenced by: '<S141>/Constant26' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnTimInValid_C;/* Referenced by: '<S141>/Constant18' */
extern CALDATA const volatile uint16 WinCtl_DrvWinDnTimValid_C;/* Referenced by: '<S141>/Constant17' */
extern CALDATA const volatile uint16 WinCtl_DrvWinSwResis_C;/* Referenced by: '<S141>/Constant15' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpMaxResis_C;/* Referenced by: '<S141>/Constant22' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpMinResis_C;/* Referenced by: '<S141>/Constant20' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpTimInValid_C;/* Referenced by: '<S141>/Constant13' */
extern CALDATA const volatile uint16 WinCtl_DrvWinUpTimValid_C;/* Referenced by: '<S141>/Constant12' */
extern CALDATA const volatile uint16 WinCtl_InportCalSwBit_C;/* Referenced by:
                                                              * '<S141>/Constant1'
                                                              * '<S141>/Constant11'
                                                              * '<S141>/Constant21'
                                                              */
extern CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdFlg_C;/* Referenced by: '<S10>/Constant18' */
extern CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdVal_C;/* Referenced by: '<S10>/Constant19' */
extern CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdFlg_C;/* Referenced by: '<S10>/Constant1' */
extern CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdVal_C;/* Referenced by: '<S10>/Constant2' */
extern CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdFlg_C;/* Referenced by: '<S10>/Constant3' */
extern CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdVal_C;/* Referenced by: '<S10>/Constant4' */
extern CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdFlg_C;/* Referenced by: '<S10>/Constant5' */
extern CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdVal_C;/* Referenced by: '<S10>/Constant6' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMaxResis_C;/* Referenced by: '<S141>/Constant45' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMinResis_C;/* Referenced by: '<S141>/Constant44' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimInValid_C;/* Referenced by: '<S141>/Constant38' */
extern CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimValid_C;/* Referenced by: '<S141>/Constant37' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnMaxResis_C;/* Referenced by: '<S141>/Constant43' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnMinResis_C;/* Referenced by: '<S141>/Constant42' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnTimInValid_C;/* Referenced by: '<S141>/Constant33' */
extern CALDATA const volatile uint16 WinCtl_PsgWinDnTimValid_C;/* Referenced by: '<S141>/Constant32' */
extern CALDATA const volatile uint16 WinCtl_PsgWinSwResis_C;/* Referenced by: '<S141>/Constant30' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpMaxResis_C;/* Referenced by: '<S141>/Constant41' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpMinResis_C;/* Referenced by: '<S141>/Constant40' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpTimInValid_C;/* Referenced by: '<S141>/Constant28' */
extern CALDATA const volatile uint16 WinCtl_PsgWinUpTimValid_C;/* Referenced by: '<S141>/Constant27' */
extern CALDATA const volatile uint16 WinCtl_PwrOffWinValidTimMax_C;/* Referenced by: '<S143>/Constant20' */
extern CALDATA const volatile float32 WinCtl_Ts_C;/* Referenced by:
                                                   * '<S141>/Constant14'
                                                   * '<S141>/Constant16'
                                                   * '<S141>/Constant19'
                                                   * '<S141>/Constant25'
                                                   * '<S141>/Constant29'
                                                   * '<S141>/Constant34'
                                                   * '<S141>/Constant39'
                                                   * '<S141>/Constant4'
                                                   * '<S141>/Constant8'
                                                   * '<S143>/Constant10'
                                                   * '<S143>/Constant36'
                                                   */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurMax_C;/* Referenced by:
                                                              * '<S143>/Constant37'
                                                              * '<S143>/Constant48'
                                                              */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurTimInValid_C;/* Referenced by:
                                                                     * '<S143>/Constant35'
                                                                     * '<S143>/Constant44'
                                                                     */
extern CALDATA const volatile uint16 WinCtl_WinMotorCurTimValid_C;/* Referenced by:
                                                                   * '<S143>/Constant11'
                                                                   * '<S143>/Constant34'
                                                                   */
extern CALDATA const volatile uint16 WinCtl_WinProtNum_C;/* Referenced by:
                                                          * '<S142>/Constant15'
                                                          * '<S142>/Constant2'
                                                          * '<S142>/Constant6'
                                                          * '<S142>/Constant9'
                                                          */
extern CALDATA const volatile uint16 WinCtl_WinProtTim_C;/* Referenced by:
                                                          * '<S142>/Constant1'
                                                          * '<S142>/Constant14'
                                                          * '<S142>/Constant5'
                                                          * '<S142>/Constant8'
                                                          */
extern CALDATA const volatile uint16 WinCtl_WinRunTimMax_C;/* Referenced by:
                                                            * '<S143>/Constant40'
                                                            * '<S143>/Constant8'
                                                            */
extern CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdFlg_C;/* Referenced by: '<S234>/Constant3' */
extern CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdVal_C;/* Referenced by: '<S234>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_HiSpdTimInValid_C;/* Referenced by: '<S570>/Constant22' */
extern CALDATA const volatile uint16 WiperCtl_HiSpdTimValid_C;/* Referenced by: '<S570>/Constant21' */
extern CALDATA const volatile uint16 WiperCtl_InportCalSwBit_C;/* Referenced by:
                                                                * '<S570>/Constant28'
                                                                * '<S570>/Constant35'
                                                                * '<S570>/Constant59'
                                                                */
extern CALDATA const volatile uint16 WiperCtl_InrLvl1Tim_C;/* Referenced by: '<S574>/Constant1' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl2Tim_C;/* Referenced by: '<S574>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl3Tim_C;/* Referenced by:
                                                            * '<S574>/Constant3'
                                                            * '<S574>/Constant8'
                                                            */
extern CALDATA const volatile uint16 WiperCtl_InrLvl4Tim_C;/* Referenced by: '<S574>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl5Tim_C;/* Referenced by: '<S574>/Constant5' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl6Tim_C;/* Referenced by: '<S574>/Constant6' */
extern CALDATA const volatile uint16 WiperCtl_InrLvl7Tim_C;/* Referenced by: '<S574>/Constant7' */
extern CALDATA const volatile uint16 WiperCtl_InrTimInValid_C;/* Referenced by: '<S570>/Constant9' */
extern CALDATA const volatile uint16 WiperCtl_InrTimValid_C;/* Referenced by: '<S570>/Constant8' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimDef_C;/* Referenced by: '<S566>/Constant1' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimOk_C;/* Referenced by: '<S566>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkDef_C;/* Referenced by: '<S566>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkOk_C;/* Referenced by: '<S566>/Constant5' */
extern CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdFlg_C;/* Referenced by: '<S234>/Constant1' */
extern CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdVal_C;/* Referenced by: '<S234>/Constant2' */
extern CALDATA const volatile uint16 WiperCtl_LowSpdTimInValid_C;/* Referenced by: '<S570>/Constant17' */
extern CALDATA const volatile uint16 WiperCtl_LowSpdTimValid_C;/* Referenced by: '<S570>/Constant16' */
extern CALDATA const volatile uint16 WiperCtl_MaintWiperRunTim_C;/* Referenced by: '<S572>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_MistTimInValid_C;/* Referenced by: '<S570>/Constant47' */
extern CALDATA const volatile uint16 WiperCtl_MistTimValid_C;/* Referenced by: '<S570>/Constant46' */
extern CALDATA const volatile uint16 WiperCtl_OffTimInValid_C;/* Referenced by: '<S570>/Constant4' */
extern CALDATA const volatile uint16 WiperCtl_OffTimValid_C;/* Referenced by: '<S570>/Constant3' */
extern CALDATA const volatile float32 WiperCtl_Ts_C;/* Referenced by:
                                                     * '<S570>/Constant10'
                                                     * '<S570>/Constant11'
                                                     * '<S570>/Constant18'
                                                     * '<S570>/Constant27'
                                                     * '<S570>/Constant34'
                                                     * '<S570>/Constant49'
                                                     * '<S570>/Constant5'
                                                     * '<S571>/Constant34'
                                                     */
extern CALDATA const volatile uint8 WiperCtl_WashAfterNum_C;/* Referenced by: '<S572>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_WashAfterTim_C;/* Referenced by: '<S572>/Chart' */
extern CALDATA const volatile uint16 WiperCtl_WashMaxTim_C;/* Referenced by: '<S571>/Constant' */
extern CALDATA const volatile uint16 WiperCtl_WashMinTim_C;/* Referenced by: '<S571>/Constant3' */
extern CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdFlg_C;/* Referenced by: '<S234>/Constant18' */
extern CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdVal_C;/* Referenced by: '<S234>/Constant19' */
extern CALDATA const volatile uint16 WiperCtl_WashTimInValid_C;/* Referenced by: '<S570>/Constant26' */
extern CALDATA const volatile uint16 WiperCtl_WashTimValid_C;/* Referenced by: '<S570>/Constant25' */
extern CALDATA const volatile boolean WiperCtl_WashVal_C;/* Referenced by: '<S570>/Constant29' */

/* 低有效 */
extern CALDATA const volatile uint16 WiperCtl_WiperParkPosTimValid_C;/* Referenced by: '<S570>/Constant32' */
extern CALDATA const volatile boolean WiperCtl_WiperParkPosVal_C;/* Referenced by: '<S570>/Constant36' */

/* 低有效 */
extern CALDATA const volatile uint16 WiperCtl_WiperPosTimInValid_C;/* Referenced by: '<S570>/Constant33' */
extern CALDATA const volatile uint8 WiperCtl_WiperSwVal_C;/* Referenced by: '<S570>/Constant60' */

#endif                                 /* RTW_HEADER_calPrmsBcm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
