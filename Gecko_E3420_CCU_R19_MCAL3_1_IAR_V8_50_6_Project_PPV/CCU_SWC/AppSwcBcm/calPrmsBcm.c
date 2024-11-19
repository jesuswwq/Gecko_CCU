/*
 * File: calPrmsBcm.c
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

#include "calPrmsBcm.h"
#include "AppSwcBcm.h"

/* Exported data definition */

/*Group of variables*/
#include "XcpTest_types.h"

/* Definition for custom storage class: CalParam */
CALDATA const volatile uint16 AlmSysCtl_AlrmTimLimit_C = 600U;/* Referenced by: '<S637>/AlmSysLogic' */
CALDATA const volatile uint16 BatSaveCtl_DlyTim_C = 12000U;/* Referenced by: '<S665>/Constant2' */
CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdFlg_C = false;/* Referenced by: '<S638>/Constant18' */
CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdVal_C = false;/* Referenced by: '<S638>/Constant19' */
CALDATA const volatile uint16 BatSaveCtl_LckDlyTim_C = 40U;/* Referenced by: '<S665>/Constant7' */
CALDATA const volatile uint16 DoorLckCtl_AntiLckProtTim_C = 20U;/* Referenced by: '<S681>/Constant' */
CALDATA const volatile uint16 DoorLckCtl_AutoLckDelayTim_C = 1200U;/* Referenced by: '<S728>/Constant7' */
CALDATA const volatile uint16 DoorLckCtl_CntSubTim_C = 26U;/* Referenced by: '<S687>/Constant' */
CALDATA const volatile uint16 DoorLckCtl_CrshPwrOnTimInValid_C = 10U;/* Referenced by: '<S710>/Constant4' */
CALDATA const volatile uint16 DoorLckCtl_CrshPwrOnTimValid_C = 400U;/* Referenced by: '<S710>/Constant3' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimInValid_C = 10U;/* Referenced by: '<S678>/Constant2' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimValid_C = 10U;/* Referenced by: '<S678>/Constant1' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarFLVal_C = false;/* Referenced by: '<S678>/Constant4' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimInValid_C = 10U;/* Referenced by: '<S678>/Constant7' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimValid_C = 10U;/* Referenced by: '<S678>/Constant6' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarFRVal_C = false;/* Referenced by: '<S678>/Constant9' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimInvalid_C = 10U;/* Referenced by: '<S678>/Constant35' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimValid_C = 10U;/* Referenced by: '<S678>/Constant34' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarRLVal_C = false;/* Referenced by: '<S678>/Constant18' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimInvalid_C = 10U;/* Referenced by: '<S678>/Constant38' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimValid_C = 10U;/* Referenced by: '<S678>/Constant37' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarRRVal_C = false;/* Referenced by: '<S678>/Constant20' */
CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimInValid_C = 10U;/* Referenced by: '<S678>/Constant47' */
CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimValid_C = 10U;/* Referenced by: '<S678>/Constant46' */
CALDATA const volatile boolean DoorLckCtl_DriverDoorLckVal_C = false;/* Referenced by: '<S678>/Constant60' */
CALDATA const volatile uint16 DoorLckCtl_DrvPETimInvalid_C = 100U;/* Referenced by: '<S678>/Constant26' */
CALDATA const volatile uint16 DoorLckCtl_DrvPETimValid_C = 5U;/* Referenced by: '<S678>/Constant25' */
CALDATA const volatile boolean DoorLckCtl_DrvPEVal_C = false;/* Referenced by: '<S678>/Constant12' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisMin_C = 55U;/* Referenced by: '<S678>/Constant67' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisVal_C = 0U;/* Referenced by: '<S678>/Constant63' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimInValid_C = 10U;/* Referenced by: '<S678>/Constant65' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimValid_C = 10U;/* Referenced by: '<S678>/Constant64' */
CALDATA const volatile uint16 DoorLckCtl_DrvTim_C = 200U;/* Referenced by: '<S640>/DoorDrv' */
CALDATA const volatile uint8 DoorLckCtl_EEIlluminatedEntrySys_C = 0U;/* Referenced by: '<S678>/Constant74' */
CALDATA const volatile uint8 DoorLckCtl_EEKeyEntry_C = 0U;/* Referenced by: '<S678>/Constant72' */
CALDATA const volatile uint8 DoorLckCtl_IllmndSts_C = 0U;/* Referenced by: '<S678>/Constant76' */
CALDATA const volatile uint16 DoorLckCtl_InportCalSwBit_C = 0U;/* Referenced by:
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
CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdFlg_C = false;/* Referenced by: '<S640>/Constant3' */
CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdVal_C = false;/* Referenced by: '<S640>/Constant4' */
CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdFlg_C = false;/* Referenced by: '<S640>/Constant1' */
CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdVal_C = false;/* Referenced by: '<S640>/Constant2' */
CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdFlg_C = false;/* Referenced by: '<S640>/Constant18' */
CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdVal_C = false;/* Referenced by: '<S640>/Constant19' */
CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMaxTim_C = 25U;/* Referenced by: '<S640>/DoorDrv' */
CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMinTim_C = 10U;/* Referenced by: '<S640>/DoorDrv' */
CALDATA const volatile uint16 DoorLckCtl_MotorProtTimMax_C = 400U;/* Referenced by: '<S687>/Constant2' */
CALDATA const volatile uint8 DoorLckCtl_MotorWorkMax_C = 10U;/* Referenced by: '<S687>/Constant1' */
CALDATA const volatile uint16 DoorLckCtl_PEProtCnt_C = 2U;/* Referenced by: '<S690>/Constant3' */
CALDATA const volatile uint16 DoorLckCtl_PEProtIntvlTim_C = 20U;/* Referenced by: '<S690>/Constant2' */
CALDATA const volatile uint16 DoorLckCtl_PsgPETimInvalid_C = 100U;/* Referenced by:
                                                                   * '<S678>/Constant29'
                                                                   * '<S678>/Constant32'
                                                                   */
CALDATA const volatile uint16 DoorLckCtl_PsgPETimValid_C = 5U;/* Referenced by:
                                                               * '<S678>/Constant28'
                                                               * '<S678>/Constant31'
                                                               */
CALDATA const volatile boolean DoorLckCtl_PsgPEVal_C = false;/* Referenced by: '<S678>/Constant14' */
CALDATA const volatile uint16 DoorLckCtl_SpdLckTimInValid_C = 50U;/* Referenced by:
                                                                   * '<S698>/Constant10'
                                                                   * '<S698>/Constant3'
                                                                   */
CALDATA const volatile uint16 DoorLckCtl_SpdLckTimValid_C = 200U;/* Referenced by:
                                                                  * '<S698>/Constant2'
                                                                  * '<S698>/Constant9'
                                                                  */
CALDATA const volatile uint8 DoorLckCtl_SpdLck_C = 20U;/* Referenced by: '<S698>/Constant' */
CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimInvalid_C = 10U;/* Referenced by: '<S678>/Constant41' */
CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimValid_C = 10U;/* Referenced by: '<S678>/Constant40' */
CALDATA const volatile boolean DoorLckCtl_TrunkAjarVal_C = false;/* Referenced by: '<S678>/Constant22' */
CALDATA const volatile uint16 DoorLckCtl_TrunkAutoLckTim_C = 1200U;/* Referenced by: '<S733>/Constant1' */
CALDATA const volatile boolean DoorLckCtl_TrunkSwVal_C = false;/* Referenced by: '<S678>/Constant16' */
CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimInvalid_C = 10U;/* Referenced by: '<S759>/Constant3' */
CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimValid_C = 150U;/* Referenced by: '<S759>/Constant2' */
CALDATA const volatile float32 DoorLckCtl_Ts_C = 0.05F;/* Referenced by:
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

CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdFlg_C = false;/* Referenced by: '<S848>/Constant18' */
CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdVal_C = false;/* Referenced by: '<S848>/Constant19' */
CALDATA const volatile uint16 ESCLCtl_LckDelay_C = 4U;/* Referenced by: '<S848>/ESCLLck' */
CALDATA const volatile uint16 ESCLCtl_LckTimMax_C = 60U;/* Referenced by: '<S848>/ESCLLck' */
CALDATA const volatile uint16 ESCLCtl_UnlckDelay_C = 4U;/* Referenced by: '<S848>/ESCLUnlck' */
CALDATA const volatile uint16 ESCLCtl_UnlckTimMax_C = 60U;/* Referenced by: '<S848>/ESCLUnlck' */
CALDATA const volatile uint16 HornCtl_HornSwTimInvalid_C = 2U;/* Referenced by: '<S287>/Constant38' */
CALDATA const volatile uint16 HornCtl_HornSwTimValid_C = 2U;/* Referenced by: '<S287>/Constant37' */
CALDATA const volatile boolean HornCtl_J430HornDrvOvrdFlg_C = false;/* Referenced by: '<S240>/Constant18' */
CALDATA const volatile boolean HornCtl_J430HornDrvOvrdVal_C = false;/* Referenced by: '<S240>/Constant19' */
CALDATA const volatile uint16 HornCtl_TrunkWarnTim_C = 1500U;/* Referenced by: '<S292>/Chart' */
CALDATA const volatile float32 HornCtl_Ts_C = 0.02F;/* Referenced by: '<S287>/Constant39' */
CALDATA const volatile uint16 LampCtl_AutoLampDayDelayTim_C = 1000U;/* Referenced by: '<S320>/Constant6' */
CALDATA const volatile uint16 LampCtl_AutoLampNightDelayTim_C = 100U;/* Referenced by: '<S320>/Constant43' */
CALDATA const volatile uint16 LampCtl_AutoLampTimInValid_C = 0U;/* Referenced by: '<S351>/Constant63' */
CALDATA const volatile uint16 LampCtl_AutoLampTimValid_C = 0U;/* Referenced by: '<S351>/Constant9' */
CALDATA const volatile boolean LampCtl_AutoLampVal_C = false;/* Referenced by: '<S351>/Constant8' */
CALDATA const volatile uint16 LampCtl_BoxLampOpenTimMax_C = 30000U;/* Referenced by: '<S322>/Constant4' */
CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant3' */
CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant4' */
CALDATA const volatile boolean LampCtl_BrakeLightVal_C = false;/* Referenced by:
                                                                * '<S351>/Constant62'
                                                                * '<S351>/Constant74'
                                                                */
CALDATA const volatile uint16 LampCtl_BrakeSwInValid_C = 5U;/* Referenced by:
                                                             * '<S351>/Constant15'
                                                             * '<S351>/Constant71'
                                                             */
CALDATA const volatile uint16 LampCtl_BrakeSwTimValid_C = 5U;/* Referenced by:
                                                              * '<S351>/Constant14'
                                                              * '<S351>/Constant70'
                                                              */
CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant1' */
CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant2' */
CALDATA const volatile uint16 LampCtl_DayTimeVal_C = 1000U;/* Referenced by: '<S330>/Chart' */
CALDATA const volatile boolean LampCtl_DomeLampPwmDutyOvrdFlg_C = false;/* Referenced by: '<S241>/Constant22' */
CALDATA const volatile uint8 LampCtl_DomeLampPwmDutyOvrdVal_C = 0U;/* Referenced by: '<S241>/Constant21' */
CALDATA const volatile uint16 LampCtl_DoorOpenFLInValidTim_C = 6U;/* Referenced by: '<S374>/Constant4' */
CALDATA const volatile uint16 LampCtl_DoorOpenFLValidTim_C = 6U;/* Referenced by: '<S374>/Constant3' */
CALDATA const volatile uint16 LampCtl_DoorOpenFRInValidTim_C = 6U;/* Referenced by: '<S374>/Constant7' */
CALDATA const volatile uint16 LampCtl_DoorOpenFRValidTim_C = 6U;/* Referenced by: '<S374>/Constant6' */
CALDATA const volatile uint16 LampCtl_FlwrMeHomeTimValid_C = 25U;/* Referenced by: '<S567>/Constant43' */
CALDATA const volatile boolean LampCtl_FogLampFStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant14' */
CALDATA const volatile boolean LampCtl_FogLampFStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant13' */
CALDATA const volatile uint16 LampCtl_FogLampFTimInValid_C = 5U;/* Referenced by: '<S351>/Constant66' */
CALDATA const volatile uint16 LampCtl_FogLampFTimValid_C = 5U;/* Referenced by: '<S351>/Constant64' */
CALDATA const volatile boolean LampCtl_FogLampFVal_C = false;/* Referenced by: '<S351>/Constant69' */
CALDATA const volatile boolean LampCtl_FogLampRStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant12' */
CALDATA const volatile boolean LampCtl_FogLampRStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant11' */
CALDATA const volatile uint16 LampCtl_FogLampRTimInValid_C = 5U;/* Referenced by: '<S351>/Constant44' */
CALDATA const volatile uint16 LampCtl_FogLampRTimValid_C = 5U;/* Referenced by: '<S351>/Constant43' */
CALDATA const volatile boolean LampCtl_FogLampRVal_C = false;/* Referenced by: '<S351>/Constant56' */
CALDATA const volatile uint16 LampCtl_HazardLightTimInValid_C = 0U;/* Referenced by: '<S351>/Constant47' */
CALDATA const volatile uint16 LampCtl_HazardLightTimValid_C = 0U;/* Referenced by: '<S351>/Constant46' */
CALDATA const volatile boolean LampCtl_HazardLightVal_C = false;/* Referenced by: '<S351>/Constant60' */
CALDATA const volatile uint16 LampCtl_HiBeamShortToBatTimInValid_C = 500U;/* Referenced by: '<S327>/Constant29' */
CALDATA const volatile boolean LampCtl_HiBeamStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant20' */
CALDATA const volatile boolean LampCtl_HiBeamStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant17' */
CALDATA const volatile uint16 LampCtl_HiBeamTimInValid_C = 0U;/* Referenced by: '<S351>/Constant26' */
CALDATA const volatile uint16 LampCtl_HiBeamTimValid_C = 0U;/* Referenced by: '<S351>/Constant25' */
CALDATA const volatile boolean LampCtl_HiBeamVal_C = false;/* Referenced by: '<S351>/Constant11' */
CALDATA const volatile uint16 LampCtl_InportCalSwBit_C = 0U;/* Referenced by:
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
CALDATA const volatile boolean LampCtl_J408BackLampPWMOvrdFlg_C = false;/* Referenced by: '<S241>/Constant30' */
CALDATA const volatile uint8 LampCtl_J408BackLampPWMOvrdVal_C = 0U;/* Referenced by: '<S241>/Constant29' */
CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdFlg_C = false;/* Referenced by: '<S241>/Constant5' */
CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdVal_C = false;/* Referenced by: '<S241>/Constant6' */
CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdFlg_C = false;/* Referenced by: '<S241>/Constant7' */
CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdVal_C = false;/* Referenced by: '<S241>/Constant8' */
CALDATA const volatile boolean LampCtl_J449BoxLampOvrdFlg_C = false;/* Referenced by: '<S241>/Constant28' */
CALDATA const volatile boolean LampCtl_J449BoxLampOvrdVal_C = false;/* Referenced by: '<S241>/Constant27' */
CALDATA const volatile uint8 LampCtl_LOpenCnt_C = 3U;/* Referenced by: '<S463>/Constant17' */
CALDATA const volatile uint8 LampCtl_LShortCnt_C = 3U;/* Referenced by: '<S463>/Constant19' */
CALDATA const volatile uint16 LampCtl_LampDelayTim_C = 3000U;/* Referenced by: '<S329>/Constant6' */
CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimInValid_C = 500U;/* Referenced by: '<S331>/Constant29' */
CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimValid_C = 500U;/* Referenced by: '<S331>/Constant28' */
CALDATA const volatile boolean LampCtl_LowBeamStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant9' */
CALDATA const volatile boolean LampCtl_LowBeamStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant10' */
CALDATA const volatile uint16 LampCtl_LowBeamStaTimInValid_C = 0U;/* Referenced by: '<S331>/Constant5' */
CALDATA const volatile uint16 LampCtl_LowBeamStaTimValid_C = 0U;/* Referenced by: '<S331>/Constant4' */
CALDATA const volatile uint16 LampCtl_LowBeamTimInValid_C = 0U;/* Referenced by: '<S351>/Constant24' */
CALDATA const volatile uint16 LampCtl_LowBeamTimValid_C = 0U;/* Referenced by: '<S351>/Constant23' */
CALDATA const volatile boolean LampCtl_LowBeamVal_C = false;/* Referenced by: '<S351>/Constant10' */
CALDATA const volatile uint16 LampCtl_NightVal_C = 1000U;/* Referenced by: '<S330>/Chart' */
CALDATA const volatile uint16 LampCtl_OsUnlckDelayTim_C = 35U;/* Referenced by: '<S572>/Constant3' */
CALDATA const volatile uint16 LampCtl_PassLightTimInValid_C = 0U;/* Referenced by: '<S351>/Constant29' */
CALDATA const volatile uint16 LampCtl_PassLightTimValid_C = 0U;/* Referenced by: '<S351>/Constant28' */
CALDATA const volatile boolean LampCtl_PassLightVal_C = false;/* Referenced by: '<S351>/Constant2' */
CALDATA const volatile boolean LampCtl_PosLampStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant18' */
CALDATA const volatile boolean LampCtl_PosLampStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant19' */
CALDATA const volatile uint16 LampCtl_PosLampStaTimInValid_C = 5U;/* Referenced by: '<S349>/Constant4' */
CALDATA const volatile uint16 LampCtl_PosLampStaTimValid_C = 5U;/* Referenced by: '<S349>/Constant2' */
CALDATA const volatile uint16 LampCtl_PosLampTimInValid_C = 0U;/* Referenced by: '<S351>/Constant20' */
CALDATA const volatile uint16 LampCtl_PosLampTimValid_C = 0U;/* Referenced by: '<S351>/Constant19' */
CALDATA const volatile boolean LampCtl_PosLampVal_C = false;/* Referenced by: '<S351>/Constant50' */
CALDATA const volatile uint8 LampCtl_ROpenCnt_C = 3U;/* Referenced by: '<S463>/Constant8' */
CALDATA const volatile uint8 LampCtl_RShortCnt_C = 3U;/* Referenced by: '<S463>/Constant16' */
CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant16' */
CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant15' */
CALDATA const volatile uint16 LampCtl_TrunkWarnTim_C = 1500U;/* Referenced by: '<S461>/Chart' */
CALDATA const volatile float32 LampCtl_Ts_C = 0.02F;/* Referenced by:
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
CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimInValid_C = 10U;/* Referenced by: '<S463>/Constant44' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimValid_C = 10U;/* Referenced by: '<S463>/Constant43' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimInValid_C = 10U;/* Referenced by: '<S463>/Constant10' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimValid_C = 10U;/* Referenced by: '<S463>/Constant9' */
CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant25' */
CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant26' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLTimInValid_C = 0U;/* Referenced by: '<S351>/Constant32' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLTimValid_C = 70U;/* Referenced by: '<S351>/Constant31' */
CALDATA const volatile boolean LampCtl_TurnIndcrLVal_C = false;/* Referenced by: '<S351>/Constant54' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimInValid_C = 0U;/* Referenced by: '<S351>/Constant35' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimValid_C = 0U;/* Referenced by: '<S351>/Constant34' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimInValid_C = 0U;/* Referenced by: '<S351>/Constant41' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimValid_C = 0U;/* Referenced by: '<S351>/Constant40' */
CALDATA const volatile uint16 LampCtl_TurnIndcrOpenCur_C = 30U;/* Referenced by:
                                                                * '<S463>/Constant11'
                                                                * '<S463>/Constant21'
                                                                */
CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimInValid_C = 10U;/* Referenced by: '<S463>/Constant3' */
CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimValid_C = 10U;/* Referenced by: '<S463>/Constant2' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimInValid_C = 10U;/* Referenced by: '<S463>/Constant12' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimValid_C = 10U;/* Referenced by: '<S463>/Constant14' */
CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant23' */
CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant24' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRTimInValid_C = 0U;/* Referenced by: '<S351>/Constant38' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRTimValid_C = 70U;/* Referenced by: '<S351>/Constant37' */
CALDATA const volatile boolean LampCtl_TurnIndcrRVal_C = false;/* Referenced by: '<S351>/Constant5' */
CALDATA const volatile uint16 LampCtl_TurnIndcrShortCur_C = 6000U;/* Referenced by:
                                                                   * '<S463>/Constant20'
                                                                   * '<S463>/Constant4'
                                                                   */
CALDATA const volatile uint16 LampCtl_WelcomeLampTimMax_C = 3000U;/* Referenced by: '<S571>/Constant6' */
CALDATA const volatile uint16 PDUCtl_EmerPwrOffTimInValid_C = 100U;/* Referenced by: '<S867>/Constant20' */
CALDATA const volatile uint16 PDUCtl_EmerPwrOffTimValid_C = 500U;/* Referenced by: '<S867>/Constant19' */
CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdFlg_C = false;/* Referenced by: '<S644>/Constant18' */
CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdVal_C = false;/* Referenced by: '<S644>/Constant19' */
CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdFlg_C = false;/* Referenced by: '<S644>/Constant1' */
CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdVal_C = false;/* Referenced by: '<S644>/Constant2' */
CALDATA const volatile boolean PDUCtl_KeyValidOvrdFlg_C = false;/* Referenced by:
                                                                 * '<S868>/Constant12'
                                                                 * '<S868>/Constant9'
                                                                 */
CALDATA const volatile boolean PDUCtl_KeyValidOvrdVal_C = false;/* Referenced by:
                                                                 * '<S868>/Constant10'
                                                                 * '<S868>/Constant11'
                                                                 */
CALDATA const volatile uint16 PDUCtl_OpenDoorPwrOnTimValid = 6000U;/* Referenced by: '<S868>/Constant6' */
CALDATA const volatile uint16 PDUCtl_PwrOnPSTimValid_C = 40U;/* Referenced by: '<S868>/Constant3' */
CALDATA const volatile uint16 PDUCtl_RemtPasvBrkSwTimValid_C = 40U;/* Referenced by: '<S867>/Constant33' */
CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffH_C = 0U;/* Referenced by: '<S867>/Constant25' */
CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffM_C = 30U;/* Referenced by: '<S867>/Constant26' */
CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffS_C = 0U;/* Referenced by: '<S867>/Constant27' */
CALDATA const volatile uint16 PDUCtl_StartReqOverTimValid_C = 200U;/* Referenced by: '<S871>/Constant5' */
CALDATA const volatile uint16 PDUCtl_StartReqTimValid_C = 10U;/* Referenced by: '<S871>/Constant4' */
CALDATA const volatile uint8 PDUCtl_TimOutPwrOffH_C = 1U;/* Referenced by: '<S867>/Constant4' */
CALDATA const volatile uint8 PDUCtl_TimOutPwrOffM_C = 0U;/* Referenced by: '<S867>/Constant5' */
CALDATA const volatile uint8 PDUCtl_TimOutPwrOffS_C = 0U;/* Referenced by: '<S867>/Constant6' */
CALDATA const volatile float32 PDUCtl_Ts_C = 0.05F;/* Referenced by:
                                                    * '<S867>/Constant21'
                                                    * '<S867>/Constant28'
                                                    * '<S867>/Constant7'
                                                    * '<S869>/Constant13'
                                                    * '<S869>/Constant6'
                                                    * '<S869>/Constant8'
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
CALDATA const volatile uint16 SeatCtl_NTCOpenInValidTim_C = 100U;/* Referenced by: '<S129>/Constant16' */
CALDATA const volatile float32 SeatCtl_NTCOpenResis_C = 380000.0F;/* Referenced by: '<S129>/Constant11' */
CALDATA const volatile uint16 SeatCtl_NTCOpenValidTim_C = 100U;/* Referenced by: '<S129>/Constant15' */
CALDATA const volatile uint16 SeatCtl_NTCShortInValidTim_C = 100U;/* Referenced by: '<S129>/Constant13' */
CALDATA const volatile float32 SeatCtl_NTCShortResis_C = 500.0F;/* Referenced by: '<S129>/Constant' */
CALDATA const volatile uint16 SeatCtl_NTCShortValidTim_C = 100U;/* Referenced by: '<S129>/Constant12' */
CALDATA const volatile float32 SeatCtl_Ts_C = 0.1F;/* Referenced by:
                                                    * '<S129>/Constant14'
                                                    * '<S129>/Constant17'
                                                    */
CALDATA const volatile uint8 SteerWhlCtl_DiffTemp_C = 5U;/* Referenced by: '<S137>/HeatCtl' */
CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdFlg_C = false;/* Referenced by: '<S137>/Constant18' */
CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdVal_C = false;/* Referenced by: '<S137>/Constant19' */
CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_X[18] = { 3546.0F,
  4172.0F, 4924.0F, 5838.0F, 6954.0F, 8318.0F, 10000.0F, 12090.0F, 14700.0F,
  17970.0F, 22100.0F, 27350.0F, 34080.0F, 42740.0F, 53970.0F, 68610.0F, 87780.0F,
  113100.0F } ;                  /* Referenced by: '<S137>/1-D Lookup Table1' */

CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_Y[18] = { 55.0F,
  50.0F, 45.0F, 40.0F, 35.0F, 30.0F, 25.0F, 20.0F, 15.0F, 10.0F, 5.0F, 0.0F,
  -5.0F, -10.0F, -15.0F, -20.0F, -25.0F, -30.0F } ;
                                 /* Referenced by: '<S137>/1-D Lookup Table1' */

CALDATA const volatile uint8 SteerWhlCtl_TrgtTemp_C = 35U;/* Referenced by: '<S137>/HeatCtl' */
CALDATA const volatile uint16 WakeUpCtl_CANSleepDelayTim_C = 300U;/* Referenced by: '<S910>/Constant22' */
CALDATA const volatile uint16 WakeUpCtl_LocalSleepDelayTim_C = 200U;/* Referenced by: '<S911>/Constant27' */
CALDATA const volatile uint16 WakeUpCtl_WinCtlDelayTim_C = 1200U;/* Referenced by: '<S910>/Constant3' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMaxResis_C = 200U;/* Referenced by: '<S150>/Constant51' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMinResis_C = 0U;/* Referenced by: '<S150>/Constant50' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimInValid_C = 10U;/* Referenced by: '<S150>/Constant10' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimValid_C = 10U;/* Referenced by: '<S150>/Constant9' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMaxResis_C = 2500U;/* Referenced by: '<S150>/Constant49' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMinResis_C = 2000U;/* Referenced by: '<S150>/Constant48' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimInValid_C = 10U;/* Referenced by: '<S150>/Constant7' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimValid_C = 10U;/* Referenced by: '<S150>/Constant6' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinSwResis_C = 0U;/* Referenced by: '<S150>/Constant5' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMaxResis_C = 1500U;/* Referenced by: '<S150>/Constant47' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMinResis_C = 1000U;/* Referenced by: '<S150>/Constant46' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimInValid_C = 10U;/* Referenced by: '<S150>/Constant3' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimValid_C = 10U;/* Referenced by: '<S150>/Constant2' */
CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMaxResis_C = 200U;/* Referenced by: '<S150>/Constant36' */
CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMinResis_C = 0U;/* Referenced by: '<S150>/Constant35' */
CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimInValid_C = 10U;/* Referenced by: '<S150>/Constant24' */
CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimValid_C = 10U;/* Referenced by: '<S150>/Constant23' */
CALDATA const volatile uint16 WinCtl_DrvWinDnMaxResis_C = 2500U;/* Referenced by: '<S150>/Constant31' */
CALDATA const volatile uint16 WinCtl_DrvWinDnMinResis_C = 2000U;/* Referenced by: '<S150>/Constant26' */
CALDATA const volatile uint16 WinCtl_DrvWinDnTimInValid_C = 10U;/* Referenced by: '<S150>/Constant18' */
CALDATA const volatile uint16 WinCtl_DrvWinDnTimValid_C = 10U;/* Referenced by: '<S150>/Constant17' */
CALDATA const volatile uint16 WinCtl_DrvWinSwResis_C = 0U;/* Referenced by: '<S150>/Constant15' */
CALDATA const volatile uint16 WinCtl_DrvWinUpMaxResis_C = 1500U;/* Referenced by: '<S150>/Constant22' */
CALDATA const volatile uint16 WinCtl_DrvWinUpMinResis_C = 1000U;/* Referenced by: '<S150>/Constant20' */
CALDATA const volatile uint16 WinCtl_DrvWinUpTimInValid_C = 10U;/* Referenced by: '<S150>/Constant13' */
CALDATA const volatile uint16 WinCtl_DrvWinUpTimValid_C = 10U;/* Referenced by: '<S150>/Constant12' */
CALDATA const volatile uint16 WinCtl_InportCalSwBit_C = 0U;/* Referenced by:
                                                            * '<S150>/Constant1'
                                                            * '<S150>/Constant11'
                                                            * '<S150>/Constant21'
                                                            */
CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdFlg_C = false;/* Referenced by: '<S10>/Constant18' */
CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdVal_C = false;/* Referenced by: '<S10>/Constant19' */
CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdFlg_C = false;/* Referenced by: '<S10>/Constant1' */
CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdVal_C = false;/* Referenced by: '<S10>/Constant2' */
CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdFlg_C = false;/* Referenced by: '<S10>/Constant3' */
CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdVal_C = false;/* Referenced by: '<S10>/Constant4' */
CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdFlg_C = false;/* Referenced by: '<S10>/Constant5' */
CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdVal_C = false;/* Referenced by: '<S10>/Constant6' */
CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMaxResis_C = 200U;/* Referenced by: '<S150>/Constant45' */
CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMinResis_C = 0U;/* Referenced by: '<S150>/Constant44' */
CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimInValid_C = 10U;/* Referenced by: '<S150>/Constant38' */
CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimValid_C = 10U;/* Referenced by: '<S150>/Constant37' */
CALDATA const volatile uint16 WinCtl_PsgWinDnMaxResis_C = 2500U;/* Referenced by: '<S150>/Constant43' */
CALDATA const volatile uint16 WinCtl_PsgWinDnMinResis_C = 2000U;/* Referenced by: '<S150>/Constant42' */
CALDATA const volatile uint16 WinCtl_PsgWinDnTimInValid_C = 10U;/* Referenced by: '<S150>/Constant33' */
CALDATA const volatile uint16 WinCtl_PsgWinDnTimValid_C = 10U;/* Referenced by: '<S150>/Constant32' */
CALDATA const volatile uint16 WinCtl_PsgWinSwResis_C = 0U;/* Referenced by: '<S150>/Constant30' */
CALDATA const volatile uint16 WinCtl_PsgWinUpMaxResis_C = 1500U;/* Referenced by: '<S150>/Constant41' */
CALDATA const volatile uint16 WinCtl_PsgWinUpMinResis_C = 1000U;/* Referenced by: '<S150>/Constant40' */
CALDATA const volatile uint16 WinCtl_PsgWinUpTimInValid_C = 10U;/* Referenced by: '<S150>/Constant28' */
CALDATA const volatile uint16 WinCtl_PsgWinUpTimValid_C = 10U;/* Referenced by: '<S150>/Constant27' */
CALDATA const volatile uint16 WinCtl_PwrOffWinValidTimMax_C = 600U;/* Referenced by: '<S152>/Constant20' */
CALDATA const volatile float32 WinCtl_Ts_C = 0.1F;/* Referenced by:
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
CALDATA const volatile uint16 WinCtl_WinMotorCurMax_C = 18000U;/* Referenced by:
                                                                * '<S152>/Constant37'
                                                                * '<S152>/Constant48'
                                                                */
CALDATA const volatile uint16 WinCtl_WinMotorCurTimInValid_C = 10U;/* Referenced by:
                                                                    * '<S152>/Constant35'
                                                                    * '<S152>/Constant44'
                                                                    */
CALDATA const volatile uint16 WinCtl_WinMotorCurTimValid_C = 150U;/* Referenced by:
                                                                   * '<S152>/Constant11'
                                                                   * '<S152>/Constant34'
                                                                   */
CALDATA const volatile uint16 WinCtl_WinProtNum_C = 30U;/* Referenced by:
                                                         * '<S151>/Constant15'
                                                         * '<S151>/Constant2'
                                                         * '<S151>/Constant6'
                                                         * '<S151>/Constant9'
                                                         */
CALDATA const volatile uint16 WinCtl_WinProtTim_C = 100U;/* Referenced by:
                                                          * '<S151>/Constant1'
                                                          * '<S151>/Constant14'
                                                          * '<S151>/Constant5'
                                                          * '<S151>/Constant8'
                                                          */
CALDATA const volatile uint16 WinCtl_WinRunTimMax_C = 120U;/* Referenced by:
                                                            * '<S152>/Constant40'
                                                            * '<S152>/Constant8'
                                                            */
CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdFlg_C = false;/* Referenced by: '<S242>/Constant3' */
CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdVal_C = false;/* Referenced by: '<S242>/Constant4' */
CALDATA const volatile uint16 WiperCtl_HiSpdTimInValid_C = 10U;/* Referenced by: '<S588>/Constant22' */
CALDATA const volatile uint16 WiperCtl_HiSpdTimValid_C = 10U;/* Referenced by: '<S588>/Constant21' */
CALDATA const volatile uint16 WiperCtl_InportCalSwBit_C = 0U;/* Referenced by:
                                                              * '<S588>/Constant28'
                                                              * '<S588>/Constant35'
                                                              * '<S588>/Constant59'
                                                              */
CALDATA const volatile uint16 WiperCtl_InrLvl1Tim_C = 100U;/* Referenced by: '<S592>/Constant1' */
CALDATA const volatile uint16 WiperCtl_InrLvl2Tim_C = 200U;/* Referenced by: '<S592>/Constant2' */
CALDATA const volatile uint16 WiperCtl_InrLvl3Tim_C = 400U;/* Referenced by:
                                                            * '<S592>/Constant3'
                                                            * '<S592>/Constant8'
                                                            */
CALDATA const volatile uint16 WiperCtl_InrLvl4Tim_C = 500U;/* Referenced by: '<S592>/Constant4' */
CALDATA const volatile uint16 WiperCtl_InrLvl5Tim_C = 650U;/* Referenced by: '<S592>/Constant5' */
CALDATA const volatile uint16 WiperCtl_InrLvl6Tim_C = 500U;/* Referenced by: '<S592>/Constant6' */
CALDATA const volatile uint16 WiperCtl_InrLvl7Tim_C = 300U;/* Referenced by: '<S592>/Constant7' */
CALDATA const volatile uint16 WiperCtl_InrTimInValid_C = 10U;/* Referenced by: '<S588>/Constant9' */
CALDATA const volatile uint16 WiperCtl_InrTimValid_C = 10U;/* Referenced by: '<S588>/Constant8' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimDef_C = 250U;/* Referenced by: '<S584>/Constant1' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimOk_C = 5U;/* Referenced by: '<S584>/Constant2' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkDef_C = 100U;/* Referenced by: '<S584>/Constant4' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkOk_C = 5U;/* Referenced by: '<S584>/Constant5' */
CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdFlg_C = false;/* Referenced by: '<S242>/Constant1' */
CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdVal_C = false;/* Referenced by: '<S242>/Constant2' */
CALDATA const volatile uint16 WiperCtl_LowSpdTimInValid_C = 10U;/* Referenced by: '<S588>/Constant17' */
CALDATA const volatile uint16 WiperCtl_LowSpdTimValid_C = 10U;/* Referenced by: '<S588>/Constant16' */
CALDATA const volatile uint16 WiperCtl_MaintWiperRunTim_C = 25U;/* Referenced by: '<S590>/Chart' */
CALDATA const volatile uint16 WiperCtl_MistTimInValid_C = 10U;/* Referenced by: '<S588>/Constant47' */
CALDATA const volatile uint16 WiperCtl_MistTimValid_C = 10U;/* Referenced by: '<S588>/Constant46' */
CALDATA const volatile uint16 WiperCtl_OffTimInValid_C = 10U;/* Referenced by: '<S588>/Constant4' */
CALDATA const volatile uint16 WiperCtl_OffTimValid_C = 10U;/* Referenced by: '<S588>/Constant3' */
CALDATA const volatile float32 WiperCtl_Ts_C = 0.02F;/* Referenced by:
                                                      * '<S588>/Constant10'
                                                      * '<S588>/Constant11'
                                                      * '<S588>/Constant18'
                                                      * '<S588>/Constant27'
                                                      * '<S588>/Constant34'
                                                      * '<S588>/Constant49'
                                                      * '<S588>/Constant5'
                                                      * '<S589>/Constant34'
                                                      */
CALDATA const volatile uint8 WiperCtl_WashAfterNum_C = 4U;/* Referenced by: '<S590>/Chart' */
CALDATA const volatile uint16 WiperCtl_WashAfterTim_C = 150U;/* Referenced by: '<S590>/Chart' */
CALDATA const volatile uint16 WiperCtl_WashMaxTim_C = 600U;/* Referenced by: '<S589>/Constant' */
CALDATA const volatile uint16 WiperCtl_WashMinTim_C = 60U;/* Referenced by: '<S589>/Constant3' */
CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdFlg_C = false;/* Referenced by: '<S242>/Constant18' */
CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdVal_C = false;/* Referenced by: '<S242>/Constant19' */
CALDATA const volatile uint16 WiperCtl_WashTimInValid_C = 10U;/* Referenced by: '<S588>/Constant26' */
CALDATA const volatile uint16 WiperCtl_WashTimValid_C = 60U;/* Referenced by: '<S588>/Constant25' */
CALDATA const volatile boolean WiperCtl_WashVal_C = true;/* Referenced by: '<S588>/Constant29' */

/* 低有效 */
CALDATA const volatile uint16 WiperCtl_WiperParkPosTimValid_C = 2U;/* Referenced by: '<S588>/Constant32' */
CALDATA const volatile boolean WiperCtl_WiperParkPosVal_C = true;/* Referenced by: '<S588>/Constant36' */

/* 低有效 */
CALDATA const volatile uint16 WiperCtl_WiperPosTimInValid_C = 2U;/* Referenced by: '<S588>/Constant33' */
CALDATA const volatile uint8 WiperCtl_WiperSwVal_C = 0U;/* Referenced by: '<S588>/Constant60' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
