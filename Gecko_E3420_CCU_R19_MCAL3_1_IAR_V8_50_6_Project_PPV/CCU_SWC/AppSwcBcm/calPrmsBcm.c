/*
 * File: calPrmsBcm.c
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

#include "calPrmsBcm.h"
#include "AppSwcBcm.h"

/* Exported data definition */

/*Group of variables*/
#include "XcpTest_types.h"

/* Definition for custom storage class: CalParam */
CALDATA const volatile uint16 AlmSysCtl_AlrmTimLimit_C = 600U;/* Referenced by: '<S619>/AlmSysLogic' */
CALDATA const volatile uint16 BatSaveCtl_DlyTim_C = 12000U;/* Referenced by: '<S647>/Constant2' */
CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdFlg_C = false;/* Referenced by: '<S620>/Constant18' */
CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdVal_C = false;/* Referenced by: '<S620>/Constant19' */
CALDATA const volatile uint16 BatSaveCtl_LckDlyTim_C = 40U;/* Referenced by: '<S647>/Constant7' */
CALDATA const volatile uint16 DoorLckCtl_AntiLckProtTim_C = 20U;/* Referenced by: '<S663>/Constant' */
CALDATA const volatile uint16 DoorLckCtl_AutoLckDelayTim_C = 1200U;/* Referenced by: '<S709>/Constant7' */
CALDATA const volatile uint16 DoorLckCtl_CntSubTim_C = 26U;/* Referenced by: '<S669>/Constant' */
CALDATA const volatile uint16 DoorLckCtl_CrshPwrOnTimInValid_C = 10U;/* Referenced by: '<S691>/Constant4' */
CALDATA const volatile uint16 DoorLckCtl_CrshPwrOnTimValid_C = 400U;/* Referenced by: '<S691>/Constant3' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimInValid_C = 10U;/* Referenced by: '<S660>/Constant2' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimValid_C = 10U;/* Referenced by: '<S660>/Constant1' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarFLVal_C = false;/* Referenced by: '<S660>/Constant4' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimInValid_C = 10U;/* Referenced by: '<S660>/Constant7' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimValid_C = 10U;/* Referenced by: '<S660>/Constant6' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarFRVal_C = false;/* Referenced by: '<S660>/Constant9' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimInvalid_C = 10U;/* Referenced by: '<S660>/Constant35' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimValid_C = 10U;/* Referenced by: '<S660>/Constant34' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarRLVal_C = false;/* Referenced by: '<S660>/Constant18' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimInvalid_C = 10U;/* Referenced by: '<S660>/Constant38' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimValid_C = 10U;/* Referenced by: '<S660>/Constant37' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarRRVal_C = false;/* Referenced by: '<S660>/Constant20' */
CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimInValid_C = 10U;/* Referenced by: '<S660>/Constant47' */
CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimValid_C = 10U;/* Referenced by: '<S660>/Constant46' */
CALDATA const volatile boolean DoorLckCtl_DriverDoorLckVal_C = false;/* Referenced by: '<S660>/Constant60' */
CALDATA const volatile uint16 DoorLckCtl_DrvPETimInvalid_C = 100U;/* Referenced by: '<S660>/Constant26' */
CALDATA const volatile uint16 DoorLckCtl_DrvPETimValid_C = 5U;/* Referenced by: '<S660>/Constant25' */
CALDATA const volatile boolean DoorLckCtl_DrvPEVal_C = false;/* Referenced by: '<S660>/Constant12' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisMin_C = 55U;/* Referenced by: '<S660>/Constant67' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisVal_C = 0U;/* Referenced by: '<S660>/Constant63' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimInValid_C = 10U;/* Referenced by: '<S660>/Constant65' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimValid_C = 10U;/* Referenced by: '<S660>/Constant64' */
CALDATA const volatile uint16 DoorLckCtl_DrvTim_C = 200U;/* Referenced by: '<S622>/DoorDrv' */
CALDATA const volatile uint8 DoorLckCtl_EEIlluminatedEntrySys_C = 0U;/* Referenced by: '<S660>/Constant74' */
CALDATA const volatile uint8 DoorLckCtl_EEKeyEntry_C = 0U;/* Referenced by: '<S660>/Constant72' */
CALDATA const volatile uint8 DoorLckCtl_IllmndSts_C = 0U;/* Referenced by: '<S660>/Constant76' */
CALDATA const volatile uint16 DoorLckCtl_InportCalSwBit_C = 0U;/* Referenced by:
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
CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdFlg_C = false;/* Referenced by: '<S622>/Constant3' */
CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdVal_C = false;/* Referenced by: '<S622>/Constant4' */
CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdFlg_C = false;/* Referenced by: '<S622>/Constant1' */
CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdVal_C = false;/* Referenced by: '<S622>/Constant2' */
CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdFlg_C = false;/* Referenced by: '<S622>/Constant18' */
CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdVal_C = false;/* Referenced by: '<S622>/Constant19' */
CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMaxTim_C = 25U;/* Referenced by: '<S622>/DoorDrv' */
CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMinTim_C = 10U;/* Referenced by: '<S622>/DoorDrv' */
CALDATA const volatile uint16 DoorLckCtl_MotorProtTimMax_C = 400U;/* Referenced by: '<S669>/Constant2' */
CALDATA const volatile uint8 DoorLckCtl_MotorWorkMax_C = 10U;/* Referenced by: '<S669>/Constant1' */
CALDATA const volatile uint16 DoorLckCtl_PEProtCnt_C = 2U;/* Referenced by: '<S672>/Constant3' */
CALDATA const volatile uint16 DoorLckCtl_PEProtIntvlTim_C = 20U;/* Referenced by: '<S672>/Constant2' */
CALDATA const volatile uint16 DoorLckCtl_PsgPETimInvalid_C = 100U;/* Referenced by:
                                                                   * '<S660>/Constant29'
                                                                   * '<S660>/Constant32'
                                                                   */
CALDATA const volatile uint16 DoorLckCtl_PsgPETimValid_C = 5U;/* Referenced by:
                                                               * '<S660>/Constant28'
                                                               * '<S660>/Constant31'
                                                               */
CALDATA const volatile boolean DoorLckCtl_PsgPEVal_C = false;/* Referenced by: '<S660>/Constant14' */
CALDATA const volatile uint16 DoorLckCtl_SpdLckTimInValid_C = 50U;/* Referenced by:
                                                                   * '<S679>/Constant10'
                                                                   * '<S679>/Constant3'
                                                                   */
CALDATA const volatile uint16 DoorLckCtl_SpdLckTimValid_C = 200U;/* Referenced by:
                                                                  * '<S679>/Constant2'
                                                                  * '<S679>/Constant9'
                                                                  */
CALDATA const volatile uint8 DoorLckCtl_SpdLck_C = 20U;/* Referenced by: '<S679>/Constant' */
CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimInvalid_C = 10U;/* Referenced by: '<S660>/Constant41' */
CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimValid_C = 10U;/* Referenced by: '<S660>/Constant40' */
CALDATA const volatile boolean DoorLckCtl_TrunkAjarVal_C = false;/* Referenced by: '<S660>/Constant22' */
CALDATA const volatile uint16 DoorLckCtl_TrunkAutoLckTim_C = 1200U;/* Referenced by: '<S713>/Constant1' */
CALDATA const volatile boolean DoorLckCtl_TrunkSwVal_C = false;/* Referenced by: '<S660>/Constant16' */
CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimInvalid_C = 10U;/* Referenced by: '<S737>/Constant3' */
CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimValid_C = 150U;/* Referenced by: '<S737>/Constant2' */
CALDATA const volatile float32 DoorLckCtl_Ts_C = 0.05F;/* Referenced by:
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
CALDATA const volatile boolean EEWriteCtl_ImmOvrdFlg_C = false;/* Referenced by: '<S5>/EEWriteCtl' */
CALDATA const volatile uint8 EEWriteCtl_ImmOvrdVal_C[128] = { 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U,
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U } ;/* Referenced by: '<S5>/EEWriteCtl' */

CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdFlg_C = false;/* Referenced by: '<S821>/Constant18' */
CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdVal_C = false;/* Referenced by: '<S821>/Constant19' */
CALDATA const volatile uint16 ESCLCtl_LckDelay_C = 4U;/* Referenced by: '<S821>/ESCLLck' */
CALDATA const volatile uint16 ESCLCtl_LckTimMax_C = 60U;/* Referenced by: '<S821>/ESCLLck' */
CALDATA const volatile uint16 ESCLCtl_UnlckDelay_C = 4U;/* Referenced by: '<S821>/ESCLUnlck' */
CALDATA const volatile uint16 ESCLCtl_UnlckTimMax_C = 60U;/* Referenced by: '<S821>/ESCLUnlck' */
CALDATA const volatile uint16 HornCtl_HornSwTimInvalid_C = 2U;/* Referenced by: '<S279>/Constant38' */
CALDATA const volatile uint16 HornCtl_HornSwTimValid_C = 2U;/* Referenced by: '<S279>/Constant37' */
CALDATA const volatile boolean HornCtl_J430HornDrvOvrdFlg_C = false;/* Referenced by: '<S232>/Constant18' */
CALDATA const volatile boolean HornCtl_J430HornDrvOvrdVal_C = false;/* Referenced by: '<S232>/Constant19' */
CALDATA const volatile uint16 HornCtl_TrunkWarnTim_C = 1500U;/* Referenced by: '<S284>/Chart' */
CALDATA const volatile float32 HornCtl_Ts_C = 0.02F;/* Referenced by: '<S279>/Constant39' */
CALDATA const volatile uint16 LampCtl_AutoLampDayDelayTim_C = 1000U;/* Referenced by: '<S310>/Constant6' */
CALDATA const volatile uint16 LampCtl_AutoLampNightDelayTim_C = 100U;/* Referenced by: '<S310>/Constant43' */
CALDATA const volatile uint16 LampCtl_AutoLampTimInValid_C = 0U;/* Referenced by: '<S340>/Constant63' */
CALDATA const volatile uint16 LampCtl_AutoLampTimValid_C = 0U;/* Referenced by: '<S340>/Constant9' */
CALDATA const volatile boolean LampCtl_AutoLampVal_C = false;/* Referenced by: '<S340>/Constant8' */
CALDATA const volatile uint16 LampCtl_BoxLampOpenTimMax_C = 30000U;/* Referenced by: '<S312>/Constant4' */
CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdFlg_C = false;/* Referenced by: '<S233>/Constant3' */
CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdVal_C = false;/* Referenced by: '<S233>/Constant4' */
CALDATA const volatile boolean LampCtl_BrakeLightVal_C = false;/* Referenced by:
                                                                * '<S340>/Constant62'
                                                                * '<S340>/Constant74'
                                                                */
CALDATA const volatile uint16 LampCtl_BrakeSwInValid_C = 5U;/* Referenced by:
                                                             * '<S340>/Constant15'
                                                             * '<S340>/Constant71'
                                                             */
CALDATA const volatile uint16 LampCtl_BrakeSwTimValid_C = 5U;/* Referenced by:
                                                              * '<S340>/Constant14'
                                                              * '<S340>/Constant70'
                                                              */
CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdFlg_C = false;/* Referenced by: '<S233>/Constant1' */
CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdVal_C = false;/* Referenced by: '<S233>/Constant2' */
CALDATA const volatile uint16 LampCtl_DayTimeVal_C = 1000U;/* Referenced by: '<S320>/Chart' */
CALDATA const volatile boolean LampCtl_DomeLampPwmDutyOvrdFlg_C = false;/* Referenced by: '<S233>/Constant22' */
CALDATA const volatile uint8 LampCtl_DomeLampPwmDutyOvrdVal_C = 0U;/* Referenced by: '<S233>/Constant21' */
CALDATA const volatile uint16 LampCtl_FlwrMeHomeTimValid_C = 25U;/* Referenced by: '<S549>/Constant43' */
CALDATA const volatile boolean LampCtl_FogLampFStaOvrdFlg_C = false;/* Referenced by: '<S233>/Constant14' */
CALDATA const volatile boolean LampCtl_FogLampFStaOvrdVal_C = false;/* Referenced by: '<S233>/Constant13' */
CALDATA const volatile uint16 LampCtl_FogLampFTimInValid_C = 5U;/* Referenced by: '<S340>/Constant66' */
CALDATA const volatile uint16 LampCtl_FogLampFTimValid_C = 5U;/* Referenced by: '<S340>/Constant64' */
CALDATA const volatile boolean LampCtl_FogLampFVal_C = false;/* Referenced by: '<S340>/Constant69' */
CALDATA const volatile boolean LampCtl_FogLampRStaOvrdFlg_C = false;/* Referenced by: '<S233>/Constant12' */
CALDATA const volatile boolean LampCtl_FogLampRStaOvrdVal_C = false;/* Referenced by: '<S233>/Constant11' */
CALDATA const volatile uint16 LampCtl_FogLampRTimInValid_C = 5U;/* Referenced by: '<S340>/Constant44' */
CALDATA const volatile uint16 LampCtl_FogLampRTimValid_C = 5U;/* Referenced by: '<S340>/Constant43' */
CALDATA const volatile boolean LampCtl_FogLampRVal_C = false;/* Referenced by: '<S340>/Constant56' */
CALDATA const volatile uint16 LampCtl_HazardLightTimInValid_C = 0U;/* Referenced by: '<S340>/Constant47' */
CALDATA const volatile uint16 LampCtl_HazardLightTimValid_C = 0U;/* Referenced by: '<S340>/Constant46' */
CALDATA const volatile boolean LampCtl_HazardLightVal_C = false;/* Referenced by: '<S340>/Constant60' */
CALDATA const volatile uint16 LampCtl_HiBeamShortToBatTimInValid_C = 500U;/* Referenced by: '<S317>/Constant29' */
CALDATA const volatile boolean LampCtl_HiBeamStaOvrdFlg_C = false;/* Referenced by: '<S233>/Constant20' */
CALDATA const volatile boolean LampCtl_HiBeamStaOvrdVal_C = false;/* Referenced by: '<S233>/Constant17' */
CALDATA const volatile uint16 LampCtl_HiBeamTimInValid_C = 0U;/* Referenced by: '<S340>/Constant26' */
CALDATA const volatile uint16 LampCtl_HiBeamTimValid_C = 0U;/* Referenced by: '<S340>/Constant25' */
CALDATA const volatile boolean LampCtl_HiBeamVal_C = false;/* Referenced by: '<S340>/Constant11' */
CALDATA const volatile uint16 LampCtl_InportCalSwBit_C = 0U;/* Referenced by:
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
CALDATA const volatile boolean LampCtl_J408BackLampPWMOvrdFlg_C = false;/* Referenced by: '<S233>/Constant30' */
CALDATA const volatile uint8 LampCtl_J408BackLampPWMOvrdVal_C = 0U;/* Referenced by: '<S233>/Constant29' */
CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdFlg_C = false;/* Referenced by: '<S233>/Constant5' */
CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdVal_C = false;/* Referenced by: '<S233>/Constant6' */
CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdFlg_C = false;/* Referenced by: '<S233>/Constant7' */
CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdVal_C = false;/* Referenced by: '<S233>/Constant8' */
CALDATA const volatile boolean LampCtl_J449BoxLampOvrdFlg_C = false;/* Referenced by: '<S233>/Constant28' */
CALDATA const volatile boolean LampCtl_J449BoxLampOvrdVal_C = false;/* Referenced by: '<S233>/Constant27' */
CALDATA const volatile uint8 LampCtl_LOpenCnt_C = 3U;/* Referenced by: '<S450>/Constant17' */
CALDATA const volatile uint8 LampCtl_LShortCnt_C = 3U;/* Referenced by: '<S450>/Constant19' */
CALDATA const volatile uint16 LampCtl_LampDelayTim_C = 3000U;/* Referenced by: '<S319>/Constant6' */
CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimInValid_C = 500U;/* Referenced by: '<S321>/Constant29' */
CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimValid_C = 500U;/* Referenced by: '<S321>/Constant28' */
CALDATA const volatile boolean LampCtl_LowBeamStaOvrdFlg_C = false;/* Referenced by: '<S233>/Constant9' */
CALDATA const volatile boolean LampCtl_LowBeamStaOvrdVal_C = false;/* Referenced by: '<S233>/Constant10' */
CALDATA const volatile uint16 LampCtl_LowBeamStaTimInValid_C = 0U;/* Referenced by: '<S321>/Constant5' */
CALDATA const volatile uint16 LampCtl_LowBeamStaTimValid_C = 0U;/* Referenced by: '<S321>/Constant4' */
CALDATA const volatile uint16 LampCtl_LowBeamTimInValid_C = 0U;/* Referenced by: '<S340>/Constant24' */
CALDATA const volatile uint16 LampCtl_LowBeamTimValid_C = 0U;/* Referenced by: '<S340>/Constant23' */
CALDATA const volatile boolean LampCtl_LowBeamVal_C = false;/* Referenced by: '<S340>/Constant10' */
CALDATA const volatile uint16 LampCtl_NightVal_C = 1000U;/* Referenced by: '<S320>/Chart' */
CALDATA const volatile uint16 LampCtl_OsUnlckDelayTim_C = 35U;/* Referenced by: '<S554>/Constant3' */
CALDATA const volatile uint16 LampCtl_PassLightTimInValid_C = 0U;/* Referenced by: '<S340>/Constant29' */
CALDATA const volatile uint16 LampCtl_PassLightTimValid_C = 0U;/* Referenced by: '<S340>/Constant28' */
CALDATA const volatile boolean LampCtl_PassLightVal_C = false;/* Referenced by: '<S340>/Constant2' */
CALDATA const volatile boolean LampCtl_PosLampStaOvrdFlg_C = false;/* Referenced by: '<S233>/Constant18' */
CALDATA const volatile boolean LampCtl_PosLampStaOvrdVal_C = false;/* Referenced by: '<S233>/Constant19' */
CALDATA const volatile uint16 LampCtl_PosLampStaTimInValid_C = 5U;/* Referenced by: '<S338>/Constant4' */
CALDATA const volatile uint16 LampCtl_PosLampStaTimValid_C = 5U;/* Referenced by: '<S338>/Constant2' */
CALDATA const volatile uint16 LampCtl_PosLampTimInValid_C = 0U;/* Referenced by: '<S340>/Constant20' */
CALDATA const volatile uint16 LampCtl_PosLampTimValid_C = 0U;/* Referenced by: '<S340>/Constant19' */
CALDATA const volatile boolean LampCtl_PosLampVal_C = false;/* Referenced by: '<S340>/Constant50' */
CALDATA const volatile uint8 LampCtl_ROpenCnt_C = 3U;/* Referenced by: '<S450>/Constant8' */
CALDATA const volatile uint8 LampCtl_RShortCnt_C = 3U;/* Referenced by: '<S450>/Constant16' */
CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdFlg_C = false;/* Referenced by: '<S233>/Constant16' */
CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdVal_C = false;/* Referenced by: '<S233>/Constant15' */
CALDATA const volatile uint16 LampCtl_TrunkWarnTim_C = 1500U;/* Referenced by: '<S448>/Chart' */
CALDATA const volatile float32 LampCtl_Ts_C = 0.02F;/* Referenced by:
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
CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimInValid_C = 10U;/* Referenced by: '<S450>/Constant44' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimValid_C = 10U;/* Referenced by: '<S450>/Constant43' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimInValid_C = 10U;/* Referenced by: '<S450>/Constant10' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimValid_C = 10U;/* Referenced by: '<S450>/Constant9' */
CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdFlg_C = false;/* Referenced by: '<S233>/Constant25' */
CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdVal_C = false;/* Referenced by: '<S233>/Constant26' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLTimInValid_C = 0U;/* Referenced by: '<S340>/Constant32' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLTimValid_C = 70U;/* Referenced by: '<S340>/Constant31' */
CALDATA const volatile boolean LampCtl_TurnIndcrLVal_C = false;/* Referenced by: '<S340>/Constant54' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimInValid_C = 0U;/* Referenced by: '<S340>/Constant35' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimValid_C = 0U;/* Referenced by: '<S340>/Constant34' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimInValid_C = 0U;/* Referenced by: '<S340>/Constant41' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimValid_C = 0U;/* Referenced by: '<S340>/Constant40' */
CALDATA const volatile uint16 LampCtl_TurnIndcrOpenCur_C = 30U;/* Referenced by:
                                                                * '<S450>/Constant11'
                                                                * '<S450>/Constant21'
                                                                */
CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimInValid_C = 10U;/* Referenced by: '<S450>/Constant3' */
CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimValid_C = 10U;/* Referenced by: '<S450>/Constant2' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimInValid_C = 10U;/* Referenced by: '<S450>/Constant12' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimValid_C = 10U;/* Referenced by: '<S450>/Constant14' */
CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdFlg_C = false;/* Referenced by: '<S233>/Constant23' */
CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdVal_C = false;/* Referenced by: '<S233>/Constant24' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRTimInValid_C = 0U;/* Referenced by: '<S340>/Constant38' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRTimValid_C = 70U;/* Referenced by: '<S340>/Constant37' */
CALDATA const volatile boolean LampCtl_TurnIndcrRVal_C = false;/* Referenced by: '<S340>/Constant5' */
CALDATA const volatile uint16 LampCtl_TurnIndcrShortCur_C = 6000U;/* Referenced by:
                                                                   * '<S450>/Constant20'
                                                                   * '<S450>/Constant4'
                                                                   */
CALDATA const volatile uint16 LampCtl_WelcomeLampTimMax_C = 3000U;/* Referenced by: '<S553>/Constant6' */
CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdFlg_C = false;/* Referenced by: '<S626>/Constant18' */
CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdVal_C = false;/* Referenced by: '<S626>/Constant19' */
CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdFlg_C = false;/* Referenced by: '<S626>/Constant1' */
CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdVal_C = false;/* Referenced by: '<S626>/Constant2' */
CALDATA const volatile boolean PDUCtl_KeyValidOvrdFlg_C = false;/* Referenced by:
                                                                 * '<S841>/Constant12'
                                                                 * '<S841>/Constant9'
                                                                 */
CALDATA const volatile boolean PDUCtl_KeyValidOvrdVal_C = false;/* Referenced by:
                                                                 * '<S841>/Constant10'
                                                                 * '<S841>/Constant11'
                                                                 */
CALDATA const volatile uint16 PDUCtl_OpenDoorPwrOnTimValid = 6000U;/* Referenced by: '<S841>/Constant6' */
CALDATA const volatile uint16 PDUCtl_PwrOnPSTimValid_C = 40U;/* Referenced by: '<S841>/Constant3' */
CALDATA const volatile uint16 PDUCtl_StartReqOverTimValid_C = 200U;/* Referenced by: '<S843>/Constant5' */
CALDATA const volatile uint16 PDUCtl_StartReqTimValid_C = 10U;/* Referenced by: '<S843>/Constant4' */
CALDATA const volatile uint8 PDUCtl_TimOutPwrOffH_C = 1U;/* Referenced by: '<S840>/Constant4' */
CALDATA const volatile uint8 PDUCtl_TimOutPwrOffM_C = 0U;/* Referenced by: '<S840>/Constant5' */
CALDATA const volatile uint8 PDUCtl_TimOutPwrOffS_C = 0U;/* Referenced by: '<S840>/Constant6' */
CALDATA const volatile float32 PDUCtl_Ts_C = 0.05F;/* Referenced by:
                                                    * '<S840>/Constant7'
                                                    * '<S842>/Constant13'
                                                    * '<S842>/Constant6'
                                                    * '<S842>/Constant8'
                                                    */
CALDATA const volatile boolean RVMCtl_J42HeatOvrdFlg_C = false;/* Referenced by: '<S7>/Constant18' */
CALDATA const volatile boolean RVMCtl_J42HeatOvrdVal_C = false;/* Referenced by: '<S7>/Constant19' */
CALDATA const volatile uint8 RVMCtl_MaxHeatTimM_C = 25U;/* Referenced by: '<S125>/Constant2' */
CALDATA const volatile float32 RVMCtl_Ts_C = 0.1F;/* Referenced by: '<S125>/Constant7' */
CALDATA const volatile boolean SeatCtl_CN167DrvSeatHtPWMOvrdFlg_C = false;/* Referenced by: '<S129>/Constant18' */
CALDATA const volatile uint8 SeatCtl_CN167DrvSeatHtPWMOvrdVal_C = 0U;/* Referenced by: '<S129>/Constant19' */
CALDATA const volatile float32 SeatCtl_DrvSeatTempLookUp_X[24] = { 2143.0F,
  2220.0F, 2301.0F, 2385.0F, 2473.0F, 2564.0F, 2660.0F, 2759.0F, 2863.0F,
  2971.0F, 3084.0F, 3202.0F, 4530.0F, 4713.0F, 4905.0F, 5105.0F, 5315.0F,
  5534.0F, 5764.0F, 6005.0F, 6258.0F, 6522.0F, 6800.0F, 7090.0F } ;
                                 /* Referenced by: '<S129>/1-D Lookup Table2' */

CALDATA const volatile float32 SeatCtl_DrvSeatTempLookUp_Y[24] = { 64.0F, 63.0F,
  62.0F, 61.0F, 60.0F, 59.0F, 58.0F, 57.0F, 56.0F, 55.0F, 54.0F, 53.0F, 44.0F,
  43.0F, 42.0F, 41.0F, 40.0F, 39.0F, 38.0F, 37.0F, 36.0F, 35.0F, 34.0F, 33.0F } ;
                                 /* Referenced by: '<S129>/1-D Lookup Table2' */

CALDATA const volatile uint8 SeatCtl_DrvTempLvl0_C = 0U;/* Referenced by: '<S129>/Constant8' */
CALDATA const volatile uint8 SeatCtl_DrvTempLvl1_C = 55U;/* Referenced by: '<S129>/Constant5' */
CALDATA const volatile uint8 SeatCtl_DrvTempLvl2_C = 58U;/* Referenced by: '<S129>/Constant6' */
CALDATA const volatile uint8 SeatCtl_DrvTempLvl3_C = 62U;/* Referenced by: '<S129>/Constant7' */
CALDATA const volatile uint8 SeatCtl_HtDiffTemp_C = 2U;/* Referenced by: '<S129>/Chart' */
CALDATA const volatile uint8 SteerWhlCtl_DiffTemp_C = 5U;/* Referenced by: '<S132>/HeatCtl' */
CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdFlg_C = false;/* Referenced by: '<S132>/Constant18' */
CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdVal_C = false;/* Referenced by: '<S132>/Constant19' */
CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_X[3] = { 5838.0F,
  6954.0F, 8318.0F } ;           /* Referenced by: '<S132>/1-D Lookup Table1' */

CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_Y[3] = { 40.0F,
  35.0F, 30.0F } ;               /* Referenced by: '<S132>/1-D Lookup Table1' */

CALDATA const volatile uint8 SteerWhlCtl_TrgtTemp_C = 35U;/* Referenced by: '<S132>/HeatCtl' */
CALDATA const volatile uint16 WakeUpCtl_CANSleepDelayTim_C = 300U;/* Referenced by: '<S872>/Constant22' */
CALDATA const volatile uint16 WakeUpCtl_LocalSleepDelayTim_C = 200U;/* Referenced by: '<S873>/Constant27' */
CALDATA const volatile uint16 WakeUpCtl_WinCtlDelayTim_C = 1200U;/* Referenced by: '<S872>/Constant3' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMaxResis_C = 200U;/* Referenced by: '<S141>/Constant51' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMinResis_C = 0U;/* Referenced by: '<S141>/Constant50' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimInValid_C = 10U;/* Referenced by: '<S141>/Constant10' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimValid_C = 10U;/* Referenced by: '<S141>/Constant9' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMaxResis_C = 2500U;/* Referenced by: '<S141>/Constant49' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMinResis_C = 2000U;/* Referenced by: '<S141>/Constant48' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimInValid_C = 10U;/* Referenced by: '<S141>/Constant7' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimValid_C = 10U;/* Referenced by: '<S141>/Constant6' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinSwResis_C = 0U;/* Referenced by: '<S141>/Constant5' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMaxResis_C = 1500U;/* Referenced by: '<S141>/Constant47' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMinResis_C = 1000U;/* Referenced by: '<S141>/Constant46' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimInValid_C = 10U;/* Referenced by: '<S141>/Constant3' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimValid_C = 10U;/* Referenced by: '<S141>/Constant2' */
CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMaxResis_C = 200U;/* Referenced by: '<S141>/Constant36' */
CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMinResis_C = 0U;/* Referenced by: '<S141>/Constant35' */
CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimInValid_C = 10U;/* Referenced by: '<S141>/Constant24' */
CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimValid_C = 10U;/* Referenced by: '<S141>/Constant23' */
CALDATA const volatile uint16 WinCtl_DrvWinDnMaxResis_C = 2500U;/* Referenced by: '<S141>/Constant31' */
CALDATA const volatile uint16 WinCtl_DrvWinDnMinResis_C = 2000U;/* Referenced by: '<S141>/Constant26' */
CALDATA const volatile uint16 WinCtl_DrvWinDnTimInValid_C = 10U;/* Referenced by: '<S141>/Constant18' */
CALDATA const volatile uint16 WinCtl_DrvWinDnTimValid_C = 10U;/* Referenced by: '<S141>/Constant17' */
CALDATA const volatile uint16 WinCtl_DrvWinSwResis_C = 0U;/* Referenced by: '<S141>/Constant15' */
CALDATA const volatile uint16 WinCtl_DrvWinUpMaxResis_C = 1500U;/* Referenced by: '<S141>/Constant22' */
CALDATA const volatile uint16 WinCtl_DrvWinUpMinResis_C = 1000U;/* Referenced by: '<S141>/Constant20' */
CALDATA const volatile uint16 WinCtl_DrvWinUpTimInValid_C = 10U;/* Referenced by: '<S141>/Constant13' */
CALDATA const volatile uint16 WinCtl_DrvWinUpTimValid_C = 10U;/* Referenced by: '<S141>/Constant12' */
CALDATA const volatile uint16 WinCtl_InportCalSwBit_C = 0U;/* Referenced by:
                                                            * '<S141>/Constant1'
                                                            * '<S141>/Constant11'
                                                            * '<S141>/Constant21'
                                                            */
CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdFlg_C = false;/* Referenced by: '<S10>/Constant18' */
CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdVal_C = false;/* Referenced by: '<S10>/Constant19' */
CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdFlg_C = false;/* Referenced by: '<S10>/Constant1' */
CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdVal_C = false;/* Referenced by: '<S10>/Constant2' */
CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdFlg_C = false;/* Referenced by: '<S10>/Constant3' */
CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdVal_C = false;/* Referenced by: '<S10>/Constant4' */
CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdFlg_C = false;/* Referenced by: '<S10>/Constant5' */
CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdVal_C = false;/* Referenced by: '<S10>/Constant6' */
CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMaxResis_C = 200U;/* Referenced by: '<S141>/Constant45' */
CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMinResis_C = 0U;/* Referenced by: '<S141>/Constant44' */
CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimInValid_C = 10U;/* Referenced by: '<S141>/Constant38' */
CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimValid_C = 10U;/* Referenced by: '<S141>/Constant37' */
CALDATA const volatile uint16 WinCtl_PsgWinDnMaxResis_C = 2500U;/* Referenced by: '<S141>/Constant43' */
CALDATA const volatile uint16 WinCtl_PsgWinDnMinResis_C = 2000U;/* Referenced by: '<S141>/Constant42' */
CALDATA const volatile uint16 WinCtl_PsgWinDnTimInValid_C = 10U;/* Referenced by: '<S141>/Constant33' */
CALDATA const volatile uint16 WinCtl_PsgWinDnTimValid_C = 10U;/* Referenced by: '<S141>/Constant32' */
CALDATA const volatile uint16 WinCtl_PsgWinSwResis_C = 0U;/* Referenced by: '<S141>/Constant30' */
CALDATA const volatile uint16 WinCtl_PsgWinUpMaxResis_C = 1500U;/* Referenced by: '<S141>/Constant41' */
CALDATA const volatile uint16 WinCtl_PsgWinUpMinResis_C = 1000U;/* Referenced by: '<S141>/Constant40' */
CALDATA const volatile uint16 WinCtl_PsgWinUpTimInValid_C = 10U;/* Referenced by: '<S141>/Constant28' */
CALDATA const volatile uint16 WinCtl_PsgWinUpTimValid_C = 10U;/* Referenced by: '<S141>/Constant27' */
CALDATA const volatile uint16 WinCtl_PwrOffWinValidTimMax_C = 600U;/* Referenced by: '<S143>/Constant20' */
CALDATA const volatile float32 WinCtl_Ts_C = 0.1F;/* Referenced by:
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
CALDATA const volatile uint16 WinCtl_WinMotorCurMax_C = 18000U;/* Referenced by:
                                                                * '<S143>/Constant37'
                                                                * '<S143>/Constant48'
                                                                */
CALDATA const volatile uint16 WinCtl_WinMotorCurTimInValid_C = 10U;/* Referenced by:
                                                                    * '<S143>/Constant35'
                                                                    * '<S143>/Constant44'
                                                                    */
CALDATA const volatile uint16 WinCtl_WinMotorCurTimValid_C = 150U;/* Referenced by:
                                                                   * '<S143>/Constant11'
                                                                   * '<S143>/Constant34'
                                                                   */
CALDATA const volatile uint16 WinCtl_WinProtNum_C = 30U;/* Referenced by:
                                                         * '<S142>/Constant15'
                                                         * '<S142>/Constant2'
                                                         * '<S142>/Constant6'
                                                         * '<S142>/Constant9'
                                                         */
CALDATA const volatile uint16 WinCtl_WinProtTim_C = 100U;/* Referenced by:
                                                          * '<S142>/Constant1'
                                                          * '<S142>/Constant14'
                                                          * '<S142>/Constant5'
                                                          * '<S142>/Constant8'
                                                          */
CALDATA const volatile uint16 WinCtl_WinRunTimMax_C = 120U;/* Referenced by:
                                                            * '<S143>/Constant40'
                                                            * '<S143>/Constant8'
                                                            */
CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdFlg_C = false;/* Referenced by: '<S234>/Constant3' */
CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdVal_C = false;/* Referenced by: '<S234>/Constant4' */
CALDATA const volatile uint16 WiperCtl_HiSpdTimInValid_C = 10U;/* Referenced by: '<S570>/Constant22' */
CALDATA const volatile uint16 WiperCtl_HiSpdTimValid_C = 10U;/* Referenced by: '<S570>/Constant21' */
CALDATA const volatile uint16 WiperCtl_InportCalSwBit_C = 0U;/* Referenced by:
                                                              * '<S570>/Constant28'
                                                              * '<S570>/Constant35'
                                                              * '<S570>/Constant59'
                                                              */
CALDATA const volatile uint16 WiperCtl_InrLvl1Tim_C = 100U;/* Referenced by: '<S574>/Constant1' */
CALDATA const volatile uint16 WiperCtl_InrLvl2Tim_C = 200U;/* Referenced by: '<S574>/Constant2' */
CALDATA const volatile uint16 WiperCtl_InrLvl3Tim_C = 400U;/* Referenced by:
                                                            * '<S574>/Constant3'
                                                            * '<S574>/Constant8'
                                                            */
CALDATA const volatile uint16 WiperCtl_InrLvl4Tim_C = 500U;/* Referenced by: '<S574>/Constant4' */
CALDATA const volatile uint16 WiperCtl_InrLvl5Tim_C = 650U;/* Referenced by: '<S574>/Constant5' */
CALDATA const volatile uint16 WiperCtl_InrLvl6Tim_C = 500U;/* Referenced by: '<S574>/Constant6' */
CALDATA const volatile uint16 WiperCtl_InrLvl7Tim_C = 300U;/* Referenced by: '<S574>/Constant7' */
CALDATA const volatile uint16 WiperCtl_InrTimInValid_C = 10U;/* Referenced by: '<S570>/Constant9' */
CALDATA const volatile uint16 WiperCtl_InrTimValid_C = 10U;/* Referenced by: '<S570>/Constant8' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimDef_C = 250U;/* Referenced by: '<S566>/Constant1' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimOk_C = 5U;/* Referenced by: '<S566>/Constant2' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkDef_C = 100U;/* Referenced by: '<S566>/Constant4' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkOk_C = 5U;/* Referenced by: '<S566>/Constant5' */
CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdFlg_C = false;/* Referenced by: '<S234>/Constant1' */
CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdVal_C = false;/* Referenced by: '<S234>/Constant2' */
CALDATA const volatile uint16 WiperCtl_LowSpdTimInValid_C = 10U;/* Referenced by: '<S570>/Constant17' */
CALDATA const volatile uint16 WiperCtl_LowSpdTimValid_C = 10U;/* Referenced by: '<S570>/Constant16' */
CALDATA const volatile uint16 WiperCtl_MaintWiperRunTim_C = 25U;/* Referenced by: '<S572>/Chart' */
CALDATA const volatile uint16 WiperCtl_MistTimInValid_C = 10U;/* Referenced by: '<S570>/Constant47' */
CALDATA const volatile uint16 WiperCtl_MistTimValid_C = 10U;/* Referenced by: '<S570>/Constant46' */
CALDATA const volatile uint16 WiperCtl_OffTimInValid_C = 10U;/* Referenced by: '<S570>/Constant4' */
CALDATA const volatile uint16 WiperCtl_OffTimValid_C = 10U;/* Referenced by: '<S570>/Constant3' */
CALDATA const volatile float32 WiperCtl_Ts_C = 0.02F;/* Referenced by:
                                                      * '<S570>/Constant10'
                                                      * '<S570>/Constant11'
                                                      * '<S570>/Constant18'
                                                      * '<S570>/Constant27'
                                                      * '<S570>/Constant34'
                                                      * '<S570>/Constant49'
                                                      * '<S570>/Constant5'
                                                      * '<S571>/Constant34'
                                                      */
CALDATA const volatile uint8 WiperCtl_WashAfterNum_C = 4U;/* Referenced by: '<S572>/Chart' */
CALDATA const volatile uint16 WiperCtl_WashAfterTim_C = 150U;/* Referenced by: '<S572>/Chart' */
CALDATA const volatile uint16 WiperCtl_WashMaxTim_C = 600U;/* Referenced by: '<S571>/Constant' */
CALDATA const volatile uint16 WiperCtl_WashMinTim_C = 60U;/* Referenced by: '<S571>/Constant3' */
CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdFlg_C = false;/* Referenced by: '<S234>/Constant18' */
CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdVal_C = false;/* Referenced by: '<S234>/Constant19' */
CALDATA const volatile uint16 WiperCtl_WashTimInValid_C = 10U;/* Referenced by: '<S570>/Constant26' */
CALDATA const volatile uint16 WiperCtl_WashTimValid_C = 60U;/* Referenced by: '<S570>/Constant25' */
CALDATA const volatile boolean WiperCtl_WashVal_C = true;/* Referenced by: '<S570>/Constant29' */

/* ����Ч */
CALDATA const volatile uint16 WiperCtl_WiperParkPosTimValid_C = 2U;/* Referenced by: '<S570>/Constant32' */
CALDATA const volatile boolean WiperCtl_WiperParkPosVal_C = true;/* Referenced by: '<S570>/Constant36' */

/* ����Ч */
CALDATA const volatile uint16 WiperCtl_WiperPosTimInValid_C = 2U;/* Referenced by: '<S570>/Constant33' */
CALDATA const volatile uint8 WiperCtl_WiperSwVal_C = 0U;/* Referenced by: '<S570>/Constant60' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
