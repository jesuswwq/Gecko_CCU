/*
 * File: calPrmsBcm.c
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

#include "calPrmsBcm.h"
#include "AppSwcBcm.h"

/* Exported data definition */

/*Group of variables*/
#include "XcpTest_types.h"

/* Definition for custom storage class: CalParam */
CALDATA const volatile uint16 AlmSysCtl_AlrmTimLimit_C = 600U;/* Referenced by: '<S405>/AlmSysLogic' */
CALDATA const volatile uint16 BatSaveCtl_DlyTim_C = 12000U;/* Referenced by: '<S433>/Constant2' */
CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdFlg_C = false;/* Referenced by: '<S406>/Constant18' */
CALDATA const volatile boolean BatSaveCtl_J64SavePwrOvrdVal_C = false;/* Referenced by: '<S406>/Constant19' */
CALDATA const volatile uint16 BatSaveCtl_LckDlyTim_C = 40U;/* Referenced by: '<S433>/Constant7' */
CALDATA const volatile uint16 DoorLckCtl_AntiLckProtTim_C = 20U;/* Referenced by: '<S449>/Constant' */
CALDATA const volatile uint16 DoorLckCtl_AutoLckDelayTim_C = 1200U;/* Referenced by: '<S489>/Constant7' */
CALDATA const volatile uint16 DoorLckCtl_CntSubTim_C = 26U;/* Referenced by: '<S455>/Constant' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimInValid_C = 10U;/* Referenced by: '<S446>/Constant2' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFLTimValid_C = 10U;/* Referenced by: '<S446>/Constant1' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarFLVal_C = false;/* Referenced by: '<S446>/Constant4' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimInValid_C = 10U;/* Referenced by: '<S446>/Constant7' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarFRTimValid_C = 10U;/* Referenced by: '<S446>/Constant6' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarFRVal_C = false;/* Referenced by: '<S446>/Constant9' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimInvalid_C = 10U;/* Referenced by: '<S446>/Constant35' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRLTimValid_C = 10U;/* Referenced by: '<S446>/Constant34' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarRLVal_C = false;/* Referenced by: '<S446>/Constant18' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimInvalid_C = 10U;/* Referenced by: '<S446>/Constant38' */
CALDATA const volatile uint16 DoorLckCtl_DoorAjarRRTimValid_C = 10U;/* Referenced by: '<S446>/Constant37' */
CALDATA const volatile boolean DoorLckCtl_DoorAjarRRVal_C = false;/* Referenced by: '<S446>/Constant20' */
CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimInValid_C = 10U;/* Referenced by: '<S446>/Constant47' */
CALDATA const volatile uint16 DoorLckCtl_DriverDoorLckTimValid_C = 10U;/* Referenced by: '<S446>/Constant46' */
CALDATA const volatile boolean DoorLckCtl_DriverDoorLckVal_C = false;/* Referenced by: '<S446>/Constant60' */
CALDATA const volatile uint16 DoorLckCtl_DrvPETimInvalid_C = 100U;/* Referenced by: '<S446>/Constant26' */
CALDATA const volatile uint16 DoorLckCtl_DrvPETimValid_C = 5U;/* Referenced by: '<S446>/Constant25' */
CALDATA const volatile boolean DoorLckCtl_DrvPEVal_C = false;/* Referenced by: '<S446>/Constant12' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisMin_C = 55U;/* Referenced by: '<S446>/Constant67' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatResisVal_C = 0U;/* Referenced by: '<S446>/Constant63' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimInValid_C = 10U;/* Referenced by: '<S446>/Constant65' */
CALDATA const volatile uint16 DoorLckCtl_DrvSeatTimValid_C = 10U;/* Referenced by: '<S446>/Constant64' */
CALDATA const volatile uint16 DoorLckCtl_DrvTim_C = 200U;/* Referenced by: '<S407>/DoorDrv' */
CALDATA const volatile uint8 DoorLckCtl_EEIlluminatedEntrySys_C = 0U;/* Referenced by: '<S446>/Constant74' */
CALDATA const volatile uint8 DoorLckCtl_EEKeyEntry_C = 0U;/* Referenced by: '<S446>/Constant72' */
CALDATA const volatile uint8 DoorLckCtl_IllmndSts_C = 0U;/* Referenced by: '<S446>/Constant76' */
CALDATA const volatile uint16 DoorLckCtl_InportCalSwBit_C = 0U;/* Referenced by:
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
CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdFlg_C = false;/* Referenced by: '<S407>/Constant3' */
CALDATA const volatile boolean DoorLckCtl_J511TrunkUnlckOvrdVal_C = false;/* Referenced by: '<S407>/Constant4' */
CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdFlg_C = false;/* Referenced by: '<S407>/Constant1' */
CALDATA const volatile boolean DoorLckCtl_J54DoorLckOvrdVal_C = false;/* Referenced by: '<S407>/Constant2' */
CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdFlg_C = false;/* Referenced by: '<S407>/Constant18' */
CALDATA const volatile boolean DoorLckCtl_J56DoorUnlckOvrdVal_C = false;/* Referenced by: '<S407>/Constant19' */
CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMaxTim_C = 25U;/* Referenced by: '<S407>/DoorDrv' */
CALDATA const volatile uint8 DoorLckCtl_LckStaCfmMinTim_C = 10U;/* Referenced by: '<S407>/DoorDrv' */
CALDATA const volatile uint16 DoorLckCtl_MotorProtTimMax_C = 400U;/* Referenced by: '<S455>/Constant2' */
CALDATA const volatile uint8 DoorLckCtl_MotorWorkMax_C = 10U;/* Referenced by: '<S455>/Constant1' */
CALDATA const volatile uint16 DoorLckCtl_PEProtCnt_C = 2U;/* Referenced by: '<S458>/Constant3' */
CALDATA const volatile uint16 DoorLckCtl_PEProtIntvlTim_C = 20U;/* Referenced by: '<S458>/Constant2' */
CALDATA const volatile uint16 DoorLckCtl_PsgPETimInvalid_C = 100U;/* Referenced by:
                                                                   * '<S446>/Constant29'
                                                                   * '<S446>/Constant32'
                                                                   */
CALDATA const volatile uint16 DoorLckCtl_PsgPETimValid_C = 5U;/* Referenced by:
                                                               * '<S446>/Constant28'
                                                               * '<S446>/Constant31'
                                                               */
CALDATA const volatile boolean DoorLckCtl_PsgPEVal_C = false;/* Referenced by: '<S446>/Constant14' */
CALDATA const volatile uint16 DoorLckCtl_SpdLckTimInValid_C = 50U;/* Referenced by:
                                                                   * '<S466>/Constant10'
                                                                   * '<S466>/Constant3'
                                                                   */
CALDATA const volatile uint16 DoorLckCtl_SpdLckTimValid_C = 200U;/* Referenced by:
                                                                  * '<S466>/Constant2'
                                                                  * '<S466>/Constant9'
                                                                  */
CALDATA const volatile uint8 DoorLckCtl_SpdLck_C = 20U;/* Referenced by:
                                                        * '<S466>/Chart'
                                                        * '<S466>/Constant'
                                                        */
CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimInvalid_C = 10U;/* Referenced by: '<S446>/Constant41' */
CALDATA const volatile uint16 DoorLckCtl_TrunkAjarTimValid_C = 10U;/* Referenced by: '<S446>/Constant40' */
CALDATA const volatile boolean DoorLckCtl_TrunkAjarVal_C = false;/* Referenced by: '<S446>/Constant22' */
CALDATA const volatile uint16 DoorLckCtl_TrunkAutoLckTim_C = 1200U;/* Referenced by: '<S494>/Constant1' */
CALDATA const volatile boolean DoorLckCtl_TrunkSwVal_C = false;/* Referenced by: '<S446>/Constant16' */
CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimInvalid_C = 10U;/* Referenced by: '<S516>/Constant3' */
CALDATA const volatile uint16 DoorLckCtl_TrunkUnlckTimValid_C = 150U;/* Referenced by: '<S516>/Constant2' */
CALDATA const volatile float32 DoorLckCtl_Ts_C = 0.05F;/* Referenced by:
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
CALDATA const volatile boolean EEWriteCtl_ImmOvrdFlg_C = false;/* Referenced by: '<S6>/EEWriteCtl' */
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
  255U, 255U, 255U, 255U, 255U, 255U, 255U, 255U } ;/* Referenced by: '<S6>/EEWriteCtl' */

CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdFlg_C = false;/* Referenced by: '<S606>/Constant18' */
CALDATA const volatile boolean ESCLCtl_J436PwrSupOvrdVal_C = false;/* Referenced by: '<S606>/Constant19' */
CALDATA const volatile uint16 ESCLCtl_LckDelay_C = 4U;/* Referenced by: '<S606>/ESCLLck' */
CALDATA const volatile uint16 ESCLCtl_LckTimMax_C = 60U;/* Referenced by: '<S606>/ESCLLck' */
CALDATA const volatile uint16 ESCLCtl_PwrOffDelay_C = 10U;/* Referenced by:
                                                           * '<S606>/ESCLLck'
                                                           * '<S606>/ESCLUnlck'
                                                           */
CALDATA const volatile uint16 ESCLCtl_UnlckDelay_C = 4U;/* Referenced by: '<S606>/ESCLUnlck' */
CALDATA const volatile uint16 ESCLCtl_UnlckTimMax_C = 60U;/* Referenced by: '<S606>/ESCLUnlck' */
CALDATA const volatile uint16 HornCtl_HornSwTimInvalid_C = 2U;/* Referenced by: '<S318>/Constant38' */
CALDATA const volatile uint16 HornCtl_HornSwTimValid_C = 2U;/* Referenced by: '<S318>/Constant37' */
CALDATA const volatile boolean HornCtl_J430HornDrvOvrdFlg_C = false;/* Referenced by: '<S269>/Constant18' */
CALDATA const volatile boolean HornCtl_J430HornDrvOvrdVal_C = false;/* Referenced by: '<S269>/Constant19' */
CALDATA const volatile float32 HornCtl_Ts_C = 0.02F;/* Referenced by: '<S318>/Constant39' */
CALDATA const volatile uint16 LampCtl_AutoLampDayDelayTim_C = 1000U;/* Referenced by: '<S622>/Constant6' */
CALDATA const volatile uint16 LampCtl_AutoLampNightDelayTim_C = 100U;/* Referenced by: '<S622>/Constant43' */
CALDATA const volatile uint16 LampCtl_AutoLampTimInValid_C = 0U;/* Referenced by: '<S653>/Constant63' */
CALDATA const volatile uint16 LampCtl_AutoLampTimValid_C = 0U;/* Referenced by: '<S653>/Constant9' */
CALDATA const volatile boolean LampCtl_AutoLampVal_C = false;/* Referenced by: '<S653>/Constant8' */
CALDATA const volatile uint16 LampCtl_BoxLampOpenTimMax_C = 12000U;/* Referenced by: '<S624>/Constant4' */
CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdFlg_C = false;/* Referenced by: '<S411>/Constant3' */
CALDATA const volatile boolean LampCtl_BrakeLightStaOvrdVal_C = false;/* Referenced by: '<S411>/Constant4' */
CALDATA const volatile boolean LampCtl_BrakeLightVal_C = false;/* Referenced by:
                                                                * '<S653>/Constant62'
                                                                * '<S653>/Constant74'
                                                                */
CALDATA const volatile uint16 LampCtl_BrakeSwInValid_C = 5U;/* Referenced by:
                                                             * '<S653>/Constant15'
                                                             * '<S653>/Constant71'
                                                             */
CALDATA const volatile uint16 LampCtl_BrakeSwTimValid_C = 5U;/* Referenced by:
                                                              * '<S653>/Constant14'
                                                              * '<S653>/Constant70'
                                                              */
CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdFlg_C = false;/* Referenced by: '<S411>/Constant1' */
CALDATA const volatile boolean LampCtl_DayRunLightStaOvrdVal_C = false;/* Referenced by: '<S411>/Constant2' */
CALDATA const volatile uint16 LampCtl_DayTimeVal_C = 1000U;/* Referenced by: '<S632>/Chart' */
CALDATA const volatile boolean LampCtl_DomeLampPwmDutyOvrdFlg_C = false;/* Referenced by: '<S411>/Constant22' */
CALDATA const volatile uint8 LampCtl_DomeLampPwmDutyOvrdVal_C = 0U;/* Referenced by: '<S411>/Constant21' */
CALDATA const volatile uint16 LampCtl_DoorOpenFLInValidTim_C = 6U;/* Referenced by: '<S676>/Constant4' */
CALDATA const volatile uint16 LampCtl_DoorOpenFLValidTim_C = 6U;/* Referenced by: '<S676>/Constant3' */
CALDATA const volatile uint16 LampCtl_DoorOpenFRInValidTim_C = 6U;/* Referenced by: '<S676>/Constant7' */
CALDATA const volatile uint16 LampCtl_DoorOpenFRValidTim_C = 6U;/* Referenced by: '<S676>/Constant6' */
CALDATA const volatile uint16 LampCtl_FlwrMeHomeTimValid_C = 10U;/* Referenced by: '<S869>/Constant43' */
CALDATA const volatile boolean LampCtl_FogLampFStaOvrdFlg_C = false;/* Referenced by: '<S411>/Constant14' */
CALDATA const volatile boolean LampCtl_FogLampFStaOvrdVal_C = false;/* Referenced by: '<S411>/Constant13' */
CALDATA const volatile uint16 LampCtl_FogLampFTimInValid_C = 5U;/* Referenced by: '<S653>/Constant66' */
CALDATA const volatile uint16 LampCtl_FogLampFTimValid_C = 5U;/* Referenced by: '<S653>/Constant64' */
CALDATA const volatile boolean LampCtl_FogLampFVal_C = false;/* Referenced by: '<S653>/Constant69' */
CALDATA const volatile boolean LampCtl_FogLampRStaOvrdFlg_C = false;/* Referenced by: '<S411>/Constant12' */
CALDATA const volatile boolean LampCtl_FogLampRStaOvrdVal_C = false;/* Referenced by: '<S411>/Constant11' */
CALDATA const volatile uint16 LampCtl_FogLampRTimInValid_C = 5U;/* Referenced by: '<S653>/Constant44' */
CALDATA const volatile uint16 LampCtl_FogLampRTimValid_C = 5U;/* Referenced by: '<S653>/Constant43' */
CALDATA const volatile boolean LampCtl_FogLampRVal_C = false;/* Referenced by: '<S653>/Constant56' */
CALDATA const volatile uint16 LampCtl_HazardLightTimInValid_C = 0U;/* Referenced by: '<S653>/Constant47' */
CALDATA const volatile uint16 LampCtl_HazardLightTimValid_C = 0U;/* Referenced by: '<S653>/Constant46' */
CALDATA const volatile boolean LampCtl_HazardLightVal_C = false;/* Referenced by: '<S653>/Constant60' */
CALDATA const volatile uint16 LampCtl_HiBeamShortToBatTimInValid_C = 500U;/* Referenced by: '<S629>/Constant29' */
CALDATA const volatile boolean LampCtl_HiBeamStaOvrdFlg_C = false;/* Referenced by: '<S411>/Constant20' */
CALDATA const volatile boolean LampCtl_HiBeamStaOvrdVal_C = false;/* Referenced by: '<S411>/Constant17' */
CALDATA const volatile uint16 LampCtl_HiBeamTimInValid_C = 0U;/* Referenced by: '<S653>/Constant26' */
CALDATA const volatile uint16 LampCtl_HiBeamTimValid_C = 0U;/* Referenced by: '<S653>/Constant25' */
CALDATA const volatile boolean LampCtl_HiBeamVal_C = false;/* Referenced by: '<S653>/Constant11' */
CALDATA const volatile uint16 LampCtl_InportCalSwBit_C = 0U;/* Referenced by:
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
CALDATA const volatile boolean LampCtl_J408BackLampPWMOvrdFlg_C = false;/* Referenced by: '<S411>/Constant30' */
CALDATA const volatile uint8 LampCtl_J408BackLampPWMOvrdVal_C = 0U;/* Referenced by: '<S411>/Constant29' */
CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdFlg_C = false;/* Referenced by: '<S411>/Constant5' */
CALDATA const volatile boolean LampCtl_J420BSDRightCtlOvrdVal_C = false;/* Referenced by: '<S411>/Constant6' */
CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdFlg_C = false;/* Referenced by: '<S411>/Constant7' */
CALDATA const volatile boolean LampCtl_J422BSDLeftCtlOvrdVal_C = false;/* Referenced by: '<S411>/Constant8' */
CALDATA const volatile boolean LampCtl_J449BoxLampOvrdFlg_C = false;/* Referenced by: '<S411>/Constant28' */
CALDATA const volatile boolean LampCtl_J449BoxLampOvrdVal_C = false;/* Referenced by: '<S411>/Constant27' */
CALDATA const volatile uint8 LampCtl_LOpenCnt_C = 3U;/* Referenced by: '<S765>/Constant17' */
CALDATA const volatile uint8 LampCtl_LShortCnt_C = 3U;/* Referenced by: '<S765>/Constant19' */
CALDATA const volatile uint16 LampCtl_LampDelayTim_C = 1200U;/* Referenced by: '<S631>/Constant6' */
CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimInValid_C = 500U;/* Referenced by: '<S633>/Constant29' */
CALDATA const volatile uint16 LampCtl_LowBeamShortToBatTimValid_C = 500U;/* Referenced by: '<S633>/Constant28' */
CALDATA const volatile boolean LampCtl_LowBeamStaOvrdFlg_C = false;/* Referenced by: '<S411>/Constant9' */
CALDATA const volatile boolean LampCtl_LowBeamStaOvrdVal_C = false;/* Referenced by: '<S411>/Constant10' */
CALDATA const volatile uint16 LampCtl_LowBeamStaTimInValid_C = 0U;/* Referenced by: '<S633>/Constant5' */
CALDATA const volatile uint16 LampCtl_LowBeamStaTimValid_C = 0U;/* Referenced by: '<S633>/Constant4' */
CALDATA const volatile uint16 LampCtl_LowBeamTimInValid_C = 0U;/* Referenced by: '<S653>/Constant24' */
CALDATA const volatile uint16 LampCtl_LowBeamTimValid_C = 0U;/* Referenced by: '<S653>/Constant23' */
CALDATA const volatile boolean LampCtl_LowBeamVal_C = false;/* Referenced by: '<S653>/Constant10' */
CALDATA const volatile uint16 LampCtl_NightVal_C = 1000U;/* Referenced by: '<S632>/Chart' */
CALDATA const volatile uint16 LampCtl_OsUnlckDelayTim_C = 14U;/* Referenced by: '<S874>/Constant3' */
CALDATA const volatile uint16 LampCtl_PassLightTimInValid_C = 0U;/* Referenced by: '<S653>/Constant29' */
CALDATA const volatile uint16 LampCtl_PassLightTimValid_C = 0U;/* Referenced by: '<S653>/Constant28' */
CALDATA const volatile boolean LampCtl_PassLightVal_C = false;/* Referenced by: '<S653>/Constant2' */
CALDATA const volatile boolean LampCtl_PosLampStaOvrdFlg_C = false;/* Referenced by: '<S411>/Constant18' */
CALDATA const volatile boolean LampCtl_PosLampStaOvrdVal_C = false;/* Referenced by: '<S411>/Constant19' */
CALDATA const volatile uint16 LampCtl_PosLampStaTimInValid_C = 5U;/* Referenced by: '<S651>/Constant4' */
CALDATA const volatile uint16 LampCtl_PosLampStaTimValid_C = 5U;/* Referenced by: '<S651>/Constant2' */
CALDATA const volatile uint16 LampCtl_PosLampTimInValid_C = 0U;/* Referenced by: '<S653>/Constant20' */
CALDATA const volatile uint16 LampCtl_PosLampTimValid_C = 0U;/* Referenced by: '<S653>/Constant19' */
CALDATA const volatile boolean LampCtl_PosLampVal_C = false;/* Referenced by: '<S653>/Constant50' */
CALDATA const volatile uint8 LampCtl_ROpenCnt_C = 3U;/* Referenced by: '<S765>/Constant8' */
CALDATA const volatile uint8 LampCtl_RShortCnt_C = 3U;/* Referenced by: '<S765>/Constant16' */
CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdFlg_C = false;/* Referenced by: '<S411>/Constant16' */
CALDATA const volatile boolean LampCtl_ReverseLampStaOvrdVal_C = false;/* Referenced by: '<S411>/Constant15' */
CALDATA const volatile uint16 LampCtl_TrunkWarnTim_C = 1500U;/* Referenced by: '<S763>/Chart' */
CALDATA const volatile float32 LampCtl_Ts_C = 0.05F;/* Referenced by:
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
CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimInValid_C = 10U;/* Referenced by: '<S765>/Constant44' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLOpenTimValid_C = 10U;/* Referenced by: '<S765>/Constant43' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimInValid_C = 10U;/* Referenced by: '<S765>/Constant10' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLShortTimValid_C = 10U;/* Referenced by: '<S765>/Constant9' */
CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdFlg_C = false;/* Referenced by: '<S411>/Constant25' */
CALDATA const volatile boolean LampCtl_TurnIndcrLStaOvrdVal_C = false;/* Referenced by: '<S411>/Constant26' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLTimInValid_C = 0U;/* Referenced by: '<S653>/Constant32' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLTimValid_C = 70U;/* Referenced by: '<S653>/Constant31' */
CALDATA const volatile boolean LampCtl_TurnIndcrLVal_C = false;/* Referenced by: '<S653>/Constant54' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimInValid_C = 0U;/* Referenced by: '<S653>/Constant35' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneLTimValid_C = 0U;/* Referenced by: '<S653>/Constant34' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimInValid_C = 0U;/* Referenced by: '<S653>/Constant41' */
CALDATA const volatile uint16 LampCtl_TurnIndcrLaneRTimValid_C = 0U;/* Referenced by: '<S653>/Constant40' */
CALDATA const volatile uint16 LampCtl_TurnIndcrOpenCur_C = 30U;/* Referenced by:
                                                                * '<S765>/Constant11'
                                                                * '<S765>/Constant21'
                                                                */
CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimInValid_C = 10U;/* Referenced by: '<S765>/Constant3' */
CALDATA const volatile uint16 LampCtl_TurnIndcrROpenTimValid_C = 10U;/* Referenced by: '<S765>/Constant2' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimInValid_C = 10U;/* Referenced by: '<S765>/Constant12' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRShortTimValid_C = 10U;/* Referenced by: '<S765>/Constant14' */
CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdFlg_C = false;/* Referenced by: '<S411>/Constant23' */
CALDATA const volatile boolean LampCtl_TurnIndcrRStaOvrdVal_C = false;/* Referenced by: '<S411>/Constant24' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRTimInValid_C = 0U;/* Referenced by: '<S653>/Constant38' */
CALDATA const volatile uint16 LampCtl_TurnIndcrRTimValid_C = 70U;/* Referenced by: '<S653>/Constant37' */
CALDATA const volatile boolean LampCtl_TurnIndcrRVal_C = false;/* Referenced by: '<S653>/Constant5' */
CALDATA const volatile uint16 LampCtl_TurnIndcrShortCur_C = 6000U;/* Referenced by:
                                                                   * '<S765>/Constant20'
                                                                   * '<S765>/Constant4'
                                                                   */
CALDATA const volatile uint16 LampCtl_WelcomeLampTimMax_C = 1200U;/* Referenced by: '<S873>/Constant6' */
CALDATA const volatile uint16 PDUCtl_EmerPwrOffTimInValid_C = 100U;/* Referenced by: '<S890>/Constant20' */
CALDATA const volatile uint16 PDUCtl_EmerPwrOffTimValid_C = 500U;/* Referenced by: '<S890>/Constant19' */
CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdFlg_C = false;/* Referenced by: '<S412>/Constant18' */
CALDATA const volatile boolean PDUCtl_J421IG1RlyCtlOvrdVal_C = false;/* Referenced by: '<S412>/Constant19' */
CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdFlg_C = false;/* Referenced by: '<S412>/Constant1' */
CALDATA const volatile boolean PDUCtl_J437IG2RlyCtlOvrdVal_C = false;/* Referenced by: '<S412>/Constant2' */
CALDATA const volatile boolean PDUCtl_KeyValidOvrdFlg_C = false;/* Referenced by:
                                                                 * '<S891>/Constant12'
                                                                 * '<S891>/Constant9'
                                                                 */
CALDATA const volatile boolean PDUCtl_KeyValidOvrdVal_C = false;/* Referenced by:
                                                                 * '<S891>/Constant10'
                                                                 * '<S891>/Constant11'
                                                                 */
CALDATA const volatile uint16 PDUCtl_OTAOverTimPwrOff_C = 36000U;/* Referenced by: '<S890>/Constant37' */
CALDATA const volatile uint16 PDUCtl_OTAPwrOnDelayTim_C = 50U;/* Referenced by: '<S891>/Constant16' */
CALDATA const volatile uint16 PDUCtl_OpenDoorPwrOnTimValid = 6000U;/* Referenced by: '<S891>/Constant6' */
CALDATA const volatile uint16 PDUCtl_PwrOnPSTimValid_C = 40U;/* Referenced by: '<S891>/Constant3' */
CALDATA const volatile uint16 PDUCtl_RemtPasvBrkSwTimValid_C = 40U;/* Referenced by: '<S890>/Constant33' */
CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffH_C = 0U;/* Referenced by: '<S890>/Constant25' */
CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffM_C = 30U;/* Referenced by: '<S890>/Constant26' */
CALDATA const volatile uint8 PDUCtl_RemtTimOutPwrOffS_C = 0U;/* Referenced by: '<S890>/Constant27' */
CALDATA const volatile uint16 PDUCtl_StartReqOverTimValid_C = 200U;/* Referenced by: '<S894>/Constant5' */
CALDATA const volatile uint16 PDUCtl_StartReqTimValid_C = 10U;/* Referenced by: '<S894>/Constant4' */
CALDATA const volatile uint8 PDUCtl_TimOutPwrOffH_C = 1U;/* Referenced by: '<S890>/Constant4' */
CALDATA const volatile uint8 PDUCtl_TimOutPwrOffM_C = 0U;/* Referenced by: '<S890>/Constant5' */
CALDATA const volatile uint8 PDUCtl_TimOutPwrOffS_C = 0U;/* Referenced by: '<S890>/Constant6' */
CALDATA const volatile float32 PDUCtl_Ts_C = 0.05F;/* Referenced by:
                                                    * '<S890>/Constant21'
                                                    * '<S890>/Constant28'
                                                    * '<S890>/Constant7'
                                                    * '<S891>/Constant17'
                                                    * '<S892>/Constant13'
                                                    * '<S892>/Constant6'
                                                    * '<S892>/Constant8'
                                                    */
CALDATA const volatile boolean RVMCtl_J42HeatOvrdFlg_C = false;/* Referenced by: '<S8>/Constant18' */
CALDATA const volatile boolean RVMCtl_J42HeatOvrdVal_C = false;/* Referenced by: '<S8>/Constant19' */
CALDATA const volatile uint8 RVMCtl_MaxHeatTimM_C = 25U;/* Referenced by: '<S132>/Constant2' */
CALDATA const volatile float32 RVMCtl_Ts_C = 0.1F;/* Referenced by: '<S132>/Constant7' */
CALDATA const volatile boolean SeatCtl_CN167DrvSeatHtPWMOvrdFlg_C = false;/* Referenced by: '<S136>/Constant18' */
CALDATA const volatile uint8 SeatCtl_CN167DrvSeatHtPWMOvrdVal_C = 0U;/* Referenced by: '<S136>/Constant19' */
CALDATA const volatile float32 SeatCtl_DrvSeatTempLookUp_X[23] = { 1738.0F,
  2068.0F, 2473.0F, 2971.0F, 3588.0F, 4355.0F, 5314.0F, 6522.0F, 8051.0F,
  10000.0F, 12500.0F, 15731.0F, 19938.0F, 25456.0F, 32754.0F, 42490.0F, 55595.0F,
  73401.0F, 97839.0F, 131733.0F, 179266.0F, 246717.0F, 343636.0F } ;
                                 /* Referenced by: '<S136>/1-D Lookup Table2' */

CALDATA const volatile float32 SeatCtl_DrvSeatTempLookUp_Y[23] = { 70.0F, 65.0F,
  60.0F, 55.0F, 50.0F, 45.0F, 40.0F, 35.0F, 30.0F, 25.0F, 20.0F, 15.0F, 10.0F,
  5.0F, 0.0F, -5.0F, -10.0F, -15.0F, -20.0F, -25.0F, -30.0F, -35.0F, -40.0F } ;
                                 /* Referenced by: '<S136>/1-D Lookup Table2' */

CALDATA const volatile uint8 SeatCtl_DrvTempLvl0_C = 0U;/* Referenced by: '<S136>/Constant8' */
CALDATA const volatile uint8 SeatCtl_DrvTempLvl1_C = 55U;/* Referenced by: '<S136>/Constant5' */
CALDATA const volatile uint8 SeatCtl_DrvTempLvl2_C = 58U;/* Referenced by: '<S136>/Constant6' */
CALDATA const volatile uint8 SeatCtl_DrvTempLvl3_C = 62U;/* Referenced by: '<S136>/Constant7' */
CALDATA const volatile uint8 SeatCtl_HtDiffTemp_C = 2U;/* Referenced by: '<S136>/Chart' */
CALDATA const volatile uint16 SeatCtl_NTCOpenInValidTim_C = 100U;/* Referenced by: '<S136>/Constant16' */
CALDATA const volatile float32 SeatCtl_NTCOpenResis_C = 380000.0F;/* Referenced by: '<S136>/Constant11' */
CALDATA const volatile uint16 SeatCtl_NTCOpenValidTim_C = 100U;/* Referenced by: '<S136>/Constant15' */
CALDATA const volatile uint16 SeatCtl_NTCShortInValidTim_C = 100U;/* Referenced by: '<S136>/Constant13' */
CALDATA const volatile float32 SeatCtl_NTCShortResis_C = 500.0F;/* Referenced by: '<S136>/Constant' */
CALDATA const volatile uint16 SeatCtl_NTCShortValidTim_C = 100U;/* Referenced by: '<S136>/Constant12' */
CALDATA const volatile float32 SeatCtl_Ts_C = 0.1F;/* Referenced by:
                                                    * '<S136>/Constant14'
                                                    * '<S136>/Constant17'
                                                    */
CALDATA const volatile uint8 SteerWhlCtl_DiffTemp_C = 5U;/* Referenced by: '<S144>/HeatCtl' */
CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdFlg_C = false;/* Referenced by: '<S144>/Constant18' */
CALDATA const volatile boolean SteerWhlCtl_J447SteerWhlHtOvrdVal_C = false;/* Referenced by: '<S144>/Constant19' */
CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_X[18] = { 3546.0F,
  4172.0F, 4924.0F, 5838.0F, 6954.0F, 8318.0F, 10000.0F, 12090.0F, 14700.0F,
  17970.0F, 22100.0F, 27350.0F, 34080.0F, 42740.0F, 53970.0F, 68610.0F, 87780.0F,
  113100.0F } ;                  /* Referenced by: '<S144>/1-D Lookup Table1' */

CALDATA const volatile float32 SteerWhlCtl_SteerWhlTempLookUp_Y[18] = { 55.0F,
  50.0F, 45.0F, 40.0F, 35.0F, 30.0F, 25.0F, 20.0F, 15.0F, 10.0F, 5.0F, 0.0F,
  -5.0F, -10.0F, -15.0F, -20.0F, -25.0F, -30.0F } ;
                                 /* Referenced by: '<S144>/1-D Lookup Table1' */

CALDATA const volatile uint8 SteerWhlCtl_TrgtTemp_C = 35U;/* Referenced by: '<S144>/HeatCtl' */
CALDATA const volatile uint16 WakeUpCtl_CANSleepDelayTim_C = 300U;/* Referenced by: '<S941>/Constant22' */
CALDATA const volatile uint16 WakeUpCtl_LocalSleepDelayTim_C = 200U;/* Referenced by: '<S942>/Constant27' */
CALDATA const volatile uint16 WakeUpCtl_WinCtlDelayTim_C = 1200U;/* Referenced by: '<S941>/Constant3' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMaxResis_C = 200U;/* Referenced by: '<S157>/Constant51' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnMinResis_C = 0U;/* Referenced by: '<S157>/Constant50' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimInValid_C = 0U;/* Referenced by: '<S157>/Constant10' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinAutoDnTimValid_C = 0U;/* Referenced by: '<S157>/Constant9' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMaxResis_C = 2500U;/* Referenced by: '<S157>/Constant49' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinDnMinResis_C = 2000U;/* Referenced by: '<S157>/Constant48' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimInValid_C = 0U;/* Referenced by: '<S157>/Constant7' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinDnTimValid_C = 0U;/* Referenced by: '<S157>/Constant6' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinSwResis_C = 0U;/* Referenced by: '<S157>/Constant5' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMaxResis_C = 1500U;/* Referenced by: '<S157>/Constant47' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinUpMinResis_C = 1000U;/* Referenced by: '<S157>/Constant46' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimInValid_C = 0U;/* Referenced by: '<S157>/Constant3' */
CALDATA const volatile uint16 WinCtl_DrvPsgWinUpTimValid_C = 0U;/* Referenced by: '<S157>/Constant2' */
CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMaxResis_C = 200U;/* Referenced by: '<S157>/Constant36' */
CALDATA const volatile uint16 WinCtl_DrvWinAutoDnMinResis_C = 0U;/* Referenced by: '<S157>/Constant35' */
CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimInValid_C = 0U;/* Referenced by: '<S157>/Constant24' */
CALDATA const volatile uint16 WinCtl_DrvWinAutoDnTimValid_C = 0U;/* Referenced by: '<S157>/Constant23' */
CALDATA const volatile uint16 WinCtl_DrvWinDnMaxResis_C = 2500U;/* Referenced by: '<S157>/Constant31' */
CALDATA const volatile uint16 WinCtl_DrvWinDnMinResis_C = 2000U;/* Referenced by: '<S157>/Constant26' */
CALDATA const volatile uint16 WinCtl_DrvWinDnTimInValid_C = 0U;/* Referenced by: '<S157>/Constant18' */
CALDATA const volatile uint16 WinCtl_DrvWinDnTimValid_C = 0U;/* Referenced by: '<S157>/Constant17' */
CALDATA const volatile uint16 WinCtl_DrvWinSwResis_C = 0U;/* Referenced by: '<S157>/Constant15' */
CALDATA const volatile uint16 WinCtl_DrvWinUpMaxResis_C = 1500U;/* Referenced by: '<S157>/Constant22' */
CALDATA const volatile uint16 WinCtl_DrvWinUpMinResis_C = 1000U;/* Referenced by: '<S157>/Constant20' */
CALDATA const volatile uint16 WinCtl_DrvWinUpTimInValid_C = 0U;/* Referenced by: '<S157>/Constant13' */
CALDATA const volatile uint16 WinCtl_DrvWinUpTimValid_C = 0U;/* Referenced by: '<S157>/Constant12' */
CALDATA const volatile uint16 WinCtl_InportCalSwBit_C = 0U;/* Referenced by:
                                                            * '<S157>/Constant1'
                                                            * '<S157>/Constant11'
                                                            * '<S157>/Constant21'
                                                            */
CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdFlg_C = false;/* Referenced by: '<S11>/Constant18' */
CALDATA const volatile boolean WinCtl_J51DrvWinUpOvrdVal_C = false;/* Referenced by: '<S11>/Constant19' */
CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdFlg_C = false;/* Referenced by: '<S11>/Constant1' */
CALDATA const volatile boolean WinCtl_J53DrvWinDnOvrdVal_C = false;/* Referenced by: '<S11>/Constant2' */
CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdFlg_C = false;/* Referenced by: '<S11>/Constant3' */
CALDATA const volatile boolean WinCtl_J55PsgWinUpOvrdVal_C = false;/* Referenced by: '<S11>/Constant4' */
CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdFlg_C = false;/* Referenced by: '<S11>/Constant5' */
CALDATA const volatile boolean WinCtl_J57PsgWinDnOvrdVal_C = false;/* Referenced by: '<S11>/Constant6' */
CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMaxResis_C = 200U;/* Referenced by: '<S157>/Constant45' */
CALDATA const volatile uint16 WinCtl_PsgWinAutoDnMinResis_C = 0U;/* Referenced by: '<S157>/Constant44' */
CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimInValid_C = 0U;/* Referenced by: '<S157>/Constant38' */
CALDATA const volatile uint16 WinCtl_PsgWinAutoDnTimValid_C = 0U;/* Referenced by: '<S157>/Constant37' */
CALDATA const volatile uint16 WinCtl_PsgWinDnMaxResis_C = 2500U;/* Referenced by: '<S157>/Constant43' */
CALDATA const volatile uint16 WinCtl_PsgWinDnMinResis_C = 2000U;/* Referenced by: '<S157>/Constant42' */
CALDATA const volatile uint16 WinCtl_PsgWinDnTimInValid_C = 0U;/* Referenced by: '<S157>/Constant33' */
CALDATA const volatile uint16 WinCtl_PsgWinDnTimValid_C = 0U;/* Referenced by: '<S157>/Constant32' */
CALDATA const volatile uint16 WinCtl_PsgWinSwResis_C = 0U;/* Referenced by: '<S157>/Constant30' */
CALDATA const volatile uint16 WinCtl_PsgWinUpMaxResis_C = 1500U;/* Referenced by: '<S157>/Constant41' */
CALDATA const volatile uint16 WinCtl_PsgWinUpMinResis_C = 1000U;/* Referenced by: '<S157>/Constant40' */
CALDATA const volatile uint16 WinCtl_PsgWinUpTimInValid_C = 0U;/* Referenced by: '<S157>/Constant28' */
CALDATA const volatile uint16 WinCtl_PsgWinUpTimValid_C = 0U;/* Referenced by: '<S157>/Constant27' */
CALDATA const volatile uint16 WinCtl_PwrOffWinValidTimMax_C = 600U;/* Referenced by: '<S159>/Constant20' */
CALDATA const volatile float32 WinCtl_Ts_C = 0.1F;/* Referenced by:
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
CALDATA const volatile uint16 WinCtl_WinMotorCurMax_C = 13000U;/* Referenced by:
                                                                * '<S159>/Constant37'
                                                                * '<S159>/Constant48'
                                                                */
CALDATA const volatile uint16 WinCtl_WinMotorCurTimInValid_C = 10U;/* Referenced by:
                                                                    * '<S159>/Constant35'
                                                                    * '<S159>/Constant44'
                                                                    */
CALDATA const volatile uint16 WinCtl_WinMotorCurTimValid_C = 150U;/* Referenced by:
                                                                   * '<S159>/Constant11'
                                                                   * '<S159>/Constant34'
                                                                   */
CALDATA const volatile uint16 WinCtl_WinProtNum_C = 30U;/* Referenced by:
                                                         * '<S158>/Constant15'
                                                         * '<S158>/Constant2'
                                                         * '<S158>/Constant6'
                                                         * '<S158>/Constant9'
                                                         */
CALDATA const volatile uint16 WinCtl_WinProtTim_C = 100U;/* Referenced by:
                                                          * '<S158>/Constant1'
                                                          * '<S158>/Constant14'
                                                          * '<S158>/Constant5'
                                                          * '<S158>/Constant8'
                                                          */
CALDATA const volatile uint16 WinCtl_WinRunTimMax_C = 120U;/* Referenced by:
                                                            * '<S159>/Constant40'
                                                            * '<S159>/Constant47'
                                                            * '<S159>/Constant8'
                                                            */
CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdFlg_C = false;/* Referenced by: '<S270>/Constant3' */
CALDATA const volatile boolean WiperCtl_HiSpdDrvOvrdVal_C = false;/* Referenced by: '<S270>/Constant4' */
CALDATA const volatile uint16 WiperCtl_HiSpdTimInValid_C = 10U;/* Referenced by: '<S354>/Constant22' */
CALDATA const volatile uint16 WiperCtl_HiSpdTimValid_C = 10U;/* Referenced by: '<S354>/Constant21' */
CALDATA const volatile uint16 WiperCtl_InportCalSwBit_C = 0U;/* Referenced by:
                                                              * '<S354>/Constant28'
                                                              * '<S354>/Constant35'
                                                              * '<S354>/Constant59'
                                                              */
CALDATA const volatile uint16 WiperCtl_InrLvl1Tim_C = 100U;/* Referenced by: '<S358>/Constant1' */
CALDATA const volatile uint16 WiperCtl_InrLvl2Tim_C = 200U;/* Referenced by: '<S358>/Constant2' */
CALDATA const volatile uint16 WiperCtl_InrLvl3Tim_C = 400U;/* Referenced by:
                                                            * '<S358>/Constant3'
                                                            * '<S358>/Constant8'
                                                            */
CALDATA const volatile uint16 WiperCtl_InrLvl4Tim_C = 500U;/* Referenced by: '<S358>/Constant4' */
CALDATA const volatile uint16 WiperCtl_InrLvl5Tim_C = 650U;/* Referenced by: '<S358>/Constant5' */
CALDATA const volatile uint16 WiperCtl_InrLvl6Tim_C = 500U;/* Referenced by: '<S358>/Constant6' */
CALDATA const volatile uint16 WiperCtl_InrLvl7Tim_C = 300U;/* Referenced by: '<S358>/Constant7' */
CALDATA const volatile uint16 WiperCtl_InrTimInValid_C = 10U;/* Referenced by: '<S354>/Constant9' */
CALDATA const volatile uint16 WiperCtl_InrTimValid_C = 10U;/* Referenced by: '<S354>/Constant8' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimDef_C = 250U;/* Referenced by: '<S350>/Constant1' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimOk_C = 5U;/* Referenced by: '<S350>/Constant2' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkDef_C = 100U;/* Referenced by: '<S350>/Constant4' */
CALDATA const volatile uint16 WiperCtl_LockedRotorTimParkOk_C = 5U;/* Referenced by: '<S350>/Constant5' */
CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdFlg_C = false;/* Referenced by: '<S270>/Constant1' */
CALDATA const volatile boolean WiperCtl_LowSpdDrvOvrdVal_C = false;/* Referenced by: '<S270>/Constant2' */
CALDATA const volatile uint16 WiperCtl_LowSpdTimInValid_C = 10U;/* Referenced by: '<S354>/Constant17' */
CALDATA const volatile uint16 WiperCtl_LowSpdTimValid_C = 10U;/* Referenced by: '<S354>/Constant16' */
CALDATA const volatile uint16 WiperCtl_MaintWiperRunTim_C = 25U;/* Referenced by: '<S356>/Chart' */
CALDATA const volatile uint16 WiperCtl_MistTimInValid_C = 10U;/* Referenced by: '<S354>/Constant47' */
CALDATA const volatile uint16 WiperCtl_MistTimValid_C = 10U;/* Referenced by: '<S354>/Constant46' */
CALDATA const volatile uint16 WiperCtl_OffTimInValid_C = 10U;/* Referenced by: '<S354>/Constant4' */
CALDATA const volatile uint16 WiperCtl_OffTimValid_C = 10U;/* Referenced by: '<S354>/Constant3' */
CALDATA const volatile float32 WiperCtl_Ts_C = 0.02F;/* Referenced by:
                                                      * '<S354>/Constant10'
                                                      * '<S354>/Constant11'
                                                      * '<S354>/Constant18'
                                                      * '<S354>/Constant27'
                                                      * '<S354>/Constant34'
                                                      * '<S354>/Constant49'
                                                      * '<S354>/Constant5'
                                                      * '<S355>/Constant34'
                                                      */
CALDATA const volatile uint8 WiperCtl_WashAfterNum_C = 4U;/* Referenced by: '<S356>/Chart' */
CALDATA const volatile uint16 WiperCtl_WashAfterTim_C = 150U;/* Referenced by: '<S356>/Chart' */
CALDATA const volatile uint16 WiperCtl_WashMaxTim_C = 600U;/* Referenced by: '<S355>/Constant' */
CALDATA const volatile uint16 WiperCtl_WashMinTim_C = 60U;/* Referenced by: '<S355>/Constant3' */
CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdFlg_C = false;/* Referenced by: '<S270>/Constant18' */
CALDATA const volatile boolean WiperCtl_WashMotorDrvOvrdVal_C = false;/* Referenced by: '<S270>/Constant19' */
CALDATA const volatile uint16 WiperCtl_WashTimInValid_C = 10U;/* Referenced by: '<S354>/Constant26' */
CALDATA const volatile uint16 WiperCtl_WashTimValid_C = 60U;/* Referenced by: '<S354>/Constant25' */
CALDATA const volatile boolean WiperCtl_WashVal_C = true;/* Referenced by: '<S354>/Constant29' */

/* 低有效 */
CALDATA const volatile uint16 WiperCtl_WiperParkPosTimValid_C = 4U;/* Referenced by: '<S354>/Constant32' */
CALDATA const volatile boolean WiperCtl_WiperParkPosVal_C = true;/* Referenced by: '<S354>/Constant36' */

/* 低有效 */
CALDATA const volatile uint16 WiperCtl_WiperPosTimInValid_C = 4U;/* Referenced by: '<S354>/Constant33' */
CALDATA const volatile uint16 WiperCtl_WiperReturnDelayTim_C = 50U;/* Referenced by: '<S356>/Chart' */
CALDATA const volatile uint8 WiperCtl_WiperSwVal_C = 0U;/* Referenced by: '<S354>/Constant60' */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
