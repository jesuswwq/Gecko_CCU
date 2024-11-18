/*
 * File: calPrmsBcm.c
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

#include "calPrmsBcm.h"
#include "AppSwcBcm.h"

/* Exported data definition */

/*Group of variables*/
#include "XcpTest_types.h"

/* Definition for custom storage class: CalParam */
CALDATA const volatile uint16 AlmSysCtl_AlrmTimLimit_C = 600U;/* Referenced by: '<S636>/AlmSysLogic' */
CALDATA const volatile uint16 BatSaveCtl_DlyTim_C = 12000U;/* Referenced by: '<S664>/Constant2' */
CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdFlg_C = false;/* Referenced by: '<S637>/Constant18' */
CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdVal_C = false;/* Referenced by: '<S637>/Constant19' */
CALDATA const volatile uint16 BatSaveCtl_LckDlyTim_C = 40U;/* Referenced by: '<S664>/Constant7' */
CALDATA const volatile uint16 DoorLckCtl_AntiLckProtTim_C = 20U;/* Referenced by: '<S680>/Constant' */
CALDATA const volatile uint16 DoorLckCtl_AutoLckDelayTim_C = 1200U;/* Referenced by: '<S727>/Constant7' */
CALDATA const volatile uint16 DoorLckCtl_CntSubTim_C = 26U;/* Referenced by: '<S686>/Constant' */
CALDATA const volatile uint16 DoorLckCtl_CrshPwrOnTimInValid_C = 10U;/* Referenced by: '<S709>/Constant4' */
CALDATA const volatile uint16 DoorLckCtl_CrshPwrOnTimValid_C = 400U;/* Referenced by: '<S709>/Constant3' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimInValid_C = 10U;/* Referenced by: '<S677>/Constant2' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimValid_C = 10U;/* Referenced by: '<S677>/Constant1' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarFLVal_C = false;/* Referenced by: '<S677>/Constant4' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimInValid_C = 10U;/* Referenced by: '<S677>/Constant7' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimValid_C = 10U;/* Referenced by: '<S677>/Constant6' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarFRVal_C = false;/* Referenced by: '<S677>/Constant9' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimInvalid_C = 10U;/* Referenced by: '<S677>/Constant35' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimValid_C = 10U;/* Referenced by: '<S677>/Constant34' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarRLVal_C = false;/* Referenced by: '<S677>/Constant18' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimInvalid_C = 10U;/* Referenced by: '<S677>/Constant38' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimValid_C = 10U;/* Referenced by: '<S677>/Constant37' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarRRVal_C = false;/* Referenced by: '<S677>/Constant20' */
CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimInValid_C = 10U;/* Referenced by: '<S677>/Constant47' */
CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimValid_C = 10U;/* Referenced by: '<S677>/Constant46' */
CALDATA const volatile boolean DoorLckCtl_DriverDoorLckVal_C = false;/* Referenced by: '<S677>/Constant60' */
CALDATA const volatile uint16 DoorLckCtl_DrvPETimInvalid_C = 100U;/* Referenced by: '<S677>/Constant26' */
CALDATA const volatile uint16 DoorLckCtl_DrvPETimValid_C = 5U;/* Referenced by: '<S677>/Constant25' */
CALDATA const volatile boolean DoorLckCtl_DrvPEVal_C = false;/* Referenced by: '<S677>/Constant12' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisMin_C = 55U;/* Referenced by: '<S677>/Constant67' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisVal_C = 0U;/* Referenced by: '<S677>/Constant63' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimInValid_C = 10U;/* Referenced by: '<S677>/Constant65' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimValid_C = 10U;/* Referenced by: '<S677>/Constant64' */
CALDATA const volatile uint16 DoorLckCtl_DrvTim_C = 200U;/* Referenced by: '<S639>/DoorDrv' */
CALDATA const volatile uint8 DoorLckCtl_EEIlluminatedEntrySys_C = 0U;/* Referenced by: '<S677>/Constant74' */
CALDATA const volatile uint8 DoorLckCtl_EEKeyEntry_C = 0U;/* Referenced by: '<S677>/Constant72' */
CALDATA const volatile uint8 DoorLckCtl_IllmndSts_C = 0U;/* Referenced by: '<S677>/Constant76' */
CALDATA const volatile uint16 DoorLckCtl_InportCalSwBit_C = 0U;/* Referenced by:
                                                                * '<S677>/Constant10'
                                                                * '<S677>/Constant11'
                                                                * '<S677>/Constant13'
                                                                * '<S677>/Constant15'
                                                                * '<S677>/Constant17'
                                                                * '<S677>/Constant19'
                                                                * '<S677>/Constant21'
                                                                * '<S677>/Constant5'
                                                                * '<S677>/Constant59'
                                                                * '<S677>/Constant62'
                                                                * '<S677>/Constant71'
                                                                * '<S677>/Constant73'
                                                                * '<S677>/Constant75'
                                                                */
CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdFlg_C = false;/* Referenced by: '<S639>/Constant3' */
CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdVal_C = false;/* Referenced by: '<S639>/Constant4' */
CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdFlg_C = false;/* Referenced by: '<S639>/Constant1' */
CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdVal_C = false;/* Referenced by: '<S639>/Constant2' */
CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdFlg_C = false;/* Referenced by: '<S639>/Constant18' */
CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdVal_C = false;/* Referenced by: '<S639>/Constant19' */
CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMaxTim_C = 25U;/* Referenced by: '<S639>/DoorDrv' */
CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMinTim_C = 10U;/* Referenced by: '<S639>/DoorDrv' */
CALDATA const volatile uint16 DoorLckCtl_MotorProtTimMax_C = 400U;/* Referenced by: '<S686>/Constant2' */
CALDATA const volatile uint8 DoorLckCtl_MotorWorkMax_C = 10U;/* Referenced by: '<S686>/Constant1' */
CALDATA const volatile uint16 DoorLckCtl_PEProtCnt_C = 2U;/* Referenced by: '<S689>/Constant3' */
CALDATA const volatile uint16 DoorLckCtl_PEProtIntvlTim_C = 20U;/* Referenced by: '<S689>/Constant2' */
CALDATA const volatile uint16 DoorLckCtl_PsgPETimInvalid_C = 100U;/* Referenced by:
                                                                   * '<S677>/Constant29'
                                                                   * '<S677>/Constant32'
                                                                   */
CALDATA const volatile uint16 DoorLckCtl_PsgPETimValid_C = 5U;/* Referenced by:
                                                               * '<S677>/Constant28'
                                                               * '<S677>/Constant31'
                                                               */
CALDATA const volatile boolean DoorLckCtl_PsgPEVal_C = false;/* Referenced by: '<S677>/Constant14' */
CALDATA const volatile uint16 DoorLckCtl_SpdLckTimInValid_C = 50U;/* Referenced by:
                                                                   * '<S697>/Constant10'
                                                                   * '<S697>/Constant3'
                                                                   */
CALDATA const volatile uint16 DoorLckCtl_SpdLckTimValid_C = 200U;/* Referenced by:
                                                                  * '<S697>/Constant2'
                                                                  * '<S697>/Constant9'
                                                                  */
CALDATA const volatile uint8 DoorLckCtl_SpdLck_C = 20U;/* Referenced by: '<S697>/Constant' */
CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimInvalid_C = 10U;/* Referenced by: '<S677>/Constant41' */
CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimValid_C = 10U;/* Referenced by: '<S677>/Constant40' */
CALDATA const volatile boolean DoorLckCtl_TrunkAjarVal_C = false;/* Referenced by: '<S677>/Constant22' */
CALDATA const volatile uint16 DoorLckCtl_TrunkAutoLckTim_C = 1200U;/* Referenced by: '<S732>/Constant1' */
CALDATA const volatile boolean DoorLckCtl_TrunkSwVal_C = false;/* Referenced by: '<S677>/Constant16' */
CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimInvalid_C = 10U;/* Referenced by: '<S758>/Constant3' */
CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimValid_C = 150U;/* Referenced by: '<S758>/Constant2' */
CALDATA const volatile float32 DoorLckCtl_Ts_C = 0.05F;/* Referenced by:
                                                        * '<S677>/Constant27'
                                                        * '<S677>/Constant3'
                                                        * '<S677>/Constant30'
                                                        * '<S677>/Constant33'
                                                        * '<S677>/Constant36'
                                                        * '<S677>/Constant39'
                                                        * '<S677>/Constant42'
                                                        * '<S677>/Constant49'
                                                        * '<S677>/Constant66'
                                                        * '<S677>/Constant8'
                                                        * '<S697>/Constant11'
                                                        * '<S697>/Constant49'
                                                        * '<S709>/Constant6'
                                                        * '<S728>/Constant42'
                                                        * '<S754>/Constant42'
                                                        * '<S758>/Constant4'
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

CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdFlg_C = false;/* Referenced by: '<S847>/Constant18' */
CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdVal_C = false;/* Referenced by: '<S847>/Constant19' */
CALDATA const volatile uint16 ESCLCtl_LckDelay_C = 4U;/* Referenced by: '<S847>/ESCLLck' */
CALDATA const volatile uint16 ESCLCtl_LckTimMax_C = 60U;/* Referenced by: '<S847>/ESCLLck' */
CALDATA const volatile uint16 ESCLCtl_UnlckDelay_C = 4U;/* Referenced by: '<S847>/ESCLUnlck' */
CALDATA const volatile uint16 ESCLCtl_UnlckTimMax_C = 60U;/* Referenced by: '<S847>/ESCLUnlck' */
CALDATA const volatile uint16 HornCtl_HornSwTimInvalid_C = 2U;/* Referenced by: '<S287>/Constant38' */
CALDATA const volatile uint16 HornCtl_HornSwTimValid_C = 2U;/* Referenced by: '<S287>/Constant37' */
CALDATA const volatile boolean HornCtl_J430HornDrvOvrdFlg_C = false;/* Referenced by: '<S240>/Constant18' */
CALDATA const volatile boolean HornCtl_J430HornDrvOvrdVal_C = false;/* Referenced by: '<S240>/Constant19' */
CALDATA const volatile uint16 HornCtl_TrunkWarnTim_C = 1500U;/* Referenced by: '<S292>/Chart' */
CALDATA const volatile float32 HornCtl_Ts_C = 0.02F;/* Referenced by: '<S287>/Constant39' */
CALDATA const volatile uint16 LampCtl_AutoLampDayDelayTim_C = 1000U;/* Referenced by: '<S320>/Constant6' */
CALDATA const volatile uint16 LampCtl_AutoLampNightDelayTim_C = 100U;/* Referenced by: '<S320>/Constant43' */
CALDATA const volatile uint16 LampCtl_AutoLampTimInValid_C = 0U;/* Referenced by: '<S350>/Constant63' */
CALDATA const volatile uint16 LampCtl_AutoLampTimValid_C = 0U;/* Referenced by: '<S350>/Constant9' */
CALDATA const volatile boolean LampCtl_AutoLampVal_C = false;/* Referenced by: '<S350>/Constant8' */
CALDATA const volatile uint16 LampCtl_BoxLampOpenTimMax_C = 30000U;/* Referenced by: '<S322>/Constant4' */
CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant3' */
CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant4' */
CALDATA const volatile boolean LampCtl_BrakeLightVal_C = false;/* Referenced by:
                                                                * '<S350>/Constant62'
                                                                * '<S350>/Constant74'
                                                                */
CALDATA const volatile uint16 LampCtl_BrakeSwInValid_C = 5U;/* Referenced by:
                                                             * '<S350>/Constant15'
                                                             * '<S350>/Constant71'
                                                             */
CALDATA const volatile uint16 LampCtl_BrakeSwTimValid_C = 5U;/* Referenced by:
                                                              * '<S350>/Constant14'
                                                              * '<S350>/Constant70'
                                                              */
CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant1' */
CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant2' */
CALDATA const volatile uint16 LampCtl_DayTimeVal_C = 1000U;/* Referenced by: '<S330>/Chart' */
CALDATA const volatile boolean LampCtl_DomeLampPwmDutyOvrdFlg_C = false;/* Referenced by: '<S241>/Constant22' */
CALDATA const volatile uint8 LampCtl_DomeLampPwmDutyOvrdVal_C = 0U;/* Referenced by: '<S241>/Constant21' */
CALDATA const volatile uint16 LampCtl_DoorOpenFLInValidTim_C = 6U;/* Referenced by: '<S373>/Constant4' */
CALDATA const volatile uint16 LampCtl_DoorOpenFLValidTim_C = 6U;/* Referenced by: '<S373>/Constant3' */
CALDATA const volatile uint16 LampCtl_DoorOpenFRInValidTim_C = 6U;/* Referenced by: '<S373>/Constant7' */
CALDATA const volatile uint16 LampCtl_DoorOpenFRValidTim_C = 6U;/* Referenced by: '<S373>/Constant6' */
CALDATA const volatile uint16 LampCtl_FlwrMeHomeTimValid_C = 25U;/* Referenced by: '<S566>/Constant43' */
CALDATA const volatile boolean LampCtl_FogLampFStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant14' */
CALDATA const volatile boolean LampCtl_FogLampFStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant13' */
CALDATA const volatile uint16 LampCtl_FogLampFTimInValid_C = 5U;/* Referenced by: '<S350>/Constant66' */
CALDATA const volatile uint16 LampCtl_FogLampFTimValid_C = 5U;/* Referenced by: '<S350>/Constant64' */
CALDATA const volatile boolean LampCtl_FogLampFVal_C = false;/* Referenced by: '<S350>/Constant69' */
CALDATA const volatile boolean LampCtl_FogLampRStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant12' */
CALDATA const volatile boolean LampCtl_FogLampRStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant11' */
CALDATA const volatile uint16 LampCtl_FogLampRTimInValid_C = 5U;/* Referenced by: '<S350>/Constant44' */
CALDATA const volatile uint16 LampCtl_FogLampRTimValid_C = 5U;/* Referenced by: '<S350>/Constant43' */
CALDATA const volatile boolean LampCtl_FogLampRVal_C = false;/* Referenced by: '<S350>/Constant56' */
CALDATA const volatile uint16 LampCtl_HazardLightTimInValid_C = 0U;/* Referenced by: '<S350>/Constant47' */
CALDATA const volatile uint16 LampCtl_HazardLightTimValid_C = 0U;/* Referenced by: '<S350>/Constant46' */
CALDATA const volatile boolean LampCtl_HazardLightVal_C = false;/* Referenced by: '<S350>/Constant60' */
CALDATA const volatile uint16 LampCtl_HiBeamShortToBatTimInValid_C = 500U;/* Referenced by: '<S327>/Constant29' */
CALDATA const volatile boolean LampCtl_HiBeamStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant20' */
CALDATA const volatile boolean LampCtl_HiBeamStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant17' */
CALDATA const volatile uint16 LampCtl_HiBeamTimInValid_C = 0U;/* Referenced by: '<S350>/Constant26' */
CALDATA const volatile uint16 LampCtl_HiBeamTimValid_C = 0U;/* Referenced by: '<S350>/Constant25' */
CALDATA const volatile boolean LampCtl_HiBeamVal_C = false;/* Referenced by: '<S350>/Constant11' */
CALDATA const volatile uint16 LampCtl_InportCalSwBit_C = 0U;/* Referenced by:
                                                             * '<S350>/Constant1'
                                                             * '<S350>/Constant12'
                                                             * '<S350>/Constant3'
                                                             * '<S350>/Constant4'
                                                             * '<S350>/Constant48'
                                                             * '<S350>/Constant53'
                                                             * '<S350>/Constant55'
                                                             * '<S350>/Constant59'
                                                             * '<S350>/Constant6'
                                                             * '<S350>/Constant61'
                                                             * '<S350>/Constant68'
                                                             * '<S350>/Constant73'
                                                             */
CALDATA const volatile boolean LampCtl_J408BackLampPWMOvrdFlg_C = false;/* Referenced by: '<S241>/Constant30' */
CALDATA const volatile uint8 LampCtl_J408BackLampPWMOvrdVal_C = 0U;/* Referenced by: '<S241>/Constant29' */
CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdFlg_C = false;/* Referenced by: '<S241>/Constant5' */
CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdVal_C = false;/* Referenced by: '<S241>/Constant6' */
CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdFlg_C = false;/* Referenced by: '<S241>/Constant7' */
CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdVal_C = false;/* Referenced by: '<S241>/Constant8' */
CALDATA const volatile boolean LampCtl_J449BoxLampOvrdFlg_C = false;/* Referenced by: '<S241>/Constant28' */
CALDATA const volatile boolean LampCtl_J449BoxLampOvrdVal_C = false;/* Referenced by: '<S241>/Constant27' */
CALDATA const volatile uint8 LampCtl_LOpenCnt_C = 3U;/* Referenced by: '<S462>/Constant17' */
CALDATA const volatile uint8 LampCtl_LShortCnt_C = 3U;/* Referenced by: '<S462>/Constant19' */
CALDATA const volatile uint16 LampCtl_LampDelayTim_C = 3000U;/* Referenced by: '<S329>/Constant6' */
CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimInValid_C = 500U;/* Referenced by: '<S331>/Constant29' */
CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimValid_C = 500U;/* Referenced by: '<S331>/Constant28' */
CALDATA const volatile boolean LampCtl_LowBeamStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant9' */
CALDATA const volatile boolean LampCtl_LowBeamStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant10' */
CALDATA const volatile uint16 LampCtl_LowBeamStaTimInValid_C = 0U;/* Referenced by: '<S331>/Constant5' */
CALDATA const volatile uint16 LampCtl_LowBeamStaTimValid_C = 0U;/* Referenced by: '<S331>/Constant4' */
CALDATA const volatile uint16 LampCtl_LowBeamTimInValid_C = 0U;/* Referenced by: '<S350>/Constant24' */
CALDATA const volatile uint16 LampCtl_LowBeamTimValid_C = 0U;/* Referenced by: '<S350>/Constant23' */
CALDATA const volatile boolean LampCtl_LowBeamVal_C = false;/* Referenced by: '<S350>/Constant10' */
CALDATA const volatile uint16 LampCtl_NightVal_C = 1000U;/* Referenced by: '<S330>/Chart' */
CALDATA const volatile uint16 LampCtl_OsUnlckDelayTim_C = 35U;/* Referenced by: '<S571>/Constant3' */
CALDATA const volatile uint16 LampCtl_PassLightTimInValid_C = 0U;/* Referenced by: '<S350>/Constant29' */
CALDATA const volatile uint16 LampCtl_PassLightTimValid_C = 0U;/* Referenced by: '<S350>/Constant28' */
CALDATA const volatile boolean LampCtl_PassLightVal_C = false;/* Referenced by: '<S350>/Constant2' */
CALDATA const volatile boolean LampCtl_PosLampStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant18' */
CALDATA const volatile boolean LampCtl_PosLampStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant19' */
CALDATA const volatile uint16 LampCtl_PosLampStaTimInValid_C = 5U;/* Referenced by: '<S348>/Constant4' */
CALDATA const volatile uint16 LampCtl_PosLampStaTimValid_C = 5U;/* Referenced by: '<S348>/Constant2' */
CALDATA const volatile uint16 LampCtl_PosLampTimInValid_C = 0U;/* Referenced by: '<S350>/Constant20' */
CALDATA const volatile uint16 LampCtl_PosLampTimValid_C = 0U;/* Referenced by: '<S350>/Constant19' */
CALDATA const volatile boolean LampCtl_PosLampVal_C = false;/* Referenced by: '<S350>/Constant50' */
CALDATA const volatile uint8 LampCtl_ROpenCnt_C = 3U;/* Referenced by: '<S462>/Constant8' */
CALDATA const volatile uint8 LampCtl_RShortCnt_C = 3U;/* Referenced by: '<S462>/Constant16' */
CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant16' */
CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant15' */
CALDATA const volatile uint16 LampCtl_TrunkWarnTim_C = 1500U;/* Referenced by: '<S460>/Chart' */
CALDATA const volatile float32 LampCtl_Ts_C = 0.02F;/* Referenced by:
                                                     * '<S320>/Constant45'
                                                     * '<S320>/Constant7'
                                                     * '<S327>/Constant30'
                                                     * '<S328>/Constant21'
                                                     * '<S331>/Constant13'
                                                     * '<S331>/Constant30'
                                                     * '<S348>/Constant13'
                                                     * '<S350>/Constant13'
                                                     * '<S350>/Constant16'
                                                     * '<S350>/Constant21'
                                                     * '<S350>/Constant22'
                                                     * '<S350>/Constant27'
                                                     * '<S350>/Constant30'
                                                     * '<S350>/Constant33'
                                                     * '<S350>/Constant36'
                                                     * '<S350>/Constant39'
                                                     * '<S350>/Constant42'
                                                     * '<S350>/Constant45'
                                                     * '<S350>/Constant49'
                                                     * '<S350>/Constant67'
                                                     * '<S350>/Constant72'
                                                     * '<S373>/Constant5'
                                                     * '<S373>/Constant8'
                                                     * '<S458>/Constant21'
                                                     * '<S462>/Constant13'
                                                     * '<S462>/Constant18'
                                                     * '<S462>/Constant45'
                                                     * '<S462>/Constant6'
                                                     */
CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimInValid_C = 10U;/* Referenced by: '<S462>/Constant44' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimValid_C = 10U;/* Referenced by: '<S462>/Constant43' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimInValid_C = 10U;/* Referenced by: '<S462>/Constant10' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimValid_C = 10U;/* Referenced by: '<S462>/Constant9' */
CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant25' */
CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant26' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLTimInValid_C = 0U;/* Referenced by: '<S350>/Constant32' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLTimValid_C = 70U;/* Referenced by: '<S350>/Constant31' */
CALDATA const volatile boolean LampCtl_TurnIndcrLVal_C = false;/* Referenced by: '<S350>/Constant54' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimInValid_C = 0U;/* Referenced by: '<S350>/Constant35' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimValid_C = 0U;/* Referenced by: '<S350>/Constant34' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimInValid_C = 0U;/* Referenced by: '<S350>/Constant41' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimValid_C = 0U;/* Referenced by: '<S350>/Constant40' */
CALDATA const volatile uint16 LampCtl_TurnIndcrOpenCur_C = 30U;/* Referenced by:
                                                                * '<S462>/Constant11'
                                                                * '<S462>/Constant21'
                                                                */
CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimInValid_C = 10U;/* Referenced by: '<S462>/Constant3' */
CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimValid_C = 10U;/* Referenced by: '<S462>/Constant2' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimInValid_C = 10U;/* Referenced by: '<S462>/Constant12' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimValid_C = 10U;/* Referenced by: '<S462>/Constant14' */
CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdFlg_C = false;/* Referenced by: '<S241>/Constant23' */
CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdVal_C = false;/* Referenced by: '<S241>/Constant24' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRTimInValid_C = 0U;/* Referenced by: '<S350>/Constant38' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRTimValid_C = 70U;/* Referenced by: '<S350>/Constant37' */
CALDATA const volatile boolean LampCtl_TurnIndcrRVal_C = false;/* Referenced by: '<S350>/Constant5' */
CALDATA const volatile uint16 LampCtl_TurnIndcrShortCur_C = 6000U;/* Referenced by:
                                                                   * '<S462>/Constant20'
                                                                   * '<S462>/Constant4'
                                                                   */
CALDATA const volatile uint16 LampCtl_WelcomeLampTimMax_C = 3000U;/* Referenced by: '<S570>/Constant6' */
CALDATA const volatile uint16 PDUCtl_EmerPwrOffTimInValid_C = 100U;/* Referenced by: '<S866>/Constant20' */
CALDATA const volatile uint16 PDUCtl_EmerPwrOffTimValid_C = 500U;/* Referenced by: '<S866>/Constant19' */
CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdFlg_C = false;/* Referenced by: '<S643>/Constant18' */
CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdVal_C = false;/* Referenced by: '<S643>/Constant19' */
CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdFlg_C = false;/* Referenced by: '<S643>/Constant1' */
CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdVal_C = false;/* Referenced by: '<S643>/Constant2' */
CALDATA const volatile boolean PDUCtl_KeyValidOvrdFlg_C = false;/* Referenced by:
                                                                 * '<S867>/Constant12'
                                                                 * '<S867>/Constant9'
                                                                 */
CALDATA const volatile boolean PDUCtl_KeyValidOvrdVal_C = false;/* Referenced by:
                                                                 * '<S867>/Constant10'
                                                                 * '<S867>/Constant11'
                                                                 */
CALDATA const volatile uint16 PDUCtl_OpenDoorPwrOnTimValid = 6000U;/* Referenced by: '<S867>/Constant6' */
CALDATA const volatile uint16 PDUCtl_PwrOnPSTimValid_C = 40U;/* Referenced by: '<S867>/Constant3' */
CALDATA const volatile uint16 PDUCtl_RemtPasvBrkSwTimValid_C = 40U;/* Referenced by: '<S866>/Constant33' */
CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffH_C = 0U;/* Referenced by: '<S866>/Constant25' */
CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffM_C = 30U;/* Referenced by: '<S866>/Constant26' */
CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffS_C = 0U;/* Referenced by: '<S866>/Constant27' */
CALDATA const volatile uint16 PDUCtl_StartReqOverTimValid_C = 200U;/* Referenced by: '<S870>/Constant5' */
CALDATA const volatile uint16 PDUCtl_StartReqTimValid_C = 10U;/* Referenced by: '<S870>/Constant4' */
CALDATA const volatile uint8 PDUCtl_TimOutPwrOffH_C = 1U;/* Referenced by: '<S866>/Constant4' */
CALDATA const volatile uint8 PDUCtl_TimOutPwrOffM_C = 0U;/* Referenced by: '<S866>/Constant5' */
CALDATA const volatile uint8 PDUCtl_TimOutPwrOffS_C = 0U;/* Referenced by: '<S866>/Constant6' */
CALDATA const volatile float32 PDUCtl_Ts_C = 0.05F;/* Referenced by:
                                                    * '<S866>/Constant21'
                                                    * '<S866>/Constant28'
                                                    * '<S866>/Constant7'
                                                    * '<S868>/Constant13'
                                                    * '<S868>/Constant6'
                                                    * '<S868>/Constant8'
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
CALDATA const volatile uint16 WakeUpCtl_CANSleepDelayTim_C = 300U;/* Referenced by: '<S909>/Constant22' */
CALDATA const volatile uint16 WakeUpCtl_LocalSleepDelayTim_C = 200U;/* Referenced by: '<S910>/Constant27' */
CALDATA const volatile uint16 WakeUpCtl_WinCtlDelayTim_C = 1200U;/* Referenced by: '<S909>/Constant3' */
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
CALDATA const volatile uint16 WiperCtl_HiSpdTimInValid_C = 10U;/* Referenced by: '<S587>/Constant22' */
CALDATA const volatile uint16 WiperCtl_HiSpdTimValid_C = 10U;/* Referenced by: '<S587>/Constant21' */
CALDATA const volatile uint16 WiperCtl_InportCalSwBit_C = 0U;/* Referenced by:
                                                              * '<S587>/Constant28'
                                                              * '<S587>/Constant35'
                                                              * '<S587>/Constant59'
                                                              */
CALDATA const volatile uint16 WiperCtl_InrLvl1Tim_C = 100U;/* Referenced by: '<S591>/Constant1' */
CALDATA const volatile uint16 WiperCtl_InrLvl2Tim_C = 200U;/* Referenced by: '<S591>/Constant2' */
CALDATA const volatile uint16 WiperCtl_InrLvl3Tim_C = 400U;/* Referenced by:
                                                            * '<S591>/Constant3'
                                                            * '<S591>/Constant8'
                                                            */
CALDATA const volatile uint16 WiperCtl_InrLvl4Tim_C = 500U;/* Referenced by: '<S591>/Constant4' */
CALDATA const volatile uint16 WiperCtl_InrLvl5Tim_C = 650U;/* Referenced by: '<S591>/Constant5' */
CALDATA const volatile uint16 WiperCtl_InrLvl6Tim_C = 500U;/* Referenced by: '<S591>/Constant6' */
CALDATA const volatile uint16 WiperCtl_InrLvl7Tim_C = 300U;/* Referenced by: '<S591>/Constant7' */
CALDATA const volatile uint16 WiperCtl_InrTimInValid_C = 10U;/* Referenced by: '<S587>/Constant9' */
CALDATA const volatile uint16 WiperCtl_InrTimValid_C = 10U;/* Referenced by: '<S587>/Constant8' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimDef_C = 250U;/* Referenced by: '<S583>/Constant1' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimOk_C = 5U;/* Referenced by: '<S583>/Constant2' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkDef_C = 100U;/* Referenced by: '<S583>/Constant4' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkOk_C = 5U;/* Referenced by: '<S583>/Constant5' */
CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdFlg_C = false;/* Referenced by: '<S242>/Constant1' */
CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdVal_C = false;/* Referenced by: '<S242>/Constant2' */
CALDATA const volatile uint16 WiperCtl_LowSpdTimInValid_C = 10U;/* Referenced by: '<S587>/Constant17' */
CALDATA const volatile uint16 WiperCtl_LowSpdTimValid_C = 10U;/* Referenced by: '<S587>/Constant16' */
CALDATA const volatile uint16 WiperCtl_MaintWiperRunTim_C = 25U;/* Referenced by: '<S589>/Chart' */
CALDATA const volatile uint16 WiperCtl_MistTimInValid_C = 10U;/* Referenced by: '<S587>/Constant47' */
CALDATA const volatile uint16 WiperCtl_MistTimValid_C = 10U;/* Referenced by: '<S587>/Constant46' */
CALDATA const volatile uint16 WiperCtl_OffTimInValid_C = 10U;/* Referenced by: '<S587>/Constant4' */
CALDATA const volatile uint16 WiperCtl_OffTimValid_C = 10U;/* Referenced by: '<S587>/Constant3' */
CALDATA const volatile float32 WiperCtl_Ts_C = 0.02F;/* Referenced by:
                                                      * '<S587>/Constant10'
                                                      * '<S587>/Constant11'
                                                      * '<S587>/Constant18'
                                                      * '<S587>/Constant27'
                                                      * '<S587>/Constant34'
                                                      * '<S587>/Constant49'
                                                      * '<S587>/Constant5'
                                                      * '<S588>/Constant34'
                                                      */
CALDATA const volatile uint8 WiperCtl_WashAfterNum_C = 4U;/* Referenced by: '<S589>/Chart' */
CALDATA const volatile uint16 WiperCtl_WashAfterTim_C = 150U;/* Referenced by: '<S589>/Chart' */
CALDATA const volatile uint16 WiperCtl_WashMaxTim_C = 600U;/* Referenced by: '<S588>/Constant' */
CALDATA const volatile uint16 WiperCtl_WashMinTim_C = 60U;/* Referenced by: '<S588>/Constant3' */
CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdFlg_C = false;/* Referenced by: '<S242>/Constant18' */
CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdVal_C = false;/* Referenced by: '<S242>/Constant19' */
CALDATA const volatile uint16 WiperCtl_WashTimInValid_C = 10U;/* Referenced by: '<S587>/Constant26' */
CALDATA const volatile uint16 WiperCtl_WashTimValid_C = 60U;/* Referenced by: '<S587>/Constant25' */
CALDATA const volatile boolean WiperCtl_WashVal_C = true;/* Referenced by: '<S587>/Constant29' */

/* 低有效 */
CALDATA const volatile uint16 WiperCtl_WiperParkPosTimValid_C = 2U;/* Referenced by: '<S587>/Constant32' */
CALDATA const volatile boolean WiperCtl_WiperParkPosVal_C = true;/* Referenced by: '<S587>/Constant36' */

/* 低有效 */
CALDATA const volatile uint16 WiperCtl_WiperPosTimInValid_C = 2U;/* Referenced by: '<S587>/Constant33' */
CALDATA const volatile uint8 WiperCtl_WiperSwVal_C = 0U;/* Referenced by: '<S587>/Constant60' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
